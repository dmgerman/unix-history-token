begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core.experimental.UnreachableCode -analyzer-check-objc-mem -analyzer-checker=core.DeadStores -verify -analyzer-opt-analyze-nested-blocks -Wno-unused-value %s
end_comment

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// The first few tests are non-path specific - we should be able to find them
end_comment

begin_function
name|void
name|test
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{
switch|switch
condition|(
name|a
condition|)
block|{
name|a
operator|+=
literal|5
expr_stmt|;
comment|// expected-warning{{never executed}}
case|case
literal|2
case|:
name|a
operator|*=
literal|10
expr_stmt|;
case|case
literal|3
case|:
name|a
operator|%=
literal|2
expr_stmt|;
block|}
name|foo
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{
name|help
label|:
if|if
condition|(
name|a
operator|>
literal|0
condition|)
return|return;
if|if
condition|(
name|a
operator|==
literal|0
condition|)
return|return;
name|foo
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning{{never executed}}
goto|goto
name|help
goto|;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
empty_stmt|;
if|if
condition|(
name|a
operator|>
literal|5
condition|)
block|{
comment|// expected-warning{{never executed}}
return|return;
block|}
block|}
end_function

begin_comment
comment|// These next tests are path-sensitive
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
name|int
name|a
init|=
literal|5
decl_stmt|;
while|while
condition|(
name|a
operator|>
literal|1
condition|)
name|a
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
name|a
operator|>
literal|1
condition|)
block|{
name|a
operator|=
name|a
operator|+
literal|56
expr_stmt|;
comment|// expected-warning{{never executed}}
block|}
name|foo
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|bar
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test5
parameter_list|(
specifier|const
name|char
modifier|*
name|c
parameter_list|)
block|{
name|foo
argument_list|(
name|c
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|c
condition|)
block|{
name|bar
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{never executed}}
block|}
block|}
end_function

begin_comment
comment|// These next tests are false positives and should not generate warnings
end_comment

begin_function
name|void
name|test6
parameter_list|(
specifier|const
name|char
modifier|*
name|c
parameter_list|)
block|{
if|if
condition|(
name|c
condition|)
return|return;
if|if
condition|(
operator|!
name|c
condition|)
return|return;
name|__builtin_unreachable
argument_list|()
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Compile-time constant false positives
end_comment

begin_define
define|#
directive|define
name|CONSTANT
value|0
end_define

begin_enum
enum|enum
name|test_enum
block|{
name|Off
block|,
name|On
block|}
enum|;
end_enum

begin_function
name|void
name|test7
parameter_list|()
block|{
if|if
condition|(
name|CONSTANT
condition|)
return|return;
comment|// no-warning
if|if
condition|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|)
return|return;
comment|// no-warning
if|if
condition|(
name|Off
condition|)
return|return;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test8
parameter_list|()
block|{
specifier|static
name|unsigned
name|a
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|a
condition|)
name|a
operator|=
literal|123
expr_stmt|;
comment|// no-warning
name|a
operator|=
literal|5
expr_stmt|;
block|}
end_function

begin_comment
comment|// Check for bugs where multiple statements are reported
end_comment

begin_function
name|void
name|test9
parameter_list|(
name|unsigned
name|a
parameter_list|)
block|{
switch|switch
condition|(
name|a
condition|)
block|{
if|if
condition|(
name|a
condition|)
comment|// expected-warning{{never executed}}
name|foo
argument_list|(
name|a
operator|+
literal|5
argument_list|)
expr_stmt|;
comment|// no-warning
else|else
comment|// no-warning
name|foo
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// no-warning
case|case
literal|1
case|:
case|case
literal|2
case|:
break|break;
default|default:
break|break;
block|}
block|}
end_function

begin_comment
comment|// Tests from flow-sensitive version
end_comment

begin_function
name|void
name|test10
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
comment|// expected-warning {{never executed}}
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
comment|// expected-warning {{never executed}}
goto|goto
name|a
goto|;
comment|// expected-warning {{never executed}}
name|b
label|:
name|i
operator|=
literal|1
expr_stmt|;
comment|// no-warning
name|a
label|:
name|i
operator|=
literal|2
expr_stmt|;
comment|// no-warning
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

