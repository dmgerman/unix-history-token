begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: We should not be testing with -O2 (ie, a dependency on the entire IR optimizer).
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -O2 -triple=x86_64-apple-darwin -target-cpu skylake-avx512 -emit-llvm -o - -Wall -Werror |opt -instnamer -S |FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|long
name|long
name|test_mm512_reduce_max_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp = icmp slt<8 x i64> %shuffle1.i, %__W
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x i64> %__W,<8 x i64> %shuffle1.i
comment|// CHECK: %shuffle3.i = shufflevector<8 x i64> %tmp1,<8 x i64> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = icmp sgt<8 x i64> %tmp1, %shuffle3.i
comment|// CHECK: %tmp3 = select<8 x i1> %tmp2,<8 x i64> %tmp1,<8 x i64> %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<8 x i64> %tmp3,<8 x i64> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = icmp sgt<8 x i64> %tmp3, %shuffle6.i
comment|// CHECK: %.elt.i = extractelement<8 x i1> %tmp4, i32 0
comment|// CHECK: %.elt20.i = extractelement<8 x i64> %tmp3, i32 0
comment|// CHECK: %shuffle6.elt.i = extractelement<8 x i64> %tmp3, i32 1
comment|// CHECK: %vecext.i = select i1 %.elt.i, i64 %.elt20.i, i64 %shuffle6.elt.i
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_reduce_max_epi64
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mm512_reduce_max_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp = icmp ult<8 x i64> %shuffle1.i, %__W
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x i64> %__W,<8 x i64> %shuffle1.i
comment|// CHECK: %shuffle3.i = shufflevector<8 x i64> %tmp1,<8 x i64> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = icmp ugt<8 x i64> %tmp1, %shuffle3.i
comment|// CHECK: %tmp3 = select<8 x i1> %tmp2,<8 x i64> %tmp1,<8 x i64> %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<8 x i64> %tmp3,<8 x i64> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = icmp ugt<8 x i64> %tmp3, %shuffle6.i
comment|// CHECK: %.elt.i = extractelement<8 x i1> %tmp4, i32 0
comment|// CHECK: %.elt20.i = extractelement<8 x i64> %tmp3, i32 0
comment|// CHECK: %shuffle6.elt.i = extractelement<8 x i64> %tmp3, i32 1
comment|// CHECK: %vecext.i = select i1 %.elt.i, i64 %.elt20.i, i64 %shuffle6.elt.i
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_reduce_max_epu64
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|test_mm512_reduce_max_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle1.i = shufflevector<8 x double> %__W,<8 x double> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp = tail call<8 x double> @llvm.x86.avx512.mask.max.pd.512(<8 x double> %__W,<8 x double> %shuffle1.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %shuffle3.i = shufflevector<8 x double> %tmp,<8 x double> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp1 = tail call<8 x double> @llvm.x86.avx512.mask.max.pd.512(<8 x double> %tmp,<8 x double> %shuffle3.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %shuffle6.i = shufflevector<8 x double> %tmp1,<8 x double> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = tail call<8 x double> @llvm.x86.avx512.mask.max.pd.512(<8 x double> %tmp1,<8 x double> %shuffle6.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %vecext.i = extractelement<8 x double> %tmp2, i32 0
comment|// CHECK: ret double %vecext.i
return|return
name|_mm512_reduce_max_pd
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_reduce_min_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp = icmp slt<8 x i64> %shuffle1.i, %__W
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x i64> %__W,<8 x i64> %shuffle1.i
comment|// CHECK: %shuffle3.i = shufflevector<8 x i64> %tmp1,<8 x i64> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = icmp sgt<8 x i64> %tmp1, %shuffle3.i
comment|// CHECK: %tmp3 = select<8 x i1> %tmp2,<8 x i64> %tmp1,<8 x i64> %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<8 x i64> %tmp3,<8 x i64> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = icmp sgt<8 x i64> %tmp3, %shuffle6.i
comment|// CHECK: %.elt.i = extractelement<8 x i1> %tmp4, i32 0
comment|// CHECK: %.elt20.i = extractelement<8 x i64> %tmp3, i32 0
comment|// CHECK: %shuffle6.elt.i = extractelement<8 x i64> %tmp3, i32 1
comment|// CHECK: %vecext.i = select i1 %.elt.i, i64 %.elt20.i, i64 %shuffle6.elt.i
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_reduce_max_epi64
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mm512_reduce_min_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %__W,<8 x i64> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp = icmp ult<8 x i64> %shuffle1.i, %__W
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x i64> %__W,<8 x i64> %shuffle1.i
comment|// CHECK: %shuffle3.i = shufflevector<8 x i64> %tmp1,<8 x i64> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = icmp ugt<8 x i64> %tmp1, %shuffle3.i
comment|// CHECK: %tmp3 = select<8 x i1> %tmp2,<8 x i64> %tmp1,<8 x i64> %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<8 x i64> %tmp3,<8 x i64> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = icmp ugt<8 x i64> %tmp3, %shuffle6.i
comment|// CHECK: %.elt.i = extractelement<8 x i1> %tmp4, i32 0
comment|// CHECK: %.elt20.i = extractelement<8 x i64> %tmp3, i32 0
comment|// CHECK: %shuffle6.elt.i = extractelement<8 x i64> %tmp3, i32 1
comment|// CHECK: %vecext.i = select i1 %.elt.i, i64 %.elt20.i, i64 %shuffle6.elt.i
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_reduce_max_epu64
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|test_mm512_reduce_min_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle1.i = shufflevector<8 x double> %__W,<8 x double> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp = tail call<8 x double> @llvm.x86.avx512.mask.min.pd.512(<8 x double> %__W,<8 x double> %shuffle1.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %shuffle3.i = shufflevector<8 x double> %tmp,<8 x double> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp1 = tail call<8 x double> @llvm.x86.avx512.mask.min.pd.512(<8 x double> %tmp,<8 x double> %shuffle3.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %shuffle6.i = shufflevector<8 x double> %tmp1,<8 x double> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = tail call<8 x double> @llvm.x86.avx512.mask.min.pd.512(<8 x double> %tmp1,<8 x double> %shuffle6.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %vecext.i = extractelement<8 x double> %tmp2, i32 0
comment|// CHECK: ret double %vecext.i
return|return
name|_mm512_reduce_min_pd
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm512_mask_reduce_max_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast i8 %__M to<8 x i1>
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x i64> %__W,<8 x i64><i64 -9223372036854775808, i64 -9223372036854775808, i64 -9223372036854775808, i64 -9223372036854775808, i64 -9223372036854775808, i64 -9223372036854775808, i64 -9223372036854775808, i64 -9223372036854775808>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %tmp1,<8 x i64> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = icmp sgt<8 x i64> %tmp1, %shuffle1.i
comment|// CHECK: %tmp3 = select<8 x i1> %tmp2,<8 x i64> %tmp1,<8 x i64> %shuffle1.i
comment|// CHECK: %shuffle4.i = shufflevector<8 x i64> %tmp3,<8 x i64> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = icmp sgt<8 x i64> %tmp3, %shuffle4.i
comment|// CHECK: %tmp5 = select<8 x i1> %tmp4,<8 x i64> %tmp3,<8 x i64> %shuffle4.i
comment|// CHECK: %shuffle7.i = shufflevector<8 x i64> %tmp5,<8 x i64> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp6 = icmp sgt<8 x i64> %tmp5, %shuffle7.i
comment|// CHECK: %.elt.i = extractelement<8 x i1> %tmp6, i32 0
comment|// CHECK: %.elt22.i = extractelement<8 x i64> %tmp5, i32 0
comment|// CHECK: %shuffle7.elt.i = extractelement<8 x i64> %tmp5, i32 1
comment|// CHECK: %vecext.i = select i1 %.elt.i, i64 %.elt22.i, i64 %shuffle7.elt.i
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_mask_reduce_max_epi64
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|test_mm512_mask_reduce_max_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast i8 %__M to<8 x i1>
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x i64> %__W,<8 x i64> zeroinitializer
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %tmp1,<8 x i64> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = icmp ugt<8 x i64> %tmp1, %shuffle1.i
comment|// CHECK: %tmp3 = select<8 x i1> %tmp2,<8 x i64> %tmp1,<8 x i64> %shuffle1.i
comment|// CHECK: %shuffle4.i = shufflevector<8 x i64> %tmp3,<8 x i64> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = icmp ugt<8 x i64> %tmp3, %shuffle4.i
comment|// CHECK: %tmp5 = select<8 x i1> %tmp4,<8 x i64> %tmp3,<8 x i64> %shuffle4.i
comment|// CHECK: %shuffle7.i = shufflevector<8 x i64> %tmp5,<8 x i64> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp6 = icmp ugt<8 x i64> %tmp5, %shuffle7.i
comment|// CHECK: %.elt.i = extractelement<8 x i1> %tmp6, i32 0
comment|// CHECK: %.elt22.i = extractelement<8 x i64> %tmp5, i32 0
comment|// CHECK: %shuffle7.elt.i = extractelement<8 x i64> %tmp5, i32 1
comment|// CHECK: %vecext.i = select i1 %.elt.i, i64 %.elt22.i, i64 %shuffle7.elt.i
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_mask_reduce_max_epu64
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
name|test_mm512_mask_reduce_max_pd
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512d
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast i8 %__M to<8 x i1>
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x double> %__W,<8 x double><double 0xFFF0000000000000, double 0xFFF0000000000000, double 0xFFF0000000000000, double 0xFFF0000000000000, double 0xFFF0000000000000, double 0xFFF0000000000000, double 0xFFF0000000000000, double 0xFFF0000000000000>
comment|// CHECK: %shuffle1.i = shufflevector<8 x double> %tmp1,<8 x double> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = tail call<8 x double> @llvm.x86.avx512.mask.max.pd.512(<8 x double> %tmp1,<8 x double> %shuffle1.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %shuffle4.i = shufflevector<8 x double> %tmp2,<8 x double> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = tail call<8 x double> @llvm.x86.avx512.mask.max.pd.512(<8 x double> %tmp2,<8 x double> %shuffle4.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %shuffle7.i = shufflevector<8 x double> %tmp3,<8 x double> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = tail call<8 x double> @llvm.x86.avx512.mask.max.pd.512(<8 x double> %tmp3,<8 x double> %shuffle7.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %vecext.i = extractelement<8 x double> %tmp4, i32 0
comment|// CHECK: %conv = fptosi double %vecext.i to i64
comment|// CHECK: ret i64 %conv
return|return
name|_mm512_mask_reduce_max_pd
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
name|test_mm512_mask_reduce_min_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast i8 %__M to<8 x i1>
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x i64> %__W,<8 x i64><i64 9223372036854775807, i64 9223372036854775807, i64 9223372036854775807, i64 9223372036854775807, i64 9223372036854775807, i64 9223372036854775807, i64 9223372036854775807, i64 9223372036854775807>
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %tmp1,<8 x i64> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = icmp slt<8 x i64> %tmp1, %shuffle1.i
comment|// CHECK: %tmp3 = select<8 x i1> %tmp2,<8 x i64> %tmp1,<8 x i64> %shuffle1.i
comment|// CHECK: %shuffle4.i = shufflevector<8 x i64> %tmp3,<8 x i64> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = icmp slt<8 x i64> %tmp3, %shuffle4.i
comment|// CHECK: %tmp5 = select<8 x i1> %tmp4,<8 x i64> %tmp3,<8 x i64> %shuffle4.i
comment|// CHECK: %shuffle7.i = shufflevector<8 x i64> %tmp5,<8 x i64> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp6 = icmp slt<8 x i64> %tmp5, %shuffle7.i
comment|// CHECK: %.elt.i = extractelement<8 x i1> %tmp6, i32 0
comment|// CHECK: %.elt22.i = extractelement<8 x i64> %tmp5, i32 0
comment|// CHECK: %shuffle7.elt.i = extractelement<8 x i64> %tmp5, i32 1
comment|// CHECK: %vecext.i = select i1 %.elt.i, i64 %.elt22.i, i64 %shuffle7.elt.i
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_mask_reduce_min_epi64
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
name|test_mm512_mask_reduce_min_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast i8 %__M to<8 x i1>
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x i64> %__W,<8 x i64> zeroinitializer
comment|// CHECK: %shuffle1.i = shufflevector<8 x i64> %tmp1,<8 x i64> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = icmp ugt<8 x i64> %tmp1, %shuffle1.i
comment|// CHECK: %tmp3 = select<8 x i1> %tmp2,<8 x i64> %tmp1,<8 x i64> %shuffle1.i
comment|// CHECK: %shuffle4.i = shufflevector<8 x i64> %tmp3,<8 x i64> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = icmp ugt<8 x i64> %tmp3, %shuffle4.i
comment|// CHECK: %tmp5 = select<8 x i1> %tmp4,<8 x i64> %tmp3,<8 x i64> %shuffle4.i
comment|// CHECK: %shuffle7.i = shufflevector<8 x i64> %tmp5,<8 x i64> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp6 = icmp ugt<8 x i64> %tmp5, %shuffle7.i
comment|// CHECK: %.elt.i = extractelement<8 x i1> %tmp6, i32 0
comment|// CHECK: %.elt22.i = extractelement<8 x i64> %tmp5, i32 0
comment|// CHECK: %shuffle7.elt.i = extractelement<8 x i64> %tmp5, i32 1
comment|// CHECK: %vecext.i = select i1 %.elt.i, i64 %.elt22.i, i64 %shuffle7.elt.i
comment|// CHECK: ret i64 %vecext.i
return|return
name|_mm512_mask_reduce_max_epu64
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
name|test_mm512_mask_reduce_min_pd
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512d
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast i8 %__M to<8 x i1>
comment|// CHECK: %tmp1 = select<8 x i1> %tmp,<8 x double> %__W,<8 x double><double 0x7FF0000000000000, double 0x7FF0000000000000, double 0x7FF0000000000000, double 0x7FF0000000000000, double 0x7FF0000000000000, double 0x7FF0000000000000, double 0x7FF0000000000000, double 0x7FF0000000000000>
comment|// CHECK: %shuffle1.i = shufflevector<8 x double> %tmp1,<8 x double> undef,<8 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = tail call<8 x double> @llvm.x86.avx512.mask.min.pd.512(<8 x double> %tmp1,<8 x double> %shuffle1.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %shuffle4.i = shufflevector<8 x double> %tmp2,<8 x double> undef,<8 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = tail call<8 x double> @llvm.x86.avx512.mask.min.pd.512(<8 x double> %tmp2,<8 x double> %shuffle4.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %shuffle7.i = shufflevector<8 x double> %tmp3,<8 x double> undef,<8 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = tail call<8 x double> @llvm.x86.avx512.mask.min.pd.512(<8 x double> %tmp3,<8 x double> %shuffle7.i,<8 x double> zeroinitializer, i8 -1, i32 4) #3
comment|// CHECK: %vecext.i = extractelement<8 x double> %tmp4, i32 0
comment|// CHECK: ret double %vecext.i
return|return
name|_mm512_mask_reduce_min_pd
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
name|test_mm512_reduce_max_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> %tmp,<16 x i32> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp1 = icmp slt<16 x i32> %shuffle1.i, %tmp
comment|// CHECK: %tmp2 = select<16 x i1> %tmp1,<16 x i32> %tmp,<16 x i32> %shuffle1.i
comment|// CHECK: %shuffle3.i = shufflevector<16 x i32> %tmp2,<16 x i32> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = icmp sgt<16 x i32> %tmp2, %shuffle3.i
comment|// CHECK: %tmp4 = select<16 x i1> %tmp3,<16 x i32> %tmp2,<16 x i32> %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<16 x i32> %tmp4,<16 x i32> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = icmp sgt<16 x i32> %tmp4, %shuffle6.i
comment|// CHECK: %tmp6 = select<16 x i1> %tmp5,<16 x i32> %tmp4,<16 x i32> %shuffle6.i
comment|// CHECK: %shuffle9.i = shufflevector<16 x i32> %tmp6,<16 x i32> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp7 = icmp sgt<16 x i32> %tmp6, %shuffle9.i
comment|// CHECK: %tmp8 = select<16 x i1> %tmp7,<16 x i32> %tmp6,<16 x i32> %shuffle9.i
comment|// CHECK: %tmp9 = bitcast<16 x i32> %tmp8 to<8 x i64>
comment|// CHECK: %vecext.i = extractelement<8 x i64> %tmp9, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_reduce_max_epi32
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_mm512_reduce_max_epu32
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> %tmp,<16 x i32> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp1 = icmp ult<16 x i32> %shuffle1.i, %tmp
comment|// CHECK: %tmp2 = select<16 x i1> %tmp1,<16 x i32> %tmp,<16 x i32> %shuffle1.i
comment|// CHECK: %shuffle3.i = shufflevector<16 x i32> %tmp2,<16 x i32> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = icmp ugt<16 x i32> %tmp2, %shuffle3.i
comment|// CHECK: %tmp4 = select<16 x i1> %tmp3,<16 x i32> %tmp2,<16 x i32> %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<16 x i32> %tmp4,<16 x i32> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = icmp ugt<16 x i32> %tmp4, %shuffle6.i
comment|// CHECK: %tmp6 = select<16 x i1> %tmp5,<16 x i32> %tmp4,<16 x i32> %shuffle6.i
comment|// CHECK: %shuffle9.i = shufflevector<16 x i32> %tmp6,<16 x i32> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp7 = icmp ugt<16 x i32> %tmp6, %shuffle9.i
comment|// CHECK: %tmp8 = select<16 x i1> %tmp7,<16 x i32> %tmp6,<16 x i32> %shuffle9.i
comment|// CHECK: %tmp9 = bitcast<16 x i32> %tmp8 to<8 x i64>
comment|// CHECK: %vecext.i = extractelement<8 x i64> %tmp9, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_reduce_max_epu32
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm512_reduce_max_ps
parameter_list|(
name|__m512
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle1.i = shufflevector<16 x float> %__W,<16 x float> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp = tail call<16 x float> @llvm.x86.avx512.mask.max.ps.512(<16 x float> %__W,<16 x float> %shuffle1.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle3.i = shufflevector<16 x float> %tmp,<16 x float> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp1 = tail call<16 x float> @llvm.x86.avx512.mask.max.ps.512(<16 x float> %tmp,<16 x float> %shuffle3.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle6.i = shufflevector<16 x float> %tmp1,<16 x float> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = tail call<16 x float> @llvm.x86.avx512.mask.max.ps.512(<16 x float> %tmp1,<16 x float> %shuffle6.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle9.i = shufflevector<16 x float> %tmp2,<16 x float> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = tail call<16 x float> @llvm.x86.avx512.mask.max.ps.512(<16 x float> %tmp2,<16 x float> %shuffle9.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %vecext.i = extractelement<16 x float> %tmp3, i32 0
comment|// CHECK: ret float %vecext.i
return|return
name|_mm512_reduce_max_ps
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_reduce_min_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> %tmp,<16 x i32> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp1 = icmp sgt<16 x i32> %shuffle1.i, %tmp
comment|// CHECK: %tmp2 = select<16 x i1> %tmp1,<16 x i32> %tmp,<16 x i32> %shuffle1.i
comment|// CHECK: %shuffle3.i = shufflevector<16 x i32> %tmp2,<16 x i32> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = icmp slt<16 x i32> %tmp2, %shuffle3.i
comment|// CHECK: %tmp4 = select<16 x i1> %tmp3,<16 x i32> %tmp2,<16 x i32> %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<16 x i32> %tmp4,<16 x i32> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = icmp slt<16 x i32> %tmp4, %shuffle6.i
comment|// CHECK: %tmp6 = select<16 x i1> %tmp5,<16 x i32> %tmp4,<16 x i32> %shuffle6.i
comment|// CHECK: %shuffle9.i = shufflevector<16 x i32> %tmp6,<16 x i32> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp7 = icmp slt<16 x i32> %tmp6, %shuffle9.i
comment|// CHECK: %tmp8 = select<16 x i1> %tmp7,<16 x i32> %tmp6,<16 x i32> %shuffle9.i
comment|// CHECK: %tmp9 = bitcast<16 x i32> %tmp8 to<8 x i64>
comment|// CHECK: %vecext.i = extractelement<8 x i64> %tmp9, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_reduce_min_epi32
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_mm512_reduce_min_epu32
parameter_list|(
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> %tmp,<16 x i32> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp1 = icmp ugt<16 x i32> %shuffle1.i, %tmp
comment|// CHECK: %tmp2 = select<16 x i1> %tmp1,<16 x i32> %tmp,<16 x i32> %shuffle1.i
comment|// CHECK: %shuffle3.i = shufflevector<16 x i32> %tmp2,<16 x i32> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = icmp ult<16 x i32> %tmp2, %shuffle3.i
comment|// CHECK: %tmp4 = select<16 x i1> %tmp3,<16 x i32> %tmp2,<16 x i32> %shuffle3.i
comment|// CHECK: %shuffle6.i = shufflevector<16 x i32> %tmp4,<16 x i32> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = icmp ult<16 x i32> %tmp4, %shuffle6.i
comment|// CHECK: %tmp6 = select<16 x i1> %tmp5,<16 x i32> %tmp4,<16 x i32> %shuffle6.i
comment|// CHECK: %shuffle9.i = shufflevector<16 x i32> %tmp6,<16 x i32> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp7 = icmp ult<16 x i32> %tmp6, %shuffle9.i
comment|// CHECK: %tmp8 = select<16 x i1> %tmp7,<16 x i32> %tmp6,<16 x i32> %shuffle9.i
comment|// CHECK: %tmp9 = bitcast<16 x i32> %tmp8 to<8 x i64>
comment|// CHECK: %vecext.i = extractelement<8 x i64> %tmp9, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_reduce_min_epu32
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm512_reduce_min_ps
parameter_list|(
name|__m512
name|__W
parameter_list|)
block|{
comment|// CHECK: %shuffle1.i = shufflevector<16 x float> %__W,<16 x float> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp = tail call<16 x float> @llvm.x86.avx512.mask.min.ps.512(<16 x float> %__W,<16 x float> %shuffle1.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle3.i = shufflevector<16 x float> %tmp,<16 x float> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp1 = tail call<16 x float> @llvm.x86.avx512.mask.min.ps.512(<16 x float> %tmp,<16 x float> %shuffle3.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle6.i = shufflevector<16 x float> %tmp1,<16 x float> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = tail call<16 x float> @llvm.x86.avx512.mask.min.ps.512(<16 x float> %tmp1,<16 x float> %shuffle6.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle9.i = shufflevector<16 x float> %tmp2,<16 x float> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = tail call<16 x float> @llvm.x86.avx512.mask.min.ps.512(<16 x float> %tmp2,<16 x float> %shuffle9.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %vecext.i = extractelement<16 x float> %tmp3, i32 0
comment|// CHECK: ret float %vecext.i
return|return
name|_mm512_reduce_min_ps
argument_list|(
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_mask_reduce_max_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %tmp1 = bitcast i16 %__M to<16 x i1>
comment|// CHECK: %tmp2 = select<16 x i1> %tmp1,<16 x i32> %tmp,<16 x i32><i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648, i32 -2147483648>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> %tmp2,<16 x i32> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = icmp sgt<16 x i32> %tmp2, %shuffle1.i
comment|// CHECK: %tmp4 = select<16 x i1> %tmp3,<16 x i32> %tmp2,<16 x i32> %shuffle1.i
comment|// CHECK: %shuffle4.i = shufflevector<16 x i32> %tmp4,<16 x i32> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = icmp sgt<16 x i32> %tmp4, %shuffle4.i
comment|// CHECK: %tmp6 = select<16 x i1> %tmp5,<16 x i32> %tmp4,<16 x i32> %shuffle4.i
comment|// CHECK: %shuffle7.i = shufflevector<16 x i32> %tmp6,<16 x i32> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp7 = icmp sgt<16 x i32> %tmp6, %shuffle7.i
comment|// CHECK: %tmp8 = select<16 x i1> %tmp7,<16 x i32> %tmp6,<16 x i32> %shuffle7.i
comment|// CHECK: %shuffle10.i = shufflevector<16 x i32> %tmp8,<16 x i32> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp9 = icmp sgt<16 x i32> %tmp8, %shuffle10.i
comment|// CHECK: %tmp10 = select<16 x i1> %tmp9,<16 x i32> %tmp8,<16 x i32> %shuffle10.i
comment|// CHECK: %tmp11 = bitcast<16 x i32> %tmp10 to<8 x i64>
comment|// CHECK: %vecext.i = extractelement<8 x i64> %tmp11, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_mask_reduce_max_epi32
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_mm512_mask_reduce_max_epu32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %tmp1 = bitcast i16 %__M to<16 x i1>
comment|// CHECK: %tmp2 = select<16 x i1> %tmp1,<16 x i32> %tmp,<16 x i32> zeroinitializer
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> %tmp2,<16 x i32> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = icmp ugt<16 x i32> %tmp2, %shuffle1.i
comment|// CHECK: %tmp4 = select<16 x i1> %tmp3,<16 x i32> %tmp2,<16 x i32> %shuffle1.i
comment|// CHECK: %shuffle4.i = shufflevector<16 x i32> %tmp4,<16 x i32> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = icmp ugt<16 x i32> %tmp4, %shuffle4.i
comment|// CHECK: %tmp6 = select<16 x i1> %tmp5,<16 x i32> %tmp4,<16 x i32> %shuffle4.i
comment|// CHECK: %shuffle7.i = shufflevector<16 x i32> %tmp6,<16 x i32> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp7 = icmp ugt<16 x i32> %tmp6, %shuffle7.i
comment|// CHECK: %tmp8 = select<16 x i1> %tmp7,<16 x i32> %tmp6,<16 x i32> %shuffle7.i
comment|// CHECK: %shuffle10.i = shufflevector<16 x i32> %tmp8,<16 x i32> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp9 = icmp ugt<16 x i32> %tmp8, %shuffle10.i
comment|// CHECK: %tmp10 = select<16 x i1> %tmp9,<16 x i32> %tmp8,<16 x i32> %shuffle10.i
comment|// CHECK: %tmp11 = bitcast<16 x i32> %tmp10 to<8 x i64>
comment|// CHECK: %vecext.i = extractelement<8 x i64> %tmp11, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_mask_reduce_max_epu32
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
name|test_mm512_mask_reduce_max_ps
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast i16 %__M to<16 x i1>
comment|// CHECK: %tmp1 = select<16 x i1> %tmp,<16 x float> %__W,<16 x float><float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000, float 0xFFF0000000000000>
comment|// CHECK: %shuffle1.i = shufflevector<16 x float> %tmp1,<16 x float> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = tail call<16 x float> @llvm.x86.avx512.mask.max.ps.512(<16 x float> %tmp1,<16 x float> %shuffle1.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle4.i = shufflevector<16 x float> %tmp2,<16 x float> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = tail call<16 x float> @llvm.x86.avx512.mask.max.ps.512(<16 x float> %tmp2,<16 x float> %shuffle4.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle7.i = shufflevector<16 x float> %tmp3,<16 x float> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = tail call<16 x float> @llvm.x86.avx512.mask.max.ps.512(<16 x float> %tmp3,<16 x float> %shuffle7.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle10.i = shufflevector<16 x float> %tmp4,<16 x float> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = tail call<16 x float> @llvm.x86.avx512.mask.max.ps.512(<16 x float> %tmp4,<16 x float> %shuffle10.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %vecext.i = extractelement<16 x float> %tmp5, i32 0
comment|// CHECK: ret float %vecext.i
return|return
name|_mm512_mask_reduce_max_ps
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
name|test_mm512_mask_reduce_min_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %tmp1 = bitcast i16 %__M to<16 x i1>
comment|// CHECK: %tmp2 = select<16 x i1> %tmp1,<16 x i32> %tmp,<16 x i32><i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647, i32 2147483647>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> %tmp2,<16 x i32> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = icmp slt<16 x i32> %tmp2, %shuffle1.i
comment|// CHECK: %tmp4 = select<16 x i1> %tmp3,<16 x i32> %tmp2,<16 x i32> %shuffle1.i
comment|// CHECK: %shuffle4.i = shufflevector<16 x i32> %tmp4,<16 x i32> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = icmp slt<16 x i32> %tmp4, %shuffle4.i
comment|// CHECK: %tmp6 = select<16 x i1> %tmp5,<16 x i32> %tmp4,<16 x i32> %shuffle4.i
comment|// CHECK: %shuffle7.i = shufflevector<16 x i32> %tmp6,<16 x i32> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp7 = icmp slt<16 x i32> %tmp6, %shuffle7.i
comment|// CHECK: %tmp8 = select<16 x i1> %tmp7,<16 x i32> %tmp6,<16 x i32> %shuffle7.i
comment|// CHECK: %shuffle10.i = shufflevector<16 x i32> %tmp8,<16 x i32> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp9 = icmp slt<16 x i32> %tmp8, %shuffle10.i
comment|// CHECK: %tmp10 = select<16 x i1> %tmp9,<16 x i32> %tmp8,<16 x i32> %shuffle10.i
comment|// CHECK: %tmp11 = bitcast<16 x i32> %tmp10 to<8 x i64>
comment|// CHECK: %vecext.i = extractelement<8 x i64> %tmp11, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_mask_reduce_min_epi32
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_mm512_mask_reduce_min_epu32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast<8 x i64> %__W to<16 x i32>
comment|// CHECK: %tmp1 = bitcast i16 %__M to<16 x i1>
comment|// CHECK: %tmp2 = select<16 x i1> %tmp1,<16 x i32> %tmp,<16 x i32><i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: %shuffle1.i = shufflevector<16 x i32> %tmp2,<16 x i32> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = icmp ult<16 x i32> %tmp2, %shuffle1.i
comment|// CHECK: %tmp4 = select<16 x i1> %tmp3,<16 x i32> %tmp2,<16 x i32> %shuffle1.i
comment|// CHECK: %shuffle4.i = shufflevector<16 x i32> %tmp4,<16 x i32> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = icmp ult<16 x i32> %tmp4, %shuffle4.i
comment|// CHECK: %tmp6 = select<16 x i1> %tmp5,<16 x i32> %tmp4,<16 x i32> %shuffle4.i
comment|// CHECK: %shuffle7.i = shufflevector<16 x i32> %tmp6,<16 x i32> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp7 = icmp ult<16 x i32> %tmp6, %shuffle7.i
comment|// CHECK: %tmp8 = select<16 x i1> %tmp7,<16 x i32> %tmp6,<16 x i32> %shuffle7.i
comment|// CHECK: %shuffle10.i = shufflevector<16 x i32> %tmp8,<16 x i32> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp9 = icmp ult<16 x i32> %tmp8, %shuffle10.i
comment|// CHECK: %tmp10 = select<16 x i1> %tmp9,<16 x i32> %tmp8,<16 x i32> %shuffle10.i
comment|// CHECK: %tmp11 = bitcast<16 x i32> %tmp10 to<8 x i64>
comment|// CHECK: %vecext.i = extractelement<8 x i64> %tmp11, i32 0
comment|// CHECK: %conv.i = trunc i64 %vecext.i to i32
comment|// CHECK: ret i32 %conv.i
return|return
name|_mm512_mask_reduce_min_epu32
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
name|test_mm512_mask_reduce_min_ps
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512
name|__W
parameter_list|)
block|{
comment|// CHECK: %tmp = bitcast i16 %__M to<16 x i1>
comment|// CHECK: %tmp1 = select<16 x i1> %tmp,<16 x float> %__W,<16 x float><float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000, float 0x7FF0000000000000>
comment|// CHECK: %shuffle1.i = shufflevector<16 x float> %tmp1,<16 x float> undef,<16 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp2 = tail call<16 x float> @llvm.x86.avx512.mask.min.ps.512(<16 x float> %tmp1,<16 x float> %shuffle1.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle4.i = shufflevector<16 x float> %tmp2,<16 x float> undef,<16 x i32><i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp3 = tail call<16 x float> @llvm.x86.avx512.mask.min.ps.512(<16 x float> %tmp2,<16 x float> %shuffle4.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle7.i = shufflevector<16 x float> %tmp3,<16 x float> undef,<16 x i32><i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp4 = tail call<16 x float> @llvm.x86.avx512.mask.min.ps.512(<16 x float> %tmp3,<16 x float> %shuffle7.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %shuffle10.i = shufflevector<16 x float> %tmp4,<16 x float> undef,<16 x i32><i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: %tmp5 = tail call<16 x float> @llvm.x86.avx512.mask.min.ps.512(<16 x float> %tmp4,<16 x float> %shuffle10.i,<16 x float> zeroinitializer, i16 -1, i32 4) #3
comment|// CHECK: %vecext.i = extractelement<16 x float> %tmp5, i32 0
comment|// CHECK: ret float %vecext.i
return|return
name|_mm512_mask_reduce_min_ps
argument_list|(
name|__M
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

end_unit

