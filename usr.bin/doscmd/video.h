begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1996  *	Berkeley Software Design, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Berkeley Software  *	Design, Inc.  *  * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI video.h,v 2.2 1996/04/08 19:33:12 bostic Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Motorola 6845 Video Controller registers  *  * They are read by  *	OUT port,code  *	IN  port+1,res  *  * They are written by  *	OUT port,code  *	OUT port+1,value  */
end_comment

begin_define
define|#
directive|define
name|MVC_TotHorzChar
value|0x00
end_define

begin_comment
comment|/* Total Horizontal Character */
end_comment

begin_define
define|#
directive|define
name|MVC_DispHorzChar
value|0x01
end_define

begin_comment
comment|/* Display Horizontal Character */
end_comment

begin_define
define|#
directive|define
name|MVC_HorzSyncChar
value|0x02
end_define

begin_comment
comment|/* Horizontal sync signal after ...char */
end_comment

begin_define
define|#
directive|define
name|MVC_HorzSyncDur
value|0x03
end_define

begin_comment
comment|/* Duration of horizontal sync signal in char */
end_comment

begin_define
define|#
directive|define
name|MVC_TotVertChar
value|0x04
end_define

begin_comment
comment|/* Total Vertical Character */
end_comment

begin_define
define|#
directive|define
name|MVC_AdjVertChar
value|0x05
end_define

begin_comment
comment|/* Adjust Veritcal Character */
end_comment

begin_define
define|#
directive|define
name|MVC_DispVertChar
value|0x06
end_define

begin_comment
comment|/* Display Vertical Charcter */
end_comment

begin_define
define|#
directive|define
name|MVC_VertSyncChar
value|0x07
end_define

begin_comment
comment|/* Vertical sync signal after .. char */
end_comment

begin_define
define|#
directive|define
name|MVC_InterlaceMode
value|0x08
end_define

begin_comment
comment|/* Interlace Mode */
end_comment

begin_define
define|#
directive|define
name|MVC_ScanLines
value|0x09
end_define

begin_comment
comment|/* Number of scan lines per screen line */
end_comment

begin_define
define|#
directive|define
name|MVC_CurStartLine
value|0x0a
end_define

begin_comment
comment|/* Starting line of screen cursor */
end_comment

begin_define
define|#
directive|define
name|MVC_CurEndLine
value|0x0b
end_define

begin_comment
comment|/* Ending line of screen cursor */
end_comment

begin_define
define|#
directive|define
name|MVC_CurHigh
value|0x0e
end_define

begin_comment
comment|/* High byte of cursor position */
end_comment

begin_define
define|#
directive|define
name|MVC_CurLow
value|0x0f
end_define

begin_comment
comment|/* High byte of cursor position */
end_comment

begin_comment
comment|/*  * Additional MDA register  */
end_comment

begin_define
define|#
directive|define
name|MDA_StartDispPageLo
value|0x0c
end_define

begin_comment
comment|/* Starting address of displayed screen page (lo byte) */
end_comment

begin_define
define|#
directive|define
name|MDA_StartDispPageHi
value|0x0d
end_define

begin_comment
comment|/* Starting address of displayed screen page (hi byte) */
end_comment

begin_define
define|#
directive|define
name|MDA_BlinkCurAddrHi
value|0x0e
end_define

begin_comment
comment|/* Character address of blinking screen cursor (hi byte) */
end_comment

begin_define
define|#
directive|define
name|MDA_BlinkCurAddrLo
value|0x0f
end_define

begin_comment
comment|/* Character address of blinking screen cursor (lo byte) */
end_comment

begin_define
define|#
directive|define
name|MDA_LightPenHi
value|0x10
end_define

begin_comment
comment|/* Light Pen Position (hi byte) */
end_comment

begin_define
define|#
directive|define
name|MDA_LightPenLo
value|0x11
end_define

begin_comment
comment|/* Light Pen Position (lo byte) */
end_comment

begin_define
define|#
directive|define
name|MDA_Control
value|0x03b8
end_define

begin_comment
comment|/* MDA Control Register Port */
end_comment

begin_define
define|#
directive|define
name|MVC_Address
value|0x03b4
end_define

begin_comment
comment|/* MVC Address Register */
end_comment

begin_define
define|#
directive|define
name|MVC_Data
value|0x03b5
end_define

begin_comment
comment|/* MVC Data Register */
end_comment

begin_define
define|#
directive|define
name|MDA_VideoSeg
value|0xb800
end_define

begin_comment
comment|/* Segmet address of video ram */
end_comment

begin_define
define|#
directive|define
name|CGA_Control
value|0x03d8
end_define

begin_comment
comment|/* CGA Control Register Port */
end_comment

begin_define
define|#
directive|define
name|CGA_Status
value|0x03da
end_define

begin_comment
comment|/* CGA Control Register Port */
end_comment

begin_define
define|#
directive|define
name|CVC_Address
value|0x03d4
end_define

begin_comment
comment|/* CVC Address Register */
end_comment

begin_define
define|#
directive|define
name|CVC_Data
value|0x03d5
end_define

begin_comment
comment|/* CVC Data Register */
end_comment

begin_define
define|#
directive|define
name|CGA_Black
value|0x0
end_define

begin_define
define|#
directive|define
name|CGA_Blue
value|0x1
end_define

begin_define
define|#
directive|define
name|CGA_Green
value|0x2
end_define

begin_define
define|#
directive|define
name|CGA_Cyan
value|0x3
end_define

begin_define
define|#
directive|define
name|CGA_Red
value|0x4
end_define

begin_define
define|#
directive|define
name|CGA_Magenta
value|0x5
end_define

begin_define
define|#
directive|define
name|CGA_Brown
value|0x6
end_define

begin_define
define|#
directive|define
name|CGA_LightGray
value|0x7
end_define

begin_define
define|#
directive|define
name|CGA_DarkGray
value|0x8
end_define

begin_define
define|#
directive|define
name|CGA_LightBlue
value|0x9
end_define

begin_define
define|#
directive|define
name|CGA_LightGreen
value|0xa
end_define

begin_define
define|#
directive|define
name|CGA_LightCyan
value|0xb
end_define

begin_define
define|#
directive|define
name|CGA_LightRed
value|0xc
end_define

begin_define
define|#
directive|define
name|CGA_LightMagenta
value|0xd
end_define

begin_define
define|#
directive|define
name|CGA_Yellow
value|0xe
end_define

begin_define
define|#
directive|define
name|CGA_White
value|0xf
end_define

begin_define
define|#
directive|define
name|VGA_Segment
value|0xa000
end_define

begin_comment
comment|/* Starting Segment of VGA Memory */
end_comment

begin_define
define|#
directive|define
name|V_int
value|0x10
end_define

begin_comment
comment|/* interrupt for dealing with screen */
end_comment

begin_define
define|#
directive|define
name|V_mode
value|0
end_define

begin_comment
comment|/* code for setting new screen mode */
end_comment

begin_define
define|#
directive|define
name|V_curtype
value|1
end_define

begin_comment
comment|/* code for setting new cursor type */
end_comment

begin_define
define|#
directive|define
name|V_setcur
value|2
end_define

begin_comment
comment|/* code for addressing cursor */
end_comment

begin_define
define|#
directive|define
name|V_readcur
value|3
end_define

begin_comment
comment|/* code for reading cursor location */
end_comment

begin_define
define|#
directive|define
name|V_readlp
value|4
end_define

begin_comment
comment|/* code for reading light pen position */
end_comment

begin_define
define|#
directive|define
name|V_setpage
value|5
end_define

begin_comment
comment|/* code to select active page */
end_comment

begin_define
define|#
directive|define
name|V_scrollup
value|6
end_define

begin_comment
comment|/* code to scroll screen up */
end_comment

begin_define
define|#
directive|define
name|V_scrolldn
value|7
end_define

begin_comment
comment|/* code to scroll screen nown */
end_comment

begin_define
define|#
directive|define
name|V_readch
value|8
end_define

begin_comment
comment|/* code to read a character from screen */
end_comment

begin_define
define|#
directive|define
name|V_writeach
value|9
end_define

begin_comment
comment|/* code to write char and attributes */
end_comment

begin_define
define|#
directive|define
name|V_writech
value|10
end_define

begin_comment
comment|/* code to write character only */
end_comment

begin_define
define|#
directive|define
name|V_setpal
value|11
end_define

begin_comment
comment|/* code to set new setpal or border */
end_comment

begin_define
define|#
directive|define
name|V_wdot
value|12
end_define

begin_comment
comment|/* code to write a dot */
end_comment

begin_define
define|#
directive|define
name|V_rdot
value|13
end_define

begin_comment
comment|/* code to read a dot */
end_comment

begin_define
define|#
directive|define
name|V_wtty
value|14
end_define

begin_comment
comment|/* code to write as if teletype */
end_comment

begin_define
define|#
directive|define
name|V_state
value|15
end_define

begin_comment
comment|/* code to find current screen status */
end_comment

begin_define
define|#
directive|define
name|VM_40x25
value|0x00
end_define

begin_define
define|#
directive|define
name|VM_80x25
value|0x02
end_define

begin_define
define|#
directive|define
name|VM_320x200x4
value|0x04
end_define

begin_define
define|#
directive|define
name|VM_640x200x2
value|0x06
end_define

begin_define
define|#
directive|define
name|VM_80x25mono
value|0x07
end_define

begin_define
define|#
directive|define
name|VM_320x200x16
value|0x0d
end_define

begin_define
define|#
directive|define
name|VM_640x200x16
value|0x0e
end_define

begin_define
define|#
directive|define
name|VM_640x350mono
value|0x0f
end_define

begin_define
define|#
directive|define
name|VM_640x350x16
value|0x10
end_define

begin_define
define|#
directive|define
name|VM_640x480x2
value|0x11
end_define

begin_define
define|#
directive|define
name|VM_640x480x16
value|0x12
end_define

begin_define
define|#
directive|define
name|VM_320x200x256
value|0x13
end_define

begin_define
define|#
directive|define
name|VM_80x30
value|0x50
end_define

begin_define
define|#
directive|define
name|VM_80x43
value|0x51
end_define

begin_define
define|#
directive|define
name|VM_80x60
value|0x52
end_define

begin_define
define|#
directive|define
name|VM_132x25
value|0x53
end_define

begin_define
define|#
directive|define
name|VM_132x30
value|0x54
end_define

begin_define
define|#
directive|define
name|VM_132x43
value|0x55
end_define

begin_define
define|#
directive|define
name|VM_132x60
value|0x56
end_define

begin_define
define|#
directive|define
name|VM_132x25h
value|0x57
end_define

begin_define
define|#
directive|define
name|VM_132x30h
value|0x58
end_define

begin_define
define|#
directive|define
name|VM_132x43h
value|0x59
end_define

begin_define
define|#
directive|define
name|VM_132x60h
value|0x5a
end_define

begin_define
define|#
directive|define
name|VM_800x600x16
value|0x5b
end_define

begin_define
define|#
directive|define
name|VM_640x400x256
value|0x5c
end_define

begin_define
define|#
directive|define
name|VM_640x480x256
value|0x5d
end_define

begin_define
define|#
directive|define
name|VM_800x600x256
value|0x5e
end_define

begin_define
define|#
directive|define
name|VM_1024x768x16
value|0x5f
end_define

begin_define
define|#
directive|define
name|VM_1024x768x4
value|0x60
end_define

begin_define
define|#
directive|define
name|VM_768x1024x16
value|0x61
end_define

begin_define
define|#
directive|define
name|VM_1024x768x256
value|0x62
end_define

begin_define
define|#
directive|define
name|VM_VGA
value|VM_640x480x256
end_define

begin_define
define|#
directive|define
name|VM_EVGA
value|VM_800x600x256
end_define

begin_define
define|#
directive|define
name|VM_SVGAportrait
value|VM_768x1024x16
end_define

begin_define
define|#
directive|define
name|VM_SVGA16
value|VM_1024x768x16
end_define

begin_define
define|#
directive|define
name|VM_SVGA256
value|VM_1024x768x256
end_define

end_unit

