begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)limits.h	7.2 (Berkeley) 6/28/90  *	$Id: limits.h,v 1.5 1994/02/26 00:56:02 ache Exp $  */
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
value|1
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
comment|/* allow 21-bit UTF2 */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MIN
value|(-0x7f-1)
end_define

begin_comment
comment|/* max value for a signed char */
end_comment

begin_define
define|#
directive|define
name|SCHAR_MAX
value|0x7f
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
value|(-0x7fff-1)
end_define

begin_comment
comment|/* min value for a short */
end_comment

begin_define
define|#
directive|define
name|UINT_MAX
value|0xffffffff
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
value|0xffffffff
end_define

begin_comment
comment|/* max value for an unsigned long */
end_comment

begin_define
define|#
directive|define
name|LONG_MAX
value|0x7fffffff
end_define

begin_comment
comment|/* max value for a long */
end_comment

begin_define
define|#
directive|define
name|LONG_MIN
value|(-0x7fffffff-1)
end_define

begin_comment
comment|/* min value for a long */
end_comment

begin_if
if|#
directive|if
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
end_if

begin_define
define|#
directive|define
name|CLK_TCK
value|128
end_define

begin_comment
comment|/* ticks per second */
end_comment

begin_define
define|#
directive|define
name|UQUAD_MAX
value|0xffffffffffffffffLL
end_define

begin_comment
comment|/* max unsigned quad */
end_comment

begin_define
define|#
directive|define
name|QUAD_MAX
value|0x7fffffffffffffffLL
end_define

begin_comment
comment|/* max signed quad */
end_comment

begin_define
define|#
directive|define
name|QUAD_MIN
value|(-0x7fffffffffffffffLL-1)
end_define

begin_comment
comment|/* min signed quad */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_LIMITS_H_ */
end_comment

end_unit

