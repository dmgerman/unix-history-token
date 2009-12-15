begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- limits.h - Standard header for integer sizes --------------------===*\  *  * Copyright (c) 2009 Chris Lattner  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  * \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CLANG_LIMITS_H
end_ifndef

begin_define
define|#
directive|define
name|__CLANG_LIMITS_H
end_define

begin_comment
comment|/* The system's limits.h may, in turn, try to #include_next GCC's limits.h.    Avert this #include_next madness. */
end_comment

begin_if
if|#
directive|if
name|defined
name|__GNUC__
operator|&&
operator|!
name|defined
name|_GCC_LIMITS_H_
end_if

begin_define
define|#
directive|define
name|_GCC_LIMITS_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System headers include a number of constants from POSIX in<limits.h>. */
end_comment

begin_empty
empty|#include_next<limits.h>
end_empty

begin_comment
comment|/* Many system headers try to "help us out" by defining these.  No really, we    know how big each datatype is. */
end_comment

begin_undef
undef|#
directive|undef
name|SCHAR_MIN
end_undef

begin_undef
undef|#
directive|undef
name|SCHAR_MAX
end_undef

begin_undef
undef|#
directive|undef
name|UCHAR_MAX
end_undef

begin_undef
undef|#
directive|undef
name|SHRT_MIN
end_undef

begin_undef
undef|#
directive|undef
name|SHRT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|USHRT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|INT_MIN
end_undef

begin_undef
undef|#
directive|undef
name|INT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|UINT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|LONG_MIN
end_undef

begin_undef
undef|#
directive|undef
name|LONG_MAX
end_undef

begin_undef
undef|#
directive|undef
name|ULONG_MAX
end_undef

begin_undef
undef|#
directive|undef
name|CHAR_BIT
end_undef

begin_undef
undef|#
directive|undef
name|CHAR_MIN
end_undef

begin_undef
undef|#
directive|undef
name|CHAR_MAX
end_undef

begin_comment
comment|/* C90/99 5.2.4.2.1 */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MAX
value|__SCHAR_MAX__
end_define

begin_define
define|#
directive|define
name|SHRT_MAX
value|__SHRT_MAX__
end_define

begin_define
define|#
directive|define
name|INT_MAX
value|__INT_MAX__
end_define

begin_define
define|#
directive|define
name|LONG_MAX
value|__LONG_MAX__
end_define

begin_define
define|#
directive|define
name|SCHAR_MIN
value|(-__SCHAR_MAX__-1)
end_define

begin_define
define|#
directive|define
name|SHRT_MIN
value|(-__SHRT_MAX__ -1)
end_define

begin_define
define|#
directive|define
name|INT_MIN
value|(-__INT_MAX__  -1)
end_define

begin_define
define|#
directive|define
name|LONG_MIN
value|(-__LONG_MAX__ -1L)
end_define

begin_define
define|#
directive|define
name|UCHAR_MAX
value|(__SCHAR_MAX__*2  +1)
end_define

begin_define
define|#
directive|define
name|USHRT_MAX
value|(__SHRT_MAX__ *2  +1)
end_define

begin_define
define|#
directive|define
name|UINT_MAX
value|(__INT_MAX__  *2U +1U)
end_define

begin_define
define|#
directive|define
name|ULONG_MAX
value|(__LONG_MAX__ *2UL+1UL)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MB_LEN_MAX
end_ifndef

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CHAR_BIT
value|__CHAR_BIT__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__CHAR_UNSIGNED__
end_ifdef

begin_comment
comment|/* -funsigned-char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CHAR_MAX
value|UCHAR_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAR_MIN
value|SCHAR_MIN
end_define

begin_define
define|#
directive|define
name|CHAR_MAX
value|__SCHAR_MAX__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C99 5.2.4.2.1: Added long long. */
end_comment

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901
end_if

begin_undef
undef|#
directive|undef
name|LLONG_MIN
end_undef

begin_undef
undef|#
directive|undef
name|LLONG_MAX
end_undef

begin_undef
undef|#
directive|undef
name|ULLONG_MAX
end_undef

begin_define
define|#
directive|define
name|LLONG_MAX
value|__LONG_LONG_MAX__
end_define

begin_define
define|#
directive|define
name|LLONG_MIN
value|(-__LONG_LONG_MAX__-1LL)
end_define

begin_define
define|#
directive|define
name|ULLONG_MAX
value|(__LONG_LONG_MAX__*2ULL+1ULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LONG_LONG_MIN/LONG_LONG_MAX/ULONG_LONG_MAX are a GNU extension.  It's too bad    that we don't have something like #pragma poison that could be used to    deprecate a macro - the code should just use LLONG_MAX and friends.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNU_LIBRARY__
argument_list|)
condition|?
name|defined
argument_list|(
name|__USE_GNU
argument_list|)
expr|:
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|LONG_LONG_MIN
end_undef

begin_undef
undef|#
directive|undef
name|LONG_LONG_MAX
end_undef

begin_undef
undef|#
directive|undef
name|ULONG_LONG_MAX
end_undef

begin_define
define|#
directive|define
name|LONG_LONG_MAX
value|__LONG_LONG_MAX__
end_define

begin_define
define|#
directive|define
name|LONG_LONG_MIN
value|(-__LONG_LONG_MAX__-1LL)
end_define

begin_define
define|#
directive|define
name|ULONG_LONG_MAX
value|(__LONG_LONG_MAX__*2ULL+1ULL)
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
comment|/* __CLANG_LIMITS_H */
end_comment

end_unit

