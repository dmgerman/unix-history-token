begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: gssapi_locl.h,v 1.14 2000/08/27 04:19:00 assar Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSAPI_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|GSSAPI_LOCL_H
end_define

begin_include
include|#
directive|include
file|<krb5_locl.h>
end_include

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_decl_stmt
specifier|extern
name|krb5_context
name|gssapi_krb5_context
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|gssapi_krb5_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|gssapi_krb5_create_8003_checksum
parameter_list|(
specifier|const
name|gss_channel_bindings_t
name|input_chan_bindings
parameter_list|,
name|OM_uint32
name|flags
parameter_list|,
name|krb5_data
modifier|*
name|fwd_data
parameter_list|,
name|Checksum
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|gssapi_krb5_verify_8003_checksum
parameter_list|(
specifier|const
name|gss_channel_bindings_t
name|input_chan_bindings
parameter_list|,
name|Checksum
modifier|*
name|cksum
parameter_list|,
name|OM_uint32
modifier|*
name|flags
parameter_list|,
name|krb5_data
modifier|*
name|fwd_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gssapi_krb5_encapsulate
parameter_list|(
specifier|const
name|krb5_data
modifier|*
name|in_data
parameter_list|,
name|gss_buffer_t
name|output_token
parameter_list|,
name|u_char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gssapi_krb5_decapsulate
parameter_list|(
name|gss_buffer_t
name|input_token_buffer
parameter_list|,
name|krb5_data
modifier|*
name|out_data
parameter_list|,
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gssapi_krb5_encap_length
parameter_list|(
name|size_t
name|data_len
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|size_t
modifier|*
name|total_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
modifier|*
name|gssapi_krb5_make_header
parameter_list|(
name|u_char
modifier|*
name|p
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u_char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gssapi_krb5_verify_header
parameter_list|(
name|u_char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
name|total_len
parameter_list|,
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|gss_krb5_getsomekey
parameter_list|(
specifier|const
name|gss_ctx_id_t
name|context_handle
parameter_list|,
name|krb5_keyblock
modifier|*
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|gss_address_to_krb5addr
parameter_list|(
name|OM_uint32
name|gss_addr_type
parameter_list|,
name|gss_buffer_desc
modifier|*
name|gss_addr
parameter_list|,
name|int16_t
name|port
parameter_list|,
name|krb5_address
modifier|*
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sec_context flags */
end_comment

begin_define
define|#
directive|define
name|SC_LOCAL_ADDRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|SC_REMOTE_ADDRESS
value|0x02
end_define

begin_define
define|#
directive|define
name|SC_KEYBLOCK
value|0x04
end_define

begin_define
define|#
directive|define
name|SC_LOCAL_SUBKEY
value|0x08
end_define

begin_define
define|#
directive|define
name|SC_REMOTE_SUBKEY
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

