begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)stdarg.h	8.2 (Berkeley) 9/27/93  *	from: NetBSD: stdarg.h,v 1.11 2000/07/23 21:36:56 mycroft Exp  * $FreeBSD$  */
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
file|<machine/ansi.h>
end_include

begin_typedef
typedef|typedef
name|_BSD_VA_LIST_
name|va_list
typedef|;
end_typedef

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
value|(__builtin_next_arg(last), (ap) = (va_list)__builtin_saveregs())
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__va_arg8
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|(*(type *)(void *)((ap) += 8, (ap) - 8))
end_define

begin_define
define|#
directive|define
name|__va_arg16
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|(*(type *)(void *)((ap) = (va_list)(((unsigned long)(ap) + 31)& -16),\ 			   (ap) - 16))
end_define

begin_define
define|#
directive|define
name|__va_int
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|(*(type *)(void *)((ap) += 8, (ap) - sizeof(type)))
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
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|(__builtin_classify_type(*(type *)0) == __REAL_TYPE_CLASS ?	\ 	 (__alignof__(type) == 16 ? __va_arg16(ap, type) :		\ 	  __va_arg8(ap, type)) :					\ 	 (__builtin_classify_type(*(type *)0)< __RECORD_TYPE_CLASS ?	\ 	  __va_int(ap, type) :						\ 	  (sizeof(type)<= 8 ? __va_arg8(ap, type) :			\ 	   (sizeof(type)<= 16 ? __va_arg16(ap, type) :			\ 	    *__va_arg8(ap, type *)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_STDARG_H_ */
end_comment

end_unit

