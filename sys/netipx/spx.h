begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, Mike Mitchell  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)spx.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_SPX_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_SPX_H_
end_define

begin_comment
comment|/*  * Definitions for IPX style Sequenced Packet Protocol  */
end_comment

begin_struct
struct|struct
name|spxhdr
block|{
name|u_char
name|spx_cc
decl_stmt|;
comment|/* connection control */
name|u_char
name|spx_dt
decl_stmt|;
comment|/* datastream type */
define|#
directive|define
name|SPX_SP
value|0x80
comment|/* system packet */
define|#
directive|define
name|SPX_SA
value|0x40
comment|/* send acknowledgement */
define|#
directive|define
name|SPX_OB
value|0x20
comment|/* attention (out of band data) */
define|#
directive|define
name|SPX_EM
value|0x10
comment|/* end of message */
name|u_short
name|spx_sid
decl_stmt|;
comment|/* source connection identifier */
name|u_short
name|spx_did
decl_stmt|;
comment|/* destination connection identifier */
name|u_short
name|spx_seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|spx_ack
decl_stmt|;
comment|/* acknowledge number */
name|u_short
name|spx_alo
decl_stmt|;
comment|/* allocation number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for NS(tm) Internet Datagram Protocol  * containing a Sequenced Packet Protocol packet.  */
end_comment

begin_struct
struct|struct
name|spx
block|{
name|struct
name|ipx
name|si_i
decl_stmt|;
name|struct
name|spxhdr
name|si_s
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|spx_q
block|{
name|struct
name|spx_q
modifier|*
name|si_next
decl_stmt|;
name|struct
name|spx_q
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
value|((struct spx *)x)
end_define

begin_define
define|#
directive|define
name|si_sum
value|si_i.ipx_sum
end_define

begin_define
define|#
directive|define
name|si_len
value|si_i.ipx_len
end_define

begin_define
define|#
directive|define
name|si_tc
value|si_i.ipx_tc
end_define

begin_define
define|#
directive|define
name|si_pt
value|si_i.ipx_pt
end_define

begin_define
define|#
directive|define
name|si_dna
value|si_i.ipx_dna
end_define

begin_define
define|#
directive|define
name|si_sna
value|si_i.ipx_sna
end_define

begin_define
define|#
directive|define
name|si_sport
value|si_i.ipx_sna.x_port
end_define

begin_define
define|#
directive|define
name|si_cc
value|si_s.spx_cc
end_define

begin_define
define|#
directive|define
name|si_dt
value|si_s.spx_dt
end_define

begin_define
define|#
directive|define
name|si_sid
value|si_s.spx_sid
end_define

begin_define
define|#
directive|define
name|si_did
value|si_s.spx_did
end_define

begin_define
define|#
directive|define
name|si_seq
value|si_s.spx_seq
end_define

begin_define
define|#
directive|define
name|si_ack
value|si_s.spx_ack
end_define

begin_define
define|#
directive|define
name|si_alo
value|si_s.spx_alo
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|spx_reass
argument_list|()
decl_stmt|,
name|spx_output
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spx_usrreq
argument_list|()
decl_stmt|,
name|spx_usrreq_sp
argument_list|()
decl_stmt|,
name|spx_ctloutput
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spx_input
argument_list|()
decl_stmt|,
name|spx_ctlinput
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spx_init
argument_list|()
decl_stmt|,
name|spx_fasttimo
argument_list|()
decl_stmt|,
name|spx_slowtimo
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spx_quench
argument_list|()
decl_stmt|,
name|spx_setpersist
argument_list|()
decl_stmt|,
name|spx_template
argument_list|()
decl_stmt|,
name|spx_abort
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|spxpcb
modifier|*
name|spx_close
argument_list|()
decl_stmt|,
modifier|*
name|spx_usrclosed
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|spxpcb
modifier|*
name|spx_disconnect
argument_list|()
decl_stmt|,
modifier|*
name|spx_drop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|spxpcb
modifier|*
name|spx_timers
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

