begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)string.h	3.1 83/11/22  */
end_comment

begin_function_decl
name|char
modifier|*
name|str_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_itoa
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|str_cmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcmp(a, b)
end_define

end_unit

