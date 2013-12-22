begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|4
argument|) )
argument_list|)
name|float
name|float4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|2
argument|) )
argument_list|)
name|float
name|float2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|4
argument|) )
argument_list|)
name|int
name|int4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|4
argument|) )
argument_list|)
name|unsigned
name|int
name|uint4
typedef|;
end_typedef

begin_comment
comment|// CHECK: @foo = global<4 x float><float 1.000000e+00, float 2.000000e+00, float 3.000000e+00, float 4.000000e+00>
end_comment

begin_decl_stmt
name|float4
name|foo
init|=
operator|(
name|float4
operator|)
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
literal|4.0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @bar = constant<4 x float><float 1.000000e+00, float 2.000000e+00, float 3.000000e+00, float 0x7FF0000000000000>
end_comment

begin_decl_stmt
specifier|const
name|float4
name|bar
init|=
operator|(
name|float4
operator|)
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
name|__builtin_inff
argument_list|()
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @test1
end_comment

begin_comment
comment|// CHECK: fadd<4 x float>
end_comment

begin_function
name|float4
name|test1
parameter_list|(
name|float4
name|V
parameter_list|)
block|{
return|return
name|V
operator|.
name|wzyx
operator|+
name|V
return|;
block|}
end_function

begin_decl_stmt
name|float2
name|vec2
decl_stmt|,
name|vec2_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float4
name|vec4
decl_stmt|,
name|vec4_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|f
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @test2
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK: extractelement
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK: insertelement
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<i32 1, i32 0>
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
name|vec2
operator|=
name|vec4
operator|.
name|xy
expr_stmt|;
comment|// shorten
name|f
operator|=
name|vec2
operator|.
name|x
expr_stmt|;
comment|// extract elt
name|vec4
operator|=
name|vec4
operator|.
name|yyyy
expr_stmt|;
comment|// splat
name|vec2
operator|.
name|x
operator|=
name|f
expr_stmt|;
comment|// insert one.
name|vec2
operator|.
name|yx
operator|=
name|vec2
expr_stmt|;
comment|// reverse
block|}
end_function

begin_comment
comment|// CHECK: @test3
end_comment

begin_comment
comment|// CHECK: store<4 x float><float 1.000000e+00, float 2.000000e+00, float 3.000000e+00, float 4.000000e+00>
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|float4
modifier|*
name|out
parameter_list|)
block|{
operator|*
name|out
operator|=
operator|(
operator|(
name|float4
operator|)
block|{
literal|1.0f
block|,
literal|2.0f
block|,
literal|3.0f
block|,
literal|4.0f
block|}
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test4
end_comment

begin_comment
comment|// CHECK: store<4 x float>
end_comment

begin_comment
comment|// CHECK: store<4 x float>
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|float4
modifier|*
name|out
parameter_list|)
block|{
name|float
name|a
init|=
literal|1.0f
decl_stmt|;
name|float
name|b
init|=
literal|2.0f
decl_stmt|;
name|float
name|c
init|=
literal|3.0f
decl_stmt|;
name|float
name|d
init|=
literal|4.0f
decl_stmt|;
operator|*
name|out
operator|=
operator|(
operator|(
name|float4
operator|)
block|{
name|a
block|,
name|b
block|,
name|c
block|,
name|d
block|}
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test5
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK: fmul<4 x float>
end_comment

begin_comment
comment|// CHECK: fmul<4 x float>
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK: fmul<4 x float>
end_comment

begin_function
name|void
name|test5
parameter_list|(
name|float4
modifier|*
name|out
parameter_list|)
block|{
name|float
name|a
decl_stmt|;
name|float4
name|b
decl_stmt|;
name|a
operator|=
literal|1.0f
expr_stmt|;
name|b
operator|=
name|a
expr_stmt|;
name|b
operator|=
name|b
operator|*
literal|5.0f
expr_stmt|;
name|b
operator|=
literal|5.0f
operator|*
name|b
expr_stmt|;
name|b
operator|*=
name|a
expr_stmt|;
operator|*
name|out
operator|=
name|b
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test6
end_comment

begin_function
name|void
name|test6
parameter_list|(
name|float4
modifier|*
name|ap
parameter_list|,
name|float4
modifier|*
name|bp
parameter_list|,
name|float
name|c
parameter_list|)
block|{
name|float4
name|a
init|=
operator|*
name|ap
decl_stmt|;
name|float4
name|b
init|=
operator|*
name|bp
decl_stmt|;
comment|// CHECK: fadd<4 x float>
comment|// CHECK: fsub<4 x float>
comment|// CHECK: fmul<4 x float>
comment|// CHECK: fdiv<4 x float>
name|a
operator|=
name|a
operator|+
name|b
expr_stmt|;
name|a
operator|=
name|a
operator|-
name|b
expr_stmt|;
name|a
operator|=
name|a
operator|*
name|b
expr_stmt|;
name|a
operator|=
name|a
operator|/
name|b
expr_stmt|;
comment|// CHECK: fadd<4 x float>
comment|// CHECK: fsub<4 x float>
comment|// CHECK: fmul<4 x float>
comment|// CHECK: fdiv<4 x float>
name|a
operator|=
name|a
operator|+
name|c
expr_stmt|;
name|a
operator|=
name|a
operator|-
name|c
expr_stmt|;
name|a
operator|=
name|a
operator|*
name|c
expr_stmt|;
name|a
operator|=
name|a
operator|/
name|c
expr_stmt|;
comment|// CHECK: fadd<4 x float>
comment|// CHECK: fsub<4 x float>
comment|// CHECK: fmul<4 x float>
comment|// CHECK: fdiv<4 x float>
name|a
operator|+=
name|b
expr_stmt|;
name|a
operator|-=
name|b
expr_stmt|;
name|a
operator|*=
name|b
expr_stmt|;
name|a
operator|/=
name|b
expr_stmt|;
comment|// CHECK: fadd<4 x float>
comment|// CHECK: fsub<4 x float>
comment|// CHECK: fmul<4 x float>
comment|// CHECK: fdiv<4 x float>
name|a
operator|+=
name|c
expr_stmt|;
name|a
operator|-=
name|c
expr_stmt|;
name|a
operator|*=
name|c
expr_stmt|;
name|a
operator|/=
name|c
expr_stmt|;
comment|// Vector comparisons can sometimes crash the x86 backend: rdar://6326239,
comment|// reject them until the implementation is stable.
if|#
directive|if
literal|0
block|int4 cmp;   cmp = a< b;   cmp = a<= b;   cmp = a< b;   cmp = a>= b;   cmp = a == b;   cmp = a != b;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// CHECK: @test7
end_comment

begin_function
name|void
name|test7
parameter_list|(
name|int4
modifier|*
name|ap
parameter_list|,
name|int4
modifier|*
name|bp
parameter_list|,
name|int
name|c
parameter_list|)
block|{
name|int4
name|a
init|=
operator|*
name|ap
decl_stmt|;
name|int4
name|b
init|=
operator|*
name|bp
decl_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK: sub<4 x i32>
comment|// CHECK: mul<4 x i32>
comment|// CHECK: sdiv<4 x i32>
comment|// CHECK: srem<4 x i32>
name|a
operator|=
name|a
operator|+
name|b
expr_stmt|;
name|a
operator|=
name|a
operator|-
name|b
expr_stmt|;
name|a
operator|=
name|a
operator|*
name|b
expr_stmt|;
name|a
operator|=
name|a
operator|/
name|b
expr_stmt|;
name|a
operator|=
name|a
operator|%
name|b
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK: sub<4 x i32>
comment|// CHECK: mul<4 x i32>
comment|// CHECK: sdiv<4 x i32>
comment|// CHECK: srem<4 x i32>
name|a
operator|=
name|a
operator|+
name|c
expr_stmt|;
name|a
operator|=
name|a
operator|-
name|c
expr_stmt|;
name|a
operator|=
name|a
operator|*
name|c
expr_stmt|;
name|a
operator|=
name|a
operator|/
name|c
expr_stmt|;
name|a
operator|=
name|a
operator|%
name|c
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK: sub<4 x i32>
comment|// CHECK: mul<4 x i32>
comment|// CHECK: sdiv<4 x i32>
comment|// CHECK: srem<4 x i32>
name|a
operator|+=
name|b
expr_stmt|;
name|a
operator|-=
name|b
expr_stmt|;
name|a
operator|*=
name|b
expr_stmt|;
name|a
operator|/=
name|b
expr_stmt|;
name|a
operator|%=
name|b
expr_stmt|;
comment|// CHECK: add<4 x i32>
comment|// CHECK: sub<4 x i32>
comment|// CHECK: mul<4 x i32>
comment|// CHECK: sdiv<4 x i32>
comment|// CHECK: srem<4 x i32>
name|a
operator|+=
name|c
expr_stmt|;
name|a
operator|-=
name|c
expr_stmt|;
name|a
operator|*=
name|c
expr_stmt|;
name|a
operator|/=
name|c
expr_stmt|;
name|a
operator|%=
name|c
expr_stmt|;
comment|// Vector comparisons.
comment|// CHECK: icmp slt
comment|// CHECK: icmp sle
comment|// CHECK: icmp sgt
comment|// CHECK: icmp sge
comment|// CHECK: icmp eq
comment|// CHECK: icmp ne
name|int4
name|cmp
decl_stmt|;
name|cmp
operator|=
name|a
operator|<
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|<=
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|>
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|>=
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|==
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|!=
name|b
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test8
end_comment

begin_function
name|void
name|test8
parameter_list|(
name|float4
modifier|*
name|ap
parameter_list|,
name|float4
modifier|*
name|bp
parameter_list|,
name|int
name|c
parameter_list|)
block|{
name|float4
name|a
init|=
operator|*
name|ap
decl_stmt|;
name|float4
name|b
init|=
operator|*
name|bp
decl_stmt|;
comment|// Vector comparisons.
comment|// CHECK: fcmp olt
comment|// CHECK: fcmp ole
comment|// CHECK: fcmp ogt
comment|// CHECK: fcmp oge
comment|// CHECK: fcmp oeq
comment|// CHECK: fcmp une
name|int4
name|cmp
decl_stmt|;
name|cmp
operator|=
name|a
operator|<
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|<=
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|>
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|>=
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|==
name|b
expr_stmt|;
name|cmp
operator|=
name|a
operator|!=
name|b
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test9
end_comment

begin_comment
comment|// CHECK: extractelement<4 x i32>
end_comment

begin_function
name|int
name|test9
parameter_list|(
name|int4
name|V
parameter_list|)
block|{
return|return
name|V
operator|.
name|xy
operator|.
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test10
end_comment

begin_comment
comment|// CHECK: add<4 x i32>
end_comment

begin_comment
comment|// CHECK: extractelement<4 x i32>
end_comment

begin_function
name|int
name|test10
parameter_list|(
name|int4
name|V
parameter_list|)
block|{
return|return
operator|(
name|V
operator|+
name|V
operator|)
operator|.
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test11
end_comment

begin_comment
comment|// CHECK: extractelement<4 x i32>
end_comment

begin_function_decl
name|int4
name|test11a
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|test11
parameter_list|()
block|{
return|return
name|test11a
argument_list|()
operator|.
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test12
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<i32 2, i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<i32 0, i32 1, i32 2, i32 undef>
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<i32 4, i32 5, i32 6, i32 3>
end_comment

begin_function
name|int4
name|test12
parameter_list|(
name|int4
name|V
parameter_list|)
block|{
name|V
operator|.
name|xyz
operator|=
name|V
operator|.
name|zyx
expr_stmt|;
return|return
name|V
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test13
end_comment

begin_comment
comment|// CHECK: shufflevector {{.*}}<i32 2, i32 1, i32 0, i32 3>
end_comment

begin_function
name|int4
name|test13
parameter_list|(
name|int4
modifier|*
name|V
parameter_list|)
block|{
return|return
name|V
operator|->
name|zyxw
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test14
end_comment

begin_function
name|void
name|test14
parameter_list|(
name|uint4
modifier|*
name|ap
parameter_list|,
name|uint4
modifier|*
name|bp
parameter_list|,
name|unsigned
name|c
parameter_list|)
block|{
name|uint4
name|a
init|=
operator|*
name|ap
decl_stmt|;
name|uint4
name|b
init|=
operator|*
name|bp
decl_stmt|;
name|int4
name|d
decl_stmt|;
comment|// CHECK: udiv<4 x i32>
comment|// CHECK: urem<4 x i32>
name|a
operator|=
name|a
operator|/
name|b
expr_stmt|;
name|a
operator|=
name|a
operator|%
name|b
expr_stmt|;
comment|// CHECK: udiv<4 x i32>
comment|// CHECK: urem<4 x i32>
name|a
operator|=
name|a
operator|/
name|c
expr_stmt|;
name|a
operator|=
name|a
operator|%
name|c
expr_stmt|;
comment|// CHECK: icmp ult
comment|// CHECK: icmp ule
comment|// CHECK: icmp ugt
comment|// CHECK: icmp uge
comment|// CHECK: icmp eq
comment|// CHECK: icmp ne
name|d
operator|=
name|a
operator|<
name|b
expr_stmt|;
name|d
operator|=
name|a
operator|<=
name|b
expr_stmt|;
name|d
operator|=
name|a
operator|>
name|b
expr_stmt|;
name|d
operator|=
name|a
operator|>=
name|b
expr_stmt|;
name|d
operator|=
name|a
operator|==
name|b
expr_stmt|;
name|d
operator|=
name|a
operator|!=
name|b
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test15
end_comment

begin_function
name|int4
name|test15
parameter_list|(
name|uint4
name|V0
parameter_list|)
block|{
comment|// CHECK: icmp eq<4 x i32>
name|int4
name|V
init|=
operator|!
name|V0
decl_stmt|;
name|V
operator|=
name|V
operator|&&
name|V
expr_stmt|;
name|V
operator|=
name|V
operator|||
name|V
expr_stmt|;
return|return
name|V
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test16
end_comment

begin_function
name|void
name|test16
parameter_list|(
name|float2
name|a
parameter_list|,
name|float2
name|b
parameter_list|)
block|{
name|float2
name|t0
init|=
operator|(
name|a
operator|+
name|b
operator|)
operator|/
literal|2
decl_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|char
name|char16
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(16)));
end_typedef

begin_comment
comment|// CHECK: @test17
end_comment

begin_function
name|void
name|test17
parameter_list|(
name|void
parameter_list|)
block|{
name|char16
name|valA
decl_stmt|;
name|char
name|valB
decl_stmt|;
name|char
name|valC
decl_stmt|;
name|char16
name|destVal
init|=
name|valC
condition|?
name|valA
else|:
name|valB
decl_stmt|;
block|}
end_function

end_unit

