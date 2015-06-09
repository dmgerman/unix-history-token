begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.1.ast %S/Inputs/body1.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.2.ast %S/Inputs/body2.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-obj -o /dev/null -ast-merge %t.1.ast -ast-merge %t.2.ast %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

end_unit

