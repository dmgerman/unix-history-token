begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)cribcur.h	5.3 (Berkeley) 6/18/88  */
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

