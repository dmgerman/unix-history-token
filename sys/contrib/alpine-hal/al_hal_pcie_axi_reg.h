begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_PCIE_HAL_AXI_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_PCIE_HAL_AXI_REG_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_plat_types.h"
end_include

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
name|al_pcie_rev1_2_axi_ctrl
block|{
comment|/* [0x0]  */
name|uint32_t
name|global
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|master_bctl
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|master_rctl
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|master_ctl
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|master_arctl
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|master_awctl
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|slave_rctl
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|slv_wctl
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|slv_ctl
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|dbi_ctl
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|vmid_mask
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_axi_ctrl
block|{
comment|/* [0x0]  */
name|uint32_t
name|global
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|master_bctl
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|master_rctl
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|master_ctl
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|master_arctl
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|master_awctl
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|slave_rctl
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|slv_wctl
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|slv_ctl
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|dbi_ctl
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|vmid_mask
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev1_axi_ob_ctrl
block|{
comment|/* [0x0]  */
name|uint32_t
name|cfg_target_bus
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|cfg_control
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|io_start_l
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|io_start_h
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|io_limit_l
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|io_limit_h
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|msg_start_l
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|msg_start_h
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|msg_limit_l
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|msg_limit_h
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev2_axi_ob_ctrl
block|{
comment|/* [0x0]  */
name|uint32_t
name|cfg_target_bus
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|cfg_control
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|io_start_l
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|io_start_h
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|io_limit_l
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|io_limit_h
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|msg_start_l
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|msg_start_h
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|msg_limit_l
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|msg_limit_h
decl_stmt|;
comment|/* 	 * [0x28] this register override the VMID field in the AXUSER [19:4], 	 * for the AXI master port. 	 */
name|uint32_t
name|vmid_reg_ovrd
decl_stmt|;
comment|/* [0x2c] this register override the ADDR[63:32] AXI master port. */
name|uint32_t
name|addr_high_reg_ovrd_value
decl_stmt|;
comment|/* [0x30] this register override the ADDR[63:32] AXI master port. */
name|uint32_t
name|addr_high_reg_ovrd_sel
decl_stmt|;
comment|/* 	 * [0x34] Define the size to replace in the master axi address bits 	 * [63:32] 	 */
name|uint32_t
name|addr_size_replace
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
name|al_pcie_rev3_axi_ob_ctrl
block|{
comment|/* [0x0]  */
name|uint32_t
name|cfg_target_bus
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|cfg_control
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|io_start_l
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|io_start_h
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|io_limit_l
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|io_limit_h
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|aw_msg_start_l
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|aw_msg_start_h
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|aw_msg_limit_l
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|aw_msg_limit_h
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|ar_msg_start_l
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|ar_msg_start_h
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|ar_msg_limit_l
decl_stmt|;
comment|/* [0x34]  */
name|uint32_t
name|ar_msg_limit_h
decl_stmt|;
comment|/* [0x38]  */
name|uint32_t
name|io_addr_mask_h
decl_stmt|;
comment|/* [0x3c]  */
name|uint32_t
name|ar_msg_addr_mask_h
decl_stmt|;
comment|/* [0x40]  */
name|uint32_t
name|aw_msg_addr_mask_h
decl_stmt|;
comment|/* 	 * [0x44] this register override the VMID field in the AXUSER [19:4], 	 * for the AXI master port. 	 */
name|uint32_t
name|vmid_reg_ovrd
decl_stmt|;
comment|/* [0x48] this register override the ADDR[63:32] AXI master port. */
name|uint32_t
name|addr_high_reg_ovrd_value
decl_stmt|;
comment|/* [0x4c] this register override the ADDR[63:32] AXI master port. */
name|uint32_t
name|addr_high_reg_ovrd_sel
decl_stmt|;
comment|/* 	 * [0x50] Define the size to replace in the master axi address bits 	 * [63:32] 	 */
name|uint32_t
name|addr_size_replace
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
name|al_pcie_revx_axi_msg
block|{
comment|/* [0x0]  */
name|uint32_t
name|addr_high
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|addr_low
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|type
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_pcie_status
block|{
comment|/* [0x0]  */
name|uint32_t
name|debug
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_rd_parity
block|{
comment|/* [0x0]  */
name|uint32_t
name|log_high
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|log_low
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_rd_cmpl
block|{
comment|/* [0x0]  */
name|uint32_t
name|cmpl_log_high
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|cmpl_log_low
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_rd_to
block|{
comment|/* [0x0]  */
name|uint32_t
name|to_log_high
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|to_log_low
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_wr_cmpl
block|{
comment|/* [0x0]  */
name|uint32_t
name|wr_cmpl_log_high
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|wr_cmpl_log_low
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_wr_to
block|{
comment|/* [0x0]  */
name|uint32_t
name|wr_to_log_high
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|wr_to_log_low
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_pcie_global
block|{
comment|/* [0x0]  */
name|uint32_t
name|conf
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev1_2_axi_status
block|{
comment|/* [0x0]  */
name|uint32_t
name|lane0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|lane1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|lane2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|lane3
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_axi_status
block|{
comment|/* [0x0]  */
name|uint32_t
name|lane0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|lane1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|lane2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|lane3
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|lane4
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|lane5
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|lane6
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|lane7
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev1_2_axi_conf
block|{
comment|/* [0x0]  */
name|uint32_t
name|zero_lane0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|zero_lane1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|zero_lane2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|zero_lane3
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|one_lane0
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|one_lane1
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|one_lane2
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|one_lane3
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_axi_conf
block|{
comment|/* [0x0]  */
name|uint32_t
name|zero_lane0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|zero_lane1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|zero_lane2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|zero_lane3
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|zero_lane4
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|zero_lane5
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|zero_lane6
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|zero_lane7
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|one_lane0
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|one_lane1
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|one_lane2
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|one_lane3
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|one_lane4
decl_stmt|;
comment|/* [0x34]  */
name|uint32_t
name|one_lane5
decl_stmt|;
comment|/* [0x38]  */
name|uint32_t
name|one_lane6
decl_stmt|;
comment|/* [0x3c]  */
name|uint32_t
name|one_lane7
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_msg_attr_axuser_table
block|{
comment|/* [0x0] 4 option, the index comes from  */
name|uint32_t
name|entry_vec
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_parity
block|{
comment|/* [0x0]  */
name|uint32_t
name|en_axi
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|status_axi
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_pos_logged
block|{
comment|/* [0x0]  */
name|uint32_t
name|error_low
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|error_high
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_ordering
block|{
comment|/* [0x0]  */
name|uint32_t
name|pos_cntl
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_link_down
block|{
comment|/* [0x0]  */
name|uint32_t
name|reset_extend
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_pre_configuration
block|{
comment|/* [0x0]  */
name|uint32_t
name|pcie_core_setup
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_init_fc
block|{
comment|/* 	 * Revision 1/2: 	 * [0x0] The sum of all the fields below must be 97 	 * Revision 3: 	 * [0x0] The sum of all the fields below must be 259 	 * */
name|uint32_t
name|cfg
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_int_grp_a_axi
block|{
comment|/* 	 * [0x0] Interrupt Cause Register 	 * Set by hardware. 	 * - If MSI-X is enabled, and auto_clear control bit =TRUE, 	 * automatically cleared after MSI-X message associated with this 	 * specific interrupt bit is sent (MSI-X acknowledge is received). 	 * - Software can set a bit in this register by writing 1 to the 	 * associated bit in the Interrupt Cause Set register. 	 * Write-0 clears a bit. Write-1 has no effect. 	 * - On CPU Read -- If clear_on_read control bit =TRUE, automatically 	 * cleared (all bits are cleared). 	 * When there is a conflict, and on the same clock cycle hardware tries 	 * to set a bit in the Interrupt Cause register, the specific bit is set 	 * to ensure the interrupt indication is not lost. 	 */
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
comment|/* 	 * [0x10] Interrupt Mask Register 	 * If Auto-mask control bit =TRUE, automatically set to 1 after MSI-X 	 * message associate to the associate interrupt bit is sent (AXI write 	 * acknowledge is received) 	 */
name|uint32_t
name|mask
decl_stmt|;
name|uint32_t
name|rsrvd_2
decl_stmt|;
comment|/* 	 * [0x18] Interrupt Mask Clear Register 	 * Used when auto-mask control bit=True. It enables the CPU to clear a 	 * specific bit, preventing a scenario in which the CPU overrides 	 * another bit with 1 (old value) that hardware has just cleared to 0. 	 * Writing 0 to this register clears its corresponding mask bit. Write 1 	 * has no effect. 	 */
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
comment|/* 	 * [0x30] Interrupt Mask Register 	 * Each bit in this register masks the corresponding cause bit for 	 * generating an Abort signal. Its default value is determined by unit 	 * instantiation. 	 * Abort = Wire-OR of Cause& !Interrupt_Abort_Mask). 	 * This register provides an error handling configuration for error 	 * interrupts. 	 */
name|uint32_t
name|abort_mask
decl_stmt|;
name|uint32_t
name|rsrvd_6
decl_stmt|;
comment|/* 	 * [0x38] Interrupt Log Register 	 * Each bit in this register masks the corresponding cause bit for 	 * capturing the log registers. Its default value is determined by unit 	 * instantiatio.n 	 * Log_capture = Wire-OR of Cause& !Interrupt_Log_Mask). 	 * This register provides an error handling configuration for error 	 * interrupts. 	 */
name|uint32_t
name|log_mask
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_axi_eq_ovrd_tx_rx_values
block|{
comment|/* [0x0]  */
name|uint32_t
name|cfg_0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|cfg_1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|cfg_2
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|cfg_3
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|cfg_4
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|cfg_5
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|cfg_6
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|cfg_7
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|cfg_8
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|cfg_9
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|cfg_10
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|cfg_11
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_axi_dbg_outstading_trans_axi
block|{
comment|/* [0x0]  */
name|uint32_t
name|read_master_counter
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|write_master_counter
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|read_slave_counter
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_device_id
block|{
comment|/* [0x0] */
name|uint32_t
name|device_rev_id
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_power_mang_ovrd_cntl
block|{
comment|/* [0x0]  */
name|uint32_t
name|cfg_static_nof_elidle
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|cfg_l0s_wait_ovrd
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|cfg_l12_wait_ovrd
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|cfg_l0s_delay_in_p0s
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|cfg_l12_delay_in_p12
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|cfg_l12_delay_in_p12_clk_rst
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|cfg_delay_powerdown_bus
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_axi_dbg_outstading_trans_axi_write
block|{
comment|/* [0x0]  */
name|uint32_t
name|slave_counter
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_rev3_axi_attr_ovrd
block|{
comment|/* 	 * [0x0] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|write_msg_ctrl_0
decl_stmt|;
comment|/* [0x4] in case of message this register set the below attributes  */
name|uint32_t
name|write_msg_ctrl_1
decl_stmt|;
comment|/* 	 * [0x8] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|read_msg_ctrl_0
decl_stmt|;
comment|/* [0xc] in case of message this register set the below attributes  */
name|uint32_t
name|read_msg_ctrl_1
decl_stmt|;
comment|/* [0x10] in case of message this register set the below attributes  */
name|uint32_t
name|pf_sel
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
name|al_pcie_rev3_axi_pf_axi_attr_ovrd
block|{
comment|/* 	 * [0x0] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_0
decl_stmt|;
comment|/* [0x4] in case of message this register set the below attributes  */
name|uint32_t
name|func_ctrl_1
decl_stmt|;
comment|/* 	 * [0x8] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_2
decl_stmt|;
comment|/* 	 * [0xc] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_3
decl_stmt|;
comment|/* 	 * [0x10] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_4
decl_stmt|;
comment|/* 	 * [0x14] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_5
decl_stmt|;
comment|/* 	 * [0x18] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_6
decl_stmt|;
comment|/* 	 * [0x1c] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_7
decl_stmt|;
comment|/* 	 * [0x20] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_8
decl_stmt|;
comment|/* 	 * [0x24] In case of hit on the io message bar and 	 * a*_cfg_outbound_msg_no_snoop_n, the message attributes come from this 	 * register 	 */
name|uint32_t
name|func_ctrl_9
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pcie_revx_axi_regs
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|91
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_device_id
name|device_id
decl_stmt|;
comment|/* [0x16c] */
block|}
struct|;
struct|struct
name|al_pcie_rev1_axi_regs
block|{
name|struct
name|al_pcie_rev1_2_axi_ctrl
name|ctrl
decl_stmt|;
comment|/* [0x0] */
name|struct
name|al_pcie_rev1_axi_ob_ctrl
name|ob_ctrl
decl_stmt|;
comment|/* [0x40] */
name|uint32_t
name|rsrvd_0
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_msg
name|msg
decl_stmt|;
comment|/* [0x90] */
name|struct
name|al_pcie_revx_axi_pcie_status
name|pcie_status
decl_stmt|;
comment|/* [0x9c] */
name|struct
name|al_pcie_revx_axi_rd_parity
name|rd_parity
decl_stmt|;
comment|/* [0xa0] */
name|struct
name|al_pcie_revx_axi_rd_cmpl
name|rd_cmpl
decl_stmt|;
comment|/* [0xa8] */
name|struct
name|al_pcie_revx_axi_rd_to
name|rd_to
decl_stmt|;
comment|/* [0xb0] */
name|struct
name|al_pcie_revx_axi_wr_cmpl
name|wr_cmpl
decl_stmt|;
comment|/* [0xb8] */
name|struct
name|al_pcie_revx_axi_wr_to
name|wr_to
decl_stmt|;
comment|/* [0xc0] */
name|struct
name|al_pcie_revx_axi_pcie_global
name|pcie_global
decl_stmt|;
comment|/* [0xc8] */
name|struct
name|al_pcie_rev1_2_axi_status
name|status
decl_stmt|;
comment|/* [0xcc] */
name|struct
name|al_pcie_rev1_2_axi_conf
name|conf
decl_stmt|;
comment|/* [0xdc] */
name|struct
name|al_pcie_revx_axi_parity
name|parity
decl_stmt|;
comment|/* [0xfc] */
name|struct
name|al_pcie_revx_axi_pos_logged
name|pos_logged
decl_stmt|;
comment|/* [0x104] */
name|struct
name|al_pcie_revx_axi_ordering
name|ordering
decl_stmt|;
comment|/* [0x10c] */
name|struct
name|al_pcie_revx_axi_link_down
name|link_down
decl_stmt|;
comment|/* [0x110] */
name|struct
name|al_pcie_revx_axi_pre_configuration
name|pre_configuration
decl_stmt|;
comment|/* [0x114] */
name|struct
name|al_pcie_revx_axi_init_fc
name|init_fc
decl_stmt|;
comment|/* [0x118] */
name|uint32_t
name|rsrvd_1
index|[
literal|20
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_device_id
name|device_id
decl_stmt|;
comment|/* [0x16c] */
name|uint32_t
name|rsrvd_2
index|[
literal|36
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_int_grp_a_axi
name|int_grp_a
decl_stmt|;
comment|/* [0x200] */
block|}
struct|;
struct|struct
name|al_pcie_rev2_axi_regs
block|{
name|struct
name|al_pcie_rev1_2_axi_ctrl
name|ctrl
decl_stmt|;
comment|/* [0x0] */
name|struct
name|al_pcie_rev2_axi_ob_ctrl
name|ob_ctrl
decl_stmt|;
comment|/* [0x40] */
name|uint32_t
name|rsrvd_0
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_msg
name|msg
decl_stmt|;
comment|/* [0x90] */
name|struct
name|al_pcie_revx_axi_pcie_status
name|pcie_status
decl_stmt|;
comment|/* [0x9c] */
name|struct
name|al_pcie_revx_axi_rd_parity
name|rd_parity
decl_stmt|;
comment|/* [0xa0] */
name|struct
name|al_pcie_revx_axi_rd_cmpl
name|rd_cmpl
decl_stmt|;
comment|/* [0xa8] */
name|struct
name|al_pcie_revx_axi_rd_to
name|rd_to
decl_stmt|;
comment|/* [0xb0] */
name|struct
name|al_pcie_revx_axi_wr_cmpl
name|wr_cmpl
decl_stmt|;
comment|/* [0xb8] */
name|struct
name|al_pcie_revx_axi_wr_to
name|wr_to
decl_stmt|;
comment|/* [0xc0] */
name|struct
name|al_pcie_revx_axi_pcie_global
name|pcie_global
decl_stmt|;
comment|/* [0xc8] */
name|struct
name|al_pcie_rev1_2_axi_status
name|status
decl_stmt|;
comment|/* [0xcc] */
name|struct
name|al_pcie_rev1_2_axi_conf
name|conf
decl_stmt|;
comment|/* [0xdc] */
name|struct
name|al_pcie_revx_axi_parity
name|parity
decl_stmt|;
comment|/* [0xfc] */
name|struct
name|al_pcie_revx_axi_pos_logged
name|pos_logged
decl_stmt|;
comment|/* [0x104] */
name|struct
name|al_pcie_revx_axi_ordering
name|ordering
decl_stmt|;
comment|/* [0x10c] */
name|struct
name|al_pcie_revx_axi_link_down
name|link_down
decl_stmt|;
comment|/* [0x110] */
name|struct
name|al_pcie_revx_axi_pre_configuration
name|pre_configuration
decl_stmt|;
comment|/* [0x114] */
name|struct
name|al_pcie_revx_axi_init_fc
name|init_fc
decl_stmt|;
comment|/* [0x118] */
name|uint32_t
name|rsrvd_1
index|[
literal|20
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_device_id
name|device_id
decl_stmt|;
comment|/* [0x16c] */
name|uint32_t
name|rsrvd_2
index|[
literal|36
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_int_grp_a_axi
name|int_grp_a
decl_stmt|;
comment|/* [0x200] */
block|}
struct|;
struct|struct
name|al_pcie_rev3_axi_regs
block|{
name|struct
name|al_pcie_rev3_axi_ctrl
name|ctrl
decl_stmt|;
comment|/* [0x0] */
name|struct
name|al_pcie_rev3_axi_ob_ctrl
name|ob_ctrl
decl_stmt|;
comment|/* [0x30] */
name|struct
name|al_pcie_revx_axi_msg
name|msg
decl_stmt|;
comment|/* [0x90] */
name|struct
name|al_pcie_revx_axi_pcie_status
name|pcie_status
decl_stmt|;
comment|/* [0x9c] */
name|struct
name|al_pcie_revx_axi_rd_parity
name|rd_parity
decl_stmt|;
comment|/* [0xa0] */
name|struct
name|al_pcie_revx_axi_rd_cmpl
name|rd_cmpl
decl_stmt|;
comment|/* [0xa8] */
name|struct
name|al_pcie_revx_axi_rd_to
name|rd_to
decl_stmt|;
comment|/* [0xb0] */
name|struct
name|al_pcie_revx_axi_wr_cmpl
name|wr_cmpl
decl_stmt|;
comment|/* [0xb8] */
name|struct
name|al_pcie_revx_axi_wr_to
name|wr_to
decl_stmt|;
comment|/* [0xc0] */
name|struct
name|al_pcie_revx_axi_pcie_global
name|pcie_global
decl_stmt|;
comment|/* [0xc8] */
name|uint32_t
name|rsrvd_0
decl_stmt|;
name|struct
name|al_pcie_revx_axi_parity
name|parity
decl_stmt|;
comment|/* [0xd0] */
name|struct
name|al_pcie_revx_axi_pos_logged
name|pos_logged
decl_stmt|;
comment|/* [0xd8] */
name|struct
name|al_pcie_revx_axi_ordering
name|ordering
decl_stmt|;
comment|/* [0xe0] */
name|struct
name|al_pcie_revx_axi_link_down
name|link_down
decl_stmt|;
comment|/* [0xe4] */
name|struct
name|al_pcie_revx_axi_pre_configuration
name|pre_configuration
decl_stmt|;
comment|/* [0xe8] */
name|struct
name|al_pcie_revx_axi_init_fc
name|init_fc
decl_stmt|;
comment|/* [0xec] */
name|uint32_t
name|rsrvd_1
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|al_pcie_rev3_axi_eq_ovrd_tx_rx_values
name|eq_ovrd_tx_rx_values
decl_stmt|;
comment|/* [0x100] */
name|struct
name|al_pcie_rev3_axi_dbg_outstading_trans_axi
name|dbg_outstading_trans_axi
decl_stmt|;
comment|/* [0x160] */
name|struct
name|al_pcie_revx_axi_device_id
name|device_id
decl_stmt|;
comment|/* [0x16c] */
name|struct
name|al_pcie_revx_axi_power_mang_ovrd_cntl
name|power_mang_ovrd_cntl
decl_stmt|;
comment|/* [0x170] */
name|struct
name|al_pcie_rev3_axi_dbg_outstading_trans_axi_write
name|dbg_outstading_trans_axi_write
decl_stmt|;
comment|/* [0x190] */
name|uint32_t
name|rsrvd_2
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|al_pcie_rev3_axi_attr_ovrd
name|axi_attr_ovrd
decl_stmt|;
comment|/* [0x1a0] */
name|struct
name|al_pcie_rev3_axi_pf_axi_attr_ovrd
name|pf_axi_attr_ovrd
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
comment|/* [0x1c0] */
name|uint32_t
name|rsrvd_3
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|al_pcie_rev3_axi_status
name|status
decl_stmt|;
comment|/* [0x3c0] */
name|struct
name|al_pcie_rev3_axi_conf
name|conf
decl_stmt|;
comment|/* [0x400] */
name|uint32_t
name|rsrvd_4
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_msg_attr_axuser_table
name|msg_attr_axuser_table
decl_stmt|;
comment|/* [0x500] */
name|uint32_t
name|rsrvd_5
index|[
literal|191
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_axi_int_grp_a_axi
name|int_grp_a
decl_stmt|;
comment|/* [0x800] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** Device ID register ****/
define|#
directive|define
name|PCIE_AXI_DEVICE_ID_REG_DEV_ID_MASK
value|AL_FIELD_MASK(31, 16)
define|#
directive|define
name|PCIE_AXI_DEVICE_ID_REG_DEV_ID_SHIFT
value|16
define|#
directive|define
name|PCIE_AXI_DEVICE_ID_REG_DEV_ID_X4
value|(0<< PCIE_AXI_DEVICE_ID_REG_DEV_ID_SHIFT)
define|#
directive|define
name|PCIE_AXI_DEVICE_ID_REG_DEV_ID_X8
value|(2<< PCIE_AXI_DEVICE_ID_REG_DEV_ID_SHIFT)
define|#
directive|define
name|PCIE_AXI_DEVICE_ID_REG_REV_ID_MASK
value|AL_FIELD_MASK(15, 0)
define|#
directive|define
name|PCIE_AXI_DEVICE_ID_REG_REV_ID_SHIFT
value|0
comment|/**** Global register ****/
comment|/*  * Not in use.  * Disable completion after inbound posted ordering enforcement to AXI bridge.  */
define|#
directive|define
name|PCIE_AXI_CTRL_GLOBAL_CPL_AFTER_P_ORDER_DIS
value|(1<< 0)
comment|/*  * Not in use.  * Enforce completion after write ordering on AXI bridge. Only for CPU read  * requests.  */
define|#
directive|define
name|PCIE_AXI_CTRL_GLOBAL_CPU_CPL_ONLY_EN
value|(1<< 1)
comment|/* When linked down, map all transactions to PCIe to DEC ERR. */
define|#
directive|define
name|PCIE_AXI_CTRL_GLOBAL_BLOCK_PCIE_SLAVE_EN
value|(1<< 2)
comment|/*  * Wait for the NIC to flush before enabling reset to the PCIe core, on a link  * down event.  */
define|#
directive|define
name|PCIE_AXI_CTRL_GLOBAL_WAIT_SLV_FLUSH_EN
value|(1<< 3)
comment|/*  * When the BME is cleared and this bit is set, it causes all transactions that  * do not get to the PCIe to be returned with DECERR.  */
define|#
directive|define
name|PCIE_REV1_2_AXI_CTRL_GLOBAL_MEM_BAR_MAP_TO_ERR
value|(1<< 4)
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_MEM_BAR_MAP_TO_ERR_MASK
value|0x00000FF0
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_MEM_BAR_MAP_TO_ERR_SHIFT
value|4
comment|/*  * Wait for the DBI port (the port that enables access to the internal PCIe core  * registers) to flush before enabling reset to the PCIe core on link down  * event.  */
define|#
directive|define
name|PCIE_REV1_2_AXI_CTRL_GLOBAL_WAIT_DBI_FLUSH_EN
value|(1<< 5)
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_WAIT_DBI_FLUSH_EN
value|(1<< 12)
comment|/* Reserved. Read undefined; must read as zeros. */
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_CFG_FLUSH_DBI_AXI
value|(1<< 13)
comment|/* Reserved. Read undefined; must read as zeros. */
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_CFG_HOLD_LNKDWN_RESET_SW
value|(1<< 14)
comment|/* Reserved. Read undefined; must read as zeros. */
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_CFG_MASK_CORECLK_ACT_CLK_RST
value|(1<< 15)
comment|/* Reserved. Read undefined; must read as zeros. */
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_CFG_MASK_RXELECIDLE_CLK_RST
value|(1<< 16)
comment|/* Reserved. Read undefined; must read as zeros. */
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_CFG_ALLOW_NONSTICKY_RESET_WHEN_LNKDOWN_CLK_RST
value|(1<< 17)
comment|/*  * When set, adds parity on the write and read address channels, and write data  * channel.  */
define|#
directive|define
name|PCIE_REV1_2_AXI_CTRL_GLOBAL_PARITY_CALC_EN_MSTR
value|(1<< 16)
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_PARITY_CALC_EN_MSTR
value|(1<< 18)
comment|/* When set, enables parity check on the read data. */
define|#
directive|define
name|PCIE_REV1_2_AXI_CTRL_GLOBAL_PARITY_ERR_EN_RD
value|(1<< 17)
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_PARITY_ERR_EN_RD
value|(1<< 19)
comment|/*  * When set, adds parity on the RD data channel.  */
define|#
directive|define
name|PCIE_REV1_2_AXI_CTRL_GLOBAL_PARITY_CALC_EN_SLV
value|(1<< 18)
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_PARITY_CALC_EN_SLV
value|(1<< 20)
comment|/*  * When set, enables parity check on the write data.  */
define|#
directive|define
name|PCIE_REV1_2_AXI_CTRL_GLOBAL_PARITY_ERR_EN_WR
value|(1<< 19)
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_PARITY_ERR_EN_WR
value|(1<< 21)
comment|/*  * When set, error track for timeout and parity is disabled, i.e., the logged  * address for parity/timeout/cmpl errors on the AXI master port is not valid,  * and timeout and completion errors check are disabled.  */
define|#
directive|define
name|PCIE_REV1_2_AXI_CTRL_GLOBAL_ERROR_TRACK_DIS
value|(1<< 20)
define|#
directive|define
name|PCIE_REV3_AXI_CTRL_GLOBAL_ERROR_TRACK_DIS
value|(1<< 22)
comment|/**** Master_Arctl register ****/
comment|/* override arcache */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_OVR_ARCACHE
value|(1<< 0)
comment|/* arache value */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_ARACHE_VA_MASK
value|0x0000001E
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_ARACHE_VA_SHIFT
value|1
comment|/* arprot override */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_ARPROT_OVR
value|(1<< 5)
comment|/* arprot value */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_ARPROT_VALUE_MASK
value|0x000001C0
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_ARPROT_VALUE_SHIFT
value|6
comment|/* vmid val */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_VMID_VAL_MASK
value|0x01FFFE00
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_VMID_VAL_SHIFT
value|9
comment|/* IPA value */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_IPA_VAL
value|(1<< 25)
comment|/* overide snoop inidcation, if not set take it from mstr_armisc ... */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_OVR_SNOOP
value|(1<< 26)
comment|/* snoop indication value when override */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_SNOOP
value|(1<< 27)
comment|/* arqos value */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_ARQOS_MASK
value|0xF0000000
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_ARCTL_ARQOS_SHIFT
value|28
comment|/**** Master_Awctl register ****/
comment|/* override arcache */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_OVR_ARCACHE
value|(1<< 0)
comment|/* awache value */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_AWACHE_VA_MASK
value|0x0000001E
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_AWACHE_VA_SHIFT
value|1
comment|/* awprot override */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_AWPROT_OVR
value|(1<< 5)
comment|/* awprot value */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_AWPROT_VALUE_MASK
value|0x000001C0
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_AWPROT_VALUE_SHIFT
value|6
comment|/* vmid val */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_VMID_VAL_MASK
value|0x01FFFE00
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_VMID_VAL_SHIFT
value|9
comment|/* IPA value */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_IPA_VAL
value|(1<< 25)
comment|/* overide snoop inidcation, if not set take it from mstr_armisc ... */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_OVR_SNOOP
value|(1<< 26)
comment|/* snoop indication value when override */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_SNOOP
value|(1<< 27)
comment|/* awqos value */
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_AWQOS_MASK
value|0xF0000000
define|#
directive|define
name|PCIE_AXI_CTRL_MASTER_AWCTL_AWQOS_SHIFT
value|28
comment|/**** slv_ctl register ****/
define|#
directive|define
name|PCIE_AXI_CTRL_SLV_CTRL_IO_BAR_EN
value|(1<< 6)
comment|/**** Cfg_Target_Bus register ****/
comment|/*  * Defines which MSBs to complete the number of the bust that arrived from ECAM.  * If set to 0, take the bit from the ECAM bar, otherwise from the busnum of  * this register.  * The LSB for the bus number comes on the addr[*:20].  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_TARGET_BUS_MASK_MASK
value|0x000000FF
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_TARGET_BUS_MASK_SHIFT
value|0
comment|/* Target bus number for outbound configuration type0 and type1 access */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_TARGET_BUS_BUSNUM_MASK
value|0x0000FF00
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_TARGET_BUS_BUSNUM_SHIFT
value|8
comment|/**** Cfg_Control register ****/
comment|/* Primary bus number */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_CONTROL_PBUS_MASK
value|0x000000FF
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_CONTROL_PBUS_SHIFT
value|0
comment|/*  *  * Subordinate bus number  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_CONTROL_SUBBUS_MASK
value|0x0000FF00
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_CONTROL_SUBBUS_SHIFT
value|8
comment|/* Secondary bus nnumber */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_CONTROL_SEC_BUS_MASK
value|0x00FF0000
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_CONTROL_SEC_BUS_SHIFT
value|16
comment|/* Enable outbound configuration access through iATU.  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_CFG_CONTROL_IATU_EN
value|(1<< 31)
comment|/**** IO_Start_H register ****/
comment|/*  *  * Outbound ATIU I/O start address high  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_IO_START_H_ADDR_MASK
value|0x000003FF
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_IO_START_H_ADDR_SHIFT
value|0
comment|/**** IO_Limit_H register ****/
comment|/*  *  * Outbound ATIU I/O limit address high  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_IO_LIMIT_H_ADDR_MASK
value|0x000003FF
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_IO_LIMIT_H_ADDR_SHIFT
value|0
comment|/**** Msg_Start_H register ****/
comment|/*  *  * Outbound ATIU msg-no-data start address high  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_MSG_START_H_ADDR_MASK
value|0x000003FF
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_MSG_START_H_ADDR_SHIFT
value|0
comment|/**** Msg_Limit_H register ****/
comment|/*  *  * Outbound ATIU msg-no-data limit address high  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_MSG_LIMIT_H_ADDR_MASK
value|0x000003FF
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_MSG_LIMIT_H_ADDR_SHIFT
value|0
comment|/**** vmid_reg_ovrd register ****/
comment|/*  * select if to take the value from register or from address[63:48]:  * 1'b1: register value.  * 1'b0: from address[63:48]  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_VMID_REG_OVRD_SEL_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_VMID_REG_OVRD_SEL_SHIFT
value|0
comment|/* vmid override value. */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_VMID_REG_OVRD_VALUE_MASK
value|0xFFFF0000
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_VMID_REG_OVRD_VALUE_SHIFT
value|16
comment|/**** addr_size_replace register ****/
comment|/*  * Size in bits to replace from bit [63:64-N], when equal zero no replace is  * done.  */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_ADDR_SIZE_REPLACE_VALUE_MASK
value|0x0000FFFF
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_ADDR_SIZE_REPLACE_VALUE_SHIFT
value|0
comment|/* Reserved. */
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_ADDR_SIZE_REPLACE_RSRVD_MASK
value|0xFFFF0000
define|#
directive|define
name|PCIE_AXI_MISC_OB_CTRL_ADDR_SIZE_REPLACE_RSRVD_SHIFT
value|16
comment|/**** type register ****/
comment|/* Type of message */
define|#
directive|define
name|PCIE_AXI_MISC_MSG_TYPE_TYPE_MASK
value|0x00FFFFFF
define|#
directive|define
name|PCIE_AXI_MISC_MSG_TYPE_TYPE_SHIFT
value|0
comment|/* Reserved */
define|#
directive|define
name|PCIE_AXI_MISC_MSG_TYPE_RSRVD_MASK
value|0xFF000000
define|#
directive|define
name|PCIE_AXI_MISC_MSG_TYPE_RSRVD_SHIFT
value|24
comment|/**** debug register ****/
comment|/* Causes ACI PCIe reset, including ,master/slave/DBI (registers). */
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_STATUS_DEBUG_AXI_BRIDGE_RESET
value|(1<< 0)
comment|/*  * Causes reset of the entire PCIe core (including the AXI bridge).  * When set, the software must not address the PCI core (through the MEM space  * and REG space).  */
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_STATUS_DEBUG_CORE_RESET
value|(1<< 1)
comment|/*  * Indicates that the SB is empty from the request to the PCIe (not including  * registers).  */
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_STATUS_DEBUG_SB_FLUSH_OB_STATUS
value|(1<< 2)
comment|/* MAP and transaction to the PCIe core to ERROR. */
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_STATUS_DEBUG_SB_MAP_TO_ERR
value|(1<< 3)
comment|/* Indicates that the pcie_core clock is gated off */
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_STATUS_DEBUG_CORE_CLK_GATE_OFF
value|(1<< 4)
comment|/* Reserved */
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_STATUS_DEBUG_RSRVD_MASK
value|0xFFFFFFE0
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_STATUS_DEBUG_RSRVD_SHIFT
value|5
comment|/**** conf register ****/
comment|/*  * Device Type  * Indicates the specific type of this PCI Express Function. It is also used to  * set the  * Device/Port Type field.  *  * 4'b0000: PCI Express Endpoint  * 4'b0001: Legacy PCI Express Endpoint  * 4'b0100: Root Port of PCI Express Root Complex  *  * Must be programmed before link training sequence, according to the reset  * strap.  * Change this register should be when the pci_exist (in the PBS regfile) is  * zero.  */
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_GLOBAL_CONF_DEV_TYPE_MASK
value|0x0000000F
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_GLOBAL_CONF_DEV_TYPE_SHIFT
value|0
comment|/*  * [i] - Lane i active  * Change this register should be when the pci_exist (in the PBS regfile) is  * zero.  */
define|#
directive|define
name|PCIE_REV1_2_AXI_MISC_PCIE_GLOBAL_CONF_NOF_ACT_LANES_MASK
value|0x000000F0
define|#
directive|define
name|PCIE_REV1_2_AXI_MISC_PCIE_GLOBAL_CONF_RESERVED_MASK
value|0xFFFFFF00
define|#
directive|define
name|PCIE_REV1_2_AXI_MISC_PCIE_GLOBAL_CONF_RESERVED_SHIFT
value|8
define|#
directive|define
name|PCIE_REVX_AXI_MISC_PCIE_GLOBAL_CONF_NOF_ACT_LANES_SHIFT
value|4
define|#
directive|define
name|PCIE_REV3_AXI_MISC_PCIE_GLOBAL_CONF_NOF_ACT_LANES_MASK
value|0x000FFFF0
define|#
directive|define
name|PCIE_REV3_AXI_MISC_PCIE_GLOBAL_CONF_RESERVED_MASK
value|0xFFF00000
define|#
directive|define
name|PCIE_REV3_AXI_MISC_PCIE_GLOBAL_CONF_RESERVED_SHIFT
value|20
define|#
directive|define
name|PCIE_REV1_2_AXI_MISC_PCIE_GLOBAL_CONF_MEM_SHUTDOWN
value|0x100
define|#
directive|define
name|PCIE_REV3_AXI_MISC_PCIE_GLOBAL_CONF_MEM_SHUTDOWN
value|0x100000
comment|/**** laneX register ****/
define|#
directive|define
name|PCIE_AXI_STATUS_LANE_IS_RESET
value|AL_BIT(13)
define|#
directive|define
name|PCIE_AXI_STATUS_LANE_REQUESTED_SPEED_MASK
value|AL_FIELD_MASK(2, 0)
define|#
directive|define
name|PCIE_AXI_STATUS_LANE_REQUESTED_SPEED_SHIFT
value|0
comment|/**** zero_laneX register ****/
comment|/* phy_mac_local_fs */
define|#
directive|define
name|PCIE_AXI_MISC_ZERO_LANEX_PHY_MAC_LOCAL_FS_MASK
value|0x0000003f
define|#
directive|define
name|PCIE_AXI_MISC_ZERO_LANEX_PHY_MAC_LOCAL_FS_SHIFT
value|0
comment|/* phy_mac_local_lf */
define|#
directive|define
name|PCIE_AXI_MISC_ZERO_LANEX_PHY_MAC_LOCAL_LF_MASK
value|0x00000fc0
define|#
directive|define
name|PCIE_AXI_MISC_ZERO_LANEX_PHY_MAC_LOCAL_LF_SHIFT
value|6
comment|/**** en_axi register ****/
comment|/* u4_ram2p */
define|#
directive|define
name|PCIE_AXI_PARITY_EN_AXI_U4_RAM2P
value|AL_BIT(1)
comment|/**** pos_cntl register ****/
comment|/* Disables POS. */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_AXI_POS_BYPASS
value|(1<< 0)
comment|/* Clear the POS data structure. */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_AXI_POS_CLEAR
value|(1<< 1)
comment|/* Read push all write. */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_AXI_POS_RSO_ENABLE
value|(1<< 2)
comment|/*  * Causes the PCIe core to wait for all the BRESPs before issuing a read  * request.  */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_AXI_DW_RD_FLUSH_WR
value|(1<< 3)
comment|/*  * When set, to 1'b1 supports interleaving data return from the PCIe core. Valid  * only when cfg_bypass_cmpl_after_write_fix is set.  */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_RD_CMPL_AFTER_WR_SUPPORT_RD_INTERLV
value|(1<< 4)
comment|/* When set, to 1'b1 disables read completion after write ordering. */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_BYPASS_CMPL_AFTER_WR_FIX
value|(1<< 5)
comment|/*  * When set, disables EP mode read cmpl on the master port push slave writes,  * when each read response from the master is not interleaved.  */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_EP_CMPL_AFTER_WR_DIS
value|(1<< 6)
comment|/* When set, disables EP mode read cmpl on the master port push slave writes. */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_EP_CMPL_AFTER_WR_SUPPORT_INTERLV_DIS
value|(1<< 7)
comment|/* should be zero */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_9_8
value|AL_FIELD_MASK(9, 8)
comment|/* Give the segmentation buffer not to wait for P writes to end in the AXI  * bridge before releasing the CMPL.  */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_SEGMENT_BUFFER_DONT_WAIT_FOR_P_WRITES
value|AL_BIT(10)
comment|/* should be zero */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_11
value|AL_BIT(11)
comment|/**  * When set cause pcie core to send ready in the middle of the read data  * burst returning from the DRAM to the PCIe core  */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_SEND_READY_ON_READ_DATA_BURST
value|AL_BIT(12)
comment|/* When set disable the ATS CAP.  */
define|#
directive|define
name|PCIE_AXI_CORE_SETUP_ATS_CAP_DIS
value|AL_BIT(13)
comment|/* When set disable D3/D2/D1 PME support */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_DISABLE_DX_PME
value|AL_BIT(14)
comment|/* When set enable nonsticky reset when linkdown hot reset */
define|#
directive|define
name|PCIE_AXI_POS_ORDER_ENABLE_NONSTICKY_RESET_ON_HOT_RESET
value|AL_BIT(15)
comment|/* When set, terminate message with data as UR request */
define|#
directive|define
name|PCIE_AXI_TERMINATE_DATA_MSG_AS_UR_REQ
value|AL_BIT(16)
comment|/**** pcie_core_setup register ****/
comment|/*  * This Value delay the rate change to the serdes, until the EIOS is sent by the  * serdes. Should be program before the pcie_exist, is asserted.  */
define|#
directive|define
name|PCIE_AXI_CORE_SETUP_DELAY_MAC_PHY_RATE_MASK
value|0x000000FF
define|#
directive|define
name|PCIE_AXI_CORE_SETUP_DELAY_MAC_PHY_RATE_SHIFT
value|0
comment|/*  * Limit the number of outstanding AXI reads that the PCIe core can get. Should  * be program before the pcie_exist, is asserted.  */
define|#
directive|define
name|PCIE_AXI_CORE_SETUP_NOF_READS_ONSLAVE_INTRF_PCIE_CORE_MASK
value|0x0000FF00
define|#
directive|define
name|PCIE_AXI_CORE_SETUP_NOF_READS_ONSLAVE_INTRF_PCIE_CORE_SHIFT
value|8
comment|/* Enable the sriov feature. */
define|#
directive|define
name|PCIE_AXI_REV1_2_CORE_SETUP_SRIOV_ENABLE
value|AL_BIT(16)
comment|/* not in use */
define|#
directive|define
name|PCIE_AXI_REV3_CORE_SETUP_NOT_IN_USE
value|(1<< 16)
comment|/* Reserved. Read undefined; must read as zeros. */
define|#
directive|define
name|PCIE_AXI_REV3_CORE_SETUP_CFG_DELAY_AFTER_PCIE_EXIST_MASK
value|0x0FFE0000
define|#
directive|define
name|PCIE_AXI_REV3_CORE_SETUP_CFG_DELAY_AFTER_PCIE_EXIST_SHIFT
value|17
comment|/**** cfg register ****/
comment|/* This value set the possible out standing headers writes (post ... */
define|#
directive|define
name|PCIE_AXI_REV1_2_INIT_FC_CFG_NOF_P_HDR_MASK
value|0x0000007F
define|#
directive|define
name|PCIE_AXI_REV1_2_INIT_FC_CFG_NOF_P_HDR_SHIFT
value|0
comment|/* This value set the possible out standing headers reads (non-p ... */
define|#
directive|define
name|PCIE_AXI_REV1_2_INIT_FC_CFG_NOF_NP_HDR_MASK
value|0x00003F80
define|#
directive|define
name|PCIE_AXI_REV1_2_INIT_FC_CFG_NOF_NP_HDR_SHIFT
value|7
comment|/* This value set the possible out standing headers CMPLs , the  ... */
define|#
directive|define
name|PCIE_AXI_REV1_2_INIT_FC_CFG_NOF_CPL_HDR_MASK
value|0x001FC000
define|#
directive|define
name|PCIE_AXI_REV1_2_INIT_FC_CFG_NOF_CPL_HDR_SHIFT
value|14
define|#
directive|define
name|PCIE_AXI_REV1_2_INIT_FC_CFG_RSRVD_MASK
value|0xFFE00000
define|#
directive|define
name|PCIE_AXI_REV1_2_INIT_FC_CFG_RSRVD_SHIFT
value|21
comment|/* This value set the possible out standing headers writes (post ... */
define|#
directive|define
name|PCIE_AXI_REV3_INIT_FC_CFG_NOF_P_HDR_MASK
value|0x000001FF
define|#
directive|define
name|PCIE_AXI_REV3_INIT_FC_CFG_NOF_P_HDR_SHIFT
value|0
comment|/* This value set the possible out standing headers reads (non-p ... */
define|#
directive|define
name|PCIE_AXI_REV3_INIT_FC_CFG_NOF_NP_HDR_MASK
value|0x0003FE00
define|#
directive|define
name|PCIE_AXI_REV3_INIT_FC_CFG_NOF_NP_HDR_SHIFT
value|9
comment|/* This value set the possible out standing headers CMPLs , the  ... */
define|#
directive|define
name|PCIE_AXI_REV3_INIT_FC_CFG_NOF_CPL_HDR_MASK
value|0x07FC0000
define|#
directive|define
name|PCIE_AXI_REV3_INIT_FC_CFG_NOF_CPL_HDR_SHIFT
value|18
comment|/*  * [27] cfg_cpl_p_rr: do round robin on the SB output btw Posted and CPL.  * [28] cfg_np_pass_p_rr, in case RR between CPL AND P, allow to pass NP in case  * p is empty.  * [29] cfg_np_part_of_rr_arb: NP also is a part of the round robin arbiter.  */
define|#
directive|define
name|PCIE_AXI_REV3_INIT_FC_CFG_RSRVD_MASK
value|0xF8000000
define|#
directive|define
name|PCIE_AXI_REV3_INIT_FC_CFG_RSRVD_SHIFT
value|27
comment|/**** write_msg_ctrl_0 register ****/
comment|/*  * choose if 17 in the AXUSER indicate message hint (1'b1) or no snoop  * indication (1'b0)  */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_OUTBOUND_MSG_NO_SNOOP_N
value|(1<< 0)
comment|/* this bit define if the message is with data or without  */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_WITH_DATA
value|(1<< 1)
comment|/* message code for message with data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_CODE_DATA_MASK
value|0x000003FC
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_CODE_DATA_SHIFT
value|2
comment|/* message code for message without data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_CODE_MASK
value|0x0003FC00
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_CODE_SHIFT
value|10
comment|/* message ST value */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_ST_MASK
value|0x03FC0000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_ST_SHIFT
value|18
comment|/* message NO-SNOOP */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_NO_SNOOP
value|(1<< 26)
comment|/* message TH bit */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_TH
value|(1<< 27)
comment|/* message PH bits */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_PH_MASK
value|0x30000000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_AW_CFG_MSG_PH_SHIFT
value|28
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_RSRVD_MASK
value|0xC0000000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_0_RSRVD_SHIFT
value|30
comment|/**** write_msg_ctrl_1 register ****/
comment|/* message type */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MISC_MSG_TYPE_VALUE_MASK
value|0x0000001F
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MISC_MSG_TYPE_VALUE_SHIFT
value|0
comment|/* this bit define if the message is with data or without  */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MSG_DATA_TYPE_VALUE_MASK
value|0x000003E0
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MSG_DATA_TYPE_VALUE_SHIFT
value|5
comment|/* override axi size for message with no data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MSG_NO_DATA_AXI_SIZE_OVRD
value|(1<< 10)
comment|/* override the AXI size to the pcie core for message with no data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MSG_NO_DATA_AXI_SIZE_MSG_MASK
value|0x00003800
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MSG_NO_DATA_AXI_SIZE_MSG_SHIFT
value|11
comment|/* override axi size for message with data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MSG_DATA_AXI_SIZE_OVRD
value|(1<< 14)
comment|/* override the AXI size to the pcie core for message with data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MSG_DATA_AXI_SIZE_MSG_MASK
value|0x00038000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_AW_CFG_MSG_DATA_AXI_SIZE_MSG_SHIFT
value|15
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_RSRVD_MASK
value|0xFFFC0000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_WR_MSG_CTRL_1_RSRVD_SHIFT
value|18
comment|/**** read_msg_ctrl_0 register ****/
comment|/*  * choose if 17 in the AXUSER indicate message hint (1'b1) or no snoop  * indication (1'b0)  */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_OUTBOUND_MSG_NO_SNOOP_N
value|(1<< 0)
comment|/* this bit define if the message is with data or without  */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_WITH_DATA
value|(1<< 1)
comment|/* message code for message with data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_CODE_DATA_MASK
value|0x000003FC
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_CODE_DATA_SHIFT
value|2
comment|/* message code for message without data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_CODE_MASK
value|0x0003FC00
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_CODE_SHIFT
value|10
comment|/* message ST value */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_ST_MASK
value|0x03FC0000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_ST_SHIFT
value|18
comment|/* message NO-SNOOP */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_NO_SNOOP
value|(1<< 26)
comment|/* message TH bit */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_TH
value|(1<< 27)
comment|/* message PH bits */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_PH_MASK
value|0x30000000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_AR_CFG_MSG_PH_SHIFT
value|28
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_RSRVD_MASK
value|0xC0000000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_0_RSRVD_SHIFT
value|30
comment|/**** read_msg_ctrl_1 register ****/
comment|/* message type */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MISC_MSG_TYPE_VALUE_MASK
value|0x0000001F
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MISC_MSG_TYPE_VALUE_SHIFT
value|0
comment|/* this bit define if the message is with data or without  */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MSG_DATA_TYPE_VALUE_MASK
value|0x000003E0
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MSG_DATA_TYPE_VALUE_SHIFT
value|5
comment|/* override axi size for message with no data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MSG_NO_DATA_AXI_SIZE_OVRD
value|(1<< 10)
comment|/* override the AXI size to the pcie core for message with no data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MSG_NO_DATA_AXI_SIZE_MSG_MASK
value|0x00003800
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MSG_NO_DATA_AXI_SIZE_MSG_SHIFT
value|11
comment|/* override axi size for message with data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MSG_DATA_AXI_SIZE_OVRD
value|(1<< 14)
comment|/* override the AXI size to the pcie core for message with data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MSG_DATA_AXI_SIZE_MSG_MASK
value|0x00038000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_AR_CFG_MSG_DATA_AXI_SIZE_MSG_SHIFT
value|15
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_RSRVD_MASK
value|0xFFFC0000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_READ_MSG_CTRL_1_RSRVD_SHIFT
value|18
comment|/**** pf_sel register ****/
comment|/* message type */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_PF_BIT0_OVRD_FROM_AXUSER
value|(1<< 0)
comment|/* this bit define if the message is with data or without  */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_PF_BIT0_OVRD_FROM_REG
value|(1<< 1)
comment|/* override axi size for message with no data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_PF_BIT0_ADDR_OFFSET_MASK
value|0x0000003C
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_PF_BIT0_ADDR_OFFSET_SHIFT
value|2
comment|/* override the AXI size to the pcie core for message with no data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_CFG_PF_BIT0_OVRD
value|(1<< 6)
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_RSRVD_7
value|(1<< 7)
comment|/* message type */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_PF_BIT1_OVRD_FROM_AXUSER
value|(1<< 8)
comment|/* this bit define if the message is with data or without  */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_PF_BIT1_OVRD_FROM_REG
value|(1<< 9)
comment|/* override axi size for message with no data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_PF_BIT1_ADDR_OFFSET_MASK
value|0x00003C00
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_PF_BIT1_ADDR_OFFSET_SHIFT
value|10
comment|/* override the AXI size to the pcie core for message with no data. */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_CFG_PF_BIT1_OVRD
value|(1<< 14)
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_RSRVD_MASK
value|0xFFFF8000
define|#
directive|define
name|PCIE_AXI_AXI_ATTR_OVRD_PF_SEL_RSRVD_SHIFT
value|15
comment|/**** func_ctrl_0 register ****/
comment|/* choose the field  from the axuser */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_PF_VEC_TH_OVRD_FROM_AXUSER
value|(1<< 0)
comment|/* choose the field  from register */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_PF_VEC_TH_OVRD_FROM_REG
value|(1<< 1)
comment|/* field offset from the address portions according to the spec */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_PF_VEC_TH_ADDR_OFFSET_MASK
value|0x0000003C
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_PF_VEC_TH_ADDR_OFFSET_SHIFT
value|2
comment|/* register value override */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_CFG_TH_OVRD
value|(1<< 6)
comment|/* choose the field  from the axuser */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_PF_VEC_ST_VEC_OVRD_FROM_AXUSER_MASK
value|0x00007F80
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_PF_VEC_ST_VEC_OVRD_FROM_AXUSER_SHIFT
value|7
comment|/* choose the field  from register */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_PF_VEC_ST_VEC_OVRD_FROM_REG_MASK
value|0x007F8000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_PF_VEC_ST_VEC_OVRD_FROM_REG_SHIFT
value|15
comment|/* register value override */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_CFG_ST_VEC_OVRD_MASK
value|0x7F800000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_CFG_ST_VEC_OVRD_SHIFT
value|23
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_0_RSRVD
value|(1<< 31)
comment|/**** func_ctrl_2 register ****/
comment|/* choose the field  from the axuser */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_PH_VEC_OVRD_FROM_AXUSER_MASK
value|0x00000003
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_PH_VEC_OVRD_FROM_AXUSER_SHIFT
value|0
comment|/* choose the field  from register */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_PH_VEC_OVRD_FROM_REG_MASK
value|0x0000000C
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_PH_VEC_OVRD_FROM_REG_SHIFT
value|2
comment|/* in case the field take from the address, offset field for each bit. */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_PH_VEC_ADDR_OFFSET_MASK
value|0x00000FF0
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_PH_VEC_ADDR_OFFSET_SHIFT
value|4
comment|/* register value override */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_CFG_PH_VEC_OVRD_MASK
value|0x00003000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_CFG_PH_VEC_OVRD_SHIFT
value|12
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_RSRVD_14_15_MASK
value|0x0000C000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_RSRVD_14_15_SHIFT
value|14
comment|/* choose the field  from the axuser */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_VMID89_VEC_OVRD_FROM_AXUSER_MASK
value|0x00030000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_VMID89_VEC_OVRD_FROM_AXUSER_SHIFT
value|16
comment|/* choose the field  from register */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_VMID89_VEC_OVRD_FROM_REG_MASK
value|0x000C0000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_VMID89_VEC_OVRD_FROM_REG_SHIFT
value|18
comment|/* in case the field take from the address, offset field for each bit. */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_VMID89_VEC_ADDR_OFFSET_MASK
value|0x0FF00000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_PF_VEC_VMID89_VEC_ADDR_OFFSET_SHIFT
value|20
comment|/* register value override */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_CFG_VMID89_VEC_OVRD_MASK
value|0x30000000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_CFG_VMID89_VEC_OVRD_SHIFT
value|28
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_RSRVD_MASK
value|0xC0000000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_2_RSRVD_SHIFT
value|30
comment|/**** func_ctrl_3 register ****/
comment|/*  * When set take the corresponding bit address from register  * pf_vec_mem_addr44_53_ovrd  */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_3_PF_VEC_MEM_ADDR44_53_SEL_MASK
value|0x000003FF
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_3_PF_VEC_MEM_ADDR44_53_SEL_SHIFT
value|0
comment|/* override value. */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_3_PF_VEC_MEM_ADDR44_53_OVRD_MASK
value|0x000FFC00
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_3_PF_VEC_MEM_ADDR44_53_OVRD_SHIFT
value|10
comment|/*  * When set take the corresponding bit address from register  * pf_vec_mem_addr54_63_ovrd  */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_3_PF_VEC_MEM_ADDR54_63_SEL_MASK
value|0x3FF00000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_3_PF_VEC_MEM_ADDR54_63_SEL_SHIFT
value|20
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_3_RSRVD_MASK
value|0xC0000000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_3_RSRVD_SHIFT
value|30
comment|/**** func_ctrl_4 register ****/
comment|/* When set take the corresponding bit address from vmid value. */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_4_PF_VEC_MEM_ADDR54_63_SEL_VMID_MASK
value|0x000003FF
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_4_PF_VEC_MEM_ADDR54_63_SEL_VMID_SHIFT
value|0
comment|/* override value. */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_4_PF_VEC_MEM_ADDR54_63_OVRD_MASK
value|0x000FFC00
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_4_PF_VEC_MEM_ADDR54_63_OVRD_SHIFT
value|10
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_4_RSRVD_MASK
value|0xFFF00000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_4_RSRVD_SHIFT
value|20
comment|/**** func_ctrl_5 register ****/
comment|/*  * When set take the corresponding bit address [63:44] from  * aw_pf_vec_msg_addr_ovrd  */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_5_AW_PF_VEC_MSG_ADDR_SEL_MASK
value|0x000FFFFF
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_5_AW_PF_VEC_MSG_ADDR_SEL_SHIFT
value|0
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_5_RSRVD_MASK
value|0xFFF00000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_5_RSRVD_SHIFT
value|20
comment|/**** func_ctrl_6 register ****/
comment|/* override value. */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_6_AW_PF_VEC_MSG_ADDR_OVRD_MASK
value|0x000FFFFF
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_6_AW_PF_VEC_MSG_ADDR_OVRD_SHIFT
value|0
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_6_RSRVD_MASK
value|0xFFF00000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_6_RSRVD_SHIFT
value|20
comment|/**** func_ctrl_7 register ****/
comment|/*  * When set take the corresponding bit address [63:44] from  * ar_pf_vec_msg_addr_ovrd  */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_7_AR_PF_VEC_MSG_ADDR_SEL_MASK
value|0x000FFFFF
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_7_AR_PF_VEC_MSG_ADDR_SEL_SHIFT
value|0
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_7_RSRVD_MASK
value|0xFFF00000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_7_RSRVD_SHIFT
value|20
comment|/**** func_ctrl_8 register ****/
comment|/* override value. */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_8_AR_PF_VEC_MSG_ADDR_OVRD_MASK
value|0x000FFFFF
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_8_AR_PF_VEC_MSG_ADDR_OVRD_SHIFT
value|0
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_8_RSRVD_MASK
value|0xFFF00000
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_8_RSRVD_SHIFT
value|20
comment|/**** func_ctrl_9 register ****/
comment|/* no snoop override  */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_9_PF_VEC_NO_SNOOP_OVRD
value|(1<< 0)
comment|/* no snoop override value  */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_9_PF_VEC_NO_SNOOP_OVRD_VALUE
value|(1<< 1)
comment|/* atu bypass override  */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_9_PF_VEC_ATU_BYPASS_OVRD
value|(1<< 2)
comment|/* atu bypass override value */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_9_PF_VEC_ATU_BYPASS_OVRD_VALUE
value|(1<< 3)
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_9_RSRVD_MASK
value|0xFFFFFFF0
define|#
directive|define
name|PCIE_AXI_PF_AXI_ATTR_OVRD_FUNC_CTRL_9_RSRVD_SHIFT
value|4
comment|/**** entry_vec register ****/
comment|/* entry0 */
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_ENTRY_0_MASK
value|0x0000001F
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_ENTRY_0_SHIFT
value|0
comment|/* entry1 */
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_ENTRY_1_MASK
value|0x000003E0
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_ENTRY_1_SHIFT
value|5
comment|/* entry2 */
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_ENTRY_2_MASK
value|0x00007C00
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_ENTRY_2_SHIFT
value|10
comment|/* entry3 */
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_ENTRY_3_MASK
value|0x000F8000
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_ENTRY_3_SHIFT
value|15
comment|/* atu bypass for message "write" */
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_AW_MSG_ATU_BYPASS
value|(1<< 20)
comment|/* atu bypass for message "read" */
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_AR_MSG_ATU_BYPASS
value|(1<< 21)
comment|/* Rsrvd */
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_RSRVD_MASK
value|0xFFC00000
define|#
directive|define
name|PCIE_AXI_MSG_ATTR_AXUSER_TABLE_ENTRY_VEC_RSRVD_SHIFT
value|22
comment|/**** int_cause_grp_A_axi register ****/
comment|/*  * Master Response Composer Lookup Error  * Overflow that occurred in a lookup table of the Outbound responses. This  * indicates that there was a violation for the number of outstanding NP  * requests issued for the Inbound direction.  * Write zero to clear.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_GM_COMPOSER_LOOKUP_ERR
value|(1<< 0)
comment|/*  * Indicates a PARITY ERROR on the master data read channel.  * Write zero to clear.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_PARITY_ERR_DATA_PATH_RD
value|(1<< 2)
comment|/*  * Indicates a PARITY ERROR on the slave addr read channel.  * Write zero to clear.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_PARITY_ERR_OUT_ADDR_RD
value|(1<< 3)
comment|/*  * Indicates a PARITY ERROR on the slave addr write channel.  * Write zero to clear.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_PARITY_ERR_OUT_ADDR_WR
value|(1<< 4)
comment|/*  * Indicates a PARITY ERROR on the slave data write channel.  * Write zero to clear.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_PARITY_ERR_OUT_DATA_WR
value|(1<< 5)
comment|/* Reserved */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_RESERVED_6
value|(1<< 6)
comment|/*  * Software error: ECAM write request with invalid bus number.  * Write Zero to clear  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_SW_ECAM_ERR_RD
value|(1<< 7)
comment|/*  * Software error: ECAM read request with invalid bus number.  * Write Zero to clear.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_SW_ECAM_ERR_WR
value|(1<< 8)
comment|/* Indicates an ERROR in the PCIe application cause register. */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_PCIE_CORE_INT
value|(1<< 9)
comment|/*  * Whenever the Master AXI finishes writing a message, it sets this bit.  * Whenever the int is cleared, the message information MSG_* regs are no longer  * valid.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_MSTR_AXI_GETOUT_MSG
value|(1<< 10)
comment|/* Read AXI compilation has ERROR. */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_RD_CMPL_ERR
value|(1<< 11)
comment|/* Write AXI compilation has ERROR. */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_WR_CMPL_ERR
value|(1<< 12)
comment|/* Read AXI compilation has timed out. */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_RD_CMPL_TO
value|(1<< 13)
comment|/* Write AXI compilation has timed out. */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_WR_CMPL_TO
value|(1<< 14)
comment|/* Parity error AXI domain */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_PARITY_ERROR_AXI
value|(1<< 15)
comment|/* POS error interrupt */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_POS_AXI_BRESP
value|(1<< 16)
comment|/* The outstanding write counter become  full should never happen */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_WRITE_CNT_FULL_ERR
value|(1<< 17)
comment|/* BRESP received before the write counter increment.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CAUSE_BRESP_BEFORE_WR_CNT_INC_ERR
value|(1<< 18)
comment|/**** int_control_grp_A_axi register ****/
comment|/* When Clear_on_Read =1, all bits of the Cause register are cleared on read. */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_CLEAR_ON_READ
value|(1<< 0)
comment|/*  * (Must be set only when MSIX is enabled.)  * When Auto-Mask =1 and an MSI-X ACK for this bit is received, its  * corresponding bit in the mask register is set, masking future interrupts.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_AUTO_MASK
value|(1<< 1)
comment|/*  * Auto_Clear (RW)  * When Auto-Clear =1, the bits in the Interrupt Cause register are auto-cleared  * after MSI-X is acknowledged. Must be used only if MSI-X is enabled.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_AUTO_CLEAR
value|(1<< 2)
comment|/*  * When set,_on_Posedge =1, the bits in the Interrupt Cause register are set on  * the posedge of the interrupt source, i.e., when interrupt source =1 and  * Interrupt Status = 0.  * When set,_on_Posedge =0, the bits in the Interrupt Cause register are set  * when interrupt source =1.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_SET_ON_POS
value|(1<< 3)
comment|/*  * When Moderation_Reset =1, all Moderation timers associated with the interrupt  * cause bits are cleared to 0, enabling immediate interrupt assertion if any  * unmasked cause bit is set to 1. This bit is self-negated.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_MOD_RST
value|(1<< 4)
comment|/*  * When mask_msi_x =1, no MSI-X from this group is sent. This bit is set to 1  * when the associate summary bit in this group is used to generate a single  * MSI-X for this group.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_MASK_MSI_X
value|(1<< 5)
comment|/* MSI-X AWID value. Same ID for all cause bits. */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_AWID_MASK
value|0x00000F00
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_AWID_SHIFT
value|8
comment|/*  * This value determines the interval between interrupts. Writing ZERO disables  * Moderation.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_MOD_INTV_MASK
value|0x00FF0000
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_MOD_INTV_SHIFT
value|16
comment|/*  * This value determines the Moderation_Timer_Clock speed.  * 0- Moderation-timer is decremented every 1x256 SB clock cycles ~1uS.  * 1- Moderation-timer is decremented every 2x256 SB clock cycles ~2uS.  * N- Moderation-timer is decremented every Nx256 SB clock cycles ~(N+1) uS.  */
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_MOD_RES_MASK
value|0x0F000000
define|#
directive|define
name|PCIE_AXI_INT_GRP_A_CTRL_MOD_RES_SHIFT
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
comment|/* __AL_HAL_pcie_axi_REG_H */
end_comment

begin_comment
comment|/** @} end of ... group */
end_comment

end_unit

