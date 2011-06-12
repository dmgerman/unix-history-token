begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -march=armv7a %s
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: arm
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__simd128_uint16_t
block|{
name|__neon_uint16x8_t
name|val
decl_stmt|;
block|}
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

