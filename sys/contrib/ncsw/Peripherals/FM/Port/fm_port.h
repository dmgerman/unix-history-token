begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_port.h   @Description   FM Port internal structures and definitions. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_PORT_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_PORT_H
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
file|"fm_port_ext.h"
end_include

begin_include
include|#
directive|include
file|"fm_common.h"
end_include

begin_include
include|#
directive|include
file|"fm_sp_common.h"
end_include

begin_include
include|#
directive|include
file|"fsl_fman_sp.h"
end_include

begin_include
include|#
directive|include
file|"fm_port_ext.h"
end_include

begin_include
include|#
directive|include
file|"fsl_fman_port.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_FM_PORT
end_define

begin_define
define|#
directive|define
name|MIN_EXT_BUF_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|DATA_ALIGNMENT
value|64
end_define

begin_define
define|#
directive|define
name|MAX_LIODN_OFFSET
value|64
end_define

begin_define
define|#
directive|define
name|MAX_PORT_FIFO_SIZE
value|MIN(BMI_MAX_FIFO_SIZE, 1024*BMI_FIFO_UNITS)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Memory Map defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BMI_PORT_REGS_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|QMI_PORT_REGS_OFFSET
value|0x400
end_define

begin_define
define|#
directive|define
name|PRS_PORT_REGS_OFFSET
value|0x800
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       defaults */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PORT_deqHighPriority_1G
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_deqHighPriority_10G
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_deqType
value|e_FM_PORT_DEQ_TYPE1
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_deqPrefetchOption
value|e_FM_PORT_DEQ_FULL_PREFETCH
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_deqPrefetchOption_HC
value|e_FM_PORT_DEQ_NO_PREFETCH
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_deqByteCnt_10G
value|0x1400
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_deqByteCnt_1G
value|0x400
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_bufferPrefixContent_privDataSize
value|DEFAULT_FM_SP_bufferPrefixContent_privDataSize
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_bufferPrefixContent_passPrsResult
value|DEFAULT_FM_SP_bufferPrefixContent_passPrsResult
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_bufferPrefixContent_passTimeStamp
value|DEFAULT_FM_SP_bufferPrefixContent_passTimeStamp
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_bufferPrefixContent_allOtherPCDInfo
value|DEFAULT_FM_SP_bufferPrefixContent_allOtherPCDInfo
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_bufferPrefixContent_dataAlign
value|DEFAULT_FM_SP_bufferPrefixContent_dataAlign
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_cheksumLastBytesIgnore
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_cutBytesFromEnd
value|4
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_fifoDeqPipelineDepth_IM
value|2
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_frmDiscardOverride
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_dmaSwapData
value|(e_FmDmaSwapOption)DEFAULT_FMAN_SP_DMA_SWAP_DATA
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_dmaIntContextCacheAttr
value|(e_FmDmaCacheOption)DEFAULT_FMAN_SP_DMA_INT_CONTEXT_CACHE_ATTR
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_dmaHeaderCacheAttr
value|(e_FmDmaCacheOption)DEFAULT_FMAN_SP_DMA_HEADER_CACHE_ATTR
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_dmaScatterGatherCacheAttr
value|(e_FmDmaCacheOption)DEFAULT_FMAN_SP_DMA_SCATTER_GATHER_CACHE_ATTR
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_dmaWriteOptimize
value|DEFAULT_FMAN_SP_DMA_WRITE_OPTIMIZE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_noScatherGather
value|DEFAULT_FMAN_SP_NO_SCATTER_GATHER
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_forwardIntContextReuse
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_BufMargins_startMargins
value|32
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_BufMargins_endMargins
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_syncReq
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_syncReqForHc
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_color
value|e_FM_PORT_COLOR_GREEN
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_errorsToDiscard
value|FM_PORT_FRM_ERR_CLS_DISCARD
end_define

begin_comment
comment|/* #define DEFAULT_PORT_dualRateLimitScaleDown             e_FM_PORT_DUAL_RATE_LIMITER_NONE */
end_comment

begin_comment
comment|/* #define DEFAULT_PORT_rateLimitBurstSizeHighGranularity  FALSE */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PORT_exception
value|IM_EV_BSY
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_maxFrameLength
value|9600
end_define

begin_define
define|#
directive|define
name|DEFAULT_notSupported
value|0xff
end_define

begin_if
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|<
literal|11
operator|)
end_if

begin_define
define|#
directive|define
name|DEFAULT_PORT_rxFifoPriElevationLevel
value|MAX_PORT_FIFO_SIZE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_rxFifoThreshold
value|(MAX_PORT_FIFO_SIZE*3/4)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_txFifoMinFillLevel
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_txFifoLowComfLevel
value|(5*KILOBYTE)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_fifoDeqPipelineDepth_1G
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_fifoDeqPipelineDepth_10G
value|4
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_fifoDeqPipelineDepth_OH
value|2
end_define

begin_comment
comment|/* Host command port MUST NOT be changed to more than 1 !!! */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PORT_numOfTasks
parameter_list|(
name|type
parameter_list|)
define|\
value|(uint32_t)((((type) == e_FM_PORT_TYPE_RX_10G) ||        \                 ((type) == e_FM_PORT_TYPE_TX_10G)) ? 16 :   \                ((((type) == e_FM_PORT_TYPE_RX) ||           \                  ((type) == e_FM_PORT_TYPE_TX) ||           \                  ((type) == e_FM_PORT_TYPE_OH_OFFLINE_PARSING)) ? 3 : 1))
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_extraNumOfTasks
parameter_list|(
name|type
parameter_list|)
define|\
value|(uint32_t)(((type) == e_FM_PORT_TYPE_RX_10G)  ? 8 :    \                (((type) == e_FM_PORT_TYPE_RX) ? 2 : 0))
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_numOfOpenDmas
parameter_list|(
name|type
parameter_list|)
define|\
value|(uint32_t)((((type) == e_FM_PORT_TYPE_TX_10G) ||        \                 ((type) == e_FM_PORT_TYPE_RX_10G)) ? 8 : 1 )
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_extraNumOfOpenDmas
parameter_list|(
name|type
parameter_list|)
define|\
value|(uint32_t)(((type) == e_FM_PORT_TYPE_RX_10G) ? 8 :    \                (((type) == e_FM_PORT_TYPE_RX) ? 1 : 0))
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_numOfFifoBufs
parameter_list|(
name|type
parameter_list|)
define|\
value|(uint32_t)((((type) == e_FM_PORT_TYPE_RX_10G) ||        \                 ((type) == e_FM_PORT_TYPE_TX_10G)) ? 48 :   \                 ((type) == e_FM_PORT_TYPE_RX) ? 45 :        \                 ((type) == e_FM_PORT_TYPE_TX) ? 44 : 8)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_extraNumOfFifoBufs
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* (DPAA_VERSION< 11) */
end_comment

begin_comment
comment|/* Defaults are registers' reset values */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PORT_rxFifoPriElevationLevel
value|MAX_PORT_FIFO_SIZE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_rxFifoThreshold
value|MAX_PORT_FIFO_SIZE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_txFifoMinFillLevel
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_txFifoLowComfLevel
value|(5 * KILOBYTE)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_fifoDeqPipelineDepth_1G
value|2
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_fifoDeqPipelineDepth_10G
value|4
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_fifoDeqPipelineDepth_OH
value|2
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_numOfTasks
parameter_list|(
name|type
parameter_list|)
define|\
value|(uint32_t)((((type) == e_FM_PORT_TYPE_RX_10G) ||        \                 ((type) == e_FM_PORT_TYPE_TX_10G)) ? 14 :   \                (((type) == e_FM_PORT_TYPE_RX) ||            \                  ((type) == e_FM_PORT_TYPE_TX)) ? 4 :       \                  ((type) == e_FM_PORT_TYPE_OH_OFFLINE_PARSING) ? 6 : 1)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_extraNumOfTasks
parameter_list|(
name|type
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_numOfOpenDmas
parameter_list|(
name|type
parameter_list|)
define|\
value|(uint32_t)(((type) == e_FM_PORT_TYPE_RX_10G) ? 8 :      \                ((type) == e_FM_PORT_TYPE_TX_10G) ? 12 :     \                ((type) == e_FM_PORT_TYPE_RX)     ? 2 :      \                ((type) == e_FM_PORT_TYPE_TX)     ? 3 :      \                ((type) == e_FM_PORT_TYPE_OH_HOST_COMMAND) ? 2 : 4)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_extraNumOfOpenDmas
parameter_list|(
name|type
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_numOfFifoBufs
parameter_list|(
name|type
parameter_list|)
define|\
value|(uint32_t) (((type) == e_FM_PORT_TYPE_RX_10G) ? 96 : \                 ((type) == e_FM_PORT_TYPE_TX_10G) ? 64 : \                 ((type) == e_FM_PORT_TYPE_OH_HOST_COMMAND) ? 10 : 50)
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_extraNumOfFifoBufs
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION< 11) */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PORT_txBdRingLength
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_rxBdRingLength
value|128
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_ImfwExtStructsMemId
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT_ImfwExtStructsMemAttr
value|MEMORY_ATTR_CACHEABLE
end_define

begin_define
define|#
directive|define
name|FM_PORT_CG_REG_NUM
parameter_list|(
name|_cgId
parameter_list|)
value|(((FM_PORT_NUM_OF_CONGESTION_GRPS/32)-1)-_cgId/32)
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Collection    PCD Engines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|fmPcdEngines_t
typedef|;
end_typedef

begin_comment
comment|/**< options as defined below: */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_NONE
value|0
end_define

begin_comment
comment|/**< No PCD Engine indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PRS
value|0x80000000
end_define

begin_comment
comment|/**< Parser indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_KG
value|0x40000000
end_define

begin_comment
comment|/**< Keygen indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_CC
value|0x20000000
end_define

begin_comment
comment|/**< Coarse classification indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR
value|0x10000000
end_define

begin_comment
comment|/**< Policer indicated */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_MANIP
value|0x08000000
end_define

begin_comment
comment|/**< Manipulation indicated */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_define
define|#
directive|define
name|FM_PORT_MAX_NUM_OF_EXT_POOLS_ALL_INTEGRATIONS
value|8
end_define

begin_define
define|#
directive|define
name|FM_PORT_MAX_NUM_OF_CONGESTION_GRPS_ALL_INTEGRATIONS
value|256
end_define

begin_define
define|#
directive|define
name|FM_PORT_CG_REG_NUM
parameter_list|(
name|_cgId
parameter_list|)
value|(((FM_PORT_NUM_OF_CONGESTION_GRPS/32)-1)-_cgId/32)
end_define

begin_define
define|#
directive|define
name|FM_OH_PORT_ID
value|0
end_define

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          SW parser OFFLOAD labels (offsets)                         */
end_comment

begin_comment
comment|/***********************************************************************/
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
name|OFFLOAD_SW_PATCH_IPv4_IPR_LABEL
value|0x300
end_define

begin_define
define|#
directive|define
name|OFFLOAD_SW_PATCH_IPv6_IPR_LABEL
value|0x325
end_define

begin_define
define|#
directive|define
name|OFFLOAD_SW_PATCH_IPv6_IPF_LABEL
value|0x325
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OFFLOAD_SW_PATCH_IPv4_IPR_LABEL
value|0x100
end_define

begin_comment
comment|/* Will be used for:  * 1. identify fragments  * 2. udp-lite  */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_SW_PATCH_IPv6_IPR_LABEL
value|0x146
end_define

begin_comment
comment|/* Will be used for:  * 1. will identify the fragmentable area  * 2. udp-lite  */
end_comment

begin_define
define|#
directive|define
name|OFFLOAD_SW_PATCH_IPv6_IPF_LABEL
value|0x261
end_define

begin_define
define|#
directive|define
name|OFFLOAD_SW_PATCH_CAPWAP_LABEL
value|0x38d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (DPAA_VERSION == 10) */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|DPAA_VERSION
operator|==
literal|10
operator|)
operator|&&
name|defined
argument_list|(
name|FM_CAPWAP_SUPPORT
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|UDP_LITE_SW_PATCH_LABEL
value|0x2E0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ((DPAA_VERSION == 10)&& defined(FM_CAPWAP_SUPPORT)) */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Memory Mapped Registers */
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

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fmbm_rcfg
decl_stmt|;
comment|/**< Rx Configuration */
specifier|volatile
name|uint32_t
name|fmbm_rst
decl_stmt|;
comment|/**< Rx Status */
specifier|volatile
name|uint32_t
name|fmbm_rda
decl_stmt|;
comment|/**< Rx DMA attributes*/
specifier|volatile
name|uint32_t
name|fmbm_rfp
decl_stmt|;
comment|/**< Rx FIFO Parameters*/
specifier|volatile
name|uint32_t
name|fmbm_rfed
decl_stmt|;
comment|/**< Rx Frame End Data*/
specifier|volatile
name|uint32_t
name|fmbm_ricp
decl_stmt|;
comment|/**< Rx Internal Context Parameters*/
specifier|volatile
name|uint32_t
name|fmbm_rim
decl_stmt|;
comment|/**< Rx Internal Buffer Margins*/
specifier|volatile
name|uint32_t
name|fmbm_rebm
decl_stmt|;
comment|/**< Rx External Buffer Margins*/
specifier|volatile
name|uint32_t
name|fmbm_rfne
decl_stmt|;
comment|/**< Rx Frame Next Engine*/
specifier|volatile
name|uint32_t
name|fmbm_rfca
decl_stmt|;
comment|/**< Rx Frame Command Attributes.*/
specifier|volatile
name|uint32_t
name|fmbm_rfpne
decl_stmt|;
comment|/**< Rx Frame Parser Next Engine*/
specifier|volatile
name|uint32_t
name|fmbm_rpso
decl_stmt|;
comment|/**< Rx Parse Start Offset*/
specifier|volatile
name|uint32_t
name|fmbm_rpp
decl_stmt|;
comment|/**< Rx Policer Profile  */
specifier|volatile
name|uint32_t
name|fmbm_rccb
decl_stmt|;
comment|/**< Rx Coarse Classification Base */
specifier|volatile
name|uint32_t
name|fmbm_reth
decl_stmt|;
comment|/**< Rx Excessive Threshold */
specifier|volatile
name|uint32_t
name|reserved1
index|[
literal|0x01
index|]
decl_stmt|;
comment|/**< (0x03C) */
specifier|volatile
name|uint32_t
name|fmbm_rprai
index|[
name|FM_PORT_PRS_RESULT_NUM_OF_WORDS
index|]
decl_stmt|;
comment|/**< Rx Parse Results Array Initialization*/
specifier|volatile
name|uint32_t
name|fmbm_rfqid
decl_stmt|;
comment|/**< Rx Frame Queue ID*/
specifier|volatile
name|uint32_t
name|fmbm_refqid
decl_stmt|;
comment|/**< Rx Error Frame Queue ID*/
specifier|volatile
name|uint32_t
name|fmbm_rfsdm
decl_stmt|;
comment|/**< Rx Frame Status Discard Mask*/
specifier|volatile
name|uint32_t
name|fmbm_rfsem
decl_stmt|;
comment|/**< Rx Frame Status Error Mask*/
specifier|volatile
name|uint32_t
name|fmbm_rfene
decl_stmt|;
comment|/**< Rx Frame Enqueue Next Engine */
specifier|volatile
name|uint32_t
name|reserved2
index|[
literal|0x02
index|]
decl_stmt|;
comment|/**< (0x074-0x078) */
specifier|volatile
name|uint32_t
name|fmbm_rcmne
decl_stmt|;
comment|/**< Rx Frame Continuous Mode Next Engine */
specifier|volatile
name|uint32_t
name|reserved3
index|[
literal|0x20
index|]
decl_stmt|;
comment|/**< (0x080 0x0FF)  */
specifier|volatile
name|uint32_t
name|fmbm_ebmpi
index|[
name|FM_PORT_MAX_NUM_OF_EXT_POOLS_ALL_INTEGRATIONS
index|]
decl_stmt|;
comment|/**< Buffer Manager pool Information-*/
specifier|volatile
name|uint32_t
name|fmbm_acnt
index|[
name|FM_PORT_MAX_NUM_OF_EXT_POOLS_ALL_INTEGRATIONS
index|]
decl_stmt|;
comment|/**< Allocate Counter-*/
specifier|volatile
name|uint32_t
name|reserved4
index|[
literal|0x08
index|]
decl_stmt|;
comment|/**< 0x130/0x140 - 0x15F reserved -*/
specifier|volatile
name|uint32_t
name|fmbm_rcgm
index|[
name|FM_PORT_MAX_NUM_OF_CONGESTION_GRPS_ALL_INTEGRATIONS
operator|/
literal|32
index|]
decl_stmt|;
comment|/**< Congestion Group Map*/
specifier|volatile
name|uint32_t
name|fmbm_rmpd
decl_stmt|;
comment|/**< BM Pool Depletion  */
specifier|volatile
name|uint32_t
name|reserved5
index|[
literal|0x1F
index|]
decl_stmt|;
comment|/**< (0x184 0x1FF) */
specifier|volatile
name|uint32_t
name|fmbm_rstc
decl_stmt|;
comment|/**< Rx Statistics Counters*/
specifier|volatile
name|uint32_t
name|fmbm_rfrc
decl_stmt|;
comment|/**< Rx Frame Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rfbc
decl_stmt|;
comment|/**< Rx Bad Frames Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rlfc
decl_stmt|;
comment|/**< Rx Large Frames Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rffc
decl_stmt|;
comment|/**< Rx Filter Frames Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rfcd
decl_stmt|;
comment|/**< Rx Frame Discard Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rfldec
decl_stmt|;
comment|/**< Rx Frames List DMA Error Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rodc
decl_stmt|;
comment|/**< Rx Out of Buffers Discard Counter-*/
specifier|volatile
name|uint32_t
name|fmbm_rbdc
decl_stmt|;
comment|/**< Rx Buffers Deallocate Counter-*/
specifier|volatile
name|uint32_t
name|fmbm_rpec
decl_stmt|;
comment|/**< Rx RX Prepare to enqueue Counter-*/
specifier|volatile
name|uint32_t
name|reserved6
index|[
literal|0x16
index|]
decl_stmt|;
comment|/**< (0x228 0x27F) */
specifier|volatile
name|uint32_t
name|fmbm_rpc
decl_stmt|;
comment|/**< Rx Performance Counters*/
specifier|volatile
name|uint32_t
name|fmbm_rpcp
decl_stmt|;
comment|/**< Rx Performance Count Parameters*/
specifier|volatile
name|uint32_t
name|fmbm_rccn
decl_stmt|;
comment|/**< Rx Cycle Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rtuc
decl_stmt|;
comment|/**< Rx Tasks Utilization Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rrquc
decl_stmt|;
comment|/**< Rx Receive Queue Utilization Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rduc
decl_stmt|;
comment|/**< Rx DMA Utilization Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rfuc
decl_stmt|;
comment|/**< Rx FIFO Utilization Counter*/
specifier|volatile
name|uint32_t
name|fmbm_rpac
decl_stmt|;
comment|/**< Rx Pause Activation Counter*/
specifier|volatile
name|uint32_t
name|reserved7
index|[
literal|0x18
index|]
decl_stmt|;
comment|/**< (0x2A0-0x2FF) */
specifier|volatile
name|uint32_t
name|fmbm_rdcfg
index|[
literal|0x3
index|]
decl_stmt|;
comment|/**< Rx Debug-*/
specifier|volatile
name|uint32_t
name|fmbm_rgpr
decl_stmt|;
comment|/**< Rx General Purpose Register. */
specifier|volatile
name|uint32_t
name|reserved8
index|[
literal|0x3a
index|]
decl_stmt|;
comment|/**< (0x310-0x3FF) */
block|}
name|t_FmPortRxBmiRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fmbm_tcfg
decl_stmt|;
comment|/**< Tx Configuration */
specifier|volatile
name|uint32_t
name|fmbm_tst
decl_stmt|;
comment|/**< Tx Status */
specifier|volatile
name|uint32_t
name|fmbm_tda
decl_stmt|;
comment|/**< Tx DMA attributes */
specifier|volatile
name|uint32_t
name|fmbm_tfp
decl_stmt|;
comment|/**< Tx FIFO Parameters */
specifier|volatile
name|uint32_t
name|fmbm_tfed
decl_stmt|;
comment|/**< Tx Frame End Data */
specifier|volatile
name|uint32_t
name|fmbm_ticp
decl_stmt|;
comment|/**< Tx Internal Context Parameters */
specifier|volatile
name|uint32_t
name|fmbm_tfdne
decl_stmt|;
comment|/**< Tx Frame Dequeue Next Engine. */
specifier|volatile
name|uint32_t
name|fmbm_tfca
decl_stmt|;
comment|/**< Tx Frame Command attribute. */
specifier|volatile
name|uint32_t
name|fmbm_tcfqid
decl_stmt|;
comment|/**< Tx Confirmation Frame Queue ID. */
specifier|volatile
name|uint32_t
name|fmbm_tfeqid
decl_stmt|;
comment|/**< Tx Frame Error Queue ID */
specifier|volatile
name|uint32_t
name|fmbm_tfene
decl_stmt|;
comment|/**< Tx Frame Enqueue Next Engine */
specifier|volatile
name|uint32_t
name|fmbm_trlmts
decl_stmt|;
comment|/**< Tx Rate Limiter Scale */
specifier|volatile
name|uint32_t
name|fmbm_trlmt
decl_stmt|;
comment|/**< Tx Rate Limiter */
specifier|volatile
name|uint32_t
name|fmbm_tccb
decl_stmt|;
comment|/**< Tx Coarse Classification Base */
specifier|volatile
name|uint32_t
name|reserved0
index|[
literal|0x0e
index|]
decl_stmt|;
comment|/**< (0x038-0x070) */
specifier|volatile
name|uint32_t
name|fmbm_tfne
decl_stmt|;
comment|/**< Tx Frame Next Engine */
specifier|volatile
name|uint32_t
name|fmbm_tpfcm
index|[
literal|0x02
index|]
decl_stmt|;
comment|/**< Tx Priority based Flow Control (PFC) Mapping */
specifier|volatile
name|uint32_t
name|fmbm_tcmne
decl_stmt|;
comment|/**< Tx Frame Continuous Mode Next Engine */
specifier|volatile
name|uint32_t
name|reserved2
index|[
literal|0x60
index|]
decl_stmt|;
comment|/**< (0x080-0x200) */
specifier|volatile
name|uint32_t
name|fmbm_tstc
decl_stmt|;
comment|/**< Tx Statistics Counters */
specifier|volatile
name|uint32_t
name|fmbm_tfrc
decl_stmt|;
comment|/**< Tx Frame Counter */
specifier|volatile
name|uint32_t
name|fmbm_tfdc
decl_stmt|;
comment|/**< Tx Frames Discard Counter */
specifier|volatile
name|uint32_t
name|fmbm_tfledc
decl_stmt|;
comment|/**< Tx Frame Length error discard counter */
specifier|volatile
name|uint32_t
name|fmbm_tfufdc
decl_stmt|;
comment|/**< Tx Frame unsupported format discard Counter */
specifier|volatile
name|uint32_t
name|fmbm_tbdc
decl_stmt|;
comment|/**< Tx Buffers Deallocate Counter */
specifier|volatile
name|uint32_t
name|reserved3
index|[
literal|0x1A
index|]
decl_stmt|;
comment|/**< (0x218-0x280) */
specifier|volatile
name|uint32_t
name|fmbm_tpc
decl_stmt|;
comment|/**< Tx Performance Counters*/
specifier|volatile
name|uint32_t
name|fmbm_tpcp
decl_stmt|;
comment|/**< Tx Performance Count Parameters*/
specifier|volatile
name|uint32_t
name|fmbm_tccn
decl_stmt|;
comment|/**< Tx Cycle Counter*/
specifier|volatile
name|uint32_t
name|fmbm_ttuc
decl_stmt|;
comment|/**< Tx Tasks Utilization Counter*/
specifier|volatile
name|uint32_t
name|fmbm_ttcquc
decl_stmt|;
comment|/**< Tx Transmit Confirm Queue Utilization Counter*/
specifier|volatile
name|uint32_t
name|fmbm_tduc
decl_stmt|;
comment|/**< Tx DMA Utilization Counter*/
specifier|volatile
name|uint32_t
name|fmbm_tfuc
decl_stmt|;
comment|/**< Tx FIFO Utilization Counter*/
specifier|volatile
name|uint32_t
name|reserved4
index|[
literal|16
index|]
decl_stmt|;
comment|/**< (0x29C-0x2FF) */
specifier|volatile
name|uint32_t
name|fmbm_tdcfg
index|[
literal|0x3
index|]
decl_stmt|;
comment|/**< Tx Debug-*/
specifier|volatile
name|uint32_t
name|fmbm_tgpr
decl_stmt|;
comment|/**< O/H General Purpose Register */
specifier|volatile
name|uint32_t
name|reserved5
index|[
literal|0x3a
index|]
decl_stmt|;
comment|/**< (0x310-0x3FF) */
block|}
name|t_FmPortTxBmiRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fmbm_ocfg
decl_stmt|;
comment|/**< O/H Configuration  */
specifier|volatile
name|uint32_t
name|fmbm_ost
decl_stmt|;
comment|/**< O/H Status */
specifier|volatile
name|uint32_t
name|fmbm_oda
decl_stmt|;
comment|/**< O/H DMA attributes  */
specifier|volatile
name|uint32_t
name|fmbm_oicp
decl_stmt|;
comment|/**< O/H Internal Context Parameters  */
specifier|volatile
name|uint32_t
name|fmbm_ofdne
decl_stmt|;
comment|/**< O/H Frame Dequeue Next Engine  */
specifier|volatile
name|uint32_t
name|fmbm_ofne
decl_stmt|;
comment|/**< O/H Frame Next Engine  */
specifier|volatile
name|uint32_t
name|fmbm_ofca
decl_stmt|;
comment|/**< O/H Frame Command Attributes.  */
specifier|volatile
name|uint32_t
name|fmbm_ofpne
decl_stmt|;
comment|/**< O/H Frame Parser Next Engine  */
specifier|volatile
name|uint32_t
name|fmbm_opso
decl_stmt|;
comment|/**< O/H Parse Start Offset  */
specifier|volatile
name|uint32_t
name|fmbm_opp
decl_stmt|;
comment|/**< O/H Policer Profile */
specifier|volatile
name|uint32_t
name|fmbm_occb
decl_stmt|;
comment|/**< O/H Coarse Classification base */
specifier|volatile
name|uint32_t
name|fmbm_oim
decl_stmt|;
comment|/**< O/H Internal margins*/
specifier|volatile
name|uint32_t
name|fmbm_ofp
decl_stmt|;
comment|/**< O/H Fifo Parameters*/
specifier|volatile
name|uint32_t
name|fmbm_ofed
decl_stmt|;
comment|/**< O/H Frame End Data*/
specifier|volatile
name|uint32_t
name|reserved0
index|[
literal|2
index|]
decl_stmt|;
comment|/**< (0x038 - 0x03F) */
specifier|volatile
name|uint32_t
name|fmbm_oprai
index|[
name|FM_PORT_PRS_RESULT_NUM_OF_WORDS
index|]
decl_stmt|;
comment|/**< O/H Parse Results Array Initialization  */
specifier|volatile
name|uint32_t
name|fmbm_ofqid
decl_stmt|;
comment|/**< O/H Frame Queue ID  */
specifier|volatile
name|uint32_t
name|fmbm_oefqid
decl_stmt|;
comment|/**< O/H Error Frame Queue ID  */
specifier|volatile
name|uint32_t
name|fmbm_ofsdm
decl_stmt|;
comment|/**< O/H Frame Status Discard Mask  */
specifier|volatile
name|uint32_t
name|fmbm_ofsem
decl_stmt|;
comment|/**< O/H Frame Status Error Mask  */
specifier|volatile
name|uint32_t
name|fmbm_ofene
decl_stmt|;
comment|/**< O/H Frame Enqueue Next Engine  */
specifier|volatile
name|uint32_t
name|fmbm_orlmts
decl_stmt|;
comment|/**< O/H Rate Limiter Scale  */
specifier|volatile
name|uint32_t
name|fmbm_orlmt
decl_stmt|;
comment|/**< O/H Rate Limiter  */
specifier|volatile
name|uint32_t
name|fmbm_ocmne
decl_stmt|;
comment|/**< O/H Continuous Mode Next Engine  */
specifier|volatile
name|uint32_t
name|reserved1
index|[
literal|0x20
index|]
decl_stmt|;
comment|/**< (0x080 - 0x0FF) */
specifier|volatile
name|uint32_t
name|fmbm_oebmpi
index|[
literal|2
index|]
decl_stmt|;
comment|/**< Buffer Manager Observed Pool Information */
specifier|volatile
name|uint32_t
name|reserved2
index|[
literal|0x16
index|]
decl_stmt|;
comment|/**< (0x108 - 0x15F) */
specifier|volatile
name|uint32_t
name|fmbm_ocgm
decl_stmt|;
comment|/**< Observed Congestion Group Map */
specifier|volatile
name|uint32_t
name|reserved3
index|[
literal|0x7
index|]
decl_stmt|;
comment|/**< (0x164 - 0x17F) */
specifier|volatile
name|uint32_t
name|fmbm_ompd
decl_stmt|;
comment|/**< Observed BMan Pool Depletion */
specifier|volatile
name|uint32_t
name|reserved4
index|[
literal|0x1F
index|]
decl_stmt|;
comment|/**< (0x184 - 0x1FF) */
specifier|volatile
name|uint32_t
name|fmbm_ostc
decl_stmt|;
comment|/**< O/H Statistics Counters  */
specifier|volatile
name|uint32_t
name|fmbm_ofrc
decl_stmt|;
comment|/**< O/H Frame Counter  */
specifier|volatile
name|uint32_t
name|fmbm_ofdc
decl_stmt|;
comment|/**< O/H Frames Discard Counter  */
specifier|volatile
name|uint32_t
name|fmbm_ofledc
decl_stmt|;
comment|/**< O/H Frames Length Error Discard Counter  */
specifier|volatile
name|uint32_t
name|fmbm_ofufdc
decl_stmt|;
comment|/**< O/H Frames Unsupported Format Discard Counter  */
specifier|volatile
name|uint32_t
name|fmbm_offc
decl_stmt|;
comment|/**< O/H Filter Frames Counter  */
specifier|volatile
name|uint32_t
name|fmbm_ofwdc
decl_stmt|;
comment|/**< - Rx Frames WRED Discard Counter  */
specifier|volatile
name|uint32_t
name|fmbm_ofldec
decl_stmt|;
comment|/**< O/H Frames List DMA Error Counter */
specifier|volatile
name|uint32_t
name|fmbm_obdc
decl_stmt|;
comment|/**< O/H Buffers Deallocate Counter */
specifier|volatile
name|uint32_t
name|fmbm_oodc
decl_stmt|;
comment|/**< O/H Out of Buffers Discard Counter */
specifier|volatile
name|uint32_t
name|fmbm_opec
decl_stmt|;
comment|/**< O/H Prepare to enqueue Counter */
specifier|volatile
name|uint32_t
name|reserved5
index|[
literal|0x15
index|]
decl_stmt|;
comment|/**< ( - 0x27F) */
specifier|volatile
name|uint32_t
name|fmbm_opc
decl_stmt|;
comment|/**< O/H Performance Counters  */
specifier|volatile
name|uint32_t
name|fmbm_opcp
decl_stmt|;
comment|/**< O/H Performance Count Parameters  */
specifier|volatile
name|uint32_t
name|fmbm_occn
decl_stmt|;
comment|/**< O/H Cycle Counter  */
specifier|volatile
name|uint32_t
name|fmbm_otuc
decl_stmt|;
comment|/**< O/H Tasks Utilization Counter  */
specifier|volatile
name|uint32_t
name|fmbm_oduc
decl_stmt|;
comment|/**< O/H DMA Utilization Counter */
specifier|volatile
name|uint32_t
name|fmbm_ofuc
decl_stmt|;
comment|/**< O/H FIFO Utilization Counter */
specifier|volatile
name|uint32_t
name|reserved6
index|[
literal|26
index|]
decl_stmt|;
comment|/**< (0x298-0x2FF) */
specifier|volatile
name|uint32_t
name|fmbm_odcfg
index|[
literal|0x3
index|]
decl_stmt|;
comment|/**< O/H Debug (only 1 in P1023) */
specifier|volatile
name|uint32_t
name|fmbm_ogpr
decl_stmt|;
comment|/**< O/H General Purpose Register. */
specifier|volatile
name|uint32_t
name|reserved7
index|[
literal|0x3a
index|]
decl_stmt|;
comment|/**< (0x310 0x3FF) */
block|}
name|t_FmPortOhBmiRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|t_FmPortRxBmiRegs
name|rxPortBmiRegs
decl_stmt|;
name|t_FmPortTxBmiRegs
name|txPortBmiRegs
decl_stmt|;
name|t_FmPortOhBmiRegs
name|ohPortBmiRegs
decl_stmt|;
block|}
name|u_FmPortBmiRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/**<   0xn024 - 0x02B */
specifier|volatile
name|uint32_t
name|fmqm_pndn
decl_stmt|;
comment|/**<   PortID n Dequeue NIA Register */
specifier|volatile
name|uint32_t
name|fmqm_pndc
decl_stmt|;
comment|/**<   PortID n Dequeue Config Register */
specifier|volatile
name|uint32_t
name|fmqm_pndtfc
decl_stmt|;
comment|/**<   PortID n Dequeue Total Frame Counter */
specifier|volatile
name|uint32_t
name|fmqm_pndfdc
decl_stmt|;
comment|/**<   PortID n Dequeue FQID from Default Counter */
specifier|volatile
name|uint32_t
name|fmqm_pndcc
decl_stmt|;
comment|/**<   PortID n Dequeue Confirm Counter */
block|}
name|t_FmPortNonRxQmiRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|uint32_t
name|fmqm_pnc
decl_stmt|;
comment|/**<   PortID n Configuration Register */
specifier|volatile
name|uint32_t
name|fmqm_pns
decl_stmt|;
comment|/**<   PortID n Status Register */
specifier|volatile
name|uint32_t
name|fmqm_pnts
decl_stmt|;
comment|/**<   PortID n Task Status Register */
specifier|volatile
name|uint32_t
name|reserved0
index|[
literal|4
index|]
decl_stmt|;
comment|/**<   0xn00C - 0xn01B */
specifier|volatile
name|uint32_t
name|fmqm_pnen
decl_stmt|;
comment|/**<   PortID n Enqueue NIA Register */
specifier|volatile
name|uint32_t
name|fmqm_pnetfc
decl_stmt|;
comment|/**<   PortID n Enqueue Total Frame Counter */
name|t_FmPortNonRxQmiRegs
name|nonRxQmiRegs
decl_stmt|;
comment|/**<   Registers for Tx Hc& Op ports */
block|}
name|t_FmPortQmiRegs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
struct|struct
block|{
specifier|volatile
name|uint32_t
name|softSeqAttach
decl_stmt|;
comment|/**<   Soft Sequence Attachment */
specifier|volatile
name|uint32_t
name|lcv
decl_stmt|;
comment|/**<   Line-up Enable Confirmation Mask */
block|}
name|hdrs
index|[
name|FM_PCD_PRS_NUM_OF_HDRS
index|]
struct|;
specifier|volatile
name|uint32_t
name|reserved0
index|[
literal|0xde
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|pcac
decl_stmt|;
comment|/**<   Parse Internal Memory Configuration Access Control Register */
specifier|volatile
name|uint32_t
name|pctpid
decl_stmt|;
comment|/**<   Parse Internal Memory Configured TPID Register */
block|}
name|t_FmPortPrsRegs
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Description   Basic buffer descriptor (BD) structure */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint16_t
name|status
decl_stmt|;
specifier|volatile
name|uint16_t
name|length
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved0
index|[
literal|0x6
index|]
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|0x1
index|]
decl_stmt|;
specifier|volatile
name|t_FmPhysAddr
name|buff
decl_stmt|;
block|}
name|_PackedType
name|t_FmImBd
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint16_t
name|gen
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint8_t
name|reserved0
index|[
literal|0x1
index|]
decl_stmt|;
specifier|volatile
name|t_FmPhysAddr
name|bdRingBase
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint16_t
name|bdRingSize
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint16_t
name|offsetIn
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint16_t
name|offsetOut
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|0x12
index|]
decl_stmt|;
comment|/**< 0x0e - 0x1f */
block|}
name|_PackedType
name|t_FmPortImQd
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Packed
struct|struct
block|{
specifier|volatile
name|uint32_t
name|mode
decl_stmt|;
comment|/**< Mode register */
specifier|volatile
name|uint32_t
name|rxQdPtr
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint32_t
name|txQdPtr
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint16_t
name|mrblr
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint16_t
name|rxQdBsyCnt
decl_stmt|;
comment|/**< tbd */
specifier|volatile
name|uint8_t
name|reserved0
index|[
literal|0x10
index|]
decl_stmt|;
comment|/**< 0x10 - 0x1f */
name|t_FmPortImQd
name|rxQd
decl_stmt|;
name|t_FmPortImQd
name|txQd
decl_stmt|;
specifier|volatile
name|uint8_t
name|reserved1
index|[
literal|0xa0
index|]
decl_stmt|;
comment|/**< 0x60 - 0xff */
block|}
name|_PackedType
name|t_FmPortImPram
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
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Registers bit fields */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       BMI defines */
end_comment

begin_comment
comment|/***************************************************************************/
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
name|BMI_SP_ID_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|BMI_SP_ID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BMI_SP_EN
value|0x01000000
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
name|BMI_PORT_CFG_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_PORT_CFG_EN_MACSEC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BMI_PORT_CFG_FDOVR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BMI_PORT_CFG_IM
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BMI_PORT_CFG_AM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BMI_PORT_STATUS_BSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_COUNTERS_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_PORT_RFNE_FRWD_DCL4C
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BMI_PORT_RFNE_FRWD_RPD
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BMI_RFNE_FDCS_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|BMI_RFNE_HXS_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|BMI_CMD_MR_LEAC
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_MR_SLEAC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_MR_MA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_MR_DEAS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_RX_MR_DEF
value|(BMI_CMD_MR_LEAC | \                                                  BMI_CMD_MR_SLEAC | \                                                  BMI_CMD_MR_MA | \                                                  BMI_CMD_MR_DEAS)
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_ORDER
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_SYNC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MODE_MISS_ALLIGN_ADDR_EN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MACCMD_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MACCMD_OVERRIDE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MACCMD_SECURED
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MACCMD_SC_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|BMI_EXT_BUF_POOL_ID_MASK
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|BMI_STATUS_RX_MASK_UNUSED
value|(uint32_t)(~(FM_PORT_FRM_ERR_DMA                    | \                                                              FM_PORT_FRM_ERR_PHYSICAL               | \                                                              FM_PORT_FRM_ERR_SIZE                   | \                                                              FM_PORT_FRM_ERR_CLS_DISCARD            | \                                                              FM_PORT_FRM_ERR_EXTRACTION             | \                                                              FM_PORT_FRM_ERR_NO_SCHEME              | \                                                              FM_PORT_FRM_ERR_COLOR_RED              | \                                                              FM_PORT_FRM_ERR_COLOR_YELLOW           | \                                                              FM_PORT_FRM_ERR_ILL_PLCR               | \                                                              FM_PORT_FRM_ERR_PLCR_FRAME_LEN         | \                                                              FM_PORT_FRM_ERR_PRS_TIMEOUT            | \                                                              FM_PORT_FRM_ERR_PRS_ILL_INSTRUCT       | \                                                              FM_PORT_FRM_ERR_BLOCK_LIMIT_EXCEEDED   | \                                                              FM_PORT_FRM_ERR_PRS_HDR_ERR            | \                                                              FM_PORT_FRM_ERR_IPRE                   | \                                                              FM_PORT_FRM_ERR_IPR_NCSP               | \                                                              FM_PORT_FRM_ERR_KEYSIZE_OVERFLOW))
end_define

begin_define
define|#
directive|define
name|BMI_STATUS_OP_MASK_UNUSED
value|(uint32_t)(BMI_STATUS_RX_MASK_UNUSED&                \                                                            ~(FM_PORT_FRM_ERR_LENGTH                 | \                                                              FM_PORT_FRM_ERR_NON_FM                 | \                                                              FM_PORT_FRM_ERR_UNSUPPORTED_FORMAT))
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_BURST_SIZE_GRAN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_SCALE_BY_2
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_SCALE_BY_4
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_SCALE_BY_8
value|0x00000003
end_define

begin_define
define|#
directive|define
name|BMI_RX_FIFO_THRESHOLD_BC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_PRS_RESULT_HIGH
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BMI_PRS_RESULT_LOW
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|RX_ERRS_TO_ENQ
value|(FM_PORT_FRM_ERR_DMA                    | \                                                  FM_PORT_FRM_ERR_PHYSICAL               | \                                                  FM_PORT_FRM_ERR_SIZE                   | \                                                  FM_PORT_FRM_ERR_EXTRACTION             | \                                                  FM_PORT_FRM_ERR_NO_SCHEME              | \                                                  FM_PORT_FRM_ERR_ILL_PLCR               | \                                                  FM_PORT_FRM_ERR_PLCR_FRAME_LEN         | \                                                  FM_PORT_FRM_ERR_PRS_TIMEOUT            | \                                                  FM_PORT_FRM_ERR_PRS_ILL_INSTRUCT       | \                                                  FM_PORT_FRM_ERR_BLOCK_LIMIT_EXCEEDED   | \                                                  FM_PORT_FRM_ERR_PRS_HDR_ERR            | \                                                  FM_PORT_FRM_ERR_KEYSIZE_OVERFLOW       | \                                                  FM_PORT_FRM_ERR_IPRE)
end_define

begin_define
define|#
directive|define
name|OP_ERRS_TO_ENQ
value|(RX_ERRS_TO_ENQ                         | \                                                  FM_PORT_FRM_ERR_LENGTH                 | \                                                  FM_PORT_FRM_ERR_NON_FM                 | \                                                  FM_PORT_FRM_ERR_UNSUPPORTED_FORMAT)
end_define

begin_define
define|#
directive|define
name|BMI_RX_FIFO_PRI_ELEVATION_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|BMI_RX_FIFO_THRESHOLD_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|BMI_TX_FIFO_MIN_FILL_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|BMI_FIFO_PIPELINE_DEPTH_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|BMI_TX_LOW_COMF_MASK
value|0x000003FF
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|BMI_PORT_CFG_MS_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_DMA_ATTR_IC_CACHE_SHIFT
value|FMAN_SP_DMA_ATTR_IC_CACHE_SHIFT
end_define

begin_define
define|#
directive|define
name|BMI_DMA_ATTR_HDR_CACHE_SHIFT
value|FMAN_SP_DMA_ATTR_HDR_CACHE_SHIFT
end_define

begin_define
define|#
directive|define
name|BMI_DMA_ATTR_SG_CACHE_SHIFT
value|FMAN_SP_DMA_ATTR_SG_CACHE_SHIFT
end_define

begin_define
define|#
directive|define
name|BMI_IM_FOF_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|BMI_PR_PORTID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BMI_RX_FIFO_PRI_ELEVATION_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_RX_FIFO_THRESHOLD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMI_RX_FRAME_END_CS_IGNORE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BMI_RX_FRAME_END_CUT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_IC_SIZE_SHIFT
value|FMAN_SP_IC_SIZE_SHIFT
end_define

begin_define
define|#
directive|define
name|BMI_INT_BUF_MARG_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|BMI_EXT_BUF_MARG_END_SHIFT
value|FMAN_SP_EXT_BUF_MARG_END_SHIFT
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_COLOR_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_COM_MODE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MACCMD_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MACCMD_OVERRIDE_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MACCMD_SECURED_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BMI_CMD_ATTR_MACCMD_SC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BMI_POOL_DEP_NUM_OF_POOLS_VECTOR_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BMI_TX_FIFO_MIN_FILL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_TX_LOW_COMF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMI_PERFORMANCE_TASK_COMP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BMI_PERFORMANCE_PORT_COMP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_PERFORMANCE_DMA_COMP_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BMI_PERFORMANCE_FIFO_COMP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMI_MAX_BURST_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_COUNT_RATE_UNIT_SHIFT
value|16
end_define

begin_comment
comment|/* sizes */
end_comment

begin_define
define|#
directive|define
name|FRAME_END_DATA_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|FRAME_OFFSET_UNITS
value|16
end_define

begin_define
define|#
directive|define
name|MIN_TX_INT_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|MAX_FRAME_OFFSET
value|64
end_define

begin_define
define|#
directive|define
name|MAX_FIFO_PIPELINE_DEPTH
value|8
end_define

begin_define
define|#
directive|define
name|MAX_PERFORMANCE_TASK_COMP
value|64
end_define

begin_define
define|#
directive|define
name|MAX_PERFORMANCE_TX_QUEUE_COMP
value|8
end_define

begin_define
define|#
directive|define
name|MAX_PERFORMANCE_RX_QUEUE_COMP
value|64
end_define

begin_define
define|#
directive|define
name|MAX_PERFORMANCE_DMA_COMP
value|16
end_define

begin_define
define|#
directive|define
name|MAX_NUM_OF_TASKS
value|64
end_define

begin_define
define|#
directive|define
name|MAX_NUM_OF_EXTRA_TASKS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_NUM_OF_DMAS
value|16
end_define

begin_define
define|#
directive|define
name|MAX_NUM_OF_EXTRA_DMAS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_BURST_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|MIN_NUM_OF_OP_DMAS
value|2
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       QMI defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|QMI_PORT_CFG_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QMI_PORT_CFG_EN_COUNTERS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QMI_PORT_STATUS_DEQ_TNUM_BSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QMI_PORT_STATUS_DEQ_FD_BSY
value|0x20000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_PREFETCH_NO_TNUM
value|0x02000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_PREFETCH_WAITING_TNUM
value|0
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_PREFETCH_1_FRAME
value|0
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_PREFETCH_3_FRAMES
value|0x01000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_PRI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_TYPE1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_TYPE2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_TYPE3
value|0x30000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_SUBPORTAL_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_SUBPORTAL_SHIFT
value|20
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       PARSER defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|PRS_HDR_ERROR_DIS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PRS_HDR_SW_PRS_EN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PRS_CP_OFFSET_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|PRS_TPID1_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|PRS_TPID2_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|PRS_TPID_DFLT
value|0x91009100
end_define

begin_define
define|#
directive|define
name|PRS_HDR_MPLS_LBL_INTER_EN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV6_ROUTE_HDR_EN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PRS_HDR_PPPOE_MTU_CHECK_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PRS_HDR_UDP_PAD_REMOVAL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PRS_HDR_TCP_PAD_REMOVAL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PRS_CAC_STOP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PRS_CAC_ACTIVE
value|0x00000100
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|PRS_PCTPID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PRS_HDR_MPLS_NEXT_HDR_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|PRS_HDR_ETH_BC_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|PRS_HDR_ETH_MC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PRS_HDR_VLAN_STACKED_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PRS_HDR_MPLS_STACKED_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV4_1_BC_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV4_1_MC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV4_2_UC_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV4_2_MC_BC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV6_1_MC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV6_2_UC_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV6_2_MC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PRS_HDR_ETH_BC_MASK
value|0x0fffffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_ETH_MC_MASK
value|0xf0ffffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_VLAN_STACKED_MASK
value|0xfff0ffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_MPLS_STACKED_MASK
value|0xfff0ffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV4_1_BC_MASK
value|0x0fffffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV4_1_MC_MASK
value|0xf0ffffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV4_2_UC_MASK
value|0xff0fffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV4_2_MC_BC_MASK
value|0xfff0ffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV6_1_MC_MASK
value|0xf0ffffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV6_2_UC_MASK
value|0xff0fffff
end_define

begin_define
define|#
directive|define
name|PRS_HDR_IPV6_2_MC_MASK
value|0xfff0ffff
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|PRS_HDR_ENTRY_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|DEFAULT_CLS_PLAN_VECTOR
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|IPSEC_SW_PATCH_START
value|0x20
end_define

begin_define
define|#
directive|define
name|SCTP_SW_PATCH_START
value|0x4D
end_define

begin_define
define|#
directive|define
name|DCCP_SW_PATCH_START
value|0x41
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       IM defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BD_R_E
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BD_L
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BD_RX_CRE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BD_RX_FTL
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BD_RX_FTS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BD_RX_OV
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BD_RX_ERRORS
value|(BD_RX_CRE | BD_RX_FTL | BD_RX_FTS | BD_RX_OV)
end_define

begin_define
define|#
directive|define
name|FM_IM_SIZEOF_BD
value|sizeof(t_FmImBd)
end_define

begin_define
define|#
directive|define
name|BD_STATUS_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|BD_LENGTH_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|BD_STATUS_AND_LENGTH_SET
parameter_list|(
name|bd
parameter_list|,
name|val
parameter_list|)
value|WRITE_UINT32(*(volatile uint32_t*)(bd), (val))
end_define

begin_define
define|#
directive|define
name|BD_STATUS_AND_LENGTH
parameter_list|(
name|bd
parameter_list|)
value|GET_UINT32(*(volatile uint32_t*)(bd))
end_define

begin_define
define|#
directive|define
name|BD_GET
parameter_list|(
name|id
parameter_list|)
value|&p_FmPort->im.p_BdRing[id]
end_define

begin_define
define|#
directive|define
name|IM_ILEGAL_BD_ID
value|0xffff
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|IM_PRAM_ALIGN
value|0x100
end_define

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|IM_MODE_GBL
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IM_MODE_BO_MASK
value|0x18000000
end_define

begin_define
define|#
directive|define
name|IM_MODE_BO_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|IM_MODE_GRC_STP
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IM_MODE_SET_BO
parameter_list|(
name|val
parameter_list|)
value|(uint32_t)((val<< (31-IM_MODE_BO_SHIFT))& IM_MODE_BO_MASK)
end_define

begin_define
define|#
directive|define
name|IM_RXQD_BSYINTM
value|0x0008
end_define

begin_define
define|#
directive|define
name|IM_RXQD_RXFINTM
value|0x0010
end_define

begin_define
define|#
directive|define
name|IM_RXQD_FPMEVT_SEL_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|IM_EV_BSY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IM_EV_RX
value|0x80000000
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Additional defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_Handle
name|h_FmMuram
decl_stmt|;
name|t_FmPortImPram
modifier|*
name|p_FmPortImPram
decl_stmt|;
name|uint8_t
name|fwExtStructsMemId
decl_stmt|;
name|uint32_t
name|fwExtStructsMemAttr
decl_stmt|;
name|uint16_t
name|bdRingSize
decl_stmt|;
name|t_FmImBd
modifier|*
name|p_BdRing
decl_stmt|;
name|t_Handle
modifier|*
name|p_BdShadow
decl_stmt|;
name|uint16_t
name|currBdId
decl_stmt|;
name|uint16_t
name|firstBdOfFrameId
decl_stmt|;
comment|/* Rx port parameters */
name|uint8_t
name|dataMemId
decl_stmt|;
comment|/**< Memory partition ID for data buffers */
name|uint32_t
name|dataMemAttributes
decl_stmt|;
comment|/**< Memory attributes for data buffers */
name|t_BufferPoolInfo
name|rxPool
decl_stmt|;
name|uint16_t
name|mrblr
decl_stmt|;
name|uint16_t
name|rxFrameAccumLength
decl_stmt|;
name|t_FmPortImRxStoreCallback
modifier|*
name|f_RxStore
decl_stmt|;
comment|/* Tx port parameters */
name|uint32_t
name|txFirstBdStatus
decl_stmt|;
name|t_FmPortImTxConfCallback
modifier|*
name|f_TxConf
decl_stmt|;
block|}
name|t_FmMacIm
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|fman_port_cfg
name|dfltCfg
decl_stmt|;
name|uint32_t
name|dfltFqid
decl_stmt|;
name|uint32_t
name|confFqid
decl_stmt|;
name|uint32_t
name|errFqid
decl_stmt|;
name|uintptr_t
name|baseAddr
decl_stmt|;
name|uint8_t
name|deqSubPortal
decl_stmt|;
name|bool
name|deqHighPriority
decl_stmt|;
name|e_FmPortDeqType
name|deqType
decl_stmt|;
name|e_FmPortDeqPrefetchOption
name|deqPrefetchOption
decl_stmt|;
name|uint16_t
name|deqByteCnt
decl_stmt|;
name|uint8_t
name|cheksumLastBytesIgnore
decl_stmt|;
name|uint8_t
name|cutBytesFromEnd
decl_stmt|;
name|t_FmBufPoolDepletion
name|bufPoolDepletion
decl_stmt|;
name|uint8_t
name|pipelineDepth
decl_stmt|;
name|uint16_t
name|fifoLowComfLevel
decl_stmt|;
name|bool
name|frmDiscardOverride
decl_stmt|;
name|bool
name|enRateLimit
decl_stmt|;
name|t_FmPortRateLimit
name|rateLimit
decl_stmt|;
name|e_FmPortDualRateLimiterScaleDown
name|rateLimitDivider
decl_stmt|;
name|bool
name|enBufPoolDepletion
decl_stmt|;
name|uint16_t
name|liodnOffset
decl_stmt|;
name|uint16_t
name|liodnBase
decl_stmt|;
name|t_FmExtPools
name|extBufPools
decl_stmt|;
name|e_FmDmaSwapOption
name|dmaSwapData
decl_stmt|;
name|e_FmDmaCacheOption
name|dmaIntContextCacheAttr
decl_stmt|;
name|e_FmDmaCacheOption
name|dmaHeaderCacheAttr
decl_stmt|;
name|e_FmDmaCacheOption
name|dmaScatterGatherCacheAttr
decl_stmt|;
name|bool
name|dmaReadOptimize
decl_stmt|;
name|bool
name|dmaWriteOptimize
decl_stmt|;
name|uint32_t
name|txFifoMinFillLevel
decl_stmt|;
name|uint32_t
name|txFifoLowComfLevel
decl_stmt|;
name|uint32_t
name|rxFifoPriElevationLevel
decl_stmt|;
name|uint32_t
name|rxFifoThreshold
decl_stmt|;
name|t_FmSpBufMargins
name|bufMargins
decl_stmt|;
name|t_FmSpIntContextDataCopy
name|intContext
decl_stmt|;
name|bool
name|syncReq
decl_stmt|;
name|e_FmPortColor
name|color
decl_stmt|;
name|fmPortFrameErrSelect_t
name|errorsToDiscard
decl_stmt|;
name|fmPortFrameErrSelect_t
name|errorsToEnq
decl_stmt|;
name|bool
name|forwardReuseIntContext
decl_stmt|;
name|t_FmBufferPrefixContent
name|bufferPrefixContent
decl_stmt|;
name|t_FmBackupBmPools
modifier|*
name|p_BackupBmPools
decl_stmt|;
name|bool
name|dontReleaseBuf
decl_stmt|;
name|bool
name|setNumOfTasks
decl_stmt|;
name|bool
name|setNumOfOpenDmas
decl_stmt|;
name|bool
name|setSizeOfFifo
decl_stmt|;
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|bool
name|noScatherGather
decl_stmt|;
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
ifdef|#
directive|ifdef
name|FM_HEAVY_TRAFFIC_HANG_ERRATA_FMAN_A005669
name|bool
name|bcbWorkaround
decl_stmt|;
endif|#
directive|endif
comment|/* FM_HEAVY_TRAFFIC_HANG_ERRATA_FMAN_A005669 */
block|}
name|t_FmPortDriverParam
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortRxPoolsParams
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
name|t_FmPortRxPoolsParams
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|t_FmPortDsarVars
block|{
name|t_Handle
modifier|*
name|autoResOffsets
decl_stmt|;
name|t_FmPortDsarTablesSizes
modifier|*
name|autoResMaxSizes
decl_stmt|;
name|uint32_t
name|fmbm_tcfg
decl_stmt|;
name|uint32_t
name|fmbm_tcmne
decl_stmt|;
name|uint32_t
name|fmbm_rfne
decl_stmt|;
name|uint32_t
name|fmbm_rfpne
decl_stmt|;
name|uint32_t
name|fmbm_rcfg
decl_stmt|;
name|bool
name|dsarEnabledParser
decl_stmt|;
block|}
name|t_FmPortDsarVars
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|fman_port
name|port
decl_stmt|;
name|t_Handle
name|h_Fm
decl_stmt|;
name|t_Handle
name|h_FmPcd
decl_stmt|;
name|t_Handle
name|h_FmMuram
decl_stmt|;
name|t_FmRevisionInfo
name|fmRevInfo
decl_stmt|;
name|uint8_t
name|portId
decl_stmt|;
name|e_FmPortType
name|portType
decl_stmt|;
name|int
name|enabled
decl_stmt|;
name|char
name|name
index|[
name|MODULE_NAME_SIZE
index|]
decl_stmt|;
name|uint8_t
name|hardwarePortId
decl_stmt|;
name|uint16_t
name|fmClkFreq
decl_stmt|;
name|t_FmPortQmiRegs
modifier|*
name|p_FmPortQmiRegs
decl_stmt|;
name|u_FmPortBmiRegs
modifier|*
name|p_FmPortBmiRegs
decl_stmt|;
name|t_FmPortPrsRegs
modifier|*
name|p_FmPortPrsRegs
decl_stmt|;
name|fmPcdEngines_t
name|pcdEngines
decl_stmt|;
name|uint32_t
name|savedBmiNia
decl_stmt|;
name|uint8_t
name|netEnvId
decl_stmt|;
name|uint32_t
name|optArray
index|[
name|FM_PCD_MAX_NUM_OF_OPTIONS
argument_list|(
name|FM_PCD_MAX_NUM_OF_CLS_PLANS
argument_list|)
index|]
decl_stmt|;
name|uint32_t
name|lcvs
index|[
name|FM_PCD_PRS_NUM_OF_HDRS
index|]
decl_stmt|;
name|uint8_t
name|privateInfo
decl_stmt|;
name|uint32_t
name|schemesPerPortVector
decl_stmt|;
name|bool
name|useClsPlan
decl_stmt|;
name|uint8_t
name|clsPlanGrpId
decl_stmt|;
name|t_Handle
name|ccTreeId
decl_stmt|;
name|t_Handle
name|completeArg
decl_stmt|;
name|void
function_decl|(
modifier|*
name|f_Complete
function_decl|)
parameter_list|(
name|t_Handle
name|arg
parameter_list|)
function_decl|;
name|t_FmSpBufferOffsets
name|bufferOffsets
decl_stmt|;
comment|/* Independent-Mode parameters support */
name|bool
name|imEn
decl_stmt|;
name|t_FmMacIm
name|im
decl_stmt|;
specifier|volatile
name|bool
name|lock
decl_stmt|;
name|t_Handle
name|h_Spinlock
decl_stmt|;
name|t_FmPortExceptionCallback
modifier|*
name|f_Exception
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
name|uint8_t
name|internalBufferOffset
decl_stmt|;
name|uint8_t
name|fmanCtrlEventId
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|bool
name|polling
decl_stmt|;
name|t_FmExtPools
name|extBufPools
decl_stmt|;
name|uint32_t
name|requiredAction
decl_stmt|;
name|uint32_t
name|savedQmiPnen
decl_stmt|;
name|uint32_t
name|savedBmiFene
decl_stmt|;
name|uint32_t
name|savedBmiFpne
decl_stmt|;
name|uint32_t
name|savedBmiCmne
decl_stmt|;
name|uint32_t
name|savedBmiOfp
decl_stmt|;
name|uint32_t
name|savedNonRxQmiRegsPndn
decl_stmt|;
name|uint32_t
name|origNonRxQmiRegsPndn
decl_stmt|;
name|int
name|savedPrsStartOffset
decl_stmt|;
name|bool
name|includeInPrsStatistics
decl_stmt|;
name|uint16_t
name|maxFrameLength
decl_stmt|;
name|t_FmFmanCtrl
name|orFmanCtrl
decl_stmt|;
name|t_FmPortRsrc
name|openDmas
decl_stmt|;
name|t_FmPortRsrc
name|tasks
decl_stmt|;
name|t_FmPortRsrc
name|fifoBufs
decl_stmt|;
name|t_FmPortRxPoolsParams
name|rxPoolsParams
decl_stmt|;
comment|//    bool                        explicitUserSizeOfFifo;
name|t_Handle
name|h_IpReassemblyManip
decl_stmt|;
name|t_Handle
name|h_CapwapReassemblyManip
decl_stmt|;
name|t_Handle
name|h_ReassemblyTree
decl_stmt|;
name|uint64_t
name|fmMuramPhysBaseAddr
decl_stmt|;
if|#
directive|if
operator|(
name|DPAA_VERSION
operator|>=
literal|11
operator|)
name|bool
name|vspe
decl_stmt|;
name|uint8_t
name|dfltRelativeId
decl_stmt|;
name|e_FmPortGprFuncType
name|gprFunc
decl_stmt|;
name|t_FmPcdCtrlParamsPage
modifier|*
name|p_ParamsPage
decl_stmt|;
endif|#
directive|endif
comment|/* (DPAA_VERSION>= 11) */
name|t_FmPortDsarVars
name|deepSleepVars
decl_stmt|;
name|t_FmPortDriverParam
modifier|*
name|p_FmPortDriverParam
decl_stmt|;
block|}
name|t_FmPort
typedef|;
end_typedef

begin_function_decl
name|void
name|FmPortConfigIM
parameter_list|(
name|t_FmPort
modifier|*
name|p_FmPort
parameter_list|,
name|t_FmPortParams
modifier|*
name|p_FmPortParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPortImCheckInitParameters
parameter_list|(
name|t_FmPort
modifier|*
name|p_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPortImInit
parameter_list|(
name|t_FmPort
modifier|*
name|p_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPortImFree
parameter_list|(
name|t_FmPort
modifier|*
name|p_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPortImEnable
parameter_list|(
name|t_FmPort
modifier|*
name|p_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPortImDisable
parameter_list|(
name|t_FmPort
modifier|*
name|p_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FmPortImRx
parameter_list|(
name|t_FmPort
modifier|*
name|p_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPortSetMacsecLcv
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FmPortSetMacsecCmd
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|uint8_t
name|dfltSci
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FM_PORT_SetNumOfOpenDmas
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortRsrc
modifier|*
name|p_NumOfOpenDmas
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FM_PORT_SetNumOfTasks
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortRsrc
modifier|*
name|p_NumOfTasks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|FM_PORT_SetSizeOfFifo
parameter_list|(
name|t_Handle
name|h_FmPort
parameter_list|,
name|t_FmPortRsrc
modifier|*
name|p_SizeOfFifo
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline__
name|uint8_t
modifier|*
name|BdBufferGet
parameter_list|(
name|t_PhysToVirt
modifier|*
name|f_PhysToVirt
parameter_list|,
name|t_FmImBd
modifier|*
name|p_Bd
parameter_list|)
block|{
name|uint64_t
name|physAddr
init|=
call|(
name|uint64_t
call|)
argument_list|(
operator|(
name|uint64_t
operator|)
name|GET_UINT8
argument_list|(
name|p_Bd
operator|->
name|buff
operator|.
name|high
argument_list|)
operator|<<
literal|32
argument_list|)
decl_stmt|;
name|physAddr
operator||=
name|GET_UINT32
argument_list|(
name|p_Bd
operator|->
name|buff
operator|.
name|low
argument_list|)
expr_stmt|;
return|return
operator|(
name|uint8_t
operator|*
operator|)
name|f_PhysToVirt
argument_list|(
call|(
name|physAddress_t
call|)
argument_list|(
name|physAddr
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|SET_ADDR
parameter_list|(
specifier|volatile
name|t_FmPhysAddr
modifier|*
name|fmPhysAddr
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
name|WRITE_UINT8
argument_list|(
name|fmPhysAddr
operator|->
name|high
argument_list|,
call|(
name|uint8_t
call|)
argument_list|(
operator|(
name|value
operator|&
literal|0x000000ff00000000LL
operator|)
operator|>>
literal|32
argument_list|)
argument_list|)
expr_stmt|;
name|WRITE_UINT32
argument_list|(
name|fmPhysAddr
operator|->
name|low
argument_list|,
operator|(
name|uint32_t
operator|)
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|BdBufferSet
parameter_list|(
name|t_VirtToPhys
modifier|*
name|f_VirtToPhys
parameter_list|,
name|t_FmImBd
modifier|*
name|p_Bd
parameter_list|,
name|uint8_t
modifier|*
name|p_Buffer
parameter_list|)
block|{
name|uint64_t
name|physAddr
init|=
call|(
name|uint64_t
call|)
argument_list|(
name|f_VirtToPhys
argument_list|(
name|p_Buffer
argument_list|)
argument_list|)
decl_stmt|;
name|SET_ADDR
argument_list|(
operator|&
name|p_Bd
operator|->
name|buff
argument_list|,
name|physAddr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint16_t
name|GetNextBdId
parameter_list|(
name|t_FmPort
modifier|*
name|p_FmPort
parameter_list|,
name|uint16_t
name|id
parameter_list|)
block|{
if|if
condition|(
name|id
operator|<
name|p_FmPort
operator|->
name|im
operator|.
name|bdRingSize
operator|-
literal|1
condition|)
return|return
call|(
name|uint16_t
call|)
argument_list|(
name|id
operator|+
literal|1
argument_list|)
return|;
else|else
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|void
name|FM_PORT_Dsar_DumpRegs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_PORT_H */
end_comment

end_unit

