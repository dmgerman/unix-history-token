begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* session.h -- Functions found in session.c.    $Id: session.h,v 1.10 2001/11/16 23:17:15 karl Exp $     Copyright (C) 1993, 98, 99, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SESSION_H
end_ifndef

begin_define
define|#
directive|define
name|SESSION_H
end_define

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"dribble.h"
end_include

begin_comment
comment|/* All commands that can be invoked from within info_session () receive    arguments in the same way.  This simple define declares the header    of a function named NAME, with associated documentation DOC.  The    documentation string is groveled out of the source files by the    utility program `makedoc', which is also responsible for making    the documentation/function-pointer maps. */
end_comment

begin_define
define|#
directive|define
name|DECLARE_INFO_COMMAND
parameter_list|(
name|name
parameter_list|,
name|doc
parameter_list|)
define|\
value|void name (window, count, key) WINDOW *window; int count; unsigned char key;
end_define

begin_comment
comment|/* Variables found in session.h. */
end_comment

begin_decl_stmt
specifier|extern
name|VFunction
modifier|*
name|info_last_executed_command
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variable controlling the garbage collection of files briefly visited    during searches.  Such files are normally gc'ed, unless they were    compressed to begin with.  If this variable is non-zero, it says    to gc even those file buffer contents which had to be uncompressed. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gc_compressed_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When non-zero, tiling takes place automatically when info_split_window    is called. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auto_tiling_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variable controlling the behaviour of default scrolling when you are    already at the bottom of a node. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_scroll_behaviour
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|info_scroll_choices
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values for info_scroll_behaviour. */
end_comment

begin_define
define|#
directive|define
name|IS_Continuous
value|0
end_define

begin_comment
comment|/* Try to get first menu item, or failing that, the                            "Next:" pointer, or failing that, the "Up:" and                            "Next:" of the up. */
end_comment

begin_define
define|#
directive|define
name|IS_NextOnly
value|1
end_define

begin_comment
comment|/* Try to get "Next:" menu item. */
end_comment

begin_define
define|#
directive|define
name|IS_PageOnly
value|2
end_define

begin_comment
comment|/* Simply give up at the bottom of a node. */
end_comment

begin_comment
comment|/* Utility functions found in session.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_dispatch_on_key
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|info_get_input_char
argument_list|()
decl_stmt|,
name|info_get_another_input_char
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|unsigned
name|char
name|info_input_pending_p
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|remember_window_and_node
argument_list|()
decl_stmt|,
name|set_remembered_pagetop_and_point
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_window_pagetop
argument_list|()
decl_stmt|,
name|info_set_node_of_window
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initialize_keyseq
argument_list|()
decl_stmt|,
name|add_char_to_keyseq
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|info_gather_typeahead
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE_BUFFER
modifier|*
name|file_buffer_of_window
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|long
name|info_search_in_node
argument_list|()
decl_stmt|,
name|info_target_search_node
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|info_select_reference
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|info_any_buffered_input_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_node
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|dump_node_to_file
argument_list|()
decl_stmt|,
name|dump_nodes_to_file
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|program_name_from_file_name
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Do the physical deletion of WINDOW, and forget this window and    associated nodes. */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_delete_window_internal
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Tell Info that input is coming from the file FILENAME. */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_set_input_from_file
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|return_if_control_g
parameter_list|(
name|val
parameter_list|)
define|\
value|do { \     info_gather_typeahead (); \     if (info_input_pending_p () == Control ('g')) \       return (val); \   } while (0)
end_define

begin_comment
comment|/* The names of the functions that run an info session. */
end_comment

begin_comment
comment|/* Starting an info session. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|begin_multiple_window_info_session
argument_list|()
decl_stmt|,
name|begin_info_session
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|begin_info_session_with_error
argument_list|()
decl_stmt|,
name|info_session
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|info_read_and_dispatch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Moving the point within a node. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|info_next_line
argument_list|()
decl_stmt|,
name|info_prev_line
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_end_of_line
argument_list|()
decl_stmt|,
name|info_beginning_of_line
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_forward_char
argument_list|()
decl_stmt|,
name|info_backward_char
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_forward_word
argument_list|()
decl_stmt|,
name|info_backward_word
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_beginning_of_node
argument_list|()
decl_stmt|,
name|info_end_of_node
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_move_to_prev_xref
argument_list|()
decl_stmt|,
name|info_move_to_next_xref
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scrolling text within a window. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|info_scroll_forward
argument_list|()
decl_stmt|,
name|info_scroll_backward
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_redraw_display
argument_list|()
decl_stmt|,
name|info_toggle_wrap
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|info_move_to_window_line
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|info_up_line
argument_list|()
decl_stmt|,
name|info_down_line
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_scroll_half_screen_down
argument_list|()
decl_stmt|,
name|info_scroll_half_screen_up
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Manipulating multiple windows. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|info_split_window
argument_list|()
decl_stmt|,
name|info_delete_window
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_keep_one_window
argument_list|()
decl_stmt|,
name|info_grow_window
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_scroll_other_window
argument_list|()
decl_stmt|,
name|info_tile_windows
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_next_window
argument_list|()
decl_stmt|,
name|info_prev_window
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Selecting nodes. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|info_next_node
argument_list|()
decl_stmt|,
name|info_prev_node
argument_list|()
decl_stmt|,
name|info_up_node
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_last_node
argument_list|()
decl_stmt|,
name|info_first_node
argument_list|()
decl_stmt|,
name|info_history_node
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_goto_node
argument_list|()
decl_stmt|,
name|info_top_node
argument_list|()
decl_stmt|,
name|info_dir_node
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_global_next_node
argument_list|()
decl_stmt|,
name|info_global_prev_node
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_kill_node
argument_list|()
decl_stmt|,
name|info_view_file
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|info_menu_sequence
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NODE
modifier|*
name|info_follow_menus
parameter_list|(
comment|/* initial_node, menus, errstr, errarg */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Selecting cross references. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|info_menu_digit
argument_list|()
decl_stmt|,
name|info_menu_item
argument_list|()
decl_stmt|,
name|info_xref_item
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_find_menu
argument_list|()
decl_stmt|,
name|info_select_reference_this_line
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hacking numeric arguments. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_explicit_arg
decl_stmt|,
name|info_numeric_arg
decl_stmt|,
name|info_numeric_arg_sign
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_add_digit_to_numeric_arg
argument_list|()
decl_stmt|,
name|info_universal_argument
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_initialize_numeric_arg
argument_list|()
decl_stmt|,
name|info_numeric_arg_digit_loop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Searching commands. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|info_search
argument_list|()
decl_stmt|,
name|isearch_forward
argument_list|()
decl_stmt|,
name|isearch_backward
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_search_case_sensitively
argument_list|()
decl_stmt|,
name|info_search_backward
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|info_search_next
argument_list|()
decl_stmt|,
name|info_search_previous
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dumping and printing nodes. */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_print_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Miscellaneous commands. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|info_abort_key
argument_list|()
decl_stmt|,
name|info_quit
argument_list|()
decl_stmt|,
name|info_do_lowercase_version
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not SESSION_H */
end_comment

end_unit

