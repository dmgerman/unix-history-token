begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2006, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $KAME: sctp_uio.h,v 1.11 2005/03/06 16:04:18 itojun Exp $	 */
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
name|__sctp_uio_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_uio_h__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_typedef
typedef|typedef
name|uint32_t
name|sctp_assoc_t
typedef|;
end_typedef

begin_comment
comment|/* On/Off setup for subscription to events */
end_comment

begin_struct
struct|struct
name|sctp_event_subscribe
block|{
name|uint8_t
name|sctp_data_io_event
decl_stmt|;
name|uint8_t
name|sctp_association_event
decl_stmt|;
name|uint8_t
name|sctp_address_event
decl_stmt|;
name|uint8_t
name|sctp_send_failure_event
decl_stmt|;
name|uint8_t
name|sctp_peer_error_event
decl_stmt|;
name|uint8_t
name|sctp_shutdown_event
decl_stmt|;
name|uint8_t
name|sctp_partial_delivery_event
decl_stmt|;
name|uint8_t
name|sctp_adaptation_layer_event
decl_stmt|;
name|uint8_t
name|sctp_authentication_event
decl_stmt|;
name|uint8_t
name|sctp_stream_reset_events
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ancillary data types */
end_comment

begin_define
define|#
directive|define
name|SCTP_INIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_SNDRCV
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_EXTRCV
value|0x0003
end_define

begin_comment
comment|/*  * ancillary data structures  */
end_comment

begin_struct
struct|struct
name|sctp_initmsg
block|{
name|uint32_t
name|sinit_num_ostreams
decl_stmt|;
name|uint32_t
name|sinit_max_instreams
decl_stmt|;
name|uint16_t
name|sinit_max_attempts
decl_stmt|;
name|uint16_t
name|sinit_max_init_timeo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* We add 96 bytes to the size of sctp_sndrcvinfo.  * This makes the current structure 128 bytes long  * which is nicely 64 bit aligned but also has room  * for us to add more and keep ABI compatability.  * For example, already we have the sctp_extrcvinfo  * when enabled which is 48 bytes.  */
end_comment

begin_comment
comment|/*  * The assoc up needs a verfid  * all sendrcvinfo's need a verfid for SENDING only.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_ALIGN_RESV_PAD
value|96
end_define

begin_define
define|#
directive|define
name|SCTP_ALIGN_RESV_PAD_SHORT
value|80
end_define

begin_struct
struct|struct
name|sctp_sndrcvinfo
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
name|uint8_t
name|__reserve_pad
index|[
name|SCTP_ALIGN_RESV_PAD
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_extrcvinfo
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
name|uint16_t
name|next_flags
decl_stmt|;
name|uint16_t
name|next_stream
decl_stmt|;
name|uint32_t
name|next_asocid
decl_stmt|;
name|uint32_t
name|next_length
decl_stmt|;
name|uint32_t
name|next_ppid
decl_stmt|;
name|uint8_t
name|__reserve_pad
index|[
name|SCTP_ALIGN_RESV_PAD_SHORT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_NO_NEXT_MSG
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCTP_NEXT_MSG_AVAIL
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_NEXT_MSG_ISCOMPLETE
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_NEXT_MSG_IS_UNORDERED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_NEXT_MSG_IS_NOTIFICATION
value|0x0008
end_define

begin_struct
struct|struct
name|sctp_snd_all_completes
block|{
name|uint16_t
name|sall_stream
decl_stmt|;
name|uint16_t
name|sall_flags
decl_stmt|;
name|uint32_t
name|sall_ppid
decl_stmt|;
name|uint32_t
name|sall_context
decl_stmt|;
name|uint32_t
name|sall_num_sent
decl_stmt|;
name|uint32_t
name|sall_num_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags that go into the sinfo->sinfo_flags field */
end_comment

begin_define
define|#
directive|define
name|SCTP_EOF
value|0x0100
end_define

begin_comment
comment|/* Start shutdown procedures */
end_comment

begin_define
define|#
directive|define
name|SCTP_ABORT
value|0x0200
end_define

begin_comment
comment|/* Send an ABORT to peer */
end_comment

begin_define
define|#
directive|define
name|SCTP_UNORDERED
value|0x0400
end_define

begin_comment
comment|/* Message is un-ordered */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDR_OVER
value|0x0800
end_define

begin_comment
comment|/* Override the primary-address */
end_comment

begin_define
define|#
directive|define
name|SCTP_SENDALL
value|0x1000
end_define

begin_comment
comment|/* Send this on all associations */
end_comment

begin_define
define|#
directive|define
name|SCTP_EOR
value|0x2000
end_define

begin_comment
comment|/* end of message signal */
end_comment

begin_define
define|#
directive|define
name|INVALID_SINFO_FLAG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xffffff00 \& ~(SCTP_EOF | SCTP_ABORT | SCTP_UNORDERED |\ 				        SCTP_ADDR_OVER | SCTP_SENDALL | SCTP_EOR)) != 0)
end_define

begin_comment
comment|/* for the endpoint */
end_comment

begin_comment
comment|/* The lower byte is an enumeration of PR-SCTP policies */
end_comment

begin_define
define|#
directive|define
name|SCTP_PR_SCTP_TTL
value|0x0001
end_define

begin_comment
comment|/* Time based PR-SCTP */
end_comment

begin_define
define|#
directive|define
name|SCTP_PR_SCTP_BUF
value|0x0002
end_define

begin_comment
comment|/* Buffer based PR-SCTP */
end_comment

begin_define
define|#
directive|define
name|SCTP_PR_SCTP_RTX
value|0x0003
end_define

begin_comment
comment|/* Number of retransmissions based PR-SCTP */
end_comment

begin_define
define|#
directive|define
name|PR_SCTP_POLICY
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|PR_SCTP_ENABLED
parameter_list|(
name|x
parameter_list|)
value|(PR_SCTP_POLICY(x) != 0)
end_define

begin_define
define|#
directive|define
name|PR_SCTP_TTL_ENABLED
parameter_list|(
name|x
parameter_list|)
value|(PR_SCTP_POLICY(x) == SCTP_PR_SCTP_TTL)
end_define

begin_define
define|#
directive|define
name|PR_SCTP_BUF_ENABLED
parameter_list|(
name|x
parameter_list|)
value|(PR_SCTP_POLICY(x) == SCTP_PR_SCTP_BUF)
end_define

begin_define
define|#
directive|define
name|PR_SCTP_RTX_ENABLED
parameter_list|(
name|x
parameter_list|)
value|(PR_SCTP_POLICY(x) == SCTP_PR_SCTP_RTX)
end_define

begin_define
define|#
directive|define
name|PR_SCTP_INVALID_POLICY
parameter_list|(
name|x
parameter_list|)
value|(PR_SCTP_POLICY(x)> SCTP_PR_SCTP_RTX)
end_define

begin_comment
comment|/* Stat's */
end_comment

begin_struct
struct|struct
name|sctp_pcbinfo
block|{
name|uint32_t
name|ep_count
decl_stmt|;
name|uint32_t
name|asoc_count
decl_stmt|;
name|uint32_t
name|laddr_count
decl_stmt|;
name|uint32_t
name|raddr_count
decl_stmt|;
name|uint32_t
name|chk_count
decl_stmt|;
name|uint32_t
name|readq_count
decl_stmt|;
name|uint32_t
name|free_chunks
decl_stmt|;
name|uint32_t
name|stream_oque
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_sockstat
block|{
name|sctp_assoc_t
name|ss_assoc_id
decl_stmt|;
name|uint32_t
name|ss_total_sndbuf
decl_stmt|;
name|uint32_t
name|ss_total_recv_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * notification event structures  */
end_comment

begin_comment
comment|/*  * association change event  */
end_comment

begin_struct
struct|struct
name|sctp_assoc_change
block|{
name|uint16_t
name|sac_type
decl_stmt|;
name|uint16_t
name|sac_flags
decl_stmt|;
name|uint32_t
name|sac_length
decl_stmt|;
name|uint16_t
name|sac_state
decl_stmt|;
name|uint16_t
name|sac_error
decl_stmt|;
name|uint16_t
name|sac_outbound_streams
decl_stmt|;
name|uint16_t
name|sac_inbound_streams
decl_stmt|;
name|sctp_assoc_t
name|sac_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sac_state values */
end_comment

begin_define
define|#
directive|define
name|SCTP_COMM_UP
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_COMM_LOST
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_RESTART
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_COMP
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_CANT_STR_ASSOC
value|0x0005
end_define

begin_comment
comment|/*  * Address event  */
end_comment

begin_struct
struct|struct
name|sctp_paddr_change
block|{
name|uint16_t
name|spc_type
decl_stmt|;
name|uint16_t
name|spc_flags
decl_stmt|;
name|uint32_t
name|spc_length
decl_stmt|;
name|struct
name|sockaddr_storage
name|spc_aaddr
decl_stmt|;
name|uint32_t
name|spc_state
decl_stmt|;
name|uint32_t
name|spc_error
decl_stmt|;
name|sctp_assoc_t
name|spc_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* paddr state values */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDR_AVAILABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_UNREACHABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_REMOVED
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_ADDED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_MADE_PRIM
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_CONFIRMED
value|0x0006
end_define

begin_comment
comment|/*  * CAUTION: these are user exposed SCTP addr reachability states must be  * compatible with SCTP_ADDR states in sctp_constants.h  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_ACTIVE
end_ifdef

begin_undef
undef|#
directive|undef
name|SCTP_ACTIVE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCTP_ACTIVE
value|0x0001
end_define

begin_comment
comment|/* SCTP_ADDR_REACHABLE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_INACTIVE
end_ifdef

begin_undef
undef|#
directive|undef
name|SCTP_INACTIVE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCTP_INACTIVE
value|0x0002
end_define

begin_comment
comment|/* SCTP_ADDR_NOT_REACHABLE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_UNCONFIRMED
end_ifdef

begin_undef
undef|#
directive|undef
name|SCTP_UNCONFIRMED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCTP_UNCONFIRMED
value|0x0200
end_define

begin_comment
comment|/* SCTP_ADDR_UNCONFIRMED */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_NOHEARTBEAT
end_ifdef

begin_undef
undef|#
directive|undef
name|SCTP_NOHEARTBEAT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCTP_NOHEARTBEAT
value|0x0040
end_define

begin_comment
comment|/* SCTP_ADDR_NOHB */
end_comment

begin_comment
comment|/* remote error events */
end_comment

begin_struct
struct|struct
name|sctp_remote_error
block|{
name|uint16_t
name|sre_type
decl_stmt|;
name|uint16_t
name|sre_flags
decl_stmt|;
name|uint32_t
name|sre_length
decl_stmt|;
name|uint16_t
name|sre_error
decl_stmt|;
name|sctp_assoc_t
name|sre_assoc_id
decl_stmt|;
name|uint8_t
name|sre_data
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* data send failure event */
end_comment

begin_struct
struct|struct
name|sctp_send_failed
block|{
name|uint16_t
name|ssf_type
decl_stmt|;
name|uint16_t
name|ssf_flags
decl_stmt|;
name|uint32_t
name|ssf_length
decl_stmt|;
name|uint32_t
name|ssf_error
decl_stmt|;
name|struct
name|sctp_sndrcvinfo
name|ssf_info
decl_stmt|;
name|sctp_assoc_t
name|ssf_assoc_id
decl_stmt|;
name|uint8_t
name|ssf_data
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flag that indicates state of data */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATA_UNSENT
value|0x0001
end_define

begin_comment
comment|/* inqueue never on wire */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATA_SENT
value|0x0002
end_define

begin_comment
comment|/* on wire at failure */
end_comment

begin_comment
comment|/* shutdown event */
end_comment

begin_struct
struct|struct
name|sctp_shutdown_event
block|{
name|uint16_t
name|sse_type
decl_stmt|;
name|uint16_t
name|sse_flags
decl_stmt|;
name|uint32_t
name|sse_length
decl_stmt|;
name|sctp_assoc_t
name|sse_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Adaptation layer indication stuff */
end_comment

begin_struct
struct|struct
name|sctp_adaptation_event
block|{
name|uint16_t
name|sai_type
decl_stmt|;
name|uint16_t
name|sai_flags
decl_stmt|;
name|uint32_t
name|sai_length
decl_stmt|;
name|uint32_t
name|sai_adaptation_ind
decl_stmt|;
name|sctp_assoc_t
name|sai_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_setadaptation
block|{
name|uint32_t
name|ssb_adaptation_ind
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* compatable old spelling */
end_comment

begin_struct
struct|struct
name|sctp_adaption_event
block|{
name|uint16_t
name|sai_type
decl_stmt|;
name|uint16_t
name|sai_flags
decl_stmt|;
name|uint32_t
name|sai_length
decl_stmt|;
name|uint32_t
name|sai_adaption_ind
decl_stmt|;
name|sctp_assoc_t
name|sai_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_setadaption
block|{
name|uint32_t
name|ssb_adaption_ind
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Partial Delivery API event  */
end_comment

begin_struct
struct|struct
name|sctp_pdapi_event
block|{
name|uint16_t
name|pdapi_type
decl_stmt|;
name|uint16_t
name|pdapi_flags
decl_stmt|;
name|uint32_t
name|pdapi_length
decl_stmt|;
name|uint32_t
name|pdapi_indication
decl_stmt|;
name|sctp_assoc_t
name|pdapi_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* indication values */
end_comment

begin_define
define|#
directive|define
name|SCTP_PARTIAL_DELIVERY_ABORTED
value|0x0001
end_define

begin_comment
comment|/*  * authentication key event  */
end_comment

begin_struct
struct|struct
name|sctp_authkey_event
block|{
name|uint16_t
name|auth_type
decl_stmt|;
name|uint16_t
name|auth_flags
decl_stmt|;
name|uint32_t
name|auth_length
decl_stmt|;
name|uint16_t
name|auth_keynumber
decl_stmt|;
name|uint16_t
name|auth_altkeynumber
decl_stmt|;
name|uint32_t
name|auth_indication
decl_stmt|;
name|sctp_assoc_t
name|auth_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* indication values */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTH_NEWKEY
value|0x0001
end_define

begin_comment
comment|/*  * stream reset event  */
end_comment

begin_struct
struct|struct
name|sctp_stream_reset_event
block|{
name|uint16_t
name|strreset_type
decl_stmt|;
name|uint16_t
name|strreset_flags
decl_stmt|;
name|uint32_t
name|strreset_length
decl_stmt|;
name|sctp_assoc_t
name|strreset_assoc_id
decl_stmt|;
name|uint16_t
name|strreset_list
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flags in strreset_flags field */
end_comment

begin_define
define|#
directive|define
name|SCTP_STRRESET_INBOUND_STR
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_STRRESET_OUTBOUND_STR
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_STRRESET_ALL_STREAMS
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_STRRESET_STREAM_LIST
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_STRRESET_FAILED
value|0x0010
end_define

begin_comment
comment|/* SCTP notification event */
end_comment

begin_struct
struct|struct
name|sctp_tlv
block|{
name|uint16_t
name|sn_type
decl_stmt|;
name|uint16_t
name|sn_flags
decl_stmt|;
name|uint32_t
name|sn_length
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|sctp_notification
block|{
name|struct
name|sctp_tlv
name|sn_header
decl_stmt|;
name|struct
name|sctp_assoc_change
name|sn_assoc_change
decl_stmt|;
name|struct
name|sctp_paddr_change
name|sn_paddr_change
decl_stmt|;
name|struct
name|sctp_remote_error
name|sn_remote_error
decl_stmt|;
name|struct
name|sctp_send_failed
name|sn_send_failed
decl_stmt|;
name|struct
name|sctp_shutdown_event
name|sn_shutdown_event
decl_stmt|;
name|struct
name|sctp_adaptation_event
name|sn_adaptation_event
decl_stmt|;
comment|/* compatability same as above */
name|struct
name|sctp_adaption_event
name|sn_adaption_event
decl_stmt|;
name|struct
name|sctp_pdapi_event
name|sn_pdapi_event
decl_stmt|;
name|struct
name|sctp_authkey_event
name|sn_auth_event
decl_stmt|;
name|struct
name|sctp_stream_reset_event
name|sn_strreset_event
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* notification types */
end_comment

begin_define
define|#
directive|define
name|SCTP_ASSOC_CHANGE
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_PEER_ADDR_CHANGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_REMOTE_ERROR
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCTP_SEND_FAILED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_EVENT
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCTP_ADAPTATION_INDICATION
value|0x0006
end_define

begin_comment
comment|/* same as above */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADAPTION_INDICATION
value|0x0006
end_define

begin_define
define|#
directive|define
name|SCTP_PARTIAL_DELIVERY_EVENT
value|0x0007
end_define

begin_define
define|#
directive|define
name|SCTP_AUTHENTICATION_EVENT
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_EVENT
value|0x0009
end_define

begin_comment
comment|/*  * socket option structs  */
end_comment

begin_struct
struct|struct
name|sctp_paddrparams
block|{
name|sctp_assoc_t
name|spp_assoc_id
decl_stmt|;
name|struct
name|sockaddr_storage
name|spp_address
decl_stmt|;
name|uint32_t
name|spp_hbinterval
decl_stmt|;
name|uint16_t
name|spp_pathmaxrxt
decl_stmt|;
name|uint32_t
name|spp_pathmtu
decl_stmt|;
name|uint32_t
name|spp_sackdelay
decl_stmt|;
name|uint32_t
name|spp_flags
decl_stmt|;
name|uint32_t
name|spp_ipv6_flowlabel
decl_stmt|;
name|uint8_t
name|spp_ipv4_tos
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SPP_HB_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SPP_HB_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SPP_HB_DEMAND
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SPP_PMTUD_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SPP_PMTUD_DISABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SPP_SACKDELAY_ENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SPP_SACKDELAY_DISABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SPP_HB_TIME_IS_ZERO
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SPP_IPV6_FLOWLABEL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SPP_IPV4_TOS
value|0x00000200
end_define

begin_struct
struct|struct
name|sctp_paddrinfo
block|{
name|sctp_assoc_t
name|spinfo_assoc_id
decl_stmt|;
name|struct
name|sockaddr_storage
name|spinfo_address
decl_stmt|;
name|int32_t
name|spinfo_state
decl_stmt|;
name|uint32_t
name|spinfo_cwnd
decl_stmt|;
name|uint32_t
name|spinfo_srtt
decl_stmt|;
name|uint32_t
name|spinfo_rto
decl_stmt|;
name|uint32_t
name|spinfo_mtu
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_rtoinfo
block|{
name|sctp_assoc_t
name|srto_assoc_id
decl_stmt|;
name|uint32_t
name|srto_initial
decl_stmt|;
name|uint32_t
name|srto_max
decl_stmt|;
name|uint32_t
name|srto_min
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_assocparams
block|{
name|sctp_assoc_t
name|sasoc_assoc_id
decl_stmt|;
name|uint16_t
name|sasoc_asocmaxrxt
decl_stmt|;
name|uint16_t
name|sasoc_number_peer_destinations
decl_stmt|;
name|uint32_t
name|sasoc_peer_rwnd
decl_stmt|;
name|uint32_t
name|sasoc_local_rwnd
decl_stmt|;
name|uint32_t
name|sasoc_cookie_life
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_setprim
block|{
name|sctp_assoc_t
name|ssp_assoc_id
decl_stmt|;
name|struct
name|sockaddr_storage
name|ssp_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_setpeerprim
block|{
name|sctp_assoc_t
name|sspp_assoc_id
decl_stmt|;
name|struct
name|sockaddr_storage
name|sspp_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_getaddresses
block|{
name|sctp_assoc_t
name|sget_assoc_id
decl_stmt|;
comment|/* addr is filled in for N * sockaddr_storage */
name|struct
name|sockaddr
name|addr
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_setstrm_timeout
block|{
name|sctp_assoc_t
name|ssto_assoc_id
decl_stmt|;
name|uint32_t
name|ssto_timeout
decl_stmt|;
name|uint32_t
name|ssto_streamid_start
decl_stmt|;
name|uint32_t
name|ssto_streamid_end
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_status
block|{
name|sctp_assoc_t
name|sstat_assoc_id
decl_stmt|;
name|int32_t
name|sstat_state
decl_stmt|;
name|uint32_t
name|sstat_rwnd
decl_stmt|;
name|uint16_t
name|sstat_unackdata
decl_stmt|;
name|uint16_t
name|sstat_penddata
decl_stmt|;
name|uint16_t
name|sstat_instrms
decl_stmt|;
name|uint16_t
name|sstat_outstrms
decl_stmt|;
name|uint32_t
name|sstat_fragmentation_point
decl_stmt|;
name|struct
name|sctp_paddrinfo
name|sstat_primary
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * AUTHENTICATION support  */
end_comment

begin_comment
comment|/* SCTP_AUTH_CHUNK */
end_comment

begin_struct
struct|struct
name|sctp_authchunk
block|{
name|uint8_t
name|sauth_chunk
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SCTP_AUTH_KEY */
end_comment

begin_struct
struct|struct
name|sctp_authkey
block|{
name|sctp_assoc_t
name|sca_assoc_id
decl_stmt|;
name|uint16_t
name|sca_keynumber
decl_stmt|;
name|uint8_t
name|sca_key
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SCTP_HMAC_IDENT */
end_comment

begin_struct
struct|struct
name|sctp_hmacalgo
block|{
name|uint16_t
name|shmac_idents
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* AUTH hmac_id */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_RSVD
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_SHA1
value|0x0001
end_define

begin_comment
comment|/* default, mandatory */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_MD5
value|0x0002
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_SHA256
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_SHA224
value|0x8001
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_SHA384
value|0x8002
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_SHA512
value|0x8003
end_define

begin_comment
comment|/* SCTP_AUTH_ACTIVE_KEY / SCTP_AUTH_DELETE_KEY */
end_comment

begin_struct
struct|struct
name|sctp_authkeyid
block|{
name|sctp_assoc_t
name|scact_assoc_id
decl_stmt|;
name|uint16_t
name|scact_keynumber
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SCTP_PEER_AUTH_CHUNKS / SCTP_LOCAL_AUTH_CHUNKS */
end_comment

begin_struct
struct|struct
name|sctp_authchunks
block|{
name|sctp_assoc_t
name|gauth_assoc_id
decl_stmt|;
name|uint8_t
name|gauth_chunks
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_assoc_value
block|{
name|sctp_assoc_t
name|assoc_id
decl_stmt|;
name|uint32_t
name|assoc_value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_ASOC_IDS_RET
value|255
end_define

begin_struct
struct|struct
name|sctp_assoc_ids
block|{
name|uint16_t
name|asls_assoc_start
decl_stmt|;
comment|/* array of index's start at 0 */
name|uint8_t
name|asls_numb_present
decl_stmt|;
name|uint8_t
name|asls_more_to_get
decl_stmt|;
name|sctp_assoc_t
name|asls_assoc_id
index|[
name|MAX_ASOC_IDS_RET
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_cwnd_args
block|{
name|struct
name|sctp_nets
modifier|*
name|net
decl_stmt|;
comment|/* network to */
name|uint32_t
name|cwnd_new_value
decl_stmt|;
comment|/* cwnd in k */
name|uint32_t
name|inflight
decl_stmt|;
comment|/* flightsize in k */
name|uint32_t
name|pseudo_cumack
decl_stmt|;
name|int
name|cwnd_augment
decl_stmt|;
comment|/* increment to it */
name|uint8_t
name|meets_pseudo_cumack
decl_stmt|;
name|uint8_t
name|need_new_pseudo_cumack
decl_stmt|;
name|uint8_t
name|cnt_in_send
decl_stmt|;
name|uint8_t
name|cnt_in_str
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_blk_args
block|{
name|uint32_t
name|onsb
decl_stmt|;
comment|/* in 1k bytes */
name|uint32_t
name|sndlen
decl_stmt|;
comment|/* len of send being attempted */
name|uint32_t
name|peer_rwnd
decl_stmt|;
comment|/* rwnd of peer */
name|uint16_t
name|send_sent_qcnt
decl_stmt|;
comment|/* chnk cnt */
name|uint16_t
name|stream_qcnt
decl_stmt|;
comment|/* chnk cnt */
name|uint16_t
name|chunks_on_oque
decl_stmt|;
comment|/* chunks out */
name|uint16_t
name|flight_size
decl_stmt|;
comment|/* flight size in k */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Max we can reset in one setting, note this is dictated not by the define  * but the size of a mbuf cluster so don't change this define and think you  * can specify more. You must do multiple resets if you want to reset more  * than SCTP_MAX_EXPLICIT_STR_RESET.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_EXPLICT_STR_RESET
value|1000
end_define

begin_define
define|#
directive|define
name|SCTP_RESET_LOCAL_RECV
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_RESET_LOCAL_SEND
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_RESET_BOTH
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCTP_RESET_TSN
value|0x0004
end_define

begin_struct
struct|struct
name|sctp_stream_reset
block|{
name|sctp_assoc_t
name|strrst_assoc_id
decl_stmt|;
name|uint16_t
name|strrst_flags
decl_stmt|;
name|uint16_t
name|strrst_num_streams
decl_stmt|;
comment|/* 0 == ALL */
name|uint16_t
name|strrst_list
index|[
literal|0
index|]
decl_stmt|;
comment|/* list if strrst_num_streams is not 0 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_get_nonce_values
block|{
name|sctp_assoc_t
name|gn_assoc_id
decl_stmt|;
name|uint32_t
name|gn_peers_tag
decl_stmt|;
name|uint32_t
name|gn_local_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Debugging logs */
end_comment

begin_struct
struct|struct
name|sctp_str_log
block|{
name|void
modifier|*
name|stcb
decl_stmt|;
name|uint32_t
name|n_tsn
decl_stmt|;
name|uint32_t
name|e_tsn
decl_stmt|;
name|uint16_t
name|n_sseq
decl_stmt|;
name|uint16_t
name|e_sseq
decl_stmt|;
name|uint16_t
name|strm
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_sb_log
block|{
name|void
modifier|*
name|stcb
decl_stmt|;
name|uint32_t
name|so_sbcc
decl_stmt|;
name|uint32_t
name|stcb_sbcc
decl_stmt|;
name|uint32_t
name|incr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_fr_log
block|{
name|uint32_t
name|largest_tsn
decl_stmt|;
name|uint32_t
name|largest_new_tsn
decl_stmt|;
name|uint32_t
name|tsn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_fr_map
block|{
name|uint32_t
name|base
decl_stmt|;
name|uint32_t
name|cum
decl_stmt|;
name|uint32_t
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_rwnd_log
block|{
name|uint32_t
name|rwnd
decl_stmt|;
name|uint32_t
name|send_size
decl_stmt|;
name|uint32_t
name|overhead
decl_stmt|;
name|uint32_t
name|new_rwnd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_mbcnt_log
block|{
name|uint32_t
name|total_queue_size
decl_stmt|;
name|uint32_t
name|size_change
decl_stmt|;
name|uint32_t
name|total_queue_mb_size
decl_stmt|;
name|uint32_t
name|mbcnt_change
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_sack_log
block|{
name|uint32_t
name|cumack
decl_stmt|;
name|uint32_t
name|oldcumack
decl_stmt|;
name|uint32_t
name|tsn
decl_stmt|;
name|uint16_t
name|numGaps
decl_stmt|;
name|uint16_t
name|numDups
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_lock_log
block|{
name|void
modifier|*
name|sock
decl_stmt|;
name|void
modifier|*
name|inp
decl_stmt|;
name|uint8_t
name|tcb_lock
decl_stmt|;
name|uint8_t
name|inp_lock
decl_stmt|;
name|uint8_t
name|info_lock
decl_stmt|;
name|uint8_t
name|sock_lock
decl_stmt|;
name|uint8_t
name|sockrcvbuf_lock
decl_stmt|;
name|uint8_t
name|socksndbuf_lock
decl_stmt|;
name|uint8_t
name|create_lock
decl_stmt|;
name|uint8_t
name|resv
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_rto_log
block|{
name|void
modifier|*
name|net
decl_stmt|;
name|uint32_t
name|rtt
decl_stmt|;
name|uint32_t
name|rttvar
decl_stmt|;
name|uint8_t
name|direction
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_nagle_log
block|{
name|void
modifier|*
name|stcb
decl_stmt|;
name|uint32_t
name|total_flight
decl_stmt|;
name|uint32_t
name|total_in_queue
decl_stmt|;
name|uint16_t
name|count_in_queue
decl_stmt|;
name|uint16_t
name|count_in_flight
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_sbwake_log
block|{
name|void
modifier|*
name|stcb
decl_stmt|;
name|uint16_t
name|send_q
decl_stmt|;
name|uint16_t
name|sent_q
decl_stmt|;
name|uint16_t
name|flight
decl_stmt|;
name|uint16_t
name|wake_cnt
decl_stmt|;
name|uint8_t
name|stream_qcnt
decl_stmt|;
comment|/* chnk cnt */
name|uint8_t
name|chunks_on_oque
decl_stmt|;
comment|/* chunks out */
name|uint8_t
name|sbflags
decl_stmt|;
name|uint8_t
name|sctpflags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_misc_info
block|{
name|uint32_t
name|log1
decl_stmt|;
name|uint32_t
name|log2
decl_stmt|;
name|uint32_t
name|log3
decl_stmt|;
name|uint32_t
name|log4
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_log_closing
block|{
name|void
modifier|*
name|inp
decl_stmt|;
name|void
modifier|*
name|stcb
decl_stmt|;
name|uint32_t
name|sctp_flags
decl_stmt|;
name|uint16_t
name|state
decl_stmt|;
name|int16_t
name|loc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_mbuf_log
block|{
name|struct
name|mbuf
modifier|*
name|mp
decl_stmt|;
name|caddr_t
name|ext
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
name|uint8_t
name|refcnt
decl_stmt|;
name|uint8_t
name|mbuf_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_cwnd_log
block|{
name|uint32_t
name|time_event
decl_stmt|;
name|uint8_t
name|from
decl_stmt|;
name|uint8_t
name|event_type
decl_stmt|;
name|uint8_t
name|resv
index|[
literal|2
index|]
decl_stmt|;
union|union
block|{
name|struct
name|sctp_log_closing
name|close
decl_stmt|;
name|struct
name|sctp_blk_args
name|blk
decl_stmt|;
name|struct
name|sctp_cwnd_args
name|cwnd
decl_stmt|;
name|struct
name|sctp_str_log
name|strlog
decl_stmt|;
name|struct
name|sctp_fr_log
name|fr
decl_stmt|;
name|struct
name|sctp_fr_map
name|map
decl_stmt|;
name|struct
name|sctp_rwnd_log
name|rwnd
decl_stmt|;
name|struct
name|sctp_mbcnt_log
name|mbcnt
decl_stmt|;
name|struct
name|sctp_sack_log
name|sack
decl_stmt|;
name|struct
name|sctp_lock_log
name|lock
decl_stmt|;
name|struct
name|sctp_rto_log
name|rto
decl_stmt|;
name|struct
name|sctp_sb_log
name|sb
decl_stmt|;
name|struct
name|sctp_nagle_log
name|nagle
decl_stmt|;
name|struct
name|sctp_sbwake_log
name|wake
decl_stmt|;
name|struct
name|sctp_mbuf_log
name|mb
decl_stmt|;
name|struct
name|sctp_misc_info
name|misc
decl_stmt|;
block|}
name|x
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_cwnd_log_req
block|{
name|int
name|num_in_log
decl_stmt|;
comment|/* Number in log */
name|int
name|num_ret
decl_stmt|;
comment|/* Number returned */
name|int
name|start_at
decl_stmt|;
comment|/* start at this one */
name|int
name|end_at
decl_stmt|;
comment|/* end at this one */
name|struct
name|sctp_cwnd_log
name|log
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctpstat
block|{
comment|/* MIB according to RFC 3873 */
name|u_long
name|sctps_currestab
decl_stmt|;
comment|/* sctpStats  1   (Gauge32) */
name|u_long
name|sctps_activeestab
decl_stmt|;
comment|/* sctpStats  2 (Counter32) */
name|u_long
name|sctps_restartestab
decl_stmt|;
name|u_long
name|sctps_collisionestab
decl_stmt|;
name|u_long
name|sctps_passiveestab
decl_stmt|;
comment|/* sctpStats  3 (Counter32) */
name|u_long
name|sctps_aborted
decl_stmt|;
comment|/* sctpStats  4 (Counter32) */
name|u_long
name|sctps_shutdown
decl_stmt|;
comment|/* sctpStats  5 (Counter32) */
name|u_long
name|sctps_outoftheblue
decl_stmt|;
comment|/* sctpStats  6 (Counter32) */
name|u_long
name|sctps_checksumerrors
decl_stmt|;
comment|/* sctpStats  7 (Counter32) */
name|u_long
name|sctps_outcontrolchunks
decl_stmt|;
comment|/* sctpStats  8 (Counter64) */
name|u_long
name|sctps_outorderchunks
decl_stmt|;
comment|/* sctpStats  9 (Counter64) */
name|u_long
name|sctps_outunorderchunks
decl_stmt|;
comment|/* sctpStats 10 (Counter64) */
name|u_long
name|sctps_incontrolchunks
decl_stmt|;
comment|/* sctpStats 11 (Counter64) */
name|u_long
name|sctps_inorderchunks
decl_stmt|;
comment|/* sctpStats 12 (Counter64) */
name|u_long
name|sctps_inunorderchunks
decl_stmt|;
comment|/* sctpStats 13 (Counter64) */
name|u_long
name|sctps_fragusrmsgs
decl_stmt|;
comment|/* sctpStats 14 (Counter64) */
name|u_long
name|sctps_reasmusrmsgs
decl_stmt|;
comment|/* sctpStats 15 (Counter64) */
name|u_long
name|sctps_outpackets
decl_stmt|;
comment|/* sctpStats 16 (Counter64) */
name|u_long
name|sctps_inpackets
decl_stmt|;
comment|/* sctpStats 17 (Counter64) */
name|struct
name|timeval
name|sctps_discontinuitytime
decl_stmt|;
comment|/* sctpStats 18 (TimeStamp) */
comment|/* input statistics: */
name|u_long
name|sctps_recvpackets
decl_stmt|;
comment|/* total input packets        */
name|u_long
name|sctps_recvdatagrams
decl_stmt|;
comment|/* total input datagrams      */
name|u_long
name|sctps_recvpktwithdata
decl_stmt|;
name|u_long
name|sctps_recvsacks
decl_stmt|;
comment|/* total input SACK chunks    */
name|u_long
name|sctps_recvdata
decl_stmt|;
comment|/* total input DATA chunks    */
name|u_long
name|sctps_recvdupdata
decl_stmt|;
comment|/* total input duplicate DATA chunks */
name|u_long
name|sctps_recvheartbeat
decl_stmt|;
comment|/* total input HB chunks      */
name|u_long
name|sctps_recvheartbeatack
decl_stmt|;
comment|/* total input HB-ACK chunks  */
name|u_long
name|sctps_recvecne
decl_stmt|;
comment|/* total input ECNE chunks    */
name|u_long
name|sctps_recvauth
decl_stmt|;
comment|/* total input AUTH chunks    */
name|u_long
name|sctps_recvauthmissing
decl_stmt|;
comment|/* total input chunks missing AUTH */
name|u_long
name|sctps_recvivalhmacid
decl_stmt|;
comment|/* total number of invalid HMAC ids 					 * received */
name|u_long
name|sctps_recvivalkeyid
decl_stmt|;
comment|/* total number of invalid secret ids 					 * received */
name|u_long
name|sctps_recvauthfailed
decl_stmt|;
comment|/* total number of auth failed */
name|u_long
name|sctps_recvexpress
decl_stmt|;
comment|/* total fast path receives all one 					 * chunk */
name|u_long
name|sctps_recvexpressm
decl_stmt|;
comment|/* total fast path multi-part data */
comment|/* output statistics: */
name|u_long
name|sctps_sendpackets
decl_stmt|;
comment|/* total output packets       */
name|u_long
name|sctps_sendsacks
decl_stmt|;
comment|/* total output SACKs         */
name|u_long
name|sctps_senddata
decl_stmt|;
comment|/* total output DATA chunks   */
name|u_long
name|sctps_sendretransdata
decl_stmt|;
comment|/* total output retransmitted DATA 					 * chunks */
name|u_long
name|sctps_sendfastretrans
decl_stmt|;
comment|/* total output fast retransmitted 					 * DATA chunks */
name|u_long
name|sctps_sendmultfastretrans
decl_stmt|;
comment|/* U-del */
name|u_long
name|sctps_sendheartbeat
decl_stmt|;
comment|/* total output HB chunks     */
name|u_long
name|sctps_sendecne
decl_stmt|;
comment|/* total output ECNE chunks    */
name|u_long
name|sctps_sendauth
decl_stmt|;
comment|/* total output AUTH chunks FIXME   */
name|u_long
name|sctps_senderrors
decl_stmt|;
comment|/* ip_output error counter */
comment|/* PCKDROPREP statistics: */
name|u_long
name|sctps_pdrpfmbox
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpfehos
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpmbda
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpmbct
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpbwrpt
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpcrupt
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpnedat
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrppdbrk
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrptsnnf
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpdnfnd
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpdiwnp
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpdizrw
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpbadd
decl_stmt|;
comment|/* */
name|u_long
name|sctps_pdrpmark
decl_stmt|;
comment|/* */
comment|/* timeouts */
name|u_long
name|sctps_timoiterator
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timodata
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timowindowprobe
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoinit
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timosack
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoshutdown
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoheartbeat
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timocookie
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timosecret
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timopathmtu
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoshutdownack
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoshutdownguard
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timostrmrst
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoearlyfr
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoasconf
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoautoclose
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoassockill
decl_stmt|;
comment|/* */
name|u_long
name|sctps_timoinpkill
decl_stmt|;
comment|/* */
comment|/* Early fast retransmission counters */
name|u_long
name|sctps_earlyfrstart
decl_stmt|;
name|u_long
name|sctps_earlyfrstop
decl_stmt|;
name|u_long
name|sctps_earlyfrmrkretrans
decl_stmt|;
name|u_long
name|sctps_earlyfrstpout
decl_stmt|;
name|u_long
name|sctps_earlyfrstpidsck1
decl_stmt|;
name|u_long
name|sctps_earlyfrstpidsck2
decl_stmt|;
name|u_long
name|sctps_earlyfrstpidsck3
decl_stmt|;
name|u_long
name|sctps_earlyfrstpidsck4
decl_stmt|;
name|u_long
name|sctps_earlyfrstrid
decl_stmt|;
name|u_long
name|sctps_earlyfrstrout
decl_stmt|;
name|u_long
name|sctps_earlyfrstrtmr
decl_stmt|;
comment|/* otheres */
name|u_long
name|sctps_hdrops
decl_stmt|;
comment|/* packet shorter than header */
name|u_long
name|sctps_badsum
decl_stmt|;
comment|/* checksum error             */
name|u_long
name|sctps_noport
decl_stmt|;
comment|/* no endpoint for port       */
name|u_long
name|sctps_badvtag
decl_stmt|;
comment|/* bad v-tag                  */
name|u_long
name|sctps_badsid
decl_stmt|;
comment|/* bad SID                    */
name|u_long
name|sctps_nomem
decl_stmt|;
comment|/* no memory                  */
name|u_long
name|sctps_fastretransinrtt
decl_stmt|;
comment|/* number of multiple FR in a RTT 					 * window */
name|u_long
name|sctps_markedretrans
decl_stmt|;
name|u_long
name|sctps_naglesent
decl_stmt|;
comment|/* nagle allowed sending      */
name|u_long
name|sctps_naglequeued
decl_stmt|;
comment|/* nagle does't allow sending */
name|u_long
name|sctps_maxburstqueued
decl_stmt|;
comment|/* max burst dosn't allow sending */
name|u_long
name|sctps_ifnomemqueued
decl_stmt|;
comment|/* */
name|u_long
name|sctps_windowprobed
decl_stmt|;
comment|/* total number of window probes sent */
name|u_long
name|sctps_lowlevelerr
decl_stmt|;
name|u_long
name|sctps_lowlevelerrusr
decl_stmt|;
name|u_long
name|sctps_datadropchklmt
decl_stmt|;
name|u_long
name|sctps_datadroprwnd
decl_stmt|;
name|u_long
name|sctps_ecnereducedcwnd
decl_stmt|;
name|u_long
name|sctps_vtagexpress
decl_stmt|;
comment|/* Used express lookup via vtag */
name|u_long
name|sctps_vtagbogus
decl_stmt|;
comment|/* Collision in express lookup. */
name|u_long
name|sctps_primary_randry
decl_stmt|;
comment|/* Number of times the sender ran dry 					 * of user data on primary */
name|u_long
name|sctps_cmt_randry
decl_stmt|;
comment|/* Same for above */
name|u_long
name|sctps_slowpath_sack
decl_stmt|;
comment|/* Sacks the slow way */
name|u_long
name|sctps_wu_sacks_sent
decl_stmt|;
comment|/* Window Update only sacks sent */
name|u_long
name|sctps_sends_with_flags
decl_stmt|;
comment|/* number of sends with sinfo_flags 					 * !=0 */
name|u_long
name|sctps_sends_with_unord
decl_stmt|;
name|u_long
name|sctps_sends_with_eof
decl_stmt|;
name|u_long
name|sctps_sends_with_abort
decl_stmt|;
name|u_long
name|sctps_protocol_drain_calls
decl_stmt|;
name|u_long
name|sctps_protocol_drains_done
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_STAT_INCR
parameter_list|(
name|_x
parameter_list|)
value|SCTP_STAT_INCR_BY(_x,1)
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_DECR
parameter_list|(
name|_x
parameter_list|)
value|SCTP_STAT_DECR_BY(_x,1)
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_INCR_BY
parameter_list|(
name|_x
parameter_list|,
name|_d
parameter_list|)
value|atomic_add_long(&sctpstat._x, _d)
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_DECR_BY
parameter_list|(
name|_x
parameter_list|,
name|_d
parameter_list|)
value|atomic_add_long(&sctpstat._x, -(_d))
end_define

begin_comment
comment|/* The following macros are for handling MIB values, */
end_comment

begin_define
define|#
directive|define
name|SCTP_STAT_INCR_COUNTER32
parameter_list|(
name|_x
parameter_list|)
value|SCTP_STAT_INCR(_x)
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_INCR_COUNTER64
parameter_list|(
name|_x
parameter_list|)
value|SCTP_STAT_INCR(_x)
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_INCR_GAUGE32
parameter_list|(
name|_x
parameter_list|)
value|SCTP_STAT_INCR(_x)
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_DECR_COUNTER32
parameter_list|(
name|_x
parameter_list|)
value|SCTP_STAT_DECR(_x)
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_DECR_COUNTER64
parameter_list|(
name|_x
parameter_list|)
value|SCTP_STAT_DECR(_x)
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_DECR_GAUGE32
parameter_list|(
name|_x
parameter_list|)
value|SCTP_STAT_DECR(_x)
end_define

begin_union
union|union
name|sctp_sockstore
block|{
ifdef|#
directive|ifdef
name|AF_INET
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|AF_INET6
name|struct
name|sockaddr_in6
name|sin6
decl_stmt|;
endif|#
directive|endif
name|struct
name|sockaddr
name|sa
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|xsctp_inpcb
block|{
name|uint32_t
name|last
decl_stmt|;
name|uint16_t
name|local_port
decl_stmt|;
name|uint16_t
name|number_local_addresses
decl_stmt|;
name|uint32_t
name|number_associations
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|features
decl_stmt|;
name|uint32_t
name|total_sends
decl_stmt|;
name|uint32_t
name|total_recvs
decl_stmt|;
name|uint32_t
name|total_nospaces
decl_stmt|;
comment|/* add more endpoint specific data here */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xsctp_tcb
block|{
name|uint16_t
name|LocalPort
decl_stmt|;
comment|/* sctpAssocEntry 3   */
name|uint16_t
name|RemPort
decl_stmt|;
comment|/* sctpAssocEntry 4   */
name|union
name|sctp_sockstore
name|RemPrimAddr
decl_stmt|;
comment|/* sctpAssocEntry 5/6 */
name|uint32_t
name|HeartBeatInterval
decl_stmt|;
comment|/* sctpAssocEntry 7   */
name|uint32_t
name|State
decl_stmt|;
comment|/* sctpAssocEntry 8   */
name|uint32_t
name|InStreams
decl_stmt|;
comment|/* sctpAssocEntry 9   */
name|uint32_t
name|OutStreams
decl_stmt|;
comment|/* sctpAssocEntry 10  */
name|uint32_t
name|MaxRetr
decl_stmt|;
comment|/* sctpAssocEntry 11  */
name|uint32_t
name|PrimProcess
decl_stmt|;
comment|/* sctpAssocEntry 12  */
name|uint32_t
name|T1expireds
decl_stmt|;
comment|/* sctpAssocEntry 13  */
name|uint32_t
name|T2expireds
decl_stmt|;
comment|/* sctpAssocEntry 14  */
name|uint32_t
name|RtxChunks
decl_stmt|;
comment|/* sctpAssocEntry 15  */
name|struct
name|timeval
name|StartTime
decl_stmt|;
comment|/* sctpAssocEntry 16  */
name|struct
name|timeval
name|DiscontinuityTime
decl_stmt|;
comment|/* sctpAssocEntry 17  */
name|uint32_t
name|total_sends
decl_stmt|;
name|uint32_t
name|total_recvs
decl_stmt|;
name|uint32_t
name|local_tag
decl_stmt|;
name|uint32_t
name|remote_tag
decl_stmt|;
name|uint32_t
name|initial_tsn
decl_stmt|;
name|uint32_t
name|highest_tsn
decl_stmt|;
name|uint32_t
name|cumulative_tsn
decl_stmt|;
name|uint32_t
name|cumulative_tsn_ack
decl_stmt|;
comment|/* add more association specific data here */
name|uint16_t
name|number_local_addresses
decl_stmt|;
name|uint16_t
name|number_remote_addresses
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xsctp_laddr
block|{
name|union
name|sctp_sockstore
name|LocalAddr
decl_stmt|;
comment|/* sctpAssocLocalAddrEntry 1/2 */
name|struct
name|timeval
name|LocalStartTime
decl_stmt|;
comment|/* sctpAssocLocalAddrEntry 3   */
comment|/* add more local address specific data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xsctp_raddr
block|{
name|union
name|sctp_sockstore
name|RemAddr
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 1/2 */
name|uint8_t
name|RemAddrActive
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 3   */
name|uint8_t
name|RemAddrConfirmed
decl_stmt|;
comment|/* */
name|uint8_t
name|RemAddrHBActive
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 4   */
name|uint32_t
name|RemAddrRTO
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 5   */
name|uint32_t
name|RemAddrMaxPathRtx
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 6   */
name|uint32_t
name|RemAddrRtx
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 7   */
name|uint32_t
name|RemAddrErrorCounter
decl_stmt|;
comment|/* */
name|uint32_t
name|RemAddrCwnd
decl_stmt|;
comment|/* */
name|uint32_t
name|RemAddrFlightSize
decl_stmt|;
comment|/* */
name|struct
name|timeval
name|RemAddrStartTime
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 8   */
comment|/* add more remote address specific data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Kernel defined for sctp_send  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_function_decl
name|int
name|sctp_lower_sosend
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|struct
name|mbuf
modifier|*
name|top
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|use_rcvinfo
parameter_list|,
name|struct
name|sctp_sndrcvinfo
modifier|*
name|srcv
parameter_list|,
name|struct
name|thread
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_sorecvmsg
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|from
parameter_list|,
name|int
name|fromlen
parameter_list|,
name|int
modifier|*
name|msg_flags
parameter_list|,
name|struct
name|sctp_sndrcvinfo
modifier|*
name|sinfo
parameter_list|,
name|int
name|filling_sinfo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * API system calls  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
end_if

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|sctp_peeloff
name|__P
argument_list|(
operator|(
name|int
operator|,
name|sctp_assoc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp_bindx
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp_connectx
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp_getaddrlen
name|__P
argument_list|(
operator|(
name|sa_family_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp_getpaddrs
name|__P
argument_list|(
operator|(
name|int
operator|,
name|sctp_assoc_t
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sctp_freepaddrs
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp_getladdrs
name|__P
argument_list|(
operator|(
name|int
operator|,
name|sctp_assoc_t
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sctp_freeladdrs
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sctp_opt_info
name|__P
argument_list|(
operator|(
name|int
operator|,
name|sctp_assoc_t
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|socklen_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sctp_sendmsg
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|,
specifier|const
expr|struct
name|sockaddr
operator|*
operator|,
name|socklen_t
operator|,
name|uint32_t
operator|,
name|uint32_t
operator|,
name|uint16_t
operator|,
name|uint32_t
operator|,
name|uint32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sctp_send
name|__P
argument_list|(
operator|(
name|int
name|sd
operator|,
specifier|const
name|void
operator|*
name|msg
operator|,
name|size_t
name|len
operator|,
specifier|const
expr|struct
name|sctp_sndrcvinfo
operator|*
name|sinfo
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sctp_sendx
name|__P
argument_list|(
operator|(
name|int
name|sd
operator|,
specifier|const
name|void
operator|*
name|msg
operator|,
name|size_t
name|len
operator|,
expr|struct
name|sockaddr
operator|*
name|addrs
operator|,
name|int
name|addrcnt
operator|,
expr|struct
name|sctp_sndrcvinfo
operator|*
name|sinfo
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sctp_sendmsgx
name|__P
argument_list|(
operator|(
name|int
name|sd
operator|,
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|,
name|uint32_t
operator|,
name|uint32_t
operator|,
name|uint16_t
operator|,
name|uint32_t
operator|,
name|uint32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sctp_assoc_t
name|sctp_getassocid
name|__P
argument_list|(
operator|(
name|int
name|sd
operator|,
expr|struct
name|sockaddr
operator|*
name|sa
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sctp_recvmsg
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|socklen_t
operator|*
operator|,
expr|struct
name|sctp_sndrcvinfo
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__sctp_uio_h__ */
end_comment

end_unit

