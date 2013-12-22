begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple armv7 -fsyntax-only -verify
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|2
argument|))
argument_list|)
name|int
name|int32x2_t
typedef|;
end_typedef

begin_comment
comment|// expected-error{{'neon_vector_type' attribute is not supported for this target}}
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_polyvector_type(
literal|16
argument|))
argument_list|)
name|short
name|poly8x16_t
typedef|;
end_typedef

begin_comment
comment|// expected-error{{'neon_polyvector_type' attribute is not supported for this target}}
end_comment

end_unit

