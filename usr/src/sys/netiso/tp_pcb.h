begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*   * ARGO TP  *  * $Header: tp_pcb.h,v 5.2 88/11/18 17:09:32 nhall Exp $  * $Source: /usr/argo/sys/netiso/RCS/tp_pcb.h,v $  *	@(#)tp_pcb.h	7.6 (Berkeley) %G% *  *  *   * This file defines the transport protocol control block (tpcb).  * and a bunch of #define values that are used in the tpcb.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TP_PCB__
end_ifndef

begin_define
define|#
directive|define
name|__TP_PCB__
end_define

begin_include
include|#
directive|include
file|"../netiso/tp_param.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_timer.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_user.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|sblock
end_ifndef

begin_include
include|#
directive|include
file|"socketvar.h"
end_include

begin_endif
endif|#
directive|endif
endif|sblock
end_endif

begin_comment
comment|/* NOTE: the code depends on REF_CLOSED> REF_OPEN> the rest, and  * on REF_FREE being zero  *  * Possible improvement:  * think about merging the tp_ref w/ the tpcb and doing a search  * through the tpcb list, from tpb. This would slow down lookup  * during data transfer  * It would be a little nicer also to have something based on the  * clock (like top n bits of the reference is part of the clock, to  * minimize the likelihood  of reuse after a crash)  * also, need to keep the timer servicing part to a minimum (although  * the cost of this is probably independent of whether the timers are  * in the pcb or in an array..  * Last, would have to make the number of timers a function of the amount of  * mbufs available, plus some for the frozen references.  *  * Possible improvement:  * Might not need the ref_state stuff either...  * REF_FREE could correspond to tp_state == CLOSED or nonexistend tpcb,  * REF_OPEN to tp_state anywhere from AK_WAIT or CR_SENT to CLOSING  * REF_OPENING could correspond to LISTENING, because that's the  * way it's used, not because the correspondence is exact.  * REF_CLOSED could correspond to REFWAIT  */
end_comment

begin_define
define|#
directive|define
name|REF_FROZEN
value|3
end_define

begin_comment
comment|/* has ref timer only */
end_comment

begin_define
define|#
directive|define
name|REF_OPEN
value|2
end_define

begin_comment
comment|/* has timers, possibly active */
end_comment

begin_define
define|#
directive|define
name|REF_OPENING
value|1
end_define

begin_comment
comment|/* in use (has a pcb) but no timers */
end_comment

begin_define
define|#
directive|define
name|REF_FREE
value|0
end_define

begin_comment
comment|/* free to reallocate */
end_comment

begin_define
define|#
directive|define
name|N_CTIMERS
value|4
end_define

begin_define
define|#
directive|define
name|N_ETIMERS
value|2
end_define

begin_struct
struct|struct
name|tp_ref
block|{
name|u_char
name|tpr_state
decl_stmt|;
comment|/* values REF_FROZEN, etc. above */
name|struct
name|Ccallout
name|tpr_callout
index|[
name|N_CTIMERS
index|]
decl_stmt|;
comment|/* C timers */
name|struct
name|Ecallout
name|tpr_calltodo
decl_stmt|;
comment|/* list of active E timers */
name|struct
name|tp_pcb
modifier|*
name|tpr_pcb
decl_stmt|;
comment|/* back ptr to PCB */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tp_param
block|{
comment|/* PER system stuff (one static structure instead of a bunch of names) */
name|unsigned
name|tpp_configed
range|:
literal|1
decl_stmt|;
comment|/* Has TP been initialized? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * retransmission control and performance measurement   */
end_comment

begin_struct
struct|struct
name|tp_rtc
block|{
name|struct
name|tp_rtc
modifier|*
name|tprt_next
decl_stmt|;
comment|/* ptr to next rtc structure in the list */
name|SeqNum
name|tprt_seq
decl_stmt|;
comment|/* seq # of this TPDU */
name|int
name|tprt_eot
decl_stmt|;
comment|/* Will this TPDU have the eot bit set? */
name|int
name|tprt_octets
decl_stmt|;
comment|/* # octets in this TPDU */
name|struct
name|mbuf
modifier|*
name|tprt_data
decl_stmt|;
comment|/* ptr to the octets of data */
block|}
struct|;
end_struct

begin_struct
specifier|extern
struct|struct
name|nl_protosw
block|{
name|int
name|nlp_afamily
decl_stmt|;
comment|/* address family */
name|int
function_decl|(
modifier|*
name|nlp_putnetaddr
function_decl|)
parameter_list|()
function_decl|;
comment|/* puts addresses in nl pcb */
name|int
function_decl|(
modifier|*
name|nlp_getnetaddr
function_decl|)
parameter_list|()
function_decl|;
comment|/* gets addresses from nl pcb */
name|int
function_decl|(
modifier|*
name|nlp_putsufx
function_decl|)
parameter_list|()
function_decl|;
comment|/* puts transport suffixes in nl pcb */
name|int
function_decl|(
modifier|*
name|nlp_getsufx
function_decl|)
parameter_list|()
function_decl|;
comment|/* gets transport suffixes from nl pcb */
name|int
function_decl|(
modifier|*
name|nlp_recycle_suffix
function_decl|)
parameter_list|()
function_decl|;
comment|/* clears suffix from nl pcb */
name|int
function_decl|(
modifier|*
name|nlp_mtu
function_decl|)
parameter_list|()
function_decl|;
comment|/* figures out mtu based on nl used */
name|int
function_decl|(
modifier|*
name|nlp_pcbbind
function_decl|)
parameter_list|()
function_decl|;
comment|/* bind to pcb for net level */
name|int
function_decl|(
modifier|*
name|nlp_pcbconn
function_decl|)
parameter_list|()
function_decl|;
comment|/* connect for net level */
name|int
function_decl|(
modifier|*
name|nlp_pcbdisc
function_decl|)
parameter_list|()
function_decl|;
comment|/* disconnect net level */
name|int
function_decl|(
modifier|*
name|nlp_pcbdetach
function_decl|)
parameter_list|()
function_decl|;
comment|/* detach net level pcb */
name|int
function_decl|(
modifier|*
name|nlp_pcballoc
function_decl|)
parameter_list|()
function_decl|;
comment|/* allocate a net level pcb */
name|int
function_decl|(
modifier|*
name|nlp_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* prepare a packet to give to nl */
name|int
function_decl|(
modifier|*
name|nlp_dgoutput
function_decl|)
parameter_list|()
function_decl|;
comment|/* prepare a packet to give to nl */
name|int
function_decl|(
modifier|*
name|nlp_ctloutput
function_decl|)
parameter_list|()
function_decl|;
comment|/* hook for network set/get options */
name|caddr_t
name|nlp_pcblist
decl_stmt|;
comment|/* list of xx_pcb's for connections */
block|}
name|nl_protosw
index|[]
struct|;
end_struct

begin_struct
struct|struct
name|tp_pcb
block|{
name|u_short
name|tp_state
decl_stmt|;
comment|/* state of fsm */
name|short
name|tp_retrans
decl_stmt|;
comment|/* # times can still retrans */
name|struct
name|tp_ref
modifier|*
name|tp_refp
decl_stmt|;
comment|/* rest of pcb	*/
name|caddr_t
name|tp_npcb
decl_stmt|;
comment|/* to lower layer pcb */
name|struct
name|nl_protosw
modifier|*
name|tp_nlproto
decl_stmt|;
comment|/* lower-layer dependent routines */
name|struct
name|socket
modifier|*
name|tp_sock
decl_stmt|;
comment|/* back ptr */
name|RefNum
name|tp_lref
decl_stmt|;
comment|/* local reference */
name|RefNum
name|tp_fref
decl_stmt|;
comment|/* foreign reference */
name|u_int
name|tp_seqmask
decl_stmt|;
comment|/* mask for seq space */
name|u_int
name|tp_seqbit
decl_stmt|;
comment|/* bit for seq number wraparound */
name|u_int
name|tp_seqhalf
decl_stmt|;
comment|/* half the seq space */
comment|/* credit& sequencing info for SENDING */
name|u_short
name|tp_fcredit
decl_stmt|;
comment|/* current remote credit in # packets */
name|u_short
name|tp_cong_win
decl_stmt|;
comment|/* congestion window : set to 1 on 										 * source quench 										 * Minimizes the amount of retrans- 										 * missions (independently of the 										 * retrans strategy).  Increased 										 * by one for each good ack received. 										 * Minimizes the amount sent in a 										 * regular tp_send() also. 										 */
name|u_int
name|tp_ackrcvd
decl_stmt|;
comment|/* ACKs received since the send window was updated */
name|SeqNum
name|tp_last_retrans
decl_stmt|;
name|SeqNum
name|tp_retrans_hiwat
decl_stmt|;
name|SeqNum
name|tp_snduna
decl_stmt|;
comment|/* seq # of lowest unacked DT */
name|struct
name|tp_rtc
modifier|*
name|tp_snduna_rtc
decl_stmt|;
comment|/* lowest unacked stuff sent so far */
name|SeqNum
name|tp_sndhiwat
decl_stmt|;
comment|/* highest seq # sent so far */
name|struct
name|tp_rtc
modifier|*
name|tp_sndhiwat_rtc
decl_stmt|;
comment|/* last stuff sent so far */
name|int
name|tp_Nwindow
decl_stmt|;
comment|/* for perf. measurement */
name|struct
name|mbuf
modifier|*
name|tp_ucddata
decl_stmt|;
comment|/* user connect/disconnect data */
comment|/* credit& sequencing info for RECEIVING */
name|SeqNum
name|tp_sent_lcdt
decl_stmt|;
comment|/* cdt according to last ack sent */
name|SeqNum
name|tp_sent_uwe
decl_stmt|;
comment|/* uwe according to last ack sent */
name|SeqNum
name|tp_sent_rcvnxt
decl_stmt|;
comment|/* rcvnxt according to last ack sent  										 * needed for perf measurements only 										 */
name|u_short
name|tp_lcredit
decl_stmt|;
comment|/* current local credit in # packets */
name|SeqNum
name|tp_rcvnxt
decl_stmt|;
comment|/* next DT seq # expect to recv */
name|struct
name|tp_rtc
modifier|*
name|tp_rcvnxt_rtc
decl_stmt|;
comment|/* unacked stuff recvd out of order */
comment|/* receiver congestion state stuff ...  */
name|u_int
name|tp_win_recv
decl_stmt|;
comment|/* receive window as a scaled int (8 bit fraction part) */
struct|struct
name|cong_sample
block|{
name|ushort
name|cs_size
decl_stmt|;
comment|/* current window size */
name|ushort
name|cs_received
decl_stmt|;
comment|/* PDUs received in this sample */
name|ushort
name|cs_ce_set
decl_stmt|;
comment|/* PDUs received in this sample with CE bit set */
block|}
name|tp_cong_sample
struct|;
comment|/* parameters per-connection controllable by user */
name|struct
name|tp_conn_param
name|_tp_param
decl_stmt|;
define|#
directive|define
name|tp_Nretrans
value|_tp_param.p_Nretrans
define|#
directive|define
name|tp_dr_ticks
value|_tp_param.p_dr_ticks
define|#
directive|define
name|tp_cc_ticks
value|_tp_param.p_cc_ticks
define|#
directive|define
name|tp_dt_ticks
value|_tp_param.p_dt_ticks
define|#
directive|define
name|tp_xpd_ticks
value|_tp_param.p_x_ticks
define|#
directive|define
name|tp_cr_ticks
value|_tp_param.p_cr_ticks
define|#
directive|define
name|tp_keepalive_ticks
value|_tp_param.p_keepalive_ticks
define|#
directive|define
name|tp_sendack_ticks
value|_tp_param.p_sendack_ticks
define|#
directive|define
name|tp_refer_ticks
value|_tp_param.p_ref_ticks
define|#
directive|define
name|tp_inact_ticks
value|_tp_param.p_inact_ticks
define|#
directive|define
name|tp_xtd_format
value|_tp_param.p_xtd_format
define|#
directive|define
name|tp_xpd_service
value|_tp_param.p_xpd_service
define|#
directive|define
name|tp_ack_strat
value|_tp_param.p_ack_strat
define|#
directive|define
name|tp_rx_strat
value|_tp_param.p_rx_strat
define|#
directive|define
name|tp_use_checksum
value|_tp_param.p_use_checksum
define|#
directive|define
name|tp_use_efc
value|_tp_param.p_use_efc
define|#
directive|define
name|tp_use_nxpd
value|_tp_param.p_use_nxpd
define|#
directive|define
name|tp_use_rcc
value|_tp_param.p_use_rcc
define|#
directive|define
name|tp_tpdusize
value|_tp_param.p_tpdusize
define|#
directive|define
name|tp_class
value|_tp_param.p_class
define|#
directive|define
name|tp_winsize
value|_tp_param.p_winsize
define|#
directive|define
name|tp_no_disc_indications
value|_tp_param.p_no_disc_indications
define|#
directive|define
name|tp_dont_change_params
value|_tp_param.p_dont_change_params
define|#
directive|define
name|tp_netservice
value|_tp_param.p_netservice
define|#
directive|define
name|tp_version
value|_tp_param.p_version
name|int
name|tp_l_tpdusize
decl_stmt|;
comment|/* whereas tp_tpdusize is log2(the negotiated max size) 		 * l_tpdusize is the size we'll use when sending, in # chars 		 */
name|struct
name|timeval
name|tp_rtv
decl_stmt|;
comment|/* max round-trip time variance */
name|struct
name|timeval
name|tp_rtt
decl_stmt|;
comment|/* smoothed round-trip time */
name|struct
name|timeval
name|tp_rttemit
index|[
name|TP_RTT_NUM
operator|+
literal|1
index|]
decl_stmt|;
comment|/* times that the last TP_RTT_NUM DT_TPDUs were emitted */
name|unsigned
name|tp_sendfcc
range|:
literal|1
decl_stmt|,
comment|/* shall next ack include FCC parameter? */
name|tp_trace
range|:
literal|1
decl_stmt|,
comment|/* is this pcb being traced? (not used yet) */
name|tp_perf_on
range|:
literal|1
decl_stmt|,
comment|/* 0/1 -> performance measuring on  */
name|tp_reneged
range|:
literal|1
decl_stmt|,
comment|/* have we reneged on cdt since last ack? */
name|tp_decbit
range|:
literal|3
decl_stmt|,
comment|/* dec bit was set, we're in reneg mode  */
name|tp_cebit_off
range|:
literal|1
decl_stmt|,
comment|/* the real DEC bit algorithms not in use */
name|tp_flags
range|:
literal|8
decl_stmt|,
comment|/* values: */
define|#
directive|define
name|TPF_CONN_DATA_OUT
value|TPFLAG_CONN_DATA_OUT
define|#
directive|define
name|TPF_CONN_DATA_IN
value|TPFLAG_CONN_DATA_IN
define|#
directive|define
name|TPF_DISC_DATA_IN
value|TPFLAG_DISC_DATA_IN
define|#
directive|define
name|TPF_DISC_DATA_OUT
value|TPFLAG_DISC_DATA_OUT
define|#
directive|define
name|TPF_XPD_PRESENT
value|TPFLAG_XPD_PRESENT
define|#
directive|define
name|TPF_NLQOS_PDN
value|TPFLAG_NLQOS_PDN
define|#
directive|define
name|TPF_PEER_ON_SAMENET
value|TPFLAG_PEER_ON_SAMENET
define|#
directive|define
name|PEER_IS_LOCAL
parameter_list|(
name|t
parameter_list|)
define|\
value|(((t)->tp_flags& TPF_PEER_ON_SAME_NET)==TPF_PEER_ON_SAME_NET)
define|#
directive|define
name|USES_PDN
parameter_list|(
name|t
parameter_list|)
define|\
value|(((t)->tp_flags& TPF_NLQOS_PDN)==TPF_NLQOS_PDN)
name|tp_unused
range|:
literal|16
decl_stmt|;
ifdef|#
directive|ifdef
name|TP_PERF_MEAS
comment|/* performance stats - see tp_stat.h */
name|struct
name|tp_pmeas
modifier|*
name|tp_p_meas
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tp_p_mbuf
decl_stmt|;
endif|#
directive|endif
endif|TP_PERF_MEAS
comment|/* addressing */
name|u_short
name|tp_domain
decl_stmt|;
comment|/* domain (INET, ISO) */
comment|/* for compatibility with the *old* way and with INET, be sure that 	 * that lsuffix and fsuffix are aligned to a short addr. 	 * having them follow the u_short *suffixlen should suffice (choke) 	 */
name|u_short
name|tp_fsuffixlen
decl_stmt|;
comment|/* foreign suffix */
name|char
name|tp_fsuffix
index|[
name|MAX_TSAP_SEL_LEN
index|]
decl_stmt|;
name|u_short
name|tp_lsuffixlen
decl_stmt|;
comment|/* local suffix */
name|char
name|tp_lsuffix
index|[
name|MAX_TSAP_SEL_LEN
index|]
decl_stmt|;
define|#
directive|define
name|SHORT_LSUFXP
parameter_list|(
name|tpcb
parameter_list|)
value|((short *)((tpcb)->tp_lsuffix))
define|#
directive|define
name|SHORT_FSUFXP
parameter_list|(
name|tpcb
parameter_list|)
value|((short *)((tpcb)->tp_fsuffix))
name|u_char
name|tp_vers
decl_stmt|;
comment|/* protocol version */
name|u_char
name|tp_peer_acktime
decl_stmt|;
comment|/* used to compute DT retrans time */
name|struct
name|sockbuf
name|tp_Xsnd
decl_stmt|;
comment|/* for expedited data */
comment|/*	struct sockbuf		tp_Xrcv;		/* for expedited data */
define|#
directive|define
name|tp_Xrcv
value|tp_sock->so_rcv
name|SeqNum
name|tp_Xsndnxt
decl_stmt|;
comment|/* next XPD seq # to send */
name|SeqNum
name|tp_Xuna
decl_stmt|;
comment|/* seq # of unacked XPD */
name|SeqNum
name|tp_Xrcvnxt
decl_stmt|;
comment|/* next XPD seq # expect to recv */
comment|/* AK subsequencing */
name|u_short
name|tp_s_subseq
decl_stmt|;
comment|/* next subseq to send */
name|u_short
name|tp_r_subseq
decl_stmt|;
comment|/* highest recv subseq */
block|}
struct|;
end_struct

begin_decl_stmt
name|u_int
name|tp_start_win
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ROUND
parameter_list|(
name|scaled_int
parameter_list|)
value|(((scaled_int)>> 8) + (((scaled_int)& 0x80) ? 1:0))
end_define

begin_comment
comment|/* to round off a scaled int with an 8 bit fraction part */
end_comment

begin_define
define|#
directive|define
name|CONG_INIT_SAMPLE
parameter_list|(
name|pcb
parameter_list|)
define|\
value|pcb->tp_cong_sample.cs_received = \     pcb->tp_cong_sample.cs_ce_set = 0; \     pcb->tp_cong_sample.cs_size = MAX(pcb->tp_lcredit, 1)<< 1;
end_define

begin_define
define|#
directive|define
name|CONG_UPDATE_SAMPLE
parameter_list|(
name|pcb
parameter_list|,
name|ce_bit
parameter_list|)
define|\
value|pcb->tp_cong_sample.cs_received++; \     if (ce_bit) { \         pcb->tp_cong_sample.cs_ce_set++; \     } \     if (pcb->tp_cong_sample.cs_size<= pcb->tp_cong_sample.cs_received) { \         if ((pcb->tp_cong_sample.cs_ce_set<< 1)>=  \                     pcb->tp_cong_sample.cs_size ) { \             pcb->tp_win_recv -= pcb->tp_win_recv>> 3;
comment|/* multiply by .875 */
value|\             pcb->tp_win_recv = MAX(1<< 8, pcb->tp_win_recv); \         } \         else { \             pcb->tp_win_recv += (1<< 8);
comment|/* add one to the scaled int */
value|\         } \         pcb->tp_lcredit = ROUND(pcb->tp_win_recv); \         CONG_INIT_SAMPLE(pcb); \     }
end_define

begin_define
define|#
directive|define
name|CONG_ACK
parameter_list|(
name|pcb
parameter_list|,
name|seq
parameter_list|)
define|\
value|{ int   newacks = SEQ_SUB(pcb, seq, pcb->tp_snduna); \ 	if (newacks> 0) { \ 		pcb->tp_ackrcvd += newacks; \ 		if (pcb->tp_ackrcvd>= MIN(pcb->tp_fcredit, pcb->tp_cong_win)) { \ 			++pcb->tp_cong_win; \ 			pcb->tp_ackrcvd = 0; \ 		} \ 	} \ }
end_define

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tp_ref
name|tp_ref
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tp_param
name|tp_param
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sototpcb
parameter_list|(
name|so
parameter_list|)
value|((struct tp_pcb *)(so->so_tpcb))
end_define

begin_define
define|#
directive|define
name|sototpref
parameter_list|(
name|so
parameter_list|)
value|((struct tp_ref *)((so)->so_tpcb->tp_ref))
end_define

begin_define
define|#
directive|define
name|tpcbtoso
parameter_list|(
name|tp
parameter_list|)
value|((struct socket *)((tp)->tp_sock))
end_define

begin_define
define|#
directive|define
name|tpcbtoref
parameter_list|(
name|tp
parameter_list|)
value|((struct tp_ref *)((tp)->tp_ref))
end_define

begin_endif
endif|#
directive|endif
endif|__TP_PCB__
end_endif

end_unit

