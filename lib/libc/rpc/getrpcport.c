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
comment|/*static char *sccsid = "from: @(#)getrpcport.c 1.3 87/08/11 SMI";*/
end_comment

begin_comment
comment|/*static char *sccsid = "from: @(#)getrpcport.c	2.1 88/07/29 4.0 RPCSRC";*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: getrpcport.c,v 1.2 1995/05/30 05:41:22 rgrimes Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (c) 1985 by Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_macro
name|getrpcport
argument_list|(
argument|host
argument_list|,
argument|prognum
argument_list|,
argument|versnum
argument_list|,
argument|proto
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|host
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|;
if|if
condition|(
operator|(
name|hp
operator|=
name|gethostbyname
argument_list|(
name|host
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|bcopy
argument_list|(
name|hp
operator|->
name|h_addr
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|addr
operator|.
name|sin_addr
argument_list|,
name|hp
operator|->
name|h_length
argument_list|)
expr_stmt|;
name|addr
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|addr
operator|.
name|sin_port
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|pmap_getport
argument_list|(
operator|&
name|addr
argument_list|,
name|prognum
argument_list|,
name|versnum
argument_list|,
name|proto
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

