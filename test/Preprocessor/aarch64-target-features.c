begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -x c -E -dM %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: __AARCH64EL__ 1
end_comment

begin_comment
comment|// CHECK: __ARM_64BIT_STATE 1
end_comment

begin_comment
comment|// CHECK: __ARM_ACLE 200
end_comment

begin_comment
comment|// CHECK: __ARM_ALIGN_MAX_STACK_PWR 4
end_comment

begin_comment
comment|// CHECK: __ARM_ARCH 8
end_comment

begin_comment
comment|// CHECK: __ARM_ARCH_ISA_A64 1
end_comment

begin_comment
comment|// CHECK: __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// CHECK-NOT: __ARM_FEATURE_BIG_ENDIAN
end_comment

begin_comment
comment|// CHECK: __ARM_FEATURE_CLZ 1
end_comment

begin_comment
comment|// CHECK-NOT: __ARM_FEATURE_CRYPTO 1
end_comment

begin_comment
comment|// CHECK: __ARM_FEATURE_DIV 1
end_comment

begin_comment
comment|// CHECK: __ARM_FEATURE_FMA 1
end_comment

begin_comment
comment|// CHECK: __ARM_FEATURE_UNALIGNED 1
end_comment

begin_comment
comment|// CHECK: __ARM_FP 0xe
end_comment

begin_comment
comment|// CHECK: __ARM_FP16_FORMAT_IEEE 1
end_comment

begin_comment
comment|// CHECK-NOT: __ARM_FP_FAST 1
end_comment

begin_comment
comment|// CHECK: __ARM_FP_FENV_ROUNDING 1
end_comment

begin_comment
comment|// CHECK-NOT: __ARM_NEON 1
end_comment

begin_comment
comment|// CHECK-NOT: __ARM_NEON_FP 7
end_comment

begin_comment
comment|// CHECK: __ARM_PCS_AAPCS64 1
end_comment

begin_comment
comment|// CHECK-NOT: __ARM_SIZEOF_MINIMAL_ENUM 1
end_comment

begin_comment
comment|// CHECK-NOT: __ARM_SIZEOF_WCHAR_T 2
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -mfpu=crypto-neon-fp-armv8 -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-CRYPTO %s
end_comment

begin_comment
comment|// CHECK-CRYPTO: __ARM_FEATURE_CRYPTO 1
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -ffast-math -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-FASTMATH %s
end_comment

begin_comment
comment|// CHECK-FASTMATH: __ARM_FP_FAST 1
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -fshort-wchar -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-SHORTWCHAR %s
end_comment

begin_comment
comment|// CHECK-SHORTWCHAR: __ARM_SIZEOF_WCHAR_T 2
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -fshort-enums -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-SHORTENUMS %s
end_comment

begin_comment
comment|// CHECK-SHORTENUMS: __ARM_SIZEOF_MINIMAL_ENUM 1
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -mfpu=neon -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-NEON %s
end_comment

begin_comment
comment|// CHECK-NEON: __ARM_NEON 1
end_comment

begin_comment
comment|// CHECK-NEON: __ARM_NEON_FP 7
end_comment

end_unit

