begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)rpc.h 1.9 88/02/08 SMI  *	from: @(#)rpc.h	2.4 89/07/11 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * rpc.h, Just includes the billions of rpc header files necessary to  * do remote procedure calling.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_RPC_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_RPC_H
end_define

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
comment|/*  *  Uncomment-out the next line if you are building the rpc library with  *  DES Authentication (see the README file in the secure_rpc/ directory).  */
end_comment

begin_include
include|#
directive|include
file|<rpc/auth_des.h>
end_include

begin_comment
comment|/* protocol for des style cred */
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

begin_comment
comment|/*  * COMMENT OUT THE NEXT INCLUDE (or add to the #ifndef) IF RUNNING ON  * A VERSION OF UNIX THAT USES SUN'S NFS SOURCE.  These systems will  * already have the structures defined by<rpc/netdb.h> included in<netdb.h>.  */
end_comment

begin_comment
comment|/* routines for parsing /etc/rpc */
end_comment

begin_struct
struct|struct
name|rpcent
block|{
name|char
modifier|*
name|r_name
decl_stmt|;
comment|/* name of server for this rpc program */
name|char
modifier|*
modifier|*
name|r_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|r_number
decl_stmt|;
comment|/* rpc program number */
block|}
struct|;
end_struct

begin_expr_stmt
name|__BEGIN_DECLS
specifier|extern
expr|struct
name|rpcent
operator|*
name|getrpcbyname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rpcent
modifier|*
name|getrpcbynumber
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rpcent
modifier|*
name|getrpcent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getrpcport
name|__P
argument_list|(
operator|(
name|char
operator|*
name|host
operator|,
name|int
name|prognum
operator|,
name|int
name|versnum
operator|,
name|int
name|proto
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setrpcent
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|endrpcent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bindresvport
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bindresvport_sa
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_myaddress
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_RPC_H */
end_comment

end_unit

