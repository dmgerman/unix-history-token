begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpc_msg.h,v 1.11 2000/06/02 22:57:56 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: @(#)rpc_msg.h 1.7 86/07/16 SMI  *	from: @(#)rpc_msg.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * rpc_msg.h  * rpc message definition  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_RPC_MSG_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_RPC_MSG_H
end_define

begin_define
define|#
directive|define
name|RPC_MSG_VERSION
value|((u_int32_t) 2)
end_define

begin_define
define|#
directive|define
name|RPC_SERVICE_PORT
value|((u_short) 2048)
end_define

begin_comment
comment|/*  * Bottom up definition of an rpc message.  * NOTE: call and reply use the same overall stuct but  * different parts of unions within it.  */
end_comment

begin_enum
enum|enum
name|msg_type
block|{
name|CALL
init|=
literal|0
block|,
name|REPLY
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|reply_stat
block|{
name|MSG_ACCEPTED
init|=
literal|0
block|,
name|MSG_DENIED
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|accept_stat
block|{
name|SUCCESS
init|=
literal|0
block|,
name|PROG_UNAVAIL
init|=
literal|1
block|,
name|PROG_MISMATCH
init|=
literal|2
block|,
name|PROC_UNAVAIL
init|=
literal|3
block|,
name|GARBAGE_ARGS
init|=
literal|4
block|,
name|SYSTEM_ERR
init|=
literal|5
block|}
enum|;
end_enum

begin_enum
enum|enum
name|reject_stat
block|{
name|RPC_MISMATCH
init|=
literal|0
block|,
name|AUTH_ERROR
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/*  * Reply part of an rpc exchange  */
end_comment

begin_comment
comment|/*  * Reply to an rpc request that was accepted by the server.  * Note: there could be an error even though the request was  * accepted.  */
end_comment

begin_struct
struct|struct
name|accepted_reply
block|{
name|struct
name|opaque_auth
name|ar_verf
decl_stmt|;
name|enum
name|accept_stat
name|ar_stat
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|rpcvers_t
name|low
decl_stmt|;
name|rpcvers_t
name|high
decl_stmt|;
block|}
name|AR_versions
struct|;
struct|struct
block|{
name|caddr_t
name|where
decl_stmt|;
name|xdrproc_t
name|proc
decl_stmt|;
block|}
name|AR_results
struct|;
comment|/* and many other null cases */
block|}
name|ru
union|;
define|#
directive|define
name|ar_results
value|ru.AR_results
define|#
directive|define
name|ar_vers
value|ru.AR_versions
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reply to an rpc request that was rejected by the server.  */
end_comment

begin_struct
struct|struct
name|rejected_reply
block|{
name|enum
name|reject_stat
name|rj_stat
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|rpcvers_t
name|low
decl_stmt|;
name|rpcvers_t
name|high
decl_stmt|;
block|}
name|RJ_versions
struct|;
name|enum
name|auth_stat
name|RJ_why
decl_stmt|;
comment|/* why authentication did not work */
block|}
name|ru
union|;
define|#
directive|define
name|rj_vers
value|ru.RJ_versions
define|#
directive|define
name|rj_why
value|ru.RJ_why
block|}
struct|;
end_struct

begin_comment
comment|/*  * Body of a reply to an rpc request.  */
end_comment

begin_struct
struct|struct
name|reply_body
block|{
name|enum
name|reply_stat
name|rp_stat
decl_stmt|;
union|union
block|{
name|struct
name|accepted_reply
name|RP_ar
decl_stmt|;
name|struct
name|rejected_reply
name|RP_dr
decl_stmt|;
block|}
name|ru
union|;
define|#
directive|define
name|rp_acpt
value|ru.RP_ar
define|#
directive|define
name|rp_rjct
value|ru.RP_dr
block|}
struct|;
end_struct

begin_comment
comment|/*  * Body of an rpc request call.  */
end_comment

begin_struct
struct|struct
name|call_body
block|{
name|rpcvers_t
name|cb_rpcvers
decl_stmt|;
comment|/* must be equal to two */
name|rpcprog_t
name|cb_prog
decl_stmt|;
name|rpcvers_t
name|cb_vers
decl_stmt|;
name|rpcproc_t
name|cb_proc
decl_stmt|;
name|struct
name|opaque_auth
name|cb_cred
decl_stmt|;
name|struct
name|opaque_auth
name|cb_verf
decl_stmt|;
comment|/* protocol specific - provided by client */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The rpc message  */
end_comment

begin_struct
struct|struct
name|rpc_msg
block|{
name|u_int32_t
name|rm_xid
decl_stmt|;
name|enum
name|msg_type
name|rm_direction
decl_stmt|;
union|union
block|{
name|struct
name|call_body
name|RM_cmb
decl_stmt|;
name|struct
name|reply_body
name|RM_rmb
decl_stmt|;
block|}
name|ru
union|;
define|#
directive|define
name|rm_call
value|ru.RM_cmb
define|#
directive|define
name|rm_reply
value|ru.RM_rmb
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|acpted_rply
value|ru.RM_rmb.ru.RP_ar
end_define

begin_define
define|#
directive|define
name|rjcted_rply
value|ru.RM_rmb.ru.RP_dr
end_define

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * XDR routine to handle a rpc message.  * xdr_callmsg(xdrs, cmsg)  * 	XDR *xdrs;  * 	struct rpc_msg *cmsg;  */
specifier|extern
name|bool_t
name|xdr_callmsg
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XDR routine to pre-serialize the static part of a rpc message.  * xdr_callhdr(xdrs, cmsg)  * 	XDR *xdrs;  * 	struct rpc_msg *cmsg;  */
end_comment

begin_function_decl
specifier|extern
name|bool_t
name|xdr_callhdr
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XDR routine to handle a rpc reply.  * xdr_replymsg(xdrs, rmsg)  * 	XDR *xdrs;  * 	struct rpc_msg *rmsg;  */
end_comment

begin_function_decl
specifier|extern
name|bool_t
name|xdr_replymsg
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XDR routine to handle an accepted rpc reply.  * xdr_accepted_reply(xdrs, rej)  * 	XDR *xdrs;  * 	struct accepted_reply *rej;  */
end_comment

begin_function_decl
specifier|extern
name|bool_t
name|xdr_accepted_reply
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|accepted_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XDR routine to handle a rejected rpc reply.  * xdr_rejected_reply(xdrs, rej)  * 	XDR *xdrs;  * 	struct rejected_reply *rej;  */
end_comment

begin_function_decl
specifier|extern
name|bool_t
name|xdr_rejected_reply
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|rejected_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Fills in the error part of a reply message.  * _seterr_reply(msg, error)  * 	struct rpc_msg *msg;  * 	struct rpc_err *error;  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_seterr_reply
parameter_list|(
name|struct
name|rpc_msg
modifier|*
parameter_list|,
name|struct
name|rpc_err
modifier|*
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
comment|/* !_RPC_RPC_MSG_H */
end_comment

end_unit

