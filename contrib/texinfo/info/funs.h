begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* funs.h -- Generated declarations for Info commands. */
end_comment

begin_comment
comment|/* Functions declared in "./session.c". */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_next_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_prev_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_end_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_beginning_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_forward_char
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_backward_char
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_forward_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_backward_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_global_next_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_global_prev_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_scroll_forward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_scroll_forward_set_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_scroll_backward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_scroll_backward_set_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_beginning_of_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_end_of_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_down_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_up_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_scroll_half_screen_down
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_scroll_half_screen_up
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_next_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_prev_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_split_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_delete_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_keep_one_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_scroll_other_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_scroll_other_window_backward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_grow_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_tile_windows
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_toggle_wrap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_next_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_prev_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_up_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_last_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_first_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_last_menu_item
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_menu_digit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_menu_item
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_xref_item
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_find_menu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_visit_menu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_goto_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_menu_sequence
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_goto_invocation_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_man
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_top_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_dir_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_history_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_kill_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_view_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_print_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_search_case_sensitively
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_search_backward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_search_next
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_search_previous
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isearch_forward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|isearch_backward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_move_to_prev_xref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_move_to_next_xref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_select_reference_this_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_abort_key
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_move_to_window_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_redraw_display
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_quit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_do_lowercase_version
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_add_digit_to_numeric_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_universal_argument
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_numeric_arg_digit_loop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions declared in "./echo-area.c". */
end_comment

begin_function_decl
specifier|extern
name|void
name|ea_forward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_backward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_beg_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_end_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_forward_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_backward_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_rubout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_abort
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_newline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_quoted_insert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_insert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_tab_insert
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_transpose_chars
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_yank
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_yank_pop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_kill_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_backward_kill_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_kill_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_backward_kill_word
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_possible_completions
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_complete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ea_scroll_completions_window
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions declared in "./infodoc.c". */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_get_help_window
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_get_info_help_node
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|describe_key
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_where_is
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions declared in "./m-x.c". */
end_comment

begin_function_decl
specifier|extern
name|void
name|describe_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_execute_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_screen_height
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions declared in "./indices.c". */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_index_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_next_index_match
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|info_index_apropos
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions declared in "./nodemenu.c". */
end_comment

begin_function_decl
specifier|extern
name|void
name|list_visited_nodes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|select_visited_node
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions declared in "./footnotes.c". */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_show_footnotes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Functions declared in "./variables.c". */
end_comment

begin_function_decl
specifier|extern
name|void
name|describe_variable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_variable
parameter_list|()
function_decl|;
end_function_decl

end_unit

