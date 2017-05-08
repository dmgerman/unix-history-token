begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv6-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX %s
end_comment

begin_comment
comment|// CHECK-VERSION-OSX: "armv6k-apple-macosx10.5.0"
end_comment

begin_comment
comment|// RUN: %clang -target armv6-apple-darwin9 -miphoneos-version-min=2.0 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-IOS2 %s
end_comment

begin_comment
comment|// CHECK-VERSION-IOS2: "armv6k-apple-ios2.0.0"
end_comment

begin_comment
comment|// RUN: %clang -target armv6-apple-darwin9 -miphoneos-version-min=2.2 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-IOS22 %s
end_comment

begin_comment
comment|// CHECK-VERSION-IOS22: "armv6k-apple-ios2.2.0"
end_comment

begin_comment
comment|// RUN: %clang -target armv6-apple-darwin9 -miphoneos-version-min=3.0 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-IOS3 %s
end_comment

begin_comment
comment|// CHECK-VERSION-IOS3: "armv6k-apple-ios3.0.0"
end_comment

begin_comment
comment|// RUN: %clang -target i686-apple-darwin8 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX4 %s
end_comment

begin_comment
comment|// RUN: %clang -target i686-apple-darwin9 -mmacosx-version-min=10.4 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX4 %s
end_comment

begin_comment
comment|// CHECK-VERSION-OSX4: "i386-apple-macosx10.4.0"
end_comment

begin_comment
comment|// RUN: %clang -target i686-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX5 %s
end_comment

begin_comment
comment|// RUN: %clang -target i686-apple-darwin9 -mmacosx-version-min=10.5 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX5 %s
end_comment

begin_comment
comment|// CHECK-VERSION-OSX5: "i386-apple-macosx10.5.0"
end_comment

begin_comment
comment|// RUN: %clang -target i686-apple-darwin10 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX6 %s
end_comment

begin_comment
comment|// RUN: %clang -target i686-apple-darwin9 -mmacosx-version-min=10.6 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX6 %s
end_comment

begin_comment
comment|// CHECK-VERSION-OSX6: "i386-apple-macosx10.6.0"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin14 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX10 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx -mmacosx-version-min=10.10 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX10 %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx -mmacos-version-min=10.10 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX10 %s
end_comment

begin_comment
comment|// CHECK-VERSION-OSX10: "x86_64-apple-macosx10.10.0"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx -mmacosx-version-min= -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-MISSING %s
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-macosx -mmacos-version-min= -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-MISSING %s
end_comment

begin_comment
comment|// CHECK-VERSION-MISSING: invalid version number
end_comment

begin_comment
comment|// RUN: %clang -target armv7k-apple-darwin -mwatchos-version-min=2.0 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-WATCHOS20 %s
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-darwin -mtvos-version-min=8.3 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-TVOS83 %s
end_comment

begin_comment
comment|// CHECK-VERSION-TVOS83: "thumbv7-apple-tvos8.3.0"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin -mtvos-simulator-version-min=8.3 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-TVSIM83 %s
end_comment

begin_comment
comment|// CHECK-VERSION-TVSIM83: "i386-apple-tvos8.3.0"
end_comment

begin_comment
comment|// RUN: %clang -target armv7k-apple-darwin -mwatchos-version-min=2.0 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-WATCHOS20 %s
end_comment

begin_comment
comment|// CHECK-VERSION-WATCHOS20: "thumbv7k-apple-watchos2.0.0"
end_comment

begin_comment
comment|// RUN: %clang -target i386-apple-darwin -mwatchos-simulator-version-min=2.0 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-WATCHSIM20 %s
end_comment

begin_comment
comment|// CHECK-VERSION-WATCHSIM20: "i386-apple-watchos2.0.0"
end_comment

begin_comment
comment|// Check environment variable gets interpreted correctly
end_comment

begin_comment
comment|// RUN: env MACOSX_DEPLOYMENT_TARGET=10.5 IPHONEOS_DEPLOYMENT_TARGET=2.0 \
end_comment

begin_comment
comment|// RUN:   %clang -target i386-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX5 %s
end_comment

begin_comment
comment|// RUN: env MACOSX_DEPLOYMENT_TARGET=10.5 IPHONEOS_DEPLOYMENT_TARGET=2.0 \
end_comment

begin_comment
comment|// RUN:   %clang -target armv6-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-IOS2 %s
end_comment

begin_comment
comment|// RUN: env MACOSX_DEPLOYMENT_TARGET=10.4.10 \
end_comment

begin_comment
comment|// RUN:   %clang -target i386-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-OSX49 %s
end_comment

begin_comment
comment|// CHECK-VERSION-OSX49: "i386-apple-macosx10.4.10"
end_comment

begin_comment
comment|// RUN: env IPHONEOS_DEPLOYMENT_TARGET=2.3.1 \
end_comment

begin_comment
comment|// RUN:   %clang -target armv6-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-IOS231 %s
end_comment

begin_comment
comment|// CHECK-VERSION-IOS231: "armv6k-apple-ios2.3.1"
end_comment

begin_comment
comment|// RUN: env MACOSX_DEPLOYMENT_TARGET=10.5 TVOS_DEPLOYMENT_TARGET=8.3.1 \
end_comment

begin_comment
comment|// RUN:   %clang -target armv7-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-TVOS %s
end_comment

begin_comment
comment|// CHECK-VERSION-TVOS: "thumbv7-apple-tvos8.3.1"
end_comment

begin_comment
comment|// RUN: env TVOS_DEPLOYMENT_TARGET=8.3.1 \
end_comment

begin_comment
comment|// RUN:   %clang -target i386-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-TVOSSIM %s
end_comment

begin_comment
comment|// CHECK-VERSION-TVOSSIM: "i386-apple-tvos8.3.1"
end_comment

begin_comment
comment|// RUN: env MACOSX_DEPLOYMENT_TARGET=10.5 WATCHOS_DEPLOYMENT_TARGET=2.0 \
end_comment

begin_comment
comment|// RUN:   %clang -target armv7-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-WATCHOS %s
end_comment

begin_comment
comment|// CHECK-VERSION-WATCHOS: "thumbv7-apple-watchos2.0.0"
end_comment

begin_comment
comment|// RUN: env WATCHOS_DEPLOYMENT_TARGET=2.0 \
end_comment

begin_comment
comment|// RUN:   %clang -target i386-apple-darwin9 -c %s -### 2>&1 | \
end_comment

begin_comment
comment|// RUN:   FileCheck --check-prefix=CHECK-VERSION-WATCHOSSIM %s
end_comment

begin_comment
comment|// CHECK-VERSION-WATCHOSSIM: "i386-apple-watchos2.0.0"
end_comment

end_unit

