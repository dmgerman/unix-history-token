begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user or with the express written consent of  * Sun Microsystems, Inc.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
name|defined
argument_list|(
name|SCCSIDS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)rwall.c	1.2 91/03/11 TIRPC 1.0; from  1.3 89/03/24 SMI"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (c) 1985 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * "High" level programmatic interface to rwall RPC service.  */
end_comment

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpcsvc/rwall.h>
end_include

begin_function
name|int
name|rwall
parameter_list|(
name|host
parameter_list|,
name|msg
parameter_list|)
name|char
modifier|*
name|host
decl_stmt|;
name|char
modifier|*
name|msg
decl_stmt|;
block|{
return|return
operator|(
name|callrpc
argument_list|(
name|host
argument_list|,
name|WALLPROG
argument_list|,
name|WALLVERS
argument_list|,
name|WALLPROC_WALL
argument_list|,
name|xdr_wrapstring
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|msg
argument_list|,
name|xdr_void
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

