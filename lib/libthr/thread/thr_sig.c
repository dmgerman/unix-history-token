begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 Jeffrey Roberson<jeff@freebsd.org>  * Copyright (c) 2003 Jonathan Mini<mini@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_comment
comment|/* #define DEBUG_SIGNAL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_SIGNAL
end_ifdef

begin_define
define|#
directive|define
name|DBG_MSG
value|stdout_debug
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBG_MSG
parameter_list|(
name|x
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_sigmask
argument_list|,
name|pthread_sigmask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_pthread_sigmask
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
name|error
decl_stmt|;
comment|/* 	 * This always sets the mask on the current thread. 	 */
name|error
operator|=
name|sigprocmask
argument_list|(
name|how
argument_list|,
name|set
argument_list|,
name|oset
argument_list|)
expr_stmt|;
comment|/* 	 * pthread_sigmask returns errno or success while sigprocmask returns 	 * -1 and sets errno. 	 */
if|if
condition|(
name|error
operator|==
operator|-
literal|1
condition|)
name|error
operator|=
name|errno
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_kill
argument_list|,
name|pthread_kill
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_pthread_kill
parameter_list|(
name|pthread_t
name|pthread
parameter_list|,
name|int
name|sig
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|sig
operator|<
literal|0
operator|||
name|sig
operator|>
name|NSIG
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
if|if
condition|(
name|_thread_initial
operator|==
name|NULL
condition|)
name|_thread_init
argument_list|()
expr_stmt|;
name|error
operator|=
name|_find_thread
argument_list|(
name|pthread
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* 	 * A 0 signal means do error-checking but don't send signal. 	 */
if|if
condition|(
name|sig
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|thr_kill
argument_list|(
name|pthread
operator|->
name|thr_id
argument_list|,
name|sig
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

