begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_function
name|void
name|a
parameter_list|()
block|{
goto|goto
name|A
goto|;
end_function

begin_comment
comment|// expected-error {{use of undeclared label}}
end_comment

begin_comment
comment|// expected-error {{expected '}'}}
end_comment

end_unit

