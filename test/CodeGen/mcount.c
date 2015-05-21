begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -pg -triple i386-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc-unknown-gnu-linux -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc64-unknown-gnu-linux -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc64le-unknown-gnu-linux -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple i386-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple x86_64-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple arm-netbsd-eabi -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple aarch64-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple mips-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc64-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple powerpc64le-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple sparc-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pg -triple sparc64-netbsd -emit-llvm -o - %s | FileCheck -check-prefix=CHECK-PREFIXED %s
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: call void @mcount()
comment|// CHECK-PREFIXED: call void @_mcount()
block|}
end_function

end_unit

