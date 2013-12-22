begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -emit-llvm -triple armv7a-apple-darwin -target-feature +neon %s -o /dev/null
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|8
argument|))
argument_list|)
name|uint16_t
name|uint16x8_t
typedef|;
end_typedef

begin_function
name|void
name|b
parameter_list|(
name|uint16x8_t
name|sat
parameter_list|,
name|uint16x8_t
name|luma
parameter_list|)
block|{
asm|__asm__("vmov.16 %1, %0   \n\t"                                            "vtrn.16 %0, %1   \n\t"    :"=w"(luma), "=w"(sat)    :"0"(luma)    );
block|}
end_function

end_unit

