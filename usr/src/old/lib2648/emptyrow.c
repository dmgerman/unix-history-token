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
literal|"@(#)emptyrow.c	5.1 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * emptyrow: returns true if row r of m is all zeros.  *  * Note that we assume the garbage at the end of the  * row is all zeros.  */
end_comment

begin_include
include|#
directive|include
file|"bit.h"
end_include

begin_macro
name|emptyrow
argument_list|(
argument|m
argument_list|,
argument|rows
argument_list|,
argument|cols
argument_list|,
argument|r
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
decl_stmt|,
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|top
decl_stmt|,
modifier|*
name|bot
decl_stmt|;
name|bot
operator|=
operator|&
name|m
index|[
name|r
operator|*
operator|(
operator|(
name|cols
operator|+
literal|7
operator|)
operator|>>
literal|3
operator|)
index|]
expr_stmt|;
name|top
operator|=
name|bot
operator|+
operator|(
operator|(
name|cols
operator|-
literal|1
operator|)
operator|>>
literal|3
operator|)
expr_stmt|;
while|while
condition|(
name|bot
operator|<=
name|top
condition|)
if|if
condition|(
operator|*
name|bot
operator|++
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

