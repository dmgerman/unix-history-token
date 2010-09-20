begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- stddef.h - Basic type definitions --------------------------------===  *  * Copyright (c) 2008 Eli Friedman  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDDEF_H
end_ifndef

begin_define
define|#
directive|define
name|__STDDEF_H
end_define

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|((int*)
literal|0
argument|)-((int*)
literal|0
argument|)
argument_list|)
name|ptrdiff_t
expr_stmt|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T
end_ifndef

begin_define
define|#
directive|define
name|_SIZE_T
end_define

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T
end_ifndef

begin_define
define|#
directive|define
name|_WCHAR_T
end_define

begin_typedef
typedef|typedef
name|__WCHAR_TYPE__
name|wchar_t
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

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_undef
undef|#
directive|undef
name|__null
end_undef

begin_comment
comment|// VC++ hack.
end_comment

begin_define
define|#
directive|define
name|NULL
value|__null
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULL
value|((void*)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Some C libraries expect to see a wint_t here. Others (notably MinGW) will use
end_comment

begin_comment
comment|// __WINT_TYPE__ directly; accomodate both by requiring __need_wint_t
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_wint_t
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_WINT_T
argument_list|)
end_if

begin_define
define|#
directive|define
name|_WINT_T
end_define

begin_typedef
typedef|typedef
name|__WINT_TYPE__
name|wint_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|t
parameter_list|,
name|d
parameter_list|)
value|__builtin_offsetof(t, d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDDEF_H */
end_comment

end_unit

