begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mstrict-align -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mno-unaligned-access -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED< %t %s
end_comment

begin_comment
comment|// CHECK-UNALIGNED: "-backend-option" "-arm-no-strict-align"
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mno-unaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mstrict-align -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -munaligned-access -mno-unaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -munaligned-access -mstrict-align -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED< %t %s
end_comment

begin_comment
comment|// CHECK-ALIGNED: "-backend-option" "-arm-strict-align"
end_comment

end_unit

