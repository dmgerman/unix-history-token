begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sccsid = "@(#)player.h	1.2 %G%";  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|"externs.h"
end_include

begin_comment
comment|/* sizes and coordinates for the screen */
end_comment

begin_define
define|#
directive|define
name|LINE_T
value|0
end_define

begin_define
define|#
directive|define
name|LINE_L
value|0
end_define

begin_define
define|#
directive|define
name|LINE_X
value|COLS
end_define

begin_define
define|#
directive|define
name|LINE_Y
value|1
end_define

begin_define
define|#
directive|define
name|LINE_B
value|(LINE_T+LINE_Y-1)
end_define

begin_define
define|#
directive|define
name|LINE_R
value|(LINE_L+LINE_X-1)
end_define

begin_define
define|#
directive|define
name|BOX_T
value|1
end_define

begin_define
define|#
directive|define
name|BOX_L
value|0
end_define

begin_define
define|#
directive|define
name|BOX_X
value|65
end_define

begin_define
define|#
directive|define
name|BOX_Y
value|16
end_define

begin_define
define|#
directive|define
name|BOX_B
value|(BOX_T+BOX_Y-1)
end_define

begin_define
define|#
directive|define
name|BOX_R
value|(BOX_L+BOX_X-1)
end_define

begin_define
define|#
directive|define
name|TURN_T
value|BOX_B
end_define

begin_define
define|#
directive|define
name|TURN_X
value|7
end_define

begin_define
define|#
directive|define
name|TURN_L
value|((BOX_L+BOX_R-TURN_X)/2)
end_define

begin_define
define|#
directive|define
name|TURN_Y
value|1
end_define

begin_define
define|#
directive|define
name|TURN_B
value|(TURN_T+TURN_Y+1)
end_define

begin_define
define|#
directive|define
name|TURN_R
value|(TURN_L+TURN_X+1)
end_define

begin_define
define|#
directive|define
name|STAT_T
value|0
end_define

begin_define
define|#
directive|define
name|STAT_L
value|(BOX_R+2)
end_define

begin_define
define|#
directive|define
name|STAT_B
value|BOX_B
end_define

begin_define
define|#
directive|define
name|STAT_R
value|(COLS-1)
end_define

begin_define
define|#
directive|define
name|STAT_X
value|(STAT_R-STAT_L+1)
end_define

begin_define
define|#
directive|define
name|STAT_Y
value|(STAT_B-STAT_T+1)
end_define

begin_define
define|#
directive|define
name|STAT_1
value|0
end_define

begin_define
define|#
directive|define
name|STAT_2
value|(STAT_1+4)
end_define

begin_define
define|#
directive|define
name|STAT_3
value|(STAT_2+7)
end_define

begin_define
define|#
directive|define
name|SCROLL_T
value|(BOX_B+1)
end_define

begin_define
define|#
directive|define
name|SCROLL_L
value|0
end_define

begin_define
define|#
directive|define
name|SCROLL_B
value|(LINES-1)
end_define

begin_define
define|#
directive|define
name|SCROLL_R
value|(COLS-1)
end_define

begin_define
define|#
directive|define
name|SCROLL_X
value|COLS
end_define

begin_define
define|#
directive|define
name|SCROLL_Y
value|(LINES-SCROLL_T)
end_define

begin_define
define|#
directive|define
name|VIEW_T
value|(BOX_T+1)
end_define

begin_define
define|#
directive|define
name|VIEW_L
value|(BOX_L+1)
end_define

begin_define
define|#
directive|define
name|VIEW_X
value|(BOX_X-5)
end_define

begin_define
define|#
directive|define
name|VIEW_Y
value|(BOX_Y-2)
end_define

begin_define
define|#
directive|define
name|VIEW_B
value|(VIEW_T+VIEW_Y-1)
end_define

begin_define
define|#
directive|define
name|VIEW_R
value|(VIEW_L+VIEW_X-1)
end_define

begin_define
define|#
directive|define
name|SLOT_T
value|VIEW_T
end_define

begin_define
define|#
directive|define
name|SLOT_L
value|(VIEW_R+1)
end_define

begin_define
define|#
directive|define
name|SLOT_X
value|3
end_define

begin_define
define|#
directive|define
name|SLOT_Y
value|VIEW_Y
end_define

begin_define
define|#
directive|define
name|SLOT_B
value|VIEW_B
end_define

begin_define
define|#
directive|define
name|SLOT_R
value|(SLOT_L+SLOT_X-1)
end_define

begin_decl_stmt
name|WINDOW
modifier|*
name|view_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|slot_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|scroll_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|stat_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|turn_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|done_curses
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|loaded
decl_stmt|,
name|fired
decl_stmt|,
name|changed
decl_stmt|,
name|repaired
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|dont_adjust
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|viewrow
decl_stmt|,
name|viewcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|movebuf
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|version
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|player
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ship
modifier|*
name|ms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memorial structure,&cc->ship[player] */
end_comment

begin_decl_stmt
name|struct
name|File
modifier|*
name|mf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ms->file */
end_comment

begin_decl_stmt
name|struct
name|shipspecs
modifier|*
name|mc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ms->specs */
end_comment

begin_comment
comment|/* condition codes for leave() */
end_comment

begin_define
define|#
directive|define
name|LEAVE_QUIT
value|0
end_define

begin_define
define|#
directive|define
name|LEAVE_CAPTURED
value|1
end_define

begin_define
define|#
directive|define
name|LEAVE_HURRICAN
value|2
end_define

begin_define
define|#
directive|define
name|LEAVE_DRIVER
value|3
end_define

end_unit

