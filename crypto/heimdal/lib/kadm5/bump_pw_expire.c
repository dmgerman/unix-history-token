begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"kadm5_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: bump_pw_expire.c,v 1.1 2000/07/24 03:47:54 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * extend password_expiration if it's defined  */
end_comment

begin_function
name|kadm5_ret_t
name|_kadm5_bump_pw_expire
parameter_list|(
name|kadm5_server_context
modifier|*
name|context
parameter_list|,
name|hdb_entry
modifier|*
name|ent
parameter_list|)
block|{
if|if
condition|(
name|ent
operator|->
name|pw_end
operator|!=
name|NULL
condition|)
block|{
name|time_t
name|life
decl_stmt|;
name|life
operator|=
name|krb5_config_get_time_default
argument_list|(
name|context
operator|->
name|context
argument_list|,
name|NULL
argument_list|,
literal|365
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
argument_list|,
literal|"kadmin"
argument_list|,
literal|"password_lifetime"
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
operator|*
operator|(
name|ent
operator|->
name|pw_end
operator|)
operator|=
name|time
argument_list|(
name|NULL
argument_list|)
operator|+
name|life
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

