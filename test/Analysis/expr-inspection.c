begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=debug.ExprInspection -verify %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Self-tests for the debug.ExprInspection checker.
end_comment

begin_function_decl
name|void
name|clang_analyzer_dump
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clang_analyzer_printState
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clang_analyzer_numTimesReached
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|clang_analyzer_dump
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// expected-warning{{reg_$0<int x>}}
name|int
name|y
init|=
literal|1
decl_stmt|;
name|clang_analyzer_printState
argument_list|()
expr_stmt|;
for|for
control|(
init|;
name|y
operator|<
literal|3
condition|;
operator|++
name|y
control|)
name|clang_analyzer_numTimesReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{2}}
block|}
end_function

begin_comment
comment|// CHECK: Store (direct and default bindings)
end_comment

begin_comment
comment|// CHECK-NEXT: (y,0,direct) : 1 S32b
end_comment

begin_comment
comment|// CHECK: Expressions:
end_comment

begin_comment
comment|// CHECK-NEXT: clang_analyzer_printState :&code{clang_analyzer_printState}
end_comment

begin_comment
comment|// CHECK-NEXT: {{(Ranges are empty.)|(Constraints:[[:space:]]*$)}}
end_comment

end_unit

