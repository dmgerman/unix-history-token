begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The default ABI is aapcs
end_comment

begin_comment
comment|// RUN: %clang -target arm--- %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// RUN: %clang -target armeb--- %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// RUN: %clang -target thumb--- %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// RUN: %clang -target thumbeb--- %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// MachO targets default to apcs-gnu, except for m-class processors
end_comment

begin_comment
comment|// RUN: %clang -target arm--darwin- -arch armv7s %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-APCS-GNU %s
end_comment

begin_comment
comment|// RUN: %clang -target thumb--darwin- -arch armv7s %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-APCS-GNU %s
end_comment

begin_comment
comment|// RUN: %clang -target thumb--darwin- -arch armv7m %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// Windows targets default to AAPCS, regardless of environment
end_comment

begin_comment
comment|// RUN: %clang -target arm--windows-gnueabi %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// NetBSD defaults to apcs-gnu, but can also use aapcs
end_comment

begin_comment
comment|// RUN: %clang -target arm--netbsd- %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-APCS-GNU %s
end_comment

begin_comment
comment|// RUN: %clang -target arm--netbsd-eabi %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// RUN: %clang -target arm--netbsd-eabihf %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// OpenBSD defaults to aapcs-linux
end_comment

begin_comment
comment|// RUN: %clang -target arm--openbsd- %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS-LINUX %s
end_comment

begin_comment
comment|// Otherwise, ABI is selected based on environment
end_comment

begin_comment
comment|// RUN: %clang -target arm---android %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS-LINUX %s
end_comment

begin_comment
comment|// RUN: %clang -target arm---gnueabi %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS-LINUX %s
end_comment

begin_comment
comment|// RUN: %clang -target arm---gnueabihf %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS-LINUX %s
end_comment

begin_comment
comment|// RUN: %clang -target arm---musleabi %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS-LINUX %s
end_comment

begin_comment
comment|// RUN: %clang -target arm---musleabihf %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS-LINUX %s
end_comment

begin_comment
comment|// RUN: %clang -target arm---eabi %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// RUN: %clang -target arm---eabihf %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// ABI can be overridden by the -mabi= option
end_comment

begin_comment
comment|// RUN: %clang -target arm---eabi -mabi=apcs-gnu %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-APCS-GNU %s
end_comment

begin_comment
comment|// RUN: %clang -target arm---gnueabi -mabi=aapcs %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS %s
end_comment

begin_comment
comment|// RUN: %clang -target arm---eabi -mabi=aapcs-linux %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-AAPCS-LINUX %s
end_comment

begin_comment
comment|// CHECK-APCS-GNU: "-target-abi" "apcs-gnu"
end_comment

begin_comment
comment|// CHECK-AAPCS: "-target-abi" "aapcs"
end_comment

begin_comment
comment|// CHECK-AAPCS-LINUX: "-target-abi" "aapcs-linux"
end_comment

end_unit

