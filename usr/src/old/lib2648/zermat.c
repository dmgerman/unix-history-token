begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)zermat.c	5.1 (Berkeley) 4/26/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * zermat: set a matrix to all zeros  */
end_comment

begin_include
include|#
directive|include
file|"bit.h"
end_include

begin_macro
name|zermat
argument_list|(
argument|m
argument_list|,
argument|rows
argument_list|,
argument|cols
argument_list|)
end_macro

begin_decl_stmt
name|bitmat
name|m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rows
decl_stmt|,
name|cols
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|size
init|=
operator|(
operator|(
name|cols
operator|+
literal|7
operator|)
operator|>>
literal|3
operator|)
operator|*
name|rows
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
operator|&
name|m
index|[
name|size
index|]
init|;
name|p
operator|>=
name|m
condition|;
control|)
operator|*
operator|--
name|p
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

