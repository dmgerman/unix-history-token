begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)svc_auth.h 1.6 86/07/16 SMI  *	from: @(#)svc_auth.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * svc_auth.h, Service side of rpc authentication.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_SVCAUTH_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_SVCAUTH_H
end_define

begin_struct_decl
struct_decl|struct
name|rpc_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|svc_req
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Server side authenticator  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|enum
name|auth_stat
name|_authenticate
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
expr|struct
name|rpc_msg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|svc_auth_reg
name|__P
argument_list|(
operator|(
name|int
operator|,
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|auth_stat
name|_svcauth_des
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
expr|struct
name|rpc_msg
operator|*
operator|)
argument_list|)
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
comment|/* !_RPC_SVCAUTH_H */
end_comment

end_unit

