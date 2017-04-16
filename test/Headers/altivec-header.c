begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-unknown -target-feature +altivec -ffreestanding -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-unknown -target-feature +altivec -ffreestanding -emit-llvm -fno-lax-vector-conversions -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-unknown -target-feature +altivec -ffreestanding -emit-llvm -x c++ -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<altivec.h>
end_include

begin_comment
comment|// Verify that simply including<altivec.h> does not generate any code
end_comment

begin_comment
comment|// (i.e. all inline routines in the header are marked "static")
end_comment

begin_comment
comment|// CHECK: target triple = "powerpc64-
end_comment

begin_comment
comment|// CHECK-NEXT: {{^$}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{llvm\..*}}
end_comment

end_unit

