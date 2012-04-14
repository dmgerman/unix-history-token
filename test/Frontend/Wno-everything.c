begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -Wno-everything -Wsign-compare %s
end_comment

begin_function_decl
name|int
name|f0
parameter_list|(
name|int
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f0
parameter_list|(
name|int
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|)
block|{
if|if
condition|(
name|x
operator|=
literal|3
condition|)
empty_stmt|;
return|return
name|x
operator|<
name|y
return|;
comment|// expected-warning {{comparison of integers}}
block|}
end_function

end_unit

