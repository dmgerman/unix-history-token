begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_common.h   @Description   FM internal structures and definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_COMMON_H
end_define

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_pcd_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_port_ext.h"
end_include

begin_define
define|#
directive|define
name|CLS_PLAN_NUM_PER_GRP
value|8
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   PCD KG scheme registers */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPcdPlcrInterModuleProfileRegs
block|{
specifier|volatile
name|uint32_t
name|fmpl_pemode
decl_stmt|;
comment|/* 0x090 FMPL_PEMODE - FM Policer Profile Entry Mode*/
specifier|volatile
name|uint32_t
name|fmpl_pegnia
decl_stmt|;
comment|/* 0x094 FMPL_PEGNIA - FM Policer Profile Entry GREEN Next Invoked Action*/
specifier|volatile
name|uint32_t
name|fmpl_peynia
decl_stmt|;
comment|/* 0x098 FMPL_PEYNIA - FM Policer Profile Entry YELLOW Next Invoked Action*/
specifier|volatile
name|uint32_t
name|fmpl_pernia
decl_stmt|;
comment|/* 0x09C FMPL_PERNIA - FM Policer Profile Entry RED Next Invoked Action*/
specifier|volatile
name|uint32_t
name|fmpl_pecir
decl_stmt|;
comment|/* 0x0A0 FMPL_PECIR  - FM Policer Profile Entry Committed Information Rate*/
specifier|volatile
name|uint32_t
name|fmpl_pecbs
decl_stmt|;
comment|/* 0x0A4 FMPL_PECBS  - FM Policer Profile Entry Committed Burst Size*/
specifier|volatile
name|uint32_t
name|fmpl_pepepir_eir
decl_stmt|;
comment|/* 0x0A8 FMPL_PEPIR_EIR - FM Policer Profile Entry Peak/Excess Information Rate*/
specifier|volatile
name|uint32_t
name|fmpl_pepbs_ebs
decl_stmt|;
comment|/* 0x0AC FMPL_PEPBS_EBS - FM Policer Profile Entry Peak/Excess Information Rate*/
specifier|volatile
name|uint32_t
name|fmpl_pelts
decl_stmt|;
comment|/* 0x0B0 FMPL_PELTS  - FM Policer Profile Entry Last TimeStamp*/
specifier|volatile
name|uint32_t
name|fmpl_pects
decl_stmt|;
comment|/* 0x0B4 FMPL_PECTS  - FM Policer Profile Entry Committed Token Status*/
specifier|volatile
name|uint32_t
name|fmpl_pepts_ets
decl_stmt|;
comment|/* 0x0B8 FMPL_PEPTS_ETS - FM Policer Profile Entry Peak/Excess Token Status*/
specifier|volatile
name|uint32_t
name|fmpl_pegpc
decl_stmt|;
comment|/* 0x0BC FMPL_PEGPC  - FM Policer Profile Entry GREEN Packet Counter*/
specifier|volatile
name|uint32_t
name|fmpl_peypc
decl_stmt|;
comment|/* 0x0C0 FMPL_PEYPC  - FM Policer Profile Entry YELLOW Packet Counter*/
specifier|volatile
name|uint32_t
name|fmpl_perpc
decl_stmt|;
comment|/* 0x0C4 FMPL_PERPC  - FM Policer Profile Entry RED Packet Counter */
specifier|volatile
name|uint32_t
name|fmpl_perypc
decl_stmt|;
comment|/* 0x0C8 FMPL_PERYPC - FM Policer Profile Entry Recolored YELLOW Packet Counter*/
specifier|volatile
name|uint32_t
name|fmpl_perrpc
decl_stmt|;
comment|/* 0x0CC FMPL_PERRPC - FM Policer Profile Entry Recolored RED Packet Counter*/
specifier|volatile
name|uint32_t
name|fmpl_res1
index|[
literal|12
index|]
decl_stmt|;
comment|/* 0x0D0-0x0FF Reserved */
block|}
name|_PackedType
name|t_FmPcdPlcrInterModuleProfileRegs
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   PCD KG scheme registers */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPcdKgInterModuleSchemeRegs
block|{
specifier|volatile
name|uint32_t
name|kgse_mode
decl_stmt|;
comment|/**< MODE */
specifier|volatile
name|uint32_t
name|kgse_ekfc
decl_stmt|;
comment|/**< Extract Known Fields Command */
specifier|volatile
name|uint32_t
name|kgse_ekdv
decl_stmt|;
comment|/**< Extract Known Default Value */
specifier|volatile
name|uint32_t
name|kgse_bmch
decl_stmt|;
comment|/**< Bit Mask Command High */
specifier|volatile
name|uint32_t
name|kgse_bmcl
decl_stmt|;
comment|/**< Bit Mask Command Low */
specifier|volatile
name|uint32_t
name|kgse_fqb
decl_stmt|;
comment|/**< Frame Queue Base */
specifier|volatile
name|uint32_t
name|kgse_hc
decl_stmt|;
comment|/**< Hash Command */
specifier|volatile
name|uint32_t
name|kgse_ppc
decl_stmt|;
comment|/**< Policer Profile Command */
specifier|volatile
name|uint32_t
name|kgse_gec
index|[
name|FM_PCD_KG_NUM_OF_GENERIC_REGS
index|]
decl_stmt|;
comment|/**< Generic Extract Command */
specifier|volatile
name|uint32_t
name|kgse_spc
decl_stmt|;
comment|/**< KeyGen Scheme Entry Statistic Packet Counter */
specifier|volatile
name|uint32_t
name|kgse_dv0
decl_stmt|;
comment|/**< KeyGen Scheme Entry Default Value 0 */
specifier|volatile
name|uint32_t
name|kgse_dv1
decl_stmt|;
comment|/**< KeyGen Scheme Entry Default Value 1 */
specifier|volatile
name|uint32_t
name|kgse_ccbs
decl_stmt|;
comment|/**< KeyGen Scheme Entry Coarse Classification Bit*/
specifier|volatile
name|uint32_t
name|kgse_mv
decl_stmt|;
comment|/**< KeyGen Scheme Entry Match vector */
block|}
name|_PackedType
name|t_FmPcdKgInterModuleSchemeRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPcdCcCapwapReassmTimeoutParams
block|{
specifier|volatile
name|uint32_t
name|portIdAndCapwapReassmTbl
decl_stmt|;
specifier|volatile
name|uint32_t
name|fqidForTimeOutFrames
decl_stmt|;
specifier|volatile
name|uint32_t
name|timeoutRequestTime
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdCcCapwapReassmTimeoutParams
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|baseEntry
decl_stmt|;
name|uint16_t
name|numOfClsPlanEntries
decl_stmt|;
name|uint32_t
name|vectors
index|[
name|FM_PCD_MAX_NUM_OF_CLS_PLANS
index|]
decl_stmt|;
block|}
name|t_FmPcdKgInterModuleClsPlanSet
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for binding a port to keygen schemes. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgInterModuleBindPortToSchemes
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
name|uint8_t
name|netEnvId
decl_stmt|;
name|bool
name|useClsPlan
decl_stmt|;
comment|/**< TRUE if this port uses the clsPlan mechanism */
name|uint8_t
name|numOfSchemes
decl_stmt|;
name|uint8_t
name|schemesIds
index|[
name|FM_PCD_KG_NUM_OF_SCHEMES
index|]
decl_stmt|;
block|}
name|t_FmPcdKgInterModuleBindPortToSchemes
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|nextCcNodeInfo
decl_stmt|;
name|t_List
name|node
decl_stmt|;
block|}
name|t_CcNodeInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_CcNode
decl_stmt|;
name|uint16_t
name|index
decl_stmt|;
name|t_List
name|node
decl_stmt|;
block|}
name|t_CcNodeInformation
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CC_NODE_F_OBJECT
parameter_list|(
name|ptr
parameter_list|)
value|LIST_OBJECT(ptr, t_CcNodeInformation, node)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Manip
decl_stmt|;
name|t_List
name|node
decl_stmt|;
block|}
name|t_ManipInfo
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CC_NEXT_NODE_F_OBJECT
parameter_list|(
name|ptr
parameter_list|)
value|LIST_OBJECT(ptr, t_CcNodeInfo, node)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|type
decl_stmt|;
name|uint8_t
name|prOffset
decl_stmt|;
name|uint16_t
name|dataOffset
decl_stmt|;
name|uint8_t
name|poolIndex
decl_stmt|;
name|uint8_t
name|poolIdForManip
decl_stmt|;
name|uint8_t
name|numOfTasks
decl_stmt|;
name|uint8_t
name|hardwarePortId
decl_stmt|;
block|}
name|t_GetCcParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|type
decl_stmt|;
name|int
name|psoSize
decl_stmt|;
name|uint32_t
name|nia
decl_stmt|;
block|}
name|t_SetCcParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_GetCcParams
name|getCcParams
decl_stmt|;
name|t_SetCcParams
name|setCcParams
decl_stmt|;
block|}
name|t_FmPortGetSetCcParams
typedef|;
end_typedef

begin_function
specifier|static
name|__inline__
name|bool
name|TRY_LOCK
parameter_list|(
name|t_Handle
name|h_Spinlock
parameter_list|,
specifier|volatile
name|bool
modifier|*
name|p_Flag
parameter_list|)
block|{
name|uint32_t
name|intFlags
decl_stmt|;
if|if
condition|(
name|h_Spinlock
condition|)
name|intFlags
operator|=
name|XX_LockIntrSpinlock
argument_list|(
name|h_Spinlock
argument_list|)
expr_stmt|;
else|else
name|intFlags
operator|=
name|XX_DisableAllIntr
argument_list|()
expr_stmt|;
if|if
condition|(
operator|*
name|p_Flag
condition|)
block|{
if|if
condition|(
name|h_Spinlock
condition|)
name|XX_UnlockIntrSpinlock
argument_list|(
name|h_Spinlock
argument_list|,
name|intFlags
argument_list|)
expr_stmt|;
else|else
name|XX_RestoreAllIntr
argument_list|(
name|intFlags
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
operator|*
name|p_Flag
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|h_Spinlock
condition|)
name|XX_UnlockIntrSpinlock
argument_list|(
name|h_Spinlock
argument_list|,
name|intFlags
argument_list|)
expr_stmt|;
else|else
name|XX_RestoreAllIntr
argument_list|(
name|intFlags
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_define
define|#
directive|define
name|RELEASE_LOCK
parameter_list|(
name|_flag
parameter_list|)
value|_flag = FALSE;
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   Defines used for manipulation CC and BMI  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|INTERNAL_CONTEXT_OFFSET
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OFFSET_OF_PR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BUFFER_POOL_ID_FOR_MANIP
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NUM_OF_TASKS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|OFFSET_OF_DATA
value|0x08000000
end_define

begin_define
define|#
directive|define
name|HW_PORT_ID
value|0x04000000
end_define

begin_define
define|#
directive|define
name|UPDATE_NIA_PNEN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|UPDATE_PSO
value|0x40000000
end_define

begin_define
define|#
directive|define
name|UPDATE_NIA_PNDN
value|0x20000000
end_define

begin_define
define|#
directive|define
name|UPDATE_FMFP_PRC_WITH_ONE_RISC_ONLY
value|0x10000000
end_define

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   Defines used for manipulation CC and CC  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|UPDATE_NIA_ENQ_WITHOUT_DMA
value|0x80000000
end_define

begin_define
define|#
directive|define
name|UPDATE_CC_WITH_TREE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|UPDATE_CC_WITH_DELETE_TREE
value|0x20000000
end_define

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection   Defines used for enabling/disabling FM interrupts  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_FmBlockErrIntrEnable
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ERR_INTR_EN_DMA
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_FPM
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_BMI
value|0x00800000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_QMI
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_PRS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_KG
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_PLCR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_MURAM
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_IRAM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_10G_MAC0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC0
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC1
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC2
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC3
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_1G_MAC4
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ERR_INTR_EN_MACSEC_MAC0
value|0x00000200
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|t_FmBlockIntrEnable
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INTR_EN_BMI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_QMI
value|0x40000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_PRS
value|0x20000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_KG
value|0x10000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_PLCR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC0_TMR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC1_TMR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC2_TMR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC3_TMR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INTR_EN_1G_MAC4_TMR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTR_EN_REV0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|INTR_EN_REV1
value|0x00004000
end_define

begin_define
define|#
directive|define
name|INTR_EN_REV2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|INTR_EN_REV3
value|0x00001000
end_define

begin_define
define|#
directive|define
name|INTR_EN_BRK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTR_EN_TMR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|INTR_EN_MACSEC_MAC0
value|0x00000001
end_define

begin_comment
comment|/* @} */
end_comment

begin_define
define|#
directive|define
name|FM_MAX_NUM_OF_PORTS
value|(FM_MAX_NUM_OF_OH_PORTS +     \                                  FM_MAX_NUM_OF_1G_RX_PORTS +  \                                  FM_MAX_NUM_OF_10G_RX_PORTS + \                                  FM_MAX_NUM_OF_1G_TX_PORTS +  \                                  FM_MAX_NUM_OF_10G_TX_PORTS)
end_define

begin_define
define|#
directive|define
name|MODULE_NAME_SIZE
value|30
end_define

begin_define
define|#
directive|define
name|DUMMY_PORT_ID
value|0
end_define

begin_define
define|#
directive|define
name|FM_LIODN_OFFSET_MASK
value|0x3FF
end_define

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
name|NIA_ORDER_RESTOR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_FM_CTL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_PRS
value|0x00440000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_KG
value|0x00480000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_PLCR
value|0x004C0000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_BMI
value|0x00500000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_QMI_ENQ
value|0x00540000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_QMI_DEQ
value|0x00580000
end_define

begin_define
define|#
directive|define
name|NIA_ENG_MASK
value|0x007C0000
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_CC
value|0x00000006
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_HC
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_IND_MODE_TX
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_IND_MODE_RX
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_FRAG
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_PRE_FETCH
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_FETCH_PCD
value|0x00000012
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_FETCH_PCD_UDP_LEN
value|0x00000018
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_FETCH_NO_PCD
value|0x00000012
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_FRAG_CHECK
value|0x00000014
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_ENQ_FRAME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_TX_RELEASE
value|0x000002C0
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_RELEASE
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_DISCARD
value|0x000000C1
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_TX
value|0x00000274
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_FETCH
value|0x00000208
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|NIA_KG_DIRECT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NIA_KG_CC_EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NIA_PLCR_ABSOLUTE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NIA_BMI_AC_ENQ_FRAME_WITHOUT_DMA
value|0x00000202
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Port Id defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BASE_OH_PORTID
value|1
end_define

begin_define
define|#
directive|define
name|BASE_1G_RX_PORTID
value|8
end_define

begin_define
define|#
directive|define
name|BASE_10G_RX_PORTID
value|0x10
end_define

begin_define
define|#
directive|define
name|BASE_1G_TX_PORTID
value|0x28
end_define

begin_define
define|#
directive|define
name|BASE_10G_TX_PORTID
value|0x30
end_define

begin_define
define|#
directive|define
name|FM_PCD_PORT_OH_BASE_INDX
value|0
end_define

begin_define
define|#
directive|define
name|FM_PCD_PORT_1G_RX_BASE_INDX
value|(FM_PCD_PORT_OH_BASE_INDX+FM_MAX_NUM_OF_OH_PORTS)
end_define

begin_define
define|#
directive|define
name|FM_PCD_PORT_10G_RX_BASE_INDX
value|(FM_PCD_PORT_1G_RX_BASE_INDX+FM_MAX_NUM_OF_1G_RX_PORTS)
end_define

begin_define
define|#
directive|define
name|FM_PCD_PORT_1G_TX_BASE_INDX
value|(FM_PCD_PORT_10G_RX_BASE_INDX+FM_MAX_NUM_OF_10G_RX_PORTS)
end_define

begin_define
define|#
directive|define
name|FM_PCD_PORT_10G_TX_BASE_INDX
value|(FM_PCD_PORT_1G_TX_BASE_INDX+FM_MAX_NUM_OF_1G_TX_PORTS)
end_define

begin_if
if|#
directive|if
operator|(
name|FM_MAX_NUM_OF_OH_PORTS
operator|>
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|CHECK_PORT_ID_OH_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|if ((_relativePortId)>= FM_MAX_NUM_OF_OH_PORTS)                \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal OH_PORT port id"))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_PORT_ID_OH_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal OH_PORT port id"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|FM_MAX_NUM_OF_1G_RX_PORTS
operator|>
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|CHECK_PORT_ID_1G_RX_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|if ((_relativePortId)>= FM_MAX_NUM_OF_1G_RX_PORTS)                \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 1G_RX_PORT port id"))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_PORT_ID_1G_RX_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 1G_RX_PORT port id"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|FM_MAX_NUM_OF_10G_RX_PORTS
operator|>
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|CHECK_PORT_ID_10G_RX_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|if ((_relativePortId)>= FM_MAX_NUM_OF_10G_RX_PORTS)                \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 10G_RX_PORT port id"))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_PORT_ID_10G_RX_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 10G_RX_PORT port id"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|FM_MAX_NUM_OF_1G_TX_PORTS
operator|>
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|CHECK_PORT_ID_1G_TX_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|if ((_relativePortId)>= FM_MAX_NUM_OF_1G_TX_PORTS)                \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 1G_TX_PORT port id"))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_PORT_ID_1G_TX_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 1G_TX_PORT port id"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|FM_MAX_NUM_OF_10G_TX_PORTS
operator|>
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|CHECK_PORT_ID_10G_TX_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|if ((_relativePortId)>= FM_MAX_NUM_OF_10G_TX_PORTS)                \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 10G_TX_PORT port id"))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECK_PORT_ID_10G_TX_PORTS
parameter_list|(
name|_relativePortId
parameter_list|)
define|\
value|REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 10G_TX_PORT port id"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SW_PORT_ID_TO_HW_PORT_ID
parameter_list|(
name|_port
parameter_list|,
name|_type
parameter_list|,
name|_relativePortId
parameter_list|)
define|\
value|switch(_type) {                                                         \     case(e_FM_PORT_TYPE_OH_OFFLINE_PARSING):                            \     case(e_FM_PORT_TYPE_OH_HOST_COMMAND):                               \         CHECK_PORT_ID_OH_PORTS(_relativePortId);                        \         _port = (uint8_t)(BASE_OH_PORTID + (_relativePortId));          \         break;                                                          \     case(e_FM_PORT_TYPE_RX):                                            \         CHECK_PORT_ID_1G_RX_PORTS(_relativePortId);                     \         _port = (uint8_t)(BASE_1G_RX_PORTID + (_relativePortId));       \         break;                                                          \     case(e_FM_PORT_TYPE_RX_10G):                                        \         CHECK_PORT_ID_10G_RX_PORTS(_relativePortId);                    \         _port = (uint8_t)(BASE_10G_RX_PORTID + (_relativePortId));      \         break;                                                          \     case(e_FM_PORT_TYPE_TX):                                            \         CHECK_PORT_ID_1G_TX_PORTS(_relativePortId);                     \         _port = (uint8_t)(BASE_1G_TX_PORTID + (_relativePortId));       \         break;                                                          \     case(e_FM_PORT_TYPE_TX_10G):                                        \         CHECK_PORT_ID_10G_TX_PORTS(_relativePortId);                    \         _port = (uint8_t)(BASE_10G_TX_PORTID + (_relativePortId));      \         break;                                                          \     default:                                                            \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal port type"));    \         _port = 0;                                                      \         break;                                                          \ }
end_define

begin_define
define|#
directive|define
name|HW_PORT_ID_TO_SW_PORT_ID
parameter_list|(
name|_relativePortId
parameter_list|,
name|hardwarePortId
parameter_list|)
define|\
value|{   if (((hardwarePortId)>= BASE_OH_PORTID)&&                                     \         ((hardwarePortId)< BASE_OH_PORTID+FM_MAX_NUM_OF_OH_PORTS))                 \         _relativePortId = (uint8_t)((hardwarePortId)-BASE_OH_PORTID);               \     else if (((hardwarePortId)>= BASE_10G_TX_PORTID)&&                            \              ((hardwarePortId)< BASE_10G_TX_PORTID+FM_MAX_NUM_OF_10G_TX_PORTS))    \         _relativePortId = (uint8_t)((hardwarePortId)-BASE_10G_TX_PORTID);           \     else if (((hardwarePortId)>= BASE_1G_TX_PORTID)&&                             \              ((hardwarePortId)< BASE_1G_TX_PORTID+FM_MAX_NUM_OF_1G_TX_PORTS))      \         _relativePortId = (uint8_t)((hardwarePortId)-BASE_1G_TX_PORTID);            \     else if (((hardwarePortId)>= BASE_10G_RX_PORTID)&&                            \              ((hardwarePortId)< BASE_10G_RX_PORTID+FM_MAX_NUM_OF_10G_RX_PORTS))    \         _relativePortId = (uint8_t)((hardwarePortId)-BASE_10G_RX_PORTID);           \     else if (((hardwarePortId)>= BASE_1G_RX_PORTID)&&                             \              ((hardwarePortId)< BASE_1G_RX_PORTID+FM_MAX_NUM_OF_1G_RX_PORTS))      \         _relativePortId = (uint8_t)((hardwarePortId)-BASE_1G_RX_PORTID);            \     else {                                                                          \         _relativePortId = (uint8_t)DUMMY_PORT_ID;                                   \         ASSERT_COND(TRUE);                                                          \     }                                                                               \ }
end_define

begin_define
define|#
directive|define
name|HW_PORT_ID_TO_SW_PORT_INDX
parameter_list|(
name|swPortIndex
parameter_list|,
name|hardwarePortId
parameter_list|)
define|\
value|do {                                                                                                        \     if (((hardwarePortId)>= BASE_OH_PORTID)&& ((hardwarePortId)< BASE_OH_PORTID+FM_MAX_NUM_OF_OH_PORTS)) \         swPortIndex = (uint8_t)((hardwarePortId)-BASE_OH_PORTID+FM_PCD_PORT_OH_BASE_INDX);                  \     else if (((hardwarePortId)>= BASE_1G_RX_PORTID)&&                                                     \              ((hardwarePortId)< BASE_1G_RX_PORTID+FM_MAX_NUM_OF_1G_RX_PORTS))                              \         swPortIndex = (uint8_t)((hardwarePortId)-BASE_1G_RX_PORTID+FM_PCD_PORT_1G_RX_BASE_INDX);            \     else if (((hardwarePortId)>= BASE_10G_RX_PORTID)&&                                                    \              ((hardwarePortId)< BASE_10G_RX_PORTID+FM_MAX_NUM_OF_10G_RX_PORTS))                            \         swPortIndex = (uint8_t)((hardwarePortId)-BASE_10G_RX_PORTID+FM_PCD_PORT_10G_RX_BASE_INDX);          \     else if (((hardwarePortId)>= BASE_1G_TX_PORTID)&&                                                     \              ((hardwarePortId)< BASE_1G_TX_PORTID+FM_MAX_NUM_OF_1G_TX_PORTS))                              \         swPortIndex = (uint8_t)((hardwarePortId)-BASE_1G_TX_PORTID+FM_PCD_PORT_1G_TX_BASE_INDX);            \     else if (((hardwarePortId)>= BASE_10G_TX_PORTID)&&                                                    \              ((hardwarePortId)< BASE_10G_TX_PORTID+FM_MAX_NUM_OF_10G_TX_PORTS))                            \         swPortIndex = (uint8_t)((hardwarePortId)-BASE_10G_TX_PORTID+FM_PCD_PORT_10G_TX_BASE_INDX);          \     else ASSERT_COND(FALSE);                                                                                \ } while (0)
end_define

begin_define
define|#
directive|define
name|SW_PORT_INDX_TO_HW_PORT_ID
parameter_list|(
name|hardwarePortId
parameter_list|,
name|swPortIndex
parameter_list|)
define|\
value|do {                                                                                                            \     if (((swPortIndex)>= FM_PCD_PORT_OH_BASE_INDX)&& ((swPortIndex)< FM_PCD_PORT_1G_RX_BASE_INDX))           \         hardwarePortId = (uint8_t)((swPortIndex)-FM_PCD_PORT_OH_BASE_INDX+BASE_OH_PORTID);                      \     else if (((swPortIndex)>= FM_PCD_PORT_1G_RX_BASE_INDX)&& ((swPortIndex)< FM_PCD_PORT_10G_RX_BASE_INDX))  \         hardwarePortId = (uint8_t)((swPortIndex)-FM_PCD_PORT_1G_RX_BASE_INDX+BASE_1G_RX_PORTID);                \     else if (((swPortIndex)>= FM_PCD_PORT_10G_RX_BASE_INDX)&& ((swPortIndex)< FM_MAX_NUM_OF_PORTS))          \         hardwarePortId = (uint8_t)((swPortIndex)-FM_PCD_PORT_10G_RX_BASE_INDX+BASE_10G_RX_PORTID);              \     else if (((swPortIndex)>= FM_PCD_PORT_1G_TX_BASE_INDX)&& ((swPortIndex)< FM_PCD_PORT_10G_TX_BASE_INDX))  \         hardwarePortId = (uint8_t)((swPortIndex)-FM_PCD_PORT_1G_TX_BASE_INDX+BASE_1G_TX_PORTID);                \     else if (((swPortIndex)>= FM_PCD_PORT_10G_TX_BASE_INDX)&& ((swPortIndex)< FM_MAX_NUM_OF_PORTS))          \         hardwarePortId = (uint8_t)((swPortIndex)-FM_PCD_PORT_10G_TX_BASE_INDX+BASE_10G_TX_PORTID);              \     else ASSERT_COND(FALSE);                                                                                    \ } while (0)
end_define

begin_define
define|#
directive|define
name|BMI_FIFO_UNITS
value|0x100
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|f_Isr
function_decl|)
parameter_list|(
name|t_Handle
name|h_Arg
parameter_list|)
function_decl|;
name|t_Handle
name|h_SrcHandle
decl_stmt|;
name|uint8_t
name|guestId
decl_stmt|;
block|}
name|t_FmIntrSrc
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ILLEGAL_HDR_NUM
value|0xFF
end_define

begin_define
define|#
directive|define
name|NO_HDR_NUM
value|FM_PCD_PRS_NUM_OF_HDRS
end_define

begin_define
define|#
directive|define
name|IS_PRIVATE_HEADER
parameter_list|(
name|hdr
parameter_list|)
value|(((hdr) == HEADER_TYPE_USER_DEFINED_SHIM1) ||   \                                              ((hdr) == HEADER_TYPE_USER_DEFINED_SHIM2))
end_define

begin_define
define|#
directive|define
name|IS_SPECIAL_HEADER
parameter_list|(
name|hdr
parameter_list|)
value|((hdr) == HEADER_TYPE_MACSEC)
end_define

begin_define
define|#
directive|define
name|GET_PRS_HDR_NUM
parameter_list|(
name|num
parameter_list|,
name|hdr
parameter_list|)
define|\
value|switch(hdr)                                                 \ {   case(HEADER_TYPE_ETH):              num = 0;  break;    \     case(HEADER_TYPE_LLC_SNAP):         num = 1;  break;    \     case(HEADER_TYPE_VLAN):             num = 2;  break;    \     case(HEADER_TYPE_PPPoE):            num = 3;  break;    \     case(HEADER_TYPE_MPLS):             num = 4;  break;    \     case(HEADER_TYPE_IPv4):             num = 5;  break;    \     case(HEADER_TYPE_IPv6):             num = 6;  break;    \     case(HEADER_TYPE_GRE):              num = 7;  break;    \     case(HEADER_TYPE_MINENCAP):         num = 8;  break;    \     case(HEADER_TYPE_USER_DEFINED_L3):  num = 9;  break;    \     case(HEADER_TYPE_TCP):              num = 10; break;    \     case(HEADER_TYPE_UDP):              num = 11; break;    \     case(HEADER_TYPE_IPSEC_AH):                             \     case(HEADER_TYPE_IPSEC_ESP):        num = 12; break;    \     case(HEADER_TYPE_SCTP):             num = 13; break;    \     case(HEADER_TYPE_DCCP):             num = 14; break;    \     case(HEADER_TYPE_USER_DEFINED_L4):  num = 15; break;    \     case(HEADER_TYPE_USER_DEFINED_SHIM1):                   \     case(HEADER_TYPE_USER_DEFINED_SHIM2):                   \     case(HEADER_TYPE_MACSEC):                               \         num = NO_HDR_NUM; break;                            \     default:                                                \         REPORT_ERROR(MAJOR, E_NOT_SUPPORTED, ("Unsupported header for parser"));\         num = ILLEGAL_HDR_NUM; break;                       \ }
end_define

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Policer defines                                            */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_GO
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_R
value|0x40000000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PNUM_SHIFT
value|16
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
comment|/* maskes */
end_comment

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
name|FM_PCD_KG_KGAR_GO
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_READ
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_WRITE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_SEL_SCHEME_ENTRY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_KG_KGAR_SCHEME_WSEL_UPDATE_CNT
value|0x00008000
end_define

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
value|15
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
value|switch(i) {                                     \     case(0):shift = 26;break;                   \     case(1):shift = 20;break;                   \     case(2):shift = 10;break;                   \     case(3):shift = 4;break;                    \     default:                                    \     RETURN_ERROR(MAJOR, E_INVALID_VALUE, NO_MSG);\ }
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
value|switch(i) {                                     \     case(0):shift = 16;break;                   \     case(1):shift = 0;break;                    \     case(2):shift = 28;break;                   \     case(3):shift = 24;break;                   \     default:                                    \     RETURN_ERROR(MAJOR, E_INVALID_VALUE, NO_MSG);\ }
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
value|switch(i) {                                     \     case(0):shift = 24;break;                   \     case(1):shift = 16;break;                   \     case(2):shift = 8;break;                    \     case(3):shift = 0;break;                    \     default:                                    \     RETURN_ERROR(MAJOR, E_INVALID_VALUE, NO_MSG);\ }
end_define

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_OPTIONS
parameter_list|(
name|clsPlanEntries
parameter_list|)
value|((clsPlanEntries==256)? 8:((clsPlanEntries==128)? 7: ((clsPlanEntries==64)? 6: ((clsPlanEntries==32)? 5:0))))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|num
decl_stmt|;
name|uint8_t
name|hardwarePortId
decl_stmt|;
name|uint16_t
name|plcrProfilesBase
decl_stmt|;
block|}
name|t_FmPortPcdInterModulePlcrParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for initializing a keygen classification plan group */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdKgInterModuleClsPlanGrpParams
block|{
name|uint8_t
name|netEnvId
decl_stmt|;
comment|/* IN */
name|bool
name|grpExists
decl_stmt|;
comment|/* OUT (unused in FmPcdKgBuildClsPlanGrp)*/
name|uint8_t
name|clsPlanGrpId
decl_stmt|;
comment|/* OUT */
name|bool
name|emptyClsPlanGrp
decl_stmt|;
comment|/* OUT */
name|uint8_t
name|numOfOptions
decl_stmt|;
comment|/* OUT in FmPcdGetSetClsPlanGrpParams IN in FmPcdKgBuildClsPlanGrp*/
name|protocolOpt_t
name|options
index|[
name|FM_PCD_MAX_NUM_OF_OPTIONS
argument_list|(
name|FM_PCD_MAX_NUM_OF_CLS_PLANS
argument_list|)
index|]
decl_stmt|;
comment|/* OUT in FmPcdGetSetClsPlanGrpParams IN in FmPcdKgBuildClsPlanGrp*/
name|uint32_t
name|optVectors
index|[
name|FM_PCD_MAX_NUM_OF_OPTIONS
argument_list|(
name|FM_PCD_MAX_NUM_OF_CLS_PLANS
argument_list|)
index|]
decl_stmt|;
comment|/* OUT in FmPcdGetSetClsPlanGrpParams IN in FmPcdKgBuildClsPlanGrp*/
block|}
name|t_FmPcdKgInterModuleClsPlanGrpParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmInterModulePortRxPoolsParams
block|{
name|uint8_t
name|numOfPools
decl_stmt|;
name|uint16_t
name|secondLargestBufSize
decl_stmt|;
name|uint16_t
name|largestBufSize
decl_stmt|;
block|}
name|t_FmInterModulePortRxPoolsParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|t_Error
function_decl|(
name|t_FmPortGetSetCcParamsCallback
function_decl|)
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortGetSetCcParams
modifier|*
name|p_FmPortGetSetCcParams
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|t_Handle
name|FmPcdGetHcHandle
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdGetSwPrsOffset
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|e_NetHeaderType
name|hdr
parameter_list|,
name|uint8_t
name|indexPerHdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdGetLcv
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint32_t
name|netEnvId
parameter_list|,
name|uint8_t
name|hdrNum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdGetMacsecLcv
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint32_t
name|netEnvId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdIncNetEnvOwners
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdDecNetEnvOwners
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdPortRegister
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdLock
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdUnlock
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint32_t
name|intFlags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdNetEnvIsHdrExist
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
name|bool
name|FmPcdIsIpFrag
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcReleaseModifiedDataStructure
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_List
modifier|*
name|h_FmPcdOldPointersLst
parameter_list|,
name|t_List
modifier|*
name|h_FmPcdNewPointersLst
parameter_list|,
name|uint16_t
name|numOfGoodChanges
parameter_list|,
name|t_Handle
modifier|*
name|h_Params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdCcGetNodeAddrOffset
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_Pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcRemoveKey
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPcdCcNode
parameter_list|,
name|uint8_t
name|keyIndex
parameter_list|,
name|t_List
modifier|*
name|h_OldLst
parameter_list|,
name|t_List
modifier|*
name|h_NewLst
parameter_list|,
name|t_Handle
modifier|*
name|h_AdditionalParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcAddKey
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keyIndex
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|t_FmPcdCcKeyParams
modifier|*
name|p_FmPCdCcKeyParams
parameter_list|,
name|t_List
modifier|*
name|h_OldLst
parameter_list|,
name|t_List
modifier|*
name|h_NewLst
parameter_list|,
name|t_Handle
modifier|*
name|h_Params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcModifyKey
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcNode
parameter_list|,
name|uint8_t
name|keyIndex
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|uint8_t
modifier|*
name|p_Key
parameter_list|,
name|uint8_t
modifier|*
name|p_Mask
parameter_list|,
name|t_List
modifier|*
name|h_OldLst
parameter_list|,
name|t_List
modifier|*
name|h_NewLst
parameter_list|,
name|t_Handle
modifier|*
name|h_AdditionalParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcModifyKeyAndNextEngine
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPcdCcNode
parameter_list|,
name|uint8_t
name|keyIndex
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|t_FmPcdCcKeyParams
modifier|*
name|p_FmPcdCcKeyParams
parameter_list|,
name|t_List
modifier|*
name|h_OldLst
parameter_list|,
name|t_List
modifier|*
name|h_NewLst
parameter_list|,
name|t_Handle
modifier|*
name|h_AdditionalParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcModifyMissNextEngineParamNode
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPcdCcNode
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|,
name|t_List
modifier|*
name|h_OldPointer
parameter_list|,
name|t_List
modifier|*
name|h_NewPointer
parameter_list|,
name|t_Handle
modifier|*
name|h_AdditionalParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcModifyNextEngineParamTree
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPcdCcTree
parameter_list|,
name|uint8_t
name|grpId
parameter_list|,
name|uint8_t
name|index
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|,
name|t_List
modifier|*
name|h_OldLst
parameter_list|,
name|t_List
modifier|*
name|h_NewLst
parameter_list|,
name|t_Handle
modifier|*
name|h_AdditionalParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcModiyNextEngineParamNode
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPcdCcNode
parameter_list|,
name|uint8_t
name|keyIndex
parameter_list|,
name|t_FmPcdCcNextEngineParams
modifier|*
name|p_FmPcdCcNextEngineParams
parameter_list|,
name|t_List
modifier|*
name|h_OldPointer
parameter_list|,
name|t_List
modifier|*
name|h_NewPointer
parameter_list|,
name|t_Handle
modifier|*
name|h_AdditionalParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdCcGetNodeAddrOffsetFromNodeInfo
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_Pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcTreeTryLock
parameter_list|(
name|t_Handle
name|h_FmPcdCcTree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcNodeTreeTryLock
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPcdCcNode
parameter_list|,
name|t_List
modifier|*
name|p_List
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdCcTreeReleaseLock
parameter_list|(
name|t_Handle
name|h_FmPcdCcTree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdCcNodeTreeReleaseLock
parameter_list|(
name|t_List
modifier|*
name|p_List
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Handle
name|FmPcdCcTreeGetSavedManipParams
parameter_list|(
name|t_Handle
name|h_FmTree
parameter_list|,
name|uint8_t
name|manipIndx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdCcTreeSetSavedManipParams
parameter_list|(
name|t_Handle
name|h_FmTree
parameter_list|,
name|t_Handle
name|h_SavedManipParams
parameter_list|,
name|uint8_t
name|manipIndx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdKgIsSchemeValidSw
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
name|uint8_t
name|FmPcdKgGetClsPlanGrpBase
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|clsPlanGrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|FmPcdKgGetClsPlanGrpSize
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|clsPlanGrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgBuildScheme
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgSchemeParams
modifier|*
name|p_Scheme
parameter_list|,
name|t_FmPcdKgInterModuleSchemeRegs
modifier|*
name|p_SchemeRegs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgBuildClsPlanGrp
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgInterModuleClsPlanGrpParams
modifier|*
name|p_Grp
parameter_list|,
name|t_FmPcdKgInterModuleClsPlanSet
modifier|*
name|p_ClsPlanSet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmPcdKgGetNumOfPartitionSchemes
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmPcdKgGetPhysicalSchemeId
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
name|uint8_t
name|FmPcdKgGetRelativeSchemeId
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
name|FmPcdKgDestroyClsPlanGrp
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|grpId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdKgValidateSchemeSw
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
name|FmPcdKgInvalidateSchemeSw
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
name|t_Error
name|FmPcdKgCheckInvalidateSchemeSw
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
name|t_Error
name|FmPcdKgBuildBindPortToSchemes
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgInterModuleBindPortToSchemes
modifier|*
name|p_BindPortToSchemes
parameter_list|,
name|uint32_t
modifier|*
name|p_SpReg
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdKgIncSchemeOwners
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgInterModuleBindPortToSchemes
modifier|*
name|p_BindPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdKgDecSchemeOwners
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgInterModuleBindPortToSchemes
modifier|*
name|p_BindPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdKgIsDriverClsPlan
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdKgHwSchemeIsValid
parameter_list|(
name|uint32_t
name|schemeModeReg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgBuildCppReg
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|clsPlanGrpId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgBuildWriteSchemeActionReg
parameter_list|(
name|uint8_t
name|schemeId
parameter_list|,
name|bool
name|updateCounter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgBuildReadSchemeActionReg
parameter_list|(
name|uint8_t
name|schemeId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgBuildWriteClsPlanBlockActionReg
parameter_list|(
name|uint8_t
name|grpId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgBuildReadClsPlanBlockActionReg
parameter_list|(
name|uint8_t
name|grpId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgBuildWritePortSchemeBindActionReg
parameter_list|(
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgBuildReadPortSchemeBindActionReg
parameter_list|(
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgBuildWritePortClsPlanBindActionReg
parameter_list|(
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmPcdKgGetSchemeSwId
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|schemeHwId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgSchemeTryLock
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|schemeId
parameter_list|,
name|bool
name|intr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdKgReleaseSchemeLock
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
name|FmPcdKgUpatePointedOwner
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|schemeId
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgBindPortToSchemes
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgInterModuleBindPortToSchemes
modifier|*
name|p_SchemeBind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgUnbindPortToSchemes
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdKgInterModuleBindPortToSchemes
modifier|*
name|p_SchemeBind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdKgGetRequiredAction
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
name|uint32_t
name|FmPcdKgGetPointedOwners
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
name|e_FmPcdDoneAction
name|FmPcdKgGetDoneAction
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
name|e_FmPcdEngine
name|FmPcdKgGetNextEngine
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
name|FmPcdKgUpdateRequiredAction
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|schemeId
parameter_list|,
name|uint32_t
name|requiredAction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdKgIsDirectPlcr
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
name|bool
name|FmPcdKgIsDistrOnPlcrProfile
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
name|uint16_t
name|FmPcdKgGetRelativeProfileId
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|schemeId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FM-PCD parser API routines */
end_comment

begin_function_decl
name|t_Error
name|FmPcdPrsIncludePortInStatistics
parameter_list|(
name|t_Handle
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

begin_comment
comment|/* FM-PCD policer API routines */
end_comment

begin_function_decl
name|t_Error
name|FmPcdPlcrAllocProfiles
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint16_t
name|numOfProfiles
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdPlcrFreeProfiles
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdPlcrIsProfileValid
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|FmPcdPlcrGetPortProfilesBase
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|FmPcdPlcrGetPortNumOfProfiles
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdPlcrBuildWritePlcrActionRegs
parameter_list|(
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdPlcrBuildCounterProfileReg
parameter_list|(
name|e_FmPcdPlcrProfileCounters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdPlcrBuildWritePlcrActionReg
parameter_list|(
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdPlcrBuildReadPlcrActionReg
parameter_list|(
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdPlcrBuildProfile
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_FmPcdPlcrProfileParams
modifier|*
name|p_Profile
parameter_list|,
name|t_FmPcdPlcrInterModuleProfileRegs
modifier|*
name|p_PlcrRegs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdPlcrGetAbsoluteProfileId
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|e_FmPcdProfileTypeSelection
name|profileType
parameter_list|,
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint16_t
name|relativeProfile
parameter_list|,
name|uint16_t
modifier|*
name|p_AbsoluteId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdPlcrInvalidateProfileSw
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdPlcrValidateProfileSw
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdPlcrHwProfileIsValid
parameter_list|(
name|uint32_t
name|profileModeReg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdPlcrProfileTryLock
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|profileId
parameter_list|,
name|bool
name|intr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdPlcrReleaseProfileLock
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|profileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdPlcrGetRequiredAction
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdPlcrGetPointedOwners
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdPlcrUpatePointedOwner
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdPlcrBuildNiaProfileReg
parameter_list|(
name|bool
name|green
parameter_list|,
name|bool
name|yellow
parameter_list|,
name|bool
name|red
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdPlcrUpdateRequiredAction
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|absoluteProfileId
parameter_list|,
name|uint32_t
name|requiredAction
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FM-PCD Coarse-Classification API routines */
end_comment

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
name|uint8_t
name|FmPcdCcGetOffset
parameter_list|(
name|t_Handle
name|h_CcNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdManipUpdate
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_Handle
name|h_Manip
parameter_list|,
name|t_Handle
name|h_Ad
parameter_list|,
name|bool
name|validate
parameter_list|,
name|int
name|level
parameter_list|,
name|t_Handle
name|h_FmTree
parameter_list|,
name|bool
name|modify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPortGetSetCcParams
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortGetSetCcParams
modifier|*
name|p_FmPortGetSetCcParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPcdManipGetRequiredAction
parameter_list|(
name|t_Handle
name|h_Manip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcBindTree
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcTree
parameter_list|,
name|uint32_t
modifier|*
name|p_Offset
parameter_list|,
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcUnbindTree
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_CcTree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdPlcrCcGetSetParams
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint16_t
name|profileIndx
parameter_list|,
name|uint32_t
name|requiredAction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgCcGetSetParams
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_Scheme
parameter_list|,
name|uint32_t
name|requiredAction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmPortGetNetEnvId
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmPortGetHardwarePortId
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmPortGetPcdEngines
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPortPcdKgSwUnbindClsPlanGrp
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPortAttachPCD
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgSetOrBindToClsPlanGrp
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint8_t
name|netEnvId
parameter_list|,
name|protocolOpt_t
modifier|*
name|p_OptArray
parameter_list|,
name|uint8_t
modifier|*
name|p_ClsPlanGrpId
parameter_list|,
name|bool
modifier|*
name|p_IsEmptyClsPlanGrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdKgDeleteOrUnbindPortToClsPlanGrp
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint8_t
name|clsPlanGrpId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmRegisterIntr   @Description   Used to register an inter-module event handler to be processed by FM   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     mod             The module that causes the event  @Param[in]     modId           Module id - if more than 1 instansiation of this                                 mode exists,0 otherwise.  @Param[in]     intrType        Interrupt type (error/normal) selection.  @Param[in]     f_Isr           The interrupt service routine.  @Param[in]     h_Arg           Argument to be passed to f_Isr.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FmRegisterIntr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmEventModules
name|mod
parameter_list|,
name|uint8_t
name|modId
parameter_list|,
name|e_FmIntrType
name|intrType
parameter_list|,
name|void
function_decl|(
modifier|*
name|f_Isr
function_decl|)
parameter_list|(
name|t_Handle
name|h_Arg
parameter_list|)
parameter_list|,
name|t_Handle
name|h_Arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmUnregisterIntr   @Description   Used to un-register an inter-module event handler that was processed by FM   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     mod             The module that causes the event  @Param[in]     modId           Module id - if more than 1 instansiation of this                                 mode exists,0 otherwise.  @Param[in]     intrType        Interrupt type (error/normal) selection.   @Return        None. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FmUnregisterIntr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmEventModules
name|mod
parameter_list|,
name|uint8_t
name|modId
parameter_list|,
name|e_FmIntrType
name|intrType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmRegisterFmCtlIntr   @Description   Used to register to one of the fmCtl events in the FM module   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     eventRegId      FmCtl event id (0-7).  @Param[in]     f_Isr           The interrupt service routine.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FmRegisterFmCtlIntr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|eventRegId
parameter_list|,
name|void
function_decl|(
modifier|*
name|f_Isr
function_decl|)
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint32_t
name|event
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining MAC types */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmMacType
block|{
name|e_FM_MAC_10G
init|=
literal|0
block|,
comment|/**< 10G MAC */
name|e_FM_MAC_1G
comment|/**< 1G MAC */
block|}
name|e_FmMacType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for port-FM communication during FM_PORT_Init.                 Fields commented 'IN' are passed by the port module to be used                 by the FM module.                 Fields commented 'OUT' will be filled by FM before returning to port.                 Some fields are optional (depending on configuration) and                 will be analized by the port and FM modules accordingly. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmInterModulePortInitParams
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
comment|/**< IN. port Id */
name|e_FmPortType
name|portType
decl_stmt|;
comment|/**< IN. Port type */
name|bool
name|independentMode
decl_stmt|;
comment|/**< IN. TRUE if FM Port operates in independent mode */
name|uint16_t
name|liodnOffset
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint8_t
name|numOfTasks
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint8_t
name|numOfExtraTasks
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint8_t
name|numOfOpenDmas
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint8_t
name|numOfExtraOpenDmas
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint32_t
name|sizeOfFifo
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint32_t
name|extraSizeOfFifo
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint8_t
name|deqPipelineDepth
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint16_t
name|liodnBase
decl_stmt|;
comment|/**< IN. Irrelevant for P4080 rev 1.                                                  LIODN base for this port, to be                                                  used together with LIODN offset. */
name|t_FmPhysAddr
name|fmMuramPhysBaseAddr
decl_stmt|;
comment|/**< OUT. FM-MURAM physical address*/
block|}
name|t_FmInterModulePortInitParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for port-FM communication during FM_PORT_Free. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_FmInterModulePortFreeParams
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
comment|/**< IN. port Id */
name|e_FmPortType
name|portType
decl_stmt|;
comment|/**< IN. Port type */
ifdef|#
directive|ifdef
name|FM_QMI_DEQ_OPTIONS_SUPPORT
name|uint8_t
name|deqPipelineDepth
decl_stmt|;
comment|/**< IN. Port's requested resource */
endif|#
directive|endif
comment|/* FM_QMI_DEQ_OPTIONS_SUPPORT */
block|}
name|t_FmInterModulePortFreeParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetPcdPrsBaseAddr   @Description   Get the base address of the Parser from the FM module   @Param[in]     h_Fm            A handle to an FM Module.   @Return        Base address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uintptr_t
name|FmGetPcdPrsBaseAddr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetPcdKgBaseAddr   @Description   Get the base address of the Keygen from the FM module   @Param[in]     h_Fm            A handle to an FM Module.   @Return        Base address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uintptr_t
name|FmGetPcdKgBaseAddr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetPcdPlcrBaseAddr   @Description   Get the base address of the Policer from the FM module   @Param[in]     h_Fm            A handle to an FM Module.   @Return        Base address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uintptr_t
name|FmGetPcdPlcrBaseAddr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetMuramHandle   @Description   Get the handle of the MURAM from the FM module   @Param[in]     h_Fm            A handle to an FM Module.   @Return        MURAM module handle. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Handle
name|FmGetMuramHandle
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetPhysicalMuramBase   @Description   Get the physical base address of the MURAM from the FM module   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     fmPhysAddr      Physical MURAM base   @Return        Physical base address. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FmGetPhysicalMuramBase
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmPhysAddr
modifier|*
name|fmPhysAddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetTimeStampScale   @Description   Used internally by other modules in order to get the timeStamp                 period as requested by the application.   @Param[in]     h_Fm                    A handle to an FM Module.   @Return        TimeStamp period in nanoseconds.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|FmGetTimeStampScale
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmResumeStalledPort   @Description   Used internally by FM port to release a stalled port.   @Param[in]     h_Fm                            A handle to an FM Module.  @Param[in]     hardwarePortId                    HW port id.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmResumeStalledPort
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmIsPortStalled   @Description   Used internally by FM port to read the port's status.   @Param[in]     h_Fm                            A handle to an FM Module.  @Param[in]     hardwarePortId                  HW port id.  @Param[in]     p_IsStalled                     A pointer to the boolean port stalled state   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmIsPortStalled
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|bool
modifier|*
name|p_IsStalled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmResetMac   @Description   Used by MAC driver to reset the MAC registers   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     type            MAC type.  @Param[in]     macId           MAC id - according to type.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmResetMac
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmMacType
name|type
parameter_list|,
name|uint8_t
name|macId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetClockFreq   @Description   Used by MAC driver to get the FM clock frequency   @Param[in]     h_Fm            A handle to an FM Module.   @Return        clock-freq on success; 0 otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint16_t
name|FmGetClockFreq
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetId   @Description   Used by PCD driver to read rhe FM id   @Param[in]     h_Fm            A handle to an FM Module.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint8_t
name|FmGetId
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmGetSetPortParams   @Description   Used by FM-PORT driver to pass and receive parameters between                 PORT and FM modules.   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in,out] p_PortParams    A structure of FM Port parameters.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmGetSetPortParams
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmInterModulePortInitParams
modifier|*
name|p_PortParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmFreePortParams   @Description   Used by FM-PORT driver to free port's resources within the FM.   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in,out] p_PortParams    A structure of FM Port parameters.   @Return        None.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|FmFreePortParams
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmInterModulePortFreeParams
modifier|*
name|p_PortParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FmSetPortToWorkWithOneRiscOnly   @Description   Used by FM-PORT driver to pass parameter between                 PORT and FM modules for working with number of RISC..   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in,out] p_PortParams    A structure of FM Port parameters.   @Return        None.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmSetNumOfRiscsPerPort
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint8_t
name|numOfFmanCtrls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmRegisterPcd
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmUnregisterPcd
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Handle
name|FmGetPcdHandle
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmRamsEccIsExternalCtl
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmEnableRamsEcc
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmDisableRamsEcc
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmGetRevision
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmRevisionInfo
modifier|*
name|p_FmRevisionInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmAllocFmanCtrlEventReg
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
modifier|*
name|p_EventId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmFreeFmanCtrlEventReg
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|eventId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmSetFmanCtrlIntr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|eventRegId
parameter_list|,
name|uint32_t
name|enableEvents
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|FmGetFmanCtrlIntr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|eventRegId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmRegisterFmanCtrlIntr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|eventRegId
parameter_list|,
name|void
function_decl|(
modifier|*
name|f_Isr
function_decl|)
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint32_t
name|event
parameter_list|)
parameter_list|,
name|t_Handle
name|h_Arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmUnregisterFmanCtrlIntr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|eventRegId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSetMacMaxFrame
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmMacType
name|type
parameter_list|,
name|uint8_t
name|macId
parameter_list|,
name|uint16_t
name|mtu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmIsMaster
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|FmGetGuestId
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FM_TX_ECC_FRMS_ERRATA_10GMAC_A004
end_ifdef

begin_function_decl
name|t_Error
name|Fm10GTxEccWorkaround
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|macId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_TX_ECC_FRMS_ERRATA_10GMAC_A004 */
end_comment

begin_function_decl
name|void
name|FmMuramClear
parameter_list|(
name|t_Handle
name|h_FmMuram
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSetNumOfOpenDmas
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint8_t
name|numOfOpenDmas
parameter_list|,
name|uint8_t
name|numOfExtraOpenDmas
parameter_list|,
name|bool
name|initialConfig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSetNumOfTasks
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|uint8_t
name|numOfTasks
parameter_list|,
name|uint8_t
name|numOfExtraTasks
parameter_list|,
name|bool
name|initialConfig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSetSizeOfFifo
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|,
name|e_FmPortType
name|portType
parameter_list|,
name|bool
name|independentMode
parameter_list|,
name|uint32_t
modifier|*
name|p_SizeOfFifo
parameter_list|,
name|uint32_t
name|extraSizeOfFifo
parameter_list|,
name|uint8_t
name|deqPipelineDepth
parameter_list|,
name|t_FmInterModulePortRxPoolsParams
modifier|*
name|p_RxPoolsParams
parameter_list|,
name|bool
name|initialConfig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_COMMON_H */
end_comment

end_unit

