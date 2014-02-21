begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- mm_malloc.h - Allocating and Freeing Aligned Memory Blocks -------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MM_MALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_function_decl
specifier|extern
name|int
name|posix_memalign
parameter_list|(
name|void
modifier|*
modifier|*
name|__memptr
parameter_list|,
name|size_t
name|__alignment
parameter_list|,
name|size_t
name|__size
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Some systems (e.g. those with GNU libc) declare posix_memalign with an
end_comment

begin_comment
comment|// exception specifier. Via an "egregious workaround" in
end_comment

begin_comment
comment|// Sema::CheckEquivalentExceptionSpec, Clang accepts the following as a valid
end_comment

begin_comment
comment|// redeclaration of glibc's declaration.
end_comment

begin_extern
extern|extern
literal|"C"
name|int
name|posix_memalign
parameter_list|(
name|void
modifier|*
modifier|*
name|__memptr
parameter_list|,
name|size_t
name|__alignment
parameter_list|,
name|size_t
name|__size
parameter_list|)
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|_mm_malloc
argument_list|)
operator|)
end_if

begin_decl_stmt
specifier|static
name|__inline__
name|void
modifier|*
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|,
name|__malloc__
operator|)
argument_list|)
name|_mm_malloc
argument_list|(
name|size_t
name|__size
argument_list|,
name|size_t
name|__align
argument_list|)
block|{
if|if
condition|(
name|__align
operator|==
literal|1
condition|)
block|{
return|return
name|malloc
argument_list|(
name|__size
argument_list|)
return|;
block|}
if|if
condition|(
operator|!
operator|(
name|__align
operator|&
operator|(
name|__align
operator|-
literal|1
operator|)
operator|)
operator|&&
name|__align
operator|<
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
condition|)
name|__align
operator|=
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
expr_stmt|;
name|void
modifier|*
name|__mallocedMemory
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
name|__mallocedMemory
operator|=
name|__mingw_aligned_malloc
argument_list|(
name|__size
argument_list|,
name|__align
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
name|__mallocedMemory
operator|=
name|_aligned_malloc
argument_list|(
name|__size
argument_list|,
name|__align
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|posix_memalign
argument_list|(
operator|&
name|__mallocedMemory
argument_list|,
name|__align
argument_list|,
name|__size
argument_list|)
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
return|return
name|__mallocedMemory
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|void
name|__attribute__
argument_list|(
operator|(
name|__always_inline__
operator|,
name|__nodebug__
operator|)
argument_list|)
name|_mm_free
argument_list|(
name|void
operator|*
name|__p
argument_list|)
block|{
name|free
argument_list|(
name|__p
argument_list|)
expr_stmt|;
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
comment|/* __MM_MALLOC_H */
end_comment

end_unit

