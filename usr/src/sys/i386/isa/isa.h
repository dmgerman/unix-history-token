begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)isa.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * AT bus specific definitions.  */
end_comment

begin_define
define|#
directive|define
name|Rd
parameter_list|(
name|s
parameter_list|)
value|({u_char rtn; u_short ioa; \ 	ioa = (s); \ 	asm volatile ("movw %1,%%dx; nop ; in %%dx,%%al ; nop ; movb %%al,%0" \ 		: "=g" (rtn) \ 		: "g" (ioa) \ 		: "ax", "dx"); \ 	rtn; \ })
end_define

begin_define
define|#
directive|define
name|Wr
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|({u_char val; u_short ioa; \ 	ioa = (s); \ 	val = (n); \ 	asm volatile ("movb %1,%%al; movw %0,%%dx; nop; out %%al,%%dx ; nop" \ 		:
comment|/* nothing returned */
value|\ 		: "g" (ioa), "g" (val) \ 		: "ax", "dx"); \ })
end_define

begin_define
define|#
directive|define
name|rdw
parameter_list|(
name|s
parameter_list|)
value|({u_short rtn; u_short ioa; \ 	ioa = (s); \ 	asm volatile ("movw %1,%%dx; nop ; in %%dx,%%ax ; nop ; movw %%ax,%0" \ 		: "=g" (rtn) \ 		: "g" (ioa) \ 		: "ax", "dx"); \ 	rtn; \ })
end_define

begin_define
define|#
directive|define
name|wrw
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|({u_short val; u_short ioa; \ 	ioa = (s); \ 	val = (n); \ 	asm volatile ("movw %1,%%ax; movw %0,%%dx; nop;  out %%ax,%%dx; nop" \ 		:
comment|/* nothing returned */
value|\ 		: "g" (ioa), "g" (val) \ 		: "ax", "dx"); \ })
end_define

begin_define
define|#
directive|define
name|Outsw
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|n
parameter_list|)
value|({short *addr; u_short ioa; int cnt,rtn; \ 	ioa = (s); \ 	addr = (a); \ 	cnt = (n); \ 	asm volatile ("movw %1,%%dx; movl %2,%%esi; movl %3,%%ecx; cld; nop; .byte 0x66,0xf2,0x6f; nop ; movl %%esi,%0" \ 		: "=g" (rtn) \ 		: "g" (ioa), "g" (addr), "g" (cnt) \ 		: "si", "dx", "cx"); \ 	rtn; \ })
end_define

begin_define
define|#
directive|define
name|Insw
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|n
parameter_list|)
value|({short  *addr; u_short ioa; int cnt,rtn; \ 	ioa = (s); \ 	addr = (a); \ 	cnt = (n); \ 	asm volatile ("movw %1,%%dx; movl %2,%%edi; movl %3,%%ecx; cld; nop; .byte 0x66,0xf2,0x6d; nop ; movl %%edi,%0" \ 		: "=g" (rtn) \ 		: "g" (ioa), "g" (addr), "g" (cnt)  \ 		: "di", "dx", "cx"); \ 	rtn; \ })
end_define

begin_function_decl
name|unsigned
name|char
name|inb
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern outb(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|IO_KBD1
value|0x60
end_define

begin_comment
comment|/* keyboard */
end_comment

begin_define
define|#
directive|define
name|IO_WD0
value|0x1f0
end_define

begin_comment
comment|/* primary base i/o address */
end_comment

begin_define
define|#
directive|define
name|IO_WD1
value|0x170
end_define

begin_comment
comment|/* secondary base i/o address */
end_comment

end_unit

