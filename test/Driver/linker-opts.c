begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|//
end_comment

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

begin_comment
comment|//
end_comment

begin_comment
comment|// Make sure that we don't warn on unused compiler arguments.
end_comment

begin_comment
comment|// RUN: %clang -Xclang -I. -x c %s -c -o %t/tmp.o
end_comment

begin_comment
comment|// RUN: %clang -Xclang -I. %t/tmp.o -o %t/tmp -### 2>&1 | FileCheck %s --check-prefix=NO-UNUSED
end_comment

begin_comment
comment|// NO-UNUSED-NOT: warning:{{.*}}unused
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Make sure that we do warn in other cases.
end_comment

begin_comment
comment|// RUN: %clang %s -lfoo -c -o %t/tmp2.o -### 2>&1 | FileCheck %s --check-prefix=UNUSED
end_comment

begin_comment
comment|// UNUSED: warning:{{.*}}unused
end_comment

end_unit

