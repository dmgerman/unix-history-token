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
literal|"@(#)cset.c	5.1 (Berkeley) 6/5/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_comment
comment|/*  * Constant sets  */
end_comment

begin_macro
name|cset
argument_list|(
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
operator|*
name|e
operator|,
operator|*
name|el
expr_stmt|;
name|ppbra
argument_list|(
literal|"["
argument_list|)
expr_stmt|;
name|el
operator|=
name|r
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
name|el
operator|!=
name|NIL
condition|)
for|for
control|(
init|;
condition|;
control|)
block|{
name|e
operator|=
name|el
index|[
literal|1
index|]
expr_stmt|;
name|el
operator|=
name|el
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
name|e
operator|==
name|NIL
condition|)
continue|continue;
if|if
condition|(
name|e
index|[
literal|0
index|]
operator|==
name|T_RANG
condition|)
block|{
name|rvalue
argument_list|(
name|e
index|[
literal|1
index|]
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
name|ppsep
argument_list|(
literal|".."
argument_list|)
expr_stmt|;
name|rvalue
argument_list|(
name|e
index|[
literal|2
index|]
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
block|}
else|else
name|rvalue
argument_list|(
name|e
argument_list|,
name|NIL
argument_list|)
expr_stmt|;
if|if
condition|(
name|el
operator|==
name|NIL
condition|)
break|break;
name|ppsep
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
block|}
name|ppket
argument_list|(
literal|"]"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

