begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_bridge.h  *  * Copyright (c) 2000 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_BRIDGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_BRIDGE_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_BRIDGE_NODE_TYPE
value|"bridge"
end_define

begin_define
define|#
directive|define
name|NGM_BRIDGE_COOKIE
value|967239368
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_BRIDGE_HOOK_LINK_PREFIX
value|"link"
end_define

begin_comment
comment|/* append decimal integer */
end_comment

begin_define
define|#
directive|define
name|NG_BRIDGE_HOOK_LINK_FMT
value|"link%d"
end_define

begin_comment
comment|/* for use with printf(3) */
end_comment

begin_comment
comment|/* Maximum number of supported links */
end_comment

begin_define
define|#
directive|define
name|NG_BRIDGE_MAX_LINKS
value|32
end_define

begin_comment
comment|/* Node configuration structure */
end_comment

begin_struct
struct|struct
name|ng_bridge_config
block|{
name|u_char
name|ipfw
index|[
name|NG_BRIDGE_MAX_LINKS
index|]
decl_stmt|;
comment|/* enable ipfw */
name|u_char
name|debugLevel
decl_stmt|;
comment|/* debug level */
name|u_int32_t
name|loopTimeout
decl_stmt|;
comment|/* link loopback mute time */
name|u_int32_t
name|maxStaleness
decl_stmt|;
comment|/* max host age before nuking */
name|u_int32_t
name|minStableAge
decl_stmt|;
comment|/* min time for a stable host */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_BRIDGE_CONFIG_TYPE_INFO
parameter_list|(
name|ainfo
parameter_list|)
value|{		\ 	{							\ 	  { "ipfw",		(ainfo)			},	\ 	  { "debugLevel",&ng_parse_uint8_type	},	\ 	  { "loopTimeout",&ng_parse_uint32_type	},	\ 	  { "maxStaleness",&ng_parse_uint32_type	},	\ 	  { "minStableAge",&ng_parse_uint32_type	},	\ 	  { NULL }						\ 	}							\ }
end_define

begin_comment
comment|/* Statistics structure (one for each link) */
end_comment

begin_struct
struct|struct
name|ng_bridge_link_stats
block|{
name|u_int64_t
name|recvOctets
decl_stmt|;
comment|/* total octets rec'd on link */
name|u_int64_t
name|recvPackets
decl_stmt|;
comment|/* total pkts rec'd on link */
name|u_int64_t
name|recvMulticasts
decl_stmt|;
comment|/* multicast pkts rec'd on link */
name|u_int64_t
name|recvBroadcasts
decl_stmt|;
comment|/* broadcast pkts rec'd on link */
name|u_int64_t
name|recvUnknown
decl_stmt|;
comment|/* pkts rec'd with unknown dest addr */
name|u_int64_t
name|recvRunts
decl_stmt|;
comment|/* pkts rec'd less than 14 bytes */
name|u_int64_t
name|recvInvalid
decl_stmt|;
comment|/* pkts rec'd with bogus source addr */
name|u_int64_t
name|xmitOctets
decl_stmt|;
comment|/* total octets xmit'd on link */
name|u_int64_t
name|xmitPackets
decl_stmt|;
comment|/* total pkts xmit'd on link */
name|u_int64_t
name|xmitMulticasts
decl_stmt|;
comment|/* multicast pkts xmit'd on link */
name|u_int64_t
name|xmitBroadcasts
decl_stmt|;
comment|/* broadcast pkts xmit'd on link */
name|u_int64_t
name|loopDrops
decl_stmt|;
comment|/* pkts dropped due to loopback */
name|u_int64_t
name|loopDetects
decl_stmt|;
comment|/* number of loop detections */
name|u_int64_t
name|memoryFailures
decl_stmt|;
comment|/* times couldn't get mem or mbuf */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_BRIDGE_STATS_TYPE_INFO
value|{			\ 	{							\ 	  { "recvOctets",&ng_parse_uint64_type	},	\ 	  { "recvPackets",&ng_parse_uint64_type	},	\ 	  { "recvMulticast",&ng_parse_uint64_type	},	\ 	  { "recvBroadcast",&ng_parse_uint64_type	},	\ 	  { "recvUnknown",&ng_parse_uint64_type	},	\ 	  { "recvRunts",&ng_parse_uint64_type	},	\ 	  { "recvInvalid",&ng_parse_uint64_type	},	\ 	  { "xmitOctets",&ng_parse_uint64_type	},	\ 	  { "xmitPackets",&ng_parse_uint64_type	},	\ 	  { "xmitMulticasts",&ng_parse_uint64_type	},	\ 	  { "xmitBroadcasts",&ng_parse_uint64_type	},	\ 	  { "loopDrops",&ng_parse_uint64_type	},	\ 	  { "loopDetects",&ng_parse_uint64_type	},	\ 	  { "memoryFailures",&ng_parse_uint64_type	},	\ 	  { NULL }						\ 	}							\ }
end_define

begin_comment
comment|/* Structure describing a single host */
end_comment

begin_struct
struct|struct
name|ng_bridge_host
block|{
name|u_char
name|addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* ethernet address */
name|u_int16_t
name|linkNum
decl_stmt|;
comment|/* link where addr can be found */
name|u_int16_t
name|age
decl_stmt|;
comment|/* seconds ago entry was created */
name|u_int16_t
name|staleness
decl_stmt|;
comment|/* seconds ago host last heard from */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_BRIDGE_HOST_TYPE_INFO
parameter_list|(
name|entype
parameter_list|)
value|{		\ 	{							\ 	  { "addr",		(entype)		},	\ 	  { "linkNum",&ng_parse_uint16_type	},	\ 	  { "age",&ng_parse_uint16_type	},	\ 	  { "staleness",&ng_parse_uint16_type	},	\ 	  { NULL }						\ 	}							\ }
end_define

begin_comment
comment|/* Structure returned by NGM_BRIDGE_GET_TABLE */
end_comment

begin_struct
struct|struct
name|ng_bridge_host_ary
block|{
name|u_int32_t
name|numHosts
decl_stmt|;
name|struct
name|ng_bridge_host
name|hosts
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_BRIDGE_HOST_ARY_TYPE_INFO
parameter_list|(
name|harytype
parameter_list|)
value|{		\ 	{							\ 	  { "numHosts",&ng_parse_uint32_type	},	\ 	  { "hosts",		(harytype)		},	\ 	  { NULL }						\ 	}							\ }
end_define

begin_comment
comment|/* Netgraph control messages */
end_comment

begin_enum
enum|enum
block|{
name|NGM_BRIDGE_SET_CONFIG
init|=
literal|1
block|,
comment|/* set node configuration */
name|NGM_BRIDGE_GET_CONFIG
block|,
comment|/* get node configuration */
name|NGM_BRIDGE_RESET
block|,
comment|/* reset (forget) all information */
name|NGM_BRIDGE_GET_STATS
block|,
comment|/* get link stats */
name|NGM_BRIDGE_CLR_STATS
block|,
comment|/* clear link stats */
name|NGM_BRIDGE_GETCLR_STATS
block|,
comment|/* atomically get& clear link stats */
name|NGM_BRIDGE_GET_TABLE
block|,
comment|/* get link table */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_BRIDGE_H_ */
end_comment

end_unit

