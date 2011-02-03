begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2008, by Cisco Systems, Inc. All rights reserved.  * Copyright (c) 2008-2011, by Randall Stewart, rrs@lakerest.net and  *                          Michael Tuexen, tuexen@fh-muenster.de  *                          All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $KAME: sctp_structs.h,v 1.13 2005/03/06 16:04:18 itojun Exp $	 */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__sctp_structs_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_structs_h__
end_define

begin_include
include|#
directive|include
file|<netinet/sctp_os.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp_header.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp_auth.h>
end_include

begin_struct
struct|struct
name|sctp_timer
block|{
name|sctp_os_timer_t
name|timer
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* 	 * Depending on the timer type these will be setup and cast with the 	 * appropriate entity. 	 */
name|void
modifier|*
name|ep
decl_stmt|;
name|void
modifier|*
name|tcb
decl_stmt|;
name|void
modifier|*
name|net
decl_stmt|;
name|void
modifier|*
name|vnet
decl_stmt|;
comment|/* for sanity checking */
name|void
modifier|*
name|self
decl_stmt|;
name|uint32_t
name|ticks
decl_stmt|;
name|uint32_t
name|stopped_from
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_foo_stuff
block|{
name|struct
name|sctp_inpcb
modifier|*
name|inp
decl_stmt|;
name|uint32_t
name|lineno
decl_stmt|;
name|uint32_t
name|ticks
decl_stmt|;
name|int
name|updown
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the information we track on each interface that we know about from  * the distant end.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctpnetlisthead
argument_list|,
name|sctp_nets
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sctp_stream_reset_list
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sctp_stream_reset_list
argument_list|)
name|next_resp
expr_stmt|;
name|uint32_t
name|tsn
decl_stmt|;
name|int
name|number_entries
decl_stmt|;
name|struct
name|sctp_stream_reset_out_request
name|req
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctp_resethead
argument_list|,
name|sctp_stream_reset_list
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Users of the iterator need to malloc a iterator with a call to  * sctp_initiate_iterator(inp_func, assoc_func, inp_func,  pcb_flags, pcb_features,  *     asoc_state, void-ptr-arg, uint32-arg, end_func, inp);  *  * Use the following two defines if you don't care what pcb flags are on the EP  * and/or you don't care what state the association is in.  *  * Note that if you specify an INP as the last argument then ONLY each  * association of that single INP will be executed upon. Note that the pcb  * flags STILL apply so if the inp you specify has different pcb_flags then  * what you put in pcb_flags nothing will happen. use SCTP_PCB_ANY_FLAGS to  * assure the inp you specify gets treated.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_ANY_FLAGS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_ANY_FEATURES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCTP_ASOC_ANY_STATE
value|0x00000000
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|asoc_func
function_decl|)
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|inp_func
function_decl|)
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|end_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|SCTP_MCORE_INPUT
argument_list|)
operator|&&
name|defined
argument_list|(
name|SMP
argument_list|)
end_if

begin_comment
comment|/* whats on the mcore control struct */
end_comment

begin_struct
struct|struct
name|sctp_mcore_queue
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sctp_mcore_queue
argument_list|)
name|next
expr_stmt|;
name|struct
name|vnet
modifier|*
name|vn
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|int
name|off
decl_stmt|;
name|int
name|v6
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctp_mcore_qhead
argument_list|,
name|sctp_mcore_queue
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sctp_mcore_ctrl
block|{
name|SCTP_PROCESS_STRUCT
name|thread_proc
decl_stmt|;
name|struct
name|sctp_mcore_qhead
name|que
decl_stmt|;
name|struct
name|mtx
name|core_mtx
decl_stmt|;
name|struct
name|mtx
name|que_mtx
decl_stmt|;
name|int
name|running
decl_stmt|;
name|int
name|cpuid
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|sctp_iterator
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sctp_iterator
argument_list|)
name|sctp_nxt_itr
expr_stmt|;
name|struct
name|vnet
modifier|*
name|vn
decl_stmt|;
name|struct
name|sctp_timer
name|tmr
decl_stmt|;
name|struct
name|sctp_inpcb
modifier|*
name|inp
decl_stmt|;
comment|/* current endpoint */
name|struct
name|sctp_tcb
modifier|*
name|stcb
decl_stmt|;
comment|/* current* assoc */
name|struct
name|sctp_inpcb
modifier|*
name|next_inp
decl_stmt|;
comment|/* special hook to skip to */
name|asoc_func
name|function_assoc
decl_stmt|;
comment|/* per assoc function */
name|inp_func
name|function_inp
decl_stmt|;
comment|/* per endpoint function */
name|inp_func
name|function_inp_end
decl_stmt|;
comment|/* end INP function */
name|end_func
name|function_atend
decl_stmt|;
comment|/* iterator completion function */
name|void
modifier|*
name|pointer
decl_stmt|;
comment|/* pointer for apply func to use */
name|uint32_t
name|val
decl_stmt|;
comment|/* value for apply func to use */
name|uint32_t
name|pcb_flags
decl_stmt|;
comment|/* endpoint flags being checked */
name|uint32_t
name|pcb_features
decl_stmt|;
comment|/* endpoint features being checked */
name|uint32_t
name|asoc_state
decl_stmt|;
comment|/* assoc state being checked */
name|uint32_t
name|iterator_flags
decl_stmt|;
name|uint8_t
name|no_chunk_output
decl_stmt|;
name|uint8_t
name|done_current_ep
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* iterator_flags values */
end_comment

begin_define
define|#
directive|define
name|SCTP_ITERATOR_DO_ALL_INP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_ITERATOR_DO_SINGLE_INP
value|0x00000002
end_define

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctpiterators
argument_list|,
name|sctp_iterator
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sctp_copy_all
block|{
name|struct
name|sctp_inpcb
modifier|*
name|inp
decl_stmt|;
comment|/* ep */
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|sctp_sndrcvinfo
name|sndrcv
decl_stmt|;
name|int
name|sndlen
decl_stmt|;
name|int
name|cnt_sent
decl_stmt|;
name|int
name|cnt_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_asconf_iterator
block|{
name|struct
name|sctpladdr
name|list_of_work
decl_stmt|;
name|int
name|cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iterator_control
block|{
name|struct
name|mtx
name|ipi_iterator_wq_mtx
decl_stmt|;
name|struct
name|mtx
name|it_mtx
decl_stmt|;
name|SCTP_PROCESS_STRUCT
name|thread_proc
decl_stmt|;
name|struct
name|sctpiterators
name|iteratorhead
decl_stmt|;
name|struct
name|sctp_iterator
modifier|*
name|cur_it
decl_stmt|;
name|uint32_t
name|iterator_running
decl_stmt|;
name|uint32_t
name|iterator_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_ITERATOR_MUST_EXIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_ITERATOR_STOP_CUR_IT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_ITERATOR_STOP_CUR_INP
value|0x00000004
end_define

begin_struct
struct|struct
name|sctp_net_route
block|{
name|sctp_rtentry_t
modifier|*
name|ro_rt
decl_stmt|;
name|void
modifier|*
name|ro_lle
decl_stmt|;
name|union
name|sctp_sockstore
name|_l_addr
decl_stmt|;
comment|/* remote peer addr */
name|struct
name|sctp_ifa
modifier|*
name|_s_addr
decl_stmt|;
comment|/* our selected src addr */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|htcp
block|{
name|uint16_t
name|alpha
decl_stmt|;
comment|/* Fixed point arith,<< 7 */
name|uint8_t
name|beta
decl_stmt|;
comment|/* Fixed point arith,<< 7 */
name|uint8_t
name|modeswitch
decl_stmt|;
comment|/* Delay modeswitch until we had at least one 				 * congestion event */
name|uint32_t
name|last_cong
decl_stmt|;
comment|/* Time since last congestion event end */
name|uint32_t
name|undo_last_cong
decl_stmt|;
name|uint16_t
name|bytes_acked
decl_stmt|;
name|uint32_t
name|bytecount
decl_stmt|;
name|uint32_t
name|minRTT
decl_stmt|;
name|uint32_t
name|maxRTT
decl_stmt|;
name|uint32_t
name|undo_maxRTT
decl_stmt|;
name|uint32_t
name|undo_old_maxB
decl_stmt|;
comment|/* Bandwidth estimation */
name|uint32_t
name|minB
decl_stmt|;
name|uint32_t
name|maxB
decl_stmt|;
name|uint32_t
name|old_maxB
decl_stmt|;
name|uint32_t
name|Bi
decl_stmt|;
name|uint32_t
name|lasttime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_nets
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sctp_nets
argument_list|)
name|sctp_next
expr_stmt|;
comment|/* next link */
comment|/* 	 * Things on the top half may be able to be split into a common 	 * structure shared by all. 	 */
name|struct
name|sctp_timer
name|pmtu_timer
decl_stmt|;
comment|/* 	 * The following two in combination equate to a route entry for v6 	 * or v4. 	 */
name|struct
name|sctp_net_route
name|ro
decl_stmt|;
comment|/* mtu discovered so far */
name|uint32_t
name|mtu
decl_stmt|;
name|uint32_t
name|ssthresh
decl_stmt|;
comment|/* not sure about this one for split */
name|uint32_t
name|last_cwr_tsn
decl_stmt|;
name|uint32_t
name|cwr_window_tsn
decl_stmt|;
name|uint32_t
name|ecn_ce_pkt_cnt
decl_stmt|;
name|uint32_t
name|lost_cnt
decl_stmt|;
comment|/* smoothed average things for RTT and RTO itself */
name|int
name|lastsa
decl_stmt|;
name|int
name|lastsv
decl_stmt|;
name|int
name|rtt
decl_stmt|;
comment|/* last measured rtt value in ms */
name|unsigned
name|int
name|RTO
decl_stmt|;
comment|/* This is used for SHUTDOWN/SHUTDOWN-ACK/SEND or INIT timers */
name|struct
name|sctp_timer
name|rxt_timer
decl_stmt|;
name|struct
name|sctp_timer
name|fr_timer
decl_stmt|;
comment|/* for early fr */
comment|/* last time in seconds I sent to it */
name|struct
name|timeval
name|last_sent_time
decl_stmt|;
name|int
name|ref_count
decl_stmt|;
comment|/* Congestion stats per destination */
comment|/* 	 * flight size variables and such, sorry Vern, I could not avoid 	 * this if I wanted performance :> 	 */
name|uint32_t
name|flight_size
decl_stmt|;
name|uint32_t
name|cwnd
decl_stmt|;
comment|/* actual cwnd */
name|uint32_t
name|prev_cwnd
decl_stmt|;
comment|/* cwnd before any processing */
name|uint32_t
name|ecn_prev_cwnd
decl_stmt|;
comment|/* ECN prev cwnd at first ecn_echo seen in new 				 * window */
name|uint32_t
name|partial_bytes_acked
decl_stmt|;
comment|/* in CA tracks when to incr a MTU */
name|uint32_t
name|prev_rtt
decl_stmt|;
comment|/* tracking variables to avoid the aloc/free in sack processing */
name|unsigned
name|int
name|net_ack
decl_stmt|;
name|unsigned
name|int
name|net_ack2
decl_stmt|;
comment|/* 	 * JRS - 5/8/07 - Variable to track last time a destination was 	 * active for CMT PF 	 */
name|uint32_t
name|last_active
decl_stmt|;
comment|/* 	 * CMT variables (iyengar@cis.udel.edu) 	 */
name|uint32_t
name|this_sack_highest_newack
decl_stmt|;
comment|/* tracks highest TSN newly 						 * acked for a given dest in 						 * the current SACK. Used in 						 * SFR and HTNA algos */
name|uint32_t
name|pseudo_cumack
decl_stmt|;
comment|/* CMT CUC algorithm. Maintains next expected 				 * pseudo-cumack for this destination */
name|uint32_t
name|rtx_pseudo_cumack
decl_stmt|;
comment|/* CMT CUC algorithm. Maintains next 					 * expected pseudo-cumack for this 					 * destination */
comment|/* CMT fast recovery variables */
name|uint32_t
name|fast_recovery_tsn
decl_stmt|;
name|uint32_t
name|heartbeat_random1
decl_stmt|;
name|uint32_t
name|heartbeat_random2
decl_stmt|;
name|uint32_t
name|tos_flowlabel
decl_stmt|;
name|struct
name|timeval
name|start_time
decl_stmt|;
comment|/* time when this net was created */
name|struct
name|timeval
name|last_measured_rtt
decl_stmt|;
name|uint32_t
name|marked_retrans
decl_stmt|;
comment|/* number or DATA chunks marked for timer 				 * based retransmissions */
name|uint32_t
name|marked_fastretrans
decl_stmt|;
comment|/* if this guy is ok or not ... status */
name|uint16_t
name|dest_state
decl_stmt|;
comment|/* number of transmit failures to down this guy */
name|uint16_t
name|failure_threshold
decl_stmt|;
comment|/* error stats on destination */
name|uint16_t
name|error_count
decl_stmt|;
comment|/* UDP port number in case of UDP tunneling */
name|uint16_t
name|port
decl_stmt|;
name|uint8_t
name|fast_retran_loss_recovery
decl_stmt|;
name|uint8_t
name|will_exit_fast_recovery
decl_stmt|;
comment|/* Flags that probably can be combined into dest_state */
name|uint8_t
name|fast_retran_ip
decl_stmt|;
comment|/* fast retransmit in progress */
name|uint8_t
name|hb_responded
decl_stmt|;
name|uint8_t
name|saw_newack
decl_stmt|;
comment|/* CMT's SFR algorithm flag */
name|uint8_t
name|src_addr_selected
decl_stmt|;
comment|/* if we split we move */
name|uint8_t
name|indx_of_eligible_next_to_use
decl_stmt|;
name|uint8_t
name|addr_is_local
decl_stmt|;
comment|/* its a local address (if known) could move 				 * in split */
comment|/* 	 * CMT variables (iyengar@cis.udel.edu) 	 */
name|uint8_t
name|find_pseudo_cumack
decl_stmt|;
comment|/* CMT CUC algorithm. Flag used to 					 * find a new pseudocumack. This flag 					 * is set after a new pseudo-cumack 					 * has been received and indicates 					 * that the sender should find the 					 * next pseudo-cumack expected for 					 * this destination */
name|uint8_t
name|find_rtx_pseudo_cumack
decl_stmt|;
comment|/* CMT CUCv2 algorithm. Flag used to 					 * find a new rtx-pseudocumack. This 					 * flag is set after a new 					 * rtx-pseudo-cumack has been received 					 * and indicates that the sender 					 * should find the next 					 * rtx-pseudo-cumack expected for this 					 * destination */
name|uint8_t
name|new_pseudo_cumack
decl_stmt|;
comment|/* CMT CUC algorithm. Flag used to 					 * indicate if a new pseudo-cumack or 					 * rtx-pseudo-cumack has been received */
name|uint8_t
name|window_probe
decl_stmt|;
comment|/* Doing a window probe? */
name|uint8_t
name|RTO_measured
decl_stmt|;
comment|/* Have we done the first measure */
name|uint8_t
name|last_hs_used
decl_stmt|;
comment|/* index into the last HS table entry we used */
name|uint8_t
name|lan_type
decl_stmt|;
comment|/* JRS - struct used in HTCP algorithm */
name|struct
name|htcp
name|htcp_ca
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_data_chunkrec
block|{
name|uint32_t
name|TSN_seq
decl_stmt|;
comment|/* the TSN of this transmit */
name|uint16_t
name|stream_seq
decl_stmt|;
comment|/* the stream sequence number of this transmit */
name|uint16_t
name|stream_number
decl_stmt|;
comment|/* the stream number of this guy */
name|uint32_t
name|payloadtype
decl_stmt|;
name|uint32_t
name|context
decl_stmt|;
comment|/* from send */
name|uint32_t
name|cwnd_at_send
decl_stmt|;
comment|/* 	 * part of the Highest sacked algorithm to be able to stroke counts 	 * on ones that are FR'd. 	 */
name|uint32_t
name|fast_retran_tsn
decl_stmt|;
comment|/* sending_seq at the time of FR */
name|struct
name|timeval
name|timetodrop
decl_stmt|;
comment|/* time we drop it from queue */
name|uint8_t
name|doing_fast_retransmit
decl_stmt|;
name|uint8_t
name|rcv_flags
decl_stmt|;
comment|/* flags pulled from data chunk on inbound for 				 * outbound holds sending flags for PR-SCTP. */
name|uint8_t
name|state_flags
decl_stmt|;
name|uint8_t
name|chunk_was_revoked
decl_stmt|;
name|uint8_t
name|fwd_tsn_cnt
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctpchunk_listhead
argument_list|,
name|sctp_tmit_chunk
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The lower byte is used to enumerate PR_SCTP policies */
end_comment

begin_define
define|#
directive|define
name|CHUNK_FLAGS_PR_SCTP_TTL
value|SCTP_PR_SCTP_TTL
end_define

begin_define
define|#
directive|define
name|CHUNK_FLAGS_PR_SCTP_BUF
value|SCTP_PR_SCTP_BUF
end_define

begin_define
define|#
directive|define
name|CHUNK_FLAGS_PR_SCTP_RTX
value|SCTP_PR_SCTP_RTX
end_define

begin_comment
comment|/* The upper byte is used a a bit mask */
end_comment

begin_define
define|#
directive|define
name|CHUNK_FLAGS_FRAGMENT_OK
value|0x0100
end_define

begin_struct
struct|struct
name|chk_id
block|{
name|uint16_t
name|id
decl_stmt|;
name|uint16_t
name|can_take_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_tmit_chunk
block|{
union|union
block|{
name|struct
name|sctp_data_chunkrec
name|data
decl_stmt|;
name|struct
name|chk_id
name|chunk_id
decl_stmt|;
block|}
name|rec
union|;
name|struct
name|sctp_association
modifier|*
name|asoc
decl_stmt|;
comment|/* bp to asoc this belongs to */
name|struct
name|timeval
name|sent_rcv_time
decl_stmt|;
comment|/* filled in if RTT being calculated */
name|struct
name|mbuf
modifier|*
name|data
decl_stmt|;
comment|/* pointer to mbuf chain of data */
name|struct
name|mbuf
modifier|*
name|last_mbuf
decl_stmt|;
comment|/* pointer to last mbuf in chain */
name|struct
name|sctp_nets
modifier|*
name|whoTo
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|sctp_tmit_chunk
argument_list|)
name|sctp_next
expr_stmt|;
comment|/* next link */
name|int32_t
name|sent
decl_stmt|;
comment|/* the send status */
name|uint16_t
name|snd_count
decl_stmt|;
comment|/* number of times I sent */
name|uint16_t
name|flags
decl_stmt|;
comment|/* flags, such as FRAGMENT_OK */
name|uint16_t
name|send_size
decl_stmt|;
name|uint16_t
name|book_size
decl_stmt|;
name|uint16_t
name|mbcnt
decl_stmt|;
name|uint16_t
name|auth_keyid
decl_stmt|;
name|uint8_t
name|holds_key_ref
decl_stmt|;
comment|/* flag if auth keyid refcount is held */
name|uint8_t
name|pad_inplace
decl_stmt|;
name|uint8_t
name|do_rtt
decl_stmt|;
name|uint8_t
name|book_size_scale
decl_stmt|;
name|uint8_t
name|no_fr_allowed
decl_stmt|;
name|uint8_t
name|pr_sctp_on
decl_stmt|;
name|uint8_t
name|copy_by_ref
decl_stmt|;
name|uint8_t
name|window_probe
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The first part of this structure MUST be the entire sinfo structure. Maybe  * I should have made it a sub structure... we can circle back later and do  * that if we want.  */
end_comment

begin_struct
struct|struct
name|sctp_queued_to_read
block|{
comment|/* sinfo structure Pluse more */
name|uint16_t
name|sinfo_stream
decl_stmt|;
comment|/* off the wire */
name|uint16_t
name|sinfo_ssn
decl_stmt|;
comment|/* off the wire */
name|uint16_t
name|sinfo_flags
decl_stmt|;
comment|/* SCTP_UNORDERED from wire use SCTP_EOF for 				 * EOR */
name|uint32_t
name|sinfo_ppid
decl_stmt|;
comment|/* off the wire */
name|uint32_t
name|sinfo_context
decl_stmt|;
comment|/* pick this up from assoc def context? */
name|uint32_t
name|sinfo_timetolive
decl_stmt|;
comment|/* not used by kernel */
name|uint32_t
name|sinfo_tsn
decl_stmt|;
comment|/* Use this in reassembly as first TSN */
name|uint32_t
name|sinfo_cumtsn
decl_stmt|;
comment|/* Use this in reassembly as last TSN */
name|sctp_assoc_t
name|sinfo_assoc_id
decl_stmt|;
comment|/* our assoc id */
comment|/* Non sinfo stuff */
name|uint32_t
name|length
decl_stmt|;
comment|/* length of data */
name|uint32_t
name|held_length
decl_stmt|;
comment|/* length held in sb */
name|struct
name|sctp_nets
modifier|*
name|whoFrom
decl_stmt|;
comment|/* where it came from */
name|struct
name|mbuf
modifier|*
name|data
decl_stmt|;
comment|/* front of the mbuf chain of data with 				 * PKT_HDR */
name|struct
name|mbuf
modifier|*
name|tail_mbuf
decl_stmt|;
comment|/* used for multi-part data */
name|struct
name|mbuf
modifier|*
name|aux_data
decl_stmt|;
comment|/* used to hold/cache  control if o/s does not 				 * take it from us */
name|struct
name|sctp_tcb
modifier|*
name|stcb
decl_stmt|;
comment|/* assoc, used for window update */
name|TAILQ_ENTRY
argument_list|(
argument|sctp_queued_to_read
argument_list|)
name|next
expr_stmt|;
name|uint16_t
name|port_from
decl_stmt|;
name|uint16_t
name|spec_flags
decl_stmt|;
comment|/* Flags to hold the notification field */
name|uint8_t
name|do_not_ref_stcb
decl_stmt|;
name|uint8_t
name|end_added
decl_stmt|;
name|uint8_t
name|pdapi_aborted
decl_stmt|;
name|uint8_t
name|some_taken
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This data structure will be on the outbound  * stream queues. Data will be pulled off from  * the front of the mbuf data and chunk-ified  * by the output routines. We will custom  * fit every chunk we pull to the send/sent  * queue to make up the next full packet  * if we can. An entry cannot be removed  * from the stream_out queue until  * the msg_is_complete flag is set. This  * means at times data/tail_mbuf MIGHT  * be NULL.. If that occurs it happens  * for one of two reasons. Either the user  * is blocked on a send() call and has not  * awoken to copy more data down... OR  * the user is in the explict MSG_EOR mode  * and wrote some data, but has not completed  * sending.  */
end_comment

begin_struct
struct|struct
name|sctp_stream_queue_pending
block|{
name|struct
name|mbuf
modifier|*
name|data
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tail_mbuf
decl_stmt|;
name|struct
name|timeval
name|ts
decl_stmt|;
name|struct
name|sctp_nets
modifier|*
name|net
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|sctp_stream_queue_pending
argument_list|)
name|next
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|sctp_stream_queue_pending
argument_list|)
name|ss_next
expr_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|timetolive
decl_stmt|;
name|uint32_t
name|ppid
decl_stmt|;
name|uint32_t
name|context
decl_stmt|;
name|uint16_t
name|sinfo_flags
decl_stmt|;
name|uint16_t
name|stream
decl_stmt|;
name|uint16_t
name|strseq
decl_stmt|;
name|uint16_t
name|act_flags
decl_stmt|;
name|uint16_t
name|auth_keyid
decl_stmt|;
name|uint8_t
name|holds_key_ref
decl_stmt|;
name|uint8_t
name|msg_is_complete
decl_stmt|;
name|uint8_t
name|some_taken
decl_stmt|;
name|uint8_t
name|pr_sctp_on
decl_stmt|;
name|uint8_t
name|sender_all_done
decl_stmt|;
name|uint8_t
name|put_last_out
decl_stmt|;
name|uint8_t
name|discard_rest
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * this struct contains info that is used to track inbound stream data and  * help with ordering.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctpwheelunrel_listhead
argument_list|,
name|sctp_stream_in
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sctp_stream_in
block|{
name|struct
name|sctp_readhead
name|inqueue
decl_stmt|;
name|uint16_t
name|stream_no
decl_stmt|;
name|uint16_t
name|last_sequence_delivered
decl_stmt|;
comment|/* used for re-order */
name|uint8_t
name|delivery_started
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctpwheel_listhead
argument_list|,
name|sctp_stream_out
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctplist_listhead
argument_list|,
name|sctp_stream_queue_pending
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Round-robin schedulers */
end_comment

begin_struct
struct|struct
name|ss_rr
block|{
comment|/* next link in wheel */
name|TAILQ_ENTRY
argument_list|(
argument|sctp_stream_out
argument_list|)
name|next_spoke
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Priority scheduler */
end_comment

begin_struct
struct|struct
name|ss_prio
block|{
comment|/* next link in wheel */
name|TAILQ_ENTRY
argument_list|(
argument|sctp_stream_out
argument_list|)
name|next_spoke
expr_stmt|;
comment|/* priority id */
name|uint16_t
name|priority
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Fair Bandwidth scheduler */
end_comment

begin_struct
struct|struct
name|ss_fb
block|{
comment|/* next link in wheel */
name|TAILQ_ENTRY
argument_list|(
argument|sctp_stream_out
argument_list|)
name|next_spoke
expr_stmt|;
comment|/* stores message size */
name|int32_t
name|rounds
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This union holds all data necessary for  * different stream schedulers.  */
end_comment

begin_union
union|union
name|scheduling_data
block|{
name|struct
name|sctpwheel_listhead
name|out_wheel
decl_stmt|;
name|struct
name|sctplist_listhead
name|out_list
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * This union holds all parameters per stream  * necessary for different stream schedulers.  */
end_comment

begin_union
union|union
name|scheduling_parameters
block|{
name|struct
name|ss_rr
name|rr
decl_stmt|;
name|struct
name|ss_prio
name|prio
decl_stmt|;
name|struct
name|ss_fb
name|fb
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* This struct is used to track the traffic on outbound streams */
end_comment

begin_struct
struct|struct
name|sctp_stream_out
block|{
name|struct
name|sctp_streamhead
name|outqueue
decl_stmt|;
name|union
name|scheduling_parameters
name|ss_params
decl_stmt|;
name|uint16_t
name|stream_no
decl_stmt|;
name|uint16_t
name|next_sequence_sent
decl_stmt|;
comment|/* next one I expect to send out */
name|uint8_t
name|last_msg_incomplete
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* used to keep track of the addresses yet to try to add/delete */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctp_asconf_addrhead
argument_list|,
name|sctp_asconf_addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sctp_asconf_addr
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sctp_asconf_addr
argument_list|)
name|next
expr_stmt|;
name|struct
name|sctp_asconf_addr_param
name|ap
decl_stmt|;
name|struct
name|sctp_ifa
modifier|*
name|ifa
decl_stmt|;
comment|/* save the ifa for add/del ip */
name|uint8_t
name|sent
decl_stmt|;
comment|/* has this been sent yet? */
name|uint8_t
name|special_del
decl_stmt|;
comment|/* not to be used in lookup */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_scoping
block|{
name|uint8_t
name|ipv4_addr_legal
decl_stmt|;
name|uint8_t
name|ipv6_addr_legal
decl_stmt|;
name|uint8_t
name|loopback_scope
decl_stmt|;
name|uint8_t
name|ipv4_local_scope
decl_stmt|;
name|uint8_t
name|local_scope
decl_stmt|;
name|uint8_t
name|site_scope
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_TSN_LOG_SIZE
value|40
end_define

begin_struct
struct|struct
name|sctp_tsn_log
block|{
name|void
modifier|*
name|stcb
decl_stmt|;
name|uint32_t
name|tsn
decl_stmt|;
name|uint16_t
name|strm
decl_stmt|;
name|uint16_t
name|seq
decl_stmt|;
name|uint16_t
name|sz
decl_stmt|;
name|uint16_t
name|flgs
decl_stmt|;
name|uint16_t
name|in_pos
decl_stmt|;
name|uint16_t
name|in_out
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_FS_SPEC_LOG_SIZE
value|200
end_define

begin_struct
struct|struct
name|sctp_fs_spec_log
block|{
name|uint32_t
name|sent
decl_stmt|;
name|uint32_t
name|total_flight
decl_stmt|;
name|uint32_t
name|tsn
decl_stmt|;
name|uint16_t
name|book
decl_stmt|;
name|uint8_t
name|incr
decl_stmt|;
name|uint8_t
name|decr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This struct is here to cut out the compatiabilty  * pad that bulks up both the inp and stcb. The non  * pad portion MUST stay in complete sync with  * sctp_sndrcvinfo... i.e. if sinfo_xxxx is added  * this must be done here too.  */
end_comment

begin_struct
struct|struct
name|sctp_nonpad_sndrcvinfo
block|{
name|uint16_t
name|sinfo_stream
decl_stmt|;
name|uint16_t
name|sinfo_ssn
decl_stmt|;
name|uint16_t
name|sinfo_flags
decl_stmt|;
name|uint32_t
name|sinfo_ppid
decl_stmt|;
name|uint32_t
name|sinfo_context
decl_stmt|;
name|uint32_t
name|sinfo_timetolive
decl_stmt|;
name|uint32_t
name|sinfo_tsn
decl_stmt|;
name|uint32_t
name|sinfo_cumtsn
decl_stmt|;
name|sctp_assoc_t
name|sinfo_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * JRS - Structure to hold function pointers to the functions responsible  * for congestion control.  */
end_comment

begin_struct
struct|struct
name|sctp_cc_functions
block|{
name|void
function_decl|(
modifier|*
name|sctp_set_initial_cc_param
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_cwnd_update_after_sack
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|,
name|int
name|accum_moved
parameter_list|,
name|int
name|reneged_all
parameter_list|,
name|int
name|will_exit
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_cwnd_update_after_fr
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_cwnd_update_after_timeout
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_cwnd_update_after_ecn_echo
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|,
name|int
name|in_window
parameter_list|,
name|int
name|num_pkt_lost
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_cwnd_update_after_packet_dropped
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|,
name|struct
name|sctp_pktdrop_chunk
modifier|*
name|cp
parameter_list|,
name|uint32_t
modifier|*
name|bottle_bw
parameter_list|,
name|uint32_t
modifier|*
name|on_queue
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_cwnd_update_after_output
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|,
name|int
name|burst_limit
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_cwnd_update_after_fr_timer
function_decl|)
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
name|inp
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RS - Structure to hold function pointers to the functions responsible  * for stream scheduling.  */
end_comment

begin_struct
struct|struct
name|sctp_ss_functions
block|{
name|void
function_decl|(
modifier|*
name|sctp_ss_init
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|,
name|int
name|holds_lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_ss_clear
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|,
name|int
name|clear_values
parameter_list|,
name|int
name|holds_lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_ss_init_stream
function_decl|)
parameter_list|(
name|struct
name|sctp_stream_out
modifier|*
name|strq
parameter_list|,
name|struct
name|sctp_stream_out
modifier|*
name|with_strq
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_ss_add_to_stream
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|,
name|struct
name|sctp_stream_out
modifier|*
name|strq
parameter_list|,
name|struct
name|sctp_stream_queue_pending
modifier|*
name|sp
parameter_list|,
name|int
name|holds_lock
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sctp_ss_is_empty
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_ss_remove_from_stream
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|,
name|struct
name|sctp_stream_out
modifier|*
name|strq
parameter_list|,
name|struct
name|sctp_stream_queue_pending
modifier|*
name|sp
parameter_list|,
name|int
name|holds_lock
parameter_list|)
function_decl|;
name|struct
name|sctp_stream_out
modifier|*
function_decl|(
modifier|*
name|sctp_ss_select_stream
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_ss_scheduled
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|,
name|struct
name|sctp_stream_out
modifier|*
name|strq
parameter_list|,
name|int
name|moved_how_much
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sctp_ss_packet_done
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_nets
modifier|*
name|net
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sctp_ss_get_value
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|,
name|struct
name|sctp_stream_out
modifier|*
name|strq
parameter_list|,
name|uint16_t
modifier|*
name|value
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sctp_ss_set_value
function_decl|)
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
name|stcb
parameter_list|,
name|struct
name|sctp_association
modifier|*
name|asoc
parameter_list|,
name|struct
name|sctp_stream_out
modifier|*
name|strq
parameter_list|,
name|uint16_t
name|value
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* used to save ASCONF chunks for retransmission */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctp_asconf_head
argument_list|,
name|sctp_asconf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sctp_asconf
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sctp_asconf
argument_list|)
name|next
expr_stmt|;
name|uint32_t
name|serial_number
decl_stmt|;
name|uint16_t
name|snd_count
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|data
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* used to save ASCONF-ACK chunks for retransmission */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|sctp_asconf_ackhead
argument_list|,
name|sctp_asconf_ack
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sctp_asconf_ack
block|{
name|TAILQ_ENTRY
argument_list|(
argument|sctp_asconf_ack
argument_list|)
name|next
expr_stmt|;
name|uint32_t
name|serial_number
decl_stmt|;
name|struct
name|sctp_nets
modifier|*
name|last_sent_to
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|data
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Here we have information about each individual association that we track.  * We probably in production would be more dynamic. But for ease of  * implementation we will have a fixed array that we hunt for in a linear  * fashion.  */
end_comment

begin_struct
struct|struct
name|sctp_association
block|{
comment|/* association state */
name|int
name|state
decl_stmt|;
comment|/* queue of pending addrs to add/delete */
name|struct
name|sctp_asconf_addrhead
name|asconf_queue
decl_stmt|;
name|struct
name|timeval
name|time_entered
decl_stmt|;
comment|/* time we entered state */
name|struct
name|timeval
name|time_last_rcvd
decl_stmt|;
name|struct
name|timeval
name|time_last_sent
decl_stmt|;
name|struct
name|timeval
name|time_last_sat_advance
decl_stmt|;
name|struct
name|sctp_nonpad_sndrcvinfo
name|def_send
decl_stmt|;
comment|/* timers and such */
name|struct
name|sctp_timer
name|hb_timer
decl_stmt|;
comment|/* hb timer */
name|struct
name|sctp_timer
name|dack_timer
decl_stmt|;
comment|/* Delayed ack timer */
name|struct
name|sctp_timer
name|asconf_timer
decl_stmt|;
comment|/* asconf */
name|struct
name|sctp_timer
name|strreset_timer
decl_stmt|;
comment|/* stream reset */
name|struct
name|sctp_timer
name|shut_guard_timer
decl_stmt|;
comment|/* shutdown guard */
name|struct
name|sctp_timer
name|autoclose_timer
decl_stmt|;
comment|/* automatic close timer */
name|struct
name|sctp_timer
name|delayed_event_timer
decl_stmt|;
comment|/* timer for delayed events */
name|struct
name|sctp_timer
name|delete_prim_timer
decl_stmt|;
comment|/* deleting primary dst */
comment|/* list of restricted local addresses */
name|struct
name|sctpladdr
name|sctp_restricted_addrs
decl_stmt|;
comment|/* last local address pending deletion (waiting for an address add) */
name|struct
name|sctp_ifa
modifier|*
name|asconf_addr_del_pending
decl_stmt|;
comment|/* Deleted primary destination (used to stop timer) */
name|struct
name|sctp_nets
modifier|*
name|deleted_primary
decl_stmt|;
name|struct
name|sctpnetlisthead
name|nets
decl_stmt|;
comment|/* remote address list */
comment|/* Free chunk list */
name|struct
name|sctpchunk_listhead
name|free_chunks
decl_stmt|;
comment|/* Control chunk queue */
name|struct
name|sctpchunk_listhead
name|control_send_queue
decl_stmt|;
comment|/* ASCONF chunk queue */
name|struct
name|sctpchunk_listhead
name|asconf_send_queue
decl_stmt|;
comment|/* 	 * Once a TSN hits the wire it is moved to the sent_queue. We 	 * maintain two counts here (don't know if any but retran_cnt is 	 * needed). The idea is that the sent_queue_retran_cnt reflects how 	 * many chunks have been marked for retranmission by either T3-rxt 	 * or FR. 	 */
name|struct
name|sctpchunk_listhead
name|sent_queue
decl_stmt|;
name|struct
name|sctpchunk_listhead
name|send_queue
decl_stmt|;
comment|/* re-assembly queue for fragmented chunks on the inbound path */
name|struct
name|sctpchunk_listhead
name|reasmqueue
decl_stmt|;
comment|/* Scheduling queues */
name|union
name|scheduling_data
name|ss_data
decl_stmt|;
comment|/* 	 * This pointer will be set to NULL most of the time. But when we 	 * have a fragmented message, where we could not get out all of the 	 * message at the last send then this will point to the stream to go 	 * get data from. 	 */
name|struct
name|sctp_stream_out
modifier|*
name|locked_on_sending
decl_stmt|;
comment|/* If an iterator is looking at me, this is it */
name|struct
name|sctp_iterator
modifier|*
name|stcb_starting_point_for_iterator
decl_stmt|;
comment|/* ASCONF save the last ASCONF-ACK so we can resend it if necessary */
name|struct
name|sctp_asconf_ackhead
name|asconf_ack_sent
decl_stmt|;
comment|/* 	 * pointer to last stream reset queued to control queue by us with 	 * requests. 	 */
name|struct
name|sctp_tmit_chunk
modifier|*
name|str_reset
decl_stmt|;
comment|/* 	 * if Source Address Selection happening, this will rotate through 	 * the link list. 	 */
name|struct
name|sctp_laddr
modifier|*
name|last_used_address
decl_stmt|;
comment|/* stream arrays */
name|struct
name|sctp_stream_in
modifier|*
name|strmin
decl_stmt|;
name|struct
name|sctp_stream_out
modifier|*
name|strmout
decl_stmt|;
name|uint8_t
modifier|*
name|mapping_array
decl_stmt|;
comment|/* primary destination to use */
name|struct
name|sctp_nets
modifier|*
name|primary_destination
decl_stmt|;
comment|/* For CMT */
name|struct
name|sctp_nets
modifier|*
name|last_net_cmt_send_started
decl_stmt|;
comment|/* last place I got a data chunk from */
name|struct
name|sctp_nets
modifier|*
name|last_data_chunk_from
decl_stmt|;
comment|/* last place I got a control from */
name|struct
name|sctp_nets
modifier|*
name|last_control_chunk_from
decl_stmt|;
comment|/* circular looking for output selection */
name|struct
name|sctp_stream_out
modifier|*
name|last_out_stream
decl_stmt|;
comment|/* 	 * wait to the point the cum-ack passes req->send_reset_at_tsn for 	 * any req on the list. 	 */
name|struct
name|sctp_resethead
name|resetHead
decl_stmt|;
comment|/* queue of chunks waiting to be sent into the local stack */
name|struct
name|sctp_readhead
name|pending_reply_queue
decl_stmt|;
comment|/* JRS - the congestion control functions are in this struct */
name|struct
name|sctp_cc_functions
name|cc_functions
decl_stmt|;
comment|/* 	 * JRS - value to store the currently loaded congestion control 	 * module 	 */
name|uint32_t
name|congestion_control_module
decl_stmt|;
comment|/* RS - the stream scheduling functions are in this struct */
name|struct
name|sctp_ss_functions
name|ss_functions
decl_stmt|;
comment|/* RS - value to store the currently loaded stream scheduling module */
name|uint32_t
name|stream_scheduling_module
decl_stmt|;
name|uint32_t
name|vrf_id
decl_stmt|;
name|uint32_t
name|cookie_preserve_req
decl_stmt|;
comment|/* ASCONF next seq I am sending out, inits at init-tsn */
name|uint32_t
name|asconf_seq_out
decl_stmt|;
name|uint32_t
name|asconf_seq_out_acked
decl_stmt|;
comment|/* ASCONF last received ASCONF from peer, starts at peer's TSN-1 */
name|uint32_t
name|asconf_seq_in
decl_stmt|;
comment|/* next seq I am sending in str reset messages */
name|uint32_t
name|str_reset_seq_out
decl_stmt|;
comment|/* next seq I am expecting in str reset messages */
name|uint32_t
name|str_reset_seq_in
decl_stmt|;
comment|/* various verification tag information */
name|uint32_t
name|my_vtag
decl_stmt|;
comment|/* The tag to be used. if assoc is re-initited 				 * by remote end, and I have unlocked this 				 * will be regenerated to a new random value. */
name|uint32_t
name|peer_vtag
decl_stmt|;
comment|/* The peers last tag */
name|uint32_t
name|my_vtag_nonce
decl_stmt|;
name|uint32_t
name|peer_vtag_nonce
decl_stmt|;
name|uint32_t
name|assoc_id
decl_stmt|;
comment|/* This is the SCTP fragmentation threshold */
name|uint32_t
name|smallest_mtu
decl_stmt|;
comment|/* 	 * Special hook for Fast retransmit, allows us to track the highest 	 * TSN that is NEW in this SACK if gap ack blocks are present. 	 */
name|uint32_t
name|this_sack_highest_gap
decl_stmt|;
comment|/* 	 * The highest consecutive TSN that has been acked by peer on my 	 * sends 	 */
name|uint32_t
name|last_acked_seq
decl_stmt|;
comment|/* The next TSN that I will use in sending. */
name|uint32_t
name|sending_seq
decl_stmt|;
comment|/* Original seq number I used ??questionable to keep?? */
name|uint32_t
name|init_seq_number
decl_stmt|;
comment|/* The Advanced Peer Ack Point, as required by the PR-SCTP */
comment|/* (A1 in Section 4.2) */
name|uint32_t
name|advanced_peer_ack_point
decl_stmt|;
comment|/* 	 * The highest consequetive TSN at the bottom of the mapping array 	 * (for his sends). 	 */
name|uint32_t
name|cumulative_tsn
decl_stmt|;
comment|/* 	 * Used to track the mapping array and its offset bits. This MAY be 	 * lower then cumulative_tsn. 	 */
name|uint32_t
name|mapping_array_base_tsn
decl_stmt|;
comment|/* 	 * used to track highest TSN we have received and is listed in the 	 * mapping array. 	 */
name|uint32_t
name|highest_tsn_inside_map
decl_stmt|;
comment|/* EY - new NR variables used for nr_sack based on mapping_array */
name|uint8_t
modifier|*
name|nr_mapping_array
decl_stmt|;
name|uint32_t
name|highest_tsn_inside_nr_map
decl_stmt|;
name|uint32_t
name|fast_recovery_tsn
decl_stmt|;
name|uint32_t
name|sat_t3_recovery_tsn
decl_stmt|;
name|uint32_t
name|tsn_last_delivered
decl_stmt|;
comment|/* 	 * For the pd-api we should re-write this a bit more efficent. We 	 * could have multiple sctp_queued_to_read's that we are building at 	 * once. Now we only do this when we get ready to deliver to the 	 * socket buffer. Note that we depend on the fact that the struct is 	 * "stuck" on the read queue until we finish all the pd-api. 	 */
name|struct
name|sctp_queued_to_read
modifier|*
name|control_pdapi
decl_stmt|;
name|uint32_t
name|tsn_of_pdapi_last_delivered
decl_stmt|;
name|uint32_t
name|pdapi_ppid
decl_stmt|;
name|uint32_t
name|context
decl_stmt|;
name|uint32_t
name|last_reset_action
index|[
name|SCTP_MAX_RESET_PARAMS
index|]
decl_stmt|;
name|uint32_t
name|last_sending_seq
index|[
name|SCTP_MAX_RESET_PARAMS
index|]
decl_stmt|;
name|uint32_t
name|last_base_tsnsent
index|[
name|SCTP_MAX_RESET_PARAMS
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|SCTP_ASOCLOG_OF_TSNS
comment|/* 	 * special log  - This adds considerable size to the asoc, but 	 * provides a log that you can use to detect problems via kgdb. 	 */
name|struct
name|sctp_tsn_log
name|in_tsnlog
index|[
name|SCTP_TSN_LOG_SIZE
index|]
decl_stmt|;
name|struct
name|sctp_tsn_log
name|out_tsnlog
index|[
name|SCTP_TSN_LOG_SIZE
index|]
decl_stmt|;
name|uint32_t
name|cumack_log
index|[
name|SCTP_TSN_LOG_SIZE
index|]
decl_stmt|;
name|uint32_t
name|cumack_logsnt
index|[
name|SCTP_TSN_LOG_SIZE
index|]
decl_stmt|;
name|uint16_t
name|tsn_in_at
decl_stmt|;
name|uint16_t
name|tsn_out_at
decl_stmt|;
name|uint16_t
name|tsn_in_wrapped
decl_stmt|;
name|uint16_t
name|tsn_out_wrapped
decl_stmt|;
name|uint16_t
name|cumack_log_at
decl_stmt|;
name|uint16_t
name|cumack_log_atsnt
decl_stmt|;
endif|#
directive|endif
comment|/* SCTP_ASOCLOG_OF_TSNS */
ifdef|#
directive|ifdef
name|SCTP_FS_SPEC_LOG
name|struct
name|sctp_fs_spec_log
name|fslog
index|[
name|SCTP_FS_SPEC_LOG_SIZE
index|]
decl_stmt|;
name|uint16_t
name|fs_index
decl_stmt|;
endif|#
directive|endif
comment|/* 	 * window state information and smallest MTU that I use to bound 	 * segmentation 	 */
name|uint32_t
name|peers_rwnd
decl_stmt|;
name|uint32_t
name|my_rwnd
decl_stmt|;
name|uint32_t
name|my_last_reported_rwnd
decl_stmt|;
name|uint32_t
name|sctp_frag_point
decl_stmt|;
name|uint32_t
name|total_output_queue_size
decl_stmt|;
name|uint32_t
name|sb_cc
decl_stmt|;
comment|/* shadow of sb_cc */
name|uint32_t
name|sb_send_resv
decl_stmt|;
comment|/* amount reserved on a send */
name|uint32_t
name|my_rwnd_control_len
decl_stmt|;
comment|/* shadow of sb_mbcnt used for rwnd 					 * control */
name|uint32_t
name|default_flowlabel
decl_stmt|;
name|uint32_t
name|pr_sctp_cnt
decl_stmt|;
name|int
name|ctrl_queue_cnt
decl_stmt|;
comment|/* could be removed  REM - NO IT CAN'T!! RRS */
comment|/* 	 * All outbound datagrams queue into this list from the individual 	 * stream queue. Here they get assigned a TSN and then await 	 * sending. The stream seq comes when it is first put in the 	 * individual str queue 	 */
name|unsigned
name|int
name|stream_queue_cnt
decl_stmt|;
name|unsigned
name|int
name|send_queue_cnt
decl_stmt|;
name|unsigned
name|int
name|sent_queue_cnt
decl_stmt|;
name|unsigned
name|int
name|sent_queue_cnt_removeable
decl_stmt|;
comment|/* 	 * Number on sent queue that are marked for retran until this value 	 * is 0 we only send one packet of retran'ed data. 	 */
name|unsigned
name|int
name|sent_queue_retran_cnt
decl_stmt|;
name|unsigned
name|int
name|size_on_reasm_queue
decl_stmt|;
name|unsigned
name|int
name|cnt_on_reasm_queue
decl_stmt|;
name|unsigned
name|int
name|fwd_tsn_cnt
decl_stmt|;
comment|/* amount of data (bytes) currently in flight (on all destinations) */
name|unsigned
name|int
name|total_flight
decl_stmt|;
comment|/* Total book size in flight */
name|unsigned
name|int
name|total_flight_count
decl_stmt|;
comment|/* count of chunks used with 						 * book total */
comment|/* count of destinaton nets and list of destination nets */
name|unsigned
name|int
name|numnets
decl_stmt|;
comment|/* Total error count on this association */
name|unsigned
name|int
name|overall_error_count
decl_stmt|;
name|unsigned
name|int
name|cnt_msg_on_sb
decl_stmt|;
comment|/* All stream count of chunks for delivery */
name|unsigned
name|int
name|size_on_all_streams
decl_stmt|;
name|unsigned
name|int
name|cnt_on_all_streams
decl_stmt|;
comment|/* Heart Beat delay in ticks */
name|unsigned
name|int
name|heart_beat_delay
decl_stmt|;
comment|/* autoclose */
name|unsigned
name|int
name|sctp_autoclose_ticks
decl_stmt|;
comment|/* how many preopen streams we have */
name|unsigned
name|int
name|pre_open_streams
decl_stmt|;
comment|/* How many streams I support coming into me */
name|unsigned
name|int
name|max_inbound_streams
decl_stmt|;
comment|/* the cookie life I award for any cookie, in seconds */
name|unsigned
name|int
name|cookie_life
decl_stmt|;
comment|/* time to delay acks for */
name|unsigned
name|int
name|delayed_ack
decl_stmt|;
name|unsigned
name|int
name|old_delayed_ack
decl_stmt|;
name|unsigned
name|int
name|sack_freq
decl_stmt|;
name|unsigned
name|int
name|data_pkts_seen
decl_stmt|;
name|unsigned
name|int
name|numduptsns
decl_stmt|;
name|int
name|dup_tsns
index|[
name|SCTP_MAX_DUP_TSNS
index|]
decl_stmt|;
name|unsigned
name|int
name|initial_init_rto_max
decl_stmt|;
comment|/* initial RTO for INIT's */
name|unsigned
name|int
name|initial_rto
decl_stmt|;
comment|/* initial send RTO */
name|unsigned
name|int
name|minrto
decl_stmt|;
comment|/* per assoc RTO-MIN */
name|unsigned
name|int
name|maxrto
decl_stmt|;
comment|/* per assoc RTO-MAX */
comment|/* authentication fields */
name|sctp_auth_chklist_t
modifier|*
name|local_auth_chunks
decl_stmt|;
name|sctp_auth_chklist_t
modifier|*
name|peer_auth_chunks
decl_stmt|;
name|sctp_hmaclist_t
modifier|*
name|local_hmacs
decl_stmt|;
comment|/* local HMACs supported */
name|sctp_hmaclist_t
modifier|*
name|peer_hmacs
decl_stmt|;
comment|/* peer HMACs supported */
name|struct
name|sctp_keyhead
name|shared_keys
decl_stmt|;
comment|/* assoc's shared keys */
name|sctp_authinfo_t
name|authinfo
decl_stmt|;
comment|/* randoms, cached keys */
comment|/* 	 * refcnt to block freeing when a sender or receiver is off coping 	 * user data in. 	 */
name|uint32_t
name|refcnt
decl_stmt|;
name|uint32_t
name|chunks_on_out_queue
decl_stmt|;
comment|/* total chunks floating around, 					 * locked by send socket buffer */
name|uint32_t
name|peers_adaptation
decl_stmt|;
name|uint16_t
name|peer_hmac_id
decl_stmt|;
comment|/* peer HMAC id to send */
comment|/* 	 * Being that we have no bag to collect stale cookies, and that we 	 * really would not want to anyway.. we will count them in this 	 * counter. We of course feed them to the pigeons right away (I have 	 * always thought of pigeons as flying rats). 	 */
name|uint16_t
name|stale_cookie_count
decl_stmt|;
comment|/* 	 * For the partial delivery API, if up, invoked this is what last 	 * TSN I delivered 	 */
name|uint16_t
name|str_of_pdapi
decl_stmt|;
name|uint16_t
name|ssn_of_pdapi
decl_stmt|;
comment|/* counts of actual built streams. Allocation may be more however */
comment|/* could re-arrange to optimize space here. */
name|uint16_t
name|streamincnt
decl_stmt|;
name|uint16_t
name|streamoutcnt
decl_stmt|;
name|uint16_t
name|strm_realoutsize
decl_stmt|;
comment|/* my maximum number of retrans of INIT and SEND */
comment|/* copied from SCTP but should be individually setable */
name|uint16_t
name|max_init_times
decl_stmt|;
name|uint16_t
name|max_send_times
decl_stmt|;
name|uint16_t
name|def_net_failure
decl_stmt|;
comment|/* 	 * lock flag: 0 is ok to send, 1+ (duals as a retran count) is 	 * awaiting ACK 	 */
name|uint16_t
name|mapping_array_size
decl_stmt|;
name|uint16_t
name|last_strm_seq_delivered
decl_stmt|;
name|uint16_t
name|last_strm_no_delivered
decl_stmt|;
name|uint16_t
name|last_revoke_count
decl_stmt|;
name|int16_t
name|num_send_timers_up
decl_stmt|;
name|uint16_t
name|stream_locked_on
decl_stmt|;
name|uint16_t
name|ecn_echo_cnt_onq
decl_stmt|;
name|uint16_t
name|free_chunk_cnt
decl_stmt|;
name|uint8_t
name|stream_locked
decl_stmt|;
name|uint8_t
name|authenticated
decl_stmt|;
comment|/* packet authenticated ok */
comment|/* 	 * This flag indicates that a SACK need to be sent. Initially this 	 * is 1 to send the first sACK immediately. 	 */
name|uint8_t
name|send_sack
decl_stmt|;
comment|/* max burst of new packets into the network */
name|uint32_t
name|max_burst
decl_stmt|;
comment|/* max burst of fast retransmit packets */
name|uint32_t
name|fr_max_burst
decl_stmt|;
name|uint8_t
name|sat_network
decl_stmt|;
comment|/* RTT is in range of sat net or greater */
name|uint8_t
name|sat_network_lockout
decl_stmt|;
comment|/* lockout code */
name|uint8_t
name|burst_limit_applied
decl_stmt|;
comment|/* Burst limit in effect at last send? */
comment|/* flag goes on when we are doing a partial delivery api */
name|uint8_t
name|hb_random_values
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|fragmented_delivery_inprogress
decl_stmt|;
name|uint8_t
name|fragment_flags
decl_stmt|;
name|uint8_t
name|last_flags_delivered
decl_stmt|;
name|uint8_t
name|hb_ect_randombit
decl_stmt|;
name|uint8_t
name|hb_random_idx
decl_stmt|;
name|uint8_t
name|hb_is_disabled
decl_stmt|;
comment|/* is the hb disabled? */
name|uint8_t
name|default_tos
decl_stmt|;
name|uint8_t
name|asconf_del_pending
decl_stmt|;
comment|/* asconf delete last addr pending */
comment|/* 	 * This value, plus all other ack'd but above cum-ack is added 	 * together to cross check against the bit that we have yet to 	 * define (probably in the SACK). When the cum-ack is updated, this 	 * sum is updated as well. 	 */
comment|/* Flag to tell if ECN is allowed */
name|uint8_t
name|ecn_allowed
decl_stmt|;
comment|/* flag to indicate if peer can do asconf */
name|uint8_t
name|peer_supports_asconf
decl_stmt|;
comment|/* EY - flag to indicate if peer can do nr_sack */
name|uint8_t
name|peer_supports_nr_sack
decl_stmt|;
comment|/* pr-sctp support flag */
name|uint8_t
name|peer_supports_prsctp
decl_stmt|;
comment|/* peer authentication support flag */
name|uint8_t
name|peer_supports_auth
decl_stmt|;
comment|/* stream resets are supported by the peer */
name|uint8_t
name|peer_supports_strreset
decl_stmt|;
name|uint8_t
name|peer_supports_nat
decl_stmt|;
comment|/* 	 * packet drop's are supported by the peer, we don't really care 	 * about this but we bookkeep it anyway. 	 */
name|uint8_t
name|peer_supports_pktdrop
decl_stmt|;
comment|/* Do we allow V6/V4? */
name|uint8_t
name|ipv4_addr_legal
decl_stmt|;
name|uint8_t
name|ipv6_addr_legal
decl_stmt|;
comment|/* Address scoping flags */
comment|/* scope value for IPv4 */
name|uint8_t
name|ipv4_local_scope
decl_stmt|;
comment|/* scope values for IPv6 */
name|uint8_t
name|local_scope
decl_stmt|;
name|uint8_t
name|site_scope
decl_stmt|;
comment|/* loopback scope */
name|uint8_t
name|loopback_scope
decl_stmt|;
comment|/* flags to handle send alternate net tracking */
name|uint8_t
name|used_alt_onsack
decl_stmt|;
name|uint8_t
name|used_alt_asconfack
decl_stmt|;
name|uint8_t
name|fast_retran_loss_recovery
decl_stmt|;
name|uint8_t
name|sat_t3_loss_recovery
decl_stmt|;
name|uint8_t
name|dropped_special_cnt
decl_stmt|;
name|uint8_t
name|seen_a_sack_this_pkt
decl_stmt|;
name|uint8_t
name|stream_reset_outstanding
decl_stmt|;
name|uint8_t
name|stream_reset_out_is_outstanding
decl_stmt|;
name|uint8_t
name|delayed_connection
decl_stmt|;
name|uint8_t
name|ifp_had_enobuf
decl_stmt|;
name|uint8_t
name|saw_sack_with_frags
decl_stmt|;
name|uint8_t
name|saw_sack_with_nr_frags
decl_stmt|;
name|uint8_t
name|in_asocid_hash
decl_stmt|;
name|uint8_t
name|assoc_up_sent
decl_stmt|;
name|uint8_t
name|adaptation_needed
decl_stmt|;
name|uint8_t
name|adaptation_sent
decl_stmt|;
comment|/* CMT variables */
name|uint8_t
name|cmt_dac_pkts_rcvd
decl_stmt|;
name|uint8_t
name|sctp_cmt_on_off
decl_stmt|;
name|uint8_t
name|iam_blocking
decl_stmt|;
name|uint8_t
name|cookie_how
index|[
literal|8
index|]
decl_stmt|;
comment|/* EY 05/05/08 - NR_SACK variable */
name|uint8_t
name|sctp_nr_sack_on_off
decl_stmt|;
comment|/* JRS 5/21/07 - CMT PF variable */
name|uint8_t
name|sctp_cmt_pf
decl_stmt|;
comment|/* 	 * The mapping array is used to track out of order sequences above 	 * last_acked_seq. 0 indicates packet missing 1 indicates packet 	 * rec'd. We slide it up every time we raise last_acked_seq and 0 	 * trailing locactions out.  If I get a TSN above the array 	 * mappingArraySz, I discard the datagram and let retransmit happen. 	 */
name|uint32_t
name|marked_retrans
decl_stmt|;
name|uint32_t
name|timoinit
decl_stmt|;
name|uint32_t
name|timodata
decl_stmt|;
name|uint32_t
name|timosack
decl_stmt|;
name|uint32_t
name|timoshutdown
decl_stmt|;
name|uint32_t
name|timoheartbeat
decl_stmt|;
name|uint32_t
name|timocookie
decl_stmt|;
name|uint32_t
name|timoshutdownack
decl_stmt|;
name|struct
name|timeval
name|start_time
decl_stmt|;
name|struct
name|timeval
name|discontinuity_time
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

