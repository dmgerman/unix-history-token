begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: omronKMap.c,v 1.1 91/06/29 13:48:59 xguest Exp $  *  * Copyright 1991 by OMRON Corporation  *   * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of OMRON not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  OMRON makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * OMRON DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL OMRON  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"sol.h"
end_include

begin_include
include|#
directive|include
file|"solKbd.h"
end_include

begin_define
define|#
directive|define
name|cT
value|(ControlMask)
end_define

begin_define
define|#
directive|define
name|sH
value|(ShiftMask)
end_define

begin_define
define|#
directive|define
name|lK
value|(LockMask)
end_define

begin_define
define|#
directive|define
name|mT
value|(Mod1Mask)
end_define

begin_decl_stmt
specifier|static
name|CARD8
name|solDefKeyModeMap
index|[
name|MAP_LENGTH
index|]
init|=
block|{
comment|/*  0   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f  */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|cT
block|,
literal|0
block|,
name|sH
block|,
name|sH
block|,
name|lK
block|,
name|mT
block|,
comment|/* 00-0f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 10-1f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 20-2f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 30-3f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 40-4f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 50-5f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 60-6f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 70-7f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 80-8f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 90-9f */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* a0-af */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* b0-bf */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* c0-cf */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* d0-df */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* e0-ef */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* f0-ff */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CARD8
modifier|*
name|solKeyModMap
index|[]
init|=
block|{
name|solDefKeyModeMap
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XK_henkan
value|XK_Kanji
end_define

begin_define
define|#
directive|define
name|XK_kakutei
value|XK_Execute
end_define

begin_decl_stmt
specifier|static
name|KeySym
name|solDefKeyMap
index|[]
init|=
block|{
comment|/*      NormalShift             ShiftedShift            */
name|XK_Tab
block|,
name|NoSymbol
block|,
comment|/* 0x9 -> min KeyCode */
name|XK_Control_L
block|,
name|NoSymbol
block|,
comment|/* 0xa */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xb -> kana Key */
name|XK_Shift_R
block|,
name|NoSymbol
block|,
comment|/* 0xc */
name|XK_Shift_L
block|,
name|NoSymbol
block|,
comment|/* 0xd */
name|XK_Caps_Lock
block|,
name|NoSymbol
block|,
comment|/* 0xe */
name|XK_Meta_L
block|,
name|NoSymbol
block|,
comment|/* 0xf -> zenmen Key */
name|XK_Escape
block|,
name|NoSymbol
block|,
comment|/* 0x10 */
name|XK_BackSpace
block|,
name|NoSymbol
block|,
comment|/* 0x11 */
name|XK_Return
block|,
name|NoSymbol
block|,
comment|/* 0x12 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x13 -> Nothing */
name|XK_space
block|,
name|NoSymbol
block|,
comment|/* 0x14 */
name|XK_Delete
block|,
name|NoSymbol
block|,
comment|/* 0x15 */
name|XK_henkan
block|,
name|NoSymbol
block|,
comment|/* 0x16 -> Henkan Key */
name|XK_kakutei
block|,
name|NoSymbol
block|,
comment|/* 0x17 -> Kakutei Key */
name|XK_F11
block|,
name|NoSymbol
block|,
comment|/* 0x18 */
name|XK_F12
block|,
name|NoSymbol
block|,
comment|/* 0x19 */
name|XK_F13
block|,
name|NoSymbol
block|,
comment|/* 0x1a */
name|XK_F14
block|,
name|NoSymbol
block|,
comment|/* 0x1b */
name|XK_Up
block|,
name|NoSymbol
block|,
comment|/* 0x1c */
name|XK_Left
block|,
name|NoSymbol
block|,
comment|/* 0x1d */
name|XK_Right
block|,
name|NoSymbol
block|,
comment|/* 0x1e */
name|XK_Down
block|,
name|NoSymbol
block|,
comment|/* 0x1f */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x20 -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x21 -> Nothing */
name|XK_1
block|,
name|XK_exclam
block|,
comment|/* 0x22 */
name|XK_2
block|,
name|XK_quotedbl
block|,
comment|/* 0x23 */
name|XK_3
block|,
name|XK_numbersign
block|,
comment|/* 0x24 */
name|XK_4
block|,
name|XK_dollar
block|,
comment|/* 0x25 */
name|XK_5
block|,
name|XK_percent
block|,
comment|/* 0x26 */
name|XK_6
block|,
name|XK_ampersand
block|,
comment|/* 0x27 */
name|XK_7
block|,
name|XK_quoteright
block|,
comment|/* 0x28 */
name|XK_8
block|,
name|XK_parenleft
block|,
comment|/* 0x29 */
name|XK_9
block|,
name|XK_parenright
block|,
comment|/* 0x2a */
name|XK_0
block|,
name|NoSymbol
block|,
comment|/* 0x2b */
name|XK_minus
block|,
name|XK_equal
block|,
comment|/* 0x2c */
name|XK_asciicircum
block|,
name|XK_asciitilde
block|,
comment|/* 0x2d */
name|XK_backslash
block|,
name|XK_bar
block|,
comment|/* 0x2e */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x2f -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x30 -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x31 -> Nothing */
name|XK_q
block|,
name|XK_Q
block|,
comment|/* 0x32 */
name|XK_w
block|,
name|XK_W
block|,
comment|/* 0x33 */
name|XK_e
block|,
name|XK_E
block|,
comment|/* 0x34 */
name|XK_r
block|,
name|XK_R
block|,
comment|/* 0x35 */
name|XK_t
block|,
name|XK_T
block|,
comment|/* 0x36 */
name|XK_y
block|,
name|XK_Y
block|,
comment|/* 0x37 */
name|XK_u
block|,
name|XK_U
block|,
comment|/* 0x38 */
name|XK_i
block|,
name|XK_I
block|,
comment|/* 0x39 */
name|XK_o
block|,
name|XK_O
block|,
comment|/* 0x3a */
name|XK_p
block|,
name|XK_P
block|,
comment|/* 0x3b */
name|XK_at
block|,
name|XK_quoteleft
block|,
comment|/* 0x3c */
name|XK_bracketleft
block|,
name|XK_braceleft
block|,
comment|/* 0x3d */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x3e -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x3f -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x40 -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x41 -> Nothing */
name|XK_a
block|,
name|XK_A
block|,
comment|/* 0x42 */
name|XK_s
block|,
name|XK_S
block|,
comment|/* 0x43 */
name|XK_d
block|,
name|XK_D
block|,
comment|/* 0x44 */
name|XK_f
block|,
name|XK_F
block|,
comment|/* 0x45 */
name|XK_g
block|,
name|XK_G
block|,
comment|/* 0x46 */
name|XK_h
block|,
name|XK_H
block|,
comment|/* 0x47 */
name|XK_j
block|,
name|XK_J
block|,
comment|/* 0x48 */
name|XK_k
block|,
name|XK_K
block|,
comment|/* 0x49 */
name|XK_l
block|,
name|XK_L
block|,
comment|/* 0x4a */
name|XK_semicolon
block|,
name|XK_plus
block|,
comment|/* 0x4b */
name|XK_colon
block|,
name|XK_asterisk
block|,
comment|/* 0x4c */
name|XK_bracketright
block|,
name|XK_braceright
block|,
comment|/* 0x4d */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x4e -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x4f -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x50 -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x51 -> Nothing */
name|XK_z
block|,
name|XK_Z
block|,
comment|/* 0x52 */
name|XK_x
block|,
name|XK_X
block|,
comment|/* 0x53 */
name|XK_c
block|,
name|XK_C
block|,
comment|/* 0x54 */
name|XK_v
block|,
name|XK_V
block|,
comment|/* 0x55 */
name|XK_b
block|,
name|XK_B
block|,
comment|/* 0x56 */
name|XK_n
block|,
name|XK_N
block|,
comment|/* 0x57 */
name|XK_m
block|,
name|XK_M
block|,
comment|/* 0x58 */
name|XK_comma
block|,
name|XK_less
block|,
comment|/* 0x59 */
name|XK_period
block|,
name|XK_greater
block|,
comment|/* 0x5a */
name|XK_slash
block|,
name|XK_question
block|,
comment|/* 0x5b */
name|NoSymbol
block|,
name|XK_underscore
block|,
comment|/* 0x5c */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x5d -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x5e -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x5f -> Nothing */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x60 -> Nothing */
name|XK_plus
block|,
name|NoSymbol
block|,
comment|/* 0x61 */
name|XK_minus
block|,
name|NoSymbol
block|,
comment|/* 0x62 */
name|XK_7
block|,
name|NoSymbol
block|,
comment|/* 0x63 */
name|XK_8
block|,
name|NoSymbol
block|,
comment|/* 0x64 */
name|XK_9
block|,
name|NoSymbol
block|,
comment|/* 0x65 */
name|XK_4
block|,
name|NoSymbol
block|,
comment|/* 0x66 */
name|XK_5
block|,
name|NoSymbol
block|,
comment|/* 0x67 */
name|XK_6
block|,
name|NoSymbol
block|,
comment|/* 0x68 */
name|XK_1
block|,
name|NoSymbol
block|,
comment|/* 0x69 */
name|XK_2
block|,
name|NoSymbol
block|,
comment|/* 0x6a */
name|XK_3
block|,
name|NoSymbol
block|,
comment|/* 0x6b */
name|XK_0
block|,
name|NoSymbol
block|,
comment|/* 0x6c */
name|XK_period
block|,
name|NoSymbol
block|,
comment|/* 0x6d */
name|XK_Return
block|,
name|NoSymbol
block|,
comment|/* 0x6e */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x6f */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x70 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x71 */
name|XK_F1
block|,
name|NoSymbol
block|,
comment|/* 0x72 */
name|XK_F2
block|,
name|NoSymbol
block|,
comment|/* 0x73 */
name|XK_F3
block|,
name|NoSymbol
block|,
comment|/* 0x74 */
name|XK_F4
block|,
name|NoSymbol
block|,
comment|/* 0x75 */
name|XK_F5
block|,
name|NoSymbol
block|,
comment|/* 0x76 */
name|XK_F6
block|,
name|NoSymbol
block|,
comment|/* 0x77 */
name|XK_F7
block|,
name|NoSymbol
block|,
comment|/* 0x78 */
name|XK_F8
block|,
name|NoSymbol
block|,
comment|/* 0x79 */
name|XK_F9
block|,
name|NoSymbol
block|,
comment|/* 0x7a */
name|XK_F10
block|,
name|NoSymbol
block|,
comment|/* 0x7b */
name|XK_asterisk
block|,
name|XK_asterisk
block|,
comment|/* 0x7c */
name|XK_slash
block|,
name|XK_slash
block|,
comment|/* 0x7d */
name|XK_equal
block|,
name|XK_equal
block|,
comment|/* 0x7e */
name|XK_comma
block|,
name|XK_comma
block|,
comment|/* 0x7f */
comment|/************************** Kana Code Table *****************************/
name|XK_Tab
block|,
name|NoSymbol
block|,
comment|/* 0x80 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x81 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x82 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x83 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x84 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x85 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x86 */
name|XK_Escape
block|,
name|NoSymbol
block|,
comment|/* 0x87 */
name|XK_BackSpace
block|,
name|NoSymbol
block|,
comment|/* 0x88 */
name|XK_Return
block|,
name|NoSymbol
block|,
comment|/* 0x89 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x8a */
name|XK_space
block|,
name|NoSymbol
block|,
comment|/* 0x8b */
name|XK_Delete
block|,
name|NoSymbol
block|,
comment|/* 0x8c */
name|XK_henkan
block|,
name|NoSymbol
block|,
comment|/* 0x8d */
comment|/* HENKAN */
name|XK_kakutei
block|,
name|NoSymbol
block|,
comment|/* 0x8e */
comment|/* KAKUTEI */
name|XK_F11
block|,
name|NoSymbol
block|,
comment|/* 0x8f */
name|XK_F12
block|,
name|NoSymbol
block|,
comment|/* 0x90 */
name|XK_F13
block|,
name|NoSymbol
block|,
comment|/* 0x91 */
name|XK_F14
block|,
name|NoSymbol
block|,
comment|/* 0x92 */
name|XK_Up
block|,
name|NoSymbol
block|,
comment|/* 0x93 */
name|XK_Left
block|,
name|NoSymbol
block|,
comment|/* 0x94 */
name|XK_Right
block|,
name|NoSymbol
block|,
comment|/* 0x95 */
name|XK_Down
block|,
name|NoSymbol
block|,
comment|/* 0x96 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x97 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0x98 */
name|XK_kana_NU
block|,
name|NoSymbol
block|,
comment|/* 0x99 */
name|XK_kana_HU
block|,
name|NoSymbol
block|,
comment|/* 0x9a */
name|XK_kana_A
block|,
name|XK_kana_a
block|,
comment|/* 0x9b */
name|XK_kana_U
block|,
name|XK_kana_u
block|,
comment|/* 0x9c */
name|XK_kana_E
block|,
name|XK_kana_e
block|,
comment|/* 0x9d */
name|XK_kana_O
block|,
name|XK_kana_o
block|,
comment|/* 0x9e */
name|XK_kana_YA
block|,
name|XK_kana_ya
block|,
comment|/* 0x9f */
name|XK_kana_YU
block|,
name|XK_kana_yu
block|,
comment|/* 0xa0 */
name|XK_kana_YO
block|,
name|XK_kana_yo
block|,
comment|/* 0xa1 */
name|XK_kana_WA
block|,
name|XK_kana_WO
block|,
comment|/* 0xa2 */
name|XK_kana_HO
block|,
name|NoSymbol
block|,
comment|/* 0xa3 */
name|XK_kana_HE
block|,
name|NoSymbol
block|,
comment|/* 0xa4 */
name|XK_prolongedsound
block|,
name|NoSymbol
block|,
comment|/* 0xa5 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xa6 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xa7 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xa8 */
name|XK_kana_TA
block|,
name|NoSymbol
block|,
comment|/* 0xa9 */
name|XK_kana_TE
block|,
name|NoSymbol
block|,
comment|/* 0xaa */
name|XK_kana_I
block|,
name|XK_kana_i
block|,
comment|/* 0xab */
name|XK_kana_SU
block|,
name|NoSymbol
block|,
comment|/* 0xac */
name|XK_kana_KA
block|,
name|NoSymbol
block|,
comment|/* 0xad */
name|XK_kana_N
block|,
name|NoSymbol
block|,
comment|/* 0xae */
name|XK_kana_NA
block|,
name|NoSymbol
block|,
comment|/* 0xaf */
name|XK_kana_NI
block|,
name|NoSymbol
block|,
comment|/* 0xb0 */
name|XK_kana_RA
block|,
name|NoSymbol
block|,
comment|/* 0xb1 */
name|XK_kana_SE
block|,
name|NoSymbol
block|,
comment|/* 0xb2 */
name|XK_voicedsound
block|,
name|NoSymbol
block|,
comment|/* 0xb3 */
name|XK_semivoicedsound
block|,
name|XK_kana_openingbracket
block|,
comment|/* 0xb4 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xb5 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xb6 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xb7 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xb8 */
name|XK_kana_TI
block|,
name|NoSymbol
block|,
comment|/* 0xb9 */
name|XK_kana_TO
block|,
name|NoSymbol
block|,
comment|/* 0xba */
name|XK_kana_SHI
block|,
name|NoSymbol
block|,
comment|/* 0xbb */
name|XK_kana_HA
block|,
name|NoSymbol
block|,
comment|/* 0xbc */
name|XK_kana_KI
block|,
name|NoSymbol
block|,
comment|/* 0xbd */
name|XK_kana_KU
block|,
name|NoSymbol
block|,
comment|/* 0xbe */
name|XK_kana_MA
block|,
name|NoSymbol
block|,
comment|/* 0xbf */
name|XK_kana_NO
block|,
name|NoSymbol
block|,
comment|/* 0xc0 */
name|XK_kana_RI
block|,
name|NoSymbol
block|,
comment|/* 0xc1 */
name|XK_kana_RE
block|,
name|NoSymbol
block|,
comment|/* 0xc2 */
name|XK_kana_KE
block|,
name|NoSymbol
block|,
comment|/* 0xc3 */
name|XK_kana_MU
block|,
name|XK_kana_closingbracket
block|,
comment|/* 0xc4 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xc5 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xc6 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xc7 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xc8 */
name|XK_kana_TU
block|,
name|XK_kana_tu
block|,
comment|/* 0xc9 */
name|XK_kana_SA
block|,
name|NoSymbol
block|,
comment|/* 0xca */
name|XK_kana_SO
block|,
name|NoSymbol
block|,
comment|/* 0xcb */
name|XK_kana_HI
block|,
name|NoSymbol
block|,
comment|/* 0xcc */
name|XK_kana_KO
block|,
name|NoSymbol
block|,
comment|/* 0xcd */
name|XK_kana_MI
block|,
name|NoSymbol
block|,
comment|/* 0xce */
name|XK_kana_MO
block|,
name|NoSymbol
block|,
comment|/* 0xcf */
name|XK_kana_NE
block|,
name|XK_kana_comma
block|,
comment|/* 0xd0 */
name|XK_kana_RU
block|,
name|XK_kana_fullstop
block|,
comment|/* 0xd1 */
name|XK_kana_ME
block|,
name|XK_kana_middledot
block|,
comment|/* 0xd2 */
name|XK_kana_RO
block|,
name|NoSymbol
block|,
comment|/* 0xd3 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xd4 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xd5 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xd6 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xd7 */
name|XK_plus
block|,
name|NoSymbol
block|,
comment|/* 0xd8 */
name|XK_minus
block|,
name|NoSymbol
block|,
comment|/* 0xd9 */
name|XK_7
block|,
name|NoSymbol
block|,
comment|/* 0xda */
name|XK_8
block|,
name|NoSymbol
block|,
comment|/* 0xdb */
name|XK_9
block|,
name|NoSymbol
block|,
comment|/* 0xdc */
name|XK_4
block|,
name|NoSymbol
block|,
comment|/* 0xdd */
name|XK_5
block|,
name|NoSymbol
block|,
comment|/* 0xde */
name|XK_6
block|,
name|NoSymbol
block|,
comment|/* 0xdf */
name|XK_1
block|,
name|NoSymbol
block|,
comment|/* 0xe0 */
name|XK_2
block|,
name|NoSymbol
block|,
comment|/* 0xe1 */
name|XK_3
block|,
name|NoSymbol
block|,
comment|/* 0xe2 */
name|XK_0
block|,
name|NoSymbol
block|,
comment|/* 0xe3 */
name|XK_period
block|,
name|NoSymbol
block|,
comment|/* 0xe4 */
name|XK_Return
block|,
name|NoSymbol
block|,
comment|/* 0xe5 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xe6 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xe7 */
name|NoSymbol
block|,
name|NoSymbol
block|,
comment|/* 0xe8 */
name|XK_F1
block|,
name|NoSymbol
block|,
comment|/* 0xe9 */
name|XK_F2
block|,
name|NoSymbol
block|,
comment|/* 0xea */
name|XK_F3
block|,
name|NoSymbol
block|,
comment|/* 0xeb */
name|XK_F4
block|,
name|NoSymbol
block|,
comment|/* 0xec */
name|XK_F5
block|,
name|NoSymbol
block|,
comment|/* 0xed */
name|XK_F6
block|,
name|NoSymbol
block|,
comment|/* 0xee */
name|XK_F7
block|,
name|NoSymbol
block|,
comment|/* 0xef */
name|XK_F8
block|,
name|NoSymbol
block|,
comment|/* 0xf0 */
name|XK_F9
block|,
name|NoSymbol
block|,
comment|/* 0xf1 */
name|XK_F10
block|,
name|NoSymbol
block|,
comment|/* 0xf2 */
name|XK_asterisk
block|,
name|XK_asterisk
block|,
comment|/* 0xf3 */
name|XK_slash
block|,
name|XK_slash
block|,
comment|/* 0xf4 */
name|XK_equal
block|,
name|XK_equal
block|,
comment|/* 0xf5 */
name|XK_comma
block|,
name|XK_comma
block|,
comment|/* 0xf6  -> maxKeyCode */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KeySymsRec
name|solKeySyms
index|[]
init|=
block|{
comment|/*  map          minKeyCode   maxKeyCode  width */
name|solDefKeyMap
block|,
literal|0x9
block|,
literal|0xf6
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|solDefAutoRepeats
index|[
name|AREPBUFSZ
index|]
init|=
block|{
literal|0x00
block|,
literal|0x02
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x81
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x7f
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|solAutoRepeats
index|[]
init|=
block|{
name|solDefAutoRepeats
block|}
decl_stmt|;
end_decl_stmt

end_unit

