begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University,  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pmaxtype.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Mother board type byte of "systype" environment variable.  */
end_comment

begin_define
define|#
directive|define
name|DS_PMAX
value|0x1
end_define

begin_comment
comment|/* DECstation 2100/3100 */
end_comment

begin_define
define|#
directive|define
name|DS_3MAX
value|0x2
end_define

begin_comment
comment|/* DECstation 5000/200 */
end_comment

begin_define
define|#
directive|define
name|DS_3MIN
value|0x3
end_define

begin_comment
comment|/* DECstation 5000/1xx */
end_comment

begin_define
define|#
directive|define
name|DS_LSIS
value|0x5
end_define

begin_comment
comment|/* DECsystem 5800 */
end_comment

begin_define
define|#
directive|define
name|DS_MIPSFAIR
value|0x6
end_define

begin_comment
comment|/* DECsystem 5400 */
end_comment

begin_define
define|#
directive|define
name|DS_MAXINE
value|0x7
end_define

begin_comment
comment|/* Personal DECstation 5000/xx */
end_comment

begin_define
define|#
directive|define
name|DS_3MAXPLUS
value|0x8
end_define

begin_comment
comment|/* DECstation 5000/240 (JUST A GUESS) */
end_comment

begin_define
define|#
directive|define
name|DS_MIPSFAIR2
value|0xb
end_define

begin_comment
comment|/* DECsystem 5500 */
end_comment

begin_define
define|#
directive|define
name|DS_MIPSMATE
value|0xc
end_define

begin_comment
comment|/* DECsystem 5100 */
end_comment

end_unit

