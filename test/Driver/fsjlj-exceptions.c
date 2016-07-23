begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv7-apple-ios -fexceptions -c %s -o /dev/null -### 2>&1 | FileCheck -check-prefix CHECK-IOS %s
end_comment

begin_comment
comment|// RUN: %clang -target i686-windows-gnu -fexceptions -c %s -o /dev/null -### 2>&1 | FileCheck -check-prefix CHECK-MINGW-DEFAULT %s
end_comment

begin_comment
comment|// RUN: %clang -target i686-windows-gnu -fexceptions -fsjlj-exceptions -c %s -o /dev/null -### 2>&1 | FileCheck -check-prefix CHECK-MINGW-SJLJ %s
end_comment

begin_comment
comment|// CHECK-IOS: -fsjlj-exceptions
end_comment

begin_comment
comment|// CHECK-MINGW-DEFAULT-NOT: -fsjlj-exceptions
end_comment

begin_comment
comment|// CHECK-MINGW-SJLJ: -fsjlj-exceptions
end_comment

end_unit

