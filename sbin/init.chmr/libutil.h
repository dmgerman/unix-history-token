begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * missing prototypes for the functions in libutil.  * These should be conatined in a system header file, but aren't.  */
end_comment

begin_function_decl
name|int
name|logout
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|logwtmp
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_tty
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

