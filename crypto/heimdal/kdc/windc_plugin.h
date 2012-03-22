begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_KRB5_PAC_PLUGIN_H
end_ifndef

begin_define
define|#
directive|define
name|HEIMDAL_KRB5_PAC_PLUGIN_H
value|1
end_define

begin_include
include|#
directive|include
file|<krb5.h>
end_include

begin_comment
comment|/*  * The PAC generate function should allocate a krb5_pac using  * krb5_pac_init and fill in the PAC structure for the principal using  * krb5_pac_add_buffer.  *  * The PAC verify function should verify all components in the PAC  * using krb5_pac_get_types and krb5_pac_get_buffer for all types.  *  * Check client access function check if the client is authorized.  */
end_comment

begin_struct_decl
struct_decl|struct
name|hdb_entry_ex
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
modifier|*
name|krb5plugin_windc_pac_generate
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|krb5_context
parameter_list|,
name|struct
name|hdb_entry_ex
modifier|*
parameter_list|,
name|krb5_pac
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
modifier|*
name|krb5plugin_windc_pac_verify
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|krb5_context
parameter_list|,
specifier|const
name|krb5_principal
parameter_list|,
comment|/* new ticket client */
specifier|const
name|krb5_principal
parameter_list|,
comment|/* delegation proxy */
name|struct
name|hdb_entry_ex
modifier|*
parameter_list|,
comment|/* client */
name|struct
name|hdb_entry_ex
modifier|*
parameter_list|,
comment|/* server */
name|struct
name|hdb_entry_ex
modifier|*
parameter_list|,
comment|/* krbtgt */
name|krb5_pac
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
modifier|*
name|krb5plugin_windc_client_access
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|krb5_context
parameter_list|,
name|krb5_kdc_configuration
modifier|*
name|config
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|hdb_entry_ex
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|KDC_REQ
modifier|*
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|KRB5_WINDC_PLUGIN_MINOR
value|6
end_define

begin_define
define|#
directive|define
name|KRB5_WINDC_PLUGING_MINOR
value|KRB5_WINDC_PLUGIN_MINOR
end_define

begin_typedef
typedef|typedef
struct|struct
name|krb5plugin_windc_ftable
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
name|krb5plugin_windc_pac_generate
name|pac_generate
decl_stmt|;
name|krb5plugin_windc_pac_verify
name|pac_verify
decl_stmt|;
name|krb5plugin_windc_client_access
name|client_access
decl_stmt|;
block|}
name|krb5plugin_windc_ftable
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIMDAL_KRB5_PAC_PLUGIN_H */
end_comment

end_unit

