begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995-1998 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_SYSCONS_SYSCONS_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_SYSCONS_SYSCONS_H_
end_define

begin_comment
comment|/* machine-dependent part of the header */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_include
include|#
directive|include
file|<pc98/pc98/sc_machdep.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_comment
comment|/* nothing for the moment */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_elif

begin_comment
comment|/* nothing for the moment */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default values for configuration options */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXCONS
end_ifndef

begin_define
define|#
directive|define
name|MAXCONS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SC_NO_SYSMOUSE
end_ifdef

begin_undef
undef|#
directive|undef
name|SC_NO_CUTPASTE
end_undef

begin_define
define|#
directive|define
name|SC_NO_CUTPASTE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SC_NO_MODE_CHANGE
end_ifdef

begin_undef
undef|#
directive|undef
name|SC_PIXEL_MODE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Always load font data if the pixel (raster text) mode is to be used. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SC_PIXEL_MODE
end_ifdef

begin_undef
undef|#
directive|undef
name|SC_NO_FONT_LOADING
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * If font data is not available, the `arrow'-shaped mouse cursor cannot  * be drawn.  Use the alternative drawing method.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SC_NO_FONT_LOADING
end_ifdef

begin_undef
undef|#
directive|undef
name|SC_ALT_MOUSE_IMAGE
end_undef

begin_define
define|#
directive|define
name|SC_ALT_MOUSE_IMAGE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SC_CURSOR_CHAR
end_ifndef

begin_define
define|#
directive|define
name|SC_CURSOR_CHAR
value|(0x07)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SC_MOUSE_CHAR
end_ifndef

begin_define
define|#
directive|define
name|SC_MOUSE_CHAR
value|(0xd0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|SC_MOUSE_CHAR
operator|<=
name|SC_CURSOR_CHAR
operator|&&
name|SC_CURSOR_CHAR
operator|<
operator|(
name|SC_MOUSE_CHAR
operator|+
literal|4
operator|)
end_if

begin_undef
undef|#
directive|undef
name|SC_CURSOR_CHAR
end_undef

begin_define
define|#
directive|define
name|SC_CURSOR_CHAR
value|(SC_MOUSE_CHAR + 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SC_DEBUG_LEVEL
end_ifndef

begin_define
define|#
directive|define
name|SC_DEBUG_LEVEL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|l
parameter_list|,
name|p
parameter_list|)
value|if (SC_DEBUG_LEVEL>= (l)) printf p
end_define

begin_define
define|#
directive|define
name|SC_DRIVER_NAME
value|"sc"
end_define

begin_define
define|#
directive|define
name|SC_VTY
parameter_list|(
name|dev
parameter_list|)
value|minor(dev)
end_define

begin_define
define|#
directive|define
name|SC_DEV
parameter_list|(
name|sc
parameter_list|,
name|vty
parameter_list|)
value|((sc)->dev[(vty) - (sc)->first_vty])
end_define

begin_define
define|#
directive|define
name|SC_STAT
parameter_list|(
name|dev
parameter_list|)
value|((scr_stat *)(dev)->si_drv1)
end_define

begin_comment
comment|/* printable chars */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PRINTABLE
end_ifndef

begin_define
define|#
directive|define
name|PRINTABLE
parameter_list|(
name|ch
parameter_list|)
value|((ch)> 0x1b || ((ch)> 0x0d&& (ch)< 0x1b) \ 			 || (ch)< 0x07)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* macros for "intelligent" screen update */
end_comment

begin_define
define|#
directive|define
name|mark_for_update
parameter_list|(
name|scp
parameter_list|,
name|x
parameter_list|)
value|{\ 			  	    if ((x)< scp->start) scp->start = (x);\ 				    else if ((x)> scp->end) scp->end = (x);\ 				}
end_define

begin_define
define|#
directive|define
name|mark_all
parameter_list|(
name|scp
parameter_list|)
value|{\ 				    scp->start = 0;\ 				    scp->end = scp->xsize * scp->ysize - 1;\ 				}
end_define

begin_comment
comment|/* vty status flags (scp->status) */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_MODE
value|0x00010
end_define

begin_comment
comment|/* unknown video mode */
end_comment

begin_define
define|#
directive|define
name|SWITCH_WAIT_REL
value|0x00080
end_define

begin_comment
comment|/* waiting for vty release */
end_comment

begin_define
define|#
directive|define
name|SWITCH_WAIT_ACQ
value|0x00100
end_define

begin_comment
comment|/* waiting for vty ack */
end_comment

begin_define
define|#
directive|define
name|BUFFER_SAVED
value|0x00200
end_define

begin_comment
comment|/* vty buffer is saved */
end_comment

begin_define
define|#
directive|define
name|CURSOR_ENABLED
value|0x00400
end_define

begin_comment
comment|/* text cursor is enabled */
end_comment

begin_define
define|#
directive|define
name|MOUSE_MOVED
value|0x01000
end_define

begin_comment
comment|/* mouse cursor has moved */
end_comment

begin_define
define|#
directive|define
name|MOUSE_CUTTING
value|0x02000
end_define

begin_comment
comment|/* mouse cursor is cutting text */
end_comment

begin_define
define|#
directive|define
name|MOUSE_VISIBLE
value|0x04000
end_define

begin_comment
comment|/* mouse cursor is showing */
end_comment

begin_define
define|#
directive|define
name|GRAPHICS_MODE
value|0x08000
end_define

begin_comment
comment|/* vty is in a graphics mode */
end_comment

begin_define
define|#
directive|define
name|PIXEL_MODE
value|0x10000
end_define

begin_comment
comment|/* vty is in a raster text mode */
end_comment

begin_define
define|#
directive|define
name|SAVER_RUNNING
value|0x20000
end_define

begin_comment
comment|/* screen saver is running */
end_comment

begin_define
define|#
directive|define
name|VR_CURSOR_BLINK
value|0x40000
end_define

begin_comment
comment|/* blinking text cursor */
end_comment

begin_define
define|#
directive|define
name|VR_CURSOR_ON
value|0x80000
end_define

begin_comment
comment|/* text cursor is on */
end_comment

begin_define
define|#
directive|define
name|MOUSE_HIDDEN
value|0x100000
end_define

begin_comment
comment|/* mouse cursor is temporarily hidden */
end_comment

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|COL
value|80
end_define

begin_define
define|#
directive|define
name|ROW
value|25
end_define

begin_define
define|#
directive|define
name|PCBURST
value|128
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BELL_DURATION
end_ifndef

begin_define
define|#
directive|define
name|BELL_DURATION
value|((5 * hz + 99) / 100)
end_define

begin_define
define|#
directive|define
name|BELL_PITCH
value|800
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* virtual terminal buffer */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sc_vtb
block|{
name|int
name|vtb_flags
decl_stmt|;
define|#
directive|define
name|VTB_VALID
value|(1<< 0)
define|#
directive|define
name|VTB_ALLOCED
value|(1<< 1)
name|int
name|vtb_type
decl_stmt|;
define|#
directive|define
name|VTB_INVALID
value|0
define|#
directive|define
name|VTB_MEMORY
value|1
define|#
directive|define
name|VTB_FRAMEBUFFER
value|2
define|#
directive|define
name|VTB_RINGBUFFER
value|3
name|int
name|vtb_cols
decl_stmt|;
name|int
name|vtb_rows
decl_stmt|;
name|int
name|vtb_size
decl_stmt|;
name|vm_offset_t
name|vtb_buffer
decl_stmt|;
name|int
name|vtb_tail
decl_stmt|;
comment|/* valid for VTB_RINGBUFFER only */
block|}
name|sc_vtb_t
typedef|;
end_typedef

begin_comment
comment|/* softc */
end_comment

begin_struct_decl
struct_decl|struct
name|keyboard
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|video_adapter
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|scr_stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tty
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|sc_softc
block|{
name|int
name|unit
decl_stmt|;
comment|/* unit # */
name|int
name|config
decl_stmt|;
comment|/* configuration flags */
define|#
directive|define
name|SC_VESA800X600
value|(1<< 7)
define|#
directive|define
name|SC_AUTODETECT_KBD
value|(1<< 8)
define|#
directive|define
name|SC_KERNEL_CONSOLE
value|(1<< 9)
name|int
name|flags
decl_stmt|;
comment|/* status flags */
define|#
directive|define
name|SC_VISUAL_BELL
value|(1<< 0)
define|#
directive|define
name|SC_QUIET_BELL
value|(1<< 1)
define|#
directive|define
name|SC_BLINK_CURSOR
value|(1<< 2)
define|#
directive|define
name|SC_CHAR_CURSOR
value|(1<< 3)
define|#
directive|define
name|SC_MOUSE_ENABLED
value|(1<< 4)
define|#
directive|define
name|SC_SCRN_IDLE
value|(1<< 5)
define|#
directive|define
name|SC_SCRN_BLANKED
value|(1<< 6)
define|#
directive|define
name|SC_SAVER_FAILED
value|(1<< 7)
define|#
directive|define
name|SC_INIT_DONE
value|(1<< 16)
define|#
directive|define
name|SC_SPLASH_SCRN
value|(1<< 17)
name|int
name|keyboard
decl_stmt|;
comment|/* -1 if unavailable */
name|struct
name|keyboard
modifier|*
name|kbd
decl_stmt|;
name|int
name|adapter
decl_stmt|;
name|struct
name|video_adapter
modifier|*
name|adp
decl_stmt|;
name|int
name|initial_mode
decl_stmt|;
comment|/* initial video mode */
name|int
name|first_vty
decl_stmt|;
name|int
name|vtys
decl_stmt|;
name|dev_t
modifier|*
name|dev
decl_stmt|;
name|struct
name|scr_stat
modifier|*
name|cur_scp
decl_stmt|;
name|struct
name|scr_stat
modifier|*
name|new_scp
decl_stmt|;
name|struct
name|scr_stat
modifier|*
name|old_scp
decl_stmt|;
name|int
name|delayed_next_scr
decl_stmt|;
name|char
name|font_loading_in_progress
decl_stmt|;
name|char
name|switch_in_progress
decl_stmt|;
name|char
name|videoio_in_progress
decl_stmt|;
name|char
name|write_in_progress
decl_stmt|;
name|char
name|blink_in_progress
decl_stmt|;
name|long
name|scrn_time_stamp
decl_stmt|;
name|char
name|cursor_base
decl_stmt|;
name|char
name|cursor_height
decl_stmt|;
name|u_char
name|scr_map
index|[
literal|256
index|]
decl_stmt|;
name|u_char
name|scr_rmap
index|[
literal|256
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|_SC_MD_SOFTC_DECLARED_
name|sc_md_softc_t
name|md
decl_stmt|;
comment|/* machine dependent vars */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SC_NO_PALETTE_LOADING
name|u_char
name|palette
index|[
literal|256
operator|*
literal|3
index|]
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SC_NO_FONT_LOADING
name|int
name|fonts_loaded
decl_stmt|;
define|#
directive|define
name|FONT_8
value|2
define|#
directive|define
name|FONT_14
value|4
define|#
directive|define
name|FONT_16
value|8
name|u_char
modifier|*
name|font_8
decl_stmt|;
name|u_char
modifier|*
name|font_14
decl_stmt|;
name|u_char
modifier|*
name|font_16
decl_stmt|;
endif|#
directive|endif
name|u_char
name|cursor_char
decl_stmt|;
name|u_char
name|mouse_char
decl_stmt|;
block|}
name|sc_softc_t
typedef|;
end_typedef

begin_comment
comment|/* virtual screen */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|scr_stat
block|{
name|int
name|index
decl_stmt|;
comment|/* index of this vty */
name|struct
name|sc_softc
modifier|*
name|sc
decl_stmt|;
comment|/* pointer to softc */
name|struct
name|sc_rndr_sw
modifier|*
name|rndr
decl_stmt|;
comment|/* renderer */
name|sc_vtb_t
name|scr
decl_stmt|;
name|sc_vtb_t
name|vtb
decl_stmt|;
name|int
name|xpos
decl_stmt|;
comment|/* current X position */
name|int
name|ypos
decl_stmt|;
comment|/* current Y position */
name|int
name|xsize
decl_stmt|;
comment|/* X text size */
name|int
name|ysize
decl_stmt|;
comment|/* Y text size */
name|int
name|xpixel
decl_stmt|;
comment|/* X graphics size */
name|int
name|ypixel
decl_stmt|;
comment|/* Y graphics size */
name|int
name|xoff
decl_stmt|;
comment|/* X offset in pixel mode */
name|int
name|yoff
decl_stmt|;
comment|/* Y offset in pixel mode */
name|u_char
modifier|*
name|font
decl_stmt|;
comment|/* current font */
name|int
name|font_size
decl_stmt|;
comment|/* fontsize in Y direction */
name|int
name|start
decl_stmt|;
comment|/* modified area start */
name|int
name|end
decl_stmt|;
comment|/* modified area end */
name|struct
name|sc_term_sw
modifier|*
name|tsw
decl_stmt|;
name|void
modifier|*
name|ts
decl_stmt|;
name|int
name|status
decl_stmt|;
comment|/* status (bitfield) */
name|int
name|kbd_mode
decl_stmt|;
comment|/* keyboard I/O mode */
name|int
name|cursor_pos
decl_stmt|;
comment|/* cursor buffer position */
name|int
name|cursor_oldpos
decl_stmt|;
comment|/* cursor old buffer position */
name|u_short
name|cursor_saveunder_char
decl_stmt|;
comment|/* saved char under cursor */
name|u_short
name|cursor_saveunder_attr
decl_stmt|;
comment|/* saved attr under cursor */
name|char
name|cursor_base
decl_stmt|;
comment|/* cursor base line # */
name|char
name|cursor_height
decl_stmt|;
comment|/* cursor height */
name|int
name|mouse_pos
decl_stmt|;
comment|/* mouse buffer position */
name|int
name|mouse_oldpos
decl_stmt|;
comment|/* mouse old buffer position */
name|short
name|mouse_xpos
decl_stmt|;
comment|/* mouse x coordinate */
name|short
name|mouse_ypos
decl_stmt|;
comment|/* mouse y coordinate */
name|short
name|mouse_oldxpos
decl_stmt|;
comment|/* mouse previous x coordinate */
name|short
name|mouse_oldypos
decl_stmt|;
comment|/* mouse previous y coordinate */
name|short
name|mouse_buttons
decl_stmt|;
comment|/* mouse buttons */
name|int
name|mouse_cut_start
decl_stmt|;
comment|/* mouse cut start pos */
name|int
name|mouse_cut_end
decl_stmt|;
comment|/* mouse cut end pos */
name|struct
name|proc
modifier|*
name|mouse_proc
decl_stmt|;
comment|/* proc* of controlling proc */
name|pid_t
name|mouse_pid
decl_stmt|;
comment|/* pid of controlling proc */
name|int
name|mouse_signal
decl_stmt|;
comment|/* signal # to report with */
name|u_short
name|bell_duration
decl_stmt|;
name|u_short
name|bell_pitch
decl_stmt|;
name|u_char
name|border
decl_stmt|;
comment|/* border color */
name|int
name|mode
decl_stmt|;
comment|/* mode */
name|pid_t
name|pid
decl_stmt|;
comment|/* pid of controlling proc */
name|struct
name|proc
modifier|*
name|proc
decl_stmt|;
comment|/* proc* of controlling proc */
name|struct
name|vt_mode
name|smode
decl_stmt|;
comment|/* switch mode */
name|sc_vtb_t
modifier|*
name|history
decl_stmt|;
comment|/* circular history buffer */
name|int
name|history_pos
decl_stmt|;
comment|/* position shown on screen */
name|int
name|history_size
decl_stmt|;
comment|/* size of history buffer */
name|int
name|splash_save_mode
decl_stmt|;
comment|/* saved mode for splash screen */
name|int
name|splash_save_status
decl_stmt|;
comment|/* saved status for splash screen */
ifdef|#
directive|ifdef
name|_SCR_MD_STAT_DECLARED_
name|scr_md_stat_t
name|md
decl_stmt|;
comment|/* machine dependent vars */
endif|#
directive|endif
block|}
name|scr_stat
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|SC_NORM_ATTR
end_ifndef

begin_define
define|#
directive|define
name|SC_NORM_ATTR
value|(FG_LIGHTGREY | BG_BLACK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SC_NORM_REV_ATTR
end_ifndef

begin_define
define|#
directive|define
name|SC_NORM_REV_ATTR
value|(FG_BLACK | BG_LIGHTGREY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SC_KERNEL_CONS_ATTR
end_ifndef

begin_define
define|#
directive|define
name|SC_KERNEL_CONS_ATTR
value|(FG_WHITE | BG_BLACK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SC_KERNEL_CONS_REV_ATTR
end_ifndef

begin_define
define|#
directive|define
name|SC_KERNEL_CONS_REV_ATTR
value|(FG_BLACK | BG_LIGHTGREY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* terminal emulator */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SC_DFLT_TERM
end_ifndef

begin_define
define|#
directive|define
name|SC_DFLT_TERM
value|"*"
end_define

begin_comment
comment|/* any */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|sc_term_init_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|void
modifier|*
modifier|*
name|tcp
parameter_list|,
name|int
name|code
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SC_TE_COLD_INIT
value|0
end_define

begin_define
define|#
directive|define
name|SC_TE_WARM_INIT
value|1
end_define

begin_typedef
typedef|typedef
name|int
name|sc_term_term_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|void
modifier|*
modifier|*
name|tcp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|sc_term_puts_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sc_term_ioctl_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sc_term_reset_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|code
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SC_TE_HARD_RESET
value|0
end_define

begin_define
define|#
directive|define
name|SC_TE_SOFT_RESET
value|1
end_define

begin_typedef
typedef|typedef
name|void
name|sc_term_default_attr_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|norm
parameter_list|,
name|int
name|rev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|sc_term_clear_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|sc_term_notify_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SC_TE_NOTIFY_VTSWITCH_IN
value|0
end_define

begin_define
define|#
directive|define
name|SC_TE_NOTIFY_VTSWITCH_OUT
value|1
end_define

begin_typedef
typedef|typedef
name|int
name|sc_term_input_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|c
parameter_list|,
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sc_term_sw
block|{
name|LIST_ENTRY
argument_list|(
argument|sc_term_sw
argument_list|)
name|link
expr_stmt|;
name|char
modifier|*
name|te_name
decl_stmt|;
comment|/* name of the emulator */
name|char
modifier|*
name|te_desc
decl_stmt|;
comment|/* description */
name|char
modifier|*
name|te_renderer
decl_stmt|;
comment|/* matching renderer */
name|size_t
name|te_size
decl_stmt|;
comment|/* size of internal buffer */
name|int
name|te_refcount
decl_stmt|;
comment|/* reference counter */
name|sc_term_init_t
modifier|*
name|te_init
decl_stmt|;
name|sc_term_term_t
modifier|*
name|te_term
decl_stmt|;
name|sc_term_puts_t
modifier|*
name|te_puts
decl_stmt|;
name|sc_term_ioctl_t
modifier|*
name|te_ioctl
decl_stmt|;
name|sc_term_reset_t
modifier|*
name|te_reset
decl_stmt|;
name|sc_term_default_attr_t
modifier|*
name|te_default_attr
decl_stmt|;
name|sc_term_clear_t
modifier|*
name|te_clear
decl_stmt|;
name|sc_term_notify_t
modifier|*
name|te_notify
decl_stmt|;
name|sc_term_input_t
modifier|*
name|te_input
decl_stmt|;
block|}
name|sc_term_sw_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|scterm_set
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SCTERM_MODULE
parameter_list|(
name|name
parameter_list|,
name|sw
parameter_list|)
define|\
value|DATA_SET(scterm_set, sw);				\ 	static int						\ 	scterm_##name##_event(module_t mod, int type, void *data) \ 	{							\ 		switch (type) {					\ 		case MOD_LOAD:					\ 			return sc_term_add(&sw);		\ 		case MOD_UNLOAD:				\ 			if (sw.te_refcount> 0)			\ 				return EBUSY;			\ 			return sc_term_remove(&sw);		\ 		default:					\ 			break;					\ 		}						\ 		return 0;					\ 	}							\ 	static moduledata_t scterm_##name##_mod = {		\ 		"scterm-" #name,				\ 		scterm_##name##_event,				\ 		NULL,						\ 	};							\ 	DECLARE_MODULE(scterm_##name, scterm_##name##_mod,	\ 		       SI_SUB_DRIVERS, SI_ORDER_MIDDLE)
end_define

begin_comment
comment|/* renderer function table */
end_comment

begin_typedef
typedef|typedef
name|void
name|vr_clear_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|attr
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vr_draw_border_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|color
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vr_draw_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|flip
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vr_set_cursor_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|blink
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vr_draw_cursor_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|at
parameter_list|,
name|int
name|blink
parameter_list|,
name|int
name|on
parameter_list|,
name|int
name|flip
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vr_blink_cursor_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|at
parameter_list|,
name|int
name|flip
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vr_set_mouse_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|vr_draw_mouse_t
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sc_rndr_sw
block|{
name|vr_clear_t
modifier|*
name|clear
decl_stmt|;
name|vr_draw_border_t
modifier|*
name|draw_border
decl_stmt|;
name|vr_draw_t
modifier|*
name|draw
decl_stmt|;
name|vr_set_cursor_t
modifier|*
name|set_cursor
decl_stmt|;
name|vr_draw_cursor_t
modifier|*
name|draw_cursor
decl_stmt|;
name|vr_blink_cursor_t
modifier|*
name|blink_cursor
decl_stmt|;
name|vr_set_mouse_t
modifier|*
name|set_mouse
decl_stmt|;
name|vr_draw_mouse_t
modifier|*
name|draw_mouse
decl_stmt|;
block|}
name|sc_rndr_sw_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sc_renderer
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|sc_rndr_sw_t
modifier|*
name|rndrsw
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|sc_renderer
argument_list|)
name|link
expr_stmt|;
block|}
name|sc_renderer_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|scrndr_set
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RENDERER
parameter_list|(
name|name
parameter_list|,
name|mode
parameter_list|,
name|sw
parameter_list|,
name|set
parameter_list|)
define|\
value|static struct sc_renderer scrndr_##name##_##mode## = {	\ 		#name, mode,&sw				\ 	};							\ 	DATA_SET(scrndr_set, scrndr_##name##_##mode##);		\ 	DATA_SET(set, scrndr_##name##_##mode##)
end_define

begin_define
define|#
directive|define
name|RENDERER_MODULE
parameter_list|(
name|name
parameter_list|,
name|set
parameter_list|)
define|\
value|static int						\ 	scrndr_##name##_event(module_t mod, int type, void *data) \ 	{							\ 		sc_renderer_t **list;				\ 		sc_renderer_t *p;				\ 		int error = 0;					\ 		switch (type) {					\ 		case MOD_LOAD:					\ 			list = (sc_renderer_t **)set.ls_items;	\ 			while ((p = *list++) != NULL) {		\ 				error = sc_render_add(p);	\ 				if (error)			\ 					break;			\ 			}					\ 			break;					\ 		case MOD_UNLOAD:				\ 			list = (sc_renderer_t **)set.ls_items;	\ 			while ((p = *list++) != NULL) {		\ 				error = sc_render_remove(p);	\ 				if (error)			\ 					break;			\ 			}					\ 			break;					\ 		default:					\ 			break;					\ 		}						\ 		return error;					\ 	}							\ 	static moduledata_t scrndr_##name##_mod = {		\ 		"scrndr-" #name,				\ 		scrndr_##name##_event,				\ 		NULL,						\ 	};							\ 	DECLARE_MODULE(scrndr_##name##, scrndr_##name##_mod, 	\ 		       SI_SUB_DRIVERS, SI_ORDER_MIDDLE)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cursor_start
decl_stmt|;
name|int
name|cursor_end
decl_stmt|;
name|int
name|shift_state
decl_stmt|;
name|int
name|bell_pitch
decl_stmt|;
block|}
name|bios_values_t
typedef|;
end_typedef

begin_comment
comment|/* other macros */
end_comment

begin_define
define|#
directive|define
name|ISTEXTSC
parameter_list|(
name|scp
parameter_list|)
value|(!((scp)->status 				\& (UNKNOWN_MODE | GRAPHICS_MODE | PIXEL_MODE)))
end_define

begin_define
define|#
directive|define
name|ISGRAPHSC
parameter_list|(
name|scp
parameter_list|)
value|(((scp)->status 				\& (UNKNOWN_MODE | GRAPHICS_MODE)))
end_define

begin_define
define|#
directive|define
name|ISPIXELSC
parameter_list|(
name|scp
parameter_list|)
value|(((scp)->status 				\& (UNKNOWN_MODE | GRAPHICS_MODE | PIXEL_MODE))\ 			  == PIXEL_MODE)
end_define

begin_define
define|#
directive|define
name|ISUNKNOWNSC
parameter_list|(
name|scp
parameter_list|)
value|((scp)->status& UNKNOWN_MODE)
end_define

begin_define
define|#
directive|define
name|ISMOUSEAVAIL
parameter_list|(
name|af
parameter_list|)
value|((af)& V_ADP_FONT)
end_define

begin_define
define|#
directive|define
name|ISFONTAVAIL
parameter_list|(
name|af
parameter_list|)
value|((af)& V_ADP_FONT)
end_define

begin_define
define|#
directive|define
name|ISPALAVAIL
parameter_list|(
name|af
parameter_list|)
value|((af)& V_ADP_PALETTE)
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
name|kbd_read_char
parameter_list|(
name|kbd
parameter_list|,
name|wait
parameter_list|)
define|\
value|(*kbdsw[(kbd)->kb_index]->read_char)((kbd), (wait))
end_define

begin_define
define|#
directive|define
name|kbd_check_char
parameter_list|(
name|kbd
parameter_list|)
define|\
value|(*kbdsw[(kbd)->kb_index]->check_char)((kbd))
end_define

begin_define
define|#
directive|define
name|kbd_enable
parameter_list|(
name|kbd
parameter_list|)
define|\
value|(*kbdsw[(kbd)->kb_index]->enable)((kbd))
end_define

begin_define
define|#
directive|define
name|kbd_disable
parameter_list|(
name|kbd
parameter_list|)
define|\
value|(*kbdsw[(kbd)->kb_index]->disable)((kbd))
end_define

begin_define
define|#
directive|define
name|kbd_lock
parameter_list|(
name|kbd
parameter_list|,
name|lockf
parameter_list|)
define|\
value|(*kbdsw[(kbd)->kb_index]->lock)((kbd), (lockf))
end_define

begin_define
define|#
directive|define
name|kbd_ioctl
parameter_list|(
name|kbd
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
define|\
value|(((kbd) == NULL) ?						\ 		ENODEV : (*kbdsw[(kbd)->kb_index]->ioctl)((kbd), (cmd), (arg)))
end_define

begin_define
define|#
directive|define
name|kbd_clear_state
parameter_list|(
name|kbd
parameter_list|)
define|\
value|(*kbdsw[(kbd)->kb_index]->clear_state)((kbd))
end_define

begin_define
define|#
directive|define
name|kbd_get_fkeystr
parameter_list|(
name|kbd
parameter_list|,
name|fkey
parameter_list|,
name|len
parameter_list|)
define|\
value|(*kbdsw[(kbd)->kb_index]->get_fkeystr)((kbd), (fkey), (len))
end_define

begin_define
define|#
directive|define
name|kbd_poll
parameter_list|(
name|kbd
parameter_list|,
name|on
parameter_list|)
define|\
value|(*kbdsw[(kbd)->kb_index]->poll)((kbd), (on))
end_define

begin_comment
comment|/* syscons.c */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|sc_user_ioctl
function_decl|)
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_probe_unit
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_attach_unit
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_mode
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_set_border
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|color
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_load_font
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|page
parameter_list|,
name|int
name|size
parameter_list|,
name|u_char
modifier|*
name|font
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_save_font
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|page
parameter_list|,
name|int
name|size
parameter_list|,
name|u_char
modifier|*
name|font
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_show_font
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_touch_scrn_saver
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_puts
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_draw_cursor_image
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_remove_cursor_image
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_set_cursor_image
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_clean_up
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_switch_scr
parameter_list|(
name|sc_softc_t
modifier|*
name|sc
parameter_list|,
name|u_int
name|next_scr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_alloc_scr_buffer
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|wait
parameter_list|,
name|int
name|discard
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_init_emulator
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_paste
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|u_char
modifier|*
name|p
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_bell
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|pitch
parameter_list|,
name|int
name|duration
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* schistory.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SC_NO_HISTORY
end_ifndef

begin_function_decl
name|int
name|sc_alloc_history_buffer
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|lines
parameter_list|,
name|int
name|prev_ysize
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_free_history_buffer
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|prev_ysize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_hist_save
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sc_hist_save_one_line
parameter_list|(
name|scp
parameter_list|,
name|from
parameter_list|)
define|\
value|sc_vtb_append(&(scp)->vtb, (from), (scp)->history, (scp)->xsize)
end_define

begin_function_decl
name|int
name|sc_hist_restore
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_hist_home
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_hist_end
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_hist_up_line
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_hist_down_line
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_hist_ioctl
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SC_NO_HISTORY */
end_comment

begin_comment
comment|/* scmouse.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SC_NO_CUTPASTE
end_ifndef

begin_function_decl
name|void
name|sc_alloc_cut_buffer
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_draw_mouse_image
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_remove_mouse_image
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_inside_cutmark
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_remove_cutmarking
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_remove_all_cutmarkings
parameter_list|(
name|sc_softc_t
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_remove_all_mouse
parameter_list|(
name|sc_softc_t
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sc_draw_mouse_image
parameter_list|(
name|scp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|sc_remove_mouse_image
parameter_list|(
name|scp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|sc_inside_cutmark
parameter_list|(
name|scp
parameter_list|,
name|pos
parameter_list|)
value|FALSE
end_define

begin_define
define|#
directive|define
name|sc_remove_cutmarking
parameter_list|(
name|scp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|sc_remove_all_cutmarkings
parameter_list|(
name|scp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|sc_remove_all_mouse
parameter_list|(
name|scp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SC_NO_CUTPASTE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SC_NO_SYSMOUSE
end_ifndef

begin_function_decl
name|void
name|sc_mouse_move
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_mouse_ioctl
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SC_NO_SYSMOUSE */
end_comment

begin_comment
comment|/* scvidctl.c */
end_comment

begin_function_decl
name|int
name|sc_set_text_mode
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|xsize
parameter_list|,
name|int
name|ysize
parameter_list|,
name|int
name|fontsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_set_graphics_mode
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_set_pixel_mode
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|int
name|xsize
parameter_list|,
name|int
name|ysize
parameter_list|,
name|int
name|fontsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_vid_ioctl
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_render_add
parameter_list|(
name|sc_renderer_t
modifier|*
name|rndr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_render_remove
parameter_list|(
name|sc_renderer_t
modifier|*
name|rndr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sc_rndr_sw_t
modifier|*
name|sc_render_match
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scvtb.c */
end_comment

begin_function_decl
name|void
name|sc_vtb_init
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|cols
parameter_list|,
name|int
name|rows
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_destroy
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|sc_vtb_size
parameter_list|(
name|int
name|cols
parameter_list|,
name|int
name|rows
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_clear
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_vtb_getc
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|at
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_vtb_geta
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|at
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_putc
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|at
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|sc_vtb_putchar
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|vm_offset_t
name|p
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|sc_vtb_pointer
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|at
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_vtb_pos
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|pos
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|sc_vtb_tail
parameter_list|(
name|vtb
parameter_list|)
value|((vtb)->vtb_tail)
end_define

begin_define
define|#
directive|define
name|sc_vtb_rows
parameter_list|(
name|vtb
parameter_list|)
value|((vtb)->vtb_rows)
end_define

begin_define
define|#
directive|define
name|sc_vtb_cols
parameter_list|(
name|vtb
parameter_list|)
value|((vtb)->vtb_cols)
end_define

begin_function_decl
name|void
name|sc_vtb_copy
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb1
parameter_list|,
name|int
name|from
parameter_list|,
name|sc_vtb_t
modifier|*
name|vtb2
parameter_list|,
name|int
name|to
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_append
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb1
parameter_list|,
name|int
name|from
parameter_list|,
name|sc_vtb_t
modifier|*
name|vtb2
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_seek
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_erase
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|at
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_move
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|from
parameter_list|,
name|int
name|to
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_delete
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|at
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_vtb_ins
parameter_list|(
name|sc_vtb_t
modifier|*
name|vtb
parameter_list|,
name|int
name|at
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sysmouse.c */
end_comment

begin_function_decl
name|int
name|sysmouse_event
parameter_list|(
name|mouse_info_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* scterm.c */
end_comment

begin_function_decl
name|void
name|sc_move_cursor
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_clear_screen
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_term_add
parameter_list|(
name|sc_term_sw_t
modifier|*
name|sw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_term_remove
parameter_list|(
name|sc_term_sw_t
modifier|*
name|sw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sc_term_sw_t
modifier|*
name|sc_term_match
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sc_term_sw_t
modifier|*
name|sc_term_match_by_number
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* machine dependent functions */
end_comment

begin_function_decl
name|int
name|sc_max_unit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sc_softc_t
modifier|*
name|sc_get_softc
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sc_softc_t
modifier|*
name|sc_find_softc
parameter_list|(
name|struct
name|video_adapter
modifier|*
name|adp
parameter_list|,
name|struct
name|keyboard
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_get_cons_priority
parameter_list|(
name|int
modifier|*
name|unit
parameter_list|,
name|int
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sc_get_bios_values
parameter_list|(
name|bios_values_t
modifier|*
name|values
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sc_tone
parameter_list|(
name|int
name|herz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_SYSCONS_SYSCONS_H_ */
end_comment

end_unit

