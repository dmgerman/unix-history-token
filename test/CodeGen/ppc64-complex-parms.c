begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function_decl
name|float
name|crealf
parameter_list|(
specifier|_Complex
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|creal
parameter_list|(
specifier|_Complex
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|creall
parameter_list|(
specifier|_Complex
name|long
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|float
name|foo_float
parameter_list|(
specifier|_Complex
name|float
name|x
parameter_list|)
block|{
return|return
name|crealf
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define float @foo_float(float {{[%A-Za-z0-9.]+}}, float {{[%A-Za-z0-9.]+}}) [[NUW:#[0-9]+]] {
end_comment

begin_function
name|double
name|foo_double
parameter_list|(
specifier|_Complex
name|double
name|x
parameter_list|)
block|{
return|return
name|creal
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define double @foo_double(double {{[%A-Za-z0-9.]+}}, double {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
name|long
name|double
name|foo_long_double
parameter_list|(
specifier|_Complex
name|long
name|double
name|x
parameter_list|)
block|{
return|return
name|creall
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define ppc_fp128 @foo_long_double(ppc_fp128 {{[%A-Za-z0-9.]+}}, ppc_fp128 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
name|int
name|foo_int
parameter_list|(
specifier|_Complex
name|int
name|x
parameter_list|)
block|{
return|return
name|__real__
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define signext i32 @foo_int(i32 {{[%A-Za-z0-9.]+}}, i32 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
name|short
name|foo_short
parameter_list|(
specifier|_Complex
name|short
name|x
parameter_list|)
block|{
return|return
name|__real__
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define signext i16 @foo_short(i16 {{[%A-Za-z0-9.]+}}, i16 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
name|signed
name|char
name|foo_char
parameter_list|(
specifier|_Complex
name|signed
name|char
name|x
parameter_list|)
block|{
return|return
name|__real__
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define signext i8 @foo_char(i8 {{[%A-Za-z0-9.]+}}, i8 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
name|long
name|foo_long
parameter_list|(
specifier|_Complex
name|long
name|x
parameter_list|)
block|{
return|return
name|__real__
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i64 @foo_long(i64 {{[%A-Za-z0-9.]+}}, i64 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
name|long
name|long
name|foo_long_long
parameter_list|(
specifier|_Complex
name|long
name|long
name|x
parameter_list|)
block|{
return|return
name|__real__
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i64 @foo_long_long(i64 {{[%A-Za-z0-9.]+}}, i64 {{[%A-Za-z0-9.]+}}) [[NUW]] {
end_comment

begin_function
name|void
name|bar_float
parameter_list|(
name|void
parameter_list|)
block|{
name|foo_float
argument_list|(
literal|2.0f
operator|-
literal|2.5fi
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bar_float() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: %[[VAR1:[A-Za-z0-9.]+]] = alloca { float, float }, align 4
end_comment

begin_comment
comment|// CHECK: %[[VAR2:[A-Za-z0-9.]+]] = getelementptr inbounds { float, float }, { float, float }* %[[VAR1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR3:[A-Za-z0-9.]+]] = getelementptr inbounds { float, float }, { float, float }* %[[VAR1]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: store float 2.000000e+00, float* %[[VAR2]]
end_comment

begin_comment
comment|// CHECK: store float -2.500000e+00, float* %[[VAR3]]
end_comment

begin_comment
comment|// CHECK: %[[VAR4:[A-Za-z0-9.]+]] = getelementptr inbounds { float, float }, { float, float }* %[[VAR1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR5:[A-Za-z0-9.]+]] = load float, float* %[[VAR4]], align 4
end_comment

begin_comment
comment|// CHECK: %[[VAR6:[A-Za-z0-9.]+]] = getelementptr inbounds { float, float }, { float, float }* %[[VAR1]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: %[[VAR7:[A-Za-z0-9.]+]] = load float, float* %[[VAR6]], align 4
end_comment

begin_comment
comment|// CHECK: %{{[A-Za-z0-9.]+}} = call float @foo_float(float %[[VAR5]], float %[[VAR7]])
end_comment

begin_function
name|void
name|bar_double
parameter_list|(
name|void
parameter_list|)
block|{
name|foo_double
argument_list|(
literal|2.0 - 2.5i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bar_double() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: %[[VAR11:[A-Za-z0-9.]+]] = alloca { double, double }, align 8
end_comment

begin_comment
comment|// CHECK: %[[VAR12:[A-Za-z0-9.]+]] = getelementptr inbounds { double, double }, { double, double }* %[[VAR11]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR13:[A-Za-z0-9.]+]] = getelementptr inbounds { double, double }, { double, double }* %[[VAR11]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: store double 2.000000e+00, double* %[[VAR12]]
end_comment

begin_comment
comment|// CHECK: store double -2.500000e+00, double* %[[VAR13]]
end_comment

begin_comment
comment|// CHECK: %[[VAR14:[A-Za-z0-9.]+]] = getelementptr inbounds { double, double }, { double, double }* %[[VAR11]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR15:[A-Za-z0-9.]+]] = load double, double* %[[VAR14]], align 8
end_comment

begin_comment
comment|// CHECK: %[[VAR16:[A-Za-z0-9.]+]] = getelementptr inbounds { double, double }, { double, double }* %[[VAR11]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: %[[VAR17:[A-Za-z0-9.]+]] = load double, double* %[[VAR16]], align 8
end_comment

begin_comment
comment|// CHECK: %{{[A-Za-z0-9.]+}} = call double @foo_double(double %[[VAR15]], double %[[VAR17]])
end_comment

begin_function
name|void
name|bar_long_double
parameter_list|(
name|void
parameter_list|)
block|{
name|foo_long_double
argument_list|(
literal|2.0L
operator|-
literal|2.5Li
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bar_long_double() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: %[[VAR21:[A-Za-z0-9.]+]] = alloca { ppc_fp128, ppc_fp128 }, align 16
end_comment

begin_comment
comment|// CHECK: %[[VAR22:[A-Za-z0-9.]+]] = getelementptr inbounds { ppc_fp128, ppc_fp128 }, { ppc_fp128, ppc_fp128 }* %[[VAR21]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR23:[A-Za-z0-9.]+]] = getelementptr inbounds { ppc_fp128, ppc_fp128 }, { ppc_fp128, ppc_fp128 }* %[[VAR21]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: store ppc_fp128 0xM40000000000000000000000000000000, ppc_fp128* %[[VAR22]]
end_comment

begin_comment
comment|// CHECK: store ppc_fp128 0xMC0040000000000008000000000000000, ppc_fp128* %[[VAR23]]
end_comment

begin_comment
comment|// CHECK: %[[VAR24:[A-Za-z0-9.]+]] = getelementptr inbounds { ppc_fp128, ppc_fp128 }, { ppc_fp128, ppc_fp128 }* %[[VAR21]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR25:[A-Za-z0-9.]+]] = load ppc_fp128, ppc_fp128* %[[VAR24]], align 16
end_comment

begin_comment
comment|// CHECK: %[[VAR26:[A-Za-z0-9.]+]] = getelementptr inbounds { ppc_fp128, ppc_fp128 }, { ppc_fp128, ppc_fp128 }* %[[VAR21]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: %[[VAR27:[A-Za-z0-9.]+]] = load ppc_fp128, ppc_fp128* %[[VAR26]], align 16
end_comment

begin_comment
comment|// CHECK: %{{[A-Za-z0-9.]+}} = call ppc_fp128 @foo_long_double(ppc_fp128 %[[VAR25]], ppc_fp128 %[[VAR27]])
end_comment

begin_function
name|void
name|bar_int
parameter_list|(
name|void
parameter_list|)
block|{
name|foo_int
argument_list|(
literal|2 - 3i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bar_int() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: %[[VAR31:[A-Za-z0-9.]+]] = alloca { i32, i32 }, align 4
end_comment

begin_comment
comment|// CHECK: %[[VAR32:[A-Za-z0-9.]+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* %[[VAR31]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR33:[A-Za-z0-9.]+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* %[[VAR31]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: store i32 2, i32* %[[VAR32]]
end_comment

begin_comment
comment|// CHECK: store i32 -3, i32* %[[VAR33]]
end_comment

begin_comment
comment|// CHECK: %[[VAR34:[A-Za-z0-9.]+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* %[[VAR31]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR35:[A-Za-z0-9.]+]] = load i32, i32* %[[VAR34]], align 4
end_comment

begin_comment
comment|// CHECK: %[[VAR36:[A-Za-z0-9.]+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* %[[VAR31]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: %[[VAR37:[A-Za-z0-9.]+]] = load i32, i32* %[[VAR36]], align 4
end_comment

begin_comment
comment|// CHECK: %{{[A-Za-z0-9.]+}} = call signext i32 @foo_int(i32 %[[VAR35]], i32 %[[VAR37]])
end_comment

begin_function
name|void
name|bar_short
parameter_list|(
name|void
parameter_list|)
block|{
name|foo_short
argument_list|(
literal|2 - 3i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bar_short() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: %[[VAR41:[A-Za-z0-9.]+]] = alloca { i16, i16 }, align 2
end_comment

begin_comment
comment|// CHECK: %[[VAR42:[A-Za-z0-9.]+]] = getelementptr inbounds { i16, i16 }, { i16, i16 }* %[[VAR41]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR43:[A-Za-z0-9.]+]] = getelementptr inbounds { i16, i16 }, { i16, i16 }* %[[VAR41]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: store i16 2, i16* %[[VAR42]]
end_comment

begin_comment
comment|// CHECK: store i16 -3, i16* %[[VAR43]]
end_comment

begin_comment
comment|// CHECK: %[[VAR44:[A-Za-z0-9.]+]] = getelementptr inbounds { i16, i16 }, { i16, i16 }* %[[VAR41]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR45:[A-Za-z0-9.]+]] = load i16, i16* %[[VAR44]], align 2
end_comment

begin_comment
comment|// CHECK: %[[VAR46:[A-Za-z0-9.]+]] = getelementptr inbounds { i16, i16 }, { i16, i16 }* %[[VAR41]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: %[[VAR47:[A-Za-z0-9.]+]] = load i16, i16* %[[VAR46]], align 2
end_comment

begin_comment
comment|// CHECK: %{{[A-Za-z0-9.]+}} = call signext i16 @foo_short(i16 %[[VAR45]], i16 %[[VAR47]])
end_comment

begin_function
name|void
name|bar_char
parameter_list|(
name|void
parameter_list|)
block|{
name|foo_char
argument_list|(
literal|2 - 3i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bar_char() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: %[[VAR51:[A-Za-z0-9.]+]] = alloca { i8, i8 }, align 1
end_comment

begin_comment
comment|// CHECK: %[[VAR52:[A-Za-z0-9.]+]] = getelementptr inbounds { i8, i8 }, { i8, i8 }* %[[VAR51]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR53:[A-Za-z0-9.]+]] = getelementptr inbounds { i8, i8 }, { i8, i8 }* %[[VAR51]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: store i8 2, i8* %[[VAR52]]
end_comment

begin_comment
comment|// CHECK: store i8 -3, i8* %[[VAR53]]
end_comment

begin_comment
comment|// CHECK: %[[VAR54:[A-Za-z0-9.]+]] = getelementptr inbounds { i8, i8 }, { i8, i8 }* %[[VAR51]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR55:[A-Za-z0-9.]+]] = load i8, i8* %[[VAR54]], align 1
end_comment

begin_comment
comment|// CHECK: %[[VAR56:[A-Za-z0-9.]+]] = getelementptr inbounds { i8, i8 }, { i8, i8 }* %[[VAR51]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: %[[VAR57:[A-Za-z0-9.]+]] = load i8, i8* %[[VAR56]], align 1
end_comment

begin_comment
comment|// CHECK: %{{[A-Za-z0-9.]+}} = call signext i8 @foo_char(i8 %[[VAR55]], i8 %[[VAR57]])
end_comment

begin_function
name|void
name|bar_long
parameter_list|(
name|void
parameter_list|)
block|{
name|foo_long
argument_list|(
literal|2L
operator|-
literal|3Li
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bar_long() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: %[[VAR61:[A-Za-z0-9.]+]] = alloca { i64, i64 }, align 8
end_comment

begin_comment
comment|// CHECK: %[[VAR62:[A-Za-z0-9.]+]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* %[[VAR61]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR63:[A-Za-z0-9.]+]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* %[[VAR61]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: store i64 2, i64* %[[VAR62]]
end_comment

begin_comment
comment|// CHECK: store i64 -3, i64* %[[VAR63]]
end_comment

begin_comment
comment|// CHECK: %[[VAR64:[A-Za-z0-9.]+]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* %[[VAR61]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR65:[A-Za-z0-9.]+]] = load i64, i64* %[[VAR64]], align 8
end_comment

begin_comment
comment|// CHECK: %[[VAR66:[A-Za-z0-9.]+]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* %[[VAR61]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: %[[VAR67:[A-Za-z0-9.]+]] = load i64, i64* %[[VAR66]], align 8
end_comment

begin_comment
comment|// CHECK: %{{[A-Za-z0-9.]+}} = call i64 @foo_long(i64 %[[VAR65]], i64 %[[VAR67]])
end_comment

begin_function
name|void
name|bar_long_long
parameter_list|(
name|void
parameter_list|)
block|{
name|foo_long_long
argument_list|(
literal|2LL
operator|-
literal|3LLi
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: define void @bar_long_long() [[NUW]] {
end_comment

begin_comment
comment|// CHECK: %[[VAR71:[A-Za-z0-9.]+]] = alloca { i64, i64 }, align 8
end_comment

begin_comment
comment|// CHECK: %[[VAR72:[A-Za-z0-9.]+]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* %[[VAR71]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR73:[A-Za-z0-9.]+]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* %[[VAR71]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: store i64 2, i64* %[[VAR72]]
end_comment

begin_comment
comment|// CHECK: store i64 -3, i64* %[[VAR73]]
end_comment

begin_comment
comment|// CHECK: %[[VAR74:[A-Za-z0-9.]+]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* %[[VAR71]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK: %[[VAR75:[A-Za-z0-9.]+]] = load i64, i64* %[[VAR74]], align 8
end_comment

begin_comment
comment|// CHECK: %[[VAR76:[A-Za-z0-9.]+]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* %[[VAR71]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK: %[[VAR77:[A-Za-z0-9.]+]] = load i64, i64* %[[VAR76]], align 8
end_comment

begin_comment
comment|// CHECK: %{{[A-Za-z0-9.]+}} = call i64 @foo_long_long(i64 %[[VAR75]], i64 %[[VAR77]])
end_comment

begin_comment
comment|// CHECK: attributes [[NUW]] = { noinline nounwind{{.*}} }
end_comment

end_unit

