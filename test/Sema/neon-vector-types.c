begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple armv7 -target-feature +neon -fsyntax-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple armv8 -target-feature +neon -fsyntax-only -verify
end_comment

begin_typedef
typedef|typedef
name|float
name|float32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|poly8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|poly16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__INT64_TYPE__
name|uint64_t
typedef|;
end_typedef

begin_comment
comment|// Define some valid Neon types.
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

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|4
argument|))
argument_list|)
name|int
name|int32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|1
argument|))
argument_list|)
name|uint64_t
name|uint64x1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|2
argument|))
argument_list|)
name|uint64_t
name|uint64x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|2
argument|))
argument_list|)
name|float32_t
name|float32x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|4
argument|))
argument_list|)
name|float32_t
name|float32x4_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_polyvector_type(
literal|16
argument|))
argument_list|)
name|poly8_t
name|poly8x16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_polyvector_type(
literal|8
argument|))
argument_list|)
name|poly16_t
name|poly16x8_t
typedef|;
end_typedef

begin_comment
comment|// The attributes must have a single argument.
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|2
argument|,
literal|4
argument|))
argument_list|)
name|int
name|only_one_arg
typedef|;
end_typedef

begin_comment
comment|// expected-error{{'neon_vector_type' attribute takes one argument}}
end_comment

begin_comment
comment|// The number of elements must be an ICE.
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|2.0
argument|))
argument_list|)
name|int
name|non_int_width
typedef|;
end_typedef

begin_comment
comment|// expected-error{{'neon_vector_type' attribute requires an integer constant}}
end_comment

begin_comment
comment|// Only certain element types are allowed.
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|4
argument|))
argument_list|)
name|void
modifier|*
name|ptr_elt
typedef|;
end_typedef

begin_comment
comment|// expected-error{{invalid vector element type}}
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_polyvector_type(
literal|4
argument|))
argument_list|)
name|float32_t
name|bad_poly_elt
typedef|;
end_typedef

begin_comment
comment|// expected-error{{invalid vector element type}}
end_comment

begin_struct
struct|struct
name|aggr
block|{
name|signed
name|char
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|8
argument|))
argument_list|)
name|struct
name|aggr
name|aggregate_elt
typedef|;
end_typedef

begin_comment
comment|// expected-error{{invalid vector element type}}
end_comment

begin_comment
comment|// The total vector size must be 64 or 128 bits.
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|1
argument|))
argument_list|)
name|int
name|int32x1_t
typedef|;
end_typedef

begin_comment
comment|// expected-error{{Neon vector size must be 64 or 128 bits}}
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|3
argument|))
argument_list|)
name|int
name|int32x3_t
typedef|;
end_typedef

begin_comment
comment|// expected-error{{Neon vector size must be 64 or 128 bits}}
end_comment

end_unit

