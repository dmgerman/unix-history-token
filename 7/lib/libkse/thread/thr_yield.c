begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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

begin_expr_stmt
name|LT10_COMPAT_PRIVATE
argument_list|(
name|_sched_yield
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LT10_COMPAT_DEFAULT
argument_list|(
name|sched_yield
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LT10_COMPAT_PRIVATE
argument_list|(
name|_pthread_yield
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LT10_COMPAT_DEFAULT
argument_list|(
name|pthread_yield
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_sched_yield
argument_list|,
name|sched_yield
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_yield
argument_list|,
name|pthread_yield
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_sched_yield
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
if|if
condition|(
name|curthread
operator|->
name|attr
operator|.
name|flags
operator|&
name|PTHREAD_SCOPE_SYSTEM
condition|)
return|return
operator|(
name|__sys_sched_yield
argument_list|()
operator|)
return|;
comment|/* Reset the accumulated time slice value for the current thread: */
name|curthread
operator|->
name|slice_usec
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Schedule the next thread: */
name|_thr_sched_switch
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
comment|/* Always return no error. */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Draft 4 yield */
end_comment

begin_function
name|void
name|_pthread_yield
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
if|if
condition|(
name|curthread
operator|->
name|attr
operator|.
name|flags
operator|&
name|PTHREAD_SCOPE_SYSTEM
condition|)
block|{
name|__sys_sched_yield
argument_list|()
expr_stmt|;
return|return;
block|}
comment|/* Reset the accumulated time slice value for the current thread: */
name|curthread
operator|->
name|slice_usec
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Schedule the next thread: */
name|_thr_sched_switch
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

