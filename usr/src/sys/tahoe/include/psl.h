begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)psl.h	7.2 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/*  * TAHOE processor status longword.  */
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
name|PSL_V
value|0x00000002
end_define

begin_comment
comment|/* overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSL_Z
value|0x00000004
end_define

begin_comment
comment|/* zero bit */
end_comment

begin_define
define|#
directive|define
name|PSL_N
value|0x00000008
end_define

begin_comment
comment|/* negative bit */
end_comment

begin_define
define|#
directive|define
name|PSL_ALLCC
value|0x0000000f
end_define

begin_comment
comment|/* all cc bits - unlikely */
end_comment

begin_define
define|#
directive|define
name|PSL_T
value|0x00000010
end_define

begin_comment
comment|/* trace enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_IV
value|0x00000020
end_define

begin_comment
comment|/* integer overflow enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_FU
value|0x00000040
end_define

begin_comment
comment|/* float underflow enable 	*/
end_comment

begin_define
define|#
directive|define
name|PSL_DBL
value|0x00000080
end_define

begin_comment
comment|/* f.p. prescision indicator	*/
end_comment

begin_define
define|#
directive|define
name|PSL_SFE
value|0x00000100
end_define

begin_comment
comment|/* system-forced-exception */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL
value|0x001f0000
end_define

begin_comment
comment|/* interrupt priority level */
end_comment

begin_define
define|#
directive|define
name|PSL_PRVMOD
value|0x00000000
end_define

begin_comment
comment|/* previous mode (kernel mode) */
end_comment

begin_define
define|#
directive|define
name|PSL_CURMOD
value|0x01000000
end_define

begin_comment
comment|/* current mode (all on is user) */
end_comment

begin_define
define|#
directive|define
name|PSL_IS
value|0x04000000
end_define

begin_comment
comment|/* interrupt stack */
end_comment

begin_define
define|#
directive|define
name|PSL_TP
value|0x40000000
end_define

begin_comment
comment|/* trace pending */
end_comment

begin_define
define|#
directive|define
name|PSL_MBZ
value|0xbae0fe00
end_define

begin_comment
comment|/* must be zero bits */
end_comment

begin_define
define|#
directive|define
name|PSL_USERSET
value|(PSL_CURMOD)
end_define

begin_define
define|#
directive|define
name|PSL_USERCLR
value|(PSL_IS|PSL_IPL|PSL_MBZ|PSL_SFE|PSL_DBL|PSL_FU)
end_define

end_unit

