begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993, 1994, 1995  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_var.h	8.4 (Berkeley) 5/24/95  * 	$Id: tcp_var.h,v 1.39 1997/04/27 20:01:15 wollman Exp $  */
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
end_define

begin_comment
comment|/*  * Kernel variables for tcp.  */
end_comment

begin_comment
comment|/*  * Tcp control block, one per tcp; fields:  * Organized for 16 byte cacheline efficiency.  */
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
name|int
name|t_dupacks
decl_stmt|;
comment|/* consecutive dup acks recd */
name|struct
name|tcpiphdr
modifier|*
name|t_template
decl_stmt|;
comment|/* skeletal packet for transmit */
name|int
name|t_timer
index|[
name|TCPT_NTIMERS
index|]
decl_stmt|;
comment|/* tcp timers */
name|struct
name|inpcb
modifier|*
name|t_inpcb
decl_stmt|;
comment|/* back pointer to internet pcb */
name|int
name|t_state
decl_stmt|;
comment|/* state of this connection */
name|u_int
name|t_flags
decl_stmt|;
define|#
directive|define
name|TF_ACKNOW
value|0x0001
comment|/* ack peer immediately */
define|#
directive|define
name|TF_DELACK
value|0x0002
comment|/* ack, but try to delay it */
define|#
directive|define
name|TF_NODELAY
value|0x0004
comment|/* don't delay packets to coalesce */
define|#
directive|define
name|TF_NOOPT
value|0x0008
comment|/* don't use tcp options */
define|#
directive|define
name|TF_SENTFIN
value|0x0010
comment|/* have sent FIN */
define|#
directive|define
name|TF_REQ_SCALE
value|0x0020
comment|/* have/will request window scaling */
define|#
directive|define
name|TF_RCVD_SCALE
value|0x0040
comment|/* other side has requested scaling */
define|#
directive|define
name|TF_REQ_TSTMP
value|0x0080
comment|/* have/will request timestamps */
define|#
directive|define
name|TF_RCVD_TSTMP
value|0x0100
comment|/* a timestamp was received in SYN */
define|#
directive|define
name|TF_SACK_PERMIT
value|0x0200
comment|/* other side said I could SACK */
define|#
directive|define
name|TF_NEEDSYN
value|0x0400
comment|/* send SYN (implicit state) */
define|#
directive|define
name|TF_NEEDFIN
value|0x0800
comment|/* send FIN (implicit state) */
define|#
directive|define
name|TF_NOPUSH
value|0x1000
comment|/* don't push */
define|#
directive|define
name|TF_REQ_CC
value|0x2000
comment|/* have/will request CC */
define|#
directive|define
name|TF_RCVD_CC
value|0x4000
comment|/* a CC was received in SYN */
define|#
directive|define
name|TF_SENDCCNEW
value|0x8000
comment|/* send CCnew instead of CC in SYN */
name|int
name|t_force
decl_stmt|;
comment|/* 1 if forcing out a byte */
name|tcp_seq
name|snd_una
decl_stmt|;
comment|/* send unacknowledged */
name|tcp_seq
name|snd_max
decl_stmt|;
comment|/* highest sequence number sent; 					 * used to recognize retransmits 					 */
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
name|tcp_seq
name|irs
decl_stmt|;
comment|/* initial receive sequence number */
name|tcp_seq
name|rcv_nxt
decl_stmt|;
comment|/* receive next */
name|tcp_seq
name|rcv_adv
decl_stmt|;
comment|/* advertised window */
name|u_long
name|rcv_wnd
decl_stmt|;
comment|/* receive window */
name|tcp_seq
name|rcv_up
decl_stmt|;
comment|/* receive urgent pointer */
name|u_long
name|snd_wnd
decl_stmt|;
comment|/* send window */
name|u_long
name|snd_cwnd
decl_stmt|;
comment|/* congestion-controlled window */
name|u_long
name|snd_ssthresh
decl_stmt|;
comment|/* snd_cwnd size threshold for 					 * for slow start exponential to 					 * linear switch 					 */
name|u_int
name|t_maxopd
decl_stmt|;
comment|/* mss plus options */
name|u_int
name|t_idle
decl_stmt|;
comment|/* inactivity time */
name|u_long
name|t_duration
decl_stmt|;
comment|/* connection duration */
name|int
name|t_rtt
decl_stmt|;
comment|/* round trip time */
name|tcp_seq
name|t_rtseq
decl_stmt|;
comment|/* sequence number being timed */
name|int
name|t_rxtcur
decl_stmt|;
comment|/* current retransmit value */
name|u_int
name|t_maxseg
decl_stmt|;
comment|/* maximum segment size */
name|int
name|t_srtt
decl_stmt|;
comment|/* smoothed round-trip time */
name|int
name|t_rttvar
decl_stmt|;
comment|/* variance in round-trip time */
name|int
name|t_rxtshift
decl_stmt|;
comment|/* log(2) of rexmt exp. backoff */
name|u_int
name|t_rttmin
decl_stmt|;
comment|/* minimum rtt allowed */
name|u_long
name|t_rttupdated
decl_stmt|;
comment|/* number of times rtt sampled */
name|u_long
name|max_sndwnd
decl_stmt|;
comment|/* largest window peer has offered */
name|int
name|t_softerror
decl_stmt|;
comment|/* possible error not yet reported */
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
comment|/* RFC 1323 variables */
name|u_char
name|snd_scale
decl_stmt|;
comment|/* window scaling for send window */
name|u_char
name|rcv_scale
decl_stmt|;
comment|/* window scaling for recv window */
name|u_char
name|request_r_scale
decl_stmt|;
comment|/* pending window scaling */
name|u_char
name|requested_s_scale
decl_stmt|;
name|u_long
name|ts_recent
decl_stmt|;
comment|/* timestamp echo data */
name|u_long
name|ts_recent_age
decl_stmt|;
comment|/* when last updated */
name|tcp_seq
name|last_ack_sent
decl_stmt|;
comment|/* RFC 1644 variables */
name|tcp_cc
name|cc_send
decl_stmt|;
comment|/* send connection count */
name|tcp_cc
name|cc_recv
decl_stmt|;
comment|/* receive connection count */
comment|/* TUBA stuff */
name|caddr_t
name|t_tuba_pcb
decl_stmt|;
comment|/* next level down pcb for TCP over z */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure to hold TCP options that are only used during segment  * processing (in tcp_input), but not held in the tcpcb.  * It's basically used to reduce the number of parameters  * to tcp_dooptions.  */
end_comment

begin_struct
struct|struct
name|tcpopt
block|{
name|u_long
name|to_flag
decl_stmt|;
comment|/* which options are present */
define|#
directive|define
name|TOF_TS
value|0x0001
comment|/* timestamp */
define|#
directive|define
name|TOF_CC
value|0x0002
comment|/* CC and CCnew are exclusive */
define|#
directive|define
name|TOF_CCNEW
value|0x0004
define|#
directive|define
name|TOF_CCECHO
value|0x0008
name|u_long
name|to_tsval
decl_stmt|;
name|u_long
name|to_tsecr
decl_stmt|;
name|tcp_cc
name|to_cc
decl_stmt|;
comment|/* holds CC or CCnew */
name|tcp_cc
name|to_ccecho
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The TAO cache entry which is stored in the protocol family specific  * portion of the route metrics.  */
end_comment

begin_struct
struct|struct
name|rmxp_tao
block|{
name|tcp_cc
name|tao_cc
decl_stmt|;
comment|/* latest CC in valid SYN */
name|tcp_cc
name|tao_ccsent
decl_stmt|;
comment|/* latest CC sent to peer */
name|u_short
name|tao_mssopt
decl_stmt|;
comment|/* peer's cached MSS */
ifdef|#
directive|ifdef
name|notyet
name|u_short
name|tao_flags
decl_stmt|;
comment|/* cache status flags */
define|#
directive|define
name|TAOF_DONT
value|0x0001
comment|/* peer doesn't understand rfc1644 */
define|#
directive|define
name|TAOF_OK
value|0x0002
comment|/* peer does understand rfc1644 */
define|#
directive|define
name|TAOF_UNDEF
value|0
comment|/* we don't know yet */
endif|#
directive|endif
comment|/* notyet */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rmx_taop
parameter_list|(
name|r
parameter_list|)
value|((struct rmxp_tao *)(r).rmx_filler)
end_define

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
value|32
end_define

begin_comment
comment|/* multiplier for srtt; 3 bits frac. */
end_comment

begin_define
define|#
directive|define
name|TCP_RTT_SHIFT
value|5
end_define

begin_comment
comment|/* shift for srtt; 3 bits frac. */
end_comment

begin_define
define|#
directive|define
name|TCP_RTTVAR_SCALE
value|16
end_define

begin_comment
comment|/* multiplier for rttvar; 2 bits */
end_comment

begin_define
define|#
directive|define
name|TCP_RTTVAR_SHIFT
value|4
end_define

begin_comment
comment|/* shift for rttvar; 2 bits */
end_comment

begin_define
define|#
directive|define
name|TCP_DELTA_SHIFT
value|2
end_define

begin_comment
comment|/* see tcp_input.c */
end_comment

begin_comment
comment|/*  * The initial retransmission should happen at rtt + 4 * rttvar.  * Because of the way we do the smoothing, srtt and rttvar  * will each average +1/2 tick of bias.  When we compute  * the retransmit timer, we want 1/2 tick of rounding and  * 1 extra tick because of +-1/2 tick uncertainty in the  * firing of the timer.  The bias will give us exactly the  * 1.5 tick we need.  But, because the bias is  * statistical, we have to test that we don't drop below  * the minimum feasible timer (which is 2 ticks).  * This version of the macro adapted from a paper by Lawrence  * Brakmo and Larry Peterson which outlines a problem caused  * by insufficient precision in the original implementation,  * which results in inappropriately large RTO values for very  * fast networks.  */
end_comment

begin_define
define|#
directive|define
name|TCP_REXMTVAL
parameter_list|(
name|tp
parameter_list|)
define|\
value|((((tp)->t_srtt>> (TCP_RTT_SHIFT - TCP_DELTA_SHIFT))  \ 	  + (tp)->t_rttvar)>> TCP_DELTA_SHIFT)
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
name|u_long
name|tcps_pawsdrop
decl_stmt|;
comment|/* segments dropped due to PAWS */
name|u_long
name|tcps_predack
decl_stmt|;
comment|/* times hdr predict ok for acks */
name|u_long
name|tcps_preddat
decl_stmt|;
comment|/* times hdr predict ok for data pkts */
name|u_long
name|tcps_pcbcachemiss
decl_stmt|;
name|u_long
name|tcps_cachedrtt
decl_stmt|;
comment|/* times cached RTT in route updated */
name|u_long
name|tcps_cachedrttvar
decl_stmt|;
comment|/* times cached rttvar updated */
name|u_long
name|tcps_cachedssthresh
decl_stmt|;
comment|/* times cached ssthresh updated */
name|u_long
name|tcps_usedrtt
decl_stmt|;
comment|/* times RTT initialized from route */
name|u_long
name|tcps_usedrttvar
decl_stmt|;
comment|/* times RTTVAR initialized from rt */
name|u_long
name|tcps_usedssthresh
decl_stmt|;
comment|/* times ssthresh initialized from rt*/
name|u_long
name|tcps_persistdrop
decl_stmt|;
comment|/* timeout in persist state */
name|u_long
name|tcps_badsyn
decl_stmt|;
comment|/* bogus SYN, e.g. premature ACK */
name|u_long
name|tcps_mturesent
decl_stmt|;
comment|/* resends due to MTU discovery */
name|u_long
name|tcps_listendrop
decl_stmt|;
comment|/* listen queue overflows */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Names for TCP sysctl objects  */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_DO_RFC1323
value|1
end_define

begin_comment
comment|/* use RFC-1323 extensions */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_DO_RFC1644
value|2
end_define

begin_comment
comment|/* use RFC-1644 extensions */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_MSSDFLT
value|3
end_define

begin_comment
comment|/* MSS default */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_STATS
value|4
end_define

begin_comment
comment|/* statistics (read-only) */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_RTTDFLT
value|5
end_define

begin_comment
comment|/* default RTT estimate */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_KEEPIDLE
value|6
end_define

begin_comment
comment|/* keepalive idle timer */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_KEEPINTVL
value|7
end_define

begin_comment
comment|/* interval to send keepalives */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_SENDSPACE
value|8
end_define

begin_comment
comment|/* send buffer space */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_RECVSPACE
value|9
end_define

begin_comment
comment|/* receive buffer space */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_KEEPINIT
value|10
end_define

begin_comment
comment|/* receive buffer space */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_MAXID
value|11
end_define

begin_define
define|#
directive|define
name|TCPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "rfc1323", CTLTYPE_INT }, \ 	{ "rfc1644", CTLTYPE_INT }, \ 	{ "mssdflt", CTLTYPE_INT }, \ 	{ "stats", CTLTYPE_STRUCT }, \ 	{ "rttdflt", CTLTYPE_INT }, \ 	{ "keepidle", CTLTYPE_INT }, \ 	{ "keepintvl", CTLTYPE_INT }, \ 	{ "sendspace", CTLTYPE_INT }, \ 	{ "recvspace", CTLTYPE_INT }, \ 	{ "keepinit", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|inpcbhead
name|tcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of queue of active tcpcb's */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|inpcbinfo
name|tcbinfo
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|tcp_mssdflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|tcp_now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for RFC 1323 timestamps */
end_comment

begin_decl_stmt
name|void
name|tcp_canceltimers
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tcpcb
modifier|*
name|tcp_close
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_ctlinput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_ctloutput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|socket
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tcpcb
modifier|*
name|tcp_drop
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_drain
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_fasttimo
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rmxp_tao
modifier|*
name|tcp_gettaocache
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_mss
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_mssopt
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_mtudisc
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tcpcb
modifier|*
name|tcp_newtcpcb
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_output
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_quench
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_respond
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|,
expr|struct
name|tcpiphdr
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rtentry
modifier|*
name|tcp_rtlookup
name|__P
argument_list|(
operator|(
expr|struct
name|inpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_setpersist
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_slowtimo
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tcpiphdr
modifier|*
name|tcp_template
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tcpcb
modifier|*
name|tcp_timers
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_trace
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
expr|struct
name|tcpcb
operator|*
operator|,
expr|struct
name|tcpiphdr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|tcp_usrreqs
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

