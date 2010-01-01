begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f5
parameter_list|(
name|int
name|z
parameter_list|)
block|{
if|if
condition|(
name|z
condition|)
default|default:
comment|// expected-error {{not in switch statement}}
empty_stmt|;
comment|// expected-warning {{if statement has empty body}}
block|}
end_function

end_unit

