begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * term.h   *  * This file was generated automatically.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TERM_H_
end_ifndef

begin_define
define|#
directive|define
name|_TERM_H_
end_define

begin_define
define|#
directive|define
name|auto_left_margin
value|(_CUR_TERM.bools[0])
end_define

begin_define
define|#
directive|define
name|auto_right_margin
value|(_CUR_TERM.bools[1])
end_define

begin_define
define|#
directive|define
name|ceol_standout_glitch
value|(_CUR_TERM.bools[2])
end_define

begin_define
define|#
directive|define
name|dest_tabs_magic_smso
value|(_CUR_TERM.bools[3])
end_define

begin_define
define|#
directive|define
name|eat_newline_glitch
value|(_CUR_TERM.bools[4])
end_define

begin_define
define|#
directive|define
name|erase_overstrike
value|(_CUR_TERM.bools[5])
end_define

begin_define
define|#
directive|define
name|generic_type
value|(_CUR_TERM.bools[6])
end_define

begin_define
define|#
directive|define
name|hard_copy
value|(_CUR_TERM.bools[7])
end_define

begin_define
define|#
directive|define
name|hard_cursor
value|(_CUR_TERM.bools[8])
end_define

begin_define
define|#
directive|define
name|has_meta_key
value|(_CUR_TERM.bools[9])
end_define

begin_define
define|#
directive|define
name|has_status_line
value|(_CUR_TERM.bools[10])
end_define

begin_define
define|#
directive|define
name|insert_null_glitch
value|(_CUR_TERM.bools[11])
end_define

begin_define
define|#
directive|define
name|memory_above
value|(_CUR_TERM.bools[12])
end_define

begin_define
define|#
directive|define
name|memory_below
value|(_CUR_TERM.bools[13])
end_define

begin_define
define|#
directive|define
name|move_insert_mode
value|(_CUR_TERM.bools[14])
end_define

begin_define
define|#
directive|define
name|move_standout_mode
value|(_CUR_TERM.bools[15])
end_define

begin_define
define|#
directive|define
name|needs_xon_xoff
value|(_CUR_TERM.bools[16])
end_define

begin_define
define|#
directive|define
name|no_esc_ctlc
value|(_CUR_TERM.bools[17])
end_define

begin_define
define|#
directive|define
name|no_pad_char
value|(_CUR_TERM.bools[18])
end_define

begin_define
define|#
directive|define
name|non_rev_rmcup
value|(_CUR_TERM.bools[19])
end_define

begin_define
define|#
directive|define
name|over_strike
value|(_CUR_TERM.bools[20])
end_define

begin_define
define|#
directive|define
name|prtr_silent
value|(_CUR_TERM.bools[21])
end_define

begin_define
define|#
directive|define
name|status_line_esc_ok
value|(_CUR_TERM.bools[22])
end_define

begin_define
define|#
directive|define
name|tilde_glitch
value|(_CUR_TERM.bools[23])
end_define

begin_define
define|#
directive|define
name|transparent_underline
value|(_CUR_TERM.bools[24])
end_define

begin_define
define|#
directive|define
name|xon_xoff
value|(_CUR_TERM.bools[25])
end_define

begin_define
define|#
directive|define
name|back_color_erase
value|(_CUR_TERM.bools[26])
end_define

begin_define
define|#
directive|define
name|can_change
value|(_CUR_TERM.bools[27])
end_define

begin_define
define|#
directive|define
name|col_addr_glitch
value|(_CUR_TERM.bools[28])
end_define

begin_define
define|#
directive|define
name|cpi_changes_res
value|(_CUR_TERM.bools[29])
end_define

begin_define
define|#
directive|define
name|cr_cancels_micro_mode
value|(_CUR_TERM.bools[30])
end_define

begin_define
define|#
directive|define
name|has_print_wheel
value|(_CUR_TERM.bools[31])
end_define

begin_define
define|#
directive|define
name|hue_lightness_saturation
value|(_CUR_TERM.bools[32])
end_define

begin_define
define|#
directive|define
name|lpi_changes_res
value|(_CUR_TERM.bools[33])
end_define

begin_define
define|#
directive|define
name|non_dest_scroll_region
value|(_CUR_TERM.bools[34])
end_define

begin_define
define|#
directive|define
name|row_addr_glitch
value|(_CUR_TERM.bools[35])
end_define

begin_define
define|#
directive|define
name|semi_auto_right_margin
value|(_CUR_TERM.bools[36])
end_define

begin_define
define|#
directive|define
name|backspaces_with_bs
value|(_CUR_TERM.bools[37])
end_define

begin_define
define|#
directive|define
name|even_parity
value|(_CUR_TERM.bools[38])
end_define

begin_define
define|#
directive|define
name|half_duplex
value|(_CUR_TERM.bools[39])
end_define

begin_define
define|#
directive|define
name|lower_case_only
value|(_CUR_TERM.bools[40])
end_define

begin_define
define|#
directive|define
name|no_correctly_working_cr
value|(_CUR_TERM.bools[41])
end_define

begin_define
define|#
directive|define
name|linefeed_is_newline
value|(_CUR_TERM.bools[42])
end_define

begin_define
define|#
directive|define
name|crt_without_scrolling
value|(_CUR_TERM.bools[43])
end_define

begin_define
define|#
directive|define
name|odd_parity
value|(_CUR_TERM.bools[44])
end_define

begin_define
define|#
directive|define
name|has_hardware_tabs
value|(_CUR_TERM.bools[45])
end_define

begin_define
define|#
directive|define
name|uppercase_only
value|(_CUR_TERM.bools[46])
end_define

begin_define
define|#
directive|define
name|return_does_clr_eol
value|(_CUR_TERM.bools[47])
end_define

begin_define
define|#
directive|define
name|tek_4025_insert_line
value|(_CUR_TERM.bools[48])
end_define

begin_define
define|#
directive|define
name|initialization_messy
value|(_CUR_TERM.bools[49])
end_define

begin_define
define|#
directive|define
name|index_at_bottom_does_cr
value|(_CUR_TERM.bools[50])
end_define

begin_define
define|#
directive|define
name|rind_only_at_top
value|(_CUR_TERM.bools[51])
end_define

begin_define
define|#
directive|define
name|GNU_has_meta_key
value|(_CUR_TERM.bools[52])
end_define

begin_define
define|#
directive|define
name|columns
value|(_CUR_TERM.nums[0])
end_define

begin_define
define|#
directive|define
name|init_tabs
value|(_CUR_TERM.nums[1])
end_define

begin_define
define|#
directive|define
name|label_height
value|(_CUR_TERM.nums[2])
end_define

begin_define
define|#
directive|define
name|label_width
value|(_CUR_TERM.nums[3])
end_define

begin_define
define|#
directive|define
name|lines
value|(_CUR_TERM.nums[4])
end_define

begin_define
define|#
directive|define
name|lines_of_memory
value|(_CUR_TERM.nums[5])
end_define

begin_define
define|#
directive|define
name|magic_cookie_glitch
value|(_CUR_TERM.nums[6])
end_define

begin_define
define|#
directive|define
name|num_labels
value|(_CUR_TERM.nums[7])
end_define

begin_define
define|#
directive|define
name|padding_baud_rate
value|(_CUR_TERM.nums[8])
end_define

begin_define
define|#
directive|define
name|virtual_terminal
value|(_CUR_TERM.nums[9])
end_define

begin_define
define|#
directive|define
name|width_status_line
value|(_CUR_TERM.nums[10])
end_define

begin_define
define|#
directive|define
name|bit_image_entwining
value|(_CUR_TERM.nums[11])
end_define

begin_define
define|#
directive|define
name|bit_image_type
value|(_CUR_TERM.nums[12])
end_define

begin_define
define|#
directive|define
name|buffer_capacity
value|(_CUR_TERM.nums[13])
end_define

begin_define
define|#
directive|define
name|buttons
value|(_CUR_TERM.nums[14])
end_define

begin_define
define|#
directive|define
name|dot_horz_spacing
value|(_CUR_TERM.nums[15])
end_define

begin_define
define|#
directive|define
name|dot_vert_spacing
value|(_CUR_TERM.nums[16])
end_define

begin_define
define|#
directive|define
name|max_attributes
value|(_CUR_TERM.nums[17])
end_define

begin_define
define|#
directive|define
name|max_colors
value|(_CUR_TERM.nums[18])
end_define

begin_define
define|#
directive|define
name|max_micro_address
value|(_CUR_TERM.nums[19])
end_define

begin_define
define|#
directive|define
name|max_micro_jump
value|(_CUR_TERM.nums[20])
end_define

begin_define
define|#
directive|define
name|max_pairs
value|(_CUR_TERM.nums[21])
end_define

begin_define
define|#
directive|define
name|maximum_windows
value|(_CUR_TERM.nums[22])
end_define

begin_define
define|#
directive|define
name|micro_char_size
value|(_CUR_TERM.nums[23])
end_define

begin_define
define|#
directive|define
name|micro_line_size
value|(_CUR_TERM.nums[24])
end_define

begin_define
define|#
directive|define
name|no_color_video
value|(_CUR_TERM.nums[25])
end_define

begin_define
define|#
directive|define
name|number_of_pins
value|(_CUR_TERM.nums[26])
end_define

begin_define
define|#
directive|define
name|output_res_char
value|(_CUR_TERM.nums[27])
end_define

begin_define
define|#
directive|define
name|output_res_horz_inch
value|(_CUR_TERM.nums[28])
end_define

begin_define
define|#
directive|define
name|output_res_line
value|(_CUR_TERM.nums[29])
end_define

begin_define
define|#
directive|define
name|output_res_vert_inch
value|(_CUR_TERM.nums[30])
end_define

begin_define
define|#
directive|define
name|print_rate
value|(_CUR_TERM.nums[31])
end_define

begin_define
define|#
directive|define
name|wide_char_size
value|(_CUR_TERM.nums[32])
end_define

begin_define
define|#
directive|define
name|backspace_delay
value|(_CUR_TERM.nums[33])
end_define

begin_define
define|#
directive|define
name|carriage_return_delay
value|(_CUR_TERM.nums[34])
end_define

begin_define
define|#
directive|define
name|form_feed_delay
value|(_CUR_TERM.nums[35])
end_define

begin_define
define|#
directive|define
name|new_line_delay
value|(_CUR_TERM.nums[36])
end_define

begin_define
define|#
directive|define
name|horizontal_tab_delay
value|(_CUR_TERM.nums[37])
end_define

begin_define
define|#
directive|define
name|vertical_tab_delay
value|(_CUR_TERM.nums[38])
end_define

begin_define
define|#
directive|define
name|number_of_function_keys
value|(_CUR_TERM.nums[39])
end_define

begin_define
define|#
directive|define
name|magic_cookie_glitch_ul
value|(_CUR_TERM.nums[40])
end_define

begin_define
define|#
directive|define
name|GNU_tab_width
value|(_CUR_TERM.nums[41])
end_define

begin_define
define|#
directive|define
name|acs_chars
value|(_CUR_TERM.strs[0])
end_define

begin_define
define|#
directive|define
name|back_tab
value|(_CUR_TERM.strs[1])
end_define

begin_define
define|#
directive|define
name|bell
value|(_CUR_TERM.strs[2])
end_define

begin_define
define|#
directive|define
name|carriage_return
value|(_CUR_TERM.strs[3])
end_define

begin_define
define|#
directive|define
name|change_scroll_region
value|(_CUR_TERM.strs[4])
end_define

begin_define
define|#
directive|define
name|char_padding
value|(_CUR_TERM.strs[5])
end_define

begin_define
define|#
directive|define
name|clear_all_tabs
value|(_CUR_TERM.strs[6])
end_define

begin_define
define|#
directive|define
name|clear_margins
value|(_CUR_TERM.strs[7])
end_define

begin_define
define|#
directive|define
name|clear_screen
value|(_CUR_TERM.strs[8])
end_define

begin_define
define|#
directive|define
name|clr_bol
value|(_CUR_TERM.strs[9])
end_define

begin_define
define|#
directive|define
name|clr_eol
value|(_CUR_TERM.strs[10])
end_define

begin_define
define|#
directive|define
name|clr_eos
value|(_CUR_TERM.strs[11])
end_define

begin_define
define|#
directive|define
name|column_address
value|(_CUR_TERM.strs[12])
end_define

begin_define
define|#
directive|define
name|command_character
value|(_CUR_TERM.strs[13])
end_define

begin_define
define|#
directive|define
name|cursor_address
value|(_CUR_TERM.strs[14])
end_define

begin_define
define|#
directive|define
name|cursor_down
value|(_CUR_TERM.strs[15])
end_define

begin_define
define|#
directive|define
name|cursor_home
value|(_CUR_TERM.strs[16])
end_define

begin_define
define|#
directive|define
name|cursor_invisible
value|(_CUR_TERM.strs[17])
end_define

begin_define
define|#
directive|define
name|cursor_left
value|(_CUR_TERM.strs[18])
end_define

begin_define
define|#
directive|define
name|cursor_mem_address
value|(_CUR_TERM.strs[19])
end_define

begin_define
define|#
directive|define
name|cursor_normal
value|(_CUR_TERM.strs[20])
end_define

begin_define
define|#
directive|define
name|cursor_right
value|(_CUR_TERM.strs[21])
end_define

begin_define
define|#
directive|define
name|cursor_to_ll
value|(_CUR_TERM.strs[22])
end_define

begin_define
define|#
directive|define
name|cursor_up
value|(_CUR_TERM.strs[23])
end_define

begin_define
define|#
directive|define
name|cursor_visible
value|(_CUR_TERM.strs[24])
end_define

begin_define
define|#
directive|define
name|delete_character
value|(_CUR_TERM.strs[25])
end_define

begin_define
define|#
directive|define
name|delete_line
value|(_CUR_TERM.strs[26])
end_define

begin_define
define|#
directive|define
name|dis_status_line
value|(_CUR_TERM.strs[27])
end_define

begin_define
define|#
directive|define
name|down_half_line
value|(_CUR_TERM.strs[28])
end_define

begin_define
define|#
directive|define
name|ena_acs
value|(_CUR_TERM.strs[29])
end_define

begin_define
define|#
directive|define
name|enter_alt_charset_mode
value|(_CUR_TERM.strs[30])
end_define

begin_define
define|#
directive|define
name|enter_am_mode
value|(_CUR_TERM.strs[31])
end_define

begin_define
define|#
directive|define
name|enter_blink_mode
value|(_CUR_TERM.strs[32])
end_define

begin_define
define|#
directive|define
name|enter_bold_mode
value|(_CUR_TERM.strs[33])
end_define

begin_define
define|#
directive|define
name|enter_ca_mode
value|(_CUR_TERM.strs[34])
end_define

begin_define
define|#
directive|define
name|enter_delete_mode
value|(_CUR_TERM.strs[35])
end_define

begin_define
define|#
directive|define
name|enter_dim_mode
value|(_CUR_TERM.strs[36])
end_define

begin_define
define|#
directive|define
name|enter_insert_mode
value|(_CUR_TERM.strs[37])
end_define

begin_define
define|#
directive|define
name|enter_protected_mode
value|(_CUR_TERM.strs[38])
end_define

begin_define
define|#
directive|define
name|enter_reverse_mode
value|(_CUR_TERM.strs[39])
end_define

begin_define
define|#
directive|define
name|enter_secure_mode
value|(_CUR_TERM.strs[40])
end_define

begin_define
define|#
directive|define
name|enter_standout_mode
value|(_CUR_TERM.strs[41])
end_define

begin_define
define|#
directive|define
name|enter_underline_mode
value|(_CUR_TERM.strs[42])
end_define

begin_define
define|#
directive|define
name|enter_xon_mode
value|(_CUR_TERM.strs[43])
end_define

begin_define
define|#
directive|define
name|erase_chars
value|(_CUR_TERM.strs[44])
end_define

begin_define
define|#
directive|define
name|exit_alt_charset_mode
value|(_CUR_TERM.strs[45])
end_define

begin_define
define|#
directive|define
name|exit_am_mode
value|(_CUR_TERM.strs[46])
end_define

begin_define
define|#
directive|define
name|exit_attribute_mode
value|(_CUR_TERM.strs[47])
end_define

begin_define
define|#
directive|define
name|exit_ca_mode
value|(_CUR_TERM.strs[48])
end_define

begin_define
define|#
directive|define
name|exit_delete_mode
value|(_CUR_TERM.strs[49])
end_define

begin_define
define|#
directive|define
name|exit_insert_mode
value|(_CUR_TERM.strs[50])
end_define

begin_define
define|#
directive|define
name|exit_standout_mode
value|(_CUR_TERM.strs[51])
end_define

begin_define
define|#
directive|define
name|exit_underline_mode
value|(_CUR_TERM.strs[52])
end_define

begin_define
define|#
directive|define
name|exit_xon_mode
value|(_CUR_TERM.strs[53])
end_define

begin_define
define|#
directive|define
name|flash_screen
value|(_CUR_TERM.strs[54])
end_define

begin_define
define|#
directive|define
name|form_feed
value|(_CUR_TERM.strs[55])
end_define

begin_define
define|#
directive|define
name|from_status_line
value|(_CUR_TERM.strs[56])
end_define

begin_define
define|#
directive|define
name|init_1string
value|(_CUR_TERM.strs[57])
end_define

begin_define
define|#
directive|define
name|init_2string
value|(_CUR_TERM.strs[58])
end_define

begin_define
define|#
directive|define
name|init_3string
value|(_CUR_TERM.strs[59])
end_define

begin_define
define|#
directive|define
name|init_file
value|(_CUR_TERM.strs[60])
end_define

begin_define
define|#
directive|define
name|init_prog
value|(_CUR_TERM.strs[61])
end_define

begin_define
define|#
directive|define
name|insert_character
value|(_CUR_TERM.strs[62])
end_define

begin_define
define|#
directive|define
name|insert_line
value|(_CUR_TERM.strs[63])
end_define

begin_define
define|#
directive|define
name|insert_padding
value|(_CUR_TERM.strs[64])
end_define

begin_define
define|#
directive|define
name|key_a1
value|(_CUR_TERM.strs[65])
end_define

begin_define
define|#
directive|define
name|key_a3
value|(_CUR_TERM.strs[66])
end_define

begin_define
define|#
directive|define
name|key_b2
value|(_CUR_TERM.strs[67])
end_define

begin_define
define|#
directive|define
name|key_backspace
value|(_CUR_TERM.strs[68])
end_define

begin_define
define|#
directive|define
name|key_beg
value|(_CUR_TERM.strs[69])
end_define

begin_define
define|#
directive|define
name|key_btab
value|(_CUR_TERM.strs[70])
end_define

begin_define
define|#
directive|define
name|key_c1
value|(_CUR_TERM.strs[71])
end_define

begin_define
define|#
directive|define
name|key_c3
value|(_CUR_TERM.strs[72])
end_define

begin_define
define|#
directive|define
name|key_cancel
value|(_CUR_TERM.strs[73])
end_define

begin_define
define|#
directive|define
name|key_catab
value|(_CUR_TERM.strs[74])
end_define

begin_define
define|#
directive|define
name|key_clear
value|(_CUR_TERM.strs[75])
end_define

begin_define
define|#
directive|define
name|key_close
value|(_CUR_TERM.strs[76])
end_define

begin_define
define|#
directive|define
name|key_command
value|(_CUR_TERM.strs[77])
end_define

begin_define
define|#
directive|define
name|key_copy
value|(_CUR_TERM.strs[78])
end_define

begin_define
define|#
directive|define
name|key_create
value|(_CUR_TERM.strs[79])
end_define

begin_define
define|#
directive|define
name|key_ctab
value|(_CUR_TERM.strs[80])
end_define

begin_define
define|#
directive|define
name|key_dc
value|(_CUR_TERM.strs[81])
end_define

begin_define
define|#
directive|define
name|key_dl
value|(_CUR_TERM.strs[82])
end_define

begin_define
define|#
directive|define
name|key_down
value|(_CUR_TERM.strs[83])
end_define

begin_define
define|#
directive|define
name|key_eic
value|(_CUR_TERM.strs[84])
end_define

begin_define
define|#
directive|define
name|key_end
value|(_CUR_TERM.strs[85])
end_define

begin_define
define|#
directive|define
name|key_enter
value|(_CUR_TERM.strs[86])
end_define

begin_define
define|#
directive|define
name|key_eol
value|(_CUR_TERM.strs[87])
end_define

begin_define
define|#
directive|define
name|key_eos
value|(_CUR_TERM.strs[88])
end_define

begin_define
define|#
directive|define
name|key_exit
value|(_CUR_TERM.strs[89])
end_define

begin_define
define|#
directive|define
name|key_f0
value|(_CUR_TERM.strs[90])
end_define

begin_define
define|#
directive|define
name|key_f1
value|(_CUR_TERM.strs[91])
end_define

begin_define
define|#
directive|define
name|key_f10
value|(_CUR_TERM.strs[92])
end_define

begin_define
define|#
directive|define
name|key_f11
value|(_CUR_TERM.strs[93])
end_define

begin_define
define|#
directive|define
name|key_f12
value|(_CUR_TERM.strs[94])
end_define

begin_define
define|#
directive|define
name|key_f13
value|(_CUR_TERM.strs[95])
end_define

begin_define
define|#
directive|define
name|key_f14
value|(_CUR_TERM.strs[96])
end_define

begin_define
define|#
directive|define
name|key_f15
value|(_CUR_TERM.strs[97])
end_define

begin_define
define|#
directive|define
name|key_f16
value|(_CUR_TERM.strs[98])
end_define

begin_define
define|#
directive|define
name|key_f17
value|(_CUR_TERM.strs[99])
end_define

begin_define
define|#
directive|define
name|key_f18
value|(_CUR_TERM.strs[100])
end_define

begin_define
define|#
directive|define
name|key_f19
value|(_CUR_TERM.strs[101])
end_define

begin_define
define|#
directive|define
name|key_f2
value|(_CUR_TERM.strs[102])
end_define

begin_define
define|#
directive|define
name|key_f20
value|(_CUR_TERM.strs[103])
end_define

begin_define
define|#
directive|define
name|key_f21
value|(_CUR_TERM.strs[104])
end_define

begin_define
define|#
directive|define
name|key_f22
value|(_CUR_TERM.strs[105])
end_define

begin_define
define|#
directive|define
name|key_f23
value|(_CUR_TERM.strs[106])
end_define

begin_define
define|#
directive|define
name|key_f24
value|(_CUR_TERM.strs[107])
end_define

begin_define
define|#
directive|define
name|key_f25
value|(_CUR_TERM.strs[108])
end_define

begin_define
define|#
directive|define
name|key_f26
value|(_CUR_TERM.strs[109])
end_define

begin_define
define|#
directive|define
name|key_f27
value|(_CUR_TERM.strs[110])
end_define

begin_define
define|#
directive|define
name|key_f28
value|(_CUR_TERM.strs[111])
end_define

begin_define
define|#
directive|define
name|key_f29
value|(_CUR_TERM.strs[112])
end_define

begin_define
define|#
directive|define
name|key_f3
value|(_CUR_TERM.strs[113])
end_define

begin_define
define|#
directive|define
name|key_f30
value|(_CUR_TERM.strs[114])
end_define

begin_define
define|#
directive|define
name|key_f31
value|(_CUR_TERM.strs[115])
end_define

begin_define
define|#
directive|define
name|key_f32
value|(_CUR_TERM.strs[116])
end_define

begin_define
define|#
directive|define
name|key_f33
value|(_CUR_TERM.strs[117])
end_define

begin_define
define|#
directive|define
name|key_f34
value|(_CUR_TERM.strs[118])
end_define

begin_define
define|#
directive|define
name|key_f35
value|(_CUR_TERM.strs[119])
end_define

begin_define
define|#
directive|define
name|key_f36
value|(_CUR_TERM.strs[120])
end_define

begin_define
define|#
directive|define
name|key_f37
value|(_CUR_TERM.strs[121])
end_define

begin_define
define|#
directive|define
name|key_f38
value|(_CUR_TERM.strs[122])
end_define

begin_define
define|#
directive|define
name|key_f39
value|(_CUR_TERM.strs[123])
end_define

begin_define
define|#
directive|define
name|key_f4
value|(_CUR_TERM.strs[124])
end_define

begin_define
define|#
directive|define
name|key_f40
value|(_CUR_TERM.strs[125])
end_define

begin_define
define|#
directive|define
name|key_f41
value|(_CUR_TERM.strs[126])
end_define

begin_define
define|#
directive|define
name|key_f42
value|(_CUR_TERM.strs[127])
end_define

begin_define
define|#
directive|define
name|key_f43
value|(_CUR_TERM.strs[128])
end_define

begin_define
define|#
directive|define
name|key_f44
value|(_CUR_TERM.strs[129])
end_define

begin_define
define|#
directive|define
name|key_f45
value|(_CUR_TERM.strs[130])
end_define

begin_define
define|#
directive|define
name|key_f46
value|(_CUR_TERM.strs[131])
end_define

begin_define
define|#
directive|define
name|key_f47
value|(_CUR_TERM.strs[132])
end_define

begin_define
define|#
directive|define
name|key_f48
value|(_CUR_TERM.strs[133])
end_define

begin_define
define|#
directive|define
name|key_f49
value|(_CUR_TERM.strs[134])
end_define

begin_define
define|#
directive|define
name|key_f5
value|(_CUR_TERM.strs[135])
end_define

begin_define
define|#
directive|define
name|key_f50
value|(_CUR_TERM.strs[136])
end_define

begin_define
define|#
directive|define
name|key_f51
value|(_CUR_TERM.strs[137])
end_define

begin_define
define|#
directive|define
name|key_f52
value|(_CUR_TERM.strs[138])
end_define

begin_define
define|#
directive|define
name|key_f53
value|(_CUR_TERM.strs[139])
end_define

begin_define
define|#
directive|define
name|key_f54
value|(_CUR_TERM.strs[140])
end_define

begin_define
define|#
directive|define
name|key_f55
value|(_CUR_TERM.strs[141])
end_define

begin_define
define|#
directive|define
name|key_f56
value|(_CUR_TERM.strs[142])
end_define

begin_define
define|#
directive|define
name|key_f57
value|(_CUR_TERM.strs[143])
end_define

begin_define
define|#
directive|define
name|key_f58
value|(_CUR_TERM.strs[144])
end_define

begin_define
define|#
directive|define
name|key_f59
value|(_CUR_TERM.strs[145])
end_define

begin_define
define|#
directive|define
name|key_f6
value|(_CUR_TERM.strs[146])
end_define

begin_define
define|#
directive|define
name|key_f60
value|(_CUR_TERM.strs[147])
end_define

begin_define
define|#
directive|define
name|key_f61
value|(_CUR_TERM.strs[148])
end_define

begin_define
define|#
directive|define
name|key_f62
value|(_CUR_TERM.strs[149])
end_define

begin_define
define|#
directive|define
name|key_f63
value|(_CUR_TERM.strs[150])
end_define

begin_define
define|#
directive|define
name|key_f7
value|(_CUR_TERM.strs[151])
end_define

begin_define
define|#
directive|define
name|key_f8
value|(_CUR_TERM.strs[152])
end_define

begin_define
define|#
directive|define
name|key_f9
value|(_CUR_TERM.strs[153])
end_define

begin_define
define|#
directive|define
name|key_find
value|(_CUR_TERM.strs[154])
end_define

begin_define
define|#
directive|define
name|key_help
value|(_CUR_TERM.strs[155])
end_define

begin_define
define|#
directive|define
name|key_home
value|(_CUR_TERM.strs[156])
end_define

begin_define
define|#
directive|define
name|key_ic
value|(_CUR_TERM.strs[157])
end_define

begin_define
define|#
directive|define
name|key_il
value|(_CUR_TERM.strs[158])
end_define

begin_define
define|#
directive|define
name|key_left
value|(_CUR_TERM.strs[159])
end_define

begin_define
define|#
directive|define
name|key_ll
value|(_CUR_TERM.strs[160])
end_define

begin_define
define|#
directive|define
name|key_mark
value|(_CUR_TERM.strs[161])
end_define

begin_define
define|#
directive|define
name|key_message
value|(_CUR_TERM.strs[162])
end_define

begin_define
define|#
directive|define
name|key_move
value|(_CUR_TERM.strs[163])
end_define

begin_define
define|#
directive|define
name|key_next
value|(_CUR_TERM.strs[164])
end_define

begin_define
define|#
directive|define
name|key_npage
value|(_CUR_TERM.strs[165])
end_define

begin_define
define|#
directive|define
name|key_open
value|(_CUR_TERM.strs[166])
end_define

begin_define
define|#
directive|define
name|key_options
value|(_CUR_TERM.strs[167])
end_define

begin_define
define|#
directive|define
name|key_ppage
value|(_CUR_TERM.strs[168])
end_define

begin_define
define|#
directive|define
name|key_previous
value|(_CUR_TERM.strs[169])
end_define

begin_define
define|#
directive|define
name|key_print
value|(_CUR_TERM.strs[170])
end_define

begin_define
define|#
directive|define
name|key_redo
value|(_CUR_TERM.strs[171])
end_define

begin_define
define|#
directive|define
name|key_reference
value|(_CUR_TERM.strs[172])
end_define

begin_define
define|#
directive|define
name|key_refresh
value|(_CUR_TERM.strs[173])
end_define

begin_define
define|#
directive|define
name|key_replace
value|(_CUR_TERM.strs[174])
end_define

begin_define
define|#
directive|define
name|key_restart
value|(_CUR_TERM.strs[175])
end_define

begin_define
define|#
directive|define
name|key_resume
value|(_CUR_TERM.strs[176])
end_define

begin_define
define|#
directive|define
name|key_right
value|(_CUR_TERM.strs[177])
end_define

begin_define
define|#
directive|define
name|key_save
value|(_CUR_TERM.strs[178])
end_define

begin_define
define|#
directive|define
name|key_sbeg
value|(_CUR_TERM.strs[179])
end_define

begin_define
define|#
directive|define
name|key_scancel
value|(_CUR_TERM.strs[180])
end_define

begin_define
define|#
directive|define
name|key_scommand
value|(_CUR_TERM.strs[181])
end_define

begin_define
define|#
directive|define
name|key_scopy
value|(_CUR_TERM.strs[182])
end_define

begin_define
define|#
directive|define
name|key_screate
value|(_CUR_TERM.strs[183])
end_define

begin_define
define|#
directive|define
name|key_sdc
value|(_CUR_TERM.strs[184])
end_define

begin_define
define|#
directive|define
name|key_sdl
value|(_CUR_TERM.strs[185])
end_define

begin_define
define|#
directive|define
name|key_select
value|(_CUR_TERM.strs[186])
end_define

begin_define
define|#
directive|define
name|key_send
value|(_CUR_TERM.strs[187])
end_define

begin_define
define|#
directive|define
name|key_seol
value|(_CUR_TERM.strs[188])
end_define

begin_define
define|#
directive|define
name|key_sexit
value|(_CUR_TERM.strs[189])
end_define

begin_define
define|#
directive|define
name|key_sf
value|(_CUR_TERM.strs[190])
end_define

begin_define
define|#
directive|define
name|key_sfind
value|(_CUR_TERM.strs[191])
end_define

begin_define
define|#
directive|define
name|key_shelp
value|(_CUR_TERM.strs[192])
end_define

begin_define
define|#
directive|define
name|key_shome
value|(_CUR_TERM.strs[193])
end_define

begin_define
define|#
directive|define
name|key_sic
value|(_CUR_TERM.strs[194])
end_define

begin_define
define|#
directive|define
name|key_sleft
value|(_CUR_TERM.strs[195])
end_define

begin_define
define|#
directive|define
name|key_smessage
value|(_CUR_TERM.strs[196])
end_define

begin_define
define|#
directive|define
name|key_smove
value|(_CUR_TERM.strs[197])
end_define

begin_define
define|#
directive|define
name|key_snext
value|(_CUR_TERM.strs[198])
end_define

begin_define
define|#
directive|define
name|key_soptions
value|(_CUR_TERM.strs[199])
end_define

begin_define
define|#
directive|define
name|key_sprevious
value|(_CUR_TERM.strs[200])
end_define

begin_define
define|#
directive|define
name|key_sprint
value|(_CUR_TERM.strs[201])
end_define

begin_define
define|#
directive|define
name|key_sr
value|(_CUR_TERM.strs[202])
end_define

begin_define
define|#
directive|define
name|key_sredo
value|(_CUR_TERM.strs[203])
end_define

begin_define
define|#
directive|define
name|key_sreplace
value|(_CUR_TERM.strs[204])
end_define

begin_define
define|#
directive|define
name|key_sright
value|(_CUR_TERM.strs[205])
end_define

begin_define
define|#
directive|define
name|key_srsume
value|(_CUR_TERM.strs[206])
end_define

begin_define
define|#
directive|define
name|key_ssave
value|(_CUR_TERM.strs[207])
end_define

begin_define
define|#
directive|define
name|key_ssuspend
value|(_CUR_TERM.strs[208])
end_define

begin_define
define|#
directive|define
name|key_stab
value|(_CUR_TERM.strs[209])
end_define

begin_define
define|#
directive|define
name|key_sundo
value|(_CUR_TERM.strs[210])
end_define

begin_define
define|#
directive|define
name|key_suspend
value|(_CUR_TERM.strs[211])
end_define

begin_define
define|#
directive|define
name|key_undo
value|(_CUR_TERM.strs[212])
end_define

begin_define
define|#
directive|define
name|key_up
value|(_CUR_TERM.strs[213])
end_define

begin_define
define|#
directive|define
name|keypad_local
value|(_CUR_TERM.strs[214])
end_define

begin_define
define|#
directive|define
name|keypad_xmit
value|(_CUR_TERM.strs[215])
end_define

begin_define
define|#
directive|define
name|lab_f0
value|(_CUR_TERM.strs[216])
end_define

begin_define
define|#
directive|define
name|lab_f1
value|(_CUR_TERM.strs[217])
end_define

begin_define
define|#
directive|define
name|lab_f10
value|(_CUR_TERM.strs[218])
end_define

begin_define
define|#
directive|define
name|lab_f2
value|(_CUR_TERM.strs[219])
end_define

begin_define
define|#
directive|define
name|lab_f3
value|(_CUR_TERM.strs[220])
end_define

begin_define
define|#
directive|define
name|lab_f4
value|(_CUR_TERM.strs[221])
end_define

begin_define
define|#
directive|define
name|lab_f5
value|(_CUR_TERM.strs[222])
end_define

begin_define
define|#
directive|define
name|lab_f6
value|(_CUR_TERM.strs[223])
end_define

begin_define
define|#
directive|define
name|lab_f7
value|(_CUR_TERM.strs[224])
end_define

begin_define
define|#
directive|define
name|lab_f8
value|(_CUR_TERM.strs[225])
end_define

begin_define
define|#
directive|define
name|lab_f9
value|(_CUR_TERM.strs[226])
end_define

begin_define
define|#
directive|define
name|label_off
value|(_CUR_TERM.strs[227])
end_define

begin_define
define|#
directive|define
name|label_on
value|(_CUR_TERM.strs[228])
end_define

begin_define
define|#
directive|define
name|meta_off
value|(_CUR_TERM.strs[229])
end_define

begin_define
define|#
directive|define
name|meta_on
value|(_CUR_TERM.strs[230])
end_define

begin_define
define|#
directive|define
name|newline
value|(_CUR_TERM.strs[231])
end_define

begin_define
define|#
directive|define
name|pad_char
value|(_CUR_TERM.strs[232])
end_define

begin_define
define|#
directive|define
name|parm_dch
value|(_CUR_TERM.strs[233])
end_define

begin_define
define|#
directive|define
name|parm_delete_line
value|(_CUR_TERM.strs[234])
end_define

begin_define
define|#
directive|define
name|parm_down_cursor
value|(_CUR_TERM.strs[235])
end_define

begin_define
define|#
directive|define
name|parm_ich
value|(_CUR_TERM.strs[236])
end_define

begin_define
define|#
directive|define
name|parm_index
value|(_CUR_TERM.strs[237])
end_define

begin_define
define|#
directive|define
name|parm_insert_line
value|(_CUR_TERM.strs[238])
end_define

begin_define
define|#
directive|define
name|parm_left_cursor
value|(_CUR_TERM.strs[239])
end_define

begin_define
define|#
directive|define
name|parm_right_cursor
value|(_CUR_TERM.strs[240])
end_define

begin_define
define|#
directive|define
name|parm_rindex
value|(_CUR_TERM.strs[241])
end_define

begin_define
define|#
directive|define
name|parm_up_cursor
value|(_CUR_TERM.strs[242])
end_define

begin_define
define|#
directive|define
name|pkey_key
value|(_CUR_TERM.strs[243])
end_define

begin_define
define|#
directive|define
name|pkey_local
value|(_CUR_TERM.strs[244])
end_define

begin_define
define|#
directive|define
name|pkey_xmit
value|(_CUR_TERM.strs[245])
end_define

begin_define
define|#
directive|define
name|plab_norm
value|(_CUR_TERM.strs[246])
end_define

begin_define
define|#
directive|define
name|print_screen
value|(_CUR_TERM.strs[247])
end_define

begin_define
define|#
directive|define
name|prtr_non
value|(_CUR_TERM.strs[248])
end_define

begin_define
define|#
directive|define
name|prtr_off
value|(_CUR_TERM.strs[249])
end_define

begin_define
define|#
directive|define
name|prtr_on
value|(_CUR_TERM.strs[250])
end_define

begin_define
define|#
directive|define
name|repeat_char
value|(_CUR_TERM.strs[251])
end_define

begin_define
define|#
directive|define
name|req_for_input
value|(_CUR_TERM.strs[252])
end_define

begin_define
define|#
directive|define
name|reset_1string
value|(_CUR_TERM.strs[253])
end_define

begin_define
define|#
directive|define
name|reset_2string
value|(_CUR_TERM.strs[254])
end_define

begin_define
define|#
directive|define
name|reset_3string
value|(_CUR_TERM.strs[255])
end_define

begin_define
define|#
directive|define
name|reset_file
value|(_CUR_TERM.strs[256])
end_define

begin_define
define|#
directive|define
name|restore_cursor
value|(_CUR_TERM.strs[257])
end_define

begin_define
define|#
directive|define
name|row_address
value|(_CUR_TERM.strs[258])
end_define

begin_define
define|#
directive|define
name|save_cursor
value|(_CUR_TERM.strs[259])
end_define

begin_define
define|#
directive|define
name|scroll_forward
value|(_CUR_TERM.strs[260])
end_define

begin_define
define|#
directive|define
name|scroll_reverse
value|(_CUR_TERM.strs[261])
end_define

begin_define
define|#
directive|define
name|set_attributes
value|(_CUR_TERM.strs[262])
end_define

begin_define
define|#
directive|define
name|set_left_margin
value|(_CUR_TERM.strs[263])
end_define

begin_define
define|#
directive|define
name|set_right_margin
value|(_CUR_TERM.strs[264])
end_define

begin_define
define|#
directive|define
name|set_tab
value|(_CUR_TERM.strs[265])
end_define

begin_define
define|#
directive|define
name|set_window
value|(_CUR_TERM.strs[266])
end_define

begin_define
define|#
directive|define
name|tab
value|(_CUR_TERM.strs[267])
end_define

begin_define
define|#
directive|define
name|to_status_line
value|(_CUR_TERM.strs[268])
end_define

begin_define
define|#
directive|define
name|underline_char
value|(_CUR_TERM.strs[269])
end_define

begin_define
define|#
directive|define
name|up_half_line
value|(_CUR_TERM.strs[270])
end_define

begin_define
define|#
directive|define
name|xoff_character
value|(_CUR_TERM.strs[271])
end_define

begin_define
define|#
directive|define
name|xon_character
value|(_CUR_TERM.strs[272])
end_define

begin_define
define|#
directive|define
name|alt_scancode_esc
value|(_CUR_TERM.strs[273])
end_define

begin_define
define|#
directive|define
name|bit_image_carriage_return
value|(_CUR_TERM.strs[274])
end_define

begin_define
define|#
directive|define
name|bit_image_newline
value|(_CUR_TERM.strs[275])
end_define

begin_define
define|#
directive|define
name|bit_image_repeat
value|(_CUR_TERM.strs[276])
end_define

begin_define
define|#
directive|define
name|change_char_pitch
value|(_CUR_TERM.strs[277])
end_define

begin_define
define|#
directive|define
name|change_line_pitch
value|(_CUR_TERM.strs[278])
end_define

begin_define
define|#
directive|define
name|change_res_horz
value|(_CUR_TERM.strs[279])
end_define

begin_define
define|#
directive|define
name|change_res_vert
value|(_CUR_TERM.strs[280])
end_define

begin_define
define|#
directive|define
name|char_set_names
value|(_CUR_TERM.strs[281])
end_define

begin_define
define|#
directive|define
name|code_set_init
value|(_CUR_TERM.strs[282])
end_define

begin_define
define|#
directive|define
name|color_names
value|(_CUR_TERM.strs[283])
end_define

begin_define
define|#
directive|define
name|create_window
value|(_CUR_TERM.strs[284])
end_define

begin_define
define|#
directive|define
name|define_bit_image_region
value|(_CUR_TERM.strs[285])
end_define

begin_define
define|#
directive|define
name|define_char
value|(_CUR_TERM.strs[286])
end_define

begin_define
define|#
directive|define
name|device_type
value|(_CUR_TERM.strs[287])
end_define

begin_define
define|#
directive|define
name|dial_phone
value|(_CUR_TERM.strs[288])
end_define

begin_define
define|#
directive|define
name|display_clock
value|(_CUR_TERM.strs[289])
end_define

begin_define
define|#
directive|define
name|display_pc_char
value|(_CUR_TERM.strs[290])
end_define

begin_define
define|#
directive|define
name|end_bit_image_region
value|(_CUR_TERM.strs[291])
end_define

begin_define
define|#
directive|define
name|enter_doublewide_mode
value|(_CUR_TERM.strs[292])
end_define

begin_define
define|#
directive|define
name|enter_draft_quality
value|(_CUR_TERM.strs[293])
end_define

begin_define
define|#
directive|define
name|enter_italics_mode
value|(_CUR_TERM.strs[294])
end_define

begin_define
define|#
directive|define
name|enter_leftward_mode
value|(_CUR_TERM.strs[295])
end_define

begin_define
define|#
directive|define
name|enter_micro_mode
value|(_CUR_TERM.strs[296])
end_define

begin_define
define|#
directive|define
name|enter_near_letter_quality
value|(_CUR_TERM.strs[297])
end_define

begin_define
define|#
directive|define
name|enter_normal_quality
value|(_CUR_TERM.strs[298])
end_define

begin_define
define|#
directive|define
name|enter_pc_charset_mode
value|(_CUR_TERM.strs[299])
end_define

begin_define
define|#
directive|define
name|enter_scancode_mode
value|(_CUR_TERM.strs[300])
end_define

begin_define
define|#
directive|define
name|enter_shadow_mode
value|(_CUR_TERM.strs[301])
end_define

begin_define
define|#
directive|define
name|enter_subscript_mode
value|(_CUR_TERM.strs[302])
end_define

begin_define
define|#
directive|define
name|enter_superscript_mode
value|(_CUR_TERM.strs[303])
end_define

begin_define
define|#
directive|define
name|enter_upward_mode
value|(_CUR_TERM.strs[304])
end_define

begin_define
define|#
directive|define
name|exit_doublewide_mode
value|(_CUR_TERM.strs[305])
end_define

begin_define
define|#
directive|define
name|exit_italics_mode
value|(_CUR_TERM.strs[306])
end_define

begin_define
define|#
directive|define
name|exit_leftward_mode
value|(_CUR_TERM.strs[307])
end_define

begin_define
define|#
directive|define
name|exit_micro_mode
value|(_CUR_TERM.strs[308])
end_define

begin_define
define|#
directive|define
name|exit_pc_charset_mode
value|(_CUR_TERM.strs[309])
end_define

begin_define
define|#
directive|define
name|exit_scancode_mode
value|(_CUR_TERM.strs[310])
end_define

begin_define
define|#
directive|define
name|exit_shadow_mode
value|(_CUR_TERM.strs[311])
end_define

begin_define
define|#
directive|define
name|exit_subscript_mode
value|(_CUR_TERM.strs[312])
end_define

begin_define
define|#
directive|define
name|exit_superscript_mode
value|(_CUR_TERM.strs[313])
end_define

begin_define
define|#
directive|define
name|exit_upward_mode
value|(_CUR_TERM.strs[314])
end_define

begin_define
define|#
directive|define
name|fixed_pause
value|(_CUR_TERM.strs[315])
end_define

begin_define
define|#
directive|define
name|flash_hook
value|(_CUR_TERM.strs[316])
end_define

begin_define
define|#
directive|define
name|get_mouse
value|(_CUR_TERM.strs[317])
end_define

begin_define
define|#
directive|define
name|goto_window
value|(_CUR_TERM.strs[318])
end_define

begin_define
define|#
directive|define
name|hangup
value|(_CUR_TERM.strs[319])
end_define

begin_define
define|#
directive|define
name|initialize_color
value|(_CUR_TERM.strs[320])
end_define

begin_define
define|#
directive|define
name|initialize_pair
value|(_CUR_TERM.strs[321])
end_define

begin_define
define|#
directive|define
name|key_mouse
value|(_CUR_TERM.strs[322])
end_define

begin_define
define|#
directive|define
name|label_format
value|(_CUR_TERM.strs[323])
end_define

begin_define
define|#
directive|define
name|micro_column_address
value|(_CUR_TERM.strs[324])
end_define

begin_define
define|#
directive|define
name|micro_down
value|(_CUR_TERM.strs[325])
end_define

begin_define
define|#
directive|define
name|micro_left
value|(_CUR_TERM.strs[326])
end_define

begin_define
define|#
directive|define
name|micro_right
value|(_CUR_TERM.strs[327])
end_define

begin_define
define|#
directive|define
name|micro_row_address
value|(_CUR_TERM.strs[328])
end_define

begin_define
define|#
directive|define
name|micro_up
value|(_CUR_TERM.strs[329])
end_define

begin_define
define|#
directive|define
name|mouse_info
value|(_CUR_TERM.strs[330])
end_define

begin_define
define|#
directive|define
name|order_of_pins
value|(_CUR_TERM.strs[331])
end_define

begin_define
define|#
directive|define
name|orig_colors
value|(_CUR_TERM.strs[332])
end_define

begin_define
define|#
directive|define
name|orig_pair
value|(_CUR_TERM.strs[333])
end_define

begin_define
define|#
directive|define
name|parm_down_micro
value|(_CUR_TERM.strs[334])
end_define

begin_define
define|#
directive|define
name|parm_left_micro
value|(_CUR_TERM.strs[335])
end_define

begin_define
define|#
directive|define
name|parm_right_micro
value|(_CUR_TERM.strs[336])
end_define

begin_define
define|#
directive|define
name|parm_up_micro
value|(_CUR_TERM.strs[337])
end_define

begin_define
define|#
directive|define
name|pc_term_options
value|(_CUR_TERM.strs[338])
end_define

begin_define
define|#
directive|define
name|pkey_plab
value|(_CUR_TERM.strs[339])
end_define

begin_define
define|#
directive|define
name|pulse
value|(_CUR_TERM.strs[340])
end_define

begin_define
define|#
directive|define
name|quick_dial
value|(_CUR_TERM.strs[341])
end_define

begin_define
define|#
directive|define
name|remove_clock
value|(_CUR_TERM.strs[342])
end_define

begin_define
define|#
directive|define
name|req_mouse_pos
value|(_CUR_TERM.strs[343])
end_define

begin_define
define|#
directive|define
name|scancode_escape
value|(_CUR_TERM.strs[344])
end_define

begin_define
define|#
directive|define
name|select_char_set
value|(_CUR_TERM.strs[345])
end_define

begin_define
define|#
directive|define
name|set0_des_seq
value|(_CUR_TERM.strs[346])
end_define

begin_define
define|#
directive|define
name|set1_des_seq
value|(_CUR_TERM.strs[347])
end_define

begin_define
define|#
directive|define
name|set2_des_seq
value|(_CUR_TERM.strs[348])
end_define

begin_define
define|#
directive|define
name|set3_des_seq
value|(_CUR_TERM.strs[349])
end_define

begin_define
define|#
directive|define
name|set_a_background
value|(_CUR_TERM.strs[350])
end_define

begin_define
define|#
directive|define
name|set_a_foreground
value|(_CUR_TERM.strs[351])
end_define

begin_define
define|#
directive|define
name|set_background
value|(_CUR_TERM.strs[352])
end_define

begin_define
define|#
directive|define
name|set_bottom_margin
value|(_CUR_TERM.strs[353])
end_define

begin_define
define|#
directive|define
name|set_bottom_margin_parm
value|(_CUR_TERM.strs[354])
end_define

begin_define
define|#
directive|define
name|set_clock
value|(_CUR_TERM.strs[355])
end_define

begin_define
define|#
directive|define
name|set_color_band
value|(_CUR_TERM.strs[356])
end_define

begin_define
define|#
directive|define
name|set_color_pair
value|(_CUR_TERM.strs[357])
end_define

begin_define
define|#
directive|define
name|set_foreground
value|(_CUR_TERM.strs[358])
end_define

begin_define
define|#
directive|define
name|set_left_margin_parm
value|(_CUR_TERM.strs[359])
end_define

begin_define
define|#
directive|define
name|set_lr_margin
value|(_CUR_TERM.strs[360])
end_define

begin_define
define|#
directive|define
name|set_page_length
value|(_CUR_TERM.strs[361])
end_define

begin_define
define|#
directive|define
name|set_right_margin_parm
value|(_CUR_TERM.strs[362])
end_define

begin_define
define|#
directive|define
name|set_tb_margin
value|(_CUR_TERM.strs[363])
end_define

begin_define
define|#
directive|define
name|set_top_margin
value|(_CUR_TERM.strs[364])
end_define

begin_define
define|#
directive|define
name|set_top_margin_parm
value|(_CUR_TERM.strs[365])
end_define

begin_define
define|#
directive|define
name|start_bit_image
value|(_CUR_TERM.strs[366])
end_define

begin_define
define|#
directive|define
name|start_char_set_def
value|(_CUR_TERM.strs[367])
end_define

begin_define
define|#
directive|define
name|stop_bit_image
value|(_CUR_TERM.strs[368])
end_define

begin_define
define|#
directive|define
name|stop_char_set_def
value|(_CUR_TERM.strs[369])
end_define

begin_define
define|#
directive|define
name|subscript_characters
value|(_CUR_TERM.strs[370])
end_define

begin_define
define|#
directive|define
name|superscript_characters
value|(_CUR_TERM.strs[371])
end_define

begin_define
define|#
directive|define
name|these_cause_cr
value|(_CUR_TERM.strs[372])
end_define

begin_define
define|#
directive|define
name|tone
value|(_CUR_TERM.strs[373])
end_define

begin_define
define|#
directive|define
name|user0
value|(_CUR_TERM.strs[374])
end_define

begin_define
define|#
directive|define
name|user1
value|(_CUR_TERM.strs[375])
end_define

begin_define
define|#
directive|define
name|user2
value|(_CUR_TERM.strs[376])
end_define

begin_define
define|#
directive|define
name|user3
value|(_CUR_TERM.strs[377])
end_define

begin_define
define|#
directive|define
name|user4
value|(_CUR_TERM.strs[378])
end_define

begin_define
define|#
directive|define
name|user5
value|(_CUR_TERM.strs[379])
end_define

begin_define
define|#
directive|define
name|user6
value|(_CUR_TERM.strs[380])
end_define

begin_define
define|#
directive|define
name|user7
value|(_CUR_TERM.strs[381])
end_define

begin_define
define|#
directive|define
name|user8
value|(_CUR_TERM.strs[382])
end_define

begin_define
define|#
directive|define
name|user9
value|(_CUR_TERM.strs[383])
end_define

begin_define
define|#
directive|define
name|wait_tone
value|(_CUR_TERM.strs[384])
end_define

begin_define
define|#
directive|define
name|zero_motion
value|(_CUR_TERM.strs[385])
end_define

begin_define
define|#
directive|define
name|backspace_if_not_bs
value|(_CUR_TERM.strs[386])
end_define

begin_define
define|#
directive|define
name|other_non_function_keys
value|(_CUR_TERM.strs[387])
end_define

begin_define
define|#
directive|define
name|arrow_key_map
value|(_CUR_TERM.strs[388])
end_define

begin_define
define|#
directive|define
name|memory_lock_above
value|(_CUR_TERM.strs[389])
end_define

begin_define
define|#
directive|define
name|memory_unlock
value|(_CUR_TERM.strs[390])
end_define

begin_define
define|#
directive|define
name|linefeed_if_not_lf
value|(_CUR_TERM.strs[391])
end_define

begin_define
define|#
directive|define
name|key_interrupt_char
value|(_CUR_TERM.strs[392])
end_define

begin_define
define|#
directive|define
name|key_kill_char
value|(_CUR_TERM.strs[393])
end_define

begin_define
define|#
directive|define
name|key_suspend_char
value|(_CUR_TERM.strs[394])
end_define

begin_define
define|#
directive|define
name|scroll_left
value|(_CUR_TERM.strs[395])
end_define

begin_define
define|#
directive|define
name|scroll_right
value|(_CUR_TERM.strs[396])
end_define

begin_define
define|#
directive|define
name|parm_scroll_left
value|(_CUR_TERM.strs[397])
end_define

begin_define
define|#
directive|define
name|parm_scroll_right
value|(_CUR_TERM.strs[398])
end_define

begin_define
define|#
directive|define
name|_get_other
value|(_CUR_TERM.strs[399])
end_define

begin_define
define|#
directive|define
name|NUM_OF_BOOLS
value|53
end_define

begin_define
define|#
directive|define
name|NUM_OF_NUMS
value|42
end_define

begin_define
define|#
directive|define
name|NUM_OF_STRS
value|400
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|OVERRIDE
end_ifndef

begin_undef
undef|#
directive|undef
name|_USE_SGTTY
end_undef

begin_undef
undef|#
directive|undef
name|_USE_TERMIO
end_undef

begin_undef
undef|#
directive|undef
name|_USE_TERMIOS
end_undef

begin_define
define|#
directive|define
name|_USE_TERMIOS
end_define

begin_undef
undef|#
directive|undef
name|_USE_SMALLMEM
end_undef

begin_undef
undef|#
directive|undef
name|_USE_PROTOTYPES
end_undef

begin_define
define|#
directive|define
name|_USE_PROTOTYPES
end_define

begin_undef
undef|#
directive|undef
name|_USE_WINSZ
end_undef

begin_define
define|#
directive|define
name|_USE_WINSZ
end_define

begin_undef
undef|#
directive|undef
name|_USE_TERMINFO
end_undef

begin_undef
undef|#
directive|undef
name|_USE_TERMCAP
end_undef

begin_define
define|#
directive|define
name|_USE_TERMCAP
end_define

begin_undef
undef|#
directive|undef
name|_MAX_CHUNK
end_undef

begin_define
define|#
directive|define
name|_MAX_CHUNK
value|640
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OVERRIDE */
end_comment

begin_comment
comment|/*   * 92/02/01 07:30:28  * @(#) mytinfo term.tail 3.2 92/02/01 public domain, By Ross Ridge  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_USE_TERMIO
argument_list|)
operator|||
name|defined
argument_list|(
name|_USE_TERMIOS
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|ICANON
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_USE_TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_USE_WINSZ
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_USE_WINSZ
argument_list|)
operator|&&
name|defined
argument_list|(
name|xenix
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptem.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_USE_SGTTY
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CBREAK
end_ifndef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_terminal
block|{
name|int
name|fd
decl_stmt|;
ifdef|#
directive|ifdef
name|_USE_SMALLMEM
ifdef|#
directive|ifdef
name|_USE_TERMIOS
name|speed_t
name|baudrate
decl_stmt|;
else|#
directive|else
name|unsigned
name|short
name|baudrate
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|pad
range|:
literal|1
decl_stmt|,
name|xon
range|:
literal|1
decl_stmt|,
name|termcap
range|:
literal|1
decl_stmt|;
else|#
directive|else
name|int
name|pad
decl_stmt|;
name|int
name|xon
decl_stmt|;
name|int
name|termcap
decl_stmt|;
ifdef|#
directive|ifdef
name|_USE_TERMIOS
name|speed_t
name|baudrate
decl_stmt|;
else|#
directive|else
name|long
name|baudrate
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|char
name|padch
decl_stmt|;
name|short
name|true_lines
decl_stmt|,
name|true_columns
decl_stmt|;
struct|struct
name|strbuf
block|{
name|struct
name|strbuf
modifier|*
name|next
decl_stmt|;
ifdef|#
directive|ifdef
name|_USE_SMALLMEM
name|short
name|len
decl_stmt|;
else|#
directive|else
name|int
name|len
decl_stmt|;
endif|#
directive|endif
name|char
name|buf
index|[
name|_MAX_CHUNK
index|]
decl_stmt|;
block|}
modifier|*
name|strbuf
struct|;
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|name_long
decl_stmt|,
modifier|*
name|name_all
decl_stmt|;
ifdef|#
directive|ifdef
name|_USE_SGTTY
struct|struct
name|sgtty_str
block|{
name|struct
name|sgttyb
name|v6
decl_stmt|;
ifdef|#
directive|ifdef
name|TIOCGETC
name|struct
name|tchars
name|v7
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCLGET
name|int
name|bsd
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TIOCGLTC
name|struct
name|ltchars
name|bsd_new
decl_stmt|;
endif|#
directive|endif
block|}
name|prog_mode
struct|,
name|shell_mode
struct|;
else|#
directive|else
comment|/* _USE_SGTTY */
ifdef|#
directive|ifdef
name|_USE_TERMIOS
name|struct
name|termios
name|prog_mode
decl_stmt|,
name|shell_mode
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|_USE_TERMIO
name|struct
name|termio
name|prog_mode
decl_stmt|,
name|shell_mode
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
comment|/* else _USE_SGTTY */
ifdef|#
directive|ifdef
name|_USE_WINSZ
ifdef|#
directive|ifdef
name|TIOCGWINSZ
name|struct
name|winsize
name|prog_winsz
decl_stmt|,
name|shell_winsz
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|char
name|bools
index|[
name|NUM_OF_BOOLS
index|]
decl_stmt|;
name|short
name|nums
index|[
name|NUM_OF_NUMS
index|]
decl_stmt|;
name|char
modifier|*
name|strs
index|[
name|NUM_OF_STRS
index|]
decl_stmt|;
block|}
name|TERMINAL
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_CUR_TERM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SINGLE
end_ifdef

begin_define
define|#
directive|define
name|_CUR_TERM
value|_term_buf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_CUR_TERM
value|(*cur_term)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|TERMINAL
modifier|*
name|cur_term
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TERMINAL
name|_term_buf
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_USE_PROTOTYPES
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_comment
comment|/* full-blown ANSI C */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_comment
comment|/* traditional C preprocessor */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tparm
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|setupterm
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|,
name|set_curterm
name|__P
argument_list|(
operator|(
name|TERMINAL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|del_curterm
name|__P
argument_list|(
operator|(
name|TERMINAL
operator|*
operator|)
argument_list|)
decl_stmt|,
name|tputs
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|putp
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
name|tigetflag
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|,
name|tigetnum
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
name|char
modifier|*
name|tigetstr
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
name|def_prog_mode
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|def_shell_mode
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
name|reset_prog_mode
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|,
name|reset_shell_mode
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
name|boolnames
index|[]
decl_stmt|,
modifier|*
name|boolcodes
index|[]
decl_stmt|,
modifier|*
name|boolfnames
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|numnames
index|[]
decl_stmt|,
modifier|*
name|numcodes
index|[]
decl_stmt|,
modifier|*
name|numfnames
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strnames
index|[]
decl_stmt|,
modifier|*
name|strcodes
index|[]
decl_stmt|,
modifier|*
name|strfnames
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|OK
end_ifndef

begin_undef
undef|#
directive|undef
name|ERR
end_undef

begin_define
define|#
directive|define
name|OK
value|(0)
end_define

begin_define
define|#
directive|define
name|ERR
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compatibility */
end_comment

begin_define
define|#
directive|define
name|Filedes
value|fd
end_define

begin_define
define|#
directive|define
name|Ottyb
value|shell_mode
end_define

begin_define
define|#
directive|define
name|Nttyb
value|prog_mode
end_define

begin_define
define|#
directive|define
name|TTY
value|struct termios
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TERM_H_ */
end_comment

end_unit

