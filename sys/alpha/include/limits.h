begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)limits.h	8.3 (Berkeley) 1/4/94  *	From: NetBSD: limits.h,v 1.3 1997/04/06 08:47:31 cgd Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_LIMITS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_LIMITS_H_
end_define

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_comment
comment|/* number of bits in a char */
end_comment

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|6
end_define

begin_comment
comment|/* Allow 31 bit UTF2 */
end_comment

begin_comment
comment|/*  * According to ANSI (section 2.2.4.2), the values below must be usable by  * #if preprocessing directives.  Additionally, the expression must have the  * same type as would an expression that is an object of the corresponding  * type converted according to the integral promotions.  The subtraction for  * INT_MIN, etc., is so the value is not unsigned; e.g., 0x80000000 is an  * unsigned int for 32-bit two's complement ANSI compilers (section 3.1.3.2).  * These numbers are for the default configuration of gcc.  They work for  * some other compilers as well, but this should not be depended on.  */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MAX
value|0x7f
end_define

begin_comment
comment|/* max value for a signed char */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MIN
value|(-0x7f-1)
end_define

begin_comment
comment|/* min value for a signed char */
end_comment

begin_define
define|#
directive|define
name|UCHAR_MAX
value|0xffU
end_define

begin_comment
comment|/* max value for an unsigned char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MAX
value|0x7f
end_define

begin_comment
comment|/* max value for a char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MIN
value|(-0x7f-1)
end_define

begin_comment
comment|/* min value for a char */
end_comment

begin_define
define|#
directive|define
name|USHRT_MAX
value|0xffffU
end_define

begin_comment
comment|/* max value for an unsigned short */
end_comment

begin_define
define|#
directive|define
name|SHRT_MAX
value|0x7fff
end_define

begin_comment
comment|/* max value for a short */
end_comment

begin_define
define|#
directive|define
name|SHRT_MIN
value|(-0x7fff-1)
end_define

begin_comment
comment|/* min value for a short */
end_comment

begin_define
define|#
directive|define
name|UINT_MAX
value|0xffffffffU
end_define

begin_comment
comment|/* max value for an unsigned int */
end_comment

begin_define
define|#
directive|define
name|INT_MAX
value|0x7fffffff
end_define

begin_comment
comment|/* max value for an int */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|(-0x7fffffff-1)
end_define

begin_comment
comment|/* min value for an int */
end_comment

begin_define
define|#
directive|define
name|ULONG_MAX
value|0xffffffffffffffffUL
end_define

begin_comment
comment|/* max for an unsigned long */
end_comment

begin_define
define|#
directive|define
name|LONG_MAX
value|0x7fffffffffffffffL
end_define

begin_comment
comment|/* max for a long */
end_comment

begin_define
define|#
directive|define
name|LONG_MIN
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
name|ULLONG_MAX
value|0xffffffffffffffffULL
end_define

begin_define
define|#
directive|define
name|LLONG_MAX
value|0x7fffffffffffffffLL
end_define

begin_comment
comment|/* max for a long long */
end_comment

begin_define
define|#
directive|define
name|LLONG_MIN
value|(-0x7fffffffffffffffLL-1)
end_define

begin_comment
comment|/* min for a long long */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SSIZE_MAX
value|LONG_MAX
end_define

begin_comment
comment|/* max value for a ssize_t */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_XOPEN_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIZE_T_MAX
value|ULONG_MAX
end_define

begin_comment
comment|/* max value for a size_t */
end_comment

begin_comment
comment|/* Quads and longs are the same on the alpha.  Ensure they stay in sync. */
end_comment

begin_define
define|#
directive|define
name|UQUAD_MAX
value|(ULONG_MAX)
end_define

begin_comment
comment|/* max value for a uquad_t */
end_comment

begin_define
define|#
directive|define
name|QUAD_MAX
value|(LONG_MAX)
end_define

begin_comment
comment|/* max value for a quad_t */
end_comment

begin_define
define|#
directive|define
name|QUAD_MIN
value|(LONG_MIN)
end_define

begin_comment
comment|/* min value for a quad_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE&& !_XOPEN_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|_XOPEN_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|LONG_BIT
value|64
end_define

begin_define
define|#
directive|define
name|WORD_BIT
value|32
end_define

begin_define
define|#
directive|define
name|DBL_DIG
value|15
end_define

begin_define
define|#
directive|define
name|DBL_MAX
value|1.7976931348623157E+308
end_define

begin_define
define|#
directive|define
name|DBL_MIN
value|2.2250738585072014E-308
end_define

begin_define
define|#
directive|define
name|FLT_DIG
value|6
end_define

begin_define
define|#
directive|define
name|FLT_MAX
value|3.40282347E+38F
end_define

begin_define
define|#
directive|define
name|FLT_MIN
value|1.17549435E-38F
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
comment|/* !_MACHINE_LIMITS_H_ */
end_comment

end_unit

