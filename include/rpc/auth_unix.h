begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: @(#)auth_unix.h 1.8 88/02/08 SMI  *	from: @(#)auth_unix.h	2.2 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * auth_unix.h, Protocol for UNIX style authentication parameters for RPC  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * The system is very weak.  The client uses no encryption for  it  * credentials and only sends null verifiers.  The server sends backs  * null verifiers or optionally a verifier that suggests a new short hand  * for the credentials.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_AUTH_UNIX_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_AUTH_UNIX_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* The machine name is part of a credential; it may not exceed 255 bytes */
end_comment

begin_define
define|#
directive|define
name|MAX_MACHINE_NAME
value|255
end_define

begin_comment
comment|/* gids compose part of a credential; there may not be more than 16 of them */
end_comment

begin_define
define|#
directive|define
name|NGRPS
value|16
end_define

begin_comment
comment|/*  * Unix style credentials.  */
end_comment

begin_struct
struct|struct
name|authunix_parms
block|{
name|u_long
name|aup_time
decl_stmt|;
name|char
modifier|*
name|aup_machname
decl_stmt|;
name|u_int
name|aup_uid
decl_stmt|;
name|u_int
name|aup_gid
decl_stmt|;
name|u_int
name|aup_len
decl_stmt|;
name|u_int
modifier|*
name|aup_gids
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|authsys_parms
value|authunix_parms
end_define

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|xdr_authunix_parms
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|authunix_parms
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * If a response verifier has flavor AUTH_SHORT,  * then the body of the response verifier encapsulates the following structure;  * again it is serialized in the obvious fashion.  */
end_comment

begin_struct
struct|struct
name|short_hand_verf
block|{
name|struct
name|opaque_auth
name|new_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_AUTH_UNIX_H */
end_comment

end_unit

