begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)endgame.c	5.3 (Berkeley) 6/1/90"
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

