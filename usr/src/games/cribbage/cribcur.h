begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
value|0
end_define

begin_define
define|#
directive|define
name|SCORE_SZ
value|41
end_define

begin_comment
comment|/* X size of score board */
end_comment

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
value|(PLAY_X + TABLE_X + SCORE_SZ)
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

end_unit

