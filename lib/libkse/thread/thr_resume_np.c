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
name|pthread_resume_np
parameter_list|(
name|pthread_t
name|thread
parameter_list|)
block|{
name|int
name|ret
init|=
operator|-
literal|1
decl_stmt|;
name|pthread_t
name|pthread
decl_stmt|;
comment|/* 	 * Search for the thread in the linked list. 	 */
for|for
control|(
name|pthread
operator|=
name|_thread_link_list
init|;
name|pthread
operator|!=
name|NULL
operator|&&
name|ret
operator|==
operator|-
literal|1
condition|;
name|pthread
operator|=
name|pthread
operator|->
name|nxt
control|)
block|{
comment|/* Is this the thread? */
if|if
condition|(
name|pthread
operator|==
name|thread
condition|)
block|{
comment|/* Found the thread. Is it suspended? */
if|if
condition|(
name|pthread
operator|->
name|state
operator|==
name|PS_SUSPENDED
condition|)
block|{
comment|/* Allow the thread to run. */
name|pthread
operator|->
name|state
operator|=
name|PS_RUNNING
expr_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pthread
operator|->
name|state
operator|==
name|PS_RUNNING
condition|)
block|{
comment|/* Thread is already running. */
name|ret
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|/* Thread is in some other state. */
name|_thread_seterrno
argument_list|(
name|_thread_run
argument_list|,
name|EINVAL
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/* Check if thread was not found. */
if|if
condition|(
name|ret
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* No such thread */
name|_thread_seterrno
argument_list|(
name|_thread_run
argument_list|,
name|ESRCH
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

