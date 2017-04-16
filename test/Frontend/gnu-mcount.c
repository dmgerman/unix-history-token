begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target,aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-none-eabi -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-none-eabi -pg -meabi gnu -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-MEABI-GNU
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-none-eabi -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-none-eabi -pg -meabi gnu -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-MEABI-GNU
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-linux-gnueabi -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-linux-gnueabi -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-MEABI-GNU
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-linux-gnueabi -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-LINUX
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-linux-gnueabi -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-MEABI-GNU
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-linux-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-linux-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-MEABI-GNU
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-linux-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-LINUX
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-linux-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-MEABI-GNU
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-freebsd-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-FREEBSD
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-freebsd-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-FREEBSD
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-freebsd-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-FREEBSD
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-freebsd-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-FREEBSD
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-openbsd-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-OPENBSD
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-openbsd-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-OPENBSD
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-openbsd-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-OPENBSD
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-openbsd-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-OPENBSD
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-netbsd-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-NETBSD
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-netbsd-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-NETBSD
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-netbsd-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-NETBSD
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-netbsd-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-NETBSD
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-IOS
end_comment

begin_comment
comment|// RUN: %clang -target armv7-apple-ios -pg -meabi gnu -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-IOS
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-ios -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-IOS
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-ios -pg -meabi gnu -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-IOS
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-bitrig-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-BIGRIG
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-bitrig-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-BIGRIG
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-bitrig-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-BITRIG
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-bitrig-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-BITRIG
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-rtems-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-RTEMS
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-rtems-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-RTEMS
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-rtems-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-RTEMS
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-rtems-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-RTEMS
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-cloudabi-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-CLOUDABI
end_comment

begin_comment
comment|// RUN: %clang -target armv7-unknown-cloudabi-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM-EABI-CLOUDABI
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-cloudabi-gnueabihf -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-CLOUDABI
end_comment

begin_comment
comment|// RUN: %clang -target aarch64-unknown-cloudabi-gnueabihf -meabi gnu -pg -S -emit-llvm -o - %s | FileCheck %s -check-prefix CHECK -check-prefix CHECK-ARM64-EABI-CLOUDABI
end_comment

begin_function
name|int
name|f
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: f
end_comment

begin_comment
comment|// CHECK-ARM-IOS-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="_mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-IOS-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-MEABI-GNU: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01_mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-LINUX: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01_mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-FREEBSD: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="__mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-FREEBSD-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-FREEBSD: attributes #{{[0-9]+}} = { {{.*}}"counting-function"=".mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-FREEBSD-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-NETBSD: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="_mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-NETBSD-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-OPENBSD: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="__mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-OPENBSD-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-OPENBSD: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="__mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-OPENBSD-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-MEABI-GNU-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-MEABI-GNU: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-BITRIG: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="__mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-BITRIG-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM54-EABI-BITRIG: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM54-EABI-BITRIG-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-RTEMS: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-RTEMS-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-RTEMS: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-RTEMS-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-CLOUDABI: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM-EABI-CLOUDABI-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-CLOUDABI: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="mcount"{{.*}} }
end_comment

begin_comment
comment|// CHECK-ARM64-EABI-CLOUDABI-NOT: attributes #{{[0-9]+}} = { {{.*}}"counting-function"="\01__gnu_mcount_nc"{{.*}} }
end_comment

end_unit

