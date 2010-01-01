begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

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
literal|3
argument|) )
argument_list|)
name|float
name|float3
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
name|float
name|float4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|( ext_vector_type(
literal|16
argument|) )
argument_list|)
name|float
name|float16
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|float4
name|vec4_0
init|=
operator|(
name|float4
operator|)
literal|0.5f
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|test
parameter_list|()
block|{
name|float2
name|vec2
decl_stmt|,
name|vec2_2
decl_stmt|;
name|float3
name|vec3
decl_stmt|;
name|float4
name|vec4
decl_stmt|,
name|vec4_2
decl_stmt|,
modifier|*
name|vec4p
decl_stmt|;
name|float16
name|vec16
decl_stmt|;
name|float
name|f
decl_stmt|;
name|vec2
operator|.
name|z
expr_stmt|;
comment|// expected-error {{vector component access exceeds type 'float2'}}
name|vec2
operator|.
name|xyzw
expr_stmt|;
comment|// expected-error {{vector component access exceeds type 'float2'}}
name|vec4
operator|.
name|xyzw
expr_stmt|;
comment|// expected-warning {{expression result unused}}
name|vec4
operator|.
name|xyzc
expr_stmt|;
comment|// expected-error {{illegal vector component name 'c'}}
name|vec4
operator|.
name|s01z
expr_stmt|;
comment|// expected-error {{illegal vector component name 'z'}}
name|vec2
operator|=
name|vec4
operator|.
name|s01
expr_stmt|;
comment|// legal, shorten
name|vec2
operator|=
name|vec4
operator|.
name|S01
expr_stmt|;
comment|// legal, shorten
name|vec3
operator|=
name|vec4
operator|.
name|xyz
expr_stmt|;
comment|// legal, shorten
name|f
operator|=
name|vec2
operator|.
name|x
expr_stmt|;
comment|// legal, shorten
name|f
operator|=
name|vec4
operator|.
name|xy
operator|.
name|x
expr_stmt|;
comment|// legal, shorten
name|vec4_2
operator|.
name|xyzx
operator|=
name|vec4
operator|.
name|xyzw
expr_stmt|;
comment|// expected-error {{vector is not assignable (contains duplicate components)}}
name|vec4_2
operator|.
name|xyzz
operator|=
name|vec4
operator|.
name|xyzw
expr_stmt|;
comment|// expected-error {{vector is not assignable (contains duplicate components)}}
name|vec4_2
operator|.
name|xyyw
operator|=
name|vec4
operator|.
name|xyzw
expr_stmt|;
comment|// expected-error {{vector is not assignable (contains duplicate components)}}
name|vec2
operator|.
name|x
operator|=
name|f
expr_stmt|;
name|vec2
operator|.
name|xx
operator|=
name|vec2_2
operator|.
name|xy
expr_stmt|;
comment|// expected-error {{vector is not assignable (contains duplicate components)}}
name|vec2
operator|.
name|yx
operator|=
name|vec2_2
operator|.
name|xy
expr_stmt|;
name|vec4
operator|=
operator|(
name|float4
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
expr_stmt|;
name|vec4
operator|.
name|xy
operator|.
name|w
expr_stmt|;
comment|// expected-error {{vector component access exceeds type 'float2'}}
name|vec4
operator|.
name|s06
expr_stmt|;
comment|// expected-error {{vector component access exceeds type 'float4'}}
name|vec4
operator|.
name|x
operator|=
name|vec16
operator|.
name|sf
expr_stmt|;
name|vec4
operator|.
name|x
operator|=
name|vec16
operator|.
name|sF
expr_stmt|;
name|vec4p
operator|->
name|yz
operator|=
name|vec4p
operator|->
name|xy
expr_stmt|;
block|}
end_function

begin_function
name|float2
name|lo
parameter_list|(
name|float3
name|x
parameter_list|)
block|{
return|return
name|x
operator|.
name|lo
return|;
block|}
end_function

begin_function
name|float2
name|hi
parameter_list|(
name|float3
name|x
parameter_list|)
block|{
return|return
name|x
operator|.
name|hi
return|;
block|}
end_function

begin_function
name|float2
name|ev
parameter_list|(
name|float3
name|x
parameter_list|)
block|{
return|return
name|x
operator|.
name|even
return|;
block|}
end_function

begin_function
name|float2
name|od
parameter_list|(
name|float3
name|x
parameter_list|)
block|{
return|return
name|x
operator|.
name|odd
return|;
block|}
end_function

end_unit

