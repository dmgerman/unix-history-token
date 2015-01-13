begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 The FreeBSD Foundation.  * All rights reserved.  *  * Portions of this software were developed by Konstantin Belousov  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible  *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/syscall.h>
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

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sys_read
argument_list|,
name|__read
argument_list|)
expr_stmt|;
end_expr_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|read
end_pragma

begin_function
name|ssize_t
name|read
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|ssize_t
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|,
name|void
operator|*
argument_list|,
name|size_t
argument_list|)
operator|)
name|__libc_interposing
index|[
name|INTERPOS_read
index|]
operator|)
operator|(
name|fd
operator|,
name|buf
operator|,
name|nbytes
operator|)
operator|)
return|;
block|}
end_function

end_unit

