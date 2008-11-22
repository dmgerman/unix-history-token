begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2005, Gleb Smirnoff<glebius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NG_NAT_NODE_TYPE
value|"nat"
end_define

begin_define
define|#
directive|define
name|NGM_NAT_COOKIE
value|1107718711
end_define

begin_define
define|#
directive|define
name|NG_NAT_HOOK_IN
value|"in"
end_define

begin_define
define|#
directive|define
name|NG_NAT_HOOK_OUT
value|"out"
end_define

begin_comment
comment|/* Arguments for NGM_NAT_SET_MODE message */
end_comment

begin_struct
struct|struct
name|ng_nat_mode
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|mask
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
name|NG_NAT_MODE_INFO
value|{				\ 	  { "flags",&ng_parse_uint32_type	},	\ 	  { "mask",&ng_parse_uint32_type	},	\ 	  { NULL }					\ }
end_define

begin_define
define|#
directive|define
name|NG_NAT_LOG
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_NAT_DENY_INCOMING
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_NAT_SAME_PORTS
value|0x04
end_define

begin_define
define|#
directive|define
name|NG_NAT_UNREGISTERED_ONLY
value|0x10
end_define

begin_define
define|#
directive|define
name|NG_NAT_RESET_ON_ADDR_CHANGE
value|0x20
end_define

begin_define
define|#
directive|define
name|NG_NAT_PROXY_ONLY
value|0x40
end_define

begin_define
define|#
directive|define
name|NG_NAT_REVERSE
value|0x80
end_define

begin_define
define|#
directive|define
name|NG_NAT_DESC_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|NG_NAT_REDIRPROTO_ADDR
value|(IPPROTO_MAX + 3)
end_define

begin_comment
comment|/* LibAlias' LINK_ADDR, also unused in in.h */
end_comment

begin_comment
comment|/* Arguments for NGM_NAT_REDIRECT_PORT message */
end_comment

begin_struct
struct|struct
name|ng_nat_redirect_port
block|{
name|struct
name|in_addr
name|local_addr
decl_stmt|;
name|struct
name|in_addr
name|alias_addr
decl_stmt|;
name|struct
name|in_addr
name|remote_addr
decl_stmt|;
name|uint16_t
name|local_port
decl_stmt|;
name|uint16_t
name|alias_port
decl_stmt|;
name|uint16_t
name|remote_port
decl_stmt|;
name|uint8_t
name|proto
decl_stmt|;
name|char
name|description
index|[
name|NG_NAT_DESC_LENGTH
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
name|NG_NAT_REDIRECT_PORT_TYPE_INFO
parameter_list|(
name|desctype
parameter_list|)
value|{		\ 	  { "local_addr",&ng_parse_ipaddr_type	},	\ 	  { "alias_addr",&ng_parse_ipaddr_type	},	\ 	  { "remote_addr",&ng_parse_ipaddr_type	},	\ 	  { "local_port",&ng_parse_uint16_type	},	\ 	  { "alias_port",&ng_parse_uint16_type	},	\ 	  { "remote_port",&ng_parse_uint16_type	},	\ 	  { "proto",&ng_parse_uint8_type	},	\ 	  { "description",	(desctype)		},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Arguments for NGM_NAT_REDIRECT_ADDR message */
end_comment

begin_struct
struct|struct
name|ng_nat_redirect_addr
block|{
name|struct
name|in_addr
name|local_addr
decl_stmt|;
name|struct
name|in_addr
name|alias_addr
decl_stmt|;
name|char
name|description
index|[
name|NG_NAT_DESC_LENGTH
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
name|NG_NAT_REDIRECT_ADDR_TYPE_INFO
parameter_list|(
name|desctype
parameter_list|)
value|{		\ 	  { "local_addr",&ng_parse_ipaddr_type	},	\ 	  { "alias_addr",&ng_parse_ipaddr_type	},	\ 	  { "description",	(desctype)		},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Arguments for NGM_NAT_REDIRECT_PROTO message */
end_comment

begin_struct
struct|struct
name|ng_nat_redirect_proto
block|{
name|struct
name|in_addr
name|local_addr
decl_stmt|;
name|struct
name|in_addr
name|alias_addr
decl_stmt|;
name|struct
name|in_addr
name|remote_addr
decl_stmt|;
name|uint8_t
name|proto
decl_stmt|;
name|char
name|description
index|[
name|NG_NAT_DESC_LENGTH
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
name|NG_NAT_REDIRECT_PROTO_TYPE_INFO
parameter_list|(
name|desctype
parameter_list|)
value|{		\ 	  { "local_addr",&ng_parse_ipaddr_type	},	\ 	  { "alias_addr",&ng_parse_ipaddr_type	},	\ 	  { "remote_addr",&ng_parse_ipaddr_type	},	\ 	  { "proto",&ng_parse_uint8_type	},	\ 	  { "description",	(desctype)		},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Arguments for NGM_NAT_ADD_SERVER message */
end_comment

begin_struct
struct|struct
name|ng_nat_add_server
block|{
name|uint32_t
name|id
decl_stmt|;
name|struct
name|in_addr
name|addr
decl_stmt|;
name|uint16_t
name|port
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
name|NG_NAT_ADD_SERVER_TYPE_INFO
value|{				\ 	  { "id",&ng_parse_uint32_type	},	\ 	  { "addr",&ng_parse_ipaddr_type	},	\ 	  { "port",&ng_parse_uint16_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* List entry of array returned in NGM_NAT_LIST_REDIRECTS message */
end_comment

begin_struct
struct|struct
name|ng_nat_listrdrs_entry
block|{
name|uint32_t
name|id
decl_stmt|;
comment|/* Anything except zero */
name|struct
name|in_addr
name|local_addr
decl_stmt|;
name|struct
name|in_addr
name|alias_addr
decl_stmt|;
name|struct
name|in_addr
name|remote_addr
decl_stmt|;
name|uint16_t
name|local_port
decl_stmt|;
name|uint16_t
name|alias_port
decl_stmt|;
name|uint16_t
name|remote_port
decl_stmt|;
name|uint16_t
name|proto
decl_stmt|;
comment|/* Valid proto or NG_NAT_REDIRPROTO_ADDR */
name|uint16_t
name|lsnat
decl_stmt|;
comment|/* LSNAT servers count */
name|char
name|description
index|[
name|NG_NAT_DESC_LENGTH
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
name|NG_NAT_LISTRDRS_ENTRY_TYPE_INFO
parameter_list|(
name|desctype
parameter_list|)
value|{			\ 	  { "id",&ng_parse_uint32_type	},	\ 	  { "local_addr",&ng_parse_ipaddr_type	},	\ 	  { "alias_addr",&ng_parse_ipaddr_type	},	\ 	  { "remote_addr",&ng_parse_ipaddr_type	},	\ 	  { "local_port",&ng_parse_uint16_type	},	\ 	  { "alias_port",&ng_parse_uint16_type	},	\ 	  { "remote_port",&ng_parse_uint16_type	},	\ 	  { "proto",&ng_parse_uint16_type	},	\ 	  { "lsnat",&ng_parse_uint16_type	},	\ 	  { "description",	(desctype)		},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Structure returned by NGM_NAT_LIST_REDIRECTS */
end_comment

begin_struct
struct|struct
name|ng_nat_list_redirects
block|{
name|uint32_t
name|total_count
decl_stmt|;
name|struct
name|ng_nat_listrdrs_entry
name|redirects
index|[]
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
name|NG_NAT_LIST_REDIRECTS_TYPE_INFO
parameter_list|(
name|redirtype
parameter_list|)
value|{		\ 	  { "total_count",&ng_parse_uint32_type	},	\ 	  { "redirects",	(redirtype)		},	\ 	  { NULL }						\ }
end_define

begin_enum
enum|enum
block|{
name|NGM_NAT_SET_IPADDR
init|=
literal|1
block|,
name|NGM_NAT_SET_MODE
block|,
name|NGM_NAT_SET_TARGET
block|,
name|NGM_NAT_REDIRECT_PORT
block|,
name|NGM_NAT_REDIRECT_ADDR
block|,
name|NGM_NAT_REDIRECT_PROTO
block|,
name|NGM_NAT_REDIRECT_DYNAMIC
block|,
name|NGM_NAT_REDIRECT_DELETE
block|,
name|NGM_NAT_ADD_SERVER
block|,
name|NGM_NAT_LIST_REDIRECTS
block|,
name|NGM_NAT_PROXY_RULE
block|, }
enum|;
end_enum

end_unit

