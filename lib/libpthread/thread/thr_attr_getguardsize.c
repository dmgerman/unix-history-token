begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001 Jason Evans<jasone@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer  *    unmodified other than the allowable addition of one or more  *    copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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
file|"thr_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_attr_getguardsize
argument_list|,
name|pthread_attr_getguardsize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_pthread_attr_getguardsize
parameter_list|(
specifier|const
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|size_t
modifier|*
name|guardsize
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
comment|/* Check for invalid arguments: */
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
operator|||
name|guardsize
operator|==
name|NULL
condition|)
name|ret
operator|=
name|EINVAL
expr_stmt|;
else|else
block|{
comment|/* Return the guard size: */
operator|*
name|guardsize
operator|=
operator|(
operator|*
name|attr
operator|)
operator|->
name|guardsize_attr
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

