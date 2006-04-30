begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/rpc_auth.h,v 1.1.2.1 2005/04/27 21:44:07 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)auth.h 1.17 88/02/08 SMI  *	from: @(#)auth.h	2.3 88/08/07 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * auth.h, Authentication interface.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  *  * The data structures are completely opaque to the client.  The client  * is required to pass a AUTH * to routines that create rpc  * "sessions".  */
end_comment

begin_comment
comment|/*  * Status returned from authentication check  */
end_comment

begin_enum
enum|enum
name|sunrpc_auth_stat
block|{
name|SUNRPC_AUTH_OK
init|=
literal|0
block|,
comment|/* 	 * failed at remote end 	 */
name|SUNRPC_AUTH_BADCRED
init|=
literal|1
block|,
comment|/* bogus credentials (seal broken) */
name|SUNRPC_AUTH_REJECTEDCRED
init|=
literal|2
block|,
comment|/* client should begin new session */
name|SUNRPC_AUTH_BADVERF
init|=
literal|3
block|,
comment|/* bogus verifier (seal broken) */
name|SUNRPC_AUTH_REJECTEDVERF
init|=
literal|4
block|,
comment|/* verifier expired or was replayed */
name|SUNRPC_AUTH_TOOWEAK
init|=
literal|5
block|,
comment|/* rejected due to security reasons */
comment|/* 	 * failed locally 	*/
name|SUNRPC_AUTH_INVALIDRESP
init|=
literal|6
block|,
comment|/* bogus response verifier */
name|SUNRPC_AUTH_FAILED
init|=
literal|7
comment|/* some unknown reason */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Authentication info.  Opaque to client.  */
end_comment

begin_struct
struct|struct
name|sunrpc_opaque_auth
block|{
name|u_int32_t
name|oa_flavor
decl_stmt|;
comment|/* flavor of auth */
name|u_int32_t
name|oa_len
decl_stmt|;
comment|/* length of opaque body */
comment|/* zero or more bytes of body */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SUNRPC_AUTH_NONE
value|0
end_define

begin_comment
comment|/* no authentication */
end_comment

begin_define
define|#
directive|define
name|SUNRPC_AUTH_NULL
value|0
end_define

begin_comment
comment|/* backward compatibility */
end_comment

begin_define
define|#
directive|define
name|SUNRPC_AUTH_UNIX
value|1
end_define

begin_comment
comment|/* unix style (uid, gids) */
end_comment

begin_define
define|#
directive|define
name|SUNRPC_AUTH_SYS
value|1
end_define

begin_comment
comment|/* forward compatibility */
end_comment

begin_define
define|#
directive|define
name|SUNRPC_AUTH_SHORT
value|2
end_define

begin_comment
comment|/* short hand unix style */
end_comment

begin_define
define|#
directive|define
name|SUNRPC_AUTH_DES
value|3
end_define

begin_comment
comment|/* des style (encrypted timestamps) */
end_comment

end_unit

