begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1989, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)echo.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
name|int
name|nflag
decl_stmt|;
comment|/* This utility may NOT do getopt(3) option parsing. */
if|if
condition|(
operator|*
operator|++
name|argv
operator|&&
operator|!
name|strcmp
argument_list|(
operator|*
name|argv
argument_list|,
literal|"-n"
argument_list|)
condition|)
block|{
operator|++
name|argv
expr_stmt|;
name|nflag
operator|=
literal|1
expr_stmt|;
block|}
else|else
name|nflag
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
name|argv
condition|)
block|{
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s"
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
operator|++
name|argv
condition|)
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|nflag
condition|)
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

