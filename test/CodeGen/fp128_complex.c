begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target aarch64-linux-gnuabi %s -O3 -S -emit-llvm -o - | FileCheck %s
end_comment

begin_decl_stmt
specifier|_Complex
name|long
name|double
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_fp128_compound_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK: tail call { fp128, fp128 } @__multc3
name|a
operator|*=
name|b
expr_stmt|;
comment|// CHECK: tail call { fp128, fp128 } @__divtc3
name|c
operator|/=
name|d
expr_stmt|;
block|}
end_function

end_unit

