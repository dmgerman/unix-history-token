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
unit|static char sccsid[] = "@(#)ttext1.c	8.1 (Berkeley) 5/31/93";
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
name|opts
init|=
literal|" QIMRHEDSPT"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|prompt
init|=
literal|"-->"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|list
index|[]
init|=
block|{
literal|"\n\n\tI\tIntroduction to Backgammon"
block|,
literal|"\tM\tMoves and Points"
block|,
literal|"\tR\tRemoving Men from the Board"
block|,
literal|"\tH\tHitting Blots"
block|,
literal|"\tE\tEnding the Game and Scoring"
block|,
literal|"\tD\tDoubling"
block|,
literal|"\tS\tStrategy"
block|,
literal|"\tP\tThe Program and How to Use It"
block|,
literal|"\nalso, you can type:"
block|,
literal|"\t?\tto get this list"
block|,
literal|"\tQ\tto go start playing"
block|,
literal|"\tT\tto go straight to the tutorial"
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
name|hello
index|[]
init|=
block|{
literal|"\n\032   These rules consist of text describing how to play Backgammon"
block|,
literal|"followed by a tutorial session where you play a practice game"
block|,
literal|"against the computer.  When using this program, think carefuly"
block|,
literal|"before typing, since it reacts as soon as you type something.  In"
block|,
literal|"addition, the program presents text output, such as these rules,"
block|,
literal|"in small blocks that will not roll off the top of the screen."
block|,
literal|"Frequently, you will see the characters '-->' indicating that the"
block|,
literal|"program is waiting for you to finish reading, and will continue"
block|,
literal|"printing when you type a space or newline.  Also, the rules are"
block|,
literal|"divided into sections, and although you should read them in or-"
block|,
literal|"der, you can go directly to any of them by typing one of the fol-"
block|,
literal|"lowing letters:"
block|,
literal|"(Remember to hit a space or a newline to continue.)"
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
name|intro1
index|[]
init|=
block|{
literal|"\nIntroduction:"
block|,
literal|"\n   Backgammon is a game involving the skill of two players and"
block|,
literal|"the luck of two dice.  There are two players, red and white, and"
block|,
literal|"each player gets fifteen men.  The object of the game is to re-"
block|,
literal|"move all your men from the board before the opponent does.  The"
block|,
literal|"board consists of twenty-four positions, a 'bar' and a 'home' for"
block|,
literal|"each player.  It looks like this:"
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
name|intro2
index|[]
init|=
block|{
literal|""
block|,
literal|"\n   Although not indicated on the board, the players' homes are"
block|,
literal|"located just to the right of the board.  A player's men are placed"
block|,
literal|"there when they are removed from the board.  The board you just"
block|,
literal|"saw was in it's initial position.  All games start with the board"
block|,
literal|"looking like this.  Notice that red's pieces are represented by the"
block|,
literal|"letter 'r' and white's pieces are represented by the letter 'w'."
block|,
literal|"Also, a position may have zero or more pieces on it, e.g.  posi-"
block|,
literal|"tion 12 has five red pieces on it, while position 11 does not"
block|,
literal|"have any pieces of either color."
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
name|moves
index|[]
init|=
block|{
literal|"\nMoves and Points:"
block|,
literal|"\n   Moves are made along the positions on the board according to"
block|,
literal|"their numbers.  Red moves in the positive direction (clockwise"
block|,
literal|"from 1 to 24), and white moves in the negative direction (coun-"
block|,
literal|"terclockwise from 24 to 1)."
block|,
literal|"\n   A turn consists of rolling the dice, and moving the number of"
block|,
literal|"positions indicated on each die.  The two numbers can be used to"
block|,
literal|"move one man the sum of the two rolls, or two men the number on"
block|,
literal|"each individual die.  For example, if red rolled 6 3 at the start"
block|,
literal|"of the game, he might move a man from 1 to 7 to 10, using both"
block|,
literal|"dice for one man, or he might move two men from position 12, one"
block|,
literal|"to 15 and one to 18.  (Red did not have to choose two men start-"
block|,
literal|"ing from the same position.)  In addition, doubles are treated"
block|,
literal|"specially in backgammon.  When a player rolls doubles, he gets to"
block|,
literal|"move as if he had four dice instead of two.  For instance, if you"
block|,
literal|"rolled double 2's, you could move one man eight positions, four"
block|,
literal|"men two positions each, or any permutation in between."
block|,
literal|""
block|,
literal|"\n   However, there are certain limitations, called 'points.'  A"
block|,
literal|"player has a point when he has two or more men on the same posi-"
block|,
literal|"tion.  This gives him custody of that position, and his opponent"
block|,
literal|"cannot place his men there, even if passing through on the way to"
block|,
literal|"another position.  When a player has six points in a row, it is"
block|,
literal|"called a 'wall,' since any of his opponent's men behind the wall"
block|,
literal|"cannot pass it and are trapped, at least for the moment.  Notice"
block|,
literal|"that this could mean that a player could not use part or all of"
block|,
literal|"his roll.  However, he must use as much of his roll as possible."
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
name|remove
index|[]
init|=
block|{
literal|"\nRemoving Men from the Board:"
block|,
literal|"\n   The most important part of the game is removing men, since"
block|,
literal|"that is how you win the game.  Once a man is removed, he stays"
block|,
literal|"off the board for the duration of the game.  However, a player"
block|,
literal|"cannot remove men until all his men are on his 'inner table,' or"
block|,
literal|"the last six positions of the board (19-24 for red, 6-1 for"
block|,
literal|"white)."
block|,
literal|"\n   To get off the board, a player must roll the exact number to"
block|,
literal|"get his man one position past the last position on the board, or"
block|,
literal|"his 'home.'  Hence, if red wanted to remove a man from position"
block|,
literal|"23, he would have to roll a 2, anything else would be used for"
block|,
literal|"another man, or for another purpose.  However, there is one ex-"
block|,
literal|"ception.  If the player rolling has no men far enough to move the"
block|,
literal|"roll made, he may move his farthest man off the board.  For exam-"
block|,
literal|"ple, if red's farthest man back was on position 21, he could re-"
block|,
literal|"move men from that position if he rolled a 5 or a 6, as well as a"
block|,
literal|"4.  Since he does not have men on 20 (where he could use a 5) or"
block|,
literal|"on 19 (where he could use a 6), he can use these rolls for posi-"
block|,
literal|"tion 21.  A player never has to remove men, but he must make as"
block|,
literal|"many moves as possible."
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
name|hits
index|[]
init|=
block|{
literal|"\nHitting Blots:"
block|,
literal|"\n   Although two men on a position form an impenetrable point, a"
block|,
literal|"lone man is not so secure.  Such a man is called a 'blot' and has"
block|,
literal|"the potential of getting hit by an opposing man.  When a player's"
block|,
literal|"blot is hit, he is placed on the bar, and the first thing that"
block|,
literal|"player must do is move the man off the bar.  Such moves are"
block|,
literal|"counted as if the bar is one position behind the first position"
block|,
literal|"on the board.  Thus if red has a man on the bar and rolls 2 3, he"
block|,
literal|"must move the man on the bar to position 2 or 3 before moving any"
block|,
literal|"other man.  If white had points on positions 2 and 3, then red"
block|,
literal|"would forfeit his turn.  Being on the bar is a very bad position,"
block|,
literal|"for often a player can lose many turns trying to move off the"
block|,
literal|"bar, as well as being set back the full distance of the board."
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
name|endgame
index|[]
init|=
block|{
literal|"\nEnding the Game and Scoring:"
block|,
literal|"\n   Winning a game usually wins one point, the normal value of a"
block|,
literal|"game.  However, if the losing player has not removed any men yet,"
block|,
literal|"then the winning player wins double the game value, called a"
block|,
literal|"'gammon.'  If the losing player has a player on the bar or on the"
block|,
literal|"winner's inner table, then the winner gets triple the game value,"
block|,
literal|"which is called a 'backgammon.'  (So that's where the name comes"
block|,
literal|"from!)"
block|,
literal|""
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

