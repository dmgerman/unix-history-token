begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/* 	 * Defer signals to protect the thread list from access 	 * by the signal handler: 	 */
name|_thread_kern_sig_defer
argument_list|()
expr_stmt|;
comment|/* Search for the specified thread: */
name|TAILQ_FOREACH
argument_list|(
argument|pthread1
argument_list|,
argument|&_thread_list
argument_list|,
argument|tle
argument_list|)
block|{
if|if
condition|(
name|pthread
operator|==
name|pthread1
condition|)
break|break;
block|}
comment|/* Undefer and handle pending signals, yielding if necessary: */
name|_thread_kern_sig_undefer
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

end_unit

