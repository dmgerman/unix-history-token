begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

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

begin_function
name|int
name|sigsuspend
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|)
block|{
name|int
name|ret
init|=
operator|-
literal|1
decl_stmt|;
name|sigset_t
name|oset
decl_stmt|;
comment|/* Check if a new signal set was provided by the caller: */
if|if
condition|(
name|set
operator|!=
name|NULL
condition|)
block|{
comment|/* Save the current sigmal mask: */
name|oset
operator|=
name|_thread_run
operator|->
name|sigmask
expr_stmt|;
comment|/* Combine the caller's mask with the current one: */
name|_thread_run
operator|->
name|sigmask
operator||=
operator|*
name|set
expr_stmt|;
comment|/* Wait for a signal: */
name|_thread_kern_sched_state
argument_list|(
name|PS_SIGWAIT
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
comment|/* Always return an interrupted error: */
name|errno
operator|=
name|EINTR
expr_stmt|;
comment|/* Restore the signal mask: */
name|_thread_run
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

