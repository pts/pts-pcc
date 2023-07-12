/*
 * ld96.c: 96-bit long double emulation, useful for OpenWatcom
 * by pts@fazekas.hu at Thu Jul  6 16:46:03 CEST 2023
 *
 * !! TODO(pts): The test fails with `return 24` (also 40 and 41) with --pcc CONFIG_LD96_S.
 * TODO(pts): Make sure the compiler (with CONFIG_LD96) doesn't even use `float' or `double' in any other file.
 * TODO(pts): As an architecture-independent alternative, add Berkeley SoftFloat (http://www.jhauser.us/arithmetic/SoftFloat.html) extFloat80_t .
 */

#ifdef CONFIG_LD96
#if !(defined(__i386__) || defined(__i386) || defined(__386__) || defined(__386) || defined(__x86_64__) || defined(__amd64__) || defined(_M_I386) || defined(_M_IX86) || defined(_M_X64) || defined(_M_AMD64) || defined(__x86_64__) || defined(__amd64__) || defined(_M_X64) || defined(__X86_64__) || defined(_M_I86) || defined(_M_X64) || defined(__X86__) || defined(__I86__) || defined(_M_I86) || defined(_M_I8086) || defined(_M_I286))
  /* This also ensures that the host is little-endian. */
#  error ld96 is implemented only for x86.  /* Not even __ia64__ has the 80-bit extended f80 type. */
#endif
#  ifdef __WATCOMC__
_Packed  /* This is needed in case `wcc386 -zp4' wasn't specified. The default is `-zp8'. */
#  endif
/*#pragma pack(__push, 4) */
  typedef union ld96u {
    struct { unsigned a, b, c; } s;
#  if !defined(__WATCOMC__) && !defined(CONFIG_LD96_S)
    long double ld;
#  endif
  } ld96u_t;
/*#pragma pack(__pop)*/
  typedef char assert_unsigned_size[sizeof(unsigned) == 4 ? 1 : -1];
  typedef char assert_unsigned_long_long_size[sizeof(unsigned long long) == 8 ? 1 : -1];
  typedef char assert_ld96_size[sizeof(ld96u_t) == 12 || sizeof(ld96u_t) == 16 ? 1 : -1];

#  ifndef __WATCOMC__  /* __GNUC__ or __TINYC__. */
#    ifdef CONFIG_LD96_S
#      if defined(__STRICT_ANSI__) || defined(_NO_EXT_KEYS)
        char ld96_dummy;  /* Pacify OpenWatcom `wcc386 -za': Error! E1123: File must contain at least one external definition. */
#      endif
#      ifndef __i386__
#        error GCC assembly implementation of ld96 supports 32-bit i386 only (not even amd64).  /* TODO(pts): Add amd64. */
#      endif
      /* The assembly rountines below assume size 12, they don't work with size 10 or 16. */
      typedef char assert_ld96_specific_size[sizeof(ld96u_t) == 12 ? 1 : -1];
#    if defined __i686__ || defined __pentium__ || defined __pentiumpro__ || defined __pentium4__ || defined __k8__ || defined __athlon__ || defined __k6__ || defined __nocona__ || defined __core2__ || defined __geode__ || defined __amdfam10__
      /* i686 (P6) or later. The other implementation ruins AX as a side effect. */
#      define FUCOMIP_01_R_AX "fucomip %st(1), %st"
#    else  /* i386 or later. It ruins AX as a side effect. */
#      define FUCOMIP_01_R_AX "fucomp %st(1); fnstsw %ax; sahf"
#    endif
#    undef E
#    ifdef __TINYC__
#      define E "L"  /* The inline assembler of TCC 0.9.26 doesn't support labels starting with `.'. TODO(pts): Fix pts-tcc, add support. */
#    else
#      define E ".L"  /* GNU as(1) supports labels starting with `.', and it won't put them to the .o file. */
#    endif
      ld96u_t ld96_from_ull(unsigned long long u);  /* { ld96u_t r; r.ld = u; return r; } */
      __asm__(".global ld96_from_ull; ld96_from_ull: ;\
		fildll 8(%esp);\
		cmpb $0x0, 0xf(%esp);\
		jns "E"35;\
		push $0x5f800000; "  /* (f32) of 1 << 64. */"\
		fadds (%esp);\
		pop %edx; "  /* EDX := junk. */"\
        "E"35:	mov 4(%esp), %eax;\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      ld96u_t ld96_from_ll(long long v);  /* { ld96u_t r; r.ld = v; return r; } */
      __asm__(".global ld96_from_ll;; ld96_from_ll: ;\
		fildll 8(%esp);\
		mov 4(%esp), %eax;\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      long long ld96_to_ll(ld96u_t ld);  /* { return ld.ld; } */
      __asm__(".global ld96_to_ll;; ld96_to_ll: ;\
		lea 4(%esp), %edx;\
		fldt (%edx);\
		fnstcw 8(%edx); "  /* Will be modified. */"\
		fnstcw 0xa(%edx); "  /* Save. */"\
		movb $0xc, 9(%edx); "  /* A more specific valu, 0xc7f, is not needed. Any 0xc.. seems to work. */"\
		fldcw 8(%edx); "  /* Load and use modified. */"\
		fistpll (%edx);\
		fldcw 0xa(%edx); "  /* Load and use saved. */"\
		mov (%edx), %eax;\
		mov 4(%edx), %edx;\
		ret;\
      ");
      unsigned long long ld96_to_ull(ld96u_t ld);  /* { return ld.ld > 0 ? (unsigned long long)ld.ld : 0ULL; } */
      __asm__(".global ld96_to_ull;; ld96_to_ull: ;\
		lea 4(%esp), %edx;\
		fldt (%edx);\
		fnstcw 8(%edx);\
		fnstcw 0xa(%edx); "  /* Save. */"\
		movb $0xf, 9(%edx);\
		fldcw 8(%edx);\
		movl $0x5f000000, (%edx);\
		fsubs (%edx);\
		fistpll (%edx);\
		xorb $0x80, 0x7(%edx); "  /* Flip sign. */"\
		fldcw 0xa(%edx); "  /* Load and use saved. */"\
		mov (%edx), %eax;\
		mov 4(%edx), %edx;\
		ret;\
      ");
#      if 0
        ld96u_t ld96_from_f32(float f);  /* { ld96u_t r; r.ld = f; return r; } */
        __asm__(".global ld96_from_f32;; ld96_from_f32: ;\
		mov 4(%esp), %eax;\
		flds 8(%esp);\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
        ");
        ld96u_t ld96_from_f64(double d);  /* { ld96u_t r; r.ld = d; return r; } */
        __asm__(".global ld96_from_f64;; ld96_from_f64: ;\
		mov 4(%esp), %eax;\
		fldl 8(%esp);\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
        ");
        float   ld96_to_f32(ld96u_t ld);  /* { return ld.ld; } */
        __asm__(".global ld96_to_f32;; ld96_to_f32: ;\
		lea 4(%esp), %edx;\
		fldt (%edx);\
		fstps (%edx);\
		flds (%edx);\
		ret;\
        ");
        double  ld96_to_f64(ld96u_t ld);  /* { return ld.ld; } */
        __asm__(".global ld96_to_f64;; ld96_to_f64: ;\
		lea 4(%esp), %edx;\
		fldt (%edx);\
		fstpl (%edx);\
		fldl (%edx);\
		ret;\
        ");
#      endif
      ld96u_t ld96_round_f32(ld96u_t ld);  /* d96u_t r; r.ld = (float) ld.ld; return r; */
      __asm__(".global ld96_round_f32;; ld96_round_f32: ;\
		lea 8(%esp), %eax;\
		fldt (%eax);\
		mov 4(%esp), %eax;\
		fstps (%eax);\
		flds (%eax);\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      ld96u_t ld96_round_f64(ld96u_t ld);  /* ld96u_t r; r.ld = (double)ld.ld; return r; */
      __asm__(".global ld96_round_f64;; ld96_round_f64: ;\
		lea 8(%esp), %eax;\
		fldt (%eax);\
		mov 4(%esp), %eax;\
		fstpl (%eax);\
		fldl (%eax);\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      void    ld96_dump_f32(char buf[4], ld96u_t ld);
      __asm__(".global ld96_dump_f32;; ld96_dump_f32: ;\
		lea 8(%esp), %edx;\
		fldt (%edx);\
		mov 4(%esp), %edx;\
		fstps (%edx);\
		ret;\
      ");
      void    ld96_dump_f64(char buf[8], ld96u_t ld);
      __asm__(".global ld96_dump_f64;; ld96_dump_f64: ;\
		lea 8(%esp), %edx;\
		fldt (%edx);\
		mov 4(%esp), %edx;\
		fstpl (%edx);\
		ret;\
      ");
      void    ld96_dump_f80_96(char buf[12], ld96u_t ld);
      __asm__(".global ld96_dump_f80_96;; ld96_dump_f80_96: ;\
		lea 8(%esp), %edx;\
		fldt (%edx);\
		mov 4(%esp), %edx;\
		fstpt (%edx);\
		movw $0, 10(%edx);\
		ret;\
      ");
      const char nan_inf_str[] = "\005nan\0\010infinity\0\5inf\0";  /* This mustn't be static, GCC would optimize it away, and the inline assembly code in ld96_strtold(...) wouldn't see it. */
      ld96u_t ld96_strtold(const char *nptr, char **endptr);  /* { ld96u_t r; r.ld = strtold(nptr, endptr); return r; } */
      __asm__(".global ld96_strtold; ld96_strtold:; \
		"/* Based on https://github.com/pts/minilibc686/blob/master/src/strtod.nasm */"\
		push %ebx;\
		push %esi;\
		push %edi;\
		push %ebp;\
		push $0x41200000;\
		push %ebp;\
		mov 0x20(%esp), %ebx;\
        "E"1:	mov (%ebx), %al;\
		cmp $0x20, %al;\
		je "E"2;\
		mov %al, %ah;\
		sub $9, %ah;\
		cmp $4, %ah;\
		ja "E"3;\
        "E"2:	inc %ebx;\
		jmp "E"1;\
        "E"3:	xor %ebp, %ebp;\
		cmp $0x2d, %al;\
		je "E"4;\
		cmp $0x2b, %al;\
		je "E"5;\
		jmp "E"6;\
        "E"4:	inc %ebp;\
        "E"5:	inc %ebx;\
        "E"6:	or $0xffffffff, %eax;\
		xor %edi, %edi;\
		xor %esi, %esi;\
		fldz ;\
		xor %edx, %edx;\
        "E"loop7:;\
		mov (%ebx), %dl;\
		sub $0x30, %dl;\
		cmp $9, %dl;\
		ja "E"after_loop7;\
		test %eax, %eax;\
		jge "E"8;\
		inc %eax;\
        "E"8:	test %eax, %eax;\
		jne "E"9;\
		test %dl, %dl;\
		je "E"10;\
        "E"9:	inc %eax;\
		cmp $0x15, %eax;\
		jg "E"10;\
		mov %edx, (%esp);\
		fmuls 4(%esp);\
		fiaddl (%esp);\
        "E"10:	inc %ebx;\
		jmp "E"loop7;\
        "E"after_loop7:;\
		cmp $0xfe, %dl;\
		jne "E"done_loop7;\
		test %esi, %esi;\
		jne "E"done_loop7;\
		inc %ebx;\
		mov %ebx, %esi;\
		jmp "E"loop7;\
        "E"done_loop7:;\
		test %eax, %eax;\
		jge "E"18;\
		test %esi, %esi;\
		jne "E"17;\
		xor %ecx, %ecx;\
		mov %esi, (%esp);\
		mov $nan_inf_str, %esi;\
        "E"loop13:;\
		mov %ebx, %edx;\
		mov %esi, %eax;\
		lea 0x1(%esi), %eax;\
        "E"14:	mov (%edx), %cl;\
		or $0x20, %cl;\
		cmp (%eax), %cl;\
		jne "E"16;\
		inc %edx;\
		inc %eax;\
		cmp %ch, (%eax);\
		jne "E"14;\
		fstp %st(0);\
		fildl (%esp);\
		fldz ;\
		fdivrp %st, %st(1);\
		test %ebp, %ebp;\
		je "E"15;\
		fchs ;\
        "E"15:	mov (%esi), %cl;\
		add %ecx, %ebx;\
		dec %ebx;\
		dec %ebx;\
		jmp "E"store_done;\
        "E"16:	mov (%esi), %cl;\
		add %ecx, %esi;\
		incb (%esp);\
		cmp %ch, %cl;\
		jne "E"loop13;\
        "E"17:	mov 0x20(%esp), %ebx;\
		jmp "E"store_done;\
        "E"18:	cmp $0x15, %eax;\
		jle "E"19;\
		sub $0x15, %eax;\
		add %eax, %edi;\
        "E"19:	test %esi, %esi;\
		je "E"20;\
		mov %esi, %eax;\
		sub %ebx, %eax;\
		add %eax, %edi;\
        "E"20:	test %ebp, %ebp;\
		je "E"21;\
		fchs ;\
        "E"21:	mov (%ebx), %al;\
		or $0x20, %al;\
		cmp $0x65, %al;\
		jne "E"29;\
		mov %ebx, (%esp);\
		xor %esi, %esi;\
		inc %esi;\
		inc %ebx;\
		mov (%ebx), %al;\
		cmp $0x2d, %al;\
		je "E"22;\
		cmp $0x2b, %al;\
		je "E"23;\
		jmp "E"24;\
        "E"store_done:;\
		mov 0x24(%esp), %eax;\
		test %eax, %eax;\
		je "E"36;\
		mov %ebx, (%eax);\
        "E"36:	mov 0x1c(%esp), %eax;\
		fstpt (%eax);\
		pop %ebp;\
		pop %ebp;\
		pop %ebp;\
		pop %edi;\
		pop %esi;\
		pop %ebx;\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
        "E"22:	neg %esi;\
        "E"23:	inc %ebx;\
        "E"24:	mov %ebx, %ebp;\
		xor %eax, %eax;\
		xor %edx, %edx;\
        "E"loop25:;\
		mov (%ebx), %dl;\
		sub $0x30, %dl;\
		cmp $9, %dl;\
		ja "E"27;\
		cmp $0x136d, %eax;\
		jge "E"26;\
		imul $0xa, %eax, %eax;\
		add %edx, %eax;\
        "E"26:	inc %ebx;\
		jmp "E"loop25;\
        "E"27:	cmp %ebp, %ebx;\
		jne "E"28;\
		mov (%esp), %ebx;\
        "E"28:	imul %esi, %eax;\
		add %eax, %edi;\
        "E"29:	fldz ;\
		"FUCOMIP_01_R_AX" ;\
		je "E"store_done;\
		mov %edi, %eax;\
		test %eax, %eax;\
		je "E"store_done;\
		jge "E"skip_neg;\
		neg %eax;\
        "E"skip_neg:;\
		flds 4(%esp);\
        "E"loop31:;\
		test $1, %al;\
		je "E"34;\
		test %edi, %edi;\
		jge "E"32;\
		fdivr %st, %st(1);\
		jmp "E"34;\
        "E"32:	fmul %st, %st(1);\
        "E"34:	fmul %st, %st(0);\
		shr %eax;\
		jne "E"loop31;\
		fstp %st(0);\
		jmp "E"store_done;\
      ");
      int     ld96_iszero(ld96u_t ld);  /* { return ld.ld == 0.0; } */
      __asm__(".global ld96_iszero;; ld96_iszero: ;\
		fldt 4(%esp);\
		fldz;\
		xor %ecx, %ecx;\
		"FUCOMIP_01_R_AX" ;\
		fstp %st(0);\
		setnp %al;\
		sete %cl;\
		and %ecx, %eax;\
		ret;\
      ");
      ld96u_t ld96_neg(ld96u_t ld);  /* { ld96u_t r; r.ld = -ld.ld; return r; } */
      __asm__(".global ld96_neg;; ld96_neg: ;\
		mov 4(%esp), %eax;\
		fldt 8(%esp);\
		fchs;\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      ld96u_t ld96_add(ld96u_t a, ld96u_t b);  /* { ld96u_t r; r.ld = a.ld + b.ld; return r; } */
      __asm__(".global ld96_add;; ld96_add: ;\
		mov 4(%esp), %eax;\
		fldt 8(%esp);\
		fldt 0x14(%esp);\
		faddp %st, %st(1);\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      ld96u_t ld96_sub(ld96u_t a, ld96u_t b);  /* { ld96u_t r; r.ld = a.ld - b.ld; return r; } */
      __asm__(".global ld96_sub;; ld96_sub: ;\
		mov 4(%esp), %eax;\
		fldt 8(%esp);\
		fldt 0x14(%esp);\
		fsubrp %st, %st(1);\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      ld96u_t ld96_mul(ld96u_t a, ld96u_t b);  /* { ld96u_t r; r.ld = a.ld * b.ld; return r; } */
      __asm__(".global ld96_mul;; ld96_mul: ;\
		mov 4(%esp), %eax;\
		fldt 8(%esp);\
		fldt 0x14(%esp);\
		fmulp %st, %st(1);\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      ld96u_t ld96_div(ld96u_t a, ld96u_t b);  /* { ld96u_t r; r.ld = a.ld / b.ld; return r; } */
      __asm__(".global ld96_div;; ld96_div: ;\
		mov 4(%esp), %eax;\
		fldt 8(%esp);\
		fldt 0x14(%esp);\
		fdivrp %st, %st(1);\
		fstpt (%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
      int     ld96_eq(ld96u_t a, ld96u_t b);  /* { return a.ld == b.ld; } */
      __asm__(".global ld96_eq;; ld96_eq: ;\
		fldt 4(%esp);\
		fldt 0x10(%esp);\
		fxch %st(1);\
		xor %ecx, %ecx;\
		"FUCOMIP_01_R_AX" ;\
		fstp %st(0);\
		setnp %al;\
		sete %cl;\
		and %ecx, %eax;\
		ret;\
      ");
      int     ld96_le(ld96u_t a, ld96u_t b);  /* { return a.ld <= b.ld; } */
      __asm__(".global ld96_le;; ld96_le: ;\
		fldt 4(%esp);\
		fldt 0x10(%esp);\
		"FUCOMIP_01_R_AX" ;\
		fstp %st(0);\
		setnb %al;"  /* AL := (CF == 0). */"\
		movzbl %al, %eax;\
		ret;\
      ");
      int     ld96_lt(ld96u_t a, ld96u_t b);  /* { return a.ld < b.ld; } */
      __asm__(".global ld96_lt;; ld96_lt: ;\
		fldt 4(%esp);\
		fldt 0x10(%esp);\
		"FUCOMIP_01_R_AX" ;\
		fstp %st(0);\
		seta %al;"  /* AL := (CF == 0 && ZF == 0). */"\
		movzbl %al, %eax;\
		ret;\
      ");
     ld96u_t ld96_from_nan(void);
      __asm__(".global ld96_from_nan;; ld96_from_nan: ;\
		mov 4(%esp), %eax;\
		xor %edx, %edx;\
		mov %edx, (%eax);\
		movl $0xc0000000, 4(%eax);\
		movw $0x7fff, 8(%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
     ld96u_t ld96_from_infinity(void);
      __asm__(".global ld96_from_infinity;; ld96_from_infinity: ;\
		mov 4(%esp), %eax;\
		xor %edx, %edx;\
		mov %edx, (%eax);\
		movl $0x80000000, 4(%eax);\
		movw $0x7fff, 8(%eax);\
		ret $4; "  /* Callee cleans up the struct return pointer. */"\
      ");
#    else  /* else CONFIG_LD96_S */
#      include <stdlib.h>
#      ifdef __TINYC__
#        include <string.h>  /* For compiler-generated memcpy(3). */
#      endif
#      ifdef __STRICT_ANSI__
        long double strtold(const char *nptr, char **endptr);
#      endif
#      if !defined(__WATCOMC__) && !defined(CONFIG_LD96_S) && __SIZEOF_LONG_DOUBLE__ > 12  /* GCC >=4.2 has __SIZEOF_LONG_DOUBLE__, and it's 16 for __amd64__. */
        /* We add a `long double' member just for the alignment. */
        typedef union ld96 { struct { unsigned a, b, c; } s; long double ld; } ld96_t;  /* Matches "ld96.h". */
#      else
        typedef struct ld96 { unsigned a, b, c; } ld96_t;  /* Matches "ld96.h". */
#      endif
      /* Everything must match "ld96.h" here. */
      /* !! TODO(pts): This produces incorrect `.long' values with TCC 0.9.26, even though src/mip/test_ld96.c succeeds, and CONFIG_LD96_S also succeeds.  */
      typedef char assert_ld96u_size_strict[sizeof(ld96_t) == sizeof(ld96u_t) ? 1 : -1];  /* Needed by 2-argument functions such as ld96_add. */
      typedef char assert_long_double_size[sizeof(long double) == 10 || sizeof(long double) == 12 || sizeof(long double) == 16 ? 1 : -1];  /* Sanity check, just to avoid sizeof(long double) <= 8. */
      typedef char assert_long_double_size_le[sizeof(long double) <= sizeof(ld96_t) ? 1 : -1];  /* If this fails, specify `gcc -m96bit-long-double'. The switch doesn't exist for Clang. It shouldn't be needed anyway for GCC >=4.2, because `union ld96' contains `long double'. */
      ld96u_t ld96_from_ull(unsigned long long u) { ld96u_t r; r.ld = u; return r; }
      ld96u_t ld96_from_ll(long long v) { ld96u_t r; r.ld = v; return r; }
      long long ld96_to_ll(ld96u_t ld) { return ld.ld; }
      unsigned long long ld96_to_ull(ld96u_t ld) { return ld.ld > 0 ? (unsigned long long)ld.ld : 0ULL; }  /* GCC 7.5.0 returns junk for negative input by default. TODO(pts): What does it return? !! Why isn't non-CONFIG_LD96 broken? Probably because of inlining. */
#      if 0
        ld96u_t ld96_from_f32(float f) { ld96u_t r; r.ld = f; return r; }
        ld96u_t ld96_from_f64(double d) { ld96u_t r; r.ld = d; return r; }
        float   ld96_to_f32(ld96u_t ld) { return ld.ld; }
        double  ld96_to_f64(ld96u_t ld) { return ld.ld; }
#      endif
      ld96u_t ld96_strtold(const char *nptr, char **endptr) { ld96u_t r; r.ld = strtold(nptr, endptr); return r; }
      int     ld96_iszero(ld96u_t ld) { return ld.ld == 0.0; }
      ld96u_t ld96_neg(ld96u_t ld) { ld96u_t r; r.ld = -ld.ld; return r; }
      ld96u_t ld96_add(ld96u_t a, ld96u_t b) { ld96u_t r; r.ld = a.ld + b.ld; return r; }
      ld96u_t ld96_sub(ld96u_t a, ld96u_t b) { ld96u_t r; r.ld = a.ld - b.ld; return r; }
      ld96u_t ld96_mul(ld96u_t a, ld96u_t b) { ld96u_t r; r.ld = a.ld * b.ld; return r; }
      ld96u_t ld96_div(ld96u_t a, ld96u_t b) { ld96u_t r; r.ld = a.ld / b.ld; return r; }
      int     ld96_eq(ld96u_t a, ld96u_t b) { return a.ld == b.ld; }
      int     ld96_le(ld96u_t a, ld96u_t b) { return a.ld <= b.ld; }
      int     ld96_lt(ld96u_t a, ld96u_t b) { return a.ld <  b.ld; }
      void    ld96_dump_f32(char *buf, ld96u_t ld) { *(float*)buf = ld.ld; }
      void    ld96_dump_f64(char *buf, ld96u_t ld) { *(double*)buf = ld.ld; }
      void    ld96_dump_f80_96(char *buf, ld96u_t ld) {
        char tmp[sizeof(ld96u_t)], *buf2;
        if (sizeof(ld96u_t) > 12) {  /* __amd64__ */
          buf2 = tmp;
          *(long double*)buf2 = ld.ld;
          *(double*)buf = *(double*)buf2;
          ((int*)buf)[2] = ((int*)buf2)[2];
        } else {
          *(long double*)buf = ld.ld;
        }
        buf[10] = buf[11] = 0;
      }
      ld96u_t ld96_round_f32(ld96u_t ld) { ld96u_t r; r.ld = (float )ld.ld; return r; }
      ld96u_t ld96_round_f64(ld96u_t ld) { ld96u_t r; r.ld = (double)ld.ld; return r; }
#    ifdef __GNUC__  /* Also __PCC__, but not __TINYC__ or __WATCOMC__. */
#      define NAN __builtin_nanl("")
#      define INFINITY __builtin_infl()
#    else
#      include <float.h>
#      include <math.h>  /* For INFINITY and NAN. */
#    endif
     ld96u_t ld96_from_nan(void) {
       ld96u_t r;
#       ifdef NAN  /* C99. */
         r.ld = NAN;
#       else  /* C89. */
         r.ld = log(-1.0);
#       endif
       return r;
     }
#     ifndef INFINITY  /* Not C99. */
       typedef char assert_float_size[sizeof(float) == 4 ? 1 : -1];
#     endif
     ld96u_t ld96_from_infinity(void) {
       ld96u_t r;
#       ifdef INFINITY  /* C99. */
         r.ld = INFINITY;
#       else  /* C89. */
         float f = 1L << 31;
         f *= f;  /* 2 ** 62. */
         f *= f;  /* 2 ** 124. */
         f *= f;  /* 2 ** 248, overflows f32, becomes INFINITY. */
         r.ld = f;
#       endif
       return r;
     }
#    endif  /* else CONFIG_LD96_S */
#  else  /* else ifndef __WATCOMC__ */
#    if !(defined(__386__) || defined(_M_I386))
#      error Watcom C assembly implementation of ld96 supports 32-bit i386 only (not even amd64).
#    elif _M_IX86 >= 600  /* i686 (P6) or later. The other implementation ruins AX as a side effect. */
#      define FUCOMIP_01_R_AX fucomip st, st(1)
#    else  /* i386 or later. It ruins AX as a side effect. */
#      define FUCOMIP_01_R_AX db 0xdd, 0xe9, 0xdf, 0xe0, 0x9e  /* fucomp st(1); fnstsw ax; sahf */  /* How to put multiple assembly instructions to a macro i.e. better than db? */
#    endif
    /* The assembly rountines below assume size 12, they don't work with size 10 or 16. */
    typedef char assert_ld96_specific_size[sizeof(ld96u_t) == 12 ? 1 : -1];
    /* Oddly enough, for all of these floating-point functions, the
     * __watcall argument passing boilerplate is longer than for GCC __cdecl
     * (as in the above __asm__). Usually it's the opposite.
     */
    __declspec(naked) void __watcall ld96_set_ld_precision(void) { __asm {
		push eax
		fnstcw word ptr [esp]
		or byte ptr [esp+1], 3  /* Set precision to ld96. */
		fldcw word ptr [esp]
		pop eax
		ret
    } }
    __declspec(naked) ld96u_t __watcall ld96_from_ull(unsigned long long u) { (void)u; __asm {  /* ld96u_t r; r.ld = u; return r; */
		push edx  /* High dword of argument v. */
		push eax  /* Low  dword of argument v. */
		fild qword ptr [esp]
		test edx, edx
		jns L35
		push 0x5f800000  /* (f32) of 1 << 64. */
		fadd dword ptr [esp]
		pop edx  /* EDX := junk. */
      L35:	pop edx
		pop edx
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret
    } }
    __declspec(naked) ld96u_t __watcall ld96_from_ll(long long v) { (void)v; __asm {  /* ld96u_t r; r.ld = v; return r; } */
		push edx  /* High dword of argument v. */
		push eax  /* Low  dword of argument v. */
		fild qword ptr [esp]
		pop edx
		pop eax
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret
    } }
    __declspec(naked) long long __watcall ld96_to_ll(ld96u_t ld) { (void)ld; __asm {  /* { return ld.ld; } */
		lea edx, [esp+4]
		fld tbyte ptr [edx+0]
		fnstcw word ptr [edx+0+8]  /* Will be modified. */
		fnstcw word ptr [edx+0+10]  /* Save. */
		mov byte ptr [edx+0+8+1], 0xc  /* A more specific valu, 0xc7f, is not needed. Any 0xc.. seems to work. */
		fldcw word ptr [edx+0+8]  /* Load and use modified. */
		fistp qword ptr [edx+0]
		fldcw word ptr [edx+0+10]  /* Load and use saved. */
		mov eax, [edx+0]
		mov edx, [edx+0+4]
		ret 0xc  /* Callee pops. */
    } }
    __declspec(naked) unsigned long long __watcall ld96_to_ull(ld96u_t ld) { (void)ld; __asm {  /* { return ld.ld; } */
		lea edx, [esp+4]
		fld tbyte ptr [edx+0]
		fnstcw word ptr [edx+0+8]
		fnstcw word ptr [edx+0+10]  /* Save. */
		mov byte ptr [edx+0+8+1], 0xf
		fldcw word ptr [edx+0+8]
		mov dword ptr [edx+0], 0x5f000000
		fsub dword ptr [edx+0]
		fistp qword ptr [edx+0]
		xor byte ptr [edx+0+7], 0x80  /* Flip sign. */
		fldcw word ptr [edx+0+10]  /* Load and use saved. */
		mov eax, [edx+0]
		mov edx, [edx+0+4]
		ret 0xc  /* Callee pops. */
    } }
#    if 0
      __declspec(naked) ld96u_t __watcall ld96_from_f32(float f) { (void)f; __asm {  /* ld96u_t r; r.ld = f; return r; */
		fld dword ptr [esp+4]
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret 4  /* Callee pops. */
      } }
      __declspec(naked) ld96u_t __watcall ld96_from_f64(double d) { (void)d; __asm {  /* ld96u_t r; r.ld = d; return r; */
		fld qword ptr [esp+4]
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret 8  /* Callee pops. */
      } }
      __declspec(naked) float   __watcall ld96_to_f32(ld96u_t ld) { (void)ld; __asm {  /* return ld.ld; */
		lea eax, [esp+4]
		fld tbyte ptr [eax]
		fstp dword ptr [eax]
		fld dword ptr [eax]
		ret 0xc  /* Callee pops. */
      } }
      __declspec(naked) double  __watcall ld96_to_f64(ld96u_t ld) { (void)ld; __asm {  /* return ld.ld; */
		lea eax, [esp+4]
		fld tbyte ptr [eax]
		fstp qword ptr [eax]
		fld qword ptr [eax]
		ret 0xc  /* Callee pops. */
      } }
#    endif
    __declspec(naked) ld96u_t __watcall ld96_round_f32(ld96u_t ld) { (void)ld; __asm {  /* ld96u_t r; r.ld = (float) ld.ld; return r; */
		lea eax, [esp+4]
		fld tbyte ptr [eax]
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp dword ptr [eax]
		fld dword ptr [eax]
		fstp tbyte ptr [eax]
		ret 0xc  /* Callee pops. */
    } }
    __declspec(naked) ld96u_t __watcall ld96_round_f64(ld96u_t ld) { (void)ld; __asm {  /* ld96u_t r; r.ld = (double)ld.ld; return r; */
		lea eax, [esp+4]
		fld tbyte ptr [eax]
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp qword ptr [eax]
		fld qword ptr [eax]
		fstp tbyte ptr [eax]
		ret 0xc  /* Callee pops. */
    } }
    __declspec(naked) void    __watcall ld96_dump_f32(char buf[4], ld96u_t ld) { (void)buf; (void)ld; __asm {
		lea edx, [esp+4]
		fld tbyte ptr [edx]
		fstp dword ptr [eax]
		ret 0xc  /* Callee pops. */
    } }
    __declspec(naked) void    __watcall ld96_dump_f64(char buf[8], ld96u_t ld) { (void)buf; (void)ld; __asm {
		lea edx, [esp+4]
		fld tbyte ptr [edx]
		fstp qword ptr [eax]
		ret 0xc  /* Callee pops. */
    } }
    __declspec(naked) void    __watcall ld96_dump_f80_96(char buf[12], ld96u_t ld) { (void)buf; (void)ld; __asm {
		lea edx, [esp+4]
		fld tbyte ptr [edx]
		fstp tbyte ptr [eax]
		mov word ptr [eax+10], 0
		ret 0xc  /* Callee pops. */
    } }
    static const char nan_inf_str[] = "\005nan\0\010infinity\0\5inf\0";
    __declspec(naked) ld96u_t __watcall ld96_strtold(const char *nptr, char **endptr) { (void)nptr; (void)endptr; __asm {  /* ld96u_t r; r.ld = strtold(nptr, endptr); return r; */
		/* Based on https://github.com/pts/minilibc686/blob/master/src/strtod.nasm */
		push edx  /* Argument endptr. */
		push eax  /* Argument nptr. */
		push esi  /* Struct return pointer. */
		push ecx  /* Save it. */
		push ebx
		push esi
		push edi
		push ebp
		push 0x41200000
		push ebp
		mov ebx, dword ptr [esp+0x1c+4]
      L1:	mov al, byte ptr [ebx]
		cmp al, 0x20
		je L2
		mov ah, al
		sub ah, 9
		cmp ah, 4
		ja L3
      L2:	inc ebx
		jmp L1
      L3:	xor ebp, ebp
		cmp al, 0x2d
		je L4
		cmp al, 0x2b
		je L5
		jmp L6
      L4:	inc ebp
      L5:	inc ebx
      L6:	or eax, 0x0ffffffff
		xor edi, edi
		xor esi, esi
		fldz
		xor edx, edx
      Lloop7:	mov dl, byte ptr [ebx]
		sub dl, 0x30
		cmp dl, 9
		ja Lafter_loop7
		test eax, eax
		jge L8
		inc eax
      L8:	test eax, eax
		jne L9
		test dl, dl
		je L10
      L9:	inc eax
		cmp eax, 0x15
		jg L10
		mov dword ptr [esp], edx
		fmul dword ptr 4[esp]
		fiadd dword ptr [esp]
      L10:	inc ebx
		jmp Lloop7
      Lafter_loop7:
		cmp dl, 0x0fe
		jne Ldone_loop7
		test esi, esi
		jne Ldone_loop7
		inc ebx
		mov esi, ebx
		jmp Lloop7
      Ldone_loop7:
		test eax, eax
		jge L18
		test esi, esi
		jne L17
		xor ecx, ecx
		mov dword ptr [esp], esi
		mov esi, offset nan_inf_str
      Lloop13:	mov edx, ebx
		mov eax, esi
		lea eax, 1[esi]
      L14:	mov cl, byte ptr [edx]
		or cl, 0x20
		cmp cl, byte ptr [eax]
		jne L16
		inc edx
		inc eax
		cmp byte ptr [eax], ch
		jne L14
		fstp st
		fild dword ptr [esp]
		fldz
		fdivp st(1), st
		test ebp, ebp
		je L15
		fchs
      L15:	mov cl, byte ptr [esi]
		add ebx, ecx
		dec ebx
		dec ebx
		jmp Lstore_done
      L16:	mov cl, byte ptr [esi]
		add esi, ecx
		inc byte ptr [esp]
		cmp cl, ch
		jne Lloop13
      L17:	mov ebx, dword ptr [esp+0x1c+4]
		jmp Lstore_done
      L18:	cmp eax, 0x15
		jle L19
		sub eax, 0x15
		add edi, eax
      L19:	test esi, esi
		je L20
		mov eax, esi
		sub eax, ebx
		add edi, eax
      L20:	test ebp, ebp
		je L21
		fchs
      L21:	mov al, byte ptr [ebx]
		or al, 0x20
		cmp al, 0x65
		jne L29
		mov dword ptr [esp], ebx
		xor esi, esi
		inc esi
		inc ebx
		mov al, byte ptr [ebx]
		cmp al, 0x2d
		je L22
		cmp al, 0x2b
		je L23
		jmp L24
      Lstore_done:
		mov eax, dword ptr [esp+0x20+4]
		test eax, eax
		je L36
		mov dword ptr [eax], ebx
      L36:	pop ebp
		pop ebp
		pop ebp
		pop edi
		pop esi
		pop ebx
		pop ecx  /* Restore it. */
		pop esi  /* Struct return pointer. */
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		pop edx  /* Argument nptr. */
		pop edx  /* Argumnet endptr. */
		ret
      L22:	neg esi
      L23:	inc ebx
      L24:	mov ebp, ebx
		xor eax, eax
		xor edx, edx
      Lloop25:	mov dl, byte ptr [ebx]
		sub dl, 0x30
		cmp dl, 9
		ja L27
		cmp eax, 0x136d
		jge L26
		imul eax, 0xa
		add eax, edx
      L26:	inc ebx
		jmp Lloop25
      L27:	cmp ebx, ebp
		jne L28
		mov ebx, dword ptr [esp]
      L28:	imul eax, esi
		add edi, eax
      L29:	fldz
		FUCOMIP_01_R_AX
		je Lstore_done
		mov eax, edi
		test eax, eax
		je Lstore_done
		jge Lskip_neg
		neg eax
      Lskip_neg:
		fld dword ptr 4[esp]
      Lloop31:	test al, 1
		je L34
		test edi, edi
		jge L32
		fdiv st(1), st
		jmp L34
      L32:	fmul st(1), st
      L34:	fmul st, st
		shr eax, 1
		jne Lloop31
		fstp st
		jmp Lstore_done
    } }
    __declspec(naked) int     __watcall ld96_iszero(ld96u_t ld) { (void)ld; __asm {  /* return ld.ld == 0.0; */
		fld tbyte ptr [esp+4]
		fldz
		push ecx  /* Save. */
		xor ecx, ecx
		FUCOMIP_01_R_AX
		fstp st
		setnp al
		sete cl
		and eax, ecx
		pop ecx  /* Restore. */
		ret 0xc  /* Callee pops. */
    } }
    __declspec(naked) ld96u_t __watcall ld96_neg(ld96u_t ld) { (void)ld; __asm {  /* ld96u_t r; r.ld = -ld.ld; return r; */
		fld tbyte ptr [esp+4]
		fchs
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret 0xc  /* Callee pops. */
    } }
    __declspec(naked) ld96u_t __watcall ld96_add(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* ld96u_t r; r.ld = a.ld + b.ld; return r; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		faddp st(1), st
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret 2*0xc  /* Callee pops. */
    } }
    __declspec(naked) ld96u_t __watcall ld96_sub(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* ld96u_t r; r.ld = a.ld - b.ld; return r; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		fsubp st(1), st
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret 2*0xc  /* Callee pops. */
    } }
    __declspec(naked) ld96u_t __watcall ld96_mul(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* ld96u_t r; r.ld = a.ld * b.ld; return r; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		fmulp st(1), st
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret 2*0xc  /* Callee pops. */
    } }
    __declspec(naked) ld96u_t __watcall ld96_div(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* ld96u_t r; r.ld = a.ld / b.ld; return r; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		fdivp st(1), st
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		fstp tbyte ptr [eax]
		ret 2*0xc  /* Callee pops. */
    } }
    __declspec(naked) int     __watcall ld96_eq(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* return a.ld == b.ld; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		fxch st(1)
		push ecx  /* Save. */
		xor ecx, ecx
		FUCOMIP_01_R_AX
		fstp st
		setnp al
		sete cl
		and eax, ecx
		pop ecx  /* Restore. */
		ret 2*0xc  /* Callee pops. */
    } }
    __declspec(naked) int     __watcall ld96_le(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* return a.ld < b.ld; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		FUCOMIP_01_R_AX
		fstp st
		setnb al  /* AL := (CF == 0). */
		movzx eax, al
		ret 2*0xc  /* Callee pops. */
    } }
    __declspec(naked) int     __watcall ld96_lt(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* return a.ld < b.ld; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		FUCOMIP_01_R_AX
		fstp st
		seta al  /* AL := (CF == 0 && ZF == 0). */
		movzx eax, al
		ret 2*0xc  /* Callee pops. */
    } }
    __declspec(naked) ld96u_t __watcall ld96_from_nan(void) { __asm {
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		mov dword ptr [eax], 0
		mov dword ptr [eax+4], 0xc0000000
		mov word ptr [eax+8], 0x7fff
		ret
    } }
    __declspec(naked) ld96u_t __watcall ld96_from_infinity(void) { __asm {
		mov eax, esi  /* ESI is the result pointer. The caller expects this in EAX upon return. */
		mov dword ptr [eax], 0
		mov dword ptr [eax+4], 0x80000000
		mov word ptr [eax+8], 0x7fff
		ret
    } }
#  endif
#else
  typedef char assert_long_double_size[sizeof(long double) == 10 || sizeof(long double) == 12 || sizeof(long double) == 16 ? 1 : -1];  /* Sanity check, just to avoid sizeof(long double) <= 8. */
#  ifndef __GNUC__  /* Also __PCC__, but not __TINYC__ or __WATCOMC__. See definition in "ld96.h". */
    long double ld96_from_infinity();
    long double ld96_from_nan() {
#      ifdef NAN  /* C99. */
        return NAN;
#      else  /* C89. */
         return ld96_from_infinity() * 0.0;  /* Returns positive NaN on x87 (8087). */
#      endif
    }
#    ifndef INFINITY  /* Not C99. */
      typedef char assert_float_size[sizeof(float) == 4 ? 1 : -1];
#    endif
    long double ld96_from_infinity() {
#      ifdef INFINITY  /* C99. */
        return INFINITY;
#      else  /* C89. */
        float f = 1L << 31;
        f *= f;  /* 2 ** 62. */
        f *= f;  /* 2 ** 124. */
        f *= f;  /* 2 ** 248, overflows f32, becomes INFINITY. */
        return f;
#      endif
  }
#  endif
  unsigned long long ld96_to_ull(long double d) { return d > 0.0 ? (unsigned long long)d : 0LL; }  /* Make sure that it returns 0 for negative input. */
  void ld96_dump_f32(char *buf, long double ld) {
    *(float*)buf = ld;
  }
  void ld96_dump_f64(char *buf, long double ld) {
    *(double*)buf = ld;
  }
  void ld96_dump_f80_96(char *buf, long double ld) {
    char tmp[sizeof(long double)], *buf2;
    if (sizeof(long double) > 12) {  /* __amd64__ */
      buf2 = tmp;
      *(long double*)buf2 = ld;
      *(double*)buf = *(double*)buf2;
      ((int*)buf)[2] = ((int*)buf2)[2];
    } else {
      *(long double*)buf = ld;
    }
    buf[10] = buf[11] = 0;
  }
#endif  /* CONFIG_LD96 */
