begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_async.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_async.h,v 1.5 1999/01/25 01:17:14 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ASYNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ASYNC_H_
end_define

begin_comment
comment|/* Type name and cookie */
end_comment

begin_define
define|#
directive|define
name|NG_ASYNC_NODE_TYPE
value|"async"
end_define

begin_define
define|#
directive|define
name|NGM_ASYNC_COOKIE
value|886473717
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_ASYNC_HOOK_SYNC
value|"sync"
end_define

begin_comment
comment|/* Sync frames */
end_comment

begin_define
define|#
directive|define
name|NG_ASYNC_HOOK_ASYNC
value|"async"
end_define

begin_comment
comment|/* Async-encoded frames */
end_comment

begin_comment
comment|/* Maximum receive size bounds (for both sync and async sides) */
end_comment

begin_define
define|#
directive|define
name|NG_ASYNC_MIN_MRU
value|1
end_define

begin_define
define|#
directive|define
name|NG_ASYNC_MAX_MRU
value|8192
end_define

begin_define
define|#
directive|define
name|NG_ASYNC_DEFAULT_MRU
value|1600
end_define

begin_comment
comment|/* Frame statistics */
end_comment

begin_struct
struct|struct
name|ng_async_stat
block|{
name|u_int32_t
name|syncOctets
decl_stmt|;
name|u_int32_t
name|syncFrames
decl_stmt|;
name|u_int32_t
name|syncOverflows
decl_stmt|;
name|u_int32_t
name|asyncOctets
decl_stmt|;
name|u_int32_t
name|asyncFrames
decl_stmt|;
name|u_int32_t
name|asyncRunts
decl_stmt|;
name|u_int32_t
name|asyncOverflows
decl_stmt|;
name|u_int32_t
name|asyncBadCheckSums
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
name|NG_ASYNC_STATS_TYPE_INFO
value|{			\ 	{							\ 	  { "syncOctets",&ng_parse_uint32_type	},	\ 	  { "syncFrames",&ng_parse_uint32_type	},	\ 	  { "syncOverflows",&ng_parse_uint32_type	},	\ 	  { "asyncOctets",&ng_parse_uint32_type	},	\ 	  { "asyncFrames",&ng_parse_uint32_type	},	\ 	  { "asyncRunts",&ng_parse_uint32_type	},	\ 	  { "asyncOverflows",&ng_parse_uint32_type	},	\ 	  { "asyncBadCheckSums",&ng_parse_uint32_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Configuration for this node */
end_comment

begin_struct
struct|struct
name|ng_async_cfg
block|{
name|u_char
name|enabled
decl_stmt|;
comment|/* Turn encoding on/off */
name|u_int16_t
name|amru
decl_stmt|;
comment|/* Max receive async frame length */
name|u_int16_t
name|smru
decl_stmt|;
comment|/* Max receive sync frame length */
name|u_int32_t
name|accm
decl_stmt|;
comment|/* ACCM encoding */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_ASYNC_CONFIG_TYPE_INFO
value|{			\ 	{							\ 	  { "enabled",&ng_parse_int8_type	},	\ 	  { "amru",&ng_parse_uint16_type	},	\ 	  { "smru",&ng_parse_uint16_type	},	\ 	  { "accm",&ng_parse_hint32_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_ASYNC_CMD_GET_STATS
init|=
literal|1
block|,
comment|/* returns struct ng_async_stat */
name|NGM_ASYNC_CMD_CLR_STATS
block|,
name|NGM_ASYNC_CMD_SET_CONFIG
block|,
comment|/* takes struct ng_async_cfg */
name|NGM_ASYNC_CMD_GET_CONFIG
block|,
comment|/* returns struct ng_async_cfg */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_ASYNC_H_ */
end_comment

end_unit

