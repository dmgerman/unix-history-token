begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Benno Rice  * Copyright (c) 2007 Semihalf, Rafal Jaworowski<raj@semihalf.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"glue.h"
end_include

begin_comment
comment|/*  * Return the time in seconds since the beginning of the day.  */
end_comment

begin_function
name|time_t
name|time
parameter_list|(
name|time_t
modifier|*
name|tloc
parameter_list|)
block|{
name|int
name|secs
decl_stmt|;
name|secs
operator|=
name|ub_get_timer
argument_list|(
literal|0
argument_list|)
operator|/
literal|1000
expr_stmt|;
if|if
condition|(
name|tloc
condition|)
operator|*
name|tloc
operator|=
name|secs
expr_stmt|;
return|return
operator|(
name|secs
operator|)
return|;
block|}
end_function

begin_function
name|time_t
name|getsecs
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|time
argument_list|(
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Use U-Boot udelay() function to wait for a given microseconds period  */
end_comment

begin_function
name|void
name|delay
parameter_list|(
name|int
name|usecs
parameter_list|)
block|{
name|ub_udelay
argument_list|(
name|usecs
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

