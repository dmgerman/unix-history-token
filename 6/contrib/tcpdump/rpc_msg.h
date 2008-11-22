begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/rpc_msg.h,v 1.1.2.1 2005/04/27 21:44:07 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)rpc_msg.h 1.7 86/07/16 SMI  *	from: @(#)rpc_msg.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * rpc_msg.h  * rpc message definition  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_define
define|#
directive|define
name|SUNRPC_MSG_VERSION
value|((u_int32_t) 2)
end_define

begin_comment
comment|/*  * Bottom up definition of an rpc message.  * NOTE: call and reply use the same overall stuct but  * different parts of unions within it.  */
end_comment

begin_enum
enum|enum
name|sunrpc_msg_type
block|{
name|SUNRPC_CALL
init|=
literal|0
block|,
name|SUNRPC_REPLY
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sunrpc_reply_stat
block|{
name|SUNRPC_MSG_ACCEPTED
init|=
literal|0
block|,
name|SUNRPC_MSG_DENIED
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sunrpc_accept_stat
block|{
name|SUNRPC_SUCCESS
init|=
literal|0
block|,
name|SUNRPC_PROG_UNAVAIL
init|=
literal|1
block|,
name|SUNRPC_PROG_MISMATCH
init|=
literal|2
block|,
name|SUNRPC_PROC_UNAVAIL
init|=
literal|3
block|,
name|SUNRPC_GARBAGE_ARGS
init|=
literal|4
block|,
name|SUNRPC_SYSTEM_ERR
init|=
literal|5
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sunrpc_reject_stat
block|{
name|SUNRPC_RPC_MISMATCH
init|=
literal|0
block|,
name|SUNRPC_AUTH_ERROR
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/*  * Reply part of an rpc exchange  */
end_comment

begin_comment
comment|/*  * Reply to an rpc request that was rejected by the server.  */
end_comment

begin_struct
struct|struct
name|sunrpc_rejected_reply
block|{
name|u_int32_t
name|rj_stat
decl_stmt|;
comment|/* enum reject_stat */
union|union
block|{
struct|struct
block|{
name|u_int32_t
name|low
decl_stmt|;
name|u_int32_t
name|high
decl_stmt|;
block|}
name|RJ_versions
struct|;
name|u_int32_t
name|RJ_why
decl_stmt|;
comment|/* enum auth_stat - why authentication did not work */
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
name|sunrpc_reply_body
block|{
name|u_int32_t
name|rp_stat
decl_stmt|;
comment|/* enum reply_stat */
name|struct
name|sunrpc_rejected_reply
name|rp_reject
decl_stmt|;
comment|/* if rejected */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Body of an rpc request call.  */
end_comment

begin_struct
struct|struct
name|sunrpc_call_body
block|{
name|u_int32_t
name|cb_rpcvers
decl_stmt|;
comment|/* must be equal to two */
name|u_int32_t
name|cb_prog
decl_stmt|;
name|u_int32_t
name|cb_vers
decl_stmt|;
name|u_int32_t
name|cb_proc
decl_stmt|;
name|struct
name|sunrpc_opaque_auth
name|cb_cred
decl_stmt|;
comment|/* followed by opaque verifier */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The rpc message  */
end_comment

begin_struct
struct|struct
name|sunrpc_msg
block|{
name|u_int32_t
name|rm_xid
decl_stmt|;
name|u_int32_t
name|rm_direction
decl_stmt|;
comment|/* enum msg_type */
union|union
block|{
name|struct
name|sunrpc_call_body
name|RM_cmb
decl_stmt|;
name|struct
name|sunrpc_reply_body
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

end_unit

