begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"krb5_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: free_host_realm.c,v 1.4 1999/12/02 17:05:09 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Free all memory allocated by `realmlist'  */
end_comment

begin_function
name|krb5_error_code
name|krb5_free_host_realm
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|krb5_realm
modifier|*
name|realmlist
parameter_list|)
block|{
name|krb5_realm
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|realmlist
operator|==
name|NULL
condition|)
return|return
literal|0
return|;
for|for
control|(
name|p
operator|=
name|realmlist
init|;
operator|*
name|p
condition|;
operator|++
name|p
control|)
name|free
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|realmlist
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

