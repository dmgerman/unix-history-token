begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 David E. O'Brien.  All rights reserved.  * Copyright (c) 2000 Tsubai Masanari.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: stdarg.h,v 1.5 2000/02/27 17:50:21 tsubai Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_STDARG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_STDARG_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUCLIKE_BUILTIN_STDARG
argument_list|)
end_if

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|last
parameter_list|)
define|\
value|__builtin_stdarg_start((ap), (last))
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
define|\
value|__builtin_va_arg((ap), type)
end_define

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_define
define|#
directive|define
name|va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|__builtin_va_copy((dest), (src))
end_define

begin_define
define|#
directive|define
name|__va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|va_copy((dest), (src))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
define|\
value|__builtin_va_end(ap)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUCLIKE_BUILTIN_STDARG */
end_comment

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
parameter_list|,
name|last
parameter_list|)
value|((ap) = *(va_list *)0)
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
value|(*(type *)(void *)&(ap))
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC_VA_LIST_COMPATIBILITY
argument_list|)
end_if

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|last
parameter_list|)
define|\
value|(__builtin_next_arg(last),					\ 	 __builtin_memcpy((void *)&(ap), __builtin_saveregs (),		\ 	 sizeof(__gnuc_va_list)))
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
parameter_list|,
name|last
parameter_list|)
define|\
value|(__builtin_next_arg(last),					\ 	 (ap).__stack = __va_stack_args,				\ 	 (ap).__base = __va_reg_args,					\ 	 (ap).__gpr = __va_first_gpr,					\ 	 (ap).__fpr = __va_first_fpr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__va_first_gpr
value|(__builtin_args_info(0))
end_define

begin_define
define|#
directive|define
name|__va_first_fpr
value|(__builtin_args_info(1) - 32 - 1)
end_define

begin_define
define|#
directive|define
name|__va_stack_args
define|\
value|((char *)__builtin_saveregs() +					\ 	 (__va_first_gpr>= 8 ? __va_first_gpr - 8 : 0) * sizeof(int))
end_define

begin_define
define|#
directive|define
name|__va_reg_args
define|\
value|((char *)__builtin_frame_address(0) + __builtin_args_info(4))
end_define

begin_define
define|#
directive|define
name|__INTEGER_TYPE_CLASS
value|1
end_define

begin_define
define|#
directive|define
name|__REAL_TYPE_CLASS
value|8
end_define

begin_define
define|#
directive|define
name|__RECORD_TYPE_CLASS
value|12
end_define

begin_define
define|#
directive|define
name|__va_longlong
parameter_list|(
name|type
parameter_list|)
define|\
value|(__builtin_classify_type(*(type *)0) == __INTEGER_TYPE_CLASS&&	\ 	 sizeof(type) == 8)
end_define

begin_define
define|#
directive|define
name|__va_double
parameter_list|(
name|type
parameter_list|)
define|\
value|(__builtin_classify_type(*(type *)0) == __REAL_TYPE_CLASS)
end_define

begin_define
define|#
directive|define
name|__va_struct
parameter_list|(
name|type
parameter_list|)
define|\
value|(__builtin_classify_type(*(type *)0)>= __RECORD_TYPE_CLASS)
end_define

begin_define
define|#
directive|define
name|__va_size
parameter_list|(
name|type
parameter_list|)
define|\
value|((sizeof(type) + sizeof(int) - 1) / sizeof(int) * sizeof(int))
end_define

begin_define
define|#
directive|define
name|__va_savedgpr
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|((ap).__base + (ap).__gpr * sizeof(int) - sizeof(type))
end_define

begin_define
define|#
directive|define
name|__va_savedfpr
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|((ap).__base + 8 * sizeof(int) + (ap).__fpr * sizeof(double) -	\ 	 sizeof(type))
end_define

begin_define
define|#
directive|define
name|__va_stack
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|((ap).__stack += __va_size(type) +				\ 			(__va_longlong(type) ? (int)(ap).__stack& 4 : 0), \ 	 (ap).__stack - sizeof(type))
end_define

begin_define
define|#
directive|define
name|__va_gpr
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|((ap).__gpr += __va_size(type) / sizeof(int) +			\ 		      (__va_longlong(type) ? (ap).__gpr& 1 : 0),	\ 	 (ap).__gpr<= 8 ? __va_savedgpr(ap, type) : __va_stack(ap, type))
end_define

begin_define
define|#
directive|define
name|__va_fpr
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|((ap).__fpr++,							\ 	 (ap).__fpr<= 8 ? __va_savedfpr(ap, type) : __va_stack(ap, type))
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
define|\
value|(*(type *)(__va_struct(type) ? (*(void **)__va_gpr(ap, void *)) : \ 		   __va_double(type) ? __va_fpr(ap, type) :		\ 		   __va_gpr(ap, type)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __lint__ */
end_comment

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
end_define

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_XOPEN_SOURCE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|_ISOC99_SOURCE
argument_list|)
operator|||
operator|(
name|__STDC_VERSION__
operator|-
literal|0
operator|)
operator|>=
literal|199901L
operator|)
end_if

begin_define
define|#
directive|define
name|va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|((dest) = (src))
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
comment|/* __GNUCLIKE_BUILTIN_STDARG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_STDARG_H_ */
end_comment

end_unit

