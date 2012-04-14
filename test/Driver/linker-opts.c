begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env LIBRARY_PATH=%T/test1 %clang -x c %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-L" "{{.*}}/test1"
end_comment

begin_comment
comment|// GCC driver is used as linker on cygming. It should be aware of LIBRARY_PATH.
end_comment

begin_comment
comment|// XFAIL: cygwin,mingw32
end_comment

end_unit

