begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)varargs.h	8.2 (Berkeley) 3/22/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VARARGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VARARGS_H_
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
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
value|(((sizeof(type) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|va_alist
value|__builtin_va_alist
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|1
end_if

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist; ...
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_dcl
value|int va_alist;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|)
define|\
value|((ap) = (va_list)&va_alist)
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
value|(*(type *)((ap) += __va_size(type), (ap) - __va_size(type)))
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VARARGS_H_ */
end_comment

end_unit

