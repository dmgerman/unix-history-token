begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1987 Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)dirname.c	5.5 (Berkeley) %G%"
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

begin_function
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
modifier|*
name|argv
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: dirname path\n"
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
name|p
operator|=
name|rindex
argument_list|(
operator|*
operator|++
name|argv
argument_list|,
literal|'/'
argument_list|)
condition|)
if|if
condition|(
name|p
operator|>
operator|*
name|argv
condition|)
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
else|else
operator|*
operator|++
name|p
operator|=
literal|'\0'
expr_stmt|;
else|else
operator|*
name|argv
operator|=
literal|"."
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
operator|*
name|argv
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

