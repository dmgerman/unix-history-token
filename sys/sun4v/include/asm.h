begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)DEFS.h	5.1 (Berkeley) 4/23/90  *	from: FreeBSD: src/sys/i386/include/asm.h,v 1.7 2000/01/25  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASM_H_
end_define

begin_define
define|#
directive|define
name|__ASM__
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_define
define|#
directive|define
name|PIC_PROLOGUE
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|)
define|\
value|sethi	%hi(_GLOBAL_OFFSET_TABLE_-4), r1 ; \ 	rd	%pc, r2 ; \ 	or	r1, %lo(_GLOBAL_OFFSET_TABLE_+4), r1 ; \ 	add	r2, r1, r2
end_define

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|name
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|)
define|\
value|set	name, r2 ; \ 	ldx	[r1 + r2], r2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIC_PROLOGUE
parameter_list|(
name|r1
parameter_list|,
name|r2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|name
parameter_list|,
name|r1
parameter_list|,
name|r2
parameter_list|)
define|\
value|set	name, r2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CNAME and HIDENAME manage the relationship between symbol names in C  * and the equivalent assembly language names.  CNAME is given a name as  * it would be used in a C program.  It expands to the equivalent assembly  * language name.  HIDENAME is given an assembly-language name, and expands  * to a possibly-modified form that will be invisible to C programs.  */
end_comment

begin_define
define|#
directive|define
name|CNAME
parameter_list|(
name|csym
parameter_list|)
value|csym
end_define

begin_define
define|#
directive|define
name|HIDENAME
parameter_list|(
name|asmsym
parameter_list|)
value|__CONCAT(.,asmsym)
end_define

begin_define
define|#
directive|define
name|CCFSZ
value|192
end_define

begin_define
define|#
directive|define
name|SPOFF
value|2047
end_define

begin_define
define|#
directive|define
name|_ALIGN_TEXT
value|.align 32
end_define

begin_define
define|#
directive|define
name|_START_ENTRY
define|\
value|.text ; \ 	_ALIGN_TEXT
end_define

begin_comment
comment|/*  * Define a function entry point.  *  * The compiler produces #function for the .type pseudo-op, but the '#'  * character has special meaning in cpp macros, so we use @function like  * other architectures.  The assembler seems to accept both.  * The assembler also accepts a .proc pseudo-op, which is used by the  * peep hole optimizer, whose argument is the type code of the return  * value.  Since this is difficult to predict and its expected that  * assembler code is already optimized, we leave it out.  */
end_comment

begin_define
define|#
directive|define
name|_ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|_START_ENTRY ; \ 	.globl	CNAME(x) ; \ 	.type	CNAME(x),@function ; \ CNAME(x):
end_define

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|_ENTRY(x)
end_define

begin_define
define|#
directive|define
name|END
parameter_list|(
name|x
parameter_list|)
value|.size x, . - x
end_define

begin_define
define|#
directive|define
name|STACK_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|SA
parameter_list|(
name|X
parameter_list|)
value|(((X)+(STACK_ALIGN-1))& ~(STACK_ALIGN-1))
end_define

begin_define
define|#
directive|define
name|WINDOWSIZE64
value|(16*8)
end_define

begin_define
define|#
directive|define
name|MINFRAME64
value|(WINDOWSIZE64 + 64)
end_define

begin_define
define|#
directive|define
name|MINFRAME
value|MINFRAME64
end_define

begin_define
define|#
directive|define
name|REGOFF
value|SA(MINFRAME)
end_define

begin_comment
comment|/*  * Kernel RCS ID tag and copyright macros  */
end_comment

begin_undef
undef|#
directive|undef
name|__FBSDID
end_undef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRIP_FBSDID
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
value|.ident s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint and not STRIP_FBSDID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASM_H_ */
end_comment

end_unit

