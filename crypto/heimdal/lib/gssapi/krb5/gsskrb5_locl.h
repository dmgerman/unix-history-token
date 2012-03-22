begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2008 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GSSKRB5_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|GSSKRB5_LOCL_H
end_define

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<krb5_locl.h>
end_include

begin_include
include|#
directive|include
file|<gkrb5_err.h>
end_include

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_include
include|#
directive|include
file|<gssapi_mech.h>
end_include

begin_include
include|#
directive|include
file|<gssapi_krb5.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|"cfx.h"
end_include

begin_comment
comment|/*  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|gss_msg_order
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|gsskrb5_ctx
block|{
name|struct
name|krb5_auth_context_data
modifier|*
name|auth_context
decl_stmt|;
name|struct
name|krb5_auth_context_data
modifier|*
name|deleg_auth_context
decl_stmt|;
name|krb5_principal
name|source
decl_stmt|,
name|target
decl_stmt|;
define|#
directive|define
name|IS_DCE_STYLE
parameter_list|(
name|ctx
parameter_list|)
value|(((ctx)->flags& GSS_C_DCE_STYLE) != 0)
name|OM_uint32
name|flags
decl_stmt|;
enum|enum
block|{
name|LOCAL
init|=
literal|1
block|,
name|OPEN
init|=
literal|2
block|,
name|COMPAT_OLD_DES3
init|=
literal|4
block|,
name|COMPAT_OLD_DES3_SELECTED
init|=
literal|8
block|,
name|ACCEPTOR_SUBKEY
init|=
literal|16
block|,
name|RETRIED
init|=
literal|32
block|,
name|CLOSE_CCACHE
init|=
literal|64
block|,
name|IS_CFX
init|=
literal|128
block|}
name|more_flags
enum|;
enum|enum
name|gss_ctx_id_t_state
block|{
comment|/* initiator states */
name|INITIATOR_START
block|,
name|INITIATOR_RESTART
block|,
name|INITIATOR_WAIT_FOR_MUTAL
block|,
name|INITIATOR_READY
block|,
comment|/* acceptor states */
name|ACCEPTOR_START
block|,
name|ACCEPTOR_WAIT_FOR_DCESTYLE
block|,
name|ACCEPTOR_READY
block|}
name|state
enum|;
name|krb5_creds
modifier|*
name|kcred
decl_stmt|;
name|krb5_ccache
name|ccache
decl_stmt|;
name|struct
name|krb5_ticket
modifier|*
name|ticket
decl_stmt|;
name|OM_uint32
name|lifetime
decl_stmt|;
name|HEIMDAL_MUTEX
name|ctx_id_mutex
decl_stmt|;
name|struct
name|gss_msg_order
modifier|*
name|order
decl_stmt|;
name|krb5_keyblock
modifier|*
name|service_keyblock
decl_stmt|;
name|krb5_data
name|fwd_data
decl_stmt|;
name|krb5_crypto
name|crypto
decl_stmt|;
block|}
typedef|*
name|gsskrb5_ctx
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|krb5_principal
name|principal
decl_stmt|;
name|int
name|cred_flags
decl_stmt|;
define|#
directive|define
name|GSS_CF_DESTROY_CRED_ON_RELEASE
value|1
define|#
directive|define
name|GSS_CF_NO_CI_FLAGS
value|2
name|struct
name|krb5_keytab_data
modifier|*
name|keytab
decl_stmt|;
name|OM_uint32
name|lifetime
decl_stmt|;
name|gss_cred_usage_t
name|usage
decl_stmt|;
name|gss_OID_set
name|mechanisms
decl_stmt|;
name|struct
name|krb5_ccache_data
modifier|*
name|ccache
decl_stmt|;
name|HEIMDAL_MUTEX
name|cred_id_mutex
decl_stmt|;
name|krb5_enctype
modifier|*
name|enctypes
decl_stmt|;
block|}
typedef|*
name|gsskrb5_cred
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Principal
modifier|*
name|gsskrb5_name
typedef|;
end_typedef

begin_comment
comment|/*  *  */
end_comment

begin_decl_stmt
specifier|extern
name|krb5_keytab
name|_gsskrb5_keytab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HEIMDAL_MUTEX
name|gssapi_keytab_mutex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_include
include|#
directive|include
file|<gsskrb5-private.h>
end_include

begin_define
define|#
directive|define
name|GSSAPI_KRB5_INIT
parameter_list|(
name|ctx
parameter_list|)
value|do {				\     krb5_error_code kret_gss_init;				\     if((kret_gss_init = _gsskrb5_init (ctx)) != 0) {		\ 	*minor_status = kret_gss_init;				\ 	return GSS_S_FAILURE;					\     }								\ } while (0)
end_define

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

begin_comment
comment|/* type to signal that that dns canon maybe should be done */
end_comment

begin_define
define|#
directive|define
name|MAGIC_HOSTBASED_NAME_TYPE
value|4711
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

