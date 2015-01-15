begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -O3 -S -o - -emit-llvm %s | FileCheck %s -check-prefix=O32
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -O3 -S -mabi=n64 -o - -emit-llvm %s | FileCheck %s -check-prefix=N64
end_comment

begin_comment
comment|// vectors larger than 16-bytes are returned via the hidden pointer argument.
end_comment

begin_comment
comment|// N64/N32 returns vectors whose size is equal to or smaller than 16-bytes in
end_comment

begin_comment
comment|// integer registers.
end_comment

begin_typedef
typedef|typedef
name|float
name|v4sf
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|double
name|v4df
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|v4i32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|// O32-LABEL: define void @test_v4sf(<4 x float>* noalias nocapture sret
end_comment

begin_comment
comment|// N64: define inreg { i64, i64 } @test_v4sf
end_comment

begin_function
name|v4sf
name|test_v4sf
parameter_list|(
name|float
name|a
parameter_list|)
block|{
return|return
operator|(
name|v4sf
operator|)
block|{
literal|0.0f
block|,
name|a
block|,
literal|0.0f
block|,
literal|0.0f
block|}
return|;
block|}
end_function

begin_comment
comment|// O32-LABEL: define void @test_v4df(<4 x double>* noalias nocapture sret
end_comment

begin_comment
comment|// N64-LABEL: define void @test_v4df(<4 x double>* noalias nocapture sret
end_comment

begin_function
name|v4df
name|test_v4df
parameter_list|(
name|double
name|a
parameter_list|)
block|{
return|return
operator|(
name|v4df
operator|)
block|{
literal|0.0
block|,
name|a
block|,
literal|0.0
block|,
literal|0.0
block|}
return|;
block|}
end_function

begin_comment
comment|// O32 returns integer vectors whose size is equal to or smaller than 16-bytes
end_comment

begin_comment
comment|// in integer registers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// O32: define inreg { i32, i32, i32, i32 } @test_v4i32
end_comment

begin_comment
comment|// N64: define inreg { i64, i64 } @test_v4i32
end_comment

begin_function
name|v4i32
name|test_v4i32
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
operator|(
name|v4i32
operator|)
block|{
literal|0
block|,
name|a
block|,
literal|0
block|,
literal|0
block|}
return|;
block|}
end_function

end_unit

