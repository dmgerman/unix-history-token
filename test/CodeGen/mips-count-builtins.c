begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple mips-unknown-linux-gnu -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Test that the ctlz and cttz builtins are defined for zero.
end_comment

begin_comment
comment|// Based on count-builtin.c
end_comment

begin_decl_stmt
name|int
name|leading
decl_stmt|,
name|trailing
decl_stmt|,
name|pop
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_i16
parameter_list|(
name|short
name|P
parameter_list|)
block|{
name|leading
operator|=
name|__builtin_clzs
argument_list|(
name|P
argument_list|)
expr_stmt|;
name|trailing
operator|=
name|__builtin_ctzs
argument_list|(
name|P
argument_list|)
expr_stmt|;
comment|// CHECK: @test_i16
comment|// CHECK: call i16 @llvm.ctlz.i16(i16 {{.*}}, i1 false)
comment|// CHECK: call i16 @llvm.cttz.i16(i16 {{.*}}, i1 false)
block|}
end_function

begin_function
name|void
name|test_i32
parameter_list|(
name|int
name|P
parameter_list|)
block|{
name|leading
operator|=
name|__builtin_clz
argument_list|(
name|P
argument_list|)
expr_stmt|;
name|trailing
operator|=
name|__builtin_ctz
argument_list|(
name|P
argument_list|)
expr_stmt|;
comment|// CHECK: @test_i32
comment|// CHECK: call i32 @llvm.ctlz.i32(i32 {{.*}}, i1 false)
comment|// CHECK: call i32 @llvm.cttz.i32(i32 {{.*}}, i1 false)
block|}
end_function

begin_function
name|void
name|test_i64
parameter_list|(
name|float
name|P
parameter_list|)
block|{
name|leading
operator|=
name|__builtin_clzll
argument_list|(
name|P
argument_list|)
expr_stmt|;
name|trailing
operator|=
name|__builtin_ctzll
argument_list|(
name|P
argument_list|)
expr_stmt|;
comment|// CHECK: @test_i64
comment|// CHECK: call i64 @llvm.ctlz.i64(i64 {{.*}}, i1 false)
comment|// CHECK: call i64 @llvm.cttz.i64(i64 {{.*}}, i1 false)
block|}
end_function

end_unit

