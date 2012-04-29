begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2007, by Cisco Systems, Inc. All rights reserved.  * Copyright (c) 2008-2011, by Randall Stewart. All rights reserved.  * Copyright (c) 2008-2011, by Michael Tuexen. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<netinet/in.h>
end_include

begin_typedef
typedef|typedef
name|uint32_t
name|sctp_assoc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCTP_FUTURE_ASSOC
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_CURRENT_ASSOC
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_ALL_ASSOC
value|2
end_define

begin_struct
struct|struct
name|sctp_event
block|{
name|sctp_assoc_t
name|se_assoc_id
decl_stmt|;
name|uint16_t
name|se_type
decl_stmt|;
name|uint8_t
name|se_on
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Compatibility to previous define's */
end_comment

begin_define
define|#
directive|define
name|sctp_stream_reset_events
value|sctp_stream_reset_event
end_define

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
name|sctp_sender_dry_event
decl_stmt|;
name|uint8_t
name|sctp_stream_reset_event
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

begin_define
define|#
directive|define
name|SCTP_SNDINFO
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_RCVINFO
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCTP_NXTINFO
value|0x0006
end_define

begin_define
define|#
directive|define
name|SCTP_PRINFO
value|0x0007
end_define

begin_define
define|#
directive|define
name|SCTP_AUTHINFO
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_DSTADDRV4
value|0x0009
end_define

begin_define
define|#
directive|define
name|SCTP_DSTADDRV6
value|0x000a
end_define

begin_comment
comment|/*  * ancillary data structures  */
end_comment

begin_struct
struct|struct
name|sctp_initmsg
block|{
name|uint16_t
name|sinit_num_ostreams
decl_stmt|;
name|uint16_t
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
comment|/* We add 96 bytes to the size of sctp_sndrcvinfo.  * This makes the current structure 128 bytes long  * which is nicely 64 bit aligned but also has room  * for us to add more and keep ABI compatibility.  * For example, already we have the sctp_extrcvinfo  * when enabled which is 48 bytes.  */
end_comment

begin_comment
comment|/*  * The assoc up needs a verfid  * all sendrcvinfo's need a verfid for SENDING only.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_ALIGN_RESV_PAD
value|92
end_define

begin_define
define|#
directive|define
name|SCTP_ALIGN_RESV_PAD_SHORT
value|76
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
name|uint16_t
name|sinfo_keynumber
decl_stmt|;
name|uint16_t
name|sinfo_keynumber_valid
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
name|sreinfo_next_flags
decl_stmt|;
name|uint16_t
name|sreinfo_next_stream
decl_stmt|;
name|uint32_t
name|sreinfo_next_aid
decl_stmt|;
name|uint32_t
name|sreinfo_next_length
decl_stmt|;
name|uint32_t
name|sreinfo_next_ppid
decl_stmt|;
name|uint16_t
name|sinfo_keynumber
decl_stmt|;
name|uint16_t
name|sinfo_keynumber_valid
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

begin_struct
struct|struct
name|sctp_sndinfo
block|{
name|uint16_t
name|snd_sid
decl_stmt|;
name|uint16_t
name|snd_flags
decl_stmt|;
name|uint32_t
name|snd_ppid
decl_stmt|;
name|uint32_t
name|snd_context
decl_stmt|;
name|sctp_assoc_t
name|snd_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_prinfo
block|{
name|uint16_t
name|pr_policy
decl_stmt|;
name|uint32_t
name|pr_value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_default_prinfo
block|{
name|uint16_t
name|pr_policy
decl_stmt|;
name|uint32_t
name|pr_value
decl_stmt|;
name|sctp_assoc_t
name|pr_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_authinfo
block|{
name|uint16_t
name|auth_keyid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_rcvinfo
block|{
name|uint16_t
name|rcv_sid
decl_stmt|;
name|uint16_t
name|rcv_ssn
decl_stmt|;
name|uint16_t
name|rcv_flags
decl_stmt|;
name|uint32_t
name|rcv_ppid
decl_stmt|;
name|uint32_t
name|rcv_tsn
decl_stmt|;
name|uint32_t
name|rcv_cumtsn
decl_stmt|;
name|uint32_t
name|rcv_context
decl_stmt|;
name|sctp_assoc_t
name|rcv_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_nxtinfo
block|{
name|uint16_t
name|nxt_sid
decl_stmt|;
name|uint16_t
name|nxt_flags
decl_stmt|;
name|uint32_t
name|nxt_ppid
decl_stmt|;
name|uint32_t
name|nxt_length
decl_stmt|;
name|sctp_assoc_t
name|nxt_assoc_id
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
name|sctp_recvv_rn
block|{
name|struct
name|sctp_rcvinfo
name|recvv_rcvinfo
decl_stmt|;
name|struct
name|sctp_nxtinfo
name|recvv_nxtinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_RECVV_NOINFO
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_RECVV_RCVINFO
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_RECVV_NXTINFO
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_RECVV_RN
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_SENDV_NOINFO
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_SENDV_SNDINFO
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_SENDV_PRINFO
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_SENDV_AUTHINFO
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_SENDV_SPA
value|4
end_define

begin_struct
struct|struct
name|sctp_sendv_spa
block|{
name|uint32_t
name|sendv_flags
decl_stmt|;
name|struct
name|sctp_sndinfo
name|sendv_sndinfo
decl_stmt|;
name|struct
name|sctp_prinfo
name|sendv_prinfo
decl_stmt|;
name|struct
name|sctp_authinfo
name|sendv_authinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_SEND_SNDINFO_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_SEND_PRINFO_VALID
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_SEND_AUTHINFO_VALID
value|0x00000004
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
name|SCTP_NOTIFICATION
value|0x0010
end_define

begin_comment
comment|/* next message is a notification */
end_comment

begin_define
define|#
directive|define
name|SCTP_COMPLETE
value|0x0020
end_define

begin_comment
comment|/* next message is complete */
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
name|SCTP_SACK_IMMEDIATELY
value|0x4000
end_define

begin_comment
comment|/* Set I-Bit */
end_comment

begin_define
define|#
directive|define
name|INVALID_SINFO_FLAG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xfffffff0 \& ~(SCTP_EOF | SCTP_ABORT | SCTP_UNORDERED |\ 				        SCTP_ADDR_OVER | SCTP_SENDALL | SCTP_EOR |\ 					SCTP_SACK_IMMEDIATELY)) != 0)
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
name|SCTP_PR_SCTP_NONE
value|0x0000
end_define

begin_comment
comment|/* Reliable transfer */
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
value|((x)& 0x0f)
end_define

begin_define
define|#
directive|define
name|PR_SCTP_ENABLED
parameter_list|(
name|x
parameter_list|)
value|(PR_SCTP_POLICY(x) != SCTP_PR_SCTP_NONE)
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
name|uint8_t
name|spc_padding
index|[
literal|4
index|]
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

begin_define
define|#
directive|define
name|SCTP_ACTIVE
value|0x0001
end_define

begin_comment
comment|/* SCTP_ADDR_REACHABLE */
end_comment

begin_define
define|#
directive|define
name|SCTP_INACTIVE
value|0x0002
end_define

begin_comment
comment|/* neither SCTP_ADDR_REACHABLE nor 					 * SCTP_ADDR_UNCONFIRMED */
end_comment

begin_define
define|#
directive|define
name|SCTP_UNCONFIRMED
value|0x0200
end_define

begin_comment
comment|/* SCTP_ADDR_UNCONFIRMED */
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
index|[]
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
comment|/* compatible old spelling */
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
name|uint16_t
name|pdapi_stream
decl_stmt|;
name|uint16_t
name|pdapi_seq
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
name|SCTP_AUTH_NEW_KEY
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_NEWKEY
value|SCTP_AUTH_NEW_KEY
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_NO_AUTH
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_FREE_KEY
value|0x0003
end_define

begin_struct
struct|struct
name|sctp_sender_dry_event
block|{
name|uint16_t
name|sender_dry_type
decl_stmt|;
name|uint16_t
name|sender_dry_flags
decl_stmt|;
name|uint32_t
name|sender_dry_length
decl_stmt|;
name|sctp_assoc_t
name|sender_dry_assoc_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Stream reset event - subscribe to SCTP_STREAM_RESET_EVENT  */
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
name|strreset_stream_list
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flags in stream_reset_event (strreset_flags) */
end_comment

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_INCOMING_SSN
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_OUTGOING_SSN
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_DENIED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_FAILED
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_CHANGED_DENIED
value|0x0010
end_define

begin_comment
comment|/*  * Assoc reset event - subscribe to SCTP_ASSOC_RESET_EVENT  */
end_comment

begin_struct
struct|struct
name|sctp_assoc_reset_event
block|{
name|uint16_t
name|assocreset_type
decl_stmt|;
name|uint16_t
name|assocreset_flags
decl_stmt|;
name|uint32_t
name|assocreset_length
decl_stmt|;
name|sctp_assoc_t
name|assocreset_assoc_id
decl_stmt|;
name|uint32_t
name|assocreset_local_tsn
decl_stmt|;
name|uint32_t
name|assocreset_remote_tsn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_ASSOC_RESET_DENIED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_ASSOC_RESET_FAILED
value|0x0008
end_define

begin_comment
comment|/*  * Stream change event - subscribe to SCTP_STREAM_CHANGE_EVENT  */
end_comment

begin_struct
struct|struct
name|sctp_stream_change_event
block|{
name|uint16_t
name|strchange_type
decl_stmt|;
name|uint16_t
name|strchange_flags
decl_stmt|;
name|uint32_t
name|strchange_length
decl_stmt|;
name|sctp_assoc_t
name|strchange_assoc_id
decl_stmt|;
name|uint16_t
name|strchange_instrms
decl_stmt|;
name|uint16_t
name|strchange_outstrms
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_STREAM_CHANGE_DENIED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_CHANGE_FAILED
value|0x0008
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
comment|/* compatibility same as above */
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
name|sctp_sender_dry_event
name|sn_sender_dry_event
decl_stmt|;
name|struct
name|sctp_stream_reset_event
name|sn_strreset_event
decl_stmt|;
name|struct
name|sctp_assoc_reset_event
name|sn_assocreset_event
decl_stmt|;
name|struct
name|sctp_stream_change_event
name|sn_strchange_event
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

begin_define
define|#
directive|define
name|SCTP_SENDER_DRY_EVENT
value|0x000a
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFICATIONS_STOPPED_EVENT
value|0x000b
end_define

begin_comment
comment|/* we don't send this */
end_comment

begin_define
define|#
directive|define
name|SCTP_ASSOC_RESET_EVENT
value|0x000c
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_CHANGE_EVENT
value|0x000d
end_define

begin_comment
comment|/*  * socket option structs  */
end_comment

begin_struct
struct|struct
name|sctp_paddrparams
block|{
name|struct
name|sockaddr_storage
name|spp_address
decl_stmt|;
name|sctp_assoc_t
name|spp_assoc_id
decl_stmt|;
name|uint32_t
name|spp_hbinterval
decl_stmt|;
name|uint32_t
name|spp_pathmtu
decl_stmt|;
name|uint32_t
name|spp_flags
decl_stmt|;
name|uint32_t
name|spp_ipv6_flowlabel
decl_stmt|;
name|uint16_t
name|spp_pathmaxrxt
decl_stmt|;
name|uint8_t
name|spp_dscp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|spp_ipv4_tos
value|spp_dscp
end_define

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
name|SPP_DSCP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SPP_IPV4_TOS
value|SPP_DSCP
end_define

begin_struct
struct|struct
name|sctp_paddrthlds
block|{
name|struct
name|sockaddr_storage
name|spt_address
decl_stmt|;
name|sctp_assoc_t
name|spt_assoc_id
decl_stmt|;
name|uint16_t
name|spt_pathmaxrxt
decl_stmt|;
name|uint16_t
name|spt_pathpfthld
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_paddrinfo
block|{
name|struct
name|sockaddr_storage
name|spinfo_address
decl_stmt|;
name|sctp_assoc_t
name|spinfo_assoc_id
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
name|uint32_t
name|sasoc_peer_rwnd
decl_stmt|;
name|uint32_t
name|sasoc_local_rwnd
decl_stmt|;
name|uint32_t
name|sasoc_cookie_life
decl_stmt|;
name|uint16_t
name|sasoc_asocmaxrxt
decl_stmt|;
name|uint16_t
name|sasoc_number_peer_destinations
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_setprim
block|{
name|struct
name|sockaddr_storage
name|ssp_addr
decl_stmt|;
name|sctp_assoc_t
name|ssp_assoc_id
decl_stmt|;
name|uint8_t
name|ssp_padding
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_setpeerprim
block|{
name|struct
name|sockaddr_storage
name|sspp_addr
decl_stmt|;
name|sctp_assoc_t
name|sspp_assoc_id
decl_stmt|;
name|uint8_t
name|sspp_padding
index|[
literal|4
index|]
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
name|uint16_t
name|sca_keylength
decl_stmt|;
name|uint8_t
name|sca_key
index|[]
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
name|uint32_t
name|shmac_number_of_idents
decl_stmt|;
name|uint16_t
name|shmac_idents
index|[]
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
name|SCTP_AUTH_HMAC_ID_SHA256
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_SHA224
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_SHA384
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_HMAC_ID_SHA512
value|0x0006
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
index|[]
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

begin_struct
struct|struct
name|sctp_cc_option
block|{
name|int
name|option
decl_stmt|;
name|struct
name|sctp_assoc_value
name|aid_value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_stream_value
block|{
name|sctp_assoc_t
name|assoc_id
decl_stmt|;
name|uint16_t
name|stream_id
decl_stmt|;
name|uint16_t
name|stream_value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_assoc_ids
block|{
name|uint32_t
name|gaids_number_of_ids
decl_stmt|;
name|sctp_assoc_t
name|gaids_assoc_id
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_sack_info
block|{
name|sctp_assoc_t
name|sack_assoc_id
decl_stmt|;
name|uint32_t
name|sack_delay
decl_stmt|;
name|uint32_t
name|sack_freq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_timeouts
block|{
name|sctp_assoc_t
name|stimo_assoc_id
decl_stmt|;
name|uint32_t
name|stimo_init
decl_stmt|;
name|uint32_t
name|stimo_data
decl_stmt|;
name|uint32_t
name|stimo_sack
decl_stmt|;
name|uint32_t
name|stimo_shutdown
decl_stmt|;
name|uint32_t
name|stimo_heartbeat
decl_stmt|;
name|uint32_t
name|stimo_cookie
decl_stmt|;
name|uint32_t
name|stimo_shutdownack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_udpencaps
block|{
name|struct
name|sockaddr_storage
name|sue_address
decl_stmt|;
name|sctp_assoc_t
name|sue_assoc_id
decl_stmt|;
name|uint16_t
name|sue_port
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
comment|/* FIXME: LP64 issue */
name|uint32_t
name|cwnd_new_value
decl_stmt|;
comment|/* cwnd in k */
name|uint32_t
name|pseudo_cumack
decl_stmt|;
name|uint16_t
name|inflight
decl_stmt|;
comment|/* flightsize in k */
name|uint16_t
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

begin_struct
struct|struct
name|sctp_reset_streams
block|{
name|sctp_assoc_t
name|srs_assoc_id
decl_stmt|;
name|uint16_t
name|srs_flags
decl_stmt|;
name|uint16_t
name|srs_number_streams
decl_stmt|;
comment|/* 0 == ALL */
name|uint16_t
name|srs_stream_list
index|[]
decl_stmt|;
comment|/* list if strrst_num_streams is not 0 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_add_streams
block|{
name|sctp_assoc_t
name|sas_assoc_id
decl_stmt|;
name|uint16_t
name|sas_instrms
decl_stmt|;
name|uint16_t
name|sas_outstrms
decl_stmt|;
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
comment|/* FIXME: LP64 issue */
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
comment|/* FIXME: LP64 issue */
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
comment|/* FIXME: LP64 issue */
name|void
modifier|*
name|inp
decl_stmt|;
comment|/* FIXME: LP64 issue */
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
comment|/* FIXME: LP64 issue */
name|uint32_t
name|rtt
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
comment|/* FIXME: LP64 issue */
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
comment|/* FIXME: LP64 issue */
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
comment|/* FIXME: LP64 issue */
name|void
modifier|*
name|stcb
decl_stmt|;
comment|/* FIXME: LP64 issue */
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
comment|/* FIXME: LP64 issue */
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
name|uint64_t
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
name|int32_t
name|num_in_log
decl_stmt|;
comment|/* Number in log */
name|int32_t
name|num_ret
decl_stmt|;
comment|/* Number returned */
name|int32_t
name|start_at
decl_stmt|;
comment|/* start at this one */
name|int32_t
name|end_at
decl_stmt|;
comment|/* end at this one */
name|struct
name|sctp_cwnd_log
name|log
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_timeval
block|{
name|uint32_t
name|tv_sec
decl_stmt|;
name|uint32_t
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctpstat
block|{
name|struct
name|sctp_timeval
name|sctps_discontinuitytime
decl_stmt|;
comment|/* sctpStats 18 							 * (TimeStamp) */
comment|/* MIB according to RFC 3873 */
name|uint32_t
name|sctps_currestab
decl_stmt|;
comment|/* sctpStats  1   (Gauge32) */
name|uint32_t
name|sctps_activeestab
decl_stmt|;
comment|/* sctpStats  2 (Counter32) */
name|uint32_t
name|sctps_restartestab
decl_stmt|;
name|uint32_t
name|sctps_collisionestab
decl_stmt|;
name|uint32_t
name|sctps_passiveestab
decl_stmt|;
comment|/* sctpStats  3 (Counter32) */
name|uint32_t
name|sctps_aborted
decl_stmt|;
comment|/* sctpStats  4 (Counter32) */
name|uint32_t
name|sctps_shutdown
decl_stmt|;
comment|/* sctpStats  5 (Counter32) */
name|uint32_t
name|sctps_outoftheblue
decl_stmt|;
comment|/* sctpStats  6 (Counter32) */
name|uint32_t
name|sctps_checksumerrors
decl_stmt|;
comment|/* sctpStats  7 (Counter32) */
name|uint32_t
name|sctps_outcontrolchunks
decl_stmt|;
comment|/* sctpStats  8 (Counter64) */
name|uint32_t
name|sctps_outorderchunks
decl_stmt|;
comment|/* sctpStats  9 (Counter64) */
name|uint32_t
name|sctps_outunorderchunks
decl_stmt|;
comment|/* sctpStats 10 (Counter64) */
name|uint32_t
name|sctps_incontrolchunks
decl_stmt|;
comment|/* sctpStats 11 (Counter64) */
name|uint32_t
name|sctps_inorderchunks
decl_stmt|;
comment|/* sctpStats 12 (Counter64) */
name|uint32_t
name|sctps_inunorderchunks
decl_stmt|;
comment|/* sctpStats 13 (Counter64) */
name|uint32_t
name|sctps_fragusrmsgs
decl_stmt|;
comment|/* sctpStats 14 (Counter64) */
name|uint32_t
name|sctps_reasmusrmsgs
decl_stmt|;
comment|/* sctpStats 15 (Counter64) */
name|uint32_t
name|sctps_outpackets
decl_stmt|;
comment|/* sctpStats 16 (Counter64) */
name|uint32_t
name|sctps_inpackets
decl_stmt|;
comment|/* sctpStats 17 (Counter64) */
comment|/* input statistics: */
name|uint32_t
name|sctps_recvpackets
decl_stmt|;
comment|/* total input packets        */
name|uint32_t
name|sctps_recvdatagrams
decl_stmt|;
comment|/* total input datagrams      */
name|uint32_t
name|sctps_recvpktwithdata
decl_stmt|;
comment|/* total packets that had data */
name|uint32_t
name|sctps_recvsacks
decl_stmt|;
comment|/* total input SACK chunks    */
name|uint32_t
name|sctps_recvdata
decl_stmt|;
comment|/* total input DATA chunks    */
name|uint32_t
name|sctps_recvdupdata
decl_stmt|;
comment|/* total input duplicate DATA chunks */
name|uint32_t
name|sctps_recvheartbeat
decl_stmt|;
comment|/* total input HB chunks      */
name|uint32_t
name|sctps_recvheartbeatack
decl_stmt|;
comment|/* total input HB-ACK chunks  */
name|uint32_t
name|sctps_recvecne
decl_stmt|;
comment|/* total input ECNE chunks    */
name|uint32_t
name|sctps_recvauth
decl_stmt|;
comment|/* total input AUTH chunks    */
name|uint32_t
name|sctps_recvauthmissing
decl_stmt|;
comment|/* total input chunks missing AUTH */
name|uint32_t
name|sctps_recvivalhmacid
decl_stmt|;
comment|/* total number of invalid HMAC ids 					 * received */
name|uint32_t
name|sctps_recvivalkeyid
decl_stmt|;
comment|/* total number of invalid secret ids 					 * received */
name|uint32_t
name|sctps_recvauthfailed
decl_stmt|;
comment|/* total number of auth failed */
name|uint32_t
name|sctps_recvexpress
decl_stmt|;
comment|/* total fast path receives all one 					 * chunk */
name|uint32_t
name|sctps_recvexpressm
decl_stmt|;
comment|/* total fast path multi-part data */
name|uint32_t
name|sctps_recvnocrc
decl_stmt|;
name|uint32_t
name|sctps_recvswcrc
decl_stmt|;
name|uint32_t
name|sctps_recvhwcrc
decl_stmt|;
comment|/* output statistics: */
name|uint32_t
name|sctps_sendpackets
decl_stmt|;
comment|/* total output packets       */
name|uint32_t
name|sctps_sendsacks
decl_stmt|;
comment|/* total output SACKs         */
name|uint32_t
name|sctps_senddata
decl_stmt|;
comment|/* total output DATA chunks   */
name|uint32_t
name|sctps_sendretransdata
decl_stmt|;
comment|/* total output retransmitted DATA 					 * chunks */
name|uint32_t
name|sctps_sendfastretrans
decl_stmt|;
comment|/* total output fast retransmitted 					 * DATA chunks */
name|uint32_t
name|sctps_sendmultfastretrans
decl_stmt|;
comment|/* total FR's that happened 						 * more than once to same 						 * chunk (u-del multi-fr 						 * algo). */
name|uint32_t
name|sctps_sendheartbeat
decl_stmt|;
comment|/* total output HB chunks     */
name|uint32_t
name|sctps_sendecne
decl_stmt|;
comment|/* total output ECNE chunks    */
name|uint32_t
name|sctps_sendauth
decl_stmt|;
comment|/* total output AUTH chunks FIXME   */
name|uint32_t
name|sctps_senderrors
decl_stmt|;
comment|/* ip_output error counter */
name|uint32_t
name|sctps_sendnocrc
decl_stmt|;
name|uint32_t
name|sctps_sendswcrc
decl_stmt|;
name|uint32_t
name|sctps_sendhwcrc
decl_stmt|;
comment|/* PCKDROPREP statistics: */
name|uint32_t
name|sctps_pdrpfmbox
decl_stmt|;
comment|/* Packet drop from middle box */
name|uint32_t
name|sctps_pdrpfehos
decl_stmt|;
comment|/* P-drop from end host */
name|uint32_t
name|sctps_pdrpmbda
decl_stmt|;
comment|/* P-drops with data */
name|uint32_t
name|sctps_pdrpmbct
decl_stmt|;
comment|/* P-drops, non-data, non-endhost */
name|uint32_t
name|sctps_pdrpbwrpt
decl_stmt|;
comment|/* P-drop, non-endhost, bandwidth rep 					 * only */
name|uint32_t
name|sctps_pdrpcrupt
decl_stmt|;
comment|/* P-drop, not enough for chunk header */
name|uint32_t
name|sctps_pdrpnedat
decl_stmt|;
comment|/* P-drop, not enough data to confirm */
name|uint32_t
name|sctps_pdrppdbrk
decl_stmt|;
comment|/* P-drop, where process_chunk_drop 					 * said break */
name|uint32_t
name|sctps_pdrptsnnf
decl_stmt|;
comment|/* P-drop, could not find TSN */
name|uint32_t
name|sctps_pdrpdnfnd
decl_stmt|;
comment|/* P-drop, attempt reverse TSN lookup */
name|uint32_t
name|sctps_pdrpdiwnp
decl_stmt|;
comment|/* P-drop, e-host confirms zero-rwnd */
name|uint32_t
name|sctps_pdrpdizrw
decl_stmt|;
comment|/* P-drop, midbox confirms no space */
name|uint32_t
name|sctps_pdrpbadd
decl_stmt|;
comment|/* P-drop, data did not match TSN */
name|uint32_t
name|sctps_pdrpmark
decl_stmt|;
comment|/* P-drop, TSN's marked for Fast Retran */
comment|/* timeouts */
name|uint32_t
name|sctps_timoiterator
decl_stmt|;
comment|/* Number of iterator timers that 					 * fired */
name|uint32_t
name|sctps_timodata
decl_stmt|;
comment|/* Number of T3 data time outs */
name|uint32_t
name|sctps_timowindowprobe
decl_stmt|;
comment|/* Number of window probe (T3) timers 					 * that fired */
name|uint32_t
name|sctps_timoinit
decl_stmt|;
comment|/* Number of INIT timers that fired */
name|uint32_t
name|sctps_timosack
decl_stmt|;
comment|/* Number of sack timers that fired */
name|uint32_t
name|sctps_timoshutdown
decl_stmt|;
comment|/* Number of shutdown timers that 					 * fired */
name|uint32_t
name|sctps_timoheartbeat
decl_stmt|;
comment|/* Number of heartbeat timers that 					 * fired */
name|uint32_t
name|sctps_timocookie
decl_stmt|;
comment|/* Number of times a cookie timeout 					 * fired */
name|uint32_t
name|sctps_timosecret
decl_stmt|;
comment|/* Number of times an endpoint changed 					 * its cookie secret */
name|uint32_t
name|sctps_timopathmtu
decl_stmt|;
comment|/* Number of PMTU timers that fired */
name|uint32_t
name|sctps_timoshutdownack
decl_stmt|;
comment|/* Number of shutdown ack timers that 					 * fired */
name|uint32_t
name|sctps_timoshutdownguard
decl_stmt|;
comment|/* Number of shutdown guard 						 * timers that fired */
name|uint32_t
name|sctps_timostrmrst
decl_stmt|;
comment|/* Number of stream reset timers that 					 * fired */
name|uint32_t
name|sctps_timoearlyfr
decl_stmt|;
comment|/* Number of early FR timers that 					 * fired */
name|uint32_t
name|sctps_timoasconf
decl_stmt|;
comment|/* Number of times an asconf timer 					 * fired */
name|uint32_t
name|sctps_timodelprim
decl_stmt|;
comment|/* Number of times a prim_deleted 					 * timer fired */
name|uint32_t
name|sctps_timoautoclose
decl_stmt|;
comment|/* Number of times auto close timer 					 * fired */
name|uint32_t
name|sctps_timoassockill
decl_stmt|;
comment|/* Number of asoc free timers expired */
name|uint32_t
name|sctps_timoinpkill
decl_stmt|;
comment|/* Number of inp free timers expired */
comment|/* former early FR counters */
name|uint32_t
name|sctps_spare
index|[
literal|11
index|]
decl_stmt|;
comment|/* others */
name|uint32_t
name|sctps_hdrops
decl_stmt|;
comment|/* packet shorter than header */
name|uint32_t
name|sctps_badsum
decl_stmt|;
comment|/* checksum error             */
name|uint32_t
name|sctps_noport
decl_stmt|;
comment|/* no endpoint for port       */
name|uint32_t
name|sctps_badvtag
decl_stmt|;
comment|/* bad v-tag                  */
name|uint32_t
name|sctps_badsid
decl_stmt|;
comment|/* bad SID                    */
name|uint32_t
name|sctps_nomem
decl_stmt|;
comment|/* no memory                  */
name|uint32_t
name|sctps_fastretransinrtt
decl_stmt|;
comment|/* number of multiple FR in a 						 * RTT window */
name|uint32_t
name|sctps_markedretrans
decl_stmt|;
name|uint32_t
name|sctps_naglesent
decl_stmt|;
comment|/* nagle allowed sending      */
name|uint32_t
name|sctps_naglequeued
decl_stmt|;
comment|/* nagle doesn't allow sending */
name|uint32_t
name|sctps_maxburstqueued
decl_stmt|;
comment|/* max burst doesn't allow sending */
name|uint32_t
name|sctps_ifnomemqueued
decl_stmt|;
comment|/* look ahead tells us no memory in 					 * interface ring buffer OR we had a 					 * send error and are queuing one 					 * send. */
name|uint32_t
name|sctps_windowprobed
decl_stmt|;
comment|/* total number of window probes sent */
name|uint32_t
name|sctps_lowlevelerr
decl_stmt|;
comment|/* total times an output error causes 					 * us to clamp down on next user send. */
name|uint32_t
name|sctps_lowlevelerrusr
decl_stmt|;
comment|/* total times sctp_senderrors were 					 * caused from a user send from a user 					 * invoked send not a sack response */
name|uint32_t
name|sctps_datadropchklmt
decl_stmt|;
comment|/* Number of in data drops due to 					 * chunk limit reached */
name|uint32_t
name|sctps_datadroprwnd
decl_stmt|;
comment|/* Number of in data drops due to rwnd 					 * limit reached */
name|uint32_t
name|sctps_ecnereducedcwnd
decl_stmt|;
comment|/* Number of times a ECN reduced the 					 * cwnd */
name|uint32_t
name|sctps_vtagexpress
decl_stmt|;
comment|/* Used express lookup via vtag */
name|uint32_t
name|sctps_vtagbogus
decl_stmt|;
comment|/* Collision in express lookup. */
name|uint32_t
name|sctps_primary_randry
decl_stmt|;
comment|/* Number of times the sender ran dry 					 * of user data on primary */
name|uint32_t
name|sctps_cmt_randry
decl_stmt|;
comment|/* Same for above */
name|uint32_t
name|sctps_slowpath_sack
decl_stmt|;
comment|/* Sacks the slow way */
name|uint32_t
name|sctps_wu_sacks_sent
decl_stmt|;
comment|/* Window Update only sacks sent */
name|uint32_t
name|sctps_sends_with_flags
decl_stmt|;
comment|/* number of sends with 						 * sinfo_flags !=0 */
name|uint32_t
name|sctps_sends_with_unord
decl_stmt|;
comment|/* number of unordered sends */
name|uint32_t
name|sctps_sends_with_eof
decl_stmt|;
comment|/* number of sends with EOF flag set */
name|uint32_t
name|sctps_sends_with_abort
decl_stmt|;
comment|/* number of sends with ABORT 						 * flag set */
name|uint32_t
name|sctps_protocol_drain_calls
decl_stmt|;
comment|/* number of times protocol 						 * drain called */
name|uint32_t
name|sctps_protocol_drains_done
decl_stmt|;
comment|/* number of times we did a 						 * protocol drain */
name|uint32_t
name|sctps_read_peeks
decl_stmt|;
comment|/* Number of times recv was called 					 * with peek */
name|uint32_t
name|sctps_cached_chk
decl_stmt|;
comment|/* Number of cached chunks used */
name|uint32_t
name|sctps_cached_strmoq
decl_stmt|;
comment|/* Number of cached stream oq's used */
name|uint32_t
name|sctps_left_abandon
decl_stmt|;
comment|/* Number of unread messages abandoned 					 * by close */
name|uint32_t
name|sctps_send_burst_avoid
decl_stmt|;
comment|/* Unused */
name|uint32_t
name|sctps_send_cwnd_avoid
decl_stmt|;
comment|/* Send cwnd full  avoidance, already 					 * max burst inflight to net */
name|uint32_t
name|sctps_fwdtsn_map_over
decl_stmt|;
comment|/* number of map array over-runs via 					 * fwd-tsn's */
name|uint32_t
name|sctps_queue_upd_ecne
decl_stmt|;
comment|/* Number of times we queued or 					 * updated an ECN chunk on send queue */
name|uint32_t
name|sctps_reserved
index|[
literal|31
index|]
decl_stmt|;
comment|/* Future ABI compat - remove int's 					 * from here when adding new */
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
name|SMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|SCTP_USE_PERCPU_STAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|SCTP_STAT_INCR_BY
parameter_list|(
name|_x
parameter_list|,
name|_d
parameter_list|)
value|(SCTP_BASE_STATS[PCPU_GET(cpuid)]._x += _d)
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
value|(SCTP_BASE_STATS[PCPU_GET(cpuid)]._x -= _d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTP_STAT_INCR_BY
parameter_list|(
name|_x
parameter_list|,
name|_d
parameter_list|)
value|atomic_add_int(&SCTP_BASE_STAT(_x), _d)
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
value|atomic_subtract_int(&SCTP_BASE_STAT(_x), _d)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
if|#
directive|if
name|defined
argument_list|(
name|INET
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|INET6
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
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

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* And something for us old timers */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ntohll
end_ifndef

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|ntohll
parameter_list|(
name|x
parameter_list|)
value|be64toh(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|htonll
end_ifndef

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|htonll
parameter_list|(
name|x
parameter_list|)
value|htobe64(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********************************/
end_comment

begin_struct
struct|struct
name|xsctp_inpcb
block|{
name|uint32_t
name|last
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
name|uint32_t
name|fragmentation_point
decl_stmt|;
name|uint16_t
name|local_port
decl_stmt|;
name|uint16_t
name|qlen
decl_stmt|;
name|uint16_t
name|maxqlen
decl_stmt|;
name|uint32_t
name|extra_padding
index|[
literal|32
index|]
decl_stmt|;
comment|/* future */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xsctp_tcb
block|{
name|union
name|sctp_sockstore
name|primary_addr
decl_stmt|;
comment|/* sctpAssocEntry 5/6 */
name|uint32_t
name|last
decl_stmt|;
name|uint32_t
name|heartbeat_interval
decl_stmt|;
comment|/* sctpAssocEntry 7   */
name|uint32_t
name|state
decl_stmt|;
comment|/* sctpAssocEntry 8   */
name|uint32_t
name|in_streams
decl_stmt|;
comment|/* sctpAssocEntry 9   */
name|uint32_t
name|out_streams
decl_stmt|;
comment|/* sctpAssocEntry 10  */
name|uint32_t
name|max_nr_retrans
decl_stmt|;
comment|/* sctpAssocEntry 11  */
name|uint32_t
name|primary_process
decl_stmt|;
comment|/* sctpAssocEntry 12  */
name|uint32_t
name|T1_expireries
decl_stmt|;
comment|/* sctpAssocEntry 13  */
name|uint32_t
name|T2_expireries
decl_stmt|;
comment|/* sctpAssocEntry 14  */
name|uint32_t
name|retransmitted_tsns
decl_stmt|;
comment|/* sctpAssocEntry 15  */
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
name|uint32_t
name|mtu
decl_stmt|;
name|uint32_t
name|refcnt
decl_stmt|;
name|uint16_t
name|local_port
decl_stmt|;
comment|/* sctpAssocEntry 3   */
name|uint16_t
name|remote_port
decl_stmt|;
comment|/* sctpAssocEntry 4   */
name|struct
name|sctp_timeval
name|start_time
decl_stmt|;
comment|/* sctpAssocEntry 16  */
name|struct
name|sctp_timeval
name|discontinuity_time
decl_stmt|;
comment|/* sctpAssocEntry 17  */
name|uint32_t
name|peers_rwnd
decl_stmt|;
name|sctp_assoc_t
name|assoc_id
decl_stmt|;
comment|/* sctpAssocEntry 1   */
name|uint32_t
name|extra_padding
index|[
literal|32
index|]
decl_stmt|;
comment|/* future */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xsctp_laddr
block|{
name|union
name|sctp_sockstore
name|address
decl_stmt|;
comment|/* sctpAssocLocalAddrEntry 1/2 */
name|uint32_t
name|last
decl_stmt|;
name|struct
name|sctp_timeval
name|start_time
decl_stmt|;
comment|/* sctpAssocLocalAddrEntry 3   */
name|uint32_t
name|extra_padding
index|[
literal|32
index|]
decl_stmt|;
comment|/* future */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xsctp_raddr
block|{
name|union
name|sctp_sockstore
name|address
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 1/2 */
name|uint32_t
name|last
decl_stmt|;
name|uint32_t
name|rto
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 5   */
name|uint32_t
name|max_path_rtx
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 6   */
name|uint32_t
name|rtx
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 7   */
name|uint32_t
name|error_counter
decl_stmt|;
comment|/* */
name|uint32_t
name|cwnd
decl_stmt|;
comment|/* */
name|uint32_t
name|flight_size
decl_stmt|;
comment|/* */
name|uint32_t
name|mtu
decl_stmt|;
comment|/* */
name|uint8_t
name|active
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 3   */
name|uint8_t
name|confirmed
decl_stmt|;
comment|/* */
name|uint8_t
name|heartbeat_enabled
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 4   */
name|uint8_t
name|potentially_failed
decl_stmt|;
name|struct
name|sctp_timeval
name|start_time
decl_stmt|;
comment|/* sctpAssocLocalRemEntry 8   */
name|uint32_t
name|rtt
decl_stmt|;
name|uint32_t
name|heartbeat_interval
decl_stmt|;
name|uint32_t
name|extra_padding
index|[
literal|31
index|]
decl_stmt|;
comment|/* future */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_MAX_LOGGING_SIZE
value|30000
end_define

begin_define
define|#
directive|define
name|SCTP_TRACE_PARAMS
value|6
end_define

begin_comment
comment|/* This number MUST be even   */
end_comment

begin_struct
struct|struct
name|sctp_log_entry
block|{
name|uint64_t
name|timestamp
decl_stmt|;
name|uint32_t
name|subsys
decl_stmt|;
name|uint32_t
name|padding
decl_stmt|;
name|uint32_t
name|params
index|[
name|SCTP_TRACE_PARAMS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_log
block|{
name|struct
name|sctp_log_entry
name|entry
index|[
name|SCTP_MAX_LOGGING_SIZE
index|]
decl_stmt|;
name|uint32_t
name|index
decl_stmt|;
name|uint32_t
name|padding
decl_stmt|;
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
operator|||
name|defined
argument_list|(
name|__Userspace__
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
name|i_pak
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|,
name|int
name|flags
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
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|__Userspace__
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
operator|,
name|sctp_assoc_t
operator|*
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

begin_comment
comment|/* deprecated */
end_comment

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

begin_comment
comment|/* deprecated */
end_comment

begin_decl_stmt
name|ssize_t
name|sctp_send
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
name|sctp_sndrcvinfo
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* deprecated */
end_comment

begin_decl_stmt
name|ssize_t
name|sctp_sendx
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
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|,
expr|struct
name|sctp_sndrcvinfo
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* deprecated */
end_comment

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
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* deprecated */
end_comment

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

begin_decl_stmt
name|ssize_t
name|sctp_sendv
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|iovec
operator|*
operator|,
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|,
name|socklen_t
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|sctp_recvv
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|iovec
operator|*
operator|,
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|socklen_t
operator|*
operator|,
name|void
operator|*
operator|,
name|socklen_t
operator|*
operator|,
name|unsigned
name|int
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

