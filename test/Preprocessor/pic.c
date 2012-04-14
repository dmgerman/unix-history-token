begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -dM -E -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: #define __PIC__
end_comment

begin_comment
comment|// CHECK-NOT: #define __PIE__
end_comment

begin_comment
comment|// CHECK-NOT: #define __pic__
end_comment

begin_comment
comment|// CHECK-NOT: #define __pie__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pic-level 1 -dM -E -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PIC1 %s
end_comment

begin_comment
comment|// CHECK-PIC1: #define __PIC__ 1
end_comment

begin_comment
comment|// CHECK-PIC1-NOT: #define __PIE__
end_comment

begin_comment
comment|// CHECK-PIC1: #define __pic__ 1
end_comment

begin_comment
comment|// CHECK-PIC1-NOT: #define __pie__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pic-level 2 -dM -E -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PIC2 %s
end_comment

begin_comment
comment|// CHECK-PIC2: #define __PIC__ 2
end_comment

begin_comment
comment|// CHECK-PIC2-NOT: #define __PIE__
end_comment

begin_comment
comment|// CHECK-PIC2: #define __pic__ 2
end_comment

begin_comment
comment|// CHECK-PIC2-NOT: #define __pie__
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pie-level 1 -dM -E -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PIE1 %s
end_comment

begin_comment
comment|// CHECK-PIE1-NOT: #define __PIC__
end_comment

begin_comment
comment|// CHECK-PIE1: #define __PIE__ 1
end_comment

begin_comment
comment|// CHECK-PIE1-NOT: #define __pic__
end_comment

begin_comment
comment|// CHECK-PIE1: #define __pie__ 1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pie-level 2 -dM -E -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PIE2 %s
end_comment

begin_comment
comment|// CHECK-PIE2-NOT: #define __PIC__
end_comment

begin_comment
comment|// CHECK-PIE2: #define __PIE__ 2
end_comment

begin_comment
comment|// CHECK-PIE2-NOT: #define __pic__
end_comment

begin_comment
comment|// CHECK-PIE2: #define __pie__ 2
end_comment

end_unit

