begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)endgame.c	5.3 (Berkeley) %G%"
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
comment|/*  * endgame:  *	Do what's necessary at the end of the game  */
end_comment

begin_macro
name|endgame
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|char
name|ch
decl_stmt|;
name|prman
argument_list|()
expr_stmt|;
if|if
condition|(
name|Errors
operator|>=
name|MAXERRS
condition|)
name|Errors
operator|=
name|MAXERRS
operator|+
literal|2
expr_stmt|;
name|prword
argument_list|()
expr_stmt|;
name|prdata
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|MESGY
argument_list|,
name|MESGX
argument_list|)
expr_stmt|;
if|if
condition|(
name|Errors
operator|>
name|MAXERRS
condition|)
name|printw
argument_list|(
literal|"Sorry, the word was \"%s\"\n"
argument_list|,
name|Word
argument_list|)
expr_stmt|;
else|else
name|printw
argument_list|(
literal|"You got it!\n"
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|mvaddstr
argument_list|(
name|MESGY
operator|+
literal|1
argument_list|,
name|MESGX
argument_list|,
literal|"Another word? "
argument_list|)
expr_stmt|;
name|leaveok
argument_list|(
name|stdscr
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|ch
operator|=
name|readch
argument_list|()
operator|)
operator|==
literal|'n'
condition|)
name|die
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|ch
operator|==
literal|'y'
condition|)
break|break;
name|mvaddstr
argument_list|(
name|MESGY
operator|+
literal|2
argument_list|,
name|MESGX
argument_list|,
literal|"Please type 'y' or 'n'"
argument_list|)
expr_stmt|;
block|}
name|leaveok
argument_list|(
name|stdscr
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|MESGY
argument_list|,
name|MESGX
argument_list|)
expr_stmt|;
name|addstr
argument_list|(
literal|"\n\n\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

