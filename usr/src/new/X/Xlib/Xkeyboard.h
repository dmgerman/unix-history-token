begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: Xkeyboard.h,v 10.4 86/02/01 15:41:50 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright 1985, Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/*  * This file is useful for dealing with key events independent of any  * ascii mapping.  */
end_comment

begin_define
define|#
directive|define
name|KC_F1
value|0126
end_define

begin_define
define|#
directive|define
name|KC_F2
value|0127
end_define

begin_define
define|#
directive|define
name|KC_F3
value|0130
end_define

begin_define
define|#
directive|define
name|KC_F4
value|0131
end_define

begin_define
define|#
directive|define
name|KC_F5
value|0132
end_define

begin_define
define|#
directive|define
name|KC_F6
value|0144
end_define

begin_define
define|#
directive|define
name|KC_F7
value|0145
end_define

begin_define
define|#
directive|define
name|KC_F8
value|0146
end_define

begin_define
define|#
directive|define
name|KC_F9
value|0147
end_define

begin_define
define|#
directive|define
name|KC_F10
value|0150
end_define

begin_define
define|#
directive|define
name|KC_F11
value|0161
end_define

begin_define
define|#
directive|define
name|KC_ESC
value|0161
end_define

begin_comment
comment|/* escape: same as F11 */
end_comment

begin_define
define|#
directive|define
name|KC_F12
value|0162
end_define

begin_define
define|#
directive|define
name|KC_BS
value|0162
end_define

begin_comment
comment|/* backspace: same as F12 */
end_comment

begin_define
define|#
directive|define
name|KC_F13
value|0163
end_define

begin_define
define|#
directive|define
name|KC_LF
value|0163
end_define

begin_comment
comment|/* line feed: same as F13 */
end_comment

begin_define
define|#
directive|define
name|KC_F14
value|0164
end_define

begin_define
define|#
directive|define
name|KC_F15
value|0174
end_define

begin_define
define|#
directive|define
name|KC_F16
value|0175
end_define

begin_define
define|#
directive|define
name|KC_F17
value|0200
end_define

begin_define
define|#
directive|define
name|KC_F18
value|0201
end_define

begin_define
define|#
directive|define
name|KC_F19
value|0202
end_define

begin_define
define|#
directive|define
name|KC_F20
value|0203
end_define

begin_define
define|#
directive|define
name|KC_E1
value|0212
end_define

begin_define
define|#
directive|define
name|KC_E2
value|0213
end_define

begin_define
define|#
directive|define
name|KC_E3
value|0214
end_define

begin_define
define|#
directive|define
name|KC_E4
value|0215
end_define

begin_define
define|#
directive|define
name|KC_E5
value|0216
end_define

begin_define
define|#
directive|define
name|KC_E6
value|0217
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_0
value|0222
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_PERIOD
value|0224
end_define

begin_define
define|#
directive|define
name|KC_ENTER
value|0225
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_1
value|0226
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_2
value|0227
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_3
value|0230
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_4
value|0231
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_5
value|0232
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_6
value|0233
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_COMMA
value|0234
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_7
value|0235
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_8
value|0236
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_9
value|0237
end_define

begin_define
define|#
directive|define
name|KC_KEYPAD_MINUS
value|0240
end_define

begin_define
define|#
directive|define
name|KC_PF1
value|0241
end_define

begin_define
define|#
directive|define
name|KC_PF2
value|0242
end_define

begin_define
define|#
directive|define
name|KC_PF3
value|0243
end_define

begin_define
define|#
directive|define
name|KC_PF4
value|0244
end_define

begin_define
define|#
directive|define
name|KC_SHIFT
value|0256
end_define

begin_define
define|#
directive|define
name|KC_CTRL
value|0257
end_define

begin_define
define|#
directive|define
name|KC_LOCK
value|0260
end_define

begin_define
define|#
directive|define
name|KC_SYMBOL
value|0261
end_define

begin_define
define|#
directive|define
name|KC_META
value|0261
end_define

begin_comment
comment|/* same as KC_SYMBOL */
end_comment

begin_define
define|#
directive|define
name|KC_CURSOR_LEFT
value|0247
end_define

begin_define
define|#
directive|define
name|KC_CURSOR_RIGHT
value|0250
end_define

begin_define
define|#
directive|define
name|KC_CURSOR_DOWN
value|0251
end_define

begin_define
define|#
directive|define
name|KC_CURSOR_UP
value|0252
end_define

begin_define
define|#
directive|define
name|IsShiftKey
parameter_list|(
name|code
parameter_list|)
define|\
value|(((unsigned)code)>=KC_SHIFT&& ((unsigned)code)<=KC_META)
end_define

begin_define
define|#
directive|define
name|IsCursorKey
parameter_list|(
name|code
parameter_list|)
define|\
value|(((unsigned)code)>=KC_CURSOR_LEFT&& ((unsigned)code)<=KC_CURSOR_UP)
end_define

begin_define
define|#
directive|define
name|IsKeypadKey
parameter_list|(
name|code
parameter_list|)
define|\
value|(((unsigned)code)>=KC_KEYPAD_0&& ((unsigned)code)<=KC_KEYPAD_MINUS)
end_define

begin_define
define|#
directive|define
name|IsFunctionKey
parameter_list|(
name|code
parameter_list|)
define|\
value|(((unsigned)code)>=KC_F1&& ((unsigned)code)<=KC_E6)
end_define

begin_define
define|#
directive|define
name|IsPFKey
parameter_list|(
name|code
parameter_list|)
define|\
value|(((unsigned)code)>=KC_PF1&& ((unsigned)code)<=KC_PF4)
end_define

begin_define
define|#
directive|define
name|IsTypewriterKey
parameter_list|(
name|code
parameter_list|)
define|\
value|(((unsigned)code)>=0274&& ((unsigned)code)<=0373)
end_define

end_unit

