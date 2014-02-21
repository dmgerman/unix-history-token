begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: svc_auth.h,v 1.8 2000/06/02 22:57:57 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,   *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,   *   this list of conditions and the following disclaimer in the documentation   *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its   *   contributors may be used to endorse or promote products derived   *   from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   * POSSIBILITY OF SUCH DAMAGE.  *  *	from: @(#)svc_auth.h 1.6 86/07/16 SMI  *	@(#)svc_auth.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * svc_auth.h, Service side of rpc authentication.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_SVC_AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_SVC_AUTH_H
end_define

begin_comment
comment|/*  * Server side authenticator  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|enum
name|auth_stat
name|_authenticate
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|struct
name|rpc_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|svc_auth_reg
argument_list|(
name|int
argument_list|,
expr|enum
name|auth_stat
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|svc_req
operator|*
argument_list|,
expr|struct
name|rpc_msg
operator|*
argument_list|)
argument_list|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|svc_req
operator|*
argument_list|,
expr|struct
name|ucred
operator|*
operator|*
argument_list|,
name|int
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|svc_auth_reg
argument_list|(
name|int
argument_list|,
expr|enum
name|auth_stat
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|svc_req
operator|*
argument_list|,
expr|struct
name|rpc_msg
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|svc_getcred
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * struct svc_req *req;                 -- RPC request  * struct ucred **crp			-- Kernel cred to modify  * int *flavorp				-- Return RPC auth flavor  *  * Retrieve unix creds corresponding to an RPC request, if  * possible. The auth flavor (AUTH_NONE or AUTH_UNIX) is returned in  * *flavorp. If the flavor is AUTH_UNIX the caller's ucred pointer  * will be modified to point at a ucred structure which reflects the  * values from the request. The caller should call crfree on this  * pointer.  *  * Return's non-zero if credentials were retrieved from the request,  * otherwise zero.  */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_SVC_AUTH_H */
end_comment

end_unit

