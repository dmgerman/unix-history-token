begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core.builtin.NoReturnFunctions -analyzer-display-progress %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Do not analyze test1() again because it was inlined
end_comment

begin_function_decl
name|void
name|test1
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test2
parameter_list|()
block|{
name|test1
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test1
parameter_list|()
block|{ }
end_function

begin_comment
comment|// CHECK: analysis-order.c test2
end_comment

begin_comment
comment|// CHECK-NEXT: analysis-order.c test1
end_comment

begin_comment
comment|// CHECK-NEXT: analysis-order.c test2
end_comment

end_unit

