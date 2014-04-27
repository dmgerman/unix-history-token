begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpc_com.h,v 1.3 2000/12/10 04:10:08 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,   *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,   *   this list of conditions and the following disclaimer in the documentation   *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its   *   contributors may be used to endorse or promote products derived   *   from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_function_decl
name|struct
name|netbuf
modifier|*
name|__rpcb_findaddr_timed
parameter_list|(
name|rpcprog_t
parameter_list|,
name|rpcvers_t
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
name|CLIENT
modifier|*
modifier|*
name|clpp
parameter_list|,
name|struct
name|timeval
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|bool_t
name|__svc_clean_idle
parameter_list|(
name|fd_set
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bool_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|__xdrrec_setnonblock
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|__xdrrec_getrec
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|enum
name|xprt_stat
modifier|*
parameter_list|,
name|bool_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__xprt_unregister_unlocked
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|SVCXPRT
modifier|*
modifier|*
name|__svc_xports
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__svc_maxrec
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
comment|/* _RPC_RPCCOM_H */
end_comment

end_unit

