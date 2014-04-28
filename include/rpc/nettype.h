begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: nettype.h,v 1.2 2000/07/06 03:17:19 christos Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986 - 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * nettype.h, Nettype definitions.  * All for the topmost layer of rpc  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_NETTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_NETTYPE_H
end_define

begin_include
include|#
directive|include
file|<netconfig.h>
end_include

begin_define
define|#
directive|define
name|_RPC_NONE
value|0
end_define

begin_define
define|#
directive|define
name|_RPC_NETPATH
value|1
end_define

begin_define
define|#
directive|define
name|_RPC_VISIBLE
value|2
end_define

begin_define
define|#
directive|define
name|_RPC_CIRCUIT_V
value|3
end_define

begin_define
define|#
directive|define
name|_RPC_DATAGRAM_V
value|4
end_define

begin_define
define|#
directive|define
name|_RPC_CIRCUIT_N
value|5
end_define

begin_define
define|#
directive|define
name|_RPC_DATAGRAM_N
value|6
end_define

begin_define
define|#
directive|define
name|_RPC_TCP
value|7
end_define

begin_define
define|#
directive|define
name|_RPC_UDP
value|8
end_define

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|void
modifier|*
name|__rpc_setconf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__rpc_endconf
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|netconfig
modifier|*
name|__rpc_getconf
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|netconfig
modifier|*
name|__rpc_getconfip
parameter_list|(
specifier|const
name|char
modifier|*
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
comment|/* !_RPC_NETTYPE_H */
end_comment

end_unit

