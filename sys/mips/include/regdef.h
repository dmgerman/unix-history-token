begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: regdef.h,v 1.12 2005/12/11 12:18:09 christos Exp $	*/
end_comment

begin_comment
comment|/*  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell. This file is derived from the MIPS RISC  * Architecture book by Gerry Kane.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)regdef.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_REGDEF_H
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_REGDEF_H
end_define

begin_include
include|#
directive|include
file|<machine/cdefs.h>
end_include

begin_comment
comment|/* for API selection */
end_comment

begin_define
define|#
directive|define
name|zero
value|$0
end_define

begin_comment
comment|/* always zero */
end_comment

begin_define
define|#
directive|define
name|AT
value|$at
end_define

begin_comment
comment|/* assembler temporary */
end_comment

begin_define
define|#
directive|define
name|v0
value|$2
end_define

begin_comment
comment|/* return value */
end_comment

begin_define
define|#
directive|define
name|v1
value|$3
end_define

begin_define
define|#
directive|define
name|a0
value|$4
end_define

begin_comment
comment|/* argument registers */
end_comment

begin_define
define|#
directive|define
name|a1
value|$5
end_define

begin_define
define|#
directive|define
name|a2
value|$6
end_define

begin_define
define|#
directive|define
name|a3
value|$7
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|a4
value|$8
end_define

begin_define
define|#
directive|define
name|a5
value|$9
end_define

begin_define
define|#
directive|define
name|a6
value|$10
end_define

begin_define
define|#
directive|define
name|a7
value|$11
end_define

begin_define
define|#
directive|define
name|t0
value|$12
end_define

begin_comment
comment|/* temp registers (not saved across subroutine calls) */
end_comment

begin_define
define|#
directive|define
name|t1
value|$13
end_define

begin_define
define|#
directive|define
name|t2
value|$14
end_define

begin_define
define|#
directive|define
name|t3
value|$15
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|t0
value|$8
end_define

begin_comment
comment|/* temp registers (not saved across subroutine calls) */
end_comment

begin_define
define|#
directive|define
name|t1
value|$9
end_define

begin_define
define|#
directive|define
name|t2
value|$10
end_define

begin_define
define|#
directive|define
name|t3
value|$11
end_define

begin_define
define|#
directive|define
name|t4
value|$12
end_define

begin_define
define|#
directive|define
name|t5
value|$13
end_define

begin_define
define|#
directive|define
name|t6
value|$14
end_define

begin_define
define|#
directive|define
name|t7
value|$15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_n32 || __mips_n64 */
end_comment

begin_define
define|#
directive|define
name|s0
value|$16
end_define

begin_comment
comment|/* saved across subroutine calls (callee saved) */
end_comment

begin_define
define|#
directive|define
name|s1
value|$17
end_define

begin_define
define|#
directive|define
name|s2
value|$18
end_define

begin_define
define|#
directive|define
name|s3
value|$19
end_define

begin_define
define|#
directive|define
name|s4
value|$20
end_define

begin_define
define|#
directive|define
name|s5
value|$21
end_define

begin_define
define|#
directive|define
name|s6
value|$22
end_define

begin_define
define|#
directive|define
name|s7
value|$23
end_define

begin_define
define|#
directive|define
name|t8
value|$24
end_define

begin_comment
comment|/* two more temporary registers */
end_comment

begin_define
define|#
directive|define
name|t9
value|$25
end_define

begin_define
define|#
directive|define
name|k0
value|$26
end_define

begin_comment
comment|/* kernel temporary */
end_comment

begin_define
define|#
directive|define
name|k1
value|$27
end_define

begin_define
define|#
directive|define
name|gp
value|$28
end_define

begin_comment
comment|/* global pointer */
end_comment

begin_define
define|#
directive|define
name|sp
value|$29
end_define

begin_comment
comment|/* stack pointer */
end_comment

begin_define
define|#
directive|define
name|s8
value|$30
end_define

begin_comment
comment|/* one more callee saved */
end_comment

begin_define
define|#
directive|define
name|ra
value|$31
end_define

begin_comment
comment|/* return address */
end_comment

begin_comment
comment|/*  * These are temp registers whose names can be used in either the old  * or new ABI, although they map to different physical registers.  In  * the old ABI, they map to t4-t7, and in the new ABI, they map to a4-a7.  *  * Because they overlap with the last 4 arg regs in the new ABI, ta0-ta3  * should be used only when we need more than t0-t3.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|ta0
value|$8
end_define

begin_define
define|#
directive|define
name|ta1
value|$9
end_define

begin_define
define|#
directive|define
name|ta2
value|$10
end_define

begin_define
define|#
directive|define
name|ta3
value|$11
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ta0
value|$12
end_define

begin_define
define|#
directive|define
name|ta1
value|$13
end_define

begin_define
define|#
directive|define
name|ta2
value|$14
end_define

begin_define
define|#
directive|define
name|ta3
value|$15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_n32 || __mips_n64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_REGDEF_H */
end_comment

end_unit

