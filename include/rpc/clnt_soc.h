begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: clnt_soc.h,v 1.1 2000/06/02 22:57:55 fvdl Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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

