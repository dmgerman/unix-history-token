begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: arcfour.h,v 1.3.2.2 2003/09/19 15:14:14 lha Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_ARCFOUR_H_
end_ifndef

begin_define
define|#
directive|define
name|GSSAPI_ARCFOUR_H_
value|1
end_define

begin_comment
comment|/*  * The arcfour message have the following formats, these are only here  * for reference and is not used.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|typedef struct gss_arcfour_mic_token {     u_char TOK_ID[2];
comment|/* 01 01 */
end_comment

begin_comment
unit|u_char SGN_ALG[2];
comment|/* 11 00 */
end_comment

begin_comment
unit|u_char Filler[4];     u_char SND_SEQ[8];     u_char SGN_CKSUM[8]; } gss_arcfour_mic_token_desc, *gss_arcfour_mic_token;  typedef struct gss_arcfour_wrap_token {     u_char TOK_ID[2];
comment|/* 02 01 */
end_comment

begin_endif
unit|u_char SGN_ALG[2];     u_char SEAL_ALG[2];     u_char Filler[2];     u_char SND_SEQ[8];     u_char SGN_CKSUM[8];     u_char Confounder[8]; } gss_arcfour_wrap_token_desc, *gss_arcfour_wrap_token;
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GSS_ARCFOUR_WRAP_TOKEN_SIZE
value|32
end_define

begin_function_decl
name|OM_uint32
name|_gssapi_wrap_arcfour
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|int
name|conf_req_flag
parameter_list|,
name|gss_qop_t
name|qop_req
parameter_list|,
specifier|const
name|gss_buffer_t
name|input_message_buffer
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|gss_buffer_t
name|output_message_buffer
parameter_list|,
name|krb5_keyblock
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|_gssapi_unwrap_arcfour
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
specifier|const
name|gss_buffer_t
name|input_message_buffer
parameter_list|,
name|gss_buffer_t
name|output_message_buffer
parameter_list|,
name|int
modifier|*
name|conf_state
parameter_list|,
name|gss_qop_t
modifier|*
name|qop_state
parameter_list|,
name|krb5_keyblock
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|_gssapi_get_mic_arcfour
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|gss_qop_t
name|qop_req
parameter_list|,
specifier|const
name|gss_buffer_t
name|message_buffer
parameter_list|,
name|gss_buffer_t
name|message_token
parameter_list|,
name|krb5_keyblock
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|_gssapi_verify_mic_arcfour
parameter_list|(
name|OM_uint32
modifier|*
name|minor_status
parameter_list|,
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
specifier|const
name|gss_buffer_t
name|message_buffer
parameter_list|,
specifier|const
name|gss_buffer_t
name|token_buffer
parameter_list|,
name|gss_qop_t
modifier|*
name|qop_state
parameter_list|,
name|krb5_keyblock
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GSSAPI_ARCFOUR_H_ */
end_comment

end_unit

