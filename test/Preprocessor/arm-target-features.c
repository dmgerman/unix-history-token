begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv8a-none-linux-gnu -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-V8A %s
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARM_ARCH_8A__ 1
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARM_FEATURE_CRC32 1
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARM_FEATURE_DIRECTED_ROUNDING 1
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARM_FEATURE_NUMERIC_MAXMIN 1
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARM_FP16_ARGS 1
end_comment

begin_comment
comment|// CHECK-V8A: #define __ARM_FP16_FORMAT_IEEE 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8r-none-linux-gnu -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-V8R %s
end_comment

begin_comment
comment|// CHECK-V8R: #define __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK-V8R: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// CHECK-V8R: #define __ARM_ARCH_8R__ 1
end_comment

begin_comment
comment|// CHECK-V8R: #define __ARM_FEATURE_CRC32 1
end_comment

begin_comment
comment|// CHECK-V8R: #define __ARM_FEATURE_DIRECTED_ROUNDING 1
end_comment

begin_comment
comment|// CHECK-V8R: #define __ARM_FEATURE_NUMERIC_MAXMIN 1
end_comment

begin_comment
comment|// CHECK-V8R: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// RUN: %clang -target armv7a-none-linux-gnu -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-V7 %s
end_comment

begin_comment
comment|// CHECK-V7: #define __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK-V7: #define __ARM_ARCH 7
end_comment

begin_comment
comment|// CHECK-V7: #define __ARM_ARCH_7A__ 1
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
comment|// CHECK-V7: #define __ARM_FP 0xC
end_comment

begin_comment
comment|// RUN: %clang -target armv7ve-none-linux-gnu -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-V7VE %s
end_comment

begin_comment
comment|// CHECK-V7VE: #define __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK-V7VE: #define __ARM_ARCH 7
end_comment

begin_comment
comment|// CHECK-V7VE: #define __ARM_ARCH_7VE__ 1
end_comment

begin_comment
comment|// CHECK-V7VE: #define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// CHECK-V7VE: #define __ARM_FP 0xC
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx10.10 -arch armv7s -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-V7S %s
end_comment

begin_comment
comment|// CHECK-V7S: #define __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK-V7S: #define __ARM_ARCH 7
end_comment

begin_comment
comment|// CHECK-V7S: #define __ARM_ARCH_7S__ 1
end_comment

begin_comment
comment|// CHECK-V7S-NOT: __ARM_FEATURE_CRC32
end_comment

begin_comment
comment|// CHECK-V7S-NOT: __ARM_FEATURE_NUMERIC_MAXMIN
end_comment

begin_comment
comment|// CHECK-V7S-NOT: __ARM_FEATURE_DIRECTED_ROUNDING
end_comment

begin_comment
comment|// CHECK-V7S: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mfloat-abi=hard -x c -E -dM %s | FileCheck -match-full-lines --check-prefix=CHECK-V8-BAREHF %s
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __ARMEL__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __ARM_ARCH_8A__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __ARM_FEATURE_CRC32 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __ARM_FEATURE_DIRECTED_ROUNDING 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __ARM_FEATURE_NUMERIC_MAXMIN 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHP: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __ARM_NEON__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __ARM_PCS_VFP 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF: #define __VFP_FP__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mfloat-abi=hard -mfpu=fp-armv8 -x c -E -dM %s | FileCheck -match-full-lines --check-prefix=CHECK-V8-BAREHF-FP %s
end_comment

begin_comment
comment|// CHECK-V8-BAREHF-FP-NOT: __ARM_NEON__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHP-FP: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// CHECK-V8-BAREHF-FP: #define __VFP_FP__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mfloat-abi=hard -mfpu=neon-fp-armv8 -x c -E -dM %s | FileCheck -match-full-lines --check-prefix=CHECK-V8-BAREHF-NEON-FP %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mfloat-abi=hard -mfpu=crypto-neon-fp-armv8 -x c -E -dM %s | FileCheck -match-full-lines --check-prefix=CHECK-V8-BAREHF-NEON-FP %s
end_comment

begin_comment
comment|// CHECK-V8-BAREHP-NEON-FP: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// CHECK-V8-BAREHF-NEON-FP: #define __ARM_NEON__ 1
end_comment

begin_comment
comment|// CHECK-V8-BAREHF-NEON-FP: #define __VFP_FP__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mnocrc -x c -E -dM %s | FileCheck -match-full-lines --check-prefix=CHECK-V8-NOCRC %s
end_comment

begin_comment
comment|// CHECK-V8-NOCRC-NOT: __ARM_FEATURE_CRC32 1
end_comment

begin_comment
comment|// Check that -mhwdiv works properly for armv8/thumbv8 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8-eabi -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8-eabi -mthumb -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8 %s
end_comment

begin_comment
comment|// V8:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mhwdiv=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NOHWDIV-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mhwdiv=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NOHWDIV-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mhwdiv=thumb -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NOHWDIV-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mhwdiv=arm -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NOHWDIV-V8 %s
end_comment

begin_comment
comment|// NOHWDIV-V8-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a -mthumb -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-eabi -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8A %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-eabi -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8A %s
end_comment

begin_comment
comment|// V8A:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// V8A:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.base-none-linux-gnu -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8M_BASELINE %s
end_comment

begin_comment
comment|// V8M_BASELINE: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// V8M_BASELINE: #define __ARM_ARCH_8M_BASE__ 1
end_comment

begin_comment
comment|// V8M_BASELINE: #define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// V8M_BASELINE-NOT: __ARM_ARCH_ISA_ARM
end_comment

begin_comment
comment|// V8M_BASELINE: #define __ARM_ARCH_ISA_THUMB 1
end_comment

begin_comment
comment|// V8M_BASELINE: #define __ARM_ARCH_PROFILE 'M'
end_comment

begin_comment
comment|// V8M_BASELINE-NOT: __ARM_FEATURE_CRC32
end_comment

begin_comment
comment|// V8M_BASELINE-NOT: __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// V8M_BASELINE-NOT: __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// V8M_BASELINE-NOT: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1
end_comment

begin_comment
comment|// RUN: %clang -target armv8m.main-none-linux-gnu -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8M_MAINLINE %s
end_comment

begin_comment
comment|// V8M_MAINLINE: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// V8M_MAINLINE: #define __ARM_ARCH_8M_MAIN__ 1
end_comment

begin_comment
comment|// V8M_MAINLINE: #define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// V8M_MAINLINE-NOT: __ARM_ARCH_ISA_ARM
end_comment

begin_comment
comment|// V8M_MAINLINE: #define __ARM_ARCH_ISA_THUMB 2
end_comment

begin_comment
comment|// V8M_MAINLINE: #define __ARM_ARCH_PROFILE 'M'
end_comment

begin_comment
comment|// V8M_MAINLINE-NOT: __ARM_FEATURE_CRC32
end_comment

begin_comment
comment|// V8M_MAINLINE-NOT: __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// V8M_MAINLINE: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// V8M_MAINLINE: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -march=armv8-m.main+dsp -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=V8M_MAINLINE_DSP %s
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP: #define __ARM_ARCH_8M_MAIN__ 1
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP: #define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP-NOT: __ARM_ARCH_ISA_ARM
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP: #define __ARM_ARCH_ISA_THUMB 2
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP: #define __ARM_ARCH_PROFILE 'M'
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP-NOT: __ARM_FEATURE_CRC32
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP: #define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// V8M_MAINLINE_DSP: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-DEFS %s
end_comment

begin_comment
comment|// CHECK-DEFS:#define __ARM_PCS 1
end_comment

begin_comment
comment|// CHECK-DEFS:#define __ARM_SIZEOF_MINIMAL_ENUM 4
end_comment

begin_comment
comment|// CHECK-DEFS:#define __ARM_SIZEOF_WCHAR_T 4
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -fno-math-errno -fno-signed-zeros\
end_comment

begin_comment
comment|// RUN:        -fno-trapping-math -fassociative-math -freciprocal-math\
end_comment

begin_comment
comment|// RUN:        -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-FASTMATH %s
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -ffast-math -x c -E -dM %s -o -\
end_comment

begin_comment
comment|// RUN:        | FileCheck -match-full-lines --check-prefix=CHECK-FASTMATH %s
end_comment

begin_comment
comment|// CHECK-FASTMATH: #define __ARM_FP_FAST 1
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -fshort-wchar -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-SHORTWCHAR %s
end_comment

begin_comment
comment|// CHECK-SHORTWCHAR:#define __ARM_SIZEOF_WCHAR_T 2
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnu -fshort-enums -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-SHORTENUMS %s
end_comment

begin_comment
comment|// CHECK-SHORTENUMS:#define __ARM_SIZEOF_MINIMAL_ENUM 1
end_comment

begin_comment
comment|// Test that -mhwdiv has the right effect for a target CPU which has hwdiv enabled by default.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a15 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=HWDIV %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a15 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=HWDIV %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a15 -mhwdiv=arm -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=HWDIV %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a15 -mhwdiv=thumb -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=HWDIV %s
end_comment

begin_comment
comment|// HWDIV:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a15 -mhwdiv=thumb -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NOHWDIV %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -mcpu=cortex-a15 -mhwdiv=arm -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NOHWDIV %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-a15 -mhwdiv=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NOHWDIV %s
end_comment

begin_comment
comment|// RUN: %clang -target arm -mthumb -mcpu=cortex-a15 -mhwdiv=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NOHWDIV %s
end_comment

begin_comment
comment|// NOHWDIV-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// Check that -mfpu works properly for Cortex-A7 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a7 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=DEFAULTFPU-A7 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a7 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=DEFAULTFPU-A7 %s
end_comment

begin_comment
comment|// DEFAULTFPU-A7:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// DEFAULTFPU-A7:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// DEFAULTFPU-A7:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a7 -mfpu=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=FPUNONE-A7 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a7 -mfpu=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=FPUNONE-A7 %s
end_comment

begin_comment
comment|// FPUNONE-A7-NOT:#define __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// FPUNONE-A7-NOT:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// FPUNONE-A7-NOT:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a7 -mfpu=vfp4 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NONEON-A7 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a7 -mfpu=vfp4 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NONEON-A7 %s
end_comment

begin_comment
comment|// NONEON-A7:#define __ARM_FP 0xE
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
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=DEFAULTFPU-A5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=DEFAULTFPU-A5 %s
end_comment

begin_comment
comment|// DEFAULTFPU-A5:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// DEFAULTFPU-A5:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// DEFAULTFPU-A5:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a5 -mfpu=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=FPUNONE-A5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a5 -mfpu=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=FPUNONE-A5 %s
end_comment

begin_comment
comment|// FPUNONE-A5-NOT:#define __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// FPUNONE-A5-NOT:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// FPUNONE-A5-NOT:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a5 -mfpu=vfp4-d16 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NONEON-A5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a5 -mfpu=vfp4-d16 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=NONEON-A5 %s
end_comment

begin_comment
comment|// NONEON-A5:#define __ARM_FP 0xE
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
comment|// RUN: %clang -target armv4t -mcpu=ep9312 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A4T %s
end_comment

begin_comment
comment|// A4T-NOT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// A4T-NOT:#define __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting arm10tdmi.
end_comment

begin_comment
comment|// RUN: %clang -target armv5 -mcpu=arm10tdmi -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A5T %s
end_comment

begin_comment
comment|// A5T-NOT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// A5T-NOT:#define __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a5.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a5 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A5 %s
end_comment

begin_comment
comment|// A5:#define __ARM_ARCH 7
end_comment

begin_comment
comment|// A5:#define __ARM_ARCH_7A__ 1
end_comment

begin_comment
comment|// A5-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A5:#define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// A5-NOT: #define __ARM_FEATURE_DIRECTED_ROUNDING
end_comment

begin_comment
comment|// A5:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// A5-NOT: #define __ARM_FEATURE_NUMERIC_MAXMIN
end_comment

begin_comment
comment|// A5:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a7.
end_comment

begin_comment
comment|// RUN: %clang -target armv7k -mcpu=cortex-a7 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A7 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7k -mthumb -mcpu=cortex-a7 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A7 %s
end_comment

begin_comment
comment|// A7:#define __ARM_ARCH 7
end_comment

begin_comment
comment|// A7:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A7:#define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// A7:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// A7:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a7.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -arch armv7k -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV7K %s
end_comment

begin_comment
comment|// ARMV7K:#define __ARM_ARCH 7
end_comment

begin_comment
comment|// ARMV7K:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// ARMV7K:#define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// ARMV7K:#define __ARM_DWARF_EH__ 1
end_comment

begin_comment
comment|// ARMV7K:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// ARMV7K:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// ARMV7K:#define __ARM_PCS_VFP 1
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a8.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a8 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a8 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A8 %s
end_comment

begin_comment
comment|// A8-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A8:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// A8:#define __ARM_FP 0xC
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a9.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a9 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A9 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a9 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A9 %s
end_comment

begin_comment
comment|// A9-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// A9:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// A9:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Check that -mfpu works properly for Cortex-A12 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a12 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=DEFAULTFPU-A12 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a12 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=DEFAULTFPU-A12 %s
end_comment

begin_comment
comment|// DEFAULTFPU-A12:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// DEFAULTFPU-A12:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// DEFAULTFPU-A12:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a12 -mfpu=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=FPUNONE-A12 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a12 -mfpu=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=FPUNONE-A12 %s
end_comment

begin_comment
comment|// FPUNONE-A12-NOT:#define __ARM_FP 0x{{.*}}
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
comment|// RUN: %clang -target armv7 -mcpu=cortex-a12 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A12 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a12 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A12 %s
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
comment|// A12:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// A12:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-a15.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-a15 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A15 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a15 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A15 %s
end_comment

begin_comment
comment|// A15:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// A15:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// A15:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Check that -mfpu works properly for Cortex-A17 (enabled by default).
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a17 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=DEFAULTFPU-A17 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a17 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=DEFAULTFPU-A17 %s
end_comment

begin_comment
comment|// DEFAULTFPU-A17:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// DEFAULTFPU-A17:#define __ARM_NEON__ 1
end_comment

begin_comment
comment|// DEFAULTFPU-A17:#define __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a17 -mfpu=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=FPUNONE-A17 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-none-linux-gnueabi -mthumb -mcpu=cortex-a17 -mfpu=none -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=FPUNONE-A17 %s
end_comment

begin_comment
comment|// FPUNONE-A17-NOT:#define __ARM_FP 0x{{.*}}
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
comment|// RUN: %clang -target armv7 -mcpu=cortex-a17 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A17 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-a17 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=A17 %s
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
comment|// A17:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// A17:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting swift.
end_comment

begin_comment
comment|// RUN: %clang -target armv7s -mcpu=swift -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=SWIFT %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7s -mthumb -mcpu=swift -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=SWIFT %s
end_comment

begin_comment
comment|// SWIFT:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// SWIFT:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// SWIFT:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting ARMv8-A Cortex implementations
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mcpu=cortex-a32 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mcpu=cortex-a32 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mcpu=cortex-a35 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mcpu=cortex-a35 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mcpu=cortex-a53 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mcpu=cortex-a53 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mcpu=cortex-a57 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mcpu=cortex-a57 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mcpu=cortex-a72 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mcpu=cortex-a72 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mcpu=cortex-a73 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mthumb -mcpu=cortex-a73 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=ARMV8 %s
end_comment

begin_comment
comment|// ARMV8:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// ARMV8:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// ARMV8:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-r4.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-r4 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R4-ARM %s
end_comment

begin_comment
comment|// R4-ARM-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// R4-ARM:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// R4-ARM-NOT:#define __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-r4 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R4-THUMB %s
end_comment

begin_comment
comment|// R4-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// R4-THUMB:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// R4-THUMB-NOT:#define __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-r4f.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-r4f -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R4F-ARM %s
end_comment

begin_comment
comment|// R4F-ARM-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// R4F-ARM:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// R4F-ARM:#define __ARM_FP 0xC
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-r4f -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R4F-THUMB %s
end_comment

begin_comment
comment|// R4F-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// R4F-THUMB:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// R4F-THUMB:#define __ARM_FP 0xC
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-r5.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-r5 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R5 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-r5 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R5 %s
end_comment

begin_comment
comment|// R5:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// R5:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// R5:#define __ARM_FP 0xC
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-r7 and cortex-r8.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-r7 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R7-R8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-r7 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R7-R8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=cortex-r8 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R7-R8 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-r8 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=R7-R8 %s
end_comment

begin_comment
comment|// R7-R8:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// R7-R8:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// R7-R8:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-m0.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m0 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M0-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m0plus -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M0-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m1 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M0-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=sc000 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M0-THUMB %s
end_comment

begin_comment
comment|// M0-THUMB-NOT:#define __ARM_ARCH_EXT_IDIV__
end_comment

begin_comment
comment|// M0-THUMB-NOT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// M0-THUMB-NOT:#define __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-m3.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m3 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M3-THUMB %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=sc300 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M3-THUMB %s
end_comment

begin_comment
comment|// M3-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// M3-THUMB-NOT:#define __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// M3-THUMB-NOT:#define __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-m4.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m4 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M4-THUMB %s
end_comment

begin_comment
comment|// M4-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// M4-THUMB:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// M4-THUMB:#define __ARM_FP 0x6
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting cortex-m7.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=cortex-m7 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M7-THUMB %s
end_comment

begin_comment
comment|// M7-THUMB:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// M7-THUMB:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// M7-THUMB:#define __ARM_FP 0xE
end_comment

begin_comment
comment|// M7-THUMB:#define __ARM_FPV5__ 1
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting v8m cores
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-m23 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M23 %s
end_comment

begin_comment
comment|// M23: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// M23: #define __ARM_ARCH_8M_BASE__ 1
end_comment

begin_comment
comment|// M23: #define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// M23-NOT: __ARM_ARCH_ISA_ARM
end_comment

begin_comment
comment|// M23: #define __ARM_ARCH_ISA_THUMB 1
end_comment

begin_comment
comment|// M23: #define __ARM_ARCH_PROFILE 'M'
end_comment

begin_comment
comment|// M23-NOT: __ARM_FEATURE_CRC32
end_comment

begin_comment
comment|// M23-NOT: __ARM_FEATURE_DSP
end_comment

begin_comment
comment|// M23-NOT: __ARM_FP 0x{{.*}}
end_comment

begin_comment
comment|// M23-NOT: __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1
end_comment

begin_comment
comment|// RUN: %clang -target arm -mcpu=cortex-m33 -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=M33 %s
end_comment

begin_comment
comment|// M33: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// M33: #define __ARM_ARCH_8M_MAIN__ 1
end_comment

begin_comment
comment|// M33: #define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// M33-NOT: __ARM_ARCH_ISA_ARM
end_comment

begin_comment
comment|// M33: #define __ARM_ARCH_ISA_THUMB 2
end_comment

begin_comment
comment|// M33: #define __ARM_ARCH_PROFILE 'M'
end_comment

begin_comment
comment|// M33-NOT: __ARM_FEATURE_CRC32
end_comment

begin_comment
comment|// M33: #define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// M33: #define __ARM_FP 0x6
end_comment

begin_comment
comment|// M33: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
end_comment

begin_comment
comment|// Test whether predefines are as expected when targeting krait.
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mcpu=krait -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=KRAIT %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7 -mthumb -mcpu=krait -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=KRAIT %s
end_comment

begin_comment
comment|// KRAIT:#define __ARM_ARCH_EXT_IDIV__ 1
end_comment

begin_comment
comment|// KRAIT:#define __ARM_FEATURE_DSP 1
end_comment

begin_comment
comment|// KRAIT:#define  __ARM_VFPV4__ 1
end_comment

begin_comment
comment|// RUN: %clang -target armv8.1a-none-none-eabi -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-V81A %s
end_comment

begin_comment
comment|// CHECK-V81A: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// CHECK-V81A: #define __ARM_ARCH_8_1A__ 1
end_comment

begin_comment
comment|// CHECK-V81A: #define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// CHECK-V81A: #define __ARM_FEATURE_QRDMX 1
end_comment

begin_comment
comment|// CHECK-V81A: #define __ARM_FP 0xE
end_comment

begin_comment
comment|// RUN: %clang -target armv8.2a-none-none-eabi -x c -E -dM %s -o - | FileCheck -match-full-lines --check-prefix=CHECK-V82A %s
end_comment

begin_comment
comment|// CHECK-V82A: #define __ARM_ARCH 8
end_comment

begin_comment
comment|// CHECK-V82A: #define __ARM_ARCH_8_2A__ 1
end_comment

begin_comment
comment|// CHECK-V82A: #define __ARM_ARCH_PROFILE 'A'
end_comment

begin_comment
comment|// CHECK-V82A: #define __ARM_FEATURE_QRDMX 1
end_comment

begin_comment
comment|// CHECK-V82A: #define __ARM_FP 0xE
end_comment

end_unit

