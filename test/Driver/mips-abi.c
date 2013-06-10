begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check passing Mips ABI options to the backend.
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
comment|// MIPS-ABI-N64: "-target-abi" "n64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -c %s \
end_comment

begin_comment
comment|// RUN:        -mabi=o64 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ABI-O64 %s
end_comment

begin_comment
comment|// MIPS-ABI-O64: "-target-abi" "o64"
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
comment|// MIPS-ABI-EABI: "-target-abi" "eabi"
end_comment

end_unit

