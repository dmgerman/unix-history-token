begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we pass -fretain-comments-from-system-headers to frontend.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-RETAIN
end_comment

begin_comment
comment|// RUN: %clang -c %s -fretain-comments-from-system-headers -### 2>&1 | FileCheck %s --check-prefix=CHECK-RETAIN
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-RETAIN: -fretain-comments-from-system-headers
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-RETAIN-NOT: -fretain-comments-from-system-headers
end_comment

end_unit

