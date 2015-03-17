begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- lzcntintrin.h - LZCNT intrinsics ---------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|__X86INTRIN_H
operator|&&
operator|!
name|defined
name|__IMMINTRIN_H
end_if

begin_error
error|#
directive|error
literal|"Never use<lzcntintrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__LZCNT__
end_ifndef

begin_error
error|#
directive|error
literal|"LZCNT instruction is not enabled"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LZCNT__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LZCNTINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__LZCNTINTRIN_H
end_define

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|short
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__lzcnt16
argument_list|(
name|unsigned
name|short
name|__X
argument_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clzs
argument_list|(
name|__X
argument_list|)
else|:
literal|16
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|__lzcnt32
argument_list|(
name|unsigned
name|int
name|__X
argument_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clz
argument_list|(
name|__X
argument_list|)
else|:
literal|32
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_lzcnt_u32
argument_list|(
name|unsigned
name|int
name|__X
argument_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clz
argument_list|(
name|__X
argument_list|)
else|:
literal|32
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
name|unsigned
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
name|__lzcnt64
argument_list|(
name|unsigned
name|long
name|long
name|__X
argument_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clzll
argument_list|(
name|__X
argument_list|)
else|:
literal|64
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|unsigned
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
name|_lzcnt_u64
argument_list|(
name|unsigned
name|long
name|long
name|__X
argument_list|)
block|{
return|return
name|__X
condition|?
name|__builtin_clzll
argument_list|(
name|__X
argument_list|)
else|:
literal|64
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LZCNTINTRIN_H */
end_comment

end_unit

