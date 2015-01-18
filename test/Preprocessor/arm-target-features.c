begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv8a-none-linux-gnu -x c -E -dM %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK: __ARM_ARCH 8
end_comment

begin_comment
comment|// CHECK: __ARM_ARCH_8A__ 1
end_comment

begin_comment
comment|// CHECK: __ARM_FEATURE_CRC32 1
end_comment

begin_comment
comment|// CHECK: __ARM_FEATURE_DIRECTED_ROUNDING 1
end_comment

begin_comment
comment|// CHECK: __ARM_FEATURE_NUMERIC_MAXMIN 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7a-none-linux-gnu -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-V7 %s
end_comment

begin_comment
comment|// CHECK-V7: __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK-V7: __ARM_ARCH 7
end_comment

begin_comment
comment|// CHECK-V7: __ARM_ARCH_7A__ 1
end_comment

begin_comment
comment|// CHECK-V7-NOT: __ARM_FEATURE_CRC32
end_comment

begin_comment
comment|// CHECK-V7-NOT: __ARM_FEATURE_NUMERIC_MAXMIN
end_comment

begin_comment
comment|// CHECK-V7-NOT: __ARM_FEATURE_DIRECTED_ROUNDING
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mfloat-abi=hard -x c -E -dM %s | FileCheck --check-prefix=CHECK-V8-BAREHF %s
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: __ARM_ARCH 8
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: __ARM_ARCH_8A__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: __ARM_FEATURE_CRC32 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: __ARM_FEATURE_DIRECTED_ROUNDING 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: __ARM_FEATURE_NUMERIC_MAXMIN 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: __ARM_NEON__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: __VFP_FP__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mfloat-abi=hard -mfpu=fp-armv8 -x c -E -dM %s | FileCheck --check-prefix=CHECK-V8-BAREHF-FP %s
end_comment

begin_comment
comment|// CHECK-V8-BAREHF-FP-NOT: __ARM_NEON__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF-FP: __VFP_FP__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mfloat-abi=hard -mfpu=neon-fp-armv8 -x c -E -dM %s | FileCheck --check-prefix=CHECK-V8-BAREHF-NEON-FP %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mfloat-abi=hard -mfpu=crypto-neon-fp-armv8 -x c -E -dM %s | FileCheck --check-prefix=CHECK-V8-BAREHF-NEON-FP %s
end_comment

begin_comment
comment|// CHECK-V8-BAREHF-NEON-FP: __ARM_NEON__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF-NEON-FP: __VFP_FP__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mnocrc -x c -E -dM %s | FileCheck --check-prefix=CHECK-V8-NOCRC %s
end_comment

begin_comment
comment|// CHECK-V8-NOCRC-NOT: __ARM_FEATURE_CRC32 1
end_comment

begin_comment
comment|// Check that -mhwdiv works properly for armv8/thumbv8 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -x c -E -dM %s -o - | FileCheck --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// ARMV8:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -x c -E -dM %s -o - | FileCheck --check-prefix=THUMBV8 %s
end_comment

begin_comment
comment|// THUMBV8:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8-eabi -x c -E -dM %s -o - | FileCheck --check-prefix=ARMV8-EABI %s
end_comment

begin_comment
comment|// ARMV8-EABI:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8-eabi -mthumb -x c -E -dM %s -o - | FileCheck --check-prefix=THUMBV8-EABI %s
end_comment

begin_comment
comment|// THUMBV8-EABI:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mhwdiv=none -x c -E -dM %s -o - | FileCheck --check-prefix=NONEHWDIV-ARMV8 %s
end_comment

begin_comment
comment|// NONEHWDIV-ARMV8-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mhwdiv=none -x c -E -dM %s -o - | FileCheck --check-prefix=NONEHWDIV-THUMBV8 %s
end_comment

begin_comment
comment|// NONEHWDIV-THUMBV8-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mhwdiv=thumb -x c -E -dM %s -o - | FileCheck --check-prefix=THUMBHWDIV-ARMV8 %s
end_comment

begin_comment
comment|// THUMBHWDIV-ARMV8-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mhwdiv=arm -x c -E -dM %s -o - | FileCheck --check-prefix=ARMHWDIV-THUMBV8 %s
end_comment

begin_comment
comment|// ARMHWDIV-THUMBV8-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -x c -E -dM %s -o - | FileCheck --check-prefix=ARMV8A %s
end_comment

begin_comment
comment|// ARMV8A:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mthumb -x c -E -dM %s -o - | FileCheck --check-prefix=THUMBV8A %s
end_comment

begin_comment
comment|// THUMBV8A:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-eabi -x c -E -dM %s -o - | FileCheck --check-prefix=ARMV8A-EABI %s
end_comment

begin_comment
comment|// ARMV8A-EABI:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-eabi -x c -E -dM %s -o - | FileCheck --check-prefix=THUMBV8A-EABI %s
end_comment

begin_comment
comment|// THUMBV8A-EABI:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-DEFS %s
end_comment

begin_comment
comment|// CHECK-DEFS:#define __ARM_SIZEOF_MINIMAL_ENUM 4
end_comment

begin_comment
comment|// CHECK-DEFS:#define __ARM_SIZEOF_WCHAR_T 4
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -fshort-wchar -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-SHORTWCHAR %s
end_comment

begin_comment
comment|// CHECK-SHORTWCHAR:#define __ARM_SIZEOF_WCHAR_T 2
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -fshort-enums -x c -E -dM %s -o - | FileCheck --check-prefix=CHECK-SHORTENUMS %s
end_comment

begin_comment
comment|// CHECK-SHORTENUMS:#define __ARM_SIZEOF_MINIMAL_ENUM 1
end_comment

begin_comment
comment|// Test that -mhwdiv has the right effect for a target CPU which has hwdiv enabled by default.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a15 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTHWDIV-ARM %s
end_comment

begin_comment
comment|// DEFAULTHWDIV-ARM:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a15 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTHWDIV-THUMB %s
end_comment

begin_comment
comment|// DEFAULTHWDIV-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a15 -mhwdiv=arm -x c -E -dM %s -o - | FileCheck --check-prefix=ARMHWDIV-ARM %s
end_comment

begin_comment
comment|// ARMHWDIV-ARM:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a15 -mhwdiv=thumb -x c -E -dM %s -o - | FileCheck --check-prefix=THUMBHWDIV-THUMB %s
end_comment

begin_comment
comment|// THUMBHWDIV-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a15 -mhwdiv=thumb -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTHWDIV-THUMBHWDIV-ARM %s
end_comment

begin_comment
comment|// DEFAULTHWDIV-THUMBHWDIV-ARM-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -mcpu=cortex-a15 -mhwdiv=arm -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTHWDIV-ARMHWDIV-THUMB %s
end_comment

begin_comment
comment|// DEFAULTHWDIV-ARMHWDIV-THUMB-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a15 -mhwdiv=none -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTHWDIV-NONEHWDIV-ARM %s
end_comment

begin_comment
comment|// DEFAULTHWDIV-NONEHWDIV-ARM-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -mcpu=cortex-a15 -mhwdiv=none -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTHWDIV-NONEHWDIV-THUMB %s
end_comment

begin_comment
comment|// DEFAULTHWDIV-NONEHWDIV-THUMB-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// Check that -mfpu works properly for Cortex-A7 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a7 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTFPU-A7 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a7 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTFPU-A7 %s
end_comment

begin_comment
comment|// DEFAULTFPU-A7:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// DEFAULTFPU-A7:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a7 -mfpu=none -x c -E -dM %s -o - | FileCheck --check-prefix=FPUNONE-A7 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a7 -mfpu=none -x c -E -dM %s -o - | FileCheck --check-prefix=FPUNONE-A7 %s
end_comment

begin_comment
comment|// FPUNONE-A7-NOT:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// FPUNONE-A7-NOT:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a7 -mfpu=vfp4 -x c -E -dM %s -o - | FileCheck --check-prefix=NONEON-A7 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a7 -mfpu=vfp4 -x c -E -dM %s -o - | FileCheck --check-prefix=NONEON-A7 %s
end_comment

begin_comment
comment|// NONEON-A7-NOT:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// NONEON-A7:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// Check that -mfpu works properly for Cortex-A5 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTFPU-A5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTFPU-A5 %s
end_comment

begin_comment
comment|// DEFAULTFPU-A5:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// DEFAULTFPU-A5:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a5 -mfpu=none -x c -E -dM %s -o - | FileCheck --check-prefix=FPUNONE-A5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a5 -mfpu=none -x c -E -dM %s -o - | FileCheck --check-prefix=FPUNONE-A5 %s
end_comment

begin_comment
comment|// FPUNONE-A5-NOT:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// FPUNONE-A5-NOT:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a5 -mfpu=vfp3-d16 -x c -E -dM %s -o - | FileCheck --check-prefix=NONEON-A5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a5 -mfpu=vfp3-d16 -x c -E -dM %s -o - | FileCheck --check-prefix=NONEON-A5 %s
end_comment

begin_comment
comment|// NONEON-A5-NOT:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// NONEON-A5:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// FIXME: add check for further predefines
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting ep9312.
end_comment

begin_comment
comment|// RUN: %clang -target armv4t -mcpu=ep9312 -x c -E -dM %s -o - | FileCheck --check-prefix=A4T %s
end_comment

begin_comment
comment|// A4T-NOT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting arm10tdmi.
end_comment

begin_comment
comment|// RUN: %clang -target armv5 -mcpu=arm10tdmi -x c -E -dM %s -o - | FileCheck --check-prefix=A5T %s
end_comment

begin_comment
comment|// A5T-NOT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a5.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck --check-prefix=A5-ARM %s
end_comment

begin_comment
comment|// A5-ARM-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A5-ARM:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck --check-prefix=A5-THUMB %s
end_comment

begin_comment
comment|// A5-THUMB-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A5-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck --check-prefix=A5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck --check-prefix=A5 %s
end_comment

begin_comment
comment|// A5:#define __ARM_ARCH 7
end_comment

begin_comment
comment|// A5:#define __ARM_ARCH_7A__ 1
end_comment

begin_comment
comment|// A5:#define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// A5-NOT: #define __ARM_FEATURE_NUMERIC_MAXMIN
end_comment

begin_comment
comment|// A5-NOT: #define __ARM_FEATURE_DIRECTED_ROUNDING
end_comment

begin_comment
comment|// A5:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a7.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a7 -x c -E -dM %s -o - | FileCheck --check-prefix=A7 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a7 -x c -E -dM %s -o - | FileCheck --check-prefix=A7 %s
end_comment

begin_comment
comment|// A7:#define __ARM_ARCH 7
end_comment

begin_comment
comment|// A7:#define __ARM_ARCH_7A__ 1
end_comment

begin_comment
comment|// A7:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A7:#define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// A7:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a8.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a8 -x c -E -dM %s -o - | FileCheck --check-prefix=A8-ARM %s
end_comment

begin_comment
comment|// A8-ARM-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A8-ARM:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a8 -x c -E -dM %s -o - | FileCheck --check-prefix=A8-THUMB %s
end_comment

begin_comment
comment|// A8-THUMB-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A8-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a9.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a9 -x c -E -dM %s -o - | FileCheck --check-prefix=A9-ARM %s
end_comment

begin_comment
comment|// A9-ARM-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A9-ARM:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a9 -x c -E -dM %s -o - | FileCheck --check-prefix=A9-THUMB %s
end_comment

begin_comment
comment|// A9-THUMB-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A9-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Check that -mfpu works properly for Cortex-A12 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a12 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTFPU-A12 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a12 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTFPU-A12 %s
end_comment

begin_comment
comment|// DEFAULTFPU-A12:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// DEFAULTFPU-A12:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a12 -mfpu=none -x c -E -dM %s -o - | FileCheck --check-prefix=FPUNONE-A12 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a12 -mfpu=none -x c -E -dM %s -o - | FileCheck --check-prefix=FPUNONE-A12 %s
end_comment

begin_comment
comment|// FPUNONE-A12-NOT:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// FPUNONE-A12-NOT:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a12.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a12 -x c -E -dM %s -o - | FileCheck --check-prefix=A12 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a12 -x c -E -dM %s -o - | FileCheck --check-prefix=A12 %s
end_comment

begin_comment
comment|// A12:#define __ARM_ARCH 7
end_comment

begin_comment
comment|// A12:#define __ARM_ARCH_7A__ 1
end_comment

begin_comment
comment|// A12:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A12:#define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// A12:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a15.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a15 -x c -E -dM %s -o - | FileCheck --check-prefix=A15-ARM %s
end_comment

begin_comment
comment|// A15-ARM:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A15-ARM:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a15 -x c -E -dM %s -o - | FileCheck --check-prefix=A15-THUMB %s
end_comment

begin_comment
comment|// A15-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A15-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Check that -mfpu works properly for Cortex-A17 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a17 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTFPU-A17 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a17 -x c -E -dM %s -o - | FileCheck --check-prefix=DEFAULTFPU-A17 %s
end_comment

begin_comment
comment|// DEFAULTFPU-A17:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// DEFAULTFPU-A17:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a17 -mfpu=none -x c -E -dM %s -o - | FileCheck --check-prefix=FPUNONE-A17 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a17 -mfpu=none -x c -E -dM %s -o - | FileCheck --check-prefix=FPUNONE-A17 %s
end_comment

begin_comment
comment|// FPUNONE-A17-NOT:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// FPUNONE-A17-NOT:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a17.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a17 -x c -E -dM %s -o - | FileCheck --check-prefix=A17 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a17 -x c -E -dM %s -o - | FileCheck --check-prefix=A17 %s
end_comment

begin_comment
comment|// A17:#define __ARM_ARCH 7
end_comment

begin_comment
comment|// A17:#define __ARM_ARCH_7A__ 1
end_comment

begin_comment
comment|// A17:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A17:#define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// A17:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting swift.
end_comment

begin_comment
comment|// RUN: %clang -target armv7s -mcpu=swift -x c -E -dM %s -o - | FileCheck --check-prefix=SWIFT-ARM %s
end_comment

begin_comment
comment|// SWIFT-ARM:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// SWIFT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// RUN: %clang -target armv7s -mthumb -mcpu=swift -x c -E -dM %s -o - | FileCheck --check-prefix=SWIFT-THUMB %s
end_comment

begin_comment
comment|// SWIFT-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// SWIFT-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a53.
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mcpu=cortex-a53 -x c -E -dM %s -o - | FileCheck --check-prefix=A53-ARM %s
end_comment

begin_comment
comment|// A53-ARM:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A53-ARM:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mcpu=cortex-a53 -x c -E -dM %s -o - | FileCheck --check-prefix=A53-THUMB %s
end_comment

begin_comment
comment|// A53-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A53-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-r5.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-r5 -x c -E -dM %s -o - | FileCheck --check-prefix=R5-ARM %s
end_comment

begin_comment
comment|// R5-ARM:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// R5-ARM:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-r5 -x c -E -dM %s -o - | FileCheck --check-prefix=R5-THUMB %s
end_comment

begin_comment
comment|// R5-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// R5-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-m0.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m0 -x c -E -dM %s -o - | FileCheck --check-prefix=M0-THUMB %s
end_comment

begin_comment
comment|// M0-THUMB-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// M0-THUMB-NOT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-m3.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m3 -x c -E -dM %s -o - | FileCheck --check-prefix=M3-THUMB %s
end_comment

begin_comment
comment|// M3-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// M3-THUMB-NOT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-m4.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m4 -x c -E -dM %s -o - | FileCheck --check-prefix=M4-THUMB %s
end_comment

begin_comment
comment|// M4-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// M4-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-m7.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m7 -x c -E -dM %s -o - | FileCheck --check-prefix=M7-THUMB %s
end_comment

begin_comment
comment|// M7-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// M7-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting krait.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=krait -x c -E -dM %s -o - | FileCheck --check-prefix=KRAIT-ARM %s
end_comment

begin_comment
comment|// KRAIT-ARM:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// KRAIT-ARM:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// KRAIT-ARM:#define  __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=krait -x c -E -dM %s -o - | FileCheck --check-prefix=KRAIT-THUMB %s
end_comment

begin_comment
comment|// KRAIT-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// KRAIT-THUMB:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// KRAIT-THUMB:#define  __ARM_VFPV4__ 1
end_comment

end_unit

