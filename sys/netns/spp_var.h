begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)spp_var.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNS_SPP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNS_SPP_VAR_H_
end_define

begin_comment
comment|/*  * Sp control block, one per connection  */
end_comment

begin_struct
struct|struct
name|sppcb
block|{
name|struct
name|spidp_q
name|s_q
decl_stmt|;
comment|/* queue for out-of-order receipt */
name|struct
name|nspcb
modifier|*
name|s_nspcb
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
name|idp
modifier|*
name|s_idp
decl_stmt|;
name|struct
name|sphdr
name|s_shdr
decl_stmt|;
comment|/* prototype header to transmit */
define|#
directive|define
name|s_cc
value|s_shdr.sp_cc
comment|/* connection control (for EM bit) */
define|#
directive|define
name|s_dt
value|s_shdr.sp_dt
comment|/* datastream type */
define|#
directive|define
name|s_sid
value|s_shdr.sp_sid
comment|/* source connection identifier */
define|#
directive|define
name|s_did
value|s_shdr.sp_did
comment|/* destination connection identifier */
define|#
directive|define
name|s_seq
value|s_shdr.sp_seq
comment|/* sequence number */
define|#
directive|define
name|s_ack
value|s_shdr.sp_ack
comment|/* acknowledge number */
define|#
directive|define
name|s_alo
value|s_shdr.sp_alo
comment|/* allocation number */
define|#
directive|define
name|s_dport
value|s_idp->idp_dna.x_port
comment|/* where we are sending */
name|struct
name|sphdr
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
comment|/* difference of two spp_seq's can be 					   no bigger than a short */
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
comment|/* s_cwnd size threshhold for 					 * slow start exponential-to- 					 * linear switch */
comment|/* transmit timing stuff  * srtt and rttvar are stored as fixed point, for convenience in smoothing.  * srtt has 3 bits to the right of the binary point, rttvar has 2.  */
name|short
name|s_idle
decl_stmt|;
comment|/* time idle */
name|short
name|s_timer
index|[
name|SPPT_NTIMERS
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
comment|/* exit taken from spp_output */
name|char
name|s_inx
decl_stmt|;
comment|/* exit taken from spp_input */
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
name|nstosppcb
parameter_list|(
name|np
parameter_list|)
value|((struct sppcb *)(np)->nsp_pcb)
end_define

begin_define
define|#
directive|define
name|sotosppcb
parameter_list|(
name|so
parameter_list|)
value|(nstosppcb(sotonspcb(so)))
end_define

begin_struct
struct|struct
name|sppstat
block|{
name|long
name|spps_connattempt
decl_stmt|;
comment|/* connections initiated */
name|long
name|spps_accepts
decl_stmt|;
comment|/* connections accepted */
name|long
name|spps_connects
decl_stmt|;
comment|/* connections established */
name|long
name|spps_drops
decl_stmt|;
comment|/* connections dropped */
name|long
name|spps_conndrops
decl_stmt|;
comment|/* embryonic connections dropped */
name|long
name|spps_closed
decl_stmt|;
comment|/* conn. closed (includes drops) */
name|long
name|spps_segstimed
decl_stmt|;
comment|/* segs where we tried to get rtt */
name|long
name|spps_rttupdated
decl_stmt|;
comment|/* times we succeeded */
name|long
name|spps_delack
decl_stmt|;
comment|/* delayed acks sent */
name|long
name|spps_timeoutdrop
decl_stmt|;
comment|/* conn. dropped in rxmt timeout */
name|long
name|spps_rexmttimeo
decl_stmt|;
comment|/* retransmit timeouts */
name|long
name|spps_persisttimeo
decl_stmt|;
comment|/* persist timeouts */
name|long
name|spps_keeptimeo
decl_stmt|;
comment|/* keepalive timeouts */
name|long
name|spps_keepprobe
decl_stmt|;
comment|/* keepalive probes sent */
name|long
name|spps_keepdrops
decl_stmt|;
comment|/* connections dropped in keepalive */
name|long
name|spps_sndtotal
decl_stmt|;
comment|/* total packets sent */
name|long
name|spps_sndpack
decl_stmt|;
comment|/* data packets sent */
name|long
name|spps_sndbyte
decl_stmt|;
comment|/* data bytes sent */
name|long
name|spps_sndrexmitpack
decl_stmt|;
comment|/* data packets retransmitted */
name|long
name|spps_sndrexmitbyte
decl_stmt|;
comment|/* data bytes retransmitted */
name|long
name|spps_sndacks
decl_stmt|;
comment|/* ack-only packets sent */
name|long
name|spps_sndprobe
decl_stmt|;
comment|/* window probes sent */
name|long
name|spps_sndurg
decl_stmt|;
comment|/* packets sent with URG only */
name|long
name|spps_sndwinup
decl_stmt|;
comment|/* window update-only packets sent */
name|long
name|spps_sndctrl
decl_stmt|;
comment|/* control (SYN|FIN|RST) packets sent */
name|long
name|spps_sndvoid
decl_stmt|;
comment|/* couldn't find requested packet*/
name|long
name|spps_rcvtotal
decl_stmt|;
comment|/* total packets received */
name|long
name|spps_rcvpack
decl_stmt|;
comment|/* packets received in sequence */
name|long
name|spps_rcvbyte
decl_stmt|;
comment|/* bytes received in sequence */
name|long
name|spps_rcvbadsum
decl_stmt|;
comment|/* packets received with ccksum errs */
name|long
name|spps_rcvbadoff
decl_stmt|;
comment|/* packets received with bad offset */
name|long
name|spps_rcvshort
decl_stmt|;
comment|/* packets received too short */
name|long
name|spps_rcvduppack
decl_stmt|;
comment|/* duplicate-only packets received */
name|long
name|spps_rcvdupbyte
decl_stmt|;
comment|/* duplicate-only bytes received */
name|long
name|spps_rcvpartduppack
decl_stmt|;
comment|/* packets with some duplicate data */
name|long
name|spps_rcvpartdupbyte
decl_stmt|;
comment|/* dup. bytes in part-dup. packets */
name|long
name|spps_rcvoopack
decl_stmt|;
comment|/* out-of-order packets received */
name|long
name|spps_rcvoobyte
decl_stmt|;
comment|/* out-of-order bytes received */
name|long
name|spps_rcvpackafterwin
decl_stmt|;
comment|/* packets with data after window */
name|long
name|spps_rcvbyteafterwin
decl_stmt|;
comment|/* bytes rcvd after window */
name|long
name|spps_rcvafterclose
decl_stmt|;
comment|/* packets rcvd after "close" */
name|long
name|spps_rcvwinprobe
decl_stmt|;
comment|/* rcvd window probe packets */
name|long
name|spps_rcvdupack
decl_stmt|;
comment|/* rcvd duplicate acks */
name|long
name|spps_rcvacktoomuch
decl_stmt|;
comment|/* rcvd acks for unsent data */
name|long
name|spps_rcvackpack
decl_stmt|;
comment|/* rcvd ack packets */
name|long
name|spps_rcvackbyte
decl_stmt|;
comment|/* bytes acked by rcvd acks */
name|long
name|spps_rcvwinupd
decl_stmt|;
comment|/* rcvd window update packets */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|spp_istat
block|{
name|short
name|hdrops
decl_stmt|;
name|short
name|badsum
decl_stmt|;
name|short
name|badlen
decl_stmt|;
name|short
name|slotim
decl_stmt|;
name|short
name|fastim
decl_stmt|;
name|short
name|nonucn
decl_stmt|;
name|short
name|noconn
decl_stmt|;
name|short
name|notme
decl_stmt|;
name|short
name|wrncon
decl_stmt|;
name|short
name|bdreas
decl_stmt|;
name|short
name|gonawy
decl_stmt|;
name|short
name|notyet
decl_stmt|;
name|short
name|lstdup
decl_stmt|;
name|struct
name|sppstat
name|newstats
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|spp_istat
name|spp_istat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Following was struct sppstat sppstat; */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|sppstat
end_ifndef

begin_define
define|#
directive|define
name|sppstat
value|spp_istat.newstats
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|u_short
name|spp_iss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sppcb
modifier|*
name|spp_close
argument_list|()
decl_stmt|,
modifier|*
name|spp_disconnect
argument_list|()
decl_stmt|,
modifier|*
name|spp_usrclosed
argument_list|()
decl_stmt|,
modifier|*
name|spp_timers
argument_list|()
decl_stmt|,
modifier|*
name|spp_drop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPP_ISSINCR
value|128
end_define

begin_comment
comment|/*  * SPP sequence numbers are 16 bit integers operated  * on with modular arithmetic.  These macros can be  * used to compare such integers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_decl_stmt
name|short
name|xnsCbug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SSEQ_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((xnsCbug = (short)((a)-(b)))< 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((xnsCbug = (short)((a)-(b)))<= 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((xnsCbug = (short)((a)-(b)))> 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((xnsCbug = (short)((a)-(b)))>= 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SSEQ_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))< 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))<= 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))> 0)
end_define

begin_define
define|#
directive|define
name|SSEQ_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((short)((a)-(b)))>= 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

