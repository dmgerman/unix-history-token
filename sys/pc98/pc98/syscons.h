begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992-1998 S
comment|en Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_PC98_SYSCONS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_PC98_SYSCONS_H_
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

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|PRINTABLE
parameter_list|(
name|ch
parameter_list|)
value|((ch)> 0x1b || ((ch)> 0x0f&& (ch)< 0x1b) \ 			 || (ch)< 0x07)
end_define

begin_else
else|#
directive|else
end_else

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
comment|/* status flags */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_MODE
value|0x00010
end_define

begin_define
define|#
directive|define
name|SWITCH_WAIT_REL
value|0x00080
end_define

begin_define
define|#
directive|define
name|SWITCH_WAIT_ACQ
value|0x00100
end_define

begin_define
define|#
directive|define
name|BUFFER_SAVED
value|0x00200
end_define

begin_define
define|#
directive|define
name|CURSOR_ENABLED
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
name|MOUSE_MOVED
value|0x01000
end_define

begin_define
define|#
directive|define
name|MOUSE_CUTTING
value|0x02000
end_define

begin_define
define|#
directive|define
name|MOUSE_VISIBLE
value|0x04000
end_define

begin_define
define|#
directive|define
name|GRAPHICS_MODE
value|0x08000
end_define

begin_define
define|#
directive|define
name|PIXEL_MODE
value|0x10000
end_define

begin_define
define|#
directive|define
name|SAVER_RUNNING
value|0x20000
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

begin_comment
comment|/* these options are now obsolete; use corresponding options for kbd driver */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|DETECT_KBD
value|0x00008
end_define

begin_define
define|#
directive|define
name|XT_KEYBD
value|0x00010
end_define

begin_define
define|#
directive|define
name|KBD_NORESET
value|0x00020
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|QUIET_BELL
value|0x00040
end_define

begin_define
define|#
directive|define
name|VESA800X600
value|0x00080
end_define

begin_comment
comment|/* attribute flags */
end_comment

begin_define
define|#
directive|define
name|NORMAL_ATTR
value|0x00
end_define

begin_define
define|#
directive|define
name|BLINK_ATTR
value|0x01
end_define

begin_define
define|#
directive|define
name|BOLD_ATTR
value|0x02
end_define

begin_define
define|#
directive|define
name|UNDERLINE_ATTR
value|0x04
end_define

begin_define
define|#
directive|define
name|REVERSE_ATTR
value|0x08
end_define

begin_define
define|#
directive|define
name|FOREGROUND_CHANGED
value|0x10
end_define

begin_define
define|#
directive|define
name|BACKGROUND_CHANGED
value|0x20
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

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|UJIS
value|0
end_define

begin_define
define|#
directive|define
name|SJIS
value|1
end_define

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|BELL_PITCH
init|=
literal|1678
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IBM-PC */
end_comment

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
name|FONT_NONE
value|1
end_define

begin_define
define|#
directive|define
name|FONT_8
value|2
end_define

begin_define
define|#
directive|define
name|FONT_14
value|4
end_define

begin_define
define|#
directive|define
name|FONT_16
value|8
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* defines related to hardware addresses */
end_comment

begin_define
define|#
directive|define
name|TEXT_GDC
value|IO_GDC1
end_define

begin_comment
comment|/* 0x60 */
end_comment

begin_define
define|#
directive|define
name|TEXT_VRAM
value|(KERNBASE+0xA0000)
end_define

begin_define
define|#
directive|define
name|ATTR_OFFSET
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* current hardware attr word */
name|int
name|attr_mask
decl_stmt|;
comment|/* current logical attr mask */
name|int
name|cur_color
decl_stmt|;
comment|/* current hardware color */
name|int
name|std_color
decl_stmt|;
comment|/* normal hardware color */
name|int
name|rev_color
decl_stmt|;
comment|/* reverse hardware color */
block|}
name|term_stat
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|scr_stat
block|{
name|int
name|ad
decl_stmt|;
comment|/* video adapter index */
name|video_adapter_t
modifier|*
name|adp
decl_stmt|;
comment|/* video adapter structure */
name|u_short
modifier|*
name|scr_buf
decl_stmt|;
comment|/* buffer when off screen */
ifdef|#
directive|ifdef
name|PC98
name|u_short
modifier|*
name|atr_buf
decl_stmt|;
comment|/* buffer when off screen */
name|u_short
modifier|*
name|cursor_atr
decl_stmt|;
comment|/* cursor address (attribute)*/
endif|#
directive|endif
name|int
name|xpos
decl_stmt|;
comment|/* current X position */
name|int
name|ypos
decl_stmt|;
comment|/* current Y position */
name|int
name|saved_xpos
decl_stmt|;
comment|/* saved X position */
name|int
name|saved_ypos
decl_stmt|;
comment|/* saved Y position */
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
name|term_stat
name|term
decl_stmt|;
comment|/* terminal emulation stuff */
name|int
name|status
decl_stmt|;
comment|/* status (bitfield) */
name|int
name|kbd_mode
decl_stmt|;
comment|/* keyboard I/O mode */
name|u_short
modifier|*
name|cursor_pos
decl_stmt|;
comment|/* cursor buffer position */
name|u_short
modifier|*
name|cursor_oldpos
decl_stmt|;
comment|/* cursor old buffer position */
ifndef|#
directive|ifndef
name|PC98
name|u_short
name|cursor_saveunder
decl_stmt|;
comment|/* saved chars under cursor */
endif|#
directive|endif
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
name|short
name|mouse_xpos
decl_stmt|;
comment|/* mouse x coordinate */
name|short
name|mouse_ypos
decl_stmt|;
comment|/* mouse y coordinate */
name|short
name|mouse_buttons
decl_stmt|;
comment|/* mouse buttons */
ifndef|#
directive|ifndef
name|PC98
name|u_char
name|mouse_cursor
index|[
literal|128
index|]
decl_stmt|;
comment|/* mouse cursor bitmap store */
endif|#
directive|endif
name|u_short
modifier|*
name|mouse_cut_start
decl_stmt|;
comment|/* mouse cut start pos */
name|u_short
modifier|*
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
ifdef|#
directive|ifdef
name|PC98
name|u_short
modifier|*
name|his_atr
decl_stmt|;
comment|/* history buffer (attribute)*/
name|u_short
modifier|*
name|his_atr_head
decl_stmt|;
comment|/* current head position */
name|u_short
modifier|*
name|his_atr_pos
decl_stmt|;
comment|/* position shown on screen */
name|u_short
modifier|*
name|his_atr_save
decl_stmt|;
comment|/* save area index */
endif|#
directive|endif
name|int
name|history_size
decl_stmt|;
comment|/* size of history buffer */
name|struct
name|apmhook
name|r_hook
decl_stmt|;
comment|/* reconfiguration support */
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
name|KANJI
name|u_char
name|kanji_1st_char
decl_stmt|;
define|#
directive|define
name|KTYPE_ASCII
value|0
define|#
directive|define
name|KTYPE_KANA
value|1
define|#
directive|define
name|KTYPE_JKANA
value|0x10
define|#
directive|define
name|KTYPE_7JIS
value|0x20
define|#
directive|define
name|KTYPE_SJIS
value|2
define|#
directive|define
name|KTYPE_UJIS
value|4
define|#
directive|define
name|KTYPE_SUKANA
value|3
define|#
directive|define
name|KTYPE_SUJIS
value|6
define|#
directive|define
name|KTYPE_KANIN
value|0x80
define|#
directive|define
name|KTYPE_ASCIN
value|0x40
name|u_char
name|kanji_type
decl_stmt|;
comment|/* 0: Ascii code	1: HANKAKU	*/
comment|/* 2: Shift JIS 	4: UJIS		*/
comment|/* 3: Shift JIS or UJIS HANKAKU		*/
comment|/* 6: Shift JIS or UJIS			*/
comment|/* 0x10: JIS HANKAKU	0x20: JIS	*/
comment|/* 0x80: Kanji Invoke sequence		*/
comment|/* 0x40: Ascii Invoke sequence		*/
define|#
directive|define
name|IS_KTYPE_ASCII_or_HANKAKU
parameter_list|(
name|A
parameter_list|)
value|(!((A)& 0xee))
define|#
directive|define
name|IS_KTYPE_KANA
parameter_list|(
name|A
parameter_list|)
value|((A)& 0x11)
define|#
directive|define
name|KTYPE_MASK_CTRL
parameter_list|(
name|A
parameter_list|)
value|((A)&= 0xF0)
endif|#
directive|endif
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
name|std_color
decl_stmt|;
comment|/* normal hardware color */
name|int
name|rev_color
decl_stmt|;
comment|/* reverse hardware color */
block|}
name|default_attr
typedef|;
end_typedef

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
name|ISFONTAVAIL
parameter_list|(
name|af
parameter_list|)
value|((af)& V_ADP_FONT)
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
name|ISPALAVAIL
parameter_list|(
name|af
parameter_list|)
value|((af)& V_ADP_PALETTE)
end_define

begin_comment
comment|/* misc prototypes used by different syscons related LKM's */
end_comment

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
name|set_mode
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|scr_stat
modifier|*
name|sc_get_scr_stat
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_font
parameter_list|(
name|scr_stat
modifier|*
name|scp
parameter_list|,
name|int
name|operation
parameter_list|,
name|int
name|font_size
parameter_list|,
name|u_char
modifier|*
name|font_image
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_border
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
name|sc_touch_scrn_saver
parameter_list|(
name|void
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
name|void
name|sc_move_mouse
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
name|sc_clean_up
parameter_list|(
name|scr_stat
modifier|*
name|scp
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
name|clear
parameter_list|)
function_decl|;
end_function_decl

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
name|extra
parameter_list|,
name|int
name|wait
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

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/*  * Screen savers use these two variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|Crtat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|Atrat
decl_stmt|;
end_decl_stmt

begin_function_decl
name|unsigned
name|int
name|at2pc98
parameter_list|(
name|unsigned
name|int
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PC98_PC98_SYSCONS_H_ */
end_comment

end_unit

