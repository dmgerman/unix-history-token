begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|int
name|unary_int_func
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|unary_int_func
name|add_one
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|add_one
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
return|return
name|arg
operator|+
literal|1
return|;
block|}
end_function

end_unit

