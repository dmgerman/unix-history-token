begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Readline.h -- the names of functions callable from within readline. */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1989, 1992 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 1, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_READLINE_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_READLINE_H_
end_define

begin_include
include|#
directive|include
file|<readline/keymaps.h>
end_include

begin_comment
comment|/* The functions for manipulating the text of the line within readline. Most of these functions are bound to keys by default. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_tilde_expand
argument_list|()
decl_stmt|,
name|rl_beg_of_line
argument_list|()
decl_stmt|,
name|rl_backward
argument_list|()
decl_stmt|,
name|rl_delete
argument_list|()
decl_stmt|,
name|rl_end_of_line
argument_list|()
decl_stmt|,
name|rl_forward
argument_list|()
decl_stmt|,
name|ding
argument_list|()
decl_stmt|,
name|rl_backward
argument_list|()
decl_stmt|,
name|rl_newline
argument_list|()
decl_stmt|,
name|rl_kill_line
argument_list|()
decl_stmt|,
name|rl_clear_screen
argument_list|()
decl_stmt|,
name|rl_get_next_history
argument_list|()
decl_stmt|,
name|rl_get_previous_history
argument_list|()
decl_stmt|,
name|rl_quoted_insert
argument_list|()
decl_stmt|,
name|rl_reverse_search_history
argument_list|()
decl_stmt|,
name|rl_transpose_chars
argument_list|()
decl_stmt|,
name|rl_unix_line_discard
argument_list|()
decl_stmt|,
name|rl_quoted_insert
argument_list|()
decl_stmt|,
name|rl_unix_word_rubout
argument_list|()
decl_stmt|,
name|rl_yank
argument_list|()
decl_stmt|,
name|rl_rubout
argument_list|()
decl_stmt|,
name|rl_backward_word
argument_list|()
decl_stmt|,
name|rl_kill_word
argument_list|()
decl_stmt|,
name|rl_forward_word
argument_list|()
decl_stmt|,
name|rl_tab_insert
argument_list|()
decl_stmt|,
name|rl_yank_pop
argument_list|()
decl_stmt|,
name|rl_yank_nth_arg
argument_list|()
decl_stmt|,
name|rl_backward_kill_word
argument_list|()
decl_stmt|,
name|rl_backward_kill_line
argument_list|()
decl_stmt|,
name|rl_transpose_words
argument_list|()
decl_stmt|,
name|rl_complete
argument_list|()
decl_stmt|,
name|rl_possible_completions
argument_list|()
decl_stmt|,
name|rl_insert_completions
argument_list|()
decl_stmt|,
name|rl_do_lowercase_version
argument_list|()
decl_stmt|,
name|rl_digit_argument
argument_list|()
decl_stmt|,
name|rl_universal_argument
argument_list|()
decl_stmt|,
name|rl_abort
argument_list|()
decl_stmt|,
name|rl_undo_command
argument_list|()
decl_stmt|,
name|rl_revert_line
argument_list|()
decl_stmt|,
name|rl_beginning_of_history
argument_list|()
decl_stmt|,
name|rl_end_of_history
argument_list|()
decl_stmt|,
name|rl_forward_search_history
argument_list|()
decl_stmt|,
name|rl_insert
argument_list|()
decl_stmt|,
name|rl_upcase_word
argument_list|()
decl_stmt|,
name|rl_downcase_word
argument_list|()
decl_stmt|,
name|rl_capitalize_word
argument_list|()
decl_stmt|,
name|rl_restart_output
argument_list|()
decl_stmt|,
name|rl_re_read_init_file
argument_list|()
decl_stmt|,
name|rl_dump_functions
argument_list|()
decl_stmt|,
name|rl_delete_horizontal_space
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #define PAREN_MATCHING */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PAREN_MATCHING
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|rl_insert_close
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PAREN_MATCHING */
end_comment

begin_comment
comment|/* These are *both* defined even when VI_MODE is not. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_vi_editing_mode
argument_list|()
decl_stmt|,
name|rl_emacs_editing_mode
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non incremental history searching. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_noninc_forward_search
argument_list|()
decl_stmt|,
name|rl_noninc_reverse_search
argument_list|()
decl_stmt|,
name|rl_noninc_forward_search_again
argument_list|()
decl_stmt|,
name|rl_noninc_reverse_search_again
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VI_MODE
argument_list|)
end_if

begin_comment
comment|/* Things for vi mode. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_vi_redo
argument_list|()
decl_stmt|,
name|rl_vi_tilde_expand
argument_list|()
decl_stmt|,
name|rl_vi_movement_mode
argument_list|()
decl_stmt|,
name|rl_vi_insertion_mode
argument_list|()
decl_stmt|,
name|rl_vi_arg_digit
argument_list|()
decl_stmt|,
name|rl_vi_prev_word
argument_list|()
decl_stmt|,
name|rl_vi_next_word
argument_list|()
decl_stmt|,
name|rl_vi_char_search
argument_list|()
decl_stmt|,
name|rl_vi_eof_maybe
argument_list|()
decl_stmt|,
name|rl_vi_append_mode
argument_list|()
decl_stmt|,
name|rl_vi_put
argument_list|()
decl_stmt|,
name|rl_vi_append_eol
argument_list|()
decl_stmt|,
name|rl_vi_insert_beg
argument_list|()
decl_stmt|,
name|rl_vi_delete
argument_list|()
decl_stmt|,
name|rl_vi_comment
argument_list|()
decl_stmt|,
name|rl_vi_first_print
argument_list|()
decl_stmt|,
name|rl_vi_fword
argument_list|()
decl_stmt|,
name|rl_vi_fWord
argument_list|()
decl_stmt|,
name|rl_vi_bword
argument_list|()
decl_stmt|,
name|rl_vi_bWord
argument_list|()
decl_stmt|,
name|rl_vi_eword
argument_list|()
decl_stmt|,
name|rl_vi_eWord
argument_list|()
decl_stmt|,
name|rl_vi_end_word
argument_list|()
decl_stmt|,
name|rl_vi_change_case
argument_list|()
decl_stmt|,
name|rl_vi_match
argument_list|()
decl_stmt|,
name|rl_vi_bracktype
argument_list|()
decl_stmt|,
name|rl_vi_change_char
argument_list|()
decl_stmt|,
name|rl_vi_yank_arg
argument_list|()
decl_stmt|,
name|rl_vi_search
argument_list|()
decl_stmt|,
name|rl_vi_search_again
argument_list|()
decl_stmt|,
name|rl_vi_subst
argument_list|()
decl_stmt|,
name|rl_vi_overstrike
argument_list|()
decl_stmt|,
name|rl_vi_overstrike_delete
argument_list|()
decl_stmt|,
name|rl_vi_replace
argument_list|()
decl_stmt|,
name|rl_vi_column
argument_list|()
decl_stmt|,
name|rl_vi_delete_to
argument_list|()
decl_stmt|,
name|rl_vi_change_to
argument_list|()
decl_stmt|,
name|rl_vi_yank_to
argument_list|()
decl_stmt|,
name|rl_vi_complete
argument_list|()
decl_stmt|,
name|rl_vi_fetch_history
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VI_MODE */
end_comment

begin_comment
comment|/* Keyboard macro commands. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_start_kbd_macro
argument_list|()
decl_stmt|,
name|rl_end_kbd_macro
argument_list|()
decl_stmt|,
name|rl_call_last_kbd_macro
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rl_arrow_keys
argument_list|()
decl_stmt|,
name|rl_refresh_line
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maintaining the state of undo.  We remember individual deletes and inserts    on a chain of things to do. */
end_comment

begin_comment
comment|/* The actions that undo knows how to undo.  Notice that UNDO_DELETE means    to insert some text, and UNDO_INSERT means to delete some text.   I.e.,    the code tells undo what to undo, not how to undo it. */
end_comment

begin_enum
enum|enum
name|undo_code
block|{
name|UNDO_DELETE
block|,
name|UNDO_INSERT
block|,
name|UNDO_BEGIN
block|,
name|UNDO_END
block|}
enum|;
end_enum

begin_comment
comment|/* What an element of THE_UNDO_LIST looks like. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|undo_list
block|{
name|struct
name|undo_list
modifier|*
name|next
decl_stmt|;
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
comment|/* Where the change took place. */
name|char
modifier|*
name|text
decl_stmt|;
comment|/* The text to insert, if undoing a delete. */
name|enum
name|undo_code
name|what
decl_stmt|;
comment|/* Delete, Insert, Begin, End. */
block|}
name|UNDO_LIST
typedef|;
end_typedef

begin_comment
comment|/* The current undo list for RL_LINE_BUFFER. */
end_comment

begin_decl_stmt
specifier|extern
name|UNDO_LIST
modifier|*
name|rl_undo_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The data structure for mapping textual names to code addresses. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|Function
modifier|*
name|function
decl_stmt|;
block|}
name|FUNMAP
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FUNMAP
modifier|*
modifier|*
name|funmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Well Published Variables		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* The name of the calling program.  You should initialize this to    whatever was in argv[0].  It is used when parsing conditionals. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_readline_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The line buffer that is in use. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_line_buffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The location of point, and end. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_point
decl_stmt|,
name|rl_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The name of the terminal to use. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_terminal_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The input and output streams. */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|rl_instream
decl_stmt|,
modifier|*
name|rl_outstream
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The basic list of characters that signal a break between words for the    completer routine.  The initial contents of this variable is what    breaks words in the shell, i.e. "n\"\\'`@$>". */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_basic_word_break_characters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The list of characters that signal a break between words for    rl_complete_internal.  The default list is the contents of    rl_basic_word_break_characters.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_completer_word_break_characters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of characters which are used to quote a substring of the command    line, upon which completion is to be performed for the entire substring.    Within quoted substrings, rl_completer_word_break_characters are treated    as normal characters, unless they also appear in this list. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_completer_quote_characters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of characters that are word break characters, but should be left    in TEXT when it is passed to the completion function.  The shell uses    this to help determine what kind of completing to do. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rl_special_prefixes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the generator function for completion_matches ().    NULL means to use filename_entry_function (), the default filename    completer. */
end_comment

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|rl_completion_entry_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If rl_ignore_some_completions_function is non-NULL it is the address    of a function to call after all of the possible matches have been    generated, but before the actual completion is done to the input line.    The function is called with one argument; a NULL terminated array    of (char *).  If your function removes any of the elements, they    must be free()'ed. */
end_comment

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|rl_ignore_some_completions_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to alternative function to create matches.    Function is called with TEXT, START, and END.    START and END are indices in RL_LINE_BUFFER saying what the boundaries    of TEXT are.    If this function exists and returns NULL then call the value of    rl_completion_entry_function to try to match, otherwise use the    array of strings returned. */
end_comment

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|rl_attempted_completion_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-zero, then this is the address of a function to call just    before readline_internal () prints the first prompt. */
end_comment

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|rl_startup_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-zero, then this is the address of a function to call when    completing on a directory name.  The function is called with    the address of a string (the current directory name) as an arg. */
end_comment

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|rl_symbolic_link_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The address of a function to call periodically while Readline is    awaiting character input, or NULL, for no event handling. */
end_comment

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|rl_event_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero means that modified history lines are preceded    with an asterisk. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_show_star
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/*             Tilde Variables That Can be Externally Set           */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* If non-null, this contains the address of a function to call if the    standard meaning for expanding a tilde fails.  The function is called    with the text (sans tilde, as in "foo"), and returns a malloc()'ed string    which is the expansion, or a NULL pointer if there is no expansion. */
end_comment

begin_decl_stmt
specifier|extern
name|Function
modifier|*
name|tilde_expansion_failure_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When non-null, this is a NULL terminated array of strings which    are duplicates for a tilde prefix.  Bash uses this to expand    `=~' and `:~'. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|tilde_additional_prefixes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When non-null, this is a NULL terminated array of strings which match    the end of a username, instead of just "/".  Bash sets this to    `/' and `:'. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|tilde_additional_suffixes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Well Published Functions		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Read a line of input.  Prompt with PROMPT.  A NULL PROMPT means none. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|readline
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return an array of strings which are the result of repeatadly calling    FUNC with TEXT. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|completion_matches
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* rl_add_defun (char *name, Function *function, int key)    Add NAME to the list of named functions.  Make FUNCTION    be the function that gets called.    If KEY is not -1, then bind it. */
end_comment

begin_function_decl
specifier|extern
name|int
name|rl_add_defun
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _READLINE_H_ */
end_comment

end_unit

