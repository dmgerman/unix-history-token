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
literal|"@(#)sync.c	5.1 (Berkeley) 4/26/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Make the screen& screen mode look like what it's supposed to.  *  * There are two basic things to do here, put the _pen  * in the right place, and make the line drawing mode be right.  * We don't sync the cursor here, only when there's user input& it's on.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|sync
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|_supx
operator|!=
name|_penx
operator|||
name|_supy
operator|!=
name|_peny
condition|)
block|{
name|escseq
argument_list|(
name|ESCP
argument_list|)
expr_stmt|;
name|outchar
argument_list|(
literal|'a'
argument_list|)
expr_stmt|;
name|motion
argument_list|(
name|_supx
argument_list|,
name|_supy
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|_supsmode
operator|!=
name|_actsmode
condition|)
block|{
name|escseq
argument_list|(
name|ESCM
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|_actsmode
operator|=
name|_supsmode
condition|)
block|{
case|case
name|MX
case|:
name|outchar
argument_list|(
literal|'3'
argument_list|)
expr_stmt|;
break|break;
case|case
name|MC
case|:
name|outchar
argument_list|(
literal|'1'
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS
case|:
name|outchar
argument_list|(
literal|'2'
argument_list|)
expr_stmt|;
break|break;
block|}
name|outchar
argument_list|(
literal|'a'
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

