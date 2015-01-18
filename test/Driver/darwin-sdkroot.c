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
comment|// It doesn't make sense on msys bash.
end_comment

begin_comment
comment|// REQUIRES: shell-preserves-root
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This test will fail with MSYS env.exe, since it does not preserve root,
end_comment

begin_comment
comment|// expanding / into C:/MINGW/MSYS/1.0. To see the problem, from cmd.exe run:
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
comment|// This test passes using env.exe from GnuWin32.
end_comment

end_unit

