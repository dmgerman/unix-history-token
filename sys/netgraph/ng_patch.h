begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Maxim Ignatenko<gelraen.ua@gmail.com>  * Copyright (c) 2015 Dmitry Vagin<daemon.hammer@ya.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_PATCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_PATCH_H_
end_define

begin_comment
comment|/* Node type name. */
end_comment

begin_define
define|#
directive|define
name|NG_PATCH_NODE_TYPE
value|"patch"
end_define

begin_comment
comment|/* Node type cookie. */
end_comment

begin_define
define|#
directive|define
name|NGM_PATCH_COOKIE
value|1262445509
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_PATCH_HOOK_IN
value|"in"
end_define

begin_define
define|#
directive|define
name|NG_PATCH_HOOK_OUT
value|"out"
end_define

begin_comment
comment|/* Checksum flags */
end_comment

begin_define
define|#
directive|define
name|NG_PATCH_CSUM_IPV4
value|(CSUM_IP|CSUM_TCP|CSUM_UDP|CSUM_SCTP)
end_define

begin_define
define|#
directive|define
name|NG_PATCH_CSUM_IPV6
value|(CSUM_TCP_IPV6|CSUM_UDP_IPV6|CSUM_SCTP_IPV6)
end_define

begin_comment
comment|/* Netgraph commands understood by this node type */
end_comment

begin_enum
enum|enum
block|{
name|NGM_PATCH_SETCONFIG
init|=
literal|1
block|,
name|NGM_PATCH_GETCONFIG
block|,
name|NGM_PATCH_GET_STATS
block|,
name|NGM_PATCH_CLR_STATS
block|,
name|NGM_PATCH_GETCLR_STATS
block|,
name|NGM_PATCH_GETDLT
block|,
name|NGM_PATCH_SETDLT
block|}
enum|;
end_enum

begin_comment
comment|/* Patching modes */
end_comment

begin_enum
enum|enum
block|{
name|NG_PATCH_MODE_SET
init|=
literal|1
block|,
name|NG_PATCH_MODE_ADD
init|=
literal|2
block|,
name|NG_PATCH_MODE_SUB
init|=
literal|3
block|,
name|NG_PATCH_MODE_MUL
init|=
literal|4
block|,
name|NG_PATCH_MODE_DIV
init|=
literal|5
block|,
name|NG_PATCH_MODE_NEG
init|=
literal|6
block|,
name|NG_PATCH_MODE_AND
init|=
literal|7
block|,
name|NG_PATCH_MODE_OR
init|=
literal|8
block|,
name|NG_PATCH_MODE_XOR
init|=
literal|9
block|,
name|NG_PATCH_MODE_SHL
init|=
literal|10
block|,
name|NG_PATCH_MODE_SHR
init|=
literal|11
block|}
enum|;
end_enum

begin_comment
comment|/* Parsing declarations */
end_comment

begin_define
define|#
directive|define
name|NG_PATCH_CONFIG_TYPE
value|{						\ 	{ "count",&ng_parse_uint32_type		},	\ 	{ "csum_flags",&ng_parse_uint64_type		},	\ 	{ "relative_offset",&ng_parse_uint32_type		},	\ 	{ "ops",&ng_patch_ops_array_type	},	\ 	{ NULL }							\ }
end_define

begin_define
define|#
directive|define
name|NG_PATCH_OP_TYPE
value|{				\ 	{ "offset",&ng_parse_uint32_type	},	\ 	{ "length",&ng_parse_uint16_type	},	\ 	{ "mode",&ng_parse_uint16_type	},	\ 	{ "value",&ng_parse_uint64_type	},	\ 	{ NULL }					\ }
end_define

begin_define
define|#
directive|define
name|NG_PATCH_STATS_TYPE
value|{				\ 	{ "Received",&ng_parse_uint64_type	},	\ 	{ "Patched",&ng_parse_uint64_type	},	\ 	{ "Dropped",&ng_parse_uint64_type	},	\ 	{ NULL }					\ }
end_define

begin_union
union|union
name|ng_patch_op_val
block|{
name|uint8_t
name|v1
decl_stmt|;
name|uint16_t
name|v2
decl_stmt|;
name|uint32_t
name|v4
decl_stmt|;
name|uint64_t
name|v8
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ng_patch_op
block|{
name|uint32_t
name|offset
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
comment|/* 1, 2, 4 or 8 (bytes) */
name|uint16_t
name|mode
decl_stmt|;
name|union
name|ng_patch_op_val
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ng_patch_config
block|{
name|uint32_t
name|count
decl_stmt|;
name|uint64_t
name|csum_flags
decl_stmt|;
name|uint32_t
name|relative_offset
decl_stmt|;
name|struct
name|ng_patch_op
name|ops
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ng_patch_stats
block|{
name|uint64_t
name|received
decl_stmt|;
name|uint64_t
name|patched
decl_stmt|;
name|uint64_t
name|dropped
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ng_patch_vlan_header
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

begin_define
define|#
directive|define
name|NG_PATCH_CONF_SIZE
parameter_list|(
name|count
parameter_list|)
value|(sizeof(struct ng_patch_config) + \ 	(count) * sizeof(struct ng_patch_op))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_PATCH_H_ */
end_comment

end_unit

