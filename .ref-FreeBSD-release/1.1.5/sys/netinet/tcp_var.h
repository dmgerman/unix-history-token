begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)tcp_var.h	7.10 (Berkeley) 6/28/90  *	$Id: tcp_var.h,v 1.4 1993/11/25 01:35:21 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_VAR_H_
value|1
end_define

begin_comment
comment|/*  * Kernel variables for tcp.  */
end_comment

begin_comment
comment|/*  * Tcp control block, one per tcp; fields:  */
end_comment

begin_struct
struct|struct
name|tcpcb
block|{
name|struct
name|tcpiphdr
modifier|*
name|seg_next
decl_stmt|;
comment|/* sequencing queue */
name|struct
name|tcpiphdr
modifier|*
name|seg_prev
decl_stmt|;
name|short
name|t_state
decl_stmt|;
comment|/* state of this connection */
name|short
name|t_timer
index|[
name|TCPT_NTIMERS
index|]
decl_stmt|;
comment|/* tcp timers */
name|short
name|t_rxtshift
decl_stmt|;
comment|/* log(2) of rexmt exp. backoff */
name|short
name|t_rxtcur
decl_stmt|;
comment|/* current retransmit value */
name|short
name|t_dupacks
decl_stmt|;
comment|/* consecutive dup acks recd */
name|u_short
name|t_maxseg
decl_stmt|;
comment|/* maximum segment size */
name|char
name|t_force
decl_stmt|;
comment|/* 1 if forcing out a byte */
name|u_char
name|t_flags
decl_stmt|;
define|#
directive|define
name|TF_ACKNOW
value|0x01
comment|/* ack peer immediately */
define|#
directive|define
name|TF_DELACK
value|0x02
comment|/* ack, but try to delay it */
define|#
directive|define
name|TF_NODELAY
value|0x04
comment|/* don't delay packets to coalesce */
define|#
directive|define
name|TF_NOOPT
value|0x08
comment|/* don't use tcp options */
define|#
directive|define
name|TF_SENTFIN
value|0x10
comment|/* have sent FIN */
name|struct
name|tcpiphdr
modifier|*
name|t_template
decl_stmt|;
comment|/* skeletal packet for transmit */
name|struct
name|inpcb
modifier|*
name|t_inpcb
decl_stmt|;
comment|/* back pointer to internet pcb */
comment|/*  * The following fields are used as in the protocol specification.  * See RFC783, Dec. 1981, page 21.  */
comment|/* send sequence variables */
name|tcp_seq
name|snd_una
decl_stmt|;
comment|/* send unacknowledged */
name|tcp_seq
name|snd_nxt
decl_stmt|;
comment|/* send next */
name|tcp_seq
name|snd_up
decl_stmt|;
comment|/* send urgent pointer */
name|tcp_seq
name|snd_wl1
decl_stmt|;
comment|/* window update seg seq number */
name|tcp_seq
name|snd_wl2
decl_stmt|;
comment|/* window update seg ack number */
name|tcp_seq
name|iss
decl_stmt|;
comment|/* initial send sequence number */
name|u_short
name|snd_wnd
decl_stmt|;
comment|/* send window */
comment|/* receive sequence variables */
name|u_short
name|rcv_wnd
decl_stmt|;
comment|/* receive window */
name|tcp_seq
name|rcv_nxt
decl_stmt|;
comment|/* receive next */
name|tcp_seq
name|rcv_up
decl_stmt|;
comment|/* receive urgent pointer */
name|tcp_seq
name|irs
decl_stmt|;
comment|/* initial receive sequence number */
comment|/*  * Additional variables for this implementation.  */
comment|/* receive variables */
name|tcp_seq
name|rcv_adv
decl_stmt|;
comment|/* advertised window */
comment|/* retransmit variables */
name|tcp_seq
name|snd_max
decl_stmt|;
comment|/* highest sequence number sent; 					 * used to recognize retransmits 					 */
comment|/* congestion control (for slow start, source quench, retransmit after loss) */
name|u_short
name|snd_cwnd
decl_stmt|;
comment|/* congestion-controlled window */
name|u_short
name|snd_ssthresh
decl_stmt|;
comment|/* snd_cwnd size threshhold for 					 * for slow start exponential to 					 * linear switch 					 */
comment|/*  * transmit timing stuff.  See below for scale of srtt and rttvar.  * "Variance" is actually smoothed difference.  */
name|short
name|t_idle
decl_stmt|;
comment|/* inactivity time */
name|short
name|t_rtt
decl_stmt|;
comment|/* round trip time */
name|tcp_seq
name|t_rtseq
decl_stmt|;
comment|/* sequence number being timed */
name|short
name|t_srtt
decl_stmt|;
comment|/* smoothed round-trip time */
name|short
name|t_rttvar
decl_stmt|;
comment|/* variance in round-trip time */
name|u_short
name|t_rttmin
decl_stmt|;
comment|/* minimum rtt allowed */
name|u_short
name|max_sndwnd
decl_stmt|;
comment|/* largest window peer has offered */
comment|/* out-of-band data */
name|char
name|t_oobflags
decl_stmt|;
comment|/* have some */
name|char
name|t_iobc
decl_stmt|;
comment|/* input character */
define|#
directive|define
name|TCPOOB_HAVEDATA
value|0x01
define|#
directive|define
name|TCPOOB_HADDATA
value|0x02
name|short
name|t_softerror
decl_stmt|;
comment|/* possible error not yet reported */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|intotcpcb
parameter_list|(
name|ip
parameter_list|)
value|((struct tcpcb *)(ip)->inp_ppcb)
end_define

begin_define
define|#
directive|define
name|sototcpcb
parameter_list|(
name|so
parameter_list|)
value|(intotcpcb(sotoinpcb(so)))
end_define

begin_comment
comment|/*  * The smoothed round-trip time and estimated variance  * are stored as fixed point numbers scaled by the values below.  * For convenience, these scales are also used in smoothing the average  * (smoothed = (1/scale)sample + ((scale-1)/scale)smoothed).  * With these scales, srtt has 3 bits to the right of the binary point,  * and thus an "ALPHA" of 0.875.  rttvar has 2 bits to the right of the  * binary point, and is smoothed with an ALPHA of 0.75.  */
end_comment

begin_define
define|#
directive|define
name|TCP_RTT_SCALE
value|8
end_define

begin_comment
comment|/* multiplier for srtt; 3 bits frac. */
end_comment

begin_define
define|#
directive|define
name|TCP_RTT_SHIFT
value|3
end_define

begin_comment
comment|/* shift for srtt; 3 bits frac. */
end_comment

begin_define
define|#
directive|define
name|TCP_RTTVAR_SCALE
value|4
end_define

begin_comment
comment|/* multiplier for rttvar; 2 bits */
end_comment

begin_define
define|#
directive|define
name|TCP_RTTVAR_SHIFT
value|2
end_define

begin_comment
comment|/* multiplier for rttvar; 2 bits */
end_comment

begin_comment
comment|/*  * The initial retransmission should happen at rtt + 4 * rttvar.  * Because of the way we do the smoothing, srtt and rttvar  * will each average +1/2 tick of bias.  When we compute  * the retransmit timer, we want 1/2 tick of rounding and  * 1 extra tick because of +-1/2 tick uncertainty in the  * firing of the timer.  The bias will give us exactly the  * 1.5 tick we need.  But, because the bias is  * statistical, we have to test that we don't drop below  * the minimum feasible timer (which is 2 ticks).  * This macro assumes that the value of TCP_RTTVAR_SCALE  * is the same as the multiplier for rttvar.  */
end_comment

begin_define
define|#
directive|define
name|TCP_REXMTVAL
parameter_list|(
name|tp
parameter_list|)
define|\
value|(((tp)->t_srtt>> TCP_RTT_SHIFT) + (tp)->t_rttvar)
end_define

begin_comment
comment|/* XXX  * We want to avoid doing m_pullup on incoming packets but that  * means avoiding dtom on the tcp reassembly code.  That in turn means  * keeping an mbuf pointer in the reassembly queue (since we might  * have a cluster).  As a quick hack, the source& destination  * port numbers (which are no longer needed once we've located the  * tcpcb) are overlayed with an mbuf pointer.  */
end_comment

begin_define
define|#
directive|define
name|REASS_MBUF
parameter_list|(
name|ti
parameter_list|)
value|(*(struct mbuf **)&((ti)->ti_t))
end_define

begin_comment
comment|/*  * TCP statistics.  * Many of these should be kept per connection,  * but that's inconvenient at the moment.  */
end_comment

begin_struct
struct|struct
name|tcpstat
block|{
name|u_long
name|tcps_connattempt
decl_stmt|;
comment|/* connections initiated */
name|u_long
name|tcps_accepts
decl_stmt|;
comment|/* connections accepted */
name|u_long
name|tcps_connects
decl_stmt|;
comment|/* connections established */
name|u_long
name|tcps_drops
decl_stmt|;
comment|/* connections dropped */
name|u_long
name|tcps_conndrops
decl_stmt|;
comment|/* embryonic connections dropped */
name|u_long
name|tcps_closed
decl_stmt|;
comment|/* conn. closed (includes drops) */
name|u_long
name|tcps_segstimed
decl_stmt|;
comment|/* segs where we tried to get rtt */
name|u_long
name|tcps_rttupdated
decl_stmt|;
comment|/* times we succeeded */
name|u_long
name|tcps_delack
decl_stmt|;
comment|/* delayed acks sent */
name|u_long
name|tcps_timeoutdrop
decl_stmt|;
comment|/* conn. dropped in rxmt timeout */
name|u_long
name|tcps_rexmttimeo
decl_stmt|;
comment|/* retransmit timeouts */
name|u_long
name|tcps_persisttimeo
decl_stmt|;
comment|/* persist timeouts */
name|u_long
name|tcps_keeptimeo
decl_stmt|;
comment|/* keepalive timeouts */
name|u_long
name|tcps_keepprobe
decl_stmt|;
comment|/* keepalive probes sent */
name|u_long
name|tcps_keepdrops
decl_stmt|;
comment|/* connections dropped in keepalive */
name|u_long
name|tcps_sndtotal
decl_stmt|;
comment|/* total packets sent */
name|u_long
name|tcps_sndpack
decl_stmt|;
comment|/* data packets sent */
name|u_long
name|tcps_sndbyte
decl_stmt|;
comment|/* data bytes sent */
name|u_long
name|tcps_sndrexmitpack
decl_stmt|;
comment|/* data packets retransmitted */
name|u_long
name|tcps_sndrexmitbyte
decl_stmt|;
comment|/* data bytes retransmitted */
name|u_long
name|tcps_sndacks
decl_stmt|;
comment|/* ack-only packets sent */
name|u_long
name|tcps_sndprobe
decl_stmt|;
comment|/* window probes sent */
name|u_long
name|tcps_sndurg
decl_stmt|;
comment|/* packets sent with URG only */
name|u_long
name|tcps_sndwinup
decl_stmt|;
comment|/* window update-only packets sent */
name|u_long
name|tcps_sndctrl
decl_stmt|;
comment|/* control (SYN|FIN|RST) packets sent */
name|u_long
name|tcps_rcvtotal
decl_stmt|;
comment|/* total packets received */
name|u_long
name|tcps_rcvpack
decl_stmt|;
comment|/* packets received in sequence */
name|u_long
name|tcps_rcvbyte
decl_stmt|;
comment|/* bytes received in sequence */
name|u_long
name|tcps_rcvbadsum
decl_stmt|;
comment|/* packets received with ccksum errs */
name|u_long
name|tcps_rcvbadoff
decl_stmt|;
comment|/* packets received with bad offset */
name|u_long
name|tcps_rcvshort
decl_stmt|;
comment|/* packets received too short */
name|u_long
name|tcps_rcvduppack
decl_stmt|;
comment|/* duplicate-only packets received */
name|u_long
name|tcps_rcvdupbyte
decl_stmt|;
comment|/* duplicate-only bytes received */
name|u_long
name|tcps_rcvpartduppack
decl_stmt|;
comment|/* packets with some duplicate data */
name|u_long
name|tcps_rcvpartdupbyte
decl_stmt|;
comment|/* dup. bytes in part-dup. packets */
name|u_long
name|tcps_rcvoopack
decl_stmt|;
comment|/* out-of-order packets received */
name|u_long
name|tcps_rcvoobyte
decl_stmt|;
comment|/* out-of-order bytes received */
name|u_long
name|tcps_rcvpackafterwin
decl_stmt|;
comment|/* packets with data after window */
name|u_long
name|tcps_rcvbyteafterwin
decl_stmt|;
comment|/* bytes rcvd after window */
name|u_long
name|tcps_rcvafterclose
decl_stmt|;
comment|/* packets rcvd after "close" */
name|u_long
name|tcps_rcvwinprobe
decl_stmt|;
comment|/* rcvd window probe packets */
name|u_long
name|tcps_rcvdupack
decl_stmt|;
comment|/* rcvd duplicate acks */
name|u_long
name|tcps_rcvacktoomuch
decl_stmt|;
comment|/* rcvd acks for unsent data */
name|u_long
name|tcps_rcvackpack
decl_stmt|;
comment|/* rcvd ack packets */
name|u_long
name|tcps_rcvackbyte
decl_stmt|;
comment|/* bytes acked by rcvd acks */
name|u_long
name|tcps_rcvwinupd
decl_stmt|;
comment|/* rcvd window update packets */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|inpcb
name|tcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of queue of active tcpcb's */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tcpstat
name|tcpstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tcp statistics */
end_comment

begin_comment
comment|/* From tcp_input.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|tcp_reass
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcpiphdr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcp_mss
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
comment|/*u_short*/
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From tcp_output.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|tcp_output
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_setpersist
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From tcp_subr.c: */
end_comment

begin_function_decl
specifier|extern
name|void
name|tcp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tcpiphdr
modifier|*
name|tcp_template
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_respond
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcpiphdr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|tcp_seq
parameter_list|,
name|tcp_seq
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tcpcb
modifier|*
name|tcp_newtcpcb
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tcpcb
modifier|*
name|tcp_drop
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tcpcb
modifier|*
name|tcp_close
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_drain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_notify
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|MTUDISC
end_ifdef

begin_function_decl
specifier|extern
name|void
name|tcp_checkmtu
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_mtuchanged
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|tcp_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_quench
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From tcp_timer.c: */
end_comment

begin_function_decl
specifier|extern
name|void
name|tcp_fasttimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_slowtimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tcp_canceltimers
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tcpcb
modifier|*
name|tcp_timers
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From tcp_usrreq.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|tcp_usrreq
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcp_ctloutput
parameter_list|(
name|int
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcp_attach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tcpcb
modifier|*
name|tcp_disconnect
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tcpcb
modifier|*
name|tcp_usrclosed
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|inpcb
modifier|*
name|tcp_last_inpcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From in_var.c: */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_ttl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_mssdflt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_rttdflt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_keepidle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_keepintvl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_maxidle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|tcp_sendspace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|tcp_recvspace
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_TCP_VAR_H_ */
end_comment

end_unit

