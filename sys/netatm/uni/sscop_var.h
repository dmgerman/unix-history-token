begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * SSCOP protocol control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SSCOP_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SSCOP_VAR_H
end_define

begin_comment
comment|/*  * Structure containing information for each SSCOP connection.  */
end_comment

begin_struct
struct|struct
name|sscop
block|{
name|struct
name|sscop
modifier|*
name|so_next
decl_stmt|;
comment|/* Next connection in chain */
name|u_char
name|so_state
decl_stmt|;
comment|/* Connection state (see below) */
name|u_short
name|so_flags
decl_stmt|;
comment|/* Connection flags (see below) */
name|enum
name|sscop_vers
name|so_vers
decl_stmt|;
comment|/* SSCOP version */
comment|/* Transmitter variables */
name|sscop_seq
name|so_send
decl_stmt|;
comment|/* VT(S) - next SD to send */
name|sscop_seq
name|so_sendmax
decl_stmt|;
comment|/* VT(MS) - max SD to send + 1 */
name|sscop_seq
name|so_ack
decl_stmt|;
comment|/* VT(A) - next expected ack */
name|sscop_seq
name|so_pollsend
decl_stmt|;
comment|/* VT(PS) - last POLL sent */
name|sscop_seq
name|so_pollack
decl_stmt|;
comment|/* VT(PA) - next expected STAT */
name|short
name|so_polldata
decl_stmt|;
comment|/* VT(PD) - SD's sent between POLLs */
name|short
name|so_connctl
decl_stmt|;
comment|/* VT(CC) - un-ack'd BGN,END,ER,RS */
name|u_char
name|so_sendconn
decl_stmt|;
comment|/* VT(SQ) - last BGN,ER,RS sent */
comment|/* Receiver variables */
name|sscop_seq
name|so_rcvnext
decl_stmt|;
comment|/* VR(R) - next SD to receive */
name|sscop_seq
name|so_rcvhigh
decl_stmt|;
comment|/* VR(H) - next highest SD to receive */
name|sscop_seq
name|so_rcvmax
decl_stmt|;
comment|/* VR(MR) - max SD to receive + 1 */
name|u_char
name|so_rcvconn
decl_stmt|;
comment|/* VR(SQ) - last BGN,ER,RS received */
comment|/* PDU queues */
name|KBuffer
modifier|*
name|so_xmit_hd
decl_stmt|;
comment|/* SD transmission queue head */
name|KBuffer
modifier|*
name|so_xmit_tl
decl_stmt|;
comment|/* SD transmission queue tail */
name|struct
name|pdu_hdr
modifier|*
name|so_rexmit_hd
decl_stmt|;
comment|/* SD retransmission queue head */
name|struct
name|pdu_hdr
modifier|*
name|so_rexmit_tl
decl_stmt|;
comment|/* SD retransmission queue head */
name|struct
name|pdu_hdr
modifier|*
name|so_pack_hd
decl_stmt|;
comment|/* SD pending ack queue head */
name|struct
name|pdu_hdr
modifier|*
name|so_pack_tl
decl_stmt|;
comment|/* SD pending ack queue tail */
name|struct
name|pdu_hdr
modifier|*
name|so_recv_hd
decl_stmt|;
comment|/* SD receive queue head */
name|struct
name|pdu_hdr
modifier|*
name|so_recv_tl
decl_stmt|;
comment|/* SD receive queue tail */
comment|/* Connection parameters */
name|struct
name|sscop_parms
name|so_parm
decl_stmt|;
comment|/* Connection parameters */
comment|/* Timers */
name|u_short
name|so_timer
index|[
name|SSCOP_T_NUM
index|]
decl_stmt|;
comment|/* Connection timers */
comment|/* Stack variables */
name|Atm_connvc
modifier|*
name|so_connvc
decl_stmt|;
comment|/* Connection vcc for this stack */
name|void
modifier|*
name|so_toku
decl_stmt|;
comment|/* Stack upper layer's token */
name|void
modifier|*
name|so_tokl
decl_stmt|;
comment|/* Stack lower layer's token */
name|void
function_decl|(
modifier|*
name|so_upper
function_decl|)
comment|/* Stack upper layer's interface */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|so_lower
function_decl|)
comment|/* Stack lower layer's interface */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|u_short
name|so_headout
decl_stmt|;
comment|/* Output buffer headroom */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Connection States  *  * Notes:  *	#  - state valid only for Q.SAAL1  *      ## - state valid only for Q.2110  */
end_comment

begin_define
define|#
directive|define
name|SOS_INST
value|0
end_define

begin_comment
comment|/* Instantiated, waiting for INIT */
end_comment

begin_define
define|#
directive|define
name|SOS_IDLE
value|1
end_define

begin_comment
comment|/* Idle connection */
end_comment

begin_define
define|#
directive|define
name|SOS_OUTCONN
value|2
end_define

begin_comment
comment|/* Outgoing connection pending */
end_comment

begin_define
define|#
directive|define
name|SOS_INCONN
value|3
end_define

begin_comment
comment|/* Incoming connection pending */
end_comment

begin_define
define|#
directive|define
name|SOS_OUTDISC
value|4
end_define

begin_comment
comment|/* Outgoing disconnection pending */
end_comment

begin_define
define|#
directive|define
name|SOS_OUTRESYN
value|5
end_define

begin_comment
comment|/* Outgoing resynchronization pending */
end_comment

begin_define
define|#
directive|define
name|SOS_INRESYN
value|6
end_define

begin_comment
comment|/* Incoming resynchronization pending */
end_comment

begin_define
define|#
directive|define
name|SOS_CONRESYN
value|7
end_define

begin_comment
comment|/* Concurrent resynch pending (#) */
end_comment

begin_define
define|#
directive|define
name|SOS_OUTRECOV
value|7
end_define

begin_comment
comment|/* Outgoing recovery pending (##) */
end_comment

begin_define
define|#
directive|define
name|SOS_RECOVRSP
value|8
end_define

begin_comment
comment|/* Recovery response pending (##) */
end_comment

begin_define
define|#
directive|define
name|SOS_INRECOV
value|9
end_define

begin_comment
comment|/* Incoming recovery pending (##) */
end_comment

begin_define
define|#
directive|define
name|SOS_READY
value|10
end_define

begin_comment
comment|/* Data transfer ready */
end_comment

begin_define
define|#
directive|define
name|SOS_TERM
value|11
end_define

begin_comment
comment|/* Waiting for TERM */
end_comment

begin_define
define|#
directive|define
name|SOS_MAXSTATE
value|11
end_define

begin_comment
comment|/* Maximum state value */
end_comment

begin_define
define|#
directive|define
name|SOS_NUMSTATES
value|(SOS_MAXSTATE+1)
end_define

begin_comment
comment|/* Number of states */
end_comment

begin_comment
comment|/*  * Connection Flags  */
end_comment

begin_define
define|#
directive|define
name|SOF_NOCLRBUF
value|0x0001
end_define

begin_comment
comment|/* Clear buffers = no */
end_comment

begin_define
define|#
directive|define
name|SOF_REESTAB
value|0x0002
end_define

begin_comment
comment|/* SSCOP initiated reestablishment */
end_comment

begin_define
define|#
directive|define
name|SOF_XMITSRVC
value|0x0004
end_define

begin_comment
comment|/* Transmit queues need servicing */
end_comment

begin_define
define|#
directive|define
name|SOF_KEEPALIVE
value|0x0008
end_define

begin_comment
comment|/* Polling in transient phase */
end_comment

begin_define
define|#
directive|define
name|SOF_ENDSSCOP
value|0x0010
end_define

begin_comment
comment|/* Last END PDU, SOURCE=SSCOP */
end_comment

begin_define
define|#
directive|define
name|SOF_NOCREDIT
value|0x0020
end_define

begin_comment
comment|/* Transmit window closed */
end_comment

begin_comment
comment|/*  * SSCOP statistics  */
end_comment

begin_struct
struct|struct
name|sscop_stat
block|{
name|u_long
name|sos_connects
decl_stmt|;
comment|/* Connection instances */
name|u_long
name|sos_aborts
decl_stmt|;
comment|/* Connection aborts */
name|u_long
name|sos_maa_error
index|[
name|MAA_ERROR_COUNT
index|]
decl_stmt|;
comment|/* Management errors */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* sscop.c */
end_comment

begin_function_decl
name|int
name|sscop_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_maa_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_abort
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscop_lower.c */
end_comment

begin_function_decl
name|void
name|sscop_lower
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_aa_noop_0
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_aa_noop_1
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_init_inst
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_term_all
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscop_pdu.c */
end_comment

begin_function_decl
name|int
name|sscop_send_bgn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_bgak
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_bgrej
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_end
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_endak
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_rs
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_rsak
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_er
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_erak
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_poll
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_stat
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|sscop_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_ustat
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|sscop_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_send_ud
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_pdu_print
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscop_sigaa.c */
end_comment

begin_function_decl
name|void
name|sscop_estreq_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_estrsp_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_relreq_outconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_relreq_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_relreq_ready
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_datreq_ready
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_udtreq_all
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscop_sigcpcs.c */
end_comment

begin_function_decl
name|void
name|sscop_noop
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgn_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgn_outdisc
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgn_outresyn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgn_inresyn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgak_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgak_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgak_outconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgrej_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgrej_outconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgrej_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgrej_outresyn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_bgrej_ready
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_end_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_end_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_end_outdisc
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_endak_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_endak_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_endak_outdisc
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_endak_ready
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_rs_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_rs_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_rsak_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_rsak_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_rsak_outresyn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_sd_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_sd_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_sd_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_poll_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_poll_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_poll_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_stat_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_stat_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_stat_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_stat_ready
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_ustat_error
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_ustat_idle
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_ustat_inconn
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_ustat_ready
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_ud_all
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_md_all
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscop_subr.c */
end_comment

begin_function_decl
name|KBuffer
modifier|*
name|sscop_stat_getelem
parameter_list|(
name|KBuffer
modifier|*
parameter_list|,
name|sscop_seq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pdu_hdr
modifier|*
name|sscop_pack_locate
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|sscop_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_pack_free
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|sscop_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_rexmit_insert
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|struct
name|pdu_hdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_rexmit_unlink
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|struct
name|pdu_hdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_xmit_drain
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_recv_insert
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|struct
name|pdu_hdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_rcvr_drain
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_service_xmit
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscop_is_rexmit
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_set_poll
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscop_timer.c */
end_comment

begin_function_decl
name|void
name|sscop_timeout
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sscop_upper.c */
end_comment

begin_function_decl
name|void
name|sscop_upper
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* q2110_sigaa.c */
end_comment

begin_comment
comment|/* q2110_sigcpcs.c */
end_comment

begin_comment
comment|/* q2110_subr.c */
end_comment

begin_function_decl
name|void
name|q2110_clear_xmit
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|q2110_init_state
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|q2110_prep_retrieve
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|q2110_prep_recovery
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|q2110_deliver_data
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|q2110_error_recovery
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* qsaal1_sigaa.c */
end_comment

begin_comment
comment|/* qsaal1_sigcpcs.c */
end_comment

begin_comment
comment|/* qsaal1_subr.c */
end_comment

begin_function_decl
name|void
name|qsaal1_reestablish
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qsaal1_reset_xmit
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qsaal1_reset_rcvr
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qsaal1_clear_connection
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * External variables  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|sscop_pool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sscop_vccnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sscop
modifier|*
name|sscop_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sscop_stat
name|sscop_stat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|atm_time
name|sscop_timer
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern void		(*(*sscop_qsaal_aatab[]
end_extern

begin_expr_stmt
unit|))
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|int
operator|,
name|int
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void		(*(*sscop_q2110_aatab[]
end_extern

begin_expr_stmt
unit|))
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|int
operator|,
name|int
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void		(*(*sscop_qsaal_pdutab[]
end_extern

begin_expr_stmt
unit|))
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void		(*(*sscop_q2110_pdutab[]
end_extern

begin_expr_stmt
unit|))
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
expr_stmt|;
end_expr_stmt

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
comment|/* _UNI_SSCOP_VAR_H */
end_comment

end_unit

