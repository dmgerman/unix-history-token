begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -fsyntax-only -verify %s  */
end_comment

begin_define
define|#
directive|define
name|XRECORD
parameter_list|(
name|x
parameter_list|,
name|c_name
parameter_list|)
value|e##c (x, __LINE__)
end_define

begin_function_decl
name|int
name|ec
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|x
parameter_list|()
block|{
name|XRECORD
argument_list|(
name|XRECORD
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

