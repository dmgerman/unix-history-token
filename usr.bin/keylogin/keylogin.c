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
literal|"@(#)keylogin.c 1.4 91/03/11 Copyr 1986 Sun Micro"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * Set secret key on local machine  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/key_prot.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
name|fullname
index|[
name|MAXNETNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|netstarg
name|netst
decl_stmt|;
if|if
condition|(
operator|!
name|getnetname
argument_list|(
name|fullname
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"netname lookup failed -- make sure the "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"system domain name is set.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|getsecretkey
argument_list|(
name|fullname
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
operator|(
name|netst
operator|.
name|st_priv_key
operator|)
argument_list|,
name|getpass
argument_list|(
literal|"Password:"
argument_list|)
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't find %s's secret key\n"
argument_list|,
name|fullname
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|netst
operator|.
name|st_priv_key
index|[
literal|0
index|]
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Password incorrect for %s\n"
argument_list|,
name|fullname
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|netst
operator|.
name|st_pub_key
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|netst
operator|.
name|st_netname
operator|=
name|strdup
argument_list|(
name|fullname
argument_list|)
expr_stmt|;
if|if
condition|(
name|key_setnet
argument_list|(
operator|&
name|netst
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Could not set %s's secret key\n"
argument_list|,
name|fullname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Maybe the keyserver is down?\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

end_unit

