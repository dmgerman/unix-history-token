begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|public
name|char
modifier|*
name|save
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|VOID_POINTER
name|ecalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|skipsp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|sprefix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|quit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|raw_mode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|scrsize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|special_key_str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|get_term
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|deinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|home
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|add_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|remove_top
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|lower_left
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|check_winch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|goto_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|vbell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|bell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|clear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|clear_eol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|clear_bot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|so_enter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|so_exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ul_enter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ul_exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|bo_enter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|bo_exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|bl_enter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|bl_exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|backspace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|putbs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
name|WIN32getch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|match_brac
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ch_ungetchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|end_logfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|sync_logfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|ch_seek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|ch_end_seek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|ch_beg_seek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|ch_length
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|ch_tell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|ch_forw_get
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|ch_back_get
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|ch_nbuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ch_flush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|seekable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ch_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ch_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|ch_getflags
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ch_dump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init_charset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|binary_char
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|control_char
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|prchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|cmd_reset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|clear_cmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|cmd_putstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|len_cmdbuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|set_mlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|cmd_addhist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|cmd_accept
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|cmd_char
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|cmd_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|get_cmdbuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|in_mca
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|dispversion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|getcc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ungetcc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ungetsc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|commands
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init_cmds
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|add_fcmd_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|add_ecmd_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|fcmd_decode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|ecmd_decode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|lgetenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|lesskey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|add_hometable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|editchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init_textlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|forw_textlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|back_textlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_first
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_last
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_next
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_prev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|IFILE
name|save_curr_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|unsave_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|reedit_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_stdin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|cat_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|use_logfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|unquote_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|homefile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|fexpand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|fcomplete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|bin_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|esc_metachars
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|esc_metachars
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|lglob
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|open_altfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|close_altfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|is_dir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|bad_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|filesize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|forw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|back
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|forward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|backward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|get_back_scroll
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|del_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|IFILE
name|next_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|IFILE
name|prev_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|IFILE
name|getoff_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|nifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|IFILE
name|get_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|get_filename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|get_index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|store_pos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|get_pos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|set_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|opened
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|hold_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|held_ifile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
modifier|*
name|get_filestate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|set_filestate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|if_dump
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|forw_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|back_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|set_attnpos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|jump_forw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|jump_back
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|repaint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|jump_percent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|jump_line_loc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|jump_loc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|prewind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|plinenum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|pappend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|pdone
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|gline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|null_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|forw_raw_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|back_raw_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|clr_linenum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|add_lnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|find_linenum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|find_pos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|currline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|lsystem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|pipe_mark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|pipe_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init_mark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|badmark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|setmark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|lastmark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|gomark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|markpos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|unmark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_o
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt__O
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_l
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_k
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_t
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt__T
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt__P
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_b
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_i
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt__V
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_D
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_quote
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|opt_query
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|get_swindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|scan_option
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|toggle_option
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|single_char_option
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|opt_prompt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|isoptpending
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|nopendopt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|getnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init_option
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|struct
name|option
modifier|*
name|findopt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|struct
name|option
modifier|*
name|findopt_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|iread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|intread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|long
name|get_time
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|errno_message
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|percentage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|percent_pos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|os9_signal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|isatty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|put_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|flush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|putchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|putstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|get_return
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|ierror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|query
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|position
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|add_forw_pos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|add_back_pos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|pos_clear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|pos_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|onscreen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|empty_screen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|empty_lines
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|get_scrpos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|adjsline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init_prompt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|pr_expand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|eq_message
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|char
modifier|*
name|pr_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|repaint_hilite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|clear_attn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|undo_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|clr_hilite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|is_hilited
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|chg_caseless
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|chg_hilite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|prep_hilite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|RETSIGTYPE
name|winch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|RETSIGTYPE
name|winch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|init_signals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|psignals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|findtag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|edit_tagfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|POSITION
name|tagsearch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|open_getchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|close_getchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|getchr
parameter_list|()
function_decl|;
end_function_decl

end_unit

