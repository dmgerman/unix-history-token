begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-2000 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of the Institute nor the names of its contributors   *    may be used to endorse or promote products derived from this software   *    without specific prior written permission.   *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   */
end_comment

begin_comment
comment|/*   * $Id: kdc_locl.h,v 1.40 2000/02/11 17:46:29 assar Exp $   */
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

begin_decl_stmt
specifier|extern
name|krb5_context
name|context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|require_preauth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sig_atomic_t
name|exit_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|max_request
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|kdc_warn_pwexpire
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|dbinfo
block|{
name|char
modifier|*
name|realm
decl_stmt|;
name|char
modifier|*
name|dbname
decl_stmt|;
name|char
modifier|*
name|mkey_file
decl_stmt|;
name|struct
name|dbinfo
modifier|*
name|next
decl_stmt|;
block|}
modifier|*
name|databases
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|HDB
modifier|*
modifier|*
name|db
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_db
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
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

begin_decl_stmt
specifier|extern
name|krb5_boolean
name|encode_as_rep_as_tgs_rep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|krb5_boolean
name|check_ticket_addresses
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|krb5_boolean
name|allow_null_ticket_addresses
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|v4_realm
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KASERVER
end_ifdef

begin_decl_stmt
specifier|extern
name|krb5_boolean
name|enable_kaserver
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|now
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|kdc_time
value|(now.tv_sec)
end_define

begin_function_decl
name|krb5_error_code
name|as_rep
parameter_list|(
name|KDC_REQ
modifier|*
parameter_list|,
name|krb5_data
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|configure
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|hdb_entry
modifier|*
name|db_fetch
parameter_list|(
name|krb5_principal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kdc_log
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|kdc_log_msg
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|kdc_log_msg_va
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kdc_openlog
parameter_list|(
name|krb5_config_section
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_master_key
parameter_list|(
name|EncryptionKey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|tgs_rep
parameter_list|(
name|KDC_REQ
modifier|*
parameter_list|,
name|krb5_data
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Key
modifier|*
name|unseal_key
parameter_list|(
name|Key
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KRB4
end_ifdef

begin_function_decl
name|hdb_entry
modifier|*
name|db_fetch4
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|do_524
parameter_list|(
name|Ticket
modifier|*
parameter_list|,
name|krb5_data
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|do_version4
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|krb5_data
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|encode_v4_ticket
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|EncTicketPart
modifier|*
parameter_list|,
name|PrincipalName
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|encrypt_v4_ticket
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|des_cblock
modifier|*
parameter_list|,
name|EncryptedData
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|krb5_error_code
name|get_des_key
parameter_list|(
name|hdb_entry
modifier|*
parameter_list|,
name|Key
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|maybe_version4
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KASERVER
end_ifdef

begin_function_decl
name|krb5_error_code
name|do_kaserver
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|krb5_data
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|sockaddr_in
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

