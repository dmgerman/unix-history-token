begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: authunix_prot.c,v 1.12 2000/01/22 22:19:17 mycroft Exp $	*/
end_comment

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

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)authunix_prot.c 1.15 87/08/11 Copyr 1984 Sun Micro"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)authunix_prot.c	2.1 88/07/29 4.0 RPCSRC"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * authunix_prot.c  * XDR for UNIX style authentication parameters for RPC  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

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
file|<rpc/auth.h>
end_include

begin_include
include|#
directive|include
file|<rpc/auth_unix.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_comment
comment|/*  * XDR for unix authentication parameters.  */
end_comment

begin_function
name|bool_t
name|xdr_authunix_parms
parameter_list|(
name|xdrs
parameter_list|,
name|p
parameter_list|)
name|XDR
modifier|*
name|xdrs
decl_stmt|;
name|struct
name|authunix_parms
modifier|*
name|p
decl_stmt|;
block|{
name|assert
argument_list|(
name|xdrs
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|p
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|xdr_u_long
argument_list|(
name|xdrs
argument_list|,
operator|&
operator|(
name|p
operator|->
name|aup_time
operator|)
argument_list|)
operator|&&
name|xdr_string
argument_list|(
name|xdrs
argument_list|,
operator|&
operator|(
name|p
operator|->
name|aup_machname
operator|)
argument_list|,
name|MAX_MACHINE_NAME
argument_list|)
operator|&&
name|xdr_int
argument_list|(
name|xdrs
argument_list|,
operator|&
operator|(
name|p
operator|->
name|aup_uid
operator|)
argument_list|)
operator|&&
name|xdr_int
argument_list|(
name|xdrs
argument_list|,
operator|&
operator|(
name|p
operator|->
name|aup_gid
operator|)
argument_list|)
operator|&&
name|xdr_array
argument_list|(
name|xdrs
argument_list|,
operator|(
name|caddr_t
operator|*
operator|)
operator|&
operator|(
name|p
operator|->
name|aup_gids
operator|)
argument_list|,
operator|&
operator|(
name|p
operator|->
name|aup_len
operator|)
argument_list|,
name|NGRPS
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|,
operator|(
name|xdrproc_t
operator|)
name|xdr_int
argument_list|)
condition|)
block|{
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

end_unit

