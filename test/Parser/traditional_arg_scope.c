begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_function
name|int
name|x
parameter_list|(
name|a
parameter_list|)
name|int
name|a
decl_stmt|;
block|{
return|return
name|a
return|;
block|}
end_function

begin_function
name|int
name|y
parameter_list|(
name|b
parameter_list|)
name|int
name|b
decl_stmt|;
block|{
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// expected-error {{use of undeclared identifier}}
end_comment

begin_comment
comment|// PR2332
end_comment

begin_function
name|int
name|a
parameter_list|(
name|a
parameter_list|)
name|int
name|a
decl_stmt|;
block|{
name|a
operator|=
literal|10
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

end_unit

