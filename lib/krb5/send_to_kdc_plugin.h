begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_KRB5_SEND_TO_KDC_PLUGIN_H
end_ifndef

begin_define
define|#
directive|define
name|HEIMDAL_KRB5_SEND_TO_KDC_PLUGIN_H
value|1
end_define

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_define
define|#
directive|define
name|KRB5_PLUGIN_SEND_TO_KDC
value|"send_to_kdc"
end_define

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
modifier|*
name|krb5plugin_send_to_kdc_func
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|void
modifier|*
parameter_list|,
name|krb5_krbhst_info
modifier|*
parameter_list|,
name|time_t
name|timeout
parameter_list|,
specifier|const
name|krb5_data
modifier|*
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5plugin_send_to_kdc_ftable
block|{
name|int
name|minor_version
decl_stmt|;
name|krb5_error_code
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|fini
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|krb5plugin_send_to_kdc_func
name|send_to_kdc
decl_stmt|;
block|}
name|krb5plugin_send_to_kdc_ftable
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIMDAL_KRB5_SEND_TO_KDC_PLUGIN_H */
end_comment

end_unit

