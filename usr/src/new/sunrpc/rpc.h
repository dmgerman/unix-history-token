begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*	@(#)rpc.h 1.2 85/02/08 SMI	*/
end_comment

begin_comment
comment|/*  * rpc.h, Just includes the billions of rpc header files necessary to   * do remote procedure calling.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_comment
comment|/* some typedefs */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* external data representation interfaces */
end_comment

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_comment
comment|/* generic (de)serializer */
end_comment

begin_comment
comment|/* Client side only authentication */
end_comment

begin_include
include|#
directive|include
file|<rpc/auth.h>
end_include

begin_comment
comment|/* generic authenticator (client side) */
end_comment

begin_comment
comment|/* Client side (mostly) remote procedure call */
end_comment

begin_include
include|#
directive|include
file|<rpc/clnt.h>
end_include

begin_comment
comment|/* generic rpc stuff */
end_comment

begin_comment
comment|/* semi-private protocol headers */
end_comment

begin_include
include|#
directive|include
file|<rpc/rpc_msg.h>
end_include

begin_comment
comment|/* protocol for rpc messages */
end_comment

begin_include
include|#
directive|include
file|<rpc/auth_unix.h>
end_include

begin_comment
comment|/* protocol for unix style cred */
end_comment

begin_comment
comment|/* Server side only remote procedure callee */
end_comment

begin_include
include|#
directive|include
file|<rpc/svc.h>
end_include

begin_comment
comment|/* service manager and multiplexer */
end_comment

begin_include
include|#
directive|include
file|<rpc/svc_auth.h>
end_include

begin_comment
comment|/* service side authenticator */
end_comment

end_unit

