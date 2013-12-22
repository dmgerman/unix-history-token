begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -dump-tokens %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -dump-tokens -x assembler-with-cpp %s 2>&1 | FileCheck %s --check-prefix=CHECK-ASM
end_comment

begin_comment
comment|// PR3808
end_comment

begin_comment
comment|// CHECK: identifier '$A'
end_comment

begin_comment
comment|// CHECK-ASM: identifier 'A'
end_comment

begin_macro
name|$A
end_macro

end_unit

