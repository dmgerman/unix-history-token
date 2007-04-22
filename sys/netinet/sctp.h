begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2006, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $KAME: sctp.h,v 1.18 2005/03/06 16:04:16 itojun Exp $	 */
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

begin_comment
comment|/*  * SCTP protocol - RFC2960.  */
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
comment|/* Adler32 C-Sum */
comment|/* chunks follow... */
block|}
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
name|SCTP_DELAYED_ACK_TIME
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
comment|/* explict EOR signalling */
end_comment

begin_define
define|#
directive|define
name|SCTP_EXPLICIT_EOR
value|0x0000001b
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

begin_comment
comment|/*  * user socket options: BSD implementation specific  */
end_comment

begin_comment
comment|/*  * Blocking I/O is enabled on any TCP type socket by default. For the UDP  * model if this is turned on then the socket buffer is shared for send  * resources amongst all associations.  The default for the UDP model is that  * is SS_NBIO is set.  Which means all associations have a seperate send  * limit BUT they will NOT ever BLOCK instead you will get an error back  * EAGAIN if you try to send to much. If you want the blocking symantics you  * set this option at the cost of sharing one socket send buffer size amongst  * all associations. Peeled off sockets turn this option off and block. But  * since both TCP and peeled off sockets have only one assoc per socket this  * is fine. It probably does NOT make sense to set this on SS_NBIO on a TCP  * model OR peeled off UDP model, but we do allow you to do so. You just use  * the normal syscall to toggle SS_NBIO the way you want.  *  * Blocking I/O is controled by the SS_NBIO flag on the socket state so_state  * field.  */
end_comment

begin_comment
comment|/* these should probably go into sockets API */
end_comment

begin_define
define|#
directive|define
name|SCTP_RESET_STREAMS
value|0x00001004
end_define

begin_comment
comment|/* wo */
end_comment

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
name|SCTP_GET_ASOC_ID_LIST
value|0x00001104
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCB_STATUS
value|0x00001105
end_define

begin_define
define|#
directive|define
name|SCTP_GET_NONCE_VALUES
value|0x00001106
end_define

begin_comment
comment|/* Special hook for dynamically setting primary for all assoc's,  * this is a write only option that requires root privledge.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_SET_DYNAMIC_PRIMARY
value|0x00002001
end_define

begin_comment
comment|/* VRF (virtual router feature) and multi-VRF support  * options. VRF's provide splits within a router  * that give the views of multiple routers. A  * standard host, without VRF support, is just  * a single VRF. If VRF's are supported then  * the transport must be VRF aware. This means  * that every socket call coming in must be directed  * within the endpoint to one of the VRF's it belongs  * to. The endpoint, before binding, may select  * the "default" VRF it is in by using a set socket  * option with SCTP_VRF_ID. This will also  * get propegated to the default VRF. Once the  * endpoint binds an address then it CANNOT add  * additional VRF's to become a Multi-VRF endpoint.  *  * Before BINDING additional VRF's can be added with  * the SCTP_ADD_VRF_ID call or deleted with  * SCTP_DEL_VRF_ID.  *  * Associations are ALWAYS contained inside a single  * VRF. They cannot reside in two (or more) VRF's. Incoming  * packets, assuming the router is VRF aware, can always  * tell us what VRF they arrived on. A host not supporting  * any VRF's will find that the packets always arrived on the  * single VRF that the host has.  *  */
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
comment|/* temporary workaround for Apple listen() issue, no args used */
end_comment

begin_define
define|#
directive|define
name|SCTP_LISTEN_FIX
value|0x0000800c
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
comment|/* Error causes from draft-ietf-tsvwg-addip-sctp */
end_comment

begin_define
define|#
directive|define
name|SCTP_CAUSE_DELETING_LAST_ADDR
value|0x0100
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_RESOURCE_SHORTAGE
value|0x0101
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_DELETING_SRC_ADDR
value|0x0102
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_ILLEGAL_ASCONF_ACK
value|0x0103
end_define

begin_define
define|#
directive|define
name|SCTP_CAUSE_REQUEST_REFUSED
value|0x0104
end_define

begin_comment
comment|/* Error causes from draft-ietf-tsvwg-sctp-auth */
end_comment

begin_define
define|#
directive|define
name|SCTP_CAUSE_UNSUPPORTED_HMACID
value|0x0105
end_define

begin_comment
comment|/*  * error cause parameters (user visisble)  */
end_comment

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
struct|;
end_struct

begin_define
define|#
directive|define
name|HAVE_SCTP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_KERNEL_SCTP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_PRSCTP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_ADDIP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_CANSET_PRIMARY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_SAT_CAPABILITY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_MULTIBUF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_NOCONNECT
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_ECN_NONCE
value|1
end_define

begin_comment
comment|/* ECN Nonce option */
end_comment

begin_define
define|#
directive|define
name|HAVE_SCTP_AUTH
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_EXT_RCVINFO
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_SCTP_CONNECTX
value|1
end_define

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
comment|/* draft-ietf-tsvwg-sctp-auth */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUTHENTICATION
value|0x0f
end_define

begin_comment
comment|/************0x40 series ***********/
end_comment

begin_comment
comment|/************0x80 series ***********/
end_comment

begin_comment
comment|/* draft-ietf-tsvwg-addip-sctp */
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
comment|/* draft-ietf-tsvwg-addip-sctp */
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

begin_include
include|#
directive|include
file|<netinet/sctp_uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_SCTP_H_ */
end_comment

end_unit

