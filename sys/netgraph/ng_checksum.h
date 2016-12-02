begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Dmitry Vagin<daemon.hammer@ya.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_CHECKSUM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_CHECKSUM_H_
end_define

begin_comment
comment|/* Node type name. */
end_comment

begin_define
define|#
directive|define
name|NG_CHECKSUM_NODE_TYPE
value|"checksum"
end_define

begin_comment
comment|/* Node type cookie. */
end_comment

begin_define
define|#
directive|define
name|NGM_CHECKSUM_COOKIE
value|439419912
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_CHECKSUM_HOOK_IN
value|"in"
end_define

begin_define
define|#
directive|define
name|NG_CHECKSUM_HOOK_OUT
value|"out"
end_define

begin_comment
comment|/* Checksum flags */
end_comment

begin_define
define|#
directive|define
name|NG_CHECKSUM_CSUM_IPV4
value|(CSUM_IP|CSUM_TCP|CSUM_UDP)
end_define

begin_define
define|#
directive|define
name|NG_CHECKSUM_CSUM_IPV6
value|(CSUM_TCP_IPV6|CSUM_UDP_IPV6)
end_define

begin_comment
comment|/* Netgraph commands understood by this node type */
end_comment

begin_enum
enum|enum
block|{
name|NGM_CHECKSUM_GETDLT
init|=
literal|1
block|,
name|NGM_CHECKSUM_SETDLT
block|,
name|NGM_CHECKSUM_GETCONFIG
block|,
name|NGM_CHECKSUM_SETCONFIG
block|,
name|NGM_CHECKSUM_GETCLR_STATS
block|,
name|NGM_CHECKSUM_GET_STATS
block|,
name|NGM_CHECKSUM_CLR_STATS
block|, }
enum|;
end_enum

begin_comment
comment|/* Parsing declarations */
end_comment

begin_define
define|#
directive|define
name|NG_CHECKSUM_CONFIG_TYPE
value|{				\ 	{ "csum_flags",&ng_parse_uint64_type	},	\ 	{ "csum_offload",&ng_parse_uint64_type	},	\ 	{ NULL }						\ }
end_define

begin_define
define|#
directive|define
name|NG_CHECKSUM_STATS_TYPE
value|{				\ 	{ "Received",&ng_parse_uint64_type	},	\ 	{ "Processed",&ng_parse_uint64_type	},	\ 	{ "Dropped",&ng_parse_uint64_type	},	\ 	{ NULL }					\ }
end_define

begin_struct
struct|struct
name|ng_checksum_config
block|{
name|uint64_t
name|csum_flags
decl_stmt|;
name|uint64_t
name|csum_offload
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ng_checksum_stats
block|{
name|uint64_t
name|received
decl_stmt|;
name|uint64_t
name|processed
decl_stmt|;
name|uint64_t
name|dropped
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ng_checksum_vlan_header
block|{
name|u_int16_t
name|tag
decl_stmt|;
name|u_int16_t
name|etype
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_CHECKSUM_H_ */
end_comment

end_unit

