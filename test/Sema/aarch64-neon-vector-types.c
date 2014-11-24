begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple aarch64-none-linux-gnu -target-feature +neon -fsyntax-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple aarch64-none-linux-gnu -target-feature +neon -DUSE_LONG -fsyntax-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple arm64-none-linux-gnu -target-feature +neon -fsyntax-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple arm64-none-linux-gnu -target-feature +neon -DUSE_LONG -fsyntax-only -verify
end_comment

begin_typedef
typedef|typedef
name|float
name|float32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|poly8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|poly16_t
typedef|;
end_typedef

begin_comment
comment|// Both "long" and "long long" should work for 64-bit arch like aarch64.
end_comment

begin_comment
comment|// stdint.h in gnu libc is using "long" for 64-bit arch.
end_comment

begin_if
if|#
directive|if
name|USE_LONG
end_if

begin_typedef
typedef|typedef
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uint64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint64_t
name|poly64_t
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
name|int64_t
name|int64x1_t
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
name|int64_t
name|int64x2_t
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

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_polyvector_type(
literal|1
argument|))
argument_list|)
name|poly64_t
name|poly64x1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_polyvector_type(
literal|2
argument|))
argument_list|)
name|poly64_t
name|poly64x2_t
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
comment|// expected-error{{attribute takes one argument}}
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
comment|// expected-error{{attribute requires an integer constant}}
end_comment

begin_comment
comment|// Only certain element types are allowed.
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|2
argument|))
argument_list|)
name|double
name|double_elt
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

