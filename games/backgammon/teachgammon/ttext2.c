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
unit|static char sccsid[] = "@(#)ttext2.c	8.1 (Berkeley) 5/31/93";
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
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|list
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|prompt
decl_stmt|,
modifier|*
name|opts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|doubl
index|[]
init|=
block|{
literal|"\nDoubling:"
block|,
literal|"\n   If a player thinks he is in a good position, he may double the"
block|,
literal|"value of the game.  However, his opponent may not accept the pro-"
block|,
literal|"posal and forfeit the game before the price gets too high.  A"
block|,
literal|"player must double before he rolls, and once his double has been"
block|,
literal|"accepted, he cannot double again, until his opponent has doubled."
block|,
literal|"Thus, unless the game swings back and forth in advantage between"
block|,
literal|"the two players a great deal, the value of the game should be"
block|,
literal|"low.  At any rate, the value of the game will never go above 64,"
block|,
literal|"or six doubles.  However, if a player wins a backgammon at 64"
block|,
literal|"points, he wins 192 points!"
block|,
literal|""
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|stragy
index|[]
init|=
block|{
literal|"\nStrategy:"
block|,
literal|"\n   Some general hints when playing:  Try not to leave men open"
block|,
literal|"unless absolutely necessary.  Also, it is good to make as many"
block|,
literal|"points as possible.  Often, two men from different positions can"
block|,
literal|"be brought together to form a new point.  Although walls (six"
block|,
literal|"points in a row) are difficult to form, many points nestled close-"
block|,
literal|"ly together produce a formidable barrier.  Also, while it is good"
block|,
literal|"to move back men forward, doing so lessens the opportunity for you"
block|,
literal|"to hit men.  Finally, remember that once the two player's have"
block|,
literal|"passed each other on the board, there is no chance of either team"
block|,
literal|"being hit, so the game reduces to a race off the board.  Addi-"
block|,
literal|"tional hints on strategy are presented in the practice game."
block|,
literal|""
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|prog
index|[]
init|=
block|{
literal|"\nThe Program and How It Works:"
block|,
literal|"\n   A general rule of thumb is when you don't know what to do,"
block|,
literal|"type a question mark, and you should get some help.  When it is"
block|,
literal|"your turn, only your color will be printed out, with nothing"
block|,
literal|"after it.  You may double by typing a 'd', but if you type a"
block|,
literal|"space or newline, you will get your roll.  (Remember, you must"
block|,
literal|"double before you roll.)  Also, typing a 'r' will reprint the"
block|,
literal|"board, and a 'q' will quit the game.  The program will type"
block|,
literal|"'Move:' when it wants your move, and you may indicate each die's"
block|,
literal|"move with<s>-<f>, where<s> is the starting position and<f> is"
block|,
literal|"the finishing position, or<s>/<r> where<r> is the roll made."
block|,
literal|"<s>-<f1>-<f2> is short for<s>-<f1>,<f1>-<f2> and<s>/<r1><r2> is"
block|,
literal|"short for<s>/<r1>,<s>/<r2>.  Moves may be separated by a comma"
block|,
literal|"or a space."
block|,
literal|""
block|,
literal|"\n   While typing, any input which does not make sense will not be"
block|,
literal|"echoed, and a bell will sound instead.  Also, backspacing and"
block|,
literal|"killing lines will echo differently than normal.  You may examine"
block|,
literal|"the board by typing a 'r' if you have made a partial move, or be-"
block|,
literal|"fore you type a newline, to see what the board looks like.  You"
block|,
literal|"must end your move with a newline.  If you cannot double, your"
block|,
literal|"roll will always be printed, and you will not be given the oppor-"
block|,
literal|"tunity to double.  Home and bar are represented by the appropri-"
block|,
literal|"ate number, 0 or 25 as the case may be, or by the letters 'h' or"
block|,
literal|"'b' as appropriate.  You may also type 'r' or 'q' when the program"
block|,
literal|"types 'Move:', which has the same effect as above.  Finally, you"
block|,
literal|"will get to decide if you want to play red or white (or both if you"
block|,
literal|"want to play a friend) at the beginning of the session, and you"
block|,
literal|"will not get to change your mind later, since the computer keeps"
block|,
literal|"score."
block|,
literal|""
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|lastch
index|[]
init|=
block|{
literal|"\nTutorial (Practice Game):"
block|,
literal|"\n   This tutorial, for simplicity's sake, will let you play one"
block|,
literal|"predetermined game.  All the rolls have been pre-arranged, and"
block|,
literal|"only one response will let you advance to the next move."
block|,
literal|"Although a given roll will may have several legal moves, the tu-"
block|,
literal|"torial will only accept one (not including the same moves in a"
block|,
literal|"different order), claiming that that move is 'best.'  Obviously,"
block|,
literal|"a subjective statement.  At any rate, be patient with it and have"
block|,
literal|"fun learning about backgammon.  Also, to speed things up a lit-"
block|,
literal|"tle, doubling will not take place in the tutorial, so you will"
block|,
literal|"never get that opportunity, and quitting only leaves the tutori-"
block|,
literal|"al, not the game.  You will still be able to play backgammon"
block|,
literal|"after quitting."
block|,
literal|"\n   This is your last chance to look over the rules before the tu-"
block|,
literal|"torial starts."
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
name|txt
parameter_list|)
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|txt
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|begin
decl_stmt|;
specifier|const
name|char
modifier|*
name|a
decl_stmt|;
name|char
name|b
decl_stmt|;
specifier|const
name|char
modifier|*
name|c
decl_stmt|;
name|int
name|i
decl_stmt|;
name|fixtty
argument_list|(
name|noech
argument_list|)
expr_stmt|;
name|begin
operator|=
name|txt
expr_stmt|;
while|while
condition|(
operator|*
name|txt
condition|)
block|{
name|a
operator|=
operator|*
operator|(
name|txt
operator|++
operator|)
expr_stmt|;
if|if
condition|(
operator|*
name|a
operator|!=
literal|'\0'
condition|)
block|{
name|c
operator|=
name|a
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|*
operator|(
name|c
operator|++
operator|)
operator|!=
literal|'\0'
condition|;
name|i
operator|--
control|)
empty_stmt|;
name|writel
argument_list|(
name|a
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
name|fixtty
argument_list|(
name|raw
argument_list|)
expr_stmt|;
name|writel
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|(
name|b
operator|=
name|readc
argument_list|()
operator|)
operator|==
literal|'?'
condition|)
block|{
if|if
condition|(
name|tflag
condition|)
block|{
if|if
condition|(
name|begscr
condition|)
block|{
name|curmove
argument_list|(
literal|18
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|clend
argument_list|()
expr_stmt|;
block|}
else|else
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
name|writec
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|text
argument_list|(
name|list
argument_list|)
expr_stmt|;
name|writel
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|i
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|b
operator|==
literal|'\n'
condition|)
break|break;
while|while
condition|(
name|i
operator|<
literal|11
condition|)
block|{
if|if
condition|(
name|b
operator|==
name|opts
index|[
name|i
index|]
condition|)
break|break;
name|i
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|i
operator|==
literal|11
condition|)
name|writec
argument_list|(
literal|'\007'
argument_list|)
expr_stmt|;
else|else
break|break;
block|}
if|if
condition|(
name|tflag
condition|)
block|{
if|if
condition|(
name|begscr
condition|)
block|{
name|curmove
argument_list|(
literal|18
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|clend
argument_list|()
expr_stmt|;
block|}
else|else
name|clear
argument_list|()
expr_stmt|;
block|}
else|else
name|writec
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
condition|)
return|return
operator|(
name|i
operator|)
return|;
name|fixtty
argument_list|(
name|noech
argument_list|)
expr_stmt|;
if|if
condition|(
name|tflag
condition|)
name|curmove
argument_list|(
name|curr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|begin
operator|=
name|txt
expr_stmt|;
block|}
block|}
name|fixtty
argument_list|(
name|raw
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

