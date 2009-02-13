begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2002  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  * Copyright (c) 2003-2004  *	Hartmut Brandt  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Interface to ng_ccatm  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ATM_NG_CCATM_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ATM_NG_CCATM_H_
end_define

begin_define
define|#
directive|define
name|NG_CCATM_NODE_TYPE
value|"ccatm"
end_define

begin_define
define|#
directive|define
name|NGM_CCATM_COOKIE
value|984046139
end_define

begin_enum
enum|enum
block|{
name|NGM_CCATM_DUMP
block|,
comment|/* dump internal status */
name|NGM_CCATM_STOP
block|,
comment|/* stop all processing, close all */
name|NGM_CCATM_START
block|,
comment|/* start processing */
name|NGM_CCATM_CLEAR
block|,
comment|/* clear prefix/address table */
name|NGM_CCATM_GET_ADDRESSES
block|,
comment|/* get list of all addresses */
name|NGM_CCATM_ADDRESS_REGISTERED
block|,
comment|/* registration ok */
name|NGM_CCATM_ADDRESS_UNREGISTERED
block|,
comment|/* unregistration ok */
name|NGM_CCATM_SET_PORT_PARAM
block|,
comment|/* set port parameters */
name|NGM_CCATM_GET_PORT_PARAM
block|,
comment|/* get port parameters */
name|NGM_CCATM_GET_PORTLIST
block|,
comment|/* get list of port numbers */
name|NGM_CCATM_GETSTATE
block|,
comment|/* get port status */
name|NGM_CCATM_SETLOG
block|,
comment|/* set/get loglevel */
name|NGM_CCATM_RESET
block|,
comment|/* reset everything */
name|NGM_CCATM_GET_EXSTAT
block|,
comment|/* get extended status */
block|}
enum|;
end_enum

begin_comment
comment|/*  * This must be synchronized with unistruct.h::struct uni_addr  */
end_comment

begin_define
define|#
directive|define
name|NGM_CCATM_ADDR_ARRAY_INFO
define|\
value|{							\&ng_parse_hint8_type,					\ 	  UNI_ADDR_MAXLEN					\ 	}
end_define

begin_define
define|#
directive|define
name|NGM_CCATM_UNI_ADDR_INFO
define|\
value|{							\ 	  { "type",&ng_parse_uint32_type },		\ 	  { "plan",&ng_parse_uint32_type },		\ 	  { "len",&ng_parse_uint32_type },		\ 	  { "addr",&ng_ccatm_addr_array_type },		\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * Address request  */
end_comment

begin_struct
struct|struct
name|ngm_ccatm_addr_req
block|{
name|uint32_t
name|port
decl_stmt|;
name|struct
name|uni_addr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_CCATM_ADDR_REQ_INFO
define|\
value|{							\ 	  { "port",&ng_parse_uint32_type },		\ 	  { "addr",&ng_ccatm_uni_addr_type },		\ 	  { NULL },						\ 	}
end_define

begin_comment
comment|/*  * Get current address list  */
end_comment

begin_struct
struct|struct
name|ngm_ccatm_get_addresses
block|{
name|uint32_t
name|count
decl_stmt|;
name|struct
name|ngm_ccatm_addr_req
name|addr
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_CCATM_ADDR_REQ_ARRAY_INFO
define|\
value|{							\&ng_ccatm_addr_req_type,				\ 	  ng_ccatm_addr_req_array_getlen			\ 	}
end_define

begin_define
define|#
directive|define
name|NGM_CCATM_GET_ADDRESSES_INFO
define|\
value|{							\ 	  { "count",&ng_parse_uint32_type },		\ 	  { "addr",&ng_ccatm_addr_req_array_type },	\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * Port as parameter  */
end_comment

begin_struct
struct|struct
name|ngm_ccatm_port
block|{
name|uint32_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_CCATM_PORT_INFO
define|\
value|{							\ 	  { "port",&ng_parse_uint32_type },		\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * Port parameters.  * This must be synchronized with atmapi.h::struct atm_port_info.  */
end_comment

begin_define
define|#
directive|define
name|NGM_CCATM_ESI_INFO
define|\
value|{								\&ng_parse_hint8_type,						\ 	  6								\ 	}
end_define

begin_define
define|#
directive|define
name|NGM_CCATM_ATM_PORT_INFO
define|\
value|{								\ 	  { "port",&ng_parse_uint32_type },		\ 	  { "pcr",&ng_parse_uint32_type },		\ 	  { "max_vpi_bits",&ng_parse_uint32_type },		\ 	  { "max_vci_bits",&ng_parse_uint32_type },		\ 	  { "max_svpc_vpi",&ng_parse_uint32_type },		\ 	  { "max_svcc_vpi",&ng_parse_uint32_type },		\ 	  { "min_svcc_vci",&ng_parse_uint32_type },		\ 	  { "esi",&ng_ccatm_esi_type },			\ 	  { "num_addr",&ng_parse_uint32_type },		\ 	  { NULL }							\ 	}
end_define

begin_comment
comment|/*  * List of port numbers  */
end_comment

begin_struct
struct|struct
name|ngm_ccatm_portlist
block|{
name|uint32_t
name|nports
decl_stmt|;
name|uint32_t
name|ports
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_CCATM_PORT_ARRAY_INFO
define|\
value|{								\&ng_parse_uint32_type,					\ 	  ng_ccatm_port_array_getlen					\ 	}
end_define

begin_define
define|#
directive|define
name|NGM_CCATM_PORTLIST_INFO
define|\
value|{								\ 	  { "nports",&ng_parse_uint32_type },			\ 	  { "ports",&ng_ccatm_port_array_type },			\ 	  { NULL }							\ 	}
end_define

begin_struct
struct|struct
name|ccatm_op
block|{
name|uint32_t
name|op
decl_stmt|;
comment|/* request code */
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

