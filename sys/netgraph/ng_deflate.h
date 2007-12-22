begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Alexander Motin<mav@alkar.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_DEFLATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_DEFLATE_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_DEFLATE_NODE_TYPE
value|"deflate"
end_define

begin_define
define|#
directive|define
name|NGM_DEFLATE_COOKIE
value|1166642656
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_DEFLATE_HOOK_COMP
value|"comp"
end_define

begin_comment
comment|/* compression hook */
end_comment

begin_define
define|#
directive|define
name|NG_DEFLATE_HOOK_DECOMP
value|"decomp"
end_define

begin_comment
comment|/* decompression hook */
end_comment

begin_comment
comment|/* Config struct */
end_comment

begin_struct
struct|struct
name|ng_deflate_config
block|{
name|u_char
name|enable
decl_stmt|;
comment|/* node enabled */
name|u_char
name|windowBits
decl_stmt|;
comment|/* log2(Window size) */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition. */
end_comment

begin_define
define|#
directive|define
name|NG_DEFLATE_CONFIG_INFO
value|{			\ 	{ "enable",&ng_parse_uint8_type	},	\ 	{ "windowBits",&ng_parse_uint8_type	},	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Statistics structure for one direction. */
end_comment

begin_struct
struct|struct
name|ng_deflate_stats
block|{
name|uint64_t
name|FramesPlain
decl_stmt|;
name|uint64_t
name|FramesComp
decl_stmt|;
name|uint64_t
name|FramesUncomp
decl_stmt|;
name|uint64_t
name|InOctets
decl_stmt|;
name|uint64_t
name|OutOctets
decl_stmt|;
name|uint64_t
name|Errors
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
name|NG_DEFLATE_STATS_INFO
value|{				\ 	{ "FramesPlain",&ng_parse_uint64_type	},	\ 	{ "FramesComp",&ng_parse_uint64_type	},	\ 	{ "FramesUncomp",&ng_parse_uint64_type	},	\ 	{ "InOctets",&ng_parse_uint64_type	},	\ 	{ "OutOctets",&ng_parse_uint64_type	},	\ 	{ "Errors",&ng_parse_uint64_type	},	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_DEFLATE_CONFIG
init|=
literal|1
block|,
name|NGM_DEFLATE_RESETREQ
block|,
comment|/* sent either way! */
name|NGM_DEFLATE_GET_STATS
block|,
name|NGM_DEFLATE_CLR_STATS
block|,
name|NGM_DEFLATE_GETCLR_STATS
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_DEFLATE_H_ */
end_comment

end_unit

