begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)time.h	8.3 (Berkeley) 1/21/94  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TIMECONV_H_
end_ifndef

begin_define
define|#
directive|define
name|_TIMECONV_H_
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
name|_TIME_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__time_t
name|time_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_TIME_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|time_t
name|_time32_to_time
parameter_list|(
name|__int32_t
name|t32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__int32_t
name|_time_to_time32
parameter_list|(
name|time_t
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|_time64_to_time
parameter_list|(
name|__int64_t
name|t64
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__int64_t
name|_time_to_time64
parameter_list|(
name|time_t
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|_time_to_long
parameter_list|(
name|time_t
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|_long_to_time
parameter_list|(
name|long
name|tlong
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_time_to_int
parameter_list|(
name|time_t
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|_int_to_time
parameter_list|(
name|int
name|tint
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TIMECONV_H_ */
end_comment

end_unit

