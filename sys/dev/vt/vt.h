begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Ed Schouten under sponsorship from the  * FreeBSD Foundation.  *  * Portions of this software were developed by Oleksandr Rybalko  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_VT_VT_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_VT_VT_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/consio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mouse.h>
end_include

begin_include
include|#
directive|include
file|<sys/terminal.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|"opt_syscons.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|VT_MAXWINDOWS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXCONS
end_ifdef

begin_define
define|#
directive|define
name|VT_MAXWINDOWS
value|MAXCONS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VT_MAXWINDOWS
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VT_ALT_TO_ESC_HACK
end_ifndef

begin_define
define|#
directive|define
name|VT_ALT_TO_ESC_HACK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VT_CONSWINDOW
value|0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SC_TWOBUTTON_MOUSE
argument_list|)
operator|||
name|defined
argument_list|(
name|VT_TWOBUTTON_MOUSE
argument_list|)
end_if

begin_define
define|#
directive|define
name|VT_MOUSE_PASTEBUTTON
value|MOUSE_BUTTON3DOWN
end_define

begin_comment
comment|/* right button */
end_comment

begin_define
define|#
directive|define
name|VT_MOUSE_EXTENDBUTTON
value|MOUSE_BUTTON2DOWN
end_define

begin_comment
comment|/* not really used */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VT_MOUSE_PASTEBUTTON
value|MOUSE_BUTTON2DOWN
end_define

begin_comment
comment|/* middle button */
end_comment

begin_define
define|#
directive|define
name|VT_MOUSE_EXTENDBUTTON
value|MOUSE_BUTTON3DOWN
end_define

begin_comment
comment|/* right button */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(SC_TWOBUTTON_MOUSE) || defined(VT_TWOBUTTON_MOUSE) */
end_comment

begin_define
define|#
directive|define
name|SC_DRIVER_NAME
value|"vt"
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|_l
parameter_list|,
modifier|...
parameter_list|)
value|if (vt_debug> (_l)) printf( __VA_ARGS__ )
end_define

begin_define
define|#
directive|define
name|ISSIGVALID
parameter_list|(
name|sig
parameter_list|)
value|((sig)> 0&& (sig)< NSIG)
end_define

begin_define
define|#
directive|define
name|VT_SYSCTL_INT
parameter_list|(
name|_name
parameter_list|,
name|_default
parameter_list|,
name|_descr
parameter_list|)
define|\
value|static int vt_##_name = _default;					\ SYSCTL_INT(_kern_vt, OID_AUTO, _name, CTLFLAG_RW,&vt_##_name, _default,\ 		_descr);						\ TUNABLE_INT("kern.vt." #_name,&vt_##_name);
end_define

begin_struct_decl
struct_decl|struct
name|vt_driver
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|vt_allocate
parameter_list|(
name|struct
name|vt_driver
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_resume
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|unsigned
name|int
name|vt_axis_t
typedef|;
end_typedef

begin_comment
comment|/*  * List of locks  * (d)	locked by vd_lock  * (b)	locked by vb_lock  * (G)	locked by Giant  * (u)	unlocked, locked by higher levels  * (c)	const until freeing  * (?)	yet to be determined  */
end_comment

begin_comment
comment|/*  * Per-device datastructure.  */
end_comment

begin_struct
struct|struct
name|vt_device
block|{
name|struct
name|vt_window
modifier|*
name|vd_windows
index|[
name|VT_MAXWINDOWS
index|]
decl_stmt|;
comment|/* (c) Windows. */
name|struct
name|vt_window
modifier|*
name|vd_curwindow
decl_stmt|;
comment|/* (d) Current window. */
name|struct
name|vt_window
modifier|*
name|vd_savedwindow
decl_stmt|;
comment|/* (?) Saved for suspend. */
name|struct
name|vt_window
modifier|*
name|vd_markedwin
decl_stmt|;
comment|/* (?) Copy/paste buf owner. */
specifier|const
name|struct
name|vt_driver
modifier|*
name|vd_driver
decl_stmt|;
comment|/* (c) Graphics driver. */
name|void
modifier|*
name|vd_softc
decl_stmt|;
comment|/* (u) Driver data. */
name|uint16_t
name|vd_mx
decl_stmt|;
comment|/* (?) Mouse X. */
name|uint16_t
name|vd_my
decl_stmt|;
comment|/* (?) Mouse Y. */
name|vt_axis_t
name|vd_mdirtyx
decl_stmt|;
comment|/* (?) Screen width. */
name|vt_axis_t
name|vd_mdirtyy
decl_stmt|;
comment|/* (?) Screen height. */
name|uint32_t
name|vd_mstate
decl_stmt|;
comment|/* (?) Mouse state. */
name|term_pos_t
name|vd_offset
decl_stmt|;
comment|/* (?) Pixel offset. */
name|vt_axis_t
name|vd_width
decl_stmt|;
comment|/* (?) Screen width. */
name|vt_axis_t
name|vd_height
decl_stmt|;
comment|/* (?) Screen height. */
name|struct
name|mtx
name|vd_lock
decl_stmt|;
comment|/* Per-device lock. */
name|struct
name|cv
name|vd_winswitch
decl_stmt|;
comment|/* (d) Window switch notify. */
name|struct
name|callout
name|vd_timer
decl_stmt|;
comment|/* (d) Display timer. */
name|int
name|vd_flags
decl_stmt|;
comment|/* (d) Device flags. */
define|#
directive|define
name|VDF_TEXTMODE
value|0x01
comment|/* Do text mode rendering. */
define|#
directive|define
name|VDF_SPLASH
value|0x02
comment|/* Splash screen active. */
define|#
directive|define
name|VDF_ASYNC
value|0x04
comment|/* vt_timer() running. */
define|#
directive|define
name|VDF_INVALID
value|0x08
comment|/* Entire screen should be re-rendered. */
define|#
directive|define
name|VDF_DEAD
value|0x10
comment|/* Early probing found nothing. */
define|#
directive|define
name|VDF_INITIALIZED
value|0x20
comment|/* vtterm_cnprobe already done. */
define|#
directive|define
name|VDF_MOUSECURSOR
value|0x40
comment|/* Mouse cursor visible. */
name|int
name|vd_keyboard
decl_stmt|;
comment|/* (G) Keyboard index. */
name|unsigned
name|int
name|vd_kbstate
decl_stmt|;
comment|/* (?) Device unit. */
name|unsigned
name|int
name|vd_unit
decl_stmt|;
comment|/* (c) Device unit. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-window terminal screen buffer.  *  * Because redrawing is performed asynchronously, the buffer keeps track  * of a rectangle that needs to be redrawn (vb_dirtyrect).  Because this  * approach seemed to cause suboptimal performance (when the top left  * and the bottom right of the screen are modified), it also uses a set  * of bitmasks to keep track of the rows and columns (mod 64) that have  * been modified.  */
end_comment

begin_struct
struct|struct
name|vt_bufmask
block|{
name|uint64_t
name|vbm_row
decl_stmt|,
name|vbm_col
decl_stmt|;
define|#
directive|define
name|VBM_DIRTY
value|UINT64_MAX
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vt_buf
block|{
name|struct
name|mtx
name|vb_lock
decl_stmt|;
comment|/* Buffer lock. */
name|term_pos_t
name|vb_scr_size
decl_stmt|;
comment|/* (b) Screen dimensions. */
name|int
name|vb_flags
decl_stmt|;
comment|/* (b) Flags. */
define|#
directive|define
name|VBF_CURSOR
value|0x1
comment|/* Cursor visible. */
define|#
directive|define
name|VBF_STATIC
value|0x2
comment|/* Buffer is statically allocated. */
define|#
directive|define
name|VBF_MTX_INIT
value|0x4
comment|/* Mutex initialized. */
define|#
directive|define
name|VBF_SCROLL
value|0x8
comment|/* scroll locked mode. */
define|#
directive|define
name|VBF_HISTORY_FULL
value|0x10
comment|/* All rows filled. */
name|int
name|vb_history_size
decl_stmt|;
define|#
directive|define
name|VBF_DEFAULT_HISTORY_SIZE
value|500
name|int
name|vb_roffset
decl_stmt|;
comment|/* (b) History rows offset. */
name|int
name|vb_curroffset
decl_stmt|;
comment|/* (b) Saved rows offset. */
name|term_pos_t
name|vb_cursor
decl_stmt|;
comment|/* (u) Cursor position. */
name|term_pos_t
name|vb_mark_start
decl_stmt|;
comment|/* (b) Copy region start. */
name|term_pos_t
name|vb_mark_end
decl_stmt|;
comment|/* (b) Copy region end. */
name|int
name|vb_mark_last
decl_stmt|;
comment|/* Last mouse event. */
name|term_rect_t
name|vb_dirtyrect
decl_stmt|;
comment|/* (b) Dirty rectangle. */
name|struct
name|vt_bufmask
name|vb_dirtymask
decl_stmt|;
comment|/* (b) Dirty bitmasks. */
name|term_char_t
modifier|*
name|vb_buffer
decl_stmt|;
comment|/* (u) Data buffer. */
name|term_char_t
modifier|*
modifier|*
name|vb_rows
decl_stmt|;
comment|/* (u) Array of rows */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|vtbuf_copy
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
specifier|const
name|term_rect_t
modifier|*
parameter_list|,
specifier|const
name|term_pos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_fill_locked
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
specifier|const
name|term_rect_t
modifier|*
parameter_list|,
name|term_char_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_init_early
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_init
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
specifier|const
name|term_pos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_grow
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
specifier|const
name|term_pos_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_putchar
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
specifier|const
name|term_pos_t
modifier|*
parameter_list|,
name|term_char_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_cursor_position
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
specifier|const
name|term_pos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_mouse_cursor_position
parameter_list|(
name|struct
name|vt_buf
modifier|*
name|vb
parameter_list|,
name|int
name|col
parameter_list|,
name|int
name|row
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_cursor_visibility
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_scroll_mode
parameter_list|(
name|struct
name|vt_buf
modifier|*
name|vb
parameter_list|,
name|int
name|yes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_undirty
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
name|term_rect_t
modifier|*
parameter_list|,
name|struct
name|vt_bufmask
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_sethistory_size
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vtbuf_set_mark
parameter_list|(
name|struct
name|vt_buf
modifier|*
name|vb
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|col
parameter_list|,
name|int
name|row
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vtbuf_iscursor
parameter_list|(
name|struct
name|vt_buf
modifier|*
name|vb
parameter_list|,
name|int
name|row
parameter_list|,
name|int
name|col
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vtbuf_get_marked_len
parameter_list|(
name|struct
name|vt_buf
modifier|*
name|vb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtbuf_extract_marked
parameter_list|(
name|struct
name|vt_buf
modifier|*
name|vb
parameter_list|,
name|term_char_t
modifier|*
name|buf
parameter_list|,
name|int
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VTB_MARK_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VTB_MARK_END
value|1
end_define

begin_define
define|#
directive|define
name|VTB_MARK_START
value|2
end_define

begin_define
define|#
directive|define
name|VTB_MARK_WORD
value|3
end_define

begin_define
define|#
directive|define
name|VTB_MARK_ROW
value|4
end_define

begin_define
define|#
directive|define
name|VTB_MARK_EXTEND
value|5
end_define

begin_define
define|#
directive|define
name|VTB_MARK_MOVE
value|6
end_define

begin_define
define|#
directive|define
name|VTBUF_SLCK_ENABLE
parameter_list|(
name|vb
parameter_list|)
value|vtbuf_scroll_mode((vb), 1)
end_define

begin_define
define|#
directive|define
name|VTBUF_SLCK_DISABLE
parameter_list|(
name|vb
parameter_list|)
value|vtbuf_scroll_mode((vb), 0)
end_define

begin_define
define|#
directive|define
name|VTBUF_MAX_HEIGHT
parameter_list|(
name|vb
parameter_list|)
define|\
value|((vb)->vb_history_size)
end_define

begin_define
define|#
directive|define
name|VTBUF_GET_ROW
parameter_list|(
name|vb
parameter_list|,
name|r
parameter_list|)
define|\
value|((vb)->vb_rows[((vb)->vb_roffset + (r)) % VTBUF_MAX_HEIGHT(vb)])
end_define

begin_define
define|#
directive|define
name|VTBUF_GET_FIELD
parameter_list|(
name|vb
parameter_list|,
name|r
parameter_list|,
name|c
parameter_list|)
define|\
value|((vb)->vb_rows[((vb)->vb_roffset + (r)) % VTBUF_MAX_HEIGHT(vb)][(c)])
end_define

begin_define
define|#
directive|define
name|VTBUF_FIELD
parameter_list|(
name|vb
parameter_list|,
name|r
parameter_list|,
name|c
parameter_list|)
define|\
value|((vb)->vb_rows[((vb)->vb_curroffset + (r)) % VTBUF_MAX_HEIGHT(vb)][(c)])
end_define

begin_define
define|#
directive|define
name|VTBUF_ISCURSOR
parameter_list|(
name|vb
parameter_list|,
name|r
parameter_list|,
name|c
parameter_list|)
define|\
value|vtbuf_iscursor((vb), (r), (c))
end_define

begin_define
define|#
directive|define
name|VTBUF_DIRTYROW
parameter_list|(
name|mask
parameter_list|,
name|row
parameter_list|)
define|\
value|((mask)->vbm_row& ((uint64_t)1<< ((row) % 64)))
end_define

begin_define
define|#
directive|define
name|VTBUF_DIRTYCOL
parameter_list|(
name|mask
parameter_list|,
name|col
parameter_list|)
define|\
value|((mask)->vbm_col& ((uint64_t)1<< ((col) % 64)))
end_define

begin_define
define|#
directive|define
name|VTBUF_SPACE_CHAR
value|(' ' | TC_WHITE<< 26 | TC_BLACK<< 29)
end_define

begin_define
define|#
directive|define
name|VHS_SET
value|0
end_define

begin_define
define|#
directive|define
name|VHS_CUR
value|1
end_define

begin_define
define|#
directive|define
name|VHS_END
value|2
end_define

begin_function_decl
name|int
name|vthistory_seek
parameter_list|(
name|struct
name|vt_buf
modifier|*
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vthistory_addlines
parameter_list|(
name|struct
name|vt_buf
modifier|*
name|vb
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vthistory_getpos
parameter_list|(
specifier|const
name|struct
name|vt_buf
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Per-window datastructure.  */
end_comment

begin_struct
struct|struct
name|vt_window
block|{
name|struct
name|vt_device
modifier|*
name|vw_device
decl_stmt|;
comment|/* (c) Device. */
name|struct
name|terminal
modifier|*
name|vw_terminal
decl_stmt|;
comment|/* (c) Terminal. */
name|struct
name|vt_buf
name|vw_buf
decl_stmt|;
comment|/* (u) Screen buffer. */
name|struct
name|vt_font
modifier|*
name|vw_font
decl_stmt|;
comment|/* (d) Graphical font. */
name|unsigned
name|int
name|vw_number
decl_stmt|;
comment|/* (c) Window number. */
name|int
name|vw_kbdmode
decl_stmt|;
comment|/* (?) Keyboard mode. */
name|char
modifier|*
name|vw_kbdsq
decl_stmt|;
comment|/* Escape sequence queue*/
name|unsigned
name|int
name|vw_flags
decl_stmt|;
comment|/* (d) Per-window flags. */
define|#
directive|define
name|VWF_BUSY
value|0x1
comment|/* Busy reconfiguring device. */
define|#
directive|define
name|VWF_OPENED
value|0x2
comment|/* TTY in use. */
define|#
directive|define
name|VWF_SCROLL
value|0x4
comment|/* Keys influence scrollback. */
define|#
directive|define
name|VWF_CONSOLE
value|0x8
comment|/* Kernel message console window. */
define|#
directive|define
name|VWF_VTYLOCK
value|0x10
comment|/* Prevent window switch. */
define|#
directive|define
name|VWF_MOUSE_HIDE
value|0x20
comment|/* Disable mouse events processing. */
define|#
directive|define
name|VWF_SWWAIT_REL
value|0x10000
comment|/* Program wait for VT acquire is done. */
define|#
directive|define
name|VWF_SWWAIT_ACQ
value|0x20000
comment|/* Program wait for VT release is done. */
name|pid_t
name|vw_pid
decl_stmt|;
comment|/* Terminal holding process */
name|struct
name|proc
modifier|*
name|vw_proc
decl_stmt|;
name|struct
name|vt_mode
name|vw_smode
decl_stmt|;
comment|/* switch mode */
name|struct
name|callout
name|vw_proc_dead_timer
decl_stmt|;
name|struct
name|vt_window
modifier|*
name|vw_switch_to
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VT_AUTO
value|0
end_define

begin_comment
comment|/* switching is automatic */
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

begin_define
define|#
directive|define
name|IS_VT_PROC_MODE
parameter_list|(
name|vw
parameter_list|)
value|((vw)->vw_smode.mode == VT_PROCESS)
end_define

begin_comment
comment|/*  * Per-device driver routines.  *  * vd_bitbltchr is used when the driver operates in graphics mode, while  * vd_putchar is used when the driver operates in text mode  * (VDF_TEXTMODE).  */
end_comment

begin_typedef
typedef|typedef
name|int
name|vd_init_t
parameter_list|(
name|struct
name|vt_device
modifier|*
name|vd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vd_postswitch_t
parameter_list|(
name|struct
name|vt_device
modifier|*
name|vd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vd_blank_t
parameter_list|(
name|struct
name|vt_device
modifier|*
name|vd
parameter_list|,
name|term_color_t
name|color
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vd_bitbltchr_t
parameter_list|(
name|struct
name|vt_device
modifier|*
name|vd
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|src
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|mask
parameter_list|,
name|int
name|bpl
parameter_list|,
name|vt_axis_t
name|top
parameter_list|,
name|vt_axis_t
name|left
parameter_list|,
name|unsigned
name|int
name|width
parameter_list|,
name|unsigned
name|int
name|height
parameter_list|,
name|term_color_t
name|fg
parameter_list|,
name|term_color_t
name|bg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vd_putchar_t
parameter_list|(
name|struct
name|vt_device
modifier|*
name|vd
parameter_list|,
name|term_char_t
parameter_list|,
name|vt_axis_t
name|top
parameter_list|,
name|vt_axis_t
name|left
parameter_list|,
name|term_color_t
name|fg
parameter_list|,
name|term_color_t
name|bg
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|vt_driver
block|{
comment|/* Console attachment. */
name|vd_init_t
modifier|*
name|vd_init
decl_stmt|;
comment|/* Drawing. */
name|vd_blank_t
modifier|*
name|vd_blank
decl_stmt|;
name|vd_bitbltchr_t
modifier|*
name|vd_bitbltchr
decl_stmt|;
comment|/* Text mode operation. */
name|vd_putchar_t
modifier|*
name|vd_putchar
decl_stmt|;
comment|/* Update display setting on vt switch. */
name|vd_postswitch_t
modifier|*
name|vd_postswitch
decl_stmt|;
comment|/* Priority to know which one can override */
name|int
name|vd_priority
decl_stmt|;
define|#
directive|define
name|VD_PRIORITY_DUMB
value|10
define|#
directive|define
name|VD_PRIORITY_GENERIC
value|100
define|#
directive|define
name|VD_PRIORITY_SPECIFIC
value|1000
block|}
struct|;
end_struct

begin_comment
comment|/*  * Console device madness.  *  * Utility macro to make early vt(4) instances work.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|terminal_class
name|vt_termclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|vt_upgrade
parameter_list|(
name|struct
name|vt_device
modifier|*
name|vd
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PIXEL_WIDTH
parameter_list|(
name|w
parameter_list|)
value|((w) / 8)
end_define

begin_define
define|#
directive|define
name|PIXEL_HEIGHT
parameter_list|(
name|h
parameter_list|)
value|((h) / 16)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|VT_FB_DEFAULT_WIDTH
end_ifndef

begin_define
define|#
directive|define
name|VT_FB_DEFAULT_WIDTH
value|640
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VT_FB_DEFAULT_HEIGHT
end_ifndef

begin_define
define|#
directive|define
name|VT_FB_DEFAULT_HEIGHT
value|480
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VT_CONSDEV_DECLARE
parameter_list|(
name|driver
parameter_list|,
name|width
parameter_list|,
name|height
parameter_list|,
name|softc
parameter_list|)
define|\
value|static struct terminal	driver ## _consterm;				\ static struct vt_window	driver ## _conswindow;				\ static struct vt_device	driver ## _consdev = {				\ 	.vd_driver =&driver,						\ 	.vd_softc = (softc),						\ 	.vd_flags = VDF_INVALID,					\ 	.vd_windows = { [VT_CONSWINDOW] =&driver ## _conswindow, },	\ 	.vd_curwindow =&driver ## _conswindow,				\ 	.vd_markedwin = NULL,						\ 	.vd_kbstate = 0,						\ };									\ static term_char_t	driver ## _constextbuf[(width) * 		\ 	    (VBF_DEFAULT_HISTORY_SIZE)];				\ static term_char_t	*driver ## _constextbufrows[			\ 	    VBF_DEFAULT_HISTORY_SIZE];					\ static struct vt_window	driver ## _conswindow = {			\ 	.vw_number = VT_CONSWINDOW,					\ 	.vw_flags = VWF_CONSOLE,					\ 	.vw_buf = {							\ 		.vb_buffer = driver ## _constextbuf,			\ 		.vb_rows = driver ## _constextbufrows,			\ 		.vb_history_size = VBF_DEFAULT_HISTORY_SIZE,		\ 		.vb_curroffset = 0,					\ 		.vb_roffset = 0,					\ 		.vb_flags = VBF_STATIC,					\ 		.vb_mark_start = {					\ 			.tp_row = 0,					\ 			.tp_col = 0,					\ 		},							\ 		.vb_mark_end = {					\ 			.tp_row = 0,					\ 			.tp_col = 0,					\ 		},							\ 		.vb_scr_size = {					\ 			.tp_row = height,				\ 			.tp_col = width,				\ 		},							\ 	},								\ 	.vw_device =&driver ## _consdev,				\ 	.vw_terminal =&driver ## _consterm,				\ 	.vw_kbdmode = K_XLATE,						\ };									\ TERMINAL_DECLARE_EARLY(driver ## _consterm, vt_termclass,		\&driver ## _conswindow);						\ SYSINIT(vt_early_cons, SI_SUB_INT_CONFIG_HOOKS, SI_ORDER_ANY,		\     vt_upgrade,&driver ## _consdev)
end_define

begin_comment
comment|/*  * Fonts.  *  * Remapping tables are used to map Unicode points to glyphs.  They need  * to be sorted, because vtfont_lookup() performs a binary search.  Each  * font has two remapping tables, for normal and bold.  When a character  * is not present in bold, it uses a normal glyph.  When no glyph is  * available, it uses glyph 0, which is normally equal to U+FFFD.  */
end_comment

begin_struct
struct|struct
name|vt_font_map
block|{
name|uint32_t
name|vfm_src
decl_stmt|;
name|uint16_t
name|vfm_dst
decl_stmt|;
name|uint16_t
name|vfm_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vt_font
block|{
name|struct
name|vt_font_map
modifier|*
name|vf_bold
decl_stmt|;
name|struct
name|vt_font_map
modifier|*
name|vf_normal
decl_stmt|;
name|uint8_t
modifier|*
name|vf_bytes
decl_stmt|;
name|unsigned
name|int
name|vf_height
decl_stmt|,
name|vf_width
decl_stmt|,
name|vf_normal_length
decl_stmt|,
name|vf_bold_length
decl_stmt|;
name|unsigned
name|int
name|vf_refcount
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mouse_cursor
block|{
name|uint8_t
name|map
index|[
literal|64
operator|*
literal|64
operator|/
literal|8
index|]
decl_stmt|;
name|uint8_t
name|mask
index|[
literal|64
operator|*
literal|64
operator|/
literal|8
index|]
decl_stmt|;
name|uint8_t
name|w
decl_stmt|;
name|uint8_t
name|h
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|uint8_t
modifier|*
name|vtfont_lookup
parameter_list|(
specifier|const
name|struct
name|vt_font
modifier|*
name|vf
parameter_list|,
name|term_char_t
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vt_font
modifier|*
name|vtfont_ref
parameter_list|(
name|struct
name|vt_font
modifier|*
name|vf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vtfont_unref
parameter_list|(
name|struct
name|vt_font
modifier|*
name|vf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vtfont_load
parameter_list|(
name|vfnt_t
modifier|*
name|f
parameter_list|,
name|struct
name|vt_font
modifier|*
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sysmouse. */
end_comment

begin_function_decl
name|void
name|sysmouse_process_event
parameter_list|(
name|mouse_info_t
modifier|*
name|mi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_mouse_event
parameter_list|(
name|int
name|type
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|event
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vt_mouse_state
parameter_list|(
name|int
name|show
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VT_MOUSE_SHOW
value|1
end_define

begin_define
define|#
directive|define
name|VT_MOUSE_HIDE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_VT_VT_H_ */
end_comment

end_unit

