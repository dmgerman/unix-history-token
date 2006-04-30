begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Netgraph module for ITU-T Q.2120 UNI SSCF.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ATM_NG_SSCFU_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ATM_NG_SSCFU_H_
end_define

begin_define
define|#
directive|define
name|NG_SSCFU_NODE_TYPE
value|"sscfu"
end_define

begin_define
define|#
directive|define
name|NGM_SSCFU_COOKIE
value|980517963
end_define

begin_comment
comment|/* Netgraph control messages */
end_comment

begin_enum
enum|enum
block|{
name|NGM_SSCFU_GETDEFPARAM
init|=
literal|1
block|,
comment|/* get default SSCOP parameters */
name|NGM_SSCFU_ENABLE
block|,
comment|/* enable processing */
name|NGM_SSCFU_DISABLE
block|,
comment|/* disable processing */
name|NGM_SSCFU_GETDEBUG
block|,
comment|/* get debug flags */
name|NGM_SSCFU_SETDEBUG
block|,
comment|/* set debug flags */
name|NGM_SSCFU_GETSTATE
block|,
comment|/* get current state */
block|}
enum|;
end_enum

begin_comment
comment|/* getdefparam return */
end_comment

begin_struct
struct|struct
name|ng_sscfu_getdefparam
block|{
name|struct
name|sscop_param
name|param
decl_stmt|;
name|uint32_t
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_SSCFU_GETDEFPARAM_INFO
define|\
value|{							\ 	  { "param",&ng_sscop_param_type },		\ 	  { "mask",&ng_parse_uint32_type },	\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * Upper interface  */
end_comment

begin_struct
struct|struct
name|sscfu_arg
block|{
name|uint32_t
name|sig
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

