begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1995 Hellmuth Michaelis and Joerg Wunsch.  *  * Copyright (c) 1992, 1993 Brian Dunford-Shore and Holger Veit.  *  * Copyright (C) 1992, 1993 Soeren Schmidt.  *  * All rights reserved.  *  * For the sake of compatibility, portions of this code regarding the  * X server interface are taken from Soeren Schmidt's syscons driver.  *  * This code is derived from software contributed to 386BSD by  * Holger Veit.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz and Don Ahn.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by  * 	Hellmuth Michaelis, Brian Dunford-Shore, Joerg Wunsch, Holger Veit  *	and Soeren Schmidt.  * 4. The name authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  * @(#)ioctl_pcvt.h, 3.20, Last Edit-Date: [Fri Apr  7 10:17:13 1995]  * $FreeBSD$  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  *	pcvt_ioctl.h	ioctl's for the VT220 video driver 'pcvt'  *	---------------------------------------------------------  *	-hm	------------ Release 3.00 --------------  *	-hm	some new PCVT_xxx (and CONF_xxx) values  *	-hm	version definitions moved to begin of file  *	-hm	removed PCVT_FAKE_SYSCONS10  *	-hm	accept KERNEL or _KERNEL  *	-hm	changed _IOCTL_PCVT_H_ to _MACHINE_PCVT_IOCTL_H_ (bde)  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCVT_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCVT_IOCTL_H_
end_define

begin_comment
comment|/* pcvt version information for VGAPCVTID ioctl */
end_comment

begin_define
define|#
directive|define
name|PCVTIDNAME
value|"pcvt-b24"
end_define

begin_comment
comment|/* driver id - string		*/
end_comment

begin_define
define|#
directive|define
name|PCVTIDMAJOR
value|3
end_define

begin_comment
comment|/* driver id - major release	*/
end_comment

begin_define
define|#
directive|define
name|PCVTIDMINOR
value|20
end_define

begin_comment
comment|/* driver id - minor release	*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*---------------------------------------------------------------------------*  *		IOCTLs for MF II and AT Keyboards  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|KBDRESET
value|_IO('K',  1)
end_define

begin_comment
comment|/* reset keyboard / set defaults */
end_comment

begin_define
define|#
directive|define
name|KBDGTPMAT
value|_IOR('K', 2, int)
end_define

begin_comment
comment|/* get current typematic value   */
end_comment

begin_define
define|#
directive|define
name|KBDSTPMAT
value|_IOW('K', 3, int)
end_define

begin_comment
comment|/* set current typematic value   */
end_comment

begin_comment
comment|/*	Typematic Delay Values	*/
end_comment

begin_define
define|#
directive|define
name|KBD_TPD250
value|0x00
end_define

begin_comment
comment|/*  250 ms	*/
end_comment

begin_define
define|#
directive|define
name|KBD_TPD500
value|0x20
end_define

begin_comment
comment|/*  500 ms	*/
end_comment

begin_define
define|#
directive|define
name|KBD_TPD750
value|0x40
end_define

begin_comment
comment|/*  750 ms	*/
end_comment

begin_define
define|#
directive|define
name|KBD_TPD1000
value|0x60
end_define

begin_comment
comment|/* 1000 ms	*/
end_comment

begin_comment
comment|/*	Typematic Repeat Rate	*/
end_comment

begin_define
define|#
directive|define
name|KBD_TPM300
value|0x00
end_define

begin_comment
comment|/* 30.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM267
value|0x01
end_define

begin_comment
comment|/* 26.7 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM240
value|0x02
end_define

begin_comment
comment|/* 24.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM218
value|0x03
end_define

begin_comment
comment|/* 21.8 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM200
value|0x04
end_define

begin_comment
comment|/* 20.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM185
value|0x05
end_define

begin_comment
comment|/* 18.5 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM171
value|0x06
end_define

begin_comment
comment|/* 17.1 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM160
value|0x07
end_define

begin_comment
comment|/* 16.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM150
value|0x08
end_define

begin_comment
comment|/* 15.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM133
value|0x09
end_define

begin_comment
comment|/* 13.3 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM120
value|0x0A
end_define

begin_comment
comment|/* 12.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM109
value|0x0B
end_define

begin_comment
comment|/* 10.9 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM100
value|0x0C
end_define

begin_comment
comment|/* 10.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM92
value|0x0D
end_define

begin_comment
comment|/*  9.2 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM86
value|0x0E
end_define

begin_comment
comment|/*  8.6 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM80
value|0x0F
end_define

begin_comment
comment|/*  8.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM75
value|0x10
end_define

begin_comment
comment|/*  7.5 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM67
value|0x11
end_define

begin_comment
comment|/*  6.7 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM60
value|0x12
end_define

begin_comment
comment|/*  6.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM55
value|0x13
end_define

begin_comment
comment|/*  5.5 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM50
value|0x14
end_define

begin_comment
comment|/*  5.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM46
value|0x15
end_define

begin_comment
comment|/*  4.6 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM43
value|0x16
end_define

begin_comment
comment|/*  4.3 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM40
value|0x17
end_define

begin_comment
comment|/*  4.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM37
value|0x18
end_define

begin_comment
comment|/*  3.7 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM33
value|0x19
end_define

begin_comment
comment|/*  3.3 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM30
value|0x1A
end_define

begin_comment
comment|/*  3.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM27
value|0x1B
end_define

begin_comment
comment|/*  2.7 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM25
value|0x1C
end_define

begin_comment
comment|/*  2.5 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM23
value|0x1D
end_define

begin_comment
comment|/*  2.3 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM21
value|0x1E
end_define

begin_comment
comment|/*  2.1 char/second */
end_comment

begin_define
define|#
directive|define
name|KBD_TPM20
value|0x1F
end_define

begin_comment
comment|/*  2.0 char/second */
end_comment

begin_define
define|#
directive|define
name|KBDGREPSW
value|_IOR('K', 4, int)
end_define

begin_comment
comment|/* get key repetition switch */
end_comment

begin_define
define|#
directive|define
name|KBDSREPSW
value|_IOW('K', 5, int)
end_define

begin_comment
comment|/* set key repetition switch */
end_comment

begin_define
define|#
directive|define
name|KBD_REPEATOFF
value|0
end_define

begin_define
define|#
directive|define
name|KBD_REPEATON
value|1
end_define

begin_define
define|#
directive|define
name|KBDGLEDS
value|_IOR('K', 6, int)
end_define

begin_comment
comment|/* get LED state */
end_comment

begin_define
define|#
directive|define
name|KBDSLEDS
value|_IOW('K', 7, int)
end_define

begin_comment
comment|/* set LED state, does not influence */
end_comment

begin_define
define|#
directive|define
name|KBD_SCROLLLOCK
value|0x0001
end_define

begin_comment
comment|/* the driver's idea of lock key state */
end_comment

begin_define
define|#
directive|define
name|KBD_NUMLOCK
value|0x0002
end_define

begin_define
define|#
directive|define
name|KBD_CAPSLOCK
value|0x0004
end_define

begin_define
define|#
directive|define
name|KBDGLOCK
value|_IOR('K', 8, int)
end_define

begin_comment
comment|/* gets state of SCROLL,NUM,CAPS */
end_comment

begin_define
define|#
directive|define
name|KBDSLOCK
value|_IOW('K', 9, int)
end_define

begin_comment
comment|/* sets state of SCROLL,NUM,CAPS + LEDs */
end_comment

begin_define
define|#
directive|define
name|KBDMAXOVLKEYSIZE
value|15
end_define

begin_comment
comment|/* + zero byte */
end_comment

begin_struct
struct|struct
name|kbd_ovlkey
comment|/* complete definition of a key */
block|{
name|u_short
name|keynum
decl_stmt|;
comment|/* the key itself */
name|u_short
name|type
decl_stmt|;
comment|/* type of key, see below */
name|u_char
name|subu
decl_stmt|;
comment|/* subtype, ignored on write */
name|char
name|unshift
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* emitted string, unshifted */
name|u_char
name|subs
decl_stmt|;
comment|/* subtype, ignored on write */
name|char
name|shift
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* emitted string, shifted */
name|u_char
name|subc
decl_stmt|;
comment|/* subtype, ignored on write */
name|char
name|ctrl
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* emitted string, control */
name|u_char
name|suba
decl_stmt|;
comment|/* subtype, ignored on write */
name|char
name|altgr
index|[
name|KBDMAXOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* emitted string, altgr */
block|}
struct|;
end_struct

begin_comment
comment|/*	Max value for keynum field	*/
end_comment

begin_define
define|#
directive|define
name|KBDMAXKEYS
value|128
end_define

begin_comment
comment|/* Max No. of Keys */
end_comment

begin_comment
comment|/*	Values for type field	*/
end_comment

begin_define
define|#
directive|define
name|KBD_NONE
value|0
end_define

begin_comment
comment|/* no function, key is disabled */
end_comment

begin_define
define|#
directive|define
name|KBD_SHIFT
value|1
end_define

begin_comment
comment|/* keyboard shift */
end_comment

begin_define
define|#
directive|define
name|KBD_META
value|2
end_define

begin_comment
comment|/* alternate shift, sets bit8 to ASCII code */
end_comment

begin_define
define|#
directive|define
name|KBD_NUM
value|3
end_define

begin_comment
comment|/* numeric shift, keypad num / appl */
end_comment

begin_define
define|#
directive|define
name|KBD_CTL
value|4
end_define

begin_comment
comment|/* control code generation */
end_comment

begin_define
define|#
directive|define
name|KBD_CAPS
value|5
end_define

begin_comment
comment|/* caps shift - swaps case of letter */
end_comment

begin_define
define|#
directive|define
name|KBD_ASCII
value|6
end_define

begin_comment
comment|/* ascii code generating key */
end_comment

begin_define
define|#
directive|define
name|KBD_SCROLL
value|7
end_define

begin_comment
comment|/* stop output */
end_comment

begin_define
define|#
directive|define
name|KBD_FUNC
value|8
end_define

begin_comment
comment|/* function key */
end_comment

begin_define
define|#
directive|define
name|KBD_KP
value|9
end_define

begin_comment
comment|/* keypad keys */
end_comment

begin_define
define|#
directive|define
name|KBD_BREAK
value|10
end_define

begin_comment
comment|/* ignored */
end_comment

begin_define
define|#
directive|define
name|KBD_ALTGR
value|11
end_define

begin_comment
comment|/* AltGr Translation feature */
end_comment

begin_define
define|#
directive|define
name|KBD_SHFTLOCK
value|12
end_define

begin_comment
comment|/* shiftlock */
end_comment

begin_define
define|#
directive|define
name|KBD_CURSOR
value|13
end_define

begin_comment
comment|/* cursor keys */
end_comment

begin_define
define|#
directive|define
name|KBD_RETURN
value|14
end_define

begin_comment
comment|/* RETURN/ENTER keys */
end_comment

begin_comment
comment|/*	Values  for subtype field	*/
end_comment

begin_define
define|#
directive|define
name|KBD_SUBT_STR
value|0
end_define

begin_comment
comment|/* key is bound to a string */
end_comment

begin_define
define|#
directive|define
name|KBD_SUBT_FNC
value|1
end_define

begin_comment
comment|/* key is bound to a function */
end_comment

begin_define
define|#
directive|define
name|KBD_OVERLOAD
value|0x8000
end_define

begin_comment
comment|/* Key is overloaded, ignored in ioctl */
end_comment

begin_define
define|#
directive|define
name|KBD_MASK
value|(~KBD_OVERLOAD)
end_define

begin_comment
comment|/* mask for type */
end_comment

begin_define
define|#
directive|define
name|KBDGCKEY
value|_IOWR('K',16, struct kbd_ovlkey)
end_define

begin_comment
comment|/* get current key values */
end_comment

begin_define
define|#
directive|define
name|KBDSCKEY
value|_IOW('K',17, struct kbd_ovlkey)
end_define

begin_comment
comment|/* set new key assignment values*/
end_comment

begin_define
define|#
directive|define
name|KBDGOKEY
value|_IOWR('K',18, struct kbd_ovlkey)
end_define

begin_comment
comment|/* get original key assignment values*/
end_comment

begin_define
define|#
directive|define
name|KBDRMKEY
value|_IOW('K',19, int)
end_define

begin_comment
comment|/* remove a key assignment */
end_comment

begin_define
define|#
directive|define
name|KBDDEFAULT
value|_IO('K',20)
end_define

begin_comment
comment|/* remove all key assignments */
end_comment

begin_comment
comment|/* mouse emulator definitions */
end_comment

begin_struct
struct|struct
name|mousedefs
block|{
name|int
name|leftbutton
decl_stmt|;
comment|/* (PC) scan code for "left button" key */
name|int
name|middlebutton
decl_stmt|;
comment|/* (PC) scan code for "mid button" key */
name|int
name|rightbutton
decl_stmt|;
comment|/* (PC) scan code for "right button" key */
name|int
name|stickybuttons
decl_stmt|;
comment|/* if true, the buttons are "sticky" */
name|int
name|acceltime
decl_stmt|;
comment|/* timeout in microseconds to start pointer */
comment|/* movement acceleration */
comment|/* defaults to: scan(F1), scan(F2), scan(F3), false, 500000 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KBDMOUSEGET
value|_IOR('K', 25, struct mousedefs)
end_define

begin_comment
comment|/* read defs */
end_comment

begin_define
define|#
directive|define
name|KBDMOUSESET
value|_IOW('K', 26, struct mousedefs)
end_define

begin_comment
comment|/* set defs */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *		IOCTLs for Video Adapter  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* Definition of PC Video Adaptor Types */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_ADAPTOR
value|0
end_define

begin_comment
comment|/* Unidentified adaptor ... */
end_comment

begin_define
define|#
directive|define
name|MDA_ADAPTOR
value|1
end_define

begin_comment
comment|/* Monochrome Display Adaptor/Hercules Graphics Card */
end_comment

begin_define
define|#
directive|define
name|CGA_ADAPTOR
value|2
end_define

begin_comment
comment|/* Color Graphics Adaptor */
end_comment

begin_define
define|#
directive|define
name|EGA_ADAPTOR
value|3
end_define

begin_comment
comment|/* Enhanced Graphics Adaptor */
end_comment

begin_define
define|#
directive|define
name|VGA_ADAPTOR
value|4
end_define

begin_comment
comment|/* Video Graphics Adaptor/Array */
end_comment

begin_comment
comment|/* Definitions of Monitor types */
end_comment

begin_define
define|#
directive|define
name|MONITOR_MONO
value|0
end_define

begin_comment
comment|/* Monochrome Monitor */
end_comment

begin_define
define|#
directive|define
name|MONITOR_COLOR
value|1
end_define

begin_comment
comment|/* Color Monitor */
end_comment

begin_comment
comment|/* Types of VGA chips detectable by current driver version */
end_comment

begin_define
define|#
directive|define
name|VGA_F_NONE
value|0
end_define

begin_comment
comment|/* FAMILY NOT KNOWN */
end_comment

begin_define
define|#
directive|define
name|VGA_UNKNOWN
value|0
end_define

begin_comment
comment|/* default, no 132 columns	*/
end_comment

begin_define
define|#
directive|define
name|VGA_F_TSENG
value|1
end_define

begin_comment
comment|/* FAMILY TSENG */
end_comment

begin_define
define|#
directive|define
name|VGA_ET4000
value|1
end_define

begin_comment
comment|/* Tseng Labs ET4000		*/
end_comment

begin_define
define|#
directive|define
name|VGA_ET3000
value|2
end_define

begin_comment
comment|/* Tseng Labs ET3000		*/
end_comment

begin_define
define|#
directive|define
name|VGA_F_WD
value|2
end_define

begin_comment
comment|/* FAMILY WD */
end_comment

begin_define
define|#
directive|define
name|VGA_PVGA
value|3
end_define

begin_comment
comment|/* Western Digital Paradise VGA	*/
end_comment

begin_define
define|#
directive|define
name|VGA_WD90C00
value|4
end_define

begin_comment
comment|/* Western Digital WD90C00	*/
end_comment

begin_define
define|#
directive|define
name|VGA_WD90C10
value|5
end_define

begin_comment
comment|/* Western Digital WD90C10	*/
end_comment

begin_define
define|#
directive|define
name|VGA_WD90C11
value|6
end_define

begin_comment
comment|/* Western Digital WD90C11	*/
end_comment

begin_define
define|#
directive|define
name|VGA_F_V7
value|3
end_define

begin_comment
comment|/* FAMILY VIDEO 7 */
end_comment

begin_define
define|#
directive|define
name|VGA_V7VEGA
value|7
end_define

begin_comment
comment|/* Video 7 VEGA VGA */
end_comment

begin_define
define|#
directive|define
name|VGA_V7FWVR
value|8
end_define

begin_comment
comment|/* Video 7 FASTWRITE/VRAM */
end_comment

begin_define
define|#
directive|define
name|VGA_V7V5
value|9
end_define

begin_comment
comment|/* Video 7 Version 5 */
end_comment

begin_define
define|#
directive|define
name|VGA_V71024I
value|10
end_define

begin_comment
comment|/* Video 7 1024i */
end_comment

begin_define
define|#
directive|define
name|VGA_V7UNKNOWN
value|11
end_define

begin_comment
comment|/* Video 7 unknown board .. */
end_comment

begin_define
define|#
directive|define
name|VGA_F_TRI
value|4
end_define

begin_comment
comment|/* FAMILY TRIDENT */
end_comment

begin_define
define|#
directive|define
name|VGA_TR8800BR
value|12
end_define

begin_comment
comment|/* Trident TVGA 8800BR */
end_comment

begin_define
define|#
directive|define
name|VGA_TR8800CS
value|13
end_define

begin_comment
comment|/* Trident TVGA 8800CS */
end_comment

begin_define
define|#
directive|define
name|VGA_TR8900B
value|14
end_define

begin_comment
comment|/* Trident TVGA 8900B  */
end_comment

begin_define
define|#
directive|define
name|VGA_TR8900C
value|15
end_define

begin_comment
comment|/* Trident TVGA 8900C  */
end_comment

begin_define
define|#
directive|define
name|VGA_TR8900CL
value|16
end_define

begin_comment
comment|/* Trident TVGA 8900CL */
end_comment

begin_define
define|#
directive|define
name|VGA_TR9000
value|17
end_define

begin_comment
comment|/* Trident TVGA 9000   */
end_comment

begin_define
define|#
directive|define
name|VGA_TR9100
value|18
end_define

begin_comment
comment|/* Trident TVGA 9100   */
end_comment

begin_define
define|#
directive|define
name|VGA_TR9200
value|19
end_define

begin_comment
comment|/* Trident TVGA 9200   */
end_comment

begin_define
define|#
directive|define
name|VGA_TRUNKNOWN
value|20
end_define

begin_comment
comment|/* Trident unknown     */
end_comment

begin_define
define|#
directive|define
name|VGA_F_S3
value|5
end_define

begin_comment
comment|/* FAMILY S3  */
end_comment

begin_define
define|#
directive|define
name|VGA_S3_911
value|21
end_define

begin_comment
comment|/* S3 911 */
end_comment

begin_define
define|#
directive|define
name|VGA_S3_924
value|22
end_define

begin_comment
comment|/* S3 924 */
end_comment

begin_define
define|#
directive|define
name|VGA_S3_80x
value|23
end_define

begin_comment
comment|/* S3 801/805 */
end_comment

begin_define
define|#
directive|define
name|VGA_S3_928
value|24
end_define

begin_comment
comment|/* S3 928 */
end_comment

begin_define
define|#
directive|define
name|VGA_S3_UNKNOWN
value|25
end_define

begin_comment
comment|/* unknown S3 chipset */
end_comment

begin_define
define|#
directive|define
name|VGA_F_CIR
value|6
end_define

begin_comment
comment|/* FAMILY CIRRUS */
end_comment

begin_define
define|#
directive|define
name|VGA_CL_GD5402
value|26
end_define

begin_comment
comment|/* Cirrus CL-GD5402	*/
end_comment

begin_define
define|#
directive|define
name|VGA_CL_GD5402r1
value|27
end_define

begin_comment
comment|/* Cirrus CL-GD5402r1	*/
end_comment

begin_define
define|#
directive|define
name|VGA_CL_GD5420
value|28
end_define

begin_comment
comment|/* Cirrus CL-GD5420	*/
end_comment

begin_define
define|#
directive|define
name|VGA_CL_GD5420r1
value|29
end_define

begin_comment
comment|/* Cirrus CL-GD5420r1	*/
end_comment

begin_define
define|#
directive|define
name|VGA_CL_GD5422
value|30
end_define

begin_comment
comment|/* Cirrus CL-GD5422	*/
end_comment

begin_define
define|#
directive|define
name|VGA_CL_GD5424
value|31
end_define

begin_comment
comment|/* Cirrus CL-GD5424	*/
end_comment

begin_define
define|#
directive|define
name|VGA_CL_GD5426
value|32
end_define

begin_comment
comment|/* Cirrus CL-GD5426	*/
end_comment

begin_define
define|#
directive|define
name|VGA_CL_GD5428
value|33
end_define

begin_comment
comment|/* Cirrus CL-GD5428	*/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* NOTE: update the 'scon' utility when adding support for more chipsets !!! */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* Definitions of Vertical Screen Sizes for EGA/VGA Adaptors */
end_comment

begin_define
define|#
directive|define
name|SIZ_25ROWS
value|0
end_define

begin_comment
comment|/* VGA: 25 lines, 8x16 font */
end_comment

begin_comment
comment|/* EGA: 25 lines, 8x14 font */
end_comment

begin_define
define|#
directive|define
name|SIZ_28ROWS
value|1
end_define

begin_comment
comment|/* VGA: 28 lines, 8x14 font */
end_comment

begin_define
define|#
directive|define
name|SIZ_35ROWS
value|2
end_define

begin_comment
comment|/* EGA: 35 lines, 8x10 font */
end_comment

begin_define
define|#
directive|define
name|SIZ_40ROWS
value|3
end_define

begin_comment
comment|/* VGA: 40 lines, 8x10 font */
end_comment

begin_define
define|#
directive|define
name|SIZ_43ROWS
value|4
end_define

begin_comment
comment|/* EGA: 43 lines, 8x8  font */
end_comment

begin_define
define|#
directive|define
name|SIZ_50ROWS
value|5
end_define

begin_comment
comment|/* VGA: 50 lines, 8x8  font */
end_comment

begin_comment
comment|/* Definitions of Font Sizes for EGA/VGA Adaptors */
end_comment

begin_define
define|#
directive|define
name|FNT_8x16
value|0
end_define

begin_comment
comment|/* 8x16 Pixel Font, only VGA */
end_comment

begin_define
define|#
directive|define
name|FNT_8x14
value|1
end_define

begin_comment
comment|/* 8x14 Pixel Font, EGA/VGA  */
end_comment

begin_define
define|#
directive|define
name|FNT_8x10
value|2
end_define

begin_comment
comment|/* 8x10 Pixel Font, EGA/VGA  */
end_comment

begin_define
define|#
directive|define
name|FNT_8x8
value|3
end_define

begin_comment
comment|/* 8x8  Pixel Font, EGA/VGA  */
end_comment

begin_comment
comment|/* Definitions of Character Set (Font) Numbers */
end_comment

begin_define
define|#
directive|define
name|CH_SET0
value|0
end_define

begin_comment
comment|/* Character Set (Font) 0, EGA/VGA */
end_comment

begin_define
define|#
directive|define
name|CH_SET1
value|1
end_define

begin_comment
comment|/* Character Set (Font) 1, EGA/VGA */
end_comment

begin_define
define|#
directive|define
name|CH_SET2
value|2
end_define

begin_comment
comment|/* Character Set (Font) 2, EGA/VGA */
end_comment

begin_define
define|#
directive|define
name|CH_SET3
value|3
end_define

begin_comment
comment|/* Character Set (Font) 3, EGA/VGA */
end_comment

begin_define
define|#
directive|define
name|CH_SETMAX_EGA
value|3
end_define

begin_comment
comment|/* EGA has 4 Character Sets / Fonts */
end_comment

begin_define
define|#
directive|define
name|CH_SET4
value|4
end_define

begin_comment
comment|/* Character Set (Font) 4, VGA */
end_comment

begin_define
define|#
directive|define
name|CH_SET5
value|5
end_define

begin_comment
comment|/* Character Set (Font) 5, VGA */
end_comment

begin_define
define|#
directive|define
name|CH_SET6
value|6
end_define

begin_comment
comment|/* Character Set (Font) 6, VGA */
end_comment

begin_define
define|#
directive|define
name|CH_SET7
value|7
end_define

begin_comment
comment|/* Character Set (Font) 7, VGA */
end_comment

begin_define
define|#
directive|define
name|CH_SETMAX_VGA
value|7
end_define

begin_comment
comment|/* VGA has 8 Character Sets / Fonts */
end_comment

begin_comment
comment|/* Definitions of Terminal Emulation Modes */
end_comment

begin_define
define|#
directive|define
name|M_HPVT
value|0
end_define

begin_comment
comment|/* VTxxx and HP Mode, Labels& Status Line on */
end_comment

begin_define
define|#
directive|define
name|M_PUREVT
value|1
end_define

begin_comment
comment|/* only VTxxx Sequences recognized, no Labels */
end_comment

begin_comment
comment|/*---*/
end_comment

begin_define
define|#
directive|define
name|VGACURSOR
value|_IOW('V',100, struct cursorshape)
end_define

begin_comment
comment|/* set cursor shape */
end_comment

begin_struct
struct|struct
name|cursorshape
block|{
name|int
name|screen_no
decl_stmt|;
comment|/* screen number for which to set,		    */
comment|/*  or -1 to set on current active screen        */
name|int
name|start
decl_stmt|;
comment|/* top scanline, range 0... Character Height - 1 */
name|int
name|end
decl_stmt|;
comment|/* end scanline, range 0... Character Height - 1 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGALOADCHAR
value|_IOW('V',101, struct vgaloadchar)
end_define

begin_comment
comment|/* load vga char */
end_comment

begin_struct
struct|struct
name|vgaloadchar
block|{
name|int
name|character_set
decl_stmt|;
comment|/* VGA character set to load into */
name|int
name|character
decl_stmt|;
comment|/* Character to load */
name|int
name|character_scanlines
decl_stmt|;
comment|/* Scanlines per character */
name|u_char
name|char_table
index|[
literal|32
index|]
decl_stmt|;
comment|/* VGA character shape table */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGASETFONTATTR
value|_IOW('V',102, struct vgafontattr)
end_define

begin_comment
comment|/* set font attr */
end_comment

begin_define
define|#
directive|define
name|VGAGETFONTATTR
value|_IOWR('V',103, struct vgafontattr)
end_define

begin_comment
comment|/* get font attr */
end_comment

begin_struct
struct|struct
name|vgafontattr
block|{
name|int
name|character_set
decl_stmt|;
comment|/* VGA character set */
name|int
name|font_loaded
decl_stmt|;
comment|/* Mark font loaded or unloaded */
name|int
name|screen_size
decl_stmt|;
comment|/* Character rows per screen */
name|int
name|character_scanlines
decl_stmt|;
comment|/* Scanlines per character - 1 */
name|int
name|screen_scanlines
decl_stmt|;
comment|/* Scanlines per screen - 1 byte */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGASETSCREEN
value|_IOW('V',104, struct screeninfo)
end_define

begin_comment
comment|/* set screen info */
end_comment

begin_define
define|#
directive|define
name|VGAGETSCREEN
value|_IOWR('V',105, struct screeninfo)
end_define

begin_comment
comment|/* get screen info */
end_comment

begin_struct
struct|struct
name|screeninfo
block|{
name|int
name|adaptor_type
decl_stmt|;
comment|/* type of video adaptor installed	*/
comment|/* read only, ignored on write		*/
name|int
name|monitor_type
decl_stmt|;
comment|/* type of monitor (mono/color)installed*/
comment|/* read only, ignored on write		*/
name|int
name|totalfonts
decl_stmt|;
comment|/* no of downloadable fonts		*/
comment|/* read only, ignored on write		*/
name|int
name|totalscreens
decl_stmt|;
comment|/* no of virtual screens		*/
comment|/* read only, ignored on write		*/
name|int
name|screen_no
decl_stmt|;
comment|/* screen number, this was got from	*/
comment|/* on write, if -1, apply pure_vt_mode	*/
comment|/* and/or screen_size to current screen */
comment|/* else to screen_no supplied		*/
name|int
name|current_screen
decl_stmt|;
comment|/* screen number, which is displayed.	*/
comment|/* on write, if -1, make this screen	*/
comment|/* the current screen, else set current	*/
comment|/* displayed screen to parameter	*/
name|int
name|pure_vt_mode
decl_stmt|;
comment|/* flag, pure VT mode or HP/VT mode	*/
comment|/* on write, if -1, no change		*/
name|int
name|screen_size
decl_stmt|;
comment|/* screen size 				*/
comment|/* on write, if -1, no change		*/
name|int
name|force_24lines
decl_stmt|;
comment|/* force 24 lines if 25 lines VT mode	*/
comment|/* or 28 lines HP mode to get pure	*/
comment|/* VT220 screen size			*/
comment|/* on write, if -1, no change		*/
name|int
name|vga_family
decl_stmt|;
comment|/* if adaptor_type = VGA, this reflects */
comment|/* the chipset family after a read	*/
comment|/* nothing happens on write ...        */
name|int
name|vga_type
decl_stmt|;
comment|/* if adaptor_type = VGA, this reflects */
comment|/* the chipset after a read		*/
comment|/* nothing happens on write ...        */
name|int
name|vga_132
decl_stmt|;
comment|/* set to 1 if driver has support for	*/
comment|/* 132 column operation for chipset	*/
comment|/* currently ignored on write		*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGAREADPEL
value|_IOWR('V', 110, struct vgapel)
end_define

begin_comment
comment|/*r VGA palette entry */
end_comment

begin_define
define|#
directive|define
name|VGAWRITEPEL
value|_IOW('V', 111, struct vgapel)
end_define

begin_comment
comment|/*w VGA palette entry */
end_comment

begin_struct
struct|struct
name|vgapel
block|{
name|unsigned
name|idx
decl_stmt|;
comment|/* index into palette, 0 .. 255 valid	*/
name|unsigned
name|r
decl_stmt|,
name|g
decl_stmt|,
name|b
decl_stmt|;
comment|/* RGB values, masked by VGA_PMASK (63) */
block|}
struct|;
end_struct

begin_comment
comment|/* NOTE: The next ioctl is only valid if option PCVT_SCREENSAVER is configured*/
end_comment

begin_comment
comment|/* this is *not* restricted to VGA's, but won't introduce new garbage...      */
end_comment

begin_define
define|#
directive|define
name|VGASCREENSAVER
value|_IOW('V', 112, int)
end_define

begin_comment
comment|/* set timeout for screen     */
end_comment

begin_comment
comment|/* saver in seconds; 0 turns  */
end_comment

begin_comment
comment|/* it off                     */
end_comment

begin_define
define|#
directive|define
name|VGAPCVTID
value|_IOWR('V',113, struct pcvtid)
end_define

begin_comment
comment|/* get driver id */
end_comment

begin_struct
struct|struct
name|pcvtid
block|{
comment|/* THIS STRUCTURE IS NOW FROZEN !!! */
define|#
directive|define
name|PCVTIDNAMELN
value|16
comment|/* driver id - string length	*/
name|char
name|name
index|[
name|PCVTIDNAMELN
index|]
decl_stmt|;
comment|/* driver name, == PCVTIDSTR	*/
name|int
name|rmajor
decl_stmt|;
comment|/* revision number, major	*/
name|int
name|rminor
decl_stmt|;
comment|/* revision number, minor	*/
block|}
struct|;
end_struct

begin_comment
comment|/* END OF COLD PART ...		*/
end_comment

begin_define
define|#
directive|define
name|VGAPCVTINFO
value|_IOWR('V',114, struct pcvtinfo)
end_define

begin_comment
comment|/* get driver info */
end_comment

begin_struct
struct|struct
name|pcvtinfo
block|{
comment|/* compile time option values */
name|u_int
name|opsys
decl_stmt|;
comment|/* PCVT_xxx(x)BSD */
define|#
directive|define
name|CONF_UNKNOWNOPSYS
value|0
define|#
directive|define
name|CONF_386BSD
value|1
comment|/* unsupported */
define|#
directive|define
name|CONF_NETBSD
value|2
define|#
directive|define
name|CONF_FREEBSD
value|3
name|u_int
name|opsysrel
decl_stmt|;
comment|/* Release */
name|u_int
name|nscreens
decl_stmt|;
comment|/* PCVT_NSCREENS */
name|u_int
name|scanset
decl_stmt|;
comment|/* PCVT_SCANSET */
name|u_int
name|updatefast
decl_stmt|;
comment|/* PCVT_UPDATEFAST */
name|u_int
name|updateslow
decl_stmt|;
comment|/* PCVT_UPDATESLOW */
name|u_int
name|sysbeepf
decl_stmt|;
comment|/* PCVT_SYSBEEPF */
name|u_int
name|pcburst
decl_stmt|;
comment|/* PCVT_PCBURST */
name|u_int
name|kbd_fifo_sz
decl_stmt|;
comment|/* PCVT_KBD_FIFO_SZ */
comment|/* config booleans */
name|u_long
name|compile_opts
decl_stmt|;
comment|/* PCVT_xxxxxxxxxxxxxxx */
define|#
directive|define
name|CONF_VT220KEYB
value|0x00000001
define|#
directive|define
name|CONF_SCREENSAVER
value|0x00000002
define|#
directive|define
name|CONF_PRETTYSCRNS
value|0x00000004
define|#
directive|define
name|CONF_CTRL_ALT_DEL
value|0x00000008
define|#
directive|define
name|CONF_USEKBDSEC
value|0x00000010
define|#
directive|define
name|CONF_24LINESDEF
value|0x00000020
define|#
directive|define
name|CONF_EMU_MOUSE
value|0x00000040
define|#
directive|define
name|CONF_SHOWKEYS
value|0x00000080
define|#
directive|define
name|CONF_KEYBDID
value|0x00000100
define|#
directive|define
name|CONF_SIGWINCH
value|0x00000200
define|#
directive|define
name|CONF_NULLCHARS
value|0x00000400
define|#
directive|define
name|CONF_BACKUP_FONTS
value|0x00000800
define|#
directive|define
name|CONF_SW0CNOUTP
value|0x00001000
comment|/* was FORCE8BIT */
comment|/* 0x00002000 was NEEDPG */
define|#
directive|define
name|CONF_SETCOLOR
value|0x00004000
define|#
directive|define
name|CONF_132GENERIC
value|0x00008000
define|#
directive|define
name|CONF_PALFLICKER
value|0x00010000
define|#
directive|define
name|CONF_WAITRETRACE
value|0x00020000
define|#
directive|define
name|CONF_XSERVER
value|0x00040000
define|#
directive|define
name|CONF_USL_VT_COMPAT
value|0x00080000
define|#
directive|define
name|CONF_PORTIO_DELAY
value|0x00100000
comment|/* was FAKE_SYSCONS10 */
define|#
directive|define
name|CONF_INHIBIT_NUMLOCK
value|0x00200000
define|#
directive|define
name|CONF_META_ESC
value|0x00400000
define|#
directive|define
name|CONF_NOFASTSCROLL
value|0x00800000
define|#
directive|define
name|CONF_SLOW_INTERRUPT
value|0x01000000
define|#
directive|define
name|CONF_KBD_FIFO
value|0x02000000
define|#
directive|define
name|CONF_NO_LED_UPDATE
value|0x04000000
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGASETCOLMS
value|_IOW('V', 115, int)
end_define

begin_comment
comment|/* set number of columns (80/132)*/
end_comment

begin_comment
comment|/*  * only useful if compiled with ``XSERVER'' defined, but always here:  * WARNING: DO NOT CHANGE THESE DEFINITIONS, the X server relies on  * it since it's defining its own values and doesn't know nothing about  * this header file.  */
end_comment

begin_define
define|#
directive|define
name|CONSOLE_X_MODE_ON
value|_IO('t', 121)
end_define

begin_comment
comment|/* turn off pcvt, grant IOPL for X */
end_comment

begin_define
define|#
directive|define
name|CONSOLE_X_MODE_OFF
value|_IO('t', 122)
end_define

begin_comment
comment|/* back to pcvt */
end_comment

begin_define
define|#
directive|define
name|CONSOLE_X_BELL
value|_IOW('t', 123, int[2])
end_define

begin_comment
comment|/* set bell behaviour */
end_comment

begin_comment
comment|/*  * start of USL VT compatibility stuff  * these definitions must match those ones used by syscons  *  * Note that some of the ioctl command definitions below break the Berkeley  * style. They accept a parameter of type "int" (instead of Berkeley style  * "int *") in order to pass a single integer to the ioctl. These macros  * below are marked with a dummy "int" comment. Dont blame anyone else  * than USL for that braindeadness. It is done here to be a bit source-  * level compatible to SysV. (N.B., within the ioctl, the argument is  * dereferenced by "int *" anyway. The translation is done by the upper-  * level ioctl stuff.)  */
end_comment

begin_comment
comment|/*  * NB: Some of the definitions below apparently override the definitions  * in the KBD section above. But, due to BSDs encoding of the IO direction  * and transfer size, the resulting ioctl cmds differ, so we can take them  * here. The only real conflict would appear if we implemented KDGKBMODE,  * which would be identical to KBDGLEDS above. Since this command is not  * necessary for XFree86 2.0, we omit it.  */
end_comment

begin_comment
comment|/* #define KDGKBMODE 	_IOR('K', 6, int) */
end_comment

begin_comment
comment|/* not yet implemented */
end_comment

begin_define
define|#
directive|define
name|KDSKBMODE
value|_IO('K', 7
comment|/*, int */
value|)
end_define

begin_define
define|#
directive|define
name|K_RAW
value|0
end_define

begin_comment
comment|/* keyboard returns scancodes	*/
end_comment

begin_define
define|#
directive|define
name|K_XLATE
value|1
end_define

begin_comment
comment|/* keyboard returns ascii 	*/
end_comment

begin_define
define|#
directive|define
name|KDMKTONE
value|_IO('K', 8
comment|/*, int */
value|)
end_define

begin_comment
comment|/* #define KDGETMODE	_IOR('K', 9, int) */
end_comment

begin_comment
comment|/* not yet implemented */
end_comment

begin_define
define|#
directive|define
name|KDSETMODE
value|_IO('K', 10
comment|/*, int */
value|)
end_define

begin_define
define|#
directive|define
name|KD_TEXT
value|0
end_define

begin_comment
comment|/* set text mode restore fonts  */
end_comment

begin_define
define|#
directive|define
name|KD_GRAPHICS
value|1
end_define

begin_comment
comment|/* set graphics mode 		*/
end_comment

begin_comment
comment|/* we cannot see any sense to support KD_TEXT0 or KD_TEXT1 */
end_comment

begin_define
define|#
directive|define
name|KDENABIO
value|_IO('K', 60)
end_define

begin_comment
comment|/* only allowed if euid == 0 */
end_comment

begin_define
define|#
directive|define
name|KDDISABIO
value|_IO('K', 61)
end_define

begin_define
define|#
directive|define
name|KDGETLED
value|_IOR('K', 65, int)
end_define

begin_define
define|#
directive|define
name|KDSETLED
value|_IO('K', 66
comment|/*, int */
value|)
end_define

begin_define
define|#
directive|define
name|LED_CAP
value|1
end_define

begin_define
define|#
directive|define
name|LED_NUM
value|2
end_define

begin_define
define|#
directive|define
name|LED_SCR
value|4
end_define

begin_define
define|#
directive|define
name|KDSETRAD
value|_IO('K', 67
comment|/*, int */
value|)
end_define

begin_comment
comment|/*  * Note that since our idea of key mapping is much different from the  * SysV style, we _only_ support mapping layers base (0), shifted (1),  * alt (4), and alt-shift (5), and only for the basic keys (without  * any function keys). This is what XFree86 2.0+ needs to establish  * the default X keysym mapping.  */
end_comment

begin_define
define|#
directive|define
name|GIO_KEYMAP
value|_IOR('k', 6, keymap_t)
end_define

begin_define
define|#
directive|define
name|VT_OPENQRY
value|_IOR('v', 1, int)
end_define

begin_define
define|#
directive|define
name|VT_SETMODE
value|_IOW('v', 2, vtmode_t)
end_define

begin_define
define|#
directive|define
name|VT_GETMODE
value|_IOR('v', 3, vtmode_t)
end_define

begin_define
define|#
directive|define
name|VT_RELDISP
value|_IO('v', 4
comment|/*, int */
value|)
end_define

begin_comment
comment|/* acceptable values for the VT_RELDISP command */
end_comment

begin_define
define|#
directive|define
name|VT_FALSE
value|0
end_define

begin_comment
comment|/* release of VT refused */
end_comment

begin_define
define|#
directive|define
name|VT_TRUE
value|1
end_define

begin_comment
comment|/* VT released */
end_comment

begin_define
define|#
directive|define
name|VT_ACKACQ
value|2
end_define

begin_comment
comment|/* acknowledging VT acquisition */
end_comment

begin_define
define|#
directive|define
name|VT_ACTIVATE
value|_IO('v', 5
comment|/*, int */
value|)
end_define

begin_define
define|#
directive|define
name|VT_WAITACTIVE
value|_IO('v', 6
comment|/*, int */
value|)
end_define

begin_define
define|#
directive|define
name|VT_GETACTIVE
value|_IOR('v', 7, int)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_VT_MODE_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_VT_MODE_DECLARED
end_define

begin_struct
struct|struct
name|vt_mode
block|{
name|char
name|mode
decl_stmt|;
define|#
directive|define
name|VT_AUTO
value|0
comment|/* switching controlled by drvr	*/
define|#
directive|define
name|VT_PROCESS
value|1
comment|/* switching controlled by prog */
name|char
name|waitv
decl_stmt|;
comment|/* not implemented yet 	SOS	*/
name|short
name|relsig
decl_stmt|;
name|short
name|acqsig
decl_stmt|;
name|short
name|frsig
decl_stmt|;
comment|/* not implemented yet	SOS	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vt_mode
name|vtmode_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VT_MODE_DECLARED */
end_comment

begin_define
define|#
directive|define
name|NUM_KEYS
value|256
end_define

begin_define
define|#
directive|define
name|NUM_STATES
value|8
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KEYMAP_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_KEYMAP_DECLARED
end_define

begin_struct
struct|struct
name|keyent_t
block|{
name|u_char
name|map
index|[
name|NUM_STATES
index|]
decl_stmt|;
name|u_char
name|spcl
decl_stmt|;
name|u_char
name|flgs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|keymap
block|{
name|u_short
name|n_keys
decl_stmt|;
name|struct
name|keyent_t
name|key
index|[
name|NUM_KEYS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|keymap
name|keymap_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KEYMAP_DECLARED */
end_comment

begin_comment
comment|/* end of USL VT compatibility stuff */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PCVT_IOCTL_H_ */
end_comment

end_unit

