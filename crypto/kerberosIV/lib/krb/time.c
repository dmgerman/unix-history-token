begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"krb_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: time.c,v 1.4 1999/12/02 16:58:44 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* number of seconds the kdc clock is ahead of us */
end_comment

begin_decl_stmt
specifier|static
name|int
name|time_diff
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|krb_set_kdc_time_diff
parameter_list|(
name|int
name|diff
parameter_list|)
block|{
name|time_diff
operator|=
name|diff
expr_stmt|;
if|if
condition|(
name|krb_debug
condition|)
name|krb_warning
argument_list|(
literal|"Setting time diff to %d\n"
argument_list|,
name|diff
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|krb_get_kdc_time_diff
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|time_diff
return|;
block|}
end_function

begin_comment
comment|/* return the time at the kdc (local time corrected with a time    differential) */
end_comment

begin_function
name|void
name|krb_kdctimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
block|{
name|time_t
name|t
decl_stmt|;
name|gettimeofday
argument_list|(
name|tv
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|t
operator|=
name|tv
operator|->
name|tv_sec
expr_stmt|;
if|if
condition|(
name|krb_debug
condition|)
name|krb_warning
argument_list|(
literal|"Machine time: %s"
argument_list|,
name|ctime
argument_list|(
operator|&
name|t
argument_list|)
argument_list|)
expr_stmt|;
name|t
operator|+=
name|krb_get_kdc_time_diff
argument_list|()
expr_stmt|;
if|if
condition|(
name|krb_debug
condition|)
name|krb_warning
argument_list|(
literal|"Correcting to %s"
argument_list|,
name|ctime
argument_list|(
operator|&
name|t
argument_list|)
argument_list|)
expr_stmt|;
name|tv
operator|->
name|tv_sec
operator|=
name|t
expr_stmt|;
block|}
end_function

end_unit

