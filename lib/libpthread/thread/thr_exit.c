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

begin_function_decl
name|void
name|_pthread_exit
parameter_list|(
name|void
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

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
name|_thr_exit
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
name|msg
parameter_list|)
block|{
comment|/* Write an error message to the standard error file descriptor: */
name|_thread_printf
argument_list|(
literal|2
argument_list|,
literal|"Fatal error '%s' at line %d in file %s (errno = %d)\n"
argument_list|,
name|msg
argument_list|,
name|lineno
argument_list|,
name|fname
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Only called when a thread is cancelled.  It may be more useful  * to call it from pthread_exit() if other ways of asynchronous or  * abnormal thread termination can be found.  */
end_comment

begin_function
name|void
name|_thr_exit_cleanup
parameter_list|(
name|void
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
name|struct
name|pthread
modifier|*
name|curthread
init|=
name|_get_curthread
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|_kse_isthreaded
argument_list|()
condition|)
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Check if this thread is already in the process of exiting: */
if|if
condition|(
operator|(
name|curthread
operator|->
name|flags
operator|&
name|THR_FLAGS_EXITING
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
literal|"Thread %p has called "
literal|"pthread_exit() from a destructor. POSIX 1003.1 "
literal|"1996 s16.2.5.2 does not allow this!"
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
comment|/* 	 * Flag this thread as exiting.  Threads should now be prevented 	 * from joining to this thread. 	 */
name|THR_SCHED_LOCK
argument_list|(
name|curthread
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|curthread
operator|->
name|flags
operator||=
name|THR_FLAGS_EXITING
expr_stmt|;
name|THR_SCHED_UNLOCK
argument_list|(
name|curthread
argument_list|,
name|curthread
argument_list|)
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
comment|/* This thread will never be re-scheduled. */
name|THR_LOCK_SWITCH
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
name|THR_SET_STATE
argument_list|(
name|curthread
argument_list|,
name|PS_DEAD
argument_list|)
expr_stmt|;
name|_thr_sched_switch_unlocked
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
comment|/* Never reach! */
comment|/* This point should not be reached. */
name|PANIC
argument_list|(
literal|"Dead thread has resumed"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

