begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* terminal.h -- The external interface to terminal I/O.    $Id: terminal.h,v 1.7 2001/11/16 23:17:29 karl Exp $     Copyright (C) 1993, 96, 97, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TERMINAL_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|TERMINAL_H
end_define

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_comment
comment|/* For almost every function externally visible from terminal.c, there is    a corresponding "hook" function which can be bound in order to replace    the functionality of the one found in terminal.c.  This is how we go    about implemented X window display. */
end_comment

begin_comment
comment|/* The width and height of the terminal. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|screenwidth
decl_stmt|,
name|screenheight
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means this terminal can't really do anything. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|terminal_is_dumb_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that this terminal has a meta key. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|terminal_has_meta_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that this terminal can produce a visible bell. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|terminal_has_visible_bell_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means to use that visible bell if at all possible. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|terminal_use_visible_bell_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that this terminal can scroll lines up and down. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|terminal_can_scroll
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize the terminal which is known as TERMINAL_NAME.  If this terminal    doesn't have cursor addressability, TERMINAL_IS_DUMB_P becomes non-zero.    The variables SCREENHEIGHT and SCREENWIDTH are set to the dimensions that    this terminal actually has.  The variable TERMINAL_HAS_META_P becomes non-    zero if this terminal supports a Meta key. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_initialize_terminal
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_initialize_terminal_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the current screen width and height in the variables    SCREENWIDTH and SCREENHEIGHT. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_get_screen_size
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_get_screen_size_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save and restore tty settings. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|terminal_prep_terminal
argument_list|()
decl_stmt|,
name|terminal_unprep_terminal
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_prep_terminal_hook
decl_stmt|,
modifier|*
name|terminal_unprep_terminal_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Re-initialize the terminal to TERMINAL_NAME. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_new_terminal
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_new_terminal_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Move the cursor to the terminal location of X and Y. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_goto_xy
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_goto_xy_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print STRING to the terminal at the current position. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_put_text
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_put_text_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print NCHARS from STRING to the terminal at the current position. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_write_chars
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_write_chars_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear from the current position of the cursor to the end of the line. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_clear_to_eol
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_clear_to_eol_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear the entire terminal screen. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_clear_screen
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_clear_screen_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Move the cursor up one line. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_up_line
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_up_line_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Move the cursor down one line. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_down_line
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_down_line_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Turn on reverse video if possible. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_begin_inverse
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_begin_inverse_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Turn off reverse video if possible. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_end_inverse
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_end_inverse_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scroll an area of the terminal, starting with the region from START    to END, AMOUNT lines.  If AMOUNT is negative, the lines are scrolled    towards the top of the screen, else they are scrolled towards the    bottom of the screen. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_scroll_terminal
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_scroll_terminal_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ring the terminal bell.  The bell is run visibly if it both has one and    terminal_use_visible_bell_p is non-zero. */
end_comment

begin_function_decl
specifier|extern
name|void
name|terminal_ring_bell
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|terminal_ring_bell_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The key sequences output by special keys, if this terminal has any. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_ku
decl_stmt|,
modifier|*
name|term_kd
decl_stmt|,
modifier|*
name|term_kr
decl_stmt|,
modifier|*
name|term_kl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_kP
decl_stmt|,
modifier|*
name|term_kN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_ke
decl_stmt|,
modifier|*
name|term_kh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_kx
decl_stmt|,
modifier|*
name|term_ki
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_kD
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !TERMINAL_H */
end_comment

end_unit

