begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2000  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information about less, or for information on how to   * contact the author, see the README file.  */
end_comment

begin_comment
comment|/*  * Definitions of keys on the PC.  * Special (non-ASCII) keys on the PC send a two-byte sequence,  * where the first byte is 0 and the second is as defined below.  */
end_comment

begin_define
define|#
directive|define
name|PCK_SHIFT_TAB
value|'\017'
end_define

begin_define
define|#
directive|define
name|PCK_ALT_E
value|'\022'
end_define

begin_define
define|#
directive|define
name|PCK_CAPS_LOCK
value|'\072'
end_define

begin_define
define|#
directive|define
name|PCK_F1
value|'\073'
end_define

begin_define
define|#
directive|define
name|PCK_NUM_LOCK
value|'\105'
end_define

begin_define
define|#
directive|define
name|PCK_HOME
value|'\107'
end_define

begin_define
define|#
directive|define
name|PCK_UP
value|'\110'
end_define

begin_define
define|#
directive|define
name|PCK_PAGEUP
value|'\111'
end_define

begin_define
define|#
directive|define
name|PCK_LEFT
value|'\113'
end_define

begin_define
define|#
directive|define
name|PCK_RIGHT
value|'\115'
end_define

begin_define
define|#
directive|define
name|PCK_END
value|'\117'
end_define

begin_define
define|#
directive|define
name|PCK_DOWN
value|'\120'
end_define

begin_define
define|#
directive|define
name|PCK_PAGEDOWN
value|'\121'
end_define

begin_define
define|#
directive|define
name|PCK_INSERT
value|'\122'
end_define

begin_define
define|#
directive|define
name|PCK_DELETE
value|'\123'
end_define

begin_define
define|#
directive|define
name|PCK_CTL_LEFT
value|'\163'
end_define

begin_define
define|#
directive|define
name|PCK_CTL_RIGHT
value|'\164'
end_define

begin_define
define|#
directive|define
name|PCK_CTL_DELETE
value|'\223'
end_define

end_unit

