begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Netgraph module to connect NATM interfaces to netgraph.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_ATM_NG_ATM_H
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_ATM_NG_ATM_H
end_define

begin_define
define|#
directive|define
name|NG_ATM_NODE_TYPE
value|"atm"
end_define

begin_define
define|#
directive|define
name|NGM_ATM_COOKIE
value|960802260
end_define

begin_comment
comment|/* Netgraph control messages */
end_comment

begin_enum
enum|enum
block|{
name|NGM_ATM_GET_IFNAME
init|=
literal|1
block|,
comment|/* get the interface name */
name|NGM_ATM_GET_CONFIG
block|,
comment|/* get configuration */
name|NGM_ATM_GET_VCCS
block|,
comment|/* get a list of all active vccs */
name|NGM_ATM_CPCS_INIT
block|,
comment|/* start the channel */
name|NGM_ATM_CPCS_TERM
block|,
comment|/* stop the channel */
name|NGM_ATM_GET_VCC
block|,
comment|/* get VCC config */
name|NGM_ATM_GET_VCCID
block|,
comment|/* get VCC by VCI/VPI */
name|NGM_ATM_GET_STATS
block|,
comment|/* get global statistics */
comment|/* messages from the node */
name|NGM_ATM_CARRIER_CHANGE
init|=
literal|1000
block|,
comment|/* UNUSED: carrier changed */
name|NGM_ATM_VCC_CHANGE
block|,
comment|/* permanent VCC changed */
name|NGM_ATM_ACR_CHANGE
block|,
comment|/* ABR ACR has changed */
name|NGM_ATM_IF_CHANGE
block|,
comment|/* interface state change */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Hardware interface configuration  */
end_comment

begin_struct
struct|struct
name|ngm_atm_config
block|{
name|uint32_t
name|pcr
decl_stmt|;
comment|/* peak cell rate */
name|uint32_t
name|vpi_bits
decl_stmt|;
comment|/* number of active VPI bits */
name|uint32_t
name|vci_bits
decl_stmt|;
comment|/* number of active VCI bits */
name|uint32_t
name|max_vpcs
decl_stmt|;
comment|/* maximum number of VPCs */
name|uint32_t
name|max_vccs
decl_stmt|;
comment|/* maximum number of VCCs */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_ATM_CONFIG_INFO
define|\
value|{							\ 	  { "pcr",&ng_parse_uint32_type },		\ 	  { "vpi_bits",&ng_parse_uint32_type },		\ 	  { "vci_bits",&ng_parse_uint32_type },		\ 	  { "max_vpcs",&ng_parse_uint32_type },		\ 	  { "max_vccs",&ng_parse_uint32_type },		\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * Information about an open VCC  * See net/if_atm.h. Keep in sync.  */
end_comment

begin_define
define|#
directive|define
name|NGM_ATM_TPARAM_INFO
define|\
value|{							\ 	  { "pcr",&ng_parse_uint32_type },		\ 	  { "scr",&ng_parse_uint32_type },		\ 	  { "mbs",&ng_parse_uint32_type },		\ 	  { "mcr",&ng_parse_uint32_type },		\ 	  { "icr",&ng_parse_uint32_type },		\ 	  { "tbe",&ng_parse_uint32_type },		\ 	  { "nrm",&ng_parse_uint8_type },			\ 	  { "trm",&ng_parse_uint8_type },			\ 	  { "adtf",&ng_parse_uint16_type },		\ 	  { "rif",&ng_parse_uint8_type },			\ 	  { "rdf",&ng_parse_uint8_type },			\ 	  { "cdf",&ng_parse_uint8_type },			\ 	  { NULL }						\ 	}
end_define

begin_define
define|#
directive|define
name|NGM_ATM_VCC_INFO
define|\
value|{							\ 	  { "flags",&ng_parse_hint16_type },		\ 	  { "vpi",&ng_parse_uint16_type },		\ 	  { "vci",&ng_parse_uint16_type },		\ 	  { "rmtu",&ng_parse_uint16_type },		\ 	  { "tmtu",&ng_parse_uint16_type },		\ 	  { "aal",&ng_parse_uint8_type },			\ 	  { "traffic",&ng_parse_uint8_type },			\ 	  { "tparam",&ng_atm_tparam_type },			\ 	  { NULL }						\ 	}
end_define

begin_define
define|#
directive|define
name|NGM_ATM_VCCARRAY_INFO
define|\
value|{							\&ng_atm_vcc_type,					\ 	  ng_atm_vccarray_getlen,				\ 	  NULL							\ 	}
end_define

begin_define
define|#
directive|define
name|NGM_ATM_VCCTABLE_INFO
define|\
value|{							\ 	  { "count",&ng_parse_uint32_type },		\ 	  { "vccs",&ng_atm_vccarray_type },		\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * Structure to open a VCC.  */
end_comment

begin_struct
struct|struct
name|ngm_atm_cpcs_init
block|{
name|char
name|name
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* flags. (if_atm.h) */
name|uint16_t
name|vci
decl_stmt|;
comment|/* VCI to open */
name|uint16_t
name|vpi
decl_stmt|;
comment|/* VPI to open */
name|uint16_t
name|rmtu
decl_stmt|;
comment|/* Receive maximum CPCS size */
name|uint16_t
name|tmtu
decl_stmt|;
comment|/* Transmit maximum CPCS size */
name|uint8_t
name|aal
decl_stmt|;
comment|/* AAL type (if_atm.h) */
name|uint8_t
name|traffic
decl_stmt|;
comment|/* traffic type (if_atm.h) */
name|uint32_t
name|pcr
decl_stmt|;
comment|/* Peak cell rate */
name|uint32_t
name|scr
decl_stmt|;
comment|/* VBR: Sustainable cell rate */
name|uint32_t
name|mbs
decl_stmt|;
comment|/* VBR: Maximum burst rate */
name|uint32_t
name|mcr
decl_stmt|;
comment|/* UBR+: Minimum cell rate */
name|uint32_t
name|icr
decl_stmt|;
comment|/* ABR: Initial cell rate */
name|uint32_t
name|tbe
decl_stmt|;
comment|/* ABR: Transmit buffer exposure */
name|uint8_t
name|nrm
decl_stmt|;
comment|/* ABR: Nrm */
name|uint8_t
name|trm
decl_stmt|;
comment|/* ABR: Trm */
name|uint16_t
name|adtf
decl_stmt|;
comment|/* ABR: ADTF */
name|uint8_t
name|rif
decl_stmt|;
comment|/* ABR: RIF */
name|uint8_t
name|rdf
decl_stmt|;
comment|/* ABR: RDF */
name|uint8_t
name|cdf
decl_stmt|;
comment|/* ABR: CDF */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_ATM_CPCS_INIT_INFO
define|\
value|{							\ 	  { "name",&ng_parse_hookbuf_type },		\ 	  { "flags",&ng_parse_hint32_type },		\ 	  { "vci",&ng_parse_uint16_type },		\ 	  { "vpi",&ng_parse_uint16_type },		\ 	  { "rmtu",&ng_parse_uint16_type },		\ 	  { "tmtu",&ng_parse_uint16_type },		\ 	  { "aal",&ng_parse_uint8_type },			\ 	  { "traffic",&ng_parse_uint8_type },			\ 	  { "pcr",&ng_parse_uint32_type },		\ 	  { "scr",&ng_parse_uint32_type },		\ 	  { "mbs",&ng_parse_uint32_type },		\ 	  { "mcr",&ng_parse_uint32_type },		\ 	  { "icr",&ng_parse_uint32_type },		\ 	  { "tbe",&ng_parse_uint32_type },		\ 	  { "nrm",&ng_parse_uint8_type },			\ 	  { "trm",&ng_parse_uint8_type },			\ 	  { "adtf",&ng_parse_uint16_type },		\ 	  { "rif",&ng_parse_uint8_type },			\ 	  { "rdf",&ng_parse_uint8_type },			\ 	  { "cdf",&ng_parse_uint8_type },			\ 	  { NULL }						\ 	}
end_define

begin_comment
comment|/*  * Structure to close a VCI without disconnecting the hook  */
end_comment

begin_struct
struct|struct
name|ngm_atm_cpcs_term
block|{
name|char
name|name
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_ATM_CPCS_TERM_INFO
define|\
value|{							\ 	  { "name",&ng_parse_hookbuf_type },		\ 	  { NULL }						\ 	}
end_define

begin_struct
struct|struct
name|ngm_atm_stats
block|{
name|uint64_t
name|in_packets
decl_stmt|;
name|uint64_t
name|in_errors
decl_stmt|;
name|uint64_t
name|out_packets
decl_stmt|;
name|uint64_t
name|out_errors
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_ATM_STATS_INFO
define|\
value|{							\ 	  { "in_packets",&ng_parse_uint64_type },	\ 	  { "in_errors",&ng_parse_uint64_type },	\ 	  { "out_packets",&ng_parse_uint64_type },	\ 	  { "out_errors",&ng_parse_uint64_type },	\ 	  { NULL }						\ 	}
end_define

begin_struct
struct|struct
name|ngm_atm_if_change
block|{
name|uint32_t
name|node
decl_stmt|;
name|uint8_t
name|carrier
decl_stmt|;
name|uint8_t
name|running
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_ATM_IF_CHANGE_INFO
define|\
value|{							\ 	  { "node",&ng_parse_hint32_type },		\ 	  { "carrier",&ng_parse_uint8_type },			\ 	  { "running",&ng_parse_uint8_type },			\ 	  { NULL }						\ 	}
end_define

begin_struct
struct|struct
name|ngm_atm_vcc_change
block|{
name|uint32_t
name|node
decl_stmt|;
name|uint16_t
name|vci
decl_stmt|;
name|uint8_t
name|vpi
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_ATM_VCC_CHANGE_INFO
define|\
value|{							\ 	  { "node",&ng_parse_hint32_type },		\ 	  { "vci",&ng_parse_uint16_type },		\ 	  { "vpi",&ng_parse_uint8_type },			\ 	  { "state",&ng_parse_uint8_type },			\ 	  { NULL }						\ 	}
end_define

begin_struct
struct|struct
name|ngm_atm_acr_change
block|{
name|uint32_t
name|node
decl_stmt|;
name|uint16_t
name|vci
decl_stmt|;
name|uint8_t
name|vpi
decl_stmt|;
name|uint32_t
name|acr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGM_ATM_ACR_CHANGE_INFO
define|\
value|{							\ 	  { "node",&ng_parse_hint32_type },		\ 	  { "vci",&ng_parse_uint16_type },		\ 	  { "vpi",&ng_parse_uint8_type },			\ 	  { "acr",&ng_parse_uint32_type },		\ 	  { NULL }						\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_ATM_NG_ATM_H */
end_comment

end_unit

