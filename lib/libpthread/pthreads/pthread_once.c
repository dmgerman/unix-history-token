begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== pthread_once.c =======================================================  * Copyright (c) 1993, 1994 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : pthread_once function.  *  *  1.00 93/12/12 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_comment
comment|/* ==========================================================================  * pthread_once()  */
end_comment

begin_decl_stmt
specifier|static
name|pthread_mutex_t
name|__pthread_once_mutex
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|pthread_once
parameter_list|(
name|pthread_once_t
modifier|*
name|once_control
parameter_list|,
name|void
function_decl|(
modifier|*
name|init_routine
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
comment|/* Check first for speed */
if|if
condition|(
operator|*
name|once_control
operator|==
name|PTHREAD_ONCE_INIT
condition|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|__pthread_once_mutex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|once_control
operator|==
name|PTHREAD_ONCE_INIT
condition|)
block|{
name|init_routine
argument_list|()
expr_stmt|;
operator|(
operator|*
name|once_control
operator|)
operator|++
expr_stmt|;
block|}
name|pthread_mutex_unlock
argument_list|(
operator|&
name|__pthread_once_mutex
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

end_unit

