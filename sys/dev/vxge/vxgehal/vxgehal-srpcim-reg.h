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
name|VXGE_HAL_SRPCIM_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_SRPCIM_REGS_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
struct|struct
name|vxge_hal_srpcim_reg_t
block|{
comment|/* 0x00000 */
name|u64
name|tim_mr2sr_resource_assignment_vh
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TIM_MR2SR_RESOURCE_ASSIGNMENT_VH_BMAP_ROOT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 32)
name|u8
name|unused00100
index|[
literal|0x00100
operator|-
literal|0x00008
index|]
decl_stmt|;
comment|/* 0x00100 */
name|u64
name|srpcim_pcipif_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_PCIPIF_INT_STATUS_MRPCIM_MSG_INT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_SRPCIM_PCIPIF_INT_STATUS_VPATH_MSG_VPATH_MSG_INT
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_SRPCIM_PCIPIF_INT_STATUS_SRPCIM_SPARE_R1_SRPCIM_SPARE_R1_INT
define|\
value|mBIT(11)
comment|/* 0x00108 */
name|u64
name|srpcim_pcipif_int_mask
decl_stmt|;
comment|/* 0x00110 */
name|u64
name|mrpcim_msg_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MRPCIM_MSG_REG_SWIF_MRPCIM_TO_SRPCIM_RMSG_INT
value|mBIT(3)
comment|/* 0x00118 */
name|u64
name|mrpcim_msg_mask
decl_stmt|;
comment|/* 0x00120 */
name|u64
name|mrpcim_msg_alarm
decl_stmt|;
comment|/* 0x00128 */
name|u64
name|vpath_msg_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH0_TO_SRPCIM_RMSG_INT
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH1_TO_SRPCIM_RMSG_INT
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH2_TO_SRPCIM_RMSG_INT
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH3_TO_SRPCIM_RMSG_INT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH4_TO_SRPCIM_RMSG_INT
value|mBIT(4)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH5_TO_SRPCIM_RMSG_INT
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH6_TO_SRPCIM_RMSG_INT
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH7_TO_SRPCIM_RMSG_INT
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH8_TO_SRPCIM_RMSG_INT
value|mBIT(8)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH9_TO_SRPCIM_RMSG_INT
value|mBIT(9)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH10_TO_SRPCIM_RMSG_INT
value|mBIT(10)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH11_TO_SRPCIM_RMSG_INT
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH12_TO_SRPCIM_RMSG_INT
value|mBIT(12)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH13_TO_SRPCIM_RMSG_INT
value|mBIT(13)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH14_TO_SRPCIM_RMSG_INT
value|mBIT(14)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH15_TO_SRPCIM_RMSG_INT
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_VPATH_MSG_REG_SWIF_VPATH16_TO_SRPCIM_RMSG_INT
value|mBIT(16)
comment|/* 0x00130 */
name|u64
name|vpath_msg_mask
decl_stmt|;
comment|/* 0x00138 */
name|u64
name|vpath_msg_alarm
decl_stmt|;
name|u8
name|unused00158
index|[
literal|0x00158
operator|-
literal|0x00140
index|]
decl_stmt|;
comment|/* 0x00158 */
name|u64
name|vf_bargrp_no
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VF_BARGRP_NO_IDENTIFIER_LSB_FOR_BAR0
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 11, 5)
define|#
directive|define
name|VXGE_HAL_VF_BARGRP_NO_IDENTIFIER_LSB_FOR_BAR1
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 19, 5)
define|#
directive|define
name|VXGE_HAL_VF_BARGRP_NO_IDENTIFIER_LSB_FOR_BAR2
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 26, 6)
define|#
directive|define
name|VXGE_HAL_VF_BARGRP_NO_FIRST_VF_OFFSET
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 4)
define|#
directive|define
name|VXGE_HAL_VF_BARGRP_NO_MASK
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 36, 4)
comment|/* 0x00160 */
name|u64
name|srpcim_to_mrpcim_wmsg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_TO_MRPCIM_WMSG_SRPCIM_TO_MRPCIM_WMSG
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 64)
comment|/* 0x00168 */
name|u64
name|srpcim_to_mrpcim_wmsg_trig
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_TO_MRPCIM_WMSG_TRIG_SRPCIM_TO_MRPCIM_WMSG_TRIG
value|mBIT(0)
comment|/* 0x00170 */
name|u64
name|mrpcim_to_srpcim_rmsg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MRPCIM_TO_SRPCIM_RMSG_SWIF_MRPCIM_TO_SRPCIM_RMSG
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 64)
comment|/* 0x00178 */
name|u64
name|vpath_to_srpcim_rmsg_sel
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_TO_SRPCIM_RMSG_SEL_SEL
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 5)
comment|/* 0x00180 */
name|u64
name|vpath_to_srpcim_rmsg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_TO_SRPCIM_RMSG_SWIF_VPATH_TO_SRPCIM_RMSG
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 64)
name|u8
name|unused00200
index|[
literal|0x00200
operator|-
literal|0x00188
index|]
decl_stmt|;
comment|/* 0x00200 */
name|u64
name|srpcim_general_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_INT_STATUS_PIC_INT
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_INT_STATUS_PCI_INT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_INT_STATUS_XMAC_INT
value|mBIT(7)
name|u8
name|unused00210
index|[
literal|0x00210
operator|-
literal|0x00208
index|]
decl_stmt|;
comment|/* 0x00210 */
name|u64
name|srpcim_general_int_mask
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_INT_MASK_PIC_INT
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_INT_MASK_PCI_INT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_INT_MASK_XMAC_INT
value|mBIT(7)
name|u8
name|unused00220
index|[
literal|0x00220
operator|-
literal|0x00218
index|]
decl_stmt|;
comment|/* 0x00220 */
name|u64
name|srpcim_ppif_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_PPIF_INT_STATUS_SRPCIM_GEN_ERRORS_INT
define|\
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_SRPCIM_PPIF_INT_STATUS_MRPCIM_TO_SRPCIM_ALARM
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_SRPCIM_PPIF_INT_STATUS_VPATH_TO_SRPCIM_ALARM_INT
value|mBIT(11)
comment|/* 0x00228 */
name|u64
name|srpcim_ppif_int_mask
decl_stmt|;
comment|/* 0x00230 */
name|u64
name|srpcim_gen_errors_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_GEN_ERRORS_REG_PCICONFIG_PF_STATUS_ERR
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GEN_ERRORS_REG_PCICONFIG_PF_UNCOR_ERR
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GEN_ERRORS_REG_PCICONFIG_PF_COR_ERR
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GEN_ERRORS_REG_INTCTRL_SCHED_INT
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GEN_ERRORS_REG_INI_SERR_DET
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GEN_ERRORS_REG_TGT_PF_ILLEGAL_ACCESS
value|mBIT(23)
comment|/* 0x00238 */
name|u64
name|srpcim_gen_errors_mask
decl_stmt|;
comment|/* 0x00240 */
name|u64
name|srpcim_gen_errors_alarm
decl_stmt|;
comment|/* 0x00248 */
name|u64
name|mrpcim_to_srpcim_alarm_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MRPCIM_TO_SRPCIM_ALARM_REG_PPIF_MRPCIM_TO_SRPCIM_ALARM
value|mBIT(3)
comment|/* 0x00250 */
name|u64
name|mrpcim_to_srpcim_alarm_mask
decl_stmt|;
comment|/* 0x00258 */
name|u64
name|mrpcim_to_srpcim_alarm_alarm
decl_stmt|;
comment|/* 0x00260 */
name|u64
name|vpath_to_srpcim_alarm_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_VPATH_TO_SRPCIM_ALARM_REG_PPIF_VPATH_TO_SRPCIM_ALARM
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 17)
comment|/* 0x00268 */
name|u64
name|vpath_to_srpcim_alarm_mask
decl_stmt|;
comment|/* 0x00270 */
name|u64
name|vpath_to_srpcim_alarm_alarm
decl_stmt|;
name|u8
name|unused00280
index|[
literal|0x00280
operator|-
literal|0x00278
index|]
decl_stmt|;
comment|/* 0x00280 */
name|u64
name|pf_sw_reset
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_PF_SW_RESET_PF_SW_RESET
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 8)
comment|/* 0x00288 */
name|u64
name|srpcim_general_cfg1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_CFG1_BOOT_BYTE_SWAPEN
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_CFG1_BOOT_BIT_FLIPEN
value|mBIT(23)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_CFG1_MSIX_ADDR_SWAPEN
value|mBIT(27)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_CFG1_MSIX_ADDR_FLIPEN
value|mBIT(31)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_CFG1_MSIX_DATA_SWAPEN
value|mBIT(35)
define|#
directive|define
name|VXGE_HAL_SRPCIM_GENERAL_CFG1_MSIX_DATA_FLIPEN
value|mBIT(39)
comment|/* 0x00290 */
name|u64
name|srpcim_interrupt_cfg1
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_INTERRUPT_CFG1_ALARM_MAP_TO_MSG
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 7)
define|#
directive|define
name|VXGE_HAL_SRPCIM_INTERRUPT_CFG1_TRAFFIC_CLASS
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 9, 3)
comment|/* 0x00298 */
name|u64
name|srpcim_interrupt_cfg2
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_INTERRUPT_CFG2_MSIX_FOR_SCHED_INT
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 1, 7)
define|#
directive|define
name|VXGE_HAL_SRPCIM_INTERRUPT_CFG2_SCHED_ONE_SHOT
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_SRPCIM_INTERRUPT_CFG2_SCHED_TIMER_EN
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_SRPCIM_INTERRUPT_CFG2_SCHED_INT_PERIOD
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 32, 32)
name|u8
name|unused002a8
index|[
literal|0x002a8
operator|-
literal|0x002a0
index|]
decl_stmt|;
comment|/* 0x002a8 */
name|u64
name|srpcim_clear_msix_mask
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_CLEAR_MSIX_MASK_SRPCIM_CLEAR_MSIX_MASK
value|mBIT(0)
comment|/* 0x002b0 */
name|u64
name|srpcim_set_msix_mask
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_SET_MSIX_MASK_SRPCIM_SET_MSIX_MASK
value|mBIT(0)
comment|/* 0x002b8 */
name|u64
name|srpcim_clr_msix_one_shot
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_CLR_MSIX_ONE_SHOT_SRPCIM_CLR_MSIX_ONE_SHOT
value|mBIT(0)
comment|/* 0x002c0 */
name|u64
name|srpcim_rst_in_prog
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_RST_IN_PROG_SRPCIM_RST_IN_PROG
value|mBIT(7)
comment|/* 0x002c8 */
name|u64
name|srpcim_reg_modified
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_REG_MODIFIED_SRPCIM_REG_MODIFIED
value|mBIT(7)
comment|/* 0x002d0 */
name|u64
name|tgt_pf_illegal_access
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_TGT_PF_ILLEGAL_ACCESS_SWIF_REGION
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 1, 7)
comment|/* 0x002d8 */
name|u64
name|srpcim_msix_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SRPCIM_MSIX_STATUS_INTCTL_SRPCIM_MSIX_MASK
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_SRPCIM_MSIX_STATUS_INTCTL_SRPCIM_MSIX_PENDING_VECTOR
value|mBIT(7)
name|u8
name|unused00318
index|[
literal|0x00318
operator|-
literal|0x002e0
index|]
decl_stmt|;
comment|/* 0x00318 */
name|u64
name|usdc_vpl
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_USDC_VPL_SGRP_OWN
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 32)
name|u8
name|unused00600
index|[
literal|0x00600
operator|-
literal|0x00320
index|]
decl_stmt|;
comment|/* 0x00600 */
name|u64
name|one_cfg_sr_copy
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ONE_CFG_SR_COPY_ONE_CFG_RDY
value|mBIT(7)
comment|/* 0x00608 */
name|u64
name|sgrp_allocated
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SGRP_ALLOCATED_SGRP_ALLOC
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 0, 64)
comment|/* 0x00610 */
name|u64
name|sgrp_iwarp_lro_allocated
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_SGRP_IWARP_LRO_ALLOCATED_ENABLE_IWARP
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_SGRP_IWARP_LRO_ALLOCATED_LAST_IWARP_SGRP
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 11, 5)
name|u8
name|unused00880
index|[
literal|0x00880
operator|-
literal|0x00618
index|]
decl_stmt|;
comment|/* 0x00880 */
name|u64
name|xgmac_sr_int_status
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_XGMAC_SR_INT_STATUS_ASIC_NTWK_SR_ERR_INT
value|mBIT(3)
comment|/* 0x00888 */
name|u64
name|xgmac_sr_int_mask
decl_stmt|;
comment|/* 0x00890 */
name|u64
name|asic_ntwk_sr_err_reg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_SR_ERR_REG_XMACJ_NTWK_SUSTAINED_FAULT
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_SR_ERR_REG_XMACJ_NTWK_SUSTAINED_OK
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_SR_ERR_REG_XMACJ_NTWK_SUSTAINED_FAULT_OCCURRED
define|\
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_ASIC_NTWK_SR_ERR_REG_XMACJ_NTWK_SUSTAINED_OK_OCCURRED
value|mBIT(15)
comment|/* 0x00898 */
name|u64
name|asic_ntwk_sr_err_mask
decl_stmt|;
comment|/* 0x008a0 */
name|u64
name|asic_ntwk_sr_err_alarm
decl_stmt|;
name|u8
name|unused008c0
index|[
literal|0x008c0
operator|-
literal|0x008a8
index|]
decl_stmt|;
comment|/* 0x008c0 */
name|u64
name|xmac_vsport_choices_sr_clone
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_XMAC_VSPORT_CHOICES_SR_CLONE_VSPORT_VECTOR
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 0, 17)
name|u8
name|unused00900
index|[
literal|0x00900
operator|-
literal|0x008c8
index|]
decl_stmt|;
comment|/* 0x00900 */
name|u64
name|mr_rqa_top_prty_for_vh
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_MR_RQA_TOP_PRTY_FOR_VH_RQA_TOP_PRTY_FOR_VH
parameter_list|(
name|val
parameter_list|)
define|\
value|vBIT(val, 59, 5)
comment|/* 0x00908 */
name|u64
name|umq_vh_data_list_empty
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_UMQ_VH_DATA_LIST_EMPTY_ROCRC_UMQ_VH_DATA_LIST_EMPTY
value|mBIT(0)
comment|/* 0x00910 */
name|u64
name|wde_cfg
decl_stmt|;
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_FORCE_MWB_START
value|mBIT(0)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_FORCE_MWB_END
value|mBIT(1)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_FORCE_QB_START
value|mBIT(2)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_FORCE_QB_END
value|mBIT(3)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_FORCE_MPSB_START
value|mBIT(4)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_FORCE_MPSB_END
value|mBIT(5)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_MWB_OPT_EN
value|mBIT(6)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_QB_OPT_EN
value|mBIT(7)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS0_MPSB_OPT_EN
value|mBIT(8)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_FORCE_MWB_START
value|mBIT(9)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_FORCE_MWB_END
value|mBIT(10)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_FORCE_QB_START
value|mBIT(11)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_FORCE_QB_END
value|mBIT(12)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_FORCE_MPSB_START
value|mBIT(13)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_FORCE_MPSB_END
value|mBIT(14)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_MWB_OPT_EN
value|mBIT(15)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_QB_OPT_EN
value|mBIT(16)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_NS1_MPSB_OPT_EN
value|mBIT(17)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_DISABLE_QPAD_FOR_UNALIGNED_ADDR
value|mBIT(19)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_ALIGNMENT_PREFERENCE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 30, 2)
define|#
directive|define
name|VXGE_HAL_WDE_CFG_MEM_WORD_SIZE
parameter_list|(
name|val
parameter_list|)
value|vBIT(val, 46, 2)
block|}
name|vxge_hal_srpcim_reg_t
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
comment|/* VXGE_HAL_SRPCIM_REGS_H */
end_comment

end_unit

