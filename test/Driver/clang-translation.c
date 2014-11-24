begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -### -S -O0 -Os %s -o %t.s -fverbose-asm -funwind-tables -fvisibility=hidden 2>&1 | FileCheck -check-prefix=I386 %s
end_comment

begin_comment
comment|// I386: "-triple" "i386-unknown-unknown"
end_comment

begin_comment
comment|// I386: "-S"
end_comment

begin_comment
comment|// I386: "-disable-free"
end_comment

begin_comment
comment|// I386: "-mrelocation-model" "static"
end_comment

begin_comment
comment|// I386: "-mdisable-fp-elim"
end_comment

begin_comment
comment|// I386: "-masm-verbose"
end_comment

begin_comment
comment|// I386: "-munwind-tables"
end_comment

begin_comment
comment|// I386: "-Os"
end_comment

begin_comment
comment|// I386: "-fvisibility"
end_comment

begin_comment
comment|// I386: "hidden"
end_comment

begin_comment
comment|// I386: "-o"
end_comment

begin_comment
comment|// I386: clang-translation
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin9 -### -S %s -o %t.s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=YONAH %s
end_comment

begin_comment
comment|// YONAH: "-target-cpu"
end_comment

begin_comment
comment|// YONAH: "yonah"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin9 -### -S %s -o %t.s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CORE2 %s
end_comment

begin_comment
comment|// CORE2: "-target-cpu"
end_comment

begin_comment
comment|// CORE2: "core2"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64h-apple-darwin -### -S %s -o %t.s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=AVX2 %s
end_comment

begin_comment
comment|// AVX2: "-target-cpu"
end_comment

begin_comment
comment|// AVX2: "core-avx2"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### -S %s -arch armv7 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=ARMV7_DEFAULT %s
end_comment

begin_comment
comment|// ARMV7_DEFAULT: clang
end_comment

begin_comment
comment|// ARMV7_DEFAULT: "-cc1"
end_comment

begin_comment
comment|// ARMV7_DEFAULT-NOT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_DEFAULT: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// ARMV7_DEFAULT-NOT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_DEFAULT: "-x" "c"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### -S %s -arch armv7 \
end_comment

begin_comment
comment|// RUN: -msoft-float 2>&1 | FileCheck -check-prefix=ARMV7_SOFTFLOAT %s
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: clang
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-cc1"
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-target-feature"
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-neon"
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// ARMV7_SOFTFLOAT: "-x" "c"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -### -S %s -arch armv7 \
end_comment

begin_comment
comment|// RUN: -mhard-float 2>&1 | FileCheck -check-prefix=ARMV7_HARDFLOAT %s
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT: clang
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT: "-cc1"
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT-NOT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT-NOT: "-msoft-float"
end_comment

begin_comment
comment|// ARMV7_HARDFLOAT: "-x" "c"
end_comment

begin_comment
comment|// RUN: %clang -target arm-linux -### -S %s -march=armv5e 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=ARMV5E %s
end_comment

begin_comment
comment|// ARMV5E: clang
end_comment

begin_comment
comment|// ARMV5E: "-cc1"
end_comment

begin_comment
comment|// ARMV5E: "-target-cpu" "arm1022e"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=G5 2>&1 | FileCheck -check-prefix=PPCG5 %s
end_comment

begin_comment
comment|// PPCG5: clang
end_comment

begin_comment
comment|// PPCG5: "-cc1"
end_comment

begin_comment
comment|// PPCG5: "-target-cpu" "g5"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power7 2>&1 | FileCheck -check-prefix=PPCPWR7 %s
end_comment

begin_comment
comment|// PPCPWR7: clang
end_comment

begin_comment
comment|// PPCPWR7: "-cc1"
end_comment

begin_comment
comment|// PPCPWR7: "-target-cpu" "pwr7"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power8 2>&1 | FileCheck -check-prefix=PPCPWR8 %s
end_comment

begin_comment
comment|// PPCPWR8: clang
end_comment

begin_comment
comment|// PPCPWR8: "-cc1"
end_comment

begin_comment
comment|// PPCPWR8: "-target-cpu" "pwr8"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=a2q 2>&1 | FileCheck -check-prefix=PPCA2Q %s
end_comment

begin_comment
comment|// PPCA2Q: clang
end_comment

begin_comment
comment|// PPCA2Q: "-cc1"
end_comment

begin_comment
comment|// PPCA2Q: "-target-cpu" "a2q"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=630 2>&1 | FileCheck -check-prefix=PPC630 %s
end_comment

begin_comment
comment|// PPC630: clang
end_comment

begin_comment
comment|// PPC630: "-cc1"
end_comment

begin_comment
comment|// PPC630: "-target-cpu" "pwr3"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power3 2>&1 | FileCheck -check-prefix=PPCPOWER3 %s
end_comment

begin_comment
comment|// PPCPOWER3: clang
end_comment

begin_comment
comment|// PPCPOWER3: "-cc1"
end_comment

begin_comment
comment|// PPCPOWER3: "-target-cpu" "pwr3"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=pwr3 2>&1 | FileCheck -check-prefix=PPCPWR3 %s
end_comment

begin_comment
comment|// PPCPWR3: clang
end_comment

begin_comment
comment|// PPCPWR3: "-cc1"
end_comment

begin_comment
comment|// PPCPWR3: "-target-cpu" "pwr3"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power4 2>&1 | FileCheck -check-prefix=PPCPOWER4 %s
end_comment

begin_comment
comment|// PPCPOWER4: clang
end_comment

begin_comment
comment|// PPCPOWER4: "-cc1"
end_comment

begin_comment
comment|// PPCPOWER4: "-target-cpu" "pwr4"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=pwr4 2>&1 | FileCheck -check-prefix=PPCPWR4 %s
end_comment

begin_comment
comment|// PPCPWR4: clang
end_comment

begin_comment
comment|// PPCPWR4: "-cc1"
end_comment

begin_comment
comment|// PPCPWR4: "-target-cpu" "pwr4"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power5 2>&1 | FileCheck -check-prefix=PPCPOWER5 %s
end_comment

begin_comment
comment|// PPCPOWER5: clang
end_comment

begin_comment
comment|// PPCPOWER5: "-cc1"
end_comment

begin_comment
comment|// PPCPOWER5: "-target-cpu" "pwr5"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=pwr5 2>&1 | FileCheck -check-prefix=PPCPWR5 %s
end_comment

begin_comment
comment|// PPCPWR5: clang
end_comment

begin_comment
comment|// PPCPWR5: "-cc1"
end_comment

begin_comment
comment|// PPCPWR5: "-target-cpu" "pwr5"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power5x 2>&1 | FileCheck -check-prefix=PPCPOWER5X %s
end_comment

begin_comment
comment|// PPCPOWER5X: clang
end_comment

begin_comment
comment|// PPCPOWER5X: "-cc1"
end_comment

begin_comment
comment|// PPCPOWER5X: "-target-cpu" "pwr5x"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=pwr5x 2>&1 | FileCheck -check-prefix=PPCPWR5X %s
end_comment

begin_comment
comment|// PPCPWR5X: clang
end_comment

begin_comment
comment|// PPCPWR5X: "-cc1"
end_comment

begin_comment
comment|// PPCPWR5X: "-target-cpu" "pwr5x"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power6 2>&1 | FileCheck -check-prefix=PPCPOWER6 %s
end_comment

begin_comment
comment|// PPCPOWER6: clang
end_comment

begin_comment
comment|// PPCPOWER6: "-cc1"
end_comment

begin_comment
comment|// PPCPOWER6: "-target-cpu" "pwr6"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=pwr6 2>&1 | FileCheck -check-prefix=PPCPWR6 %s
end_comment

begin_comment
comment|// PPCPWR6: clang
end_comment

begin_comment
comment|// PPCPWR6: "-cc1"
end_comment

begin_comment
comment|// PPCPWR6: "-target-cpu" "pwr6"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power6x 2>&1 | FileCheck -check-prefix=PPCPOWER6X %s
end_comment

begin_comment
comment|// PPCPOWER6X: clang
end_comment

begin_comment
comment|// PPCPOWER6X: "-cc1"
end_comment

begin_comment
comment|// PPCPOWER6X: "-target-cpu" "pwr6x"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=pwr6x 2>&1 | FileCheck -check-prefix=PPCPWR6X %s
end_comment

begin_comment
comment|// PPCPWR6X: clang
end_comment

begin_comment
comment|// PPCPWR6X: "-cc1"
end_comment

begin_comment
comment|// PPCPWR6X: "-target-cpu" "pwr6x"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=power7 2>&1 | FileCheck -check-prefix=PPCPOWER7 %s
end_comment

begin_comment
comment|// PPCPOWER7: clang
end_comment

begin_comment
comment|// PPCPOWER7: "-cc1"
end_comment

begin_comment
comment|// PPCPOWER7: "-target-cpu" "pwr7"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=powerpc 2>&1 | FileCheck -check-prefix=PPCPOWERPC %s
end_comment

begin_comment
comment|// PPCPOWERPC: clang
end_comment

begin_comment
comment|// PPCPOWERPC: "-cc1"
end_comment

begin_comment
comment|// PPCPOWERPC: "-target-cpu" "ppc"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s -mcpu=powerpc64 2>&1 | FileCheck -check-prefix=PPCPOWERPC64 %s
end_comment

begin_comment
comment|// PPCPOWERPC64: clang
end_comment

begin_comment
comment|// PPCPOWERPC64: "-cc1"
end_comment

begin_comment
comment|// PPCPOWERPC64: "-target-cpu" "ppc64"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-unknown-linux-gnu \
end_comment

begin_comment
comment|// RUN: -### -S %s 2>&1 | FileCheck -check-prefix=PPC64NS %s
end_comment

begin_comment
comment|// PPC64NS: clang
end_comment

begin_comment
comment|// PPC64NS: "-cc1"
end_comment

begin_comment
comment|// PPC64NS: "-target-cpu" "ppc64"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc-fsl-linux -### -S %s \
end_comment

begin_comment
comment|// RUN: -mcpu=e500mc 2>&1 | FileCheck -check-prefix=PPCE500MC %s
end_comment

begin_comment
comment|// PPCE500MC: clang
end_comment

begin_comment
comment|// PPCE500MC: "-cc1"
end_comment

begin_comment
comment|// PPCE500MC: "-target-cpu" "e500mc"
end_comment

begin_comment
comment|// RUN: %clang -target powerpc64-fsl-linux -### -S \
end_comment

begin_comment
comment|// RUN: %s -mcpu=e5500 2>&1 | FileCheck -check-prefix=PPCE5500 %s
end_comment

begin_comment
comment|// PPCE5500: clang
end_comment

begin_comment
comment|// PPCE5500: "-cc1"
end_comment

begin_comment
comment|// PPCE5500: "-target-cpu" "e5500"
end_comment

begin_comment
comment|// RUN: %clang -target amd64-unknown-openbsd5.2 -### -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=AMD64 %s
end_comment

begin_comment
comment|// AMD64: clang
end_comment

begin_comment
comment|// AMD64: "-cc1"
end_comment

begin_comment
comment|// AMD64: "-triple"
end_comment

begin_comment
comment|// AMD64: "amd64-unknown-openbsd5.2"
end_comment

begin_comment
comment|// AMD64: "-munwind-tables"
end_comment

begin_comment
comment|// RUN: %clang -target amd64--mingw32 -### -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=AMD64-MINGW %s
end_comment

begin_comment
comment|// AMD64-MINGW: clang
end_comment

begin_comment
comment|// AMD64-MINGW: "-cc1"
end_comment

begin_comment
comment|// AMD64-MINGW: "-triple"
end_comment

begin_comment
comment|// AMD64-MINGW: "amd64--windows-gnu"
end_comment

begin_comment
comment|// AMD64-MINGW: "-munwind-tables"
end_comment

begin_comment
comment|// RUN: %clang -target i686-linux-android -### -S %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=ANDROID-X86 %s
end_comment

begin_comment
comment|// ANDROID-X86: clang
end_comment

begin_comment
comment|// ANDROID-X86: "-target-cpu" "i686"
end_comment

begin_comment
comment|// ANDROID-X86: "-target-feature" "+ssse3"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-android -### -S %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        --sysroot=%S/Inputs/basic_android_tree/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=ANDROID-X86_64 %s
end_comment

begin_comment
comment|// ANDROID-X86_64: clang
end_comment

begin_comment
comment|// ANDROID-X86_64: "-target-cpu" "x86-64"
end_comment

begin_comment
comment|// ANDROID-X86_64: "-target-feature" "+sse4.2"
end_comment

begin_comment
comment|// ANDROID-X86_64: "-target-feature" "+popcnt"
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=MIPS %s
end_comment

begin_comment
comment|// MIPS: clang
end_comment

begin_comment
comment|// MIPS: "-cc1"
end_comment

begin_comment
comment|// MIPS: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// MIPS: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-linux-gnu -### -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=MIPSEL %s
end_comment

begin_comment
comment|// MIPSEL: clang
end_comment

begin_comment
comment|// MIPSEL: "-cc1"
end_comment

begin_comment
comment|// MIPSEL: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// MIPSEL: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-linux-android -### -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=MIPSEL-ANDROID %s
end_comment

begin_comment
comment|// MIPSEL-ANDROID: clang
end_comment

begin_comment
comment|// MIPSEL-ANDROID: "-cc1"
end_comment

begin_comment
comment|// MIPSEL-ANDROID: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// MIPSEL-ANDROID: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=MIPS64 %s
end_comment

begin_comment
comment|// MIPS64: clang
end_comment

begin_comment
comment|// MIPS64: "-cc1"
end_comment

begin_comment
comment|// MIPS64: "-target-cpu" "mips64r2"
end_comment

begin_comment
comment|// MIPS64: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-gnu -### -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=MIPS64EL %s
end_comment

begin_comment
comment|// MIPS64EL: clang
end_comment

begin_comment
comment|// MIPS64EL: "-cc1"
end_comment

begin_comment
comment|// MIPS64EL: "-target-cpu" "mips64r2"
end_comment

begin_comment
comment|// MIPS64EL: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-android -### -S %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=MIPS64EL-ANDROID %s
end_comment

begin_comment
comment|// MIPS64EL-ANDROID: clang
end_comment

begin_comment
comment|// MIPS64EL-ANDROID: "-cc1"
end_comment

begin_comment
comment|// MIPS64EL-ANDROID: "-target-cpu" "mips64r2"
end_comment

begin_comment
comment|// MIPS64EL-ANDROID: "-mfloat-abi" "hard"
end_comment

end_unit

