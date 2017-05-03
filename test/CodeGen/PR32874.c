begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c -S -emit-llvm -o - -triple x86_64-apple-darwin10 %s \
end_comment

begin_comment
comment|// RUN:   -w -fsanitize=signed-integer-overflow,unsigned-integer-overflow,integer-divide-by-zero,float-divide-by-zero \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define void @foo
end_comment

begin_comment
comment|// CHECK-NOT: !nosanitize
end_comment

begin_function
name|void
name|foo
parameter_list|(
specifier|const
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// __builtin_prefetch expects its optional arguments to be constant integers.
comment|// Check that ubsan does not instrument any safe arithmetic performed in
comment|// operands to __builtin_prefetch. (A clang frontend check should reject
comment|// unsafe arithmetic in these operands.)
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|0
operator|+
literal|1
argument_list|,
literal|0
operator|+
literal|3
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|1
operator|-
literal|0
argument_list|,
literal|3
operator|-
literal|0
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|1
operator|*
literal|1
argument_list|,
literal|1
operator|*
literal|3
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|1
operator|/
literal|1
argument_list|,
literal|3
operator|/
literal|1
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|3
operator|%
literal|2
argument_list|,
literal|3
operator|%
literal|1
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|0U
operator|+
literal|1U
argument_list|,
literal|0U
operator|+
literal|3U
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|1U
operator|-
literal|0U
argument_list|,
literal|3U
operator|-
literal|0U
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|1U
operator|*
literal|1U
argument_list|,
literal|1U
operator|*
literal|3U
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|1U
operator|/
literal|1U
argument_list|,
literal|3U
operator|/
literal|1U
argument_list|)
expr_stmt|;
name|__builtin_prefetch
argument_list|(
name|p
argument_list|,
literal|3U
operator|%
literal|2U
argument_list|,
literal|3U
operator|%
literal|1U
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @ub_constant_arithmetic
end_comment

begin_function
name|void
name|ub_constant_arithmetic
parameter_list|()
block|{
comment|// Check that we still instrument unsafe arithmetic, even if it is known to
comment|// be unsafe at compile time.
name|int
name|INT_MIN
init|=
literal|0xffffffff
decl_stmt|;
name|int
name|INT_MAX
init|=
literal|0x7fffffff
decl_stmt|;
comment|// CHECK: call void @__ubsan_handle_add_overflow
comment|// CHECK: call void @__ubsan_handle_add_overflow
name|INT_MAX
operator|+
literal|1
expr_stmt|;
name|INT_MAX
operator|+
operator|-
literal|1
expr_stmt|;
comment|// CHECK: call void @__ubsan_handle_negate_overflow
comment|// CHECK: call void @__ubsan_handle_sub_overflow
operator|-
name|INT_MIN
expr_stmt|;
operator|-
name|INT_MAX
operator|-
literal|2
expr_stmt|;
comment|// CHECK: call void @__ubsan_handle_mul_overflow
comment|// CHECK: call void @__ubsan_handle_mul_overflow
name|INT_MAX
modifier|*
name|INT_MAX
decl_stmt|;
name|INT_MIN
modifier|*
name|INT_MIN
decl_stmt|;
comment|// CHECK: call void @__ubsan_handle_divrem_overflow
comment|// CHECK: call void @__ubsan_handle_divrem_overflow
literal|1
operator|/
literal|0
expr_stmt|;
name|INT_MIN
operator|/
operator|-
literal|1
expr_stmt|;
comment|// CHECK: call void @__ubsan_handle_divrem_overflow
comment|// CHECK: call void @__ubsan_handle_divrem_overflow
literal|1
operator|%
literal|0
expr_stmt|;
name|INT_MIN
operator|%
operator|-
literal|1
expr_stmt|;
comment|// CHECK: call void @__ubsan_handle_divrem_overflow
literal|1.0
operator|/
literal|0.0
expr_stmt|;
block|}
end_function

end_unit

