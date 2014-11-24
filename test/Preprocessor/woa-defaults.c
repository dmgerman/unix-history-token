begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -dM -triple armv7-windows -E %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -dM -fno-signed-char -triple armv7-windows -E %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s -check-prefix CHECK-UNSIGNED-CHAR
end_comment

begin_comment
comment|// CHECK: #define _INTEGRAL_MAX_BITS 64
end_comment

begin_comment
comment|// CHECK: #define _M_ARM 7
end_comment

begin_comment
comment|// CHECK: #define _M_ARMT _M_ARM
end_comment

begin_comment
comment|// CHECK: #define _M_ARM_FP 31
end_comment

begin_comment
comment|// CHECK: #define _M_ARM_NT 1
end_comment

begin_comment
comment|// CHECK: #define _M_THUMB _M_ARM
end_comment

begin_comment
comment|// CHECK: #define _WIN32 1
end_comment

begin_comment
comment|// CHECK: #define __ARM_PCS 1
end_comment

begin_comment
comment|// CHECK: #define __ARM_PCS_VFP 1
end_comment

begin_comment
comment|// CHECK: #define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_DOUBLE__ 8
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_FLOAT__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_INT__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_LONG_DOUBLE__ 8
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_LONG_LONG__ 8
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_LONG__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_POINTER__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_PTRDIFF_T__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_SHORT__ 2
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_SIZE_T__ 4
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_WCHAR_T__ 2
end_comment

begin_comment
comment|// CHECK: #define __SIZEOF_WINT_T__ 4
end_comment

begin_comment
comment|// CHECK-NOT: __THUMB_INTERWORK__
end_comment

begin_comment
comment|// CHECK-NOT: __ARM_EABI__
end_comment

begin_comment
comment|// CHECK-NOT: _CHAR_UNSIGNED
end_comment

begin_comment
comment|// CHECK-UNSIGNED-CHAR: #define _CHAR_UNSIGNED 1
end_comment

end_unit

