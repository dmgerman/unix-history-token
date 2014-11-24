begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check passing Mips ABI options to the backend.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-DEF %s
end_comment

begin_comment
comment|// MIPS-DEF: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// MIPS-DEF: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64-DEF %s
end_comment

begin_comment
comment|// MIPS64-DEF: "-target-cpu" "mips64r2"
end_comment

begin_comment
comment|// MIPS64-DEF: "-target-abi" "n64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-32 %s
end_comment

begin_comment
comment|// MIPS-ABI-32: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// MIPS-ABI-32: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=o32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-O32 %s
end_comment

begin_comment
comment|// MIPS-ABI-O32: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// MIPS-ABI-O32: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=n32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-N32 %s
end_comment

begin_comment
comment|// MIPS-ABI-N32: "-target-cpu" "mips64r2"
end_comment

begin_comment
comment|// MIPS-ABI-N32: "-target-abi" "n32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-64 %s
end_comment

begin_comment
comment|// MIPS-ABI-64: "-target-cpu" "mips64r2"
end_comment

begin_comment
comment|// MIPS-ABI-64: "-target-abi" "n64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=n64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-N64 %s
end_comment

begin_comment
comment|// MIPS-ABI-N64: "-target-cpu" "mips64r2"
end_comment

begin_comment
comment|// MIPS-ABI-N64: "-target-abi" "n64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang -target mips64-linux-gnu -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=o64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-O64 %s
end_comment

begin_comment
comment|// MIPS-ABI-O64: error: unknown target ABI 'o64'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=eabi 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-EABI %s
end_comment

begin_comment
comment|// MIPS-ABI-EABI: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// MIPS-ABI-EABI: "-target-abi" "eabi"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang -target mips-linux-gnu -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=unknown 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-UNKNOWN %s
end_comment

begin_comment
comment|// MIPS-ABI-UNKNOWN: error: unknown target ABI 'unknown'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips1 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-1 %s
end_comment

begin_comment
comment|// MIPS-ARCH-1: "-target-cpu" "mips1"
end_comment

begin_comment
comment|// MIPS-ARCH-1: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-2 %s
end_comment

begin_comment
comment|// MIPS-ARCH-2: "-target-cpu" "mips2"
end_comment

begin_comment
comment|// MIPS-ARCH-2: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips3 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-3 %s
end_comment

begin_comment
comment|// MIPS-ARCH-3: "-target-cpu" "mips3"
end_comment

begin_comment
comment|// MIPS-ARCH-3: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips4 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-4 %s
end_comment

begin_comment
comment|// MIPS-ARCH-4: "-target-cpu" "mips4"
end_comment

begin_comment
comment|// MIPS-ARCH-4: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips5 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-5 %s
end_comment

begin_comment
comment|// MIPS-ARCH-5: "-target-cpu" "mips5"
end_comment

begin_comment
comment|// MIPS-ARCH-5: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-32 %s
end_comment

begin_comment
comment|// MIPS-ARCH-32: "-target-cpu" "mips32"
end_comment

begin_comment
comment|// MIPS-ARCH-32: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips32r2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-32R2 %s
end_comment

begin_comment
comment|// MIPS-ARCH-32R2: "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// MIPS-ARCH-32R2: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-3264 %s
end_comment

begin_comment
comment|// MIPS-ARCH-3264: "-target-cpu" "mips64"
end_comment

begin_comment
comment|// MIPS-ARCH-3264: "-target-abi" "o32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-64 %s
end_comment

begin_comment
comment|// MIPS-ARCH-64: "-target-cpu" "mips64"
end_comment

begin_comment
comment|// MIPS-ARCH-64: "-target-abi" "n64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips64r2 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-64R2 %s
end_comment

begin_comment
comment|// MIPS-ARCH-64R2: "-target-cpu" "mips64r2"
end_comment

begin_comment
comment|// MIPS-ARCH-64R2: "-target-abi" "n64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -march=octeon 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-OCTEON %s
end_comment

begin_comment
comment|// MIPS-ARCH-OCTEON: "-target-cpu" "octeon"
end_comment

begin_comment
comment|// MIPS-ARCH-OCTEON: "-target-abi" "n64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang -target mips64-linux-gnu -c %s \
end_comment

begin_comment
comment|// RUN:        -march=mips32 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-6432 %s
end_comment

begin_comment
comment|// MIPS-ARCH-6432: error: unknown target CPU 'mips32'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: not %clang -target mips-linux-gnu -c %s \
end_comment

begin_comment
comment|// RUN:        -march=unknown 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ARCH-UNKNOWN %s
end_comment

begin_comment
comment|// MIPS-ARCH-UNKNOWN: error: unknown target CPU 'unknown'
end_comment

end_unit

