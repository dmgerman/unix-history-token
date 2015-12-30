begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that SDKROOT is used to define the default for -isysroot on Darwin.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -rf %t.tmpdir
end_comment

begin_comment
comment|// RUN: mkdir -p %t.tmpdir
end_comment

begin_comment
comment|// RUN: env SDKROOT=%t.tmpdir %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -c %s -### 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-BASIC< %t.log %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-BASIC: clang
end_comment

begin_comment
comment|// CHECK-BASIC: "-cc1"
end_comment

begin_comment
comment|// CHECK-BASIC: "-isysroot" "{{.*tmpdir}}"
end_comment

begin_comment
comment|// Check that we don't use SDKROOT as the default if it is not a valid path.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -rf %t.nonpath
end_comment

begin_comment
comment|// RUN: env SDKROOT=%t.nonpath %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -c %s -### 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NONPATH< %t.log %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NONPATH: clang
end_comment

begin_comment
comment|// CHECK-NONPATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-NONPATH-NOT: "-isysroot"
end_comment

begin_comment
comment|// Check that we don't use SDKROOT as the default if it is just "/"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: env SDKROOT=/ %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -c %s -### 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NONROOT< %t.log %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NONROOT: clang
end_comment

begin_comment
comment|// CHECK-NONROOT: "-cc1"
end_comment

begin_comment
comment|// CHECK-NONROOT-NOT: "-isysroot"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This test fails with MSYS or MSYS2 env.exe, since it does not preserve
end_comment

begin_comment
comment|// root, expanding / into C:/MINGW/MSYS/1.0 or c:/msys64. To reproduce the
end_comment

begin_comment
comment|// problem, run:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   env SDKROOT=/ cmd //c echo %SDKROOT%
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This test do pass using GnuWin32 env.exe.
end_comment

begin_comment
comment|// Check if clang set the correct deployment target from -sysroot
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -rf %t/SDKs/iPhoneOS8.0.0.sdk
end_comment

begin_comment
comment|// RUN: mkdir -p %t/SDKs/iPhoneOS8.0.0.sdk
end_comment

begin_comment
comment|// RUN: env SDKROOT=%t/SDKs/iPhoneOS8.0.0.sdk %clang -target arm64-apple-darwin %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-IPHONE %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-IPHONE: clang
end_comment

begin_comment
comment|// CHECK-IPHONE: "-cc1"
end_comment

begin_comment
comment|// CHECK-IPHONE: "-triple" "arm64-apple-ios8.0.0"
end_comment

begin_comment
comment|// CHECK-IPHONE: ld
end_comment

begin_comment
comment|// CHECK-IPHONE: "-iphoneos_version_min" "8.0.0"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -rf %t/SDKs/iPhoneSimulator8.0.sdk
end_comment

begin_comment
comment|// RUN: mkdir -p %t/SDKs/iPhoneSimulator8.0.sdk
end_comment

begin_comment
comment|// RUN: env SDKROOT=%t/SDKs/iPhoneSimulator8.0.sdk %clang -target x86_64-apple-darwin %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-SIMULATOR %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-SIMULATOR: clang
end_comment

begin_comment
comment|// CHECK-SIMULATOR: "-cc1"
end_comment

begin_comment
comment|// CHECK-SIMULATOR: "-triple" "x86_64-apple-ios8.0.0"
end_comment

begin_comment
comment|// CHECK-SIMULATOR: ld
end_comment

begin_comment
comment|// CHECK-SIMULATOR: "-ios_simulator_version_min" "8.0.0"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -rf %t/SDKs/MacOSX10.10.0.sdk
end_comment

begin_comment
comment|// RUN: mkdir -p %t/SDKs/MacOSX10.10.0.sdk
end_comment

begin_comment
comment|// RUN: env SDKROOT=%t/SDKs/MacOSX10.10.0.sdk %clang -target x86_64-apple-darwin %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MACOSX %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-MACOSX: clang
end_comment

begin_comment
comment|// CHECK-MACOSX: "-cc1"
end_comment

begin_comment
comment|// CHECK-MACOSX: "-triple" "x86_64-apple-macosx10.10.0"
end_comment

begin_comment
comment|// CHECK-MACOSX: ld
end_comment

begin_comment
comment|// CHECK-MACOSX: "-macosx_version_min" "10.10.0"
end_comment

end_unit

