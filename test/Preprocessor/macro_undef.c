begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -dM -undef -Dfoo=1 -E %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: #define __clang__
end_comment

begin_comment
comment|// CHECK: #define foo 1
end_comment

end_unit

