begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/kdb_destroy/RCS/kdb_destroy.c,v $  * $Author: kfall $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Description.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_kdb_destroy_c
index|[]
init|=
literal|"$Header: /usr/src/kerberosIV/kdb_destroy/RCS/kdb_destroy.c,v 4.1 90/06/25 21:03:10 kfall Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"des.h"
end_include

begin_include
include|#
directive|include
file|"krb.h"
end_include

begin_include
include|#
directive|include
file|"krb_db.h"
end_include

begin_function
name|main
parameter_list|()
block|{
name|char
name|answer
index|[
literal|10
index|]
decl_stmt|;
comment|/* user input */
name|char
name|dbm
index|[
literal|256
index|]
decl_stmt|;
comment|/* database path and name */
name|char
name|dbm1
index|[
literal|256
index|]
decl_stmt|;
comment|/* database path and name */
name|char
modifier|*
name|file1
decl_stmt|,
modifier|*
name|file2
decl_stmt|;
comment|/* database file names */
name|strcpy
argument_list|(
name|dbm
argument_list|,
name|DBM_FILE
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|dbm1
argument_list|,
name|DBM_FILE
argument_list|)
expr_stmt|;
name|file1
operator|=
name|strcat
argument_list|(
name|dbm
argument_list|,
literal|".dir"
argument_list|)
expr_stmt|;
name|file2
operator|=
name|strcat
argument_list|(
name|dbm1
argument_list|,
literal|".pag"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"You are about to destroy the Kerberos database "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"on this machine.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Are you sure you want to do this (y/n)? "
argument_list|)
expr_stmt|;
name|fgets
argument_list|(
name|answer
argument_list|,
sizeof|sizeof
argument_list|(
name|answer
argument_list|)
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
if|if
condition|(
name|answer
index|[
literal|0
index|]
operator|==
literal|'y'
operator|||
name|answer
index|[
literal|0
index|]
operator|==
literal|'Y'
condition|)
block|{
if|if
condition|(
name|unlink
argument_list|(
name|file1
argument_list|)
operator|==
literal|0
operator|&&
name|unlink
argument_list|(
name|file2
argument_list|)
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Database deleted at %s\n"
argument_list|,
name|DBM_FILE
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Database cannot be deleted at %s\n"
argument_list|,
name|DBM_FILE
argument_list|)
expr_stmt|;
block|}
else|else
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Database not deleted.\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

