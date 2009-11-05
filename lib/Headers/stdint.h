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
expr|\
name|defined
argument_list|(
name|__has_include_next
argument_list|)
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

begin_empty
empty|# include_next<stdint.h>
end_empty

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We currently only support targets with power of two, 2s complement integers.  */
end_comment

begin_comment
comment|/* C99 7.18.1.1 Exact-width integer types.  * C99 7.18.1.2 Minimum-width integer types.  * C99 7.18.1.3 Fastest minimum-width integer types.  * Since we only support pow-2 targets, these map directly to exact width types.  */
end_comment

begin_comment
comment|/* Some 16-bit targets do not have a 64-bit datatype.  Only define the 64-bit  * typedefs if there is something to typedef them to.  */
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
comment|/* glibc does weird things with sys/types.h */
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

begin_typedef
typedef|typedef
name|unsigned
name|__INT64_TYPE__
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|int_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|uint_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|int_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|uint_fast64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__int8_t_defined
end_ifndef

begin_comment
comment|/* glibc does weird things with sys/types.h */
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
name|unsigned
name|__INT32_TYPE__
name|uint32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int32_t
name|int_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uint_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|int_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|uint_fast32_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__int8_t_defined
end_ifndef

begin_comment
comment|/* glibc does weird things with sys/types.h */
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

begin_typedef
typedef|typedef
name|unsigned
name|__INT16_TYPE__
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|int_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|uint_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|int_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|uint_fast16_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__int8_t_defined
end_ifndef

begin_comment
comment|/* glibc does weird things with sys/types.h */
end_comment

begin_typedef
typedef|typedef
name|signed
name|__INT8_TYPE__
name|int8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|__INT8_TYPE__
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|int_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|uint_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|int_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|uint_fast8_t
typedef|;
end_typedef

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

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|__INTPTR_TYPE__
name|uintptr_t
typedef|;
end_typedef

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
comment|/* C99 7.18.4 Macros for minimum-width integer constants.  *  * Note that C++ should not check __STDC_CONSTANT_MACROS here, contrary to the  * claims of the C standard (see C++ 18.3.1p2, [cstdint.syn]).  */
end_comment

begin_comment
comment|/* Only define the 64-bit size macros if we have 64-bit support. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__INT64_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|v
parameter_list|)
value|(v##LL)
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|v
parameter_list|)
value|(v##ULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INT32_C
parameter_list|(
name|v
parameter_list|)
value|(v)
end_define

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|v
parameter_list|)
value|(v##U)
end_define

begin_define
define|#
directive|define
name|INT16_C
parameter_list|(
name|v
parameter_list|)
value|(v)
end_define

begin_define
define|#
directive|define
name|UINT16_C
parameter_list|(
name|v
parameter_list|)
value|(v##U)
end_define

begin_define
define|#
directive|define
name|INT8_C
parameter_list|(
name|v
parameter_list|)
value|(v)
end_define

begin_define
define|#
directive|define
name|UINT8_C
parameter_list|(
name|v
parameter_list|)
value|(v##U)
end_define

begin_comment
comment|/* C99 7.18.2.1 Limits of exact-width integer types.   * Fixed sized values have fixed size max/min.  * C99 7.18.2.2 Limits of minimum-width integer types.  * Since we map these directly onto fixed-sized types, these values the same.  * C99 7.18.2.3 Limits of fastest minimum-width integer types.  *  * Note that C++ should not check __STDC_LIMIT_MACROS here, contrary to the  * claims of the C standard (see C++ 18.3.1p2, [cstdint.syn]).  */
end_comment

begin_comment
comment|/* If we do not have 64-bit support, don't define the 64-bit size macros. */
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
value|9223372036854775807LL
end_define

begin_define
define|#
directive|define
name|INT64_MIN
value|(-9223372036854775807LL-1)
end_define

begin_define
define|#
directive|define
name|UINT64_MAX
value|18446744073709551615ULL
end_define

begin_define
define|#
directive|define
name|INT_LEAST64_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST64_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST64_MAX
value|UINT64_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST64_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST64_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST64_MAX
value|UINT64_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INT32_MAX
value|2147483647
end_define

begin_define
define|#
directive|define
name|INT32_MIN
value|(-2147483647-1)
end_define

begin_define
define|#
directive|define
name|UINT32_MAX
value|4294967295U
end_define

begin_define
define|#
directive|define
name|INT_LEAST32_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST32_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST32_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST32_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST32_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST32_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|INT16_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|INT16_MIN
value|(-32768)
end_define

begin_define
define|#
directive|define
name|UINT16_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|INT_LEAST16_MIN
value|INT16_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST16_MAX
value|INT16_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST16_MAX
value|UINT16_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST16_MIN
value|INT16_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST16_MAX
value|INT16_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST16_MAX
value|UINT16_MAX
end_define

begin_define
define|#
directive|define
name|INT8_MAX
value|127
end_define

begin_define
define|#
directive|define
name|INT8_MIN
value|(-128)
end_define

begin_define
define|#
directive|define
name|UINT8_MAX
value|255
end_define

begin_define
define|#
directive|define
name|INT_LEAST8_MIN
value|INT8_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST8_MAX
value|INT8_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST8_MAX
value|UINT8_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST8_MIN
value|INT8_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST8_MAX
value|INT8_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST8_MAX
value|UINT8_MAX
end_define

begin_comment
comment|/* C99 7.18.2.4 Limits of integer types capable of holding object pointers. */
end_comment

begin_comment
comment|/* C99 7.18.3 Limits of other integer types. */
end_comment

begin_if
if|#
directive|if
name|__POINTER_WIDTH__
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|INTPTR_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|INTPTR_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|UINTPTR_MAX
value|UINT64_MAX
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|SIZE_MAX
value|UINT64_MAX
end_define

begin_elif
elif|#
directive|elif
name|__POINTER_WIDTH__
operator|==
literal|32
end_elif

begin_define
define|#
directive|define
name|INTPTR_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|INTPTR_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|UINTPTR_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|SIZE_MAX
value|UINT32_MAX
end_define

begin_elif
elif|#
directive|elif
name|__POINTER_WIDTH__
operator|==
literal|16
end_elif

begin_define
define|#
directive|define
name|INTPTR_MIN
value|INT16_MIN
end_define

begin_define
define|#
directive|define
name|INTPTR_MAX
value|INT16_MAX
end_define

begin_define
define|#
directive|define
name|UINTPTR_MAX
value|UINT16_MAX
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MIN
value|INT16_MIN
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|INT16_MAX
end_define

begin_define
define|#
directive|define
name|SIZE_MAX
value|UINT16_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"unknown or unset pointer width!"
end_error

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
value|(__INTMAX_MAX__*2ULL+1ULL)
end_define

begin_comment
comment|/* C99 7.18.3 Limits of other integer types. */
end_comment

begin_define
define|#
directive|define
name|SIG_ATOMIC_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|SIG_ATOMIC_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|WINT_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|WINT_MAX
value|INT32_MAX
end_define

begin_comment
comment|/* FIXME: if we ever support a target with unsigned wchar_t, this should be  * 0 .. Max.  */
end_comment

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

begin_define
define|#
directive|define
name|WCHAR_MIN
value|(-__WCHAR_MAX__-1)
end_define

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
value|(v##LL)
end_define

begin_define
define|#
directive|define
name|UINTMAX_C
parameter_list|(
name|v
parameter_list|)
value|(v##ULL)
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

