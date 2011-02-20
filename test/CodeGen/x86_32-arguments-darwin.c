begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -fblocks -triple i386-apple-darwin9 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|// CHECK: define signext i8 @f0()
end_comment

begin_function
name|char
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define signext i16 @f1()
end_comment

begin_function
name|short
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i32 @f2()
end_comment

begin_function
name|int
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define float @f3()
end_comment

begin_function
name|float
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define double @f4()
end_comment

begin_function
name|double
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define x86_fp80 @f5()
end_comment

begin_function
name|long
name|double
name|f5
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @f6(i8 signext %a0, i16 signext %a1, i32 %a2, i64 %a3, i8* %a4)
end_comment

begin_function
name|void
name|f6
parameter_list|(
name|char
name|a0
parameter_list|,
name|short
name|a1
parameter_list|,
name|int
name|a2
parameter_list|,
name|long
name|long
name|a3
parameter_list|,
name|void
modifier|*
name|a4
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f7(i32 %a0)
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|A
block|,
name|B
block|,
name|C
block|}
name|e7
typedef|;
end_typedef

begin_function
name|void
name|f7
parameter_list|(
name|e7
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define i64 @f8_1()
end_comment

begin_comment
comment|// CHECK: define void @f8_2(i32 %a0.0, i32 %a0.1)
end_comment

begin_struct
struct|struct
name|s8
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s8
name|f8_1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f8_2
parameter_list|(
name|struct
name|s8
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// This should be passed just as s8.
end_comment

begin_comment
comment|// CHECK: define i64 @f9_1()
end_comment

begin_comment
comment|// FIXME: llvm-gcc expands this, this may have some value for the
end_comment

begin_comment
comment|// backend in terms of optimization but doesn't change the ABI.
end_comment

begin_comment
comment|// CHECK: define void @f9_2(%struct.s9* byval %a0)
end_comment

begin_struct
struct|struct
name|s9
block|{
name|int
name|a
range|:
literal|17
decl_stmt|;
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|struct
name|s9
name|f9_1
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_function
name|void
name|f9_2
parameter_list|(
name|struct
name|s9
name|a0
parameter_list|)
block|{}
end_function

begin_comment
comment|// Return of small structures and unions
end_comment

begin_comment
comment|// CHECK: float @f10()
end_comment

begin_struct
struct|struct
name|s10
block|{
union|union
block|{ }
union|;
name|float
name|f
decl_stmt|;
block|}
name|f10
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// Small vectors and 1 x {i64,double} are returned in registers
comment|// CHECK: i32 @f11()
comment|// CHECK: void @f12(<2 x i32>* sret %agg.result)
comment|// CHECK: i64 @f13()
comment|// CHECK: i64 @f14()
comment|// CHECK:<2 x i64> @f15()
comment|// CHECK:<2 x i64> @f16()
decl|typedef
name|short
name|T11
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_function
name|T11
name|f11
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|T12
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_function
name|T12
name|f12
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_typedef
typedef|typedef
name|long
name|long
name|T13
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_function
name|T13
name|f13
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_typedef
typedef|typedef
name|double
name|T14
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_function
name|T14
name|f14
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_typedef
typedef|typedef
name|long
name|long
name|T15
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|T15
name|f15
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_typedef
typedef|typedef
name|double
name|T16
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|T16
name|f16
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
end_function

begin_comment
comment|// And when the single element in a struct (but not for 64 and
end_comment

begin_comment
comment|// 128-bits).
end_comment

begin_comment
comment|// CHECK: i32 @f17()
end_comment

begin_comment
comment|// CHECK: void @f18(%{{.*}}* sret %agg.result)
end_comment

begin_comment
comment|// CHECK: void @f19(%{{.*}}* sret %agg.result)
end_comment

begin_comment
comment|// CHECK: void @f20(%{{.*}}* sret %agg.result)
end_comment

begin_comment
comment|// CHECK: void @f21(%{{.*}}* sret %agg.result)
end_comment

begin_comment
comment|// CHECK: void @f22(%{{.*}}* sret %agg.result)
end_comment

begin_struct
struct|struct
block|{
name|T11
name|a
decl_stmt|;
block|}
name|f17
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
decl|struct
block|{
name|T12
name|a
decl_stmt|;
block|}
name|f18
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
decl|struct
block|{
name|T13
name|a
decl_stmt|;
block|}
name|f19
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
decl|struct
block|{
name|T14
name|a
decl_stmt|;
block|}
name|f20
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
decl|struct
block|{
name|T15
name|a
decl_stmt|;
block|}
name|f21
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
decl|struct
block|{
name|T16
name|a
decl_stmt|;
block|}
name|f22
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// Single element structures are handled specially
comment|// CHECK: float @f23()
comment|// CHECK: float @f24()
comment|// CHECK: float @f25()
decl|struct
block|{
name|float
name|a
decl_stmt|;
block|}
name|f23
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
decl|struct
block|{
name|float
name|a
index|[
literal|1
index|]
decl_stmt|;
block|}
name|f24
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
decl|struct
block|{
struct|struct
block|{}
name|a
struct|;
struct|struct
block|{
name|float
name|a
index|[
literal|1
index|]
decl_stmt|;
block|}
name|b
struct|;
block|}
name|f25
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// Small structures are handled recursively
comment|// CHECK: i32 @f26()
comment|// CHECK: void @f27(%struct.s27* sret %agg.result)
decl|struct
name|s26
block|{
struct|struct
block|{
name|char
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|a
struct|;
struct|struct
block|{
name|char
name|a
decl_stmt|,
name|b
decl_stmt|;
block|}
name|b
struct|;
block|}
name|f26
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
decl|struct
name|s27
block|{
struct|struct
block|{
name|char
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
block|}
name|a
struct|;
struct|struct
block|{
name|char
name|a
decl_stmt|;
block|}
name|b
struct|;
block|}
name|f27
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: void @f28(%struct.s28* sret %agg.result)
decl|struct
name|s28
block|{
name|int
name|a
decl_stmt|;
name|int
name|b
index|[]
decl_stmt|;
block|}
name|f28
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define i16 @f29()
decl|struct
name|s29
block|{
struct|struct
block|{ }
name|a
index|[
literal|1
index|]
struct|;
name|char
name|b
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
name|f29
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define i16 @f30()
decl|struct
name|s30
block|{
name|char
name|a
decl_stmt|;
name|char
name|b
range|:
literal|4
decl_stmt|;
block|}
name|f30
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define float @f31()
decl|struct
name|s31
block|{
name|char
label|:
literal|0
expr_stmt|;
name|float
name|b
decl_stmt|;
name|char
label|:
literal|0
expr_stmt|;
block|}
name|f31
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define i32 @f32()
decl|struct
name|s32
block|{
name|char
name|a
decl_stmt|;
name|unsigned
label|:
literal|0
expr_stmt|;
block|}
name|f32
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define float @f33()
decl|struct
name|s33
block|{
name|float
name|a
decl_stmt|;
name|long
name|long
range|:
literal|0
decl_stmt|;
block|}
name|f33
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define float @f34()
decl|struct
name|s34
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|a
struct|;
name|float
name|b
decl_stmt|;
block|}
name|f34
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define i16 @f35()
decl|struct
name|s35
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|a
struct|;
name|char
name|b
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
name|f35
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define i16 @f36()
decl|struct
name|s36
block|{
struct|struct
block|{
name|int
label|:
literal|0
expr_stmt|;
block|}
name|a
index|[
literal|2
index|]
index|[
literal|10
index|]
struct|;
name|char
name|b
decl_stmt|;
name|char
name|c
decl_stmt|;
block|}
name|f36
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define float @f37()
decl|struct
name|s37
block|{
name|float
name|c
index|[
literal|1
index|]
index|[
literal|1
index|]
decl_stmt|;
block|}
name|f37
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define void @f38(%struct.s38* sret %agg.result)
decl|struct
name|s38
block|{
name|char
name|a
index|[
literal|3
index|]
decl_stmt|;
name|short
name|b
decl_stmt|;
block|}
name|f38
argument_list|(
name|void
argument_list|)
block|{
while|while
condition|(
literal|1
condition|)
block|{}
block|}
comment|// CHECK: define void @f39(%struct.s39* byval align 16 %x)
decl|typedef
name|int
name|v39
name|__attribute
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|s39
block|{
name|v39
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f39
parameter_list|(
name|struct
name|s39
name|x
parameter_list|)
block|{}
end_function

begin_comment
comment|//<rdar://problem/7247671>
end_comment

begin_comment
comment|// CHECK: define i32 @f40()
end_comment

begin_enum
enum|enum
name|e40
block|{
name|ec0
init|=
literal|0
block|}
enum|;
end_enum

begin_function
name|enum
name|e40
name|f40
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void ()* @f41()
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|vvbp
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|vvbp
name|f41
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define i32 @f42()
end_comment

begin_struct
struct|struct
name|s42
block|{
name|enum
name|e40
name|f0
decl_stmt|;
block|}
name|f42
argument_list|(
name|void
argument_list|)
block|{  }
comment|// CHECK: define i64 @f43()
decl|struct
name|s43
block|{
name|enum
name|e40
name|f0
decl_stmt|;
name|int
name|f1
decl_stmt|;
block|}
name|f43
argument_list|(
name|void
argument_list|)
block|{  }
comment|// CHECK: define i32 @f44()
decl|struct
name|s44
block|{
name|vvbp
name|f0
decl_stmt|;
block|}
name|f44
argument_list|(
name|void
argument_list|)
block|{  }
comment|// CHECK: define i64 @f45()
decl|struct
name|s45
block|{
name|vvbp
name|f0
decl_stmt|;
name|int
name|f1
decl_stmt|;
block|}
name|f45
argument_list|(
name|void
argument_list|)
block|{  }
comment|// CHECK: define void @f46(i32 %a0)
name|void
name|f46
argument_list|(
expr|enum
name|e40
name|a0
argument_list|)
block|{ }
comment|// CHECK: define void @f47(void ()* %a1)
name|void
name|f47
argument_list|(
name|vvbp
name|a1
argument_list|)
block|{ }
comment|// CHECK: define void @f48(i32 %a0.0)
decl|struct
name|s48
block|{
name|enum
name|e40
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f48
parameter_list|(
name|struct
name|s48
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @f49(i32 %a0.0, i32 %a0.1)
end_comment

begin_struct
struct|struct
name|s49
block|{
name|enum
name|e40
name|f0
decl_stmt|;
name|int
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f49
parameter_list|(
name|struct
name|s49
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @f50(void ()* %a0.0)
end_comment

begin_struct
struct|struct
name|s50
block|{
name|vvbp
name|f0
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f50
parameter_list|(
name|struct
name|s50
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @f51(void ()* %a0.0, i32 %a0.1)
end_comment

begin_struct
struct|struct
name|s51
block|{
name|vvbp
name|f0
decl_stmt|;
name|int
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f51
parameter_list|(
name|struct
name|s51
name|a0
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: define void @f52(%struct.s52* byval align 4)
end_comment

begin_struct
struct|struct
name|s52
block|{
name|long
name|double
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f52
parameter_list|(
name|struct
name|s52
name|x
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @f53(%struct.s53* byval align 4)
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(aligned(
literal|32
argument|))
argument_list|)
name|s53
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f53
parameter_list|(
name|struct
name|s53
name|x
parameter_list|)
block|{}
end_function

begin_typedef
typedef|typedef
name|unsigned
name|short
name|v2i16
name|__attribute__
typedef|((
name|__vector_size__
typedef|(4)));
end_typedef

begin_comment
comment|// CHECK: define i32 @f54(i32 %arg.coerce)
end_comment

begin_comment
comment|// rdar://8359483
end_comment

begin_function
name|v2i16
name|f54
parameter_list|(
name|v2i16
name|arg
parameter_list|)
block|{
return|return
name|arg
operator|+
name|arg
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|v4i32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|// CHECK: define<2 x i64> @f55(<4 x i32> %arg)
end_comment

begin_comment
comment|// PR8029
end_comment

begin_function
name|v4i32
name|f55
parameter_list|(
name|v4i32
name|arg
parameter_list|)
block|{
return|return
name|arg
operator|+
name|arg
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @f56(
end_comment

begin_comment
comment|// CHECK: i8 signext %a0, %struct.s56_0* byval %a1,
end_comment

begin_comment
comment|// CHECK: x86_mmx %a2.coerce, %struct.s56_1* byval align 4,
end_comment

begin_comment
comment|// CHECK: i64 %a4.coerce, %struct.s56_2* byval align 4,
end_comment

begin_comment
comment|// CHECK:<4 x i32> %a6, %struct.s39* byval align 16 %a7,
end_comment

begin_comment
comment|// CHECK:<2 x double> %a8, %struct.s56_4* byval align 16 %a9,
end_comment

begin_comment
comment|// CHECK:<8 x i32> %a10, %struct.s56_5* byval align 4,
end_comment

begin_comment
comment|// CHECK:<4 x double> %a12, %struct.s56_6* byval align 4)
end_comment

begin_comment
comment|// CHECK:   call void (i32, ...)* @f56_0(i32 1,
end_comment

begin_comment
comment|// CHECK: i32 %{{[^ ]*}}, %struct.s56_0* byval %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK: x86_mmx %{{[^ ]*}}, %struct.s56_1* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK: i64 %{{[^ ]*}}, %struct.s56_2* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<4 x i32> %{{[^ ]*}}, %struct.s39* byval align 16 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<2 x double> %{{[^ ]*}}, %struct.s56_4* byval align 16 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<8 x i32> {{[^ ]*}}, %struct.s56_5* byval align 4 %{{[^ ]*}},
end_comment

begin_comment
comment|// CHECK:<4 x double> {{[^ ]*}}, %struct.s56_6* byval align 4 %{{[^ ]*}})
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<rdar://problem/7964854> [i386] clang misaligns long double in structures
end_comment

begin_comment
comment|// when passed byval
end_comment

begin_comment
comment|//<rdar://problem/8431367> clang misaligns parameters on stack
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|t56_v2i
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|t56_v1d
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|t56_v4i
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|t56_v2d
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
name|t56_v8i
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|32
argument_list|)
operator|)
argument_list|)
name|t56_v4d
typedef|;
end_typedef

begin_struct
struct|struct
name|s56_0
block|{
name|char
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_1
block|{
name|t56_v2i
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_2
block|{
name|t56_v1d
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_3
block|{
name|t56_v4i
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_4
block|{
name|t56_v2d
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_5
block|{
name|t56_v8i
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s56_6
block|{
name|t56_v4d
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f56
parameter_list|(
name|char
name|a0
parameter_list|,
name|struct
name|s56_0
name|a1
parameter_list|,
name|t56_v2i
name|a2
parameter_list|,
name|struct
name|s56_1
name|a3
parameter_list|,
name|t56_v1d
name|a4
parameter_list|,
name|struct
name|s56_2
name|a5
parameter_list|,
name|t56_v4i
name|a6
parameter_list|,
name|struct
name|s56_3
name|a7
parameter_list|,
name|t56_v2d
name|a8
parameter_list|,
name|struct
name|s56_4
name|a9
parameter_list|,
name|t56_v8i
name|a10
parameter_list|,
name|struct
name|s56_5
name|a11
parameter_list|,
name|t56_v4d
name|a12
parameter_list|,
name|struct
name|s56_6
name|a13
parameter_list|)
block|{
specifier|extern
name|void
name|f56_0
argument_list|(
name|int
name|x
argument_list|,
operator|...
argument_list|)
decl_stmt|;
name|f56_0
argument_list|(
literal|1
argument_list|,
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|,
name|a6
argument_list|,
name|a7
argument_list|,
name|a8
argument_list|,
name|a9
argument_list|,
name|a10
argument_list|,
name|a11
argument_list|,
name|a12
argument_list|,
name|a13
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

