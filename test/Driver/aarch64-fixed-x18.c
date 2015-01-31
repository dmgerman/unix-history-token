begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target aarch64-none-gnu -ffixed-x18 -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-FIXED-X18< %t %s
end_comment

begin_comment
comment|// CHECK-FIXED-X18: "-backend-option" "-aarch64-reserve-x18"
end_comment

end_unit

