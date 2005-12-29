begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<gssapi/gssapi.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"mech_switch.h"
end_include

begin_struct
struct|struct
name|_gss_status_desc
block|{
name|OM_uint32
name|gs_status
decl_stmt|;
specifier|const
name|char
modifier|*
name|gs_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|_gss_status_desc
name|_gss_status_descs
index|[]
init|=
block|{
name|GSS_S_BAD_MECH
block|,
literal|"An unsupported mechanism was requested"
block|,
name|GSS_S_BAD_NAME
block|,
literal|"An invalid name was supplied"
block|,
name|GSS_S_BAD_NAMETYPE
block|,
literal|"A supplied name was of an unsupported type"
block|,
name|GSS_S_BAD_BINDINGS
block|,
literal|"Incorrect channel bindings were supplied"
block|,
name|GSS_S_BAD_STATUS
block|,
literal|"An invalid status code was supplied"
block|,
name|GSS_S_BAD_MIC
block|,
literal|"A token had an invalid MIC"
block|,
name|GSS_S_NO_CRED
block|,
literal|"No credentials were supplied, or the "
literal|"credentials were unavailable or inaccessible"
block|,
name|GSS_S_NO_CONTEXT
block|,
literal|"No context has been established"
block|,
name|GSS_S_DEFECTIVE_TOKEN
block|,
literal|"A token was invalid"
block|,
name|GSS_S_DEFECTIVE_CREDENTIAL
block|,
literal|"A credential was invalid"
block|,
name|GSS_S_CREDENTIALS_EXPIRED
block|,
literal|"The referenced credentials have expired"
block|,
name|GSS_S_CONTEXT_EXPIRED
block|,
literal|"The context has expired"
block|,
name|GSS_S_FAILURE
block|,
literal|"Miscellaneous failure"
block|,
name|GSS_S_BAD_QOP
block|,
literal|"The quality-of-protection requested could "
literal|"not be provided"
block|,
name|GSS_S_UNAUTHORIZED
block|,
literal|"The operation is forbidden by local security "
literal|"policy"
block|,
name|GSS_S_UNAVAILABLE
block|,
literal|"The operation or option is unavailable"
block|,
name|GSS_S_DUPLICATE_ELEMENT
block|,
literal|"The requested credential element already "
literal|"exists"
block|,
name|GSS_S_NAME_NOT_MN
block|,
literal|"The provided name was not a mechanism name"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_gss_status_desc_count
define|\
value|sizeof(_gss_status_descs) / sizeof(_gss_status_descs[0])
end_define

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
name|message_content
parameter_list|,
name|gss_buffer_t
name|status_string
parameter_list|)
block|{
name|OM_uint32
name|major_status
decl_stmt|;
name|struct
name|_gss_mech_switch
modifier|*
name|m
decl_stmt|;
name|int
name|i
decl_stmt|;
specifier|const
name|char
modifier|*
name|message
decl_stmt|;
operator|*
name|minor_status
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|status_type
condition|)
block|{
case|case
name|GSS_C_GSS_CODE
case|:
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|_gss_status_desc_count
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|_gss_status_descs
index|[
name|i
index|]
operator|.
name|gs_status
operator|==
name|status_value
condition|)
block|{
name|message
operator|=
name|_gss_status_descs
index|[
name|i
index|]
operator|.
name|gs_desc
expr_stmt|;
name|status_string
operator|->
name|length
operator|=
name|strlen
argument_list|(
name|message
argument_list|)
expr_stmt|;
name|status_string
operator|->
name|value
operator|=
name|strdup
argument_list|(
name|message
argument_list|)
expr_stmt|;
return|return
operator|(
name|GSS_S_COMPLETE
operator|)
return|;
block|}
block|}
comment|/* 		 * Fall through to attempt to get some underlying 		 * implementation to describe the value. 		 */
case|case
name|GSS_C_MECH_CODE
case|:
name|SLIST_FOREACH
argument_list|(
argument|m
argument_list|,
argument|&_gss_mechs
argument_list|,
argument|gm_link
argument_list|)
block|{
if|if
condition|(
name|mech_type
operator|&&
operator|!
name|_gss_oid_equal
argument_list|(
operator|&
name|m
operator|->
name|gm_mech_oid
argument_list|,
name|mech_type
argument_list|)
condition|)
continue|continue;
name|major_status
operator|=
name|m
operator|->
name|gm_display_status
argument_list|(
name|minor_status
argument_list|,
name|status_value
argument_list|,
name|status_type
argument_list|,
name|mech_type
argument_list|,
name|message_content
argument_list|,
name|status_string
argument_list|)
expr_stmt|;
if|if
condition|(
name|major_status
operator|==
name|GSS_S_COMPLETE
condition|)
return|return
operator|(
name|GSS_S_COMPLETE
operator|)
return|;
block|}
block|}
return|return
operator|(
name|GSS_S_BAD_STATUS
operator|)
return|;
block|}
end_function

end_unit

