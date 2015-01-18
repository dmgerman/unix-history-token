begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-unknown -faltivec -ffreestanding -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-unknown -faltivec -ffreestanding -fno-lax-vector-conversions -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-unknown -faltivec -ffreestanding -x c++ -S -o - %s | FileCheck %s
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
comment|// CHECK: .text
end_comment

begin_comment
comment|// CHECK-NEXT: .file
end_comment

begin_comment
comment|// CHECK-NEXT: {{^$}}
end_comment

begin_comment
comment|// CHECK-NEXT: .ident{{.*$}}
end_comment

begin_comment
comment|// CHECK-NEXT: .section ".note.GNU-stack","",@progbits
end_comment

begin_comment
comment|// CHECK-NOT: .
end_comment

end_unit

