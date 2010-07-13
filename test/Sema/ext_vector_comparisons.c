begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wno-unreachable-code %s
end_comment

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

begin_function
specifier|static
name|int4
name|test1
parameter_list|()
block|{
name|int4
name|vec
decl_stmt|,
name|rv
decl_stmt|;
comment|// comparisons to self...
return|return
name|vec
operator|==
name|vec
return|;
comment|// expected-warning{{self-comparison always evaluates to a constant}}
return|return
name|vec
operator|!=
name|vec
return|;
comment|// expected-warning{{self-comparison always evaluates to a constant}}
return|return
name|vec
operator|<
name|vec
return|;
comment|// expected-warning{{self-comparison always evaluates to a constant}}
return|return
name|vec
operator|<=
name|vec
return|;
comment|// expected-warning{{self-comparison always evaluates to a constant}}
return|return
name|vec
operator|>
name|vec
return|;
comment|// expected-warning{{self-comparison always evaluates to a constant}}
return|return
name|vec
operator|>=
name|vec
return|;
comment|// expected-warning{{self-comparison always evaluates to a constant}}
block|}
end_function

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

begin_function
specifier|static
name|int4
name|test2
parameter_list|()
block|{
name|float4
name|vec
decl_stmt|,
name|rv
decl_stmt|;
comment|// comparisons to self.  no warning, they're floats
return|return
name|vec
operator|==
name|vec
return|;
comment|// no-warning
return|return
name|vec
operator|!=
name|vec
return|;
comment|// no-warning
return|return
name|vec
operator|<
name|vec
return|;
comment|// no-warning
return|return
name|vec
operator|<=
name|vec
return|;
comment|// no-warning
return|return
name|vec
operator|>
name|vec
return|;
comment|// no-warning
return|return
name|vec
operator|>=
name|vec
return|;
comment|// no-warning
block|}
end_function

end_unit

