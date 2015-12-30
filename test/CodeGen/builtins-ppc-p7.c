begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: powerpc-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-unknown -target-cpu pwr7 \
end_comment

begin_comment
comment|// RUN: -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-unknown-unknown -target-cpu pwr8 \
end_comment

begin_comment
comment|// RUN: -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: define signext i32 @test_divwe
end_comment

begin_function
name|int
name|test_divwe
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
init|=
literal|74
decl_stmt|;
name|int
name|b
init|=
literal|32
decl_stmt|;
return|return
name|__builtin_divwe
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.divwe
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define zeroext i32 @test_divweu
end_comment

begin_function
name|unsigned
name|int
name|test_divweu
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|int
name|a
init|=
literal|74
decl_stmt|;
name|unsigned
name|int
name|b
init|=
literal|32
decl_stmt|;
return|return
name|__builtin_divweu
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.divweu
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_divde
end_comment

begin_function
name|long
name|long
name|test_divde
parameter_list|(
name|void
parameter_list|)
block|{
name|long
name|long
name|a
init|=
literal|74LL
decl_stmt|;
name|long
name|long
name|b
init|=
literal|32LL
decl_stmt|;
return|return
name|__builtin_divde
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.divde
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_divdeu
end_comment

begin_function
name|unsigned
name|long
name|long
name|test_divdeu
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|long
name|long
name|a
init|=
literal|74ULL
decl_stmt|;
name|unsigned
name|long
name|long
name|b
init|=
literal|32ULL
decl_stmt|;
return|return
name|__builtin_divdeu
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.divdeu
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_bpermd
end_comment

begin_function
name|long
name|long
name|test_bpermd
parameter_list|(
name|void
parameter_list|)
block|{
name|long
name|long
name|a
init|=
literal|74LL
decl_stmt|;
name|long
name|long
name|b
init|=
literal|32LL
decl_stmt|;
return|return
name|__builtin_bpermd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: @llvm.ppc.bpermd
block|}
end_function

end_unit

