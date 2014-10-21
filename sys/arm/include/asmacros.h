begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Olivier Houchard<cognet@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASMACROS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASMACROS_H_
end_define

begin_include
include|#
directive|include
file|<machine/asm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_include
include|#
directive|include
file|"opt_global.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_ARM_ARCH_6
end_ifdef

begin_define
define|#
directive|define
name|GET_CURTHREAD_PTR
parameter_list|(
name|tmp
parameter_list|)
define|\
value|mrc	p15, 0, tmp, c13, c0, 4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_CURTHREAD_PTR
parameter_list|(
name|tmp
parameter_list|)
define|\
value|ldr	tmp, =_C_LABEL(__pcpu);\ 	ldr	tmp, [tmp, #PC_CURTHREAD]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ELFNOTE
parameter_list|(
name|section
parameter_list|,
name|type
parameter_list|,
name|vendor
parameter_list|,
name|desctype
parameter_list|,
name|descdata
modifier|...
parameter_list|)
define|\
value|.pushsection section					; \ 	    .balign 4						; \ 	    .long 2f - 1f
comment|/* namesz */
value|; \ 	    .long 4f - 3f
comment|/* descsz */
value|; \ 	    .long type
comment|/* type */
value|; \ 	    1: .asciz vendor
comment|/* vendor name */
value|; \ 	    2: .balign 4					; \ 	    3:  desctype descdata
comment|/* node */
value|; \ 	    4: .balign 4					; \ 	.popsection
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASMACROS_H_ */
end_comment

end_unit

