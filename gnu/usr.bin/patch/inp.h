begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$  *  * $Log: inp.h,v $  * Revision 2.0  86/09/17  15:37:25  lwall  * Baseline for netwide release.  *  */
end_comment

begin_decl_stmt
name|EXT
name|LINENUM
name|input_lines
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how long is input file in lines */
end_comment

begin_decl_stmt
name|EXT
name|LINENUM
name|last_frozen_line
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many input lines have been */
end_comment

begin_comment
comment|/* irretractibly output */
end_comment

begin_function_decl
name|bool
name|rev_in_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|scan_input
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|plan_a
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* returns false if insufficient memory */
end_comment

begin_function_decl
name|void
name|plan_b
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ifetch
parameter_list|()
function_decl|;
end_function_decl

end_unit

