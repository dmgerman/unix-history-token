begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)spidp.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNS_SPIDP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNS_SPIDP_H_
end_define

begin_comment
comment|/*  * Definitions for NS(tm) Internet Datagram Protocol  * containing a Sequenced Packet Protocol packet.  */
end_comment

begin_struct
struct|struct
name|spidp
block|{
name|struct
name|idp
name|si_i
decl_stmt|;
name|struct
name|sphdr
name|si_s
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|spidp_q
block|{
name|struct
name|spidp_q
modifier|*
name|si_next
decl_stmt|;
name|struct
name|spidp_q
modifier|*
name|si_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SI
parameter_list|(
name|x
parameter_list|)
value|((struct spidp *)x)
end_define

begin_define
define|#
directive|define
name|si_sum
value|si_i.idp_sum
end_define

begin_define
define|#
directive|define
name|si_len
value|si_i.idp_len
end_define

begin_define
define|#
directive|define
name|si_tc
value|si_i.idp_tc
end_define

begin_define
define|#
directive|define
name|si_pt
value|si_i.idp_pt
end_define

begin_define
define|#
directive|define
name|si_dna
value|si_i.idp_dna
end_define

begin_define
define|#
directive|define
name|si_sna
value|si_i.idp_sna
end_define

begin_define
define|#
directive|define
name|si_sport
value|si_i.idp_sna.x_port
end_define

begin_define
define|#
directive|define
name|si_cc
value|si_s.sp_cc
end_define

begin_define
define|#
directive|define
name|si_dt
value|si_s.sp_dt
end_define

begin_define
define|#
directive|define
name|si_sid
value|si_s.sp_sid
end_define

begin_define
define|#
directive|define
name|si_did
value|si_s.sp_did
end_define

begin_define
define|#
directive|define
name|si_seq
value|si_s.sp_seq
end_define

begin_define
define|#
directive|define
name|si_ack
value|si_s.sp_ack
end_define

begin_define
define|#
directive|define
name|si_alo
value|si_s.sp_alo
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

