begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#) Copyright (c) 1983 The Regents of the University of California.\n\  All rights reserved.\n"
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
literal|"@(#)rmdir.c	5.3 (Berkeley) %G%"
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
comment|/*  * Remove directory  */
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
name|int
name|errors
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
literal|"usage: rmdir directory ...\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|errors
operator|=
literal|0
init|;
operator|*
operator|++
name|argv
condition|;
control|)
if|if
condition|(
name|rmdir
argument_list|(
operator|*
name|argv
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"rmdir: "
argument_list|)
expr_stmt|;
name|perror
argument_list|(
operator|*
name|argv
argument_list|)
expr_stmt|;
name|errors
operator|=
literal|1
expr_stmt|;
block|}
name|exit
argument_list|(
name|errors
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

