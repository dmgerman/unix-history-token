begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  top - a top users display for Unix 4.2  *  *  This file contains all the definitions necessary to use the hand-written  *  screen package in "screen.c"  */
end_comment

begin_define
define|#
directive|define
name|TCputs
parameter_list|(
name|str
parameter_list|)
value|tputs(str, 1, putstdout)
end_define

begin_define
define|#
directive|define
name|putcap
parameter_list|(
name|str
parameter_list|)
value|(void)((str) != NULL ? TCputs(str) : 0)
end_define

begin_define
define|#
directive|define
name|Move_to
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|TCputs(tgoto(cursor_motion, x, y))
end_define

begin_comment
comment|/* declare return values for termcap functions */
end_comment

begin_function_decl
name|char
modifier|*
name|tgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tgoto
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|ch_erase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to the user's erase character */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ch_kill
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to the user's kill  character */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|smart_terminal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if the terminal has sufficient termcap 				   capabilities for normal operation */
end_comment

begin_comment
comment|/* These are some termcap strings for use outside of "screen.c" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cursor_motion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|clear_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|clear_to_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rows and columns on the screen according to termcap */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|screen_length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|screen_width
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a function that puts a single character on stdout */
end_comment

begin_function_decl
name|int
name|putstdout
parameter_list|()
function_decl|;
end_function_decl

end_unit

