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
comment|// CHECK-PIC1: "-mrelocation-model" "pic"
end_comment

begin_comment
comment|// CHECK-PIC1: "-pic-level" "1"
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
comment|// CHECK-PIE1: "-mrelocation-model" "pic"
end_comment

begin_comment
comment|// CHECK-PIE1: "-pic-level" "1"
end_comment

begin_comment
comment|// CHECK-PIE1: "-pie-level" "1"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PIE2: "-mrelocation-model" "pic"
end_comment

begin_comment
comment|// CHECK-PIE2: "-pic-level" "2"
end_comment

begin_comment
comment|// CHECK-PIE2: "-pie-level" "2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-PIE-LD: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-PIE-LD: "-pie"
end_comment

begin_comment
comment|// CHECK-PIE-LD: "Scrt1.o" "crti.o" "crtbeginS.o"
end_comment

begin_comment
comment|// CHECK-PIE-LD: "crtendS.o" "crtn.o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC-32: "-mrelocation-model" "dynamic-no-pic"
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC-32-NOT: "-pic-level"
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC-32-NOT: "-pie-level"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC-64: "-mrelocation-model" "dynamic-no-pic"
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC-64: "-pic-level" "2"
end_comment

begin_comment
comment|// CHECK-DYNAMIC-NO-PIC-64-NOT: "-pie-level"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NON-DARWIN-DYNAMIC-NO-PIC: error: unsupported option '-mdynamic-no-pic' for target 'i386-unknown-unknown'
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
comment|//
end_comment

begin_comment
comment|// Check that PIC and PIE flags obey last-match-wins. If the last flag is
end_comment

begin_comment
comment|// a no-* variant, regardless of which variant or which flags precede it, we
end_comment

begin_comment
comment|// get no PIC.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fno-pic -### 2>&1 \
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
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -fno-pic -### 2>&1 \
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
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -fno-PIC -### 2>&1 \
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
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -fno-pie -### 2>&1 \
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
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -fno-pie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -fno-PIE -### 2>&1 \
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
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Last-match-wins where both pic and pie are specified.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpie -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIE -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE1
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fpic -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -fPIC -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Last-match-wins when selecting level 1 vs. level 2.
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
comment|// Make sure -pie is passed to along to ld and that the right *crt* files
end_comment

begin_comment
comment|// are linked in.
end_comment

begin_comment
comment|// RUN: %clang %s -target i386-unknown-freebsd -fPIE -pie -### \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_freebsd_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE-LD
end_comment

begin_comment
comment|// RUN: %clang %s -target i386-linux-gnu -fPIE -pie -### \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE-LD
end_comment

begin_comment
comment|// RUN: %clang %s -target i386-linux-gnu -fPIC -pie -### \
end_comment

begin_comment
comment|// RUN: --sysroot=%S/Inputs/basic_linux_tree 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIE-LD
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
comment|//
end_comment

begin_comment
comment|// Darwin is a beautiful and unique snowflake when it comes to these flags.
end_comment

begin_comment
comment|// When targetting a 32-bit darwin system, the -fno-* flag variants work and
end_comment

begin_comment
comment|// disable PIC, but any other flag enables PIC (*not* PIE) even if the flag
end_comment

begin_comment
comment|// specifies PIE. On 64-bit targets, there is simply nothing you can do, there
end_comment

begin_comment
comment|// is no PIE, there is only PIC when it comes to compilation.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fPIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fno-PIC -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -fno-PIC -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-apple-darwin -fno-PIC -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-apple-darwin -fno-PIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-apple-darwin -fpic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-apple-darwin -fPIE -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Darwin gets even more special with '-mdynamic-no-pic'. This flag is only
end_comment

begin_comment
comment|// valid on Darwin, and it's behavior is very strange but needs to remain
end_comment

begin_comment
comment|// consistent for compatibility.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-unknown-unknown -mdynamic-no-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NON-DARWIN-DYNAMIC-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -mdynamic-no-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC-32
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -mdynamic-no-pic -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC-32
end_comment

begin_comment
comment|// RUN: %clang -c %s -target i386-apple-darwin -mdynamic-no-pic -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC-32
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-apple-darwin -mdynamic-no-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC-64
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-apple-darwin -mdynamic-no-pic -fno-pic -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC-64
end_comment

begin_comment
comment|// RUN: %clang -c %s -target x86_64-apple-darwin -mdynamic-no-pic -fpie -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-DYNAMIC-NO-PIC-64
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Checks for ARM+Apple+IOS including -fapple-kext, -mkernel, and iphoneos
end_comment

begin_comment
comment|// version boundaries.
end_comment

begin_comment
comment|// RUN: %clang -c %s -target armv7-apple-ios -fapple-kext -miphoneos-version-min=6.0.0 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target armv7-apple-ios -mkernel -miphoneos-version-min=6.0.0 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-PIC2
end_comment

begin_comment
comment|// RUN: %clang -c %s -target armv7-apple-ios -fapple-kext -miphoneos-version-min=5.0.0 -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

begin_comment
comment|// RUN: %clang -c %s -target armv7-apple-ios -fapple-kext -miphoneos-version-min=6.0.0 -static -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-NO-PIC
end_comment

end_unit

