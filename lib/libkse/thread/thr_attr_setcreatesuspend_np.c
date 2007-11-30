begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_expr_stmt
name|LT10_COMPAT_PRIVATE
argument_list|(
name|_pthread_attr_setcreatesuspend_np
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LT10_COMPAT_DEFAULT
argument_list|(
name|pthread_attr_setcreatesuspend_np
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|_pthread_attr_setcreatesuspend_np
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_attr_setcreatesuspend_np
argument_list|,
name|pthread_attr_setcreatesuspend_np
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_pthread_attr_setcreatesuspend_np
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
if|if
condition|(
name|attr
operator|==
name|NULL
operator|||
operator|*
name|attr
operator|==
name|NULL
condition|)
block|{
name|ret
operator|=
name|EINVAL
expr_stmt|;
block|}
else|else
block|{
operator|(
operator|*
name|attr
operator|)
operator|->
name|suspend
operator|=
name|THR_CREATE_SUSPENDED
expr_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

