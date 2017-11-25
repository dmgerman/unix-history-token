begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2011 Xin Li<delphij@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_comment
comment|/*  * Whether we want to restrict dlopen()s.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|__libc_restricted_mode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|libc_dlopen
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
if|if
condition|(
name|__libc_restricted_mode
condition|)
block|{
name|_rtld_error
argument_list|(
literal|"Service unavailable -- libc in restricted mode"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
else|else
return|return
operator|(
name|dlopen
argument_list|(
name|path
argument_list|,
name|mode
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|__FreeBSD_libc_enter_restricted_mode
parameter_list|(
name|void
parameter_list|)
block|{
name|__libc_restricted_mode
operator|=
literal|1
expr_stmt|;
return|return;
block|}
end_function

end_unit

