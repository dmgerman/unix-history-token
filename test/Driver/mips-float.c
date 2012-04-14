begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check handling -mhard-float / -msoft-float / -mfloat-abi options
end_comment

begin_comment
comment|// when build for MIPS platforms.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default
end_comment

begin_comment
comment|// RUN: %clang -ccc-clang-archs mips -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEF %s
end_comment

begin_comment
comment|// CHECK-DEF: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mhard-float
end_comment

begin_comment
comment|// RUN: %clang -ccc-clang-archs mips -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mhard-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-HARD %s
end_comment

begin_comment
comment|// CHECK-HARD: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float
end_comment

begin_comment
comment|// RUN: %clang -ccc-clang-archs mips -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -msoft-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SOFT %s
end_comment

begin_comment
comment|// CHECK-SOFT: "-msoft-float"
end_comment

begin_comment
comment|// CHECK-SOFT: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// CHECK-SOFT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfloat-abi=hard
end_comment

begin_comment
comment|// RUN: %clang -ccc-clang-archs mips -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mfloat-abi=hard \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-HARD %s
end_comment

begin_comment
comment|// CHECK-ABI-HARD: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfloat-abi=soft
end_comment

begin_comment
comment|// RUN: %clang -ccc-clang-archs mips -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mfloat-abi=soft \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-SOFT %s
end_comment

begin_comment
comment|// CHECK-ABI-SOFT: "-msoft-float"
end_comment

begin_comment
comment|// CHECK-ABI-SOFT: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|// CHECK-ABI-SOFT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfloat-abi=single
end_comment

begin_comment
comment|// RUN: %clang -ccc-clang-archs mips -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mfloat-abi=single \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-SINGLE %s
end_comment

begin_comment
comment|// CHECK-ABI-SINGLE: "-target-feature" "+single-float"
end_comment

end_unit

