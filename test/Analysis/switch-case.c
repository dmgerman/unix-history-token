begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,debug.ExprInspection -verify %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clang_analyzer_warnIfReached
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|INT_MIN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|INT_MAX
value|0x7fffffff
end_define

begin_comment
comment|// PR16833: Analyzer consumes memory until killed by kernel OOM killer
end_comment

begin_comment
comment|// while analyzing large case ranges.
end_comment

begin_function
name|void
name|PR16833
parameter_list|(
name|unsigned
name|op
parameter_list|)
block|{
switch|switch
condition|(
name|op
condition|)
block|{
case|case
literal|0x02
operator|<<
literal|26
operator|...
literal|0x03
operator|<<
literal|26
case|:
comment|// Analyzer should not hang here.
return|return;
block|}
block|}
end_function

begin_function
name|void
name|testAdjustment
parameter_list|(
name|int
name|t
parameter_list|)
block|{
switch|switch
condition|(
name|t
operator|+
literal|1
condition|)
block|{
case|case
literal|2
case|:
name|clang_analyzer_eval
argument_list|(
name|t
operator|==
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
break|break;
case|case
literal|3
operator|...
literal|10
case|:
name|clang_analyzer_eval
argument_list|(
name|t
operator|>
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
name|t
operator|+
literal|2
operator|<=
literal|11
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
name|t
operator|>
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
name|clang_analyzer_eval
argument_list|(
name|t
operator|+
literal|1
operator|==
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
name|clang_analyzer_eval
argument_list|(
name|t
operator|+
literal|1
operator|==
literal|10
argument_list|)
expr_stmt|;
comment|// expected-warning{{UNKNOWN}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
block|}
block|}
end_function

begin_function
name|void
name|testUnknownVal
parameter_list|(
name|int
name|value
parameter_list|,
name|int
name|mask
parameter_list|)
block|{
comment|// Once ConstraintManager will process '&' and this test will require some changes.
switch|switch
condition|(
name|value
operator|&
name|mask
condition|)
block|{
case|case
literal|1
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
case|case
literal|3
operator|...
literal|10
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
block|}
block|}
end_function

begin_function
name|void
name|testSwitchCond
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|arg
operator|>
literal|10
condition|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
name|INT_MIN
operator|...
literal|10
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|11
operator|...
literal|20
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
block|}
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
name|INT_MIN
operator|...
literal|9
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|10
operator|...
literal|20
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|>
literal|10
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
block|}
block|}
comment|// arg> 10
block|}
end_function

begin_function
name|void
name|testDefaultUnreachable
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|arg
operator|>
literal|10
condition|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
name|INT_MIN
operator|...
literal|9
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|10
operator|...
name|INT_MAX
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|>
literal|10
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
block|}
block|}
block|}
end_function

begin_function
name|void
name|testBranchReachability
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|arg
operator|>
literal|10
operator|&&
name|arg
operator|<
literal|20
condition|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
name|INT_MIN
operator|...
literal|4
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|5
operator|...
literal|9
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|10
operator|...
literal|15
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|>
literal|10
operator|&&
name|arg
operator|<=
literal|15
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|17
operator|...
literal|25
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|>=
literal|17
operator|&&
name|arg
operator|<
literal|20
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
break|break;
case|case
literal|26
operator|...
name|INT_MAX
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|16
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|==
literal|16
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
break|break;
block|}
block|}
block|}
end_function

begin_function
name|void
name|testDefaultBranchRange
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
name|INT_MIN
operator|...
literal|9
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
case|case
literal|20
operator|...
name|INT_MAX
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|>=
literal|20
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|==
literal|16
argument_list|)
expr_stmt|;
comment|// expected-warning{{FALSE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|>
literal|9
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
name|arg
operator|<=
literal|20
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
case|case
literal|16
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
block|}
block|}
end_function

begin_function
name|void
name|testAllUnreachableButDefault
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|arg
operator|<
literal|0
condition|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
literal|0
operator|...
literal|9
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|20
operator|...
name|INT_MAX
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
case|case
literal|16
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
block|}
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
block|}
block|}
end_function

begin_function
name|void
name|testAllUnreachable
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|arg
operator|<
literal|0
condition|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
literal|0
operator|...
literal|9
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|20
operator|...
name|INT_MAX
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
case|case
literal|16
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
block|}
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
block|}
block|}
end_function

begin_function
name|void
name|testDifferentTypes
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
operator|-
literal|1U
operator|...
literal|400000000LL
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|testDifferentTypes2
parameter_list|(
name|unsigned
name|long
name|arg
parameter_list|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
literal|1UL
operator|...
literal|400000000UL
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|testDifferentTypes3
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
literal|1UL
operator|...
literal|400000000UL
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|testConstant
parameter_list|()
block|{
switch|switch
condition|(
literal|3
condition|)
block|{
case|case
literal|1
operator|...
literal|5
case|:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
break|break;
default|default:
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
break|break;
block|}
block|}
end_function

end_unit

