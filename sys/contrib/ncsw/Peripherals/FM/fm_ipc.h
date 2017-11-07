begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @File          fm_ipc.h   @Description   FM Inter-Partition prototypes, structures and definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_IPC_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_IPC_H
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_grp Frame Manager API   @Description   FM API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         FM_IPC_grp FM Inter-Partition messaging Unit   @Description   FM Inter-Partition messaging unit API definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
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

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining MAC types */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure of parameters for specifying a MAC. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|uint8_t
name|id
decl_stmt|;
name|uint32_t
name|enumType
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcMacParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure of parameters for specifying a MAC. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
name|t_FmIpcMacParams
name|macParams
decl_stmt|;
name|uint16_t
name|maxFrameLength
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcMacMaxFrameParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   FM physical Address */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcPhysAddr
block|{
specifier|volatile
name|uint8_t
name|high
decl_stmt|;
specifier|volatile
name|uint32_t
name|low
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcPhysAddr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcPortOutInitParams
block|{
name|uint8_t
name|numOfTasks
decl_stmt|;
comment|/**< OUT */
name|uint8_t
name|numOfExtraTasks
decl_stmt|;
comment|/**< OUT */
name|uint8_t
name|numOfOpenDmas
decl_stmt|;
comment|/**< OUT */
name|uint8_t
name|numOfExtraOpenDmas
decl_stmt|;
comment|/**< OUT */
name|uint32_t
name|sizeOfFifo
decl_stmt|;
comment|/**< OUT */
name|uint32_t
name|extraSizeOfFifo
decl_stmt|;
comment|/**< OUT */
name|t_FmIpcPhysAddr
name|ipcPhysAddr
decl_stmt|;
comment|/**< OUT */
block|}
name|_PackedType
name|t_FmIpcPortOutInitParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for IPC communication during FM_PORT_Init. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcPortInInitParams
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
comment|/**< IN. port Id */
name|uint32_t
name|enumPortType
decl_stmt|;
comment|/**< IN. Port type */
name|uint8_t
name|boolIndependentMode
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
block|}
name|_PackedType
name|t_FmIpcPortInInitParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for IPC communication between port and FM                 regarding tasks and open DMA resources management. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcPortRsrcParams
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
comment|/**< IN. port Id */
name|uint32_t
name|val
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint32_t
name|extra
decl_stmt|;
comment|/**< IN. Port's requested resource */
name|uint8_t
name|boolInitialConfig
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcPortRsrcParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for IPC communication between port and FM                 regarding tasks and open DMA resources management. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcPortFifoParams
block|{
name|t_FmIpcPortRsrcParams
name|rsrcParams
decl_stmt|;
name|uint32_t
name|enumPortType
decl_stmt|;
name|uint8_t
name|boolIndependentMode
decl_stmt|;
name|uint8_t
name|deqPipelineDepth
decl_stmt|;
name|uint8_t
name|numOfPools
decl_stmt|;
name|uint16_t
name|secondLargestBufSize
decl_stmt|;
name|uint16_t
name|largestBufSize
decl_stmt|;
name|uint8_t
name|boolInitialConfig
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcPortFifoParams
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
name|_Packed
struct|struct
name|t_FmIpcPortFreeParams
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
comment|/**< IN. port Id */
name|uint32_t
name|enumPortType
decl_stmt|;
comment|/**< IN. Port type */
name|uint8_t
name|deqPipelineDepth
decl_stmt|;
comment|/**< IN. Port's requested resource */
block|}
name|_PackedType
name|t_FmIpcPortFreeParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for defining DMA status */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcDmaStatus
block|{
name|uint8_t
name|boolCmqNotEmpty
decl_stmt|;
comment|/**< Command queue is not empty */
name|uint8_t
name|boolBusError
decl_stmt|;
comment|/**< Bus error occurred */
name|uint8_t
name|boolReadBufEccError
decl_stmt|;
comment|/**< Double ECC error on buffer Read */
name|uint8_t
name|boolWriteBufEccSysError
decl_stmt|;
comment|/**< Double ECC error on buffer write from system side */
name|uint8_t
name|boolWriteBufEccFmError
decl_stmt|;
comment|/**< Double ECC error on buffer write from FM side */
name|uint8_t
name|boolSinglePortEccError
decl_stmt|;
comment|/**< Single port ECC error from FM side */
block|}
name|_PackedType
name|t_FmIpcDmaStatus
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcRegisterIntr
block|{
name|uint8_t
name|guestId
decl_stmt|;
comment|/* IN */
name|uint32_t
name|event
decl_stmt|;
comment|/* IN */
block|}
name|_PackedType
name|t_FmIpcRegisterIntr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcIsr
block|{
name|uint8_t
name|boolErr
decl_stmt|;
comment|/* IN */
name|uint32_t
name|pendingReg
decl_stmt|;
comment|/* IN */
block|}
name|_PackedType
name|t_FmIpcIsr
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for returning FM parameters */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcParams
block|{
name|uint16_t
name|fmClkFreq
decl_stmt|;
comment|/**< OUT: FM Clock frequency */
name|uint16_t
name|fmMacClkFreq
decl_stmt|;
comment|/**< OUT: FM MAC clock frequence */
name|uint8_t
name|majorRev
decl_stmt|;
comment|/**< OUT: FM Major revision */
name|uint8_t
name|minorRev
decl_stmt|;
comment|/**< OUT: FM Minor revision */
block|}
name|_PackedType
name|t_FmIpcParams
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for returning Fman Ctrl Code revision information */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcFmanCtrlCodeRevisionInfo
block|{
name|uint16_t
name|packageRev
decl_stmt|;
comment|/**< OUT: Package revision */
name|uint8_t
name|majorRev
decl_stmt|;
comment|/**< OUT: Major revision */
name|uint8_t
name|minorRev
decl_stmt|;
comment|/**< OUT: Minor revision */
block|}
name|_PackedType
name|t_FmIpcFmanCtrlCodeRevisionInfo
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Structure for defining Fm number of Fman controlers */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcPortNumOfFmanCtrls
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
comment|/**< IN. port Id */
name|uint8_t
name|numOfFmanCtrls
decl_stmt|;
comment|/**< IN. Port type */
name|t_FmFmanCtrl
name|orFmanCtrl
decl_stmt|;
comment|/**< IN. fman controller for order restoration*/
block|}
name|t_FmIpcPortNumOfFmanCtrls
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   structure for setting Fman contriller events */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcFmanEvents
block|{
name|uint8_t
name|eventRegId
decl_stmt|;
comment|/**< IN: Fman controller event register id */
name|uint32_t
name|enableEvents
decl_stmt|;
comment|/**< IN/OUT: required enabled events mask */
block|}
name|_PackedType
name|t_FmIpcFmanEvents
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcResourceAllocParams
block|{
name|uint8_t
name|guestId
decl_stmt|;
name|uint16_t
name|base
decl_stmt|;
name|uint16_t
name|num
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcResourceAllocParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcVspSetPortWindow
block|{
name|uint8_t
name|hardwarePortId
decl_stmt|;
name|uint8_t
name|baseStorageProfile
decl_stmt|;
name|uint8_t
name|log2NumOfProfiles
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcVspSetPortWindow
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcSetCongestionGroupPfcPriority
block|{
name|uint32_t
name|congestionGroupId
decl_stmt|;
name|uint8_t
name|priorityBitMap
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcSetCongestionGroupPfcPriority
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FM_IPC_MAX_REPLY_BODY_SIZE
value|20
end_define

begin_define
define|#
directive|define
name|FM_IPC_MAX_REPLY_SIZE
value|(FM_IPC_MAX_REPLY_BODY_SIZE + sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|FM_IPC_MAX_MSG_SIZE
value|30
end_define

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcMsg
block|{
name|uint32_t
name|msgId
decl_stmt|;
name|uint8_t
name|msgBody
index|[
name|FM_IPC_MAX_MSG_SIZE
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcMsg
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_FmIpcReply
block|{
name|uint32_t
name|error
decl_stmt|;
name|uint8_t
name|replyBody
index|[
name|FM_IPC_MAX_REPLY_BODY_SIZE
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_FmIpcReply
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
comment|/***************************************************************************/
end_comment

begin_comment
comment|/************************ FRONT-END-TO-BACK-END*****************************/
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GET_TIMESTAMP_SCALE   @Description   Used by FM front-end.   @Param[out]    uint32_t Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_GET_TIMESTAMP_SCALE
value|1
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GET_COUNTER   @Description   Used by FM front-end.   @Param[in/out] t_FmIpcGetCounter Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_GET_COUNTER
value|2
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GET_SET_PORT_PARAMS   @Description   Used by FM front-end for the PORT module in order to set and get                 parameters in/from master FM module on FM PORT initialization time.   @Param[in/out] t_FmIcPortInitParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_GET_SET_PORT_PARAMS
value|4
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_FREE_PORT   @Description   Used by FM front-end for the PORT module when a port is freed                 to free all FM PORT resources.   @Param[in]     uint8_t Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_FREE_PORT
value|5
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RESET_MAC   @Description   Used by front-end for the MAC module to reset the MAC registers   @Param[in]     t_FmIpcMacParams Pointer . */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_RESET_MAC
value|6
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_RESUME_STALLED_PORT   @Description   Used by FM front-end for the PORT module in order to                 release a stalled FM Port.   @Param[in]     uint8_t Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_RESUME_STALLED_PORT
value|7
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_IS_PORT_STALLED   @Description   Used by FM front-end for the PORT module in order to check whether                 an FM port is stalled.   @Param[in/out] t_FmIcPortIsStalled Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_IS_PORT_STALLED
value|8
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GET_PARAMS   @Description   Used by FM front-end for the PORT module in order to dump                 return FM parameters.   @Param[in]     uint8_t Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_GET_PARAMS
value|10
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_REGISTER_INTR   @Description   Used by FM front-end to register an interrupt handler to                 be called upon interrupt for guest.   @Param[out]    t_FmIpcRegisterIntr Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_REGISTER_INTR
value|11
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_DMA_STAT   @Description   Used by FM front-end to read the FM DMA status.   @Param[out]    t_FmIpcDmaStatus Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_DMA_STAT
value|13
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_ALLOC_FMAN_CTRL_EVENT_REG   @Description   Used by FM front-end to allocate event register.   @Param[out]    Event register id Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_ALLOC_FMAN_CTRL_EVENT_REG
value|14
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_FREE_FMAN_CTRL_EVENT_REG   @Description   Used by FM front-end to free locate event register.   @Param[in]    uint8_t Pointer - Event register id */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_FREE_FMAN_CTRL_EVENT_REG
value|15
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_SET_FMAN_CTRL_EVENTS_ENABLE   @Description   Used by FM front-end to enable events in the FPM                 Fman controller event register.   @Param[in]    t_FmIpcFmanEvents Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_SET_FMAN_CTRL_EVENTS_ENABLE
value|16
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_SET_FMAN_CTRL_EVENTS_ENABLE   @Description   Used by FM front-end to enable events in the FPM                 Fman controller event register.   @Param[in/out] t_FmIpcFmanEvents Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_GET_FMAN_CTRL_EVENTS_ENABLE
value|17
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_SET_MAC_MAX_FRAME   @Description   Used by FM front-end to set MAC's MTU/RTU's in                 back-end.   @Param[in/out] t_FmIpcMacMaxFrameParams Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_SET_MAC_MAX_FRAME
value|18
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GET_PHYS_MURAM_BASE   @Description   Used by FM front-end in order to get MURAM base address   @Param[in/out] t_FmIpcPhysAddr Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_GET_PHYS_MURAM_BASE
value|19
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_MASTER_IS_ALIVE   @Description   Used by FM front-end in order to verify Master is up   @Param[in/out] bool */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_MASTER_IS_ALIVE
value|20
end_define

begin_define
define|#
directive|define
name|FM_ENABLE_RAM_ECC
value|21
end_define

begin_define
define|#
directive|define
name|FM_DISABLE_RAM_ECC
value|22
end_define

begin_define
define|#
directive|define
name|FM_SET_NUM_OF_FMAN_CTRL
value|23
end_define

begin_define
define|#
directive|define
name|FM_SET_SIZE_OF_FIFO
value|24
end_define

begin_define
define|#
directive|define
name|FM_SET_NUM_OF_TASKS
value|25
end_define

begin_define
define|#
directive|define
name|FM_SET_NUM_OF_OPEN_DMAS
value|26
end_define

begin_define
define|#
directive|define
name|FM_VSP_ALLOC
value|27
end_define

begin_define
define|#
directive|define
name|FM_VSP_FREE
value|28
end_define

begin_define
define|#
directive|define
name|FM_VSP_SET_PORT_WINDOW
value|29
end_define

begin_define
define|#
directive|define
name|FM_GET_FMAN_CTRL_CODE_REV
value|30
end_define

begin_define
define|#
directive|define
name|FM_SET_CONG_GRP_PFC_PRIO
value|31
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FM_TX_ECC_FRMS_ERRATA_10GMAC_A004
end_ifdef

begin_define
define|#
directive|define
name|FM_10G_TX_ECC_WA
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FM_TX_ECC_FRMS_ERRATA_10GMAC_A004 */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/************************ BACK-END-TO-FRONT-END*****************************/
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      FM_GUEST_ISR   @Description   Used by FM back-end to report an interrupt to the front-end.   @Param[out]    t_FmIpcIsr Pointer */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_GUEST_ISR
value|1
end_define

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_IPC_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of FM_grp group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_IPC_H */
end_comment

end_unit

