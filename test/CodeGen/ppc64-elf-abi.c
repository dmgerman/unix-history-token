begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// Verify ABI selection by the front end
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-ELFv1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   -target-abi elfv1 | FileCheck %s --check-prefix=CHECK-ELFv1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   -target-abi elfv2 | FileCheck %s --check-prefix=CHECK-ELFv2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-ELFv2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   -target-abi elfv1 | FileCheck %s --check-prefix=CHECK-ELFv1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:   -target-abi elfv2 | FileCheck %s --check-prefix=CHECK-ELFv2
end_comment

begin_comment
comment|// CHECK-ELFv1: define void @func_fab(%struct.fab* noalias sret %agg.result, i64 %x.coerce)
end_comment

begin_comment
comment|// CHECK-ELFv2: define [2 x float] @func_fab([2 x float] %x.coerce)
end_comment

begin_struct
struct|struct
name|fab
block|{
name|float
name|a
decl_stmt|;
name|float
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|fab
name|func_fab
parameter_list|(
name|struct
name|fab
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// Verify ABI choice is passed on to the back end
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -S -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-ASM-ELFv1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -S -o - %s \
end_comment

begin_comment
comment|// RUN:   -target-abi elfv1 | FileCheck %s --check-prefix=CHECK-ASM-ELFv1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -S -o - %s \
end_comment

begin_comment
comment|// RUN:   -target-abi elfv2 | FileCheck %s --check-prefix=CHECK-ASM-ELFv2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -S -o - %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK-ASM-ELFv2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -S -o - %s \
end_comment

begin_comment
comment|// RUN:   -target-abi elfv1 | FileCheck %s --check-prefix=CHECK-ASM-ELFv1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-linux-gnu -S -o - %s \
end_comment

begin_comment
comment|// RUN:   -target-abi elfv2 | FileCheck %s --check-prefix=CHECK-ASM-ELFv2
end_comment

begin_comment
comment|// CHECK-ASM-ELFv2: .abiversion 2
end_comment

begin_comment
comment|// CHECK-ASM-ELFv1-NOT: .abiversion 2
end_comment

end_unit

