begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)limits.h	8.3 (Berkeley) 1/4/94  * $FreeBSD$  */
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
value|(-0x7f - 1)
end_define

begin_comment
comment|/* min value for a signed char */
end_comment

begin_define
define|#
directive|define
name|UCHAR_MAX
value|0xff
end_define

begin_comment
comment|/* max value for an unsigned char */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CHAR_UNSIGNED__
end_ifdef

begin_define
define|#
directive|define
name|CHAR_MAX
value|UCHAR_MAX
end_define

begin_comment
comment|/* max value for a char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MIN
value|0
end_define

begin_comment
comment|/* min value for a char */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAR_MAX
value|SCHAR_MAX
end_define

begin_comment
comment|/* max value for a char */
end_comment

begin_define
define|#
directive|define
name|CHAR_MIN
value|SCHAR_MIN
end_define

begin_comment
comment|/* min value for a char */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USHRT_MAX
value|0xffff
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
value|(-0x7fff - 1)
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
name|ULONG_MAX
value|0xffffffffffffffffUL
end_define

begin_define
define|#
directive|define
name|LONG_MAX
value|0x7fffffffffffffffL
end_define

begin_define
define|#
directive|define
name|LONG_MIN
value|(-0x7fffffffffffffffL - 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ULONG_MAX
value|0xffffffffUL
end_define

begin_comment
comment|/* max value for an unsigned long */
end_comment

begin_define
define|#
directive|define
name|LONG_MAX
value|0x7fffffffL
end_define

begin_comment
comment|/* max value for a long */
end_comment

begin_define
define|#
directive|define
name|LONG_MIN
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
comment|/* max value for a long long */
end_comment

begin_define
define|#
directive|define
name|LLONG_MIN
value|(-0x7fffffffffffffffLL - 1)
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
value|INT_MAX
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
end_if

begin_define
define|#
directive|define
name|SIZE_T_MAX
value|UINT_MAX
end_define

begin_comment
comment|/* max value for a size_t */
end_comment

begin_comment
comment|/* Quads and long longs are the same size.  Ensure they stay in sync. */
end_comment

begin_define
define|#
directive|define
name|UQUAD_MAX
value|ULLONG_MAX
end_define

begin_comment
comment|/* max value for a uquad_t */
end_comment

begin_define
define|#
directive|define
name|QUAD_MAX
value|LLONG_MAX
end_define

begin_comment
comment|/* max value for a quad_t */
end_comment

begin_define
define|#
directive|define
name|QUAD_MIN
value|LLONG_MIN
end_define

begin_comment
comment|/* min value for a quad_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_LIMITS_H_ */
end_comment

end_unit

