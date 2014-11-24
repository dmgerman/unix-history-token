begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -x c -E -dM %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -x c -E -dM %s -o - | FileCheck %s
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
comment|// CHECK-NOT: __ARM_FEATURE_CRC32 1
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
comment|// CHECK: __ARM_NEON 1
end_comment

begin_comment
comment|// CHECK: __ARM_NEON_FP 0xe
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
comment|// RUN: %clang -target aarch64-none-linux-gnu -march=armv8-a+crypto -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-CRYPTO %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -march=armv8-a+crypto -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-CRYPTO %s
end_comment

begin_comment
comment|// CHECK-CRYPTO: __ARM_FEATURE_CRYPTO 1
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -mcrc -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-CRC32 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -mcrc -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-CRC32 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -march=armv8-a+crc -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-CRC32 %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -march=armv8-a+crc -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-CRC32 %s
end_comment

begin_comment
comment|// CHECK-CRC32: __ARM_FEATURE_CRC32 1
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -ffast-math -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-FASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -ffast-math -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-FASTMATH %s
end_comment

begin_comment
comment|// CHECK-FASTMATH: __ARM_FP_FAST 1
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -fshort-wchar -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-SHORTWCHAR %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -fshort-wchar -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-SHORTWCHAR %s
end_comment

begin_comment
comment|// CHECK-SHORTWCHAR: __ARM_SIZEOF_WCHAR_T 2
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -fshort-enums -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-SHORTENUMS %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -fshort-enums -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-SHORTENUMS %s
end_comment

begin_comment
comment|// CHECK-SHORTENUMS: __ARM_SIZEOF_MINIMAL_ENUM 1
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-none-linux-gnu -march=armv8-a+simd -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-NEON %s
end_comment

begin_comment
comment|// RUN: %clang -target arm64-none-linux-gnu -march=armv8-a+simd -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-NEON %s
end_comment

begin_comment
comment|// CHECK-NEON: __ARM_NEON 1
end_comment

begin_comment
comment|// CHECK-NEON: __ARM_NEON_FP 0xe
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=arm64 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-ARCH-NOT-ACCEPT %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=aarch64 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-ARCH-NOT-ACCEPT %s
end_comment

begin_comment
comment|// CHECK-ARCH-NOT-ACCEPT: error: the clang compiler does not support
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-GENERIC %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-GENERIC %s
end_comment

begin_comment
comment|// CHECK-GENERIC: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cyclone -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MTUNE-CYCLONE %s
end_comment

begin_comment
comment|// CHECK-MTUNE-CYCLONE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon" "-target-feature" "+zcm" "-target-feature" "+zcz"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cyclone -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-CYCLONE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-A53 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-A57 %s
end_comment

begin_comment
comment|// CHECK-MCPU-CYCLONE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon" "-target-feature" "+crc" "-target-feature" "+crypto" "-target-feature" "+zcm" "-target-feature" "+zcz"
end_comment

begin_comment
comment|// CHECK-MCPU-A53: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon" "-target-feature" "+crc" "-target-feature" "+crypto"
end_comment

begin_comment
comment|// CHECK-MCPU-A57: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon" "-target-feature" "+crc" "-target-feature" "+crypto"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a+fp+simd+crc+crypto -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MARCH-1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a+nofp+nosimd+nocrc+nocrypto+fp+simd+crc+crypto -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MARCH-1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a+nofp+nosimd+nocrc+nocrypto -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MARCH-2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a+fp+simd+crc+crypto+nofp+nosimd+nocrc+nocrypto -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MARCH-2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a+nosimd -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MARCH-3 %s
end_comment

begin_comment
comment|// CHECK-MARCH-1: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+fp-armv8" "-target-feature" "+neon" "-target-feature" "+crc" "-target-feature" "+crypto"
end_comment

begin_comment
comment|// CHECK-MARCH-2: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "-fp-armv8" "-target-feature" "-neon" "-target-feature" "-crc" "-target-feature" "-crypto"
end_comment

begin_comment
comment|// CHECK-MARCH-3: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "-neon"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cyclone+nocrypto -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cyclone+crypto+nocrypto -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-1 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=generic+crc -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=generic+nocrc+crc -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-2 %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a53+nosimd -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-3 %s
end_comment

begin_comment
comment|// CHECK-MCPU-1: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon" "-target-feature" "+crc" "-target-feature" "-crypto" "-target-feature" "+zcm" "-target-feature" "+zcz"
end_comment

begin_comment
comment|// CHECK-MCPU-2: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon" "-target-feature" "+crc"
end_comment

begin_comment
comment|// CHECK-MCPU-3: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "-neon"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cyclone+nocrc+nocrypto -march=armv8-a -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-MARCH %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a -mcpu=cyclone+nocrc+nocrypto  -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-MARCH %s
end_comment

begin_comment
comment|// CHECK-MCPU-MARCH: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon" "-target-feature" "+zcm" "-target-feature" "+zcz"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=cortex-a53 -mtune=cyclone -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-MTUNE %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mtune=cyclone -mcpu=cortex-a53  -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-MCPU-MTUNE %s
end_comment

begin_comment
comment|// CHECK-MCPU-MTUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-feature" "+neon" "-target-feature" "+crc" "-target-feature" "+crypto" "-target-feature" "+zcm" "-target-feature" "+zcz"
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=generic+neon -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-ERROR-NEON %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -mcpu=generic+noneon -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-ERROR-NEON %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a+neon -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-ERROR-NEON %s
end_comment

begin_comment
comment|// RUN: %clang -target aarch64 -march=armv8-a+noneon -### -c %s 2>&1 | FileCheck -check-prefix=CHECK-ERROR-NEON %s
end_comment

begin_comment
comment|// CHECK-ERROR-NEON: error: [no]neon is not accepted as modifier, please use [no]simd instead
end_comment

end_unit

