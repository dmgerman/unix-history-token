begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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

begin_comment
comment|/* Suspend a thread: */
end_comment

begin_function
name|int
name|pthread_suspend_np
parameter_list|(
name|pthread_t
name|thread
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
comment|/* Find the thread in the list of active threads: */
if|if
condition|(
operator|(
name|ret
operator|=
name|_find_thread
argument_list|(
name|thread
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* The thread exists. Is it running? */
if|if
condition|(
name|thread
operator|->
name|state
operator|!=
name|PS_RUNNING
operator|&&
name|thread
operator|->
name|state
operator|!=
name|PS_SUSPENDED
condition|)
block|{
comment|/* The thread operation has been interrupted */
name|_thread_seterrno
argument_list|(
name|thread
argument_list|,
name|EINTR
argument_list|)
expr_stmt|;
name|thread
operator|->
name|interrupted
operator|=
literal|1
expr_stmt|;
block|}
comment|/* 		 * Defer signals to protect the scheduling queues from 		 * access by the signal handler: 		 */
name|_thread_kern_sig_defer
argument_list|()
expr_stmt|;
comment|/* Suspend the thread. */
name|PTHREAD_NEW_STATE
argument_list|(
name|thread
argument_list|,
name|PS_SUSPENDED
argument_list|)
expr_stmt|;
comment|/* 		 * Undefer and handle pending signals, yielding if 		 * necessary: 		 */
name|_thread_kern_sig_undefer
argument_list|()
expr_stmt|;
block|}
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

