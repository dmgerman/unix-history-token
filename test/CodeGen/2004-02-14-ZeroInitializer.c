begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1  %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: zeroinitializer
end_comment

begin_decl_stmt
name|int
name|X
index|[
literal|1000
index|]
decl_stmt|;
end_decl_stmt

end_unit

