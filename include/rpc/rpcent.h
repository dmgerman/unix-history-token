begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpcent.h,v 1.1 2000/06/02 22:57:56 fvdl Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
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

