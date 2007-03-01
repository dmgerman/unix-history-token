begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_source.h  */
end_comment

begin_comment
comment|/*-  * Copyright 2002 Sandvine Inc.  * All rights reserved.  *  * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Sandvine Inc.; provided,  * however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Sandvine Inc.  *    trademarks, including the mark "SANDVINE" on advertising, endorsements,  *    or otherwise except as such appears in the above copyright notice or in  *    the software.  *  * THIS SOFTWARE IS BEING PROVIDED BY SANDVINE "AS IS", AND TO THE MAXIMUM  * EXTENT PERMITTED BY LAW, SANDVINE MAKES NO REPRESENTATIONS OR WARRANTIES,  * EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE, INCLUDING WITHOUT LIMITATION,  * ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR  * PURPOSE, OR NON-INFRINGEMENT.  SANDVINE DOES NOT WARRANT, GUARANTEE, OR  * MAKE ANY REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE  * USE OF THIS SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY  * OR OTHERWISE.  IN NO EVENT SHALL SANDVINE BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF SANDVINE IS ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Author: Dave Chapeskie<dchapeskie@sandvine.com>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_SOURCE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_SOURCE_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_SOURCE_NODE_TYPE
value|"source"
end_define

begin_define
define|#
directive|define
name|NGM_SOURCE_COOKIE
value|1110646684
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_SOURCE_HOOK_INPUT
value|"input"
end_define

begin_define
define|#
directive|define
name|NG_SOURCE_HOOK_OUTPUT
value|"output"
end_define

begin_comment
comment|/* Statistics structure returned by NGM_SOURCE_GET_STATS */
end_comment

begin_struct
struct|struct
name|ng_source_stats
block|{
name|uint64_t
name|outOctets
decl_stmt|;
name|uint64_t
name|outFrames
decl_stmt|;
name|uint32_t
name|queueOctets
decl_stmt|;
name|uint32_t
name|queueFrames
decl_stmt|;
name|uint32_t
name|maxPps
decl_stmt|;
name|struct
name|timeval
name|startTime
decl_stmt|;
name|struct
name|timeval
name|endTime
decl_stmt|;
name|struct
name|timeval
name|elapsedTime
decl_stmt|;
name|struct
name|timeval
name|lastTime
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_source_timeval_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_SOURCE_STATS_TYPE_INFO
value|{			\ 	  { "outOctets",&ng_parse_uint64_type	},	\ 	  { "outFrames",&ng_parse_uint64_type	},	\ 	  { "queueOctets",&ng_parse_uint32_type	},	\ 	  { "queueFrames",&ng_parse_uint32_type	},	\ 	  { "maxPps",&ng_parse_uint32_type	},	\ 	  { "startTime",&ng_source_timeval_type },	\ 	  { "endTime",&ng_source_timeval_type },	\ 	  { "elapsedTime",&ng_source_timeval_type },	\ 	  { "lastTime",&ng_source_timeval_type },	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Packet embedding info for NGM_SOURCE_GET/SET_TIMESTAMP */
end_comment

begin_struct
struct|struct
name|ng_source_embed_info
block|{
name|uint16_t
name|offset
decl_stmt|;
comment|/* offset from ethernet header */
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|spare
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_SOURCE_EMBED_ENABLE
value|0x01
end_define

begin_comment
comment|/* enable embedding */
end_comment

begin_comment
comment|/* Keep this in sync with the above structure definition. */
end_comment

begin_define
define|#
directive|define
name|NG_SOURCE_EMBED_TYPE_INFO
value|{				\ 	{ "offset",&ng_parse_hint16_type	},	\ 	{ "flags",&ng_parse_hint8_type	},	\ 	{ NULL }						\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_SOURCE_GET_STATS
init|=
literal|1
block|,
comment|/* get stats */
name|NGM_SOURCE_CLR_STATS
block|,
comment|/* clear stats */
name|NGM_SOURCE_GETCLR_STATS
block|,
comment|/* atomically get and clear stats */
name|NGM_SOURCE_START
block|,
comment|/* start sending queued data */
name|NGM_SOURCE_STOP
block|,
comment|/* stop sending queued data */
name|NGM_SOURCE_CLR_DATA
block|,
comment|/* clear the queued data */
name|NGM_SOURCE_SETIFACE
block|,
comment|/* configure downstream iface */
name|NGM_SOURCE_SETPPS
block|,
comment|/* rate-limiting packets per second */
name|NGM_SOURCE_SET_TIMESTAMP
block|,
comment|/* embed xmit timestamp */
name|NGM_SOURCE_GET_TIMESTAMP
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_SOURCE_H_ */
end_comment

end_unit

