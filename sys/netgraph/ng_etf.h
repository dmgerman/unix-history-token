begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ng_etf.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, FreeBSD Incorporated   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Julian Elischer<julian@freebsd.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_ETF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_ETF_H_
end_define

begin_comment
comment|/* Node type name. This should be unique among all netgraph node types */
end_comment

begin_define
define|#
directive|define
name|NG_ETF_NODE_TYPE
value|"etf"
end_define

begin_comment
comment|/* Node type cookie. Should also be unique. This value MUST change whenever    an incompatible change is made to this header file, to insure consistency.    The de facto method for generating cookies is to take the output of the    date command: date -u +'%s' */
end_comment

begin_define
define|#
directive|define
name|NGM_ETF_COOKIE
value|983084516
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_ETF_HOOK_DOWNSTREAM
value|"downstream"
end_define

begin_define
define|#
directive|define
name|NG_ETF_HOOK_NOMATCH
value|"nomatch"
end_define

begin_comment
comment|/* Netgraph commands understood by this node type */
end_comment

begin_enum
enum|enum
block|{
name|NGM_ETF_SET_FLAG
init|=
literal|1
block|,
name|NGM_ETF_GET_STATUS
block|,
name|NGM_ETF_SET_FILTER
block|,  }
enum|;
end_enum

begin_comment
comment|/* This structure is returned by the NGM_ETF_GET_STATUS command */
end_comment

begin_struct
struct|struct
name|ng_etfstat
block|{
name|u_int32_t
name|packets_in
decl_stmt|;
comment|/* packets in from downstream */
name|u_int32_t
name|packets_out
decl_stmt|;
comment|/* packets out towards downstream */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This needs to be kept in sync with the above structure definition  */
end_comment

begin_define
define|#
directive|define
name|NG_ETF_STATS_TYPE_INFO
value|{				\ 	  { "packets_in",&ng_parse_uint32_type	},	\ 	  { "packets_out",&ng_parse_uint32_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* This structure is returned by the NGM_ETF_GET_STATUS command */
end_comment

begin_struct
struct|struct
name|ng_etffilter
block|{
name|char
name|matchhook
index|[
name|NG_HOOKSIZ
index|]
decl_stmt|;
comment|/* hook name */
name|u_int16_t
name|ethertype
decl_stmt|;
comment|/* this ethertype to this hook */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This needs to be kept in sync with the above structure definition  */
end_comment

begin_define
define|#
directive|define
name|NG_ETF_FILTER_TYPE_INFO
value|{				\           { "matchhook",&ng_parse_hookbuf_type  },	\ 	  { "ethertype",&ng_parse_uint16_type   },	\ 	  { NULL }						\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_ETF_H_ */
end_comment

end_unit

