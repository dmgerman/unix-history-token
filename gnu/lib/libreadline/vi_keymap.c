begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vi_keymap.c -- the keymap for vi_mode in readline (). */
end_comment

begin_comment
comment|/* Copyright (C) 1988,1989 Free Software Foundation, Inc.     This file is part of GNU Readline, a library for reading lines    of text with interactive input and history editing.     Readline is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 1, or (at your option) any    later version.     Readline is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with Readline; see the file COPYING.  If not, write to the Free    Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

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
comment|/* BUFSIZ */
end_comment

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_decl_stmt
specifier|extern
name|KEYMAP_ENTRY_ARRAY
name|vi_escape_keymap
decl_stmt|;
end_decl_stmt

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
name|Function
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
name|Function
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
name|Function
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
name|Function
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
name|Function
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
name|rl_rubout
block|}
block|,
comment|/* Control-h */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
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
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-z */
block|{
name|ISKMAP
block|,
operator|(
name|Function
operator|*
operator|)
name|vi_escape_keymap
block|}
block|,
comment|/* Control-[ */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-^ */
block|{
name|ISFUNC
block|,
name|rl_undo_command
block|}
block|,
comment|/* Control-_ */
comment|/* The start of printing characters. */
block|{
name|ISFUNC
block|,
name|rl_forward
block|}
block|,
comment|/* SPACE */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* " */
block|{
name|ISFUNC
block|,
name|rl_vi_comment
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
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/*& */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
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
name|Function
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
operator|(
name|Function
operator|*
operator|)
literal|0x0
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
name|rl_vi_arg_digit
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
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/*< */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* = */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
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
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* G */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
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
name|Function
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
name|Function
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
name|Function
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
name|Function
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
name|Function
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
name|Function
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
name|rl_rubout
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
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* [ */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* \ */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
operator|(
name|Function
operator|*
operator|)
literal|0x0
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* g */
block|{
name|ISFUNC
block|,
name|rl_backward
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
name|rl_forward
block|}
block|,
comment|/* l */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
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
name|Function
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
name|Function
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
name|rl_undo_command
block|}
block|,
comment|/* u */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
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
name|Function
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
name|Function
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
name|rl_backward
block|}
comment|/* RUBOUT */
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
name|Function
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
name|rl_undo_command
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
comment|/* RUBOUT */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|KEYMAP_ENTRY_ARRAY
name|vi_escape_keymap
init|=
block|{
comment|/* The regular control keys come first. */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
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
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-c */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-d */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-e */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-f */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-g */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-h */
block|{
name|ISFUNC
block|,
name|rl_tab_insert
block|}
block|,
comment|/* Control-i */
block|{
name|ISFUNC
block|,
name|rl_emacs_editing_mode
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
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-l */
block|{
name|ISFUNC
block|,
name|rl_emacs_editing_mode
block|}
block|,
comment|/* Control-m */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-n */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-o */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-p */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-q */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-r */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-s */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-t */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-u */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-v */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-w */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-x */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-y */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
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
operator|(
name|Function
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
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* Control-^ */
block|{
name|ISFUNC
block|,
name|rl_undo_command
block|}
block|,
comment|/* Control-_ */
comment|/* The start of printing characters. */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* SPACE */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* " */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* # */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* $ */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* % */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/*& */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ) */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* * */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* + */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* , */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* - */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* . */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* / */
comment|/* Regular digits. */
block|{
name|ISFUNC
block|,
name|rl_vi_arg_digit
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* : */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ; */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/*< */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* = */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/*> */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ? */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|rl_do_lowercase_version
block|}
block|,
comment|/* A */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* B */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* C */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* D */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* E */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* F */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* G */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* H */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* I */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* J */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* K */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* L */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* M */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* N */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* O */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* P */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* Q */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* R */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* S */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* T */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* U */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* V */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* W */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* X */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* Y */
block|{
name|ISFUNC
block|,
name|rl_do_lowercase_version
block|}
block|,
comment|/* Z */
comment|/* Some more punctuation. */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* [ */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* \ */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ] */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ^ */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* _ */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ` */
comment|/* Lowercase alphabet. */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* a */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* b */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* c */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* d */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* e */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* f */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* g */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* h */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* i */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* j */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* k */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* l */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* m */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* n */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* o */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* p */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* q */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* r */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* s */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* t */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* u */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* v */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* w */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* x */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* y */
block|{
name|ISFUNC
block|,
operator|(
name|Function
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
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* { */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* | */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* } */
block|{
name|ISFUNC
block|,
operator|(
name|Function
operator|*
operator|)
literal|0x0
block|}
block|,
comment|/* ~ */
block|{
name|ISFUNC
block|,
name|rl_backward_kill_word
block|}
comment|/* RUBOUT */
block|}
decl_stmt|;
end_decl_stmt

end_unit

