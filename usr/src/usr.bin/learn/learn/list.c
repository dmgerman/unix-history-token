begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)list.c	4.4 (Berkeley) %G%"
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
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"lrnref.h"
end_include

begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_decl_stmt
name|int
name|istop
decl_stmt|;
end_decl_stmt

begin_macro
name|list
argument_list|(
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|void
name|stop
argument_list|()
decl_stmt|,
name|intrpt
argument_list|()
decl_stmt|;
name|FILE
modifier|*
name|ft
decl_stmt|;
name|char
name|s
index|[
literal|100
index|]
decl_stmt|;
if|if
condition|(
name|r
operator|==
literal|0
condition|)
return|return;
name|istop
operator|=
literal|1
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|stop
argument_list|)
expr_stmt|;
name|ft
operator|=
name|fopen
argument_list|(
name|r
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ft
operator|!=
name|NULL
condition|)
block|{
while|while
condition|(
name|fgets
argument_list|(
name|s
argument_list|,
literal|100
argument_list|,
name|ft
argument_list|)
operator|&&
name|istop
condition|)
name|fputs
argument_list|(
name|s
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|ft
argument_list|)
expr_stmt|;
block|}
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|intrpt
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|void
name|stop
parameter_list|()
block|{
name|istop
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

