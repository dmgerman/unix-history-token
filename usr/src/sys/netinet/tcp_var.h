begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tcp_var.h	4.6	81/11/24	*/
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
decl_stmt|,
modifier|*
name|seg_prev
decl_stmt|;
comment|/* seq queue */
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
name|seq_t
name|iss
decl_stmt|;
comment|/* initial send seq # */
name|seq_t
name|irs
decl_stmt|;
comment|/* initial recv seq # */
name|seq_t
name|rcv_urp
decl_stmt|;
comment|/* rcv urgent pointer */
name|seq_t
name|rcv_nxt
decl_stmt|;
comment|/* next seq # to rcv */
name|seq_t
name|rcv_end
decl_stmt|;
comment|/* rcv eol pointer */
name|seq_t
name|snd_off
decl_stmt|;
comment|/* seq # of first datum in send buf */
name|seq_t
name|seq_fin
decl_stmt|;
comment|/* seq # of FIN sent */
name|seq_t
name|snd_end
decl_stmt|;
comment|/* send eol pointer */
name|seq_t
name|snd_urp
decl_stmt|;
comment|/* snd urgent pointer */
name|seq_t
name|snd_lst
decl_stmt|;
comment|/* seq # of last sent datum */
name|seq_t
name|snd_nxt
decl_stmt|;
comment|/* seq # of next datum to send */
name|seq_t
name|snd_una
decl_stmt|;
comment|/* seq # of first unacked datum */
name|seq_t
name|snd_wl
decl_stmt|;
comment|/* seq # of last sent window */
name|seq_t
name|snd_hi
decl_stmt|;
comment|/* highest seq # sent */
name|seq_t
name|snd_wnd
decl_stmt|;
comment|/* send window max */
name|seq_t
name|t_rexmt_val
decl_stmt|;
comment|/* val saved in rexmt timer */
name|seq_t
name|t_rtl_val
decl_stmt|;
comment|/* val saved in rexmt too long timer */
name|seq_t
name|t_xmt_val
decl_stmt|;
comment|/* seq # sent when xmt timer started */
name|seq_t
name|rcv_adv
decl_stmt|;
comment|/* advertised window */
name|struct
name|mbuf
modifier|*
name|seg_unack
decl_stmt|;
comment|/* unacked message queue */
name|short
name|seqcnt
decl_stmt|;
name|u_short
name|tc_flags
decl_stmt|;
comment|/* flags and state; see below */
name|u_short
name|t_options
decl_stmt|;
define|#
directive|define
name|TO_EOL
value|0x01
comment|/* eol mode */
define|#
directive|define
name|TO_URG
value|0x02
comment|/* urgent mode */
name|u_char
name|t_state
decl_stmt|;
comment|/* state of this connection */
name|u_char
name|t_xmtime
decl_stmt|;
comment|/* current rexmt time */
comment|/* timers... must be in order */
name|short
name|t_init
decl_stmt|;
comment|/* init */
name|short
name|t_rexmt
decl_stmt|;
comment|/* retransmission */
name|short
name|t_rexmttl
decl_stmt|;
comment|/* retransmit too long */
name|short
name|t_persist
decl_stmt|;
comment|/* retransmit persistance */
name|short
name|t_finack
decl_stmt|;
comment|/* fin acknowledged */
name|short
name|t_xmt
decl_stmt|;
comment|/* round trip transmission time */
comment|/* end timers */
block|}
struct|;
end_struct

begin_comment
comment|/* tc_flags values */
end_comment

begin_define
define|#
directive|define
name|TC_ACK_DUE
value|0x0001
end_define

begin_comment
comment|/* must we send ACK */
end_comment

begin_define
define|#
directive|define
name|TC_CANCELLED
value|0x0002
end_define

begin_comment
comment|/* retransmit timer cancelled */
end_comment

begin_define
define|#
directive|define
name|TC_FIN_RCVD
value|0x0004
end_define

begin_comment
comment|/* FIN received */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_ONE
value|0x0008
end_define

begin_comment
comment|/* force sending of one byte */
end_comment

begin_define
define|#
directive|define
name|TC_NEW_WINDOW
value|0x0010
end_define

begin_comment
comment|/* received new window size */
end_comment

begin_define
define|#
directive|define
name|TC_REXMT
value|0x0020
end_define

begin_comment
comment|/* this msg is a retransmission */
end_comment

begin_define
define|#
directive|define
name|TC_SND_FIN
value|0x0040
end_define

begin_comment
comment|/* FIN should be sent */
end_comment

begin_define
define|#
directive|define
name|TC_SND_RST
value|0x0080
end_define

begin_comment
comment|/* RST should be sent */
end_comment

begin_define
define|#
directive|define
name|TC_SND_URG
value|0x0100
end_define

begin_comment
comment|/* urgent data to send */
end_comment

begin_define
define|#
directive|define
name|TC_SYN_ACKED
value|0x0200
end_define

begin_comment
comment|/* SYN has been ACKed */
end_comment

begin_define
define|#
directive|define
name|TC_SYN_RCVD
value|0x0400
end_define

begin_comment
comment|/* SYN has been received */
end_comment

begin_define
define|#
directive|define
name|TC_USR_CLOSED
value|0x0800
end_define

begin_comment
comment|/* user has closed connection */
end_comment

begin_define
define|#
directive|define
name|TC_USR_ABORT
value|0x1000
end_define

begin_comment
comment|/* user has closed and does not expect 					   to receive any more data */
end_comment

begin_comment
comment|/*  * TCP timers.  */
end_comment

begin_define
define|#
directive|define
name|TINIT
value|0
end_define

begin_define
define|#
directive|define
name|TREXMT
value|1
end_define

begin_define
define|#
directive|define
name|TREXMTTL
value|2
end_define

begin_define
define|#
directive|define
name|TPERSIST
value|3
end_define

begin_define
define|#
directive|define
name|TFINACK
value|4
end_define

begin_define
define|#
directive|define
name|TNTIMERS
value|5
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
comment|/*  * Tcp machine predicates  */
end_comment

begin_define
define|#
directive|define
name|ack_ok
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(((y)->ti_flags&TH_ACK)==0 || \       ((x)->iss< (y)->ti_ackno&& (y)->ti_ackno<= (x)->snd_hi))
end_define

begin_define
define|#
directive|define
name|syn_ok
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((y)->ti_flags&TH_SYN)
end_define

begin_define
define|#
directive|define
name|ack_fin
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->seq_fin> (x)->iss&& (y)->ti_ackno> (x)->seq_fin)
end_define

begin_define
define|#
directive|define
name|rcv_empty
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)->tc_flags&TC_USR_ABORT) || \       ((x)->t_inpcb->inp_socket->so_rcv.sb_mb == NULL&& \        (x)->seg_next == (x)->seg_prev))
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
name|TCPSIZE
value|20
end_define

begin_comment
comment|/* size of TCP leader (bytes) */
end_comment

begin_comment
comment|/*  * THESE NEED TO BE JUSTIFIED!  *  * *2 here is because slow timeout routine called every 1/2 second.  */
end_comment

begin_define
define|#
directive|define
name|T_INIT
value|(30*2)
end_define

begin_define
define|#
directive|define
name|T_2ML
value|(10*2)
end_define

begin_comment
comment|/* 2*maximum packet lifetime */
end_comment

begin_define
define|#
directive|define
name|T_PERS
value|(5*2)
end_define

begin_comment
comment|/* persist time */
end_comment

begin_define
define|#
directive|define
name|T_REXMT
value|(1*2)
end_define

begin_comment
comment|/* base for retransmission time */
end_comment

begin_define
define|#
directive|define
name|T_REXMTTL
value|(30*2)
end_define

begin_comment
comment|/* retransmit too long timeout */
end_comment

begin_define
define|#
directive|define
name|T_REMAX
value|(30*2)
end_define

begin_comment
comment|/* maximum retransmission time */
end_comment

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
name|TCPDEBUG
end_ifdef

begin_define
define|#
directive|define
name|TDBSIZE
value|50
end_define

begin_comment
comment|/*  * Tcp debugging record.  */
end_comment

begin_struct
struct|struct
name|tcp_debug
block|{
name|long
name|td_tod
decl_stmt|;
comment|/* time of day */
name|struct
name|tcbcb
modifier|*
name|td_tcb
decl_stmt|;
comment|/* -> tcb */
name|char
name|td_old
decl_stmt|;
comment|/* old state */
name|char
name|td_inp
decl_stmt|;
comment|/* input */
name|char
name|td_tim
decl_stmt|;
comment|/* timer id */
name|char
name|td_new
decl_stmt|;
comment|/* new state */
name|seq_t
name|td_sno
decl_stmt|;
comment|/* seq_t number */
name|seq_t
name|td_ano
decl_stmt|;
comment|/* acknowledgement */
name|u_short
name|td_wno
decl_stmt|;
comment|/* window */
name|u_short
name|td_lno
decl_stmt|;
comment|/* length */
name|u_char
name|td_flg
decl_stmt|;
comment|/* message flags */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|seq_t
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

begin_decl_stmt
name|struct
name|tcpstat
name|tcpstat
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TCPDEBUG
end_ifdef

begin_decl_stmt
name|int
name|tcpconsdebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 traces on console */
end_comment

begin_decl_stmt
name|struct
name|tcp_debug
name|tcp_debug
index|[
name|TDBSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tdbx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rotating index into tcp_debug */
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

end_unit

