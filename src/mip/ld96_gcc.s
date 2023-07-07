/*
 * ld96_gcc.s: 96-bit long double emulation, usable but not required for GCC
 * by pts@fazekas.hu at Thu Jul  6 16:46:03 CEST 2023
 *
 * This file was generated from a disassembly output, so it doesn't have
 * many comments. See src/mip/ld96_wcc_for_gcc.c instead for more info about
 * each function.
 *
 * TODO(pts): Use `fucomip' instead of `fucomp' on i686.
 */

.text

.global ld96_from_ull
ld96_from_ull:
		fildll 0x8(%esp)
		cmpb $0x0, 0xf(%esp)
		jns .L2
		push $0x5f800000
		fadds (%esp)
		pop %edx
.L2:		mov 0x4(%esp), %eax
		fstpt (%eax)
		ret $0x4

.global ld96_from_ll
ld96_from_ll:
		fildll 0x8(%esp)
		mov 0x4(%esp), %eax
		fstpt (%eax)
		ret $0x4

.global ld96_to_ll
ld96_to_ll:
		lea 0x4(%esp), %edx
		fldt (%edx)
		fnstcw 0x8(%edx)
		fnstcw 0xa(%edx)
		movb $0xc, 0x9(%edx)
		fldcw 0x8(%edx)
		fistpll (%edx)
		fldcw 0xa(%edx)
		mov (%edx), %eax
		mov 0x4(%edx), %edx
		ret

.global ld96_to_ull
ld96_to_ull:
		lea 0x4(%esp), %edx
		fldt (%edx)
		fnstcw 0x8(%edx)
		fnstcw 0xa(%edx)
		movb $0xf, 0x9(%edx)
		fldcw 0x8(%edx)
		movl $0x5f000000, (%edx)
		fsubs (%edx)
		fistpll (%edx)
		xorb $0x80, 0x7(%edx)
		fldcw 0xa(%edx)
		mov (%edx), %eax
		mov 0x4(%edx), %edx
		ret

.global ld96_from_f32
ld96_from_f32:
		mov 0x4(%esp), %eax
		flds 0x8(%esp)
		fstpt (%eax)
		ret $0x4

.global ld96_from_f64
ld96_from_f64:
		mov 0x4(%esp), %eax
		fldl 0x8(%esp)
		fstpt (%eax)
		ret $0x4

.global ld96_to_f32
ld96_to_f32:
		lea 0x4(%esp), %edx
		fldt (%edx)
		fstps (%edx)
		flds (%edx)
		ret

.global ld96_to_f64
ld96_to_f64:
		lea 0x4(%esp), %edx
		fldt (%edx)
		fstpl (%edx)
		fldl (%edx)
		ret

.global ld96_strtold
ld96_strtold:
		push %ebx
		push %esi
		push %edi
		push %ebp
		push $0x41200000
		push %ebp
		mov 0x20(%esp), %ebx
.Lb4:		mov (%ebx), %al
		cmp $0x20, %al
		je .Lcc
		mov %al, %ah
		sub $0x9, %ah
		cmp $0x4, %ah
		ja .Lcf
.Lcc:		inc %ebx
		jmp .Lb4
.Lcf:		xor %ebp, %ebp
		cmp $0x2d, %al
		je .Le6
		cmp $0x2b, %al
		je .Le7
		jmp .Le8
.Le6:		inc %ebp
.Le7:		inc %ebx
.Le8:		or $0xffffffff, %eax
		xor %edi, %edi
		xor %esi, %esi
		fldz 
		xor %edx, %edx
.Lf3:		mov (%ebx), %dl
		sub $0x30, %dl
		cmp $0x9, %dl
		ja .L131
		test %eax, %eax
		jge .L10a
		inc %eax
.L10a:		test %eax, %eax
		jne .L11a
		test %dl, %dl
		je .L12e
.L11a:		inc %eax
		cmp $0x15, %eax
		jg .L12e
		mov %edx, (%esp)
		fmuls 0x4(%esp)
		fiaddl (%esp)
.L12e:		inc %ebx
		jmp .Lf3
.L131:		cmp $0xfe, %dl
		jne .L147
		test %esi, %esi
		jne .L147
		inc %ebx
		mov %ebx, %esi
		jmp .Lf3
.L147:		test %eax, %eax
		jge .L1ad
		test %esi, %esi
		jne .L1a4
		xor %ecx, %ecx
		mov %esi, (%esp)
		mov $nan_inf_str, %esi
.L161:		mov %ebx, %edx
		mov %esi, %eax
		lea 0x1(%esi), %eax
.L168:		mov (%edx), %cl
		or $0x20, %cl
		cmp (%eax), %cl
		jne .L199
		inc %edx
		inc %eax
		cmp %ch, (%eax)
		jne .L168
		fstp %st(0)
		fildl (%esp)
		fldz 
		fdivrp %st, %st(1)
		test %ebp, %ebp
		je .L18e
		fchs 
.L18e:		mov (%esi), %cl
		add %ecx, %ebx
		dec %ebx
		dec %ebx
		jmp .L1fd
.L199:		mov (%esi), %cl
		add %ecx, %esi
		incb (%esp)
		cmp %ch, %cl
		jne .L161
.L1a4:		mov 0x20(%esp), %ebx
		jmp .L1fd
.L1ad:		cmp $0x15, %eax
		jle .L1bb
		sub $0x15, %eax
		add %eax, %edi
.L1bb:		test %esi, %esi
		je .L1c9
		mov %esi, %eax
		sub %ebx, %eax
		add %eax, %edi
.L1c9:		test %ebp, %ebp
		je .L1d3
		fchs 
.L1d3:		mov (%ebx), %al
		or $0x20, %al
		cmp $0x65, %al
		jne .L254
		mov %ebx, (%esp)
		xor %esi, %esi
		inc %esi
		inc %ebx
		mov (%ebx), %al
		cmp $0x2d, %al
		je .L21a
		cmp $0x2b, %al
		je .L21c
		jmp .L21d
.L1fd:		mov 0x24(%esp), %eax
		test %eax, %eax
		je .L20b
		mov %ebx, (%eax)
.L20b:		mov 0x1c(%esp), %eax
		fstpt (%eax)
		pop %ebp
		pop %ebp
		pop %ebp
		pop %edi
		pop %esi
		pop %ebx
		ret $0x4
.L21a:		neg %esi
.L21c:		inc %ebx
.L21d:		mov %ebx, %ebp
		xor %eax, %eax
		xor %edx, %edx
.L223:		mov (%ebx), %dl
		sub $0x30, %dl
		cmp $0x9, %dl
		ja .L244
		cmp $0x136d, %eax
		jge .L241
		imul $0xa, %eax, %eax
		add %edx, %eax
.L241:		inc %ebx
		jmp .L223
.L244:		cmp %ebp, %ebx
		jne .L24f
		mov (%esp), %ebx
.L24f:		imul %esi, %eax
		add %eax, %edi
.L254:		fldz 
		fucomp %st(1)
		fnstsw %ax
		sahf 
		je .L1fd
		mov %edi, %eax
		test %eax, %eax
		je .L1fd
		jge .L26b
		neg %eax
.L26b:		flds 0x4(%esp)
.L26f:		test $0x1, %al
		je .L288
		test %edi, %edi
		jge .L286
		fdivr %st, %st(1)
		jmp .L288
.L286:		fmul %st, %st(1)
.L288:		fmul %st, %st(0)
		shr %eax
		jne .L26f
		fstp %st(0)
		jmp .L1fd

.global ld96_iszero
ld96_iszero:
		fldt 0x4(%esp)
		fldz
		xor %ecx, %ecx
		fucomp %st(1)
		fnstsw %ax
		sahf
		fstp %st(0)
		setnp %al
		sete %cl
		and %ecx, %eax
		ret

.global ld96_neg
ld96_neg:
		mov 0x4(%esp), %eax
		fldt 0x8(%esp)
		fchs
		fstpt (%eax)
		ret $0x4

.global ld96_add
ld96_add:
		mov 0x4(%esp), %eax
		fldt 0x8(%esp)
		fldt 0x14(%esp)
		faddp %st, %st(1)
		fstpt (%eax)
		ret $0x4

.global ld96_sub
ld96_sub:
		mov 0x4(%esp), %eax
		fldt 0x8(%esp)
		fldt 0x14(%esp)
		fsubrp %st, %st(1)
		fstpt (%eax)
		ret $0x4

.global ld96_mul
ld96_mul:
		mov 0x4(%esp), %eax
		fldt 0x8(%esp)
		fldt 0x14(%esp)
		fmulp %st, %st(1)
		fstpt (%eax)
		ret $0x4

.global ld96_div
ld96_div:
		mov 0x4(%esp), %eax
		fldt 0x8(%esp)
		fldt 0x14(%esp)
		fdivrp %st, %st(1)
		fstpt (%eax)
		ret $0x4

.global ld96_eq
ld96_eq:
		fldt 0x4(%esp)
		fldt 0x10(%esp)
		fxch %st(1)
		xor %ecx, %ecx
		fucomp %st(1)
		fnstsw %ax
		sahf
		fstp %st(0)
		setnp %al
		sete %cl
		and %ecx, %eax
		ret

.global ld96_lt
ld96_lt:
		fldt 0x4(%esp)
		fldt 0x10(%esp)
		fucomp %st(1)
		fnstsw %ax
		sahf
		fstp %st(0)
		seta %al
		movzbl %al, %eax
		ret

.section .rodata
nan_inf_str:	.string "\005nan\0\010infinity\0\5inf\0"
