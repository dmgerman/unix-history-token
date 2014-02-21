begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpcent.h,v 1.1 2000/06/02 22:57:56 fvdl Exp $	*/
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
comment|/*  * rpcent.h,  * For converting rpc program numbers to names etc.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_RPCENT_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_RPCENT_H
end_define

begin_comment
comment|/*	#pragma ident "@(#)rpcent.h   1.13    94/04/25 SMI"	*/
end_comment

begin_comment
comment|/*      @(#)rpcent.h 1.1 88/12/06 SMI   */
end_comment

begin_struct
struct|struct
name|rpcent
block|{
name|char
modifier|*
name|r_name
decl_stmt|;
comment|/* name of server for this rpc program */
name|char
modifier|*
modifier|*
name|r_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|r_number
decl_stmt|;
comment|/* rpc program number */
block|}
struct|;
end_struct

begin_expr_stmt
name|__BEGIN_DECLS
comment|/*  * These interfaces are currently implemented through nsswitch and are  * MT-safe.  */
specifier|extern
expr|struct
name|rpcent
operator|*
name|getrpcbyname
argument_list|(
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|struct
name|rpcent
modifier|*
name|getrpcbynumber
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rpcent
modifier|*
name|getrpcent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setrpcent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|endrpcent
parameter_list|(
name|void
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
comment|/* !_RPC_CENT_H */
end_comment

end_unit

