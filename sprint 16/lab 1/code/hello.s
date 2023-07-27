
hello:	file format mach-o 64-bit x86-64

Disassembly of section __TEXT,__text:

0000000100003f40 <_main>:
100003f40: 55                          	pushq	%rbp
100003f41: 48 89 e5                    	movq	%rsp, %rbp
100003f44: 48 8d 3d 35 00 00 00        	leaq	53(%rip), %rdi          ## 0x100003f80 <_puts+0x100003f80>
100003f4b: e8 2a 00 00 00              	callq	0x100003f7a <_puts+0x100003f7a>
100003f50: 31 c0                       	xorl	%eax, %eax
100003f52: e8 09 00 00 00              	callq	0x100003f60 <_print_hello>
100003f57: 31 c0                       	xorl	%eax, %eax
100003f59: 5d                          	popq	%rbp
100003f5a: c3                          	retq
100003f5b: 90                          	nop
100003f5c: 90                          	nop
100003f5d: 90                          	nop
100003f5e: 90                          	nop
100003f5f: 90                          	nop

0000000100003f60 <_print_hello>:
100003f60: 55                          	pushq	%rbp
100003f61: 48 89 e5                    	movq	%rsp, %rbp
100003f64: 48 8d 3d 2c 00 00 00        	leaq	44(%rip), %rdi          ## 0x100003f97 <_puts+0x100003f97>
100003f6b: 31 c0                       	xorl	%eax, %eax
100003f6d: e8 02 00 00 00              	callq	0x100003f74 <_puts+0x100003f74>
100003f72: 5d                          	popq	%rbp
100003f73: c3                          	retq

Disassembly of section __TEXT,__stubs:

0000000100003f74 <__stubs>:
100003f74: ff 25 86 00 00 00           	jmpq	*134(%rip)              ## 0x100004000 <_puts+0x100004000>
100003f7a: ff 25 88 00 00 00           	jmpq	*136(%rip)              ## 0x100004008 <_puts+0x100004008>
