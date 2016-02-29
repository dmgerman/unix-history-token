begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|HMAN_OC_CAPWAP_FRAGMENTATION
value|0x33
end_define

begin_define
define|#
directive|define
name|HMAN_OC_IPSEC
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
name|UDP_UDPHECKSUM_FIELD_OFFSET_FROM_UDP
value|6
end_define

begin_define
define|#
directive|define
name|UDP_UDPCHECKSUM_FIELD_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|IP_DSCECN_FIELD_OFFSET_FROM_IP
value|1
end_define

begin_define
define|#
directive|define
name|IP_TOTALLENGTH_FIELD_OFFSET_FROM_IP
value|2
end_define

begin_define
define|#
directive|define
name|IP_HDRCHECKSUM_FIELD_OFFSET_FROM_IP
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
name|IP_ID_FIELD_OFFSET_FROM_IP
value|4
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_CAPWAP_REASM_TABLE_SIZE
value|80
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

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_CALC_UDP_LENGTH
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IPSEC_CNIA
value|0x20000000
end_define

begin_define
define|#
directive|define
name|e_FM_MANIP_CAPWAP_INDX
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UNDER_CONSTRUCTION_FRAG_REASSEMBLY
end_ifdef

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_REASM_TABLE_SIZE
value|0x40
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_REASM_TABLE_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_REASM_COMMON_PARAM_TABLE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_REASM_COMMON_PARAM_TABLE_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_REASM_TIME_OUT_BETWEEN_FRAMES
value|0x80000000
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
name|FM_PCD_MANIP_IP_REASM_LIODN_MASK
value|0x000003F0
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_REASM_LIODN_SHIFT
value|56
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_REASM_ELIODN_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|FM_PCD_MANIP_IP_REASM_ELIODN_SHIFT
value|44
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNDER_CONSTRUCTION_FRAG_REASSEMBLY */
end_comment

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

begin_typedef
typedef|typedef
name|_Packed
struct|struct
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
name|uint8_t
name|res
index|[
literal|16
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_CapwapReasmPram
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|UNDER_CONSTRUCTION_FRAG_REASSEMBLY
end_ifdef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_IpReasmPram
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
name|ipReassCommonPrmTblPtr
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
specifier|volatile
name|uint16_t
name|reserved1
decl_stmt|;
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
name|t_IpReasmPram
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
name|t_IpReasmCommonTbl
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
name|reseervd1
decl_stmt|;
specifier|volatile
name|uint32_t
name|reseervd2
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
name|reserved3
index|[
literal|4
index|]
decl_stmt|;
block|}
name|_PackedType
name|t_IpReasmCommonTbl
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*UNDER_CONSTRUCTION_FRAG_REASSEMBLY*/
end_comment

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
name|uint8_t
name|maxNumFramesInProcess
decl_stmt|;
name|uint8_t
name|numOfTasks
decl_stmt|;
name|uint8_t
name|poolId
decl_stmt|;
name|uint8_t
name|prOffset
decl_stmt|;
name|uint16_t
name|dataOffset
decl_stmt|;
name|uint8_t
name|poolIndx
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
name|t_FragParams
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|UNDER_CONSTRUCTION_FRAG_REASSEMBLY
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_Frag
decl_stmt|;
name|t_Handle
name|h_FragId
decl_stmt|;
name|uint8_t
name|poolId
decl_stmt|;
name|uint16_t
name|dataOffset
decl_stmt|;
name|uint8_t
name|poolIndx
decl_stmt|;
block|}
name|t_IpFragParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_IpReassmParams
block|{
name|t_Handle
name|h_Ipv4Ad
decl_stmt|;
name|t_Handle
name|h_Ipv6Ad
decl_stmt|;
name|e_NetHeaderType
name|hdr
decl_stmt|;
comment|/**< Header selection */
name|uint32_t
name|fqidForTimeOutFrames
decl_stmt|;
name|uint16_t
name|dataOffset
decl_stmt|;
name|t_Handle
name|h_IpReassCommonParamsTbl
decl_stmt|;
name|t_Handle
name|h_Ipv4ReassParamsTblPtr
decl_stmt|;
name|t_Handle
name|h_Ipv6ReassParamsTblPtr
decl_stmt|;
name|t_Handle
name|h_Ipv4AutoLearnHashTbl
decl_stmt|;
name|t_Handle
name|h_Ipv6AutoLearnHashTbl
decl_stmt|;
name|t_Handle
name|h_Ipv4AutoLearnSetLockTblPtr
decl_stmt|;
name|t_Handle
name|h_Ipv6AutoLearnSetLockTblPtr
decl_stmt|;
name|t_Handle
name|h_ReassmFrmDescrIndxPoolTbl
decl_stmt|;
name|t_Handle
name|h_ReassmFrmDescrPoolTbl
decl_stmt|;
name|t_Handle
name|h_TimeOutTbl
decl_stmt|;
name|uint32_t
name|maxNumFramesInProcess
decl_stmt|;
name|uint32_t
name|liodnOffset
decl_stmt|;
name|uint32_t
name|minFragSize
decl_stmt|;
name|uint8_t
name|dataMemId
decl_stmt|;
comment|/**< Memory partition ID for data buffers */
name|uint32_t
name|bpid
decl_stmt|;
name|e_FmPcdManipReassemTimeOutMode
name|timeOutMode
decl_stmt|;
name|e_FmPcdManipReassemWaysNumber
name|numOfFramesPerHashEntry
decl_stmt|;
name|uint32_t
name|timeoutThresholdForReassmProcess
decl_stmt|;
block|}
name|t_IpReassmParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_IpCommonReassmParams
block|{
name|uint8_t
name|numOfTasks
decl_stmt|;
name|uint32_t
name|bitFor1Micro
decl_stmt|;
name|t_Handle
name|h_ReassmFrmDescrPoolTbl
decl_stmt|;
name|t_Handle
name|h_ReassmFrmDescrIndxPoolTbl
decl_stmt|;
name|t_Handle
name|h_TimeOutTbl
decl_stmt|;
block|}
name|t_IpCommonReassmParams
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*UNDER_CONSTRUCTION_FRAG_REASSEMBLY*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bool
name|muramAllocate
decl_stmt|;
name|t_Handle
name|h_Ad
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
name|bool
name|rmv
decl_stmt|;
name|bool
name|insrt
decl_stmt|;
name|uint8_t
modifier|*
name|p_Template
decl_stmt|;
name|t_Handle
name|h_Frag
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
name|uint8_t
name|owner
decl_stmt|;
name|uint32_t
name|updateParams
decl_stmt|;
name|uint32_t
name|shadowUpdateParams
decl_stmt|;
name|t_FragParams
name|fragParams
decl_stmt|;
ifdef|#
directive|ifdef
name|UNDER_CONSTRUCTION_FRAG_REASSEMBLY
name|t_IpReassmParams
name|ipReassmParams
decl_stmt|;
name|t_IpFragParams
name|ipFragParams
decl_stmt|;
endif|#
directive|endif
comment|/* UNDER_CONSTRUCTION_FRAG_REASSEMBLY */
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
name|uint8_t
name|poolId
decl_stmt|;
block|}
name|capwapParams
struct|;
ifdef|#
directive|ifdef
name|UNDER_CONSTRUCTION_FRAG_REASSEMBLY
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
endif|#
directive|endif
comment|/*UNDER_CONSTRUCTION_FRAG_REASSEMBLY*/
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

