begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpc.h,v 1.13 2000/06/02 22:57:56 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: @(#)rpc.h 1.9 88/02/08 SMI  *	from: @(#)rpc.h	2.4 89/07/11 4.0 RPCSRC  * $FreeBSD$  */
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

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|get_myaddress
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bindresvport
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|registerrpc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|char
index|[
name|UDPMSGSIZE
index|]
parameter_list|)
parameter_list|,
name|xdrproc_t
parameter_list|,
name|xdrproc_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|callrpc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|xdrproc_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|xdrproc_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getrpcport
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|taddr2uaddr
parameter_list|(
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|,
specifier|const
name|struct
name|netbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netbuf
modifier|*
name|uaddr2taddr
parameter_list|(
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|bindresvport_sa
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * The following are not exported interfaces, they are for internal library  * and rpcbind use only. Do not use, they may change without notice.  */
name|__BEGIN_DECLS
name|int
name|__rpc_nconf2fd
parameter_list|(
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rpc_nconf2sockinfo
parameter_list|(
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|,
name|struct
name|__rpc_sockinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rpc_fd2sockinfo
parameter_list|(
name|int
parameter_list|,
name|struct
name|__rpc_sockinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|__rpc_get_t_size
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
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
comment|/* !_RPC_RPC_H */
end_comment

end_unit

