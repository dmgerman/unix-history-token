begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabihf -target-cpu cortex-a8 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP3
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabi -target-cpu cortex-a9 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP3
end_comment

begin_comment
comment|// CHECK-VFP3: "target-features"="+neon,+vfp3"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabihf -target-cpu cortex-a5 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP4
end_comment

begin_comment
comment|// CHECK-VFP4: "target-features"="+vfp4,+neon"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabihf -target-cpu cortex-a7 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP4-DIV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabi -target-cpu cortex-a12 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP4-DIV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-linux-gnueabihf -target-cpu cortex-a15 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP4-DIV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-linux-gnueabihf -target-cpu cortex-a17 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP4-DIV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7s-linux-gnueabi -target-cpu swift -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP4-DIV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabihf -target-cpu krait -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-VFP4-DIV
end_comment

begin_comment
comment|// CHECK-VFP4-DIV: "target-features"="+vfp4,+neon,+hwdiv,+hwdiv-arm"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7s-apple-ios7.0 -target-cpu cyclone -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-BASIC-V8
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv8-linux-gnueabi -target-cpu cortex-a53 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-BASIC-V8
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv8-linux-gnueabihf -target-cpu cortex-a57 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-BASIC-V8
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv8-linux-gnueabihf -target-cpu cortex-a72 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-BASIC-V8
end_comment

begin_comment
comment|// CHECK-BASIC-V8: "target-features"="+neon,+fp-armv8,+hwdiv,+crypto,+crc,+hwdiv-arm"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabi -target-cpu cortex-r5 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-DIV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabi -target-cpu cortex-r7 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-DIV
end_comment

begin_comment
comment|// CHECK-DIV: "target-features"="+hwdiv,+hwdiv-arm"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-linux-gnueabi -target-cpu cortex-r4 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-THUMB-DIV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabi -target-cpu cortex-m3 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-THUMB-DIV
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-linux-gnueabi -target-cpu cortex-m4 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-THUMB-DIV
end_comment

begin_comment
comment|// CHECK-THUMB-DIV: "target-features"="+hwdiv"
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

end_unit

