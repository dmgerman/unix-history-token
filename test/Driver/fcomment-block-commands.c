begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we pass -fcomment-block-commands to frontend.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-ARG
end_comment

begin_comment
comment|// RUN: %clang -c %s -fcomment-block-commands=Foo -### 2>&1 | FileCheck %s --check-prefix=CHECK-ARG
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ARG: -fcomment-block-commands=Foo
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-ARG-NOT: -fcomment-block-commands=
end_comment

end_unit

