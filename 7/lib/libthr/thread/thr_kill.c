begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

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

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_pthread_kill
argument_list|,
name|pthread_kill
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_pthread_kill
parameter_list|(
name|pthread_t
name|pthread
parameter_list|,
name|int
name|sig
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
name|int
name|ret
decl_stmt|;
comment|/* Check for invalid signal numbers: */
if|if
condition|(
name|sig
operator|<
literal|0
operator|||
name|sig
operator|>
name|_SIG_MAXSIG
condition|)
comment|/* Invalid signal: */
name|ret
operator|=
name|EINVAL
expr_stmt|;
comment|/* 	 * Ensure the thread is in the list of active threads, and the 	 * signal is valid (signal 0 specifies error checking only) and 	 * not being ignored: 	 */
elseif|else
if|if
condition|(
operator|(
name|ret
operator|=
name|_thr_ref_add
argument_list|(
name|curthread
argument_list|,
name|pthread
argument_list|,
comment|/*include dead*/
literal|0
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|sig
operator|>
literal|0
condition|)
name|_thr_send_sig
argument_list|(
name|pthread
argument_list|,
name|sig
argument_list|)
expr_stmt|;
name|_thr_ref_delete
argument_list|(
name|curthread
argument_list|,
name|pthread
argument_list|)
expr_stmt|;
block|}
comment|/* Return the completion status: */
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

