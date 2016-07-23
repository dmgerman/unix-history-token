begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -emit-llvm %s -o - -fprofile-instrument-use-path=%t.nonexistent.profdata 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: Could not read profile {{.*}}.nonexistent.profdata:
end_comment

begin_comment
comment|// CHECK-NOT: Assertion failed
end_comment

end_unit

