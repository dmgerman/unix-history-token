begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)init.c	5.4 (Berkeley) 6/1/90"
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
file|<sgtty.h>
end_include

begin_comment
comment|/*  * variable initialization.  */
end_comment

begin_comment
comment|/* name of executable object programs */
end_comment

begin_decl_stmt
name|char
name|EXEC
index|[]
init|=
literal|"/usr/games/backgammon"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of args */
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
name|char
modifier|*
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

end_unit

