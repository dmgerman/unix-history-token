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
name|pthread_t
name|pthread
decl_stmt|;
comment|/* 	 * Check if the pthread kernel has unblocked signals (or is about to) 	 * and was on its way into a _thread_sys_select when the current 	 * signal interrupted it:  	 */
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
comment|/* 		 * Write the signal number to the kernel pipe so that it will 		 * be ready to read when this signal handler returns. This 		 * means that the _thread_sys_select call will complete 		 * immediately.  		 */
if|if
condition|(
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
operator|!=
literal|1
condition|)
block|{ 		}
block|}
comment|/* Check if the signal requires a dump of thread information: */
if|if
condition|(
name|sig
operator|==
name|SIGINFO
condition|)
block|{
comment|/* Dump thread information to file: */
name|_thread_dump_info
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|/* Handle depending on signal type: */
switch|switch
condition|(
name|sig
condition|)
block|{
comment|/* Interval timer used for timeslicing: */
case|case
name|SIGVTALRM
case|:
comment|/* 			 * Don't add the signal to any thread.  Just want to 			 * call the scheduler: 			 */
break|break;
comment|/* Child termination: */
case|case
name|SIGCHLD
case|:
comment|/* 			 * Enter a loop to process each thread in the linked 			 * list: 			 */
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
block|{
comment|/* 				 * Add the signal to the set of pending 				 * signals: 				 */
name|pthread
operator|->
name|sigpend
index|[
name|sig
index|]
operator|+=
literal|1
expr_stmt|;
if|if
condition|(
name|pthread
operator|->
name|state
operator|==
name|PS_WAIT_WAIT
condition|)
block|{
comment|/* Reset the error: */
comment|/* There should be another flag so that this is not required! ### */
name|_thread_seterrno
argument_list|(
name|pthread
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Change the state of the thread to run: */
name|pthread
operator|->
name|state
operator|=
name|PS_RUNNING
expr_stmt|;
block|}
block|}
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
comment|/* Set the file descriptor to non-blocking: */
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
break|break;
comment|/* Signals specific to the running thread: */
case|case
name|SIGBUS
case|:
case|case
name|SIGEMT
case|:
case|case
name|SIGFPE
case|:
case|case
name|SIGILL
case|:
case|case
name|SIGPIPE
case|:
case|case
name|SIGSEGV
case|:
case|case
name|SIGSYS
case|:
comment|/* Add the signal to the set of pending signals: */
name|_thread_run
operator|->
name|sigpend
index|[
name|sig
index|]
operator|+=
literal|1
expr_stmt|;
break|break;
comment|/* Signals to send to all threads: */
default|default:
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
block|{
comment|/* 				 * Add the signal to the set of pending 				 * signals:  				 */
name|pthread
operator|->
name|sigpend
index|[
name|sig
index|]
operator|+=
literal|1
expr_stmt|;
block|}
break|break;
block|}
comment|/* Check if the kernel is not locked: */
if|if
condition|(
name|_thread_run
operator|!=
operator|&
name|_thread_kern_thread
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
comment|/* Returns nothing. */
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

