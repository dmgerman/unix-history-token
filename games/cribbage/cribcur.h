begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cribcur.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_define
define|#
directive|define
name|PLAY_Y
value|15
end_define

begin_comment
comment|/* size of player's hand window */
end_comment

begin_define
define|#
directive|define
name|PLAY_X
value|12
end_define

begin_define
define|#
directive|define
name|TABLE_Y
value|21
end_define

begin_comment
comment|/* size of table window */
end_comment

begin_define
define|#
directive|define
name|TABLE_X
value|14
end_define

begin_define
define|#
directive|define
name|COMP_Y
value|15
end_define

begin_comment
comment|/* size of computer's hand window */
end_comment

begin_define
define|#
directive|define
name|COMP_X
value|12
end_define

begin_define
define|#
directive|define
name|Y_SCORE_SZ
value|9
end_define

begin_comment
comment|/* Y size of score board */
end_comment

begin_define
define|#
directive|define
name|X_SCORE_SZ
value|41
end_define

begin_comment
comment|/* X size of score board */
end_comment

begin_define
define|#
directive|define
name|SCORE_Y
value|0
end_define

begin_comment
comment|/* starting position of scoring board */
end_comment

begin_define
define|#
directive|define
name|SCORE_X
value|(PLAY_X + TABLE_X + COMP_X)
end_define

begin_define
define|#
directive|define
name|CRIB_Y
value|17
end_define

begin_comment
comment|/* position of crib (cut card) */
end_comment

begin_define
define|#
directive|define
name|CRIB_X
value|(PLAY_X + TABLE_X)
end_define

begin_define
define|#
directive|define
name|MSG_Y
value|(LINES - (Y_SCORE_SZ + 1))
end_define

begin_define
define|#
directive|define
name|MSG_X
value|(COLS - SCORE_X - 1)
end_define

begin_define
define|#
directive|define
name|Y_MSG_START
value|(Y_SCORE_SZ + 1)
end_define

begin_define
define|#
directive|define
name|PEG
value|'*'
end_define

begin_comment
comment|/* what a peg looks like on the board */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|Compwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* computer's hand window */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|Msgwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* message window */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|Playwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* player's hand window */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|Tablewin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table window */
end_comment

end_unit

