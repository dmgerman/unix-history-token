begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we pass -fparse-all-comments to frontend.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -c %s -fparse-all-comments -### 2>&1 | FileCheck %s --check-prefix=CHECK-ARG
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ARG: -fparse-all-comments
end_comment

end_unit

