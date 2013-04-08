begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang --param ssp-buffer-size=1 %t.o -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: warning: argument unused during compilation: '--param ssp-buffer-size=1'
end_comment

end_unit

