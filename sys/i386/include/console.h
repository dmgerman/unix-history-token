begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991-1996 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CONSOLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CONSOLE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

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

begin_define
define|#
directive|define
name|KDGKBMODE
value|_IOR('K', 6, int)
end_define

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
name|KDMKTONE
value|_IO('K', 8
comment|/*, int */
value|)
end_define

begin_define
define|#
directive|define
name|KDGETMODE
value|_IOR('K', 9, int)
end_define

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
name|KDSBORDER
value|_IO('K', 13
comment|/*, int */
value|)
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
value|_IO('K', 20
comment|/*, int */
value|)
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
value|_IO('K', 63
comment|/*, int */
value|)
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
value|_IO('K', 66
comment|/*, int */
value|)
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
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|KDRASTER
value|_IOW('K', 100, scr_size_t)
end_define

begin_define
define|#
directive|define
name|KDGKBINFO
value|_IOR('K', 101, keyboard_info_t)
end_define

begin_define
define|#
directive|define
name|KDSETREPEAT
value|_IOW('K', 102, keyboard_delay_t)
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
name|GIO_DEADKEYMAP
value|_IOR('k', 8, accentmap_t)
end_define

begin_define
define|#
directive|define
name|PIO_DEADKEYMAP
value|_IOW('k', 9, accentmap_t)
end_define

begin_define
define|#
directive|define
name|GIO_KEYMAPENT
value|_IOWR('k', 10, keyarg_t)
end_define

begin_define
define|#
directive|define
name|PIO_KEYMAPENT
value|_IOW('k', 11, keyarg_t)
end_define

begin_define
define|#
directive|define
name|GIO_ATTR
value|_IOR('a', 0, int)
end_define

begin_define
define|#
directive|define
name|GIO_COLOR
value|_IOR('c', 0, int)
end_define

begin_define
define|#
directive|define
name|CONS_CURRENT
value|_IOR('c', 1, int)
end_define

begin_define
define|#
directive|define
name|CONS_GET
value|_IOR('c', 2, int)
end_define

begin_define
define|#
directive|define
name|CONS_IO
value|_IO('c', 3)
end_define

begin_define
define|#
directive|define
name|CONS_BLANKTIME
value|_IOW('c', 4, int)
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
name|CONS_CURSORTYPE
value|_IOW('c', 7, int)
end_define

begin_define
define|#
directive|define
name|CONS_BELLTYPE
value|_IOW('c', 8, int)
end_define

begin_define
define|#
directive|define
name|CONS_HISTORY
value|_IOW('c', 9, int)
end_define

begin_define
define|#
directive|define
name|CONS_MOUSECTL
value|_IOWR('c', 10, mouse_info_t)
end_define

begin_define
define|#
directive|define
name|CONS_IDLE
value|_IOR('c', 11, int)
end_define

begin_define
define|#
directive|define
name|CONS_SAVERMODE
value|_IOW('c', 12, int)
end_define

begin_define
define|#
directive|define
name|CONS_SAVERSTART
value|_IOW('c', 13, int)
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
value|_IOR('c', 74, int)
end_define

begin_define
define|#
directive|define
name|CONS_CURRENTADP
value|_IOR('c', 100, int)
end_define

begin_define
define|#
directive|define
name|CONS_ADPINFO
value|_IOWR('c', 101, video_adapter_info_t)
end_define

begin_define
define|#
directive|define
name|CONS_MODEINFO
value|_IOWR('c', 102, video_info_t)
end_define

begin_define
define|#
directive|define
name|CONS_FINDMODE
value|_IOWR('c', 103, video_info_t)
end_define

begin_define
define|#
directive|define
name|CONS_SETWINORG
value|_IO('c', 104
comment|/* u_int */
value|)
end_define

begin_define
define|#
directive|define
name|CONS_SETKBD
value|_IO('c', 110
comment|/* int */
value|)
end_define

begin_define
define|#
directive|define
name|CONS_RELKBD
value|_IO('c', 111)
end_define

begin_comment
comment|/* CONS_SAVERMODE */
end_comment

begin_define
define|#
directive|define
name|CONS_LKM_SAVER
value|0
end_define

begin_define
define|#
directive|define
name|CONS_USR_SAVER
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|ADJUST_CLOCK
value|_IO('t',100)
end_define

begin_comment
comment|/* for 98note resume */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|VT_KERNEL
value|255
end_define

begin_comment
comment|/* switching controlled in kernel */
end_comment

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

begin_struct
struct|struct
name|mouse_data
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|z
decl_stmt|;
name|int
name|buttons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mouse_mode
block|{
name|int
name|mode
decl_stmt|;
name|int
name|signal
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mouse_event
block|{
name|int
name|id
decl_stmt|;
comment|/* one based */
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MOUSE_SHOW
value|0x01
end_define

begin_define
define|#
directive|define
name|MOUSE_HIDE
value|0x02
end_define

begin_define
define|#
directive|define
name|MOUSE_MOVEABS
value|0x03
end_define

begin_define
define|#
directive|define
name|MOUSE_MOVEREL
value|0x04
end_define

begin_define
define|#
directive|define
name|MOUSE_GETINFO
value|0x05
end_define

begin_define
define|#
directive|define
name|MOUSE_MODE
value|0x06
end_define

begin_define
define|#
directive|define
name|MOUSE_ACTION
value|0x07
end_define

begin_define
define|#
directive|define
name|MOUSE_MOTION_EVENT
value|0x08
end_define

begin_define
define|#
directive|define
name|MOUSE_BUTTON_EVENT
value|0x09
end_define

begin_struct
struct|struct
name|mouse_info
block|{
name|int
name|operation
decl_stmt|;
union|union
block|{
name|struct
name|mouse_data
name|data
decl_stmt|;
name|struct
name|mouse_mode
name|mode
decl_stmt|;
name|struct
name|mouse_event
name|event
decl_stmt|;
block|}
name|u
union|;
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
comment|/* video graphics adapter    	*/
end_comment

begin_define
define|#
directive|define
name|KD_PC98
value|6
end_define

begin_comment
comment|/* PC-98 display            	*/
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
name|KD_PIXEL
value|3
end_define

begin_comment
comment|/* set pixel mode		*/
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
name|K_CODE
value|2
end_define

begin_comment
comment|/* keyboard returns keycodes 	*/
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
name|LOCK_MASK
value|(CLKED | NLKED | SLKED | ALKED)
end_define

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

begin_define
define|#
directive|define
name|LED_MASK
value|(LED_CAP | LED_NUM | LED_SCR)
end_define

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

begin_struct
struct|struct
name|keyarg
block|{
name|u_short
name|keynum
decl_stmt|;
name|struct
name|keyent_t
name|key
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|keyarg
name|keyarg_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KEYMAP_DECLARED */
end_comment

begin_define
define|#
directive|define
name|NUM_DEADKEYS
value|15
end_define

begin_comment
comment|/* number of accent keys */
end_comment

begin_define
define|#
directive|define
name|NUM_ACCENTCHARS
value|52
end_define

begin_comment
comment|/* max number of accent chars */
end_comment

begin_struct
struct|struct
name|acc_t
block|{
name|u_char
name|accchar
decl_stmt|;
name|u_char
name|map
index|[
name|NUM_ACCENTCHARS
index|]
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|accentmap
block|{
name|u_short
name|n_accs
decl_stmt|;
name|struct
name|acc_t
name|acc
index|[
name|NUM_DEADKEYS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXFK
value|16
end_define

begin_define
define|#
directive|define
name|NUM_FKEYS
value|96
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

begin_comment
comment|/* video mode information block */
end_comment

begin_struct
struct|struct
name|video_info
block|{
name|int
name|vi_mode
decl_stmt|;
name|int
name|vi_flags
decl_stmt|;
define|#
directive|define
name|V_INFO_COLOR
value|(1<<0)
define|#
directive|define
name|V_INFO_GRAPHICS
value|(1<<1)
define|#
directive|define
name|V_INFO_LINEAR
value|(1<<2)
define|#
directive|define
name|V_INFO_VESA
value|(1<<3)
name|int
name|vi_width
decl_stmt|;
name|int
name|vi_height
decl_stmt|;
name|int
name|vi_cwidth
decl_stmt|;
name|int
name|vi_cheight
decl_stmt|;
name|int
name|vi_depth
decl_stmt|;
name|int
name|vi_planes
decl_stmt|;
name|u_int
name|vi_window
decl_stmt|;
comment|/* physical address */
name|size_t
name|vi_window_size
decl_stmt|;
name|size_t
name|vi_window_gran
decl_stmt|;
name|u_int
name|vi_buffer
decl_stmt|;
comment|/* physical address */
name|size_t
name|vi_buffer_size
decl_stmt|;
comment|/* XXX pixel format, memory model,... */
block|}
struct|;
end_struct

begin_comment
comment|/* adapter infromation block */
end_comment

begin_struct
struct|struct
name|video_adapter
block|{
name|int
name|va_index
decl_stmt|;
name|int
name|va_type
decl_stmt|;
name|char
modifier|*
name|va_name
decl_stmt|;
name|int
name|va_unit
decl_stmt|;
name|int
name|va_minor
decl_stmt|;
name|int
name|va_flags
decl_stmt|;
define|#
directive|define
name|V_ADP_COLOR
value|(1<<0)
define|#
directive|define
name|V_ADP_MODECHANGE
value|(1<<1)
define|#
directive|define
name|V_ADP_STATESAVE
value|(1<<2)
define|#
directive|define
name|V_ADP_STATELOAD
value|(1<<3)
define|#
directive|define
name|V_ADP_FONT
value|(1<<4)
define|#
directive|define
name|V_ADP_PALETTE
value|(1<<5)
define|#
directive|define
name|V_ADP_BORDER
value|(1<<6)
define|#
directive|define
name|V_ADP_VESA
value|(1<<7)
define|#
directive|define
name|V_ADP_PROBED
value|(1<<16)
define|#
directive|define
name|V_ADP_INITIALIZED
value|(1<<17)
define|#
directive|define
name|V_ADP_REGISTERED
value|(1<<18)
name|int
name|va_io_base
decl_stmt|;
name|int
name|va_io_size
decl_stmt|;
name|int
name|va_crtc_addr
decl_stmt|;
name|int
name|va_mem_base
decl_stmt|;
name|int
name|va_mem_size
decl_stmt|;
name|u_int
name|va_window
decl_stmt|;
comment|/* virtual address */
name|size_t
name|va_window_size
decl_stmt|;
name|size_t
name|va_window_gran
decl_stmt|;
name|u_int
name|va_buffer
decl_stmt|;
comment|/* virtual address */
name|size_t
name|va_buffer_size
decl_stmt|;
name|int
name|va_initial_mode
decl_stmt|;
name|int
name|va_initial_bios_mode
decl_stmt|;
name|int
name|va_mode
decl_stmt|;
name|struct
name|video_info
name|va_info
decl_stmt|;
name|int
name|va_line_width
decl_stmt|;
name|void
modifier|*
name|va_token
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_adapter_info
block|{
name|int
name|va_index
decl_stmt|;
name|int
name|va_type
decl_stmt|;
name|char
name|va_name
index|[
literal|16
index|]
decl_stmt|;
name|int
name|va_unit
decl_stmt|;
name|int
name|va_flags
decl_stmt|;
name|int
name|va_io_base
decl_stmt|;
name|int
name|va_io_size
decl_stmt|;
name|int
name|va_crtc_addr
decl_stmt|;
name|int
name|va_mem_base
decl_stmt|;
name|int
name|va_mem_size
decl_stmt|;
name|u_int
name|va_window
decl_stmt|;
comment|/* virtual address */
name|size_t
name|va_window_size
decl_stmt|;
name|size_t
name|va_window_gran
decl_stmt|;
name|u_int
name|va_buffer
decl_stmt|;
comment|/* virtual address */
name|size_t
name|va_buffer_size
decl_stmt|;
name|int
name|va_initial_mode
decl_stmt|;
name|int
name|va_initial_bios_mode
decl_stmt|;
name|int
name|va_mode
decl_stmt|;
name|int
name|va_line_width
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|V_ADP_PRIMARY
value|0
end_define

begin_define
define|#
directive|define
name|V_ADP_SECONDARY
value|1
end_define

begin_struct
struct|struct
name|keyboard_info
block|{
name|int
name|kb_index
decl_stmt|;
comment|/* kbdio index# */
name|char
name|kb_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* driver name */
name|int
name|kb_unit
decl_stmt|;
comment|/* unit# */
name|int
name|kb_type
decl_stmt|;
comment|/* KB_84, KB_101, KB_OTHER,... */
name|int
name|kb_config
decl_stmt|;
comment|/* device configuration flags */
name|int
name|kb_flags
decl_stmt|;
comment|/* internal flags */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|accentmap
name|accentmap_t
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
name|mouse_info
name|mouse_info_t
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

begin_typedef
typedef|typedef
name|struct
name|video_adapter
name|video_adapter_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|video_adapter_info
name|video_adapter_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|video_info
name|video_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|keyboard_info
name|keyboard_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|scr_size
index|[
literal|3
index|]
decl_stmt|;
block|}
name|scr_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|kbd_delay
index|[
literal|2
index|]
decl_stmt|;
block|}
name|keyboard_delay_t
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
name|BTAB
value|0x08
end_define

begin_comment
comment|/* backwards tab		*/
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

begin_comment
comment|/*			0x7b-0x7f	   reserved do not use !	*/
end_comment

begin_define
define|#
directive|define
name|RCTR
value|0x80
end_define

begin_comment
comment|/* right control key		*/
end_comment

begin_define
define|#
directive|define
name|RALT
value|0x81
end_define

begin_comment
comment|/* right alt (altgr) key	*/
end_comment

begin_define
define|#
directive|define
name|ALK
value|0x82
end_define

begin_comment
comment|/* alt lock key			*/
end_comment

begin_define
define|#
directive|define
name|ASH
value|0x83
end_define

begin_comment
comment|/* alt shift key		*/
end_comment

begin_define
define|#
directive|define
name|META
value|0x84
end_define

begin_comment
comment|/* meta key			*/
end_comment

begin_define
define|#
directive|define
name|RBT
value|0x85
end_define

begin_comment
comment|/* boot machine			*/
end_comment

begin_define
define|#
directive|define
name|DBG
value|0x86
end_define

begin_comment
comment|/* call debugger		*/
end_comment

begin_define
define|#
directive|define
name|SUSP
value|0x87
end_define

begin_comment
comment|/* suspend power (APM)		*/
end_comment

begin_define
define|#
directive|define
name|SPSC
value|0x88
end_define

begin_comment
comment|/* toggle splash/text screen	*/
end_comment

begin_define
define|#
directive|define
name|F_ACC
value|DGRA
end_define

begin_comment
comment|/* first accent key		*/
end_comment

begin_define
define|#
directive|define
name|DGRA
value|0x89
end_define

begin_comment
comment|/* grave			*/
end_comment

begin_define
define|#
directive|define
name|DACU
value|0x8a
end_define

begin_comment
comment|/* acute			*/
end_comment

begin_define
define|#
directive|define
name|DCIR
value|0x8b
end_define

begin_comment
comment|/* circumflex			*/
end_comment

begin_define
define|#
directive|define
name|DTIL
value|0x8c
end_define

begin_comment
comment|/* tilde			*/
end_comment

begin_define
define|#
directive|define
name|DMAC
value|0x8d
end_define

begin_comment
comment|/* macron			*/
end_comment

begin_define
define|#
directive|define
name|DBRE
value|0x8e
end_define

begin_comment
comment|/* breve			*/
end_comment

begin_define
define|#
directive|define
name|DDOT
value|0x8f
end_define

begin_comment
comment|/* dot				*/
end_comment

begin_define
define|#
directive|define
name|DUML
value|0x90
end_define

begin_comment
comment|/* umlaut/diaresis		*/
end_comment

begin_define
define|#
directive|define
name|DDIA
value|0x90
end_define

begin_comment
comment|/* diaresis			*/
end_comment

begin_define
define|#
directive|define
name|DSLA
value|0x91
end_define

begin_comment
comment|/* slash			*/
end_comment

begin_define
define|#
directive|define
name|DRIN
value|0x92
end_define

begin_comment
comment|/* ring				*/
end_comment

begin_define
define|#
directive|define
name|DCED
value|0x93
end_define

begin_comment
comment|/* cedilla			*/
end_comment

begin_define
define|#
directive|define
name|DAPO
value|0x94
end_define

begin_comment
comment|/* apostrophe			*/
end_comment

begin_define
define|#
directive|define
name|DDAC
value|0x95
end_define

begin_comment
comment|/* double acute			*/
end_comment

begin_define
define|#
directive|define
name|DOGO
value|0x96
end_define

begin_comment
comment|/* ogonek			*/
end_comment

begin_define
define|#
directive|define
name|DCAR
value|0x97
end_define

begin_comment
comment|/* caron			*/
end_comment

begin_define
define|#
directive|define
name|L_ACC
value|DCAR
end_define

begin_comment
comment|/* last accent key		*/
end_comment

begin_define
define|#
directive|define
name|STBY
value|0x98
end_define

begin_comment
comment|/* Go into standby mode (apm)   */
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
name|ACC
parameter_list|(
name|x
parameter_list|)
value|((x)+F_ACC)
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
comment|/* function key marker 		*/
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
name|BKEY
value|0x800
end_define

begin_comment
comment|/* backtab (ESC [ Z)		*/
end_comment

begin_define
define|#
directive|define
name|SPCLKEY
value|0x8000
end_define

begin_comment
comment|/* special key */
end_comment

begin_define
define|#
directive|define
name|RELKEY
value|0x4000
end_define

begin_comment
comment|/* key released */
end_comment

begin_define
define|#
directive|define
name|ERRKEY
value|0x2000
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|KEYCHAR
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x00ff)
end_define

begin_define
define|#
directive|define
name|KEYFLAGS
parameter_list|(
name|c
parameter_list|)
value|((c)& ~0x00ff)
end_define

begin_comment
comment|/* video mode definitions */
end_comment

begin_define
define|#
directive|define
name|M_B40x25
value|0
end_define

begin_comment
comment|/* black& white 40 columns */
end_comment

begin_define
define|#
directive|define
name|M_C40x25
value|1
end_define

begin_comment
comment|/* color 40 columns */
end_comment

begin_define
define|#
directive|define
name|M_B80x25
value|2
end_define

begin_comment
comment|/* black& white 80 columns */
end_comment

begin_define
define|#
directive|define
name|M_C80x25
value|3
end_define

begin_comment
comment|/* color 80 columns */
end_comment

begin_define
define|#
directive|define
name|M_BG320
value|4
end_define

begin_comment
comment|/* black& white graphics 320x200 */
end_comment

begin_define
define|#
directive|define
name|M_CG320
value|5
end_define

begin_comment
comment|/* color graphics 320x200 */
end_comment

begin_define
define|#
directive|define
name|M_BG640
value|6
end_define

begin_comment
comment|/* black& white graphics 640x200 hi-res */
end_comment

begin_define
define|#
directive|define
name|M_EGAMONO80x25
value|7
end_define

begin_comment
comment|/* ega-mono 80x25 */
end_comment

begin_define
define|#
directive|define
name|M_CG320_D
value|13
end_define

begin_comment
comment|/* ega mode D */
end_comment

begin_define
define|#
directive|define
name|M_CG640_E
value|14
end_define

begin_comment
comment|/* ega mode E */
end_comment

begin_define
define|#
directive|define
name|M_EGAMONOAPA
value|15
end_define

begin_comment
comment|/* ega mode F */
end_comment

begin_define
define|#
directive|define
name|M_CG640x350
value|16
end_define

begin_comment
comment|/* ega mode 10 */
end_comment

begin_define
define|#
directive|define
name|M_ENHMONOAPA2
value|17
end_define

begin_comment
comment|/* ega mode F with extended memory */
end_comment

begin_define
define|#
directive|define
name|M_ENH_CG640
value|18
end_define

begin_comment
comment|/* ega mode 10* */
end_comment

begin_define
define|#
directive|define
name|M_ENH_B40x25
value|19
end_define

begin_comment
comment|/* ega enhanced black& white 40 columns */
end_comment

begin_define
define|#
directive|define
name|M_ENH_C40x25
value|20
end_define

begin_comment
comment|/* ega enhanced color 40 columns */
end_comment

begin_define
define|#
directive|define
name|M_ENH_B80x25
value|21
end_define

begin_comment
comment|/* ega enhanced black& white 80 columns */
end_comment

begin_define
define|#
directive|define
name|M_ENH_C80x25
value|22
end_define

begin_comment
comment|/* ega enhanced color 80 columns */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C40x25
value|23
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C80x25
value|24
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M80x25
value|25
end_define

begin_comment
comment|/* vga 8x16 font on mono */
end_comment

begin_define
define|#
directive|define
name|M_VGA11
value|26
end_define

begin_comment
comment|/* vga 640x480 2 colors */
end_comment

begin_define
define|#
directive|define
name|M_BG640x480
value|26
end_define

begin_define
define|#
directive|define
name|M_VGA12
value|27
end_define

begin_comment
comment|/* vga 640x480 16 colors */
end_comment

begin_define
define|#
directive|define
name|M_CG640x480
value|27
end_define

begin_define
define|#
directive|define
name|M_VGA13
value|28
end_define

begin_comment
comment|/* vga 640x200 256 colors */
end_comment

begin_define
define|#
directive|define
name|M_VGA_CG320
value|28
end_define

begin_define
define|#
directive|define
name|M_VGA_C80x50
value|30
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M80x50
value|31
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C80x30
value|32
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M80x30
value|33
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C80x60
value|34
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M80x60
value|35
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_CG640
value|36
end_define

begin_comment
comment|/* vga 640x400 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_MODEX
value|37
end_define

begin_comment
comment|/* vga 320x240 256 color */
end_comment

begin_define
define|#
directive|define
name|M_ENH_B80x43
value|0x70
end_define

begin_comment
comment|/* ega black& white 80x43 */
end_comment

begin_define
define|#
directive|define
name|M_ENH_C80x43
value|0x71
end_define

begin_comment
comment|/* ega color 80x43 */
end_comment

begin_define
define|#
directive|define
name|M_PC98_80x25
value|98
end_define

begin_comment
comment|/* PC98 80x25 */
end_comment

begin_define
define|#
directive|define
name|M_PC98_80x30
value|99
end_define

begin_comment
comment|/* PC98 80x30 */
end_comment

begin_define
define|#
directive|define
name|M_HGC_P0
value|0xe0
end_define

begin_comment
comment|/* hercules graphics - page 0 @ B0000 */
end_comment

begin_define
define|#
directive|define
name|M_HGC_P1
value|0xe1
end_define

begin_comment
comment|/* hercules graphics - page 1 @ B8000 */
end_comment

begin_define
define|#
directive|define
name|M_MCA_MODE
value|0xff
end_define

begin_comment
comment|/* monochrome adapter mode */
end_comment

begin_define
define|#
directive|define
name|M_TEXT_80x25
value|200
end_define

begin_comment
comment|/* generic text modes */
end_comment

begin_define
define|#
directive|define
name|M_TEXT_80x30
value|201
end_define

begin_define
define|#
directive|define
name|M_TEXT_80x43
value|202
end_define

begin_define
define|#
directive|define
name|M_TEXT_80x50
value|203
end_define

begin_define
define|#
directive|define
name|M_TEXT_80x60
value|204
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x25
value|205
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x30
value|206
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x43
value|207
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x50
value|208
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x60
value|209
end_define

begin_define
define|#
directive|define
name|SW_PC98_80x25
value|_IO('S', M_PC98_80x25)
end_define

begin_define
define|#
directive|define
name|SW_PC98_80x30
value|_IO('S', M_PC98_80x30)
end_define

begin_define
define|#
directive|define
name|SW_B40x25
value|_IO('S', M_B40x25)
end_define

begin_define
define|#
directive|define
name|SW_C40x25
value|_IO('S', M_C40x25)
end_define

begin_define
define|#
directive|define
name|SW_B80x25
value|_IO('S', M_B80x25)
end_define

begin_define
define|#
directive|define
name|SW_C80x25
value|_IO('S', M_C80x25)
end_define

begin_define
define|#
directive|define
name|SW_BG320
value|_IO('S', M_BG320)
end_define

begin_define
define|#
directive|define
name|SW_CG320
value|_IO('S', M_CG320)
end_define

begin_define
define|#
directive|define
name|SW_BG640
value|_IO('S', M_BG640)
end_define

begin_define
define|#
directive|define
name|SW_EGAMONO80x25
value|_IO('S', M_EGAMONO80x25)
end_define

begin_define
define|#
directive|define
name|SW_CG320_D
value|_IO('S', M_CG320_D)
end_define

begin_define
define|#
directive|define
name|SW_CG640_E
value|_IO('S', M_CG640_E)
end_define

begin_define
define|#
directive|define
name|SW_EGAMONOAPA
value|_IO('S', M_EGAMONOAPA)
end_define

begin_define
define|#
directive|define
name|SW_CG640x350
value|_IO('S', M_CG640x350)
end_define

begin_define
define|#
directive|define
name|SW_ENH_MONOAPA2
value|_IO('S', M_ENHMONOAPA2)
end_define

begin_define
define|#
directive|define
name|SW_ENH_CG640
value|_IO('S', M_ENH_CG640)
end_define

begin_define
define|#
directive|define
name|SW_ENH_B40x25
value|_IO('S', M_ENH_B40x25)
end_define

begin_define
define|#
directive|define
name|SW_ENH_C40x25
value|_IO('S', M_ENH_C40x25)
end_define

begin_define
define|#
directive|define
name|SW_ENH_B80x25
value|_IO('S', M_ENH_B80x25)
end_define

begin_define
define|#
directive|define
name|SW_ENH_C80x25
value|_IO('S', M_ENH_C80x25)
end_define

begin_define
define|#
directive|define
name|SW_ENH_B80x43
value|_IO('S', M_ENH_B80x43)
end_define

begin_define
define|#
directive|define
name|SW_ENH_C80x43
value|_IO('S', M_ENH_C80x43)
end_define

begin_define
define|#
directive|define
name|SW_MCAMODE
value|_IO('S', M_MCA_MODE)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C40x25
value|_IO('S', M_VGA_C40x25)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C80x25
value|_IO('S', M_VGA_C80x25)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C80x30
value|_IO('S', M_VGA_C80x30)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C80x50
value|_IO('S', M_VGA_C80x50)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C80x60
value|_IO('S', M_VGA_C80x60)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M80x25
value|_IO('S', M_VGA_M80x25)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M80x30
value|_IO('S', M_VGA_M80x30)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M80x50
value|_IO('S', M_VGA_M80x50)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M80x60
value|_IO('S', M_VGA_M80x60)
end_define

begin_define
define|#
directive|define
name|SW_VGA11
value|_IO('S', M_VGA11)
end_define

begin_define
define|#
directive|define
name|SW_BG640x480
value|_IO('S', M_VGA11)
end_define

begin_define
define|#
directive|define
name|SW_VGA12
value|_IO('S', M_VGA12)
end_define

begin_define
define|#
directive|define
name|SW_CG640x480
value|_IO('S', M_VGA12)
end_define

begin_define
define|#
directive|define
name|SW_VGA13
value|_IO('S', M_VGA13)
end_define

begin_define
define|#
directive|define
name|SW_VGA_CG320
value|_IO('S', M_VGA13)
end_define

begin_define
define|#
directive|define
name|SW_VGA_CG640
value|_IO('S', M_VGA_CG640)
end_define

begin_define
define|#
directive|define
name|SW_VGA_MODEX
value|_IO('S', M_VGA_MODEX)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_80x25
value|_IO('S', M_TEXT_80x25)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_80x30
value|_IO('S', M_TEXT_80x30)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_80x43
value|_IO('S', M_TEXT_80x43)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_80x50
value|_IO('S', M_TEXT_80x50)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_80x60
value|_IO('S', M_TEXT_80x60)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_132x25
value|_IO('S', M_TEXT_132x25)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_132x30
value|_IO('S', M_TEXT_132x30)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_132x43
value|_IO('S', M_TEXT_132x43)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_132x50
value|_IO('S', M_TEXT_132x50)
end_define

begin_define
define|#
directive|define
name|SW_TEXT_132x60
value|_IO('S', M_TEXT_132x60)
end_define

begin_define
define|#
directive|define
name|M_VESA_BASE
value|0x100
end_define

begin_comment
comment|/* VESA mode number base */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG640x400
value|0x100
end_define

begin_comment
comment|/* 640x400, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG640x480
value|0x101
end_define

begin_comment
comment|/* 640x480, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_800x600
value|0x102
end_define

begin_comment
comment|/* 800x600, 16 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG800x600
value|0x103
end_define

begin_comment
comment|/* 800x600, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_1024x768
value|0x104
end_define

begin_comment
comment|/* 1024x768, 16 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG1024x768
value|0x105
end_define

begin_comment
comment|/* 1024x768, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_1280x1024
value|0x106
end_define

begin_comment
comment|/* 1280x1024, 16 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG1280x1024
value|0x107
end_define

begin_comment
comment|/* 1280x1024, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C80x60
value|0x108
end_define

begin_comment
comment|/* 8x8 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C132x25
value|0x109
end_define

begin_comment
comment|/* 8x16 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C132x43
value|0x10a
end_define

begin_comment
comment|/* 8x14 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C132x50
value|0x10b
end_define

begin_comment
comment|/* 8x8 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C132x60
value|0x10c
end_define

begin_comment
comment|/* 8x8 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_320
value|0x10d
end_define

begin_comment
comment|/* 320x200, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_320
value|0x10e
end_define

begin_comment
comment|/* 320x200, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_320
value|0x10f
end_define

begin_comment
comment|/* 320x200, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_640
value|0x110
end_define

begin_comment
comment|/* 640x480, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_640
value|0x111
end_define

begin_comment
comment|/* 640x480, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_640
value|0x112
end_define

begin_comment
comment|/* 640x480, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_800
value|0x113
end_define

begin_comment
comment|/* 800x600, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_800
value|0x114
end_define

begin_comment
comment|/* 800x600, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_800
value|0x115
end_define

begin_comment
comment|/* 800x600, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_1024
value|0x116
end_define

begin_comment
comment|/* 1024x768, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_1024
value|0x117
end_define

begin_comment
comment|/* 1024x768, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_1024
value|0x118
end_define

begin_comment
comment|/* 1024x768, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_1280
value|0x119
end_define

begin_comment
comment|/* 1280x1024, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_1280
value|0x11a
end_define

begin_comment
comment|/* 1280x1024, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_1280
value|0x11b
end_define

begin_comment
comment|/* 1280x1024, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_MODE_MAX
value|0x1ff
end_define

begin_define
define|#
directive|define
name|SW_VESA_CG640x400
value|_IO('V', M_VESA_CG640x400 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_CG640x480
value|_IO('V', M_VESA_CG640x480 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_800x600
value|_IO('V', M_VESA_800x600 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_CG800x600
value|_IO('V', M_VESA_CG800x600 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_1024x768
value|_IO('V', M_VESA_1024x768 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_CG1024x768
value|_IO('V', M_VESA_CG1024x768 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_1280x1024
value|_IO('V', M_VESA_1280x1024 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_CG1280x1024
value|_IO('V', M_VESA_CG1280x1024 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_C80x60
value|_IO('V', M_VESA_C80x60 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_C132x25
value|_IO('V', M_VESA_C132x25 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_C132x43
value|_IO('V', M_VESA_C132x43 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_C132x50
value|_IO('V', M_VESA_C132x50 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_C132x60
value|_IO('V', M_VESA_C132x60 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_32K_320
value|_IO('V', M_VESA_32K_320 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_64K_320
value|_IO('V', M_VESA_64K_320 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_FULL_320
value|_IO('V', M_VESA_FULL_320 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_32K_640
value|_IO('V', M_VESA_32K_640 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_64K_640
value|_IO('V', M_VESA_64K_640 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_FULL_640
value|_IO('V', M_VESA_FULL_640 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_32K_800
value|_IO('V', M_VESA_32K_800 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_64K_800
value|_IO('V', M_VESA_64K_800 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_FULL_800
value|_IO('V', M_VESA_FULL_800 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_32K_1024
value|_IO('V', M_VESA_32K_1024 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_64K_1024
value|_IO('V', M_VESA_64K_1024 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_FULL_1024
value|_IO('V', M_VESA_FULL_1024 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_32K_1280
value|_IO('V', M_VESA_32K_1280 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_64K_1280
value|_IO('V', M_VESA_64K_1280 - M_VESA_BASE)
end_define

begin_define
define|#
directive|define
name|SW_VESA_FULL_1280
value|_IO('V', M_VESA_FULL_1280 - M_VESA_BASE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CONSOLE_H_ */
end_comment

end_unit

