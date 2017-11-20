begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   SPDX-License-Identifier: BSD-3-Clause    rpcsec_gss.h      Copyright (c) 2000 The Regents of the University of Michigan.   All rights reserved.      Copyright (c) 2000 Dug Song<dugsong@UMICH.EDU>.   All rights reserved, all wrongs reversed.    Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions   are met:    1. Redistributions of source code must retain the above copyright      notice, this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright      notice, this list of conditions and the following disclaimer in the      documentation and/or other materials provided with the distribution.   3. Neither the name of the University nor the names of its      contributors may be used to endorse or promote products derived      from this software without specific prior written permission.    THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE   DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    $Id: auth_gss.h,v 1.12 2001/04/30 19:44:47 andros Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPCSEC_GSS_INT_H
end_ifndef

begin_define
define|#
directive|define
name|_RPCSEC_GSS_INT_H
end_define

begin_comment
comment|/* RPCSEC_GSS control procedures. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|RPCSEC_GSS_DATA
init|=
literal|0
block|,
name|RPCSEC_GSS_INIT
init|=
literal|1
block|,
name|RPCSEC_GSS_CONTINUE_INIT
init|=
literal|2
block|,
name|RPCSEC_GSS_DESTROY
init|=
literal|3
block|}
name|rpc_gss_proc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RPCSEC_GSS_VERSION
value|1
end_define

begin_comment
comment|/* Credentials. */
end_comment

begin_struct
struct|struct
name|rpc_gss_cred
block|{
name|u_int
name|gc_version
decl_stmt|;
comment|/* version */
name|rpc_gss_proc_t
name|gc_proc
decl_stmt|;
comment|/* control procedure */
name|u_int
name|gc_seq
decl_stmt|;
comment|/* sequence number */
name|rpc_gss_service_t
name|gc_svc
decl_stmt|;
comment|/* service */
name|gss_buffer_desc
name|gc_handle
decl_stmt|;
comment|/* handle to server-side context */
block|}
struct|;
end_struct

begin_comment
comment|/* Context creation response. */
end_comment

begin_struct
struct|struct
name|rpc_gss_init_res
block|{
name|gss_buffer_desc
name|gr_handle
decl_stmt|;
comment|/* handle to server-side context */
name|u_int
name|gr_major
decl_stmt|;
comment|/* major status */
name|u_int
name|gr_minor
decl_stmt|;
comment|/* minor status */
name|u_int
name|gr_win
decl_stmt|;
comment|/* sequence window */
name|gss_buffer_desc
name|gr_token
decl_stmt|;
comment|/* token */
block|}
struct|;
end_struct

begin_comment
comment|/* Maximum sequence number value. */
end_comment

begin_define
define|#
directive|define
name|MAXSEQ
value|0x80000000
end_define

begin_comment
comment|/* Prototypes. */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|bool_t
name|xdr_gss_buffer_desc
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|gss_buffer_desc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_rpc_gss_cred
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|struct
name|rpc_gss_cred
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_rpc_gss_init_res
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|struct
name|rpc_gss_init_res
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_rpc_gss_wrap_data
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|xdrproc_t
name|xdr_func
parameter_list|,
name|caddr_t
name|xdr_ptr
parameter_list|,
name|gss_ctx_id_t
name|ctx
parameter_list|,
name|gss_qop_t
name|qop
parameter_list|,
name|rpc_gss_service_t
name|svc
parameter_list|,
name|u_int
name|seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|xdr_rpc_gss_unwrap_data
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|xdrproc_t
name|xdr_func
parameter_list|,
name|caddr_t
name|xdr_ptr
parameter_list|,
name|gss_ctx_id_t
name|ctx
parameter_list|,
name|gss_qop_t
name|qop
parameter_list|,
name|rpc_gss_service_t
name|svc
parameter_list|,
name|u_int
name|seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|_rpc_gss_num_to_qop
parameter_list|(
specifier|const
name|char
modifier|*
name|mech
parameter_list|,
name|u_int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_rpc_gss_set_error
parameter_list|(
name|int
name|rpc_gss_error
parameter_list|,
name|int
name|system_error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_debug
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_status
parameter_list|(
specifier|const
name|char
modifier|*
name|m
parameter_list|,
name|gss_OID
name|mech
parameter_list|,
name|OM_uint32
name|major
parameter_list|,
name|OM_uint32
name|minor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_hexdump
parameter_list|(
specifier|const
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|offset
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
comment|/* !_RPCSEC_GSS_INT_H */
end_comment

end_unit

