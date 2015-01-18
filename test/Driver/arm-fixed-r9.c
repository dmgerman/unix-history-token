begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -ffixed-r9 -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-FIXED-R9< %t %s
end_comment

begin_comment
comment|// CHECK-FIXED-R9: "-backend-option" "-arm-reserve-r9"
end_comment

end_unit

