begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios -target-feature +neon -target-abi darwinpcs -fallow-half-arguments-and-returns -emit-llvm -o - %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
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
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|3
argument|))
argument_list|)
name|float
name|float32x3_t
typedef|;
end_typedef

begin_comment
comment|// CHECK: %struct.HFAv3 = type { [4 x<3 x float>] }
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float32x3_t
name|arr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|HFAv3
typedef|;
end_typedef

begin_comment
comment|// CHECK: %struct.MixedHFAv3 = type { [3 x<3 x float>],<16 x i8> }
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float32x3_t
name|arr
index|[
literal|3
index|]
decl_stmt|;
name|int8x16_t
name|b
decl_stmt|;
block|}
name|MixedHFAv3
typedef|;
end_typedef

begin_comment
comment|// CHECK: define %struct.HFAv3 @test([4 x<4 x float>] %{{.*}}, [4 x<4 x float>] %{{.*}}, [4 x<4 x float>] %{{.*}})
end_comment

begin_function
name|HFAv3
name|test
parameter_list|(
name|HFAv3
name|a0
parameter_list|,
name|HFAv3
name|a1
parameter_list|,
name|HFAv3
name|a2
parameter_list|)
block|{
return|return
name|a2
return|;
block|}
end_function

begin_comment
comment|// CHECK: define %struct.MixedHFAv3 @test_mixed([4 x<4 x float>] %{{.*}}, [4 x<4 x float>] %{{.*}}, [4 x<4 x float>] %{{.*}})
end_comment

begin_function
name|MixedHFAv3
name|test_mixed
parameter_list|(
name|MixedHFAv3
name|a0
parameter_list|,
name|MixedHFAv3
name|a1
parameter_list|,
name|MixedHFAv3
name|a2
parameter_list|)
block|{
return|return
name|a2
return|;
block|}
end_function

end_unit

