begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fmath-errno -emit-llvm -o - %s -triple i386-unknown-unknown | FileCheck -check-prefix CHECK-YES %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s -triple i386-unknown-unknown | FileCheck -check-prefix CHECK-NO %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -menable-unsafe-fp-math -emit-llvm -o - %s -triple i386-unknown-unknown | FileCheck -check-prefix CHECK-FAST %s
end_comment

begin_comment
comment|// CHECK-YES-LABEL: define void @test_sqrt
end_comment

begin_comment
comment|// CHECK-NO-LABEL: define void @test_sqrt
end_comment

begin_comment
comment|// CHECK-FAST-LABEL: define void @test_sqrt
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
comment|// CHECK-NO: declare float @sqrtf(float) [[NUW_RN:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-NO: declare double @sqrt(double) [[NUW_RN]]
end_comment

begin_comment
comment|// CHECK-NO: declare x86_fp80 @sqrtl(x86_fp80) [[NUW_RN]]
end_comment

begin_comment
comment|// CHECK-FAST: declare float @llvm.sqrt.f32(float)
end_comment

begin_comment
comment|// CHECK-FAST: declare double @llvm.sqrt.f64(double)
end_comment

begin_comment
comment|// CHECK-FAST: declare x86_fp80 @llvm.sqrt.f80(x86_fp80)
end_comment

begin_comment
comment|// CHECK-YES-LABEL: define void @test_pow
end_comment

begin_comment
comment|// CHECK-NO-LABEL: define void @test_pow
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
comment|// CHECK-NO: declare float @llvm.pow.f32(float, float) [[NUW_RNI:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-NO: declare double @llvm.pow.f64(double, double) [[NUW_RNI]]
end_comment

begin_comment
comment|// CHECK-NO: declare x86_fp80 @llvm.pow.f80(x86_fp80, x86_fp80) [[NUW_RNI]]
end_comment

begin_comment
comment|// CHECK-YES-LABEL: define void @test_fma
end_comment

begin_comment
comment|// CHECK-NO-LABEL: define void @test_fma
end_comment

begin_function
name|void
name|test_fma
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
comment|// CHECK-YES: call float @llvm.fma.f32
comment|// CHECK-NO: call float @llvm.fma.f32
name|float
name|l0
init|=
name|fmaf
argument_list|(
name|a0
argument_list|,
name|a0
argument_list|,
name|a0
argument_list|)
decl_stmt|;
comment|// CHECK-YES: call double @llvm.fma.f64
comment|// CHECK-NO: call double @llvm.fma.f64
name|double
name|l1
init|=
name|fma
argument_list|(
name|a1
argument_list|,
name|a1
argument_list|,
name|a1
argument_list|)
decl_stmt|;
comment|// CHECK-YES: call x86_fp80 @llvm.fma.f80
comment|// CHECK-NO: call x86_fp80 @llvm.fma.f80
name|long
name|double
name|l2
init|=
name|fmal
argument_list|(
name|a2
argument_list|,
name|a2
argument_list|,
name|a2
argument_list|)
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-YES: declare float @llvm.fma.f32(float, float, float) [[NUW_RN:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-YES: declare double @llvm.fma.f64(double, double, double) [[NUW_RN]]
end_comment

begin_comment
comment|// CHECK-YES: declare x86_fp80 @llvm.fma.f80(x86_fp80, x86_fp80, x86_fp80) [[NUW_RN]]
end_comment

begin_comment
comment|// CHECK-NO: declare float @llvm.fma.f32(float, float, float) [[NUW_RN2:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK-NO: declare double @llvm.fma.f64(double, double, double) [[NUW_RN2]]
end_comment

begin_comment
comment|// CHECK-NO: declare x86_fp80 @llvm.fma.f80(x86_fp80, x86_fp80, x86_fp80) [[NUW_RN2]]
end_comment

begin_comment
comment|// Just checking to make sure these library functions are marked readnone
end_comment

begin_function
name|void
name|test_builtins
parameter_list|(
name|double
name|d
parameter_list|,
name|float
name|f
parameter_list|,
name|long
name|double
name|ld
parameter_list|)
block|{
comment|// CHECK-NO: @test_builtins
comment|// CHECK-YES: @test_builtins
name|double
name|atan_
init|=
name|atan
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|long
name|double
name|atanl_
init|=
name|atanl
argument_list|(
name|ld
argument_list|)
decl_stmt|;
name|float
name|atanf_
init|=
name|atanf
argument_list|(
name|f
argument_list|)
decl_stmt|;
comment|// CHECK-NO: declare double @atan(double) [[NUW_RN]]
comment|// CHECK-NO: declare x86_fp80 @atanl(x86_fp80) [[NUW_RN]]
comment|// CHECK-NO: declare float @atanf(float) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare double @atan(double) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare x86_fp80 @atanl(x86_fp80) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare float @atanf(float) [[NUW_RN]]
name|double
name|atan2_
init|=
name|atan2
argument_list|(
name|d
argument_list|,
literal|2
argument_list|)
decl_stmt|;
name|long
name|double
name|atan2l_
init|=
name|atan2l
argument_list|(
name|ld
argument_list|,
name|ld
argument_list|)
decl_stmt|;
name|float
name|atan2f_
init|=
name|atan2f
argument_list|(
name|f
argument_list|,
name|f
argument_list|)
decl_stmt|;
comment|// CHECK-NO: declare double @atan2(double, double) [[NUW_RN]]
comment|// CHECK-NO: declare x86_fp80 @atan2l(x86_fp80, x86_fp80) [[NUW_RN]]
comment|// CHECK-NO: declare float @atan2f(float, float) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare double @atan2(double, double) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare x86_fp80 @atan2l(x86_fp80, x86_fp80) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare float @atan2f(float, float) [[NUW_RN]]
name|double
name|exp_
init|=
name|exp
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|long
name|double
name|expl_
init|=
name|expl
argument_list|(
name|ld
argument_list|)
decl_stmt|;
name|float
name|expf_
init|=
name|expf
argument_list|(
name|f
argument_list|)
decl_stmt|;
comment|// CHECK-NO: declare double @exp(double) [[NUW_RN]]
comment|// CHECK-NO: declare x86_fp80 @expl(x86_fp80) [[NUW_RN]]
comment|// CHECK-NO: declare float @expf(float) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare double @exp(double) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare x86_fp80 @expl(x86_fp80) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare float @expf(float) [[NUW_RN]]
name|double
name|log_
init|=
name|log
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|long
name|double
name|logl_
init|=
name|logl
argument_list|(
name|ld
argument_list|)
decl_stmt|;
name|float
name|logf_
init|=
name|logf
argument_list|(
name|f
argument_list|)
decl_stmt|;
comment|// CHECK-NO: declare double @log(double) [[NUW_RN]]
comment|// CHECK-NO: declare x86_fp80 @logl(x86_fp80) [[NUW_RN]]
comment|// CHECK-NO: declare float @logf(float) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare double @log(double) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare x86_fp80 @logl(x86_fp80) [[NUW_RN]]
comment|// CHECK-YES-NOT: declare float @logf(float) [[NUW_RN]]
block|}
end_function

begin_comment
comment|// CHECK-YES: attributes [[NUW_RN]] = { nounwind readnone speculatable }
end_comment

begin_comment
comment|// CHECK-NO: attributes [[NUW_RN]] = { nounwind readnone{{.*}} }
end_comment

begin_comment
comment|// CHECK-NO: attributes [[NUW_RNI]] = { nounwind readnone speculatable }
end_comment

end_unit

