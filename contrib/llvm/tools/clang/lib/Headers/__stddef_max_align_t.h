begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- __stddef_max_align_t.h - Definition of max_align_t for modules ---===  *  * Copyright (c) 2014 Chandler Carruth  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CLANG_MAX_ALIGN_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|__CLANG_MAX_ALIGN_T_DEFINED
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|__clang_max_align_nonce1
name|__attribute__
decl|((
name|__aligned__
decl|(
name|__alignof__
decl|(
name|long
name|long
decl_stmt|)
block|)
typedef|));
end_typedef

begin_decl_stmt
name|long
name|double
name|__clang_max_align_nonce2
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
name|__alignof__
argument_list|(
argument|long double
argument_list|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_empty_stmt
unit|} max_align_t
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|double
name|max_align_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

