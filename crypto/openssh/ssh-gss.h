begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: ssh-gss.h,v 1.10 2007/06/12 08:20:00 djm Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001-2003 Simon Wilkinson. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR `AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SSH_GSS_H
end_ifndef

begin_define
define|#
directive|define
name|_SSH_GSS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GSSAPI
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GSSAPI_GSSAPI_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<gssapi/gssapi.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_GSSAPI_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<gssapi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KRB5
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GSSAPI_GENERIC_H
end_ifdef

begin_include
include|#
directive|include
file|<gssapi_generic.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_GSSAPI_GSSAPI_GENERIC_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<gssapi/gssapi_generic.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Old MIT Kerberos doesn't seem to define GSS_NT_HOSTBASED_SERVICE */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GSS_C_NT_HOSTBASED_SERVICE
end_if

begin_define
define|#
directive|define
name|GSS_C_NT_HOSTBASED_SERVICE
value|gss_nt_service_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_DECL_GSS_C_NT_... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HEIMDAL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KRB5 */
end_comment

begin_comment
comment|/* draft-ietf-secsh-gsskeyex-06 */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_GSSAPI_RESPONSE
value|60
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_GSSAPI_TOKEN
value|61
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_GSSAPI_EXCHANGE_COMPLETE
value|63
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_GSSAPI_ERROR
value|64
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_GSSAPI_ERRTOK
value|65
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_GSSAPI_MIC
value|66
end_define

begin_define
define|#
directive|define
name|SSH_GSS_OIDTYPE
value|0x06
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|filename
decl_stmt|;
name|char
modifier|*
name|envvar
decl_stmt|;
name|char
modifier|*
name|envval
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|ssh_gssapi_ccache
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|gss_buffer_desc
name|displayname
decl_stmt|;
name|gss_buffer_desc
name|exportedname
decl_stmt|;
name|gss_cred_id_t
name|creds
decl_stmt|;
name|struct
name|ssh_gssapi_mech_struct
modifier|*
name|mech
decl_stmt|;
name|ssh_gssapi_ccache
name|store
decl_stmt|;
block|}
name|ssh_gssapi_client
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ssh_gssapi_mech_struct
block|{
name|char
modifier|*
name|enc_name
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|gss_OID_desc
name|oid
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dochild
function_decl|)
parameter_list|(
name|ssh_gssapi_client
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|userok
function_decl|)
parameter_list|(
name|ssh_gssapi_client
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|localname
function_decl|)
parameter_list|(
name|ssh_gssapi_client
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|storecreds
function_decl|)
parameter_list|(
name|ssh_gssapi_client
modifier|*
parameter_list|)
function_decl|;
block|}
name|ssh_gssapi_mech
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|OM_uint32
name|major
decl_stmt|;
comment|/* both */
name|OM_uint32
name|minor
decl_stmt|;
comment|/* both */
name|gss_ctx_id_t
name|context
decl_stmt|;
comment|/* both */
name|gss_name_t
name|name
decl_stmt|;
comment|/* both */
name|gss_OID
name|oid
decl_stmt|;
comment|/* client */
name|gss_cred_id_t
name|creds
decl_stmt|;
comment|/* server */
name|gss_name_t
name|client
decl_stmt|;
comment|/* server */
name|gss_cred_id_t
name|client_creds
decl_stmt|;
comment|/* server */
block|}
name|Gssctxt
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ssh_gssapi_mech
modifier|*
name|supported_mechs
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ssh_gssapi_check_oid
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_set_oid_data
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_set_oid
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|gss_OID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_supported_oids
parameter_list|(
name|gss_OID_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssh_gssapi_mech
modifier|*
name|ssh_gssapi_get_ctype
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|ssh_gssapi_import_name
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|ssh_gssapi_init_ctx
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|int
parameter_list|,
name|gss_buffer_desc
modifier|*
parameter_list|,
name|gss_buffer_desc
modifier|*
parameter_list|,
name|OM_uint32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|ssh_gssapi_accept_ctx
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|gss_buffer_desc
modifier|*
parameter_list|,
name|gss_buffer_desc
modifier|*
parameter_list|,
name|OM_uint32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|ssh_gssapi_getclient
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|ssh_gssapi_client
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_error
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ssh_gssapi_last_error
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|OM_uint32
modifier|*
parameter_list|,
name|OM_uint32
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_build_ctx
parameter_list|(
name|Gssctxt
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_delete_ctx
parameter_list|(
name|Gssctxt
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|ssh_gssapi_sign
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|gss_buffer_t
parameter_list|,
name|gss_buffer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_buildmic
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
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
name|int
name|ssh_gssapi_check_mechanism
parameter_list|(
name|Gssctxt
modifier|*
modifier|*
parameter_list|,
name|gss_OID
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In the server */
end_comment

begin_function_decl
name|OM_uint32
name|ssh_gssapi_server_ctx
parameter_list|(
name|Gssctxt
modifier|*
modifier|*
parameter_list|,
name|gss_OID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_gssapi_userok
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OM_uint32
name|ssh_gssapi_checkmic
parameter_list|(
name|Gssctxt
modifier|*
parameter_list|,
name|gss_buffer_t
parameter_list|,
name|gss_buffer_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_do_child
parameter_list|(
name|char
modifier|*
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_cleanup_creds
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_gssapi_storecreds
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GSSAPI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SSH_GSS_H */
end_comment

end_unit

