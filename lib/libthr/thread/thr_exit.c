begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
name|_pthread_exit
argument_list|,
name|pthread_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|_thread_exit
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|lineno
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
block|{
name|char
name|s
index|[
literal|256
index|]
decl_stmt|;
comment|/* Prepare an error message string: */
name|snprintf
argument_list|(
name|s
argument_list|,
sizeof|sizeof
argument_list|(
name|s
argument_list|)
argument_list|,
literal|"Fatal error '%s' at line %d in file %s (errno = %d)\n"
argument_list|,
name|string
argument_list|,
name|lineno
argument_list|,
name|fname
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|/* Write the string to the standard error file descriptor: */
name|__sys_write
argument_list|(
literal|2
argument_list|,
name|s
argument_list|,
name|strlen
argument_list|(
name|s
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Force this process to exit: */
comment|/* XXX - Do we want abort to be conditional on _PTHREADS_INVARIANTS? */
if|#
directive|if
name|defined
argument_list|(
name|_PTHREADS_INVARIANTS
argument_list|)
name|abort
argument_list|()
expr_stmt|;
else|#
directive|else
name|__sys_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Only called when a thread is cancelled.  It may be more useful  * to call it from pthread_exit() if other ways of asynchronous or  * abnormal thread termination can be found.  */
end_comment

begin_function
name|void
name|_thread_exit_cleanup
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * POSIX states that cancellation/termination of a thread should 	 * not release any visible resources (such as mutexes) and that 	 * it is the applications responsibility.  Resources that are 	 * internal to the threads library, including file and fd locks, 	 * are not visible to the application and need to be released. 	 */
comment|/* Unlock all private mutexes: */
name|_mutex_unlock_private
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
comment|/* 	 * This still isn't quite correct because we don't account 	 * for held spinlocks (see libc/stdlib/malloc.c). 	 */
block|}
end_function

begin_function
name|void
name|_pthread_exit
parameter_list|(
name|void
modifier|*
name|status
parameter_list|)
block|{
name|pthread_t
name|pthread
decl_stmt|;
comment|/* Check if this thread is already in the process of exiting: */
if|if
condition|(
operator|(
name|curthread
operator|->
name|flags
operator|&
name|PTHREAD_EXITING
operator|)
operator|!=
literal|0
condition|)
block|{
name|char
name|msg
index|[
literal|128
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|msg
argument_list|,
sizeof|sizeof
argument_list|(
name|msg
argument_list|)
argument_list|,
literal|"Thread %p has called pthread_exit() from a destructor. POSIX 1003.1 1996 s16.2.5.2 does not allow this!"
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|PANIC
argument_list|(
name|msg
argument_list|)
expr_stmt|;
block|}
comment|/* Flag this thread as exiting: */
name|curthread
operator|->
name|flags
operator||=
name|PTHREAD_EXITING
expr_stmt|;
comment|/* Save the return value: */
name|curthread
operator|->
name|ret
operator|=
name|status
expr_stmt|;
while|while
condition|(
name|curthread
operator|->
name|cleanup
operator|!=
name|NULL
condition|)
block|{
name|pthread_cleanup_pop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|curthread
operator|->
name|attr
operator|.
name|cleanup_attr
operator|!=
name|NULL
condition|)
block|{
name|curthread
operator|->
name|attr
operator|.
name|cleanup_attr
argument_list|(
name|curthread
operator|->
name|attr
operator|.
name|arg_attr
argument_list|)
expr_stmt|;
block|}
comment|/* Check if there is thread specific data: */
if|if
condition|(
name|curthread
operator|->
name|specific
operator|!=
name|NULL
condition|)
block|{
comment|/* Run the thread-specific data destructors: */
name|_thread_cleanupspecific
argument_list|()
expr_stmt|;
block|}
comment|/* 	 * Lock the garbage collector mutex to ensure that the garbage 	 * collector is not using the dead thread list. 	 */
if|if
condition|(
name|pthread_mutex_lock
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
comment|/* Add this thread to the list of dead threads. */
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|_dead_list
argument_list|,
name|curthread
argument_list|,
name|dle
argument_list|)
expr_stmt|;
comment|/* 	 * Signal the garbage collector thread that there is something 	 * to clean up. 	 */
if|if
condition|(
name|pthread_cond_signal
argument_list|(
operator|&
name|_gc_cond
argument_list|)
operator|!=
literal|0
condition|)
name|PANIC
argument_list|(
literal|"Cannot signal gc cond"
argument_list|)
expr_stmt|;
comment|/* 	 * Avoid a race condition where a scheduling signal can occur 	 * causing the garbage collector thread to run.  If this happens, 	 * the current thread can be cleaned out from under us. 	 */
name|GIANT_LOCK
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
comment|/* Unlock the garbage collector mutex. */
if|if
condition|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|_gc_mutex
argument_list|)
operator|!=
literal|0
condition|)
name|PANIC
argument_list|(
literal|"Cannot unlock gc mutex"
argument_list|)
expr_stmt|;
comment|/* Check if there is a thread joining this one: */
if|if
condition|(
name|curthread
operator|->
name|joiner
operator|!=
name|NULL
condition|)
block|{
name|pthread
operator|=
name|curthread
operator|->
name|joiner
expr_stmt|;
name|curthread
operator|->
name|joiner
operator|=
name|NULL
expr_stmt|;
comment|/* Make the joining thread runnable: */
name|PTHREAD_NEW_STATE
argument_list|(
name|pthread
argument_list|,
name|PS_RUNNING
argument_list|)
expr_stmt|;
comment|/* Set the return value for the joining thread: */
name|pthread
operator|->
name|join_status
operator|.
name|ret
operator|=
name|curthread
operator|->
name|ret
expr_stmt|;
name|pthread
operator|->
name|join_status
operator|.
name|error
operator|=
literal|0
expr_stmt|;
name|pthread
operator|->
name|join_status
operator|.
name|thread
operator|=
name|NULL
expr_stmt|;
comment|/* Make this thread collectable by the garbage collector. */
name|PTHREAD_ASSERT
argument_list|(
operator|(
operator|(
name|curthread
operator|->
name|attr
operator|.
name|flags
operator|&
name|PTHREAD_DETACHED
operator|)
operator|==
literal|0
operator|)
argument_list|,
literal|"Cannot join a detached thread"
argument_list|)
expr_stmt|;
name|curthread
operator|->
name|attr
operator|.
name|flags
operator||=
name|PTHREAD_DETACHED
expr_stmt|;
block|}
comment|/* Remove this thread from the thread list: */
name|TAILQ_REMOVE
argument_list|(
operator|&
name|_thread_list
argument_list|,
name|curthread
argument_list|,
name|tle
argument_list|)
expr_stmt|;
name|PTHREAD_SET_STATE
argument_list|(
name|curthread
argument_list|,
name|PS_DEAD
argument_list|)
expr_stmt|;
name|GIANT_UNLOCK
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
comment|/* If we're the last thread, call it quits */
if|if
condition|(
name|TAILQ_EMPTY
argument_list|(
operator|&
name|_thread_list
argument_list|)
condition|)
name|exit
argument_list|(
name|curthread
operator|->
name|ret
argument_list|)
expr_stmt|;
comment|/* 	 * Retire the architecture specific id so that it can be used for 	 * new threads. 	 */
name|_retire_thread
argument_list|(
name|curthread
operator|->
name|arch_id
argument_list|)
expr_stmt|;
name|_thr_exit
argument_list|()
expr_stmt|;
comment|/* This point should not be reached. */
name|PANIC
argument_list|(
literal|"Dead thread has resumed"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

