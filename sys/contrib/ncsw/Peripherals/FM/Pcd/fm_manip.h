begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_manip.h   @Description   FM PCD manip... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_MANIP_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_MANIP_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"list_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_cc.h"
end_include

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Header manipulations defines                              */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|NUM_OF_SCRATCH_POOL_BUFFERS
value|1000
end_define

begin_comment
comment|/*TODO - Change it!!*/
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|&&
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|HMAN_OC_RMV_N_OR_INSRT_INT_FRM_HDR
value|0x2e
end_define

begin_define
define|#
directive|define
name|HMAN_OC_INSRT_HDR_BY_TEMPL_N_OR_FRAG_AFTER
value|0x31
end_define

begin_define
define|#
directive|define
name|HMAN_OC_MV_INT_FRAME_HDR_FROM_FRM_TO_BUFFER_PREFFIX
value|0x2f
end_define

begin_define
define|#
directive|define
name|HMAN_OC_CAPWAP_RMV_DTLS_IF_EXIST
value|0x30
end_define

begin_define
define|#
directive|define
name|HMAN_OC_CAPWAP_REASSEMBLY
value|0x11
end_define

begin_comment
comment|/* dummy */
end_comment

begin_define
define|#
directive|define
name|HMAN_OC_CAPWAP_INDEXED_STATS
value|0x32
end_define

begin_comment
comment|/* dummy */
end_comment

begin_define
define|#
directive|define
name|HMAN_OC_CAPWAP_FRAGMENTATION
value|0x33
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HMAN_OC_CAPWAP_MANIP
value|0x2F
end_define

begin_define
define|#
directive|define
name|HMAN_OC_CAPWAP_FRAG_CHECK
value|0x2E
end_define

begin_define
define|#
directive|define
name|HMAN_OC_CAPWAP_FRAGMENTATION
value|0x33
end_define

begin_define
define|#
directive|define
name|HMAN_OC_CAPWAP_REASSEMBLY
value|0x30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(FM_CAPWAP_SUPPORT)&& (DPAA_VERSION == 10)) */
end_comment

begin_define
define|#
directive|define
name|HMAN_OC_IP_MANIP
value|0x34
end_define

begin_define
define|#
directive|define
name|HMAN_OC_IP_FRAGMENTATION
value|0x74
end_define

begin_define
define|#
directive|define
name|HMAN_OC_IP_REASSEMBLY
value|0xB4
end_define

begin_define
define|#
directive|define
name|HMAN_OC_IPSEC_MANIP
value|0xF4
end_define

begin_define
define|#
directive|define
name|HMAN_OC
value|0x35
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|&&
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|HMAN_RMV_HDR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HMAN_INSRT_INT_FRM_HDR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|UDP_CHECKSUM_FIELD_OFFSET_FROM_UDP
value|6
end_define

begin_define
define|#
directive|define
name|UDP_CHECKSUM_FIELD_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|UDP_LENGTH_FIELD_OFFSET_FROM_UDP
value|4
end_define

begin_define
define|#
directive|define
name|IPv4_DSCECN_FIELD_OFFSET_FROM_IP
value|1
end_define

begin_define
define|#
directive|define
name|IPv4_TOTALLENGTH_FIELD_OFFSET_FROM_IP
value|2
end_define

begin_define
define|#
directive|define
name|IPv4_HDRCHECKSUM_FIELD_OFFSET_FROM_IP
value|10
end_define

begin_define
define|#
directive|define
name|VLAN_TAG_FIELD_OFFSET_FROM_ETH
value|12
end_define

begin_define
define|#
directive|define
name|IPv4_ID_FIELD_OFFSET_FROM_IP
value|4
end_define

begin_define
define|#
directive|define
name|IPv6_PAYLOAD_LENGTH_OFFSET_FROM_IP
value|4
end_define

begin_define
define|#
directive|define
name|IPv6_NEXT_HEADER_OFFSET_FROM_IP
value|6
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_TABLE_SIZE
value|0x80
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_TABLE_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_RFD_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_AUTO_LEARNING_HASH_ENTRY_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_TIME_OUT_ENTRY_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_TIME_OUT_BETWEEN_FRAMES
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_HALT_ON_DUPLICATE_FRAG
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_AUTOMATIC_LEARNIN_HASH_8_WAYS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_PR_COPY
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_COMPR_OPTION_FIELD_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_INDEXED_STATS_ENTRY_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_INDEXED_STATS_CNIA
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_INDEXED_STATS_DPD
value|0x10000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(FM_CAPWAP_SUPPORT)&& (DPAA_VERSION == 10)) */
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
name|FM_PCD_MANIP_CAPWAP_DTLS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_NADEN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_CHECK_MTU_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_CHECK_NO_FRAGMENTATION
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_CHECK_CNIA
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_COMPRESS_EN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_SCRATCH_BPID
value|24
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_SG_BDID_EN
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_SG_BDID_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_FRAG_SG_BDID_SHIFT
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_TABLE_SIZE
value|0x40
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_TABLE_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_COMMON_PARAM_TABLE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_COMMON_PARAM_TABLE_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_TIME_OUT_BETWEEN_FRAMES
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_COUPLING_ENABLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_COUPLING_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_COUPLING_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_LIODN_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_LIODN_SHIFT
value|56
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_ELIODN_MASK
value|0x000003c0
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_ELIODN_SHIFT
value|38
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_COMMON_INT_BUFFER_IDX_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_COMMON_INT_BUFFER_IDX_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_REASM_TIMEOUT_THREAD_THRESH
value|1024
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_MTU_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_NO_FRAGMENTATION
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_CNIA
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_FRAG_DF_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_FRAG_SCRATCH_BPID
value|24
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_FRAG_SG_BDID_EN
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_FRAG_SG_BDID_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_FRAG_SG_BDID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_DEC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_VIPV_EN
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_ECN_EN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_DSCP_EN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_VIPL_EN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_NADEN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_IP_HDR_LEN_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_IP_HDR_LEN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_ARW_SIZE_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_ARW_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|e_FM_MANIP_IP_INDX
value|1
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_GENERIC_RMV
value|0x01
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_GENERIC_INSRT
value|0x02
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_GENERIC_REPLACE
value|0x05
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_L2_RMV
value|0x08
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_L2_INSRT
value|0x09
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_VLAN_PRI_UPDATE
value|0x0B
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_IPV4_UPDATE
value|0x0C
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_IPV6_UPDATE
value|0x10
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_TCP_UDP_UPDATE
value|0x0E
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_TCP_UDP_CHECKSUM
value|0x14
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_REPLACE_IP
value|0x12
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_RMV_TILL
value|0x15
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_UDP_INSRT
value|0x16
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_IP_INSRT
value|0x17
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_CAPWAP_RMV
value|0x18
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_CAPWAP_INSRT
value|0x18
end_define

begin_define
define|#
directive|define
name|HMCD_OPCODE_GEN_FIELD_REPLACE
value|0x19
end_define

begin_define
define|#
directive|define
name|HMCD_LAST
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HMCD_DSCP_VALUES
value|64
end_define

begin_define
define|#
directive|define
name|HMCD_BASIC_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|HMCD_PTR_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|HMCD_PARAM_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|HMCD_IPV4_ADDR_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|HMCD_IPV6_ADDR_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|HMCD_L4_HDR_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|HMCD_CAPWAP_INSRT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HMCD_INSRT_UDP_LITE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HMCD_IP_ID_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|HMCD_IP_SIZE_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|HMCD_IP_SIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HMCD_IP_LAST_PID_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|HMCD_IP_OR_QOS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HMCD_IP_L4_CS_CALC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HMCD_IP_DF_MODE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HMCD_OC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|HMCD_RMV_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HMCD_RMV_SIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HMCD_INSRT_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HMCD_INSRT_SIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HMTD_CFG_TYPE
value|0x4000
end_define

begin_define
define|#
directive|define
name|HMTD_CFG_EXT_HMCT
value|0x0080
end_define

begin_define
define|#
directive|define
name|HMTD_CFG_PRS_AFTER_HM
value|0x0040
end_define

begin_define
define|#
directive|define
name|HMTD_CFG_NEXT_AD_EN
value|0x0020
end_define

begin_define
define|#
directive|define
name|HMCD_RMV_L2_ETHERNET
value|0
end_define

begin_define
define|#
directive|define
name|HMCD_RMV_L2_STACKED_QTAGS
value|1
end_define

begin_define
define|#
directive|define
name|HMCD_RMV_L2_ETHERNET_AND_MPLS
value|2
end_define

begin_define
define|#
directive|define
name|HMCD_RMV_L2_MPLS
value|3
end_define

begin_define
define|#
directive|define
name|HMCD_RMV_L2_PPPOE
value|4
end_define

begin_define
define|#
directive|define
name|HMCD_INSRT_L2_MPLS
value|0
end_define

begin_define
define|#
directive|define
name|HMCD_INSRT_N_UPDATE_L2_MPLS
value|1
end_define

begin_define
define|#
directive|define
name|HMCD_INSRT_L2_PPPOE
value|2
end_define

begin_define
define|#
directive|define
name|HMCD_INSRT_L2_SIZE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|HMCD_L2_MODE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HMCD_VLAN_PRI_REP_MODE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HMCD_VLAN_PRI_UPDATE
value|0
end_define

begin_define
define|#
directive|define
name|HMCD_VLAN_PRI_UPDATE_DSCP_TO_VPRI
value|1
end_define

begin_define
define|#
directive|define
name|HMCD_IPV4_UPDATE_TTL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HMCD_IPV4_UPDATE_TOS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HMCD_IPV4_UPDATE_DST
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HMCD_IPV4_UPDATE_SRC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HMCD_IPV4_UPDATE_ID
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HMCD_IPV4_UPDATE_TOS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HMCD_IPV6_UPDATE_HL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HMCD_IPV6_UPDATE_TC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HMCD_IPV6_UPDATE_DST
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HMCD_IPV6_UPDATE_SRC
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HMCD_IPV6_UPDATE_TC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HMCD_TCP_UDP_UPDATE_DST
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HMCD_TCP_UDP_UPDATE_SRC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HMCD_TCP_UDP_UPDATE_SRC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HMCD_IP_REPLACE_REPLACE_IPV4
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HMCD_IP_REPLACE_REPLACE_IPV6
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HMCD_IP_REPLACE_TTL_HL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HMCD_IP_REPLACE_ID
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HMCD_IP_REPLACE_L3HDRSIZE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|HMCD_GEN_FIELD_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HMCD_GEN_FIELD_SRC_OFF_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HMCD_GEN_FIELD_DST_OFF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HMCD_GEN_FIELD_MASK_EN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HMCD_GEN_FIELD_MASK_OFF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HMCD_GEN_FIELD_MASK_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DSCP_TO_VLAN_TABLE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|MANIP_GET_HMCT_SIZE
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->tableSize)
end_define

begin_define
define|#
directive|define
name|MANIP_GET_DATA_SIZE
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->dataSize)
end_define

begin_define
define|#
directive|define
name|MANIP_GET_HMCT_PTR
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->p_Hmct)
end_define

begin_define
define|#
directive|define
name|MANIP_GET_DATA_PTR
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->p_Data)
end_define

begin_define
define|#
directive|define
name|MANIP_SET_HMCT_PTR
parameter_list|(
name|h_Manip
parameter_list|,
name|h_NewPtr
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->p_Hmct = h_NewPtr)
end_define

begin_define
define|#
directive|define
name|MANIP_SET_DATA_PTR
parameter_list|(
name|h_Manip
parameter_list|,
name|h_NewPtr
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->p_Data = h_NewPtr)
end_define

begin_define
define|#
directive|define
name|MANIP_GET_HMTD_PTR
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->h_Ad)
end_define

begin_define
define|#
directive|define
name|MANIP_DONT_REPARSE
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->dontParseAfterManip)
end_define

begin_define
define|#
directive|define
name|MANIP_SET_PREV
parameter_list|(
name|h_Manip
parameter_list|,
name|h_Prev
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->h_PrevManip = h_Prev)
end_define

begin_define
define|#
directive|define
name|MANIP_GET_OWNERS
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->owner)
end_define

begin_define
define|#
directive|define
name|MANIP_GET_TYPE
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->type)
end_define

begin_define
define|#
directive|define
name|MANIP_SET_UNIFIED_TBL_PTR_INDICATION
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->unifiedTablePtr = TRUE)
end_define

begin_define
define|#
directive|define
name|MANIP_GET_MURAM
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcd *)((t_FmPcdManip *)h_Manip)->h_FmPcd)->h_FmMuram)
end_define

begin_define
define|#
directive|define
name|MANIP_FREE_HMTD
parameter_list|(
name|h_Manip
parameter_list|)
define|\
value|{if (((t_FmPcdManip *)h_Manip)->muramAllocate)    \             FM_MURAM_FreeMem(((t_FmPcd *)((t_FmPcdManip *)h_Manip)->h_FmPcd)->h_FmMuram, ((t_FmPcdManip *)h_Manip)->h_Ad);\         else                                            \             XX_Free(((t_FmPcdManip *)h_Manip)->h_Ad);    \         ((t_FmPcdManip *)h_Manip)->h_Ad = NULL;            \         }
end_define

begin_comment
comment|/* position regarding Manip SW structure */
end_comment

begin_define
define|#
directive|define
name|MANIP_IS_FIRST
parameter_list|(
name|h_Manip
parameter_list|)
value|(!(((t_FmPcdManip *)h_Manip)->h_PrevManip))
end_define

begin_define
define|#
directive|define
name|MANIP_IS_CASCADED
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->cascaded)
end_define

begin_define
define|#
directive|define
name|MANIP_IS_UNIFIED
parameter_list|(
name|h_Manip
parameter_list|)
value|(!(((t_FmPcdManip *)h_Manip)->unifiedPosition == e_MANIP_UNIFIED_NONE))
end_define

begin_define
define|#
directive|define
name|MANIP_IS_UNIFIED_NON_FIRST
parameter_list|(
name|h_Manip
parameter_list|)
value|((((t_FmPcdManip *)h_Manip)->unifiedPosition == e_MANIP_UNIFIED_MID) || \                                                          (((t_FmPcdManip *)h_Manip)->unifiedPosition == e_MANIP_UNIFIED_LAST))
end_define

begin_define
define|#
directive|define
name|MANIP_IS_UNIFIED_NON_LAST
parameter_list|(
name|h_Manip
parameter_list|)
value|((((t_FmPcdManip *)h_Manip)->unifiedPosition == e_MANIP_UNIFIED_FIRST) ||\                                                          (((t_FmPcdManip *)h_Manip)->unifiedPosition == e_MANIP_UNIFIED_MID))
end_define

begin_define
define|#
directive|define
name|MANIP_IS_UNIFIED_FIRST
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->unifiedPosition == e_MANIP_UNIFIED_FIRST)
end_define

begin_define
define|#
directive|define
name|MANIP_IS_UNIFIED_LAST
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->unifiedPosition == e_MANIP_UNIFIED_LAST)
end_define

begin_define
define|#
directive|define
name|MANIP_UPDATE_UNIFIED_POSITION
parameter_list|(
name|h_Manip
parameter_list|)
value|(((t_FmPcdManip *)h_Manip)->unifiedPosition = \                                                          (((t_FmPcdManip *)h_Manip)->unifiedPosition == e_MANIP_UNIFIED_NONE)? \                                                             e_MANIP_UNIFIED_LAST : e_MANIP_UNIFIED_MID)
end_define

begin_typedef
typedef|typedef
enum|enum
name|e_ManipUnifiedPosition
block|{
name|e_MANIP_UNIFIED_NONE
init|=
literal|0
block|,
name|e_MANIP_UNIFIED_FIRST
block|,
name|e_MANIP_UNIFIED_MID
block|,
name|e_MANIP_UNIFIED_LAST
block|}
name|e_ManipUnifiedPosition
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|e_ManipInfo
block|{
name|e_MANIP_HMTD
block|,
name|e_MANIP_HMCT
block|,
name|e_MANIP_HANDLER_TABLE_OWNER
block|}
name|e_ManipInfo
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Memory map                                                 */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|&&
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|t_CapwapReasmPram
block|{
specifier|volatile
name|uint32_t
name|mode
decl_stmt|;
specifier|volatile
name|uint32_t
name|autoLearnHashTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|intStatsTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|reasmFrmDescPoolTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|reasmFrmDescIndexPoolTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|timeOutTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|bufferPoolIdAndRisc1SetIndexes
decl_stmt|;
specifier|volatile
name|uint32_t
name|risc23SetIndexes
decl_stmt|;
specifier|volatile
name|uint32_t
name|risc4SetIndexesAndExtendedStatsTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|extendedStatsTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|expirationDelay
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalProcessedFragCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalUnsuccessfulReasmFramesCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalDuplicatedFragCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalMalformdFragCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalTimeOutCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalSetBusyCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalRfdPoolBusyCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalDiscardedFragsCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalMoreThan16FramesCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|internalBufferBusy
decl_stmt|;
specifier|volatile
name|uint32_t
name|externalBufferBusy
decl_stmt|;
specifier|volatile
name|uint32_t
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
block|}
name|t_CapwapReasmPram
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(FM_CAPWAP_SUPPORT)&& (DPAA_VERSION == 10)) */
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_ReassTbl
block|{
specifier|volatile
name|uint16_t
name|waysNumAndSetSize
decl_stmt|;
specifier|volatile
name|uint16_t
name|autoLearnHashKeyMask
decl_stmt|;
specifier|volatile
name|uint32_t
name|reassCommonPrmTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|liodnAlAndAutoLearnHashTblPtrHi
decl_stmt|;
specifier|volatile
name|uint32_t
name|autoLearnHashTblPtrLow
decl_stmt|;
specifier|volatile
name|uint32_t
name|liodnSlAndAutoLearnSetLockTblPtrHi
decl_stmt|;
specifier|volatile
name|uint32_t
name|autoLearnSetLockTblPtrLow
decl_stmt|;
specifier|volatile
name|uint16_t
name|minFragSize
decl_stmt|;
comment|/* Not relevant for CAPWAP*/
specifier|volatile
name|uint16_t
name|maxReassemblySize
decl_stmt|;
comment|/* Only relevant for CAPWAP*/
specifier|volatile
name|uint32_t
name|totalSuccessfullyReasmFramesCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalValidFragmentCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalProcessedFragCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalMalformdFragCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalSetBusyCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalDiscardedFragsCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalMoreThan16FramesCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_ReassTbl
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_ReassCommonTbl
block|{
specifier|volatile
name|uint32_t
name|timeoutModeAndFqid
decl_stmt|;
specifier|volatile
name|uint32_t
name|reassFrmDescIndexPoolTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|liodnAndReassFrmDescPoolPtrHi
decl_stmt|;
specifier|volatile
name|uint32_t
name|reassFrmDescPoolPtrLow
decl_stmt|;
specifier|volatile
name|uint32_t
name|timeOutTblPtr
decl_stmt|;
specifier|volatile
name|uint32_t
name|expirationDelay
decl_stmt|;
specifier|volatile
name|uint32_t
name|internalBufferManagement
decl_stmt|;
specifier|volatile
name|uint32_t
name|reserved2
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalTimeOutCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalRfdPoolBusyCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalInternalBufferBusy
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalExternalBufferBusy
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalSgFragmentCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalDmaSemaphoreDepletionCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|totalNCSPCounter
decl_stmt|;
specifier|volatile
name|uint32_t
name|discardMask
decl_stmt|;
block|}
name|t_ReassCommonTbl
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_Hmtd
block|{
specifier|volatile
name|uint16_t
name|cfg
decl_stmt|;
specifier|volatile
name|uint8_t
name|eliodnOffset
decl_stmt|;
specifier|volatile
name|uint8_t
name|extHmcdBasePtrHi
decl_stmt|;
specifier|volatile
name|uint32_t
name|hmcdBasePtr
decl_stmt|;
specifier|volatile
name|uint16_t
name|nextAdIdx
decl_stmt|;
specifier|volatile
name|uint8_t
name|res1
decl_stmt|;
specifier|volatile
name|uint8_t
name|opCode
decl_stmt|;
specifier|volatile
name|uint32_t
name|res2
decl_stmt|;
block|}
name|_PackedType
name|t_Hmtd
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__MWERKS__)&& ... */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*  Driver's internal structures                                       */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|&&
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|)
end_if

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|p_AutoLearnHashTbl
decl_stmt|;
name|t_Handle
name|p_ReassmFrmDescrPoolTbl
decl_stmt|;
name|t_Handle
name|p_ReassmFrmDescrIndxPoolTbl
decl_stmt|;
name|t_Handle
name|p_TimeOutTbl
decl_stmt|;
name|uint16_t
name|maxNumFramesInProcess
decl_stmt|;
name|uint8_t
name|numOfTasks
decl_stmt|;
comment|//uint8_t  poolId;
name|uint8_t
name|prOffset
decl_stmt|;
name|uint16_t
name|dataOffset
decl_stmt|;
name|uint8_t
name|sgBpid
decl_stmt|;
name|uint8_t
name|hwPortId
decl_stmt|;
name|uint32_t
name|fqidForTimeOutFrames
decl_stmt|;
name|uint32_t
name|timeoutRoutineRequestTime
decl_stmt|;
name|uint32_t
name|bitFor1Micro
decl_stmt|;
block|}
name|t_CapwapFragParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(FM_CAPWAP_SUPPORT)&& (DPAA_VERSION == 10)) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_AdOfTypeContLookup
modifier|*
name|p_Frag
decl_stmt|;
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
name|uint8_t
name|scratchBpid
decl_stmt|;
endif|#
directive|endif
comment|/* (DPAA_VERSION == 10) */
block|}
name|t_FragParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_ReassmParams
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/* Header selection */
name|t_ReassCommonTbl
modifier|*
name|p_ReassCommonTbl
decl_stmt|;
name|uintptr_t
name|reassFrmDescrIndxPoolTblAddr
decl_stmt|;
name|uintptr_t
name|reassFrmDescrPoolTblAddr
decl_stmt|;
name|uintptr_t
name|timeOutTblAddr
decl_stmt|;
name|uintptr_t
name|internalBufferPoolManagementIndexAddr
decl_stmt|;
name|uintptr_t
name|internalBufferPoolAddr
decl_stmt|;
name|uint32_t
name|maxNumFramesInProcess
decl_stmt|;
name|uint8_t
name|sgBpid
decl_stmt|;
name|uint8_t
name|dataMemId
decl_stmt|;
name|uint16_t
name|dataLiodnOffset
decl_stmt|;
name|uint32_t
name|fqidForTimeOutFrames
decl_stmt|;
name|e_FmPcdManipReassemTimeOutMode
name|timeOutMode
decl_stmt|;
name|uint32_t
name|timeoutThresholdForReassmProcess
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|t_Handle
name|h_Ipv4Ad
decl_stmt|;
name|t_Handle
name|h_Ipv6Ad
decl_stmt|;
name|bool
name|ipv6Assigned
decl_stmt|;
name|t_ReassTbl
modifier|*
name|p_Ipv4ReassTbl
decl_stmt|;
name|t_ReassTbl
modifier|*
name|p_Ipv6ReassTbl
decl_stmt|;
name|uintptr_t
name|ipv4AutoLearnHashTblAddr
decl_stmt|;
name|uintptr_t
name|ipv6AutoLearnHashTblAddr
decl_stmt|;
name|uintptr_t
name|ipv4AutoLearnSetLockTblAddr
decl_stmt|;
name|uintptr_t
name|ipv6AutoLearnSetLockTblAddr
decl_stmt|;
name|uint16_t
name|minFragSize
index|[
literal|2
index|]
decl_stmt|;
name|e_FmPcdManipReassemWaysNumber
name|numOfFramesPerHashEntry
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|relativeSchemeId
index|[
literal|2
index|]
decl_stmt|;
name|t_Handle
name|h_Ipv4Scheme
decl_stmt|;
name|t_Handle
name|h_Ipv6Scheme
decl_stmt|;
name|uint32_t
name|nonConsistentSpFqid
decl_stmt|;
block|}
name|ip
struct|;
struct|struct
block|{
name|t_Handle
name|h_Ad
decl_stmt|;
name|t_ReassTbl
modifier|*
name|p_ReassTbl
decl_stmt|;
name|uintptr_t
name|autoLearnHashTblAddr
decl_stmt|;
name|uintptr_t
name|autoLearnSetLockTblAddr
decl_stmt|;
name|uint16_t
name|maxRessembledsSize
decl_stmt|;
name|e_FmPcdManipReassemWaysNumber
name|numOfFramesPerHashEntry
decl_stmt|;
name|uint8_t
name|relativeSchemeId
decl_stmt|;
name|t_Handle
name|h_Scheme
decl_stmt|;
block|}
name|capwap
struct|;
block|}
union|;
block|}
name|t_ReassmParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|e_FmPcdManipType
name|type
decl_stmt|;
name|t_FmPcdManipParams
name|manipParams
decl_stmt|;
name|bool
name|muramAllocate
decl_stmt|;
name|t_Handle
name|h_Ad
decl_stmt|;
name|uint32_t
name|opcode
decl_stmt|;
name|bool
name|rmv
decl_stmt|;
name|bool
name|insrt
decl_stmt|;
name|t_Handle
name|h_NextManip
decl_stmt|;
name|t_Handle
name|h_PrevManip
decl_stmt|;
name|e_FmPcdManipType
name|nextManipType
decl_stmt|;
comment|/* HdrManip parameters*/
name|uint8_t
modifier|*
name|p_Hmct
decl_stmt|;
name|uint8_t
modifier|*
name|p_Data
decl_stmt|;
name|bool
name|dontParseAfterManip
decl_stmt|;
name|bool
name|fieldUpdate
decl_stmt|;
name|bool
name|custom
decl_stmt|;
name|uint16_t
name|tableSize
decl_stmt|;
name|uint8_t
name|dataSize
decl_stmt|;
name|bool
name|cascaded
decl_stmt|;
name|e_ManipUnifiedPosition
name|unifiedPosition
decl_stmt|;
comment|/* end HdrManip */
name|uint8_t
modifier|*
name|p_Template
decl_stmt|;
name|uint16_t
name|owner
decl_stmt|;
name|uint32_t
name|updateParams
decl_stmt|;
name|uint32_t
name|shadowUpdateParams
decl_stmt|;
name|bool
name|frag
decl_stmt|;
name|bool
name|reassm
decl_stmt|;
name|uint16_t
name|sizeForFragmentation
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|&&
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|)
name|t_Handle
name|h_Frag
decl_stmt|;
name|t_CapwapFragParams
name|capwapFragParams
decl_stmt|;
endif|#
directive|endif
comment|/* (defined(FM_CAPWAP_SUPPORT)&& (DPAA_VERSION == 10)) */
union|union
block|{
name|t_ReassmParams
name|reassmParams
decl_stmt|;
name|t_FragParams
name|fragParams
decl_stmt|;
block|}
union|;
name|uint8_t
name|icOffset
decl_stmt|;
name|uint16_t
name|ownerTmp
decl_stmt|;
name|bool
name|cnia
decl_stmt|;
name|t_Handle
name|p_StatsTbl
decl_stmt|;
name|t_Handle
name|h_FmPcd
decl_stmt|;
name|t_List
name|nodesLst
decl_stmt|;
name|t_Handle
name|h_Spinlock
decl_stmt|;
block|}
name|t_FmPcdManip
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcSavedManipParams
block|{
union|union
block|{
struct|struct
block|{
name|uint16_t
name|dataOffset
decl_stmt|;
comment|//uint8_t     poolId;
block|}
name|capwapParams
struct|;
struct|struct
block|{
name|uint16_t
name|dataOffset
decl_stmt|;
name|uint8_t
name|poolId
decl_stmt|;
block|}
name|ipParams
struct|;
block|}
union|;
block|}
name|t_FmPcdCcSavedManipParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_MANIP_H */
end_comment

end_unit

