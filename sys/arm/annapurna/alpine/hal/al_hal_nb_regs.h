begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  *  @{  * @file   al_hal_nb_regs.h  *  * @brief North Bridge service registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_NB_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_NB_REGS_H__
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
name|al_nb_global
block|{
comment|/* [0x0]  */
name|uint32_t
name|cpus_config
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|cpus_secure
decl_stmt|;
comment|/* [0x8] Force init reset. */
name|uint32_t
name|cpus_init_control
decl_stmt|;
comment|/* [0xc] Force init reset per DECEI mode. */
name|uint32_t
name|cpus_init_status
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|nb_int_cause
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|sev_int_cause
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|pmus_int_cause
decl_stmt|;
comment|/* [0x1c]  */
name|uint32_t
name|sev_mask
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|cpus_hold_reset
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|cpus_software_reset
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|wd_timer0_reset
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|wd_timer1_reset
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|wd_timer2_reset
decl_stmt|;
comment|/* [0x34]  */
name|uint32_t
name|wd_timer3_reset
decl_stmt|;
comment|/* [0x38]  */
name|uint32_t
name|ddrc_hold_reset
decl_stmt|;
comment|/* [0x3c]  */
name|uint32_t
name|fabric_software_reset
decl_stmt|;
comment|/* [0x40]  */
name|uint32_t
name|cpus_power_ctrl
decl_stmt|;
name|uint32_t
name|rsrvd_0
index|[
literal|7
index|]
decl_stmt|;
comment|/* [0x60]  */
name|uint32_t
name|acf_base_high
decl_stmt|;
comment|/* [0x64]  */
name|uint32_t
name|acf_base_low
decl_stmt|;
comment|/* [0x68]  */
name|uint32_t
name|acf_control_override
decl_stmt|;
comment|/* [0x6c] Read-only that reflects CPU Cluster Local GIC base high address  */
name|uint32_t
name|lgic_base_high
decl_stmt|;
comment|/* [0x70] Read-only that reflects CPU Cluster Local GIC base low address   */
name|uint32_t
name|lgic_base_low
decl_stmt|;
comment|/* [0x74] Read-only that reflects the device's IOGIC base high address.  */
name|uint32_t
name|iogic_base_high
decl_stmt|;
comment|/* [0x78] Read-only that reflects IOGIC base low address  */
name|uint32_t
name|iogic_base_low
decl_stmt|;
comment|/* [0x7c]  */
name|uint32_t
name|io_wr_split_control
decl_stmt|;
comment|/* [0x80]  */
name|uint32_t
name|io_rd_rob_control
decl_stmt|;
comment|/* [0x84]  */
name|uint32_t
name|sb_pos_error_log_1
decl_stmt|;
comment|/* [0x88]  */
name|uint32_t
name|sb_pos_error_log_0
decl_stmt|;
comment|/* [0x8c]  */
name|uint32_t
name|c2swb_config
decl_stmt|;
comment|/* [0x90]  */
name|uint32_t
name|msix_error_log
decl_stmt|;
comment|/* [0x94]  */
name|uint32_t
name|error_cause
decl_stmt|;
comment|/* [0x98]  */
name|uint32_t
name|error_mask
decl_stmt|;
name|uint32_t
name|rsrvd_1
decl_stmt|;
comment|/* [0xa0]  */
name|uint32_t
name|qos_peak_control
decl_stmt|;
comment|/* [0xa4]  */
name|uint32_t
name|qos_set_control
decl_stmt|;
comment|/* [0xa8]  */
name|uint32_t
name|ddr_qos
decl_stmt|;
name|uint32_t
name|rsrvd_2
index|[
literal|9
index|]
decl_stmt|;
comment|/* [0xd0]  */
name|uint32_t
name|acf_misc
decl_stmt|;
comment|/* [0xd4]  */
name|uint32_t
name|config_bus_control
decl_stmt|;
name|uint32_t
name|rsrvd_3
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0xe0]  */
name|uint32_t
name|pos_id_match
decl_stmt|;
name|uint32_t
name|rsrvd_4
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0xf0]  */
name|uint32_t
name|sb_sel_override_awuser
decl_stmt|;
comment|/* [0xf4]  */
name|uint32_t
name|sb_override_awuser
decl_stmt|;
comment|/* [0xf8]  */
name|uint32_t
name|sb_sel_override_aruser
decl_stmt|;
comment|/* [0xfc]  */
name|uint32_t
name|sb_override_aruser
decl_stmt|;
comment|/* [0x100]  */
name|uint32_t
name|cpu_max_pd_timer
decl_stmt|;
comment|/* [0x104]  */
name|uint32_t
name|cpu_max_pu_timer
decl_stmt|;
name|uint32_t
name|rsrvd_5
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x110]  */
name|uint32_t
name|auto_ddr_self_refresh_counter
decl_stmt|;
name|uint32_t
name|rsrvd_6
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x120]  */
name|uint32_t
name|coresight_pd
decl_stmt|;
comment|/* [0x124]  */
name|uint32_t
name|coresight_internal_0
decl_stmt|;
comment|/* [0x128]  */
name|uint32_t
name|coresight_dbgromaddr
decl_stmt|;
comment|/* [0x12c]  */
name|uint32_t
name|coresight_dbgselfaddr
decl_stmt|;
comment|/* [0x130]  */
name|uint32_t
name|coresght_targetid
decl_stmt|;
comment|/* [0x134]  */
name|uint32_t
name|coresght_targetid0
decl_stmt|;
name|uint32_t
name|rsrvd_7
index|[
literal|10
index|]
decl_stmt|;
comment|/* [0x160]  */
name|uint32_t
name|sb_force_same_id_cfg_0
decl_stmt|;
comment|/* [0x164]  */
name|uint32_t
name|sb_mstr_force_same_id_sel_0
decl_stmt|;
comment|/* [0x168]  */
name|uint32_t
name|sb_force_same_id_cfg_1
decl_stmt|;
comment|/* [0x16c]  */
name|uint32_t
name|sb_mstr_force_same_id_sel_1
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|932
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_system_counter
block|{
comment|/* [0x0]  */
name|uint32_t
name|cnt_control
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|cnt_base_freq
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|cnt_low
decl_stmt|;
comment|/* [0xc]  */
name|uint32_t
name|cnt_high
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|cnt_init_low
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|cnt_init_high
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|58
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_rams_control_misc
block|{
comment|/* [0x0]  */
name|uint32_t
name|ca15_rf_misc
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|nb_rf_misc
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|61
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_ca15_rams_control
block|{
comment|/* [0x0]  */
name|uint32_t
name|rf_0
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|rf_1
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|rf_2
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_semaphores
block|{
comment|/* [0x0] This configuration is only sampled during reset of the processor */
name|uint32_t
name|lockn
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_debug
block|{
comment|/* [0x0]  */
name|uint32_t
name|ca15_outputs_1
decl_stmt|;
comment|/* [0x4]  */
name|uint32_t
name|ca15_outputs_2
decl_stmt|;
name|uint32_t
name|rsrvd_0
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|cpu_msg
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|rsv0_config
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|rsv1_config
decl_stmt|;
name|uint32_t
name|rsrvd_1
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|rsv0_status
decl_stmt|;
comment|/* [0x34]  */
name|uint32_t
name|rsv1_status
decl_stmt|;
name|uint32_t
name|rsrvd_2
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x40]  */
name|uint32_t
name|ddrc
decl_stmt|;
comment|/* [0x44]  */
name|uint32_t
name|ddrc_phy_smode_control
decl_stmt|;
comment|/* [0x48]  */
name|uint32_t
name|ddrc_phy_smode_status
decl_stmt|;
name|uint32_t
name|rsrvd_3
index|[
literal|5
index|]
decl_stmt|;
comment|/* [0x60]  */
name|uint32_t
name|pmc
decl_stmt|;
name|uint32_t
name|rsrvd_4
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x70]  */
name|uint32_t
name|cpus_general
decl_stmt|;
comment|/* [0x74]  */
name|uint32_t
name|cpus_general_1
decl_stmt|;
name|uint32_t
name|rsrvd_5
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x80]  */
name|uint32_t
name|cpus_int_out
decl_stmt|;
name|uint32_t
name|rsrvd_6
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x90]  */
name|uint32_t
name|latch_pc_req
decl_stmt|;
name|uint32_t
name|rsrvd_7
decl_stmt|;
comment|/* [0x98]  */
name|uint32_t
name|latch_pc_low
decl_stmt|;
comment|/* [0x9c]  */
name|uint32_t
name|latch_pc_high
decl_stmt|;
name|uint32_t
name|rsrvd_8
index|[
literal|24
index|]
decl_stmt|;
comment|/* [0x100]  */
name|uint32_t
name|track_dump_ctrl
decl_stmt|;
comment|/* [0x104]  */
name|uint32_t
name|track_dump_rdata_0
decl_stmt|;
comment|/* [0x108]  */
name|uint32_t
name|track_dump_rdata_1
decl_stmt|;
name|uint32_t
name|rsrvd_9
index|[
literal|5
index|]
decl_stmt|;
comment|/* [0x120]  */
name|uint32_t
name|track_events
decl_stmt|;
name|uint32_t
name|rsrvd_10
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x130]  */
name|uint32_t
name|pos_track_dump_ctrl
decl_stmt|;
comment|/* [0x134]  */
name|uint32_t
name|pos_track_dump_rdata_0
decl_stmt|;
comment|/* [0x138]  */
name|uint32_t
name|pos_track_dump_rdata_1
decl_stmt|;
name|uint32_t
name|rsrvd_11
decl_stmt|;
comment|/* [0x140]  */
name|uint32_t
name|c2swb_track_dump_ctrl
decl_stmt|;
comment|/* [0x144]  */
name|uint32_t
name|c2swb_track_dump_rdata_0
decl_stmt|;
comment|/* [0x148]  */
name|uint32_t
name|c2swb_track_dump_rdata_1
decl_stmt|;
name|uint32_t
name|rsrvd_12
decl_stmt|;
comment|/* [0x150]  */
name|uint32_t
name|cpus_track_dump_ctrl
decl_stmt|;
comment|/* [0x154]  */
name|uint32_t
name|cpus_track_dump_rdata_0
decl_stmt|;
comment|/* [0x158]  */
name|uint32_t
name|cpus_track_dump_rdata_1
decl_stmt|;
name|uint32_t
name|rsrvd_13
decl_stmt|;
comment|/* [0x160]  */
name|uint32_t
name|c2swb_bar_ovrd_high
decl_stmt|;
comment|/* [0x164]  */
name|uint32_t
name|c2swb_bar_ovrd_low
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|38
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_cpun_config_status
block|{
comment|/* [0x0] This configuration is only sampled during reset of the processor. */
name|uint32_t
name|config
decl_stmt|;
comment|/* [0x4] This configuration is only sampled during reset of the processor. */
name|uint32_t
name|config_aarch64
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|local_cause_mask
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|pmus_cause_mask
decl_stmt|;
comment|/* [0x14]  */
name|uint32_t
name|sei_cause_mask
decl_stmt|;
name|uint32_t
name|rsrvd_1
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x20] Specifies the state of the CPU with reference to power modes. */
name|uint32_t
name|power_ctrl
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|power_status
decl_stmt|;
comment|/* [0x28]  */
name|uint32_t
name|resume_addr_l
decl_stmt|;
comment|/* [0x2c]  */
name|uint32_t
name|resume_addr_h
decl_stmt|;
name|uint32_t
name|rsrvd_2
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x40]  */
name|uint32_t
name|warm_rst_ctl
decl_stmt|;
name|uint32_t
name|rsrvd_3
decl_stmt|;
comment|/* [0x48]  */
name|uint32_t
name|rvbar_low
decl_stmt|;
comment|/* [0x4c]  */
name|uint32_t
name|rvbar_high
decl_stmt|;
comment|/* [0x50]  */
name|uint32_t
name|pmu_snapshot
decl_stmt|;
name|uint32_t
name|rsrvd_4
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x60]  */
name|uint32_t
name|cpu_msg_in
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|39
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_mc_pmu
block|{
comment|/* [0x0] PMU Global Control Register */
name|uint32_t
name|pmu_control
decl_stmt|;
comment|/* [0x4] PMU Global Control Register */
name|uint32_t
name|overflow
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|62
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_mc_pmu_counters
block|{
comment|/* [0x0] Counter Configuration Register */
name|uint32_t
name|cfg
decl_stmt|;
comment|/* [0x4] Counter Control Register */
name|uint32_t
name|cntl
decl_stmt|;
comment|/* [0x8] Counter Control Register */
name|uint32_t
name|low
decl_stmt|;
comment|/* [0xc] Counter Control Register */
name|uint32_t
name|high
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
name|al_nb_nb_version
block|{
comment|/* [0x0] Northbridge Revision */
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|rsrvd
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_sriov
block|{
comment|/* [0x0]  */
name|uint32_t
name|cpu_vmid
index|[
literal|4
index|]
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
name|al_nb_dram_channels
block|{
comment|/* [0x0]  */
name|uint32_t
name|dram_0_control
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x8]  */
name|uint32_t
name|dram_0_status
decl_stmt|;
name|uint32_t
name|rsrvd_1
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|ddr_int_cause
decl_stmt|;
name|uint32_t
name|rsrvd_2
decl_stmt|;
comment|/* [0x18]  */
name|uint32_t
name|ddr_cause_mask
decl_stmt|;
name|uint32_t
name|rsrvd_3
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|address_map
decl_stmt|;
name|uint32_t
name|rsrvd_4
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|reorder_id_mask_0
decl_stmt|;
comment|/* [0x34]  */
name|uint32_t
name|reorder_id_value_0
decl_stmt|;
comment|/* [0x38]  */
name|uint32_t
name|reorder_id_mask_1
decl_stmt|;
comment|/* [0x3c]  */
name|uint32_t
name|reorder_id_value_1
decl_stmt|;
comment|/* [0x40]  */
name|uint32_t
name|reorder_id_mask_2
decl_stmt|;
comment|/* [0x44]  */
name|uint32_t
name|reorder_id_value_2
decl_stmt|;
comment|/* [0x48]  */
name|uint32_t
name|reorder_id_mask_3
decl_stmt|;
comment|/* [0x4c]  */
name|uint32_t
name|reorder_id_value_3
decl_stmt|;
comment|/* [0x50]  */
name|uint32_t
name|mrr_control_status
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|43
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_ddr_0_mrr
block|{
comment|/* [0x0] Counter Configuration Register */
name|uint32_t
name|val
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_push_packet
block|{
comment|/* [0x0]  */
name|uint32_t
name|pp_config
decl_stmt|;
name|uint32_t
name|rsrvd_0
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x10]  */
name|uint32_t
name|pp_ext_awuser
decl_stmt|;
name|uint32_t
name|rsrvd_1
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x20]  */
name|uint32_t
name|pp_base_low
decl_stmt|;
comment|/* [0x24]  */
name|uint32_t
name|pp_base_high
decl_stmt|;
name|uint32_t
name|rsrvd_2
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x30]  */
name|uint32_t
name|pp_sel_awuser
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|51
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_nb_regs
block|{
name|struct
name|al_nb_global
name|global
decl_stmt|;
comment|/* [0x0] */
name|struct
name|al_nb_system_counter
name|system_counter
decl_stmt|;
comment|/* [0x1000] */
name|struct
name|al_nb_rams_control_misc
name|rams_control_misc
decl_stmt|;
comment|/* [0x1100] */
name|struct
name|al_nb_ca15_rams_control
name|ca15_rams_control
index|[
literal|5
index|]
decl_stmt|;
comment|/* [0x1200] */
name|uint32_t
name|rsrvd_0
index|[
literal|108
index|]
decl_stmt|;
name|struct
name|al_nb_semaphores
name|semaphores
index|[
literal|64
index|]
decl_stmt|;
comment|/* [0x1400] */
name|uint32_t
name|rsrvd_1
index|[
literal|320
index|]
decl_stmt|;
name|struct
name|al_nb_debug
name|debug
decl_stmt|;
comment|/* [0x1a00] */
name|uint32_t
name|rsrvd_2
index|[
literal|256
index|]
decl_stmt|;
name|struct
name|al_nb_cpun_config_status
name|cpun_config_status
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x2000] */
name|uint32_t
name|rsrvd_3
index|[
literal|1792
index|]
decl_stmt|;
name|struct
name|al_nb_mc_pmu
name|mc_pmu
decl_stmt|;
comment|/* [0x4000] */
name|struct
name|al_nb_mc_pmu_counters
name|mc_pmu_counters
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x4100] */
name|uint32_t
name|rsrvd_4
index|[
literal|160
index|]
decl_stmt|;
name|struct
name|al_nb_nb_version
name|nb_version
decl_stmt|;
comment|/* [0x4400] */
name|uint32_t
name|rsrvd_5
index|[
literal|126
index|]
decl_stmt|;
name|struct
name|al_nb_sriov
name|sriov
decl_stmt|;
comment|/* [0x4600] */
name|uint32_t
name|rsrvd_6
index|[
literal|120
index|]
decl_stmt|;
name|struct
name|al_nb_dram_channels
name|dram_channels
decl_stmt|;
comment|/* [0x4800] */
name|struct
name|al_nb_ddr_0_mrr
name|ddr_0_mrr
index|[
literal|9
index|]
decl_stmt|;
comment|/* [0x4900] */
name|uint32_t
name|rsrvd_7
index|[
literal|439
index|]
decl_stmt|;
name|uint32_t
name|rsrvd_8
index|[
literal|1024
index|]
decl_stmt|;
comment|/* [0x5000] */
name|struct
name|al_nb_push_packet
name|push_packet
decl_stmt|;
comment|/* [0x6000] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** CPUs_Config register ****/
comment|/* Disable broadcast of barrier onto system bus. Connect to Processor Cluster SYSBARDISABLE. */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_SYSBARDISABLE
value|(1<< 0)
comment|/* Enable broadcast of inner shareable transactions from CPUs. Connect to Processor Cluster BROADCASTINNER. */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_BROADCASTINNER
value|(1<< 1)
comment|/* Disable broadcast of cache maintenance system bus. Connect to Processor Cluster BROADCASTCACHEMAIN */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_BROADCASTCACHEMAINT
value|(1<< 2)
comment|/* Enable broadcast of outer shareable transactions from CPUs. Connect to Processor Cluster  BROADCASTOUTER. */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_BROADCASTOUTER
value|(1<< 3)
comment|/* Defines the internal CPU GIC operating frequency ratio with the main CPU clock. 0x0: 1:1 0x1: 1:2 0x2: 1:3 0x3: 1:4  Note: This is not in used with CA57 */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_PERIPHCLKEN_MASK
value|0x00000030
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_PERIPHCLKEN_SHIFT
value|4
comment|/* Disables the GIC CPU interface logic and routes the legacy nIRQ, nFIQ, nVIRQ, and nVFIQ signals directly to the processor: 0 Enable the GIC CPU interface logic. 1 Disable the GIC CPU interface logic. The processor only samples this signal as it exits reset. */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_GIC_DISABLE
value|(1<< 6)
comment|/* Disable L1 data cache and L2 snoop tag RAMs automatic invalidate on reset functionality  */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_DBG_L1_RESET_DISABLE
value|(1<< 7)
comment|/* Value read in the Cluster ID Affinity Level-1 field, bits[15:8], of the Multiprocessor Affinity Register (MPIDR). This signal is only sampled during reset of the processor. */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_CLUSTERIDAFF1_MASK
value|0x00FF0000
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_CLUSTERIDAFF1_SHIFT
value|16
comment|/* Value read in the Cluster ID Affinity Level-2 field, bits[23:16], of the Multiprocessor Affinity Register (MPIDR). This signal is only sampled during reset of the processor.. */
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_CLUSTERIDAFF2_MASK
value|0xFF000000
define|#
directive|define
name|NB_GLOBAL_CPUS_CONFIG_CLUSTERIDAFF2_SHIFT
value|24
comment|/**** CPUs_Secure register ****/
comment|/* DBGEN  */
define|#
directive|define
name|NB_GLOBAL_CPUS_SECURE_DBGEN
value|(1<< 0)
comment|/* NIDEN  */
define|#
directive|define
name|NB_GLOBAL_CPUS_SECURE_NIDEN
value|(1<< 1)
comment|/* SPIDEN  */
define|#
directive|define
name|NB_GLOBAL_CPUS_SECURE_SPIDEN
value|(1<< 2)
comment|/* SPNIDEN  */
define|#
directive|define
name|NB_GLOBAL_CPUS_SECURE_SPNIDEN
value|(1<< 3)
comment|/* Disable write access to some secure GIC registers */
define|#
directive|define
name|NB_GLOBAL_CPUS_SECURE_CFGSDISABLE
value|(1<< 4)
comment|/* Disable write access to some secure IOGIC registers */
define|#
directive|define
name|NB_GLOBAL_CPUS_SECURE_IOGIC_CFGSDISABLE
value|(1<< 5)
comment|/**** CPUs_Init_Control register ****/
comment|/* CPU Init Done Specifies which CPUs' inits are done and can exit poreset. By default, CPU0 only exits poreset when the CPUs cluster exits power-on-reset and then kicks other CPUs. If this bit is cleared for a specific CPU, setting it by primary CPU as part of the initialization process will initiate power-on-reset to this specific CPU. */
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_CONTROL_CPUS_INITDONE_MASK
value|0x0000000F
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_CONTROL_CPUS_INITDONE_SHIFT
value|0
comment|/* DBGPWRDNREQ Mask When CPU does not exist, its DBGPWRDNREQ must be asserted. If corresponding mask bit is set, the DBGPWDNREQ is deasserted. */
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_CONTROL_DBGPWRDNREQ_MASK_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_CONTROL_DBGPWRDNREQ_MASK_SHIFT
value|4
comment|/* Force CPU init power-on-reset exit. For debug purposes only. */
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_CONTROL_FORCE_CPUPOR_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_CONTROL_FORCE_CPUPOR_SHIFT
value|8
comment|/* Force dbgpwrdup signal high If dbgpwrdup is clear on the processor interface it indicates that the process debug resources are not available for APB access. */
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_CONTROL_FORCE_DBGPWRDUP_MASK
value|0x0000F000
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_CONTROL_FORCE_DBGPWRDUP_SHIFT
value|12
comment|/**** CPUs_Init_Status register ****/
comment|/* Specifies which CPUs are enabled in the device configuration. sample at rst_cpus_exist[3:0] reset strap. */
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_STATUS_CPUS_EXIST_MASK
value|0x0000000F
define|#
directive|define
name|NB_GLOBAL_CPUS_INIT_STATUS_CPUS_EXIST_SHIFT
value|0
comment|/**** NB_Int_Cause register ****/
comment|/*  * Each bit corresponds to an IRQ.  * value is 1 for level irq, 0 for trigger irq  * Level IRQ indices: 12-13, 23, 24, 26-29  */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_LEVEL_IRQ_MASK
value|0x3D803000
comment|/* Cross trigger interrupt  */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_NCTIIRQ_MASK
value|0x0000000F
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_NCTIIRQ_SHIFT
value|0
comment|/* Communications channel receive. Receive portion of Data Transfer Register full flag */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_COMMRX_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_COMMRX_SHIFT
value|4
comment|/* Communication channel transmit. Transmit portion of Data Transfer Register empty flag. */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_COMMTX_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_COMMTX_SHIFT
value|8
comment|/* Reserved, read undefined must write as zeros. */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_RESERVED_15_15
value|(1<< 15)
comment|/* Error indicator for AXI write transactions with a BRESP error condition. Writing 0 to bit[29] of the L2ECTLR clears the error indicator connected to CA15 nAXIERRIRQ. */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_CPU_AXIERRIRQ
value|(1<< 16)
comment|/* Error indicator for: L2 RAM double-bit ECC error, illegal writes to the GIC memory-map region. */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_CPU_INTERRIRQ
value|(1<< 17)
comment|/* Coherent fabric error summary interrupt */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_ACF_ERRORIRQ
value|(1<< 18)
comment|/* DDR Controller ECC Correctable error summary interrupt */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_MCTL_ECC_CORR_ERR
value|(1<< 19)
comment|/* DDR Controller ECC Uncorrectable error summary interrupt */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_MCTL_ECC_UNCORR_ERR
value|(1<< 20)
comment|/* DRAM parity error interrupt */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_MCTL_PARITY_ERR
value|(1<< 21)
comment|/* Reserved, not functional */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_MCTL_WDATARAM_PAR
value|(1<< 22)
comment|/* Error cause summary interrupt */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_ERR_CAUSE_SUM_A0
value|(1<< 23)
comment|/* SB PoS error */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_SB_POS_ERR
value|(1<< 24)
comment|/* Received msix is not mapped to local GIC or IO-GIC spin */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_MSIX_ERR_INT_M0
value|(1<< 25)
comment|/* Coresight timestamp overflow */
define|#
directive|define
name|NB_GLOBAL_NB_INT_CAUSE_CORESIGHT_TS_OVERFLOW_M0
value|(1<< 26)
comment|/**** SEV_Int_Cause register ****/
comment|/* SMMU 0/1 global non-secure fault interrupt */
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_SMMU_GBL_FLT_IRPT_NS_MASK
value|0x00000003
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_SMMU_GBL_FLT_IRPT_NS_SHIFT
value|0
comment|/* SMMU 0/1 non-secure context interrupt */
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_SMMU_CXT_IRPT_NS_MASK
value|0x0000000C
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_SMMU_CXT_IRPT_NS_SHIFT
value|2
comment|/* SMMU0/1 Non-secure configuration access fault interrupt */
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_SMMU_CFG_FLT_IRPT_S_MASK
value|0x00000030
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_SMMU_CFG_FLT_IRPT_S_SHIFT
value|4
comment|/* Reserved. Read undefined; must write as zeros. */
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_RESERVED_11_6_MASK
value|0x00000FC0
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_RESERVED_11_6_SHIFT
value|6
comment|/* Reserved. Read undefined; must write as zeros. */
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_RESERVED_31_20_MASK
value|0xFFF00000
define|#
directive|define
name|NB_GLOBAL_SEV_INT_CAUSE_RESERVED_31_20_SHIFT
value|20
comment|/**** PMUs_Int_Cause register ****/
comment|/* CPUs PMU Overflow interrupt */
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_CPUS_OVFL_MASK
value|0x0000000F
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_CPUS_OVFL_SHIFT
value|0
comment|/* Northbridge PMU overflow */
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_NB_OVFL
value|(1<< 4)
comment|/* Memory Controller PMU overflow */
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_MCTL_OVFL
value|(1<< 5)
comment|/* Coherency Interconnect PMU overflow */
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_CCI_OVFL_MASK
value|0x000007C0
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_CCI_OVFL_SHIFT
value|6
comment|/* Coherency Interconnect PMU overflow */
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_SMMU_OVFL_MASK
value|0x00001800
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_SMMU_OVFL_SHIFT
value|11
comment|/* Reserved. Read undefined; must write as zeros. */
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_RESERVED_23_13_MASK
value|0x00FFE000
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_RESERVED_23_13_SHIFT
value|13
comment|/* Southbridge PMUs overflow */
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_SB_PMUS_OVFL_MASK
value|0xFF000000
define|#
directive|define
name|NB_GLOBAL_PMUS_INT_CAUSE_SB_PMUS_OVFL_SHIFT
value|24
comment|/**** CPUs_Hold_Reset register ****/
comment|/* Shared L2 memory system, interrupt controller and timer logic reset. Reset is applied only when all processors are in STNDBYWFI state. */
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_L2RESET
value|(1<< 0)
comment|/* Shared debug domain reset */
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_PRESETDBG
value|(1<< 1)
comment|/* Individual CPU debug, PTM, watchpoint and breakpoint logic reset */
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_CPU_DBGRESET_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_CPU_DBGRESET_SHIFT
value|4
comment|/* Individual CPU core and VFP/NEON logic reset. Reset is applied only when specific CPU is in STNDBYWFI state. */
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_CPU_CORERESET_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_CPU_CORERESET_SHIFT
value|8
comment|/* Individual CPU por-on-reset. Reset is applied only when specific CPU is in STNDBYWFI state. */
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_CPU_PORESET_MASK
value|0x0000F000
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_CPU_PORESET_SHIFT
value|12
comment|/* Wait for interrupt mask. If set, reset is applied without waiting for the specified CPU's STNDBYWFI state. */
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_WFI_MASK_MASK
value|0x000F0000
define|#
directive|define
name|NB_GLOBAL_CPUS_HOLD_RESET_WFI_MASK_SHIFT
value|16
comment|/**** CPUs_Software_Reset register ****/
comment|/* Write 1. Apply the software reset. */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_SWRESET_REQ
value|(1<< 0)
comment|/* Defines the level of software reset. 0x0 - cpu_core: Individual CPU core reset. 0x1 - cpu_poreset: Individual CPU power-on-reset. 0x2 - cpu_dbg: Individual CPU debug reset. 0x3 - cluster_no_dbg: A Cluster reset puts each core into core reset (no dbg) and also resets the interrupt controller and L2 logic. 0x4 - cluster: A Cluster reset puts each core into power-on-reset and also resets the interrupt controller and L2 logic. Debug is active. 0x5 - cluster_poreset: A Cluster power-on-reset puts each core into power-on-reset and also resets the interrupt controller and L2 logic. This include the cluster debug logic.  */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_MASK
value|0x0000000E
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_SHIFT
value|1
comment|/* Individual CPU core reset. */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_CPU_CORE
define|\
value|(0x0<< NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* Individual CPU power-on-reset. */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_CPU_PORESET
define|\
value|(0x1<< NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* Individual CPU debug reset. */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_CPU_DBG
define|\
value|(0x2<< NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* A Cluster reset puts each core into core reset (no dbg) and a ... */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_CLUSTER_NO_DBG
define|\
value|(0x3<< NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* A Cluster reset puts each core into power-on-reset and also r ... */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_CLUSTER
define|\
value|(0x4<< NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* A Cluster power-on-reset puts each core into power-on-reset a ... */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_CLUSTER_PORESET
define|\
value|(0x5<< NB_GLOBAL_CPUS_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* Defines which cores to reset when no cluster_poreset is requested. */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_CORES_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_CORES_SHIFT
value|4
comment|/* CPUn wait for interrupt enable. Defines which CPU WFI indication to wait for before applying the software reset. */
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_WFI_MASK_MASK
value|0x000F0000
define|#
directive|define
name|NB_GLOBAL_CPUS_SOFTWARE_RESET_WFI_MASK_SHIFT
value|16
comment|/**** WD_Timer0_Reset register ****/
comment|/* Shared L2 memory system, interrupt controller and timer logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER0_RESET_L2RESET
value|(1<< 0)
comment|/* Shared debug domain reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER0_RESET_PRESETDBG
value|(1<< 1)
comment|/* Individual CPU debug PTM, watchpoint and breakpoint logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER0_RESET_CPU_DBGRESET_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_WD_TIMER0_RESET_CPU_DBGRESET_SHIFT
value|4
comment|/* Individual CPU core and VFP/NEON logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER0_RESET_CPU_CORERESET_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_WD_TIMER0_RESET_CPU_CORERESET_SHIFT
value|8
comment|/* Individual CPU por-on-reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER0_RESET_CPU_PORESET_MASK
value|0x0000F000
define|#
directive|define
name|NB_GLOBAL_WD_TIMER0_RESET_CPU_PORESET_SHIFT
value|12
comment|/**** WD_Timer1_Reset register ****/
comment|/* Shared L2 memory system, interrupt controller and timer logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER1_RESET_L2RESET
value|(1<< 0)
comment|/* Shared debug domain reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER1_RESET_PRESETDBG
value|(1<< 1)
comment|/* Individual CPU debug PTM, watchpoint and breakpoint logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER1_RESET_CPU_DBGRESET_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_WD_TIMER1_RESET_CPU_DBGRESET_SHIFT
value|4
comment|/* Individual CPU core and VFP/NEON logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER1_RESET_CPU_CORERESET_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_WD_TIMER1_RESET_CPU_CORERESET_SHIFT
value|8
comment|/* Individual CPU por-on-reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER1_RESET_CPU_PORESET_MASK
value|0x0000F000
define|#
directive|define
name|NB_GLOBAL_WD_TIMER1_RESET_CPU_PORESET_SHIFT
value|12
comment|/**** WD_Timer2_Reset register ****/
comment|/* Shared L2 memory system, interrupt controller and timer logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER2_RESET_L2RESET
value|(1<< 0)
comment|/* Shared debug domain reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER2_RESET_PRESETDBG
value|(1<< 1)
comment|/* Individual CPU debug, PTM, watchpoint and breakpoint logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER2_RESET_CPU_DBGRESET_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_WD_TIMER2_RESET_CPU_DBGRESET_SHIFT
value|4
comment|/* Individual CPU core and VFP/NEON logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER2_RESET_CPU_CORERESET_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_WD_TIMER2_RESET_CPU_CORERESET_SHIFT
value|8
comment|/* Individual CPU por-on-reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER2_RESET_CPU_PORESET_MASK
value|0x0000F000
define|#
directive|define
name|NB_GLOBAL_WD_TIMER2_RESET_CPU_PORESET_SHIFT
value|12
comment|/**** WD_Timer3_Reset register ****/
comment|/* Shared L2 memory system, interrupt controller and timer logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER3_RESET_L2RESET
value|(1<< 0)
comment|/* Shared debug domain reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER3_RESET_PRESETDBG
value|(1<< 1)
comment|/* Individual CPU debug, PTM, watchpoint and breakpoint logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER3_RESET_CPU_DBGRESET_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_WD_TIMER3_RESET_CPU_DBGRESET_SHIFT
value|4
comment|/* Individual CPU core and VFP/NEON logic reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER3_RESET_CPU_CORERESET_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_WD_TIMER3_RESET_CPU_CORERESET_SHIFT
value|8
comment|/* Individual CPU por-on-reset */
define|#
directive|define
name|NB_GLOBAL_WD_TIMER3_RESET_CPU_PORESET_MASK
value|0x0000F000
define|#
directive|define
name|NB_GLOBAL_WD_TIMER3_RESET_CPU_PORESET_SHIFT
value|12
comment|/**** DDRC_Hold_Reset register ****/
comment|/* DDR Control and PHY memory mapped registers reset control 0 - Reset is deasserted. 1 - Reset is asserted (active). */
define|#
directive|define
name|NB_GLOBAL_DDRC_HOLD_RESET_APB_SYNC_RESET
value|(1<< 0)
comment|/* DDR Control Core reset control 0 - Reset is deasserted. 1 - Reset is asserted. This field must be set to 0 to start the initialization process after configuring the DDR Controller registers. */
define|#
directive|define
name|NB_GLOBAL_DDRC_HOLD_RESET_CORE_SYNC_RESET
value|(1<< 1)
comment|/* DDR Control AXI Interface reset control 0 - Reset is deasserted. 1 - Reset is asserted. This field must not be set to 0 while core_sync_reset is set to 1. */
define|#
directive|define
name|NB_GLOBAL_DDRC_HOLD_RESET_AXI_SYNC_RESET
value|(1<< 2)
comment|/* DDR PUB Controller reset control 0 - Reset is deasserted. 1 - Reset is asserted. This field must be set to 0 to start the initialization process after configuring the PUB Controller registers. */
define|#
directive|define
name|NB_GLOBAL_DDRC_HOLD_RESET_PUB_CTL_SYNC_RESET
value|(1<< 3)
comment|/* DDR PUB SDR Controller reset control 0 - Reset is deasserted. 1 - Reset is asserted. This field must be set to 0 to start the initialization process after configuring the PUB Controller registers. */
define|#
directive|define
name|NB_GLOBAL_DDRC_HOLD_RESET_PUB_SDR_SYNC_RESET
value|(1<< 4)
comment|/* DDR PHY reset control 0 - Reset is deasserted. 1 - Reset is asserted.  */
define|#
directive|define
name|NB_GLOBAL_DDRC_HOLD_RESET_PHY_SYNC_RESET
value|(1<< 5)
comment|/* Memory initialization input to DDR SRAM for parity check support */
define|#
directive|define
name|NB_GLOBAL_DDRC_HOLD_RESET_DDR_UNIT_MEM_INIT
value|(1<< 6)
comment|/**** Fabric_Software_Reset register ****/
comment|/* Write 1 apply the software reset. */
define|#
directive|define
name|NB_GLOBAL_FABRIC_SOFTWARE_RESET_SWRESET_REQ
value|(1<< 0)
comment|/* Defines the level of software reset: 0x0 -  fabric: Fabric reset 0x1 - gic: GIC reset 0x2 - smmu: SMMU reset */
define|#
directive|define
name|NB_GLOBAL_FABRIC_SOFTWARE_RESET_LEVEL_MASK
value|0x0000000E
define|#
directive|define
name|NB_GLOBAL_FABRIC_SOFTWARE_RESET_LEVEL_SHIFT
value|1
comment|/* Fabric reset */
define|#
directive|define
name|NB_GLOBAL_FABRIC_SOFTWARE_RESET_LEVEL_FABRIC
define|\
value|(0x0<< NB_GLOBAL_FABRIC_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* GIC reset */
define|#
directive|define
name|NB_GLOBAL_FABRIC_SOFTWARE_RESET_LEVEL_GIC
define|\
value|(0x1<< NB_GLOBAL_FABRIC_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* SMMU reset */
define|#
directive|define
name|NB_GLOBAL_FABRIC_SOFTWARE_RESET_LEVEL_SMMU
define|\
value|(0x2<< NB_GLOBAL_FABRIC_SOFTWARE_RESET_LEVEL_SHIFT)
comment|/* CPUn waiting for interrupt enable. Defines which CPU WFI indication to wait before applying the software reset. */
define|#
directive|define
name|NB_GLOBAL_FABRIC_SOFTWARE_RESET_WFI_MASK_MASK
value|0x000F0000
define|#
directive|define
name|NB_GLOBAL_FABRIC_SOFTWARE_RESET_WFI_MASK_SHIFT
value|16
comment|/**** CPUs_Power_Ctrl register ****/
comment|/* L2 WFI enable When all the processors are in WFI mode or powered-down, the shared L2 memory system Power Management controller resumes clock on any interrupt. Power management controller resumes clock on snoop request. NOT IMPLEMENTED */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2WFI_EN
value|(1<< 0)
comment|/* L2 WFI status */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2WFI_STATUS
value|(1<< 1)
comment|/* L2 RAMs Power Down Power down the L2 RAMs. L2 caches must be flushed prior to entering this state. */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2RAMS_PWRDN_EN
value|(1<< 2)
comment|/* L2 RAMs power down status */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2RAMS_PWRDN_STATUS
value|(1<< 3)
comment|/* CPU state condition to enable L2 RAM power down 0 - Power down 1 - WFI NOT IMPLEMENTED */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2RAMS_PWRDN_CPUS_STATE_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2RAMS_PWRDN_CPUS_STATE_SHIFT
value|4
comment|/* Enable external debugger over power-down. Provides support for external debug over power down. If any or all of the processors are powered down, the SoC can still use the debug facilities if the debug PCLKDBG domain is powered up. */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_EXT_DEBUGGER_OVER_PD_EN
value|(1<< 8)
comment|/* L2 hardware flush request. This signal indicates: 0 L2 hardware flush request is not asserted. flush is performed by SW 1 L2 hardware flush request is asserted by power management block as part of cluster rams power down flow. HW starts L2 flush flow when all CPUs are in WFI */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2FLUSH_EN
value|(1<< 9)
comment|/* Force wakeup the CPU in L2RAM power down INTERNAL DEBUG PURPOSE ONLY */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_FORCE_CPUS_OK_PWRUP
value|(1<< 27)
comment|/* L2 RAMs power down SM status */
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2RAMS_PWRDN_SM_STATUS_MASK
value|0xF0000000
define|#
directive|define
name|NB_GLOBAL_CPUS_POWER_CTRL_L2RAMS_PWRDN_SM_STATUS_SHIFT
value|28
comment|/**** ACF_Base_High register ****/
comment|/* Coherency Fabric registers base [39:32]. */
define|#
directive|define
name|NB_GLOBAL_ACF_BASE_HIGH_BASE_39_32_MASK
value|0x000000FF
define|#
directive|define
name|NB_GLOBAL_ACF_BASE_HIGH_BASE_39_32_SHIFT
value|0
comment|/* Coherency Fabric registers base [31:15] */
define|#
directive|define
name|NB_GLOBAL_ACF_BASE_LOW_BASED_31_15_MASK
value|0xFFFF8000
define|#
directive|define
name|NB_GLOBAL_ACF_BASE_LOW_BASED_31_15_SHIFT
value|15
comment|/**** ACF_Control_Override register ****/
comment|/* Override the AWCACHE[0] and ARCACHE[0] outputs to be non-bufferable. One bit exists for each master interface. Connected to BUFFERABLEOVERRIDE[2:0] */
define|#
directive|define
name|NB_GLOBAL_ACF_CONTROL_OVERRIDE_BUFFOVRD_MASK
value|0x00000007
define|#
directive|define
name|NB_GLOBAL_ACF_CONTROL_OVERRIDE_BUFFOVRD_SHIFT
value|0
comment|/* Overrides the ARQOS and AWQOS input signals. One bit exists for each slave interface. Connected to QOSOVERRIDE[4:0] */
define|#
directive|define
name|NB_GLOBAL_ACF_CONTROL_OVERRIDE_QOSOVRD_MASK
value|0x000000F8
define|#
directive|define
name|NB_GLOBAL_ACF_CONTROL_OVERRIDE_QOSOVRD_SHIFT
value|3
comment|/* If LOW, then AC requests are never issued on the corresponding slave interface. One bit exists for each slave interface. Connected to ACCHANNELEN[4:0]. */
define|#
directive|define
name|NB_GLOBAL_ACF_CONTROL_OVERRIDE_ACE_CH_EN_MASK
value|0x00001F00
define|#
directive|define
name|NB_GLOBAL_ACF_CONTROL_OVERRIDE_ACE_CH_EN_SHIFT
value|8
comment|/* Internal register: Enables 4k hazard of post-barrier vs pre-barrier transactions. Otherwise, 64B hazard granularity is applied. */
define|#
directive|define
name|NB_GLOBAL_ACF_CONTROL_OVERRIDE_DMB_4K_HAZARD_EN
value|(1<< 13)
comment|/**** LGIC_Base_High register ****/
comment|/* GIC registers base [39:32]. This value is sampled into the CP15 Configuration Base Address Register (CBAR) at reset. */
define|#
directive|define
name|NB_GLOBAL_LGIC_BASE_HIGH_BASE_39_32_MASK
value|0x000000FF
define|#
directive|define
name|NB_GLOBAL_LGIC_BASE_HIGH_BASE_39_32_SHIFT
value|0
define|#
directive|define
name|NB_GLOBAL_LGIC_BASE_HIGH_BASE_43_32_MASK_PKR
value|0x00000FFF
define|#
directive|define
name|NB_GLOBAL_LGIC_BASE_HIGH_BASE_43_32_SHIFT_PKR
value|0
comment|/* GIC registers base [31:15]. This value is sampled into the CP15 Configuration Base Address Register (CBAR) at reset */
define|#
directive|define
name|NB_GLOBAL_LGIC_BASE_LOW_BASED_31_15_MASK
value|0xFFFF8000
define|#
directive|define
name|NB_GLOBAL_LGIC_BASE_LOW_BASED_31_15_SHIFT
value|15
comment|/**** IOGIC_Base_High register ****/
comment|/* IOGIC registers base [39:32] */
define|#
directive|define
name|NB_GLOBAL_IOGIC_BASE_HIGH_BASE_39_32_MASK
value|0x000000FF
define|#
directive|define
name|NB_GLOBAL_IOGIC_BASE_HIGH_BASE_39_32_SHIFT
value|0
comment|/* IOGIC registers base [31:15] */
define|#
directive|define
name|NB_GLOBAL_IOGIC_BASE_LOW_BASED_31_15_MASK
value|0xFFFF8000
define|#
directive|define
name|NB_GLOBAL_IOGIC_BASE_LOW_BASED_31_15_SHIFT
value|15
comment|/**** IO_Wr_Split_Control register ****/
comment|/* Write splitters bypass. [0] Splitter 0 bypass enable [1] Splitter 1 bypass enable */
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_BYPASS_MASK
value|0x00000003
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_BYPASS_SHIFT
value|0
comment|/* Write splitters store and forward. If store and forward is disabled, splitter does not check non-active BE in the middle of a transaction. */
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_ST_FW_MASK
value|0x0000000C
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_ST_FW_SHIFT
value|2
comment|/* Write splitters unmodify snoop type. Disables modifying snoop type from Clean& Invalidate to Invalidate when conditions enable it. Only split operation to 64B is applied. */
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_UNMODIFY_SNP_MASK
value|0x00000030
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_UNMODIFY_SNP_SHIFT
value|4
comment|/* Write splitters unsplit non-coherent access. Disables splitting of non-coherent access to cache-line chunks. */
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_UNSPLIT_NOSNP_MASK
value|0x000000C0
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_UNSPLIT_NOSNP_SHIFT
value|6
comment|/* Write splitter rate limit. */
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR0_SPLT_RATE_LIMIT_MASK
value|0x00001F00
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR0_SPLT_RATE_LIMIT_SHIFT
value|8
comment|/* Write splitter rate limit  */
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR1_SPLT_RATE_LIMIT_MASK
value|0x0003E000
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR1_SPLT_RATE_LIMIT_SHIFT
value|13
comment|/* Write splitters 64bit remap enable Enables remapping of 64bit transactions */
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_REMAP_64BIT_EN_MASK
value|0x000C0000
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_REMAP_64BIT_EN_SHIFT
value|18
comment|/* Clear is not supported. This bit was changed to wr_pack_disable. In default mode, AWADDR waits for WDATA. */
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_CLEAR_MASK
value|0xC0000000
define|#
directive|define
name|NB_GLOBAL_IO_WR_SPLIT_CONTROL_WR_SPLT_CLEAR_SHIFT
value|30
comment|/**** IO_Rd_ROB_Control register ****/
comment|/* Read ROB Bypass [0] Rd ROB 0 bypass enable. [1] Rd ROB 1 bypass enable. */
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD_ROB_BYPASS_MASK
value|0x00000003
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD_ROB_BYPASS_SHIFT
value|0
comment|/* Read ROB in order. Return data in the order of request acceptance. */
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD_ROB_INORDER_MASK
value|0x0000000C
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD_ROB_INORDER_SHIFT
value|2
comment|/* Read ROB response rate When enabled drops one cycle from back to back read responses */
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD_ROB_RSP_RATE_MASK
value|0x00000030
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD_ROB_RSP_RATE_SHIFT
value|4
comment|/* Read splitter rate limit */
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD0_ROB_RATE_LIMIT_MASK
value|0x00001F00
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD0_ROB_RATE_LIMIT_SHIFT
value|8
comment|/* Read splitter rate limit */
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD1_ROB_RATE_LIMIT_MASK
value|0x0003E000
define|#
directive|define
name|NB_GLOBAL_IO_RD_ROB_CONTROL_RD1_ROB_RATE_LIMIT_SHIFT
value|13
comment|/**** SB_PoS_Error_Log_1 register ****/
comment|/* Error Log 1 [7:0] address_high [16:8] request id [18:17] bresp  */
define|#
directive|define
name|NB_GLOBAL_SB_POS_ERROR_LOG_1_ERR_LOG_MASK
value|0x7FFFFFFF
define|#
directive|define
name|NB_GLOBAL_SB_POS_ERROR_LOG_1_ERR_LOG_SHIFT
value|0
comment|/* Valid logged error Set on SB PoS error occurrence on capturing the error information. Subsequent errors will not be captured until the valid bit is cleared. The SB PoS reports on write errors. When valid, an interrupt is set in the NB Cause Register. */
define|#
directive|define
name|NB_GLOBAL_SB_POS_ERROR_LOG_1_VALID
value|(1<< 31)
comment|/**** MSIx_Error_Log register ****/
comment|/* Error Log Corresponds to MSIx address message [30:0]. */
define|#
directive|define
name|NB_GLOBAL_MSIX_ERROR_LOG_ERR_LOG_MASK
value|0x7FFFFFFF
define|#
directive|define
name|NB_GLOBAL_MSIX_ERROR_LOG_ERR_LOG_SHIFT
value|0
comment|/* Valid logged error */
define|#
directive|define
name|NB_GLOBAL_MSIX_ERROR_LOG_VALID
value|(1<< 31)
comment|/**** Error_Cause register ****/
comment|/* Received msix is not mapped to local GIC or IO-GIC spin */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_MSIX_ERR_INT
value|(1<< 2)
comment|/* Coresight timestamp overflow */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_CORESIGHT_TS_OVERFLOW
value|(1<< 3)
comment|/* Write data parity error from SB channel 0. */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_SB0_WRDATA_PERR
value|(1<< 4)
comment|/* Write data parity error from SB channel 1. */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_SB1_WRDATA_PERR
value|(1<< 5)
comment|/* Read data parity error from SB slaves. */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_SB_SLV_RDATA_PERR
value|(1<< 6)
comment|/* Local GIC uncorrectable ECC error */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_LOCAL_GIC_ECC_FATAL
value|(1<< 7)
comment|/* SB PoS error */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_SB_POS_ERR
value|(1<< 8)
comment|/* Coherent fabric error summary interrupt */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_ACF_ERRORIRQ
value|(1<< 9)
comment|/* Error indicator for AXI write transactions with a BRESP error condition. Writing 0 to bit[29] of the L2ECTLR clears the error indicator connected to CA15 nAXIERRIRQ. */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_CPU_AXIERRIRQ
value|(1<< 10)
comment|/* Error indicator for: L2 RAM double-bit ECC error, illegal writes to the GIC memory-map region. */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_CPU_INTERRIRQ
value|(1<< 12)
comment|/* DDR cause summery interrupt */
define|#
directive|define
name|NB_GLOBAL_ERROR_CAUSE_DDR_CAUSE_SUM
value|(1<< 14)
comment|/**** QoS_Peak_Control register ****/
comment|/* Peak Read Low Threshold When the number of outstanding read transactions from SB masters is below this value, the CPU is assigned high-priority QoS.  */
define|#
directive|define
name|NB_GLOBAL_QOS_PEAK_CONTROL_PEAK_RD_L_THRESHOLD_MASK
value|0x0000007F
define|#
directive|define
name|NB_GLOBAL_QOS_PEAK_CONTROL_PEAK_RD_L_THRESHOLD_SHIFT
value|0
comment|/* Peak Read High Threshold When the number of outstanding read transactions from SB masters exceeds this value, the CPU is assigned high-priority QoS.  */
define|#
directive|define
name|NB_GLOBAL_QOS_PEAK_CONTROL_PEAK_RD_H_THRESHOLD_MASK
value|0x00007F00
define|#
directive|define
name|NB_GLOBAL_QOS_PEAK_CONTROL_PEAK_RD_H_THRESHOLD_SHIFT
value|8
comment|/* Peak Write Low Threshold When the number of outstanding write transactions from SB masters is below this value, the CPU is assigned high-priority QoS  */
define|#
directive|define
name|NB_GLOBAL_QOS_PEAK_CONTROL_PEAK_WR_L_THRESHOLD_MASK
value|0x007F0000
define|#
directive|define
name|NB_GLOBAL_QOS_PEAK_CONTROL_PEAK_WR_L_THRESHOLD_SHIFT
value|16
comment|/* Peak Write High Threshold When the number of outstanding write transactions from SB masters exceeds this value, the CPU is assigned high-priority QoS.  */
define|#
directive|define
name|NB_GLOBAL_QOS_PEAK_CONTROL_PEAK_WR_H_THRESHOLD_MASK
value|0x7F000000
define|#
directive|define
name|NB_GLOBAL_QOS_PEAK_CONTROL_PEAK_WR_H_THRESHOLD_SHIFT
value|24
comment|/**** QoS_Set_Control register ****/
comment|/* CPU Low priority Read QoS */
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_CPU_LP_ARQOS_MASK
value|0x0000000F
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_CPU_LP_ARQOS_SHIFT
value|0
comment|/* CPU High priority Read QoS */
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_CPU_HP_ARQOS_MASK
value|0x000000F0
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_CPU_HP_ARQOS_SHIFT
value|4
comment|/* CPU Low priority Write QoS */
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_CPU_LP_AWQOS_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_CPU_LP_AWQOS_SHIFT
value|8
comment|/* CPU High priority Write QoS */
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_CPU_HP_AWQOS_MASK
value|0x0000F000
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_CPU_HP_AWQOS_SHIFT
value|12
comment|/* SB Low priority Read QoS */
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_SB_LP_ARQOS_MASK
value|0x000F0000
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_SB_LP_ARQOS_SHIFT
value|16
comment|/* SB Low-priority Write QoS */
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_SB_LP_AWQOS_MASK
value|0x00F00000
define|#
directive|define
name|NB_GLOBAL_QOS_SET_CONTROL_SB_LP_AWQOS_SHIFT
value|20
comment|/**** DDR_QoS register ****/
comment|/* High Priority Read Threshold Limits the number of outstanding high priority reads in the system through the memory controller. This parameter is programmed in conjunction with number of outstanding high priority reads supported by the DDR controller. */
define|#
directive|define
name|NB_GLOBAL_DDR_QOS_HIGH_PRIO_THRESHOLD_MASK
value|0x0000007F
define|#
directive|define
name|NB_GLOBAL_DDR_QOS_HIGH_PRIO_THRESHOLD_SHIFT
value|0
comment|/* DDR Low Priority QoS Fabric priority below this value is mapped to DDR low priority queue. */
define|#
directive|define
name|NB_GLOBAL_DDR_QOS_LP_QOS_MASK
value|0x00000F00
define|#
directive|define
name|NB_GLOBAL_DDR_QOS_LP_QOS_SHIFT
value|8
comment|/**** ACF_Misc register ****/
comment|/* Disable DDR Write Chop Performance optimization feature to chop non-active data beats to the DDR. */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_DDR_WR_CHOP_DIS
value|(1<< 0)
comment|/* Disable SB-2-SB path through NB fabric. */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_SB2SB_PATH_DIS
value|(1<< 1)
comment|/* Disable ETR tracing to non-DDR. */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_ETR2SB_PATH_DIS
value|(1<< 2)
comment|/* Disable ETR tracing to non-DDR. */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_CPU2MSIX_DIS
value|(1<< 3)
comment|/* Disable CPU generation of MSIx By default, the CPU can set any MSIx message results by setting any SPIn bit in the local and IO-GIC. */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_MSIX_TERMINATE_DIS
value|(1<< 4)
comment|/* Disable snoop override for MSIx By default, an MSIx transaction is downgraded to non-coherent. */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_MSIX_SNOOPOVRD_DIS
value|(1<< 5)
comment|/* POS bypass */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_POS_BYPASS
value|(1<< 6)
comment|/* PoS ReadStronglyOrdered enable SO read forces flushing of all prior writes */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_POS_RSO_EN
value|(1<< 7)
comment|/* WRAP to INC transfer enable */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_POS_WRAP2INC
value|(1<< 8)
comment|/* PoS DSB flush Disable On DSB from CPU, PoS blocks the progress of post-barrier reads and writes until all pre-barrier writes have been completed. */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_POS_DSB_FLUSH_DIS
value|(1<< 9)
comment|/* PoS DMB Flush Disable On DMB from CPU, the PoS blocks the progress of post-barrier non-buffereable reads or writes when there are outstanding non-bufferable writes that have not yet been completed. Other access types are  hazard check against the pre-barrier requests. */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_POS_DMB_FLUSH_DIS
value|(1<< 10)
comment|/* change DMB functionality to DSB (block and drain) */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_POS_DMB_TO_DSB_EN
value|(1<< 11)
comment|/* Disable write after read stall when accessing IO fabric slaves.  */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_M0_WAR_STALL_DIS
value|(1<< 12)
comment|/* Disable write after read stall when accessing DDR  */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_M1_WAR_STALL_DIS
value|(1<< 13)
comment|/* Disable counter (wait 1000 NB cycles) before applying PoS enable/disable configuration */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_POS_CONFIG_CNT_DIS
value|(1<< 14)
comment|/* Disable wr spliter A0 bug fixes */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_WRSPLT_ALPINE_M0_MODE
value|(1<< 16)
comment|/* Disable wr spliter PKR bug fixes */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_WRSPLT_ALPINE_A0_MODE
value|(1<< 17)
comment|/* Override the address parity calucation for write transactions going to IO-fabric */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_NB_NIC_AWADDR_PAR_OVRD
value|(1<< 18)
comment|/* Override the data parity calucation for write transactions going to IO-fabric */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_NB_NIC_WDATA_PAR_OVRD
value|(1<< 19)
comment|/* Override the address parity calucation for read transactions going to IO-fabric */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_NB_NIC_ARADDR_PAR_OVRD
value|(1<< 20)
comment|/* Halts CPU AXI interface (Ar/Aw channels), not allowing the CPU to send additional transactions */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_CPU_AXI_HALT
value|(1<< 23)
comment|/* Disable early arbar termination when fabric write buffer is enabled.  */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_CCIWB_EARLY_ARBAR_TERM_DIS
value|(1<< 24)
comment|/* Enable wire interrupts connectivity to IO-GIC IRQs */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_IOGIC_CHIP_SPI_EN
value|(1<< 25)
comment|/* Enable DMB flush request to NB to SB PoS when barrier is terminted inside the processor cluster */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_CPU_DSB_FLUSH_DIS
value|(1<< 26)
comment|/* Enable DMB flush request to NB to SB PoS when barrier is terminted inside the processor cluster */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_CPU_DMB_FLUSH_DIS
value|(1<< 27)
comment|/* Peakrock only: remap CPU address above 40 bits to Slave Error INTERNAL  */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_ADDR43_40_REMAP_DIS
value|(1<< 28)
comment|/* Enable CPU WriteUnique to WriteNoSnoop trasform */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_CPU_WU2WNS_EN
value|(1<< 29)
comment|/* Disable device after device check */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_WR_POS_DEV_AFTER_DEV_DIS
value|(1<< 30)
comment|/* Disable wrap to inc on write */
define|#
directive|define
name|NB_GLOBAL_ACF_MISC_WR_INC2WRAP_EN
value|(1<< 31)
comment|/**** Config_Bus_Control register ****/
comment|/* Write slave error enable */
define|#
directive|define
name|NB_GLOBAL_CONFIG_BUS_CONTROL_WR_SLV_ERR_EN
value|(1<< 0)
comment|/* Write decode error enable */
define|#
directive|define
name|NB_GLOBAL_CONFIG_BUS_CONTROL_WR_DEC_ERR_EN
value|(1<< 1)
comment|/* Read slave error enable */
define|#
directive|define
name|NB_GLOBAL_CONFIG_BUS_CONTROL_RD_SLV_ERR_EN
value|(1<< 2)
comment|/* Read decode error enable */
define|#
directive|define
name|NB_GLOBAL_CONFIG_BUS_CONTROL_RD_DEC_ERR_EN
value|(1<< 3)
comment|/* Ignore Write ID */
define|#
directive|define
name|NB_GLOBAL_CONFIG_BUS_CONTROL_IGNORE_WR_ID
value|(1<< 4)
comment|/* Timeout limit before terminating configuration bus access with slave error */
define|#
directive|define
name|NB_GLOBAL_CONFIG_BUS_CONTROL_TIMEOUT_LIMIT_MASK
value|0xFFFFFF00
define|#
directive|define
name|NB_GLOBAL_CONFIG_BUS_CONTROL_TIMEOUT_LIMIT_SHIFT
value|8
comment|/**** Pos_ID_Match register ****/
comment|/* Enable Device (GRE and nGRE) after Device ID hazard */
define|#
directive|define
name|NB_GLOBAL_POS_ID_MATCH_ENABLE
value|(1<< 0)
comment|/* ID Field Mask If set, corresonpding ID bits are not used for ID match */
define|#
directive|define
name|NB_GLOBAL_POS_ID_MATCH_MASK_MASK
value|0xFFFF0000
define|#
directive|define
name|NB_GLOBAL_POS_ID_MATCH_MASK_SHIFT
value|16
comment|/**** sb_sel_override_awuser register ****/
comment|/* Select whether to use transaction awuser or sb_override_awuser value for awuser field on outgoing write transactions to SB. Each bit if set to 1 selects the corresponding sb_override_awuser bit. Otherwise, selects the corersponding transaction awuser bit. */
define|#
directive|define
name|NB_GLOBAL_SB_SEL_OVERRIDE_AWUSER_SEL_MASK
value|0x03FFFFFF
define|#
directive|define
name|NB_GLOBAL_SB_SEL_OVERRIDE_AWUSER_SEL_SHIFT
value|0
comment|/**** sb_override_awuser register ****/
comment|/* Awuser to use on overriden transactions Only applicable if sel_override_awuser.sel is set to 1'b1 for the coressponding bit */
define|#
directive|define
name|NB_GLOBAL_SB_OVERRIDE_AWUSER_AWUSER_MASK
value|0x03FFFFFF
define|#
directive|define
name|NB_GLOBAL_SB_OVERRIDE_AWUSER_AWUSER_SHIFT
value|0
comment|/**** sb_sel_override_aruser register ****/
comment|/* Select whether to use transaction aruser or sb_override_aruser value for aruser field on outgoing read transactions to SB. Each bit if set to 1 selects the corresponding sb_override_aruser bit. Otherwise, selects the corersponding transaction aruser bit. */
define|#
directive|define
name|NB_GLOBAL_SB_SEL_OVERRIDE_ARUSER_SEL_MASK
value|0x03FFFFFF
define|#
directive|define
name|NB_GLOBAL_SB_SEL_OVERRIDE_ARUSER_SEL_SHIFT
value|0
comment|/**** sb_override_aruser register ****/
comment|/* Aruser to use on overriden transactions Only applicable if sb_sel_override_aruser.sel is set to 1'b1 for the coressponding bit */
define|#
directive|define
name|NB_GLOBAL_SB_OVERRIDE_ARUSER_ARUSER_MASK
value|0x03FFFFFF
define|#
directive|define
name|NB_GLOBAL_SB_OVERRIDE_ARUSER_ARUSER_SHIFT
value|0
comment|/**** Coresight_PD register ****/
comment|/* ETF0 RAM force power down */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_PD_ETF0_RAM_FORCE_PD
value|(1<< 0)
comment|/* ETF1 RAM force power down */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_PD_ETF1_RAM_FORCE_PD
value|(1<< 1)
comment|/* ETF0 RAM force clock gate */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_PD_ETF0_RAM_FORCE_CG
value|(1<< 2)
comment|/* ETF1 RAM force clock gate */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_PD_ETF1_RAM_FORCE_CG
value|(1<< 3)
comment|/* APBIC clock enable */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_PD_APBICLKEN
value|(1<< 4)
comment|/* DAP system clock enable */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_PD_DAP_SYS_CLKEN
value|(1<< 5)
comment|/**** Coresight_INTERNAL_0 register ****/
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_INTERNAL_0_CTIAPBSBYPASS
value|(1<< 0)
comment|/* CA15 CTM and Coresight CTI operate at same clock, bypass modes can be enabled but it's being set to bypass disable to break timing path. */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_INTERNAL_0_CISBYPASS
value|(1<< 1)
comment|/* CA15 CTM and Coresight CTI operate according to the same clock. Bypass modes can be enabled, but it is set to bypass disable, to break the timing path. */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_INTERNAL_0_CIHSBYPASS_MASK
value|0x0000003C
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_INTERNAL_0_CIHSBYPASS_SHIFT
value|2
comment|/**** Coresight_DBGROMADDR register ****/
comment|/* Valid signal for DBGROMADDR. Connected to DBGROMADDRV */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_DBGROMADDR_VALID
value|(1<< 0)
comment|/* Specifies bits [39:12] of the ROM table physical address. */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_DBGROMADDR_ADDR_39_12_MASK
value|0x3FFFFFFC
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_DBGROMADDR_ADDR_39_12_SHIFT
value|2
comment|/**** Coresight_DBGSELFADDR register ****/
comment|/* Valid signal for DBGROMADDR. Connected to DBGROMADDRV */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_DBGSELFADDR_VALID
value|(1<< 0)
comment|/* Specifies bits [18:17] of the two's complement signed offset from the ROM table physical address to the physical address where the debug registers are memory-mapped. Note: The CA15 debug unit starts at offset 0x1 within the Coresight cluster. */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_DBGSELFADDR_ADDR_18_17_MASK
value|0x00000180
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_DBGSELFADDR_ADDR_18_17_SHIFT
value|7
comment|/* Specifies bits [39:19] of the two's complement signed offset from the ROM table physical address to the physical address where the debug registers are memory-mapped. Note: The CA15 debug unit starts at offset 0x1 within the Coresight cluster, so this offset if fixed to zero. */
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_DBGSELFADDR_ADDR_39_19_MASK
value|0x3FFFFE00
define|#
directive|define
name|NB_GLOBAL_CORESIGHT_DBGSELFADDR_ADDR_39_19_SHIFT
value|9
comment|/**** SB_force_same_id_cfg_0 register ****/
comment|/* Enables force same id mechanism for SB port 0 */
define|#
directive|define
name|NB_GLOBAL_SB_FORCE_SAME_ID_CFG_0_FORCE_SAME_ID_EN
value|(1<< 0)
comment|/* Enables MSIx stall when write transactions from same ID mechanism are in progress for SB port 0 */
define|#
directive|define
name|NB_GLOBAL_SB_FORCE_SAME_ID_CFG_0_FORCE_SAME_ID_MSIX_STALL_EN
value|(1<< 1)
comment|/* Mask for choosing which ID bits to match for indicating the originating master */
define|#
directive|define
name|NB_GLOBAL_SB_FORCE_SAME_ID_CFG_0_SB_MSTR_ID_MASK_MASK
value|0x000000F8
define|#
directive|define
name|NB_GLOBAL_SB_FORCE_SAME_ID_CFG_0_SB_MSTR_ID_MASK_SHIFT
value|3
comment|/**** SB_force_same_id_cfg_1 register ****/
comment|/* Enables force same id mechanism for SB port 1 */
define|#
directive|define
name|NB_GLOBAL_SB_FORCE_SAME_ID_CFG_1_FORCE_SAME_ID_EN
value|(1<< 0)
comment|/* Enables MSIx stall when write transactions from same ID mechanism are in progress for SB port 1 */
define|#
directive|define
name|NB_GLOBAL_SB_FORCE_SAME_ID_CFG_1_FORCE_SAME_ID_MSIX_STALL_EN
value|(1<< 1)
comment|/* Mask for choosing which ID bits to match for indicating the originating master */
define|#
directive|define
name|NB_GLOBAL_SB_FORCE_SAME_ID_CFG_1_SB_MSTR_ID_MASK_MASK
value|0x000000F8
define|#
directive|define
name|NB_GLOBAL_SB_FORCE_SAME_ID_CFG_1_SB_MSTR_ID_MASK_SHIFT
value|3
comment|/**** Cnt_Control register ****/
comment|/* System counter enable Counter is enabled after reset. */
define|#
directive|define
name|NB_SYSTEM_COUNTER_CNT_CONTROL_EN
value|(1<< 0)
comment|/* System counter restart Initial value is reloaded from Counter_Init_L and Counter_Init_H registers. Transition from 0 to 1 reloads the register. */
define|#
directive|define
name|NB_SYSTEM_COUNTER_CNT_CONTROL_RESTART
value|(1<< 1)
comment|/* Disable CTI trigger out that halt the counter progress */
define|#
directive|define
name|NB_SYSTEM_COUNTER_CNT_CONTROL_CTI_TRIGOUT_HALT_DIS
value|(1<< 2)
comment|/* System counter tick Specifies the counter tick rate relative to the Northbridge clock, e.g., the counter is incremented every 16 NB cycles if programmed to 0x0f. */
define|#
directive|define
name|NB_SYSTEM_COUNTER_CNT_CONTROL_SCALE_MASK
value|0x0000FF00
define|#
directive|define
name|NB_SYSTEM_COUNTER_CNT_CONTROL_SCALE_SHIFT
value|8
comment|/**** CA15_RF_Misc register ****/
define|#
directive|define
name|NB_RAMS_CONTROL_MISC_CA15_RF_MISC_NONECPU_RF_MISC_MASK
value|0x0000000F
define|#
directive|define
name|NB_RAMS_CONTROL_MISC_CA15_RF_MISC_NONECPU_RF_MISC_SHIFT
value|0
define|#
directive|define
name|NB_RAMS_CONTROL_MISC_CA15_RF_MISC_CPU_RF_MISC_MASK
value|0x00FFFF00
define|#
directive|define
name|NB_RAMS_CONTROL_MISC_CA15_RF_MISC_CPU_RF_MISC_SHIFT
value|8
comment|/* Pause for CPUs from the time all power is up to the time the SRAMs start opening. */
define|#
directive|define
name|NB_RAMS_CONTROL_MISC_CA15_RF_MISC_PWR_UP_PAUSE_MASK
value|0xF8000000
define|#
directive|define
name|NB_RAMS_CONTROL_MISC_CA15_RF_MISC_PWR_UP_PAUSE_SHIFT
value|27
comment|/**** NB_RF_Misc register ****/
comment|/* SMMU TLB RAMs force power down */
define|#
directive|define
name|NB_RAMS_CONTROL_MISC_NB_RF_MISC_SMMU_RAM_FORCE_PD
value|(1<< 0)
comment|/**** Lockn register ****/
comment|/* Semaphore Lock CPU reads it: If current value ==0,  return 0 to CPU but set bit to 1. (CPU knows it captured the semaphore.) If current value ==1, return 1 to CPU. (CPU knows it is already used and waits.) CPU writes 0 to it to release the semaphore. */
define|#
directive|define
name|NB_SEMAPHORES_LOCKN_LOCK
value|(1<< 0)
comment|/**** CA15_outputs_1 register ****/
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_STANDBYWFI_MASK
value|0x0000000F
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_STANDBYWFI_SHIFT
value|0
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_CPU_PWR_DN_ACK_MASK
value|0x000000F0
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_CPU_PWR_DN_ACK_SHIFT
value|4
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_IRQOUT_N_MASK
value|0x00000F00
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_IRQOUT_N_SHIFT
value|8
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_FIQOUT_N_MASK
value|0x0000F000
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_FIQOUT_N_SHIFT
value|12
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_CNTHPIRQ_N_MASK
value|0x000F0000
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_CNTHPIRQ_N_SHIFT
value|16
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_NCNTPNSIRQ_N_MASK
value|0x00F00000
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_NCNTPNSIRQ_N_SHIFT
value|20
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_NCNTPSIRQ_N_MASK
value|0x0F000000
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_NCNTPSIRQ_N_SHIFT
value|24
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_NCNTVIRQ_N_MASK
value|0xF0000000
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_1_NCNTVIRQ_N_SHIFT
value|28
comment|/**** CA15_outputs_2 register ****/
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_2_STANDBYWFIL2
value|(1<< 0)
comment|/*  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_2_L2RAM_PWR_DN_ACK
value|(1<< 1)
comment|/* Indicates for each CPU if coherency is enabled  */
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_2_SMPEN_MASK
value|0x0000003C
define|#
directive|define
name|NB_DEBUG_CA15_OUTPUTS_2_SMPEN_SHIFT
value|2
comment|/**** cpu_msg register ****/
comment|/* Status/ASCII code */
define|#
directive|define
name|NB_DEBUG_CPU_MSG_STATUS_MASK
value|0x000000FF
define|#
directive|define
name|NB_DEBUG_CPU_MSG_STATUS_SHIFT
value|0
comment|/* Toggle with each ASCII write */
define|#
directive|define
name|NB_DEBUG_CPU_MSG_ASCII_TOGGLE
value|(1<< 8)
comment|/* Signals ASCII */
define|#
directive|define
name|NB_DEBUG_CPU_MSG_ASCII
value|(1<< 9)
define|#
directive|define
name|NB_DEBUG_CPU_MSG_RESERVED_11_10_MASK
value|0x00000C00
define|#
directive|define
name|NB_DEBUG_CPU_MSG_RESERVED_11_10_SHIFT
value|10
comment|/* Signals new section started in S/W */
define|#
directive|define
name|NB_DEBUG_CPU_MSG_SECTION_START
value|(1<< 12)
define|#
directive|define
name|NB_DEBUG_CPU_MSG_RESERVED_13
value|(1<< 13)
comment|/* Signals a single CPU is done. */
define|#
directive|define
name|NB_DEBUG_CPU_MSG_CPU_DONE
value|(1<< 14)
comment|/* Signals test is done */
define|#
directive|define
name|NB_DEBUG_CPU_MSG_TEST_DONE
value|(1<< 15)
comment|/**** ddrc register ****/
comment|/* External DLL calibration request. Also compensates for VT variations, such as an external request for the controller (can be performed automatically by the controller at the normal settings). */
define|#
directive|define
name|NB_DEBUG_DDRC_DLL_CALIB_EXT_REQ
value|(1<< 0)
comment|/* External request to perform short (long is performed during initialization) and/or ODT calibration. */
define|#
directive|define
name|NB_DEBUG_DDRC_ZQ_SHORT_CALIB_EXT_REQ
value|(1<< 1)
comment|/* External request to perform a refresh command to a specific bank. Usually performed automatically by the controller, however, the controller supports disabling of the automatic mechanism, and use of an external pulse instead.  */
define|#
directive|define
name|NB_DEBUG_DDRC_RANK_REFRESH_EXT_REQ_MASK
value|0x0000003C
define|#
directive|define
name|NB_DEBUG_DDRC_RANK_REFRESH_EXT_REQ_SHIFT
value|2
comment|/**** ddrc_phy_smode_control register ****/
comment|/* DDR PHY special mode */
define|#
directive|define
name|NB_DEBUG_DDRC_PHY_SMODE_CONTROL_CTL_MASK
value|0x0000FFFF
define|#
directive|define
name|NB_DEBUG_DDRC_PHY_SMODE_CONTROL_CTL_SHIFT
value|0
comment|/**** ddrc_phy_smode_status register ****/
comment|/* DDR PHY special mode */
define|#
directive|define
name|NB_DEBUG_DDRC_PHY_SMODE_STATUS_STT_MASK
value|0x0000FFFF
define|#
directive|define
name|NB_DEBUG_DDRC_PHY_SMODE_STATUS_STT_SHIFT
value|0
comment|/**** pmc register ****/
comment|/* Enable system control on NB DRO */
define|#
directive|define
name|NB_DEBUG_PMC_SYS_EN
value|(1<< 0)
comment|/* NB PMC HVT35 counter value */
define|#
directive|define
name|NB_DEBUG_PMC_HVT35_VAL_14_0_MASK
value|0x0000FFFE
define|#
directive|define
name|NB_DEBUG_PMC_HVT35_VAL_14_0_SHIFT
value|1
comment|/* NB PMC SVT31 counter value */
define|#
directive|define
name|NB_DEBUG_PMC_SVT31_VAL_14_0_MASK
value|0x7FFF0000
define|#
directive|define
name|NB_DEBUG_PMC_SVT31_VAL_14_0_SHIFT
value|16
comment|/**** cpus_general register ****/
comment|/* Swaps sysaddr[16:14] with sysaddr[19:17] for DDR access*/
define|#
directive|define
name|NB_DEBUG_CPUS_GENERAL_ADDR_MAP_ECO
value|(1<< 23)
comment|/**** cpus_int_out register ****/
comment|/* Defines which CPUs' FIQ will be triggered out through the cpus_int_out[1] pinout. */
define|#
directive|define
name|NB_DEBUG_CPUS_INT_OUT_FIQ_EN_MASK
value|0x0000000F
define|#
directive|define
name|NB_DEBUG_CPUS_INT_OUT_FIQ_EN_SHIFT
value|0
comment|/* Defines which CPUs' IRQ will be triggered out through the cpus_int_out[0] pinout. */
define|#
directive|define
name|NB_DEBUG_CPUS_INT_OUT_IRQ_EN_MASK
value|0x000000F0
define|#
directive|define
name|NB_DEBUG_CPUS_INT_OUT_IRQ_EN_SHIFT
value|4
comment|/* Defines which CPUs' SEI will be triggered out through the cpus_int_out[0] pinout. */
define|#
directive|define
name|NB_DEBUG_CPUS_INT_OUT_IRQ_SEI_EN_MASK
value|0x00000F00
define|#
directive|define
name|NB_DEBUG_CPUS_INT_OUT_IRQ_SEI_EN_SHIFT
value|8
comment|/**** latch_pc_req register ****/
comment|/* If set, request to latch execution  PC from processor cluster */
define|#
directive|define
name|NB_DEBUG_LATCH_PC_REQ_EN
value|(1<< 0)
comment|/* target CPU id to latch its execution PC */
define|#
directive|define
name|NB_DEBUG_LATCH_PC_REQ_CPU_ID_MASK
value|0x000000F0
define|#
directive|define
name|NB_DEBUG_LATCH_PC_REQ_CPU_ID_SHIFT
value|4
comment|/**** latch_pc_low register ****/
comment|/* Set by hardware when the processor cluster ack the PC latch request. Clear on read latch_pc_high */
define|#
directive|define
name|NB_DEBUG_LATCH_PC_LOW_VALID
value|(1<< 0)
comment|/* Latched PC value [31:1] */
define|#
directive|define
name|NB_DEBUG_LATCH_PC_LOW_VAL_MASK
value|0xFFFFFFFE
define|#
directive|define
name|NB_DEBUG_LATCH_PC_LOW_VAL_SHIFT
value|1
comment|/**** track_dump_ctrl register ****/
comment|/* [24:16]: Queue entry pointer [2] Target queue:  1'b0: HazardTrack or 1'b1: AmiRMI queues [1:0]: CCI target master: 2'b00: M0, 2'b01: M1, 2'b10: M2 */
define|#
directive|define
name|NB_DEBUG_TRACK_DUMP_CTRL_PTR_MASK
value|0x7FFFFFFF
define|#
directive|define
name|NB_DEBUG_TRACK_DUMP_CTRL_PTR_SHIFT
value|0
comment|/* Track Dump Request If set, queue entry info is latched on track_dump_rdata register. Program the pointer and target queue. This is a full handshake register. Read<valid> bit from track_dump_rdata register. If set, clear the request field before triggering a new request. */
define|#
directive|define
name|NB_DEBUG_TRACK_DUMP_CTRL_REQ
value|(1<< 31)
comment|/**** track_dump_rdata_0 register ****/
comment|/* Valid */
define|#
directive|define
name|NB_DEBUG_TRACK_DUMP_RDATA_0_VALID
value|(1<< 0)
comment|/* Low data */
define|#
directive|define
name|NB_DEBUG_TRACK_DUMP_RDATA_0_DATA_MASK
value|0xFFFFFFFE
define|#
directive|define
name|NB_DEBUG_TRACK_DUMP_RDATA_0_DATA_SHIFT
value|1
comment|/**** pos_track_dump_ctrl register ****/
comment|/* [24:16]: queue entry pointer */
define|#
directive|define
name|NB_DEBUG_POS_TRACK_DUMP_CTRL_PTR_MASK
value|0x7FFFFFFF
define|#
directive|define
name|NB_DEBUG_POS_TRACK_DUMP_CTRL_PTR_SHIFT
value|0
comment|/* Track Dump Request If set, queue entry info is latched on track_dump_rdata register. Program the pointer and target queue. This is a  full handshake register Read<valid> bit from track_dump_rdata register. If set, clear the request field before triggering a new request. */
define|#
directive|define
name|NB_DEBUG_POS_TRACK_DUMP_CTRL_REQ
value|(1<< 31)
comment|/**** pos_track_dump_rdata_0 register ****/
comment|/* Valid */
define|#
directive|define
name|NB_DEBUG_POS_TRACK_DUMP_RDATA_0_VALID
value|(1<< 0)
comment|/* Low data */
define|#
directive|define
name|NB_DEBUG_POS_TRACK_DUMP_RDATA_0_DATA_MASK
value|0xFFFFFFFE
define|#
directive|define
name|NB_DEBUG_POS_TRACK_DUMP_RDATA_0_DATA_SHIFT
value|1
comment|/**** c2swb_track_dump_ctrl register ****/
comment|/* [24:16]: Queue entry pointer */
define|#
directive|define
name|NB_DEBUG_C2SWB_TRACK_DUMP_CTRL_PTR_MASK
value|0x7FFFFFFF
define|#
directive|define
name|NB_DEBUG_C2SWB_TRACK_DUMP_CTRL_PTR_SHIFT
value|0
comment|/* Track Dump Request If set, queue entry info is latched on track_dump_rdata register. Program the pointer and target queue. This is a full handshake register Read<valid> bit from track_dump_rdata register. If set, clear the request field before triggering a new request. */
define|#
directive|define
name|NB_DEBUG_C2SWB_TRACK_DUMP_CTRL_REQ
value|(1<< 31)
comment|/**** c2swb_track_dump_rdata_0 register ****/
comment|/* Valid */
define|#
directive|define
name|NB_DEBUG_C2SWB_TRACK_DUMP_RDATA_0_VALID
value|(1<< 0)
comment|/* Low data */
define|#
directive|define
name|NB_DEBUG_C2SWB_TRACK_DUMP_RDATA_0_DATA_MASK
value|0xFFFFFFFE
define|#
directive|define
name|NB_DEBUG_C2SWB_TRACK_DUMP_RDATA_0_DATA_SHIFT
value|1
comment|/**** cpus_track_dump_ctrl register ****/
comment|/* [24:16]: Queue entry pointer [3:2] Target queue - 0:ASI, 1: AMI [1:0]: Target Processor Cluster - 0: Cluster0, 1: Cluster1 */
define|#
directive|define
name|NB_DEBUG_CPUS_TRACK_DUMP_CTRL_PTR_MASK
value|0x7FFFFFFF
define|#
directive|define
name|NB_DEBUG_CPUS_TRACK_DUMP_CTRL_PTR_SHIFT
value|0
comment|/* Track Dump Request If set, queue entry info is latched on track_dump_rdata register. Program the pointer and target queue. This is a  full handshake register Read<valid> bit from track_dump_rdata register. If set, clear the request field before triggering a new request. */
define|#
directive|define
name|NB_DEBUG_CPUS_TRACK_DUMP_CTRL_REQ
value|(1<< 31)
comment|/**** cpus_track_dump_rdata_0 register ****/
comment|/* Valid */
define|#
directive|define
name|NB_DEBUG_CPUS_TRACK_DUMP_RDATA_0_VALID
value|(1<< 0)
comment|/* Low data */
define|#
directive|define
name|NB_DEBUG_CPUS_TRACK_DUMP_RDATA_0_DATA_MASK
value|0xFFFFFFFE
define|#
directive|define
name|NB_DEBUG_CPUS_TRACK_DUMP_RDATA_0_DATA_SHIFT
value|1
comment|/**** c2swb_bar_ovrd_high register ****/
comment|/* Read barrier is progressed downstream when not terminated in the CCI. By specification, barrier address is 0x0. This register enables barrier address OVRD to a programmable value. */
define|#
directive|define
name|NB_DEBUG_C2SWB_BAR_OVRD_HIGH_RD_ADDR_OVRD_EN
value|(1<< 0)
comment|/* Address bits 39:32 */
define|#
directive|define
name|NB_DEBUG_C2SWB_BAR_OVRD_HIGH_ADDR_39_32_MASK
value|0x00FF0000
define|#
directive|define
name|NB_DEBUG_C2SWB_BAR_OVRD_HIGH_ADDR_39_32_SHIFT
value|16
comment|/**** Config register ****/
comment|/* Individual processor control of the endianness configuration at reset. It sets the initial value of the EE bit in the CP15 System Control Register (SCTLR) related to CFGEND<n> input: little - 0x0: Little endian bit - 0x1: Bit endian */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CONFIG_ENDIAN
value|(1<< 0)
comment|/* Individual processor control of the default exception handling state. It sets the initial value of the TE bit in the CP15 System Control Register (SCTLR) related to CFGTE<n> input: arm: 0x0: Exception operates ARM code. Thumb: 0x1: Exception operates Thumb code. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CONFIG_TE
value|(1<< 1)
comment|/* Individual processor control of the location of the exception vectors at reset. It sets the initial value of the V bit in the CP15 System Control Register (SCTLR). Connected to VINITHIGH<n> input. low - 0x0: Exception vectors start at address 0x00000000. high - 0x1: Exception vectors start at address 0xFFFF0000. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CONFIG_VINITHI
value|(1<< 2)
comment|/* Individual processor control to disable write access to some secure CP15 registers connected to CP15SDISABLE<n> input. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CONFIG_CP15DISABLE
value|(1<< 3)
comment|/* Force Write init implementation to ConfigAARch64 register */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CONFIG_AARCH64_REG_FORCE_WINIT
value|(1<< 4)
comment|/* Force Write Once implementation to ConfigAARch64 register. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CONFIG_AARCH64_REG_FORCE_WONCE
value|(1<< 5)
comment|/**** Config_AARch64 register ****/
comment|/* Individual processor register width state. The register width states are: 0 AArch32. 1 AArch64. This signal is only sampled during reset of the processor. This is Write Init register */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CONFIG_AARCH64_AA64_NAA32
value|(1<< 0)
comment|/* Individual processor Cryptography engine disable: 0 Enable the Cryptography engine. 1 Disable the Cryptography engine. This signal is only sampled during reset of the processor */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CONFIG_AARCH64_CRYPTO_DIS
value|(1<< 1)
comment|/**** Power_Ctrl register ****/
comment|/* Individual CPU power mode transition request If requested to enter power mode other than normal mode, low power state is resumed whenever CPU reenters STNDBYWFI state: normal: 0x0: normal power state deep_idle: 0x2: Dormant power mode state poweredoff: 0x3: Powered-off power mode */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_PM_REQ_MASK
value|0x00000003
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_PM_REQ_SHIFT
value|0
comment|/* Normal power mode state */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_PM_REQ_NORMAL
define|\
value|(0x0<< NB_CPUN_CONFIG_STATUS_POWER_CTRL_PM_REQ_SHIFT)
comment|/* Dormant power mode state */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_PM_REQ_DEEP_IDLE
define|\
value|(0x2<< NB_CPUN_CONFIG_STATUS_POWER_CTRL_PM_REQ_SHIFT)
comment|/* Powered-off power mode */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_PM_REQ_POWEREDOFF
define|\
value|(0x3<< NB_CPUN_CONFIG_STATUS_POWER_CTRL_PM_REQ_SHIFT)
comment|/* Power down regret disable When power down regret is enabled, the powerdown enter flow can be halted whenever a valid wakeup event occurs. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_PWRDN_RGRT_DIS
value|(1<< 16)
comment|/* Power down emulation enable If set, the entire power down sequence is applied, but the CPU is placed in soft reset instead of hardware power down. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_PWRDN_EMULATE
value|(1<< 17)
comment|/* Disable wakeup from Local--GIC FIQ. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_WU_LGIC_FIQ_DIS
value|(1<< 18)
comment|/* Disable wakeup from Local-GIC IRQ. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_WU_LGIC_IRQ_DIS
value|(1<< 19)
comment|/* Disable wakeup from IO-GIC FIQ. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_WU_IOGIC_FIQ_DIS
value|(1<< 20)
comment|/* Disable wakeup from IO-GIC IRQ. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_WU_IOGIC_IRQ_DIS
value|(1<< 21)
comment|/* Disable scheduling of interrrupts in GIC(500) to non-active CPU */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_CTRL_IOGIC_DIS_CPU
value|(1<< 22)
comment|/**** Power_Status register ****/
comment|/* Read-only bits that reflect the individual CPU power mode status. Default value for non-exist CPU is 2b11: normal - 0x0: Normal mode por - 0x1: por on reset mode deep_idle - 0x2: Dormant power mode state poweredoff - 0x3: Powered-off power mode */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_MASK
value|0x00000003
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_SHIFT
value|0
comment|/* Normal power mode state */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_NORMAL
define|\
value|(0x0<< NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_SHIFT)
comment|/* Idle power mode state (WFI) */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_IDLE
define|\
value|(0x1<< NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_SHIFT)
comment|/* Dormant power mode state */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_DEEP_IDLE
define|\
value|(0x2<< NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_SHIFT)
comment|/* Powered-off power mode */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_POWEREDOFF
define|\
value|(0x3<< NB_CPUN_CONFIG_STATUS_POWER_STATUS_CPU_PM_SHIFT)
comment|/* WFI status */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_STATUS_WFI
value|(1<< 2)
comment|/* WFE status */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_POWER_STATUS_WFE
value|(1<< 3)
comment|/**** Warm_Rst_Ctl register ****/
comment|/* Disable CPU Warm Reset when warmrstreq is asserted  When the Reset Request bit in the RMR or RMR_EL3 register is set to 1 in the CPU Core , the processor asserts the WARMRSTREQ signal and the SoC reset controller use this request to trigger a Warm reset of the processor and change the register width state. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_WARM_RST_CTL_REQ_DIS
value|(1<< 0)
comment|/* Disable waiting WFI on Warm Reset */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_WARM_RST_CTL_WFI_DIS
value|(1<< 1)
comment|/* CPU Core AARach64 reset vector bar This is Write Once register (controlled by aarch64_reg_force_* fields) */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_RVBAR_LOW_ADDR_31_2_MASK
value|0xFFFFFFFC
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_RVBAR_LOW_ADDR_31_2_SHIFT
value|2
comment|/**** Rvbar_High register ****/
comment|/* CPU Core AARach64 reset vector bar high bits This is Write Once register (controlled by aarch64_reg_force_* fields) */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_RVBAR_HIGH_ADDR_43_32_MASK
value|0x00000FFF
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_RVBAR_HIGH_ADDR_43_32_SHIFT
value|0
comment|/**** pmu_snapshot register ****/
comment|/* PMU Snapshot Request */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_PMU_SNAPSHOT_REQ
value|(1<< 0)
comment|/* 0:  HW deassert requests when received ack 1: SW deasserts request when received done */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_PMU_SNAPSHOT_MODE
value|(1<< 1)
comment|/* Snapshot process completed */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_PMU_SNAPSHOT_DONE
value|(1<< 31)
comment|/**** cpu_msg_in register ****/
comment|/* CPU read this register to receive input (char) from simulation. */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CPU_MSG_IN_DATA_MASK
value|0x000000FF
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CPU_MSG_IN_DATA_SHIFT
value|0
comment|/* Indicates the data is valid. Cleared on read */
define|#
directive|define
name|NB_CPUN_CONFIG_STATUS_CPU_MSG_IN_VALID
value|(1<< 8)
comment|/**** PMU_Control register ****/
comment|/* Disable all counters When this bit is clear, counter state is determined through the specific counter control register */
define|#
directive|define
name|NB_MC_PMU_PMU_CONTROL_DISABLE_ALL
value|(1<< 0)
comment|/* Pause all counters. When this bit is clear, counter state is determined through the specific counter control register. */
define|#
directive|define
name|NB_MC_PMU_PMU_CONTROL_PAUSE_ALL
value|(1<< 1)
comment|/* Overflow interrupt enable: disable - 0x0: Disable interrupt on overflow. enable - 0x1: Enable interrupt on overflow. */
define|#
directive|define
name|NB_MC_PMU_PMU_CONTROL_OVRF_INTR_EN
value|(1<< 2)
comment|/* Number of monitored events supported by the PMU. */
define|#
directive|define
name|NB_MC_PMU_PMU_CONTROL_NUM_OF_EVENTS_MASK
value|0x00FC0000
define|#
directive|define
name|NB_MC_PMU_PMU_CONTROL_NUM_OF_EVENTS_SHIFT
value|18
define|#
directive|define
name|NB_MC_PMU_PMU_CONTROL_NUM_OF_EVENTS_SHIFT_ALPINE
value|19
comment|/* Number of counters implemented by PMU. */
define|#
directive|define
name|NB_MC_PMU_PMU_CONTROL_NUM_OF_CNTS_MASK
value|0x0F000000
define|#
directive|define
name|NB_MC_PMU_PMU_CONTROL_NUM_OF_CNTS_SHIFT
value|24
comment|/**** Cfg register ****/
comment|/* Event select */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_EVENT_SEL_MASK
value|0x0000003F
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_EVENT_SEL_SHIFT
value|0
comment|/* Enable setting of counter low overflow status bit: disable - 0x0: Disable setting. enable - 0x1: Enable setting. */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_OVRF_LOW_STT_EN
value|(1<< 6)
comment|/* Enable setting of counter high overflow status bit: disable - 0x0: Disable setting. enable - 0x1: Enable setting. */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_OVRF_HIGH_STT_EN
value|(1<< 7)
comment|/* Enable pause on trigger in assertion: disable - 0x0: Disable pause. enable - 0x1: Enable pause. */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_TRIGIN_PAUSE_EN
value|(1<< 8)
comment|/* Enable increment trigger out for trace. Trigger is generated whenever counter reaches<granule> value: disable - 0x0: Disable trigger out. enable - 0x1: Enable trigger out. */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_TRIGOUT_EN
value|(1<< 9)
comment|/* Trigger out granule value Specifies the number of events counted between two consecutive trigger out events 0x0: 1 - Trigger out on every event occurrence. 0x1: 2 - Trigger out on every two events. ... 0xn: 2^(n-1) - Trigger out on event 2^(n-1) events. ... 0x1F: 2^31 */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_TRIGOUT_GRANULA_MASK
value|0x00007C00
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_TRIGOUT_GRANULA_SHIFT
value|10
comment|/* Pause on overflow bitmask If set for counter<i>, current counter pauses counting when counter<i> is overflowed, including self-pause. Bit [16]: counter 0 Bit [17]: counter 1 Note: This field must be changed for larger counters. */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_PAUSE_ON_OVRF_BITMASK_MASK
value|0x000F0000
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CFG_PAUSE_ON_OVRF_BITMASK_SHIFT
value|16
comment|/**** Cntl register ****/
comment|/* Set the counter state to disable, enable, or pause: 0x0 - disable: Disable counter. 0x1 - enable: Enable counter. 0x3 - pause: Pause counter. */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CNTL_CNT_STATE_MASK
value|0x00000003
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CNTL_CNT_STATE_SHIFT
value|0
comment|/* Disable counter. */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CNTL_CNT_STATE_DISABLE
define|\
value|(0x0<< NB_MC_PMU_COUNTERS_CNTL_CNT_STATE_SHIFT)
comment|/* Enable counter.  */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CNTL_CNT_STATE_ENABLE
define|\
value|(0x1<< NB_MC_PMU_COUNTERS_CNTL_CNT_STATE_SHIFT)
comment|/* Pause counter.  */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_CNTL_CNT_STATE_PAUSE
define|\
value|(0x3<< NB_MC_PMU_COUNTERS_CNTL_CNT_STATE_SHIFT)
comment|/**** High register ****/
comment|/* Counter high value */
define|#
directive|define
name|NB_MC_PMU_COUNTERS_HIGH_COUNTER_MASK
value|0x0000FFFF
define|#
directive|define
name|NB_MC_PMU_COUNTERS_HIGH_COUNTER_SHIFT
value|0
comment|/**** version register ****/
comment|/*  Revision number (Minor) */
define|#
directive|define
name|NB_NB_VERSION_VERSION_RELEASE_NUM_MINOR_MASK
value|0x000000FF
define|#
directive|define
name|NB_NB_VERSION_VERSION_RELEASE_NUM_MINOR_SHIFT
value|0
comment|/*  Revision number (Major) */
define|#
directive|define
name|NB_NB_VERSION_VERSION_RELEASE_NUM_MAJOR_MASK
value|0x0000FF00
define|#
directive|define
name|NB_NB_VERSION_VERSION_RELEASE_NUM_MAJOR_SHIFT
value|8
comment|/*  Date of release */
define|#
directive|define
name|NB_NB_VERSION_VERSION_DATE_DAY_MASK
value|0x001F0000
define|#
directive|define
name|NB_NB_VERSION_VERSION_DATE_DAY_SHIFT
value|16
comment|/*  Month of release */
define|#
directive|define
name|NB_NB_VERSION_VERSION_DATA_MONTH_MASK
value|0x01E00000
define|#
directive|define
name|NB_NB_VERSION_VERSION_DATA_MONTH_SHIFT
value|21
comment|/*  Year of release (starting from 2000) */
define|#
directive|define
name|NB_NB_VERSION_VERSION_DATE_YEAR_MASK
value|0x3E000000
define|#
directive|define
name|NB_NB_VERSION_VERSION_DATE_YEAR_SHIFT
value|25
comment|/*  Reserved */
define|#
directive|define
name|NB_NB_VERSION_VERSION_RESERVED_MASK
value|0xC0000000
define|#
directive|define
name|NB_NB_VERSION_VERSION_RESERVED_SHIFT
value|30
comment|/**** cpu_vmid register ****/
comment|/* Target VMID */
define|#
directive|define
name|NB_SRIOV_CPU_VMID_VAL_MASK
value|0x000000FF
define|#
directive|define
name|NB_SRIOV_CPU_VMID_VAL_SHIFT
value|0
comment|/**** DRAM_0_Control register ****/
comment|/* Controller Idle Indicates to the DDR PHY, if set, that the memory controller is idle */
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_CONTROL_DDR_PHY_CTL_IDLE
value|(1<< 0)
comment|/* Disable clear exclusive monitor request from DDR controller to CPU Clear request is triggered whenever an exlusive monitor inside the DDR controller is being invalidated. */
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_CONTROL_DDR_EXMON_REQ_DIS
value|(1<< 1)
comment|/**** DRAM_0_Status register ****/
comment|/* Bypass Mode: Indicates if set that the PHY is in PLL bypass mod */
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_DDR_PHY_BYP_MODE
value|(1<< 0)
comment|/* Number of available AXI transactions (used positions) in the DDR controller read address FIFO. */
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_RAQ_WCOUNT_MASK
value|0x00000030
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_RAQ_WCOUNT_SHIFT
value|4
comment|/* Number of available AXI transactions (used positions) in the DDR controller write address FIFO */
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_WAQ_WCOUNT_0_MASK
value|0x000000C0
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_WAQ_WCOUNT_0_SHIFT
value|6
comment|/* Number of available Low priority read CAM slots (free positions) in  the DDR controller. Each slots holds a DRAM burst */
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_LPR_CREDIT_CNT_MASK
value|0x00007F00
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_LPR_CREDIT_CNT_SHIFT
value|8
comment|/* Number of available High priority read CAM slots (free positions) in  the DDR controller. Each slots holds a DRAM burst */
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_HPR_CREDIT_CNT_MASK
value|0x003F8000
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_HPR_CREDIT_CNT_SHIFT
value|15
comment|/* Number of available write CAM slots (free positions) in  the DDR controller. Each slots holds a DRAM burst */
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_WR_CREDIT_CNT_MASK
value|0x1FC00000
define|#
directive|define
name|NB_DRAM_CHANNELS_DRAM_0_STATUS_WR_CREDIT_CNT_SHIFT
value|22
comment|/**** DDR_Int_Cause register ****/
comment|/* This interrupt is asserted when a correctable ECC error is detected */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_ECC_CORRECTED_ERR
value|(1<< 0)
comment|/* This interrupt is asserted when a uncorrectable ECC error is detected */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_ECC_UNCORRECTED_ERR
value|(1<< 1)
comment|/* This interrupt is asserted when a parity or CRC error is detected on the DFI interface */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_DFI_ALERT_ERR
value|(1<< 2)
comment|/* On-Chip Write data parity error interrupt on output */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_PAR_WDATA_OUT_ERR
value|(1<< 3)
comment|/* This interrupt is asserted when a parity error due to MRS is detected on the DFI interface */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_DFI_ALERT_ERR_FATL
value|(1<< 4)
comment|/* This interrupt is asserted when the CRC/parity retry counter reaches it maximum value */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_DFI_ALERT_ERR_MAX_REACHED
value|(1<< 5)
comment|/* AXI Read address parity error interrupt. This interrupt is asserted when an on-chip parity error occurred on the DDR controller AXI read address. */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_PAR_RADDR_ERR
value|(1<< 6)
comment|/* AXI Read data parity error interrupt. This interrupt is asserted when an on-chip parity error occurred on the DDR controller AXI read data */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_PAR_RDATA_ERR
value|(1<< 7)
comment|/* AXI Write address parity error interrupt. This interrupt is asserted when an on-chip parity error occurred on the DDR controller AXI write address. */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_PAR_WADDR_ERR
value|(1<< 8)
comment|/* AXI Write data parity error interrupt on input. This interrupt is asserted when an on-chip parity error occurred on the DDR controller AXI write data */
define|#
directive|define
name|NB_DRAM_CHANNELS_DDR_INT_CAUSE_PAR_WDATA_IN_ERR
value|(1<< 9)
comment|/**** Address_Map register ****/
comment|/* Controls which system address bit will be mapped to DDR row bit 2. This field is only used when addrmap_part_en == 1 */
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_ROW_B2_MASK
value|0x0000000F
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_ROW_B2_SHIFT
value|0
comment|/* Controls which system address bit will be mapped to DDR row bit 3. This field is only used when addrmap_part_en == 1 */
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_ROW_B3_MASK
value|0x000003C0
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_ROW_B3_SHIFT
value|6
comment|/* Controls which system address bit will be mapped to DDR row bit 4. This field is only used when addrmap_part_en == 1 */
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_ROW_B4_MASK
value|0x0000F000
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_ROW_B4_SHIFT
value|12
comment|/* Controls which system address bit will be mapped to DDR row bit 5. This field is only used when addrmap_part_en == 1 */
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_ROW_B5_MASK
value|0x003C0000
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_ROW_B5_SHIFT
value|18
comment|/* Enables partitioning of the address mapping control. When set, addrmap_row_b2-5 are used inside DDR controler instead of the built in address mapping registers */
define|#
directive|define
name|NB_DRAM_CHANNELS_ADDRESS_MAP_ADDRMAP_PART_EN
value|(1<< 31)
comment|/**** Reorder_ID_Mask register ****/
comment|/* DDR Read Reorder buffer ID mask. If incoming read transaction ID ANDed with mask is equal Reorder_ID_Value, then the transaction is mapped to the DDR controller bypass channel. Setting this register to 0 will disable the check */
define|#
directive|define
name|NB_DRAM_CHANNELS_REORDER_ID_MASK_MASK_MASK
value|0x003FFFFF
define|#
directive|define
name|NB_DRAM_CHANNELS_REORDER_ID_MASK_MASK_SHIFT
value|0
comment|/**** Reorder_ID_Value register ****/
comment|/* DDR Read Reorder buffer ID value If incoming read transaction ID ANDed with Reorder_ID_Mask is equal to this register, then the transaction is mapped to the DDR controller bypass channel */
define|#
directive|define
name|NB_DRAM_CHANNELS_REORDER_ID_VALUE_VALUE_MASK
value|0x003FFFFF
define|#
directive|define
name|NB_DRAM_CHANNELS_REORDER_ID_VALUE_VALUE_SHIFT
value|0
comment|/**** MRR_Control_Status register ****/
comment|/* DDR4 Mode Register Read Data Valid */
define|#
directive|define
name|NB_DRAM_CHANNELS_MRR_CONTROL_STATUS_MRR_VLD
value|(1<< 0)
comment|/* MRR Ack, when asserted it clears the mrr_val indication and ready to load new MRR data. Write 1 to clear and then 0 */
define|#
directive|define
name|NB_DRAM_CHANNELS_MRR_CONTROL_STATUS_MRR_ACK
value|(1<< 16)
comment|/**** pp_config register ****/
comment|/* Bypass PP module (formality equivalent) */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_FM_BYPASS
value|(1<< 0)
comment|/* Bypass PP module */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_BYPASS
value|(1<< 1)
comment|/* Force Cleanup of entries */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_CLEAR
value|(1<< 2)
comment|/* Enable forwarding DECERR response */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_DECERR_EN
value|(1<< 3)
comment|/* Enable forwarding SLVERR response */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_SLVERR_EN
value|(1<< 4)
comment|/* Enable forwarding of data parity generation */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_PAR_GEN_EN
value|(1<< 5)
comment|/* Select channel on 8K boundaries ([15:13]) instead of 64k boundaries ([18:16]). */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_SEL_8K
value|(1<< 6)
comment|/* Forces awuser to be as configured in ext_awuser register. Not functional */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_SEL_EXT_AWUSER
value|(1<< 7)
comment|/* Enables PP channel. 1 bit per channel */
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_CHANNEL_ENABLE_MASK
value|0x00030000
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_CHANNEL_ENABLE_SHIFT
value|16
define|#
directive|define
name|NB_PUSH_PACKET_PP_CONFIG_CHANNEL_ENABLE
parameter_list|(
name|i
parameter_list|)
define|\
value|(1<< (NB_PUSH_PACKET_PP_CONFIG_CHANNEL_ENABLE_SHIFT + i))
comment|/**** pp_ext_awuser register ****/
comment|/* Awuser to use on PP transactions Only applicable if config.sel_ext_awuser is set to 1'b1 Parity bits are still generated per transaction */
define|#
directive|define
name|NB_PUSH_PACKET_PP_EXT_AWUSER_AWUSER_MASK
value|0x03FFFFFF
define|#
directive|define
name|NB_PUSH_PACKET_PP_EXT_AWUSER_AWUSER_SHIFT
value|0
comment|/**** pp_sel_awuser register ****/
comment|/* Select whether to use addr[63:48] or PP awmisc as vmid. Each bit if set to 1 selects the corresponding address bit. Otherwise, selects the corersponding awmis bit. */
define|#
directive|define
name|NB_PUSH_PACKET_PP_SEL_AWUSER_SEL_MASK
value|0x0000FFFF
define|#
directive|define
name|NB_PUSH_PACKET_PP_SEL_AWUSER_SEL_SHIFT
value|0
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
comment|/* __AL_HAL_NB_REGS_H__ */
end_comment

begin_comment
comment|/** @} end of ... group */
end_comment

end_unit

