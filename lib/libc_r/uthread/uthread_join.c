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
file|"namespace.h"
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
file|"pthread_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_join
argument_list|,
name|pthread_join
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_pthread_join
parameter_list|(
name|pthread_t
name|pthread
parameter_list|,
name|void
modifier|*
modifier|*
name|thread_return
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
literal|0
decl_stmt|;
name|pthread_t
name|thread
decl_stmt|;
name|_thread_enter_cancellation_point
argument_list|()
expr_stmt|;
comment|/* Check if the caller has specified an invalid thread: */
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
block|{
comment|/* Invalid thread: */
name|_thread_leave_cancellation_point
argument_list|()
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
comment|/* Check if the caller has specified itself: */
if|if
condition|(
name|pthread
operator|==
name|curthread
condition|)
block|{
comment|/* Avoid a deadlock condition: */
name|_thread_leave_cancellation_point
argument_list|()
expr_stmt|;
return|return
operator|(
name|EDEADLK
operator|)
return|;
block|}
comment|/* 	 * Lock the garbage collector mutex to ensure that the garbage 	 * collector is not using the dead thread list. 	 */
if|if
condition|(
name|_pthread_mutex_lock
argument_list|(
operator|&
name|_gc_mutex
argument_list|)
operator|!=
literal|0
condition|)
name|PANIC
argument_list|(
literal|"Cannot lock gc mutex"
argument_list|)
expr_stmt|;
comment|/* 	 * Defer signals to protect the thread list from access 	 * by the signal handler: 	 */
name|_thread_kern_sig_defer
argument_list|()
expr_stmt|;
comment|/* 	 * Unlock the garbage collector mutex, now that the garbage collector 	 * can't be run: 	 */
if|if
condition|(
name|_pthread_mutex_unlock
argument_list|(
operator|&
name|_gc_mutex
argument_list|)
operator|!=
literal|0
condition|)
name|PANIC
argument_list|(
literal|"Cannot lock gc mutex"
argument_list|)
expr_stmt|;
comment|/* 	 * Search for the specified thread in the list of active threads.  This 	 * is done manually here rather than calling _find_thread() because 	 * the searches in _thread_list and _dead_list (as well as setting up 	 * join/detach state) have to be done atomically. 	 */
name|TAILQ_FOREACH
argument_list|(
argument|thread
argument_list|,
argument|&_thread_list
argument_list|,
argument|tle
argument_list|)
block|{
if|if
condition|(
name|thread
operator|==
name|pthread
condition|)
break|break;
block|}
if|if
condition|(
name|thread
operator|==
name|NULL
condition|)
block|{
comment|/* 		 * Search for the specified thread in the list of dead threads: 		 */
name|TAILQ_FOREACH
argument_list|(
argument|thread
argument_list|,
argument|&_dead_list
argument_list|,
argument|dle
argument_list|)
block|{
if|if
condition|(
name|thread
operator|==
name|pthread
condition|)
break|break;
block|}
block|}
comment|/* Check if the thread was not found or has been detached: */
if|if
condition|(
name|thread
operator|==
name|NULL
operator|||
operator|(
operator|(
name|pthread
operator|->
name|attr
operator|.
name|flags
operator|&
name|PTHREAD_DETACHED
operator|)
operator|!=
literal|0
operator|)
condition|)
block|{
comment|/* Undefer and handle pending signals, yielding if necessary: */
name|_thread_kern_sig_undefer
argument_list|()
expr_stmt|;
comment|/* Return an error: */
name|ret
operator|=
name|ESRCH
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pthread
operator|->
name|joiner
operator|!=
name|NULL
condition|)
block|{
comment|/* Undefer and handle pending signals, yielding if necessary: */
name|_thread_kern_sig_undefer
argument_list|()
expr_stmt|;
comment|/* Multiple joiners are not supported. */
name|ret
operator|=
name|ENOTSUP
expr_stmt|;
comment|/* Check if the thread is not dead: */
block|}
elseif|else
if|if
condition|(
name|pthread
operator|->
name|state
operator|!=
name|PS_DEAD
condition|)
block|{
comment|/* Set the running thread to be the joiner: */
name|pthread
operator|->
name|joiner
operator|=
name|curthread
expr_stmt|;
comment|/* Keep track of which thread we're joining to: */
name|curthread
operator|->
name|join_status
operator|.
name|thread
operator|=
name|pthread
expr_stmt|;
while|while
condition|(
name|curthread
operator|->
name|join_status
operator|.
name|thread
operator|==
name|pthread
condition|)
block|{
comment|/* Schedule the next thread: */
name|_thread_kern_sched_state
argument_list|(
name|PS_JOIN
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * The thread return value and error are set by the thread we're 		 * joining to when it exits or detaches: 		 */
name|ret
operator|=
name|curthread
operator|->
name|join_status
operator|.
name|error
expr_stmt|;
if|if
condition|(
operator|(
name|ret
operator|==
literal|0
operator|)
operator|&&
operator|(
name|thread_return
operator|!=
name|NULL
operator|)
condition|)
operator|*
name|thread_return
operator|=
name|curthread
operator|->
name|join_status
operator|.
name|ret
expr_stmt|;
comment|/* Undefer and handle pending signals, yielding if necessary: */
name|_thread_kern_sig_undefer
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * The thread exited (is dead) without being detached, and no 		 * thread has joined it. 		 */
comment|/* Check if the return value is required: */
if|if
condition|(
name|thread_return
operator|!=
name|NULL
condition|)
block|{
comment|/* Return the thread's return value: */
operator|*
name|thread_return
operator|=
name|pthread
operator|->
name|ret
expr_stmt|;
block|}
comment|/* Make the thread collectable by the garbage collector. */
name|pthread
operator|->
name|attr
operator|.
name|flags
operator||=
name|PTHREAD_DETACHED
expr_stmt|;
comment|/* Undefer and handle pending signals, yielding if necessary: */
name|_thread_kern_sig_undefer
argument_list|()
expr_stmt|;
block|}
name|_thread_leave_cancellation_point
argument_list|()
expr_stmt|;
comment|/* Return the completion status: */
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

