begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * Id: printifname.c,v 1.2 2002/01/28 06:50:47 darrenr Exp  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_function
name|void
name|printifname
parameter_list|(
name|format
parameter_list|,
name|name
parameter_list|,
name|ifp
parameter_list|)
name|char
modifier|*
name|format
decl_stmt|,
decl|*
name|name
decl_stmt|;
end_function

begin_decl_stmt
name|void
modifier|*
name|ifp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%s%s"
argument_list|,
name|format
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ifp
operator|==
name|NULL
operator|)
operator|&&
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"-"
argument_list|)
operator|&&
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"*"
argument_list|)
condition|)
name|printf
argument_list|(
literal|"(!)"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

