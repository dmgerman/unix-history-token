begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991-1996 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CONSIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CONSIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
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

begin_comment
comment|/*  * Console ioctl commands.  Some commands are named as KDXXXX, GIO_XXX, and  * PIO_XXX, rather than CONS_XXX, for historical and compatibility reasons.  * Some other CONS_XXX commands are works as wrapper around frame buffer   * ioctl commands FBIO_XXX.  Do not try to change all these commands,   * otherwise we shall have compatibility problems.  */
end_comment

begin_comment
comment|/* get/set video mode */
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
name|KD_GRAPHICS
value|1
end_define

begin_comment
comment|/* set graphics mode 		*/
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
name|KD_PIXEL
value|3
end_define

begin_comment
comment|/* set pixel mode		*/
end_comment

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

begin_comment
comment|/* set border color */
end_comment

begin_define
define|#
directive|define
name|KDSBORDER
value|_IO('K', 13
comment|/*, int */
value|)
end_define

begin_comment
comment|/* set up raster(pixel) text mode */
end_comment

begin_struct
struct|struct
name|scr_size
block|{
name|int
name|scr_size
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scr_size
name|scr_size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KDRASTER
value|_IOW('K', 100, scr_size_t)
end_define

begin_comment
comment|/* get/set screen char map */
end_comment

begin_struct
struct|struct
name|scrmap
block|{
name|char
name|scrmap
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scrmap
name|scrmap_t
typedef|;
end_typedef

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

begin_comment
comment|/* get the current text attribute */
end_comment

begin_define
define|#
directive|define
name|GIO_ATTR
value|_IOR('a', 0, int)
end_define

begin_comment
comment|/* get the current text color */
end_comment

begin_define
define|#
directive|define
name|GIO_COLOR
value|_IOR('c', 0, int)
end_define

begin_comment
comment|/* get the adapter type (equivalent to FBIO_ADPTYPE) */
end_comment

begin_define
define|#
directive|define
name|CONS_CURRENT
value|_IOR('c', 1, int)
end_define

begin_comment
comment|/* get the current video mode (equivalent to FBIO_GETMODE) */
end_comment

begin_define
define|#
directive|define
name|CONS_GET
value|_IOR('c', 2, int)
end_define

begin_comment
comment|/* not supported? */
end_comment

begin_define
define|#
directive|define
name|CONS_IO
value|_IO('c', 3)
end_define

begin_comment
comment|/* set blank time interval */
end_comment

begin_define
define|#
directive|define
name|CONS_BLANKTIME
value|_IOW('c', 4, int)
end_define

begin_comment
comment|/* set/get the screen saver (these ioctls are current noop) */
end_comment

begin_struct
struct|struct
name|ssaver
block|{
define|#
directive|define
name|MAXSSAVER
value|16
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
name|ssaver
name|ssaver_t
typedef|;
end_typedef

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

begin_comment
comment|/* set the text cursor type (obsolete, see CONS_CURSORSHAPE below) */
end_comment

begin_comment
comment|/* #define CONS_BLINK_CURSOR (1<< 0) #define CONS_CHAR_CURSOR (1<< 1) */
end_comment

begin_define
define|#
directive|define
name|CONS_CURSORTYPE
value|_IOW('c', 7, int)
end_define

begin_comment
comment|/* set the bell type to audible or visual */
end_comment

begin_define
define|#
directive|define
name|CONS_VISUAL_BELL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CONS_QUIET_BELL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CONS_BELLTYPE
value|_IOW('c', 8, int)
end_define

begin_comment
comment|/* set the history (scroll back) buffer size (in lines) */
end_comment

begin_define
define|#
directive|define
name|CONS_HISTORY
value|_IOW('c', 9, int)
end_define

begin_comment
comment|/* clear the history (scroll back) buffer */
end_comment

begin_define
define|#
directive|define
name|CONS_CLRHIST
value|_IO('c', 10)
end_define

begin_comment
comment|/* mouse cursor ioctl */
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

begin_typedef
typedef|typedef
name|struct
name|mouse_data
name|mouse_data_t
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|struct
name|mouse_mode
name|mouse_mode_t
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|struct
name|mouse_event
name|mouse_event_t
typedef|;
end_typedef

begin_struct
struct|struct
name|mouse_info
block|{
name|int
name|operation
decl_stmt|;
define|#
directive|define
name|MOUSE_SHOW
value|0x01
define|#
directive|define
name|MOUSE_HIDE
value|0x02
define|#
directive|define
name|MOUSE_MOVEABS
value|0x03
define|#
directive|define
name|MOUSE_MOVEREL
value|0x04
define|#
directive|define
name|MOUSE_GETINFO
value|0x05
define|#
directive|define
name|MOUSE_MODE
value|0x06
define|#
directive|define
name|MOUSE_ACTION
value|0x07
define|#
directive|define
name|MOUSE_MOTION_EVENT
value|0x08
define|#
directive|define
name|MOUSE_BUTTON_EVENT
value|0x09
define|#
directive|define
name|MOUSE_MOUSECHAR
value|0x0a
union|union
block|{
name|mouse_data_t
name|data
decl_stmt|;
name|mouse_mode_t
name|mode
decl_stmt|;
name|mouse_event_t
name|event
decl_stmt|;
name|int
name|mouse_char
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mouse_info
name|mouse_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CONS_MOUSECTL
value|_IOWR('c', 10, mouse_info_t)
end_define

begin_comment
comment|/* see if the vty has been idle */
end_comment

begin_define
define|#
directive|define
name|CONS_IDLE
value|_IOR('c', 11, int)
end_define

begin_comment
comment|/* set the screen saver mode */
end_comment

begin_define
define|#
directive|define
name|CONS_NO_SAVER
value|(-1)
end_define

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

begin_define
define|#
directive|define
name|CONS_SAVERMODE
value|_IOW('c', 12, int)
end_define

begin_comment
comment|/* start the screen saver */
end_comment

begin_define
define|#
directive|define
name|CONS_SAVERSTART
value|_IOW('c', 13, int)
end_define

begin_comment
comment|/* set the text cursor shape (see also CONS_CURSORTYPE above) */
end_comment

begin_define
define|#
directive|define
name|CONS_BLINK_CURSOR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CONS_CHAR_CURSOR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CONS_HIDDEN_CURSOR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CONS_CURSOR_ATTRS
value|(CONS_BLINK_CURSOR | CONS_CHAR_CURSOR |	\ 				 CONS_HIDDEN_CURSOR)
end_define

begin_define
define|#
directive|define
name|CONS_RESET_CURSOR
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|CONS_LOCAL_CURSOR
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|CONS_CURSOR_FLAGS
value|(CONS_RESET_CURSOR | CONS_LOCAL_CURSOR)
end_define

begin_struct
struct|struct
name|cshape
block|{
comment|/* shape[0]: flags, shape[1]: base, shape[2]: height */
name|int
name|shape
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CONS_GETCURSORSHAPE
value|_IOWR('c', 14, struct cshape)
end_define

begin_define
define|#
directive|define
name|CONS_SETCURSORSHAPE
value|_IOW('c', 15, struct cshape)
end_define

begin_comment
comment|/* set/get font data */
end_comment

begin_struct
struct|struct
name|fnt8
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
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fnt8
name|fnt8_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fnt14
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
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fnt14
name|fnt14_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fnt16
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
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fnt16
name|fnt16_t
typedef|;
end_typedef

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

begin_comment
comment|/* get video mode information */
end_comment

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
name|font_size
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

begin_typedef
typedef|typedef
name|struct
name|vid_info
name|vid_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CONS_GETINFO
value|_IOWR('c', 73, vid_info_t)
end_define

begin_comment
comment|/* get version */
end_comment

begin_define
define|#
directive|define
name|CONS_GETVERS
value|_IOR('c', 74, int)
end_define

begin_comment
comment|/* get the video adapter index (equivalent to FBIO_ADAPTER) */
end_comment

begin_define
define|#
directive|define
name|CONS_CURRENTADP
value|_IOR('c', 100, int)
end_define

begin_comment
comment|/* get the video adapter information (equivalent to FBIO_ADPINFO) */
end_comment

begin_define
define|#
directive|define
name|CONS_ADPINFO
value|_IOWR('c', 101, video_adapter_info_t)
end_define

begin_comment
comment|/* get the video mode information (equivalent to FBIO_MODEINFO) */
end_comment

begin_define
define|#
directive|define
name|CONS_MODEINFO
value|_IOWR('c', 102, video_info_t)
end_define

begin_comment
comment|/* find a video mode (equivalent to FBIO_FINDMODE) */
end_comment

begin_define
define|#
directive|define
name|CONS_FINDMODE
value|_IOWR('c', 103, video_info_t)
end_define

begin_comment
comment|/* set the frame buffer window origin (equivalent to FBIO_SETWINORG) */
end_comment

begin_define
define|#
directive|define
name|CONS_SETWINORG
value|_IO('c', 104
comment|/*, u_int */
value|)
end_define

begin_comment
comment|/* use the specified keyboard */
end_comment

begin_define
define|#
directive|define
name|CONS_SETKBD
value|_IO('c', 110
comment|/*, int */
value|)
end_define

begin_comment
comment|/* release the current keyboard */
end_comment

begin_define
define|#
directive|define
name|CONS_RELKBD
value|_IO('c', 111)
end_define

begin_struct
struct|struct
name|scrshot
block|{
name|int
name|xsize
decl_stmt|;
name|int
name|ysize
decl_stmt|;
name|u_int16_t
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scrshot
name|scrshot_t
typedef|;
end_typedef

begin_comment
comment|/* Snapshot the current video buffer */
end_comment

begin_define
define|#
directive|define
name|CONS_SCRSHOT
value|_IOWR('c', 105, scrshot_t)
end_define

begin_comment
comment|/* get/set the current terminal emulator info. */
end_comment

begin_define
define|#
directive|define
name|TI_NAME_LEN
value|32
end_define

begin_define
define|#
directive|define
name|TI_DESC_LEN
value|64
end_define

begin_struct
struct|struct
name|term_info
block|{
name|int
name|ti_index
decl_stmt|;
name|int
name|ti_flags
decl_stmt|;
name|u_char
name|ti_name
index|[
name|TI_NAME_LEN
index|]
decl_stmt|;
name|u_char
name|ti_desc
index|[
name|TI_DESC_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|term_info
name|term_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CONS_GETTERM
value|_IOWR('c', 112, term_info_t)
end_define

begin_define
define|#
directive|define
name|CONS_SETTERM
value|_IOW('c', 113, term_info_t)
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

begin_comment
comment|/*  * Vty switching ioctl commands.  */
end_comment

begin_comment
comment|/* get the next available vty */
end_comment

begin_define
define|#
directive|define
name|VT_OPENQRY
value|_IOR('v', 1, int)
end_define

begin_comment
comment|/* set/get vty switching mode */
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
define|#
directive|define
name|VT_AUTO
value|0
comment|/* switching is automatic 	*/
define|#
directive|define
name|VT_PROCESS
value|1
comment|/* switching controlled by prog */
define|#
directive|define
name|VT_KERNEL
value|255
comment|/* switching controlled in kernel */
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
name|VT_SETMODE
value|_IOW('v', 2, vtmode_t)
end_define

begin_define
define|#
directive|define
name|VT_GETMODE
value|_IOR('v', 3, vtmode_t)
end_define

begin_comment
comment|/* acknowledge release or acquisition of a vty */
end_comment

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
name|VT_RELDISP
value|_IO('v', 4
comment|/*, int */
value|)
end_define

begin_comment
comment|/* activate the specified vty */
end_comment

begin_define
define|#
directive|define
name|VT_ACTIVATE
value|_IO('v', 5
comment|/*, int */
value|)
end_define

begin_comment
comment|/* wait until the specified vty is activate */
end_comment

begin_define
define|#
directive|define
name|VT_WAITACTIVE
value|_IO('v', 6
comment|/*, int */
value|)
end_define

begin_comment
comment|/* get the currently active vty */
end_comment

begin_define
define|#
directive|define
name|VT_GETACTIVE
value|_IOR('v', 7, int)
end_define

begin_comment
comment|/* get the index of the vty */
end_comment

begin_define
define|#
directive|define
name|VT_GETINDEX
value|_IOR('v', 8, int)
end_define

begin_comment
comment|/*  * Video mode switching ioctl.  See sys/fbio.h for mode numbers.  */
end_comment

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
name|SW_PC98_EGC640x400
value|_IO('S', M_PC98_EGC640x400)
end_define

begin_define
define|#
directive|define
name|SW_PC98_PEGC640x400
value|_IO('S', M_PC98_PEGC640x400)
end_define

begin_define
define|#
directive|define
name|SW_PC98_PEGC640x480
value|_IO('S', M_PC98_PEGC640x480)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C90x25
value|_IO('S', M_VGA_C90x25)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M90x25
value|_IO('S', M_VGA_M90x25)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C90x30
value|_IO('S', M_VGA_C90x30)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M90x30
value|_IO('S', M_VGA_M90x30)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C90x43
value|_IO('S', M_VGA_C90x43)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M90x43
value|_IO('S', M_VGA_M90x43)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C90x50
value|_IO('S', M_VGA_C90x50)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M90x50
value|_IO('S', M_VGA_M90x50)
end_define

begin_define
define|#
directive|define
name|SW_VGA_C90x60
value|_IO('S', M_VGA_C90x60)
end_define

begin_define
define|#
directive|define
name|SW_VGA_M90x60
value|_IO('S', M_VGA_M90x60)
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
comment|/* !_SYS_CONSIO_H_ */
end_comment

end_unit

