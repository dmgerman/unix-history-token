begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2000  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information about less, or for information on how to   * contact the author, see the README file.  */
end_comment

begin_define
define|#
directive|define
name|MAX_USERCMD
value|500
end_define

begin_define
define|#
directive|define
name|MAX_CMDLEN
value|16
end_define

begin_define
define|#
directive|define
name|A_B_LINE
value|2
end_define

begin_define
define|#
directive|define
name|A_B_SCREEN
value|3
end_define

begin_define
define|#
directive|define
name|A_B_SCROLL
value|4
end_define

begin_define
define|#
directive|define
name|A_B_SEARCH
value|5
end_define

begin_define
define|#
directive|define
name|A_DIGIT
value|6
end_define

begin_define
define|#
directive|define
name|A_DISP_OPTION
value|7
end_define

begin_define
define|#
directive|define
name|A_DEBUG
value|8
end_define

begin_define
define|#
directive|define
name|A_EXAMINE
value|9
end_define

begin_define
define|#
directive|define
name|A_FIRSTCMD
value|10
end_define

begin_define
define|#
directive|define
name|A_FREPAINT
value|11
end_define

begin_define
define|#
directive|define
name|A_F_LINE
value|12
end_define

begin_define
define|#
directive|define
name|A_F_SCREEN
value|13
end_define

begin_define
define|#
directive|define
name|A_F_SCROLL
value|14
end_define

begin_define
define|#
directive|define
name|A_F_SEARCH
value|15
end_define

begin_define
define|#
directive|define
name|A_GOEND
value|16
end_define

begin_define
define|#
directive|define
name|A_GOLINE
value|17
end_define

begin_define
define|#
directive|define
name|A_GOMARK
value|18
end_define

begin_define
define|#
directive|define
name|A_HELP
value|19
end_define

begin_define
define|#
directive|define
name|A_NEXT_FILE
value|20
end_define

begin_define
define|#
directive|define
name|A_PERCENT
value|21
end_define

begin_define
define|#
directive|define
name|A_PREFIX
value|22
end_define

begin_define
define|#
directive|define
name|A_PREV_FILE
value|23
end_define

begin_define
define|#
directive|define
name|A_QUIT
value|24
end_define

begin_define
define|#
directive|define
name|A_REPAINT
value|25
end_define

begin_define
define|#
directive|define
name|A_SETMARK
value|26
end_define

begin_define
define|#
directive|define
name|A_SHELL
value|27
end_define

begin_define
define|#
directive|define
name|A_STAT
value|28
end_define

begin_define
define|#
directive|define
name|A_FF_LINE
value|29
end_define

begin_define
define|#
directive|define
name|A_BF_LINE
value|30
end_define

begin_define
define|#
directive|define
name|A_VERSION
value|31
end_define

begin_define
define|#
directive|define
name|A_VISUAL
value|32
end_define

begin_define
define|#
directive|define
name|A_F_WINDOW
value|33
end_define

begin_define
define|#
directive|define
name|A_B_WINDOW
value|34
end_define

begin_define
define|#
directive|define
name|A_F_BRACKET
value|35
end_define

begin_define
define|#
directive|define
name|A_B_BRACKET
value|36
end_define

begin_define
define|#
directive|define
name|A_PIPE
value|37
end_define

begin_define
define|#
directive|define
name|A_INDEX_FILE
value|38
end_define

begin_define
define|#
directive|define
name|A_UNDO_SEARCH
value|39
end_define

begin_define
define|#
directive|define
name|A_FF_SCREEN
value|40
end_define

begin_define
define|#
directive|define
name|A_LSHIFT
value|41
end_define

begin_define
define|#
directive|define
name|A_RSHIFT
value|42
end_define

begin_define
define|#
directive|define
name|A_AGAIN_SEARCH
value|43
end_define

begin_define
define|#
directive|define
name|A_T_AGAIN_SEARCH
value|44
end_define

begin_define
define|#
directive|define
name|A_REVERSE_SEARCH
value|45
end_define

begin_define
define|#
directive|define
name|A_T_REVERSE_SEARCH
value|46
end_define

begin_define
define|#
directive|define
name|A_OPT_TOGGLE
value|47
end_define

begin_define
define|#
directive|define
name|A_OPT_SET
value|48
end_define

begin_define
define|#
directive|define
name|A_OPT_UNSET
value|49
end_define

begin_define
define|#
directive|define
name|A_F_FOREVER
value|50
end_define

begin_define
define|#
directive|define
name|A_GOPOS
value|51
end_define

begin_define
define|#
directive|define
name|A_REMOVE_FILE
value|52
end_define

begin_define
define|#
directive|define
name|A_INVALID
value|100
end_define

begin_define
define|#
directive|define
name|A_NOACTION
value|101
end_define

begin_define
define|#
directive|define
name|A_UINVALID
value|102
end_define

begin_define
define|#
directive|define
name|A_END_LIST
value|103
end_define

begin_define
define|#
directive|define
name|A_SPECIAL_KEY
value|104
end_define

begin_define
define|#
directive|define
name|A_SKIP
value|127
end_define

begin_define
define|#
directive|define
name|A_EXTRA
value|0200
end_define

begin_comment
comment|/* Line editting characters */
end_comment

begin_define
define|#
directive|define
name|EC_BACKSPACE
value|1
end_define

begin_define
define|#
directive|define
name|EC_LINEKILL
value|2
end_define

begin_define
define|#
directive|define
name|EC_RIGHT
value|3
end_define

begin_define
define|#
directive|define
name|EC_LEFT
value|4
end_define

begin_define
define|#
directive|define
name|EC_W_LEFT
value|5
end_define

begin_define
define|#
directive|define
name|EC_W_RIGHT
value|6
end_define

begin_define
define|#
directive|define
name|EC_INSERT
value|7
end_define

begin_define
define|#
directive|define
name|EC_DELETE
value|8
end_define

begin_define
define|#
directive|define
name|EC_HOME
value|9
end_define

begin_define
define|#
directive|define
name|EC_END
value|10
end_define

begin_define
define|#
directive|define
name|EC_W_BACKSPACE
value|11
end_define

begin_define
define|#
directive|define
name|EC_W_DELETE
value|12
end_define

begin_define
define|#
directive|define
name|EC_UP
value|13
end_define

begin_define
define|#
directive|define
name|EC_DOWN
value|14
end_define

begin_define
define|#
directive|define
name|EC_EXPAND
value|15
end_define

begin_define
define|#
directive|define
name|EC_F_COMPLETE
value|17
end_define

begin_define
define|#
directive|define
name|EC_B_COMPLETE
value|18
end_define

begin_define
define|#
directive|define
name|EC_LITERAL
value|19
end_define

begin_define
define|#
directive|define
name|EC_NOACTION
value|101
end_define

begin_define
define|#
directive|define
name|EC_UINVALID
value|102
end_define

begin_comment
comment|/* Flags for editchar() */
end_comment

begin_define
define|#
directive|define
name|EC_PEEK
value|01
end_define

begin_define
define|#
directive|define
name|EC_NOHISTORY
value|02
end_define

begin_define
define|#
directive|define
name|EC_NOCOMPLETE
value|04
end_define

begin_comment
comment|/* Environment variable stuff */
end_comment

begin_define
define|#
directive|define
name|EV_OK
value|01
end_define

begin_comment
comment|/* Special keys (keys which output different strings on different terminals) */
end_comment

begin_define
define|#
directive|define
name|SK_SPECIAL_KEY
value|CONTROL('K')
end_define

begin_define
define|#
directive|define
name|SK_RIGHT_ARROW
value|1
end_define

begin_define
define|#
directive|define
name|SK_LEFT_ARROW
value|2
end_define

begin_define
define|#
directive|define
name|SK_UP_ARROW
value|3
end_define

begin_define
define|#
directive|define
name|SK_DOWN_ARROW
value|4
end_define

begin_define
define|#
directive|define
name|SK_PAGE_UP
value|5
end_define

begin_define
define|#
directive|define
name|SK_PAGE_DOWN
value|6
end_define

begin_define
define|#
directive|define
name|SK_HOME
value|7
end_define

begin_define
define|#
directive|define
name|SK_END
value|8
end_define

begin_define
define|#
directive|define
name|SK_DELETE
value|9
end_define

begin_define
define|#
directive|define
name|SK_INSERT
value|10
end_define

begin_define
define|#
directive|define
name|SK_CTL_LEFT_ARROW
value|11
end_define

begin_define
define|#
directive|define
name|SK_CTL_RIGHT_ARROW
value|12
end_define

begin_define
define|#
directive|define
name|SK_CTL_DELETE
value|13
end_define

begin_define
define|#
directive|define
name|SK_F1
value|14
end_define

begin_define
define|#
directive|define
name|SK_BACKTAB
value|15
end_define

begin_define
define|#
directive|define
name|SK_CTL_BACKSPACE
value|16
end_define

begin_define
define|#
directive|define
name|SK_CONTROL_K
value|40
end_define

end_unit

