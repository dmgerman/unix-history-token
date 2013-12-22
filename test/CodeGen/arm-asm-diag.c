begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple armv7 -target-feature +neon %s -S -o /dev/null 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// rdar://13446483
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
name|t1
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
comment|// expected-warning {{value size does not match register size specified by the constraint and modifier}}
asm|[r1] "=r"(r.val[1]),
comment|// expected-warning {{value size does not match register size specified by the constraint and modifier}}
asm|[r2] "=r"(r.val[2]),
comment|// expected-warning {{value size does not match register size specified by the constraint and modifier}}
asm|[r3] "=r"(r.val[3])
comment|// expected-warning {{value size does not match register size specified by the constraint and modifier}}
asm|: [a] "r"(a));
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|// We should see all four errors, rather than report a fatal error after the first.
end_comment

begin_comment
comment|// CHECK: error: non-trivial scalar-to-vector conversion, possible invalid constraint for vector type
end_comment

begin_comment
comment|// CHECK: error: non-trivial scalar-to-vector conversion, possible invalid constraint for vector type
end_comment

begin_comment
comment|// CHECK: error: non-trivial scalar-to-vector conversion, possible invalid constraint for vector type
end_comment

begin_comment
comment|// CHECK: error: non-trivial scalar-to-vector conversion, possible invalid constraint for vector type
end_comment

end_unit

