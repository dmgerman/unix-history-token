begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
name|strcpy
argument_list|(
name|s
argument_list|,
literal|"Fatal error '"
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|s
argument_list|,
name|string
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|s
argument_list|,
literal|"' at line ? "
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|s
argument_list|,
literal|"in file "
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|s
argument_list|,
name|fname
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|s
argument_list|,
literal|" (errno = ?"
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|s
argument_list|,
literal|")\n"
argument_list|)
expr_stmt|;
comment|/* Write the string to the standard error file descriptor: */
name|_thread_sys_write
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
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|pthread_exit
parameter_list|(
name|void
modifier|*
name|status
parameter_list|)
block|{
name|int
name|sig
decl_stmt|;
name|long
name|l
decl_stmt|;
name|pthread_t
name|pthread
decl_stmt|;
comment|/* Block signals: */
name|_thread_kern_sig_block
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
comment|/* Save the return value: */
name|_thread_run
operator|->
name|ret
operator|=
name|status
expr_stmt|;
while|while
condition|(
name|_thread_run
operator|->
name|cleanup
operator|!=
name|NULL
condition|)
block|{
name|_thread_cleanup_pop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|_thread_run
operator|->
name|attr
operator|.
name|cleanup_attr
operator|!=
name|NULL
condition|)
block|{
name|_thread_run
operator|->
name|attr
operator|.
name|cleanup_attr
argument_list|(
name|_thread_run
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
name|_thread_run
operator|->
name|specific_data
operator|!=
name|NULL
condition|)
block|{
comment|/* Run the thread-specific data destructors: */
name|_thread_cleanupspecific
argument_list|()
expr_stmt|;
block|}
comment|/* Check if there are any threads joined to this one: */
while|while
condition|(
operator|(
name|pthread
operator|=
name|_thread_queue_deq
argument_list|(
operator|&
operator|(
name|_thread_run
operator|->
name|join_queue
operator|)
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* Wake the joined thread and let it detach this thread: */
name|pthread
operator|->
name|state
operator|=
name|PS_RUNNING
expr_stmt|;
block|}
comment|/* Check if the running thread is at the head of the linked list: */
if|if
condition|(
name|_thread_link_list
operator|==
name|_thread_run
condition|)
block|{
comment|/* There is no previous thread: */
name|_thread_link_list
operator|=
name|_thread_run
operator|->
name|nxt
expr_stmt|;
block|}
else|else
block|{
comment|/* Point to the first thread in the list: */
name|pthread
operator|=
name|_thread_link_list
expr_stmt|;
comment|/* 		 * Enter a loop to find the thread in the linked list before 		 * the running thread:  		 */
while|while
condition|(
name|pthread
operator|!=
name|NULL
operator|&&
name|pthread
operator|->
name|nxt
operator|!=
name|_thread_run
condition|)
block|{
comment|/* Point to the next thread: */
name|pthread
operator|=
name|pthread
operator|->
name|nxt
expr_stmt|;
block|}
comment|/* Check that a previous thread was found: */
if|if
condition|(
name|pthread
operator|!=
name|NULL
condition|)
block|{
comment|/* 			 * Point the previous thread to the one after the 			 * running thread:  			 */
name|pthread
operator|->
name|nxt
operator|=
name|_thread_run
operator|->
name|nxt
expr_stmt|;
block|}
block|}
comment|/* Check if this is a signal handler thread: */
if|if
condition|(
name|_thread_run
operator|->
name|parent_thread
operator|!=
name|NULL
condition|)
block|{
comment|/* 		 * Enter a loop to search for other threads with the same 		 * parent:  		 */
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
comment|/* Compare the parent thread pointers: */
if|if
condition|(
name|pthread
operator|->
name|parent_thread
operator|==
name|_thread_run
operator|->
name|parent_thread
condition|)
block|{
comment|/* 				 * The parent thread is waiting on at least 				 * one other signal handler. Exit the loop 				 * now that this is known.  				 */
break|break;
block|}
block|}
comment|/* 		 * Check if the parent is not waiting on any other signal 		 * handler threads:  		 */
if|if
condition|(
name|pthread
operator|==
name|NULL
condition|)
block|{
comment|/* Allow the parent thread to run again: */
name|_thread_run
operator|->
name|parent_thread
operator|->
name|state
operator|=
name|PS_RUNNING
expr_stmt|;
block|}
comment|/* Get the signal number: */
name|l
operator|=
operator|(
name|long
operator|)
name|_thread_run
operator|->
name|arg
expr_stmt|;
name|sig
operator|=
operator|(
name|int
operator|)
name|l
expr_stmt|;
comment|/* Unblock the signal from the parent thread: */
name|sigdelset
argument_list|(
operator|&
name|_thread_run
operator|->
name|parent_thread
operator|->
name|sigmask
argument_list|,
name|sig
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * This thread will never run again. Add it to the list of dead 	 * threads:  	 */
name|_thread_run
operator|->
name|nxt
operator|=
name|_thread_dead
expr_stmt|;
name|_thread_dead
operator|=
name|_thread_run
expr_stmt|;
comment|/* 	 * The running thread is no longer in the thread link list so it will 	 * now die:  	 */
name|_thread_kern_sched_state
argument_list|(
name|PS_DEAD
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
comment|/* This point should not be reached. */
name|PANIC
argument_list|(
literal|"Dead thread has resumed"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

