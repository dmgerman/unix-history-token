begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: if_enreg.h,v 4.300 91/06/09 06:25:57 root Rel41 $ SONY  *  *	@(#)if_enreg.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * if_enreg.h for news800, news900  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ENREG__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ENREG__
value|1
end_define

begin_comment
comment|/* command definitions */
end_comment

begin_define
define|#
directive|define
name|ENC_ADDR
value|0x00
end_define

begin_comment
comment|/* Get Ethernet address */
end_comment

begin_define
define|#
directive|define
name|ENC_DIAG
value|0x01
end_define

begin_comment
comment|/* Run On-board Diagnostics */
end_comment

begin_define
define|#
directive|define
name|ENC_START
value|0x02
end_define

begin_comment
comment|/* Go Online */
end_comment

begin_define
define|#
directive|define
name|ENC_RESET
value|0x03
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|ENC_STAT
value|0x04
end_define

begin_comment
comment|/* Report and Reset Statistics */
end_comment

begin_define
define|#
directive|define
name|ENC_XMIT
value|0x05
end_define

begin_comment
comment|/* Load Transmit Data and Send */
end_comment

begin_define
define|#
directive|define
name|ENC_RECV
value|0x06
end_define

begin_comment
comment|/* Receive Data */
end_comment

begin_define
define|#
directive|define
name|ENC_PROM
value|0x07
end_define

begin_comment
comment|/* Set prom mode */
end_comment

begin_define
define|#
directive|define
name|ENC_SADDR
value|0x08
end_define

begin_comment
comment|/* Set Ethernet address */
end_comment

begin_define
define|#
directive|define
name|ENC_NEWIF
value|0x09
end_define

begin_comment
comment|/* Switch driver interface */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__IF_ENREG__ */
end_comment

end_unit

