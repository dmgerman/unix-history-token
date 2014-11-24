begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-linux-gnu -target-feature +neon -target-abi aapcs -ffreestanding -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_comment
comment|// AAPCS clause C.8 says: If the argument has an alignment of 16 then the NGRN
end_comment

begin_comment
comment|// is rounded up to the next even number.
end_comment

begin_comment
comment|// CHECK: void @test1(i32 %x0, i128 %x2_x3, i128 %x4_x5, i128 %x6_x7, i128 %sp.coerce)
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|__int128
name|a
decl_stmt|;
block|}
name|Small
typedef|;
end_typedef

begin_function
name|void
name|test1
parameter_list|(
name|int
name|x0
parameter_list|,
name|__int128
name|x2_x3
parameter_list|,
name|__int128
name|x4_x5
parameter_list|,
name|__int128
name|x6_x7
parameter_list|,
name|Small
name|sp
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: void @test2(i32 %x0, i128 %x2_x3.coerce, i32 %x4, i128 %x6_x7.coerce, i32 %sp, i128 %sp16.coerce)
end_comment

begin_function
name|void
name|test2
parameter_list|(
name|int
name|x0
parameter_list|,
name|Small
name|x2_x3
parameter_list|,
name|int
name|x4
parameter_list|,
name|Small
name|x6_x7
parameter_list|,
name|int
name|sp
parameter_list|,
name|Small
name|sp16
parameter_list|)
block|{ }
end_function

begin_comment
comment|// We coerce HFAs into a contiguous [N x double] type if they're going on the
end_comment

begin_comment
comment|// stack in order to avoid holes. Make sure we get all of them, and not just the
end_comment

begin_comment
comment|// first:
end_comment

begin_comment
comment|// CHECK: void @test3(float %s0_s3.0, float %s0_s3.1, float %s0_s3.2, float %s0_s3.3, float %s4, [3 x float], [2 x double] %sp.coerce, [2 x double] %sp16.coerce)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|arr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|HFA
typedef|;
end_typedef

begin_function
name|void
name|test3
parameter_list|(
name|HFA
name|s0_s3
parameter_list|,
name|float
name|s4
parameter_list|,
name|HFA
name|sp
parameter_list|,
name|HFA
name|sp16
parameter_list|)
block|{ }
end_function

begin_comment
comment|// However, we shouldn't perform the [N x double] coercion on types which have
end_comment

begin_comment
comment|// sufficient alignment to avoid holes on their own. We could coerce to [N x
end_comment

begin_comment
comment|// fp128] or something, but leaving them as-is retains more information for
end_comment

begin_comment
comment|// users to debug.
end_comment

begin_comment
comment|//  CHECK: void @test4(<16 x i8> %v0_v2.0,<16 x i8> %v0_v2.1,<16 x i8> %v0_v2.2,<16 x i8> %v3_v5.0,<16 x i8> %v3_v5.1,<16 x i8> %v3_v5.2, [2 x float],<16 x i8> %sp.0,<16 x i8> %sp.1,<16 x i8> %sp.2, double %sp48,<16 x i8> %sp64.0,<16 x i8> %sp64.1,<16 x i8> %sp64.2)
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(neon_vector_type(
literal|16
argument|))
argument_list|)
name|signed
name|char
name|int8x16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int8x16_t
name|arr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|BigHFA
typedef|;
end_typedef

begin_function
name|void
name|test4
parameter_list|(
name|BigHFA
name|v0_v2
parameter_list|,
name|BigHFA
name|v3_v5
parameter_list|,
name|BigHFA
name|sp
parameter_list|,
name|double
name|sp48
parameter_list|,
name|BigHFA
name|sp64
parameter_list|)
block|{ }
end_function

begin_comment
comment|// It's the job of the argument *consumer* to perform the required sign& zero
end_comment

begin_comment
comment|// extensions under AAPCS. There shouldn't be
end_comment

begin_comment
comment|// CHECK: define i8 @test5(i8 %a, i16 %b)
end_comment

begin_function
name|unsigned
name|char
name|test5
parameter_list|(
name|unsigned
name|char
name|a
parameter_list|,
name|signed
name|short
name|b
parameter_list|)
block|{ }
end_function

end_unit

