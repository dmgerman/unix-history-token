begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)back.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_define
define|#
directive|define
name|rnum
parameter_list|(
name|r
parameter_list|)
value|(random()%r)
end_define

begin_define
define|#
directive|define
name|D0
value|dice[0]
end_define

begin_define
define|#
directive|define
name|D1
value|dice[1]
end_define

begin_define
define|#
directive|define
name|swap
value|{D0 ^= D1; D1 ^= D0; D0 ^= D1; d0 = 1-d0;}
end_define

begin_comment
comment|/*  *  * Some numerical conventions:  *  *	Arrays have white's value in [0], red in [1].  *	Numeric values which are one color or the other use  *	-1 for white, 1 for red.  *	Hence, white will be negative values, red positive one.  *	This makes a lot of sense since white is going in decending  *	order around the board, and red is ascending.  *  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|EXEC
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* object for main program */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|TEACH
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* object for tutorial program */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color of player: 					-1 = white 					 1 = red 					 0 = both 					 2 = not yet init'ed */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|args
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* args passed to teachgammon and back */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|acnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of args */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag to ask for rules or instructions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for automatic board printing */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* case conversion flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for cleaning screen */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* backgammon flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'roll again' flag for recovered game */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* recovered game flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cursor addressing flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rfl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* saved value of rflag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special flag for inputting rolls */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|board
index|[
literal|26
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* board:  negative values are white, 				   positive are red */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dice
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of dice */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mvlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'move limit':  max. number of moves */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mvl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* working copy of mvlim */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|p
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* starting position of moves */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|g
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ending position of moves (goals) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|h
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for each move if a man was hit */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cturn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whose turn it currently is: 					-1 = white 					 1 = red 					 0 = just quitted 					-2 = white just lost 					 2 = red just lost */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|d0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag if dice have been reversed from 				   original position */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|table
index|[
literal|6
index|]
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* odds table for possible rolls */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* red's score */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|wscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* white's score */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gvalue
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of game (64 max.) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dlast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* who doubled last (0 = neither) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* position of bar for current player */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|home
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* position of home for current player */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|off
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of men off board */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|offptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to off for current player */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|offopp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to off for opponent */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of men in inner table */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|inptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to in for current player */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|inopp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to in for opponent */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ncin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of characters in cin */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|cin
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input line of current move 				   (used for reconstructing input after 				   a backspace) */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|color
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* colors as strings */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|colorptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color of current player */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|Colorptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color of current player, capitalized */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|colen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of color of current player */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sgttyb
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty information buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|old
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original tty status */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|noech
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original tty status without echo */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* raw tty status, no echo */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|curr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* row position of cursor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|curc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* column position of cursor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|begscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'beginning' of screen 				   (not including board) */
end_comment

begin_function_decl
name|void
name|getout
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* function to exit backgammon cleanly */
end_comment

end_unit

