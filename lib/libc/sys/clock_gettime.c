begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2012 Konstantin Belousov<kib@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/vdso.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_function_decl
name|int
name|__clock_gettime
parameter_list|(
name|clockid_t
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__clock_gettime
argument_list|,
name|clock_gettime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|__clock_gettime
parameter_list|(
name|clockid_t
name|clock_id
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|__vdso_clock_gettime
operator|!=
name|NULL
operator|&&
name|__vdso_gettc
operator|!=
name|NULL
condition|)
name|error
operator|=
name|__vdso_clock_gettime
argument_list|(
name|clock_id
argument_list|,
name|ts
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
name|ENOSYS
expr_stmt|;
if|if
condition|(
name|error
operator|==
name|ENOSYS
condition|)
name|error
operator|=
name|__sys_clock_gettime
argument_list|(
name|clock_id
argument_list|,
name|ts
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

end_unit

