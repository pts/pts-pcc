/* pts@fazekas.hu at Wed May 15 02:20:34 CEST 2024 */

#ifndef __WATCOMC__
#  error This adapter needs the Watcom C compiler.
#endif

#ifndef __386__
#  error This adapter works only on i386 CPU.
#endif

#ifndef __MINILIBC686__
#  error This adapter works with minilibc686.
#endif

#pragma aux __watcall "*_"
#pragma aux __cdecl "*"

#define NULL ((void*)0)
typedef int time_t;
typedef unsigned size_t;
typedef struct _FILE *FILE;

/* Overrides lib386/nt/clib3r.lib / mbcupper.o
 * Source: https://github.com/open-watcom/open-watcom-v2/blob/master/bld/clib/mbyte/c/mbcupper.c
 * Overridden implementation calls CharUpperA in USER32.DLL:
 * https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-charuppera
 *
 * This function is a transitive dependency of _cstart() with main() in
 * OpenWatcom. By overridding it, we remove the transitive dependency of all
 * .exe files compiled with `owcc -bwin32' on USER32.DLL.
 *
 * This is a simplified implementation, it keeps non-ASCII characters intact.
 */
unsigned int __watcall _mbctoupper(unsigned int c) {
  return (c - 'a' + 0U <= 'z' - 'a' + 0U)  ? c + 'A' - 'a' : c;
}

extern int __cdecl tcc_main(int argc, char **argv);
#pragma aux tcc_main "main"

extern FILE* __watcall __get_std_file(unsigned handle);

FILE *mini_stdin, *mini_stdout, *mini_stderr;
#pragma aux mini_stdin "mini_stdin"
#pragma aux mini_stdout "mini_stdout"
#pragma aux mini_stderr "mini_stderr"

int mini_errno;  /* Set and ingnored. */
#pragma aux mini_errno "mini_errno"

int __watcall main(int argc, char **argv) {
  mini_stdin = __get_std_file(0);
  mini_stdout = __get_std_file(1);
  mini_stderr = __get_std_file(2);
  return tcc_main(argc, argv);
}
#pragma aux main "main_"

/* Win32 API. */
#define CONST const
#define FALSE 0
#define TRUE 1
typedef unsigned long DWORD;
typedef DWORD *LPDWORD;
typedef char CHAR;
typedef CHAR *LPSTR, *PSTR;
typedef CONST CHAR *LPCSTR, *PCSTR;
typedef unsigned char BYTE;
typedef BYTE *LPBYTE;
typedef int BOOL;
typedef unsigned short WORD;
#define VOID void
typedef VOID *PVOID, *LPVOID;
typedef PVOID HANDLE;
typedef HANDLE HINSTANCE;
typedef HINSTANCE HMODULE;
typedef struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;
typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;
typedef void *LPSECURITY_ATTRIBUTES;
#define INVALID_FILE_ATTRIBUTES 0xFFFFFFFFL
#define FILE_ATTRIBUTE_DIRECTORY 0x00000010L
/* __declspec(dllimport) produces the wrong call without `owcc -bwin32'. */
extern /*__declspec(dllimport)*/ DWORD __stdcall GetFileAttributesA(LPCSTR lpFileName);
extern /*__declspec(dllimport)*/ DWORD __stdcall GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
#define HIGH_PRIORITY_CLASS 0x00000080
extern /*__declspec(dllimport)*/ BOOL __stdcall CreateProcessA(LPCSTR lpApplicationName, LPSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory, LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
#define INFINITE 0xFFFFFFFF
extern /*__declspec(dllimport)*/ DWORD __stdcall WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
extern /*__declspec(dllimport)*/ BOOL __stdcall GetExitCodeProcess(HANDLE hProcess, LPDWORD lpExitCode);
extern /*__declspec(dllimport)*/ BOOL __stdcall CloseHandle(HANDLE hObject);

char __cdecl is_directory(const char *pathname) {
  const unsigned attrs = GetFileAttributesA(pathname);
  return attrs != INVALID_FILE_ATTRIBUTES && (attrs & FILE_ATTRIBUTE_DIRECTORY) != 0;
}

struct string { struct string *next; char *value; };
struct strlist { struct string *first, *last; };
#define	STRLIST_FIRST(head)	((head)->first)
#define	STRLIST_NEXT(elem)	((elem)->next)
#define	STRLIST_FOREACH(var, head) for ((var) = STRLIST_FIRST(head); (var) != NULL; (var) = STRLIST_NEXT(var))

extern int __watcall dprintf(const char *format, ...);
#pragma aux dprintf "printf_"
extern void * __watcall dmalloc(size_t size);
#pragma aux dmalloc "malloc_"
extern void __watcall dfree(void *ptr);
#pragma aux dfree "free_"
void * __cdecl dmemset(void *s, int c, size_t n);
#pragma aux dmemset "mini_memset"

/* Returns the number of bytes needed by append_arg_quoted(arg).
 * Based on https://learn.microsoft.com/en-us/archive/blogs/twistylittlepassagesallalike/everyone-quotes-command-line-arguments-the-wrong-way
 */
static size_t get_arg_quoted_size(const char *arg) {
  const char *p;
  size_t size = 1;  /* It starts with space even if it's the first argument. */
  size_t bsc;  /* Backslash count. */
  for (p = arg; *p != '\0' && *p != ' ' && *p != '\t' && *p != '\n' && *p != '\v' && *p != '"'; ++p) {}
  if (p != arg && *p == '\0') return size + (p - arg);  /* No need to quote. */
  size += 2;  /* Two '"' quotes, one on each side. */
  for (p = arg; ; ++p) {
    for (bsc = 0; *p == '\\'; ++p, ++bsc) {}
    if (*p == '\0') {
      size += bsc << 1;
      break;
    }
    if (*p == '"') bsc = (bsc << 1) + 1;
    size += bsc + 1;
  }
  return size;
}

/* Appends the quoted (escaped) arg to pout, always starting with a space, and returns the new pout.
 * Implements the inverse of parts of CommandLineToArgvW(...).
 * Implementation corresponds to get_arg_quoted_size(arg).
 * Based on https://learn.microsoft.com/en-us/archive/blogs/twistylittlepassagesallalike/everyone-quotes-command-line-arguments-the-wrong-way
 */
static char *append_arg_quoted(const char *arg, char *pout) {
  const char *p;
  size_t bsc;  /* Backslash count. */
  *pout++ = ' ';  /* It starts with space even if it's the first argument. */
  for (p = arg; *p != '\0' && *p != ' ' && *p != '\t' && *p != '\n' && *p != '\v' && *p != '"'; ++p) {}
  if (p != arg && *p == '\0') {  /* No need to quote. */
    for (p = arg; *p != '\0'; *pout++ = *p++) {}
    return pout;
  }
  *pout++ = '"';
  for (p = arg; ; *pout++ = *p++) {
    for (bsc = 0; *p == '\\'; ++p, ++bsc) {}
    if (*p == '\0') {
      for (bsc <<= 1; bsc != 0; --bsc, *pout++ = '\\') {}
      break;
    }
    if (*p == '"') bsc = (bsc << 1) + 1;
    for (; bsc != 0; --bsc, *pout++ = '\\') {}
  }
  *pout++ = '"';
  return pout;
}

static char *concatenate_strlist_args(const char *arg0, const char *arg1, const struct strlist *l) {
  const struct string *s;
  char *result, *pout;
  size_t size = get_arg_quoted_size(arg0) + get_arg_quoted_size(arg1) + 1;  /* Trailing '\0'. */
  STRLIST_FOREACH(s, l) { size += get_arg_quoted_size(s->value); }
  ++size;
  result = dmalloc(size);
  if (result) {
    pout = append_arg_quoted(arg1, append_arg_quoted(arg0, result));
    STRLIST_FOREACH(s, l) { pout = append_arg_quoted(s->value, pout); }
    *pout = '\0';
  }
  return result;
}

int __cdecl strlist_exec_low(const struct strlist *l) {
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	DWORD exit_code;
	BOOL ok;
	char *arg0, *cmd;
	unsigned size = GetModuleFileNameA(NULL, 0, 0);
	if (size == 0) size = 260;
	arg0 = dmalloc(size);
	GetModuleFileNameA(NULL, arg0, size);
	cmd = concatenate_strlist_args(arg0, "--exec", l);
	dfree(arg0);
	/*dprintf("!! strlist_exec_low (%s)\n", cmd);*/
	dmemset(&si, 0, sizeof(STARTUPINFOA));
	si.cb = sizeof(STARTUPINFOA);
	dmemset(&pi, 0, sizeof(PROCESS_INFORMATION));
	ok = CreateProcessA(NULL,  // the executable program
		cmd + 1,   // the command line arguments, skip leading space
		NULL,       // ignored
		NULL,       // ignored
		TRUE,       // inherit handles
		HIGH_PRIORITY_CLASS,
		NULL,       // ignored
		NULL,       // ignored
		&si,
		&pi);
	dfree(cmd);
	if (!ok) return -1;
	WaitForSingleObject(pi.hProcess, INFINITE);
	GetExitCodeProcess(pi.hProcess, &exit_code);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return exit_code;
}

#if 0  /* Unused. */
char * __cdecl mini_getcwd(char *buf, size_t size) {  /* Fake. */
  (void)size;
  buf[0] = '.';
  buf[1] = '\0';
  return buf;
}
#endif

/* Watcom libc constants. */
#ifdef LINUX
#  define W_O_CREAT  00100
#  define W_O_TRUNC  01000
#  define W_O_EXCL   00200
#  define W_O_BINARY 0
#else
#  define W_O_CREAT  0x0020
#  define W_O_TRUNC  0x0040
#  define W_O_EXCL   0x0400
#  define W_O_BINARY 0x0200
#endif

/* Linux constants. */
#define O_CREAT 00100
#define O_TRUNC 01000
#define O_EXCL  00200

extern int __watcall open(const char *__path, int __oflag, ...);
int __cdecl mini_open(const char *path, int flags, unsigned mode) {
  int flags2 = (flags & 3) | W_O_BINARY;
  if (flags & O_CREAT) flags2 |= W_O_CREAT;
  if (flags & O_TRUNC) flags2 |= W_O_TRUNC;
  /*if (flags & O_EXCL) flags2 |= W_O_EXCL;*/  /* Unused. */
  return open(path, flags2, mode);
}

#if 0  /* Unused. */
struct timeb {
  time_t         time;      /* seconds since Jan 1, 1970 UTC */
  unsigned short millitm;   /* milliseconds */
  short          timezone;  /* difference in minutes from UTC */
  short          dstflag;   /* nonzero if daylight savings time */
};
struct timeval {
  long tv_sec;     /* seconds */
  long tv_usec;    /* microseconds */
};
extern int __watcall ftime(struct timeb *timeptr);
int __cdecl mini_gettimeofday(struct timeval *tv, struct timezone *tz) {
  struct timeb tb;
  (void)tz;  /* Simplified, we don't set it. */
  if (ftime(&tb) != 0) return -1;
  tv->tv_sec = tb.time;
  tv->tv_usec = tb.millitm * 1000;
  return 0;
}
#endif

/* Forwards __cdecl to __cdecl. __watcall with variable number of arguments is actually __cdecl. */
#define FWD(func) extern void __watcall func(void); __declspec(naked) void __cdecl mini_ ## func(void) { __asm { jmp func } }
FWD(printf)
FWD(fprintf)
FWD(snprintf)
/*FWD(sprintf)*/  /* Unused. */

/* Forwards __cdecl function call to __watcall implementation of up to 4 arguments. */
static __declspec(naked) void fwd4(void) { __asm {
		push ebx  /* Save. */
		mov eax, [esp+3*4]
		mov edx, [esp+4*4]
		mov ebx, [esp+5*4]
		mov ecx, [esp+6*4]
		call dword ptr [esp+1*4]
		pop ebx  /* Restore. */
		pop ecx  /* Pop the called function. It's OK to spoil ECX for the __cdecl calling convention. */
		ret
} }
#define FWD4(func) extern void __watcall func(void); __declspec(naked) void __cdecl mini_ ## func(void) { __asm { push offset func } __asm { jmp fwd4 } }
FWD4(calloc)
FWD4(close)
FWD4(exit)
FWD4(fclose)
FWD4(fgetc)
FWD4(fopen)
FWD4(fputc)
FWD4(fputs)
FWD4(fread)
FWD4(free)
FWD4(freopen)
FWD4(fwrite)
FWD4(isatty)
FWD4(malloc)
FWD4(mkstemp)
FWD4(putchar)
FWD4(read)
FWD4(realloc)
FWD4(time)
FWD4(unlink)
FWD4(vfprintf)
FWD4(vprintf)
FWD4(vsnprintf)
FWD4(write)
FWD4(ctime)  /* struct tm for ctime(3) matches. */
FWD4(localtime)  /* struct tm for localtime(3) matches. */
