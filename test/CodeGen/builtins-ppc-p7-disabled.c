begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple powerpc64-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -target-cpu pwr6 -emit-llvm %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple powerpc-unknown-unknown -emit-llvm %s -o - 2>&1 \
end_comment

begin_comment
comment|// RUN: -target-cpu pwr7 | FileCheck %s -check-prefix=CHECK-32
end_comment

begin_function
name|void
name|call_p7_builtins
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
init|=
name|__builtin_divwe
argument_list|(
literal|33
argument_list|,
literal|11
argument_list|)
decl_stmt|;
name|unsigned
name|int
name|b
init|=
name|__builtin_divweu
argument_list|(
literal|33U
argument_list|,
literal|11U
argument_list|)
decl_stmt|;
name|unsigned
name|long
name|long
name|d
init|=
name|__builtin_divde
argument_list|(
literal|33ULL
argument_list|,
literal|11ULL
argument_list|)
decl_stmt|;
name|unsigned
name|long
name|long
name|e
init|=
name|__builtin_divdeu
argument_list|(
literal|33ULL
argument_list|,
literal|11ULL
argument_list|)
decl_stmt|;
name|unsigned
name|long
name|long
name|f
init|=
name|__builtin_bpermd
argument_list|(
literal|33ULL
argument_list|,
literal|11ULL
argument_list|)
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: error: this builtin is only valid on POWER7 or later CPUs
end_comment

begin_comment
comment|// CHECK: __builtin_divwe
end_comment

begin_comment
comment|// CHECK: error: this builtin is only valid on POWER7 or later CPUs
end_comment

begin_comment
comment|// CHECK: __builtin_divweu
end_comment

begin_comment
comment|// CHECK: error: this builtin is only valid on POWER7 or later CPUs
end_comment

begin_comment
comment|// CHECK: __builtin_divde
end_comment

begin_comment
comment|// CHECK: error: this builtin is only valid on POWER7 or later CPUs
end_comment

begin_comment
comment|// CHECK: __builtin_divdeu
end_comment

begin_comment
comment|// CHECK: error: this builtin is only valid on POWER7 or later CPUs
end_comment

begin_comment
comment|// CHECK: __builtin_bpermd
end_comment

begin_comment
comment|// CHECK-32: error: this builtin is only available on 64-bit targets
end_comment

begin_comment
comment|// CHECK-32: __builtin_divde
end_comment

begin_comment
comment|// CHECK-32: error: this builtin is only available on 64-bit targets
end_comment

begin_comment
comment|// CHECK-32: __builtin_divdeu
end_comment

begin_comment
comment|// CHECK-32: error: this builtin is only available on 64-bit targets
end_comment

begin_comment
comment|// CHECK-32: __builtin_bpermd
end_comment

end_unit

