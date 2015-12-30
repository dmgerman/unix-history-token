begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: echo "#include<stddef.h>"> %t.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -debug-info-kind=limited -include %t.h %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !DIGlobalVariable(name: "outer",
end_comment

begin_comment
comment|// CHECK-NOT:               linkageName:
end_comment

begin_comment
comment|// CHECK-SAME:              line: [[@LINE+2]]
end_comment

begin_comment
comment|// CHECK-SAME:              isDefinition: true
end_comment

begin_decl_stmt
name|int
name|outer
init|=
literal|42
decl_stmt|;
end_decl_stmt

end_unit

