begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: sccparam.h,v 4.300 91/06/09 06:44:57 root Rel41 $ SONY  *  *	@(#)sccparam.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  *	SCC channel parameter  */
end_comment

begin_define
define|#
directive|define
name|BAUD_RATE
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|RXE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TXE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CHAR_SIZE
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|C5BIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|C7BIT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|C6BIT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|C8BIT
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|PARITY
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EVEN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ODD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|STOPBIT
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|STOP1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|STOP1_5
value|0x00000800
end_define

begin_define
define|#
directive|define
name|STOP2
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|RTS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DTR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|XBREAK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NOCHECK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DCD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CTS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RI
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DSR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RBREAK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SCC_PARITY_ERROR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|OVERRUN_ERROR
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FRAMING_ERROR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AUTO_ENABLE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EXTCLK_ENABLE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TERM_MODE
value|0x70000000
end_define

begin_define
define|#
directive|define
name|CJIS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CSJIS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CEUC
value|0x40000000
end_define

end_unit

