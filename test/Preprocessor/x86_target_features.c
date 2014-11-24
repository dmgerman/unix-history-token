begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=core2 -msse4 -x c -E -dM -o - %s | FileCheck --check-prefix=SSE4 %s
end_comment

begin_comment
comment|// SSE4: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// SSE4: #define __SSE2__ 1
end_comment

begin_comment
comment|// SSE4: #define __SSE3__ 1
end_comment

begin_comment
comment|// SSE4: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// SSE4: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// SSE4: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// SSE4: #define __SSE__ 1
end_comment

begin_comment
comment|// SSE4: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=core2 -msse4 -mno-sse2 -x c -E -dM -o - %s | FileCheck --check-prefix=SSE %s
end_comment

begin_comment
comment|// SSE-NOT: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// SSE-NOT: #define __SSE2__ 1
end_comment

begin_comment
comment|// SSE-NOT: #define __SSE3__ 1
end_comment

begin_comment
comment|// SSE-NOT: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// SSE-NOT: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// SSE: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// SSE: #define __SSE__ 1
end_comment

begin_comment
comment|// SSE-NOT: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentium-m -x c -E -dM -o - %s | FileCheck --check-prefix=SSE2 %s
end_comment

begin_comment
comment|// SSE2: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// SSE2: #define __SSE2__ 1
end_comment

begin_comment
comment|// SSE2-NOT: #define __SSE3__ 1
end_comment

begin_comment
comment|// SSE2-NOT: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// SSE2-NOT: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// SSE2: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// SSE2: #define __SSE__ 1
end_comment

begin_comment
comment|// SSE2-NOT: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentium-m -mno-sse -mavx -x c -E -dM -o - %s | FileCheck --check-prefix=AVX %s
end_comment

begin_comment
comment|// AVX: #define __AVX__ 1
end_comment

begin_comment
comment|// AVX: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// AVX: #define __SSE2__ 1
end_comment

begin_comment
comment|// AVX: #define __SSE3__ 1
end_comment

begin_comment
comment|// AVX: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// AVX: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// AVX: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// AVX: #define __SSE__ 1
end_comment

begin_comment
comment|// AVX: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentium-m -mxop -mno-avx -x c -E -dM -o - %s | FileCheck --check-prefix=SSE4A %s
end_comment

begin_comment
comment|// SSE4A: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// SSE4A: #define __SSE2__ 1
end_comment

begin_comment
comment|// SSE4A: #define __SSE3__ 1
end_comment

begin_comment
comment|// SSE4A: #define __SSE4A__ 1
end_comment

begin_comment
comment|// SSE4A: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// SSE4A: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// SSE4A: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// SSE4A: #define __SSE__ 1
end_comment

begin_comment
comment|// SSE4A: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mavx512f -x c -E -dM -o - %s | FileCheck --check-prefix=AVX512F %s
end_comment

begin_comment
comment|// AVX512F: #define __AVX2__ 1
end_comment

begin_comment
comment|// AVX512F: #define __AVX512F__ 1
end_comment

begin_comment
comment|// AVX512F: #define __AVX__ 1
end_comment

begin_comment
comment|// AVX512F: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// AVX512F: #define __SSE2__ 1
end_comment

begin_comment
comment|// AVX512F: #define __SSE3__ 1
end_comment

begin_comment
comment|// AVX512F: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// AVX512F: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// AVX512F: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// AVX512F: #define __SSE__ 1
end_comment

begin_comment
comment|// AVX512F: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mavx512cd -x c -E -dM -o - %s | FileCheck --check-prefix=AVX512CD %s
end_comment

begin_comment
comment|// AVX512CD: #define __AVX2__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __AVX512CD__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __AVX512F__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __AVX__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __SSE2__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __SSE3__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __SSE__ 1
end_comment

begin_comment
comment|// AVX512CD: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mavx512er -x c -E -dM -o - %s | FileCheck --check-prefix=AVX512ER %s
end_comment

begin_comment
comment|// AVX512ER: #define __AVX2__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __AVX512ER__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __AVX512F__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __AVX__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __SSE2__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __SSE3__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __SSE__ 1
end_comment

begin_comment
comment|// AVX512ER: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mavx512pf -x c -E -dM -o - %s | FileCheck --check-prefix=AVX512PF %s
end_comment

begin_comment
comment|// AVX512PF: #define __AVX2__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __AVX512F__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __AVX512PF__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __AVX__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __SSE2__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __SSE3__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __SSE__ 1
end_comment

begin_comment
comment|// AVX512PF: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mavx512pf -mno-avx512f -x c -E -dM -o - %s | FileCheck --check-prefix=AVX512F2 %s
end_comment

begin_comment
comment|// AVX512F2: #define __AVX2__ 1
end_comment

begin_comment
comment|// AVX512F2-NOT: #define __AVX512F__ 1
end_comment

begin_comment
comment|// AVX512F2-NOT: #define __AVX512PF__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __AVX__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __SSE2_MATH__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __SSE2__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __SSE3__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __SSE4_1__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __SSE4_2__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __SSE_MATH__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __SSE__ 1
end_comment

begin_comment
comment|// AVX512F2: #define __SSSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -msse4.2 -x c -E -dM -o - %s | FileCheck --check-prefix=SSE42POPCNT %s
end_comment

begin_comment
comment|// SSE42POPCNT: #define __POPCNT__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mno-popcnt -msse4.2 -x c -E -dM -o - %s | FileCheck --check-prefix=SSE42NOPOPCNT %s
end_comment

begin_comment
comment|// SSE42NOPOPCNT-NOT: #define __POPCNT__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mpopcnt -mno-sse4.2 -x c -E -dM -o - %s | FileCheck --check-prefix=NOSSE42POPCNT %s
end_comment

begin_comment
comment|// NOSSE42POPCNT: #define __POPCNT__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -msse -x c -E -dM -o - %s | FileCheck --check-prefix=SSEMMX %s
end_comment

begin_comment
comment|// SSEMMX: #define __MMX__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -msse -mno-sse -x c -E -dM -o - %s | FileCheck --check-prefix=SSENOSSEMMX %s
end_comment

begin_comment
comment|// SSENOSSEMMX-NOT: #define __MMX__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -msse -mno-mmx -x c -E -dM -o - %s | FileCheck --check-prefix=SSENOMMX %s
end_comment

begin_comment
comment|// SSENOMMX-NOT: #define __MMX__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mf16c -x c -E -dM -o - %s | FileCheck --check-prefix=F16C %s
end_comment

begin_comment
comment|// F16C: #define __AVX__ 1
end_comment

begin_comment
comment|// F16C: #define __F16C__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mf16c -mno-avx -x c -E -dM -o - %s | FileCheck --check-prefix=F16CNOAVX %s
end_comment

begin_comment
comment|// F16CNOAVX-NOT: #define __AVX__ 1
end_comment

begin_comment
comment|// F16CNOAVX-NOT: #define __F16C__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentiumpro -mpclmul -x c -E -dM -o - %s | FileCheck --check-prefix=PCLMUL %s
end_comment

begin_comment
comment|// PCLMUL: #define __PCLMUL__ 1
end_comment

begin_comment
comment|// PCLMUL: #define __SSE2__ 1
end_comment

begin_comment
comment|// PCLMUL-NOT: #define __SSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentiumpro -mpclmul -mno-sse2 -x c -E -dM -o - %s | FileCheck --check-prefix=PCLMULNOSSE2 %s
end_comment

begin_comment
comment|// PCLMULNOSSE2-NOT: #define __PCLMUL__ 1
end_comment

begin_comment
comment|// PCLMULNOSSE2-NOT: #define __SSE2__ 1
end_comment

begin_comment
comment|// PCLMULNOSSE2-NOT: #define __SSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentiumpro -maes -x c -E -dM -o - %s | FileCheck --check-prefix=AES %s
end_comment

begin_comment
comment|// AES: #define __AES__ 1
end_comment

begin_comment
comment|// AES: #define __SSE2__ 1
end_comment

begin_comment
comment|// AES-NOT: #define __SSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentiumpro -maes -mno-sse2 -x c -E -dM -o - %s | FileCheck --check-prefix=AESNOSSE2 %s
end_comment

begin_comment
comment|// AESNOSSE2-NOT: #define __AES__ 1
end_comment

begin_comment
comment|// AESNOSSE2-NOT: #define __SSE2__ 1
end_comment

begin_comment
comment|// AESNOSSE2-NOT: #define __SSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentiumpro -msha -x c -E -dM -o - %s | FileCheck --check-prefix=SHA %s
end_comment

begin_comment
comment|// SHA: #define __SHA__ 1
end_comment

begin_comment
comment|// SHA: #define __SSE2__ 1
end_comment

begin_comment
comment|// SHA-NOT: #define __SSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentiumpro -msha -mno-sha -x c -E -dM -o - %s | FileCheck --check-prefix=SHANOSHA %s
end_comment

begin_comment
comment|// SHANOSHA-NOT: #define __SHA__ 1
end_comment

begin_comment
comment|// SHANOSHA-NOT: #define __SSE2__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentiumpro -msha -mno-sse2 -x c -E -dM -o - %s | FileCheck --check-prefix=SHANOSSE2 %s
end_comment

begin_comment
comment|// SHANOSSE2-NOT: #define __SHA__ 1
end_comment

begin_comment
comment|// SHANOSSE2-NOT: #define __SSE2__ 1
end_comment

begin_comment
comment|// SHANOSSE2-NOT: #define __SSE3__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mtbm -x c -E -dM -o - %s | FileCheck --check-prefix=TBM %s
end_comment

begin_comment
comment|// TBM: #define __TBM__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=bdver2 -mno-tbm -x c -E -dM -o - %s | FileCheck --check-prefix=NOTBM %s
end_comment

begin_comment
comment|// NOTBM-NOT: #define __TBM__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=pentiumpro -mcx16 -x c -E -dM -o - %s | FileCheck --check-prefix=MCX16 %s
end_comment

begin_comment
comment|// MCX16: #define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mprfchw -x c -E -dM -o - %s | FileCheck --check-prefix=PRFCHW %s
end_comment

begin_comment
comment|// PRFCHW: #define __PRFCHW__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=btver2 -mno-prfchw -x c -E -dM -o - %s | FileCheck --check-prefix=NOPRFCHW %s
end_comment

begin_comment
comment|// NOPRFCHW-NOT: #define __PRFCHW__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -m3dnow -x c -E -dM -o - %s | FileCheck --check-prefix=3DNOWPRFCHW %s
end_comment

begin_comment
comment|// 3DNOWPRFCHW: #define __PRFCHW__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mno-prfchw -m3dnow -x c -E -dM -o - %s | FileCheck --check-prefix=3DNOWNOPRFCHW %s
end_comment

begin_comment
comment|// 3DNOWNOPRFCHW-NOT: #define __PRFCHW__ 1
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -march=atom -mprfchw -mno-3dnow -x c -E -dM -o - %s | FileCheck --check-prefix=NO3DNOWPRFCHW %s
end_comment

begin_comment
comment|// NO3DNOWPRFCHW: #define __PRFCHW__ 1
end_comment

end_unit

