begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2008 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPCSEC_GSS_H
end_ifndef

begin_define
define|#
directive|define
name|_RPCSEC_GSS_H
end_define

begin_include
include|#
directive|include
file|<gssapi/gssapi.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_GSS_MECH
end_ifndef

begin_define
define|#
directive|define
name|MAX_GSS_MECH
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define the types of security service required for rpc_gss_seccreate().  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|rpc_gss_svc_default
init|=
literal|0
block|,
name|rpc_gss_svc_none
init|=
literal|1
block|,
name|rpc_gss_svc_integrity
init|=
literal|2
block|,
name|rpc_gss_svc_privacy
init|=
literal|3
block|}
name|rpc_gss_service_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure containing options for rpc_gss_seccreate().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|req_flags
decl_stmt|;
comment|/* GSS request bits */
name|int
name|time_req
decl_stmt|;
comment|/* requested credential lifetime */
name|gss_cred_id_t
name|my_cred
decl_stmt|;
comment|/* GSS credential */
name|gss_channel_bindings_t
name|input_channel_bindings
decl_stmt|;
block|}
name|rpc_gss_options_req_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure containing options returned by rpc_gss_seccreate().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|major_status
decl_stmt|;
name|int
name|minor_status
decl_stmt|;
name|u_int
name|rpcsec_version
decl_stmt|;
name|int
name|ret_flags
decl_stmt|;
name|int
name|time_req
decl_stmt|;
name|gss_ctx_id_t
name|gss_context
decl_stmt|;
name|char
name|actual_mechanism
index|[
name|MAX_GSS_MECH
index|]
decl_stmt|;
block|}
name|rpc_gss_options_ret_t
typedef|;
end_typedef

begin_comment
comment|/*  * Client principal type. Used as an argument to  * rpc_gss_get_principal_name(). Also referenced by the  * rpc_gss_rawcred_t structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|len
decl_stmt|;
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|rpc_gss_principal_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure for raw credentials used by rpc_gss_getcred() and  * rpc_gss_set_callback().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|version
decl_stmt|;
comment|/* RPC version number */
specifier|const
name|char
modifier|*
name|mechanism
decl_stmt|;
comment|/* security mechanism */
specifier|const
name|char
modifier|*
name|qop
decl_stmt|;
comment|/* quality of protection */
name|rpc_gss_principal_t
name|client_principal
decl_stmt|;
comment|/* client name */
specifier|const
name|char
modifier|*
name|svc_principal
decl_stmt|;
comment|/* server name */
name|rpc_gss_service_t
name|service
decl_stmt|;
comment|/* service type */
block|}
name|rpc_gss_rawcred_t
typedef|;
end_typedef

begin_comment
comment|/*  * Unix credentials derived from raw credentials. Returned by  * rpc_gss_getcred().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uid_t
name|uid
decl_stmt|;
comment|/* user ID */
name|gid_t
name|gid
decl_stmt|;
comment|/* group ID */
name|short
name|gidlen
decl_stmt|;
name|gid_t
modifier|*
name|gidlist
decl_stmt|;
comment|/* list of groups */
block|}
name|rpc_gss_ucred_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure used to enforce a particular QOP and service.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool_t
name|locked
decl_stmt|;
name|rpc_gss_rawcred_t
modifier|*
name|raw_cred
decl_stmt|;
block|}
name|rpc_gss_lock_t
typedef|;
end_typedef

begin_comment
comment|/*  * Callback structure used by rpc_gss_set_callback().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|program
decl_stmt|;
comment|/* RPC program number */
name|u_int
name|version
decl_stmt|;
comment|/* RPC version number */
comment|/* user defined callback */
name|bool_t
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
name|req
parameter_list|,
name|gss_cred_id_t
name|deleg
parameter_list|,
name|gss_ctx_id_t
name|gss_context
parameter_list|,
name|rpc_gss_lock_t
modifier|*
name|lock
parameter_list|,
name|void
modifier|*
modifier|*
name|cookie
parameter_list|)
function_decl|;
block|}
name|rpc_gss_callback_t
typedef|;
end_typedef

begin_comment
comment|/*  * Structure used to return error information by rpc_gss_get_error()  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rpc_gss_error
decl_stmt|;
name|int
name|system_error
decl_stmt|;
comment|/* same as errno */
block|}
name|rpc_gss_error_t
typedef|;
end_typedef

begin_comment
comment|/*  * Values for rpc_gss_error  */
end_comment

begin_define
define|#
directive|define
name|RPC_GSS_ER_SUCCESS
value|0
end_define

begin_comment
comment|/* no error */
end_comment

begin_define
define|#
directive|define
name|RPC_GSS_ER_SYSTEMERROR
value|1
end_define

begin_comment
comment|/* system error */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|AUTH
modifier|*
name|rpc_gss_seccreate
parameter_list|(
name|CLIENT
modifier|*
name|clnt
parameter_list|,
specifier|const
name|char
modifier|*
name|principal
parameter_list|,
specifier|const
name|char
modifier|*
name|mechanism
parameter_list|,
name|rpc_gss_service_t
name|service
parameter_list|,
specifier|const
name|char
modifier|*
name|qop
parameter_list|,
name|rpc_gss_options_req_t
modifier|*
name|options_req
parameter_list|,
name|rpc_gss_options_ret_t
modifier|*
name|options_ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_set_defaults
parameter_list|(
name|AUTH
modifier|*
name|auth
parameter_list|,
name|rpc_gss_service_t
name|service
parameter_list|,
specifier|const
name|char
modifier|*
name|qop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpc_gss_max_data_length
parameter_list|(
name|AUTH
modifier|*
name|handle
parameter_list|,
name|int
name|max_tp_unit_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpc_gss_get_error
parameter_list|(
name|rpc_gss_error_t
modifier|*
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_mech_to_oid
parameter_list|(
specifier|const
name|char
modifier|*
name|mech
parameter_list|,
name|gss_OID
modifier|*
name|oid_ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_oid_to_mech
parameter_list|(
name|gss_OID
name|oid
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|mech_ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_qop_to_num
parameter_list|(
specifier|const
name|char
modifier|*
name|qop
parameter_list|,
specifier|const
name|char
modifier|*
name|mech
parameter_list|,
name|u_int
modifier|*
name|num_ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
modifier|*
name|rpc_gss_get_mechanisms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
modifier|*
name|rpc_gss_get_mech_info
parameter_list|(
specifier|const
name|char
modifier|*
name|mech
parameter_list|,
name|rpc_gss_service_t
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_get_versions
parameter_list|(
name|u_int
modifier|*
name|vers_hi
parameter_list|,
name|u_int
modifier|*
name|vers_lo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_is_installed
parameter_list|(
specifier|const
name|char
modifier|*
name|mech
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_set_svc_name
parameter_list|(
specifier|const
name|char
modifier|*
name|principal
parameter_list|,
specifier|const
name|char
modifier|*
name|mechanism
parameter_list|,
name|u_int
name|req_time
parameter_list|,
name|u_int
name|program
parameter_list|,
name|u_int
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_getcred
parameter_list|(
name|struct
name|svc_req
modifier|*
name|req
parameter_list|,
name|rpc_gss_rawcred_t
modifier|*
modifier|*
name|rcred
parameter_list|,
name|rpc_gss_ucred_t
modifier|*
modifier|*
name|ucred
parameter_list|,
name|void
modifier|*
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_set_callback
parameter_list|(
name|rpc_gss_callback_t
modifier|*
name|cb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|rpc_gss_get_principal_name
parameter_list|(
name|rpc_gss_principal_t
modifier|*
name|principal
parameter_list|,
specifier|const
name|char
modifier|*
name|mech
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpc_gss_svc_max_data_length
parameter_list|(
name|struct
name|svc_req
modifier|*
name|req
parameter_list|,
name|int
name|max_tp_unit_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Internal interface from the RPC implementation.  */
end_comment

begin_function_decl
name|bool_t
name|__rpc_gss_wrap
parameter_list|(
name|AUTH
modifier|*
name|auth
parameter_list|,
name|void
modifier|*
name|header
parameter_list|,
name|size_t
name|headerlen
parameter_list|,
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|xdrproc_t
name|xdr_args
parameter_list|,
name|void
modifier|*
name|args_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|__rpc_gss_unwrap
parameter_list|(
name|AUTH
modifier|*
name|auth
parameter_list|,
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|xdrproc_t
name|xdr_args
parameter_list|,
name|void
modifier|*
name|args_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|__rpc_gss_set_error
parameter_list|(
name|int
name|rpc_gss_error
parameter_list|,
name|int
name|system_error
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPCSEC_GSS_H */
end_comment

end_unit

