begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.1.ast %S/Inputs/function1.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.2.ast %S/Inputs/function2.c
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -ast-merge %t.1.ast -ast-merge %t.2.ast -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ast-merge %t.1.ast -ast-merge %t.2.ast -fsyntax-only -verify %s
end_comment

begin_comment
comment|// CHECK: function2.c:3:6: error: external function 'f1' declared with incompatible types in different translation units ('void (Int, double)' vs. 'void (int, float)')
end_comment

begin_comment
comment|// CHECK: function1.c:2:6: note: declared here with type 'void (int, float)'
end_comment

begin_comment
comment|// CHECK: function2.c:5:6: error: external function 'f3' declared with incompatible types in different translation units ('void (int)' vs. 'void (void)')
end_comment

begin_comment
comment|// CHECK: function1.c:4:6: note: declared here with type 'void (void)'
end_comment

begin_comment
comment|// CHECK: 2 errors generated
end_comment

begin_comment
comment|// expected-error@Inputs/function2.c:3 {{external function 'f1' declared with incompatible types}}
end_comment

begin_comment
comment|// expected-note@Inputs/function1.c:2 {{declared here}}
end_comment

begin_comment
comment|// expected-error@Inputs/function2.c:5 {{external function 'f3' declared with incompatible types}}
end_comment

begin_comment
comment|// expected-note@Inputs/function1.c:4 {{declared here}}
end_comment

end_unit

