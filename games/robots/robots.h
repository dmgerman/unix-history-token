begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)robots.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/*  * miscellaneous constants  */
end_comment

begin_define
define|#
directive|define
name|Y_FIELDSIZE
value|23
end_define

begin_define
define|#
directive|define
name|X_FIELDSIZE
value|60
end_define

begin_define
define|#
directive|define
name|Y_SIZE
value|24
end_define

begin_define
define|#
directive|define
name|X_SIZE
value|80
end_define

begin_define
define|#
directive|define
name|MAXLEVELS
value|4
end_define

begin_define
define|#
directive|define
name|MAXROBOTS
value|(MAXLEVELS * 10)
end_define

begin_define
define|#
directive|define
name|ROB_SCORE
value|10
end_define

begin_define
define|#
directive|define
name|S_BONUS
value|(60 * ROB_SCORE)
end_define

begin_define
define|#
directive|define
name|Y_SCORE
value|21
end_define

begin_define
define|#
directive|define
name|X_SCORE
value|(X_FIELDSIZE + 9)
end_define

begin_define
define|#
directive|define
name|Y_PROMPT
value|(Y_FIELDSIZE - 1)
end_define

begin_define
define|#
directive|define
name|X_PROMPT
value|(X_FIELDSIZE + 2)
end_define

begin_define
define|#
directive|define
name|MAXSCORES
value|(Y_SIZE - 2)
end_define

begin_define
define|#
directive|define
name|MAXNAME
value|16
end_define

begin_define
define|#
directive|define
name|MS_NAME
value|"Ten"
end_define

begin_comment
comment|/*  * characters on screen  */
end_comment

begin_define
define|#
directive|define
name|ROBOT
value|'+'
end_define

begin_define
define|#
directive|define
name|HEAP
value|'*'
end_define

begin_define
define|#
directive|define
name|PLAYER
value|'@'
end_define

begin_comment
comment|/*  * type definitions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
block|}
name|COORD
typedef|;
end_typedef

begin_comment
comment|/*  * global variables  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Dead
decl_stmt|,
name|Full_clear
decl_stmt|,
name|Jump
decl_stmt|,
name|Newscore
decl_stmt|,
name|Real_time
decl_stmt|,
name|Running
decl_stmt|,
name|Teleport
decl_stmt|,
name|Waiting
decl_stmt|,
name|Was_bonus
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FANCY
end_ifdef

begin_decl_stmt
specifier|extern
name|bool
name|Pattern_roll
decl_stmt|,
name|Stand_still
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|Cnt_move
decl_stmt|,
name|Field
index|[
name|Y_FIELDSIZE
index|]
index|[
name|X_FIELDSIZE
index|]
decl_stmt|,
modifier|*
name|Next_move
decl_stmt|,
modifier|*
name|Move_list
decl_stmt|,
name|Run_ch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Count
decl_stmt|,
name|Level
decl_stmt|,
name|Num_robots
decl_stmt|,
name|Num_scores
decl_stmt|,
name|Score
decl_stmt|,
name|Start_level
decl_stmt|,
name|Wait_bonus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|COORD
name|Max
decl_stmt|,
name|Min
decl_stmt|,
name|My_pos
decl_stmt|,
name|Robots
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|End_move
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * functions types  */
end_comment

begin_function_decl
name|int
name|cmp_sc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|move_robots
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|COORD
modifier|*
name|rnd_pos
parameter_list|()
function_decl|;
end_function_decl

end_unit

