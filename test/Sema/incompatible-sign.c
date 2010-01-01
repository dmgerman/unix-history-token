begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_function_decl
name|int
name|a
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|b
parameter_list|(
name|unsigned
modifier|*
name|y
parameter_list|)
block|{
return|return
name|a
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// expected-warning {{pointer types point to integer types with different sign}}
end_comment

end_unit

