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
unit|static char sccsid[] = "@(#)init.c	8.1 (Berkeley) 5/31/93";
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
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_comment
comment|/*  * variable initialization.  */
end_comment

begin_comment
comment|/* name of executable object programs */
end_comment

begin_decl_stmt
specifier|const
name|char
name|EXEC
index|[]
init|=
literal|"/usr/games/backgammon"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
name|TEACH
index|[]
init|=
literal|"/usr/games/teachgammon"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pnum
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color of player: 					-1 = white 					 1 = red 					 0 = both 					 2 = not yet init'ed */
end_comment

begin_decl_stmt
name|int
name|acnt
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of args */
end_comment

begin_decl_stmt
name|int
name|aflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag to ask for rules or instructions */
end_comment

begin_decl_stmt
name|int
name|bflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for automatic board printing */
end_comment

begin_decl_stmt
name|int
name|cflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* case conversion flag */
end_comment

begin_decl_stmt
name|int
name|hflag
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for cleaning screen */
end_comment

begin_decl_stmt
name|int
name|mflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* backgammon flag */
end_comment

begin_decl_stmt
name|int
name|raflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 'roll again' flag for recovered game */
end_comment

begin_decl_stmt
name|int
name|rflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* recovered game flag */
end_comment

begin_decl_stmt
name|int
name|tflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cursor addressing flag */
end_comment

begin_decl_stmt
name|int
name|iroll
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special flag for inputting rolls */
end_comment

begin_decl_stmt
name|int
name|rfl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|color
index|[]
init|=
block|{
literal|"White"
block|,
literal|"Red"
block|,
literal|"white"
block|,
literal|"red"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|Colorptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|colorptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|inopp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|inptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|offopp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|offptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|args
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|begscr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|board
index|[
literal|26
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cin
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|colen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cturn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|d0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dice
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dlast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gvalue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|h
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|home
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|in
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mvl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mvlim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|off
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|p
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rscore
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|wscore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|termios
name|tty
decl_stmt|,
name|old
decl_stmt|,
name|noech
decl_stmt|,
name|raw
decl_stmt|;
end_decl_stmt

end_unit

