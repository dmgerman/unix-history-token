begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"kadm5_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: destroy_s.c,v 1.5 1999/12/02 17:05:05 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|kadm5_ret_t
name|kadm5_s_destroy
parameter_list|(
name|void
modifier|*
name|server_handle
parameter_list|)
block|{
name|kadm5_ret_t
name|ret
decl_stmt|;
name|kadm5_server_context
modifier|*
name|context
init|=
name|server_handle
decl_stmt|;
name|krb5_context
name|kcontext
init|=
name|context
operator|->
name|context
decl_stmt|;
name|ret
operator|=
name|context
operator|->
name|db
operator|->
name|destroy
argument_list|(
name|kcontext
argument_list|,
name|context
operator|->
name|db
argument_list|)
expr_stmt|;
if|if
condition|(
name|context
operator|->
name|my_context
condition|)
name|krb5_free_context
argument_list|(
name|kcontext
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

