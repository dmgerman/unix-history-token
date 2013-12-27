begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * kbd.c  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: kbd.c,v 1.4 2006/09/07 21:06:53 max Exp $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/consio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<bluetooth.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbhid.h>
end_include

begin_include
include|#
directive|include
file|<dev/vkbd/vkbd_var.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<usbhid.h>
end_include

begin_include
include|#
directive|include
file|"bthid_config.h"
end_include

begin_include
include|#
directive|include
file|"bthidd.h"
end_include

begin_include
include|#
directive|include
file|"kbd.h"
end_include

begin_function_decl
specifier|static
name|void
name|kbd_write
parameter_list|(
name|bitstr_t
modifier|*
name|m
parameter_list|,
name|int32_t
name|fb
parameter_list|,
name|int32_t
name|make
parameter_list|,
name|int32_t
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int32_t
name|kbd_xlate
parameter_list|(
name|int32_t
name|code
parameter_list|,
name|int32_t
name|make
parameter_list|,
name|int32_t
modifier|*
name|b
parameter_list|,
name|int32_t
specifier|const
modifier|*
name|eob
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * HID code to PS/2 set 1 code translation table.  *  * http://www.microsoft.com/whdc/device/input/Scancode.mspx  *  * The table only contains "make" (key pressed) codes.  * The "break" (key released) code is generated as "make" | 0x80  */
end_comment

begin_define
define|#
directive|define
name|E0PREFIX
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|NOBREAK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|CODEMASK
value|(~(E0PREFIX|NOBREAK))
end_define

begin_decl_stmt
specifier|static
name|int32_t
specifier|const
name|x
index|[]
init|=
block|{
comment|/*==================================================*/
comment|/* Name                   HID code    Make     Break*/
comment|/*==================================================*/
comment|/* No Event                     00 */
operator|-
literal|1
block|,
comment|/* None */
comment|/* Overrun Error                01 */
name|NOBREAK
operator||
literal|0xFF
block|,
comment|/* None */
comment|/* POST Fail                    02 */
name|NOBREAK
operator||
literal|0xFC
block|,
comment|/* None */
comment|/* ErrorUndefined               03 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* a A                          04 */
literal|0x1E
block|,
comment|/* 9E */
comment|/* b B                          05 */
literal|0x30
block|,
comment|/* B0 */
comment|/* c C                          06 */
literal|0x2E
block|,
comment|/* AE */
comment|/* d D                          07 */
literal|0x20
block|,
comment|/* A0 */
comment|/* e E                          08 */
literal|0x12
block|,
comment|/* 92 */
comment|/* f F                          09 */
literal|0x21
block|,
comment|/* A1 */
comment|/* g G                          0A */
literal|0x22
block|,
comment|/* A2 */
comment|/* h H                          0B */
literal|0x23
block|,
comment|/* A3 */
comment|/* i I                          0C */
literal|0x17
block|,
comment|/* 97 */
comment|/* j J                          0D */
literal|0x24
block|,
comment|/* A4 */
comment|/* k K                          0E */
literal|0x25
block|,
comment|/* A5 */
comment|/* l L                          0F */
literal|0x26
block|,
comment|/* A6 */
comment|/* m M                          10 */
literal|0x32
block|,
comment|/* B2 */
comment|/* n N                          11 */
literal|0x31
block|,
comment|/* B1 */
comment|/* o O                          12 */
literal|0x18
block|,
comment|/* 98 */
comment|/* p P                          13 */
literal|0x19
block|,
comment|/* 99 */
comment|/* q Q                          14 */
literal|0x10
block|,
comment|/* 90 */
comment|/* r R                          15 */
literal|0x13
block|,
comment|/* 93 */
comment|/* s S                          16 */
literal|0x1F
block|,
comment|/* 9F */
comment|/* t T                          17 */
literal|0x14
block|,
comment|/* 94 */
comment|/* u U                          18 */
literal|0x16
block|,
comment|/* 96 */
comment|/* v V                          19 */
literal|0x2F
block|,
comment|/* AF */
comment|/* w W                          1A */
literal|0x11
block|,
comment|/* 91 */
comment|/* x X                          1B */
literal|0x2D
block|,
comment|/* AD */
comment|/* y Y                          1C */
literal|0x15
block|,
comment|/* 95 */
comment|/* z Z                          1D */
literal|0x2C
block|,
comment|/* AC */
comment|/* 1 !                          1E */
literal|0x02
block|,
comment|/* 82 */
comment|/* 2 @                          1F */
literal|0x03
block|,
comment|/* 83 */
comment|/* 3 #                          20 */
literal|0x04
block|,
comment|/* 84 */
comment|/* 4 $                          21 */
literal|0x05
block|,
comment|/* 85 */
comment|/* 5 %                          22 */
literal|0x06
block|,
comment|/* 86 */
comment|/* 6 ^                          23 */
literal|0x07
block|,
comment|/* 87 */
comment|/* 7&                          24 */
literal|0x08
block|,
comment|/* 88 */
comment|/* 8 *                          25 */
literal|0x09
block|,
comment|/* 89 */
comment|/* 9 (                          26 */
literal|0x0A
block|,
comment|/* 8A */
comment|/* 0 )                          27 */
literal|0x0B
block|,
comment|/* 8B */
comment|/* Return                       28 */
literal|0x1C
block|,
comment|/* 9C */
comment|/* Escape                       29 */
literal|0x01
block|,
comment|/* 81 */
comment|/* Backspace                    2A */
literal|0x0E
block|,
comment|/* 8E */
comment|/* Tab                          2B */
literal|0x0F
block|,
comment|/* 8F */
comment|/* Space                        2C */
literal|0x39
block|,
comment|/* B9 */
comment|/* - _                          2D */
literal|0x0C
block|,
comment|/* 8C */
comment|/* = +                          2E */
literal|0x0D
block|,
comment|/* 8D */
comment|/* [ {                          2F */
literal|0x1A
block|,
comment|/* 9A */
comment|/* ] }                          30 */
literal|0x1B
block|,
comment|/* 9B */
comment|/* \ |                          31 */
literal|0x2B
block|,
comment|/* AB */
comment|/* Europe 1                     32 */
literal|0x2B
block|,
comment|/* AB */
comment|/* ; :                          33 */
literal|0x27
block|,
comment|/* A7 */
comment|/* " '                          34 */
literal|0x28
block|,
comment|/* A8 */
comment|/* ` ~                          35 */
literal|0x29
block|,
comment|/* A9 */
comment|/* comma<                      36 */
literal|0x33
block|,
comment|/* B3 */
comment|/* .>                          37 */
literal|0x34
block|,
comment|/* B4 */
comment|/* / ?                          38 */
literal|0x35
block|,
comment|/* B5 */
comment|/* Caps Lock                    39 */
literal|0x3A
block|,
comment|/* BA */
comment|/* F1                           3A */
literal|0x3B
block|,
comment|/* BB */
comment|/* F2                           3B */
literal|0x3C
block|,
comment|/* BC */
comment|/* F3                           3C */
literal|0x3D
block|,
comment|/* BD */
comment|/* F4                           3D */
literal|0x3E
block|,
comment|/* BE */
comment|/* F5                           3E */
literal|0x3F
block|,
comment|/* BF */
comment|/* F6                           3F */
literal|0x40
block|,
comment|/* C0 */
comment|/* F7                           40 */
literal|0x41
block|,
comment|/* C1 */
comment|/* F8                           41 */
literal|0x42
block|,
comment|/* C2 */
comment|/* F9                           42 */
literal|0x43
block|,
comment|/* C3 */
comment|/* F10                          43 */
literal|0x44
block|,
comment|/* C4 */
comment|/* F11                          44 */
literal|0x57
block|,
comment|/* D7 */
comment|/* F12                          45 */
literal|0x58
block|,
comment|/* D8 */
comment|/* Print Screen                 46 */
name|E0PREFIX
operator||
literal|0x37
block|,
comment|/* E0 B7 */
comment|/* Scroll Lock                  47 */
literal|0x46
block|,
comment|/* C6 */
if|#
directive|if
literal|0
comment|/* Break (Ctrl-Pause)           48 */
block|E0 46 E0 C6,
comment|/* None */
comment|/* Pause                        48 */
block|E1 1D 45 E1 9D C5,
comment|/* None */
else|#
directive|else
comment|/* Break (Ctrl-Pause)/Pause     48 */
name|NOBREAK
comment|/* Special case */
block|,
comment|/* None */
endif|#
directive|endif
comment|/* Insert                       49 */
name|E0PREFIX
operator||
literal|0x52
block|,
comment|/* E0 D2 */
comment|/* Home                         4A */
name|E0PREFIX
operator||
literal|0x47
block|,
comment|/* E0 C7 */
comment|/* Page Up                      4B */
name|E0PREFIX
operator||
literal|0x49
block|,
comment|/* E0 C9 */
comment|/* Delete                       4C */
name|E0PREFIX
operator||
literal|0x53
block|,
comment|/* E0 D3 */
comment|/* End                          4D */
name|E0PREFIX
operator||
literal|0x4F
block|,
comment|/* E0 CF */
comment|/* Page Down                    4E */
name|E0PREFIX
operator||
literal|0x51
block|,
comment|/* E0 D1 */
comment|/* Right Arrow                  4F */
name|E0PREFIX
operator||
literal|0x4D
block|,
comment|/* E0 CD */
comment|/* Left Arrow                   50 */
name|E0PREFIX
operator||
literal|0x4B
block|,
comment|/* E0 CB */
comment|/* Down Arrow                   51 */
name|E0PREFIX
operator||
literal|0x50
block|,
comment|/* E0 D0 */
comment|/* Up Arrow                     52 */
name|E0PREFIX
operator||
literal|0x48
block|,
comment|/* E0 C8 */
comment|/* Num Lock                     53 */
literal|0x45
block|,
comment|/* C5 */
comment|/* Keypad /                     54 */
name|E0PREFIX
operator||
literal|0x35
block|,
comment|/* E0 B5 */
comment|/* Keypad *                     55 */
literal|0x37
block|,
comment|/* B7 */
comment|/* Keypad -                     56 */
literal|0x4A
block|,
comment|/* CA */
comment|/* Keypad +                     57 */
literal|0x4E
block|,
comment|/* CE */
comment|/* Keypad Enter                 58 */
name|E0PREFIX
operator||
literal|0x1C
block|,
comment|/* E0 9C */
comment|/* Keypad 1 End                 59 */
literal|0x4F
block|,
comment|/* CF */
comment|/* Keypad 2 Down                5A */
literal|0x50
block|,
comment|/* D0 */
comment|/* Keypad 3 PageDn              5B */
literal|0x51
block|,
comment|/* D1 */
comment|/* Keypad 4 Left                5C */
literal|0x4B
block|,
comment|/* CB */
comment|/* Keypad 5                     5D */
literal|0x4C
block|,
comment|/* CC */
comment|/* Keypad 6 Right               5E */
literal|0x4D
block|,
comment|/* CD */
comment|/* Keypad 7 Home                5F */
literal|0x47
block|,
comment|/* C7 */
comment|/* Keypad 8 Up                  60 */
literal|0x48
block|,
comment|/* C8 */
comment|/* Keypad 9 PageUp              61 */
literal|0x49
block|,
comment|/* C9 */
comment|/* Keypad 0 Insert              62 */
literal|0x52
block|,
comment|/* D2 */
comment|/* Keypad . Delete              63 */
literal|0x53
block|,
comment|/* D3 */
comment|/* Europe 2                     64 */
literal|0x56
block|,
comment|/* D6 */
comment|/* App                          65 */
name|E0PREFIX
operator||
literal|0x5D
block|,
comment|/* E0 DD */
comment|/* Keyboard Power               66 */
name|E0PREFIX
operator||
literal|0x5E
block|,
comment|/* E0 DE */
comment|/* Keypad =                     67 */
literal|0x59
block|,
comment|/* D9 */
comment|/* F13                          68 */
literal|0x64
block|,
comment|/* E4 */
comment|/* F14                          69 */
literal|0x65
block|,
comment|/* E5 */
comment|/* F15                          6A */
literal|0x66
block|,
comment|/* E6 */
comment|/* F16                          6B */
literal|0x67
block|,
comment|/* E7 */
comment|/* F17                          6C */
literal|0x68
block|,
comment|/* E8 */
comment|/* F18                          6D */
literal|0x69
block|,
comment|/* E9 */
comment|/* F19                          6E */
literal|0x6A
block|,
comment|/* EA */
comment|/* F20                          6F */
literal|0x6B
block|,
comment|/* EB */
comment|/* F21                          70 */
literal|0x6C
block|,
comment|/* EC */
comment|/* F22                          71 */
literal|0x6D
block|,
comment|/* ED */
comment|/* F23                          72 */
literal|0x6E
block|,
comment|/* EE */
comment|/* F24                          73 */
literal|0x76
block|,
comment|/* F6 */
comment|/* Keyboard Execute             74 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Help                75 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Menu                76 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Select              77 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Stop                78 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Again               79 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Undo                7A */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Cut                 7B */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Copy                7C */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Paste               7D */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Find                7E */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Mute                7F */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Volume Up           80 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Volume Dn           81 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Locking Caps Lock   82 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Locking Num Lock    83 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Locking Scroll Lock 84 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keypad comma                 85 */
literal|0x7E
block|,
comment|/* FE */
comment|/* Keyboard Equal Sign          86 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Int'l 1             87 */
literal|0x73
block|,
comment|/* F3 */
comment|/* Keyboard Int'l 2             88 */
literal|0x70
block|,
comment|/* F0 */
comment|/* Keyboard Int'l 2             89 */
literal|0x7D
block|,
comment|/* FD */
comment|/* Keyboard Int'l 4             8A */
literal|0x79
block|,
comment|/* F9 */
comment|/* Keyboard Int'l 5             8B */
literal|0x7B
block|,
comment|/* FB */
comment|/* Keyboard Int'l 6             8C */
literal|0x5C
block|,
comment|/* DC */
comment|/* Keyboard Int'l 7             8D */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Int'l 8             8E */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Int'l 9             8F */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Lang 1              90 */
name|NOBREAK
operator||
literal|0xF2
block|,
comment|/* None */
comment|/* Keyboard Lang 2              91 */
name|NOBREAK
operator||
literal|0xF1
block|,
comment|/* None */
comment|/* Keyboard Lang 3              92 */
literal|0x78
block|,
comment|/* F8 */
comment|/* Keyboard Lang 4              93 */
literal|0x77
block|,
comment|/* F7 */
comment|/* Keyboard Lang 5              94 */
literal|0x76
block|,
comment|/* F6 */
comment|/* Keyboard Lang 6              95 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Lang 7              96 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Lang 8              97 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Lang 9              98 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Alternate Erase     99 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard SysReq/Attention    9A */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Cancel              9B */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Clear               9C */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Prior               9D */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Return              9E */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Separator           9F */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Out                 A0 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Oper                A1 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard Clear/Again         A2 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard CrSel/Props         A3 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Keyboard ExSel               A4 */
operator|-
literal|1
block|,
comment|/* Unassigned */
comment|/* Reserved                     A5 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     A6 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     A7 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     A8 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     A9 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     AA */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     AB */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     AC */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     AD */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     AE */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     AF */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B0 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B1 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B2 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B3 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B4 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B5 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B6 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B7 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B8 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     B9 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     BA */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     BB */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     BC */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     BD */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     BE */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     BF */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C0 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C1 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C2 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C3 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C4 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C5 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C6 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C7 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C8 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     C9 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     CA */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     CB */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     CC */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     CD */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     CE */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     CF */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D0 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D1 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D2 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D3 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D4 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D5 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D6 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D7 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D8 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     D9 */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     DA */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     DB */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     DC */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     DD */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     DE */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Reserved                     DF */
operator|-
literal|1
block|,
comment|/* Reserved */
comment|/* Left Control                 E0 */
literal|0x1D
block|,
comment|/* 9D */
comment|/* Left Shift                   E1 */
literal|0x2A
block|,
comment|/* AA */
comment|/* Left Alt                     E2 */
literal|0x38
block|,
comment|/* B8 */
comment|/* Left GUI                     E3 */
name|E0PREFIX
operator||
literal|0x5B
block|,
comment|/* E0 DB */
comment|/* Right Control                E4 */
name|E0PREFIX
operator||
literal|0x1D
block|,
comment|/* E0 9D */
comment|/* Right Shift                  E5 */
literal|0x36
block|,
comment|/* B6 */
comment|/* Right Alt                    E6 */
name|E0PREFIX
operator||
literal|0x38
block|,
comment|/* E0 B8 */
comment|/* Right GUI                    E7 */
name|E0PREFIX
operator||
literal|0x5C
comment|/* E0 DC */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|xsize
value|((int32_t)(sizeof(x)/sizeof(x[0])))
end_define

begin_comment
comment|/*  * Get a max HID keycode (aligned)  */
end_comment

begin_function
name|int32_t
name|kbd_maxkey
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|xsize
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Process keys  */
end_comment

begin_function
name|int32_t
name|kbd_process_keys
parameter_list|(
name|bthid_session_p
name|s
parameter_list|)
block|{
name|bitstr_t
name|diff
index|[
name|bitstr_size
argument_list|(
name|xsize
argument_list|)
index|]
decl_stmt|;
name|int32_t
name|f1
decl_stmt|,
name|f2
decl_stmt|,
name|i
decl_stmt|;
name|assert
argument_list|(
name|s
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|s
operator|->
name|srv
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|/* Check if the new keys have been pressed */
name|bit_ffs
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
name|xsize
argument_list|,
operator|&
name|f1
argument_list|)
expr_stmt|;
comment|/* Check if old keys still pressed */
name|bit_ffs
argument_list|(
name|s
operator|->
name|keys2
argument_list|,
name|xsize
argument_list|,
operator|&
name|f2
argument_list|)
expr_stmt|;
if|if
condition|(
name|f1
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* no new key pressed */
if|if
condition|(
name|f2
operator|!=
operator|-
literal|1
condition|)
block|{
comment|/* release old keys */
name|kbd_write
argument_list|(
name|s
operator|->
name|keys2
argument_list|,
name|f2
argument_list|,
literal|0
argument_list|,
name|s
operator|->
name|vkbd
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|s
operator|->
name|keys2
argument_list|,
literal|0
argument_list|,
name|bitstr_size
argument_list|(
name|xsize
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|f2
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* no old keys, but new keys pressed */
name|assert
argument_list|(
name|f1
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|s
operator|->
name|keys2
argument_list|,
name|s
operator|->
name|keys1
argument_list|,
name|bitstr_size
argument_list|(
name|xsize
argument_list|)
argument_list|)
expr_stmt|;
name|kbd_write
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
name|f1
argument_list|,
literal|1
argument_list|,
name|s
operator|->
name|vkbd
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
literal|0
argument_list|,
name|bitstr_size
argument_list|(
name|xsize
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* new keys got pressed, old keys got released */
name|memset
argument_list|(
name|diff
argument_list|,
literal|0
argument_list|,
name|bitstr_size
argument_list|(
name|xsize
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|f2
init|;
name|i
operator|<
name|xsize
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|bit_test
argument_list|(
name|s
operator|->
name|keys2
argument_list|,
name|i
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|bit_test
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
name|i
argument_list|)
condition|)
block|{
name|bit_clear
argument_list|(
name|s
operator|->
name|keys2
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|bit_set
argument_list|(
name|diff
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
block|}
for|for
control|(
name|i
operator|=
name|f1
init|;
name|i
operator|<
name|xsize
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|bit_test
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
name|i
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|bit_test
argument_list|(
name|s
operator|->
name|keys2
argument_list|,
name|i
argument_list|)
condition|)
name|bit_set
argument_list|(
name|s
operator|->
name|keys2
argument_list|,
name|i
argument_list|)
expr_stmt|;
else|else
name|bit_clear
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
name|bit_ffs
argument_list|(
name|diff
argument_list|,
name|xsize
argument_list|,
operator|&
name|f2
argument_list|)
expr_stmt|;
if|if
condition|(
name|f2
operator|>
literal|0
condition|)
name|kbd_write
argument_list|(
name|diff
argument_list|,
name|f2
argument_list|,
literal|0
argument_list|,
name|s
operator|->
name|vkbd
argument_list|)
expr_stmt|;
name|bit_ffs
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
name|xsize
argument_list|,
operator|&
name|f1
argument_list|)
expr_stmt|;
if|if
condition|(
name|f1
operator|>
literal|0
condition|)
block|{
name|kbd_write
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
name|f1
argument_list|,
literal|1
argument_list|,
name|s
operator|->
name|vkbd
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|s
operator|->
name|keys1
argument_list|,
literal|0
argument_list|,
name|bitstr_size
argument_list|(
name|xsize
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Translate given keymap and write keyscodes  */
end_comment

begin_function
specifier|static
name|void
name|kbd_write
parameter_list|(
name|bitstr_t
modifier|*
name|m
parameter_list|,
name|int32_t
name|fb
parameter_list|,
name|int32_t
name|make
parameter_list|,
name|int32_t
name|fd
parameter_list|)
block|{
name|int32_t
name|i
decl_stmt|,
modifier|*
name|b
decl_stmt|,
modifier|*
name|eob
decl_stmt|,
name|n
decl_stmt|,
name|buf
index|[
literal|64
index|]
decl_stmt|;
name|b
operator|=
name|buf
expr_stmt|;
name|eob
operator|=
name|b
operator|+
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|i
operator|=
name|fb
expr_stmt|;
while|while
condition|(
name|i
operator|<
name|xsize
condition|)
block|{
if|if
condition|(
name|bit_test
argument_list|(
name|m
argument_list|,
name|i
argument_list|)
condition|)
block|{
name|n
operator|=
name|kbd_xlate
argument_list|(
name|i
argument_list|,
name|make
argument_list|,
name|b
argument_list|,
name|eob
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|==
operator|-
literal|1
condition|)
block|{
name|write
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
operator|(
name|b
operator|-
name|buf
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|b
operator|=
name|buf
expr_stmt|;
continue|continue;
block|}
name|b
operator|+=
name|n
expr_stmt|;
block|}
name|i
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|b
operator|!=
name|buf
condition|)
name|write
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
operator|(
name|b
operator|-
name|buf
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|buf
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Translate HID code into PS/2 code and put codes into buffer b.  * Returns the number of codes put in b. Return -1 if buffer has not  * enough space.  */
end_comment

begin_undef
undef|#
directive|undef
name|PUT
end_undef

begin_define
define|#
directive|define
name|PUT
parameter_list|(
name|c
parameter_list|,
name|n
parameter_list|,
name|b
parameter_list|,
name|eob
parameter_list|)
define|\
value|do {				\ 	if ((b)>= (eob))	\ 		return (-1);	\ 	*(b) = (c);		\ 	(b) ++;			\ 	(n) ++;			\ } while (0)
end_define

begin_function
specifier|static
name|int32_t
name|kbd_xlate
parameter_list|(
name|int32_t
name|code
parameter_list|,
name|int32_t
name|make
parameter_list|,
name|int32_t
modifier|*
name|b
parameter_list|,
name|int32_t
specifier|const
modifier|*
name|eob
parameter_list|)
block|{
name|int32_t
name|c
decl_stmt|,
name|n
decl_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|code
operator|>=
name|xsize
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* HID code is not in the table */
comment|/* Handle special case - Pause/Break */
if|if
condition|(
name|code
operator|==
literal|0x48
condition|)
block|{
if|if
condition|(
operator|!
name|make
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* No break code */
if|#
directive|if
literal|0
block|XXX FIXME 		if (ctrl_is_pressed) {
comment|/* Break (Ctrl-Pause) */
block|PUT(0xe0, n, b, eob); 			PUT(0x46, n, b, eob); 			PUT(0xe0, n, b, eob); 			PUT(0xc6, n, b, eob); 		} else {
comment|/* Pause */
block|PUT(0xe1, n, b, eob); 			PUT(0x1d, n, b, eob); 			PUT(0x45, n, b, eob); 			PUT(0xe1, n, b, eob); 			PUT(0x9d, n, b, eob); 			PUT(0xc5, n, b, eob); 		}
endif|#
directive|endif
return|return
operator|(
name|n
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|c
operator|=
name|x
index|[
name|code
index|]
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* HID code translation is not defined */
if|if
condition|(
name|make
condition|)
block|{
if|if
condition|(
name|c
operator|&
name|E0PREFIX
condition|)
name|PUT
argument_list|(
literal|0xe0
argument_list|,
name|n
argument_list|,
name|b
argument_list|,
name|eob
argument_list|)
expr_stmt|;
name|PUT
argument_list|(
operator|(
name|c
operator|&
name|CODEMASK
operator|)
argument_list|,
name|n
argument_list|,
name|b
argument_list|,
name|eob
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
operator|(
name|c
operator|&
name|NOBREAK
operator|)
condition|)
block|{
if|if
condition|(
name|c
operator|&
name|E0PREFIX
condition|)
name|PUT
argument_list|(
literal|0xe0
argument_list|,
name|n
argument_list|,
name|b
argument_list|,
name|eob
argument_list|)
expr_stmt|;
name|PUT
argument_list|(
operator|(
literal|0x80
operator||
operator|(
name|c
operator|&
name|CODEMASK
operator|)
operator|)
argument_list|,
name|n
argument_list|,
name|b
argument_list|,
name|eob
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|n
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Process status change from vkbd(4)  */
end_comment

begin_function
name|int32_t
name|kbd_status_changed
parameter_list|(
name|bthid_session_p
name|s
parameter_list|,
name|uint8_t
modifier|*
name|data
parameter_list|,
name|int32_t
name|len
parameter_list|)
block|{
name|vkbd_status_t
name|st
decl_stmt|;
name|uint8_t
name|leds
decl_stmt|,
name|report_id
decl_stmt|;
name|hid_device_p
name|hid_device
decl_stmt|;
name|hid_data_t
name|d
decl_stmt|;
name|hid_item_t
name|h
decl_stmt|;
name|assert
argument_list|(
name|s
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|len
operator|==
sizeof|sizeof
argument_list|(
name|vkbd_status_t
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|st
argument_list|,
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|st
argument_list|)
argument_list|)
expr_stmt|;
name|leds
operator|=
literal|0
expr_stmt|;
name|report_id
operator|=
name|NO_REPORT_ID
expr_stmt|;
name|hid_device
operator|=
name|get_hid_device
argument_list|(
operator|&
name|s
operator|->
name|bdaddr
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|hid_device
operator|!=
name|NULL
argument_list|)
expr_stmt|;
for|for
control|(
name|d
operator|=
name|hid_start_parse
argument_list|(
name|hid_device
operator|->
name|desc
argument_list|,
literal|1
operator|<<
name|hid_output
argument_list|,
operator|-
literal|1
argument_list|)
init|;
name|hid_get_item
argument_list|(
name|d
argument_list|,
operator|&
name|h
argument_list|)
operator|>
literal|0
condition|;
control|)
block|{
if|if
condition|(
name|HID_PAGE
argument_list|(
name|h
operator|.
name|usage
argument_list|)
operator|==
name|HUP_LEDS
condition|)
block|{
if|if
condition|(
name|report_id
operator|==
name|NO_REPORT_ID
condition|)
name|report_id
operator|=
name|h
operator|.
name|report_ID
expr_stmt|;
elseif|else
if|if
condition|(
name|h
operator|.
name|report_ID
operator|!=
name|report_id
condition|)
name|syslog
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"Output HID report IDs "
expr|\
literal|"for %s do not match: %d vs. %d. "
expr|\
literal|"Please report"
argument_list|,
name|bt_ntoa
argument_list|(
operator|&
name|s
operator|->
name|bdaddr
argument_list|,
name|NULL
argument_list|)
argument_list|,
name|h
operator|.
name|report_ID
argument_list|,
name|report_id
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|HID_USAGE
argument_list|(
name|h
operator|.
name|usage
argument_list|)
condition|)
block|{
case|case
literal|0x01
case|:
comment|/* Num Lock LED */
if|if
condition|(
name|st
operator|.
name|leds
operator|&
name|LED_NUM
condition|)
name|hid_set_data
argument_list|(
operator|&
name|leds
argument_list|,
operator|&
name|h
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x02
case|:
comment|/* Caps Lock LED */
if|if
condition|(
name|st
operator|.
name|leds
operator|&
name|LED_CAP
condition|)
name|hid_set_data
argument_list|(
operator|&
name|leds
argument_list|,
operator|&
name|h
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x03
case|:
comment|/* Scroll Lock LED */
if|if
condition|(
name|st
operator|.
name|leds
operator|&
name|LED_SCR
condition|)
name|hid_set_data
argument_list|(
operator|&
name|leds
argument_list|,
operator|&
name|h
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
comment|/* XXX add other LEDs ? */
block|}
block|}
block|}
name|hid_end_parse
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|data
index|[
literal|0
index|]
operator|=
literal|0xa2
expr_stmt|;
comment|/* DATA output (HID output report) */
if|if
condition|(
name|report_id
operator|!=
name|NO_REPORT_ID
condition|)
block|{
name|data
index|[
literal|1
index|]
operator|=
name|report_id
expr_stmt|;
name|data
index|[
literal|2
index|]
operator|=
name|leds
expr_stmt|;
name|len
operator|=
literal|3
expr_stmt|;
block|}
else|else
block|{
name|data
index|[
literal|1
index|]
operator|=
name|leds
expr_stmt|;
name|len
operator|=
literal|2
expr_stmt|;
block|}
name|write
argument_list|(
name|s
operator|->
name|intr
argument_list|,
name|data
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

