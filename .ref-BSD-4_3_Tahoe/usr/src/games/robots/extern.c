begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)extern.c	5.3 (Berkeley) 6/18/88"
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
file|"robots.h"
end_include

begin_decl_stmt
name|bool
name|Dead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Player is now dead */
end_comment

begin_decl_stmt
name|bool
name|Full_clear
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lots of junk for init_field to clear */
end_comment

begin_decl_stmt
name|bool
name|Jump
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Jump while running, counting, or waiting */
end_comment

begin_decl_stmt
name|bool
name|Newscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* There was a new score added */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FANCY
end_ifdef

begin_decl_stmt
name|bool
name|Pattern_roll
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Auto play for YHBJNLUK pattern */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|bool
name|Real_time
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Play in real time? */
end_comment

begin_decl_stmt
name|bool
name|Running
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Currently in the middle of a run */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FANCY
end_ifdef

begin_decl_stmt
name|bool
name|Stand_still
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Auto play for standing still pattern */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|bool
name|Teleport
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Teleport automatically when player must */
end_comment

begin_decl_stmt
name|bool
name|Waiting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Player is waiting for end */
end_comment

begin_decl_stmt
name|bool
name|Was_bonus
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Was a bonus last level */
end_comment

begin_decl_stmt
name|char
name|Cnt_move
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command which has preceded the count */
end_comment

begin_decl_stmt
name|char
name|Field
index|[
name|Y_FIELDSIZE
index|]
index|[
name|X_FIELDSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the playing field itslef */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Next_move
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Next move to be used in the pattern */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Move_list
init|=
literal|"YHBJNLUK"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of moves in the pattern */
end_comment

begin_decl_stmt
name|char
name|Run_ch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character for the direction we are running */
end_comment

begin_decl_stmt
name|int
name|Count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command count */
end_comment

begin_decl_stmt
name|int
name|Level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current level */
end_comment

begin_decl_stmt
name|int
name|Num_robots
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of robots left */
end_comment

begin_decl_stmt
name|int
name|Num_scores
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of scores posted */
end_comment

begin_decl_stmt
name|int
name|Score
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current score */
end_comment

begin_decl_stmt
name|int
name|Start_level
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Level on which to start */
end_comment

begin_decl_stmt
name|int
name|Wait_bonus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bonus for waiting */
end_comment

begin_decl_stmt
name|COORD
name|Max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max area robots take up */
end_comment

begin_decl_stmt
name|COORD
name|Min
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Min area robots take up */
end_comment

begin_decl_stmt
name|COORD
name|My_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Player's current position */
end_comment

begin_decl_stmt
name|COORD
name|Robots
index|[
name|MAXROBOTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Robots' current positions */
end_comment

begin_decl_stmt
name|jmp_buf
name|End_move
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Jump to on Real_time */
end_comment

end_unit

