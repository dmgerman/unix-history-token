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
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
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
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
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
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -msoft-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SOFT %s
end_comment

begin_comment
comment|// CHECK-SOFT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-SOFT: "-msoft-float"
end_comment

begin_comment
comment|// CHECK-SOFT: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfloat-abi=hard
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
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
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mfloat-abi=soft \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-SOFT %s
end_comment

begin_comment
comment|// CHECK-ABI-SOFT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-ABI-SOFT: "-msoft-float"
end_comment

begin_comment
comment|// CHECK-ABI-SOFT: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mdouble-float
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -msingle-float -mdouble-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-DOUBLE %s
end_comment

begin_comment
comment|// CHECK-ABI-DOUBLE: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|// CHECK-ABI-DOUBLE-NOT: "+single-float"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msingle-float
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mdouble-float -msingle-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-SINGLE %s
end_comment

begin_comment
comment|// CHECK-ABI-SINGLE: "-target-feature" "+single-float"
end_comment

begin_comment
comment|// CHECK-ABI-SINGLE: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float -msingle-float
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -msoft-float -msingle-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-SOFT-SINGLE %s
end_comment

begin_comment
comment|// CHECK-ABI-SOFT-SINGLE: "-target-feature" "+single-float"
end_comment

begin_comment
comment|// CHECK-ABI-SOFT-SINGLE: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default -mips16
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mips16 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEF-MIPS16 %s
end_comment

begin_comment
comment|// CHECK-DEF-MIPS16: "-target-feature" "+mips16"
end_comment

begin_comment
comment|// CHECK-DEF-MIPS16: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mhard-float -mips16
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mhard-float -mips16 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-HARD-MIPS16 %s
end_comment

begin_comment
comment|// CHECK-HARD-MIPS16: "-target-feature" "+mips16"
end_comment

begin_comment
comment|// CHECK-HARD-MIPS16: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -msoft-float -mips16
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -msoft-float -mips16 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SOFT-MIPS16 %s
end_comment

begin_comment
comment|// CHECK-SOFT-MIPS16: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-SOFT-MIPS16: "-target-feature" "+mips16"
end_comment

begin_comment
comment|// CHECK-SOFT-MIPS16: "-msoft-float"
end_comment

begin_comment
comment|// CHECK-SOFT-MIPS16: "-mfloat-abi" "soft"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfloat-abi=hard -mips16
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mfloat-abi=hard -mips16 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-HARD-MIPS16 %s
end_comment

begin_comment
comment|// CHECK-ABI-HARD-MIPS16: "-target-feature" "+mips16"
end_comment

begin_comment
comment|// CHECK-ABI-HARD-MIPS16: "-mfloat-abi" "hard"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -mfloat-abi=soft -mips16
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target mips-linux-gnu -mfloat-abi=soft -mips16 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ABI-SOFT-MIPS16 %s
end_comment

begin_comment
comment|// CHECK-ABI-SOFT-MIPS16: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-ABI-SOFT-MIPS16: "-target-feature" "+mips16"
end_comment

begin_comment
comment|// CHECK-ABI-SOFT-MIPS16: "-msoft-float"
end_comment

begin_comment
comment|// CHECK-ABI-SOFT-MIPS16: "-mfloat-abi" "soft"
end_comment

end_unit

