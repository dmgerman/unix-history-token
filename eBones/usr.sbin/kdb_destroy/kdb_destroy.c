begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: kdb_destroy.c,v 4.0 89/01/24 21:49:02 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
endif|lint
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unistd.h>
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
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<krb_db.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_DBM_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
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
ifdef|#
directive|ifdef
name|_DBM_
name|char
name|dbm
index|[
literal|256
index|]
decl_stmt|;
comment|/* database path and name */
name|char
modifier|*
name|file
decl_stmt|;
comment|/* database file names */
else|#
directive|else
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
endif|#
directive|endif
name|strcpy
argument_list|(
name|dbm
argument_list|,
name|DBM_FILE
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|_DBM_
name|file
operator|=
name|strcat
argument_list|(
name|dbm
argument_list|,
literal|".db"
argument_list|)
expr_stmt|;
else|#
directive|else
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
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|_DBM_
if|if
condition|(
name|unlink
argument_list|(
name|file
argument_list|)
operator|==
literal|0
condition|)
else|#
directive|else
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
endif|#
directive|endif
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

