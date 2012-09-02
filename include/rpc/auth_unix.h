begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)auth_unix.h 1.8 88/02/08 SMI  *	from: @(#)auth_unix.h	2.2 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* The machine name is part of a credential; it may not exceed 255 bytes */
define|#
directive|define
name|MAX_MACHINE_NAME
value|255
comment|/* gids compose part of a credential; there may not be more than 16 of them */
define|#
directive|define
name|NGRPS
value|16
comment|/*  * Unix style credentials.  */
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
name|uid_t
name|aup_uid
decl_stmt|;
name|gid_t
name|aup_gid
decl_stmt|;
name|u_int
name|aup_len
decl_stmt|;
name|gid_t
modifier|*
name|aup_gids
decl_stmt|;
block|}
struct|;
define|#
directive|define
name|authsys_parms
value|authunix_parms
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
name|__END_DECLS
comment|/*  * If a response verifier has flavor AUTH_SHORT,  * then the body of the response verifier encapsulates the following structure;  * again it is serialized in the obvious fashion.  */
struct|struct
name|short_hand_verf
block|{
name|struct
name|opaque_auth
name|new_cred
decl_stmt|;
block|}
struct|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_AUTH_UNIX_H */
end_comment

end_unit

