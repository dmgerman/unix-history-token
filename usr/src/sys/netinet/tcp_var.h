begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tcp_var.h	4.8	81/11/25	*/
end_comment

begin_comment
comment|/*  * Kernel variables for tcp.  */
end_comment

begin_comment
comment|/*  * Tcp+ip header, after ip options removed.  */
end_comment

begin_struct
struct|struct
name|tcpiphdr
block|{
name|struct
name|ipovly
name|ti_i
decl_stmt|;
comment|/* overlaid ip structure */
name|struct
name|tcphdr
name|ti_t
decl_stmt|;
comment|/* tcp header */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ti_next
value|ti_i.ih_next
end_define

begin_define
define|#
directive|define
name|ti_prev
value|ti_i.ih_prev
end_define

begin_define
define|#
directive|define
name|ti_x1
value|ti_i.ih_x1
end_define

begin_define
define|#
directive|define
name|ti_pr
value|ti_i.ih_pr
end_define

begin_define
define|#
directive|define
name|ti_len
value|ti_i.ih_len
end_define

begin_define
define|#
directive|define
name|ti_src
value|ti_i.ih_src
end_define

begin_define
define|#
directive|define
name|ti_dst
value|ti_i.ih_dst
end_define

begin_define
define|#
directive|define
name|ti_sport
value|ti_t.th_sport
end_define

begin_define
define|#
directive|define
name|ti_dport
value|ti_t.th_dport
end_define

begin_define
define|#
directive|define
name|ti_seq
value|ti_t.th_seq
end_define

begin_define
define|#
directive|define
name|ti_ackno
value|ti_t.th_ackno
end_define

begin_define
define|#
directive|define
name|ti_x2
value|ti_t.th_x2
end_define

begin_define
define|#
directive|define
name|ti_off
value|ti_t.th_off
end_define

begin_define
define|#
directive|define
name|ti_flags
value|ti_t.th_flags
end_define

begin_define
define|#
directive|define
name|ti_win
value|ti_t.th_win
end_define

begin_define
define|#
directive|define
name|ti_sum
value|ti_t.th_sum
end_define

begin_define
define|#
directive|define
name|ti_urp
value|ti_t.th_urp
end_define

begin_comment
comment|/*  * TCP sequence numbers are 32 bit integers operated  * on with modular arithmetic.  These macros can be  * used to compare such integers.  */
end_comment

begin_define
define|#
directive|define
name|SEQ_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))< 0)
end_define

begin_define
define|#
directive|define
name|SEQ_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))<= 0)
end_define

begin_define
define|#
directive|define
name|SEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))> 0)
end_define

begin_define
define|#
directive|define
name|SEQ_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))>= 0)
end_define

begin_comment
comment|/*  * Definitions of the TCP timers.  These timers are counted  * down PR_SLOWHZ times a second.  */
end_comment

begin_define
define|#
directive|define
name|TCPT_NTIMERS
value|4
end_define

begin_define
define|#
directive|define
name|TCPT_REXMT
value|0
end_define

begin_comment
comment|/* retransmit */
end_comment

begin_define
define|#
directive|define
name|TCPT_2MSL
value|1
end_define

begin_comment
comment|/* 2*msl quiet time timer */
end_comment

begin_define
define|#
directive|define
name|TCPT_PERSIST
value|2
end_define

begin_comment
comment|/* retransmit persistance */
end_comment

begin_define
define|#
directive|define
name|TCPT_KEEP
value|3
end_define

begin_comment
comment|/* keep alive */
end_comment

begin_comment
comment|/*  * Tcp control block.  */
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
name|t_state
decl_stmt|;
comment|/* state of this connection */
name|int
name|seqcnt
decl_stmt|;
comment|/* count of chars in seq queue */
name|short
name|t_timers
index|[
name|TCPT_NTIMERS
index|]
decl_stmt|;
comment|/* tcp timers */
name|short
name|t_options
decl_stmt|;
comment|/* connection options: */
define|#
directive|define
name|TO_PUSH
value|0x01
comment|/* push mode */
define|#
directive|define
name|TO_URG
value|0x02
comment|/* urgent mode */
define|#
directive|define
name|TO_KEEP
value|0x04
comment|/* use keep-alives */
name|u_char
name|t_flags
decl_stmt|;
define|#
directive|define
name|TF_OWEACK
value|0x01
comment|/* owe ack to peer */
define|#
directive|define
name|TF_DELACK
value|0x02
comment|/* delaying ack to peer */
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
name|u_short
name|snd_wnd
decl_stmt|;
comment|/* send window */
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
comment|/* receive sequence variables */
name|tcp_seq
name|rcv_nxt
decl_stmt|;
comment|/* receive next */
name|u_short
name|rcv_wnd
decl_stmt|;
comment|/* receive window */
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
comment|/* highest sequence number sent */
name|used
name|to
name|recognize
name|retransmits
operator|*
operator|/
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

begin_define
define|#
directive|define
name|ISSINCR
value|128
end_define

begin_comment
comment|/* increment for iss each second */
end_comment

begin_define
define|#
directive|define
name|TCP_TTL
value|60
end_define

begin_comment
comment|/* time to live for TCP segs */
end_comment

begin_comment
comment|/*  * TCPSC constants give various timeouts in ``slow-clock'' ticks.  */
end_comment

begin_define
define|#
directive|define
name|TCPSC_MSL
value|(120*PR_SLOWHZ)
end_define

begin_comment
comment|/* max seg lifetime */
end_comment

begin_define
define|#
directive|define
name|TCPSC_REXMT
value|(  1*PR_SLOWHZ)
end_define

begin_comment
comment|/* base retransmit time */
end_comment

begin_define
define|#
directive|define
name|TCPSC_KEEP
value|(240*PR_SLOWHZ)
end_define

begin_comment
comment|/* keep alive */
end_comment

begin_define
define|#
directive|define
name|TCPSC_PERSIST
value|(  5*PR_SLOWHZ)
end_define

begin_comment
comment|/* retransmit persistance */
end_comment

begin_define
define|#
directive|define
name|TCPSC_KEEPTTL
value|(  4*TCPSC_KEEP)
end_define

begin_comment
comment|/* keep alive too long */
end_comment

begin_define
define|#
directive|define
name|TCPSC_2MSL
value|(  2*TCPSC_MSL)
end_define

begin_comment
comment|/* 2*msl quiet time timer */
end_comment

begin_define
define|#
directive|define
name|TCPSC_TOOLONG
value|(480*PR_SLOWHZ)
end_define

begin_struct
struct|struct
name|tcpstat
block|{
name|int
name|tcps_badsum
decl_stmt|;
name|int
name|tcps_badoff
decl_stmt|;
name|int
name|tcps_hdrops
decl_stmt|;
name|int
name|tcps_badsegs
decl_stmt|;
name|int
name|tcps_unack
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
name|tcp_seq
name|tcp_iss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tcp initial send seq # */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|tcpiphdr
modifier|*
name|tcp_template
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TCPTIMERS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|tcptimers
index|[]
init|=
block|{
literal|"INIT"
block|,
literal|"REXMT"
block|,
literal|"REXMTTL"
block|,
literal|"KEEP"
block|,
literal|"KEEPTTL"
block|,
literal|"PERSIST"
block|,
literal|"2MSL"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

