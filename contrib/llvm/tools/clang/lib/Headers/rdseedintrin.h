begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- rdseedintrin.h - RDSEED intrinsics -------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86INTRIN_H
end_ifndef

begin_error
error|#
directive|error
literal|"Never use<rdseedintrin.h> directly; include<x86intrin.h> instead."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RDSEEDINTRIN_H
end_ifndef

begin_define
define|#
directive|define
name|__RDSEEDINTRIN_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__RDSEED__
end_ifdef

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
name|_rdseed16_step
argument_list|(
name|unsigned
name|short
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdseed16_step
argument_list|(
name|__p
argument_list|)
return|;
block|}
end_decl_stmt

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
name|_rdseed32_step
argument_list|(
name|unsigned
name|int
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdseed32_step
argument_list|(
name|__p
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
name|int
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_rdseed64_step
argument_list|(
name|unsigned
name|long
name|long
operator|*
name|__p
argument_list|)
block|{
return|return
name|__builtin_ia32_rdseed64_step
argument_list|(
name|__p
argument_list|)
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
comment|/* __RDSEED__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RDSEEDINTRIN_H */
end_comment

end_unit

