begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|"pthread_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_detach
argument_list|,
name|pthread_detach
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_pthread_detach
parameter_list|(
name|pthread_t
name|pthread
parameter_list|)
block|{
name|int
name|rval
init|=
literal|0
decl_stmt|;
comment|/* Check for invalid calling parameters: */
if|if
condition|(
name|pthread
operator|==
name|NULL
operator|||
name|pthread
operator|->
name|magic
operator|!=
name|PTHREAD_MAGIC
condition|)
comment|/* Return an invalid argument error: */
name|rval
operator|=
name|EINVAL
expr_stmt|;
comment|/* Check if the thread has not been detached: */
elseif|else
if|if
condition|(
operator|(
name|pthread
operator|->
name|attr
operator|.
name|flags
operator|&
name|PTHREAD_DETACHED
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Flag the thread as detached: */
name|pthread
operator|->
name|attr
operator|.
name|flags
operator||=
name|PTHREAD_DETACHED
expr_stmt|;
comment|/* 		 * Defer signals to protect the scheduling queues from 		 * access by the signal handler: 		 */
name|_thread_kern_sig_defer
argument_list|()
expr_stmt|;
comment|/* Check if there is a joiner: */
if|if
condition|(
name|pthread
operator|->
name|joiner
operator|!=
name|NULL
condition|)
block|{
name|struct
name|pthread
modifier|*
name|joiner
init|=
name|pthread
operator|->
name|joiner
decl_stmt|;
comment|/* Make the thread runnable: */
name|PTHREAD_NEW_STATE
argument_list|(
name|joiner
argument_list|,
name|PS_RUNNING
argument_list|)
expr_stmt|;
comment|/* Set the return value for the woken thread: */
name|joiner
operator|->
name|join_status
operator|.
name|error
operator|=
name|ESRCH
expr_stmt|;
name|joiner
operator|->
name|join_status
operator|.
name|ret
operator|=
name|NULL
expr_stmt|;
name|joiner
operator|->
name|join_status
operator|.
name|thread
operator|=
name|NULL
expr_stmt|;
comment|/* 			 * Disconnect the joiner from the thread being detached: 			 */
name|pthread
operator|->
name|joiner
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* 		 * Undefer and handle pending signals, yielding if a 		 * scheduling signal occurred while in the critical region. 		 */
name|_thread_kern_sig_undefer
argument_list|()
expr_stmt|;
block|}
else|else
comment|/* Return an error: */
name|rval
operator|=
name|EINVAL
expr_stmt|;
comment|/* Return the completion status: */
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_function

end_unit

