begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -emit-llvm -arch x86_64 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-emit-llvm-bc"
end_comment

begin_comment
comment|// CHECK: "-emit-llvm-uselists"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -flto -arch x86_64 %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=LTO %s
end_comment

begin_comment
comment|// LTO:      "-emit-llvm-bc"
end_comment

begin_comment
comment|// LTO-NOT:  "-emit-llvm-uselists"
end_comment

end_unit

