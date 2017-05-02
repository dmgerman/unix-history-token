begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-print-target-info %s --target=i386-unknown-linux-gnu | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-print-target-info %s --target=x86_64-unknown-linux-gnu | FileCheck --check-prefix=CHECK-1 %s
end_comment

begin_comment
comment|// CHECK: TargetTriple: i386-unknown-linux-gnu
end_comment

begin_comment
comment|// CHECK: PointerWidth: 32
end_comment

begin_comment
comment|// CHECK-1: TargetTriple: x86_64-unknown-linux-gnu
end_comment

begin_comment
comment|// CHECK-1: PointerWidth: 64
end_comment

end_unit

