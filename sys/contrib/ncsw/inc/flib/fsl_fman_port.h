begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2013 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_PORT_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_PORT_H
end_define

begin_include
include|#
directive|include
file|"fsl_fman_sp.h"
end_include

begin_comment
comment|/** @Collection  Registers bit fields */
end_comment

begin_comment
comment|/** @Description  BMI defines */
end_comment

begin_define
define|#
directive|define
name|BMI_EBD_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_PORT_CFG_EN
value|0x80000000
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
name|BMI_PORT_STATUS_BSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_DMA_ATTR_SWP_SHIFT
value|FMAN_SP_DMA_ATTR_SWP_SHIFT
end_define

begin_define
define|#
directive|define
name|BMI_DMA_ATTR_IC_STASH_ON
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BMI_DMA_ATTR_HDR_STASH_ON
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BMI_DMA_ATTR_SG_STASH_ON
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BMI_DMA_ATTR_WRITE_OPTIMIZE
value|FMAN_SP_DMA_ATTR_WRITE_OPTIMIZE
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
name|BMI_RX_FIFO_THRESHOLD_ETHE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_TX_FRAME_END_CS_IGNORE_SHIFT
value|24
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
name|BMI_IC_TO_EXT_SHIFT
value|FMAN_SP_IC_TO_EXT_SHIFT
end_define

begin_define
define|#
directive|define
name|BMI_IC_FROM_INT_SHIFT
value|FMAN_SP_IC_FROM_INT_SHIFT
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
name|BMI_EXT_BUF_MARG_START_SHIFT
value|FMAN_SP_EXT_BUF_MARG_START_SHIFT
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
value|(BMI_CMD_MR_LEAC | \ 						BMI_CMD_MR_SLEAC | \ 						BMI_CMD_MR_MA | \ 						BMI_CMD_MR_DEAS)
end_define

begin_define
define|#
directive|define
name|BMI_CMD_TX_MR_DEF
value|0
end_define

begin_define
define|#
directive|define
name|BMI_CMD_OP_MR_DEF
value|(BMI_CMD_MR_DEAS | \ 						BMI_CMD_MR_MA)
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
name|BMI_CMD_ATTR_COLOR_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|BMI_FIFO_PIPELINE_DEPTH_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BMI_NEXT_ENG_FD_BITS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BMI_FRAME_END_CS_IGNORE_SHIFT
value|24
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
name|BMI_EXT_BUF_POOL_VALID
value|FMAN_SP_EXT_BUF_POOL_VALID
end_define

begin_define
define|#
directive|define
name|BMI_EXT_BUF_POOL_EN_COUNTER
value|FMAN_SP_EXT_BUF_POOL_EN_COUNTER
end_define

begin_define
define|#
directive|define
name|BMI_EXT_BUF_POOL_BACKUP
value|FMAN_SP_EXT_BUF_POOL_BACKUP
end_define

begin_define
define|#
directive|define
name|BMI_EXT_BUF_POOL_ID_SHIFT
value|16
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
name|BMI_POOL_DEP_NUM_OF_POOLS_SHIFT
value|16
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
name|BMI_TX_FIFO_PIPELINE_DEPTH_SHIFT
value|12
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
name|MAX_PERFORMANCE_RX_QUEUE_COMP
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
name|MAX_PERFORMANCE_DMA_COMP
value|16
end_define

begin_define
define|#
directive|define
name|MAX_PERFORMANCE_FIFO_COMP
value|1024
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
name|BMI_PERFORMANCE_QUEUE_COMP_SHIFT
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
name|BMI_RATE_LIMIT_GRAN_TX
value|16000
end_define

begin_comment
comment|/* In Kbps */
end_comment

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_GRAN_OP
value|10000
end_define

begin_comment
comment|/* In frames */
end_comment

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_MAX_RATE_IN_GRAN_UNITS
value|1024
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_MAX_BURST_SIZE
value|1024
end_define

begin_comment
comment|/* In KBytes */
end_comment

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_MAX_BURST_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_HIGH_BURST_SIZE_GRAN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_SCALE_TSBS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_RATE_LIMIT_SCALE_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_SG_DISABLE
value|FMAN_SP_SG_DISABLE
end_define

begin_comment
comment|/** @Description  QMI defines */
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
name|QMI_DEQ_CFG_PREFETCH_PARTIAL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_PREFETCH_FULL
value|0x03000000
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_SP_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|QMI_DEQ_CFG_SP_SHIFT
value|20
end_define

begin_comment
comment|/** @Description  General port defines */
end_comment

begin_define
define|#
directive|define
name|FMAN_PORT_EXT_POOLS_NUM
parameter_list|(
name|fm_rev_maj
parameter_list|)
define|\
value|(((fm_rev_maj) == 4) ? 4 : 8)
end_define

begin_define
define|#
directive|define
name|FMAN_PORT_MAX_EXT_POOLS_NUM
value|8
end_define

begin_define
define|#
directive|define
name|FMAN_PORT_OBS_EXT_POOLS_NUM
value|2
end_define

begin_define
define|#
directive|define
name|FMAN_PORT_CG_MAP_NUM
value|8
end_define

begin_define
define|#
directive|define
name|FMAN_PORT_PRS_RESULT_WORDS_NUM
value|8
end_define

begin_define
define|#
directive|define
name|FMAN_PORT_BMI_FIFO_UNITS
value|0x100
end_define

begin_define
define|#
directive|define
name|FMAN_PORT_IC_OFFSET_UNITS
value|0x10
end_define

begin_comment
comment|/** @Collection    FM Port Register Map */
end_comment

begin_comment
comment|/** @Description   BMI Rx port register map */
end_comment

begin_struct
struct|struct
name|fman_port_rx_bmi_regs
block|{
name|uint32_t
name|fmbm_rcfg
decl_stmt|;
comment|/**< Rx Configuration */
name|uint32_t
name|fmbm_rst
decl_stmt|;
comment|/**< Rx Status */
name|uint32_t
name|fmbm_rda
decl_stmt|;
comment|/**< Rx DMA attributes*/
name|uint32_t
name|fmbm_rfp
decl_stmt|;
comment|/**< Rx FIFO Parameters*/
name|uint32_t
name|fmbm_rfed
decl_stmt|;
comment|/**< Rx Frame End Data*/
name|uint32_t
name|fmbm_ricp
decl_stmt|;
comment|/**< Rx Internal Context Parameters*/
name|uint32_t
name|fmbm_rim
decl_stmt|;
comment|/**< Rx Internal Buffer Margins*/
name|uint32_t
name|fmbm_rebm
decl_stmt|;
comment|/**< Rx External Buffer Margins*/
name|uint32_t
name|fmbm_rfne
decl_stmt|;
comment|/**< Rx Frame Next Engine*/
name|uint32_t
name|fmbm_rfca
decl_stmt|;
comment|/**< Rx Frame Command Attributes.*/
name|uint32_t
name|fmbm_rfpne
decl_stmt|;
comment|/**< Rx Frame Parser Next Engine*/
name|uint32_t
name|fmbm_rpso
decl_stmt|;
comment|/**< Rx Parse Start Offset*/
name|uint32_t
name|fmbm_rpp
decl_stmt|;
comment|/**< Rx Policer Profile  */
name|uint32_t
name|fmbm_rccb
decl_stmt|;
comment|/**< Rx Coarse Classification Base */
name|uint32_t
name|fmbm_reth
decl_stmt|;
comment|/**< Rx Excessive Threshold */
name|uint32_t
name|reserved003c
index|[
literal|1
index|]
decl_stmt|;
comment|/**< (0x03C 0x03F) */
name|uint32_t
name|fmbm_rprai
index|[
name|FMAN_PORT_PRS_RESULT_WORDS_NUM
index|]
decl_stmt|;
comment|/**< Rx Parse Results Array Init*/
name|uint32_t
name|fmbm_rfqid
decl_stmt|;
comment|/**< Rx Frame Queue ID*/
name|uint32_t
name|fmbm_refqid
decl_stmt|;
comment|/**< Rx Error Frame Queue ID*/
name|uint32_t
name|fmbm_rfsdm
decl_stmt|;
comment|/**< Rx Frame Status Discard Mask*/
name|uint32_t
name|fmbm_rfsem
decl_stmt|;
comment|/**< Rx Frame Status Error Mask*/
name|uint32_t
name|fmbm_rfene
decl_stmt|;
comment|/**< Rx Frame Enqueue Next Engine */
name|uint32_t
name|reserved0074
index|[
literal|0x2
index|]
decl_stmt|;
comment|/**< (0x074-0x07C)  */
name|uint32_t
name|fmbm_rcmne
decl_stmt|;
comment|/**< Rx Frame Continuous Mode Next Engine */
name|uint32_t
name|reserved0080
index|[
literal|0x20
index|]
decl_stmt|;
comment|/**< (0x080 0x0FF)  */
name|uint32_t
name|fmbm_ebmpi
index|[
name|FMAN_PORT_MAX_EXT_POOLS_NUM
index|]
decl_stmt|;
comment|/**< Buffer Manager pool Information-*/
name|uint32_t
name|fmbm_acnt
index|[
name|FMAN_PORT_MAX_EXT_POOLS_NUM
index|]
decl_stmt|;
comment|/**< Allocate Counter-*/
name|uint32_t
name|reserved0130
index|[
literal|8
index|]
decl_stmt|;
comment|/**< 0x130/0x140 - 0x15F reserved -*/
name|uint32_t
name|fmbm_rcgm
index|[
name|FMAN_PORT_CG_MAP_NUM
index|]
decl_stmt|;
comment|/**< Congestion Group Map*/
name|uint32_t
name|fmbm_mpd
decl_stmt|;
comment|/**< BM Pool Depletion  */
name|uint32_t
name|reserved0184
index|[
literal|0x1F
index|]
decl_stmt|;
comment|/**< (0x184 0x1FF) */
name|uint32_t
name|fmbm_rstc
decl_stmt|;
comment|/**< Rx Statistics Counters*/
name|uint32_t
name|fmbm_rfrc
decl_stmt|;
comment|/**< Rx Frame Counter*/
name|uint32_t
name|fmbm_rfbc
decl_stmt|;
comment|/**< Rx Bad Frames Counter*/
name|uint32_t
name|fmbm_rlfc
decl_stmt|;
comment|/**< Rx Large Frames Counter*/
name|uint32_t
name|fmbm_rffc
decl_stmt|;
comment|/**< Rx Filter Frames Counter*/
name|uint32_t
name|fmbm_rfdc
decl_stmt|;
comment|/**< Rx Frame Discard Counter*/
name|uint32_t
name|fmbm_rfldec
decl_stmt|;
comment|/**< Rx Frames List DMA Error Counter*/
name|uint32_t
name|fmbm_rodc
decl_stmt|;
comment|/**< Rx Out of Buffers Discard nntr*/
name|uint32_t
name|fmbm_rbdc
decl_stmt|;
comment|/**< Rx Buffers Deallocate Counter*/
name|uint32_t
name|reserved0224
index|[
literal|0x17
index|]
decl_stmt|;
comment|/**< (0x224 0x27F) */
name|uint32_t
name|fmbm_rpc
decl_stmt|;
comment|/**< Rx Performance Counters*/
name|uint32_t
name|fmbm_rpcp
decl_stmt|;
comment|/**< Rx Performance Count Parameters*/
name|uint32_t
name|fmbm_rccn
decl_stmt|;
comment|/**< Rx Cycle Counter*/
name|uint32_t
name|fmbm_rtuc
decl_stmt|;
comment|/**< Rx Tasks Utilization Counter*/
name|uint32_t
name|fmbm_rrquc
decl_stmt|;
comment|/**< Rx Receive Queue Utilization cntr*/
name|uint32_t
name|fmbm_rduc
decl_stmt|;
comment|/**< Rx DMA Utilization Counter*/
name|uint32_t
name|fmbm_rfuc
decl_stmt|;
comment|/**< Rx FIFO Utilization Counter*/
name|uint32_t
name|fmbm_rpac
decl_stmt|;
comment|/**< Rx Pause Activation Counter*/
name|uint32_t
name|reserved02a0
index|[
literal|0x18
index|]
decl_stmt|;
comment|/**< (0x2A0 0x2FF) */
name|uint32_t
name|fmbm_rdbg
decl_stmt|;
comment|/**< Rx Debug-*/
block|}
struct|;
end_struct

begin_comment
comment|/** @Description   BMI Tx port register map */
end_comment

begin_struct
struct|struct
name|fman_port_tx_bmi_regs
block|{
name|uint32_t
name|fmbm_tcfg
decl_stmt|;
comment|/**< Tx Configuration */
name|uint32_t
name|fmbm_tst
decl_stmt|;
comment|/**< Tx Status */
name|uint32_t
name|fmbm_tda
decl_stmt|;
comment|/**< Tx DMA attributes */
name|uint32_t
name|fmbm_tfp
decl_stmt|;
comment|/**< Tx FIFO Parameters */
name|uint32_t
name|fmbm_tfed
decl_stmt|;
comment|/**< Tx Frame End Data */
name|uint32_t
name|fmbm_ticp
decl_stmt|;
comment|/**< Tx Internal Context Parameters */
name|uint32_t
name|fmbm_tfdne
decl_stmt|;
comment|/**< Tx Frame Dequeue Next Engine. */
name|uint32_t
name|fmbm_tfca
decl_stmt|;
comment|/**< Tx Frame Command attribute. */
name|uint32_t
name|fmbm_tcfqid
decl_stmt|;
comment|/**< Tx Confirmation Frame Queue ID. */
name|uint32_t
name|fmbm_tefqid
decl_stmt|;
comment|/**< Tx Frame Error Queue ID */
name|uint32_t
name|fmbm_tfene
decl_stmt|;
comment|/**< Tx Frame Enqueue Next Engine */
name|uint32_t
name|fmbm_trlmts
decl_stmt|;
comment|/**< Tx Rate Limiter Scale */
name|uint32_t
name|fmbm_trlmt
decl_stmt|;
comment|/**< Tx Rate Limiter */
name|uint32_t
name|reserved0034
index|[
literal|0x0e
index|]
decl_stmt|;
comment|/**< (0x034-0x6c) */
name|uint32_t
name|fmbm_tccb
decl_stmt|;
comment|/**< Tx Coarse Classification base */
name|uint32_t
name|fmbm_tfne
decl_stmt|;
comment|/**< Tx Frame Next Engine */
name|uint32_t
name|fmbm_tpfcm
index|[
literal|0x02
index|]
decl_stmt|;
comment|/**< Tx Priority based Flow Control (PFC) Mapping */
name|uint32_t
name|fmbm_tcmne
decl_stmt|;
comment|/**< Tx Frame Continuous Mode Next Engine */
name|uint32_t
name|reserved0080
index|[
literal|0x60
index|]
decl_stmt|;
comment|/**< (0x080-0x200) */
name|uint32_t
name|fmbm_tstc
decl_stmt|;
comment|/**< Tx Statistics Counters */
name|uint32_t
name|fmbm_tfrc
decl_stmt|;
comment|/**< Tx Frame Counter */
name|uint32_t
name|fmbm_tfdc
decl_stmt|;
comment|/**< Tx Frames Discard Counter */
name|uint32_t
name|fmbm_tfledc
decl_stmt|;
comment|/**< Tx Frame len error discard cntr */
name|uint32_t
name|fmbm_tfufdc
decl_stmt|;
comment|/**< Tx Frame unsprt frmt discard cntr*/
name|uint32_t
name|fmbm_tbdc
decl_stmt|;
comment|/**< Tx Buffers Deallocate Counter */
name|uint32_t
name|reserved0218
index|[
literal|0x1A
index|]
decl_stmt|;
comment|/**< (0x218-0x280) */
name|uint32_t
name|fmbm_tpc
decl_stmt|;
comment|/**< Tx Performance Counters*/
name|uint32_t
name|fmbm_tpcp
decl_stmt|;
comment|/**< Tx Performance Count Parameters*/
name|uint32_t
name|fmbm_tccn
decl_stmt|;
comment|/**< Tx Cycle Counter*/
name|uint32_t
name|fmbm_ttuc
decl_stmt|;
comment|/**< Tx Tasks Utilization Counter*/
name|uint32_t
name|fmbm_ttcquc
decl_stmt|;
comment|/**< Tx Transmit conf Q util Counter*/
name|uint32_t
name|fmbm_tduc
decl_stmt|;
comment|/**< Tx DMA Utilization Counter*/
name|uint32_t
name|fmbm_tfuc
decl_stmt|;
comment|/**< Tx FIFO Utilization Counter*/
block|}
struct|;
end_struct

begin_comment
comment|/** @Description   BMI O/H port register map */
end_comment

begin_struct
struct|struct
name|fman_port_oh_bmi_regs
block|{
name|uint32_t
name|fmbm_ocfg
decl_stmt|;
comment|/**< O/H Configuration  */
name|uint32_t
name|fmbm_ost
decl_stmt|;
comment|/**< O/H Status */
name|uint32_t
name|fmbm_oda
decl_stmt|;
comment|/**< O/H DMA attributes  */
name|uint32_t
name|fmbm_oicp
decl_stmt|;
comment|/**< O/H Internal Context Parameters */
name|uint32_t
name|fmbm_ofdne
decl_stmt|;
comment|/**< O/H Frame Dequeue Next Engine  */
name|uint32_t
name|fmbm_ofne
decl_stmt|;
comment|/**< O/H Frame Next Engine  */
name|uint32_t
name|fmbm_ofca
decl_stmt|;
comment|/**< O/H Frame Command Attributes.  */
name|uint32_t
name|fmbm_ofpne
decl_stmt|;
comment|/**< O/H Frame Parser Next Engine  */
name|uint32_t
name|fmbm_opso
decl_stmt|;
comment|/**< O/H Parse Start Offset  */
name|uint32_t
name|fmbm_opp
decl_stmt|;
comment|/**< O/H Policer Profile */
name|uint32_t
name|fmbm_occb
decl_stmt|;
comment|/**< O/H Coarse Classification base */
name|uint32_t
name|fmbm_oim
decl_stmt|;
comment|/**< O/H Internal margins*/
name|uint32_t
name|fmbm_ofp
decl_stmt|;
comment|/**< O/H Fifo Parameters*/
name|uint32_t
name|fmbm_ofed
decl_stmt|;
comment|/**< O/H Frame End Data*/
name|uint32_t
name|reserved0030
index|[
literal|2
index|]
decl_stmt|;
comment|/**< (0x038 - 0x03F) */
name|uint32_t
name|fmbm_oprai
index|[
name|FMAN_PORT_PRS_RESULT_WORDS_NUM
index|]
decl_stmt|;
comment|/**< O/H Parse Results Array Initialization  */
name|uint32_t
name|fmbm_ofqid
decl_stmt|;
comment|/**< O/H Frame Queue ID  */
name|uint32_t
name|fmbm_oefqid
decl_stmt|;
comment|/**< O/H Error Frame Queue ID  */
name|uint32_t
name|fmbm_ofsdm
decl_stmt|;
comment|/**< O/H Frame Status Discard Mask  */
name|uint32_t
name|fmbm_ofsem
decl_stmt|;
comment|/**< O/H Frame Status Error Mask  */
name|uint32_t
name|fmbm_ofene
decl_stmt|;
comment|/**< O/H Frame Enqueue Next Engine  */
name|uint32_t
name|fmbm_orlmts
decl_stmt|;
comment|/**< O/H Rate Limiter Scale  */
name|uint32_t
name|fmbm_orlmt
decl_stmt|;
comment|/**< O/H Rate Limiter  */
name|uint32_t
name|fmbm_ocmne
decl_stmt|;
comment|/**< O/H Continuous Mode Next Engine  */
name|uint32_t
name|reserved0080
index|[
literal|0x20
index|]
decl_stmt|;
comment|/**< 0x080 - 0x0FF Reserved */
name|uint32_t
name|fmbm_oebmpi
index|[
literal|2
index|]
decl_stmt|;
comment|/**< Buf Mngr Observed Pool Info */
name|uint32_t
name|reserved0108
index|[
literal|0x16
index|]
decl_stmt|;
comment|/**< 0x108 - 0x15F Reserved */
name|uint32_t
name|fmbm_ocgm
index|[
name|FMAN_PORT_CG_MAP_NUM
index|]
decl_stmt|;
comment|/**< Observed Congestion Group Map */
name|uint32_t
name|fmbm_ompd
decl_stmt|;
comment|/**< Observed BMan Pool Depletion */
name|uint32_t
name|reserved0184
index|[
literal|0x1F
index|]
decl_stmt|;
comment|/**< 0x184 - 0x1FF Reserved */
name|uint32_t
name|fmbm_ostc
decl_stmt|;
comment|/**< O/H Statistics Counters  */
name|uint32_t
name|fmbm_ofrc
decl_stmt|;
comment|/**< O/H Frame Counter  */
name|uint32_t
name|fmbm_ofdc
decl_stmt|;
comment|/**< O/H Frames Discard Counter  */
name|uint32_t
name|fmbm_ofledc
decl_stmt|;
comment|/**< O/H Frames Len Err Discard Cntr */
name|uint32_t
name|fmbm_ofufdc
decl_stmt|;
comment|/**< O/H Frames Unsprtd Discard Cutr  */
name|uint32_t
name|fmbm_offc
decl_stmt|;
comment|/**< O/H Filter Frames Counter  */
name|uint32_t
name|fmbm_ofwdc
decl_stmt|;
comment|/**< Rx Frames WRED Discard Counter  */
name|uint32_t
name|fmbm_ofldec
decl_stmt|;
comment|/**< O/H Frames List DMA Error Cntr */
name|uint32_t
name|fmbm_obdc
decl_stmt|;
comment|/**< O/H Buffers Deallocate Counter */
name|uint32_t
name|reserved0218
index|[
literal|0x17
index|]
decl_stmt|;
comment|/**< (0x218 - 0x27F) */
name|uint32_t
name|fmbm_opc
decl_stmt|;
comment|/**< O/H Performance Counters  */
name|uint32_t
name|fmbm_opcp
decl_stmt|;
comment|/**< O/H Performance Count Parameters */
name|uint32_t
name|fmbm_occn
decl_stmt|;
comment|/**< O/H Cycle Counter  */
name|uint32_t
name|fmbm_otuc
decl_stmt|;
comment|/**< O/H Tasks Utilization Counter  */
name|uint32_t
name|fmbm_oduc
decl_stmt|;
comment|/**< O/H DMA Utilization Counter */
name|uint32_t
name|fmbm_ofuc
decl_stmt|;
comment|/**< O/H FIFO Utilization Counter */
block|}
struct|;
end_struct

begin_comment
comment|/** @Description   BMI port register map */
end_comment

begin_union
union|union
name|fman_port_bmi_regs
block|{
name|struct
name|fman_port_rx_bmi_regs
name|rx
decl_stmt|;
name|struct
name|fman_port_tx_bmi_regs
name|tx
decl_stmt|;
name|struct
name|fman_port_oh_bmi_regs
name|oh
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/** @Description   QMI port register map */
end_comment

begin_struct
struct|struct
name|fman_port_qmi_regs
block|{
name|uint32_t
name|fmqm_pnc
decl_stmt|;
comment|/**< PortID n Configuration Register */
name|uint32_t
name|fmqm_pns
decl_stmt|;
comment|/**< PortID n Status Register */
name|uint32_t
name|fmqm_pnts
decl_stmt|;
comment|/**< PortID n Task Status Register */
name|uint32_t
name|reserved00c
index|[
literal|4
index|]
decl_stmt|;
comment|/**< 0xn00C - 0xn01B */
name|uint32_t
name|fmqm_pnen
decl_stmt|;
comment|/**< PortID n Enqueue NIA Register */
name|uint32_t
name|fmqm_pnetfc
decl_stmt|;
comment|/**< PortID n Enq Total Frame Counter */
name|uint32_t
name|reserved024
index|[
literal|2
index|]
decl_stmt|;
comment|/**< 0xn024 - 0x02B */
name|uint32_t
name|fmqm_pndn
decl_stmt|;
comment|/**< PortID n Dequeue NIA Register */
name|uint32_t
name|fmqm_pndc
decl_stmt|;
comment|/**< PortID n Dequeue Config Register */
name|uint32_t
name|fmqm_pndtfc
decl_stmt|;
comment|/**< PortID n Dequeue tot Frame cntr */
name|uint32_t
name|fmqm_pndfdc
decl_stmt|;
comment|/**< PortID n Dequeue FQID Dflt Cntr */
name|uint32_t
name|fmqm_pndcc
decl_stmt|;
comment|/**< PortID n Dequeue Confirm Counter */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fman_port_dma_swap
block|{
name|E_FMAN_PORT_DMA_NO_SWAP
block|,
comment|/**< No swap, transfer data as is */
name|E_FMAN_PORT_DMA_SWAP_LE
block|,
comment|/**< The transferred data should be swapped in PPC Little Endian mode */
name|E_FMAN_PORT_DMA_SWAP_BE
comment|/**< The transferred data should be swapped in Big Endian mode */
block|}
enum|;
end_enum

begin_comment
comment|/* Default port color */
end_comment

begin_enum
enum|enum
name|fman_port_color
block|{
name|E_FMAN_PORT_COLOR_GREEN
block|,
comment|/**< Default port color is green */
name|E_FMAN_PORT_COLOR_YELLOW
block|,
comment|/**< Default port color is yellow */
name|E_FMAN_PORT_COLOR_RED
block|,
comment|/**< Default port color is red */
name|E_FMAN_PORT_COLOR_OVERRIDE
comment|/**< Ignore color */
block|}
enum|;
end_enum

begin_comment
comment|/* QMI dequeue from the SP channel - types */
end_comment

begin_enum
enum|enum
name|fman_port_deq_type
block|{
name|E_FMAN_PORT_DEQ_BY_PRI
block|,
comment|/**< Priority precedence and Intra-Class scheduling */
name|E_FMAN_PORT_DEQ_ACTIVE_FQ
block|,
comment|/**< Active FQ precedence and Intra-Class scheduling */
name|E_FMAN_PORT_DEQ_ACTIVE_FQ_NO_ICS
comment|/**< Active FQ precedence and override Intra-Class scheduling */
block|}
enum|;
end_enum

begin_comment
comment|/* QMI dequeue prefetch modes */
end_comment

begin_enum
enum|enum
name|fman_port_deq_prefetch
block|{
name|E_FMAN_PORT_DEQ_NO_PREFETCH
block|,
comment|/**< No prefetch mode */
name|E_FMAN_PORT_DEQ_PART_PREFETCH
block|,
comment|/**< Partial prefetch mode */
name|E_FMAN_PORT_DEQ_FULL_PREFETCH
comment|/**< Full prefetch mode */
block|}
enum|;
end_enum

begin_comment
comment|/* Parameters for defining performance counters behavior */
end_comment

begin_struct
struct|struct
name|fman_port_perf_cnt_params
block|{
name|uint8_t
name|task_val
decl_stmt|;
comment|/**< Task compare value */
name|uint8_t
name|queue_val
decl_stmt|;
comment|/**< Rx or Tx conf queue compare value (unused for O/H ports) */
name|uint8_t
name|dma_val
decl_stmt|;
comment|/**< Dma compare value */
name|uint32_t
name|fifo_val
decl_stmt|;
comment|/**< Fifo compare value (in bytes) */
block|}
struct|;
end_struct

begin_comment
comment|/** @Description   FM Port configuration structure, used at init */
end_comment

begin_struct
struct|struct
name|fman_port_cfg
block|{
name|struct
name|fman_port_perf_cnt_params
name|perf_cnt_params
decl_stmt|;
comment|/* BMI parameters */
name|enum
name|fman_port_dma_swap
name|dma_swap_data
decl_stmt|;
name|bool
name|dma_ic_stash_on
decl_stmt|;
name|bool
name|dma_header_stash_on
decl_stmt|;
name|bool
name|dma_sg_stash_on
decl_stmt|;
name|bool
name|dma_write_optimize
decl_stmt|;
name|uint16_t
name|ic_ext_offset
decl_stmt|;
name|uint8_t
name|ic_int_offset
decl_stmt|;
name|uint16_t
name|ic_size
decl_stmt|;
name|enum
name|fman_port_color
name|color
decl_stmt|;
name|bool
name|sync_req
decl_stmt|;
name|bool
name|discard_override
decl_stmt|;
name|uint8_t
name|checksum_bytes_ignore
decl_stmt|;
name|uint8_t
name|rx_cut_end_bytes
decl_stmt|;
name|uint32_t
name|rx_pri_elevation
decl_stmt|;
name|uint32_t
name|rx_fifo_thr
decl_stmt|;
name|uint8_t
name|rx_fd_bits
decl_stmt|;
name|uint8_t
name|int_buf_start_margin
decl_stmt|;
name|uint16_t
name|ext_buf_start_margin
decl_stmt|;
name|uint16_t
name|ext_buf_end_margin
decl_stmt|;
name|uint32_t
name|tx_fifo_min_level
decl_stmt|;
name|uint32_t
name|tx_fifo_low_comf_level
decl_stmt|;
name|uint8_t
name|tx_fifo_deq_pipeline_depth
decl_stmt|;
name|bool
name|stats_counters_enable
decl_stmt|;
name|bool
name|perf_counters_enable
decl_stmt|;
comment|/* QMI parameters */
name|bool
name|deq_high_pri
decl_stmt|;
name|enum
name|fman_port_deq_type
name|deq_type
decl_stmt|;
name|enum
name|fman_port_deq_prefetch
name|deq_prefetch_opt
decl_stmt|;
name|uint16_t
name|deq_byte_cnt
decl_stmt|;
name|bool
name|queue_counters_enable
decl_stmt|;
name|bool
name|no_scatter_gather
decl_stmt|;
name|int
name|errata_A006675
decl_stmt|;
name|int
name|errata_A006320
decl_stmt|;
name|int
name|excessive_threshold_register
decl_stmt|;
name|int
name|fmbm_rebm_has_sgd
decl_stmt|;
name|int
name|fmbm_tfne_has_features
decl_stmt|;
name|int
name|qmi_deq_options_support
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fman_port_type
block|{
name|E_FMAN_PORT_TYPE_OP
init|=
literal|0
block|,
comment|/**< Offline parsing port, shares id-s with 	 * host command, so must have exclusive id-s */
name|E_FMAN_PORT_TYPE_RX
block|,
comment|/**< 1G Rx port */
name|E_FMAN_PORT_TYPE_RX_10G
block|,
comment|/**< 10G Rx port */
name|E_FMAN_PORT_TYPE_TX
block|,
comment|/**< 1G Tx port */
name|E_FMAN_PORT_TYPE_TX_10G
block|,
comment|/**< 10G Tx port */
name|E_FMAN_PORT_TYPE_DUMMY
block|,
name|E_FMAN_PORT_TYPE_HC
init|=
name|E_FMAN_PORT_TYPE_DUMMY
comment|/**< Host command port, shares id-s with 	 * offline parsing ports, so must have exclusive id-s */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fman_port_params
block|{
name|uint32_t
name|discard_mask
decl_stmt|;
name|uint32_t
name|err_mask
decl_stmt|;
name|uint32_t
name|dflt_fqid
decl_stmt|;
name|uint32_t
name|err_fqid
decl_stmt|;
name|uint8_t
name|deq_sp
decl_stmt|;
name|bool
name|dont_release_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Port context - used by most API functions */
end_comment

begin_struct
struct|struct
name|fman_port
block|{
name|enum
name|fman_port_type
name|type
decl_stmt|;
name|uint8_t
name|fm_rev_maj
decl_stmt|;
name|uint8_t
name|fm_rev_min
decl_stmt|;
name|union
name|fman_port_bmi_regs
modifier|*
name|bmi_regs
decl_stmt|;
name|struct
name|fman_port_qmi_regs
modifier|*
name|qmi_regs
decl_stmt|;
name|bool
name|im_en
decl_stmt|;
name|uint8_t
name|ext_pools_num
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** @Description   External buffer pools configuration */
end_comment

begin_struct
struct|struct
name|fman_port_bpools
block|{
name|uint8_t
name|count
decl_stmt|;
comment|/**< Num of pools to set up */
name|bool
name|counters_enable
decl_stmt|;
comment|/**< Enable allocate counters */
name|uint8_t
name|grp_bp_depleted_num
decl_stmt|;
comment|/**< Number of depleted pools - if reached the BMI indicates 	 * the MAC to send a pause frame */
struct|struct
block|{
name|uint8_t
name|bpid
decl_stmt|;
comment|/**< BM pool ID */
name|uint16_t
name|size
decl_stmt|;
comment|/**< Pool's size - must be in ascending order */
name|bool
name|is_backup
decl_stmt|;
comment|/**< If this is a backup pool */
name|bool
name|grp_bp_depleted
decl_stmt|;
comment|/**< Consider this buffer in multiple pools depletion criteria*/
name|bool
name|single_bp_depleted
decl_stmt|;
comment|/**< Consider this buffer in single pool depletion criteria */
name|bool
name|pfc_priorities_en
decl_stmt|;
block|}
name|bpool
index|[
name|FMAN_PORT_MAX_EXT_POOLS_NUM
index|]
struct|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fman_port_rate_limiter_scale_down
block|{
name|E_FMAN_PORT_RATE_DOWN_NONE
block|,
name|E_FMAN_PORT_RATE_DOWN_BY_2
block|,
name|E_FMAN_PORT_RATE_DOWN_BY_4
block|,
name|E_FMAN_PORT_RATE_DOWN_BY_8
block|}
enum|;
end_enum

begin_comment
comment|/* Rate limiter configuration */
end_comment

begin_struct
struct|struct
name|fman_port_rate_limiter
block|{
name|uint8_t
name|count_1micro_bit
decl_stmt|;
name|bool
name|high_burst_size_gran
decl_stmt|;
comment|/**< Defines burst_size granularity for OP ports; when TRUE, 	 * burst_size below counts in frames, otherwise in 10^3 frames */
name|uint16_t
name|burst_size
decl_stmt|;
comment|/**< Max burst size, in KBytes for Tx port, according to 	 * high_burst_size_gran definition for OP port */
name|uint32_t
name|rate
decl_stmt|;
comment|/**< In Kbps for Tx port, in frames/sec for OP port */
name|enum
name|fman_port_rate_limiter_scale_down
name|rate_factor
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* BMI statistics counters */
end_comment

begin_enum
enum|enum
name|fman_port_stats_counters
block|{
name|E_FMAN_PORT_STATS_CNT_FRAME
block|,
comment|/**< Number of processed frames; valid for all ports */
name|E_FMAN_PORT_STATS_CNT_DISCARD
block|,
comment|/**< For Rx ports - frames discarded by QMAN, for Tx or O/H ports - 	 * frames discarded due to DMA error; valid for all ports */
name|E_FMAN_PORT_STATS_CNT_DEALLOC_BUF
block|,
comment|/**< Number of buffer deallocate operations; valid for all ports */
name|E_FMAN_PORT_STATS_CNT_RX_BAD_FRAME
block|,
comment|/**< Number of bad Rx frames, like CRC error, Rx FIFO overflow etc; 	 * valid for Rx ports only */
name|E_FMAN_PORT_STATS_CNT_RX_LARGE_FRAME
block|,
comment|/**< Number of Rx oversized frames, that is frames exceeding max frame 	 * size configured for the corresponding ETH controller; 	 * valid for Rx ports only */
name|E_FMAN_PORT_STATS_CNT_RX_OUT_OF_BUF
block|,
comment|/**< Frames discarded due to lack of external buffers; valid for 	 * Rx ports only */
name|E_FMAN_PORT_STATS_CNT_LEN_ERR
block|,
comment|/**< Frames discarded due to frame length error; valid for Tx and 	 * O/H ports only */
name|E_FMAN_PORT_STATS_CNT_UNSUPPORTED_FORMAT
block|,
comment|/**< Frames discarded due to unsupported FD format; valid for Tx 	 * and O/H ports only */
name|E_FMAN_PORT_STATS_CNT_FILTERED_FRAME
block|,
comment|/**< Number of frames filtered out by PCD module; valid for 	 * Rx and OP ports only */
name|E_FMAN_PORT_STATS_CNT_DMA_ERR
block|,
comment|/**< Frames rejected by QMAN that were not able to release their 	 * buffers due to DMA error; valid for Rx and O/H ports only */
name|E_FMAN_PORT_STATS_CNT_WRED_DISCARD
comment|/**< Frames going through O/H port that were not able to to enter the 	 * return queue due to WRED algorithm; valid for O/H ports only */
block|}
enum|;
end_enum

begin_comment
comment|/* BMI performance counters */
end_comment

begin_enum
enum|enum
name|fman_port_perf_counters
block|{
name|E_FMAN_PORT_PERF_CNT_CYCLE
block|,
comment|/**< Cycle counter */
name|E_FMAN_PORT_PERF_CNT_TASK_UTIL
block|,
comment|/**< Tasks utilization counter */
name|E_FMAN_PORT_PERF_CNT_QUEUE_UTIL
block|,
comment|/**< For Rx ports - Rx queue utilization, for Tx ports - Tx conf queue 	 * utilization; not valid for O/H ports */
name|E_FMAN_PORT_PERF_CNT_DMA_UTIL
block|,
comment|/**< DMA utilization counter */
name|E_FMAN_PORT_PERF_CNT_FIFO_UTIL
block|,
comment|/**< FIFO utilization counter */
name|E_FMAN_PORT_PERF_CNT_RX_PAUSE
comment|/**< Number of cycles in which Rx pause activation control is on; 	 * valid for Rx ports only */
block|}
enum|;
end_enum

begin_comment
comment|/* QMI counters */
end_comment

begin_enum
enum|enum
name|fman_port_qmi_counters
block|{
name|E_FMAN_PORT_ENQ_TOTAL
block|,
comment|/**< EnQ tot frame cntr */
name|E_FMAN_PORT_DEQ_TOTAL
block|,
comment|/**< DeQ tot frame cntr; invalid for Rx ports */
name|E_FMAN_PORT_DEQ_FROM_DFLT
block|,
comment|/**< Dequeue from default FQID counter not valid for Rx ports */
name|E_FMAN_PORT_DEQ_CONFIRM
comment|/**< DeQ confirm cntr invalid for Rx ports */
block|}
enum|;
end_enum

begin_comment
comment|/** @Collection    FM Port API */
end_comment

begin_function_decl
name|void
name|fman_port_defconfig
parameter_list|(
name|struct
name|fman_port_cfg
modifier|*
name|cfg
parameter_list|,
name|enum
name|fman_port_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_init
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|struct
name|fman_port_cfg
modifier|*
name|cfg
parameter_list|,
name|struct
name|fman_port_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_enable
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_disable
parameter_list|(
specifier|const
name|struct
name|fman_port
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_bpools
parameter_list|(
specifier|const
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
specifier|const
name|struct
name|fman_port_bpools
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_rate_limiter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|struct
name|fman_port_rate_limiter
modifier|*
name|rate_limiter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_delete_rate_limiter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_err_mask
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|uint32_t
name|err_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_discard_mask
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|uint32_t
name|discard_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_modify_rx_fd_bits
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|uint8_t
name|rx_fd_bits
parameter_list|,
name|bool
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_perf_cnt_params
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|struct
name|fman_port_perf_cnt_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_stats_cnt_mode
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_perf_cnt_mode
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_queue_cnt_mode
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_set_bpool_cnt_mode
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|uint8_t
name|bpid
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_port_get_stats_counter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|enum
name|fman_port_stats_counters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_port_set_stats_counter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|enum
name|fman_port_stats_counters
name|counter
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_port_get_perf_counter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|enum
name|fman_port_perf_counters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_port_set_perf_counter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|enum
name|fman_port_perf_counters
name|counter
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_port_get_qmi_counter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|enum
name|fman_port_qmi_counters
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_port_set_qmi_counter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|enum
name|fman_port_qmi_counters
name|counter
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_port_get_bpool_counter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|uint8_t
name|bpid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_port_set_bpool_counter
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|uint8_t
name|bpid
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_add_congestion_grps
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|uint32_t
name|grps_map
index|[
name|FMAN_PORT_CG_MAP_NUM
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_port_remove_congestion_grps
parameter_list|(
name|struct
name|fman_port
modifier|*
name|port
parameter_list|,
name|uint32_t
name|grps_map
index|[
name|FMAN_PORT_CG_MAP_NUM
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_FMAN_PORT_H */
end_comment

end_unit

