%{
/*	$Id: scanner.l,v 1.50 2011/06/03 15:42:45 plunky Exp $   */

/*
 * Copyright (c) 2004 Anders Magnusson. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config_auto.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <fcntl.h>
#include <errno.h>

#include "compat.h"
#include "cpp.h"
#include "y.tab.h"
%}

%{
static void cvtdig(int rad);
static int charcon(usch *);
static void elsestmt(void);
static void ifdefstmt(void);
static void ifndefstmt(void);
static void endifstmt(void);
static void ifstmt(void);
static void cpperror(void);
static void pragmastmt(void);
static void undefstmt(void);
static void cpperror(void);
static void elifstmt(void);
static void storepb(void);
static void badop(const char *);
void  include(void);
void  define(void);

extern int yyget_lineno (void);
extern void yyset_lineno (int);

static int inch(void);

static int scale, gotdef, contr;
int inif;

#ifdef FLEX_SCANNER /* should be set by autoconf instead */
static int
yyinput(char *b, int m)
{
	int c, i;

	for (i = 0; i < m; i++) {
		if ((c = inch()) < 0)
			break;
		*b++ = c;
		if (c == '\n') {
			i++;
			break;
		}
	}
	return i;
}
#undef YY_INPUT
#undef YY_BUF_SIZE
#define	YY_BUF_SIZE (8*65536)
#define YY_INPUT(b,r,m) (r = yyinput(b, m))
#ifdef HAVE_CPP_VARARG_MACRO_GCC
#define fprintf(x, ...) error(__VA_ARGS__)
#endif
#define	ECHO putstr((usch *)yytext)
#undef fileno
#define fileno(x) 0

#if YY_FLEX_SUBMINOR_VERSION >= 31
/* Hack to avoid unnecessary warnings */
FILE *yyget_in	(void);
FILE *yyget_out  (void);
int yyget_leng	(void);
char *yyget_text  (void);
void yyset_in (FILE *  in_str );
void yyset_out (FILE *	out_str );
int yyget_debug  (void);
void yyset_debug (int  bdebug );
int yylex_destroy  (void);
#endif
#else	/* Assume lex here */
#undef input
#undef unput
#define input() inch()
#define unput(ch) unch(ch)
#endif
#define PRTOUT(x) if (YYSTATE || slow) return x; if (!flslvl) putstr((usch *)yytext);
/* protection against recursion in #include */
#define MAX_INCLEVEL	100
static int inclevel;
%}

D	[0-9]
L	[a-zA-Z_]
H	[a-fA-F0-9]
E	[Ee][+-]?{D}+
FS	(f|F|l|L)
IS	(u|U|l|L)*
WS	[\t ]

%s IFR CONTR DEF COMMENT

%%

"\n"			{	int os = YYSTATE;
				if (os != IFR)
					BEGIN 0;
				ifiles->lineno++;
				if (flslvl == 0) {
					if (ifiles->lineno == 1)
						prtline();
					else
						putch('\n');
				}
				if ((os != 0 || slow) && !contr)
					return '\n';
				contr = 0;
			}

"\r"			{ ; /* Ignore CR's */ }

<IFR>"++"		{ badop("++"); }
<IFR>"--"		{ badop("--"); }
<IFR>"=="		{ return EQ; }
<IFR>"!="		{ return NE; }
<IFR>"<="		{ return LE; }
<IFR>"<<"		{ return LS; }
<IFR>">>"		{ return RS; }
<IFR>">="		{ return GE; }
<IFR>"||"		{ return OROR; }
<IFR>"&&"		{ return ANDAND; }
<IFR>"defined"		{	int p, c;
				gotdef = 1;
				if ((p = c = yylex()) == '(')
					c = yylex();
				if (c != IDENT || (p != IDENT && p != '('))
					error("syntax error");
				if (p == '(' && yylex() != ')')
					error("syntax error");
				return NUMBER;
			}

<IFR>{WS}+		{ ; }
<IFR>{L}({L}|{D})*	{
				yylval.node.op = NUMBER;
				if (gotdef) {
					yylval.node.nd_val
					    = lookup((usch *)yytext, FIND) != 0;
					gotdef = 0;
					return IDENT;
				}
				yylval.node.nd_val = 0;
				return NUMBER;
			}

[0-9][0-9]*		{
				if (slow && !YYSTATE)
					return IDENT;
				scale = yytext[0] == '0' ? 8 : 10;
				goto num;
			}

0[xX]{H}+{IS}?		{	scale = 16;
			num:	if (YYSTATE == IFR) 
					cvtdig(scale);
				PRTOUT(NUMBER);
			}
0{D}+{IS}?		{ scale = 8; goto num; }
{D}+{IS}?		{ scale = 10; goto num; }
'(\\.|[^\\'])+'		{
				if (YYSTATE || slow) {
					yylval.node.op = NUMBER;
					yylval.node.nd_val = charcon((usch *)yytext);
					return (NUMBER);
				}
				if (tflag)
					yyless(1);
				if (!flslvl)
					putstr((usch *)yytext);
			}

<IFR>.			{ return yytext[0]; }

{D}+{E}{FS}?		{ PRTOUT(FPOINT); }
{D}*"."{D}+({E})?{FS}?	{ PRTOUT(FPOINT); }
{D}+"."{D}*({E})?{FS}?	{ PRTOUT(FPOINT); }

^{WS}*#{WS}*		{	extern int inmac;

				if (inmac)
					error("preprocessor directive found "
					    "while expanding macro");
				contr = 1;
				BEGIN CONTR;
			}
{WS}+			{ PRTOUT(WSPACE); }

<CONTR>"ifndef"		{ contr = 0; ifndefstmt(); }
<CONTR>"ifdef"		{ contr = 0; ifdefstmt(); }
<CONTR>"if"		{ contr = 0; storepb(); BEGIN IFR; ifstmt(); BEGIN 0; }
<CONTR>"include"	{ contr = 0; BEGIN 0; include(); prtline(); }
<CONTR>"else"		{ contr = 0; elsestmt(); }
<CONTR>"endif"		{ contr = 0; endifstmt(); }
<CONTR>"error"		{ contr = 0; if (slow) return IDENT; cpperror(); BEGIN 0; }
<CONTR>"define"		{ contr = 0; BEGIN DEF; define(); BEGIN 0; }
<CONTR>"undef"		{ contr = 0; if (slow) return IDENT; undefstmt(); }
<CONTR>"line"		{ contr = 0; storepb(); BEGIN 0; line(); }
<CONTR>"pragma"		{ contr = 0; pragmastmt(); BEGIN 0; }
<CONTR>"elif"		{ contr = 0; storepb(); BEGIN IFR; elifstmt(); BEGIN 0; }



"//".*$			{ /* if (tflag) yyless(..) */
				if (Cflag && !flslvl && !slow)
					putstr((usch *)yytext);
				else if (!flslvl)
					putch(' ');
			}
"/*"			{	int c, wrn;
				int prtcm = Cflag && !flslvl && !slow;
				extern int readmac;

				if (Cflag && !flslvl && readmac)
					return CMNT;

				if (prtcm)
					putstr((usch *)yytext);
				wrn = 0;
			more:	while ((c = input()) && c != '*') {
					if (c == '\n')
						putch(c), ifiles->lineno++;
					else if (c == 1) /* WARN */
						wrn = 1;
					else if (prtcm)
						putch(c);
				}
				if (c == 0)
					return 0;
				if (prtcm)
					putch(c);
				if ((c = input()) && c != '/') {
					unput(c);
					goto more;
				}
				if (prtcm)
					putch(c);
				if (c == 0)
					return 0;
				if (!tflag && !Cflag && !flslvl)
					unput(' ');
				if (wrn)
					unput(1);
			}

<DEF>"##"		{ return CONCAT; }
<DEF>"#"		{ return MKSTR; }
<DEF>"..."		{ return ELLIPS; }
<DEF>"__VA_ARGS__"	{ return VA_ARGS; }

L?\"(\\.|[^\\"])*\"	{ PRTOUT(STRING); }
[a-zA-Z_0-9]+		{ /* {L}({L}|{D})* */
				struct symtab *nl;
				if (slow)
					return IDENT;
				if (YYSTATE == CONTR) {
					if (flslvl == 0) {
						/*error("undefined control");*/
						while (input() != '\n')
							;
						unput('\n');
						BEGIN 0;
						goto xx;
					} else {
						BEGIN 0; /* do nothing */
					}
				}
				if (flslvl) {
					; /* do nothing */
				} else if (isdigit((int)yytext[0]) == 0 &&
				    (nl = lookup((usch *)yytext, FIND)) != 0) {
					usch *op = stringbuf;
					putstr(gotident(nl));
					stringbuf = op;
				} else
					putstr((usch *)yytext);
				xx: ;
			}

.			{
				if (contr) {
					while (input() != '\n')
						;
					unput('\n');
					BEGIN 0;
					contr = 0;
					goto yy;
				}
				if (YYSTATE || slow)
					return yytext[0];
				if (yytext[0] == 6) { /* PRAGS */
					usch *obp = stringbuf;
					extern usch *prtprag(usch *);
					*stringbuf++ = yytext[0];
					do {
						*stringbuf = input();
					} while (*stringbuf++ != 14);
					prtprag(obp);
					stringbuf = obp;
				} else {
					PRTOUT(yytext[0]);
				}
				yy:;
			}

%%

usch *yyp, yybuf[CPPBUF];

int yylex(void);
int yywrap(void);

static int
inpch(void)
{
	int len;

	if (ifiles->curptr < ifiles->maxread)
		return *ifiles->curptr++;

	if ((len = read(ifiles->infil, ifiles->buffer, CPPBUF)) < 0)
		error("read error on file %s", ifiles->orgfn);
	if (len == 0)
		return -1;
	ifiles->curptr = ifiles->buffer;
	ifiles->maxread = ifiles->buffer + len;
	return inpch();
}

#define unch(c) *--ifiles->curptr = c

static int
inch(void)
{
	int c;

again:	switch (c = inpch()) {
	case '\\': /* continued lines */
msdos:		if ((c = inpch()) == '\n') {
			ifiles->lineno++;
			putch('\n');
			goto again;
		} else if (c == '\r')
			goto msdos;
		unch(c);
		return '\\';
	case '?': /* trigraphs */
		if ((c = inpch()) != '?') {
			unch(c);
			return '?';
		}
		switch (c = inpch()) {
		case '=': c = '#'; break;
		case '(': c = '['; break;
		case ')': c = ']'; break;
		case '<': c = '{'; break;
		case '>': c = '}'; break;
		case '/': c = '\\'; break;
		case '\'': c = '^'; break;
		case '!': c = '|'; break;
		case '-': c = '~'; break;
		default:
			unch(c);
			unch('?');
			return '?';
		}
		unch(c);
		goto again;
	default:
		return c;
	}
}

/*
 * Let the command-line args be faked defines at beginning of file.
 */
static void
prinit(struct initar *it, struct includ *ic)
{
	char *a, *pre, *post;

	if (it->next)
		prinit(it->next, ic);
	pre = post = NULL; /* XXX gcc */
	switch (it->type) {
	case 'D':
		pre = "#define ";
		if ((a = strchr(it->str, '=')) != NULL) {
			*a = ' ';
			post = "\n";
		} else
			post = " 1\n";
		break;
	case 'U':
		pre = "#undef ";
		post = "\n";
		break;
	case 'i':
		pre = "#include \"";
		post = "\"\n";
		break;
	default:
		error("prinit");
	}
	strlcat((char *)ic->buffer, pre, CPPBUF+1);
	strlcat((char *)ic->buffer, it->str, CPPBUF+1);
	if (strlcat((char *)ic->buffer, post, CPPBUF+1) >= CPPBUF+1)
		error("line exceeds buffer size");

	ic->lineno--;
	while (*ic->maxread)
		ic->maxread++;
}

/*
 * A new file included.
 * If ifiles == NULL, this is the first file and already opened (stdin).
 * Return 0 on success, -1 if file to be included is not found.
 */
int
pushfile(usch *file)
{
	extern struct initar *initar;
	struct includ ibuf;
	struct includ *ic;
	int c, otrulvl;

	ic = &ibuf;
	ic->next = ifiles;

	slow = 0;
	if (file != NULL) {
		if ((ic->infil = open((char *)file, O_RDONLY)) < 0)
			return -1;
		ic->orgfn = ic->fname = file;
		if (++inclevel > MAX_INCLEVEL)
			error("Limit for nested includes exceeded");
	} else {
		ic->infil = 0;
		ic->orgfn = ic->fname = (usch *)"<stdin>";
	}
	ic->buffer = ic->bbuf+NAMEMAX;
	ic->curptr = ic->buffer;
	ifiles = ic;
	ic->lineno = 1;
	ic->maxread = ic->curptr;
	prtline();
	if (initar) {
		*ic->maxread = 0;
		prinit(initar, ic);
		if (dMflag)
			write(ofd, ic->buffer, strlen((char *)ic->buffer));
		initar = NULL;
	}

	otrulvl = trulvl;

	if ((c = yylex()) != 0)
		error("yylex returned %d", c);

	if (otrulvl != trulvl || flslvl)
		error("unterminated conditional");

	ifiles = ic->next;
	close(ic->infil);
	inclevel--;
	return 0;
}

/*
 * Print current position to output file.
 */
void
prtline()
{
	usch *s, *os = stringbuf;

	if (Mflag) {
		if (dMflag)
			return; /* no output */
		if (ifiles->lineno == 1) {
			s = sheap("%s: %s\n", Mfile, ifiles->fname);
			write(ofd, s, strlen((char *)s));
		}
	} else if (!Pflag)
		putstr(sheap("# %d \"%s\"\n", ifiles->lineno, ifiles->fname));
	stringbuf = os;
}

void
cunput(int c)
{
#ifdef PCC_DEBUG
	extern int dflag;
	if (dflag)printf(": '%c'(%d)", c > 31 ? c : ' ', c);
#endif
	unput(c);
}

int yywrap(void) { return 1; }

static int
dig2num(int c)
{
	if (c >= 'a')
		c = c - 'a' + 10;
	else if (c >= 'A')
		c = c - 'A' + 10;
	else
		c = c - '0';
	return c;
}

/*
 * Convert string numbers to unsigned long long and check overflow.
 */
static void
cvtdig(int rad)
{
	unsigned long long rv = 0;
	unsigned long long rv2 = 0;
	char *y = yytext;
	int c;

	c = *y++;
	if (rad == 16)
		y++;
	while (isxdigit(c)) {
		rv = rv * rad + dig2num(c);
		/* check overflow */
		if (rv / rad < rv2)
			error("Constant \"%s\" is out of range", yytext);
		rv2 = rv;
		c = *y++;
	}
	y--;
	while (*y == 'l' || *y == 'L')
		y++;
	yylval.node.op = *y == 'u' || *y == 'U' ? UNUMBER : NUMBER;
	yylval.node.nd_uval = rv;
	if ((rad == 8 || rad == 16) && yylval.node.nd_val < 0)
		yylval.node.op = UNUMBER;
	if (yylval.node.op == NUMBER && yylval.node.nd_val < 0)
		/* too large for signed */
		error("Constant \"%s\" is out of range", yytext);
}

static int
charcon(usch *p)
{
	int val, c;

	p++; /* skip first ' */
	val = 0;
	if (*p++ == '\\') {
		switch (*p++) {
		case 'a': val = '\a'; break;
		case 'b': val = '\b'; break;
		case 'f': val = '\f'; break;
		case 'n': val = '\n'; break;
		case 'r': val = '\r'; break;
		case 't': val = '\t'; break;
		case 'v': val = '\v'; break;
		case '\"': val = '\"'; break;
		case '\'': val = '\''; break;
		case '\\': val = '\\'; break;
		case 'x':
			while (isxdigit(c = *p)) {
				val = val * 16 + dig2num(c);
				p++;
			}
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7':
			p--;
			while (isdigit(c = *p)) {
				val = val * 8 + (c - '0');
				p++;
			}
			break;
		default: val = p[-1];
		}

	} else
		val = p[-1];
	return val;
}

static void
chknl(int ignore)
{
	int t;

	slow = 1;
	while ((t = yylex()) == WSPACE)
		;
	if (t != '\n') {
		if (ignore) {
			warning("newline expected, got \"%s\"", yytext);
			/* ignore rest of line */
			while ((t = yylex()) && t != '\n')
				;
		}
		else
			error("newline expected, got \"%s\"", yytext);
	}
	slow = 0;
}

static void
elsestmt(void)
{
	if (flslvl) {
		if (elflvl > trulvl)
			;
		else if (--flslvl!=0) {
			flslvl++;
		} else {
			trulvl++;
			prtline();
		}
	} else if (trulvl) {
		flslvl++;
		trulvl--;
	} else
		error("If-less else");
	if (elslvl==trulvl+flslvl)
		error("Too many else");
	elslvl=trulvl+flslvl;
	chknl(1);
}

static void
ifdefstmt(void)		 
{ 
	int t;

	if (flslvl) {
		/* just ignore the rest of the line */
		while (input() != '\n')
			;
		unput('\n');
		yylex();
		flslvl++;
		return;
	}
	slow = 1;
	do
		t = yylex();
	while (t == WSPACE);
	if (t != IDENT)
		error("bad ifdef");
	slow = 0;
	if (flslvl == 0 && lookup((usch *)yytext, FIND) != 0)
		trulvl++;
	else
		flslvl++;
	chknl(0);
}

static void
ifndefstmt(void)	  
{ 
	int t;

	slow = 1;
	do
		t = yylex();
	while (t == WSPACE);
	if (t != IDENT)
		error("bad ifndef");
	slow = 0;
	if (flslvl == 0 && lookup((usch *)yytext, FIND) == 0)
		trulvl++;
	else
		flslvl++;
	chknl(0);
}

static void
endifstmt(void)		 
{
	if (flslvl) {
		flslvl--;
		if (flslvl == 0)
			prtline();
	} else if (trulvl)
		trulvl--;
	else
		error("If-less endif");
	if (flslvl == 0)
		elflvl = 0;
	elslvl = 0;
	chknl(1);
}

/*
 * Note! Ugly!
 * Walk over the string s and search for defined, and replace it with 
 * spaces and a 1 or 0. 
 */
static void
fixdefined(usch *s)
{
	usch *bc, oc;

	for (; *s; s++) {
		if (*s != 'd')
			continue;
		if (memcmp(s, "defined", 7))
			continue;
		/* Ok, got defined, can scratch it now */
		memset(s, ' ', 7);
		s += 7;
#define	WSARG(x) (x == ' ' || x == '\t')
		if (*s != '(' && !WSARG(*s))
			continue;
		while (WSARG(*s))
			s++;
		if (*s == '(')
			s++;
		while (WSARG(*s))
			s++;
#define IDARG(x) ((x>= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x == '_'))
#define	NUMARG(x) (x >= '0' && x <= '9')
		if (!IDARG(*s))
			error("bad defined arg");
		bc = s;
		while (IDARG(*s) || NUMARG(*s))
			s++;
		oc = *s;
		*s = 0;
		*bc = (lookup(bc, FIND) != 0) + '0';
		memset(bc+1, ' ', s-bc-1);
		*s = oc;
	}
}

/*
 * get the full line of identifiers after an #if, pushback a WARN and
 * the line and prepare for expmac() to expand.
 * This is done before switching state.  When expmac is finished,
 * pushback the expanded line, change state and call yyparse.
 */
static void
storepb(void)
{
	usch *opb = stringbuf;
	int c;

	while ((c = input()) != '\n') {
		if (c == '/') {
			 if ((c = input()) == '*') {
				/* ignore comments here whatsoever */
				usch *g = stringbuf;
				getcmnt();
				stringbuf = g;
				continue;
			} else if (c == '/') {
				while ((c = input()) && c != '\n')
					;
				break;
			}
			unput(c);
			c = '/';
		}
		savch(c);
	}
	cunput('\n');
	savch(0);
	fixdefined(opb); /* XXX can fail if #line? */
	cunput(1); /* WARN XXX */
	unpstr(opb);
	stringbuf = opb;
	slow = 1;
	expmac(NULL);
	slow = 0;
	/* line now expanded */
	while (stringbuf > opb)
		cunput(*--stringbuf);
}

static void
ifstmt(void)
{
	if (flslvl == 0) {
		slow = 1;
		if (yyparse())
			++trulvl;
		else
			++flslvl;
		slow = 0;
	} else
		++flslvl;
}

static void
elifstmt(void)
{
	if (flslvl == 0)
		elflvl = trulvl;
	if (flslvl) {
		if (elflvl > trulvl)
			;
		else if (--flslvl!=0)
			++flslvl;
		else {
			slow = 1;
			if (yyparse()) {
				++trulvl;
				prtline();
			} else
				++flslvl;
			slow = 0;
		}
	} else if (trulvl) {
		++flslvl;
		--trulvl;
	} else
		error("If-less elif");
}

static usch *
svinp(void)
{
	int c;
	usch *cp = stringbuf;

	while ((c = input()) && c != '\n')
		savch(c);
	savch('\n');
	savch(0);
	BEGIN 0;
	return cp;
}

static void
cpperror(void)
{
	usch *cp;
	int c;

	if (flslvl)
		return;
	c = yylex();
	if (c != WSPACE && c != '\n')
		error("bad error");
	cp = svinp();
	if (flslvl)
		stringbuf = cp;
	else
		error("%s", cp);
}

static void
undefstmt(void)
{
	struct symtab *np;

	slow = 1;
	if (yylex() != WSPACE || yylex() != IDENT)
		error("bad undef");
	if (flslvl == 0 && (np = lookup((usch *)yytext, FIND)))
		np->value = 0;
	slow = 0;
	chknl(0);
}

static void
pragmastmt(void)
{
	int c;

	slow = 1;
	if (yylex() != WSPACE)
		error("bad pragma");
	if (!flslvl)
		putstr((usch *)"#pragma ");
	do {
		c = input();
		if (!flslvl)
			putch(c);	/* Do arg expansion instead? */
	} while (c && c != '\n');
	ifiles->lineno++;
	prtline();
	slow = 0;
}

static void
badop(const char *op)
{
	error("invalid operator in preprocessor expression: %s", op);
}

int
cinput()
{
	return input();
}
