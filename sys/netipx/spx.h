begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1995, Mike Mitchell  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)spx.h  *  * $FreeBSD$  */
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
name|__packed
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
name|__packed
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

begin_comment
comment|/*  * SPX control block, one per connection  */
end_comment

begin_struct
struct|struct
name|spxpcb
block|{
name|struct
name|spx_q
name|s_q
decl_stmt|;
comment|/* queue for out-of-order receipt */
name|struct
name|ipxpcb
modifier|*
name|s_ipxpcb
decl_stmt|;
comment|/* backpointer to internet pcb */
name|u_char
name|s_state
decl_stmt|;
name|u_char
name|s_flags
decl_stmt|;
define|#
directive|define
name|SF_ACKNOW
value|0x01
comment|/* Ack peer immediately */
define|#
directive|define
name|SF_DELACK
value|0x02
comment|/* Ack, but try to delay it */
define|#
directive|define
name|SF_HI
value|0x04
comment|/* Show headers on input */
define|#
directive|define
name|SF_HO
value|0x08
comment|/* Show headers on output */
define|#
directive|define
name|SF_PI
value|0x10
comment|/* Packet (datagram) interface */
define|#
directive|define
name|SF_WIN
value|0x20
comment|/* Window info changed */
define|#
directive|define
name|SF_RXT
value|0x40
comment|/* Rxt info changed */
define|#
directive|define
name|SF_RVD
value|0x80
comment|/* Calling from read usrreq routine */
name|u_short
name|s_mtu
decl_stmt|;
comment|/* Max packet size for this stream */
comment|/* use sequence fields in headers to store sequence numbers for this    connection */
name|struct
name|ipx
modifier|*
name|s_ipx
decl_stmt|;
name|struct
name|spxhdr
name|s_shdr
decl_stmt|;
comment|/* prototype header to transmit */
define|#
directive|define
name|s_cc
value|s_shdr.spx_cc
comment|/* connection control (for EM bit) */
define|#
directive|define
name|s_dt
value|s_shdr.spx_dt
comment|/* datastream type */
define|#
directive|define
name|s_sid
value|s_shdr.spx_sid
comment|/* source connection identifier */
define|#
directive|define
name|s_did
value|s_shdr.spx_did
comment|/* destination connection identifier */
define|#
directive|define
name|s_seq
value|s_shdr.spx_seq
comment|/* sequence number */
define|#
directive|define
name|s_ack
value|s_shdr.spx_ack
comment|/* acknowledge number */
define|#
directive|define
name|s_alo
value|s_shdr.spx_alo
comment|/* allocation number */
define|#
directive|define
name|s_dport
value|s_ipx->ipx_dna.x_port
comment|/* where we are sending */
name|struct
name|spxhdr
name|s_rhdr
decl_stmt|;
comment|/* last received header (in effect!)*/
name|u_short
name|s_rack
decl_stmt|;
comment|/* their acknowledge number */
name|u_short
name|s_ralo
decl_stmt|;
comment|/* their allocation number */
name|u_short
name|s_smax
decl_stmt|;
comment|/* highest packet # we have sent */
name|u_short
name|s_snxt
decl_stmt|;
comment|/* which packet to send next */
comment|/* congestion control */
define|#
directive|define
name|CUNIT
value|1024
comment|/* scaling for ... */
name|int
name|s_cwnd
decl_stmt|;
comment|/* Congestion-controlled window */
comment|/* in packets * CUNIT */
name|short
name|s_swnd
decl_stmt|;
comment|/* == tcp snd_wnd, in packets */
name|short
name|s_smxw
decl_stmt|;
comment|/* == tcp max_sndwnd */
comment|/* difference of two spx_seq's can be 					   no bigger than a short */
name|u_short
name|s_swl1
decl_stmt|;
comment|/* == tcp snd_wl1 */
name|u_short
name|s_swl2
decl_stmt|;
comment|/* == tcp snd_wl2 */
name|int
name|s_cwmx
decl_stmt|;
comment|/* max allowable cwnd */
name|int
name|s_ssthresh
decl_stmt|;
comment|/* s_cwnd size threshold for 					 * slow start exponential-to- 					 * linear switch */
comment|/* transmit timing stuff  * srtt and rttvar are stored as fixed point, for convenience in smoothing.  * srtt has 3 bits to the right of the binary point, rttvar has 2.  */
name|short
name|s_idle
decl_stmt|;
comment|/* time idle */
define|#
directive|define
name|SPXT_NTIMERS
value|4
name|short
name|s_timer
index|[
name|SPXT_NTIMERS
index|]
decl_stmt|;
comment|/* timers */
name|short
name|s_rxtshift
decl_stmt|;
comment|/* log(2) of rexmt exp. backoff */
name|short
name|s_rxtcur
decl_stmt|;
comment|/* current retransmit value */
name|u_short
name|s_rtseq
decl_stmt|;
comment|/* packet being timed */
name|short
name|s_rtt
decl_stmt|;
comment|/* timer for round trips */
name|short
name|s_srtt
decl_stmt|;
comment|/* averaged timer */
name|short
name|s_rttvar
decl_stmt|;
comment|/* variance in round trip time */
name|char
name|s_force
decl_stmt|;
comment|/* which timer expired */
name|char
name|s_dupacks
decl_stmt|;
comment|/* counter to intuit xmt loss */
comment|/* out of band data */
name|char
name|s_oobflags
decl_stmt|;
define|#
directive|define
name|SF_SOOB
value|0x08
comment|/* sending out of band data */
define|#
directive|define
name|SF_IOOB
value|0x10
comment|/* receiving out of band data */
name|char
name|s_iobc
decl_stmt|;
comment|/* input characters */
comment|/* debug stuff */
name|u_short
name|s_want
decl_stmt|;
comment|/* Last candidate for sending */
name|char
name|s_outx
decl_stmt|;
comment|/* exit taken from spx_output */
name|char
name|s_inx
decl_stmt|;
comment|/* exit taken from spx_input */
name|u_short
name|s_flags2
decl_stmt|;
comment|/* more flags for testing */
define|#
directive|define
name|SF_NEWCALL
value|0x100
comment|/* for new_recvmsg */
define|#
directive|define
name|SO_NEWCALL
value|10
comment|/* for new_recvmsg */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ipxtospxpcb
parameter_list|(
name|np
parameter_list|)
value|((struct spxpcb *)(np)->ipxp_pcb)
end_define

begin_define
define|#
directive|define
name|sotospxpcb
parameter_list|(
name|so
parameter_list|)
value|(ipxtospxpcb(sotoipxpcb(so)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|spx_usrreqs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|spx_usrreq_sps
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|spx_ctlinput
parameter_list|(
name|int
name|cmd
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|arg_as_sa
parameter_list|,
name|void
modifier|*
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|spx_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spx_fasttimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spx_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spx_input
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|ipxpcb
modifier|*
name|ipxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spx_slowtimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPX_SPX_H_ */
end_comment

end_unit

