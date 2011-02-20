begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t1 -detailed-preprocessing-record %S/Inputs/chain-macro1.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t2 -detailed-preprocessing-record %S/Inputs/chain-macro2.h -include-pch %t1 -chained-pch
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -include-pch %t2 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ast-print -include-pch %t2 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: void f();
end_comment

begin_expr_stmt
name|FOOBAR
comment|// CHECK: void g();
name|BARFOO
end_expr_stmt

end_unit

