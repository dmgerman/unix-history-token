begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// Test the driver's control over the PIC behavior for PS4 compiler.
end_comment

begin_comment
comment|// These consist of tests of the relocation model flags and the
end_comment

begin_comment
comment|// pic level flags passed to CC1.
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
comment|// CHECK-NO-PIC-NOT: "-pic-is-pie"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC2: unsupported option '-mdynamic-no-pic'
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC2: "-mrelocation-model" "dynamic-no-pic"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PIC2: "-mrelocation-model" "pic"
end_comment

begin_comment
comment|// CHECK-PIC2: "-pic-level" "2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PIE2: "-mrelocation-model" "pic"
end_comment

begin_comment
comment|// CHECK-PIE2: "-pic-is-pie"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NOPIC-IGNORED: using '-fPIC'
end_comment

begin_comment
comment|// CHECK-NOPIC-IGNORED: "-mrelocation-model" "pic"
end_comment

begin_comment
comment|// CHECK-NOPIC-IGNORED: "-pic-level" "2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DIAG-PIC: option '-fno-PIC' was ignored by the PS4 toolchain, using '-fPIC'
end_comment

begin_comment
comment|// CHECK-DIAG-PIE: option '-fno-PIE' was ignored by the PS4 toolchain, using '-fPIC'
end_comment

begin_comment
comment|// CHECK-DIAG-pic: option '-fno-pic' was ignored by the PS4 toolchain, using '-fPIC'
end_comment

begin_comment
comment|// CHECK-DIAG-pie: option '-fno-pie' was ignored by the PS4 toolchain, using '-fPIC'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-STATIC-ERR: unsupported option '-static' for target 'PS4'
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpic -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fPIC -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpic -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fPIC -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpie -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fPIE -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpie -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fPIE -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpie -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpic -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpic -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fPIC -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpic -fPIE -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fpie -fPIC -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Defaults change for PS4.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NOPIC-IGNORED
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Disregard any of the PIC-specific flags if we have a trump-card flag.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -mkernel -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -mdynamic-no-pic -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -static not supported at all.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -static -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-STATIC-ERR
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -fno-PIC etc. is obeyed if -mcmodel=kernel is also present.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -mcmodel=kernel -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -mcmodel=kernel -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -mcmodel=kernel -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -mcmodel=kernel -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Verify that we reflect the option the user specified, when we ignore it.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DIAG-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DIAG-PIE
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DIAG-pic
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-scei-ps4 -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DIAG-pie
end_comment

end_unit

