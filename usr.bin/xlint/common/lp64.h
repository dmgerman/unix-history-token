begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lp64.h,v 1.1 2002/01/18 20:39:23 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Type sizes for LP64 platforms (long, pointer: 64-bit)  */
end_comment

begin_define
define|#
directive|define
name|CHAR_SIZE
value|(CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|SHORT_SIZE
value|(2 * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|INT_SIZE
value|(4 * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|LONG_SIZE
value|(8 * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|QUAD_SIZE
value|(8 * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|PTR_SIZE
value|(8 * CHAR_BIT)
end_define

begin_define
define|#
directive|define
name|TARG_INT_MAX
value|((int32_t) (((uint32_t) -1)>> 1))
end_define

begin_define
define|#
directive|define
name|TARG_INT_MIN
value|((-TARG_INT_MAX) - 1)
end_define

begin_define
define|#
directive|define
name|TARG_UINT_MAX
value|((uint32_t) -1)
end_define

begin_define
define|#
directive|define
name|TARG_QUAD_MAX
value|((int64_t) (((uint64_t) -1)>> 1))
end_define

begin_define
define|#
directive|define
name|TARG_QUAD_MIN
value|((-TARG_QUAD_MAX) - 1)
end_define

begin_define
define|#
directive|define
name|TARG_UQUAD_MAX
value|((uint64_t) -1)
end_define

begin_define
define|#
directive|define
name|TARG_LONG_MAX
value|TARG_QUAD_MAX
end_define

begin_define
define|#
directive|define
name|TARG_LONG_MIN
value|TARG_QUAD_MIN
end_define

begin_define
define|#
directive|define
name|TARG_ULONG_MAX
value|TARG_UQUAD_MAX
end_define

end_unit

