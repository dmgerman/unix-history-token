begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)psl.h	5.2 (Berkeley) 1/18/91  * $FreeBSD$  */
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
comment|/*  * 386 processor status longword.  */
end_comment

begin_define
define|#
directive|define
name|PSL_C
value|0x00000001
end_define

begin_comment
comment|/* carry bit */
end_comment

begin_define
define|#
directive|define
name|PSL_PF
value|0x00000004
end_define

begin_comment
comment|/* parity bit */
end_comment

begin_define
define|#
directive|define
name|PSL_AF
value|0x00000010
end_define

begin_comment
comment|/* bcd carry bit */
end_comment

begin_define
define|#
directive|define
name|PSL_Z
value|0x00000040
end_define

begin_comment
comment|/* zero bit */
end_comment

begin_define
define|#
directive|define
name|PSL_N
value|0x00000080
end_define

begin_comment
comment|/* negative bit */
end_comment

begin_define
define|#
directive|define
name|PSL_T
value|0x00000100
end_define

begin_comment
comment|/* trace enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_I
value|0x00000200
end_define

begin_comment
comment|/* interrupt enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_D
value|0x00000400
end_define

begin_comment
comment|/* string instruction direction bit */
end_comment

begin_define
define|#
directive|define
name|PSL_V
value|0x00000800
end_define

begin_comment
comment|/* overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSL_IOPL
value|0x00003000
end_define

begin_comment
comment|/* i/o privilege level */
end_comment

begin_define
define|#
directive|define
name|PSL_NT
value|0x00004000
end_define

begin_comment
comment|/* nested task bit */
end_comment

begin_define
define|#
directive|define
name|PSL_RF
value|0x00010000
end_define

begin_comment
comment|/* resume flag bit */
end_comment

begin_define
define|#
directive|define
name|PSL_VM
value|0x00020000
end_define

begin_comment
comment|/* virtual 8086 mode bit */
end_comment

begin_define
define|#
directive|define
name|PSL_AC
value|0x00040000
end_define

begin_comment
comment|/* alignment checking */
end_comment

begin_define
define|#
directive|define
name|PSL_VIF
value|0x00080000
end_define

begin_comment
comment|/* virtual interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PSL_VIP
value|0x00100000
end_define

begin_comment
comment|/* virtual interrupt pending */
end_comment

begin_define
define|#
directive|define
name|PSL_ID
value|0x00200000
end_define

begin_comment
comment|/* identification bit */
end_comment

begin_comment
comment|/*  * The i486 manual says that we are not supposed to change reserved flags,  * but this is too much trouble since the reserved flags depend on the cpu  * and setting them to their historical values works in practice.  */
end_comment

begin_define
define|#
directive|define
name|PSL_RESERVED_DEFAULT
value|0x00000002
end_define

begin_comment
comment|/*  * Initial flags for kernel and user mode.  The kernel later inherits  * PSL_I and some other flags from user mode.  */
end_comment

begin_define
define|#
directive|define
name|PSL_KERNEL
value|PSL_RESERVED_DEFAULT
end_define

begin_define
define|#
directive|define
name|PSL_USER
value|(PSL_RESERVED_DEFAULT | PSL_I)
end_define

begin_comment
comment|/*  * Bits that can be changed in user mode on 486's.  We allow these bits  * to be changed using ptrace(), sigreturn() and procfs.  Setting PS_NT  * is undesirable but it may as well be allowed since users can inflict  * it on the kernel directly.  Changes to PSL_AC are silently ignored on  * 386's.  */
end_comment

begin_define
define|#
directive|define
name|PSL_USERCHANGE
value|(PSL_C | PSL_PF | PSL_AF | PSL_Z | PSL_N | PSL_T \ 			| PSL_D | PSL_V | PSL_NT | PSL_AC | PSL_ID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PSL_H_ */
end_comment

end_unit

