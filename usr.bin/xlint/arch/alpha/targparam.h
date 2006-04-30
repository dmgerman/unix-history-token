begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: targparam.h,v 1.1 2002/01/18 20:39:18 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Machine-dependent target parameters for lint1.  */
end_comment

begin_include
include|#
directive|include
file|"lp64.h"
end_include

begin_comment
comment|/*      * Should be set to 1 if the difference of two pointers is of type long  * or the value of sizeof is of type unsigned long.  Note this MUST be  * kept in sync with the compiler!  */
end_comment

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|1
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|1
end_define

begin_define
define|#
directive|define
name|FLOAT_SIZE
value|(4 * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|DOUBLE_SIZE
value|(8 * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|LDOUBLE_SIZE
value|(8 * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|ENUM_SIZE
value|(4 * CHAR_BIT)
end_define

end_unit

