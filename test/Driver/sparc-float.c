begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check handling -mhard-float / -msoft-float options
end_comment

begin_comment
comment|// when build for SPARC platforms.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default sparc
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target sparc-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEF %s
end_comment

begin_comment
comment|// CHECK-DEF-NOT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-DEF-NOT: "-msoft-float"
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
comment|// RUN:     -target sparc-linux-gnu -mhard-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-HARD %s
end_comment

begin_comment
comment|// CHECK-HARD-NOT: "-msoft-float"
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
comment|// RUN:     -target sparc-linux-gnu -msoft-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SOFT %s
end_comment

begin_comment
comment|// CHECK-SOFT: "-target-feature" "+soft-float"
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
comment|// RUN:     -target sparc-linux-gnu -mfloat-abi=soft \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FLOATABISOFT %s
end_comment

begin_comment
comment|// CHECK-FLOATABISOFT: "-target-feature" "+soft-float"
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
comment|// RUN:     -target sparc-linux-gnu -mfloat-abi=hard \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FLOATABIHARD %s
end_comment

begin_comment
comment|// CHECK-FLOATABIHARD-NOT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// check invalid -mfloat-abi
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target sparc-linux-gnu -mfloat-abi=x \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ERRMSG %s
end_comment

begin_comment
comment|// CHECK-ERRMSG: error: invalid float ABI '-mfloat-abi=x'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default sparc64
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target sparc64-linux-gnu \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-DEF-SPARC64 %s
end_comment

begin_comment
comment|// CHECK-DEF-SPARC64-NOT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|// CHECK-DEF-SPARC64-NOT: "-msoft-float"
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
comment|// RUN:     -target sparc64-linux-gnu -mhard-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-HARD-SPARC64 %s
end_comment

begin_comment
comment|// CHECK-HARD-SPARC64-NOT: "-msoft-float"
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
comment|// RUN:     -target sparc64-linux-gnu -msoft-float \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SOFT-SPARC64 %s
end_comment

begin_comment
comment|// CHECK-SOFT-SPARC64: "-target-feature" "+soft-float"
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
comment|// RUN:     -target sparc64-linux-gnu -mfloat-abi=soft \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FLOATABISOFT64 %s
end_comment

begin_comment
comment|// CHECK-FLOATABISOFT64: "-target-feature" "+soft-float"
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
comment|// RUN:     -target sparc64-linux-gnu -mfloat-abi=hard \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FLOATABIHARD64 %s
end_comment

begin_comment
comment|// CHECK-FLOATABIHARD64-NOT: "-target-feature" "+soft-float"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// check invalid -mfloat-abi
end_comment

begin_comment
comment|// RUN: %clang -c %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -target sparc64-linux-gnu -mfloat-abi=x \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-ERRMSG64 %s
end_comment

begin_comment
comment|// CHECK-ERRMSG64: error: invalid float ABI '-mfloat-abi=x'
end_comment

end_unit

