begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -target-feature +altivec -triple powerpc64-unknown-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|short
name|v2i16
name|__attribute__
typedef|((
name|vector_size
typedef|(4)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|v3i16
name|__attribute__
typedef|((
name|vector_size
typedef|(6)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|v4i16
name|__attribute__
typedef|((
name|vector_size
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|v6i16
name|__attribute__
typedef|((
name|vector_size
typedef|(12)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|v8i16
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|v16i16
name|__attribute__
typedef|((
name|vector_size
typedef|(32)));
end_typedef

begin_struct
struct|struct
name|v16i16
block|{
name|v16i16
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: define i32 @test_v2i16(i32 %x.coerce)
end_comment

begin_function
name|v2i16
name|test_v2i16
parameter_list|(
name|v2i16
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i64 @test_v3i16(i64 %x.coerce)
end_comment

begin_function
name|v3i16
name|test_v3i16
parameter_list|(
name|v3i16
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i64 @test_v4i16(i64 %x.coerce)
end_comment

begin_function
name|v4i16
name|test_v4i16
parameter_list|(
name|v4i16
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define<6 x i16> @test_v6i16(<6 x i16> %x)
end_comment

begin_function
name|v6i16
name|test_v6i16
parameter_list|(
name|v6i16
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define<8 x i16> @test_v8i16(<8 x i16> %x)
end_comment

begin_function
name|v8i16
name|test_v8i16
parameter_list|(
name|v8i16
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @test_v16i16(<16 x i16>* noalias sret %agg.result,<16 x i16>*)
end_comment

begin_function
name|v16i16
name|test_v16i16
parameter_list|(
name|v16i16
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @test_struct_v16i16(%struct.v16i16* noalias sret %agg.result, [2 x i128] %x.coerce)
end_comment

begin_function
name|struct
name|v16i16
name|test_struct_v16i16
parameter_list|(
name|struct
name|v16i16
name|x
parameter_list|)
block|{
return|return
name|x
return|;
block|}
end_function

end_unit

