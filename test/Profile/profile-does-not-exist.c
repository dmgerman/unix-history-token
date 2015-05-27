begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -emit-llvm %s -o - -fprofile-instr-use=%t.nonexistent.profdata 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: Could not read profile:
end_comment

begin_comment
comment|// CHECK-NOT: Assertion failed
end_comment

end_unit

