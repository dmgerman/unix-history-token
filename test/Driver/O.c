begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that we parse and translate the -O option correctly.
end_comment

begin_comment
comment|// RUN: %clang -O -### %s 2>&1 | FileCheck -check-prefix=CHECK-O %s
end_comment

begin_comment
comment|// CHECK-O: -O2
end_comment

begin_comment
comment|// RUN: %clang -O0 -### %s 2>&1 | FileCheck -check-prefix=CHECK-O0 %s
end_comment

begin_comment
comment|// CHECK-O0: -O0
end_comment

begin_comment
comment|// RUN: %clang -O1 -### %s 2>&1 | FileCheck -check-prefix=CHECK-O1 %s
end_comment

begin_comment
comment|// CHECK-O1: -O1
end_comment

end_unit

