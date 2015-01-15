begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -O3 -S -o - -emit-llvm %s | FileCheck %s -check-prefix=O32
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -O3 -S -mabi=n64 -o - -emit-llvm %s | FileCheck %s -check-prefix=N64
end_comment

begin_comment
comment|// check that
end_comment

begin_comment
comment|// 1. vector arguments are passed in integer registers
end_comment

begin_comment
comment|// 2. argument alignment is no larger than 8-byte for O32 and 16-byte for N64.
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
name|int
name|v4i32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|// O32: define void @test_v4sf(i32 inreg %a1.coerce0, i32 inreg %a1.coerce1, i32 inreg %a1.coerce2, i32 inreg %a1.coerce3, i32 signext %a2, i32, i32 inreg %a3.coerce0, i32 inreg %a3.coerce1, i32 inreg %a3.coerce2, i32 inreg %a3.coerce3) [[NUW:#[0-9]+]]
end_comment

begin_comment
comment|// O32: declare i32 @test_v4sf_2(i32 inreg, i32 inreg, i32 inreg, i32 inreg, i32 signext, i32, i32 inreg, i32 inreg, i32 inreg, i32 inreg)
end_comment

begin_comment
comment|// N64: define void @test_v4sf(i64 inreg %a1.coerce0, i64 inreg %a1.coerce1, i32 signext %a2, i64, i64 inreg %a3.coerce0, i64 inreg %a3.coerce1) [[NUW:#[0-9]+]]
end_comment

begin_comment
comment|// N64: declare i32 @test_v4sf_2(i64 inreg, i64 inreg, i32 signext, i64, i64 inreg, i64 inreg)
end_comment

begin_extern
extern|extern test_v4sf_2(v4sf
operator|,
extern|int
operator|,
extern|v4sf
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_v4sf
parameter_list|(
name|v4sf
name|a1
parameter_list|,
name|int
name|a2
parameter_list|,
name|v4sf
name|a3
parameter_list|)
block|{
name|test_v4sf_2
argument_list|(
name|a3
argument_list|,
name|a2
argument_list|,
name|a1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// O32: define void @test_v4i32(i32 inreg %a1.coerce0, i32 inreg %a1.coerce1, i32 inreg %a1.coerce2, i32 inreg %a1.coerce3, i32 signext %a2, i32, i32 inreg %a3.coerce0, i32 inreg %a3.coerce1, i32 inreg %a3.coerce2, i32 inreg %a3.coerce3) [[NUW]]
end_comment

begin_comment
comment|// O32: declare i32 @test_v4i32_2(i32 inreg, i32 inreg, i32 inreg, i32 inreg, i32 signext, i32, i32 inreg, i32 inreg, i32 inreg, i32 inreg)
end_comment

begin_comment
comment|// N64: define void @test_v4i32(i64 inreg %a1.coerce0, i64 inreg %a1.coerce1, i32 signext %a2, i64, i64 inreg %a3.coerce0, i64 inreg %a3.coerce1) [[NUW]]
end_comment

begin_comment
comment|// N64: declare i32 @test_v4i32_2(i64 inreg, i64 inreg, i32 signext, i64, i64 inreg, i64 inreg)
end_comment

begin_extern
extern|extern test_v4i32_2(v4i32
operator|,
extern|int
operator|,
extern|v4i32
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test_v4i32
parameter_list|(
name|v4i32
name|a1
parameter_list|,
name|int
name|a2
parameter_list|,
name|v4i32
name|a3
parameter_list|)
block|{
name|test_v4i32_2
argument_list|(
name|a3
argument_list|,
name|a2
argument_list|,
name|a1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// O32: attributes [[NUW]] = { nounwind{{.*}} }
end_comment

begin_comment
comment|// N64: attributes [[NUW]] = { nounwind{{.*}} }
end_comment

end_unit

