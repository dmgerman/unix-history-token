begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993, 1994, 1995  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_var.h	8.4 (Berkeley) 5/24/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_comment
comment|/*  * Kernel variables for tcp.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_do_rfc1323
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TCP segment queue entry */
end_comment

begin_struct
struct|struct
name|tseg_qent
block|{
name|LIST_ENTRY
argument_list|(
argument|tseg_qent
argument_list|)
name|tqe_q
expr_stmt|;
name|int
name|tqe_len
decl_stmt|;
comment|/* TCP segment data length */
name|struct
name|tcphdr
modifier|*
name|tqe_th
decl_stmt|;
comment|/* a pointer to tcp header */
name|struct
name|mbuf
modifier|*
name|tqe_m
decl_stmt|;
comment|/* mbuf contains packet */
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|tsegqe_head
argument_list|,
name|tseg_qent
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_reass_qsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uma_zone
modifier|*
name|tcp_reass_zone
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|sackblk
block|{
name|tcp_seq
name|start
decl_stmt|;
comment|/* start seq no. of sack block */
name|tcp_seq
name|end
decl_stmt|;
comment|/* end seq no. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sackhole
block|{
name|tcp_seq
name|start
decl_stmt|;
comment|/* start seq no. of hole */
name|tcp_seq
name|end
decl_stmt|;
comment|/* end seq no. */
name|tcp_seq
name|rxmit
decl_stmt|;
comment|/* next seq. no in hole to be retransmitted */
name|TAILQ_ENTRY
argument_list|(
argument|sackhole
argument_list|)
name|scblink
expr_stmt|;
comment|/* scoreboard linkage */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sackhint
block|{
name|struct
name|sackhole
modifier|*
name|nexthole
decl_stmt|;
name|int
name|sack_bytes_rexmit
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcptemp
block|{
name|u_char
name|tt_ipgen
index|[
literal|40
index|]
decl_stmt|;
comment|/* the size must be of max ip header, now IPv6 */
name|struct
name|tcphdr
name|tt_t
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tcp6cb
value|tcpcb
end_define

begin_comment
comment|/* for KAME src sync over BSD*'s */
end_comment

begin_comment
comment|/*  * Tcp control block, one per tcp; fields:  * Organized for 16 byte cacheline efficiency.  */
end_comment

begin_struct
struct|struct
name|tcpcb
block|{
name|struct
name|tsegqe_head
name|t_segq
decl_stmt|;
comment|/* segment reassembly queue */
name|int
name|t_segqlen
decl_stmt|;
comment|/* segment reassembly queue length */
name|int
name|t_dupacks
decl_stmt|;
comment|/* consecutive dup acks recd */
name|struct
name|callout
modifier|*
name|tt_rexmt
decl_stmt|;
comment|/* retransmit timer */
name|struct
name|callout
modifier|*
name|tt_persist
decl_stmt|;
comment|/* retransmit persistence */
name|struct
name|callout
modifier|*
name|tt_keep
decl_stmt|;
comment|/* keepalive */
name|struct
name|callout
modifier|*
name|tt_2msl
decl_stmt|;
comment|/* 2*msl TIME_WAIT timer */
name|struct
name|callout
modifier|*
name|tt_delack
decl_stmt|;
comment|/* delayed ACK timer */
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
value|0x000001
comment|/* ack peer immediately */
define|#
directive|define
name|TF_DELACK
value|0x000002
comment|/* ack, but try to delay it */
define|#
directive|define
name|TF_NODELAY
value|0x000004
comment|/* don't delay packets to coalesce */
define|#
directive|define
name|TF_NOOPT
value|0x000008
comment|/* don't use tcp options */
define|#
directive|define
name|TF_SENTFIN
value|0x000010
comment|/* have sent FIN */
define|#
directive|define
name|TF_REQ_SCALE
value|0x000020
comment|/* have/will request window scaling */
define|#
directive|define
name|TF_RCVD_SCALE
value|0x000040
comment|/* other side has requested scaling */
define|#
directive|define
name|TF_REQ_TSTMP
value|0x000080
comment|/* have/will request timestamps */
define|#
directive|define
name|TF_RCVD_TSTMP
value|0x000100
comment|/* a timestamp was received in SYN */
define|#
directive|define
name|TF_SACK_PERMIT
value|0x000200
comment|/* other side said I could SACK */
define|#
directive|define
name|TF_NEEDSYN
value|0x000400
comment|/* send SYN (implicit state) */
define|#
directive|define
name|TF_NEEDFIN
value|0x000800
comment|/* send FIN (implicit state) */
define|#
directive|define
name|TF_NOPUSH
value|0x001000
comment|/* don't push */
define|#
directive|define
name|TF_MORETOCOME
value|0x010000
comment|/* More data to be appended to sock */
define|#
directive|define
name|TF_LQ_OVERFLOW
value|0x020000
comment|/* listen queue overflow */
define|#
directive|define
name|TF_LASTIDLE
value|0x040000
comment|/* connection was previously idle */
define|#
directive|define
name|TF_RXWIN0SENT
value|0x080000
comment|/* sent a receiver win 0 in response */
define|#
directive|define
name|TF_FASTRECOVERY
value|0x100000
comment|/* in NewReno Fast Recovery */
define|#
directive|define
name|TF_WASFRECOVERY
value|0x200000
comment|/* was in NewReno Fast Recovery */
define|#
directive|define
name|TF_SIGNATURE
value|0x400000
comment|/* require MD5 digests (RFC2385) */
define|#
directive|define
name|TF_FORCEDATA
value|0x800000
comment|/* force out a byte */
define|#
directive|define
name|TF_TSO
value|0x1000000
comment|/* TSO enabled on this connection */
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
name|snd_bwnd
decl_stmt|;
comment|/* bandwidth-controlled window */
name|u_long
name|snd_ssthresh
decl_stmt|;
comment|/* snd_cwnd size threshold for 					 * for slow start exponential to 					 * linear switch 					 */
name|u_long
name|snd_bandwidth
decl_stmt|;
comment|/* calculated bandwidth or 0 */
name|tcp_seq
name|snd_recover
decl_stmt|;
comment|/* for use in NewReno Fast Recovery */
name|u_int
name|t_maxopd
decl_stmt|;
comment|/* mss plus options */
name|u_long
name|t_rcvtime
decl_stmt|;
comment|/* inactivity time */
name|u_long
name|t_starttime
decl_stmt|;
comment|/* time connection was established */
name|int
name|t_rtttime
decl_stmt|;
comment|/* round trip time */
name|tcp_seq
name|t_rtseq
decl_stmt|;
comment|/* sequence number being timed */
name|int
name|t_bw_rtttime
decl_stmt|;
comment|/* used for bandwidth calculation */
name|tcp_seq
name|t_bw_rtseq
decl_stmt|;
comment|/* used for bandwidth calculation */
name|int
name|t_rxtcur
decl_stmt|;
comment|/* current retransmit value (ticks) */
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
name|u_int
name|t_rttbest
decl_stmt|;
comment|/* best rtt we've seen */
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
comment|/* unused, to be reused later */
name|u_int32_t
name|ts_recent
decl_stmt|;
comment|/* timestamp echo data */
name|u_long
name|ts_recent_age
decl_stmt|;
comment|/* when last updated */
name|u_int32_t
name|ts_offset
decl_stmt|;
comment|/* our timestamp offset */
name|tcp_seq
name|last_ack_sent
decl_stmt|;
comment|/* experimental */
name|u_long
name|snd_cwnd_prev
decl_stmt|;
comment|/* cwnd prior to retransmit */
name|u_long
name|snd_ssthresh_prev
decl_stmt|;
comment|/* ssthresh prior to retransmit */
name|tcp_seq
name|snd_recover_prev
decl_stmt|;
comment|/* snd_recover prior to retransmit */
name|u_long
name|t_badrxtwin
decl_stmt|;
comment|/* window for retransmit recovery */
name|u_char
name|snd_limited
decl_stmt|;
comment|/* segments limited transmitted */
comment|/* anti DoS counters */
name|u_long
name|rcv_second
decl_stmt|;
comment|/* start of interval second */
name|u_long
name|rcv_pps
decl_stmt|;
comment|/* received packets per second */
name|u_long
name|rcv_byps
decl_stmt|;
comment|/* received bytes per second */
comment|/* SACK related state */
name|int
name|sack_enable
decl_stmt|;
comment|/* enable SACK for this connection */
name|int
name|snd_numholes
decl_stmt|;
comment|/* number of holes seen by sender */
name|TAILQ_HEAD
argument_list|(
argument|sackhole_head
argument_list|,
argument|sackhole
argument_list|)
name|snd_holes
expr_stmt|;
comment|/* SACK scoreboard (sorted) */
name|tcp_seq
name|snd_fack
decl_stmt|;
comment|/* last seq number(+1) sack'd by rcv'r*/
name|int
name|rcv_numsacks
decl_stmt|;
comment|/* # distinct sack blks present */
name|struct
name|sackblk
name|sackblks
index|[
name|MAX_SACK_BLKS
index|]
decl_stmt|;
comment|/* seq nos. of sack blocks */
name|tcp_seq
name|sack_newdata
decl_stmt|;
comment|/* New data xmitted in this recovery 					   episode starts at this seq number */
name|struct
name|sackhint
name|sackhint
decl_stmt|;
comment|/* SACK scoreboard hint */
name|int
name|t_rttlow
decl_stmt|;
comment|/* smallest observerved RTT */
name|u_int32_t
name|rfbuf_ts
decl_stmt|;
comment|/* recv buffer autoscaling timestamp */
name|int
name|rfbuf_cnt
decl_stmt|;
comment|/* recv buffer autoscaling byte count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IN_FASTRECOVERY
parameter_list|(
name|tp
parameter_list|)
value|(tp->t_flags& TF_FASTRECOVERY)
end_define

begin_define
define|#
directive|define
name|ENTER_FASTRECOVERY
parameter_list|(
name|tp
parameter_list|)
value|tp->t_flags |= TF_FASTRECOVERY
end_define

begin_define
define|#
directive|define
name|EXIT_FASTRECOVERY
parameter_list|(
name|tp
parameter_list|)
value|tp->t_flags&= ~TF_FASTRECOVERY
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TCP_SIGNATURE
end_ifdef

begin_comment
comment|/*  * Defines which are needed by the xform_tcp module and tcp_[in|out]put  * for SADB verification and lookup.  */
end_comment

begin_define
define|#
directive|define
name|TCP_SIGLEN
value|16
end_define

begin_comment
comment|/* length of computed digest in bytes */
end_comment

begin_define
define|#
directive|define
name|TCP_KEYLEN_MIN
value|1
end_define

begin_comment
comment|/* minimum length of TCP-MD5 key */
end_comment

begin_define
define|#
directive|define
name|TCP_KEYLEN_MAX
value|80
end_define

begin_comment
comment|/* maximum length of TCP-MD5 key */
end_comment

begin_comment
comment|/*  * Only a single SA per host may be specified at this time. An SPI is  * needed in order for the KEY_ALLOCSA() lookup to work.  */
end_comment

begin_define
define|#
directive|define
name|TCP_SIG_SPI
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCP_SIGNATURE */
end_comment

begin_comment
comment|/*  * Structure to hold TCP options that are only used during segment  * processing (in tcp_input), but not held in the tcpcb.  * It's basically used to reduce the number of parameters  * to tcp_dooptions.  */
end_comment

begin_struct
struct|struct
name|tcpopt
block|{
name|u_long
name|to_flags
decl_stmt|;
comment|/* which options are present */
define|#
directive|define
name|TOF_TS
value|0x0001
comment|/* timestamp */
define|#
directive|define
name|TOF_MSS
value|0x0010
comment|/* maximum segment size */
define|#
directive|define
name|TOF_SCALE
value|0x0020
comment|/* window scaling */
define|#
directive|define
name|TOF_SIGNATURE
value|0x0040
comment|/* signature option present */
define|#
directive|define
name|TOF_SIGLEN
value|0x0080
comment|/* signature length valid (RFC2385) */
define|#
directive|define
name|TOF_SACK
value|0x0100
comment|/* Peer sent SACK option */
name|u_int32_t
name|to_tsval
decl_stmt|;
name|u_int32_t
name|to_tsecr
decl_stmt|;
name|u_int16_t
name|to_mss
decl_stmt|;
name|u_int8_t
name|to_requested_s_scale
decl_stmt|;
name|u_int8_t
name|to_nsacks
decl_stmt|;
comment|/* number of SACK blocks */
name|u_char
modifier|*
name|to_sacks
decl_stmt|;
comment|/* pointer to the first SACK blocks */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for tcp_dooptions.  */
end_comment

begin_define
define|#
directive|define
name|TO_SYN
value|0x01
end_define

begin_comment
comment|/* parse SYN-only options */
end_comment

begin_struct
struct|struct
name|hc_metrics_lite
block|{
comment|/* must stay in sync with hc_metrics */
name|u_long
name|rmx_mtu
decl_stmt|;
comment|/* MTU for this path */
name|u_long
name|rmx_ssthresh
decl_stmt|;
comment|/* outbound gateway buffer limit */
name|u_long
name|rmx_rtt
decl_stmt|;
comment|/* estimated round trip time */
name|u_long
name|rmx_rttvar
decl_stmt|;
comment|/* estimated rtt variance */
name|u_long
name|rmx_bandwidth
decl_stmt|;
comment|/* estimated bandwidth */
name|u_long
name|rmx_cwnd
decl_stmt|;
comment|/* congestion window */
name|u_long
name|rmx_sendpipe
decl_stmt|;
comment|/* outbound delay-bandwidth product */
name|u_long
name|rmx_recvpipe
decl_stmt|;
comment|/* inbound delay-bandwidth product */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_PCB_H_
end_ifndef

begin_struct_decl
struct_decl|struct
name|in_conninfo
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IN_PCB_H_ */
end_comment

begin_struct
struct|struct
name|tcptw
block|{
name|struct
name|inpcb
modifier|*
name|tw_inpcb
decl_stmt|;
comment|/* XXX back pointer to internet pcb */
name|tcp_seq
name|snd_nxt
decl_stmt|;
name|tcp_seq
name|rcv_nxt
decl_stmt|;
name|tcp_seq
name|iss
decl_stmt|;
name|tcp_seq
name|irs
decl_stmt|;
name|u_short
name|last_win
decl_stmt|;
comment|/* cached window value */
name|u_short
name|tw_so_options
decl_stmt|;
comment|/* copy of so_options */
name|struct
name|ucred
modifier|*
name|tw_cred
decl_stmt|;
comment|/* user credentials */
name|u_long
name|t_recent
decl_stmt|;
name|u_long
name|t_starttime
decl_stmt|;
name|int
name|tw_time
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|tcptw
argument_list|)
name|tw_2msl
expr_stmt|;
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
name|intotw
parameter_list|(
name|ip
parameter_list|)
value|((struct tcptw *)(ip)->inp_ppcb)
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
value|max((tp)->t_rttmin, (((tp)->t_srtt>> (TCP_RTT_SHIFT - TCP_DELTA_SHIFT))  \ 	  + (tp)->t_rttvar)>> TCP_DELTA_SHIFT)
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
name|tcps_minmssdrops
decl_stmt|;
comment|/* average minmss too low drops */
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
name|tcps_sndrexmitbad
decl_stmt|;
comment|/* unnecessary packet retransmissions */
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
name|tcps_rcvmemdrop
decl_stmt|;
comment|/* packets dropped for lack of memory */
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
name|u_long
name|tcps_badrst
decl_stmt|;
comment|/* ignored RSTs in the window */
name|u_long
name|tcps_sc_added
decl_stmt|;
comment|/* entry added to syncache */
name|u_long
name|tcps_sc_retransmitted
decl_stmt|;
comment|/* syncache entry was retransmitted */
name|u_long
name|tcps_sc_dupsyn
decl_stmt|;
comment|/* duplicate SYN packet */
name|u_long
name|tcps_sc_dropped
decl_stmt|;
comment|/* could not reply to packet */
name|u_long
name|tcps_sc_completed
decl_stmt|;
comment|/* successful extraction of entry */
name|u_long
name|tcps_sc_bucketoverflow
decl_stmt|;
comment|/* syncache per-bucket limit hit */
name|u_long
name|tcps_sc_cacheoverflow
decl_stmt|;
comment|/* syncache cache limit hit */
name|u_long
name|tcps_sc_reset
decl_stmt|;
comment|/* RST removed entry from syncache */
name|u_long
name|tcps_sc_stale
decl_stmt|;
comment|/* timed out or listen socket gone */
name|u_long
name|tcps_sc_aborted
decl_stmt|;
comment|/* syncache entry aborted */
name|u_long
name|tcps_sc_badack
decl_stmt|;
comment|/* removed due to bad ACK */
name|u_long
name|tcps_sc_unreach
decl_stmt|;
comment|/* ICMP unreachable received */
name|u_long
name|tcps_sc_zonefail
decl_stmt|;
comment|/* zalloc() failed */
name|u_long
name|tcps_sc_sendcookie
decl_stmt|;
comment|/* SYN cookie sent */
name|u_long
name|tcps_sc_recvcookie
decl_stmt|;
comment|/* SYN cookie received */
name|u_long
name|tcps_hc_added
decl_stmt|;
comment|/* entry added to hostcache */
name|u_long
name|tcps_hc_bucketoverflow
decl_stmt|;
comment|/* hostcache per bucket limit hit */
comment|/* SACK related stats */
name|u_long
name|tcps_sack_recovery_episode
decl_stmt|;
comment|/* SACK recovery episodes */
name|u_long
name|tcps_sack_rexmits
decl_stmt|;
comment|/* SACK rexmit segments   */
name|u_long
name|tcps_sack_rexmit_bytes
decl_stmt|;
comment|/* SACK rexmit bytes      */
name|u_long
name|tcps_sack_rcv_blocks
decl_stmt|;
comment|/* SACK blocks (options) received */
name|u_long
name|tcps_sack_send_blocks
decl_stmt|;
comment|/* SACK blocks (options) sent     */
name|u_long
name|tcps_sack_sboverflow
decl_stmt|;
comment|/* times scoreboard overflowed */
block|}
struct|;
end_struct

begin_comment
comment|/*  * TCB structure exported to user-land via sysctl(3).  * Evil hack: declare only if in_pcb.h and sys/socketvar.h have been  * included.  Not all of our clients do.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NETINET_IN_PCB_H_
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SYS_SOCKETVAR_H_
argument_list|)
end_if

begin_struct
struct|struct
name|xtcpcb
block|{
name|size_t
name|xt_len
decl_stmt|;
name|struct
name|inpcb
name|xt_inp
decl_stmt|;
name|struct
name|tcpcb
name|xt_tp
decl_stmt|;
name|struct
name|xsocket
name|xt_socket
decl_stmt|;
name|u_quad_t
name|xt_alignment_hack
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* timeout for establishing syn */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_PCBLIST
value|11
end_define

begin_comment
comment|/* list of all outstanding PCBs */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_DELACKTIME
value|12
end_define

begin_comment
comment|/* time before sending delayed ACK */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_V6MSSDFLT
value|13
end_define

begin_comment
comment|/* MSS default for IPv6 */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_SACK
value|14
end_define

begin_comment
comment|/* Selective Acknowledgement,rfc 2018 */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_DROP
value|15
end_define

begin_comment
comment|/* drop tcp connection */
end_comment

begin_define
define|#
directive|define
name|TCPCTL_MAXID
value|16
end_define

begin_define
define|#
directive|define
name|TCPCTL_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "rfc1323", CTLTYPE_INT }, \ 	{ "mssdflt", CTLTYPE_INT }, \ 	{ "stats", CTLTYPE_STRUCT }, \ 	{ "rttdflt", CTLTYPE_INT }, \ 	{ "keepidle", CTLTYPE_INT }, \ 	{ "keepintvl", CTLTYPE_INT }, \ 	{ "sendspace", CTLTYPE_INT }, \ 	{ "recvspace", CTLTYPE_INT }, \ 	{ "keepinit", CTLTYPE_INT }, \ 	{ "pcblist", CTLTYPE_STRUCT }, \ 	{ "delacktime", CTLTYPE_INT }, \ 	{ "v6mssdflt", CTLTYPE_INT }, \ 	{ "maxid", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_tcp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_tcp_sack
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|tcp_minmss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_minmssoverload
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_delack_enabled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_do_newreno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|path_mtu_discovery
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ss_fltsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ss_fltsz_local
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tcp_do_sack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SACK enabled/disabled */
end_comment

begin_function_decl
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
name|void
name|tcp_discardcb
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_twstart
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int	 tcp_twrecycleable(struct tcptw *tw);
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|tcp_twclose
parameter_list|(
name|struct
name|tcptw
modifier|*
name|_tw
parameter_list|,
name|int
name|_reuse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|tcp_drain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_fasttimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_fini
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_reass_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|u_long
name|tcp_maxmtu
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|tcp_maxmtu6
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_mss
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
name|int
name|tcp_mssopt
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inpcb
modifier|*
name|tcp_drop_syn_sent
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
name|struct
name|inpcb
modifier|*
name|tcp_mtudisc
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
name|void
name|tcp_respond
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|tcphdr
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
name|int
name|tcp_twrespond
parameter_list|(
name|struct
name|tcptw
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_setpersist
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TCP_SIGNATURE
end_ifdef

begin_function_decl
name|int
name|tcp_signature_compute
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|tcp_slowtimo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tcptemp
modifier|*
name|tcpip_maketemplate
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcpip_fillheaders
parameter_list|(
name|struct
name|inpcb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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

begin_function_decl
name|void
name|tcp_trace
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_xmit_bandwidth_limit
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|tcp_seq
name|ack_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_unreach
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syncache_expand
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syncache_add
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_chkrst
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_badack
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * All tcp_hc_* functions are IPv4 and IPv6 (via in_conninfo)  */
end_comment

begin_function_decl
name|void
name|tcp_hc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_hc_get
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|hc_metrics_lite
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|tcp_hc_getmtu
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_hc_updatemtu
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_hc_update
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|hc_metrics_lite
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|tcp_seq
name|tcp_new_isn
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_sack_doack
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|tcp_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_update_sack_list
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|tcp_seq
name|rcv_laststart
parameter_list|,
name|tcp_seq
name|rcv_lastend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_clean_sackreport
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_sack_adjust
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sackhole
modifier|*
name|tcp_sack_output
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|,
name|int
modifier|*
name|sack_bytes_rexmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_sack_partialack
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_free_sackholes
parameter_list|(
name|struct
name|tcpcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcp_newreno
parameter_list|(
name|struct
name|tcpcb
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|tcp_seq_subtract
parameter_list|(
name|u_long
parameter_list|,
name|u_long
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
comment|/* _NETINET_TCP_VAR_H_ */
end_comment

end_unit

