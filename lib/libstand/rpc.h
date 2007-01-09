begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpc.h,v 1.8 1996/09/26 23:22:03 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* XXX defines we can't easily get from system includes */
end_comment

begin_define
define|#
directive|define
name|PMAPPORT
value|111
end_define

begin_define
define|#
directive|define
name|PMAPPROG
value|100000
end_define

begin_define
define|#
directive|define
name|PMAPVERS
value|2
end_define

begin_define
define|#
directive|define
name|PMAPPROC_NULL
value|0
end_define

begin_define
define|#
directive|define
name|PMAPPROC_SET
value|1
end_define

begin_define
define|#
directive|define
name|PMAPPROC_UNSET
value|2
end_define

begin_define
define|#
directive|define
name|PMAPPROC_GETPORT
value|3
end_define

begin_define
define|#
directive|define
name|PMAPPROC_DUMP
value|4
end_define

begin_define
define|#
directive|define
name|PMAPPROC_CALLIT
value|5
end_define

begin_comment
comment|/* RPC functions: */
end_comment

begin_function_decl
name|ssize_t
name|rpc_call
parameter_list|(
name|struct
name|iodesc
modifier|*
parameter_list|,
name|n_long
parameter_list|,
name|n_long
parameter_list|,
name|n_long
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpc_fromaddr
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpc_pmap_getcache
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpc_pmap_putcache
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|rpc_port
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* decrement before bind */
end_comment

begin_comment
comment|/*  * How much space to leave in front of RPC requests.  * In 32-bit words (alignment) we have:  * 12: Ether + IP + UDP + padding  *  6: RPC call header  *  7: Auth UNIX  *  2: Auth NULL  */
end_comment

begin_define
define|#
directive|define
name|RPC_HEADER_WORDS
value|28
end_define

end_unit

