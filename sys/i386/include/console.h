begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (C) 1992, 1993, 1994 Søren Schmidt  *  *  This program is free software; you may redistribute it and/or   *  modify it, provided that it retain the above copyright notice   *  and the following disclaimer.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   *  *	Søren Schmidt 		Email:	sos@login.dkuug.dk  *	Tritonvej 36		UUCP:	...uunet!dkuug!login!sos  *	DK9210 Aalborg SO	Phone:  +45 9814 8076  *  *	from:@(#)console.h	1.1 940105  *	$Id: console.h,v 1.7 1994/02/04 10:35:29 chmr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONSOLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CONSOLE_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|KDGKBMODE
value|_IOR('K',  6, int)
end_define

begin_define
define|#
directive|define
name|KDSKBMODE
value|_IO('K',  7)
end_define

begin_define
define|#
directive|define
name|KDMKTONE
value|_IO('K',  8)
end_define

begin_define
define|#
directive|define
name|KDGETMODE
value|_IOR('K',  9, int)
end_define

begin_define
define|#
directive|define
name|KDSETMODE
value|_IO('K', 10)
end_define

begin_define
define|#
directive|define
name|KDSBORDER
value|_IO('K', 13)
end_define

begin_define
define|#
directive|define
name|KDGKBSTATE
value|_IOR('K', 19, int)
end_define

begin_define
define|#
directive|define
name|KDSKBSTATE
value|_IO('K', 20)
end_define

begin_define
define|#
directive|define
name|KDENABIO
value|_IO('K', 60)
end_define

begin_define
define|#
directive|define
name|KDDISABIO
value|_IO('K', 61)
end_define

begin_define
define|#
directive|define
name|KIOCSOUND
value|_IO('K', 63)
end_define

begin_define
define|#
directive|define
name|KDGKBTYPE
value|_IOR('K', 64, int)
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
value|_IO('K', 66)
end_define

begin_define
define|#
directive|define
name|KDSETRAD
value|_IO('K', 67)
end_define

begin_define
define|#
directive|define
name|GETFKEY
value|_IOWR('k', 0, fkeyarg_t)
end_define

begin_define
define|#
directive|define
name|SETFKEY
value|_IOWR('k', 1, fkeyarg_t)
end_define

begin_define
define|#
directive|define
name|GIO_SCRNMAP
value|_IOR('k', 2, scrmap_t)
end_define

begin_define
define|#
directive|define
name|PIO_SCRNMAP
value|_IOW('k', 3, scrmap_t)
end_define

begin_define
define|#
directive|define
name|GIO_KEYMAP
value|_IOR('k', 6, keymap_t)
end_define

begin_define
define|#
directive|define
name|PIO_KEYMAP
value|_IOW('k', 7, keymap_t)
end_define

begin_define
define|#
directive|define
name|CONS_BLANKTIME
value|_IOW('c', 4, long)
end_define

begin_define
define|#
directive|define
name|CONS_SSAVER
value|_IOW('c', 5, ssaver_t)
end_define

begin_define
define|#
directive|define
name|CONS_GSAVER
value|_IOWR('c', 6, ssaver_t)
end_define

begin_define
define|#
directive|define
name|PIO_FONT8x8
value|_IOW('c', 64, fnt8_t)
end_define

begin_define
define|#
directive|define
name|GIO_FONT8x8
value|_IOR('c', 65, fnt8_t)
end_define

begin_define
define|#
directive|define
name|PIO_FONT8x14
value|_IOW('c', 66, fnt14_t)
end_define

begin_define
define|#
directive|define
name|GIO_FONT8x14
value|_IOR('c', 67, fnt14_t)
end_define

begin_define
define|#
directive|define
name|PIO_FONT8x16
value|_IOW('c', 68, fnt16_t)
end_define

begin_define
define|#
directive|define
name|GIO_FONT8x16
value|_IOR('c', 69, fnt16_t)
end_define

begin_define
define|#
directive|define
name|CONS_GETINFO
value|_IOWR('c', 73, vid_info_t)
end_define

begin_define
define|#
directive|define
name|CONS_GETVERS
value|_IOR('c', 74, long)
end_define

begin_define
define|#
directive|define
name|CONS_80x25TEXT
value|_IO('c', 102)
end_define

begin_define
define|#
directive|define
name|CONS_80x50TEXT
value|_IO('c', 103)
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
value|_IO('v', 4)
end_define

begin_define
define|#
directive|define
name|VT_ACTIVATE
value|_IO('v', 5)
end_define

begin_define
define|#
directive|define
name|VT_WAITACTIVE
value|_IO('v', 6)
end_define

begin_define
define|#
directive|define
name|VT_GETACTIVE
value|_IOR('v', 7, int)
end_define

begin_define
define|#
directive|define
name|VT_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|VT_TRUE
value|1
end_define

begin_define
define|#
directive|define
name|VT_ACKACQ
value|2
end_define

begin_define
define|#
directive|define
name|VT_AUTO
value|0
end_define

begin_comment
comment|/* switching is automatic 	*/
end_comment

begin_define
define|#
directive|define
name|VT_PROCESS
value|1
end_define

begin_comment
comment|/* switching controlled by prog */
end_comment

begin_comment
comment|/* compatibility to old pccons& X386 */
end_comment

begin_define
define|#
directive|define
name|CONSOLE_X_MODE_ON
value|_IO('t', 121)
end_define

begin_define
define|#
directive|define
name|CONSOLE_X_MODE_OFF
value|_IO('t', 122)
end_define

begin_define
define|#
directive|define
name|CONSOLE_X_BELL
value|_IOW('t',123,int[2])
end_define

begin_struct
struct|struct
name|vt_mode
block|{
name|char
name|mode
decl_stmt|;
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

begin_define
define|#
directive|define
name|KD_MONO
value|1
end_define

begin_comment
comment|/* monochrome adapter        	*/
end_comment

begin_define
define|#
directive|define
name|KD_HERCULES
value|2
end_define

begin_comment
comment|/* hercules adapter          	*/
end_comment

begin_define
define|#
directive|define
name|KD_CGA
value|3
end_define

begin_comment
comment|/* color graphics adapter    	*/
end_comment

begin_define
define|#
directive|define
name|KD_EGA
value|4
end_define

begin_comment
comment|/* enhanced graphics adapter 	*/
end_comment

begin_define
define|#
directive|define
name|KD_VGA
value|5
end_define

begin_comment
comment|/* video graohics adapter    	*/
end_comment

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
name|KD_TEXT0
value|0
end_define

begin_comment
comment|/* ditto			*/
end_comment

begin_define
define|#
directive|define
name|KD_TEXT1
value|2
end_define

begin_comment
comment|/* set text mode !restore fonts */
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
name|KB_84
value|1
end_define

begin_comment
comment|/* 'old' 84 key AT-keyboard	*/
end_comment

begin_define
define|#
directive|define
name|KB_101
value|2
end_define

begin_comment
comment|/* MF-101 or MF-102 keyboard	*/
end_comment

begin_define
define|#
directive|define
name|KB_OTHER
value|3
end_define

begin_comment
comment|/* keyboard not known 		*/
end_comment

begin_define
define|#
directive|define
name|CLKED
value|1
end_define

begin_comment
comment|/* Caps locked			*/
end_comment

begin_define
define|#
directive|define
name|NLKED
value|2
end_define

begin_comment
comment|/* Num locked			*/
end_comment

begin_define
define|#
directive|define
name|SLKED
value|4
end_define

begin_comment
comment|/* Scroll locked		*/
end_comment

begin_define
define|#
directive|define
name|ALKED
value|8
end_define

begin_comment
comment|/* AltGr locked			*/
end_comment

begin_define
define|#
directive|define
name|LED_CAP
value|1
end_define

begin_comment
comment|/* Caps lock LED 		*/
end_comment

begin_define
define|#
directive|define
name|LED_NUM
value|2
end_define

begin_comment
comment|/* Num lock LED 		*/
end_comment

begin_define
define|#
directive|define
name|LED_SCR
value|4
end_define

begin_comment
comment|/* Scroll lock LED 		*/
end_comment

begin_comment
comment|/* possible flag values */
end_comment

begin_define
define|#
directive|define
name|FLAG_LOCK_O
value|0
end_define

begin_define
define|#
directive|define
name|FLAG_LOCK_C
value|1
end_define

begin_define
define|#
directive|define
name|FLAG_LOCK_N
value|2
end_define

begin_define
define|#
directive|define
name|NUM_KEYS
value|256
end_define

begin_comment
comment|/* number of keys in table	*/
end_comment

begin_define
define|#
directive|define
name|NUM_STATES
value|8
end_define

begin_comment
comment|/* states per key		*/
end_comment

begin_define
define|#
directive|define
name|ALTGR_OFFSET
value|128
end_define

begin_comment
comment|/* offset for altlock keys	*/
end_comment

begin_struct
struct|struct
name|keymap
block|{
name|u_short
name|n_keys
decl_stmt|;
struct|struct
name|key_t
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
name|key
index|[
name|NUM_KEYS
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXFK
value|16
end_define

begin_struct
struct|struct
name|fkeytab
block|{
name|u_char
name|str
index|[
name|MAXFK
index|]
decl_stmt|;
name|u_char
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fkeyarg
block|{
name|u_short
name|keynum
decl_stmt|;
name|char
name|keydef
index|[
name|MAXFK
index|]
decl_stmt|;
name|char
name|flen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|colors
block|{
name|char
name|fore
decl_stmt|;
name|char
name|back
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vid_info
block|{
name|short
name|size
decl_stmt|;
name|short
name|m_num
decl_stmt|;
name|u_short
name|mv_row
decl_stmt|,
name|mv_col
decl_stmt|;
name|u_short
name|mv_rsz
decl_stmt|,
name|mv_csz
decl_stmt|;
name|struct
name|colors
name|mv_norm
decl_stmt|,
name|mv_rev
decl_stmt|,
name|mv_grfc
decl_stmt|;
name|u_char
name|mv_ovscan
decl_stmt|;
name|u_char
name|mk_keylock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXSSAVER
value|16
end_define

begin_struct
struct|struct
name|ssaver
block|{
name|char
name|name
index|[
name|MAXSSAVER
index|]
decl_stmt|;
name|int
name|num
decl_stmt|;
name|long
name|time
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

begin_typedef
typedef|typedef
name|struct
name|fkeytab
name|fkeytab_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fkeyarg
name|fkeyarg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|vid_info
name|vid_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|vt_mode
name|vtmode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|scrmap
index|[
literal|256
index|]
decl_stmt|;
block|}
name|scrmap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|fnt8x8
index|[
literal|8
operator|*
literal|256
index|]
decl_stmt|;
block|}
name|fnt8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|fnt8x14
index|[
literal|14
operator|*
literal|256
index|]
decl_stmt|;
block|}
name|fnt14_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|fnt8x16
index|[
literal|16
operator|*
literal|256
index|]
decl_stmt|;
block|}
name|fnt16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ssaver
name|ssaver_t
typedef|;
end_typedef

begin_comment
comment|/* defines for "special" keys (spcl bit set in keymap) */
end_comment

begin_define
define|#
directive|define
name|NOP
value|0x00
end_define

begin_comment
comment|/* nothing (dead key)		*/
end_comment

begin_define
define|#
directive|define
name|LSH
value|0x02
end_define

begin_comment
comment|/* left shift key		*/
end_comment

begin_define
define|#
directive|define
name|RSH
value|0x03
end_define

begin_comment
comment|/* right shift key		*/
end_comment

begin_define
define|#
directive|define
name|CLK
value|0x04
end_define

begin_comment
comment|/* caps lock key		*/
end_comment

begin_define
define|#
directive|define
name|NLK
value|0x05
end_define

begin_comment
comment|/* num lock key			*/
end_comment

begin_define
define|#
directive|define
name|SLK
value|0x06
end_define

begin_comment
comment|/* scroll lock key		*/
end_comment

begin_define
define|#
directive|define
name|LALT
value|0x07
end_define

begin_comment
comment|/* left alt key			*/
end_comment

begin_define
define|#
directive|define
name|LCTR
value|0x09
end_define

begin_comment
comment|/* left control key		*/
end_comment

begin_define
define|#
directive|define
name|NEXT
value|0x0a
end_define

begin_comment
comment|/* switch to next screen 	*/
end_comment

begin_define
define|#
directive|define
name|F_SCR
value|0x0b
end_define

begin_comment
comment|/* switch to first screen 	*/
end_comment

begin_define
define|#
directive|define
name|L_SCR
value|0x1a
end_define

begin_comment
comment|/* switch to last screen 	*/
end_comment

begin_define
define|#
directive|define
name|F_FN
value|0x1b
end_define

begin_comment
comment|/* first function key 		*/
end_comment

begin_define
define|#
directive|define
name|L_FN
value|0x7a
end_define

begin_comment
comment|/* last function key 		*/
end_comment

begin_define
define|#
directive|define
name|RCTR
value|0x7b
end_define

begin_comment
comment|/* right control key		*/
end_comment

begin_define
define|#
directive|define
name|RALT
value|0x7c
end_define

begin_comment
comment|/* right alt (altgr) key	*/
end_comment

begin_define
define|#
directive|define
name|ALK
value|0x7d
end_define

begin_comment
comment|/* alt lock key			*/
end_comment

begin_define
define|#
directive|define
name|ASH
value|0x7e
end_define

begin_comment
comment|/* alt shift key		*/
end_comment

begin_define
define|#
directive|define
name|META
value|0x7f
end_define

begin_comment
comment|/* meta key			*/
end_comment

begin_define
define|#
directive|define
name|RBT
value|0x80
end_define

begin_comment
comment|/* boot machine			*/
end_comment

begin_define
define|#
directive|define
name|DBG
value|0x81
end_define

begin_comment
comment|/* call debugger		*/
end_comment

begin_define
define|#
directive|define
name|F
parameter_list|(
name|x
parameter_list|)
value|((x)+F_FN-1)
end_define

begin_define
define|#
directive|define
name|S
parameter_list|(
name|x
parameter_list|)
value|((x)+F_SCR-1)
end_define

begin_define
define|#
directive|define
name|NOKEY
value|0x100
end_define

begin_comment
comment|/* no key pressed marker 	*/
end_comment

begin_define
define|#
directive|define
name|FKEY
value|0x200
end_define

begin_comment
comment|/* funtion key marker 		*/
end_comment

begin_define
define|#
directive|define
name|MKEY
value|0x400
end_define

begin_comment
comment|/* meta key marker (prepend ESC)*/
end_comment

begin_define
define|#
directive|define
name|KB_DATA
value|0x60
end_define

begin_comment
comment|/* kbd data port 		*/
end_comment

begin_define
define|#
directive|define
name|KB_STAT
value|0x64
end_define

begin_comment
comment|/* kbd status port 		*/
end_comment

begin_define
define|#
directive|define
name|KB_BUF_FULL
value|0x01
end_define

begin_comment
comment|/* kbd has char pending 	*/
end_comment

begin_define
define|#
directive|define
name|KB_READY
value|0x02
end_define

begin_comment
comment|/* kbd ready for command 	*/
end_comment

begin_define
define|#
directive|define
name|KB_WRITE
value|0x60
end_define

begin_comment
comment|/* kbd write command 		*/
end_comment

begin_define
define|#
directive|define
name|KB_SETLEDS
value|0xed
end_define

begin_comment
comment|/* kbd set leds 		*/
end_comment

begin_define
define|#
directive|define
name|KB_SETRAD
value|0xf3
end_define

begin_comment
comment|/* kbd set repeat&delay command */
end_comment

begin_define
define|#
directive|define
name|KB_ACK
value|0xfa
end_define

begin_comment
comment|/* kbd acknowledge answer 	*/
end_comment

begin_define
define|#
directive|define
name|KB_RESET_CPU
value|0xfe
end_define

begin_comment
comment|/* kbd reset main cpu command 	*/
end_comment

begin_define
define|#
directive|define
name|KB_RESET
value|0xff
end_define

begin_comment
comment|/* kbd reset 			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

