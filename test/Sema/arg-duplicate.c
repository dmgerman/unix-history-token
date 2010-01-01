begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|int
name|f3
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|x
parameter_list|)
comment|// expected-error {{redefinition of parameter}}
name|int
name|y
decl_stmt|,
name|x
decl_stmt|,
name|x
decl_stmt|;
comment|// expected-error {{redefinition of parameter}}
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_function
name|void
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
name|f3
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{too many arguments}}
block|}
end_function

end_unit

