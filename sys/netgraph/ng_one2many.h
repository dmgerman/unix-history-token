begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_one2many.h  *  * Copyright (c) 2000 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@FreeBSD.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_ONE2MANY_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_ONE2MANY_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_ONE2MANY_NODE_TYPE
value|"one2many"
end_define

begin_define
define|#
directive|define
name|NGM_ONE2MANY_COOKIE
value|971111383
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_ONE2MANY_HOOK_ONE
value|"one"
end_define

begin_define
define|#
directive|define
name|NG_ONE2MANY_HOOK_MANY_PREFIX
value|"many"
end_define

begin_comment
comment|/* append decimal integer */
end_comment

begin_define
define|#
directive|define
name|NG_ONE2MANY_HOOK_MANY_FMT
value|"many%d"
end_define

begin_comment
comment|/* for use with printf(3) */
end_comment

begin_comment
comment|/* Maximum number of supported "many" links */
end_comment

begin_define
define|#
directive|define
name|NG_ONE2MANY_MAX_LINKS
value|64
end_define

begin_comment
comment|/* Link number used to indicate the "one" hook */
end_comment

begin_define
define|#
directive|define
name|NG_ONE2MANY_ONE_LINKNUM
value|(-1)
end_define

begin_comment
comment|/* Algorithms for outgoing packet distribution (XXX only one so far) */
end_comment

begin_define
define|#
directive|define
name|NG_ONE2MANY_XMIT_ROUNDROBIN
value|1
end_define

begin_comment
comment|/* round-robin delivery */
end_comment

begin_comment
comment|/* Algorithms for detecting link failure (XXX only one so far) */
end_comment

begin_define
define|#
directive|define
name|NG_ONE2MANY_FAIL_MANUAL
value|1
end_define

begin_comment
comment|/* use enabledLinks[] array */
end_comment

begin_comment
comment|/* Node configuration structure */
end_comment

begin_struct
struct|struct
name|ng_one2many_config
block|{
name|u_int32_t
name|xmitAlg
decl_stmt|;
comment|/* how to distribute packets */
name|u_int32_t
name|failAlg
decl_stmt|;
comment|/* how to detect link failure */
name|u_char
name|enabledLinks
index|[
name|NG_ONE2MANY_MAX_LINKS
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
name|NG_ONE2MANY_CONFIG_TYPE_INFO
parameter_list|(
name|atype
parameter_list|)
value|{		\ 	{							\ 	  { "xmitAlg",&ng_parse_uint32_type	},	\ 	  { "failAlg",&ng_parse_uint32_type	},	\ 	  { "enabledLinks",	(atype)			},	\ 	  { NULL }						\ 	}							\ }
end_define

begin_comment
comment|/* Statistics structure (one for each link) */
end_comment

begin_struct
struct|struct
name|ng_one2many_link_stats
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
name|xmitOctets
decl_stmt|;
comment|/* total octets xmit'd on link */
name|u_int64_t
name|xmitPackets
decl_stmt|;
comment|/* total pkts xmit'd on link */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_ONE2MANY_LINK_STATS_TYPE_INFO
value|{		\ 	{							\ 	  { "recvOctets",&ng_parse_uint64_type	},	\ 	  { "recvPackets",&ng_parse_uint64_type	},	\ 	  { "xmitOctets",&ng_parse_uint64_type	},	\ 	  { "xmitPackets",&ng_parse_uint64_type	},	\ 	  { NULL }						\ 	}							\ }
end_define

begin_comment
comment|/* Netgraph control messages */
end_comment

begin_enum
enum|enum
block|{
name|NGM_ONE2MANY_SET_CONFIG
block|,
comment|/* set configuration */
name|NGM_ONE2MANY_GET_CONFIG
block|,
comment|/* get configuration */
name|NGM_ONE2MANY_GET_STATS
block|,
comment|/* get link stats */
name|NGM_ONE2MANY_CLR_STATS
block|,
comment|/* clear link stats */
name|NGM_ONE2MANY_GETCLR_STATS
block|,
comment|/* atomically get& clear link stats */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_ONE2MANY_H_ */
end_comment

end_unit

