begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Timeval stuff  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: timeval.c,v 1.1 2000/03/03 09:02:42 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"roken.h"
end_include

begin_comment
comment|/*  * Make `t1' consistent.  */
end_comment

begin_function
name|void
name|timevalfix
parameter_list|(
name|struct
name|timeval
modifier|*
name|t1
parameter_list|)
block|{
if|if
condition|(
name|t1
operator|->
name|tv_usec
operator|<
literal|0
condition|)
block|{
name|t1
operator|->
name|tv_sec
operator|--
expr_stmt|;
name|t1
operator|->
name|tv_usec
operator|+=
literal|1000000
expr_stmt|;
block|}
if|if
condition|(
name|t1
operator|->
name|tv_usec
operator|>=
literal|1000000
condition|)
block|{
name|t1
operator|->
name|tv_sec
operator|++
expr_stmt|;
name|t1
operator|->
name|tv_usec
operator|-=
literal|1000000
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * t1 += t2  */
end_comment

begin_function
name|void
name|timevaladd
parameter_list|(
name|struct
name|timeval
modifier|*
name|t1
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|t2
parameter_list|)
block|{
name|t1
operator|->
name|tv_sec
operator|+=
name|t2
operator|->
name|tv_sec
expr_stmt|;
name|t1
operator|->
name|tv_usec
operator|+=
name|t2
operator|->
name|tv_usec
expr_stmt|;
name|timevalfix
argument_list|(
name|t1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * t1 -= t2  */
end_comment

begin_function
name|void
name|timevalsub
parameter_list|(
name|struct
name|timeval
modifier|*
name|t1
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|t2
parameter_list|)
block|{
name|t1
operator|->
name|tv_sec
operator|-=
name|t2
operator|->
name|tv_sec
expr_stmt|;
name|t1
operator|->
name|tv_usec
operator|-=
name|t2
operator|->
name|tv_usec
expr_stmt|;
name|timevalfix
argument_list|(
name|t1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

