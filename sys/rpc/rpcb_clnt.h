begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpcb_clnt.h,v 1.1 2000/06/02 22:57:56 fvdl Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,   *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,   *   this list of conditions and the following disclaimer in the documentation   *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its   *   contributors may be used to endorse or promote products derived   *   from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986 - 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * rpcb_clnt.h  * Supplies C routines to get to rpcbid services.  *  */
end_comment

begin_comment
comment|/*  * Usage:  *	success = rpcb_set(program, version, nconf, address);  *	success = rpcb_unset(program, version, nconf);  *	success = rpcb_getaddr(program, version, nconf, host);  *	head = rpcb_getmaps(nconf, host);  *	clnt_stat = rpcb_rmtcall(nconf, host, program, version, procedure,  *		xdrargs, argsp, xdrres, resp, tout, addr_ptr)  *	success = rpcb_gettime(host, timep)  *	uaddr = rpcb_taddr2uaddr(nconf, taddr);  *	taddr = rpcb_uaddr2uaddr(nconf, uaddr);  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_RPCB_CLNT_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_RPCB_CLNT_H
end_define

begin_comment
comment|/* #pragma ident	"@(#)rpcb_clnt.h	1.13	94/04/25 SMI" */
end_comment

begin_comment
comment|/* rpcb_clnt.h 1.3 88/12/05 SMI */
end_comment

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<rpc/rpcb_prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|rpcb_set
parameter_list|(
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
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
specifier|extern
name|bool_t
name|rpcb_unset
parameter_list|(
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
specifier|extern
name|rpcblist
modifier|*
name|rpcb_getmaps
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

begin_function_decl
specifier|extern
name|enum
name|clnt_stat
name|rpcb_rmtcall
parameter_list|(
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|rpcproc_t
parameter_list|,
specifier|const
name|xdrproc_t
parameter_list|,
specifier|const
name|caddr_t
parameter_list|,
specifier|const
name|xdrproc_t
parameter_list|,
specifier|const
name|caddr_t
parameter_list|,
specifier|const
name|struct
name|timeval
parameter_list|,
specifier|const
name|struct
name|netbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|rpcb_getaddr
parameter_list|(
specifier|const
name|rpcprog_t
parameter_list|,
specifier|const
name|rpcvers_t
parameter_list|,
specifier|const
name|struct
name|netconfig
modifier|*
parameter_list|,
name|struct
name|netbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|rpcb_gettime
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|rpcb_taddr2uaddr
parameter_list|(
name|struct
name|netconfig
modifier|*
parameter_list|,
name|struct
name|netbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|netbuf
modifier|*
name|rpcb_uaddr2taddr
parameter_list|(
name|struct
name|netconfig
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_RPCB_CLNT_H */
end_comment

end_unit

