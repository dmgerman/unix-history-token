begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1996  *	Berkeley Software Design, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Berkeley Software  *	Design, Inc.  *  * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI trap.h,v 2.2 1996/04/08 19:33:09 bostic Exp  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|CLI
value|0xfa
end_define

begin_define
define|#
directive|define
name|STI
value|0xfb
end_define

begin_define
define|#
directive|define
name|PUSHF
value|0x9c
end_define

begin_define
define|#
directive|define
name|POPF
value|0x9d
end_define

begin_define
define|#
directive|define
name|INTn
value|0xcd
end_define

begin_define
define|#
directive|define
name|TRACETRAP
value|0xcc
end_define

begin_define
define|#
directive|define
name|IRET
value|0xcf
end_define

begin_define
define|#
directive|define
name|LOCK
value|0xf0
end_define

begin_define
define|#
directive|define
name|HLT
value|0xf4
end_define

begin_define
define|#
directive|define
name|OPSIZ
value|0x66
end_define

begin_define
define|#
directive|define
name|REPNZ
value|0xf2
end_define

begin_define
define|#
directive|define
name|REPZ
value|0xf3
end_define

begin_define
define|#
directive|define
name|INd
value|0xe4
end_define

begin_define
define|#
directive|define
name|INdX
value|0xe5
end_define

begin_define
define|#
directive|define
name|OUTd
value|0xe6
end_define

begin_define
define|#
directive|define
name|OUTdX
value|0xe7
end_define

begin_define
define|#
directive|define
name|IN
value|0xec
end_define

begin_define
define|#
directive|define
name|INX
value|0xed
end_define

begin_define
define|#
directive|define
name|OUT
value|0xee
end_define

begin_define
define|#
directive|define
name|OUTX
value|0xef
end_define

begin_define
define|#
directive|define
name|INSB
value|0x6c
end_define

begin_define
define|#
directive|define
name|INSW
value|0x6d
end_define

begin_define
define|#
directive|define
name|OUTSB
value|0x6e
end_define

begin_define
define|#
directive|define
name|OUTSW
value|0x6f
end_define

begin_define
define|#
directive|define
name|IOFS
value|0x64
end_define

begin_define
define|#
directive|define
name|IOGS
value|0x65
end_define

begin_define
define|#
directive|define
name|TWOBYTE
value|0x0f
end_define

begin_define
define|#
directive|define
name|LAR
value|0x02
end_define

begin_define
define|#
directive|define
name|AC_P
value|0x8000
end_define

begin_comment
comment|/* Present */
end_comment

begin_define
define|#
directive|define
name|AC_P0
value|0x0000
end_define

begin_comment
comment|/* Priv Level 0 */
end_comment

begin_define
define|#
directive|define
name|AC_P1
value|0x2000
end_define

begin_comment
comment|/* Priv Level 1 */
end_comment

begin_define
define|#
directive|define
name|AC_P2
value|0x4000
end_define

begin_comment
comment|/* Priv Level 2 */
end_comment

begin_define
define|#
directive|define
name|AC_P3
value|0x6000
end_define

begin_comment
comment|/* Priv Level 3 */
end_comment

begin_define
define|#
directive|define
name|AC_S
value|0x1000
end_define

begin_comment
comment|/* Memory Segment */
end_comment

begin_define
define|#
directive|define
name|AC_RO
value|0x0000
end_define

begin_comment
comment|/* Read Only */
end_comment

begin_define
define|#
directive|define
name|AC_RW
value|0x0200
end_define

begin_comment
comment|/* Read Write */
end_comment

begin_define
define|#
directive|define
name|AC_RWE
value|0x0600
end_define

begin_comment
comment|/* Read Write Expand Down */
end_comment

begin_define
define|#
directive|define
name|AC_EX
value|0x0800
end_define

begin_comment
comment|/* Execute Only */
end_comment

begin_define
define|#
directive|define
name|AC_EXR
value|0x0a00
end_define

begin_comment
comment|/* Execute Readable */
end_comment

begin_define
define|#
directive|define
name|AC_EXC
value|0x0c00
end_define

begin_comment
comment|/* Execute Only Conforming */
end_comment

begin_define
define|#
directive|define
name|AC_EXRC
value|0x0e00
end_define

begin_comment
comment|/* Execute Readable Conforming */
end_comment

begin_define
define|#
directive|define
name|AC_A
value|0x0100
end_define

begin_comment
comment|/* Accessed */
end_comment

end_unit

