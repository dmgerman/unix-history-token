begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rlprivate.h -- functions and variables global to the readline library, 		  but not intended for use by applications. */
end_comment

begin_comment
comment|/* Copyright (C) 1999-2005 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
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
comment|/*************************************************************************  *									 *  * Global structs undocumented in texinfo manual and not in readline.h   *  *									 *  *************************************************************************/
end_comment

begin_comment
comment|/* search types */
end_comment

begin_define
define|#
directive|define
name|RL_SEARCH_ISEARCH
value|0x01
end_define

begin_comment
comment|/* incremental search */
end_comment

begin_define
define|#
directive|define
name|RL_SEARCH_NSEARCH
value|0x02
end_define

begin_comment
comment|/* non-incremental search */
end_comment

begin_define
define|#
directive|define
name|RL_SEARCH_CSEARCH
value|0x04
end_define

begin_comment
comment|/* intra-line char search */
end_comment

begin_comment
comment|/* search flags */
end_comment

begin_define
define|#
directive|define
name|SF_REVERSE
value|0x01
end_define

begin_define
define|#
directive|define
name|SF_FOUND
value|0x02
end_define

begin_define
define|#
directive|define
name|SF_FAILED
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|__rl_search_context
block|{
name|int
name|type
decl_stmt|;
name|int
name|sflags
decl_stmt|;
name|char
modifier|*
name|search_string
decl_stmt|;
name|int
name|search_string_index
decl_stmt|;
name|int
name|search_string_size
decl_stmt|;
name|char
modifier|*
modifier|*
name|lines
decl_stmt|;
name|char
modifier|*
name|allocated_line
decl_stmt|;
name|int
name|hlen
decl_stmt|;
name|int
name|hindex
decl_stmt|;
name|int
name|save_point
decl_stmt|;
name|int
name|save_mark
decl_stmt|;
name|int
name|save_line
decl_stmt|;
name|int
name|last_found_line
decl_stmt|;
name|char
modifier|*
name|prev_line_found
decl_stmt|;
name|UNDO_LIST
modifier|*
name|save_undo_list
decl_stmt|;
name|int
name|history_pos
decl_stmt|;
name|int
name|direction
decl_stmt|;
name|int
name|lastc
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_MULTIBYTE
argument_list|)
name|char
name|mb
index|[
name|MB_LEN_MAX
index|]
decl_stmt|;
endif|#
directive|endif
name|char
modifier|*
name|sline
decl_stmt|;
name|int
name|sline_len
decl_stmt|;
name|int
name|sline_index
decl_stmt|;
name|char
modifier|*
name|search_terminators
decl_stmt|;
block|}
name|_rl_search_cxt
typedef|;
end_typedef

begin_comment
comment|/* Callback data for reading numeric arguments */
end_comment

begin_define
define|#
directive|define
name|NUM_SAWMINUS
value|0x01
end_define

begin_define
define|#
directive|define
name|NUM_SAWDIGITS
value|0x02
end_define

begin_define
define|#
directive|define
name|NUM_READONE
value|0x04
end_define

begin_typedef
typedef|typedef
name|int
name|_rl_arg_cxt
typedef|;
end_typedef

begin_comment
comment|/* A context for reading key sequences longer than a single character when    using the callback interface. */
end_comment

begin_define
define|#
directive|define
name|KSEQ_DISPATCHED
value|0x01
end_define

begin_define
define|#
directive|define
name|KSEQ_SUBSEQ
value|0x02
end_define

begin_define
define|#
directive|define
name|KSEQ_RECURSIVE
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|__rl_keyseq_context
block|{
name|int
name|flags
decl_stmt|;
name|int
name|subseq_arg
decl_stmt|;
name|int
name|subseq_retval
decl_stmt|;
comment|/* XXX */
name|Keymap
name|dmap
decl_stmt|;
name|Keymap
name|oldmap
decl_stmt|;
name|int
name|okey
decl_stmt|;
name|struct
name|__rl_keyseq_context
modifier|*
name|ocxt
decl_stmt|;
name|int
name|childval
decl_stmt|;
block|}
name|_rl_keyseq_cxt
typedef|;
end_typedef

begin_comment
comment|/* fill in more as needed */
end_comment

begin_comment
comment|/* `Generic' callback data and functions */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__rl_callback_generic_arg
block|{
name|int
name|count
decl_stmt|;
name|int
name|i1
decl_stmt|,
name|i2
decl_stmt|;
comment|/* add here as needed */
block|}
name|_rl_callback_generic_arg
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|_rl_callback_func_t
name|PARAMS
typedef|((
name|_rl_callback_generic_arg
modifier|*
typedef|));
end_typedef

begin_comment
comment|/*************************************************************************  *									 *  * Global functions undocumented in texinfo manual and not in readline.h *  *									 *  *************************************************************************/
end_comment

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
name|rl_arg_sign
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

begin_decl_stmt
specifier|extern
name|int
name|rl_byte_oriented
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_rl_keyseq_cxt
modifier|*
name|_rl_kscxt
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
comment|/* kill.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_set_retained_kills
name|PARAMS
argument_list|(
operator|(
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_rl_keyseq_cxt
modifier|*
name|_rl_keyseq_cxt_alloc
name|PARAMS
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
name|_rl_keyseq_cxt_dispose
name|PARAMS
argument_list|(
operator|(
name|_rl_keyseq_cxt
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_keyseq_chain_dispose
name|PARAMS
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
name|_rl_dispatch_callback
name|PARAMS
argument_list|(
operator|(
name|_rl_keyseq_cxt
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* callback.c */
end_comment

begin_decl_stmt
specifier|extern
name|_rl_callback_generic_arg
modifier|*
name|_rl_callback_data_alloc
name|PARAMS
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
name|_rl_callback_data_dispose
name|PARAMS
argument_list|(
operator|(
name|_rl_callback_generic_arg
operator|*
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

begin_comment
comment|/* complete.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|_rl_find_completion_word
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_free_match_list
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|_rl_current_display_line
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|_rl_input_queued
name|PARAMS
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
name|_rl_insert_typein
name|PARAMS
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
name|_rl_unget_char
name|PARAMS
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
name|_rl_pushed_input_available
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* isearch.c */
end_comment

begin_decl_stmt
specifier|extern
name|_rl_search_cxt
modifier|*
name|_rl_scxt_alloc
name|PARAMS
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
name|void
name|_rl_scxt_dispose
name|PARAMS
argument_list|(
operator|(
name|_rl_search_cxt
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
name|_rl_isearch_dispatch
name|PARAMS
argument_list|(
operator|(
name|_rl_search_cxt
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
name|_rl_isearch_callback
name|PARAMS
argument_list|(
operator|(
name|_rl_search_cxt
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_search_getchar
name|PARAMS
argument_list|(
operator|(
name|_rl_search_cxt
operator|*
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* misc.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_arg_overflow
name|PARAMS
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
name|_rl_arg_init
name|PARAMS
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
name|_rl_arg_getchar
name|PARAMS
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
name|_rl_arg_callback
name|PARAMS
argument_list|(
operator|(
name|_rl_arg_cxt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_reset_argument
name|PARAMS
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
name|_rl_start_using_history
name|PARAMS
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
name|_rl_free_saved_history_line
name|PARAMS
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
name|_rl_set_insert_mode
name|PARAMS
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
comment|/* nls.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_init_eightbit
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|_rl_dispatch_subseq
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|Keymap
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_rl_internal_char_cleanup
name|PARAMS
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
name|_rl_disable_tty_signals
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* search.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_nsearch_callback
name|PARAMS
argument_list|(
operator|(
name|_rl_search_cxt
operator|*
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|_rl_set_cursor
name|PARAMS
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
comment|/* text.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_rl_fix_point
name|PARAMS
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
name|_rl_replace_text
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|_rl_insert_char
name|PARAMS
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
name|_rl_overwrite_char
name|PARAMS
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
name|_rl_overwrite_rubout
name|PARAMS
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
name|_rl_rubout_char
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HANDLE_MULTIBYTE
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|_rl_char_search_internal
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
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
name|_rl_char_search_internal
name|PARAMS
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

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|_rl_set_mark_at_pos
name|PARAMS
argument_list|(
operator|(
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
name|UNDO_LIST
modifier|*
name|_rl_copy_undo_entry
name|PARAMS
argument_list|(
operator|(
name|UNDO_LIST
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UNDO_LIST
modifier|*
name|_rl_copy_undo_list
name|PARAMS
argument_list|(
operator|(
name|UNDO_LIST
operator|*
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
name|_rl_abort_internal
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
name|PARAMS
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
comment|/* bind.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_rl_possible_control_prefixes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_rl_possible_meta_prefixes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* callback.c */
end_comment

begin_decl_stmt
specifier|extern
name|_rl_callback_func_t
modifier|*
name|_rl_callback_func
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_rl_callback_generic_arg
modifier|*
name|_rl_callback_data
decl_stmt|;
end_decl_stmt

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
name|_rl_complete_show_unmodified
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
name|_rl_complete_mark_symlink_dirs
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

begin_decl_stmt
specifier|extern
name|int
name|_rl_match_hidden_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_page_completions
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
name|int
name|_rl_want_redisplay
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
comment|/* isearch.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_isearch_terminators
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_rl_search_cxt
modifier|*
name|_rl_iscxt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macro.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_executing_macro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* misc.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_history_preserve_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_history_saved_point
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_rl_arg_cxt
name|_rl_argcxt
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
name|int
name|_rl_bind_stty_chars
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
comment|/* search.c */
end_comment

begin_decl_stmt
specifier|extern
name|_rl_search_cxt
modifier|*
name|_rl_nscxt
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
name|_rl_term_clreol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_clrpag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_im
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_ic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_ei
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_DC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_up
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_dc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_cr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_IC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_rl_term_forward_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_screenheight
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_screenwidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_screenchars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_terminal_can_insert
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

begin_comment
comment|/* vi_mode.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_rl_vi_last_command
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

