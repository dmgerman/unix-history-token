begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|public
name|void
name|edit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|next_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|prev_file
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
name|init_option
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
name|void
name|scan_option
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
name|void
name|repaint
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
name|jump_percent
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
name|init_mark
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
name|gomark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|search
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
name|void
name|ch_init
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
name|int
name|onscreen
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
name|put_line
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
name|int
name|carat_char
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
name|void
name|dropout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|putc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|puts
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
name|int
name|error_width
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
name|lower_left
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
name|vbell
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
name|prewind
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
name|lsystem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|help
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|void
name|open_getc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|public
name|int
name|getc
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

end_unit

