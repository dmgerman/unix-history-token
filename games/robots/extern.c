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
unit|static char sccsid[] = "@(#)extern.c	8.1 (Berkeley) 5/31/93";
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

