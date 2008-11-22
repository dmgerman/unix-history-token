begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: nettype.h,v 1.2 2000/07/06 03:17:19 christos Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
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

