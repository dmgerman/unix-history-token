begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)limits.h	8.3 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE__LIMITS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE__LIMITS_H_
end_define

begin_define
define|#
directive|define
name|__CHAR_BIT
value|8
end_define

begin_comment
comment|/* number of bits in a char */
end_comment

begin_define
define|#
directive|define
name|__SCHAR_MAX
value|0x7f
end_define

begin_comment
comment|/* max value for a signed char */
end_comment

begin_define
define|#
directive|define
name|__SCHAR_MIN
value|(-0x7f - 1)
end_define

begin_comment
comment|/* min value for a signed char */
end_comment

begin_define
define|#
directive|define
name|__UCHAR_MAX
value|0xff
end_define

begin_comment
comment|/* max value for an unsigned char */
end_comment

begin_define
define|#
directive|define
name|__USHRT_MAX
value|0xffff
end_define

begin_comment
comment|/* max value for an unsigned short */
end_comment

begin_define
define|#
directive|define
name|__SHRT_MAX
value|0x7fff
end_define

begin_comment
comment|/* max value for a short */
end_comment

begin_define
define|#
directive|define
name|__SHRT_MIN
value|(-0x7fff - 1)
end_define

begin_comment
comment|/* min value for a short */
end_comment

begin_define
define|#
directive|define
name|__UINT_MAX
value|0xffffffffU
end_define

begin_comment
comment|/* max value for an unsigned int */
end_comment

begin_define
define|#
directive|define
name|__INT_MAX
value|0x7fffffff
end_define

begin_comment
comment|/* max value for an int */
end_comment

begin_define
define|#
directive|define
name|__INT_MIN
value|(-0x7fffffff - 1)
end_define

begin_comment
comment|/* min value for an int */
end_comment

begin_comment
comment|/* Bad hack for gcc configured to give 64-bit longs. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LARGE_LONG
end_ifdef

begin_define
define|#
directive|define
name|__ULONG_MAX
value|0xffffffffffffffffUL
end_define

begin_define
define|#
directive|define
name|__LONG_MAX
value|0x7fffffffffffffffL
end_define

begin_define
define|#
directive|define
name|__LONG_MIN
value|(-0x7fffffffffffffffL - 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ULONG_MAX
value|0xffffffffUL
end_define

begin_comment
comment|/* max value for an unsigned long */
end_comment

begin_define
define|#
directive|define
name|__LONG_MAX
value|0x7fffffffL
end_define

begin_comment
comment|/* max value for a long */
end_comment

begin_define
define|#
directive|define
name|__LONG_MIN
value|(-0x7fffffffL - 1)
end_define

begin_comment
comment|/* min value for a long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* max value for an unsigned long long */
end_comment

begin_define
define|#
directive|define
name|__ULLONG_MAX
value|0xffffffffffffffffULL
end_define

begin_define
define|#
directive|define
name|__LLONG_MAX
value|0x7fffffffffffffffLL
end_define

begin_comment
comment|/* max value for a long long */
end_comment

begin_define
define|#
directive|define
name|__LLONG_MIN
value|(-0x7fffffffffffffffLL - 1)
end_define

begin_comment
comment|/* min for a long long */
end_comment

begin_define
define|#
directive|define
name|__SSIZE_MAX
value|__INT_MAX
end_define

begin_comment
comment|/* max value for a ssize_t */
end_comment

begin_define
define|#
directive|define
name|__SIZE_T_MAX
value|__UINT_MAX
end_define

begin_comment
comment|/* max value for a size_t */
end_comment

begin_define
define|#
directive|define
name|__OFF_MAX
value|__LLONG_MAX
end_define

begin_comment
comment|/* max value for an off_t */
end_comment

begin_define
define|#
directive|define
name|__OFF_MIN
value|__LLONG_MIN
end_define

begin_comment
comment|/* min value for an off_t */
end_comment

begin_comment
comment|/* Quads and long longs are the same size.  Ensure they stay in sync. */
end_comment

begin_define
define|#
directive|define
name|__UQUAD_MAX
value|__ULLONG_MAX
end_define

begin_comment
comment|/* max value for a uquad_t */
end_comment

begin_define
define|#
directive|define
name|__QUAD_MAX
value|__LLONG_MAX
end_define

begin_comment
comment|/* max value for a quad_t */
end_comment

begin_define
define|#
directive|define
name|__QUAD_MIN
value|__LLONG_MIN
end_define

begin_comment
comment|/* min value for a quad_t */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LARGE_LONG
end_ifdef

begin_define
define|#
directive|define
name|__LONG_BIT
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__LONG_BIT
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__WORD_BIT
value|32
end_define

begin_define
define|#
directive|define
name|__DBL_DIG
value|15
end_define

begin_define
define|#
directive|define
name|__DBL_MAX
value|1.7976931348623157E+308
end_define

begin_define
define|#
directive|define
name|__DBL_MIN
value|2.2250738585072014E-308
end_define

begin_define
define|#
directive|define
name|__FLT_DIG
value|6
end_define

begin_define
define|#
directive|define
name|__FLT_MAX
value|3.40282347E+38F
end_define

begin_define
define|#
directive|define
name|__FLT_MIN
value|1.17549435E-38F
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE__LIMITS_H_ */
end_comment

end_unit

