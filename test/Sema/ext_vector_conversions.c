begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macos10.7.0 -fsyntax-only -verify -Wconversion %s
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|4
argument|))
argument_list|)
name|char
name|char4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|4
argument|))
argument_list|)
name|short
name|short4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(ext_vector_type(
literal|1
argument|))
argument_list|)
name|float
name|float1
typedef|;
end_typedef

begin_function
specifier|static
name|void
name|test
parameter_list|()
block|{
name|char4
name|vc4
decl_stmt|;
name|float
name|f
decl_stmt|;
comment|// Not allowed.  There's no splatting conversion between float and int vector,
comment|// and we don't want to bitcast f to vector-of-char (as would happen with the
comment|// old-style vector types).
name|vc4
operator|+=
name|f
expr_stmt|;
comment|// expected-error {{cannot convert between vector values of different size}}
name|short4
name|vs4
decl_stmt|;
name|long
name|long
name|ll
decl_stmt|;
comment|// This one is OK; we don't re-interpret ll as short4, rather we splat its
comment|// value, which should produce a warning about clamping.
name|vs4
operator|+=
name|ll
expr_stmt|;
comment|// expected-warning {{implicit conversion loses integer precision}}
block|}
end_function

end_unit

