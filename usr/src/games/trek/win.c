begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)win.c	5.4 (Berkeley) %G%"
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
file|"trek.h"
end_include

begin_include
include|#
directive|include
file|"getpar.h"
end_include

begin_comment
comment|/* **  Signal game won ** **	This routine prints out the win message, arranges to print out **	your score, tells you if you have a promotion coming to you, **	cleans up the current input line, and arranges to have you **	asked whether or not you want another game (via the reset() **	call). ** **	Pretty straightforward, although the promotion algorithm is **	pretty off the wall. */
end_comment

begin_macro
name|win
argument_list|()
end_macro

begin_block
block|{
name|long
name|s
decl_stmt|;
specifier|extern
name|long
name|score
parameter_list|()
function_decl|;
specifier|extern
name|struct
name|cvntab
name|Skitab
index|[]
decl_stmt|;
specifier|register
name|struct
name|cvntab
modifier|*
name|p
decl_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nCongratulations, you have saved the Federation\n"
argument_list|)
expr_stmt|;
name|Move
operator|.
name|endgame
operator|=
literal|1
expr_stmt|;
comment|/* print and return the score */
name|s
operator|=
name|score
argument_list|()
expr_stmt|;
comment|/* decide if she gets a promotion */
if|if
condition|(
name|Game
operator|.
name|helps
operator|==
literal|0
operator|&&
name|Game
operator|.
name|killb
operator|==
literal|0
operator|&&
name|Game
operator|.
name|killinhab
operator|==
literal|0
operator|&&
literal|5
operator|*
name|Game
operator|.
name|kills
operator|+
name|Game
operator|.
name|deaths
operator|<
literal|100
operator|&&
name|s
operator|>=
literal|1000
operator|&&
name|Ship
operator|.
name|ship
operator|==
name|ENTERPRISE
condition|)
block|{
name|printf
argument_list|(
literal|"In fact, you are promoted one step in rank,\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Game
operator|.
name|skill
operator|>=
literal|6
condition|)
name|printf
argument_list|(
literal|"to the exalted rank of Commodore Emeritus\n"
argument_list|)
expr_stmt|;
else|else
block|{
name|p
operator|=
operator|&
name|Skitab
index|[
name|Game
operator|.
name|skill
operator|-
literal|1
index|]
expr_stmt|;
name|printf
argument_list|(
literal|"from %s%s "
argument_list|,
name|p
operator|->
name|abrev
argument_list|,
name|p
operator|->
name|full
argument_list|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"to %s%s\n"
argument_list|,
name|p
operator|->
name|abrev
argument_list|,
name|p
operator|->
name|full
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* clean out input, and request new game */
name|skiptonl
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|reset
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

