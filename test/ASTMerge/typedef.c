begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.1.ast %S/Inputs/typedef1.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.2.ast %S/Inputs/typedef2.c
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -ast-merge %t.1.ast -ast-merge %t.2.ast -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: typedef2.c:4:10: error: external variable 'x2' declared with incompatible types in different translation units ('Typedef2' (aka 'double') vs. 'Typedef2' (aka 'int'))
end_comment

begin_comment
comment|// CHECK: typedef1.c:4:10: note: declared here with type 'Typedef2' (aka 'int')
end_comment

begin_comment
comment|// CHECK: 1 error
end_comment

end_unit

