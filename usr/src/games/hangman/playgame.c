begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)playgame.c	8.1 (Berkeley) %G%"
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
file|"hangman.h"
end_include

begin_comment
comment|/*  * playgame:  *	play a game  */
end_comment

begin_macro
name|playgame
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|bool
modifier|*
name|bp
decl_stmt|;
name|getword
argument_list|()
expr_stmt|;
name|Errors
operator|=
literal|0
expr_stmt|;
name|bp
operator|=
name|Guessed
expr_stmt|;
while|while
condition|(
name|bp
operator|<
operator|&
name|Guessed
index|[
literal|26
index|]
condition|)
operator|*
name|bp
operator|++
operator|=
name|FALSE
expr_stmt|;
while|while
condition|(
name|Errors
operator|<
name|MAXERRS
operator|&&
name|index
argument_list|(
name|Known
argument_list|,
literal|'-'
argument_list|)
operator|!=
name|NULL
condition|)
block|{
name|prword
argument_list|()
expr_stmt|;
name|prdata
argument_list|()
expr_stmt|;
name|prman
argument_list|()
expr_stmt|;
name|getguess
argument_list|()
expr_stmt|;
block|}
name|endgame
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

