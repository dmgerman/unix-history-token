begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_comment
comment|/*static char *sccsid = "from: @(#)pmap_prot.c 1.17 87/08/11 Copyr 1984 Sun Micro";*/
end_comment

begin_comment
comment|/*static char *sccsid = "from: @(#)pmap_prot.c	2.1 88/07/29 4.0 RPCSRC";*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * pmap_prot.c  * Protocol for the local binder service, or pmap.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_include
include|#
directive|include
file|<rpc/xdr.h>
end_include

begin_include
include|#
directive|include
file|<rpc/pmap_prot.h>
end_include

begin_function
name|bool_t
name|xdr_pmap
parameter_list|(
name|xdrs
parameter_list|,
name|regs
parameter_list|)
name|XDR
modifier|*
name|xdrs
decl_stmt|;
name|struct
name|pmap
modifier|*
name|regs
decl_stmt|;
block|{
if|if
condition|(
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
name|regs
operator|->
name|pm_prog
argument_list|)
operator|&&
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
name|regs
operator|->
name|pm_vers
argument_list|)
operator|&&
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
name|regs
operator|->
name|pm_prot
argument_list|)
condition|)
return|return
operator|(
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
name|regs
operator|->
name|pm_port
argument_list|)
operator|)
return|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

end_unit

