begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: keysymdef.h,v 1.14 91/02/14 15:26:22 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_define
define|#
directive|define
name|XK_VoidSymbol
value|0xFFFFFF
end_define

begin_comment
comment|/* void symbol */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_MISCELLANY
end_ifdef

begin_comment
comment|/*  * TTY Functions, cleverly chosen to map to ascii, for convenience of  * programming, but could have been arbitrary (at the cost of lookup  * tables in client code.  */
end_comment

begin_define
define|#
directive|define
name|XK_BackSpace
value|0xFF08
end_define

begin_comment
comment|/* back space, back char */
end_comment

begin_define
define|#
directive|define
name|XK_Tab
value|0xFF09
end_define

begin_define
define|#
directive|define
name|XK_Linefeed
value|0xFF0A
end_define

begin_comment
comment|/* Linefeed, LF */
end_comment

begin_define
define|#
directive|define
name|XK_Clear
value|0xFF0B
end_define

begin_define
define|#
directive|define
name|XK_Return
value|0xFF0D
end_define

begin_comment
comment|/* Return, enter */
end_comment

begin_define
define|#
directive|define
name|XK_Pause
value|0xFF13
end_define

begin_comment
comment|/* Pause, hold */
end_comment

begin_define
define|#
directive|define
name|XK_Scroll_Lock
value|0xFF14
end_define

begin_define
define|#
directive|define
name|XK_Escape
value|0xFF1B
end_define

begin_define
define|#
directive|define
name|XK_Delete
value|0xFFFF
end_define

begin_comment
comment|/* Delete, rubout */
end_comment

begin_comment
comment|/* International& multi-key character composition */
end_comment

begin_define
define|#
directive|define
name|XK_Multi_key
value|0xFF20
end_define

begin_comment
comment|/* Multi-key character compose */
end_comment

begin_comment
comment|/* Japanese keyboard support */
end_comment

begin_define
define|#
directive|define
name|XK_Kanji
value|0xFF21
end_define

begin_comment
comment|/* Kanji, Kanji convert */
end_comment

begin_define
define|#
directive|define
name|XK_Muhenkan
value|0xFF22
end_define

begin_comment
comment|/* Cancel Conversion */
end_comment

begin_define
define|#
directive|define
name|XK_Henkan_Mode
value|0xFF23
end_define

begin_comment
comment|/* Start/Stop Conversion */
end_comment

begin_define
define|#
directive|define
name|XK_Henkan
value|0xFF23
end_define

begin_comment
comment|/* Alias for Henkan_Mode */
end_comment

begin_define
define|#
directive|define
name|XK_Romaji
value|0xFF24
end_define

begin_comment
comment|/* to Romaji */
end_comment

begin_define
define|#
directive|define
name|XK_Hiragana
value|0xFF25
end_define

begin_comment
comment|/* to Hiragana */
end_comment

begin_define
define|#
directive|define
name|XK_Katakana
value|0xFF26
end_define

begin_comment
comment|/* to Katakana */
end_comment

begin_define
define|#
directive|define
name|XK_Hiragana_Katakana
value|0xFF27
end_define

begin_comment
comment|/* Hiragana/Katakana toggle */
end_comment

begin_define
define|#
directive|define
name|XK_Zenkaku
value|0xFF28
end_define

begin_comment
comment|/* to Zenkaku */
end_comment

begin_define
define|#
directive|define
name|XK_Hankaku
value|0xFF29
end_define

begin_comment
comment|/* to Hankaku */
end_comment

begin_define
define|#
directive|define
name|XK_Zenkaku_Hankaku
value|0xFF2A
end_define

begin_comment
comment|/* Zenkaku/Hankaku toggle */
end_comment

begin_define
define|#
directive|define
name|XK_Touroku
value|0xFF2B
end_define

begin_comment
comment|/* Add to Dictionary */
end_comment

begin_define
define|#
directive|define
name|XK_Massyo
value|0xFF2C
end_define

begin_comment
comment|/* Delete from Dictionary */
end_comment

begin_define
define|#
directive|define
name|XK_Kana_Lock
value|0xFF2D
end_define

begin_comment
comment|/* Kana Lock */
end_comment

begin_define
define|#
directive|define
name|XK_Kana_Shift
value|0xFF2E
end_define

begin_comment
comment|/* Kana Shift */
end_comment

begin_define
define|#
directive|define
name|XK_Eisu_Shift
value|0xFF2F
end_define

begin_comment
comment|/* Alphanumeric Shift */
end_comment

begin_define
define|#
directive|define
name|XK_Eisu_toggle
value|0xFF30
end_define

begin_comment
comment|/* Alphanumeric toggle */
end_comment

begin_comment
comment|/* Cursor control& motion */
end_comment

begin_define
define|#
directive|define
name|XK_Home
value|0xFF50
end_define

begin_define
define|#
directive|define
name|XK_Left
value|0xFF51
end_define

begin_comment
comment|/* Move left, left arrow */
end_comment

begin_define
define|#
directive|define
name|XK_Up
value|0xFF52
end_define

begin_comment
comment|/* Move up, up arrow */
end_comment

begin_define
define|#
directive|define
name|XK_Right
value|0xFF53
end_define

begin_comment
comment|/* Move right, right arrow */
end_comment

begin_define
define|#
directive|define
name|XK_Down
value|0xFF54
end_define

begin_comment
comment|/* Move down, down arrow */
end_comment

begin_define
define|#
directive|define
name|XK_Prior
value|0xFF55
end_define

begin_comment
comment|/* Prior, previous */
end_comment

begin_define
define|#
directive|define
name|XK_Next
value|0xFF56
end_define

begin_comment
comment|/* Next */
end_comment

begin_define
define|#
directive|define
name|XK_End
value|0xFF57
end_define

begin_comment
comment|/* EOL */
end_comment

begin_define
define|#
directive|define
name|XK_Begin
value|0xFF58
end_define

begin_comment
comment|/* BOL */
end_comment

begin_comment
comment|/* Misc Functions */
end_comment

begin_define
define|#
directive|define
name|XK_Select
value|0xFF60
end_define

begin_comment
comment|/* Select, mark */
end_comment

begin_define
define|#
directive|define
name|XK_Print
value|0xFF61
end_define

begin_define
define|#
directive|define
name|XK_Execute
value|0xFF62
end_define

begin_comment
comment|/* Execute, run, do */
end_comment

begin_define
define|#
directive|define
name|XK_Insert
value|0xFF63
end_define

begin_comment
comment|/* Insert, insert here */
end_comment

begin_define
define|#
directive|define
name|XK_Undo
value|0xFF65
end_define

begin_comment
comment|/* Undo, oops */
end_comment

begin_define
define|#
directive|define
name|XK_Redo
value|0xFF66
end_define

begin_comment
comment|/* redo, again */
end_comment

begin_define
define|#
directive|define
name|XK_Menu
value|0xFF67
end_define

begin_define
define|#
directive|define
name|XK_Find
value|0xFF68
end_define

begin_comment
comment|/* Find, search */
end_comment

begin_define
define|#
directive|define
name|XK_Cancel
value|0xFF69
end_define

begin_comment
comment|/* Cancel, stop, abort, exit */
end_comment

begin_define
define|#
directive|define
name|XK_Help
value|0xFF6A
end_define

begin_comment
comment|/* Help, ? */
end_comment

begin_define
define|#
directive|define
name|XK_Break
value|0xFF6B
end_define

begin_define
define|#
directive|define
name|XK_Mode_switch
value|0xFF7E
end_define

begin_comment
comment|/* Character set switch */
end_comment

begin_define
define|#
directive|define
name|XK_script_switch
value|0xFF7E
end_define

begin_comment
comment|/* Alias for mode_switch */
end_comment

begin_define
define|#
directive|define
name|XK_Num_Lock
value|0xFF7F
end_define

begin_comment
comment|/* Keypad Functions, keypad numbers cleverly chosen to map to ascii */
end_comment

begin_define
define|#
directive|define
name|XK_KP_Space
value|0xFF80
end_define

begin_comment
comment|/* space */
end_comment

begin_define
define|#
directive|define
name|XK_KP_Tab
value|0xFF89
end_define

begin_define
define|#
directive|define
name|XK_KP_Enter
value|0xFF8D
end_define

begin_comment
comment|/* enter */
end_comment

begin_define
define|#
directive|define
name|XK_KP_F1
value|0xFF91
end_define

begin_comment
comment|/* PF1, KP_A, ... */
end_comment

begin_define
define|#
directive|define
name|XK_KP_F2
value|0xFF92
end_define

begin_define
define|#
directive|define
name|XK_KP_F3
value|0xFF93
end_define

begin_define
define|#
directive|define
name|XK_KP_F4
value|0xFF94
end_define

begin_define
define|#
directive|define
name|XK_KP_Equal
value|0xFFBD
end_define

begin_comment
comment|/* equals */
end_comment

begin_define
define|#
directive|define
name|XK_KP_Multiply
value|0xFFAA
end_define

begin_define
define|#
directive|define
name|XK_KP_Add
value|0xFFAB
end_define

begin_define
define|#
directive|define
name|XK_KP_Separator
value|0xFFAC
end_define

begin_comment
comment|/* separator, often comma */
end_comment

begin_define
define|#
directive|define
name|XK_KP_Subtract
value|0xFFAD
end_define

begin_define
define|#
directive|define
name|XK_KP_Decimal
value|0xFFAE
end_define

begin_define
define|#
directive|define
name|XK_KP_Divide
value|0xFFAF
end_define

begin_define
define|#
directive|define
name|XK_KP_0
value|0xFFB0
end_define

begin_define
define|#
directive|define
name|XK_KP_1
value|0xFFB1
end_define

begin_define
define|#
directive|define
name|XK_KP_2
value|0xFFB2
end_define

begin_define
define|#
directive|define
name|XK_KP_3
value|0xFFB3
end_define

begin_define
define|#
directive|define
name|XK_KP_4
value|0xFFB4
end_define

begin_define
define|#
directive|define
name|XK_KP_5
value|0xFFB5
end_define

begin_define
define|#
directive|define
name|XK_KP_6
value|0xFFB6
end_define

begin_define
define|#
directive|define
name|XK_KP_7
value|0xFFB7
end_define

begin_define
define|#
directive|define
name|XK_KP_8
value|0xFFB8
end_define

begin_define
define|#
directive|define
name|XK_KP_9
value|0xFFB9
end_define

begin_comment
comment|/*  * Auxilliary Functions; note the duplicate definitions for left and right  * function keys;  Sun keyboards and a few other manufactures have such  * function key groups on the left and/or right sides of the keyboard.  * We've not found a keyboard with more than 35 function keys total.  */
end_comment

begin_define
define|#
directive|define
name|XK_F1
value|0xFFBE
end_define

begin_define
define|#
directive|define
name|XK_F2
value|0xFFBF
end_define

begin_define
define|#
directive|define
name|XK_F3
value|0xFFC0
end_define

begin_define
define|#
directive|define
name|XK_F4
value|0xFFC1
end_define

begin_define
define|#
directive|define
name|XK_F5
value|0xFFC2
end_define

begin_define
define|#
directive|define
name|XK_F6
value|0xFFC3
end_define

begin_define
define|#
directive|define
name|XK_F7
value|0xFFC4
end_define

begin_define
define|#
directive|define
name|XK_F8
value|0xFFC5
end_define

begin_define
define|#
directive|define
name|XK_F9
value|0xFFC6
end_define

begin_define
define|#
directive|define
name|XK_F10
value|0xFFC7
end_define

begin_define
define|#
directive|define
name|XK_F11
value|0xFFC8
end_define

begin_define
define|#
directive|define
name|XK_L1
value|0xFFC8
end_define

begin_define
define|#
directive|define
name|XK_F12
value|0xFFC9
end_define

begin_define
define|#
directive|define
name|XK_L2
value|0xFFC9
end_define

begin_define
define|#
directive|define
name|XK_F13
value|0xFFCA
end_define

begin_define
define|#
directive|define
name|XK_L3
value|0xFFCA
end_define

begin_define
define|#
directive|define
name|XK_F14
value|0xFFCB
end_define

begin_define
define|#
directive|define
name|XK_L4
value|0xFFCB
end_define

begin_define
define|#
directive|define
name|XK_F15
value|0xFFCC
end_define

begin_define
define|#
directive|define
name|XK_L5
value|0xFFCC
end_define

begin_define
define|#
directive|define
name|XK_F16
value|0xFFCD
end_define

begin_define
define|#
directive|define
name|XK_L6
value|0xFFCD
end_define

begin_define
define|#
directive|define
name|XK_F17
value|0xFFCE
end_define

begin_define
define|#
directive|define
name|XK_L7
value|0xFFCE
end_define

begin_define
define|#
directive|define
name|XK_F18
value|0xFFCF
end_define

begin_define
define|#
directive|define
name|XK_L8
value|0xFFCF
end_define

begin_define
define|#
directive|define
name|XK_F19
value|0xFFD0
end_define

begin_define
define|#
directive|define
name|XK_L9
value|0xFFD0
end_define

begin_define
define|#
directive|define
name|XK_F20
value|0xFFD1
end_define

begin_define
define|#
directive|define
name|XK_L10
value|0xFFD1
end_define

begin_define
define|#
directive|define
name|XK_F21
value|0xFFD2
end_define

begin_define
define|#
directive|define
name|XK_R1
value|0xFFD2
end_define

begin_define
define|#
directive|define
name|XK_F22
value|0xFFD3
end_define

begin_define
define|#
directive|define
name|XK_R2
value|0xFFD3
end_define

begin_define
define|#
directive|define
name|XK_F23
value|0xFFD4
end_define

begin_define
define|#
directive|define
name|XK_R3
value|0xFFD4
end_define

begin_define
define|#
directive|define
name|XK_F24
value|0xFFD5
end_define

begin_define
define|#
directive|define
name|XK_R4
value|0xFFD5
end_define

begin_define
define|#
directive|define
name|XK_F25
value|0xFFD6
end_define

begin_define
define|#
directive|define
name|XK_R5
value|0xFFD6
end_define

begin_define
define|#
directive|define
name|XK_F26
value|0xFFD7
end_define

begin_define
define|#
directive|define
name|XK_R6
value|0xFFD7
end_define

begin_define
define|#
directive|define
name|XK_F27
value|0xFFD8
end_define

begin_define
define|#
directive|define
name|XK_R7
value|0xFFD8
end_define

begin_define
define|#
directive|define
name|XK_F28
value|0xFFD9
end_define

begin_define
define|#
directive|define
name|XK_R8
value|0xFFD9
end_define

begin_define
define|#
directive|define
name|XK_F29
value|0xFFDA
end_define

begin_define
define|#
directive|define
name|XK_R9
value|0xFFDA
end_define

begin_define
define|#
directive|define
name|XK_F30
value|0xFFDB
end_define

begin_define
define|#
directive|define
name|XK_R10
value|0xFFDB
end_define

begin_define
define|#
directive|define
name|XK_F31
value|0xFFDC
end_define

begin_define
define|#
directive|define
name|XK_R11
value|0xFFDC
end_define

begin_define
define|#
directive|define
name|XK_F32
value|0xFFDD
end_define

begin_define
define|#
directive|define
name|XK_R12
value|0xFFDD
end_define

begin_define
define|#
directive|define
name|XK_F33
value|0xFFDE
end_define

begin_define
define|#
directive|define
name|XK_R13
value|0xFFDE
end_define

begin_define
define|#
directive|define
name|XK_F34
value|0xFFDF
end_define

begin_define
define|#
directive|define
name|XK_R14
value|0xFFDF
end_define

begin_define
define|#
directive|define
name|XK_F35
value|0xFFE0
end_define

begin_define
define|#
directive|define
name|XK_R15
value|0xFFE0
end_define

begin_comment
comment|/* Modifiers */
end_comment

begin_define
define|#
directive|define
name|XK_Shift_L
value|0xFFE1
end_define

begin_comment
comment|/* Left shift */
end_comment

begin_define
define|#
directive|define
name|XK_Shift_R
value|0xFFE2
end_define

begin_comment
comment|/* Right shift */
end_comment

begin_define
define|#
directive|define
name|XK_Control_L
value|0xFFE3
end_define

begin_comment
comment|/* Left control */
end_comment

begin_define
define|#
directive|define
name|XK_Control_R
value|0xFFE4
end_define

begin_comment
comment|/* Right control */
end_comment

begin_define
define|#
directive|define
name|XK_Caps_Lock
value|0xFFE5
end_define

begin_comment
comment|/* Caps lock */
end_comment

begin_define
define|#
directive|define
name|XK_Shift_Lock
value|0xFFE6
end_define

begin_comment
comment|/* Shift lock */
end_comment

begin_define
define|#
directive|define
name|XK_Meta_L
value|0xFFE7
end_define

begin_comment
comment|/* Left meta */
end_comment

begin_define
define|#
directive|define
name|XK_Meta_R
value|0xFFE8
end_define

begin_comment
comment|/* Right meta */
end_comment

begin_define
define|#
directive|define
name|XK_Alt_L
value|0xFFE9
end_define

begin_comment
comment|/* Left alt */
end_comment

begin_define
define|#
directive|define
name|XK_Alt_R
value|0xFFEA
end_define

begin_comment
comment|/* Right alt */
end_comment

begin_define
define|#
directive|define
name|XK_Super_L
value|0xFFEB
end_define

begin_comment
comment|/* Left super */
end_comment

begin_define
define|#
directive|define
name|XK_Super_R
value|0xFFEC
end_define

begin_comment
comment|/* Right super */
end_comment

begin_define
define|#
directive|define
name|XK_Hyper_L
value|0xFFED
end_define

begin_comment
comment|/* Left hyper */
end_comment

begin_define
define|#
directive|define
name|XK_Hyper_R
value|0xFFEE
end_define

begin_comment
comment|/* Right hyper */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_MISCELLANY */
end_comment

begin_comment
comment|/*  *  Latin 1  *  Byte 3 = 0  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_LATIN1
end_ifdef

begin_define
define|#
directive|define
name|XK_space
value|0x020
end_define

begin_define
define|#
directive|define
name|XK_exclam
value|0x021
end_define

begin_define
define|#
directive|define
name|XK_quotedbl
value|0x022
end_define

begin_define
define|#
directive|define
name|XK_numbersign
value|0x023
end_define

begin_define
define|#
directive|define
name|XK_dollar
value|0x024
end_define

begin_define
define|#
directive|define
name|XK_percent
value|0x025
end_define

begin_define
define|#
directive|define
name|XK_ampersand
value|0x026
end_define

begin_define
define|#
directive|define
name|XK_apostrophe
value|0x027
end_define

begin_define
define|#
directive|define
name|XK_quoteright
value|0x027
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_parenleft
value|0x028
end_define

begin_define
define|#
directive|define
name|XK_parenright
value|0x029
end_define

begin_define
define|#
directive|define
name|XK_asterisk
value|0x02a
end_define

begin_define
define|#
directive|define
name|XK_plus
value|0x02b
end_define

begin_define
define|#
directive|define
name|XK_comma
value|0x02c
end_define

begin_define
define|#
directive|define
name|XK_minus
value|0x02d
end_define

begin_define
define|#
directive|define
name|XK_period
value|0x02e
end_define

begin_define
define|#
directive|define
name|XK_slash
value|0x02f
end_define

begin_define
define|#
directive|define
name|XK_0
value|0x030
end_define

begin_define
define|#
directive|define
name|XK_1
value|0x031
end_define

begin_define
define|#
directive|define
name|XK_2
value|0x032
end_define

begin_define
define|#
directive|define
name|XK_3
value|0x033
end_define

begin_define
define|#
directive|define
name|XK_4
value|0x034
end_define

begin_define
define|#
directive|define
name|XK_5
value|0x035
end_define

begin_define
define|#
directive|define
name|XK_6
value|0x036
end_define

begin_define
define|#
directive|define
name|XK_7
value|0x037
end_define

begin_define
define|#
directive|define
name|XK_8
value|0x038
end_define

begin_define
define|#
directive|define
name|XK_9
value|0x039
end_define

begin_define
define|#
directive|define
name|XK_colon
value|0x03a
end_define

begin_define
define|#
directive|define
name|XK_semicolon
value|0x03b
end_define

begin_define
define|#
directive|define
name|XK_less
value|0x03c
end_define

begin_define
define|#
directive|define
name|XK_equal
value|0x03d
end_define

begin_define
define|#
directive|define
name|XK_greater
value|0x03e
end_define

begin_define
define|#
directive|define
name|XK_question
value|0x03f
end_define

begin_define
define|#
directive|define
name|XK_at
value|0x040
end_define

begin_define
define|#
directive|define
name|XK_A
value|0x041
end_define

begin_define
define|#
directive|define
name|XK_B
value|0x042
end_define

begin_define
define|#
directive|define
name|XK_C
value|0x043
end_define

begin_define
define|#
directive|define
name|XK_D
value|0x044
end_define

begin_define
define|#
directive|define
name|XK_E
value|0x045
end_define

begin_define
define|#
directive|define
name|XK_F
value|0x046
end_define

begin_define
define|#
directive|define
name|XK_G
value|0x047
end_define

begin_define
define|#
directive|define
name|XK_H
value|0x048
end_define

begin_define
define|#
directive|define
name|XK_I
value|0x049
end_define

begin_define
define|#
directive|define
name|XK_J
value|0x04a
end_define

begin_define
define|#
directive|define
name|XK_K
value|0x04b
end_define

begin_define
define|#
directive|define
name|XK_L
value|0x04c
end_define

begin_define
define|#
directive|define
name|XK_M
value|0x04d
end_define

begin_define
define|#
directive|define
name|XK_N
value|0x04e
end_define

begin_define
define|#
directive|define
name|XK_O
value|0x04f
end_define

begin_define
define|#
directive|define
name|XK_P
value|0x050
end_define

begin_define
define|#
directive|define
name|XK_Q
value|0x051
end_define

begin_define
define|#
directive|define
name|XK_R
value|0x052
end_define

begin_define
define|#
directive|define
name|XK_S
value|0x053
end_define

begin_define
define|#
directive|define
name|XK_T
value|0x054
end_define

begin_define
define|#
directive|define
name|XK_U
value|0x055
end_define

begin_define
define|#
directive|define
name|XK_V
value|0x056
end_define

begin_define
define|#
directive|define
name|XK_W
value|0x057
end_define

begin_define
define|#
directive|define
name|XK_X
value|0x058
end_define

begin_define
define|#
directive|define
name|XK_Y
value|0x059
end_define

begin_define
define|#
directive|define
name|XK_Z
value|0x05a
end_define

begin_define
define|#
directive|define
name|XK_bracketleft
value|0x05b
end_define

begin_define
define|#
directive|define
name|XK_backslash
value|0x05c
end_define

begin_define
define|#
directive|define
name|XK_bracketright
value|0x05d
end_define

begin_define
define|#
directive|define
name|XK_asciicircum
value|0x05e
end_define

begin_define
define|#
directive|define
name|XK_underscore
value|0x05f
end_define

begin_define
define|#
directive|define
name|XK_grave
value|0x060
end_define

begin_define
define|#
directive|define
name|XK_quoteleft
value|0x060
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_a
value|0x061
end_define

begin_define
define|#
directive|define
name|XK_b
value|0x062
end_define

begin_define
define|#
directive|define
name|XK_c
value|0x063
end_define

begin_define
define|#
directive|define
name|XK_d
value|0x064
end_define

begin_define
define|#
directive|define
name|XK_e
value|0x065
end_define

begin_define
define|#
directive|define
name|XK_f
value|0x066
end_define

begin_define
define|#
directive|define
name|XK_g
value|0x067
end_define

begin_define
define|#
directive|define
name|XK_h
value|0x068
end_define

begin_define
define|#
directive|define
name|XK_i
value|0x069
end_define

begin_define
define|#
directive|define
name|XK_j
value|0x06a
end_define

begin_define
define|#
directive|define
name|XK_k
value|0x06b
end_define

begin_define
define|#
directive|define
name|XK_l
value|0x06c
end_define

begin_define
define|#
directive|define
name|XK_m
value|0x06d
end_define

begin_define
define|#
directive|define
name|XK_n
value|0x06e
end_define

begin_define
define|#
directive|define
name|XK_o
value|0x06f
end_define

begin_define
define|#
directive|define
name|XK_p
value|0x070
end_define

begin_define
define|#
directive|define
name|XK_q
value|0x071
end_define

begin_define
define|#
directive|define
name|XK_r
value|0x072
end_define

begin_define
define|#
directive|define
name|XK_s
value|0x073
end_define

begin_define
define|#
directive|define
name|XK_t
value|0x074
end_define

begin_define
define|#
directive|define
name|XK_u
value|0x075
end_define

begin_define
define|#
directive|define
name|XK_v
value|0x076
end_define

begin_define
define|#
directive|define
name|XK_w
value|0x077
end_define

begin_define
define|#
directive|define
name|XK_x
value|0x078
end_define

begin_define
define|#
directive|define
name|XK_y
value|0x079
end_define

begin_define
define|#
directive|define
name|XK_z
value|0x07a
end_define

begin_define
define|#
directive|define
name|XK_braceleft
value|0x07b
end_define

begin_define
define|#
directive|define
name|XK_bar
value|0x07c
end_define

begin_define
define|#
directive|define
name|XK_braceright
value|0x07d
end_define

begin_define
define|#
directive|define
name|XK_asciitilde
value|0x07e
end_define

begin_define
define|#
directive|define
name|XK_nobreakspace
value|0x0a0
end_define

begin_define
define|#
directive|define
name|XK_exclamdown
value|0x0a1
end_define

begin_define
define|#
directive|define
name|XK_cent
value|0x0a2
end_define

begin_define
define|#
directive|define
name|XK_sterling
value|0x0a3
end_define

begin_define
define|#
directive|define
name|XK_currency
value|0x0a4
end_define

begin_define
define|#
directive|define
name|XK_yen
value|0x0a5
end_define

begin_define
define|#
directive|define
name|XK_brokenbar
value|0x0a6
end_define

begin_define
define|#
directive|define
name|XK_section
value|0x0a7
end_define

begin_define
define|#
directive|define
name|XK_diaeresis
value|0x0a8
end_define

begin_define
define|#
directive|define
name|XK_copyright
value|0x0a9
end_define

begin_define
define|#
directive|define
name|XK_ordfeminine
value|0x0aa
end_define

begin_define
define|#
directive|define
name|XK_guillemotleft
value|0x0ab
end_define

begin_comment
comment|/* left angle quotation mark */
end_comment

begin_define
define|#
directive|define
name|XK_notsign
value|0x0ac
end_define

begin_define
define|#
directive|define
name|XK_hyphen
value|0x0ad
end_define

begin_define
define|#
directive|define
name|XK_registered
value|0x0ae
end_define

begin_define
define|#
directive|define
name|XK_macron
value|0x0af
end_define

begin_define
define|#
directive|define
name|XK_degree
value|0x0b0
end_define

begin_define
define|#
directive|define
name|XK_plusminus
value|0x0b1
end_define

begin_define
define|#
directive|define
name|XK_twosuperior
value|0x0b2
end_define

begin_define
define|#
directive|define
name|XK_threesuperior
value|0x0b3
end_define

begin_define
define|#
directive|define
name|XK_acute
value|0x0b4
end_define

begin_define
define|#
directive|define
name|XK_mu
value|0x0b5
end_define

begin_define
define|#
directive|define
name|XK_paragraph
value|0x0b6
end_define

begin_define
define|#
directive|define
name|XK_periodcentered
value|0x0b7
end_define

begin_define
define|#
directive|define
name|XK_cedilla
value|0x0b8
end_define

begin_define
define|#
directive|define
name|XK_onesuperior
value|0x0b9
end_define

begin_define
define|#
directive|define
name|XK_masculine
value|0x0ba
end_define

begin_define
define|#
directive|define
name|XK_guillemotright
value|0x0bb
end_define

begin_comment
comment|/* right angle quotation mark */
end_comment

begin_define
define|#
directive|define
name|XK_onequarter
value|0x0bc
end_define

begin_define
define|#
directive|define
name|XK_onehalf
value|0x0bd
end_define

begin_define
define|#
directive|define
name|XK_threequarters
value|0x0be
end_define

begin_define
define|#
directive|define
name|XK_questiondown
value|0x0bf
end_define

begin_define
define|#
directive|define
name|XK_Agrave
value|0x0c0
end_define

begin_define
define|#
directive|define
name|XK_Aacute
value|0x0c1
end_define

begin_define
define|#
directive|define
name|XK_Acircumflex
value|0x0c2
end_define

begin_define
define|#
directive|define
name|XK_Atilde
value|0x0c3
end_define

begin_define
define|#
directive|define
name|XK_Adiaeresis
value|0x0c4
end_define

begin_define
define|#
directive|define
name|XK_Aring
value|0x0c5
end_define

begin_define
define|#
directive|define
name|XK_AE
value|0x0c6
end_define

begin_define
define|#
directive|define
name|XK_Ccedilla
value|0x0c7
end_define

begin_define
define|#
directive|define
name|XK_Egrave
value|0x0c8
end_define

begin_define
define|#
directive|define
name|XK_Eacute
value|0x0c9
end_define

begin_define
define|#
directive|define
name|XK_Ecircumflex
value|0x0ca
end_define

begin_define
define|#
directive|define
name|XK_Ediaeresis
value|0x0cb
end_define

begin_define
define|#
directive|define
name|XK_Igrave
value|0x0cc
end_define

begin_define
define|#
directive|define
name|XK_Iacute
value|0x0cd
end_define

begin_define
define|#
directive|define
name|XK_Icircumflex
value|0x0ce
end_define

begin_define
define|#
directive|define
name|XK_Idiaeresis
value|0x0cf
end_define

begin_define
define|#
directive|define
name|XK_ETH
value|0x0d0
end_define

begin_define
define|#
directive|define
name|XK_Eth
value|0x0d0
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Ntilde
value|0x0d1
end_define

begin_define
define|#
directive|define
name|XK_Ograve
value|0x0d2
end_define

begin_define
define|#
directive|define
name|XK_Oacute
value|0x0d3
end_define

begin_define
define|#
directive|define
name|XK_Ocircumflex
value|0x0d4
end_define

begin_define
define|#
directive|define
name|XK_Otilde
value|0x0d5
end_define

begin_define
define|#
directive|define
name|XK_Odiaeresis
value|0x0d6
end_define

begin_define
define|#
directive|define
name|XK_multiply
value|0x0d7
end_define

begin_define
define|#
directive|define
name|XK_Ooblique
value|0x0d8
end_define

begin_define
define|#
directive|define
name|XK_Ugrave
value|0x0d9
end_define

begin_define
define|#
directive|define
name|XK_Uacute
value|0x0da
end_define

begin_define
define|#
directive|define
name|XK_Ucircumflex
value|0x0db
end_define

begin_define
define|#
directive|define
name|XK_Udiaeresis
value|0x0dc
end_define

begin_define
define|#
directive|define
name|XK_Yacute
value|0x0dd
end_define

begin_define
define|#
directive|define
name|XK_THORN
value|0x0de
end_define

begin_define
define|#
directive|define
name|XK_Thorn
value|0x0de
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_ssharp
value|0x0df
end_define

begin_define
define|#
directive|define
name|XK_agrave
value|0x0e0
end_define

begin_define
define|#
directive|define
name|XK_aacute
value|0x0e1
end_define

begin_define
define|#
directive|define
name|XK_acircumflex
value|0x0e2
end_define

begin_define
define|#
directive|define
name|XK_atilde
value|0x0e3
end_define

begin_define
define|#
directive|define
name|XK_adiaeresis
value|0x0e4
end_define

begin_define
define|#
directive|define
name|XK_aring
value|0x0e5
end_define

begin_define
define|#
directive|define
name|XK_ae
value|0x0e6
end_define

begin_define
define|#
directive|define
name|XK_ccedilla
value|0x0e7
end_define

begin_define
define|#
directive|define
name|XK_egrave
value|0x0e8
end_define

begin_define
define|#
directive|define
name|XK_eacute
value|0x0e9
end_define

begin_define
define|#
directive|define
name|XK_ecircumflex
value|0x0ea
end_define

begin_define
define|#
directive|define
name|XK_ediaeresis
value|0x0eb
end_define

begin_define
define|#
directive|define
name|XK_igrave
value|0x0ec
end_define

begin_define
define|#
directive|define
name|XK_iacute
value|0x0ed
end_define

begin_define
define|#
directive|define
name|XK_icircumflex
value|0x0ee
end_define

begin_define
define|#
directive|define
name|XK_idiaeresis
value|0x0ef
end_define

begin_define
define|#
directive|define
name|XK_eth
value|0x0f0
end_define

begin_define
define|#
directive|define
name|XK_ntilde
value|0x0f1
end_define

begin_define
define|#
directive|define
name|XK_ograve
value|0x0f2
end_define

begin_define
define|#
directive|define
name|XK_oacute
value|0x0f3
end_define

begin_define
define|#
directive|define
name|XK_ocircumflex
value|0x0f4
end_define

begin_define
define|#
directive|define
name|XK_otilde
value|0x0f5
end_define

begin_define
define|#
directive|define
name|XK_odiaeresis
value|0x0f6
end_define

begin_define
define|#
directive|define
name|XK_division
value|0x0f7
end_define

begin_define
define|#
directive|define
name|XK_oslash
value|0x0f8
end_define

begin_define
define|#
directive|define
name|XK_ugrave
value|0x0f9
end_define

begin_define
define|#
directive|define
name|XK_uacute
value|0x0fa
end_define

begin_define
define|#
directive|define
name|XK_ucircumflex
value|0x0fb
end_define

begin_define
define|#
directive|define
name|XK_udiaeresis
value|0x0fc
end_define

begin_define
define|#
directive|define
name|XK_yacute
value|0x0fd
end_define

begin_define
define|#
directive|define
name|XK_thorn
value|0x0fe
end_define

begin_define
define|#
directive|define
name|XK_ydiaeresis
value|0x0ff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_LATIN1 */
end_comment

begin_comment
comment|/*  *   Latin 2  *   Byte 3 = 1  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_LATIN2
end_ifdef

begin_define
define|#
directive|define
name|XK_Aogonek
value|0x1a1
end_define

begin_define
define|#
directive|define
name|XK_breve
value|0x1a2
end_define

begin_define
define|#
directive|define
name|XK_Lstroke
value|0x1a3
end_define

begin_define
define|#
directive|define
name|XK_Lcaron
value|0x1a5
end_define

begin_define
define|#
directive|define
name|XK_Sacute
value|0x1a6
end_define

begin_define
define|#
directive|define
name|XK_Scaron
value|0x1a9
end_define

begin_define
define|#
directive|define
name|XK_Scedilla
value|0x1aa
end_define

begin_define
define|#
directive|define
name|XK_Tcaron
value|0x1ab
end_define

begin_define
define|#
directive|define
name|XK_Zacute
value|0x1ac
end_define

begin_define
define|#
directive|define
name|XK_Zcaron
value|0x1ae
end_define

begin_define
define|#
directive|define
name|XK_Zabovedot
value|0x1af
end_define

begin_define
define|#
directive|define
name|XK_aogonek
value|0x1b1
end_define

begin_define
define|#
directive|define
name|XK_ogonek
value|0x1b2
end_define

begin_define
define|#
directive|define
name|XK_lstroke
value|0x1b3
end_define

begin_define
define|#
directive|define
name|XK_lcaron
value|0x1b5
end_define

begin_define
define|#
directive|define
name|XK_sacute
value|0x1b6
end_define

begin_define
define|#
directive|define
name|XK_caron
value|0x1b7
end_define

begin_define
define|#
directive|define
name|XK_scaron
value|0x1b9
end_define

begin_define
define|#
directive|define
name|XK_scedilla
value|0x1ba
end_define

begin_define
define|#
directive|define
name|XK_tcaron
value|0x1bb
end_define

begin_define
define|#
directive|define
name|XK_zacute
value|0x1bc
end_define

begin_define
define|#
directive|define
name|XK_doubleacute
value|0x1bd
end_define

begin_define
define|#
directive|define
name|XK_zcaron
value|0x1be
end_define

begin_define
define|#
directive|define
name|XK_zabovedot
value|0x1bf
end_define

begin_define
define|#
directive|define
name|XK_Racute
value|0x1c0
end_define

begin_define
define|#
directive|define
name|XK_Abreve
value|0x1c3
end_define

begin_define
define|#
directive|define
name|XK_Lacute
value|0x1c5
end_define

begin_define
define|#
directive|define
name|XK_Cacute
value|0x1c6
end_define

begin_define
define|#
directive|define
name|XK_Ccaron
value|0x1c8
end_define

begin_define
define|#
directive|define
name|XK_Eogonek
value|0x1ca
end_define

begin_define
define|#
directive|define
name|XK_Ecaron
value|0x1cc
end_define

begin_define
define|#
directive|define
name|XK_Dcaron
value|0x1cf
end_define

begin_define
define|#
directive|define
name|XK_Dstroke
value|0x1d0
end_define

begin_define
define|#
directive|define
name|XK_Nacute
value|0x1d1
end_define

begin_define
define|#
directive|define
name|XK_Ncaron
value|0x1d2
end_define

begin_define
define|#
directive|define
name|XK_Odoubleacute
value|0x1d5
end_define

begin_define
define|#
directive|define
name|XK_Rcaron
value|0x1d8
end_define

begin_define
define|#
directive|define
name|XK_Uring
value|0x1d9
end_define

begin_define
define|#
directive|define
name|XK_Udoubleacute
value|0x1db
end_define

begin_define
define|#
directive|define
name|XK_Tcedilla
value|0x1de
end_define

begin_define
define|#
directive|define
name|XK_racute
value|0x1e0
end_define

begin_define
define|#
directive|define
name|XK_abreve
value|0x1e3
end_define

begin_define
define|#
directive|define
name|XK_lacute
value|0x1e5
end_define

begin_define
define|#
directive|define
name|XK_cacute
value|0x1e6
end_define

begin_define
define|#
directive|define
name|XK_ccaron
value|0x1e8
end_define

begin_define
define|#
directive|define
name|XK_eogonek
value|0x1ea
end_define

begin_define
define|#
directive|define
name|XK_ecaron
value|0x1ec
end_define

begin_define
define|#
directive|define
name|XK_dcaron
value|0x1ef
end_define

begin_define
define|#
directive|define
name|XK_dstroke
value|0x1f0
end_define

begin_define
define|#
directive|define
name|XK_nacute
value|0x1f1
end_define

begin_define
define|#
directive|define
name|XK_ncaron
value|0x1f2
end_define

begin_define
define|#
directive|define
name|XK_odoubleacute
value|0x1f5
end_define

begin_define
define|#
directive|define
name|XK_udoubleacute
value|0x1fb
end_define

begin_define
define|#
directive|define
name|XK_rcaron
value|0x1f8
end_define

begin_define
define|#
directive|define
name|XK_uring
value|0x1f9
end_define

begin_define
define|#
directive|define
name|XK_tcedilla
value|0x1fe
end_define

begin_define
define|#
directive|define
name|XK_abovedot
value|0x1ff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_LATIN2 */
end_comment

begin_comment
comment|/*  *   Latin 3  *   Byte 3 = 2  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_LATIN3
end_ifdef

begin_define
define|#
directive|define
name|XK_Hstroke
value|0x2a1
end_define

begin_define
define|#
directive|define
name|XK_Hcircumflex
value|0x2a6
end_define

begin_define
define|#
directive|define
name|XK_Iabovedot
value|0x2a9
end_define

begin_define
define|#
directive|define
name|XK_Gbreve
value|0x2ab
end_define

begin_define
define|#
directive|define
name|XK_Jcircumflex
value|0x2ac
end_define

begin_define
define|#
directive|define
name|XK_hstroke
value|0x2b1
end_define

begin_define
define|#
directive|define
name|XK_hcircumflex
value|0x2b6
end_define

begin_define
define|#
directive|define
name|XK_idotless
value|0x2b9
end_define

begin_define
define|#
directive|define
name|XK_gbreve
value|0x2bb
end_define

begin_define
define|#
directive|define
name|XK_jcircumflex
value|0x2bc
end_define

begin_define
define|#
directive|define
name|XK_Cabovedot
value|0x2c5
end_define

begin_define
define|#
directive|define
name|XK_Ccircumflex
value|0x2c6
end_define

begin_define
define|#
directive|define
name|XK_Gabovedot
value|0x2d5
end_define

begin_define
define|#
directive|define
name|XK_Gcircumflex
value|0x2d8
end_define

begin_define
define|#
directive|define
name|XK_Ubreve
value|0x2dd
end_define

begin_define
define|#
directive|define
name|XK_Scircumflex
value|0x2de
end_define

begin_define
define|#
directive|define
name|XK_cabovedot
value|0x2e5
end_define

begin_define
define|#
directive|define
name|XK_ccircumflex
value|0x2e6
end_define

begin_define
define|#
directive|define
name|XK_gabovedot
value|0x2f5
end_define

begin_define
define|#
directive|define
name|XK_gcircumflex
value|0x2f8
end_define

begin_define
define|#
directive|define
name|XK_ubreve
value|0x2fd
end_define

begin_define
define|#
directive|define
name|XK_scircumflex
value|0x2fe
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_LATIN3 */
end_comment

begin_comment
comment|/*  *   Latin 4  *   Byte 3 = 3  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_LATIN4
end_ifdef

begin_define
define|#
directive|define
name|XK_kra
value|0x3a2
end_define

begin_define
define|#
directive|define
name|XK_kappa
value|0x3a2
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Rcedilla
value|0x3a3
end_define

begin_define
define|#
directive|define
name|XK_Itilde
value|0x3a5
end_define

begin_define
define|#
directive|define
name|XK_Lcedilla
value|0x3a6
end_define

begin_define
define|#
directive|define
name|XK_Emacron
value|0x3aa
end_define

begin_define
define|#
directive|define
name|XK_Gcedilla
value|0x3ab
end_define

begin_define
define|#
directive|define
name|XK_Tslash
value|0x3ac
end_define

begin_define
define|#
directive|define
name|XK_rcedilla
value|0x3b3
end_define

begin_define
define|#
directive|define
name|XK_itilde
value|0x3b5
end_define

begin_define
define|#
directive|define
name|XK_lcedilla
value|0x3b6
end_define

begin_define
define|#
directive|define
name|XK_emacron
value|0x3ba
end_define

begin_define
define|#
directive|define
name|XK_gcedilla
value|0x3bb
end_define

begin_define
define|#
directive|define
name|XK_tslash
value|0x3bc
end_define

begin_define
define|#
directive|define
name|XK_ENG
value|0x3bd
end_define

begin_define
define|#
directive|define
name|XK_eng
value|0x3bf
end_define

begin_define
define|#
directive|define
name|XK_Amacron
value|0x3c0
end_define

begin_define
define|#
directive|define
name|XK_Iogonek
value|0x3c7
end_define

begin_define
define|#
directive|define
name|XK_Eabovedot
value|0x3cc
end_define

begin_define
define|#
directive|define
name|XK_Imacron
value|0x3cf
end_define

begin_define
define|#
directive|define
name|XK_Ncedilla
value|0x3d1
end_define

begin_define
define|#
directive|define
name|XK_Omacron
value|0x3d2
end_define

begin_define
define|#
directive|define
name|XK_Kcedilla
value|0x3d3
end_define

begin_define
define|#
directive|define
name|XK_Uogonek
value|0x3d9
end_define

begin_define
define|#
directive|define
name|XK_Utilde
value|0x3dd
end_define

begin_define
define|#
directive|define
name|XK_Umacron
value|0x3de
end_define

begin_define
define|#
directive|define
name|XK_amacron
value|0x3e0
end_define

begin_define
define|#
directive|define
name|XK_iogonek
value|0x3e7
end_define

begin_define
define|#
directive|define
name|XK_eabovedot
value|0x3ec
end_define

begin_define
define|#
directive|define
name|XK_imacron
value|0x3ef
end_define

begin_define
define|#
directive|define
name|XK_ncedilla
value|0x3f1
end_define

begin_define
define|#
directive|define
name|XK_omacron
value|0x3f2
end_define

begin_define
define|#
directive|define
name|XK_kcedilla
value|0x3f3
end_define

begin_define
define|#
directive|define
name|XK_uogonek
value|0x3f9
end_define

begin_define
define|#
directive|define
name|XK_utilde
value|0x3fd
end_define

begin_define
define|#
directive|define
name|XK_umacron
value|0x3fe
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_LATIN4 */
end_comment

begin_comment
comment|/*  * Katakana  * Byte 3 = 4  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_KATAKANA
end_ifdef

begin_define
define|#
directive|define
name|XK_overline
value|0x47e
end_define

begin_define
define|#
directive|define
name|XK_kana_fullstop
value|0x4a1
end_define

begin_define
define|#
directive|define
name|XK_kana_openingbracket
value|0x4a2
end_define

begin_define
define|#
directive|define
name|XK_kana_closingbracket
value|0x4a3
end_define

begin_define
define|#
directive|define
name|XK_kana_comma
value|0x4a4
end_define

begin_define
define|#
directive|define
name|XK_kana_conjunctive
value|0x4a5
end_define

begin_define
define|#
directive|define
name|XK_kana_middledot
value|0x4a5
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_kana_WO
value|0x4a6
end_define

begin_define
define|#
directive|define
name|XK_kana_a
value|0x4a7
end_define

begin_define
define|#
directive|define
name|XK_kana_i
value|0x4a8
end_define

begin_define
define|#
directive|define
name|XK_kana_u
value|0x4a9
end_define

begin_define
define|#
directive|define
name|XK_kana_e
value|0x4aa
end_define

begin_define
define|#
directive|define
name|XK_kana_o
value|0x4ab
end_define

begin_define
define|#
directive|define
name|XK_kana_ya
value|0x4ac
end_define

begin_define
define|#
directive|define
name|XK_kana_yu
value|0x4ad
end_define

begin_define
define|#
directive|define
name|XK_kana_yo
value|0x4ae
end_define

begin_define
define|#
directive|define
name|XK_kana_tsu
value|0x4af
end_define

begin_define
define|#
directive|define
name|XK_kana_tu
value|0x4af
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_prolongedsound
value|0x4b0
end_define

begin_define
define|#
directive|define
name|XK_kana_A
value|0x4b1
end_define

begin_define
define|#
directive|define
name|XK_kana_I
value|0x4b2
end_define

begin_define
define|#
directive|define
name|XK_kana_U
value|0x4b3
end_define

begin_define
define|#
directive|define
name|XK_kana_E
value|0x4b4
end_define

begin_define
define|#
directive|define
name|XK_kana_O
value|0x4b5
end_define

begin_define
define|#
directive|define
name|XK_kana_KA
value|0x4b6
end_define

begin_define
define|#
directive|define
name|XK_kana_KI
value|0x4b7
end_define

begin_define
define|#
directive|define
name|XK_kana_KU
value|0x4b8
end_define

begin_define
define|#
directive|define
name|XK_kana_KE
value|0x4b9
end_define

begin_define
define|#
directive|define
name|XK_kana_KO
value|0x4ba
end_define

begin_define
define|#
directive|define
name|XK_kana_SA
value|0x4bb
end_define

begin_define
define|#
directive|define
name|XK_kana_SHI
value|0x4bc
end_define

begin_define
define|#
directive|define
name|XK_kana_SU
value|0x4bd
end_define

begin_define
define|#
directive|define
name|XK_kana_SE
value|0x4be
end_define

begin_define
define|#
directive|define
name|XK_kana_SO
value|0x4bf
end_define

begin_define
define|#
directive|define
name|XK_kana_TA
value|0x4c0
end_define

begin_define
define|#
directive|define
name|XK_kana_CHI
value|0x4c1
end_define

begin_define
define|#
directive|define
name|XK_kana_TI
value|0x4c1
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_kana_TSU
value|0x4c2
end_define

begin_define
define|#
directive|define
name|XK_kana_TU
value|0x4c2
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_kana_TE
value|0x4c3
end_define

begin_define
define|#
directive|define
name|XK_kana_TO
value|0x4c4
end_define

begin_define
define|#
directive|define
name|XK_kana_NA
value|0x4c5
end_define

begin_define
define|#
directive|define
name|XK_kana_NI
value|0x4c6
end_define

begin_define
define|#
directive|define
name|XK_kana_NU
value|0x4c7
end_define

begin_define
define|#
directive|define
name|XK_kana_NE
value|0x4c8
end_define

begin_define
define|#
directive|define
name|XK_kana_NO
value|0x4c9
end_define

begin_define
define|#
directive|define
name|XK_kana_HA
value|0x4ca
end_define

begin_define
define|#
directive|define
name|XK_kana_HI
value|0x4cb
end_define

begin_define
define|#
directive|define
name|XK_kana_FU
value|0x4cc
end_define

begin_define
define|#
directive|define
name|XK_kana_HU
value|0x4cc
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_kana_HE
value|0x4cd
end_define

begin_define
define|#
directive|define
name|XK_kana_HO
value|0x4ce
end_define

begin_define
define|#
directive|define
name|XK_kana_MA
value|0x4cf
end_define

begin_define
define|#
directive|define
name|XK_kana_MI
value|0x4d0
end_define

begin_define
define|#
directive|define
name|XK_kana_MU
value|0x4d1
end_define

begin_define
define|#
directive|define
name|XK_kana_ME
value|0x4d2
end_define

begin_define
define|#
directive|define
name|XK_kana_MO
value|0x4d3
end_define

begin_define
define|#
directive|define
name|XK_kana_YA
value|0x4d4
end_define

begin_define
define|#
directive|define
name|XK_kana_YU
value|0x4d5
end_define

begin_define
define|#
directive|define
name|XK_kana_YO
value|0x4d6
end_define

begin_define
define|#
directive|define
name|XK_kana_RA
value|0x4d7
end_define

begin_define
define|#
directive|define
name|XK_kana_RI
value|0x4d8
end_define

begin_define
define|#
directive|define
name|XK_kana_RU
value|0x4d9
end_define

begin_define
define|#
directive|define
name|XK_kana_RE
value|0x4da
end_define

begin_define
define|#
directive|define
name|XK_kana_RO
value|0x4db
end_define

begin_define
define|#
directive|define
name|XK_kana_WA
value|0x4dc
end_define

begin_define
define|#
directive|define
name|XK_kana_N
value|0x4dd
end_define

begin_define
define|#
directive|define
name|XK_voicedsound
value|0x4de
end_define

begin_define
define|#
directive|define
name|XK_semivoicedsound
value|0x4df
end_define

begin_define
define|#
directive|define
name|XK_kana_switch
value|0xFF7E
end_define

begin_comment
comment|/* Alias for mode_switch */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_KATAKANA */
end_comment

begin_comment
comment|/*  *  Arabic  *  Byte 3 = 5  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_ARABIC
end_ifdef

begin_define
define|#
directive|define
name|XK_Arabic_comma
value|0x5ac
end_define

begin_define
define|#
directive|define
name|XK_Arabic_semicolon
value|0x5bb
end_define

begin_define
define|#
directive|define
name|XK_Arabic_question_mark
value|0x5bf
end_define

begin_define
define|#
directive|define
name|XK_Arabic_hamza
value|0x5c1
end_define

begin_define
define|#
directive|define
name|XK_Arabic_maddaonalef
value|0x5c2
end_define

begin_define
define|#
directive|define
name|XK_Arabic_hamzaonalef
value|0x5c3
end_define

begin_define
define|#
directive|define
name|XK_Arabic_hamzaonwaw
value|0x5c4
end_define

begin_define
define|#
directive|define
name|XK_Arabic_hamzaunderalef
value|0x5c5
end_define

begin_define
define|#
directive|define
name|XK_Arabic_hamzaonyeh
value|0x5c6
end_define

begin_define
define|#
directive|define
name|XK_Arabic_alef
value|0x5c7
end_define

begin_define
define|#
directive|define
name|XK_Arabic_beh
value|0x5c8
end_define

begin_define
define|#
directive|define
name|XK_Arabic_tehmarbuta
value|0x5c9
end_define

begin_define
define|#
directive|define
name|XK_Arabic_teh
value|0x5ca
end_define

begin_define
define|#
directive|define
name|XK_Arabic_theh
value|0x5cb
end_define

begin_define
define|#
directive|define
name|XK_Arabic_jeem
value|0x5cc
end_define

begin_define
define|#
directive|define
name|XK_Arabic_hah
value|0x5cd
end_define

begin_define
define|#
directive|define
name|XK_Arabic_khah
value|0x5ce
end_define

begin_define
define|#
directive|define
name|XK_Arabic_dal
value|0x5cf
end_define

begin_define
define|#
directive|define
name|XK_Arabic_thal
value|0x5d0
end_define

begin_define
define|#
directive|define
name|XK_Arabic_ra
value|0x5d1
end_define

begin_define
define|#
directive|define
name|XK_Arabic_zain
value|0x5d2
end_define

begin_define
define|#
directive|define
name|XK_Arabic_seen
value|0x5d3
end_define

begin_define
define|#
directive|define
name|XK_Arabic_sheen
value|0x5d4
end_define

begin_define
define|#
directive|define
name|XK_Arabic_sad
value|0x5d5
end_define

begin_define
define|#
directive|define
name|XK_Arabic_dad
value|0x5d6
end_define

begin_define
define|#
directive|define
name|XK_Arabic_tah
value|0x5d7
end_define

begin_define
define|#
directive|define
name|XK_Arabic_zah
value|0x5d8
end_define

begin_define
define|#
directive|define
name|XK_Arabic_ain
value|0x5d9
end_define

begin_define
define|#
directive|define
name|XK_Arabic_ghain
value|0x5da
end_define

begin_define
define|#
directive|define
name|XK_Arabic_tatweel
value|0x5e0
end_define

begin_define
define|#
directive|define
name|XK_Arabic_feh
value|0x5e1
end_define

begin_define
define|#
directive|define
name|XK_Arabic_qaf
value|0x5e2
end_define

begin_define
define|#
directive|define
name|XK_Arabic_kaf
value|0x5e3
end_define

begin_define
define|#
directive|define
name|XK_Arabic_lam
value|0x5e4
end_define

begin_define
define|#
directive|define
name|XK_Arabic_meem
value|0x5e5
end_define

begin_define
define|#
directive|define
name|XK_Arabic_noon
value|0x5e6
end_define

begin_define
define|#
directive|define
name|XK_Arabic_ha
value|0x5e7
end_define

begin_define
define|#
directive|define
name|XK_Arabic_heh
value|0x5e7
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Arabic_waw
value|0x5e8
end_define

begin_define
define|#
directive|define
name|XK_Arabic_alefmaksura
value|0x5e9
end_define

begin_define
define|#
directive|define
name|XK_Arabic_yeh
value|0x5ea
end_define

begin_define
define|#
directive|define
name|XK_Arabic_fathatan
value|0x5eb
end_define

begin_define
define|#
directive|define
name|XK_Arabic_dammatan
value|0x5ec
end_define

begin_define
define|#
directive|define
name|XK_Arabic_kasratan
value|0x5ed
end_define

begin_define
define|#
directive|define
name|XK_Arabic_fatha
value|0x5ee
end_define

begin_define
define|#
directive|define
name|XK_Arabic_damma
value|0x5ef
end_define

begin_define
define|#
directive|define
name|XK_Arabic_kasra
value|0x5f0
end_define

begin_define
define|#
directive|define
name|XK_Arabic_shadda
value|0x5f1
end_define

begin_define
define|#
directive|define
name|XK_Arabic_sukun
value|0x5f2
end_define

begin_define
define|#
directive|define
name|XK_Arabic_switch
value|0xFF7E
end_define

begin_comment
comment|/* Alias for mode_switch */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_ARABIC */
end_comment

begin_comment
comment|/*  * Cyrillic  * Byte 3 = 6  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_CYRILLIC
end_ifdef

begin_define
define|#
directive|define
name|XK_Serbian_dje
value|0x6a1
end_define

begin_define
define|#
directive|define
name|XK_Macedonia_gje
value|0x6a2
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_io
value|0x6a3
end_define

begin_define
define|#
directive|define
name|XK_Ukrainian_ie
value|0x6a4
end_define

begin_define
define|#
directive|define
name|XK_Ukranian_je
value|0x6a4
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Macedonia_dse
value|0x6a5
end_define

begin_define
define|#
directive|define
name|XK_Ukrainian_i
value|0x6a6
end_define

begin_define
define|#
directive|define
name|XK_Ukranian_i
value|0x6a6
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Ukrainian_yi
value|0x6a7
end_define

begin_define
define|#
directive|define
name|XK_Ukranian_yi
value|0x6a7
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Cyrillic_je
value|0x6a8
end_define

begin_define
define|#
directive|define
name|XK_Serbian_je
value|0x6a8
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Cyrillic_lje
value|0x6a9
end_define

begin_define
define|#
directive|define
name|XK_Serbian_lje
value|0x6a9
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Cyrillic_nje
value|0x6aa
end_define

begin_define
define|#
directive|define
name|XK_Serbian_nje
value|0x6aa
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Serbian_tshe
value|0x6ab
end_define

begin_define
define|#
directive|define
name|XK_Macedonia_kje
value|0x6ac
end_define

begin_define
define|#
directive|define
name|XK_Byelorussian_shortu
value|0x6ae
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_dzhe
value|0x6af
end_define

begin_define
define|#
directive|define
name|XK_Serbian_dze
value|0x6af
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_numerosign
value|0x6b0
end_define

begin_define
define|#
directive|define
name|XK_Serbian_DJE
value|0x6b1
end_define

begin_define
define|#
directive|define
name|XK_Macedonia_GJE
value|0x6b2
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_IO
value|0x6b3
end_define

begin_define
define|#
directive|define
name|XK_Ukrainian_IE
value|0x6b4
end_define

begin_define
define|#
directive|define
name|XK_Ukranian_JE
value|0x6b4
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Macedonia_DSE
value|0x6b5
end_define

begin_define
define|#
directive|define
name|XK_Ukrainian_I
value|0x6b6
end_define

begin_define
define|#
directive|define
name|XK_Ukranian_I
value|0x6b6
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Ukrainian_YI
value|0x6b7
end_define

begin_define
define|#
directive|define
name|XK_Ukranian_YI
value|0x6b7
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Cyrillic_JE
value|0x6b8
end_define

begin_define
define|#
directive|define
name|XK_Serbian_JE
value|0x6b8
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Cyrillic_LJE
value|0x6b9
end_define

begin_define
define|#
directive|define
name|XK_Serbian_LJE
value|0x6b9
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Cyrillic_NJE
value|0x6ba
end_define

begin_define
define|#
directive|define
name|XK_Serbian_NJE
value|0x6ba
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Serbian_TSHE
value|0x6bb
end_define

begin_define
define|#
directive|define
name|XK_Macedonia_KJE
value|0x6bc
end_define

begin_define
define|#
directive|define
name|XK_Byelorussian_SHORTU
value|0x6be
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_DZHE
value|0x6bf
end_define

begin_define
define|#
directive|define
name|XK_Serbian_DZE
value|0x6bf
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Cyrillic_yu
value|0x6c0
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_a
value|0x6c1
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_be
value|0x6c2
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_tse
value|0x6c3
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_de
value|0x6c4
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ie
value|0x6c5
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ef
value|0x6c6
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ghe
value|0x6c7
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ha
value|0x6c8
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_i
value|0x6c9
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_shorti
value|0x6ca
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ka
value|0x6cb
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_el
value|0x6cc
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_em
value|0x6cd
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_en
value|0x6ce
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_o
value|0x6cf
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_pe
value|0x6d0
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ya
value|0x6d1
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_er
value|0x6d2
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_es
value|0x6d3
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_te
value|0x6d4
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_u
value|0x6d5
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_zhe
value|0x6d6
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ve
value|0x6d7
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_softsign
value|0x6d8
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_yeru
value|0x6d9
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ze
value|0x6da
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_sha
value|0x6db
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_e
value|0x6dc
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_shcha
value|0x6dd
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_che
value|0x6de
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_hardsign
value|0x6df
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_YU
value|0x6e0
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_A
value|0x6e1
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_BE
value|0x6e2
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_TSE
value|0x6e3
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_DE
value|0x6e4
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_IE
value|0x6e5
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_EF
value|0x6e6
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_GHE
value|0x6e7
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_HA
value|0x6e8
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_I
value|0x6e9
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_SHORTI
value|0x6ea
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_KA
value|0x6eb
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_EL
value|0x6ec
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_EM
value|0x6ed
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_EN
value|0x6ee
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_O
value|0x6ef
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_PE
value|0x6f0
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_YA
value|0x6f1
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ER
value|0x6f2
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ES
value|0x6f3
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_TE
value|0x6f4
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_U
value|0x6f5
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ZHE
value|0x6f6
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_VE
value|0x6f7
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_SOFTSIGN
value|0x6f8
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_YERU
value|0x6f9
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_ZE
value|0x6fa
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_SHA
value|0x6fb
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_E
value|0x6fc
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_SHCHA
value|0x6fd
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_CHE
value|0x6fe
end_define

begin_define
define|#
directive|define
name|XK_Cyrillic_HARDSIGN
value|0x6ff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_CYRILLIC */
end_comment

begin_comment
comment|/*  * Greek  * Byte 3 = 7  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_GREEK
end_ifdef

begin_define
define|#
directive|define
name|XK_Greek_ALPHAaccent
value|0x7a1
end_define

begin_define
define|#
directive|define
name|XK_Greek_EPSILONaccent
value|0x7a2
end_define

begin_define
define|#
directive|define
name|XK_Greek_ETAaccent
value|0x7a3
end_define

begin_define
define|#
directive|define
name|XK_Greek_IOTAaccent
value|0x7a4
end_define

begin_define
define|#
directive|define
name|XK_Greek_IOTAdiaeresis
value|0x7a5
end_define

begin_define
define|#
directive|define
name|XK_Greek_OMICRONaccent
value|0x7a7
end_define

begin_define
define|#
directive|define
name|XK_Greek_UPSILONaccent
value|0x7a8
end_define

begin_define
define|#
directive|define
name|XK_Greek_UPSILONdieresis
value|0x7a9
end_define

begin_define
define|#
directive|define
name|XK_Greek_OMEGAaccent
value|0x7ab
end_define

begin_define
define|#
directive|define
name|XK_Greek_accentdieresis
value|0x7ae
end_define

begin_define
define|#
directive|define
name|XK_Greek_horizbar
value|0x7af
end_define

begin_define
define|#
directive|define
name|XK_Greek_alphaaccent
value|0x7b1
end_define

begin_define
define|#
directive|define
name|XK_Greek_epsilonaccent
value|0x7b2
end_define

begin_define
define|#
directive|define
name|XK_Greek_etaaccent
value|0x7b3
end_define

begin_define
define|#
directive|define
name|XK_Greek_iotaaccent
value|0x7b4
end_define

begin_define
define|#
directive|define
name|XK_Greek_iotadieresis
value|0x7b5
end_define

begin_define
define|#
directive|define
name|XK_Greek_iotaaccentdieresis
value|0x7b6
end_define

begin_define
define|#
directive|define
name|XK_Greek_omicronaccent
value|0x7b7
end_define

begin_define
define|#
directive|define
name|XK_Greek_upsilonaccent
value|0x7b8
end_define

begin_define
define|#
directive|define
name|XK_Greek_upsilondieresis
value|0x7b9
end_define

begin_define
define|#
directive|define
name|XK_Greek_upsilonaccentdieresis
value|0x7ba
end_define

begin_define
define|#
directive|define
name|XK_Greek_omegaaccent
value|0x7bb
end_define

begin_define
define|#
directive|define
name|XK_Greek_ALPHA
value|0x7c1
end_define

begin_define
define|#
directive|define
name|XK_Greek_BETA
value|0x7c2
end_define

begin_define
define|#
directive|define
name|XK_Greek_GAMMA
value|0x7c3
end_define

begin_define
define|#
directive|define
name|XK_Greek_DELTA
value|0x7c4
end_define

begin_define
define|#
directive|define
name|XK_Greek_EPSILON
value|0x7c5
end_define

begin_define
define|#
directive|define
name|XK_Greek_ZETA
value|0x7c6
end_define

begin_define
define|#
directive|define
name|XK_Greek_ETA
value|0x7c7
end_define

begin_define
define|#
directive|define
name|XK_Greek_THETA
value|0x7c8
end_define

begin_define
define|#
directive|define
name|XK_Greek_IOTA
value|0x7c9
end_define

begin_define
define|#
directive|define
name|XK_Greek_KAPPA
value|0x7ca
end_define

begin_define
define|#
directive|define
name|XK_Greek_LAMDA
value|0x7cb
end_define

begin_define
define|#
directive|define
name|XK_Greek_LAMBDA
value|0x7cb
end_define

begin_define
define|#
directive|define
name|XK_Greek_MU
value|0x7cc
end_define

begin_define
define|#
directive|define
name|XK_Greek_NU
value|0x7cd
end_define

begin_define
define|#
directive|define
name|XK_Greek_XI
value|0x7ce
end_define

begin_define
define|#
directive|define
name|XK_Greek_OMICRON
value|0x7cf
end_define

begin_define
define|#
directive|define
name|XK_Greek_PI
value|0x7d0
end_define

begin_define
define|#
directive|define
name|XK_Greek_RHO
value|0x7d1
end_define

begin_define
define|#
directive|define
name|XK_Greek_SIGMA
value|0x7d2
end_define

begin_define
define|#
directive|define
name|XK_Greek_TAU
value|0x7d4
end_define

begin_define
define|#
directive|define
name|XK_Greek_UPSILON
value|0x7d5
end_define

begin_define
define|#
directive|define
name|XK_Greek_PHI
value|0x7d6
end_define

begin_define
define|#
directive|define
name|XK_Greek_CHI
value|0x7d7
end_define

begin_define
define|#
directive|define
name|XK_Greek_PSI
value|0x7d8
end_define

begin_define
define|#
directive|define
name|XK_Greek_OMEGA
value|0x7d9
end_define

begin_define
define|#
directive|define
name|XK_Greek_alpha
value|0x7e1
end_define

begin_define
define|#
directive|define
name|XK_Greek_beta
value|0x7e2
end_define

begin_define
define|#
directive|define
name|XK_Greek_gamma
value|0x7e3
end_define

begin_define
define|#
directive|define
name|XK_Greek_delta
value|0x7e4
end_define

begin_define
define|#
directive|define
name|XK_Greek_epsilon
value|0x7e5
end_define

begin_define
define|#
directive|define
name|XK_Greek_zeta
value|0x7e6
end_define

begin_define
define|#
directive|define
name|XK_Greek_eta
value|0x7e7
end_define

begin_define
define|#
directive|define
name|XK_Greek_theta
value|0x7e8
end_define

begin_define
define|#
directive|define
name|XK_Greek_iota
value|0x7e9
end_define

begin_define
define|#
directive|define
name|XK_Greek_kappa
value|0x7ea
end_define

begin_define
define|#
directive|define
name|XK_Greek_lamda
value|0x7eb
end_define

begin_define
define|#
directive|define
name|XK_Greek_lambda
value|0x7eb
end_define

begin_define
define|#
directive|define
name|XK_Greek_mu
value|0x7ec
end_define

begin_define
define|#
directive|define
name|XK_Greek_nu
value|0x7ed
end_define

begin_define
define|#
directive|define
name|XK_Greek_xi
value|0x7ee
end_define

begin_define
define|#
directive|define
name|XK_Greek_omicron
value|0x7ef
end_define

begin_define
define|#
directive|define
name|XK_Greek_pi
value|0x7f0
end_define

begin_define
define|#
directive|define
name|XK_Greek_rho
value|0x7f1
end_define

begin_define
define|#
directive|define
name|XK_Greek_sigma
value|0x7f2
end_define

begin_define
define|#
directive|define
name|XK_Greek_finalsmallsigma
value|0x7f3
end_define

begin_define
define|#
directive|define
name|XK_Greek_tau
value|0x7f4
end_define

begin_define
define|#
directive|define
name|XK_Greek_upsilon
value|0x7f5
end_define

begin_define
define|#
directive|define
name|XK_Greek_phi
value|0x7f6
end_define

begin_define
define|#
directive|define
name|XK_Greek_chi
value|0x7f7
end_define

begin_define
define|#
directive|define
name|XK_Greek_psi
value|0x7f8
end_define

begin_define
define|#
directive|define
name|XK_Greek_omega
value|0x7f9
end_define

begin_define
define|#
directive|define
name|XK_Greek_switch
value|0xFF7E
end_define

begin_comment
comment|/* Alias for mode_switch */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_GREEK */
end_comment

begin_comment
comment|/*  * Technical  * Byte 3 = 8  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_TECHNICAL
end_ifdef

begin_define
define|#
directive|define
name|XK_leftradical
value|0x8a1
end_define

begin_define
define|#
directive|define
name|XK_topleftradical
value|0x8a2
end_define

begin_define
define|#
directive|define
name|XK_horizconnector
value|0x8a3
end_define

begin_define
define|#
directive|define
name|XK_topintegral
value|0x8a4
end_define

begin_define
define|#
directive|define
name|XK_botintegral
value|0x8a5
end_define

begin_define
define|#
directive|define
name|XK_vertconnector
value|0x8a6
end_define

begin_define
define|#
directive|define
name|XK_topleftsqbracket
value|0x8a7
end_define

begin_define
define|#
directive|define
name|XK_botleftsqbracket
value|0x8a8
end_define

begin_define
define|#
directive|define
name|XK_toprightsqbracket
value|0x8a9
end_define

begin_define
define|#
directive|define
name|XK_botrightsqbracket
value|0x8aa
end_define

begin_define
define|#
directive|define
name|XK_topleftparens
value|0x8ab
end_define

begin_define
define|#
directive|define
name|XK_botleftparens
value|0x8ac
end_define

begin_define
define|#
directive|define
name|XK_toprightparens
value|0x8ad
end_define

begin_define
define|#
directive|define
name|XK_botrightparens
value|0x8ae
end_define

begin_define
define|#
directive|define
name|XK_leftmiddlecurlybrace
value|0x8af
end_define

begin_define
define|#
directive|define
name|XK_rightmiddlecurlybrace
value|0x8b0
end_define

begin_define
define|#
directive|define
name|XK_topleftsummation
value|0x8b1
end_define

begin_define
define|#
directive|define
name|XK_botleftsummation
value|0x8b2
end_define

begin_define
define|#
directive|define
name|XK_topvertsummationconnector
value|0x8b3
end_define

begin_define
define|#
directive|define
name|XK_botvertsummationconnector
value|0x8b4
end_define

begin_define
define|#
directive|define
name|XK_toprightsummation
value|0x8b5
end_define

begin_define
define|#
directive|define
name|XK_botrightsummation
value|0x8b6
end_define

begin_define
define|#
directive|define
name|XK_rightmiddlesummation
value|0x8b7
end_define

begin_define
define|#
directive|define
name|XK_lessthanequal
value|0x8bc
end_define

begin_define
define|#
directive|define
name|XK_notequal
value|0x8bd
end_define

begin_define
define|#
directive|define
name|XK_greaterthanequal
value|0x8be
end_define

begin_define
define|#
directive|define
name|XK_integral
value|0x8bf
end_define

begin_define
define|#
directive|define
name|XK_therefore
value|0x8c0
end_define

begin_define
define|#
directive|define
name|XK_variation
value|0x8c1
end_define

begin_define
define|#
directive|define
name|XK_infinity
value|0x8c2
end_define

begin_define
define|#
directive|define
name|XK_nabla
value|0x8c5
end_define

begin_define
define|#
directive|define
name|XK_approximate
value|0x8c8
end_define

begin_define
define|#
directive|define
name|XK_similarequal
value|0x8c9
end_define

begin_define
define|#
directive|define
name|XK_ifonlyif
value|0x8cd
end_define

begin_define
define|#
directive|define
name|XK_implies
value|0x8ce
end_define

begin_define
define|#
directive|define
name|XK_identical
value|0x8cf
end_define

begin_define
define|#
directive|define
name|XK_radical
value|0x8d6
end_define

begin_define
define|#
directive|define
name|XK_includedin
value|0x8da
end_define

begin_define
define|#
directive|define
name|XK_includes
value|0x8db
end_define

begin_define
define|#
directive|define
name|XK_intersection
value|0x8dc
end_define

begin_define
define|#
directive|define
name|XK_union
value|0x8dd
end_define

begin_define
define|#
directive|define
name|XK_logicaland
value|0x8de
end_define

begin_define
define|#
directive|define
name|XK_logicalor
value|0x8df
end_define

begin_define
define|#
directive|define
name|XK_partialderivative
value|0x8ef
end_define

begin_define
define|#
directive|define
name|XK_function
value|0x8f6
end_define

begin_define
define|#
directive|define
name|XK_leftarrow
value|0x8fb
end_define

begin_define
define|#
directive|define
name|XK_uparrow
value|0x8fc
end_define

begin_define
define|#
directive|define
name|XK_rightarrow
value|0x8fd
end_define

begin_define
define|#
directive|define
name|XK_downarrow
value|0x8fe
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_TECHNICAL */
end_comment

begin_comment
comment|/*  *  Special  *  Byte 3 = 9  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_SPECIAL
end_ifdef

begin_define
define|#
directive|define
name|XK_blank
value|0x9df
end_define

begin_define
define|#
directive|define
name|XK_soliddiamond
value|0x9e0
end_define

begin_define
define|#
directive|define
name|XK_checkerboard
value|0x9e1
end_define

begin_define
define|#
directive|define
name|XK_ht
value|0x9e2
end_define

begin_define
define|#
directive|define
name|XK_ff
value|0x9e3
end_define

begin_define
define|#
directive|define
name|XK_cr
value|0x9e4
end_define

begin_define
define|#
directive|define
name|XK_lf
value|0x9e5
end_define

begin_define
define|#
directive|define
name|XK_nl
value|0x9e8
end_define

begin_define
define|#
directive|define
name|XK_vt
value|0x9e9
end_define

begin_define
define|#
directive|define
name|XK_lowrightcorner
value|0x9ea
end_define

begin_define
define|#
directive|define
name|XK_uprightcorner
value|0x9eb
end_define

begin_define
define|#
directive|define
name|XK_upleftcorner
value|0x9ec
end_define

begin_define
define|#
directive|define
name|XK_lowleftcorner
value|0x9ed
end_define

begin_define
define|#
directive|define
name|XK_crossinglines
value|0x9ee
end_define

begin_define
define|#
directive|define
name|XK_horizlinescan1
value|0x9ef
end_define

begin_define
define|#
directive|define
name|XK_horizlinescan3
value|0x9f0
end_define

begin_define
define|#
directive|define
name|XK_horizlinescan5
value|0x9f1
end_define

begin_define
define|#
directive|define
name|XK_horizlinescan7
value|0x9f2
end_define

begin_define
define|#
directive|define
name|XK_horizlinescan9
value|0x9f3
end_define

begin_define
define|#
directive|define
name|XK_leftt
value|0x9f4
end_define

begin_define
define|#
directive|define
name|XK_rightt
value|0x9f5
end_define

begin_define
define|#
directive|define
name|XK_bott
value|0x9f6
end_define

begin_define
define|#
directive|define
name|XK_topt
value|0x9f7
end_define

begin_define
define|#
directive|define
name|XK_vertbar
value|0x9f8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_SPECIAL */
end_comment

begin_comment
comment|/*  *  Publishing  *  Byte 3 = a  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_PUBLISHING
end_ifdef

begin_define
define|#
directive|define
name|XK_emspace
value|0xaa1
end_define

begin_define
define|#
directive|define
name|XK_enspace
value|0xaa2
end_define

begin_define
define|#
directive|define
name|XK_em3space
value|0xaa3
end_define

begin_define
define|#
directive|define
name|XK_em4space
value|0xaa4
end_define

begin_define
define|#
directive|define
name|XK_digitspace
value|0xaa5
end_define

begin_define
define|#
directive|define
name|XK_punctspace
value|0xaa6
end_define

begin_define
define|#
directive|define
name|XK_thinspace
value|0xaa7
end_define

begin_define
define|#
directive|define
name|XK_hairspace
value|0xaa8
end_define

begin_define
define|#
directive|define
name|XK_emdash
value|0xaa9
end_define

begin_define
define|#
directive|define
name|XK_endash
value|0xaaa
end_define

begin_define
define|#
directive|define
name|XK_signifblank
value|0xaac
end_define

begin_define
define|#
directive|define
name|XK_ellipsis
value|0xaae
end_define

begin_define
define|#
directive|define
name|XK_doubbaselinedot
value|0xaaf
end_define

begin_define
define|#
directive|define
name|XK_onethird
value|0xab0
end_define

begin_define
define|#
directive|define
name|XK_twothirds
value|0xab1
end_define

begin_define
define|#
directive|define
name|XK_onefifth
value|0xab2
end_define

begin_define
define|#
directive|define
name|XK_twofifths
value|0xab3
end_define

begin_define
define|#
directive|define
name|XK_threefifths
value|0xab4
end_define

begin_define
define|#
directive|define
name|XK_fourfifths
value|0xab5
end_define

begin_define
define|#
directive|define
name|XK_onesixth
value|0xab6
end_define

begin_define
define|#
directive|define
name|XK_fivesixths
value|0xab7
end_define

begin_define
define|#
directive|define
name|XK_careof
value|0xab8
end_define

begin_define
define|#
directive|define
name|XK_figdash
value|0xabb
end_define

begin_define
define|#
directive|define
name|XK_leftanglebracket
value|0xabc
end_define

begin_define
define|#
directive|define
name|XK_decimalpoint
value|0xabd
end_define

begin_define
define|#
directive|define
name|XK_rightanglebracket
value|0xabe
end_define

begin_define
define|#
directive|define
name|XK_marker
value|0xabf
end_define

begin_define
define|#
directive|define
name|XK_oneeighth
value|0xac3
end_define

begin_define
define|#
directive|define
name|XK_threeeighths
value|0xac4
end_define

begin_define
define|#
directive|define
name|XK_fiveeighths
value|0xac5
end_define

begin_define
define|#
directive|define
name|XK_seveneighths
value|0xac6
end_define

begin_define
define|#
directive|define
name|XK_trademark
value|0xac9
end_define

begin_define
define|#
directive|define
name|XK_signaturemark
value|0xaca
end_define

begin_define
define|#
directive|define
name|XK_trademarkincircle
value|0xacb
end_define

begin_define
define|#
directive|define
name|XK_leftopentriangle
value|0xacc
end_define

begin_define
define|#
directive|define
name|XK_rightopentriangle
value|0xacd
end_define

begin_define
define|#
directive|define
name|XK_emopencircle
value|0xace
end_define

begin_define
define|#
directive|define
name|XK_emopenrectangle
value|0xacf
end_define

begin_define
define|#
directive|define
name|XK_leftsinglequotemark
value|0xad0
end_define

begin_define
define|#
directive|define
name|XK_rightsinglequotemark
value|0xad1
end_define

begin_define
define|#
directive|define
name|XK_leftdoublequotemark
value|0xad2
end_define

begin_define
define|#
directive|define
name|XK_rightdoublequotemark
value|0xad3
end_define

begin_define
define|#
directive|define
name|XK_prescription
value|0xad4
end_define

begin_define
define|#
directive|define
name|XK_minutes
value|0xad6
end_define

begin_define
define|#
directive|define
name|XK_seconds
value|0xad7
end_define

begin_define
define|#
directive|define
name|XK_latincross
value|0xad9
end_define

begin_define
define|#
directive|define
name|XK_hexagram
value|0xada
end_define

begin_define
define|#
directive|define
name|XK_filledrectbullet
value|0xadb
end_define

begin_define
define|#
directive|define
name|XK_filledlefttribullet
value|0xadc
end_define

begin_define
define|#
directive|define
name|XK_filledrighttribullet
value|0xadd
end_define

begin_define
define|#
directive|define
name|XK_emfilledcircle
value|0xade
end_define

begin_define
define|#
directive|define
name|XK_emfilledrect
value|0xadf
end_define

begin_define
define|#
directive|define
name|XK_enopencircbullet
value|0xae0
end_define

begin_define
define|#
directive|define
name|XK_enopensquarebullet
value|0xae1
end_define

begin_define
define|#
directive|define
name|XK_openrectbullet
value|0xae2
end_define

begin_define
define|#
directive|define
name|XK_opentribulletup
value|0xae3
end_define

begin_define
define|#
directive|define
name|XK_opentribulletdown
value|0xae4
end_define

begin_define
define|#
directive|define
name|XK_openstar
value|0xae5
end_define

begin_define
define|#
directive|define
name|XK_enfilledcircbullet
value|0xae6
end_define

begin_define
define|#
directive|define
name|XK_enfilledsqbullet
value|0xae7
end_define

begin_define
define|#
directive|define
name|XK_filledtribulletup
value|0xae8
end_define

begin_define
define|#
directive|define
name|XK_filledtribulletdown
value|0xae9
end_define

begin_define
define|#
directive|define
name|XK_leftpointer
value|0xaea
end_define

begin_define
define|#
directive|define
name|XK_rightpointer
value|0xaeb
end_define

begin_define
define|#
directive|define
name|XK_club
value|0xaec
end_define

begin_define
define|#
directive|define
name|XK_diamond
value|0xaed
end_define

begin_define
define|#
directive|define
name|XK_heart
value|0xaee
end_define

begin_define
define|#
directive|define
name|XK_maltesecross
value|0xaf0
end_define

begin_define
define|#
directive|define
name|XK_dagger
value|0xaf1
end_define

begin_define
define|#
directive|define
name|XK_doubledagger
value|0xaf2
end_define

begin_define
define|#
directive|define
name|XK_checkmark
value|0xaf3
end_define

begin_define
define|#
directive|define
name|XK_ballotcross
value|0xaf4
end_define

begin_define
define|#
directive|define
name|XK_musicalsharp
value|0xaf5
end_define

begin_define
define|#
directive|define
name|XK_musicalflat
value|0xaf6
end_define

begin_define
define|#
directive|define
name|XK_malesymbol
value|0xaf7
end_define

begin_define
define|#
directive|define
name|XK_femalesymbol
value|0xaf8
end_define

begin_define
define|#
directive|define
name|XK_telephone
value|0xaf9
end_define

begin_define
define|#
directive|define
name|XK_telephonerecorder
value|0xafa
end_define

begin_define
define|#
directive|define
name|XK_phonographcopyright
value|0xafb
end_define

begin_define
define|#
directive|define
name|XK_caret
value|0xafc
end_define

begin_define
define|#
directive|define
name|XK_singlelowquotemark
value|0xafd
end_define

begin_define
define|#
directive|define
name|XK_doublelowquotemark
value|0xafe
end_define

begin_define
define|#
directive|define
name|XK_cursor
value|0xaff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_PUBLISHING */
end_comment

begin_comment
comment|/*  *  APL  *  Byte 3 = b  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_APL
end_ifdef

begin_define
define|#
directive|define
name|XK_leftcaret
value|0xba3
end_define

begin_define
define|#
directive|define
name|XK_rightcaret
value|0xba6
end_define

begin_define
define|#
directive|define
name|XK_downcaret
value|0xba8
end_define

begin_define
define|#
directive|define
name|XK_upcaret
value|0xba9
end_define

begin_define
define|#
directive|define
name|XK_overbar
value|0xbc0
end_define

begin_define
define|#
directive|define
name|XK_downtack
value|0xbc2
end_define

begin_define
define|#
directive|define
name|XK_upshoe
value|0xbc3
end_define

begin_define
define|#
directive|define
name|XK_downstile
value|0xbc4
end_define

begin_define
define|#
directive|define
name|XK_underbar
value|0xbc6
end_define

begin_define
define|#
directive|define
name|XK_jot
value|0xbca
end_define

begin_define
define|#
directive|define
name|XK_quad
value|0xbcc
end_define

begin_define
define|#
directive|define
name|XK_uptack
value|0xbce
end_define

begin_define
define|#
directive|define
name|XK_circle
value|0xbcf
end_define

begin_define
define|#
directive|define
name|XK_upstile
value|0xbd3
end_define

begin_define
define|#
directive|define
name|XK_downshoe
value|0xbd6
end_define

begin_define
define|#
directive|define
name|XK_rightshoe
value|0xbd8
end_define

begin_define
define|#
directive|define
name|XK_leftshoe
value|0xbda
end_define

begin_define
define|#
directive|define
name|XK_lefttack
value|0xbdc
end_define

begin_define
define|#
directive|define
name|XK_righttack
value|0xbfc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_APL */
end_comment

begin_comment
comment|/*  * Hebrew  * Byte 3 = c  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XK_HEBREW
end_ifdef

begin_define
define|#
directive|define
name|XK_hebrew_doublelowline
value|0xcdf
end_define

begin_define
define|#
directive|define
name|XK_hebrew_aleph
value|0xce0
end_define

begin_define
define|#
directive|define
name|XK_hebrew_bet
value|0xce1
end_define

begin_define
define|#
directive|define
name|XK_hebrew_beth
value|0xce1
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_gimel
value|0xce2
end_define

begin_define
define|#
directive|define
name|XK_hebrew_gimmel
value|0xce2
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_dalet
value|0xce3
end_define

begin_define
define|#
directive|define
name|XK_hebrew_daleth
value|0xce3
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_he
value|0xce4
end_define

begin_define
define|#
directive|define
name|XK_hebrew_waw
value|0xce5
end_define

begin_define
define|#
directive|define
name|XK_hebrew_zain
value|0xce6
end_define

begin_define
define|#
directive|define
name|XK_hebrew_zayin
value|0xce6
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_chet
value|0xce7
end_define

begin_define
define|#
directive|define
name|XK_hebrew_het
value|0xce7
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_tet
value|0xce8
end_define

begin_define
define|#
directive|define
name|XK_hebrew_teth
value|0xce8
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_yod
value|0xce9
end_define

begin_define
define|#
directive|define
name|XK_hebrew_finalkaph
value|0xcea
end_define

begin_define
define|#
directive|define
name|XK_hebrew_kaph
value|0xceb
end_define

begin_define
define|#
directive|define
name|XK_hebrew_lamed
value|0xcec
end_define

begin_define
define|#
directive|define
name|XK_hebrew_finalmem
value|0xced
end_define

begin_define
define|#
directive|define
name|XK_hebrew_mem
value|0xcee
end_define

begin_define
define|#
directive|define
name|XK_hebrew_finalnun
value|0xcef
end_define

begin_define
define|#
directive|define
name|XK_hebrew_nun
value|0xcf0
end_define

begin_define
define|#
directive|define
name|XK_hebrew_samech
value|0xcf1
end_define

begin_define
define|#
directive|define
name|XK_hebrew_samekh
value|0xcf1
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_ayin
value|0xcf2
end_define

begin_define
define|#
directive|define
name|XK_hebrew_finalpe
value|0xcf3
end_define

begin_define
define|#
directive|define
name|XK_hebrew_pe
value|0xcf4
end_define

begin_define
define|#
directive|define
name|XK_hebrew_finalzade
value|0xcf5
end_define

begin_define
define|#
directive|define
name|XK_hebrew_finalzadi
value|0xcf5
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_zade
value|0xcf6
end_define

begin_define
define|#
directive|define
name|XK_hebrew_zadi
value|0xcf6
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_qoph
value|0xcf7
end_define

begin_define
define|#
directive|define
name|XK_hebrew_kuf
value|0xcf7
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_hebrew_resh
value|0xcf8
end_define

begin_define
define|#
directive|define
name|XK_hebrew_shin
value|0xcf9
end_define

begin_define
define|#
directive|define
name|XK_hebrew_taw
value|0xcfa
end_define

begin_define
define|#
directive|define
name|XK_hebrew_taf
value|0xcfa
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|XK_Hebrew_switch
value|0xFF7E
end_define

begin_comment
comment|/* Alias for mode_switch */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XK_HEBREW */
end_comment

end_unit

