begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)DEFS.h	5.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Macros used to define entry points  * in assembly language routines.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GPROF
argument_list|)
operator|||
name|defined
argument_list|(
name|PROF
argument_list|)
end_if

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl _
comment|/**/
value|name; .align 2; _
comment|/**/
value|name: .word regs; \ 	.data; .align 2; 1: .long 0; .text; \ 	pushal 1b; callf $8,mcount;
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|name
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl name; .align 2; name: .word regs; \ 	.data; .align 2; 1: .long 0; .text; \ 	pushal 1b; callf $8,mcount;
end_define

begin_define
define|#
directive|define
name|XENTRY
parameter_list|(
name|name
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl _
comment|/**/
value|name; .globl X
comment|/**/
value|name; .align 2; \ 	_
comment|/**/
value|name: X
comment|/**/
value|name: .word regs; \ 	.data; .align 2; 1: .long 0; .text; \ 	pushal 1b; callf $8,mcount
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|name
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl _
comment|/**/
value|name; .align 2; _
comment|/**/
value|name: .word regs
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|name
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl name; .align 2; name: .word regs
end_define

begin_define
define|#
directive|define
name|XENTRY
parameter_list|(
name|name
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl _
comment|/**/
value|name; .globl X
comment|/**/
value|name; .align 2; \ 	_
comment|/**/
value|name: X
comment|/**/
value|name: .word regs;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|R0
value|0x0001
end_define

begin_define
define|#
directive|define
name|R1
value|0x0002
end_define

begin_define
define|#
directive|define
name|R2
value|0x0004
end_define

begin_define
define|#
directive|define
name|R3
value|0x0008
end_define

begin_define
define|#
directive|define
name|R4
value|0x0010
end_define

begin_define
define|#
directive|define
name|R5
value|0x0020
end_define

begin_define
define|#
directive|define
name|R6
value|0x0040
end_define

begin_define
define|#
directive|define
name|R7
value|0x0080
end_define

begin_define
define|#
directive|define
name|R8
value|0x0100
end_define

begin_define
define|#
directive|define
name|R9
value|0x0200
end_define

begin_define
define|#
directive|define
name|R10
value|0x0400
end_define

begin_define
define|#
directive|define
name|R11
value|0x0800
end_define

begin_define
define|#
directive|define
name|R12
value|0x1000
end_define

end_unit

