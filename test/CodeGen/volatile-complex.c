begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Validate that volatile _Complex loads and stores are generated
end_comment

begin_comment
comment|// properly, including their alignment (even when overaligned).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This test assumes that floats are 32-bit aligned and doubles are
end_comment

begin_comment
comment|// 64-bit aligned, and uses x86-64 as a target that should have this
end_comment

begin_comment
comment|// property.
end_comment

begin_decl_stmt
specifier|volatile
specifier|_Complex
name|float
name|cf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
specifier|_Complex
name|double
name|cd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
specifier|_Complex
name|float
name|cf32
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
specifier|_Complex
name|double
name|cd32
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @test_cf()
end_comment

begin_function
name|void
name|test_cf
parameter_list|()
block|{
comment|// CHECK:      load volatile float* getelementptr inbounds ({ float, float }* @cf, i32 0, i32 0), align 4
comment|// CHECK-NEXT: load volatile float* getelementptr inbounds ({ float, float }* @cf, i32 0, i32 1), align 4
call|(
name|void
call|)
argument_list|(
name|cf
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[R:%.*]] = load volatile float* getelementptr inbounds ({ float, float }* @cf, i32 0, i32 0), align 4
comment|// CHECK-NEXT: [[I:%.*]] = load volatile float* getelementptr inbounds ({ float, float }* @cf, i32 0, i32 1), align 4
comment|// CHECK-NEXT: store volatile float [[R]], float* getelementptr inbounds ({ float, float }* @cf, i32 0, i32 0), align 4
comment|// CHECK-NEXT: store volatile float [[I]], float* getelementptr inbounds ({ float, float }* @cf, i32 0, i32 1), align 4
call|(
name|void
call|)
argument_list|(
name|cf
operator|=
name|cf
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cd()
end_comment

begin_function
name|void
name|test_cd
parameter_list|()
block|{
comment|// CHECK:      load volatile double* getelementptr inbounds ({ double, double }* @cd, i32 0, i32 0), align 8
comment|// CHECK-NEXT: load volatile double* getelementptr inbounds ({ double, double }* @cd, i32 0, i32 1), align 8
call|(
name|void
call|)
argument_list|(
name|cd
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[R:%.*]] = load volatile double* getelementptr inbounds ({ double, double }* @cd, i32 0, i32 0), align 8
comment|// CHECK-NEXT: [[I:%.*]] = load volatile double* getelementptr inbounds ({ double, double }* @cd, i32 0, i32 1), align 8
comment|// CHECK-NEXT: store volatile double [[R]], double* getelementptr inbounds ({ double, double }* @cd, i32 0, i32 0), align 8
comment|// CHECK-NEXT: store volatile double [[I]], double* getelementptr inbounds ({ double, double }* @cd, i32 0, i32 1), align 8
call|(
name|void
call|)
argument_list|(
name|cd
operator|=
name|cd
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cf32()
end_comment

begin_function
name|void
name|test_cf32
parameter_list|()
block|{
comment|// CHECK:      load volatile float* getelementptr inbounds ({ float, float }* @cf32, i32 0, i32 0), align 32
comment|// CHECK-NEXT: load volatile float* getelementptr inbounds ({ float, float }* @cf32, i32 0, i32 1), align 4
call|(
name|void
call|)
argument_list|(
name|cf32
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[R:%.*]] = load volatile float* getelementptr inbounds ({ float, float }* @cf32, i32 0, i32 0), align 32
comment|// CHECK-NEXT: [[I:%.*]] = load volatile float* getelementptr inbounds ({ float, float }* @cf32, i32 0, i32 1), align 4
comment|// CHECK-NEXT: store volatile float [[R]], float* getelementptr inbounds ({ float, float }* @cf32, i32 0, i32 0), align 32
comment|// CHECK-NEXT: store volatile float [[I]], float* getelementptr inbounds ({ float, float }* @cf32, i32 0, i32 1), align 4
call|(
name|void
call|)
argument_list|(
name|cf32
operator|=
name|cf32
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cd32()
end_comment

begin_function
name|void
name|test_cd32
parameter_list|()
block|{
comment|// CHECK:      load volatile double* getelementptr inbounds ({ double, double }* @cd32, i32 0, i32 0), align 32
comment|// CHECK-NEXT: load volatile double* getelementptr inbounds ({ double, double }* @cd32, i32 0, i32 1), align 8
call|(
name|void
call|)
argument_list|(
name|cd32
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: [[R:%.*]] = load volatile double* getelementptr inbounds ({ double, double }* @cd32, i32 0, i32 0), align 32
comment|// CHECK-NEXT: [[I:%.*]] = load volatile double* getelementptr inbounds ({ double, double }* @cd32, i32 0, i32 1), align 8
comment|// CHECK-NEXT: store volatile double [[R]], double* getelementptr inbounds ({ double, double }* @cd32, i32 0, i32 0), align 32
comment|// CHECK-NEXT: store volatile double [[I]], double* getelementptr inbounds ({ double, double }* @cd32, i32 0, i32 1), align 8
call|(
name|void
call|)
argument_list|(
name|cd32
operator|=
name|cd32
argument_list|)
expr_stmt|;
comment|// CHECK-NEXT: ret void
block|}
end_function

end_unit

