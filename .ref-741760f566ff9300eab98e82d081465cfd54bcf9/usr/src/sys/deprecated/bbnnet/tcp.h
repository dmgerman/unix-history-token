begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|RCSTCPHDR
value|"$Header: tcp.h,v 1.19 85/07/31 09:33:34 walsh Exp $"
end_define

begin_struct
struct|struct
name|th
block|{
comment|/* tcp header (fits over ip header) */
name|struct
name|th
modifier|*
name|t_next
decl_stmt|;
comment|/* -> next tcp on rcv chain */
name|struct
name|th
modifier|*
name|t_prev
decl_stmt|;
comment|/* -> prev tcp on rcv chain */
name|u_char
name|t_x1
decl_stmt|;
comment|/* (unused) */
name|u_char
name|t_pr
decl_stmt|;
comment|/* protocol */
name|u_short
name|t_len
decl_stmt|;
comment|/* seg length */
name|struct
name|in_addr
name|t_s
decl_stmt|;
comment|/* source internet address */
name|struct
name|in_addr
name|t_d
decl_stmt|;
comment|/* destination internet address */
name|u_short
name|t_src
decl_stmt|;
comment|/* source port */
name|u_short
name|t_dst
decl_stmt|;
comment|/* destination port */
name|sequence
name|t_seq
decl_stmt|;
comment|/* sequence number */
name|sequence
name|t_ackno
decl_stmt|;
comment|/* acknowledgement number */
define|#
directive|define
name|t_end
parameter_list|(
name|x
parameter_list|)
value|(x->t_seq + x->t_len - 1)
name|u_char
name|t_x2
range|:
literal|4
decl_stmt|,
comment|/* (unused) */
name|t_off
range|:
literal|4
decl_stmt|;
comment|/* data offset */
define|#
directive|define
name|TCP_OFFSHIFT
value|2
name|u_char
name|t_flags
decl_stmt|;
define|#
directive|define
name|T_FIN
value|0x01
comment|/* fin flag */
define|#
directive|define
name|T_SYN
value|0x02
comment|/* syn flag */
define|#
directive|define
name|T_RST
value|0x04
comment|/* reset flag */
define|#
directive|define
name|T_PUSH
value|0x08
comment|/* push flag */
define|#
directive|define
name|T_ACK
value|0x10
comment|/* ack flag */
define|#
directive|define
name|T_URG
value|0x20
comment|/* urgent flag */
name|u_short
name|t_win
decl_stmt|;
comment|/* window */
name|u_short
name|t_sum
decl_stmt|;
comment|/* checksum */
name|u_short
name|t_urp
decl_stmt|;
comment|/* urgent pointer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TCP_END_OPT
value|0
end_define

begin_comment
comment|/* end of option list */
end_comment

begin_define
define|#
directive|define
name|TCP_NOP_OPT
value|1
end_define

begin_comment
comment|/* nop option */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXSEG_OPT
value|2
end_define

begin_comment
comment|/* maximum segment size option */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXSEG_OPTLEN
value|4
end_define

begin_comment
comment|/* max seg option length */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXSEG_OPTHDR
value|((TCP_MAXSEG_OPT<<8)|TCP_MAXSEG_OPTLEN)
end_define

begin_typedef
typedef|typedef
name|u_char
name|tcptimerval
typedef|;
end_typedef

begin_comment
comment|/* in 0.5 second units */
end_comment

begin_define
define|#
directive|define
name|MAX_TCPTIMERVAL
value|255
end_define

begin_struct
struct|struct
name|tcpcb
block|{
comment|/* tcp control block */
comment|/* various pointers */
comment|/* where store data until gets to socket */
name|struct
name|th
modifier|*
name|t_rcv_next
decl_stmt|;
comment|/* -> first el on rcv queue */
name|struct
name|th
modifier|*
name|t_rcv_prev
decl_stmt|;
comment|/* -> last el on rcv queue */
name|int
name|t_rcv_len
decl_stmt|;
comment|/* length of rcv queue */
name|struct
name|inpcb
modifier|*
name|t_in_pcb
decl_stmt|;
comment|/* -> in_pcb */
name|struct
name|mbuf
modifier|*
name|t_rcv_unack
decl_stmt|;
comment|/* -> unacked message queue */
comment|/* ### how about a tail pointer */
comment|/* sequence number variables */
name|sequence
name|iss
decl_stmt|;
comment|/* initial send seq # */
name|sequence
name|irs
decl_stmt|;
comment|/* initial recv seq # */
name|sequence
name|rcv_urp
decl_stmt|;
comment|/* rcv urgent pointer */
name|sequence
name|rcv_nxt
decl_stmt|;
comment|/* next contiguous seq # to rcv */
name|sequence
name|seq_fin
decl_stmt|;
comment|/* seq # of FIN sent */
name|sequence
name|snd_end
decl_stmt|;
comment|/* send eol pointer. end of PUSH */
name|sequence
name|snd_urp
decl_stmt|;
comment|/* snd urgent pointer. end of URG */
name|sequence
name|snd_lst
decl_stmt|;
comment|/* seq # of last datum to send */
name|sequence
name|snd_nxt
decl_stmt|;
comment|/* seq # of next datum to send */
name|sequence
name|snd_una
decl_stmt|;
comment|/* seq # of first unacked datum */
name|sequence
name|snd_wl
decl_stmt|;
comment|/* seq # of last sent window */
name|sequence
name|snd_hi
decl_stmt|;
comment|/* highest seq # we sent */
name|sequence
name|t_xmt_val
decl_stmt|;
comment|/* seq # measuring round trip time of */
comment|/* various flags and state variables 	 * At one time booleans were a bitfield, but since are using mbufs, 	 * have space and is quicker to test/set byte than bit. 	 */
name|char
name|ack_due
decl_stmt|;
comment|/* must we send ACK */
name|char
name|cancelled
decl_stmt|;
comment|/* retransmit timer cancelled */
name|char
name|dropped_txt
decl_stmt|;
comment|/* dropped incoming data */
name|char
name|fin_rcvd
decl_stmt|;
comment|/* FIN received */
name|char
name|force_one
decl_stmt|;
comment|/* force sending of one byte */
name|char
name|new_window
decl_stmt|;
comment|/* received new window size */
name|char
name|rexmt
decl_stmt|;
comment|/* this msg is a retransmission */
name|char
name|snd_fin
decl_stmt|;
comment|/* FIN should be sent */
name|char
name|snd_rst
decl_stmt|;
comment|/* RST should be sent */
name|char
name|snd_urg
decl_stmt|;
comment|/* urgent data to send */
name|char
name|syn_acked
decl_stmt|;
comment|/* SYN has been ACKed */
name|char
name|syn_rcvd
decl_stmt|;
comment|/* SYN has been received */
name|char
name|usr_closed
decl_stmt|;
comment|/* user has closed connection */
name|char
name|waited_2_ml
decl_stmt|;
comment|/* wait time for FIN ACK is up */
name|char
name|usr_abort
decl_stmt|;
comment|/* user has closed and does not expect 				           to receive any more data */
name|char
name|sent_zero
decl_stmt|;
comment|/* sent zero window */
name|char
name|force_ack
decl_stmt|;
comment|/* force sending of ack */
name|char
name|t_push
decl_stmt|;
name|char
name|t_urg
decl_stmt|;
name|char
name|t_noactprobe
decl_stmt|;
comment|/* see tcp_newtcpcb() */
name|char
name|t_noactsig
decl_stmt|;
comment|/* end booleans */
name|u_short
name|snd_wnd
decl_stmt|;
comment|/* window he advertised */
name|short
name|t_maxseg
decl_stmt|;
comment|/* max seg size peer can handle */
name|u_short
name|t_maxfrag
decl_stmt|;
comment|/* max IP frag size received */
name|u_short
name|t_olddata
decl_stmt|;
comment|/* useless rexmts received */
name|u_short
name|t_preproc
decl_stmt|;
comment|/* #segs out of window rcvd */
name|u_short
name|t_rxtct
decl_stmt|;
comment|/* # of retransmissions */
name|u_char
name|t_state
decl_stmt|;
comment|/* state of this connection */
name|tcptimerval
name|t_srtt
decl_stmt|;
comment|/* smoothed round trip time */
comment|/* 	 * Not used to limit t_srtt, but to estimate limits/values for the 	 * timers given the rxmitime = 1.5 srtt, and rxmitime doubles for 	 * each retransmission. 	 * This is the srtt on our slowest network connection. 	 */
define|#
directive|define
name|TCP_tvMAXSRTT
value|20
comment|/* 10 seconds */
name|tcptimerval
name|t_rxmitime
decl_stmt|;
comment|/* current rexmt time */
comment|/* 	 * Allow some slop for the maximum in case the network experiences 	 * a temporary peak loading 	 */
define|#
directive|define
name|TCP_tvRXMIN
value|4
define|#
directive|define
name|TCP_tvRXMAX
value|((3 * TCP_tvMAXSRTT) / 2)
name|tcptimerval
name|t_itimeo
decl_stmt|;
comment|/* init timeout value */
comment|/* by default, try 3+ syns to get to the other side */
define|#
directive|define
name|TCP_tvINIT
value|(TCP_tvMAXSRTT + 3 * TCP_tvRXMAX)
name|tcptimerval
name|t_rttltimeo
decl_stmt|;
comment|/* rxmit took too long timeout value */
comment|/* by default, try 4+ retransmissions before warn user */
define|#
directive|define
name|TCP_tvRTTL
value|(TCP_tvMAXSRTT + 4 * TCP_tvRXMAX)
name|tcptimerval
name|t_noact
decl_stmt|;
comment|/* no activity timeout value (mins.) */
define|#
directive|define
name|TCP_tvNOACT
value|10
comment|/* internal no activity timeout (min) */
name|tcptimerval
name|t_timers
index|[
name|NTIMERS
index|]
decl_stmt|;
comment|/* the timers */
define|#
directive|define
name|TCP_tvMINPERSIST
value|10
define|#
directive|define
name|TCP_tvMAXPERSIST
value|90
define|#
directive|define
name|TCP_tv2ML
value|40
comment|/* 2*maximum packet lifetime */
name|struct
name|mbuf
modifier|*
name|oob_data
decl_stmt|;
comment|/* for 4.2 implementation of urgent */
name|sequence
name|rcv_urpend
decl_stmt|;
comment|/* (out-of-band) data */
name|short
name|sws_qff
decl_stmt|;
comment|/* silly window syndrome and icmp 					 * source quench fudge factor */
name|short
name|ack_skipped
decl_stmt|;
name|sequence
name|lastack
decl_stmt|;
comment|/* with force_ack, for TDELACK */
name|u_short
name|rcv_wnd
decl_stmt|;
comment|/* window we advertised */
name|struct
name|th
modifier|*
name|t_template
decl_stmt|;
comment|/* for send_pkt() */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|TCP_tvRXMAX
operator|>
name|MAX_TCPTIMERVAL
end_if

begin_expr_stmt
name|whoops
endif|#
directive|endif
if|#
directive|if
name|TCP_tvINIT
operator|>
name|MAX_TCPTIMERVAL
name|whoops
endif|#
directive|endif
if|#
directive|if
name|TCP_tvRTTL
operator|>
name|MAX_TCPTIMERVAL
name|whoops
endif|#
directive|endif
expr|struct
name|t_debug
block|{
comment|/* tcp debugging record */
name|u_long
name|t_iptime
block|;
name|char
name|t_oldstate
block|;
comment|/* old state */
name|char
name|t_input
block|;
comment|/* input */
name|char
name|t_timer
block|;
comment|/* timer id */
name|char
name|t_newstate
block|;
comment|/* new state */
block|struct
name|tcpcb
name|t_tcb
block|;
comment|/* -> tcb */
block|struct
name|th
name|t_hdr
block|;
comment|/* valid iff input is INRECV */
block|}
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DB_PER_CHUNK
parameter_list|(
name|x
parameter_list|)
value|(((x)/sizeof(struct t_debug)) * sizeof(struct t_debug))
end_define

begin_define
define|#
directive|define
name|TDBLEN
value|DB_PER_CHUNK(MLEN)
end_define

begin_define
define|#
directive|define
name|TCDBLEN
value|DB_PER_CHUNK(CLBYTES)
end_define

begin_comment
comment|/*  * tcp statistics  */
end_comment

begin_struct
struct|struct
name|tcp_stat
block|{
name|struct
name|in_stat
name|t_in
decl_stmt|;
define|#
directive|define
name|t_total
value|t_in.in_total
define|#
directive|define
name|t_badsum
value|t_in.in_badsum
define|#
directive|define
name|t_tooshort
value|t_in.in_tooshort
name|int
name|t_badsegs
decl_stmt|;
comment|/* #bad tcp segments (to which we send RST) */
name|int
name|t_unack
decl_stmt|;
comment|/* #tcp segs placed on rcv_unack */
name|int
name|t_retransmit
decl_stmt|;
comment|/* #retransmissions we sent */
name|int
name|t_ackonly
decl_stmt|;
comment|/* #send_pkt just to send ack, no data */
block|}
struct|;
end_struct

begin_comment
comment|/* size of TCP leader (bytes) */
end_comment

begin_define
define|#
directive|define
name|TCPSIZE
value|(sizeof(struct th)-sizeof(struct ip))
end_define

begin_comment
comment|/*  * max size of TCP/IP leader.  If start using options on tcp connections,  * increase TCPIPMAX accordingly.  */
end_comment

begin_define
define|#
directive|define
name|TCPIPMAX
value|sizeof(struct th)
end_define

begin_comment
comment|/* initial maximum segment size */
end_comment

begin_define
define|#
directive|define
name|TCPMAXSND
value|(IPMAX - TCPIPMAX)
end_define

begin_comment
comment|/* get the tcpcb from the inpcb */
end_comment

begin_define
define|#
directive|define
name|inptotcpcb
parameter_list|(
name|inp
parameter_list|)
value|((struct tcpcb *)((inp)->inp_ppcb))
end_define

begin_define
define|#
directive|define
name|sototcpcb
parameter_list|(
name|so
parameter_list|)
value|(inptotcpcb((struct inpcb *)((so)->so_pcb)))
end_define

begin_define
define|#
directive|define
name|tcpcbtoso
parameter_list|(
name|tp
parameter_list|)
value|((tp)->t_in_pcb->inp_socket)
end_define

begin_define
define|#
directive|define
name|TCP_CTL
value|1
end_define

begin_comment
comment|/* send/receive control call */
end_comment

begin_define
define|#
directive|define
name|TCP_DATA
value|0
end_define

begin_comment
comment|/* send/receive data call */
end_comment

begin_define
define|#
directive|define
name|T_LINGERTIME
value|120
end_define

begin_comment
comment|/* two minutes of linger */
end_comment

begin_comment
comment|/* tcp machine predicates */
end_comment

begin_comment
comment|/*  * Is there unacked data on this TCP connection?  */
end_comment

begin_define
define|#
directive|define
name|is_unacked
parameter_list|(
name|t
parameter_list|)
value|(SEQ_LT((t)->snd_una, (t)->snd_hi))
end_define

begin_comment
comment|/* ACK of local FIN */
end_comment

begin_define
define|#
directive|define
name|ack_fin
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(SEQ_GT((x)->seq_fin, (x)->iss)&& \ 			SEQ_GT((y)->t_ackno, (x)->seq_fin))
end_define

begin_comment
comment|/* receive buffer empty */
end_comment

begin_define
define|#
directive|define
name|rcv_empty
parameter_list|(
name|x
parameter_list|)
value|((x)->usr_abort || \ 		((x)->t_in_pcb->inp_socket->so_rcv.sb_cc == 0&& \ 		 (x)->t_rcv_next == (struct th *)(x)))
end_define

begin_define
define|#
directive|define
name|t_cancel
parameter_list|(
name|tp
parameter_list|,
name|timer
parameter_list|)
value|((tp)->t_timers[timer] = 0)
end_define

begin_function_decl
name|sequence
name|firstempty
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tcp_conn_used
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* see note about return value */
end_comment

begin_function_decl
name|struct
name|th
modifier|*
name|tcp_template
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * If we have many incarnations of a connection in a time period, do not  * want the sequence number space of them to overlap and have packets for  * one be mistaken as from another.  * Assume max throughput of 1Mbit/sec == 125kbyte/sec for TCP  */
end_comment

begin_define
define|#
directive|define
name|ISSINCR
value|((125*1024) / PR_SLOWHZ)
end_define

begin_comment
comment|/*  * 512 is arbitrary.  */
end_comment

begin_define
define|#
directive|define
name|MAX_TCPOOB
value|512
end_define

begin_comment
comment|/*  * TCP port allocation  */
end_comment

begin_define
define|#
directive|define
name|TCP_RESERVED
value|1023
end_define

begin_comment
comment|/*<= for root only */
end_comment

begin_define
define|#
directive|define
name|TCP_USERRESERVED
value|5000
end_define

begin_comment
comment|/* reserved for applications */
end_comment

begin_define
define|#
directive|define
name|TCP_MAXPORT
value|0xffff
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|tcp_stat
name|tcpstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

