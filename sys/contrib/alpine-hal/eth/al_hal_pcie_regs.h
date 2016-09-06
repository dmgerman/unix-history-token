begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_PCIE_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_PCIE_REGS_H__
end_define

begin_comment
comment|/* Note: Definitions before the includes so axi/wrapper regs sees them */
end_comment

begin_comment
comment|/** Maximum physical functions supported */
end_comment

begin_define
define|#
directive|define
name|REV1_2_MAX_NUM_OF_PFS
value|1
end_define

begin_define
define|#
directive|define
name|REV3_MAX_NUM_OF_PFS
value|4
end_define

begin_define
define|#
directive|define
name|AL_MAX_NUM_OF_PFS
value|4
end_define

begin_comment
comment|/* the maximum between all Revisions */
end_comment

begin_include
include|#
directive|include
file|"al_hal_pcie_axi_reg.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|AL_PCIE_EX
end_ifndef

begin_include
include|#
directive|include
file|"al_hal_pcie_w_reg.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"al_hal_pcie_w_reg_ex.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Revision IDs:  * ID_0: SlickRock M0  * ID_1: SlickRock A0  * ID_2: PeakRock  x4  * ID_3: PeakRock  x8  */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_REV_ID_0
value|0
end_define

begin_define
define|#
directive|define
name|AL_PCIE_REV_ID_1
value|1
end_define

begin_define
define|#
directive|define
name|AL_PCIE_REV_ID_2
value|2
end_define

begin_define
define|#
directive|define
name|AL_PCIE_REV_ID_3
value|3
end_define

begin_define
define|#
directive|define
name|AL_PCIE_AXI_REGS_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|AL_PCIE_REV_1_2_APP_REGS_OFFSET
value|0x1000
end_define

begin_define
define|#
directive|define
name|AL_PCIE_REV_3_APP_REGS_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|AL_PCIE_REV_1_2_CORE_CONF_BASE_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|AL_PCIE_REV_3_CORE_CONF_BASE_OFFSET
value|0x10000
end_define

begin_comment
comment|/** Maximum number of lanes supported */
end_comment

begin_define
define|#
directive|define
name|REV1_2_MAX_NUM_LANES
value|4
end_define

begin_define
define|#
directive|define
name|REV3_MAX_NUM_LANES
value|8
end_define

begin_define
define|#
directive|define
name|AL_MAX_NUM_OF_LANES
value|8
end_define

begin_comment
comment|/* the maximum between all Revisions */
end_comment

begin_struct
struct|struct
name|al_pcie_core_iatu_regs
block|{
name|uint32_t
name|index
decl_stmt|;
name|uint32_t
name|cr1
decl_stmt|;
name|uint32_t
name|cr2
decl_stmt|;
name|uint32_t
name|lower_base_addr
decl_stmt|;
name|uint32_t
name|upper_base_addr
decl_stmt|;
name|uint32_t
name|limit_addr
decl_stmt|;
name|uint32_t
name|lower_target_addr
decl_stmt|;
name|uint32_t
name|upper_target_addr
decl_stmt|;
name|uint32_t
name|cr3
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
operator|(
literal|0x270
operator|-
literal|0x224
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_core_port_regs
block|{
name|uint32_t
name|ack_lat_rply_timer
decl_stmt|;
name|uint32_t
name|reserved1
index|[
operator|(
literal|0x10
operator|-
literal|0x4
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|port_link_ctrl
decl_stmt|;
name|uint32_t
name|reserved2
index|[
operator|(
literal|0x18
operator|-
literal|0x14
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|timer_ctrl_max_func_num
decl_stmt|;
name|uint32_t
name|filter_mask_reg_1
decl_stmt|;
name|uint32_t
name|reserved3
index|[
operator|(
literal|0x48
operator|-
literal|0x20
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|vc0_posted_rcv_q_ctrl
decl_stmt|;
name|uint32_t
name|vc0_non_posted_rcv_q_ctrl
decl_stmt|;
name|uint32_t
name|vc0_comp_rcv_q_ctrl
decl_stmt|;
name|uint32_t
name|reserved4
index|[
operator|(
literal|0x10C
operator|-
literal|0x54
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|gen2_ctrl
decl_stmt|;
name|uint32_t
name|reserved5
index|[
operator|(
literal|0x190
operator|-
literal|0x110
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|gen3_ctrl
decl_stmt|;
name|uint32_t
name|gen3_eq_fs_lf
decl_stmt|;
name|uint32_t
name|gen3_eq_preset_to_coef_map
decl_stmt|;
name|uint32_t
name|gen3_eq_preset_idx
decl_stmt|;
name|uint32_t
name|reserved6
decl_stmt|;
name|uint32_t
name|gen3_eq_status
decl_stmt|;
name|uint32_t
name|gen3_eq_ctrl
decl_stmt|;
name|uint32_t
name|reserved7
index|[
operator|(
literal|0x1B8
operator|-
literal|0x1AC
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|pipe_loopback_ctrl
decl_stmt|;
name|uint32_t
name|rd_only_wr_en
decl_stmt|;
name|uint32_t
name|reserved8
index|[
operator|(
literal|0x1D0
operator|-
literal|0x1C0
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|axi_slave_err_resp
decl_stmt|;
name|uint32_t
name|reserved9
index|[
operator|(
literal|0x200
operator|-
literal|0x1D4
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_core_iatu_regs
name|iatu
decl_stmt|;
name|uint32_t
name|reserved10
index|[
operator|(
literal|0x448
operator|-
literal|0x270
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_core_aer_regs
block|{
comment|/* 0x0 - PCI Express Extended Capability Header */
name|uint32_t
name|header
decl_stmt|;
comment|/* 0x4 - Uncorrectable Error Status Register */
name|uint32_t
name|uncorr_err_stat
decl_stmt|;
comment|/* 0x8 - Uncorrectable Error Mask Register */
name|uint32_t
name|uncorr_err_mask
decl_stmt|;
comment|/* 0xc - Uncorrectable Error Severity Register */
name|uint32_t
name|uncorr_err_severity
decl_stmt|;
comment|/* 0x10 - Correctable Error Status Register */
name|uint32_t
name|corr_err_stat
decl_stmt|;
comment|/* 0x14 - Correctable Error Mask Register */
name|uint32_t
name|corr_err_mask
decl_stmt|;
comment|/* 0x18 - Advanced Error Capabilities and Control Register */
name|uint32_t
name|cap_and_ctrl
decl_stmt|;
comment|/* 0x1c - Header Log Registers */
name|uint32_t
name|header_log
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x2c - Root Error Command Register */
name|uint32_t
name|root_err_cmd
decl_stmt|;
comment|/* 0x30 - Root Error Status Register */
name|uint32_t
name|root_err_stat
decl_stmt|;
comment|/* 0x34 - Error Source Identification Register */
name|uint32_t
name|err_src_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_core_reg_space_rev_1_2
block|{
name|uint32_t
name|config_header
index|[
literal|0x40
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|pcie_pm_cap_base
decl_stmt|;
name|uint32_t
name|reserved1
index|[
operator|(
literal|0x70
operator|-
literal|0x44
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|pcie_cap_base
decl_stmt|;
name|uint32_t
name|pcie_dev_cap_base
decl_stmt|;
name|uint32_t
name|pcie_dev_ctrl_status
decl_stmt|;
name|uint32_t
name|pcie_link_cap_base
decl_stmt|;
name|uint32_t
name|reserved2
index|[
operator|(
literal|0xB0
operator|-
literal|0x80
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|msix_cap_base
decl_stmt|;
name|uint32_t
name|reserved3
index|[
operator|(
literal|0x100
operator|-
literal|0xB4
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_core_aer_regs
name|aer
decl_stmt|;
name|uint32_t
name|reserved4
index|[
operator|(
literal|0x150
operator|-
operator|(
literal|0x100
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_core_aer_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|pcie_sec_ext_cap_base
decl_stmt|;
name|uint32_t
name|reserved5
index|[
operator|(
literal|0x700
operator|-
literal|0x154
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_core_port_regs
name|port_regs
decl_stmt|;
name|uint32_t
name|reserved6
index|[
operator|(
literal|0x1000
operator|-
operator|(
literal|0x700
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_core_port_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_core_reg_space_rev_3
block|{
name|uint32_t
name|config_header
index|[
literal|0x40
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|pcie_pm_cap_base
decl_stmt|;
name|uint32_t
name|reserved1
index|[
operator|(
literal|0x70
operator|-
literal|0x44
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|pcie_cap_base
decl_stmt|;
name|uint32_t
name|pcie_dev_cap_base
decl_stmt|;
name|uint32_t
name|pcie_dev_ctrl_status
decl_stmt|;
name|uint32_t
name|pcie_link_cap_base
decl_stmt|;
name|uint32_t
name|reserved2
index|[
operator|(
literal|0xB0
operator|-
literal|0x80
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|uint32_t
name|msix_cap_base
decl_stmt|;
name|uint32_t
name|reserved3
index|[
operator|(
literal|0x100
operator|-
literal|0xB4
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_core_aer_regs
name|aer
decl_stmt|;
name|uint32_t
name|reserved4
index|[
operator|(
literal|0x158
operator|-
operator|(
literal|0x100
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_core_aer_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
comment|/* pcie_sec_cap is only applicable for function 0 */
name|uint32_t
name|pcie_sec_ext_cap_base
decl_stmt|;
name|uint32_t
name|reserved5
index|[
operator|(
literal|0x178
operator|-
literal|0x15C
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
comment|/* tph capability is only applicable for rev3 */
name|uint32_t
name|tph_cap_base
decl_stmt|;
name|uint32_t
name|reserved6
index|[
operator|(
literal|0x700
operator|-
literal|0x17C
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
comment|/* port_regs is only applicable for function 0 */
name|struct
name|al_pcie_core_port_regs
name|port_regs
decl_stmt|;
name|uint32_t
name|reserved7
index|[
operator|(
literal|0x1000
operator|-
operator|(
literal|0x700
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_core_port_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_rev3_core_reg_space
block|{
name|struct
name|al_pcie_core_reg_space_rev_3
name|func
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_core_reg_space
block|{
name|uint32_t
modifier|*
name|config_header
decl_stmt|;
name|uint32_t
modifier|*
name|pcie_pm_cap_base
decl_stmt|;
name|uint32_t
modifier|*
name|pcie_cap_base
decl_stmt|;
name|uint32_t
modifier|*
name|pcie_dev_cap_base
decl_stmt|;
name|uint32_t
modifier|*
name|pcie_dev_ctrl_status
decl_stmt|;
name|uint32_t
modifier|*
name|pcie_link_cap_base
decl_stmt|;
name|uint32_t
modifier|*
name|msix_cap_base
decl_stmt|;
name|struct
name|al_pcie_core_aer_regs
modifier|*
name|aer
decl_stmt|;
name|uint32_t
modifier|*
name|pcie_sec_ext_cap_base
decl_stmt|;
name|uint32_t
modifier|*
name|tph_cap_base
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_revx_regs
block|{
name|struct
name|al_pcie_revx_axi_regs
name|__iomem
name|axi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_rev1_regs
block|{
name|struct
name|al_pcie_rev1_axi_regs
name|__iomem
name|axi
decl_stmt|;
name|uint32_t
name|reserved1
index|[
operator|(
name|AL_PCIE_REV_1_2_APP_REGS_OFFSET
operator|-
operator|(
name|AL_PCIE_AXI_REGS_OFFSET
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_rev1_axi_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_rev1_w_regs
name|__iomem
name|app
decl_stmt|;
name|uint32_t
name|reserved2
index|[
operator|(
name|AL_PCIE_REV_1_2_CORE_CONF_BASE_OFFSET
operator|-
operator|(
name|AL_PCIE_REV_1_2_APP_REGS_OFFSET
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_rev1_w_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_core_reg_space_rev_1_2
name|core_space
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_rev2_regs
block|{
name|struct
name|al_pcie_rev2_axi_regs
name|__iomem
name|axi
decl_stmt|;
name|uint32_t
name|reserved1
index|[
operator|(
name|AL_PCIE_REV_1_2_APP_REGS_OFFSET
operator|-
operator|(
name|AL_PCIE_AXI_REGS_OFFSET
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_rev2_axi_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_rev2_w_regs
name|__iomem
name|app
decl_stmt|;
name|uint32_t
name|reserved2
index|[
operator|(
name|AL_PCIE_REV_1_2_CORE_CONF_BASE_OFFSET
operator|-
operator|(
name|AL_PCIE_REV_1_2_APP_REGS_OFFSET
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_rev2_w_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_core_reg_space_rev_1_2
name|core_space
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_rev3_regs
block|{
name|struct
name|al_pcie_rev3_axi_regs
name|__iomem
name|axi
decl_stmt|;
name|uint32_t
name|reserved1
index|[
operator|(
name|AL_PCIE_REV_3_APP_REGS_OFFSET
operator|-
operator|(
name|AL_PCIE_AXI_REGS_OFFSET
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_rev3_axi_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_rev3_w_regs
name|__iomem
name|app
decl_stmt|;
name|uint32_t
name|reserved2
index|[
operator|(
name|AL_PCIE_REV_3_CORE_CONF_BASE_OFFSET
operator|-
operator|(
name|AL_PCIE_REV_3_APP_REGS_OFFSET
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|al_pcie_rev3_w_regs
argument_list|)
operator|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_pcie_rev3_core_reg_space
name|core_space
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_ctrl
block|{
name|uint32_t
modifier|*
name|global
decl_stmt|;
name|uint32_t
modifier|*
name|master_arctl
decl_stmt|;
name|uint32_t
modifier|*
name|master_awctl
decl_stmt|;
name|uint32_t
modifier|*
name|slv_ctl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_ob_ctrl
block|{
name|uint32_t
modifier|*
name|cfg_target_bus
decl_stmt|;
name|uint32_t
modifier|*
name|cfg_control
decl_stmt|;
name|uint32_t
modifier|*
name|io_start_l
decl_stmt|;
name|uint32_t
modifier|*
name|io_start_h
decl_stmt|;
name|uint32_t
modifier|*
name|io_limit_l
decl_stmt|;
name|uint32_t
modifier|*
name|io_limit_h
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_pcie_global
block|{
name|uint32_t
modifier|*
name|conf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_conf
block|{
name|uint32_t
modifier|*
name|zero_lane0
decl_stmt|;
name|uint32_t
modifier|*
name|zero_lane1
decl_stmt|;
name|uint32_t
modifier|*
name|zero_lane2
decl_stmt|;
name|uint32_t
modifier|*
name|zero_lane3
decl_stmt|;
name|uint32_t
modifier|*
name|zero_lane4
decl_stmt|;
name|uint32_t
modifier|*
name|zero_lane5
decl_stmt|;
name|uint32_t
modifier|*
name|zero_lane6
decl_stmt|;
name|uint32_t
modifier|*
name|zero_lane7
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_status
block|{
name|uint32_t
modifier|*
name|lane
index|[
name|AL_MAX_NUM_OF_LANES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_parity
block|{
name|uint32_t
modifier|*
name|en_axi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_ordering
block|{
name|uint32_t
modifier|*
name|pos_cntl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_pre_configuration
block|{
name|uint32_t
modifier|*
name|pcie_core_setup
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_init_fc
block|{
name|uint32_t
modifier|*
name|cfg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_attr_ovrd
block|{
name|uint32_t
modifier|*
name|write_msg_ctrl_0
decl_stmt|;
name|uint32_t
modifier|*
name|write_msg_ctrl_1
decl_stmt|;
name|uint32_t
modifier|*
name|pf_sel
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_pf_axi_attr_ovrd
block|{
name|uint32_t
modifier|*
name|func_ctrl_0
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_1
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_2
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_3
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_4
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_5
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_6
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_7
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_8
decl_stmt|;
name|uint32_t
modifier|*
name|func_ctrl_9
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_msg_attr_axuser_table
block|{
name|uint32_t
modifier|*
name|entry_vec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_axi_regs
block|{
name|struct
name|al_pcie_axi_ctrl
name|ctrl
decl_stmt|;
name|struct
name|al_pcie_axi_ob_ctrl
name|ob_ctrl
decl_stmt|;
name|struct
name|al_pcie_axi_pcie_global
name|pcie_global
decl_stmt|;
name|struct
name|al_pcie_axi_conf
name|conf
decl_stmt|;
name|struct
name|al_pcie_axi_status
name|status
decl_stmt|;
name|struct
name|al_pcie_axi_parity
name|parity
decl_stmt|;
name|struct
name|al_pcie_axi_ordering
name|ordering
decl_stmt|;
name|struct
name|al_pcie_axi_pre_configuration
name|pre_configuration
decl_stmt|;
name|struct
name|al_pcie_axi_init_fc
name|init_fc
decl_stmt|;
name|struct
name|al_pcie_revx_axi_int_grp_a_axi
modifier|*
name|int_grp_a
decl_stmt|;
comment|/* Rev3 only */
name|struct
name|al_pcie_axi_attr_ovrd
name|axi_attr_ovrd
decl_stmt|;
name|struct
name|al_pcie_axi_pf_axi_attr_ovrd
name|pf_axi_attr_ovrd
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
name|struct
name|al_pcie_axi_msg_attr_axuser_table
name|msg_attr_axuser_table
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_w_global_ctrl
block|{
name|uint32_t
modifier|*
name|port_init
decl_stmt|;
name|uint32_t
modifier|*
name|pm_control
decl_stmt|;
name|uint32_t
modifier|*
name|events_gen
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
name|uint32_t
modifier|*
name|corr_err_sts_int
decl_stmt|;
name|uint32_t
modifier|*
name|uncorr_err_sts_int
decl_stmt|;
name|uint32_t
modifier|*
name|sris_kp_counter
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_w_soc_int
block|{
name|uint32_t
modifier|*
name|mask_inta_leg_0
decl_stmt|;
name|uint32_t
modifier|*
name|mask_inta_leg_3
decl_stmt|;
comment|/* Rev 2/3 only */
name|uint32_t
modifier|*
name|mask_msi_leg_0
decl_stmt|;
name|uint32_t
modifier|*
name|mask_msi_leg_3
decl_stmt|;
comment|/* Rev 2/3 only */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_w_atu
block|{
name|uint32_t
modifier|*
name|in_mask_pair
decl_stmt|;
name|uint32_t
modifier|*
name|out_mask_pair
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_w_regs
block|{
name|struct
name|al_pcie_w_global_ctrl
name|global_ctrl
decl_stmt|;
name|struct
name|al_pcie_revx_w_debug
modifier|*
name|debug
decl_stmt|;
name|struct
name|al_pcie_revx_w_ap_user_send_msg
modifier|*
name|ap_user_send_msg
decl_stmt|;
name|struct
name|al_pcie_w_soc_int
name|soc_int
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_cntl_gen
modifier|*
name|ctrl_gen
decl_stmt|;
name|struct
name|al_pcie_revx_w_parity
modifier|*
name|parity
decl_stmt|;
name|struct
name|al_pcie_w_atu
name|atu
decl_stmt|;
name|struct
name|al_pcie_revx_w_status_per_func
modifier|*
name|status_per_func
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
name|struct
name|al_pcie_revx_w_int_grp
modifier|*
name|int_grp_a
decl_stmt|;
name|struct
name|al_pcie_revx_w_int_grp
modifier|*
name|int_grp_b
decl_stmt|;
name|struct
name|al_pcie_revx_w_int_grp
modifier|*
name|int_grp_c
decl_stmt|;
name|struct
name|al_pcie_revx_w_int_grp
modifier|*
name|int_grp_d
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_pcie_regs
block|{
name|struct
name|al_pcie_axi_regs
name|axi
decl_stmt|;
name|struct
name|al_pcie_w_regs
name|app
decl_stmt|;
name|struct
name|al_pcie_core_port_regs
modifier|*
name|port_regs
decl_stmt|;
name|struct
name|al_pcie_core_reg_space
name|core_space
index|[
name|REV3_MAX_NUM_OF_PFS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_GLOBAL_CONF_DEV_TYPE_EP
value|0
end_define

begin_define
define|#
directive|define
name|PCIE_AXI_MISC_PCIE_GLOBAL_CONF_DEV_TYPE_RC
value|4
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN2_CTRL_DIRECT_SPEED_CHANGE
value|AL_BIT(17)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN2_CTRL_TX_SWING_LOW_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN2_CTRL_TX_COMPLIANCE_RCV_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN2_CTRL_DEEMPHASIS_SET_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN2_CTRL_NUM_OF_LANES_MASK
value|AL_FIELD_MASK(12, 8)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN2_CTRL_NUM_OF_LANES_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN3_CTRL_EQ_PHASE_2_3_DISABLE_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN3_CTRL_EQ_DISABLE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN3_EQ_LF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN3_EQ_LF_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN3_EQ_FS_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_GEN3_EQ_FS_MASK
value|(0x3f<< PCIE_PORT_GEN3_EQ_FS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_LINK_CTRL_LB_EN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_LINK_CTRL_FAST_LINK_EN_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_LINK_CTRL_LINK_CAPABLE_MASK
value|AL_FIELD_MASK(21, 16)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_LINK_CTRL_LINK_CAPABLE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_PIPE_LOOPBACK_CTRL_PIPE_LB_EN_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_AXI_SLAVE_ERR_RESP_ALL_MAPPING_SHIFT
value|0
end_define

begin_comment
comment|/** timer_ctrl_max_func_num register  * Max physical function number (for example: 0 for 1PF, 3 for 4PFs)  */
end_comment

begin_define
define|#
directive|define
name|PCIE_PORT_GEN3_MAX_FUNC_NUM
value|AL_FIELD_MASK(7, 0)
end_define

begin_comment
comment|/* filter_mask_reg_1 register */
end_comment

begin_comment
comment|/**  * SKP Interval Value.  * The number of symbol times to wait between transmitting SKP ordered sets  */
end_comment

begin_define
define|#
directive|define
name|PCIE_FLT_MASK_SKP_INT_VAL_MASK
value|AL_FIELD_MASK(10, 0)
end_define

begin_comment
comment|/*  * 0: Treat Function MisMatched TLPs as UR  * 1: Treat Function MisMatched TLPs as Supported  */
end_comment

begin_define
define|#
directive|define
name|CX_FLT_MASK_UR_FUNC_MISMATCH
value|AL_BIT(16)
end_define

begin_comment
comment|/*  * 0: Treat CFG type1 TLPs as UR for EP; Supported for RC  * 1: Treat CFG type1 TLPs as Supported for EP; UR for RC  */
end_comment

begin_define
define|#
directive|define
name|CX_FLT_MASK_CFG_TYPE1_RE_AS_UR
value|AL_BIT(19)
end_define

begin_comment
comment|/*  * 0: Enforce requester id match for received CPL TLPs.  *    A violation results in cpl_abort, and possibly AER of unexp_cpl_err,  *    cpl_rcvd_ur, cpl_rcvd_ca  * 1: Mask requester id match for received CPL TLPs  */
end_comment

begin_define
define|#
directive|define
name|CX_FLT_MASK_CPL_REQID_MATCH
value|AL_BIT(22)
end_define

begin_comment
comment|/*  * 0: Enforce function match for received CPL TLPs.  *    A violation results in cpl_abort, and possibly AER of unexp_cpl_err,  *    cpl_rcvd_ur, cpl_rcvd_ca  * 1: Mask function match for received CPL TLPs  */
end_comment

begin_define
define|#
directive|define
name|CX_FLT_MASK_CPL_FUNC_MATCH
value|AL_BIT(23)
end_define

begin_comment
comment|/* vc0_posted_rcv_q_ctrl register */
end_comment

begin_define
define|#
directive|define
name|RADM_PQ_HCRD_VC0_MASK
value|AL_FIELD_MASK(19, 12)
end_define

begin_define
define|#
directive|define
name|RADM_PQ_HCRD_VC0_SHIFT
value|12
end_define

begin_comment
comment|/* vc0_non_posted_rcv_q_ctrl register */
end_comment

begin_define
define|#
directive|define
name|RADM_NPQ_HCRD_VC0_MASK
value|AL_FIELD_MASK(19, 12)
end_define

begin_define
define|#
directive|define
name|RADM_NPQ_HCRD_VC0_SHIFT
value|12
end_define

begin_comment
comment|/* vc0_comp_rcv_q_ctrl register */
end_comment

begin_define
define|#
directive|define
name|RADM_CPLQ_HCRD_VC0_MASK
value|AL_FIELD_MASK(19, 12)
end_define

begin_define
define|#
directive|define
name|RADM_CPLQ_HCRD_VC0_SHIFT
value|12
end_define

begin_comment
comment|/**** iATU, Control Register 1 ****/
end_comment

begin_comment
comment|/**  * When the Address and BAR matching logic in the core indicate that a MEM-I/O  * transaction matches a BAR in the function corresponding to this value, then  * address translation proceeds. This check is only performed if the "Function  * Number Match Enable" bit of the "iATU Control 2 Register" is set  */
end_comment

begin_define
define|#
directive|define
name|PCIE_IATU_CR1_FUNC_NUM_MASK
value|AL_FIELD_MASK(24, 20)
end_define

begin_define
define|#
directive|define
name|PCIE_IATU_CR1_FUNC_NUM_SHIFT
value|20
end_define

begin_comment
comment|/**** iATU, Control Register 2 ****/
end_comment

begin_comment
comment|/** For outbound regions, the Function Number Translation Bypass mode enables  *  taking the function number of the translated TLP from the PCIe core  *  interface and not from the "Function Number" field of CR1.  *  For inbound regions, this bit should be asserted when physical function  *  match mode needs to be enabled  */
end_comment

begin_define
define|#
directive|define
name|PCIE_IATU_CR2_FUNC_NUM_TRANS_BYPASS_FUNC_MATCH_ENABLE_MASK
value|AL_BIT(19)
end_define

begin_define
define|#
directive|define
name|PCIE_IATU_CR2_FUNC_NUM_TRANS_BYPASS_FUNC_MATCH_ENABLE_SHIFT
value|19
end_define

begin_comment
comment|/* pcie_dev_ctrl_status register */
end_comment

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_CORR_ERR_REPORT_EN
value|AL_BIT(0)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_NON_FTL_ERR_REPORT_EN
value|AL_BIT(1)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_FTL_ERR_REPORT_EN
value|AL_BIT(2)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_UNSUP_REQ_REPORT_EN
value|AL_BIT(3)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_MPS_MASK
value|AL_FIELD_MASK(7, 5)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_MPS_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_MPS_VAL_256
value|(1<< PCIE_PORT_DEV_CTRL_STATUS_MPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_MRRS_MASK
value|AL_FIELD_MASK(14, 12)
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_MRRS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PCIE_PORT_DEV_CTRL_STATUS_MRRS_VAL_256
value|(1<< PCIE_PORT_DEV_CTRL_STATUS_MRRS_SHIFT)
end_define

begin_comment
comment|/******************************************************************************  * AER registers  ******************************************************************************/
end_comment

begin_comment
comment|/* PCI Express Extended Capability ID */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_CAP_ID_MASK
value|AL_FIELD_MASK(15, 0)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_CAP_ID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PCIE_AER_CAP_ID_VAL
value|1
end_define

begin_comment
comment|/* Capability Version */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_CAP_VER_MASK
value|AL_FIELD_MASK(19, 16)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_CAP_VER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCIE_AER_CAP_VER_VAL
value|2
end_define

begin_comment
comment|/* First Error Pointer */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_CTRL_STAT_FIRST_ERR_PTR_MASK
value|AL_FIELD_MASK(4, 0)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_CTRL_STAT_FIRST_ERR_PTR_SHIFT
value|0
end_define

begin_comment
comment|/* ECRC Generation Capability */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_CTRL_STAT_ECRC_GEN_SUPPORTED
value|AL_BIT(5)
end_define

begin_comment
comment|/* ECRC Generation Enable */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_CTRL_STAT_ECRC_GEN_EN
value|AL_BIT(6)
end_define

begin_comment
comment|/* ECRC Check Capable */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_CTRL_STAT_ECRC_CHK_SUPPORTED
value|AL_BIT(7)
end_define

begin_comment
comment|/* ECRC Check Enable */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_CTRL_STAT_ECRC_CHK_EN
value|AL_BIT(8)
end_define

begin_comment
comment|/* Correctable Error Reporting Enable */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_CMD_CORR_ERR_RPRT_EN
value|AL_BIT(0)
end_define

begin_comment
comment|/* Non-Fatal Error Reporting Enable */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_CMD_NON_FTL_ERR_RPRT_EN
value|AL_BIT(1)
end_define

begin_comment
comment|/* Fatal Error Reporting Enable */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_CMD_FTL_ERR_RPRT_EN
value|AL_BIT(2)
end_define

begin_comment
comment|/* ERR_COR Received */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_CORR_ERR
value|AL_BIT(0)
end_define

begin_comment
comment|/* Multiple ERR_COR Received */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_CORR_ERR_MULTI
value|AL_BIT(1)
end_define

begin_comment
comment|/* ERR_FATAL/NONFATAL Received */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_FTL_NON_FTL_ERR
value|AL_BIT(2)
end_define

begin_comment
comment|/* Multiple ERR_FATAL/NONFATAL Received */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_FTL_NON_FTL_ERR_MULTI
value|AL_BIT(3)
end_define

begin_comment
comment|/* First Uncorrectable Fatal */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_FIRST_UNCORR_FTL
value|AL_BIT(4)
end_define

begin_comment
comment|/* Non-Fatal Error Messages Received */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_NON_FTL_RCVD
value|AL_BIT(5)
end_define

begin_comment
comment|/* Fatal Error Messages Received */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_FTL_RCVD
value|AL_BIT(6)
end_define

begin_comment
comment|/* Advanced Error Interrupt Message Number */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_ERR_INT_MSG_NUM_MASK
value|AL_FIELD_MASK(31, 27)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_ROOT_ERR_STAT_ERR_INT_MSG_NUM_SHIFT
value|27
end_define

begin_comment
comment|/* ERR_COR Source Identification */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_SRC_ID_CORR_ERR_MASK
value|AL_FIELD_MASK(15, 0)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_SRC_ID_CORR_ERR_SHIFT
value|0
end_define

begin_comment
comment|/* ERR_FATAL/NONFATAL Source Identification */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_SRC_ID_CORR_ERR_FTL_NON_FTL_MASK
value|AL_FIELD_MASK(31, 16)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_SRC_ID_CORR_ERR_FTL_NON_FTL_SHIFT
value|16
end_define

begin_comment
comment|/* AER message */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_MSG_REQID_MASK
value|AL_FIELD_MASK(31, 16)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_MSG_REQID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCIE_AER_MSG_TYPE_MASK
value|AL_FIELD_MASK(15, 8)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_MSG_TYPE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PCIE_AER_MSG_RESERVED
value|AL_FIELD_MASK(7, 1)
end_define

begin_define
define|#
directive|define
name|PCIE_AER_MSG_VALID
value|AL_BIT(0)
end_define

begin_comment
comment|/* AER message ack */
end_comment

begin_define
define|#
directive|define
name|PCIE_AER_MSG_ACK
value|AL_BIT(0)
end_define

begin_comment
comment|/* AER errors definitions */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_AER_TYPE_CORR
value|(0x30)
end_define

begin_define
define|#
directive|define
name|AL_PCIE_AER_TYPE_NON_FATAL
value|(0x31)
end_define

begin_define
define|#
directive|define
name|AL_PCIE_AER_TYPE_FATAL
value|(0x33)
end_define

begin_comment
comment|/* Requester ID Bus */
end_comment

begin_define
define|#
directive|define
name|AL_PCIE_REQID_BUS_NUM_SHIFT
value|(8)
end_define

begin_comment
comment|/******************************************************************************  * TPH registers  ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PCIE_TPH_NEXT_POINTER
value|AL_FIELD_MASK(31, 20)
end_define

begin_comment
comment|/******************************************************************************  * Config Header registers  ******************************************************************************/
end_comment

begin_comment
comment|/**  * see BIST_HEADER_TYPE_LATENCY_CACHE_LINE_SIZE_REG in core spec  * Note: valid only for EP mode  */
end_comment

begin_define
define|#
directive|define
name|PCIE_BIST_HEADER_TYPE_BASE
value|0xc
end_define

begin_define
define|#
directive|define
name|PCIE_BIST_HEADER_TYPE_MULTI_FUNC_MASK
value|AL_BIT(23)
end_define

begin_comment
comment|/******************************************************************************  * SRIS KP counters default values  ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PCIE_SRIS_KP_COUNTER_GEN3_DEFAULT_VAL
value|(0x24)
end_define

begin_define
define|#
directive|define
name|PCIE_SRIS_KP_COUNTER_GEN21_DEFAULT_VAL
value|(0x4B)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

