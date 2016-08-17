begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- emmintrin.h - SSE2 intrinsics ------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EMMINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__EMMINTRIN_H
end_define

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_typedef
typedef|typedef
name|double
name|__m128d
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__m128i
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|/* Type defines.  */
end_comment

begin_typedef
typedef|typedef
name|double
name|__v2df
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__v2di
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|__v8hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|char
name|__v16qi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|/* Unsigned types */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|__v2du
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|__v8hu
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__v16qu
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_comment
comment|/* We need an explicitly signed variant for char. Note that this shouldn't  * appear in the interface though. */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|__v16qs
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_include
include|#
directive|include
file|<f16cintrin.h>
end_include

begin_comment
comment|/* Define the default attributes for the functions in this file. */
end_comment

begin_define
define|#
directive|define
name|__DEFAULT_FN_ATTRS
value|__attribute__((__always_inline__, __nodebug__, __target__("sse2")))
end_define

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_add_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|+=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_add_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
operator|+
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_sub_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|-=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_sub_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
operator|-
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_mul_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|*=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_mul_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
operator|*
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_div_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|/=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_div_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
operator|/
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_sqrt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_sqrtsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_sqrt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_sqrtpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_min_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_minsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_min_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_minpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_max_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_maxsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_max_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_maxpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_and_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator|&
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_andnot_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|~
operator|(
name|__v4su
operator|)
name|__a
operator|&
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_or_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator||
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_xor_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128d
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator|^
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpeqpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpltpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmple_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmplepd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpltpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpge_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmplepd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpord_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpordpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpunord_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpunordpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpneq_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpneqpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnlt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnltpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnle_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnlepd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpngt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnltpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnge_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnlepd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpeqsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpltsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmple_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmplesd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_cmpltsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpge_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_cmplesd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpord_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpordsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpunord_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpunordsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpneq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpneqsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnlt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnltsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnle_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_cmpnlesd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpngt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_cmpnltsd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cmpnge_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
name|__m128d
name|__c
init|=
name|__builtin_ia32_cmpnlesd
argument_list|(
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__c
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comieq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdeq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comilt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdlt
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comile_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdle
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comigt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdgt
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comige_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdge
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_comineq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_comisdneq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomieq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdeq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomilt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdlt
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomile_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdle
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomigt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdgt
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomige_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdge
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_ucomineq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_ucomisdneq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpd_ps
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtpd2ps
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtps_pd
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2df
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi32_pd
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_convertvector
argument_list|(
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|,
name|__v2df
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpd_epi32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtpd2dq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsd_si32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtsd2si
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsd_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__builtin_ia32_cvtsd2ss
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi32_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|int
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|=
name|__b
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtss_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|=
name|__b
index|[
literal|0
index|]
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvttpd_epi32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_cvttpd2dq
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvttsd_si32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvttsd2si
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpd_pi32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_cvtpd2pi
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_cvttpd_pi32
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_cvttpd2pi
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtpi32_pd
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtpi2pd
argument_list|(
operator|(
name|__v2si
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|double
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsd_f64
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_load_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
return|return
operator|*
operator|(
name|__m128d
operator|*
operator|)
name|__dp
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_load1_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__mm_load1_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|double
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_load1_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__u
block|,
name|__u
block|}
return|;
block|}
end_function

begin_define
define|#
directive|define
name|_mm_load_pd1
parameter_list|(
name|dp
parameter_list|)
value|_mm_load1_pd(dp)
end_define

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_loadr_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
name|__m128d
name|__u
init|=
operator|*
operator|(
name|__m128d
operator|*
operator|)
name|__dp
decl_stmt|;
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__u
argument_list|,
operator|(
name|__v2df
operator|)
name|__u
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_loadu_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__loadu_pd
block|{
name|__m128d
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
return|return
operator|(
operator|(
expr|struct
name|__loadu_pd
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__v
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_loadu_si64
parameter_list|(
name|void
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
struct|struct
name|__loadu_si64
block|{
name|long
name|long
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|long
name|long
name|__u
init|=
operator|(
operator|(
expr|struct
name|__loadu_si64
operator|*
operator|)
name|__a
operator|)
operator|->
name|__v
decl_stmt|;
return|return
operator|(
name|__m128i
operator|)
block|{
name|__u
block|,
literal|0L
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_load_sd
parameter_list|(
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__mm_load_sd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|double
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_load_sd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__u
block|,
literal|0
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_loadh_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__mm_loadh_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|double
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_loadh_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__a
index|[
literal|0
index|]
block|,
name|__u
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_loadl_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|double
specifier|const
modifier|*
name|__dp
parameter_list|)
block|{
struct|struct
name|__mm_loadl_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
name|double
name|__u
init|=
operator|(
operator|(
expr|struct
name|__mm_loadl_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
decl_stmt|;
return|return
operator|(
name|__m128d
operator|)
block|{
name|__u
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_undefined_pd
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__builtin_ia32_undef128
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_set_sd
parameter_list|(
name|double
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__w
block|,
literal|0
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_set1_pd
parameter_list|(
name|double
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__w
block|,
name|__w
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_set_pd
parameter_list|(
name|double
name|__w
parameter_list|,
name|double
name|__x
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__x
block|,
name|__w
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_setr_pd
parameter_list|(
name|double
name|__w
parameter_list|,
name|double
name|__x
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__w
block|,
name|__x
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_setzero_pd
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
literal|0
block|,
literal|0
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_move_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
block|{
name|__b
index|[
literal|0
index|]
block|,
name|__a
index|[
literal|1
index|]
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_sd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_store_sd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__mm_store_sd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
operator|=
name|__a
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
operator|*
operator|(
name|__m128d
operator|*
operator|)
name|__dp
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store1_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
name|__a
operator|=
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_mm_store_pd
argument_list|(
name|__dp
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_pd1
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|_mm_store1_pd
argument_list|(
name|__dp
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storeu_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
struct|struct
name|__storeu_pd
block|{
name|__m128d
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__storeu_pd
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__v
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storer_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
name|__a
operator|=
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|*
operator|(
name|__m128d
operator|*
operator|)
name|__dp
operator|=
name|__a
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storeh_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_storeh_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__mm_storeh_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
operator|=
name|__a
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storel_pd
parameter_list|(
name|double
modifier|*
name|__dp
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_storeh_pd_struct
block|{
name|double
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__mm_storeh_pd_struct
operator|*
operator|)
name|__dp
operator|)
operator|->
name|__u
operator|=
name|__a
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_add_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v16qu
operator|)
name|__a
operator|+
operator|(
name|__v16qu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_add_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hu
operator|)
name|__a
operator|+
operator|(
name|__v8hu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_add_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator|+
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_add_si64
parameter_list|(
name|__m64
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_paddq
argument_list|(
operator|(
name|__v1di
operator|)
name|__a
argument_list|,
operator|(
name|__v1di
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_add_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|+
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_adds_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_paddsb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_adds_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_paddsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_adds_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_paddusb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_adds_epu16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_paddusw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_avg_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pavgb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_avg_epu16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pavgw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_madd_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaddwd128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_max_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_max_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmaxub128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_min_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_min_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pminub128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mulhi_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmulhw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mulhi_epu16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pmulhuw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies the corresponding elements of two [8 x short] vectors and
end_comment

begin_comment
comment|///    returns a vector containing the low-order 16 bits of each 32-bit product
end_comment

begin_comment
comment|///    in the corresponding element.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPMULLW / PMULLW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the products of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mullo_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hu
operator|)
name|__a
operator|*
operator|(
name|__v8hu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies 32-bit unsigned integer values contained in the lower bits
end_comment

begin_comment
comment|///    of the two 64-bit integer vectors and returns the 64-bit unsigned
end_comment

begin_comment
comment|///    product.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PMULUDQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the product of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_mul_su32
parameter_list|(
name|__m64
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_pmuludq
argument_list|(
operator|(
name|__v2si
operator|)
name|__a
argument_list|,
operator|(
name|__v2si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Multiplies 32-bit unsigned integer values contained in the lower
end_comment

begin_comment
comment|///    bits of the corresponding elements of two [2 x i64] vectors, and returns
end_comment

begin_comment
comment|///    the 64-bit products in the corresponding elements of a [2 x i64] vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPMULUDQ / PMULUDQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A [2 x i64] vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A [2 x i64] vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A [2 x i64] vector containing the product of both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_mul_epu32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_pmuludq128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Computes the absolute differences of corresponding 8-bit integer
end_comment

begin_comment
comment|///    values in two 128-bit vectors. Sums the first 8 absolute differences, and
end_comment

begin_comment
comment|///    separately sums the second 8 absolute differences. Packss these two
end_comment

begin_comment
comment|///    unsigned 16-bit integer sums into the upper and lower elements of a
end_comment

begin_comment
comment|///    [2 x i64] vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSADBW / PSADBW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A [2 x i64] vector containing the sums of the sets of absolute
end_comment

begin_comment
comment|///    differences between both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sad_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|__builtin_ia32_psadbw128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding 8-bit integer values in the operands.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSUBB / PSUBB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sub_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v16qu
operator|)
name|__a
operator|-
operator|(
name|__v16qu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding 16-bit integer values in the operands.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSUBW / PSUBW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sub_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hu
operator|)
name|__a
operator|-
operator|(
name|__v8hu
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding 32-bit integer values in the operands.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSUBD / PSUBD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sub_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4su
operator|)
name|__a
operator|-
operator|(
name|__v4su
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts signed or unsigned 64-bit integer values and writes the
end_comment

begin_comment
comment|///    difference to the corresponding bits in the destination.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c PSUBQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the minuend.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit integer vector containing the subtrahend.
end_comment

begin_comment
comment|/// \returns A 64-bit integer vector containing the difference of the values in
end_comment

begin_comment
comment|///    the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_sub_si64
parameter_list|(
name|__m64
name|__a
parameter_list|,
name|__m64
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__builtin_ia32_psubq
argument_list|(
operator|(
name|__v1di
operator|)
name|__a
argument_list|,
operator|(
name|__v1di
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts the corresponding elements of two [2 x i64] vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSUBQ / PSUBQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sub_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|-
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts corresponding 8-bit signed integer values in the input and
end_comment

begin_comment
comment|///    returns the differences in the corresponding bytes in the destination.
end_comment

begin_comment
comment|///    Differences greater than 7Fh are saturated to 7Fh, and differences less
end_comment

begin_comment
comment|///    than 80h are saturated to 80h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSUBSB / PSUBSB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_subs_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psubsb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts corresponding 16-bit signed integer values in the input and
end_comment

begin_comment
comment|///    returns the differences in the corresponding bytes in the destination.
end_comment

begin_comment
comment|///    Differences greater than 7FFFh are saturated to 7FFFh, and values less
end_comment

begin_comment
comment|///    than 8000h are saturated to 8000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSUBSW / PSUBSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the differences of the values
end_comment

begin_comment
comment|///    in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_subs_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psubsw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts corresponding 8-bit unsigned integer values in the input
end_comment

begin_comment
comment|///    and returns the differences in the corresponding bytes in the
end_comment

begin_comment
comment|///    destination. Differences less than 00h are saturated to 00h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSUBUSB / PSUBUSB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the unsigned integer
end_comment

begin_comment
comment|///    differences of the values in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_subs_epu8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psubusb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Subtracts corresponding 16-bit unsigned integer values in the input
end_comment

begin_comment
comment|///    and returns the differences in the corresponding bytes in the
end_comment

begin_comment
comment|///    destination. Differences less than 0000h are saturated to 0000h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSUBUSW / PSUBUSW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the minuends.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the subtrahends.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the unsigned integer
end_comment

begin_comment
comment|///    differences of the values in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_subs_epu16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psubusw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 128-bit integer vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPAND / PAND instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the bitwise AND of the values
end_comment

begin_comment
comment|///    in both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_and_si128
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|&
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise AND of two 128-bit integer vectors, using the
end_comment

begin_comment
comment|///    one's complement of the values contained in the first source operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPANDN / PANDN instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector containing the left source operand. The one's complement
end_comment

begin_comment
comment|///    of this value is used in the bitwise AND.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit vector containing the right source operand.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the bitwise AND of the one's
end_comment

begin_comment
comment|///    complement of the first operand and the values in the second operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_andnot_si128
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|~
operator|(
name|__v2du
operator|)
name|__a
operator|&
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise OR of two 128-bit integer vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPOR / POR instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the bitwise OR of the values
end_comment

begin_comment
comment|///    in both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_or_si128
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator||
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Performs a bitwise exclusive OR of two 128-bit integer vectors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPXOR / PXOR instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector containing one of the source operands.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the bitwise exclusive OR of the
end_comment

begin_comment
comment|///    values in both operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_xor_si128
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v2du
operator|)
name|__a
operator|^
operator|(
name|__v2du
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts the 128-bit integer vector operand by the specified
end_comment

begin_comment
comment|///    number of bytes. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_slli_si128(__m128i a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSLLDQ / PSLLDQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An immediate value specifying the number of bytes to left-shift
end_comment

begin_comment
comment|///    operand a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted value.
end_comment

begin_define
define|#
directive|define
name|_mm_slli_si128
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({                              \   (__m128i)__builtin_shufflevector(                                          \                                  (__v16qi)_mm_setzero_si128(),               \                                  (__v16qi)(__m128i)(a),                      \                                  ((char)(imm)&0xF0) ?  0 : 16 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  1 : 17 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  2 : 18 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  3 : 19 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  4 : 20 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  5 : 21 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  6 : 22 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  7 : 23 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  8 : 24 - (char)(imm), \                                  ((char)(imm)&0xF0) ?  9 : 25 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 10 : 26 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 11 : 27 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 12 : 28 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 13 : 29 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 14 : 30 - (char)(imm), \                                  ((char)(imm)&0xF0) ? 15 : 31 - (char)(imm)); })
end_define

begin_define
define|#
directive|define
name|_mm_bslli_si128
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
define|\
value|_mm_slli_si128((a), (imm))
end_define

begin_comment
comment|/// \brief Left-shifts each 16-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSLLW / PSLLW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to left-shift each value
end_comment

begin_comment
comment|///    in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_slli_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psllwi128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 16-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSLLW / PSLLW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to left-shift each value in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sll_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psllw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 32-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSLLD / PSLLD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to left-shift each value
end_comment

begin_comment
comment|///    in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_slli_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pslldi128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 32-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSLLD / PSLLD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to left-shift each value in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sll_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_pslld128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 64-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSLLQ / PSLLQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to left-shift each value
end_comment

begin_comment
comment|///    in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_slli_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
name|__builtin_ia32_psllqi128
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Left-shifts each 64-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. Low-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSLLQ / PSLLQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to left-shift each value in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the left-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sll_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
name|__builtin_ia32_psllq128
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 16-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. High-order bits are filled with the sign
end_comment

begin_comment
comment|///    bit of the initial value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRAW / PSRAW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srai_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrawi128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 16-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. High-order bits are filled with the sign
end_comment

begin_comment
comment|///    bit of the initial value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRAW / PSRAW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sra_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psraw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 32-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. High-order bits are filled with the sign
end_comment

begin_comment
comment|///    bit of the initial value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRAD / PSRAD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srai_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psradi128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each 32-bit value in the 128-bit integer vector operand
end_comment

begin_comment
comment|///    by the specified number of bits. High-order bits are filled with the sign
end_comment

begin_comment
comment|///    bit of the initial value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRAD / PSRAD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_sra_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrad128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts the 128-bit integer vector operand by the specified
end_comment

begin_comment
comment|///    number of bytes. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// __m128i _mm_srli_si128(__m128i a, const int imm);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRLDQ / PSRLDQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param imm
end_comment

begin_comment
comment|///    An immediate value specifying the number of bytes to right-shift operand
end_comment

begin_comment
comment|///    a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted value.
end_comment

begin_define
define|#
directive|define
name|_mm_srli_si128
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({                              \   (__m128i)__builtin_shufflevector(                                          \                                  (__v16qi)(__m128i)(a),                      \                                  (__v16qi)_mm_setzero_si128(),               \                                  ((char)(imm)&0xF0) ? 16 : (char)(imm) + 0,  \                                  ((char)(imm)&0xF0) ? 17 : (char)(imm) + 1,  \                                  ((char)(imm)&0xF0) ? 18 : (char)(imm) + 2,  \                                  ((char)(imm)&0xF0) ? 19 : (char)(imm) + 3,  \                                  ((char)(imm)&0xF0) ? 20 : (char)(imm) + 4,  \                                  ((char)(imm)&0xF0) ? 21 : (char)(imm) + 5,  \                                  ((char)(imm)&0xF0) ? 22 : (char)(imm) + 6,  \                                  ((char)(imm)&0xF0) ? 23 : (char)(imm) + 7,  \                                  ((char)(imm)&0xF0) ? 24 : (char)(imm) + 8,  \                                  ((char)(imm)&0xF0) ? 25 : (char)(imm) + 9,  \                                  ((char)(imm)&0xF0) ? 26 : (char)(imm) + 10, \                                  ((char)(imm)&0xF0) ? 27 : (char)(imm) + 11, \                                  ((char)(imm)&0xF0) ? 28 : (char)(imm) + 12, \                                  ((char)(imm)&0xF0) ? 29 : (char)(imm) + 13, \                                  ((char)(imm)&0xF0) ? 30 : (char)(imm) + 14, \                                  ((char)(imm)&0xF0) ? 31 : (char)(imm) + 15); })
end_define

begin_define
define|#
directive|define
name|_mm_bsrli_si128
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
define|\
value|_mm_srli_si128((a), (imm))
end_define

begin_comment
comment|/// \brief Right-shifts each of 16-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRLW / PSRLW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srli_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrlwi128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 16-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRLW / PSRLW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srl_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrlw128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 32-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRLD / PSRLD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srli_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrldi128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 32-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRLD / PSRLD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srl_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_psrld128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 64-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRLQ / PSRLQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    An integer value specifying the number of bits to right-shift each value
end_comment

begin_comment
comment|///    in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srli_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__count
parameter_list|)
block|{
return|return
name|__builtin_ia32_psrlqi128
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Right-shifts each of 64-bit values in the 128-bit integer vector
end_comment

begin_comment
comment|///    operand by the specified number of bits. High-order bits are cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPSRLQ / PSRLQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector containing the source operand.
end_comment

begin_comment
comment|/// \param __count
end_comment

begin_comment
comment|///    A 128-bit integer vector in which bits [63:0] specify the number of bits
end_comment

begin_comment
comment|///    to right-shift each value in operand __a.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the right-shifted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_srl_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__count
parameter_list|)
block|{
return|return
name|__builtin_ia32_psrlq128
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__count
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 8-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors for equality. Each comparison yields 0h for false, FFh
end_comment

begin_comment
comment|///    for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPEQB / PCMPEQB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
operator|==
operator|(
name|__v16qi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 16-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors for equality. Each comparison yields 0h for false, FFFFh
end_comment

begin_comment
comment|///    for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPEQW / PCMPEQW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
operator|==
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding 32-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors for equality. Each comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPEQD / PCMPEQD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpeq_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
operator|==
operator|(
name|__v4si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 8-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors to determine if the values in the first operand are
end_comment

begin_comment
comment|///    greater than those in the second operand. Each comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPGTB / PCMPGTB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|/* This function always performs a signed comparison, but __v16qi is a char      which may be signed or unsigned, so use __v16qs. */
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v16qs
operator|)
name|__a
operator|>
operator|(
name|__v16qs
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 16-bit values of the
end_comment

begin_comment
comment|///    128-bit integer vectors to determine if the values in the first operand
end_comment

begin_comment
comment|///    are greater than those in the second operand. Each comparison yields 0h
end_comment

begin_comment
comment|///    for false, FFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPGTW / PCMPGTW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
operator|>
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 32-bit values of the
end_comment

begin_comment
comment|///    128-bit integer vectors to determine if the values in the first operand
end_comment

begin_comment
comment|///    are greater than those in the second operand. Each comparison yields 0h
end_comment

begin_comment
comment|///    for false, FFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPGTD / PCMPGTD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmpgt_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
call|(
name|__m128i
call|)
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
operator|>
operator|(
name|__v4si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 8-bit values of the 128-bit
end_comment

begin_comment
comment|///    integer vectors to determine if the values in the first operand are less
end_comment

begin_comment
comment|///    than those in the second operand. Each comparison yields 0h for false,
end_comment

begin_comment
comment|///    FFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPGTB / PCMPGTB instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|_mm_cmpgt_epi8
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 16-bit values of the
end_comment

begin_comment
comment|///    128-bit integer vectors to determine if the values in the first operand
end_comment

begin_comment
comment|///    are less than those in the second operand. Each comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPGTW / PCMPGTW instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|_mm_cmpgt_epi16
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Compares each of the corresponding signed 32-bit values of the
end_comment

begin_comment
comment|///    128-bit integer vectors to determine if the values in the first operand
end_comment

begin_comment
comment|///    are less than those in the second operand. Each comparison yields 0h for
end_comment

begin_comment
comment|///    false, FFFFFFFFh for true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VPCMPGTD / PCMPGTD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the comparison results.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cmplt_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
name|_mm_cmpgt_epi32
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Converts a 64-bit signed integer value from the second operand into a
end_comment

begin_comment
comment|///    double-precision value and returns it in the lower element of a [2 x
end_comment

begin_comment
comment|///    double] vector; the upper element of the returned vector is copied from
end_comment

begin_comment
comment|///    the upper element of the first operand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTSI2SD / CVTSI2SD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The upper 64 bits of this operand are
end_comment

begin_comment
comment|///    copied to the upper 64 bits of the destination.
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    A 64-bit signed integer operand containing the value to be converted.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x double] whose lower 64 bits contain the
end_comment

begin_comment
comment|///    converted value of the second operand. The upper 64 bits are copied from
end_comment

begin_comment
comment|///    the upper 64 bits of the first operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi64_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|long
name|long
name|__b
parameter_list|)
block|{
name|__a
index|[
literal|0
index|]
operator|=
name|__b
expr_stmt|;
return|return
name|__a
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the first (lower) element of a vector of [2 x double] into a
end_comment

begin_comment
comment|///    64-bit signed integer value, according to the current rounding mode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTSD2SI / CVTSD2SI instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower 64 bits are used in the
end_comment

begin_comment
comment|///    conversion.
end_comment

begin_comment
comment|/// \returns A 64-bit signed integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsd_si64
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtsd2si64
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts the first (lower) element of a vector of [2 x double] into a
end_comment

begin_comment
comment|///    64-bit signed integer value, truncating the result when it is inexact.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTTSD2SI / CVTTSD2SI instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x double]. The lower 64 bits are used in the
end_comment

begin_comment
comment|///    conversion.
end_comment

begin_comment
comment|/// \returns A 64-bit signed integer containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvttsd_si64
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvttsd2si64
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Converts a vector of [4 x i32] into a vector of [4 x float].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTDQ2PS / CVTDQ2PS instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit integer vector.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x float] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_cvtepi32_ps
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_cvtdq2ps
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a vector of [4 x float] into a vector of [4 x i32].
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTPS2DQ / CVTPS2DQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector of [4 x i32] containing the converted
end_comment

begin_comment
comment|///    values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtps_epi32
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_cvtps2dq
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Converts a vector of [4 x float] into a vector of [4 x i32],
end_comment

begin_comment
comment|///    truncating the result when it is inexact.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VCVTTPS2DQ / CVTTPS2DQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 128-bit vector of [4 x float].
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] containing the converted values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvttps_epi32
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_cvttps2dq
argument_list|(
operator|(
name|__v4sf
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a vector of [4 x i32] where the lowest element is the input
end_comment

begin_comment
comment|///    operand and the remaining elements are zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMOVD / MOVD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 32-bit signed integer operand.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32].
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi32_si128
parameter_list|(
name|int
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v4si
operator|)
block|{
name|__a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Returns a vector of [2 x i64] where the lower element is the input
end_comment

begin_comment
comment|///    operand and the upper element is zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMOVQ / MOVQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A 64-bit signed integer operand containing the value to be converted.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64] containing the converted value.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi64_si128
parameter_list|(
name|long
name|long
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
name|__a
block|,
literal|0
block|}
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Moves the least significant 32 bits of a vector of [4 x i32] to a
end_comment

begin_comment
comment|///    32-bit signed integer value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMOVD / MOVD instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [4 x i32]. The least significant 32 bits are moved to the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 32-bit signed integer containing the moved value.
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi128_si32
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
name|__v4si
name|__b
init|=
operator|(
name|__v4si
operator|)
name|__a
decl_stmt|;
return|return
name|__b
index|[
literal|0
index|]
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_comment
comment|/// \brief Moves the least significant 64 bits of a vector of [2 x i64] to a
end_comment

begin_comment
comment|///    64-bit signed integer value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMOVQ / MOVQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __a
end_comment

begin_comment
comment|///    A vector of [2 x i64]. The least significant 64 bits are moved to the
end_comment

begin_comment
comment|///    destination.
end_comment

begin_comment
comment|/// \returns A 64-bit signed integer containing the moved value.
end_comment

begin_function
specifier|static
name|__inline__
name|long
name|long
name|__DEFAULT_FN_ATTRS
name|_mm_cvtsi128_si64
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
name|__a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Moves packed integer values from an aligned 128-bit memory location
end_comment

begin_comment
comment|///    to elements in a 128-bit integer vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMOVDQA / MOVDQA instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    An aligned pointer to a memory location containing integer values.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_load_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
return|return
operator|*
name|__p
return|;
block|}
end_function

begin_comment
comment|/// \brief Moves packed integer values from an unaligned 128-bit memory location
end_comment

begin_comment
comment|///    to elements in a 128-bit integer vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMOVDQU / MOVDQU instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A pointer to a memory location containing integer values.
end_comment

begin_comment
comment|/// \returns A 128-bit integer vector containing the moved values.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_loadu_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__loadu_si128
block|{
name|__m128i
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
return|return
operator|(
operator|(
expr|struct
name|__loadu_si128
operator|*
operator|)
name|__p
operator|)
operator|->
name|__v
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a vector of [2 x i64] where the lower element is taken from
end_comment

begin_comment
comment|///    the lower element of the operand, and the upper element is zero.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic corresponds to the \c VMOVQ / MOVQ instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __p
end_comment

begin_comment
comment|///    A 128-bit vector of [2 x i64]. Bits [63:0] are written to bits [63:0] of
end_comment

begin_comment
comment|///    the destination.
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [2 x i64]. The lower order bits contain the
end_comment

begin_comment
comment|///    moved value. The higher order bits are cleared.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_loadl_epi64
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
struct|struct
name|__mm_loadl_epi64_struct
block|{
name|long
name|long
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
operator|(
expr|struct
name|__mm_loadl_epi64_struct
operator|*
operator|)
name|__p
operator|)
operator|->
name|__u
block|,
literal|0
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Generates a 128-bit vector of [4 x i32] with unspecified content.
end_comment

begin_comment
comment|///    This could be used as an argument to another intrinsic function where the
end_comment

begin_comment
comment|///    argument is required but the value is not actually used.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic has no corresponding instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns A 128-bit vector of [4 x i32] with unspecified content.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_undefined_si128
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_undef128
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes both 64-bit values in a 128-bit vector of [2 x i64] with
end_comment

begin_comment
comment|///    the specified 64-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q1
end_comment

begin_comment
comment|///    A 64-bit integer value used to initialize the upper 64 bits of the
end_comment

begin_comment
comment|///    destination vector of [2 x i64].
end_comment

begin_comment
comment|/// \param __q0
end_comment

begin_comment
comment|///    A 64-bit integer value used to initialize the lower 64 bits of the
end_comment

begin_comment
comment|///    destination vector of [2 x i64].
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [2 x i64] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi64x
parameter_list|(
name|long
name|long
name|__q1
parameter_list|,
name|long
name|long
name|__q0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
name|__q0
block|,
name|__q1
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes both 64-bit values in a 128-bit vector of [2 x i64] with
end_comment

begin_comment
comment|///    the specified 64-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q1
end_comment

begin_comment
comment|///    A 64-bit integer value used to initialize the upper 64 bits of the
end_comment

begin_comment
comment|///    destination vector of [2 x i64].
end_comment

begin_comment
comment|/// \param __q0
end_comment

begin_comment
comment|///    A 64-bit integer value used to initialize the lower 64 bits of the
end_comment

begin_comment
comment|///    destination vector of [2 x i64].
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [2 x i64] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi64
parameter_list|(
name|__m64
name|__q1
parameter_list|,
name|__m64
name|__q0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
name|long
name|long
operator|)
name|__q0
block|,
operator|(
name|long
name|long
operator|)
name|__q1
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes the 32-bit values in a 128-bit vector of [4 x i32] with
end_comment

begin_comment
comment|///    the specified 32-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i3
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize bits [127:96] of the
end_comment

begin_comment
comment|///    destination vector.
end_comment

begin_comment
comment|/// \param __i2
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize bits [95:64] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __i1
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize bits [63:32] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __i0
end_comment

begin_comment
comment|///    A 32-bit integer value used to initialize bits [31:0] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [4 x i32] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi32
parameter_list|(
name|int
name|__i3
parameter_list|,
name|int
name|__i2
parameter_list|,
name|int
name|__i1
parameter_list|,
name|int
name|__i0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v4si
operator|)
block|{
name|__i0
block|,
name|__i1
block|,
name|__i2
block|,
name|__i3
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes the 16-bit values in a 128-bit vector of [8 x i16] with
end_comment

begin_comment
comment|///    the specified 16-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w7
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [127:112] of the
end_comment

begin_comment
comment|///    destination vector.
end_comment

begin_comment
comment|/// \param __w6
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [111:96] of the
end_comment

begin_comment
comment|///    destination vector.
end_comment

begin_comment
comment|/// \param __w5
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [95:80] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w4
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [79:64] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w3
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [63:48] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w2
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [47:32] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w1
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [31:16] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \param __w0
end_comment

begin_comment
comment|///    A 16-bit integer value used to initialize bits [15:0] of the destination
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [8 x i16] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi16
parameter_list|(
name|short
name|__w7
parameter_list|,
name|short
name|__w6
parameter_list|,
name|short
name|__w5
parameter_list|,
name|short
name|__w4
parameter_list|,
name|short
name|__w3
parameter_list|,
name|short
name|__w2
parameter_list|,
name|short
name|__w1
parameter_list|,
name|short
name|__w0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v8hi
operator|)
block|{
name|__w0
block|,
name|__w1
block|,
name|__w2
block|,
name|__w3
block|,
name|__w4
block|,
name|__w5
block|,
name|__w6
block|,
name|__w7
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes the 8-bit values in a 128-bit vector of [16 x i8] with
end_comment

begin_comment
comment|///    the specified 8-bit integer values.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __b15
end_comment

begin_comment
comment|///    Initializes bits [127:120] of the destination vector.
end_comment

begin_comment
comment|/// \param __b14
end_comment

begin_comment
comment|///    Initializes bits [119:112] of the destination vector.
end_comment

begin_comment
comment|/// \param __b13
end_comment

begin_comment
comment|///    Initializes bits [111:104] of the destination vector.
end_comment

begin_comment
comment|/// \param __b12
end_comment

begin_comment
comment|///    Initializes bits [103:96] of the destination vector.
end_comment

begin_comment
comment|/// \param __b11
end_comment

begin_comment
comment|///    Initializes bits [95:88] of the destination vector.
end_comment

begin_comment
comment|/// \param __b10
end_comment

begin_comment
comment|///    Initializes bits [87:80] of the destination vector.
end_comment

begin_comment
comment|/// \param __b9
end_comment

begin_comment
comment|///    Initializes bits [79:72] of the destination vector.
end_comment

begin_comment
comment|/// \param __b8
end_comment

begin_comment
comment|///    Initializes bits [71:64] of the destination vector.
end_comment

begin_comment
comment|/// \param __b7
end_comment

begin_comment
comment|///    Initializes bits [63:56] of the destination vector.
end_comment

begin_comment
comment|/// \param __b6
end_comment

begin_comment
comment|///    Initializes bits [55:48] of the destination vector.
end_comment

begin_comment
comment|/// \param __b5
end_comment

begin_comment
comment|///    Initializes bits [47:40] of the destination vector.
end_comment

begin_comment
comment|/// \param __b4
end_comment

begin_comment
comment|///    Initializes bits [39:32] of the destination vector.
end_comment

begin_comment
comment|/// \param __b3
end_comment

begin_comment
comment|///    Initializes bits [31:24] of the destination vector.
end_comment

begin_comment
comment|/// \param __b2
end_comment

begin_comment
comment|///    Initializes bits [23:16] of the destination vector.
end_comment

begin_comment
comment|/// \param __b1
end_comment

begin_comment
comment|///    Initializes bits [15:8] of the destination vector.
end_comment

begin_comment
comment|/// \param __b0
end_comment

begin_comment
comment|///    Initializes bits [7:0] of the destination vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [16 x i8] containing the values
end_comment

begin_comment
comment|///    provided in the operands.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set_epi8
parameter_list|(
name|char
name|__b15
parameter_list|,
name|char
name|__b14
parameter_list|,
name|char
name|__b13
parameter_list|,
name|char
name|__b12
parameter_list|,
name|char
name|__b11
parameter_list|,
name|char
name|__b10
parameter_list|,
name|char
name|__b9
parameter_list|,
name|char
name|__b8
parameter_list|,
name|char
name|__b7
parameter_list|,
name|char
name|__b6
parameter_list|,
name|char
name|__b5
parameter_list|,
name|char
name|__b4
parameter_list|,
name|char
name|__b3
parameter_list|,
name|char
name|__b2
parameter_list|,
name|char
name|__b1
parameter_list|,
name|char
name|__b0
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v16qi
operator|)
block|{
name|__b0
block|,
name|__b1
block|,
name|__b2
block|,
name|__b3
block|,
name|__b4
block|,
name|__b5
block|,
name|__b6
block|,
name|__b7
block|,
name|__b8
block|,
name|__b9
block|,
name|__b10
block|,
name|__b11
block|,
name|__b12
block|,
name|__b13
block|,
name|__b14
block|,
name|__b15
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes both values in a 128-bit integer vector with the
end_comment

begin_comment
comment|///    specified 64-bit integer value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q
end_comment

begin_comment
comment|///    Integer value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit integer vector of [2 x i64] with both
end_comment

begin_comment
comment|///    elements containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi64x
parameter_list|(
name|long
name|long
name|__q
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
name|__q
block|,
name|__q
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes both values in a 128-bit vector of [2 x i64] with the
end_comment

begin_comment
comment|///    specified 64-bit value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __q
end_comment

begin_comment
comment|///    A 64-bit value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [2 x i64] with all elements
end_comment

begin_comment
comment|///    containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi64
parameter_list|(
name|__m64
name|__q
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
name|long
name|long
operator|)
name|__q
block|,
operator|(
name|long
name|long
operator|)
name|__q
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes all values in a 128-bit vector of [4 x i32] with the
end_comment

begin_comment
comment|///    specified 32-bit value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __i
end_comment

begin_comment
comment|///    A 32-bit value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [4 x i32] with all elements
end_comment

begin_comment
comment|///    containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi32
parameter_list|(
name|int
name|__i
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v4si
operator|)
block|{
name|__i
block|,
name|__i
block|,
name|__i
block|,
name|__i
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes all values in a 128-bit vector of [8 x i16] with the
end_comment

begin_comment
comment|///    specified 16-bit value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __w
end_comment

begin_comment
comment|///    A 16-bit value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [8 x i16] with all elements
end_comment

begin_comment
comment|///    containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi16
parameter_list|(
name|short
name|__w
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v8hi
operator|)
block|{
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|,
name|__w
block|}
return|;
block|}
end_function

begin_comment
comment|/// \brief Initializes all values in a 128-bit vector of [16 x i8] with the
end_comment

begin_comment
comment|///    specified 8-bit value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \headerfile<x86intrin.h>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This intrinsic is a utility function and does not correspond to a specific
end_comment

begin_comment
comment|///    instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param __b
end_comment

begin_comment
comment|///    An 8-bit value used to initialize the elements of the destination integer
end_comment

begin_comment
comment|///    vector.
end_comment

begin_comment
comment|/// \returns An initialized 128-bit vector of [16 x i8] with all elements
end_comment

begin_comment
comment|///    containing the value provided in the operand.
end_comment

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_set1_epi8
parameter_list|(
name|char
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v16qi
operator|)
block|{
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|,
name|__b
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setr_epi64
parameter_list|(
name|__m64
name|__q0
parameter_list|,
name|__m64
name|__q1
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
name|long
name|long
operator|)
name|__q0
block|,
operator|(
name|long
name|long
operator|)
name|__q1
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setr_epi32
parameter_list|(
name|int
name|__i0
parameter_list|,
name|int
name|__i1
parameter_list|,
name|int
name|__i2
parameter_list|,
name|int
name|__i3
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v4si
operator|)
block|{
name|__i0
block|,
name|__i1
block|,
name|__i2
block|,
name|__i3
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setr_epi16
parameter_list|(
name|short
name|__w0
parameter_list|,
name|short
name|__w1
parameter_list|,
name|short
name|__w2
parameter_list|,
name|short
name|__w3
parameter_list|,
name|short
name|__w4
parameter_list|,
name|short
name|__w5
parameter_list|,
name|short
name|__w6
parameter_list|,
name|short
name|__w7
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v8hi
operator|)
block|{
name|__w0
block|,
name|__w1
block|,
name|__w2
block|,
name|__w3
block|,
name|__w4
block|,
name|__w5
block|,
name|__w6
block|,
name|__w7
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setr_epi8
parameter_list|(
name|char
name|__b0
parameter_list|,
name|char
name|__b1
parameter_list|,
name|char
name|__b2
parameter_list|,
name|char
name|__b3
parameter_list|,
name|char
name|__b4
parameter_list|,
name|char
name|__b5
parameter_list|,
name|char
name|__b6
parameter_list|,
name|char
name|__b7
parameter_list|,
name|char
name|__b8
parameter_list|,
name|char
name|__b9
parameter_list|,
name|char
name|__b10
parameter_list|,
name|char
name|__b11
parameter_list|,
name|char
name|__b12
parameter_list|,
name|char
name|__b13
parameter_list|,
name|char
name|__b14
parameter_list|,
name|char
name|__b15
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
operator|(
name|__v16qi
operator|)
block|{
name|__b0
block|,
name|__b1
block|,
name|__b2
block|,
name|__b3
block|,
name|__b4
block|,
name|__b5
block|,
name|__b6
block|,
name|__b7
block|,
name|__b8
block|,
name|__b9
block|,
name|__b10
block|,
name|__b11
block|,
name|__b12
block|,
name|__b13
block|,
name|__b14
block|,
name|__b15
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_setzero_si128
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
literal|0LL
block|,
literal|0LL
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_store_si128
parameter_list|(
name|__m128i
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
operator|*
name|__p
operator|=
name|__b
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storeu_si128
parameter_list|(
name|__m128i
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
struct|struct
name|__storeu_si128
block|{
name|__m128i
name|__v
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__storeu_si128
operator|*
operator|)
name|__p
operator|)
operator|->
name|__v
operator|=
name|__b
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_maskmoveu_si128
parameter_list|(
name|__m128i
name|__d
parameter_list|,
name|__m128i
name|__n
parameter_list|,
name|char
modifier|*
name|__p
parameter_list|)
block|{
name|__builtin_ia32_maskmovdqu
argument_list|(
operator|(
name|__v16qi
operator|)
name|__d
argument_list|,
operator|(
name|__v16qi
operator|)
name|__n
argument_list|,
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_storel_epi64
parameter_list|(
name|__m128i
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__a
parameter_list|)
block|{
struct|struct
name|__mm_storel_epi64_struct
block|{
name|long
name|long
name|__u
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|,
name|__may_alias__
operator|)
argument_list|)
struct|;
operator|(
operator|(
expr|struct
name|__mm_storel_epi64_struct
operator|*
operator|)
name|__p
operator|)
operator|->
name|__u
operator|=
name|__a
index|[
literal|0
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_pd
parameter_list|(
name|double
modifier|*
name|__p
parameter_list|,
name|__m128d
name|__a
parameter_list|)
block|{
name|__builtin_nontemporal_store
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|*
operator|)
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_si128
parameter_list|(
name|__m128i
modifier|*
name|__p
parameter_list|,
name|__m128i
name|__a
parameter_list|)
block|{
name|__builtin_nontemporal_store
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|*
operator|)
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_si32
parameter_list|(
name|int
modifier|*
name|__p
parameter_list|,
name|int
name|__a
parameter_list|)
block|{
name|__builtin_ia32_movnti
argument_list|(
name|__p
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_stream_si64
parameter_list|(
name|long
name|long
modifier|*
name|__p
parameter_list|,
name|long
name|long
name|__a
parameter_list|)
block|{
name|__builtin_ia32_movnti64
argument_list|(
name|__p
argument_list|,
name|__a
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_clflush
parameter_list|(
name|void
specifier|const
modifier|*
name|__p
parameter_list|)
block|{
name|__builtin_ia32_clflush
argument_list|(
name|__p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_lfence
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_ia32_lfence
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_mfence
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_ia32_mfence
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_packs_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_packsswb128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_packs_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_packssdw128
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_packus_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_ia32_packuswb128
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_extract_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__imm
parameter_list|)
block|{
name|__v8hi
name|__b
init|=
operator|(
name|__v8hi
operator|)
name|__a
decl_stmt|;
return|return
operator|(
name|unsigned
name|short
operator|)
name|__b
index|[
name|__imm
operator|&
literal|7
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_insert_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|__b
parameter_list|,
name|int
name|__imm
parameter_list|)
block|{
name|__v8hi
name|__c
init|=
operator|(
name|__v8hi
operator|)
name|__a
decl_stmt|;
name|__c
index|[
name|__imm
operator|&
literal|7
index|]
operator|=
name|__b
expr_stmt|;
return|return
operator|(
name|__m128i
operator|)
name|__c
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_movemask_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_pmovmskb128
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|_mm_shuffle_epi32
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_shufflevector((__v4si)(__m128i)(a), \                                    (__v4si)_mm_undefined_si128(), \                                    ((imm)>> 0)& 0x3, ((imm)>> 2)& 0x3, \                                    ((imm)>> 4)& 0x3, ((imm)>> 6)& 0x3); })
end_define

begin_define
define|#
directive|define
name|_mm_shufflelo_epi16
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_shufflevector((__v8hi)(__m128i)(a), \                                    (__v8hi)_mm_undefined_si128(), \                                    ((imm)>> 0)& 0x3, ((imm)>> 2)& 0x3, \                                    ((imm)>> 4)& 0x3, ((imm)>> 6)& 0x3, \                                    4, 5, 6, 7); })
end_define

begin_define
define|#
directive|define
name|_mm_shufflehi_epi16
parameter_list|(
name|a
parameter_list|,
name|imm
parameter_list|)
value|__extension__ ({ \   (__m128i)__builtin_shufflevector((__v8hi)(__m128i)(a), \                                    (__v8hi)_mm_undefined_si128(), \                                    0, 1, 2, 3, \                                    4 + (((imm)>> 0)& 0x3), \                                    4 + (((imm)>> 2)& 0x3), \                                    4 + (((imm)>> 4)& 0x3), \                                    4 + (((imm)>> 6)& 0x3)); })
end_define

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|,
literal|8
argument_list|,
literal|16
operator|+
literal|8
argument_list|,
literal|9
argument_list|,
literal|16
operator|+
literal|9
argument_list|,
literal|10
argument_list|,
literal|16
operator|+
literal|10
argument_list|,
literal|11
argument_list|,
literal|16
operator|+
literal|11
argument_list|,
literal|12
argument_list|,
literal|16
operator|+
literal|12
argument_list|,
literal|13
argument_list|,
literal|16
operator|+
literal|13
argument_list|,
literal|14
argument_list|,
literal|16
operator|+
literal|14
argument_list|,
literal|15
argument_list|,
literal|16
operator|+
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|,
literal|4
argument_list|,
literal|8
operator|+
literal|4
argument_list|,
literal|5
argument_list|,
literal|8
operator|+
literal|5
argument_list|,
literal|6
argument_list|,
literal|8
operator|+
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
operator|+
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__b
argument_list|,
literal|2
argument_list|,
literal|4
operator|+
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
operator|+
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__b
argument_list|,
literal|1
argument_list|,
literal|2
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v16qi
operator|)
name|__a
argument_list|,
operator|(
name|__v16qi
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|16
operator|+
literal|0
argument_list|,
literal|1
argument_list|,
literal|16
operator|+
literal|1
argument_list|,
literal|2
argument_list|,
literal|16
operator|+
literal|2
argument_list|,
literal|3
argument_list|,
literal|16
operator|+
literal|3
argument_list|,
literal|4
argument_list|,
literal|16
operator|+
literal|4
argument_list|,
literal|5
argument_list|,
literal|16
operator|+
literal|5
argument_list|,
literal|6
argument_list|,
literal|16
operator|+
literal|6
argument_list|,
literal|7
argument_list|,
literal|16
operator|+
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v8hi
operator|)
name|__a
argument_list|,
operator|(
name|__v8hi
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|8
operator|+
literal|0
argument_list|,
literal|1
argument_list|,
literal|8
operator|+
literal|1
argument_list|,
literal|2
argument_list|,
literal|8
operator|+
literal|2
argument_list|,
literal|3
argument_list|,
literal|8
operator|+
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v4si
operator|)
name|__a
argument_list|,
operator|(
name|__v4si
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|4
operator|+
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__v2di
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|2
operator|+
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m64
name|__DEFAULT_FN_ATTRS
name|_mm_movepi64_pi64
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m64
operator|)
name|__a
index|[
literal|0
index|]
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_movpi64_epi64
parameter_list|(
name|__m64
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
block|{
operator|(
name|long
name|long
operator|)
name|__a
block|,
literal|0
block|}
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_move_epi64
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2di
operator|)
name|__a
argument_list|,
operator|(
name|__m128i
operator|)
block|{
literal|0
block|}
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_unpackhi_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
literal|1
argument_list|,
literal|2
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_unpacklo_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
return|return
name|__builtin_shufflevector
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|,
operator|(
name|__v2df
operator|)
name|__b
argument_list|,
literal|0
argument_list|,
literal|2
operator|+
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|__DEFAULT_FN_ATTRS
name|_mm_movemask_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
name|__builtin_ia32_movmskpd
argument_list|(
operator|(
name|__v2df
operator|)
name|__a
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|_mm_shuffle_pd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|i
parameter_list|)
value|__extension__ ({ \   (__m128d)__builtin_shufflevector((__v2df)(__m128d)(a), (__v2df)(__m128d)(b), \                                    0 + (((i)>> 0)& 0x1), \                                    2 + (((i)>> 1)& 0x1)); })
end_define

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_castpd_ps
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_castpd_si128
parameter_list|(
name|__m128d
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_castps_pd
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128i
name|__DEFAULT_FN_ATTRS
name|_mm_castps_si128
parameter_list|(
name|__m128
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128i
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128
name|__DEFAULT_FN_ATTRS
name|_mm_castsi128_ps
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|__m128d
name|__DEFAULT_FN_ATTRS
name|_mm_castsi128_pd
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
return|return
operator|(
name|__m128d
operator|)
name|__a
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|__DEFAULT_FN_ATTRS
name|_mm_pause
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_ia32_pause
argument_list|()
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|__DEFAULT_FN_ATTRS
end_undef

begin_define
define|#
directive|define
name|_MM_SHUFFLE2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<< 1) | (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMMINTRIN_H */
end_comment

end_unit

