begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/* $Id: hprop.h,v 1.7 1999/12/02 17:04:59 joda Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HPROP_H__
end_ifndef

begin_define
define|#
directive|define
name|__HPROP_H__
end_define

begin_include
include|#
directive|include
file|"headers.h"
end_include

begin_define
define|#
directive|define
name|HPROP_VERSION
value|"hprop-0.0"
end_define

begin_define
define|#
directive|define
name|HPROP_NAME
value|"hprop"
end_define

begin_define
define|#
directive|define
name|HPROP_KEYTAB
value|"FILE:/etc/hprop.keytab"
end_define

begin_define
define|#
directive|define
name|HPROP_PORT
value|754
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NEVERDATE
end_ifndef

begin_define
define|#
directive|define
name|NEVERDATE
value|((1U<< 31) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|krb5_error_code
name|send_priv
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_auth_context
parameter_list|,
name|krb5_data
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|recv_priv
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_auth_context
parameter_list|,
name|int
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|send_clear
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|int
name|fd
parameter_list|,
name|krb5_data
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|recv_clear
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|int
name|fd
parameter_list|,
name|krb5_data
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HPROP_H__ */
end_comment

end_unit

