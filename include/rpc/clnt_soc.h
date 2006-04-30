begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: clnt_soc.h,v 1.1 2000/06/02 22:57:55 fvdl Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1984 - 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * clnt.h - Client side remote procedure call interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_CLNT_SOC_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_CLNT_SOC_H
end_define

begin_comment
comment|/* derived from clnt_soc.h 1.3 88/12/17 SMI     */
end_comment

begin_comment
comment|/*  * All the following declarations are only for backward compatibility  * with TS-RPC.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|UDPMSGSIZE
value|8800
end_define

begin_comment
comment|/* rpc imposed limit on udp msg size */
end_comment

begin_comment
comment|/*  * TCP based rpc  * CLIENT *  * clnttcp_create(raddr, prog, vers, sockp, sendsz, recvsz)  *	struct sockaddr_in *raddr;  *	u_long prog;  *	u_long version;  *	register int *sockp;  *	u_int sendsz;  *	u_int recvsz;  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clnttcp_create
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * Raw (memory) rpc.  */
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clntraw_create
parameter_list|(
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
comment|/*  * UDP based rpc.  * CLIENT *  * clntudp_create(raddr, program, version, wait, sockp)  *	struct sockaddr_in *raddr;  *	u_long program;  *	u_long version;  *	struct timeval wait;  *	int *sockp;  *  * Same as above, but you specify max packet sizes.  * CLIENT *  * clntudp_bufcreate(raddr, program, version, wait, sockp, sendsz, recvsz)  *	struct sockaddr_in *raddr;  *	u_long program;  *	u_long version;  *	struct timeval wait;  *	int *sockp;  *	u_int sendsz;  *	u_int recvsz;  */
name|__BEGIN_DECLS
specifier|extern
name|CLIENT
modifier|*
name|clntudp_create
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|struct
name|timeval
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CLIENT
modifier|*
name|clntudp_bufcreate
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|struct
name|timeval
parameter_list|,
name|int
modifier|*
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
comment|/* _RPC_CLNT_SOC_H */
end_comment

end_unit

