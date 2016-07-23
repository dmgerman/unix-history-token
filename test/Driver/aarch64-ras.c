begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target aarch64-none-none-eabi -march=armv8a+ras -### -c %s 2>&1 | FileCheck --check-prefix=CHECK-RAS %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-none-eabi -mcpu=generic+ras -### -c %s 2>&1 | FileCheck --check-prefix=CHECK-RAS %s
end_comment

begin_comment
comment|// CHECK-RAS: "-target-feature" "+ras"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-none-eabi -march=armv8a+noras -### -c %s 2>&1 | FileCheck --check-prefix=CHECK-NORAS %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-none-eabi -mcpu=generic+noras -### -c %s 2>&1 | FileCheck --check-prefix=CHECK-NORAS %s
end_comment

begin_comment
comment|// CHECK-NORAS: "-target-feature" "-ras"
end_comment

end_unit

