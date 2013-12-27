begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 David E. O'Brien.  All rights reserved.  * Copyright (c) 2000 Tsubai Masanari.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   *	$NetBSD: varargs.h,v 1.5 2000/02/27 17:50:22 tsubai Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VARARGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_VARARGS_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUCLIKE_BUILTIN_VARARGS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_DECLARED
end_define

begin_typedef
typedef|typedef
name|__va_list
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|__builtin_va_alist_t
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__word__
typedef|)));
end_typedef

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_define
define|#
directive|define
name|va_dcl
value|__builtin_va_alist_t __builtin_va_alist; ...
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|)
value|__builtin_varargs_start(ap)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
value|__builtin_va_arg((ap), type)
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|__builtin_va_end(ap)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !  __GNUCLIKE_BUILTIN_VARARGS */
end_comment

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUCLIKE_BUILTIN_VAALIST
end_ifdef

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_define
define|#
directive|define
name|va_dcl
value|int __builtin_va_alist; ...
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|this file needs to be ported to your compiler
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|va_start
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__lint__
end_ifdef

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|)
value|((ap) = *(va_list *)0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|)
define|\
value|((ap).__stack = __va_stack_args,				\ 	 (ap).__base = __va_reg_args,					\ 	 (ap).__gpr = __va_first_gpr,					\ 	 (ap).__fpr = __va_first_fpr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUCLIKE_BUILTIN_VARARGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_VARARGS_H_ */
end_comment

end_unit

