begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_kg.h   @Description   FM KG private header */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_KG_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_KG_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Keygen defines                                             */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/* maskes */
end_comment

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_define
define|#
directive|define
name|KG_SCH_VSP_SHIFT_MASK
value|0x0003f000
end_define

begin_define
define|#
directive|define
name|KG_SCH_OM_VSPE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KG_SCH_VSP_NO_KSP_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MAX_SP_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|KG_SCH_VSP_MASK_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|KG_SCH_VSP_SHIFT
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_KnownFieldsMasks
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KG_SCH_KN_PORT_ID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_MACDST
value|0x40000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_MACSRC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_TCI1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_TCI2
value|0x08000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_ETYPE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_PPPSID
value|0x02000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_PPPID
value|0x01000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_MPLS1
value|0x00800000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_MPLS2
value|0x00400000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_MPLS_LAST
value|0x00200000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPSRC1
value|0x00100000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPDST1
value|0x00080000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_PTYPE1
value|0x00040000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPTOS_TC1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPV6FL1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPSRC2
value|0x00008000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPDST2
value|0x00004000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_PTYPE2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPTOS_TC2
value|0x00001000
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPV6FL2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_GREPTYPE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPSEC_SPI
value|0x00000200
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPSEC_NH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_IPPID
value|0x00000080
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_L4PSRC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_L4PDST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KG_SCH_KN_TFLG
value|0x00000001
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|t_GenericCodes
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KG_SCH_GEN_SHIM1
value|0x70
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_DEFAULT
value|0x10
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_PARSE_RESULT_N_FQID
value|0x20
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_START_OF_FRM
value|0x40
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_SHIM2
value|0x71
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_IP_PID_NO_V
value|0x72
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_ETH
value|0x03
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_ETH_NO_V
value|0x73
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_SNAP
value|0x04
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_SNAP_NO_V
value|0x74
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_VLAN1
value|0x05
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_VLAN1_NO_V
value|0x75
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_VLAN2
value|0x06
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_VLAN2_NO_V
value|0x76
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_ETH_TYPE
value|0x07
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_ETH_TYPE_NO_V
value|0x77
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_PPP
value|0x08
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_PPP_NO_V
value|0x78
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MPLS1
value|0x09
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MPLS2
value|0x19
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MPLS3
value|0x29
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MPLS1_NO_V
value|0x79
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MPLS_LAST
value|0x0a
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MPLS_LAST_NO_V
value|0x7a
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_IPV4
value|0x0b
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_IPV6
value|0x1b
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_L3_NO_V
value|0x7b
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_IPV4_TUNNELED
value|0x0c
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_IPV6_TUNNELED
value|0x1c
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MIN_ENCAP
value|0x2c
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_IP2_NO_V
value|0x7c
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_GRE
value|0x0d
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_GRE_NO_V
value|0x7d
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_TCP
value|0x0e
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_UDP
value|0x1e
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_IPSEC_AH
value|0x2e
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_SCTP
value|0x3e
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_DCCP
value|0x4e
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_IPSEC_ESP
value|0x6e
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_L4_NO_V
value|0x7e
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_NEXTHDR
value|0x7f
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|KG_SCH_PP_SHIFT_HIGH_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|KG_SCH_PP_SHIFT_LOW_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|KG_SCH_PP_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|KG_SCH_MODE_CCOBASE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_MAC_ADDR_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_TCI_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_ENET_TYPE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_PPP_SESSION_ID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_PPP_PROTOCOL_ID_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_MPLS_LABEL_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_IP_ADDR_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_PROTOCOL_TYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_IP_TOS_TC_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_IPV6_FLOW_LABEL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_IPSEC_SPI_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_L4_PORT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|KG_SCH_DEF_TCP_FLAG_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|KG_SCH_HASH_CONFIG_SHIFT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_HT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_SIZE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_DEF_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_NUM_SHIFT
value|16
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|NUM_OF_SW_DEFAULTS
value|3
end_define

begin_define
define|#
directive|define
name|MAX_PP_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|MAX_KG_SCH_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|MASK_FOR_GENERIC_BASE_ID
value|0x20
end_define

begin_define
define|#
directive|define
name|MAX_HASH_SHIFT
value|40
end_define

begin_define
define|#
directive|define
name|MAX_KG_SCH_FQID_BIT_OFFSET
value|31
end_define

begin_define
define|#
directive|define
name|MAX_KG_SCH_PP_BIT_OFFSET
value|15
end_define

begin_define
define|#
directive|define
name|MAX_DIST_FQID_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|GET_MASK_SEL_SHIFT
parameter_list|(
name|shift
parameter_list|,
name|i
parameter_list|)
define|\
value|switch (i) {                                        \     case (0):shift = 26;break;                      \     case (1):shift = 20;break;                      \     case (2):shift = 10;break;                      \     case (3):shift = 4;break;                       \     default:                                        \     RETURN_ERROR(MAJOR, E_INVALID_VALUE, NO_MSG);   \ }
end_define

begin_define
define|#
directive|define
name|GET_MASK_OFFSET_SHIFT
parameter_list|(
name|shift
parameter_list|,
name|i
parameter_list|)
define|\
value|switch (i) {                                        \     case (0):shift = 16;break;                      \     case (1):shift = 0;break;                       \     case (2):shift = 28;break;                      \     case (3):shift = 24;break;                      \     default:                                        \     RETURN_ERROR(MAJOR, E_INVALID_VALUE, NO_MSG);   \ }
end_define

begin_define
define|#
directive|define
name|GET_MASK_SHIFT
parameter_list|(
name|shift
parameter_list|,
name|i
parameter_list|)
define|\
value|switch (i) {                                        \     case (0):shift = 24;break;                      \     case (1):shift = 16;break;                      \     case (2):shift = 8;break;                       \     case (3):shift = 0;break;                       \     default:                                        \     RETURN_ERROR(MAJOR, E_INVALID_VALUE, NO_MSG);   \ }
end_define

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Keygen defines                                             */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|KG_DOUBLE_MEANING_REGS_OFFSET
value|0x100
end_define

begin_define
define|#
directive|define
name|NO_VALIDATION
value|0x70
end_define

begin_define
define|#
directive|define
name|KG_ACTION_REG_TO
value|1024
end_define

begin_define
define|#
directive|define
name|KG_MAX_PROFILE
value|255
end_define

begin_define
define|#
directive|define
name|SCHEME_ALWAYS_DIRECT
value|0xFFFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_KG_H */
end_comment

end_unit

