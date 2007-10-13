begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: asm.h,v 1.5 2003/08/07 16:26:53 agc Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)asm.h	5.5 (Berkeley) 5/7/91  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|_ ## x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|_
comment|/**/
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_ASM_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_JB_MAGIC__SETJMP
end_ifndef

begin_define
define|#
directive|define
name|_JB_MAGIC__SETJMP
value|0x4278f500
end_define

begin_define
define|#
directive|define
name|_JB_MAGIC_SETJMP
value|0x4278f501
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|I32_bit
value|(1<< 7)
end_define

begin_comment
comment|/* IRQ disable */
end_comment

begin_define
define|#
directive|define
name|F32_bit
value|(1<< 6)
end_define

begin_comment
comment|/* FIQ disable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_32BP_ENABLE
value|0x00000010
end_define

begin_comment
comment|/* P: 32-bit exception handlers */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_32BD_ENABLE
value|0x00000020
end_define

begin_comment
comment|/* D: 32-bit addressing */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGN_TEXT
end_ifndef

begin_define
define|#
directive|define
name|_ALIGN_TEXT
value|.align 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * gas/arm uses @ as a single comment character and thus cannot be used here  * Instead it recognised the # instead of an @ symbols in .type directives  * We define a couple of macros so that assembly code will not be dependant  * on one or the other.  */
end_comment

begin_define
define|#
directive|define
name|_ASM_TYPE_FUNCTION
value|#function
end_define

begin_define
define|#
directive|define
name|_ASM_TYPE_OBJECT
value|#object
end_define

begin_define
define|#
directive|define
name|GLOBAL
parameter_list|(
name|X
parameter_list|)
value|.globl x
end_define

begin_define
define|#
directive|define
name|_ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.text; _ALIGN_TEXT; .globl x; .type x,_ASM_TYPE_FUNCTION; x:
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_define
define|#
directive|define
name|_PROF_PROLOGUE
define|\
value|mov ip, lr; bl __mcount
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PROF_PROLOGUE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(_C_LABEL(y)); _PROF_PROLOGUE
end_define

begin_define
define|#
directive|define
name|ENTRY_NP
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(_C_LABEL(y))
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(_ASM_LABEL(y)); _PROF_PROLOGUE
end_define

begin_define
define|#
directive|define
name|ASENTRY_NP
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(_ASM_LABEL(y))
end_define

begin_define
define|#
directive|define
name|ASMSTR
value|.asciz
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ELF__
argument_list|)
operator|&&
name|defined
argument_list|(
name|PIC
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PIC_SYM
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## ( ## y ## )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIC_SYM
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
comment|/**/
value|(
comment|/**/
value|y
comment|/**/
value|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIC_SYM
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|WEAK_ALIAS
parameter_list|(
name|alias
parameter_list|,
name|sym
parameter_list|)
define|\
value|.weak alias;							\ 	alias = sym
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|WARN_REFERENCES
parameter_list|(
name|sym
parameter_list|,
name|msg
parameter_list|)
define|\
value|.stabs msg ## ,30,0,0,0 ;					\ 	.stabs __STRING(_C_LABEL(sym)) ## ,1,0,0,0
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|WARN_REFERENCES
parameter_list|(
name|sym
parameter_list|,
name|msg
parameter_list|)
define|\
value|.stabs msg,30,0,0,0 ;						\ 	.stabs __STRING(sym),1,0,0,0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WARN_REFERENCES
parameter_list|(
name|sym
parameter_list|,
name|msg
parameter_list|)
define|\
value|.stabs msg,30,0,0,0 ;						\ 	.stabs __STRING(_
comment|/**/
value|sym),1,0,0,0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ARM_ARCH_6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ARM_ARCH_6
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_5T__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5TE__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_5TEJ__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5E__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ARM_ARCH_5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ARM_ARCH_6
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5TE__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_5TEJ__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5E__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ARM_ARCH_5E
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ARM_ARCH_5
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_4T__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_ARM_ARCH_4T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ARM_ARCH_4T
argument_list|)
end_if

begin_define
define|#
directive|define
name|RET
value|bx	lr
end_define

begin_define
define|#
directive|define
name|RETeq
value|bxeq	lr
end_define

begin_define
define|#
directive|define
name|RETne
value|bxne	lr
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RETc
parameter_list|(
name|c
parameter_list|)
value|bx##c	lr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RETc
parameter_list|(
name|c
parameter_list|)
value|bx
comment|/**/
value|c	lr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RET
value|mov	pc, lr
end_define

begin_define
define|#
directive|define
name|RETeq
value|moveq	pc, lr
end_define

begin_define
define|#
directive|define
name|RETne
value|movne	pc, lr
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RETc
parameter_list|(
name|c
parameter_list|)
value|mov##c	pc, lr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RETc
parameter_list|(
name|c
parameter_list|)
value|mov
comment|/**/
value|c	pc, lr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASM_H_ */
end_comment

end_unit

