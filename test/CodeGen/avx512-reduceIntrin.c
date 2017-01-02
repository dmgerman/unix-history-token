begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -O2 -triple=x86_64-apple-darwin -target-cpu skylake-avx512 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|long
name|long
name|test_mm512_reduce_add_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %add.i = add<4 x i64> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x i64> %add.i,<4 x i64> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x i64> %add.i,<4 x i64> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %add4.i = add<2 x i64> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x i64> %add4.i,<2 x i64> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %add7.i = add<2 x i64> %shuffle6.i, %add4.i
comment|// CHECK: %vecext.i = extractelement<2 x i64> %add7.i, i32 0
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_reduce_add_epi64
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_reduce_mul_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %mul.i = mul<4 x i64> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x i64> %mul.i,<4 x i64> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x i64> %mul.i,<4 x i64> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %mul4.i = mul<2 x i64> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x i64> %mul4.i,<2 x i64> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %mul7.i = mul<2 x i64> %shuffle6.i, %mul4.i
comment|// CHECK: %vecext.i = extractelement<2 x i64> %mul7.i, i32 0
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_reduce_mul_epi64
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_reduce_or_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %or.i = or<4 x i64> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x i64> %or.i,<4 x i64> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x i64> %or.i,<4 x i64> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %or4.i = or<2 x i64> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x i64> %or4.i,<2 x i64> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %or7.i = or<2 x i64> %shuffle6.i, %or4.i
comment|// CHECK: %vecext.i = extractelement<2 x i64> %or7.i, i32 0
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_reduce_or_epi64
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_reduce_and_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %and.i = and<4 x i64> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x i64> %and.i,<4 x i64> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x i64> %and.i,<4 x i64> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %and4.i = and<2 x i64> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x i64> %and4.i,<2 x i64> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %and7.i = and<2 x i64> %shuffle6.i, %and4.i
comment|// CHECK: %vecext.i = extractelement<2 x i64> %and7.i, i32 0
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_reduce_and_epi64
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_mask_reduce_add_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast i8 %__M to<8 x i1>
comment|// CHECK: {{.*}} = select<8 x i1> {{.*}},<8 x i64> %__W,<8 x i64> zeroinitializer
comment|// CHECK: %shuffle.i = shufflevector<8 x i64> {{.*}},<8 x i64> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> {{.*}},<8 x i64> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %add.i = add<4 x i64> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x i64> %add.i,<4 x i64> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x i64> %add.i,<4 x i64> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %add4.i = add<2 x i64> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x i64> %add4.i,<2 x i64> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %add7.i = add<2 x i64> %shuffle6.i, %add4.i
comment|// CHECK: %vecext.i = extractelement<2 x i64> %add7.i, i32 0
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_mask_reduce_add_epi64
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_mask_reduce_mul_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast i8 %__M to<8 x i1>
comment|// CHECK: {{.*}} = select<8 x i1> {{.*}},<8 x i64> %__W,<8 x i64><i64 1, i64 1, i64 1, i64 1, i64 1, i64 1, i64 1, i64 1>
comment|// CHECK: %shuffle.i = shufflevector<8 x i64> {{.*}},<8 x i64> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> {{.*}},<8 x i64> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %mul.i = mul<4 x i64> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x i64> %mul.i,<4 x i64> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x i64> %mul.i,<4 x i64> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %mul4.i = mul<2 x i64> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x i64> %mul4.i,<2 x i64> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %mul7.i = mul<2 x i64> %shuffle6.i, %mul4.i
comment|// CHECK: %vecext.i = extractelement<2 x i64> %mul7.i, i32 0
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_mask_reduce_mul_epi64
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_mask_reduce_and_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast i8 %__M to<8 x i1>
comment|// CHECK: {{.*}} = select<8 x i1> {{.*}},<8 x i64> %__W,<8 x i64><i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: %shuffle.i = shufflevector<8 x i64> {{.*}},<8 x i64> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> {{.*}},<8 x i64> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %and.i = and<4 x i64> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x i64> %and.i,<4 x i64> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x i64> %and.i,<4 x i64> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %and4.i = and<2 x i64> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x i64> %and4.i,<2 x i64> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %and7.i = and<2 x i64> %shuffle6.i, %and4.i
comment|// CHECK: %vecext.i = extractelement<2 x i64> %and7.i, i32 0
return|return
name|_mm512_mask_reduce_and_epi64
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_mask_reduce_or_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast i8 %__M to<8 x i1>
comment|// CHECK: {{.*}} = select<8 x i1> {{.*}},<8 x i64> %__W,<8 x i64> zeroinitializer
comment|// CHECK: %shuffle.i = shufflevector<8 x i64> {{.*}},<8 x i64> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> {{.*}},<8 x i64> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %or.i = or<4 x i64> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x i64> %or.i,<4 x i64> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x i64> %or.i,<4 x i64> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %or4.i = or<2 x i64> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x i64> %or4.i,<2 x i64> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %or7.i = or<2 x i64> %shuffle6.i, %or4.i
comment|// CHECK: %vecext.i = extractelement<2 x i64> %or7.i, i32 0
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_mask_reduce_or_epi64
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_reduce_add_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %shuffle.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %add.i = add<8 x i32> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x i32> %add.i,<8 x i32> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x i32> %add.i,<8 x i32> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %add4.i = add<4 x i32> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x i32> %add4.i,<4 x i32> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %add7.i = add<4 x i32> %shuffle6.i, %add4.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x i32> %add7.i,<4 x i32> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %add10.i = add<4 x i32> %shuffle9.i, %add7.i
comment|// CHECK: {{.*}} = bitcast<4 x i32> %add10.i to<2 x i64>
comment|// CHECK: %vecext.i = extractelement<2 x i64> {{.*}}, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_reduce_add_epi32
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_reduce_mul_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %shuffle.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %mul.i = mul<8 x i32> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x i32> %mul.i,<8 x i32> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x i32> %mul.i,<8 x i32> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %mul4.i = mul<4 x i32> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x i32> %mul4.i,<4 x i32> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %mul7.i = mul<4 x i32> %shuffle6.i, %mul4.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x i32> %mul7.i,<4 x i32> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %mul10.i = mul<4 x i32> %shuffle9.i, %mul7.i
comment|// CHECK: {{.*}} = bitcast<4 x i32> %mul10.i to<2 x i64>
comment|// CHECK: %vecext.i = extractelement<2 x i64> {{.*}}, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_reduce_mul_epi32
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_reduce_or_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %shuffle.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %or.i = or<8 x i32> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x i32> %or.i,<8 x i32> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x i32> %or.i,<8 x i32> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %or4.i = or<4 x i32> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x i32> %or4.i,<4 x i32> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %or7.i = or<4 x i32> %shuffle6.i, %or4.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x i32> %or7.i,<4 x i32> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %or10.i = or<4 x i32> %shuffle9.i, %or7.i
comment|// CHECK: {{.*}} = bitcast<4 x i32> %or10.i to<2 x i64>
comment|// CHECK: %vecext.i = extractelement<2 x i64> {{.*}}, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_reduce_or_epi32
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_reduce_and_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %shuffle.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %and.i = and<8 x i32> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x i32> %and.i,<8 x i32> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x i32> %and.i,<8 x i32> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %and4.i = and<4 x i32> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x i32> %and4.i,<4 x i32> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %and7.i = and<4 x i32> %shuffle6.i, %and4.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x i32> %and7.i,<4 x i32> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %and10.i = and<4 x i32> %shuffle9.i, %and7.i
comment|// CHECK: {{.*}} = bitcast<4 x i32> %and10.i to<2 x i64>
comment|// CHECK: %vecext.i = extractelement<2 x i64> {{.*}}, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_reduce_and_epi32
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_mask_reduce_add_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: {{.*}} = bitcast i16 %__M to<16 x i1>
comment|// CHECK: {{.*}} = select<16 x i1> {{.*}},<16 x i32> {{.*}},<16 x i32> zeroinitializer
comment|// CHECK: %shuffle.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %add.i = add<8 x i32> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x i32> %add.i,<8 x i32> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x i32> %add.i,<8 x i32> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %add4.i = add<4 x i32> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x i32> %add4.i,<4 x i32> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %add7.i = add<4 x i32> %shuffle6.i, %add4.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x i32> %add7.i,<4 x i32> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %add10.i = add<4 x i32> %shuffle9.i, %add7.i
comment|// CHECK: {{.*}} = bitcast<4 x i32> %add10.i to<2 x i64>
comment|// CHECK: %vecext.i = extractelement<2 x i64> {{.*}}, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_mask_reduce_add_epi32
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_mask_reduce_mul_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: {{.*}} = bitcast i16 %__M to<16 x i1>
comment|// CHECK: {{.*}} = select<16 x i1> {{.*}},<16 x i32> {{.*}},<16 x i32><i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1>
comment|// CHECK: %shuffle.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %mul.i = mul<8 x i32> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x i32> %mul.i,<8 x i32> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x i32> %mul.i,<8 x i32> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %mul4.i = mul<4 x i32> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x i32> %mul4.i,<4 x i32> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %mul7.i = mul<4 x i32> %shuffle6.i, %mul4.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x i32> %mul7.i,<4 x i32> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %mul10.i = mul<4 x i32> %shuffle9.i, %mul7.i
comment|// CHECK: {{.*}} = bitcast<4 x i32> %mul10.i to<2 x i64>
comment|// CHECK: %vecext.i = extractelement<2 x i64> {{.*}}, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_mask_reduce_mul_epi32
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_mask_reduce_and_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: {{.*}} = bitcast i16 %__M to<16 x i1>
comment|// CHECK: {{.*}} = select<16 x i1> {{.*}},<16 x i32> {{.*}},<16 x i32><i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: %shuffle.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %and.i = and<8 x i32> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x i32> %and.i,<8 x i32> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x i32> %and.i,<8 x i32> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %and4.i = and<4 x i32> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x i32> %and4.i,<4 x i32> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %and7.i = and<4 x i32> %shuffle6.i, %and4.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x i32> %and7.i,<4 x i32> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %and10.i = and<4 x i32> %shuffle9.i, %and7.i
comment|// CHECK: {{.*}} = bitcast<4 x i32> %and10.i to<2 x i64>
comment|// CHECK: %vecext.i = extractelement<2 x i64> {{.*}}, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_mask_reduce_and_epi32
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_mask_reduce_or_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: {{.*}} = bitcast i16 %__M to<16 x i1>
comment|// CHECK: {{.*}} = select<16 x i1> {{.*}},<16 x i32> {{.*}},<16 x i32> zeroinitializer
comment|// CHECK: %shuffle.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> {{.*}},<16 x i32> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %or.i = or<8 x i32> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x i32> %or.i,<8 x i32> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x i32> %or.i,<8 x i32> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %or4.i = or<4 x i32> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x i32> %or4.i,<4 x i32> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %or7.i = or<4 x i32> %shuffle6.i, %or4.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x i32> %or7.i,<4 x i32> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %or10.i = or<4 x i32> %shuffle9.i, %or7.i
comment|// CHECK: {{.*}} = bitcast<4 x i32> %or10.i to<2 x i64>
comment|// CHECK: %vecext.i = extractelement<2 x i64> {{.*}}, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_mask_reduce_or_epi32
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|test_mm512_reduce_add_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle.i = shufflevector<8 x double> %__W,<8 x double> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x double> %__W,<8 x double> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %add.i = fadd<4 x double> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x double> %add.i,<4 x double> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x double> %add.i,<4 x double> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %add4.i = fadd<2 x double> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x double> %add4.i,<2 x double> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %add7.i = fadd<2 x double> %add4.i, %shuffle6.i
comment|// CHECK: %vecext.i = extractelement<2 x double> %add7.i, i32 0
comment|// CHECK: ret double %vecext.i
return|return
name|_mm512_reduce_add_pd
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|test_mm512_reduce_mul_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle.i = shufflevector<8 x double> %__W,<8 x double> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x double> %__W,<8 x double> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %mul.i = fmul<4 x double> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x double> %mul.i,<4 x double> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x double> %mul.i,<4 x double> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %mul4.i = fmul<2 x double> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x double> %mul4.i,<2 x double> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %mul7.i = fmul<2 x double> %mul4.i, %shuffle6.i
comment|// CHECK: %vecext.i = extractelement<2 x double> %mul7.i, i32 0
comment|// CHECK: ret double %vecext.i
return|return
name|_mm512_reduce_mul_pd
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm512_reduce_add_ps
parameter_list|(
name|__m512
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle.i = shufflevector<16 x float> %__W,<16 x float> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x float> %__W,<16 x float> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %add.i = fadd<8 x float> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x float> %add.i,<8 x float> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x float> %add.i,<8 x float> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %add4.i = fadd<4 x float> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x float> %add4.i,<4 x float> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %add7.i = fadd<4 x float> %add4.i, %shuffle6.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x float> %add7.i,<4 x float> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %add10.i = fadd<4 x float> %add7.i, %shuffle9.i
comment|// CHECK: %vecext.i = extractelement<4 x float> %add10.i, i32 0
comment|// CHECK: ret float %vecext.i
return|return
name|_mm512_reduce_add_ps
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm512_reduce_mul_ps
parameter_list|(
name|__m512
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle.i = shufflevector<16 x float> %__W,<16 x float> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x float> %__W,<16 x float> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %mul.i = fmul<8 x float> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x float> %mul.i,<8 x float> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x float> %mul.i,<8 x float> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %mul4.i = fmul<4 x float> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x float> %mul4.i,<4 x float> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %mul7.i = fmul<4 x float> %mul4.i, %shuffle6.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x float> %mul7.i,<4 x float> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %mul10.i = fmul<4 x float> %mul7.i, %shuffle9.i
comment|// CHECK: %vecext.i = extractelement<4 x float> %mul10.i, i32 0
comment|// CHECK: ret float %vecext.i
return|return
name|_mm512_reduce_mul_ps
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|test_mm512_mask_reduce_add_pd
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512d
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast i8 %__M to<8 x i1>
comment|// CHECK: {{.*}} = select<8 x i1> {{.*}},<8 x double> %__W,<8 x double> zeroinitializer
comment|// CHECK: %shuffle.i = shufflevector<8 x double> {{.*}},<8 x double> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x double> {{.*}},<8 x double> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %add.i = fadd<4 x double> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x double> %add.i,<4 x double> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x double> %add.i,<4 x double> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %add4.i = fadd<2 x double> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x double> %add4.i,<2 x double> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %add7.i = fadd<2 x double> %add4.i, %shuffle6.i
comment|// CHECK: %vecext.i = extractelement<2 x double> %add7.i, i32 0
comment|// CHECK: ret double %vecext.i
return|return
name|_mm512_mask_reduce_add_pd
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|test_mm512_mask_reduce_mul_pd
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512d
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast i8 %__M to<8 x i1>
comment|// CHECK: {{.*}} = select<8 x i1> {{.*}},<8 x double> %__W,<8 x double><double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00, double 1.000000e+00>
comment|// CHECK: %shuffle.i = shufflevector<8 x double> {{.*}},<8 x double> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle1.i = shufflevector<8 x double> {{.*}},<8 x double> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %mul.i = fmul<4 x double> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<4 x double> %mul.i,<4 x double> undef,<2 x i32><i32 0, i32 1>
comment|// CHECK: %shuffle3.i = shufflevector<4 x double> %mul.i,<4 x double> undef,<2 x i32><i32 2, i32 3>
comment|// CHECK: %mul4.i = fmul<2 x double> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<2 x double> %mul4.i,<2 x double> undef,<2 x i32><i32 1, i32 undef>
comment|// CHECK: %mul7.i = fmul<2 x double> %mul4.i, %shuffle6.i
comment|// CHECK: %vecext.i = extractelement<2 x double> %mul7.i, i32 0
comment|// CHECK: ret double %vecext.i
return|return
name|_mm512_mask_reduce_mul_pd
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm512_mask_reduce_add_ps
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast i16 %__M to<16 x i1>
comment|// CHECK: {{.*}} = select<16 x i1> {{.*}},<16 x float> %__W,<16 x float> zeroinitializer
comment|// CHECK: %shuffle.i = shufflevector<16 x float> {{.*}},<16 x float> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x float> {{.*}},<16 x float> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %add.i = fadd<8 x float> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x float> %add.i,<8 x float> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x float> %add.i,<8 x float> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %add4.i = fadd<4 x float> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x float> %add4.i,<4 x float> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %add7.i = fadd<4 x float> %add4.i, %shuffle6.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x float> %add7.i,<4 x float> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %add10.i = fadd<4 x float> %add7.i, %shuffle9.i
comment|// CHECK: %vecext.i = extractelement<4 x float> %add10.i, i32 0
comment|// CHECK: ret float %vecext.i
return|return
name|_mm512_mask_reduce_add_ps
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm512_mask_reduce_mul_ps
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512
name|__W
parameter_list|)
block|{
comment|// CHECK: {{.*}} = bitcast i16 %__M to<16 x i1>
comment|// CHECK: {{.*}} = select<16 x i1> {{.*}},<16 x float> %__W,<16 x float><float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00>
comment|// CHECK: %shuffle.i = shufflevector<16 x float> {{.*}},<16 x float> undef,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %shuffle1.i = shufflevector<16 x float> {{.*}},<16 x float> undef,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: %mul.i = fmul<8 x float> %shuffle.i, %shuffle1.i
comment|// CHECK: %shuffle2.i = shufflevector<8 x float> %mul.i,<8 x float> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %shuffle3.i = shufflevector<8 x float> %mul.i,<8 x float> undef,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: %mul4.i = fmul<4 x float> %shuffle2.i, %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<4 x float> %mul4.i,<4 x float> undef,<4 x i32><i32 2, i32 3, i32 undef, i32 undef>
comment|// CHECK: %mul7.i = fmul<4 x float> %mul4.i, %shuffle6.i
comment|// CHECK: %shuffle9.i = shufflevector<4 x float> %mul7.i,<4 x float> undef,<4 x i32><i32 1, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %mul10.i = fmul<4 x float> %mul7.i, %shuffle9.i
comment|// CHECK: %vecext.i = extractelement<4 x float> %mul10.i, i32 0
comment|// CHECK: ret float %vecext.i
return|return
name|_mm512_mask_reduce_mul_ps
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

end_unit

