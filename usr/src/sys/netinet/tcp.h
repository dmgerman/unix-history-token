begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tcp.h 1.8 81/10/29 */
end_comment

begin_comment
comment|/*  * Tcp header (fits over ip header).  */
end_comment

begin_struct
struct|struct
name|th
block|{
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
comment|/* by rights, t_len should be a u_short, but this makes operations */
comment|/* on it very dangerous as comparisons become unsigned and comparing */
comment|/* against negative numbers then fails... we don't expect any> 32767 */
comment|/* byte segments, so pragmatically delcare it to be a short */
name|short
name|t_len
decl_stmt|;
comment|/* seg length */
name|struct
name|socket
name|t_s
decl_stmt|;
comment|/* source internet address */
name|struct
name|socket
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
name|seq_t
name|t_seq
decl_stmt|;
comment|/* sequence number */
name|seq_t
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
name|u_char
name|th_flags
decl_stmt|;
define|#
directive|define
name|TH_FIN
value|001
define|#
directive|define
name|TH_SYN
value|002
define|#
directive|define
name|TH_RST
value|004
define|#
directive|define
name|TH_EOL
value|010
define|#
directive|define
name|TH_ACK
value|020
define|#
directive|define
name|TH_URG
value|040
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

begin_comment
comment|/*  * Tcp control block.  */
end_comment

begin_struct
struct|struct
name|tcb
block|{
name|struct
name|th
modifier|*
name|t_rcv_next
decl_stmt|;
comment|/* first el on rcv queue */
name|struct
name|th
modifier|*
name|t_rcv_prev
decl_stmt|;
comment|/* last el on rcv queue */
name|struct
name|tcb
modifier|*
name|t_tcb_next
decl_stmt|;
comment|/* next tcb */
name|struct
name|tcb
modifier|*
name|t_tcb_prev
decl_stmt|;
comment|/* next tcb */
name|struct
name|ucb
modifier|*
name|t_ucb
decl_stmt|;
comment|/* ucb */
name|struct
name|mbuf
modifier|*
name|t_rcv_unack
decl_stmt|;
comment|/* unacked message queue */
name|short
name|seqcnt
decl_stmt|;
name|short
name|xxx
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
comment|/* various flags and state variables */
name|u_short
name|tc_flags
decl_stmt|;
define|#
directive|define
name|TC_ACK_DUE
value|0x0001
comment|/* must we send ACK */
define|#
directive|define
name|TC_CANCELLED
value|0x0002
comment|/* retransmit timer cancelled */
define|#
directive|define
name|TC_DROPPED_TXT
value|0x0004
comment|/* dropped incoming data */
define|#
directive|define
name|TC_FIN_RCVD
value|0x0008
comment|/* FIN received */
define|#
directive|define
name|TC_FORCE_ONE
value|0x0010
comment|/* force sending of one byte */
define|#
directive|define
name|TC_NEW_WINDOW
value|0x0020
comment|/* received new window size */
define|#
directive|define
name|TC_REXMT
value|0x0040
comment|/* this msg is a retransmission */
define|#
directive|define
name|TC_SND_FIN
value|0x0080
comment|/* FIN should be sent */
define|#
directive|define
name|TC_SND_RST
value|0x0100
comment|/* RST should be sent */
define|#
directive|define
name|TC_SND_URG
value|0x0200
comment|/* urgent data to send */
define|#
directive|define
name|TC_SYN_ACKED
value|0x0400
comment|/* SYN has been ACKed */
define|#
directive|define
name|TC_SYN_RCVD
value|0x0800
comment|/* SYN has been received */
define|#
directive|define
name|TC_USR_CLOSED
value|0x1000
comment|/* user has closed connection */
define|#
directive|define
name|TC_WAITED_2_ML
value|0x2000
comment|/* wait time for FIN ACK is up */
define|#
directive|define
name|TC_NET_KEEP
value|0x4000
comment|/* don't free this net input */
define|#
directive|define
name|TC_USR_ABORT
value|0x8000
comment|/* user has closed and does not expect 					   to receive any more data */
name|u_short
name|t_lport
decl_stmt|;
comment|/* local port */
name|u_short
name|t_fport
decl_stmt|;
comment|/* foreign port */
name|u_char
name|t_state
decl_stmt|;
comment|/* state of this connection */
name|u_char
name|t_xmtime
decl_stmt|;
comment|/* current rexmt time */
comment|/* timers */
name|u_char
name|t_init
decl_stmt|;
comment|/* initialization too long */
name|u_char
name|t_rexmt
decl_stmt|;
comment|/* retransmission */
name|u_char
name|t_rexmttl
decl_stmt|;
comment|/* retransmit too long */
name|u_char
name|t_persist
decl_stmt|;
comment|/* retransmit persistance */
name|u_char
name|t_finack
decl_stmt|;
comment|/* fin acknowledged */
name|u_char
name|t_xmt
decl_stmt|;
comment|/* round trip transmission time */
block|}
struct|;
end_struct

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
value|(((y)->th_flags&TH_ACK)==0 || \       ((x)->iss< (y)->t_ackno&& (y)->t_ackno<= (x)->snd_hi))
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
value|((y)->th_flags&TH_SYN)
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
value|((x)->seq_fin> (x)->iss&& (y)->t_ackno> (x)->seq_fin)
end_define

begin_define
define|#
directive|define
name|rcv_empty
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)->tc_flags&TC_USR_ABORT) || \       ((x)->t_ucb->uc_rbuf == NULL&& (x)->t_rcv_next == (x)->t_rcv_prev))
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
name|TCPROTO
value|6
end_define

begin_comment
comment|/* TCP-4 protocol number */
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

begin_define
define|#
directive|define
name|T_2ML
value|10
end_define

begin_comment
comment|/* 2*maximum packet lifetime */
end_comment

begin_define
define|#
directive|define
name|T_PERS
value|5
end_define

begin_comment
comment|/* persist time */
end_comment

begin_define
define|#
directive|define
name|T_INIT
value|30
end_define

begin_comment
comment|/* init too long timeout */
end_comment

begin_define
define|#
directive|define
name|T_REXMT
value|1
end_define

begin_comment
comment|/* base for retransmission time */
end_comment

begin_define
define|#
directive|define
name|T_REXMTTL
value|30
end_define

begin_comment
comment|/* retransmit too long timeout */
end_comment

begin_define
define|#
directive|define
name|T_REMAX
value|30
end_define

begin_comment
comment|/* maximum retransmission time */
end_comment

begin_define
define|#
directive|define
name|ACTIVE
value|1
end_define

begin_comment
comment|/* active open */
end_comment

begin_define
define|#
directive|define
name|PASSIVE
value|0
end_define

begin_comment
comment|/* passive open */
end_comment

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
name|tcb
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
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

