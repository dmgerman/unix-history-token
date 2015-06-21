begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|void
name|double_declarator1
parameter_list|(
name|int
modifier|*
name|__nonnull
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning{{pointer is missing a nullability type specifier (__nonnull, __nullable, or __null_unspecified)}}
end_comment

end_unit

