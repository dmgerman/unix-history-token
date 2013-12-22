begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -fblocks
end_comment

begin_function
name|void
name|test_gotos
parameter_list|()
block|{
goto|goto
name|L1
goto|;
comment|// expected-error {{use of undeclared label 'L1'}}
goto|goto
name|L3
goto|;
comment|// OK
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|L1
label|:
goto|goto
name|L2
goto|;
comment|// OK
name|L2
label|:
goto|goto
name|L3
goto|;
comment|// expected-error {{use of undeclared label 'L3'}}
block|}
name|L3
label|:
empty_stmt|;
block|}
end_function

begin_function
name|void
name|test_break_continue
parameter_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
break|break;
comment|// expected-error {{'break' statement not in loop or switch statement}}
continue|continue;
comment|// expected-error {{'continue' statement not in loop statement}}
block|}
block|}
block|}
end_function

begin_function
name|void
name|test_return
parameter_list|()
block|{
while|while
condition|(
literal|1
condition|)
block|{
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
return|return;
comment|// expected-error {{cannot return from default captured statement}}
block|}
block|}
block|}
end_function

begin_function
name|void
name|test_nest
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|int
name|y
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|int
name|z
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|x
operator|=
name|z
operator|=
name|y
expr_stmt|;
comment|// OK
block|}
block|}
block|}
block|}
end_function

begin_function
name|void
name|test_nest_block
parameter_list|()
block|{
specifier|__block
name|int
name|x
decl_stmt|;
comment|// expected-note {{'x' declared here}}
name|int
name|y
decl_stmt|;
lambda|^
block|{
name|int
name|z
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
name|x
operator|=
name|y
expr_stmt|;
comment|// expected-error{{__block variable 'x' cannot be captured in a captured statement}}
name|y
operator|=
name|z
expr_stmt|;
comment|// expected-error{{variable is not assignable (missing __block type specifier)}}
name|z
operator|=
name|y
expr_stmt|;
comment|// OK
block|}
block|}
argument_list|()
expr_stmt|;
specifier|__block
name|int
name|a
decl_stmt|;
comment|// expected-note 2 {{'a' declared here}}
name|int
name|b
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
specifier|__block
name|int
name|c
decl_stmt|;
name|int
name|d
decl_stmt|;
lambda|^
block|{
name|a
operator|=
name|b
expr_stmt|;
comment|// expected-error{{__block variable 'a' cannot be captured in a captured statement}}
name|b
operator|=
name|d
expr_stmt|;
comment|// OK - Consistent with block inside a lambda
name|c
operator|=
name|a
expr_stmt|;
comment|// expected-error{{__block variable 'a' cannot be captured in a captured statement}}
name|c
operator|=
name|d
expr_stmt|;
comment|// OK
name|d
operator|=
name|b
expr_stmt|;
comment|// expected-error{{variable is not assignable (missing __block type specifier)}}
block|}
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

