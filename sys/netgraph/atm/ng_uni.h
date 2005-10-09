begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Netgraph module for UNI 4.0  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ATM_NG_UNI_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ATM_NG_UNI_H_
end_define

begin_define
define|#
directive|define
name|NG_UNI_NODE_TYPE
value|"uni"
end_define

begin_define
define|#
directive|define
name|NGM_UNI_COOKIE
value|981112392
end_define

begin_enum
enum|enum
block|{
name|NGM_UNI_GETDEBUG
block|,
comment|/* get debug flags */
name|NGM_UNI_SETDEBUG
block|,
comment|/* set debug flags */
name|NGM_UNI_GET_CONFIG
block|,
comment|/* get configuration */
name|NGM_UNI_SET_CONFIG
block|,
comment|/* set configuration */
name|NGM_UNI_ENABLE
block|,
comment|/* enable processing */
name|NGM_UNI_DISABLE
block|,
comment|/* free resources and disable */
name|NGM_UNI_GETSTATE
block|,
comment|/* retrieve coord state */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ngm_uni_debug
block|{
name|uint32_t
name|level
index|[
name|UNI_MAXFACILITY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_UNI_DEBUGLEVEL_INFO
value|{				\&ng_parse_uint32_type,					\ 	UNI_MAXFACILITY						\ }
end_define

begin_define
define|#
directive|define
name|NGM_UNI_DEBUG_INFO
define|\
value|{							\ 	  { "level",&ng_uni_debuglevel_type },		\ 	  { NULL }						\ 	}
end_define

begin_define
define|#
directive|define
name|NGM_UNI_CONFIG_INFO
define|\
value|{							\ 	  { "proto",&ng_parse_uint32_type },		\ 	  { "popt",&ng_parse_uint32_type },		\ 	  { "option",&ng_parse_uint32_type },		\ 	  { "timer301",&ng_parse_uint32_type },		\ 	  { "timer303",&ng_parse_uint32_type },		\ 	  { "init303",&ng_parse_uint32_type },		\ 	  { "timer308",&ng_parse_uint32_type },		\ 	  { "init308",&ng_parse_uint32_type },		\ 	  { "timer309",&ng_parse_uint32_type },		\ 	  { "timer310",&ng_parse_uint32_type },		\ 	  { "timer313",&ng_parse_uint32_type },		\ 	  { "timer316",&ng_parse_uint32_type },		\ 	  { "init316",&ng_parse_uint32_type },		\ 	  { "timer317",&ng_parse_uint32_type },		\ 	  { "timer322",&ng_parse_uint32_type },		\ 	  { "init322",&ng_parse_uint32_type },		\ 	  { "timer397",&ng_parse_uint32_type },		\ 	  { "timer398",&ng_parse_uint32_type },		\ 	  { "timer399",&ng_parse_uint32_type },		\ 	  { NULL }						\ 	}
end_define

begin_struct
struct|struct
name|ngm_uni_config_mask
block|{
name|uint32_t
name|mask
decl_stmt|;
name|uint32_t
name|popt_mask
decl_stmt|;
name|uint32_t
name|option_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_UNI_CONFIG_MASK_INFO
define|\
value|{							\ 	  { "mask",&ng_parse_hint32_type },	\ 	  { "popt_mask",&ng_parse_hint32_type },	\ 	  { "option_mask",&ng_parse_hint32_type },	\ 	  { NULL }						\ 	}
end_define

begin_struct
struct|struct
name|ngm_uni_set_config
block|{
name|struct
name|uni_config
name|config
decl_stmt|;
name|struct
name|ngm_uni_config_mask
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_UNI_SET_CONFIG_INFO
define|\
value|{							\ 	  { "config",&ng_uni_config_type },		\ 	  { "mask",&ng_uni_config_mask_type },	\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * API message  */
end_comment

begin_struct
struct|struct
name|uni_arg
block|{
name|uint32_t
name|sig
decl_stmt|;
name|uint32_t
name|cookie
decl_stmt|;
name|u_char
name|data
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

