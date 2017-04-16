begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -### %s 2>&1 | FileCheck %s --check-prefix=CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mno-neg-immediates -### %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -### %s 2>&1 | FileCheck %s --check-prefix=CHECK-DEFAULT
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -mno-neg-immediates -### %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-target-feature" "+no-neg-immediates"
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: "+no-neg-immediates"
end_comment

end_unit

