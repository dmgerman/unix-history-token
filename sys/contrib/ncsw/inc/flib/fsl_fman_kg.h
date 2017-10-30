begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_KG_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_KG_H
end_define

begin_include
include|#
directive|include
file|"common/general.h"
end_include

begin_define
define|#
directive|define
name|FM_KG_NUM_OF_GENERIC_REGS
value|8
end_define

begin_comment
comment|/**< Num of generic KeyGen regs */
end_comment

begin_define
define|#
directive|define
name|FMAN_MAX_NUM_OF_HW_PORTS
value|64
end_define

begin_comment
comment|/**< Total num of masks allowed on KG extractions */
end_comment

begin_define
define|#
directive|define
name|FM_KG_EXTRACT_MASKS_NUM
value|4
end_define

begin_define
define|#
directive|define
name|FM_KG_NUM_CLS_PLAN_ENTR
value|8
end_define

begin_comment
comment|/**< Num of class. plan regs */
end_comment

begin_define
define|#
directive|define
name|FM_KG_CLS_PLAN_GRPS_NUM
value|32
end_define

begin_comment
comment|/**< Max num of class. groups */
end_comment

begin_struct
struct|struct
name|fman_kg_regs
block|{
name|uint32_t
name|fmkg_gcr
decl_stmt|;
name|uint32_t
name|res004
decl_stmt|;
name|uint32_t
name|res008
decl_stmt|;
name|uint32_t
name|fmkg_eer
decl_stmt|;
name|uint32_t
name|fmkg_eeer
decl_stmt|;
name|uint32_t
name|res014
decl_stmt|;
name|uint32_t
name|res018
decl_stmt|;
name|uint32_t
name|fmkg_seer
decl_stmt|;
name|uint32_t
name|fmkg_seeer
decl_stmt|;
name|uint32_t
name|fmkg_gsr
decl_stmt|;
name|uint32_t
name|fmkg_tpc
decl_stmt|;
name|uint32_t
name|fmkg_serc
decl_stmt|;
name|uint32_t
name|res030
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|fmkg_fdor
decl_stmt|;
name|uint32_t
name|fmkg_gdv0r
decl_stmt|;
name|uint32_t
name|fmkg_gdv1r
decl_stmt|;
name|uint32_t
name|res04c
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|fmkg_feer
decl_stmt|;
name|uint32_t
name|res068
index|[
literal|38
index|]
decl_stmt|;
name|uint32_t
name|fmkg_indirect
index|[
literal|63
index|]
decl_stmt|;
name|uint32_t
name|fmkg_ar
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_scheme_regs
block|{
name|uint32_t
name|kgse_mode
decl_stmt|;
comment|/**< MODE */
name|uint32_t
name|kgse_ekfc
decl_stmt|;
comment|/**< Extract Known Fields Command */
name|uint32_t
name|kgse_ekdv
decl_stmt|;
comment|/**< Extract Known Default Value */
name|uint32_t
name|kgse_bmch
decl_stmt|;
comment|/**< Bit Mask Command High */
name|uint32_t
name|kgse_bmcl
decl_stmt|;
comment|/**< Bit Mask Command Low */
name|uint32_t
name|kgse_fqb
decl_stmt|;
comment|/**< Frame Queue Base */
name|uint32_t
name|kgse_hc
decl_stmt|;
comment|/**< Hash Command */
name|uint32_t
name|kgse_ppc
decl_stmt|;
comment|/**< Policer Profile Command */
name|uint32_t
name|kgse_gec
index|[
name|FM_KG_NUM_OF_GENERIC_REGS
index|]
decl_stmt|;
comment|/**< Generic Extract Command */
name|uint32_t
name|kgse_spc
decl_stmt|;
comment|/**< KeyGen Scheme Entry Statistic Packet Counter */
name|uint32_t
name|kgse_dv0
decl_stmt|;
comment|/**< KeyGen Scheme Entry Default Value 0 */
name|uint32_t
name|kgse_dv1
decl_stmt|;
comment|/**< KeyGen Scheme Entry Default Value 1 */
name|uint32_t
name|kgse_ccbs
decl_stmt|;
comment|/**< KeyGen Scheme Entry Coarse Classification Bit*/
name|uint32_t
name|kgse_mv
decl_stmt|;
comment|/**< KeyGen Scheme Entry Match vector */
name|uint32_t
name|kgse_om
decl_stmt|;
comment|/**< KeyGen Scheme Entry Operation Mode bits */
name|uint32_t
name|kgse_vsp
decl_stmt|;
comment|/**< KeyGen Scheme Entry Virtual Storage Profile */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_pe_regs
block|{
name|uint32_t
name|fmkg_pe_sp
decl_stmt|;
name|uint32_t
name|fmkg_pe_cpp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_cp_regs
block|{
name|uint32_t
name|kgcpe
index|[
name|FM_KG_NUM_CLS_PLAN_ENTR
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FM_KG_KGAR_GO
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_KG_KGAR_READ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_KG_KGAR_WRITE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FM_KG_KGAR_SEL_SCHEME_ENTRY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FM_KG_KGAR_SCM_WSEL_UPDATE_CNT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|KG_SCH_PP_SHIFT_HIGH
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_PP_NO_GEN
value|0x10000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_PP_SHIFT_LOW
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|KG_SCH_MODE_NIA_PLCR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_EXTRACT_TYPE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|KG_SCH_BITMASK_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_ERR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_SEL_CLS_PLAN_ENTRY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_SEL_PORT_ENTRY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_SEL_PORT_WSEL_SP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_SEL_PORT_WSEL_CPP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_WSEL_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|KG_SCH_HASH_CONFIG_NO_FQID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_HASH_CONFIG_SYM
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_EX_KG_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_EX_KG_KEYSIZE_OVERFLOW
value|0x40000000
end_define

begin_comment
comment|/* ECC capture register */
end_comment

begin_define
define|#
directive|define
name|KG_FMKG_SERC_CAP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KG_FMKG_SERC_CET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|KG_FMKG_SERC_CNT_MSK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|KG_FMKG_SERC_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|KG_FMKG_SERC_ADDR_MSK
value|0x000003FF
end_define

begin_comment
comment|/* Masks */
end_comment

begin_define
define|#
directive|define
name|FM_KG_KGGCR_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KG_SCH_GEN_EXTRACT_TYPE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|KG_ERR_TYPE_DOUBLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|KG_ERR_ADDR_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|KG_SCH_MODE_EN
value|0x80000000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|FM_KG_KGAR_NUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_KG_PE_CPP_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_KG_KGAR_WSEL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FM_KG_SCH_GEN_HT_INVALID
value|0
end_define

begin_define
define|#
directive|define
name|FM_KG_MASK_SEL_GEN_BASE
value|0x20
end_define

begin_define
define|#
directive|define
name|KG_GET_MASK_SEL_SHIFT
parameter_list|(
name|shift
parameter_list|,
name|i
parameter_list|)
define|\
value|switch (i)				\ {					\ 	case 0: (shift) = 26; break;	\ 	case 1: (shift) = 20; break;	\ 	case 2: (shift) = 10; break;	\ 	case 3: (shift) = 4; break;	\ 	default: (shift) = 0;		\ }
end_define

begin_define
define|#
directive|define
name|KG_GET_MASK_OFFSET_SHIFT
parameter_list|(
name|shift
parameter_list|,
name|i
parameter_list|)
define|\
value|switch (i)				\ {					\ 	case 0: (shift) = 16; break;	\ 	case 1: (shift) = 0; break;	\ 	case 2: (shift) = 28; break;	\ 	case 3: (shift) = 24; break;	\ 	default: (shift) = 0;		\ }
end_define

begin_define
define|#
directive|define
name|KG_GET_MASK_SHIFT
parameter_list|(
name|shift
parameter_list|,
name|i
parameter_list|)
define|\
value|switch (i)				\ {					\ 	case 0: shift = 24; break;	\ 	case 1: shift = 16; break;	\ 	case 2: shift = 8;  break;	\ 	case 3: shift = 0;  break;	\ 	default: shift = 0;		\ }
end_define

begin_comment
comment|/* Port entry CPP register */
end_comment

begin_define
define|#
directive|define
name|FMAN_KG_PE_CPP_MASK_SHIFT
value|16
end_define

begin_comment
comment|/* Scheme registers */
end_comment

begin_define
define|#
directive|define
name|FMAN_KG_SCH_MODE_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_MODE_NIA_PLCR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_MODE_CCOBASE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_MAC_ADDR_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_VLAN_TCI_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_ETYPE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_PPP_SID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_PPP_PID_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_MPLS_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_IP_ADDR_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_PTYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_IP_TOS_TC_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_IPv6_FL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_IPSEC_SPI_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_L4_PORT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_DEF_TCP_FLG_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_GEN_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_GEN_SIZE_MAX
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_GEN_OR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_GEN_DEF_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_GEN_SIZE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_GEN_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_GEN_HT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_HASH_HSHIFT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_HASH_HSHIFT_MAX
value|0x28
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_HASH_SYM
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_HASH_NO_FQID_GEN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_PP_SH_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_PP_SL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_PP_SH_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_PP_SL_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_PP_SHIFT_MAX
value|0x17
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_PP_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FMAN_KG_SCH_PP_NO_GEN
value|0x10000000
end_define

begin_enum
enum|enum
name|fman_kg_gen_extract_src
block|{
name|E_FMAN_KG_GEN_EXTRACT_ETH
block|,
name|E_FMAN_KG_GEN_EXTRACT_ETYPE
block|,
name|E_FMAN_KG_GEN_EXTRACT_SNAP
block|,
name|E_FMAN_KG_GEN_EXTRACT_VLAN_TCI_1
block|,
name|E_FMAN_KG_GEN_EXTRACT_VLAN_TCI_N
block|,
name|E_FMAN_KG_GEN_EXTRACT_PPPoE
block|,
name|E_FMAN_KG_GEN_EXTRACT_MPLS_1
block|,
name|E_FMAN_KG_GEN_EXTRACT_MPLS_2
block|,
name|E_FMAN_KG_GEN_EXTRACT_MPLS_3
block|,
name|E_FMAN_KG_GEN_EXTRACT_MPLS_N
block|,
name|E_FMAN_KG_GEN_EXTRACT_IPv4_1
block|,
name|E_FMAN_KG_GEN_EXTRACT_IPv6_1
block|,
name|E_FMAN_KG_GEN_EXTRACT_IPv4_2
block|,
name|E_FMAN_KG_GEN_EXTRACT_IPv6_2
block|,
name|E_FMAN_KG_GEN_EXTRACT_MINENCAP
block|,
name|E_FMAN_KG_GEN_EXTRACT_IP_PID
block|,
name|E_FMAN_KG_GEN_EXTRACT_GRE
block|,
name|E_FMAN_KG_GEN_EXTRACT_TCP
block|,
name|E_FMAN_KG_GEN_EXTRACT_UDP
block|,
name|E_FMAN_KG_GEN_EXTRACT_SCTP
block|,
name|E_FMAN_KG_GEN_EXTRACT_DCCP
block|,
name|E_FMAN_KG_GEN_EXTRACT_IPSEC_AH
block|,
name|E_FMAN_KG_GEN_EXTRACT_IPSEC_ESP
block|,
name|E_FMAN_KG_GEN_EXTRACT_SHIM_1
block|,
name|E_FMAN_KG_GEN_EXTRACT_SHIM_2
block|,
name|E_FMAN_KG_GEN_EXTRACT_FROM_DFLT
block|,
name|E_FMAN_KG_GEN_EXTRACT_FROM_FRAME_START
block|,
name|E_FMAN_KG_GEN_EXTRACT_FROM_PARSE_RESULT
block|,
name|E_FMAN_KG_GEN_EXTRACT_FROM_END_OF_PARSE
block|,
name|E_FMAN_KG_GEN_EXTRACT_FROM_FQID
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fman_kg_ex_ecc_attr
block|{
name|bool
name|valid
decl_stmt|;
name|bool
name|double_ecc
decl_stmt|;
name|uint16_t
name|addr
decl_stmt|;
name|uint8_t
name|single_ecc_count
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fman_kg_def_select
block|{
name|E_FMAN_KG_DEF_GLOBAL_0
block|,
name|E_FMAN_KG_DEF_GLOBAL_1
block|,
name|E_FMAN_KG_DEF_SCHEME_0
block|,
name|E_FMAN_KG_DEF_SCHEME_1
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fman_kg_extract_def
block|{
name|enum
name|fman_kg_def_select
name|mac_addr
decl_stmt|;
name|enum
name|fman_kg_def_select
name|vlan_tci
decl_stmt|;
name|enum
name|fman_kg_def_select
name|etype
decl_stmt|;
name|enum
name|fman_kg_def_select
name|ppp_sid
decl_stmt|;
name|enum
name|fman_kg_def_select
name|ppp_pid
decl_stmt|;
name|enum
name|fman_kg_def_select
name|mpls
decl_stmt|;
name|enum
name|fman_kg_def_select
name|ip_addr
decl_stmt|;
name|enum
name|fman_kg_def_select
name|ptype
decl_stmt|;
name|enum
name|fman_kg_def_select
name|ip_tos_tc
decl_stmt|;
name|enum
name|fman_kg_def_select
name|ipv6_fl
decl_stmt|;
name|enum
name|fman_kg_def_select
name|ipsec_spi
decl_stmt|;
name|enum
name|fman_kg_def_select
name|l4_port
decl_stmt|;
name|enum
name|fman_kg_def_select
name|tcp_flg
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fman_kg_gen_extract_type
block|{
name|E_FMAN_KG_HASH_EXTRACT
block|,
name|E_FMAN_KG_OR_EXTRACT
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fman_kg_gen_extract_params
block|{
comment|/* Hash or Or-ed extract */
name|enum
name|fman_kg_gen_extract_type
name|type
decl_stmt|;
name|enum
name|fman_kg_gen_extract_src
name|src
decl_stmt|;
name|bool
name|no_validation
decl_stmt|;
comment|/* Extraction offset from the header location specified above */
name|uint8_t
name|offset
decl_stmt|;
comment|/* Size of extraction for FMAN_KG_HASH_EXTRACT, 	 * hash result shift for FMAN_KG_OR_EXTRACT */
name|uint8_t
name|extract
decl_stmt|;
name|uint8_t
name|mask
decl_stmt|;
comment|/* Default value to use when header specified 	 * by fman_kg_gen_extract_src doesn't present */
name|enum
name|fman_kg_def_select
name|def_val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_extract_mask
block|{
comment|/**< Indication if mask is on known field extraction or 	 * on general extraction; TRUE for known field */
name|bool
name|is_known
decl_stmt|;
comment|/**< One of FMAN_KG_EXTRACT_xxx defines for known fields mask and 	 * generic register index for generic extracts mask */
name|uint32_t
name|field_or_gen_idx
decl_stmt|;
comment|/**< Byte offset from start of the extracted data specified 	 * by field_or_gen_idx */
name|uint8_t
name|offset
decl_stmt|;
comment|/**< Byte mask (selected bits will be used) */
name|uint8_t
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_extract_params
block|{
comment|/* Or-ed mask of FMAN_KG_EXTRACT_xxx defines */
name|uint32_t
name|known_fields
decl_stmt|;
name|struct
name|fman_kg_extract_def
name|known_fields_def
decl_stmt|;
comment|/* Number of entries in gen_extract */
name|uint8_t
name|gen_extract_num
decl_stmt|;
name|struct
name|fman_kg_gen_extract_params
name|gen_extract
index|[
name|FM_KG_NUM_OF_GENERIC_REGS
index|]
decl_stmt|;
comment|/* Number of entries in masks */
name|uint8_t
name|masks_num
decl_stmt|;
name|struct
name|fman_kg_extract_mask
name|masks
index|[
name|FM_KG_EXTRACT_MASKS_NUM
index|]
decl_stmt|;
name|uint32_t
name|def_scheme_0
decl_stmt|;
name|uint32_t
name|def_scheme_1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_hash_params
block|{
name|bool
name|use_hash
decl_stmt|;
name|uint8_t
name|shift_r
decl_stmt|;
name|uint32_t
name|mask
decl_stmt|;
comment|/**< 24-bit mask */
name|bool
name|sym
decl_stmt|;
comment|/**< Symmetric hash for src and dest pairs */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_pp_params
block|{
name|uint8_t
name|base
decl_stmt|;
name|uint8_t
name|shift
decl_stmt|;
name|uint8_t
name|mask
decl_stmt|;
name|bool
name|bypass_pp_gen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_cc_params
block|{
name|uint8_t
name|base_offset
decl_stmt|;
name|uint32_t
name|qlcv_bits_sel
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fman_pcd_engine
block|{
name|E_FMAN_PCD_INVALID
init|=
literal|0
block|,
comment|/**< Invalid PCD engine indicated*/
name|E_FMAN_PCD_DONE
block|,
comment|/**< No PCD Engine indicated */
name|E_FMAN_PCD_KG
block|,
comment|/**< Keygen indicated */
name|E_FMAN_PCD_CC
block|,
comment|/**< Coarse classification indicated */
name|E_FMAN_PCD_PLCR
block|,
comment|/**< Policer indicated */
name|E_FMAN_PCD_PRS
comment|/**< Parser indicated */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fman_kg_cls_plan_params
block|{
name|uint8_t
name|entries_mask
decl_stmt|;
name|uint32_t
name|mask_vector
index|[
name|FM_KG_NUM_CLS_PLAN_ENTR
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_kg_scheme_params
block|{
name|uint32_t
name|match_vector
decl_stmt|;
name|struct
name|fman_kg_extract_params
name|extract_params
decl_stmt|;
name|struct
name|fman_kg_hash_params
name|hash_params
decl_stmt|;
name|uint32_t
name|base_fqid
decl_stmt|;
comment|/* What we do w/features supported per FM version ?? */
name|bool
name|bypass_fqid_gen
decl_stmt|;
name|struct
name|fman_kg_pp_params
name|policer_params
decl_stmt|;
name|struct
name|fman_kg_cc_params
name|cc_params
decl_stmt|;
name|bool
name|update_counter
decl_stmt|;
comment|/**< counter_value: Set scheme counter to the specified value; 	 * relevant only when update_counter = TRUE. */
name|uint32_t
name|counter_value
decl_stmt|;
name|enum
name|fman_pcd_engine
name|next_engine
decl_stmt|;
comment|/**< Next engine action code */
name|uint32_t
name|next_engine_action
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|fman_kg_write_ar_wait
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|fmkg_ar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_write_sp
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|sp
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_write_cpp
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|cpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_get_event
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
modifier|*
name|event
parameter_list|,
name|uint32_t
modifier|*
name|scheme_idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_init
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|exceptions
parameter_list|,
name|uint32_t
name|dflt_nia
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_enable_scheme_interrupts
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_enable
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_disable
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_write_bind_cls_plans
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|hwport_id
parameter_list|,
name|uint32_t
name|bind_cls_plans
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_build_bind_cls_plans
parameter_list|(
name|uint8_t
name|grp_base
parameter_list|,
name|uint8_t
name|grp_mask
parameter_list|,
name|uint32_t
modifier|*
name|bind_cls_plans
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_write_bind_schemes
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|hwport_id
parameter_list|,
name|uint32_t
name|schemes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_write_cls_plan
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|grp_id
parameter_list|,
name|uint8_t
name|entries_mask
parameter_list|,
name|uint8_t
name|hwport_id
parameter_list|,
name|struct
name|fman_kg_cp_regs
modifier|*
name|cls_plan_regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_build_cls_plan
parameter_list|(
name|struct
name|fman_kg_cls_plan_params
modifier|*
name|params
parameter_list|,
name|struct
name|fman_kg_cp_regs
modifier|*
name|cls_plan_regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_kg_get_schemes_total_counter
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_set_scheme_counter
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|scheme_id
parameter_list|,
name|uint8_t
name|hwport_id
parameter_list|,
name|uint32_t
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_get_scheme_counter
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|scheme_id
parameter_list|,
name|uint8_t
name|hwport_id
parameter_list|,
name|uint32_t
modifier|*
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_delete_scheme
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|scheme_id
parameter_list|,
name|uint8_t
name|hwport_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_write_scheme
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|scheme_id
parameter_list|,
name|uint8_t
name|hwport_id
parameter_list|,
name|struct
name|fman_kg_scheme_regs
modifier|*
name|scheme_regs
parameter_list|,
name|bool
name|update_counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_kg_build_scheme
parameter_list|(
name|struct
name|fman_kg_scheme_params
modifier|*
name|params
parameter_list|,
name|struct
name|fman_kg_scheme_regs
modifier|*
name|scheme_regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_get_capture
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|struct
name|fman_kg_ex_ecc_attr
modifier|*
name|ecc_attr
parameter_list|,
name|bool
name|clear
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_get_exception
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
modifier|*
name|events
parameter_list|,
name|uint32_t
modifier|*
name|scheme_ids
parameter_list|,
name|bool
name|clear
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_set_exception
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|exception
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_set_dflt_val
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|def_id
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_kg_set_data_after_prs
parameter_list|(
name|struct
name|fman_kg_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @Description       NIA Description */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|KG_NIA_ORDER_RESTOR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|KG_NIA_ENG_FM_CTL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|KG_NIA_ENG_PRS
value|0x00440000
end_define

begin_define
define|#
directive|define
name|KG_NIA_ENG_KG
value|0x00480000
end_define

begin_define
define|#
directive|define
name|KG_NIA_ENG_PLCR
value|0x004C0000
end_define

begin_define
define|#
directive|define
name|KG_NIA_ENG_BMI
value|0x00500000
end_define

begin_define
define|#
directive|define
name|KG_NIA_ENG_QMI_ENQ
value|0x00540000
end_define

begin_define
define|#
directive|define
name|KG_NIA_ENG_QMI_DEQ
value|0x00580000
end_define

begin_define
define|#
directive|define
name|KG_NIA_ENG_MASK
value|0x007C0000
end_define

begin_define
define|#
directive|define
name|KG_NIA_AC_MASK
value|0x0003FFFF
end_define

begin_define
define|#
directive|define
name|KG_NIA_INVALID
value|0xFFFFFFFF
end_define

begin_function
specifier|static
name|__inline__
name|uint32_t
name|fm_kg_build_nia
parameter_list|(
name|enum
name|fman_pcd_engine
name|next_engine
parameter_list|,
name|uint32_t
name|next_engine_action
parameter_list|)
block|{
name|uint32_t
name|nia
decl_stmt|;
if|if
condition|(
name|next_engine_action
operator|&
operator|~
name|KG_NIA_AC_MASK
condition|)
return|return
name|KG_NIA_INVALID
return|;
switch|switch
condition|(
name|next_engine
condition|)
block|{
case|case
name|E_FMAN_PCD_DONE
case|:
name|nia
operator|=
name|KG_NIA_ENG_BMI
operator||
name|next_engine_action
expr_stmt|;
break|break;
case|case
name|E_FMAN_PCD_KG
case|:
name|nia
operator|=
name|KG_NIA_ENG_KG
operator||
name|next_engine_action
expr_stmt|;
break|break;
case|case
name|E_FMAN_PCD_CC
case|:
name|nia
operator|=
name|KG_NIA_ENG_FM_CTL
operator||
name|next_engine_action
expr_stmt|;
break|break;
case|case
name|E_FMAN_PCD_PLCR
case|:
name|nia
operator|=
name|KG_NIA_ENG_PLCR
operator||
name|next_engine_action
expr_stmt|;
break|break;
default|default:
name|nia
operator|=
name|KG_NIA_INVALID
expr_stmt|;
block|}
return|return
name|nia
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_FMAN_KG_H */
end_comment

end_unit

