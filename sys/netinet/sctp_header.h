begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2007, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $KAME: sctp_header.h,v 1.14 2005/03/06 16:04:17 itojun Exp $	 */
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
name|__sctp_header_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_header_h__
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/sctp_constants.h>
end_include

begin_comment
comment|/*  * Parameter structures  */
end_comment

begin_struct
struct|struct
name|sctp_ipv4addr_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type=SCTP_IPV4_PARAM_TYPE, len=8 */
name|uint32_t
name|addr
decl_stmt|;
comment|/* IPV4 address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_V6_ADDR_BYTES
value|16
end_define

begin_struct
struct|struct
name|sctp_ipv6addr_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type=SCTP_IPV6_PARAM_TYPE, len=20 */
name|uint8_t
name|addr
index|[
name|SCTP_V6_ADDR_BYTES
index|]
decl_stmt|;
comment|/* IPV6 address */
block|}
struct|;
end_struct

begin_comment
comment|/* Cookie Preservative */
end_comment

begin_struct
struct|struct
name|sctp_cookie_perserve_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type=SCTP_COOKIE_PRESERVE, len=8 */
name|uint32_t
name|time
decl_stmt|;
comment|/* time in ms to extend cookie */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_ARRAY_MIN_LEN
value|1
end_define

begin_comment
comment|/* Host Name Address */
end_comment

begin_struct
struct|struct
name|sctp_host_name_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type=SCTP_HOSTNAME_ADDRESS */
name|char
name|name
index|[
name|SCTP_ARRAY_MIN_LEN
index|]
decl_stmt|;
comment|/* host name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the maximum padded size of a s-a-p  * so paramheadr + 3 address types (6 bytes) + 2 byte pad = 12  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_ADDR_PARAMS_SIZE
value|12
end_define

begin_comment
comment|/* supported address type */
end_comment

begin_struct
struct|struct
name|sctp_supported_addr_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type=SCTP_SUPPORTED_ADDRTYPE */
name|uint16_t
name|addr_type
index|[
name|SCTP_ARRAY_MIN_LEN
index|]
decl_stmt|;
comment|/* array of supported address 						 * types */
block|}
struct|;
end_struct

begin_comment
comment|/* ECN parameter */
end_comment

begin_struct
struct|struct
name|sctp_ecn_supported_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type=SCTP_ECN_CAPABLE */
block|}
struct|;
end_struct

begin_comment
comment|/* heartbeat info parameter */
end_comment

begin_struct
struct|struct
name|sctp_heartbeat_info_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|uint32_t
name|time_value_1
decl_stmt|;
name|uint32_t
name|time_value_2
decl_stmt|;
name|uint32_t
name|random_value1
decl_stmt|;
name|uint32_t
name|random_value2
decl_stmt|;
name|uint16_t
name|user_req
decl_stmt|;
name|uint8_t
name|addr_family
decl_stmt|;
name|uint8_t
name|addr_len
decl_stmt|;
name|char
name|address
index|[
name|SCTP_ADDRMAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* draft-ietf-tsvwg-prsctp */
end_comment

begin_comment
comment|/* PR-SCTP supported parameter */
end_comment

begin_struct
struct|struct
name|sctp_prsctp_supported_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* draft-ietf-tsvwg-addip-sctp */
end_comment

begin_struct
struct|struct
name|sctp_asconf_paramhdr
block|{
comment|/* an ASCONF "parameter" */
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* a SCTP parameter header */
name|uint32_t
name|correlation_id
decl_stmt|;
comment|/* correlation id for this param */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_asconf_addr_param
block|{
comment|/* an ASCONF address parameter */
name|struct
name|sctp_asconf_paramhdr
name|aph
decl_stmt|;
comment|/* asconf "parameter" */
name|struct
name|sctp_ipv6addr_param
name|addrp
decl_stmt|;
comment|/* max storage size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_asconf_addrv4_param
block|{
comment|/* an ASCONF address (v4) parameter */
name|struct
name|sctp_asconf_paramhdr
name|aph
decl_stmt|;
comment|/* asconf "parameter" */
name|struct
name|sctp_ipv4addr_param
name|addrp
decl_stmt|;
comment|/* max storage size */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_MAX_SUPPORTED_EXT
value|256
end_define

begin_struct
struct|struct
name|sctp_supported_chunk_types_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type = 0x8008  len = x */
name|uint8_t
name|chunk_types
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ECN Nonce: draft-ladha-sctp-ecn-nonce */
end_comment

begin_struct
struct|struct
name|sctp_ecn_nonce_supported_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type = 0x8001  len = 4 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structures for DATA chunks  */
end_comment

begin_struct
struct|struct
name|sctp_data
block|{
name|uint32_t
name|tsn
decl_stmt|;
name|uint16_t
name|stream_id
decl_stmt|;
name|uint16_t
name|stream_sequence
decl_stmt|;
name|uint32_t
name|protocol_id
decl_stmt|;
comment|/* user data follows */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_data_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_data
name|dp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structures for the control chunks  */
end_comment

begin_comment
comment|/* Initiate (INIT)/Initiate Ack (INIT ACK) */
end_comment

begin_struct
struct|struct
name|sctp_init
block|{
name|uint32_t
name|initiate_tag
decl_stmt|;
comment|/* initiate tag */
name|uint32_t
name|a_rwnd
decl_stmt|;
comment|/* a_rwnd */
name|uint16_t
name|num_outbound_streams
decl_stmt|;
comment|/* OS */
name|uint16_t
name|num_inbound_streams
decl_stmt|;
comment|/* MIS */
name|uint32_t
name|initial_tsn
decl_stmt|;
comment|/* I-TSN */
comment|/* optional param's follow */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_IDENTIFICATION_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_ADDRESS_SIZE
value|4
end_define

begin_comment
comment|/* state cookie header */
end_comment

begin_struct
struct|struct
name|sctp_state_cookie
block|{
comment|/* this is our definition... */
name|uint8_t
name|identification
index|[
name|SCTP_IDENTIFICATION_SIZE
index|]
decl_stmt|;
comment|/* id of who we are */
name|uint32_t
name|cookie_life
decl_stmt|;
comment|/* life I will award this cookie */
name|uint32_t
name|tie_tag_my_vtag
decl_stmt|;
comment|/* my tag in old association */
name|uint32_t
name|tie_tag_peer_vtag
decl_stmt|;
comment|/* peers tag in old association */
name|uint32_t
name|peers_vtag
decl_stmt|;
comment|/* peers tag in INIT (for quick ref) */
name|uint32_t
name|my_vtag
decl_stmt|;
comment|/* my tag in INIT-ACK (for quick ref) */
name|struct
name|timeval
name|time_entered
decl_stmt|;
comment|/* the time I built cookie */
name|uint32_t
name|address
index|[
name|SCTP_ADDRESS_SIZE
index|]
decl_stmt|;
comment|/* 4 ints/128 bits */
name|uint32_t
name|addr_type
decl_stmt|;
comment|/* address type */
name|uint32_t
name|laddress
index|[
name|SCTP_ADDRESS_SIZE
index|]
decl_stmt|;
comment|/* my local from address */
name|uint32_t
name|laddr_type
decl_stmt|;
comment|/* my local from address type */
name|uint32_t
name|scope_id
decl_stmt|;
comment|/* v6 scope id for link-locals */
name|uint16_t
name|peerport
decl_stmt|;
comment|/* port address of the peer in the INIT */
name|uint16_t
name|myport
decl_stmt|;
comment|/* my port address used in the INIT */
name|uint8_t
name|ipv4_addr_legal
decl_stmt|;
comment|/* Are V4 addr legal? */
name|uint8_t
name|ipv6_addr_legal
decl_stmt|;
comment|/* Are V6 addr legal? */
name|uint8_t
name|local_scope
decl_stmt|;
comment|/* IPv6 local scope flag */
name|uint8_t
name|site_scope
decl_stmt|;
comment|/* IPv6 site scope flag */
name|uint8_t
name|ipv4_scope
decl_stmt|;
comment|/* IPv4 private addr scope */
name|uint8_t
name|loopback_scope
decl_stmt|;
comment|/* loopback scope information */
name|uint16_t
name|reserved
decl_stmt|;
comment|/* 	 * at the end is tacked on the INIT chunk and the INIT-ACK chunk 	 * (minus the cookie). 	 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_inv_mandatory_param
block|{
name|uint16_t
name|cause
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint32_t
name|num_param
decl_stmt|;
name|uint16_t
name|param
decl_stmt|;
comment|/* 	 * We include this to 0 it since only a missing cookie will cause 	 * this error. 	 */
name|uint16_t
name|resv
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_unresolv_addr
block|{
name|uint16_t
name|cause
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|addr_type
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
comment|/* Only one invalid addr type */
block|}
struct|;
end_struct

begin_comment
comment|/* state cookie parameter */
end_comment

begin_struct
struct|struct
name|sctp_state_cookie_param
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|struct
name|sctp_state_cookie
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_init_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_init
name|init
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_init_msg
block|{
name|struct
name|sctphdr
name|sh
decl_stmt|;
name|struct
name|sctp_init_chunk
name|msg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ... used for both INIT and INIT ACK */
end_comment

begin_define
define|#
directive|define
name|sctp_init_ack
value|sctp_init
end_define

begin_define
define|#
directive|define
name|sctp_init_ack_chunk
value|sctp_init_chunk
end_define

begin_define
define|#
directive|define
name|sctp_init_ack_msg
value|sctp_init_msg
end_define

begin_comment
comment|/* Selective Ack (SACK) */
end_comment

begin_struct
struct|struct
name|sctp_gap_ack_block
block|{
name|uint16_t
name|start
decl_stmt|;
comment|/* Gap Ack block start */
name|uint16_t
name|end
decl_stmt|;
comment|/* Gap Ack block end */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_sack
block|{
name|uint32_t
name|cum_tsn_ack
decl_stmt|;
comment|/* cumulative TSN Ack */
name|uint32_t
name|a_rwnd
decl_stmt|;
comment|/* updated a_rwnd of sender */
name|uint16_t
name|num_gap_ack_blks
decl_stmt|;
comment|/* number of Gap Ack blocks */
name|uint16_t
name|num_dup_tsns
decl_stmt|;
comment|/* number of duplicate TSNs */
comment|/* struct sctp_gap_ack_block's follow */
comment|/* uint32_t duplicate_tsn's follow */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_sack_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_sack
name|sack
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Heartbeat Request (HEARTBEAT) */
end_comment

begin_struct
struct|struct
name|sctp_heartbeat
block|{
name|struct
name|sctp_heartbeat_info_param
name|hb_info
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_heartbeat_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_heartbeat
name|heartbeat
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ... used for Heartbeat Ack (HEARTBEAT ACK) */
end_comment

begin_define
define|#
directive|define
name|sctp_heartbeat_ack
value|sctp_heartbeat
end_define

begin_define
define|#
directive|define
name|sctp_heartbeat_ack_chunk
value|sctp_heartbeat_chunk
end_define

begin_comment
comment|/* Abort Asssociation (ABORT) */
end_comment

begin_struct
struct|struct
name|sctp_abort_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
comment|/* optional error cause may follow */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_abort_msg
block|{
name|struct
name|sctphdr
name|sh
decl_stmt|;
name|struct
name|sctp_abort_chunk
name|msg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Shutdown Association (SHUTDOWN) */
end_comment

begin_struct
struct|struct
name|sctp_shutdown_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|uint32_t
name|cumulative_tsn_ack
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Shutdown Acknowledgment (SHUTDOWN ACK) */
end_comment

begin_struct
struct|struct
name|sctp_shutdown_ack_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Operation Error (ERROR) */
end_comment

begin_struct
struct|struct
name|sctp_error_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
comment|/* optional error causes follow */
block|}
struct|;
end_struct

begin_comment
comment|/* Cookie Echo (COOKIE ECHO) */
end_comment

begin_struct
struct|struct
name|sctp_cookie_echo_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_state_cookie
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Cookie Acknowledgment (COOKIE ACK) */
end_comment

begin_struct
struct|struct
name|sctp_cookie_ack_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Explicit Congestion Notification Echo (ECNE) */
end_comment

begin_struct
struct|struct
name|sctp_ecne_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|uint32_t
name|tsn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Congestion Window Reduced (CWR) */
end_comment

begin_struct
struct|struct
name|sctp_cwr_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|uint32_t
name|tsn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Shutdown Complete (SHUTDOWN COMPLETE) */
end_comment

begin_struct
struct|struct
name|sctp_shutdown_complete_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Oper error holding a stale cookie */
end_comment

begin_struct
struct|struct
name|sctp_stale_cookie_msg
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* really an error cause */
name|uint32_t
name|time_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_adaptation_layer_indication
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|uint32_t
name|indication
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_cookie_while_shutting_down
block|{
name|struct
name|sctphdr
name|sh
decl_stmt|;
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* really an error cause */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_shutdown_complete_msg
block|{
name|struct
name|sctphdr
name|sh
decl_stmt|;
name|struct
name|sctp_shutdown_complete_chunk
name|shut_cmp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * draft-ietf-tsvwg-addip-sctp  */
end_comment

begin_comment
comment|/* Address/Stream Configuration Change (ASCONF) */
end_comment

begin_struct
struct|struct
name|sctp_asconf_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|uint32_t
name|serial_number
decl_stmt|;
comment|/* lookup address parameter (mandatory) */
comment|/* asconf parameters follow */
block|}
struct|;
end_struct

begin_comment
comment|/* Address/Stream Configuration Acknowledge (ASCONF ACK) */
end_comment

begin_struct
struct|struct
name|sctp_asconf_ack_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|uint32_t
name|serial_number
decl_stmt|;
comment|/* asconf parameters follow */
block|}
struct|;
end_struct

begin_comment
comment|/* draft-ietf-tsvwg-prsctp */
end_comment

begin_comment
comment|/* Forward Cumulative TSN (FORWARD TSN) */
end_comment

begin_struct
struct|struct
name|sctp_forward_tsn_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|uint32_t
name|new_cumulative_tsn
decl_stmt|;
comment|/* stream/sequence pairs (sctp_strseq) follow */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_strseq
block|{
name|uint16_t
name|stream
decl_stmt|;
name|uint16_t
name|sequence
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_forward_tsn_msg
block|{
name|struct
name|sctphdr
name|sh
decl_stmt|;
name|struct
name|sctp_forward_tsn_chunk
name|msg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* should be a multiple of 4 - 1 aka 3/7/11 etc. */
end_comment

begin_define
define|#
directive|define
name|SCTP_NUM_DB_TO_VERIFY
value|31
end_define

begin_struct
struct|struct
name|sctp_chunk_desc
block|{
name|uint8_t
name|chunk_type
decl_stmt|;
name|uint8_t
name|data_bytes
index|[
name|SCTP_NUM_DB_TO_VERIFY
index|]
decl_stmt|;
name|uint32_t
name|tsn_ifany
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_pktdrop_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|uint32_t
name|bottle_bw
decl_stmt|;
name|uint32_t
name|current_onq
decl_stmt|;
name|uint16_t
name|trunc_len
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**********STREAM RESET STUFF ******************/
end_comment

begin_struct
struct|struct
name|sctp_stream_reset_out_request
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|uint32_t
name|request_seq
decl_stmt|;
comment|/* monotonically increasing seq no */
name|uint32_t
name|response_seq
decl_stmt|;
comment|/* if a response, the resp seq no */
name|uint32_t
name|send_reset_at_tsn
decl_stmt|;
comment|/* last TSN I assigned outbound */
name|uint16_t
name|list_of_streams
index|[
literal|0
index|]
decl_stmt|;
comment|/* if not all list of streams */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_stream_reset_in_request
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|uint32_t
name|request_seq
decl_stmt|;
name|uint16_t
name|list_of_streams
index|[
literal|0
index|]
decl_stmt|;
comment|/* if not all list of streams */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_stream_reset_tsn_request
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|uint32_t
name|request_seq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_stream_reset_response
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|uint32_t
name|response_seq
decl_stmt|;
comment|/* if a response, the resp seq no */
name|uint32_t
name|result
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_stream_reset_response_tsn
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|uint32_t
name|response_seq
decl_stmt|;
comment|/* if a response, the resp seq no */
name|uint32_t
name|result
decl_stmt|;
name|uint32_t
name|senders_next_tsn
decl_stmt|;
name|uint32_t
name|receivers_next_tsn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_NOTHING
value|0x00000000
end_define

begin_comment
comment|/* Nothing for me to do */
end_comment

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_PERFORMED
value|0x00000001
end_define

begin_comment
comment|/* Did it */
end_comment

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_DENIED
value|0x00000002
end_define

begin_comment
comment|/* refused to do it */
end_comment

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_ERROR_STR
value|0x00000003
end_define

begin_comment
comment|/* bad Stream no */
end_comment

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_TRY_LATER
value|0x00000004
end_define

begin_comment
comment|/* collision, try again */
end_comment

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_BAD_SEQNO
value|0x00000005
end_define

begin_comment
comment|/* bad str-reset seq no */
end_comment

begin_comment
comment|/*  * convience structures, note that if you are making a request for specific  * streams then the request will need to be an overlay structure.  */
end_comment

begin_struct
struct|struct
name|sctp_stream_reset_out_req
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_stream_reset_out_request
name|sr_req
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_stream_reset_in_req
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_stream_reset_in_request
name|sr_req
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_stream_reset_tsn_req
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_stream_reset_tsn_request
name|sr_req
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_stream_reset_resp
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_stream_reset_response
name|sr_resp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* respone only valid with a TSN request */
end_comment

begin_struct
struct|struct
name|sctp_stream_reset_resp_tsn
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|struct
name|sctp_stream_reset_response_tsn
name|sr_resp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************/
end_comment

begin_comment
comment|/*  * Authenticated chunks support draft-ietf-tsvwg-sctp-auth  */
end_comment

begin_comment
comment|/* Should we make the max be 32? */
end_comment

begin_define
define|#
directive|define
name|SCTP_RANDOM_MAX_SIZE
value|256
end_define

begin_struct
struct|struct
name|sctp_auth_random
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type = 0x8002 */
name|uint8_t
name|random_data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_auth_chunk_list
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type = 0x8003 */
name|uint8_t
name|chunk_types
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_auth_hmac_algo
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
comment|/* type = 0x8004 */
name|uint16_t
name|hmac_ids
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_auth_chunk
block|{
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
name|uint16_t
name|shared_key_id
decl_stmt|;
name|uint16_t
name|hmac_id
decl_stmt|;
name|uint8_t
name|hmac
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_auth_invalid_hmac
block|{
name|struct
name|sctp_paramhdr
name|ph
decl_stmt|;
name|uint16_t
name|hmac_id
decl_stmt|;
name|uint16_t
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * we pre-reserve enough room for a ECNE or CWR AND a SACK with no missing  * pieces. If ENCE is missing we could have a couple of blocks. This way we  * optimize so we MOST likely can bundle a SACK/ECN with the smallest size  * data chunk I will split into. We could increase throughput slightly by  * taking out these two but the  24-sack/8-CWR i.e. 32 bytes I pre-reserve I  * feel is worth it for now.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_MAX_OVERHEAD
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|SCTP_MAX_OVERHEAD
value|(sizeof(struct sctp_data_chunk) + \ 			   sizeof(struct sctphdr) + \ 			   sizeof(struct sctp_ecne_chunk) + \ 			   sizeof(struct sctp_sack_chunk) + \ 			   sizeof(struct ip6_hdr))
end_define

begin_define
define|#
directive|define
name|SCTP_MED_OVERHEAD
value|(sizeof(struct sctp_data_chunk) + \ 			   sizeof(struct sctphdr) + \ 			   sizeof(struct ip6_hdr))
end_define

begin_define
define|#
directive|define
name|SCTP_MIN_OVERHEAD
value|(sizeof(struct ip6_hdr) + \ 			   sizeof(struct sctphdr))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTP_MAX_OVERHEAD
value|(sizeof(struct sctp_data_chunk) + \ 			   sizeof(struct sctphdr) + \ 			   sizeof(struct sctp_ecne_chunk) + \ 			   sizeof(struct sctp_sack_chunk) + \ 			   sizeof(struct ip))
end_define

begin_define
define|#
directive|define
name|SCTP_MED_OVERHEAD
value|(sizeof(struct sctp_data_chunk) + \ 			   sizeof(struct sctphdr) + \ 			   sizeof(struct ip))
end_define

begin_define
define|#
directive|define
name|SCTP_MIN_OVERHEAD
value|(sizeof(struct ip) + \ 			   sizeof(struct sctphdr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SCTP_MAX_OVERHEAD */
end_comment

begin_define
define|#
directive|define
name|SCTP_MED_V4_OVERHEAD
value|(sizeof(struct sctp_data_chunk) + \ 			      sizeof(struct sctphdr) + \ 			      sizeof(struct ip))
end_define

begin_define
define|#
directive|define
name|SCTP_MIN_V4_OVERHEAD
value|(sizeof(struct ip) + \ 			      sizeof(struct sctphdr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__sctp_header_h__ */
end_comment

end_unit

