begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tcp.h 1.1 81/10/14 */
end_comment

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
name|unsigned
name|char
name|t_x1
decl_stmt|;
comment|/* (unused) */
name|unsigned
name|char
name|t_pr
decl_stmt|;
comment|/* protocol */
name|unsigned
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
name|unsigned
name|short
name|t_src
decl_stmt|;
comment|/* source port */
name|unsigned
name|short
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
name|unsigned
name|char
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
name|unsigned
name|char
name|t_fin
range|:
literal|1
decl_stmt|,
comment|/* fin flag */
name|t_syn
range|:
literal|1
decl_stmt|,
comment|/* syn flag */
name|t_rst
range|:
literal|1
decl_stmt|,
comment|/* reset flag */
name|t_eol
range|:
literal|1
decl_stmt|,
comment|/* eol flag */
name|t_ack
range|:
literal|1
decl_stmt|,
comment|/* ack flag */
name|t_urg
range|:
literal|1
decl_stmt|,
comment|/* urgent flag */
name|t_x3
range|:
literal|2
decl_stmt|;
comment|/* (unused) */
name|unsigned
name|short
name|t_win
decl_stmt|;
comment|/* window */
name|unsigned
name|short
name|t_sum
decl_stmt|;
comment|/* checksum */
name|unsigned
name|short
name|t_urp
decl_stmt|;
comment|/* urgent pointer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcb
block|{
comment|/* tcp control block */
comment|/* various pointers */
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
name|struct
name|tcb
modifier|*
name|t_tcb_next
decl_stmt|;
comment|/* -> next tcb */
name|struct
name|tcb
modifier|*
name|t_tcb_prev
decl_stmt|;
comment|/* -> prev tcb */
name|struct
name|ucb
modifier|*
name|t_ucb
decl_stmt|;
comment|/* -> ucb */
name|struct
name|mbuf
modifier|*
name|t_rcv_unack
decl_stmt|;
comment|/* -> unacked message queue */
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
comment|/* next seq # to rcv */
name|sequence
name|rcv_end
decl_stmt|;
comment|/* rcv eol pointer */
name|sequence
name|snd_off
decl_stmt|;
comment|/* seq # of first datum in send buf */
name|sequence
name|seq_fin
decl_stmt|;
comment|/* seq # of FIN sent */
name|sequence
name|snd_end
decl_stmt|;
comment|/* send eol pointer */
name|sequence
name|snd_urp
decl_stmt|;
comment|/* snd urgent pointer */
name|sequence
name|snd_lst
decl_stmt|;
comment|/* seq # of last sent datum */
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
comment|/* highest seq # sent */
name|sequence
name|snd_wnd
decl_stmt|;
comment|/* send window max */
name|sequence
name|t_rexmt_val
decl_stmt|;
comment|/* value saved in rexmt timer */
name|sequence
name|t_rtl_val
decl_stmt|;
comment|/* value saved in rexmt too long timer */
name|sequence
name|t_xmt_val
decl_stmt|;
comment|/* seq # sent when xmt timer started */
comment|/* various flags and state variables */
name|unsigned
name|short
name|ack_due
range|:
literal|1
decl_stmt|,
comment|/* must we send ACK */
name|cancelled
range|:
literal|1
decl_stmt|,
comment|/* retransmit timer cancelled */
name|dropped_txt
range|:
literal|1
decl_stmt|,
comment|/* dropped incoming data */
name|fin_rcvd
range|:
literal|1
decl_stmt|,
comment|/* FIN received */
name|force_one
range|:
literal|1
decl_stmt|,
comment|/* force sending of one byte */
name|new_window
range|:
literal|1
decl_stmt|,
comment|/* received new window size */
name|rexmt
range|:
literal|1
decl_stmt|,
comment|/* this msg is a retransmission */
name|snd_fin
range|:
literal|1
decl_stmt|,
comment|/* FIN should be sent */
name|snd_rst
range|:
literal|1
decl_stmt|,
comment|/* RST should be sent */
name|snd_urg
range|:
literal|1
decl_stmt|,
comment|/* urgent data to send */
name|syn_acked
range|:
literal|1
decl_stmt|,
comment|/* SYN has been ACKed */
name|syn_rcvd
range|:
literal|1
decl_stmt|,
comment|/* SYN has been received */
name|usr_closed
range|:
literal|1
decl_stmt|,
comment|/* user has closed connection */
name|waited_2_ml
range|:
literal|1
decl_stmt|,
comment|/* wait time for FIN ACK is up */
name|net_keep
range|:
literal|1
decl_stmt|,
comment|/* don't free this net input */
name|usr_abort
range|:
literal|1
decl_stmt|;
comment|/* user has closed and does not expect 					   to receive any more data */
name|unsigned
name|short
name|t_flag2
decl_stmt|;
comment|/* (unused) */
name|unsigned
name|short
name|t_lport
decl_stmt|;
comment|/* local port */
name|unsigned
name|short
name|t_fport
decl_stmt|;
comment|/* foreign port */
name|unsigned
name|char
name|t_state
decl_stmt|;
comment|/* state of this connection */
name|unsigned
name|char
name|t_xmtime
decl_stmt|;
comment|/* current rexmt time */
name|unsigned
name|char
name|t_sec
decl_stmt|;
comment|/* security */
name|unsigned
name|char
name|t_prec
decl_stmt|;
comment|/* precedence */
name|unsigned
name|char
name|t_compt
decl_stmt|;
comment|/* compartment */
comment|/* timers */
name|unsigned
name|char
name|t_init
decl_stmt|;
comment|/* initialization too long */
name|unsigned
name|char
name|t_rexmt
decl_stmt|;
comment|/* retransmission */
name|unsigned
name|char
name|t_rexmttl
decl_stmt|;
comment|/* retransmit too long */
name|unsigned
name|char
name|t_persist
decl_stmt|;
comment|/* retransmit persistance */
name|unsigned
name|char
name|t_finack
decl_stmt|;
comment|/* fin acknowledged */
name|unsigned
name|char
name|t_xmt
decl_stmt|;
comment|/* round trip transmission time */
block|}
struct|;
end_struct

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

end_unit

