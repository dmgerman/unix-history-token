begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_cisco.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_cisco.h,v 1.6 1999/01/25 01:21:48 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_CISCO_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_CISCO_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_CISCO_NODE_TYPE
value|"cisco"
end_define

begin_define
define|#
directive|define
name|NGM_CISCO_COOKIE
value|860707227
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_CISCO_HOOK_DOWNSTREAM
value|"downstream"
end_define

begin_define
define|#
directive|define
name|NG_CISCO_HOOK_INET
value|"inet"
end_define

begin_define
define|#
directive|define
name|NG_CISCO_HOOK_INET6
value|"inet6"
end_define

begin_define
define|#
directive|define
name|NG_CISCO_HOOK_APPLETALK
value|"atalk"
end_define

begin_define
define|#
directive|define
name|NG_CISCO_HOOK_IPX
value|"ipx"
end_define

begin_define
define|#
directive|define
name|NG_CISCO_HOOK_DEBUG
value|"debug"
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_CISCO_SET_IPADDR
init|=
literal|1
block|,
comment|/* requires a struct ng_cisco_ipaddr */
name|NGM_CISCO_GET_IPADDR
block|,
comment|/* returns a struct ng_cisco_ipaddr */
name|NGM_CISCO_GET_STATUS
block|,
comment|/* returns a struct ng_cisco_stat */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ng_cisco_ipaddr
block|{
name|struct
name|in_addr
name|ipaddr
decl_stmt|;
comment|/* IP address */
name|struct
name|in_addr
name|netmask
decl_stmt|;
comment|/* Netmask */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_CISCO_IPADDR_TYPE_INFO
value|{			\ 	{							\ 	  { "ipaddr",&ng_parse_ipaddr_type	},	\ 	  { "netmask",&ng_parse_ipaddr_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_struct
struct|struct
name|ng_cisco_stats
block|{
name|u_int32_t
name|seqRetries
decl_stmt|;
comment|/* # unack'd retries */
name|u_int32_t
name|keepAlivePeriod
decl_stmt|;
comment|/* in seconds */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_CISCO_STATS_TYPE_INFO
value|{			\ 	{							\ 	  { "seqRetries",&ng_parse_uint32_type	},	\ 	  { "keepAlivePeriod",&ng_parse_uint32_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_CISCO_H_ */
end_comment

end_unit

