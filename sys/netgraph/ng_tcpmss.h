begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ng_tcpmss.h  *  * Copyright (c) 2004, Alexey Popov<lollypop@flexuser.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_TCPMSS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_TCPMSS_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_TCPMSS_NODE_TYPE
value|"tcpmss"
end_define

begin_define
define|#
directive|define
name|NGM_TCPMSS_COOKIE
value|1097623478
end_define

begin_comment
comment|/* Statistics structure for one hook. */
end_comment

begin_struct
struct|struct
name|ng_tcpmss_hookstat
block|{
name|uint64_t
name|Octets
decl_stmt|;
name|uint64_t
name|Packets
decl_stmt|;
name|uint16_t
name|maxMSS
decl_stmt|;
name|uint64_t
name|SYNPkts
decl_stmt|;
name|uint64_t
name|FixedPkts
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
name|NG_TCPMSS_HOOKSTAT_INFO
value|{			\ 	{ "Octets",&ng_parse_uint64_type	},	\ 	{ "Packets",&ng_parse_uint64_type	},	\ 	{ "maxMSS",&ng_parse_uint16_type	},	\ 	{ "SYNPkts",&ng_parse_uint64_type	},	\ 	{ "FixedPkts",&ng_parse_uint64_type	},	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Structure for NGM_TCPMSS_CONFIG. */
end_comment

begin_struct
struct|struct
name|ng_tcpmss_config
block|{
name|char
name|inHook
index|[
name|NG_HOOKSIZ
index|]
decl_stmt|;
name|char
name|outHook
index|[
name|NG_HOOKSIZ
index|]
decl_stmt|;
name|uint16_t
name|maxMSS
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
name|NG_TCPMSS_CONFIG_INFO
value|{				\ 	{ "inHook",&ng_parse_hookbuf_type	},	\ 	{ "outHook",&ng_parse_hookbuf_type	},	\ 	{ "maxMSS",&ng_parse_uint16_type	},	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_TCPMSS_GET_STATS
init|=
literal|1
block|,
comment|/* Get stats. */
name|NGM_TCPMSS_CLR_STATS
block|,
comment|/* Clear stats. */
name|NGM_TCPMSS_GETCLR_STATS
block|,
comment|/* "Atomically" get and clear stats. */
name|NGM_TCPMSS_CONFIG
comment|/* Set configuration. */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_TCPMSS_H_ */
end_comment

end_unit

