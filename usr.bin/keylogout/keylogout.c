begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user or with the express written consent of  * Sun Microsystems, Inc.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * unset the secret key on local machine  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<rpc/key_prot.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|static
name|char
name|secret
index|[
name|HEXKEYBYTES
operator|+
literal|1
index|]
decl_stmt|;
if|if
condition|(
name|geteuid
argument_list|()
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|argc
operator|!=
literal|2
operator|)
operator|||
operator|(
name|strcmp
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"-f"
argument_list|)
operator|!=
literal|0
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"keylogout by root would break all servers that use secure rpc!\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"root may use keylogout -f to do this (at your own risk)!\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|key_setsecret
argument_list|(
name|secret
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Could not unset your secret key.\n"
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

