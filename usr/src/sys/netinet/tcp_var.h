begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tcp_var.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * TCP configuration:  This is a half-assed attempt to make TCP  * self-configure for a few varieties of 4.2 and 4.3-based unixes.  * If you don't have a) a 4.3bsd vax or b) a 3.x Sun (x<6), check  * this carefully (it's probably not right).  Please send me mail  * if you run into configuration problems.  *  - Van Jacobson (van@lbl-csam.arpa)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|42
end_define

begin_comment
comment|/* if we're not 4.3, pretend we're 4.2 */
end_comment

begin_define
define|#
directive|define
name|OLDSTAT
end_define

begin_comment
comment|/* set if we have to use old netstat binaries */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define OLDSTAT	/* set if we have to use old netstat binaries */
end_comment

begin_if
if|#
directive|if
name|sun
operator|||
name|BSD
operator|<
literal|43
end_if

begin_define
define|#
directive|define
name|TCP_COMPAT_42
end_define

begin_comment
comment|/* set if we have to interop w/4.2 systems */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SB_MAX
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SB_MAXCOUNT
end_ifdef

begin_define
define|#
directive|define
name|SB_MAX
value|SB_MAXCOUNT
end_define

begin_comment
comment|/* Sun has to be a little bit different... */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SB_MAX
value|32767
end_define

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
endif|SB_MAXCOUNT
end_endif

begin_endif
endif|#
directive|endif
endif|SB_MAX
end_endif

begin_comment
comment|/*  * Bill Nowicki pointed out that the page size (CLBYTES) has  * nothing to do with the mbuf cluster size.  So, we followed  * Sun's lead and made the new define MCLBYTES stand for the mbuf  * cluster size.  The following define makes up backwards compatible  * with 4.3 and 4.2.  If CLBYTES is>1024 on your machine, check  * this against the mbuf cluster definitions in /usr/include/sys/mbuf.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MCLBYTES
end_ifndef

begin_define
define|#
directive|define
name|MCLBYTES
value|CLBYTES
end_define

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The routine in_localaddr is broken in Sun's 3.4.  We redefine ours  * (in tcp_input.c) so we use can it but won't have a name conflict.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|in_localaddr
value|tcp_in_localaddr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* --------------- end of TCP config ---------------- */
end_comment

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
name|u_short
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
name|u_long
name|snd_wnd
decl_stmt|;
comment|/* send window */
comment|/* receive sequence variables */
name|u_long
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
name|u_long
name|snd_cwnd
decl_stmt|;
comment|/* congestion-controlled window */
name|u_long
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
name|u_long
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
comment|/* TUBA stuff */
name|caddr_t
name|t_tuba_pcb
decl_stmt|;
comment|/* next level down pcb for TCP over z */
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
ifdef|#
directive|ifdef
name|OLDSTAT
comment|/* 	 * Declare statistics the same as in 4.3 	 * at the start of tcpstat (same size and 	 * position) for netstat. 	 */
name|int
name|tcps_rcvbadsum
decl_stmt|;
name|int
name|tcps_rcvbadoff
decl_stmt|;
name|int
name|tcps_rcvshort
decl_stmt|;
name|int
name|tcps_badsegs
decl_stmt|;
name|int
name|tcps_unack
decl_stmt|;
define|#
directive|define
name|tcps_badsum
value|tcps_rcvbadsum
define|#
directive|define
name|tcps_badoff
value|tcps_rcvbadoff
define|#
directive|define
name|tcps_hdrops
value|tcps_rcvshort
endif|#
directive|endif
endif|OLDSTAT
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
endif|#
directive|endif
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
name|inpcb
name|tcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of queue of active tcpcb's */
end_comment

begin_decl_stmt
name|struct
name|tcpstat
name|tcpstat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tcp statistics */
end_comment

begin_decl_stmt
name|u_long
name|tcp_now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for RFC 1323 timestamps */
end_comment

begin_decl_stmt
name|int
name|tcp_attach
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
expr|struct
name|ip
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tcpcb
modifier|*
name|tcp_disconnect
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
name|tcp_dooptions
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|,
expr|struct
name|tcpiphdr
operator|*
operator|,
name|int
operator|*
operator|,
name|u_long
operator|*
operator|,
name|u_long
operator|*
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
name|int
name|tcp_mss
name|__P
argument_list|(
operator|(
expr|struct
name|tcpcb
operator|*
operator|,
name|u_int
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
name|void
name|tcp_notify
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
name|tcp_pulloutofband
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
expr|struct
name|tcpiphdr
operator|*
operator|,
expr|struct
name|mbuf
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
name|int
name|tcp_reass
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
name|struct
name|tcpcb
modifier|*
name|tcp_usrclosed
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
name|int
name|tcp_usrreq
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|int
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tcp_xmit_timer
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

