begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wunused-label -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|a
label|:
goto|goto
name|a
goto|;
name|b
label|:
comment|// expected-warning{{unused}}
name|c
label|:
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
expr_stmt|;
name|d
label|:
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{'noreturn' attribute only applies to functions}}
goto|goto
name|d
goto|;
return|return;
block|}
end_function

begin_function
name|void
name|PR8455
parameter_list|()
block|{
name|L
label|:
name|__attribute__
argument_list|(
argument|(unused)
argument_list|)
return|return;
comment|// ok, no semicolon required
block|}
end_function

end_unit

