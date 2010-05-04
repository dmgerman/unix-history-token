begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fmath-errno -emit-llvm -o - %s -triple i386-unknown-unknown | FileCheck -check-prefix YES %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -triple i386-unknown-unknown | FileCheck -check-prefix NO %s
end_comment

begin_comment
comment|// CHECK-YES: define void @test_sqrt
end_comment

begin_comment
comment|// CHECK-NO: define void @test_sqrt
end_comment

begin_function
name|void
name|test_sqrt
parameter_list|(
name|float
name|a0
parameter_list|,
name|double
name|a1
parameter_list|,
name|long
name|double
name|a2
parameter_list|)
block|{
comment|// Following llvm-gcc's lead, we never emit these as intrinsics;
comment|// no-math-errno isn't good enough.  We could probably use intrinsics
comment|// with appropriate guards if it proves worthwhile.
comment|// CHECK-YES: call float @sqrtf
comment|// CHECK-NO: call float @sqrtf
name|float
name|l0
init|=
name|sqrtf
argument_list|(
name|a0
argument_list|)
decl_stmt|;
comment|// CHECK-YES: call double @sqrt
comment|// CHECK-NO: call double @sqrt
name|double
name|l1
init|=
name|sqrt
argument_list|(
name|a1
argument_list|)
decl_stmt|;
comment|// CHECK-YES: call x86_fp80 @sqrtl
comment|// CHECK-NO: call x86_fp80 @sqrtl
name|long
name|double
name|l2
init|=
name|sqrtl
argument_list|(
name|a2
argument_list|)
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-YES: declare float @sqrtf(float)
end_comment

begin_comment
comment|// CHECK-YES: declare double @sqrt(double)
end_comment

begin_comment
comment|// CHECK-YES: declare x86_fp80 @sqrtl(x86_fp80)
end_comment

begin_comment
comment|// CHECK-NO: declare float @sqrtf(float) readnone
end_comment

begin_comment
comment|// CHECK-NO: declare double @sqrt(double) readnone
end_comment

begin_comment
comment|// CHECK-NO: declare x86_fp80 @sqrtl(x86_fp80) readnone
end_comment

begin_comment
comment|// CHECK-YES: define void @test_pow
end_comment

begin_comment
comment|// CHECK-NO: define void @test_pow
end_comment

begin_function
name|void
name|test_pow
parameter_list|(
name|float
name|a0
parameter_list|,
name|double
name|a1
parameter_list|,
name|long
name|double
name|a2
parameter_list|)
block|{
comment|// CHECK-YES: call float @powf
comment|// CHECK-NO: call float @llvm.pow.f32
name|float
name|l0
init|=
name|powf
argument_list|(
name|a0
argument_list|,
name|a0
argument_list|)
decl_stmt|;
comment|// CHECK-YES: call double @pow
comment|// CHECK-NO: call double @llvm.pow.f64
name|double
name|l1
init|=
name|pow
argument_list|(
name|a1
argument_list|,
name|a1
argument_list|)
decl_stmt|;
comment|// CHECK-YES: call x86_fp80 @powl
comment|// CHECK-NO: call x86_fp80 @llvm.pow.f80
name|long
name|double
name|l2
init|=
name|powl
argument_list|(
name|a2
argument_list|,
name|a2
argument_list|)
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-YES: declare float @powf(float, float)
end_comment

begin_comment
comment|// CHECK-YES: declare double @pow(double, double)
end_comment

begin_comment
comment|// CHECK-YES: declare x86_fp80 @powl(x86_fp80, x86_fp80)
end_comment

begin_comment
comment|// CHECK-NO: declare float @llvm.pow.f32(float, float) nounwind readonly
end_comment

begin_comment
comment|// CHECK-NO: declare double @llvm.pow.f64(double, double) nounwind readonly
end_comment

begin_comment
comment|// CHECK-NO: declare x86_fp80 @llvm.pow.f80(x86_fp80, x86_fp80) nounwind readonly
end_comment

end_unit

