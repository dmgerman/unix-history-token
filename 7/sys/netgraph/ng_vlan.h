begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 IPNET Internet Communication Company  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Ruslan Ermilov<ru@FreeBSD.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_VLAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_VLAN_H_
end_define

begin_comment
comment|/* Node type name and magic cookie. */
end_comment

begin_define
define|#
directive|define
name|NG_VLAN_NODE_TYPE
value|"vlan"
end_define

begin_define
define|#
directive|define
name|NGM_VLAN_COOKIE
value|1068486472
end_define

begin_comment
comment|/* Hook names. */
end_comment

begin_define
define|#
directive|define
name|NG_VLAN_HOOK_DOWNSTREAM
value|"downstream"
end_define

begin_define
define|#
directive|define
name|NG_VLAN_HOOK_NOMATCH
value|"nomatch"
end_define

begin_comment
comment|/* Netgraph commands. */
end_comment

begin_enum
enum|enum
block|{
name|NGM_VLAN_ADD_FILTER
init|=
literal|1
block|,
name|NGM_VLAN_DEL_FILTER
block|,
name|NGM_VLAN_GET_TABLE
block|}
enum|;
end_enum

begin_comment
comment|/* For NGM_VLAN_ADD_FILTER control message. */
end_comment

begin_struct
struct|struct
name|ng_vlan_filter
block|{
name|char
name|hook
index|[
name|NG_HOOKSIZ
index|]
decl_stmt|;
name|u_int16_t
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition.  */
end_comment

begin_define
define|#
directive|define
name|NG_VLAN_FILTER_FIELDS
value|{				\ 	{ "hook",&ng_parse_hookbuf_type  },		\ 	{ "vlan",&ng_parse_uint16_type   },		\ 	{ NULL }						\ }
end_define

begin_comment
comment|/* Structure returned by NGM_VLAN_GET_TABLE. */
end_comment

begin_struct
struct|struct
name|ng_vlan_table
block|{
name|u_int32_t
name|n
decl_stmt|;
name|struct
name|ng_vlan_filter
name|filter
index|[]
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
name|NG_VLAN_TABLE_FIELDS
value|{				\ 	{ "n",&ng_parse_uint32_type },		\ 	{ "filter",&ng_vlan_table_array_type },		\ 	{ NULL }						\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_VLAN_H_ */
end_comment

end_unit

