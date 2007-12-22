begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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
file|"thr_private.h"
end_include

begin_expr_stmt
name|LT10_COMPAT_PRIVATE
argument_list|(
name|_sigprocmask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LT10_COMPAT_DEFAULT
argument_list|(
name|sigprocmask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_sigprocmask
argument_list|,
name|sigprocmask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_sigprocmask
parameter_list|(
name|int
name|how
parameter_list|,
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|,
name|sigset_t
modifier|*
name|oset
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
name|pthread_sigmask
argument_list|(
name|how
argument_list|,
name|set
argument_list|,
name|oset
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
condition|)
block|{
name|errno
operator|=
name|ret
expr_stmt|;
name|ret
operator|=
operator|-
literal|1
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

