begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: rsreg.h,v 4.300 91/06/09 06:43:04 root Rel41 $ SONY  *  *	@(#)rsreg.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RSREG__
end_ifndef

begin_define
define|#
directive|define
name|__RSREG__
value|1
end_define

begin_comment
comment|/* bits in dm lsr, copied from dh.c */
end_comment

begin_define
define|#
directive|define
name|DML_USR
value|0001000
end_define

begin_comment
comment|/* usr modem sig, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DML_DSR
value|0000400
end_define

begin_comment
comment|/* data set ready, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DML_RNG
value|0000200
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DML_CAR
value|0000100
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DML_CTS
value|0000040
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DML_SR
value|0000020
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DML_ST
value|0000010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|DML_RTS
value|0000004
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DML_DTR
value|0000002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DML_LE
value|0000001
end_define

begin_comment
comment|/* line enable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__RSREG__ */
end_comment

end_unit

