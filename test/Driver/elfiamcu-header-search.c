begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-elfiamcu -c -v -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: /usr/include
end_comment

begin_comment
comment|// CHECK-NOT: /usr/local/include
end_comment

end_unit

