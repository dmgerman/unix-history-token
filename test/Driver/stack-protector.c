begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fno-stack-protector -### %s 2>&1 | FileCheck %s -check-prefix=NOSSP
end_comment

begin_comment
comment|// NOSSP-NOT: "-stack-protector"
end_comment

begin_comment
comment|// NOSSP-NOT: "-stack-protector-buffer-size"
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux -fstack-protector -### %s 2>&1 | FileCheck %s -check-prefix=SSP
end_comment

begin_comment
comment|// SSP: "-stack-protector" "1"
end_comment

begin_comment
comment|// SSP-NOT: "-stack-protector-buffer-size"
end_comment

begin_comment
comment|// RUN: %clang -target i386-unknown-linux -fstack-protector --param ssp-buffer-size=16 -### %s 2>&1 | FileCheck %s -check-prefix=SSP-BUF
end_comment

begin_comment
comment|// SSP-BUF: "-stack-protector" "1"
end_comment

begin_comment
comment|// SSP-BUF: "-stack-protector-buffer-size" "16"
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-openbsd -### %s 2>&1 | FileCheck %s -check-prefix=OPENBSD
end_comment

begin_comment
comment|// OPENBSD: "-stack-protector" "2"
end_comment

begin_comment
comment|// RUN: %clang -target i386-pc-openbsd -fstack-protector -### %s 2>&1 | FileCheck %s -check-prefix=OPENBSD_SPS
end_comment

begin_comment
comment|// OPENBSD_SPS: "-stack-protector" "2"
end_comment

begin_comment
comment|// RUN: %clang -fstack-protector-strong -### %s 2>&1 | FileCheck %s -check-prefix=SSP-STRONG
end_comment

begin_comment
comment|// SSP-STRONG: "-stack-protector" "2"
end_comment

begin_comment
comment|// SSP-STRONG-NOT: "-stack-protector-buffer-size"
end_comment

begin_comment
comment|// RUN: %clang -fstack-protector-all -### %s 2>&1 | FileCheck %s -check-prefix=SSP-ALL
end_comment

begin_comment
comment|// SSP-ALL: "-stack-protector" "3"
end_comment

begin_comment
comment|// SSP-ALL-NOT: "-stack-protector-buffer-size"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -### %s 2>&1 | FileCheck %s -check-prefix=SSP-PS4
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fstack-protector -### %s 2>&1 | FileCheck %s -check-prefix=SSP-PS4
end_comment

begin_comment
comment|// SSP-PS4: "-stack-protector" "2"
end_comment

begin_comment
comment|// SSP-PS4-NOT: "-stack-protector-buffer-size"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-scei-ps4 -fstack-protector --param ssp-buffer-size=16 -### %s 2>&1 | FileCheck %s -check-prefix=SSP-PS4-BUF
end_comment

begin_comment
comment|// SSP-PS4-BUF: "-stack-protector" "2"
end_comment

begin_comment
comment|// SSP-PS4-BUF: "-stack-protector-buffer-size" "16"
end_comment

begin_comment
comment|// Test default stack protector values for Darwin platforms
end_comment

begin_comment
comment|// RUN: %clang -target armv7k-apple-watchos2.0 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_WATCHOS
end_comment

begin_comment
comment|// SSP_WATCHOS: "-stack-protector" "1"
end_comment

begin_comment
comment|// RUN: %clang -target arm64-apple-ios8.0.0 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_IOS
end_comment

begin_comment
comment|// SSP_IOS: "-stack-protector" "1"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mmacosx-version-min=10.6 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_MACOSX
end_comment

begin_comment
comment|// SSP_MACOSX: "-stack-protector" "1"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mmacosx-version-min=10.5 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_MACOSX_10_5
end_comment

begin_comment
comment|// SSP_MACOSX_10_5: "-stack-protector" "1"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mmacosx-version-min=10.5 -mkernel -### %s 2>&1 | FileCheck %s -check-prefix=SSP_MACOSX_KERNEL
end_comment

begin_comment
comment|// SSP_MACOSX_KERNEL-NOT: "-stack-protector"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -mmacosx-version-min=10.6 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_MACOSX_10_6_KERNEL
end_comment

begin_comment
comment|// SSP_MACOSX_10_6_KERNEL: "-stack-protector" "1"
end_comment

begin_comment
comment|// Test default stack protector values for Darwin platforms with -ffreestanding
end_comment

begin_comment
comment|// RUN: %clang -ffreestanding -target armv7k-apple-watchos2.0 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_FREE_WATCHOS
end_comment

begin_comment
comment|// SSP_FREE_WATCHOS-NOT: "-stack-protector"
end_comment

begin_comment
comment|// RUN: %clang -ffreestanding -target arm64-apple-ios8.0.0 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_FREE_IOS
end_comment

begin_comment
comment|// SSP_FREE_IOS-NOT: "-stack-protector"
end_comment

begin_comment
comment|// RUN: %clang -ffreestanding -target x86_64-apple-darwin10 -mmacosx-version-min=10.6 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_FREE_MACOSX
end_comment

begin_comment
comment|// SSP_FREE_MACOSX-NOT: "-stack-protector"
end_comment

begin_comment
comment|// RUN: %clang -ffreestanding -target x86_64-apple-darwin10 -mmacosx-version-min=10.5 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_FREE_MACOSX_10_5
end_comment

begin_comment
comment|// SSP_FREE_MACOSX_10_5-NOT: "-stack-protector"
end_comment

begin_comment
comment|// RUN: %clang -ffreestanding -target x86_64-apple-darwin10 -mmacosx-version-min=10.6 -### %s 2>&1 | FileCheck %s -check-prefix=SSP_FREE_MACOSX_10_6_KERNEL
end_comment

begin_comment
comment|// SSP_FREE_MACOSX_10_6_KERNEL-NOT: "-stack-protector"
end_comment

end_unit

