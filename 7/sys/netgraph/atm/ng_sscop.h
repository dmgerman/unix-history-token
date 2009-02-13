begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Netgraph module for Q.2110 SSCOP  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ATM_NG_SSCOP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ATM_NG_SSCOP_H_
end_define

begin_define
define|#
directive|define
name|NG_SSCOP_NODE_TYPE
value|"sscop"
end_define

begin_define
define|#
directive|define
name|NGM_SSCOP_COOKIE
value|980175044
end_define

begin_comment
comment|/* Netgraph control messages */
end_comment

begin_enum
enum|enum
block|{
name|NGM_SSCOP_GETPARAM
init|=
literal|1
block|,
comment|/* get parameters */
name|NGM_SSCOP_SETPARAM
block|,
comment|/* set parameters */
name|NGM_SSCOP_ENABLE
block|,
comment|/* enable processing */
name|NGM_SSCOP_DISABLE
block|,
comment|/* disable and reset */
name|NGM_SSCOP_GETDEBUG
block|,
comment|/* get debugging flags */
name|NGM_SSCOP_SETDEBUG
block|,
comment|/* set debugging flags */
name|NGM_SSCOP_GETSTATE
block|,
comment|/* get current SSCOP state */
block|}
enum|;
end_enum

begin_comment
comment|/* This must be in-sync with the definition in sscopdef.h */
end_comment

begin_define
define|#
directive|define
name|NG_SSCOP_PARAM_INFO
define|\
value|{							\ 	  { "timer_cc",&ng_parse_uint32_type },	\ 	  { "timer_poll",&ng_parse_uint32_type },	\ 	  { "timer_keep_alive",&ng_parse_uint32_type },	\ 	  { "timer_no_response",&ng_parse_uint32_type },	\ 	  { "timer_idle",&ng_parse_uint32_type },	\ 	  { "maxk",&ng_parse_uint32_type },	\ 	  { "maxj",&ng_parse_uint32_type },	\ 	  { "maxcc",&ng_parse_uint32_type },	\ 	  { "maxpd",&ng_parse_uint32_type },	\ 	  { "maxstat",&ng_parse_uint32_type },	\ 	  { "mr",&ng_parse_uint32_type },	\ 	  { "flags",&ng_parse_uint32_type },	\ 	  { NULL }						\ 	}
end_define

begin_struct
struct|struct
name|ng_sscop_setparam
block|{
name|uint32_t
name|mask
decl_stmt|;
name|struct
name|sscop_param
name|param
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_SSCOP_SETPARAM_INFO
define|\
value|{							\ 	  { "mask",&ng_parse_uint32_type },	\ 	  { "param",&ng_sscop_param_type },		\ 	  { NULL }						\ 	}
end_define

begin_struct
struct|struct
name|ng_sscop_setparam_resp
block|{
name|uint32_t
name|mask
decl_stmt|;
name|int32_t
name|error
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_SSCOP_SETPARAM_RESP_INFO
define|\
value|{							\ 	  { "mask",&ng_parse_uint32_type },	\ 	  { "error",&ng_parse_int32_type },		\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * Upper interface  */
end_comment

begin_struct
struct|struct
name|sscop_arg
block|{
name|uint32_t
name|sig
decl_stmt|;
name|uint32_t
name|arg
decl_stmt|;
comment|/* opt. sequence number or clear-buff */
name|u_char
name|data
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sscop_marg
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

begin_struct
struct|struct
name|sscop_merr
block|{
name|uint32_t
name|sig
decl_stmt|;
name|uint32_t
name|err
decl_stmt|;
comment|/* error code */
name|uint32_t
name|cnt
decl_stmt|;
comment|/* error count */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

