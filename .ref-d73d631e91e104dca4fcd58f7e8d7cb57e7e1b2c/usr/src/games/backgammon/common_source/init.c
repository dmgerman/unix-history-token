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
literal|"@(#)init.c	5.4 (Berkeley) %G%"
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

