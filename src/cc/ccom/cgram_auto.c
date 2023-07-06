/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 145 "./cgram.y" /* yacc.c:339  */

# include "pass1.h"
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

#ifdef __STRICT_ANSI__  /* For __GNUC__. */
extern int snprintf(char *str, size_t size, const char *format, ...);
#endif

int fun_inline;	/* Reading an inline function */
int oldstyle;	/* Current function being defined */
static struct symtab *xnf;
extern int enummer, tvaloff, inattr;
extern struct rstack *rpole;
static int widestr, alwinl;
NODE *cftnod;
static int attrwarn = 1;

#define	NORETYP	SNOCREAT /* no return type, save in unused field in symtab */

       NODE *bdty(int op, ...);
static void fend(void);
static void fundef(NODE *tp, NODE *p);
static void olddecl(NODE *p, NODE *a);
static struct symtab *init_declarator(NODE *tn, NODE *p, int assign, NODE *a,
	char *as);
static void resetbc(int mask);
static void swend(void);
static void addcase(NODE *p);
#ifdef GCC_COMPAT
static void gcccase(NODE *p, NODE *);
#endif
static struct attr *gcc_attr_wrapper(NODE *p);
static void adddef(void);
static void savebc(void);
static void swstart(int, TWORD);
static void genswitch(int, TWORD, struct swents **, int);
static char *mkpstr(char *str);
static struct symtab *clbrace(NODE *);
static NODE *cmop(NODE *l, NODE *r);
static NODE *xcmop(NODE *out, NODE *in, NODE *str);
static void mkxasm(char *str, NODE *p);
static NODE *xasmop(char *str, NODE *p);
static char *stradd(char *old, char *new);
static NODE *biop(int op, NODE *l, NODE *r);
static void flend(void);
static char * simname(char *s);
static NODE *tyof(NODE *);	/* COMPAT_GCC */
static NODE *voidcon(void);
static NODE *funargs(NODE *p);
static void oldargs(NODE *p);
static void uawarn(NODE *p, char *s);
static int con_e(NODE *p);
static void dainit(NODE *d, NODE *a);
static NODE *tymfix(NODE *p);
static NODE *namekill(NODE *p, int clr);
static NODE *aryfix(NODE *p);
static void savlab(int);
static void xcbranch(NODE *, int);
extern int *mkclabs(void);

#define	TYMFIX(inp) { \
	NODE *pp = inp; \
	inp = tymerge(pp->n_left, pp->n_right); \
	nfree(pp->n_left); nfree(pp); }
/*
 * State for saving current switch state (when nested switches).
 */
struct savbc {
	struct savbc *next;
	int brklab;
	int contlab;
	int flostat;
	int swx;
} *savbc, *savctx;


#line 141 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    C_STRING = 258,
    C_ICON = 259,
    C_FCON = 260,
    C_NAME = 261,
    C_TYPENAME = 262,
    C_ANDAND = 263,
    C_OROR = 264,
    C_GOTO = 265,
    C_RETURN = 266,
    C_TYPE = 267,
    C_CLASS = 268,
    C_ASOP = 269,
    C_RELOP = 270,
    C_EQUOP = 271,
    C_DIVOP = 272,
    C_SHIFTOP = 273,
    C_INCOP = 274,
    C_UNOP = 275,
    C_STROP = 276,
    C_STRUCT = 277,
    C_IF = 278,
    C_ELSE = 279,
    C_SWITCH = 280,
    C_BREAK = 281,
    C_CONTINUE = 282,
    C_WHILE = 283,
    C_DO = 284,
    C_FOR = 285,
    C_DEFAULT = 286,
    C_CASE = 287,
    C_SIZEOF = 288,
    C_ALIGNOF = 289,
    C_ENUM = 290,
    C_ELLIPSIS = 291,
    C_QUALIFIER = 292,
    C_FUNSPEC = 293,
    C_ASM = 294,
    NOMATCH = 295,
    C_TYPEOF = 296,
    C_ATTRIBUTE = 297,
    PCC_OFFSETOF = 298,
    GCC_DESIG = 299
  };
#endif
/* Tokens.  */
#define C_STRING 258
#define C_ICON 259
#define C_FCON 260
#define C_NAME 261
#define C_TYPENAME 262
#define C_ANDAND 263
#define C_OROR 264
#define C_GOTO 265
#define C_RETURN 266
#define C_TYPE 267
#define C_CLASS 268
#define C_ASOP 269
#define C_RELOP 270
#define C_EQUOP 271
#define C_DIVOP 272
#define C_SHIFTOP 273
#define C_INCOP 274
#define C_UNOP 275
#define C_STROP 276
#define C_STRUCT 277
#define C_IF 278
#define C_ELSE 279
#define C_SWITCH 280
#define C_BREAK 281
#define C_CONTINUE 282
#define C_WHILE 283
#define C_DO 284
#define C_FOR 285
#define C_DEFAULT 286
#define C_CASE 287
#define C_SIZEOF 288
#define C_ALIGNOF 289
#define C_ENUM 290
#define C_ELLIPSIS 291
#define C_QUALIFIER 292
#define C_FUNSPEC 293
#define C_ASM 294
#define NOMATCH 295
#define C_TYPEOF 296
#define C_ATTRIBUTE 297
#define PCC_OFFSETOF 298
#define GCC_DESIG 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 220 "./cgram.y" /* yacc.c:355  */

	int intval;
	NODE *nodep;
	struct symtab *symp;
	struct rstack *rp;
	char *strp;

#line 277 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 292 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

/* Proper declaration of memcpy(...) in case __builtin_memcpy(...) uses it. Useful for minilibc686 with TinyCC, PCC and Clang. GCC doesn't seem to need it. */
#include <string.h>
#if defined(__clang__)
#  define __builtin_memcpy memcpy
#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1987

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  264
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  488

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,     2,
      56,    58,    54,    52,    45,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    57,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    59,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,    49,    61,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   254,   254,   255,   258,   259,   260,   261,   262,   265,
     269,   272,   273,   282,   285,   286,   287,   288,   291,   292,
     300,   301,   302,   303,   304,   307,   308,   312,   313,   317,
     320,   321,   324,   329,   330,   338,   339,   343,   344,   348,
     349,   350,   353,   357,   360,   361,   362,   363,   364,   365,
     366,   369,   376,   384,   385,   390,   393,   398,   399,   409,
     410,   420,   421,   430,   436,   440,   446,   447,   451,   452,
     456,   457,   461,   465,   469,   472,   476,   480,   483,   488,
     491,   492,   498,   499,   503,   508,   512,   521,   522,   525,
     526,   536,   537,   548,   549,   549,   555,   556,   559,   560,
     563,   564,   567,   568,   569,   570,   573,   582,   586,   589,
     601,   604,   605,   608,   609,   612,   613,   617,   622,   623,
     627,   630,   631,   635,   636,   636,   640,   650,   656,   668,
     683,   695,   698,   708,   711,   715,   723,   727,   730,   733,
     734,   735,   738,   739,   742,   743,   744,   745,   748,   749,
     752,   760,   765,   772,   773,   776,   781,   782,   785,   808,
     809,   810,   811,   817,   826,   839,   851,   859,   867,   875,
     886,   916,   917,   918,   919,   920,   921,   922,   925,   926,
     929,   930,   933,   934,   935,   938,   939,   942,   943,   948,
     949,   952,   953,   954,   955,   960,   963,   971,   976,   986,
    1000,  1014,  1014,  1027,  1052,  1053,  1056,  1057,  1060,  1061,
    1062,  1067,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1093,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1107,  1108,
    1112,  1116,  1124,  1129,  1134,  1135,  1138,  1139,  1140,  1141,
    1142,  1159,  1160,  1161,  1162,  1163,  1171,  1179,  1187,  1198,
    1201,  1204,  1205,  1208,  1211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "C_STRING", "C_ICON", "C_FCON", "C_NAME",
  "C_TYPENAME", "C_ANDAND", "C_OROR", "C_GOTO", "C_RETURN", "C_TYPE",
  "C_CLASS", "C_ASOP", "C_RELOP", "C_EQUOP", "C_DIVOP", "C_SHIFTOP",
  "C_INCOP", "C_UNOP", "C_STROP", "C_STRUCT", "C_IF", "C_ELSE", "C_SWITCH",
  "C_BREAK", "C_CONTINUE", "C_WHILE", "C_DO", "C_FOR", "C_DEFAULT",
  "C_CASE", "C_SIZEOF", "C_ALIGNOF", "C_ENUM", "C_ELLIPSIS", "C_QUALIFIER",
  "C_FUNSPEC", "C_ASM", "NOMATCH", "C_TYPEOF", "C_ATTRIBUTE",
  "PCC_OFFSETOF", "GCC_DESIG", "','", "'='", "'?'", "':'", "'|'", "'^'",
  "'&'", "'+'", "'-'", "'*'", "'['", "'('", "';'", "')'", "']'", "'{'",
  "'}'", "$accept", "ext_def_list", "external_def", "funtype", "kr_args",
  "declaration_specifiers", "merge_attribs", "type_sq", "cf_spec",
  "typeof", "attribute_specifier", "attribute_list", "attribute",
  "declarator", "ecq", "r", "c", "type_qualifier_list", "identifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "abstract_declarator", "ib2", "maybe_r", "arg_dcl_list",
  "arg_declaration", "arg_param_list", "block_item_list", "block_item",
  "declaration", "init_declarator_list", "@1", "enum_dcl", "enum_head",
  "moe_list", "moe", "struct_dcl", "attr_var", "attr_spec_list",
  "str_head", "struct_dcl_list", "struct_declaration", "optsemi",
  "specifier_qualifier_list", "merge_specifiers", "struct_declarator_list",
  "@2", "struct_declarator", "xnfdeclarator", "init_declarator", "begbr",
  "initializer", "init_list", "designation", "designator_list",
  "designator", "optcomma", "ibrace", "compoundstmt", "begin", "statement",
  "asmstatement", "mvol", "xasm", "oplist", "oper", "cnstr", "label",
  "doprefix", "ifprefix", "ifelprefix", "whprefix", "forprefix", "$@3",
  "switchpart", ".e", "elist", "e2", "e", "xbegin", "term", "xa",
  "clbrace", "string", "cast_type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    44,    61,    63,    58,   124,
      94,    38,    43,    45,    42,    91,    40,    59,    41,    93,
     123,   125
};
# endif

#define YYPACT_NINF -320

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-320)))

#define YYTABLE_NINF -206

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -320,   427,  -320,  -320,  -320,  -320,  -320,  -320,   -22,    19,
    -320,  -320,     4,     0,    15,   237,    82,  -320,  -320,  1180,
      16,  -320,  1180,  1180,  -320,  -320,    51,  -320,  -320,   -14,
    -320,     6,    73,  -320,    46,   -22,    75,  -320,    98,  1068,
     106,  -320,  -320,    51,   246,   275,    82,   109,   107,  1180,
    -320,  -320,   907,     3,   138,  -320,  -320,  -320,  1110,   133,
     174,    92,  -320,   130,  -320,   184,  -320,  -320,  -320,   152,
     204,  1275,  1275,  -320,  -320,   161,  1275,  1275,  1275,  1275,
     788,  1147,   403,  -320,  1473,   376,   234,   168,   239,  -320,
    -320,    51,  -320,   334,  -320,  -320,   489,   185,    10,  -320,
     210,   225,   -22,  -320,   830,  -320,   216,  1275,   217,  1152,
     249,  -320,  1920,  -320,  -320,   103,   -19,   229,   253,  -320,
     262,   267,   256,  -320,  -320,   255,  -320,   251,    20,  1068,
    -320,   376,   376,  1316,   254,  1147,   376,   376,   376,   376,
    -320,  1487,   672,   259,  -320,   214,  1193,   270,   193,  1275,
    1275,  1275,  1275,  1275,  1275,  1275,  1275,  1275,  1234,  1275,
    1275,  1275,  1275,  1275,  1275,  -320,  -320,   223,  1275,  1068,
    -320,  -320,   258,   263,   284,  -320,   -10,     2,   289,    36,
     972,   292,   306,   283,   314,   326,  -320,   328,   339,  1275,
    -320,  -320,    16,   550,  -320,  -320,  -320,  -320,   337,   730,
     730,   730,   730,   730,  1275,   730,  1717,  -320,   107,  -320,
     184,  -320,  -320,   122,  1045,  -320,  1275,  1275,  1920,  -320,
    1275,    56,   180,   185,   193,   385,  -320,  -320,  1000,  1275,
    1275,   174,   335,  -320,  -320,  1275,   941,   119,  -320,   184,
    -320,   340,   342,   357,  1045,  -320,   788,   376,  1147,   358,
    -320,   611,  1730,   872,   322,   193,   348,  1346,   -22,   387,
    1180,  1193,   353,   850,   844,  1045,   398,   352,  -320,   327,
    1045,  1045,  1275,  1861,   420,   750,   802,   125,   125,  -320,
    -320,  -320,  1393,   355,  1068,   368,   239,  -320,  -320,   -22,
     -22,   372,  1275,  -320,  1743,  1275,  1275,  -320,  -320,  1275,
    1013,  -320,  1850,   264,  -320,  -320,  -320,   289,  -320,   416,
     422,  -320,  -320,   389,  1920,  -320,  -320,   185,    37,   107,
     248,  -320,  1275,  -320,   409,   914,   127,  -320,  1920,  1920,
      63,  -320,  -320,  -320,  -320,  1045,  1045,  -320,  -320,  1045,
    1275,  -320,  -320,  -320,   404,   412,   418,    18,  -320,  -320,
    1068,   417,   419,  1275,   428,  1790,   406,  -320,   376,   290,
     193,   -22,   -22,  -320,  -320,   430,   432,  1404,   -22,  1180,
     762,  1275,  -320,  -320,   431,  -320,  -320,  -320,  -320,  -320,
    1803,  -320,  1534,  1548,  1595,  1180,   421,  1275,  -320,   442,
    -320,   730,  -320,    74,  -320,  -320,  -320,  1329,   297,   415,
    -320,  -320,   311,  1045,  -320,  1275,  -320,  1933,   251,  -320,
     184,   184,  1275,  1045,  -320,   939,  -320,   354,  -320,   443,
     445,  -320,   409,  -320,  -320,   -22,   -22,   -22,  -320,   447,
     762,  -320,  -320,  -320,  -320,  -320,  1275,  1275,  1873,  1275,
    -320,  -320,  1275,  -320,   914,  -320,  -320,   409,  1415,   -22,
    -320,   458,    40,  1609,  -320,   449,  -320,   464,  -320,  -320,
    -320,   -22,   453,   472,  -320,  1656,  1462,  -320,   473,   184,
    1275,  -320,  -320,  -320,  -320,  -320,  -320,   476,   490,  -320,
     492,   234,  1670,  -320,  -320,   184,  -320,   234
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     1,     8,    37,    19,    18,    25,   109,    98,
      22,    26,   180,     0,     0,     0,     0,     7,     2,    11,
       0,    13,    14,    16,    24,    23,     9,     5,    21,     0,
      20,     0,     0,   111,   113,   110,    97,   181,     0,     0,
       0,    53,    55,    35,     0,     0,     0,     0,     0,    12,
      82,    91,    10,     0,     0,    93,    15,    17,    80,     0,
       0,     0,     6,   107,   112,     0,   261,   251,   252,   249,
       0,     0,     0,   259,   259,     0,     0,     0,     0,     0,
       0,   122,   263,   120,     0,   229,   253,     0,    32,    54,
      56,    36,    39,     0,   158,     4,     0,   109,     0,    83,
       0,   133,   109,    92,     0,    52,    51,    49,     0,     0,
      80,    44,    45,    57,    43,    65,     0,     0,    59,    61,
     102,   103,   153,   100,   108,     0,   115,   130,     0,   206,
     258,   237,   236,     0,     0,     0,   233,   235,   234,   232,
     230,     0,     0,     0,   121,    66,    80,    79,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,   231,     0,     0,   206,
     262,    28,    33,     0,    30,    38,     0,   249,    19,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,     0,
     174,   157,     0,     0,    87,    89,   160,    90,     0,     0,
       0,     0,     0,     0,   205,     0,     0,    85,     0,    84,
       0,    94,   138,   147,   135,    40,    50,     0,    46,    81,
       0,    66,    79,   109,    64,     0,    42,    41,     0,     0,
       0,   154,     0,   106,   116,     0,   109,     0,   123,   185,
     178,     0,     0,   207,   208,   211,     0,   238,     0,     0,
     254,     0,     0,     0,    67,    68,     0,     0,   109,     0,
       0,    80,    79,   218,   217,   214,   223,   222,   227,   224,
     212,   213,     0,     0,   219,   220,   221,   225,   226,   228,
     247,   248,     0,     0,   206,     0,    32,   175,   176,   109,
     109,     0,     0,   169,     0,     0,     0,   167,   168,     0,
     201,   195,     0,   109,   156,    88,   173,     0,   177,     0,
     161,   162,   163,     0,   204,   166,   159,   109,     0,     0,
       0,   145,     0,   137,   153,     0,     0,   148,    48,    47,
      67,    63,    58,    60,    62,   104,   105,   101,    96,   127,
       0,   126,   124,   118,   117,   182,   186,     0,   179,   245,
       0,     0,     0,     0,     0,     0,   159,   260,   239,   147,
      69,   109,   109,    75,    70,     0,     0,     0,   109,     0,
     216,     0,   244,   246,     0,    29,    31,   191,   192,   171,
       0,   170,     0,     0,     0,     0,     0,     0,   193,     0,
     198,     0,    86,   109,    95,   152,   151,     0,   147,     0,
     155,   142,   147,   139,   144,     0,   149,   128,   130,   119,
     185,     0,     0,   209,   210,   240,   241,     0,   257,   159,
       0,   243,   153,    71,    72,   109,   109,   109,    77,     0,
     215,    34,   172,   197,   203,   199,   205,   205,     0,     0,
     165,   134,     0,   150,     0,   136,   141,   153,     0,   129,
     125,   183,     0,     0,   250,     0,   255,     0,    76,    73,
      74,   109,     0,     0,   194,     0,     0,   143,     0,     0,
       0,   187,   256,   242,    78,   202,   200,     0,     0,   140,
     184,   189,     0,   164,   146,     0,   188,   190
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -320,  -320,  -320,  -320,  -320,     5,   236,    -4,  -320,  -320,
      -8,   252,  -320,    17,  -320,  -320,   426,  -130,  -320,  -247,
    -320,   316,   -66,   277,  -101,  -320,   498,  -320,   410,  -176,
       1,  -320,  -320,  -320,  -320,  -320,   317,  -320,    -5,    -6,
    -320,  -320,   434,  -320,   -42,   483,  -320,  -320,   157,  -320,
     247,  -320,   123,  -300,   170,  -320,   245,  -319,  -320,   527,
     -79,  -171,   585,  -320,  -320,   186,  -320,  -320,  -320,  -320,
    -320,  -320,  -320,  -320,  -320,  -320,  -286,  -158,  -320,    43,
    -320,     8,   516,  -320,   -61,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    47,   192,    21,    22,    23,    24,
      25,   173,   174,    43,   108,   109,   110,    44,   116,   117,
     118,   119,   255,   260,   111,    49,    50,    98,   193,   194,
     195,    53,   319,    28,    29,   122,   123,    30,   101,    35,
      31,   125,   126,   344,    82,    83,   237,   408,   238,    54,
      55,   213,   401,   324,   325,   326,   327,   232,   402,   196,
      96,   197,   198,    38,   241,   345,   346,   480,   199,   200,
     201,   202,   203,   204,   385,   205,   313,   242,   243,   206,
     142,    85,   133,   359,    86,   245
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   140,    27,    34,   128,   399,    20,    42,    33,   220,
      46,   283,    87,   365,   386,   254,   148,   305,    26,   127,
      14,   170,     4,   170,    48,    36,   225,    64,   308,   309,
     310,   311,   312,    45,   315,    81,    90,    52,    64,   226,
     170,    37,   291,   170,    33,   256,    60,   287,   102,   224,
     289,   288,    63,   143,    48,   208,    39,    81,   129,   422,
     103,    91,     4,    93,   115,    97,    61,   209,   239,     4,
      15,    40,    16,    51,   412,   305,    81,    81,   240,   131,
     132,   259,    84,   127,   136,   137,   138,   139,     4,    33,
     292,   330,   207,    41,    33,   393,   470,   211,    14,     5,
      89,   112,   447,   457,     6,    14,    58,    59,   249,     4,
     221,   146,   222,     4,     8,   139,    14,   221,   146,   222,
    -132,    81,   429,   141,    14,    81,   374,     9,   468,    10,
      62,    81,   223,    13,    14,   -99,    15,    42,    16,   113,
       5,   247,   154,   320,   236,     6,     7,   214,   320,   318,
     462,   463,   218,   124,    65,     8,   259,   221,   146,   222,
     366,    15,    88,    16,   342,    81,   321,   140,     9,    94,
      10,    11,   244,   404,    13,    14,   343,   322,   347,   164,
     120,   121,   405,   323,   104,   252,     4,    66,   360,   257,
    -114,   114,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   273,   274,   275,   276,   277,   278,   279,   129,   303,
     130,   282,   244,    42,    33,    33,    46,   135,   331,   351,
     440,   352,    14,   294,   139,   317,   171,    14,    33,   280,
     281,   341,   302,   115,   221,   146,   222,   170,   258,    45,
      58,    59,    81,     4,    81,   172,    90,   314,   261,   262,
      33,    41,     4,   363,   395,   396,    14,     4,    56,    57,
     328,   358,     5,   329,   360,   115,   210,     6,   145,   146,
     147,  -131,   335,   336,    41,   -81,   215,     8,   339,    14,
      81,    33,    33,    89,   377,   378,   219,   227,    14,   141,
       9,    15,    10,    16,   355,    33,    13,    14,   228,   235,
      15,   231,    16,   100,   367,    15,    14,    16,   229,    33,
     248,   320,   392,   230,   284,   370,   233,   253,   320,    58,
      59,   285,    90,   414,   145,   146,   147,   244,   258,   286,
      58,    59,   320,    92,   321,   380,   303,   290,   382,   383,
     297,   321,   384,   314,   154,   322,    81,    91,   295,   347,
     452,   421,   322,    33,    33,   321,   423,   424,  -154,    89,
      33,   417,   296,   428,    14,   397,   322,   152,   403,   154,
     155,   298,   446,   166,   115,   167,   145,   146,   147,   162,
     163,   164,   299,   407,   300,    33,   436,   301,   441,    58,
      59,   332,   175,   413,   306,   166,   338,   167,   348,    33,
     349,   449,   350,   353,   162,   163,   164,   361,   481,   168,
     169,   368,   454,   373,   430,   154,   155,    33,    33,    33,
     458,   459,   460,   358,   487,   236,   375,     2,     3,   379,
     438,   168,   169,     4,     5,   152,   153,   154,   155,     6,
       7,    64,   261,   262,   389,   364,   390,   391,   448,     8,
     162,   163,   164,    33,   398,   453,   474,   145,   146,   147,
     410,   409,     9,   411,    10,    11,    12,   420,    13,    14,
     160,   161,   162,   163,   164,   415,   445,   416,   437,   314,
     314,    15,   465,    16,    17,   466,   418,   403,   425,   431,
     176,   426,    66,    67,    68,   177,   178,    70,   439,   179,
     180,     6,     7,   456,   455,   461,   469,   472,    71,    72,
     475,     8,   181,   482,   182,   183,   184,   185,   186,   187,
     188,   189,    73,    74,     9,   473,    10,    11,    12,   476,
      13,    14,    75,   483,   479,   217,   484,   485,   376,   369,
      76,    77,    78,    79,   334,    80,   190,    99,   337,    94,
     191,   176,   251,    66,    67,    68,   177,   178,    70,   234,
     179,   180,     6,     7,   144,   450,   394,   467,   444,    71,
      72,   406,     8,   181,    95,   182,   183,   184,   185,   186,
     187,   188,   189,    73,    74,     9,    32,    10,    11,    12,
     134,    13,    14,    75,     0,     0,   451,     0,     0,     0,
       0,    76,    77,    78,    79,     0,    80,   190,     0,     0,
      94,   304,   176,     0,    66,    67,    68,   177,   178,    70,
       0,   179,   180,     6,     7,     0,     0,     0,     0,     0,
      71,    72,     0,     8,   181,     0,   182,   183,   184,   185,
     186,   187,   188,   189,    73,    74,     9,     0,    10,    11,
      12,     0,    13,    14,    75,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79,     0,    80,   190,     0,
       0,    94,   354,   176,     0,    66,    67,    68,   177,   178,
      70,     0,   179,   180,     6,     7,     0,     0,     0,     0,
       0,    71,    72,     0,     8,   181,     0,   182,   183,   184,
     185,   186,   187,   188,   189,    73,    74,     9,     0,    10,
      11,    12,     0,    13,    14,    75,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,     0,    80,   190,
       0,   176,    94,    66,    67,    68,   177,   307,    70,     0,
     179,   180,     0,     0,     0,     0,     0,     0,     0,    71,
      72,     0,     0,   181,     0,   182,   183,   184,   185,   186,
     187,   188,   189,    73,    74,   152,   153,   154,   155,    12,
     149,   150,     0,    75,     0,     0,     0,   152,   153,   154,
     155,    76,    77,    78,    79,     0,    80,   190,     0,     0,
      94,    66,    67,    68,    69,     5,    70,     0,     0,     0,
       6,   161,   162,   163,   164,     0,     0,    71,    72,   158,
       8,   159,   160,   161,   162,   163,   164,   152,   153,   154,
     155,    73,    74,     9,     0,    10,     0,     0,     0,    13,
      14,    75,     0,    66,    67,    68,    69,     0,    70,    76,
      77,    78,    79,     0,    80,     0,     0,     0,    94,    71,
      72,     0,   149,     0,   162,   163,   164,     0,     0,   152,
     153,   154,   155,    73,    74,   152,   153,   154,   155,     0,
       0,     0,     0,    75,     0,    66,    67,    68,    69,     0,
      70,    76,    77,    78,    79,     0,    80,     0,     0,     0,
     212,    71,    72,   159,   160,   161,   162,   163,   164,   159,
     160,   161,   162,   163,   164,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     0,    66,    67,    68,
      69,     0,    70,    76,    77,    78,    79,     0,    80,     0,
       0,     0,   357,    71,    72,     0,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,   100,    73,    74,    14,
       0,     0,  -109,  -109,     0,     0,     0,    75,    71,    72,
       0,     0,    58,    59,  -109,    76,    77,    78,    79,     0,
      80,     0,    73,    74,   400,    66,    67,    68,    69,     0,
      70,     0,    75,    14,     0,     0,     0,     0,     0,   340,
       0,    71,    72,     0,     0,    80,    58,    59,     0,   357,
       0,     0,     0,     0,     0,    73,    74,     5,     0,     0,
       0,     0,     6,     7,     0,    75,    66,    67,    68,    69,
       0,    70,     8,    76,    77,    78,    79,     0,    80,   293,
       0,     0,    71,    72,     0,     9,   333,    10,    11,     0,
       0,    13,    14,     0,     0,     0,    73,    74,     0,     0,
       0,     0,     0,   149,   150,     0,    75,     0,     0,   151,
     152,   153,   154,   155,    76,    77,    78,    79,     0,    80,
    -205,    66,    67,    68,    69,     5,    70,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,    71,    72,     0,
       8,   157,   158,     0,   159,   160,   161,   162,   163,   164,
       0,    73,    74,     9,     0,    10,     0,     0,     0,    13,
      14,    75,     0,    66,    67,    68,    69,     0,    70,    76,
      77,    78,    79,   105,    80,     0,     0,     0,     0,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,   106,     0,     0,
       0,     0,     0,    75,     5,    66,    67,    68,    69,     6,
      70,    76,    77,    78,   107,   105,    80,     0,     0,     8,
       0,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,    73,    74,     5,    13,    14,
       0,     0,     6,     7,     0,    75,    66,    67,    68,    69,
       0,    70,     8,    76,    77,    78,   216,     0,    80,     0,
       0,     0,    71,    72,     0,     9,     0,    10,    11,     0,
       0,    13,    14,     0,     0,     0,    73,    74,     0,     0,
     219,     0,     0,     0,     0,     0,    75,    66,    67,    68,
      69,     0,    70,     0,    76,    77,    78,    79,     0,    80,
       0,     0,     0,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    66,    67,
      68,    69,   272,    70,     0,    76,    77,    78,    79,     0,
      80,     0,     0,     0,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    66,
      67,    68,    69,     0,    70,     0,    76,    77,    78,    79,
       0,    80,     0,     0,     0,    71,    72,   149,   150,     0,
       0,     0,     0,   151,   152,   153,   154,   155,     0,    73,
      74,     0,     0,     0,   149,   150,     0,     0,     0,    75,
     151,   152,   153,   154,   155,   442,     0,    76,    77,    78,
      79,     0,   246,     0,   156,   157,   158,     0,   159,   160,
     161,   162,   163,   164,     0,     0,     0,     0,   443,     0,
       0,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   149,   150,     0,     0,   362,     0,   151,   152,   153,
     154,   155,   149,   150,     0,     0,     0,     0,   151,   152,
     153,   154,   155,   149,   150,     0,     0,     0,     0,   151,
     152,   153,   154,   155,     0,     0,     0,     0,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,     0,   156,
     157,   158,   372,   159,   160,   161,   162,   163,   164,     0,
     156,   157,   158,   427,   159,   160,   161,   162,   163,   164,
     149,   150,     0,     0,   443,     0,   151,   152,   153,   154,
     155,   149,   150,     0,     0,     0,     0,   151,   152,   153,
     154,   155,     0,     0,     0,   149,   150,     0,     0,     0,
       0,   151,   152,   153,   154,   155,     0,   156,   157,   158,
       0,   159,   160,   161,   162,   163,   164,     0,   156,   157,
     158,   478,   159,   160,   161,   162,   163,   164,     0,     0,
       0,   165,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,   149,   150,     0,   250,     0,     0,   151,   152,
     153,   154,   155,     0,     0,     0,   149,   150,     0,     0,
       0,     0,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,     0,
       0,     0,   433,   156,   157,   158,     0,   159,   160,   161,
     162,   163,   164,   149,   150,     0,   434,     0,     0,   151,
     152,   153,   154,   155,     0,     0,     0,   149,   150,     0,
       0,     0,     0,   151,   152,   153,   154,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
       0,     0,     0,   435,   156,   157,   158,     0,   159,   160,
     161,   162,   163,   164,   149,   150,     0,   471,     0,     0,
     151,   152,   153,   154,   155,     0,     0,     0,   149,   150,
       0,     0,     0,     0,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,     0,     0,     0,   477,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,   149,   150,     0,   486,     0,
       0,   151,   152,   153,   154,   155,     0,     0,   149,   150,
       0,     0,     0,     0,   151,   152,   153,   154,   155,     0,
       0,   149,   150,     0,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,     0,     0,   316,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,     0,     0,   356,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   149,   150,
     381,     0,     0,     0,   151,   152,   153,   154,   155,     0,
       0,   149,   150,     0,     0,     0,     0,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,     0,     0,   419,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   149,   150,
     432,     0,     0,     0,   151,   152,   153,   154,   155,   149,
     150,     0,     0,     0,     0,   151,   152,   153,   154,   155,
       0,   149,   150,     0,     0,     0,   387,   151,   152,   153,
     154,   155,     0,     0,     0,   156,   157,   158,   388,   159,
     160,   161,   162,   163,   164,     0,   156,   157,   158,   371,
     159,   160,   161,   162,   163,   164,     0,     0,   156,   157,
     158,   464,   159,   160,   161,   162,   163,   164,   149,   150,
       0,     0,     0,     0,   151,   152,   153,   154,   155,     0,
       0,   149,   150,     0,     0,     0,     0,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,    14,     0,     0,     0,   157,
     158,     0,   159,   160,   161,   162,   163,   164
};

static const yytype_int16 yycheck[] =
{
       8,    80,     1,     8,    65,   324,     1,    15,    16,   110,
      16,   169,    39,   260,   300,   145,    82,   193,     1,    61,
      42,     3,     6,     3,    19,     6,    45,    35,   199,   200,
     201,   202,   203,    16,   205,    39,    44,    20,    46,    58,
       3,    37,     6,     3,    52,   146,    60,    57,    45,   115,
      48,    61,     6,    80,    49,    45,    56,    61,    56,   359,
      57,    44,     6,    46,    59,    48,    60,    57,    48,     6,
      54,    56,    56,    57,    56,   251,    80,    81,    58,    71,
      72,   147,    39,   125,    76,    77,    78,    79,     6,    97,
      54,   221,    97,    37,   102,    58,    56,   102,    42,     7,
      37,    58,   402,   422,    12,    42,    55,    56,   135,     6,
      54,    55,    56,     6,    22,   107,    42,    54,    55,    56,
      46,   125,   369,    80,    42,   129,   284,    35,   447,    37,
      57,   135,   115,    41,    42,    60,    54,   145,    56,     6,
       7,   133,    17,    21,   127,    12,    13,   104,    21,   210,
     436,   437,   109,    61,    56,    22,   222,    54,    55,    56,
     261,    54,    56,    56,    45,   169,    44,   246,    35,    60,
      37,    38,   129,    46,    41,    42,    57,    55,   239,    54,
       6,     7,    55,    61,    46,   142,     6,     3,   254,   146,
      60,    58,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    56,   192,
       6,   168,   169,   221,   222,   223,   222,    56,   223,   246,
     391,   248,    42,   180,   216,   208,    58,    42,   236,     6,
       7,   236,   189,   228,    54,    55,    56,     3,    58,   222,
      55,    56,   246,     6,   248,     6,   254,   204,    55,    56,
     258,    37,     6,   258,     6,     7,    42,     6,    22,    23,
     217,   253,     7,   220,   330,   260,    56,    12,    54,    55,
      56,    46,   229,   230,    37,    59,    59,    22,   235,    42,
     284,   289,   290,    37,   289,   290,    37,    58,    42,   246,
      35,    54,    37,    56,   251,   303,    41,    42,    45,    48,
      54,    45,    56,    39,   261,    54,    42,    56,    46,   317,
      56,    21,   317,    46,    56,   272,    61,    58,    21,    55,
      56,    58,   330,   350,    54,    55,    56,   284,    58,    45,
      55,    56,    21,    58,    44,   292,   319,    48,   295,   296,
      57,    44,   299,   300,    17,    55,   350,   330,    56,   410,
     411,    61,    55,   361,   362,    44,   361,   362,    61,    37,
     368,   353,    56,   368,    42,   322,    55,    15,   325,    17,
      18,    57,    61,    19,   369,    21,    54,    55,    56,    52,
      53,    54,    56,   340,    56,   393,   385,    48,   393,    55,
      56,     6,    58,   350,    57,    19,    61,    21,    58,   407,
      58,   407,    45,    45,    52,    53,    54,    59,   469,    55,
      56,    58,    58,    58,   371,    17,    18,   425,   426,   427,
     425,   426,   427,   415,   485,   408,    58,     0,     1,    57,
     387,    55,    56,     6,     7,    15,    16,    17,    18,    12,
      13,   449,    55,    56,    28,    58,    24,    58,   405,    22,
      52,    53,    54,   461,    45,   412,   461,    54,    55,    56,
      48,    57,    35,    45,    37,    38,    39,    61,    41,    42,
      50,    51,    52,    53,    54,    58,    61,    58,    57,   436,
     437,    54,   439,    56,    57,   442,    58,   444,    58,    58,
       1,    59,     3,     4,     5,     6,     7,     8,    56,    10,
      11,    12,    13,    58,    61,    58,    48,    58,    19,    20,
      57,    22,    23,   470,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    61,    37,    38,    39,    57,
      41,    42,    43,    57,    61,   109,    46,    45,   286,   262,
      51,    52,    53,    54,   228,    56,    57,    49,   231,    60,
      61,     1,   142,     3,     4,     5,     6,     7,     8,   125,
      10,    11,    12,    13,    81,   408,   319,   444,   398,    19,
      20,   326,    22,    23,    47,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     1,    37,    38,    39,
      74,    41,    42,    43,    -1,    -1,   410,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    -1,    56,    57,    -1,    -1,
      60,    61,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    -1,    56,    57,    -1,
      -1,    60,    61,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    19,    20,    -1,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    37,
      38,    39,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    -1,    56,    57,
      -1,     1,    60,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    15,    16,    17,    18,    39,
       8,     9,    -1,    43,    -1,    -1,    -1,    15,    16,    17,
      18,    51,    52,    53,    54,    -1,    56,    57,    -1,    -1,
      60,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    51,    52,    53,    54,    -1,    -1,    19,    20,    47,
      22,    49,    50,    51,    52,    53,    54,    15,    16,    17,
      18,    33,    34,    35,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    -1,     3,     4,     5,     6,    -1,     8,    51,
      52,    53,    54,    -1,    56,    -1,    -1,    -1,    60,    19,
      20,    -1,     8,    -1,    52,    53,    54,    -1,    -1,    15,
      16,    17,    18,    33,    34,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    43,    -1,     3,     4,     5,     6,    -1,
       8,    51,    52,    53,    54,    -1,    56,    -1,    -1,    -1,
      60,    19,    20,    49,    50,    51,    52,    53,    54,    49,
      50,    51,    52,    53,    54,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,     3,     4,     5,
       6,    -1,     8,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    60,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    39,    33,    34,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    43,    19,    20,
      -1,    -1,    55,    56,    57,    51,    52,    53,    54,    -1,
      56,    -1,    33,    34,    60,     3,     4,     5,     6,    -1,
       8,    -1,    43,    42,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    19,    20,    -1,    -1,    56,    55,    56,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    33,    34,     7,    -1,    -1,
      -1,    -1,    12,    13,    -1,    43,     3,     4,     5,     6,
      -1,     8,    22,    51,    52,    53,    54,    -1,    56,    57,
      -1,    -1,    19,    20,    -1,    35,    36,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,     8,     9,    -1,    43,    -1,    -1,    14,
      15,    16,    17,    18,    51,    52,    53,    54,    -1,    56,
      57,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      22,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      -1,    33,    34,    35,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    -1,     3,     4,     5,     6,    -1,     8,    51,
      52,    53,    54,    13,    56,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    43,     7,     3,     4,     5,     6,    12,
       8,    51,    52,    53,    54,    13,    56,    -1,    -1,    22,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    37,    33,    34,     7,    41,    42,
      -1,    -1,    12,    13,    -1,    43,     3,     4,     5,     6,
      -1,     8,    22,    51,    52,    53,    54,    -1,    56,    -1,
      -1,    -1,    19,    20,    -1,    35,    -1,    37,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    33,    34,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    43,     3,     4,     5,
       6,    -1,     8,    -1,    51,    52,    53,    54,    -1,    56,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,     3,     4,
       5,     6,    48,     8,    -1,    51,    52,    53,    54,    -1,
      56,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,     3,
       4,     5,     6,    -1,     8,    -1,    51,    52,    53,    54,
      -1,    56,    -1,    -1,    -1,    19,    20,     8,     9,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,    33,
      34,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    43,
      14,    15,    16,    17,    18,    36,    -1,    51,    52,    53,
      54,    -1,    56,    -1,    45,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,     8,     9,    -1,    -1,    59,    -1,    14,    15,    16,
      17,    18,     8,     9,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,     8,     9,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    -1,    45,
      46,    47,    59,    49,    50,    51,    52,    53,    54,    -1,
      45,    46,    47,    59,    49,    50,    51,    52,    53,    54,
       8,     9,    -1,    -1,    59,    -1,    14,    15,    16,    17,
      18,     8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    54,    -1,    45,    46,
      47,    59,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    58,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,     8,     9,    -1,    58,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    58,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,     8,     9,    -1,    58,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    58,    45,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,     8,     9,    -1,    58,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    58,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,     8,     9,    -1,    58,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    -1,    -1,    57,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    -1,    -1,    57,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,     8,     9,
      57,    -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    -1,    -1,    57,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,     8,     9,
      57,    -1,    -1,    -1,    14,    15,    16,    17,    18,     8,
       9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      -1,     8,     9,    -1,    -1,    -1,    36,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,     8,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    42,    -1,    -1,    -1,    46,
      47,    -1,    49,    50,    51,    52,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,     0,     1,     6,     7,    12,    13,    22,    35,
      37,    38,    39,    41,    42,    54,    56,    57,    64,    65,
      67,    68,    69,    70,    71,    72,    75,    92,    95,    96,
      99,   102,   124,    72,   100,   101,     6,    37,   125,    56,
      56,    37,    72,    75,    79,    75,   101,    66,    67,    87,
      88,    57,    75,    93,   111,   112,    68,    68,    55,    56,
      60,    60,    57,     6,    72,    56,     3,     4,     5,     6,
       8,    19,    20,    33,    34,    43,    51,    52,    53,    54,
      56,    69,   106,   107,   141,   143,   146,   147,    56,    37,
      72,    75,    58,    75,    60,   121,   122,    75,    89,    88,
      39,   100,    45,    57,    46,    13,    37,    54,    76,    77,
      78,    86,   141,     6,    58,    67,    80,    81,    82,    83,
       6,     7,    97,    98,    61,   103,   104,   106,   146,    56,
       6,   143,   143,   144,   144,    56,   143,   143,   143,   143,
     122,   141,   142,   147,   107,    54,    55,    56,    84,     8,
       9,    14,    15,    16,    17,    18,    45,    46,    47,    49,
      50,    51,    52,    53,    54,    58,    19,    21,    55,    56,
       3,    58,     6,    73,    74,    58,     1,     6,     7,    10,
      11,    23,    25,    26,    27,    28,    29,    30,    31,    32,
      57,    61,    67,    90,    91,    92,   121,   123,   124,   130,
     131,   132,   133,   134,   135,   137,   141,   100,    45,    57,
      56,   100,    60,   113,   141,    59,    54,    78,   141,    37,
      86,    54,    56,    75,    84,    45,    58,    58,    45,    46,
      46,    45,   119,    61,   104,    48,    75,   108,   110,    48,
      58,   126,   139,   140,   141,   147,    56,   143,    56,   147,
      58,    90,   141,    58,    79,    84,    86,   141,    58,    84,
      85,    55,    56,   141,   141,   141,   141,   141,   141,   141,
     141,   141,    48,   141,   141,   141,   141,   141,   141,   141,
       6,     7,   141,   139,    56,    58,    45,    57,    61,    48,
      48,     6,    54,    57,   141,    56,    56,    57,    57,    56,
      56,    48,   141,    75,    61,    91,    57,     7,   123,   123,
     123,   123,   123,   138,   141,   123,    57,    75,   146,    94,
      21,    44,    55,    61,   115,   116,   117,   118,   141,   141,
      79,   100,     6,    36,    83,   141,   141,    98,    61,   141,
      48,   100,    45,    57,   105,   127,   128,   146,    58,    58,
      45,   147,   147,    45,    61,   141,    57,    60,   143,   145,
      84,    59,    59,   100,    58,    81,    86,   141,    58,    85,
     141,    48,    59,    58,   139,    58,    73,   100,   100,    57,
     141,    57,   141,   141,   141,   136,   138,    36,    48,    28,
      24,    58,   100,    58,   112,     6,     7,   141,    45,   119,
      60,   114,   120,   141,    46,    55,   118,   141,   109,    57,
      48,    45,    56,   141,   147,    58,    58,   143,    58,    57,
      61,    61,   115,   100,   100,    58,    59,    59,   100,    81,
     141,    58,    57,    58,    58,    58,    92,    57,   141,    56,
     123,   100,    36,    59,   116,    61,    61,   115,   141,   101,
     110,   127,   146,   141,    58,    61,    58,   119,   100,   100,
     100,    58,   138,   138,    48,   141,   141,   114,   119,    48,
      56,    58,    58,    61,   100,    57,    57,    58,    59,    61,
     129,   146,   141,    57,    46,    45,    58,   146
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    67,    68,    68,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    77,    78,    79,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      86,    86,    87,    87,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    94,    93,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    99,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   105,   105,
     106,   107,   107,   108,   109,   108,   110,   110,   110,   110,
     110,   111,   111,   112,   112,   112,   112,   112,   113,   114,
     114,   114,   115,   115,   116,   116,   116,   116,   117,   117,
     118,   118,   118,   119,   119,   120,   121,   121,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   130,   131,   132,   133,   134,
     135,   136,   135,   137,   138,   138,   139,   139,   140,   140,
     140,   140,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     142,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     145,   146,   146,   147,   147
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     3,     1,     2,     1,     1,     1,
       2,     0,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     6,
       1,     3,     0,     1,     4,     2,     3,     1,     4,     3,
       4,     4,     4,     3,     1,     1,     2,     3,     3,     1,
       2,     1,     1,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     3,     3,     2,     1,     1,     2,     2,     3,
       3,     4,     4,     5,     5,     3,     5,     4,     6,     0,
       0,     1,     1,     2,     3,     2,     4,     1,     2,     1,
       1,     2,     3,     1,     0,     5,     5,     2,     1,     2,
       1,     3,     1,     1,     3,     3,     4,     3,     3,     0,
       1,     1,     2,     2,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     1,     0,     4,     2,     2,     3,     4,
       0,     2,     5,     2,     6,     3,     6,     4,     1,     1,
       4,     2,     2,     4,     2,     1,     6,     0,     1,     2,
       3,     2,     2,     0,     1,     1,     3,     2,     1,     2,
       1,     2,     2,     2,     7,     4,     2,     2,     2,     2,
       3,     3,     4,     2,     1,     2,     2,     2,     5,     6,
       0,     1,     2,     4,     6,     0,     1,     4,     6,     1,
       3,     3,     3,     3,     5,     2,     1,     4,     3,     4,
       6,     0,     6,     4,     1,     0,     0,     1,     1,     3,
       3,     1,     3,     3,     3,     5,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     3,     4,
       5,     5,     7,     5,     4,     4,     4,     3,     3,     1,
       6,     1,     1,     1,     3,     6,     7,     5,     2,     0,
       1,     1,     2,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 255 "./cgram.y" /* yacc.c:1646  */
    { ftnend(); }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 258 "./cgram.y" /* yacc.c:1646  */
    { fend(); }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 259 "./cgram.y" /* yacc.c:1646  */
    { blevel = 0; symclear(0); }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 262 "./cgram.y" /* yacc.c:1646  */
    { blevel = 0; }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 265 "./cgram.y" /* yacc.c:1646  */
    {
		    fundef(mkty(INT, 0, 0), (yyvsp[0].nodep));
		    cftnsp->sflags |= NORETYP;
		}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 269 "./cgram.y" /* yacc.c:1646  */
    { fundef((yyvsp[-1].nodep),(yyvsp[0].nodep)); }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 282 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = typenode((yyvsp[0].nodep)); }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 285 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 286 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = cmop((yyvsp[0].nodep), (yyvsp[-1].nodep)); }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 287 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 288 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = cmop((yyvsp[0].nodep), (yyvsp[-1].nodep)); }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 291 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 292 "./cgram.y" /* yacc.c:1646  */
    { 
			struct symtab *sp = lookup((yyvsp[0].strp), 0);
			if (sp->stype == ENUMTY) {
				sp->stype = strmemb(sp->sap)->stype;
			}
			(yyval.nodep) = mkty(sp->stype, sp->sdf, sp->sap);
			(yyval.nodep)->n_sp = sp;
		}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 300 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 301 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 302 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 303 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(ATTRIB, (yyvsp[0].nodep), 0); }
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 304 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 307 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 308 "./cgram.y" /* yacc.c:1646  */
    { fun_inline = 1;  /* XXX - hack */
			(yyval.nodep) = block(CLASS, NIL, NIL, 0, 0, 0); }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 312 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = tyof(eve((yyvsp[-1].nodep))); }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 313 "./cgram.y" /* yacc.c:1646  */
    { TYMFIX((yyvsp[-1].nodep)); (yyval.nodep) = tyof((yyvsp[-1].nodep)); }
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 317 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[-2].nodep); }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 321 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = cmop((yyvsp[0].nodep), (yyvsp[-2].nodep)); }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 324 "./cgram.y" /* yacc.c:1646  */
    {
#ifdef GCC_COMPAT
			 (yyval.nodep) = voidcon();
#endif
		}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 329 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(NAME, (yyvsp[0].strp)); }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 330 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = bdty((yyvsp[-1].nodep) == NIL ? UCALL : CALL, bdty(NAME, (yyvsp[-3].strp)), (yyvsp[-1].nodep));
		}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 338 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(UMUL, (yyvsp[0].nodep)); }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 339 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = (yyvsp[-1].nodep);
			(yyval.nodep)->n_left = (yyvsp[0].nodep);
		}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 343 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(NAME, (yyvsp[0].strp)); }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 344 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = (yyvsp[-1].nodep);
			(yyval.nodep)->n_ap = attr_add((yyval.nodep)->n_ap, gcc_attr_wrapper((yyvsp[-2].nodep)));
		}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 348 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[-1].nodep); }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 349 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(LB, (yyvsp[-3].nodep), (yyvsp[-1].nodep)); }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 350 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = bdty(CALL, (yyvsp[-3].nodep), (yyvsp[-1].nodep));
		}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 353 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = bdty(CALL, (yyvsp[-3].nodep), (yyvsp[-1].nodep));
			oldstyle = 1;
		}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 357 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(UCALL, (yyvsp[-2].nodep)); }
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 360 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bcon(NOOFFSET); }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 361 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 362 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 363 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 364 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 365 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bcon(NOOFFSET); }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 366 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bcon(NOOFFSET); }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 369 "./cgram.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].nodep)->n_qual != 0)
				uerror("bad qualifier");
			nfree((yyvsp[0].nodep));
		}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 376 "./cgram.y" /* yacc.c:1646  */
    {
			if ((yyvsp[0].nodep)->n_type != STATIC)
				uerror("bad class keyword");
			nfree((yyvsp[0].nodep));
		}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 384 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); (yyval.nodep)->n_op = UMUL; }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 385 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = (yyvsp[-1].nodep);
			(yyval.nodep)->n_qual |= (yyvsp[0].nodep)->n_qual;
			nfree((yyvsp[0].nodep));
		}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 390 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(UMUL, NIL, NIL, 0, 0, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 393 "./cgram.y" /* yacc.c:1646  */
    {
			(yyvsp[-1].nodep)->n_ap = attr_add((yyvsp[-1].nodep)->n_ap, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 398 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(NAME, (yyvsp[0].strp)); oldargs((yyval.nodep)); }
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 399 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = cmop((yyvsp[-2].nodep), bdty(NAME, (yyvsp[0].strp)));
			oldargs((yyval.nodep)->n_right);
		}
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 409 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 410 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = cmop((yyvsp[-2].nodep), biop(ELLIPSIS, NIL, NIL));
		}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 420 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 421 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = cmop((yyvsp[-2].nodep), (yyvsp[0].nodep));
		}
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 430 "./cgram.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].nodep)->n_lval != SNULL && (yyvsp[-2].nodep)->n_lval != REGISTER)
				uerror("illegal parameter class");
			(yyval.nodep) = block(TYMERGE, (yyvsp[-2].nodep), (yyvsp[-1].nodep), INT, 0,
			    gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 436 "./cgram.y" /* yacc.c:1646  */
    { 
			(yyvsp[-1].nodep)->n_ap = attr_add((yyvsp[-1].nodep)->n_ap, (yyvsp[0].nodep)->n_ap);
			(yyval.nodep) = block(TYMERGE, (yyvsp[-1].nodep), (yyvsp[0].nodep), INT, 0, 0);
		}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 440 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(TYMERGE, (yyvsp[0].nodep), bdty(NAME, NULL), INT, 0, 0);
		}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 446 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(UMUL, bdty(NAME, NULL)); }
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 447 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = (yyvsp[0].nodep);
			(yyval.nodep)->n_left = bdty(NAME, NULL);
		}
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 451 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(UMUL, (yyvsp[0].nodep)); }
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 452 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = (yyvsp[-1].nodep);
			(yyval.nodep)->n_left = (yyvsp[0].nodep);
		}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 456 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[-1].nodep); }
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 457 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(LB, bdty(NAME, NULL), bcon(NOOFFSET),
			    INT, 0, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 461 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(LB, bdty(NAME, NULL), (yyvsp[-2].nodep),
			    INT, 0, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 465 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(LB, (yyvsp[-4].nodep), bcon(NOOFFSET),
			    INT, 0, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 469 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(LB, (yyvsp[-4].nodep), (yyvsp[-2].nodep), INT, 0, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 472 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = bdty(UCALL, bdty(NAME, NULL));
			(yyval.nodep)->n_ap = gcc_attr_wrapper((yyvsp[0].nodep));
		}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 476 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(CALL, bdty(NAME, NULL), (yyvsp[-2].nodep), INT, 0,
			    gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 480 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(UCALL, (yyvsp[-3].nodep), NIL, INT, 0, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 483 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = block(CALL, (yyvsp[-5].nodep), (yyvsp[-2].nodep), INT, 0, gcc_attr_wrapper((yyvsp[0].nodep)));
		}
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 488 "./cgram.y" /* yacc.c:1646  */
    { }
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 491 "./cgram.y" /* yacc.c:1646  */
    { }
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 492 "./cgram.y" /* yacc.c:1646  */
    { nfree((yyvsp[0].nodep)); }
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 503 "./cgram.y" /* yacc.c:1646  */
    {
			nfree((yyvsp[-2].nodep));
		}
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 508 "./cgram.y" /* yacc.c:1646  */
    {
			olddecl(block(TYMERGE, ccopy((yyvsp[-2].nodep)), (yyvsp[-1].nodep),
			    INT, 0, 0), (yyvsp[0].nodep));
		}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 512 "./cgram.y" /* yacc.c:1646  */
    {
			olddecl(block(TYMERGE, ccopy((yyvsp[-4].nodep)), (yyvsp[-1].nodep),
			    INT, 0, 0), (yyvsp[0].nodep));
		}
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 536 "./cgram.y" /* yacc.c:1646  */
    { tfree((yyvsp[-1].nodep)); fun_inline = 0; }
#line 2584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 537 "./cgram.y" /* yacc.c:1646  */
    {
			tfree((yyvsp[-2].nodep));
			fun_inline = 0;
		}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 548 "./cgram.y" /* yacc.c:1646  */
    { symclear(blevel); }
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 549 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[-3].nodep); }
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 549 "./cgram.y" /* yacc.c:1646  */
    {
			uawarn((yyvsp[-2].nodep), "init_declarator");
			symclear(blevel);
		}
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 555 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = enumdcl((yyvsp[-4].symp)); }
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 556 "./cgram.y" /* yacc.c:1646  */
    {  (yyval.nodep) = enumref((yyvsp[0].strp)); }
#line 2626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 559 "./cgram.y" /* yacc.c:1646  */
    { (yyval.symp) = enumhd(NULL); }
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 560 "./cgram.y" /* yacc.c:1646  */
    {  (yyval.symp) = enumhd((yyvsp[0].strp)); }
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 567 "./cgram.y" /* yacc.c:1646  */
    {  moedef((yyvsp[0].strp)); }
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 568 "./cgram.y" /* yacc.c:1646  */
    {  moedef((yyvsp[0].strp)); }
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 569 "./cgram.y" /* yacc.c:1646  */
    { enummer = con_e((yyvsp[0].nodep)); moedef((yyvsp[-2].strp)); }
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 570 "./cgram.y" /* yacc.c:1646  */
    { enummer = con_e((yyvsp[0].nodep)); moedef((yyvsp[-2].strp)); }
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 573 "./cgram.y" /* yacc.c:1646  */
    {
			NODE *p;

			(yyval.nodep) = dclstruct((yyvsp[-3].rp));
			if (pragma_allpacked) {
				p = bdty(CALL, bdty(NAME, "packed"),
				    bcon(pragma_allpacked));
				(yyval.nodep)->n_ap = attr_add((yyval.nodep)->n_ap,gcc_attr_wrapper(p)); }
		}
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 582 "./cgram.y" /* yacc.c:1646  */
    { 
			(yyval.nodep) = rstruct((yyvsp[0].strp),(yyvsp[-2].intval));
			uawarn((yyvsp[-1].nodep), "struct_dcl");
		}
#line 2685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 586 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = dclstruct((yyvsp[-2].rp)); }
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 589 "./cgram.y" /* yacc.c:1646  */
    {	
			NODE *q, *p;

			p = pragma_aligned ? bdty(CALL, bdty(NAME, "aligned"),
			    bcon(pragma_aligned)) : NIL;
			if (pragma_packed) {
				q = bdty(NAME, "packed");
				p = (p == NIL ? q : cmop(p, q));
			}
			pragma_aligned = pragma_packed = 0;
			(yyval.nodep) = p;
		}
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 605 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = cmop((yyvsp[-1].nodep), (yyvsp[0].nodep)); }
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 608 "./cgram.y" /* yacc.c:1646  */
    {  (yyval.rp) = bstruct(NULL, (yyvsp[-1].intval), (yyvsp[0].nodep));  }
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 609 "./cgram.y" /* yacc.c:1646  */
    {  (yyval.rp) = bstruct((yyvsp[0].strp), (yyvsp[-2].intval), (yyvsp[-1].nodep));  }
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 617 "./cgram.y" /* yacc.c:1646  */
    {
			tfree((yyvsp[-2].nodep));
		}
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 622 "./cgram.y" /* yacc.c:1646  */
    { }
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 623 "./cgram.y" /* yacc.c:1646  */
    { werror("extra ; in struct"); }
#line 2746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 627 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = typenode((yyvsp[0].nodep)); }
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 630 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = cmop((yyvsp[0].nodep), (yyvsp[-1].nodep)); }
#line 2758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 631 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 635 "./cgram.y" /* yacc.c:1646  */
    { symclear(blevel); }
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 636 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep)=(yyvsp[-2].nodep); }
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 637 "./cgram.y" /* yacc.c:1646  */
    { symclear(blevel); }
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 640 "./cgram.y" /* yacc.c:1646  */
    {
			NODE *p;

			(yyvsp[-1].nodep) = aryfix((yyvsp[-1].nodep));
			p = tymerge((yyvsp[-2].nodep), tymfix((yyvsp[-1].nodep)));
			if ((yyvsp[0].nodep))
				p->n_ap = attr_add(p->n_ap, gcc_attr_wrapper((yyvsp[0].nodep)));
			soumemb(p, (char *)(yyvsp[-1].nodep)->n_sp, 0);
			tfree(p);
		}
#line 2797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 650 "./cgram.y" /* yacc.c:1646  */
    {
			int ie = con_e((yyvsp[0].nodep));
			if (fldchk(ie))
				ie = 1;
			falloc(NULL, ie, (yyvsp[-2].nodep));
		}
#line 2808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 656 "./cgram.y" /* yacc.c:1646  */
    {
			int ie = con_e((yyvsp[0].nodep));
			if (fldchk(ie))
				ie = 1;
			if ((yyvsp[-2].nodep)->n_op == NAME) {
				/* XXX - tymfix() may alter $1 */
				tymerge((yyvsp[-3].nodep), tymfix((yyvsp[-2].nodep)));
				soumemb((yyvsp[-2].nodep), (char *)(yyvsp[-2].nodep)->n_sp, FIELD | ie);
				nfree((yyvsp[-2].nodep));
			} else
				uerror("illegal declarator");
		}
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 668 "./cgram.y" /* yacc.c:1646  */
    {
			int ie = con_e((yyvsp[-1].nodep));
			if (fldchk(ie))
				ie = 1;
			if ((yyvsp[-3].nodep)->n_op == NAME) {
				/* XXX - tymfix() may alter $1 */
				tymerge((yyvsp[-4].nodep), tymfix((yyvsp[-3].nodep)));
				if ((yyvsp[0].nodep))
					(yyvsp[-3].nodep)->n_ap = attr_add((yyvsp[-3].nodep)->n_ap,
					    gcc_attr_wrapper((yyvsp[0].nodep)));
				soumemb((yyvsp[-3].nodep), (char *)(yyvsp[-3].nodep)->n_sp, FIELD | ie);
				nfree((yyvsp[-3].nodep));
			} else
				uerror("illegal declarator");
		}
#line 2845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 683 "./cgram.y" /* yacc.c:1646  */
    {
			NODE *p = (yyvsp[0].nodep);
			char *c = permalloc(10);

			if (p->n_type != STRTY && p->n_type != UNIONTY)
				uerror("bad unnamed member type");
			snprintf(c, 10, "*%dFAKE", getlab());
			soumemb(p, c, 0);
		}
#line 2859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 695 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.symp) = xnf = init_declarator((yyvsp[-2].nodep), (yyvsp[-1].nodep), 1, (yyvsp[0].nodep), 0);
		}
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 698 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.symp) = xnf = init_declarator((yyvsp[-5].nodep), (yyvsp[-4].nodep), 1, NULL, 
			    newstring((yyvsp[-1].strp), strlen((yyvsp[-1].strp))));
		}
#line 2876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 708 "./cgram.y" /* yacc.c:1646  */
    {
			init_declarator((yyvsp[-2].nodep), (yyvsp[-1].nodep), 0, (yyvsp[0].nodep), 0);
		}
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 711 "./cgram.y" /* yacc.c:1646  */
    {
			init_declarator((yyvsp[-6].nodep), (yyvsp[-5].nodep), 0, (yyvsp[0].nodep),
			    newstring((yyvsp[-2].strp), strlen((yyvsp[-2].strp))));
		}
#line 2893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 715 "./cgram.y" /* yacc.c:1646  */
    { 
			if ((yyvsp[-2].symp)->sclass == STATIC || (yyvsp[-2].symp)->sclass == EXTDEF)
				statinit++;
			simpleinit((yyvsp[-2].symp), eve((yyvsp[0].nodep)));
			if ((yyvsp[-2].symp)->sclass == STATIC || (yyvsp[-2].symp)->sclass == EXTDEF)
				statinit--;
			xnf = NULL;
		}
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 723 "./cgram.y" /* yacc.c:1646  */
    {
			endinit(0);
			xnf = NULL;
		}
#line 2915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 727 "./cgram.y" /* yacc.c:1646  */
    { endinit(0); xnf = NULL; }
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 730 "./cgram.y" /* yacc.c:1646  */
    { beginit((yyvsp[(-1) - (1)].symp)); }
#line 2927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 733 "./cgram.y" /* yacc.c:1646  */
    {  (yyval.nodep) = eve((yyvsp[0].nodep)); }
#line 2933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 734 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = NULL; }
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 735 "./cgram.y" /* yacc.c:1646  */
    { asginit(bcon(0)); (yyval.nodep) = NULL; }
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 738 "./cgram.y" /* yacc.c:1646  */
    { dainit((yyvsp[-1].nodep), (yyvsp[0].nodep)); }
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 739 "./cgram.y" /* yacc.c:1646  */
    { dainit((yyvsp[-1].nodep), (yyvsp[0].nodep)); }
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 742 "./cgram.y" /* yacc.c:1646  */
    { desinit((yyvsp[-1].nodep)); (yyval.nodep) = NIL; }
#line 2963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 743 "./cgram.y" /* yacc.c:1646  */
    { desinit(bdty(NAME, (yyvsp[0].strp))); (yyval.nodep) = NIL; }
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 744 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(CM, (yyvsp[-4].nodep), (yyvsp[-2].nodep)); }
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 745 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = NIL; }
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 748 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 2987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 749 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); (yyval.nodep)->n_left = (yyvsp[-1].nodep); }
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 752 "./cgram.y" /* yacc.c:1646  */
    {
			int ie = con_e((yyvsp[-1].nodep));
			if (ie < 0) {
				uerror("designator must be non-negative");
				ie = 0;
			}
			(yyval.nodep) = biop(LB, NIL, bcon(ie));
		}
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 760 "./cgram.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].intval) != DOT)
				uerror("invalid designator");
			(yyval.nodep) = bdty(NAME, (yyvsp[0].strp));
		}
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 765 "./cgram.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].intval) != DOT)
				uerror("invalid designator");
			(yyval.nodep) = bdty(NAME, (yyvsp[0].strp));
		}
#line 3026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 776 "./cgram.y" /* yacc.c:1646  */
    {  ilbrace(); }
#line 3032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 781 "./cgram.y" /* yacc.c:1646  */
    { flend(); }
#line 3038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 782 "./cgram.y" /* yacc.c:1646  */
    { flend(); }
#line 3044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 785 "./cgram.y" /* yacc.c:1646  */
    {
			struct savbc *bc = tmpalloc(sizeof(struct savbc));
			if (blevel == 1) {
#ifdef STABS
				if (gflag)
					stabs_line(lineno);
#endif
				dclargs();
			}
#ifdef STABS
			if (gflag && blevel > 1)
				stabs_lbrac(blevel+1);
#endif
			++blevel;
			oldstyle = 0;
			bc->contlab = autooff;
			bc->next = savctx;
			savctx = bc;
			if (!isinlining && sspflag && blevel == 2)
				sspstart();
		}
#line 3070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 808 "./cgram.y" /* yacc.c:1646  */
    { ecomp(eve((yyvsp[-1].nodep))); symclear(blevel); }
#line 3076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 810 "./cgram.y" /* yacc.c:1646  */
    { plabel((yyvsp[-1].intval)); reached = 1; }
#line 3082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 811 "./cgram.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].intval) != NOLAB) {
				plabel( (yyvsp[-1].intval));
				reached = 1;
			}
		}
#line 3093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 817 "./cgram.y" /* yacc.c:1646  */
    {
			branch(contlab);
			plabel( brklab );
			if( (flostat&FBRK) || !(flostat&FLOOP))
				reached = 1;
			else
				reached = 0;
			resetbc(0);
		}
#line 3107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 826 "./cgram.y" /* yacc.c:1646  */
    {
			plabel(contlab);
			if (flostat & FCONT)
				reached = 1;
			if (reached)
				cbranch(buildtree(NE, eve((yyvsp[-2].nodep)), bcon(0)),
				    bcon((yyvsp[-6].intval)));
			else
				tfree(eve((yyvsp[-2].nodep)));
			plabel( brklab);
			reached = 1;
			resetbc(0);
		}
#line 3125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 840 "./cgram.y" /* yacc.c:1646  */
    {  plabel( contlab );
			    if( flostat&FCONT ) reached = 1;
			    if( (yyvsp[-2].nodep) ) ecomp( (yyvsp[-2].nodep) );
			    branch((yyvsp[-3].intval));
			    plabel( brklab );
			    if( (flostat&FBRK) || !(flostat&FLOOP) ) reached = 1;
			    else reached = 0;
			    resetbc(0);
			    blevel--;
			    symclear(blevel);
			    }
#line 3141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 852 "./cgram.y" /* yacc.c:1646  */
    { if( reached ) branch( brklab );
			    plabel( (yyvsp[-1].intval) );
			    swend();
			    plabel( brklab);
			    if( (flostat&FBRK) || !(flostat&FDEF) ) reached = 1;
			    resetbc(FCONT);
			    }
#line 3153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 859 "./cgram.y" /* yacc.c:1646  */
    {
			if (brklab == NOLAB)
				uerror("illegal break");
			else if (reached)
				branch(brklab);
			flostat |= FBRK;
			reached = 0;
		}
#line 3166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 867 "./cgram.y" /* yacc.c:1646  */
    {
			if (contlab == NOLAB)
				uerror("illegal continue");
			else
				branch(contlab);
			flostat |= FCONT;
			goto rch;
		}
#line 3179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 875 "./cgram.y" /* yacc.c:1646  */
    {
			branch(retlab);
			if (cftnsp->stype != VOID && 
			    (cftnsp->sflags & NORETYP) == 0 &&
			    cftnsp->stype != VOID+FTN)
				uerror("return value required");
			rch:
			if (!reached)
				warner(Wunreachable_code);
			reached = 0;
		}
#line 3195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 886 "./cgram.y" /* yacc.c:1646  */
    {
			NODE *p, *q;

			p = nametree(cftnsp);
			p->n_type = DECREF(p->n_type);
			q = eve((yyvsp[-1].nodep));
#ifdef TARGET_TIMODE  
			NODE *r;
			if ((r = gcc_eval_ticast(RETURN, p, q)) != NULL)
				q = r;
#endif
#ifndef NO_COMPLEX
			if (ANYCX(q) || ANYCX(p))
				q = cxret(q, p);
#endif
			p = buildtree(RETURN, p, q);
			if (p->n_type == VOID) {
				ecomp(p->n_right);
			} else {
				if (cftnod == NIL)
					cftnod = tempnode(0, p->n_type,
					    p->n_df, p->n_ap);
				ecomp(buildtree(ASSIGN,
				    ccopy(cftnod), p->n_right));
			}
			tfree(p->n_left);
			nfree(p);
			branch(retlab);
			reached = 0;
		}
#line 3230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 916 "./cgram.y" /* yacc.c:1646  */
    { gotolabel((yyvsp[-1].strp)); goto rch; }
#line 3236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 917 "./cgram.y" /* yacc.c:1646  */
    { ecomp(biop(GOTO, eve((yyvsp[-1].nodep)), NIL)); }
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 925 "./cgram.y" /* yacc.c:1646  */
    { send_passt(IP_ASM, mkpstr((yyvsp[-1].strp))); }
#line 3248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 926 "./cgram.y" /* yacc.c:1646  */
    { mkxasm((yyvsp[-2].strp), (yyvsp[-1].nodep)); }
#line 3254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 930 "./cgram.y" /* yacc.c:1646  */
    { nfree((yyvsp[0].nodep)); }
#line 3260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 933 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = xcmop((yyvsp[0].nodep), NIL, NIL); }
#line 3266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 934 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = xcmop((yyvsp[-2].nodep), (yyvsp[0].nodep), NIL); }
#line 3272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 935 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = xcmop((yyvsp[-4].nodep), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 938 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = NIL; }
#line 3284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 939 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 3290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 942 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = xasmop((yyvsp[-3].strp), pconvert(eve((yyvsp[-1].nodep)))); }
#line 3296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 943 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = cmop((yyvsp[-5].nodep), xasmop((yyvsp[-3].strp), pconvert(eve((yyvsp[-1].nodep)))));
		}
#line 3304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 948 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = xasmop((yyvsp[0].strp), bcon(0)); }
#line 3310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 949 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = cmop((yyvsp[-2].nodep), xasmop((yyvsp[0].strp), bcon(0))); }
#line 3316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 952 "./cgram.y" /* yacc.c:1646  */
    { deflabel((yyvsp[-2].strp), (yyvsp[0].nodep)); reached = 1; }
#line 3322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 953 "./cgram.y" /* yacc.c:1646  */
    { deflabel((yyvsp[-2].strp), (yyvsp[0].nodep)); reached = 1; }
#line 3328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 954 "./cgram.y" /* yacc.c:1646  */
    { addcase(eve((yyvsp[-1].nodep))); reached = 1; }
#line 3334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 955 "./cgram.y" /* yacc.c:1646  */
    {
#ifdef GCC_COMPAT
			gcccase(eve((yyvsp[-3].nodep)), eve((yyvsp[-1].nodep))); reached = 1;
#endif
		}
#line 3344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 960 "./cgram.y" /* yacc.c:1646  */
    { reached = 1; adddef(); flostat |= FDEF; }
#line 3350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 963 "./cgram.y" /* yacc.c:1646  */
    {
			savebc();
			brklab = getlab();
			contlab = getlab();
			plabel(  (yyval.intval) = getlab());
			reached = 1;
		}
#line 3362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 971 "./cgram.y" /* yacc.c:1646  */
    {
			xcbranch(eve((yyvsp[-1].nodep)), (yyval.intval) = getlab());
			reached = 1;
		}
#line 3371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 976 "./cgram.y" /* yacc.c:1646  */
    {
			if (reached)
				branch((yyval.intval) = getlab());
			else
				(yyval.intval) = NOLAB;
			plabel( (yyvsp[-2].intval));
			reached = 1;
		}
#line 3384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 986 "./cgram.y" /* yacc.c:1646  */
    {
			savebc();
			(yyvsp[-1].nodep) = eve((yyvsp[-1].nodep));
			if ((yyvsp[-1].nodep)->n_op == ICON && (yyvsp[-1].nodep)->n_lval != 0)
				flostat = FLOOP;
			plabel( contlab = getlab());
			reached = 1;
			brklab = getlab();
			if (flostat == FLOOP)
				tfree((yyvsp[-1].nodep));
			else
				xcbranch((yyvsp[-1].nodep), brklab);
		}
#line 3402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1000 "./cgram.y" /* yacc.c:1646  */
    {
			++blevel;
			if ((yyvsp[-3].nodep))
				ecomp((yyvsp[-3].nodep));
			savebc();
			contlab = getlab();
			brklab = getlab();
			plabel( (yyval.intval) = getlab());
			reached = 1;
			if ((yyvsp[-1].nodep))
				xcbranch((yyvsp[-1].nodep), brklab);
			else
				flostat |= FLOOP;
		}
#line 3421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1014 "./cgram.y" /* yacc.c:1646  */
    { ++blevel; }
#line 3427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1014 "./cgram.y" /* yacc.c:1646  */
    {
			savebc();
			contlab = getlab();
			brklab = getlab();
			plabel( (yyval.intval) = getlab());
			reached = 1;
			if ((yyvsp[-1].nodep))
				xcbranch((yyvsp[-1].nodep), brklab);
			else
				flostat |= FLOOP;
		}
#line 3443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1027 "./cgram.y" /* yacc.c:1646  */
    {
			NODE *p;
			int num;
			TWORD t;

			savebc();
			brklab = getlab();
			(yyvsp[-1].nodep) = eve((yyvsp[-1].nodep));
			if (!ISINTEGER((yyvsp[-1].nodep)->n_type)) {
				uerror("switch expression must have integer "
				       "type");
				t = INT;
			} else {
				(yyvsp[-1].nodep) = intprom((yyvsp[-1].nodep));
				t = (yyvsp[-1].nodep)->n_type;
			}
			p = tempnode(0, t, 0, 0);
			num = regno(p);
			ecomp(buildtree(ASSIGN, p, (yyvsp[-1].nodep)));
			branch( (yyval.intval) = getlab());
			swstart(num, t);
			reached = 0;
		}
#line 3471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1052 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = eve((yyvsp[0].nodep)); }
#line 3477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1053 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep)=0; }
#line 3483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1056 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = NIL; }
#line 3489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1057 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 3495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1061 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(CM, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1062 "./cgram.y" /* yacc.c:1646  */
    { /* hack for stdarg */
			TYMFIX((yyvsp[0].nodep));
			(yyvsp[0].nodep)->n_op = TYPE;
			(yyval.nodep) = biop(CM, (yyvsp[-2].nodep), (yyvsp[0].nodep));
		}
#line 3511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1067 "./cgram.y" /* yacc.c:1646  */
    { TYMFIX((yyvsp[0].nodep)); (yyvsp[0].nodep)->n_op = TYPE; (yyval.nodep) = (yyvsp[0].nodep); }
#line 3517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1073 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(COMOP, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1074 "./cgram.y" /* yacc.c:1646  */
    {  (yyval.nodep) = biop(ASSIGN, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1075 "./cgram.y" /* yacc.c:1646  */
    {  (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1076 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep)=biop(QUEST, (yyvsp[-4].nodep), biop(COLON, (yyvsp[-2].nodep), (yyvsp[0].nodep))); }
#line 3541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1077 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(BIQUEST, (yyvsp[-3].nodep), (yyvsp[0].nodep)); }
#line 3547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1078 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1079 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1080 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(OR, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1081 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(ER, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1082 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(AND, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1083 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1084 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1085 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1086 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(PLUS, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1087 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(MINUS, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1088 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1089 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(MUL, (yyvsp[-2].nodep), (yyvsp[0].nodep)); }
#line 3619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1093 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.intval) = getlab(); getlab(); getlab();
			branch((yyval.intval)); plabel(((yyval.intval))+1); }
#line 3627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1098 "./cgram.y" /* yacc.c:1646  */
    {  (yyval.nodep) = biop((yyvsp[0].intval), (yyvsp[-1].nodep), bcon(1)); }
#line 3633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1099 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(UMUL, (yyvsp[0].nodep), NIL); }
#line 3639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1100 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(ADDROF, (yyvsp[0].nodep), NIL); }
#line 3645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1101 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(UMINUS, (yyvsp[0].nodep), NIL ); }
#line 3651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1102 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(UPLUS, (yyvsp[0].nodep), NIL ); }
#line 3657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1103 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[0].nodep), NIL); }
#line 3663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1104 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = biop((yyvsp[-1].intval) == INCR ? PLUSEQ : MINUSEQ, (yyvsp[0].nodep), bcon(1));
		}
#line 3671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1107 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(SZOF, (yyvsp[0].nodep), bcon(0)); inattr = (yyvsp[-1].intval); }
#line 3677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1108 "./cgram.y" /* yacc.c:1646  */
    {
			TYMFIX((yyvsp[-2].nodep));
			(yyval.nodep) = biop(CAST, (yyvsp[-2].nodep), (yyvsp[0].nodep));
		}
#line 3686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1112 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = biop(SZOF, (yyvsp[-1].nodep), bcon(1));
			inattr = (yyvsp[-3].intval);
		}
#line 3695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1116 "./cgram.y" /* yacc.c:1646  */
    {
			int al;
			TYMFIX((yyvsp[-1].nodep));
			al = talign((yyvsp[-1].nodep)->n_type, (yyvsp[-1].nodep)->n_ap);
			(yyval.nodep) = bcon(al/SZCHAR);
			inattr = (yyvsp[-3].intval);
			tfree((yyvsp[-1].nodep));
		}
#line 3708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1124 "./cgram.y" /* yacc.c:1646  */
    {
			endinit(0);
			(yyval.nodep) = bdty(NAME, (yyvsp[-3].symp));
			(yyval.nodep)->n_op = CLOP;
		}
#line 3718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1129 "./cgram.y" /* yacc.c:1646  */
    {
			endinit(0);
			(yyval.nodep) = bdty(NAME, (yyvsp[-1].symp));
			(yyval.nodep)->n_op = CLOP;
		}
#line 3728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1134 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop(LB, (yyvsp[-3].nodep), (yyvsp[-1].nodep)); }
#line 3734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1135 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = biop((yyvsp[-1].nodep) ? CALL : UCALL, bdty(NAME, (yyvsp[-3].strp)), (yyvsp[-1].nodep));
		}
#line 3742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1138 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].nodep) ? CALL : UCALL, (yyvsp[-3].nodep), (yyvsp[-1].nodep)); }
#line 3748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1139 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), bdty(NAME, (yyvsp[0].strp))); }
#line 3754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1140 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = biop((yyvsp[-1].intval), (yyvsp[-2].nodep), bdty(NAME, (yyvsp[0].strp)));}
#line 3760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1141 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(NAME, (yyvsp[0].strp)); }
#line 3766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1142 "./cgram.y" /* yacc.c:1646  */
    {
			TYMFIX((yyvsp[-3].nodep));
			(yyvsp[-3].nodep)->n_type = INCREF((yyvsp[-3].nodep)->n_type);
			(yyvsp[-3].nodep) = biop(CAST, (yyvsp[-3].nodep), bcon(0));
			if ((yyvsp[-1].nodep)->n_op == NAME) {
				(yyval.nodep) = biop(STREF, (yyvsp[-3].nodep), (yyvsp[-1].nodep));
			} else {
				NODE *p = (yyvsp[-1].nodep);
				while (p->n_left->n_op != NAME)
					p = p->n_left;
				p->n_left = biop(STREF, (yyvsp[-3].nodep), p->n_left);
				(yyval.nodep) = (yyvsp[-1].nodep);
			}
			(yyval.nodep) = biop(ADDROF, (yyval.nodep), NIL);
			(yyvsp[-3].nodep) = block(NAME, NIL, NIL, ENUNSIGN(INTPTR), 0, 0);
			(yyval.nodep) = biop(CAST, (yyvsp[-3].nodep), (yyval.nodep));
		}
#line 3788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1159 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 3794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1160 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = (yyvsp[0].nodep); }
#line 3800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1161 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep) = bdty(STRING, (yyvsp[0].strp), widestr); }
#line 3806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1162 "./cgram.y" /* yacc.c:1646  */
    { (yyval.nodep)=(yyvsp[-1].nodep); }
#line 3812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1163 "./cgram.y" /* yacc.c:1646  */
    {
			/* XXX - check recursive ({ }) statements */
			branch(((yyvsp[-4].intval))+2);
			plabel((yyvsp[-4].intval));
			(yyval.nodep) = buildtree(COMOP,
			    biop(GOTO, bcon(((yyvsp[-4].intval))+1), NIL), eve((yyvsp[-3].nodep)));
			flend();
		}
#line 3825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1171 "./cgram.y" /* yacc.c:1646  */
    {
			/* XXX - check recursive ({ }) statements */
			branch(((yyvsp[-5].intval))+2);
			plabel((yyvsp[-5].intval));
			(yyval.nodep) = buildtree(COMOP,
			    biop(GOTO, bcon(((yyvsp[-5].intval))+1), NIL), eve((yyvsp[-3].nodep)));
			flend();
		}
#line 3838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1179 "./cgram.y" /* yacc.c:1646  */
    { 
			/* XXX - check recursive ({ }) statements */
			branch(((yyvsp[-3].intval))+2);
			plabel((yyvsp[-3].intval));
			(yyval.nodep) = buildtree(COMOP,
			    biop(GOTO, bcon(((yyvsp[-3].intval))+1), NIL), voidcon());
			flend();
		}
#line 3851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1187 "./cgram.y" /* yacc.c:1646  */
    {
			struct symtab *s = lookup((yyvsp[0].strp), SLBLNAME);
			if (s->soffset == 0) {
				s->soffset = -getlab();
				s->sclass = STATIC;
			}
			savlab(s->soffset);
			(yyval.nodep) = biop(ADDROF, bdty(GOTO, (yyvsp[0].strp)), NIL);
		}
#line 3865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1198 "./cgram.y" /* yacc.c:1646  */
    { (yyval.intval) = inattr; inattr = 0; }
#line 3871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1201 "./cgram.y" /* yacc.c:1646  */
    { NODE *q = (yyvsp[(-1) - (1)].nodep); TYMFIX(q); (yyval.symp) = clbrace(q); }
#line 3877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1204 "./cgram.y" /* yacc.c:1646  */
    { widestr = 0; (yyval.strp) = stradd("", (yyvsp[0].strp)); }
#line 3883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1205 "./cgram.y" /* yacc.c:1646  */
    { (yyval.strp) = stradd((yyvsp[-1].strp), (yyvsp[0].strp)); }
#line 3889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1208 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = biop(TYMERGE, (yyvsp[0].nodep), bdty(NAME, NULL));
		}
#line 3897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1211 "./cgram.y" /* yacc.c:1646  */
    {
			(yyval.nodep) = biop(TYMERGE, (yyvsp[-1].nodep), aryfix((yyvsp[0].nodep)));
		}
#line 3905 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3909 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1216 "./cgram.y" /* yacc.c:1906  */


NODE *
mkty(TWORD t, union dimfun *d, struct attr *sue)
{
	return block(TYPE, NIL, NIL, t, d, sue);
}

NODE *
bdty(int op, ...)
{
	va_list ap;
	int val;
	register NODE *q;

	va_start(ap, op);
	q = biop(op, NIL, NIL);

	switch (op) {
	case UMUL:
	case UCALL:
		q->n_left = va_arg(ap, NODE *);
		q->n_rval = 0;
		break;

	case CALL:
		q->n_left = va_arg(ap, NODE *);
		q->n_right = va_arg(ap, NODE *);
		break;

	case LB:
		q->n_left = va_arg(ap, NODE *);
		if ((val = va_arg(ap, int)) <= 0) {
			uerror("array size must be positive");
			val = 1;
		}
		q->n_right = bcon(val);
		break;

	case GOTO: /* for named labels */
		q->n_label = SLBLNAME;
		/* FALLTHROUGH */
	case NAME:
		q->n_op = NAME;
		q->n_sp = va_arg(ap, struct symtab *); /* XXX survive tymerge */
		break;

	case STRING:
		q->n_type = PTR|CHAR;
		q->n_name = va_arg(ap, char *);
		q->n_lval = va_arg(ap, int);
		break;

	default:
		cerror("bad bdty");
	}
	va_end(ap);

	return q;
}

static void
flend(void)
{
	if (!isinlining && sspflag && blevel == 2)
		sspend();
#ifdef STABS
	if (gflag && blevel > 2)
		stabs_rbrac(blevel);
#endif
	--blevel;
	if( blevel == 1 )
		blevel = 0;
	symclear(blevel); /* Clean ut the symbol table */
	if (autooff > maxautooff)
		maxautooff = autooff;
	autooff = savctx->contlab;
	savctx = savctx->next;
}

static void
savebc(void)
{
	struct savbc *bc = tmpalloc(sizeof(struct savbc));

	bc->brklab = brklab;
	bc->contlab = contlab;
	bc->flostat = flostat;
	bc->next = savbc;
	savbc = bc;
	flostat = 0;
}

static void
resetbc(int mask)
{
	flostat = savbc->flostat | (flostat&mask);
	contlab = savbc->contlab;
	brklab = savbc->brklab;
	savbc = savbc->next;
}

struct swdef {
	struct swdef *next;	/* Next in list */
	int deflbl;		/* Label for "default" */
	struct swents *ents;	/* Linked sorted list of case entries */
	int nents;		/* # of entries in list */
	int num;		/* Node value will end up in */
	TWORD type;		/* Type of switch expression */
} *swpole;

/*
 * add case to switch
 */
static void
addcase(NODE *p)
{
	struct swents **put, *w, *sw = tmpalloc(sizeof(struct swents));
	CONSZ val;

	p = optloop(p);  /* change enum to ints */
	if (p->n_op != ICON || p->n_sp != NULL) {
		uerror( "non-constant case expression");
		return;
	}
	if (swpole == NULL) {
		uerror("case not in switch");
		return;
	}

	if (DEUNSIGN(swpole->type) != DEUNSIGN(p->n_type)) {
		val = p->n_lval;
		p = makety(p, swpole->type, 0, 0, 0);
		if (p->n_op != ICON)
			cerror("could not cast case value to type of switch "
			       "expression");
		if (p->n_lval != val)
			werror("case expression truncated");
	}
	sw->sval = p->n_lval;
	tfree(p);
	put = &swpole->ents;
	if (ISUNSIGNED(swpole->type)) {
		for (w = swpole->ents;
		     w != NULL && (U_CONSZ)w->sval < (U_CONSZ)sw->sval;
		     w = w->next)
			put = &w->next;
	} else {
		for (w = swpole->ents; w != NULL && w->sval < sw->sval;
		     w = w->next)
			put = &w->next;
	}
	if (w != NULL && w->sval == sw->sval) {
		uerror("duplicate case in switch");
		return;
	}
	plabel(sw->slab = getlab());
	*put = sw;
	sw->next = w;
	swpole->nents++;
}

#ifdef GCC_COMPAT
void
gcccase(NODE *ln, NODE *hn)
{
	CONSZ i, l, h;

	l = icons(optim(ln));
	h = icons(optim(hn));

	if (h < l)
		i = l, l = h, h = i;

	for (i = l; i <= h; i++)
		addcase(xbcon(i, NULL, hn->n_type));
}
#endif

/*
 * add default case to switch
 */
static void
adddef(void)
{
	if (swpole == NULL)
		uerror("default not inside switch");
	else if (swpole->deflbl != 0)
		uerror("duplicate default in switch");
	else
		plabel( swpole->deflbl = getlab());
}

static void
swstart(int num, TWORD type)
{
	struct swdef *sw = tmpalloc(sizeof(struct swdef));

	sw->deflbl = sw->nents = 0;
	sw->ents = NULL;
	sw->next = swpole;
	sw->num = num;
	sw->type = type;
	swpole = sw;
}

/*
 * end a switch block
 */
static void
swend(void)
{
	struct swents *sw, **swp;
	int i;

	sw = tmpalloc(sizeof(struct swents));
	swp = tmpalloc(sizeof(struct swents *) * (swpole->nents+1));

	sw->slab = swpole->deflbl;
	swp[0] = sw;

	for (i = 1; i <= swpole->nents; i++) {
		swp[i] = swpole->ents;
		swpole->ents = swpole->ents->next;
	}
	genswitch(swpole->num, swpole->type, swp, swpole->nents);

	swpole = swpole->next;
}

/*
 * num: tempnode the value of the switch expression is in
 * type: type of the switch expression
 *
 * p points to an array of structures, each consisting
 * of a constant value and a label.
 * The first is >=0 if there is a default label;
 * its value is the label number
 * The entries p[1] to p[n] are the nontrivial cases
 * n is the number of case statements (length of list)
 */
static void
genswitch(int num, TWORD type, struct swents **p, int n)
{
	NODE *r, *q;
	int i;

	if (mygenswitch(num, type, p, n))
		return;

	/* simple switch code */
	for (i = 1; i <= n; ++i) {
		/* already in 1 */
		r = tempnode(num, type, 0, 0);
		q = xbcon(p[i]->sval, NULL, type);
		r = buildtree(NE, r, clocal(q));
		xcbranch(r, p[i]->slab);
	}
	if (p[0]->slab > 0)
		branch(p[0]->slab);
}

/*
 * Declare a variable or prototype.
 */
static struct symtab *
init_declarator(NODE *tn, NODE *p, int assign, NODE *a, char *as)
{
	int class = tn->n_lval;
	struct symtab *sp;

	p = aryfix(p);
	p = tymerge(tn, p);
	if (a) {
		struct attr *ap = gcc_attr_wrapper(a);
		p->n_ap = attr_add(p->n_ap, ap);
	}

	p->n_sp = sp = lookup((char *)p->n_sp, 0); /* XXX */

	if (fun_inline && ISFTN(p->n_type))
		sp->sflags |= SINLINE;

	if (!ISFTN(p->n_type)) {
		if (assign) {
			defid2(p, class, as);
			sp = p->n_sp;
			sp->sflags |= SASG;
			if (sp->sflags & SDYNARRAY)
				uerror("can't initialize dynamic arrays");
			lcommdel(sp);
		} else
			nidcl2(p, class, as);
	} else {
		extern NODE *parlink;
		if (assign)
			uerror("cannot initialise function");
		defid2(p, uclass(class), as);
		sp = p->n_sp;
		if (sp->sdf->dfun == 0 && !issyshdr)
			warner(Wstrict_prototypes);
		if (parlink) {
			/* dynamic sized arrays in prototypes */
			tfree(parlink); /* Free delayed tree */
			parlink = NIL;
		}
	}
	tfree(p);
	if (issyshdr)
		sp->sflags |= SINSYS; /* declared in system header */
	return sp;
}

/*
 * Declare old-stype function arguments.
 */
static void
oldargs(NODE *p)
{
	blevel++;
	p->n_op = TYPE;
	p->n_type = FARG;
	p->n_sp = lookup((char *)p->n_sp, 0);/* XXX */
	defid(p, PARAM);
	blevel--;
}

/*
 * Set NAME nodes to a null name and index of LB nodes to NOOFFSET
 * unless clr is one, in that case preserve variable name.
 */
static NODE *
namekill(NODE *p, int clr)
{
	NODE *q;
	int o = p->n_op;

	switch (coptype(o)) {
	case LTYPE:
		if (o == NAME) {
			if (clr)
				p->n_sp = NULL;
			else
				p->n_sp = lookup((char *)p->n_sp, 0);/* XXX */
		}
		break;

	case UTYPE:
		p->n_left = namekill(p->n_left, clr);
		break;

        case BITYPE:
                p->n_left = namekill(p->n_left, clr);
		if (o == LB) {
			if (clr) {
				tfree(p->n_right);
				p->n_right = bcon(NOOFFSET);
			} else
				p->n_right = eve(p->n_right);
		} else if (o == CALL)
			p->n_right = namekill(p->n_right, 1);
		else
			p->n_right = namekill(p->n_right, clr);
		if (o == TYMERGE) {
			q = tymerge(p->n_left, p->n_right);
			q->n_ap = attr_add(q->n_ap, p->n_ap);
			tfree(p->n_left);
			nfree(p);
			p = q;
		}
		break;
	}
	return p;
}

/*
 * Declare function arguments.
 */
static NODE *
funargs(NODE *p)
{
	extern NODE *arrstk[10];

	if (p->n_op == ELLIPSIS)
		return p;

	p = namekill(p, 0);
	if (ISFTN(p->n_type))
		p->n_type = INCREF(p->n_type);
	if (ISARY(p->n_type)) {
		p->n_type += (PTR-ARY);
		if (p->n_df->ddim == -1)
			tfree(arrstk[0]), arrstk[0] = NIL;
		p->n_df++;
	}
	if (p->n_type == VOID && p->n_sp->sname == NULL)
		return p; /* sanitycheck later */
	else if (p->n_sp->sname == NULL)
		uerror("argument missing");
	else
		defid(p, PARAM);
	return p;
}

static NODE *
listfw(NODE *p, NODE * (*f)(NODE *))
{
        if (p->n_op == CM) {
                p->n_left = listfw(p->n_left, f);
                p->n_right = (*f)(p->n_right);
        } else
                p = (*f)(p);
	return p;
}


/*
 * Declare a function.
 */
static void
fundef(NODE *tp, NODE *p)
{
	extern int prolab;
	struct symtab *s;
	NODE *q, *typ;
	int class = tp->n_lval, oclass, ctval;
	char *c;

	/*
	 * We discard all names except for those needed for
	 * parameter declaration. While doing that, also change
	 * non-constant array sizes to unknown.
	 */
	ctval = tvaloff;
	for (q = p; coptype(q->n_op) != LTYPE &&
	    q->n_left->n_op != NAME; q = q->n_left) {
		if (q->n_op == CALL)
			q->n_right = namekill(q->n_right, 1);
	}
	if (q->n_op != CALL && q->n_op != UCALL) {
		uerror("invalid function definition");
		p = bdty(UCALL, p);
	} else if (q->n_op == CALL) {
		blevel = 1;
		argoff = ARGINIT;
		if (oldstyle == 0)
			q->n_right = listfw(q->n_right, funargs);
		ftnarg(q);
		blevel = 0;
	}

	p = typ = tymerge(tp, p);
#ifdef GCC_COMPAT
	/* gcc seems to discard __builtin_ when declaring functions */
	if (strncmp("__builtin_", (char *)typ->n_sp, 10) == 0)
		typ->n_sp = (struct symtab *)((char *)typ->n_sp + 10);
#endif
	s = typ->n_sp = lookup((char *)typ->n_sp, 0); /* XXX */

	oclass = s->sclass;
	if (class == STATIC && oclass == EXTERN)
		werror("%s was first declared extern, then static", s->sname);

	if (fun_inline) {
		/* special syntax for inline functions */
		if (! strcmp(s->sname,"main")) 
			uerror("cannot inline main()");

		s->sflags |= SINLINE;
		inline_start(s, class);
		if (class == EXTERN)
			class = EXTDEF;
	} else if (class == EXTERN)
		class = SNULL; /* same result */

	cftnsp = s;
	defid(p, class);
	if (s->sdf->dfun == 0 && !issyshdr)
		warner(Wstrict_prototypes);
#ifdef GCC_COMPAT
	if (attr_find(p->n_ap, GCC_ATYP_ALW_INL)) {
		/* Temporary turn on temps to make always_inline work */
		alwinl = 1;
		if (xtemps == 0) alwinl |= 2;
		xtemps = 1;
	}
#endif
	prolab = getlab();
	if ((c = cftnsp->soname) == NULL)
		c = addname(exname(cftnsp->sname));
	send_passt(IP_PROLOG, -1, c, cftnsp->stype,
	    cftnsp->sclass == EXTDEF, prolab, ctval);
	blevel++;
#ifdef STABS
	if (gflag)
		stabs_func(s);
#endif
	tfree(tp);
	tfree(p);

}

static void
fend(void)
{
	if (blevel)
		cerror("function level error");
	ftnend();
	fun_inline = 0;
	if (alwinl & 2) xtemps = 0;
	alwinl = 0;
	cftnsp = NULL;
}

NODE *
structref(NODE *p, int f, char *name)
{
	NODE *r;

	if (f == DOT)
		p = buildtree(ADDROF, p, NIL);
	r = biop(NAME, NIL, NIL);
	r->n_name = name;
	r = buildtree(STREF, p, r);
	return r;
}

static void
olddecl(NODE *p, NODE *a)
{
	struct symtab *s;

	p = namekill(p, 0);
	s = p->n_sp;
	if (s->slevel != 1 || s->stype == UNDEF)
		uerror("parameter '%s' not defined", s->sname);
	else if (s->stype != FARG)
		uerror("parameter '%s' redefined", s->sname);

	s->stype = p->n_type;
	s->sdf = p->n_df;
	s->sap = p->n_ap;
	if (ISARY(s->stype)) {
		s->stype += (PTR-ARY);
		s->sdf++;
	} else if (s->stype == FLOAT)
		s->stype = DOUBLE;
	if (a)
		attr_add(s->sap, gcc_attr_wrapper(a));
	nfree(p);
}

void
branch(int lbl)
{
	int r = reached++;
	ecomp(biop(GOTO, bcon(lbl), NIL));
	reached = r;
}

/*
 * Create a printable string based on an encoded string.
 */
static char *
mkpstr(char *str)
{
	char *os, *s;
	int l = strlen(str) + 3; /* \t + \n + \0 */

	os = s = inlalloc(l);
	*s++ = '\t';
	while (*str) {
		if (*str == '\\')
			*s++ = esccon(&str);
		else
			*s++ = *str++;
	}
	*s++ = '\n';
	*s = 0;

	return os;
}

/*
 * encode value as 3-digit octal escape sequence
 */
static char *
voct(char *d, unsigned int v)
{
	*d++ = '\\';
	*d++ = ((v & 0700) >> 6) + '0';
	*d++ = ((v & 0070) >> 3) + '0';
	*d++ = (v & 0007) + '0';
	return d;
}

/*
 * Add "raw" string new to cleaned string old.
 */
static char *
stradd(char *old, char *new)
{
	char *rv, *p;
	int oldlen, max;

	if (new[0] == 'L' && new[1] == '\"') {
		widestr = 1;
		new++;
	}

	if (new[0] == '\"') {
		new++;
		new[strlen(new) - 1] = 0;
	}

	/* estimate max space needed for new string */
	for (p = new, max = 0; *p; max++, p++)
		if (*p == '\\' || *p < ' ' || *p > '~')
			max += 3;

	/* start new buffer with old string */
	oldlen = strlen(old);
	rv = tmpalloc(oldlen + max + 1);
	memcpy(rv, old, oldlen);

	/* append new string, cleaning up as we go */
	p = rv + oldlen;
	while (*new) {
		if (*new == '\\') {
			p = voct(p, esccon(&new));
			max -= 4;
		} else if (*new < ' ' || *new > '~') {
			p = voct(p, *(unsigned char *)new++);
			max -= 4;
		} else {
			*p++ = *new++;
			max--;
		}
		if (max < 0)
			cerror("stradd");
	}

	/* nil terminate */
	*p = 0;

	return rv;
}

/*
 * Fake a symtab entry for compound literals.
 */
static struct symtab *
clbrace(NODE *p)
{
	struct symtab *sp;

	sp = getsymtab(simname("cl"), STEMP);
	sp->stype = p->n_type;
	sp->squal = p->n_qual;
	sp->sdf = p->n_df;
	sp->sap = p->n_ap;
	tfree(p);
	if (blevel == 0 && xnf != NULL) {
		sp->sclass = STATIC;
		sp->slevel = 2;
		sp->soffset = getlab();
	} else {
		sp->sclass = blevel ? AUTO : STATIC;
		if (!ISARY(sp->stype) || sp->sdf->ddim != NOOFFSET) {
			sp->soffset = NOOFFSET;
			oalloc(sp, &autooff);
		}
	}
	beginit(sp);
	return sp;
}

char *
simname(char *s)
{
	int len = strlen(s) + 10 + 1;
	char *w = tmpalloc(len);

	snprintf(w, len, "%s%d", s, getlab());
	return w;
}

NODE *
biop(int op, NODE *l, NODE *r)
{
	return block(op, l, r, INT, 0, 0);
}

static NODE *
cmop(NODE *l, NODE *r)
{
	return biop(CM, l, r);
}

static NODE *
voidcon(void)
{
	return block(ICON, NIL, NIL, STRTY, 0, 0);
}

/* Support for extended assembler a' la' gcc style follows below */

static NODE *
xmrg(NODE *out, NODE *in)
{
	NODE *p = in;

	if (p->n_op == XARG) {
		in = cmop(out, p);
	} else {
		while (p->n_left->n_op == CM)
			p = p->n_left;
		p->n_left = cmop(out, p->n_left);
	}
	return in;
}

/*
 * Put together in and out node lists in one list, and balance it with
 * the constraints on the right side of a CM node.
 */
static NODE *
xcmop(NODE *out, NODE *in, NODE *str)
{
	NODE *p, *q;

	if (out) {
		/* D out-list sanity check */
		for (p = out; p->n_op == CM; p = p->n_left) {
			q = p->n_right;
			if (q->n_name[0] != '=' && q->n_name[0] != '+')
				uerror("output missing =");
		}
		if (p->n_name[0] != '=' && p->n_name[0] != '+')
			uerror("output missing =");
		if (in == NIL)
			p = out;
		else
			p = xmrg(out, in);
	} else if (in) {
		p = in;
	} else
		p = voidcon();

	if (str == NIL)
		str = voidcon();
	return cmop(p, str);
}

/*
 * Generate a XARG node based on a string and an expression.
 */
static NODE *
xasmop(char *str, NODE *p)
{

	p = biop(XARG, p, NIL);
	p->n_name = isinlining ? newstring(str, strlen(str)) : str;
	return p;
}

/*
 * Generate a XASM node based on a string and an expression.
 */
static void
mkxasm(char *str, NODE *p)
{
	NODE *q;

	q = biop(XASM, p->n_left, p->n_right);
	q->n_name = isinlining ? newstring(str, strlen(str)) : str;
	nfree(p);
	ecomp(optloop(q));
}

static struct attr *
gcc_attr_wrapper(NODE *p)
{
#ifdef GCC_COMPAT
	return gcc_attr_parse(p);
#else
	if (p != NIL)
		uerror("gcc attribute used");
	return NIL;
#endif
}

#ifdef GCC_COMPAT
static NODE *
tyof(NODE *p)
{
	static struct symtab spp;
	NODE *q = block(TYPE, NIL, NIL, p->n_type, p->n_df, p->n_ap);
	q->n_qual = p->n_qual;
	q->n_sp = &spp; /* for typenode */
	tfree(p);
	return q;
}

#else
static NODE *
tyof(NODE *p)
{
	uerror("typeof gcc extension");
	return bcon(0);
}
#endif

/*
 * Traverse an unhandled expression tree bottom-up and call buildtree()
 * or equivalent as needed.
 */
NODE *
eve(NODE *p)
{
	struct symtab *sp;
	NODE *r, *p1, *p2;
	int x;

	p1 = p->n_left;
	p2 = p->n_right;
	switch (p->n_op) {
	case NAME:
		sp = lookup((char *)p->n_sp, p->n_label);
		if (sp->sflags & SINLINE)
			inline_ref(sp);
		r = nametree(sp);
		if (sp->sflags & SDYNARRAY)
			r = buildtree(UMUL, r, NIL);
#ifdef GCC_COMPAT
		if (attr_find(sp->sap, GCC_ATYP_DEPRECATED))
			warner(Wdeprecated_declarations, sp->sname);
#endif
		break;

	case DOT:
	case STREF:
		r = structref(eve(p1), p->n_op, (char *)p2->n_sp);
		nfree(p2);
		break;

	case CAST:
		p2 = eve(p2);
#ifndef NO_COMPLEX
		if (ANYCX(p1) || ANYCX(p2)) {
			r = cxcast(p1, p2);
			break;
		}
#endif
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_ticast(CAST, p1, p2)) != NULL)
			break;
#endif
		p1 = buildtree(CAST, p1, p2);
		nfree(p1->n_left);
		r = p1->n_right;
		nfree(p1);
		break;


	case SZOF:
		x = xinline; xinline = 0; /* XXX hack */
		if (p2->n_lval == 0)
			p1 = eve(p1);
		else
			TYMFIX(p1);
		nfree(p2);
		r = doszof(p1);
		xinline = x;
		break;

	case LB:
		p1 = eve(p1);
		p2 = eve(p2);
#ifdef TARGET_TIMODE
		if (isti(p2)) {
			NODE *s = block(NAME, NIL, NIL, LONG, 0, 0);
			if ((r = gcc_eval_ticast(CAST, s, p2)) != NULL)
				p2 = r;
			nfree(s);
		}
#endif
		r = buildtree(UMUL, buildtree(PLUS, p1, p2), NIL);
		break;

	case COMPL:
#ifndef NO_COMPLEX
		p1 = eve(p1);
		if (ANYCX(p1))
			r = cxconj(p1);
		else
			r = buildtree(COMPL, p1, NIL);
		break;
#endif
	case UPLUS:
		r = eve(p1);
		if (r->n_op == FLD || r->n_type < INT)
			r = buildtree(PLUS, r, bcon(0)); /* must be size int */
		break;

	case UMINUS:
#ifndef NO_COMPLEX
		p1 = eve(p1);
		if (ANYCX(p1))
			r = cxop(UMINUS, p1, p1);
		else
			r = buildtree(UMINUS, p1, NIL);
		break;
#endif
	case NOT:
	case UMUL:
		p1 = eve(p1);
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_tiuni(p->n_op, p1)) != NULL)
			break;
#endif
#ifndef NO_COMPLEX
		if (p->n_op == NOT && ANYCX(p1))
			p1 = cxop(NE, p1, bcon(0));
#endif
		r = buildtree(p->n_op, p1, NIL);
		break;

	case ADDROF:
		r = eve(p1);
		if (ISFTN(p->n_type)/* || ISARY(p->n_type) */){
#ifdef notdef
			werror( "& before array or function: ignored" );
#endif
		} else
			r = buildtree(ADDROF, r, NIL);
		break;

	case UCALL:
		p2 = NIL;
		/* FALLTHROUGH */
	case CALL:
		if (p1->n_op == NAME) {
			sp = lookup((char *)p1->n_sp, 0);
#ifndef NO_C_BUILTINS
			if (sp->sflags & SBUILTIN) {
				nfree(p1);
				r = builtin_check(sp, p2);
				break;
			}
#endif
			if (sp->stype == UNDEF) {
				p1->n_type = FTN|INT;
				p1->n_sp = sp;
				p1->n_ap = NULL;
				defid(p1, EXTERN);
			}
			nfree(p1);
#ifdef GCC_COMPAT
			if (attr_find(sp->sap, GCC_ATYP_DEPRECATED))
				warner(Wdeprecated_declarations, sp->sname);
#endif
			if (p->n_op == CALL)
				p2 = eve(p2);
			r = doacall(sp, nametree(sp), p2);
		} else {
			if (p->n_op == CALL)
				p2 = eve(p2);
			r = doacall(NULL, eve(p1), p2);
		}
		break;

#ifndef NO_COMPLEX
	case XREAL:
	case XIMAG:
		p1 = eve(p1);
		r = cxelem(p->n_op, p1);
		break;
#endif

	case COLON:
	case MUL:
	case DIV:
	case PLUS:
	case MINUS:
	case ASSIGN:
	case EQ:
	case NE:
	case OROR:
	case ANDAND:
#ifndef NO_COMPLEX
		p1 = eve(p1);
		p2 = eve(p2);
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_timode(p->n_op, p1, p2)) != NULL)
			break;
#endif
		if (ANYCX(p1) || ANYCX(p2)) {
			r = cxop(p->n_op, p1, p2);
		} else if (ISITY(p1->n_type) || ISITY(p2->n_type)) {
			r = imop(p->n_op, p1, p2);
		} else
			r = buildtree(p->n_op, p1, p2);
		break;
#endif
	case MOD:
	case CM:
	case GT:
	case GE:
	case LT:
	case LE:
	case RS:
	case LS:
	case RSEQ:
	case LSEQ:
	case AND:
	case OR:
	case ER:
	case EREQ:
	case OREQ:
	case ANDEQ:
	case QUEST:
		p1 = eve(p1);
		p2 = eve(p2);
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_timode(p->n_op, p1, p2)) != NULL)
			break;
#endif
		r = buildtree(p->n_op, p1, p2);
		break;

	case BIQUEST: /* gcc e ?: e op */
		p1 = eve(p1);
		r = tempnode(0, p1->n_type, p1->n_df, p1->n_ap);
		p2 = eve(biop(COLON, ccopy(r), p2));
		r = buildtree(QUEST, buildtree(ASSIGN, r, p1), p2);
		break;

	case INCR:
	case DECR:
	case MODEQ:
	case MINUSEQ:
	case PLUSEQ:
	case MULEQ:
	case DIVEQ:
		p1 = eve(p1);
		p2 = eve(p2);
#ifdef TARGET_TIMODE
		if ((r = gcc_eval_timode(p->n_op, p1, p2)) != NULL)
			break;
#endif
#ifndef NO_COMPLEX
		if (ANYCX(p1) || ANYCX(p2)) {
			r = cxop(UNASG p->n_op, ccopy(p1), p2);
			r = cxop(ASSIGN, p1, r);
			break;
		} else if (ISITY(p1->n_type) || ISITY(p2->n_type)) {
			r = imop(UNASG p->n_op, ccopy(p1), p2);
			r = cxop(ASSIGN, p1, r);
			break;
		}
		/* FALLTHROUGH */
#endif
		r = buildtree(p->n_op, p1, p2);
		break;

	case STRING:
		r = strend(p->n_lval, p->n_name);
		break;

	case COMOP:
		if (p1->n_op == GOTO) {
			/* inside ({ }), eve already called */
			r = buildtree(p->n_op, p1, p2);
		} else {
			p1 = eve(p1);
			r = buildtree(p->n_op, p1, eve(p2));
		}
		break;

	case TYPE:
	case ICON:
	case FCON:
	case TEMP:
		return p;

	case CLOP:
		r = nametree(p->n_sp);
		break;

	default:
#ifdef PCC_DEBUG
		fwalk(p, eprint, 0);
#endif
		cerror("eve");
		r = NIL;
	}
	nfree(p);
	return r;
}

int
con_e(NODE *p)
{
	return icons(optloop(eve(p)));
}

void
uawarn(NODE *p, char *s)
{
	if (p == 0)
		return;
	if (attrwarn)
		werror("unhandled %s attribute", s);
	tfree(p);
}

static void
dainit(NODE *d, NODE *a)
{
	if (d == NULL) {
		asginit(a);
	} else if (d->n_op == CM) {
		int is = con_e(d->n_left);
		int ie = con_e(d->n_right);
		int i;

		nfree(d);
		if (ie < is)
			uerror("negative initializer range");
		desinit(biop(LB, NIL, bcon(is)));
		for (i = is; i < ie; i++)
			asginit(ccopy(a));
		asginit(a);
	} else {
		cerror("dainit");
	}
}

/*
 * Traverse down and tymerge() where appropriate.
 */
static NODE *
tymfix(NODE *p)
{
	NODE *q;
	int o = coptype(p->n_op);

	switch (o) {
	case LTYPE:
		break;
	case UTYPE:
		p->n_left = tymfix(p->n_left);
		break;
	case BITYPE:
		p->n_left = tymfix(p->n_left);
		p->n_right = tymfix(p->n_right);
		if (p->n_op == TYMERGE) {
			q = tymerge(p->n_left, p->n_right);
			q->n_ap = attr_add(q->n_ap, p->n_ap);
			tfree(p->n_left);
			nfree(p);
			p = q;
		}
		break;
	}
	return p;
}

static NODE *
aryfix(NODE *p)
{
	NODE *q;

	for (q = p; q->n_op != NAME; q = q->n_left) {
		if (q->n_op == LB) {
			q->n_right = optloop(eve(q->n_right));
			if ((blevel == 0 || rpole != NULL) &&
			    !nncon(q->n_right))
				uerror("array size not constant"); 
			/*
			 * Checks according to 6.7.5.2 clause 1:
			 * "...the expression shall have an integer type."
			 * "If the expression is a constant expression,	 
			 * it shall have a value greater than zero."
			 */
			if (!ISINTEGER(q->n_right->n_type))
				werror("array size is not an integer");
			else if (q->n_right->n_op == ICON &&
			    q->n_right->n_lval < 0 &&
			    q->n_right->n_lval != NOOFFSET) {
					uerror("array size cannot be negative");
					q->n_right->n_lval = 1;
			}
		} else if (q->n_op == CALL)
			q->n_right = namekill(q->n_right, 1);
	}
	return p;
}

struct labs {
	struct labs *next;
	int lab;
} *labp;

static void
savlab(int lab)
{
	struct labs *l = tmpalloc(sizeof(struct labs));
	l->lab = lab < 0 ? -lab : lab;
	l->next = labp;
	labp = l;
}

int *
mkclabs(void)
{
	struct labs *l;
	int i, *rv;

	for (i = 0, l = labp; l; l = l->next, i++)
		;
	rv = inlalloc((i+1)*sizeof(int));
	for (i = 0, l = labp; l; l = l->next, i++)
		rv[i] = l->lab;
	rv[i] = 0;
	labp = 0;
	return rv;
}

void
xcbranch(NODE *p, int lab)
{
#ifndef NO_COMPLEX
	if (ANYCX(p))
		p = cxop(NE, p, bcon(0));
#endif
	cbranch(buildtree(NOT, p, NIL), bcon(lab));
}
