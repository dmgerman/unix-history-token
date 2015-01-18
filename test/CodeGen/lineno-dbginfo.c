begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: echo "#include<stddef.h>"> %t.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -g -include %t.h %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: !"0x34\00outer\00outer\00\00[[@LINE+1]]\000\001"
end_comment

begin_decl_stmt
name|int
name|outer
init|=
literal|42
decl_stmt|;
end_decl_stmt

end_unit

