begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- stdint.h - Standard header for sized integer types --------------===*\  *  * Copyright (c) 2009 Chris Lattner  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  * \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CLANG_STDINT_H
end_ifndef

begin_define
define|#
directive|define
name|__CLANG_STDINT_H
end_define

begin_comment
comment|/* If we're hosted, fall back to the system's stdint.h, which might have  * additional definitions.  */
end_comment

begin_if
if|#
directive|if
name|__STDC_HOSTED__
operator|&&
name|__has_include_next
argument_list|(
operator|<
name|stdint
operator|.
name|h
operator|>
argument_list|)
end_if

begin_comment
comment|// C99 7.18.3 Limits of other integer types
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Footnote 219, 220: C++ implementations should define these macros only when
end_comment

begin_comment
comment|//  __STDC_LIMIT_MACROS is defined before<stdint.h> is included.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Footnote 222: C++ implementations should define these macros only when
end_comment

begin_comment
comment|//  __STDC_CONSTANT_MACROS is defined before<stdint.h> is included.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C++11 [cstdint.syn]p2:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  The macros defined by<cstdint> are provided unconditionally. In particular,
end_comment

begin_comment
comment|//  the symbols __STDC_LIMIT_MACROS and __STDC_CONSTANT_MACROS (mentioned in
end_comment

begin_comment
comment|//  footnotes 219, 220, and 222 in the C standard) play no role in C++.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C11 removed the problematic footnotes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Work around this inconsistency by always defining those macros in C++ mode,
end_comment

begin_comment
comment|// so that a C library implementation which follows the C99 standard can be
end_comment

begin_comment
comment|// used in C++.
end_comment

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
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STDC_LIMIT_MACROS
end_define

begin_define
define|#
directive|define
name|__STDC_LIMIT_MACROS_DEFINED_BY_CLANG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC_CONSTANT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STDC_CONSTANT_MACROS
end_define

begin_define
define|#
directive|define
name|__STDC_CONSTANT_MACROS_DEFINED_BY_CLANG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|# include_next<stdint.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC_LIMIT_MACROS_DEFINED_BY_CLANG
end_ifdef

begin_undef
undef|#
directive|undef
name|__STDC_LIMIT_MACROS
end_undef

begin_undef
undef|#
directive|undef
name|__STDC_LIMIT_MACROS_DEFINED_BY_CLANG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC_CONSTANT_MACROS_DEFINED_BY_CLANG
end_ifdef

begin_undef
undef|#
directive|undef
name|__STDC_CONSTANT_MACROS
end_undef

begin_undef
undef|#
directive|undef
name|__STDC_CONSTANT_MACROS_DEFINED_BY_CLANG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* C99 7.18.1.1 Exact-width integer types.  * C99 7.18.1.2 Minimum-width integer types.  * C99 7.18.1.3 Fastest minimum-width integer types.  *  * The standard requires that exact-width type be defined for 8-, 16-, 32-, and  * 64-bit types if they are implemented. Other exact width types are optional.  * This implementation defines an exact-width types for every integer width  * that is represented in the standard integer types.  *  * The standard also requires minimum-width types be defined for 8-, 16-, 32-,  * and 64-bit widths regardless of whether there are corresponding exact-width  * types.  *  * To accommodate targets that are missing types that are exactly 8, 16, 32, or  * 64 bits wide, this implementation takes an approach of cascading  * redefintions, redefining __int_leastN_t to successively smaller exact-width  * types. It is therefore important that the types are defined in order of  * descending widths.  *  * We currently assume that the minimum-width types and the fastest  * minimum-width types are the same. This is allowed by the standard, but is  * suboptimal.  *  * In violation of the standard, some targets do not implement a type that is  * wide enough to represent all of the required widths (8-, 16-, 32-, 64-bit).  * To accommodate these targets, a required minimum-width type is only  * defined if there exists an exact-width type of equal or greater width.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT64_TYPE__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__int8_t_defined
end_ifndef

begin_comment
comment|/* glibc sys/types.h also defines int64_t*/
end_comment

begin_typedef
typedef|typedef
name|__INT64_TYPE__
name|int64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int8_t_defined */
end_comment

begin_typedef
typedef|typedef
name|__UINT64_TYPE__
name|uint64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__int_least64_t
value|int64_t
end_define

begin_define
define|#
directive|define
name|__uint_least64_t
value|uint64_t
end_define

begin_define
define|#
directive|define
name|__int_least32_t
value|int64_t
end_define

begin_define
define|#
directive|define
name|__uint_least32_t
value|uint64_t
end_define

begin_define
define|#
directive|define
name|__int_least16_t
value|int64_t
end_define

begin_define
define|#
directive|define
name|__uint_least16_t
value|uint64_t
end_define

begin_define
define|#
directive|define
name|__int_least8_t
value|int64_t
end_define

begin_define
define|#
directive|define
name|__uint_least8_t
value|uint64_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT64_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__int_least64_t
end_ifdef

begin_typedef
typedef|typedef
name|__int_least64_t
name|int_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least64_t
name|uint_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_least64_t
name|int_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least64_t
name|uint_fast64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int_least64_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT56_TYPE__
end_ifdef

begin_typedef
typedef|typedef
name|__INT56_TYPE__
name|int56_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__UINT56_TYPE__
name|uint56_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int56_t
name|int_least56_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint56_t
name|uint_least56_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int56_t
name|int_fast56_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint56_t
name|uint_fast56_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__int_least32_t
value|int56_t
end_define

begin_define
define|#
directive|define
name|__uint_least32_t
value|uint56_t
end_define

begin_define
define|#
directive|define
name|__int_least16_t
value|int56_t
end_define

begin_define
define|#
directive|define
name|__uint_least16_t
value|uint56_t
end_define

begin_define
define|#
directive|define
name|__int_least8_t
value|int56_t
end_define

begin_define
define|#
directive|define
name|__uint_least8_t
value|uint56_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT56_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT48_TYPE__
end_ifdef

begin_typedef
typedef|typedef
name|__INT48_TYPE__
name|int48_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__UINT48_TYPE__
name|uint48_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int48_t
name|int_least48_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint48_t
name|uint_least48_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int48_t
name|int_fast48_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint48_t
name|uint_fast48_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__int_least32_t
value|int48_t
end_define

begin_define
define|#
directive|define
name|__uint_least32_t
value|uint48_t
end_define

begin_define
define|#
directive|define
name|__int_least16_t
value|int48_t
end_define

begin_define
define|#
directive|define
name|__uint_least16_t
value|uint48_t
end_define

begin_define
define|#
directive|define
name|__int_least8_t
value|int48_t
end_define

begin_define
define|#
directive|define
name|__uint_least8_t
value|uint48_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT48_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT40_TYPE__
end_ifdef

begin_typedef
typedef|typedef
name|__INT40_TYPE__
name|int40_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__UINT40_TYPE__
name|uint40_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int40_t
name|int_least40_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint40_t
name|uint_least40_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int40_t
name|int_fast40_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint40_t
name|uint_fast40_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__int_least32_t
value|int40_t
end_define

begin_define
define|#
directive|define
name|__uint_least32_t
value|uint40_t
end_define

begin_define
define|#
directive|define
name|__int_least16_t
value|int40_t
end_define

begin_define
define|#
directive|define
name|__uint_least16_t
value|uint40_t
end_define

begin_define
define|#
directive|define
name|__int_least8_t
value|int40_t
end_define

begin_define
define|#
directive|define
name|__uint_least8_t
value|uint40_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT40_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT32_TYPE__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__int8_t_defined
end_ifndef

begin_comment
comment|/* glibc sys/types.h also defines int32_t*/
end_comment

begin_typedef
typedef|typedef
name|__INT32_TYPE__
name|int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int8_t_defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__uint32_t_defined
end_ifndef

begin_comment
comment|/* more glibc compatibility */
end_comment

begin_define
define|#
directive|define
name|__uint32_t_defined
end_define

begin_typedef
typedef|typedef
name|__UINT32_TYPE__
name|uint32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __uint32_t_defined */
end_comment

begin_define
define|#
directive|define
name|__int_least32_t
value|int32_t
end_define

begin_define
define|#
directive|define
name|__uint_least32_t
value|uint32_t
end_define

begin_define
define|#
directive|define
name|__int_least16_t
value|int32_t
end_define

begin_define
define|#
directive|define
name|__uint_least16_t
value|uint32_t
end_define

begin_define
define|#
directive|define
name|__int_least8_t
value|int32_t
end_define

begin_define
define|#
directive|define
name|__uint_least8_t
value|uint32_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT32_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__int_least32_t
end_ifdef

begin_typedef
typedef|typedef
name|__int_least32_t
name|int_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least32_t
name|uint_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_least32_t
name|int_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least32_t
name|uint_fast32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int_least32_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT24_TYPE__
end_ifdef

begin_typedef
typedef|typedef
name|__INT24_TYPE__
name|int24_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__UINT24_TYPE__
name|uint24_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int24_t
name|int_least24_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint24_t
name|uint_least24_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int24_t
name|int_fast24_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint24_t
name|uint_fast24_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__int_least16_t
value|int24_t
end_define

begin_define
define|#
directive|define
name|__uint_least16_t
value|uint24_t
end_define

begin_define
define|#
directive|define
name|__int_least8_t
value|int24_t
end_define

begin_define
define|#
directive|define
name|__uint_least8_t
value|uint24_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT24_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT16_TYPE__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__int8_t_defined
end_ifndef

begin_comment
comment|/* glibc sys/types.h also defines int16_t*/
end_comment

begin_typedef
typedef|typedef
name|__INT16_TYPE__
name|int16_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int8_t_defined */
end_comment

begin_typedef
typedef|typedef
name|__UINT16_TYPE__
name|uint16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__int_least16_t
value|int16_t
end_define

begin_define
define|#
directive|define
name|__uint_least16_t
value|uint16_t
end_define

begin_define
define|#
directive|define
name|__int_least8_t
value|int16_t
end_define

begin_define
define|#
directive|define
name|__uint_least8_t
value|uint16_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT16_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__int_least16_t
end_ifdef

begin_typedef
typedef|typedef
name|__int_least16_t
name|int_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least16_t
name|uint_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_least16_t
name|int_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least16_t
name|uint_fast16_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int_least16_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT8_TYPE__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__int8_t_defined
end_ifndef

begin_comment
comment|/* glibc sys/types.h also defines int8_t*/
end_comment

begin_typedef
typedef|typedef
name|__INT8_TYPE__
name|int8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int8_t_defined */
end_comment

begin_typedef
typedef|typedef
name|__UINT8_TYPE__
name|uint8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__int_least8_t
value|int8_t
end_define

begin_define
define|#
directive|define
name|__uint_least8_t
value|uint8_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT8_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__int_least8_t
end_ifdef

begin_typedef
typedef|typedef
name|__int_least8_t
name|int_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least8_t
name|uint_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_least8_t
name|int_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least8_t
name|uint_fast8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int_least8_t */
end_comment

begin_comment
comment|/* prevent glibc sys/types.h from defining conflicting types */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__int8_t_defined
end_ifndef

begin_define
define|#
directive|define
name|__int8_t_defined
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int8_t_defined */
end_comment

begin_comment
comment|/* C99 7.18.1.4 Integer types capable of holding object pointers.  */
end_comment

begin_define
define|#
directive|define
name|__stdint_join3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a ## b ## c
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_INTPTR_T
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__intptr_t_defined
end_ifndef

begin_typedef
typedef|typedef
name|__INTPTR_TYPE__
name|intptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__intptr_t_defined
end_define

begin_define
define|#
directive|define
name|_INTPTR_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINTPTR_T
end_ifndef

begin_typedef
typedef|typedef
name|__UINTPTR_TYPE__
name|uintptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINTPTR_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C99 7.18.1.5 Greatest-width integer types.  */
end_comment

begin_typedef
typedef|typedef
name|__INTMAX_TYPE__
name|intmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__UINTMAX_TYPE__
name|uintmax_t
typedef|;
end_typedef

begin_comment
comment|/* C99 7.18.4 Macros for minimum-width integer constants.  *  * The standard requires that integer constant macros be defined for all the  * minimum-width types defined above. As 8-, 16-, 32-, and 64-bit minimum-width  * types are required, the corresponding integer constant macros are defined  * here. This implementation also defines minimum-width types for every other  * integer width that the target implements, so corresponding macros are  * defined below, too.  *  * These macros are defined using the same successive-shrinking approach as  * the type definitions above. It is likewise important that macros are defined  * in order of decending width.  *  * Note that C++ should not check __STDC_CONSTANT_MACROS here, contrary to the  * claims of the C standard (see C++ 18.3.1p2, [cstdint.syn]).  */
end_comment

begin_define
define|#
directive|define
name|__int_c_join
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_define
define|#
directive|define
name|__int_c
parameter_list|(
name|v
parameter_list|,
name|suffix
parameter_list|)
value|__int_c_join(v, suffix)
end_define

begin_define
define|#
directive|define
name|__uint_c
parameter_list|(
name|v
parameter_list|,
name|suffix
parameter_list|)
value|__int_c_join(v##U, suffix)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__INT64_TYPE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__INT64_C_SUFFIX__
end_ifdef

begin_define
define|#
directive|define
name|__int64_c_suffix
value|__INT64_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int32_c_suffix
value|__INT64_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int16_c_suffix
value|__INT64_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int8_c_suffix
value|__INT64_C_SUFFIX__
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|__int64_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int32_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int16_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int8_c_suffix
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT64_C_SUFFIX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT64_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__int_least64_t
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__int64_c_suffix
end_ifdef

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __int64_c_suffix)
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|v
parameter_list|)
value|__uint_c(v, __int64_c_suffix)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|v
parameter_list|)
value|v ## U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int64_c_suffix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int_least64_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT56_TYPE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__INT56_C_SUFFIX__
end_ifdef

begin_define
define|#
directive|define
name|INT56_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __INT56_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|UINT56_C
parameter_list|(
name|v
parameter_list|)
value|__uint_c(v, __INT56_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|__int32_c_suffix
value|__INT56_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int16_c_suffix
value|__INT56_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int8_c_suffix
value|__INT56_C_SUFFIX__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT56_C
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|UINT56_C
parameter_list|(
name|v
parameter_list|)
value|v ## U
end_define

begin_undef
undef|#
directive|undef
name|__int32_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int16_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int8_c_suffix
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT56_C_SUFFIX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT56_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT48_TYPE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__INT48_C_SUFFIX__
end_ifdef

begin_define
define|#
directive|define
name|INT48_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __INT48_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|UINT48_C
parameter_list|(
name|v
parameter_list|)
value|__uint_c(v, __INT48_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|__int32_c_suffix
value|__INT48_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int16_c_suffix
value|__INT48_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int8_c_suffix
value|__INT48_C_SUFFIX__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT48_C
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|UINT48_C
parameter_list|(
name|v
parameter_list|)
value|v ## U
end_define

begin_undef
undef|#
directive|undef
name|__int32_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int16_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int8_c_suffix
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT48_C_SUFFIX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT48_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT40_TYPE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__INT40_C_SUFFIX__
end_ifdef

begin_define
define|#
directive|define
name|INT40_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __INT40_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|UINT40_C
parameter_list|(
name|v
parameter_list|)
value|__uint_c(v, __INT40_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|__int32_c_suffix
value|__INT40_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int16_c_suffix
value|__INT40_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int8_c_suffix
value|__INT40_C_SUFFIX__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT40_C
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|UINT40_C
parameter_list|(
name|v
parameter_list|)
value|v ## U
end_define

begin_undef
undef|#
directive|undef
name|__int32_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int16_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int8_c_suffix
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT40_C_SUFFIX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT40_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT32_TYPE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__INT32_C_SUFFIX__
end_ifdef

begin_define
define|#
directive|define
name|__int32_c_suffix
value|__INT32_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int16_c_suffix
value|__INT32_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int8_c_suffix
value|__INT32_C_SUFFIX__
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|__int32_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int16_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int8_c_suffix
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT32_C_SUFFIX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT32_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__int_least32_t
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__int32_c_suffix
end_ifdef

begin_define
define|#
directive|define
name|INT32_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __int32_c_suffix)
end_define

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|v
parameter_list|)
value|__uint_c(v, __int32_c_suffix)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT32_C
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|v
parameter_list|)
value|v ## U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int32_c_suffix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int_least32_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT24_TYPE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__INT24_C_SUFFIX__
end_ifdef

begin_define
define|#
directive|define
name|INT24_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __INT24_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|UINT24_C
parameter_list|(
name|v
parameter_list|)
value|__uint_c(v, __INT24_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|__int16_c_suffix
value|__INT24_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int8_c_suffix
value|__INT24_C_SUFFIX__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT24_C
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|UINT24_C
parameter_list|(
name|v
parameter_list|)
value|v ## U
end_define

begin_undef
undef|#
directive|undef
name|__int16_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int8_c_suffix
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT24_C_SUFFIX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT24_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT16_TYPE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__INT16_C_SUFFIX__
end_ifdef

begin_define
define|#
directive|define
name|__int16_c_suffix
value|__INT16_C_SUFFIX__
end_define

begin_define
define|#
directive|define
name|__int8_c_suffix
value|__INT16_C_SUFFIX__
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|__int16_c_suffix
end_undef

begin_undef
undef|#
directive|undef
name|__int8_c_suffix
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT16_C_SUFFIX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT16_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__int_least16_t
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__int16_c_suffix
end_ifdef

begin_define
define|#
directive|define
name|INT16_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __int16_c_suffix)
end_define

begin_define
define|#
directive|define
name|UINT16_C
parameter_list|(
name|v
parameter_list|)
value|__uint_c(v, __int16_c_suffix)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT16_C
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|UINT16_C
parameter_list|(
name|v
parameter_list|)
value|v ## U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int16_c_suffix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int_least16_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT8_TYPE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__INT8_C_SUFFIX__
end_ifdef

begin_define
define|#
directive|define
name|__int8_c_suffix
value|__INT8_C_SUFFIX__
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|__int8_c_suffix
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT8_C_SUFFIX__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT8_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__int_least8_t
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__int8_c_suffix
end_ifdef

begin_define
define|#
directive|define
name|INT8_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __int8_c_suffix)
end_define

begin_define
define|#
directive|define
name|UINT8_C
parameter_list|(
name|v
parameter_list|)
value|__uint_c(v, __int8_c_suffix)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT8_C
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|UINT8_C
parameter_list|(
name|v
parameter_list|)
value|v ## U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int8_c_suffix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __int_least8_t */
end_comment

begin_comment
comment|/* C99 7.18.2.1 Limits of exact-width integer types.  * C99 7.18.2.2 Limits of minimum-width integer types.  * C99 7.18.2.3 Limits of fastest minimum-width integer types.  *  * The presence of limit macros are completely optional in C99.  This  * implementation defines limits for all of the types (exact- and  * minimum-width) that it defines above, using the limits of the minimum-width  * type for any types that do not have exact-width representations.  *  * As in the type definitions, this section takes an approach of  * successive-shrinking to determine which limits to use for the standard (8,  * 16, 32, 64) bit widths when they don't have exact representations. It is  * therefore important that the defintions be kept in order of decending  * widths.  *  * Note that C++ should not check __STDC_LIMIT_MACROS here, contrary to the  * claims of the C standard (see C++ 18.3.1p2, [cstdint.syn]).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT64_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT64_MAX
value|INT64_C( 9223372036854775807)
end_define

begin_define
define|#
directive|define
name|INT64_MIN
value|(-INT64_C( 9223372036854775807)-1)
end_define

begin_define
define|#
directive|define
name|UINT64_MAX
value|UINT64_C(18446744073709551615)
end_define

begin_define
define|#
directive|define
name|__INT_LEAST64_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST64_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST64_MAX
value|UINT64_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST32_MAX
value|UINT64_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST16_MAX
value|UINT64_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST8_MAX
value|UINT64_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT64_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT_LEAST64_MIN
end_ifdef

begin_define
define|#
directive|define
name|INT_LEAST64_MIN
value|__INT_LEAST64_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST64_MAX
value|__INT_LEAST64_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST64_MAX
value|__UINT_LEAST64_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST64_MIN
value|__INT_LEAST64_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST64_MAX
value|__INT_LEAST64_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST64_MAX
value|__UINT_LEAST64_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT_LEAST64_MIN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT56_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT56_MAX
value|INT56_C(36028797018963967)
end_define

begin_define
define|#
directive|define
name|INT56_MIN
value|(-INT56_C(36028797018963967)-1)
end_define

begin_define
define|#
directive|define
name|UINT56_MAX
value|UINT56_C(72057594037927935)
end_define

begin_define
define|#
directive|define
name|INT_LEAST56_MIN
value|INT56_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST56_MAX
value|INT56_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST56_MAX
value|UINT56_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST56_MIN
value|INT56_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST56_MAX
value|INT56_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST56_MAX
value|UINT56_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MIN
value|INT56_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MAX
value|INT56_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST32_MAX
value|UINT56_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MIN
value|INT56_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MAX
value|INT56_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST16_MAX
value|UINT56_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MIN
value|INT56_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MAX
value|INT56_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST8_MAX
value|UINT56_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT56_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT48_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT48_MAX
value|INT48_C(140737488355327)
end_define

begin_define
define|#
directive|define
name|INT48_MIN
value|(-INT48_C(140737488355327)-1)
end_define

begin_define
define|#
directive|define
name|UINT48_MAX
value|UINT48_C(281474976710655)
end_define

begin_define
define|#
directive|define
name|INT_LEAST48_MIN
value|INT48_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST48_MAX
value|INT48_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST48_MAX
value|UINT48_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST48_MIN
value|INT48_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST48_MAX
value|INT48_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST48_MAX
value|UINT48_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MIN
value|INT48_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MAX
value|INT48_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST32_MAX
value|UINT48_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MIN
value|INT48_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MAX
value|INT48_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST16_MAX
value|UINT48_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MIN
value|INT48_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MAX
value|INT48_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST8_MAX
value|UINT48_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT48_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT40_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT40_MAX
value|INT40_C(549755813887)
end_define

begin_define
define|#
directive|define
name|INT40_MIN
value|(-INT40_C(549755813887)-1)
end_define

begin_define
define|#
directive|define
name|UINT40_MAX
value|UINT40_C(1099511627775)
end_define

begin_define
define|#
directive|define
name|INT_LEAST40_MIN
value|INT40_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST40_MAX
value|INT40_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST40_MAX
value|UINT40_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST40_MIN
value|INT40_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST40_MAX
value|INT40_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST40_MAX
value|UINT40_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MIN
value|INT40_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MAX
value|INT40_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST32_MAX
value|UINT40_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MIN
value|INT40_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MAX
value|INT40_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST16_MAX
value|UINT40_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MIN
value|INT40_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MAX
value|INT40_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST8_MAX
value|UINT40_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT40_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT32_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT32_MAX
value|INT32_C(2147483647)
end_define

begin_define
define|#
directive|define
name|INT32_MIN
value|(-INT32_C(2147483647)-1)
end_define

begin_define
define|#
directive|define
name|UINT32_MAX
value|UINT32_C(4294967295)
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST32_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST32_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST16_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST8_MAX
value|UINT32_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT32_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT_LEAST32_MIN
end_ifdef

begin_define
define|#
directive|define
name|INT_LEAST32_MIN
value|__INT_LEAST32_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST32_MAX
value|__INT_LEAST32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST32_MAX
value|__UINT_LEAST32_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST32_MIN
value|__INT_LEAST32_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST32_MAX
value|__INT_LEAST32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST32_MAX
value|__UINT_LEAST32_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT_LEAST32_MIN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT24_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT24_MAX
value|INT24_C(8388607)
end_define

begin_define
define|#
directive|define
name|INT24_MIN
value|(-INT24_C(8388607)-1)
end_define

begin_define
define|#
directive|define
name|UINT24_MAX
value|UINT24_C(16777215)
end_define

begin_define
define|#
directive|define
name|INT_LEAST24_MIN
value|INT24_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST24_MAX
value|INT24_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST24_MAX
value|UINT24_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST24_MIN
value|INT24_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST24_MAX
value|INT24_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST24_MAX
value|UINT24_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MIN
value|INT24_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MAX
value|INT24_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST16_MAX
value|UINT24_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MIN
value|INT24_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MAX
value|INT24_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST8_MAX
value|UINT24_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT24_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT16_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT16_MAX
value|INT16_C(32767)
end_define

begin_define
define|#
directive|define
name|INT16_MIN
value|(-INT16_C(32767)-1)
end_define

begin_define
define|#
directive|define
name|UINT16_MAX
value|UINT16_C(65535)
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MIN
value|INT16_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST16_MAX
value|INT16_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST16_MAX
value|UINT16_MAX
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MIN
value|INT16_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MAX
value|INT16_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST8_MAX
value|UINT16_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT16_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT_LEAST16_MIN
end_ifdef

begin_define
define|#
directive|define
name|INT_LEAST16_MIN
value|__INT_LEAST16_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST16_MAX
value|__INT_LEAST16_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST16_MAX
value|__UINT_LEAST16_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST16_MIN
value|__INT_LEAST16_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST16_MAX
value|__INT_LEAST16_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST16_MAX
value|__UINT_LEAST16_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT_LEAST16_MIN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT8_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT8_MAX
value|INT8_C(127)
end_define

begin_define
define|#
directive|define
name|INT8_MIN
value|(-INT8_C(127)-1)
end_define

begin_define
define|#
directive|define
name|UINT8_MAX
value|UINT8_C(255)
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MIN
value|INT8_MIN
end_define

begin_define
define|#
directive|define
name|__INT_LEAST8_MAX
value|INT8_MAX
end_define

begin_define
define|#
directive|define
name|__UINT_LEAST8_MAX
value|UINT8_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT8_TYPE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT_LEAST8_MIN
end_ifdef

begin_define
define|#
directive|define
name|INT_LEAST8_MIN
value|__INT_LEAST8_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST8_MAX
value|__INT_LEAST8_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST8_MAX
value|__UINT_LEAST8_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST8_MIN
value|__INT_LEAST8_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST8_MAX
value|__INT_LEAST8_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST8_MAX
value|__UINT_LEAST8_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INT_LEAST8_MIN */
end_comment

begin_comment
comment|/* Some utility macros */
end_comment

begin_define
define|#
directive|define
name|__INTN_MIN
parameter_list|(
name|n
parameter_list|)
value|__stdint_join3( INT, n, _MIN)
end_define

begin_define
define|#
directive|define
name|__INTN_MAX
parameter_list|(
name|n
parameter_list|)
value|__stdint_join3( INT, n, _MAX)
end_define

begin_define
define|#
directive|define
name|__UINTN_MAX
parameter_list|(
name|n
parameter_list|)
value|__stdint_join3(UINT, n, _MAX)
end_define

begin_define
define|#
directive|define
name|__INTN_C
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|__stdint_join3( INT, n, _C(v))
end_define

begin_define
define|#
directive|define
name|__UINTN_C
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|__stdint_join3(UINT, n, _C(v))
end_define

begin_comment
comment|/* C99 7.18.2.4 Limits of integer types capable of holding object pointers. */
end_comment

begin_comment
comment|/* C99 7.18.3 Limits of other integer types. */
end_comment

begin_define
define|#
directive|define
name|INTPTR_MIN
value|(-__INTPTR_MAX__-1)
end_define

begin_define
define|#
directive|define
name|INTPTR_MAX
value|__INTPTR_MAX__
end_define

begin_define
define|#
directive|define
name|UINTPTR_MAX
value|__UINTPTR_MAX__
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MIN
value|(-__PTRDIFF_MAX__-1)
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|__PTRDIFF_MAX__
end_define

begin_define
define|#
directive|define
name|SIZE_MAX
value|__SIZE_MAX__
end_define

begin_comment
comment|/* ISO9899:2011 7.20 (C11 Annex K): Define RSIZE_MAX if __STDC_WANT_LIB_EXT1__  * is enabled. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC_WANT_LIB_EXT1__
argument_list|)
operator|&&
name|__STDC_WANT_LIB_EXT1__
operator|>=
literal|1
end_if

begin_define
define|#
directive|define
name|RSIZE_MAX
value|(SIZE_MAX>> 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C99 7.18.2.5 Limits of greatest-width integer types. */
end_comment

begin_define
define|#
directive|define
name|INTMAX_MIN
value|(-__INTMAX_MAX__-1)
end_define

begin_define
define|#
directive|define
name|INTMAX_MAX
value|__INTMAX_MAX__
end_define

begin_define
define|#
directive|define
name|UINTMAX_MAX
value|__UINTMAX_MAX__
end_define

begin_comment
comment|/* C99 7.18.3 Limits of other integer types. */
end_comment

begin_define
define|#
directive|define
name|SIG_ATOMIC_MIN
value|__INTN_MIN(__SIG_ATOMIC_WIDTH__)
end_define

begin_define
define|#
directive|define
name|SIG_ATOMIC_MAX
value|__INTN_MAX(__SIG_ATOMIC_WIDTH__)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__WINT_UNSIGNED__
end_ifdef

begin_define
define|#
directive|define
name|WINT_MIN
value|__UINTN_C(__WINT_WIDTH__, 0)
end_define

begin_define
define|#
directive|define
name|WINT_MAX
value|__UINTN_MAX(__WINT_WIDTH__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WINT_MIN
value|__INTN_MIN(__WINT_WIDTH__)
end_define

begin_define
define|#
directive|define
name|WINT_MAX
value|__INTN_MAX(__WINT_WIDTH__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|WCHAR_MAX
value|__WCHAR_MAX__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_MIN
end_ifndef

begin_if
if|#
directive|if
name|__WCHAR_MAX__
operator|==
name|__INTN_MAX
argument_list|(
name|__WCHAR_WIDTH__
argument_list|)
end_if

begin_define
define|#
directive|define
name|WCHAR_MIN
value|__INTN_MIN(__WCHAR_WIDTH__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WCHAR_MIN
value|__UINTN_C(__WCHAR_WIDTH__, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 7.18.4.2 Macros for greatest-width integer constants. */
end_comment

begin_define
define|#
directive|define
name|INTMAX_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v,  __INTMAX_C_SUFFIX__)
end_define

begin_define
define|#
directive|define
name|UINTMAX_C
parameter_list|(
name|v
parameter_list|)
value|__int_c(v, __UINTMAX_C_SUFFIX__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC_HOSTED__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CLANG_STDINT_H */
end_comment

end_unit

