begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Garbage collector thread. Frees memory allocated for dead threads.  *  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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

begin_function
name|pthread_addr_t
name|_thread_gc
parameter_list|(
name|pthread_addr_t
name|arg
parameter_list|)
block|{
name|int
name|f_debug
decl_stmt|;
name|int
name|f_done
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|pthread_t
name|pthread
decl_stmt|;
name|pthread_t
name|pthread_cln
decl_stmt|;
name|pthread_t
name|pthread_nxt
decl_stmt|;
name|pthread_t
name|pthread_prv
decl_stmt|;
name|struct
name|timespec
name|abstime
decl_stmt|;
name|void
modifier|*
name|p_stack
decl_stmt|;
comment|/* Set a debug flag based on an environment variable. */
name|f_debug
operator|=
operator|(
name|getenv
argument_list|(
literal|"LIBC_R_DEBUG"
argument_list|)
operator|!=
name|NULL
operator|)
expr_stmt|;
comment|/* Set the name of this thread. */
name|pthread_set_name_np
argument_list|(
name|_thread_run
argument_list|,
literal|"GC"
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|f_done
condition|)
block|{
comment|/* Check if debugging this application. */
if|if
condition|(
name|f_debug
condition|)
comment|/* Dump thread info to file. */
name|_thread_dump_info
argument_list|()
expr_stmt|;
comment|/* Lock the thread list: */
name|_lock_thread_list
argument_list|()
expr_stmt|;
comment|/* Check if this is the last running thread: */
if|if
condition|(
name|_thread_link_list
operator|==
name|_thread_run
operator|&&
name|_thread_link_list
operator|->
name|nxt
operator|==
name|NULL
condition|)
comment|/* 			 * This is the last thread, so it can exit 			 * now. 			 */
name|f_done
operator|=
literal|1
expr_stmt|;
comment|/* Unlock the thread list: */
name|_unlock_thread_list
argument_list|()
expr_stmt|;
comment|/* 		 * Lock the garbage collector mutex which ensures that 		 * this thread sees another thread exit: 		 */
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
comment|/* No stack of thread structure to free yet: */
name|p_stack
operator|=
name|NULL
expr_stmt|;
name|pthread_cln
operator|=
name|NULL
expr_stmt|;
comment|/* Point to the first dead thread (if there are any): */
name|pthread
operator|=
name|_thread_dead
expr_stmt|;
comment|/* There is no previous dead thread: */
name|pthread_prv
operator|=
name|NULL
expr_stmt|;
comment|/* 		 * Enter a loop to search for the first dead thread that 		 * has memory to free. 		 */
while|while
condition|(
name|p_stack
operator|==
name|NULL
operator|&&
name|pthread_cln
operator|==
name|NULL
operator|&&
name|pthread
operator|!=
name|NULL
condition|)
block|{
comment|/* Save a pointer to the next thread: */
name|pthread_nxt
operator|=
name|pthread
operator|->
name|nxt_dead
expr_stmt|;
comment|/* Check if the initial thread: */
if|if
condition|(
name|pthread
operator|==
name|_thread_initial
condition|)
comment|/* Don't destroy the initial thread. */
name|pthread_prv
operator|=
name|pthread
expr_stmt|;
comment|/* 			 * Check if this thread has detached: 			 */
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
operator|!=
literal|0
condition|)
block|{
comment|/* 				 * Check if there is no previous dead 				 * thread: 				 */
if|if
condition|(
name|pthread_prv
operator|==
name|NULL
condition|)
comment|/* 					 * The dead thread is at the head 					 * of the list:  					 */
name|_thread_dead
operator|=
name|pthread_nxt
expr_stmt|;
else|else
comment|/* 					 * The dead thread is not at the 					 * head of the list:  					 */
name|pthread_prv
operator|->
name|nxt_dead
operator|=
name|pthread
operator|->
name|nxt_dead
expr_stmt|;
comment|/* 				 * Check if the stack was not specified by 				 * the caller to pthread_create and has not 				 * been destroyed yet:  				 */
if|if
condition|(
name|pthread
operator|->
name|attr
operator|.
name|stackaddr_attr
operator|==
name|NULL
operator|&&
name|pthread
operator|->
name|stack
operator|!=
name|NULL
condition|)
block|{
comment|/* 					 * Point to the stack that must 					 * be freed outside the locks: 					 */
name|p_stack
operator|=
name|pthread
operator|->
name|stack
expr_stmt|;
block|}
comment|/* 				 * Point to the thread structure that must 				 * be freed outside the locks: 				 */
name|pthread_cln
operator|=
name|pthread
expr_stmt|;
block|}
else|else
block|{
comment|/* 				 * This thread has not detached, so do 				 * not destroy it:  				 */
name|pthread_prv
operator|=
name|pthread
expr_stmt|;
comment|/* 				 * Check if the stack was not specified by 				 * the caller to pthread_create and has not 				 * been destroyed yet:  				 */
if|if
condition|(
name|pthread
operator|->
name|attr
operator|.
name|stackaddr_attr
operator|==
name|NULL
operator|&&
name|pthread
operator|->
name|stack
operator|!=
name|NULL
condition|)
block|{
comment|/* 					 * Point to the stack that must 					 * be freed outside the locks: 					 */
name|p_stack
operator|=
name|pthread
operator|->
name|stack
expr_stmt|;
comment|/* 					 * NULL the stack pointer now 					 * that the memory has been freed:  					 */
name|pthread
operator|->
name|stack
operator|=
name|NULL
expr_stmt|;
block|}
block|}
comment|/* Point to the next thread: */
name|pthread
operator|=
name|pthread_nxt
expr_stmt|;
block|}
comment|/* 		 * Check if this is not the last thread and there is no 		 * memory to free this time around. 		 */
if|if
condition|(
operator|!
name|f_done
operator|&&
name|p_stack
operator|==
name|NULL
operator|&&
name|pthread_cln
operator|==
name|NULL
condition|)
block|{
comment|/* Get the current time.                           *                          * Note that we can't use clock_gettime(2) on 2.2.x;                          * use gettimeofday(2) instead.                          */
name|struct
name|timeval
name|abstimeval
decl_stmt|;
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|abstimeval
argument_list|,
name|NULL
argument_list|)
operator|!=
literal|0
condition|)
name|PANIC
argument_list|(
literal|"gc cannot get time"
argument_list|)
expr_stmt|;
name|TIMEVAL_TO_TIMESPEC
argument_list|(
operator|&
name|abstimeval
argument_list|,
operator|&
name|abstime
argument_list|)
expr_stmt|;
comment|/* 			 * Do a backup poll in 10 seconds if no threads 			 * die before then. 			 */
name|abstime
operator|.
name|tv_sec
operator|+=
literal|10
expr_stmt|;
comment|/* 			 * Wait for a signal from a dying thread or a 			 * timeout (for a backup poll). 			 */
if|if
condition|(
operator|(
name|ret
operator|=
name|pthread_cond_timedwait
argument_list|(
operator|&
name|_gc_cond
argument_list|,
operator|&
name|_gc_mutex
argument_list|,
operator|&
name|abstime
argument_list|)
operator|)
operator|!=
literal|0
operator|&&
name|ret
operator|!=
name|ETIMEDOUT
condition|)
name|PANIC
argument_list|(
literal|"gc cannot wait for a signal"
argument_list|)
expr_stmt|;
block|}
comment|/* Unlock the garbage collector mutex: */
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
comment|/* 		 * If there is memory to free, do it now. The call to 		 * free() might block, so this must be done outside the 		 * locks. 		 */
if|if
condition|(
name|p_stack
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|p_stack
argument_list|)
expr_stmt|;
if|if
condition|(
name|pthread_cln
operator|!=
name|NULL
condition|)
block|{
comment|/* Lock the thread list: */
name|_lock_thread_list
argument_list|()
expr_stmt|;
comment|/* 			 * Check if the thread is at the head of the 			 * linked list. 			 */
if|if
condition|(
name|_thread_link_list
operator|==
name|pthread_cln
condition|)
comment|/* There is no previous thread: */
name|_thread_link_list
operator|=
name|pthread_cln
operator|->
name|nxt
expr_stmt|;
else|else
block|{
comment|/* Point to the first thread in the list: */
name|pthread
operator|=
name|_thread_link_list
expr_stmt|;
comment|/* 				 * Enter a loop to find the thread in the 				 * linked list before the thread that is 				 * about to be freed. 				 */
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
name|pthread_cln
condition|)
comment|/* Point to the next thread: */
name|pthread
operator|=
name|pthread
operator|->
name|nxt
expr_stmt|;
comment|/* Check that a previous thread was found: */
if|if
condition|(
name|pthread
operator|!=
name|NULL
condition|)
block|{
comment|/* 					 * Point the previous thread to 					 * the one after the thread being 					 * freed:  					 */
name|pthread
operator|->
name|nxt
operator|=
name|pthread_cln
operator|->
name|nxt
expr_stmt|;
block|}
block|}
comment|/* Unlock the thread list: */
name|_unlock_thread_list
argument_list|()
expr_stmt|;
comment|/* 			 * Free the memory allocated for the thread 			 * structure. 			 */
name|free
argument_list|(
name|pthread_cln
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

