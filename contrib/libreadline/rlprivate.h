begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rlprivate.h -- functions and variables global to the readline library, 		  but not intended for use by applications. */
end_comment

begin_comment
comment|/* Copyright (C) 1999 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RL_PRIVATE_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RL_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|"rlconf.h"
end_include

begin_comment
comment|/* for VISIBLE_STATS */
end_comment

begin_include
include|#
directive|include
file|"rlstdc.h"
end_include

begin_include
include|#
directive|include
file|"posixjmp.h"
end_include

begin_comment
comment|/* defines procenv_t */
end_comment

begin_comment
comment|/*************************************************************************  *									 *  * Global functions undocumented in texinfo manual and not in readline.h *  *									 *  *************************************************************************/
end_comment

begin_comment
comment|/* terminal.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_get_termcap
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************************************************************  *									 *  * Global variables undocumented in texinfo manual and not in readline.h *  *									 *  *************************************************************************/
end_comment

begin_comment
comment|/* complete.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_complete_with_tilde_expansion
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VISIBLE_STATS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|rl_visible_stats
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VISIBLE_STATS */
end_comment

begin_comment
comment|/* readline.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_line_buffer_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_numeric_arg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_arg_sign
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_explicit_arg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_editing_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_visible_prompt_length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|rl_last_func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|readline_echoing_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_key_sequence_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_display_fixed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parens.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_blink_matching_paren
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************************************************************  *									 *  * Global functions and variables unsed and undocumented		 *  *									 *  *************************************************************************/
end_comment

begin_comment
comment|/* bind.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_untranslate_keyseq
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kill.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_set_retained_kills
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* readline.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_discard_argument
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rltty.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_stop_output
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_rl_set_screen_size
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* undo.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_fix_last_undo_of_type
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* util.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_savestring
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************************************************************  *									 *  * Functions and variables private to the readline library		 *  *									 *  *************************************************************************/
end_comment

begin_comment
comment|/* NOTE: Functions and variables prefixed with `_rl_' are    pseudo-global: they are global so they can be shared    between files in the readline library, but are not intended    to be visible to readline callers. */
end_comment

begin_comment
comment|/*************************************************************************  * Undocumented private functions					 *  *************************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READLINE_CALLBACKS
argument_list|)
end_if

begin_comment
comment|/* readline.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|readline_internal_setup
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|readline_internal_teardown
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|readline_internal_char
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* READLINE_CALLBACKS */
end_comment

begin_comment
comment|/* bind.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_rl_bind_if_unbound
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Function
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_strip_prompt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_move_cursor_relative
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_move_vert
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_save_prompt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_restore_prompt
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_make_prompt_for_search
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_erase_at_end_of_line
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_clear_to_eol
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_clear_screen
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_update_final
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_redisplay_after_sigwinch
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_clean_up_for_exit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_erase_entire_line
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_currentb_display_line
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_any_typein
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_input_available
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_insert_typein
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macro.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_rl_with_macro_input
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_next_macro_key
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_push_executing_macro
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_pop_executing_macro
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_add_macro_char
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_kill_kbd_macro
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nls.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_init_eightbit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parens.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_rl_enable_paren_matching
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* readline.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_rl_init_line_state
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_set_the_line
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_dispatch
name|__P
argument_list|(
operator|(
name|int
operator|,
name|Keymap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_init_argument
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_fix_point
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_replace_text
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_char_search_internal
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_set_mark_at_pos
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rltty.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_disable_tty_signals
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_restore_tty_signals
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_rl_get_screen_size
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_init_terminal_io
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_MINIX
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|_rl_output_character_function
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|_rl_output_character_function
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|_rl_output_some_chars
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_backspace
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_enable_meta_key
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_control_keypad
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* util.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alphabetic
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_abort_internal
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_strindex
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_qsort_string_compare
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern int (_rl_uppercase_p
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (_rl_lowercase_p
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (_rl_pure_alphabetic
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (_rl_digit_p
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (_rl_to_lower
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (_rl_to_upper
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (_rl_digit_value
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* vi_mode.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_rl_vi_initialize_line
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_vi_reset_last
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_vi_set_last
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_vi_textmod_command
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_vi_done_inserting
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************************************************************  * Undocumented private variables					 *  *************************************************************************/
end_comment

begin_comment
comment|/* complete.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_complete_show_all
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_complete_mark_directories
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_print_completions_horizontally
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_completion_case_fold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_vis_botlin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_last_c_pos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_suppress_redisplay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_display_prompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* funmap.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|possible_control_prefixes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|possible_meta_prefixes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* isearch.c */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|_rl_isearch_terminators
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macro.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_defining_kbd_macro
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_executing_macro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* readline.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_horizontal_scroll_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_mark_modified_lines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_bell_preference
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_meta_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_convert_meta_chars_to_ascii
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_output_meta_chars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_comment_begin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|_rl_parsing_conditionalized_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Keymap
name|_rl_keymap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|_rl_in_stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|_rl_out_stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_last_command_was_kill
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_eof_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|procenv_t
name|readline_top_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_enable_keypad
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_enable_meta
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_clreol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_clrpag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_im
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_ic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_ei
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_DC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_up
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_dc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_cr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|term_IC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|screenheight
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|screenwidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|screenchars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|terminal_can_insert
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_term_autowrap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* undo.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_doing_an_undo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_undo_group_level
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RL_PRIVATE_H_ */
end_comment

end_unit

