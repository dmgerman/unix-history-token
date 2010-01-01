begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
condition|)
empty_stmt|;
comment|// expected-warning {{if statement has empty body}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|int
name|a
parameter_list|)
block|{
if|if
condition|(
name|a
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f3
parameter_list|()
block|{
if|if
condition|(
literal|1
condition|)
name|xx
expr_stmt|;
comment|// expected-error {{use of undeclared identifier}}
return|return;
comment|// no empty body warning.
block|}
end_function

end_unit

