begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 - 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_include
include|#
directive|include
file|"gssapi_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: display_status.c,v 1.7 2001/08/23 04:34:41 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|krb5_error_string
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|char
modifier|*
name|calling_error
parameter_list|(
name|OM_uint32
name|v
parameter_list|)
block|{
specifier|static
name|char
modifier|*
name|msgs
index|[]
init|=
block|{
name|NULL
block|,
comment|/* 0 */
literal|"A required input parameter could not be read."
block|,
comment|/*  */
literal|"A required output parameter could not be written."
block|,
comment|/*  */
literal|"A parameter was malformed"
block|}
decl_stmt|;
name|v
operator|>>=
name|GSS_C_CALLING_ERROR_OFFSET
expr_stmt|;
if|if
condition|(
name|v
operator|==
literal|0
condition|)
return|return
literal|""
return|;
elseif|else
if|if
condition|(
name|v
operator|>=
sizeof|sizeof
argument_list|(
name|msgs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|msgs
argument_list|)
condition|)
return|return
literal|"unknown calling error"
return|;
else|else
return|return
name|msgs
index|[
name|v
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|char
modifier|*
name|routine_error
parameter_list|(
name|OM_uint32
name|v
parameter_list|)
block|{
specifier|static
name|char
modifier|*
name|msgs
index|[]
init|=
block|{
name|NULL
block|,
comment|/* 0 */
literal|"An unsupported mechanism was requested"
block|,
literal|"An invalid name was supplied"
block|,
literal|"A supplied name was of an unsupported type"
block|,
literal|"Incorrect channel bindings were supplied"
block|,
literal|"An invalid status code was supplied"
block|,
literal|"A token had an invalid MIC"
block|,
literal|"No credentials were supplied, "
literal|"or the credentials were unavailable or inaccessible."
block|,
literal|"No context has been established"
block|,
literal|"A token was invalid"
block|,
literal|"A credential was invalid"
block|,
literal|"The referenced credentials have expired"
block|,
literal|"The context has expired"
block|,
literal|"Miscellaneous failure (see text)"
block|,
literal|"The quality-of-protection requested could not be provide"
block|,
literal|"The operation is forbidden by local security policy"
block|,
literal|"The operation or option is not available"
block|,
literal|"The requested credential element already exists"
block|,
literal|"The provided name was not a mechanism name."
block|,     }
decl_stmt|;
name|v
operator|>>=
name|GSS_C_ROUTINE_ERROR_OFFSET
expr_stmt|;
if|if
condition|(
name|v
operator|==
literal|0
condition|)
return|return
literal|""
return|;
elseif|else
if|if
condition|(
name|v
operator|>=
sizeof|sizeof
argument_list|(
name|msgs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|msgs
argument_list|)
condition|)
return|return
literal|"unknown routine error"
return|;
else|else
return|return
name|msgs
index|[
name|v
index|]
return|;
block|}
end_function

begin_function
name|void
name|gssapi_krb5_set_error_string
parameter_list|(
name|void
parameter_list|)
block|{
name|krb5_error_string
operator|=
name|krb5_get_error_string
argument_list|(
name|gssapi_krb5_context
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|char
modifier|*
name|gssapi_krb5_get_error_string
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|ret
init|=
name|krb5_error_string
decl_stmt|;
name|krb5_error_string
operator|=
name|NULL
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|OM_uint32
name|gss_display_status
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
name|OM_uint32
name|status_value
parameter_list|,
name|int
name|status_type
parameter_list|,
specifier|const
name|gss_OID
name|mech_type
parameter_list|,
name|OM_uint32
modifier|*
name|message_context
parameter_list|,
name|gss_buffer_t
name|status_string
parameter_list|)
block|{
name|char
modifier|*
name|buf
decl_stmt|;
name|gssapi_krb5_init
argument_list|()
expr_stmt|;
operator|*
name|minor_status
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|mech_type
operator|!=
name|GSS_C_NO_OID
operator|&&
name|mech_type
operator|!=
name|GSS_KRB5_MECHANISM
condition|)
return|return
name|GSS_S_BAD_MECH
return|;
if|if
condition|(
name|status_type
operator|==
name|GSS_C_GSS_CODE
condition|)
block|{
name|asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"%s %s"
argument_list|,
name|calling_error
argument_list|(
name|GSS_CALLING_ERROR
argument_list|(
name|status_value
argument_list|)
argument_list|)
argument_list|,
name|routine_error
argument_list|(
name|GSS_ROUTINE_ERROR
argument_list|(
name|status_value
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|status_type
operator|==
name|GSS_C_MECH_CODE
condition|)
block|{
name|buf
operator|=
name|gssapi_krb5_get_error_string
argument_list|()
expr_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
block|{
specifier|const
name|char
modifier|*
name|tmp
init|=
name|krb5_get_err_text
argument_list|(
name|gssapi_krb5_context
argument_list|,
name|status_value
argument_list|)
decl_stmt|;
if|if
condition|(
name|tmp
operator|==
name|NULL
condition|)
name|asprintf
argument_list|(
operator|&
name|buf
argument_list|,
literal|"unknown mech error-code %u"
argument_list|,
operator|(
name|unsigned
operator|)
name|status_value
argument_list|)
expr_stmt|;
else|else
name|buf
operator|=
name|strdup
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
block|}
block|}
else|else
return|return
name|GSS_S_BAD_STATUS
return|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
block|{
operator|*
name|minor_status
operator|=
name|ENOMEM
expr_stmt|;
return|return
name|GSS_S_FAILURE
return|;
block|}
operator|*
name|message_context
operator|=
literal|0
expr_stmt|;
name|status_string
operator|->
name|length
operator|=
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|status_string
operator|->
name|value
operator|=
name|buf
expr_stmt|;
return|return
name|GSS_S_COMPLETE
return|;
block|}
end_function

end_unit

