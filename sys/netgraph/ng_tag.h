begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Vadim Goncharov<vadimnuclight@tpu.ru>  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_TAG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_TAG_H_
end_define

begin_comment
comment|/* Node type name and magic cookie. */
end_comment

begin_define
define|#
directive|define
name|NG_TAG_NODE_TYPE
value|"tag"
end_define

begin_define
define|#
directive|define
name|NGM_TAG_COOKIE
value|1149771193
end_define

begin_comment
comment|/*  * The types of tag_cookie, tag_len and tag_id in structures below  * must be the same as corresponding members m_tag_cookie, m_tag_len  * and m_tag_id in struct m_tag (defined in<sys/mbuf.h>).  */
end_comment

begin_comment
comment|/* Tag match structure for every (input) hook. */
end_comment

begin_struct
struct|struct
name|ng_tag_hookin
block|{
name|char
name|thisHook
index|[
name|NG_HOOKSIZ
index|]
decl_stmt|;
comment|/* name of hook */
name|char
name|ifMatch
index|[
name|NG_HOOKSIZ
index|]
decl_stmt|;
comment|/* match dest hook */
name|char
name|ifNotMatch
index|[
name|NG_HOOKSIZ
index|]
decl_stmt|;
comment|/* !match dest hook */
name|uint8_t
name|strip
decl_stmt|;
comment|/* strip tag if found */
name|uint32_t
name|tag_cookie
decl_stmt|;
comment|/* ABI/Module ID */
name|uint16_t
name|tag_id
decl_stmt|;
comment|/* tag ID */
name|uint16_t
name|tag_len
decl_stmt|;
comment|/* length of data */
name|uint8_t
name|tag_data
index|[
literal|0
index|]
decl_stmt|;
comment|/* tag data */
block|}
struct|;
end_struct

begin_comment
comment|/* Tag set structure for every (output) hook. */
end_comment

begin_struct
struct|struct
name|ng_tag_hookout
block|{
name|char
name|thisHook
index|[
name|NG_HOOKSIZ
index|]
decl_stmt|;
comment|/* name of hook */
name|uint32_t
name|tag_cookie
decl_stmt|;
comment|/* ABI/Module ID */
name|uint16_t
name|tag_id
decl_stmt|;
comment|/* tag ID */
name|uint16_t
name|tag_len
decl_stmt|;
comment|/* length of data */
name|uint8_t
name|tag_data
index|[
literal|0
index|]
decl_stmt|;
comment|/* tag data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_TAG_HOOKIN_SIZE
parameter_list|(
name|taglen
parameter_list|)
define|\
value|(sizeof(struct ng_tag_hookin) + (taglen))
end_define

begin_define
define|#
directive|define
name|NG_TAG_HOOKOUT_SIZE
parameter_list|(
name|taglen
parameter_list|)
define|\
value|(sizeof(struct ng_tag_hookout) + (taglen))
end_define

begin_comment
comment|/* Keep this in sync with the above structures definitions. */
end_comment

begin_define
define|#
directive|define
name|NG_TAG_HOOKIN_TYPE_INFO
parameter_list|(
name|tdtype
parameter_list|)
value|{		\ 	  { "thisHook",&ng_parse_hookbuf_type	},	\ 	  { "ifMatch",&ng_parse_hookbuf_type	},	\ 	  { "ifNotMatch",&ng_parse_hookbuf_type	},	\ 	  { "strip",&ng_parse_uint8_type	},	\ 	  { "tag_cookie",&ng_parse_uint32_type	},	\ 	  { "tag_id",&ng_parse_uint16_type	},	\ 	  { "tag_len",&ng_parse_uint16_type	},	\ 	  { "tag_data",		(tdtype)		},	\ 	  { NULL }						\ }
end_define

begin_define
define|#
directive|define
name|NG_TAG_HOOKOUT_TYPE_INFO
parameter_list|(
name|tdtype
parameter_list|)
value|{		\ 	  { "thisHook",&ng_parse_hookbuf_type	},	\ 	  { "tag_cookie",&ng_parse_uint32_type	},	\ 	  { "tag_id",&ng_parse_uint16_type	},	\ 	  { "tag_len",&ng_parse_uint16_type	},	\ 	  { "tag_data",		(tdtype)		},	\ 	  { NULL }						\ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NG_TAG_DEBUG
end_ifdef

begin_comment
comment|/* Statistics structure for one hook. */
end_comment

begin_struct
struct|struct
name|ng_tag_hookstat
block|{
name|uint64_t
name|recvFrames
decl_stmt|;
name|uint64_t
name|recvOctets
decl_stmt|;
name|uint64_t
name|recvMatchFrames
decl_stmt|;
name|uint64_t
name|recvMatchOctets
decl_stmt|;
name|uint64_t
name|xmitFrames
decl_stmt|;
name|uint64_t
name|xmitOctets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition. */
end_comment

begin_define
define|#
directive|define
name|NG_TAG_HOOKSTAT_TYPE_INFO
value|{			\ 	  { "recvFrames",&ng_parse_uint64_type	},	\ 	  { "recvOctets",&ng_parse_uint64_type	},	\ 	  { "recvMatchFrames",&ng_parse_uint64_type	},	\ 	  { "recvMatchOctets",&ng_parse_uint64_type	},	\ 	  { "xmitFrames",&ng_parse_uint64_type	},	\ 	  { "xmitOctets",&ng_parse_uint64_type	},	\ 	  { NULL }						\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NG_TAG_DEBUG */
end_comment

begin_comment
comment|/* Netgraph commands. */
end_comment

begin_enum
enum|enum
block|{
name|NGM_TAG_SET_HOOKIN
init|=
literal|1
block|,
comment|/* supply a struct ng_tag_hookin */
name|NGM_TAG_GET_HOOKIN
block|,
comment|/* returns a struct ng_tag_hookin */
name|NGM_TAG_SET_HOOKOUT
block|,
comment|/* supply a struct ng_tag_hookout */
name|NGM_TAG_GET_HOOKOUT
block|,
comment|/* returns a struct ng_tag_hookout */
ifdef|#
directive|ifdef
name|NG_TAG_DEBUG
name|NGM_TAG_GET_STATS
block|,
comment|/* supply name as char[NG_HOOKSIZ] */
name|NGM_TAG_CLR_STATS
block|,
comment|/* supply name as char[NG_HOOKSIZ] */
name|NGM_TAG_GETCLR_STATS
block|,
comment|/* supply name as char[NG_HOOKSIZ] */
endif|#
directive|endif
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_TAG_H_ */
end_comment

end_unit

