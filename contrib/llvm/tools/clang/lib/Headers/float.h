begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- float.h - Characteristics of floating point types ----------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FLOAT_H
end_ifndef

begin_define
define|#
directive|define
name|__FLOAT_H
end_define

begin_comment
comment|/* If we're on MinGW, fall back to the system's float.h, which might have  * additional definitions provided for Windows.  * For more details see http://msdn.microsoft.com/en-us/library/y0ybw9fy.aspx  *  * Also fall back on Darwin to allow additional definitions and  * implementation-defined values.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|)
operator|)
operator|&&
expr|\
name|__STDC_HOSTED__
operator|&&
name|__has_include_next
argument_list|(
operator|<
name|float
operator|.
name|h
operator|>
argument_list|)
end_if

begin_comment
comment|/* Prior to Apple's 10.7 SDK, float.h SDK header used to apply an extra level  * of #include_next<float.h> to keep Metrowerks compilers happy. Avoid this  * extra indirection.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_define
define|#
directive|define
name|_FLOAT_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#  include_next<float.h>
end_empty

begin_comment
comment|/* Undefine anything that we'll be redefining below. */
end_comment

begin_undef
undef|#
directive|undef
name|FLT_EVAL_METHOD
end_undef

begin_undef
undef|#
directive|undef
name|FLT_ROUNDS
end_undef

begin_undef
undef|#
directive|undef
name|FLT_RADIX
end_undef

begin_undef
undef|#
directive|undef
name|FLT_MANT_DIG
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MANT_DIG
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MANT_DIG
end_undef

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|DECIMAL_DIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|FLT_DIG
end_undef

begin_undef
undef|#
directive|undef
name|DBL_DIG
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_DIG
end_undef

begin_undef
undef|#
directive|undef
name|FLT_MIN_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MIN_EXP
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MIN_EXP
end_undef

begin_undef
undef|#
directive|undef
name|FLT_MIN_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MIN_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MIN_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|FLT_MAX_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MAX_EXP
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MAX_EXP
end_undef

begin_undef
undef|#
directive|undef
name|FLT_MAX_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MAX_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MAX_10_EXP
end_undef

begin_undef
undef|#
directive|undef
name|FLT_MAX
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MAX
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MAX
end_undef

begin_undef
undef|#
directive|undef
name|FLT_EPSILON
end_undef

begin_undef
undef|#
directive|undef
name|DBL_EPSILON
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_EPSILON
end_undef

begin_undef
undef|#
directive|undef
name|FLT_MIN
end_undef

begin_undef
undef|#
directive|undef
name|DBL_MIN
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_MIN
end_undef

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|201112L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|FLT_TRUE_MIN
end_undef

begin_undef
undef|#
directive|undef
name|DBL_TRUE_MIN
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_TRUE_MIN
end_undef

begin_undef
undef|#
directive|undef
name|FLT_DECIMAL_DIG
end_undef

begin_undef
undef|#
directive|undef
name|DBL_DECIMAL_DIG
end_undef

begin_undef
undef|#
directive|undef
name|LDBL_DECIMAL_DIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Characteristics of floating point types, C99 5.2.4.2.2 */
end_comment

begin_define
define|#
directive|define
name|FLT_EVAL_METHOD
value|__FLT_EVAL_METHOD__
end_define

begin_define
define|#
directive|define
name|FLT_ROUNDS
value|(__builtin_flt_rounds())
end_define

begin_define
define|#
directive|define
name|FLT_RADIX
value|__FLT_RADIX__
end_define

begin_define
define|#
directive|define
name|FLT_MANT_DIG
value|__FLT_MANT_DIG__
end_define

begin_define
define|#
directive|define
name|DBL_MANT_DIG
value|__DBL_MANT_DIG__
end_define

begin_define
define|#
directive|define
name|LDBL_MANT_DIG
value|__LDBL_MANT_DIG__
end_define

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECIMAL_DIG
value|__DECIMAL_DIG__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FLT_DIG
value|__FLT_DIG__
end_define

begin_define
define|#
directive|define
name|DBL_DIG
value|__DBL_DIG__
end_define

begin_define
define|#
directive|define
name|LDBL_DIG
value|__LDBL_DIG__
end_define

begin_define
define|#
directive|define
name|FLT_MIN_EXP
value|__FLT_MIN_EXP__
end_define

begin_define
define|#
directive|define
name|DBL_MIN_EXP
value|__DBL_MIN_EXP__
end_define

begin_define
define|#
directive|define
name|LDBL_MIN_EXP
value|__LDBL_MIN_EXP__
end_define

begin_define
define|#
directive|define
name|FLT_MIN_10_EXP
value|__FLT_MIN_10_EXP__
end_define

begin_define
define|#
directive|define
name|DBL_MIN_10_EXP
value|__DBL_MIN_10_EXP__
end_define

begin_define
define|#
directive|define
name|LDBL_MIN_10_EXP
value|__LDBL_MIN_10_EXP__
end_define

begin_define
define|#
directive|define
name|FLT_MAX_EXP
value|__FLT_MAX_EXP__
end_define

begin_define
define|#
directive|define
name|DBL_MAX_EXP
value|__DBL_MAX_EXP__
end_define

begin_define
define|#
directive|define
name|LDBL_MAX_EXP
value|__LDBL_MAX_EXP__
end_define

begin_define
define|#
directive|define
name|FLT_MAX_10_EXP
value|__FLT_MAX_10_EXP__
end_define

begin_define
define|#
directive|define
name|DBL_MAX_10_EXP
value|__DBL_MAX_10_EXP__
end_define

begin_define
define|#
directive|define
name|LDBL_MAX_10_EXP
value|__LDBL_MAX_10_EXP__
end_define

begin_define
define|#
directive|define
name|FLT_MAX
value|__FLT_MAX__
end_define

begin_define
define|#
directive|define
name|DBL_MAX
value|__DBL_MAX__
end_define

begin_define
define|#
directive|define
name|LDBL_MAX
value|__LDBL_MAX__
end_define

begin_define
define|#
directive|define
name|FLT_EPSILON
value|__FLT_EPSILON__
end_define

begin_define
define|#
directive|define
name|DBL_EPSILON
value|__DBL_EPSILON__
end_define

begin_define
define|#
directive|define
name|LDBL_EPSILON
value|__LDBL_EPSILON__
end_define

begin_define
define|#
directive|define
name|FLT_MIN
value|__FLT_MIN__
end_define

begin_define
define|#
directive|define
name|DBL_MIN
value|__DBL_MIN__
end_define

begin_define
define|#
directive|define
name|LDBL_MIN
value|__LDBL_MIN__
end_define

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|201112L
operator|||
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|FLT_TRUE_MIN
value|__FLT_DENORM_MIN__
end_define

begin_define
define|#
directive|define
name|DBL_TRUE_MIN
value|__DBL_DENORM_MIN__
end_define

begin_define
define|#
directive|define
name|LDBL_TRUE_MIN
value|__LDBL_DENORM_MIN__
end_define

begin_define
define|#
directive|define
name|FLT_DECIMAL_DIG
value|__FLT_DECIMAL_DIG__
end_define

begin_define
define|#
directive|define
name|DBL_DECIMAL_DIG
value|__DBL_DECIMAL_DIG__
end_define

begin_define
define|#
directive|define
name|LDBL_DECIMAL_DIG
value|__LDBL_DECIMAL_DIG__
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
comment|/* __FLOAT_H */
end_comment

end_unit

