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
literal|"@(#)lab.c	5.1 (Berkeley) 6/5/85"
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

begin_comment
comment|/*  * Label declaration part  */
end_comment

begin_macro
name|label
argument_list|(
argument|r
argument_list|,
argument|l
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|r
decl_stmt|,
name|l
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
operator|*
name|ll
expr_stmt|;
if|if
condition|(
name|nodecl
condition|)
name|printoff
argument_list|()
expr_stmt|;
name|puthedr
argument_list|()
expr_stmt|;
name|setline
argument_list|(
name|l
argument_list|)
expr_stmt|;
name|ppnl
argument_list|()
expr_stmt|;
name|indent
argument_list|()
expr_stmt|;
name|ppkw
argument_list|(
literal|"label"
argument_list|)
expr_stmt|;
name|ppgoin
argument_list|(
name|DECL
argument_list|)
expr_stmt|;
name|ppnl
argument_list|()
expr_stmt|;
name|indent
argument_list|()
expr_stmt|;
name|ppbra
argument_list|(
name|NIL
argument_list|)
expr_stmt|;
name|ll
operator|=
name|r
expr_stmt|;
if|if
condition|(
name|ll
operator|!=
name|NIL
condition|)
for|for
control|(
init|;
condition|;
control|)
block|{
name|pplab
argument_list|(
name|ll
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|ll
operator|=
name|ll
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
name|ll
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
else|else
name|ppid
argument_list|(
literal|"{label list}"
argument_list|)
expr_stmt|;
name|ppket
argument_list|(
literal|";"
argument_list|)
expr_stmt|;
name|putcml
argument_list|()
expr_stmt|;
name|ppgoout
argument_list|(
name|DECL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Goto statement  */
end_comment

begin_macro
name|gotoop
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|gocnt
operator|++
expr_stmt|;
name|ppkw
argument_list|(
literal|"goto"
argument_list|)
expr_stmt|;
name|ppspac
argument_list|()
expr_stmt|;
name|pplab
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * A label on a statement  */
end_comment

begin_macro
name|labeled
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|linopr
argument_list|()
expr_stmt|;
name|indentlab
argument_list|()
expr_stmt|;
name|pplab
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|ppsep
argument_list|(
literal|":"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

