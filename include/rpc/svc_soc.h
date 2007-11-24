begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: svc_soc.h,v 1.1 2000/06/02 22:57:57 fvdl Exp $	*/
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
comment|/*  * svc.h, Server-side remote procedure call interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_SVC_SOC_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_SVC_SOC_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* #pragma ident   "@(#)svc_soc.h  1.11    94/04/25 SMI" */
end_comment

begin_comment
comment|/*      svc_soc.h 1.8 89/05/01 SMI      */
end_comment

begin_comment
comment|/*  * All the following declarations are only for backward compatibility  * with TS-RPC  */
end_comment

begin_comment
comment|/*  *  Approved way of getting address of caller  */
end_comment

begin_define
define|#
directive|define
name|svc_getcaller
parameter_list|(
name|x
parameter_list|)
value|(&(x)->xp_raddr)
end_define

begin_comment
comment|/*  * Service registration  *  * svc_register(xprt, prog, vers, dispatch, protocol)  *	SVCXPRT *xprt;  *	u_long prog;  *	u_long vers;  *	void (*dispatch)();  *	int protocol;    like TCP or UDP, zero means do not register   */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|svc_register
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Service un-registration  *  * svc_unregister(prog, vers)  *	u_long prog;  *	u_long vers;  */
name|__BEGIN_DECLS
specifier|extern
name|void
name|svc_unregister
parameter_list|(
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Memory based rpc for testing and timing.  */
name|__BEGIN_DECLS
specifier|extern
name|SVCXPRT
modifier|*
name|svcraw_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Udp based rpc.  */
name|__BEGIN_DECLS
specifier|extern
name|SVCXPRT
modifier|*
name|svcudp_create
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SVCXPRT
modifier|*
name|svcudp_bufcreate
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|svcudp_enablecache
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Tcp based rpc.  */
name|__BEGIN_DECLS
specifier|extern
name|SVCXPRT
modifier|*
name|svctcp_create
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Fd based rpc.  */
name|__BEGIN_DECLS
specifier|extern
name|SVCXPRT
modifier|*
name|svcfd_create
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
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
comment|/* !_RPC_SVC_SOC_H */
end_comment

end_unit

