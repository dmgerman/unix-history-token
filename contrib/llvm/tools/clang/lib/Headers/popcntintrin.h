begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- popcntintrin.h - POPCNT intrinsics -------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__POPCNT__
end_ifndef

begin_error
error|#
directive|error
literal|"POPCNT instruction set not enabled"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POPCNTINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|_POPCNTINTRIN_H
end_define

begin_decl_stmt
specifier|static
name|__inline__
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_popcnt_u32
argument_list|(
name|unsigned
name|int
name|__A
argument_list|)
block|{
return|return
name|__builtin_popcount
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_decl_stmt
specifier|static
name|__inline__
name|long
name|long
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_popcnt_u64
argument_list|(
name|unsigned
name|long
name|long
name|__A
argument_list|)
block|{
return|return
name|__builtin_popcountll
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POPCNTINTRIN_H */
end_comment

end_unit

