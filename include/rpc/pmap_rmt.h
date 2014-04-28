begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pmap_rmt.h,v 1.7 1998/02/11 23:01:23 lukem Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: @(#)pmap_rmt.h 1.2 88/02/08 SMI  *	from: @(#)pmap_rmt.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Structures and XDR routines for parameters to and replies from  * the portmapper remote-call-service.  *  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_PMAP_RMT_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_PMAP_RMT_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct
struct|struct
name|rmtcallargs
block|{
name|u_long
name|prog
decl_stmt|,
name|vers
decl_stmt|,
name|proc
decl_stmt|,
name|arglen
decl_stmt|;
name|caddr_t
name|args_ptr
decl_stmt|;
name|xdrproc_t
name|xdr_args
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmtcallres
block|{
name|u_long
modifier|*
name|port_ptr
decl_stmt|;
name|u_long
name|resultslen
decl_stmt|;
name|caddr_t
name|results_ptr
decl_stmt|;
name|xdrproc_t
name|xdr_results
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|xdr_rmtcall_args
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|rmtcallargs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_rmtcallres
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|rmtcallres
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
comment|/* !_RPC_PMAP_RMT_H */
end_comment

end_unit

