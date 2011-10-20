begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-pch -o %t1 %S/Inputs/chain-trivial1.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-pch -o %t2 -include-pch %t1 %S/Inputs/chain-trivial2.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -ast-print -include-pch %t2 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: struct __va_list_tag {
end_comment

end_unit

