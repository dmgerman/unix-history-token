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
name|clang_analyzer_checkInlined
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test1_f1
parameter_list|()
block|{
name|int
name|y
init|=
literal|1
decl_stmt|;
name|y
operator|++
expr_stmt|;
name|clang_analyzer_checkInlined
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
return|return
name|y
return|;
block|}
end_function

begin_function
name|void
name|test1_f2
parameter_list|()
block|{
name|int
name|x
init|=
literal|1
decl_stmt|;
name|x
operator|=
name|test1_f1
argument_list|()
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|1
condition|)
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|3
expr_stmt|;
comment|// no-warning
block|}
if|if
condition|(
name|x
operator|==
literal|2
condition|)
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|3
expr_stmt|;
comment|// expected-warning{{Dereference of null pointer (loaded from variable 'p')}}
block|}
block|}
end_function

begin_comment
comment|// Test that inlining works when the declared function has less arguments
end_comment

begin_comment
comment|// than the actual number in the declaration.
end_comment

begin_function
name|void
name|test2_f1
parameter_list|()
block|{}
end_function

begin_function_decl
name|int
name|test2_f2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test2_f3
parameter_list|()
block|{
name|test2_f1
argument_list|(
name|test2_f2
argument_list|()
argument_list|)
expr_stmt|;
comment|// expected-warning{{too many arguments in call to 'test2_f1'}}
block|}
end_function

begin_comment
comment|// Test that inlining works with recursive functions.
end_comment

begin_function
name|unsigned
name|factorial
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|<=
literal|1
condition|)
return|return
literal|1
return|;
return|return
name|x
operator|*
name|factorial
argument_list|(
name|x
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_factorial
parameter_list|()
block|{
if|if
condition|(
name|factorial
argument_list|(
literal|3
argument_list|)
operator|==
literal|6
condition|)
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|0xDEADBEEF
expr_stmt|;
comment|// expected-warning {{null}}
block|}
else|else
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|0xDEADBEEF
expr_stmt|;
comment|// no-warning
block|}
block|}
end_function

begin_function
name|void
name|test_factorial_2
parameter_list|()
block|{
name|unsigned
name|x
init|=
name|factorial
argument_list|(
literal|3
argument_list|)
decl_stmt|;
if|if
condition|(
name|x
operator|==
name|factorial
argument_list|(
literal|3
argument_list|)
condition|)
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|0xDEADBEEF
expr_stmt|;
comment|// expected-warning {{null}}
block|}
else|else
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|0xDEADBEEF
expr_stmt|;
comment|// no-warning
block|}
block|}
end_function

begin_comment
comment|// Test that returning stack memory from a parent stack frame does
end_comment

begin_comment
comment|// not trigger a warning.
end_comment

begin_function
specifier|static
name|char
modifier|*
name|return_buf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
block|{
return|return
name|buf
operator|+
literal|10
return|;
block|}
end_function

begin_function
name|void
name|test_return_stack_memory_ok
parameter_list|()
block|{
name|char
name|stack_buf
index|[
literal|100
index|]
decl_stmt|;
name|char
modifier|*
name|pos
init|=
name|return_buf
argument_list|(
name|stack_buf
argument_list|)
decl_stmt|;
operator|(
name|void
operator|)
name|pos
expr_stmt|;
block|}
end_function

begin_function
name|char
modifier|*
name|test_return_stack_memory_bad
parameter_list|()
block|{
name|char
name|stack_buf
index|[
literal|100
index|]
decl_stmt|;
name|char
modifier|*
name|x
init|=
name|stack_buf
decl_stmt|;
return|return
name|x
return|;
comment|// expected-warning {{stack memory associated}}
block|}
end_function

begin_comment
comment|// Test that passing a struct value with an uninitialized field does
end_comment

begin_comment
comment|// not trigger a warning if we are inlining and the body is available.
end_comment

begin_struct
struct|struct
name|rdar10977037
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|test_rdar10977037_aux
parameter_list|(
name|struct
name|rdar10977037
name|v
parameter_list|)
block|{
return|return
name|v
operator|.
name|y
return|;
block|}
end_function

begin_function_decl
name|int
name|test_rdar10977037_aux_2
parameter_list|(
name|struct
name|rdar10977037
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test_rdar10977037
parameter_list|()
block|{
name|struct
name|rdar10977037
name|v
decl_stmt|;
name|v
operator|.
name|y
operator|=
literal|1
expr_stmt|;
name|v
operator|.
name|y
operator|+=
name|test_rdar10977037_aux
argument_list|(
name|v
argument_list|)
expr_stmt|;
comment|// no-warning
return|return
name|test_rdar10977037_aux_2
argument_list|(
name|v
argument_list|)
return|;
comment|// expected-warning {{Passed-by-value struct argument contains uninitialized data}}
block|}
end_function

begin_comment
comment|// Test inlining a forward-declared function.
end_comment

begin_comment
comment|// This regressed when CallEvent was first introduced.
end_comment

begin_function_decl
name|int
name|plus1
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test
parameter_list|()
block|{
name|clang_analyzer_eval
argument_list|(
name|plus1
argument_list|(
literal|2
argument_list|)
operator|==
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
end_function

begin_function
name|int
name|plus1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|+
literal|1
return|;
block|}
end_function

begin_function
name|void
name|never_called_by_anyone
parameter_list|()
block|{
name|clang_analyzer_checkInlined
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|knr_one_argument
parameter_list|(
name|a
parameter_list|)
name|int
name|a
decl_stmt|;
block|{ }
end_function

begin_function
name|void
name|call_with_less_arguments
parameter_list|()
block|{
name|knr_one_argument
argument_list|()
expr_stmt|;
comment|// expected-warning{{too few arguments}} expected-warning{{Function taking 1 argument is called with fewer (0)}}
block|}
end_function

end_unit

