begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -S %s        2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g     2>&1 | FileCheck --check-prefix=CHECK-WITH-G    %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0    2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g -g0 2>&1 | FileCheck --check-prefix=CHECK-WITHOUT-G %s
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -g0 -g 2>&1 | FileCheck --check-prefix=CHECK-WITH-G    %s
end_comment

begin_comment
comment|// CHECK-WITHOUT-G-NOT: "-g"
end_comment

begin_comment
comment|// CHECK-WITH-G: "-g"
end_comment

end_unit

