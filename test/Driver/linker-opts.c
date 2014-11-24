begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env LIBRARY_PATH=%T/test1 %clang -x c %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-L{{.*}}/test1"
end_comment

begin_comment
comment|// GCC driver is used as linker on cygming. It should be aware of LIBRARY_PATH.
end_comment

begin_comment
comment|// XFAIL: win32
end_comment

begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// REQUIRES: native
end_comment

begin_comment
comment|// Make sure that LIBRARY_PATH works for both i386 and x86_64 on Darwin.
end_comment

begin_comment
comment|// RUN: env LIBRARY_PATH=%T/test1 %clang -target x86_64-apple-darwin %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: env LIBRARY_PATH=%T/test1 %clang -target i386-apple-darwin  %s -### 2>&1 | FileCheck %s
end_comment

end_unit

