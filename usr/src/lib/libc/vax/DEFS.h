begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)DEFS.h	5.3 (Berkeley) 6/1/90  */
end_comment

begin_define
define|#
directive|define
name|R0
value|0x001
end_define

begin_define
define|#
directive|define
name|R1
value|0x002
end_define

begin_define
define|#
directive|define
name|R2
value|0x004
end_define

begin_define
define|#
directive|define
name|R3
value|0x008
end_define

begin_define
define|#
directive|define
name|R4
value|0x010
end_define

begin_define
define|#
directive|define
name|R5
value|0x020
end_define

begin_define
define|#
directive|define
name|R6
value|0x040
end_define

begin_define
define|#
directive|define
name|R7
value|0x080
end_define

begin_define
define|#
directive|define
name|R8
value|0x100
end_define

begin_define
define|#
directive|define
name|R9
value|0x200
end_define

begin_define
define|#
directive|define
name|R10
value|0x400
end_define

begin_define
define|#
directive|define
name|R11
value|0x800
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl _
comment|/**/
value|x; .align 2; _
comment|/**/
value|x: .word regs; \ 	.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|x
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl x; .align 2; x: .word regs; \ 	.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
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
name|x
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl _
comment|/**/
value|x; .align 2; _
comment|/**/
value|x: .word regs
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|x
parameter_list|,
name|regs
parameter_list|)
define|\
value|.globl x; .align 2; x: .word regs
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

