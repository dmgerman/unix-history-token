begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: asm.h,v 1.6.18.1 2000/07/25 08:37:14 kleink Exp $  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_define
define|#
directive|define
name|PIC_PROLOGUE
value|XXX
end_define

begin_define
define|#
directive|define
name|PIC_EPILOGUE
value|XXX
end_define

begin_define
define|#
directive|define
name|PIC_PLT
parameter_list|(
name|x
parameter_list|)
value|x@plt
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PIC_GOT
parameter_list|(
name|x
parameter_list|)
value|XXX
end_define

begin_define
define|#
directive|define
name|PIC_GOTOFF
parameter_list|(
name|x
parameter_list|)
value|XXX
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_define
define|#
directive|define
name|PIC_GOT
parameter_list|(
name|x
parameter_list|)
value|XXX
end_define

begin_define
define|#
directive|define
name|PIC_GOTOFF
parameter_list|(
name|x
parameter_list|)
value|XXX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PIC_PROLOGUE
end_define

begin_define
define|#
directive|define
name|PIC_EPILOGUE
end_define

begin_define
define|#
directive|define
name|PIC_PLT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|PIC_GOT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|PIC_GOTOFF
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_C_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|_ASM_LABEL
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|_GLOBAL
parameter_list|(
name|x
parameter_list|)
define|\
value|.data; .align 2; .globl x; x:
end_define

begin_define
define|#
directive|define
name|_ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.text; .align 2; .globl x; .type x,@function; x:
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
value|mflr 0; stw 0,4(1); bl _mcount
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
name|ASENTRY
parameter_list|(
name|y
parameter_list|)
value|_ENTRY(_ASM_LABEL(y)); _PROF_PROLOGUE
end_define

begin_define
define|#
directive|define
name|GLOBAL
parameter_list|(
name|y
parameter_list|)
value|_GLOBAL(_C_LABEL(y))
end_define

begin_define
define|#
directive|define
name|ASMSTR
value|.asciz
end_define

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|x
parameter_list|)
value|.text; .asciz x
end_define

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
value|.weak alias;						\ 	alias = sym
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
name|_sym
parameter_list|,
name|_msg
parameter_list|)
define|\
value|.section .gnu.warning. ## _sym ; .ascii _msg ; .text
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
name|_sym
parameter_list|,
name|_msg
parameter_list|)
define|\
value|.section .gnu.warning.
comment|/**/
value|_sym ; .ascii _msg ; .text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASM_H_ */
end_comment

end_unit

