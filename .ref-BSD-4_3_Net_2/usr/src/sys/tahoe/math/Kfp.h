begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)Kfp.h	7.1 (Berkeley) 12/6/90  */
end_comment

begin_comment
comment|/*  * Opcodes to be emulated by kernel software.  */
end_comment

begin_define
define|#
directive|define
name|CVLF
value|0x76
end_define

begin_define
define|#
directive|define
name|CVLD
value|0x77
end_define

begin_define
define|#
directive|define
name|CVFL
value|0x86
end_define

begin_define
define|#
directive|define
name|CVDL
value|0x87
end_define

begin_define
define|#
directive|define
name|LDFD
value|0x97
end_define

begin_define
define|#
directive|define
name|CVDF
value|0xa6
end_define

begin_define
define|#
directive|define
name|ADDF
value|0xc6
end_define

begin_define
define|#
directive|define
name|ADDD
value|0xc7
end_define

begin_define
define|#
directive|define
name|SUBF
value|0xd6
end_define

begin_define
define|#
directive|define
name|SUBD
value|0xd7
end_define

begin_define
define|#
directive|define
name|MULF
value|0xe6
end_define

begin_define
define|#
directive|define
name|MULD
value|0xe7
end_define

begin_define
define|#
directive|define
name|DIVF
value|0xf6
end_define

begin_define
define|#
directive|define
name|DIVD
value|0xf7
end_define

begin_define
define|#
directive|define
name|SINF
value|0x05
end_define

begin_define
define|#
directive|define
name|COSF
value|0x15
end_define

begin_define
define|#
directive|define
name|ATANF
value|0x25
end_define

begin_define
define|#
directive|define
name|LOGF
value|0x35
end_define

begin_define
define|#
directive|define
name|SQRTF
value|0x45
end_define

begin_define
define|#
directive|define
name|EXPF
value|0x55
end_define

begin_comment
comment|/* HFS bits:	*/
end_comment

begin_define
define|#
directive|define
name|HFS_UNDF
value|0x008
end_define

begin_comment
comment|/* float underflow */
end_comment

begin_define
define|#
directive|define
name|HFS_OVF
value|0x004
end_define

begin_comment
comment|/* float overflow */
end_comment

begin_define
define|#
directive|define
name|HFS_RANGE
value|0x8000
end_define

begin_comment
comment|/* set u_error to ERANGE */
end_comment

begin_define
define|#
directive|define
name|HFS_DOM
value|0x4000
end_define

begin_comment
comment|/* set u_error to EDOM */
end_comment

begin_define
define|#
directive|define
name|HFS_DIVZ
value|0x2000
end_define

begin_comment
comment|/* divide by zero flag */
end_comment

begin_comment
comment|/* destination types for the f.p. opcodes:	*/
end_comment

begin_define
define|#
directive|define
name|LONG
value|01
end_define

begin_define
define|#
directive|define
name|FLOAT
value|02
end_define

begin_define
define|#
directive|define
name|DOUBLE
value|03
end_define

begin_comment
comment|/* exceptions:	*/
end_comment

begin_define
define|#
directive|define
name|OVF_EXC
value|0x003
end_define

begin_comment
comment|/* floating overflow */
end_comment

begin_define
define|#
directive|define
name|UNDF_EXC
value|0x004
end_define

begin_comment
comment|/* floating underflow */
end_comment

begin_define
define|#
directive|define
name|DIV0_EXC
value|0x005
end_define

begin_comment
comment|/* floating divide by 0 */
end_comment

end_unit

