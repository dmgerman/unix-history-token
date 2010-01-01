begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=i686-apple-darwin -target-feature +ssse3 -O1 -S -o - | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|_mm_alignr_epi8
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|(__builtin_ia32_palignr128((a), (b), (n)))
end_define

begin_define
define|#
directive|define
name|_mm_alignr_pi8
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|(__builtin_ia32_palignr((a), (b), (n*8)))
end_define

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|int
name|int2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|int
name|int4
typedef|;
end_typedef

begin_comment
comment|// CHECK: palignr
end_comment

begin_function
name|int2
name|mmx_align1
parameter_list|(
name|int2
name|a
parameter_list|,
name|int2
name|b
parameter_list|)
block|{
return|return
name|_mm_alignr_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: palignr
end_comment

begin_function
name|int4
name|align1
parameter_list|(
name|int4
name|a
parameter_list|,
name|int4
name|b
parameter_list|)
block|{
return|return
name|_mm_alignr_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: ret
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_comment
comment|// CHECK-NOT: palignr
end_comment

begin_function
name|int4
name|align2
parameter_list|(
name|int4
name|a
parameter_list|,
name|int4
name|b
parameter_list|)
block|{
return|return
name|_mm_alignr_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: psrldq
end_comment

begin_function
name|int4
name|align3
parameter_list|(
name|int4
name|a
parameter_list|,
name|int4
name|b
parameter_list|)
block|{
return|return
name|_mm_alignr_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|17
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: xorps
end_comment

begin_function
name|int4
name|align4
parameter_list|(
name|int4
name|a
parameter_list|,
name|int4
name|b
parameter_list|)
block|{
return|return
name|_mm_alignr_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

end_unit

