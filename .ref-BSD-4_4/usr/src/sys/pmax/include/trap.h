begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: trap.h 1.1 90/07/09$  *  *	@(#)trap.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Trap codes  * also known in trap.c for name strings  */
end_comment

begin_define
define|#
directive|define
name|T_INT
value|0
end_define

begin_comment
comment|/* Interrupt pending */
end_comment

begin_define
define|#
directive|define
name|T_TLB_MOD
value|1
end_define

begin_comment
comment|/* TLB modified fault */
end_comment

begin_define
define|#
directive|define
name|T_TLB_LD_MISS
value|2
end_define

begin_comment
comment|/* TLB miss on load or ifetch */
end_comment

begin_define
define|#
directive|define
name|T_TLB_ST_MISS
value|3
end_define

begin_comment
comment|/* TLB miss on a store */
end_comment

begin_define
define|#
directive|define
name|T_ADDR_ERR_LD
value|4
end_define

begin_comment
comment|/* Address error on a load or ifetch */
end_comment

begin_define
define|#
directive|define
name|T_ADDR_ERR_ST
value|5
end_define

begin_comment
comment|/* Address error on a store */
end_comment

begin_define
define|#
directive|define
name|T_BUS_ERR_IFETCH
value|6
end_define

begin_comment
comment|/* Bus error on an ifetch */
end_comment

begin_define
define|#
directive|define
name|T_BUS_ERR_LD_ST
value|7
end_define

begin_comment
comment|/* Bus error on a load or store */
end_comment

begin_define
define|#
directive|define
name|T_SYSCALL
value|8
end_define

begin_comment
comment|/* System call */
end_comment

begin_define
define|#
directive|define
name|T_BREAK
value|9
end_define

begin_comment
comment|/* Breakpoint */
end_comment

begin_define
define|#
directive|define
name|T_RES_INST
value|10
end_define

begin_comment
comment|/* Reserved instruction exception */
end_comment

begin_define
define|#
directive|define
name|T_COP_UNUSABLE
value|11
end_define

begin_comment
comment|/* Coprocessor unusable */
end_comment

begin_define
define|#
directive|define
name|T_OVFLOW
value|12
end_define

begin_comment
comment|/* Arithmetic overflow */
end_comment

begin_define
define|#
directive|define
name|T_USER
value|0x10
end_define

begin_comment
comment|/* user-mode flag or'ed with type */
end_comment

end_unit

