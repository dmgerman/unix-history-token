begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
comment|/* Find a thread in the linked list of active threads: */
end_comment

begin_function
name|int
name|_find_thread
parameter_list|(
name|pthread_t
name|pthread
parameter_list|)
block|{
name|pthread_t
name|pthread1
decl_stmt|;
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
comment|/* Invalid thread: */
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* Lock the thread list: */
name|_lock_thread_list
argument_list|()
expr_stmt|;
comment|/* Point to the first thread in the list: */
name|pthread1
operator|=
name|_thread_link_list
expr_stmt|;
comment|/* Search for the thread to join to: */
while|while
condition|(
name|pthread1
operator|!=
name|NULL
operator|&&
name|pthread1
operator|!=
name|pthread
condition|)
block|{
comment|/* Point to the next thread: */
name|pthread1
operator|=
name|pthread1
operator|->
name|nxt
expr_stmt|;
block|}
comment|/* Unlock the thread list: */
name|_unlock_thread_list
argument_list|()
expr_stmt|;
comment|/* Return zero if the thread exists: */
return|return
operator|(
operator|(
name|pthread1
operator|!=
name|NULL
operator|)
condition|?
literal|0
else|:
name|ESRCH
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Find a thread in the linked list of dead threads: */
end_comment

begin_function
name|int
name|_find_dead_thread
parameter_list|(
name|pthread_t
name|pthread
parameter_list|)
block|{
name|pthread_t
name|pthread1
decl_stmt|;
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
comment|/* Invalid thread: */
return|return
operator|(
name|EINVAL
operator|)
return|;
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
comment|/* Point to the first thread in the list: */
name|pthread1
operator|=
name|_thread_dead
expr_stmt|;
comment|/* Search for the thread to join to: */
while|while
condition|(
name|pthread1
operator|!=
name|NULL
operator|&&
name|pthread1
operator|!=
name|pthread
condition|)
block|{
comment|/* Point to the next thread: */
name|pthread1
operator|=
name|pthread1
operator|->
name|nxt_dead
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
literal|"Cannot lock gc mutex"
argument_list|)
expr_stmt|;
comment|/* Return zero if the thread exists: */
return|return
operator|(
operator|(
name|pthread1
operator|!=
name|NULL
operator|)
condition|?
literal|0
else|:
name|ESRCH
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

