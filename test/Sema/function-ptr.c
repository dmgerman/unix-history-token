begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -pedantic
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
modifier|*
name|func
decl_stmt|;
end_decl_stmt

begin_function
name|unary_int_func
modifier|*
name|set_func
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|func
operator|=
name|p
expr_stmt|;
comment|// expected-warning {{converts between void* and function pointer}}
name|p
operator|=
name|func
expr_stmt|;
comment|// expected-warning {{converts between void* and function pointer}}
return|return
name|p
return|;
comment|// expected-warning {{converts between void* and function pointer}}
block|}
end_function

end_unit

