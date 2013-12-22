begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -include %S/pragma-weak.h %s -verify -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x c-header -emit-pch -o %t %S/pragma-weak.h
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -include-pch %t %s -verify -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @weakvar = weak global i32 0
end_comment

begin_decl_stmt
name|int
name|weakvar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{weak identifier 'undeclaredvar' never declared}}
end_comment

end_unit

