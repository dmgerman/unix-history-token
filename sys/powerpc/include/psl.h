begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: psl.h,v 1.5 2000/11/19 19:52:37 matt Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PSL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PSL_H_
end_define

begin_comment
comment|/*  * Machine State Register (MSR)  *  * The PowerPC 601 does not implement the following bits:  *  *	VEC, POW, ILE, BE, RI, LE[*]  *  * [*] Little-endian mode on the 601 is implemented in the HID0 register.  */
end_comment

begin_define
define|#
directive|define
name|PSL_VEC
value|0x02000000
end_define

begin_comment
comment|/* AltiVec vector unit available */
end_comment

begin_define
define|#
directive|define
name|PSL_POW
value|0x00040000
end_define

begin_comment
comment|/* power management */
end_comment

begin_define
define|#
directive|define
name|PSL_ILE
value|0x00010000
end_define

begin_comment
comment|/* interrupt endian mode (1 == le) */
end_comment

begin_define
define|#
directive|define
name|PSL_EE
value|0x00008000
end_define

begin_comment
comment|/* external interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PSL_PR
value|0x00004000
end_define

begin_comment
comment|/* privilege mode (1 == user) */
end_comment

begin_define
define|#
directive|define
name|PSL_FP
value|0x00002000
end_define

begin_comment
comment|/* floating point enable */
end_comment

begin_define
define|#
directive|define
name|PSL_ME
value|0x00001000
end_define

begin_comment
comment|/* machine check enable */
end_comment

begin_define
define|#
directive|define
name|PSL_FE0
value|0x00000800
end_define

begin_comment
comment|/* floating point interrupt mode 0 */
end_comment

begin_define
define|#
directive|define
name|PSL_SE
value|0x00000400
end_define

begin_comment
comment|/* single-step trace enable */
end_comment

begin_define
define|#
directive|define
name|PSL_BE
value|0x00000200
end_define

begin_comment
comment|/* branch trace enable */
end_comment

begin_define
define|#
directive|define
name|PSL_FE1
value|0x00000100
end_define

begin_comment
comment|/* floating point interrupt mode 1 */
end_comment

begin_define
define|#
directive|define
name|PSL_IP
value|0x00000040
end_define

begin_comment
comment|/* interrupt prefix */
end_comment

begin_define
define|#
directive|define
name|PSL_IR
value|0x00000020
end_define

begin_comment
comment|/* instruction address relocation */
end_comment

begin_define
define|#
directive|define
name|PSL_DR
value|0x00000010
end_define

begin_comment
comment|/* data address relocation */
end_comment

begin_define
define|#
directive|define
name|PSL_RI
value|0x00000002
end_define

begin_comment
comment|/* recoverable interrupt */
end_comment

begin_define
define|#
directive|define
name|PSL_LE
value|0x00000001
end_define

begin_comment
comment|/* endian mode (1 == le) */
end_comment

begin_define
define|#
directive|define
name|PSL_601_MASK
value|~(PSL_POW|PSL_ILE|PSL_BE|PSL_RI|PSL_LE)
end_define

begin_comment
comment|/*  * Floating-point exception modes:  */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_DIS
value|0
end_define

begin_comment
comment|/* none */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_NONREC
value|PSL_FE1
end_define

begin_comment
comment|/* imprecise non-recoverable */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_REC
value|PSL_FE0
end_define

begin_comment
comment|/* imprecise recoverable */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_PREC
value|(PSL_FE0 | PSL_FE1)
end_define

begin_comment
comment|/* precise */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_DFLT
value|PSL_FE_DIS
end_define

begin_comment
comment|/* default == none */
end_comment

begin_comment
comment|/*  * Note that PSL_POW and PSL_ILE are not in the saved copy of the MSR  */
end_comment

begin_define
define|#
directive|define
name|PSL_MBO
value|0
end_define

begin_define
define|#
directive|define
name|PSL_MBZ
value|0
end_define

begin_define
define|#
directive|define
name|PSL_KERNSET
value|(PSL_EE | PSL_ME | PSL_IR | PSL_DR | PSL_RI)
end_define

begin_define
define|#
directive|define
name|PSL_USERSET
value|(PSL_KERNSET | PSL_PR)
end_define

begin_define
define|#
directive|define
name|PSL_USERSTATIC
value|(PSL_USERSET | PSL_IP | 0x87c0008c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PSL_H_ */
end_comment

end_unit

