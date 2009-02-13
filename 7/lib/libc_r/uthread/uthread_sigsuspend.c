begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
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
file|"pthread_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sigsuspend
argument_list|,
name|sigsuspend
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_sigsuspend
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|)
block|{
name|struct
name|pthread
modifier|*
name|curthread
init|=
name|_get_curthread
argument_list|()
decl_stmt|;
name|int
name|ret
init|=
operator|-
literal|1
decl_stmt|;
name|sigset_t
name|oset
decl_stmt|,
name|sigset
decl_stmt|;
comment|/* Check if a new signal set was provided by the caller: */
if|if
condition|(
name|set
operator|!=
name|NULL
condition|)
block|{
comment|/* Save the current signal mask: */
name|oset
operator|=
name|curthread
operator|->
name|sigmask
expr_stmt|;
comment|/* Change the caller's mask: */
name|curthread
operator|->
name|sigmask
operator|=
operator|*
name|set
expr_stmt|;
comment|/* 		 * Check if there are pending signals for the running 		 * thread or process that aren't blocked: 		 */
name|sigset
operator|=
name|curthread
operator|->
name|sigpend
expr_stmt|;
name|SIGSETOR
argument_list|(
name|sigset
argument_list|,
name|_process_sigpending
argument_list|)
expr_stmt|;
name|SIGSETNAND
argument_list|(
name|sigset
argument_list|,
name|curthread
operator|->
name|sigmask
argument_list|)
expr_stmt|;
if|if
condition|(
name|SIGNOTEMPTY
argument_list|(
name|sigset
argument_list|)
condition|)
block|{
comment|/* 			 * Call the kernel scheduler which will safely 			 * install a signal frame for the running thread: 			 */
name|_thread_kern_sched_sig
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|/* Wait for a signal: */
name|_thread_kern_sched_state
argument_list|(
name|PS_SIGSUSPEND
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
block|}
comment|/* Always return an interrupted error: */
name|errno
operator|=
name|EINTR
expr_stmt|;
comment|/* Restore the signal mask: */
name|curthread
operator|->
name|sigmask
operator|=
name|oset
expr_stmt|;
block|}
else|else
block|{
comment|/* Return an invalid argument error: */
name|errno
operator|=
name|EINVAL
expr_stmt|;
block|}
comment|/* Return the completion status: */
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
name|int
name|__sigsuspend
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|_thread_enter_cancellation_point
argument_list|()
expr_stmt|;
name|ret
operator|=
name|_sigsuspend
argument_list|(
name|set
argument_list|)
expr_stmt|;
name|_thread_leave_cancellation_point
argument_list|()
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

