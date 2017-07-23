begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * Copyright (c) 2015-2016 Vladimir Kondratyev<wulf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EVDEV_INPUT_EVENT_CODES_H
end_ifndef

begin_define
define|#
directive|define
name|_EVDEV_INPUT_EVENT_CODES_H
end_define

begin_comment
comment|/*  * Device properties and quirks  */
end_comment

begin_define
define|#
directive|define
name|INPUT_PROP_POINTER
value|0x00
end_define

begin_comment
comment|/* needs a pointer */
end_comment

begin_define
define|#
directive|define
name|INPUT_PROP_DIRECT
value|0x01
end_define

begin_comment
comment|/* direct input devices */
end_comment

begin_define
define|#
directive|define
name|INPUT_PROP_BUTTONPAD
value|0x02
end_define

begin_comment
comment|/* has button(s) under pad */
end_comment

begin_define
define|#
directive|define
name|INPUT_PROP_SEMI_MT
value|0x03
end_define

begin_comment
comment|/* touch rectangle only */
end_comment

begin_define
define|#
directive|define
name|INPUT_PROP_TOPBUTTONPAD
value|0x04
end_define

begin_comment
comment|/* softbuttons at top of pad */
end_comment

begin_define
define|#
directive|define
name|INPUT_PROP_POINTING_STICK
value|0x05
end_define

begin_comment
comment|/* is a pointing stick */
end_comment

begin_define
define|#
directive|define
name|INPUT_PROP_ACCELEROMETER
value|0x06
end_define

begin_comment
comment|/* has accelerometer */
end_comment

begin_define
define|#
directive|define
name|INPUT_PROP_MAX
value|0x1f
end_define

begin_define
define|#
directive|define
name|INPUT_PROP_CNT
value|(INPUT_PROP_MAX + 1)
end_define

begin_comment
comment|/*  * Event types  */
end_comment

begin_define
define|#
directive|define
name|EV_SYN
value|0x00
end_define

begin_define
define|#
directive|define
name|EV_KEY
value|0x01
end_define

begin_define
define|#
directive|define
name|EV_REL
value|0x02
end_define

begin_define
define|#
directive|define
name|EV_ABS
value|0x03
end_define

begin_define
define|#
directive|define
name|EV_MSC
value|0x04
end_define

begin_define
define|#
directive|define
name|EV_SW
value|0x05
end_define

begin_define
define|#
directive|define
name|EV_LED
value|0x11
end_define

begin_define
define|#
directive|define
name|EV_SND
value|0x12
end_define

begin_define
define|#
directive|define
name|EV_REP
value|0x14
end_define

begin_define
define|#
directive|define
name|EV_FF
value|0x15
end_define

begin_define
define|#
directive|define
name|EV_PWR
value|0x16
end_define

begin_define
define|#
directive|define
name|EV_FF_STATUS
value|0x17
end_define

begin_define
define|#
directive|define
name|EV_MAX
value|0x1f
end_define

begin_define
define|#
directive|define
name|EV_CNT
value|(EV_MAX+1)
end_define

begin_comment
comment|/*  * Synchronization events.  */
end_comment

begin_define
define|#
directive|define
name|SYN_REPORT
value|0
end_define

begin_define
define|#
directive|define
name|SYN_CONFIG
value|1
end_define

begin_define
define|#
directive|define
name|SYN_MT_REPORT
value|2
end_define

begin_define
define|#
directive|define
name|SYN_DROPPED
value|3
end_define

begin_define
define|#
directive|define
name|SYN_MAX
value|0xf
end_define

begin_define
define|#
directive|define
name|SYN_CNT
value|(SYN_MAX+1)
end_define

begin_comment
comment|/*  * Keys and buttons  */
end_comment

begin_comment
comment|/*  * Abbreviations in the comments:  * AC - Application Control  * AL - Application Launch Button  * SC - System Control  */
end_comment

begin_define
define|#
directive|define
name|KEY_RESERVED
value|0
end_define

begin_define
define|#
directive|define
name|KEY_ESC
value|1
end_define

begin_define
define|#
directive|define
name|KEY_1
value|2
end_define

begin_define
define|#
directive|define
name|KEY_2
value|3
end_define

begin_define
define|#
directive|define
name|KEY_3
value|4
end_define

begin_define
define|#
directive|define
name|KEY_4
value|5
end_define

begin_define
define|#
directive|define
name|KEY_5
value|6
end_define

begin_define
define|#
directive|define
name|KEY_6
value|7
end_define

begin_define
define|#
directive|define
name|KEY_7
value|8
end_define

begin_define
define|#
directive|define
name|KEY_8
value|9
end_define

begin_define
define|#
directive|define
name|KEY_9
value|10
end_define

begin_define
define|#
directive|define
name|KEY_0
value|11
end_define

begin_define
define|#
directive|define
name|KEY_MINUS
value|12
end_define

begin_define
define|#
directive|define
name|KEY_EQUAL
value|13
end_define

begin_define
define|#
directive|define
name|KEY_BACKSPACE
value|14
end_define

begin_define
define|#
directive|define
name|KEY_TAB
value|15
end_define

begin_define
define|#
directive|define
name|KEY_Q
value|16
end_define

begin_define
define|#
directive|define
name|KEY_W
value|17
end_define

begin_define
define|#
directive|define
name|KEY_E
value|18
end_define

begin_define
define|#
directive|define
name|KEY_R
value|19
end_define

begin_define
define|#
directive|define
name|KEY_T
value|20
end_define

begin_define
define|#
directive|define
name|KEY_Y
value|21
end_define

begin_define
define|#
directive|define
name|KEY_U
value|22
end_define

begin_define
define|#
directive|define
name|KEY_I
value|23
end_define

begin_define
define|#
directive|define
name|KEY_O
value|24
end_define

begin_define
define|#
directive|define
name|KEY_P
value|25
end_define

begin_define
define|#
directive|define
name|KEY_LEFTBRACE
value|26
end_define

begin_define
define|#
directive|define
name|KEY_RIGHTBRACE
value|27
end_define

begin_define
define|#
directive|define
name|KEY_ENTER
value|28
end_define

begin_define
define|#
directive|define
name|KEY_LEFTCTRL
value|29
end_define

begin_define
define|#
directive|define
name|KEY_A
value|30
end_define

begin_define
define|#
directive|define
name|KEY_S
value|31
end_define

begin_define
define|#
directive|define
name|KEY_D
value|32
end_define

begin_define
define|#
directive|define
name|KEY_F
value|33
end_define

begin_define
define|#
directive|define
name|KEY_G
value|34
end_define

begin_define
define|#
directive|define
name|KEY_H
value|35
end_define

begin_define
define|#
directive|define
name|KEY_J
value|36
end_define

begin_define
define|#
directive|define
name|KEY_K
value|37
end_define

begin_define
define|#
directive|define
name|KEY_L
value|38
end_define

begin_define
define|#
directive|define
name|KEY_SEMICOLON
value|39
end_define

begin_define
define|#
directive|define
name|KEY_APOSTROPHE
value|40
end_define

begin_define
define|#
directive|define
name|KEY_GRAVE
value|41
end_define

begin_define
define|#
directive|define
name|KEY_LEFTSHIFT
value|42
end_define

begin_define
define|#
directive|define
name|KEY_BACKSLASH
value|43
end_define

begin_define
define|#
directive|define
name|KEY_Z
value|44
end_define

begin_define
define|#
directive|define
name|KEY_X
value|45
end_define

begin_define
define|#
directive|define
name|KEY_C
value|46
end_define

begin_define
define|#
directive|define
name|KEY_V
value|47
end_define

begin_define
define|#
directive|define
name|KEY_B
value|48
end_define

begin_define
define|#
directive|define
name|KEY_N
value|49
end_define

begin_define
define|#
directive|define
name|KEY_M
value|50
end_define

begin_define
define|#
directive|define
name|KEY_COMMA
value|51
end_define

begin_define
define|#
directive|define
name|KEY_DOT
value|52
end_define

begin_define
define|#
directive|define
name|KEY_SLASH
value|53
end_define

begin_define
define|#
directive|define
name|KEY_RIGHTSHIFT
value|54
end_define

begin_define
define|#
directive|define
name|KEY_KPASTERISK
value|55
end_define

begin_define
define|#
directive|define
name|KEY_LEFTALT
value|56
end_define

begin_define
define|#
directive|define
name|KEY_SPACE
value|57
end_define

begin_define
define|#
directive|define
name|KEY_CAPSLOCK
value|58
end_define

begin_define
define|#
directive|define
name|KEY_F1
value|59
end_define

begin_define
define|#
directive|define
name|KEY_F2
value|60
end_define

begin_define
define|#
directive|define
name|KEY_F3
value|61
end_define

begin_define
define|#
directive|define
name|KEY_F4
value|62
end_define

begin_define
define|#
directive|define
name|KEY_F5
value|63
end_define

begin_define
define|#
directive|define
name|KEY_F6
value|64
end_define

begin_define
define|#
directive|define
name|KEY_F7
value|65
end_define

begin_define
define|#
directive|define
name|KEY_F8
value|66
end_define

begin_define
define|#
directive|define
name|KEY_F9
value|67
end_define

begin_define
define|#
directive|define
name|KEY_F10
value|68
end_define

begin_define
define|#
directive|define
name|KEY_NUMLOCK
value|69
end_define

begin_define
define|#
directive|define
name|KEY_SCROLLLOCK
value|70
end_define

begin_define
define|#
directive|define
name|KEY_KP7
value|71
end_define

begin_define
define|#
directive|define
name|KEY_KP8
value|72
end_define

begin_define
define|#
directive|define
name|KEY_KP9
value|73
end_define

begin_define
define|#
directive|define
name|KEY_KPMINUS
value|74
end_define

begin_define
define|#
directive|define
name|KEY_KP4
value|75
end_define

begin_define
define|#
directive|define
name|KEY_KP5
value|76
end_define

begin_define
define|#
directive|define
name|KEY_KP6
value|77
end_define

begin_define
define|#
directive|define
name|KEY_KPPLUS
value|78
end_define

begin_define
define|#
directive|define
name|KEY_KP1
value|79
end_define

begin_define
define|#
directive|define
name|KEY_KP2
value|80
end_define

begin_define
define|#
directive|define
name|KEY_KP3
value|81
end_define

begin_define
define|#
directive|define
name|KEY_KP0
value|82
end_define

begin_define
define|#
directive|define
name|KEY_KPDOT
value|83
end_define

begin_define
define|#
directive|define
name|KEY_ZENKAKUHANKAKU
value|85
end_define

begin_define
define|#
directive|define
name|KEY_102ND
value|86
end_define

begin_define
define|#
directive|define
name|KEY_F11
value|87
end_define

begin_define
define|#
directive|define
name|KEY_F12
value|88
end_define

begin_define
define|#
directive|define
name|KEY_RO
value|89
end_define

begin_define
define|#
directive|define
name|KEY_KATAKANA
value|90
end_define

begin_define
define|#
directive|define
name|KEY_HIRAGANA
value|91
end_define

begin_define
define|#
directive|define
name|KEY_HENKAN
value|92
end_define

begin_define
define|#
directive|define
name|KEY_KATAKANAHIRAGANA
value|93
end_define

begin_define
define|#
directive|define
name|KEY_MUHENKAN
value|94
end_define

begin_define
define|#
directive|define
name|KEY_KPJPCOMMA
value|95
end_define

begin_define
define|#
directive|define
name|KEY_KPENTER
value|96
end_define

begin_define
define|#
directive|define
name|KEY_RIGHTCTRL
value|97
end_define

begin_define
define|#
directive|define
name|KEY_KPSLASH
value|98
end_define

begin_define
define|#
directive|define
name|KEY_SYSRQ
value|99
end_define

begin_define
define|#
directive|define
name|KEY_RIGHTALT
value|100
end_define

begin_define
define|#
directive|define
name|KEY_LINEFEED
value|101
end_define

begin_define
define|#
directive|define
name|KEY_HOME
value|102
end_define

begin_define
define|#
directive|define
name|KEY_UP
value|103
end_define

begin_define
define|#
directive|define
name|KEY_PAGEUP
value|104
end_define

begin_define
define|#
directive|define
name|KEY_LEFT
value|105
end_define

begin_define
define|#
directive|define
name|KEY_RIGHT
value|106
end_define

begin_define
define|#
directive|define
name|KEY_END
value|107
end_define

begin_define
define|#
directive|define
name|KEY_DOWN
value|108
end_define

begin_define
define|#
directive|define
name|KEY_PAGEDOWN
value|109
end_define

begin_define
define|#
directive|define
name|KEY_INSERT
value|110
end_define

begin_define
define|#
directive|define
name|KEY_DELETE
value|111
end_define

begin_define
define|#
directive|define
name|KEY_MACRO
value|112
end_define

begin_define
define|#
directive|define
name|KEY_MUTE
value|113
end_define

begin_define
define|#
directive|define
name|KEY_VOLUMEDOWN
value|114
end_define

begin_define
define|#
directive|define
name|KEY_VOLUMEUP
value|115
end_define

begin_define
define|#
directive|define
name|KEY_POWER
value|116
end_define

begin_comment
comment|/* SC System Power Down */
end_comment

begin_define
define|#
directive|define
name|KEY_KPEQUAL
value|117
end_define

begin_define
define|#
directive|define
name|KEY_KPPLUSMINUS
value|118
end_define

begin_define
define|#
directive|define
name|KEY_PAUSE
value|119
end_define

begin_define
define|#
directive|define
name|KEY_SCALE
value|120
end_define

begin_comment
comment|/* AL Compiz Scale (Expose) */
end_comment

begin_define
define|#
directive|define
name|KEY_KPCOMMA
value|121
end_define

begin_define
define|#
directive|define
name|KEY_HANGEUL
value|122
end_define

begin_define
define|#
directive|define
name|KEY_HANGUEL
value|KEY_HANGEUL
end_define

begin_define
define|#
directive|define
name|KEY_HANJA
value|123
end_define

begin_define
define|#
directive|define
name|KEY_YEN
value|124
end_define

begin_define
define|#
directive|define
name|KEY_LEFTMETA
value|125
end_define

begin_define
define|#
directive|define
name|KEY_RIGHTMETA
value|126
end_define

begin_define
define|#
directive|define
name|KEY_COMPOSE
value|127
end_define

begin_define
define|#
directive|define
name|KEY_STOP
value|128
end_define

begin_comment
comment|/* AC Stop */
end_comment

begin_define
define|#
directive|define
name|KEY_AGAIN
value|129
end_define

begin_define
define|#
directive|define
name|KEY_PROPS
value|130
end_define

begin_comment
comment|/* AC Properties */
end_comment

begin_define
define|#
directive|define
name|KEY_UNDO
value|131
end_define

begin_comment
comment|/* AC Undo */
end_comment

begin_define
define|#
directive|define
name|KEY_FRONT
value|132
end_define

begin_define
define|#
directive|define
name|KEY_COPY
value|133
end_define

begin_comment
comment|/* AC Copy */
end_comment

begin_define
define|#
directive|define
name|KEY_OPEN
value|134
end_define

begin_comment
comment|/* AC Open */
end_comment

begin_define
define|#
directive|define
name|KEY_PASTE
value|135
end_define

begin_comment
comment|/* AC Paste */
end_comment

begin_define
define|#
directive|define
name|KEY_FIND
value|136
end_define

begin_comment
comment|/* AC Search */
end_comment

begin_define
define|#
directive|define
name|KEY_CUT
value|137
end_define

begin_comment
comment|/* AC Cut */
end_comment

begin_define
define|#
directive|define
name|KEY_HELP
value|138
end_define

begin_comment
comment|/* AL Integrated Help Center */
end_comment

begin_define
define|#
directive|define
name|KEY_MENU
value|139
end_define

begin_comment
comment|/* Menu (show menu) */
end_comment

begin_define
define|#
directive|define
name|KEY_CALC
value|140
end_define

begin_comment
comment|/* AL Calculator */
end_comment

begin_define
define|#
directive|define
name|KEY_SETUP
value|141
end_define

begin_define
define|#
directive|define
name|KEY_SLEEP
value|142
end_define

begin_comment
comment|/* SC System Sleep */
end_comment

begin_define
define|#
directive|define
name|KEY_WAKEUP
value|143
end_define

begin_comment
comment|/* System Wake Up */
end_comment

begin_define
define|#
directive|define
name|KEY_FILE
value|144
end_define

begin_comment
comment|/* AL Local Machine Browser */
end_comment

begin_define
define|#
directive|define
name|KEY_SENDFILE
value|145
end_define

begin_define
define|#
directive|define
name|KEY_DELETEFILE
value|146
end_define

begin_define
define|#
directive|define
name|KEY_XFER
value|147
end_define

begin_define
define|#
directive|define
name|KEY_PROG1
value|148
end_define

begin_define
define|#
directive|define
name|KEY_PROG2
value|149
end_define

begin_define
define|#
directive|define
name|KEY_WWW
value|150
end_define

begin_comment
comment|/* AL Internet Browser */
end_comment

begin_define
define|#
directive|define
name|KEY_MSDOS
value|151
end_define

begin_define
define|#
directive|define
name|KEY_COFFEE
value|152
end_define

begin_comment
comment|/* AL Terminal Lock/Screensaver */
end_comment

begin_define
define|#
directive|define
name|KEY_SCREENLOCK
value|KEY_COFFEE
end_define

begin_define
define|#
directive|define
name|KEY_ROTATE_DISPLAY
value|153
end_define

begin_comment
comment|/* Display orientation for e.g. tablets */
end_comment

begin_define
define|#
directive|define
name|KEY_DIRECTION
value|KEY_ROTATE_DISPLAY
end_define

begin_define
define|#
directive|define
name|KEY_CYCLEWINDOWS
value|154
end_define

begin_define
define|#
directive|define
name|KEY_MAIL
value|155
end_define

begin_define
define|#
directive|define
name|KEY_BOOKMARKS
value|156
end_define

begin_comment
comment|/* AC Bookmarks */
end_comment

begin_define
define|#
directive|define
name|KEY_COMPUTER
value|157
end_define

begin_define
define|#
directive|define
name|KEY_BACK
value|158
end_define

begin_comment
comment|/* AC Back */
end_comment

begin_define
define|#
directive|define
name|KEY_FORWARD
value|159
end_define

begin_comment
comment|/* AC Forward */
end_comment

begin_define
define|#
directive|define
name|KEY_CLOSECD
value|160
end_define

begin_define
define|#
directive|define
name|KEY_EJECTCD
value|161
end_define

begin_define
define|#
directive|define
name|KEY_EJECTCLOSECD
value|162
end_define

begin_define
define|#
directive|define
name|KEY_NEXTSONG
value|163
end_define

begin_define
define|#
directive|define
name|KEY_PLAYPAUSE
value|164
end_define

begin_define
define|#
directive|define
name|KEY_PREVIOUSSONG
value|165
end_define

begin_define
define|#
directive|define
name|KEY_STOPCD
value|166
end_define

begin_define
define|#
directive|define
name|KEY_RECORD
value|167
end_define

begin_define
define|#
directive|define
name|KEY_REWIND
value|168
end_define

begin_define
define|#
directive|define
name|KEY_PHONE
value|169
end_define

begin_comment
comment|/* Media Select Telephone */
end_comment

begin_define
define|#
directive|define
name|KEY_ISO
value|170
end_define

begin_define
define|#
directive|define
name|KEY_CONFIG
value|171
end_define

begin_comment
comment|/* AL Consumer Control Configuration */
end_comment

begin_define
define|#
directive|define
name|KEY_HOMEPAGE
value|172
end_define

begin_comment
comment|/* AC Home */
end_comment

begin_define
define|#
directive|define
name|KEY_REFRESH
value|173
end_define

begin_comment
comment|/* AC Refresh */
end_comment

begin_define
define|#
directive|define
name|KEY_EXIT
value|174
end_define

begin_comment
comment|/* AC Exit */
end_comment

begin_define
define|#
directive|define
name|KEY_MOVE
value|175
end_define

begin_define
define|#
directive|define
name|KEY_EDIT
value|176
end_define

begin_define
define|#
directive|define
name|KEY_SCROLLUP
value|177
end_define

begin_define
define|#
directive|define
name|KEY_SCROLLDOWN
value|178
end_define

begin_define
define|#
directive|define
name|KEY_KPLEFTPAREN
value|179
end_define

begin_define
define|#
directive|define
name|KEY_KPRIGHTPAREN
value|180
end_define

begin_define
define|#
directive|define
name|KEY_NEW
value|181
end_define

begin_comment
comment|/* AC New */
end_comment

begin_define
define|#
directive|define
name|KEY_REDO
value|182
end_define

begin_comment
comment|/* AC Redo/Repeat */
end_comment

begin_define
define|#
directive|define
name|KEY_F13
value|183
end_define

begin_define
define|#
directive|define
name|KEY_F14
value|184
end_define

begin_define
define|#
directive|define
name|KEY_F15
value|185
end_define

begin_define
define|#
directive|define
name|KEY_F16
value|186
end_define

begin_define
define|#
directive|define
name|KEY_F17
value|187
end_define

begin_define
define|#
directive|define
name|KEY_F18
value|188
end_define

begin_define
define|#
directive|define
name|KEY_F19
value|189
end_define

begin_define
define|#
directive|define
name|KEY_F20
value|190
end_define

begin_define
define|#
directive|define
name|KEY_F21
value|191
end_define

begin_define
define|#
directive|define
name|KEY_F22
value|192
end_define

begin_define
define|#
directive|define
name|KEY_F23
value|193
end_define

begin_define
define|#
directive|define
name|KEY_F24
value|194
end_define

begin_define
define|#
directive|define
name|KEY_PLAYCD
value|200
end_define

begin_define
define|#
directive|define
name|KEY_PAUSECD
value|201
end_define

begin_define
define|#
directive|define
name|KEY_PROG3
value|202
end_define

begin_define
define|#
directive|define
name|KEY_PROG4
value|203
end_define

begin_define
define|#
directive|define
name|KEY_DASHBOARD
value|204
end_define

begin_comment
comment|/* AL Dashboard */
end_comment

begin_define
define|#
directive|define
name|KEY_SUSPEND
value|205
end_define

begin_define
define|#
directive|define
name|KEY_CLOSE
value|206
end_define

begin_comment
comment|/* AC Close */
end_comment

begin_define
define|#
directive|define
name|KEY_PLAY
value|207
end_define

begin_define
define|#
directive|define
name|KEY_FASTFORWARD
value|208
end_define

begin_define
define|#
directive|define
name|KEY_BASSBOOST
value|209
end_define

begin_define
define|#
directive|define
name|KEY_PRINT
value|210
end_define

begin_comment
comment|/* AC Print */
end_comment

begin_define
define|#
directive|define
name|KEY_HP
value|211
end_define

begin_define
define|#
directive|define
name|KEY_CAMERA
value|212
end_define

begin_define
define|#
directive|define
name|KEY_SOUND
value|213
end_define

begin_define
define|#
directive|define
name|KEY_QUESTION
value|214
end_define

begin_define
define|#
directive|define
name|KEY_EMAIL
value|215
end_define

begin_define
define|#
directive|define
name|KEY_CHAT
value|216
end_define

begin_define
define|#
directive|define
name|KEY_SEARCH
value|217
end_define

begin_define
define|#
directive|define
name|KEY_CONNECT
value|218
end_define

begin_define
define|#
directive|define
name|KEY_FINANCE
value|219
end_define

begin_comment
comment|/* AL Checkbook/Finance */
end_comment

begin_define
define|#
directive|define
name|KEY_SPORT
value|220
end_define

begin_define
define|#
directive|define
name|KEY_SHOP
value|221
end_define

begin_define
define|#
directive|define
name|KEY_ALTERASE
value|222
end_define

begin_define
define|#
directive|define
name|KEY_CANCEL
value|223
end_define

begin_comment
comment|/* AC Cancel */
end_comment

begin_define
define|#
directive|define
name|KEY_BRIGHTNESSDOWN
value|224
end_define

begin_define
define|#
directive|define
name|KEY_BRIGHTNESSUP
value|225
end_define

begin_define
define|#
directive|define
name|KEY_MEDIA
value|226
end_define

begin_define
define|#
directive|define
name|KEY_SWITCHVIDEOMODE
value|227
end_define

begin_comment
comment|/* Cycle between available video 					   outputs (Monitor/LCD/TV-out/etc) */
end_comment

begin_define
define|#
directive|define
name|KEY_KBDILLUMTOGGLE
value|228
end_define

begin_define
define|#
directive|define
name|KEY_KBDILLUMDOWN
value|229
end_define

begin_define
define|#
directive|define
name|KEY_KBDILLUMUP
value|230
end_define

begin_define
define|#
directive|define
name|KEY_SEND
value|231
end_define

begin_comment
comment|/* AC Send */
end_comment

begin_define
define|#
directive|define
name|KEY_REPLY
value|232
end_define

begin_comment
comment|/* AC Reply */
end_comment

begin_define
define|#
directive|define
name|KEY_FORWARDMAIL
value|233
end_define

begin_comment
comment|/* AC Forward Msg */
end_comment

begin_define
define|#
directive|define
name|KEY_SAVE
value|234
end_define

begin_comment
comment|/* AC Save */
end_comment

begin_define
define|#
directive|define
name|KEY_DOCUMENTS
value|235
end_define

begin_define
define|#
directive|define
name|KEY_BATTERY
value|236
end_define

begin_define
define|#
directive|define
name|KEY_BLUETOOTH
value|237
end_define

begin_define
define|#
directive|define
name|KEY_WLAN
value|238
end_define

begin_define
define|#
directive|define
name|KEY_UWB
value|239
end_define

begin_define
define|#
directive|define
name|KEY_UNKNOWN
value|240
end_define

begin_define
define|#
directive|define
name|KEY_VIDEO_NEXT
value|241
end_define

begin_comment
comment|/* drive next video source */
end_comment

begin_define
define|#
directive|define
name|KEY_VIDEO_PREV
value|242
end_define

begin_comment
comment|/* drive previous video source */
end_comment

begin_define
define|#
directive|define
name|KEY_BRIGHTNESS_CYCLE
value|243
end_define

begin_comment
comment|/* brightness up, after max is min */
end_comment

begin_define
define|#
directive|define
name|KEY_BRIGHTNESS_AUTO
value|244
end_define

begin_comment
comment|/* Set Auto Brightness: manual 					  brightness control is off, 					  rely on ambient */
end_comment

begin_define
define|#
directive|define
name|KEY_BRIGHTNESS_ZERO
value|KEY_BRIGHTNESS_AUTO
end_define

begin_define
define|#
directive|define
name|KEY_DISPLAY_OFF
value|245
end_define

begin_comment
comment|/* display device to off state */
end_comment

begin_define
define|#
directive|define
name|KEY_WWAN
value|246
end_define

begin_comment
comment|/* Wireless WAN (LTE, UMTS, GSM, etc.) */
end_comment

begin_define
define|#
directive|define
name|KEY_WIMAX
value|KEY_WWAN
end_define

begin_define
define|#
directive|define
name|KEY_RFKILL
value|247
end_define

begin_comment
comment|/* Key that controls all radios */
end_comment

begin_define
define|#
directive|define
name|KEY_MICMUTE
value|248
end_define

begin_comment
comment|/* Mute / unmute the microphone */
end_comment

begin_comment
comment|/* Code 255 is reserved for special needs of AT keyboard driver */
end_comment

begin_define
define|#
directive|define
name|BTN_MISC
value|0x100
end_define

begin_define
define|#
directive|define
name|BTN_0
value|0x100
end_define

begin_define
define|#
directive|define
name|BTN_1
value|0x101
end_define

begin_define
define|#
directive|define
name|BTN_2
value|0x102
end_define

begin_define
define|#
directive|define
name|BTN_3
value|0x103
end_define

begin_define
define|#
directive|define
name|BTN_4
value|0x104
end_define

begin_define
define|#
directive|define
name|BTN_5
value|0x105
end_define

begin_define
define|#
directive|define
name|BTN_6
value|0x106
end_define

begin_define
define|#
directive|define
name|BTN_7
value|0x107
end_define

begin_define
define|#
directive|define
name|BTN_8
value|0x108
end_define

begin_define
define|#
directive|define
name|BTN_9
value|0x109
end_define

begin_define
define|#
directive|define
name|BTN_MOUSE
value|0x110
end_define

begin_define
define|#
directive|define
name|BTN_LEFT
value|0x110
end_define

begin_define
define|#
directive|define
name|BTN_RIGHT
value|0x111
end_define

begin_define
define|#
directive|define
name|BTN_MIDDLE
value|0x112
end_define

begin_define
define|#
directive|define
name|BTN_SIDE
value|0x113
end_define

begin_define
define|#
directive|define
name|BTN_EXTRA
value|0x114
end_define

begin_define
define|#
directive|define
name|BTN_FORWARD
value|0x115
end_define

begin_define
define|#
directive|define
name|BTN_BACK
value|0x116
end_define

begin_define
define|#
directive|define
name|BTN_TASK
value|0x117
end_define

begin_define
define|#
directive|define
name|BTN_JOYSTICK
value|0x120
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER
value|0x120
end_define

begin_define
define|#
directive|define
name|BTN_THUMB
value|0x121
end_define

begin_define
define|#
directive|define
name|BTN_THUMB2
value|0x122
end_define

begin_define
define|#
directive|define
name|BTN_TOP
value|0x123
end_define

begin_define
define|#
directive|define
name|BTN_TOP2
value|0x124
end_define

begin_define
define|#
directive|define
name|BTN_PINKIE
value|0x125
end_define

begin_define
define|#
directive|define
name|BTN_BASE
value|0x126
end_define

begin_define
define|#
directive|define
name|BTN_BASE2
value|0x127
end_define

begin_define
define|#
directive|define
name|BTN_BASE3
value|0x128
end_define

begin_define
define|#
directive|define
name|BTN_BASE4
value|0x129
end_define

begin_define
define|#
directive|define
name|BTN_BASE5
value|0x12a
end_define

begin_define
define|#
directive|define
name|BTN_BASE6
value|0x12b
end_define

begin_define
define|#
directive|define
name|BTN_DEAD
value|0x12f
end_define

begin_define
define|#
directive|define
name|BTN_GAMEPAD
value|0x130
end_define

begin_define
define|#
directive|define
name|BTN_SOUTH
value|0x130
end_define

begin_define
define|#
directive|define
name|BTN_A
value|BTN_SOUTH
end_define

begin_define
define|#
directive|define
name|BTN_EAST
value|0x131
end_define

begin_define
define|#
directive|define
name|BTN_B
value|BTN_EAST
end_define

begin_define
define|#
directive|define
name|BTN_C
value|0x132
end_define

begin_define
define|#
directive|define
name|BTN_NORTH
value|0x133
end_define

begin_define
define|#
directive|define
name|BTN_X
value|BTN_NORTH
end_define

begin_define
define|#
directive|define
name|BTN_WEST
value|0x134
end_define

begin_define
define|#
directive|define
name|BTN_Y
value|BTN_WEST
end_define

begin_define
define|#
directive|define
name|BTN_Z
value|0x135
end_define

begin_define
define|#
directive|define
name|BTN_TL
value|0x136
end_define

begin_define
define|#
directive|define
name|BTN_TR
value|0x137
end_define

begin_define
define|#
directive|define
name|BTN_TL2
value|0x138
end_define

begin_define
define|#
directive|define
name|BTN_TR2
value|0x139
end_define

begin_define
define|#
directive|define
name|BTN_SELECT
value|0x13a
end_define

begin_define
define|#
directive|define
name|BTN_START
value|0x13b
end_define

begin_define
define|#
directive|define
name|BTN_MODE
value|0x13c
end_define

begin_define
define|#
directive|define
name|BTN_THUMBL
value|0x13d
end_define

begin_define
define|#
directive|define
name|BTN_THUMBR
value|0x13e
end_define

begin_define
define|#
directive|define
name|BTN_DIGI
value|0x140
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_PEN
value|0x140
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_RUBBER
value|0x141
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_BRUSH
value|0x142
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_PENCIL
value|0x143
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_AIRBRUSH
value|0x144
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_FINGER
value|0x145
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_MOUSE
value|0x146
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_LENS
value|0x147
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_QUINTTAP
value|0x148
end_define

begin_comment
comment|/* Five fingers on trackpad */
end_comment

begin_define
define|#
directive|define
name|BTN_TOUCH
value|0x14a
end_define

begin_define
define|#
directive|define
name|BTN_STYLUS
value|0x14b
end_define

begin_define
define|#
directive|define
name|BTN_STYLUS2
value|0x14c
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_DOUBLETAP
value|0x14d
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_TRIPLETAP
value|0x14e
end_define

begin_define
define|#
directive|define
name|BTN_TOOL_QUADTAP
value|0x14f
end_define

begin_comment
comment|/* Four fingers on trackpad */
end_comment

begin_define
define|#
directive|define
name|BTN_WHEEL
value|0x150
end_define

begin_define
define|#
directive|define
name|BTN_GEAR_DOWN
value|0x150
end_define

begin_define
define|#
directive|define
name|BTN_GEAR_UP
value|0x151
end_define

begin_define
define|#
directive|define
name|KEY_OK
value|0x160
end_define

begin_define
define|#
directive|define
name|KEY_SELECT
value|0x161
end_define

begin_define
define|#
directive|define
name|KEY_GOTO
value|0x162
end_define

begin_define
define|#
directive|define
name|KEY_CLEAR
value|0x163
end_define

begin_define
define|#
directive|define
name|KEY_POWER2
value|0x164
end_define

begin_define
define|#
directive|define
name|KEY_OPTION
value|0x165
end_define

begin_define
define|#
directive|define
name|KEY_INFO
value|0x166
end_define

begin_comment
comment|/* AL OEM Features/Tips/Tutorial */
end_comment

begin_define
define|#
directive|define
name|KEY_TIME
value|0x167
end_define

begin_define
define|#
directive|define
name|KEY_VENDOR
value|0x168
end_define

begin_define
define|#
directive|define
name|KEY_ARCHIVE
value|0x169
end_define

begin_define
define|#
directive|define
name|KEY_PROGRAM
value|0x16a
end_define

begin_comment
comment|/* Media Select Program Guide */
end_comment

begin_define
define|#
directive|define
name|KEY_CHANNEL
value|0x16b
end_define

begin_define
define|#
directive|define
name|KEY_FAVORITES
value|0x16c
end_define

begin_define
define|#
directive|define
name|KEY_EPG
value|0x16d
end_define

begin_define
define|#
directive|define
name|KEY_PVR
value|0x16e
end_define

begin_comment
comment|/* Media Select Home */
end_comment

begin_define
define|#
directive|define
name|KEY_MHP
value|0x16f
end_define

begin_define
define|#
directive|define
name|KEY_LANGUAGE
value|0x170
end_define

begin_define
define|#
directive|define
name|KEY_TITLE
value|0x171
end_define

begin_define
define|#
directive|define
name|KEY_SUBTITLE
value|0x172
end_define

begin_define
define|#
directive|define
name|KEY_ANGLE
value|0x173
end_define

begin_define
define|#
directive|define
name|KEY_ZOOM
value|0x174
end_define

begin_define
define|#
directive|define
name|KEY_MODE
value|0x175
end_define

begin_define
define|#
directive|define
name|KEY_KEYBOARD
value|0x176
end_define

begin_define
define|#
directive|define
name|KEY_SCREEN
value|0x177
end_define

begin_define
define|#
directive|define
name|KEY_PC
value|0x178
end_define

begin_comment
comment|/* Media Select Computer */
end_comment

begin_define
define|#
directive|define
name|KEY_TV
value|0x179
end_define

begin_comment
comment|/* Media Select TV */
end_comment

begin_define
define|#
directive|define
name|KEY_TV2
value|0x17a
end_define

begin_comment
comment|/* Media Select Cable */
end_comment

begin_define
define|#
directive|define
name|KEY_VCR
value|0x17b
end_define

begin_comment
comment|/* Media Select VCR */
end_comment

begin_define
define|#
directive|define
name|KEY_VCR2
value|0x17c
end_define

begin_comment
comment|/* VCR Plus */
end_comment

begin_define
define|#
directive|define
name|KEY_SAT
value|0x17d
end_define

begin_comment
comment|/* Media Select Satellite */
end_comment

begin_define
define|#
directive|define
name|KEY_SAT2
value|0x17e
end_define

begin_define
define|#
directive|define
name|KEY_CD
value|0x17f
end_define

begin_comment
comment|/* Media Select CD */
end_comment

begin_define
define|#
directive|define
name|KEY_TAPE
value|0x180
end_define

begin_comment
comment|/* Media Select Tape */
end_comment

begin_define
define|#
directive|define
name|KEY_RADIO
value|0x181
end_define

begin_define
define|#
directive|define
name|KEY_TUNER
value|0x182
end_define

begin_comment
comment|/* Media Select Tuner */
end_comment

begin_define
define|#
directive|define
name|KEY_PLAYER
value|0x183
end_define

begin_define
define|#
directive|define
name|KEY_TEXT
value|0x184
end_define

begin_define
define|#
directive|define
name|KEY_DVD
value|0x185
end_define

begin_comment
comment|/* Media Select DVD */
end_comment

begin_define
define|#
directive|define
name|KEY_AUX
value|0x186
end_define

begin_define
define|#
directive|define
name|KEY_MP3
value|0x187
end_define

begin_define
define|#
directive|define
name|KEY_AUDIO
value|0x188
end_define

begin_comment
comment|/* AL Audio Browser */
end_comment

begin_define
define|#
directive|define
name|KEY_VIDEO
value|0x189
end_define

begin_comment
comment|/* AL Movie Browser */
end_comment

begin_define
define|#
directive|define
name|KEY_DIRECTORY
value|0x18a
end_define

begin_define
define|#
directive|define
name|KEY_LIST
value|0x18b
end_define

begin_define
define|#
directive|define
name|KEY_MEMO
value|0x18c
end_define

begin_comment
comment|/* Media Select Messages */
end_comment

begin_define
define|#
directive|define
name|KEY_CALENDAR
value|0x18d
end_define

begin_define
define|#
directive|define
name|KEY_RED
value|0x18e
end_define

begin_define
define|#
directive|define
name|KEY_GREEN
value|0x18f
end_define

begin_define
define|#
directive|define
name|KEY_YELLOW
value|0x190
end_define

begin_define
define|#
directive|define
name|KEY_BLUE
value|0x191
end_define

begin_define
define|#
directive|define
name|KEY_CHANNELUP
value|0x192
end_define

begin_comment
comment|/* Channel Increment */
end_comment

begin_define
define|#
directive|define
name|KEY_CHANNELDOWN
value|0x193
end_define

begin_comment
comment|/* Channel Decrement */
end_comment

begin_define
define|#
directive|define
name|KEY_FIRST
value|0x194
end_define

begin_define
define|#
directive|define
name|KEY_LAST
value|0x195
end_define

begin_comment
comment|/* Recall Last */
end_comment

begin_define
define|#
directive|define
name|KEY_AB
value|0x196
end_define

begin_define
define|#
directive|define
name|KEY_NEXT
value|0x197
end_define

begin_define
define|#
directive|define
name|KEY_RESTART
value|0x198
end_define

begin_define
define|#
directive|define
name|KEY_SLOW
value|0x199
end_define

begin_define
define|#
directive|define
name|KEY_SHUFFLE
value|0x19a
end_define

begin_define
define|#
directive|define
name|KEY_BREAK
value|0x19b
end_define

begin_define
define|#
directive|define
name|KEY_PREVIOUS
value|0x19c
end_define

begin_define
define|#
directive|define
name|KEY_DIGITS
value|0x19d
end_define

begin_define
define|#
directive|define
name|KEY_TEEN
value|0x19e
end_define

begin_define
define|#
directive|define
name|KEY_TWEN
value|0x19f
end_define

begin_define
define|#
directive|define
name|KEY_VIDEOPHONE
value|0x1a0
end_define

begin_comment
comment|/* Media Select Video Phone */
end_comment

begin_define
define|#
directive|define
name|KEY_GAMES
value|0x1a1
end_define

begin_comment
comment|/* Media Select Games */
end_comment

begin_define
define|#
directive|define
name|KEY_ZOOMIN
value|0x1a2
end_define

begin_comment
comment|/* AC Zoom In */
end_comment

begin_define
define|#
directive|define
name|KEY_ZOOMOUT
value|0x1a3
end_define

begin_comment
comment|/* AC Zoom Out */
end_comment

begin_define
define|#
directive|define
name|KEY_ZOOMRESET
value|0x1a4
end_define

begin_comment
comment|/* AC Zoom */
end_comment

begin_define
define|#
directive|define
name|KEY_WORDPROCESSOR
value|0x1a5
end_define

begin_comment
comment|/* AL Word Processor */
end_comment

begin_define
define|#
directive|define
name|KEY_EDITOR
value|0x1a6
end_define

begin_comment
comment|/* AL Text Editor */
end_comment

begin_define
define|#
directive|define
name|KEY_SPREADSHEET
value|0x1a7
end_define

begin_comment
comment|/* AL Spreadsheet */
end_comment

begin_define
define|#
directive|define
name|KEY_GRAPHICSEDITOR
value|0x1a8
end_define

begin_comment
comment|/* AL Graphics Editor */
end_comment

begin_define
define|#
directive|define
name|KEY_PRESENTATION
value|0x1a9
end_define

begin_comment
comment|/* AL Presentation App */
end_comment

begin_define
define|#
directive|define
name|KEY_DATABASE
value|0x1aa
end_define

begin_comment
comment|/* AL Database App */
end_comment

begin_define
define|#
directive|define
name|KEY_NEWS
value|0x1ab
end_define

begin_comment
comment|/* AL Newsreader */
end_comment

begin_define
define|#
directive|define
name|KEY_VOICEMAIL
value|0x1ac
end_define

begin_comment
comment|/* AL Voicemail */
end_comment

begin_define
define|#
directive|define
name|KEY_ADDRESSBOOK
value|0x1ad
end_define

begin_comment
comment|/* AL Contacts/Address Book */
end_comment

begin_define
define|#
directive|define
name|KEY_MESSENGER
value|0x1ae
end_define

begin_comment
comment|/* AL Instant Messaging */
end_comment

begin_define
define|#
directive|define
name|KEY_DISPLAYTOGGLE
value|0x1af
end_define

begin_comment
comment|/* Turn display (LCD) on and off */
end_comment

begin_define
define|#
directive|define
name|KEY_BRIGHTNESS_TOGGLE
value|KEY_DISPLAYTOGGLE
end_define

begin_define
define|#
directive|define
name|KEY_SPELLCHECK
value|0x1b0
end_define

begin_comment
comment|/* AL Spell Check */
end_comment

begin_define
define|#
directive|define
name|KEY_LOGOFF
value|0x1b1
end_define

begin_comment
comment|/* AL Logoff */
end_comment

begin_define
define|#
directive|define
name|KEY_DOLLAR
value|0x1b2
end_define

begin_define
define|#
directive|define
name|KEY_EURO
value|0x1b3
end_define

begin_define
define|#
directive|define
name|KEY_FRAMEBACK
value|0x1b4
end_define

begin_comment
comment|/* Consumer - transport controls */
end_comment

begin_define
define|#
directive|define
name|KEY_FRAMEFORWARD
value|0x1b5
end_define

begin_define
define|#
directive|define
name|KEY_CONTEXT_MENU
value|0x1b6
end_define

begin_comment
comment|/* GenDesc - system context menu */
end_comment

begin_define
define|#
directive|define
name|KEY_MEDIA_REPEAT
value|0x1b7
end_define

begin_comment
comment|/* Consumer - transport control */
end_comment

begin_define
define|#
directive|define
name|KEY_10CHANNELSUP
value|0x1b8
end_define

begin_comment
comment|/* 10 channels up (10+) */
end_comment

begin_define
define|#
directive|define
name|KEY_10CHANNELSDOWN
value|0x1b9
end_define

begin_comment
comment|/* 10 channels down (10-) */
end_comment

begin_define
define|#
directive|define
name|KEY_IMAGES
value|0x1ba
end_define

begin_comment
comment|/* AL Image Browser */
end_comment

begin_define
define|#
directive|define
name|KEY_DEL_EOL
value|0x1c0
end_define

begin_define
define|#
directive|define
name|KEY_DEL_EOS
value|0x1c1
end_define

begin_define
define|#
directive|define
name|KEY_INS_LINE
value|0x1c2
end_define

begin_define
define|#
directive|define
name|KEY_DEL_LINE
value|0x1c3
end_define

begin_define
define|#
directive|define
name|KEY_FN
value|0x1d0
end_define

begin_define
define|#
directive|define
name|KEY_FN_ESC
value|0x1d1
end_define

begin_define
define|#
directive|define
name|KEY_FN_F1
value|0x1d2
end_define

begin_define
define|#
directive|define
name|KEY_FN_F2
value|0x1d3
end_define

begin_define
define|#
directive|define
name|KEY_FN_F3
value|0x1d4
end_define

begin_define
define|#
directive|define
name|KEY_FN_F4
value|0x1d5
end_define

begin_define
define|#
directive|define
name|KEY_FN_F5
value|0x1d6
end_define

begin_define
define|#
directive|define
name|KEY_FN_F6
value|0x1d7
end_define

begin_define
define|#
directive|define
name|KEY_FN_F7
value|0x1d8
end_define

begin_define
define|#
directive|define
name|KEY_FN_F8
value|0x1d9
end_define

begin_define
define|#
directive|define
name|KEY_FN_F9
value|0x1da
end_define

begin_define
define|#
directive|define
name|KEY_FN_F10
value|0x1db
end_define

begin_define
define|#
directive|define
name|KEY_FN_F11
value|0x1dc
end_define

begin_define
define|#
directive|define
name|KEY_FN_F12
value|0x1dd
end_define

begin_define
define|#
directive|define
name|KEY_FN_1
value|0x1de
end_define

begin_define
define|#
directive|define
name|KEY_FN_2
value|0x1df
end_define

begin_define
define|#
directive|define
name|KEY_FN_D
value|0x1e0
end_define

begin_define
define|#
directive|define
name|KEY_FN_E
value|0x1e1
end_define

begin_define
define|#
directive|define
name|KEY_FN_F
value|0x1e2
end_define

begin_define
define|#
directive|define
name|KEY_FN_S
value|0x1e3
end_define

begin_define
define|#
directive|define
name|KEY_FN_B
value|0x1e4
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT1
value|0x1f1
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT2
value|0x1f2
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT3
value|0x1f3
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT4
value|0x1f4
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT5
value|0x1f5
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT6
value|0x1f6
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT7
value|0x1f7
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT8
value|0x1f8
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT9
value|0x1f9
end_define

begin_define
define|#
directive|define
name|KEY_BRL_DOT10
value|0x1fa
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_0
value|0x200
end_define

begin_comment
comment|/* used by phones, remote controls, */
end_comment

begin_define
define|#
directive|define
name|KEY_NUMERIC_1
value|0x201
end_define

begin_comment
comment|/* and other keypads */
end_comment

begin_define
define|#
directive|define
name|KEY_NUMERIC_2
value|0x202
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_3
value|0x203
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_4
value|0x204
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_5
value|0x205
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_6
value|0x206
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_7
value|0x207
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_8
value|0x208
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_9
value|0x209
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_STAR
value|0x20a
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_POUND
value|0x20b
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_A
value|0x20c
end_define

begin_comment
comment|/* Phone key A - HUT Telephony 0xb9 */
end_comment

begin_define
define|#
directive|define
name|KEY_NUMERIC_B
value|0x20d
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_C
value|0x20e
end_define

begin_define
define|#
directive|define
name|KEY_NUMERIC_D
value|0x20f
end_define

begin_define
define|#
directive|define
name|KEY_CAMERA_FOCUS
value|0x210
end_define

begin_define
define|#
directive|define
name|KEY_WPS_BUTTON
value|0x211
end_define

begin_comment
comment|/* WiFi Protected Setup key */
end_comment

begin_define
define|#
directive|define
name|KEY_TOUCHPAD_TOGGLE
value|0x212
end_define

begin_comment
comment|/* Request switch touchpad on or off */
end_comment

begin_define
define|#
directive|define
name|KEY_TOUCHPAD_ON
value|0x213
end_define

begin_define
define|#
directive|define
name|KEY_TOUCHPAD_OFF
value|0x214
end_define

begin_define
define|#
directive|define
name|KEY_CAMERA_ZOOMIN
value|0x215
end_define

begin_define
define|#
directive|define
name|KEY_CAMERA_ZOOMOUT
value|0x216
end_define

begin_define
define|#
directive|define
name|KEY_CAMERA_UP
value|0x217
end_define

begin_define
define|#
directive|define
name|KEY_CAMERA_DOWN
value|0x218
end_define

begin_define
define|#
directive|define
name|KEY_CAMERA_LEFT
value|0x219
end_define

begin_define
define|#
directive|define
name|KEY_CAMERA_RIGHT
value|0x21a
end_define

begin_define
define|#
directive|define
name|KEY_ATTENDANT_ON
value|0x21b
end_define

begin_define
define|#
directive|define
name|KEY_ATTENDANT_OFF
value|0x21c
end_define

begin_define
define|#
directive|define
name|KEY_ATTENDANT_TOGGLE
value|0x21d
end_define

begin_comment
comment|/* Attendant call on or off */
end_comment

begin_define
define|#
directive|define
name|KEY_LIGHTS_TOGGLE
value|0x21e
end_define

begin_comment
comment|/* Reading light on or off */
end_comment

begin_define
define|#
directive|define
name|BTN_DPAD_UP
value|0x220
end_define

begin_define
define|#
directive|define
name|BTN_DPAD_DOWN
value|0x221
end_define

begin_define
define|#
directive|define
name|BTN_DPAD_LEFT
value|0x222
end_define

begin_define
define|#
directive|define
name|BTN_DPAD_RIGHT
value|0x223
end_define

begin_define
define|#
directive|define
name|KEY_ALS_TOGGLE
value|0x230
end_define

begin_comment
comment|/* Ambient light sensor */
end_comment

begin_define
define|#
directive|define
name|KEY_BUTTONCONFIG
value|0x240
end_define

begin_comment
comment|/* AL Button Configuration */
end_comment

begin_define
define|#
directive|define
name|KEY_TASKMANAGER
value|0x241
end_define

begin_comment
comment|/* AL Task/Project Manager */
end_comment

begin_define
define|#
directive|define
name|KEY_JOURNAL
value|0x242
end_define

begin_comment
comment|/* AL Log/Journal/Timecard */
end_comment

begin_define
define|#
directive|define
name|KEY_CONTROLPANEL
value|0x243
end_define

begin_comment
comment|/* AL Control Panel */
end_comment

begin_define
define|#
directive|define
name|KEY_APPSELECT
value|0x244
end_define

begin_comment
comment|/* AL Select Task/Application */
end_comment

begin_define
define|#
directive|define
name|KEY_SCREENSAVER
value|0x245
end_define

begin_comment
comment|/* AL Screen Saver */
end_comment

begin_define
define|#
directive|define
name|KEY_VOICECOMMAND
value|0x246
end_define

begin_comment
comment|/* Listening Voice Command */
end_comment

begin_define
define|#
directive|define
name|KEY_BRIGHTNESS_MIN
value|0x250
end_define

begin_comment
comment|/* Set Brightness to Minimum */
end_comment

begin_define
define|#
directive|define
name|KEY_BRIGHTNESS_MAX
value|0x251
end_define

begin_comment
comment|/* Set Brightness to Maximum */
end_comment

begin_define
define|#
directive|define
name|KEY_KBDINPUTASSIST_PREV
value|0x260
end_define

begin_define
define|#
directive|define
name|KEY_KBDINPUTASSIST_NEXT
value|0x261
end_define

begin_define
define|#
directive|define
name|KEY_KBDINPUTASSIST_PREVGROUP
value|0x262
end_define

begin_define
define|#
directive|define
name|KEY_KBDINPUTASSIST_NEXTGROUP
value|0x263
end_define

begin_define
define|#
directive|define
name|KEY_KBDINPUTASSIST_ACCEPT
value|0x264
end_define

begin_define
define|#
directive|define
name|KEY_KBDINPUTASSIST_CANCEL
value|0x265
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY
value|0x2c0
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY1
value|0x2c0
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY2
value|0x2c1
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY3
value|0x2c2
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY4
value|0x2c3
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY5
value|0x2c4
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY6
value|0x2c5
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY7
value|0x2c6
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY8
value|0x2c7
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY9
value|0x2c8
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY10
value|0x2c9
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY11
value|0x2ca
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY12
value|0x2cb
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY13
value|0x2cc
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY14
value|0x2cd
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY15
value|0x2ce
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY16
value|0x2cf
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY17
value|0x2d0
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY18
value|0x2d1
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY19
value|0x2d2
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY20
value|0x2d3
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY21
value|0x2d4
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY22
value|0x2d5
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY23
value|0x2d6
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY24
value|0x2d7
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY25
value|0x2d8
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY26
value|0x2d9
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY27
value|0x2da
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY28
value|0x2db
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY29
value|0x2dc
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY30
value|0x2dd
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY31
value|0x2de
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY32
value|0x2df
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY33
value|0x2e0
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY34
value|0x2e1
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY35
value|0x2e2
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY36
value|0x2e3
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY37
value|0x2e4
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY38
value|0x2e5
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY39
value|0x2e6
end_define

begin_define
define|#
directive|define
name|BTN_TRIGGER_HAPPY40
value|0x2e7
end_define

begin_comment
comment|/* We avoid low common keys in module aliases so they don't get huge. */
end_comment

begin_define
define|#
directive|define
name|KEY_MIN_INTERESTING
value|KEY_MUTE
end_define

begin_define
define|#
directive|define
name|KEY_MAX
value|0x2ff
end_define

begin_define
define|#
directive|define
name|KEY_CNT
value|(KEY_MAX+1)
end_define

begin_comment
comment|/*  * Relative axes  */
end_comment

begin_define
define|#
directive|define
name|REL_X
value|0x00
end_define

begin_define
define|#
directive|define
name|REL_Y
value|0x01
end_define

begin_define
define|#
directive|define
name|REL_Z
value|0x02
end_define

begin_define
define|#
directive|define
name|REL_RX
value|0x03
end_define

begin_define
define|#
directive|define
name|REL_RY
value|0x04
end_define

begin_define
define|#
directive|define
name|REL_RZ
value|0x05
end_define

begin_define
define|#
directive|define
name|REL_HWHEEL
value|0x06
end_define

begin_define
define|#
directive|define
name|REL_DIAL
value|0x07
end_define

begin_define
define|#
directive|define
name|REL_WHEEL
value|0x08
end_define

begin_define
define|#
directive|define
name|REL_MISC
value|0x09
end_define

begin_define
define|#
directive|define
name|REL_MAX
value|0x0f
end_define

begin_define
define|#
directive|define
name|REL_CNT
value|(REL_MAX+1)
end_define

begin_comment
comment|/*  * Absolute axes  */
end_comment

begin_define
define|#
directive|define
name|ABS_X
value|0x00
end_define

begin_define
define|#
directive|define
name|ABS_Y
value|0x01
end_define

begin_define
define|#
directive|define
name|ABS_Z
value|0x02
end_define

begin_define
define|#
directive|define
name|ABS_RX
value|0x03
end_define

begin_define
define|#
directive|define
name|ABS_RY
value|0x04
end_define

begin_define
define|#
directive|define
name|ABS_RZ
value|0x05
end_define

begin_define
define|#
directive|define
name|ABS_THROTTLE
value|0x06
end_define

begin_define
define|#
directive|define
name|ABS_RUDDER
value|0x07
end_define

begin_define
define|#
directive|define
name|ABS_WHEEL
value|0x08
end_define

begin_define
define|#
directive|define
name|ABS_GAS
value|0x09
end_define

begin_define
define|#
directive|define
name|ABS_BRAKE
value|0x0a
end_define

begin_define
define|#
directive|define
name|ABS_HAT0X
value|0x10
end_define

begin_define
define|#
directive|define
name|ABS_HAT0Y
value|0x11
end_define

begin_define
define|#
directive|define
name|ABS_HAT1X
value|0x12
end_define

begin_define
define|#
directive|define
name|ABS_HAT1Y
value|0x13
end_define

begin_define
define|#
directive|define
name|ABS_HAT2X
value|0x14
end_define

begin_define
define|#
directive|define
name|ABS_HAT2Y
value|0x15
end_define

begin_define
define|#
directive|define
name|ABS_HAT3X
value|0x16
end_define

begin_define
define|#
directive|define
name|ABS_HAT3Y
value|0x17
end_define

begin_define
define|#
directive|define
name|ABS_PRESSURE
value|0x18
end_define

begin_define
define|#
directive|define
name|ABS_DISTANCE
value|0x19
end_define

begin_define
define|#
directive|define
name|ABS_TILT_X
value|0x1a
end_define

begin_define
define|#
directive|define
name|ABS_TILT_Y
value|0x1b
end_define

begin_define
define|#
directive|define
name|ABS_TOOL_WIDTH
value|0x1c
end_define

begin_define
define|#
directive|define
name|ABS_VOLUME
value|0x20
end_define

begin_define
define|#
directive|define
name|ABS_MISC
value|0x28
end_define

begin_define
define|#
directive|define
name|ABS_MT_SLOT
value|0x2f
end_define

begin_comment
comment|/* MT slot being modified */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_TOUCH_MAJOR
value|0x30
end_define

begin_comment
comment|/* Major axis of touching ellipse */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_TOUCH_MINOR
value|0x31
end_define

begin_comment
comment|/* Minor axis (omit if circular) */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_WIDTH_MAJOR
value|0x32
end_define

begin_comment
comment|/* Major axis of approaching ellipse */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_WIDTH_MINOR
value|0x33
end_define

begin_comment
comment|/* Minor axis (omit if circular) */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_ORIENTATION
value|0x34
end_define

begin_comment
comment|/* Ellipse orientation */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_POSITION_X
value|0x35
end_define

begin_comment
comment|/* Center X touch position */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_POSITION_Y
value|0x36
end_define

begin_comment
comment|/* Center Y touch position */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_TOOL_TYPE
value|0x37
end_define

begin_comment
comment|/* Type of touching device */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_BLOB_ID
value|0x38
end_define

begin_comment
comment|/* Group a set of packets as a blob */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_TRACKING_ID
value|0x39
end_define

begin_comment
comment|/* Unique ID of initiated contact */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_PRESSURE
value|0x3a
end_define

begin_comment
comment|/* Pressure on contact area */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_DISTANCE
value|0x3b
end_define

begin_comment
comment|/* Contact hover distance */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_TOOL_X
value|0x3c
end_define

begin_comment
comment|/* Center X tool position */
end_comment

begin_define
define|#
directive|define
name|ABS_MT_TOOL_Y
value|0x3d
end_define

begin_comment
comment|/* Center Y tool position */
end_comment

begin_define
define|#
directive|define
name|ABS_MAX
value|0x3f
end_define

begin_define
define|#
directive|define
name|ABS_CNT
value|(ABS_MAX+1)
end_define

begin_comment
comment|/*  * Switch events  */
end_comment

begin_define
define|#
directive|define
name|SW_LID
value|0x00
end_define

begin_comment
comment|/* set = lid shut */
end_comment

begin_define
define|#
directive|define
name|SW_TABLET_MODE
value|0x01
end_define

begin_comment
comment|/* set = tablet mode */
end_comment

begin_define
define|#
directive|define
name|SW_HEADPHONE_INSERT
value|0x02
end_define

begin_comment
comment|/* set = inserted */
end_comment

begin_define
define|#
directive|define
name|SW_RFKILL_ALL
value|0x03
end_define

begin_comment
comment|/* rfkill master switch, type "any" 					 set = radio enabled */
end_comment

begin_define
define|#
directive|define
name|SW_RADIO
value|SW_RFKILL_ALL
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|SW_MICROPHONE_INSERT
value|0x04
end_define

begin_comment
comment|/* set = inserted */
end_comment

begin_define
define|#
directive|define
name|SW_DOCK
value|0x05
end_define

begin_comment
comment|/* set = plugged into dock */
end_comment

begin_define
define|#
directive|define
name|SW_LINEOUT_INSERT
value|0x06
end_define

begin_comment
comment|/* set = inserted */
end_comment

begin_define
define|#
directive|define
name|SW_JACK_PHYSICAL_INSERT
value|0x07
end_define

begin_comment
comment|/* set = mechanical switch set */
end_comment

begin_define
define|#
directive|define
name|SW_VIDEOOUT_INSERT
value|0x08
end_define

begin_comment
comment|/* set = inserted */
end_comment

begin_define
define|#
directive|define
name|SW_CAMERA_LENS_COVER
value|0x09
end_define

begin_comment
comment|/* set = lens covered */
end_comment

begin_define
define|#
directive|define
name|SW_KEYPAD_SLIDE
value|0x0a
end_define

begin_comment
comment|/* set = keypad slide out */
end_comment

begin_define
define|#
directive|define
name|SW_FRONT_PROXIMITY
value|0x0b
end_define

begin_comment
comment|/* set = front proximity sensor active */
end_comment

begin_define
define|#
directive|define
name|SW_ROTATE_LOCK
value|0x0c
end_define

begin_comment
comment|/* set = rotate locked/disabled */
end_comment

begin_define
define|#
directive|define
name|SW_LINEIN_INSERT
value|0x0d
end_define

begin_comment
comment|/* set = inserted */
end_comment

begin_define
define|#
directive|define
name|SW_MUTE_DEVICE
value|0x0e
end_define

begin_comment
comment|/* set = device disabled */
end_comment

begin_define
define|#
directive|define
name|SW_MAX
value|0x0f
end_define

begin_define
define|#
directive|define
name|SW_CNT
value|(SW_MAX+1)
end_define

begin_comment
comment|/*  * Misc events  */
end_comment

begin_define
define|#
directive|define
name|MSC_SERIAL
value|0x00
end_define

begin_define
define|#
directive|define
name|MSC_PULSELED
value|0x01
end_define

begin_define
define|#
directive|define
name|MSC_GESTURE
value|0x02
end_define

begin_define
define|#
directive|define
name|MSC_RAW
value|0x03
end_define

begin_define
define|#
directive|define
name|MSC_SCAN
value|0x04
end_define

begin_define
define|#
directive|define
name|MSC_TIMESTAMP
value|0x05
end_define

begin_define
define|#
directive|define
name|MSC_MAX
value|0x07
end_define

begin_define
define|#
directive|define
name|MSC_CNT
value|(MSC_MAX+1)
end_define

begin_comment
comment|/*  * LEDs  */
end_comment

begin_define
define|#
directive|define
name|LED_NUML
value|0x00
end_define

begin_define
define|#
directive|define
name|LED_CAPSL
value|0x01
end_define

begin_define
define|#
directive|define
name|LED_SCROLLL
value|0x02
end_define

begin_define
define|#
directive|define
name|LED_COMPOSE
value|0x03
end_define

begin_define
define|#
directive|define
name|LED_KANA
value|0x04
end_define

begin_define
define|#
directive|define
name|LED_SLEEP
value|0x05
end_define

begin_define
define|#
directive|define
name|LED_SUSPEND
value|0x06
end_define

begin_define
define|#
directive|define
name|LED_MUTE
value|0x07
end_define

begin_define
define|#
directive|define
name|LED_MISC
value|0x08
end_define

begin_define
define|#
directive|define
name|LED_MAIL
value|0x09
end_define

begin_define
define|#
directive|define
name|LED_CHARGING
value|0x0a
end_define

begin_define
define|#
directive|define
name|LED_MAX
value|0x0f
end_define

begin_define
define|#
directive|define
name|LED_CNT
value|(LED_MAX+1)
end_define

begin_comment
comment|/*  * Autorepeat values  */
end_comment

begin_define
define|#
directive|define
name|REP_DELAY
value|0x00
end_define

begin_define
define|#
directive|define
name|REP_PERIOD
value|0x01
end_define

begin_define
define|#
directive|define
name|REP_MAX
value|0x01
end_define

begin_define
define|#
directive|define
name|REP_CNT
value|(REP_MAX+1)
end_define

begin_comment
comment|/*  * Sounds  */
end_comment

begin_define
define|#
directive|define
name|SND_CLICK
value|0x00
end_define

begin_define
define|#
directive|define
name|SND_BELL
value|0x01
end_define

begin_define
define|#
directive|define
name|SND_TONE
value|0x02
end_define

begin_define
define|#
directive|define
name|SND_MAX
value|0x07
end_define

begin_define
define|#
directive|define
name|SND_CNT
value|(SND_MAX+1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EVDEV_INPUT_EVENT_CODES_H */
end_comment

end_unit

