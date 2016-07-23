begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple hexagon-unknown-elf -target-cpu hexagonv5 %s | FileCheck %s -check-prefix CHECK-V5
end_comment

begin_comment
comment|// CHECK-V5: #define __HEXAGON_ARCH__ 5
end_comment

begin_comment
comment|// CHECK-V5: #define __HEXAGON_V5__ 1
end_comment

begin_comment
comment|// CHECK-V5: #define __hexagon__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple hexagon-unknown-elf -target-cpu hexagonv55 %s | FileCheck %s -check-prefix CHECK-V55
end_comment

begin_comment
comment|// CHECK-V55: #define __HEXAGON_ARCH__ 55
end_comment

begin_comment
comment|// CHECK-V55: #define __HEXAGON_V55__ 1
end_comment

begin_comment
comment|// CHECK-V55: #define __hexagon__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple hexagon-unknown-elf -target-cpu hexagonv60 %s | FileCheck %s -check-prefix CHECK-V60
end_comment

begin_comment
comment|// CHECK-V60: #define __HEXAGON_ARCH__ 60
end_comment

begin_comment
comment|// CHECK-V60: #define __HEXAGON_V60__ 1
end_comment

begin_comment
comment|// CHECK-V60: #define __hexagon__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple hexagon-unknown-elf -target-cpu hexagonv60 -target-feature +hvx %s | FileCheck %s -check-prefix CHECK-V60HVX
end_comment

begin_comment
comment|// CHECK-V60HVX: #define __HEXAGON_ARCH__ 60
end_comment

begin_comment
comment|// CHECK-V60HVX: #define __HEXAGON_V60__ 1
end_comment

begin_comment
comment|// CHECK-V60HVX: #define __HVX__ 1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -dM -triple hexagon-unknown-elf -target-cpu hexagonv60 -target-feature +hvx-double  %s | FileCheck %s -check-prefix CHECK-V60HVXD
end_comment

begin_comment
comment|// CHECK-V60HVXD: #define __HEXAGON_ARCH__ 60
end_comment

begin_comment
comment|// CHECK-V60HVXD: #define __HEXAGON_V60__ 1
end_comment

begin_comment
comment|// CHECK-V60HVXD: #define __HVXDBL__ 1
end_comment

begin_comment
comment|// CHECK-V60HVXD: #define __HVX__ 1
end_comment

begin_comment
comment|// CHECK-V60HVXD: #define __hexagon__ 1
end_comment

end_unit

