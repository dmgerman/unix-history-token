begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2005 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KDC_LOCL_H__
end_ifndef

begin_define
define|#
directive|define
name|__KDC_LOCL_H__
end_define

begin_include
include|#
directive|include
file|"headers.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|pk_client_params
name|pk_client_params
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|DigestREQ
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|Kx509Request
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<kdc-private.h>
end_include

begin_decl_stmt
specifier|extern
name|sig_atomic_t
name|exit_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|max_request_udp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|max_request_tcp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|request_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|port_str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|krb5_addresses
name|explicit_addresses
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|enable_http
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_DETACH
end_ifdef

begin_define
define|#
directive|define
name|DETACH_IS_DEFAULT
value|FALSE
end_define

begin_decl_stmt
specifier|extern
name|int
name|detach_from_console
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|units
name|_kdc_digestunits
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KDC_LOG_FILE
value|"kdc.log"
end_define

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|_kdc_now
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|kdc_time
value|(_kdc_now.tv_sec)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|runas_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|chroot_string
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|loop
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|krb5_kdc_configuration
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_kdc_configuration
modifier|*
name|configure
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_function_decl
name|void
name|bonjour_announce
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_kdc_configuration
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KDC_LOCL_H__ */
end_comment

end_unit

