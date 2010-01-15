begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -fsyntax-only -Xclang -verify -fblocks -Wunreachable-code
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
goto|goto
name|c
goto|;
name|d
label|:
goto|goto
name|e
goto|;
comment|// expected-warning {{will never be executed}}
name|c
label|:
empty_stmt|;
name|int
name|i
decl_stmt|;
return|return;
goto|goto
name|b
goto|;
comment|// expected-warning {{will never be executed}}
goto|goto
name|a
goto|;
comment|// expected-warning {{will never be executed}}
name|b
label|:
name|i
operator|=
literal|1
expr_stmt|;
name|a
label|:
name|i
operator|=
literal|2
expr_stmt|;
goto|goto
name|f
goto|;
name|e
label|:
goto|goto
name|d
goto|;
name|f
label|:
empty_stmt|;
block|}
end_function

end_unit

