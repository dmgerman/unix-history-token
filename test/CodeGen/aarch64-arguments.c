begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -emit-llvm -w -o - %s | FileCheck -check-prefix=PCS %s
end_comment

begin_comment
comment|// Sign extension is performed by the callee on AArch64, which means
end_comment

begin_comment
comment|// that we *shouldn't* tag arguments and returns with their extension.
end_comment

begin_comment
comment|// PCS-LABEL: define i8 @f0(i16 %a)
end_comment

begin_function
name|char
name|f0
parameter_list|(
name|short
name|a
parameter_list|)
block|{
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f1()
end_comment

begin_struct
struct|struct
name|s1
block|{
name|char
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s1
name|f1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f2()
end_comment

begin_struct
struct|struct
name|s2
block|{
name|short
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s2
name|f2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f3()
end_comment

begin_struct
struct|struct
name|s3
block|{
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s3
name|f3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f4()
end_comment

begin_struct
struct|struct
name|s4
block|{
struct|struct
name|s4_0
block|{
name|int
name|f0
decl_stmt|;
block|}
name|f0
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s4
name|f4
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f5()
end_comment

begin_struct
struct|struct
name|s5
block|{
struct|struct
block|{ }
name|f0
struct|;
name|int
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s5
name|f5
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define  [1 x i64] @f6()
end_comment

begin_struct
struct|struct
name|s6
block|{
name|int
name|f0
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s6
name|f6
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define void @f7()
end_comment

begin_struct
struct|struct
name|s7
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|f0
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s7
name|f7
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define  void @f8()
end_comment

begin_struct
struct|struct
name|s8
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|f0
index|[
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s8
name|f8
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f9()
end_comment

begin_struct
struct|struct
name|s9
block|{
name|long
name|f0
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s9
name|f9
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f10()
end_comment

begin_struct
struct|struct
name|s10
block|{
name|long
name|f0
decl_stmt|;
name|int
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s10
name|f10
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f11()
end_comment

begin_struct
struct|struct
name|s11
block|{
name|int
label|:
literal|0
expr_stmt|;
name|long
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s11
name|f11
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f12()
end_comment

begin_union
union|union
name|u12
block|{
name|char
name|f0
decl_stmt|;
name|short
name|f1
decl_stmt|;
name|int
name|f2
decl_stmt|;
name|long
name|f3
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|u12
name|f12
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define %struct.s13 @f13()
end_comment

begin_struct
struct|struct
name|s13
block|{
name|float
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s13
name|f13
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define %union.u14 @f14()
end_comment

begin_union
union|union
name|u14
block|{
name|float
name|f0
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|u14
name|f14
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define void @f15()
end_comment

begin_function
name|void
name|f15
parameter_list|(
name|struct
name|s7
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define void @f16()
end_comment

begin_function
name|void
name|f16
parameter_list|(
name|struct
name|s8
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f17()
end_comment

begin_struct
struct|struct
name|s17
block|{
name|short
name|f0
range|:
literal|13
decl_stmt|;
name|char
name|f1
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s17
name|f17
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f18()
end_comment

begin_struct
struct|struct
name|s18
block|{
name|short
name|f0
decl_stmt|;
name|char
name|f1
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s18
name|f18
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f19()
end_comment

begin_struct
struct|struct
name|s19
block|{
name|long
name|f0
decl_stmt|;
name|struct
name|s8
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s19
name|f19
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f20()
end_comment

begin_struct
struct|struct
name|s20
block|{
name|struct
name|s8
name|f1
decl_stmt|;
name|long
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s20
name|f20
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f21()
end_comment

begin_struct
struct|struct
name|s21
block|{
struct|struct
block|{}
name|f1
struct|;
name|long
name|f0
range|:
literal|4
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s21
name|f21
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define { float, float } @f22()
end_comment

begin_comment
comment|// PCS: define { double, double } @f23(
end_comment

begin_function
specifier|_Complex
name|float
name|f22
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
specifier|_Complex
name|double
name|f23
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f24()
end_comment

begin_struct
struct|struct
name|s24
block|{
specifier|_Complex
name|char
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s24
name|f24
parameter_list|()
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f25()
end_comment

begin_struct
struct|struct
name|s25
block|{
specifier|_Complex
name|short
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s25
name|f25
parameter_list|()
block|{}
end_function

begin_comment
comment|// PCS: define [1 x i64] @f26()
end_comment

begin_struct
struct|struct
name|s26
block|{
specifier|_Complex
name|int
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s26
name|f26
parameter_list|()
block|{}
end_function

begin_comment
comment|// PCS: define [2 x i64] @f27()
end_comment

begin_struct
struct|struct
name|s27
block|{
specifier|_Complex
name|long
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s27
name|f27
parameter_list|()
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define void @f28(i8 %a, i16 %b, i32 %c, i64 %d, float %e, double %f)
end_comment

begin_function
name|void
name|f28
parameter_list|(
name|char
name|a
parameter_list|,
name|short
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|long
name|d
parameter_list|,
name|float
name|e
parameter_list|,
name|double
name|f
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define void @f29([2 x i64] %a
end_comment

begin_struct
struct|struct
name|s29
block|{
name|int
name|arr
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f29
parameter_list|(
name|struct
name|s29
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define void @f30(%struct.s30* %a)
end_comment

begin_struct
struct|struct
name|s30
block|{
name|int
name|arr
index|[
literal|4
index|]
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f30
parameter_list|(
name|struct
name|s30
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS: define void @f31([4 x double] %a
end_comment

begin_struct
struct|struct
name|s31
block|{
name|double
name|arr
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f31
parameter_list|(
name|struct
name|s31
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define void @f32(%struct.s32* %a)
end_comment

begin_struct
struct|struct
name|s32
block|{
name|float
name|arr
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f32
parameter_list|(
name|struct
name|s32
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// Not the only solution, but it *is* an HFA.
end_comment

begin_comment
comment|// PCS: define void @f33([3 x float] %a.coerce0, float %a.coerce1)
end_comment

begin_struct
struct|struct
name|s33
block|{
name|float
name|arr
index|[
literal|3
index|]
decl_stmt|;
name|float
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f33
parameter_list|(
name|struct
name|s33
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define void @f34(%struct.s34* noalias sret
end_comment

begin_struct
struct|struct
name|s34
block|{
name|int
name|a
index|[
literal|4
index|]
decl_stmt|;
name|char
name|b
block|}
struct|;
end_struct

begin_function
name|struct
name|s34
name|f34
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// PCS-LABEL: define void @f35()
end_comment

begin_struct
struct|struct
name|s35
block|{}
struct|;
end_struct

begin_function
name|void
name|f35
parameter_list|(
name|struct
name|s35
name|a
parameter_list|)
block|{}
end_function

begin_comment
comment|// Check padding is added:
end_comment

begin_comment
comment|// PCS: @f36(i32 %x0, i32 %x1, i32 %x2, i32 %x3, i32 %x4, i32 %x5, i32 %x6, [1 x i64], %struct.s36* byval align 8 %stacked)
end_comment

begin_struct
struct|struct
name|s36
block|{
name|long
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f36
parameter_list|(
name|int
name|x0
parameter_list|,
name|int
name|x1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|x3
parameter_list|,
name|int
name|x4
parameter_list|,
name|int
name|x5
parameter_list|,
name|int
name|x6
parameter_list|,
name|struct
name|s36
name|stacked
parameter_list|)
block|{}
end_function

begin_comment
comment|// But only once:
end_comment

begin_comment
comment|// PCS: @f37(i32 %x0, i32 %x1, i32 %x2, i32 %x3, i32 %x4, i32 %x5, i32 %x6, [1 x i64], %struct.s37* byval align 8 %stacked, %struct.s37* byval align 8 %stacked2)
end_comment

begin_struct
struct|struct
name|s37
block|{
name|long
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f37
parameter_list|(
name|int
name|x0
parameter_list|,
name|int
name|x1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|x3
parameter_list|,
name|int
name|x4
parameter_list|,
name|int
name|x5
parameter_list|,
name|int
name|x6
parameter_list|,
name|struct
name|s37
name|stacked
parameter_list|,
name|struct
name|s37
name|stacked2
parameter_list|)
block|{}
end_function

begin_comment
comment|// Check for HFA padding args. Also, they should not end up on the stack in a
end_comment

begin_comment
comment|// way which will have holes in when lowered further by LLVM. In particular [3 x
end_comment

begin_comment
comment|// float] would be unacceptable.
end_comment

begin_comment
comment|// PCS: @f38(float %s0, double %d1, float %s2, float %s3, float %s4, float %s5, [2 x float], %struct.s38* byval align 4 %stacked)
end_comment

begin_struct
struct|struct
name|s38
block|{
name|float
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f38
parameter_list|(
name|float
name|s0
parameter_list|,
name|double
name|d1
parameter_list|,
name|float
name|s2
parameter_list|,
name|float
name|s3
parameter_list|,
name|float
name|s4
parameter_list|,
name|float
name|s5
parameter_list|,
name|struct
name|s38
name|stacked
parameter_list|)
block|{}
end_function

begin_comment
comment|// Check both VFP and integer arguments are padded (also that pointers and enums
end_comment

begin_comment
comment|// get counted as integer types correctly).
end_comment

begin_struct
struct|struct
name|s39_int
block|{
name|long
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s39_float
block|{
name|float
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|s39_enum
block|{
name|Val1
block|,
name|Val2
block|}
enum|;
end_enum

begin_comment
comment|// PCS: @f39(float %s0, i32 %x0, float %s1, i32* %x1, float %s2, i32 %x2, float %s3, float %s4, i32 %x3, [3 x float], %struct.s39_float* byval align 4 %stacked, i32 %x4, i32 %x5, i32 %x6, [1 x i64], %struct.s39_int* byval align 8 %stacked2)
end_comment

begin_function
name|void
name|f39
parameter_list|(
name|float
name|s0
parameter_list|,
name|int
name|x0
parameter_list|,
name|float
name|s1
parameter_list|,
name|int
modifier|*
name|x1
parameter_list|,
name|float
name|s2
parameter_list|,
name|enum
name|s39_enum
name|x2
parameter_list|,
name|float
name|s3
parameter_list|,
name|float
name|s4
parameter_list|,
name|int
name|x3
parameter_list|,
name|struct
name|s39_float
name|stacked
parameter_list|,
name|int
name|x4
parameter_list|,
name|int
name|x5
parameter_list|,
name|int
name|x6
parameter_list|,
name|struct
name|s39_int
name|stacked2
parameter_list|)
block|{}
end_function

begin_struct
struct|struct
name|s40
block|{
name|__int128
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// PCS: @f40(i32 %x0, [1 x i128] %x2_3.coerce, i32 %x4, i32 %x5, i32 %x6, [1 x i64], %struct.s40* byval align 16 %stacked)
end_comment

begin_function
name|void
name|f40
parameter_list|(
name|int
name|x0
parameter_list|,
name|struct
name|s40
name|x2_3
parameter_list|,
name|int
name|x4
parameter_list|,
name|int
name|x5
parameter_list|,
name|int
name|x6
parameter_list|,
name|struct
name|s40
name|stacked
parameter_list|)
block|{}
end_function

begin_comment
comment|// Checking: __int128 will get properly aligned type, with padding so big struct doesn't use x7.
end_comment

begin_struct
struct|struct
name|s41
block|{
name|int
name|arr
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// PCS: @f41(i32 %x0, i32 %x1, i32 %x2, i32 %x3, i32 %x4, i32 %x5, i32 %x6, [1 x i64], i128* byval align 16, %struct.s41* %stacked2)
end_comment

begin_function
name|int
name|f41
parameter_list|(
name|int
name|x0
parameter_list|,
name|int
name|x1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|x3
parameter_list|,
name|int
name|x4
parameter_list|,
name|int
name|x5
parameter_list|,
name|int
name|x6
parameter_list|,
name|__int128
name|stacked
parameter_list|,
name|struct
name|s41
name|stacked2
parameter_list|)
block|{}
end_function

begin_comment
comment|// Checking: __int128 needing to be aligned in registers will consume correct
end_comment

begin_comment
comment|// number. Previously padding was inserted before "stacked" because x6_7 was
end_comment

begin_comment
comment|// "allocated" to x5 and x6 by clang.
end_comment

begin_comment
comment|// PCS: @f42(i32 %x0, i32 %x1, i32 %x2, i32 %x3, i32 %x4, i128 %x6_7, i128* byval align 16)
end_comment

begin_function
name|void
name|f42
parameter_list|(
name|int
name|x0
parameter_list|,
name|int
name|x1
parameter_list|,
name|int
name|x2
parameter_list|,
name|int
name|x3
parameter_list|,
name|int
name|x4
parameter_list|,
name|__int128
name|x6_7
parameter_list|,
name|__int128
name|stacked
parameter_list|)
block|{}
end_function

begin_comment
comment|// Checking: __fp16 is extended to double when calling variadic functions
end_comment

begin_function_decl
name|void
name|variadic
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f43
parameter_list|(
name|__fp16
modifier|*
name|in
parameter_list|)
block|{
name|variadic
argument_list|(
literal|42
argument_list|,
operator|*
name|in
argument_list|)
expr_stmt|;
comment|// CHECK: call void @variadic(i32 42, double
block|}
end_function

end_unit

