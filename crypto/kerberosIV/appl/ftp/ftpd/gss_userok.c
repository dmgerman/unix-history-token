begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"ftpd_locl.h"
end_include

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: gss_userok.c,v 1.2 1999/12/02 16:58:31 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX a bit too much of krb5 dependency here...     What is the correct way to do this?     */
end_comment

begin_decl_stmt
specifier|extern
name|krb5_context
name|gssapi_krb5_context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX sync with gssapi.c */
end_comment

begin_struct
struct|struct
name|gss_data
block|{
name|gss_ctx_id_t
name|context_hdl
decl_stmt|;
name|char
modifier|*
name|client_name
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|gss_userok
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* to keep gcc happy */
end_comment

begin_function
name|int
name|gss_userok
parameter_list|(
name|void
modifier|*
name|app_data
parameter_list|,
name|char
modifier|*
name|username
parameter_list|)
block|{
name|struct
name|gss_data
modifier|*
name|data
init|=
name|app_data
decl_stmt|;
if|if
condition|(
name|gssapi_krb5_context
condition|)
block|{
name|krb5_principal
name|client
decl_stmt|;
name|krb5_error_code
name|ret
decl_stmt|;
name|ret
operator|=
name|krb5_parse_name
argument_list|(
name|gssapi_krb5_context
argument_list|,
name|data
operator|->
name|client_name
argument_list|,
operator|&
name|client
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
condition|)
return|return
literal|1
return|;
name|ret
operator|=
name|krb5_kuserok
argument_list|(
name|gssapi_krb5_context
argument_list|,
name|client
argument_list|,
name|username
argument_list|)
expr_stmt|;
name|krb5_free_principal
argument_list|(
name|gssapi_krb5_context
argument_list|,
name|client
argument_list|)
expr_stmt|;
return|return
operator|!
name|ret
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

end_unit

