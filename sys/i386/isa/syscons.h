begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_SYSCONS_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_SYSCONS_H_
end_define

begin_comment
comment|/* vm things */
end_comment

begin_define
define|#
directive|define
name|ISMAPPED
parameter_list|(
name|pa
parameter_list|,
name|width
parameter_list|)
define|\
value|(((pa)<= (u_long)0x1000 - (width)) \ 	 || ((pa)>= 0xa0000&& (pa)<= 0x100000 - (width)))
end_define

begin_define
define|#
directive|define
name|pa_to_va
parameter_list|(
name|pa
parameter_list|)
value|(KERNBASE + (pa))
end_define

begin_comment
comment|/* works if ISMAPPED(pa...) */
end_comment

begin_comment
comment|/* printable chars */
end_comment

begin_define
define|#
directive|define
name|PRINTABLE
parameter_list|(
name|ch
parameter_list|)
value|((ch)> 0x1b || ((ch)> 0x0d&& (ch)< 0x1b) \ 			 || (ch)< 0x07)
end_define

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
value|{\ 				    scp->start = 0;\ 				    scp->end = scp->xsize * scp->ysize;\ 				}
end_define

begin_comment
comment|/* status flags */
end_comment

begin_define
define|#
directive|define
name|LOCK_KEY_MASK
value|0x0000F
end_define

begin_define
define|#
directive|define
name|LED_MASK
value|0x00007
end_define

begin_define
define|#
directive|define
name|UNKNOWN_MODE
value|0x00010
end_define

begin_define
define|#
directive|define
name|KBD_RAW_MODE
value|0x00020
end_define

begin_define
define|#
directive|define
name|SWITCH_WAIT_REL
value|0x00040
end_define

begin_define
define|#
directive|define
name|SWITCH_WAIT_ACQ
value|0x00080
end_define

begin_define
define|#
directive|define
name|BUFFER_SAVED
value|0x00100
end_define

begin_define
define|#
directive|define
name|CURSOR_ENABLED
value|0x00200
end_define

begin_define
define|#
directive|define
name|CURSOR_SHOWN
value|0x00400
end_define

begin_define
define|#
directive|define
name|MOUSE_ENABLED
value|0x00800
end_define

begin_define
define|#
directive|define
name|UPDATE_MOUSE
value|0x01000
end_define

begin_comment
comment|/* configuration flags */
end_comment

begin_define
define|#
directive|define
name|VISUAL_BELL
value|0x00001
end_define

begin_define
define|#
directive|define
name|BLINK_CURSOR
value|0x00002
end_define

begin_define
define|#
directive|define
name|CHAR_CURSOR
value|0x00004
end_define

begin_define
define|#
directive|define
name|XT_KEYBD
value|0x00010
end_define

begin_comment
comment|/* video hardware memory addresses */
end_comment

begin_define
define|#
directive|define
name|VIDEOMEM
value|0x000A0000
end_define

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
name|MAX_ESC_PAR
value|5
end_define

begin_define
define|#
directive|define
name|LOAD
value|1
end_define

begin_define
define|#
directive|define
name|SAVE
value|0
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
name|BELL_DURATION
value|5
end_define

begin_define
define|#
directive|define
name|BELL_PITCH
value|800
end_define

begin_define
define|#
directive|define
name|TIMER_FREQ
value|1193182
end_define

begin_comment
comment|/* should be in isa.h */
end_comment

begin_define
define|#
directive|define
name|CONSOLE_BUFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|PCBURST
value|128
end_define

begin_define
define|#
directive|define
name|FONT_8
value|0x001
end_define

begin_define
define|#
directive|define
name|FONT_14
value|0x002
end_define

begin_define
define|#
directive|define
name|FONT_16
value|0x004
end_define

begin_define
define|#
directive|define
name|HISTORY_SIZE
value|100*80
end_define

begin_comment
comment|/* defines related to hardware addresses */
end_comment

begin_define
define|#
directive|define
name|MONO_BASE
value|0x3B4
end_define

begin_comment
comment|/* crt controller base mono */
end_comment

begin_define
define|#
directive|define
name|COLOR_BASE
value|0x3D4
end_define

begin_comment
comment|/* crt controller base color */
end_comment

begin_define
define|#
directive|define
name|MISC
value|0x3C2
end_define

begin_comment
comment|/* misc output register */
end_comment

begin_define
define|#
directive|define
name|ATC
value|IO_VGA+0x00
end_define

begin_comment
comment|/* attribute controller */
end_comment

begin_define
define|#
directive|define
name|TSIDX
value|IO_VGA+0x04
end_define

begin_comment
comment|/* timing sequencer idx */
end_comment

begin_define
define|#
directive|define
name|TSREG
value|IO_VGA+0x05
end_define

begin_comment
comment|/* timing sequencer data */
end_comment

begin_define
define|#
directive|define
name|PIXMASK
value|IO_VGA+0x06
end_define

begin_comment
comment|/* pixel write mask */
end_comment

begin_define
define|#
directive|define
name|PALRADR
value|IO_VGA+0x07
end_define

begin_comment
comment|/* palette read address */
end_comment

begin_define
define|#
directive|define
name|PALWADR
value|IO_VGA+0x08
end_define

begin_comment
comment|/* palette write address */
end_comment

begin_define
define|#
directive|define
name|PALDATA
value|IO_VGA+0x09
end_define

begin_comment
comment|/* palette data register */
end_comment

begin_define
define|#
directive|define
name|GDCIDX
value|IO_VGA+0x0E
end_define

begin_comment
comment|/* graph data controller idx */
end_comment

begin_define
define|#
directive|define
name|GDCREG
value|IO_VGA+0x0F
end_define

begin_comment
comment|/* graph data controller data */
end_comment

begin_comment
comment|/* special characters */
end_comment

begin_define
define|#
directive|define
name|cntlc
value|0x03
end_define

begin_define
define|#
directive|define
name|cntld
value|0x04
end_define

begin_define
define|#
directive|define
name|bs
value|0x08
end_define

begin_define
define|#
directive|define
name|lf
value|0x0a
end_define

begin_define
define|#
directive|define
name|cr
value|0x0d
end_define

begin_define
define|#
directive|define
name|del
value|0x7f
end_define

begin_define
define|#
directive|define
name|DEAD_CHAR
value|0x07
end_define

begin_comment
comment|/* char used for cursor */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|term_stat
block|{
name|int
name|esc
decl_stmt|;
comment|/* processing escape sequence */
name|int
name|num_param
decl_stmt|;
comment|/* # of parameters to ESC */
name|int
name|last_param
decl_stmt|;
comment|/* last parameter # */
name|int
name|param
index|[
name|MAX_ESC_PAR
index|]
decl_stmt|;
comment|/* contains ESC parameters */
name|int
name|cur_attr
decl_stmt|;
comment|/* current attributes */
name|int
name|std_attr
decl_stmt|;
comment|/* normal attributes */
name|int
name|rev_attr
decl_stmt|;
comment|/* reverse attributes */
block|}
name|term_stat
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|scr_stat
block|{
name|u_short
modifier|*
name|scr_buf
decl_stmt|;
comment|/* buffer when off screen */
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
comment|/* X size */
name|int
name|ysize
decl_stmt|;
comment|/* Y size */
name|int
name|start
decl_stmt|;
comment|/* modified area start */
name|int
name|end
decl_stmt|;
comment|/* modified area end */
name|term_stat
name|term
decl_stmt|;
comment|/* terminal emulation stuff */
name|int
name|status
decl_stmt|;
comment|/* status (bitfield) */
name|u_short
modifier|*
name|cursor_pos
decl_stmt|;
comment|/* cursor buffer position */
name|u_short
name|cursor_saveunder
decl_stmt|;
comment|/* saved chars under cursor */
name|char
name|cursor_start
decl_stmt|;
comment|/* cursor start line # */
name|char
name|cursor_end
decl_stmt|;
comment|/* cursor end line # */
name|u_short
modifier|*
name|mouse_pos
decl_stmt|;
comment|/* mouse buffer position */
name|u_short
modifier|*
name|mouse_oldpos
decl_stmt|;
comment|/* mouse old buffer position */
name|u_short
name|mouse_saveunder
index|[
literal|4
index|]
decl_stmt|;
comment|/* saved chars under mouse */
name|short
name|mouse_xpos
decl_stmt|;
comment|/* mouse x coordinate */
name|short
name|mouse_ypos
decl_stmt|;
comment|/* mouse y coordinate */
name|u_char
name|mouse_cursor
index|[
literal|128
index|]
decl_stmt|;
comment|/* mouse cursor bitmap store */
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
name|u_char
name|mode
decl_stmt|;
comment|/* mode */
name|u_char
name|font
decl_stmt|;
comment|/* font on this screen */
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
name|u_short
modifier|*
name|history
decl_stmt|;
comment|/* circular history buffer */
name|u_short
modifier|*
name|history_head
decl_stmt|;
comment|/* current head position */
name|u_short
modifier|*
name|history_pos
decl_stmt|;
comment|/* position shown on screen */
name|u_short
modifier|*
name|history_save
decl_stmt|;
comment|/* save area index */
name|int
name|history_size
decl_stmt|;
comment|/* size of history buffer */
name|struct
name|apmhook
name|r_hook
decl_stmt|;
comment|/* reconfiguration support */
block|}
name|scr_stat
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|default_attr
block|{
name|int
name|std_attr
decl_stmt|;
comment|/* normal attributes */
name|int
name|rev_attr
decl_stmt|;
comment|/* reverse attributes */
block|}
name|default_attr
typedef|;
end_typedef

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|int
name|scprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scopen
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
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
name|scclose
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
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
name|scread
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scwrite
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scparam
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|,
name|struct
name|termios
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
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
name|void
name|scstart
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scintr
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcmmap
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|nprot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|scinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int
name|scgetc
parameter_list|(
name|int
name|noblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tty
modifier|*
name|scdevtotty
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|scr_stat
modifier|*
name|get_scr_stat
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|scr_stat
modifier|*
name|alloc_scp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|init_scp
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|get_scr_num
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|scrn_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|clear_screen
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|switch_scr
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|u_int
name|next_scr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|exchange_scr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|move_crsr
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
specifier|static
name|void
name|scan_esc
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|u_char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|void
name|draw_cursor
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|show
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ansi_put
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
specifier|static
name|u_char
modifier|*
name|get_fstr
parameter_list|(
name|u_int
name|c
parameter_list|,
name|u_int
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|update_leds
parameter_list|(
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|history_to_screen
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|history_up_line
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|history_down_line
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|kbd_wait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|kbd_cmd
parameter_list|(
name|u_char
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
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
name|set_border
parameter_list|(
name|int
name|color
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|set_vgaregs
parameter_list|(
name|char
modifier|*
name|modetable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|set_font_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|set_normal_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|copy_font
parameter_list|(
name|int
name|operation
parameter_list|,
name|int
name|font_type
parameter_list|,
name|char
modifier|*
name|font_image
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|set_destructive_cursor
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|draw_mouse_image
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|save_palette
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|load_palette
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|do_bell
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

begin_function_decl
specifier|static
name|void
name|blink_screen
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_SYSCONS_H_ */
end_comment

end_unit

