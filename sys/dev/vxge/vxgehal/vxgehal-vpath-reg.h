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
name|VXGE_HAL_VPATH_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_VPATH_REGS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_vpath_reg_t
block|{
name|u8
name|unused00300
index|[
literal|0x00300
index|]
decl_stmt|;
comment|/* 0x00300 */
name|u64
name|usdc_vpath
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_USDC_VPATH_SGRP_ASSIGN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
name|u8
name|unused00a00
index|[
literal|0x00a00
operator|-
literal|0x00308
index|]
decl_stmt|;
comment|/* 0x00a00 */
name|u64
name|wrdma_alarm_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_WRDMA_ALARM_STATUS_PRC_ALARM_PRC_INT
value|mBIT(1)
comment|/* 0x00a08 */
name|u64
name|wrdma_alarm_mask
decl_stmt|;
name|u8
name|unused00a30
index|[
literal|0x00a30
operator|-
literal|0x00a10
index|]
decl_stmt|;
comment|/* 0x00a30 */
name|u64
name|prc_alarm_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PRC_ALARM_REG_PRC_RING_BUMP
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_PRC_ALARM_REG_PRC_RXDCM_SC_ERR
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_PRC_ALARM_REG_PRC_RXDCM_SC_ABORT
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_PRC_ALARM_REG_PRC_QUANTA_SIZE_ERR
value|mBIT(3)
comment|/* 0x00a38 */
name|u64
name|prc_alarm_mask
decl_stmt|;
comment|/* 0x00a40 */
name|u64
name|prc_alarm_alarm
decl_stmt|;
comment|/* 0x00a48 */
name|u64
name|prc_cfg1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PRC_CFG1_RX_TIMER_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 3, 29)
define|#
directive|define
name|VXGE_HAL_PRC_CFG1_TIM_RING_BUMP_INT_ENABLE
value|mBIT(34)
define|#
directive|define
name|VXGE_HAL_PRC_CFG1_RTI_TINT_DISABLE
value|mBIT(35)
define|#
directive|define
name|VXGE_HAL_PRC_CFG1_GREEDY_RETURN
value|mBIT(36)
define|#
directive|define
name|VXGE_HAL_PRC_CFG1_QUICK_SHOT
value|mBIT(37)
define|#
directive|define
name|VXGE_HAL_PRC_CFG1_RX_TIMER_CI
value|mBIT(39)
define|#
directive|define
name|VXGE_HAL_PRC_CFG1_RESET_TIMER_ON_RXD_RET
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 40, 2)
name|u8
name|unused00a60
index|[
literal|0x00a60
operator|-
literal|0x00a50
index|]
decl_stmt|;
comment|/* 0x00a60 */
name|u64
name|prc_cfg4
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_IN_SVC
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_RING_MODE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 14, 2)
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_RXD_NO_SNOOP
value|mBIT(22)
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_FRM_NO_SNOOP
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_RTH_DISABLE
value|mBIT(31)
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_IGNORE_OWNERSHIP
value|mBIT(32)
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_SIGNAL_BENIGN_OVFLW
value|mBIT(36)
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_BIMODAL_INTERRUPT
value|mBIT(37)
define|#
directive|define
name|VXGE_HAL_PRC_CFG4_BACKOFF_INTERVAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 40, 24)
comment|/* 0x00a68 */
name|u64
name|prc_cfg5
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PRC_CFG5_RXD0_ADD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 61)
comment|/* 0x00a70 */
name|u64
name|prc_cfg6
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PRC_CFG6_FRM_PAD_EN
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_PRC_CFG6_QSIZE_ALIGNED_RXD
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_PRC_CFG6_DOORBELL_MODE_EN
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_PRC_CFG6_L3_CPC_TRSFR_CODE_EN
value|mBIT(8)
define|#
directive|define
name|VXGE_HAL_PRC_CFG6_L4_CPC_TRSFR_CODE_EN
value|mBIT(9)
define|#
directive|define
name|VXGE_HAL_PRC_CFG6_RXD_CRXDT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 23, 9)
define|#
directive|define
name|VXGE_HAL_PRC_CFG6_RXD_SPAT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 36, 9)
comment|/* 0x00a78 */
name|u64
name|prc_cfg7
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PRC_CFG7_SCATTER_MODE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 6, 2)
define|#
directive|define
name|VXGE_HAL_PRC_CFG7_SMART_SCAT_EN
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_PRC_CFG7_RXD_NS_CHG_EN
value|mBIT(12)
define|#
directive|define
name|VXGE_HAL_PRC_CFG7_NO_HDR_SEPARATION
value|mBIT(14)
define|#
directive|define
name|VXGE_HAL_PRC_CFG7_RXD_BUFF_SIZE_MASK
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 20, 4)
define|#
directive|define
name|VXGE_HAL_PRC_CFG7_BUFF_SIZE0_MASK
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 27, 5)
comment|/* 0x00a80 */
name|u64
name|tim_dest_addr
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_DEST_ADDR_TIM_DEST_ADDR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00a88 */
name|u64
name|prc_rxd_doorbell
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PRC_RXD_DOORBELL_NEW_QW_CNT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 48, 16)
comment|/* 0x00a90 */
name|u64
name|rqa_prty_for_vp
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RQA_PRTY_FOR_VP_RQA_PRTY_FOR_VP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 59, 5)
comment|/* 0x00a98 */
name|u64
name|rxdmem_size
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RXDMEM_SIZE_PRC_RXDMEM_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 51, 13)
comment|/* 0x00aa0 */
name|u64
name|frm_in_progress_cnt
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FRM_IN_PROGRESS_CNT_PRC_FRM_IN_PROGRESS_CNT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 59, 5)
comment|/* 0x00aa8 */
name|u64
name|rx_multi_cast_stats
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RX_MULTI_CAST_STATS_FRAME_DISCARD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 48, 16)
comment|/* 0x00ab0 */
name|u64
name|rx_frm_transferred
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RX_FRM_TRANSFERRED_RX_FRM_TRANSFERRED
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
comment|/* 0x00ab8 */
name|u64
name|rxd_returned
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RXD_RETURNED_RXD_RETURNED
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 48, 16)
name|u8
name|unused00c00
index|[
literal|0x00c00
operator|-
literal|0x00ac0
index|]
decl_stmt|;
comment|/* 0x00c00 */
name|u64
name|kdfc_fifo_trpl_partition
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_FIFO_TRPL_PARTITION_LENGTH_0
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 17, 15)
define|#
directive|define
name|VXGE_HAL_KDFC_FIFO_TRPL_PARTITION_LENGTH_1
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 33, 15)
define|#
directive|define
name|VXGE_HAL_KDFC_FIFO_TRPL_PARTITION_LENGTH_2
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 49, 15)
comment|/* 0x00c08 */
name|u64
name|kdfc_fifo_trpl_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_FIFO_TRPL_CTRL_TRIPLET_ENABLE
value|mBIT(7)
comment|/* 0x00c10 */
name|u64
name|kdfc_trpl_fifo_0_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_MODE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 14, 2)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_FLIP_EN
value|mBIT(22)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_SWAP_EN
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_INT_CTRL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 26, 2)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_CTRL_STRUC
value|mBIT(28)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_ADD_PAD
value|mBIT(29)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_NO_SNOOP
value|mBIT(30)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_RLX_ORD
value|mBIT(31)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_SELECT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 8)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_INT_NO
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 41, 7)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_CTRL_BIT_MAP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 48, 16)
comment|/* 0x00c18 */
name|u64
name|kdfc_trpl_fifo_1_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_MODE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 14, 2)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_FLIP_EN
value|mBIT(22)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_SWAP_EN
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_INT_CTRL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 26, 2)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_CTRL_STRUC
value|mBIT(28)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_ADD_PAD
value|mBIT(29)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_NO_SNOOP
value|mBIT(30)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_RLX_ORD
value|mBIT(31)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_SELECT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 8)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_INT_NO
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 41, 7)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_CTRL_BIT_MAP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 48, 16)
comment|/* 0x00c20 */
name|u64
name|kdfc_trpl_fifo_2_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_FLIP_EN
value|mBIT(22)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_SWAP_EN
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_INT_CTRL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 26, 2)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_CTRL_STRUC
value|mBIT(28)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_ADD_PAD
value|mBIT(29)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_NO_SNOOP
value|mBIT(30)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_RLX_ORD
value|mBIT(31)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_SELECT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 8)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_INT_NO
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 41, 7)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_CTRL_BIT_MAP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 48, 16)
comment|/* 0x00c28 */
name|u64
name|kdfc_trpl_fifo_0_wb_address
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_0_WB_ADDRESS_ADD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00c30 */
name|u64
name|kdfc_trpl_fifo_1_wb_address
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_1_WB_ADDRESS_ADD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00c38 */
name|u64
name|kdfc_trpl_fifo_2_wb_address
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_2_WB_ADDRESS_ADD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00c40 */
name|u64
name|kdfc_trpl_fifo_offset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_OFFSET_KDFC_RCTR0
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 15)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_OFFSET_KDFC_RCTR1
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 17, 15)
define|#
directive|define
name|VXGE_HAL_KDFC_TRPL_FIFO_OFFSET_KDFC_RCTR2
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 33, 15)
comment|/* 0x00c48 */
name|u64
name|kdfc_drbl_triplet_total
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_DRBL_TRIPLET_TOTAL_KDFC_MAX_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 17, 15)
name|u8
name|unused00c60
index|[
literal|0x00c60
operator|-
literal|0x00c50
index|]
decl_stmt|;
comment|/* 0x00c60 */
name|u64
name|usdc_drbl_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_USDC_DRBL_CTRL_FLIP_EN
value|mBIT(22)
define|#
directive|define
name|VXGE_HAL_USDC_DRBL_CTRL_SWAP_EN
value|mBIT(23)
comment|/* 0x00c68 */
name|u64
name|usdc_vp_ready
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_USDC_VP_READY_USDC_HTN_READY
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_USDC_VP_READY_USDC_SRQ_READY
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_USDC_VP_READY_USDC_CQRQ_READY
value|mBIT(23)
comment|/* 0x00c70 */
name|u64
name|kdfc_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFC_STATUS_KDFC_WRR_0_READY
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_KDFC_STATUS_KDFC_WRR_1_READY
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_KDFC_STATUS_KDFC_WRR_2_READY
value|mBIT(2)
name|u8
name|unused00c80
index|[
literal|0x00c80
operator|-
literal|0x00c78
index|]
decl_stmt|;
comment|/* 0x00c80 */
name|u64
name|xmac_rpa_vcfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_XMAC_RPA_VCFG_IPV4_TCP_INCL_PH
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_XMAC_RPA_VCFG_IPV6_TCP_INCL_PH
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_XMAC_RPA_VCFG_IPV4_UDP_INCL_PH
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_XMAC_RPA_VCFG_IPV6_UDP_INCL_PH
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_XMAC_RPA_VCFG_L4_INCL_CF
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_XMAC_RPA_VCFG_STRIP_VLAN_TAG
value|mBIT(23)
comment|/* 0x00c88 */
name|u64
name|rxmac_vcfg0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG0_RTS_MAX_FRM_LEN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 2, 14)
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG0_RTS_USE_MIN_LEN
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG0_RTS_MIN_FRM_LEN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 26, 14)
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG0_UCAST_ALL_ADDR_EN
value|mBIT(43)
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG0_MCAST_ALL_ADDR_EN
value|mBIT(47)
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG0_BCAST_EN
value|mBIT(51)
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG0_ALL_VID_EN
value|mBIT(55)
comment|/* 0x00c90 */
name|u64
name|rxmac_vcfg1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG1_RTS_RTH_MULTI_IT_BD_MODE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 42, 2)
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG1_RTS_RTH_MULTI_IT_EN_MODE
value|mBIT(47)
define|#
directive|define
name|VXGE_HAL_RXMAC_VCFG1_CONTRIB_L2_FLOW
value|mBIT(51)
comment|/* 0x00c98 */
name|u64
name|rts_access_steer_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_CTRL_ACTION
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 7)
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_CTRL_DATA_STRUCT_SEL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 8, 4)
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_CTRL_STROBE
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_CTRL_BEHAV_TBL_SEL
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_CTRL_TABLE_SEL
value|mBIT(27)
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_CTRL_OFFSET
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 40, 8)
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_CTRL_RMACJ_STATUS
value|mBIT(0)
comment|/* 0x00ca0 */
name|u64
name|rts_access_steer_data0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_DATA0_DATA
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00ca8 */
name|u64
name|rts_access_steer_data1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTS_ACCESS_STEER_DATA1_DATA
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
name|u8
name|unused00d00
index|[
literal|0x00d00
operator|-
literal|0x00cb0
index|]
decl_stmt|;
comment|/* 0x00d00 */
name|u64
name|xmac_vsport_choice
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_XMAC_VSPORT_CHOICE_VSPORT_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 3, 5)
comment|/* 0x00d08 */
name|u64
name|xmac_stats_cfg
decl_stmt|;
comment|/* 0x00d10 */
name|u64
name|xmac_stats_access_cmd
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_XMAC_STATS_ACCESS_CMD_OP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 6, 2)
define|#
directive|define
name|VXGE_HAL_XMAC_STATS_ACCESS_CMD_STROBE
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_XMAC_STATS_ACCESS_CMD_OFFSET_SEL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 8)
comment|/* 0x00d18 */
name|u64
name|xmac_stats_access_data
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_XMAC_STATS_ACCESS_DATA_XSMGR_DATA
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00d20 */
name|u64
name|asic_ntwk_vp_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_CTRL_REQ_TEST_NTWK
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_CTRL_XMACJ_SHOW_PORT_INFO
value|mBIT(55)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_CTRL_XMACJ_PORT_NUM
value|mBIT(63)
name|u8
name|unused00d30
index|[
literal|0x00d30
operator|-
literal|0x00d28
index|]
decl_stmt|;
comment|/* 0x00d30 */
name|u64
name|xgmac_vp_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_XGMAC_VP_INT_STATUS_ASIC_NTWK_VP_ERR_INT
value|mBIT(3)
comment|/* 0x00d38 */
name|u64
name|xgmac_vp_int_mask
decl_stmt|;
comment|/* 0x00d40 */
name|u64
name|asic_ntwk_vp_err_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_ERR_REG_SUS_FAULT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_ERR_REG_SUS_OK
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_ERR_REG_SUS_FAULT_OCCURRED
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_ERR_REG_SUS_OK_OCCURRED
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_ERR_REG_REAF_FAULT
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_VP_ERR_REG_REAF_OK
value|mBIT(23)
comment|/* 0x00d48 */
name|u64
name|asic_ntwk_vp_err_mask
decl_stmt|;
comment|/* 0x00d50 */
name|u64
name|asic_ntwk_vp_err_alarm
decl_stmt|;
name|u8
name|unused00d80
index|[
literal|0x00d80
operator|-
literal|0x00d58
index|]
decl_stmt|;
comment|/* 0x00d80 */
name|u64
name|rtdma_bw_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTDMA_BW_CTRL_BW_CTRL_EN
value|mBIT(39)
define|#
directive|define
name|VXGE_HAL_RTDMA_BW_CTRL_DESIRED_BW
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 46, 18)
comment|/* 0x00d88 */
name|u64
name|rtdma_rd_optimization_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_GEN_INT_AFTER_ABORT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_PAD_MODE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 6, 2)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_PAD_PATTERN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 8, 8)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_FB_WAIT_FOR_SPACE
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_FB_FILL_THRESH
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 21, 3)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_TXD_PYLD_WMARK_EN
value|mBIT(28)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_TXD_PYLD_WMARK
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 29, 3)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_FB_ADDR_BDRY_EN
value|mBIT(35)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_FB_ADDR_BDRY
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 37, 3)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_TXD_WAIT_FOR_SPACE
value|mBIT(43)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_TXD_FILL_THRESH
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 51, 5)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_TXD_ADDR_BDRY_EN
value|mBIT(59)
define|#
directive|define
name|VXGE_HAL_RTDMA_RD_OPTIMIZATION_CTRL_TXD_ADDR_BDRY
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 61, 3)
comment|/* 0x00d90 */
name|u64
name|pda_pcc_job_monitor
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PDA_PCC_JOB_MONITOR_PDA_PCC_JOB_STATUS
value|mBIT(7)
comment|/* 0x00d98 */
name|u64
name|tx_protocol_assist_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TX_PROTOCOL_ASSIST_CFG_LSOV2_EN
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_TX_PROTOCOL_ASSIST_CFG_IPV6_KEEP_SEARCHING
value|mBIT(7)
name|u8
name|unused01000
index|[
literal|0x01000
operator|-
literal|0x00da0
index|]
decl_stmt|;
comment|/* 0x01000 */
name|u64
name|tim_cfg1_int_num
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_BTIMER_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 6, 26)
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_BITMP_EN
value|mBIT(35)
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_TXFRM_CNT_EN
value|mBIT(36)
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_TXD_CNT_EN
value|mBIT(37)
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_TIMER_AC
value|mBIT(38)
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_TIMER_CI
value|mBIT(39)
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_URNG_A
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 41, 7)
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_URNG_B
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 49, 7)
define|#
directive|define
name|VXGE_HAL_TIM_CFG1_INT_NUM_URNG_C
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 57, 7)
comment|/* 0x01020 */
name|u64
name|tim_cfg2_int_num
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_CFG2_INT_NUM_UEC_A
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 16)
define|#
directive|define
name|VXGE_HAL_TIM_CFG2_INT_NUM_UEC_B
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 16, 16)
define|#
directive|define
name|VXGE_HAL_TIM_CFG2_INT_NUM_UEC_C
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 16)
define|#
directive|define
name|VXGE_HAL_TIM_CFG2_INT_NUM_UEC_D
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 48, 16)
comment|/* 0x01040 */
name|u64
name|tim_cfg3_int_num
index|[
literal|4
index|]
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_CFG3_INT_NUM_TIMER_RI
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_TIM_CFG3_INT_NUM_RTIMER_EVENT_SF
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 4)
define|#
directive|define
name|VXGE_HAL_TIM_CFG3_INT_NUM_RTIMER_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 6, 26)
define|#
directive|define
name|VXGE_HAL_TIM_CFG3_INT_NUM_UTIL_SEL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 6)
define|#
directive|define
name|VXGE_HAL_TIM_CFG3_INT_NUM_LTIMER_VAL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 38, 26)
comment|/* 0x01060 */
name|u64
name|tim_wrkld_clc
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_WRKLD_CLC_WRKLD_EVAL_PRD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
define|#
directive|define
name|VXGE_HAL_TIM_WRKLD_CLC_WRKLD_EVAL_DIV
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 35, 5)
define|#
directive|define
name|VXGE_HAL_TIM_WRKLD_CLC_CNT_FRM_BYTE
value|mBIT(40)
define|#
directive|define
name|VXGE_HAL_TIM_WRKLD_CLC_CNT_RX_TX
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 41, 2)
define|#
directive|define
name|VXGE_HAL_TIM_WRKLD_CLC_CNT_LNK_EN
value|mBIT(43)
define|#
directive|define
name|VXGE_HAL_TIM_WRKLD_CLC_HOST_UTIL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 57, 7)
comment|/* 0x01068 */
name|u64
name|tim_bitmap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_BITMAP_MASK
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
define|#
directive|define
name|VXGE_HAL_TIM_BITMAP_LLROOT_RXD_EN
value|mBIT(32)
define|#
directive|define
name|VXGE_HAL_TIM_BITMAP_LLROOT_TXD_EN
value|mBIT(33)
comment|/* 0x01070 */
name|u64
name|tim_ring_assn
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_RING_ASSN_INT_NUM
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 6, 2)
comment|/* 0x01078 */
name|u64
name|tim_remap
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_REMAP_TX_EN
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_TIM_REMAP_RX_EN
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_TIM_REMAP_OFFLOAD_EN
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_TIM_REMAP_TO_VPATH_NUM
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 11, 5)
comment|/* 0x01080 */
name|u64
name|tim_vpath_map
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_VPATH_MAP_BMAP_ROOT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
comment|/* 0x01088 */
name|u64
name|tim_pci_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_PCI_CFG_ADD_PAD
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_TIM_PCI_CFG_NO_SNOOP
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_TIM_PCI_CFG_RELAXED
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_TIM_PCI_CFG_CTL_STR
value|mBIT(31)
name|u8
name|unused01100
index|[
literal|0x01100
operator|-
literal|0x01090
index|]
decl_stmt|;
comment|/* 0x01100 */
name|u64
name|sgrp_assign
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SGRP_ASSIGN_SGRP_ASSIGN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x01108 */
name|u64
name|sgrp_aoa_and_result
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SGRP_AOA_AND_RESULT_PET_SGRP_AOA_AND_RESULT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 64)
comment|/* 0x01110 */
name|u64
name|rpe_pci_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_LRO_DATA_ENABLE
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_LRO_HDR_ENABLE
value|mBIT(8)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_LRO_CQE_ENABLE
value|mBIT(9)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_NONLL_CQE_ENABLE
value|mBIT(10)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_BASE_LL_CQE_ENABLE
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_LL_CQE_IDATA_ENABLE
value|mBIT(12)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_CQRQ_IR_ENABLE
value|mBIT(13)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_CQSQ_IR_ENABLE
value|mBIT(14)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_PAD_CQRR_IR_ENABLE
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_NOSNOOP_DATA
value|mBIT(18)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_NOSNOOP_NONLL_CQE
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_NOSNOOP_LL_CQE
value|mBIT(20)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_NOSNOOP_CQRQ_IR
value|mBIT(21)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_NOSNOOP_CQSQ_IR
value|mBIT(22)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_NOSNOOP_CQRR_IR
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_RELAXED_DATA
value|mBIT(26)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_RELAXED_NONLL_CQE
value|mBIT(27)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_RELAXED_LL_CQE
value|mBIT(28)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_RELAXED_CQRQ_IR
value|mBIT(29)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_RELAXED_CQSQ_IR
value|mBIT(30)
define|#
directive|define
name|VXGE_HAL_RPE_PCI_CFG_RELAXED_CQRR_IR
value|mBIT(31)
comment|/* 0x01118 */
name|u64
name|rpe_lro_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RPE_LRO_CFG_SUPPRESS_LRO_ETH_TRLR
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_RPE_LRO_CFG_ALLOW_LRO_SNAP_SNAPJUMBO_MRG
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_RPE_LRO_CFG_ALLOW_LRO_LLC_LLCJUMBO_MRG
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_RPE_LRO_CFG_INCL_ACK_CNT_IN_CQE
value|mBIT(23)
comment|/* 0x01120 */
name|u64
name|pe_mr2vp_ack_blk_limit
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PE_MR2VP_ACK_BLK_LIMIT_BLK_LIMIT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
comment|/* 0x01128 */
name|u64
name|pe_mr2vp_rirr_lirr_blk_limit
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PE_MR2VP_RIRR_LIRR_BLK_LIMIT_RIRR_BLK_LIMIT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 32)
define|#
directive|define
name|VXGE_HAL_PE_MR2VP_RIRR_LIRR_BLK_LIMIT_LIRR_BLK_LIMIT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 32, 32)
comment|/* 0x01130 */
name|u64
name|txpe_pci_nce_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TXPE_PCI_NCE_CFG_NCE_THRESH
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
define|#
directive|define
name|VXGE_HAL_TXPE_PCI_NCE_CFG_PAD_TOWI_ENABLE
value|mBIT(55)
define|#
directive|define
name|VXGE_HAL_TXPE_PCI_NCE_CFG_NOSNOOP_TOWI
value|mBIT(63)
name|u8
name|unused01180
index|[
literal|0x01180
operator|-
literal|0x01138
index|]
decl_stmt|;
comment|/* 0x01180 */
name|u64
name|msg_qpad_en_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSG_QPAD_EN_CFG_UMQ_BWR_READ
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_MSG_QPAD_EN_CFG_DMQ_BWR_READ
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_MSG_QPAD_EN_CFG_MXP_GENDMA_READ
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_MSG_QPAD_EN_CFG_UXP_GENDMA_READ
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_MSG_QPAD_EN_CFG_UMQ_MSG_WRITE
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_MSG_QPAD_EN_CFG_UMQDMQ_IR_WRITE
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_MSG_QPAD_EN_CFG_MXP_GENDMA_WRITE
value|mBIT(27)
define|#
directive|define
name|VXGE_HAL_MSG_QPAD_EN_CFG_UXP_GENDMA_WRITE
value|mBIT(31)
comment|/* 0x01188 */
name|u64
name|msg_pci_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MSG_PCI_CFG_GENDMA_NO_SNOOP
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_MSG_PCI_CFG_UMQDMQ_IR_NO_SNOOP
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_MSG_PCI_CFG_UMQ_NO_SNOOP
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_MSG_PCI_CFG_DMQ_NO_SNOOP
value|mBIT(15)
comment|/* 0x01190 */
name|u64
name|umqdmq_ir_init
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQDMQ_IR_INIT_HOST_WRITE_ADD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x01198 */
name|u64
name|dmq_ir_int
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DMQ_IR_INT_IMMED_ENABLE
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_DMQ_IR_INT_EVENT_ENABLE
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_DMQ_IR_INT_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 9, 7)
define|#
directive|define
name|VXGE_HAL_DMQ_IR_INT_BITMAP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 16, 16)
comment|/* 0x011a0 */
name|u64
name|dmq_bwr_init_add
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DMQ_BWR_INIT_ADD_HOST
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x011a8 */
name|u64
name|dmq_bwr_init_byte
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DMQ_BWR_INIT_BYTE_COUNT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
comment|/* 0x011b0 */
name|u64
name|dmq_ir
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DMQ_IR_POLICY
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
comment|/* 0x011b8 */
name|u64
name|umq_int
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQ_INT_IMMED_ENABLE
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_UMQ_INT_EVENT_ENABLE
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_UMQ_INT_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 9, 7)
define|#
directive|define
name|VXGE_HAL_UMQ_INT_BITMAP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 16, 16)
comment|/* 0x011c0 */
name|u64
name|umq_mr2vp_bwr_pfch_init
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQ_MR2VP_BWR_PFCH_INIT_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
comment|/* 0x011c8 */
name|u64
name|umq_bwr_pfch_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQ_BWR_PFCH_CTRL_POLL_EN
value|mBIT(3)
comment|/* 0x011d0 */
name|u64
name|umq_mr2vp_bwr_eol
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQ_MR2VP_BWR_EOL_POLL_LATENCY
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
comment|/* 0x011d8 */
name|u64
name|umq_bwr_init_add
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQ_BWR_INIT_ADD_HOST
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x011e0 */
name|u64
name|umq_bwr_init_byte
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQ_BWR_INIT_BYTE_COUNT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
comment|/* 0x011e8 */
name|u64
name|gendma_int
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_GENDMA_INT_IMMED_ENABLE
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_GENDMA_INT_EVENT_ENABLE
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_GENDMA_INT_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 9, 7)
define|#
directive|define
name|VXGE_HAL_GENDMA_INT_BITMAP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 16, 16)
comment|/* 0x011f0 */
name|u64
name|umqdmq_ir_init_notify
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQDMQ_IR_INIT_NOTIFY_PULSE
value|mBIT(3)
comment|/* 0x011f8 */
name|u64
name|dmq_init_notify
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DMQ_INIT_NOTIFY_PULSE
value|mBIT(3)
comment|/* 0x01200 */
name|u64
name|umq_init_notify
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQ_INIT_NOTIFY_PULSE
value|mBIT(3)
name|u8
name|unused01380
index|[
literal|0x01380
operator|-
literal|0x01208
index|]
decl_stmt|;
comment|/* 0x01380 */
name|u64
name|tpa_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TPA_CFG_IGNORE_FRAME_ERR
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_TPA_CFG_IPV6_STOP_SEARCHING
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_TPA_CFG_L4_PSHDR_PRESENT
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_TPA_CFG_SUPPORT_MOBILE_IPV6_HDRS
value|mBIT(15)
name|u8
name|unused01400
index|[
literal|0x01400
operator|-
literal|0x01388
index|]
decl_stmt|;
comment|/* 0x01400 */
name|u64
name|tx_vp_reset_discarded_frms
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TX_VP_RESET_DISCARDED_FRMS_TX_VP_RESET_DISCARDED_FRMS
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 48, 16)
name|u8
name|unused01480
index|[
literal|0x01480
operator|-
literal|0x01408
index|]
decl_stmt|;
comment|/* 0x01480 */
name|u64
name|fau_rpa_vcfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FAU_RPA_VCFG_L4_COMP_CSUM
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_FAU_RPA_VCFG_L3_INCL_CF
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_FAU_RPA_VCFG_L3_COMP_CSUM
value|mBIT(15)
name|u8
name|unused014a8
index|[
literal|0x014a8
operator|-
literal|0x01488
index|]
decl_stmt|;
comment|/* 0x014a8 */
name|u64
name|fau_adaptive_lro_filter_ctrl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_CTRL_IP_FILTER_EN
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_CTRL_IP_MODE
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_CTRL_VLAN_FILTER_EN
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_CTRL_IPV4_ADDRESS_A_EN
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_CTRL_IPV4_ADDRESS_B_EN
value|mBIT(4)
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_CTRL_IPV4_ADDRESS_C_EN
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_CTRL_IPV4_ADDRESS_D_EN
value|mBIT(6)
comment|/* 0x014b0 */
name|u64
name|fau_adaptive_lro_filter_ip_data0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_IP_DATA0_DATA
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x014b8 */
name|u64
name|fau_adaptive_lro_filter_ip_data1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_IP_DATA1_DATA
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x014c0 */
name|u64
name|fau_adaptive_lro_filter_vlan_data
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FAU_ADAPTIVE_LRO_FILTER_VLAN_DATA_VLAN_VID
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 12)
name|u8
name|unused014d0
index|[
literal|0x014d0
operator|-
literal|0x014c8
index|]
decl_stmt|;
comment|/* 0x014d0 */
name|u64
name|dbg_stats_rx_mpa
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBG_STATS_RX_MPA_CRC_FAIL_FRMS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 16)
define|#
directive|define
name|VXGE_HAL_DBG_STATS_RX_MPA_MRK_FAIL_FRMS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 16, 16)
define|#
directive|define
name|VXGE_HAL_DBG_STATS_RX_MPA_LEN_FAIL_FRMS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 16)
comment|/* 0x014d8 */
name|u64
name|dbg_stats_rx_fau
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBG_STATS_RX_FAU_RX_WOL_FRMS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 16)
define|#
directive|define
name|VXGE_HAL_DBG_STATS_RX_FAU_RX_VP_RESET_DISCARDED_FRMS
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 16, 16)
define|#
directive|define
name|VXGE_HAL_DBG_STATS_RX_FAU_RX_PERMITTED_FRMS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
name|u8
name|unused014f0
index|[
literal|0x014f0
operator|-
literal|0x014e0
index|]
decl_stmt|;
comment|/* 0x014f0 */
name|u64
name|fbmc_vp_rdy
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FBMC_VP_RDY_QUEUE_SPAV_FM
value|mBIT(0)
name|u8
name|unused01e00
index|[
literal|0x01e00
operator|-
literal|0x014f8
index|]
decl_stmt|;
comment|/* 0x01e00 */
name|u64
name|vpath_pcipif_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_PCIPIF_INT_STATUS_SRPCIM_MSG_TO_VPATH_INT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_VPATH_PCIPIF_INT_STATUS_VPATH_SPARE_R1_INT
value|mBIT(7)
comment|/* 0x01e08 */
name|u64
name|vpath_pcipif_int_mask
decl_stmt|;
name|u8
name|unused01e20
index|[
literal|0x01e20
operator|-
literal|0x01e10
index|]
decl_stmt|;
comment|/* 0x01e20 */
name|u64
name|srpcim_msg_to_vpath_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_MSG_TO_VPATH_REG_INT
value|mBIT(3)
comment|/* 0x01e28 */
name|u64
name|srpcim_msg_to_vpath_mask
decl_stmt|;
comment|/* 0x01e30 */
name|u64
name|srpcim_msg_to_vpath_alarm
decl_stmt|;
name|u8
name|unused01ea0
index|[
literal|0x01ea0
operator|-
literal|0x01e38
index|]
decl_stmt|;
comment|/* 0x01ea0 */
name|u64
name|vpath_to_srpcim_wmsg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_TO_SRPCIM_WMSG_WMSG
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x01ea8 */
name|u64
name|vpath_to_srpcim_wmsg_trig
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_TO_SRPCIM_WMSG_TRIG
value|mBIT(0)
name|u8
name|unused02000
index|[
literal|0x02000
operator|-
literal|0x01eb0
index|]
decl_stmt|;
comment|/* 0x02000 */
name|u64
name|vpath_general_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_INT_STATUS_PIC_INT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_INT_STATUS_PCI_INT
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_INT_STATUS_WRDMA_INT
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_INT_STATUS_XMAC_INT
value|mBIT(19)
comment|/* 0x02008 */
name|u64
name|vpath_general_int_mask
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_INT_MASK_PIC_INT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_INT_MASK_PCI_INT
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_INT_MASK_WRDMA_INT
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_INT_MASK_XMAC_INT
value|mBIT(19)
comment|/* 0x02010 */
name|u64
name|vpath_ppif_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_PPIF_INT_STATUS_KDFCCTL_ERRORS_INT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_VPATH_PPIF_INT_STATUS_GENERAL_ERRORS_INT
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_VPATH_PPIF_INT_STATUS_PCI_CONFIG_ERRORS_INT
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_VPATH_PPIF_INT_STATUS_MRPCIM_TO_VPATH_ALARM_INT
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_VPATH_PPIF_INT_STATUS_SRPCIM_TO_VPATH_ALARM_INT
value|mBIT(19)
comment|/* 0x02018 */
name|u64
name|vpath_ppif_int_mask
decl_stmt|;
comment|/* 0x02020 */
name|u64
name|kdfcctl_errors_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO0_OVRWR
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO1_OVRWR
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO2_OVRWR
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO0_POISON
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO1_POISON
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO2_POISON
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO0_DMA_ERR
value|mBIT(31)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO1_DMA_ERR
value|mBIT(35)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_ERRORS_REG_KDFCCTL_FIFO2_DMA_ERR
value|mBIT(39)
comment|/* 0x02028 */
name|u64
name|kdfcctl_errors_mask
decl_stmt|;
comment|/* 0x02030 */
name|u64
name|kdfcctl_errors_alarm
decl_stmt|;
name|u8
name|unused02040
index|[
literal|0x02040
operator|-
literal|0x02038
index|]
decl_stmt|;
comment|/* 0x02040 */
name|u64
name|general_errors_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_GENERAL_ERRORS_REG_DBLGEN_FIFO0_OVRFLOW
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_GENERAL_ERRORS_REG_DBLGEN_FIFO1_OVRFLOW
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_GENERAL_ERRORS_REG_DBLGEN_FIFO2_OVRFLOW
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_GENERAL_ERRORS_REG_STATSB_PIF_CHAIN_ERR
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_GENERAL_ERRORS_REG_STATSB_DROP_TIMEOUT
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_GENERAL_ERRORS_REG_TGT_ILLEGAL_ACCESS
value|mBIT(27)
define|#
directive|define
name|VXGE_HAL_GENERAL_ERRORS_REG_INI_SERR_DET
value|mBIT(31)
comment|/* 0x02048 */
name|u64
name|general_errors_mask
decl_stmt|;
comment|/* 0x02050 */
name|u64
name|general_errors_alarm
decl_stmt|;
comment|/* 0x02058 */
name|u64
name|pci_config_errors_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_ERRORS_REG_STATUS_ERR
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_ERRORS_REG_UNCOR_ERR
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_ERRORS_REG_COR_ERR
value|mBIT(11)
comment|/* 0x02060 */
name|u64
name|pci_config_errors_mask
decl_stmt|;
comment|/* 0x02068 */
name|u64
name|pci_config_errors_alarm
decl_stmt|;
comment|/* 0x02070 */
name|u64
name|mrpcim_to_vpath_alarm_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MRPCIM_TO_VPATH_ALARM_REG_ALARM
value|mBIT(3)
comment|/* 0x02078 */
name|u64
name|mrpcim_to_vpath_alarm_mask
decl_stmt|;
comment|/* 0x02080 */
name|u64
name|mrpcim_to_vpath_alarm_alarm
decl_stmt|;
comment|/* 0x02088 */
name|u64
name|srpcim_to_vpath_alarm_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_TO_VPATH_ALARM_REG_PPIF_ALARM
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 17)
comment|/* 0x02090 */
name|u64
name|srpcim_to_vpath_alarm_mask
decl_stmt|;
comment|/* 0x02098 */
name|u64
name|srpcim_to_vpath_alarm_alarm
decl_stmt|;
name|u8
name|unused02108
index|[
literal|0x02108
operator|-
literal|0x020a0
index|]
decl_stmt|;
comment|/* 0x02108 */
name|u64
name|kdfcctl_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFCCTL_STATUS_KDFCCTL_FIFO0_PRES
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_STATUS_KDFCCTL_FIFO1_PRES
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 8, 8)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_STATUS_KDFCCTL_FIFO2_PRES
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 16, 8)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_STATUS_KDFCCTL_FIFO0_OVRWR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 24, 8)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_STATUS_KDFCCTL_FIFO1_OVRWR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 8)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_STATUS_KDFCCTL_FIFO2_OVRWR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 40, 8)
comment|/* 0x02110 */
name|u64
name|rsthdlr_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_RSTHDLR_STATUS_RSTHDLR_CURRENT_RESET
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_RSTHDLR_STATUS_RSTHDLR_CURRENT_VPIN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 6, 2)
comment|/* 0x02118 */
name|u64
name|fifo0_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FIFO0_STATUS_DBLGEN_FIFO0_RDIDX
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 12)
comment|/* 0x02120 */
name|u64
name|fifo1_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FIFO1_STATUS_DBLGEN_FIFO1_RDIDX
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 12)
comment|/* 0x02128 */
name|u64
name|fifo2_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_FIFO2_STATUS_DBLGEN_FIFO2_RDIDX
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 12)
name|u8
name|unused02158
index|[
literal|0x02158
operator|-
literal|0x02130
index|]
decl_stmt|;
comment|/* 0x02158 */
name|u64
name|tgt_illegal_access
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TGT_ILLEGAL_ACCESS_SWIF_REGION
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 7)
name|u8
name|unused02200
index|[
literal|0x02200
operator|-
literal|0x02160
index|]
decl_stmt|;
comment|/* 0x02200 */
name|u64
name|vpath_general_cfg1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_TC_VALUE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 3)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_DATA_BYTE_SWAPEN
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_DATA_FLIPEN
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_CTL_BYTE_SWAPEN
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_CTL_FLIPEN
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_MSIX_ADDR_SWAPEN
value|mBIT(51)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_MSIX_ADDR_FLIPEN
value|mBIT(55)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_MSIX_DATA_SWAPEN
value|mBIT(59)
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG1_MSIX_DATA_FLIPEN
value|mBIT(63)
comment|/* 0x02208 */
name|u64
name|vpath_general_cfg2
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG2_SIZE_QUANTUM
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 3)
comment|/* 0x02210 */
name|u64
name|vpath_general_cfg3
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENERAL_CFG3_IGNORE_VPATH_RST_FOR_INTA
value|mBIT(3)
name|u8
name|unused02220
index|[
literal|0x02220
operator|-
literal|0x02218
index|]
decl_stmt|;
comment|/* 0x02220 */
name|u64
name|kdfcctl_cfg0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_SWAPEN_FIFO0
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_SWAPEN_FIFO1
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_SWAPEN_FIFO2
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BIT_FLIPEN_FIFO0
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BIT_FLIPEN_FIFO1
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BIT_FLIPEN_FIFO2
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE0_FIFO0
value|mBIT(9)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE0_FIFO1
value|mBIT(10)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE0_FIFO2
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE1_FIFO0
value|mBIT(13)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE1_FIFO1
value|mBIT(14)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE1_FIFO2
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE2_FIFO0
value|mBIT(17)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE2_FIFO1
value|mBIT(18)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE2_FIFO2
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE3_FIFO0
value|mBIT(21)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE3_FIFO1
value|mBIT(22)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE3_FIFO2
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE4_FIFO0
value|mBIT(25)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE4_FIFO1
value|mBIT(26)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE4_FIFO2
value|mBIT(27)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE5_FIFO0
value|mBIT(29)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE5_FIFO1
value|mBIT(30)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE5_FIFO2
value|mBIT(31)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE6_FIFO0
value|mBIT(33)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE6_FIFO1
value|mBIT(34)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE6_FIFO2
value|mBIT(35)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE7_FIFO0
value|mBIT(37)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE7_FIFO1
value|mBIT(38)
define|#
directive|define
name|VXGE_HAL_KDFCCTL_CFG0_BYTE_MASK_BYTE7_FIFO2
value|mBIT(39)
comment|/* 0x02228 */
name|u64
name|dblgen_cfg0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG0_NO_OF_QWORDS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 12)
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG0_EN_DMA
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG0_NO_SNOOP
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG0_RELAX_ORD
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG0_RD_SPLIT_ON_ADDR
value|mBIT(27)
comment|/* 0x02230 */
name|u64
name|dblgen_cfg1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG1_FIFO0_BUFFER_START_ADDR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x02238 */
name|u64
name|dblgen_cfg2
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG2_FIFO1_BUFFER_START_ADDR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x02240 */
name|u64
name|dblgen_cfg3
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG3_FIFO2_BUFFER_START_ADDR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x02248 */
name|u64
name|dblgen_cfg4
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG4_TRIPLET_PRIORITY_VP_NUMBER
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 3, 5)
comment|/* 0x02250 */
name|u64
name|dblgen_cfg5
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG5_FIFO0_WRIDX
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 12)
comment|/* 0x02258 */
name|u64
name|dblgen_cfg6
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG6_FIFO1_WRIDX
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 12)
comment|/* 0x02260 */
name|u64
name|dblgen_cfg7
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_DBLGEN_CFG7_FIFO2_WRIDX
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 12)
comment|/* 0x02268 */
name|u64
name|stats_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_STATS_CFG_START_HOST_ADDR
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 57)
comment|/* 0x02270 */
name|u64
name|interrupt_cfg0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_INTERRUPT_CFG0_MSIX_FOR_RXTI
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 7)
define|#
directive|define
name|VXGE_HAL_INTERRUPT_CFG0_GROUP0_MSIX_FOR_TXTI
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 9, 7)
define|#
directive|define
name|VXGE_HAL_INTERRUPT_CFG0_GROUP1_MSIX_FOR_TXTI
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 17, 7)
define|#
directive|define
name|VXGE_HAL_INTERRUPT_CFG0_GROUP2_MSIX_FOR_TXTI
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 25, 7)
define|#
directive|define
name|VXGE_HAL_INTERRUPT_CFG0_GROUP3_MSIX_FOR_TXTI
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 33, 7)
name|u8
name|unused02280
index|[
literal|0x02280
operator|-
literal|0x02278
index|]
decl_stmt|;
comment|/* 0x02280 */
name|u64
name|interrupt_cfg2
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_INTERRUPT_CFG2_ALARM_MAP_TO_MSG
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 7)
comment|/* 0x02288 */
name|u64
name|one_shot_vect0_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ONE_SHOT_VECT0_EN_ONE_SHOT_VECT0_EN
value|mBIT(3)
comment|/* 0x02290 */
name|u64
name|one_shot_vect1_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ONE_SHOT_VECT1_EN_ONE_SHOT_VECT1_EN
value|mBIT(3)
comment|/* 0x02298 */
name|u64
name|one_shot_vect2_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ONE_SHOT_VECT2_EN_ONE_SHOT_VECT2_EN
value|mBIT(3)
comment|/* 0x022a0 */
name|u64
name|one_shot_vect3_en
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ONE_SHOT_VECT3_EN_ONE_SHOT_VECT3_EN
value|mBIT(3)
name|u8
name|unused022b0
index|[
literal|0x022b0
operator|-
literal|0x022a8
index|]
decl_stmt|;
comment|/* 0x022b0 */
name|u64
name|pci_config_access_cfg1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_ACCESS_CFG1_ADDRESS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 12)
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_ACCESS_CFG1_SEL_FUNC0
value|mBIT(15)
comment|/* 0x022b8 */
name|u64
name|pci_config_access_cfg2
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_ACCESS_CFG2_REQ
value|mBIT(0)
comment|/* 0x022c0 */
name|u64
name|pci_config_access_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_ACCESS_STATUS_ACCESS_ERR
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_PCI_CONFIG_ACCESS_STATUS_DATA
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
name|u8
name|unused02300
index|[
literal|0x02300
operator|-
literal|0x022c8
index|]
decl_stmt|;
comment|/* 0x02300 */
name|u64
name|vpath_debug_stats0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_DEBUG_STATS0_INI_NUM_MWR_SENT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
comment|/* 0x02308 */
name|u64
name|vpath_debug_stats1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_DEBUG_STATS1_INI_NUM_MRD_SENT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
comment|/* 0x02310 */
name|u64
name|vpath_debug_stats2
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_DEBUG_STATS2_INI_NUM_CPL_RCVD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
comment|/* 0x02318 */
name|u64
name|vpath_debug_stats3
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_DEBUG_STATS3_INI_NUM_MWR_BYTE_SENT
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x02320 */
name|u64
name|vpath_debug_stats4
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_DEBUG_STATS4_INI_NUM_CPL_BYTE_RCVD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x02328 */
name|u64
name|vpath_debug_stats5
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_DEBUG_STATS5_WRCRDTARB_XOFF
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
comment|/* 0x02330 */
name|u64
name|vpath_debug_stats6
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_DEBUG_STATS6_RDCRDTARB_XOFF
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
comment|/* 0x02338 */
name|u64
name|vpath_genstats_count01
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENSTATS_COUNT01_PPIF_VPATH_GENSTATS_COUNT1
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 32)
define|#
directive|define
name|VXGE_HAL_VPATH_GENSTATS_COUNT01_PPIF_VPATH_GENSTATS_COUNT0
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 32, 32)
comment|/* 0x02340 */
name|u64
name|vpath_genstats_count23
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENSTATS_COUNT23_PPIF_VPATH_GENSTATS_COUNT3
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 32)
define|#
directive|define
name|VXGE_HAL_VPATH_GENSTATS_COUNT23_PPIF_VPATH_GENSTATS_COUNT2
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 32, 32)
comment|/* 0x02348 */
name|u64
name|vpath_genstats_count4
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENSTATS_COUNT4_PPIF_VPATH_GENSTATS_COUNT4
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 32, 32)
comment|/* 0x02350 */
name|u64
name|vpath_genstats_count5
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_GENSTATS_COUNT5_PPIF_VPATH_GENSTATS_COUNT5
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 32, 32)
name|u8
name|unused02540
index|[
literal|0x02540
operator|-
literal|0x02358
index|]
decl_stmt|;
comment|/* 0x02540 */
name|u64
name|qcc_pci_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_ADD_PAD_CQE_SPACE
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_ADD_PAD_WQE
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_ADD_PAD_SRQIR
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_NO_SNOOP_CQE_SPACE
value|mBIT(13)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_NO_SNOOP_WQE
value|mBIT(14)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_NO_SNOOP_SRQIR
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_RELAXED_SRQIR
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_CTL_STR_CQE_SPACE
value|mBIT(29)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_CTL_STR_WQE
value|mBIT(30)
define|#
directive|define
name|VXGE_HAL_QCC_PCI_CFG_CTL_STR_SRQIR
value|mBIT(31)
name|u8
name|unused02600
index|[
literal|0x02600
operator|-
literal|0x02548
index|]
decl_stmt|;
comment|/* 0x02600 */
name|u64
name|h2l_vpath_config
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_H2L_VPATH_CONFIG_OD_PAD_ENABLE
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_H2L_VPATH_CONFIG_OD_NO_SNOOP
value|mBIT(15)
comment|/* 0x02608 */
name|u64
name|h2l_zero_byte_read_address
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_H2L_ZERO_BYTE_READ_ADDRESS_H2L_ZERO_BYTE_READ_ADDRESS
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 64)
name|u8
name|unused02640
index|[
literal|0x02640
operator|-
literal|0x02610
index|]
decl_stmt|;
comment|/* 0x02640 */
name|u64
name|ph2l_vp_cfg0
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PH2L_VP_CFG0_NOSNOOP_DATA
value|mBIT(7)
block|}
name|vxge_hal_vpath_reg_t
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
comment|/* VXGE_HAL_VPATH_REGS_H */
end_comment

end_unit

