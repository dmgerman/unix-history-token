begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cltp_var.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_CLTP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_CLTP_VAR_H_
end_define

begin_define
define|#
directive|define
name|UD_TPDU_type
value|0x40
end_define

begin_comment
comment|/* packet type */
end_comment

begin_define
define|#
directive|define
name|CLTPOVAL_SRC
value|0xc1
end_define

begin_comment
comment|/* Source TSAP -- required */
end_comment

begin_define
define|#
directive|define
name|CLTPOVAL_DST
value|0xc2
end_define

begin_comment
comment|/* Destination TSAP -- required */
end_comment

begin_define
define|#
directive|define
name|CLTPOVAL_CSM
value|0xc3
end_define

begin_comment
comment|/* Checksum parameter -- optional */
end_comment

begin_struct
struct|struct
name|cltpstat
block|{
name|int
name|cltps_hdrops
decl_stmt|;
name|int
name|cltps_badsum
decl_stmt|;
name|int
name|cltps_badlen
decl_stmt|;
name|int
name|cltps_noport
decl_stmt|;
name|int
name|cltps_ipackets
decl_stmt|;
name|int
name|cltps_opackets
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|isopcb
name|cltb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cltpstat
name|cltpstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

