begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)preset.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * preset.h -- preset infomation  *   by A.Fujita, Dec-12-1992  */
end_comment

begin_comment
comment|/*  * DIP SW-1  */
end_comment

begin_define
define|#
directive|define
name|PS_AUTOBOOT
value|0x01
end_define

begin_comment
comment|/* 1: PROM auto-boot */
end_comment

begin_define
define|#
directive|define
name|PS_BMC_CONS
value|0x02
end_define

begin_comment
comment|/* 2: use bitmap display as console */
end_comment

begin_define
define|#
directive|define
name|PS_BW_DISP
value|0x04
end_define

begin_comment
comment|/* 3: use B&W display (unused) */
end_comment

begin_comment
comment|/* 4: HD write verify (???) */
end_comment

begin_define
define|#
directive|define
name|PS_COFF
value|0x10
end_define

begin_comment
comment|/* 5: boot COFF format kernel */
end_comment

begin_define
define|#
directive|define
name|PS_PLAIN
value|0x20
end_define

begin_comment
comment|/* 6: number of bitmap plain (unused) */
end_comment

begin_comment
comment|/* NOTE: it has 4 plain, if turn it on, else 1 */
end_comment

begin_comment
comment|/* 7: boot device (unused) */
end_comment

begin_comment
comment|/* NOTE: it should be net-booting, if turn it on */
end_comment

begin_comment
comment|/* 8: load diagnostic program (unused) */
end_comment

end_unit

