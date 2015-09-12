begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_PCIE_W_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_PCIE_W_REG_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* * Unit Registers */
struct|struct
name|al_pcie_rev1_w_global_ctrl
block|{
comment|/* [0x0]  */
name|uint32_t
name|port_init
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|port_status
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|pm_control
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|events_gen
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev2_w_global_ctrl
block|{
comment|/* [0x0]  */
name|uint32_t
name|port_init
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|port_status
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|pm_control
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|events_gen
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|pended_corr_err_sts_int
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|pended_uncorr_err_sts_int
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|sris_kp_counter_value
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_global_ctrl
block|{
comment|/* [0x0]  */
name|uint32_t
name|port_init
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|port_status
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|pm_control
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|pended_corr_err_sts_int
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|pended_uncorr_err_sts_int
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|sris_kp_counter_value
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_events_gen_per_func
block|{
comment|/* [0x0]  */
name|uint32_t
name|events_gen
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_pm_state_per_func
block|{
comment|/* [0x0]  */
name|uint32_t
name|pm_state_per_func
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_cfg_bars_ovrd
block|{
comment|/* [0x0]  */
name|uint32_t
name|bar0_mask_lsb
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|bar0_mask_msb
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|bar0_limit_lsb
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|bar0_limit_msb
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|bar0_start_lsb
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|bar0_start_msb
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|bar0_ctrl
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|bar1_mask_lsb
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|bar1_mask_msb
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|bar1_limit_lsb
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|bar1_limit_msb
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|bar1_start_lsb
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|bar1_start_msb
decl_stmt|;
comment|/* [0x34]  */
name|uint32_t
name|bar1_ctrl
decl_stmt|;
comment|/* [0x38]  */
name|uint32_t
name|bar2_mask_lsb
decl_stmt|;
comment|/* [0x3c]  */
name|uint32_t
name|bar2_mask_msb
decl_stmt|;
comment|/* [0x40]  */
name|uint32_t
name|bar2_limit_lsb
decl_stmt|;
comment|/* [0x44]  */
name|uint32_t
name|bar2_limit_msb
decl_stmt|;
comment|/* [0x48]  */
name|uint32_t
name|bar2_start_lsb
decl_stmt|;
comment|/* [0x4c]  */
name|uint32_t
name|bar2_start_msb
decl_stmt|;
comment|/* [0x50]  */
name|uint32_t
name|bar2_ctrl
decl_stmt|;
comment|/* [0x54]  */
name|uint32_t
name|bar3_mask_lsb
decl_stmt|;
comment|/* [0x58]  */
name|uint32_t
name|bar3_mask_msb
decl_stmt|;
comment|/* [0x5c]  */
name|uint32_t
name|bar3_limit_lsb
decl_stmt|;
comment|/* [0x60]  */
name|uint32_t
name|bar3_limit_msb
decl_stmt|;
comment|/* [0x64]  */
name|uint32_t
name|bar3_start_lsb
decl_stmt|;
comment|/* [0x68]  */
name|uint32_t
name|bar3_start_msb
decl_stmt|;
comment|/* [0x6c]  */
name|uint32_t
name|bar3_ctrl
decl_stmt|;
comment|/* [0x70]  */
name|uint32_t
name|bar4_mask_lsb
decl_stmt|;
comment|/* [0x74]  */
name|uint32_t
name|bar4_mask_msb
decl_stmt|;
comment|/* [0x78]  */
name|uint32_t
name|bar4_limit_lsb
decl_stmt|;
comment|/* [0x7c]  */
name|uint32_t
name|bar4_limit_msb
decl_stmt|;
comment|/* [0x80]  */
name|uint32_t
name|bar4_start_lsb
decl_stmt|;
comment|/* [0x84]  */
name|uint32_t
name|bar4_start_msb
decl_stmt|;
comment|/* [0x88]  */
name|uint32_t
name|bar4_ctrl
decl_stmt|;
comment|/* [0x8c]  */
name|uint32_t
name|bar5_mask_lsb
decl_stmt|;
comment|/* [0x90]  */
name|uint32_t
name|bar5_mask_msb
decl_stmt|;
comment|/* [0x94]  */
name|uint32_t
name|bar5_limit_lsb
decl_stmt|;
comment|/* [0x98]  */
name|uint32_t
name|bar5_limit_msb
decl_stmt|;
comment|/* [0x9c]  */
name|uint32_t
name|bar5_start_lsb
decl_stmt|;
comment|/* [0xa0]  */
name|uint32_t
name|bar5_start_msb
decl_stmt|;
comment|/* [0xa4]  */
name|uint32_t
name|bar5_ctrl
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_debug
block|{
comment|/* [0x0]  */
name|uint32_t
name|info_0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|info_1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|info_2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|info_3
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_ob_ven_msg
block|{
comment|/* [0x0]  */
name|uint32_t
name|control
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|param_1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|param_2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|data_high
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|data_low
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_ap_user_send_msg
block|{
comment|/* [0x0]  */
name|uint32_t
name|req_info
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|ack_info
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_link_down
block|{
comment|/* [0x0]  */
name|uint32_t
name|reset_delay
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|reset_extend_rsrvd
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_cntl_gen
block|{
comment|/* [0x0]  */
name|uint32_t
name|features
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_parity
block|{
comment|/* [0x0]  */
name|uint32_t
name|en_core
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|status_core
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_last_wr
block|{
comment|/* [0x0]  */
name|uint32_t
name|cfg_addr
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev1_2_w_atu
block|{
comment|/* [0x0]  */
name|uint32_t
name|in_mask_pair
index|[
literal|6
index|]
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|out_mask_pair
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_atu
block|{
comment|/* [0x0]  */
name|uint32_t
name|in_mask_pair
index|[
literal|12
index|]
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|out_mask_pair
index|[
literal|8
index|]
decl_stmt|;
comment|/* [0x50] */
name|uint32_t
name|reg_out_mask
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_cfg_func_ext
block|{
comment|/* [0x0]  */
name|uint32_t
name|cfg
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_app_hdr_interface_send
block|{
comment|/* [0x0]  */
name|uint32_t
name|app_hdr_31_0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|app_hdr_63_32
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|app_hdr_95_64
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|app_hdr_127_96
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|app_err_bus
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|app_func_num_advisory
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|app_hdr_cmd
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_diag_command
block|{
comment|/* [0x0]  */
name|uint32_t
name|diag_ctrl
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev1_w_soc_int
block|{
comment|/* [0x0]  */
name|uint32_t
name|status_0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|status_1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|status_2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|mask_inta_leg_0
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|mask_inta_leg_1
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|mask_inta_leg_2
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|mask_msi_leg_0
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|mask_msi_leg_1
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|mask_msi_leg_2
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|msi_leg_cntl
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev2_w_soc_int
block|{
comment|/* [0x0]  */
name|uint32_t
name|status_0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|status_1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|status_2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|status_3
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|mask_inta_leg_0
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|mask_inta_leg_1
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|mask_inta_leg_2
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|mask_inta_leg_3
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|mask_msi_leg_0
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|mask_msi_leg_1
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|mask_msi_leg_2
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|mask_msi_leg_3
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|msi_leg_cntl
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_soc_int_per_func
block|{
comment|/* [0x0]  */
name|uint32_t
name|status_0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|status_1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|status_2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|status_3
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|mask_inta_leg_0
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|mask_inta_leg_1
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|mask_inta_leg_2
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|mask_inta_leg_3
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|mask_msi_leg_0
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|mask_msi_leg_1
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|mask_msi_leg_2
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|mask_msi_leg_3
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|msi_leg_cntl
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_ap_err
block|{
comment|/* 	 * [0x0] latch the header in case of any error occur in the core, read 	 * on clear of the last register in the bind. 	 */
name|uint32_t
name|hdr_log
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_status_per_func
block|{
comment|/* 	 * [0x0] latch the header in case of any error occure in the core, read 	 * on clear of the last register in the bind. 	 */
name|uint32_t
name|status_per_func
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_w_int_grp
block|{
comment|/* 	 * [0x0] Interrupt Cause Register 	 * Set by hardware 	 * - If MSI-X is enabled and auto_clear control bit =TRUE, automatically 	 * cleared after MSI-X message associated with this specific interrupt 	 * bit is sent (MSI-X acknowledge is received). 	 * - Software can set a bit in this register by writing 1 to the 	 * associated bit in the Interrupt Cause Set register 	 * Write-0 clears a bit. Write-1 has no effect. 	 * - On CPU Read - If clear_on_read control bit =TRUE, automatically 	 * cleared (all bits are cleared). 	 * When there is a conflict and on the same clock cycle, hardware tries 	 * to set a bit in the Interrupt Cause register, the specific bit is set 	 * to ensure the interrupt indication is not lost. 	 */
name|uint32_t
name|cause
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* 	 * [0x8] Interrupt Cause Set Register 	 * Writing 1 to a bit in this register sets its corresponding cause bit, 	 * enabling software to generate a hardware interrupt. Write 0 has no 	 * effect. 	 */
name|uint32_t
name|cause_set
decl_stmt|;
name|uint32_t
name|rsrvd_1
decl_stmt|;
comment|/* 	 * [0x10] Interrupt Mask Register 	 * If Auto-mask control bit =TRUE, automatically set to 1 after MSI-X 	 * message associatd with the associated interrupt bit is sent (AXI 	 * write acknowledge is received). 	 */
name|uint32_t
name|mask
decl_stmt|;
name|uint32_t
name|rsrvd_2
decl_stmt|;
comment|/* 	 * [0x18] Interrupt Mask Clear Register 	 * Used when auto-mask control bit=True. Enables CPU to clear a specific 	 * bit. It prevents a scenario in which the CPU overrides another bit 	 * with 1 (old value) that hardware has just cleared to 0. 	 * Write 0 to this register clears its corresponding mask bit. Write 1 	 * has no effect. 	 */
name|uint32_t
name|mask_clear
decl_stmt|;
name|uint32_t
name|rsrvd_3
decl_stmt|;
comment|/* 	 * [0x20] Interrupt Status Register 	 * This register latches the status of the interrupt source. 	 */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|rsrvd_4
decl_stmt|;
comment|/* [0x28] Interrupt Control Register */
name|uint32_t
name|control
decl_stmt|;
name|uint32_t
name|rsrvd_5
decl_stmt|;
comment|/* 	 * [0x30] Interrupt Mask Register 	 * Each bit in this register masks the corresponding cause bit for 	 * generating an Abort signal. Its default value is determined by unit 	 * instantiation. 	 * (Abort = Wire-OR of Cause& !Interrupt_Abort_Mask) 	 * This register provides error handling configuration for error 	 * interrupts 	 */
name|uint32_t
name|abort_mask
decl_stmt|;
name|uint32_t
name|rsrvd_6
decl_stmt|;
comment|/* 	 * [0x38] Interrupt Log Register 	 * Each bit in this register masks the corresponding cause bit for 	 * capturing the log registers. Its default value is determined by unit 	 * instantiation. 	 * (Log_capture = Wire-OR of Cause& !Interrupt_Log_Mask) 	 * This register provides error handling configuration for error 	 * interrupts. 	 */
name|uint32_t
name|log_mask
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev1_w_regs
block|{
name|struct
name|al_pcie_rev1_w_global_ctrl
name|global_ctrl
decl_stmt|;
comment|/* [0x0] */
name|uint32_t
name|rsrvd_0
index|[
literal|24
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_debug
name|debug
decl_stmt|;
comment|/* [0x80] */
name|struct
name|al_pcie_revx_w_ob_ven_msg
name|ob_ven_msg
decl_stmt|;
comment|/* [0x90] */
name|uint32_t
name|rsrvd_1
index|[
literal|86
index|]
decl_stmt|;
name|struct
name|al_pcie_rev1_w_soc_int
name|soc_int
decl_stmt|;
comment|/* [0x200] */
name|struct
name|al_pcie_revx_w_link_down
name|link_down
decl_stmt|;
comment|/* [0x228] */
name|struct
name|al_pcie_revx_w_cntl_gen
name|ctrl_gen
decl_stmt|;
comment|/* [0x230] */
name|struct
name|al_pcie_revx_w_parity
name|parity
decl_stmt|;
comment|/* [0x234] */
name|struct
name|al_pcie_revx_w_last_wr
name|last_wr
decl_stmt|;
comment|/* [0x23c] */
name|struct
name|al_pcie_rev1_2_w_atu
name|atu
decl_stmt|;
comment|/* [0x240] */
name|uint32_t
name|rsrvd_2
index|[
literal|36
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_a_m0
decl_stmt|;
comment|/* [0x300] */
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_b_m0
decl_stmt|;
comment|/* [0x340] */
name|uint32_t
name|rsrvd_3
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_a
decl_stmt|;
comment|/* [0x400] */
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_b
decl_stmt|;
comment|/* [0x440] */
block|}
struct|;
struct|struct
name|al_pcie_rev2_w_regs
block|{
name|struct
name|al_pcie_rev2_w_global_ctrl
name|global_ctrl
decl_stmt|;
comment|/* [0x0] */
name|uint32_t
name|rsrvd_0
index|[
literal|24
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_debug
name|debug
decl_stmt|;
comment|/* [0x80] */
name|struct
name|al_pcie_revx_w_ob_ven_msg
name|ob_ven_msg
decl_stmt|;
comment|/* [0x90] */
name|struct
name|al_pcie_revx_w_ap_user_send_msg
name|ap_user_send_msg
decl_stmt|;
comment|/* [0xa8] */
name|uint32_t
name|rsrvd_1
index|[
literal|20
index|]
decl_stmt|;
name|struct
name|al_pcie_rev2_w_soc_int
name|soc_int
decl_stmt|;
comment|/* [0x100] */
name|uint32_t
name|rsrvd_2
index|[
literal|61
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_link_down
name|link_down
decl_stmt|;
comment|/* [0x228] */
name|struct
name|al_pcie_revx_w_cntl_gen
name|ctrl_gen
decl_stmt|;
comment|/* [0x230] */
name|struct
name|al_pcie_revx_w_parity
name|parity
decl_stmt|;
comment|/* [0x234] */
name|struct
name|al_pcie_revx_w_last_wr
name|last_wr
decl_stmt|;
comment|/* [0x23c] */
name|struct
name|al_pcie_rev1_2_w_atu
name|atu
decl_stmt|;
comment|/* [0x240] */
name|uint32_t
name|rsrvd_3
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_ap_err
name|ap_err
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x288] */
name|uint32_t
name|rsrvd_4
index|[
literal|26
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_status_per_func
name|status_per_func
decl_stmt|;
comment|/* [0x300] */
name|uint32_t
name|rsrvd_5
index|[
literal|63
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_a
decl_stmt|;
comment|/* [0x400] */
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_b
decl_stmt|;
comment|/* [0x440] */
block|}
struct|;
struct|struct
name|al_pcie_rev3_w_regs
block|{
name|struct
name|al_pcie_rev3_w_global_ctrl
name|global_ctrl
decl_stmt|;
comment|/* [0x0] */
name|uint32_t
name|rsrvd_0
index|[
literal|24
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_debug
name|debug
decl_stmt|;
comment|/* [0x80] */
name|struct
name|al_pcie_revx_w_ob_ven_msg
name|ob_ven_msg
decl_stmt|;
comment|/* [0x90] */
name|struct
name|al_pcie_revx_w_ap_user_send_msg
name|ap_user_send_msg
decl_stmt|;
comment|/* [0xa8] */
name|uint32_t
name|rsrvd_1
index|[
literal|94
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_link_down
name|link_down
decl_stmt|;
comment|/* [0x228] */
name|struct
name|al_pcie_revx_w_cntl_gen
name|ctrl_gen
decl_stmt|;
comment|/* [0x230] */
name|struct
name|al_pcie_revx_w_parity
name|parity
decl_stmt|;
comment|/* [0x234] */
name|struct
name|al_pcie_revx_w_last_wr
name|last_wr
decl_stmt|;
comment|/* [0x23c] */
name|struct
name|al_pcie_rev3_w_atu
name|atu
decl_stmt|;
comment|/* [0x240] */
name|uint32_t
name|rsrvd_2
index|[
literal|8
index|]
decl_stmt|;
name|struct
name|al_pcie_rev3_w_cfg_func_ext
name|cfg_func_ext
decl_stmt|;
comment|/* [0x2e0] */
name|struct
name|al_pcie_rev3_w_app_hdr_interface_send
name|app_hdr_interface_send
decl_stmt|;
comment|/* [0x2e4] */
name|struct
name|al_pcie_rev3_w_diag_command
name|diag_command
decl_stmt|;
comment|/* [0x300] */
name|uint32_t
name|rsrvd_3
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|al_pcie_rev3_w_soc_int_per_func
name|soc_int_per_func
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
comment|/* [0x310] */
name|uint32_t
name|rsrvd_4
index|[
literal|44
index|]
decl_stmt|;
name|struct
name|al_pcie_rev3_w_events_gen_per_func
name|events_gen_per_func
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
comment|/* [0x490] */
name|uint32_t
name|rsrvd_5
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|al_pcie_rev3_w_pm_state_per_func
name|pm_state_per_func
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
comment|/* [0x4b0] */
name|uint32_t
name|rsrvd_6
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|al_pcie_rev3_w_cfg_bars_ovrd
name|cfg_bars_ovrd
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
comment|/* [0x500] */
name|uint32_t
name|rsrvd_7
index|[
literal|176
index|]
decl_stmt|;
name|uint32_t
name|rsrvd_8
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_ap_err
name|ap_err
index|[
literal|5
index|]
decl_stmt|;
comment|/* [0xac0] */
name|uint32_t
name|rsrvd_9
index|[
literal|11
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_status_per_func
name|status_per_func
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0xb00] */
name|uint32_t
name|rsrvd_10
index|[
literal|316
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_a
decl_stmt|;
comment|/* [0x1000] */
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_b
decl_stmt|;
comment|/* [0x1040] */
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_c
decl_stmt|;
comment|/* [0x1080] */
name|struct
name|al_pcie_revx_w_int_grp
name|int_grp_d
decl_stmt|;
comment|/* [0x10c0] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** Port_Init register ****/
comment|/* Enable port to start LTSSM Link Training */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_INIT_APP_LTSSM_EN_MASK
value|(1<< 0)
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_INIT_APP_LTSSM_EN_SHIFT
value|(0)
comment|/*  * Device Type  * Indicates the specific type of this PCIe Function. It is also used to set the  * Device/Port Type field.  * 4'b0000: PCIe Endpoint  * 4'b0001: Legacy PCIe Endpoint  * 4'b0100: Root Port of PCIe Root Complex  * Must be programmed before link training sequence. According to the reset  * strap  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_INIT_DEVICE_TYPE_MASK
value|0x000000F0
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_INIT_DEVICE_TYPE_SHIFT
value|4
comment|/*  * Performs Manual Lane reversal for transmit Lanes.  * Must be programmed before link training sequence.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_INIT_TX_LANE_FLIP_EN
value|(1<< 8)
comment|/*  * Performs Manual Lane reversal for receive Lanes.  * Must be programmed before link training sequence.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_INIT_RX_LANE_FLIP_EN
value|(1<< 9)
comment|/*  * Auxiliary Power Detected  * Indicates that auxiliary power (Vaux) is present. This one move to reset  * strap from  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_INIT_SYS_AUX_PWR_DET_NOT_USE
value|(1<< 10)
comment|/**** Port_Status register ****/
comment|/* PHY Link up/down indicator */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_PHY_LINK_UP
value|(1<< 0)
comment|/*  * Data Link Layer up/down indicator  * This status from the Flow Control Initialization State Machine indicates that  * Flow Control has been initiated and the Data Link Layer is ready to transmit  * and receive packets.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_DL_LINK_UP
value|(1<< 1)
comment|/* Reset request due to link down status. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_LINK_REQ_RST
value|(1<< 2)
comment|/* Power management is in L0s state.. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_PM_LINKST_IN_L0S
value|(1<< 3)
comment|/* Power management is in L1 state. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_PM_LINKST_IN_L1
value|(1<< 4)
comment|/* Power management is in L2 state. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_PM_LINKST_IN_L2
value|(1<< 5)
comment|/* Power management is exiting L2 state. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_PM_LINKST_L2_EXIT
value|(1<< 6)
comment|/* Power state of the device. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_PM_DSTATE_MASK
value|0x00000380
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_PM_DSTATE_SHIFT
value|7
comment|/* tie to zero. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_XMLH_IN_RL0S
value|(1<< 10)
comment|/* Timeout count before flush */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_LINK_TOUT_FLUSH_NOT
value|(1<< 11)
comment|/* Segmentation buffer not empty  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_RADM_Q_NOT_EMPTY
value|(1<< 12)
comment|/*  * Clock Turnoff Request  * Allows clock generation module to turn off core_clk based on the current  * power management state:  * 0: core_clk is required to be active for the current power state.  * 1: The current power state allows core_clk to be shut down.  * This does not indicate the clock requirement for the PHY.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PORT_STS_CORE_CLK_REQ_N
value|(1<< 31)
comment|/**** PM_Control register ****/
comment|/*  * Wake Up. Used by application logic to wake up the PMC state machine from a  * D1, D2, or D3 power state. EP mode only. Change the value from 0 to 1 to send  * the message. Per function the upper bits are not use for ocie core less than  * 8 functions  */
define|#
directive|define
name|PCIE_W_REV1_2_GLOBAL_CTRL_PM_CONTROL_PM_XMT_PME
value|(1<< 0)
define|#
directive|define
name|PCIE_W_REV3_GLOBAL_CTRL_PM_CONTROL_PM_XMT_PME_FUNC_MASK
value|0x000000FF
define|#
directive|define
name|PCIE_W_REV3_GLOBAL_CTRL_PM_CONTROL_PM_XMT_PME_FUNC_SHIFT
value|0
comment|/*  * Request to Enter ASPM L1.  * The core ignores the L1 entry request on app_req_entr_l1 when it is busy  * processing a transaction.  */
define|#
directive|define
name|PCIE_W_REV1_2_GLOBAL_CTRL_PM_CONTROL_REQ_ENTR_L1
value|(1<< 3)
define|#
directive|define
name|PCIE_W_REV3_GLOBAL_CTRL_PM_CONTROL_REQ_ENTR_L1
value|(1<< 8)
comment|/*  * Request to exit ASPM L1.  * Only effective if L1 is enabled.  */
define|#
directive|define
name|PCIE_W_REV1_2_GLOBAL_CTRL_PM_CONTROL_REQ_EXIT_L1
value|(1<< 4)
define|#
directive|define
name|PCIE_W_REV3_GLOBAL_CTRL_PM_CONTROL_REQ_EXIT_L1
value|(1<< 9)
comment|/*  * Indication that component is ready to enter the L23 state. The core delays  * sending PM_Enter_L23 (in response to PM_Turn_Off) until this signal becomes  * active.  * EP mode  */
define|#
directive|define
name|PCIE_W_REV1_2_GLOBAL_CTRL_PM_CONTROL_READY_ENTR_L23
value|(1<< 5)
define|#
directive|define
name|PCIE_W_REV3_GLOBAL_CTRL_PM_CONTROL_READY_ENTR_L23
value|(1<< 10)
comment|/*  * Request to generate a PM_Turn_Off Message to communicate transition to L2/L3  * Ready state to downstream components. Host must wait PM_Turn_Off_Ack messages  * acceptance RC mode.  */
define|#
directive|define
name|PCIE_W_REV1_2_GLOBAL_CTRL_PM_CONTROL_PM_XMT_TURNOFF
value|(1<< 6)
define|#
directive|define
name|PCIE_W_REV3_GLOBAL_CTRL_PM_CONTROL_PM_XMT_TURNOFF
value|(1<< 11)
comment|/*  * Provides a capability to defer incoming Configuration Requests until  * initialization is complete. When app_req_retry_en is asserted, the core  * completes incoming Configuration Requests with a Configuration Request Retry  * Status. Other incoming Requests complete with Unsupported Request status.  */
define|#
directive|define
name|PCIE_W_REV1_2_GLOBAL_CTRL_PM_CONTROL_APP_REQ_RETRY_EN
value|(1<< 7)
define|#
directive|define
name|PCIE_W_REV3_GLOBAL_CTRL_PM_CONTROL_APP_REQ_RETRY_EN
value|(1<< 12)
comment|/*  * Core core gate enable  * If set, core_clk is gated off whenever a clock turnoff request allows the  * clock generation module to turn off core_clk (Port_Status.core_clk_req_n  * field), and the PHY supports a request to disable clock gating. If not, the  * core clock turns off in P2 mode in any case (PIPE).  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_PM_CONTROL_CORE_CLK_GATE
value|(1<< 31)
comment|/**** sris_kp_counter_value register ****/
comment|/* skp counter when SRIS disable */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_GEN3_NO_SRIS_MASK
value|0x000001FF
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_GEN3_NO_SRIS_SHIFT
value|0
comment|/* skp counter when SRIS enable */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_GEN3_SRIS_MASK
value|0x0003FE00
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_GEN3_SRIS_SHIFT
value|9
comment|/* skp counter when SRIS enable for gen3 */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_GEN21_SRIS_MASK
value|0x1FFC0000
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_GEN21_SRIS_SHIFT
value|18
comment|/* mask the interrupt to the soc in case correctable error occur in the ARI.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_RSRVD_MASK
value|0x60000000
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_RSRVD_SHIFT
value|29
comment|/* not in use in the pcie_x8 core. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_SRIS_KP_COUNTER_VALUE_PCIE_X4_SRIS_EN
value|(1<< 31)
comment|/**** Events_Gen register ****/
comment|/* INT_D. Not supported  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_ASSERT_INTD
value|(1<< 0)
comment|/* INT_C. Not supported  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_ASSERT_INTC
value|(1<< 1)
comment|/* INT_B. Not supported  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_ASSERT_INTB
value|(1<< 2)
comment|/* Transmit INT_A Interrupt ControlEvery transition from 0 to 1  ... */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_ASSERT_INTA
value|(1<< 3)
comment|/* A request to generate an outbound MSI interrupt when MSI is e ... */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_MSI_TRNS_REQ
value|(1<< 4)
comment|/* Set the MSI vector before issuing msi_trans_req. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_MSI_VECTOR_MASK
value|0x000003E0
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_MSI_VECTOR_SHIFT
value|5
comment|/* The application requests hot reset to a downstream device */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_APP_RST_INIT
value|(1<< 10)
comment|/* The application request unlock message to be sent */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_UNLOCK_GEN
value|(1<< 30)
comment|/* Indicates that FLR on a Physical Function has been completed */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_FLR_PF_DONE
value|(1<< 31)
comment|/**** Cpl_TO_Info register ****/
comment|/* The Traffic Class of the timed out CPL */
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_TC_MASK
value|0x00000003
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_TC_SHIFT
value|0
comment|/* Indicates which Virtual Function (VF) had a CPL timeout */
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_FUN_NUM_MASK
value|0x000000FC
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_FUN_NUM_SHIFT
value|2
comment|/* The Tag field of the timed out CPL */
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_TAG_MASK
value|0x0000FF00
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_TAG_SHIFT
value|8
comment|/* The Attributes field of the timed out CPL */
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_ATTR_MASK
value|0x00030000
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_ATTR_SHIFT
value|16
comment|/* The Len field of the timed out CPL */
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_LEN_MASK
value|0x3FFC0000
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_LEN_SHIFT
value|18
comment|/*  * Write 1 to this field to clear the information logged in the register. New  * logged information will only be valid when the interrupt is cleared .  */
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_VALID
value|(1<< 31)
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_INFO_VALID_SHIFT
value|(31)
comment|/**** Rcv_Msg0_0 register ****/
comment|/* The Requester ID of the received message */
define|#
directive|define
name|PCIE_W_LCL_LOG_RCV_MSG0_0_REQ_ID_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_W_LCL_LOG_RCV_MSG0_0_REQ_ID_SHIFT
value|0
comment|/*  * Valid logged message  * Writing 1 to this bit enables new message capturing. Write one to clear  */
define|#
directive|define
name|PCIE_W_LCL_LOG_RCV_MSG0_0_VALID
value|(1<< 31)
comment|/**** Rcv_Msg1_0 register ****/
comment|/* The Requester ID of the received message */
define|#
directive|define
name|PCIE_W_LCL_LOG_RCV_MSG1_0_REQ_ID_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_W_LCL_LOG_RCV_MSG1_0_REQ_ID_SHIFT
value|0
comment|/*  * Valid logged message  * Writing 1 to this bit enables new message capturing. Write one to clear  */
define|#
directive|define
name|PCIE_W_LCL_LOG_RCV_MSG1_0_VALID
value|(1<< 31)
comment|/**** Core_Queues_Status register ****/
comment|/*  * Indicates which entries in the CPL lookup table  * have valid entries stored. NOT supported.  */
define|#
directive|define
name|PCIE_W_LCL_LOG_CORE_Q_STATUS_CPL_LUT_VALID_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_W_LCL_LOG_CORE_Q_STATUS_CPL_LUT_VALID_SHIFT
value|0
comment|/**** Cpl_to register ****/
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_REQID_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_W_LCL_LOG_CPL_TO_REQID_SHIFT
value|0
comment|/**** Debug_Info_0 register ****/
comment|/* Indicates the current power state */
define|#
directive|define
name|PCIE_W_DEBUG_INFO_0_PM_CURRENT_STATE_MASK
value|0x00000007
define|#
directive|define
name|PCIE_W_DEBUG_INFO_0_PM_CURRENT_STATE_SHIFT
value|0
comment|/* Current state of the LTSSM */
define|#
directive|define
name|PCIE_W_DEBUG_INFO_0_LTSSM_STATE_MASK
value|0x000001F8
define|#
directive|define
name|PCIE_W_DEBUG_INFO_0_LTSSM_STATE_SHIFT
value|3
comment|/* Decode of the Recovery. Equalization LTSSM state */
define|#
directive|define
name|PCIE_W_DEBUG_INFO_0_LTSSM_STATE_RCVRY_EQ
value|(1<< 9)
comment|/* State of selected internal signals, for debug purposes only */
define|#
directive|define
name|PCIE_W_DEBUG_INFO_0_CXPL_DEBUG_INFO_EI_MASK
value|0x03FFFC00
define|#
directive|define
name|PCIE_W_DEBUG_INFO_0_CXPL_DEBUG_INFO_EI_SHIFT
value|10
comment|/**** control register ****/
comment|/* Indication to send vendor message; when clear the message was sent. */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_CONTROL_REQ
value|(1<< 0)
comment|/**** param_1 register ****/
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_FMT_MASK
value|0x00000003
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_FMT_SHIFT
value|0
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_TYPE_MASK
value|0x0000007C
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_TYPE_SHIFT
value|2
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_TC_MASK
value|0x00000380
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_TC_SHIFT
value|7
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_TD
value|(1<< 10)
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_EP
value|(1<< 11)
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_ATTR_MASK
value|0x00003000
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_ATTR_SHIFT
value|12
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_LEN_MASK
value|0x00FFC000
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_LEN_SHIFT
value|14
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_TAG_MASK
value|0xFF000000
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_1_TAG_SHIFT
value|24
comment|/**** param_2 register ****/
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_2_REQ_ID_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_2_REQ_ID_SHIFT
value|0
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_2_CODE_MASK
value|0x00FF0000
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_2_CODE_SHIFT
value|16
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_2_RSVD_31_24_MASK
value|0xFF000000
define|#
directive|define
name|PCIE_W_OB_VEN_MSG_PARAM_2_RSVD_31_24_SHIFT
value|24
comment|/**** ack_info register ****/
comment|/* Vendor message parameters */
define|#
directive|define
name|PCIE_W_AP_USER_SEND_MSG_ACK_INFO_ACK
value|(1<< 0)
comment|/**** features register ****/
comment|/* Enable MSI fix from the SATA to the PCIe EP - Only valid for port zero */
define|#
directive|define
name|PCIE_W_CTRL_GEN_FEATURES_SATA_EP_MSI_FIX
value|AL_BIT(16)
comment|/**** in/out_mask_x_y register ****/
comment|/* When bit [i] set to 1 it maks the compare in the atu_in/out wind ... */
define|#
directive|define
name|PCIE_W_ATU_MASK_EVEN_ODD_ATU_MASK_40_32_EVEN_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_W_ATU_MASK_EVEN_ODD_ATU_MASK_40_32_EVEN_SHIFT
value|0
comment|/* When bit [i] set to 1 it maks the compare in the atu_in/out wind ... */
define|#
directive|define
name|PCIE_W_ATU_MASK_EVEN_ODD_ATU_MASK_40_32_ODD_MASK
value|0xFFFF0000
define|#
directive|define
name|PCIE_W_ATU_MASK_EVEN_ODD_ATU_MASK_40_32_ODD_SHIFT
value|16
comment|/**** cfg register ****/
comment|/*  * The 2-bit TPH Requester Enabled field of each TPH  * Requester Control register.  */
define|#
directive|define
name|PCIE_W_CFG_FUNC_EXT_CFG_CFG_TPH_REQ_EN_MASK
value|0x000000FF
define|#
directive|define
name|PCIE_W_CFG_FUNC_EXT_CFG_CFG_TPH_REQ_EN_SHIFT
value|0
comment|/* SRIS mode enable. */
define|#
directive|define
name|PCIE_W_CFG_FUNC_EXT_CFG_APP_SRIS_MODE
value|(1<< 8)
comment|/*  *  */
define|#
directive|define
name|PCIE_W_CFG_FUNC_EXT_CFG_RSRVD_MASK
value|0xFFFFFE00
define|#
directive|define
name|PCIE_W_CFG_FUNC_EXT_CFG_RSRVD_SHIFT
value|9
comment|/**** app_func_num_advisory register ****/
comment|/*  * The number of the function that is reporting the error  * indicated app_err_bus, valid when app_hdr_valid is asserted.  * Correctable and Uncorrected Internal errors (app_err_bus[10:9]) are  * not function specific, and are recorded for all physical functions,  * regardless of the value this bus. Function numbering starts at '0'.  */
define|#
directive|define
name|PCIE_W_APP_HDR_INTERFACE_SEND_APP_FUNC_NUM_ADVISORY_APP_ERR_FUNC_NUM_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_W_APP_HDR_INTERFACE_SEND_APP_FUNC_NUM_ADVISORY_APP_ERR_FUNC_NUM_SHIFT
value|0
comment|/*  * Description: Indicates that your application error is an advisory  * error. Your application should assert app_err_advisory under either  * of the following conditions:  * - The core is configured to mask completion timeout errors, your  * application is reporting a completion timeout error app_err_bus,  * and your application intends to resend the request. In such cases  * the error is an advisory error, as described in PCI Express 3.0  * Specification. When your application does not intend to resend  * the request, then your application must keep app_err_advisory  * de-asserted when reporting a completion timeout error.  * - The core is configured to forward poisoned TLPs to your  * application and your application is going to treat the poisoned  * TLP as a normal TLP, as described in PCI Express 3.0  * Specification. Upon receipt of a poisoned TLP, your application  * must report the error app_err_bus, and either assert  * app_err_advisory (to indicate an advisory error) or de-assert  * app_err_advisory (to indicate that your application is dropping the  * TLP).  * For more details, see the PCI Express 3.0 Specification to determine  * when an application error is an advisory error.  */
define|#
directive|define
name|PCIE_W_APP_HDR_INTERFACE_SEND_APP_FUNC_NUM_ADVISORY_APP_ERR_ADVISORY
value|(1<< 16)
comment|/*  * Rsrvd.  */
define|#
directive|define
name|PCIE_W_APP_HDR_INTERFACE_SEND_APP_FUNC_NUM_ADVISORY_RSRVD_MASK
value|0xFFFE0000
define|#
directive|define
name|PCIE_W_APP_HDR_INTERFACE_SEND_APP_FUNC_NUM_ADVISORY_RSRVD_SHIFT
value|17
comment|/**** app_hdr_cmd register ****/
comment|/*  * When set the header is send (need to clear before sending the next message).  */
define|#
directive|define
name|PCIE_W_APP_HDR_INTERFACE_SEND_APP_HDR_CMD_APP_HDR_VALID
value|(1<< 0)
comment|/*  * Rsrvd.  */
define|#
directive|define
name|PCIE_W_APP_HDR_INTERFACE_SEND_APP_HDR_CMD_RSRVD_MASK
value|0xFFFFFFFE
define|#
directive|define
name|PCIE_W_APP_HDR_INTERFACE_SEND_APP_HDR_CMD_RSRVD_SHIFT
value|1
comment|/**** diag_ctrl register ****/
comment|/*  * The 2-bit TPH Requester Enabled field of each TPH  * Requester Control register.  */
define|#
directive|define
name|PCIE_W_DIAG_COMMAND_DIAG_CTRL_DIAG_CTRL_BUS_MASK
value|0x00000007
define|#
directive|define
name|PCIE_W_DIAG_COMMAND_DIAG_CTRL_DIAG_CTRL_BUS_SHIFT
value|0
comment|/*  *  */
define|#
directive|define
name|PCIE_W_DIAG_COMMAND_DIAG_CTRL_RSRVD_MASK
value|0xFFFFFFF8
define|#
directive|define
name|PCIE_W_DIAG_COMMAND_DIAG_CTRL_RSRVD_SHIFT
value|3
comment|/**** Events_Gen register ****/
comment|/* INT_D. Not supported  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_ASSERT_INTD
value|(1<< 0)
comment|/* INT_C. Not supported  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_ASSERT_INTC
value|(1<< 1)
comment|/* INT_B. Not supported  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_ASSERT_INTB
value|(1<< 2)
comment|/*  * Transmit INT_A Interrupt Control  * Every transition from 0 to 1 schedules an Assert_ INT interrupt message for  * transmit.  * Every transition from 1 to 0, schedules a Deassert_INT interrupt message for  * transmit. Which interrupt, the PCIe only use INTA message.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_ASSERT_INTA
value|(1<< 3)
comment|/*  * A request to generate an outbound MSI interrupt when MSI is enabled. Change  * from 1'b0 to 1'b1 to create an MSI write to be sent.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_MSI_TRNS_REQ
value|(1<< 4)
comment|/* Set the MSI vector before issuing msi_trans_req. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_MSI_VECTOR_MASK
value|0x000003E0
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_MSI_VECTOR_SHIFT
value|5
comment|/*  * The application requests hot reset to a downstream device. Change the value  * from 0 to 1 to send hot reset. Only func 0 is supported.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_APP_RST_INIT
value|(1<< 10)
comment|/*  * The application request unlock message to be sent. Change the value from 0 to  * 1 to send the message. Only func 0 is supported.  */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_UNLOCK_GEN
value|(1<< 30)
comment|/* Indicates that FLR on a Physical Function has been completed. */
define|#
directive|define
name|PCIE_W_GLOBAL_CTRL_EVENTS_GEN_FLR_PF_DONE
value|(1<< 31)
comment|/**** pm_state_per_func register ****/
comment|/*  * Description: The current power management D-state of the  * function:  * \u25a0 000b: D0  * \u25a0 001b: D1  * \u25a0 010b: D2  * \u25a0 011b: D3  * \u25a0 100b: Uninitialized  * \u25a0 Other values: Not applicable  * There are 3 bits of pm_dstate for each configured function.  */
define|#
directive|define
name|PCIE_W_PM_STATE_PER_FUNC_PM_STATE_PER_FUNC_PM_DSTATE_MASK
value|0x0000000F
define|#
directive|define
name|PCIE_W_PM_STATE_PER_FUNC_PM_STATE_PER_FUNC_PM_DSTATE_SHIFT
value|0
comment|/*  * PME Status bit from the PMCSR. There is 1 bit of  * pm_status for each configured function  */
define|#
directive|define
name|PCIE_W_PM_STATE_PER_FUNC_PM_STATE_PER_FUNC_PM_STATUS
value|(1<< 4)
comment|/*  * PME Enable bit in the PMCSR. There is 1 bit of  * pm_pme_en for each configured function.  */
define|#
directive|define
name|PCIE_W_PM_STATE_PER_FUNC_PM_STATE_PER_FUNC_PM_PME_EN
value|(1<< 5)
comment|/*  * Auxiliary Power Enable bit in the Device Control  * register. There is 1 bit of aux_pm_en for each configured function.  */
define|#
directive|define
name|PCIE_W_PM_STATE_PER_FUNC_PM_STATE_PER_FUNC_AUX_PME_EN
value|(1<< 6)
comment|/*  * This field should be set according to the MAX_FUNC_NUM set in the PCIe core,  * it uses as mask (bit per function) to the dsate when set to zero.  */
define|#
directive|define
name|PCIE_W_PM_STATE_PER_FUNC_PM_STATE_PER_FUNC_ASPM_PF_ENABLE_MAX_FUNC_NUMBER
value|(1<< 7)
comment|/*  * This field should be set according to the MAX_FUNC_NUM set in the PCIe core,  * it uses as mask (bit per function) to the ASPM contrl bit, when set to zero.  */
define|#
directive|define
name|PCIE_W_PM_STATE_PER_FUNC_PM_STATE_PER_FUNC_DSATE_PF_ENABLE_MAX_FUNC_NUMBER
value|(1<< 8)
comment|/**** bar0_ctrl register ****/
comment|/* bar is en and override the internal PF bar. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR0_CTRL_BAR_EN_MASK
value|0x00000003
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR0_CTRL_BAR_EN_SHIFT
value|0
comment|/* bar is io */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR0_CTRL_BAR_IO_MASK
value|0x0000000C
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR0_CTRL_BAR_IO_SHIFT
value|2
comment|/* Reserved. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR0_CTRL_RSRVS_MASK
value|0xFFFFFFF0
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR0_CTRL_RSRVS_SHIFT
value|4
comment|/**** bar1_ctrl register ****/
comment|/* bar is en and override the internal PF bar. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR1_CTRL_BAR_EN_MASK
value|0x00000003
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR1_CTRL_BAR_EN_SHIFT
value|0
comment|/* bar is io */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR1_CTRL_BAR_IO_MASK
value|0x0000000C
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR1_CTRL_BAR_IO_SHIFT
value|2
comment|/* Reserved. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR1_CTRL_RSRVS_MASK
value|0xFFFFFFF0
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR1_CTRL_RSRVS_SHIFT
value|4
comment|/**** bar2_ctrl register ****/
comment|/* bar is en and override the internal PF bar. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR2_CTRL_BAR_EN_MASK
value|0x00000003
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR2_CTRL_BAR_EN_SHIFT
value|0
comment|/* bar is io */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR2_CTRL_BAR_IO_MASK
value|0x0000000C
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR2_CTRL_BAR_IO_SHIFT
value|2
comment|/* Reserved. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR2_CTRL_RSRVS_MASK
value|0xFFFFFFF0
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR2_CTRL_RSRVS_SHIFT
value|4
comment|/**** bar3_ctrl register ****/
comment|/* bar is en and override the internal PF bar. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR3_CTRL_BAR_EN_MASK
value|0x00000003
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR3_CTRL_BAR_EN_SHIFT
value|0
comment|/* bar is io */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR3_CTRL_BAR_IO_MASK
value|0x0000000C
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR3_CTRL_BAR_IO_SHIFT
value|2
comment|/* Reserved. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR3_CTRL_RSRVS_MASK
value|0xFFFFFFF0
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR3_CTRL_RSRVS_SHIFT
value|4
comment|/**** bar4_ctrl register ****/
comment|/* bar is en and override the internal PF bar. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR4_CTRL_BAR_EN_MASK
value|0x00000003
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR4_CTRL_BAR_EN_SHIFT
value|0
comment|/* bar is io */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR4_CTRL_BAR_IO_MASK
value|0x0000000C
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR4_CTRL_BAR_IO_SHIFT
value|2
comment|/* Reserved. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR4_CTRL_RSRVS_MASK
value|0xFFFFFFF0
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR4_CTRL_RSRVS_SHIFT
value|4
comment|/**** bar5_ctrl register ****/
comment|/* bar is en and override the internal PF bar. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR5_CTRL_BAR_EN_MASK
value|0x00000003
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR5_CTRL_BAR_EN_SHIFT
value|0
comment|/* bar is io */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR5_CTRL_BAR_IO_MASK
value|0x0000000C
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR5_CTRL_BAR_IO_SHIFT
value|2
comment|/* Reserved. */
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR5_CTRL_RSRVS_MASK
value|0xFFFFFFF0
define|#
directive|define
name|PCIE_W_CFG_BARS_OVRD_BAR5_CTRL_RSRVS_SHIFT
value|4
comment|/**** cause_A register ****/
comment|/* Deassert_INTD received. Write zero to clear this bit. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_DEASSERT_INTD
value|(1<< 0)
comment|/* Deassert_INTC received. Write zero to clear this bit. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_DEASSERT_INTC
value|(1<< 1)
comment|/* Deassert_INTB received. Write zero to clear this bit. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_DEASSERT_INTB
value|(1<< 2)
comment|/* Deassert_INTA received. Write zero to clear this bit. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_DEASSERT_INTA
value|(1<< 3)
comment|/* Assert_INTD received. Write zero to clear this bit. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_ASSERT_INTD
value|(1<< 4)
comment|/* Assert_INTC received. Write zero to clear this bit. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_ASSERT_INTC
value|(1<< 5)
comment|/* Assert_INTC received. Write zero to clear this bit. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_ASSERT_INTB
value|(1<< 6)
comment|/* Assert_INTA received. Write zero to clear this bit. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_ASSERT_INTA
value|(1<< 7)
comment|/*  * MSI Controller Interrupt  * MSI interrupt is being received. Write zero to clear this bit  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_MSI_CNTR_RCV_INT
value|(1<< 8)
comment|/*  * MSI sent grant. Write zero to clear this bit.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_MSI_TRNS_GNT
value|(1<< 9)
comment|/*  * System error detected  * Indicates if any device in the hierarchy reports any of the following errors  * and the associated enable bit is set in the Root Control register:  * ERR_COR  * ERR_FATAL  * ERR_NONFATAL  * Also asserted when an internal error is detected. Write zero to clear this  * bit.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_SYS_ERR_RC
value|(1<< 10)
comment|/*  * Set when software initiates FLR on a Physical Function by writing to the  * Initiate FLR register bit of that function Write zero to clear this bit.  */
define|#
directive|define
name|PCIE_W_REV1_2_INT_GRP_A_CAUSE_A_FLR_PF_ACTIVE
value|(1<< 11)
define|#
directive|define
name|PCIE_W_REV3_INT_GRP_A_CAUSE_A_RSRVD_11
value|(1<< 11)
comment|/*  * Reported error condition causes a bit to be set in the Root Error Status  * register and the associated error message reporting enable bit is set in the  * Root Error Command Register. Write zero to clear this bit.  */
define|#
directive|define
name|PCIE_W_REV1_2_INT_GRP_A_CAUSE_A_AER_RC_ERR
value|(1<< 12)
define|#
directive|define
name|PCIE_W_REV3_INT_GRP_A_CAUSE_A_RSRVD_12
value|(1<< 12)
comment|/*  * The core asserts aer_rc_err_msi when all of the following conditions are  * true:  * - MSI or MSI-X is enabled.  * - A reported error condition causes a bit to be set in the Root Error Status  * register.  * - The associated error message reporting enable bit is set in the Root Error  * Command register Write zero to clear this bit  */
define|#
directive|define
name|PCIE_W_REV1_2_INT_GRP_A_CAUSE_A_AER_RC_ERR_MSI
value|(1<< 13)
define|#
directive|define
name|PCIE_W_REV3_INT_GRP_A_CAUSE_A_RSRVD_13
value|(1<< 13)
comment|/*  * Wake Up. Wake up from power management unit.  * The core generates wake to request the system to restore power and clock when  * a beacon has been detected. wake is an active high signal and its rising edge  * should be detected to drive the WAKE# on the connector Write zero to clear  * this bit  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_WAKE
value|(1<< 14)
comment|/*  * The core asserts cfg_pme_int when all of the following conditions are true:  * - INTx Assertion Disable bit in the Command register is 0.  * - PME Interrupt Enable bit in the Root Control register is set to 1.  * - PME Status bit in the Root Status register is set to 1. Write zero to clear  * this bit  */
define|#
directive|define
name|PCIE_W_REV1_2_INT_GRP_A_CAUSE_A_PME_INT
value|(1<< 15)
define|#
directive|define
name|PCIE_W_REV3_INT_GRP_A_CAUSE_A_RSRVD_15
value|(1<< 15)
comment|/*  * The core asserts cfg_pme_msi when all of the following conditions are true:  * - MSI or MSI-X is enabled.  * - PME Interrupt Enable bit in the Root Control register is set to 1.  * - PME Status bit in the Root Status register is set to 1. Write zero to clear  * this bit  */
define|#
directive|define
name|PCIE_W_REV1_2_INT_GRP_A_CAUSE_A_PME_MSI
value|(1<< 16)
define|#
directive|define
name|PCIE_W_REV3_INT_GRP_A_CAUSE_A_RSRVD_16
value|(1<< 16)
comment|/*  * The core asserts hp_pme when all of the following conditions are true:  * - The PME Enable bit in the Power Management Control and Status register is  * set to 1.  * - Any bit in the Slot Status register transitions from 0 to 1 and the  * associated event notification is enabled in the Slot Control register. Write  * zero to clear this bit  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_HP_PME
value|(1<< 17)
comment|/*  * The core asserts hp_int when all of the following conditions are true:  * - INTx Assertion Disable bit in the Command register is 0.  * - Hot-Plug interrupts are enabled in the Slot Control register.  * - Any bit in the Slot Status register is equal to 1, and the associated event  * notification is enabled in the Slot Control register. Write zero to clear  * this bit  */
define|#
directive|define
name|PCIE_W_REV1_2_INT_GRP_A_CAUSE_A_HP_INT
value|(1<< 18)
comment|/* The outstanding write counter become  full should never happen */
define|#
directive|define
name|PCIE_W_REV3_INT_GRP_A_CAUSE_A_WRITE_COUNTER_FULL_ERR
value|(1<< 18)
comment|/*  * The core asserts hp_msi when the logical AND of the following conditions  * transitions from false to true:  * - MSI or MSI-X is enabled.  * - Hot-Plug interrupts are enabled in the Slot Control register.  * - Any bit in the Slot Status register transitions from 0 to 1 and the  * associated event notification is enabled in the Slot Control register.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_HP_MSI
value|(1<< 19)
comment|/* Read VPD registers notification */
define|#
directive|define
name|PCIE_W_REV1_2_INT_GRP_A_CAUSE_A_VPD_INT
value|(1<< 20)
comment|/* not use */
define|#
directive|define
name|PCIE_W_REV3_INT_GRP_A_CAUSE_A_NOT_USE
value|(1<< 20)
comment|/*  * The core assert link down event, whenever the link is going down. Write zero  * to clear this bit, pulse signal  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_LINK_DOWN_EVENT
value|(1<< 21)
comment|/*  * When the EP gets a command to shut down, signal the software to block any new  * TLP.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_PM_XTLH_BLOCK_TLP
value|(1<< 22)
comment|/* PHY/MAC link up */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_XMLH_LINK_UP
value|(1<< 23)
comment|/* Data link up */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_RDLH_LINK_UP
value|(1<< 24)
comment|/* The ltssm is in RCVRY_LOCK state. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_LTSSM_RCVRY_STATE
value|(1<< 25)
comment|/*  * Config write transaction to the config space by the RC peer, enable this  * interrupt only for EP mode.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_CFG_WR_EVENT
value|(1<< 26)
comment|/* AER error */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_AP_PENDED_CORR_ERR_STS_INT
value|(1<< 28)
comment|/* AER error */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CAUSE_A_AP_PENDED_UNCORR_ERR_STS_INT
value|(1<< 29)
comment|/**** control_A register ****/
comment|/* When Clear_on_Read =1, all bits of  Cause register are cleared on read. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_CLEAR_ON_READ
value|(1<< 0)
comment|/*  * (Must be set only when MSIX is enabled.)  * When Auto-Mask =1 and an MSI-X ACK for this bit is received, its  * corresponding bit in the Mask register is set, masking future interrupts.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_AUTO_MASK
value|(1<< 1)
comment|/*  * Auto_Clear (RW)  * When Auto-Clear =1, the bits in the Interrupt Cause register are auto-cleared  * after MSI-X is acknowledged. Must be used only if MSI-X is enabled.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_AUTO_CLEAR
value|(1<< 2)
comment|/*  * When Set_on_Posedge =1, the bits in the Interrupt Cause register are set on  * the posedge of the interrupt source, i.e., when interrupt source =1 and  * Interrupt Status = 0.  * When Set_on_Posedge =0, the bits in the Interrupt Cause register are set when  * interrupt source =1.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_SET_ON_POSEDGE
value|(1<< 3)
comment|/*  * When Moderation_Reset =1, all Moderation timers associated with the interrupt  * cause bits are cleared to 0, enabling immediate interrupt assertion if any  * unmasked cause bit is set to 1. This bit is self-negated.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_MOD_RST
value|(1<< 4)
comment|/*  * When mask_msi_x =1, no MSI-X from this group is sent. This bit must be set to  * 1 when the associated summary bit in this group is used to generate a single  * MSI-X for this group.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_MASK_MSI_X
value|(1<< 5)
comment|/* MSI-X AWID value. Same ID for all cause bits. */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_AWID_MASK
value|0x00000F00
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_AWID_SHIFT
value|8
comment|/*  * This value determines the interval between interrupts; writing ZERO disables  * Moderation.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_MOD_INTV_MASK
value|0x00FF0000
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_MOD_INTV_SHIFT
value|16
comment|/*  * This value determines the Moderation_Timer_Clock speed.  * 0- Moderation-timer is decremented every 1x256 SB clock cycles ~1uS.  * 1- Moderation-timer is decremented every 2x256 SB clock cycles ~2uS.  * N- Moderation-timer is decremented every Nx256 SB clock cycles ~(N+1) uS.  */
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_MOD_RES_MASK
value|0x0F000000
define|#
directive|define
name|PCIE_W_INT_GRP_A_CONTROL_A_MOD_RES_SHIFT
value|24
comment|/**** cause_B register ****/
comment|/* Indicates that the core received a PM_PME Message. Write Zero to clear. */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_PM_PME
value|(1<< 0)
comment|/*  * Indicates that the core received a PME_TO_Ack Message. Write Zero to clear.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_PM_TO_ACK
value|(1<< 1)
comment|/*  * Indicates that the core received an PME_Turn_Off Message. Write Zero to  * clear.  * EP mode only  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_PM_TURNOFF
value|(1<< 2)
comment|/* Indicates that the core received an ERR_CORR Message. Write Zero to clear. */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_CORRECTABLE_ERR
value|(1<< 3)
comment|/*  * Indicates that the core received an ERR_NONFATAL Message. Write Zero to  * clear.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_NONFATAL_ERR
value|(1<< 4)
comment|/*  * Indicates that the core received an ERR_FATAL Message. Write Zero to clear.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_FATAL_ERR
value|(1<< 5)
comment|/*  * Indicates that the core received a Vendor Defined Message. Write Zero to  * clear.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_VENDOR_0
value|(1<< 6)
comment|/*  * Indicates that the core received a Vendor Defined Message. Write Zero to  * clear.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_VENDOR_1
value|(1<< 7)
comment|/* Indicates that the core received an Unlock Message. Write Zero to clear. */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_MSG_UNLOCK
value|(1<< 8)
comment|/*  * Notification when the Link Autonomous Bandwidth Status register (Link Status  * register bit 15) is updated and the Link Autonomous Bandwidth Interrupt  * Enable (Link Control register bit 11) is set. This bit is not applicable to,  * and is reserved, for Endpoint device. Write Zero to clear  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_LINK_AUTO_BW_INT
value|(1<< 12)
comment|/*  * Notification that the Link Equalization Request bit in the Link Status 2  * Register has been set. Write Zero to clear.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_LINK_EQ_REQ_INT
value|(1<< 13)
comment|/*  * OB Vendor message request is granted by the PCIe core Write Zero to clear.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_VENDOR_MSG_GRANT
value|(1<< 14)
comment|/* CPL timeout from the PCIe core inidication. Write Zero to clear */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_CMP_TIME_OUT
value|(1<< 15)
comment|/*  * Slave Response Composer Lookup Error  * Indicates that an overflow occurred in a lookup table of the Inbound  * responses. This indicates that there was a violation of the number of  * outstanding NP requests issued for the Outbound direction. Write zero to  * clear  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_RADMX_CMPOSER_LOOKUP_ERR
value|(1<< 16)
comment|/* Parity Error */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CAUSE_B_PARITY_ERROR_CORE
value|(1<< 17)
comment|/**** control_B register ****/
comment|/* When Clear_on_Read =1, all bits of the Cause register are cleared on read. */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_CLEAR_ON_READ
value|(1<< 0)
comment|/*  * (Must be set only when MSIX is enabled.)  * When Auto-Mask =1 and an MSI-X ACK for this bit is received, its  * corresponding bit in the Mask register is set, masking future interrupts.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_AUTO_MASK
value|(1<< 1)
comment|/*  * Auto_Clear (RW)  * When Auto-Clear =1, the bits in the Interrupt Cause register are auto-cleared  * after MSI-X is acknowledged. Must be used only if MSI-X is enabled.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_AUTO_CLEAR
value|(1<< 2)
comment|/*  * When Set_on_Posedge =1, the bits in the interrupt Cause register are set on  * the posedge of the interrupt source, i.e., when Interrupt Source =1 and  * Interrupt Status = 0.  * When Set_on_Posedge =0, the bits in the Interrupt Cause register are set when  * Interrupt Source =1.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_SET_ON_POSEDGE
value|(1<< 3)
comment|/*  * When Moderation_Reset =1, all Moderation timers associated with the interrupt  * cause bits are cleared to 0, enabling an immediate interrupt assertion if any  * unmasked cause bit is set to 1. This bit is self-negated.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_MOD_RST
value|(1<< 4)
comment|/*  * When mask_msi_x =1, no MSI-X from this group is sent. This bit must be set to  * 1 when the associated summary bit in this group is used to generate a single  * MSI-X for this group.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_MASK_MSI_X
value|(1<< 5)
comment|/* MSI-X AWID value. Same ID for all cause bits. */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_AWID_MASK
value|0x00000F00
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_AWID_SHIFT
value|8
comment|/*  * This value determines the interval between interrupts. Writing ZERO disables  * Moderation.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_MOD_INTV_MASK
value|0x00FF0000
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_MOD_INTV_SHIFT
value|16
comment|/*  * This value determines the Moderation_Timer_Clock speed.  * 0- Moderation-timer is decremented every 1x256 SB clock cycles ~1uS.  * 1- Moderation-timer is decremented every 2x256 SB clock cycles ~2uS.  * N- Moderation-timer is decremented every Nx256 SB clock cycles ~(N+1) uS.  */
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_MOD_RES_MASK
value|0x0F000000
define|#
directive|define
name|PCIE_W_INT_GRP_B_CONTROL_B_MOD_RES_SHIFT
value|24
comment|/**** cause_C register ****/
comment|/* VPD interrupt, ot read/write frpm EEPROM */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_VPD_INT_FUNC_MASK
value|0x0000000F
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_VPD_INT_FUNC_SHIFT
value|0
comment|/* flr PF active */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_FLR_PF_ACTIVE_MASK
value|0x000000F0
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_FLR_PF_ACTIVE_SHIFT
value|4
comment|/* System ERR RC. */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_SYS_ERR_RC_MASK
value|0x00000F00
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_SYS_ERR_RC_SHIFT
value|8
comment|/* AER RC INT */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_AER_RC_ERR_INT_MASK
value|0x0000F000
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_AER_RC_ERR_INT_SHIFT
value|12
comment|/* AER RC MSI */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_AER_RC_ERR_MSI_MASK
value|0x000F0000
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_AER_RC_ERR_MSI_SHIFT
value|16
comment|/* PME MSI */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_PME_MSI_MASK
value|0x00F00000
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_PME_MSI_SHIFT
value|20
comment|/* PME int */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_PME_INT_MASK
value|0x0F000000
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_CFG_PME_INT_SHIFT
value|24
comment|/* SB overflow */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_RADM_QOVERFLOW
value|(1<< 28)
comment|/* ecrc was injected through the diag_ctrl bus */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_ECRC_INJECTED
value|(1<< 29)
comment|/* lcrc was injected through the diag_ctrl bus */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_LCRC_INJECTED
value|(1<< 30)
comment|/* lcrc was injected through the diag_ctrl bus */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CAUSE_GRP_C_RSRVD
value|(1<< 31)
comment|/**** control_C register ****/
comment|/* When Clear_on_Read =1, all bits of  Cause register are cleared on read. */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_CLEAR_ON_READ
value|(1<< 0)
comment|/*  * (Must be set only when MSIX is enabled.)  * When Auto-Mask =1 and an MSI-X ACK for this bit is received, its  * corresponding bit in the Mask register is set, masking future interrupts.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_AUTO_MASK
value|(1<< 1)
comment|/*  * Auto_Clear (RW)  * When Auto-Clear =1, the bits in the Interrupt Cause register are auto-cleared  * after MSI-X is acknowledged. Must be used only if MSI-X is enabled.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_AUTO_CLEAR
value|(1<< 2)
comment|/*  * When Set_on_Posedge =1, the bits in the Interrupt Cause register are set on  * the posedge of the interrupt source, i.e., when interrupt source =1 and  * Interrupt Status = 0.  * When Set_on_Posedge =0, the bits in the Interrupt Cause register are set when  * interrupt source =1.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_SET_ON_POSEDGE
value|(1<< 3)
comment|/*  * When Moderation_Reset =1, all Moderation timers associated with the interrupt  * cause bits are cleared to 0, enabling immediate interrupt assertion if any  * unmasked cause bit is set to 1. This bit is self-negated.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_MOD_RST
value|(1<< 4)
comment|/*  * When mask_msi_x =1, no MSI-X from this group is sent. This bit must be set to  * 1 when the associated summary bit in this group is used to generate a single  * MSI-X for this group.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_MASK_MSI_X
value|(1<< 5)
comment|/* MSI-X AWID value. Same ID for all cause bits. */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_AWID_MASK
value|0x00000F00
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_AWID_SHIFT
value|8
comment|/*  * This value determines the interval between interrupts; writing ZERO disables  * Moderation.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_MOD_INTV_MASK
value|0x00FF0000
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_MOD_INTV_SHIFT
value|16
comment|/*  * This value determines the Moderation_Timer_Clock speed.  * 0- Moderation-timer is decremented every 1x256 SB clock cycles ~1uS.  * 1- Moderation-timer is decremented every 2x256 SB clock cycles ~2uS.  * N- Moderation-timer is decremented every Nx256 SB clock cycles ~(N+1) uS.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_MOD_RES_MASK
value|0x0F000000
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_C_INT_CONTROL_GRP_C_MOD_RES_SHIFT
value|24
comment|/**** control_D register ****/
comment|/* When Clear_on_Read =1, all bits of  Cause register are cleared on read. */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_CLEAR_ON_READ
value|(1<< 0)
comment|/*  * (Must be set only when MSIX is enabled.)  * When Auto-Mask =1 and an MSI-X ACK for this bit is received, its  * corresponding bit in the Mask register is set, masking future interrupts.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_AUTO_MASK
value|(1<< 1)
comment|/*  * Auto_Clear (RW)  * When Auto-Clear =1, the bits in the Interrupt Cause register are auto-cleared  * after MSI-X is acknowledged. Must be used only if MSI-X is enabled.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_AUTO_CLEAR
value|(1<< 2)
comment|/*  * When Set_on_Posedge =1, the bits in the Interrupt Cause register are set on  * the posedge of the interrupt source, i.e., when interrupt source =1 and  * Interrupt Status = 0.  * When Set_on_Posedge =0, the bits in the Interrupt Cause register are set when  * interrupt source =1.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_SET_ON_POSEDGE
value|(1<< 3)
comment|/*  * When Moderation_Reset =1, all Moderation timers associated with the interrupt  * cause bits are cleared to 0, enabling immediate interrupt assertion if any  * unmasked cause bit is set to 1. This bit is self-negated.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_MOD_RST
value|(1<< 4)
comment|/*  * When mask_msi_x =1, no MSI-X from this group is sent. This bit must be set to  * 1 when the associated summary bit in this group is used to generate a single  * MSI-X for this group.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_MASK_MSI_X
value|(1<< 5)
comment|/* MSI-X AWID value. Same ID for all cause bits. */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_AWID_MASK
value|0x00000F00
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_AWID_SHIFT
value|8
comment|/*  * This value determines the interval between interrupts; writing ZERO disables  * Moderation.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_MOD_INTV_MASK
value|0x00FF0000
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_MOD_INTV_SHIFT
value|16
comment|/*  * This value determines the Moderation_Timer_Clock speed.  * 0- Moderation-timer is decremented every 1x256 SB clock cycles ~1uS.  * 1- Moderation-timer is decremented every 2x256 SB clock cycles ~2uS.  * N- Moderation-timer is decremented every Nx256 SB clock cycles ~(N+1) uS.  */
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_MOD_RES_MASK
value|0x0F000000
define|#
directive|define
name|PCIE_W_INTERRUPT_GRP_D_INT_CONTROL_GRP_D_MOD_RES_SHIFT
value|24
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_PCIE_W_REG_H */
end_comment

begin_comment
comment|/** @} end of ... group */
end_comment

end_unit

