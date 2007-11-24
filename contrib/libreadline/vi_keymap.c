begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vi_keymap.c -- the keymap for vi_mode in readline (). */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1989, 1992 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BUFSIZ
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BUFSIZ */
end_comment

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern KEYMAP_ENTRY_ARRAY vi_escape_keymap;
endif|#
directive|endif
end_endif

begin_comment
comment|/* The keymap arrays for handling vi mode. */
end_comment

begin_decl_stmt
name|KEYMAP_ENTRY_ARRAY
name|vi_movement_keymap
init|=
block|{
comment|/* The regular control keys come first. */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-@ */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-a */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-b */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-c */
block|{
name|ISFUNC
block|,
name|rl_vi_eof_maybe
block|}
block|,
comment|/* Control-d */
block|{
name|ISFUNC
block|,
name|rl_emacs_editing_mode
block|}
block|,
comment|/* Control-e */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-f */
block|{
name|ISFUNC
block|,
name|rl_abort
block|}
block|,
comment|/* Control-g */
block|{
name|ISFUNC
block|,
name|rl_backward_char
block|}
block|,
comment|/* Control-h */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-i */
block|{
name|ISFUNC
block|,
name|rl_newline
block|}
block|,
comment|/* Control-j */
block|{
name|ISFUNC
block|,
name|rl_kill_line
block|}
block|,
comment|/* Control-k */
block|{
name|ISFUNC
block|,
name|rl_clear_screen
block|}
block|,
comment|/* Control-l */
block|{
name|ISFUNC
block|,
name|rl_newline
block|}
block|,
comment|/* Control-m */
block|{
name|ISFUNC
block|,
name|rl_get_next_history
block|}
block|,
comment|/* Control-n */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-o */
block|{
name|ISFUNC
block|,
name|rl_get_previous_history
block|}
block|,
comment|/* Control-p */
block|{
name|ISFUNC
block|,
name|rl_quoted_insert
block|}
block|,
comment|/* Control-q */
block|{
name|ISFUNC
block|,
name|rl_reverse_search_history
block|}
block|,
comment|/* Control-r */
block|{
name|ISFUNC
block|,
name|rl_forward_search_history
block|}
block|,
comment|/* Control-s */
block|{
name|ISFUNC
block|,
name|rl_transpose_chars
block|}
block|,
comment|/* Control-t */
block|{
name|ISFUNC
block|,
name|rl_unix_line_discard
block|}
block|,
comment|/* Control-u */
block|{
name|ISFUNC
block|,
name|rl_quoted_insert
block|}
block|,
comment|/* Control-v */
block|{
name|ISFUNC
block|,
name|rl_unix_word_rubout
block|}
block|,
comment|/* Control-w */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-x */
block|{
name|ISFUNC
block|,
name|rl_yank
block|}
block|,
comment|/* Control-y */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-z */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-[ */
comment|/* vi_escape_keymap */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-\ */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-] */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-^ */
block|{
name|ISFUNC
block|,
name|rl_vi_undo
block|}
block|,
comment|/* Control-_ */
comment|/* The start of printing characters. */
block|{
name|ISFUNC
block|,
name|rl_forward_char
block|}
block|,
comment|/* SPACE */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ! */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* " */
block|{
name|ISFUNC
block|,
name|rl_insert_comment
block|}
block|,
comment|/* # */
block|{
name|ISFUNC
block|,
name|rl_end_of_line
block|}
block|,
comment|/* $ */
block|{
name|ISFUNC
block|,
name|rl_vi_match
block|}
block|,
comment|/* % */
block|{
name|ISFUNC
block|,
name|rl_vi_tilde_expand
block|}
block|,
comment|/*& */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ' */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ( */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ) */
block|{
name|ISFUNC
block|,
name|rl_vi_complete
block|}
block|,
comment|/* * */
block|{
name|ISFUNC
block|,
name|rl_get_next_history
block|}
block|,
comment|/* + */
block|{
name|ISFUNC
block|,
name|rl_vi_char_search
block|}
block|,
comment|/* , */
block|{
name|ISFUNC
block|,
name|rl_get_previous_history
block|}
block|,
comment|/* - */
block|{
name|ISFUNC
block|,
name|rl_vi_redo
block|}
block|,
comment|/* . */
block|{
name|ISFUNC
block|,
name|rl_vi_search
block|}
block|,
comment|/* / */
comment|/* Regular digits. */
block|{
name|ISFUNC
block|,
name|rl_beg_of_line
block|}
block|,
comment|/* 0 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 1 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 2 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 3 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 4 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 5 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 6 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 7 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 8 */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
block|}
block|,
comment|/* 9 */
comment|/* A little more punctuation. */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* : */
block|{
name|ISFUNC
block|,
name|rl_vi_char_search
block|}
block|,
comment|/* ; */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/*< */
block|{
name|ISFUNC
block|,
name|rl_vi_complete
block|}
block|,
comment|/* = */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/*> */
block|{
name|ISFUNC
block|,
name|rl_vi_search
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* @ */
comment|/* Uppercase alphabet. */
block|{
name|ISFUNC
block|,
name|rl_vi_append_eol
block|}
block|,
comment|/* A */
block|{
name|ISFUNC
block|,
name|rl_vi_prev_word
block|}
block|,
comment|/* B */
block|{
name|ISFUNC
block|,
name|rl_vi_change_to
block|}
block|,
comment|/* C */
block|{
name|ISFUNC
block|,
name|rl_vi_delete_to
block|}
block|,
comment|/* D */
block|{
name|ISFUNC
block|,
name|rl_vi_end_word
block|}
block|,
comment|/* E */
block|{
name|ISFUNC
block|,
name|rl_vi_char_search
block|}
block|,
comment|/* F */
block|{
name|ISFUNC
block|,
name|rl_vi_fetch_history
block|}
block|,
comment|/* G */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* H */
block|{
name|ISFUNC
block|,
name|rl_vi_insert_beg
block|}
block|,
comment|/* I */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* J */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* K */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* L */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* M */
block|{
name|ISFUNC
block|,
name|rl_vi_search_again
block|}
block|,
comment|/* N */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* O */
block|{
name|ISFUNC
block|,
name|rl_vi_put
block|}
block|,
comment|/* P */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Q */
block|{
name|ISFUNC
block|,
name|rl_vi_replace
block|}
block|,
comment|/* R */
block|{
name|ISFUNC
block|,
name|rl_vi_subst
block|}
block|,
comment|/* S */
block|{
name|ISFUNC
block|,
name|rl_vi_char_search
block|}
block|,
comment|/* T */
block|{
name|ISFUNC
block|,
name|rl_revert_line
block|}
block|,
comment|/* U */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* V */
block|{
name|ISFUNC
block|,
name|rl_vi_next_word
block|}
block|,
comment|/* W */
block|{
name|ISFUNC
block|,
name|rl_vi_rubout
block|}
block|,
comment|/* X */
block|{
name|ISFUNC
block|,
name|rl_vi_yank_to
block|}
block|,
comment|/* Y */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Z */
comment|/* Some more punctuation. */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* [ */
block|{
name|ISFUNC
block|,
name|rl_vi_complete
block|}
block|,
comment|/* \ */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ] */
block|{
name|ISFUNC
block|,
name|rl_vi_first_print
block|}
block|,
comment|/* ^ */
block|{
name|ISFUNC
block|,
name|rl_vi_yank_arg
block|}
block|,
comment|/* _ */
block|{
name|ISFUNC
block|,
name|rl_vi_goto_mark
block|}
block|,
comment|/* ` */
comment|/* Lowercase alphabet. */
block|{
name|ISFUNC
block|,
name|rl_vi_append_mode
block|}
block|,
comment|/* a */
block|{
name|ISFUNC
block|,
name|rl_vi_prev_word
block|}
block|,
comment|/* b */
block|{
name|ISFUNC
block|,
name|rl_vi_change_to
block|}
block|,
comment|/* c */
block|{
name|ISFUNC
block|,
name|rl_vi_delete_to
block|}
block|,
comment|/* d */
block|{
name|ISFUNC
block|,
name|rl_vi_end_word
block|}
block|,
comment|/* e */
block|{
name|ISFUNC
block|,
name|rl_vi_char_search
block|}
block|,
comment|/* f */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* g */
block|{
name|ISFUNC
block|,
name|rl_backward_char
block|}
block|,
comment|/* h */
block|{
name|ISFUNC
block|,
name|rl_vi_insertion_mode
block|}
block|,
comment|/* i */
block|{
name|ISFUNC
block|,
name|rl_get_next_history
block|}
block|,
comment|/* j */
block|{
name|ISFUNC
block|,
name|rl_get_previous_history
block|}
block|,
comment|/* k */
block|{
name|ISFUNC
block|,
name|rl_forward_char
block|}
block|,
comment|/* l */
block|{
name|ISFUNC
block|,
name|rl_vi_set_mark
block|}
block|,
comment|/* m */
block|{
name|ISFUNC
block|,
name|rl_vi_search_again
block|}
block|,
comment|/* n */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* o */
block|{
name|ISFUNC
block|,
name|rl_vi_put
block|}
block|,
comment|/* p */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* q */
block|{
name|ISFUNC
block|,
name|rl_vi_change_char
block|}
block|,
comment|/* r */
block|{
name|ISFUNC
block|,
name|rl_vi_subst
block|}
block|,
comment|/* s */
block|{
name|ISFUNC
block|,
name|rl_vi_char_search
block|}
block|,
comment|/* t */
block|{
name|ISFUNC
block|,
name|rl_vi_undo
block|}
block|,
comment|/* u */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* v */
block|{
name|ISFUNC
block|,
name|rl_vi_next_word
block|}
block|,
comment|/* w */
block|{
name|ISFUNC
block|,
name|rl_vi_delete
block|}
block|,
comment|/* x */
block|{
name|ISFUNC
block|,
name|rl_vi_yank_to
block|}
block|,
comment|/* y */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* z */
comment|/* Final punctuation. */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* { */
block|{
name|ISFUNC
block|,
name|rl_vi_column
block|}
block|,
comment|/* | */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* } */
block|{
name|ISFUNC
block|,
name|rl_vi_change_case
block|}
block|,
comment|/* ~ */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* RUBOUT */
if|#
directive|if
name|KEYMAP_SIZE
operator|>
literal|128
comment|/* Undefined keys. */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
endif|#
directive|endif
comment|/* KEYMAP_SIZE> 128 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KEYMAP_ENTRY_ARRAY
name|vi_insertion_keymap
init|=
block|{
comment|/* The regular control keys come first. */
block|{
name|ISFUNC
block|,
operator|(
name|rl_command_func_t
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-@ */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-a */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-b */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-c */
block|{
name|ISFUNC
block|,
name|rl_vi_eof_maybe
block|}
block|,
comment|/* Control-d */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-e */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-f */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-g */
block|{
name|ISFUNC
block|,
name|rl_rubout
block|}
block|,
comment|/* Control-h */
block|{
name|ISFUNC
block|,
name|rl_complete
block|}
block|,
comment|/* Control-i */
block|{
name|ISFUNC
block|,
name|rl_newline
block|}
block|,
comment|/* Control-j */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-k */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-l */
block|{
name|ISFUNC
block|,
name|rl_newline
block|}
block|,
comment|/* Control-m */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-n */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-o */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-p */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-q */
block|{
name|ISFUNC
block|,
name|rl_reverse_search_history
block|}
block|,
comment|/* Control-r */
block|{
name|ISFUNC
block|,
name|rl_forward_search_history
block|}
block|,
comment|/* Control-s */
block|{
name|ISFUNC
block|,
name|rl_transpose_chars
block|}
block|,
comment|/* Control-t */
block|{
name|ISFUNC
block|,
name|rl_unix_line_discard
block|}
block|,
comment|/* Control-u */
block|{
name|ISFUNC
block|,
name|rl_quoted_insert
block|}
block|,
comment|/* Control-v */
block|{
name|ISFUNC
block|,
name|rl_unix_word_rubout
block|}
block|,
comment|/* Control-w */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-x */
block|{
name|ISFUNC
block|,
name|rl_yank
block|}
block|,
comment|/* Control-y */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-z */
block|{
name|ISFUNC
block|,
name|rl_vi_movement_mode
block|}
block|,
comment|/* Control-[ */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-\ */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-] */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Control-^ */
block|{
name|ISFUNC
block|,
name|rl_vi_undo
block|}
block|,
comment|/* Control-_ */
comment|/* The start of printing characters. */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* SPACE */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ! */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* " */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* # */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* $ */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* % */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/*& */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ' */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ( */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ) */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* * */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* + */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* , */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* - */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* . */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* / */
comment|/* Regular digits. */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 0 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 1 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 2 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 3 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 4 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 5 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 6 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 7 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 8 */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* 9 */
comment|/* A little more punctuation. */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* : */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ; */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/*< */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* = */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/*> */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* @ */
comment|/* Uppercase alphabet. */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* A */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* B */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* C */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* D */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* E */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* F */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* G */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* H */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* I */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* J */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* K */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* L */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* M */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* N */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* O */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* P */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Q */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* R */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* S */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* T */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* U */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* V */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* W */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* X */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Y */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Z */
comment|/* Some more punctuation. */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* [ */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* \ */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ] */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ^ */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* _ */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ` */
comment|/* Lowercase alphabet. */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* a */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* b */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* c */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* d */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* e */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* f */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* g */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* h */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* i */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* j */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* k */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* l */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* m */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* n */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* o */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* p */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* q */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* r */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* s */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* t */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* u */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* v */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* w */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* x */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* y */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* z */
comment|/* Final punctuation. */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* { */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* | */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* } */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ~ */
block|{
name|ISFUNC
block|,
name|rl_rubout
block|}
block|,
comment|/* RUBOUT */
if|#
directive|if
name|KEYMAP_SIZE
operator|>
literal|128
comment|/* Pure 8-bit characters (128 - 159).      These might be used in some      character sets. */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* ? */
comment|/* ISO Latin-1 characters (160 - 255) */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* No-break space */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Inverted exclamation mark */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Cent sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Pound sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Currency sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Yen sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Broken bar */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Section sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Copyright sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Feminine ordinal indicator */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Left pointing double angle quotation mark */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Not sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Soft hyphen */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Registered sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Macron */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Degree sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Plus-minus sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Superscript two */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Superscript three */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Acute accent */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Micro sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Pilcrow sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Middle dot */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Cedilla */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Superscript one */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Masculine ordinal indicator */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Right pointing double angle quotation mark */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Vulgar fraction one quarter */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Vulgar fraction one half */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Vulgar fraction three quarters */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Inverted questionk mark */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter a with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter a with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter a with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter a with tilde */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter a with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter a with ring above */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter ae */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter c with cedilla */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter e with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter e with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter e with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter e with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter i with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter i with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter i with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter i with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter eth (Icelandic) */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter n with tilde */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter o with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter o with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter o with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter o with tilde */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter o with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Multiplication sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter o with stroke */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter u with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter u with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter u with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter u with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter Y with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin capital letter thorn (Icelandic) */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter sharp s (German) */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter a with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter a with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter a with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter a with tilde */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter a with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter a with ring above */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter ae */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter c with cedilla */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter e with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter e with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter e with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter e with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter i with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter i with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter i with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter i with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter eth (Icelandic) */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter n with tilde */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter o with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter o with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter o with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter o with tilde */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter o with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Division sign */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter o with stroke */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter u with grave */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter u with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter u with circumflex */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter u with diaeresis */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter y with acute */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
block|,
comment|/* Latin small letter thorn (Icelandic) */
block|{
name|ISFUNC
block|,
name|rl_insert
block|}
comment|/* Latin small letter y with diaeresis */
endif|#
directive|endif
comment|/* KEYMAP_SIZE> 128 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Unused for the time being. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|KEYMAP_ENTRY_ARRAY vi_escape_keymap = {
comment|/* The regular control keys come first. */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-@ */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-a */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-b */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-c */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-d */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-e */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-f */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-g */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-h */
end_comment

begin_comment
unit|{ ISFUNC, rl_tab_insert},
comment|/* Control-i */
end_comment

begin_comment
unit|{ ISFUNC, rl_emacs_editing_mode},
comment|/* Control-j */
end_comment

begin_comment
unit|{ ISFUNC, rl_kill_line },
comment|/* Control-k */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-l */
end_comment

begin_comment
unit|{ ISFUNC, rl_emacs_editing_mode},
comment|/* Control-m */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-n */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-o */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-p */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-q */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-r */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-s */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-t */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-u */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-v */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-w */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-x */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-y */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-z */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_movement_mode },
comment|/* Control-[ */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-\ */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-] */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* Control-^ */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_undo },
comment|/* Control-_ */
end_comment

begin_comment
comment|/* The start of printing characters. */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* SPACE */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ! */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* " */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* # */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* $ */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* % */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/*& */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ' */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ( */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ) */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* * */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* + */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* , */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* - */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* . */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* / */
end_comment

begin_comment
comment|/* Regular digits. */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 0 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 1 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 2 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 3 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 4 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 5 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 6 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 7 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 8 */
end_comment

begin_comment
unit|{ ISFUNC, rl_vi_arg_digit },
comment|/* 9 */
end_comment

begin_comment
comment|/* A little more punctuation. */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* : */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ; */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/*< */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* = */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/*> */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ? */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* @ */
end_comment

begin_comment
comment|/* Uppercase alphabet. */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* A */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* B */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* C */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* D */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* E */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* F */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* G */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* H */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* I */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* J */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* K */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* L */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* M */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* N */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* O */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* P */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* Q */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* R */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* S */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* T */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* U */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* V */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* W */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* X */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* Y */
end_comment

begin_comment
unit|{ ISFUNC, rl_do_lowercase_version },
comment|/* Z */
end_comment

begin_comment
comment|/* Some more punctuation. */
end_comment

begin_comment
unit|{ ISFUNC, rl_arrow_keys },
comment|/* [ */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* \ */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ] */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ^ */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* _ */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ` */
end_comment

begin_comment
comment|/* Lowercase alphabet. */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* a */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* b */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* c */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* d */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* e */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* f */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* g */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* h */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* i */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* j */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* k */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* l */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* m */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* n */
end_comment

begin_comment
unit|{ ISFUNC, rl_arrow_keys },
comment|/* o */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* p */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* q */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* r */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* s */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* t */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* u */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* v */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* w */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* x */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* y */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* z */
end_comment

begin_comment
comment|/* Final punctuation. */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* { */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* | */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* } */
end_comment

begin_comment
unit|{ ISFUNC, (rl_command_func_t *)0x0 },
comment|/* ~ */
end_comment

begin_comment
unit|{ ISFUNC, rl_backward_kill_word },
comment|/* RUBOUT */
end_comment

begin_if
if|#
directive|if
name|KEYMAP_SIZE
operator|>
literal|128
end_if

begin_comment
comment|/* Undefined keys. */
end_comment

begin_endif
unit|{ ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 },   { ISFUNC, (rl_command_func_t *)0x0 }
endif|#
directive|endif
end_endif

begin_comment
comment|/* KEYMAP_SIZE> 128 */
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

end_unit

