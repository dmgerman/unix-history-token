begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2008, by Cisco Systems, Inc. All rights reserved.  * Copyright (c) 2008-2012, by Randall Stewart. All rights reserved.  * Copyright (c) 2008-2012, by Michael Tuexen. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|_NETINET_SCTP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_SCTP_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|SCTP_PACKED
value|__attribute__((packed))
end_define

begin_comment
comment|/*  * SCTP protocol - RFC4960.  */
end_comment

begin_struct
struct|struct
name|sctphdr
block|{
name|uint16_t
name|src_port
decl_stmt|;
comment|/* source port */
name|uint16_t
name|dest_port
decl_stmt|;
comment|/* destination port */
name|uint32_t
name|v_tag
decl_stmt|;
comment|/* verification tag of packet */
name|uint32_t
name|checksum
decl_stmt|;
comment|/* CRC32C checksum */
comment|/* chunks follow... */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_comment
comment|/*  * SCTP Chunks  */
end_comment

begin_struct
struct|struct
name|sctp_chunkhdr
block|{
name|uint8_t
name|chunk_type
decl_stmt|;
comment|/* chunk type */
name|uint8_t
name|chunk_flags
decl_stmt|;
comment|/* chunk flags */
name|uint16_t
name|chunk_length
decl_stmt|;
comment|/* chunk length */
comment|/* optional params follow */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_comment
comment|/*  * SCTP chunk parameters  */
end_comment

begin_struct
struct|struct
name|sctp_paramhdr
block|{
name|uint16_t
name|param_type
decl_stmt|;
comment|/* parameter type */
name|uint16_t
name|param_length
decl_stmt|;
comment|/* parameter length */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_comment
comment|/*  * user socket options: socket API defined  */
end_comment

begin_comment
comment|/*  * read-write options  */
end_comment

begin_define
define|#
directive|define
name|SCTP_RTOINFO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_ASSOCINFO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_INITMSG
value|0x00000003
end_define

begin_define
define|#
directive|define
name|SCTP_NODELAY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_AUTOCLOSE
value|0x00000005
end_define

begin_define
define|#
directive|define
name|SCTP_SET_PEER_PRIMARY_ADDR
value|0x00000006
end_define

begin_define
define|#
directive|define
name|SCTP_PRIMARY_ADDR
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SCTP_ADAPTATION_LAYER
value|0x00000008
end_define

begin_comment
comment|/* same as above */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADAPTION_LAYER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SCTP_DISABLE_FRAGMENTS
value|0x00000009
end_define

begin_define
define|#
directive|define
name|SCTP_PEER_ADDR_PARAMS
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|SCTP_DEFAULT_SEND_PARAM
value|0x0000000b
end_define

begin_comment
comment|/* ancillary data/notification interest options */
end_comment

begin_define
define|#
directive|define
name|SCTP_EVENTS
value|0x0000000c
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_comment
comment|/* Without this applied we will give V4 and V6 addresses on a V6 socket */
end_comment

begin_define
define|#
directive|define
name|SCTP_I_WANT_MAPPED_V4_ADDR
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|SCTP_MAXSEG
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|SCTP_DELAYED_SACK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|SCTP_FRAGMENT_INTERLEAVE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SCTP_PARTIAL_DELIVERY_POINT
value|0x00000011
end_define

begin_comment
comment|/* authentication support */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTH_CHUNK
value|0x00000012
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_KEY
value|0x00000013
end_define

begin_define
define|#
directive|define
name|SCTP_HMAC_IDENT
value|0x00000014
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_ACTIVE_KEY
value|0x00000015
end_define

begin_define
define|#
directive|define
name|SCTP_AUTH_DELETE_KEY
value|0x00000016
end_define

begin_define
define|#
directive|define
name|SCTP_USE_EXT_RCVINFO
value|0x00000017
end_define

begin_define
define|#
directive|define
name|SCTP_AUTO_ASCONF
value|0x00000018
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAXBURST
value|0x00000019
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_BURST
value|0x00000019
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* assoc level context */
end_comment

begin_define
define|#
directive|define
name|SCTP_CONTEXT
value|0x0000001a
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* explicit EOR signalling */
end_comment

begin_define
define|#
directive|define
name|SCTP_EXPLICIT_EOR
value|0x0000001b
end_define

begin_define
define|#
directive|define
name|SCTP_REUSE_PORT
value|0x0000001c
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTH_DEACTIVATE_KEY
value|0x0000001d
end_define

begin_define
define|#
directive|define
name|SCTP_EVENT
value|0x0000001e
end_define

begin_define
define|#
directive|define
name|SCTP_RECVRCVINFO
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|SCTP_RECVNXTINFO
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SCTP_DEFAULT_SNDINFO
value|0x00000021
end_define

begin_define
define|#
directive|define
name|SCTP_DEFAULT_PRINFO
value|0x00000022
end_define

begin_define
define|#
directive|define
name|SCTP_PEER_ADDR_THLDS
value|0x00000023
end_define

begin_define
define|#
directive|define
name|SCTP_REMOTE_UDP_ENCAPS_PORT
value|0x00000024
end_define

begin_define
define|#
directive|define
name|SCTP_ECN_SUPPORTED
value|0x00000025
end_define

begin_define
define|#
directive|define
name|SCTP_PR_SUPPORTED
value|0x00000026
end_define

begin_comment
comment|/*  * read-only options  */
end_comment

begin_define
define|#
directive|define
name|SCTP_STATUS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SCTP_GET_PEER_ADDR_INFO
value|0x00000101
end_define

begin_comment
comment|/* authentication support */
end_comment

begin_define
define|#
directive|define
name|SCTP_PEER_AUTH_CHUNKS
value|0x00000102
end_define

begin_define
define|#
directive|define
name|SCTP_LOCAL_AUTH_CHUNKS
value|0x00000103
end_define

begin_define
define|#
directive|define
name|SCTP_GET_ASSOC_NUMBER
value|0x00000104
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_ASSOC_ID_LIST
value|0x00000105
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|SCTP_TIMEOUTS
value|0x00000106
end_define

begin_comment
comment|/*  * user socket options: BSD implementation specific  */
end_comment

begin_comment
comment|/*  * Blocking I/O is enabled on any TCP type socket by default. For the UDP  * model if this is turned on then the socket buffer is shared for send  * resources amongst all associations.  The default for the UDP model is that  * is SS_NBIO is set.  Which means all associations have a separate send  * limit BUT they will NOT ever BLOCK instead you will get an error back  * EAGAIN if you try to send too much. If you want the blocking semantics you  * set this option at the cost of sharing one socket send buffer size amongst  * all associations. Peeled off sockets turn this option off and block. But  * since both TCP and peeled off sockets have only one assoc per socket this  * is fine. It probably does NOT make sense to set this on SS_NBIO on a TCP  * model OR peeled off UDP model, but we do allow you to do so. You just use  * the normal syscall to toggle SS_NBIO the way you want.  *  * Blocking I/O is controlled by the SS_NBIO flag on the socket state so_state  * field.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_ENABLE_STREAM_RESET
value|0x00000900
end_define

begin_comment
comment|/* struct 							 * sctp_assoc_value */
end_comment

begin_define
define|#
directive|define
name|SCTP_RESET_STREAMS
value|0x00000901
end_define

begin_comment
comment|/* struct 							 * sctp_reset_streams */
end_comment

begin_define
define|#
directive|define
name|SCTP_RESET_ASSOC
value|0x00000902
end_define

begin_comment
comment|/* sctp_assoc_t */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADD_STREAMS
value|0x00000903
end_define

begin_comment
comment|/* struct 							 * sctp_add_streams */
end_comment

begin_comment
comment|/* For enable stream reset */
end_comment

begin_define
define|#
directive|define
name|SCTP_ENABLE_RESET_STREAM_REQ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_ENABLE_RESET_ASSOC_REQ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_ENABLE_CHANGE_ASSOC_REQ
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_ENABLE_VALUE_MASK
value|0x00000007
end_define

begin_comment
comment|/* For reset streams */
end_comment

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_INCOMING
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_OUTGOING
value|0x00000002
end_define

begin_comment
comment|/* here on down are more implementation specific */
end_comment

begin_define
define|#
directive|define
name|SCTP_SET_DEBUG_LEVEL
value|0x00001005
end_define

begin_define
define|#
directive|define
name|SCTP_CLR_STAT_LOG
value|0x00001007
end_define

begin_comment
comment|/* CMT ON/OFF socket option */
end_comment

begin_define
define|#
directive|define
name|SCTP_CMT_ON_OFF
value|0x00001200
end_define

begin_define
define|#
directive|define
name|SCTP_CMT_USE_DAC
value|0x00001201
end_define

begin_comment
comment|/* JRS - Pluggable Congestion Control Socket option */
end_comment

begin_define
define|#
directive|define
name|SCTP_PLUGGABLE_CC
value|0x00001202
end_define

begin_comment
comment|/* RS - Pluggable Stream Scheduling Socket option */
end_comment

begin_define
define|#
directive|define
name|SCTP_PLUGGABLE_SS
value|0x00001203
end_define

begin_define
define|#
directive|define
name|SCTP_SS_VALUE
value|0x00001204
end_define

begin_define
define|#
directive|define
name|SCTP_CC_OPTION
value|0x00001205
end_define

begin_comment
comment|/* Options for CC 							 * modules */
end_comment

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_SNDBUF_USE
value|0x00001101
end_define

begin_define
define|#
directive|define
name|SCTP_GET_STAT_LOG
value|0x00001103
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_STATUS
value|0x00001104
end_define

begin_define
define|#
directive|define
name|SCTP_GET_NONCE_VALUES
value|0x00001105
end_define

begin_comment
comment|/* Special hook for dynamically setting primary for all assoc's,  * this is a write only option that requires root privilege.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_SET_DYNAMIC_PRIMARY
value|0x00002001
end_define

begin_comment
comment|/* VRF (virtual router feature) and multi-VRF support  * options. VRF's provide splits within a router  * that give the views of multiple routers. A  * standard host, without VRF support, is just  * a single VRF. If VRF's are supported then  * the transport must be VRF aware. This means  * that every socket call coming in must be directed  * within the endpoint to one of the VRF's it belongs  * to. The endpoint, before binding, may select  * the "default" VRF it is in by using a set socket  * option with SCTP_VRF_ID. This will also  * get propagated to the default VRF. Once the  * endpoint binds an address then it CANNOT add  * additional VRF's to become a Multi-VRF endpoint.  *  * Before BINDING additional VRF's can be added with  * the SCTP_ADD_VRF_ID call or deleted with  * SCTP_DEL_VRF_ID.  *  * Associations are ALWAYS contained inside a single  * VRF. They cannot reside in two (or more) VRF's. Incoming  * packets, assuming the router is VRF aware, can always  * tell us what VRF they arrived on. A host not supporting  * any VRF's will find that the packets always arrived on the  * single VRF that the host has.  *  */
end_comment

begin_define
define|#
directive|define
name|SCTP_VRF_ID
value|0x00003001
end_define

begin_define
define|#
directive|define
name|SCTP_ADD_VRF_ID
value|0x00003002
end_define

begin_define
define|#
directive|define
name|SCTP_GET_VRF_IDS
value|0x00003003
end_define

begin_define
define|#
directive|define
name|SCTP_GET_ASOC_VRF
value|0x00003004
end_define

begin_define
define|#
directive|define
name|SCTP_DEL_VRF_ID
value|0x00003005
end_define

begin_comment
comment|/*  * If you enable packet logging you can get  * a poor mans ethereal output in binary  * form. Note this is a compile option to  * the kernel,  SCTP_PACKET_LOGGING, and  * without it in your kernel you  * will get a EOPNOTSUPP  */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_PACKET_LOG
value|0x00004001
end_define

begin_comment
comment|/*  * hidden implementation specific options these are NOT user visible (should  * move out of sctp.h)  */
end_comment

begin_comment
comment|/* sctp_bindx() flags as hidden socket options */
end_comment

begin_define
define|#
directive|define
name|SCTP_BINDX_ADD_ADDR
value|0x00008001
end_define

begin_define
define|#
directive|define
name|SCTP_BINDX_REM_ADDR
value|0x00008002
end_define

begin_comment
comment|/* Hidden socket option that gets the addresses */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_PEER_ADDRESSES
value|0x00008003
end_define

begin_define
define|#
directive|define
name|SCTP_GET_LOCAL_ADDRESSES
value|0x00008004
end_define

begin_comment
comment|/* return the total count in bytes needed to hold all local addresses bound */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_LOCAL_ADDR_SIZE
value|0x00008005
end_define

begin_comment
comment|/* Return the total count in bytes needed to hold the remote address */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_REMOTE_ADDR_SIZE
value|0x00008006
end_define

begin_comment
comment|/* hidden option for connectx */
end_comment

begin_define
define|#
directive|define
name|SCTP_CONNECT_X
value|0x00008007
end_define

begin_comment
comment|/* hidden option for connectx_delayed, part of sendx */
end_comment

begin_define
define|#
directive|define
name|SCTP_CONNECT_X_DELAYED
value|0x00008008
end_define

begin_define
define|#
directive|define
name|SCTP_CONNECT_X_COMPLETE
value|0x00008009
end_define

begin_comment
comment|/* hidden socket option based sctp_peeloff */
end_comment

begin_define
define|#
directive|define
name|SCTP_PEELOFF
value|0x0000800a
end_define

begin_comment
comment|/* the real worker for sctp_getaddrlen() */
end_comment

begin_define
define|#
directive|define
name|SCTP_GET_ADDR_LEN
value|0x0000800b
end_define

begin_comment
comment|/* Debug things that need to be purged */
end_comment

begin_define
define|#
directive|define
name|SCTP_SET_INITIAL_DBG_SEQ
value|0x00009f00
end_define

begin_comment
comment|/* JRS - Supported congestion control modules for pluggable  * congestion control  */
end_comment

begin_comment
comment|/* Standard TCP Congestion Control */
end_comment

begin_define
define|#
directive|define
name|SCTP_CC_RFC2581
value|0x00000000
end_define

begin_comment
comment|/* High Speed TCP Congestion Control (Floyd) */
end_comment

begin_define
define|#
directive|define
name|SCTP_CC_HSTCP
value|0x00000001
end_define

begin_comment
comment|/* HTCP Congestion Control */
end_comment

begin_define
define|#
directive|define
name|SCTP_CC_HTCP
value|0x00000002
end_define

begin_comment
comment|/* RTCC Congestion Control - RFC2581 plus */
end_comment

begin_define
define|#
directive|define
name|SCTP_CC_RTCC
value|0x00000003
end_define

begin_define
define|#
directive|define
name|SCTP_CC_OPT_RTCC_SETMODE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SCTP_CC_OPT_USE_DCCC_ECN
value|0x00002001
end_define

begin_define
define|#
directive|define
name|SCTP_CC_OPT_STEADY_STEP
value|0x00002002
end_define

begin_define
define|#
directive|define
name|SCTP_CMT_OFF
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_CMT_BASE
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_CMT_RPV1
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_CMT_RPV2
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_CMT_MPTCP
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_CMT_MAX
value|SCTP_CMT_MPTCP
end_define

begin_comment
comment|/* RS - Supported stream scheduling modules for pluggable  * stream scheduling  */
end_comment

begin_comment
comment|/* Default simple round-robin */
end_comment

begin_define
define|#
directive|define
name|SCTP_SS_DEFAULT
value|0x00000000
end_define

begin_comment
comment|/* Real round-robin */
end_comment

begin_define
define|#
directive|define
name|SCTP_SS_ROUND_ROBIN
value|0x00000001
end_define

begin_comment
comment|/* Real round-robin per packet */
end_comment

begin_define
define|#
directive|define
name|SCTP_SS_ROUND_ROBIN_PACKET
value|0x00000002
end_define

begin_comment
comment|/* Priority */
end_comment

begin_define
define|#
directive|define
name|SCTP_SS_PRIORITY
value|0x00000003
end_define

begin_comment
comment|/* Fair Bandwidth */
end_comment

begin_define
define|#
directive|define
name|SCTP_SS_FAIR_BANDWITH
value|0x00000004
end_define

begin_comment
comment|/* First-come, first-serve */
end_comment

begin_define
define|#
directive|define
name|SCTP_SS_FIRST_COME
value|0x00000005
end_define

begin_comment
comment|/* fragment interleave constants  * setting must be one of these or  * EINVAL returned.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_FRAG_LEVEL_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCTP_FRAG_LEVEL_1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_FRAG_LEVEL_2
value|0x00000002
end_define

begin_comment
comment|/*  * user state values  */
end_comment

begin_define
define|#
directive|define
name|SCTP_CLOSED
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCTP_BOUND
value|0x1000
end_define

begin_define
define|#
directive|define
name|SCTP_LISTEN
value|0x2000
end_define

begin_define
define|#
directive|define
name|SCTP_COOKIE_WAIT
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_COOKIE_ECHOED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_ESTABLISHED
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_SENT
value|0x0010
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_RECEIVED
value|0x0020
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_ACK_SENT
value|0x0040
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_PENDING
value|0x0080
end_define

begin_comment
comment|/*  * SCTP operational error codes (user visible)  */
end_comment

begin_define
define|#
directive|define
name|SCTP_CAUSE_NO_ERROR
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_INVALID_STREAM
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_MISSING_PARAM
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_STALE_COOKIE
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_OUT_OF_RESC
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_UNRESOLVABLE_ADDR
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_UNRECOG_CHUNK
value|0x0006
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_INVALID_PARAM
value|0x0007
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_UNRECOG_PARAM
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_NO_USER_DATA
value|0x0009
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_COOKIE_IN_SHUTDOWN
value|0x000a
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_RESTART_W_NEWADDR
value|0x000b
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_USER_INITIATED_ABT
value|0x000c
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_PROTOCOL_VIOLATION
value|0x000d
end_define

begin_comment
comment|/* Error causes from RFC5061 */
end_comment

begin_define
define|#
directive|define
name|SCTP_CAUSE_DELETING_LAST_ADDR
value|0x00a0
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_RESOURCE_SHORTAGE
value|0x00a1
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_DELETING_SRC_ADDR
value|0x00a2
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_ILLEGAL_ASCONF_ACK
value|0x00a3
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_REQUEST_REFUSED
value|0x00a4
end_define

begin_comment
comment|/* Error causes from nat-draft */
end_comment

begin_define
define|#
directive|define
name|SCTP_CAUSE_NAT_COLLIDING_STATE
value|0x00b0
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_NAT_MISSING_STATE
value|0x00b1
end_define

begin_comment
comment|/* Error causes from RFC4895 */
end_comment

begin_define
define|#
directive|define
name|SCTP_CAUSE_UNSUPPORTED_HMACID
value|0x0105
end_define

begin_comment
comment|/*  * error cause parameters (user visible)  */
end_comment

begin_struct
struct|struct
name|sctp_gen_error_cause
block|{
name|uint16_t
name|code
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|info
index|[]
decl_stmt|;
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|sctp_error_cause
block|{
name|uint16_t
name|code
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
comment|/* optional cause-specific info may follow */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|sctp_error_invalid_stream
block|{
name|struct
name|sctp_error_cause
name|cause
decl_stmt|;
comment|/* code=SCTP_ERROR_INVALID_STREAM */
name|uint16_t
name|stream_id
decl_stmt|;
comment|/* stream id of the DATA in error */
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|sctp_error_missing_param
block|{
name|struct
name|sctp_error_cause
name|cause
decl_stmt|;
comment|/* code=SCTP_ERROR_MISSING_PARAM */
name|uint32_t
name|num_missing_params
decl_stmt|;
comment|/* number of missing parameters */
comment|/* uint16_t param_type's follow */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|sctp_error_stale_cookie
block|{
name|struct
name|sctp_error_cause
name|cause
decl_stmt|;
comment|/* code=SCTP_ERROR_STALE_COOKIE */
name|uint32_t
name|stale_time
decl_stmt|;
comment|/* time in usec of staleness */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|sctp_error_out_of_resource
block|{
name|struct
name|sctp_error_cause
name|cause
decl_stmt|;
comment|/* code=SCTP_ERROR_OUT_OF_RESOURCES */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|sctp_error_unresolv_addr
block|{
name|struct
name|sctp_error_cause
name|cause
decl_stmt|;
comment|/* code=SCTP_ERROR_UNRESOLVABLE_ADDR */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|sctp_error_unrecognized_chunk
block|{
name|struct
name|sctp_error_cause
name|cause
decl_stmt|;
comment|/* code=SCTP_ERROR_UNRECOG_CHUNK */
name|struct
name|sctp_chunkhdr
name|ch
decl_stmt|;
comment|/* header from chunk in error */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_struct
struct|struct
name|sctp_error_no_user_data
block|{
name|struct
name|sctp_error_cause
name|cause
decl_stmt|;
comment|/* code=SCTP_CAUSE_NO_USER_DATA */
name|uint32_t
name|tsn
decl_stmt|;
comment|/* TSN of the empty data chunk */
block|}
name|SCTP_PACKED
struct|;
end_struct

begin_comment
comment|/*  * Main SCTP chunk types we place these here so natd and f/w's in user land  * can find them.  */
end_comment

begin_comment
comment|/************0x00 series ***********/
end_comment

begin_define
define|#
directive|define
name|SCTP_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|SCTP_INITIATION
value|0x01
end_define

begin_define
define|#
directive|define
name|SCTP_INITIATION_ACK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_SELECTIVE_ACK
value|0x03
end_define

begin_define
define|#
directive|define
name|SCTP_HEARTBEAT_REQUEST
value|0x04
end_define

begin_define
define|#
directive|define
name|SCTP_HEARTBEAT_ACK
value|0x05
end_define

begin_define
define|#
directive|define
name|SCTP_ABORT_ASSOCIATION
value|0x06
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN
value|0x07
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_ACK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCTP_OPERATION_ERROR
value|0x09
end_define

begin_define
define|#
directive|define
name|SCTP_COOKIE_ECHO
value|0x0a
end_define

begin_define
define|#
directive|define
name|SCTP_COOKIE_ACK
value|0x0b
end_define

begin_define
define|#
directive|define
name|SCTP_ECN_ECHO
value|0x0c
end_define

begin_define
define|#
directive|define
name|SCTP_ECN_CWR
value|0x0d
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_COMPLETE
value|0x0e
end_define

begin_comment
comment|/* RFC4895 */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTHENTICATION
value|0x0f
end_define

begin_comment
comment|/* EY nr_sack chunk id*/
end_comment

begin_define
define|#
directive|define
name|SCTP_NR_SELECTIVE_ACK
value|0x10
end_define

begin_comment
comment|/************0x40 series ***********/
end_comment

begin_comment
comment|/************0x80 series ***********/
end_comment

begin_comment
comment|/* RFC5061 */
end_comment

begin_define
define|#
directive|define
name|SCTP_ASCONF_ACK
value|0x80
end_define

begin_comment
comment|/* draft-ietf-stewart-pktdrpsctp */
end_comment

begin_define
define|#
directive|define
name|SCTP_PACKET_DROPPED
value|0x81
end_define

begin_comment
comment|/* draft-ietf-stewart-strreset-xxx */
end_comment

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET
value|0x82
end_define

begin_comment
comment|/* RFC4820                         */
end_comment

begin_define
define|#
directive|define
name|SCTP_PAD_CHUNK
value|0x84
end_define

begin_comment
comment|/************0xc0 series ***********/
end_comment

begin_comment
comment|/* RFC3758 */
end_comment

begin_define
define|#
directive|define
name|SCTP_FORWARD_CUM_TSN
value|0xc0
end_define

begin_comment
comment|/* RFC5061 */
end_comment

begin_define
define|#
directive|define
name|SCTP_ASCONF
value|0xc1
end_define

begin_comment
comment|/* ABORT and SHUTDOWN COMPLETE FLAG */
end_comment

begin_define
define|#
directive|define
name|SCTP_HAD_NO_TCB
value|0x01
end_define

begin_comment
comment|/* Packet dropped flags */
end_comment

begin_define
define|#
directive|define
name|SCTP_FROM_MIDDLE_BOX
value|SCTP_HAD_NO_TCB
end_define

begin_define
define|#
directive|define
name|SCTP_BADCRC
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_PACKET_TRUNCATED
value|0x04
end_define

begin_comment
comment|/* Flag for ECN -CWR */
end_comment

begin_define
define|#
directive|define
name|SCTP_CWR_REDUCE_OVERRIDE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCTP_CWR_IN_SAME_WINDOW
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_SAT_NETWORK_MIN
value|400
end_define

begin_comment
comment|/* min ms for RTT to set satellite 					 * time */
end_comment

begin_define
define|#
directive|define
name|SCTP_SAT_NETWORK_BURST_INCR
value|2
end_define

begin_comment
comment|/* how many times to multiply maxburst 					 * in sat */
end_comment

begin_comment
comment|/* Data Chuck Specific Flags */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATA_FRAG_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_MIDDLE_FRAG
value|0x00
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_LAST_FRAG
value|0x01
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_FIRST_FRAG
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_NOT_FRAG
value|0x03
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_UNORDERED
value|0x04
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_SACK_IMMEDIATELY
value|0x08
end_define

begin_comment
comment|/* ECN Nonce: SACK Chunk Specific Flags */
end_comment

begin_define
define|#
directive|define
name|SCTP_SACK_NONCE_SUM
value|0x01
end_define

begin_comment
comment|/* CMT DAC algorithm SACK flag */
end_comment

begin_define
define|#
directive|define
name|SCTP_SACK_CMT_DAC
value|0x80
end_define

begin_comment
comment|/*  * PCB flags (in sctp_flags bitmask).  * Note the features and flags are meant  * for use by netstat.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_UDPTYPE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_TCPTYPE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_BOUNDALL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_ACCEPTING
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_UNBOUND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_CLOSE_IP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_WAS_CONNECTED
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_WAS_ABORTED
value|0x00100000
end_define

begin_comment
comment|/* TCP model support */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_CONNECTED
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_IN_TCPPOOL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_DONT_WAKE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_WAKEOUTPUT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_WAKEINPUT
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_BOUND_V6
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_BLOCKING_IO
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_SOCKET_GONE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_SOCKET_ALLGONE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_SOCKET_CANT_READ
value|0x40000000
end_define

begin_comment
comment|/* flags to copy to new PCB */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_COPY_FLAGS
value|(SCTP_PCB_FLAGS_BOUNDALL|\ 					 SCTP_PCB_FLAGS_WAKEINPUT|\ 					 SCTP_PCB_FLAGS_BOUND_V6)
end_define

begin_comment
comment|/*  * PCB Features (in sctp_features bitmask)  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_DO_NOT_PMTUD
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_EXT_RCVINFO
value|0x0000000000000002
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_DONOT_HEARTBEAT
value|0x0000000000000004
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_FRAG_INTERLEAVE
value|0x0000000000000008
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_INTERLEAVE_STRMS
value|0x0000000000000010
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_DO_ASCONF
value|0x0000000000000020
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_AUTO_ASCONF
value|0x0000000000000040
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_ZERO_COPY_ACTIVE
value|0x0000000000000080
end_define

begin_comment
comment|/* socket options */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_NODELAY
value|0x0000000000000100
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_AUTOCLOSE
value|0x0000000000000200
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVDATAIOEVNT
value|0x0000000000000400
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVASSOCEVNT
value|0x0000000000000800
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVPADDREVNT
value|0x0000000000001000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVPEERERR
value|0x0000000000002000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVSENDFAILEVNT
value|0x0000000000004000
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVSHUTDOWNEVNT
value|0x0000000000008000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_ADAPTATIONEVNT
value|0x0000000000010000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_PDAPIEVNT
value|0x0000000000020000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_AUTHEVNT
value|0x0000000000040000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_STREAM_RESETEVNT
value|0x0000000000080000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_NO_FRAGMENT
value|0x0000000000100000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_EXPLICIT_EOR
value|0x0000000000400000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_NEEDS_MAPPED_V4
value|0x0000000000800000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_MULTIPLE_ASCONFS
value|0x0000000001000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_PORTREUSE
value|0x0000000002000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_DRYEVNT
value|0x0000000004000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVRCVINFO
value|0x0000000008000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVNXTINFO
value|0x0000000010000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_ASSOC_RESETEVNT
value|0x0000000020000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_STREAM_CHANGEEVNT
value|0x0000000040000000
end_define

begin_define
define|#
directive|define
name|SCTP_PCB_FLAGS_RECVNSENDFAILEVNT
value|0x0000000080000000
end_define

begin_comment
comment|/*-  * mobility_features parameters (by micchie).Note  * these features are applied against the  * sctp_mobility_features flags.. not the sctp_features  * flags.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MOBILITY_BASE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_MOBILITY_FASTHANDOFF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_MOBILITY_PRIM_DELETED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_SMALLEST_PMTU
value|512
end_define

begin_comment
comment|/* smallest pmtu allowed when disabling PMTU 				 * discovery */
end_comment

begin_undef
undef|#
directive|undef
name|SCTP_PACKED
end_undef

begin_include
include|#
directive|include
file|<netinet/sctp_uio.h>
end_include

begin_comment
comment|/* This dictates the size of the packet  * collection buffer. This only applies  * if SCTP_PACKET_LOGGING is enabled in  * your config.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PACKET_LOG_SIZE
value|65536
end_define

begin_comment
comment|/* Maximum delays and such a user can set for options that  * take ms.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_SACK_DELAY
value|500
end_define

begin_comment
comment|/* per RFC4960 */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_HB_INTERVAL
value|14400000
end_define

begin_comment
comment|/* 4 hours in ms */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_COOKIE_LIFE
value|3600000
end_define

begin_comment
comment|/* 1 hour in ms */
end_comment

begin_comment
comment|/* Types of logging/KTR tracing  that can be enabled via the  * sysctl net.inet.sctp.sctp_logging. You must also enable  * SUBSYS tracing.  * Note that you must have the SCTP option in the kernel  * to enable these as well.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_BLK_LOGGING_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_MONITOR_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOGGING_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_FLIGHT_LOGGING_ENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SCTP_FR_LOGGING_ENABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SCTP_LOCK_LOGGING_ENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SCTP_MAP_LOGGING_ENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SCTP_MBCNT_LOGGING_ENABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCTP_MBUF_LOGGING_ENABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SCTP_NAGLE_LOGGING_ENABLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SCTP_RECV_RWND_LOGGING_ENABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SCTP_RTTVAR_LOGGING_ENABLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SCTP_SACK_LOGGING_ENABLE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SCTP_SACK_RWND_LOGGING_ENABLE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SCTP_SB_LOGGING_ENABLE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SCTP_STR_LOGGING_ENABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SCTP_WAKE_LOGGING_ENABLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_MAXBURST_ENABLE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_RWND_ENABLE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_SACK_ARRIVALS_ENABLE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SCTP_LTRACE_CHUNK_ENABLE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SCTP_LTRACE_ERROR_ENABLE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SCTP_LAST_PACKET_TRACING
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCTP_THRESHOLD_LOGGING
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_AT_SEND_2_SCTP
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_AT_SEND_2_OUTQ
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_TRY_ADVANCE
value|0x10000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_SCTP_H_ */
end_comment

end_unit

