begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#) Copyright (c) 1983 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"@(#)mkdir.c	5.1 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * make directory  */
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
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|int
name|errors
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: %s directory ...\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
while|while
condition|(
operator|--
name|argc
condition|)
if|if
condition|(
name|mkdir
argument_list|(
operator|*
operator|++
name|argv
argument_list|,
literal|0777
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"mkdir: "
argument_list|)
expr_stmt|;
name|perror
argument_list|(
operator|*
name|argv
argument_list|)
expr_stmt|;
name|errors
operator|++
expr_stmt|;
block|}
name|exit
argument_list|(
name|errors
operator|!=
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

