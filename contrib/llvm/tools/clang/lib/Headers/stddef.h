begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- stddef.h - Basic type definitions --------------------------------===  *  * Copyright (c) 2008 Eli Friedman  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDDEF_H
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__need_size_t
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_wchar_t
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__need_NULL
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_wint_t
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__need_size_t
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__need_wchar_t
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__need_NULL
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__need_wint_t
argument_list|)
end_if

begin_comment
comment|/* Always define miscellaneous pieces when modules are available. */
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STDDEF_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__need_ptrdiff_t
end_define

begin_define
define|#
directive|define
name|__need_size_t
end_define

begin_define
define|#
directive|define
name|__need_wchar_t
end_define

begin_define
define|#
directive|define
name|__need_NULL
end_define

begin_define
define|#
directive|define
name|__need_STDDEF_H_misc
end_define

begin_comment
comment|/* __need_wint_t is intentionally not defined here. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_PTRDIFF_T
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_comment
comment|/* Always define ptrdiff_t when modules are available. */
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PTRDIFF_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__PTRDIFF_TYPE__
name|ptrdiff_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__need_ptrdiff_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__need_ptrdiff_t) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_size_t
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_SIZE_T
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_comment
comment|/* Always define size_t when modules are available. */
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_define
define|#
directive|define
name|_SIZE_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|__need_size_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*defined(__need_size_t) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_STDDEF_H_misc
argument_list|)
end_if

begin_comment
comment|/* ISO9899:2011 7.20 (C11 Annex K): Define rsize_t if __STDC_WANT_LIB_EXT1__ is  * enabled. */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__STDC_WANT_LIB_EXT1__
argument_list|)
operator|&&
name|__STDC_WANT_LIB_EXT1__
operator|>=
literal|1
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|_RSIZE_T
argument_list|)
operator|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_comment
comment|/* Always define rsize_t when modules are available. */
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RSIZE_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|rsize_t
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

begin_comment
comment|/* defined(__need_STDDEF_H_misc) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_wchar_t
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* Always define wchar_t when modules are available. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WCHAR_T
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_define
define|#
directive|define
name|_WCHAR_T
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
end_if

begin_define
define|#
directive|define
name|_WCHAR_T_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|__need_wchar_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__need_wchar_t) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_NULL
argument_list|)
end_if

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

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
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
operator|&&
name|defined
argument_list|(
name|_NATIVE_NULLPTR_SUPPORTED
argument_list|)
end_if

begin_decl_stmt
name|namespace
name|std
block|{
typedef|typedef
name|decltype
argument_list|(
argument|nullptr
argument_list|)
name|nullptr_t
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|using
operator|::
name|std
operator|::
name|nullptr_t
expr_stmt|;
end_expr_stmt

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
name|__need_NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__need_NULL) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_STDDEF_H_misc
argument_list|)
end_if

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|201112L
operator|||
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_include
include|#
directive|include
file|"__stddef_max_align_t.h"
end_include

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

begin_undef
undef|#
directive|undef
name|__need_STDDEF_H_misc
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__need_STDDEF_H_misc) */
end_comment

begin_comment
comment|/* Some C libraries expect to see a wint_t here. Others (notably MinGW) will use __WINT_TYPE__ directly; accommodate both by requiring __need_wint_t */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_wint_t
argument_list|)
end_if

begin_comment
comment|/* Always define wint_t when modules are available. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WINT_T
argument_list|)
operator|||
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|modules
argument_list|)
end_if

begin_define
define|#
directive|define
name|_WINT_T
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_undef
undef|#
directive|undef
name|__need_wint_t
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __need_wint_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

