begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* funs.h -- Generated declarations for Info commands. */
end_comment

begin_comment
comment|/* Functions declared in "./session.c". */
end_comment

begin_define
define|#
directive|define
name|A_info_next_line
value|0
end_define

begin_function_decl
specifier|extern
name|void
name|info_next_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_prev_line
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|info_prev_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_end_of_line
value|2
end_define

begin_function_decl
specifier|extern
name|void
name|info_end_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_beginning_of_line
value|3
end_define

begin_function_decl
specifier|extern
name|void
name|info_beginning_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_forward_char
value|4
end_define

begin_function_decl
specifier|extern
name|void
name|info_forward_char
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_backward_char
value|5
end_define

begin_function_decl
specifier|extern
name|void
name|info_backward_char
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_forward_word
value|6
end_define

begin_function_decl
specifier|extern
name|void
name|info_forward_word
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_backward_word
value|7
end_define

begin_function_decl
specifier|extern
name|void
name|info_backward_word
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_global_next_node
value|8
end_define

begin_function_decl
specifier|extern
name|void
name|info_global_next_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_global_prev_node
value|9
end_define

begin_function_decl
specifier|extern
name|void
name|info_global_prev_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_forward
value|10
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_forward
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_forward_set_window
value|11
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_forward_set_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_forward_page_only
value|12
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_forward_page_only
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_forward_page_only_set_window
value|13
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_forward_page_only_set_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_backward
value|14
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_backward
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_backward_set_window
value|15
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_backward_set_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_backward_page_only
value|16
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_backward_page_only
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_backward_page_only_set_window
value|17
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_backward_page_only_set_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_beginning_of_node
value|18
end_define

begin_function_decl
specifier|extern
name|void
name|info_beginning_of_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_end_of_node
value|19
end_define

begin_function_decl
specifier|extern
name|void
name|info_end_of_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_down_line
value|20
end_define

begin_function_decl
specifier|extern
name|void
name|info_down_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_up_line
value|21
end_define

begin_function_decl
specifier|extern
name|void
name|info_up_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_half_screen_down
value|22
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_half_screen_down
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_half_screen_up
value|23
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_half_screen_up
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_next_window
value|24
end_define

begin_function_decl
specifier|extern
name|void
name|info_next_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_prev_window
value|25
end_define

begin_function_decl
specifier|extern
name|void
name|info_prev_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_split_window
value|26
end_define

begin_function_decl
specifier|extern
name|void
name|info_split_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_delete_window
value|27
end_define

begin_function_decl
specifier|extern
name|void
name|info_delete_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_keep_one_window
value|28
end_define

begin_function_decl
specifier|extern
name|void
name|info_keep_one_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_other_window
value|29
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_other_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_scroll_other_window_backward
value|30
end_define

begin_function_decl
specifier|extern
name|void
name|info_scroll_other_window_backward
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_grow_window
value|31
end_define

begin_function_decl
specifier|extern
name|void
name|info_grow_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_tile_windows
value|32
end_define

begin_function_decl
specifier|extern
name|void
name|info_tile_windows
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_toggle_wrap
value|33
end_define

begin_function_decl
specifier|extern
name|void
name|info_toggle_wrap
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_next_node
value|34
end_define

begin_function_decl
specifier|extern
name|void
name|info_next_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_prev_node
value|35
end_define

begin_function_decl
specifier|extern
name|void
name|info_prev_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_up_node
value|36
end_define

begin_function_decl
specifier|extern
name|void
name|info_up_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_last_node
value|37
end_define

begin_function_decl
specifier|extern
name|void
name|info_last_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_first_node
value|38
end_define

begin_function_decl
specifier|extern
name|void
name|info_first_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_last_menu_item
value|39
end_define

begin_function_decl
specifier|extern
name|void
name|info_last_menu_item
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_menu_digit
value|40
end_define

begin_function_decl
specifier|extern
name|void
name|info_menu_digit
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_menu_item
value|41
end_define

begin_function_decl
specifier|extern
name|void
name|info_menu_item
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_xref_item
value|42
end_define

begin_function_decl
specifier|extern
name|void
name|info_xref_item
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_find_menu
value|43
end_define

begin_function_decl
specifier|extern
name|void
name|info_find_menu
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_visit_menu
value|44
end_define

begin_function_decl
specifier|extern
name|void
name|info_visit_menu
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_goto_node
value|45
end_define

begin_function_decl
specifier|extern
name|void
name|info_goto_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_menu_sequence
value|46
end_define

begin_function_decl
specifier|extern
name|void
name|info_menu_sequence
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_goto_invocation_node
value|47
end_define

begin_function_decl
specifier|extern
name|void
name|info_goto_invocation_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_man
value|48
end_define

begin_function_decl
specifier|extern
name|void
name|info_man
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_top_node
value|49
end_define

begin_function_decl
specifier|extern
name|void
name|info_top_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_dir_node
value|50
end_define

begin_function_decl
specifier|extern
name|void
name|info_dir_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_history_node
value|51
end_define

begin_function_decl
specifier|extern
name|void
name|info_history_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_kill_node
value|52
end_define

begin_function_decl
specifier|extern
name|void
name|info_kill_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_view_file
value|53
end_define

begin_function_decl
specifier|extern
name|void
name|info_view_file
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_print_node
value|54
end_define

begin_function_decl
specifier|extern
name|void
name|info_print_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_search_case_sensitively
value|55
end_define

begin_function_decl
specifier|extern
name|void
name|info_search_case_sensitively
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_search
value|56
end_define

begin_function_decl
specifier|extern
name|void
name|info_search
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_search_backward
value|57
end_define

begin_function_decl
specifier|extern
name|void
name|info_search_backward
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_search_next
value|58
end_define

begin_function_decl
specifier|extern
name|void
name|info_search_next
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_search_previous
value|59
end_define

begin_function_decl
specifier|extern
name|void
name|info_search_previous
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_isearch_forward
value|60
end_define

begin_function_decl
specifier|extern
name|void
name|isearch_forward
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_isearch_backward
value|61
end_define

begin_function_decl
specifier|extern
name|void
name|isearch_backward
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_move_to_prev_xref
value|62
end_define

begin_function_decl
specifier|extern
name|void
name|info_move_to_prev_xref
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_move_to_next_xref
value|63
end_define

begin_function_decl
specifier|extern
name|void
name|info_move_to_next_xref
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_select_reference_this_line
value|64
end_define

begin_function_decl
specifier|extern
name|void
name|info_select_reference_this_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_abort_key
value|65
end_define

begin_function_decl
specifier|extern
name|void
name|info_abort_key
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_move_to_window_line
value|66
end_define

begin_function_decl
specifier|extern
name|void
name|info_move_to_window_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_redraw_display
value|67
end_define

begin_function_decl
specifier|extern
name|void
name|info_redraw_display
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_quit
value|68
end_define

begin_function_decl
specifier|extern
name|void
name|info_quit
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_do_lowercase_version
value|69
end_define

begin_function_decl
specifier|extern
name|void
name|info_do_lowercase_version
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_add_digit_to_numeric_arg
value|70
end_define

begin_function_decl
specifier|extern
name|void
name|info_add_digit_to_numeric_arg
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_universal_argument
value|71
end_define

begin_function_decl
specifier|extern
name|void
name|info_universal_argument
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_numeric_arg_digit_loop
value|72
end_define

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

begin_define
define|#
directive|define
name|A_ea_forward
value|73
end_define

begin_function_decl
specifier|extern
name|void
name|ea_forward
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_backward
value|74
end_define

begin_function_decl
specifier|extern
name|void
name|ea_backward
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_beg_of_line
value|75
end_define

begin_function_decl
specifier|extern
name|void
name|ea_beg_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_end_of_line
value|76
end_define

begin_function_decl
specifier|extern
name|void
name|ea_end_of_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_forward_word
value|77
end_define

begin_function_decl
specifier|extern
name|void
name|ea_forward_word
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_backward_word
value|78
end_define

begin_function_decl
specifier|extern
name|void
name|ea_backward_word
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_delete
value|79
end_define

begin_function_decl
specifier|extern
name|void
name|ea_delete
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_rubout
value|80
end_define

begin_function_decl
specifier|extern
name|void
name|ea_rubout
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_abort
value|81
end_define

begin_function_decl
specifier|extern
name|void
name|ea_abort
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_newline
value|82
end_define

begin_function_decl
specifier|extern
name|void
name|ea_newline
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_quoted_insert
value|83
end_define

begin_function_decl
specifier|extern
name|void
name|ea_quoted_insert
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_insert
value|84
end_define

begin_function_decl
specifier|extern
name|void
name|ea_insert
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_tab_insert
value|85
end_define

begin_function_decl
specifier|extern
name|void
name|ea_tab_insert
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_transpose_chars
value|86
end_define

begin_function_decl
specifier|extern
name|void
name|ea_transpose_chars
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_yank
value|87
end_define

begin_function_decl
specifier|extern
name|void
name|ea_yank
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_yank_pop
value|88
end_define

begin_function_decl
specifier|extern
name|void
name|ea_yank_pop
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_kill_line
value|89
end_define

begin_function_decl
specifier|extern
name|void
name|ea_kill_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_backward_kill_line
value|90
end_define

begin_function_decl
specifier|extern
name|void
name|ea_backward_kill_line
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_kill_word
value|91
end_define

begin_function_decl
specifier|extern
name|void
name|ea_kill_word
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_backward_kill_word
value|92
end_define

begin_function_decl
specifier|extern
name|void
name|ea_backward_kill_word
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_possible_completions
value|93
end_define

begin_function_decl
specifier|extern
name|void
name|ea_possible_completions
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_complete
value|94
end_define

begin_function_decl
specifier|extern
name|void
name|ea_complete
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_ea_scroll_completions_window
value|95
end_define

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

begin_define
define|#
directive|define
name|A_info_get_help_window
value|96
end_define

begin_function_decl
specifier|extern
name|void
name|info_get_help_window
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_get_info_help_node
value|97
end_define

begin_function_decl
specifier|extern
name|void
name|info_get_info_help_node
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_describe_key
value|98
end_define

begin_function_decl
specifier|extern
name|void
name|describe_key
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_where_is
value|99
end_define

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

begin_define
define|#
directive|define
name|A_describe_command
value|100
end_define

begin_function_decl
specifier|extern
name|void
name|describe_command
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_execute_command
value|101
end_define

begin_function_decl
specifier|extern
name|void
name|info_execute_command
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_set_screen_height
value|102
end_define

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

begin_define
define|#
directive|define
name|A_info_index_search
value|103
end_define

begin_function_decl
specifier|extern
name|void
name|info_index_search
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_next_index_match
value|104
end_define

begin_function_decl
specifier|extern
name|void
name|info_next_index_match
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_info_index_apropos
value|105
end_define

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

begin_define
define|#
directive|define
name|A_list_visited_nodes
value|106
end_define

begin_function_decl
specifier|extern
name|void
name|list_visited_nodes
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_select_visited_node
value|107
end_define

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

begin_define
define|#
directive|define
name|A_info_show_footnotes
value|108
end_define

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

begin_define
define|#
directive|define
name|A_describe_variable
value|109
end_define

begin_function_decl
specifier|extern
name|void
name|describe_variable
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_set_variable
value|110
end_define

begin_function_decl
specifier|extern
name|void
name|set_variable
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|A_NCOMMANDS
value|111
end_define

end_unit

