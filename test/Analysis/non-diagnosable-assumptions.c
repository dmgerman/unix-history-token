begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -w -analyzer-checker=core.DivideZero -analyzer-output=text -verify %s
end_comment

begin_comment
comment|// This test file verifies the "Assuming..." diagnostic pieces that are being
end_comment

begin_comment
comment|// reported when the branch condition was too complicated to explain.
end_comment

begin_comment
comment|// Therefore, if your change replaces the generic "Assuming the condition is
end_comment

begin_comment
comment|// true" with a more specific message, causing this test to fail, the condition
end_comment

begin_comment
comment|// should be replaced with a more complicated condition that we still cannot
end_comment

begin_comment
comment|// properly explain to the user. Once we reach the point at which all conditions
end_comment

begin_comment
comment|// are "diagnosable", this test (or this note) should probably be removed,
end_comment

begin_comment
comment|// together with the code section that handles generic messages for
end_comment

begin_comment
comment|// non-diagnosable conditions.
end_comment

begin_comment
comment|// Function calls are currently non-diagnosable.
end_comment

begin_function_decl
name|int
name|non_diagnosable
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test_true
parameter_list|()
block|{
if|if
condition|(
name|non_diagnosable
argument_list|()
condition|)
block|{
comment|// expected-note@-1{{Assuming the condition is true}}
comment|// expected-note@-2{{Taking true branch}}
literal|1
operator|/
literal|0
expr_stmt|;
comment|// expected-warning@-1{{Division by zero}}
comment|// expected-note@-2{{Division by zero}}
block|}
block|}
end_function

begin_function
name|void
name|test_false
parameter_list|()
block|{
if|if
condition|(
name|non_diagnosable
argument_list|()
condition|)
block|{
comment|// expected-note@-1{{Assuming the condition is false}}
comment|// expected-note@-2{{Taking false branch}}
block|}
else|else
block|{
literal|1
operator|/
literal|0
expr_stmt|;
comment|// expected-warning@-1{{Division by zero}}
comment|// expected-note@-2{{Division by zero}}
block|}
block|}
end_function

begin_comment
comment|// Test that we're still reporting that the condition is true,
end_comment

begin_comment
comment|// when we encounter an exclamation mark (used to be broken).
end_comment

begin_function
name|void
name|test_exclamation_mark
parameter_list|()
block|{
if|if
condition|(
operator|!
name|non_diagnosable
argument_list|()
condition|)
block|{
comment|// expected-note@-1{{Assuming the condition is true}}
comment|// expected-note@-2{{Taking true branch}}
literal|1
operator|/
literal|0
expr_stmt|;
comment|// expected-warning@-1{{Division by zero}}
comment|// expected-note@-2{{Division by zero}}
block|}
block|}
end_function

end_unit

