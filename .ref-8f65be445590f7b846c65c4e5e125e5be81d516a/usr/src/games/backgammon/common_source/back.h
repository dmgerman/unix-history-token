begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)back.h	5.4 (Berkeley) %G%  */
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
name|char
name|EXEC
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* object for main program */
end_comment

begin_decl_stmt
name|char
name|TEACH
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* object for tutorial program */
end_comment

begin_decl_stmt
name|int
name|pnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color of player: 					-1 = white 					 1 = red 					 0 = both 					 2 = not yet init'ed */
end_comment

begin_decl_stmt
name|char
name|args
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* args passed to teachgammon and back */
end_comment

begin_decl_stmt
name|int
name|acnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of args */
end_comment

begin_decl_stmt
name|int
name|aflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag to ask for rules or instructions */
end_comment

begin_decl_stmt
name|int
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for automatic board printing */
end_comment

begin_decl_stmt
name|int
name|cflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* case conversion flag */
end_comment

begin_decl_stmt
name|int
name|hflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for cleaning screen */
end_comment

begin_decl_stmt
name|int
name|mflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* backgammon flag */
end_comment

begin_decl_stmt
name|int
name|raflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'roll again' flag for recovered game */
end_comment

begin_decl_stmt
name|int
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* recovered game flag */
end_comment

begin_decl_stmt
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cursor addressing flag */
end_comment

begin_decl_stmt
name|int
name|rfl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* saved value of rflag */
end_comment

begin_decl_stmt
name|int
name|iroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special flag for inputting rolls */
end_comment

begin_decl_stmt
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
name|int
name|mvlim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'move limit':  max. number of moves */
end_comment

begin_decl_stmt
name|int
name|mvl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* working copy of mvlim */
end_comment

begin_decl_stmt
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
name|int
name|cturn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whose turn it currently is: 					-1 = white 					 1 = red 					 0 = just quitted 					-2 = white just lost 					 2 = red just lost */
end_comment

begin_decl_stmt
name|int
name|d0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag if dice have been reversed from 				   original position */
end_comment

begin_decl_stmt
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
name|int
name|rscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* red's score */
end_comment

begin_decl_stmt
name|int
name|wscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* white's score */
end_comment

begin_decl_stmt
name|int
name|gvalue
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of game (64 max.) */
end_comment

begin_decl_stmt
name|int
name|dlast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* who doubled last (0 = neither) */
end_comment

begin_decl_stmt
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* position of bar for current player */
end_comment

begin_decl_stmt
name|int
name|home
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* position of home for current player */
end_comment

begin_decl_stmt
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
name|int
modifier|*
name|offptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to off for current player */
end_comment

begin_decl_stmt
name|int
modifier|*
name|offopp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to off for opponent */
end_comment

begin_decl_stmt
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
name|int
modifier|*
name|inptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to in for current player */
end_comment

begin_decl_stmt
name|int
modifier|*
name|inopp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to in for opponent */
end_comment

begin_decl_stmt
name|int
name|ncin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of characters in cin */
end_comment

begin_decl_stmt
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
name|char
modifier|*
name|color
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* colors as strings */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|colorptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color of current player */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|Colorptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color of current player, capitalized */
end_comment

begin_decl_stmt
name|int
name|colen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of color of current player */
end_comment

begin_decl_stmt
name|struct
name|sgttyb
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty information buffer */
end_comment

begin_decl_stmt
name|int
name|old
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original tty status */
end_comment

begin_decl_stmt
name|int
name|noech
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original tty status without echo */
end_comment

begin_decl_stmt
name|int
name|raw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* raw tty status, no echo */
end_comment

begin_decl_stmt
name|int
name|curr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* row position of cursor */
end_comment

begin_decl_stmt
name|int
name|curc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* column position of cursor */
end_comment

begin_decl_stmt
name|int
name|begscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'beginning' of screen 				   (not including board) */
end_comment

begin_function_decl
name|int
name|getout
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* function to exit backgammon cleanly */
end_comment

end_unit

