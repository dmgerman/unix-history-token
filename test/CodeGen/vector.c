begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin9 -O1 -target-cpu pentium4 -target-feature +sse4.1 -g -emit-llvm %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|short
name|__v4hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_function
name|void
name|test1
parameter_list|()
block|{
name|__v4hi
name|A
init|=
operator|(
name|__v4hi
operator|)
literal|0LL
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|__v4hi
name|x
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__v4hi
name|y
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|vty
name|__attribute
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|int
name|test2
parameter_list|()
block|{
name|vty
name|b
decl_stmt|;
return|return
name|b
index|[
literal|2LL
index|]
return|;
block|}
end_function

begin_comment
comment|// PR4339
end_comment

begin_typedef
typedef|typedef
name|float
name|vec4
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|void
name|test3
parameter_list|(
name|vec4
modifier|*
name|a
parameter_list|,
name|char
name|b
parameter_list|,
name|float
name|c
parameter_list|)
block|{
operator|(
operator|*
name|a
operator|)
index|[
name|b
index|]
operator|=
name|c
expr_stmt|;
block|}
end_function

begin_comment
comment|// Don't include mm_malloc.h, it's system specific.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_include
include|#
directive|include
file|<mmintrin.h>
end_include

begin_function
name|int
name|test4
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|array
index|[
literal|16
index|]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|}
decl_stmt|;
name|__m64
modifier|*
name|p
init|=
operator|(
name|__m64
operator|*
operator|)
name|array
decl_stmt|;
name|__m64
name|accum
init|=
name|_mm_setzero_si64
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
operator|++
name|i
control|)
name|accum
operator|=
name|_mm_add_pi32
argument_list|(
name|p
index|[
name|i
index|]
argument_list|,
name|accum
argument_list|)
expr_stmt|;
name|__m64
name|accum2
init|=
name|_mm_unpackhi_pi32
argument_list|(
name|accum
argument_list|,
name|accum
argument_list|)
decl_stmt|;
name|accum
operator|=
name|_mm_add_pi32
argument_list|(
name|accum
argument_list|,
name|accum2
argument_list|)
expr_stmt|;
name|int
name|result
init|=
name|_mm_cvtsi64_si32
argument_list|(
name|accum
argument_list|)
decl_stmt|;
name|_mm_empty
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_include
include|#
directive|include
file|<smmintrin.h>
end_include

begin_function
name|unsigned
name|long
name|test_epi8
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
return|return
name|_mm_extract_epi8
argument_list|(
name|x
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test_epi8
end_comment

begin_comment
comment|// CHECK: extractelement<16 x i8> {{.*}}, i32 4
end_comment

begin_comment
comment|// CHECK: zext i8 {{.*}} to i32
end_comment

begin_function
name|unsigned
name|long
name|test_epi16
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
return|return
name|_mm_extract_epi16
argument_list|(
name|x
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test_epi16
end_comment

begin_comment
comment|// CHECK: extractelement<8 x i16> {{.*}}, i32 3
end_comment

begin_comment
comment|// CHECK: zext i16 {{.*}} to i32
end_comment

begin_function
name|void
name|extractinttypes
parameter_list|()
block|{
specifier|extern
name|int
name|check_extract_result_int
decl_stmt|;
extern|extern __typeof(_mm_extract_epi8(_mm_setzero_si128(
block|)
operator|,
function|3
end_function

begin_expr_stmt
unit|))
name|check_result_int
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __typeof(_mm_extract_epi16(_mm_setzero_si128(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
literal|3
end_expr_stmt

begin_expr_stmt
unit|))
name|check_result_int
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __typeof(_mm_extract_epi32(_mm_setzero_si128(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
literal|3
end_expr_stmt

begin_expr_stmt
unit|))
name|check_result_int
expr_stmt|;
end_expr_stmt

unit|}
end_unit

