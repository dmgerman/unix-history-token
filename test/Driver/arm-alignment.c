begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mstrict-align -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mno-unaligned-access -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED-AARCH64< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -mstrict-align -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED-AARCH64< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -mno-unaligned-access -munaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-UNALIGNED-AARCH64< %t %s
end_comment

begin_comment
comment|// CHECK-UNALIGNED-ARM: "-backend-option" "-arm-no-strict-align"
end_comment

begin_comment
comment|// CHECK-UNALIGNED-AARCH64: "-backend-option" "-aarch64-no-strict-align"
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mno-unaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mstrict-align -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -munaligned-access -mno-unaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -munaligned-access -mstrict-align -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED-ARM< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -mno-unaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED-AARCH64< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -mstrict-align -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED-AARCH64< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -munaligned-access -mno-unaligned-access -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED-AARCH64< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-gnueabi -munaligned-access -mstrict-align -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ALIGNED-AARCH64< %t %s
end_comment

begin_comment
comment|// CHECK-ALIGNED-ARM: "-backend-option" "-arm-strict-align"
end_comment

begin_comment
comment|// CHECK-ALIGNED-AARCH64: "-backend-option" "-aarch64-strict-align"
end_comment

end_unit

