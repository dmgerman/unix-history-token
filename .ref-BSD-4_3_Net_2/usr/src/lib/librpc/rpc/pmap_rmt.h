begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)pmap_rmt.h	2.1 88/07/29 4.0 RPCSRC; from 1.2 88/02/08 SMI */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Structures and XDR routines for parameters to and replies from  * the portmapper remote-call-service.  *  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

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

begin_function_decl
name|bool_t
name|xdr_rmtcall_args
parameter_list|()
function_decl|;
end_function_decl

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
name|bool_t
name|xdr_rmtcallres
parameter_list|()
function_decl|;
end_function_decl

end_unit

