begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	nsp_var.h	1.3	82/10/09	*/
end_comment

begin_comment
comment|/*  * Kernel variables for NSP  */
end_comment

begin_typedef
typedef|typedef
name|short
name|nsp_seq
typedef|;
end_typedef

begin_comment
comment|/*  * NSP control block, ala Session Control Port,  * p. 41-44, NSP spec.  */
end_comment

begin_struct
struct|struct
name|nspcb
block|{
name|struct
name|nspcb
modifier|*
name|n_next
decl_stmt|,
modifier|*
name|n_prev
decl_stmt|;
comment|/* list of all NSP cb's */
name|struct
name|nspcb
modifier|*
name|n_head
decl_stmt|;
comment|/* pointer to head of list */
name|struct
name|nspq
modifier|*
name|nq_next
decl_stmt|,
modifier|*
name|nq_prev
decl_stmt|;
comment|/* retransmit queue */
comment|/* NEED STUFF FOR INPUT REASSEMBLY */
name|struct
name|socket
modifier|*
name|n_socket
decl_stmt|;
comment|/* back pointer to socket */
name|char
name|n_state
decl_stmt|;
comment|/* state of the port */
name|char
name|n_flags
decl_stmt|;
comment|/* flags, see below */
name|short
name|n_retrans
decl_stmt|;
comment|/* count of message retransmissions */
name|short
name|n_segsize
decl_stmt|;
comment|/* transmit segment size */
name|u_short
name|n_node
decl_stmt|;
comment|/* remote node address */
name|u_short
name|n_loc
decl_stmt|;
comment|/* local link address */
name|u_short
name|n_rem
decl_stmt|;
comment|/* remote link address */
comment|/* timer variables */
name|u_short
name|nt_dat
decl_stmt|;
comment|/* timeout for data segments */
name|u_short
name|nt_oth
decl_stmt|;
comment|/* timeout for other data */
name|u_short
name|nt_con
decl_stmt|;
comment|/* timeout for connect, disconnect */
comment|/* sequence variables */
name|nsp_seq
name|nn_dat
decl_stmt|;
comment|/* number of next data segment to transmit */
name|nsp_seq
name|nn_oth
decl_stmt|;
comment|/* number of next other data segment */
name|nsp_seq
name|nn_high
decl_stmt|;
comment|/* highest numbered data segment queued */
comment|/* error control variables */
name|nsp_seq
name|na_xmtdat
decl_stmt|;
comment|/* number of last data segment we acked */
name|nsp_seq
name|na_xmtoth
decl_stmt|;
comment|/* number of last other data we acked */
name|nsp_seq
name|na_rcvdat
decl_stmt|;
comment|/* number of highest data segment ack rcv'ed */
comment|/* flow control variables */
name|char
name|nf_locdat
decl_stmt|;
comment|/* data request count */
name|char
name|nf_locint
decl_stmt|;
comment|/* flow control state for receiving intr data */
name|char
name|nf_remdat
decl_stmt|;
comment|/* data request count from remote */
name|char
name|nf_remint
decl_stmt|;
comment|/* interrupt request count from remote */
comment|/* buffers for optional data */
name|u_short
name|nb_src
decl_stmt|;
comment|/* source node addr for rcv CI */
name|struct
name|mbuf
modifier|*
name|nb_con
decl_stmt|;
comment|/* data for rcv or xmt CI */
name|struct
name|mbuf
modifier|*
name|nb_xmt
decl_stmt|;
comment|/* data for xmt CC, DI, Intr */
name|struct
name|mbuf
modifier|*
name|nb_rcv
decl_stmt|;
comment|/* data for rcv CC, DI, Intr */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sotonspcb
parameter_list|(
name|so
parameter_list|)
value|((struct nspcb *)(so)->so_pcb)
end_define

begin_comment
comment|/* port states, p. 34-36 */
end_comment

begin_define
define|#
directive|define
name|NS_O
value|0
end_define

begin_comment
comment|/* open */
end_comment

begin_define
define|#
directive|define
name|NS_CR
value|1
end_define

begin_comment
comment|/* connect received */
end_comment

begin_define
define|#
directive|define
name|NS_DR
value|2
end_define

begin_comment
comment|/* disconnect reject */
end_comment

begin_define
define|#
directive|define
name|NS_DRC
value|3
end_define

begin_comment
comment|/* disconnect reject complete */
end_comment

begin_define
define|#
directive|define
name|NS_CC
value|4
end_define

begin_comment
comment|/* connect confirm */
end_comment

begin_define
define|#
directive|define
name|NS_CI
value|5
end_define

begin_comment
comment|/* connect initiate */
end_comment

begin_define
define|#
directive|define
name|NS_NR
value|6
end_define

begin_comment
comment|/* no resources */
end_comment

begin_define
define|#
directive|define
name|NS_NC
value|7
end_define

begin_comment
comment|/* no communication */
end_comment

begin_define
define|#
directive|define
name|NS_CD
value|8
end_define

begin_comment
comment|/* connect delivered */
end_comment

begin_define
define|#
directive|define
name|NS_RJ
value|9
end_define

begin_comment
comment|/* rejected */
end_comment

begin_define
define|#
directive|define
name|NS_RUN
value|10
end_define

begin_comment
comment|/* running */
end_comment

begin_define
define|#
directive|define
name|NS_DI
value|11
end_define

begin_comment
comment|/* disconnect initiate */
end_comment

begin_define
define|#
directive|define
name|NS_DIC
value|12
end_define

begin_comment
comment|/* disconnect complete */
end_comment

begin_define
define|#
directive|define
name|NS_DN
value|13
end_define

begin_comment
comment|/* disconnect notification */
end_comment

begin_define
define|#
directive|define
name|NS_CL
value|14
end_define

begin_comment
comment|/* closed */
end_comment

begin_define
define|#
directive|define
name|NS_CN
value|15
end_define

begin_comment
comment|/* closed notification */
end_comment

begin_define
define|#
directive|define
name|NS_LI
value|16
end_define

begin_comment
comment|/* listen for connection */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|NF_DATACK
value|0001
end_define

begin_comment
comment|/* data acknowledgement required */
end_comment

begin_define
define|#
directive|define
name|NF_OTHACK
value|0002
end_define

begin_comment
comment|/* other data acknowledgement required */
end_comment

begin_define
define|#
directive|define
name|NF_CON
value|0004
end_define

begin_comment
comment|/* connect data available */
end_comment

begin_define
define|#
directive|define
name|NF_INTAVAIL
value|0010
end_define

begin_comment
comment|/* transmit interrupt data available */
end_comment

begin_define
define|#
directive|define
name|NF_OTHSENT
value|0020
end_define

begin_comment
comment|/* other data message has been sent */
end_comment

begin_define
define|#
directive|define
name|NF_OTHINTR
value|0040
end_define

begin_comment
comment|/* other data message was an interrupt msg */
end_comment

begin_define
define|#
directive|define
name|NF_DATOFF
value|0100
end_define

begin_comment
comment|/* on/off switch for data flow control */
end_comment

begin_comment
comment|/* locint states */
end_comment

begin_comment
comment|/* I STILL DON'T UNDERSTAND THIS WELL ENOUGH */
end_comment

begin_define
define|#
directive|define
name|NFL_EMPTY
value|0
end_define

begin_define
define|#
directive|define
name|NFL_INTR
value|1
end_define

begin_define
define|#
directive|define
name|NFL_SEND
value|2
end_define

end_unit

