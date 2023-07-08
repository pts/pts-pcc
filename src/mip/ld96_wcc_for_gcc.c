/*
 * ld96_wcc_for_gcc.c: compile with OpenWatcom, to be used by GCC
 * by pts@fazekas.hu at Thu Jul  6 16:46:03 CEST 2023
 *
 * This file is unmaintained.
 *
 * The __asm__("...") parts of file ld96_gcc.s was generated from this file.
 * It contains the assembly instructions in OpenWatcom syntax (rather than
 * AT&T). However, this code only works if called from C code compiled by
 * GCC (or pts-tcc or pts-pcc), because the ABI differences between
 * OpenWatcom and GCC of calling functions which return a struct.
 */

#if !defined(__WATCOMC__) || !defined(__386__)
#  error OpenWatcom with i386 target required.
#endif

_Packed typedef union ld96u {
  struct { unsigned a, b, c; } s;
  long double ld;  /* This doesn't matter with __WATCOMC__. */
} ld96u_t;
typedef char assert_unsigned_size[sizeof(unsigned) == 4 ? 1 : -1];
typedef char assert_unsigned_long_long_size[sizeof(unsigned long long) == 8 ? 1 : -1];
typedef char assert_ld96_size[sizeof(ld96u_t) == 12 || sizeof(ld96u_t) == 16 ? 1 : -1];

#    if !(defined(__386__) || defined(_M_I386))
#      error Watcom C is supported for i386 only.
#    elif _M_IX86 >= 600  /* i686 (P6) or later. */
#      define FUCOMIP_01 fucomip st, st(1)
#    else  /* i386 or later. */
#      define FUCOMIP_01 db 0xdd, 0xe9, 0xdf, 0xe0, 0x9e  /* fucomp st(1); fnstsw ax; sahf */  /* How to put multiple assembly instructions to a macro i.e. better than db? */
#    endif

__declspec(naked) ld96u_t ld96_from_ull(unsigned long long u) { (void)u; __asm {  /* ld96u_t r; r.ld = u; return r; */
		fild qword ptr [esp+8]
		cmp byte ptr [esp+0xf], 0
		jns L2
		push 0x5f800000  /* (f32) of 1 << 64. */
		fadd dword ptr [esp]
		pop edx  /* EDX := junk. */
  L2:		mov eax, [esp+0x4]
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) ld96u_t ld96_from_ll(long long v){ (void)v; __asm {  /* ld96u_t r; r.ld = v; return r; } */
		fild qword ptr [esp+8]
		mov eax, [esp+0x4]
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) long long ld96_to_ll(ld96u_t ld) { (void)ld; __asm {  /* { return ld.ld; } */
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
		ret
} }
__declspec(naked) unsigned long long ld96_to_ull(ld96u_t ld) { (void)ld; __asm {  /* { return ld.ld; } */
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
		ret
} }
__declspec(naked) ld96u_t ld96_from_f32(float f) { (void)f; __asm {  /* ld96u_t r; r.ld = f; return r; */
		mov eax, [esp+4]
		fld dword ptr [esp+8]
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) ld96u_t ld96_from_f64(double d) { (void)d; __asm {  /* ld96u_t r; r.ld = d; return r; */
		mov eax, [esp+4]
		fld qword ptr [esp+8]
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) float   ld96_to_f32(ld96u_t ld) { (void)ld; __asm {  /* return ld.ld; */
		lea edx, [esp+4]
		fld tbyte ptr [edx]
		fstp dword ptr [edx]
		fld dword ptr [edx]
		ret
} }
__declspec(naked) double  ld96_to_f64(ld96u_t ld) { (void)ld; __asm {  /* return ld.ld; */
		lea edx, [esp+4]
		fld tbyte ptr [edx]
		fstp qword ptr [edx]
		fld qword ptr [edx]
		ret
} }
static const char nan_inf_str[] = "\005nan\0\010infinity\0\5inf\0";
__declspec(naked) ld96u_t ld96_strtold(const char *nptr, char **endptr) { (void)nptr; (void)endptr; __asm {  /* ld96u_t r; r.ld = strtold(nptr, endptr); return r; */
		/* Based on https://github.com/pts/minilibc686/blob/master/src/strtod.nasm */
		push ebx
		push esi
		push edi
		push ebp
		push 0x41200000
		push ebp
		mov ebx, dword ptr [esp+0x1c+4]
  L1:
		mov al, byte ptr [ebx]
		cmp al, 0x20
		je L2
		mov ah, al
		sub ah, 9
		cmp ah, 4
		ja L3
  L2:
		inc ebx
		jmp L1
  L3:
		xor ebp, ebp
		cmp al, 0x2d
		je L4
		cmp al, 0x2b
		je L5
		jmp L6
  L4:
		inc ebp
  L5:
		inc ebx
  L6:
		or eax, 0x0ffffffff
		xor edi, edi
		xor esi, esi
		fldz
		xor edx, edx
  Lloop7:
		mov dl, byte ptr [ebx]
		sub dl, 0x30
		cmp dl, 9
		ja Lafter_loop7
		test eax, eax
		jge L8
		inc eax
  L8:
		test eax, eax
		jne L9
		test dl, dl
		je L10
  L9:
		inc eax
		cmp eax, 0x15
		jg L10
		mov dword ptr [esp], edx
		fmul dword ptr 4[esp]
		fiadd dword ptr [esp]
  L10:
		inc ebx
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
  Lloop13:
		mov edx, ebx
		mov eax, esi
		lea eax, 1[esi]
  L14:
		mov cl, byte ptr [edx]
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
  L15:
		mov cl, byte ptr [esi]
		add ebx, ecx
		dec ebx
		dec ebx
		jmp Lstore_done
  L16:
		mov cl, byte ptr [esi]
		add esi, ecx
		inc byte ptr [esp]
		cmp cl, ch
		jne Lloop13
  L17:
		mov ebx, dword ptr [esp+0x1c+4]
		jmp Lstore_done
  L18:
		cmp eax, 0x15
		jle L19
		sub eax, 0x15
		add edi, eax
  L19:
		test esi, esi
		je L20
		mov eax, esi
		sub eax, ebx
		add edi, eax
  L20:
		test ebp, ebp
		je L21
		fchs
  L21:
		mov al, byte ptr [ebx]
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
  L36:
		mov eax, dword ptr [esp+0x1c]
		fstp tbyte ptr [eax]
		pop ebp
		pop ebp
		pop ebp
		pop edi
		pop esi
		pop ebx
		ret 4  /* Callee cleans up the struct return pointer. */
  L22:
		neg esi
  L23:
		inc ebx
  L24:
		mov ebp, ebx
		xor eax, eax
		xor edx, edx
  Lloop25:
		mov dl, byte ptr [ebx]
		sub dl, 0x30
		cmp dl, 9
		ja L27
		cmp eax, 0x136d
		jge L26
		imul eax, 0xa
		add eax, edx
  L26:
		inc ebx
		jmp Lloop25
  L27:
		cmp ebx, ebp
		jne L28
		mov ebx, dword ptr [esp]
  L28:
		imul eax, esi
		add edi, eax
  L29:
		fldz
		FUCOMIP_01
		je Lstore_done
		mov eax, edi
		test eax, eax
		je Lstore_done
		jge Lskip_neg
		neg eax
  Lskip_neg:
		fld dword ptr 4[esp]
  Lloop31:
		test al, 1
		je L34
		test edi, edi
		jge L32
		fdiv st(1), st
		jmp L34
  L32:
		fmul st(1), st
  L34:
		fmul st, st
		shr eax, 1
		jne Lloop31
		fstp st
		jmp Lstore_done
} }
__declspec(naked) int     ld96_iszero(ld96u_t ld) { (void)ld; __asm {  /* return ld.ld == 0.0; */
		fld tbyte ptr [esp+4]
		fldz
		xor ecx, ecx
		FUCOMIP_01
		fstp st
		setnp al
		sete cl
		and eax, ecx
		ret
} }
__declspec(naked) ld96u_t ld96_neg(ld96u_t ld) { (void)ld; __asm {  /* ld96u_t r; r.ld = -ld.ld; return r; */
		mov eax, [esp+4]
		fld tbyte ptr [esp+8]
		fchs
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) ld96u_t ld96_add(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* ld96u_t r; r.ld = a.ld + b.ld; return r; */
		mov eax, [esp+4]
		fld tbyte ptr [esp+8]
		fld tbyte ptr [esp+0x14]
		faddp st(1), st
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) ld96u_t ld96_sub(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* ld96u_t r; r.ld = a.ld - b.ld; return r; */
		mov eax, [esp+4]
		fld tbyte ptr [esp+8]
		fld tbyte ptr [esp+0x14]
		fsubp st(1), st
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) ld96u_t ld96_mul(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* ld96u_t r; r.ld = a.ld * b.ld; return r; */
		mov eax, [esp+4]
		fld tbyte ptr [esp+8]
		fld tbyte ptr [esp+0x14]
		fmulp st(1), st
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) ld96u_t ld96_div(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* ld96u_t r; r.ld = a.ld / b.ld; return r; */
		mov eax, [esp+4]
		fld tbyte ptr [esp+8]
		fld tbyte ptr [esp+0x14]
		fdivp st(1), st
		fstp tbyte ptr [eax]
		ret 4  /* Callee cleans up the struct return pointer. */
} }
__declspec(naked) int     ld96_eq(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* return a.ld == b.ld; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		fxch st(1)
		xor ecx, ecx
		FUCOMIP_01
		fstp st
		setnp al
		sete cl
		and eax, ecx
		ret
} }
__declspec(naked) int     ld96_lt(ld96u_t a, ld96u_t b) { (void)a; (void)b; __asm {  /* return a.ld < b.ld; */
		fld tbyte ptr [esp+4]
		fld tbyte ptr [esp+0x10]
		FUCOMIP_01
		fstp st
		seta al
		movzx eax, al
		ret
} }
