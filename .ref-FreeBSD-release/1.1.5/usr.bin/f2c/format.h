begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|DEF_C_LINE_LENGTH
value|77
end_define

begin_comment
comment|/* actual max will be 79 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|c_output_line_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max # chars per line in C source 					   code */
end_comment

begin_function_decl
name|char
modifier|*
name|wr_ardecls
parameter_list|(
comment|/* FILE *, struct Dimblock * */
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|list_init_data
argument_list|()
decl_stmt|,
name|wr_one_init
argument_list|()
decl_stmt|,
name|wr_output_values
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|do_init_data
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|chainp
name|data_value
parameter_list|()
function_decl|;
end_function_decl

end_unit

