begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

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
comment|/* Static variables: */
end_comment

begin_decl_stmt
specifier|static
name|int
specifier|volatile
name|yield_on_unlock_dead
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
specifier|volatile
name|yield_on_unlock_thread
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|spinlock_t
name|thread_dead_lock
init|=
name|_SPINLOCK_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|spinlock_t
name|thread_link_list_lock
init|=
name|_SPINLOCK_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lock the thread list: */
end_comment

begin_function
name|void
name|_lock_thread_list
parameter_list|()
block|{
comment|/* Lock the thread list: */
name|_SPINLOCK
argument_list|(
operator|&
name|thread_link_list_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Lock the dead thread list: */
end_comment

begin_function
name|void
name|_lock_dead_thread_list
parameter_list|()
block|{
comment|/* Lock the dead thread list: */
name|_SPINLOCK
argument_list|(
operator|&
name|thread_dead_lock
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Lock the thread list: */
end_comment

begin_function
name|void
name|_unlock_thread_list
parameter_list|()
block|{
comment|/* Unlock the thread list: */
name|_SPINUNLOCK
argument_list|(
operator|&
name|thread_link_list_lock
argument_list|)
expr_stmt|;
comment|/* 	 * Check if a scheduler interrupt occurred while the thread 	 * list was locked: 	 */
if|if
condition|(
name|yield_on_unlock_thread
condition|)
block|{
comment|/* Reset the interrupt flag: */
name|yield_on_unlock_thread
operator|=
literal|0
expr_stmt|;
comment|/* This thread has overstayed it's welcome: */
name|sched_yield
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Lock the dead thread list: */
end_comment

begin_function
name|void
name|_unlock_dead_thread_list
parameter_list|()
block|{
comment|/* Unlock the dead thread list: */
name|_SPINUNLOCK
argument_list|(
operator|&
name|thread_dead_lock
argument_list|)
expr_stmt|;
comment|/* 	 * Check if a scheduler interrupt occurred while the dead 	 * thread list was locked: 	 */
if|if
condition|(
name|yield_on_unlock_dead
condition|)
block|{
comment|/* Reset the interrupt flag: */
name|yield_on_unlock_dead
operator|=
literal|0
expr_stmt|;
comment|/* This thread has overstayed it's welcome: */
name|sched_yield
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|_thread_sig_handler
parameter_list|(
name|int
name|sig
parameter_list|,
name|int
name|code
parameter_list|,
name|struct
name|sigcontext
modifier|*
name|scp
parameter_list|)
block|{
name|char
name|c
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|dispatch
init|=
literal|0
decl_stmt|;
name|pthread_t
name|pthread
decl_stmt|;
comment|/* 	 * Check if the pthread kernel has unblocked signals (or is about to) 	 * and was on its way into a _select when the current 	 * signal interrupted it:  	 */
if|if
condition|(
name|_thread_kern_in_select
condition|)
block|{
comment|/* Cast the signal number to a character variable: */
name|c
operator|=
name|sig
expr_stmt|;
comment|/* 		 * Write the signal number to the kernel pipe so that it will 		 * be ready to read when this signal handler returns. This 		 * means that the _select call will complete 		 * immediately.  		 */
name|_thread_sys_write
argument_list|(
name|_thread_kern_pipe
index|[
literal|1
index|]
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Check if the signal requires a dump of thread information: */
if|if
condition|(
name|sig
operator|==
name|SIGINFO
condition|)
comment|/* Dump thread information to file: */
name|_thread_dump_info
argument_list|()
expr_stmt|;
comment|/* Check if an interval timer signal: */
elseif|else
if|if
condition|(
name|sig
operator|==
name|SIGVTALRM
condition|)
block|{
comment|/* Check if the scheduler interrupt has come at an 		 * unfortunate time which one of the threads is 		 * modifying the thread list: 		 */
if|if
condition|(
name|thread_link_list_lock
operator|.
name|access_lock
condition|)
comment|/* 			 * Set a flag so that the thread that has 			 * the lock yields when it unlocks the 			 * thread list: 			 */
name|yield_on_unlock_thread
operator|=
literal|1
expr_stmt|;
comment|/* Check if the scheduler interrupt has come at an 		 * unfortunate time which one of the threads is 		 * modifying the dead thread list: 		 */
if|if
condition|(
name|thread_dead_lock
operator|.
name|access_lock
condition|)
comment|/* 			 * Set a flag so that the thread that has 			 * the lock yields when it unlocks the 			 * dead thread list: 			 */
name|yield_on_unlock_dead
operator|=
literal|1
expr_stmt|;
comment|/* 		 * Check if the kernel has not been interrupted while 		 * executing scheduler code: 		 */
elseif|else
if|if
condition|(
operator|!
name|_thread_kern_in_sched
condition|)
block|{
comment|/* 			 * Schedule the next thread. This function is not 			 * expected to return because it will do a longjmp 			 * instead.  			 */
name|_thread_kern_sched
argument_list|(
name|scp
argument_list|)
expr_stmt|;
comment|/* 			 * This point should not be reached, so abort the 			 * process:  			 */
name|PANIC
argument_list|(
literal|"Returned to signal function from scheduler"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Check if a child has terminated: */
if|if
condition|(
name|sig
operator|==
name|SIGCHLD
condition|)
block|{
comment|/* 			 * Go through the file list and set all files 			 * to non-blocking again in case the child 			 * set some of them to block. Sigh. 			 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|_thread_dtablesize
condition|;
name|i
operator|++
control|)
block|{
comment|/* Check if this file is used: */
if|if
condition|(
name|_thread_fd_table
index|[
name|i
index|]
operator|!=
name|NULL
condition|)
block|{
comment|/* 					 * Set the file descriptor to 					 * non-blocking: 					 */
name|_thread_sys_fcntl
argument_list|(
name|i
argument_list|,
name|F_SETFL
argument_list|,
name|_thread_fd_table
index|[
name|i
index|]
operator|->
name|flags
operator||
name|O_NONBLOCK
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/* 		 * POSIX says that pending SIGCONT signals are 		 * discarded when one of there signals occurs. 		 */
if|if
condition|(
name|sig
operator|==
name|SIGTSTP
operator|||
name|sig
operator|==
name|SIGTTIN
operator|||
name|sig
operator|==
name|SIGTTOU
condition|)
block|{
comment|/* 			 * Enter a loop to discard pending SIGCONT 			 * signals: 			 */
for|for
control|(
name|pthread
operator|=
name|_thread_link_list
init|;
name|pthread
operator|!=
name|NULL
condition|;
name|pthread
operator|=
name|pthread
operator|->
name|nxt
control|)
name|sigdelset
argument_list|(
operator|&
name|pthread
operator|->
name|sigpend
argument_list|,
name|SIGCONT
argument_list|)
expr_stmt|;
block|}
comment|/* Check if the signal is not being ignored: */
if|if
condition|(
name|_thread_sigact
index|[
name|sig
operator|-
literal|1
index|]
operator|.
name|sa_handler
operator|!=
name|SIG_IGN
condition|)
comment|/* 			 * Enter a loop to process each thread in the linked 			 * list:  			 */
for|for
control|(
name|pthread
operator|=
name|_thread_link_list
init|;
name|pthread
operator|!=
name|NULL
condition|;
name|pthread
operator|=
name|pthread
operator|->
name|nxt
control|)
name|_thread_signal
argument_list|(
name|pthread
argument_list|,
name|sig
argument_list|)
expr_stmt|;
comment|/* Dispatch pending signals to the running thread: */
name|_dispatch_signals
argument_list|()
expr_stmt|;
block|}
comment|/* Returns nothing. */
return|return;
block|}
end_function

begin_comment
comment|/* Perform thread specific actions in response to a signal: */
end_comment

begin_function
name|void
name|_thread_signal
parameter_list|(
name|pthread_t
name|pthread
parameter_list|,
name|int
name|sig
parameter_list|)
block|{
name|pthread_t
name|saved
decl_stmt|;
name|struct
name|sigaction
name|act
decl_stmt|;
comment|/* 	 * Flag the signal as pending. It will be dispatched later. 	 */
name|sigaddset
argument_list|(
operator|&
name|pthread
operator|->
name|sigpend
argument_list|,
name|sig
argument_list|)
expr_stmt|;
comment|/* 	 * Process according to thread state: 	 */
switch|switch
condition|(
name|pthread
operator|->
name|state
condition|)
block|{
comment|/* 	 * States which do not change when a signal is trapped: 	 */
case|case
name|PS_COND_WAIT
case|:
case|case
name|PS_DEAD
case|:
case|case
name|PS_FDLR_WAIT
case|:
case|case
name|PS_FDLW_WAIT
case|:
case|case
name|PS_FILE_WAIT
case|:
case|case
name|PS_JOIN
case|:
case|case
name|PS_MUTEX_WAIT
case|:
case|case
name|PS_RUNNING
case|:
case|case
name|PS_STATE_MAX
case|:
case|case
name|PS_SIGTHREAD
case|:
case|case
name|PS_SUSPENDED
case|:
comment|/* Nothing to do here. */
break|break;
comment|/* 	 * States that are interrupted by the occurrence of a signal 	 * other than the scheduling alarm:  	 */
case|case
name|PS_FDR_WAIT
case|:
case|case
name|PS_FDW_WAIT
case|:
case|case
name|PS_SLEEP_WAIT
case|:
case|case
name|PS_SIGWAIT
case|:
case|case
name|PS_WAIT_WAIT
case|:
case|case
name|PS_SELECT_WAIT
case|:
comment|/* Flag the operation as interrupted: */
name|pthread
operator|->
name|interrupted
operator|=
literal|1
expr_stmt|;
comment|/* Change the state of the thread to run: */
name|PTHREAD_NEW_STATE
argument_list|(
name|pthread
argument_list|,
name|PS_RUNNING
argument_list|)
expr_stmt|;
comment|/* Return the signal number: */
name|pthread
operator|->
name|signo
operator|=
name|sig
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/* Dispatch pending signals to the running thread: */
end_comment

begin_function
name|void
name|_dispatch_signals
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
comment|/* 	 * Check if there are pending signals for the running 	 * thread that aren't blocked: 	 */
if|if
condition|(
operator|(
name|_thread_run
operator|->
name|sigpend
operator|&
operator|~
name|_thread_run
operator|->
name|sigmask
operator|)
operator|!=
literal|0
condition|)
comment|/* Look for all possible pending signals: */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|NSIG
condition|;
name|i
operator|++
control|)
comment|/* 			 * Check that a custom handler is installed 			 * and if the signal is not blocked: 			 */
if|if
condition|(
name|_thread_sigact
index|[
name|i
operator|-
literal|1
index|]
operator|.
name|sa_handler
operator|!=
name|SIG_DFL
operator|&&
name|_thread_sigact
index|[
name|i
operator|-
literal|1
index|]
operator|.
name|sa_handler
operator|!=
name|SIG_IGN
operator|&&
name|sigismember
argument_list|(
operator|&
name|_thread_run
operator|->
name|sigpend
argument_list|,
name|i
argument_list|)
operator|&&
operator|!
name|sigismember
argument_list|(
operator|&
name|_thread_run
operator|->
name|sigmask
argument_list|,
name|i
argument_list|)
condition|)
block|{
comment|/* Clear the pending signal: */
name|sigdelset
argument_list|(
operator|&
name|_thread_run
operator|->
name|sigpend
argument_list|,
name|i
argument_list|)
expr_stmt|;
comment|/* 				 * Dispatch the signal via the custom signal 				 * handler: 				 */
operator|(
operator|*
operator|(
name|_thread_sigact
index|[
name|i
operator|-
literal|1
index|]
operator|.
name|sa_handler
operator|)
operator|)
operator|(
name|i
operator|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

