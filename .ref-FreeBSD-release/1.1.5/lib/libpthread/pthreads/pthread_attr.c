begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== pthread_attr.c =======================================================  * Copyright (c) 1993, 1994 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : Pthread attribute functions.  *  *  1.00 93/11/04 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Currently we do no locking, should we just to be safe? CAP */
end_comment

begin_comment
comment|/* ==========================================================================  * pthread_attr_init()  */
end_comment

begin_function
name|int
name|pthread_attr_init
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|)
block|{
name|memcpy
argument_list|(
name|attr
argument_list|,
operator|&
name|pthread_default_attr
argument_list|,
sizeof|sizeof
argument_list|(
name|pthread_attr_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_destroy()  */
end_comment

begin_function
name|int
name|pthread_attr_destroy
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|)
block|{
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_getstacksize()  */
end_comment

begin_function
name|int
name|pthread_attr_getstacksize
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|size_t
modifier|*
name|stacksize
parameter_list|)
block|{
operator|*
name|stacksize
operator|=
name|attr
operator|->
name|stacksize_attr
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_setstacksize()  */
end_comment

begin_function
name|int
name|pthread_attr_setstacksize
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|size_t
name|stacksize
parameter_list|)
block|{
if|if
condition|(
name|stacksize
operator|>=
name|PTHREAD_STACK_MIN
condition|)
block|{
name|attr
operator|->
name|stacksize_attr
operator|=
name|stacksize
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_getstackaddr()  */
end_comment

begin_function
name|int
name|pthread_attr_getstackaddr
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|void
modifier|*
modifier|*
name|stackaddr
parameter_list|)
block|{
operator|*
name|stackaddr
operator|=
name|attr
operator|->
name|stackaddr_attr
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_setstackaddr()  */
end_comment

begin_function
name|int
name|pthread_attr_setstackaddr
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|void
modifier|*
name|stackaddr
parameter_list|)
block|{
name|attr
operator|->
name|stackaddr_attr
operator|=
name|stackaddr
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

end_unit

