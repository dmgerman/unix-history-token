begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986 - 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * rpc_com.h, Common definitions for both the server and client side.  * All for the topmost layer of rpc  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_RPCCOM_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_RPCCOM_H
end_define

begin_comment
comment|/* From: #pragma ident	"@(#)rpc_com.h	1.11	93/07/05 SMI" */
end_comment

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
comment|/*  * File descriptor to be used on xxx_create calls to get default descriptor  */
define|#
directive|define
name|RPC_ANYSOCK
value|-1
define|#
directive|define
name|RPC_ANYFD
value|RPC_ANYSOCK
comment|/*  * The max size of the transport, if the size cannot be determined  * by other means.  */
define|#
directive|define
name|RPC_MAXDATASIZE
value|9000
define|#
directive|define
name|RPC_MAXADDRSIZE
value|1024
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
specifier|extern
name|u_int
name|__rpc_get_t_size
parameter_list|(
name|int
parameter_list|,
name|long
parameter_list|)
function_decl|;
specifier|extern
name|u_int
name|__rpc_get_a_size
parameter_list|(
name|long
parameter_list|)
function_decl|;
specifier|extern
name|int
name|__rpc_dtbsize
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_rpc_dtablesize
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|int
name|_rpc_get_default_domain
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|u_int
name|__rpc_get_t_size
parameter_list|()
function_decl|;
specifier|extern
name|u_int
name|__rpc_get_a_size
parameter_list|()
function_decl|;
specifier|extern
name|int
name|__rpc_dtbsize
parameter_list|()
function_decl|;
specifier|extern
name|int
name|_rpc_dtablesize
parameter_list|()
function_decl|;
specifier|extern
name|int
name|_rpc_get_default_domain
parameter_list|()
function_decl|;
endif|#
directive|endif
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
comment|/* _RPC_RPCCOM_H */
end_comment

end_unit

