begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_pcd.h   @Description   FM PCD ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_PCD_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_PCD_H
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
file|"fm_pcd_ext.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_FM_PCD
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_PCD_Runtime_grp FM PCD Runtime Unit  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/* Network defines          */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_define
define|#
directive|define
name|UDP_HEADER_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|ESP_SPI_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|ESP_SPI_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|ESP_SEQ_NUM_OFFSET
value|ESP_SPI_SIZE
end_define

begin_define
define|#
directive|define
name|ESP_SEQ_NUM_SIZE
value|4
end_define

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/* General defines          */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_define
define|#
directive|define
name|ILLEGAL_CLS_PLAN
value|0xff
end_define

begin_define
define|#
directive|define
name|ILLEGAL_NETENV
value|0xff
end_define

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/* Error defines           */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_EX_KG_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_EX_KG_KEYSIZE_OVERFLOW
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_EX_PLCR_DOUBLE_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_EX_PLCR_INIT_ENTRY_ERROR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_EX_PLCR_PRAM_SELF_INIT_COMPLETE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_EX_PLCR_ATOMIC_ACTION_COMPLETE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_EX_PRS_DOUBLE_ECC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_EX_PRS_SINGLE_ECC
value|0x01000000
end_define

begin_define
define|#
directive|define
name|GET_FM_PCD_EXCEPTION_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|exception
parameter_list|)
define|\
value|switch(exception){                                                  \     case e_FM_PCD_KG_EXCEPTION_DOUBLE_ECC:                          \         bitMask = FM_PCD_EX_KG_DOUBLE_ECC; break;                   \     case e_FM_PCD_PLCR_EXCEPTION_DOUBLE_ECC:                        \         bitMask = FM_PCD_EX_PLCR_DOUBLE_ECC; break;                 \     case e_FM_PCD_KG_EXCEPTION_KEYSIZE_OVERFLOW:                    \         bitMask = FM_PCD_EX_KG_KEYSIZE_OVERFLOW; break;             \     case e_FM_PCD_PLCR_EXCEPTION_INIT_ENTRY_ERROR:                  \         bitMask = FM_PCD_EX_PLCR_INIT_ENTRY_ERROR; break;           \     case e_FM_PCD_PLCR_EXCEPTION_PRAM_SELF_INIT_COMPLETE:           \         bitMask = FM_PCD_EX_PLCR_PRAM_SELF_INIT_COMPLETE; break;    \     case e_FM_PCD_PLCR_EXCEPTION_ATOMIC_ACTION_COMPLETE:            \         bitMask = FM_PCD_EX_PLCR_ATOMIC_ACTION_COMPLETE; break;     \     case e_FM_PCD_PRS_EXCEPTION_DOUBLE_ECC:                         \         bitMask = FM_PCD_EX_PRS_DOUBLE_ECC; break;                  \     case e_FM_PCD_PRS_EXCEPTION_SINGLE_ECC:                         \         bitMask = FM_PCD_EX_PRS_SINGLE_ECC; break;                  \     default: bitMask = 0;break;}
end_define

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          SW parser L4 shells patch                                  */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FM_PRS_L4_SHELL_ERRATA_FMANb
end_ifdef

begin_define
define|#
directive|define
name|SW_PRS_L4_PATCH
define|\
value|{   0x31,0x92,0x02,0x1f,0x00,0x32,0x00,0x78,    \     0x00,0x34,0x32,0xf0,0x00,0x50,0x00,0x0c,    \     0x28,0x5e,0x83,0x8e,0x29,0x32,0xaf,0x8e,    \     0x31,0xb2,0x9f,0xff,0x00,0x06,0xaf,0xbf,    \     0x00,0x06,0x29,0x36,0x00,0x01,0x1b,0xff,    \     0x32,0xf0,0x00,0x50,0x00,0x08,0x28,0x5e,    \     0x08,0x99,0x00,0x00,0x9f,0x8e,0x31,0xb2,    \     0x9f,0xff,0x00,0x06,0x29,0x36,0x00,0x01,    \     0x1b,0xff,0x32,0xf0,0x00,0x50,0x00,0x04,    \     0x28,0x5e,0x8f,0x9e,0x29,0x32,0x31,0xb2,    \     0x8f,0xbf,0x00,0x06,0x29,0x36,0x00,0x01,    \     0x1b,0xff,0x32,0xf0,0x00,0x50,0x00,0x04,    \     0x28,0x5e,0x8f,0x9e,0x29,0x32,0x31,0xb2,    \     0x8f,0xbf,0x00,0x06,0x29,0x36,0x00,0x01,    \     0x1b,0xff,0x00,0x00,0x00,0x00,0x00,0x00};
end_define

begin_define
define|#
directive|define
name|SW_PRS_L4_PATCH_SIZE
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_PRS_L4_SHELL_ERRATA_FMANb */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/* Parser defines           */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|PRS_ERR_CAP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PRS_ERR_TYPE_DOUBLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PRS_ERR_SINGLE_ECC_CNT_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|PRS_ERR_ADDR_MASK
value|0x000001FF
end_define

begin_define
define|#
directive|define
name|FM_PCD_PRS_RPIMAC_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FM_PCD_PRS_SINGLE_ECC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PRS_PORT_IDLE_STS
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PRS_DOUBLE_ECC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PRS_PPSC_ALL_PORTS
value|0xffff0000
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|PRS_MAX_CYCLE_LIMIT
value|8191
end_define

begin_define
define|#
directive|define
name|PRS_SW_DATA
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PRS_REGS_OFFSET
value|0x00000840
end_define

begin_define
define|#
directive|define
name|GET_FM_PCD_PRS_PORT_ID
parameter_list|(
name|prsPortId
parameter_list|,
name|hardwarePortId
parameter_list|)
define|\
value|prsPortId = (uint8_t)(hardwarePortId& 0x0f)
end_define

begin_define
define|#
directive|define
name|GET_FM_PCD_INDEX_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|prsPortId
parameter_list|)
define|\
value|bitMask = 0x80000000>>prsPortId
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

begin_comment
comment|/* Masks */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG_KGGCR_EN
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
name|KG_ERR_CAP
value|0x80000000
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
name|FM_PCD_KG_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KEYSIZE_OVERFLOW
value|0x40000000
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
name|FM_PCD_KG_PE_CPP_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_WSEL_SHIFT
value|8
end_define

begin_comment
comment|/* others */
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|known
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
block|}
name|t_FmPcdKgSchemesExtractsEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmPcdKgSchemesExtractsEntry
name|extractsArray
index|[
name|FM_PCD_KG_MAX_NUM_OF_EXTRACTS_PER_KEY
index|]
decl_stmt|;
block|}
name|t_FmPcdKgSchemesExtracts
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Policer defines                                            */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_PI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_CBLND
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_ALG_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_ALG_RFC2698
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_ALG_RFC4115
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_DEFC_MASK
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_DEFC_Y
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_DEFC_R
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_DEFC_OVERRIDE
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_OVCLR_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_OVCLR_Y
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_OVCLR_R
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_OVCLR_G_NC
value|0x03000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_PKT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FPP_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FPP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_L2
value|0x00003000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_L3
value|0x0000B000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_L4
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_FULL
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_RBFLS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_TRA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_TRB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_TRC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_INIT_ENTRY_ERROR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PRAM_SELF_INIT_COMPLETE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_ATOMIC_ACTION_COMPLETE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_NIA_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GCR_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GCR_STEN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GCR_DAR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GCR_DEFNIA
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_NIA_ABS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_BSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_DQS
value|0x60000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_RPB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_FQS
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_LPALG
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_LPCA
value|0x00003000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_LPNUM
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_EVR_PSIC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_EVR_AAC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PSI
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PNUM
value|0x00FF0000
end_define

begin_comment
comment|/* PWSEL Selctive select options */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEMODE
value|0x00008000
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEGNIA
value|0x00004000
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEYNIA
value|0x00002000
end_define

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PERNIA
value|0x00001000
end_define

begin_comment
comment|/* 3 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PECIR
value|0x00000800
end_define

begin_comment
comment|/* 4 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PECBS
value|0x00000400
end_define

begin_comment
comment|/* 5 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEPIR_EIR
value|0x00000200
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEPBS_EBS
value|0x00000100
end_define

begin_comment
comment|/* 7 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PELTS
value|0x00000080
end_define

begin_comment
comment|/* 8 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PECTS
value|0x00000040
end_define

begin_comment
comment|/* 9 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEPTS_ETS
value|0x00000020
end_define

begin_comment
comment|/* 10 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEGPC
value|0x00000010
end_define

begin_comment
comment|/* 11 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEYPC
value|0x00000008
end_define

begin_comment
comment|/* 12 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PERPC
value|0x00000004
end_define

begin_comment
comment|/* 13 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PERYPC
value|0x00000002
end_define

begin_comment
comment|/* 14 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PERRPC
value|0x00000001
end_define

begin_comment
comment|/* 15 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_1TO1
value|0x0000
end_define

begin_comment
comment|/* - Full bit replacement. {PBNUM[0:N-1]                                                            1-> 2^N specific locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_2TO2
value|0x1
end_define

begin_comment
comment|/* - {PBNUM[0:N-2],PNUM[N-1]}.                                                            2-> 2^(N-1) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_4TO4
value|0x2
end_define

begin_comment
comment|/* - {PBNUM[0:N-3],PNUM[N-2:N-1]}.                                                            4-> 2^(N-2) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_8TO8
value|0x3
end_define

begin_comment
comment|/* - {PBNUM[0:N-4],PNUM[N-3:N-1]}.                                                            8->2^(N-3) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_16TO16
value|0x4
end_define

begin_comment
comment|/* - {PBNUM[0:N-5],PNUM[N-4:N-1]}.                                                            16-> 2^(N-4) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_32TO32
value|0x5
end_define

begin_comment
comment|/* {PBNUM[0:N-6],PNUM[N-5:N-1]}.                                                            32-> 2^(N-5) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_64TO64
value|0x6
end_define

begin_comment
comment|/* {PBNUM[0:N-7],PNUM[N-6:N-1]}.                                                            64-> 2^(N-6) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_128TO128
value|0x7
end_define

begin_comment
comment|/* {PBNUM[0:N-8],PNUM[N-7:N-1]}.                                                             128-> 2^(N-7) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_256TO256
value|0x8
end_define

begin_comment
comment|/* - No bit replacement for N=8. {PNUM[N-8:N-1]}.                                                             When N=8 this option maps all 256 profiles by the DISPATCH bus into one group. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PMR_V
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_CAP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_TYPE_DOUBLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_PNUM_MASK
value|0x00000FF0
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_OFFSET_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_CAP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_NUM_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_PID_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_ABSOLUTE_MASK
value|0x00008000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_PNUM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_PID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PMR_BRN_SHIFT
value|16
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|WAIT_FOR_PLCR_EVR_AAC
define|\
value|{\     uint32_t count = 0; \     uint32_t tmpReg32; \     while (count< FM_PCD_PLCR_POLL) \     { \         tmpReg32 = GET_UINT32(p_FmPcdPlcrRegs->fmpl_evr);\         if (!( tmpReg32& FM_PCD_PLCR_EVR_AAC)) break;\         count++;\     }\ }
end_define

begin_define
define|#
directive|define
name|WAIT_FOR_PLCR_PAR_GO
define|\
value|{\     uint32_t count = 0; \     uint32_t tmpReg32; \     while (count< FM_PCD_PLCR_POLL) \     { \         tmpReg32 = GET_UINT32(p_FmPcdPlcrRegs->fmpl_par);\         if (!( tmpReg32& FM_PCD_PLCR_PAR_GO)) break;\         count++; \     }\ }
end_define

begin_define
define|#
directive|define
name|PLCR_PORT_WINDOW_SIZE
parameter_list|(
name|hardwarePortId
parameter_list|)
end_define

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/* Defaults                 */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_define
define|#
directive|define
name|DEFAULT_plcrAutoRefresh
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_prsMaxParseCycleLimit
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_fmPcdKgErrorExceptions
value|(FM_PCD_EX_KG_DOUBLE_ECC | FM_PCD_EX_KG_KEYSIZE_OVERFLOW)
end_define

begin_define
define|#
directive|define
name|DEFAULT_fmPcdPlcrErrorExceptions
value|(FM_PCD_EX_PLCR_DOUBLE_ECC | FM_PCD_EX_PLCR_INIT_ENTRY_ERROR)
end_define

begin_define
define|#
directive|define
name|DEFAULT_fmPcdPlcrExceptions
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_fmPcdPrsErrorExceptions
value|(FM_PCD_EX_PRS_DOUBLE_ECC)
end_define

begin_define
define|#
directive|define
name|DEFAULT_fmPcdPrsExceptions
value|FM_PCD_EX_PRS_SINGLE_ECC
end_define

begin_define
define|#
directive|define
name|DEFAULT_numOfUsedProfilesPerWindow
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_numOfSharedPlcrProfiles
value|4
end_define

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

begin_define
define|#
directive|define
name|MEM_MAP_START
end_define

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|kgoe_sp
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgoe_cpp
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdKgPortConfigRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|kgcpe
index|[
literal|8
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdKgClsPlanRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
union|union
block|{
name|t_FmPcdKgInterModuleSchemeRegs
name|schemeRegs
decl_stmt|;
name|t_FmPcdKgPortConfigRegs
name|portRegs
decl_stmt|;
name|t_FmPcdKgClsPlanRegs
name|clsPlanRegs
decl_stmt|;
block|}
name|_PackedType
name|u_FmPcdKgIndirectAccessRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|kggcr
decl_stmt|;
specifier|volatile
name|uint32_t
name|res0
decl_stmt|;
specifier|volatile
name|uint32_t
name|res1
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgeer
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgeeer
decl_stmt|;
specifier|volatile
name|uint32_t
name|res2
decl_stmt|;
specifier|volatile
name|uint32_t
name|res3
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgseer
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgseeer
decl_stmt|;
specifier|volatile
name|uint32_t
name|kggsr
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgtpc
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgserc
decl_stmt|;
specifier|volatile
name|uint32_t
name|res4
index|[
literal|4
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgfdor
decl_stmt|;
specifier|volatile
name|uint32_t
name|kggdv0r
decl_stmt|;
specifier|volatile
name|uint32_t
name|kggdv1r
decl_stmt|;
specifier|volatile
name|uint32_t
name|res5
index|[
literal|5
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgfer
decl_stmt|;
specifier|volatile
name|uint32_t
name|kgfeer
decl_stmt|;
specifier|volatile
name|uint32_t
name|res6
index|[
literal|38
index|]
decl_stmt|;
name|u_FmPcdKgIndirectAccessRegs
name|indirectAccessRegs
decl_stmt|;
specifier|volatile
name|uint32_t
name|res
index|[
literal|42
index|]
decl_stmt|;
comment|/*(0xfc-sizeof(u_FmPcdKgIndirectAccessRegs))/4 */
specifier|volatile
name|uint32_t
name|kgar
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdKgRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
comment|/* General Configuration and Status Registers */
specifier|volatile
name|uint32_t
name|fmpl_gcr
decl_stmt|;
comment|/* 0x000 FMPL_GCR  - FM Policer General Configuration */
specifier|volatile
name|uint32_t
name|fmpl_gsr
decl_stmt|;
comment|/* 0x004 FMPL_GSR  - FM Policer Global Status Register */
specifier|volatile
name|uint32_t
name|fmpl_evr
decl_stmt|;
comment|/* 0x008 FMPL_EVR  - FM Policer Event Register */
specifier|volatile
name|uint32_t
name|fmpl_ier
decl_stmt|;
comment|/* 0x00C FMPL_IER  - FM Policer Interrupt Enable Register */
specifier|volatile
name|uint32_t
name|fmpl_ifr
decl_stmt|;
comment|/* 0x010 FMPL_IFR  - FM Policer Interrupt Force Register */
specifier|volatile
name|uint32_t
name|fmpl_eevr
decl_stmt|;
comment|/* 0x014 FMPL_EEVR - FM Policer Error Event Register */
specifier|volatile
name|uint32_t
name|fmpl_eier
decl_stmt|;
comment|/* 0x018 FMPL_EIER - FM Policer Error Interrupt Enable Register */
specifier|volatile
name|uint32_t
name|fmpl_eifr
decl_stmt|;
comment|/* 0x01C FMPL_EIFR - FM Policer Error Interrupt Force Register */
comment|/* Global Statistic Counters */
specifier|volatile
name|uint32_t
name|fmpl_rpcnt
decl_stmt|;
comment|/* 0x020 FMPL_RPC  - FM Policer RED Packets Counter */
specifier|volatile
name|uint32_t
name|fmpl_ypcnt
decl_stmt|;
comment|/* 0x024 FMPL_YPC  - FM Policer YELLOW Packets Counter */
specifier|volatile
name|uint32_t
name|fmpl_rrpcnt
decl_stmt|;
comment|/* 0x028 FMPL_RRPC - FM Policer Recolored RED Packet Counter */
specifier|volatile
name|uint32_t
name|fmpl_rypcnt
decl_stmt|;
comment|/* 0x02C FMPL_RYPC - FM Policer Recolored YELLOW Packet Counter */
specifier|volatile
name|uint32_t
name|fmpl_tpcnt
decl_stmt|;
comment|/* 0x030 FMPL_TPC  - FM Policer Total Packet Counter */
specifier|volatile
name|uint32_t
name|fmpl_flmcnt
decl_stmt|;
comment|/* 0x034 FMPL_FLMC - FM Policer Frame Length Mismatch Counter */
specifier|volatile
name|uint32_t
name|fmpl_res0
index|[
literal|21
index|]
decl_stmt|;
comment|/* 0x038 - 0x08B Reserved */
comment|/* Profile RAM Access Registers */
specifier|volatile
name|uint32_t
name|fmpl_par
decl_stmt|;
comment|/* 0x08C FMPL_PAR    - FM Policer Profile Action Register*/
name|t_FmPcdPlcrInterModuleProfileRegs
name|profileRegs
decl_stmt|;
comment|/* Error Capture Registers */
specifier|volatile
name|uint32_t
name|fmpl_serc
decl_stmt|;
comment|/* 0x100 FMPL_SERC - FM Policer Soft Error Capture */
specifier|volatile
name|uint32_t
name|fmpl_upcr
decl_stmt|;
comment|/* 0x104 FMPL_UPCR - FM Policer Uninitialized Profile Capture Register */
specifier|volatile
name|uint32_t
name|fmpl_res2
decl_stmt|;
comment|/* 0x108 Reserved */
comment|/* Debug Registers */
specifier|volatile
name|uint32_t
name|fmpl_res3
index|[
literal|61
index|]
decl_stmt|;
comment|/* 0x10C-0x200 Reserved Debug*/
comment|/* Profile Selection Mapping Registers Per Port-ID (n=1-11, 16) */
specifier|volatile
name|uint32_t
name|fmpl_dpmr
decl_stmt|;
comment|/* 0x200 FMPL_DPMR - FM Policer Default Mapping Register */
specifier|volatile
name|uint32_t
name|fmpl_pmr
index|[
literal|63
index|]
decl_stmt|;
comment|/*+default 0x204-0x2FF FMPL_PMR1 - FMPL_PMR63, - FM Policer Profile Mapping Registers.                                            (for port-ID 1-11, only for supported Port-ID registers) */
block|}
name|_PackedType
name|t_FmPcdPlcrRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|rpclim
decl_stmt|;
specifier|volatile
name|uint32_t
name|rpimac
decl_stmt|;
specifier|volatile
name|uint32_t
name|pmeec
decl_stmt|;
specifier|volatile
name|uint32_t
name|res1
index|[
literal|5
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|pevr
decl_stmt|;
specifier|volatile
name|uint32_t
name|pever
decl_stmt|;
specifier|volatile
name|uint32_t
name|pevfr
decl_stmt|;
specifier|volatile
name|uint32_t
name|perr
decl_stmt|;
specifier|volatile
name|uint32_t
name|perer
decl_stmt|;
specifier|volatile
name|uint32_t
name|perfr
decl_stmt|;
specifier|volatile
name|uint32_t
name|res2
index|[
literal|0xA
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|ppsc
decl_stmt|;
specifier|volatile
name|uint32_t
name|res3
decl_stmt|;
specifier|volatile
name|uint32_t
name|pds
decl_stmt|;
specifier|volatile
name|uint32_t
name|l2rrs
decl_stmt|;
specifier|volatile
name|uint32_t
name|l3rrs
decl_stmt|;
specifier|volatile
name|uint32_t
name|l4rrs
decl_stmt|;
specifier|volatile
name|uint32_t
name|srrs
decl_stmt|;
specifier|volatile
name|uint32_t
name|l2rres
decl_stmt|;
specifier|volatile
name|uint32_t
name|l3rres
decl_stmt|;
specifier|volatile
name|uint32_t
name|l4rres
decl_stmt|;
specifier|volatile
name|uint32_t
name|srres
decl_stmt|;
specifier|volatile
name|uint32_t
name|spcs
decl_stmt|;
specifier|volatile
name|uint32_t
name|spscs
decl_stmt|;
specifier|volatile
name|uint32_t
name|hxscs
decl_stmt|;
specifier|volatile
name|uint32_t
name|mrcs
decl_stmt|;
specifier|volatile
name|uint32_t
name|mwcs
decl_stmt|;
specifier|volatile
name|uint32_t
name|mrscs
decl_stmt|;
specifier|volatile
name|uint32_t
name|mwscs
decl_stmt|;
specifier|volatile
name|uint32_t
name|fcscs
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdPrsRegs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MEM_MAP_END
end_define

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

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Manip
decl_stmt|;
name|bool
name|keepRes
decl_stmt|;
name|e_FmPcdEngine
name|nextEngine
decl_stmt|;
name|uint8_t
name|parseCode
decl_stmt|;
block|}
name|t_FmPcdInfoForManip
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure of parameters to communicate                 between the port and PCD regarding the KG scheme. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|netEnvId
decl_stmt|;
comment|/* in */
name|uint8_t
name|numOfDistinctionUnits
decl_stmt|;
comment|/* in */
name|uint8_t
name|unitIds
index|[
name|FM_PCD_MAX_NUM_OF_DISTINCTION_UNITS
index|]
decl_stmt|;
comment|/* in */
name|uint32_t
name|vector
decl_stmt|;
comment|/* out */
block|}
name|t_NetEnvParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|bool
name|lock
decl_stmt|;
name|bool
name|used
decl_stmt|;
name|uint8_t
name|owners
decl_stmt|;
name|uint8_t
name|netEnvId
decl_stmt|;
name|uint8_t
name|guestId
decl_stmt|;
name|uint8_t
name|baseEntry
decl_stmt|;
name|uint16_t
name|sizeOfGrp
decl_stmt|;
name|protocolOpt_t
name|optArray
index|[
name|FM_PCD_MAX_NUM_OF_OPTIONS
argument_list|(
name|FM_PCD_MAX_NUM_OF_CLS_PLANS
argument_list|)
index|]
decl_stmt|;
block|}
name|t_FmPcdKgClsPlanGrp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|bool
name|lock
decl_stmt|;
name|bool
name|valid
decl_stmt|;
name|uint8_t
name|netEnvId
decl_stmt|;
name|uint8_t
name|owners
decl_stmt|;
name|uint32_t
name|matchVector
decl_stmt|;
name|uint32_t
name|ccUnits
decl_stmt|;
name|bool
name|nextRelativePlcrProfile
decl_stmt|;
name|uint16_t
name|relativeProfileId
decl_stmt|;
name|uint16_t
name|numOfProfiles
decl_stmt|;
name|t_FmPcdKgKeyOrder
name|orderedArray
decl_stmt|;
name|e_FmPcdEngine
name|nextEngine
decl_stmt|;
name|e_FmPcdDoneAction
name|doneAction
decl_stmt|;
name|uint8_t
name|pointedOwners
decl_stmt|;
name|uint32_t
name|requiredAction
decl_stmt|;
name|bool
name|extractedOrs
decl_stmt|;
name|uint8_t
name|bitOffsetInPlcrProfile
decl_stmt|;
name|bool
name|directPlcr
decl_stmt|;
block|}
name|t_FmPcdKgScheme
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|allocated
decl_stmt|;
name|uint8_t
name|ownerId
decl_stmt|;
comment|/* guestId for KG in multi-partition only,                            portId for PLCR in any environment */
block|}
name|t_FmPcdAllocMng
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmPcdKgRegs
modifier|*
name|p_FmPcdKgRegs
decl_stmt|;
name|uint32_t
name|schemeExceptionsBitMask
decl_stmt|;
name|uint8_t
name|numOfSchemes
decl_stmt|;
name|uint8_t
name|schemesIds
index|[
name|FM_PCD_KG_NUM_OF_SCHEMES
index|]
decl_stmt|;
name|t_FmPcdKgScheme
name|schemes
index|[
name|FM_PCD_KG_NUM_OF_SCHEMES
index|]
decl_stmt|;
name|t_FmPcdKgClsPlanGrp
name|clsPlanGrps
index|[
name|FM_MAX_NUM_OF_PORTS
index|]
decl_stmt|;
name|uint8_t
name|emptyClsPlanGrpId
decl_stmt|;
name|t_FmPcdAllocMng
name|schemesMng
index|[
name|FM_PCD_KG_NUM_OF_SCHEMES
index|]
decl_stmt|;
comment|/* only for MASTER ! */
name|t_FmPcdAllocMng
name|clsPlanBlocksMng
index|[
name|FM_PCD_MAX_NUM_OF_CLS_PLANS
operator|/
name|CLS_PLAN_NUM_PER_GRP
index|]
decl_stmt|;
block|}
name|t_FmPcdKg
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|profilesBase
decl_stmt|;
name|uint16_t
name|numOfProfiles
decl_stmt|;
name|t_Handle
name|h_FmPort
decl_stmt|;
block|}
name|t_FmPcdPlcrMapParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|valid
decl_stmt|;
specifier|volatile
name|bool
name|lock
decl_stmt|;
name|t_FmPcdAllocMng
name|profilesMng
decl_stmt|;
name|uint8_t
name|pointedOwners
decl_stmt|;
name|uint32_t
name|requiredAction
decl_stmt|;
name|e_FmPcdEngine
name|nextEngineOnGreen
decl_stmt|;
comment|/**< Green next engine type */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnGreen
decl_stmt|;
comment|/**< Green next engine params */
name|e_FmPcdEngine
name|nextEngineOnYellow
decl_stmt|;
comment|/**< Yellow next engine type */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnYellow
decl_stmt|;
comment|/**< Yellow next engine params */
name|e_FmPcdEngine
name|nextEngineOnRed
decl_stmt|;
comment|/**< Red next engine type */
name|u_FmPcdPlcrNextEngineParams
name|paramsOnRed
decl_stmt|;
comment|/**< Red next engine params */
block|}
name|t_FmPcdPlcrProfile
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmPcdPlcrRegs
modifier|*
name|p_FmPcdPlcrRegs
decl_stmt|;
name|t_FmPcdPlcrProfile
name|profiles
index|[
name|FM_PCD_PLCR_NUM_ENTRIES
index|]
decl_stmt|;
name|uint16_t
name|numOfSharedProfiles
decl_stmt|;
name|uint16_t
name|sharedProfilesIds
index|[
name|FM_PCD_PLCR_NUM_ENTRIES
index|]
decl_stmt|;
name|t_FmPcdPlcrMapParam
name|portsMapping
index|[
name|FM_MAX_NUM_OF_PORTS
index|]
decl_stmt|;
block|}
name|t_FmPcdPlcr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
modifier|*
name|p_SwPrsCode
decl_stmt|;
name|uint32_t
modifier|*
name|p_CurrSwPrs
decl_stmt|;
name|uint8_t
name|currLabel
decl_stmt|;
name|t_FmPcdPrsRegs
modifier|*
name|p_FmPcdPrsRegs
decl_stmt|;
name|t_FmPcdPrsLabelParams
name|labelsTable
index|[
name|FM_PCD_PRS_NUM_OF_LABELS
index|]
decl_stmt|;
name|uint32_t
name|fmPcdPrsPortIdStatistics
decl_stmt|;
block|}
name|t_FmPcdPrs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
struct|struct
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
name|protocolOpt_t
name|opt
decl_stmt|;
comment|/* only one option !! */
block|}
name|hdrs
index|[
name|FM_PCD_MAX_NUM_OF_INTERCHANGEABLE_HDRS
index|]
struct|;
block|}
name|t_FmPcdIntDistinctionUnit
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|e_NetHeaderType
name|hdr
decl_stmt|;
name|e_NetHeaderType
name|aliasHdr
decl_stmt|;
block|}
name|t_FmPcdNetEnvAliases
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|bool
name|lock
decl_stmt|;
name|bool
name|used
decl_stmt|;
name|uint8_t
name|owners
decl_stmt|;
name|uint8_t
name|clsPlanGrpId
decl_stmt|;
name|t_FmPcdIntDistinctionUnit
name|units
index|[
name|FM_PCD_MAX_NUM_OF_DISTINCTION_UNITS
index|]
decl_stmt|;
name|uint32_t
name|unitsVectors
index|[
name|FM_PCD_MAX_NUM_OF_DISTINCTION_UNITS
index|]
decl_stmt|;
name|uint32_t
name|lcvs
index|[
name|FM_PCD_PRS_NUM_OF_HDRS
index|]
decl_stmt|;
name|uint32_t
name|macsecVector
decl_stmt|;
name|t_FmPcdNetEnvAliases
name|aliasHdrs
index|[
name|FM_PCD_MAX_NUM_OF_PRIVATE_HDRS
index|]
decl_stmt|;
block|}
name|t_FmPcdNetEnv
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|plcrAutoRefresh
decl_stmt|;
name|uint16_t
name|prsMaxParseCycleLimit
decl_stmt|;
block|}
name|t_FmPcdDriverParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Fm
decl_stmt|;
name|t_Handle
name|h_FmMuram
decl_stmt|;
name|uint64_t
name|physicalMuramBase
decl_stmt|;
specifier|volatile
name|bool
name|lock
decl_stmt|;
name|t_Handle
name|h_Spinlock
decl_stmt|;
name|t_Handle
name|h_IpcSession
decl_stmt|;
comment|/* relevant for guest only */
name|bool
name|enabled
decl_stmt|;
name|uint8_t
name|guestId
decl_stmt|;
comment|/**< Guest Partition Id */
name|uint8_t
name|numOfEnabledGuestPartitionsPcds
decl_stmt|;
name|char
name|fmPcdModuleName
index|[
name|MODULE_NAME_SIZE
index|]
decl_stmt|;
name|char
name|fmPcdIpcHandlerModuleName
index|[
name|MODULE_NAME_SIZE
index|]
decl_stmt|;
comment|/* relevant for guest only - this is the master's name */
name|t_FmPcdNetEnv
name|netEnvs
index|[
name|FM_MAX_NUM_OF_PORTS
index|]
decl_stmt|;
name|t_FmPcdKg
modifier|*
name|p_FmPcdKg
decl_stmt|;
name|t_FmPcdPlcr
modifier|*
name|p_FmPcdPlcr
decl_stmt|;
name|t_FmPcdPrs
modifier|*
name|p_FmPcdPrs
decl_stmt|;
name|t_Handle
name|h_Hc
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|t_FmPcdExceptionCallback
modifier|*
name|f_Exception
decl_stmt|;
name|t_FmPcdIdExceptionCallback
modifier|*
name|f_FmPcdIndexedException
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
name|t_FmPcdDriverParam
modifier|*
name|p_FmPcdDriverParam
decl_stmt|;
block|}
name|t_FmPcd
typedef|;
end_typedef

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*  PCD internal routines                                              */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @Group         FM_PCD_InterModule_grp FM PCD Inter-Module Unit   @Description   FM PCD Inter Module functions -                 These are not User API routines but routines that may be called                 from other modules. This will be the case in a single core environment,                 where instead of useing the XX messeging mechanism, the routines may be                 called from other modules. In a multicore environment, the other modules may                 be run by other cores and therefor these routines may not be called directly.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|PcdGetVectorForOpt
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|,
name|protocolOpt_t
name|opt
parameter_list|,
name|uint32_t
modifier|*
name|p_Vector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PcdGetUnitsVector
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|t_NetEnvParams
modifier|*
name|p_Params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PcdNetEnvIsUnitWithoutOpts
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|,
name|uint32_t
name|unitVector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PcdGetClsPlanGrpParams
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|t_FmPcdKgInterModuleClsPlanGrpParams
modifier|*
name|p_GrpParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdSetClsPlanGrpId
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|,
name|uint8_t
name|clsPlanGrpId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|e_NetHeaderType
name|FmPcdGetAliasHdr
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|,
name|e_NetHeaderType
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmPcdNetEnvGetUnitIdForSingleHdr
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|,
name|e_NetHeaderType
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Handle
name|KgConfig
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|t_FmPcdParams
modifier|*
name|p_FmPcdParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|KgInit
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|KgFree
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|KgSetClsPlan
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgInterModuleClsPlanSet
modifier|*
name|p_Set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|KgIsSchemeAlwaysDirect
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|schemeId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|KgEnable
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|KgDisable
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|KgAllocClsPlanEntries
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|numOfClsPlanEntries
parameter_list|,
name|uint8_t
name|guestId
parameter_list|,
name|uint8_t
modifier|*
name|p_First
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|KgFreeClsPlanEntries
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|numOfClsPlanEntries
parameter_list|,
name|uint8_t
name|guestId
parameter_list|,
name|uint8_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* only for MULTI partittion */
end_comment

begin_function_decl
name|t_Error
name|FmPcdKgAllocSchemes
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|numOfSchemes
parameter_list|,
name|uint8_t
name|guestId
parameter_list|,
name|uint8_t
modifier|*
name|p_SchemesIds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgFreeSchemes
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|numOfSchemes
parameter_list|,
name|uint8_t
name|guestId
parameter_list|,
name|uint8_t
modifier|*
name|p_SchemesIds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* only for SINGLE partittion */
end_comment

begin_function_decl
name|t_Error
name|KgBindPortToSchemes
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint32_t
name|spReg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Handle
name|PlcrConfig
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|t_FmPcdParams
modifier|*
name|p_FmPcdParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PlcrInit
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PlcrFree
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PlcrEnable
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PlcrDisable
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PlcrFreeProfiles
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint16_t
name|num
parameter_list|,
name|uint16_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PlcrAllocProfiles
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint16_t
name|numOfProfiles
parameter_list|,
name|uint16_t
modifier|*
name|p_Base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PlcrAllocSharedProfiles
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint16_t
name|numOfProfiles
parameter_list|,
name|uint16_t
modifier|*
name|profilesIds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PlcrFreeSharedProfiles
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint16_t
name|numOfProfiles
parameter_list|,
name|uint16_t
modifier|*
name|profilesIds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Handle
name|PrsConfig
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|t_FmPcdParams
modifier|*
name|p_FmPcdParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PrsInit
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrsEnable
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrsDisable
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrsFree
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|PrsIncludePortInStatistics
parameter_list|(
name|t_FmPcd
modifier|*
name|p_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|bool
name|include
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Handle
name|FmPcdCcConfig
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdParams
modifier|*
name|p_FmPcdParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcGetGrpParams
parameter_list|(
name|t_Handle
name|treeId
parameter_list|,
name|uint8_t
name|grpId
parameter_list|,
name|uint32_t
modifier|*
name|p_GrpBits
parameter_list|,
name|uint8_t
modifier|*
name|p_GrpBase
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmPcdCcGetOffset
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmPcdCcGetParseCode
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|FmPcdCcGetNumOfKeys
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdManipUpdateOwner
parameter_list|(
name|t_Handle
name|h_Manip
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdManipCheckParamsForCcNextEgine
parameter_list|(
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_InfoForManip
parameter_list|,
name|uint32_t
modifier|*
name|requiredAction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdManipUpdateAdResultForCc
parameter_list|(
name|t_Handle
name|h_Manip
parameter_list|,
name|t_Handle
name|p_Ad
parameter_list|,
name|t_Handle
modifier|*
name|p_AdNew
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdManipUpdateAdContLookupForCc
parameter_list|(
name|t_Handle
name|h_Manip
parameter_list|,
name|t_Handle
name|p_Ad
parameter_list|,
name|t_Handle
modifier|*
name|p_AdNew
parameter_list|,
name|uint32_t
name|adTableOffset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdManipCheckNia
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_Ad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdManipUpdateOwner
parameter_list|(
name|t_Handle
name|h_Manip
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdManipCheckParamsWithCcNodeParams
parameter_list|(
name|t_Handle
name|h_Manip
parameter_list|,
name|t_Handle
name|h_FmPcdCcNode
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline__
name|t_Handle
name|FmPcdGetMuramHandle
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
block|{
name|t_FmPcd
modifier|*
name|p_FmPcd
init|=
operator|(
name|t_FmPcd
operator|*
operator|)
name|h_FmPcd
decl_stmt|;
name|ASSERT_COND
argument_list|(
name|p_FmPcd
argument_list|)
expr_stmt|;
return|return
name|p_FmPcd
operator|->
name|h_FmMuram
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint64_t
name|FmPcdGetMuramPhysBase
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
block|{
name|t_FmPcd
modifier|*
name|p_FmPcd
init|=
operator|(
name|t_FmPcd
operator|*
operator|)
name|h_FmPcd
decl_stmt|;
name|ASSERT_COND
argument_list|(
name|p_FmPcd
argument_list|)
expr_stmt|;
return|return
name|p_FmPcd
operator|->
name|physicalMuramBase
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_PCD_H */
end_comment

end_unit

