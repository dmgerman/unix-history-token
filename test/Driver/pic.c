begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test the driver's control over the PIC behavior. These consist of tests of
end_comment

begin_comment
comment|// the relocation model flags and the pic level flags passed to CC1.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-PIC: "-mrelocation-model" "static"
end_comment

begin_comment
comment|// CHECK-NO-PIC-NOT: "-pic-level"
end_comment

begin_comment
comment|// CHECK-NO-PIC-NOT: "-pie-level"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC1: "-mrelocation-model" "dynamic-no-pic"
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC1: "-pic-level" "1"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC2: "-mrelocation-model" "dynamic-no-pic"
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC2: "-pic-level" "2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PIC1-NOT: "-mrelocation-model"
end_comment

begin_comment
comment|// CHECK-PIC1: "-pic-level" "1"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PIC2-NOT: "-mrelocation-model"
end_comment

begin_comment
comment|// CHECK-PIC2: "-pic-level" "2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PIE1-NOT: "-mrelocation-model"
end_comment

begin_comment
comment|// CHECK-PIE1: "-pie-level" "1"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PIE2-NOT: "-mrelocation-model"
end_comment

begin_comment
comment|// CHECK-PIE2: "-pie-level" "2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fPIE -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -fPIC -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Defaults change for Darwin.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Disregard any of the PIC-specific flags if we have a trump-card flag.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -mkernel -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -static -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -mdynamic-no-pic -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -mdynamic-no-pic -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC2
end_comment

end_unit

