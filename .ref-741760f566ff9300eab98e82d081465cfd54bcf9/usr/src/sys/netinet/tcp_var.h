begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)tcp_var.h	7.2 (Berkeley) %G%  */
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
name|struct
name|mbuf
modifier|*
name|t_tcpopt
decl_stmt|;
comment|/* tcp options */
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
comment|/* highest sequence number sent 					 * used to recognize retransmits 					 */
comment|/* congestion control (for source quench) */
name|u_short
name|snd_cwnd
decl_stmt|;
comment|/* congestion-controlled window */
comment|/* transmit timing stuff */
name|short
name|t_idle
decl_stmt|;
comment|/* inactivity time */
name|short
name|t_rtt
decl_stmt|;
comment|/* round trip time */
name|u_short
name|max_rcvd
decl_stmt|;
comment|/* most peer has sent into window */
name|tcp_seq
name|t_rtseq
decl_stmt|;
comment|/* sequence number being timed */
name|float
name|t_srtt
decl_stmt|;
comment|/* smoothed round-trip time */
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

begin_function_decl
name|struct
name|tcpiphdr
modifier|*
name|tcp_template
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tcpcb
modifier|*
name|tcp_close
argument_list|()
decl_stmt|,
modifier|*
name|tcp_drop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tcpcb
modifier|*
name|tcp_timers
argument_list|()
decl_stmt|,
modifier|*
name|tcp_disconnect
argument_list|()
decl_stmt|,
modifier|*
name|tcp_usrclosed
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

