begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)limits.h	8.3 (Berkeley) 1/4/94  *	From: NetBSD: limits.h,v 1.3 1997/04/06 08:47:31 cgd Exp  * $FreeBSD$  */
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

begin_comment
comment|/*  * According to ANSI (section 2.2.4.2), the values below must be usable by  * #if preprocessing directives.  Additionally, the expression must have the  * same type as would an expression that is an object of the corresponding  * type converted according to the integral promotions.  The subtraction for  * INT_MIN, etc., is so the value is not unsigned; e.g., 0x80000000 is an  * unsigned int for 32-bit two's complement ANSI compilers (section 3.1.3.2).  * These numbers are for the default configuration of gcc.  They work for  * some other compilers as well, but this should not be depended on.  */
end_comment

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
value|(-0x7f-1)
end_define

begin_comment
comment|/* min value for a signed char */
end_comment

begin_define
define|#
directive|define
name|__UCHAR_MAX
value|0xffU
end_define

begin_comment
comment|/* max value for an unsigned char */
end_comment

begin_define
define|#
directive|define
name|__CHAR_MAX
value|0x7f
end_define

begin_comment
comment|/* max value for a char */
end_comment

begin_define
define|#
directive|define
name|__CHAR_MIN
value|(-0x7f-1)
end_define

begin_comment
comment|/* min value for a char */
end_comment

begin_define
define|#
directive|define
name|__USHRT_MAX
value|0xffffU
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
value|(-0x7fff-1)
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
value|(-0x7fffffff-1)
end_define

begin_comment
comment|/* min value for an int */
end_comment

begin_define
define|#
directive|define
name|__ULONG_MAX
value|0xffffffffffffffffUL
end_define

begin_comment
comment|/* max for an unsigned long */
end_comment

begin_define
define|#
directive|define
name|__LONG_MAX
value|0x7fffffffffffffffL
end_define

begin_comment
comment|/* max for a long */
end_comment

begin_define
define|#
directive|define
name|__LONG_MIN
value|(-0x7fffffffffffffffL-1)
end_define

begin_comment
comment|/* min for a long */
end_comment

begin_comment
comment|/* Long longs and longs are the same size on the alpha. */
end_comment

begin_comment
comment|/* max for an unsigned long long */
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
comment|/* max for a long long */
end_comment

begin_define
define|#
directive|define
name|__LLONG_MIN
value|(-0x7fffffffffffffffLL-1)
end_define

begin_comment
comment|/* min for a long long */
end_comment

begin_define
define|#
directive|define
name|__SSIZE_MAX
value|__LONG_MAX
end_define

begin_comment
comment|/* max value for a ssize_t */
end_comment

begin_define
define|#
directive|define
name|__SIZE_T_MAX
value|__ULONG_MAX
end_define

begin_comment
comment|/* max value for a size_t */
end_comment

begin_define
define|#
directive|define
name|__OFF_MAX
value|__LONG_MAX
end_define

begin_comment
comment|/* max value for a off_t */
end_comment

begin_define
define|#
directive|define
name|__OFF_MIN
value|__LONG_MIN
end_define

begin_comment
comment|/* min value for a off_t */
end_comment

begin_comment
comment|/* Quads and longs are the same on the alpha. Ensure they stay in sync. */
end_comment

begin_define
define|#
directive|define
name|__UQUAD_MAX
value|(__ULONG_MAX)
end_define

begin_comment
comment|/* max value for a uquad_t */
end_comment

begin_define
define|#
directive|define
name|__QUAD_MAX
value|(__LONG_MAX)
end_define

begin_comment
comment|/* max value for a quad_t */
end_comment

begin_define
define|#
directive|define
name|__QUAD_MIN
value|(__LONG_MIN)
end_define

begin_comment
comment|/* min value for a quad_t */
end_comment

begin_define
define|#
directive|define
name|__LONG_BIT
value|64
end_define

begin_define
define|#
directive|define
name|__WORD_BIT
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE__LIMITS_H_ */
end_comment

end_unit

