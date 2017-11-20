begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_HAL_COMMON_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_COMMON_REGS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_common_reg_t
block|{
name|u8
name|unused00a00
index|[
literal|0x00a00
index|]
decl_stmt|;
comment|/* 0x00a00 */
name|u64
name|prc_status1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PRC_STATUS1_PRC_VP_QUIESCENT
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00a08 */
name|u64
name|rxdcm_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RXDCM_RESET_IN_PROGRESS_PRC_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00a10 */
name|u64
name|replicq_flush_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_REPLICQ_FLUSH_IN_PROGRESS_NOA_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00a18 */
name|u64
name|rxpe_cmds_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RXPE_CMDS_RESET_IN_PROGRESS_NOA_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00a20 */
name|u64
name|mxp_cmds_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MXP_CMDS_RESET_IN_PROGRESS_NOA_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00a28 */
name|u64
name|noffload_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_NOFFLOAD_RESET_IN_PROGRESS_PRC_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00a30 */
name|u64
name|rd_req_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RD_REQ_IN_PROGRESS_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00a38 */
name|u64
name|rd_req_outstanding
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RD_REQ_OUTSTANDING_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00a40 */
name|u64
name|kdfc_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_RESET_IN_PROGRESS_NOA_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
name|u8
name|unused00b00
index|[
literal|0x00b00
operator|-
literal|0x00a48
index|]
decl_stmt|;
comment|/* 0x00b00 */
name|u64
name|one_cfg_vp
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ONE_CFG_VP_RDY
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00b08 */
name|u64
name|one_common
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ONE_COMMON_PET_VPATH_RESET_IN_PROGRESS
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
name|u8
name|unused00b80
index|[
literal|0x00b80
operator|-
literal|0x00b10
index|]
decl_stmt|;
comment|/* 0x00b80 */
name|u64
name|tim_int_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_INT_EN_TIM_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00b88 */
name|u64
name|tim_set_int_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_SET_INT_EN_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00b90 */
name|u64
name|tim_clr_int_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_CLR_INT_EN_VP
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00b98 */
name|u64
name|tim_mask_int_during_reset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_MASK_INT_DURING_RESET_VPATH
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00ba0 */
name|u64
name|tim_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_RESET_IN_PROGRESS_TIM_VPATH
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00ba8 */
name|u64
name|tim_outstanding_bmap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_OUTSTANDING_BMAP_TIM_VPATH
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
name|u8
name|unused00c00
index|[
literal|0x00c00
operator|-
literal|0x00bb0
index|]
decl_stmt|;
comment|/* 0x00c00 */
name|u64
name|msg_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSG_RESET_IN_PROGRESS_MSG_COMPOSITE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00c08 */
name|u64
name|msg_mxp_mr_ready
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSG_MXP_MR_READY_MP_BOOTED
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00c10 */
name|u64
name|msg_uxp_mr_ready
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSG_UXP_MR_READY_UP_BOOTED
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00c18 */
name|u64
name|msg_dmq_noni_rtl_prefetch
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSG_DMQ_NONI_RTL_PREFETCH_BYPASS_ENABLE
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
comment|/* 0x00c20 */
name|u64
name|msg_umq_rtl_bwr
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSG_UMQ_RTL_BWR_PREFETCH_DISABLE
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
name|u8
name|unused00d00
index|[
literal|0x00d00
operator|-
literal|0x00c28
index|]
decl_stmt|;
comment|/* 0x00d00 */
name|u64
name|cmn_rsthdlr_cfg0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CMN_RSTHDLR_CFG0_SW_RESET_VPATH
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00d08 */
name|u64
name|cmn_rsthdlr_cfg1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CMN_RSTHDLR_CFG1_CLR_VPATH_RESET
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00d10 */
name|u64
name|cmn_rsthdlr_cfg2
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CMN_RSTHDLR_CFG2_SW_RESET_FIFO0
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00d18 */
name|u64
name|cmn_rsthdlr_cfg3
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CMN_RSTHDLR_CFG3_SW_RESET_FIFO1
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00d20 */
name|u64
name|cmn_rsthdlr_cfg4
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CMN_RSTHDLR_CFG4_SW_RESET_FIFO2
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
name|u8
name|unused00d40
index|[
literal|0x00d40
operator|-
literal|0x00d28
index|]
decl_stmt|;
comment|/* 0x00d40 */
name|u64
name|cmn_rsthdlr_cfg8
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CMN_RSTHDLR_CFG8_INCR_VPATH_INST_NUM
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00d48 */
name|u64
name|stats_cfg0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_STATS_CFG0_STATS_ENABLE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
name|u8
name|unused00da8
index|[
literal|0x00da8
operator|-
literal|0x00d50
index|]
decl_stmt|;
comment|/* 0x00da8 */
name|u64
name|clear_msix_mask_vect
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CLEAR_MSIX_MASK_VECT_CLEAR_MSIX_MASK_VECT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00dc8 */
name|u64
name|set_msix_mask_vect
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SET_MSIX_MASK_VECT_SET_MSIX_MASK_VECT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00de8 */
name|u64
name|clear_msix_mask_all_vect
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CLEAR_MSIX_MASK_ALL_VECT_CLEAR_MSIX_MASK_ALL_VECT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 17)
comment|/* 0x00df0 */
name|u64
name|set_msix_mask_all_vect
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SET_MSIX_MASK_ALL_VECT_SET_MSIX_MASK_ALL_VECT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 17)
comment|/* 0x00df8 */
name|u64
name|mask_vector
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MASK_VECTOR_MASK_VECTOR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00e18 */
name|u64
name|msix_pending_vector
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSIX_PENDING_VECTOR_MSIX_PENDING_VECTOR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00e38 */
name|u64
name|clr_msix_one_shot_vec
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CLR_MSIX_ONE_SHOT_VEC_CLR_MSIX_ONE_SHOT_VEC
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 17)
comment|/* 0x00e58 */
name|u64
name|titan_asic_id
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TITAN_ASIC_ID_INITIAL_DEVICE_ID
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 16)
define|#
directive|define
name|VXGE_HAL_TITAN_ASIC_ID_INITIAL_MAJOR_REVISION
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 48, 8)
define|#
directive|define
name|VXGE_HAL_TITAN_ASIC_ID_INITIAL_MINOR_REVISION
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 56, 8)
comment|/* 0x00e60 */
name|u64
name|titan_general_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TITAN_GENERAL_INT_STATUS_MRPCIM_ALARM_INT
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_TITAN_GENERAL_INT_STATUS_SRPCIM_ALARM_INT
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_TITAN_GENERAL_INT_STATUS_VPATH_ALARM_INT
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_TITAN_GENERAL_INT_STATUS_VPATH_TRAFFIC_INT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 3, 17)
name|u8
name|unused00e70
index|[
literal|0x00e70
operator|-
literal|0x00e68
index|]
decl_stmt|;
comment|/* 0x00e70 */
name|u64
name|titan_mask_all_int
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TITAN_MASK_ALL_INT_ALARM
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_TITAN_MASK_ALL_INT_TRAFFIC
value|mBIT(15)
name|u8
name|unused00e80
index|[
literal|0x00e80
operator|-
literal|0x00e78
index|]
decl_stmt|;
comment|/* 0x00e80 */
name|u64
name|tim_int_status0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_INT_STATUS0_TIM_INT_STATUS0
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00e88 */
name|u64
name|tim_int_mask0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_INT_MASK0_TIM_INT_MASK0
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00e90 */
name|u64
name|tim_int_status1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_INT_STATUS1_TIM_INT_STATUS1
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 4)
comment|/* 0x00e98 */
name|u64
name|tim_int_mask1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_INT_MASK1_TIM_INT_MASK1
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 4)
comment|/* 0x00ea0 */
name|u64
name|rti_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTI_INT_STATUS_RTI_INT_STATUS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00ea8 */
name|u64
name|rti_int_mask
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTI_INT_MASK_RTI_INT_MASK
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00eb0 */
name|u64
name|adapter_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_RTDMA_RTDMA_READY
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_WRDMA_WRDMA_READY
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_KDFC_KDFC_READY
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_TPA_TMAC_BUF_EMPTY
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_RDCTL_PIC_QUIESCENT
value|mBIT(4)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_XGMAC_NETWORK_FAULT
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_ROCRC_OFFLOAD_QUIESCENT
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_G3IF_FB_G3IF_FB_GDDR3_READY
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_G3IF_CM_G3IF_CM_GDDR3_READY
value|mBIT(8)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_RIC_RIC_RUNNING
value|mBIT(9)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_CMG_C_PLL_IN_LOCK
value|mBIT(10)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_XGMAC_X_PLL_IN_LOCK
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_FBIF_M_PLL_IN_LOCK
value|mBIT(12)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_PCC_PCC_IDLE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 24, 8)
define|#
directive|define
name|VXGE_HAL_ADAPTER_STATUS_ROCRC_RC_PRC_QUIESCENT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 44, 8)
comment|/* 0x00eb8 */
name|u64
name|gen_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_GEN_CTRL_SPI_MRPCIM_WR_DIS
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_GEN_CTRL_SPI_MRPCIM_RD_DIS
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_GEN_CTRL_SPI_SRPCIM_WR_DIS
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_GEN_CTRL_SPI_SRPCIM_RD_DIS
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_GEN_CTRL_SPI_DEBUG_DIS
value|mBIT(4)
define|#
directive|define
name|VXGE_HAL_GEN_CTRL_SPI_APP_LTSSM_TIMER_DIS
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_GEN_CTRL_SPI_NOT_USED
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 6, 4)
name|u8
name|unused00ed0
index|[
literal|0x00ed0
operator|-
literal|0x00ec0
index|]
decl_stmt|;
comment|/* 0x00ed0 */
name|u64
name|adapter_ready
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ADAPTER_READY_ADAPTER_READY
value|mBIT(63)
comment|/* 0x00ed8 */
name|u64
name|outstanding_read
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_OUTSTANDING_READ_OUTSTANDING_READ
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00ee0 */
name|u64
name|vpath_rst_in_prog
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_RST_IN_PROG_VPATH_RST_IN_PROG
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x00ee8 */
name|u64
name|vpath_reg_modified
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_REG_MODIFIED_VPATH_REG_MODIFIED
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
name|u8
name|unused00f40
index|[
literal|0x00f40
operator|-
literal|0x00ef0
index|]
decl_stmt|;
comment|/* 0x00f40 */
name|u64
name|qcc_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_QCC_RESET_IN_PROGRESS_QCC_VPATH
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
name|u8
name|unused00fc0
index|[
literal|0x00fc0
operator|-
literal|0x00f48
index|]
decl_stmt|;
comment|/* 0x00fc0 */
name|u64
name|cp_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_CP_RESET_IN_PROGRESS_CP_VPATH
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
name|u8
name|unused01000
index|[
literal|0x01000
operator|-
literal|0x00fc8
index|]
decl_stmt|;
comment|/* 0x01000 */
name|u64
name|h2l_reset_in_progress
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_H2L_RESET_IN_PROGRESS_H2L_VPATH
parameter_list|(
name|n
parameter_list|)
value|mBIT(n)
name|u8
name|unused01080
index|[
literal|0x01080
operator|-
literal|0x01008
index|]
decl_stmt|;
comment|/* 0x01080 */
name|u64
name|xgmac_ready
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_XGMAC_READY_XMACJ_READY
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
name|u8
name|unused010c0
index|[
literal|0x010c0
operator|-
literal|0x01088
index|]
decl_stmt|;
comment|/* 0x010c0 */
name|u64
name|fbif_ready
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FBIF_READY_FAU_READY
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
name|u8
name|unused01100
index|[
literal|0x01100
operator|-
literal|0x010c8
index|]
decl_stmt|;
comment|/* 0x01100 */
name|u64
name|vplane_assignments
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPLANE_ASSIGNMENTS_VPLANE_ASSIGNMENTS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 3, 5)
comment|/* 0x01108 */
name|u64
name|vpath_assignments
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_ASSIGNMENTS_VPATH_ASSIGNMENTS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x01110 */
name|u64
name|resource_assignments
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RESOURCE_ASSIGNMENTS_RESOURCE_ASSIGNMENTS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x01118 */
name|u64
name|host_type_assignments
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_HOST_TYPE_ASSIGNMENTS_HOST_TYPE_ASSIGNMENTS
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 5, 3)
comment|/* 0x01120 */
name|u64
name|debug_assignments
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DEBUG_ASSIGNMENTS_VHLABEL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 3, 5)
define|#
directive|define
name|VXGE_HAL_DEBUG_ASSIGNMENTS_VPLANE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 11, 5)
define|#
directive|define
name|VXGE_HAL_DEBUG_ASSIGNMENTS_FUNC
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 19, 5)
comment|/* 0x01128 */
name|u64
name|max_resource_assignments
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MAX_RESOURCE_ASSIGNMENTS_PCI_MAX_VPLANE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 3, 5)
define|#
directive|define
name|VXGE_HAL_MAX_RESOURCE_ASSIGNMENTS_PCI_MAX_VPATHS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 11, 5)
comment|/* 0x01130 */
name|u64
name|pf_vpath_assignments
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PF_VPATH_ASSIGNMENTS_PF_VPATH_ASSIGNMENTS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
name|u8
name|unused01200
index|[
literal|0x01200
operator|-
literal|0x01138
index|]
decl_stmt|;
comment|/* 0x01200 */
name|u64
name|rts_access_icmp
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_ICMP_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x01208 */
name|u64
name|rts_access_tcpsyn
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_TCPSYN_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x01210 */
name|u64
name|rts_access_zl4pyld
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_ZL4PYLD_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x01218 */
name|u64
name|rts_access_l4prtcl_tcp
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_L4PRTCL_TCP_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x01220 */
name|u64
name|rts_access_l4prtcl_udp
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_L4PRTCL_UDP_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x01228 */
name|u64
name|rts_access_l4prtcl_flex
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_L4PRTCL_FLEX_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x01230 */
name|u64
name|rts_access_ipfrag
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_IPFRAG_EN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
name|u8
name|unused01238
index|[
literal|0x01248
operator|-
literal|0x01238
index|]
decl_stmt|;
block|}
name|vxge_hal_common_reg_t
typedef|;
end_typedef

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_COMMON_REGS_H */
end_comment

end_unit

