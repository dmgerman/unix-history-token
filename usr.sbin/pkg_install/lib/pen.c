begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: pen.c,v 1.2 1993/09/04 05:06:51 jkh Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * FreeBSD install - a package for the installation and maintainance  * of non-core utilities.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Jordan K. Hubbard  * 18 July 1993  *  * Routines for managing the "play pen".  *  */
end_comment

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_comment
comment|/* For keeping track of where we are */
end_comment

begin_decl_stmt
specifier|static
name|char
name|Cwd
index|[
name|FILENAME_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|Pen
index|[
name|FILENAME_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Make a temporary directory to play in and chdir() to it, returning  * pathname of previous working directory.  */
end_comment

begin_function
name|char
modifier|*
name|make_playpen
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|getcwd
argument_list|(
name|Cwd
argument_list|,
name|FILENAME_MAX
argument_list|)
condition|)
name|upchuck
argument_list|(
literal|"getcwd"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|Pen
argument_list|,
literal|"/tmp/instmp.XXXXXX"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mktemp
argument_list|(
name|Pen
argument_list|)
condition|)
name|barf
argument_list|(
literal|"Can't mktemp '%s'."
argument_list|,
name|Pen
argument_list|)
expr_stmt|;
if|if
condition|(
name|mkdir
argument_list|(
name|Pen
argument_list|,
literal|0755
argument_list|)
operator|==
name|FAIL
condition|)
name|barf
argument_list|(
literal|"Can't mkdir '%s'."
argument_list|,
name|Pen
argument_list|)
expr_stmt|;
if|if
condition|(
name|chdir
argument_list|(
name|Pen
argument_list|)
operator|==
name|FAIL
condition|)
name|barf
argument_list|(
literal|"Can't chdir to '%s'."
argument_list|,
name|Pen
argument_list|)
expr_stmt|;
return|return
name|Cwd
return|;
block|}
end_function

begin_comment
comment|/* Convenience routine for getting out of playpen */
end_comment

begin_function
name|void
name|leave_playpen
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|Cwd
index|[
literal|0
index|]
condition|)
block|{
if|if
condition|(
name|chdir
argument_list|(
name|Cwd
argument_list|)
operator|==
name|FAIL
condition|)
name|barf
argument_list|(
literal|"Can't chdir back to '%s'."
argument_list|,
name|Cwd
argument_list|)
expr_stmt|;
if|if
condition|(
name|vsystem
argument_list|(
literal|"rm -rf %s"
argument_list|,
name|Pen
argument_list|)
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Couldn't remove temporary dir '%s'\n"
argument_list|,
name|Pen
argument_list|)
expr_stmt|;
name|Cwd
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
end_function

end_unit

