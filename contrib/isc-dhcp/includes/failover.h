begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* failover.h     Definitions for address trees... */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000-2001 Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about the Internet Software Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FAILOVER_PROTOCOL
argument_list|)
end_if

begin_struct
struct|struct
name|failover_option_info
block|{
name|int
name|code
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
enum|enum
block|{
name|FT_UINT8
block|,
name|FT_IPADDR
block|,
name|FT_UINT32
block|,
name|FT_BYTES
block|,
name|FT_TEXT_OR_BYTES
block|,
name|FT_DDNS
block|,
name|FT_DDNS1
block|,
name|FT_UINT16
block|,
name|FT_TEXT
block|,
name|FT_UNDEF
block|,
name|FT_DIGEST
block|}
name|type
enum|;
name|int
name|num_present
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|u_int32_t
name|bit
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|count
decl_stmt|;
name|u_int8_t
modifier|*
name|data
decl_stmt|;
block|}
name|failover_option_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FM_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(long)(&(((failover_message_t *)0) -> x))
end_define

begin_comment
comment|/* Failover message options: */
end_comment

begin_define
define|#
directive|define
name|FTO_BINDING_STATUS
value|1
end_define

begin_define
define|#
directive|define
name|FTB_BINDING_STATUS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FTO_ASSIGNED_IP_ADDRESS
value|2
end_define

begin_define
define|#
directive|define
name|FTB_ASSIGNED_IP_ADDRESS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FTO_SERVER_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|FTB_SERVER_ADDR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FTO_ADDRESSES_TRANSFERRED
value|4
end_define

begin_define
define|#
directive|define
name|FTB_ADDRESSES_TRANSFERRED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|FTO_CLIENT_IDENTIFIER
value|5
end_define

begin_define
define|#
directive|define
name|FTB_CLIENT_IDENTIFIER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FTO_CHADDR
value|6
end_define

begin_define
define|#
directive|define
name|FTB_CHADDR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FTO_DDNS
value|7
end_define

begin_define
define|#
directive|define
name|FTB_DDNS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|FTO_REJECT_REASON
value|8
end_define

begin_define
define|#
directive|define
name|FTB_REJECT_REASON
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FTO_MESSAGE
value|9
end_define

begin_define
define|#
directive|define
name|FTB_MESSAGE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|FTO_MCLT
value|10
end_define

begin_define
define|#
directive|define
name|FTB_MCLT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|FTO_VENDOR_CLASS
value|11
end_define

begin_define
define|#
directive|define
name|FTB_VENDOR_CLASS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|FTO_LEASE_EXPIRY
value|13
end_define

begin_define
define|#
directive|define
name|FTB_LEASE_EXPIRY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FTO_POTENTIAL_EXPIRY
value|14
end_define

begin_define
define|#
directive|define
name|FTB_POTENTIAL_EXPIRY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FTO_GRACE_EXPIRY
value|15
end_define

begin_define
define|#
directive|define
name|FTB_GRACE_EXPIRY
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FTO_CLTT
value|16
end_define

begin_define
define|#
directive|define
name|FTB_CLTT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|FTO_STOS
value|17
end_define

begin_define
define|#
directive|define
name|FTB_STOS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FTO_SERVER_STATE
value|18
end_define

begin_define
define|#
directive|define
name|FTB_SERVER_STATE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|FTO_SERVER_FLAGS
value|19
end_define

begin_define
define|#
directive|define
name|FTB_SERVER_FLAGS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FTO_VENDOR_OPTIONS
value|20
end_define

begin_define
define|#
directive|define
name|FTB_VENDOR_OPTIONS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|FTO_MAX_UNACKED
value|21
end_define

begin_define
define|#
directive|define
name|FTB_MAX_UNACKED
value|0x00200000
end_define

begin_define
define|#
directive|define
name|FTO_RECEIVE_TIMER
value|23
end_define

begin_define
define|#
directive|define
name|FTB_RECEIVE_TIMER
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FTO_HBA
value|24
end_define

begin_define
define|#
directive|define
name|FTB_HBA
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FTO_MESSAGE_DIGEST
value|25
end_define

begin_define
define|#
directive|define
name|FTB_MESSAGE_DIGEST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FTO_PROTOCOL_VERSION
value|26
end_define

begin_define
define|#
directive|define
name|FTB_PROTOCOL_VERSION
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FTO_TLS_REQUEST
value|27
end_define

begin_define
define|#
directive|define
name|FTB_TLS_REQUEST
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FTO_TLS_REPLY
value|28
end_define

begin_define
define|#
directive|define
name|FTB_TLS_REPLY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FTO_REQUEST_OPTIONS
value|29
end_define

begin_define
define|#
directive|define
name|FTB_REQUEST_OPTIONS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FTO_REPLY_OPTIONS
value|30
end_define

begin_define
define|#
directive|define
name|FTB_REPLY_OPTIONS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FTO_MAX
value|FTO_REPLY_OPTIONS
end_define

begin_comment
comment|/* Failover protocol message types: */
end_comment

begin_define
define|#
directive|define
name|FTM_POOLREQ
value|1
end_define

begin_define
define|#
directive|define
name|FTM_POOLRESP
value|2
end_define

begin_define
define|#
directive|define
name|FTM_BNDUPD
value|3
end_define

begin_define
define|#
directive|define
name|FTM_BNDACK
value|4
end_define

begin_define
define|#
directive|define
name|FTM_CONNECT
value|5
end_define

begin_define
define|#
directive|define
name|FTM_CONNECTACK
value|6
end_define

begin_define
define|#
directive|define
name|FTM_UPDREQ
value|7
end_define

begin_define
define|#
directive|define
name|FTM_UPDDONE
value|8
end_define

begin_define
define|#
directive|define
name|FTM_UPDREQALL
value|9
end_define

begin_define
define|#
directive|define
name|FTM_STATE
value|10
end_define

begin_define
define|#
directive|define
name|FTM_CONTACT
value|11
end_define

begin_define
define|#
directive|define
name|FTM_DISCONNECT
value|12
end_define

begin_comment
comment|/* Reject reasons: */
end_comment

begin_define
define|#
directive|define
name|FTR_ILLEGAL_IP_ADDR
value|1
end_define

begin_define
define|#
directive|define
name|FTR_FATAL_CONFLICT
value|2
end_define

begin_define
define|#
directive|define
name|FTR_MISSING_BINDINFO
value|3
end_define

begin_define
define|#
directive|define
name|FTR_TIMEMISMATCH
value|4
end_define

begin_define
define|#
directive|define
name|FTR_INVALID_MCLT
value|5
end_define

begin_define
define|#
directive|define
name|FTR_MISC_REJECT
value|6
end_define

begin_define
define|#
directive|define
name|FTR_DUP_CONNECTION
value|7
end_define

begin_define
define|#
directive|define
name|FTR_INVALID_PARTNER
value|8
end_define

begin_define
define|#
directive|define
name|FTR_TLS_UNSUPPORTED
value|9
end_define

begin_define
define|#
directive|define
name|FTR_TLS_UNCONFIGURED
value|10
end_define

begin_define
define|#
directive|define
name|FTR_TLS_REQUIRED
value|11
end_define

begin_define
define|#
directive|define
name|FTR_DIGEST_UNSUPPORTED
value|12
end_define

begin_define
define|#
directive|define
name|FTR_DIGEST_UNCONFIGURED
value|13
end_define

begin_define
define|#
directive|define
name|FTR_VERSION_MISMATCH
value|14
end_define

begin_define
define|#
directive|define
name|FTR_MISSING_BIND_INFO
value|15
end_define

begin_define
define|#
directive|define
name|FTR_OUTDATED_BIND_INFO
value|16
end_define

begin_define
define|#
directive|define
name|FTR_LESS_CRIT_BIND_INFO
value|17
end_define

begin_define
define|#
directive|define
name|FTR_NO_TRAFFIC
value|18
end_define

begin_define
define|#
directive|define
name|FTR_HBA_CONFLICT
value|19
end_define

begin_define
define|#
directive|define
name|FTR_UNKNOWN
value|254
end_define

begin_define
define|#
directive|define
name|DHCP_FAILOVER_MAX_MESSAGE_SIZE
value|2048
end_define

begin_comment
comment|/* Failover server flags. */
end_comment

begin_define
define|#
directive|define
name|FTF_STARTUP
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|failover_message
block|{
name|int
name|refcnt
decl_stmt|;
name|struct
name|failover_message
modifier|*
name|next
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
name|u_int8_t
name|binding_status
decl_stmt|;
name|u_int8_t
name|protocol_version
decl_stmt|;
name|u_int8_t
name|reject_reason
decl_stmt|;
name|u_int8_t
name|server_flags
decl_stmt|;
name|u_int8_t
name|server_state
decl_stmt|;
name|u_int8_t
name|tls_reply
decl_stmt|;
name|u_int8_t
name|tls_request
decl_stmt|;
name|u_int32_t
name|stos
decl_stmt|;
name|u_int32_t
name|time
decl_stmt|;
name|u_int32_t
name|xid
decl_stmt|;
name|u_int32_t
name|addresses_transferred
decl_stmt|;
name|u_int32_t
name|assigned_addr
decl_stmt|;
name|u_int32_t
name|client_ltt
decl_stmt|;
name|u_int32_t
name|expiry
decl_stmt|;
name|u_int32_t
name|grace_expiry
decl_stmt|;
name|u_int32_t
name|max_unacked
decl_stmt|;
name|u_int32_t
name|mclt
decl_stmt|;
name|u_int32_t
name|potential_expiry
decl_stmt|;
name|u_int32_t
name|receive_timer
decl_stmt|;
name|u_int32_t
name|server_addr
decl_stmt|;
name|failover_option_t
name|chaddr
decl_stmt|;
name|failover_option_t
name|client_identifier
decl_stmt|;
name|failover_option_t
name|hba
decl_stmt|;
name|failover_option_t
name|message
decl_stmt|;
name|failover_option_t
name|reply_options
decl_stmt|;
name|failover_option_t
name|request_options
decl_stmt|;
name|ddns_fqdn_t
name|ddns
decl_stmt|;
name|failover_option_t
name|vendor_class
decl_stmt|;
name|failover_option_t
name|vendor_options
decl_stmt|;
name|int
name|options_present
decl_stmt|;
block|}
name|failover_message_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|struct
name|option_cache
modifier|*
name|peer_address
decl_stmt|;
name|unsigned
name|peer_port
decl_stmt|;
name|int
name|options_present
decl_stmt|;
enum|enum
name|dhcp_flink_state
block|{
name|dhcp_flink_start
block|,
name|dhcp_flink_message_length_wait
block|,
name|dhcp_flink_message_wait
block|,
name|dhcp_flink_disconnected
block|,
name|dhcp_flink_state_max
block|}
name|state
enum|;
name|failover_message_t
modifier|*
name|imsg
decl_stmt|;
name|struct
name|_dhcp_failover_state
modifier|*
name|state_object
decl_stmt|;
name|u_int16_t
name|imsg_len
decl_stmt|;
name|unsigned
name|imsg_count
decl_stmt|;
name|u_int8_t
name|imsg_payoff
decl_stmt|;
comment|/* Pay*load* offset. :') */
name|u_int32_t
name|xid
decl_stmt|;
block|}
name|dhcp_failover_link_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dhcp_failover_listener
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|struct
name|_dhcp_failover_listener
modifier|*
name|next
decl_stmt|;
name|omapi_addr_t
name|address
decl_stmt|;
block|}
name|dhcp_failover_listener_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FAILOVER_PROTOCOL */
end_comment

begin_comment
comment|/* A failover peer. */
end_comment

begin_enum
enum|enum
name|failover_state
block|{
name|unknown_state
block|,
name|partner_down
block|,
name|normal
block|,
name|communications_interrupted
block|,
name|resolution_interrupted
block|,
name|potential_conflict
block|,
name|recover
block|,
name|recover_done
block|,
name|shut_down
block|,
name|paused
block|,
name|startup
block|,
name|recover_wait
block|}
enum|;
end_enum

begin_comment
comment|/* Service states are simplifications of failover states, particularly    useful because the startup state isn't actually implementable as a    seperate failover state without maintaining a state stack. */
end_comment

begin_enum
enum|enum
name|service_state
block|{
name|unknown_service_state
block|,
name|cooperating
block|,
name|not_cooperating
block|,
name|service_partner_down
block|,
name|not_responding
block|,
name|service_startup
block|}
enum|;
end_enum

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FAILOVER_PROTOCOL
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|_dhcp_failover_config
block|{
name|struct
name|option_cache
modifier|*
name|address
decl_stmt|;
name|int
name|port
decl_stmt|;
name|u_int32_t
name|max_flying_updates
decl_stmt|;
name|enum
name|failover_state
name|state
decl_stmt|;
name|TIME
name|stos
decl_stmt|;
name|u_int32_t
name|max_response_delay
decl_stmt|;
block|}
name|dhcp_failover_config_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dhcp_failover_state
block|{
name|OMAPI_OBJECT_PREAMBLE
expr_stmt|;
name|struct
name|_dhcp_failover_state
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of this failover instance. */
name|dhcp_failover_config_t
name|me
decl_stmt|;
comment|/* My configuration. */
name|dhcp_failover_config_t
name|partner
decl_stmt|;
comment|/* Partner's configuration. */
name|enum
name|failover_state
name|saved_state
decl_stmt|;
comment|/* Saved state during startup. */
name|struct
name|data_string
name|server_identifier
decl_stmt|;
comment|/* Server identifier (IP addr) */
name|u_int32_t
name|mclt
decl_stmt|;
name|u_int8_t
modifier|*
name|hba
decl_stmt|;
comment|/* Hash bucket array for load balancing. */
name|int
name|load_balance_max_secs
decl_stmt|;
name|enum
name|service_state
name|service_state
decl_stmt|;
specifier|const
name|char
modifier|*
name|nrr
decl_stmt|;
comment|/* Printable reason why we're in the 				   not_responding service state (empty 				   string if we are responding. */
name|dhcp_failover_link_t
modifier|*
name|link_to_peer
decl_stmt|;
comment|/* Currently-established link 						   to peer. */
enum|enum
block|{
name|primary
block|,
name|secondary
block|}
name|i_am
enum|;
comment|/* We are primary or secondary in this relationship. */
name|TIME
name|last_packet_sent
decl_stmt|;
comment|/* Timestamp on last packet we sent. */
name|TIME
name|last_timestamp_received
decl_stmt|;
comment|/* The last timestamp we sent that 					   has been returned by our partner. */
name|TIME
name|skew
decl_stmt|;
comment|/* The skew between our clock and our partner's. */
name|struct
name|lease
modifier|*
name|update_queue_head
decl_stmt|;
comment|/* List of leases we haven't sent 					    to peer. */
name|struct
name|lease
modifier|*
name|update_queue_tail
decl_stmt|;
name|struct
name|lease
modifier|*
name|ack_queue_head
decl_stmt|;
comment|/* List of lease updates the peer 					   hasn't yet acked. */
name|struct
name|lease
modifier|*
name|ack_queue_tail
decl_stmt|;
name|struct
name|lease
modifier|*
name|send_update_done
decl_stmt|;
comment|/* When we get a BNDACK for this 					   lease, send an UPDDONE message. */
name|int
name|cur_unacked_updates
decl_stmt|;
comment|/* Number of updates we've sent 					   that have not yet been acked. */
comment|/* List of messages which we haven't 					   acked yet. */
name|failover_message_t
modifier|*
name|toack_queue_head
decl_stmt|;
name|failover_message_t
modifier|*
name|toack_queue_tail
decl_stmt|;
name|int
name|pending_acks
decl_stmt|;
comment|/* Number of messages in the toack 					   queue. */
name|int
name|pool_count
decl_stmt|;
comment|/* Number of pools referencing this 					   failover state object. */
block|}
name|dhcp_failover_state_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DHCP_FAILOVER_VERSION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FAILOVER_PROTOCOL */
end_comment

end_unit

