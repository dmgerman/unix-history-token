begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpc.h,v 1.13 2000/06/02 22:57:56 fvdl Exp $	*/
end_comment

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
file|<sys/socket.h>
end_include

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
comment|/* Portmapper client, server, and protocol headers */
end_comment

begin_include
include|#
directive|include
file|<rpc/pmap_clnt.h>
end_include

begin_include
include|#
directive|include
file|<rpc/pmap_prot.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<rpc/rpcb_clnt.h>
end_include

begin_comment
comment|/* rpcbind interface functions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<rpc/rpcent.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
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
name|registerrpc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|(
operator|*
operator|)
name|__P
argument_list|(
operator|(
name|char
index|[
name|UDPMSGSIZE
index|]
operator|)
argument_list|)
operator|,
name|xdrproc_t
operator|,
name|xdrproc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|callrpc
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|xdrproc_t
operator|,
name|void
operator|*
operator|,
name|xdrproc_t
operator|,
name|void
operator|*
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
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|taddr2uaddr
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|netconfig
operator|*
operator|,
specifier|const
expr|struct
name|netbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|netbuf
modifier|*
name|uaddr2taddr
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|netconfig
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

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
name|__END_DECLS
comment|/*  * The following are not exported interfaces, they are for internal library  * and rpcbind use only. Do not use, they may change without notice.  */
name|__BEGIN_DECLS
name|int
name|__rpc_nconf2fd
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|netconfig
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__rpc_nconf2sockinfo
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|netconfig
operator|*
operator|,
expr|struct
name|__rpc_sockinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__rpc_fd2sockinfo
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|__rpc_sockinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|__rpc_get_t_size
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
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

