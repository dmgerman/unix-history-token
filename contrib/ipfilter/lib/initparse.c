begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * Id: initparse.c,v 1.6 2002/01/28 06:50:46 darrenr Exp  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_decl_stmt
name|char
name|thishost
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|initparse
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
block|{
name|gethostname
argument_list|(
name|thishost
argument_list|,
sizeof|sizeof
argument_list|(
name|thishost
argument_list|)
argument_list|)
expr_stmt|;
name|thishost
index|[
sizeof|sizeof
argument_list|(
name|thishost
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_decl_stmt

end_unit

