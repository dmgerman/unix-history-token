begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7 %s -emit-llvm -o /dev/null
end_comment

begin_comment
comment|//<rdar://problem/12284092>
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|2
argument|))
argument_list|)
name|long
name|long
name|int64x2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|int64x2x4_t
block|{
name|int64x2_t
name|val
index|[
literal|4
index|]
decl_stmt|;
block|}
name|int64x2x4_t
typedef|;
end_typedef

begin_function
name|int64x2x4_t
name|t2
parameter_list|(
specifier|const
name|long
name|long
name|a
index|[]
parameter_list|)
block|{
name|int64x2x4_t
name|r
decl_stmt|;
asm|__asm__("vldm %[a], { %q[r0], %q[r1], %q[r2], %q[r3] }"           : [r0] "=r"(r.val[0]),
comment|// expected-warning {{the size being stored is truncated, use a modifier to specify the size}}
asm|[r1] "=r"(r.val[1]),
comment|// expected-warning {{the size being stored is truncated, use a modifier to specify the size}}
asm|[r2] "=r"(r.val[2]),
comment|// expected-warning {{the size being stored is truncated, use a modifier to specify the size}}
asm|[r3] "=r"(r.val[3])
comment|// expected-warning {{the size being stored is truncated, use a modifier to specify the size}}
asm|: [a] "r"(a));
return|return
name|r
return|;
block|}
end_function

end_unit

