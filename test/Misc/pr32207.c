begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// test for r305179
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -O -mllvm -print-after-all %s -o %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: *** IR Dump After Function Integration/Inlining ***
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

end_unit

