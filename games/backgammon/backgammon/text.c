begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)text.c	8.1 (Berkeley) 5/31/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
file|"back.h"
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|instr
index|[]
init|=
block|{
literal|"    If you did not notice by now, this program reacts to things as"
block|,
literal|"soon as you type them, without waiting for a newline.  This means that"
block|,
literal|"the special characters RUBOUT, ESC, and CONTROL-D, will not perform"
block|,
literal|"their special functions during most of this program.  The program"
block|,
literal|"should usually stop when a RUBOUT is typed, but occasionally it will"
block|,
literal|"ignore RUBOUTs until it is waiting for input.\n"
block|,
literal|"    These instructions are presented in small chunks designed not to"
block|,
literal|"roll off the top of your screen.  When the characters '-->' are print-"
block|,
literal|"ed, no more data will be printed until a space or newline is typed."
block|,
literal|"In this way, you can finish one section before continuing to another."
block|,
literal|"Like this:"
block|,
literal|""
block|,
literal|"    The two sides are colored 'red' and 'white.' The computer may play"
block|,
literal|"one side, or if there are two players, the computer can merely act as"
block|,
literal|"a gamekeeper, letting the players make the moves.  Once you tell the"
block|,
literal|"computer what color(s) you want to play, the decision remains in ef-"
block|,
literal|"fect until you quit the program, even if you play more than one game,"
block|,
literal|"since the program keeps a running score.\n"
block|,
literal|"    The program will prompt for a move in one of two ways.  If the"
block|,
literal|"player has the opportunity to double, then merely his color will be"
block|,
literal|"typed out.  The player can now do one of several things.  He can dou-"
block|,
literal|"ble by typing a 'd', he can roll by typing a space (' ') or newline,"
block|,
literal|"or if he is not sure, he can reprint the board by typing a 'r'.\n"
block|,
literal|"    If the player cannot double, his roll will be thrust in front of"
block|,
literal|"him, followed by the request 'Move:', asking for a move but not giving"
block|,
literal|"him the chance to double.  He can still ask for the board by typing"
block|,
literal|"'r'.  In either of these two states, the player can quit by typing 'q'"
block|,
literal|"or save the game by typing 's'.  In either case, the player will be"
block|,
literal|"asked to verify, in case there was some error.  The program then ends"
block|,
literal|"immediately, after first saving the file if so requested."
block|,
literal|""
block|,
literal|"    A player can move one of his men using two forms of input.  The"
block|,
literal|"first form is<s>-<f>, where<s> is the starting position, and<f> is"
block|,
literal|"the finishing position of the player's man.  For example, if white"
block|,
literal|"wanted to move a piece from position 13 to position 8, his move could"
block|,
literal|"be entered as 13-8.  The second form is<s>/<r> where<s> is the"
block|,
literal|"starting position, an<r> is the roll actually made.  Hence, white"
block|,
literal|"could have entered as 13/5 instead of 13-8.\n"
block|,
literal|"    A player must move each roll of the dice separately.  For example,"
block|,
literal|"if a player rolled 4 3, and wanted to move from 13 to 6, he could"
block|,
literal|"enter it as 13/4,9/3 or 13/3,10/4 or 13-10,10-6 or 13-9,9-6, but not"
block|,
literal|"13-6.  The last two entries can be shortened to 13-10-6 and 13-9-6."
block|,
literal|"If you want to move more than one piece from the same position, such"
block|,
literal|"as 13-10,13-9, you can abbreviate this using the<s>/<r> format as by"
block|,
literal|"entering more than one<r>, or 13/34.  A player can use both forms for"
block|,
literal|"the same roll, e.g. 13/3,13-9, and separates individual moves by ei-"
block|,
literal|"ther a comma or a space.  The letter 'b' represents the bar, and the"
block|,
literal|"letter 'h' represents a player's home.  You could also enter the"
block|,
literal|"number that would be in the position of the bar, 25 or 0 as appropri-"
block|,
literal|"ate.  Use a newline at the end of your moves for a turn."
block|,
literal|""
block|,
literal|"    As you type in your move, if a character does not make sense under"
block|,
literal|"the above constrictions, a bell will sound instead of the character,"
block|,
literal|"and it will be ignored.  You may kill lines and erase characters as"
block|,
literal|"you would normally, but don't be surprised if they look different than"
block|,
literal|"usual.  Also, if you have entered one or more of your rolls, and you"
block|,
literal|"wish to see what the move looks like so far, type a 'r' to see what it"
block|,
literal|"looks like.  This cannot be done in the middle of a move (e.g., after"
block|,
literal|"a '-' or '/').  After the printing board, the program will go back to"
block|,
literal|"inputting your move and you can backspace or kill just as if you had"
block|,
literal|"just typed in your input.\n"
block|,
literal|"    Now you should be ready to begin the game.  Good luck!"
block|,
literal|""
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_function
name|int
name|text
parameter_list|(
name|t
parameter_list|)
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|t
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|a
decl_stmt|;
name|fixtty
argument_list|(
name|noech
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|t
operator|!=
literal|0
condition|)
block|{
name|s
operator|=
name|a
operator|=
operator|*
name|t
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|*
name|a
operator|!=
literal|'\0'
condition|;
name|i
operator|--
control|)
name|a
operator|++
expr_stmt|;
if|if
condition|(
name|i
condition|)
block|{
name|writel
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|writec
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|writel
argument_list|(
literal|"-->"
argument_list|)
expr_stmt|;
name|fixtty
argument_list|(
name|raw
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|i
operator|=
name|readc
argument_list|()
operator|)
operator|!=
literal|' '
operator|&&
name|i
operator|!=
literal|'\n'
condition|)
empty_stmt|;
name|fixtty
argument_list|(
name|noech
argument_list|)
expr_stmt|;
name|clear
argument_list|()
expr_stmt|;
block|}
name|t
operator|++
expr_stmt|;
block|}
name|fixtty
argument_list|(
name|raw
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

