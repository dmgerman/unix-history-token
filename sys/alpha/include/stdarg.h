begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: stdarg.h,v 1.1 1998/01/10 22:09:53 jb Exp $ */
end_comment

begin_comment
comment|/* From: NetBSD: stdarg.h,v 1.7 1997/04/06 08:47:44 cgd Exp */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stdarg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_STDARG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_STDARG_H_
end_define

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__lint__
end_ifdef

begin_define
define|#
directive|define
name|__builtin_saveregs
parameter_list|()
value|(0)
end_define

begin_define
define|#
directive|define
name|__builtin_classify_type
parameter_list|(
name|t
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|_BSD_VA_LIST_
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__va_size
parameter_list|(
name|type
parameter_list|)
define|\
value|(((sizeof(type) + sizeof(long) - 1) / sizeof(long)) * sizeof(long))
end_define

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
value|(__builtin_next_arg(last), (ap) = *(va_list *)__builtin_saveregs(), (ap).__pad = 0)
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
name|__va_arg_offset
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
define|\
value|((__builtin_classify_type(*(type *)0) == __REAL_TYPE_CLASS&&	\ 	    (ap).__offset<= (6 * 8) ? -(6 * 8) : 0) - __va_size(type))
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
value|(*(type *)((ap).__offset += __va_size(type),			\ 		   (ap).__base + (ap).__offset + __va_arg_offset(ap, type)))
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ALPHA_STDARG_H_ */
end_comment

end_unit

