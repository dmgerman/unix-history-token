begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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
name|pthread_kill
parameter_list|(
name|pthread_t
name|pthread
parameter_list|,
name|int
name|sig
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
name|p_pthread
decl_stmt|;
comment|/* Check for invalid signal numbers: */
if|if
condition|(
name|sig
operator|<
literal|0
operator|||
name|sig
operator|>=
name|NSIG
condition|)
comment|/* Invalid signal: */
name|rval
operator|=
name|EINVAL
expr_stmt|;
else|else
block|{
comment|/* Assume that the search will succeed: */
name|rval
operator|=
literal|0
expr_stmt|;
comment|/* Block signals: */
name|_thread_kern_sig_block
argument_list|(
operator|&
name|status
argument_list|)
expr_stmt|;
comment|/* Search for the thread: */
name|p_pthread
operator|=
name|_thread_link_list
expr_stmt|;
while|while
condition|(
name|p_pthread
operator|!=
name|NULL
operator|&&
name|p_pthread
operator|!=
name|pthread
condition|)
block|{
name|p_pthread
operator|=
name|p_pthread
operator|->
name|nxt
expr_stmt|;
block|}
comment|/* Check if the thread was not found: */
if|if
condition|(
name|p_pthread
operator|==
name|NULL
condition|)
comment|/* Can't find the thread: */
name|rval
operator|=
name|ESRCH
expr_stmt|;
else|else
comment|/* Increment the pending signal count: */
name|p_pthread
operator|->
name|sigpend
index|[
name|sig
index|]
operator|+=
literal|1
expr_stmt|;
comment|/* Unblock signals: */
name|_thread_kern_sig_unblock
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
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

