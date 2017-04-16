begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not --crash %clang_analyze_cc1 -analyzer-checker=debug.ExprInspection %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// REQUIRES: crash-recovery
end_comment

begin_comment
comment|// FIXME: CHECKs might be incompatible to win32.
end_comment

begin_comment
comment|// Stack traces also require back traces.
end_comment

begin_comment
comment|// REQUIRES: shell, backtrace
end_comment

begin_function_decl
name|void
name|clang_analyzer_crash
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|inlined
parameter_list|()
block|{
name|clang_analyzer_crash
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test
parameter_list|()
block|{
name|inlined
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: 0.	Program arguments: {{.*}}clang
end_comment

begin_comment
comment|// CHECK-NEXT: 1.<eof> parser at end of file
end_comment

begin_comment
comment|// CHECK-NEXT: 2. While analyzing stack:
end_comment

begin_comment
comment|// CHECK-NEXT:  #0 void inlined()
end_comment

begin_comment
comment|// CHECK-NEXT:  #1 void test()
end_comment

begin_comment
comment|// CHECK-NEXT: 3.	{{.*}}crash-trace.c:{{[0-9]+}}:3: Error evaluating statement
end_comment

end_unit

