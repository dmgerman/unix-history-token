begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Daniel Hartmeier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *    - Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    - Redistributions in binary form must reproduce the above  *      copyright notice, this list of conditions and the following  *      disclaimer in the documentation and/or other materials provided  *      with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	$OpenBSD: pfvar.h,v 1.282 2009/01/29 15:12:28 pyr Exp $  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_PF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_PF_H_
end_define

begin_define
define|#
directive|define
name|PF_TCPS_PROXY_SRC
value|((TCP_NSTATES)+0)
end_define

begin_define
define|#
directive|define
name|PF_TCPS_PROXY_DST
value|((TCP_NSTATES)+1)
end_define

begin_define
define|#
directive|define
name|PF_MD5_DIGEST_LENGTH
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MD5_DIGEST_LENGTH
end_ifdef

begin_if
if|#
directive|if
name|PF_MD5_DIGEST_LENGTH
operator|!=
name|MD5_DIGEST_LENGTH
end_if

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
block|{
name|PF_INOUT
block|,
name|PF_IN
block|,
name|PF_OUT
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_PASS
block|,
name|PF_DROP
block|,
name|PF_SCRUB
block|,
name|PF_NOSCRUB
block|,
name|PF_NAT
block|,
name|PF_NONAT
block|,
name|PF_BINAT
block|,
name|PF_NOBINAT
block|,
name|PF_RDR
block|,
name|PF_NORDR
block|,
name|PF_SYNPROXY_DROP
block|,
name|PF_DEFER
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_RULESET_SCRUB
block|,
name|PF_RULESET_FILTER
block|,
name|PF_RULESET_NAT
block|,
name|PF_RULESET_BINAT
block|,
name|PF_RULESET_RDR
block|,
name|PF_RULESET_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_OP_NONE
block|,
name|PF_OP_IRG
block|,
name|PF_OP_EQ
block|,
name|PF_OP_NE
block|,
name|PF_OP_LT
block|,
name|PF_OP_LE
block|,
name|PF_OP_GT
block|,
name|PF_OP_GE
block|,
name|PF_OP_XRG
block|,
name|PF_OP_RRG
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_DEBUG_NONE
block|,
name|PF_DEBUG_URGENT
block|,
name|PF_DEBUG_MISC
block|,
name|PF_DEBUG_NOISY
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_CHANGE_NONE
block|,
name|PF_CHANGE_ADD_HEAD
block|,
name|PF_CHANGE_ADD_TAIL
block|,
name|PF_CHANGE_ADD_BEFORE
block|,
name|PF_CHANGE_ADD_AFTER
block|,
name|PF_CHANGE_REMOVE
block|,
name|PF_CHANGE_GET_TICKET
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_GET_NONE
block|,
name|PF_GET_CLR_CNTR
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_SK_WIRE
block|,
name|PF_SK_STACK
block|,
name|PF_SK_BOTH
block|}
enum|;
end_enum

begin_comment
comment|/*  * Note about PFTM_*: real indices into pf_rule.timeout[] come before  * PFTM_MAX, special cases afterwards. See pf_state_expires().  */
end_comment

begin_enum
enum|enum
block|{
name|PFTM_TCP_FIRST_PACKET
block|,
name|PFTM_TCP_OPENING
block|,
name|PFTM_TCP_ESTABLISHED
block|,
name|PFTM_TCP_CLOSING
block|,
name|PFTM_TCP_FIN_WAIT
block|,
name|PFTM_TCP_CLOSED
block|,
name|PFTM_UDP_FIRST_PACKET
block|,
name|PFTM_UDP_SINGLE
block|,
name|PFTM_UDP_MULTIPLE
block|,
name|PFTM_ICMP_FIRST_PACKET
block|,
name|PFTM_ICMP_ERROR_REPLY
block|,
name|PFTM_OTHER_FIRST_PACKET
block|,
name|PFTM_OTHER_SINGLE
block|,
name|PFTM_OTHER_MULTIPLE
block|,
name|PFTM_FRAG
block|,
name|PFTM_INTERVAL
block|,
name|PFTM_ADAPTIVE_START
block|,
name|PFTM_ADAPTIVE_END
block|,
name|PFTM_SRC_NODE
block|,
name|PFTM_TS_DIFF
block|,
name|PFTM_MAX
block|,
name|PFTM_PURGE
block|,
name|PFTM_UNLINKED
block|,
name|PFTM_UNTIL_PACKET
block|}
enum|;
end_enum

begin_comment
comment|/* PFTM default values */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_FIRST_PACKET_VAL
value|120
end_define

begin_comment
comment|/* First TCP packet */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_OPENING_VAL
value|30
end_define

begin_comment
comment|/* No response yet */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_ESTABLISHED_VAL
value|24*60*60
end_define

begin_comment
comment|/* Established */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_CLOSING_VAL
value|15 * 60
end_define

begin_comment
comment|/* Half closed */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_FIN_WAIT_VAL
value|45
end_define

begin_comment
comment|/* Got both FINs */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_CLOSED_VAL
value|90
end_define

begin_comment
comment|/* Got a RST */
end_comment

begin_define
define|#
directive|define
name|PFTM_UDP_FIRST_PACKET_VAL
value|60
end_define

begin_comment
comment|/* First UDP packet */
end_comment

begin_define
define|#
directive|define
name|PFTM_UDP_SINGLE_VAL
value|30
end_define

begin_comment
comment|/* Unidirectional */
end_comment

begin_define
define|#
directive|define
name|PFTM_UDP_MULTIPLE_VAL
value|60
end_define

begin_comment
comment|/* Bidirectional */
end_comment

begin_define
define|#
directive|define
name|PFTM_ICMP_FIRST_PACKET_VAL
value|20
end_define

begin_comment
comment|/* First ICMP packet */
end_comment

begin_define
define|#
directive|define
name|PFTM_ICMP_ERROR_REPLY_VAL
value|10
end_define

begin_comment
comment|/* Got error response */
end_comment

begin_define
define|#
directive|define
name|PFTM_OTHER_FIRST_PACKET_VAL
value|60
end_define

begin_comment
comment|/* First packet */
end_comment

begin_define
define|#
directive|define
name|PFTM_OTHER_SINGLE_VAL
value|30
end_define

begin_comment
comment|/* Unidirectional */
end_comment

begin_define
define|#
directive|define
name|PFTM_OTHER_MULTIPLE_VAL
value|60
end_define

begin_comment
comment|/* Bidirectional */
end_comment

begin_define
define|#
directive|define
name|PFTM_FRAG_VAL
value|30
end_define

begin_comment
comment|/* Fragment expire */
end_comment

begin_define
define|#
directive|define
name|PFTM_INTERVAL_VAL
value|10
end_define

begin_comment
comment|/* Expire interval */
end_comment

begin_define
define|#
directive|define
name|PFTM_SRC_NODE_VAL
value|0
end_define

begin_comment
comment|/* Source tracking */
end_comment

begin_define
define|#
directive|define
name|PFTM_TS_DIFF_VAL
value|30
end_define

begin_comment
comment|/* Allowed TS diff */
end_comment

begin_enum
enum|enum
block|{
name|PF_NOPFROUTE
block|,
name|PF_FASTROUTE
block|,
name|PF_ROUTETO
block|,
name|PF_DUPTO
block|,
name|PF_REPLYTO
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_LIMIT_STATES
block|,
name|PF_LIMIT_SRC_NODES
block|,
name|PF_LIMIT_FRAGS
block|,
name|PF_LIMIT_TABLE_ENTRIES
block|,
name|PF_LIMIT_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PF_POOL_IDMASK
value|0x0f
end_define

begin_enum
enum|enum
block|{
name|PF_POOL_NONE
block|,
name|PF_POOL_BITMASK
block|,
name|PF_POOL_RANDOM
block|,
name|PF_POOL_SRCHASH
block|,
name|PF_POOL_ROUNDROBIN
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_ADDR_ADDRMASK
block|,
name|PF_ADDR_NOROUTE
block|,
name|PF_ADDR_DYNIFTL
block|,
name|PF_ADDR_TABLE
block|,
name|PF_ADDR_URPFFAILED
block|,
name|PF_ADDR_RANGE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PF_POOL_TYPEMASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|PF_POOL_STICKYADDR
value|0x20
end_define

begin_define
define|#
directive|define
name|PF_WSCALE_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|PF_WSCALE_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|PF_LOG
value|0x01
end_define

begin_define
define|#
directive|define
name|PF_LOG_ALL
value|0x02
end_define

begin_define
define|#
directive|define
name|PF_LOG_SOCKET_LOOKUP
value|0x04
end_define

begin_comment
comment|/* Reasons code for passing/dropping a packet */
end_comment

begin_define
define|#
directive|define
name|PFRES_MATCH
value|0
end_define

begin_comment
comment|/* Explicit match of a rule */
end_comment

begin_define
define|#
directive|define
name|PFRES_BADOFF
value|1
end_define

begin_comment
comment|/* Bad offset for pull_hdr */
end_comment

begin_define
define|#
directive|define
name|PFRES_FRAG
value|2
end_define

begin_comment
comment|/* Dropping following fragment */
end_comment

begin_define
define|#
directive|define
name|PFRES_SHORT
value|3
end_define

begin_comment
comment|/* Dropping short packet */
end_comment

begin_define
define|#
directive|define
name|PFRES_NORM
value|4
end_define

begin_comment
comment|/* Dropping by normalizer */
end_comment

begin_define
define|#
directive|define
name|PFRES_MEMORY
value|5
end_define

begin_comment
comment|/* Dropped due to lacking mem */
end_comment

begin_define
define|#
directive|define
name|PFRES_TS
value|6
end_define

begin_comment
comment|/* Bad TCP Timestamp (RFC1323) */
end_comment

begin_define
define|#
directive|define
name|PFRES_CONGEST
value|7
end_define

begin_comment
comment|/* Congestion (of ipintrq) */
end_comment

begin_define
define|#
directive|define
name|PFRES_IPOPTIONS
value|8
end_define

begin_comment
comment|/* IP option */
end_comment

begin_define
define|#
directive|define
name|PFRES_PROTCKSUM
value|9
end_define

begin_comment
comment|/* Protocol checksum invalid */
end_comment

begin_define
define|#
directive|define
name|PFRES_BADSTATE
value|10
end_define

begin_comment
comment|/* State mismatch */
end_comment

begin_define
define|#
directive|define
name|PFRES_STATEINS
value|11
end_define

begin_comment
comment|/* State insertion failure */
end_comment

begin_define
define|#
directive|define
name|PFRES_MAXSTATES
value|12
end_define

begin_comment
comment|/* State limit */
end_comment

begin_define
define|#
directive|define
name|PFRES_SRCLIMIT
value|13
end_define

begin_comment
comment|/* Source node/conn limit */
end_comment

begin_define
define|#
directive|define
name|PFRES_SYNPROXY
value|14
end_define

begin_comment
comment|/* SYN proxy */
end_comment

begin_define
define|#
directive|define
name|PFRES_MAX
value|15
end_define

begin_comment
comment|/* total+1 */
end_comment

begin_define
define|#
directive|define
name|PFRES_NAMES
value|{ \ 	"match", \ 	"bad-offset", \ 	"fragment", \ 	"short", \ 	"normalize", \ 	"memory", \ 	"bad-timestamp", \ 	"congestion", \ 	"ip-option", \ 	"proto-cksum", \ 	"state-mismatch", \ 	"state-insert", \ 	"state-limit", \ 	"src-limit", \ 	"synproxy", \ 	NULL \ }
end_define

begin_comment
comment|/* Counters for other things we want to keep track of */
end_comment

begin_define
define|#
directive|define
name|LCNT_STATES
value|0
end_define

begin_comment
comment|/* states */
end_comment

begin_define
define|#
directive|define
name|LCNT_SRCSTATES
value|1
end_define

begin_comment
comment|/* max-src-states */
end_comment

begin_define
define|#
directive|define
name|LCNT_SRCNODES
value|2
end_define

begin_comment
comment|/* max-src-nodes */
end_comment

begin_define
define|#
directive|define
name|LCNT_SRCCONN
value|3
end_define

begin_comment
comment|/* max-src-conn */
end_comment

begin_define
define|#
directive|define
name|LCNT_SRCCONNRATE
value|4
end_define

begin_comment
comment|/* max-src-conn-rate */
end_comment

begin_define
define|#
directive|define
name|LCNT_OVERLOAD_TABLE
value|5
end_define

begin_comment
comment|/* entry added to overload table */
end_comment

begin_define
define|#
directive|define
name|LCNT_OVERLOAD_FLUSH
value|6
end_define

begin_comment
comment|/* state entries flushed */
end_comment

begin_define
define|#
directive|define
name|LCNT_MAX
value|7
end_define

begin_comment
comment|/* total+1 */
end_comment

begin_define
define|#
directive|define
name|LCNT_NAMES
value|{ \ 	"max states per rule", \ 	"max-src-states", \ 	"max-src-nodes", \ 	"max-src-conn", \ 	"max-src-conn-rate", \ 	"overload table insertion", \ 	"overload flush states", \ 	NULL \ }
end_define

begin_comment
comment|/* state operation counters */
end_comment

begin_define
define|#
directive|define
name|FCNT_STATE_SEARCH
value|0
end_define

begin_define
define|#
directive|define
name|FCNT_STATE_INSERT
value|1
end_define

begin_define
define|#
directive|define
name|FCNT_STATE_REMOVALS
value|2
end_define

begin_define
define|#
directive|define
name|FCNT_MAX
value|3
end_define

begin_comment
comment|/* src_node operation counters */
end_comment

begin_define
define|#
directive|define
name|SCNT_SRC_NODE_SEARCH
value|0
end_define

begin_define
define|#
directive|define
name|SCNT_SRC_NODE_INSERT
value|1
end_define

begin_define
define|#
directive|define
name|SCNT_SRC_NODE_REMOVALS
value|2
end_define

begin_define
define|#
directive|define
name|SCNT_MAX
value|3
end_define

begin_define
define|#
directive|define
name|PF_TABLE_NAME_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|PF_QNAME_SIZE
value|64
end_define

begin_struct
struct|struct
name|pf_status
block|{
name|uint64_t
name|counters
index|[
name|PFRES_MAX
index|]
decl_stmt|;
name|uint64_t
name|lcounters
index|[
name|LCNT_MAX
index|]
decl_stmt|;
name|uint64_t
name|fcounters
index|[
name|FCNT_MAX
index|]
decl_stmt|;
name|uint64_t
name|scounters
index|[
name|SCNT_MAX
index|]
decl_stmt|;
name|uint64_t
name|pcounters
index|[
literal|2
index|]
index|[
literal|2
index|]
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|bcounters
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|running
decl_stmt|;
name|uint32_t
name|states
decl_stmt|;
name|uint32_t
name|src_nodes
decl_stmt|;
name|uint32_t
name|since
decl_stmt|;
name|uint32_t
name|debug
decl_stmt|;
name|uint32_t
name|hostid
decl_stmt|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|uint8_t
name|pf_chksum
index|[
name|PF_MD5_DIGEST_LENGTH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PF_H_ */
end_comment

end_unit

