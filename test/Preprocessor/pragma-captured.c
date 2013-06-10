begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck %s
end_comment

begin_comment
comment|// Test pragma clang __debug captured, for Captured Statements
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{   }
comment|// CHECK: void test1()
comment|// CHECK: {
comment|// CHECK: #pragma clang __debug captured
block|}
end_function

end_unit

