begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dbg.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * Screen debug flags  */
end_comment

begin_define
define|#
directive|define
name|DPAUSE
value|0x0001
end_define

begin_comment
comment|/* wait for key press */
end_comment

begin_define
define|#
directive|define
name|DALLTRAPS
value|0x0002
end_define

begin_comment
comment|/* print on alltraps */
end_comment

begin_define
define|#
directive|define
name|DALLSYSC
value|0x0004
end_define

begin_comment
comment|/* print on allsystem calls */
end_comment

begin_define
define|#
directive|define
name|DSYSFAIL
value|0x0008
end_define

begin_comment
comment|/* print on system call failures */
end_comment

begin_define
define|#
directive|define
name|DPAGIN
value|0x0010
end_define

begin_comment
comment|/* print on pagin activity */
end_comment

begin_define
define|#
directive|define
name|DEXEC
value|0x0020
end_define

begin_comment
comment|/* print on exec activity */
end_comment

begin_define
define|#
directive|define
name|DNAMEI
value|0x0040
end_define

begin_comment
comment|/* print on namei activity */
end_comment

begin_define
define|#
directive|define
name|DEXPAND
value|0x0080
end_define

begin_comment
comment|/* print on segment expand activity */
end_comment

begin_define
define|#
directive|define
name|DCLK
value|0x0100
end_define

begin_comment
comment|/* print on clock activity */
end_comment

begin_define
define|#
directive|define
name|DDSK
value|0x0200
end_define

begin_comment
comment|/* print on disk activity */
end_comment

begin_define
define|#
directive|define
name|DSIGNAL
value|0x0400
end_define

begin_comment
comment|/* print on signal delivery */
end_comment

end_unit

