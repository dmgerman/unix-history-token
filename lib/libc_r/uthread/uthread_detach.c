begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_function
name|int
name|pthread_detach
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
name|int
name|status
decl_stmt|;
name|pthread_t
name|next_thread
decl_stmt|;
comment|/* Block signals: */
name|_thread_kern_sig_block
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* Check for invalid calling parameters: */
if|if
condition|(
name|pthread
operator|==
name|NULL
condition|)
block|{
comment|/* Return an invalid argument error: */
name|rval
operator|=
name|EINVAL
expr_stmt|;
block|}
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
comment|/* Enter a loop to bring all threads off the join queue: */
while|while
condition|(
operator|(
name|next_thread
operator|=
name|_thread_queue_deq
argument_list|(
operator|&
name|pthread
operator|->
name|join_queue
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
comment|/* Make the thread run: */
name|PTHREAD_NEW_STATE
argument_list|(
name|next_thread
argument_list|,
name|PS_RUNNING
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Return an error: */
name|rval
operator|=
name|EINVAL
expr_stmt|;
block|}
comment|/* Unblock signals: */
name|_thread_kern_sig_unblock
argument_list|(
name|status
argument_list|)
expr_stmt|;
comment|/* Return the completion status: */
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

