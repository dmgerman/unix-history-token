begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Thomas Moestl  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"pthread_private.h"
end_include

begin_pragma
pragma|#
directive|pragma
name|weak
name|__acl_delete_fd
name|=
name|___acl_delete_fd
end_pragma

begin_function
name|int
name|___acl_delete_fd
parameter_list|(
name|int
name|fd
parameter_list|,
name|acl_type_t
name|tp
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
operator|(
name|error
operator|=
name|_FD_LOCK
argument_list|(
name|fd
argument_list|,
name|FD_WRITE
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
name|error
operator|=
name|__sys___acl_delete_fd
argument_list|(
name|fd
argument_list|,
name|tp
argument_list|)
expr_stmt|;
name|_FD_UNLOCK
argument_list|(
name|fd
argument_list|,
name|FD_WRITE
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

end_unit

