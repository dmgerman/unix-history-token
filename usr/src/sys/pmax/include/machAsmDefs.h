begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)machAsmDefs.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * machAsmDefs.h --  *  *	Macros used when writing assembler programs.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  * from: $Header: /sprite/src/kernel/mach/ds3100.md/RCS/machAsmDefs.h,  *	v 1.2 89/08/15 18:28:24 rab Exp $ SPRITE (DECWRL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHASMDEFS
end_ifndef

begin_define
define|#
directive|define
name|_MACHASMDEFS
end_define

begin_include
include|#
directive|include
file|<machine/regdef.h>
end_include

begin_comment
comment|/*  * Define -pg profile entry code.  */
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
name|MCOUNT
value|.set noreorder; \ 		.set noat; \ 		move $1,$31; \ 		jal _mcount; \ 		subu sp,sp,8; \ 		.set reorder; \ 		.set at;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * LEAF(x)  *  *	Declare a leaf routine.  */
end_comment

begin_define
define|#
directive|define
name|LEAF
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl x; \ 	.ent x, 0; \ x: ; \ 	.frame sp, 0, ra; \ 	MCOUNT
end_define

begin_comment
comment|/*  * NLEAF(x)  *  *	Declare a non-profiled leaf routine.  */
end_comment

begin_define
define|#
directive|define
name|NLEAF
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl x; \ 	.ent x, 0; \ x: ; \ 	.frame sp, 0, ra
end_define

begin_comment
comment|/*  * ALEAF -- declare alternate entry to a leaf routine.  */
end_comment

begin_define
define|#
directive|define
name|ALEAF
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl	x;					\ 	.aent	x,0;					\ x:
end_define

begin_comment
comment|/*  * NON_LEAF(x)  *  *	Declare a non-leaf routine (a routine that makes other C calls).  */
end_comment

begin_define
define|#
directive|define
name|NON_LEAF
parameter_list|(
name|x
parameter_list|,
name|fsize
parameter_list|,
name|retpc
parameter_list|)
define|\
value|.globl x; \ 	.ent x, 0; \ x: ; \ 	.frame sp, fsize, retpc; \ 	MCOUNT
end_define

begin_comment
comment|/*  * NNON_LEAF(x)  *  *	Declare a non-profiled non-leaf routine  *	(a routine that makes other C calls).  */
end_comment

begin_define
define|#
directive|define
name|NNON_LEAF
parameter_list|(
name|x
parameter_list|,
name|fsize
parameter_list|,
name|retpc
parameter_list|)
define|\
value|.globl x; \ 	.ent x, 0; \ x: ; \ 	.frame sp, fsize, retpc
end_define

begin_comment
comment|/*  * END(x)  *  *	Mark end of a procedure.  */
end_comment

begin_define
define|#
directive|define
name|END
parameter_list|(
name|x
parameter_list|)
define|\
value|.end x
end_define

begin_define
define|#
directive|define
name|STAND_FRAME_SIZE
value|24
end_define

begin_define
define|#
directive|define
name|STAND_RA_OFFSET
value|20
end_define

begin_comment
comment|/*  * Macros to panic and printf from assembly language.  */
end_comment

begin_define
define|#
directive|define
name|PANIC
parameter_list|(
name|msg
parameter_list|)
define|\
value|la	a0, 9f; \ 	jal	panic; \ 	MSG(msg)
end_define

begin_define
define|#
directive|define
name|PRINTF
parameter_list|(
name|msg
parameter_list|)
define|\
value|la	a0, 9f; \ 	jal	printf; \ 	MSG(msg)
end_define

begin_define
define|#
directive|define
name|MSG
parameter_list|(
name|msg
parameter_list|)
define|\
value|.rdata; \ 9:	.asciiz	msg; \ 	.text
end_define

begin_define
define|#
directive|define
name|ASMSTR
parameter_list|(
name|str
parameter_list|)
define|\
value|.asciiz str; \ 	.align	2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHASMDEFS */
end_comment

end_unit

