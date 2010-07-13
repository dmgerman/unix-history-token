begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -faltivec -triple powerpc-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @test0 = global<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_decl_stmt
name|vector
name|int
name|test0
init|=
call|(
name|vector
name|int
call|)
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

