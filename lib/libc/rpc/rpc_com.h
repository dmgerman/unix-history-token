begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpc_com.h,v 1.3 2000/12/10 04:10:08 christos Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986 - 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * rpc_com.h, Common definitions for both the server and client side.  * All for the topmost layer of rpc  *  * In Sun's tirpc distribution, this was installed as<rpc/rpc_com.h>,  * but as it contains only non-exported interfaces, it was moved here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_RPCCOM_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_RPCCOM_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* #pragma ident	"@(#)rpc_com.h	1.11	93/07/05 SMI" */
end_comment

begin_comment
comment|/*  * The max size of the transport, if the size cannot be determined  * by other means.  */
end_comment

begin_define
define|#
directive|define
name|RPC_MAXDATASIZE
value|9000
end_define

begin_define
define|#
directive|define
name|RPC_MAXADDRSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|__RPC_GETXID
parameter_list|(
name|now
parameter_list|)
value|((u_int32_t)getpid() ^ (u_int32_t)(now)->tv_sec ^ \     (u_int32_t)(now)->tv_usec)
end_define

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|u_int
name|__rpc_get_a_size
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__rpc_dtbsize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|netconfig
modifier|*
name|__rpcgettp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__rpc_get_default_domain
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|__rpc_taddr2uaddr_af
parameter_list|(
name|int
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
name|__rpc_uaddr2taddr_af
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rpc_fixup_addr
parameter_list|(
name|struct
name|netbuf
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
name|int
name|__rpc_sockinfo2netid
parameter_list|(
name|struct
name|__rpc_sockinfo
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rpc_seman2socktype
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rpc_socktype2seman
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rpc_nullproc
parameter_list|(
name|CLIENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__rpc_sockisbound
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|netbuf
modifier|*
name|__rpcb_findaddr
name|__P
argument_list|(
operator|(
name|rpcprog_t
operator|,
name|rpcvers_t
operator|,
specifier|const
expr|struct
name|netconfig
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|CLIENT
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool_t
name|__rpc_control
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|_get_next_token
parameter_list|(
name|char
modifier|*
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
comment|/* _RPC_RPCCOM_H */
end_comment

end_unit

