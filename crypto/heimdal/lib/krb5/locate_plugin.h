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
name|HEIMDAL_KRB5_LOCATE_PLUGIN_H
end_ifndef

begin_define
define|#
directive|define
name|HEIMDAL_KRB5_LOCATE_PLUGIN_H
value|1
end_define

begin_define
define|#
directive|define
name|KRB5_PLUGIN_LOCATE
value|"service_locator"
end_define

begin_enum
enum|enum
name|locate_service_type
block|{
name|locate_service_kdc
init|=
literal|1
block|,
name|locate_service_master_kdc
block|,
name|locate_service_kadmin
block|,
name|locate_service_krb524
block|,
name|locate_service_kpasswd
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|krb5_error_code
function_decl|(
modifier|*
name|krb5plugin_service_locate_lookup
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|enum
name|locate_service_type
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|krb5plugin_service_locate_ftable
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
name|krb5plugin_service_locate_lookup
name|lookup
decl_stmt|;
block|}
name|krb5plugin_service_locate_ftable
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIMDAL_KRB5_LOCATE_PLUGIN_H */
end_comment

end_unit

