begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|"fm_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_port_ext.h"
end_include

begin_define
define|#
directive|define
name|e_FM_PORT_TYPE_OH_HOST_COMMAND
value|e_FM_PORT_TYPE_DUMMY
end_define

begin_define
define|#
directive|define
name|CLS_PLAN_NUM_PER_GRP
value|8
end_define

begin_define
define|#
directive|define
name|IP_OFFLOAD_PACKAGE_NUMBER
value|106
end_define

begin_define
define|#
directive|define
name|CAPWAP_OFFLOAD_PACKAGE_NUMBER
value|108
end_define

begin_define
define|#
directive|define
name|IS_OFFLOAD_PACKAGE
parameter_list|(
name|num
parameter_list|)
value|((num == IP_OFFLOAD_PACKAGE_NUMBER) || (num == CAPWAP_OFFLOAD_PACKAGE_NUMBER))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Modules registers offsets */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_MM_MURAM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FM_MM_BMI
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FM_MM_QMI
value|0x00080400
end_define

begin_define
define|#
directive|define
name|FM_MM_PRS
value|0x000c7000
end_define

begin_define
define|#
directive|define
name|FM_MM_KG
value|0x000C1000
end_define

begin_define
define|#
directive|define
name|FM_MM_DMA
value|0x000C2000
end_define

begin_define
define|#
directive|define
name|FM_MM_FPM
value|0x000C3000
end_define

begin_define
define|#
directive|define
name|FM_MM_PLCR
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|FM_MM_IMEM
value|0x000C4000
end_define

begin_define
define|#
directive|define
name|FM_MM_CGP
value|0x000DB000
end_define

begin_define
define|#
directive|define
name|FM_MM_TRB
parameter_list|(
name|i
parameter_list|)
value|(0x000D0200 + 0x400 * (i))
end_define

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
name|FM_MM_SP
value|0x000dc000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for inter-module interrupts registration */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmEventModules
block|{
name|e_FM_MOD_PRS
block|,
comment|/**< Parser event */
name|e_FM_MOD_KG
block|,
comment|/**< Keygen event */
name|e_FM_MOD_PLCR
block|,
comment|/**< Policer event */
name|e_FM_MOD_10G_MAC
block|,
comment|/**< 10G MAC event */
name|e_FM_MOD_1G_MAC
block|,
comment|/**< 1G MAC event */
name|e_FM_MOD_TMR
block|,
comment|/**< Timer event */
name|e_FM_MOD_FMAN_CTRL
block|,
comment|/**< FMAN Controller  Timer event */
name|e_FM_MOD_MACSEC
block|,
name|e_FM_MOD_DUMMY_LAST
block|}
name|e_FmEventModules
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for interrupts types */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmIntrType
block|{
name|e_FM_INTR_TYPE_ERR
block|,
name|e_FM_INTR_TYPE_NORMAL
block|}
name|e_FmIntrType
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for inter-module interrupts registration */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_FmInterModuleEvent
block|{
name|e_FM_EV_PRS
init|=
literal|0
block|,
comment|/**< Parser event */
name|e_FM_EV_ERR_PRS
block|,
comment|/**< Parser error event */
name|e_FM_EV_KG
block|,
comment|/**< Keygen event */
name|e_FM_EV_ERR_KG
block|,
comment|/**< Keygen error event */
name|e_FM_EV_PLCR
block|,
comment|/**< Policer event */
name|e_FM_EV_ERR_PLCR
block|,
comment|/**< Policer error event */
name|e_FM_EV_ERR_10G_MAC0
block|,
comment|/**< 10G MAC 0 error event */
name|e_FM_EV_ERR_10G_MAC1
block|,
comment|/**< 10G MAC 1 error event */
name|e_FM_EV_ERR_1G_MAC0
block|,
comment|/**< 1G MAC 0 error event */
name|e_FM_EV_ERR_1G_MAC1
block|,
comment|/**< 1G MAC 1 error event */
name|e_FM_EV_ERR_1G_MAC2
block|,
comment|/**< 1G MAC 2 error event */
name|e_FM_EV_ERR_1G_MAC3
block|,
comment|/**< 1G MAC 3 error event */
name|e_FM_EV_ERR_1G_MAC4
block|,
comment|/**< 1G MAC 4 error event */
name|e_FM_EV_ERR_1G_MAC5
block|,
comment|/**< 1G MAC 5 error event */
name|e_FM_EV_ERR_1G_MAC6
block|,
comment|/**< 1G MAC 6 error event */
name|e_FM_EV_ERR_1G_MAC7
block|,
comment|/**< 1G MAC 7 error event */
name|e_FM_EV_ERR_MACSEC_MAC0
block|,
name|e_FM_EV_TMR
block|,
comment|/**< Timer event */
name|e_FM_EV_10G_MAC0
block|,
comment|/**< 10G MAC 0 event (Magic packet detection)*/
name|e_FM_EV_10G_MAC1
block|,
comment|/**< 10G MAC 1 event (Magic packet detection)*/
name|e_FM_EV_1G_MAC0
block|,
comment|/**< 1G MAC 0 event (Magic packet detection)*/
name|e_FM_EV_1G_MAC1
block|,
comment|/**< 1G MAC 1 event (Magic packet detection)*/
name|e_FM_EV_1G_MAC2
block|,
comment|/**< 1G MAC 2 (Magic packet detection)*/
name|e_FM_EV_1G_MAC3
block|,
comment|/**< 1G MAC 3 (Magic packet detection)*/
name|e_FM_EV_1G_MAC4
block|,
comment|/**< 1G MAC 4 (Magic packet detection)*/
name|e_FM_EV_1G_MAC5
block|,
comment|/**< 1G MAC 5 (Magic packet detection)*/
name|e_FM_EV_1G_MAC6
block|,
comment|/**< 1G MAC 6 (Magic packet detection)*/
name|e_FM_EV_1G_MAC7
block|,
comment|/**< 1G MAC 7 (Magic packet detection)*/
name|e_FM_EV_MACSEC_MAC0
block|,
comment|/**< MACSEC MAC 0 event */
name|e_FM_EV_FMAN_CTRL_0
block|,
comment|/**< Fman controller event 0 */
name|e_FM_EV_FMAN_CTRL_1
block|,
comment|/**< Fman controller event 1 */
name|e_FM_EV_FMAN_CTRL_2
block|,
comment|/**< Fman controller event 2 */
name|e_FM_EV_FMAN_CTRL_3
block|,
comment|/**< Fman controller event 3 */
name|e_FM_EV_DUMMY_LAST
block|}
name|e_FmInterModuleEvent
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
name|t_FmPcdPlcrProfileRegs
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
name|t_FmPcdPlcrProfileRegs
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   PCD CTRL Parameters Page */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmPcdCtrlParamsPage
block|{
specifier|volatile
name|uint8_t
name|reserved0
index|[
literal|16
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|iprIpv4Nia
decl_stmt|;
specifier|volatile
name|uint32_t
name|iprIpv6Nia
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|24
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|ipfOptionsCounter
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved2
index|[
literal|12
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|misc
decl_stmt|;
specifier|volatile
name|uint32_t
name|errorsDiscardMask
decl_stmt|;
specifier|volatile
name|uint32_t
name|discardMask
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved3
index|[
literal|4
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|postBmiFetchNia
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved4
index|[
literal|172
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FmPcdCtrlParamsPage
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
comment|/*for UNDER_CONSTRUCTION_FM_RMU_USE_SEC its defined in fm_ext.h*/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_FmFmanCtrl
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FPM_PORT_FM_CTL1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FPM_PORT_FM_CTL2
value|0x00000002
end_define

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcFragScratchPoolCmdParams
block|{
name|uint32_t
name|numOfBuffers
decl_stmt|;
name|uint8_t
name|bufferPoolId
decl_stmt|;
block|}
name|t_FmPcdCcFragScratchPoolCmdParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmPcdCcReassmTimeoutParams
block|{
name|bool
name|activate
decl_stmt|;
name|uint8_t
name|tsbs
decl_stmt|;
name|uint32_t
name|iprcpt
decl_stmt|;
block|}
name|t_FmPcdCcReassmTimeoutParams
typedef|;
end_typedef

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
value|NCSW_LIST_OBJECT(ptr, t_CcNodeInformation, node)
end_define

begin_typedef
typedef|typedef
enum|enum
name|e_ModifyState
block|{
name|e_MODIFY_STATE_ADD
init|=
literal|0
block|,
name|e_MODIFY_STATE_REMOVE
block|,
name|e_MODIFY_STATE_CHANGE
block|}
name|e_ModifyState
typedef|;
end_typedef

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
value|NCSW_LIST_OBJECT(ptr, t_CcNodeInfo, node)
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
name|internalBufferOffset
decl_stmt|;
name|uint8_t
name|numOfTasks
decl_stmt|;
name|uint8_t
name|numOfExtraTasks
decl_stmt|;
name|uint8_t
name|hardwarePortId
decl_stmt|;
name|t_FmRevisionInfo
name|revInfo
decl_stmt|;
name|uint32_t
name|nia
decl_stmt|;
name|uint32_t
name|discardMask
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
name|t_FmFmanCtrl
name|orFmanCtrl
decl_stmt|;
name|bool
name|overwrite
decl_stmt|;
name|uint8_t
name|ofpDpde
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|type
decl_stmt|;
name|bool
name|sleep
decl_stmt|;
block|}
name|t_FmSetParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|fmqm_gs
decl_stmt|;
name|uint32_t
name|fm_npi
decl_stmt|;
name|uint32_t
name|fm_cld
decl_stmt|;
name|uint32_t
name|fmfp_extc
decl_stmt|;
block|}
name|t_FmGetParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmSetParams
name|setParams
decl_stmt|;
name|t_FmGetParams
name|getParams
decl_stmt|;
block|}
name|t_FmGetSetParams
typedef|;
end_typedef

begin_function_decl
name|t_Error
name|FmGetSetParams
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmGetSetParams
modifier|*
name|p_Params
parameter_list|)
function_decl|;
end_function_decl

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
name|MANIP_EXTRA_SPACE
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
name|FM_REV
value|0x02000000
end_define

begin_define
define|#
directive|define
name|GET_NIA_FPNE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|GET_NIA_PNDN
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NUM_OF_EXTRA_TASKS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DISCARD_MASK
value|0x00200000
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

begin_define
define|#
directive|define
name|UPDATE_OFP_DPTE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|UPDATE_NIA_FENE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|UPDATE_NIA_CMNE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|UPDATE_NIA_FPNE
value|0x01000000
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

begin_define
define|#
directive|define
name|UPDATE_KG_NIA_CC_WA
value|0x10000000
end_define

begin_define
define|#
directive|define
name|UPDATE_KG_OPT_MODE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|UPDATE_KG_NIA
value|0x04000000
end_define

begin_define
define|#
directive|define
name|UPDATE_CC_SHADOW_CLEAR
value|0x02000000
end_define

begin_comment
comment|/* @} */
end_comment

begin_define
define|#
directive|define
name|UPDATE_FPM_BRKC_SLP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|UPDATE_FPM_EXTC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|UPDATE_FPM_EXTC_CLEAR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|GET_FMQM_GS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|GET_FM_NPI
value|0x08000000
end_define

begin_define
define|#
directive|define
name|GET_FMFP_EXTC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CLEAR_IRAM_READY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|UPDATE_FM_CLD
value|0x01000000
end_define

begin_define
define|#
directive|define
name|GET_FM_CLD
value|0x00800000
end_define

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
name|NIA_ENG_MASK
value|0x007C0000
end_define

begin_define
define|#
directive|define
name|NIA_AC_MASK
value|0x0003ffff
end_define

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
name|NIA_FM_CTL_AC_POP_TO_N_STEP
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_PRE_BMI_FETCH_HEADER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_PRE_BMI_FETCH_FULL_FRAME
value|0x00000018
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_BMI_FETCH
value|0x00000012
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_PRE_BMI_ENQ_FRAME
value|0x0000001A
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_PRE_BMI_DISCARD_FRAME
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_BMI_ENQ_ORR
value|0x00000014
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_BMI_ENQ
value|0x00000022
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_PRE_CC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_POST_TX
value|0x00000024
end_define

begin_comment
comment|/* V3 only */
end_comment

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_NO_IPACC_PRE_BMI_ENQ_FRAME
value|0x00000028
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_NO_IPACC_PRE_BMI_DISCARD_FRAME
value|0x0000002A
end_define

begin_define
define|#
directive|define
name|NIA_FM_CTL_AC_NO_IPACC_POP_TO_N_STEP
value|0x0000002C
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FM_OP_NO_VSP_NO_RELEASE_ERRATA_FMAN_A006675
argument_list|)
operator|||
name|defined
argument_list|(
name|FM_ERROR_VSP_NO_MATCH_SW006
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_NIA_BMI_AC_ENQ_FRAME
parameter_list|(
name|h_FmPcd
parameter_list|)
define|\
value|(uint32_t)((FmPcdIsAdvancedOffloadSupported(h_FmPcd)) ? \                 (NIA_ENG_FM_CTL | NIA_FM_CTL_AC_PRE_BMI_ENQ_FRAME) : \                 (NIA_ENG_FM_CTL | NIA_FM_CTL_AC_NO_IPACC_PRE_BMI_ENQ_FRAME))
end_define

begin_define
define|#
directive|define
name|GET_NIA_BMI_AC_DISCARD_FRAME
parameter_list|(
name|h_FmPcd
parameter_list|)
define|\
value|(uint32_t)((FmPcdIsAdvancedOffloadSupported(h_FmPcd)) ? \                 (NIA_ENG_FM_CTL | NIA_FM_CTL_AC_PRE_BMI_DISCARD_FRAME) : \                 (NIA_ENG_FM_CTL | NIA_FM_CTL_AC_NO_IPACC_PRE_BMI_DISCARD_FRAME))
end_define

begin_define
define|#
directive|define
name|GET_NO_PCD_NIA_BMI_AC_ENQ_FRAME
parameter_list|()
define|\
value|(NIA_ENG_FM_CTL | NIA_FM_CTL_AC_NO_IPACC_PRE_BMI_ENQ_FRAME)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_NIA_BMI_AC_ENQ_FRAME
parameter_list|(
name|h_FmPcd
parameter_list|)
define|\
value|(uint32_t)((FmPcdIsAdvancedOffloadSupported(h_FmPcd)) ? \                 (NIA_ENG_FM_CTL | NIA_FM_CTL_AC_PRE_BMI_ENQ_FRAME) : \                 (NIA_ENG_BMI | NIA_BMI_AC_ENQ_FRAME))
end_define

begin_define
define|#
directive|define
name|GET_NIA_BMI_AC_DISCARD_FRAME
parameter_list|(
name|h_FmPcd
parameter_list|)
define|\
value|(uint32_t)((FmPcdIsAdvancedOffloadSupported(h_FmPcd)) ? \                 (NIA_ENG_FM_CTL | NIA_FM_CTL_AC_PRE_BMI_DISCARD_FRAME) : \                 (NIA_ENG_BMI | NIA_BMI_AC_DISCARD))
end_define

begin_define
define|#
directive|define
name|GET_NO_PCD_NIA_BMI_AC_ENQ_FRAME
parameter_list|()
define|\
value|(NIA_ENG_BMI | NIA_BMI_AC_ENQ_FRAME)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FM_OP_NO_VSP_NO_RELEASE_ERRATA_FMAN_A006675) || ... */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**   @Description        CTRL Parameters Page defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_CTL_PARAMS_PAGE_OP_FIX_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_CTL_PARAMS_PAGE_OFFLOAD_SUPPORT_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_CTL_PARAMS_PAGE_ALWAYS_ON
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FM_CTL_PARAMS_PAGE_ERROR_VSP_MASK
value|0x0000003f
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

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
end_if

begin_define
define|#
directive|define
name|BASE_OH_PORTID
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BASE_OH_PORTID
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION == 10) */
end_comment

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
value|if ((_relativePortId)>= FM_MAX_NUM_OF_1G_RX_PORTS)             \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 1G_RX_PORT port id"))
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
value|if ((_relativePortId)>= FM_MAX_NUM_OF_10G_RX_PORTS)            \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 10G_RX_PORT port id"))
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
value|if ((_relativePortId)>= FM_MAX_NUM_OF_1G_TX_PORTS)             \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 1G_TX_PORT port id"))
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
value|if ((_relativePortId)>= FM_MAX_NUM_OF_10G_TX_PORTS)            \         REPORT_ERROR(MAJOR, E_INVALID_VALUE, ("Illegal 10G_TX_PORT port id"))
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

begin_function_decl
name|uint8_t
name|SwPortIdToHwPortId
parameter_list|(
name|e_FmPortType
name|type
parameter_list|,
name|uint8_t
name|relativePortId
parameter_list|,
name|uint8_t
name|majorRev
parameter_list|,
name|uint8_t
name|minorRev
parameter_list|)
function_decl|;
end_function_decl

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
name|BMI_MAX_FIFO_SIZE
value|(FM_MURAM_SIZE)
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

begin_function
specifier|static
name|__inline__
name|uint8_t
name|GetPrsHdrNum
parameter_list|(
name|e_NetHeaderType
name|hdr
parameter_list|)
block|{
switch|switch
condition|(
name|hdr
condition|)
block|{
case|case
operator|(
name|HEADER_TYPE_ETH
operator|)
case|:
return|return
literal|0
return|;
case|case
operator|(
name|HEADER_TYPE_LLC_SNAP
operator|)
case|:
return|return
literal|1
return|;
case|case
operator|(
name|HEADER_TYPE_VLAN
operator|)
case|:
return|return
literal|2
return|;
case|case
operator|(
name|HEADER_TYPE_PPPoE
operator|)
case|:
return|return
literal|3
return|;
case|case
operator|(
name|HEADER_TYPE_PPP
operator|)
case|:
return|return
literal|3
return|;
case|case
operator|(
name|HEADER_TYPE_MPLS
operator|)
case|:
return|return
literal|4
return|;
case|case
operator|(
name|HEADER_TYPE_IPv4
operator|)
case|:
return|return
literal|5
return|;
case|case
operator|(
name|HEADER_TYPE_IPv6
operator|)
case|:
return|return
literal|6
return|;
case|case
operator|(
name|HEADER_TYPE_GRE
operator|)
case|:
return|return
literal|7
return|;
case|case
operator|(
name|HEADER_TYPE_MINENCAP
operator|)
case|:
return|return
literal|8
return|;
case|case
operator|(
name|HEADER_TYPE_USER_DEFINED_L3
operator|)
case|:
return|return
literal|9
return|;
case|case
operator|(
name|HEADER_TYPE_TCP
operator|)
case|:
return|return
literal|10
return|;
case|case
operator|(
name|HEADER_TYPE_UDP
operator|)
case|:
return|return
literal|11
return|;
case|case
operator|(
name|HEADER_TYPE_IPSEC_AH
operator|)
case|:
case|case
operator|(
name|HEADER_TYPE_IPSEC_ESP
operator|)
case|:
return|return
literal|12
return|;
case|case
operator|(
name|HEADER_TYPE_SCTP
operator|)
case|:
return|return
literal|13
return|;
case|case
operator|(
name|HEADER_TYPE_DCCP
operator|)
case|:
return|return
literal|14
return|;
case|case
operator|(
name|HEADER_TYPE_USER_DEFINED_L4
operator|)
case|:
return|return
literal|15
return|;
case|case
operator|(
name|HEADER_TYPE_USER_DEFINED_SHIM1
operator|)
case|:
case|case
operator|(
name|HEADER_TYPE_USER_DEFINED_SHIM2
operator|)
case|:
case|case
operator|(
name|HEADER_TYPE_MACSEC
operator|)
case|:
return|return
name|NO_HDR_NUM
return|;
default|default:
return|return
name|ILLEGAL_HDR_NUM
return|;
block|}
block|}
end_function

begin_define
define|#
directive|define
name|FM_PCD_MAX_NUM_OF_OPTIONS
parameter_list|(
name|clsPlanEntries
parameter_list|)
value|((clsPlanEntries==256)? 8:((clsPlanEntries==128)? 7: ((clsPlanEntries==64)? 6: ((clsPlanEntries==32)? 5:0))))
end_define

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
name|t_FmPcdLock
block|{
name|t_Handle
name|h_Spinlock
decl_stmt|;
specifier|volatile
name|bool
name|flag
decl_stmt|;
name|t_List
name|node
decl_stmt|;
block|}
name|t_FmPcdLock
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FM_PCD_LOCK_OBJ
parameter_list|(
name|ptr
parameter_list|)
value|NCSW_LIST_OBJECT(ptr, t_FmPcdLock, node)
end_define

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

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Common API for FM-PCD module                               */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

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
name|uint8_t
name|FmPcdGetNetEnvId
parameter_list|(
name|t_Handle
name|h_NetEnv
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
name|t_Error
name|FmPcdFragHcScratchPoolInit
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|scratchBpid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdRegisterReassmPort
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_IpReasmCommonPramTbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdUnregisterReassmPort
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_IpReasmCommonPramTbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdIsAdvancedOffloadSupported
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdLockTryLockAll
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPcdLockUnlockAll
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdHcSync
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Handle
name|FmGetPcd
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Common API for FM-PCD KG module                            */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

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
name|FmPcdKgGetSchemeId
parameter_list|(
name|t_Handle
name|h_Scheme
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_function_decl
name|bool
name|FmPcdKgGetVspe
parameter_list|(
name|t_Handle
name|h_Scheme
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

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
name|t_Error
name|FmPcdKgCheckInvalidateSchemeSw
parameter_list|(
name|t_Handle
name|h_Scheme
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
name|bool
name|FmPcdKgIsSchemeValidSw
parameter_list|(
name|t_Handle
name|h_Scheme
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
name|FmPcdKgGetRequiredActionFlag
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
name|h_Scheme
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

begin_function_decl
name|t_Handle
name|FmPcdKgGetSchemeHandle
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|uint8_t
name|relativeSchemeId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FmPcdKgIsSchemeHasOwners
parameter_list|(
name|t_Handle
name|h_Scheme
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
parameter_list|,
name|uint32_t
name|value
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
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Common API for FM-PCD parser module                        */
end_comment

begin_comment
comment|/***********************************************************************/
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
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Common API for FM-PCD policer module                       */
end_comment

begin_comment
comment|/***********************************************************************/
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
name|uint16_t
name|FmPcdPlcrProfileGetAbsoluteId
parameter_list|(
name|t_Handle
name|h_Profile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdPlcrGetAbsoluteIdByProfileParams
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
name|FmPcdPlcrGetRequiredActionFlag
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

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Common API for FM-PCD CC module                            */
end_comment

begin_comment
comment|/***********************************************************************/
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
name|FmPcdCcRemoveKey
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPcdCcNode
parameter_list|,
name|uint16_t
name|keyIndex
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
name|uint16_t
name|keyIndex
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|t_FmPcdCcKeyParams
modifier|*
name|p_FmPCdCcKeyParams
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
name|uint16_t
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
name|uint16_t
name|keyIndex
parameter_list|,
name|uint8_t
name|keySize
parameter_list|,
name|t_FmPcdCcKeyParams
modifier|*
name|p_FmPcdCcKeyParams
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
name|t_Handle
name|FmPcdCcTreeGetSavedManipParams
parameter_list|(
name|t_Handle
name|h_FmTree
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcTreeAddIPR
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmTree
parameter_list|,
name|t_Handle
name|h_NetEnv
parameter_list|,
name|t_Handle
name|h_ReassemblyManip
parameter_list|,
name|bool
name|schemes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPcdCcTreeAddCPR
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmTree
parameter_list|,
name|t_Handle
name|h_NetEnv
parameter_list|,
name|t_Handle
name|h_ReassemblyManip
parameter_list|,
name|bool
name|schemes
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
name|h_PcdParams
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

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Common API for FM-PCD Manip module                            */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmPcdManipUpdate
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_PcdParams
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

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Common API for FM-Port module                            */
end_comment

begin_comment
comment|/***********************************************************************/
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

begin_typedef
typedef|typedef
enum|enum
name|e_FmPortGprFuncType
block|{
name|e_FM_PORT_GPR_EMPTY
init|=
literal|0
block|,
name|e_FM_PORT_GPR_MURAM_PAGE
block|}
name|e_FmPortGprFuncType
typedef|;
end_typedef

begin_function_decl
name|t_Error
name|FmPortSetGprFunc
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|e_FmPortGprFuncType
name|gprFunc
parameter_list|,
name|void
modifier|*
modifier|*
name|p_Value
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DPAA_VERSION>= 11) */
end_comment

begin_function_decl
name|t_Error
name|FmGetSetParams
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|t_FmGetSetParams
modifier|*
name|p_FmGetSetParams
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

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_function_decl
name|t_Error
name|FmPcdFrmReplicUpdate
parameter_list|(
name|t_Handle
name|h_FmPcd
parameter_list|,
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_Handle
name|h_FrmReplic
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

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
name|maxFrameLength
decl_stmt|;
comment|/**< IN. Port's max frame length. */
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
name|uint8_t
name|deqPipelineDepth
decl_stmt|;
comment|/**< IN. Port's requested resource */
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
comment|/**  @Function      FmGetTimeStampScale   @Description   Used internally by other modules in order to get the timeStamp                 period as requested by the application.                  This function returns bit number that is incremented every 1 usec.                 To calculate timestamp period in nsec, use                 1000 / (1<< FmGetTimeStampScale()).   @Param[in]     h_Fm                    A handle to an FM Module.   @Return        Bit that counts 1 usec.   @Cautions      Allowed only following FM_Init(). */
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
comment|/**  @Function      FmGetMacClockFreq   @Description   Used by MAC driver to get the MAC clock frequency   @Param[in]     h_Fm            A handle to an FM Module.   @Return        clock-freq on success; 0 otherwise.   @Cautions      Allowed only following FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint16_t
name|FmGetMacClockFreq
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
comment|/**  @Function      FmReset   @Description   Used to reset the FM   @Param[in]     h_Fm            A handle to an FM Module.   @Return        E_OK on success; Error code otherwise. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmReset
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
comment|/**  @Function      FmSetNumOfRiscsPerPort   @Description   Used by FM-PORT driver to pass parameter between                 PORT and FM modules for working with number of RISC..   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     hardwarePortId    hardware port Id.  @Param[in]     numOfFmanCtrls    number of Fman Controllers.  @Param[in]     orFmanCtrl        Fman Controller for order restoration.   @Return        None.   @Cautions      Allowed only following FM_Init(). */
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
parameter_list|,
name|t_FmFmanCtrl
name|orFmanCtrl
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|DEBUG_ERRORS
argument_list|)
operator|&&
operator|(
name|DEBUG_ERRORS
operator|>
literal|0
operator|)
operator|)
end_if

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Function      FmDumpPortRegs   @Description   Dumps FM port registers which are part of FM common registers   @Param[in]     h_Fm            A handle to an FM Module.  @Param[in]     hardwarePortId    HW port id.   @Return        E_OK on success; Error code otherwise.   @Cautions      Allowed only FM_Init(). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|t_Error
name|FmDumpPortRegs
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|hardwarePortId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(DEBUG_ERRORS)&& ... */
end_comment

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

begin_function_decl
name|uint16_t
name|FmGetTnumAgingPeriod
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSetPortPreFetchConfiguration
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|portNum
parameter_list|,
name|bool
name|preFetchConfigured
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmGetPortPreFetchConfiguration
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint8_t
name|portNum
parameter_list|,
name|bool
modifier|*
name|p_PortConfigured
parameter_list|,
name|bool
modifier|*
name|p_PreFetchConfigured
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
modifier|*
name|p_NumOfOpenDmas
parameter_list|,
name|uint8_t
modifier|*
name|p_NumOfExtraOpenDmas
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
modifier|*
name|p_NumOfTasks
parameter_list|,
name|uint8_t
modifier|*
name|p_NumOfExtraTasks
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
name|uint32_t
modifier|*
name|p_SizeOfFifo
parameter_list|,
name|uint32_t
modifier|*
name|p_ExtraSizeOfFifo
parameter_list|,
name|bool
name|initialConfig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmSetCongestionGroupPFCpriority
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|uint32_t
name|congestionGroupId
parameter_list|,
name|uint8_t
name|priorityBitMap
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
end_if

begin_function_decl
name|t_Error
name|FmVSPAllocForPort
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmPortType
name|portType
parameter_list|,
name|uint8_t
name|portId
parameter_list|,
name|uint8_t
name|numOfStorageProfiles
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmVSPFreeForPort
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmPortType
name|portType
parameter_list|,
name|uint8_t
name|portId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmVSPGetAbsoluteProfileId
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmPortType
name|portType
parameter_list|,
name|uint8_t
name|portId
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
name|t_Error
name|FmVSPCheckRelativeProfile
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|,
name|e_FmPortType
name|portType
parameter_list|,
name|uint8_t
name|portId
parameter_list|,
name|uint16_t
name|relativeProfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintptr_t
name|FmGetVSPBaseAddr
parameter_list|(
name|t_Handle
name|h_Fm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION>= 11) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_COMMON_H */
end_comment

end_unit

