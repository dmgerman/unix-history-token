begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LIMITS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LIMITS_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/_limits.h>
end_include

begin_define
define|#
directive|define
name|CHAR_BIT
value|__CHAR_BIT
end_define

begin_comment
comment|/* number of bits in a char */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MAX
value|__SCHAR_MAX
end_define

begin_comment
comment|/* max value for a signed char */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MIN
value|__SCHAR_MIN
end_define

begin_comment
comment|/* min value for a signed char */
end_comment

begin_define
define|#
directive|define
name|UCHAR_MAX
value|__UCHAR_MAX
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

begin_define
define|#
directive|define
name|CHAR_MIN
value|SCHAR_MIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USHRT_MAX
value|__USHRT_MAX
end_define

begin_comment
comment|/* max value for an unsigned short */
end_comment

begin_define
define|#
directive|define
name|SHRT_MAX
value|__SHRT_MAX
end_define

begin_comment
comment|/* max value for a short */
end_comment

begin_define
define|#
directive|define
name|SHRT_MIN
value|__SHRT_MIN
end_define

begin_comment
comment|/* min value for a short */
end_comment

begin_define
define|#
directive|define
name|UINT_MAX
value|__UINT_MAX
end_define

begin_comment
comment|/* max value for an unsigned int */
end_comment

begin_define
define|#
directive|define
name|INT_MAX
value|__INT_MAX
end_define

begin_comment
comment|/* max value for an int */
end_comment

begin_define
define|#
directive|define
name|INT_MIN
value|__INT_MIN
end_define

begin_comment
comment|/* min value for an int */
end_comment

begin_define
define|#
directive|define
name|ULONG_MAX
value|__ULONG_MAX
end_define

begin_comment
comment|/* max for an unsigned long */
end_comment

begin_define
define|#
directive|define
name|LONG_MAX
value|__LONG_MAX
end_define

begin_comment
comment|/* max for a long */
end_comment

begin_define
define|#
directive|define
name|LONG_MIN
value|__LONG_MIN
end_define

begin_comment
comment|/* min for a long */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LONG_LONG_SUPPORTED
end_ifdef

begin_define
define|#
directive|define
name|ULLONG_MAX
value|__ULLONG_MAX
end_define

begin_comment
comment|/* max for an unsigned long long */
end_comment

begin_define
define|#
directive|define
name|LLONG_MAX
value|__LLONG_MAX
end_define

begin_comment
comment|/* max for a long long */
end_comment

begin_define
define|#
directive|define
name|LLONG_MIN
value|__LLONG_MIN
end_define

begin_comment
comment|/* min for a long long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|SSIZE_MAX
value|__SSIZE_MAX
end_define

begin_comment
comment|/* max value for an ssize_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIZE_T_MAX
value|__SIZE_T_MAX
end_define

begin_comment
comment|/* max value for a size_t */
end_comment

begin_define
define|#
directive|define
name|OFF_MAX
value|__OFF_MAX
end_define

begin_comment
comment|/* max value for an off_t */
end_comment

begin_define
define|#
directive|define
name|OFF_MIN
value|__OFF_MIN
end_define

begin_comment
comment|/* min value for an off_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|GID_MAX
value|UINT_MAX
end_define

begin_comment
comment|/* max value for a gid_t */
end_comment

begin_define
define|#
directive|define
name|UID_MAX
value|UINT_MAX
end_define

begin_comment
comment|/* max value for a uid_t */
end_comment

begin_define
define|#
directive|define
name|UQUAD_MAX
value|(__UQUAD_MAX)
end_define

begin_comment
comment|/* max value for a uquad_t */
end_comment

begin_define
define|#
directive|define
name|QUAD_MAX
value|(__QUAD_MAX)
end_define

begin_comment
comment|/* max value for a quad_t */
end_comment

begin_define
define|#
directive|define
name|QUAD_MIN
value|(__QUAD_MIN)
end_define

begin_comment
comment|/* min value for a quad_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|LONG_BIT
value|__LONG_BIT
end_define

begin_define
define|#
directive|define
name|WORD_BIT
value|__WORD_BIT
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
comment|/* !_SYS_LIMITS_H_ */
end_comment

end_unit

