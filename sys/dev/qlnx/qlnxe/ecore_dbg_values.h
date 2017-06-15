begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DBG_VALUES_H__
end_ifndef

begin_define
define|#
directive|define
name|__DBG_VALUES_H__
end_define

begin_comment
comment|/* modes tree buffer */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u8
name|dbg_modes_tree_buf
index|[]
init|=
block|{
literal|0x02
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x04
block|,
literal|0x05
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x07
block|,
literal|0x09
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x05
block|,
literal|0x12
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x09
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x01
block|,
literal|0x04
block|,
literal|0x05
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x12
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x07
block|,
literal|0x09
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x07
block|,
literal|0x09
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x0b
block|,
literal|0x0e
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x0b
block|,
literal|0x0f
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x0b
block|,
literal|0x10
block|,
literal|0x02
block|,
literal|0x05
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x07
block|,
literal|0x09
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x01
block|,
literal|0x04
block|,
literal|0x05
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x11
block|,
literal|0x0f
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x11
block|,
literal|0x0e
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x07
block|,
literal|0x09
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x0b
block|,
literal|0x10
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x0b
block|,
literal|0x0e
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x0b
block|,
literal|0x0f
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x09
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x01
block|,
literal|0x06
block|,
literal|0x01
block|,
literal|0x08
block|,
literal|0x0a
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x04
block|,
literal|0x12
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x11
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x12
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x0e
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x0c
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x0f
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x10
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x0f
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x10
block|,
literal|0x02
block|,
literal|0x05
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x06
block|,
literal|0x05
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x0f
block|,
literal|0x02
block|,
literal|0x12
block|,
literal|0x10
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x11
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x06
block|,
literal|0x01
block|,
literal|0x0b
block|,
literal|0x0d
block|,
literal|0x02
block|,
literal|0x05
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x0d
block|,
literal|0x00
block|,
literal|0x05
block|,
literal|0x03
block|,  }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 212 bytes */
end_comment

begin_comment
comment|/* Array of registers to be dumped */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|dump_reg
index|[]
init|=
block|{
literal|0x00000c74
block|,
comment|/* split NONE */
literal|0x06000000
block|,
comment|/* block grc */
literal|0x02014000
block|,
comment|/* grc.override_window_mem_self_init_start .. grc.override_window_mem_self_init_done (2 regs) */
literal|0x0a014010
block|,
comment|/* grc.rsv_attn_access_data_0 .. grc.trace_fifo_valid_data (10 regs) */
literal|0x1201401c
block|,
comment|/* grc.trace_fifo_enable .. grc.dbg_force_frame (18 regs) */
literal|0x0201403a
block|,
comment|/* grc.dbgsyn_status .. grc.dbgsyn_almost_full_thr (2 regs) */
literal|0x02014060
block|,
comment|/* grc.INT_STS_0 .. grc.INT_MASK_0 (2 regs) */
literal|0x04014100
block|,
comment|/* grc.timeout_val .. grc.number_valid_override_window (4 regs) */
literal|0x0d010000
block|,
comment|/* block miscs */
literal|0x02002410
block|,
comment|/* miscs.reset_config .. miscs.reset_config_por (2 regs) */
literal|0x0500241c
block|,
comment|/* miscs.clk_100g_mode .. miscs.NVM_WR_EN (5 regs) */
literal|0x0100245b
block|,
comment|/* miscs.memctrl_status (1 regs) */
literal|0x02002460
block|,
comment|/* miscs.INT_STS_0 .. miscs.INT_MASK_0 (2 regs) */
literal|0x83002500
block|,
comment|/* miscs.gpio0_driver .. miscs.gpio_event_en (131 regs) */
literal|0x0d0025af
block|,
comment|/* miscs.LINK_HOLDOFF_STATUS .. miscs.vmain_por (13 regs) */
literal|0x040025bd
block|,
comment|/* miscs.pwr_attn .. miscs.func_hide_pin (4 regs) */
literal|0x050025c4
block|,
comment|/* miscs.sel_vaux .. miscs.isolate_path (5 regs) */
literal|0x0c0025cb
block|,
comment|/* miscs.hot_reset_unprepared .. miscs.unprepared_fw (12 regs) */
literal|0x070025d8
block|,
comment|/* miscs.VAUX_PRESENT .. miscs.CHIP_TEST_REG (7 regs) */
literal|0x080025e0
block|,
comment|/* miscs.PCIE_DIS_IO .. miscs.perst_deassert_cnt (8 regs) */
literal|0x010025eb
block|,
comment|/* miscs.hot_reset_en (1 regs) */
literal|0x020025ed
block|,
comment|/* miscs.eco_reserved .. miscs.mcp_rom_tm (2 regs) */
literal|0x09020000
block|,
comment|/* block misc */
literal|0x01002010
block|,
comment|/* misc.reset_config (1 regs) */
literal|0x02002060
block|,
comment|/* misc.INT_STS .. misc.INT_MASK (2 regs) */
literal|0xff002100
block|,
comment|/* misc.aeu_general_attn_0 .. misc.aeu_after_invert_9_mcp (255 regs) */
literal|0x0c0021ff
block|,
comment|/* misc.aeu_sys_kill_occurred .. misc.aeu_general_mask (12 regs) */
literal|0x0100220c
block|,
comment|/* misc.aeu_mask_attn_igu_msb (1 regs) */
literal|0x0200220e
block|,
comment|/* misc.aeu_vpd_latch_status .. misc.attn_num_st (2 regs) */
literal|0x01002300
block|,
comment|/* misc.port_mode (1 regs) */
literal|0x16002303
block|,
comment|/* misc.opte_mode .. misc.sw_timer_reload_val_8 (22 regs) */
literal|0x0f00231a
block|,
comment|/* misc.sw_timer_event .. misc.eco_reserved (15 regs) */
literal|0x1d040000
block|,
comment|/* block pglue_b */
literal|0x010aa001
block|,
comment|/* pglue_b.init_done_inb_int_mem (1 regs) */
literal|0x010aa003
block|,
comment|/* pglue_b.init_done_ptt_gtt (1 regs) */
literal|0x010aa005
block|,
comment|/* pglue_b.init_done_zone_a (1 regs) */
literal|0x020aa060
block|,
comment|/* pglue_b.INT_STS .. pglue_b.INT_MASK (2 regs) */
literal|0x050aa100
block|,
comment|/* pglue_b.dbg_select .. pglue_b.dbg_force_frame (5 regs) */
literal|0x170aa118
block|,
comment|/* pglue_b.pgl_eco_reserved .. pglue_b.DISABLE_HIGHER_BW (23 regs) */
literal|0x040aa132
block|,
comment|/* pglue_b.memctrl_status .. pglue_b.tc_per_vq (4 regs) */
literal|0x020aa148
block|,
comment|/* pglue_b.pgl_control0 .. pglue_b.cssnoop_almost_full_thr (2 regs) */
literal|0x020aa158
block|,
comment|/* pglue_b.pgl_txr_cdts .. pglue_b.pgl_txw_cdts (2 regs) */
literal|0x050aa800
block|,
comment|/* pglue_b.cfg_space_a_address .. pglue_b.cfg_space_a_request (5 regs) */
literal|0x010aa806
block|,
comment|/* pglue_b.cfg_space_b_request (1 regs) */
literal|0x090aa808
block|,
comment|/* pglue_b.flr_request_vf_31_0 .. pglue_b.flr_request_pf_31_0 (9 regs) */
literal|0x020aa81a
block|,
comment|/* pglue_b.DISABLE_FLR_SRIOV_DISABLED .. pglue_b.sr_iov_disabled_request (2 regs) */
literal|0x090aa81d
block|,
comment|/* pglue_b.shadow_bme_vf_31_0 .. pglue_b.shadow_bme_pf_31_0 (9 regs) */
literal|0x0a0aa82f
block|,
comment|/* pglue_b.shadow_ats_enable_vf_31_0 .. pglue_b.shadow_vf_enable_pf_31_0 (10 regs) */
literal|0x0c0aa83a
block|,
comment|/* pglue_b.shadow_ido_bits .. pglue_b.was_error_pf_31_0 (12 regs) */
literal|0x0b0aa84f
block|,
comment|/* pglue_b.rx_err_details .. pglue_b.tx_err_wr_details_icpl (11 regs) */
literal|0x400aa85e
block|,
comment|/* pglue_b.internal_vfid_enable_31_0_value .. pglue_b.psdm_inb_int_b_vf_1 (64 regs) */
literal|0x290aa8c6
block|,
comment|/* pglue_b.tsdm_zone_a_size_pf .. pglue_b.vf_grc_space_violation_details (41 regs) */
literal|0x090aa8f0
block|,
comment|/* pglue_b.ido_enable_master_rw .. pglue_b.cpu_mbist_memctrl_1_cntrl_cmd (9 regs) */
literal|0x030aa8fb
block|,
comment|/* pglue_b.disable_tcpl_translation_size_check .. pglue_b.cpu_mbist_memctrl_3_cntrl_cmd (3 regs) */
literal|0x010aa900
block|,
comment|/* pglue_b.pgl_tgtwr_mlength (1 regs) */
literal|0x070aa905
block|,
comment|/* pglue_b.pgl_exp_rom_addr .. pglue_b.pgl_tags_limit (7 regs) */
literal|0x0e0aa951
block|,
comment|/* pglue_b.master_zlr_err_add_31_0 .. pglue_b.psdm_queue_zone_size (14 regs) */
literal|0x050aa960
block|,
comment|/* pglue_b.sdm_channel_enable .. pglue_b.MASTER_ATTENTION_SETTING (5 regs) */
literal|0x170aab80
block|,
comment|/* pglue_b.write_fifo_occupancy_level .. pglue_b.pcie_ltr_state (23 regs) */
literal|0x070aab9c
block|,
comment|/* pglue_b.mctp_tc .. pglue_b.expansion_rom_attn (7 regs) */
literal|0x010aaba4
block|,
comment|/* pglue_b.mps_attn (1 regs) */
literal|0x060aaba6
block|,
comment|/* pglue_b.vpd_request_pf_31_0 .. pglue_b.sticky_master_error_en (6 regs) */
literal|0x0b060000
block|,
comment|/* block cpmu */
literal|0x0200c088
block|,
comment|/* cpmu.obff_mode_config .. cpmu.obff_mode_control (2 regs) */
literal|0x1300c08b
block|,
comment|/* cpmu.obff_mem_timer_short_threshold .. cpmu.sw_force_l1 (19 regs) */
literal|0x0500c09f
block|,
comment|/* cpmu.ltr_mode_config .. cpmu.sw_force_ltr (5 regs) */
literal|0x0e00c0a5
block|,
comment|/* cpmu.clk_en_config .. cpmu.sw_force_main_clk_slowdown (14 regs) */
literal|0x0300c0b4
block|,
comment|/* cpmu.storm_clk_slowdown_entry_en .. cpmu.sw_force_storm_clk_slowdown (3 regs) */
literal|0x0300c0b8
block|,
comment|/* cpmu.nw_clk_slowdown_entry_en .. cpmu.sw_force_nw_clk_slowdown (3 regs) */
literal|0x0300c0bc
block|,
comment|/* cpmu.pci_clk_slowdown_entry_en .. cpmu.sw_force_pci_clk_slowdown (3 regs) */
literal|0x0900c0c0
block|,
comment|/* cpmu.pxp_vq_empty_status_e0_0 .. cpmu.cpmu_output_sig_status (9 regs) */
literal|0x1000c0cf
block|,
comment|/* cpmu.obff_stall_mem_stat_ro .. cpmu.pcs_duration_stat_ro (16 regs) */
literal|0x1500c0e5
block|,
comment|/* cpmu.obff_stall_mem_stat .. cpmu.INT_MASK_0 (21 regs) */
literal|0x0400c0fc
block|,
comment|/* cpmu.sdm_sq_counter_e0_p0 .. cpmu.sdm_sq_counter_e1_p1 (4 regs) */
literal|0x010a0000
block|,
comment|/* block pcie */
literal|0x04015080
block|,
comment|/* pcie.eco_reserved .. pcie.pcie_debug_bits (4 regs) */
literal|0x180b0000
block|,
comment|/* block mcp */
literal|0x0e380020
block|,
comment|/* mcp.mcp_control .. mcp.mcp_doorbell (14 regs) */
literal|0x09380031
block|,
comment|/* mcp.mcp_vfid .. mcp.gp_event_vec (9 regs) */
literal|0x03381400
block|,
comment|/* mcp.cpu_mode .. mcp.cpu_event_mask (3 regs) */
literal|0x03381407
block|,
comment|/* mcp.cpu_program_counter .. mcp.cpu_data_access (3 regs) */
literal|0x0438140b
block|,
comment|/* mcp.cpu_interrupt_vector .. mcp.cpu_debug_vect_peek (4 regs) */
literal|0x01381412
block|,
comment|/* mcp.cpu_last_branch_addr (1 regs) */
literal|0x0538152a
block|,
comment|/* mcp.mdio_auto_poll .. mcp.mdio_auto_status (5 regs) */
literal|0x0b381640
block|,
comment|/* mcp.ucint_warp_mode .. mcp.ucint_avs_address (11 regs) */
literal|0x02381680
block|,
comment|/* mcp.imc_command .. mcp.imc_slave_control (2 regs) */
literal|0x07381685
block|,
comment|/* mcp.imc_timing0 .. mcp.imc_datareg3 (7 regs) */
literal|0x01381840
block|,
comment|/* mcp.m2p_m2p_status (1 regs) */
literal|0x09381842
block|,
comment|/* mcp.m2p_m2p_vdm_length .. mcp.m2p_m2p_path_id (9 regs) */
literal|0x17381880
block|,
comment|/* mcp.p2m_p2m_status .. mcp.p2m_p2m_other_hdr_fields (23 regs) */
literal|0x023818c0
block|,
comment|/* mcp.cache_pim_nvram_base .. mcp.cache_paging_enable (2 regs) */
literal|0x1b3818c3
block|,
comment|/* mcp.cache_cache_ctrl_status_0 .. mcp.cache_cache_error_status (27 regs) */
literal|0x0d381900
block|,
comment|/* mcp.nvm_command .. mcp.nvm_reconfig (13 regs) */
literal|0x16381a00
block|,
comment|/* mcp.erngn_exp_rom_ctrl .. mcp.erngn_img_loader2_cfg (22 regs) */
literal|0x14382000
block|,
comment|/* mcp.smbus_config .. mcp.smbus_slave_data_read (20 regs) */
literal|0x01382020
block|,
comment|/* mcp.smbus_arp_state (1 regs) */
literal|0x08382024
block|,
comment|/* mcp.smbus_udid0_3 .. mcp.smbus_udid1_0 (8 regs) */
literal|0x013820ff
block|,
comment|/* mcp.smbus_smb_reg_end (1 regs) */
literal|0x02382108
block|,
comment|/* mcp.frm_bmb_fifo_command .. mcp.frm_bmb_fifo_status (2 regs) */
literal|0x0538210b
block|,
comment|/* mcp.frm_bmb_fifo_rd_data .. mcp.frm_bmb_fifo_sop_dscr3 (5 regs) */
literal|0x013821ff
block|,
comment|/* mcp.bmb_reg_end (1 regs) */
literal|0x060d0000
block|,
comment|/* block pswhst */
literal|0x020a8000
block|,
comment|/* pswhst.zone_perm_table_init .. pswhst.zone_perm_table_init_done (2 regs) */
literal|0x1c0a8010
block|,
comment|/* pswhst.discard_internal_writes .. pswhst.is_in_drain_mode (28 regs) */
literal|0x040a802d
block|,
comment|/* pswhst.timeout_data .. pswhst.source_usdm_credits (4 regs) */
literal|0x0d0a8032
block|,
comment|/* pswhst.host_strict_priority .. pswhst.psdm_swap_mode (13 regs) */
literal|0x050a8040
block|,
comment|/* pswhst.dbg_select .. pswhst.dbg_force_frame (5 regs) */
literal|0x020a8060
block|,
comment|/* pswhst.INT_STS .. pswhst.INT_MASK (2 regs) */
literal|0x020e0000
block|,
comment|/* block pswhst2 */
literal|0x0b0a7810
block|,
comment|/* pswhst2.header_fifo_status .. pswhst2.dbg_force_frame (11 regs) */
literal|0x020a7860
block|,
comment|/* pswhst2.INT_STS .. pswhst2.INT_MASK (2 regs) */
literal|0x030f0000
block|,
comment|/* block pswrd */
literal|0x050a7010
block|,
comment|/* pswrd.dbg_select .. pswrd.dbg_force_frame (5 regs) */
literal|0x030a7028
block|,
comment|/* pswrd.eco_reserved .. pswrd.fifo_full_sticky (3 regs) */
literal|0x020a7060
block|,
comment|/* pswrd.INT_STS .. pswrd.INT_MASK (2 regs) */
literal|0x08100000
block|,
comment|/* block pswrd2 */
literal|0x020a7400
block|,
comment|/* pswrd2.start_init .. pswrd2.init_done (2 regs) */
literal|0x040a7418
block|,
comment|/* pswrd2.mask_error_to_clients .. pswrd2.cpl_err_details2 (4 regs) */
literal|0x050a741d
block|,
comment|/* pswrd2.arb_delay .. pswrd2.eco_reserved (5 regs) */
literal|0x060a7430
block|,
comment|/* pswrd2.pbf_swap_mode .. pswrd2.ptu_swap_mode (6 regs) */
literal|0x1e0a7438
block|,
comment|/* pswrd2.almost_full_0 .. pswrd2.max_fill_level_pbf (30 regs) */
literal|0x020a7460
block|,
comment|/* pswrd2.INT_STS .. pswrd2.INT_MASK (2 regs) */
literal|0x050a7500
block|,
comment|/* pswrd2.dbg_select .. pswrd2.dbg_force_frame (5 regs) */
literal|0x140a7518
block|,
comment|/* pswrd2.disable_inputs .. pswrd2.prm_additional_requests (20 regs) */
literal|0x03110000
block|,
comment|/* block pswwr */
literal|0x160a6810
block|,
comment|/* pswwr.usdm_full_th .. pswwr.dbg_force_frame (22 regs) */
literal|0x010a6832
block|,
comment|/* pswwr.eco_reserved (1 regs) */
literal|0x020a6860
block|,
comment|/* pswwr.INT_STS .. pswwr.INT_MASK (2 regs) */
literal|0x03120000
block|,
comment|/* block pswwr2 */
literal|0x030a6c10
block|,
comment|/* pswwr2.cdu_full_th2 .. pswwr2.pglue_eop_err_details (3 regs) */
literal|0x060a6c14
block|,
comment|/* pswwr2.prm_curr_fill_level .. pswwr2.eco_reserved (6 regs) */
literal|0x020a6c60
block|,
comment|/* pswwr2.INT_STS .. pswwr2.INT_MASK (2 regs) */
literal|0x03130000
block|,
comment|/* block pswrq */
literal|0x050a0008
block|,
comment|/* pswrq.dbg_select .. pswrq.dbg_force_frame (5 regs) */
literal|0x010a0018
block|,
comment|/* pswrq.eco_reserved (1 regs) */
literal|0x020a0060
block|,
comment|/* pswrq.INT_STS .. pswrq.INT_MASK (2 regs) */
literal|0x08140000
block|,
comment|/* block pswrq2 */
literal|0x03090000
block|,
comment|/* pswrq2.rbc_done .. pswrq2.reset_stt (3 regs) */
literal|0x0609001e
block|,
comment|/* pswrq2.endianity_00 .. pswrq2.m2p_endian_m (6 regs) */
literal|0x05090040
block|,
comment|/* pswrq2.dbg_select .. pswrq2.dbg_force_frame (5 regs) */
literal|0x02090060
block|,
comment|/* pswrq2.INT_STS .. pswrq2.INT_MASK (2 regs) */
literal|0xfc090100
block|,
comment|/* pswrq2.wr_mbs0 .. pswrq2.atc_vq_enable (252 regs) */
literal|0x250901fd
block|,
comment|/* pswrq2.atc_internal_ats_enable_all .. pswrq2.sr_cnt_window_value (37 regs) */
literal|0x2a090224
block|,
comment|/* pswrq2.sr_cnt_start_mode .. pswrq2.l2p_err_details2 (42 regs) */
literal|0xc609024f
block|,
comment|/* pswrq2.sr_num_cfg .. pswrq2.l2p_validate_vfid (198 regs) */
literal|0x01150000
block|,
comment|/* block pglcs */
literal|0x02000740
block|,
comment|/* pglcs.INT_STS .. pglcs.INT_MASK (2 regs) */
literal|0x05160000
block|,
comment|/* block dmae */
literal|0x01003000
block|,
comment|/* dmae.init (1 regs) */
literal|0x22003010
block|,
comment|/* dmae.pci_ifen .. dmae.go_c31 (34 regs) */
literal|0x02003060
block|,
comment|/* dmae.INT_STS .. dmae.INT_MASK (2 regs) */
literal|0x14003100
block|,
comment|/* dmae.pxp_req_init_crd .. dmae.fsm_st (20 regs) */
literal|0x06003143
block|,
comment|/* dmae.memctrl_status .. dmae.dbg_force_frame (6 regs) */
literal|0x07170000
block|,
comment|/* block ptu */
literal|0x02158000
block|,
comment|/* ptu.atc_init_array .. ptu.atc_init_done (2 regs) */
literal|0x0e158010
block|,
comment|/* ptu.LOG_TRANSPEND_REUSE_MISS_TID .. ptu.inv_err_ctr (14 regs) */
literal|0x14158023
block|,
comment|/* ptu.inv_halt_on_reuse_cnt_err .. ptu.ptu_b0_disable (20 regs) */
literal|0x05158040
block|,
comment|/* ptu.dbg_select .. ptu.dbg_force_frame (5 regs) */
literal|0x02158060
block|,
comment|/* ptu.INT_STS .. ptu.INT_MASK (2 regs) */
literal|0x65158100
block|,
comment|/* ptu.atc_num_sets .. ptu.atc_during_inv (101 regs) */
literal|0x06158173
block|,
comment|/* ptu.dbgsyn_almost_full_thr .. ptu.atc_ireq_fifo_tm (6 regs) */
literal|0x24180000
block|,
comment|/* block tcm */
literal|0x01460000
block|,
comment|/* tcm.init (1 regs) */
literal|0x05460010
block|,
comment|/* tcm.dbg_select .. tcm.dbg_force_frame (5 regs) */
literal|0x02460060
block|,
comment|/* tcm.INT_STS_0 .. tcm.INT_MASK_0 (2 regs) */
literal|0x02460064
block|,
comment|/* tcm.INT_STS_1 .. tcm.INT_MASK_1 (2 regs) */
literal|0x02460068
block|,
comment|/* tcm.INT_STS_2 .. tcm.INT_MASK_2 (2 regs) */
literal|0x01460100
block|,
comment|/* tcm.ifen (1 regs) */
literal|0x08460109
block|,
comment|/* tcm.qm_task_base_evnt_id_0 .. tcm.qm_task_base_evnt_id_7 (8 regs) */
literal|0x10460121
block|,
comment|/* tcm.qm_agg_task_ctx_part_size_0 .. tcm.qm_sm_task_ctx_ldst_flg_7 (16 regs) */
literal|0x08460141
block|,
comment|/* tcm.qm_task_use_st_flg_0 .. tcm.qm_task_use_st_flg_7 (8 regs) */
literal|0x09460151
block|,
comment|/* tcm.tm_task_evnt_id_0 .. tcm.err_evnt_id (9 regs) */
literal|0x02460181
block|,
comment|/* tcm.storm_weight .. tcm.msem_weight (2 regs) */
literal|0x02460184
block|,
comment|/* tcm.dorq_weight .. tcm.pbf_weight (2 regs) */
literal|0x01460187
block|,
comment|/* tcm.grc_weight (1 regs) */
literal|0x0a460189
block|,
comment|/* tcm.qm_p_weight .. tcm.ia_arb_sp_timeout (10 regs) */
literal|0x09460199
block|,
comment|/* tcm.sdm_err_handle_en .. tcm.ia_trans_part_fill_lvl (9 regs) */
literal|0x1b4601c1
block|,
comment|/* tcm.xx_msg_up_bnd .. tcm.xx_tbyp_tbl_up_bnd (27 regs) */
literal|0x054601e4
block|,
comment|/* tcm.xx_byp_lock_msg_thr .. tcm.unlock_miss (5 regs) */
literal|0x04460201
block|,
comment|/* tcm.prcs_agg_con_curr_st .. tcm.prcs_sm_task_curr_st (4 regs) */
literal|0x1b46020d
block|,
comment|/* tcm.n_sm_task_ctx_ld_0 .. tcm.trans_data_buf_crd_dir (27 regs) */
literal|0x0a460230
block|,
comment|/* tcm.agg_task_ctx_size_0 .. tcm.sm_task_ctx_size (10 regs) */
literal|0x06460261
block|,
comment|/* tcm.agg_task_rule0_q .. tcm.agg_task_rule5_q (6 regs) */
literal|0x0d460281
block|,
comment|/* tcm.in_prcs_tbl_crd_agg .. tcm.xx_byp_task_state_evnt_id_flg (13 regs) */
literal|0x054602a1
block|,
comment|/* tcm.ccfc_init_crd .. tcm.fic_init_crd (5 regs) */
literal|0x014602a9
block|,
comment|/* tcm.dir_byp_msg_cnt (1 regs) */
literal|0x024602ab
block|,
comment|/* tcm.dorq_length_mis .. tcm.pbf_length_mis (2 regs) */
literal|0x034602ae
block|,
comment|/* tcm.grc_buf_empty .. tcm.storm_msg_cntr (3 regs) */
literal|0x014602b2
block|,
comment|/* tcm.msem_msg_cntr (1 regs) */
literal|0x024602b4
block|,
comment|/* tcm.dorq_msg_cntr .. tcm.pbf_msg_cntr (2 regs) */
literal|0x034602b7
block|,
comment|/* tcm.qm_p_msg_cntr .. tcm.tm_msg_cntr (3 regs) */
literal|0x044602bb
block|,
comment|/* tcm.is_qm_p_fill_lvl .. tcm.is_storm_fill_lvl (4 regs) */
literal|0x014602c0
block|,
comment|/* tcm.is_msem_fill_lvl (1 regs) */
literal|0x024602c2
block|,
comment|/* tcm.is_dorq_fill_lvl .. tcm.is_pbf_fill_lvl (2 regs) */
literal|0x074602d1
block|,
comment|/* tcm.fic_msg_cntr .. tcm.tcfc_cntr (7 regs) */
literal|0x034602e1
block|,
comment|/* tcm.eco_reserved .. tcm.is_foc_msem_nxt_inf_unit (3 regs) */
literal|0x024602e6
block|,
comment|/* tcm.is_foc_pbf_nxt_inf_unit .. tcm.is_foc_dorq_nxt_inf_unit (2 regs) */
literal|0x05460530
block|,
comment|/* tcm.ctx_rbc_accs .. tcm.sm_task_ctx (5 regs) */
literal|0x21190000
block|,
comment|/* block mcm */
literal|0x01480000
block|,
comment|/* mcm.init (1 regs) */
literal|0x05480010
block|,
comment|/* mcm.dbg_select .. mcm.dbg_force_frame (5 regs) */
literal|0x02480060
block|,
comment|/* mcm.INT_STS_0 .. mcm.INT_MASK_0 (2 regs) */
literal|0x02480064
block|,
comment|/* mcm.INT_STS_1 .. mcm.INT_MASK_1 (2 regs) */
literal|0x02480068
block|,
comment|/* mcm.INT_STS_2 .. mcm.INT_MASK_2 (2 regs) */
literal|0x01480100
block|,
comment|/* mcm.ifen (1 regs) */
literal|0x08480109
block|,
comment|/* mcm.qm_task_base_evnt_id_0 .. mcm.qm_task_base_evnt_id_7 (8 regs) */
literal|0x20480121
block|,
comment|/* mcm.qm_agg_task_ctx_part_size_0 .. mcm.qm_tcfc_xxlock_cmd_7 (32 regs) */
literal|0x09480151
block|,
comment|/* mcm.qm_task_use_st_flg_0 .. mcm.err_evnt_id (9 regs) */
literal|0x02480181
block|,
comment|/* mcm.storm_weight .. mcm.usem_weight (2 regs) */
literal|0x02480184
block|,
comment|/* mcm.pbf_weight .. mcm.grc_weight (2 regs) */
literal|0x0c480187
block|,
comment|/* mcm.ysdm_weight .. mcm.ia_arb_sp_timeout (12 regs) */
literal|0x0948019b
block|,
comment|/* mcm.sdm_err_handle_en .. mcm.ia_trans_part_fill_lvl (9 regs) */
literal|0x1b4801c1
block|,
comment|/* mcm.xx_msg_up_bnd .. mcm.xx_tbyp_tbl_up_bnd (27 regs) */
literal|0x054801e4
block|,
comment|/* mcm.xx_byp_lock_msg_thr .. mcm.unlock_miss (5 regs) */
literal|0x04480201
block|,
comment|/* mcm.prcs_agg_con_curr_st .. mcm.prcs_sm_task_curr_st (4 regs) */
literal|0x1b48020d
block|,
comment|/* mcm.n_sm_task_ctx_ld_0 .. mcm.trans_data_buf_crd_dir (27 regs) */
literal|0x0a480230
block|,
comment|/* mcm.agg_task_ctx_size_0 .. mcm.sm_task_ctx_size (10 regs) */
literal|0x07480250
block|,
comment|/* mcm.agg_task_rule0_q .. mcm.agg_task_rule6_q (7 regs) */
literal|0x0b480281
block|,
comment|/* mcm.in_prcs_tbl_crd_agg .. mcm.xx_byp_task_state_evnt_id_flg (11 regs) */
literal|0x064802a1
block|,
comment|/* mcm.ccfc_init_crd .. mcm.fic_init_crd (6 regs) */
literal|0x014802a9
block|,
comment|/* mcm.dir_byp_msg_cnt (1 regs) */
literal|0x074802ab
block|,
comment|/* mcm.ysdm_length_mis .. mcm.storm_msg_cntr (7 regs) */
literal|0x044802b3
block|,
comment|/* mcm.ysdm_msg_cntr .. mcm.usem_msg_cntr (4 regs) */
literal|0x034802b8
block|,
comment|/* mcm.pbf_msg_cntr .. mcm.qm_s_msg_cntr (3 regs) */
literal|0x034802bc
block|,
comment|/* mcm.is_qm_p_fill_lvl .. mcm.is_storm_fill_lvl (3 regs) */
literal|0x044802c0
block|,
comment|/* mcm.is_ysdm_fill_lvl .. mcm.is_usem_fill_lvl (4 regs) */
literal|0x014802c5
block|,
comment|/* mcm.is_pbf_fill_lvl (1 regs) */
literal|0x074802d1
block|,
comment|/* mcm.fic_msg_cntr .. mcm.tcfc_cntr (7 regs) */
literal|0x034802e1
block|,
comment|/* mcm.eco_reserved .. mcm.is_foc_usem_nxt_inf_unit (3 regs) */
literal|0x014802e5
block|,
comment|/* mcm.is_foc_pbf_nxt_inf_unit (1 regs) */
literal|0x034802e7
block|,
comment|/* mcm.is_foc_usdm_nxt_inf_unit .. mcm.is_foc_tmld_nxt_inf_unit (3 regs) */
literal|0x05480600
block|,
comment|/* mcm.ctx_rbc_accs .. mcm.sm_task_ctx (5 regs) */
literal|0x1d1a0000
block|,
comment|/* block ucm */
literal|0x014a0000
block|,
comment|/* ucm.init (1 regs) */
literal|0x064a0013
block|,
comment|/* ucm.memctrl_status .. ucm.dbg_force_frame (6 regs) */
literal|0x024a0060
block|,
comment|/* ucm.INT_STS_0 .. ucm.INT_MASK_0 (2 regs) */
literal|0x024a0064
block|,
comment|/* ucm.INT_STS_1 .. ucm.INT_MASK_1 (2 regs) */
literal|0x024a0068
block|,
comment|/* ucm.INT_STS_2 .. ucm.INT_MASK_2 (2 regs) */
literal|0x014a0100
block|,
comment|/* ucm.ifen (1 regs) */
literal|0x084a0109
block|,
comment|/* ucm.qm_task_base_evnt_id_0 .. ucm.qm_task_base_evnt_id_7 (8 regs) */
literal|0x104a0121
block|,
comment|/* ucm.qm_agg_task_ctx_part_size_0 .. ucm.qm_sm_task_ctx_ldst_flg_7 (16 regs) */
literal|0x084a0141
block|,
comment|/* ucm.qm_task_use_st_flg_0 .. ucm.qm_task_use_st_flg_7 (8 regs) */
literal|0x094a0151
block|,
comment|/* ucm.tm_task_evnt_id_0 .. ucm.err_evnt_id (9 regs) */
literal|0x0a4a0181
block|,
comment|/* ucm.storm_weight .. ucm.muld_weight (10 regs) */
literal|0x0a4a018c
block|,
comment|/* ucm.qm_p_weight .. ucm.ia_arb_sp_timeout (10 regs) */
literal|0x094a01a1
block|,
comment|/* ucm.sdm_err_handle_en .. ucm.ia_trans_part_fill_lvl (9 regs) */
literal|0x1b4a01c1
block|,
comment|/* ucm.xx_msg_up_bnd .. ucm.xx_tbyp_tbl_up_bnd (27 regs) */
literal|0x054a01e4
block|,
comment|/* ucm.xx_byp_lock_msg_thr .. ucm.unlock_miss (5 regs) */
literal|0x044a0201
block|,
comment|/* ucm.prcs_agg_con_curr_st .. ucm.prcs_sm_task_curr_st (4 regs) */
literal|0x1b4a020d
block|,
comment|/* ucm.n_sm_task_ctx_ld_0 .. ucm.trans_data_buf_crd_dir (27 regs) */
literal|0x0a4a0230
block|,
comment|/* ucm.agg_task_ctx_size_0 .. ucm.sm_task_ctx_size (10 regs) */
literal|0x074a025a
block|,
comment|/* ucm.agg_task_rule0_q .. ucm.agg_task_rule6_q (7 regs) */
literal|0x0d4a0281
block|,
comment|/* ucm.in_prcs_tbl_crd_agg .. ucm.xx_byp_task_state_evnt_id_flg (13 regs) */
literal|0x054a02a1
block|,
comment|/* ucm.ccfc_init_crd .. ucm.fic_init_crd (5 regs) */
literal|0x094a02a9
block|,
comment|/* ucm.dir_byp_msg_cnt .. ucm.muld_length_mis (9 regs) */
literal|0x094a02b3
block|,
comment|/* ucm.grc_buf_empty .. ucm.muld_msg_cntr (9 regs) */
literal|0x054a02bd
block|,
comment|/* ucm.dorq_msg_cntr .. ucm.tm_msg_cntr (5 regs) */
literal|0x0a4a02c3
block|,
comment|/* ucm.is_qm_p_fill_lvl .. ucm.is_muld_fill_lvl (10 regs) */
literal|0x024a02ce
block|,
comment|/* ucm.is_dorq_fill_lvl .. ucm.is_pbf_fill_lvl (2 regs) */
literal|0x094a02d1
block|,
comment|/* ucm.fic_msg_cntr .. ucm.tcfc_cntr (9 regs) */
literal|0x0a4a02e1
block|,
comment|/* ucm.eco_reserved .. ucm.is_foc_muld_nxt_inf_unit (10 regs) */
literal|0x054a05c0
block|,
comment|/* ucm.ctx_rbc_accs .. ucm.sm_task_ctx (5 regs) */
literal|0x1f1b0000
block|,
comment|/* block xcm */
literal|0x01400000
block|,
comment|/* xcm.init (1 regs) */
literal|0x01400002
block|,
comment|/* xcm.qm_act_st_cnt_init_done (1 regs) */
literal|0x05400010
block|,
comment|/* xcm.dbg_select .. xcm.dbg_force_frame (5 regs) */
literal|0x02400060
block|,
comment|/* xcm.INT_STS_0 .. xcm.INT_MASK_0 (2 regs) */
literal|0x02400064
block|,
comment|/* xcm.INT_STS_1 .. xcm.INT_MASK_1 (2 regs) */
literal|0x02400068
block|,
comment|/* xcm.INT_STS_2 .. xcm.INT_MASK_2 (2 regs) */
literal|0x01400100
block|,
comment|/* xcm.ifen (1 regs) */
literal|0x01400131
block|,
comment|/* xcm.err_evnt_id (1 regs) */
literal|0x03400181
block|,
comment|/* xcm.storm_weight .. xcm.usem_weight (3 regs) */
literal|0x03400185
block|,
comment|/* xcm.dorq_weight .. xcm.grc_weight (3 regs) */
literal|0x0d400189
block|,
comment|/* xcm.xsdm_weight .. xcm.ia_arb_sp_timeout (13 regs) */
literal|0x064001a0
block|,
comment|/* xcm.sdm_err_handle_en .. xcm.ia_trans_part_fill_lvl (6 regs) */
literal|0x184001c1
block|,
comment|/* xcm.xx_msg_up_bnd .. xcm.xx_cbyp_tbl_up_bnd (24 regs) */
literal|0x054001e1
block|,
comment|/* xcm.xx_byp_lock_msg_thr .. xcm.unlock_miss (5 regs) */
literal|0x02400201
block|,
comment|/* xcm.prcs_agg_con_curr_st .. xcm.prcs_sm_con_curr_st (2 regs) */
literal|0x0a40020b
block|,
comment|/* xcm.agg_con_fic_buf_fill_lvl .. xcm.trans_data_buf_crd_dir (10 regs) */
literal|0x0240021d
block|,
comment|/* xcm.cm_con_reg0_sz .. xcm.sm_con_ctx_size (2 regs) */
literal|0x09400281
block|,
comment|/* xcm.in_prcs_tbl_crd_agg .. xcm.xx_byp_con_state_evnt_id_flg (9 regs) */
literal|0x054002a1
block|,
comment|/* xcm.ccfc_init_crd .. xcm.fic_init_crd (5 regs) */
literal|0x014002a9
block|,
comment|/* xcm.dir_byp_msg_cnt (1 regs) */
literal|0x084002ab
block|,
comment|/* xcm.xsdm_length_mis .. xcm.storm_msg_cntr (8 regs) */
literal|0x054002b4
block|,
comment|/* xcm.xsdm_msg_cntr .. xcm.usem_msg_cntr (5 regs) */
literal|0x054002ba
block|,
comment|/* xcm.dorq_msg_cntr .. xcm.tm_msg_cntr (5 regs) */
literal|0x044002c0
block|,
comment|/* xcm.is_qm_p_fill_lvl .. xcm.is_storm_fill_lvl (4 regs) */
literal|0x054002c5
block|,
comment|/* xcm.is_xsdm_fill_lvl .. xcm.is_usem_fill_lvl (5 regs) */
literal|0x024002cb
block|,
comment|/* xcm.is_dorq_fill_lvl .. xcm.is_pbf_fill_lvl (2 regs) */
literal|0x0b4002d1
block|,
comment|/* xcm.qm_act_st_fifo_fill_lvl .. xcm.ccfc_cntr (11 regs) */
literal|0x044002e1
block|,
comment|/* xcm.eco_reserved .. xcm.is_foc_xsem_nxt_inf_unit (4 regs) */
literal|0x024002e6
block|,
comment|/* xcm.is_foc_pbf_nxt_inf_unit .. xcm.is_foc_dorq_nxt_inf_unit (2 regs) */
literal|0x034002e9
block|,
comment|/* xcm.is_foc_usdm_nxt_inf_unit .. xcm.is_foc_ysdm_nxt_inf_unit (3 regs) */
literal|0x03400600
block|,
comment|/* xcm.ctx_rbc_accs .. xcm.sm_con_ctx (3 regs) */
literal|0x1d1c0000
block|,
comment|/* block ycm */
literal|0x01420000
block|,
comment|/* ycm.init (1 regs) */
literal|0x05420010
block|,
comment|/* ycm.dbg_select .. ycm.dbg_force_frame (5 regs) */
literal|0x02420060
block|,
comment|/* ycm.INT_STS_0 .. ycm.INT_MASK_0 (2 regs) */
literal|0x02420064
block|,
comment|/* ycm.INT_STS_1 .. ycm.INT_MASK_1 (2 regs) */
literal|0x02420068
block|,
comment|/* ycm.INT_STS_2 .. ycm.INT_MASK_2 (2 regs) */
literal|0x01420100
block|,
comment|/* ycm.ifen (1 regs) */
literal|0x08420109
block|,
comment|/* ycm.qm_task_base_evnt_id_0 .. ycm.qm_task_base_evnt_id_7 (8 regs) */
literal|0x20420121
block|,
comment|/* ycm.qm_agg_task_ctx_part_size_0 .. ycm.qm_tcfc_xxlock_cmd_7 (32 regs) */
literal|0x09420151
block|,
comment|/* ycm.qm_task_use_st_flg_0 .. ycm.err_evnt_id (9 regs) */
literal|0x05420181
block|,
comment|/* ycm.storm_weight .. ycm.grc_weight (5 regs) */
literal|0x0b420187
block|,
comment|/* ycm.ysdm_weight .. ycm.ia_arb_sp_timeout (11 regs) */
literal|0x09420199
block|,
comment|/* ycm.sdm_err_handle_en .. ycm.ia_trans_part_fill_lvl (9 regs) */
literal|0x1b4201c1
block|,
comment|/* ycm.xx_msg_up_bnd .. ycm.xx_tbyp_tbl_up_bnd (27 regs) */
literal|0x054201e4
block|,
comment|/* ycm.xx_byp_lock_msg_thr .. ycm.unlock_miss (5 regs) */
literal|0x04420201
block|,
comment|/* ycm.prcs_agg_con_curr_st .. ycm.prcs_sm_task_curr_st (4 regs) */
literal|0x1b42020d
block|,
comment|/* ycm.n_sm_task_ctx_ld_0 .. ycm.trans_data_buf_crd_dir (27 regs) */
literal|0x0a420230
block|,
comment|/* ycm.agg_task_ctx_size_0 .. ycm.sm_task_ctx_size (10 regs) */
literal|0x0b420281
block|,
comment|/* ycm.in_prcs_tbl_crd_agg .. ycm.xx_byp_task_state_evnt_id_flg (11 regs) */
literal|0x064202a1
block|,
comment|/* ycm.ccfc_init_crd .. ycm.fic_init_crd (6 regs) */
literal|0x014202a9
block|,
comment|/* ycm.dir_byp_msg_cnt (1 regs) */
literal|0x064202ab
block|,
comment|/* ycm.ysdm_length_mis .. ycm.storm_msg_cntr (6 regs) */
literal|0x074202b2
block|,
comment|/* ycm.ysdm_msg_cntr .. ycm.qm_s_msg_cntr (7 regs) */
literal|0x034202ba
block|,
comment|/* ycm.is_qm_p_fill_lvl .. ycm.is_storm_fill_lvl (3 regs) */
literal|0x054202be
block|,
comment|/* ycm.is_ysdm_fill_lvl .. ycm.is_pbf_fill_lvl (5 regs) */
literal|0x084202d1
block|,
comment|/* ycm.fic_msg_cntr .. ycm.tcfc_cntr (8 regs) */
literal|0x034202e1
block|,
comment|/* ycm.eco_reserved .. ycm.is_foc_usem_nxt_inf_unit (3 regs) */
literal|0x014202e5
block|,
comment|/* ycm.is_foc_pbf_nxt_inf_unit (1 regs) */
literal|0x024202e7
block|,
comment|/* ycm.is_foc_ysdm_nxt_inf_unit .. ycm.is_foc_xyld_nxt_inf_unit (2 regs) */
literal|0x05420600
block|,
comment|/* ycm.ctx_rbc_accs .. ycm.sm_task_ctx (5 regs) */
literal|0x151d0000
block|,
comment|/* block pcm */
literal|0x01440000
block|,
comment|/* pcm.init (1 regs) */
literal|0x05440010
block|,
comment|/* pcm.dbg_select .. pcm.dbg_force_frame (5 regs) */
literal|0x02440060
block|,
comment|/* pcm.INT_STS_0 .. pcm.INT_MASK_0 (2 regs) */
literal|0x02440064
block|,
comment|/* pcm.INT_STS_1 .. pcm.INT_MASK_1 (2 regs) */
literal|0x02440068
block|,
comment|/* pcm.INT_STS_2 .. pcm.INT_MASK_2 (2 regs) */
literal|0x02440100
block|,
comment|/* pcm.ifen .. pcm.err_evnt_id (2 regs) */
literal|0x01440181
block|,
comment|/* pcm.storm_weight (1 regs) */
literal|0x01440183
block|,
comment|/* pcm.grc_weight (1 regs) */
literal|0x07440185
block|,
comment|/* pcm.ia_group_pr0 .. pcm.ia_arb_sp_timeout (7 regs) */
literal|0x0544018f
block|,
comment|/* pcm.sdm_err_handle_en .. pcm.ia_trans_part_fill_lvl (5 regs) */
literal|0x184401c1
block|,
comment|/* pcm.xx_msg_up_bnd .. pcm.unlock_miss (24 regs) */
literal|0x01440201
block|,
comment|/* pcm.prcs_sm_con_curr_st (1 regs) */
literal|0x0644020a
block|,
comment|/* pcm.sm_con_fic_buf_fill_lvl .. pcm.sm_con_ctx_size (6 regs) */
literal|0x07440281
block|,
comment|/* pcm.in_prcs_tbl_crd_agg .. pcm.xx_byp_con_state_evnt_id_flg (7 regs) */
literal|0x024402a1
block|,
comment|/* pcm.ccfc_init_crd .. pcm.fic_init_crd (2 regs) */
literal|0x014402a9
block|,
comment|/* pcm.dir_byp_msg_cnt (1 regs) */
literal|0x034402ac
block|,
comment|/* pcm.grc_buf_empty .. pcm.storm_msg_cntr (3 regs) */
literal|0x014402b2
block|,
comment|/* pcm.is_storm_fill_lvl (1 regs) */
literal|0x024402d1
block|,
comment|/* pcm.fic_msg_cntr .. pcm.ccfc_cntr (2 regs) */
literal|0x024402e1
block|,
comment|/* pcm.eco_reserved .. pcm.is_foc_psem_nxt_inf_unit (2 regs) */
literal|0x02440510
block|,
comment|/* pcm.ctx_rbc_accs .. pcm.sm_con_ctx (2 regs) */
literal|0x1c1e0000
block|,
comment|/* block qm */
literal|0x020bc060
block|,
comment|/* qm.INT_STS .. qm.INT_MASK (2 regs) */
literal|0x0d0bc100
block|,
comment|/* qm.wrc_drop_cnt_0 .. qm.cm_push_int_en (13 regs) */
literal|0x380bc110
block|,
comment|/* qm.MaxPqSizeTxSel_0 .. qm.MaxPqSizeTxSel_55 (56 regs) */
literal|0x040bc200
block|,
comment|/* qm.OutLdReqSizeConnTx .. qm.OutLdReqCrdConnOther (4 regs) */
literal|0x0e0bc410
block|,
comment|/* qm.QstatusTx_0 .. qm.QstatusTx_13 (14 regs) */
literal|0x020bc430
block|,
comment|/* qm.QstatusOther_0 .. qm.QstatusOther_1 (2 regs) */
literal|0x280bc488
block|,
comment|/* qm.CtxRegTcfc_0 .. qm.CtxRegTcfc_39 (40 regs) */
literal|0x280bc508
block|,
comment|/* qm.ActCtrInitValTcfc_0 .. qm.ActCtrInitValTcfc_39 (40 regs) */
literal|0x040bc548
block|,
comment|/* qm.PciReqQId .. qm.QmPageSize (4 regs) */
literal|0x050bc54d
block|,
comment|/* qm.PciReqPadToCacheLine .. qm.OvfErrorOther (5 regs) */
literal|0x010bc580
block|,
comment|/* qm.VoqCrdLineFull (1 regs) */
literal|0x010bc5c0
block|,
comment|/* qm.TaskLineCrdCost (1 regs) */
literal|0x010bc600
block|,
comment|/* qm.VoqCrdByteFull (1 regs) */
literal|0x220bc640
block|,
comment|/* qm.TaskByteCrdCost_0 .. qm.WrrOtherPqGrp_7 (34 regs) */
literal|0x040bc67a
block|,
comment|/* qm.WrrOtherGrpWeight_0 .. qm.WrrOtherGrpWeight_3 (4 regs) */
literal|0x170bc682
block|,
comment|/* qm.WrrTxGrpWeight_0 .. qm.CmIntEn (23 regs) */
literal|0x010bc780
block|,
comment|/* qm.VoqByteCrdEnable (1 regs) */
literal|0x040bc900
block|,
comment|/* qm.MHQTxNumSel .. qm.QOtherLevelMHVal (4 regs) */
literal|0x390bcb00
block|,
comment|/* qm.Soft_Reset .. qm.PqTx2Pf_55 (57 regs) */
literal|0x080bcb81
block|,
comment|/* qm.PqOther2Pf_0 .. qm.PqOther2Pf_7 (8 regs) */
literal|0x090bcb99
block|,
comment|/* qm.arb_tx_en .. qm.dbg_force_frame (9 regs) */
literal|0x020bcba6
block|,
comment|/* qm.eco_reserved .. qm.TxPqMap_MaskAccess (2 regs) */
literal|0x0f0bcbaf
block|,
comment|/* qm.Xsdm_Fifo_Full_Thr .. qm.RlGlblPeriodSel_7 (15 regs) */
literal|0x090bd300
block|,
comment|/* qm.RlGlblEnable .. qm.RlPfPeriodTimer (9 regs) */
literal|0x060bd380
block|,
comment|/* qm.RlPfEnable .. qm.Err_Mask_RlPfCrd (6 regs) */
literal|0x130bd700
block|,
comment|/* qm.WfqPfEnable .. qm.Voq_Arb_Grp0_Weight_7 (19 regs) */
literal|0x080bd72b
block|,
comment|/* qm.Voq_Arb_Grp1_Weight_0 .. qm.Voq_Arb_Grp1_Weight_7 (8 regs) */
literal|0x200bd74b
block|,
comment|/* qm.Voq_Arb_Timeout .. qm.cam_bist_status (32 regs) */
literal|0x0a1f0000
block|,
comment|/* block tm */
literal|0x100b0000
block|,
comment|/* tm.memory_self_init_start .. tm.ac_command_fifo_init (16 regs) */
literal|0x040b0018
block|,
comment|/* tm.pxp_interface_enable .. tm.client_in_interface_enable (4 regs) */
literal|0x050b001e
block|,
comment|/* tm.pxp_request_credit .. tm.load_request_credit (5 regs) */
literal|0x020b0060
block|,
comment|/* tm.INT_STS_0 .. tm.INT_MASK_0 (2 regs) */
literal|0x020b0064
block|,
comment|/* tm.INT_STS_1 .. tm.INT_MASK_1 (2 regs) */
literal|0x0b0b0100
block|,
comment|/* tm.pxp_read_data_fifo_a_f_thr .. tm.ac_command_fifo_a_f_thr (11 regs) */
literal|0x2d0b0112
block|,
comment|/* tm.tick_timer_val .. tm.task_timer_threshold_2 (45 regs) */
literal|0x030b0143
block|,
comment|/* tm.during_scan_conn .. tm.during_scan (3 regs) */
literal|0x1f0b0180
block|,
comment|/* tm.completed_scans .. tm.pxp_read_data_error (31 regs) */
literal|0x2f0b01c0
block|,
comment|/* tm.current_time .. tm.dbg_force_frame (47 regs) */
literal|0x18200000
block|,
comment|/* block dorq */
literal|0x01040000
block|,
comment|/* dorq.INIT (1 regs) */
literal|0x01040010
block|,
comment|/* dorq.ifen (1 regs) */
literal|0x02040060
block|,
comment|/* dorq.INT_STS .. dorq.INT_MASK (2 regs) */
literal|0x15040118
block|,
comment|/* dorq.dems_target_1 .. dorq.dems_agg_cmd_7 (21 regs) */
literal|0x0204013d
block|,
comment|/* dorq.pwm_agg_cmd .. dorq.cm_ac_upd (2 regs) */
literal|0x05040180
block|,
comment|/* dorq.dpm_l2_succ_cflg_cmd .. dorq.dpm_l2_abrt_agg_cmd (5 regs) */
literal|0x030401be
block|,
comment|/* dorq.xcm_agg_type .. dorq.tcm_agg_type (3 regs) */
literal|0x010401c2
block|,
comment|/* dorq.xcm_sm_ctx_ld_st_flg_dpm (1 regs) */
literal|0x07040200
block|,
comment|/* dorq.xcm_ccfc_regn .. dorq.dpm_xcm_db_abrt_th (7 regs) */
literal|0x06040208
block|,
comment|/* dorq.dpm_ent_abrt_th .. dorq.dpm_timeout (6 regs) */
literal|0x0304020f
block|,
comment|/* dorq.dq_pxp_full_en .. dorq.dq_full_cycles (3 regs) */
literal|0x04040229
block|,
comment|/* dorq.grh_nxt_header .. dorq.crc32_bswap (4 regs) */
literal|0x01040233
block|,
comment|/* dorq.rroce_dst_udp_port (1 regs) */
literal|0x01040240
block|,
comment|/* dorq.l2_edpm_num_bd_thr (1 regs) */
literal|0x08040243
block|,
comment|/* dorq.l2_edpm_tunnel_gre_eth_en .. dorq.l2_edpm_pkt_hdr_size (8 regs) */
literal|0x04040260
block|,
comment|/* dorq.xcm_msg_init_crd .. dorq.pbf_cmd_init_crd (4 regs) */
literal|0x03040277
block|,
comment|/* dorq.db_drop_reason_mask .. dorq.auto_freeze_st (3 regs) */
literal|0x0204027b
block|,
comment|/* dorq.auto_drop_en .. dorq.auto_drop_st (2 regs) */
literal|0x0c04027e
block|,
comment|/* dorq.pxp_trans_size .. dorq.db_drop_details (12 regs) */
literal|0x0704028b
block|,
comment|/* dorq.db_drop_reason .. dorq.dpm_abort_details_reason (7 regs) */
literal|0x11040293
block|,
comment|/* dorq.dpm_abort_reason .. dorq.cfc_bypass_cnt (17 regs) */
literal|0x048402a4
block|,
comment|/* dorq.mini_cache_entry .. dorq.cfc_lcres_err_detail (4 regs, WB) */
literal|0x030402a8
block|,
comment|/* dorq.cfc_ld_req_cnt .. dorq.eco_reserved (3 regs) */
literal|0x060402b3
block|,
comment|/* dorq.memctrl_status .. dorq.dbg_force_frame (6 regs) */
literal|0x33210000
block|,
comment|/* block brb */
literal|0x030d0001
block|,
comment|/* brb.hw_init_en .. brb.start_en (3 regs) */
literal|0x020d0030
block|,
comment|/* brb.INT_STS_0 .. brb.INT_MASK_0 (2 regs) */
literal|0x020d0036
block|,
comment|/* brb.INT_STS_1 .. brb.INT_MASK_1 (2 regs) */
literal|0x020d003c
block|,
comment|/* brb.INT_STS_2 .. brb.INT_MASK_2 (2 regs) */
literal|0x020d0042
block|,
comment|/* brb.INT_STS_3 .. brb.INT_MASK_3 (2 regs) */
literal|0x020d0048
block|,
comment|/* brb.INT_STS_4 .. brb.INT_MASK_4 (2 regs) */
literal|0x020d004e
block|,
comment|/* brb.INT_STS_5 .. brb.INT_MASK_5 (2 regs) */
literal|0x020d0054
block|,
comment|/* brb.INT_STS_6 .. brb.INT_MASK_6 (2 regs) */
literal|0x020d005a
block|,
comment|/* brb.INT_STS_7 .. brb.INT_MASK_7 (2 regs) */
literal|0x020d0061
block|,
comment|/* brb.INT_STS_8 .. brb.INT_MASK_8 (2 regs) */
literal|0x020d0067
block|,
comment|/* brb.INT_STS_9 .. brb.INT_MASK_9 (2 regs) */
literal|0x020d006d
block|,
comment|/* brb.INT_STS_10 .. brb.INT_MASK_10 (2 regs) */
literal|0x020d0073
block|,
comment|/* brb.INT_STS_11 .. brb.INT_MASK_11 (2 regs) */
literal|0x010d0200
block|,
comment|/* brb.big_ram_address (1 regs) */
literal|0x020d0210
block|,
comment|/* brb.max_releases .. brb.stop_on_len_err (2 regs) */
literal|0x120d0240
block|,
comment|/* brb.tc_guarantied_0 .. brb.tc_guarantied_17 (18 regs) */
literal|0x100d025e
block|,
comment|/* brb.main_tc_guarantied_hyst_0 .. brb.main_tc_guarantied_hyst_15 (16 regs) */
literal|0x120d0276
block|,
comment|/* brb.lb_tc_guarantied_hyst_0 .. brb.lb_tc_guarantied_hyst_17 (18 regs) */
literal|0x100d0294
block|,
comment|/* brb.main_tc_pause_xoff_threshold_0 .. brb.main_tc_pause_xoff_threshold_15 (16 regs) */
literal|0x120d02ac
block|,
comment|/* brb.lb_tc_pause_xoff_threshold_0 .. brb.lb_tc_pause_xoff_threshold_17 (18 regs) */
literal|0x100d02ca
block|,
comment|/* brb.main_tc_pause_xon_threshold_0 .. brb.main_tc_pause_xon_threshold_15 (16 regs) */
literal|0x120d02e2
block|,
comment|/* brb.lb_tc_pause_xon_threshold_0 .. brb.lb_tc_pause_xon_threshold_17 (18 regs) */
literal|0x100d0300
block|,
comment|/* brb.main_tc_full_xoff_threshold_0 .. brb.main_tc_full_xoff_threshold_15 (16 regs) */
literal|0x120d0318
block|,
comment|/* brb.lb_tc_full_xoff_threshold_0 .. brb.lb_tc_full_xoff_threshold_17 (18 regs) */
literal|0x100d0336
block|,
comment|/* brb.main_tc_full_xon_threshold_0 .. brb.main_tc_full_xon_threshold_15 (16 regs) */
literal|0x120d034e
block|,
comment|/* brb.lb_tc_full_xon_threshold_0 .. brb.lb_tc_full_xon_threshold_17 (18 regs) */
literal|0x080d036c
block|,
comment|/* brb.lossless_threshold .. brb.rc_pkt_priority (8 regs) */
literal|0x110d0382
block|,
comment|/* brb.rc_sop_priority .. brb.pm_tc_latency_sensitive_1 (17 regs) */
literal|0x080d03b1
block|,
comment|/* brb.dbgsyn_almost_full_thr .. brb.dbg_force_frame (8 regs) */
literal|0x060d03ca
block|,
comment|/* brb.inp_if_enable .. brb.wc_empty_3 (6 regs) */
literal|0x040d03dc
block|,
comment|/* brb.wc_full_0 .. brb.wc_full_3 (4 regs) */
literal|0x070d03ec
block|,
comment|/* brb.wc_bandwidth_if_full .. brb.rc_pkt_empty_4 (7 regs) */
literal|0x050d03fd
block|,
comment|/* brb.rc_pkt_full_0 .. brb.rc_pkt_full_4 (5 regs) */
literal|0x050d040c
block|,
comment|/* brb.rc_pkt_status_0 .. brb.rc_pkt_status_4 (5 regs) */
literal|0x0b0d041b
block|,
comment|/* brb.rc_sop_empty .. brb.empty_if_1 (11 regs) */
literal|0x050d042a
block|,
comment|/* brb.rc_sop_inp_sync_fifo_push_status .. brb.rc_inp_sync_fifo_push_status_3 (5 regs) */
literal|0x050d043a
block|,
comment|/* brb.rc_out_sync_fifo_push_status_0 .. brb.rc_out_sync_fifo_push_status_4 (5 regs) */
literal|0x010d0449
block|,
comment|/* brb.rc_eop_inp_sync_fifo_push_status_0 (1 regs) */
literal|0x010d0458
block|,
comment|/* brb.rc_eop_out_sync_fifo_push_status_0 (1 regs) */
literal|0x040d0467
block|,
comment|/* brb.pkt_avail_sync_fifo_push_status .. brb.rc_pkt_state (4 regs) */
literal|0x020d046e
block|,
comment|/* brb.mac_free_shared_hr_0 .. brb.mac_free_shared_hr_1 (2 regs) */
literal|0x090d0474
block|,
comment|/* brb.mac0_tc_occupancy_0 .. brb.mac0_tc_occupancy_8 (9 regs) */
literal|0x090d0484
block|,
comment|/* brb.mac1_tc_occupancy_0 .. brb.mac1_tc_occupancy_8 (9 regs) */
literal|0x020d04b4
block|,
comment|/* brb.available_mac_size_0 .. brb.available_mac_size_1 (2 regs) */
literal|0x020d04ba
block|,
comment|/* brb.main_tc_pause_0 .. brb.main_tc_pause_1 (2 regs) */
literal|0x020d04c0
block|,
comment|/* brb.lb_tc_pause_0 .. brb.lb_tc_pause_1 (2 regs) */
literal|0x020d04c6
block|,
comment|/* brb.main_tc_full_0 .. brb.main_tc_full_1 (2 regs) */
literal|0x020d04cc
block|,
comment|/* brb.lb_tc_full_0 .. brb.lb_tc_full_1 (2 regs) */
literal|0x080d04d2
block|,
comment|/* brb.main0_tc_lossless_cnt_0 .. brb.main0_tc_lossless_cnt_7 (8 regs) */
literal|0x080d04e2
block|,
comment|/* brb.main1_tc_lossless_cnt_0 .. brb.main1_tc_lossless_cnt_7 (8 regs) */
literal|0x020d0512
block|,
comment|/* brb.main_tc_lossless_int_0 .. brb.main_tc_lossless_int_1 (2 regs) */
literal|0x08220000
block|,
comment|/* block src */
literal|0x0108e010
block|,
comment|/* src.CTRL (1 regs) */
literal|0x0108e076
block|,
comment|/* src.INT_STS (1 regs) */
literal|0x0108e079
block|,
comment|/* src.INT_MASK (1 regs) */
literal|0x0b08e100
block|,
comment|/* src.KeySearch_0 .. src.KeySearch_vlan (11 regs) */
literal|0x0708e120
block|,
comment|/* src.IF_Stat_PF_Config .. src.IF_Stat_No_Read_Counter (7 regs) */
literal|0x0108e180
block|,
comment|/* src.PXP_CTRL (1 regs) */
literal|0x0508e1c0
block|,
comment|/* src.dbg_select .. src.dbg_force_frame (5 regs) */
literal|0x0208e1d2
block|,
comment|/* src.eco_reserved .. src.soft_rst (2 regs) */
literal|0x25230000
block|,
comment|/* block prs */
literal|0x0107c000
block|,
comment|/* prs.soft_rst (1 regs) */
literal|0x0307c002
block|,
comment|/* prs.mac_vlan_cache_init_done .. prs.cam_scrub_miss_en (3 regs) */
literal|0x0207c010
block|,
comment|/* prs.INT_STS_0 .. prs.INT_MASK_0 (2 regs) */
literal|0x0107c050
block|,
comment|/* prs.task_inc_value (1 regs) */
literal|0x0107c059
block|,
comment|/* prs.search_resp_initiator_type (1 regs) */
literal|0x0607c05e
block|,
comment|/* prs.task_id_segment .. prs.roce_con_type (6 regs) */
literal|0x0107c065
block|,
comment|/* prs.roce_opcode_req_res (1 regs) */
literal|0x0107c067
block|,
comment|/* prs.cfc_load_mini_cache_en (1 regs) */
literal|0x0107c080
block|,
comment|/* prs.eco_reserved (1 regs) */
literal|0x0107c104
block|,
comment|/* prs.search_tcp_first_frag (1 regs) */
literal|0x0107c10a
block|,
comment|/* prs.roce_spcl_qp_val (1 regs) */
literal|0x0907c114
block|,
comment|/* prs.tenant_id_default_val_enable .. prs.tenant_id_default_val_ttag (9 regs) */
literal|0x0407c11e
block|,
comment|/* prs.tenant_id_mask_eth_nge .. prs.tenant_id_default_val_ip_nge (4 regs) */
literal|0x0407c140
block|,
comment|/* prs.ports_arb_scheme .. prs.max_packet_size (4 regs) */
literal|0x0b07c1c1
block|,
comment|/* prs.llc_type_threshold .. prs.icmpv4_protocol (11 regs) */
literal|0x0107c1cd
block|,
comment|/* prs.gre_protocol (1 regs) */
literal|0x0e07c1d1
block|,
comment|/* prs.fcoe_type .. prs.tag_len_5 (14 regs) */
literal|0x0407c1ef
block|,
comment|/* prs.dst_mac_global_0 .. prs.dst_mac_global_mask_1 (4 regs) */
literal|0x0107c21a
block|,
comment|/* prs.nge_eth_type (1 regs) */
literal|0x0107c21c
block|,
comment|/* prs.rroce_port (1 regs) */
literal|0x0507c240
block|,
comment|/* prs.l2_irreg_cases .. prs.light_l2 (5 regs) */
literal|0x0307c24d
block|,
comment|/* prs.l2_regular_pkt .. prs.def_l2_con_type (3 regs) */
literal|0x0607c254
block|,
comment|/* prs.light_l2_ethertype_0 .. prs.light_l2_ethertype_5 (6 regs) */
literal|0x0307c25c
block|,
comment|/* prs.dst_mac_select .. prs.vlan_tag_select (3 regs) */
literal|0x0407c270
block|,
comment|/* prs.mac_vlan_flex_upper .. prs.mac_vlan_flex_bitmask_1 (4 regs) */
literal|0x0107c275
block|,
comment|/* prs.sack_blk_override (1 regs) */
literal|0x0807c277
block|,
comment|/* prs.rdma_syn_seed_0 .. prs.rdma_syn_seed_7 (8 regs) */
literal|0x0207c2c0
block|,
comment|/* prs.num_of_cfc_flush_messages .. prs.num_of_transparent_flush_messages (2 regs) */
literal|0x0887c2cc
block|,
comment|/* prs.fifo_empty_flags .. prs.fifo_full_flags (8 regs, WB) */
literal|0x0107c2d7
block|,
comment|/* prs.stop_parsing_status (1 regs) */
literal|0x0287c2d8
block|,
comment|/* prs.mini_cache_entry (2 regs, WB) */
literal|0x0407c2da
block|,
comment|/* prs.mini_cache_failed_response .. prs.dbg_shift (4 regs) */
literal|0x0207c2e8
block|,
comment|/* prs.dbg_force_valid .. prs.dbg_force_frame (2 regs) */
literal|0x0207c3c1
block|,
comment|/* prs.ccfc_search_initial_credit .. prs.tcfc_search_initial_credit (2 regs) */
literal|0x0907c3c4
block|,
comment|/* prs.ccfc_search_current_credit .. prs.sop_req_ct (9 regs) */
literal|0x0f07c460
block|,
comment|/* prs.gft_hash_key_0 .. prs.gft_tunnel_vlan_select (15 regs) */
literal|0x0407c471
block|,
comment|/* prs.gft_connection_type .. prs.gft_cam_scrub_miss_en (4 regs) */
literal|0x0a240000
block|,
comment|/* block tsdm */
literal|0x053ec001
block|,
comment|/* tsdm.enable_in1 .. tsdm.disable_engine (5 regs) */
literal|0x023ec010
block|,
comment|/* tsdm.INT_STS .. tsdm.INT_MASK (2 regs) */
literal|0x023ec100
block|,
comment|/* tsdm.timer_tick .. tsdm.timers_tick_enable (2 regs) */
literal|0x093ec103
block|,
comment|/* tsdm.grc_privilege_level .. tsdm.eco_reserved (9 regs) */
literal|0x053ec140
block|,
comment|/* tsdm.init_credit_pxp .. tsdm.init_credit_cm (5 regs) */
literal|0x0c3ec180
block|,
comment|/* tsdm.num_of_dma_cmd .. tsdm.num_of_dpm_req (12 regs) */
literal|0x033ec1c0
block|,
comment|/* tsdm.brb_almost_full .. tsdm.dorq_almost_full (3 regs) */
literal|0x203ec300
block|,
comment|/* tsdm.queue_full .. tsdm.prm_fifo_full (32 regs) */
literal|0x1a3ec340
block|,
comment|/* tsdm.int_cmpl_pend_empty .. tsdm.prm_fifo_empty (26 regs) */
literal|0x053ec38a
block|,
comment|/* tsdm.dbg_select .. tsdm.dbg_force_frame (5 regs) */
literal|0x0a250000
block|,
comment|/* block msdm */
literal|0x053f0001
block|,
comment|/* msdm.enable_in1 .. msdm.disable_engine (5 regs) */
literal|0x023f0010
block|,
comment|/* msdm.INT_STS .. msdm.INT_MASK (2 regs) */
literal|0x023f0100
block|,
comment|/* msdm.timer_tick .. msdm.timers_tick_enable (2 regs) */
literal|0x093f0103
block|,
comment|/* msdm.grc_privilege_level .. msdm.eco_reserved (9 regs) */
literal|0x053f0140
block|,
comment|/* msdm.init_credit_pxp .. msdm.init_credit_cm (5 regs) */
literal|0x0c3f0180
block|,
comment|/* msdm.num_of_dma_cmd .. msdm.num_of_dpm_req (12 regs) */
literal|0x033f01c0
block|,
comment|/* msdm.brb_almost_full .. msdm.dorq_almost_full (3 regs) */
literal|0x203f0300
block|,
comment|/* msdm.queue_full .. msdm.prm_fifo_full (32 regs) */
literal|0x1a3f0340
block|,
comment|/* msdm.int_cmpl_pend_empty .. msdm.prm_fifo_empty (26 regs) */
literal|0x053f038a
block|,
comment|/* msdm.dbg_select .. msdm.dbg_force_frame (5 regs) */
literal|0x0a260000
block|,
comment|/* block usdm */
literal|0x053f4001
block|,
comment|/* usdm.enable_in1 .. usdm.disable_engine (5 regs) */
literal|0x023f4010
block|,
comment|/* usdm.INT_STS .. usdm.INT_MASK (2 regs) */
literal|0x023f4100
block|,
comment|/* usdm.timer_tick .. usdm.timers_tick_enable (2 regs) */
literal|0x093f4103
block|,
comment|/* usdm.grc_privilege_level .. usdm.eco_reserved (9 regs) */
literal|0x053f4140
block|,
comment|/* usdm.init_credit_pxp .. usdm.init_credit_cm (5 regs) */
literal|0x0c3f4180
block|,
comment|/* usdm.num_of_dma_cmd .. usdm.num_of_dpm_req (12 regs) */
literal|0x033f41c0
block|,
comment|/* usdm.brb_almost_full .. usdm.dorq_almost_full (3 regs) */
literal|0x203f4300
block|,
comment|/* usdm.queue_full .. usdm.prm_fifo_full (32 regs) */
literal|0x1a3f4340
block|,
comment|/* usdm.int_cmpl_pend_empty .. usdm.prm_fifo_empty (26 regs) */
literal|0x053f438a
block|,
comment|/* usdm.dbg_select .. usdm.dbg_force_frame (5 regs) */
literal|0x0b270000
block|,
comment|/* block xsdm */
literal|0x053e0001
block|,
comment|/* xsdm.enable_in1 .. xsdm.disable_engine (5 regs) */
literal|0x023e0010
block|,
comment|/* xsdm.INT_STS .. xsdm.INT_MASK (2 regs) */
literal|0x023e0100
block|,
comment|/* xsdm.timer_tick .. xsdm.timers_tick_enable (2 regs) */
literal|0x093e0103
block|,
comment|/* xsdm.grc_privilege_level .. xsdm.eco_reserved (9 regs) */
literal|0x053e0140
block|,
comment|/* xsdm.init_credit_pxp .. xsdm.init_credit_cm (5 regs) */
literal|0x013e0148
block|,
comment|/* xsdm.init_credit_cm_rmt (1 regs) */
literal|0x0c3e0180
block|,
comment|/* xsdm.num_of_dma_cmd .. xsdm.num_of_dpm_req (12 regs) */
literal|0x033e01c0
block|,
comment|/* xsdm.brb_almost_full .. xsdm.dorq_almost_full (3 regs) */
literal|0x203e0300
block|,
comment|/* xsdm.queue_full .. xsdm.prm_fifo_full (32 regs) */
literal|0x1a3e0340
block|,
comment|/* xsdm.int_cmpl_pend_empty .. xsdm.prm_fifo_empty (26 regs) */
literal|0x053e038a
block|,
comment|/* xsdm.dbg_select .. xsdm.dbg_force_frame (5 regs) */
literal|0x0a280000
block|,
comment|/* block ysdm */
literal|0x053e4001
block|,
comment|/* ysdm.enable_in1 .. ysdm.disable_engine (5 regs) */
literal|0x023e4010
block|,
comment|/* ysdm.INT_STS .. ysdm.INT_MASK (2 regs) */
literal|0x023e4100
block|,
comment|/* ysdm.timer_tick .. ysdm.timers_tick_enable (2 regs) */
literal|0x093e4103
block|,
comment|/* ysdm.grc_privilege_level .. ysdm.eco_reserved (9 regs) */
literal|0x053e4140
block|,
comment|/* ysdm.init_credit_pxp .. ysdm.init_credit_cm (5 regs) */
literal|0x0c3e4180
block|,
comment|/* ysdm.num_of_dma_cmd .. ysdm.num_of_dpm_req (12 regs) */
literal|0x033e41c0
block|,
comment|/* ysdm.brb_almost_full .. ysdm.dorq_almost_full (3 regs) */
literal|0x203e4300
block|,
comment|/* ysdm.queue_full .. ysdm.prm_fifo_full (32 regs) */
literal|0x1a3e4340
block|,
comment|/* ysdm.int_cmpl_pend_empty .. ysdm.prm_fifo_empty (26 regs) */
literal|0x053e438a
block|,
comment|/* ysdm.dbg_select .. ysdm.dbg_force_frame (5 regs) */
literal|0x0a290000
block|,
comment|/* block psdm */
literal|0x053e8001
block|,
comment|/* psdm.enable_in1 .. psdm.disable_engine (5 regs) */
literal|0x023e8010
block|,
comment|/* psdm.INT_STS .. psdm.INT_MASK (2 regs) */
literal|0x023e8100
block|,
comment|/* psdm.timer_tick .. psdm.timers_tick_enable (2 regs) */
literal|0x093e8103
block|,
comment|/* psdm.grc_privilege_level .. psdm.eco_reserved (9 regs) */
literal|0x053e8140
block|,
comment|/* psdm.init_credit_pxp .. psdm.init_credit_cm (5 regs) */
literal|0x0c3e8180
block|,
comment|/* psdm.num_of_dma_cmd .. psdm.num_of_dpm_req (12 regs) */
literal|0x033e81c0
block|,
comment|/* psdm.brb_almost_full .. psdm.dorq_almost_full (3 regs) */
literal|0x203e8300
block|,
comment|/* psdm.queue_full .. psdm.prm_fifo_full (32 regs) */
literal|0x1a3e8340
block|,
comment|/* psdm.int_cmpl_pend_empty .. psdm.prm_fifo_empty (26 regs) */
literal|0x053e838a
block|,
comment|/* psdm.dbg_select .. psdm.dbg_force_frame (5 regs) */
literal|0x232a0000
block|,
comment|/* block tsem */
literal|0x025c0010
block|,
comment|/* tsem.INT_STS_0 .. tsem.INT_MASK_0 (2 regs) */
literal|0x025c0014
block|,
comment|/* tsem.INT_STS_1 .. tsem.INT_MASK_1 (2 regs) */
literal|0x035c0110
block|,
comment|/* tsem.pf_err_vector .. tsem.exception_int (3 regs) */
literal|0x025c0116
block|,
comment|/* tsem.allow_lp_sleep_thrd .. tsem.eco_reserved (2 regs) */
literal|0x025c01a0
block|,
comment|/* tsem.foc_credit (2 regs) */
literal|0x015c02c0
block|,
comment|/* tsem.num_of_threads (1 regs) */
literal|0x025c0400
block|,
comment|/* tsem.dbg_alm_full .. tsem.passive_alm_full (2 regs) */
literal|0x015c0403
block|,
comment|/* tsem.sync_ram_wr_alm_full (1 regs) */
literal|0x015c0441
block|,
comment|/* tsem.ext_pas_empty (1 regs) */
literal|0x015c0448
block|,
comment|/* tsem.fic_empty (1 regs) */
literal|0x025c0454
block|,
comment|/* tsem.slow_ext_store_empty .. tsem.slow_ext_load_empty (2 regs) */
literal|0x025c0457
block|,
comment|/* tsem.slow_ram_wr_empty .. tsem.sync_dbg_empty (2 regs) */
literal|0x025c0480
block|,
comment|/* tsem.ext_pas_full .. tsem.ext_store_if_full (2 regs) */
literal|0x015c0488
block|,
comment|/* tsem.fic_full (1 regs) */
literal|0x015c0491
block|,
comment|/* tsem.ram_if_full (1 regs) */
literal|0x065c0497
block|,
comment|/* tsem.slow_ext_store_full .. tsem.sync_dbg_full (6 regs) */
literal|0x055c054a
block|,
comment|/* tsem.dbg_select .. tsem.dbg_force_frame (5 regs) */
literal|0x025d0010
block|,
comment|/* tsem.fast_memory.INT_STS .. tsem.fast_memory.INT_MASK (2 regs) */
literal|0x025d0120
block|,
comment|/* tsem.fast_memory.gpre0 .. tsem.fast_memory.stall_mask (2 regs) */
literal|0x045d0128
block|,
comment|/* tsem.fast_memory.storm_stack_size .. tsem.fast_memory.pram_prty_addr_high (4 regs) */
literal|0x025d012e
block|,
comment|/* tsem.fast_memory.port_id_width .. tsem.fast_memory.port_id_offset (2 regs) */
literal|0x015d0131
block|,
comment|/* tsem.fast_memory.state_machine (1 regs) */
literal|0x035d0133
block|,
comment|/* tsem.fast_memory.iram_ecc_error_inj .. tsem.fast_memory.storm_pc (3 regs) */
literal|0x0e5d018a
block|,
comment|/* tsem.fast_memory.rt_clk_enable .. tsem.fast_memory.cam_init_in_process (14 regs) */
literal|0x0d5d01d0
block|,
comment|/* tsem.fast_memory.debug_active .. tsem.fast_memory.dbg_store_addr_value (13 regs) */
literal|0x045d0210
block|,
comment|/* tsem.fast_memory.sync_dra_rd_alm_full .. tsem.fast_memory.dbg_alm_full (4 regs) */
literal|0x035d0250
block|,
comment|/* tsem.fast_memory.full .. tsem.fast_memory.alm_full (3 regs) */
literal|0x015d0290
block|,
comment|/* tsem.fast_memory.active_filter_enable (1 regs) */
literal|0x015d0292
block|,
comment|/* tsem.fast_memory.stall_cycles_mask (1 regs) */
literal|0x015d02d3
block|,
comment|/* tsem.fast_memory.vfc_status (1 regs) */
literal|0x045d0310
block|,
comment|/* tsem.fast_memory.cam_bist_en .. tsem.fast_memory.cam_bist_status (4 regs) */
literal|0x0e5d2800
block|,
comment|/* tsem.fast_memory.vfc_config.mask_lsb_0_low .. tsem.fast_memory.vfc_config.indications2 (14 regs) */
literal|0x135d280f
block|,
comment|/* tsem.fast_memory.vfc_config.memories_rst .. tsem.fast_memory.vfc_config.cpu_mbist_memctrl_1_cntrl_cmd (19 regs) */
literal|0x125d2824
block|,
comment|/* tsem.fast_memory.vfc_config.debug_data .. tsem.fast_memory.vfc_config.mask_lsb_7_high (18 regs) */
literal|0x0c5d283e
block|,
comment|/* tsem.fast_memory.vfc_config.offset_alu_vector_0 .. tsem.fast_memory.vfc_config.cam_bist_skip_error_cnt (12 regs) */
literal|0x1f2b0000
block|,
comment|/* block msem */
literal|0x02600010
block|,
comment|/* msem.INT_STS_0 .. msem.INT_MASK_0 (2 regs) */
literal|0x02600014
block|,
comment|/* msem.INT_STS_1 .. msem.INT_MASK_1 (2 regs) */
literal|0x03600110
block|,
comment|/* msem.pf_err_vector .. msem.exception_int (3 regs) */
literal|0x02600116
block|,
comment|/* msem.allow_lp_sleep_thrd .. msem.eco_reserved (2 regs) */
literal|0x066001a0
block|,
comment|/* msem.foc_credit (6 regs) */
literal|0x016002c0
block|,
comment|/* msem.num_of_threads (1 regs) */
literal|0x02600400
block|,
comment|/* msem.dbg_alm_full .. msem.passive_alm_full (2 regs) */
literal|0x01600403
block|,
comment|/* msem.sync_ram_wr_alm_full (1 regs) */
literal|0x01600441
block|,
comment|/* msem.ext_pas_empty (1 regs) */
literal|0x01600448
block|,
comment|/* msem.fic_empty (1 regs) */
literal|0x02600454
block|,
comment|/* msem.slow_ext_store_empty .. msem.slow_ext_load_empty (2 regs) */
literal|0x02600457
block|,
comment|/* msem.slow_ram_wr_empty .. msem.sync_dbg_empty (2 regs) */
literal|0x02600480
block|,
comment|/* msem.ext_pas_full .. msem.ext_store_if_full (2 regs) */
literal|0x01600488
block|,
comment|/* msem.fic_full (1 regs) */
literal|0x01600491
block|,
comment|/* msem.ram_if_full (1 regs) */
literal|0x06600497
block|,
comment|/* msem.slow_ext_store_full .. msem.sync_dbg_full (6 regs) */
literal|0x0560054a
block|,
comment|/* msem.dbg_select .. msem.dbg_force_frame (5 regs) */
literal|0x02610010
block|,
comment|/* msem.fast_memory.INT_STS .. msem.fast_memory.INT_MASK (2 regs) */
literal|0x02610120
block|,
comment|/* msem.fast_memory.gpre0 .. msem.fast_memory.stall_mask (2 regs) */
literal|0x04610128
block|,
comment|/* msem.fast_memory.storm_stack_size .. msem.fast_memory.pram_prty_addr_high (4 regs) */
literal|0x0261012e
block|,
comment|/* msem.fast_memory.port_id_width .. msem.fast_memory.port_id_offset (2 regs) */
literal|0x01610131
block|,
comment|/* msem.fast_memory.state_machine (1 regs) */
literal|0x03610133
block|,
comment|/* msem.fast_memory.iram_ecc_error_inj .. msem.fast_memory.storm_pc (3 regs) */
literal|0x0e61018a
block|,
comment|/* msem.fast_memory.rt_clk_enable .. msem.fast_memory.cam_init_in_process (14 regs) */
literal|0x0d6101d0
block|,
comment|/* msem.fast_memory.debug_active .. msem.fast_memory.dbg_store_addr_value (13 regs) */
literal|0x04610210
block|,
comment|/* msem.fast_memory.sync_dra_rd_alm_full .. msem.fast_memory.dbg_alm_full (4 regs) */
literal|0x03610250
block|,
comment|/* msem.fast_memory.full .. msem.fast_memory.alm_full (3 regs) */
literal|0x01610290
block|,
comment|/* msem.fast_memory.active_filter_enable (1 regs) */
literal|0x01610292
block|,
comment|/* msem.fast_memory.stall_cycles_mask (1 regs) */
literal|0x016102d3
block|,
comment|/* msem.fast_memory.vfc_status (1 regs) */
literal|0x04610310
block|,
comment|/* msem.fast_memory.cam_bist_en .. msem.fast_memory.cam_bist_status (4 regs) */
literal|0x1f2c0000
block|,
comment|/* block usem */
literal|0x02640010
block|,
comment|/* usem.INT_STS_0 .. usem.INT_MASK_0 (2 regs) */
literal|0x02640014
block|,
comment|/* usem.INT_STS_1 .. usem.INT_MASK_1 (2 regs) */
literal|0x03640110
block|,
comment|/* usem.pf_err_vector .. usem.exception_int (3 regs) */
literal|0x02640116
block|,
comment|/* usem.allow_lp_sleep_thrd .. usem.eco_reserved (2 regs) */
literal|0x056401a0
block|,
comment|/* usem.foc_credit (5 regs) */
literal|0x016402c0
block|,
comment|/* usem.num_of_threads (1 regs) */
literal|0x02640400
block|,
comment|/* usem.dbg_alm_full .. usem.passive_alm_full (2 regs) */
literal|0x01640403
block|,
comment|/* usem.sync_ram_wr_alm_full (1 regs) */
literal|0x01640441
block|,
comment|/* usem.ext_pas_empty (1 regs) */
literal|0x01640448
block|,
comment|/* usem.fic_empty (1 regs) */
literal|0x02640454
block|,
comment|/* usem.slow_ext_store_empty .. usem.slow_ext_load_empty (2 regs) */
literal|0x02640457
block|,
comment|/* usem.slow_ram_wr_empty .. usem.sync_dbg_empty (2 regs) */
literal|0x02640480
block|,
comment|/* usem.ext_pas_full .. usem.ext_store_if_full (2 regs) */
literal|0x01640488
block|,
comment|/* usem.fic_full (1 regs) */
literal|0x01640491
block|,
comment|/* usem.ram_if_full (1 regs) */
literal|0x06640497
block|,
comment|/* usem.slow_ext_store_full .. usem.sync_dbg_full (6 regs) */
literal|0x0564054a
block|,
comment|/* usem.dbg_select .. usem.dbg_force_frame (5 regs) */
literal|0x02650010
block|,
comment|/* usem.fast_memory.INT_STS .. usem.fast_memory.INT_MASK (2 regs) */
literal|0x02650120
block|,
comment|/* usem.fast_memory.gpre0 .. usem.fast_memory.stall_mask (2 regs) */
literal|0x04650128
block|,
comment|/* usem.fast_memory.storm_stack_size .. usem.fast_memory.pram_prty_addr_high (4 regs) */
literal|0x0265012e
block|,
comment|/* usem.fast_memory.port_id_width .. usem.fast_memory.port_id_offset (2 regs) */
literal|0x01650131
block|,
comment|/* usem.fast_memory.state_machine (1 regs) */
literal|0x03650133
block|,
comment|/* usem.fast_memory.iram_ecc_error_inj .. usem.fast_memory.storm_pc (3 regs) */
literal|0x0e65018a
block|,
comment|/* usem.fast_memory.rt_clk_enable .. usem.fast_memory.cam_init_in_process (14 regs) */
literal|0x0d6501d0
block|,
comment|/* usem.fast_memory.debug_active .. usem.fast_memory.dbg_store_addr_value (13 regs) */
literal|0x04650210
block|,
comment|/* usem.fast_memory.sync_dra_rd_alm_full .. usem.fast_memory.dbg_alm_full (4 regs) */
literal|0x03650250
block|,
comment|/* usem.fast_memory.full .. usem.fast_memory.alm_full (3 regs) */
literal|0x01650290
block|,
comment|/* usem.fast_memory.active_filter_enable (1 regs) */
literal|0x01650292
block|,
comment|/* usem.fast_memory.stall_cycles_mask (1 regs) */
literal|0x016502d3
block|,
comment|/* usem.fast_memory.vfc_status (1 regs) */
literal|0x04650310
block|,
comment|/* usem.fast_memory.cam_bist_en .. usem.fast_memory.cam_bist_status (4 regs) */
literal|0x1d2d0000
block|,
comment|/* block xsem */
literal|0x02500010
block|,
comment|/* xsem.INT_STS_0 .. xsem.INT_MASK_0 (2 regs) */
literal|0x02500014
block|,
comment|/* xsem.INT_STS_1 .. xsem.INT_MASK_1 (2 regs) */
literal|0x03500110
block|,
comment|/* xsem.pf_err_vector .. xsem.exception_int (3 regs) */
literal|0x02500116
block|,
comment|/* xsem.allow_lp_sleep_thrd .. xsem.eco_reserved (2 regs) */
literal|0x025001a0
block|,
comment|/* xsem.foc_credit (2 regs) */
literal|0x015002c0
block|,
comment|/* xsem.num_of_threads (1 regs) */
literal|0x02500400
block|,
comment|/* xsem.dbg_alm_full .. xsem.passive_alm_full (2 regs) */
literal|0x01500403
block|,
comment|/* xsem.sync_ram_wr_alm_full (1 regs) */
literal|0x01500441
block|,
comment|/* xsem.ext_pas_empty (1 regs) */
literal|0x02500454
block|,
comment|/* xsem.slow_ext_store_empty .. xsem.slow_ext_load_empty (2 regs) */
literal|0x02500457
block|,
comment|/* xsem.slow_ram_wr_empty .. xsem.sync_dbg_empty (2 regs) */
literal|0x02500480
block|,
comment|/* xsem.ext_pas_full .. xsem.ext_store_if_full (2 regs) */
literal|0x01500491
block|,
comment|/* xsem.ram_if_full (1 regs) */
literal|0x06500497
block|,
comment|/* xsem.slow_ext_store_full .. xsem.sync_dbg_full (6 regs) */
literal|0x0550054a
block|,
comment|/* xsem.dbg_select .. xsem.dbg_force_frame (5 regs) */
literal|0x02510010
block|,
comment|/* xsem.fast_memory.INT_STS .. xsem.fast_memory.INT_MASK (2 regs) */
literal|0x02510120
block|,
comment|/* xsem.fast_memory.gpre0 .. xsem.fast_memory.stall_mask (2 regs) */
literal|0x04510128
block|,
comment|/* xsem.fast_memory.storm_stack_size .. xsem.fast_memory.pram_prty_addr_high (4 regs) */
literal|0x0251012e
block|,
comment|/* xsem.fast_memory.port_id_width .. xsem.fast_memory.port_id_offset (2 regs) */
literal|0x01510131
block|,
comment|/* xsem.fast_memory.state_machine (1 regs) */
literal|0x03510133
block|,
comment|/* xsem.fast_memory.iram_ecc_error_inj .. xsem.fast_memory.storm_pc (3 regs) */
literal|0x0e51018a
block|,
comment|/* xsem.fast_memory.rt_clk_enable .. xsem.fast_memory.cam_init_in_process (14 regs) */
literal|0x0d5101d0
block|,
comment|/* xsem.fast_memory.debug_active .. xsem.fast_memory.dbg_store_addr_value (13 regs) */
literal|0x04510210
block|,
comment|/* xsem.fast_memory.sync_dra_rd_alm_full .. xsem.fast_memory.dbg_alm_full (4 regs) */
literal|0x03510250
block|,
comment|/* xsem.fast_memory.full .. xsem.fast_memory.alm_full (3 regs) */
literal|0x01510290
block|,
comment|/* xsem.fast_memory.active_filter_enable (1 regs) */
literal|0x01510292
block|,
comment|/* xsem.fast_memory.stall_cycles_mask (1 regs) */
literal|0x015102d3
block|,
comment|/* xsem.fast_memory.vfc_status (1 regs) */
literal|0x04510310
block|,
comment|/* xsem.fast_memory.cam_bist_en .. xsem.fast_memory.cam_bist_status (4 regs) */
literal|0x1d2e0000
block|,
comment|/* block ysem */
literal|0x02540010
block|,
comment|/* ysem.INT_STS_0 .. ysem.INT_MASK_0 (2 regs) */
literal|0x02540014
block|,
comment|/* ysem.INT_STS_1 .. ysem.INT_MASK_1 (2 regs) */
literal|0x03540110
block|,
comment|/* ysem.pf_err_vector .. ysem.exception_int (3 regs) */
literal|0x02540116
block|,
comment|/* ysem.allow_lp_sleep_thrd .. ysem.eco_reserved (2 regs) */
literal|0x065401a0
block|,
comment|/* ysem.foc_credit (6 regs) */
literal|0x015402c0
block|,
comment|/* ysem.num_of_threads (1 regs) */
literal|0x02540400
block|,
comment|/* ysem.dbg_alm_full .. ysem.passive_alm_full (2 regs) */
literal|0x01540403
block|,
comment|/* ysem.sync_ram_wr_alm_full (1 regs) */
literal|0x01540441
block|,
comment|/* ysem.ext_pas_empty (1 regs) */
literal|0x02540454
block|,
comment|/* ysem.slow_ext_store_empty .. ysem.slow_ext_load_empty (2 regs) */
literal|0x02540457
block|,
comment|/* ysem.slow_ram_wr_empty .. ysem.sync_dbg_empty (2 regs) */
literal|0x02540480
block|,
comment|/* ysem.ext_pas_full .. ysem.ext_store_if_full (2 regs) */
literal|0x01540491
block|,
comment|/* ysem.ram_if_full (1 regs) */
literal|0x06540497
block|,
comment|/* ysem.slow_ext_store_full .. ysem.sync_dbg_full (6 regs) */
literal|0x0554054a
block|,
comment|/* ysem.dbg_select .. ysem.dbg_force_frame (5 regs) */
literal|0x02550010
block|,
comment|/* ysem.fast_memory.INT_STS .. ysem.fast_memory.INT_MASK (2 regs) */
literal|0x02550120
block|,
comment|/* ysem.fast_memory.gpre0 .. ysem.fast_memory.stall_mask (2 regs) */
literal|0x04550128
block|,
comment|/* ysem.fast_memory.storm_stack_size .. ysem.fast_memory.pram_prty_addr_high (4 regs) */
literal|0x0255012e
block|,
comment|/* ysem.fast_memory.port_id_width .. ysem.fast_memory.port_id_offset (2 regs) */
literal|0x01550131
block|,
comment|/* ysem.fast_memory.state_machine (1 regs) */
literal|0x03550133
block|,
comment|/* ysem.fast_memory.iram_ecc_error_inj .. ysem.fast_memory.storm_pc (3 regs) */
literal|0x0e55018a
block|,
comment|/* ysem.fast_memory.rt_clk_enable .. ysem.fast_memory.cam_init_in_process (14 regs) */
literal|0x0d5501d0
block|,
comment|/* ysem.fast_memory.debug_active .. ysem.fast_memory.dbg_store_addr_value (13 regs) */
literal|0x04550210
block|,
comment|/* ysem.fast_memory.sync_dra_rd_alm_full .. ysem.fast_memory.dbg_alm_full (4 regs) */
literal|0x03550250
block|,
comment|/* ysem.fast_memory.full .. ysem.fast_memory.alm_full (3 regs) */
literal|0x01550290
block|,
comment|/* ysem.fast_memory.active_filter_enable (1 regs) */
literal|0x01550292
block|,
comment|/* ysem.fast_memory.stall_cycles_mask (1 regs) */
literal|0x015502d3
block|,
comment|/* ysem.fast_memory.vfc_status (1 regs) */
literal|0x04550310
block|,
comment|/* ysem.fast_memory.cam_bist_en .. ysem.fast_memory.cam_bist_status (4 regs) */
literal|0x1f2f0000
block|,
comment|/* block psem */
literal|0x02580010
block|,
comment|/* psem.INT_STS_0 .. psem.INT_MASK_0 (2 regs) */
literal|0x02580014
block|,
comment|/* psem.INT_STS_1 .. psem.INT_MASK_1 (2 regs) */
literal|0x03580110
block|,
comment|/* psem.pf_err_vector .. psem.exception_int (3 regs) */
literal|0x02580116
block|,
comment|/* psem.allow_lp_sleep_thrd .. psem.eco_reserved (2 regs) */
literal|0x025801a0
block|,
comment|/* psem.foc_credit (2 regs) */
literal|0x015802c0
block|,
comment|/* psem.num_of_threads (1 regs) */
literal|0x02580400
block|,
comment|/* psem.dbg_alm_full .. psem.passive_alm_full (2 regs) */
literal|0x01580403
block|,
comment|/* psem.sync_ram_wr_alm_full (1 regs) */
literal|0x01580441
block|,
comment|/* psem.ext_pas_empty (1 regs) */
literal|0x01580448
block|,
comment|/* psem.fic_empty (1 regs) */
literal|0x02580454
block|,
comment|/* psem.slow_ext_store_empty .. psem.slow_ext_load_empty (2 regs) */
literal|0x02580457
block|,
comment|/* psem.slow_ram_wr_empty .. psem.sync_dbg_empty (2 regs) */
literal|0x02580480
block|,
comment|/* psem.ext_pas_full .. psem.ext_store_if_full (2 regs) */
literal|0x01580488
block|,
comment|/* psem.fic_full (1 regs) */
literal|0x01580491
block|,
comment|/* psem.ram_if_full (1 regs) */
literal|0x06580497
block|,
comment|/* psem.slow_ext_store_full .. psem.sync_dbg_full (6 regs) */
literal|0x0558054a
block|,
comment|/* psem.dbg_select .. psem.dbg_force_frame (5 regs) */
literal|0x02590010
block|,
comment|/* psem.fast_memory.INT_STS .. psem.fast_memory.INT_MASK (2 regs) */
literal|0x02590120
block|,
comment|/* psem.fast_memory.gpre0 .. psem.fast_memory.stall_mask (2 regs) */
literal|0x04590128
block|,
comment|/* psem.fast_memory.storm_stack_size .. psem.fast_memory.pram_prty_addr_high (4 regs) */
literal|0x0259012e
block|,
comment|/* psem.fast_memory.port_id_width .. psem.fast_memory.port_id_offset (2 regs) */
literal|0x01590131
block|,
comment|/* psem.fast_memory.state_machine (1 regs) */
literal|0x03590133
block|,
comment|/* psem.fast_memory.iram_ecc_error_inj .. psem.fast_memory.storm_pc (3 regs) */
literal|0x0e59018a
block|,
comment|/* psem.fast_memory.rt_clk_enable .. psem.fast_memory.cam_init_in_process (14 regs) */
literal|0x0d5901d0
block|,
comment|/* psem.fast_memory.debug_active .. psem.fast_memory.dbg_store_addr_value (13 regs) */
literal|0x04590210
block|,
comment|/* psem.fast_memory.sync_dra_rd_alm_full .. psem.fast_memory.dbg_alm_full (4 regs) */
literal|0x03590250
block|,
comment|/* psem.fast_memory.full .. psem.fast_memory.alm_full (3 regs) */
literal|0x01590290
block|,
comment|/* psem.fast_memory.active_filter_enable (1 regs) */
literal|0x01590292
block|,
comment|/* psem.fast_memory.stall_cycles_mask (1 regs) */
literal|0x015902d3
block|,
comment|/* psem.fast_memory.vfc_status (1 regs) */
literal|0x04590310
block|,
comment|/* psem.fast_memory.cam_bist_en .. psem.fast_memory.cam_bist_status (4 regs) */
literal|0x04300000
block|,
comment|/* block rss */
literal|0x0308e201
block|,
comment|/* rss.rss_init_en .. rss.if_enable (3 regs) */
literal|0x0208e260
block|,
comment|/* rss.INT_STS .. rss.INT_MASK (2 regs) */
literal|0x0208e300
block|,
comment|/* rss.key_rss_ext5 .. rss.tmld_credit (2 regs) */
literal|0x0608e312
block|,
comment|/* rss.eco_reserved .. rss.dbg_force_frame (6 regs) */
literal|0x06310000
block|,
comment|/* block tmld */
literal|0x01134000
block|,
comment|/* tmld.scbd_strict_prio (1 regs) */
literal|0x2c134003
block|,
comment|/* tmld.foci_foc_credits .. tmld.cm_hdr_127_96 (44 regs) */
literal|0x05134030
block|,
comment|/* tmld.stat_fic_msg .. tmld.len_err_log_2 (5 regs) */
literal|0x01134036
block|,
comment|/* tmld.len_err_log_v (1 regs) */
literal|0x02134060
block|,
comment|/* tmld.INT_STS .. tmld.INT_MASK (2 regs) */
literal|0x05134580
block|,
comment|/* tmld.dbg_select .. tmld.dbg_force_frame (5 regs) */
literal|0x05320000
block|,
comment|/* block muld */
literal|0x38138000
block|,
comment|/* muld.scbd_strict_prio .. muld.cm_hdr_127_96 (56 regs) */
literal|0x05138039
block|,
comment|/* muld.stat_fic_msg .. muld.len_err_log_2 (5 regs) */
literal|0x0113803f
block|,
comment|/* muld.len_err_log_v (1 regs) */
literal|0x02138060
block|,
comment|/* muld.INT_STS .. muld.INT_MASK (2 regs) */
literal|0x05138580
block|,
comment|/* muld.dbg_select .. muld.dbg_force_frame (5 regs) */
literal|0x07340000
block|,
comment|/* block xyld */
literal|0x01130000
block|,
comment|/* xyld.scbd_strict_prio (1 regs) */
literal|0x2e130003
block|,
comment|/* xyld.foci_foc_credits .. xyld.cm_hdr_127_96 (46 regs) */
literal|0x04130032
block|,
comment|/* xyld.seg_msg_log .. xyld.seg_msg_log_len_arr_95_64 (4 regs) */
literal|0x06130037
block|,
comment|/* xyld.seg_msg_log_v .. xyld.len_err_log_2 (6 regs) */
literal|0x0113003e
block|,
comment|/* xyld.len_err_log_v (1 regs) */
literal|0x02130060
block|,
comment|/* xyld.INT_STS .. xyld.INT_MASK (2 regs) */
literal|0x05130580
block|,
comment|/* xyld.dbg_select .. xyld.dbg_force_frame (5 regs) */
literal|0x06370000
block|,
comment|/* block prm */
literal|0x0608c000
block|,
comment|/* prm.disable_prm .. prm.disable_outputs (6 regs) */
literal|0x0208c010
block|,
comment|/* prm.INT_STS .. prm.INT_MASK (2 regs) */
literal|0x0508c108
block|,
comment|/* prm.pad_data .. prm.init_credit_rdif_pth (5 regs) */
literal|0x0508c140
block|,
comment|/* prm.rpb_db_full_thr .. prm.pxp_resp_full_thr (5 regs) */
literal|0x0208c180
block|,
comment|/* prm.num_of_mstorm_cmd .. prm.num_of_ustorm_cmd (2 regs) */
literal|0x0508c1aa
block|,
comment|/* prm.dbg_select .. prm.dbg_force_frame (5 regs) */
literal|0x05380000
block|,
comment|/* block pbf_pb1 */
literal|0x02368010
block|,
comment|/* pbf_pb1.INT_STS .. pbf_pb1.INT_MASK (2 regs) */
literal|0x0d368100
block|,
comment|/* pbf_pb1.control .. pbf_pb1.crc_mask_3_3 (13 regs) */
literal|0x09368140
block|,
comment|/* pbf_pb1.db_empty .. pbf_pb1.tq_th_empty (9 regs) */
literal|0x06368180
block|,
comment|/* pbf_pb1.errored_crc .. pbf_pb1.eco_reserved (6 regs) */
literal|0x053681ca
block|,
comment|/* pbf_pb1.dbg_select .. pbf_pb1.dbg_force_frame (5 regs) */
literal|0x05390000
block|,
comment|/* block pbf_pb2 */
literal|0x02369010
block|,
comment|/* pbf_pb2.INT_STS .. pbf_pb2.INT_MASK (2 regs) */
literal|0x0d369100
block|,
comment|/* pbf_pb2.control .. pbf_pb2.crc_mask_3_3 (13 regs) */
literal|0x09369140
block|,
comment|/* pbf_pb2.db_empty .. pbf_pb2.tq_th_empty (9 regs) */
literal|0x06369180
block|,
comment|/* pbf_pb2.errored_crc .. pbf_pb2.eco_reserved (6 regs) */
literal|0x053691ca
block|,
comment|/* pbf_pb2.dbg_select .. pbf_pb2.dbg_force_frame (5 regs) */
literal|0x053a0000
block|,
comment|/* block rpb */
literal|0x0208f010
block|,
comment|/* rpb.INT_STS .. rpb.INT_MASK (2 regs) */
literal|0x0d08f100
block|,
comment|/* rpb.control .. rpb.crc_mask_3_3 (13 regs) */
literal|0x0908f140
block|,
comment|/* rpb.db_empty .. rpb.tq_th_empty (9 regs) */
literal|0x0608f180
block|,
comment|/* rpb.errored_crc .. rpb.eco_reserved (6 regs) */
literal|0x0508f1ca
block|,
comment|/* rpb.dbg_select .. rpb.dbg_force_frame (5 regs) */
literal|0x173b0000
block|,
comment|/* block btb */
literal|0x0336c001
block|,
comment|/* btb.hw_init_en .. btb.start_en (3 regs) */
literal|0x0236c030
block|,
comment|/* btb.INT_STS_0 .. btb.INT_MASK_0 (2 regs) */
literal|0x0236c036
block|,
comment|/* btb.INT_STS_1 .. btb.INT_MASK_1 (2 regs) */
literal|0x0236c03c
block|,
comment|/* btb.INT_STS_2 .. btb.INT_MASK_2 (2 regs) */
literal|0x0236c042
block|,
comment|/* btb.INT_STS_3 .. btb.INT_MASK_3 (2 regs) */
literal|0x0236c048
block|,
comment|/* btb.INT_STS_4 .. btb.INT_MASK_4 (2 regs) */
literal|0x0236c04e
block|,
comment|/* btb.INT_STS_5 .. btb.INT_MASK_5 (2 regs) */
literal|0x0236c054
block|,
comment|/* btb.INT_STS_6 .. btb.INT_MASK_6 (2 regs) */
literal|0x0236c061
block|,
comment|/* btb.INT_STS_8 .. btb.INT_MASK_8 (2 regs) */
literal|0x0236c067
block|,
comment|/* btb.INT_STS_9 .. btb.INT_MASK_9 (2 regs) */
literal|0x0236c06d
block|,
comment|/* btb.INT_STS_10 .. btb.INT_MASK_10 (2 regs) */
literal|0x0236c073
block|,
comment|/* btb.INT_STS_11 .. btb.INT_MASK_11 (2 regs) */
literal|0x0236c200
block|,
comment|/* btb.big_ram_address .. btb.header_size (2 regs) */
literal|0x0536c210
block|,
comment|/* btb.max_releases .. btb.rc_pkt_priority (5 regs) */
literal|0x1436c223
block|,
comment|/* btb.rc_sop_priority .. btb.dbg_force_frame (20 regs) */
literal|0x0636c242
block|,
comment|/* btb.inp_if_enable .. btb.wc_empty_0 (6 regs) */
literal|0x0136c257
block|,
comment|/* btb.wc_full_0 (1 regs) */
literal|0x0636c267
block|,
comment|/* btb.wc_bandwidth_if_full .. btb.rc_pkt_empty_3 (6 regs) */
literal|0x0436c278
block|,
comment|/* btb.rc_pkt_full_0 .. btb.rc_pkt_full_3 (4 regs) */
literal|0x0436c287
block|,
comment|/* btb.rc_pkt_status_0 .. btb.rc_pkt_status_3 (4 regs) */
literal|0x0936c296
block|,
comment|/* btb.rc_sop_empty .. btb.wc_sync_fifo_push_status_0 (9 regs) */
literal|0x0236c2ad
block|,
comment|/* btb.rls_sync_fifo_push_status .. btb.rc_pkt_state (2 regs) */
literal|0x0136c2b2
block|,
comment|/* btb.clocks_ratio (1 regs) */
literal|0x293c0000
block|,
comment|/* block pbf */
literal|0x01360000
block|,
comment|/* pbf.init (1 regs) */
literal|0x01360010
block|,
comment|/* pbf.if_enable_reg (1 regs) */
literal|0x05360018
block|,
comment|/* pbf.dbg_select .. pbf.dbg_force_frame (5 regs) */
literal|0x0336002a
block|,
comment|/* pbf.fc_dbg_select .. pbf.fc_dbg_shift (3 regs) */
literal|0x08b60030
block|,
comment|/* pbf.fc_dbg_out_data (8 regs, WB) */
literal|0x04360038
block|,
comment|/* pbf.fc_dbg_force_valid .. pbf.fc_dbg_out_frame (4 regs) */
literal|0x01360043
block|,
comment|/* pbf.memctrl_status (1 regs) */
literal|0x02360060
block|,
comment|/* pbf.INT_STS .. pbf.INT_MASK (2 regs) */
literal|0x06360100
block|,
comment|/* pbf.pxp_req_if_init_crd .. pbf.tm_if_init_crd (6 regs) */
literal|0x05360107
block|,
comment|/* pbf.tcm_if_init_crd .. pbf.ycm_if_init_crd (5 regs) */
literal|0x08360110
block|,
comment|/* pbf.pb1_db_almost_full_thrsh .. pbf.mrku_almost_full_thrsh (8 regs) */
literal|0x04360120
block|,
comment|/* pbf.tag_ethertype_0 .. pbf.tag_ethertype_3 (4 regs) */
literal|0x04360126
block|,
comment|/* pbf.tag_len_0 .. pbf.tag_len_3 (4 regs) */
literal|0x0836013e
block|,
comment|/* pbf.llc_type_threshold .. pbf.gre_protocol (8 regs) */
literal|0x01360148
block|,
comment|/* pbf.nge_eth_type (1 regs) */
literal|0x01360161
block|,
comment|/* pbf.regular_inband_tag_order (1 regs) */
literal|0x07360163
block|,
comment|/* pbf.dst_mac_global_0 .. pbf.udp_dst_port_cfg_2 (7 regs) */
literal|0x02360175
block|,
comment|/* pbf.l2_edpm_thrsh .. pbf.cpmu_thrsh (2 regs) */
literal|0x0e360180
block|,
comment|/* pbf.ip_id_mask_0 .. pbf.tcm_snd_nxt_reg_offset (14 regs) */
literal|0x02360190
block|,
comment|/* pbf.pci_vq_id .. pbf.drop_pkt_upon_err (2 regs) */
literal|0x07360196
block|,
comment|/* pbf.per_voq_stat_mask .. pbf.num_pkts_sent_with_drop_to_btb (7 regs) */
literal|0x0c3601a8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq0 .. pbf.num_blocks_allocated_cons_voq0 (12 regs) */
literal|0x0c3601b8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq1 .. pbf.num_blocks_allocated_cons_voq1 (12 regs) */
literal|0x0c3601c8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq2 .. pbf.num_blocks_allocated_cons_voq2 (12 regs) */
literal|0x0c3601d8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq3 .. pbf.num_blocks_allocated_cons_voq3 (12 regs) */
literal|0x0c3601e8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq4 .. pbf.num_blocks_allocated_cons_voq4 (12 regs) */
literal|0x0c3601f8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq5 .. pbf.num_blocks_allocated_cons_voq5 (12 regs) */
literal|0x0c360208
block|,
comment|/* pbf.ycmd_qs_num_lines_voq6 .. pbf.num_blocks_allocated_cons_voq6 (12 regs) */
literal|0x0c360218
block|,
comment|/* pbf.ycmd_qs_num_lines_voq7 .. pbf.num_blocks_allocated_cons_voq7 (12 regs) */
literal|0x0c360228
block|,
comment|/* pbf.ycmd_qs_num_lines_voq8 .. pbf.num_blocks_allocated_cons_voq8 (12 regs) */
literal|0x0c360238
block|,
comment|/* pbf.ycmd_qs_num_lines_voq9 .. pbf.num_blocks_allocated_cons_voq9 (12 regs) */
literal|0x0c360248
block|,
comment|/* pbf.ycmd_qs_num_lines_voq10 .. pbf.num_blocks_allocated_cons_voq10 (12 regs) */
literal|0x0c360258
block|,
comment|/* pbf.ycmd_qs_num_lines_voq11 .. pbf.num_blocks_allocated_cons_voq11 (12 regs) */
literal|0x0c360268
block|,
comment|/* pbf.ycmd_qs_num_lines_voq12 .. pbf.num_blocks_allocated_cons_voq12 (12 regs) */
literal|0x0c360278
block|,
comment|/* pbf.ycmd_qs_num_lines_voq13 .. pbf.num_blocks_allocated_cons_voq13 (12 regs) */
literal|0x0c360288
block|,
comment|/* pbf.ycmd_qs_num_lines_voq14 .. pbf.num_blocks_allocated_cons_voq14 (12 regs) */
literal|0x0c360298
block|,
comment|/* pbf.ycmd_qs_num_lines_voq15 .. pbf.num_blocks_allocated_cons_voq15 (12 regs) */
literal|0x0c3602a8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq16 .. pbf.num_blocks_allocated_cons_voq16 (12 regs) */
literal|0x0c3602b8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq17 .. pbf.num_blocks_allocated_cons_voq17 (12 regs) */
literal|0x0c3602c8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq18 .. pbf.num_blocks_allocated_cons_voq18 (12 regs) */
literal|0x0c3602d8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq19 .. pbf.num_blocks_allocated_cons_voq19 (12 regs) */
literal|0x053d0000
block|,
comment|/* block rdif */
literal|0x040c0010
block|,
comment|/* rdif.stop_on_error .. rdif.min_eob2wf_l1_rd_del (4 regs) */
literal|0x010c0015
block|,
comment|/* rdif.dirty_l1 (1 regs) */
literal|0x1c0c001c
block|,
comment|/* rdif.debug_command_fifo_empty .. rdif.stat_num_err_interval_0 (28 regs) */
literal|0x020c0060
block|,
comment|/* rdif.INT_STS .. rdif.INT_MASK (2 regs) */
literal|0x050c0140
block|,
comment|/* rdif.dbg_select .. rdif.dbg_force_frame (5 regs) */
literal|0x043e0000
block|,
comment|/* block tdif */
literal|0x060c4010
block|,
comment|/* tdif.stop_on_error .. tdif.dirty_l1 (6 regs) */
literal|0x200c401c
block|,
comment|/* tdif.debug_command_fifo_empty .. tdif.stat_num_err_interval_3 (32 regs) */
literal|0x020c4060
block|,
comment|/* tdif.INT_STS .. tdif.INT_MASK (2 regs) */
literal|0x050c4140
block|,
comment|/* tdif.dbg_select .. tdif.dbg_force_frame (5 regs) */
literal|0x0a3f0000
block|,
comment|/* block cdu */
literal|0x01160010
block|,
comment|/* cdu.control0 (1 regs) */
literal|0x01160070
block|,
comment|/* cdu.INT_STS (1 regs) */
literal|0x01160073
block|,
comment|/* cdu.INT_MASK (1 regs) */
literal|0x04160100
block|,
comment|/* cdu.ccfc_ctx_valid0 .. cdu.tcfc_ctx_valid1 (4 regs) */
literal|0x02160140
block|,
comment|/* cdu.ldbuf_af_thresh .. cdu.wbbuf_af_thresh (2 regs) */
literal|0x04160180
block|,
comment|/* cdu.ccfc_pxp .. cdu.wb_vqid (4 regs) */
literal|0x061601c0
block|,
comment|/* cdu.debug .. cdu.dbg_force_frame (6 regs) */
literal|0x011601d2
block|,
comment|/* cdu.eco_reserved (1 regs) */
literal|0x06160200
block|,
comment|/* cdu.ccfc_cvld_error_data .. cdu.tcfc_wb_l1_num_error_data (6 regs) */
literal|0x03160240
block|,
comment|/* cdu.cid_addr_params .. cdu.segment1_params (3 regs) */
literal|0x10400000
block|,
comment|/* block ccfc */
literal|0x050b8000
block|,
comment|/* ccfc.init_reg .. ccfc.tidram_init_done (5 regs) */
literal|0x020b8060
block|,
comment|/* ccfc.INT_STS_0 .. ccfc.INT_MASK_0 (2 regs) */
literal|0x0c0b8100
block|,
comment|/* ccfc.lc_blocked .. ccfc.cdu_write_backs (12 regs) */
literal|0x050b8140
block|,
comment|/* ccfc.dbg_select .. ccfc.dbg_force_frame (5 regs) */
literal|0x090b8152
block|,
comment|/* ccfc.eco_reserved .. ccfc.arbiters_reg (9 regs) */
literal|0x060b8170
block|,
comment|/* ccfc.debug0 .. ccfc.cdu_pcie_err_mask (6 regs) */
literal|0x020b8177
block|,
comment|/* ccfc.sreq_full_sticky .. ccfc.prsresp_full_sticky (2 regs) */
literal|0x0b0b8180
block|,
comment|/* ccfc.num_lcids_empty .. ccfc.max_inside (11 regs) */
literal|0x020b81c4
block|,
comment|/* ccfc.LoadRetry_Types .. ccfc.MiniCache_Control (2 regs) */
literal|0x010b81c7
block|,
comment|/* ccfc.control0 (1 regs) */
literal|0x040b81e0
block|,
comment|/* ccfc.prsresp_credit .. ccfc.cduwb_credit (4 regs) */
literal|0x040b8200
block|,
comment|/* ccfc.ll_policy_cfg .. ccfc.empty_size (4 regs) */
literal|0x1f0b8240
block|,
comment|/* ccfc.lc_client_0_lcid_threshold .. ccfc.wave_sm_2_one_count (31 regs) */
literal|0x120b8280
block|,
comment|/* ccfc.cache_string_type .. ccfc.include_vlan_in_hash (18 regs) */
literal|0x080b82c0
block|,
comment|/* ccfc.cid_cam_bist_en .. ccfc.string_cam_bist_status (8 regs) */
literal|0x020bb400
block|,
comment|/* ccfc.vpf1_lstate_sel .. ccfc.vpf2_lstate_sel (2 regs) */
literal|0x10410000
block|,
comment|/* block tcfc */
literal|0x050b4000
block|,
comment|/* tcfc.init_reg .. tcfc.tidram_init_done (5 regs) */
literal|0x020b4060
block|,
comment|/* tcfc.INT_STS_0 .. tcfc.INT_MASK_0 (2 regs) */
literal|0x0c0b4100
block|,
comment|/* tcfc.lc_blocked .. tcfc.cdu_write_backs (12 regs) */
literal|0x050b4140
block|,
comment|/* tcfc.dbg_select .. tcfc.dbg_force_frame (5 regs) */
literal|0x090b4152
block|,
comment|/* tcfc.eco_reserved .. tcfc.arbiters_reg (9 regs) */
literal|0x060b4170
block|,
comment|/* tcfc.debug0 .. tcfc.cdu_pcie_err_mask (6 regs) */
literal|0x020b4177
block|,
comment|/* tcfc.sreq_full_sticky .. tcfc.prsresp_full_sticky (2 regs) */
literal|0x0b0b4180
block|,
comment|/* tcfc.num_lcids_empty .. tcfc.max_inside (11 regs) */
literal|0x020b41c4
block|,
comment|/* tcfc.LoadRetry_Types .. tcfc.MiniCache_Control (2 regs) */
literal|0x010b41c7
block|,
comment|/* tcfc.control0 (1 regs) */
literal|0x040b41e0
block|,
comment|/* tcfc.prsresp_credit .. tcfc.cduwb_credit (4 regs) */
literal|0x040b4200
block|,
comment|/* tcfc.ll_policy_cfg .. tcfc.empty_size (4 regs) */
literal|0x1f0b4240
block|,
comment|/* tcfc.lc_client_0_lcid_threshold .. tcfc.wave_sm_2_one_count (31 regs) */
literal|0x120b4280
block|,
comment|/* tcfc.cache_string_type .. tcfc.include_vlan_in_hash (18 regs) */
literal|0x080b42c0
block|,
comment|/* tcfc.cid_cam_bist_en .. tcfc.string_cam_bist_status (8 regs) */
literal|0x020b7400
block|,
comment|/* tcfc.vpf1_lstate_sel .. tcfc.vpf2_lstate_sel (2 regs) */
literal|0x0e420000
block|,
comment|/* block igu */
literal|0x01060000
block|,
comment|/* igu.reset_memories (1 regs) */
literal|0x01060010
block|,
comment|/* igu.block_configuration (1 regs) */
literal|0x01060014
block|,
comment|/* igu.pxp_requester_initial_credit (1 regs) */
literal|0x02060060
block|,
comment|/* igu.INT_STS .. igu.INT_MASK (2 regs) */
literal|0x08060103
block|,
comment|/* igu.pxp_request_counter .. igu.cons_upd_counter (8 regs) */
literal|0x01060202
block|,
comment|/* igu.message_fields (1 regs) */
literal|0x01060213
block|,
comment|/* igu.statistic_en (1 regs) */
literal|0x03060218
block|,
comment|/* igu.cam_parity_scrubbing .. igu.eco_reserved (3 regs) */
literal|0x10060300
block|,
comment|/* igu.vf_with_more_16sb_0 .. igu.vf_with_more_16sb_15 (16 regs) */
literal|0x03060480
block|,
comment|/* igu.global_rate_limiter_vari0 .. igu.global_rate_tick_rate_counter (3 regs) */
literal|0x01060485
block|,
comment|/* igu.clk25_counter_sensitivity (1 regs) */
literal|0x06060487
block|,
comment|/* igu.group_rl_en_0 .. igu.group_rl_pending_1 (6 regs) */
literal|0x08060540
block|,
comment|/* igu.attention_signal_p0_status .. igu.Interrupt_status (8 regs) */
literal|0x1706054c
block|,
comment|/* igu.error_handling_data_valid .. igu.dbg_force_frame (23 regs) */
literal|0x0f430000
block|,
comment|/* block cau */
literal|0x01070035
block|,
comment|/* cau.INT_STS (1 regs) */
literal|0x01070038
block|,
comment|/* cau.INT_MASK (1 regs) */
literal|0x05070100
block|,
comment|/* cau.num_pi_per_sb .. cau.reset_memories (5 regs) */
literal|0x02070140
block|,
comment|/* cau.in_arb_priority .. cau.in_arb_timeout (2 regs) */
literal|0x040701c0
block|,
comment|/* cau.tick_size .. cau.stop_scan (4 regs) */
literal|0x01070220
block|,
comment|/* cau.wdata_fifo_afull_thr (1 regs) */
literal|0x02070260
block|,
comment|/* cau.igu_req_credit_status .. cau.igu_cmd_credit_status (2 regs) */
literal|0x060702a0
block|,
comment|/* cau.stat_ctrl_sb_select .. cau.stat_ctrl_timer_cmd_type (6 regs) */
literal|0x0a0702e0
block|,
comment|/* cau.stat_counter_sb_gen .. cau.stat_counter_fsm1_line (10 regs) */
literal|0x06070320
block|,
comment|/* cau.debug_fifo_status .. cau.error_cleanup_cmd_reg (6 regs) */
literal|0x0107032b
block|,
comment|/* cau.eco_reserved (1 regs) */
literal|0x05070360
block|,
comment|/* cau.debug_record_mask_min_sb .. cau.debug_record_mask_cmd_type (5 regs) */
literal|0x03070380
block|,
comment|/* cau.req_counter .. cau.wdone_counter (3 regs) */
literal|0x050703aa
block|,
comment|/* cau.dbg_select .. cau.dbg_force_frame (5 regs) */
literal|0x030703c0
block|,
comment|/* cau.main_fsm_status .. cau.igu_dma_fsm_status (3 regs) */
literal|0x0b4a0000
block|,
comment|/* block dbg */
literal|0x01004001
block|,
comment|/* dbg.client_enable (1 regs) */
literal|0x01004003
block|,
comment|/* dbg.output_enable (1 regs) */
literal|0x14004005
block|,
comment|/* dbg.calendar_slot0 .. dbg.full_mode (20 regs) */
literal|0x02004060
block|,
comment|/* dbg.INT_STS .. dbg.INT_MASK (2 regs) */
literal|0x02004100
block|,
comment|/* dbg.intr_buffer_rd_ptr .. dbg.intr_buffer_wr_ptr (2 regs) */
literal|0x04804102
block|,
comment|/* dbg.ext_buffer_rd_ptr .. dbg.ext_buffer_wr_ptr (4 regs, WB) */
literal|0x13004106
block|,
comment|/* dbg.wrap_on_int_buffer .. dbg.pci_logic_addr (19 regs) */
literal|0xff004150
block|,
comment|/* dbg.pattern_recognition_disable .. dbg.trigger_state_set_cnstr_cyclic_15 (255 regs) */
literal|0x6100424f
block|,
comment|/* dbg.trigger_state_set_cnstr_cyclic_16 .. dbg.dbg_driver_trigger (97 regs) */
literal|0x210042c4
block|,
comment|/* dbg.hw_id_num .. dbg.filter_status_match_cnstr (33 regs) */
literal|0x020042e8
block|,
comment|/* dbg.memctrl_status .. dbg.num_of_empty_lines_in_int_buffer (2 regs) */
literal|0x264b0000
block|,
comment|/* block nig */
literal|0x02140010
block|,
comment|/* nig.INT_STS_0 .. nig.INT_MASK_0 (2 regs) */
literal|0x02140014
block|,
comment|/* nig.INT_STS_1 .. nig.INT_MASK_1 (2 regs) */
literal|0x02140018
block|,
comment|/* nig.INT_STS_2 .. nig.INT_MASK_2 (2 regs) */
literal|0x0214001c
block|,
comment|/* nig.INT_STS_3 .. nig.INT_MASK_3 (2 regs) */
literal|0x02140020
block|,
comment|/* nig.INT_STS_4 .. nig.INT_MASK_4 (2 regs) */
literal|0x02140024
block|,
comment|/* nig.INT_STS_5 .. nig.INT_MASK_5 (2 regs) */
literal|0x12140200
block|,
comment|/* nig.close_gate_disable .. nig.tx_lb_drop_fwderr (18 regs) */
literal|0x04140301
block|,
comment|/* nig.lb_sopq_empty .. nig.tx_sopq_full (4 regs) */
literal|0x04140380
block|,
comment|/* nig.dorq_in_en .. nig.ppp_out_en (4 regs) */
literal|0x01140401
block|,
comment|/* nig.initial_header_size (1 regs) */
literal|0x01140403
block|,
comment|/* nig.llh_arp_type (1 regs) */
literal|0x0214041b
block|,
comment|/* nig.roce_type .. nig.gre_eth_type (2 regs) */
literal|0x01140421
block|,
comment|/* nig.gre_protocol (1 regs) */
literal|0x0114044e
block|,
comment|/* nig.rx_llh_svol_mcp_fwd_allpf (1 regs) */
literal|0x01140454
block|,
comment|/* nig.rx_llh_svol_brb_dntfwd_allpf (1 regs) */
literal|0x0114047c
block|,
comment|/* nig.rx_llh_brb_gate_dntfwd_clsfailed (1 regs) */
literal|0x01140598
block|,
comment|/* nig.lb_llh_brb_gate_dntfwd_clsfailed (1 regs) */
literal|0x041406e0
block|,
comment|/* nig.llh_eng_cls_type .. nig.llh_eng_cls_crc8_init_val (4 regs) */
literal|0x029406e4
block|,
comment|/* nig.llh_eng_cls_eng_id_tbl (2 regs, WB) */
literal|0x011406e6
block|,
comment|/* nig.llh_eng_cls_roce_qp_sel (1 regs) */
literal|0x04140715
block|,
comment|/* nig.ppp_address .. nig.ppp_trig (4 regs) */
literal|0x0114074a
block|,
comment|/* nig.stat_rx_storm_packet_sent (1 regs) */
literal|0x0114082b
block|,
comment|/* nig.bmb_fifo_alm_full_thr (1 regs) */
literal|0x05140830
block|,
comment|/* nig.dorq_fifo_alm_full_thr .. nig.debug_port (5 regs) */
literal|0x04140836
block|,
comment|/* nig.debug_pkt_wait_size .. nig.debug_fifo_full (4 regs) */
literal|0x10140871
block|,
comment|/* nig.rx_fc_dbg_select_pllh .. nig.eco_reserved (16 regs) */
literal|0x02142216
block|,
comment|/* nig.pm_timer_select .. nig.ts_for_semi_select (2 regs) */
literal|0x0214221c
block|,
comment|/* nig.ts_output_enable_pda .. nig.ts_output_enable_hv (2 regs) */
literal|0x0214222a
block|,
comment|/* nig.tsgen_free_cnt_value_lsb .. nig.tsgen_free_cnt_value_msb (2 regs) */
literal|0x0214222e
block|,
comment|/* nig.tsgen_freecnt_lsb .. nig.tsgen_freecnt_msb (2 regs) */
literal|0x02142234
block|,
comment|/* nig.tsgen_pps_high_time .. nig.tsgen_pps_low_time (2 regs) */
literal|0x03142238
block|,
comment|/* nig.tsgen_tsio_oeb .. nig.edpm_fifo_full_thresh (3 regs) */
literal|0x011422c3
block|,
comment|/* nig.rroce_port (1 regs) */
literal|0x011422cd
block|,
comment|/* nig.nge_eth_type (1 regs) */
literal|0x021422d0
block|,
comment|/* nig.bth_hdr_flow_ctrl_opcode_1 .. nig.bth_hdr_flow_ctrl_opcode_2 (2 regs) */
literal|0x011422d7
block|,
comment|/* nig.dbgmux_ovflw_ind_en (1 regs) */
literal|0x011422df
block|,
comment|/* nig.tx_parity_error_timer (1 regs) */
literal|0x021422e3
block|,
comment|/* nig.tx_inhibit_bmb_arb_en .. nig.lb_inhibit_bmb_arb_en (2 regs) */
literal|0x02050007
block|,
comment|/* mode bb, block cnig */
literal|0x0108608e
block|,
comment|/* cnig.eco_reserved (1 regs) */
literal|0x020860ba
block|,
comment|/* cnig.INT_STS .. cnig.INT_MASK (2 regs) */
literal|0x11180000
block|,
comment|/* block tcm */
literal|0x08460101
block|,
comment|/* tcm.qm_con_base_evnt_id_0 .. tcm.qm_con_base_evnt_id_7 (8 regs) */
literal|0x10460111
block|,
comment|/* tcm.qm_agg_con_ctx_part_size_0 .. tcm.qm_sm_con_ctx_ldst_flg_7 (16 regs) */
literal|0x10460131
block|,
comment|/* tcm.qm_xxlock_cmd_0 .. tcm.qm_con_use_st_flg_7 (16 regs) */
literal|0x08460149
block|,
comment|/* tcm.tm_con_evnt_id_0 .. tcm.tm_con_evnt_id_7 (8 regs) */
literal|0x01460183
block|,
comment|/* tcm.ysem_weight (1 regs) */
literal|0x01460188
block|,
comment|/* tcm.tsdm_weight (1 regs) */
literal|0x084601dc
block|,
comment|/* tcm.xx_byp_msg_up_bnd_0 .. tcm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x08460205
block|,
comment|/* tcm.n_sm_con_ctx_ld_0 .. tcm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x08460228
block|,
comment|/* tcm.agg_con_ctx_size_0 .. tcm.agg_con_ctx_size_7 (8 regs) */
literal|0x1c460245
block|,
comment|/* tcm.agg_con_cf0_q .. tcm.agg_task_cf7_q (28 regs) */
literal|0x014602aa
block|,
comment|/* tcm.tsdm_length_mis (1 regs) */
literal|0x014602b1
block|,
comment|/* tcm.tsdm_msg_cntr (1 regs) */
literal|0x014602b3
block|,
comment|/* tcm.ysem_msg_cntr (1 regs) */
literal|0x014602bf
block|,
comment|/* tcm.is_tsdm_fill_lvl (1 regs) */
literal|0x014602c1
block|,
comment|/* tcm.is_ysem_fill_lvl (1 regs) */
literal|0x014602e4
block|,
comment|/* tcm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x014602e8
block|,
comment|/* tcm.is_foc_tsdm_nxt_inf_unit (1 regs) */
literal|0x10190000
block|,
comment|/* block mcm */
literal|0x08480101
block|,
comment|/* mcm.qm_con_base_evnt_id_0 .. mcm.qm_con_base_evnt_id_7 (8 regs) */
literal|0x10480111
block|,
comment|/* mcm.qm_agg_con_ctx_part_size_0 .. mcm.qm_sm_con_ctx_ldst_flg_7 (16 regs) */
literal|0x10480141
block|,
comment|/* mcm.qm_xxlock_cmd_0 .. mcm.qm_con_use_st_flg_7 (16 regs) */
literal|0x01480183
block|,
comment|/* mcm.ysem_weight (1 regs) */
literal|0x01480186
block|,
comment|/* mcm.msdm_weight (1 regs) */
literal|0x084801dc
block|,
comment|/* mcm.xx_byp_msg_up_bnd_0 .. mcm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x08480205
block|,
comment|/* mcm.n_sm_con_ctx_ld_0 .. mcm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x08480228
block|,
comment|/* mcm.agg_con_ctx_size_0 .. mcm.agg_con_ctx_size_7 (8 regs) */
literal|0x0b480245
block|,
comment|/* mcm.agg_con_cf0_q .. mcm.agg_task_cf2_q (11 regs) */
literal|0x014802aa
block|,
comment|/* mcm.msdm_length_mis (1 regs) */
literal|0x014802b2
block|,
comment|/* mcm.msdm_msg_cntr (1 regs) */
literal|0x014802b7
block|,
comment|/* mcm.ysem_msg_cntr (1 regs) */
literal|0x014802bf
block|,
comment|/* mcm.is_msdm_fill_lvl (1 regs) */
literal|0x014802c4
block|,
comment|/* mcm.is_ysem_fill_lvl (1 regs) */
literal|0x014802e4
block|,
comment|/* mcm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x014802e6
block|,
comment|/* mcm.is_foc_msdm_nxt_inf_unit (1 regs) */
literal|0x081a0000
block|,
comment|/* block ucm */
literal|0x084a0101
block|,
comment|/* ucm.qm_con_base_evnt_id_0 .. ucm.qm_con_base_evnt_id_7 (8 regs) */
literal|0x104a0111
block|,
comment|/* ucm.qm_agg_con_ctx_part_size_0 .. ucm.qm_sm_con_ctx_ldst_flg_7 (16 regs) */
literal|0x104a0131
block|,
comment|/* ucm.qm_xxlock_cmd_0 .. ucm.qm_con_use_st_flg_7 (16 regs) */
literal|0x084a0149
block|,
comment|/* ucm.tm_con_evnt_id_0 .. ucm.tm_con_evnt_id_7 (8 regs) */
literal|0x084a01dc
block|,
comment|/* ucm.xx_byp_msg_up_bnd_0 .. ucm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x084a0205
block|,
comment|/* ucm.n_sm_con_ctx_ld_0 .. ucm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x084a0228
block|,
comment|/* ucm.agg_con_ctx_size_0 .. ucm.agg_con_ctx_size_7 (8 regs) */
literal|0x154a0245
block|,
comment|/* ucm.agg_con_cf0_q .. ucm.agg_task_cf4_q (21 regs) */
literal|0x0e1b0000
block|,
comment|/* block xcm */
literal|0x30400101
block|,
comment|/* xcm.qm_con_base_evnt_id_0 .. xcm.tm_con_evnt_id_7 (48 regs) */
literal|0x01400184
block|,
comment|/* xcm.ysem_weight (1 regs) */
literal|0x01400188
block|,
comment|/* xcm.msdm_weight (1 regs) */
literal|0x084001d9
block|,
comment|/* xcm.xx_byp_msg_up_bnd_0 .. xcm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x08400203
block|,
comment|/* xcm.n_sm_con_ctx_ld_0 .. xcm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x08400215
block|,
comment|/* xcm.agg_con_ctx_size_0 .. xcm.agg_con_ctx_size_7 (8 regs) */
literal|0x32400242
block|,
comment|/* xcm.agg_con_cf0_q .. xcm.agg_con_rule25_q (50 regs) */
literal|0x014002aa
block|,
comment|/* xcm.msdm_length_mis (1 regs) */
literal|0x014002b3
block|,
comment|/* xcm.msdm_msg_cntr (1 regs) */
literal|0x014002b9
block|,
comment|/* xcm.ysem_msg_cntr (1 regs) */
literal|0x014002c4
block|,
comment|/* xcm.is_msdm_fill_lvl (1 regs) */
literal|0x014002ca
block|,
comment|/* xcm.is_ysem_fill_lvl (1 regs) */
literal|0x014002e5
block|,
comment|/* xcm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x014002e8
block|,
comment|/* xcm.is_foc_msdm_nxt_inf_unit (1 regs) */
literal|0x0d1c0000
block|,
comment|/* block ycm */
literal|0x08420101
block|,
comment|/* ycm.qm_con_base_evnt_id_0 .. ycm.qm_con_base_evnt_id_7 (8 regs) */
literal|0x10420111
block|,
comment|/* ycm.qm_agg_con_ctx_part_size_0 .. ycm.qm_sm_con_ctx_ldst_flg_7 (16 regs) */
literal|0x10420141
block|,
comment|/* ycm.qm_xxlock_cmd_0 .. ycm.qm_con_use_st_flg_7 (16 regs) */
literal|0x01420186
block|,
comment|/* ycm.msdm_weight (1 regs) */
literal|0x084201dc
block|,
comment|/* ycm.xx_byp_msg_up_bnd_0 .. ycm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x08420205
block|,
comment|/* ycm.n_sm_con_ctx_ld_0 .. ycm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x08420228
block|,
comment|/* ycm.agg_con_ctx_size_0 .. ycm.agg_con_ctx_size_7 (8 regs) */
literal|0x11420245
block|,
comment|/* ycm.agg_con_cf0_q .. ycm.agg_task_rule6_q (17 regs) */
literal|0x014202aa
block|,
comment|/* ycm.msdm_length_mis (1 regs) */
literal|0x014202b1
block|,
comment|/* ycm.msdm_msg_cntr (1 regs) */
literal|0x014202bd
block|,
comment|/* ycm.is_msdm_fill_lvl (1 regs) */
literal|0x014202e4
block|,
comment|/* ycm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x014202e6
block|,
comment|/* ycm.is_foc_msdm_nxt_inf_unit (1 regs) */
literal|0x061d0000
block|,
comment|/* block pcm */
literal|0x01440184
block|,
comment|/* pcm.psdm_weight (1 regs) */
literal|0x08440202
block|,
comment|/* pcm.n_sm_con_ctx_ld_0 .. pcm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x014402aa
block|,
comment|/* pcm.psdm_length_mis (1 regs) */
literal|0x014402af
block|,
comment|/* pcm.psdm_msg_cntr (1 regs) */
literal|0x014402b3
block|,
comment|/* pcm.is_psdm_fill_lvl (1 regs) */
literal|0x014402e4
block|,
comment|/* pcm.is_foc_psdm_nxt_inf_unit (1 regs) */
literal|0x021e0000
block|,
comment|/* block qm */
literal|0x280bc448
block|,
comment|/* qm.CtxRegCcfc_0 .. qm.CtxRegCcfc_39 (40 regs) */
literal|0x280bc4c8
block|,
comment|/* qm.ActCtrInitValCcfc_0 .. qm.ActCtrInitValCcfc_39 (40 regs) */
literal|0x03200000
block|,
comment|/* block dorq */
literal|0x1004012d
block|,
comment|/* dorq.qm_en_byp_mask_0 .. dorq.dpi_val_sup_7 (16 regs) */
literal|0x38040185
block|,
comment|/* dorq.xcm_agg_flg_mask_conn_0 .. dorq.dpm_xcm_event_id_7 (56 regs) */
literal|0x080401c3
block|,
comment|/* dorq.qm_byp_agg_ctx_size_0 .. dorq.qm_byp_agg_ctx_size_7 (8 regs) */
literal|0x02210000
block|,
comment|/* block brb */
literal|0x020d0220
block|,
comment|/* brb.shared_hr_area (2 regs) */
literal|0x020d0230
block|,
comment|/* brb.total_mac_size (2 regs) */
literal|0x04230000
block|,
comment|/* block prs */
literal|0x1007c040
block|,
comment|/* prs.packet_region_0 .. prs.pure_region_7 (16 regs) */
literal|0x0807c051
block|,
comment|/* prs.con_inc_value_0 .. prs.con_inc_value_7 (8 regs) */
literal|0x0807c245
block|,
comment|/* prs.cm_hdr_event_id_0 .. prs.cm_hdr_event_id_7 (8 regs) */
literal|0x1007c25f
block|,
comment|/* prs.output_format_0_0 .. prs.output_format_7_1 (16 regs) */
literal|0x012a0000
block|,
comment|/* block tsem */
literal|0x04dc0108
block|,
comment|/* tsem.vf_err_vector (4 regs, WB) */
literal|0x012b0000
block|,
comment|/* block msem */
literal|0x04e00108
block|,
comment|/* msem.vf_err_vector (4 regs, WB) */
literal|0x012c0000
block|,
comment|/* block usem */
literal|0x04e40108
block|,
comment|/* usem.vf_err_vector (4 regs, WB) */
literal|0x012d0000
block|,
comment|/* block xsem */
literal|0x04d00108
block|,
comment|/* xsem.vf_err_vector (4 regs, WB) */
literal|0x012e0000
block|,
comment|/* block ysem */
literal|0x04d40108
block|,
comment|/* ysem.vf_err_vector (4 regs, WB) */
literal|0x012f0000
block|,
comment|/* block psem */
literal|0x04d80108
block|,
comment|/* psem.vf_err_vector (4 regs, WB) */
literal|0x01310000
block|,
comment|/* block tmld */
literal|0x02134001
block|,
comment|/* tmld.scbd_wrr_weight_q0 .. tmld.scbd_wrr_weight_q1 (2 regs) */
literal|0x01340000
block|,
comment|/* block xyld */
literal|0x02130001
block|,
comment|/* xyld.scbd_wrr_weight_q0 .. xyld.scbd_wrr_weight_q1 (2 regs) */
literal|0x013c0000
block|,
comment|/* block pbf */
literal|0x013603a8
block|,
comment|/* pbf.eco_reserved (1 regs) */
literal|0x11180009
block|,
comment|/* mode k2, block tcm */
literal|0x08460101
block|,
comment|/* tcm.qm_con_base_evnt_id_0 .. tcm.qm_con_base_evnt_id_7 (8 regs) */
literal|0x10460111
block|,
comment|/* tcm.qm_agg_con_ctx_part_size_0 .. tcm.qm_sm_con_ctx_ldst_flg_7 (16 regs) */
literal|0x10460131
block|,
comment|/* tcm.qm_xxlock_cmd_0 .. tcm.qm_con_use_st_flg_7 (16 regs) */
literal|0x08460149
block|,
comment|/* tcm.tm_con_evnt_id_0 .. tcm.tm_con_evnt_id_7 (8 regs) */
literal|0x01460183
block|,
comment|/* tcm.ysem_weight (1 regs) */
literal|0x01460188
block|,
comment|/* tcm.tsdm_weight (1 regs) */
literal|0x084601dc
block|,
comment|/* tcm.xx_byp_msg_up_bnd_0 .. tcm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x08460205
block|,
comment|/* tcm.n_sm_con_ctx_ld_0 .. tcm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x08460228
block|,
comment|/* tcm.agg_con_ctx_size_0 .. tcm.agg_con_ctx_size_7 (8 regs) */
literal|0x1c460245
block|,
comment|/* tcm.agg_con_cf0_q .. tcm.agg_task_cf7_q (28 regs) */
literal|0x014602aa
block|,
comment|/* tcm.tsdm_length_mis (1 regs) */
literal|0x014602b1
block|,
comment|/* tcm.tsdm_msg_cntr (1 regs) */
literal|0x014602b3
block|,
comment|/* tcm.ysem_msg_cntr (1 regs) */
literal|0x014602bf
block|,
comment|/* tcm.is_tsdm_fill_lvl (1 regs) */
literal|0x014602c1
block|,
comment|/* tcm.is_ysem_fill_lvl (1 regs) */
literal|0x014602e4
block|,
comment|/* tcm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x014602e8
block|,
comment|/* tcm.is_foc_tsdm_nxt_inf_unit (1 regs) */
literal|0x10190000
block|,
comment|/* block mcm */
literal|0x08480101
block|,
comment|/* mcm.qm_con_base_evnt_id_0 .. mcm.qm_con_base_evnt_id_7 (8 regs) */
literal|0x10480111
block|,
comment|/* mcm.qm_agg_con_ctx_part_size_0 .. mcm.qm_sm_con_ctx_ldst_flg_7 (16 regs) */
literal|0x10480141
block|,
comment|/* mcm.qm_xxlock_cmd_0 .. mcm.qm_con_use_st_flg_7 (16 regs) */
literal|0x01480183
block|,
comment|/* mcm.ysem_weight (1 regs) */
literal|0x01480186
block|,
comment|/* mcm.msdm_weight (1 regs) */
literal|0x084801dc
block|,
comment|/* mcm.xx_byp_msg_up_bnd_0 .. mcm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x08480205
block|,
comment|/* mcm.n_sm_con_ctx_ld_0 .. mcm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x08480228
block|,
comment|/* mcm.agg_con_ctx_size_0 .. mcm.agg_con_ctx_size_7 (8 regs) */
literal|0x0b480245
block|,
comment|/* mcm.agg_con_cf0_q .. mcm.agg_task_cf2_q (11 regs) */
literal|0x014802aa
block|,
comment|/* mcm.msdm_length_mis (1 regs) */
literal|0x014802b2
block|,
comment|/* mcm.msdm_msg_cntr (1 regs) */
literal|0x014802b7
block|,
comment|/* mcm.ysem_msg_cntr (1 regs) */
literal|0x014802bf
block|,
comment|/* mcm.is_msdm_fill_lvl (1 regs) */
literal|0x014802c4
block|,
comment|/* mcm.is_ysem_fill_lvl (1 regs) */
literal|0x014802e4
block|,
comment|/* mcm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x014802e6
block|,
comment|/* mcm.is_foc_msdm_nxt_inf_unit (1 regs) */
literal|0x081a0000
block|,
comment|/* block ucm */
literal|0x084a0101
block|,
comment|/* ucm.qm_con_base_evnt_id_0 .. ucm.qm_con_base_evnt_id_7 (8 regs) */
literal|0x104a0111
block|,
comment|/* ucm.qm_agg_con_ctx_part_size_0 .. ucm.qm_sm_con_ctx_ldst_flg_7 (16 regs) */
literal|0x104a0131
block|,
comment|/* ucm.qm_xxlock_cmd_0 .. ucm.qm_con_use_st_flg_7 (16 regs) */
literal|0x084a0149
block|,
comment|/* ucm.tm_con_evnt_id_0 .. ucm.tm_con_evnt_id_7 (8 regs) */
literal|0x084a01dc
block|,
comment|/* ucm.xx_byp_msg_up_bnd_0 .. ucm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x084a0205
block|,
comment|/* ucm.n_sm_con_ctx_ld_0 .. ucm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x084a0228
block|,
comment|/* ucm.agg_con_ctx_size_0 .. ucm.agg_con_ctx_size_7 (8 regs) */
literal|0x154a0245
block|,
comment|/* ucm.agg_con_cf0_q .. ucm.agg_task_cf4_q (21 regs) */
literal|0x0e1b0000
block|,
comment|/* block xcm */
literal|0x30400101
block|,
comment|/* xcm.qm_con_base_evnt_id_0 .. xcm.tm_con_evnt_id_7 (48 regs) */
literal|0x01400184
block|,
comment|/* xcm.ysem_weight (1 regs) */
literal|0x01400188
block|,
comment|/* xcm.msdm_weight (1 regs) */
literal|0x084001d9
block|,
comment|/* xcm.xx_byp_msg_up_bnd_0 .. xcm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x08400203
block|,
comment|/* xcm.n_sm_con_ctx_ld_0 .. xcm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x08400215
block|,
comment|/* xcm.agg_con_ctx_size_0 .. xcm.agg_con_ctx_size_7 (8 regs) */
literal|0x32400242
block|,
comment|/* xcm.agg_con_cf0_q .. xcm.agg_con_rule25_q (50 regs) */
literal|0x014002aa
block|,
comment|/* xcm.msdm_length_mis (1 regs) */
literal|0x014002b3
block|,
comment|/* xcm.msdm_msg_cntr (1 regs) */
literal|0x014002b9
block|,
comment|/* xcm.ysem_msg_cntr (1 regs) */
literal|0x014002c4
block|,
comment|/* xcm.is_msdm_fill_lvl (1 regs) */
literal|0x014002ca
block|,
comment|/* xcm.is_ysem_fill_lvl (1 regs) */
literal|0x014002e5
block|,
comment|/* xcm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x014002e8
block|,
comment|/* xcm.is_foc_msdm_nxt_inf_unit (1 regs) */
literal|0x0d1c0000
block|,
comment|/* block ycm */
literal|0x08420101
block|,
comment|/* ycm.qm_con_base_evnt_id_0 .. ycm.qm_con_base_evnt_id_7 (8 regs) */
literal|0x10420111
block|,
comment|/* ycm.qm_agg_con_ctx_part_size_0 .. ycm.qm_sm_con_ctx_ldst_flg_7 (16 regs) */
literal|0x10420141
block|,
comment|/* ycm.qm_xxlock_cmd_0 .. ycm.qm_con_use_st_flg_7 (16 regs) */
literal|0x01420186
block|,
comment|/* ycm.msdm_weight (1 regs) */
literal|0x084201dc
block|,
comment|/* ycm.xx_byp_msg_up_bnd_0 .. ycm.xx_byp_msg_up_bnd_7 (8 regs) */
literal|0x08420205
block|,
comment|/* ycm.n_sm_con_ctx_ld_0 .. ycm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x08420228
block|,
comment|/* ycm.agg_con_ctx_size_0 .. ycm.agg_con_ctx_size_7 (8 regs) */
literal|0x11420245
block|,
comment|/* ycm.agg_con_cf0_q .. ycm.agg_task_rule6_q (17 regs) */
literal|0x014202aa
block|,
comment|/* ycm.msdm_length_mis (1 regs) */
literal|0x014202b1
block|,
comment|/* ycm.msdm_msg_cntr (1 regs) */
literal|0x014202bd
block|,
comment|/* ycm.is_msdm_fill_lvl (1 regs) */
literal|0x014202e4
block|,
comment|/* ycm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x014202e6
block|,
comment|/* ycm.is_foc_msdm_nxt_inf_unit (1 regs) */
literal|0x061d0000
block|,
comment|/* block pcm */
literal|0x01440184
block|,
comment|/* pcm.psdm_weight (1 regs) */
literal|0x08440202
block|,
comment|/* pcm.n_sm_con_ctx_ld_0 .. pcm.n_sm_con_ctx_ld_7 (8 regs) */
literal|0x014402aa
block|,
comment|/* pcm.psdm_length_mis (1 regs) */
literal|0x014402af
block|,
comment|/* pcm.psdm_msg_cntr (1 regs) */
literal|0x014402b3
block|,
comment|/* pcm.is_psdm_fill_lvl (1 regs) */
literal|0x014402e4
block|,
comment|/* pcm.is_foc_psdm_nxt_inf_unit (1 regs) */
literal|0x021e0000
block|,
comment|/* block qm */
literal|0x280bc448
block|,
comment|/* qm.CtxRegCcfc_0 .. qm.CtxRegCcfc_39 (40 regs) */
literal|0x280bc4c8
block|,
comment|/* qm.ActCtrInitValCcfc_0 .. qm.ActCtrInitValCcfc_39 (40 regs) */
literal|0x03200000
block|,
comment|/* block dorq */
literal|0x1004012d
block|,
comment|/* dorq.qm_en_byp_mask_0 .. dorq.dpi_val_sup_7 (16 regs) */
literal|0x38040185
block|,
comment|/* dorq.xcm_agg_flg_mask_conn_0 .. dorq.dpm_xcm_event_id_7 (56 regs) */
literal|0x080401c3
block|,
comment|/* dorq.qm_byp_agg_ctx_size_0 .. dorq.qm_byp_agg_ctx_size_7 (8 regs) */
literal|0x04230000
block|,
comment|/* block prs */
literal|0x1007c040
block|,
comment|/* prs.packet_region_0 .. prs.pure_region_7 (16 regs) */
literal|0x0807c051
block|,
comment|/* prs.con_inc_value_0 .. prs.con_inc_value_7 (8 regs) */
literal|0x0807c245
block|,
comment|/* prs.cm_hdr_event_id_0 .. prs.cm_hdr_event_id_7 (8 regs) */
literal|0x1007c25f
block|,
comment|/* prs.output_format_0_0 .. prs.output_format_7_1 (16 regs) */
literal|0x01310000
block|,
comment|/* block tmld */
literal|0x02134001
block|,
comment|/* tmld.scbd_wrr_weight_q0 .. tmld.scbd_wrr_weight_q1 (2 regs) */
literal|0x01340000
block|,
comment|/* block xyld */
literal|0x02130001
block|,
comment|/* xyld.scbd_wrr_weight_q0 .. xyld.scbd_wrr_weight_q1 (2 regs) */
literal|0x013c0000
block|,
comment|/* block pbf */
literal|0x013603a8
block|,
comment|/* pbf.eco_reserved (1 regs) */
literal|0x04010025
block|,
comment|/* mode !bb, block miscs */
literal|0x0100245c
block|,
comment|/* miscs.bsc_smbio_enable_glitch_filter (1 regs) */
literal|0x060024f0
block|,
comment|/* miscs.pcie_link_up_state .. miscs.main_pll_status (6 regs) */
literal|0x05002594
block|,
comment|/* miscs.bsc_sda_sel .. miscs.pcie_phy_rst_n_status (5 regs) */
literal|0x010025ae
block|,
comment|/* miscs.core_rst_n_status (1 regs) */
literal|0x07040000
block|,
comment|/* block pglue_b */
literal|0x030aa14a
block|,
comment|/* pglue_b.txw_h_syncfifo_almostfull_th .. pglue_b.txr_h_syncfifo_almostfull_th (3 regs) */
literal|0x010aabac
block|,
comment|/* pglue_b.cfg_no_l1_on_int (1 regs) */
literal|0x020aabaf
block|,
comment|/* pglue_b.mctp_max_length .. pglue_b.mctp_reqid (2 regs) */
literal|0x090aabb2
block|,
comment|/* pglue_b.pbus_num .. pglue_b.mrrs_attn (9 regs) */
literal|0x090aabbc
block|,
comment|/* pglue_b.txw_b2b_disable .. pglue_b.pgl_pm_dstate_47_32 (9 regs) */
literal|0x0f0aabd7
block|,
comment|/* pglue_b.check_tc_on_err .. pglue_b.mctp_venderid_chk_disable (15 regs) */
literal|0x0b0aabea
block|,
comment|/* pglue_b.ext_tag_en_pf_31_0 .. pglue_b.rxd_syncfifo_pop_status (11 regs) */
literal|0x03050000
block|,
comment|/* block cnig */
literal|0x08086080
block|,
comment|/* cnig.nig_port0_conf .. cnig.INT_MASK (8 regs) */
literal|0x0108608a
block|,
comment|/* cnig.nwm_lpi_defualt_value (1 regs) */
literal|0x06086094
block|,
comment|/* cnig.eco_reserved .. cnig.dbg_force_frame (6 regs) */
literal|0x01060000
block|,
comment|/* block cpmu */
literal|0x0200c100
block|,
comment|/* cpmu.sdm_sq_counter_e0_p2 .. cpmu.sdm_sq_counter_e0_p3 (2 regs) */
literal|0x040a0000
block|,
comment|/* block pcie */
literal|0x6a015084
block|,
comment|/* pcie.soft_reset_control .. pcie.msix_synch_sticky (106 regs) */
literal|0x020151e8
block|,
comment|/* pcie.INT_STS .. pcie.INT_MASK (2 regs) */
literal|0x050151fa
block|,
comment|/* pcie.dbg_select .. pcie.dbg_force_frame (5 regs) */
literal|0x02015200
block|,
comment|/* pcie.reset_status_2 .. pcie.reset_status_3 (2 regs) */
literal|0x10150000
block|,
comment|/* block pglcs */
literal|0x06000744
block|,
comment|/* pglcs.rasdp_error_mode_en_off .. pglcs.dbg_force_frame (6 regs) */
literal|0x07000852
block|,
comment|/* pglcs.pgl_cs.VC_BASE .. pglcs.pgl_cs.RESOURCE_STATUS_REG_VC0 (7 regs) */
literal|0x07000866
block|,
comment|/* pglcs.pgl_cs.SPCIE_CAP_HEADER_REG .. pglcs.pgl_cs.SPCIE_CAP_OFF_18H_REG (7 regs) */
literal|0x020008a1
block|,
comment|/* pglcs.pgl_cs.LTR_CAP_HDR_REG .. pglcs.pgl_cs.LTR_LATENCY_REG (2 regs) */
literal|0x030008f1
block|,
comment|/* pglcs.pgl_cs.PTM_EXT_CAP_HDR_OFF .. pglcs.pgl_cs.PTM_CONTROL_OFF (3 regs) */
literal|0x090009c0
block|,
comment|/* pglcs.pgl_cs.ACK_LATENCY_TIMER_OFF .. pglcs.pgl_cs.FILTER_MASK_2_OFF (9 regs) */
literal|0x0b0009ca
block|,
comment|/* pglcs.pgl_cs.PL_DEBUG0_OFF .. pglcs.pgl_cs.VC0_CPL_RX_Q_CTRL_OFF (11 regs) */
literal|0x03000a03
block|,
comment|/* pglcs.pgl_cs.GEN2_CTRL_OFF .. pglcs.pgl_cs.PHY_CONTROL_OFF (3 regs) */
literal|0x01000a24
block|,
comment|/* pglcs.pgl_cs.GEN3_RELATED_OFF (1 regs) */
literal|0x01000a28
block|,
comment|/* pglcs.pgl_cs.PF_HIDE_CONTROL (1 regs) */
literal|0x02000a2a
block|,
comment|/* pglcs.pgl_cs.GEN3_EQ_CONTROL_OFF .. pglcs.pgl_cs.GEN3_EQ_FB_MODE_DIR_CHANGE_OFF (2 regs) */
literal|0x06000a2d
block|,
comment|/* pglcs.pgl_cs.ORDER_RULE_CTRL_OFF .. pglcs.pgl_cs.TRGT_CPL_LUT_DELETE_ENTRY_OFF (6 regs) */
literal|0x01000a3f
block|,
comment|/* pglcs.pgl_cs.PL_LAST_OFF (1 regs) */
literal|0x01000acc
block|,
comment|/* pglcs.pgl_cs.PL_LTR_LATENCY_OFF (1 regs) */
literal|0x01000ad0
block|,
comment|/* pglcs.pgl_cs.AUX_CLK_FREQ_OFF (1 regs) */
literal|0x0e000e01
block|,
comment|/* pglcs.discard_poisoned_mctp_tgtwr .. pglcs.tx_syncfifo_pop_status (14 regs) */
literal|0x01170000
block|,
comment|/* block ptu */
literal|0x01158037
block|,
comment|/* ptu.atc_otb_overrun_fix_chicken_bit (1 regs) */
literal|0x061e0000
block|,
comment|/* block qm */
literal|0x080bc148
block|,
comment|/* qm.MaxPqSizeTxSel_56 .. qm.MaxPqSizeTxSel_63 (8 regs) */
literal|0x020bc41e
block|,
comment|/* qm.QstatusTx_14 .. qm.QstatusTx_15 (2 regs) */
literal|0x020bc432
block|,
comment|/* qm.QstatusOther_2 .. qm.QstatusOther_3 (2 regs) */
literal|0x080bc662
block|,
comment|/* qm.WrrOtherPqGrp_8 .. qm.WrrOtherPqGrp_15 (8 regs) */
literal|0x080bcb39
block|,
comment|/* qm.PqTx2Pf_56 .. qm.PqTx2Pf_63 (8 regs) */
literal|0x080bcb89
block|,
comment|/* qm.PqOther2Pf_8 .. qm.PqOther2Pf_15 (8 regs) */
literal|0x01200000
block|,
comment|/* block dorq */
literal|0x0204024b
block|,
comment|/* dorq.l2_edpm_tunnel_nge_ip_en .. dorq.l2_edpm_tunnel_nge_eth_en (2 regs) */
literal|0x18210000
block|,
comment|/* block brb */
literal|0x040d0220
block|,
comment|/* brb.shared_hr_area (4 regs) */
literal|0x040d0230
block|,
comment|/* brb.total_mac_size (4 regs) */
literal|0x020d0252
block|,
comment|/* brb.tc_guarantied_18 .. brb.tc_guarantied_19 (2 regs) */
literal|0x020d0288
block|,
comment|/* brb.lb_tc_guarantied_hyst_18 .. brb.lb_tc_guarantied_hyst_19 (2 regs) */
literal|0x020d02be
block|,
comment|/* brb.lb_tc_pause_xoff_threshold_18 .. brb.lb_tc_pause_xoff_threshold_19 (2 regs) */
literal|0x020d02f4
block|,
comment|/* brb.lb_tc_pause_xon_threshold_18 .. brb.lb_tc_pause_xon_threshold_19 (2 regs) */
literal|0x020d032a
block|,
comment|/* brb.lb_tc_full_xoff_threshold_18 .. brb.lb_tc_full_xoff_threshold_19 (2 regs) */
literal|0x020d0360
block|,
comment|/* brb.lb_tc_full_xon_threshold_18 .. brb.lb_tc_full_xon_threshold_19 (2 regs) */
literal|0x020d0374
block|,
comment|/* brb.wc_no_dead_cycles_en .. brb.wc_highest_pri_en (2 regs) */
literal|0x020d0393
block|,
comment|/* brb.pm_tc_latency_sensitive_2 .. brb.pm_tc_latency_sensitive_3 (2 regs) */
literal|0x040d03d0
block|,
comment|/* brb.wc_empty_4 .. brb.wc_empty_7 (4 regs) */
literal|0x040d03e0
block|,
comment|/* brb.wc_full_4 .. brb.wc_full_7 (4 regs) */
literal|0x020d0426
block|,
comment|/* brb.empty_if_2 .. brb.empty_if_3 (2 regs) */
literal|0x020d0470
block|,
comment|/* brb.mac_free_shared_hr_2 .. brb.mac_free_shared_hr_3 (2 regs) */
literal|0x050d0494
block|,
comment|/* brb.mac2_tc_occupancy_0 .. brb.mac2_tc_occupancy_4 (5 regs) */
literal|0x050d04a4
block|,
comment|/* brb.mac3_tc_occupancy_0 .. brb.mac3_tc_occupancy_4 (5 regs) */
literal|0x020d04b6
block|,
comment|/* brb.available_mac_size_2 .. brb.available_mac_size_3 (2 regs) */
literal|0x020d04bc
block|,
comment|/* brb.main_tc_pause_2 .. brb.main_tc_pause_3 (2 regs) */
literal|0x020d04c2
block|,
comment|/* brb.lb_tc_pause_2 .. brb.lb_tc_pause_3 (2 regs) */
literal|0x020d04c8
block|,
comment|/* brb.main_tc_full_2 .. brb.main_tc_full_3 (2 regs) */
literal|0x020d04ce
block|,
comment|/* brb.lb_tc_full_2 .. brb.lb_tc_full_3 (2 regs) */
literal|0x040d04f2
block|,
comment|/* brb.main2_tc_lossless_cnt_0 .. brb.main2_tc_lossless_cnt_3 (4 regs) */
literal|0x040d0502
block|,
comment|/* brb.main3_tc_lossless_cnt_0 .. brb.main3_tc_lossless_cnt_3 (4 regs) */
literal|0x020d0514
block|,
comment|/* brb.main_tc_lossless_int_2 .. brb.main_tc_lossless_int_3 (2 regs) */
literal|0x02240000
block|,
comment|/* block tsdm */
literal|0x023ec320
block|,
comment|/* tsdm.rmt_xcm_fifo_full .. tsdm.rmt_ycm_fifo_full (2 regs) */
literal|0x023ec35a
block|,
comment|/* tsdm.rmt_xcm_fifo_empty .. tsdm.rmt_ycm_fifo_empty (2 regs) */
literal|0x02250000
block|,
comment|/* block msdm */
literal|0x023f0320
block|,
comment|/* msdm.rmt_xcm_fifo_full .. msdm.rmt_ycm_fifo_full (2 regs) */
literal|0x023f035a
block|,
comment|/* msdm.rmt_xcm_fifo_empty .. msdm.rmt_ycm_fifo_empty (2 regs) */
literal|0x02260000
block|,
comment|/* block usdm */
literal|0x023f4320
block|,
comment|/* usdm.rmt_xcm_fifo_full .. usdm.rmt_ycm_fifo_full (2 regs) */
literal|0x023f435a
block|,
comment|/* usdm.rmt_xcm_fifo_empty .. usdm.rmt_ycm_fifo_empty (2 regs) */
literal|0x02270000
block|,
comment|/* block xsdm */
literal|0x023e0320
block|,
comment|/* xsdm.rmt_xcm_fifo_full .. xsdm.rmt_ycm_fifo_full (2 regs) */
literal|0x023e035a
block|,
comment|/* xsdm.rmt_xcm_fifo_empty .. xsdm.rmt_ycm_fifo_empty (2 regs) */
literal|0x02280000
block|,
comment|/* block ysdm */
literal|0x023e4320
block|,
comment|/* ysdm.rmt_xcm_fifo_full .. ysdm.rmt_ycm_fifo_full (2 regs) */
literal|0x023e435a
block|,
comment|/* ysdm.rmt_xcm_fifo_empty .. ysdm.rmt_ycm_fifo_empty (2 regs) */
literal|0x02290000
block|,
comment|/* block psdm */
literal|0x023e8320
block|,
comment|/* psdm.rmt_xcm_fifo_full .. psdm.rmt_ycm_fifo_full (2 regs) */
literal|0x023e835a
block|,
comment|/* psdm.rmt_xcm_fifo_empty .. psdm.rmt_ycm_fifo_empty (2 regs) */
literal|0x012a0000
block|,
comment|/* block tsem */
literal|0x08dc0108
block|,
comment|/* tsem.vf_err_vector (8 regs, WB) */
literal|0x012b0000
block|,
comment|/* block msem */
literal|0x08e00108
block|,
comment|/* msem.vf_err_vector (8 regs, WB) */
literal|0x012c0000
block|,
comment|/* block usem */
literal|0x08e40108
block|,
comment|/* usem.vf_err_vector (8 regs, WB) */
literal|0x012d0000
block|,
comment|/* block xsem */
literal|0x08d00108
block|,
comment|/* xsem.vf_err_vector (8 regs, WB) */
literal|0x012e0000
block|,
comment|/* block ysem */
literal|0x08d40108
block|,
comment|/* ysem.vf_err_vector (8 regs, WB) */
literal|0x012f0000
block|,
comment|/* block psem */
literal|0x08d80108
block|,
comment|/* psem.vf_err_vector (8 regs, WB) */
literal|0x01370000
block|,
comment|/* block prm */
literal|0x0108d800
block|,
comment|/* prm.nop_without_completion_fix_disable (1 regs) */
literal|0x043b0000
block|,
comment|/* block btb */
literal|0x0236c215
block|,
comment|/* btb.wc_no_dead_cycles_en .. btb.wc_highest_pri_en (2 regs) */
literal|0x0436c26d
block|,
comment|/* btb.rc_pkt_empty_4 .. btb.rc_pkt_empty_7 (4 regs) */
literal|0x0436c27c
block|,
comment|/* btb.rc_pkt_full_4 .. btb.rc_pkt_full_7 (4 regs) */
literal|0x0436c28b
block|,
comment|/* btb.rc_pkt_status_4 .. btb.rc_pkt_status_7 (4 regs) */
literal|0x013e0000
block|,
comment|/* block tdif */
literal|0x040c403c
block|,
comment|/* tdif.stat_num_err_interval_4 .. tdif.stat_num_err_interval_7 (4 regs) */
literal|0x01420000
block|,
comment|/* block igu */
literal|0x05060310
block|,
comment|/* igu.vf_with_more_16sb_16 .. igu.vf_with_more_16sb_20 (5 regs) */
literal|0x014a0000
block|,
comment|/* block dbg */
literal|0x01004119
block|,
comment|/* dbg.ifmux_select (1 regs) */
literal|0x094b0000
block|,
comment|/* block nig */
literal|0x02140028
block|,
comment|/* nig.INT_STS_6 .. nig.INT_MASK_6 (2 regs) */
literal|0x0214002c
block|,
comment|/* nig.INT_STS_7 .. nig.INT_MASK_7 (2 regs) */
literal|0x02140030
block|,
comment|/* nig.INT_STS_8 .. nig.INT_MASK_8 (2 regs) */
literal|0x02140034
block|,
comment|/* nig.INT_STS_9 .. nig.INT_MASK_9 (2 regs) */
literal|0x07142400
block|,
comment|/* nig.tx_tdm_0_enable .. nig.tsgen_pps_out_sel_mask_3 (7 regs) */
literal|0x01142409
block|,
comment|/* nig.tsgen_tsio_in_val (1 regs) */
literal|0x01142413
block|,
comment|/* nig.ts_for_pxp_select (1 regs) */
literal|0x02942414
block|,
comment|/* nig.ptm_time_latch (2 regs, WB) */
literal|0x0114241a
block|,
comment|/* nig.mpa_mul_pdu_crc_calc_en (1 regs) */
literal|0x034d0000
block|,
comment|/* block bmbn */
literal|0x02184010
block|,
comment|/* bmbn.INT_STS_0 .. bmbn.INT_MASK_0 (2 regs) */
literal|0x05184050
block|,
comment|/* bmbn.dbg_select .. bmbn.dbg_force_frame (5 regs) */
literal|0x0318407e
block|,
comment|/* bmbn.tag_len_0 .. bmbn.eco_reserved (3 regs) */
literal|0x644f0000
block|,
comment|/* block nwm */
literal|0x02200001
block|,
comment|/* nwm.INT_STS .. nwm.INT_MASK (2 regs) */
literal|0x3b200005
block|,
comment|/* nwm.mac0_peer_delay .. nwm.dbg_force_frame (59 regs) */
literal|0x06200100
block|,
comment|/* nwm.mac0.REVISION .. nwm.mac0.FRM_LENGTH (6 regs) */
literal|0x08200107
block|,
comment|/* nwm.mac0.RX_FIFO_SECTIONS .. nwm.mac0.MDIO_DATA (8 regs) */
literal|0x0e200110
block|,
comment|/* nwm.mac0.STATUS .. nwm.mac0.RX_PAUSE_STATUS (14 regs) */
literal|0x0220011f
block|,
comment|/* nwm.mac0.TS_TIMESTAMP .. nwm.mac0.XIF_MODE (2 regs) */
literal|0x03200138
block|,
comment|/* nwm.mac0.STATN_CONFIG .. nwm.mac0.STATN_CLEARVALUE_HI (3 regs) */
literal|0x36200140
block|,
comment|/* nwm.mac0.etherStatsOctets .. nwm.mac0.aInRangeLengthError_h (54 regs) */
literal|0x04200180
block|,
comment|/* nwm.mac0.TXetherStatsOctets .. nwm.mac0.TXOctetsOK_h (4 regs) */
literal|0x24200186
block|,
comment|/* nwm.mac0.TXaPauseMacCtrlFrames .. nwm.mac0.TXetherStatsPkts1519toTX_MTU_h (36 regs) */
literal|0x022001b0
block|,
comment|/* nwm.mac0.TXaMACControlFrames .. nwm.mac0.TXaMACControlFrames_h (2 regs) */
literal|0x262001e0
block|,
comment|/* nwm.mac0.aCBFCPAUSEFramesReceived_0 .. nwm.mac1.FRM_LENGTH (38 regs) */
literal|0x08200207
block|,
comment|/* nwm.mac1.RX_FIFO_SECTIONS .. nwm.mac1.MDIO_DATA (8 regs) */
literal|0x0e200210
block|,
comment|/* nwm.mac1.STATUS .. nwm.mac1.RX_PAUSE_STATUS (14 regs) */
literal|0x0220021f
block|,
comment|/* nwm.mac1.TS_TIMESTAMP .. nwm.mac1.XIF_MODE (2 regs) */
literal|0x03200238
block|,
comment|/* nwm.mac1.STATN_CONFIG .. nwm.mac1.STATN_CLEARVALUE_HI (3 regs) */
literal|0x36200240
block|,
comment|/* nwm.mac1.etherStatsOctets .. nwm.mac1.aInRangeLengthError_h (54 regs) */
literal|0x04200280
block|,
comment|/* nwm.mac1.TXetherStatsOctets .. nwm.mac1.TXOctetsOK_h (4 regs) */
literal|0x24200286
block|,
comment|/* nwm.mac1.TXaPauseMacCtrlFrames .. nwm.mac1.TXetherStatsPkts1519toTX_MTU_h (36 regs) */
literal|0x022002b0
block|,
comment|/* nwm.mac1.TXaMACControlFrames .. nwm.mac1.TXaMACControlFrames_h (2 regs) */
literal|0x262002e0
block|,
comment|/* nwm.mac1.aCBFCPAUSEFramesReceived_0 .. nwm.mac2.FRM_LENGTH (38 regs) */
literal|0x08200307
block|,
comment|/* nwm.mac2.RX_FIFO_SECTIONS .. nwm.mac2.MDIO_DATA (8 regs) */
literal|0x0e200310
block|,
comment|/* nwm.mac2.STATUS .. nwm.mac2.RX_PAUSE_STATUS (14 regs) */
literal|0x0220031f
block|,
comment|/* nwm.mac2.TS_TIMESTAMP .. nwm.mac2.XIF_MODE (2 regs) */
literal|0x03200338
block|,
comment|/* nwm.mac2.STATN_CONFIG .. nwm.mac2.STATN_CLEARVALUE_HI (3 regs) */
literal|0x36200340
block|,
comment|/* nwm.mac2.etherStatsOctets .. nwm.mac2.aInRangeLengthError_h (54 regs) */
literal|0x04200380
block|,
comment|/* nwm.mac2.TXetherStatsOctets .. nwm.mac2.TXOctetsOK_h (4 regs) */
literal|0x24200386
block|,
comment|/* nwm.mac2.TXaPauseMacCtrlFrames .. nwm.mac2.TXetherStatsPkts1519toTX_MTU_h (36 regs) */
literal|0x022003b0
block|,
comment|/* nwm.mac2.TXaMACControlFrames .. nwm.mac2.TXaMACControlFrames_h (2 regs) */
literal|0x262003e0
block|,
comment|/* nwm.mac2.aCBFCPAUSEFramesReceived_0 .. nwm.mac3.FRM_LENGTH (38 regs) */
literal|0x08200407
block|,
comment|/* nwm.mac3.RX_FIFO_SECTIONS .. nwm.mac3.MDIO_DATA (8 regs) */
literal|0x0e200410
block|,
comment|/* nwm.mac3.STATUS .. nwm.mac3.RX_PAUSE_STATUS (14 regs) */
literal|0x0220041f
block|,
comment|/* nwm.mac3.TS_TIMESTAMP .. nwm.mac3.XIF_MODE (2 regs) */
literal|0x03200438
block|,
comment|/* nwm.mac3.STATN_CONFIG .. nwm.mac3.STATN_CLEARVALUE_HI (3 regs) */
literal|0x36200440
block|,
comment|/* nwm.mac3.etherStatsOctets .. nwm.mac3.aInRangeLengthError_h (54 regs) */
literal|0x04200480
block|,
comment|/* nwm.mac3.TXetherStatsOctets .. nwm.mac3.TXOctetsOK_h (4 regs) */
literal|0x24200486
block|,
comment|/* nwm.mac3.TXaPauseMacCtrlFrames .. nwm.mac3.TXetherStatsPkts1519toTX_MTU_h (36 regs) */
literal|0x022004b0
block|,
comment|/* nwm.mac3.TXaMACControlFrames .. nwm.mac3.TXaMACControlFrames_h (2 regs) */
literal|0x272004e0
block|,
comment|/* nwm.mac3.aCBFCPAUSEFramesReceived_0 .. nwm.pcs_reg91_0.RS_FEC_LANEMAP (39 regs) */
literal|0x0820050a
block|,
comment|/* nwm.pcs_reg91_0.RS_FEC_SYMBLERR0_LO .. nwm.pcs_reg91_0.RS_FEC_SYMBLERR3_HI (8 regs) */
literal|0x08200580
block|,
comment|/* nwm.pcs_reg91_0.RS_FEC_VENDOR_CONTROL .. nwm.pcs_reg91_0.RS_FEC_VENDOR_TX_TESTTRIGGER (8 regs) */
literal|0x07200600
block|,
comment|/* nwm.pcs_reg91_1.RS_FEC_CONTROL .. nwm.pcs_reg91_1.RS_FEC_LANEMAP (7 regs) */
literal|0x0820060a
block|,
comment|/* nwm.pcs_reg91_1.RS_FEC_SYMBLERR0_LO .. nwm.pcs_reg91_1.RS_FEC_SYMBLERR3_HI (8 regs) */
literal|0x08200680
block|,
comment|/* nwm.pcs_reg91_1.RS_FEC_VENDOR_CONTROL .. nwm.pcs_reg91_1.RS_FEC_VENDOR_TX_TESTTRIGGER (8 regs) */
literal|0x07200700
block|,
comment|/* nwm.pcs_reg91_2.RS_FEC_CONTROL .. nwm.pcs_reg91_2.RS_FEC_LANEMAP (7 regs) */
literal|0x0820070a
block|,
comment|/* nwm.pcs_reg91_2.RS_FEC_SYMBLERR0_LO .. nwm.pcs_reg91_2.RS_FEC_SYMBLERR3_HI (8 regs) */
literal|0x08200780
block|,
comment|/* nwm.pcs_reg91_2.RS_FEC_VENDOR_CONTROL .. nwm.pcs_reg91_2.RS_FEC_VENDOR_TX_TESTTRIGGER (8 regs) */
literal|0x07200800
block|,
comment|/* nwm.pcs_reg91_3.RS_FEC_CONTROL .. nwm.pcs_reg91_3.RS_FEC_LANEMAP (7 regs) */
literal|0x0820080a
block|,
comment|/* nwm.pcs_reg91_3.RS_FEC_SYMBLERR0_LO .. nwm.pcs_reg91_3.RS_FEC_SYMBLERR3_HI (8 regs) */
literal|0x08200880
block|,
comment|/* nwm.pcs_reg91_3.RS_FEC_VENDOR_CONTROL .. nwm.pcs_reg91_3.RS_FEC_VENDOR_TX_TESTTRIGGER (8 regs) */
literal|0x09200900
block|,
comment|/* nwm.pcs_ls0.CONTROL .. nwm.pcs_ls0.LP_NP_RX (9 regs) */
literal|0x06200910
block|,
comment|/* nwm.pcs_ls0.SCRATCH .. nwm.pcs_ls0.DECODE_ERRORS (6 regs) */
literal|0x09200920
block|,
comment|/* nwm.pcs_ls1.CONTROL .. nwm.pcs_ls1.LP_NP_RX (9 regs) */
literal|0x06200930
block|,
comment|/* nwm.pcs_ls1.SCRATCH .. nwm.pcs_ls1.DECODE_ERRORS (6 regs) */
literal|0x09200940
block|,
comment|/* nwm.pcs_ls2.CONTROL .. nwm.pcs_ls2.LP_NP_RX (9 regs) */
literal|0x06200950
block|,
comment|/* nwm.pcs_ls2.SCRATCH .. nwm.pcs_ls2.DECODE_ERRORS (6 regs) */
literal|0x09200960
block|,
comment|/* nwm.pcs_ls3.CONTROL .. nwm.pcs_ls3.LP_NP_RX (9 regs) */
literal|0x06200970
block|,
comment|/* nwm.pcs_ls3.SCRATCH .. nwm.pcs_ls3.DECODE_ERRORS (6 regs) */
literal|0x09210000
block|,
comment|/* nwm.pcs_hs0.CONTROL1 .. nwm.pcs_hs0.STATUS2 (9 regs) */
literal|0x0221000e
block|,
comment|/* nwm.pcs_hs0.PKG_ID0 .. nwm.pcs_hs0.PKG_ID1 (2 regs) */
literal|0x01210014
block|,
comment|/* nwm.pcs_hs0.EEE_CTRL_CAPABILITY (1 regs) */
literal|0x01210016
block|,
comment|/* nwm.pcs_hs0.WAKE_ERR_COUNTER (1 regs) */
literal|0x0e210020
block|,
comment|/* nwm.pcs_hs0.BASER_STATUS1 .. nwm.pcs_hs0.ERR_BLK_HIGH_ORDER_CNT (14 regs) */
literal|0x01210032
block|,
comment|/* nwm.pcs_hs0.MULTILANE_ALIGN_STAT1 (1 regs) */
literal|0x01210034
block|,
comment|/* nwm.pcs_hs0.MULTILANE_ALIGN_STAT3 (1 regs) */
literal|0x042100c8
block|,
comment|/* nwm.pcs_hs0.BIP_ERR_CNT_LANE0 .. nwm.pcs_hs0.BIP_ERR_CNT_LANE3 (4 regs) */
literal|0x04210190
block|,
comment|/* nwm.pcs_hs0.LANE0_MAPPING .. nwm.pcs_hs0.LANE3_MAPPING (4 regs) */
literal|0x05218000
block|,
comment|/* nwm.pcs_hs0.VENDOR_SCRATCH .. nwm.pcs_hs0.VENDOR_RXLAUI_CONFIG (5 regs) */
literal|0x09218008
block|,
comment|/* nwm.pcs_hs0.VENDOR_VL0_0 .. nwm.pcs_hs0.VENDOR_PCS_MODE (9 regs) */
literal|0x09220000
block|,
comment|/* nwm.pcs_hs1.CONTROL1 .. nwm.pcs_hs1.STATUS2 (9 regs) */
literal|0x0222000e
block|,
comment|/* nwm.pcs_hs1.PKG_ID0 .. nwm.pcs_hs1.PKG_ID1 (2 regs) */
literal|0x01220014
block|,
comment|/* nwm.pcs_hs1.EEE_CTRL_CAPABILITY (1 regs) */
literal|0x01220016
block|,
comment|/* nwm.pcs_hs1.WAKE_ERR_COUNTER (1 regs) */
literal|0x0e220020
block|,
comment|/* nwm.pcs_hs1.BASER_STATUS1 .. nwm.pcs_hs1.ERR_BLK_HIGH_ORDER_CNT (14 regs) */
literal|0x01220032
block|,
comment|/* nwm.pcs_hs1.MULTILANE_ALIGN_STAT1 (1 regs) */
literal|0x01220034
block|,
comment|/* nwm.pcs_hs1.MULTILANE_ALIGN_STAT3 (1 regs) */
literal|0x042200c8
block|,
comment|/* nwm.pcs_hs1.BIP_ERR_CNT_LANE0 .. nwm.pcs_hs1.BIP_ERR_CNT_LANE3 (4 regs) */
literal|0x04220190
block|,
comment|/* nwm.pcs_hs1.LANE0_MAPPING .. nwm.pcs_hs1.LANE3_MAPPING (4 regs) */
literal|0x05228000
block|,
comment|/* nwm.pcs_hs1.VENDOR_SCRATCH .. nwm.pcs_hs1.VENDOR_RXLAUI_CONFIG (5 regs) */
literal|0x09228008
block|,
comment|/* nwm.pcs_hs1.VENDOR_VL0_0 .. nwm.pcs_hs1.VENDOR_PCS_MODE (9 regs) */
literal|0x09230000
block|,
comment|/* nwm.pcs_hs2.CONTROL1 .. nwm.pcs_hs2.STATUS2 (9 regs) */
literal|0x0223000e
block|,
comment|/* nwm.pcs_hs2.PKG_ID0 .. nwm.pcs_hs2.PKG_ID1 (2 regs) */
literal|0x01230014
block|,
comment|/* nwm.pcs_hs2.EEE_CTRL_CAPABILITY (1 regs) */
literal|0x01230016
block|,
comment|/* nwm.pcs_hs2.WAKE_ERR_COUNTER (1 regs) */
literal|0x0e230020
block|,
comment|/* nwm.pcs_hs2.BASER_STATUS1 .. nwm.pcs_hs2.ERR_BLK_HIGH_ORDER_CNT (14 regs) */
literal|0x01230032
block|,
comment|/* nwm.pcs_hs2.MULTILANE_ALIGN_STAT1 (1 regs) */
literal|0x01230034
block|,
comment|/* nwm.pcs_hs2.MULTILANE_ALIGN_STAT3 (1 regs) */
literal|0x042300c8
block|,
comment|/* nwm.pcs_hs2.BIP_ERR_CNT_LANE0 .. nwm.pcs_hs2.BIP_ERR_CNT_LANE3 (4 regs) */
literal|0x04238000
block|,
comment|/* nwm.pcs_hs2.VENDOR_SCRATCH .. nwm.pcs_hs2.VENDOR_TXLANE_THRESH (4 regs) */
literal|0x09238008
block|,
comment|/* nwm.pcs_hs2.VENDOR_VL0_0 .. nwm.pcs_hs2.VENDOR_PCS_MODE (9 regs) */
literal|0x09240000
block|,
comment|/* nwm.pcs_hs3.CONTROL1 .. nwm.pcs_hs3.STATUS2 (9 regs) */
literal|0x0224000e
block|,
comment|/* nwm.pcs_hs3.PKG_ID0 .. nwm.pcs_hs3.PKG_ID1 (2 regs) */
literal|0x01240014
block|,
comment|/* nwm.pcs_hs3.EEE_CTRL_CAPABILITY (1 regs) */
literal|0x01240016
block|,
comment|/* nwm.pcs_hs3.WAKE_ERR_COUNTER (1 regs) */
literal|0x0e240020
block|,
comment|/* nwm.pcs_hs3.BASER_STATUS1 .. nwm.pcs_hs3.ERR_BLK_HIGH_ORDER_CNT (14 regs) */
literal|0x01240032
block|,
comment|/* nwm.pcs_hs3.MULTILANE_ALIGN_STAT1 (1 regs) */
literal|0x01240034
block|,
comment|/* nwm.pcs_hs3.MULTILANE_ALIGN_STAT3 (1 regs) */
literal|0x042400c8
block|,
comment|/* nwm.pcs_hs3.BIP_ERR_CNT_LANE0 .. nwm.pcs_hs3.BIP_ERR_CNT_LANE3 (4 regs) */
literal|0x04248000
block|,
comment|/* nwm.pcs_hs3.VENDOR_SCRATCH .. nwm.pcs_hs3.VENDOR_TXLANE_THRESH (4 regs) */
literal|0x09248008
block|,
comment|/* nwm.pcs_hs3.VENDOR_VL0_0 .. nwm.pcs_hs3.VENDOR_PCS_MODE (9 regs) */
literal|0x06500000
block|,
comment|/* block nws */
literal|0x171c0000
block|,
comment|/* nws.common_control .. nws.eco_reserved (23 regs) */
literal|0x0b1c004a
block|,
comment|/* nws.dbg_select .. nws.dbg_fw_trigger_enable (11 regs) */
literal|0x021c0060
block|,
comment|/* nws.INT_STS_0 .. nws.INT_MASK_0 (2 regs) */
literal|0x021c0064
block|,
comment|/* nws.INT_STS_1 .. nws.INT_MASK_1 (2 regs) */
literal|0x021c0068
block|,
comment|/* nws.INT_STS_2 .. nws.INT_MASK_2 (2 regs) */
literal|0x021c006c
block|,
comment|/* nws.INT_STS_3 .. nws.INT_MASK_3 (2 regs) */
literal|0x02530000
block|,
comment|/* block led */
literal|0x061ae006
block|,
comment|/* led.mac_led_swap .. led.eco_reserved (6 regs) */
literal|0x021ae060
block|,
comment|/* led.INT_STS_0 .. led.INT_MASK_0 (2 regs) */
literal|0x01040003
block|,
comment|/* mode !(bb|k2), block pglue_b */
literal|0x020aa13a
block|,
comment|/* pglue_b.dorq_access_via_bar0 .. pglue_b.vsc_en (2 regs) */
literal|0x010d0000
block|,
comment|/* block pswhst */
literal|0x010a8031
block|,
comment|/* pswhst.dest_dorq_credits (1 regs) */
literal|0x01110000
block|,
comment|/* block pswwr */
literal|0x030a6833
block|,
comment|/* pswwr.prms_full_th .. pswwr.tgsrc_full_th (3 regs) */
literal|0x01120000
block|,
comment|/* block pswwr2 */
literal|0x030a6c1a
block|,
comment|/* pswwr2.prms_full_th2 .. pswwr2.prms_max_fill_level (3 regs) */
literal|0x01160000
block|,
comment|/* block dmae */
literal|0x01003032
block|,
comment|/* dmae.go_sticky (1 regs) */
literal|0x01170000
block|,
comment|/* block ptu */
literal|0x0515817b
block|,
comment|/* ptu.LOG_INV_HALT_RSC_TYPE .. ptu.index2_rsc_type_mask (5 regs) */
literal|0x0c180000
block|,
comment|/* block tcm */
literal|0x2c460022
block|,
comment|/* tcm.affinity_type_0 .. tcm.agg_con_cf11_q (44 regs) */
literal|0x0b46015a
block|,
comment|/* tcm.agg_con_rule0_q .. tcm.agg_con_rule10_q (11 regs) */
literal|0x014601a2
block|,
comment|/* tcm.ext_rd_fill_lvl (1 regs) */
literal|0x134601e9
block|,
comment|/* tcm.err_affinity_type .. tcm.xx_byp_msg_up_bnd_15 (19 regs) */
literal|0x08460267
block|,
comment|/* tcm.cm_task_event_id_bwidth_0 .. tcm.cm_task_event_id_bwidth_7 (8 regs) */
literal|0x1046028e
block|,
comment|/* tcm.cm_con_event_id_bwidth_0 .. tcm.cm_con_event_id_bwidth_15 (16 regs) */
literal|0x85460640
block|,
comment|/* tcm.tm_con_evnt_id_0 .. tcm.is_foc_tsdm_nxt_inf_unit (133 regs) */
literal|0x054606e0
block|,
comment|/* tcm.psdm_weight .. tcm.is_foc_psdm_nxt_inf_unit (5 regs) */
literal|0x05460700
block|,
comment|/* tcm.msdm_weight .. tcm.is_foc_msdm_nxt_inf_unit (5 regs) */
literal|0x04460720
block|,
comment|/* tcm.ysem_weight .. tcm.is_foc_ysem_nxt_inf_unit (4 regs) */
literal|0x05460780
block|,
comment|/* tcm.ptld_weight .. tcm.is_foc_ptld_nxt_inf_unit (5 regs) */
literal|0x08460a00
block|,
comment|/* tcm.agg_task_cf0_q .. tcm.agg_task_cf7_q (8 regs) */
literal|0x0c190000
block|,
comment|/* block mcm */
literal|0x23480022
block|,
comment|/* mcm.affinity_type_0 .. mcm.agg_con_cf2_q (35 regs) */
literal|0x0548015a
block|,
comment|/* mcm.agg_con_rule0_q .. mcm.agg_con_rule4_q (5 regs) */
literal|0x014801a4
block|,
comment|/* mcm.ext_rd_fill_lvl (1 regs) */
literal|0x134801e9
block|,
comment|/* mcm.err_affinity_type .. mcm.xx_byp_msg_up_bnd_15 (19 regs) */
literal|0x09480257
block|,
comment|/* mcm.agg_task_rule7_q .. mcm.cm_task_event_id_bwidth_7 (9 regs) */
literal|0x1048028c
block|,
comment|/* mcm.cm_con_event_id_bwidth_0 .. mcm.cm_con_event_id_bwidth_15 (16 regs) */
literal|0x70480740
block|,
comment|/* mcm.n_sm_con_ctx_ld_0 .. mcm.qm_sm_con_ctx_ldst_flg_15 (112 regs) */
literal|0x05480a00
block|,
comment|/* mcm.tsdm_weight .. mcm.is_foc_tsdm_nxt_inf_unit (5 regs) */
literal|0x05480a20
block|,
comment|/* mcm.psdm_weight .. mcm.is_foc_psdm_nxt_inf_unit (5 regs) */
literal|0x05480a40
block|,
comment|/* mcm.msdm_weight .. mcm.is_foc_msdm_nxt_inf_unit (5 regs) */
literal|0x04480a80
block|,
comment|/* mcm.ysem_weight .. mcm.is_foc_ysem_nxt_inf_unit (4 regs) */
literal|0x05480b80
block|,
comment|/* mcm.agg_task_cf0_q .. mcm.agg_task_cf4_q (5 regs) */
literal|0x091a0000
block|,
comment|/* block ucm */
literal|0x294a002a
block|,
comment|/* ucm.affinity_type_0 .. ucm.agg_con_cf8_q (41 regs) */
literal|0x094a015a
block|,
comment|/* ucm.agg_con_rule0_q .. ucm.agg_con_rule8_q (9 regs) */
literal|0x014a01aa
block|,
comment|/* ucm.ext_rd_fill_lvl (1 regs) */
literal|0x134a01e9
block|,
comment|/* ucm.err_affinity_type .. ucm.xx_byp_msg_up_bnd_15 (19 regs) */
literal|0x0a4a0261
block|,
comment|/* ucm.agg_task_rule7_q .. ucm.cm_task_event_id_bwidth_7 (10 regs) */
literal|0x104a028e
block|,
comment|/* ucm.cm_con_event_id_bwidth_0 .. ucm.cm_con_event_id_bwidth_15 (16 regs) */
literal|0x804a0700
block|,
comment|/* ucm.tm_con_evnt_id_0 .. ucm.qm_sm_con_ctx_ldst_flg_15 (128 regs) */
literal|0x064a0a00
block|,
comment|/* ucm.ring_base .. ucm.is_foc_ysem_nxt_inf_unit (6 regs) */
literal|0x064a0a80
block|,
comment|/* ucm.agg_task_cf0_q .. ucm.agg_task_cf5_q (6 regs) */
literal|0x071b0000
block|,
comment|/* block xcm */
literal|0x39400022
block|,
comment|/* xcm.affinity_type_0 .. xcm.agg_con_cf24_q (57 regs) */
literal|0x1c400132
block|,
comment|/* xcm.agg_con_rule0_q .. xcm.agg_con_rule27_q (28 regs) */
literal|0x014001a6
block|,
comment|/* xcm.ext_rd_fill_lvl (1 regs) */
literal|0x134001e6
block|,
comment|/* xcm.err_affinity_type .. xcm.xx_byp_msg_up_bnd_15 (19 regs) */
literal|0x1040028a
block|,
comment|/* xcm.cm_con_event_id_bwidth_0 .. xcm.cm_con_event_id_bwidth_15 (16 regs) */
literal|0x95400700
block|,
comment|/* xcm.tm_con_evnt_id_0 .. xcm.is_foc_msdm_nxt_inf_unit (149 regs) */
literal|0x044007c0
block|,
comment|/* xcm.ysem_weight .. xcm.is_foc_ysem_nxt_inf_unit (4 regs) */
literal|0x091c0000
block|,
comment|/* block ycm */
literal|0x23420022
block|,
comment|/* ycm.affinity_type_0 .. ycm.agg_con_cf2_q (35 regs) */
literal|0x0542015a
block|,
comment|/* ycm.agg_con_rule0_q .. ycm.agg_con_rule4_q (5 regs) */
literal|0x014201a2
block|,
comment|/* ycm.ext_rd_fill_lvl (1 regs) */
literal|0x134201e9
block|,
comment|/* ycm.err_affinity_type .. ycm.xx_byp_msg_up_bnd_15 (19 regs) */
literal|0x10420251
block|,
comment|/* ycm.agg_task_rule0_q .. ycm.cm_task_event_id_bwidth_7 (16 regs) */
literal|0x1042028c
block|,
comment|/* ycm.cm_con_event_id_bwidth_0 .. ycm.cm_con_event_id_bwidth_15 (16 regs) */
literal|0x75420740
block|,
comment|/* ycm.n_sm_con_ctx_ld_0 .. ycm.is_foc_msdm_nxt_inf_unit (117 regs) */
literal|0x01420900
block|,
comment|/* ycm.is_foc_ysem_nxt_inf_unit (1 regs) */
literal|0x04420b00
block|,
comment|/* ycm.agg_task_cf0_q .. ycm.agg_task_cf4_q (4 regs) */
literal|0x041d0000
block|,
comment|/* block pcm */
literal|0x01440194
block|,
comment|/* pcm.ext_rd_fill_lvl (1 regs) */
literal|0x034401d9
block|,
comment|/* pcm.err_affinity_type .. pcm.err_src_affinity (3 regs) */
literal|0x154405c4
block|,
comment|/* pcm.n_sm_con_ctx_ld_0 .. pcm.is_foc_psdm_nxt_inf_unit (21 regs) */
literal|0x054405f0
block|,
comment|/* pcm.ypld_weight .. pcm.is_foc_ypld_nxt_inf_unit (5 regs) */
literal|0x031e0000
block|,
comment|/* block qm */
literal|0x080bd733
block|,
comment|/* qm.Voq_Arb_Grp2_Weight_0 .. qm.Voq_Arb_Grp2_Weight_7 (8 regs) */
literal|0xa00bda00
block|,
comment|/* qm.CtxRegCcfc_0 .. qm.ActCtrInitValCcfc_79 (160 regs) */
literal|0x040bff80
block|,
comment|/* qm.AFullQmBypThrLineVoqMask_msb .. qm.VoqCrdByteFull_msb (4 regs) */
literal|0x08200000
block|,
comment|/* block dorq */
literal|0x010402ab
block|,
comment|/* dorq.iedpm_payload_endianity (1 regs) */
literal|0x04040a00
block|,
comment|/* dorq.glb_max_icid_0 .. dorq.glb_range2conn_type_1 (4 regs) */
literal|0x02040a14
block|,
comment|/* dorq.iedpm_exist_in_qm_en .. dorq.iedpm_agg_type (2 regs) */
literal|0xc3040a1a
block|,
comment|/* dorq.edpm_agg_type_sel_0 .. dorq.rtc_en (195 regs) */
literal|0x02040adf
block|,
comment|/* dorq.crc32c_bswap .. dorq.iwarp_opcode_en (2 regs) */
literal|0x0c040ae9
block|,
comment|/* dorq.rdma_en_pbf_spc_roce .. dorq.iedpm_abort_details_reason (12 regs) */
literal|0x06040af6
block|,
comment|/* dorq.iedpm_abort_reason .. dorq.iedpm_drop_details_db_icid (6 regs) */
literal|0x41040afd
block|,
comment|/* dorq.iedpm_drop_reason .. dorq.dpm_iedpm_success_cnt (65 regs) */
literal|0x01210000
block|,
comment|/* block brb */
literal|0x090d1000
block|,
comment|/* brb.wc_ll_high_pri .. brb.limit_oversubscrition_pause_lb (9 regs) */
literal|0x0b230000
block|,
comment|/* block prs */
literal|0x0307c2ec
block|,
comment|/* prs.fc_dbg_select_a .. prs.fc_dbg_shift_a (3 regs) */
literal|0x0887c2f0
block|,
comment|/* prs.fc_dbg_out_data_a (8 regs, WB) */
literal|0x0407c2f8
block|,
comment|/* prs.fc_dbg_force_valid_a .. prs.fc_dbg_out_frame_a (4 regs) */
literal|0x0307c380
block|,
comment|/* prs.fc_dbg_select_b .. prs.fc_dbg_shift_b (3 regs) */
literal|0x0887c388
block|,
comment|/* prs.fc_dbg_out_data_b (8 regs, WB) */
literal|0x0407c390
block|,
comment|/* prs.fc_dbg_force_valid_b .. prs.fc_dbg_out_frame_b (4 regs) */
literal|0x0107c3c0
block|,
comment|/* prs.ptld_initial_credit (1 regs) */
literal|0x0107c3c3
block|,
comment|/* prs.ptld_current_credit (1 regs) */
literal|0x0707c3ce
block|,
comment|/* prs.rgfs_initial_credit .. prs.fce_use_single_fc_chicken_bit (7 regs) */
literal|0xb907c500
block|,
comment|/* prs.compare_gre_version .. prs.xrc_opcodes (185 regs) */
literal|0x0407c5ba
block|,
comment|/* prs.new_entry_exclusive_classify_failed .. prs.en_ipv6_ext_event_id (4 regs) */
literal|0x01240000
block|,
comment|/* block tsdm */
literal|0x013ec148
block|,
comment|/* tsdm.init_credit_cm_rmt (1 regs) */
literal|0x112a0000
block|,
comment|/* block tsem */
literal|0x085c0005
block|,
comment|/* tsem.passive_buffer_write_wrr_arbiter .. tsem.passive_buffer_dra_wr (8 regs) */
literal|0x025c0018
block|,
comment|/* tsem.INT_STS_2 .. tsem.INT_MASK_2 (2 regs) */
literal|0x015c0114
block|,
comment|/* tsem.gpi_data_a (1 regs) */
literal|0x035c0118
block|,
comment|/* tsem.pb_wr_sdm_dma_mode .. tsem.gpi_data_b (3 regs) */
literal|0x015c02c1
block|,
comment|/* tsem.thread_error_low (1 regs) */
literal|0x025c02c6
block|,
comment|/* tsem.thread_number .. tsem.thread_error_high (2 regs) */
literal|0x095c0404
block|,
comment|/* tsem.sync_foc_fifo_wr_alm_full .. tsem.stall_on_breakpoint (9 regs) */
literal|0x055c045b
block|,
comment|/* tsem.pb_queue_empty .. tsem.ext_store_pre_fetch_fifo_empty (5 regs) */
literal|0x035c049f
block|,
comment|/* tsem.sync_ready_fifo_full .. tsem.sync_foc_fifo_full (3 regs) */
literal|0x105c050a
block|,
comment|/* tsem.dbg_queue_peformance_mon_stat .. tsem.dbg_queue_max_sleep_value (16 regs) */
literal|0x015d0122
block|,
comment|/* tsem.fast_memory.stall_common (1 regs) */
literal|0x015d0132
block|,
comment|/* tsem.fast_memory.pram_last_addr_a (1 regs) */
literal|0x075d0136
block|,
comment|/* tsem.fast_memory.data_breakpoint_address_start .. tsem.fast_memory.stall_storm_b (7 regs) */
literal|0x015d01dd
block|,
comment|/* tsem.fast_memory.dbg_gpre_vect (1 regs) */
literal|0x015d0214
block|,
comment|/* tsem.fast_memory.sync_dra_wr_alm_full (1 regs) */
literal|0x015d0291
block|,
comment|/* tsem.fast_memory.storm_active_cycles_a (1 regs) */
literal|0x085d0293
block|,
comment|/* tsem.fast_memory.storm_stall_cycles_a .. tsem.fast_memory.lock_max_cycle_stall (8 regs) */
literal|0x112b0000
block|,
comment|/* block msem */
literal|0x08600005
block|,
comment|/* msem.passive_buffer_write_wrr_arbiter .. msem.passive_buffer_dra_wr (8 regs) */
literal|0x02600018
block|,
comment|/* msem.INT_STS_2 .. msem.INT_MASK_2 (2 regs) */
literal|0x01600114
block|,
comment|/* msem.gpi_data_a (1 regs) */
literal|0x03600118
block|,
comment|/* msem.pb_wr_sdm_dma_mode .. msem.gpi_data_b (3 regs) */
literal|0x016002c1
block|,
comment|/* msem.thread_error_low (1 regs) */
literal|0x026002c6
block|,
comment|/* msem.thread_number .. msem.thread_error_high (2 regs) */
literal|0x09600404
block|,
comment|/* msem.sync_foc_fifo_wr_alm_full .. msem.stall_on_breakpoint (9 regs) */
literal|0x0560045b
block|,
comment|/* msem.pb_queue_empty .. msem.ext_store_pre_fetch_fifo_empty (5 regs) */
literal|0x0360049f
block|,
comment|/* msem.sync_ready_fifo_full .. msem.sync_foc_fifo_full (3 regs) */
literal|0x1060050a
block|,
comment|/* msem.dbg_queue_peformance_mon_stat .. msem.dbg_queue_max_sleep_value (16 regs) */
literal|0x01610122
block|,
comment|/* msem.fast_memory.stall_common (1 regs) */
literal|0x01610132
block|,
comment|/* msem.fast_memory.pram_last_addr_a (1 regs) */
literal|0x07610136
block|,
comment|/* msem.fast_memory.data_breakpoint_address_start .. msem.fast_memory.stall_storm_b (7 regs) */
literal|0x016101dd
block|,
comment|/* msem.fast_memory.dbg_gpre_vect (1 regs) */
literal|0x01610214
block|,
comment|/* msem.fast_memory.sync_dra_wr_alm_full (1 regs) */
literal|0x01610291
block|,
comment|/* msem.fast_memory.storm_active_cycles_a (1 regs) */
literal|0x08610293
block|,
comment|/* msem.fast_memory.storm_stall_cycles_a .. msem.fast_memory.lock_max_cycle_stall (8 regs) */
literal|0x112c0000
block|,
comment|/* block usem */
literal|0x08640005
block|,
comment|/* usem.passive_buffer_write_wrr_arbiter .. usem.passive_buffer_dra_wr (8 regs) */
literal|0x02640018
block|,
comment|/* usem.INT_STS_2 .. usem.INT_MASK_2 (2 regs) */
literal|0x01640114
block|,
comment|/* usem.gpi_data_a (1 regs) */
literal|0x03640118
block|,
comment|/* usem.pb_wr_sdm_dma_mode .. usem.gpi_data_b (3 regs) */
literal|0x016402c1
block|,
comment|/* usem.thread_error_low (1 regs) */
literal|0x026402c6
block|,
comment|/* usem.thread_number .. usem.thread_error_high (2 regs) */
literal|0x09640404
block|,
comment|/* usem.sync_foc_fifo_wr_alm_full .. usem.stall_on_breakpoint (9 regs) */
literal|0x0564045b
block|,
comment|/* usem.pb_queue_empty .. usem.ext_store_pre_fetch_fifo_empty (5 regs) */
literal|0x0364049f
block|,
comment|/* usem.sync_ready_fifo_full .. usem.sync_foc_fifo_full (3 regs) */
literal|0x1064050a
block|,
comment|/* usem.dbg_queue_peformance_mon_stat .. usem.dbg_queue_max_sleep_value (16 regs) */
literal|0x01650122
block|,
comment|/* usem.fast_memory.stall_common (1 regs) */
literal|0x01650132
block|,
comment|/* usem.fast_memory.pram_last_addr_a (1 regs) */
literal|0x07650136
block|,
comment|/* usem.fast_memory.data_breakpoint_address_start .. usem.fast_memory.stall_storm_b (7 regs) */
literal|0x016501dd
block|,
comment|/* usem.fast_memory.dbg_gpre_vect (1 regs) */
literal|0x01650214
block|,
comment|/* usem.fast_memory.sync_dra_wr_alm_full (1 regs) */
literal|0x01650291
block|,
comment|/* usem.fast_memory.storm_active_cycles_a (1 regs) */
literal|0x08650293
block|,
comment|/* usem.fast_memory.storm_stall_cycles_a .. usem.fast_memory.lock_max_cycle_stall (8 regs) */
literal|0x112d0000
block|,
comment|/* block xsem */
literal|0x08500005
block|,
comment|/* xsem.passive_buffer_write_wrr_arbiter .. xsem.passive_buffer_dra_wr (8 regs) */
literal|0x02500018
block|,
comment|/* xsem.INT_STS_2 .. xsem.INT_MASK_2 (2 regs) */
literal|0x01500114
block|,
comment|/* xsem.gpi_data_a (1 regs) */
literal|0x03500118
block|,
comment|/* xsem.pb_wr_sdm_dma_mode .. xsem.gpi_data_b (3 regs) */
literal|0x015002c1
block|,
comment|/* xsem.thread_error_low (1 regs) */
literal|0x025002c6
block|,
comment|/* xsem.thread_number .. xsem.thread_error_high (2 regs) */
literal|0x09500404
block|,
comment|/* xsem.sync_foc_fifo_wr_alm_full .. xsem.stall_on_breakpoint (9 regs) */
literal|0x0550045b
block|,
comment|/* xsem.pb_queue_empty .. xsem.ext_store_pre_fetch_fifo_empty (5 regs) */
literal|0x0350049f
block|,
comment|/* xsem.sync_ready_fifo_full .. xsem.sync_foc_fifo_full (3 regs) */
literal|0x1050050a
block|,
comment|/* xsem.dbg_queue_peformance_mon_stat .. xsem.dbg_queue_max_sleep_value (16 regs) */
literal|0x01510122
block|,
comment|/* xsem.fast_memory.stall_common (1 regs) */
literal|0x01510132
block|,
comment|/* xsem.fast_memory.pram_last_addr_a (1 regs) */
literal|0x07510136
block|,
comment|/* xsem.fast_memory.data_breakpoint_address_start .. xsem.fast_memory.stall_storm_b (7 regs) */
literal|0x015101dd
block|,
comment|/* xsem.fast_memory.dbg_gpre_vect (1 regs) */
literal|0x01510214
block|,
comment|/* xsem.fast_memory.sync_dra_wr_alm_full (1 regs) */
literal|0x01510291
block|,
comment|/* xsem.fast_memory.storm_active_cycles_a (1 regs) */
literal|0x08510293
block|,
comment|/* xsem.fast_memory.storm_stall_cycles_a .. xsem.fast_memory.lock_max_cycle_stall (8 regs) */
literal|0x112e0000
block|,
comment|/* block ysem */
literal|0x08540005
block|,
comment|/* ysem.passive_buffer_write_wrr_arbiter .. ysem.passive_buffer_dra_wr (8 regs) */
literal|0x02540018
block|,
comment|/* ysem.INT_STS_2 .. ysem.INT_MASK_2 (2 regs) */
literal|0x01540114
block|,
comment|/* ysem.gpi_data_a (1 regs) */
literal|0x03540118
block|,
comment|/* ysem.pb_wr_sdm_dma_mode .. ysem.gpi_data_b (3 regs) */
literal|0x015402c1
block|,
comment|/* ysem.thread_error_low (1 regs) */
literal|0x025402c6
block|,
comment|/* ysem.thread_number .. ysem.thread_error_high (2 regs) */
literal|0x09540404
block|,
comment|/* ysem.sync_foc_fifo_wr_alm_full .. ysem.stall_on_breakpoint (9 regs) */
literal|0x0554045b
block|,
comment|/* ysem.pb_queue_empty .. ysem.ext_store_pre_fetch_fifo_empty (5 regs) */
literal|0x0354049f
block|,
comment|/* ysem.sync_ready_fifo_full .. ysem.sync_foc_fifo_full (3 regs) */
literal|0x1054050a
block|,
comment|/* ysem.dbg_queue_peformance_mon_stat .. ysem.dbg_queue_max_sleep_value (16 regs) */
literal|0x01550122
block|,
comment|/* ysem.fast_memory.stall_common (1 regs) */
literal|0x01550132
block|,
comment|/* ysem.fast_memory.pram_last_addr_a (1 regs) */
literal|0x07550136
block|,
comment|/* ysem.fast_memory.data_breakpoint_address_start .. ysem.fast_memory.stall_storm_b (7 regs) */
literal|0x015501dd
block|,
comment|/* ysem.fast_memory.dbg_gpre_vect (1 regs) */
literal|0x01550214
block|,
comment|/* ysem.fast_memory.sync_dra_wr_alm_full (1 regs) */
literal|0x01550291
block|,
comment|/* ysem.fast_memory.storm_active_cycles_a (1 regs) */
literal|0x08550293
block|,
comment|/* ysem.fast_memory.storm_stall_cycles_a .. ysem.fast_memory.lock_max_cycle_stall (8 regs) */
literal|0x112f0000
block|,
comment|/* block psem */
literal|0x08580005
block|,
comment|/* psem.passive_buffer_write_wrr_arbiter .. psem.passive_buffer_dra_wr (8 regs) */
literal|0x02580018
block|,
comment|/* psem.INT_STS_2 .. psem.INT_MASK_2 (2 regs) */
literal|0x01580114
block|,
comment|/* psem.gpi_data_a (1 regs) */
literal|0x03580118
block|,
comment|/* psem.pb_wr_sdm_dma_mode .. psem.gpi_data_b (3 regs) */
literal|0x015802c1
block|,
comment|/* psem.thread_error_low (1 regs) */
literal|0x025802c6
block|,
comment|/* psem.thread_number .. psem.thread_error_high (2 regs) */
literal|0x09580404
block|,
comment|/* psem.sync_foc_fifo_wr_alm_full .. psem.stall_on_breakpoint (9 regs) */
literal|0x0558045b
block|,
comment|/* psem.pb_queue_empty .. psem.ext_store_pre_fetch_fifo_empty (5 regs) */
literal|0x0358049f
block|,
comment|/* psem.sync_ready_fifo_full .. psem.sync_foc_fifo_full (3 regs) */
literal|0x1058050a
block|,
comment|/* psem.dbg_queue_peformance_mon_stat .. psem.dbg_queue_max_sleep_value (16 regs) */
literal|0x01590122
block|,
comment|/* psem.fast_memory.stall_common (1 regs) */
literal|0x01590132
block|,
comment|/* psem.fast_memory.pram_last_addr_a (1 regs) */
literal|0x07590136
block|,
comment|/* psem.fast_memory.data_breakpoint_address_start .. psem.fast_memory.stall_storm_b (7 regs) */
literal|0x015901dd
block|,
comment|/* psem.fast_memory.dbg_gpre_vect (1 regs) */
literal|0x01590214
block|,
comment|/* psem.fast_memory.sync_dra_wr_alm_full (1 regs) */
literal|0x01590291
block|,
comment|/* psem.fast_memory.storm_active_cycles_a (1 regs) */
literal|0x08590293
block|,
comment|/* psem.fast_memory.storm_stall_cycles_a .. psem.fast_memory.lock_max_cycle_stall (8 regs) */
literal|0x01300000
block|,
comment|/* block rss */
literal|0x0408e326
block|,
comment|/* rss.fifo_full_status1 .. rss.state_machines1 (4 regs) */
literal|0x01310000
block|,
comment|/* block tmld */
literal|0x3a134240
block|,
comment|/* tmld.l2ma_aggr_config1 .. tmld.scbd_wrr_weight_q3 (58 regs) */
literal|0x01320000
block|,
comment|/* block muld */
literal|0x37138500
block|,
comment|/* muld.l2ma_aggr_config1 .. muld.page_size (55 regs) */
literal|0x01340000
block|,
comment|/* block xyld */
literal|0x3a130240
block|,
comment|/* xyld.l2ma_aggr_config1 .. xyld.scbd_wrr_weight_q3 (58 regs) */
literal|0x06350000
block|,
comment|/* block ptld */
literal|0x10168000
block|,
comment|/* ptld.foci_foc_credits .. ptld.cm_hdr_127_96 (16 regs) */
literal|0x03168011
block|,
comment|/* ptld.stat_fic_msg .. ptld.len_err_log_2 (3 regs) */
literal|0x01168015
block|,
comment|/* ptld.len_err_log_v (1 regs) */
literal|0x02168060
block|,
comment|/* ptld.INT_STS .. ptld.INT_MASK (2 regs) */
literal|0x36168300
block|,
comment|/* ptld.l2ma_aggr_config1 .. ptld.ld_max_msg_size (54 regs) */
literal|0x05168580
block|,
comment|/* ptld.dbg_select .. ptld.dbg_force_frame (5 regs) */
literal|0x06360000
block|,
comment|/* block ypld */
literal|0x10170000
block|,
comment|/* ypld.foci_foc_credits .. ypld.cm_hdr_127_96 (16 regs) */
literal|0x03170011
block|,
comment|/* ypld.stat_fic_msg .. ypld.len_err_log_2 (3 regs) */
literal|0x01170015
block|,
comment|/* ypld.len_err_log_v (1 regs) */
literal|0x02170060
block|,
comment|/* ypld.INT_STS .. ypld.INT_MASK (2 regs) */
literal|0x36170300
block|,
comment|/* ypld.l2ma_aggr_config1 .. ypld.ld_max_msg_size (54 regs) */
literal|0x05170580
block|,
comment|/* ypld.dbg_select .. ypld.dbg_force_frame (5 regs) */
literal|0x01370000
block|,
comment|/* block prm */
literal|0x1308c182
block|,
comment|/* prm.num_of_wdone .. prm.num_of_xcm_done (19 regs) */
literal|0x013b0000
block|,
comment|/* block btb */
literal|0x0236d000
block|,
comment|/* btb.wc_ll_high_pri .. btb.br_fix_high_pri_collision (2 regs) */
literal|0x163c0000
block|,
comment|/* block pbf */
literal|0x03360002
block|,
comment|/* pbf.sal_cache_init_done .. pbf.sal_cam_scrub_miss_en (3 regs) */
literal|0x0236010c
block|,
comment|/* pbf.tgfs_main_if_init_crd .. pbf.tgfs_side_if_init_crd (2 regs) */
literal|0x0836014a
block|,
comment|/* pbf.same_as_last_config .. pbf.num_lookups_in_sal (8 regs) */
literal|0x0236016a
block|,
comment|/* pbf.event_id_mask_config .. pbf.event_id_l2_tags_exist_mask_config (2 regs) */
literal|0x0136019d
block|,
comment|/* pbf.per_voq_stat_mask_loopback (1 regs) */
literal|0x0c3602e8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq20 .. pbf.num_blocks_allocated_cons_voq20 (12 regs) */
literal|0x0c3602f8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq21 .. pbf.num_blocks_allocated_cons_voq21 (12 regs) */
literal|0x0c360308
block|,
comment|/* pbf.ycmd_qs_num_lines_voq22 .. pbf.num_blocks_allocated_cons_voq22 (12 regs) */
literal|0x0c360318
block|,
comment|/* pbf.ycmd_qs_num_lines_voq23 .. pbf.num_blocks_allocated_cons_voq23 (12 regs) */
literal|0x0c360328
block|,
comment|/* pbf.ycmd_qs_num_lines_voq24 .. pbf.num_blocks_allocated_cons_voq24 (12 regs) */
literal|0x0c360338
block|,
comment|/* pbf.ycmd_qs_num_lines_voq25 .. pbf.num_blocks_allocated_cons_voq25 (12 regs) */
literal|0x0c360348
block|,
comment|/* pbf.ycmd_qs_num_lines_voq26 .. pbf.num_blocks_allocated_cons_voq26 (12 regs) */
literal|0x0c360358
block|,
comment|/* pbf.ycmd_qs_num_lines_voq27 .. pbf.num_blocks_allocated_cons_voq27 (12 regs) */
literal|0x0c360368
block|,
comment|/* pbf.ycmd_qs_num_lines_voq28 .. pbf.num_blocks_allocated_cons_voq28 (12 regs) */
literal|0x0c360378
block|,
comment|/* pbf.ycmd_qs_num_lines_voq29 .. pbf.num_blocks_allocated_cons_voq29 (12 regs) */
literal|0x0c360388
block|,
comment|/* pbf.ycmd_qs_num_lines_voq30 .. pbf.num_blocks_allocated_cons_voq30 (12 regs) */
literal|0x0c360398
block|,
comment|/* pbf.ycmd_qs_num_lines_voq31 .. pbf.num_blocks_allocated_cons_voq31 (12 regs) */
literal|0x0c3603a8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq32 .. pbf.num_blocks_allocated_cons_voq32 (12 regs) */
literal|0x0c3603b8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq33 .. pbf.num_blocks_allocated_cons_voq33 (12 regs) */
literal|0x0c3603c8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq34 .. pbf.num_blocks_allocated_cons_voq34 (12 regs) */
literal|0x0c3603d8
block|,
comment|/* pbf.ycmd_qs_num_lines_voq35 .. pbf.num_blocks_allocated_cons_voq35 (12 regs) */
literal|0x013603e8
block|,
comment|/* pbf.eco_reserved (1 regs) */
literal|0x013d0000
block|,
comment|/* block rdif */
literal|0x010c0038
block|,
comment|/* rdif.e4_backward_compatible_mode (1 regs) */
literal|0x013e0000
block|,
comment|/* block tdif */
literal|0x090c4040
block|,
comment|/* tdif.stat_num_err_interval_8 .. tdif.e4_backward_compatible_mode (9 regs) */
literal|0x01400000
block|,
comment|/* block ccfc */
literal|0x010b8204
block|,
comment|/* ccfc.eio_threshold (1 regs) */
literal|0x01410000
block|,
comment|/* block tcfc */
literal|0x010b4204
block|,
comment|/* tcfc.eio_threshold (1 regs) */
literal|0x01420000
block|,
comment|/* block igu */
literal|0x09060315
block|,
comment|/* igu.vf_with_more_16sb_21 .. igu.vf_with_more_16sb_29 (9 regs) */
literal|0x06450000
block|,
comment|/* block rgsrc */
literal|0x050c8010
block|,
comment|/* rgsrc.dbg_select .. rgsrc.dbg_force_frame (5 regs) */
literal|0x020c8060
block|,
comment|/* rgsrc.INT_STS .. rgsrc.INT_MASK (2 regs) */
literal|0x010c8080
block|,
comment|/* rgsrc.eco_reserved (1 regs) */
literal|0x040c8100
block|,
comment|/* rgsrc.cache_en .. rgsrc.max_hops (4 regs) */
literal|0x040c8114
block|,
comment|/* rgsrc.pxp_ctrl .. rgsrc.num_inhouse_cmd (4 regs) */
literal|0x090c8119
block|,
comment|/* rgsrc.num_src_cmd .. rgsrc.num_src_cmd_hit_hop_3_or_more (9 regs) */
literal|0x06470000
block|,
comment|/* block tgsrc */
literal|0x050c8810
block|,
comment|/* tgsrc.dbg_select .. tgsrc.dbg_force_frame (5 regs) */
literal|0x020c8860
block|,
comment|/* tgsrc.INT_STS .. tgsrc.INT_MASK (2 regs) */
literal|0x010c8880
block|,
comment|/* tgsrc.eco_reserved (1 regs) */
literal|0x040c8900
block|,
comment|/* tgsrc.cache_en .. tgsrc.max_hops (4 regs) */
literal|0x040c8914
block|,
comment|/* tgsrc.pxp_ctrl .. tgsrc.num_inhouse_cmd (4 regs) */
literal|0x090c8919
block|,
comment|/* tgsrc.num_src_cmd .. tgsrc.num_src_cmd_hit_hop_3_or_more (9 regs) */
literal|0x014a0000
block|,
comment|/* block dbg */
literal|0x020042ea
block|,
comment|/* dbg.filter_mode .. dbg.trigger_semi_core (2 regs) */
literal|0x034b0000
block|,
comment|/* block nig */
literal|0x0214003c
block|,
comment|/* nig.INT_STS_10 .. nig.INT_MASK_10 (2 regs) */
literal|0x01143600
block|,
comment|/* nig.tx_bmb_fifo_alm_full_thr (1 regs) */
literal|0x29143603
block|,
comment|/* nig.tx_ooo_rfifo_full .. nig.ipv6_ext_authentication_hdr_type_valid (41 regs) */
literal|0x08010015
block|,
comment|/* mode !(k2|e5), block miscs */
literal|0x03002458
block|,
comment|/* miscs.memctrl_wr_rd_n .. miscs.memctrl_address (3 regs) */
literal|0x02002464
block|,
comment|/* miscs.INT_STS_1 .. miscs.INT_MASK_1 (2 regs) */
literal|0x010025c1
block|,
comment|/* miscs.nig_dbg_vector (1 regs) */
literal|0x030025e8
block|,
comment|/* miscs.pcie_rst_prepared_assert_cnt .. miscs.pcie_rst_deassert_cnt (3 regs) */
literal|0x010025ec
block|,
comment|/* miscs.pcie_rst_n (1 regs) */
literal|0x030025ef
block|,
comment|/* miscs.avs_otp_sram_ctrl .. miscs.avs_otp_ctrl_vmgmt (3 regs) */
literal|0x060025f4
block|,
comment|/* miscs.avs_pvtmon_daccode .. miscs.opte_almfull_thr (6 regs) */
literal|0x040025fb
block|,
comment|/* miscs.avs_clock_observe .. miscs.avs_tp_out (4 regs) */
literal|0x01020000
block|,
comment|/* block misc */
literal|0x02002301
block|,
comment|/* misc.xmac_phy_port_mode .. misc.xmac_core_port_mode (2 regs) */
literal|0x01040000
block|,
comment|/* block pglue_b */
literal|0x030aa12f
block|,
comment|/* pglue_b.memctrl_wr_rd_n .. pglue_b.memctrl_address (3 regs) */
literal|0x04050000
block|,
comment|/* block cnig */
literal|0x02086080
block|,
comment|/* cnig.nw_port_mode .. cnig.nw_serdes_swap (2 regs) */
literal|0x25086095
block|,
comment|/* cnig.mac_led_swap .. cnig.cnig_dbg_ifmux_phy_lasi_b (37 regs) */
literal|0x010860be
block|,
comment|/* cnig.cnig_dbg_nigtx_fifo_afull_thresh_large (1 regs) */
literal|0x0a0860c8
block|,
comment|/* cnig.pmeg_sign_ext .. cnig.pmfc_crc_tx_corrupt_on_error (10 regs) */
literal|0x26150000
block|,
comment|/* block pglcs */
literal|0x05000902
block|,
comment|/* pglcs.pgl_cs.config_2 .. pglcs.pgl_cs.pci_extended_bar_siz (5 regs) */
literal|0x0800090a
block|,
comment|/* pglcs.pgl_cs.reg_vpd_intf .. pglcs.pgl_cs.reg_id_val5 (8 regs) */
literal|0x04000913
block|,
comment|/* pglcs.pgl_cs.reg_id_val6 .. pglcs.pgl_cs.reg_msi_addr_l (4 regs) */
literal|0x03000919
block|,
comment|/* pglcs.pgl_cs.reg_msi_mask .. pglcs.pgl_cs.reg_pm_data_c (3 regs) */
literal|0x03000930
block|,
comment|/* pglcs.pgl_cs.reg_msix_control .. pglcs.pgl_cs.reg_msix_pba_off_bir (3 regs) */
literal|0x1a000934
block|,
comment|/* pglcs.pgl_cs.reg_pcie_capability .. pglcs.pgl_cs.reg_pwr_bdgt_data_8 (26 regs) */
literal|0x02000950
block|,
comment|/* pglcs.pgl_cs.reg_l1sub_cap .. pglcs.pgl_cs.reg_l1sub_ext_cap (2 regs) */
literal|0x06000954
block|,
comment|/* pglcs.pgl_cs.reg_pwr_bdgt_capability .. pglcs.pgl_cs.reg_rc_user_mem_hi2 (6 regs) */
literal|0x1000097b
block|,
comment|/* pglcs.pgl_cs.reg_PCIER_MC_WINDOW_SIZE_REQ .. pglcs.pgl_cs.reg_vf_nsp (16 regs) */
literal|0x0200098c
block|,
comment|/* pglcs.pgl_cs.reg_ats_inld_queue_depth .. pglcs.pgl_cs.reg_VFTPH_CAP (2 regs) */
literal|0x0e000a00
block|,
comment|/* pglcs.pgl_cs.tl_control_0 .. pglcs.pgl_cs.user_control_8 (14 regs) */
literal|0x0c000a0f
block|,
comment|/* pglcs.pgl_cs.tl_control_6 .. pglcs.pgl_cs.tl_rst_ctrl (12 regs) */
literal|0x0a000a1c
block|,
comment|/* pglcs.pgl_cs.tl_obff_ctrl .. pglcs.pgl_cs.tl_func14to15_stat (10 regs) */
literal|0x29000a40
block|,
comment|/* pglcs.pgl_cs.tl_status_0 .. pglcs.pgl_cs.tl_rst_debug (41 regs) */
literal|0x01000a81
block|,
comment|/* pglcs.pgl_cs.tl_iov_vfctl_0 (1 regs) */
literal|0x02000a84
block|,
comment|/* pglcs.pgl_cs.tl_fcimm_np_limit .. pglcs.pgl_cs.tl_fcimm_p_limit (2 regs) */
literal|0x0a000a87
block|,
comment|/* pglcs.pgl_cs.reg_capena_fn0_mask .. pglcs.pgl_cs.ptm_mstr_prop_dly (10 regs) */
literal|0x0a000a94
block|,
comment|/* pglcs.pgl_cs.PCIER_TL_STAT_TX_CTL .. pglcs.pgl_cs.PCIER_TL_STAT_RX_CTR_HI (10 regs) */
literal|0x05000b00
block|,
comment|/* pglcs.pgl_cs.PCIER_DBG_FIFO_CTLSTAT .. pglcs.pgl_cs.PCIER_TLPL_DBG_FIFO_CTL (5 regs) */
literal|0x1a000b06
block|,
comment|/* pglcs.pgl_cs.PCIER_DBG_FIFO_RD_9 .. pglcs.pgl_cs.PCIER_TLDA1_RDFIFO_0 (26 regs) */
literal|0x0f000c00
block|,
comment|/* pglcs.pgl_cs.pdl_control_0 .. pglcs.pgl_cs.pdl_control_14 (15 regs) */
literal|0x08000c10
block|,
comment|/* pglcs.pgl_cs.DLATTN_VEC .. pglcs.pgl_cs.dl_spare0 (8 regs) */
literal|0x09000c40
block|,
comment|/* pglcs.pgl_cs.mdio_addr .. pglcs.pgl_cs.ate_tlp_ctl (9 regs) */
literal|0x03000c4c
block|,
comment|/* pglcs.pgl_cs.serdes_pmi_addr .. pglcs.pgl_cs.serdes_pmi_rdata (3 regs) */
literal|0x14000d00
block|,
comment|/* pglcs.pgl_cs.dl_dbg_0 .. pglcs.pgl_cs.dl_dbg_19 (20 regs) */
literal|0x0a000e00
block|,
comment|/* pglcs.pgl_cs.reg_phy_ctl_0 .. pglcs.pgl_cs.phy_err_attn_mask (10 regs) */
literal|0x08000e0c
block|,
comment|/* pglcs.pgl_cs.reg_phy_ctl_8 .. pglcs.pgl_cs.reg_phy_ctl_15 (8 regs) */
literal|0x04000e15
block|,
comment|/* pglcs.pgl_cs.reg_phy_ctl_16 .. pglcs.pgl_cs.pl_gen3_ena_frmerr (4 regs) */
literal|0x05000e40
block|,
comment|/* pglcs.pgl_cs.pl_lpbk_master_ctl0 .. pglcs.pgl_cs.pl_lpbk_master_tx_setting (5 regs) */
literal|0x01000e4c
block|,
comment|/* pglcs.pgl_cs.pl_sw_ltssm_ctl (1 regs) */
literal|0x10000e50
block|,
comment|/* pglcs.pgl_cs.pcie_statis_ctl .. pglcs.pgl_cs.pcie_rxtlperr_statis (16 regs) */
literal|0x06000e68
block|,
comment|/* pglcs.pgl_cs.ltssm_statis_ctl .. pglcs.pgl_cs.ltssm_statis_cnt (6 regs) */
literal|0x09000f00
block|,
comment|/* pglcs.pgl_cs.Received_MCP_Errors_1512 .. pglcs.pgl_cs.rx_fts_limit (9 regs) */
literal|0x06000f34
block|,
comment|/* pglcs.pgl_cs.fts_hist .. pglcs.pgl_cs.recovery_hist_1 (6 regs) */
literal|0x28000f3b
block|,
comment|/* pglcs.pgl_cs.phy_ltssm_hist_0 .. pglcs.pgl_cs.phy_dbg_sed_extcfg_74 (40 regs) */
literal|0x01000f64
block|,
comment|/* pglcs.pgl_cs.phy_dbg_preset_lut (1 regs) */
literal|0x01000f80
block|,
comment|/* pglcs.pgl_cs.phy_dbg_muxed_sigs (1 regs) */
literal|0x05000f84
block|,
comment|/* pglcs.pgl_cs.phy_dbg_clkreq_0 .. pglcs.pgl_cs.misc_dbg_status (5 regs) */
literal|0x01160000
block|,
comment|/* block dmae */
literal|0x03003140
block|,
comment|/* dmae.memctrl_wr_rd_n .. dmae.memctrl_address (3 regs) */
literal|0x011a0000
block|,
comment|/* block ucm */
literal|0x034a0010
block|,
comment|/* ucm.memctrl_wr_rd_n .. ucm.memctrl_address (3 regs) */
literal|0x01200000
block|,
comment|/* block dorq */
literal|0x030402b0
block|,
comment|/* dorq.memctrl_wr_rd_n .. dorq.memctrl_address (3 regs) */
literal|0x01210000
block|,
comment|/* block brb */
literal|0x040d0700
block|,
comment|/* brb.memctrl_wr_rd_n .. brb.memctrl_status (4 regs) */
literal|0x01230000
block|,
comment|/* block prs */
literal|0x0707c3e0
block|,
comment|/* prs.cam_bist_en .. prs.cam_bist_dbg_compare_en (7 regs) */
literal|0x012a0000
block|,
comment|/* block tsem */
literal|0x045d0330
block|,
comment|/* tsem.fast_memory.memctrl_wr_rd_n .. tsem.fast_memory.memctrl_status (4 regs) */
literal|0x012b0000
block|,
comment|/* block msem */
literal|0x04610330
block|,
comment|/* msem.fast_memory.memctrl_wr_rd_n .. msem.fast_memory.memctrl_status (4 regs) */
literal|0x012c0000
block|,
comment|/* block usem */
literal|0x04650330
block|,
comment|/* usem.fast_memory.memctrl_wr_rd_n .. usem.fast_memory.memctrl_status (4 regs) */
literal|0x012d0000
block|,
comment|/* block xsem */
literal|0x04510330
block|,
comment|/* xsem.fast_memory.memctrl_wr_rd_n .. xsem.fast_memory.memctrl_status (4 regs) */
literal|0x012e0000
block|,
comment|/* block ysem */
literal|0x04550330
block|,
comment|/* ysem.fast_memory.memctrl_wr_rd_n .. ysem.fast_memory.memctrl_status (4 regs) */
literal|0x012f0000
block|,
comment|/* block psem */
literal|0x04590330
block|,
comment|/* psem.fast_memory.memctrl_wr_rd_n .. psem.fast_memory.memctrl_status (4 regs) */
literal|0x01300000
block|,
comment|/* block rss */
literal|0x0408e322
block|,
comment|/* rss.memctrl_wr_rd_n .. rss.memctrl_status (4 regs) */
literal|0x013c0000
block|,
comment|/* block pbf */
literal|0x03360040
block|,
comment|/* pbf.memctrl_wr_rd_n .. pbf.memctrl_address (3 regs) */
literal|0x013f0000
block|,
comment|/* block cdu */
literal|0x041601d3
block|,
comment|/* cdu.memctrl_wr_rd_n .. cdu.memctrl_status (4 regs) */
literal|0x01420000
block|,
comment|/* block igu */
literal|0x07060018
block|,
comment|/* igu.cam_bist_en .. igu.cam_bist_dbg_compare_en (7 regs) */
literal|0x024a0000
block|,
comment|/* block dbg */
literal|0x0a0042b0
block|,
comment|/* dbg.cpu_mbist_memctrl_0_cntrl_cmd .. dbg.cpu_mbist_memctrl_9_cntrl_cmd (10 regs) */
literal|0x030042e5
block|,
comment|/* dbg.memctrl_wr_rd_n .. dbg.memctrl_address (3 regs) */
literal|0x024b0000
block|,
comment|/* block nig */
literal|0x04142218
block|,
comment|/* nig.user_one_step_type .. nig.ts_shift (4 regs) */
literal|0x0114221e
block|,
comment|/* nig.user_one_step_32 (1 regs) */
literal|0x04010043
block|,
comment|/* mode !e5, block miscs */
literal|0x010025bc
block|,
comment|/* miscs.function_hide (1 regs) */
literal|0x020025c2
block|,
comment|/* miscs.four_port_shared_mdio_en .. miscs.sel_dbg_ifmux_test (2 regs) */
literal|0x020025c9
block|,
comment|/* miscs.mdio_override .. miscs.mdio_subscription (2 regs) */
literal|0x010025df
block|,
comment|/* miscs.LINK_IN_L23 (1 regs) */
literal|0x01170000
block|,
comment|/* block ptu */
literal|0x0e158165
block|,
comment|/* ptu.atc_fli_done_vf_31_0 .. ptu.atc_fli_done_clr_pf_15_0 (14 regs) */
literal|0x06180000
block|,
comment|/* block tcm */
literal|0x01460186
block|,
comment|/* tcm.prs_weight (1 regs) */
literal|0x06460193
block|,
comment|/* tcm.storm_frwrd_mode .. tcm.pbf_frwrd_mode (6 regs) */
literal|0x014602ad
block|,
comment|/* tcm.prs_length_mis (1 regs) */
literal|0x014602b6
block|,
comment|/* tcm.prs_msg_cntr (1 regs) */
literal|0x014602c4
block|,
comment|/* tcm.is_prs_fill_lvl (1 regs) */
literal|0x014602e5
block|,
comment|/* tcm.is_foc_prs_nxt_inf_unit (1 regs) */
literal|0x01190000
block|,
comment|/* block mcm */
literal|0x08480193
block|,
comment|/* mcm.storm_frwrd_mode .. mcm.pbf_frwrd_mode (8 regs) */
literal|0x061a0000
block|,
comment|/* block ucm */
literal|0x014a018b
block|,
comment|/* ucm.yuld_weight (1 regs) */
literal|0x0b4a0196
block|,
comment|/* ucm.storm_frwrd_mode .. ucm.pbf_frwrd_mode (11 regs) */
literal|0x014a02b2
block|,
comment|/* ucm.yuld_length_mis (1 regs) */
literal|0x014a02bc
block|,
comment|/* ucm.yuld_msg_cntr (1 regs) */
literal|0x014a02cd
block|,
comment|/* ucm.is_yuld_fill_lvl (1 regs) */
literal|0x014a02eb
block|,
comment|/* ucm.is_foc_yuld_nxt_inf_unit (1 regs) */
literal|0x011b0000
block|,
comment|/* block xcm */
literal|0x0a400196
block|,
comment|/* xcm.storm_frwrd_mode .. xcm.pbf_frwrd_mode (10 regs) */
literal|0x011c0000
block|,
comment|/* block ycm */
literal|0x07420192
block|,
comment|/* ycm.storm_frwrd_mode .. ycm.pbf_frwrd_mode (7 regs) */
literal|0x061d0000
block|,
comment|/* block pcm */
literal|0x01440182
block|,
comment|/* pcm.pbf_weight (1 regs) */
literal|0x0344018c
block|,
comment|/* pcm.storm_frwrd_mode .. pcm.pbf_frwrd_mode (3 regs) */
literal|0x014402ab
block|,
comment|/* pcm.pbf_length_mis (1 regs) */
literal|0x014402b0
block|,
comment|/* pcm.pbf_msg_cntr (1 regs) */
literal|0x014402b4
block|,
comment|/* pcm.is_pbf_fill_lvl (1 regs) */
literal|0x014402e3
block|,
comment|/* pcm.is_foc_pbf_nxt_inf_unit (1 regs) */
literal|0x02200000
block|,
comment|/* block dorq */
literal|0x0104020e
block|,
comment|/* dorq.edpm_exist_in_qm_en (1 regs) */
literal|0x02040241
block|,
comment|/* dorq.l2_edpm_ext_hdr_size .. dorq.l2_edpm_ext_hdr_offs (2 regs) */
literal|0x02210000
block|,
comment|/* block brb */
literal|0x010d044a
block|,
comment|/* brb.rc_eop_inp_sync_fifo_push_status_1 (1 regs) */
literal|0x010d0459
block|,
comment|/* brb.rc_eop_out_sync_fifo_push_status_1 (1 regs) */
literal|0x06230000
block|,
comment|/* block prs */
literal|0x0107c2d4
block|,
comment|/* prs.prs_pkt_ct (1 regs) */
literal|0x0307c2ec
block|,
comment|/* prs.fc_dbg_select .. prs.fc_dbg_shift (3 regs) */
literal|0x0887c2f0
block|,
comment|/* prs.fc_dbg_out_data (8 regs, WB) */
literal|0x0407c2f8
block|,
comment|/* prs.fc_dbg_force_valid .. prs.fc_dbg_out_frame (4 regs) */
literal|0x0107c3c0
block|,
comment|/* prs.tcm_initial_credit (1 regs) */
literal|0x0107c3c3
block|,
comment|/* prs.tcm_current_credit (1 regs) */
literal|0x1d2a0000
block|,
comment|/* block tsem */
literal|0x045c0001
block|,
comment|/* tsem.enable_in .. tsem.pas_disable (4 regs) */
literal|0x015c0100
block|,
comment|/* tsem.arb_cycle_size (1 regs) */
literal|0x035c0113
block|,
comment|/* tsem.ext_store_free_entries .. tsem.gpre_samp_period (3 regs) */
literal|0x015c0180
block|,
comment|/* tsem.fic_min_msg (1 regs) */
literal|0x025c0188
block|,
comment|/* tsem.fic_empty_ct_mode .. tsem.fic_empty_ct_cnt (2 regs) */
literal|0x015c01b0
block|,
comment|/* tsem.full_foc_dra_strt_en (1 regs) */
literal|0x10dc01c0
block|,
comment|/* tsem.fin_command (16 regs, WB) */
literal|0x015c0240
block|,
comment|/* tsem.invld_pas_wr_en (1 regs) */
literal|0x035c0260
block|,
comment|/* tsem.arbiter_request .. tsem.arbiter_slot (3 regs) */
literal|0x025c02c1
block|,
comment|/* tsem.thread_error .. tsem.thread_rdy (2 regs) */
literal|0x015c02c5
block|,
comment|/* tsem.threads_list (1 regs) */
literal|0x015c0380
block|,
comment|/* tsem.order_pop_en (1 regs) */
literal|0x015c0382
block|,
comment|/* tsem.order_wake_en (1 regs) */
literal|0x015c0384
block|,
comment|/* tsem.pf_num_order_base (1 regs) */
literal|0x015c0402
block|,
comment|/* tsem.sync_dra_wr_alm_full (1 regs) */
literal|0x015c0440
block|,
comment|/* tsem.dra_empty (1 regs) */
literal|0x045c0450
block|,
comment|/* tsem.slow_dbg_empty .. tsem.slow_dra_wr_empty (4 regs) */
literal|0x015c0456
block|,
comment|/* tsem.slow_ram_rd_empty (1 regs) */
literal|0x025c0459
block|,
comment|/* tsem.thread_fifo_empty .. tsem.ord_id_fifo_empty (2 regs) */
literal|0x015c0490
block|,
comment|/* tsem.pas_if_full (1 regs) */
literal|0x055c0492
block|,
comment|/* tsem.slow_dbg_alm_full .. tsem.slow_dra_wr_full (5 regs) */
literal|0x025c049d
block|,
comment|/* tsem.thread_fifo_full .. tsem.ord_id_fifo_full (2 regs) */
literal|0x035c04c0
block|,
comment|/* tsem.thread_inter_cnt .. tsem.thread_orun_num (3 regs) */
literal|0x0a5c0500
block|,
comment|/* tsem.slow_dbg_active .. tsem.dbg_msg_src (10 regs) */
literal|0x015d0001
block|,
comment|/* tsem.fast_memory.ram_ext_disable (1 regs) */
literal|0x035d0122
block|,
comment|/* tsem.fast_memory.stall_0 .. tsem.fast_memory.stall_2 (3 regs) */
literal|0x015d0132
block|,
comment|/* tsem.fast_memory.pram_last_addr (1 regs) */
literal|0x015d0291
block|,
comment|/* tsem.fast_memory.storm_active_cycles (1 regs) */
literal|0x035d0293
block|,
comment|/* tsem.fast_memory.storm_stall_cycles .. tsem.fast_memory.idle_inactive_cycles (3 regs) */
literal|0x1d2b0000
block|,
comment|/* block msem */
literal|0x04600001
block|,
comment|/* msem.enable_in .. msem.pas_disable (4 regs) */
literal|0x01600100
block|,
comment|/* msem.arb_cycle_size (1 regs) */
literal|0x03600113
block|,
comment|/* msem.ext_store_free_entries .. msem.gpre_samp_period (3 regs) */
literal|0x01600180
block|,
comment|/* msem.fic_min_msg (1 regs) */
literal|0x02600188
block|,
comment|/* msem.fic_empty_ct_mode .. msem.fic_empty_ct_cnt (2 regs) */
literal|0x016001b0
block|,
comment|/* msem.full_foc_dra_strt_en (1 regs) */
literal|0x10e001c0
block|,
comment|/* msem.fin_command (16 regs, WB) */
literal|0x01600240
block|,
comment|/* msem.invld_pas_wr_en (1 regs) */
literal|0x03600260
block|,
comment|/* msem.arbiter_request .. msem.arbiter_slot (3 regs) */
literal|0x026002c1
block|,
comment|/* msem.thread_error .. msem.thread_rdy (2 regs) */
literal|0x016002c5
block|,
comment|/* msem.threads_list (1 regs) */
literal|0x01600380
block|,
comment|/* msem.order_pop_en (1 regs) */
literal|0x01600382
block|,
comment|/* msem.order_wake_en (1 regs) */
literal|0x01600384
block|,
comment|/* msem.pf_num_order_base (1 regs) */
literal|0x01600402
block|,
comment|/* msem.sync_dra_wr_alm_full (1 regs) */
literal|0x01600440
block|,
comment|/* msem.dra_empty (1 regs) */
literal|0x04600450
block|,
comment|/* msem.slow_dbg_empty .. msem.slow_dra_wr_empty (4 regs) */
literal|0x01600456
block|,
comment|/* msem.slow_ram_rd_empty (1 regs) */
literal|0x02600459
block|,
comment|/* msem.thread_fifo_empty .. msem.ord_id_fifo_empty (2 regs) */
literal|0x01600490
block|,
comment|/* msem.pas_if_full (1 regs) */
literal|0x05600492
block|,
comment|/* msem.slow_dbg_alm_full .. msem.slow_dra_wr_full (5 regs) */
literal|0x0260049d
block|,
comment|/* msem.thread_fifo_full .. msem.ord_id_fifo_full (2 regs) */
literal|0x036004c0
block|,
comment|/* msem.thread_inter_cnt .. msem.thread_orun_num (3 regs) */
literal|0x0a600500
block|,
comment|/* msem.slow_dbg_active .. msem.dbg_msg_src (10 regs) */
literal|0x01610001
block|,
comment|/* msem.fast_memory.ram_ext_disable (1 regs) */
literal|0x03610122
block|,
comment|/* msem.fast_memory.stall_0 .. msem.fast_memory.stall_2 (3 regs) */
literal|0x01610132
block|,
comment|/* msem.fast_memory.pram_last_addr (1 regs) */
literal|0x01610291
block|,
comment|/* msem.fast_memory.storm_active_cycles (1 regs) */
literal|0x03610293
block|,
comment|/* msem.fast_memory.storm_stall_cycles .. msem.fast_memory.idle_inactive_cycles (3 regs) */
literal|0x1d2c0000
block|,
comment|/* block usem */
literal|0x04640001
block|,
comment|/* usem.enable_in .. usem.pas_disable (4 regs) */
literal|0x01640100
block|,
comment|/* usem.arb_cycle_size (1 regs) */
literal|0x03640113
block|,
comment|/* usem.ext_store_free_entries .. usem.gpre_samp_period (3 regs) */
literal|0x01640180
block|,
comment|/* usem.fic_min_msg (1 regs) */
literal|0x02640188
block|,
comment|/* usem.fic_empty_ct_mode .. usem.fic_empty_ct_cnt (2 regs) */
literal|0x016401b0
block|,
comment|/* usem.full_foc_dra_strt_en (1 regs) */
literal|0x10e401c0
block|,
comment|/* usem.fin_command (16 regs, WB) */
literal|0x01640240
block|,
comment|/* usem.invld_pas_wr_en (1 regs) */
literal|0x03640260
block|,
comment|/* usem.arbiter_request .. usem.arbiter_slot (3 regs) */
literal|0x026402c1
block|,
comment|/* usem.thread_error .. usem.thread_rdy (2 regs) */
literal|0x016402c5
block|,
comment|/* usem.threads_list (1 regs) */
literal|0x01640380
block|,
comment|/* usem.order_pop_en (1 regs) */
literal|0x01640382
block|,
comment|/* usem.order_wake_en (1 regs) */
literal|0x01640384
block|,
comment|/* usem.pf_num_order_base (1 regs) */
literal|0x01640402
block|,
comment|/* usem.sync_dra_wr_alm_full (1 regs) */
literal|0x01640440
block|,
comment|/* usem.dra_empty (1 regs) */
literal|0x04640450
block|,
comment|/* usem.slow_dbg_empty .. usem.slow_dra_wr_empty (4 regs) */
literal|0x01640456
block|,
comment|/* usem.slow_ram_rd_empty (1 regs) */
literal|0x02640459
block|,
comment|/* usem.thread_fifo_empty .. usem.ord_id_fifo_empty (2 regs) */
literal|0x01640490
block|,
comment|/* usem.pas_if_full (1 regs) */
literal|0x05640492
block|,
comment|/* usem.slow_dbg_alm_full .. usem.slow_dra_wr_full (5 regs) */
literal|0x0264049d
block|,
comment|/* usem.thread_fifo_full .. usem.ord_id_fifo_full (2 regs) */
literal|0x036404c0
block|,
comment|/* usem.thread_inter_cnt .. usem.thread_orun_num (3 regs) */
literal|0x0a640500
block|,
comment|/* usem.slow_dbg_active .. usem.dbg_msg_src (10 regs) */
literal|0x01650001
block|,
comment|/* usem.fast_memory.ram_ext_disable (1 regs) */
literal|0x03650122
block|,
comment|/* usem.fast_memory.stall_0 .. usem.fast_memory.stall_2 (3 regs) */
literal|0x01650132
block|,
comment|/* usem.fast_memory.pram_last_addr (1 regs) */
literal|0x01650291
block|,
comment|/* usem.fast_memory.storm_active_cycles (1 regs) */
literal|0x03650293
block|,
comment|/* usem.fast_memory.storm_stall_cycles .. usem.fast_memory.idle_inactive_cycles (3 regs) */
literal|0x1c2d0000
block|,
comment|/* block xsem */
literal|0x04500001
block|,
comment|/* xsem.enable_in .. xsem.pas_disable (4 regs) */
literal|0x01500100
block|,
comment|/* xsem.arb_cycle_size (1 regs) */
literal|0x03500113
block|,
comment|/* xsem.ext_store_free_entries .. xsem.gpre_samp_period (3 regs) */
literal|0x02500188
block|,
comment|/* xsem.fic_empty_ct_mode .. xsem.fic_empty_ct_cnt (2 regs) */
literal|0x015001b0
block|,
comment|/* xsem.full_foc_dra_strt_en (1 regs) */
literal|0x10d001c0
block|,
comment|/* xsem.fin_command (16 regs, WB) */
literal|0x01500240
block|,
comment|/* xsem.invld_pas_wr_en (1 regs) */
literal|0x03500260
block|,
comment|/* xsem.arbiter_request .. xsem.arbiter_slot (3 regs) */
literal|0x025002c1
block|,
comment|/* xsem.thread_error .. xsem.thread_rdy (2 regs) */
literal|0x015002c5
block|,
comment|/* xsem.threads_list (1 regs) */
literal|0x01500380
block|,
comment|/* xsem.order_pop_en (1 regs) */
literal|0x01500382
block|,
comment|/* xsem.order_wake_en (1 regs) */
literal|0x01500384
block|,
comment|/* xsem.pf_num_order_base (1 regs) */
literal|0x01500402
block|,
comment|/* xsem.sync_dra_wr_alm_full (1 regs) */
literal|0x01500440
block|,
comment|/* xsem.dra_empty (1 regs) */
literal|0x04500450
block|,
comment|/* xsem.slow_dbg_empty .. xsem.slow_dra_wr_empty (4 regs) */
literal|0x01500456
block|,
comment|/* xsem.slow_ram_rd_empty (1 regs) */
literal|0x02500459
block|,
comment|/* xsem.thread_fifo_empty .. xsem.ord_id_fifo_empty (2 regs) */
literal|0x01500490
block|,
comment|/* xsem.pas_if_full (1 regs) */
literal|0x05500492
block|,
comment|/* xsem.slow_dbg_alm_full .. xsem.slow_dra_wr_full (5 regs) */
literal|0x0250049d
block|,
comment|/* xsem.thread_fifo_full .. xsem.ord_id_fifo_full (2 regs) */
literal|0x035004c0
block|,
comment|/* xsem.thread_inter_cnt .. xsem.thread_orun_num (3 regs) */
literal|0x0a500500
block|,
comment|/* xsem.slow_dbg_active .. xsem.dbg_msg_src (10 regs) */
literal|0x01510001
block|,
comment|/* xsem.fast_memory.ram_ext_disable (1 regs) */
literal|0x03510122
block|,
comment|/* xsem.fast_memory.stall_0 .. xsem.fast_memory.stall_2 (3 regs) */
literal|0x01510132
block|,
comment|/* xsem.fast_memory.pram_last_addr (1 regs) */
literal|0x01510291
block|,
comment|/* xsem.fast_memory.storm_active_cycles (1 regs) */
literal|0x03510293
block|,
comment|/* xsem.fast_memory.storm_stall_cycles .. xsem.fast_memory.idle_inactive_cycles (3 regs) */
literal|0x1c2e0000
block|,
comment|/* block ysem */
literal|0x04540001
block|,
comment|/* ysem.enable_in .. ysem.pas_disable (4 regs) */
literal|0x01540100
block|,
comment|/* ysem.arb_cycle_size (1 regs) */
literal|0x03540113
block|,
comment|/* ysem.ext_store_free_entries .. ysem.gpre_samp_period (3 regs) */
literal|0x02540188
block|,
comment|/* ysem.fic_empty_ct_mode .. ysem.fic_empty_ct_cnt (2 regs) */
literal|0x015401b0
block|,
comment|/* ysem.full_foc_dra_strt_en (1 regs) */
literal|0x10d401c0
block|,
comment|/* ysem.fin_command (16 regs, WB) */
literal|0x01540240
block|,
comment|/* ysem.invld_pas_wr_en (1 regs) */
literal|0x03540260
block|,
comment|/* ysem.arbiter_request .. ysem.arbiter_slot (3 regs) */
literal|0x025402c1
block|,
comment|/* ysem.thread_error .. ysem.thread_rdy (2 regs) */
literal|0x015402c5
block|,
comment|/* ysem.threads_list (1 regs) */
literal|0x01540380
block|,
comment|/* ysem.order_pop_en (1 regs) */
literal|0x01540382
block|,
comment|/* ysem.order_wake_en (1 regs) */
literal|0x01540384
block|,
comment|/* ysem.pf_num_order_base (1 regs) */
literal|0x01540402
block|,
comment|/* ysem.sync_dra_wr_alm_full (1 regs) */
literal|0x01540440
block|,
comment|/* ysem.dra_empty (1 regs) */
literal|0x04540450
block|,
comment|/* ysem.slow_dbg_empty .. ysem.slow_dra_wr_empty (4 regs) */
literal|0x01540456
block|,
comment|/* ysem.slow_ram_rd_empty (1 regs) */
literal|0x02540459
block|,
comment|/* ysem.thread_fifo_empty .. ysem.ord_id_fifo_empty (2 regs) */
literal|0x01540490
block|,
comment|/* ysem.pas_if_full (1 regs) */
literal|0x05540492
block|,
comment|/* ysem.slow_dbg_alm_full .. ysem.slow_dra_wr_full (5 regs) */
literal|0x0254049d
block|,
comment|/* ysem.thread_fifo_full .. ysem.ord_id_fifo_full (2 regs) */
literal|0x035404c0
block|,
comment|/* ysem.thread_inter_cnt .. ysem.thread_orun_num (3 regs) */
literal|0x0a540500
block|,
comment|/* ysem.slow_dbg_active .. ysem.dbg_msg_src (10 regs) */
literal|0x01550001
block|,
comment|/* ysem.fast_memory.ram_ext_disable (1 regs) */
literal|0x03550122
block|,
comment|/* ysem.fast_memory.stall_0 .. ysem.fast_memory.stall_2 (3 regs) */
literal|0x01550132
block|,
comment|/* ysem.fast_memory.pram_last_addr (1 regs) */
literal|0x01550291
block|,
comment|/* ysem.fast_memory.storm_active_cycles (1 regs) */
literal|0x03550293
block|,
comment|/* ysem.fast_memory.storm_stall_cycles .. ysem.fast_memory.idle_inactive_cycles (3 regs) */
literal|0x1d2f0000
block|,
comment|/* block psem */
literal|0x04580001
block|,
comment|/* psem.enable_in .. psem.pas_disable (4 regs) */
literal|0x01580100
block|,
comment|/* psem.arb_cycle_size (1 regs) */
literal|0x03580113
block|,
comment|/* psem.ext_store_free_entries .. psem.gpre_samp_period (3 regs) */
literal|0x01580180
block|,
comment|/* psem.fic_min_msg (1 regs) */
literal|0x02580188
block|,
comment|/* psem.fic_empty_ct_mode .. psem.fic_empty_ct_cnt (2 regs) */
literal|0x015801b0
block|,
comment|/* psem.full_foc_dra_strt_en (1 regs) */
literal|0x10d801c0
block|,
comment|/* psem.fin_command (16 regs, WB) */
literal|0x01580240
block|,
comment|/* psem.invld_pas_wr_en (1 regs) */
literal|0x03580260
block|,
comment|/* psem.arbiter_request .. psem.arbiter_slot (3 regs) */
literal|0x025802c1
block|,
comment|/* psem.thread_error .. psem.thread_rdy (2 regs) */
literal|0x015802c5
block|,
comment|/* psem.threads_list (1 regs) */
literal|0x01580380
block|,
comment|/* psem.order_pop_en (1 regs) */
literal|0x01580382
block|,
comment|/* psem.order_wake_en (1 regs) */
literal|0x01580384
block|,
comment|/* psem.pf_num_order_base (1 regs) */
literal|0x01580402
block|,
comment|/* psem.sync_dra_wr_alm_full (1 regs) */
literal|0x01580440
block|,
comment|/* psem.dra_empty (1 regs) */
literal|0x04580450
block|,
comment|/* psem.slow_dbg_empty .. psem.slow_dra_wr_empty (4 regs) */
literal|0x01580456
block|,
comment|/* psem.slow_ram_rd_empty (1 regs) */
literal|0x02580459
block|,
comment|/* psem.thread_fifo_empty .. psem.ord_id_fifo_empty (2 regs) */
literal|0x01580490
block|,
comment|/* psem.pas_if_full (1 regs) */
literal|0x05580492
block|,
comment|/* psem.slow_dbg_alm_full .. psem.slow_dra_wr_full (5 regs) */
literal|0x0258049d
block|,
comment|/* psem.thread_fifo_full .. psem.ord_id_fifo_full (2 regs) */
literal|0x035804c0
block|,
comment|/* psem.thread_inter_cnt .. psem.thread_orun_num (3 regs) */
literal|0x0a580500
block|,
comment|/* psem.slow_dbg_active .. psem.dbg_msg_src (10 regs) */
literal|0x01590001
block|,
comment|/* psem.fast_memory.ram_ext_disable (1 regs) */
literal|0x03590122
block|,
comment|/* psem.fast_memory.stall_0 .. psem.fast_memory.stall_2 (3 regs) */
literal|0x01590132
block|,
comment|/* psem.fast_memory.pram_last_addr (1 regs) */
literal|0x01590291
block|,
comment|/* psem.fast_memory.storm_active_cycles (1 regs) */
literal|0x03590293
block|,
comment|/* psem.fast_memory.storm_stall_cycles .. psem.fast_memory.idle_inactive_cycles (3 regs) */
literal|0x01300000
block|,
comment|/* block rss */
literal|0x0508e30d
block|,
comment|/* rss.rbc_status .. rss.state_machines (5 regs) */
literal|0x05330000
block|,
comment|/* block yuld */
literal|0x2a132000
block|,
comment|/* yuld.scbd_strict_prio .. yuld.cm_hdr_127_96 (42 regs) */
literal|0x0513202b
block|,
comment|/* yuld.stat_fic_msg .. yuld.len_err_log_2 (5 regs) */
literal|0x01132031
block|,
comment|/* yuld.len_err_log_v (1 regs) */
literal|0x02132060
block|,
comment|/* yuld.INT_STS .. yuld.INT_MASK (2 regs) */
literal|0x05132580
block|,
comment|/* yuld.dbg_select .. yuld.dbg_force_frame (5 regs) */
literal|0x033c0000
block|,
comment|/* block pbf */
literal|0x01360106
block|,
comment|/* pbf.pcm_if_init_crd (1 regs) */
literal|0x02360124
block|,
comment|/* pbf.tag_ethertype_4 .. pbf.tag_ethertype_5 (2 regs) */
literal|0x0236012a
block|,
comment|/* pbf.tag_len_4 .. pbf.tag_len_5 (2 regs) */
literal|0x05430000
block|,
comment|/* block cau */
literal|0x05070180
block|,
comment|/* cau.cqe_size .. cau.agg_release_timer (5 regs) */
literal|0x01070221
block|,
comment|/* cau.cqe_fifo_afull_thr (1 regs) */
literal|0x070702ea
block|,
comment|/* cau.stat_counter_cqe_msg_sent .. cau.stat_counter_cqe_partial_cache (7 regs) */
literal|0x04070327
block|,
comment|/* cau.agg_units_0to15_state .. cau.agg_units_48to63_state (4 regs) */
literal|0x020703c3
block|,
comment|/* cau.igu_cqe_cmd_fsm_status .. cau.igu_cqe_agg_fsm_status (2 regs) */
literal|0x024a0000
block|,
comment|/* block dbg */
literal|0x01004002
block|,
comment|/* dbg.other_client_enable (1 regs) */
literal|0x01004004
block|,
comment|/* dbg.other_engine_mode (1 regs) */
literal|0x014b0000
block|,
comment|/* block nig */
literal|0xa0140212
block|,
comment|/* nig.tx_lb_vport_drop_0 .. nig.tx_lb_vport_drop_159 (160 regs) */
literal|0x0221011b
block|,
comment|/* mode !(bb|e5), block brb */
literal|0x020d044b
block|,
comment|/* brb.rc_eop_inp_sync_fifo_push_status_2 .. brb.rc_eop_inp_sync_fifo_push_status_3 (2 regs) */
literal|0x020d045a
block|,
comment|/* brb.rc_eop_out_sync_fifo_push_status_2 .. brb.rc_eop_out_sync_fifo_push_status_3 (2 regs) */
literal|0x0e2a0000
block|,
comment|/* block tsem */
literal|0x015d0087
block|,
comment|/* tsem.fast_memory.reserved_21C (1 regs) */
literal|0x015d008a
block|,
comment|/* tsem.fast_memory.reserved_228 (1 regs) */
literal|0x015d008d
block|,
comment|/* tsem.fast_memory.reserved_234 (1 regs) */
literal|0x015d008f
block|,
comment|/* tsem.fast_memory.reserved_23C (1 regs) */
literal|0x015d0091
block|,
comment|/* tsem.fast_memory.reserved_244 (1 regs) */
literal|0x015d0094
block|,
comment|/* tsem.fast_memory.reserved_250 (1 regs) */
literal|0x015d0096
block|,
comment|/* tsem.fast_memory.reserved_258 (1 regs) */
literal|0x015d0098
block|,
comment|/* tsem.fast_memory.reserved_260 (1 regs) */
literal|0x015d009a
block|,
comment|/* tsem.fast_memory.reserved_268 (1 regs) */
literal|0x015d009c
block|,
comment|/* tsem.fast_memory.reserved_270 (1 regs) */
literal|0x015d009e
block|,
comment|/* tsem.fast_memory.reserved_278 (1 regs) */
literal|0x015d00a0
block|,
comment|/* tsem.fast_memory.reserved_280 (1 regs) */
literal|0x0f5d00a2
block|,
comment|/* tsem.fast_memory.reserved_288 .. tsem.fast_memory.reserved_2C0 (15 regs) */
literal|0x025d00b3
block|,
comment|/* tsem.fast_memory.reserved_2CC .. tsem.fast_memory.reserved_2D0 (2 regs) */
literal|0x0e2b0000
block|,
comment|/* block msem */
literal|0x01610087
block|,
comment|/* msem.fast_memory.reserved_21C (1 regs) */
literal|0x0161008a
block|,
comment|/* msem.fast_memory.reserved_228 (1 regs) */
literal|0x0161008d
block|,
comment|/* msem.fast_memory.reserved_234 (1 regs) */
literal|0x0161008f
block|,
comment|/* msem.fast_memory.reserved_23C (1 regs) */
literal|0x01610091
block|,
comment|/* msem.fast_memory.reserved_244 (1 regs) */
literal|0x01610094
block|,
comment|/* msem.fast_memory.reserved_250 (1 regs) */
literal|0x01610096
block|,
comment|/* msem.fast_memory.reserved_258 (1 regs) */
literal|0x01610098
block|,
comment|/* msem.fast_memory.reserved_260 (1 regs) */
literal|0x0161009a
block|,
comment|/* msem.fast_memory.reserved_268 (1 regs) */
literal|0x0161009c
block|,
comment|/* msem.fast_memory.reserved_270 (1 regs) */
literal|0x0161009e
block|,
comment|/* msem.fast_memory.reserved_278 (1 regs) */
literal|0x016100a0
block|,
comment|/* msem.fast_memory.reserved_280 (1 regs) */
literal|0x0f6100a2
block|,
comment|/* msem.fast_memory.reserved_288 .. msem.fast_memory.reserved_2C0 (15 regs) */
literal|0x026100b3
block|,
comment|/* msem.fast_memory.reserved_2CC .. msem.fast_memory.reserved_2D0 (2 regs) */
literal|0x0e2c0000
block|,
comment|/* block usem */
literal|0x01650087
block|,
comment|/* usem.fast_memory.reserved_21C (1 regs) */
literal|0x0165008a
block|,
comment|/* usem.fast_memory.reserved_228 (1 regs) */
literal|0x0165008d
block|,
comment|/* usem.fast_memory.reserved_234 (1 regs) */
literal|0x0165008f
block|,
comment|/* usem.fast_memory.reserved_23C (1 regs) */
literal|0x01650091
block|,
comment|/* usem.fast_memory.reserved_244 (1 regs) */
literal|0x01650094
block|,
comment|/* usem.fast_memory.reserved_250 (1 regs) */
literal|0x01650096
block|,
comment|/* usem.fast_memory.reserved_258 (1 regs) */
literal|0x01650098
block|,
comment|/* usem.fast_memory.reserved_260 (1 regs) */
literal|0x0165009a
block|,
comment|/* usem.fast_memory.reserved_268 (1 regs) */
literal|0x0165009c
block|,
comment|/* usem.fast_memory.reserved_270 (1 regs) */
literal|0x0165009e
block|,
comment|/* usem.fast_memory.reserved_278 (1 regs) */
literal|0x016500a0
block|,
comment|/* usem.fast_memory.reserved_280 (1 regs) */
literal|0x0f6500a2
block|,
comment|/* usem.fast_memory.reserved_288 .. usem.fast_memory.reserved_2C0 (15 regs) */
literal|0x026500b3
block|,
comment|/* usem.fast_memory.reserved_2CC .. usem.fast_memory.reserved_2D0 (2 regs) */
literal|0x0e2d0000
block|,
comment|/* block xsem */
literal|0x01510087
block|,
comment|/* xsem.fast_memory.reserved_21C (1 regs) */
literal|0x0151008a
block|,
comment|/* xsem.fast_memory.reserved_228 (1 regs) */
literal|0x0151008d
block|,
comment|/* xsem.fast_memory.reserved_234 (1 regs) */
literal|0x0151008f
block|,
comment|/* xsem.fast_memory.reserved_23C (1 regs) */
literal|0x01510091
block|,
comment|/* xsem.fast_memory.reserved_244 (1 regs) */
literal|0x01510094
block|,
comment|/* xsem.fast_memory.reserved_250 (1 regs) */
literal|0x01510096
block|,
comment|/* xsem.fast_memory.reserved_258 (1 regs) */
literal|0x01510098
block|,
comment|/* xsem.fast_memory.reserved_260 (1 regs) */
literal|0x0151009a
block|,
comment|/* xsem.fast_memory.reserved_268 (1 regs) */
literal|0x0151009c
block|,
comment|/* xsem.fast_memory.reserved_270 (1 regs) */
literal|0x0151009e
block|,
comment|/* xsem.fast_memory.reserved_278 (1 regs) */
literal|0x015100a0
block|,
comment|/* xsem.fast_memory.reserved_280 (1 regs) */
literal|0x0f5100a2
block|,
comment|/* xsem.fast_memory.reserved_288 .. xsem.fast_memory.reserved_2C0 (15 regs) */
literal|0x025100b3
block|,
comment|/* xsem.fast_memory.reserved_2CC .. xsem.fast_memory.reserved_2D0 (2 regs) */
literal|0x0e2e0000
block|,
comment|/* block ysem */
literal|0x01550087
block|,
comment|/* ysem.fast_memory.reserved_21C (1 regs) */
literal|0x0155008a
block|,
comment|/* ysem.fast_memory.reserved_228 (1 regs) */
literal|0x0155008d
block|,
comment|/* ysem.fast_memory.reserved_234 (1 regs) */
literal|0x0155008f
block|,
comment|/* ysem.fast_memory.reserved_23C (1 regs) */
literal|0x01550091
block|,
comment|/* ysem.fast_memory.reserved_244 (1 regs) */
literal|0x01550094
block|,
comment|/* ysem.fast_memory.reserved_250 (1 regs) */
literal|0x01550096
block|,
comment|/* ysem.fast_memory.reserved_258 (1 regs) */
literal|0x01550098
block|,
comment|/* ysem.fast_memory.reserved_260 (1 regs) */
literal|0x0155009a
block|,
comment|/* ysem.fast_memory.reserved_268 (1 regs) */
literal|0x0155009c
block|,
comment|/* ysem.fast_memory.reserved_270 (1 regs) */
literal|0x0155009e
block|,
comment|/* ysem.fast_memory.reserved_278 (1 regs) */
literal|0x015500a0
block|,
comment|/* ysem.fast_memory.reserved_280 (1 regs) */
literal|0x0f5500a2
block|,
comment|/* ysem.fast_memory.reserved_288 .. ysem.fast_memory.reserved_2C0 (15 regs) */
literal|0x025500b3
block|,
comment|/* ysem.fast_memory.reserved_2CC .. ysem.fast_memory.reserved_2D0 (2 regs) */
literal|0x0e2f0000
block|,
comment|/* block psem */
literal|0x01590087
block|,
comment|/* psem.fast_memory.reserved_21C (1 regs) */
literal|0x0159008a
block|,
comment|/* psem.fast_memory.reserved_228 (1 regs) */
literal|0x0159008d
block|,
comment|/* psem.fast_memory.reserved_234 (1 regs) */
literal|0x0159008f
block|,
comment|/* psem.fast_memory.reserved_23C (1 regs) */
literal|0x01590091
block|,
comment|/* psem.fast_memory.reserved_244 (1 regs) */
literal|0x01590094
block|,
comment|/* psem.fast_memory.reserved_250 (1 regs) */
literal|0x01590096
block|,
comment|/* psem.fast_memory.reserved_258 (1 regs) */
literal|0x01590098
block|,
comment|/* psem.fast_memory.reserved_260 (1 regs) */
literal|0x0159009a
block|,
comment|/* psem.fast_memory.reserved_268 (1 regs) */
literal|0x0159009c
block|,
comment|/* psem.fast_memory.reserved_270 (1 regs) */
literal|0x0159009e
block|,
comment|/* psem.fast_memory.reserved_278 (1 regs) */
literal|0x015900a0
block|,
comment|/* psem.fast_memory.reserved_280 (1 regs) */
literal|0x0f5900a2
block|,
comment|/* psem.fast_memory.reserved_288 .. psem.fast_memory.reserved_2C0 (15 regs) */
literal|0x025900b3
block|,
comment|/* psem.fast_memory.reserved_2CC .. psem.fast_memory.reserved_2D0 (2 regs) */
literal|0x014b0000
block|,
comment|/* block nig */
literal|0x301402b2
block|,
comment|/* nig.tx_lb_vport_drop_160 .. nig.tx_lb_vport_drop_207 (48 regs) */
literal|0x02540000
block|,
comment|/* block avs_wrap */
literal|0x041ad000
block|,
comment|/* avs_wrap.avs_control .. avs_wrap.INT_MASK (4 regs) */
literal|0x091ad00a
block|,
comment|/* avs_wrap.eco_reserved .. avs_wrap.efuse_data_word_23 (9 regs) */
literal|0x01030033
block|,
comment|/* mode !((!asic)|(bb|k2)), block dbu */
literal|0x01002800
block|,
comment|/* dbu.cmd (1 regs) */
literal|0x0203001d
block|,
comment|/* mode !(!asic), block dbu */
literal|0x02002802
block|,
comment|/* dbu.config .. dbu.timing (2 regs) */
literal|0x02002805
block|,
comment|/* dbu.txdata .. dbu.vfid_cfg (2 regs) */
literal|0x030c0000
block|,
comment|/* block mcp2 */
literal|0x01014880
block|,
comment|/* mcp2.eco_reserved (1 regs) */
literal|0x03014900
block|,
comment|/* mcp2.dbg_select .. mcp2.dbg_shift (3 regs) */
literal|0x02014910
block|,
comment|/* mcp2.dbg_force_valid .. mcp2.dbg_force_frame (2 regs) */
literal|0x06480000
block|,
comment|/* block umac */
literal|0x02014401
block|,
comment|/* umac.ipg_hd_bkp_cntl .. umac.command_config (2 regs) */
literal|0x01014405
block|,
comment|/* umac.frm_length (1 regs) */
literal|0x01014411
block|,
comment|/* umac.mac_mode (1 regs) */
literal|0x01014417
block|,
comment|/* umac.tx_ipg_length (1 regs) */
literal|0x010144c0
block|,
comment|/* umac.mac_pfc_type (1 regs) */
literal|0x010144cc
block|,
comment|/* umac.pause_control (1 regs) */
literal|0x0207000b
block|,
comment|/* mode !(emul_reduced|fpga), block ncsi */
literal|0xa2010080
block|,
comment|/* ncsi.config .. ncsi.dbg_force_frame (162 regs) */
literal|0x03010132
block|,
comment|/* ncsi.eco_reserved .. ncsi.INT_MASK_0 (3 regs) */
literal|0x26090000
block|,
comment|/* block bmb */
literal|0x03150001
block|,
comment|/* bmb.hw_init_en .. bmb.start_en (3 regs) */
literal|0x02150030
block|,
comment|/* bmb.INT_STS_0 .. bmb.INT_MASK_0 (2 regs) */
literal|0x02150036
block|,
comment|/* bmb.INT_STS_1 .. bmb.INT_MASK_1 (2 regs) */
literal|0x0215003c
block|,
comment|/* bmb.INT_STS_2 .. bmb.INT_MASK_2 (2 regs) */
literal|0x02150042
block|,
comment|/* bmb.INT_STS_3 .. bmb.INT_MASK_3 (2 regs) */
literal|0x02150048
block|,
comment|/* bmb.INT_STS_4 .. bmb.INT_MASK_4 (2 regs) */
literal|0x0215004e
block|,
comment|/* bmb.INT_STS_5 .. bmb.INT_MASK_5 (2 regs) */
literal|0x02150054
block|,
comment|/* bmb.INT_STS_6 .. bmb.INT_MASK_6 (2 regs) */
literal|0x0215005a
block|,
comment|/* bmb.INT_STS_7 .. bmb.INT_MASK_7 (2 regs) */
literal|0x02150061
block|,
comment|/* bmb.INT_STS_8 .. bmb.INT_MASK_8 (2 regs) */
literal|0x02150067
block|,
comment|/* bmb.INT_STS_9 .. bmb.INT_MASK_9 (2 regs) */
literal|0x0215006d
block|,
comment|/* bmb.INT_STS_10 .. bmb.INT_MASK_10 (2 regs) */
literal|0x02150073
block|,
comment|/* bmb.INT_STS_11 .. bmb.INT_MASK_11 (2 regs) */
literal|0x02150200
block|,
comment|/* bmb.big_ram_address .. bmb.header_size (2 regs) */
literal|0x0a150210
block|,
comment|/* bmb.max_releases .. bmb.tc_guarantied_5 (10 regs) */
literal|0x0615021e
block|,
comment|/* bmb.tc_guarantied_hyst_0 .. bmb.tc_guarantied_hyst_5 (6 regs) */
literal|0x06150228
block|,
comment|/* bmb.tc_pause_xoff_threshold_0 .. bmb.tc_pause_xoff_threshold_5 (6 regs) */
literal|0x06150232
block|,
comment|/* bmb.tc_pause_xon_threshold_0 .. bmb.tc_pause_xon_threshold_5 (6 regs) */
literal|0x0615023c
block|,
comment|/* bmb.tc_full_xoff_threshold_0 .. bmb.tc_full_xoff_threshold_5 (6 regs) */
literal|0x06150246
block|,
comment|/* bmb.tc_full_xon_threshold_0 .. bmb.tc_full_xon_threshold_5 (6 regs) */
literal|0x02150250
block|,
comment|/* bmb.no_dead_cycles_en .. bmb.rc_pkt_priority (2 regs) */
literal|0x0d150260
block|,
comment|/* bmb.rc_sop_priority .. bmb.pm_tc_latency_sensitive_0 (13 regs) */
literal|0x0615028c
block|,
comment|/* bmb.pm_cos_threshold_0 .. bmb.pm_cos_threshold_5 (6 regs) */
literal|0x0815029c
block|,
comment|/* bmb.dbgsyn_almost_full_thr .. bmb.dbg_force_frame (8 regs) */
literal|0x0c1502b2
block|,
comment|/* bmb.inp_if_enable .. bmb.wc_empty_9 (12 regs) */
literal|0x0a1502c4
block|,
comment|/* bmb.wc_full_0 .. bmb.wc_full_9 (10 regs) */
literal|0x051502d4
block|,
comment|/* bmb.wc_bandwidth_if_full .. bmb.rc_pkt_empty_2 (5 regs) */
literal|0x031502e5
block|,
comment|/* bmb.rc_pkt_full_0 .. bmb.rc_pkt_full_2 (3 regs) */
literal|0x031502f4
block|,
comment|/* bmb.rc_pkt_status_0 .. bmb.rc_pkt_status_2 (3 regs) */
literal|0x36150303
block|,
comment|/* bmb.rc_sop_empty .. bmb.rc_dscr_pend_fifo_cnt_7 (54 regs) */
literal|0x03150341
block|,
comment|/* bmb.rc_gnt_pend_fifo_empty .. bmb.rc_gnt_pend_fifo_cnt (3 regs) */
literal|0x02150353
block|,
comment|/* bmb.wc_sync_fifo_push_status_8 .. bmb.wc_sync_fifo_push_status_9 (2 regs) */
literal|0x02150362
block|,
comment|/* bmb.pkt_avail_sync_fifo_push_status .. bmb.rc_pkt_state (2 regs) */
literal|0x01150367
block|,
comment|/* bmb.mac_free_shared_hr_0 (1 regs) */
literal|0x0615036d
block|,
comment|/* bmb.tc_occupancy_0 .. bmb.tc_occupancy_5 (6 regs) */
literal|0x0115037d
block|,
comment|/* bmb.available_mac_size_0 (1 regs) */
literal|0x01150383
block|,
comment|/* bmb.tc_pause_0 (1 regs) */
literal|0x01150389
block|,
comment|/* bmb.tc_full_0 (1 regs) */
literal|0x042f0000
block|,
comment|/* block psem */
literal|0x0e592800
block|,
comment|/* psem.fast_memory.vfc_config.mask_lsb_0_low .. psem.fast_memory.vfc_config.indications2 (14 regs) */
literal|0x1359280f
block|,
comment|/* psem.fast_memory.vfc_config.memories_rst .. psem.fast_memory.vfc_config.cpu_mbist_memctrl_1_cntrl_cmd (19 regs) */
literal|0x12592824
block|,
comment|/* psem.fast_memory.vfc_config.debug_data .. psem.fast_memory.vfc_config.mask_lsb_7_high (18 regs) */
literal|0x0c59283e
block|,
comment|/* psem.fast_memory.vfc_config.offset_alu_vector_0 .. psem.fast_memory.vfc_config.cam_bist_skip_error_cnt (12 regs) */
literal|0x0109004f
block|,
comment|/* mode (!bb)&(!(emul_reduced|fpga)), block bmb */
literal|0x02150252
block|,
comment|/* bmb.wc_no_dead_cycles_en .. bmb.wc_highest_pri_en (2 regs) */
literal|0x06090041
block|,
comment|/* mode (!e5)&(!(emul_reduced|fpga)), block bmb */
literal|0x071502d9
block|,
comment|/* bmb.rc_pkt_empty_3 .. bmb.rc_pkt_empty_9 (7 regs) */
literal|0x071502e8
block|,
comment|/* bmb.rc_pkt_full_3 .. bmb.rc_pkt_full_9 (7 regs) */
literal|0x071502f7
block|,
comment|/* bmb.rc_pkt_status_3 .. bmb.rc_pkt_status_9 (7 regs) */
literal|0x08150339
block|,
comment|/* bmb.rc_sop_inp_sync_fifo_pop_empty_8 .. bmb.rc_sop_out_sync_fifo_push_status_9 (8 regs) */
literal|0x02150344
block|,
comment|/* bmb.rc_out_sync_fifo_push_status_8 .. bmb.rc_out_sync_fifo_push_status_9 (2 regs) */
literal|0x01150364
block|,
comment|/* bmb.rc_pkt_state_1 (1 regs) */
literal|0x03090001
block|,
comment|/* mode (!(bb|k2))&(!(emul_reduced|fpga)), block bmb */
literal|0x08150339
block|,
comment|/* bmb.rc_sop_inp_sync_fifo_pop_empty_1 .. bmb.rc_sop_out_sync_fifo_push_status_2 (8 regs) */
literal|0x02150344
block|,
comment|/* bmb.rc_out_sync_fifo_push_status_1 .. bmb.rc_out_sync_fifo_push_status_2 (2 regs) */
literal|0x02151000
block|,
comment|/* bmb.wc_ll_high_pri .. bmb.br_fix_high_pri_collision (2 regs) */
literal|0x08480013
block|,
comment|/* mode (!(k2|e5))&(!(!asic)), block umac */
literal|0x02014403
block|,
comment|/* umac.mac_0 .. umac.mac_1 (2 regs) */
literal|0x01014406
block|,
comment|/* umac.pause_quant (1 regs) */
literal|0x01014410
block|,
comment|/* umac.sfd_offset (1 regs) */
literal|0x04014412
block|,
comment|/* umac.tag_0 .. umac.tx_preamble (4 regs) */
literal|0x05014418
block|,
comment|/* umac.pfc_xoff_timer .. umac.umac_eee_ref_count (5 regs) */
literal|0x0501441e
block|,
comment|/* umac.umac_rx_pkt_drop_status .. umac.umac_rev_id (5 regs) */
literal|0x070144c1
block|,
comment|/* umac.mac_pfc_opcode .. umac.tx_ts_data (7 regs) */
literal|0x050144cd
block|,
comment|/* umac.flush_control .. umac.mac_pfc_refresh_ctrl (5 regs) */
literal|0x054e0000
block|,
comment|/* block ipc */
literal|0xa3008080
block|,
comment|/* ipc.mdio_voltage_sel .. ipc.swreg_sync_clk_en (163 regs) */
literal|0x03008126
block|,
comment|/* ipc.nw_serdes_mdio_comm .. ipc.nw_serdes_mdio_mode (3 regs) */
literal|0x0100812c
block|,
comment|/* ipc.freq_nw (1 regs) */
literal|0x0800813a
block|,
comment|/* ipc.otp_config_0 .. ipc.otp_config_7 (8 regs) */
literal|0x0500814b
block|,
comment|/* ipc.lcpll_refclk_sel .. ipc.cpu_otp_rd_syndrome (5 regs) */
literal|0x044800c3
block|,
comment|/* mode (!bb)&(!(!asic)), block umac */
literal|0x07014423
block|,
comment|/* umac.tx_ipg_length1 .. umac.dbg_force_frame (7 regs) */
literal|0x02014460
block|,
comment|/* umac.INT_STS .. umac.INT_MASK (2 regs) */
literal|0x070144c1
block|,
comment|/* umac.pause_opcode .. umac.mac_pause_sa_1 (7 regs) */
literal|0x030144cd
block|,
comment|/* umac.rsv_err_mask .. umac.probe_data (3 regs) */
literal|0x034e0000
block|,
comment|/* block ipc */
literal|0x26008080
block|,
comment|/* ipc.pll_main_divr .. ipc.sgmii_rstb_mdioregs (38 regs) */
literal|0x120080a7
block|,
comment|/* ipc.freq_main .. ipc.INT_MASK_0 (18 regs) */
literal|0x230080bb
block|,
comment|/* ipc.jtag_compliance .. ipc.eco_reserved (35 regs) */
literal|0xff500000
block|,
comment|/* block nws */
literal|0x031c8000
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister0 .. nws.nws_cmu.phy0_top_ReservedRegister2 (3 regs) */
literal|0x031c8004
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister3 .. nws.nws_cmu.phy0_top_ReservedRegister5 (3 regs) */
literal|0x011c8009
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister6 (1 regs) */
literal|0x041c8030
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister7 .. nws.nws_cmu.phy0_top_ReservedRegister10 (4 regs) */
literal|0x021c8038
block|,
comment|/* nws.nws_cmu.phy0_top_afe_atest_ctrl0 .. nws.nws_cmu.phy0_top_afe_atest_ctrl1 (2 regs) */
literal|0x011c8040
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister11 (1 regs) */
literal|0x011c8050
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister12 (1 regs) */
literal|0x041c8054
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister13 .. nws.nws_cmu.phy0_top_ReservedRegister16 (4 regs) */
literal|0x0b1c80f0
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister17 .. nws.nws_cmu.phy0_top_clock_cm_lc0_clk_cmudiv_ctrl1 (11 regs) */
literal|0x0a1c8100
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister26 .. nws.nws_cmu.phy0_top_clock_cm_r0_clk_pll3div_ctrl1 (10 regs) */
literal|0x061c8110
block|,
comment|/* nws.nws_cmu.phy0_top_clock_ln0_clk_tx .. nws.nws_cmu.phy0_top_ReservedRegister35 (6 regs) */
literal|0x061c8118
block|,
comment|/* nws.nws_cmu.phy0_top_clock_ln1_clk_tx .. nws.nws_cmu.phy0_top_ReservedRegister39 (6 regs) */
literal|0x061c8120
block|,
comment|/* nws.nws_cmu.phy0_top_clock_ln2_clk_tx .. nws.nws_cmu.phy0_top_ReservedRegister43 (6 regs) */
literal|0x061c8128
block|,
comment|/* nws.nws_cmu.phy0_top_clock_ln3_clk_tx .. nws.nws_cmu.phy0_top_ReservedRegister47 (6 regs) */
literal|0x021c8130
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister48 .. nws.nws_cmu.phy0_top_ReservedRegister49 (2 regs) */
literal|0x011c8170
block|,
comment|/* nws.nws_cmu.phy0_top_ReservedRegister50 (1 regs) */
literal|0x031c8180
block|,
comment|/* nws.nws_cmu.phy0_top_err_ctrl0 .. nws.nws_cmu.phy0_top_err_ctrl2 (3 regs) */
literal|0x061c8187
block|,
comment|/* nws.nws_cmu.phy0_top_regbus_err_info_ctrl .. nws.nws_cmu.phy0_top_regbus_err_info_status4 (6 regs) */
literal|0x051c81a0
block|,
comment|/* nws.nws_cmu.phy0_top_tbus_addr_7_0 .. nws.nws_cmu.phy0_top_ReservedRegister53 (5 regs) */
literal|0x021c81b0
block|,
comment|/* nws.nws_cmu.phy0_top_tbus_data_7_0 .. nws.nws_cmu.phy0_top_tbus_data_11_8 (2 regs) */
literal|0x021c81c0
block|,
comment|/* nws.nws_cmu.phy0_top_sim_ctrl .. nws.nws_cmu.phy0_top_fw_ctrl (2 regs) */
literal|0x011c8200
block|,
comment|/* nws.nws_cmu.phy0_mb_cmd (1 regs) */
literal|0x081c8203
block|,
comment|/* nws.nws_cmu.phy0_mb_cmd_data0 .. nws.nws_cmu.phy0_mb_cmd_data7 (8 regs) */
literal|0x011c8210
block|,
comment|/* nws.nws_cmu.phy0_mb_rsp (1 regs) */
literal|0x101c8213
block|,
comment|/* nws.nws_cmu.phy0_mb_rsp_data0 .. nws.nws_cmu.phy0_mb_rsp_data15 (16 regs) */
literal|0x221c8300
block|,
comment|/* nws.nws_cmu.phy0_ovr_cmu_lc_ReservedRegister54 .. nws.nws_cmu.phy0_ovr_cmu_lc_ReservedRegister87 (34 regs) */
literal|0x0a1c8380
block|,
comment|/* nws.nws_cmu.phy0_ovr_cmu_r_ReservedRegister88 .. nws.nws_cmu.phy0_ovr_cmu_r_ReservedRegister97 (10 regs) */
literal|0x931c8400
block|,
comment|/* nws.nws_cmu.phy0_ovr_ln0_ReservedRegister98 .. nws.nws_cmu.phy0_ovr_ln0_ReservedRegister244 (147 regs) */
literal|0x931c8500
block|,
comment|/* nws.nws_cmu.phy0_ovr_ln1_ReservedRegister245 .. nws.nws_cmu.phy0_ovr_ln1_ReservedRegister391 (147 regs) */
literal|0x931c8600
block|,
comment|/* nws.nws_cmu.phy0_ovr_ln2_ReservedRegister392 .. nws.nws_cmu.phy0_ovr_ln2_ReservedRegister538 (147 regs) */
literal|0x931c8700
block|,
comment|/* nws.nws_cmu.phy0_ovr_ln3_ReservedRegister539 .. nws.nws_cmu.phy0_ovr_ln3_ReservedRegister685 (147 regs) */
literal|0x021c8800
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister686 .. nws.nws_cmu.cmu_lc0_top_ReservedRegister687 (2 regs) */
literal|0x011c8803
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister688 (1 regs) */
literal|0x061c8805
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister689 .. nws.nws_cmu.cmu_lc0_top_ReservedRegister694 (6 regs) */
literal|0x011c880c
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister695 (1 regs) */
literal|0x021c881a
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister696 .. nws.nws_cmu.cmu_lc0_top_ReservedRegister697 (2 regs) */
literal|0x081c881f
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister698 .. nws.nws_cmu.cmu_lc0_top_ReservedRegister704 (8 regs) */
literal|0x011c8828
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_afe_tstclk_ctrl0 (1 regs) */
literal|0x051c8830
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister705 .. nws.nws_cmu.cmu_lc0_top_ReservedRegister709 (5 regs) */
literal|0x031c8850
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister710 .. nws.nws_cmu.cmu_lc0_top_phy_if_status (3 regs) */
literal|0x021c8858
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister712 .. nws.nws_cmu.cmu_lc0_top_ReservedRegister713 (2 regs) */
literal|0x031c8880
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_err_ctrl1 .. nws.nws_cmu.cmu_lc0_top_err_ctrl3 (3 regs) */
literal|0x031c888a
block|,
comment|/* nws.nws_cmu.cmu_lc0_top_ReservedRegister714 .. nws.nws_cmu.cmu_lc0_top_ReservedRegister716 (3 regs) */
literal|0x041c8900
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister717 .. nws.nws_cmu.cmu_lc0_pll_afe_reg_ctrl1 (4 regs) */
literal|0x021c8905
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister720 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister721 (2 regs) */
literal|0x031c8908
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister722 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister724 (3 regs) */
literal|0x021c8910
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister725 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister726 (2 regs) */
literal|0x041c8913
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister727 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister730 (4 regs) */
literal|0x051c8918
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister731 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister735 (5 regs) */
literal|0x1b1c8920
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister736 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister762 (27 regs) */
literal|0x011c893c
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister763 (1 regs) */
literal|0x031c8944
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister764 .. nws.nws_cmu.cmu_lc0_pll_lockdet_status (3 regs) */
literal|0x091c8949
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister766 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister774 (9 regs) */
literal|0x021c8954
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister775 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister776 (2 regs) */
literal|0x021c8958
block|,
comment|/* nws.nws_cmu.cmu_lc0_pll_ReservedRegister777 .. nws.nws_cmu.cmu_lc0_pll_ReservedRegister778 (2 regs) */
literal|0x041c8a00
block|,
comment|/* nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister779 .. nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister782 (4 regs) */
literal|0x041c8a10
block|,
comment|/* nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister783 .. nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister786 (4 regs) */
literal|0x071c8a20
block|,
comment|/* nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister787 .. nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister793 (7 regs) */
literal|0x031c8a30
block|,
comment|/* nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister794 .. nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister796 (3 regs) */
literal|0x091c8a40
block|,
comment|/* nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister797 .. nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister805 (9 regs) */
literal|0x021c8a50
block|,
comment|/* nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister806 .. nws.nws_cmu.cmu_lc0_gcfsm2_ReservedRegister807 (2 regs) */
literal|0x061c8b00
block|,
comment|/* nws.nws_cmu.cmu_lc0_feature_ReservedRegister808 .. nws.nws_cmu.cmu_lc0_feature_ReservedRegister813 (6 regs) */
literal|0x011c8b08
block|,
comment|/* nws.nws_cmu.cmu_lc0_feature_ReservedRegister814 (1 regs) */
literal|0x081c8b10
block|,
comment|/* nws.nws_cmu.cmu_lc0_feature_ReservedRegister815 .. nws.nws_cmu.cmu_lc0_feature_ReservedRegister822 (8 regs) */
literal|0x021c8c00
block|,
comment|/* nws.nws_cmu.cmu_r0_top_ReservedRegister823 .. nws.nws_cmu.cmu_r0_top_ReservedRegister824 (2 regs) */
literal|0x011c8c03
block|,
comment|/* nws.nws_cmu.cmu_r0_top_ReservedRegister825 (1 regs) */
literal|0x041c8c10
block|,
comment|/* nws.nws_cmu.cmu_r0_top_ReservedRegister826 .. nws.nws_cmu.cmu_r0_top_ReservedRegister829 (4 regs) */
literal|0x041c8c20
block|,
comment|/* nws.nws_cmu.cmu_r0_top_ReservedRegister830 .. nws.nws_cmu.cmu_r0_top_ReservedRegister833 (4 regs) */
literal|0x011c8c30
block|,
comment|/* nws.nws_cmu.cmu_r0_top_ReservedRegister834 (1 regs) */
literal|0x031c8c50
block|,
comment|/* nws.nws_cmu.cmu_r0_top_ReservedRegister835 .. nws.nws_cmu.cmu_r0_top_phy_if_status (3 regs) */
literal|0x021c8c58
block|,
comment|/* nws.nws_cmu.cmu_r0_top_ReservedRegister837 .. nws.nws_cmu.cmu_r0_top_ReservedRegister838 (2 regs) */
literal|0x031c8c80
block|,
comment|/* nws.nws_cmu.cmu_r0_top_err_ctrl1 .. nws.nws_cmu.cmu_r0_top_err_ctrl3 (3 regs) */
literal|0x031c8c8a
block|,
comment|/* nws.nws_cmu.cmu_r0_top_ReservedRegister839 .. nws.nws_cmu.cmu_r0_top_ReservedRegister841 (3 regs) */
literal|0x051c8d00
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_afe_pd_ctrl0 .. nws.nws_cmu.cmu_r0_rpll_afe_vco_ctrl0 (5 regs) */
literal|0x011c8d06
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_afe_clkdiv_ctrl0 (1 regs) */
literal|0x061c8d08
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_ReservedRegister843 .. nws.nws_cmu.cmu_r0_rpll_afe_int_ctrl0 (6 regs) */
literal|0x041c8d0f
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_afe_int_ctrl1 .. nws.nws_cmu.cmu_r0_rpll_afe_fracn_ctrl0 (4 regs) */
literal|0x021c8d16
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_afe_misc_ctrl0 .. nws.nws_cmu.cmu_r0_rpll_afe_misc_ctrl1 (2 regs) */
literal|0x131c8d20
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_ReservedRegister844 .. nws.nws_cmu.cmu_r0_rpll_ReservedRegister862 (19 regs) */
literal|0x071c8d34
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_ReservedRegister863 .. nws.nws_cmu.cmu_r0_rpll_ReservedRegister869 (7 regs) */
literal|0x031c8d44
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_ReservedRegister870 .. nws.nws_cmu.cmu_r0_rpll_lockdet_status (3 regs) */
literal|0x091c8d49
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_ssc_gen_ctrl0 .. nws.nws_cmu.cmu_r0_rpll_fracn_ctrl2 (9 regs) */
literal|0x021c8d54
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_fracn_ctrl3 .. nws.nws_cmu.cmu_r0_rpll_fracn_ctrl4 (2 regs) */
literal|0x021c8d58
block|,
comment|/* nws.nws_cmu.cmu_r0_rpll_ReservedRegister872 .. nws.nws_cmu.cmu_r0_rpll_ReservedRegister873 (2 regs) */
literal|0x041c8e00
block|,
comment|/* nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister874 .. nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister877 (4 regs) */
literal|0x041c8e10
block|,
comment|/* nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister878 .. nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister881 (4 regs) */
literal|0x071c8e20
block|,
comment|/* nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister882 .. nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister888 (7 regs) */
literal|0x031c8e30
block|,
comment|/* nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister889 .. nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister891 (3 regs) */
literal|0x091c8e40
block|,
comment|/* nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister892 .. nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister900 (9 regs) */
literal|0x021c8e50
block|,
comment|/* nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister901 .. nws.nws_cmu.cmu_r0_gcfsm2_ReservedRegister902 (2 regs) */
literal|0x011c8f00
block|,
comment|/* nws.nws_cmu.cmu_r0_feature_ReservedRegister903 (1 regs) */
literal|0x021c8f04
block|,
comment|/* nws.nws_cmu.cmu_r0_feature_ReservedRegister904 .. nws.nws_cmu.cmu_r0_feature_ReservedRegister905 (2 regs) */
literal|0x011c8f08
block|,
comment|/* nws.nws_cmu.cmu_r0_feature_ReservedRegister906 (1 regs) */
literal|0x081c8f10
block|,
comment|/* nws.nws_cmu.cmu_r0_feature_ReservedRegister907 .. nws.nws_cmu.cmu_r0_feature_ReservedRegister914 (8 regs) */
literal|0x071c9800
block|,
comment|/* nws.nws_cmu.ln0_top_afe_loopback_ctrl .. nws.nws_cmu.ln0_top_ReservedRegister920 (7 regs) */
literal|0x011c9810
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister921 (1 regs) */
literal|0x031c9812
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister922 .. nws.nws_cmu.ln0_top_ReservedRegister924 (3 regs) */
literal|0x011c9816
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister925 (1 regs) */
literal|0x011c9819
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister926 (1 regs) */
literal|0x021c981b
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister927 .. nws.nws_cmu.ln0_top_ReservedRegister928 (2 regs) */
literal|0x011c981e
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister929 (1 regs) */
literal|0x011c9822
block|,
comment|/* nws.nws_cmu.ln0_top_dpl_txdp_ctrl1 (1 regs) */
literal|0x041c9824
block|,
comment|/* nws.nws_cmu.ln0_top_dpl_rxdp_ctrl1 .. nws.nws_cmu.ln0_top_phy_if_status (4 regs) */
literal|0x021c9830
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister932 .. nws.nws_cmu.ln0_top_ReservedRegister933 (2 regs) */
literal|0x091c9838
block|,
comment|/* nws.nws_cmu.ln0_top_ln_stat_ctrl0 .. nws.nws_cmu.ln0_top_ReservedRegister940 (9 regs) */
literal|0x021c9842
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister941 .. nws.nws_cmu.ln0_top_ReservedRegister942 (2 regs) */
literal|0x051c9848
block|,
comment|/* nws.nws_cmu.ln0_top_ReservedRegister943 .. nws.nws_cmu.ln0_top_ReservedRegister947 (5 regs) */
literal|0x031c9850
block|,
comment|/* nws.nws_cmu.ln0_top_err_ctrl1 .. nws.nws_cmu.ln0_top_err_ctrl3 (3 regs) */
literal|0x021c9890
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister948 .. nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister949 (2 regs) */
literal|0x021c98a1
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister950 .. nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister951 (2 regs) */
literal|0x061c98a6
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister952 .. nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister957 (6 regs) */
literal|0x011c98ad
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister958 (1 regs) */
literal|0x031c98b0
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister959 .. nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister961 (3 regs) */
literal|0x011c98b4
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister962 (1 regs) */
literal|0x021c98b6
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister963 .. nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister964 (2 regs) */
literal|0x091c98b9
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister965 .. nws.nws_cmu.ln0_cdr_rxclk_dlpf_status4 (9 regs) */
literal|0x031c98c4
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_dlpf_status5 .. nws.nws_cmu.ln0_cdr_rxclk_integral_status1 (3 regs) */
literal|0x081c98c8
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_integral_status2 .. nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister977 (8 regs) */
literal|0x041c98e0
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister978 .. nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister981 (4 regs) */
literal|0x091c98e8
block|,
comment|/* nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister982 .. nws.nws_cmu.ln0_cdr_rxclk_ReservedRegister990 (9 regs) */
literal|0x021c9900
block|,
comment|/* nws.nws_cmu.ln0_cdr_refclk_ReservedRegister991 .. nws.nws_cmu.ln0_cdr_refclk_ReservedRegister992 (2 regs) */
literal|0x011c9904
block|,
comment|/* nws.nws_cmu.ln0_cdr_refclk_ReservedRegister993 (1 regs) */
literal|0x011c9906
block|,
comment|/* nws.nws_cmu.ln0_cdr_refclk_ReservedRegister994 (1 regs) */
literal|0x031c990a
block|,
comment|/* nws.nws_cmu.ln0_cdr_refclk_ReservedRegister995 .. nws.nws_cmu.ln0_cdr_refclk_ReservedRegister997 (3 regs) */
literal|0x021c9910
block|,
comment|/* nws.nws_cmu.ln0_cdr_refclk_ReservedRegister998 .. nws.nws_cmu.ln0_cdr_refclk_ReservedRegister999 (2 regs) */
literal|0x041c9918
block|,
comment|/* nws.nws_cmu.ln0_cdr_refclk_ReservedRegister1000 .. nws.nws_cmu.ln0_cdr_refclk_ReservedRegister1003 (4 regs) */
literal|0x061c9920
block|,
comment|/* nws.nws_cmu.ln0_cdr_refclk_ReservedRegister1004 .. nws.nws_cmu.ln0_cdr_refclk_ReservedRegister1009 (6 regs) */
literal|0x011c9930
block|,
comment|/* nws.nws_cmu.ln0_cdr_refclk_ReservedRegister1010 (1 regs) */
literal|0x0f1c9980
block|,
comment|/* nws.nws_cmu.ln0_aneg_ReservedRegister1011 .. nws.nws_cmu.ln0_aneg_ReservedRegister1022 (15 regs) */
literal|0x011c9990
block|,
comment|/* nws.nws_cmu.ln0_aneg_status0 (1 regs) */
literal|0x021c9994
block|,
comment|/* nws.nws_cmu.ln0_aneg_status_dbg0 .. nws.nws_cmu.ln0_aneg_status_dbg1 (2 regs) */
literal|0x251c9998
block|,
comment|/* nws.nws_cmu.ln0_aneg_base_page0 .. nws.nws_cmu.ln0_aneg_resolution_eee (37 regs) */
literal|0x021c99be
block|,
comment|/* nws.nws_cmu.ln0_aneg_link_status0 .. nws.nws_cmu.ln0_aneg_link_status1 (2 regs) */
literal|0x031c99c1
block|,
comment|/* nws.nws_cmu.ln0_eee_ReservedRegister1039 .. nws.nws_cmu.ln0_eee_ReservedRegister1041 (3 regs) */
literal|0x041c99c5
block|,
comment|/* nws.nws_cmu.ln0_eee_ReservedRegister1042 .. nws.nws_cmu.ln0_eee_ReservedRegister1045 (4 regs) */
literal|0x011c9a00
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1046 (1 regs) */
literal|0x021c9a02
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1047 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1048 (2 regs) */
literal|0x011c9a05
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1049 (1 regs) */
literal|0x011c9a07
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1050 (1 regs) */
literal|0x041c9a09
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1051 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1054 (4 regs) */
literal|0x041c9a0e
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1055 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1058 (4 regs) */
literal|0x0d1c9a20
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1059 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1071 (13 regs) */
literal|0x011c9a2e
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1072 (1 regs) */
literal|0x0b1c9a30
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_agclos_ctrl0 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1082 (11 regs) */
literal|0x021c9a3d
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1083 .. nws.nws_cmu.ln0_leq_refclk_ple_att_ctrl1 (2 regs) */
literal|0x071c9a40
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_eq_hfg_sql_ctrl0 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1089 (7 regs) */
literal|0x191c9a50
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1090 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1114 (25 regs) */
literal|0x071c9a70
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_gn_apg_ctrl0 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1120 (7 regs) */
literal|0x091c9a80
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_eq_lfg_ctrl0 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1126 (9 regs) */
literal|0x071c9a90
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1127 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1133 (7 regs) */
literal|0x061c9a98
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1134 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1138 (6 regs) */
literal|0x041c9aa0
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1139 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1142 (4 regs) */
literal|0x041c9aa6
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1143 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1146 (4 regs) */
literal|0x021c9aab
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1147 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1148 (2 regs) */
literal|0x021c9aae
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1149 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1150 (2 regs) */
literal|0x021c9ab8
block|,
comment|/* nws.nws_cmu.ln0_leq_refclk_ReservedRegister1151 .. nws.nws_cmu.ln0_leq_refclk_ReservedRegister1152 (2 regs) */
literal|0x061c9b00
block|,
comment|/* nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1153 .. nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1158 (6 regs) */
literal|0x021c9b08
block|,
comment|/* nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1159 .. nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1160 (2 regs) */
literal|0x021c9b0c
block|,
comment|/* nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1161 .. nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1162 (2 regs) */
literal|0x021c9b10
block|,
comment|/* nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1163 .. nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1164 (2 regs) */
literal|0x021c9b13
block|,
comment|/* nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1165 .. nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1166 (2 regs) */
literal|0x021c9b16
block|,
comment|/* nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1167 .. nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1168 (2 regs) */
literal|0x021c9b20
block|,
comment|/* nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1169 .. nws.nws_cmu.ln0_leq_rxclk_ReservedRegister1170 (2 regs) */
literal|0x071c9b80
block|,
comment|/* nws.nws_cmu.ln0_drv_refclk_afe_pd_ctrl0 .. nws.nws_cmu.ln0_drv_refclk_ReservedRegister1175 (7 regs) */
literal|0x061c9b88
block|,
comment|/* nws.nws_cmu.ln0_drv_refclk_ReservedRegister1176 .. nws.nws_cmu.ln0_drv_refclk_ReservedRegister1181 (6 regs) */
literal|0x0a1c9b90
block|,
comment|/* nws.nws_cmu.ln0_drv_refclk_txeq_ctrl0 .. nws.nws_cmu.ln0_drv_refclk_ReservedRegister1186 (10 regs) */
literal|0x011c9b9b
block|,
comment|/* nws.nws_cmu.ln0_drv_refclk_ReservedRegister1187 (1 regs) */
literal|0x051c9c00
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1188 .. nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1192 (5 regs) */
literal|0x011c9c06
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1193 (1 regs) */
literal|0x011c9c0a
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1194 (1 regs) */
literal|0x011c9c0c
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1195 (1 regs) */
literal|0x011c9c0e
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1196 (1 regs) */
literal|0x011c9c10
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1197 (1 regs) */
literal|0x011c9c12
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1198 (1 regs) */
literal|0x011c9c14
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1199 (1 regs) */
literal|0x011c9c16
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1200 (1 regs) */
literal|0x021c9c18
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1201 .. nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1202 (2 regs) */
literal|0x011c9c1b
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1203 (1 regs) */
literal|0x091c9c20
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_fsm_ctrl0 .. nws.nws_cmu.ln0_dfe_refclk_fsm_status0 (9 regs) */
literal|0x191c9c2a
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_tap_ctrl0 .. nws.nws_cmu.ln0_dfe_refclk_tap_val_status7 (25 regs) */
literal|0x161c9c50
block|,
comment|/* nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1211 .. nws.nws_cmu.ln0_dfe_refclk_ReservedRegister1232 (22 regs) */
literal|0x031c9c80
block|,
comment|/* nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1233 .. nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1235 (3 regs) */
literal|0x081c9c86
block|,
comment|/* nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1236 .. nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1243 (8 regs) */
literal|0x031c9c90
block|,
comment|/* nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1244 .. nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1246 (3 regs) */
literal|0x091c9c96
block|,
comment|/* nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1247 .. nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1255 (9 regs) */
literal|0x161c9ca4
block|,
comment|/* nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1256 .. nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1277 (22 regs) */
literal|0x121c9cc0
block|,
comment|/* nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1278 .. nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1295 (18 regs) */
literal|0x031c9cd6
block|,
comment|/* nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1296 .. nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1298 (3 regs) */
literal|0x0c1c9ce0
block|,
comment|/* nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1299 .. nws.nws_cmu.ln0_dfe_rxclk_ReservedRegister1310 (12 regs) */
literal|0x061c9d00
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_afe_cal_ctrl .. nws.nws_cmu.ln0_los_refclk_run_length_status0 (6 regs) */
literal|0x071c9d10
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_filter_ctrl0 .. nws.nws_cmu.ln0_los_refclk_filter_ctrl6 (7 regs) */
literal|0x051c9d20
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_ReservedRegister1313 .. nws.nws_cmu.ln0_los_refclk_ReservedRegister1317 (5 regs) */
literal|0x041c9d30
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_override_ctrl0 .. nws.nws_cmu.ln0_los_refclk_ReservedRegister1320 (4 regs) */
literal|0x041c9d40
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_ReservedRegister1321 .. nws.nws_cmu.ln0_los_refclk_ReservedRegister1324 (4 regs) */
literal|0x011c9d46
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_ReservedRegister1325 (1 regs) */
literal|0x011c9d51
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_ReservedRegister1326 (1 regs) */
literal|0x011c9d59
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_ReservedRegister1327 (1 regs) */
literal|0x011c9d60
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_ReservedRegister1328 (1 regs) */
literal|0x021c9d70
block|,
comment|/* nws.nws_cmu.ln0_los_refclk_ReservedRegister1329 .. nws.nws_cmu.ln0_los_refclk_status0 (2 regs) */
literal|0x041c9d80
block|,
comment|/* nws.nws_cmu.ln0_gcfsm2_ReservedRegister1330 .. nws.nws_cmu.ln0_gcfsm2_ReservedRegister1333 (4 regs) */
literal|0x041c9d90
block|,
comment|/* nws.nws_cmu.ln0_gcfsm2_ReservedRegister1334 .. nws.nws_cmu.ln0_gcfsm2_ReservedRegister1337 (4 regs) */
literal|0x071c9da0
block|,
comment|/* nws.nws_cmu.ln0_gcfsm2_ReservedRegister1338 .. nws.nws_cmu.ln0_gcfsm2_ReservedRegister1344 (7 regs) */
literal|0x031c9db0
block|,
comment|/* nws.nws_cmu.ln0_gcfsm2_ReservedRegister1345 .. nws.nws_cmu.ln0_gcfsm2_ReservedRegister1347 (3 regs) */
literal|0x091c9dc0
block|,
comment|/* nws.nws_cmu.ln0_gcfsm2_ReservedRegister1348 .. nws.nws_cmu.ln0_gcfsm2_ReservedRegister1356 (9 regs) */
literal|0x021c9dd0
block|,
comment|/* nws.nws_cmu.ln0_gcfsm2_ReservedRegister1357 .. nws.nws_cmu.ln0_gcfsm2_ReservedRegister1358 (2 regs) */
literal|0x051c9e00
block|,
comment|/* nws.nws_cmu.ln0_bist_tx_ctrl .. nws.nws_cmu.ln0_bist_tx_ReservedRegister1362 (5 regs) */
literal|0x081c9e06
block|,
comment|/* nws.nws_cmu.ln0_bist_tx_ber_ctrl0 .. nws.nws_cmu.ln0_bist_tx_ber_ctrl7 (8 regs) */
literal|0x011c9e20
block|,
comment|/* nws.nws_cmu.ln0_bist_tx_udp_shift_amount (1 regs) */
literal|0x191c9e24
block|,
comment|/* nws.nws_cmu.ln0_bist_tx_udp_7_0 .. nws.nws_cmu.ln0_bist_tx_udp_199_192 (25 regs) */
literal|0x011c9e80
block|,
comment|/* nws.nws_cmu.ln0_bist_rx_ctrl (1 regs) */
literal|0x011c9e84
block|,
comment|/* nws.nws_cmu.ln0_bist_rx_status (1 regs) */
literal|0x031c9e88
block|,
comment|/* nws.nws_cmu.ln0_bist_rx_ber_status0 .. nws.nws_cmu.ln0_bist_rx_ber_status2 (3 regs) */
literal|0x031c9e8c
block|,
comment|/* nws.nws_cmu.ln0_bist_rx_ber_status4 .. nws.nws_cmu.ln0_bist_rx_ber_status6 (3 regs) */
literal|0x041c9e94
block|,
comment|/* nws.nws_cmu.ln0_bist_rx_lock_ctrl0 .. nws.nws_cmu.ln0_bist_rx_lock_ctrl3 (4 regs) */
literal|0x051c9ea0
block|,
comment|/* nws.nws_cmu.ln0_bist_rx_loss_lock_ctrl0 .. nws.nws_cmu.ln0_bist_rx_loss_lock_ctrl4 (5 regs) */
literal|0x011c9eb0
block|,
comment|/* nws.nws_cmu.ln0_bist_rx_udp_shift_amount (1 regs) */
literal|0x191c9eb4
block|,
comment|/* nws.nws_cmu.ln0_bist_rx_udp_7_0 .. nws.nws_cmu.ln0_bist_rx_udp_199_192 (25 regs) */
literal|0x021c9f00
block|,
comment|/* nws.nws_cmu.ln0_feature_rxterm_cfg0 .. nws.nws_cmu.ln0_feature_rxclkdiv_cfg0 (2 regs) */
literal|0x061c9f04
block|,
comment|/* nws.nws_cmu.ln0_feature_ReservedRegister1363 .. nws.nws_cmu.ln0_feature_ReservedRegister1368 (6 regs) */
literal|0x071c9f10
block|,
comment|/* nws.nws_cmu.ln0_feature_ReservedRegister1369 .. nws.nws_cmu.ln0_feature_ReservedRegister1375 (7 regs) */
literal|0x0a1c9f20
block|,
comment|/* nws.nws_cmu.ln0_feature_ReservedRegister1376 .. nws.nws_cmu.ln0_feature_ReservedRegister1378 (10 regs) */
literal|0x071c9f30
block|,
comment|/* nws.nws_cmu.ln0_feature_dfe_cfg .. nws.nws_cmu.ln0_feature_dfe_adapt_tap5_cfg (7 regs) */
literal|0x101c9f38
block|,
comment|/* nws.nws_cmu.ln0_feature_adapt_cont_cfg0 .. nws.nws_cmu.ln0_feature_ReservedRegister1390 (16 regs) */
literal|0x011c9f50
block|,
comment|/* nws.nws_cmu.ln0_feature_test_cfg0 (1 regs) */
literal|0x081c9f58
block|,
comment|/* nws.nws_cmu.ln0_feature_ReservedRegister1391 .. nws.nws_cmu.ln0_feature_ReservedRegister1398 (8 regs) */
literal|0x061c9f80
block|,
comment|/* nws.nws_cmu.ln0_lt_tx_fsm_ctrl0 .. nws.nws_cmu.ln0_lt_tx_fsm_ctrl5 (6 regs) */
literal|0x011c9f90
block|,
comment|/* nws.nws_cmu.ln0_lt_tx_fsm_status (1 regs) */
literal|0x031c9f93
block|,
comment|/* nws.nws_cmu.ln0_lt_tx_prbs_ctrl0 .. nws.nws_cmu.ln0_lt_tx_prbs_ctrl2 (3 regs) */
literal|0x011c9fa0
block|,
comment|/* nws.nws_cmu.ln0_lt_tx_coefficient_update_ctrl (1 regs) */
literal|0x011c9fa2
block|,
comment|/* nws.nws_cmu.ln0_lt_tx_status_report_ctrl (1 regs) */
literal|0x021c9fb0
block|,
comment|/* nws.nws_cmu.ln0_lt_tx_fsm_state_status0 .. nws.nws_cmu.ln0_lt_tx_fsm_state_status1 (2 regs) */
literal|0x011c9fc0
block|,
comment|/* nws.nws_cmu.ln0_lt_rx_ctrl0 (1 regs) */
literal|0x021c9fc2
block|,
comment|/* nws.nws_cmu.ln0_lt_rx_prbs_ctrl0 .. nws.nws_cmu.ln0_lt_rx_prbs_ctrl1 (2 regs) */
literal|0x031c9fc5
block|,
comment|/* nws.nws_cmu.ln0_lt_rx_prbs_status0 .. nws.nws_cmu.ln0_lt_rx_prbs_status2 (3 regs) */
literal|0x011c9fd0
block|,
comment|/* nws.nws_cmu.ln0_lt_rx_frame_ctrl (1 regs) */
literal|0x051c9fd3
block|,
comment|/* nws.nws_cmu.ln0_lt_rx_frame_status0 .. nws.nws_cmu.ln0_lt_rx_frame_status4 (5 regs) */
literal|0x011c9fe0
block|,
comment|/* nws.nws_cmu.ln0_lt_rx_coefficient_update_status (1 regs) */
literal|0x011c9fe2
block|,
comment|/* nws.nws_cmu.ln0_lt_rx_report_status (1 regs) */
literal|0x071ca000
block|,
comment|/* nws.nws_cmu.ln1_top_afe_loopback_ctrl .. nws.nws_cmu.ln1_top_ReservedRegister1404 (7 regs) */
literal|0x011ca010
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1405 (1 regs) */
literal|0x031ca012
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1406 .. nws.nws_cmu.ln1_top_ReservedRegister1408 (3 regs) */
literal|0x011ca016
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1409 (1 regs) */
literal|0x011ca019
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1410 (1 regs) */
literal|0x021ca01b
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1411 .. nws.nws_cmu.ln1_top_ReservedRegister1412 (2 regs) */
literal|0x011ca01e
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1413 (1 regs) */
literal|0x011ca022
block|,
comment|/* nws.nws_cmu.ln1_top_dpl_txdp_ctrl1 (1 regs) */
literal|0x041ca024
block|,
comment|/* nws.nws_cmu.ln1_top_dpl_rxdp_ctrl1 .. nws.nws_cmu.ln1_top_phy_if_status (4 regs) */
literal|0x021ca030
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1416 .. nws.nws_cmu.ln1_top_ReservedRegister1417 (2 regs) */
literal|0x091ca038
block|,
comment|/* nws.nws_cmu.ln1_top_ln_stat_ctrl0 .. nws.nws_cmu.ln1_top_ReservedRegister1424 (9 regs) */
literal|0x021ca042
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1425 .. nws.nws_cmu.ln1_top_ReservedRegister1426 (2 regs) */
literal|0x051ca048
block|,
comment|/* nws.nws_cmu.ln1_top_ReservedRegister1427 .. nws.nws_cmu.ln1_top_ReservedRegister1431 (5 regs) */
literal|0x031ca050
block|,
comment|/* nws.nws_cmu.ln1_top_err_ctrl1 .. nws.nws_cmu.ln1_top_err_ctrl3 (3 regs) */
literal|0x021ca090
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1432 .. nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1433 (2 regs) */
literal|0x021ca0a1
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1434 .. nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1435 (2 regs) */
literal|0x061ca0a6
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1436 .. nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1441 (6 regs) */
literal|0xff500000
block|,
comment|/* block nws */
literal|0x011ca0ad
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1442 (1 regs) */
literal|0x031ca0b0
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1443 .. nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1445 (3 regs) */
literal|0x011ca0b4
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1446 (1 regs) */
literal|0x021ca0b6
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1447 .. nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1448 (2 regs) */
literal|0x091ca0b9
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1449 .. nws.nws_cmu.ln1_cdr_rxclk_dlpf_status4 (9 regs) */
literal|0x031ca0c4
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_dlpf_status5 .. nws.nws_cmu.ln1_cdr_rxclk_integral_status1 (3 regs) */
literal|0x081ca0c8
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_integral_status2 .. nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1461 (8 regs) */
literal|0x041ca0e0
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1462 .. nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1465 (4 regs) */
literal|0x091ca0e8
block|,
comment|/* nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1466 .. nws.nws_cmu.ln1_cdr_rxclk_ReservedRegister1474 (9 regs) */
literal|0x021ca100
block|,
comment|/* nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1475 .. nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1476 (2 regs) */
literal|0x011ca104
block|,
comment|/* nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1477 (1 regs) */
literal|0x011ca106
block|,
comment|/* nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1478 (1 regs) */
literal|0x031ca10a
block|,
comment|/* nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1479 .. nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1481 (3 regs) */
literal|0x021ca110
block|,
comment|/* nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1482 .. nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1483 (2 regs) */
literal|0x041ca118
block|,
comment|/* nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1484 .. nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1487 (4 regs) */
literal|0x061ca120
block|,
comment|/* nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1488 .. nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1493 (6 regs) */
literal|0x011ca130
block|,
comment|/* nws.nws_cmu.ln1_cdr_refclk_ReservedRegister1494 (1 regs) */
literal|0x0f1ca180
block|,
comment|/* nws.nws_cmu.ln1_aneg_ReservedRegister1495 .. nws.nws_cmu.ln1_aneg_ReservedRegister1506 (15 regs) */
literal|0x011ca190
block|,
comment|/* nws.nws_cmu.ln1_aneg_status0 (1 regs) */
literal|0x021ca194
block|,
comment|/* nws.nws_cmu.ln1_aneg_status_dbg0 .. nws.nws_cmu.ln1_aneg_status_dbg1 (2 regs) */
literal|0x251ca198
block|,
comment|/* nws.nws_cmu.ln1_aneg_base_page0 .. nws.nws_cmu.ln1_aneg_resolution_eee (37 regs) */
literal|0x021ca1be
block|,
comment|/* nws.nws_cmu.ln1_aneg_link_status0 .. nws.nws_cmu.ln1_aneg_link_status1 (2 regs) */
literal|0x031ca1c1
block|,
comment|/* nws.nws_cmu.ln1_eee_ReservedRegister1523 .. nws.nws_cmu.ln1_eee_ReservedRegister1525 (3 regs) */
literal|0x041ca1c5
block|,
comment|/* nws.nws_cmu.ln1_eee_ReservedRegister1526 .. nws.nws_cmu.ln1_eee_ReservedRegister1529 (4 regs) */
literal|0x011ca200
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1530 (1 regs) */
literal|0x021ca202
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1531 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1532 (2 regs) */
literal|0x011ca205
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1533 (1 regs) */
literal|0x011ca207
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1534 (1 regs) */
literal|0x041ca209
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1535 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1538 (4 regs) */
literal|0x041ca20e
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1539 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1542 (4 regs) */
literal|0x0d1ca220
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1543 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1555 (13 regs) */
literal|0x011ca22e
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1556 (1 regs) */
literal|0x0b1ca230
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_agclos_ctrl0 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1566 (11 regs) */
literal|0x021ca23d
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1567 .. nws.nws_cmu.ln1_leq_refclk_ple_att_ctrl1 (2 regs) */
literal|0x071ca240
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_eq_hfg_sql_ctrl0 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1573 (7 regs) */
literal|0x191ca250
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1574 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1598 (25 regs) */
literal|0x071ca270
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_gn_apg_ctrl0 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1604 (7 regs) */
literal|0x091ca280
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_eq_lfg_ctrl0 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1610 (9 regs) */
literal|0x071ca290
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1611 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1617 (7 regs) */
literal|0x061ca298
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1618 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1622 (6 regs) */
literal|0x041ca2a0
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1623 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1626 (4 regs) */
literal|0x041ca2a6
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1627 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1630 (4 regs) */
literal|0x021ca2ab
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1631 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1632 (2 regs) */
literal|0x021ca2ae
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1633 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1634 (2 regs) */
literal|0x021ca2b8
block|,
comment|/* nws.nws_cmu.ln1_leq_refclk_ReservedRegister1635 .. nws.nws_cmu.ln1_leq_refclk_ReservedRegister1636 (2 regs) */
literal|0x061ca300
block|,
comment|/* nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1637 .. nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1642 (6 regs) */
literal|0x021ca308
block|,
comment|/* nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1643 .. nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1644 (2 regs) */
literal|0x021ca30c
block|,
comment|/* nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1645 .. nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1646 (2 regs) */
literal|0x021ca310
block|,
comment|/* nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1647 .. nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1648 (2 regs) */
literal|0x021ca313
block|,
comment|/* nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1649 .. nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1650 (2 regs) */
literal|0x021ca316
block|,
comment|/* nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1651 .. nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1652 (2 regs) */
literal|0x021ca320
block|,
comment|/* nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1653 .. nws.nws_cmu.ln1_leq_rxclk_ReservedRegister1654 (2 regs) */
literal|0x071ca380
block|,
comment|/* nws.nws_cmu.ln1_drv_refclk_afe_pd_ctrl0 .. nws.nws_cmu.ln1_drv_refclk_ReservedRegister1659 (7 regs) */
literal|0x061ca388
block|,
comment|/* nws.nws_cmu.ln1_drv_refclk_ReservedRegister1660 .. nws.nws_cmu.ln1_drv_refclk_ReservedRegister1665 (6 regs) */
literal|0x0a1ca390
block|,
comment|/* nws.nws_cmu.ln1_drv_refclk_txeq_ctrl0 .. nws.nws_cmu.ln1_drv_refclk_ReservedRegister1670 (10 regs) */
literal|0x011ca39b
block|,
comment|/* nws.nws_cmu.ln1_drv_refclk_ReservedRegister1671 (1 regs) */
literal|0x051ca400
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1672 .. nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1676 (5 regs) */
literal|0x011ca406
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1677 (1 regs) */
literal|0x011ca40a
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1678 (1 regs) */
literal|0x011ca40c
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1679 (1 regs) */
literal|0x011ca40e
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1680 (1 regs) */
literal|0x011ca410
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1681 (1 regs) */
literal|0x011ca412
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1682 (1 regs) */
literal|0x011ca414
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1683 (1 regs) */
literal|0x011ca416
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1684 (1 regs) */
literal|0x021ca418
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1685 .. nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1686 (2 regs) */
literal|0x011ca41b
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1687 (1 regs) */
literal|0x091ca420
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_fsm_ctrl0 .. nws.nws_cmu.ln1_dfe_refclk_fsm_status0 (9 regs) */
literal|0x191ca42a
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_tap_ctrl0 .. nws.nws_cmu.ln1_dfe_refclk_tap_val_status7 (25 regs) */
literal|0x161ca450
block|,
comment|/* nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1695 .. nws.nws_cmu.ln1_dfe_refclk_ReservedRegister1716 (22 regs) */
literal|0x031ca480
block|,
comment|/* nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1717 .. nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1719 (3 regs) */
literal|0x081ca486
block|,
comment|/* nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1720 .. nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1727 (8 regs) */
literal|0x031ca490
block|,
comment|/* nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1728 .. nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1730 (3 regs) */
literal|0x091ca496
block|,
comment|/* nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1731 .. nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1739 (9 regs) */
literal|0x161ca4a4
block|,
comment|/* nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1740 .. nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1761 (22 regs) */
literal|0x121ca4c0
block|,
comment|/* nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1762 .. nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1779 (18 regs) */
literal|0x031ca4d6
block|,
comment|/* nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1780 .. nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1782 (3 regs) */
literal|0x0c1ca4e0
block|,
comment|/* nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1783 .. nws.nws_cmu.ln1_dfe_rxclk_ReservedRegister1794 (12 regs) */
literal|0x061ca500
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_afe_cal_ctrl .. nws.nws_cmu.ln1_los_refclk_run_length_status0 (6 regs) */
literal|0x071ca510
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_filter_ctrl0 .. nws.nws_cmu.ln1_los_refclk_filter_ctrl6 (7 regs) */
literal|0x051ca520
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_ReservedRegister1797 .. nws.nws_cmu.ln1_los_refclk_ReservedRegister1801 (5 regs) */
literal|0x041ca530
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_override_ctrl0 .. nws.nws_cmu.ln1_los_refclk_ReservedRegister1804 (4 regs) */
literal|0x041ca540
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_ReservedRegister1805 .. nws.nws_cmu.ln1_los_refclk_ReservedRegister1808 (4 regs) */
literal|0x011ca546
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_ReservedRegister1809 (1 regs) */
literal|0x011ca551
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_ReservedRegister1810 (1 regs) */
literal|0x011ca559
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_ReservedRegister1811 (1 regs) */
literal|0x011ca560
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_ReservedRegister1812 (1 regs) */
literal|0x021ca570
block|,
comment|/* nws.nws_cmu.ln1_los_refclk_ReservedRegister1813 .. nws.nws_cmu.ln1_los_refclk_status0 (2 regs) */
literal|0x041ca580
block|,
comment|/* nws.nws_cmu.ln1_gcfsm2_ReservedRegister1814 .. nws.nws_cmu.ln1_gcfsm2_ReservedRegister1817 (4 regs) */
literal|0x041ca590
block|,
comment|/* nws.nws_cmu.ln1_gcfsm2_ReservedRegister1818 .. nws.nws_cmu.ln1_gcfsm2_ReservedRegister1821 (4 regs) */
literal|0x071ca5a0
block|,
comment|/* nws.nws_cmu.ln1_gcfsm2_ReservedRegister1822 .. nws.nws_cmu.ln1_gcfsm2_ReservedRegister1828 (7 regs) */
literal|0x031ca5b0
block|,
comment|/* nws.nws_cmu.ln1_gcfsm2_ReservedRegister1829 .. nws.nws_cmu.ln1_gcfsm2_ReservedRegister1831 (3 regs) */
literal|0x091ca5c0
block|,
comment|/* nws.nws_cmu.ln1_gcfsm2_ReservedRegister1832 .. nws.nws_cmu.ln1_gcfsm2_ReservedRegister1840 (9 regs) */
literal|0x021ca5d0
block|,
comment|/* nws.nws_cmu.ln1_gcfsm2_ReservedRegister1841 .. nws.nws_cmu.ln1_gcfsm2_ReservedRegister1842 (2 regs) */
literal|0x051ca600
block|,
comment|/* nws.nws_cmu.ln1_bist_tx_ctrl .. nws.nws_cmu.ln1_bist_tx_ReservedRegister1846 (5 regs) */
literal|0x081ca606
block|,
comment|/* nws.nws_cmu.ln1_bist_tx_ber_ctrl0 .. nws.nws_cmu.ln1_bist_tx_ber_ctrl7 (8 regs) */
literal|0x011ca620
block|,
comment|/* nws.nws_cmu.ln1_bist_tx_udp_shift_amount (1 regs) */
literal|0x191ca624
block|,
comment|/* nws.nws_cmu.ln1_bist_tx_udp_7_0 .. nws.nws_cmu.ln1_bist_tx_udp_199_192 (25 regs) */
literal|0x011ca680
block|,
comment|/* nws.nws_cmu.ln1_bist_rx_ctrl (1 regs) */
literal|0x011ca684
block|,
comment|/* nws.nws_cmu.ln1_bist_rx_status (1 regs) */
literal|0x031ca688
block|,
comment|/* nws.nws_cmu.ln1_bist_rx_ber_status0 .. nws.nws_cmu.ln1_bist_rx_ber_status2 (3 regs) */
literal|0x031ca68c
block|,
comment|/* nws.nws_cmu.ln1_bist_rx_ber_status4 .. nws.nws_cmu.ln1_bist_rx_ber_status6 (3 regs) */
literal|0x041ca694
block|,
comment|/* nws.nws_cmu.ln1_bist_rx_lock_ctrl0 .. nws.nws_cmu.ln1_bist_rx_lock_ctrl3 (4 regs) */
literal|0x051ca6a0
block|,
comment|/* nws.nws_cmu.ln1_bist_rx_loss_lock_ctrl0 .. nws.nws_cmu.ln1_bist_rx_loss_lock_ctrl4 (5 regs) */
literal|0x011ca6b0
block|,
comment|/* nws.nws_cmu.ln1_bist_rx_udp_shift_amount (1 regs) */
literal|0x191ca6b4
block|,
comment|/* nws.nws_cmu.ln1_bist_rx_udp_7_0 .. nws.nws_cmu.ln1_bist_rx_udp_199_192 (25 regs) */
literal|0x021ca700
block|,
comment|/* nws.nws_cmu.ln1_feature_rxterm_cfg0 .. nws.nws_cmu.ln1_feature_rxclkdiv_cfg0 (2 regs) */
literal|0x061ca704
block|,
comment|/* nws.nws_cmu.ln1_feature_ReservedRegister1847 .. nws.nws_cmu.ln1_feature_ReservedRegister1852 (6 regs) */
literal|0x071ca710
block|,
comment|/* nws.nws_cmu.ln1_feature_ReservedRegister1853 .. nws.nws_cmu.ln1_feature_ReservedRegister1859 (7 regs) */
literal|0x0a1ca720
block|,
comment|/* nws.nws_cmu.ln1_feature_ReservedRegister1860 .. nws.nws_cmu.ln1_feature_ReservedRegister1862 (10 regs) */
literal|0x071ca730
block|,
comment|/* nws.nws_cmu.ln1_feature_dfe_cfg .. nws.nws_cmu.ln1_feature_dfe_adapt_tap5_cfg (7 regs) */
literal|0x101ca738
block|,
comment|/* nws.nws_cmu.ln1_feature_adapt_cont_cfg0 .. nws.nws_cmu.ln1_feature_ReservedRegister1874 (16 regs) */
literal|0x011ca750
block|,
comment|/* nws.nws_cmu.ln1_feature_test_cfg0 (1 regs) */
literal|0x081ca758
block|,
comment|/* nws.nws_cmu.ln1_feature_ReservedRegister1875 .. nws.nws_cmu.ln1_feature_ReservedRegister1882 (8 regs) */
literal|0x061ca780
block|,
comment|/* nws.nws_cmu.ln1_lt_tx_fsm_ctrl0 .. nws.nws_cmu.ln1_lt_tx_fsm_ctrl5 (6 regs) */
literal|0x011ca790
block|,
comment|/* nws.nws_cmu.ln1_lt_tx_fsm_status (1 regs) */
literal|0x031ca793
block|,
comment|/* nws.nws_cmu.ln1_lt_tx_prbs_ctrl0 .. nws.nws_cmu.ln1_lt_tx_prbs_ctrl2 (3 regs) */
literal|0x011ca7a0
block|,
comment|/* nws.nws_cmu.ln1_lt_tx_coefficient_update_ctrl (1 regs) */
literal|0x011ca7a2
block|,
comment|/* nws.nws_cmu.ln1_lt_tx_status_report_ctrl (1 regs) */
literal|0x021ca7b0
block|,
comment|/* nws.nws_cmu.ln1_lt_tx_fsm_state_status0 .. nws.nws_cmu.ln1_lt_tx_fsm_state_status1 (2 regs) */
literal|0x011ca7c0
block|,
comment|/* nws.nws_cmu.ln1_lt_rx_ctrl0 (1 regs) */
literal|0x021ca7c2
block|,
comment|/* nws.nws_cmu.ln1_lt_rx_prbs_ctrl0 .. nws.nws_cmu.ln1_lt_rx_prbs_ctrl1 (2 regs) */
literal|0x031ca7c5
block|,
comment|/* nws.nws_cmu.ln1_lt_rx_prbs_status0 .. nws.nws_cmu.ln1_lt_rx_prbs_status2 (3 regs) */
literal|0x011ca7d0
block|,
comment|/* nws.nws_cmu.ln1_lt_rx_frame_ctrl (1 regs) */
literal|0x051ca7d3
block|,
comment|/* nws.nws_cmu.ln1_lt_rx_frame_status0 .. nws.nws_cmu.ln1_lt_rx_frame_status4 (5 regs) */
literal|0x011ca7e0
block|,
comment|/* nws.nws_cmu.ln1_lt_rx_coefficient_update_status (1 regs) */
literal|0x011ca7e2
block|,
comment|/* nws.nws_cmu.ln1_lt_rx_report_status (1 regs) */
literal|0x071ca800
block|,
comment|/* nws.nws_cmu.ln2_top_afe_loopback_ctrl .. nws.nws_cmu.ln2_top_ReservedRegister1888 (7 regs) */
literal|0x011ca810
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1889 (1 regs) */
literal|0x031ca812
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1890 .. nws.nws_cmu.ln2_top_ReservedRegister1892 (3 regs) */
literal|0x011ca816
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1893 (1 regs) */
literal|0x011ca819
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1894 (1 regs) */
literal|0x021ca81b
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1895 .. nws.nws_cmu.ln2_top_ReservedRegister1896 (2 regs) */
literal|0x011ca81e
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1897 (1 regs) */
literal|0x011ca822
block|,
comment|/* nws.nws_cmu.ln2_top_dpl_txdp_ctrl1 (1 regs) */
literal|0x041ca824
block|,
comment|/* nws.nws_cmu.ln2_top_dpl_rxdp_ctrl1 .. nws.nws_cmu.ln2_top_phy_if_status (4 regs) */
literal|0x021ca830
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1900 .. nws.nws_cmu.ln2_top_ReservedRegister1901 (2 regs) */
literal|0x091ca838
block|,
comment|/* nws.nws_cmu.ln2_top_ln_stat_ctrl0 .. nws.nws_cmu.ln2_top_ReservedRegister1908 (9 regs) */
literal|0x021ca842
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1909 .. nws.nws_cmu.ln2_top_ReservedRegister1910 (2 regs) */
literal|0x051ca848
block|,
comment|/* nws.nws_cmu.ln2_top_ReservedRegister1911 .. nws.nws_cmu.ln2_top_ReservedRegister1915 (5 regs) */
literal|0x031ca850
block|,
comment|/* nws.nws_cmu.ln2_top_err_ctrl1 .. nws.nws_cmu.ln2_top_err_ctrl3 (3 regs) */
literal|0x021ca890
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1916 .. nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1917 (2 regs) */
literal|0x021ca8a1
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1918 .. nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1919 (2 regs) */
literal|0x061ca8a6
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1920 .. nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1925 (6 regs) */
literal|0x011ca8ad
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1926 (1 regs) */
literal|0x031ca8b0
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1927 .. nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1929 (3 regs) */
literal|0x011ca8b4
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1930 (1 regs) */
literal|0x021ca8b6
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1931 .. nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1932 (2 regs) */
literal|0x091ca8b9
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1933 .. nws.nws_cmu.ln2_cdr_rxclk_dlpf_status4 (9 regs) */
literal|0x031ca8c4
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_dlpf_status5 .. nws.nws_cmu.ln2_cdr_rxclk_integral_status1 (3 regs) */
literal|0x081ca8c8
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_integral_status2 .. nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1945 (8 regs) */
literal|0x041ca8e0
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1946 .. nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1949 (4 regs) */
literal|0x091ca8e8
block|,
comment|/* nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1950 .. nws.nws_cmu.ln2_cdr_rxclk_ReservedRegister1958 (9 regs) */
literal|0x021ca900
block|,
comment|/* nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1959 .. nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1960 (2 regs) */
literal|0x011ca904
block|,
comment|/* nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1961 (1 regs) */
literal|0x011ca906
block|,
comment|/* nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1962 (1 regs) */
literal|0x031ca90a
block|,
comment|/* nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1963 .. nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1965 (3 regs) */
literal|0x021ca910
block|,
comment|/* nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1966 .. nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1967 (2 regs) */
literal|0x041ca918
block|,
comment|/* nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1968 .. nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1971 (4 regs) */
literal|0x061ca920
block|,
comment|/* nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1972 .. nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1977 (6 regs) */
literal|0x011ca930
block|,
comment|/* nws.nws_cmu.ln2_cdr_refclk_ReservedRegister1978 (1 regs) */
literal|0x0f1ca980
block|,
comment|/* nws.nws_cmu.ln2_aneg_ReservedRegister1979 .. nws.nws_cmu.ln2_aneg_ReservedRegister1990 (15 regs) */
literal|0x011ca990
block|,
comment|/* nws.nws_cmu.ln2_aneg_status0 (1 regs) */
literal|0x021ca994
block|,
comment|/* nws.nws_cmu.ln2_aneg_status_dbg0 .. nws.nws_cmu.ln2_aneg_status_dbg1 (2 regs) */
literal|0x251ca998
block|,
comment|/* nws.nws_cmu.ln2_aneg_base_page0 .. nws.nws_cmu.ln2_aneg_resolution_eee (37 regs) */
literal|0x021ca9be
block|,
comment|/* nws.nws_cmu.ln2_aneg_link_status0 .. nws.nws_cmu.ln2_aneg_link_status1 (2 regs) */
literal|0x031ca9c1
block|,
comment|/* nws.nws_cmu.ln2_eee_ReservedRegister2007 .. nws.nws_cmu.ln2_eee_ReservedRegister2009 (3 regs) */
literal|0x041ca9c5
block|,
comment|/* nws.nws_cmu.ln2_eee_ReservedRegister2010 .. nws.nws_cmu.ln2_eee_ReservedRegister2013 (4 regs) */
literal|0x011caa00
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2014 (1 regs) */
literal|0x021caa02
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2015 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2016 (2 regs) */
literal|0x011caa05
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2017 (1 regs) */
literal|0x011caa07
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2018 (1 regs) */
literal|0x041caa09
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2019 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2022 (4 regs) */
literal|0x041caa0e
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2023 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2026 (4 regs) */
literal|0x0d1caa20
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2027 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2039 (13 regs) */
literal|0x011caa2e
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2040 (1 regs) */
literal|0x0b1caa30
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_agclos_ctrl0 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2050 (11 regs) */
literal|0x021caa3d
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2051 .. nws.nws_cmu.ln2_leq_refclk_ple_att_ctrl1 (2 regs) */
literal|0x071caa40
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_eq_hfg_sql_ctrl0 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2057 (7 regs) */
literal|0x191caa50
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2058 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2082 (25 regs) */
literal|0x071caa70
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_gn_apg_ctrl0 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2088 (7 regs) */
literal|0x091caa80
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_eq_lfg_ctrl0 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2094 (9 regs) */
literal|0x071caa90
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2095 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2101 (7 regs) */
literal|0x061caa98
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2102 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2106 (6 regs) */
literal|0x041caaa0
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2107 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2110 (4 regs) */
literal|0x041caaa6
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2111 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2114 (4 regs) */
literal|0x021caaab
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2115 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2116 (2 regs) */
literal|0x021caaae
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2117 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2118 (2 regs) */
literal|0x021caab8
block|,
comment|/* nws.nws_cmu.ln2_leq_refclk_ReservedRegister2119 .. nws.nws_cmu.ln2_leq_refclk_ReservedRegister2120 (2 regs) */
literal|0x061cab00
block|,
comment|/* nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2121 .. nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2126 (6 regs) */
literal|0x021cab08
block|,
comment|/* nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2127 .. nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2128 (2 regs) */
literal|0x021cab0c
block|,
comment|/* nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2129 .. nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2130 (2 regs) */
literal|0x021cab10
block|,
comment|/* nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2131 .. nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2132 (2 regs) */
literal|0x021cab13
block|,
comment|/* nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2133 .. nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2134 (2 regs) */
literal|0x021cab16
block|,
comment|/* nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2135 .. nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2136 (2 regs) */
literal|0x021cab20
block|,
comment|/* nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2137 .. nws.nws_cmu.ln2_leq_rxclk_ReservedRegister2138 (2 regs) */
literal|0x071cab80
block|,
comment|/* nws.nws_cmu.ln2_drv_refclk_afe_pd_ctrl0 .. nws.nws_cmu.ln2_drv_refclk_ReservedRegister2143 (7 regs) */
literal|0x061cab88
block|,
comment|/* nws.nws_cmu.ln2_drv_refclk_ReservedRegister2144 .. nws.nws_cmu.ln2_drv_refclk_ReservedRegister2149 (6 regs) */
literal|0x0a1cab90
block|,
comment|/* nws.nws_cmu.ln2_drv_refclk_txeq_ctrl0 .. nws.nws_cmu.ln2_drv_refclk_ReservedRegister2154 (10 regs) */
literal|0x011cab9b
block|,
comment|/* nws.nws_cmu.ln2_drv_refclk_ReservedRegister2155 (1 regs) */
literal|0x051cac00
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2156 .. nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2160 (5 regs) */
literal|0x011cac06
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2161 (1 regs) */
literal|0x011cac0a
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2162 (1 regs) */
literal|0x011cac0c
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2163 (1 regs) */
literal|0x011cac0e
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2164 (1 regs) */
literal|0x011cac10
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2165 (1 regs) */
literal|0x011cac12
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2166 (1 regs) */
literal|0x011cac14
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2167 (1 regs) */
literal|0x011cac16
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2168 (1 regs) */
literal|0x021cac18
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2169 .. nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2170 (2 regs) */
literal|0x011cac1b
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2171 (1 regs) */
literal|0x091cac20
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_fsm_ctrl0 .. nws.nws_cmu.ln2_dfe_refclk_fsm_status0 (9 regs) */
literal|0x191cac2a
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_tap_ctrl0 .. nws.nws_cmu.ln2_dfe_refclk_tap_val_status7 (25 regs) */
literal|0x161cac50
block|,
comment|/* nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2179 .. nws.nws_cmu.ln2_dfe_refclk_ReservedRegister2200 (22 regs) */
literal|0x031cac80
block|,
comment|/* nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2201 .. nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2203 (3 regs) */
literal|0x081cac86
block|,
comment|/* nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2204 .. nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2211 (8 regs) */
literal|0x031cac90
block|,
comment|/* nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2212 .. nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2214 (3 regs) */
literal|0x091cac96
block|,
comment|/* nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2215 .. nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2223 (9 regs) */
literal|0x161caca4
block|,
comment|/* nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2224 .. nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2245 (22 regs) */
literal|0x121cacc0
block|,
comment|/* nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2246 .. nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2263 (18 regs) */
literal|0x031cacd6
block|,
comment|/* nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2264 .. nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2266 (3 regs) */
literal|0x0c1cace0
block|,
comment|/* nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2267 .. nws.nws_cmu.ln2_dfe_rxclk_ReservedRegister2278 (12 regs) */
literal|0x061cad00
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_afe_cal_ctrl .. nws.nws_cmu.ln2_los_refclk_run_length_status0 (6 regs) */
literal|0x071cad10
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_filter_ctrl0 .. nws.nws_cmu.ln2_los_refclk_filter_ctrl6 (7 regs) */
literal|0x051cad20
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_ReservedRegister2281 .. nws.nws_cmu.ln2_los_refclk_ReservedRegister2285 (5 regs) */
literal|0x041cad30
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_override_ctrl0 .. nws.nws_cmu.ln2_los_refclk_ReservedRegister2288 (4 regs) */
literal|0x041cad40
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_ReservedRegister2289 .. nws.nws_cmu.ln2_los_refclk_ReservedRegister2292 (4 regs) */
literal|0x011cad46
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_ReservedRegister2293 (1 regs) */
literal|0x011cad51
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_ReservedRegister2294 (1 regs) */
literal|0x011cad59
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_ReservedRegister2295 (1 regs) */
literal|0x011cad60
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_ReservedRegister2296 (1 regs) */
literal|0x021cad70
block|,
comment|/* nws.nws_cmu.ln2_los_refclk_ReservedRegister2297 .. nws.nws_cmu.ln2_los_refclk_status0 (2 regs) */
literal|0x041cad80
block|,
comment|/* nws.nws_cmu.ln2_gcfsm2_ReservedRegister2298 .. nws.nws_cmu.ln2_gcfsm2_ReservedRegister2301 (4 regs) */
literal|0x041cad90
block|,
comment|/* nws.nws_cmu.ln2_gcfsm2_ReservedRegister2302 .. nws.nws_cmu.ln2_gcfsm2_ReservedRegister2305 (4 regs) */
literal|0x071cada0
block|,
comment|/* nws.nws_cmu.ln2_gcfsm2_ReservedRegister2306 .. nws.nws_cmu.ln2_gcfsm2_ReservedRegister2312 (7 regs) */
literal|0x031cadb0
block|,
comment|/* nws.nws_cmu.ln2_gcfsm2_ReservedRegister2313 .. nws.nws_cmu.ln2_gcfsm2_ReservedRegister2315 (3 regs) */
literal|0x091cadc0
block|,
comment|/* nws.nws_cmu.ln2_gcfsm2_ReservedRegister2316 .. nws.nws_cmu.ln2_gcfsm2_ReservedRegister2324 (9 regs) */
literal|0x021cadd0
block|,
comment|/* nws.nws_cmu.ln2_gcfsm2_ReservedRegister2325 .. nws.nws_cmu.ln2_gcfsm2_ReservedRegister2326 (2 regs) */
literal|0x051cae00
block|,
comment|/* nws.nws_cmu.ln2_bist_tx_ctrl .. nws.nws_cmu.ln2_bist_tx_ReservedRegister2330 (5 regs) */
literal|0x081cae06
block|,
comment|/* nws.nws_cmu.ln2_bist_tx_ber_ctrl0 .. nws.nws_cmu.ln2_bist_tx_ber_ctrl7 (8 regs) */
literal|0x011cae20
block|,
comment|/* nws.nws_cmu.ln2_bist_tx_udp_shift_amount (1 regs) */
literal|0x191cae24
block|,
comment|/* nws.nws_cmu.ln2_bist_tx_udp_7_0 .. nws.nws_cmu.ln2_bist_tx_udp_199_192 (25 regs) */
literal|0x011cae80
block|,
comment|/* nws.nws_cmu.ln2_bist_rx_ctrl (1 regs) */
literal|0x011cae84
block|,
comment|/* nws.nws_cmu.ln2_bist_rx_status (1 regs) */
literal|0x031cae88
block|,
comment|/* nws.nws_cmu.ln2_bist_rx_ber_status0 .. nws.nws_cmu.ln2_bist_rx_ber_status2 (3 regs) */
literal|0x031cae8c
block|,
comment|/* nws.nws_cmu.ln2_bist_rx_ber_status4 .. nws.nws_cmu.ln2_bist_rx_ber_status6 (3 regs) */
literal|0x041cae94
block|,
comment|/* nws.nws_cmu.ln2_bist_rx_lock_ctrl0 .. nws.nws_cmu.ln2_bist_rx_lock_ctrl3 (4 regs) */
literal|0x051caea0
block|,
comment|/* nws.nws_cmu.ln2_bist_rx_loss_lock_ctrl0 .. nws.nws_cmu.ln2_bist_rx_loss_lock_ctrl4 (5 regs) */
literal|0x011caeb0
block|,
comment|/* nws.nws_cmu.ln2_bist_rx_udp_shift_amount (1 regs) */
literal|0x191caeb4
block|,
comment|/* nws.nws_cmu.ln2_bist_rx_udp_7_0 .. nws.nws_cmu.ln2_bist_rx_udp_199_192 (25 regs) */
literal|0x021caf00
block|,
comment|/* nws.nws_cmu.ln2_feature_rxterm_cfg0 .. nws.nws_cmu.ln2_feature_rxclkdiv_cfg0 (2 regs) */
literal|0x061caf04
block|,
comment|/* nws.nws_cmu.ln2_feature_ReservedRegister2331 .. nws.nws_cmu.ln2_feature_ReservedRegister2336 (6 regs) */
literal|0x071caf10
block|,
comment|/* nws.nws_cmu.ln2_feature_ReservedRegister2337 .. nws.nws_cmu.ln2_feature_ReservedRegister2343 (7 regs) */
literal|0x0a1caf20
block|,
comment|/* nws.nws_cmu.ln2_feature_ReservedRegister2344 .. nws.nws_cmu.ln2_feature_ReservedRegister2346 (10 regs) */
literal|0x071caf30
block|,
comment|/* nws.nws_cmu.ln2_feature_dfe_cfg .. nws.nws_cmu.ln2_feature_dfe_adapt_tap5_cfg (7 regs) */
literal|0xa0500000
block|,
comment|/* block nws */
literal|0x101caf38
block|,
comment|/* nws.nws_cmu.ln2_feature_adapt_cont_cfg0 .. nws.nws_cmu.ln2_feature_ReservedRegister2358 (16 regs) */
literal|0x011caf50
block|,
comment|/* nws.nws_cmu.ln2_feature_test_cfg0 (1 regs) */
literal|0x081caf58
block|,
comment|/* nws.nws_cmu.ln2_feature_ReservedRegister2359 .. nws.nws_cmu.ln2_feature_ReservedRegister2366 (8 regs) */
literal|0x061caf80
block|,
comment|/* nws.nws_cmu.ln2_lt_tx_fsm_ctrl0 .. nws.nws_cmu.ln2_lt_tx_fsm_ctrl5 (6 regs) */
literal|0x011caf90
block|,
comment|/* nws.nws_cmu.ln2_lt_tx_fsm_status (1 regs) */
literal|0x031caf93
block|,
comment|/* nws.nws_cmu.ln2_lt_tx_prbs_ctrl0 .. nws.nws_cmu.ln2_lt_tx_prbs_ctrl2 (3 regs) */
literal|0x011cafa0
block|,
comment|/* nws.nws_cmu.ln2_lt_tx_coefficient_update_ctrl (1 regs) */
literal|0x011cafa2
block|,
comment|/* nws.nws_cmu.ln2_lt_tx_status_report_ctrl (1 regs) */
literal|0x021cafb0
block|,
comment|/* nws.nws_cmu.ln2_lt_tx_fsm_state_status0 .. nws.nws_cmu.ln2_lt_tx_fsm_state_status1 (2 regs) */
literal|0x011cafc0
block|,
comment|/* nws.nws_cmu.ln2_lt_rx_ctrl0 (1 regs) */
literal|0x021cafc2
block|,
comment|/* nws.nws_cmu.ln2_lt_rx_prbs_ctrl0 .. nws.nws_cmu.ln2_lt_rx_prbs_ctrl1 (2 regs) */
literal|0x031cafc5
block|,
comment|/* nws.nws_cmu.ln2_lt_rx_prbs_status0 .. nws.nws_cmu.ln2_lt_rx_prbs_status2 (3 regs) */
literal|0x011cafd0
block|,
comment|/* nws.nws_cmu.ln2_lt_rx_frame_ctrl (1 regs) */
literal|0x051cafd3
block|,
comment|/* nws.nws_cmu.ln2_lt_rx_frame_status0 .. nws.nws_cmu.ln2_lt_rx_frame_status4 (5 regs) */
literal|0x011cafe0
block|,
comment|/* nws.nws_cmu.ln2_lt_rx_coefficient_update_status (1 regs) */
literal|0x011cafe2
block|,
comment|/* nws.nws_cmu.ln2_lt_rx_report_status (1 regs) */
literal|0x071cb000
block|,
comment|/* nws.nws_cmu.ln3_top_afe_loopback_ctrl .. nws.nws_cmu.ln3_top_ReservedRegister2372 (7 regs) */
literal|0x011cb010
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2373 (1 regs) */
literal|0x031cb012
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2374 .. nws.nws_cmu.ln3_top_ReservedRegister2376 (3 regs) */
literal|0x011cb016
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2377 (1 regs) */
literal|0x011cb019
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2378 (1 regs) */
literal|0x021cb01b
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2379 .. nws.nws_cmu.ln3_top_ReservedRegister2380 (2 regs) */
literal|0x011cb01e
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2381 (1 regs) */
literal|0x011cb022
block|,
comment|/* nws.nws_cmu.ln3_top_dpl_txdp_ctrl1 (1 regs) */
literal|0x041cb024
block|,
comment|/* nws.nws_cmu.ln3_top_dpl_rxdp_ctrl1 .. nws.nws_cmu.ln3_top_phy_if_status (4 regs) */
literal|0x021cb030
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2384 .. nws.nws_cmu.ln3_top_ReservedRegister2385 (2 regs) */
literal|0x091cb038
block|,
comment|/* nws.nws_cmu.ln3_top_ln_stat_ctrl0 .. nws.nws_cmu.ln3_top_ReservedRegister2392 (9 regs) */
literal|0x021cb042
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2393 .. nws.nws_cmu.ln3_top_ReservedRegister2394 (2 regs) */
literal|0x051cb048
block|,
comment|/* nws.nws_cmu.ln3_top_ReservedRegister2395 .. nws.nws_cmu.ln3_top_ReservedRegister2399 (5 regs) */
literal|0x031cb050
block|,
comment|/* nws.nws_cmu.ln3_top_err_ctrl1 .. nws.nws_cmu.ln3_top_err_ctrl3 (3 regs) */
literal|0x021cb090
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2400 .. nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2401 (2 regs) */
literal|0x021cb0a1
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2402 .. nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2403 (2 regs) */
literal|0x061cb0a6
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2404 .. nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2409 (6 regs) */
literal|0x011cb0ad
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2410 (1 regs) */
literal|0x031cb0b0
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2411 .. nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2413 (3 regs) */
literal|0x011cb0b4
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2414 (1 regs) */
literal|0x021cb0b6
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2415 .. nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2416 (2 regs) */
literal|0x091cb0b9
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2417 .. nws.nws_cmu.ln3_cdr_rxclk_dlpf_status4 (9 regs) */
literal|0x031cb0c4
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_dlpf_status5 .. nws.nws_cmu.ln3_cdr_rxclk_integral_status1 (3 regs) */
literal|0x081cb0c8
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_integral_status2 .. nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2429 (8 regs) */
literal|0x041cb0e0
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2430 .. nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2433 (4 regs) */
literal|0x091cb0e8
block|,
comment|/* nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2434 .. nws.nws_cmu.ln3_cdr_rxclk_ReservedRegister2442 (9 regs) */
literal|0x021cb100
block|,
comment|/* nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2443 .. nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2444 (2 regs) */
literal|0x011cb104
block|,
comment|/* nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2445 (1 regs) */
literal|0x011cb106
block|,
comment|/* nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2446 (1 regs) */
literal|0x031cb10a
block|,
comment|/* nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2447 .. nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2449 (3 regs) */
literal|0x021cb110
block|,
comment|/* nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2450 .. nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2451 (2 regs) */
literal|0x041cb118
block|,
comment|/* nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2452 .. nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2455 (4 regs) */
literal|0x061cb120
block|,
comment|/* nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2456 .. nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2461 (6 regs) */
literal|0x011cb130
block|,
comment|/* nws.nws_cmu.ln3_cdr_refclk_ReservedRegister2462 (1 regs) */
literal|0x0f1cb180
block|,
comment|/* nws.nws_cmu.ln3_aneg_ReservedRegister2463 .. nws.nws_cmu.ln3_aneg_ReservedRegister2474 (15 regs) */
literal|0x011cb190
block|,
comment|/* nws.nws_cmu.ln3_aneg_status0 (1 regs) */
literal|0x021cb194
block|,
comment|/* nws.nws_cmu.ln3_aneg_status_dbg0 .. nws.nws_cmu.ln3_aneg_status_dbg1 (2 regs) */
literal|0x251cb198
block|,
comment|/* nws.nws_cmu.ln3_aneg_base_page0 .. nws.nws_cmu.ln3_aneg_resolution_eee (37 regs) */
literal|0x021cb1be
block|,
comment|/* nws.nws_cmu.ln3_aneg_link_status0 .. nws.nws_cmu.ln3_aneg_link_status1 (2 regs) */
literal|0x031cb1c1
block|,
comment|/* nws.nws_cmu.ln3_eee_ReservedRegister2491 .. nws.nws_cmu.ln3_eee_ReservedRegister2493 (3 regs) */
literal|0x041cb1c5
block|,
comment|/* nws.nws_cmu.ln3_eee_ReservedRegister2494 .. nws.nws_cmu.ln3_eee_ReservedRegister2497 (4 regs) */
literal|0x011cb200
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2498 (1 regs) */
literal|0x021cb202
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2499 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2500 (2 regs) */
literal|0x011cb205
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2501 (1 regs) */
literal|0x011cb207
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2502 (1 regs) */
literal|0x041cb209
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2503 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2506 (4 regs) */
literal|0x041cb20e
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2507 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2510 (4 regs) */
literal|0x0d1cb220
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2511 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2523 (13 regs) */
literal|0x011cb22e
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2524 (1 regs) */
literal|0x0b1cb230
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_agclos_ctrl0 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2534 (11 regs) */
literal|0x021cb23d
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2535 .. nws.nws_cmu.ln3_leq_refclk_ple_att_ctrl1 (2 regs) */
literal|0x071cb240
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_eq_hfg_sql_ctrl0 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2541 (7 regs) */
literal|0x191cb250
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2542 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2566 (25 regs) */
literal|0x071cb270
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_gn_apg_ctrl0 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2572 (7 regs) */
literal|0x091cb280
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_eq_lfg_ctrl0 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2578 (9 regs) */
literal|0x071cb290
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2579 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2585 (7 regs) */
literal|0x061cb298
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2586 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2590 (6 regs) */
literal|0x041cb2a0
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2591 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2594 (4 regs) */
literal|0x041cb2a6
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2595 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2598 (4 regs) */
literal|0x021cb2ab
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2599 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2600 (2 regs) */
literal|0x021cb2ae
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2601 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2602 (2 regs) */
literal|0x021cb2b8
block|,
comment|/* nws.nws_cmu.ln3_leq_refclk_ReservedRegister2603 .. nws.nws_cmu.ln3_leq_refclk_ReservedRegister2604 (2 regs) */
literal|0x061cb300
block|,
comment|/* nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2605 .. nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2610 (6 regs) */
literal|0x021cb308
block|,
comment|/* nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2611 .. nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2612 (2 regs) */
literal|0x021cb30c
block|,
comment|/* nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2613 .. nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2614 (2 regs) */
literal|0x021cb310
block|,
comment|/* nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2615 .. nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2616 (2 regs) */
literal|0x021cb313
block|,
comment|/* nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2617 .. nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2618 (2 regs) */
literal|0x021cb316
block|,
comment|/* nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2619 .. nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2620 (2 regs) */
literal|0x021cb320
block|,
comment|/* nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2621 .. nws.nws_cmu.ln3_leq_rxclk_ReservedRegister2622 (2 regs) */
literal|0x071cb380
block|,
comment|/* nws.nws_cmu.ln3_drv_refclk_afe_pd_ctrl0 .. nws.nws_cmu.ln3_drv_refclk_ReservedRegister2627 (7 regs) */
literal|0x061cb388
block|,
comment|/* nws.nws_cmu.ln3_drv_refclk_ReservedRegister2628 .. nws.nws_cmu.ln3_drv_refclk_ReservedRegister2633 (6 regs) */
literal|0x0a1cb390
block|,
comment|/* nws.nws_cmu.ln3_drv_refclk_txeq_ctrl0 .. nws.nws_cmu.ln3_drv_refclk_ReservedRegister2638 (10 regs) */
literal|0x011cb39b
block|,
comment|/* nws.nws_cmu.ln3_drv_refclk_ReservedRegister2639 (1 regs) */
literal|0x051cb400
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2640 .. nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2644 (5 regs) */
literal|0x011cb406
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2645 (1 regs) */
literal|0x011cb40a
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2646 (1 regs) */
literal|0x011cb40c
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2647 (1 regs) */
literal|0x011cb40e
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2648 (1 regs) */
literal|0x011cb410
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2649 (1 regs) */
literal|0x011cb412
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2650 (1 regs) */
literal|0x011cb414
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2651 (1 regs) */
literal|0x011cb416
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2652 (1 regs) */
literal|0x021cb418
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2653 .. nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2654 (2 regs) */
literal|0x011cb41b
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2655 (1 regs) */
literal|0x091cb420
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_fsm_ctrl0 .. nws.nws_cmu.ln3_dfe_refclk_fsm_status0 (9 regs) */
literal|0x191cb42a
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_tap_ctrl0 .. nws.nws_cmu.ln3_dfe_refclk_tap_val_status7 (25 regs) */
literal|0x161cb450
block|,
comment|/* nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2663 .. nws.nws_cmu.ln3_dfe_refclk_ReservedRegister2684 (22 regs) */
literal|0x031cb480
block|,
comment|/* nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2685 .. nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2687 (3 regs) */
literal|0x081cb486
block|,
comment|/* nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2688 .. nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2695 (8 regs) */
literal|0x031cb490
block|,
comment|/* nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2696 .. nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2698 (3 regs) */
literal|0x091cb496
block|,
comment|/* nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2699 .. nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2707 (9 regs) */
literal|0x161cb4a4
block|,
comment|/* nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2708 .. nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2729 (22 regs) */
literal|0x121cb4c0
block|,
comment|/* nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2730 .. nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2747 (18 regs) */
literal|0x031cb4d6
block|,
comment|/* nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2748 .. nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2750 (3 regs) */
literal|0x0c1cb4e0
block|,
comment|/* nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2751 .. nws.nws_cmu.ln3_dfe_rxclk_ReservedRegister2762 (12 regs) */
literal|0x061cb500
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_afe_cal_ctrl .. nws.nws_cmu.ln3_los_refclk_run_length_status0 (6 regs) */
literal|0x071cb510
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_filter_ctrl0 .. nws.nws_cmu.ln3_los_refclk_filter_ctrl6 (7 regs) */
literal|0x051cb520
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_ReservedRegister2765 .. nws.nws_cmu.ln3_los_refclk_ReservedRegister2769 (5 regs) */
literal|0x041cb530
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_override_ctrl0 .. nws.nws_cmu.ln3_los_refclk_ReservedRegister2772 (4 regs) */
literal|0x041cb540
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_ReservedRegister2773 .. nws.nws_cmu.ln3_los_refclk_ReservedRegister2776 (4 regs) */
literal|0x011cb546
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_ReservedRegister2777 (1 regs) */
literal|0x011cb551
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_ReservedRegister2778 (1 regs) */
literal|0x011cb559
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_ReservedRegister2779 (1 regs) */
literal|0x011cb560
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_ReservedRegister2780 (1 regs) */
literal|0x021cb570
block|,
comment|/* nws.nws_cmu.ln3_los_refclk_ReservedRegister2781 .. nws.nws_cmu.ln3_los_refclk_status0 (2 regs) */
literal|0x041cb580
block|,
comment|/* nws.nws_cmu.ln3_gcfsm2_ReservedRegister2782 .. nws.nws_cmu.ln3_gcfsm2_ReservedRegister2785 (4 regs) */
literal|0x041cb590
block|,
comment|/* nws.nws_cmu.ln3_gcfsm2_ReservedRegister2786 .. nws.nws_cmu.ln3_gcfsm2_ReservedRegister2789 (4 regs) */
literal|0x071cb5a0
block|,
comment|/* nws.nws_cmu.ln3_gcfsm2_ReservedRegister2790 .. nws.nws_cmu.ln3_gcfsm2_ReservedRegister2796 (7 regs) */
literal|0x031cb5b0
block|,
comment|/* nws.nws_cmu.ln3_gcfsm2_ReservedRegister2797 .. nws.nws_cmu.ln3_gcfsm2_ReservedRegister2799 (3 regs) */
literal|0x091cb5c0
block|,
comment|/* nws.nws_cmu.ln3_gcfsm2_ReservedRegister2800 .. nws.nws_cmu.ln3_gcfsm2_ReservedRegister2808 (9 regs) */
literal|0x021cb5d0
block|,
comment|/* nws.nws_cmu.ln3_gcfsm2_ReservedRegister2809 .. nws.nws_cmu.ln3_gcfsm2_ReservedRegister2810 (2 regs) */
literal|0x051cb600
block|,
comment|/* nws.nws_cmu.ln3_bist_tx_ctrl .. nws.nws_cmu.ln3_bist_tx_ReservedRegister2814 (5 regs) */
literal|0x081cb606
block|,
comment|/* nws.nws_cmu.ln3_bist_tx_ber_ctrl0 .. nws.nws_cmu.ln3_bist_tx_ber_ctrl7 (8 regs) */
literal|0x011cb620
block|,
comment|/* nws.nws_cmu.ln3_bist_tx_udp_shift_amount (1 regs) */
literal|0x191cb624
block|,
comment|/* nws.nws_cmu.ln3_bist_tx_udp_7_0 .. nws.nws_cmu.ln3_bist_tx_udp_199_192 (25 regs) */
literal|0x011cb680
block|,
comment|/* nws.nws_cmu.ln3_bist_rx_ctrl (1 regs) */
literal|0x011cb684
block|,
comment|/* nws.nws_cmu.ln3_bist_rx_status (1 regs) */
literal|0x031cb688
block|,
comment|/* nws.nws_cmu.ln3_bist_rx_ber_status0 .. nws.nws_cmu.ln3_bist_rx_ber_status2 (3 regs) */
literal|0x031cb68c
block|,
comment|/* nws.nws_cmu.ln3_bist_rx_ber_status4 .. nws.nws_cmu.ln3_bist_rx_ber_status6 (3 regs) */
literal|0x041cb694
block|,
comment|/* nws.nws_cmu.ln3_bist_rx_lock_ctrl0 .. nws.nws_cmu.ln3_bist_rx_lock_ctrl3 (4 regs) */
literal|0x051cb6a0
block|,
comment|/* nws.nws_cmu.ln3_bist_rx_loss_lock_ctrl0 .. nws.nws_cmu.ln3_bist_rx_loss_lock_ctrl4 (5 regs) */
literal|0x011cb6b0
block|,
comment|/* nws.nws_cmu.ln3_bist_rx_udp_shift_amount (1 regs) */
literal|0x191cb6b4
block|,
comment|/* nws.nws_cmu.ln3_bist_rx_udp_7_0 .. nws.nws_cmu.ln3_bist_rx_udp_199_192 (25 regs) */
literal|0x021cb700
block|,
comment|/* nws.nws_cmu.ln3_feature_rxterm_cfg0 .. nws.nws_cmu.ln3_feature_rxclkdiv_cfg0 (2 regs) */
literal|0x061cb704
block|,
comment|/* nws.nws_cmu.ln3_feature_ReservedRegister2815 .. nws.nws_cmu.ln3_feature_ReservedRegister2820 (6 regs) */
literal|0x071cb710
block|,
comment|/* nws.nws_cmu.ln3_feature_ReservedRegister2821 .. nws.nws_cmu.ln3_feature_ReservedRegister2827 (7 regs) */
literal|0x0a1cb720
block|,
comment|/* nws.nws_cmu.ln3_feature_ReservedRegister2828 .. nws.nws_cmu.ln3_feature_ReservedRegister2830 (10 regs) */
literal|0x071cb730
block|,
comment|/* nws.nws_cmu.ln3_feature_dfe_cfg .. nws.nws_cmu.ln3_feature_dfe_adapt_tap5_cfg (7 regs) */
literal|0x101cb738
block|,
comment|/* nws.nws_cmu.ln3_feature_adapt_cont_cfg0 .. nws.nws_cmu.ln3_feature_ReservedRegister2842 (16 regs) */
literal|0x011cb750
block|,
comment|/* nws.nws_cmu.ln3_feature_test_cfg0 (1 regs) */
literal|0x081cb758
block|,
comment|/* nws.nws_cmu.ln3_feature_ReservedRegister2843 .. nws.nws_cmu.ln3_feature_ReservedRegister2850 (8 regs) */
literal|0x061cb780
block|,
comment|/* nws.nws_cmu.ln3_lt_tx_fsm_ctrl0 .. nws.nws_cmu.ln3_lt_tx_fsm_ctrl5 (6 regs) */
literal|0x011cb790
block|,
comment|/* nws.nws_cmu.ln3_lt_tx_fsm_status (1 regs) */
literal|0x031cb793
block|,
comment|/* nws.nws_cmu.ln3_lt_tx_prbs_ctrl0 .. nws.nws_cmu.ln3_lt_tx_prbs_ctrl2 (3 regs) */
literal|0x011cb7a0
block|,
comment|/* nws.nws_cmu.ln3_lt_tx_coefficient_update_ctrl (1 regs) */
literal|0x011cb7a2
block|,
comment|/* nws.nws_cmu.ln3_lt_tx_status_report_ctrl (1 regs) */
literal|0x021cb7b0
block|,
comment|/* nws.nws_cmu.ln3_lt_tx_fsm_state_status0 .. nws.nws_cmu.ln3_lt_tx_fsm_state_status1 (2 regs) */
literal|0x011cb7c0
block|,
comment|/* nws.nws_cmu.ln3_lt_rx_ctrl0 (1 regs) */
literal|0x021cb7c2
block|,
comment|/* nws.nws_cmu.ln3_lt_rx_prbs_ctrl0 .. nws.nws_cmu.ln3_lt_rx_prbs_ctrl1 (2 regs) */
literal|0x031cb7c5
block|,
comment|/* nws.nws_cmu.ln3_lt_rx_prbs_status0 .. nws.nws_cmu.ln3_lt_rx_prbs_status2 (3 regs) */
literal|0x011cb7d0
block|,
comment|/* nws.nws_cmu.ln3_lt_rx_frame_ctrl (1 regs) */
literal|0x051cb7d3
block|,
comment|/* nws.nws_cmu.ln3_lt_rx_frame_status0 .. nws.nws_cmu.ln3_lt_rx_frame_status4 (5 regs) */
literal|0x011cb7e0
block|,
comment|/* nws.nws_cmu.ln3_lt_rx_coefficient_update_status (1 regs) */
literal|0x011cb7e2
block|,
comment|/* nws.nws_cmu.ln3_lt_rx_report_status (1 regs) */
literal|0x044c00fd
block|,
comment|/* mode (!bb)&(!fpga), block wol */
literal|0x02180010
block|,
comment|/* wol.INT_STS_0 .. wol.INT_MASK_0 (2 regs) */
literal|0x05180050
block|,
comment|/* wol.dbg_select .. wol.dbg_force_frame (5 regs) */
literal|0x06182067
block|,
comment|/* wol.tag_len_0 .. wol.tag_len_5 (6 regs) */
literal|0x0118206e
block|,
comment|/* wol.eco_reserved (1 regs) */
literal|0x03510000
block|,
comment|/* block ms */
literal|0x061a8000
block|,
comment|/* ms.common_control .. ms.eco_reserved (6 regs) */
literal|0x021a8060
block|,
comment|/* ms.INT_STS .. ms.INT_MASK (2 regs) */
literal|0x0b1a808a
block|,
comment|/* ms.dbg_select .. ms.dbg_fw_trigger_enable (11 regs) */
literal|0x02520000
block|,
comment|/* block phy_pcie */
literal|0x0c18a000
block|,
comment|/* phy_pcie.eco_reserved .. phy_pcie.dbg_status (12 regs) */
literal|0x0518a7fa
block|,
comment|/* phy_pcie.dbg_select .. phy_pcie.dbg_force_frame (5 regs) */
literal|0x044e0107
block|,
comment|/* mode bb&(!(!asic)), block ipc */
literal|0x03008123
block|,
comment|/* ipc.mdio_comm .. ipc.mdio_mode (3 regs) */
literal|0x0200812a
block|,
comment|/* ipc.freq_main .. ipc.freq_storm (2 regs) */
literal|0x0d00812d
block|,
comment|/* ipc.free_running_cntr_0 .. ipc.hw_straps (13 regs) */
literal|0x03008142
block|,
comment|/* ipc.jtag_compliance .. ipc.INT_MASK_0 (3 regs) */
literal|0x2c510023
block|,
comment|/* mode (!bb)&(!(fpga|(!asic))), block ms */
literal|0x241a9000
block|,
comment|/* ms.ms_cmu.ahb_cmu_csr_0_x0 .. ms.ms_cmu.ahb_cmu_csr_0_x35 (36 regs) */
literal|0x4f1a9038
block|,
comment|/* ms.ms_cmu.ahb_cmu_csr_0_x56 .. ms.ms_cmu.ahb_cmu_csr_0_x134 (79 regs) */
literal|0x011a9090
block|,
comment|/* ms.ms_cmu.ahb_cmu_csr_0_x144 (1 regs) */
literal|0x041a9092
block|,
comment|/* ms.ms_cmu.ahb_cmu_csr_0_x146 .. ms.ms_cmu.ahb_cmu_csr_0_x149 (4 regs) */
literal|0x021a9099
block|,
comment|/* ms.ms_cmu.ahb_cmu_csr_0_x153 .. ms.ms_cmu.ahb_cmu_csr_0_x154 (2 regs) */
literal|0x2a1a90a1
block|,
comment|/* ms.ms_cmu.ahb_cmu_csr_0_x161 .. ms.ms_cmu.ahb_cmu_csr_0_x202 (42 regs) */
literal|0x011a90d2
block|,
comment|/* ms.ms_cmu.ahb_cmu_csr_0_x210 (1 regs) */
literal|0x061a9400
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x0 .. ms.ms_cmu.ahb_lane_csr_1_x5 (6 regs) */
literal|0x401a9407
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x7 .. ms.ms_cmu.ahb_lane_csr_1_x70 (64 regs) */
literal|0x221a9448
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x72 .. ms.ms_cmu.ahb_lane_csr_1_x105 (34 regs) */
literal|0x0e1a9473
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x115 .. ms.ms_cmu.ahb_lane_csr_1_x128 (14 regs) */
literal|0x1b1a9482
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x130 .. ms.ms_cmu.ahb_lane_csr_1_x156 (27 regs) */
literal|0x021a949e
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x158 .. ms.ms_cmu.ahb_lane_csr_1_x159 (2 regs) */
literal|0x011a94a1
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x161 (1 regs) */
literal|0x011a94a7
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x167 (1 regs) */
literal|0x551a94c9
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x201 .. ms.ms_cmu.ahb_lane_csr_1_x285 (85 regs) */
literal|0x081a952d
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x301 .. ms.ms_cmu.ahb_lane_csr_1_x308 (8 regs) */
literal|0x011a9536
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_x310 (1 regs) */
literal|0x121a9539
block|,
comment|/* ms.ms_cmu.ahb_lane_csr_1_ReservedReg53 .. ms.ms_cmu.ahb_lane_csr_1_x330 (18 regs) */
literal|0x021a9a00
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x0 .. ms.ms_cmu.ahb_comlane_csr_5_x1 (2 regs) */
literal|0x051a9a04
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x4 .. ms.ms_cmu.ahb_comlane_csr_5_x8 (5 regs) */
literal|0x011a9a1f
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x31 (1 regs) */
literal|0x031a9a2a
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_ReservedReg17 .. ms.ms_cmu.ahb_comlane_csr_5_x44 (3 regs) */
literal|0x851a9a31
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x49 .. ms.ms_cmu.ahb_comlane_csr_5_x181 (133 regs) */
literal|0x341a9ad2
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x210 .. ms.ms_cmu.ahb_comlane_csr_5_x261 (52 regs) */
literal|0x0d1a9b07
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x263 .. ms.ms_cmu.ahb_comlane_csr_5_x275 (13 regs) */
literal|0x011a9b19
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x281 (1 regs) */
literal|0x021a9b28
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x296 .. ms.ms_cmu.ahb_comlane_csr_5_x297 (2 regs) */
literal|0x011a9b2d
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x301 (1 regs) */
literal|0x061a9b2f
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_ReservedReg23 .. ms.ms_cmu.ahb_comlane_csr_5_x308 (6 regs) */
literal|0x061a9b36
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x310 .. ms.ms_cmu.ahb_comlane_csr_5_x315 (6 regs) */
literal|0x061a9b3d
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_ReservedReg24 .. ms.ms_cmu.ahb_comlane_csr_5_x322 (6 regs) */
literal|0x471a9b44
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x324 .. ms.ms_cmu.ahb_comlane_csr_5_x394 (71 regs) */
literal|0x031a9b91
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x401 .. ms.ms_cmu.ahb_comlane_csr_5_x403 (3 regs) */
literal|0x041a9b96
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x406 .. ms.ms_cmu.ahb_comlane_csr_5_x409 (4 regs) */
literal|0x011a9b9c
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_ReservedReg40 (1 regs) */
literal|0x361a9bbe
block|,
comment|/* ms.ms_cmu.ahb_comlane_csr_5_x446 .. ms.ms_cmu.ahb_comlane_csr_5_x499 (54 regs) */
literal|0x241a9c00
block|,
comment|/* ms.ms_cmu.ahb_cmu1_csr_6_x0 .. ms.ms_cmu.ahb_cmu1_csr_6_x35 (36 regs) */
literal|0x4f1a9c38
block|,
comment|/* ms.ms_cmu.ahb_cmu1_csr_6_x56 .. ms.ms_cmu.ahb_cmu1_csr_6_x134 (79 regs) */
literal|0x011a9c90
block|,
comment|/* ms.ms_cmu.ahb_cmu1_csr_6_x144 (1 regs) */
literal|0x041a9c92
block|,
comment|/* ms.ms_cmu.ahb_cmu1_csr_6_x146 .. ms.ms_cmu.ahb_cmu1_csr_6_x149 (4 regs) */
literal|0x021a9c99
block|,
comment|/* ms.ms_cmu.ahb_cmu1_csr_6_x153 .. ms.ms_cmu.ahb_cmu1_csr_6_x154 (2 regs) */
literal|0x2a1a9ca1
block|,
comment|/* ms.ms_cmu.ahb_cmu1_csr_6_x161 .. ms.ms_cmu.ahb_cmu1_csr_6_x202 (42 regs) */
literal|0x011a9cd2
block|,
comment|/* ms.ms_cmu.ahb_cmu1_csr_6_x210 (1 regs) */
literal|0x90520000
block|,
comment|/* block phy_pcie */
literal|0x23188000
block|,
comment|/* phy_pcie.phy0.ahb_cmu_csr_0_x0 .. phy_pcie.phy0.ahb_cmu_csr_0_x34 (35 regs) */
literal|0x2f188038
block|,
comment|/* phy_pcie.phy0.ahb_cmu_csr_0_x56 .. phy_pcie.phy0.ahb_cmu_csr_0_x102 (47 regs) */
literal|0x2818806c
block|,
comment|/* phy_pcie.phy0.ahb_cmu_csr_0_x108 .. phy_pcie.phy0.ahb_cmu_csr_0_x147 (40 regs) */
literal|0x06188095
block|,
comment|/* phy_pcie.phy0.ahb_cmu_csr_0_x149 .. phy_pcie.phy0.ahb_cmu_csr_0_x154 (6 regs) */
literal|0x1c1880a1
block|,
comment|/* phy_pcie.phy0.ahb_cmu_csr_0_x161 .. phy_pcie.phy0.ahb_cmu_csr_0_x188 (28 regs) */
literal|0x141880bf
block|,
comment|/* phy_pcie.phy0.ahb_cmu_csr_0_x191 .. phy_pcie.phy0.ahb_cmu_csr_0_x210 (20 regs) */
literal|0x06188200
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x0 .. phy_pcie.phy0.ahb_lane_csr_1_x5 (6 regs) */
literal|0x38188207
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x7 .. phy_pcie.phy0.ahb_lane_csr_1_x62 (56 regs) */
literal|0x21188241
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x65 .. phy_pcie.phy0.ahb_lane_csr_1_x97 (33 regs) */
literal|0x11188263
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x99 .. phy_pcie.phy0.ahb_lane_csr_1_x115 (17 regs) */
literal|0x0a188277
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x119 .. phy_pcie.phy0.ahb_lane_csr_1_x128 (10 regs) */
literal|0x29188282
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x130 .. phy_pcie.phy0.ahb_lane_csr_1_x170 (41 regs) */
literal|0x081882c9
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x201 .. phy_pcie.phy0.ahb_lane_csr_1_x208 (8 regs) */
literal|0x051882d5
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x213 .. phy_pcie.phy0.ahb_lane_csr_1_x217 (5 regs) */
literal|0x421882dc
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x220 .. phy_pcie.phy0.ahb_lane_csr_1_x285 (66 regs) */
literal|0x1b18832d
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x301 .. phy_pcie.phy0.ahb_lane_csr_1_x327 (27 regs) */
literal|0x0118834a
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_1_x330 (1 regs) */
literal|0x06188400
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x0 .. phy_pcie.phy0.ahb_lane_csr_2_x5 (6 regs) */
literal|0x38188407
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x7 .. phy_pcie.phy0.ahb_lane_csr_2_x62 (56 regs) */
literal|0x21188441
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x65 .. phy_pcie.phy0.ahb_lane_csr_2_x97 (33 regs) */
literal|0x11188463
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x99 .. phy_pcie.phy0.ahb_lane_csr_2_x115 (17 regs) */
literal|0x0a188477
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x119 .. phy_pcie.phy0.ahb_lane_csr_2_x128 (10 regs) */
literal|0x29188482
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x130 .. phy_pcie.phy0.ahb_lane_csr_2_x170 (41 regs) */
literal|0x081884c9
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x201 .. phy_pcie.phy0.ahb_lane_csr_2_x208 (8 regs) */
literal|0x051884d5
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x213 .. phy_pcie.phy0.ahb_lane_csr_2_x217 (5 regs) */
literal|0x421884dc
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x220 .. phy_pcie.phy0.ahb_lane_csr_2_x285 (66 regs) */
literal|0x1b18852d
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x301 .. phy_pcie.phy0.ahb_lane_csr_2_x327 (27 regs) */
literal|0x0118854a
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_2_x330 (1 regs) */
literal|0x06188600
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x0 .. phy_pcie.phy0.ahb_lane_csr_3_x5 (6 regs) */
literal|0x38188607
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x7 .. phy_pcie.phy0.ahb_lane_csr_3_x62 (56 regs) */
literal|0x21188641
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x65 .. phy_pcie.phy0.ahb_lane_csr_3_x97 (33 regs) */
literal|0x11188663
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x99 .. phy_pcie.phy0.ahb_lane_csr_3_x115 (17 regs) */
literal|0x0a188677
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x119 .. phy_pcie.phy0.ahb_lane_csr_3_x128 (10 regs) */
literal|0x29188682
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x130 .. phy_pcie.phy0.ahb_lane_csr_3_x170 (41 regs) */
literal|0x081886c9
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x201 .. phy_pcie.phy0.ahb_lane_csr_3_x208 (8 regs) */
literal|0x051886d5
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x213 .. phy_pcie.phy0.ahb_lane_csr_3_x217 (5 regs) */
literal|0x421886dc
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x220 .. phy_pcie.phy0.ahb_lane_csr_3_x285 (66 regs) */
literal|0x1b18872d
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x301 .. phy_pcie.phy0.ahb_lane_csr_3_x327 (27 regs) */
literal|0x0118874a
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_3_x330 (1 regs) */
literal|0x06188800
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x0 .. phy_pcie.phy0.ahb_lane_csr_4_x5 (6 regs) */
literal|0x38188807
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x7 .. phy_pcie.phy0.ahb_lane_csr_4_x62 (56 regs) */
literal|0x21188841
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x65 .. phy_pcie.phy0.ahb_lane_csr_4_x97 (33 regs) */
literal|0x11188863
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x99 .. phy_pcie.phy0.ahb_lane_csr_4_x115 (17 regs) */
literal|0x0a188877
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x119 .. phy_pcie.phy0.ahb_lane_csr_4_x128 (10 regs) */
literal|0x29188882
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x130 .. phy_pcie.phy0.ahb_lane_csr_4_x170 (41 regs) */
literal|0x081888c9
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x201 .. phy_pcie.phy0.ahb_lane_csr_4_x208 (8 regs) */
literal|0x051888d5
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x213 .. phy_pcie.phy0.ahb_lane_csr_4_x217 (5 regs) */
literal|0x421888dc
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x220 .. phy_pcie.phy0.ahb_lane_csr_4_x285 (66 regs) */
literal|0x1b18892d
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x301 .. phy_pcie.phy0.ahb_lane_csr_4_x327 (27 regs) */
literal|0x0118894a
block|,
comment|/* phy_pcie.phy0.ahb_lane_csr_4_x330 (1 regs) */
literal|0x05188a00
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x0 .. phy_pcie.phy0.ahb_comlane_csr_5_x4 (5 regs) */
literal|0x15188a06
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x6 .. phy_pcie.phy0.ahb_comlane_csr_5_x26 (21 regs) */
literal|0x07188a1d
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x29 .. phy_pcie.phy0.ahb_comlane_csr_5_x35 (7 regs) */
literal|0x04188a26
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x38 .. phy_pcie.phy0.ahb_comlane_csr_5_x41 (4 regs) */
literal|0x78188a2b
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x43 .. phy_pcie.phy0.ahb_comlane_csr_5_x162 (120 regs) */
literal|0x5e188aa8
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x168 .. phy_pcie.phy0.ahb_comlane_csr_5_x261 (94 regs) */
literal|0x23188b07
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x263 .. phy_pcie.phy0.ahb_comlane_csr_5_x297 (35 regs) */
literal|0x01188b2d
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x301 (1 regs) */
literal|0x05188b30
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x304 .. phy_pcie.phy0.ahb_comlane_csr_5_x308 (5 regs) */
literal|0x06188b36
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x310 .. phy_pcie.phy0.ahb_comlane_csr_5_x315 (6 regs) */
literal|0x05188b3e
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x318 .. phy_pcie.phy0.ahb_comlane_csr_5_x322 (5 regs) */
literal|0x0a188b44
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x324 .. phy_pcie.phy0.ahb_comlane_csr_5_x333 (10 regs) */
literal|0x02188b52
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x338 .. phy_pcie.phy0.ahb_comlane_csr_5_x339 (2 regs) */
literal|0x02188b55
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x341 .. phy_pcie.phy0.ahb_comlane_csr_5_x342 (2 regs) */
literal|0x01188b58
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x344 (1 regs) */
literal|0x0a188b5a
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x346 .. phy_pcie.phy0.ahb_comlane_csr_5_x355 (10 regs) */
literal|0x01188b66
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x358 (1 regs) */
literal|0x0c188b6a
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x362 .. phy_pcie.phy0.ahb_comlane_csr_5_x373 (12 regs) */
literal|0x11188b78
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x376 .. phy_pcie.phy0.ahb_comlane_csr_5_x392 (17 regs) */
literal|0x01188b8a
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x394 (1 regs) */
literal|0x0b188b91
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x401 .. phy_pcie.phy0.ahb_comlane_csr_5_x411 (11 regs) */
literal|0x57188b9d
block|,
comment|/* phy_pcie.phy0.ahb_comlane_csr_5_x413 .. phy_pcie.phy0.ahb_comlane_csr_5_x499 (87 regs) */
literal|0x23189000
block|,
comment|/* phy_pcie.phy1.ahb_cmu_csr_0_x0 .. phy_pcie.phy1.ahb_cmu_csr_0_x34 (35 regs) */
literal|0x2f189038
block|,
comment|/* phy_pcie.phy1.ahb_cmu_csr_0_x56 .. phy_pcie.phy1.ahb_cmu_csr_0_x102 (47 regs) */
literal|0x2818906c
block|,
comment|/* phy_pcie.phy1.ahb_cmu_csr_0_x108 .. phy_pcie.phy1.ahb_cmu_csr_0_x147 (40 regs) */
literal|0x06189095
block|,
comment|/* phy_pcie.phy1.ahb_cmu_csr_0_x149 .. phy_pcie.phy1.ahb_cmu_csr_0_x154 (6 regs) */
literal|0x1c1890a1
block|,
comment|/* phy_pcie.phy1.ahb_cmu_csr_0_x161 .. phy_pcie.phy1.ahb_cmu_csr_0_x188 (28 regs) */
literal|0x141890bf
block|,
comment|/* phy_pcie.phy1.ahb_cmu_csr_0_x191 .. phy_pcie.phy1.ahb_cmu_csr_0_x210 (20 regs) */
literal|0x06189200
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x0 .. phy_pcie.phy1.ahb_lane_csr_1_x5 (6 regs) */
literal|0x38189207
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x7 .. phy_pcie.phy1.ahb_lane_csr_1_x62 (56 regs) */
literal|0x21189241
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x65 .. phy_pcie.phy1.ahb_lane_csr_1_x97 (33 regs) */
literal|0x11189263
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x99 .. phy_pcie.phy1.ahb_lane_csr_1_x115 (17 regs) */
literal|0x0a189277
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x119 .. phy_pcie.phy1.ahb_lane_csr_1_x128 (10 regs) */
literal|0x29189282
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x130 .. phy_pcie.phy1.ahb_lane_csr_1_x170 (41 regs) */
literal|0x081892c9
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x201 .. phy_pcie.phy1.ahb_lane_csr_1_x208 (8 regs) */
literal|0x051892d5
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x213 .. phy_pcie.phy1.ahb_lane_csr_1_x217 (5 regs) */
literal|0x421892dc
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x220 .. phy_pcie.phy1.ahb_lane_csr_1_x285 (66 regs) */
literal|0x1b18932d
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x301 .. phy_pcie.phy1.ahb_lane_csr_1_x327 (27 regs) */
literal|0x0118934a
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_1_x330 (1 regs) */
literal|0x06189400
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x0 .. phy_pcie.phy1.ahb_lane_csr_2_x5 (6 regs) */
literal|0x38189407
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x7 .. phy_pcie.phy1.ahb_lane_csr_2_x62 (56 regs) */
literal|0x21189441
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x65 .. phy_pcie.phy1.ahb_lane_csr_2_x97 (33 regs) */
literal|0x11189463
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x99 .. phy_pcie.phy1.ahb_lane_csr_2_x115 (17 regs) */
literal|0x0a189477
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x119 .. phy_pcie.phy1.ahb_lane_csr_2_x128 (10 regs) */
literal|0x29189482
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x130 .. phy_pcie.phy1.ahb_lane_csr_2_x170 (41 regs) */
literal|0x081894c9
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x201 .. phy_pcie.phy1.ahb_lane_csr_2_x208 (8 regs) */
literal|0x051894d5
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x213 .. phy_pcie.phy1.ahb_lane_csr_2_x217 (5 regs) */
literal|0x421894dc
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x220 .. phy_pcie.phy1.ahb_lane_csr_2_x285 (66 regs) */
literal|0x1b18952d
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x301 .. phy_pcie.phy1.ahb_lane_csr_2_x327 (27 regs) */
literal|0x0118954a
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_2_x330 (1 regs) */
literal|0x06189600
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x0 .. phy_pcie.phy1.ahb_lane_csr_3_x5 (6 regs) */
literal|0x38189607
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x7 .. phy_pcie.phy1.ahb_lane_csr_3_x62 (56 regs) */
literal|0x21189641
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x65 .. phy_pcie.phy1.ahb_lane_csr_3_x97 (33 regs) */
literal|0x11189663
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x99 .. phy_pcie.phy1.ahb_lane_csr_3_x115 (17 regs) */
literal|0x0a189677
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x119 .. phy_pcie.phy1.ahb_lane_csr_3_x128 (10 regs) */
literal|0x29189682
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x130 .. phy_pcie.phy1.ahb_lane_csr_3_x170 (41 regs) */
literal|0x081896c9
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x201 .. phy_pcie.phy1.ahb_lane_csr_3_x208 (8 regs) */
literal|0x051896d5
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x213 .. phy_pcie.phy1.ahb_lane_csr_3_x217 (5 regs) */
literal|0x421896dc
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x220 .. phy_pcie.phy1.ahb_lane_csr_3_x285 (66 regs) */
literal|0x1b18972d
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x301 .. phy_pcie.phy1.ahb_lane_csr_3_x327 (27 regs) */
literal|0x0118974a
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_3_x330 (1 regs) */
literal|0x06189800
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x0 .. phy_pcie.phy1.ahb_lane_csr_4_x5 (6 regs) */
literal|0x38189807
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x7 .. phy_pcie.phy1.ahb_lane_csr_4_x62 (56 regs) */
literal|0x21189841
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x65 .. phy_pcie.phy1.ahb_lane_csr_4_x97 (33 regs) */
literal|0x11189863
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x99 .. phy_pcie.phy1.ahb_lane_csr_4_x115 (17 regs) */
literal|0x0a189877
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x119 .. phy_pcie.phy1.ahb_lane_csr_4_x128 (10 regs) */
literal|0x29189882
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x130 .. phy_pcie.phy1.ahb_lane_csr_4_x170 (41 regs) */
literal|0x081898c9
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x201 .. phy_pcie.phy1.ahb_lane_csr_4_x208 (8 regs) */
literal|0x051898d5
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x213 .. phy_pcie.phy1.ahb_lane_csr_4_x217 (5 regs) */
literal|0x421898dc
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x220 .. phy_pcie.phy1.ahb_lane_csr_4_x285 (66 regs) */
literal|0x1b18992d
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x301 .. phy_pcie.phy1.ahb_lane_csr_4_x327 (27 regs) */
literal|0x0118994a
block|,
comment|/* phy_pcie.phy1.ahb_lane_csr_4_x330 (1 regs) */
literal|0x05189a00
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x0 .. phy_pcie.phy1.ahb_comlane_csr_5_x4 (5 regs) */
literal|0x15189a06
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x6 .. phy_pcie.phy1.ahb_comlane_csr_5_x26 (21 regs) */
literal|0x07189a1d
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x29 .. phy_pcie.phy1.ahb_comlane_csr_5_x35 (7 regs) */
literal|0x04189a26
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x38 .. phy_pcie.phy1.ahb_comlane_csr_5_x41 (4 regs) */
literal|0x78189a2b
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x43 .. phy_pcie.phy1.ahb_comlane_csr_5_x162 (120 regs) */
literal|0x5e189aa8
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x168 .. phy_pcie.phy1.ahb_comlane_csr_5_x261 (94 regs) */
literal|0x23189b07
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x263 .. phy_pcie.phy1.ahb_comlane_csr_5_x297 (35 regs) */
literal|0x01189b2d
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x301 (1 regs) */
literal|0x05189b30
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x304 .. phy_pcie.phy1.ahb_comlane_csr_5_x308 (5 regs) */
literal|0x06189b36
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x310 .. phy_pcie.phy1.ahb_comlane_csr_5_x315 (6 regs) */
literal|0x05189b3e
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x318 .. phy_pcie.phy1.ahb_comlane_csr_5_x322 (5 regs) */
literal|0x0a189b44
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x324 .. phy_pcie.phy1.ahb_comlane_csr_5_x333 (10 regs) */
literal|0x02189b52
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x338 .. phy_pcie.phy1.ahb_comlane_csr_5_x339 (2 regs) */
literal|0x02189b55
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x341 .. phy_pcie.phy1.ahb_comlane_csr_5_x342 (2 regs) */
literal|0x01189b58
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x344 (1 regs) */
literal|0x0a189b5a
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x346 .. phy_pcie.phy1.ahb_comlane_csr_5_x355 (10 regs) */
literal|0x01189b66
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x358 (1 regs) */
literal|0x0c189b6a
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x362 .. phy_pcie.phy1.ahb_comlane_csr_5_x373 (12 regs) */
literal|0x11189b78
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x376 .. phy_pcie.phy1.ahb_comlane_csr_5_x392 (17 regs) */
literal|0x01189b8a
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x394 (1 regs) */
literal|0x0b189b91
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x401 .. phy_pcie.phy1.ahb_comlane_csr_5_x411 (11 regs) */
literal|0x57189b9d
block|,
comment|/* phy_pcie.phy1.ahb_comlane_csr_5_x413 .. phy_pcie.phy1.ahb_comlane_csr_5_x499 (87 regs) */
literal|0x01000081
block|,
comment|/* split PORT */
literal|0x03060000
block|,
comment|/* block cpmu */
literal|0x0700c080
block|,
comment|/* cpmu.lpi_mode_config .. cpmu.sw_force_lpi (7 regs) */
literal|0x0600c0c9
block|,
comment|/* cpmu.lpi_tx_req_stat_ro .. cpmu.lpi_duration_stat_ro (6 regs) */
literal|0x0600c0df
block|,
comment|/* cpmu.lpi_tx_req_stat .. cpmu.lpi_duration_stat (6 regs) */
literal|0x02200000
block|,
comment|/* block dorq */
literal|0x0104013f
block|,
comment|/* dorq.wake_misc_en (1 regs) */
literal|0x08040221
block|,
comment|/* dorq.tag1_ethertype .. dorq.tag4_size (8 regs) */
literal|0x01210000
block|,
comment|/* block brb */
literal|0x010d0201
block|,
comment|/* brb.header_size (1 regs) */
literal|0x0f230000
block|,
comment|/* block prs */
literal|0x0107c11d
block|,
comment|/* prs.t_tag_tagnum (1 regs) */
literal|0x5607c144
block|,
comment|/* prs.ets_packet_additional_network_size .. prs.wfq_port_arb_current_credit (86 regs) */
literal|0x0107c1c0
block|,
comment|/* prs.prop_hdr_size (1 regs) */
literal|0x0107c1cc
block|,
comment|/* prs.encapsulation_type_en (1 regs) */
literal|0x0107c1ce
block|,
comment|/* prs.vxlan_port (1 regs) */
literal|0x1007c1df
block|,
comment|/* prs.first_hdr_hdrs_after_basic .. prs.inner_hdr_must_have_hdrs (16 regs) */
literal|0x2007c1fa
block|,
comment|/* prs.src_mac_0_0 .. prs.src_mac_15_1 (32 regs) */
literal|0x0107c21b
block|,
comment|/* prs.nge_port (1 regs) */
literal|0x0207c21d
block|,
comment|/* prs.rroce_enable .. prs.nge_comp_ver (2 regs) */
literal|0x0107c250
block|,
comment|/* prs.no_match_pfid (1 regs) */
literal|0x0307c284
block|,
comment|/* prs.classify_failed_pkt_len_stat_add_crc .. prs.classify_failed_pkt_len_stat_tags_not_counted_first (3 regs) */
literal|0x1307c288
block|,
comment|/* prs.nig_classify_failed .. prs.ignore_udp_zero_checksum (19 regs) */
literal|0x0907c2c2
block|,
comment|/* prs.num_of_packets_0 .. prs.num_of_packets_8 (9 regs) */
literal|0x0207c2d5
block|,
comment|/* prs.queue_pkt_avail_status .. prs.storm_bkprs_status (2 regs) */
literal|0x0107c3cd
block|,
comment|/* prs.eop_req_ct (1 regs) */
literal|0x073c0000
block|,
comment|/* block pbf */
literal|0x0636012c
block|,
comment|/* pbf.first_hdr_hdrs_after_basic .. pbf.first_hdr_hdrs_after_tag_3 (6 regs) */
literal|0x07360134
block|,
comment|/* pbf.first_hdr_must_have_hdrs .. pbf.inner_hdr_hdrs_after_tag_3 (7 regs) */
literal|0x0136013d
block|,
comment|/* pbf.inner_hdr_must_have_hdrs (1 regs) */
literal|0x02360146
block|,
comment|/* pbf.vxlan_port .. pbf.nge_port (2 regs) */
literal|0x01360149
block|,
comment|/* pbf.nge_comp_ver (1 regs) */
literal|0x01360162
block|,
comment|/* pbf.t_tag_tagnum (1 regs) */
literal|0x05360170
block|,
comment|/* pbf.btb_shared_area_size .. pbf.num_strict_priority_slots (5 regs) */
literal|0x2e4b0000
block|,
comment|/* block nig */
literal|0x05140384
block|,
comment|/* nig.mac_in_en .. nig.flowctrl_out_en (5 regs) */
literal|0x01140402
block|,
comment|/* nig.rx_pkt_has_fcs (1 regs) */
literal|0x03140404
block|,
comment|/* nig.llc_jumbo_type .. nig.first_hdr_hdrs_after_basic (3 regs) */
literal|0x07140408
block|,
comment|/* nig.first_hdr_hdrs_after_tag_0 .. nig.inner_hdr_hdrs_after_basic (7 regs) */
literal|0x08140410
block|,
comment|/* nig.inner_hdr_hdrs_after_tag_0 .. nig.vxlan_ctrl (8 regs) */
literal|0x2c140422
block|,
comment|/* nig.llh_dest_mac_0_0 .. nig.rx_llh_svol_mcp_mask (44 regs) */
literal|0x04140450
block|,
comment|/* nig.rx_llh_ncsi_brb_dntfwd_mask .. nig.rx_llh_svol_brb_dntfwd_mask (4 regs) */
literal|0x26140456
block|,
comment|/* nig.l2filt_ethertype0 .. nig.rx_llh_brb_gate_dntfwd (38 regs) */
literal|0x0514047e
block|,
comment|/* nig.storm_ethertype0 .. nig.rx_llh_storm_mask (5 regs) */
literal|0x061404c2
block|,
comment|/* nig.rx_llh_dfifo_empty .. nig.rx_llh_rfifo_full (6 regs) */
literal|0x01140500
block|,
comment|/* nig.storm_status (1 regs) */
literal|0x33140540
block|,
comment|/* nig.lb_min_cyc_threshold .. nig.lb_arb_num_strict_arb_slots (51 regs) */
literal|0x02940574
block|,
comment|/* nig.lb_arb_priority_client (2 regs, WB) */
literal|0x22140576
block|,
comment|/* nig.lb_arb_burst_mode .. nig.lb_llh_brb_gate_dntfwd (34 regs) */
literal|0x0f1405d9
block|,
comment|/* nig.lb_btb_fifo_alm_full_thr .. nig.lb_llh_rfifo_alm_full (15 regs) */
literal|0x01140600
block|,
comment|/* nig.lb_llh_rfifo_full (1 regs) */
literal|0x29140640
block|,
comment|/* nig.rx_ptp_en .. nig.outer_tag_value_mask (41 regs) */
literal|0x2d1406e8
block|,
comment|/* nig.flowctrl_mode .. nig.rx_flowctrl_status_clear (45 regs) */
literal|0x08140719
block|,
comment|/* nig.stat_rx_brb_packet_priority_0 .. nig.stat_rx_brb_packet_priority_7 (8 regs) */
literal|0x22140728
block|,
comment|/* nig.stat_rx_brb_octet_priority_0 .. nig.stat_rx_brb_discard_priority_7 (34 regs) */
literal|0x0214074b
block|,
comment|/* nig.stat_rx_storm_packet_discard .. nig.stat_rx_storm_packet_truncate (2 regs) */
literal|0x46140750
block|,
comment|/* nig.stat_lb_brb_packet_priority_0 .. nig.stat_tx_octet_tc_7 (70 regs) */
literal|0x20940796
block|,
comment|/* nig.tx_xoff_cyc_tc_0 .. nig.lb_xoff_cyc_tc_7 (32 regs, WB) */
literal|0x1a1407b6
block|,
comment|/* nig.stat_rx_bmb_octet .. nig.tx_arb_num_strict_arb_slots (26 regs) */
literal|0x029407d0
block|,
comment|/* nig.tx_arb_priority_client (2 regs, WB) */
literal|0x3d1407d2
block|,
comment|/* nig.tx_arb_burst_mode .. nig.tx_gnt_fifo_full (61 regs) */
literal|0x02140825
block|,
comment|/* nig.mng_tc .. nig.tx_mng_tc_en (2 regs) */
literal|0x03140828
block|,
comment|/* nig.tx_mng_timestamp_pkt .. nig.bmb_pkt_len (3 regs) */
literal|0x0414082c
block|,
comment|/* nig.tx_bmb_fifo_empty .. nig.lb_bmb_fifo_full (4 regs) */
literal|0x01140835
block|,
comment|/* nig.debug_pkt_len (1 regs) */
literal|0x05140850
block|,
comment|/* nig.dbg_select .. nig.dbg_force_frame (5 regs) */
literal|0x0f140862
block|,
comment|/* nig.rx_fc_dbg_select .. nig.lb_fc_dbg_force_frame (15 regs) */
literal|0x01140881
block|,
comment|/* nig.eco_reserved_perport (1 regs) */
literal|0x0214220a
block|,
comment|/* nig.tx_ptp_one_stp_en .. nig.rx_ptp_one_stp_en (2 regs) */
literal|0x01142214
block|,
comment|/* nig.add_freecnt_offset (1 regs) */
literal|0x0214222c
block|,
comment|/* nig.tsgen_offset_value_lsb .. nig.tsgen_offset_value_msb (2 regs) */
literal|0x04142230
block|,
comment|/* nig.tsgen_sync_time_lsb .. nig.tsgen_sw_pps_en (4 regs) */
literal|0x02142236
block|,
comment|/* nig.tsgen_rst_drift_cntr .. nig.tsgen_drift_cntr_conf (2 regs) */
literal|0x0214223c
block|,
comment|/* nig.roce_duplicate_to_host .. nig.default_engine_id_sel (2 regs) */
literal|0x43142280
block|,
comment|/* nig.dscp_to_tc_map .. nig.rroce_zero_udp_ignore (67 regs) */
literal|0x011422c8
block|,
comment|/* nig.add_eth_crc (1 regs) */
literal|0x031422ca
block|,
comment|/* nig.nge_ip_enable .. nig.nge_comp_ver (3 regs) */
literal|0x021422ce
block|,
comment|/* nig.nge_port .. nig.llh_lb_tc_remap (2 regs) */
literal|0x051422d2
block|,
comment|/* nig.rx_llh_ncsi_mcp_mask_2 .. nig.tx_llh_ncsi_ntwk_mask_2 (5 regs) */
literal|0x071422d8
block|,
comment|/* nig.timer_counter .. nig.tx_parity_error_close_egress (7 regs) */
literal|0x031422e0
block|,
comment|/* nig.tx_arb_client_0_map .. nig.lb_arb_client_0_map (3 regs) */
literal|0x044b0025
block|,
comment|/* mode !bb, block nig */
literal|0x02142407
block|,
comment|/* nig.tsgen_tsio_in_sel_mask .. nig.tsgen_tsio_in_sel_pol (2 regs) */
literal|0x0494240a
block|,
comment|/* nig.tsgen_tsio_in_latched_value .. nig.tsgen_tsio_out_next_toggle_time (4 regs, WB) */
literal|0x0514240e
block|,
comment|/* nig.tsgen_pps_start_time_0 .. nig.ptp_update_sw_osts_pkt_time (5 regs) */
literal|0x04142416
block|,
comment|/* nig.llh_dest_mac_6_0 .. nig.llh_dest_mac_7_1 (4 regs) */
literal|0x024d0000
block|,
comment|/* block bmbn */
literal|0x06184078
block|,
comment|/* bmbn.mng_outer_tag0_0 .. bmbn.mng_inner_vlan_tag1 (6 regs) */
literal|0x01184081
block|,
comment|/* bmbn.eco_reserved_perport (1 regs) */
literal|0x01530000
block|,
comment|/* block led */
literal|0x061ae000
block|,
comment|/* led.control .. led.mac_led_speed (6 regs) */
literal|0x024b0003
block|,
comment|/* mode !(bb|k2), block nig */
literal|0x02143420
block|,
comment|/* nig.mng_to_mcp_ncsi_filter .. nig.mng_to_mcp_ncsi_filter_2 (2 regs) */
literal|0x02143601
block|,
comment|/* nig.tx_order_fifo_full .. nig.lb_order_fifo_full (2 regs) */
literal|0x01050015
block|,
comment|/* mode !(k2|e5), block cnig */
literal|0x0608608f
block|,
comment|/* cnig.led_control .. cnig.mac_led_speed (6 regs) */
literal|0x144b0000
block|,
comment|/* block nig */
literal|0x02140391
block|,
comment|/* nig.rx_macfifo_empty .. nig.rx_macfifo_full (2 regs) */
literal|0x01140400
block|,
comment|/* nig.hdr_skip_size (1 regs) */
literal|0x01140407
block|,
comment|/* nig.first_hdr_hdrs_after_llc (1 regs) */
literal|0x0114040f
block|,
comment|/* nig.inner_hdr_hdrs_after_llc (1 regs) */
literal|0x03140418
block|,
comment|/* nig.ipv4_type .. nig.fcoe_type (3 regs) */
literal|0x0414041d
block|,
comment|/* nig.tcp_protocol .. nig.icmpv6_protocol (4 regs) */
literal|0x1614080f
block|,
comment|/* nig.mng_outer_tag0_0 .. nig.mng_prop_hdr1_7 (22 regs) */
literal|0x01140827
block|,
comment|/* nig.tx_host_mng_enable (1 regs) */
literal|0x02142002
block|,
comment|/* nig.mf_global_en .. nig.upon_mgmt (2 regs) */
literal|0x04142070
block|,
comment|/* nig.wake_buffer_clear .. nig.wake_details (4 regs) */
literal|0x02142208
block|,
comment|/* nig.tx_up_ts_en .. nig.rx_up_ts_en (2 regs) */
literal|0x0814220c
block|,
comment|/* nig.tx_up_ts_addr_0 .. nig.rx_enable_up_rules (8 regs) */
literal|0x01142215
block|,
comment|/* nig.up_ts_insert_en (1 regs) */
literal|0x0114221f
block|,
comment|/* nig.llh_up_buf_seqid (1 regs) */
literal|0x04942220
block|,
comment|/* nig.llh_up_buf_timestamp .. nig.llh_up_buf_src_addr (4 regs, WB) */
literal|0x01142224
block|,
comment|/* nig.tx_llh_up_buf_seqid (1 regs) */
literal|0x04942226
block|,
comment|/* nig.tx_llh_up_buf_timestamp .. nig.llh_up_buf_dst_addr (4 regs, WB) */
literal|0x0114223b
block|,
comment|/* nig.mld_msg_type (1 regs) */
literal|0x041422c4
block|,
comment|/* nig.acpi_tag_remove .. nig.rm_eth_crc (4 regs) */
literal|0x011422c9
block|,
comment|/* nig.corrupt_eth_crc (1 regs) */
literal|0x033c0043
block|,
comment|/* mode !e5, block pbf */
literal|0x02360132
block|,
comment|/* pbf.first_hdr_hdrs_after_tag_4 .. pbf.first_hdr_hdrs_after_tag_5 (2 regs) */
literal|0x0236013b
block|,
comment|/* pbf.inner_hdr_hdrs_after_tag_4 .. pbf.inner_hdr_hdrs_after_tag_5 (2 regs) */
literal|0x01360160
block|,
comment|/* pbf.prop_hdr_size (1 regs) */
literal|0x034b0000
block|,
comment|/* block nig */
literal|0x01140390
block|,
comment|/* nig.tx_macfifo_alm_full_thr (1 regs) */
literal|0x02140393
block|,
comment|/* nig.tx_macfifo_alm_full .. nig.tx_macfifo_empty (2 regs) */
literal|0x011403c0
block|,
comment|/* nig.tx_macfifo_full (1 regs) */
literal|0x044c00fd
block|,
comment|/* mode (!bb)&(!fpga), block wol */
literal|0x02182000
block|,
comment|/* wol.acpi_tag_rm .. wol.upon_mgmt (2 regs) */
literal|0x06182060
block|,
comment|/* wol.wake_buffer_clear .. wol.acpi_pat_sel (6 regs) */
literal|0x0118206d
block|,
comment|/* wol.wake_mem_rd_offset (1 regs) */
literal|0x0418206f
block|,
comment|/* wol.eco_reserved_perport .. wol.hdr_fifo_error (4 regs) */
literal|0x020000b4
block|,
comment|/* split PF */
literal|0x01010000
block|,
comment|/* block miscs */
literal|0x010025d7
block|,
comment|/* miscs.unprepared_dr (1 regs) */
literal|0x05040000
block|,
comment|/* block pglue_b */
literal|0x040aa136
block|,
comment|/* pglue_b.pseudo_vf_master_enable .. pglue_b.vf_base (4 regs) */
literal|0x030aa85b
block|,
comment|/* pglue_b.internal_pfid_enable_master .. pglue_b.internal_pfid_enable_target_read (3 regs) */
literal|0x010aa950
block|,
comment|/* pglue_b.pf_trusted (1 regs) */
literal|0x010aa965
block|,
comment|/* pglue_b.mask_block_discard_attn_pf (1 regs) */
literal|0x040aab97
block|,
comment|/* pglue_b.config_reg_78 .. pglue_b.vf_bar1_size (4 regs) */
literal|0x03140000
block|,
comment|/* block pswrq2 */
literal|0x1b090003
block|,
comment|/* pswrq2.cdut_p_size .. pswrq2.dbg_last_ilt (27 regs) */
literal|0x0b090024
block|,
comment|/* pswrq2.tm_number_of_pf_blocks .. pswrq2.vf_last_ilt (11 regs) */
literal|0x010901fc
block|,
comment|/* pswrq2.atc_internal_ats_enable (1 regs) */
literal|0x01170000
block|,
comment|/* block ptu */
literal|0x0515801e
block|,
comment|/* ptu.inv_tid .. ptu.inv_halt_on_err (5 regs) */
literal|0x01180000
block|,
comment|/* block tcm */
literal|0x04460241
block|,
comment|/* tcm.con_phy_q0 .. tcm.task_phy_q1 (4 regs) */
literal|0x01190000
block|,
comment|/* block mcm */
literal|0x04480241
block|,
comment|/* mcm.con_phy_q0 .. mcm.task_phy_q1 (4 regs) */
literal|0x011a0000
block|,
comment|/* block ucm */
literal|0x044a0241
block|,
comment|/* ucm.con_phy_q0 .. ucm.task_phy_q1 (4 regs) */
literal|0x011b0000
block|,
comment|/* block xcm */
literal|0x01400241
block|,
comment|/* xcm.con_phy_q3 (1 regs) */
literal|0x011c0000
block|,
comment|/* block ycm */
literal|0x04420241
block|,
comment|/* ycm.con_phy_q0 .. ycm.task_phy_q1 (4 regs) */
literal|0x041e0000
block|,
comment|/* block qm */
literal|0x030bc10d
block|,
comment|/* qm.MaxPqSize_0 .. qm.MaxPqSize_2 (3 regs) */
literal|0x010bc54c
block|,
comment|/* qm.PciReqTph (1 regs) */
literal|0x020bcba8
block|,
comment|/* qm.pci_rd_err .. qm.pf_en (2 regs) */
literal|0x020bcbab
block|,
comment|/* qm.usg_cnt_pf_tx .. qm.usg_cnt_pf_other (2 regs) */
literal|0x031f0000
block|,
comment|/* block tm */
literal|0x010b010f
block|,
comment|/* tm.pf_enable_conn (1 regs) */
literal|0x010b0111
block|,
comment|/* tm.pf_enable_task (1 regs) */
literal|0x020b013f
block|,
comment|/* tm.pf_scan_active_conn .. tm.pf_scan_active_task (2 regs) */
literal|0x07200000
block|,
comment|/* block dorq */
literal|0x02040100
block|,
comment|/* dorq.pf_min_addr_reg1 .. dorq.vf_min_addr_reg1 (2 regs) */
literal|0x06040112
block|,
comment|/* dorq.pf_icid_bit_shift_norm .. dorq.vf_min_val_dpi (6 regs) */
literal|0x03040140
block|,
comment|/* dorq.pf_net_port_id .. dorq.pf_db_enable (3 regs) */
literal|0x02040144
block|,
comment|/* dorq.pf_dpm_enable .. dorq.vf_dpm_enable (2 regs) */
literal|0x0404022d
block|,
comment|/* dorq.tag1_ovrd_mode .. dorq.tag4_ovrd_mode (4 regs) */
literal|0x01040270
block|,
comment|/* dorq.pf_usage_cnt (1 regs) */
literal|0x03040272
block|,
comment|/* dorq.pf_usage_cnt_lim .. dorq.pf_ovfl_sticky (3 regs) */
literal|0x05220000
block|,
comment|/* block src */
literal|0x0208e127
block|,
comment|/* src.NumIpv4Conn .. src.NumIpv6Conn (2 regs) */
literal|0x0288e140
block|,
comment|/* src.FirstFree (2 regs, WB) */
literal|0x0288e148
block|,
comment|/* src.LastFree (2 regs, WB) */
literal|0x0108e150
block|,
comment|/* src.CountFree (1 regs) */
literal|0x0108e181
block|,
comment|/* src.number_hash_bits (1 regs) */
literal|0x11230000
block|,
comment|/* block prs */
literal|0x0407c05a
block|,
comment|/* prs.task_id_max_initiator_pf .. prs.task_id_max_target_vf (4 regs) */
literal|0x0107c064
block|,
comment|/* prs.roce_separate_rx_tx_cid_flg (1 regs) */
literal|0x0107c066
block|,
comment|/* prs.load_l2_filter (1 regs) */
literal|0x0207c068
block|,
comment|/* prs.target_initiator_select .. prs.fcoe_search_with_exchange_context (2 regs) */
literal|0x0407c100
block|,
comment|/* prs.search_tcp .. prs.search_roce (4 regs) */
literal|0x0507c105
block|,
comment|/* prs.tcp_search_key_mask .. prs.roce_build_cid_wo_search (5 regs) */
literal|0x0907c10b
block|,
comment|/* prs.roce_dest_qp_max_vf .. prs.search_tenant_id (9 regs) */
literal|0x0207c1cf
block|,
comment|/* prs.roce_icid_base_pf .. prs.roce_icid_base_vf (2 regs) */
literal|0x0507c1f5
block|,
comment|/* prs.first_hdr_dst_ip_0 .. prs.first_hdr_dst_ip_4 (5 regs) */
literal|0x0307c251
block|,
comment|/* prs.override_pfid_if_no_match .. prs.no_match_lcid (3 regs) */
literal|0x0207c25a
block|,
comment|/* prs.light_l2_ethertype_en .. prs.use_light_l2 (2 regs) */
literal|0x0107c26f
block|,
comment|/* prs.mac_vlan_cache_use_tenant_id (1 regs) */
literal|0x0107c274
block|,
comment|/* prs.sort_sack (1 regs) */
literal|0x0107c276
block|,
comment|/* prs.rdma_syn_mask (1 regs) */
literal|0x0507c27f
block|,
comment|/* prs.rdma_syn_cookie_en .. prs.pkt_len_stat_tags_not_counted_first (5 regs) */
literal|0x0107c287
block|,
comment|/* prs.msg_info (1 regs) */
literal|0x0207c46f
block|,
comment|/* prs.search_gft .. prs.search_non_ip_as_gft (2 regs) */
literal|0x013f0000
block|,
comment|/* block cdu */
literal|0x0a160243
block|,
comment|/* cdu.pf_seg0_type_offset .. cdu.vf_fl_seg_type_offset (10 regs) */
literal|0x06400000
block|,
comment|/* block ccfc */
literal|0x010b8176
block|,
comment|/* ccfc.robustwb_pf (1 regs) */
literal|0x010b81c0
block|,
comment|/* ccfc.weak_enable_pf (1 regs) */
literal|0x010b81c2
block|,
comment|/* ccfc.strong_enable_pf (1 regs) */
literal|0x010b81c6
block|,
comment|/* ccfc.pf_minicache_enable (1 regs) */
literal|0x010bb403
block|,
comment|/* ccfc.pf_lstate_cnt1 (1 regs) */
literal|0x010bb405
block|,
comment|/* ccfc.pf_lstate_cnt2 (1 regs) */
literal|0x06410000
block|,
comment|/* block tcfc */
literal|0x010b4176
block|,
comment|/* tcfc.robustwb_pf (1 regs) */
literal|0x010b41c0
block|,
comment|/* tcfc.weak_enable_pf (1 regs) */
literal|0x010b41c2
block|,
comment|/* tcfc.strong_enable_pf (1 regs) */
literal|0x010b41c6
block|,
comment|/* tcfc.pf_minicache_enable (1 regs) */
literal|0x010b7403
block|,
comment|/* tcfc.pf_lstate_cnt1 (1 regs) */
literal|0x010b7405
block|,
comment|/* tcfc.pf_lstate_cnt2 (1 regs) */
literal|0x08420000
block|,
comment|/* block igu */
literal|0x02060100
block|,
comment|/* igu.statistic_num_pf_msg_sent (2 regs) */
literal|0x0106010b
block|,
comment|/* igu.statistic_num_of_inta_asserted (1 regs) */
literal|0x01060200
block|,
comment|/* igu.pf_configuration (1 regs) */
literal|0x0a060208
block|,
comment|/* igu.attn_msg_addr_l .. igu.command_reg_32msb_data (10 regs) */
literal|0x05060328
block|,
comment|/* igu.int_before_mask_sts_pf (5 regs) */
literal|0x05060338
block|,
comment|/* igu.int_mask_sts_pf (5 regs) */
literal|0x05060348
block|,
comment|/* igu.pba_sts_pf (5 regs) */
literal|0x01060486
block|,
comment|/* igu.attn_tph (1 regs) */
literal|0x01430000
block|,
comment|/* block cau */
literal|0x01070106
block|,
comment|/* cau.cleanup_command_done (1 regs) */
literal|0x094b0000
block|,
comment|/* block nig */
literal|0x01140300
block|,
comment|/* nig.tx_lb_pf_drop_perpf (1 regs) */
literal|0x0114044f
block|,
comment|/* nig.rx_llh_svol_mcp_fwd_perpf (1 regs) */
literal|0x01140455
block|,
comment|/* nig.rx_llh_svol_brb_dntfwd_perpf (1 regs) */
literal|0x0114047d
block|,
comment|/* nig.rx_llh_brb_gate_dntfwd_perpf (1 regs) */
literal|0x01140599
block|,
comment|/* nig.lb_llh_brb_gate_dntfwd_perpf (1 regs) */
literal|0x011406e7
block|,
comment|/* nig.llh_eng_cls_eng_id_perpf (1 regs) */
literal|0x07142051
block|,
comment|/* nig.tcp_syn_enable .. nig.tcp_syn_ipv4_dst_port (7 regs) */
literal|0x08942058
block|,
comment|/* nig.tcp_syn_ipv6_src_addr .. nig.tcp_syn_ipv6_dst_addr (8 regs, WB) */
literal|0x02142060
block|,
comment|/* nig.tcp_syn_ipv4_src_addr .. nig.tcp_syn_ipv4_dst_addr (2 regs) */
literal|0x02040025
block|,
comment|/* mode !bb, block pglue_b */
literal|0x020aabad
block|,
comment|/* pglue_b.vf_bar0_size .. pglue_b.pf_rom_size (2 regs) */
literal|0x040aabe6
block|,
comment|/* pglue_b.pgl_addr_e8_f0 .. pglue_b.pgl_addr_f4_f0 (4 regs) */
literal|0x1c150000
block|,
comment|/* block pglcs */
literal|0x0e000800
block|,
comment|/* pglcs.pgl_cs.DEVICE_ID_VENDOR_ID_REG .. pglcs.pgl_cs.PCI_CAP_PTR_REG (14 regs) */
literal|0x0300080f
block|,
comment|/* pglcs.pgl_cs.MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG .. pglcs.pgl_cs.CON_STATUS_REG (3 regs) */
literal|0x06000814
block|,
comment|/* pglcs.pgl_cs.PCI_MSI_CAP_ID_NEXT_CTRL_REG .. pglcs.pgl_cs.MSI_CAP_OFF_14H_REG (6 regs) */
literal|0x0500081c
block|,
comment|/* pglcs.pgl_cs.PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG .. pglcs.pgl_cs.LINK_CONTROL_LINK_STATUS_REG (5 regs) */
literal|0x04000825
block|,
comment|/* pglcs.pgl_cs.DEVICE_CAPABILITIES2_REG .. pglcs.pgl_cs.LINK_CONTROL2_LINK_STATUS2_REG (4 regs) */
literal|0x0300082c
block|,
comment|/* pglcs.pgl_cs.PCI_MSIX_CAP_ID_NEXT_CTRL_REG .. pglcs.pgl_cs.MSIX_PBA_OFFSET_REG (3 regs) */
literal|0x02000834
block|,
comment|/* pglcs.pgl_cs.VPD_BASE .. pglcs.pgl_cs.DATA_REG (2 regs) */
literal|0x0b000840
block|,
comment|/* pglcs.pgl_cs.AER_EXT_CAP_HDR_OFF .. pglcs.pgl_cs.HDR_LOG_3_OFF (11 regs) */
literal|0x0400084e
block|,
comment|/* pglcs.pgl_cs.TLP_PREFIX_LOG_1_OFF .. pglcs.pgl_cs.TLP_PREFIX_LOG_4_OFF (4 regs) */
literal|0x0300085a
block|,
comment|/* pglcs.pgl_cs.SN_BASE .. pglcs.pgl_cs.SER_NUM_REG_DW_2 (3 regs) */
literal|0x0600085e
block|,
comment|/* pglcs.pgl_cs.PB_BASE .. pglcs.pgl_cs.CAP_REG (6 regs) */
literal|0x1400086e
block|,
comment|/* pglcs.pgl_cs.SRIOV_BASE_REG .. pglcs.pgl_cs.TPH_ST_TABLE_REG_0 (20 regs) */
literal|0x060008a3
block|,
comment|/* pglcs.pgl_cs.RAS_DES_CAP_HEADER_REG .. pglcs.pgl_cs.TIME_BASED_ANALYSIS_DATA_REG (6 regs) */
literal|0x180008af
block|,
comment|/* pglcs.pgl_cs.EINJ_ENABLE_REG .. pglcs.pgl_cs.EINJ6_TLP_REG (24 regs) */
literal|0x020008cb
block|,
comment|/* pglcs.pgl_cs.SD_CONTROL1_REG .. pglcs.pgl_cs.SD_CONTROL2_REG (2 regs) */
literal|0x060008cf
block|,
comment|/* pglcs.pgl_cs.SD_STATUS_L1LANE_REG .. pglcs.pgl_cs.SD_STATUS_L3_REG (6 regs) */
literal|0x030008d7
block|,
comment|/* pglcs.pgl_cs.SD_EQ_CONTROL1_REG .. pglcs.pgl_cs.SD_EQ_CONTROL3_REG (3 regs) */
literal|0x030008db
block|,
comment|/* pglcs.pgl_cs.SD_EQ_STATUS1_REG .. pglcs.pgl_cs.SD_EQ_STATUS3_REG (3 regs) */
literal|0x0e0008e3
block|,
comment|/* pglcs.pgl_cs.RASDP_EXT_CAP_HDR_OFF .. pglcs.pgl_cs.RASDP_RAM_ADDR_UNCORR_ERROR_OFF (14 regs) */
literal|0x180008f4
block|,
comment|/* pglcs.pgl_cs.PTM_REQ_CAP_HDR_OFF .. pglcs.pgl_cs.RESBAR_CTRL_REG_0_REG (24 regs) */
literal|0x01000d05
block|,
comment|/* pglcs.pgl_cs_shadow.BAR1_MASK_REG (1 regs) */
literal|0x01000d0c
block|,
comment|/* pglcs.pgl_cs_shadow.EXP_ROM_BAR_MASK_REG (1 regs) */
literal|0x01000d71
block|,
comment|/* pglcs.pgl_cs_shadow.SHADOW_SRIOV_INITIAL_VFS (1 regs) */
literal|0x01000d73
block|,
comment|/* pglcs.pgl_cs_shadow.SHADOW_SRIOV_VF_OFFSET_POSITION (1 regs) */
literal|0x01000d78
block|,
comment|/* pglcs.pgl_cs_shadow.SRIOV_BAR1_MASK_REG (1 regs) */
literal|0x01000d7a
block|,
comment|/* pglcs.pgl_cs_shadow.SRIOV_BAR3_MASK_REG (1 regs) */
literal|0x01000d7c
block|,
comment|/* pglcs.pgl_cs_shadow.SRIOV_BAR5_MASK_REG (1 regs) */
literal|0x01000e00
block|,
comment|/* pglcs.first_vf (1 regs) */
literal|0x01170003
block|,
comment|/* mode !(bb|k2), block ptu */
literal|0x02158179
block|,
comment|/* ptu.inv_rsc_type .. ptu.inv_rsc_type_mask (2 regs) */
literal|0x03200000
block|,
comment|/* block dorq */
literal|0x10040a04
block|,
comment|/* dorq.prv_pf_max_icid_2 .. dorq.prv_vf_range2conn_type_5 (16 regs) */
literal|0x02040add
block|,
comment|/* dorq.ddp_version .. dorq.rdmap_version (2 regs) */
literal|0x08040ae1
block|,
comment|/* dorq.pf_ext_pcp_roce .. dorq.pf_int_vid_iwarp (8 regs) */
literal|0x01230000
block|,
comment|/* block prs */
literal|0x0107c5b9
block|,
comment|/* prs.new_entry_exclusive (1 regs) */
literal|0x03450000
block|,
comment|/* block rgsrc */
literal|0x010c8104
block|,
comment|/* rgsrc.hash_bin_bit_w (1 regs) */
literal|0x020c8112
block|,
comment|/* rgsrc.table_t1_entry_size .. rgsrc.table_t2_entry_size (2 regs) */
literal|0x010c8118
block|,
comment|/* rgsrc.was_error (1 regs) */
literal|0x03470000
block|,
comment|/* block tgsrc */
literal|0x010c8904
block|,
comment|/* tgsrc.hash_bin_bit_w (1 regs) */
literal|0x020c8912
block|,
comment|/* tgsrc.table_t1_entry_size .. tgsrc.table_t2_entry_size (2 regs) */
literal|0x010c8918
block|,
comment|/* tgsrc.was_error (1 regs) */
literal|0x01040015
block|,
comment|/* mode !(k2|e5), block pglue_b */
literal|0x040aa901
block|,
comment|/* pglue_b.pgl_addr_88_f0 .. pglue_b.pgl_addr_94_f0 (4 regs) */
literal|0x0f150000
block|,
comment|/* block pglcs */
literal|0x0e000800
block|,
comment|/* pglcs.pgl_cs.device_vendor_id .. pglcs.pgl_cs.cap_pointer (14 regs) */
literal|0x0100080f
block|,
comment|/* pglcs.pgl_cs.lat_min_grant_int_pin_int_line (1 regs) */
literal|0x08000812
block|,
comment|/* pglcs.pgl_cs.pm_cap .. pglcs.pgl_cs.msi_data (8 regs) */
literal|0x12000828
block|,
comment|/* pglcs.pgl_cs.msix_cap .. pglcs.pgl_cs.slot_status_control_2 (18 regs) */
literal|0x0e000840
block|,
comment|/* pglcs.pgl_cs.adv_err_cap .. pglcs.pgl_cs.root_err_id (14 regs) */
literal|0x0300084f
block|,
comment|/* pglcs.pgl_cs.device_ser_num_cap .. pglcs.pgl_cs.upper_ser_num (3 regs) */
literal|0x0b000854
block|,
comment|/* pglcs.pgl_cs.pwr_bdgt_cap .. pglcs.pgl_cs.vc_rsrc_status (11 regs) */
literal|0x07000860
block|,
comment|/* pglcs.pgl_cs.vendor_cap .. pglcs.pgl_cs.vendor_specific_reg5 (7 regs) */
literal|0x1300086c
block|,
comment|/* pglcs.pgl_cs.LTR_cap .. pglcs.pgl_cs.VF_BAR5 (19 regs) */
literal|0x03000880
block|,
comment|/* pglcs.pgl_cs.PTM_extended_cap .. pglcs.pgl_cs.ptm_ctrl_reg (3 regs) */
literal|0x02000884
block|,
comment|/* pglcs.pgl_cs.ATS_cap .. pglcs.pgl_cs.ATS_control (2 regs) */
literal|0x03000888
block|,
comment|/* pglcs.pgl_cs.RBAR_ext_cap .. pglcs.pgl_cs.RBAR_CTRL (3 regs) */
literal|0x0300088c
block|,
comment|/* pglcs.pgl_cs.TPH_extended_cap .. pglcs.pgl_cs.tph_req_control (3 regs) */
literal|0x04000890
block|,
comment|/* pglcs.pgl_cs.PML1sub_capID .. pglcs.pgl_cs.PML1_sub_control2 (4 regs) */
literal|0x0b0008c0
block|,
comment|/* pglcs.pgl_cs.Secondary_PCIE_Extended_Cap .. pglcs.pgl_cs.Lane14_15_equalization_ctrl (11 regs) */
literal|0x01420000
block|,
comment|/* block igu */
literal|0x03060203
block|,
comment|/* igu.pci_pf_msi_en .. igu.pci_pf_msix_func_mask (3 regs) */
literal|0x02200043
block|,
comment|/* mode !e5, block dorq */
literal|0x10040102
block|,
comment|/* dorq.pf_max_icid_0 .. dorq.vf_max_icid_7 (16 regs) */
literal|0x02040231
block|,
comment|/* dorq.pf_pcp .. dorq.pf_ext_vid (2 regs) */
literal|0x010401a3
block|,
comment|/* mode !k2, block pglue_b */
literal|0x010aa839
block|,
comment|/* pglue_b.shadow_ats_stu (1 regs) */
literal|0x044c00fd
block|,
comment|/* mode (!bb)&(!fpga), block wol */
literal|0x12182040
block|,
comment|/* wol.acpi_enable .. wol.mpkt_enable (18 regs) */
literal|0x02982052
block|,
comment|/* wol.mpkt_mac_addr (2 regs, WB) */
literal|0x01182054
block|,
comment|/* wol.force_wol (1 regs) */
literal|0x01182066
block|,
comment|/* wol.tcp_syn_enable (1 regs) */
literal|0x0300000f
block|,
comment|/* split PORT_PF */
literal|0x01230000
block|,
comment|/* block prs */
literal|0x0207c1f3
block|,
comment|/* prs.first_hdr_dst_mac_0 .. prs.first_hdr_dst_mac_1 (2 regs) */
literal|0x034b0000
block|,
comment|/* block nig */
literal|0x01140669
block|,
comment|/* nig.llh_func_tagmac_cls_type (1 regs) */
literal|0x0d14066c
block|,
comment|/* nig.llh_func_tag_en .. nig.llh_func_no_tag (13 regs) */
literal|0x0114223e
block|,
comment|/* nig.dscp_to_tc_map_enable (1 regs) */
literal|0x054b0015
block|,
comment|/* mode !(k2|e5), block nig */
literal|0x02142000
block|,
comment|/* nig.acpi_tag_rm .. nig.acpi_prop_hdr_rm (2 regs) */
literal|0x11142040
block|,
comment|/* nig.acpi_enable .. nig.acpi_pat_7_len (17 regs) */
literal|0x01142062
block|,
comment|/* nig.mpkt_enable (1 regs) */
literal|0x02942064
block|,
comment|/* nig.mpkt_mac_addr (2 regs, WB) */
literal|0x01142066
block|,
comment|/* nig.force_wol (1 regs) */
literal|0x024b0043
block|,
comment|/* mode !e5, block nig */
literal|0x20940680
block|,
comment|/* nig.llh_func_filter_value (32 regs, WB) */
literal|0x401406a0
block|,
comment|/* nig.llh_func_filter_en .. nig.llh_func_filter_hdr_sel (64 regs) */
literal|0x0400002a
block|,
comment|/* split VF */
literal|0x03040000
block|,
comment|/* block pglue_b */
literal|0x010aa85a
block|,
comment|/* pglue_b.internal_vfid_enable (1 regs) */
literal|0x010aa95f
block|,
comment|/* pglue_b.fid_channel_enable (1 regs) */
literal|0x010aa966
block|,
comment|/* pglue_b.mask_block_discard_attn_vf (1 regs) */
literal|0x021e0000
block|,
comment|/* block qm */
literal|0x010bcbaa
block|,
comment|/* qm.vf_en (1 regs) */
literal|0x020bcbad
block|,
comment|/* qm.usg_cnt_vf_tx .. qm.usg_cnt_vf_other (2 regs) */
literal|0x031f0000
block|,
comment|/* block tm */
literal|0x010b010e
block|,
comment|/* tm.vf_enable_conn (1 regs) */
literal|0x010b0110
block|,
comment|/* tm.vf_enable_task (1 regs) */
literal|0x020b0141
block|,
comment|/* tm.vf_scan_active_conn .. tm.vf_scan_active_task (2 regs) */
literal|0x03200000
block|,
comment|/* block dorq */
literal|0x01040143
block|,
comment|/* dorq.vf_db_enable (1 regs) */
literal|0x01040271
block|,
comment|/* dorq.vf_usage_cnt (1 regs) */
literal|0x01040275
block|,
comment|/* dorq.vf_ovfl_sticky (1 regs) */
literal|0x04400000
block|,
comment|/* block ccfc */
literal|0x010b81c1
block|,
comment|/* ccfc.weak_enable_vf (1 regs) */
literal|0x010b81c3
block|,
comment|/* ccfc.strong_enable_vf (1 regs) */
literal|0x010bb402
block|,
comment|/* ccfc.vf_lstate_cnt1 (1 regs) */
literal|0x010bb404
block|,
comment|/* ccfc.vf_lstate_cnt2 (1 regs) */
literal|0x04410000
block|,
comment|/* block tcfc */
literal|0x010b41c1
block|,
comment|/* tcfc.weak_enable_vf (1 regs) */
literal|0x010b41c3
block|,
comment|/* tcfc.strong_enable_vf (1 regs) */
literal|0x010b7402
block|,
comment|/* tcfc.vf_lstate_cnt1 (1 regs) */
literal|0x010b7404
block|,
comment|/* tcfc.vf_lstate_cnt2 (1 regs) */
literal|0x05420000
block|,
comment|/* block igu */
literal|0x01060102
block|,
comment|/* igu.statistic_num_vf_msg_sent (1 regs) */
literal|0x01060201
block|,
comment|/* igu.vf_configuration (1 regs) */
literal|0x02060330
block|,
comment|/* igu.int_before_mask_sts_vf_lsb .. igu.int_before_mask_sts_vf_msb (2 regs) */
literal|0x02060340
block|,
comment|/* igu.int_mask_sts_vf_lsb .. igu.int_mask_sts_vf_msb (2 regs) */
literal|0x02060350
block|,
comment|/* igu.pba_sts_vf_lsb .. igu.pba_sts_vf_msb (2 regs) */
literal|0x08150025
block|,
comment|/* mode !bb, block pglcs */
literal|0x0c000c00
block|,
comment|/* pglcs.pgl_cs_vf_1.VF_DEVICE_ID_VENDOR_ID_REG .. pglcs.pgl_cs_vf_1.VF_SUBSYSTEM_ID_SUBSYSTEM_VENDOR_ID_REG (12 regs) */
literal|0x01000c0d
block|,
comment|/* pglcs.pgl_cs_vf_1.VF_PCI_CAP_PTR_REG (1 regs) */
literal|0x01000c0f
block|,
comment|/* pglcs.pgl_cs_vf_1.VF_MAX_LATENCY_MIN_GRANT_INTERRUPT_PIN_INTERRUPT_LINE_REG (1 regs) */
literal|0x05000c1c
block|,
comment|/* pglcs.pgl_cs_vf_1.VF_PCIE_CAP_ID_PCIE_NEXT_CAP_PTR_PCIE_CAP_REG .. pglcs.pgl_cs_vf_1.VF_LINK_CONTROL_LINK_STATUS_REG (5 regs) */
literal|0x04000c25
block|,
comment|/* pglcs.pgl_cs_vf_1.VF_DEVICE_CAPABILITIES2_REG .. pglcs.pgl_cs_vf_1.VF_LINK_CONTROL2_LINK_STATUS2_REG (4 regs) */
literal|0x03000c2c
block|,
comment|/* pglcs.pgl_cs_vf_1.VF_PCI_MSIX_CAP_ID_NEXT_CTRL_REG .. pglcs.pgl_cs_vf_1.VF_MSIX_PBA_OFFSET_REG (3 regs) */
literal|0x02000c40
block|,
comment|/* pglcs.pgl_cs_vf_1.VF_ARI_BASE .. pglcs.pgl_cs_vf_1.VF_CAP_REG (2 regs) */
literal|0x04000c44
block|,
comment|/* pglcs.pgl_cs_vf_1.VF_TPH_EXT_CAP_HDR_REG .. pglcs.pgl_cs_vf_1.VF_TPH_ST_TABLE_REG_0 (4 regs) */
literal|0x01420015
block|,
comment|/* mode !(k2|e5), block igu */
literal|0x02060206
block|,
comment|/* igu.pci_vf_msix_en .. igu.pci_vf_msix_func_mask (2 regs) */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 14236 bytes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PREVENT_DUMP_MEM_ARR__
end_ifndef

begin_comment
comment|/* Array of memories to be dumped */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|dump_mem
index|[]
init|=
block|{
literal|0x00000295
block|,
comment|/* split NONE */
literal|0x14040000
block|,
comment|/* block pglue_b */
literal|0x000aa910
block|,
literal|0x00000006
block|,
comment|/* pglue_b.sdm_inb_int_b_pf_0, group=PXP_MEM, size=6 regs */
literal|0x000aa918
block|,
literal|0x00000006
block|,
comment|/* pglue_b.sdm_inb_int_b_pf_1, group=PXP_MEM, size=6 regs */
literal|0x000aa920
block|,
literal|0x00000006
block|,
comment|/* pglue_b.sdm_inb_int_b_pf_2, group=PXP_MEM, size=6 regs */
literal|0x000aa928
block|,
literal|0x00000006
block|,
comment|/* pglue_b.sdm_inb_int_b_pf_3, group=PXP_MEM, size=6 regs */
literal|0x000aa930
block|,
literal|0x00000006
block|,
comment|/* pglue_b.sdm_inb_int_b_pf_4, group=PXP_MEM, size=6 regs */
literal|0x000aa938
block|,
literal|0x00000006
block|,
comment|/* pglue_b.sdm_inb_int_b_pf_5, group=PXP_MEM, size=6 regs */
literal|0x000aa940
block|,
literal|0x00000006
block|,
comment|/* pglue_b.sdm_inb_int_b_pf_6, group=PXP_MEM, size=6 regs */
literal|0x000aa948
block|,
literal|0x00000006
block|,
comment|/* pglue_b.sdm_inb_int_b_pf_7, group=PXP_MEM, size=6 regs */
literal|0x000aaa00
block|,
literal|0x010000b0
block|,
comment|/* pglue_b.write_fifo_queue, group=PXP_MEM, size=176 regs, WB */
literal|0x000aab00
block|,
literal|0x01000070
block|,
comment|/* pglue_b.read_fifo_queue, group=PXP_MEM, size=112 regs, WB */
literal|0x020d0000
block|,
comment|/* block pswhst */
literal|0x000a8100
block|,
literal|0x00000048
block|,
comment|/* pswhst.inbound_int, group=PXP_MEM, size=72 regs */
literal|0x02160000
block|,
comment|/* block dmae */
literal|0x01003200
block|,
literal|0x000001c0
block|,
comment|/* dmae.cmd_mem, group=DMAE_MEM, size=448 regs */
literal|0x02180000
block|,
comment|/* block tcm */
literal|0x02460600
block|,
literal|0x00000040
block|,
comment|/* tcm.xx_dscr_tbl, group=CM_MEM, size=64 regs */
literal|0x02190000
block|,
comment|/* block mcm */
literal|0x02480700
block|,
literal|0x00000040
block|,
comment|/* mcm.xx_dscr_tbl, group=CM_MEM, size=64 regs */
literal|0x021a0000
block|,
comment|/* block ucm */
literal|0x024a06c0
block|,
literal|0x00000040
block|,
comment|/* ucm.xx_dscr_tbl, group=CM_MEM, size=64 regs */
literal|0x041b0000
block|,
comment|/* block xcm */
literal|0x024006c0
block|,
literal|0x00000040
block|,
comment|/* xcm.xx_dscr_tbl, group=CM_MEM, size=64 regs */
literal|0x02400800
block|,
literal|0x00000400
block|,
comment|/* xcm.xx_msg_ram, group=CM_MEM, size=1024 regs */
literal|0x041c0000
block|,
comment|/* block ycm */
literal|0x02420700
block|,
literal|0x00000040
block|,
comment|/* ycm.xx_dscr_tbl, group=CM_MEM, size=64 regs */
literal|0x02422000
block|,
literal|0x00001860
block|,
comment|/* ycm.xx_msg_ram, group=CM_MEM, size=6240 regs */
literal|0x081d0000
block|,
comment|/* block pcm */
literal|0x02440540
block|,
literal|0x00000002
block|,
comment|/* pcm.xx_lcid_cam, group=CM_MEM, size=2 regs */
literal|0x02440580
block|,
literal|0x00000002
block|,
comment|/* pcm.xx_tbl, group=CM_MEM, size=2 regs */
literal|0x024405c0
block|,
literal|0x00000004
block|,
comment|/* pcm.xx_dscr_tbl, group=CM_MEM, size=4 regs */
literal|0x02440800
block|,
literal|0x000002c0
block|,
comment|/* pcm.xx_msg_ram, group=CM_MEM, size=704 regs */
literal|0x081e0000
block|,
comment|/* block qm */
literal|0x030bc700
block|,
literal|0x00000048
block|,
comment|/* qm.CMIntQMask, group=QM_MEM, size=72 regs */
literal|0x030bcd00
block|,
literal|0x00000100
block|,
comment|/* qm.RlGlblIncVal, group=QM_MEM, size=256 regs */
literal|0x030bcf00
block|,
literal|0x00000100
block|,
comment|/* qm.RlGlblUpperBound, group=QM_MEM, size=256 regs */
literal|0x030bd100
block|,
literal|0x00000100
block|,
comment|/* qm.RlGlblCrd, group=QM_MEM, size=256 regs */
literal|0x021f0000
block|,
comment|/* block tm */
literal|0x040b2000
block|,
literal|0x01000a00
block|,
comment|/* tm.context_mem, group=TM_MEM, size=2560 regs, WB */
literal|0x0a210000
block|,
comment|/* block brb */
literal|0x050d0204
block|,
literal|0x00000004
block|,
comment|/* brb.free_list_head, group=BRB_RAM, size=4 regs */
literal|0x050d0208
block|,
literal|0x00000004
block|,
comment|/* brb.free_list_tail, group=BRB_RAM, size=4 regs */
literal|0x050d020c
block|,
literal|0x00000004
block|,
comment|/* brb.free_list_size, group=BRB_RAM, size=4 regs */
literal|0x060d0600
block|,
literal|0x01000014
block|,
comment|/* brb.stopped_rd_req, group=BRB_MEM, size=20 regs, WB */
literal|0x060d0640
block|,
literal|0x01000014
block|,
comment|/* brb.stopped_rls_req, group=BRB_MEM, size=20 regs, WB */
literal|0x04230000
block|,
comment|/* block prs */
literal|0x0707c400
block|,
literal|0x01000040
block|,
comment|/* prs.gft_profile_mask_ram, group=PRS_MEM, size=64 regs, WB */
literal|0x0707c440
block|,
literal|0x0000001f
block|,
comment|/* prs.gft_cam, group=PRS_MEM, size=31 regs */
literal|0x04250000
block|,
comment|/* block msdm */
literal|0x083f0200
block|,
literal|0x00000020
block|,
comment|/* msdm.agg_int_ctrl, group=SDM_MEM, size=32 regs */
literal|0x083f0280
block|,
literal|0x00000020
block|,
comment|/* msdm.agg_int_state, group=SDM_MEM, size=32 regs */
literal|0x04260000
block|,
comment|/* block usdm */
literal|0x083f4200
block|,
literal|0x00000020
block|,
comment|/* usdm.agg_int_ctrl, group=SDM_MEM, size=32 regs */
literal|0x083f4280
block|,
literal|0x00000020
block|,
comment|/* usdm.agg_int_state, group=SDM_MEM, size=32 regs */
literal|0x04270000
block|,
comment|/* block xsdm */
literal|0x083e0200
block|,
literal|0x00000020
block|,
comment|/* xsdm.agg_int_ctrl, group=SDM_MEM, size=32 regs */
literal|0x083e0280
block|,
literal|0x00000020
block|,
comment|/* xsdm.agg_int_state, group=SDM_MEM, size=32 regs */
literal|0x04280000
block|,
comment|/* block ysdm */
literal|0x083e4200
block|,
literal|0x00000020
block|,
comment|/* ysdm.agg_int_ctrl, group=SDM_MEM, size=32 regs */
literal|0x083e4280
block|,
literal|0x00000020
block|,
comment|/* ysdm.agg_int_state, group=SDM_MEM, size=32 regs */
literal|0x04290000
block|,
comment|/* block psdm */
literal|0x083e8200
block|,
literal|0x00000020
block|,
comment|/* psdm.agg_int_ctrl, group=SDM_MEM, size=32 regs */
literal|0x083e8280
block|,
literal|0x00000020
block|,
comment|/* psdm.agg_int_state, group=SDM_MEM, size=32 regs */
literal|0x062a0000
block|,
comment|/* block tsem */
literal|0x095d0100
block|,
literal|0x00000020
block|,
comment|/* tsem.fast_memory.gpre, group=IOR, size=32 regs */
literal|0x095d0130
block|,
literal|0x00000001
block|,
comment|/* tsem.fast_memory.active_reg_set, group=IOR, size=1 regs */
literal|0x0a5d8000
block|,
literal|0x00005000
block|,
comment|/* tsem.fast_memory.int_ram, group=RAM, size=20480 regs */
literal|0x062b0000
block|,
comment|/* block msem */
literal|0x09610100
block|,
literal|0x00000020
block|,
comment|/* msem.fast_memory.gpre, group=IOR, size=32 regs */
literal|0x09610130
block|,
literal|0x00000001
block|,
comment|/* msem.fast_memory.active_reg_set, group=IOR, size=1 regs */
literal|0x0a618000
block|,
literal|0x00005000
block|,
comment|/* msem.fast_memory.int_ram, group=RAM, size=20480 regs */
literal|0x062c0000
block|,
comment|/* block usem */
literal|0x09650100
block|,
literal|0x00000020
block|,
comment|/* usem.fast_memory.gpre, group=IOR, size=32 regs */
literal|0x09650130
block|,
literal|0x00000001
block|,
comment|/* usem.fast_memory.active_reg_set, group=IOR, size=1 regs */
literal|0x0a658000
block|,
literal|0x00005000
block|,
comment|/* usem.fast_memory.int_ram, group=RAM, size=20480 regs */
literal|0x062d0000
block|,
comment|/* block xsem */
literal|0x09510100
block|,
literal|0x00000020
block|,
comment|/* xsem.fast_memory.gpre, group=IOR, size=32 regs */
literal|0x09510130
block|,
literal|0x00000001
block|,
comment|/* xsem.fast_memory.active_reg_set, group=IOR, size=1 regs */
literal|0x0a518000
block|,
literal|0x00005000
block|,
comment|/* xsem.fast_memory.int_ram, group=RAM, size=20480 regs */
literal|0x062e0000
block|,
comment|/* block ysem */
literal|0x09550100
block|,
literal|0x00000020
block|,
comment|/* ysem.fast_memory.gpre, group=IOR, size=32 regs */
literal|0x09550130
block|,
literal|0x00000001
block|,
comment|/* ysem.fast_memory.active_reg_set, group=IOR, size=1 regs */
literal|0x0a558000
block|,
literal|0x00005000
block|,
comment|/* ysem.fast_memory.int_ram, group=RAM, size=20480 regs */
literal|0x062f0000
block|,
comment|/* block psem */
literal|0x09590100
block|,
literal|0x00000020
block|,
comment|/* psem.fast_memory.gpre, group=IOR, size=32 regs */
literal|0x09590130
block|,
literal|0x00000001
block|,
comment|/* psem.fast_memory.active_reg_set, group=IOR, size=1 regs */
literal|0x0a598000
block|,
literal|0x00005000
block|,
comment|/* psem.fast_memory.int_ram, group=RAM, size=20480 regs */
literal|0x063b0000
block|,
comment|/* block btb */
literal|0x0b36c204
block|,
literal|0x00000004
block|,
comment|/* btb.free_list_head, group=BTB_RAM, size=4 regs */
literal|0x0b36c208
block|,
literal|0x00000004
block|,
comment|/* btb.free_list_tail, group=BTB_RAM, size=4 regs */
literal|0x0b36c20c
block|,
literal|0x00000004
block|,
comment|/* btb.free_list_size, group=BTB_RAM, size=4 regs */
literal|0x08400000
block|,
comment|/* block ccfc */
literal|0x0c0ba200
block|,
literal|0x00000140
block|,
comment|/* ccfc.activity_counter, group=CONN_CFC_MEM, size=320 regs */
literal|0x0c0ba400
block|,
literal|0x00000140
block|,
comment|/* ccfc.info_state, group=CONN_CFC_MEM, size=320 regs */
literal|0x0c0ba600
block|,
literal|0x00000140
block|,
comment|/* ccfc.info_reg, group=CONN_CFC_MEM, size=320 regs */
literal|0x0c0bac00
block|,
literal|0x01000280
block|,
comment|/* ccfc.cid_cam, group=CONN_CFC_MEM, size=640 regs, WB */
literal|0x08410000
block|,
comment|/* block tcfc */
literal|0x0d0b6200
block|,
literal|0x00000140
block|,
comment|/* tcfc.activity_counter, group=TASK_CFC_MEM, size=320 regs */
literal|0x0d0b6400
block|,
literal|0x00000140
block|,
comment|/* tcfc.info_state, group=TASK_CFC_MEM, size=320 regs */
literal|0x0d0b6600
block|,
literal|0x00000140
block|,
comment|/* tcfc.info_reg, group=TASK_CFC_MEM, size=320 regs */
literal|0x0d0b6c00
block|,
literal|0x01000280
block|,
comment|/* tcfc.cid_cam, group=TASK_CFC_MEM, size=640 regs, WB */
literal|0x0a430000
block|,
comment|/* block cau */
literal|0x0e070100
block|,
literal|0x00000001
block|,
comment|/* cau.num_pi_per_sb, group=CAU_PI, size=1 regs */
literal|0x0f070880
block|,
literal|0x01000010
block|,
comment|/* cau.igu_cmd_fifo, group=CAU_MEM, size=16 regs, WB */
literal|0x0f0708c0
block|,
literal|0x01000020
block|,
comment|/* cau.pxp_req_fifo, group=CAU_MEM, size=32 regs, WB */
literal|0x0f070900
block|,
literal|0x01000100
block|,
comment|/* cau.pxp_wdata_fifo, group=CAU_MEM, size=256 regs, WB */
literal|0x0f071100
block|,
literal|0x00000100
block|,
comment|/* cau.fsm_table, group=CAU_MEM, size=256 regs */
literal|0x020d0007
block|,
comment|/* mode bb, block pswhst */
literal|0x000a8200
block|,
literal|0x00000100
block|,
comment|/* pswhst.zone_permission_table, group=PXP_MEM, size=256 regs */
literal|0x02140000
block|,
comment|/* block pswrq2 */
literal|0x10098000
block|,
literal|0x01003b60
block|,
comment|/* pswrq2.ilt_memory, group=PXP_ILT, size=15200 regs, WB */
literal|0x06180000
block|,
comment|/* block tcm */
literal|0x02460580
block|,
literal|0x00000020
block|,
comment|/* tcm.xx_lcid_cam, group=CM_MEM, size=32 regs */
literal|0x024605c0
block|,
literal|0x00000020
block|,
comment|/* tcm.xx_tbl, group=CM_MEM, size=32 regs */
literal|0x02462000
block|,
literal|0x00001600
block|,
comment|/* tcm.xx_msg_ram, group=CM_MEM, size=5632 regs */
literal|0x06190000
block|,
comment|/* block mcm */
literal|0x02480680
block|,
literal|0x00000016
block|,
comment|/* mcm.xx_lcid_cam, group=CM_MEM, size=22 regs */
literal|0x024806c0
block|,
literal|0x00000016
block|,
comment|/* mcm.xx_tbl, group=CM_MEM, size=22 regs */
literal|0x02482000
block|,
literal|0x00001a00
block|,
comment|/* mcm.xx_msg_ram, group=CM_MEM, size=6656 regs */
literal|0x061a0000
block|,
comment|/* block ucm */
literal|0x024a0640
block|,
literal|0x00000018
block|,
comment|/* ucm.xx_lcid_cam, group=CM_MEM, size=24 regs */
literal|0x024a0680
block|,
literal|0x00000018
block|,
comment|/* ucm.xx_tbl, group=CM_MEM, size=24 regs */
literal|0x024a2000
block|,
literal|0x00001a00
block|,
comment|/* ucm.xx_msg_ram, group=CM_MEM, size=6656 regs */
literal|0x041b0000
block|,
comment|/* block xcm */
literal|0x02400640
block|,
literal|0x0000001e
block|,
comment|/* xcm.xx_lcid_cam, group=CM_MEM, size=30 regs */
literal|0x02400680
block|,
literal|0x0000001e
block|,
comment|/* xcm.xx_tbl, group=CM_MEM, size=30 regs */
literal|0x041c0000
block|,
comment|/* block ycm */
literal|0x02420680
block|,
literal|0x00000016
block|,
comment|/* ycm.xx_lcid_cam, group=CM_MEM, size=22 regs */
literal|0x024206c0
block|,
literal|0x00000016
block|,
comment|/* ycm.xx_tbl, group=CM_MEM, size=22 regs */
literal|0x2a1e0000
block|,
comment|/* block qm */
literal|0x030bc180
block|,
literal|0x00000040
block|,
comment|/* qm.BaseAddrOtherPq, group=QM_MEM, size=64 regs */
literal|0x030bc560
block|,
literal|0x00000012
block|,
comment|/* qm.VoqCrdLine, group=QM_MEM, size=18 regs */
literal|0x030bc5a0
block|,
literal|0x00000012
block|,
comment|/* qm.VoqInitCrdLine, group=QM_MEM, size=18 regs */
literal|0x030bc5e0
block|,
literal|0x00000012
block|,
comment|/* qm.VoqCrdByte, group=QM_MEM, size=18 regs */
literal|0x030bc620
block|,
literal|0x00000012
block|,
comment|/* qm.VoqInitCrdByte, group=QM_MEM, size=18 regs */
literal|0x030bc800
block|,
literal|0x00000040
block|,
comment|/* qm.PqFillLvlOther, group=QM_MEM, size=64 regs */
literal|0x030bca00
block|,
literal|0x00000040
block|,
comment|/* qm.PqStsOther, group=QM_MEM, size=64 regs */
literal|0x030bd320
block|,
literal|0x00000008
block|,
comment|/* qm.RlPfIncVal, group=QM_MEM, size=8 regs */
literal|0x030bd340
block|,
literal|0x00000008
block|,
comment|/* qm.RlPfUpperBound, group=QM_MEM, size=8 regs */
literal|0x030bd360
block|,
literal|0x00000008
block|,
comment|/* qm.RlPfCrd, group=QM_MEM, size=8 regs */
literal|0x030bd3a0
block|,
literal|0x00000008
block|,
comment|/* qm.WfqPfWeight, group=QM_MEM, size=8 regs */
literal|0x030bd3c0
block|,
literal|0x00000008
block|,
comment|/* qm.WfqPfUpperBound, group=QM_MEM, size=8 regs */
literal|0x030bd500
block|,
literal|0x00000090
block|,
comment|/* qm.WfqPfCrd, group=QM_MEM, size=144 regs */
literal|0x030bd800
block|,
literal|0x000001c0
block|,
comment|/* qm.BaseAddrTxPq, group=QM_MEM, size=448 regs */
literal|0x030bdc00
block|,
literal|0x000001c0
block|,
comment|/* qm.PqFillLvlTx, group=QM_MEM, size=448 regs */
literal|0x030be000
block|,
literal|0x000001c0
block|,
comment|/* qm.PqStsTx, group=QM_MEM, size=448 regs */
literal|0x030be400
block|,
literal|0x000001c0
block|,
comment|/* qm.TxPqMap, group=QM_MEM, size=448 regs */
literal|0x030be800
block|,
literal|0x000001c0
block|,
comment|/* qm.WfqVpWeight, group=QM_MEM, size=448 regs */
literal|0x030bec00
block|,
literal|0x000001c0
block|,
comment|/* qm.WfqVpUpperBound, group=QM_MEM, size=448 regs */
literal|0x030bf000
block|,
literal|0x000001c0
block|,
comment|/* qm.WfqVpCrd, group=QM_MEM, size=448 regs */
literal|0x030bf400
block|,
literal|0x000001c0
block|,
comment|/* qm.WfqVpMap, group=QM_MEM, size=448 regs */
literal|0x021f0000
block|,
comment|/* block tm */
literal|0x040b0800
block|,
literal|0x01000130
block|,
comment|/* tm.config_task_mem, group=TM_MEM, size=304 regs, WB */
literal|0x04210000
block|,
comment|/* block brb */
literal|0x060d0680
block|,
literal|0x00000022
block|,
comment|/* brb.per_tc_counters, group=BRB_MEM, size=34 regs */
literal|0x050d2000
block|,
literal|0x000012c0
block|,
comment|/* brb.link_list, group=BRB_RAM, size=4800 regs */
literal|0x022a0000
block|,
comment|/* block tsem */
literal|0x115c8000
block|,
literal|0x010010e0
block|,
comment|/* tsem.passive_buffer, group=PBUF, size=4320 regs, WB */
literal|0x022b0000
block|,
comment|/* block msem */
literal|0x11608000
block|,
literal|0x010010e0
block|,
comment|/* msem.passive_buffer, group=PBUF, size=4320 regs, WB */
literal|0x022c0000
block|,
comment|/* block usem */
literal|0x11648000
block|,
literal|0x01000b40
block|,
comment|/* usem.passive_buffer, group=PBUF, size=2880 regs, WB */
literal|0x022d0000
block|,
comment|/* block xsem */
literal|0x11508000
block|,
literal|0x010010e0
block|,
comment|/* xsem.passive_buffer, group=PBUF, size=4320 regs, WB */
literal|0x022e0000
block|,
comment|/* block ysem */
literal|0x11548000
block|,
literal|0x010009d8
block|,
comment|/* ysem.passive_buffer, group=PBUF, size=2520 regs, WB */
literal|0x022f0000
block|,
comment|/* block psem */
literal|0x11588000
block|,
literal|0x010002d0
block|,
comment|/* psem.passive_buffer, group=PBUF, size=720 regs, WB */
literal|0x04320000
block|,
comment|/* block muld */
literal|0x12139000
block|,
literal|0x01000800
block|,
comment|/* muld.bd_db_arr_dw, group=MULD_MEM, size=2048 regs, WB */
literal|0x1213a000
block|,
literal|0x01000800
block|,
comment|/* muld.sge_db_arr_dw, group=MULD_MEM, size=2048 regs, WB */
literal|0x063b0000
block|,
comment|/* block btb */
literal|0x1336c400
block|,
literal|0x01000008
block|,
comment|/* btb.stopped_rd_req, group=BTB_MEM, size=8 regs, WB */
literal|0x1336c440
block|,
literal|0x01000008
block|,
comment|/* btb.stopped_rls_req, group=BTB_MEM, size=8 regs, WB */
literal|0x0b36d000
block|,
literal|0x00000b40
block|,
comment|/* btb.link_list, group=BTB_RAM, size=2880 regs */
literal|0x023d0000
block|,
comment|/* block rdif */
literal|0x140c1000
block|,
literal|0x01000a00
block|,
comment|/* rdif.l1_task_context, group=RDIF_CTX, size=2560 regs, WB */
literal|0x023e0000
block|,
comment|/* block tdif */
literal|0x150c6000
block|,
literal|0x01001400
block|,
comment|/* tdif.l1_task_context, group=TDIF_CTX, size=5120 regs, WB */
literal|0x02400000
block|,
comment|/* block ccfc */
literal|0x160b81d0
block|,
literal|0x0000000e
block|,
comment|/* ccfc.lcreq_credit, group=CFC_MEM, size=14 regs */
literal|0x02410000
block|,
comment|/* block tcfc */
literal|0x160b41d0
block|,
literal|0x0000000e
block|,
comment|/* tcfc.lcreq_credit, group=CFC_MEM, size=14 regs */
literal|0x0c420000
block|,
comment|/* block igu */
literal|0x17060220
block|,
literal|0x00000009
block|,
comment|/* igu.pending_bits_status, group=IGU_MEM, size=9 regs */
literal|0x17060240
block|,
literal|0x00000009
block|,
comment|/* igu.write_done_pending, group=IGU_MEM, size=9 regs */
literal|0x17060800
block|,
literal|0x00000128
block|,
comment|/* igu.producer_memory, group=IGU_MEM, size=296 regs */
literal|0x17060c00
block|,
literal|0x00000128
block|,
comment|/* igu.consumer_mem, group=IGU_MEM, size=296 regs */
literal|0x17061000
block|,
literal|0x00000120
block|,
comment|/* igu.mapping_memory, group=IGU_MEM, size=288 regs */
literal|0x18061800
block|,
literal|0x01000480
block|,
comment|/* igu.msix_memory, group=IGU_MSIX, size=1152 regs, WB */
literal|0x06430000
block|,
comment|/* block cau */
literal|0x19071800
block|,
literal|0x01000240
block|,
comment|/* cau.sb_var_memory, group=CAU_SB, size=576 regs, WB */
literal|0x19072000
block|,
literal|0x01000240
block|,
comment|/* cau.sb_addr_memory, group=CAU_SB, size=576 regs, WB */
literal|0x0e074000
block|,
literal|0x00000d80
block|,
comment|/* cau.pi_memory, group=CAU_PI, size=3456 regs */
literal|0x06180009
block|,
comment|/* mode k2, block tcm */
literal|0x02460580
block|,
literal|0x00000020
block|,
comment|/* tcm.xx_lcid_cam, group=CM_MEM, size=32 regs */
literal|0x024605c0
block|,
literal|0x00000020
block|,
comment|/* tcm.xx_tbl, group=CM_MEM, size=32 regs */
literal|0x02462000
block|,
literal|0x00001600
block|,
comment|/* tcm.xx_msg_ram, group=CM_MEM, size=5632 regs */
literal|0x06190000
block|,
comment|/* block mcm */
literal|0x02480680
block|,
literal|0x00000016
block|,
comment|/* mcm.xx_lcid_cam, group=CM_MEM, size=22 regs */
literal|0x024806c0
block|,
literal|0x00000016
block|,
comment|/* mcm.xx_tbl, group=CM_MEM, size=22 regs */
literal|0x02482000
block|,
literal|0x00001a00
block|,
comment|/* mcm.xx_msg_ram, group=CM_MEM, size=6656 regs */
literal|0x061a0000
block|,
comment|/* block ucm */
literal|0x024a0640
block|,
literal|0x00000018
block|,
comment|/* ucm.xx_lcid_cam, group=CM_MEM, size=24 regs */
literal|0x024a0680
block|,
literal|0x00000018
block|,
comment|/* ucm.xx_tbl, group=CM_MEM, size=24 regs */
literal|0x024a2000
block|,
literal|0x00001a00
block|,
comment|/* ucm.xx_msg_ram, group=CM_MEM, size=6656 regs */
literal|0x041b0000
block|,
comment|/* block xcm */
literal|0x02400640
block|,
literal|0x0000001e
block|,
comment|/* xcm.xx_lcid_cam, group=CM_MEM, size=30 regs */
literal|0x02400680
block|,
literal|0x0000001e
block|,
comment|/* xcm.xx_tbl, group=CM_MEM, size=30 regs */
literal|0x041c0000
block|,
comment|/* block ycm */
literal|0x02420680
block|,
literal|0x00000016
block|,
comment|/* ycm.xx_lcid_cam, group=CM_MEM, size=22 regs */
literal|0x024206c0
block|,
literal|0x00000016
block|,
comment|/* ycm.xx_tbl, group=CM_MEM, size=22 regs */
literal|0x0e1e0000
block|,
comment|/* block qm */
literal|0x030bc560
block|,
literal|0x00000014
block|,
comment|/* qm.VoqCrdLine, group=QM_MEM, size=20 regs */
literal|0x030bc5a0
block|,
literal|0x00000014
block|,
comment|/* qm.VoqInitCrdLine, group=QM_MEM, size=20 regs */
literal|0x030bc5e0
block|,
literal|0x00000014
block|,
comment|/* qm.VoqCrdByte, group=QM_MEM, size=20 regs */
literal|0x030bc620
block|,
literal|0x00000014
block|,
comment|/* qm.VoqInitCrdByte, group=QM_MEM, size=20 regs */
literal|0x030bd500
block|,
literal|0x000000a0
block|,
comment|/* qm.WfqPfCrd, group=QM_MEM, size=160 regs */
literal|0x030bfc00
block|,
literal|0x00000048
block|,
comment|/* qm.CMIntQMask_msb, group=QM_MEM, size=72 regs */
literal|0x030bfd00
block|,
literal|0x000000a0
block|,
comment|/* qm.WfqPfCrd_msb, group=QM_MEM, size=160 regs */
literal|0x041f0000
block|,
comment|/* block tm */
literal|0x040b0400
block|,
literal|0x010001a0
block|,
comment|/* tm.config_conn_mem, group=TM_MEM, size=416 regs, WB */
literal|0x040b0800
block|,
literal|0x01000200
block|,
comment|/* tm.config_task_mem, group=TM_MEM, size=512 regs, WB */
literal|0x04210000
block|,
comment|/* block brb */
literal|0x060d0680
block|,
literal|0x00000022
block|,
comment|/* brb.per_tc_counters, group=BRB_MEM, size=34 regs */
literal|0x050d2000
block|,
literal|0x00001e00
block|,
comment|/* brb.link_list, group=BRB_RAM, size=7680 regs */
literal|0x022a0000
block|,
comment|/* block tsem */
literal|0x115c8000
block|,
literal|0x010010e0
block|,
comment|/* tsem.passive_buffer, group=PBUF, size=4320 regs, WB */
literal|0x022b0000
block|,
comment|/* block msem */
literal|0x11608000
block|,
literal|0x010010e0
block|,
comment|/* msem.passive_buffer, group=PBUF, size=4320 regs, WB */
literal|0x022c0000
block|,
comment|/* block usem */
literal|0x11648000
block|,
literal|0x01000b40
block|,
comment|/* usem.passive_buffer, group=PBUF, size=2880 regs, WB */
literal|0x022d0000
block|,
comment|/* block xsem */
literal|0x11508000
block|,
literal|0x010010e0
block|,
comment|/* xsem.passive_buffer, group=PBUF, size=4320 regs, WB */
literal|0x022e0000
block|,
comment|/* block ysem */
literal|0x11548000
block|,
literal|0x010009d8
block|,
comment|/* ysem.passive_buffer, group=PBUF, size=2520 regs, WB */
literal|0x022f0000
block|,
comment|/* block psem */
literal|0x11588000
block|,
literal|0x010002d0
block|,
comment|/* psem.passive_buffer, group=PBUF, size=720 regs, WB */
literal|0x04320000
block|,
comment|/* block muld */
literal|0x12139000
block|,
literal|0x01000a00
block|,
comment|/* muld.bd_db_arr_dw, group=MULD_MEM, size=2560 regs, WB */
literal|0x1213a000
block|,
literal|0x01000a00
block|,
comment|/* muld.sge_db_arr_dw, group=MULD_MEM, size=2560 regs, WB */
literal|0x043b0000
block|,
comment|/* block btb */
literal|0x1336c400
block|,
literal|0x01000010
block|,
comment|/* btb.stopped_rd_req, group=BTB_MEM, size=16 regs, WB */
literal|0x0b36d000
block|,
literal|0x00000e60
block|,
comment|/* btb.link_list, group=BTB_RAM, size=3680 regs */
literal|0x023d0000
block|,
comment|/* block rdif */
literal|0x140c1000
block|,
literal|0x01000a00
block|,
comment|/* rdif.l1_task_context, group=RDIF_CTX, size=2560 regs, WB */
literal|0x023e0000
block|,
comment|/* block tdif */
literal|0x150c6000
block|,
literal|0x01001400
block|,
comment|/* tdif.l1_task_context, group=TDIF_CTX, size=5120 regs, WB */
literal|0x02400000
block|,
comment|/* block ccfc */
literal|0x160b81d0
block|,
literal|0x0000000e
block|,
comment|/* ccfc.lcreq_credit, group=CFC_MEM, size=14 regs */
literal|0x02410000
block|,
comment|/* block tcfc */
literal|0x160b41d0
block|,
literal|0x0000000e
block|,
comment|/* tcfc.lcreq_credit, group=CFC_MEM, size=14 regs */
literal|0x0c420000
block|,
comment|/* block igu */
literal|0x17060220
block|,
literal|0x0000000c
block|,
comment|/* igu.pending_bits_status, group=IGU_MEM, size=12 regs */
literal|0x17060240
block|,
literal|0x0000000c
block|,
comment|/* igu.write_done_pending, group=IGU_MEM, size=12 regs */
literal|0x17060800
block|,
literal|0x00000180
block|,
comment|/* igu.producer_memory, group=IGU_MEM, size=384 regs */
literal|0x17060c00
block|,
literal|0x00000180
block|,
comment|/* igu.consumer_mem, group=IGU_MEM, size=384 regs */
literal|0x17061000
block|,
literal|0x00000170
block|,
comment|/* igu.mapping_memory, group=IGU_MEM, size=368 regs */
literal|0x18061800
block|,
literal|0x010005c0
block|,
comment|/* igu.msix_memory, group=IGU_MSIX, size=1472 regs, WB */
literal|0x06430000
block|,
comment|/* block cau */
literal|0x19071800
block|,
literal|0x010002e0
block|,
comment|/* cau.sb_var_memory, group=CAU_SB, size=736 regs, WB */
literal|0x19072000
block|,
literal|0x010002e0
block|,
comment|/* cau.sb_addr_memory, group=CAU_SB, size=736 regs, WB */
literal|0x0e074000
block|,
literal|0x00001140
block|,
comment|/* cau.pi_memory, group=CAU_PI, size=4416 regs */
literal|0x020d0025
block|,
comment|/* mode !bb, block pswhst */
literal|0x000a8200
block|,
literal|0x00000140
block|,
comment|/* pswhst.zone_permission_table, group=PXP_MEM, size=320 regs */
literal|0x02140000
block|,
comment|/* block pswrq2 */
literal|0x10098000
block|,
literal|0x010055f0
block|,
comment|/* pswrq2.ilt_memory, group=PXP_ILT, size=22000 regs, WB */
literal|0x201e0000
block|,
comment|/* block qm */
literal|0x030bc180
block|,
literal|0x00000080
block|,
comment|/* qm.BaseAddrOtherPq, group=QM_MEM, size=128 regs */
literal|0x030bc800
block|,
literal|0x00000080
block|,
comment|/* qm.PqFillLvlOther, group=QM_MEM, size=128 regs */
literal|0x030bca00
block|,
literal|0x00000080
block|,
comment|/* qm.PqStsOther, group=QM_MEM, size=128 regs */
literal|0x030bd320
block|,
literal|0x00000010
block|,
comment|/* qm.RlPfIncVal, group=QM_MEM, size=16 regs */
literal|0x030bd340
block|,
literal|0x00000010
block|,
comment|/* qm.RlPfUpperBound, group=QM_MEM, size=16 regs */
literal|0x030bd360
block|,
literal|0x00000010
block|,
comment|/* qm.RlPfCrd, group=QM_MEM, size=16 regs */
literal|0x030bd3a0
block|,
literal|0x00000010
block|,
comment|/* qm.WfqPfWeight, group=QM_MEM, size=16 regs */
literal|0x030bd3c0
block|,
literal|0x00000010
block|,
comment|/* qm.WfqPfUpperBound, group=QM_MEM, size=16 regs */
literal|0x030bd800
block|,
literal|0x00000200
block|,
comment|/* qm.BaseAddrTxPq, group=QM_MEM, size=512 regs */
literal|0x030bdc00
block|,
literal|0x00000200
block|,
comment|/* qm.PqFillLvlTx, group=QM_MEM, size=512 regs */
literal|0x030be000
block|,
literal|0x00000200
block|,
comment|/* qm.PqStsTx, group=QM_MEM, size=512 regs */
literal|0x030be400
block|,
literal|0x00000200
block|,
comment|/* qm.TxPqMap, group=QM_MEM, size=512 regs */
literal|0x030be800
block|,
literal|0x00000200
block|,
comment|/* qm.WfqVpWeight, group=QM_MEM, size=512 regs */
literal|0x030bec00
block|,
literal|0x00000200
block|,
comment|/* qm.WfqVpUpperBound, group=QM_MEM, size=512 regs */
literal|0x030bf000
block|,
literal|0x00000200
block|,
comment|/* qm.WfqVpCrd, group=QM_MEM, size=512 regs */
literal|0x030bf400
block|,
literal|0x00000200
block|,
comment|/* qm.WfqVpMap, group=QM_MEM, size=512 regs */
literal|0x023b0000
block|,
comment|/* block btb */
literal|0x1336c440
block|,
literal|0x01000010
block|,
comment|/* btb.stopped_rls_req, group=BTB_MEM, size=16 regs, WB */
literal|0x06180003
block|,
comment|/* mode !(bb|k2), block tcm */
literal|0x02460580
block|,
literal|0x00000040
block|,
comment|/* tcm.xx_lcid_cam, group=CM_MEM, size=64 regs */
literal|0x024605c0
block|,
literal|0x00000040
block|,
comment|/* tcm.xx_tbl, group=CM_MEM, size=64 regs */
literal|0x02462000
block|,
literal|0x00001800
block|,
comment|/* tcm.xx_msg_ram, group=CM_MEM, size=6144 regs */
literal|0x06190000
block|,
comment|/* block mcm */
literal|0x02480680
block|,
literal|0x00000040
block|,
comment|/* mcm.xx_lcid_cam, group=CM_MEM, size=64 regs */
literal|0x024806c0
block|,
literal|0x00000040
block|,
comment|/* mcm.xx_tbl, group=CM_MEM, size=64 regs */
literal|0x02482000
block|,
literal|0x00001c00
block|,
comment|/* mcm.xx_msg_ram, group=CM_MEM, size=7168 regs */
literal|0x061a0000
block|,
comment|/* block ucm */
literal|0x024a0640
block|,
literal|0x00000040
block|,
comment|/* ucm.xx_lcid_cam, group=CM_MEM, size=64 regs */
literal|0x024a0680
block|,
literal|0x00000040
block|,
comment|/* ucm.xx_tbl, group=CM_MEM, size=64 regs */
literal|0x024a2000
block|,
literal|0x00001c00
block|,
comment|/* ucm.xx_msg_ram, group=CM_MEM, size=7168 regs */
literal|0x041b0000
block|,
comment|/* block xcm */
literal|0x02400640
block|,
literal|0x00000040
block|,
comment|/* xcm.xx_lcid_cam, group=CM_MEM, size=64 regs */
literal|0x02400680
block|,
literal|0x00000040
block|,
comment|/* xcm.xx_tbl, group=CM_MEM, size=64 regs */
literal|0x041c0000
block|,
comment|/* block ycm */
literal|0x02420680
block|,
literal|0x00000040
block|,
comment|/* ycm.xx_lcid_cam, group=CM_MEM, size=64 regs */
literal|0x024206c0
block|,
literal|0x00000040
block|,
comment|/* ycm.xx_tbl, group=CM_MEM, size=64 regs */
literal|0x0e1e0000
block|,
comment|/* block qm */
literal|0x030bd500
block|,
literal|0x00000100
block|,
comment|/* qm.WfqPfCrd, group=QM_MEM, size=256 regs */
literal|0x030bfc00
block|,
literal|0x00000140
block|,
comment|/* qm.WfqPfCrd_msb, group=QM_MEM, size=320 regs */
literal|0x030bfe00
block|,
literal|0x00000048
block|,
comment|/* qm.CMIntQMask_msb, group=QM_MEM, size=72 regs */
literal|0x030bfe80
block|,
literal|0x00000024
block|,
comment|/* qm.VoqCrdLine, group=QM_MEM, size=36 regs */
literal|0x030bfec0
block|,
literal|0x00000024
block|,
comment|/* qm.VoqInitCrdLine, group=QM_MEM, size=36 regs */
literal|0x030bff00
block|,
literal|0x00000024
block|,
comment|/* qm.VoqCrdByte, group=QM_MEM, size=36 regs */
literal|0x030bff40
block|,
literal|0x00000024
block|,
comment|/* qm.VoqInitCrdByte, group=QM_MEM, size=36 regs */
literal|0x021f0000
block|,
comment|/* block tm */
literal|0x040b0800
block|,
literal|0x01000260
block|,
comment|/* tm.config_task_mem, group=TM_MEM, size=608 regs, WB */
literal|0x04210000
block|,
comment|/* block brb */
literal|0x060d0680
block|,
literal|0x00000024
block|,
comment|/* brb.per_tc_counters, group=BRB_MEM, size=36 regs */
literal|0x050d4000
block|,
literal|0x00002280
block|,
comment|/* brb.link_list, group=BRB_RAM, size=8832 regs */
literal|0x022a0000
block|,
comment|/* block tsem */
literal|0x115c8000
block|,
literal|0x00003100
block|,
comment|/* tsem.passive_buffer, group=PBUF, size=12544 regs */
literal|0x022b0000
block|,
comment|/* block msem */
literal|0x11608000
block|,
literal|0x00003100
block|,
comment|/* msem.passive_buffer, group=PBUF, size=12544 regs */
literal|0x022c0000
block|,
comment|/* block usem */
literal|0x11648000
block|,
literal|0x00003100
block|,
comment|/* usem.passive_buffer, group=PBUF, size=12544 regs */
literal|0x022d0000
block|,
comment|/* block xsem */
literal|0x11508000
block|,
literal|0x00003100
block|,
comment|/* xsem.passive_buffer, group=PBUF, size=12544 regs */
literal|0x022e0000
block|,
comment|/* block ysem */
literal|0x11548000
block|,
literal|0x00003100
block|,
comment|/* ysem.passive_buffer, group=PBUF, size=12544 regs */
literal|0x022f0000
block|,
comment|/* block psem */
literal|0x11588000
block|,
literal|0x00003100
block|,
comment|/* psem.passive_buffer, group=PBUF, size=12544 regs */
literal|0x04320000
block|,
comment|/* block muld */
literal|0x12139000
block|,
literal|0x01001000
block|,
comment|/* muld.bd_db_arr_dw, group=MULD_MEM, size=4096 regs, WB */
literal|0x1213a000
block|,
literal|0x01001000
block|,
comment|/* muld.sge_db_arr_dw, group=MULD_MEM, size=4096 regs, WB */
literal|0x043b0000
block|,
comment|/* block btb */
literal|0x1336c400
block|,
literal|0x01000020
block|,
comment|/* btb.stopped_rd_req, group=BTB_MEM, size=32 regs, WB */
literal|0x0b36e000
block|,
literal|0x000014a0
block|,
comment|/* btb.link_list, group=BTB_RAM, size=5280 regs */
literal|0x023d0000
block|,
comment|/* block rdif */
literal|0x140c2000
block|,
literal|0x01001800
block|,
comment|/* rdif.l1_task_context, group=RDIF_CTX, size=6144 regs, WB */
literal|0x023e0000
block|,
comment|/* block tdif */
literal|0x150c6000
block|,
literal|0x01001800
block|,
comment|/* tdif.l1_task_context, group=TDIF_CTX, size=6144 regs, WB */
literal|0x02400000
block|,
comment|/* block ccfc */
literal|0x160b81d0
block|,
literal|0x0000000d
block|,
comment|/* ccfc.lcreq_credit, group=CFC_MEM, size=13 regs */
literal|0x02410000
block|,
comment|/* block tcfc */
literal|0x160b41d0
block|,
literal|0x0000000d
block|,
comment|/* tcfc.lcreq_credit, group=CFC_MEM, size=13 regs */
literal|0x0c420000
block|,
comment|/* block igu */
literal|0x17060220
block|,
literal|0x00000010
block|,
comment|/* igu.pending_bits_status, group=IGU_MEM, size=16 regs */
literal|0x17060240
block|,
literal|0x00000010
block|,
comment|/* igu.write_done_pending, group=IGU_MEM, size=16 regs */
literal|0x17060800
block|,
literal|0x00000210
block|,
comment|/* igu.producer_memory, group=IGU_MEM, size=528 regs */
literal|0x17060c00
block|,
literal|0x00000210
block|,
comment|/* igu.consumer_mem, group=IGU_MEM, size=528 regs */
literal|0x17061000
block|,
literal|0x00000200
block|,
comment|/* igu.mapping_memory, group=IGU_MEM, size=512 regs */
literal|0x18061800
block|,
literal|0x01000800
block|,
comment|/* igu.msix_memory, group=IGU_MSIX, size=2048 regs, WB */
literal|0x06430000
block|,
comment|/* block cau */
literal|0x19071800
block|,
literal|0x01000400
block|,
comment|/* cau.sb_var_memory, group=CAU_SB, size=1024 regs, WB */
literal|0x19072000
block|,
literal|0x01000400
block|,
comment|/* cau.sb_addr_memory, group=CAU_SB, size=1024 regs, WB */
literal|0x0e074000
block|,
literal|0x00001000
block|,
comment|/* cau.pi_memory, group=CAU_PI, size=4096 regs */
literal|0x02230043
block|,
comment|/* mode !e5, block prs */
literal|0x0707c300
block|,
literal|0x00000080
block|,
comment|/* prs.last_pkt_list, group=PRS_MEM, size=128 regs */
literal|0x022a0000
block|,
comment|/* block tsem */
literal|0x115c02c4
block|,
literal|0x00000001
block|,
comment|/* tsem.thread_valid, group=PBUF, size=1 regs */
literal|0x022b0000
block|,
comment|/* block msem */
literal|0x116002c4
block|,
literal|0x00000001
block|,
comment|/* msem.thread_valid, group=PBUF, size=1 regs */
literal|0x022c0000
block|,
comment|/* block usem */
literal|0x116402c4
block|,
literal|0x00000001
block|,
comment|/* usem.thread_valid, group=PBUF, size=1 regs */
literal|0x022d0000
block|,
comment|/* block xsem */
literal|0x115002c4
block|,
literal|0x00000001
block|,
comment|/* xsem.thread_valid, group=PBUF, size=1 regs */
literal|0x022e0000
block|,
comment|/* block ysem */
literal|0x115402c4
block|,
literal|0x00000001
block|,
comment|/* ysem.thread_valid, group=PBUF, size=1 regs */
literal|0x022f0000
block|,
comment|/* block psem */
literal|0x115802c4
block|,
literal|0x00000001
block|,
comment|/* psem.thread_valid, group=PBUF, size=1 regs */
literal|0x04430000
block|,
comment|/* block cau */
literal|0x0f070800
block|,
literal|0x01000078
block|,
comment|/* cau.cqe_fifo, group=CAU_MEM, size=120 regs, WB */
literal|0x0f077000
block|,
literal|0x01000100
block|,
comment|/* cau.agg_unit_descriptor, group=CAU_MEM, size=256 regs, WB */
literal|0x021f01a3
block|,
comment|/* mode !k2, block tm */
literal|0x040b0400
block|,
literal|0x01000100
block|,
comment|/* tm.config_conn_mem, group=TM_MEM, size=256 regs, WB */
literal|0x0809000b
block|,
comment|/* mode !(emul_reduced|fpga), block bmb */
literal|0x1a150204
block|,
literal|0x00000004
block|,
comment|/* bmb.free_list_head, group=BMB_RAM, size=4 regs */
literal|0x1a150208
block|,
literal|0x00000004
block|,
comment|/* bmb.free_list_tail, group=BMB_RAM, size=4 regs */
literal|0x1a15020c
block|,
literal|0x00000004
block|,
comment|/* bmb.free_list_size, group=BMB_RAM, size=4 regs */
literal|0x1a150800
block|,
literal|0x00000480
block|,
comment|/* bmb.link_list, group=BMB_RAM, size=1152 regs */
literal|0x04090001
block|,
comment|/* mode (!(bb|k2))&(!(emul_reduced|fpga)), block bmb */
literal|0x1b150480
block|,
literal|0x01000006
block|,
comment|/* bmb.stopped_rd_req, group=BMB_MEM, size=6 regs, WB */
literal|0x1b1504c0
block|,
literal|0x0100000c
block|,
comment|/* bmb.stopped_rls_req, group=BMB_MEM, size=12 regs, WB */
literal|0x040900b7
block|,
comment|/* mode bb&(!(emul_reduced|fpga)), block bmb */
literal|0x1b150480
block|,
literal|0x01000014
block|,
comment|/* bmb.stopped_rd_req, group=BMB_MEM, size=20 regs, WB */
literal|0x1b1504c0
block|,
literal|0x01000028
block|,
comment|/* bmb.stopped_rls_req, group=BMB_MEM, size=40 regs, WB */
literal|0x04090087
block|,
comment|/* mode k2&(!(emul_reduced|fpga)), block bmb */
literal|0x1b150480
block|,
literal|0x01000014
block|,
comment|/* bmb.stopped_rd_req, group=BMB_MEM, size=20 regs, WB */
literal|0x1b1504c0
block|,
literal|0x01000028
block|,
comment|/* bmb.stopped_rls_req, group=BMB_MEM, size=40 regs, WB */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 2648 bytes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PREVENT_DUMP_MEM_ARR__ */
end_comment

begin_comment
comment|/* Idle check registers */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|idle_chk_regs
index|[]
init|=
block|{
literal|0x02002060
block|,
literal|0x00010001
block|,
comment|/* cond: misc.INT_STS */
literal|0x02002061
block|,
literal|0x00010001
block|,
comment|/* cond: misc.INT_MASK */
literal|0x020021ed
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_1_igu */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021ee
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_2_igu */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f0
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_4_igu */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f1
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_5_igu */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f2
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_6_igu */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f3
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_7_igu */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f4
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_8_igu */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f5
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_9_igu */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f6
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_1_mcp */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f7
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_2_mcp */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021f9
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_4_mcp */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021fa
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_5_mcp */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021fb
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_6_mcp */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021fc
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_7_mcp */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021fd
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_8_mcp */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021fe
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_after_invert_9_mcp */
literal|0x0200220f
block|,
literal|0x00000001
block|,
comment|/* info: misc.attn_num_st mode=all */
literal|0x020021ff
block|,
literal|0x00010001
block|,
comment|/* cond: misc.aeu_sys_kill_occurred */
literal|0x01002460
block|,
literal|0x00010001
block|,
comment|/* cond: miscs.INT_STS_0 */
literal|0x01002461
block|,
literal|0x00010001
block|,
comment|/* cond: miscs.INT_MASK_0 */
literal|0x010025bf
block|,
literal|0x00010001
block|,
comment|/* cond: miscs.pcie_hot_reset */
literal|0x16003012
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c0 */
literal|0x16003013
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c1 */
literal|0x16003014
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c2 */
literal|0x16003015
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c3 */
literal|0x16003016
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c4 */
literal|0x16003017
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c5 */
literal|0x16003018
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c6 */
literal|0x16003019
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c7 */
literal|0x1600301a
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c8 */
literal|0x1600301b
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c9 */
literal|0x1600301c
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c10 */
literal|0x1600301d
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c11 */
literal|0x1600301e
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c12 */
literal|0x1600301f
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c13 */
literal|0x16003020
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c14 */
literal|0x16003021
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c15 */
literal|0x16003022
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c16 */
literal|0x16003023
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c17 */
literal|0x16003024
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c18 */
literal|0x16003025
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c19 */
literal|0x16003026
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c20 */
literal|0x16003027
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c21 */
literal|0x16003028
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c22 */
literal|0x16003029
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c23 */
literal|0x1600302a
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c24 */
literal|0x1600302b
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c25 */
literal|0x1600302c
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c26 */
literal|0x1600302d
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c27 */
literal|0x1600302e
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c28 */
literal|0x1600302f
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c29 */
literal|0x16003030
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c30 */
literal|0x16003031
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.go_c31 */
literal|0x16003080
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.PRTY_STS_H_0 */
literal|0x16003081
block|,
literal|0x00010001
block|,
comment|/* cond: dmae.PRTY_MASK_H_0 */
literal|0x4a004080
block|,
literal|0x00010001
block|,
comment|/* cond: dbg.PRTY_STS_H_0 */
literal|0x4a004081
block|,
literal|0x00010001
block|,
comment|/* cond: dbg.PRTY_MASK_H_0 */
literal|0x00014019
block|,
literal|0x00010001
block|,
comment|/* cond: grc.trace_fifo_valid_data */
literal|0x00014060
block|,
literal|0x00010001
block|,
comment|/* cond: grc.INT_STS_0 */
literal|0x00014061
block|,
literal|0x00010001
block|,
comment|/* cond: grc.INT_MASK_0 */
literal|0x00014080
block|,
literal|0x00010001
block|,
comment|/* cond: grc.PRTY_STS_H_0 */
literal|0x00014081
block|,
literal|0x00010001
block|,
comment|/* cond: grc.PRTY_MASK_H_0 */
literal|0x20040060
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.INT_STS */
literal|0x20040061
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.INT_MASK */
literal|0x20040080
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.PRTY_STS_H_0 */
literal|0x20040081
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.PRTY_MASK_H_0 */
literal|0x20040260
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.xcm_msg_init_crd */
literal|0x20040261
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.tcm_msg_init_crd */
literal|0x20040262
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.ucm_msg_init_crd */
literal|0x20040263
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.pbf_cmd_init_crd */
literal|0x20040270
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.pf_usage_cnt */
literal|0x20040271
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.vf_usage_cnt */
literal|0x20040282
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.cfc_ld_req_fifo_fill_lvl */
literal|0x20040283
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.dorq_fifo_fill_lvl */
literal|0x20040286
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.db_drop_cnt */
literal|0x20040289
block|,
literal|0x00000001
block|,
comment|/* info: dorq.db_drop_details mode=all */
literal|0x20040288
block|,
literal|0x00000001
block|,
comment|/* info: dorq.db_drop_details_reason mode=all */
literal|0x2004028c
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.dpm_abort_cnt */
literal|0x20040293
block|,
literal|0x00000001
block|,
comment|/* info: dorq.dpm_abort_reason mode=all */
literal|0x20040291
block|,
literal|0x00000001
block|,
comment|/* info: dorq.dpm_abort_details_reason mode=all */
literal|0x200402a2
block|,
literal|0x00010001
block|,
comment|/* cond: dorq.dpm_tbl_fill_lvl */
literal|0x42060064
block|,
literal|0x00010001
block|,
comment|/* cond: igu.PRTY_STS */
literal|0x42060065
block|,
literal|0x00010001
block|,
comment|/* cond: igu.PRTY_MASK */
literal|0x42060080
block|,
literal|0x00010001
block|,
comment|/* cond: igu.PRTY_STS_H_0 */
literal|0x42060081
block|,
literal|0x00010001
block|,
comment|/* cond: igu.PRTY_MASK_H_0 */
literal|0x42060545
block|,
literal|0x00010001
block|,
comment|/* cond: igu.attn_write_done_pending */
literal|0x42060547
block|,
literal|0x00010001
block|,
comment|/* cond: igu.Interrupt_status */
literal|0x4206054c
block|,
literal|0x00010001
block|,
comment|/* cond: igu.error_handling_data_valid */
literal|0x4206054d
block|,
literal|0x00010001
block|,
comment|/* cond: igu.silent_drop */
literal|0x4206054f
block|,
literal|0x00010001
block|,
comment|/* cond: igu.sb_ctrl_fsm */
literal|0x42060550
block|,
literal|0x00010001
block|,
comment|/* cond: igu.int_handle_fsm */
literal|0x42060551
block|,
literal|0x00010001
block|,
comment|/* cond: igu.attn_fsm */
literal|0x42060555
block|,
literal|0x00010001
block|,
comment|/* cond: igu.ctrl_fsm */
literal|0x42060556
block|,
literal|0x00010001
block|,
comment|/* cond: igu.pxp_arb_fsm */
literal|0x43070080
block|,
literal|0x00010001
block|,
comment|/* cond: cau.PRTY_STS_H_0 */
literal|0x43070081
block|,
literal|0x00010001
block|,
comment|/* cond: cau.PRTY_MASK_H_0 */
literal|0x43070260
block|,
literal|0x00010001
block|,
comment|/* cond: cau.igu_req_credit_status */
literal|0x43070261
block|,
literal|0x00010001
block|,
comment|/* cond: cau.igu_cmd_credit_status */
literal|0x43070320
block|,
literal|0x00010001
block|,
comment|/* cond: cau.debug_fifo_status */
literal|0x43070321
block|,
literal|0x00010001
block|,
comment|/* cond: cau.error_pxp_req */
literal|0x43070322
block|,
literal|0x00010001
block|,
comment|/* cond: cau.error_fsm_line */
literal|0x43070323
block|,
literal|0x00000001
block|,
comment|/* info: cau.error_fsm_line_pre mode=all */
literal|0x43070324
block|,
literal|0x00010001
block|,
comment|/* cond: cau.parity_latch_status */
literal|0x43070325
block|,
literal|0x00010001
block|,
comment|/* cond: cau.error_cleanup_cmd_reg */
literal|0x43070380
block|,
literal|0x00010001
block|,
comment|/* cond: cau.req_counter */
literal|0x43070381
block|,
literal|0x00010001
block|,
comment|/* cond: cau.ack_counter */
literal|0x43070380
block|,
literal|0x00010001
block|,
comment|/* cond: cau.req_counter */
literal|0x43070382
block|,
literal|0x00010001
block|,
comment|/* cond: cau.wdone_counter */
literal|0x430703c0
block|,
literal|0x00010001
block|,
comment|/* cond: cau.main_fsm_status */
literal|0x430703c1
block|,
literal|0x00010001
block|,
comment|/* cond: cau.var_read_fsm_status */
literal|0x430703c2
block|,
literal|0x00010001
block|,
comment|/* cond: cau.igu_dma_fsm_status */
literal|0x2307c010
block|,
literal|0x00010001
block|,
comment|/* cond: prs.INT_STS_0 */
literal|0x2307c011
block|,
literal|0x00010001
block|,
comment|/* cond: prs.INT_MASK_0 */
literal|0x2307c2da
block|,
literal|0x00000001
block|,
comment|/* info: prs.mini_cache_failed_response mode=all */
literal|0x2387c2d8
block|,
literal|0x00000002
block|,
comment|/* info: prs.mini_cache_entry width=2 access=WB mode=all */
literal|0x00014019
block|,
literal|0x00000001
block|,
comment|/* info: grc.trace_fifo_valid_data mode=all */
literal|0x2307c014
block|,
literal|0x00010001
block|,
comment|/* cond: prs.PRTY_STS */
literal|0x2307c015
block|,
literal|0x00010001
block|,
comment|/* cond: prs.PRTY_MASK */
literal|0x2307c081
block|,
literal|0x00010001
block|,
comment|/* cond: prs.PRTY_STS_H_0 */
literal|0x2307c082
block|,
literal|0x00010001
block|,
comment|/* cond: prs.PRTY_MASK_H_0 */
literal|0x2307c2d5
block|,
literal|0x00010001
block|,
comment|/* cond: prs.queue_pkt_avail_status */
literal|0x2307c2d6
block|,
literal|0x00010001
block|,
comment|/* cond: prs.storm_bkprs_status */
literal|0x2307c2d7
block|,
literal|0x00010001
block|,
comment|/* cond: prs.stop_parsing_status */
literal|0x2307c3c4
block|,
literal|0x00010001
block|,
comment|/* cond: prs.ccfc_search_current_credit */
literal|0x2307c3c5
block|,
literal|0x00010001
block|,
comment|/* cond: prs.tcfc_search_current_credit */
literal|0x2307c3c6
block|,
literal|0x00010001
block|,
comment|/* cond: prs.ccfc_load_current_credit */
literal|0x2307c3c7
block|,
literal|0x00010001
block|,
comment|/* cond: prs.tcfc_load_current_credit */
literal|0x2307c3c8
block|,
literal|0x00010001
block|,
comment|/* cond: prs.ccfc_search_req_ct */
literal|0x2307c3c9
block|,
literal|0x00010001
block|,
comment|/* cond: prs.tcfc_search_req_ct */
literal|0x2307c3ca
block|,
literal|0x00010001
block|,
comment|/* cond: prs.ccfc_load_req_ct */
literal|0x2307c3cb
block|,
literal|0x00010001
block|,
comment|/* cond: prs.tcfc_load_req_ct */
literal|0x2307c3cc
block|,
literal|0x00010001
block|,
comment|/* cond: prs.sop_req_ct */
literal|0x2307c3cd
block|,
literal|0x00010001
block|,
comment|/* cond: prs.eop_req_ct */
literal|0x3708c010
block|,
literal|0x00010001
block|,
comment|/* cond: prm.INT_STS */
literal|0x3708c011
block|,
literal|0x00010001
block|,
comment|/* cond: prm.INT_MASK */
literal|0x3708c080
block|,
literal|0x00010001
block|,
comment|/* cond: prm.PRTY_STS_H_0 */
literal|0x3708c081
block|,
literal|0x00010001
block|,
comment|/* cond: prm.PRTY_MASK_H_0 */
literal|0x3008e202
block|,
literal|0x00010001
block|,
comment|/* cond: rss.rss_init_done */
literal|0x3008e260
block|,
literal|0x00010001
block|,
comment|/* cond: rss.INT_STS */
literal|0x3008e261
block|,
literal|0x00010001
block|,
comment|/* cond: rss.INT_MASK */
literal|0x3008e280
block|,
literal|0x00010001
block|,
comment|/* cond: rss.PRTY_STS_H_0 */
literal|0x3008e281
block|,
literal|0x00010001
block|,
comment|/* cond: rss.PRTY_MASK_H_0 */
literal|0x3008e301
block|,
literal|0x00010001
block|,
comment|/* cond: rss.tmld_credit */
literal|0x14090000
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.rbc_done */
literal|0x14090001
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.cfg_done */
literal|0x14090060
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.INT_STS */
literal|0x14090061
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.INT_MASK */
literal|0x14090080
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.PRTY_STS_H_0 */
literal|0x14090081
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.PRTY_MASK_H_0 */
literal|0x14090115
block|,
literal|0x00010020
block|,
comment|/* cond: pswrq2.vq0_entry_cnt[0:31] */
literal|0x140901c5
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.BW_CREDIT */
literal|0x14090206
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.treq_fifo_fill_lvl */
literal|0x14090207
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.icpl_fifo_fill_lvl */
literal|0x1409024a
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.l2p_err_add_31_0 */
literal|0x1409024b
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.l2p_err_add_63_32 */
literal|0x1409024c
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.l2p_err_details */
literal|0x1409024d
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.l2p_err_details2 */
literal|0x14090271
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt */
literal|0x1409024f
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_num_cfg */
literal|0x14090271
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt */
literal|0x1409024f
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_num_cfg */
literal|0x14090272
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_0 */
literal|0x140902d1
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq0 */
literal|0x14090273
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_1 */
literal|0x140902d2
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq1 */
literal|0x14090274
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_2 */
literal|0x140902d3
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq2 */
literal|0x14090275
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_3 */
literal|0x140902d4
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq3 */
literal|0x14090276
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_4 */
literal|0x140902d5
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq4 */
literal|0x14090277
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_5 */
literal|0x140902d6
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq5 */
literal|0x14090278
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_6 */
literal|0x140902d7
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq6 */
literal|0x1409027b
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_9 */
literal|0x140902da
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq9 */
literal|0x1409027d
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_11 */
literal|0x140902dc
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq11 */
literal|0x1409027e
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_12 */
literal|0x140902dd
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq12 */
literal|0x14090281
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_15 */
literal|0x140902e0
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq15 */
literal|0x14090282
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_16 */
literal|0x140902e1
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq16 */
literal|0x14090283
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_17 */
literal|0x140902e2
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq17 */
literal|0x14090284
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_18 */
literal|0x140902e3
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq18 */
literal|0x14090285
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_19 */
literal|0x140902e4
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq19 */
literal|0x14090287
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_21 */
literal|0x140902e6
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq21 */
literal|0x14090288
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_22 */
literal|0x140902e7
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq22 */
literal|0x14090289
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_23 */
literal|0x140902e8
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq23 */
literal|0x1409028a
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_24 */
literal|0x140902e9
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq24 */
literal|0x1409028c
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_26 */
literal|0x140902eb
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq26 */
literal|0x1409028e
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_28 */
literal|0x140902ed
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq28 */
literal|0x1409028f
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_29 */
literal|0x140902ee
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq29 */
literal|0x14090290
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_30 */
literal|0x140902ef
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq30 */
literal|0x14090292
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt */
literal|0x14090250
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_num_cfg */
literal|0x14090292
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt */
literal|0x14090250
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_num_cfg */
literal|0x14090293
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_0 */
literal|0x14090251
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq0 */
literal|0x14090294
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_1 */
literal|0x14090252
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq1 */
literal|0x14090295
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_2 */
literal|0x14090253
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq2 */
literal|0x14090296
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_3 */
literal|0x14090254
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq3 */
literal|0x14090297
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_4 */
literal|0x14090255
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq4 */
literal|0x14090298
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_5 */
literal|0x14090256
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq5 */
literal|0x14090299
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_6 */
literal|0x14090257
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq6 */
literal|0x1409029c
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_9 */
literal|0x1409025a
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq9 */
literal|0x1409029e
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_11 */
literal|0x1409025c
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq11 */
literal|0x1409029f
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_12 */
literal|0x1409025d
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq12 */
literal|0x140902a2
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_15 */
literal|0x14090260
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq15 */
literal|0x140902a3
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_16 */
literal|0x14090261
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq16 */
literal|0x140902a4
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_17 */
literal|0x14090262
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq17 */
literal|0x140902a5
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_18 */
literal|0x14090263
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq18 */
literal|0x140902a6
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_19 */
literal|0x14090264
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq19 */
literal|0x140902a8
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_21 */
literal|0x14090266
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq21 */
literal|0x140902a9
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_22 */
literal|0x14090267
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq22 */
literal|0x140902aa
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_23 */
literal|0x14090268
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq23 */
literal|0x140902ab
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_24 */
literal|0x14090269
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq24 */
literal|0x140902ad
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_26 */
literal|0x1409026b
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq26 */
literal|0x140902af
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_28 */
literal|0x1409026d
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq28 */
literal|0x140902b0
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_29 */
literal|0x1409026e
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq29 */
literal|0x140902b1
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_30 */
literal|0x1409026f
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq30 */
literal|0x140902f2
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.l2p_close_gate_sts */
literal|0x140902f3
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.misc_close_gate_sts */
literal|0x140902f4
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.misc_stall_mem_sts */
literal|0x130a0060
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq.INT_STS */
literal|0x130a0061
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq.INT_MASK */
literal|0x110a6860
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr.INT_STS */
literal|0x110a6861
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr.INT_MASK */
literal|0x120a6c12
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.pglue_eop_err_details */
literal|0x120a6c14
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.prm_curr_fill_level */
literal|0x120a6c16
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.cdu_curr_fill_level */
literal|0x120a6c60
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.INT_STS */
literal|0x120a6c61
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.INT_MASK */
literal|0x120a6c80
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.PRTY_STS_H_0 */
literal|0x120a6c81
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.PRTY_MASK_H_0 */
literal|0x120a6c84
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.PRTY_STS_H_1 */
literal|0x120a6c85
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.PRTY_MASK_H_1 */
literal|0x120a6c88
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.PRTY_STS_H_2 */
literal|0x120a6c89
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.PRTY_MASK_H_2 */
literal|0x120a6c8c
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.PRTY_STS_H_3 */
literal|0x120a6c8d
block|,
literal|0x00010001
block|,
comment|/* cond: pswwr2.PRTY_MASK_H_3 */
literal|0x0f0a7029
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd.fifo_full_status */
literal|0x0f0a7060
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd.INT_STS */
literal|0x0f0a7061
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd.INT_MASK */
literal|0x100a7400
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.start_init */
literal|0x100a7401
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.init_done */
literal|0x100a741a
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.cpl_err_details */
literal|0x100a741b
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.cpl_err_details2 */
literal|0x100a741f
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.port_is_idle_0 */
literal|0x100a7420
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.port_is_idle_1 */
literal|0x100a7438
block|,
literal|0x0001000f
block|,
comment|/* cond: pswrd2.almost_full_0[0:14] */
literal|0x100a7460
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.INT_STS */
literal|0x100a7461
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.INT_MASK */
literal|0x100a7480
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.PRTY_STS_H_0 */
literal|0x100a7481
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.PRTY_MASK_H_0 */
literal|0x100a7484
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.PRTY_STS_H_1 */
literal|0x100a7485
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.PRTY_MASK_H_1 */
literal|0x100a7518
block|,
literal|0x00010001
block|,
comment|/* cond: pswrd2.disable_inputs */
literal|0x0e0a7810
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst2.header_fifo_status */
literal|0x0e0a7811
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst2.data_fifo_status */
literal|0x0e0a7860
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst2.INT_STS */
literal|0x0e0a7861
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst2.INT_MASK */
literal|0x0d0a8013
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.discard_internal_writes_status */
literal|0x0d0a8014
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.discard_doorbells_status */
literal|0x0d0a8016
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.arb_is_idle */
literal|0x0d0a801c
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.incorrect_access_valid */
literal|0x0d0a801a
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.incorrect_access_data mode=all */
literal|0x0d0a801b
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.incorrect_access_length mode=all */
literal|0x0d0a801d
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.incorrect_access_address mode=all */
literal|0x0d0a801e
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.per_violation_valid */
literal|0x0d0a801f
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.per_violation_data mode=all */
literal|0x0d0a8023
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.source_credits_avail */
literal|0x0d0a8025
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.source_credit_viol_valid */
literal|0x0d0a8024
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.source_credit_viol_data mode=all */
literal|0x0d0a8029
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.dest_credits_avail */
literal|0x0d0a802b
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.is_in_drain_mode */
literal|0x0d0a802e
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.timeout_valid */
literal|0x0d0a802d
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.timeout_data mode=all */
literal|0x0d0a802e
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.timeout_valid */
literal|0x0d0a802f
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.timeout_address mode=all */
literal|0x0d0a8058
block|,
literal|0x00010008
block|,
comment|/* cond: pswhst.clients_waiting_to_source_arb[0:7] */
literal|0x0d0a8060
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.INT_STS */
literal|0x0d0a8061
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.INT_MASK */
literal|0x0d0a8080
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.PRTY_STS_H_0 */
literal|0x0d0a8081
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.PRTY_MASK_H_0 */
literal|0x040aa060
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.INT_STS */
literal|0x040aa060
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.INT_STS */
literal|0x040aa080
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.PRTY_STS_H_0 */
literal|0x040aa081
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.PRTY_MASK_H_0 */
literal|0x040aa120
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.pgl_write_blocked */
literal|0x040aa121
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.pgl_read_blocked */
literal|0x040aa122
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.read_fifo_occupancy_level */
literal|0x040aa12b
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.rx_legacy_errors */
literal|0x040aa159
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.pgl_txw_cdts */
literal|0x040aa804
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.cfg_space_a_request */
literal|0x040aa806
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.cfg_space_b_request */
literal|0x040aa808
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_vf_31_0 */
literal|0x040aa809
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_vf_63_32 */
literal|0x040aa80a
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_vf_95_64 */
literal|0x040aa80b
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_vf_127_96 */
literal|0x040aa80c
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_vf_159_128 */
literal|0x040aa80d
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_vf_191_160 */
literal|0x040aa810
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_pf_31_0 */
literal|0x040aa81b
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.sr_iov_disabled_request */
literal|0x040aa83d
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_vf_31_0 */
literal|0x040aa83e
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_vf_63_32 */
literal|0x040aa83f
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_vf_95_64 */
literal|0x040aa840
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_vf_127_96 */
literal|0x040aa841
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_vf_159_128 */
literal|0x040aa842
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_vf_191_160 */
literal|0x040aa845
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_pf_31_0 */
literal|0x040aa84f
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.rx_err_details */
literal|0x040aa850
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.rx_tcpl_err_details */
literal|0x040aa851
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tx_err_wr_add_31_0 */
literal|0x040aa852
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tx_err_wr_add_63_32 */
literal|0x040aa853
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tx_err_wr_details */
literal|0x040aa854
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tx_err_wr_details2 */
literal|0x040aa855
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tx_err_rd_add_31_0 */
literal|0x040aa856
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tx_err_rd_add_63_32 */
literal|0x040aa857
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tx_err_rd_details */
literal|0x040aa858
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tx_err_rd_details2 */
literal|0x040aa8ec
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.vf_length_violation_details */
literal|0x040aa8ed
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.vf_length_violation_details2 */
literal|0x040aa8ee
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.vf_grc_space_violation_details */
literal|0x040aa951
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.master_zlr_err_add_31_0 */
literal|0x040aa952
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.master_zlr_err_add_63_32 */
literal|0x040aa953
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.master_zlr_err_details */
literal|0x040aa955
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.admin_window_violation_details */
literal|0x040aa956
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.out_of_range_function_in_pretend_details */
literal|0x040aa957
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.out_of_range_function_in_pretend_address */
literal|0x040aab80
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.write_fifo_occupancy_level */
literal|0x040aab84
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.illegal_address_add_31_0 */
literal|0x040aab85
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.illegal_address_add_63_32 */
literal|0x040aab86
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.illegal_address_details */
literal|0x040aab87
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.illegal_address_details2 */
literal|0x040aab8e
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tags_31_0 */
literal|0x040aab8f
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tags_63_32 */
literal|0x040aab90
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tags_95_64 */
literal|0x040aab91
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tags_127_96 */
literal|0x040aab9d
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.vf_ilt_err_add_31_0 */
literal|0x040aab9e
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.vf_ilt_err_add_63_32 */
literal|0x040aab9f
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.vf_ilt_err_details */
literal|0x040aaba0
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.vf_ilt_err_details2 */
literal|0x1f0b0060
block|,
literal|0x00010001
block|,
comment|/* cond: tm.INT_STS_0 */
literal|0x1f0b0060
block|,
literal|0x00010001
block|,
comment|/* cond: tm.INT_STS_0 */
literal|0x1f0b0060
block|,
literal|0x00010001
block|,
comment|/* cond: tm.INT_STS_0 */
literal|0x1f0b0064
block|,
literal|0x00010001
block|,
comment|/* cond: tm.INT_STS_1 */
literal|0x1f0b0080
block|,
literal|0x00010001
block|,
comment|/* cond: tm.PRTY_STS_H_0 */
literal|0x1f0b0081
block|,
literal|0x00010001
block|,
comment|/* cond: tm.PRTY_MASK_H_0 */
literal|0x1f0b01c4
block|,
literal|0x00010001
block|,
comment|/* cond: tm.pxp_read_data_fifo_status */
literal|0x1f0b01c6
block|,
literal|0x00010001
block|,
comment|/* cond: tm.pxp_read_ctrl_fifo_status */
literal|0x1f0b01c8
block|,
literal|0x00010001
block|,
comment|/* cond: tm.cfc_load_echo_fifo_status */
literal|0x1f0b01c9
block|,
literal|0x00010001
block|,
comment|/* cond: tm.client_out_fifo_status */
literal|0x1f0b01ca
block|,
literal|0x00010001
block|,
comment|/* cond: tm.client_in_pbf_fifo_status */
literal|0x1f0b01cb
block|,
literal|0x00010001
block|,
comment|/* cond: tm.client_in_xcm_fifo_status */
literal|0x1f0b01cc
block|,
literal|0x00010001
block|,
comment|/* cond: tm.client_in_tcm_fifo_status */
literal|0x1f0b01cd
block|,
literal|0x00010001
block|,
comment|/* cond: tm.client_in_ucm_fifo_status */
literal|0x1f0b01ce
block|,
literal|0x00010001
block|,
comment|/* cond: tm.expiration_cmd_fifo_status */
literal|0x1f0b01cf
block|,
literal|0x00010001
block|,
comment|/* cond: tm.ac_command_fifo_status */
literal|0x410b4001
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.ll_init_done */
literal|0x410b4002
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.ac_init_done */
literal|0x410b4003
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.cam_init_done */
literal|0x410b4004
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.tidram_init_done */
literal|0x410b4060
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.INT_STS_0 */
literal|0x410b4061
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.INT_MASK_0 */
literal|0x410b4153
block|,
literal|0x00000001
block|,
comment|/* info: tcfc.error_vector mode=all */
literal|0x410b4156
block|,
literal|0x00000001
block|,
comment|/* info: tcfc.error_data1 mode=all */
literal|0x410b4157
block|,
literal|0x00000001
block|,
comment|/* info: tcfc.error_data2 mode=all */
literal|0x410b4158
block|,
literal|0x00000001
block|,
comment|/* info: tcfc.error_data3 mode=all */
literal|0x410b4159
block|,
literal|0x00000001
block|,
comment|/* info: tcfc.error_data4 mode=all */
literal|0x410b4080
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.PRTY_STS_H_0 */
literal|0x410b4081
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.PRTY_MASK_H_0 */
literal|0x410b4184
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.lstate_arriving */
literal|0x410b4187
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.lstate_leaving */
literal|0x410b41e2
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.cduld_credit */
literal|0x400b8001
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.ll_init_done */
literal|0x400b8002
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.ac_init_done */
literal|0x400b8003
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.cam_init_done */
literal|0x400b8004
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.tidram_init_done */
literal|0x400b8060
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.INT_STS_0 */
literal|0x400b8061
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.INT_MASK_0 */
literal|0x400b8153
block|,
literal|0x00000001
block|,
comment|/* info: ccfc.error_vector mode=all */
literal|0x400b8156
block|,
literal|0x00000001
block|,
comment|/* info: ccfc.error_data1 mode=all */
literal|0x400b8157
block|,
literal|0x00000001
block|,
comment|/* info: ccfc.error_data2 mode=all */
literal|0x400b8158
block|,
literal|0x00000001
block|,
comment|/* info: ccfc.error_data3 mode=all */
literal|0x400b8159
block|,
literal|0x00000001
block|,
comment|/* info: ccfc.error_data4 mode=all */
literal|0x400b8080
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.PRTY_STS_H_0 */
literal|0x400b8081
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.PRTY_MASK_H_0 */
literal|0x400b8179
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.PRTY_STS */
literal|0x400b817a
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.PRTY_MASK */
literal|0x400b8184
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.lstate_arriving */
literal|0x400b8187
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.lstate_leaving */
literal|0x400b81e2
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.cduld_credit */
literal|0x400b81e3
block|,
literal|0x00010001
block|,
comment|/* cond: ccfc.cduwb_credit */
literal|0x1e0bc060
block|,
literal|0x00010001
block|,
comment|/* cond: qm.INT_STS */
literal|0x1e0bc061
block|,
literal|0x00010001
block|,
comment|/* cond: qm.INT_MASK */
literal|0x1e0bc064
block|,
literal|0x00010001
block|,
comment|/* cond: qm.PRTY_STS */
literal|0x1e0bc065
block|,
literal|0x00010001
block|,
comment|/* cond: qm.PRTY_MASK */
literal|0x1e0bc080
block|,
literal|0x00010001
block|,
comment|/* cond: qm.PRTY_STS_H_0 */
literal|0x1e0bc081
block|,
literal|0x00010001
block|,
comment|/* cond: qm.PRTY_MASK_H_0 */
literal|0x1e0bc084
block|,
literal|0x00010001
block|,
comment|/* cond: qm.PRTY_STS_H_1 */
literal|0x1e0bc085
block|,
literal|0x00010001
block|,
comment|/* cond: qm.PRTY_MASK_H_1 */
literal|0x1e0bc088
block|,
literal|0x00010001
block|,
comment|/* cond: qm.PRTY_STS_H_2 */
literal|0x1e0bc089
block|,
literal|0x00010001
block|,
comment|/* cond: qm.PRTY_MASK_H_2 */
literal|0x1e0bc106
block|,
literal|0x00010006
block|,
comment|/* cond: qm.wrc_fifolvl_0[0:5] */
literal|0x1e0bc202
block|,
literal|0x00010001
block|,
comment|/* cond: qm.OutLdReqCrdConnTx */
literal|0x1e0bc200
block|,
literal|0x00010001
block|,
comment|/* cond: qm.OutLdReqSizeConnTx */
literal|0x1e0bc203
block|,
literal|0x00010001
block|,
comment|/* cond: qm.OutLdReqCrdConnOther */
literal|0x1e0bc201
block|,
literal|0x00010001
block|,
comment|/* cond: qm.OutLdReqSizeConnOther */
literal|0x1e0bc54e
block|,
literal|0x00010001
block|,
comment|/* cond: qm.OvfQNumTx */
literal|0x1e0bc54f
block|,
literal|0x00010001
block|,
comment|/* cond: qm.OvfErrorTx */
literal|0x1e0bc54e
block|,
literal|0x00000001
block|,
comment|/* info: qm.OvfQNumTx mode=all */
literal|0x1e0bc550
block|,
literal|0x00010001
block|,
comment|/* cond: qm.OvfQNumOther */
literal|0x1e0bc551
block|,
literal|0x00010001
block|,
comment|/* cond: qm.OvfErrorOther */
literal|0x1e0bc550
block|,
literal|0x00000001
block|,
comment|/* info: qm.OvfQNumOther mode=all */
literal|0x1e0bc68e
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_0 */
literal|0x1e0bc684
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_0 */
literal|0x1e0bc68f
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_1 */
literal|0x1e0bc685
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_1 */
literal|0x1e0bc690
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_2 */
literal|0x1e0bc686
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_2 */
literal|0x1e0bc691
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_3 */
literal|0x1e0bc687
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_3 */
literal|0x1e0bc692
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_4 */
literal|0x1e0bc688
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_4 */
literal|0x1e0bc693
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_5 */
literal|0x1e0bc689
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_5 */
literal|0x1e0bc694
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_6 */
literal|0x1e0bc68a
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_6 */
literal|0x1e0bc695
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_7 */
literal|0x1e0bc68b
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_7 */
literal|0x1e0bc696
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_8 */
literal|0x1e0bc68c
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_8 */
literal|0x1e0bc697
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmCrd_9 */
literal|0x1e0bc68d
block|,
literal|0x00010001
block|,
comment|/* cond: qm.CmInitCrd_9 */
literal|0x3d0c0060
block|,
literal|0x00010001
block|,
comment|/* cond: rdif.INT_STS */
literal|0x3d0c0061
block|,
literal|0x00010001
block|,
comment|/* cond: rdif.INT_MASK */
literal|0x3e0c4060
block|,
literal|0x00010001
block|,
comment|/* cond: tdif.INT_STS */
literal|0x3e0c4061
block|,
literal|0x00010001
block|,
comment|/* cond: tdif.INT_MASK */
literal|0x3e0c4080
block|,
literal|0x00010001
block|,
comment|/* cond: tdif.PRTY_STS_H_0 */
literal|0x3e0c4081
block|,
literal|0x00010001
block|,
comment|/* cond: tdif.PRTY_MASK_H_0 */
literal|0x210d0030
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_STS_0 */
literal|0x210d0031
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_MASK_0 */
literal|0x218d0600
block|,
literal|0x00000014
block|,
comment|/* info: brb.stopped_rd_req[0:4] width=3 access=WB mode=all */
literal|0x218d0640
block|,
literal|0x00000014
block|,
comment|/* info: brb.stopped_rls_req[0:4] width=3 access=WB mode=all */
literal|0x210d0036
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_STS_1 */
literal|0x210d0037
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_MASK_1 */
literal|0x210d003c
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_STS_2 */
literal|0x210d003d
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_MASK_2 */
literal|0x210d0042
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_STS_3 */
literal|0x210d0043
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_MASK_3 */
literal|0x210d0048
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_STS_4 */
literal|0x210d0049
block|,
literal|0x00010001
block|,
comment|/* cond: brb.INT_MASK_4 */
literal|0x218d0600
block|,
literal|0x00000014
block|,
comment|/* info: brb.stopped_rd_req[0:4] width=3 access=WB mode=all */
literal|0x218d0640
block|,
literal|0x00000014
block|,
comment|/* info: brb.stopped_rls_req[0:4] width=3 access=WB mode=all */
literal|0x210d0100
block|,
literal|0x00010001
block|,
comment|/* cond: brb.PRTY_STS_H_0 */
literal|0x210d0101
block|,
literal|0x00010001
block|,
comment|/* cond: brb.PRTY_MASK_H_0 */
literal|0x210d0104
block|,
literal|0x00010001
block|,
comment|/* cond: brb.PRTY_STS_H_1 */
literal|0x210d0105
block|,
literal|0x00010001
block|,
comment|/* cond: brb.PRTY_MASK_H_1 */
literal|0x210d03ec
block|,
literal|0x00010001
block|,
comment|/* cond: brb.wc_bandwidth_if_full */
literal|0x210d03ed
block|,
literal|0x00010001
block|,
comment|/* cond: brb.rc_pkt_if_full */
literal|0x210d03ee
block|,
literal|0x00010005
block|,
comment|/* cond: brb.rc_pkt_empty_0[0:4] */
literal|0x210d041b
block|,
literal|0x00010001
block|,
comment|/* cond: brb.rc_sop_empty */
literal|0x210d0421
block|,
literal|0x00010001
block|,
comment|/* cond: brb.ll_arb_empty */
literal|0x210d0468
block|,
literal|0x00010001
block|,
comment|/* cond: brb.stop_packet_counter */
literal|0x210d0469
block|,
literal|0x00010001
block|,
comment|/* cond: brb.stop_byte_counter */
literal|0x210d046a
block|,
literal|0x00010001
block|,
comment|/* cond: brb.rc_pkt_state */
literal|0x210d0474
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_0 */
literal|0x210d0475
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_1 */
literal|0x210d0476
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_2 */
literal|0x210d0477
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_3 */
literal|0x210d0478
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_4 */
literal|0x210d0479
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_5 */
literal|0x210d047a
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_6 */
literal|0x210d047b
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_7 */
literal|0x210d047c
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac0_tc_occupancy_8 */
literal|0x210d0484
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_0 */
literal|0x210d0485
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_1 */
literal|0x210d0486
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_2 */
literal|0x210d0487
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_3 */
literal|0x210d0488
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_4 */
literal|0x210d0489
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_5 */
literal|0x210d048a
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_6 */
literal|0x210d048b
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_7 */
literal|0x210d048c
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac1_tc_occupancy_8 */
literal|0x34130017
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.pending_msg_to_ext_ev_1_ctr */
literal|0x34130018
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.pending_msg_to_ext_ev_2_ctr */
literal|0x34130019
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.pending_msg_to_ext_ev_3_ctr */
literal|0x3413001a
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.pending_msg_to_ext_ev_4_ctr */
literal|0x3413001b
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.pending_msg_to_ext_ev_5_ctr */
literal|0x3413001c
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.foc_remain_credits */
literal|0x34130003
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.foci_foc_credits */
literal|0x3413001f
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.pci_pending_msg_ctr */
literal|0x34130039
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.dbg_pending_ccfc_req */
literal|0x3413003a
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.dbg_pending_tcfc_req */
literal|0x34130080
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.PRTY_STS_H_0 */
literal|0x34130081
block|,
literal|0x00010001
block|,
comment|/* cond: xyld.PRTY_MASK_H_0 */
literal|0x31134016
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.pending_msg_to_ext_ev_1_ctr */
literal|0x31134017
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.pending_msg_to_ext_ev_2_ctr */
literal|0x31134018
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.pending_msg_to_ext_ev_3_ctr */
literal|0x31134019
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.pending_msg_to_ext_ev_4_ctr */
literal|0x3113401a
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.pending_msg_to_ext_ev_5_ctr */
literal|0x3113401b
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.foc_remain_credits */
literal|0x31134003
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.foci_foc_credits */
literal|0x31134031
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.dbg_pending_ccfc_req */
literal|0x31134032
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.dbg_pending_tcfc_req */
literal|0x31134080
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.PRTY_STS_H_0 */
literal|0x31134081
block|,
literal|0x00010001
block|,
comment|/* cond: tmld.PRTY_MASK_H_0 */
literal|0x3213801c
block|,
literal|0x00010001
block|,
comment|/* cond: muld.pending_msg_to_ext_ev_1_ctr */
literal|0x3213801d
block|,
literal|0x00010001
block|,
comment|/* cond: muld.pending_msg_to_ext_ev_2_ctr */
literal|0x3213801e
block|,
literal|0x00010001
block|,
comment|/* cond: muld.pending_msg_to_ext_ev_3_ctr */
literal|0x3213801f
block|,
literal|0x00010001
block|,
comment|/* cond: muld.pending_msg_to_ext_ev_4_ctr */
literal|0x32138020
block|,
literal|0x00010001
block|,
comment|/* cond: muld.pending_msg_to_ext_ev_5_ctr */
literal|0x32138021
block|,
literal|0x00010001
block|,
comment|/* cond: muld.foc_remain_credits */
literal|0x32138009
block|,
literal|0x00010001
block|,
comment|/* cond: muld.foci_foc_credits */
literal|0x32138022
block|,
literal|0x00010001
block|,
comment|/* cond: muld.bd_pending_msg_ctr */
literal|0x32138023
block|,
literal|0x00010001
block|,
comment|/* cond: muld.sge_pending_msg_ctr */
literal|0x32138026
block|,
literal|0x00010001
block|,
comment|/* cond: muld.pci_pending_msg_ctr */
literal|0x3213803a
block|,
literal|0x00010001
block|,
comment|/* cond: muld.dbg_pending_ccfc_req */
literal|0x3213803b
block|,
literal|0x00010001
block|,
comment|/* cond: muld.dbg_pending_tcfc_req */
literal|0x32138080
block|,
literal|0x00010001
block|,
comment|/* cond: muld.PRTY_STS_H_0 */
literal|0x32138081
block|,
literal|0x00010001
block|,
comment|/* cond: muld.PRTY_MASK_H_0 */
literal|0x4b140010
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_0 */
literal|0x4b140011
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_0 */
literal|0x4b140014
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_1 */
literal|0x4b140015
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_1 */
literal|0x4b140018
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_2 */
literal|0x4b140019
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_2 */
literal|0x4b14001c
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_3 */
literal|0x4b14001d
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_3 */
literal|0x4b1406e8
block|,
literal|0x00000001
block|,
comment|/* info: nig.flowctrl_mode mode=all */
literal|0x4b140713
block|,
literal|0x00000001
block|,
comment|/* info: nig.rx_flowctrl_status mode=all */
literal|0x4b140020
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_4 */
literal|0x4b140021
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_4 */
literal|0x4b140024
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_5 */
literal|0x4b140025
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_5 */
literal|0x4b1406e8
block|,
literal|0x00000001
block|,
comment|/* info: nig.flowctrl_mode mode=all */
literal|0x4b140713
block|,
literal|0x00000001
block|,
comment|/* info: nig.rx_flowctrl_status mode=all */
literal|0x4b140080
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_STS_H_0 */
literal|0x4b140081
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_MASK_H_0 */
literal|0x4b140084
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_STS_H_1 */
literal|0x4b140085
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_MASK_H_1 */
literal|0x4b140088
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_STS_H_2 */
literal|0x4b140089
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_MASK_H_2 */
literal|0x4b14008c
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_STS_H_3 */
literal|0x4b14008d
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_MASK_H_3 */
literal|0x4b140301
block|,
literal|0x00010001
block|,
comment|/* cond: nig.lb_sopq_empty */
literal|0x4b140303
block|,
literal|0x00010001
block|,
comment|/* cond: nig.tx_sopq_empty */
literal|0x4b1404c6
block|,
literal|0x00010001
block|,
comment|/* cond: nig.rx_llh_rfifo_empty */
literal|0x4b1405db
block|,
literal|0x00010001
block|,
comment|/* cond: nig.lb_btb_fifo_empty */
literal|0x4b1405e6
block|,
literal|0x00010001
block|,
comment|/* cond: nig.lb_llh_rfifo_empty */
literal|0x4b140655
block|,
literal|0x00010001
block|,
comment|/* cond: nig.rx_ptp_ts_msb_err */
literal|0x4b140640
block|,
literal|0x00010001
block|,
comment|/* cond: nig.rx_ptp_en */
literal|0x4b1407ff
block|,
literal|0x00010001
block|,
comment|/* cond: nig.tx_btb_fifo_empty */
literal|0x4b140838
block|,
literal|0x00010001
block|,
comment|/* cond: nig.debug_fifo_empty */
literal|0x1715801c
block|,
literal|0x00010001
block|,
comment|/* cond: ptu.pxp_err_ctr */
literal|0x1715801d
block|,
literal|0x00010001
block|,
comment|/* cond: ptu.inv_err_ctr */
literal|0x17158032
block|,
literal|0x00010001
block|,
comment|/* cond: ptu.pbf_fill_level */
literal|0x17158033
block|,
literal|0x00010001
block|,
comment|/* cond: ptu.prm_fill_level */
literal|0x17158060
block|,
literal|0x00010001
block|,
comment|/* cond: ptu.INT_STS */
literal|0x17158061
block|,
literal|0x00010001
block|,
comment|/* cond: ptu.INT_MASK */
literal|0x17158080
block|,
literal|0x00010001
block|,
comment|/* cond: ptu.PRTY_STS_H_0 */
literal|0x17158081
block|,
literal|0x00010001
block|,
comment|/* cond: ptu.PRTY_MASK_H_0 */
literal|0x3f160070
block|,
literal|0x00010001
block|,
comment|/* cond: cdu.INT_STS */
literal|0x3f160073
block|,
literal|0x00010001
block|,
comment|/* cond: cdu.INT_MASK */
literal|0x3f160200
block|,
literal|0x00000001
block|,
comment|/* info: cdu.ccfc_cvld_error_data mode=all */
literal|0x3f160201
block|,
literal|0x00000001
block|,
comment|/* info: cdu.tcfc_cvld_error_data mode=all */
literal|0x3f160202
block|,
literal|0x00000001
block|,
comment|/* info: cdu.ccfc_ld_l1_num_error_data mode=all */
literal|0x3f160203
block|,
literal|0x00000001
block|,
comment|/* info: cdu.tcfc_ld_l1_num_error_data mode=all */
literal|0x3f160204
block|,
literal|0x00000001
block|,
comment|/* info: cdu.ccfc_wb_l1_num_error_data mode=all */
literal|0x3f160205
block|,
literal|0x00000001
block|,
comment|/* info: cdu.tcfc_wb_l1_num_error_data mode=all */
literal|0x3f160080
block|,
literal|0x00010001
block|,
comment|/* cond: cdu.PRTY_STS_H_0 */
literal|0x3f160081
block|,
literal|0x00010001
block|,
comment|/* cond: cdu.PRTY_MASK_H_0 */
literal|0x3c36019a
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.num_pkts_received_with_error */
literal|0x3c36019b
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.num_pkts_sent_with_error_to_btb */
literal|0x3c36019c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.num_pkts_sent_with_drop_to_btb */
literal|0x3c3601ac
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq0 */
literal|0x3c3601ae
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq0 */
literal|0x3c3601b1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq0 */
literal|0x3c3601bc
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq1 */
literal|0x3c3601be
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq1 */
literal|0x3c3601c1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq1 */
literal|0x3c3601cc
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq2 */
literal|0x3c3601ce
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq2 */
literal|0x3c3601d1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq2 */
literal|0x3c3601dc
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq3 */
literal|0x3c3601de
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq3 */
literal|0x3c3601e1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq3 */
literal|0x3c3601ec
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq4 */
literal|0x3c3601ee
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq4 */
literal|0x3c3601f1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq4 */
literal|0x3c3601fc
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq5 */
literal|0x3c3601fe
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq5 */
literal|0x3c360201
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq5 */
literal|0x3c36020c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq6 */
literal|0x3c36020e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq6 */
literal|0x3c360211
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq6 */
literal|0x3c36021c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq7 */
literal|0x3c36021e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq7 */
literal|0x3c360221
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq7 */
literal|0x3c36022c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq8 */
literal|0x3c36022e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq8 */
literal|0x3c360231
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq8 */
literal|0x3c36023c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq9 */
literal|0x3c36023e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq9 */
literal|0x3c360241
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq9 */
literal|0x3c36024c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq10 */
literal|0x3c36024e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq10 */
literal|0x3c360251
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq10 */
literal|0x3c36025c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq11 */
literal|0x3c36025e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq11 */
literal|0x3c360261
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq11 */
literal|0x3c36026c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq12 */
literal|0x3c36026e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq12 */
literal|0x3c360271
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq12 */
literal|0x3c36027c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq13 */
literal|0x3c36027e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq13 */
literal|0x3c360281
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq13 */
literal|0x3c36028c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq14 */
literal|0x3c36028e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq14 */
literal|0x3c360291
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq14 */
literal|0x3c36029c
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq15 */
literal|0x3c36029e
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq15 */
literal|0x3c3602a1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq15 */
literal|0x3c3602ac
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq16 */
literal|0x3c3602ae
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq16 */
literal|0x3c3602b1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq16 */
literal|0x3c3602bc
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq17 */
literal|0x3c3602be
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq17 */
literal|0x3c3602c1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq17 */
literal|0x3c3602cc
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq18 */
literal|0x3c3602ce
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq18 */
literal|0x3c3602d1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq18 */
literal|0x3c3602dc
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_cmd_cnt_voq19 */
literal|0x3c3602de
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.ycmd_qs_occupancy_voq19 */
literal|0x3c3602e1
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.btb_allocated_blocks_voq19 */
literal|0x3b36c036
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_1 */
literal|0x3b36c037
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_1 */
literal|0x3b36c03c
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_2 */
literal|0x3b36c03d
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_2 */
literal|0x3b36c042
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_3 */
literal|0x3b36c043
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_3 */
literal|0x3b36c100
block|,
literal|0x00010001
block|,
comment|/* cond: btb.PRTY_STS_H_0 */
literal|0x3b36c101
block|,
literal|0x00010001
block|,
comment|/* cond: btb.PRTY_MASK_H_0 */
literal|0x3b36c244
block|,
literal|0x00010001
block|,
comment|/* cond: btb.wc_dup_empty */
literal|0x3b36c246
block|,
literal|0x00010001
block|,
comment|/* cond: btb.wc_dup_status */
literal|0x3b36c247
block|,
literal|0x00010001
block|,
comment|/* cond: btb.wc_empty_0 */
literal|0x3b36c267
block|,
literal|0x00010001
block|,
comment|/* cond: btb.wc_bandwidth_if_full */
literal|0x3b36c268
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_if_full */
literal|0x3b36c269
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_empty_0 */
literal|0x3b36c26a
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_empty_1 */
literal|0x3b36c26b
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_empty_2 */
literal|0x3b36c26c
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_empty_3 */
literal|0x3b36c296
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_sop_empty */
literal|0x3b36c299
block|,
literal|0x00010001
block|,
comment|/* cond: btb.ll_arb_empty */
literal|0x3b36c29c
block|,
literal|0x00010001
block|,
comment|/* cond: btb.block_occupancy */
literal|0x3b36c2ae
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_state */
literal|0x3bb6c480
block|,
literal|0x00030001
block|,
comment|/* cond: btb.wc_status_0 width=3 access=WB */
literal|0x273e0010
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.INT_STS */
literal|0x273e0011
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.INT_MASK */
literal|0x273e0109
block|,
literal|0x00000001
block|,
comment|/* info: xsdm.inp_queue_err_vect mode=all */
literal|0x273e0080
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.PRTY_STS_H_0 */
literal|0x273e0081
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.PRTY_MASK_H_0 */
literal|0x273e0303
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.qm_full */
literal|0x273e030c
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.rsp_brb_if_full */
literal|0x273e030d
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.rsp_pxp_if_full */
literal|0x273e0316
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_pxp_if_full */
literal|0x273e0317
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_int_ram_if_full */
literal|0x273e0318
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_pas_buf_if_full */
literal|0x273e0340
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.int_cmpl_pend_empty */
literal|0x273e0341
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.int_cprm_pend_empty */
literal|0x273e0342
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.queue_empty */
literal|0x273e0343
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.delay_fifo_empty */
literal|0x273e0346
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.rsp_pxp_rdata_empty */
literal|0x273e0347
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.rsp_brb_rdata_empty */
literal|0x273e0348
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.rsp_int_ram_rdata_empty */
literal|0x273e0349
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.rsp_brb_pend_empty */
literal|0x273e034a
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.rsp_int_ram_pend_empty */
literal|0x273e034b
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_pxp_immed_empty */
literal|0x273e034c
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_pxp_dst_pend_empty */
literal|0x273e034d
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_pxp_src_pend_empty */
literal|0x273e034e
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_brb_src_pend_empty */
literal|0x273e034f
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_brb_src_addr_empty */
literal|0x273e0350
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_pxp_link_empty */
literal|0x273e0351
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_int_ram_wait_empty */
literal|0x273e0352
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.dst_pas_buf_wait_empty */
literal|0x273e0353
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.sh_delay_empty */
literal|0x273e0354
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.cm_delay_empty */
literal|0x273e0355
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.cmsg_que_empty */
literal|0x273e0356
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.ccfc_load_pend_empty */
literal|0x273e0357
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.tcfc_load_pend_empty */
literal|0x273e0358
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.async_host_empty */
literal|0x273e0359
block|,
literal|0x00010001
block|,
comment|/* cond: xsdm.prm_fifo_empty */
literal|0x283e4010
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.INT_STS */
literal|0x283e4011
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.INT_MASK */
literal|0x283e4109
block|,
literal|0x00000001
block|,
comment|/* info: ysdm.inp_queue_err_vect mode=all */
literal|0x283e4080
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.PRTY_STS_H_0 */
literal|0x283e4081
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.PRTY_MASK_H_0 */
literal|0x283e4303
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.qm_full */
literal|0x283e430c
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.rsp_brb_if_full */
literal|0x283e430d
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.rsp_pxp_if_full */
literal|0x283e4316
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_pxp_if_full */
literal|0x283e4317
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_int_ram_if_full */
literal|0x283e4318
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_pas_buf_if_full */
literal|0x283e4340
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.int_cmpl_pend_empty */
literal|0x283e4341
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.int_cprm_pend_empty */
literal|0x283e4342
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.queue_empty */
literal|0x283e4343
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.delay_fifo_empty */
literal|0x283e4346
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.rsp_pxp_rdata_empty */
literal|0x283e4347
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.rsp_brb_rdata_empty */
literal|0x283e4348
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.rsp_int_ram_rdata_empty */
literal|0x283e4349
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.rsp_brb_pend_empty */
literal|0x283e434a
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.rsp_int_ram_pend_empty */
literal|0x283e434b
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_pxp_immed_empty */
literal|0x283e434c
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_pxp_dst_pend_empty */
literal|0x283e434d
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_pxp_src_pend_empty */
literal|0x283e434e
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_brb_src_pend_empty */
literal|0x283e434f
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_brb_src_addr_empty */
literal|0x283e4350
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_pxp_link_empty */
literal|0x283e4351
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_int_ram_wait_empty */
literal|0x283e4352
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.dst_pas_buf_wait_empty */
literal|0x283e4353
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.sh_delay_empty */
literal|0x283e4354
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.cm_delay_empty */
literal|0x283e4355
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.cmsg_que_empty */
literal|0x283e4356
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.ccfc_load_pend_empty */
literal|0x283e4357
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.tcfc_load_pend_empty */
literal|0x283e4358
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.async_host_empty */
literal|0x283e4359
block|,
literal|0x00010001
block|,
comment|/* cond: ysdm.prm_fifo_empty */
literal|0x293e8010
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.INT_STS */
literal|0x293e8011
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.INT_MASK */
literal|0x293e8109
block|,
literal|0x00000001
block|,
comment|/* info: psdm.inp_queue_err_vect mode=all */
literal|0x293e8080
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.PRTY_STS_H_0 */
literal|0x293e8081
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.PRTY_MASK_H_0 */
literal|0x293e8303
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.qm_full */
literal|0x293e830c
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.rsp_brb_if_full */
literal|0x293e830d
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.rsp_pxp_if_full */
literal|0x293e8316
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_pxp_if_full */
literal|0x293e8317
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_int_ram_if_full */
literal|0x293e8318
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_pas_buf_if_full */
literal|0x293e8340
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.int_cmpl_pend_empty */
literal|0x293e8341
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.int_cprm_pend_empty */
literal|0x293e8342
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.queue_empty */
literal|0x293e8343
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.delay_fifo_empty */
literal|0x293e8346
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.rsp_pxp_rdata_empty */
literal|0x293e8347
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.rsp_brb_rdata_empty */
literal|0x293e8348
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.rsp_int_ram_rdata_empty */
literal|0x293e8349
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.rsp_brb_pend_empty */
literal|0x293e834a
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.rsp_int_ram_pend_empty */
literal|0x293e834b
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_pxp_immed_empty */
literal|0x293e834c
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_pxp_dst_pend_empty */
literal|0x293e834d
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_pxp_src_pend_empty */
literal|0x293e834e
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_brb_src_pend_empty */
literal|0x293e834f
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_brb_src_addr_empty */
literal|0x293e8350
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_pxp_link_empty */
literal|0x293e8351
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_int_ram_wait_empty */
literal|0x293e8352
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.dst_pas_buf_wait_empty */
literal|0x293e8353
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.sh_delay_empty */
literal|0x293e8354
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.cm_delay_empty */
literal|0x293e8355
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.cmsg_que_empty */
literal|0x293e8356
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.ccfc_load_pend_empty */
literal|0x293e8357
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.tcfc_load_pend_empty */
literal|0x293e8358
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.async_host_empty */
literal|0x293e8359
block|,
literal|0x00010001
block|,
comment|/* cond: psdm.prm_fifo_empty */
literal|0x243ec010
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.INT_STS */
literal|0x243ec011
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.INT_MASK */
literal|0x243ec109
block|,
literal|0x00000001
block|,
comment|/* info: tsdm.inp_queue_err_vect mode=all */
literal|0x243ec080
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.PRTY_STS_H_0 */
literal|0x243ec081
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.PRTY_MASK_H_0 */
literal|0x243ec303
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.qm_full */
literal|0x243ec30c
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.rsp_brb_if_full */
literal|0x243ec30d
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.rsp_pxp_if_full */
literal|0x243ec316
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_pxp_if_full */
literal|0x243ec317
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_int_ram_if_full */
literal|0x243ec318
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_pas_buf_if_full */
literal|0x243ec340
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.int_cmpl_pend_empty */
literal|0x243ec341
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.int_cprm_pend_empty */
literal|0x243ec342
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.queue_empty */
literal|0x243ec343
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.delay_fifo_empty */
literal|0x243ec346
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.rsp_pxp_rdata_empty */
literal|0x243ec347
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.rsp_brb_rdata_empty */
literal|0x243ec348
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.rsp_int_ram_rdata_empty */
literal|0x243ec349
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.rsp_brb_pend_empty */
literal|0x243ec34a
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.rsp_int_ram_pend_empty */
literal|0x243ec34b
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_pxp_immed_empty */
literal|0x243ec34c
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_pxp_dst_pend_empty */
literal|0x243ec34d
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_pxp_src_pend_empty */
literal|0x243ec34e
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_brb_src_pend_empty */
literal|0x243ec34f
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_brb_src_addr_empty */
literal|0x243ec350
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_pxp_link_empty */
literal|0x243ec351
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_int_ram_wait_empty */
literal|0x243ec352
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.dst_pas_buf_wait_empty */
literal|0x243ec353
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.sh_delay_empty */
literal|0x243ec354
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.cm_delay_empty */
literal|0x243ec355
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.cmsg_que_empty */
literal|0x243ec356
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.ccfc_load_pend_empty */
literal|0x243ec357
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.tcfc_load_pend_empty */
literal|0x243ec358
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.async_host_empty */
literal|0x243ec359
block|,
literal|0x00010001
block|,
comment|/* cond: tsdm.prm_fifo_empty */
literal|0x253f0010
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.INT_STS */
literal|0x253f0011
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.INT_MASK */
literal|0x253f0109
block|,
literal|0x00000001
block|,
comment|/* info: msdm.inp_queue_err_vect mode=all */
literal|0x253f0080
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.PRTY_STS_H_0 */
literal|0x253f0081
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.PRTY_MASK_H_0 */
literal|0x253f0303
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.qm_full */
literal|0x253f030c
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.rsp_brb_if_full */
literal|0x253f030d
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.rsp_pxp_if_full */
literal|0x253f0316
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_pxp_if_full */
literal|0x253f0317
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_int_ram_if_full */
literal|0x253f0318
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_pas_buf_if_full */
literal|0x253f0340
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.int_cmpl_pend_empty */
literal|0x253f0341
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.int_cprm_pend_empty */
literal|0x253f0342
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.queue_empty */
literal|0x253f0343
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.delay_fifo_empty */
literal|0x253f0346
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.rsp_pxp_rdata_empty */
literal|0x253f0347
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.rsp_brb_rdata_empty */
literal|0x253f0348
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.rsp_int_ram_rdata_empty */
literal|0x253f0349
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.rsp_brb_pend_empty */
literal|0x253f034a
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.rsp_int_ram_pend_empty */
literal|0x253f034b
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_pxp_immed_empty */
literal|0x253f034c
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_pxp_dst_pend_empty */
literal|0x253f034d
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_pxp_src_pend_empty */
literal|0x253f034e
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_brb_src_pend_empty */
literal|0x253f034f
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_brb_src_addr_empty */
literal|0x253f0350
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_pxp_link_empty */
literal|0x253f0351
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_int_ram_wait_empty */
literal|0x253f0352
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.dst_pas_buf_wait_empty */
literal|0x253f0353
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.sh_delay_empty */
literal|0x253f0354
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.cm_delay_empty */
literal|0x253f0355
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.cmsg_que_empty */
literal|0x253f0356
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.ccfc_load_pend_empty */
literal|0x253f0357
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.tcfc_load_pend_empty */
literal|0x253f0358
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.async_host_empty */
literal|0x253f0359
block|,
literal|0x00010001
block|,
comment|/* cond: msdm.prm_fifo_empty */
literal|0x263f4010
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.INT_STS */
literal|0x263f4011
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.INT_MASK */
literal|0x263f4109
block|,
literal|0x00000001
block|,
comment|/* info: usdm.inp_queue_err_vect mode=all */
literal|0x263f4080
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.PRTY_STS_H_0 */
literal|0x263f4081
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.PRTY_MASK_H_0 */
literal|0x263f4303
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.qm_full */
literal|0x263f430c
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.rsp_brb_if_full */
literal|0x263f430d
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.rsp_pxp_if_full */
literal|0x263f4316
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_pxp_if_full */
literal|0x263f4317
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_int_ram_if_full */
literal|0x263f4318
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_pas_buf_if_full */
literal|0x263f4340
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.int_cmpl_pend_empty */
literal|0x263f4341
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.int_cprm_pend_empty */
literal|0x263f4342
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.queue_empty */
literal|0x263f4343
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.delay_fifo_empty */
literal|0x263f4346
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.rsp_pxp_rdata_empty */
literal|0x263f4347
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.rsp_brb_rdata_empty */
literal|0x263f4348
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.rsp_int_ram_rdata_empty */
literal|0x263f4349
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.rsp_brb_pend_empty */
literal|0x263f434a
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.rsp_int_ram_pend_empty */
literal|0x263f434b
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_pxp_immed_empty */
literal|0x263f434c
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_pxp_dst_pend_empty */
literal|0x263f434d
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_pxp_src_pend_empty */
literal|0x263f434e
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_brb_src_pend_empty */
literal|0x263f434f
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_brb_src_addr_empty */
literal|0x263f4350
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_pxp_link_empty */
literal|0x263f4351
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_int_ram_wait_empty */
literal|0x263f4352
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.dst_pas_buf_wait_empty */
literal|0x263f4353
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.sh_delay_empty */
literal|0x263f4354
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.cm_delay_empty */
literal|0x263f4355
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.cmsg_que_empty */
literal|0x263f4356
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.ccfc_load_pend_empty */
literal|0x263f4357
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.tcfc_load_pend_empty */
literal|0x263f4358
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.async_host_empty */
literal|0x263f4359
block|,
literal|0x00010001
block|,
comment|/* cond: usdm.prm_fifo_empty */
literal|0x1b400060
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.INT_STS_0 */
literal|0x1b400061
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.INT_MASK_0 */
literal|0x1b400064
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.INT_STS_1 */
literal|0x1b400065
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.INT_MASK_1 */
literal|0x1b400068
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.INT_STS_2 */
literal|0x1b400069
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.INT_MASK_2 */
literal|0x1b4002d4
block|,
literal|0x00000001
block|,
comment|/* info: xcm.qm_act_st_cnt_err_details mode=all */
literal|0x1b400080
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.PRTY_STS_H_0 */
literal|0x1b400081
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.PRTY_MASK_H_0 */
literal|0x1b400084
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.PRTY_STS_H_1 */
literal|0x1b400085
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.PRTY_MASK_H_1 */
literal|0x1b4001a2
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.fi_desc_input_violate */
literal|0x1b4001a3
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.ia_agg_con_part_fill_lvl */
literal|0x1b4001a4
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.ia_sm_con_part_fill_lvl */
literal|0x1b4001a5
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.ia_trans_part_fill_lvl */
literal|0x1b4001c4
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.xx_free_cnt */
literal|0x1b4001c5
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.xx_lcid_cam_fill_lvl */
literal|0x1b4001cf
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.xx_lock_cnt */
literal|0x1b4001d6
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.xx_cbyp_tbl_fill_lvl */
literal|0x1b40020b
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.agg_con_fic_buf_fill_lvl */
literal|0x1b40020c
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.sm_con_fic_buf_fill_lvl */
literal|0x1b400283
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.in_prcs_tbl_fill_lvl */
literal|0x1b4002a1
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.ccfc_init_crd */
literal|0x1b4002a2
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.qm_init_crd0 */
literal|0x1b4002a3
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.qm_init_crd1 */
literal|0x1b4002a4
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.tm_init_crd */
literal|0x1b4002a5
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.fic_init_crd */
literal|0x1b4002ab
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.xsdm_length_mis */
literal|0x1b4002ac
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.ysdm_length_mis */
literal|0x1b4002ae
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.dorq_length_mis */
literal|0x1b4002af
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.pbf_length_mis */
literal|0x1b4002c0
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_qm_p_fill_lvl */
literal|0x1b4002c1
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_qm_s_fill_lvl */
literal|0x1b4002c2
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_tm_fill_lvl */
literal|0x1b4002c3
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_storm_fill_lvl */
literal|0x1b4002c5
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_xsdm_fill_lvl */
literal|0x1b4002c6
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_ysdm_fill_lvl */
literal|0x1b4002c8
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_msem_fill_lvl */
literal|0x1b4002c9
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_usem_fill_lvl */
literal|0x1b4002cb
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_dorq_fill_lvl */
literal|0x1b4002cc
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_pbf_fill_lvl */
literal|0x1c420060
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.INT_STS_0 */
literal|0x1c420061
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.INT_MASK_0 */
literal|0x1c420064
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.INT_STS_1 */
literal|0x1c420065
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.INT_MASK_1 */
literal|0x1c420080
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.PRTY_STS_H_0 */
literal|0x1c420081
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.PRTY_MASK_H_0 */
literal|0x1c420084
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.PRTY_STS_H_1 */
literal|0x1c420085
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.PRTY_MASK_H_1 */
literal|0x1c42019b
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.fi_desc_input_violate */
literal|0x1c42019c
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.se_desc_input_violate */
literal|0x1c42019e
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.ia_sm_con_part_fill_lvl */
literal|0x1c42019f
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.ia_agg_task_part_fill_lvl */
literal|0x1c4201a0
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.ia_sm_task_part_fill_lvl */
literal|0x1c4201a1
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.ia_trans_part_fill_lvl */
literal|0x1c4201c4
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.xx_free_cnt */
literal|0x1c4201c5
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.xx_lcid_cam_fill_lvl */
literal|0x1c4201cf
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.xx_lock_cnt */
literal|0x1c4201d6
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.xx_cbyp_tbl_fill_lvl */
literal|0x1c4201d9
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.xx_tbyp_tbl_fill_lvl */
literal|0x1c4201d9
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.xx_tbyp_tbl_fill_lvl */
literal|0x1c420216
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.sm_con_fic_buf_fill_lvl */
literal|0x1c42021e
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.agg_task_fic_buf_fill_lvl */
literal|0x1c42021f
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.sm_task_fic_buf_fill_lvl */
literal|0x1c420283
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.in_prcs_tbl_fill_lvl */
literal|0x1c4202a1
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.ccfc_init_crd */
literal|0x1c4202a2
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.tcfc_init_crd */
literal|0x1c4202a3
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.qm_init_crd0 */
literal|0x1c4202a6
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.fic_init_crd */
literal|0x1c4202ab
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.ysdm_length_mis */
literal|0x1c4202ac
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.pbf_length_mis */
literal|0x1c4202ad
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.xyld_length_mis */
literal|0x1c4202ba
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_qm_p_fill_lvl */
literal|0x1c4202bb
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_qm_s_fill_lvl */
literal|0x1c4202bc
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_storm_fill_lvl */
literal|0x1c4202be
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_ysdm_fill_lvl */
literal|0x1c4202bf
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_xyld_fill_lvl */
literal|0x1c4202c0
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_msem_fill_lvl */
literal|0x1c4202c1
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_usem_fill_lvl */
literal|0x1c4202c2
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_pbf_fill_lvl */
literal|0x1d440060
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.INT_STS_0 */
literal|0x1d440061
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.INT_MASK_0 */
literal|0x1d440064
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.INT_STS_1 */
literal|0x1d440065
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.INT_MASK_1 */
literal|0x1d440080
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.PRTY_STS_H_0 */
literal|0x1d440081
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.PRTY_MASK_H_0 */
literal|0x1d440191
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.fi_desc_input_violate */
literal|0x1d440192
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.ia_sm_con_part_fill_lvl */
literal|0x1d440193
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.ia_trans_part_fill_lvl */
literal|0x1d4401c4
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.xx_free_cnt */
literal|0x1d4401c5
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.xx_lcid_cam_fill_lvl */
literal|0x1d4401cf
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.xx_lock_cnt */
literal|0x1d44020a
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.sm_con_fic_buf_fill_lvl */
literal|0x1d440283
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.in_prcs_tbl_fill_lvl */
literal|0x1d4402a1
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.ccfc_init_crd */
literal|0x1d4402a2
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.fic_init_crd */
literal|0x1d4402b2
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.is_storm_fill_lvl */
literal|0x18460060
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.INT_STS_0 */
literal|0x18460061
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.INT_MASK_0 */
literal|0x18460064
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.INT_STS_1 */
literal|0x18460065
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.INT_MASK_1 */
literal|0x18460080
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.PRTY_STS_H_0 */
literal|0x18460081
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.PRTY_MASK_H_0 */
literal|0x18460084
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.PRTY_STS_H_1 */
literal|0x18460085
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.PRTY_MASK_H_1 */
literal|0x1846019b
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.fi_desc_input_violate */
literal|0x1846019c
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.se_desc_input_violate */
literal|0x1846019d
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.ia_agg_con_part_fill_lvl */
literal|0x1846019e
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.ia_sm_con_part_fill_lvl */
literal|0x1846019f
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.ia_agg_task_part_fill_lvl */
literal|0x184601a0
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.ia_sm_task_part_fill_lvl */
literal|0x184601a1
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.ia_trans_part_fill_lvl */
literal|0x184601c4
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.xx_free_cnt */
literal|0x184601c5
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.xx_lcid_cam_fill_lvl */
literal|0x184601cf
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.xx_lock_cnt */
literal|0x184601d6
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.xx_cbyp_tbl_fill_lvl */
literal|0x184601d9
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.xx_tbyp_tbl_fill_lvl */
literal|0x184601d9
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.xx_tbyp_tbl_fill_lvl */
literal|0x18460215
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.agg_con_fic_buf_fill_lvl */
literal|0x18460216
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.sm_con_fic_buf_fill_lvl */
literal|0x1846021e
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.agg_task_fic_buf_fill_lvl */
literal|0x1846021f
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.sm_task_fic_buf_fill_lvl */
literal|0x18460283
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.in_prcs_tbl_fill_lvl */
literal|0x184602a1
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.ccfc_init_crd */
literal|0x184602a2
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.tcfc_init_crd */
literal|0x184602a3
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.qm_init_crd0 */
literal|0x184602a4
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.tm_init_crd */
literal|0x184602a5
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.fic_init_crd */
literal|0x184602ab
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.dorq_length_mis */
literal|0x184602ac
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.pbf_length_mis */
literal|0x184602bb
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_qm_p_fill_lvl */
literal|0x184602bc
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_qm_s_fill_lvl */
literal|0x184602bd
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_tm_fill_lvl */
literal|0x184602be
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_storm_fill_lvl */
literal|0x184602c0
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_msem_fill_lvl */
literal|0x184602c2
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_dorq_fill_lvl */
literal|0x184602c3
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_pbf_fill_lvl */
literal|0x19480060
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.INT_STS_0 */
literal|0x19480061
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.INT_MASK_0 */
literal|0x19480064
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.INT_STS_1 */
literal|0x19480065
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.INT_MASK_1 */
literal|0x19480080
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.PRTY_STS_H_0 */
literal|0x19480081
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.PRTY_MASK_H_0 */
literal|0x19480084
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.PRTY_STS_H_1 */
literal|0x19480085
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.PRTY_MASK_H_1 */
literal|0x1948019d
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.fi_desc_input_violate */
literal|0x1948019e
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.se_desc_input_violate */
literal|0x1948019f
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.ia_agg_con_part_fill_lvl */
literal|0x194801a0
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.ia_sm_con_part_fill_lvl */
literal|0x194801a1
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.ia_agg_task_part_fill_lvl */
literal|0x194801a2
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.ia_sm_task_part_fill_lvl */
literal|0x194801a3
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.ia_trans_part_fill_lvl */
literal|0x194801c4
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.xx_free_cnt */
literal|0x194801c5
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.xx_lcid_cam_fill_lvl */
literal|0x194801cf
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.xx_lock_cnt */
literal|0x194801d6
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.xx_cbyp_tbl_fill_lvl */
literal|0x194801d9
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.xx_tbyp_tbl_fill_lvl */
literal|0x194801d9
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.xx_tbyp_tbl_fill_lvl */
literal|0x19480215
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.agg_con_fic_buf_fill_lvl */
literal|0x19480216
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.sm_con_fic_buf_fill_lvl */
literal|0x1948021e
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.agg_task_fic_buf_fill_lvl */
literal|0x1948021f
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.sm_task_fic_buf_fill_lvl */
literal|0x19480283
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.in_prcs_tbl_fill_lvl */
literal|0x194802a1
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.ccfc_init_crd */
literal|0x194802a2
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.tcfc_init_crd */
literal|0x194802a3
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.qm_init_crd0 */
literal|0x194802a6
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.fic_init_crd */
literal|0x194802ab
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.ysdm_length_mis */
literal|0x194802ac
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.usdm_length_mis */
literal|0x194802ad
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.pbf_length_mis */
literal|0x194802ae
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.tmld_length_mis */
literal|0x194802bc
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_qm_p_fill_lvl */
literal|0x194802bd
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_qm_s_fill_lvl */
literal|0x194802be
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_storm_fill_lvl */
literal|0x194802c0
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_ysdm_fill_lvl */
literal|0x194802c1
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_usdm_fill_lvl */
literal|0x194802c2
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_tmld_fill_lvl */
literal|0x194802c3
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_usem_fill_lvl */
literal|0x194802c5
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_pbf_fill_lvl */
literal|0x1a4a0060
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.INT_STS_0 */
literal|0x1a4a0061
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.INT_MASK_0 */
literal|0x1a4a0064
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.INT_STS_1 */
literal|0x1a4a0065
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.INT_MASK_1 */
literal|0x1a4a0080
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.PRTY_STS_H_0 */
literal|0x1a4a0081
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.PRTY_MASK_H_0 */
literal|0x1a4a0084
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.PRTY_STS_H_1 */
literal|0x1a4a0085
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.PRTY_MASK_H_1 */
literal|0x1a4a01a3
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.fi_desc_input_violate */
literal|0x1a4a01a4
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.se_desc_input_violate */
literal|0x1a4a01a5
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.ia_agg_con_part_fill_lvl */
literal|0x1a4a01a6
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.ia_sm_con_part_fill_lvl */
literal|0x1a4a01a7
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.ia_agg_task_part_fill_lvl */
literal|0x1a4a01a8
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.ia_sm_task_part_fill_lvl */
literal|0x1a4a01a9
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.ia_trans_part_fill_lvl */
literal|0x1a4a01c4
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.xx_free_cnt */
literal|0x1a4a01c5
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.xx_lcid_cam_fill_lvl */
literal|0x1a4a01cf
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.xx_lock_cnt */
literal|0x1a4a01d6
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.xx_cbyp_tbl_fill_lvl */
literal|0x1a4a01d9
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.xx_tbyp_tbl_fill_lvl */
literal|0x1a4a01d9
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.xx_tbyp_tbl_fill_lvl */
literal|0x1a4a0215
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.agg_con_fic_buf_fill_lvl */
literal|0x1a4a0216
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.sm_con_fic_buf_fill_lvl */
literal|0x1a4a021e
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.agg_task_fic_buf_fill_lvl */
literal|0x1a4a021f
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.sm_task_fic_buf_fill_lvl */
literal|0x1a4a0283
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.in_prcs_tbl_fill_lvl */
literal|0x1a4a02a1
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.ccfc_init_crd */
literal|0x1a4a02a2
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.tcfc_init_crd */
literal|0x1a4a02a3
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.qm_init_crd0 */
literal|0x1a4a02a4
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.tm_init_crd */
literal|0x1a4a02a5
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.fic_init_crd */
literal|0x1a4a02ab
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.ysdm_length_mis */
literal|0x1a4a02ac
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.usdm_length_mis */
literal|0x1a4a02ad
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.dorq_length_mis */
literal|0x1a4a02ae
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.pbf_length_mis */
literal|0x1a4a02af
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.rdif_length_mis */
literal|0x1a4a02b0
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.tdif_length_mis */
literal|0x1a4a02b1
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.muld_length_mis */
literal|0x1a4a02c3
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_qm_p_fill_lvl */
literal|0x1a4a02c4
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_qm_s_fill_lvl */
literal|0x1a4a02c5
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_tm_fill_lvl */
literal|0x1a4a02c6
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_storm_fill_lvl */
literal|0x1a4a02c8
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_ysdm_fill_lvl */
literal|0x1a4a02c9
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_usdm_fill_lvl */
literal|0x1a4a02ca
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_rdif_fill_lvl */
literal|0x1a4a02cb
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_tdif_fill_lvl */
literal|0x1a4a02cc
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_muld_fill_lvl */
literal|0x1a4a02ce
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_dorq_fill_lvl */
literal|0x1a4a02cf
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_pbf_fill_lvl */
literal|0x2d500010
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.INT_STS_0 */
literal|0x2d500011
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.INT_MASK_0 */
literal|0x2d500014
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.INT_STS_1 */
literal|0x2d500015
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.INT_MASK_1 */
literal|0x2d500032
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.PRTY_STS */
literal|0x2d500033
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.PRTY_MASK */
literal|0x2d500110
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.pf_err_vector */
literal|0x2d5001a0
block|,
literal|0x01010001
block|,
comment|/* cond: xsem.foc_credit[1] */
literal|0x2d5001a0
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.foc_credit */
literal|0x2d500441
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.ext_pas_empty */
literal|0x2d500448
block|,
literal|0x00010002
block|,
comment|/* cond: xsem.fic_empty[0:1] */
literal|0x2d500454
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.slow_ext_store_empty */
literal|0x2d500455
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.slow_ext_load_empty */
literal|0x2d500457
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.slow_ram_wr_empty */
literal|0x2d500458
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.sync_dbg_empty */
literal|0x2d500481
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.ext_store_if_full */
literal|0x2d500491
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.ram_if_full */
literal|0x2e540010
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.INT_STS_0 */
literal|0x2e540011
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.INT_MASK_0 */
literal|0x2e540014
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.INT_STS_1 */
literal|0x2e540015
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.INT_MASK_1 */
literal|0x2e540032
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.PRTY_STS */
literal|0x2e540033
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.PRTY_MASK */
literal|0x2e540110
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.pf_err_vector */
literal|0x2e5401a0
block|,
literal|0x02010001
block|,
comment|/* cond: ysem.foc_credit[2] */
literal|0x2e5401a0
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.foc_credit */
literal|0x2e5401a0
block|,
literal|0x01010001
block|,
comment|/* cond: ysem.foc_credit[1] */
literal|0x2e5401a0
block|,
literal|0x03010001
block|,
comment|/* cond: ysem.foc_credit[3] */
literal|0x2e5401a0
block|,
literal|0x04010001
block|,
comment|/* cond: ysem.foc_credit[4] */
literal|0x2e5401a0
block|,
literal|0x05010001
block|,
comment|/* cond: ysem.foc_credit[5] */
literal|0x2e540441
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.ext_pas_empty */
literal|0x2e540448
block|,
literal|0x00010002
block|,
comment|/* cond: ysem.fic_empty[0:1] */
literal|0x2e540454
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.slow_ext_store_empty */
literal|0x2e540455
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.slow_ext_load_empty */
literal|0x2e540457
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.slow_ram_wr_empty */
literal|0x2e540458
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.sync_dbg_empty */
literal|0x2e540481
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.ext_store_if_full */
literal|0x2e540491
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.ram_if_full */
literal|0x2f580010
block|,
literal|0x00010001
block|,
comment|/* cond: psem.INT_STS_0 */
literal|0x2f580011
block|,
literal|0x00010001
block|,
comment|/* cond: psem.INT_MASK_0 */
literal|0x2f580014
block|,
literal|0x00010001
block|,
comment|/* cond: psem.INT_STS_1 */
literal|0x2f580015
block|,
literal|0x00010001
block|,
comment|/* cond: psem.INT_MASK_1 */
literal|0x2f580032
block|,
literal|0x00010001
block|,
comment|/* cond: psem.PRTY_STS */
literal|0x2f580033
block|,
literal|0x00010001
block|,
comment|/* cond: psem.PRTY_MASK */
literal|0x2f580110
block|,
literal|0x00010001
block|,
comment|/* cond: psem.pf_err_vector */
literal|0x2f5801a0
block|,
literal|0x00010001
block|,
comment|/* cond: psem.foc_credit */
literal|0x2f5801a0
block|,
literal|0x01010001
block|,
comment|/* cond: psem.foc_credit[1] */
literal|0x2f580441
block|,
literal|0x00010001
block|,
comment|/* cond: psem.ext_pas_empty */
literal|0x2f580448
block|,
literal|0x00010001
block|,
comment|/* cond: psem.fic_empty */
literal|0x2f580454
block|,
literal|0x00010001
block|,
comment|/* cond: psem.slow_ext_store_empty */
literal|0x2f580455
block|,
literal|0x00010001
block|,
comment|/* cond: psem.slow_ext_load_empty */
literal|0x2f580457
block|,
literal|0x00010001
block|,
comment|/* cond: psem.slow_ram_wr_empty */
literal|0x2f580458
block|,
literal|0x00010001
block|,
comment|/* cond: psem.sync_dbg_empty */
literal|0x2f580481
block|,
literal|0x00010001
block|,
comment|/* cond: psem.ext_store_if_full */
literal|0x2f580491
block|,
literal|0x00010001
block|,
comment|/* cond: psem.ram_if_full */
literal|0x2a5c0010
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.INT_STS_0 */
literal|0x2a5c0011
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.INT_MASK_0 */
literal|0x2a5c0014
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.INT_STS_1 */
literal|0x2a5c0015
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.INT_MASK_1 */
literal|0x2a5c0032
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.PRTY_STS */
literal|0x2a5c0033
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.PRTY_MASK */
literal|0x2a5c0110
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.pf_err_vector */
literal|0x2a5c01a0
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.foc_credit */
literal|0x2a5c01a0
block|,
literal|0x01010001
block|,
comment|/* cond: tsem.foc_credit[1] */
literal|0x2a5c0441
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.ext_pas_empty */
literal|0x2a5c0448
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.fic_empty */
literal|0x2a5c0454
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.slow_ext_store_empty */
literal|0x2a5c0455
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.slow_ext_load_empty */
literal|0x2a5c0457
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.slow_ram_wr_empty */
literal|0x2a5c0458
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.sync_dbg_empty */
literal|0x2a5c0481
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.ext_store_if_full */
literal|0x2a5c0491
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.ram_if_full */
literal|0x2b600010
block|,
literal|0x00010001
block|,
comment|/* cond: msem.INT_STS_0 */
literal|0x2b600011
block|,
literal|0x00010001
block|,
comment|/* cond: msem.INT_MASK_0 */
literal|0x2b600014
block|,
literal|0x00010001
block|,
comment|/* cond: msem.INT_STS_1 */
literal|0x2b600015
block|,
literal|0x00010001
block|,
comment|/* cond: msem.INT_MASK_1 */
literal|0x2b600032
block|,
literal|0x00010001
block|,
comment|/* cond: msem.PRTY_STS */
literal|0x2b600033
block|,
literal|0x00010001
block|,
comment|/* cond: msem.PRTY_MASK */
literal|0x2b600080
block|,
literal|0x00010001
block|,
comment|/* cond: msem.PRTY_STS_H_0 */
literal|0x2b600081
block|,
literal|0x00010001
block|,
comment|/* cond: msem.PRTY_MASK_H_0 */
literal|0x2b600110
block|,
literal|0x00010001
block|,
comment|/* cond: msem.pf_err_vector */
literal|0x2b6001a0
block|,
literal|0x03010001
block|,
comment|/* cond: msem.foc_credit[3] */
literal|0x2b6001a0
block|,
literal|0x04010001
block|,
comment|/* cond: msem.foc_credit[4] */
literal|0x2b6001a0
block|,
literal|0x05010001
block|,
comment|/* cond: msem.foc_credit[5] */
literal|0x2b6001a0
block|,
literal|0x00010001
block|,
comment|/* cond: msem.foc_credit */
literal|0x2b6001a0
block|,
literal|0x01010001
block|,
comment|/* cond: msem.foc_credit[1] */
literal|0x2b6001a0
block|,
literal|0x02010001
block|,
comment|/* cond: msem.foc_credit[2] */
literal|0x2b600441
block|,
literal|0x00010001
block|,
comment|/* cond: msem.ext_pas_empty */
literal|0x2b600448
block|,
literal|0x00010001
block|,
comment|/* cond: msem.fic_empty */
literal|0x2b600454
block|,
literal|0x00010001
block|,
comment|/* cond: msem.slow_ext_store_empty */
literal|0x2b600455
block|,
literal|0x00010001
block|,
comment|/* cond: msem.slow_ext_load_empty */
literal|0x2b600457
block|,
literal|0x00010001
block|,
comment|/* cond: msem.slow_ram_wr_empty */
literal|0x2b600458
block|,
literal|0x00010001
block|,
comment|/* cond: msem.sync_dbg_empty */
literal|0x2b600481
block|,
literal|0x00010001
block|,
comment|/* cond: msem.ext_store_if_full */
literal|0x2b600491
block|,
literal|0x00010001
block|,
comment|/* cond: msem.ram_if_full */
literal|0x2c640010
block|,
literal|0x00010001
block|,
comment|/* cond: usem.INT_STS_0 */
literal|0x2c640011
block|,
literal|0x00010001
block|,
comment|/* cond: usem.INT_MASK_0 */
literal|0x2c640014
block|,
literal|0x00010001
block|,
comment|/* cond: usem.INT_STS_1 */
literal|0x2c640015
block|,
literal|0x00010001
block|,
comment|/* cond: usem.INT_MASK_1 */
literal|0x2c640032
block|,
literal|0x00010001
block|,
comment|/* cond: usem.PRTY_STS */
literal|0x2c640033
block|,
literal|0x00010001
block|,
comment|/* cond: usem.PRTY_MASK */
literal|0x2c640110
block|,
literal|0x00010001
block|,
comment|/* cond: usem.pf_err_vector */
literal|0x2c6401a0
block|,
literal|0x01010001
block|,
comment|/* cond: usem.foc_credit[1] */
literal|0x2c6401a0
block|,
literal|0x03010001
block|,
comment|/* cond: usem.foc_credit[3] */
literal|0x2c6401a0
block|,
literal|0x02010001
block|,
comment|/* cond: usem.foc_credit[2] */
literal|0x2c6401a0
block|,
literal|0x00010001
block|,
comment|/* cond: usem.foc_credit */
literal|0x2c6401a0
block|,
literal|0x04010001
block|,
comment|/* cond: usem.foc_credit[4] */
literal|0x2c640441
block|,
literal|0x00010001
block|,
comment|/* cond: usem.ext_pas_empty */
literal|0x2c640448
block|,
literal|0x00010001
block|,
comment|/* cond: usem.fic_empty */
literal|0x2c640454
block|,
literal|0x00010001
block|,
comment|/* cond: usem.slow_ext_store_empty */
literal|0x2c640455
block|,
literal|0x00010001
block|,
comment|/* cond: usem.slow_ext_load_empty */
literal|0x2c640457
block|,
literal|0x00010001
block|,
comment|/* cond: usem.slow_ram_wr_empty */
literal|0x2c640458
block|,
literal|0x00010001
block|,
comment|/* cond: usem.sync_dbg_empty */
literal|0x2c640481
block|,
literal|0x00010001
block|,
comment|/* cond: usem.ext_store_if_full */
literal|0x2c640491
block|,
literal|0x00010001
block|,
comment|/* cond: usem.ram_if_full */
literal|0x0a015000
block|,
literal|0x00010001
block|,
comment|/* cond: pcie.PRTY_STS_H_0 */
literal|0x42060220
block|,
literal|0x00010009
block|,
comment|/* cond: igu.pending_bits_status[0:8] */
literal|0x42060240
block|,
literal|0x00010009
block|,
comment|/* cond: igu.write_done_pending[0:8] */
literal|0x050860ba
block|,
literal|0x00010001
block|,
comment|/* cond: cnig.INT_STS */
literal|0x050860bb
block|,
literal|0x00010001
block|,
comment|/* cond: cnig.INT_MASK */
literal|0x050860a7
block|,
literal|0x00150001
block|,
comment|/* info: cnig.cnig_dbg_fifo_error mode=!(k2|e5) */
literal|0x050860d2
block|,
literal|0x00010001
block|,
comment|/* cond: cnig.PRTY_STS */
literal|0x050860d3
block|,
literal|0x00010001
block|,
comment|/* cond: cnig.PRTY_MASK */
literal|0x0d0a8018
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.vf_disabled_error_valid */
literal|0x0d0a8017
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.vf_disabled_error_data mode=all */
literal|0x040aa80e
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_vf_223_192 */
literal|0x040aa80f
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.flr_request_vf_255_224 */
literal|0x040aa83c
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.incorrect_rcv_details */
literal|0x040aa843
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_vf_223_192 */
literal|0x040aa844
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.was_error_vf_255_224 */
literal|0x040aab92
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tags_159_128 */
literal|0x040aab93
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tags_191_160 */
literal|0x040aab94
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tags_223_192 */
literal|0x040aab95
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.tags_255_224 */
literal|0x410b41e3
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.cduwb_credit */
literal|0x1e8bc300
block|,
literal|0x00020040
block|,
comment|/* cond: qm.PtrTblOther[0:63] width=2 access=WB */
literal|0x1e8bc300
block|,
literal|0x00020040
block|,
comment|/* cond: qm.PtrTblOther[0:63] width=2 access=WB */
literal|0x1e0bc410
block|,
literal|0x0001000e
block|,
comment|/* cond: qm.QstatusTx_0[0:13] */
literal|0x1e0bc430
block|,
literal|0x00010002
block|,
comment|/* cond: qm.QstatusOther_0[0:1] */
literal|0x1e0bc560
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqCrdLine[0:7] */
literal|0x1e0bc5a0
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqInitCrdLine[0:7] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc560
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqCrdLine[16] */
literal|0x1e0bc5a0
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqInitCrdLine[16] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc560
block|,
literal|0x00010012
block|,
comment|/* cond: qm.VoqCrdLine[0:17] */
literal|0x1e0bc5a0
block|,
literal|0x00010012
block|,
comment|/* cond: qm.VoqInitCrdLine[0:17] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc5e0
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqCrdByte[0:7] */
literal|0x1e0bc620
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqInitCrdByte[0:7] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc5e0
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqCrdByte[16] */
literal|0x1e0bc620
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqInitCrdByte[16] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc5e0
block|,
literal|0x00010012
block|,
comment|/* cond: qm.VoqCrdByte[0:17] */
literal|0x1e0bc620
block|,
literal|0x00010012
block|,
comment|/* cond: qm.VoqInitCrdByte[0:17] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e8bf800
block|,
literal|0x000201c0
block|,
comment|/* cond: qm.PtrTblTx[0:447] width=2 access=WB */
literal|0x1e8bf800
block|,
literal|0x000201c0
block|,
comment|/* cond: qm.PtrTblTx[0:447] width=2 access=WB */
literal|0x210d03cc
block|,
literal|0x00010004
block|,
comment|/* cond: brb.wc_empty_0[0:3] */
literal|0x210d041e
block|,
literal|0x00010001
block|,
comment|/* cond: brb.rc_eop_empty */
literal|0x218d06c0
block|,
literal|0x00030004
block|,
comment|/* cond: brb.wc_status_0[0:3] width=3 access=WB */
literal|0x4b140028
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_STS */
literal|0x4b140029
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_MASK */
literal|0x4b1422db
block|,
literal|0x00000001
block|,
comment|/* info: nig.rx_parity_err mode=all */
literal|0x4b1422dc
block|,
literal|0x00000001
block|,
comment|/* info: nig.tx_parity_err mode=all */
literal|0x4b1422dd
block|,
literal|0x00000001
block|,
comment|/* info: nig.lb_parity_err mode=all */
literal|0x3b36c030
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_0 */
literal|0x3b36c031
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_0 */
literal|0x3bb6c400
block|,
literal|0x00000008
block|,
comment|/* info: btb.stopped_rd_req[0:3] width=2 access=WB mode=all */
literal|0x3bb6c440
block|,
literal|0x00000008
block|,
comment|/* info: btb.stopped_rls_req[0:3] width=2 access=WB mode=all */
literal|0x3b36c048
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_4 */
literal|0x3b36c049
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_4 */
literal|0x3bb6c400
block|,
literal|0x00000008
block|,
comment|/* info: btb.stopped_rd_req[0:3] width=2 access=WB mode=all */
literal|0x3bb6c440
block|,
literal|0x00000008
block|,
comment|/* info: btb.stopped_rls_req[0:3] width=2 access=WB mode=all */
literal|0x1b4002aa
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.msdm_length_mis */
literal|0x1b4002c4
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_msdm_fill_lvl */
literal|0x1b4002ca
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_ysem_fill_lvl */
literal|0x1b401000
block|,
literal|0x000101c0
block|,
comment|/* cond: xcm.qm_act_st_cnt[0:447] */
literal|0x1c4202aa
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.msdm_length_mis */
literal|0x1c4202bd
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_msdm_fill_lvl */
literal|0x1d4402aa
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.psdm_length_mis */
literal|0x1d4402b3
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.is_psdm_fill_lvl */
literal|0x184602aa
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.tsdm_length_mis */
literal|0x184602bf
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_tsdm_fill_lvl */
literal|0x194802aa
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.msdm_length_mis */
literal|0x194802bf
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_msdm_fill_lvl */
literal|0x194802c4
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_ysem_fill_lvl */
literal|0x2dd00108
block|,
literal|0x00040001
block|,
comment|/* cond: xsem.vf_err_vector width=4 access=WB */
literal|0x2ed40108
block|,
literal|0x00040001
block|,
comment|/* cond: ysem.vf_err_vector width=4 access=WB */
literal|0x2fd80108
block|,
literal|0x00040001
block|,
comment|/* cond: psem.vf_err_vector width=4 access=WB */
literal|0x2adc0108
block|,
literal|0x00040001
block|,
comment|/* cond: tsem.vf_err_vector width=4 access=WB */
literal|0x2be00108
block|,
literal|0x00040001
block|,
comment|/* cond: msem.vf_err_vector width=4 access=WB */
literal|0x2ce40108
block|,
literal|0x00040001
block|,
comment|/* cond: usem.vf_err_vector width=4 access=WB */
literal|0x0a015000
block|,
literal|0x00010001
block|,
comment|/* cond: pcie.PRTY_STS_H_0 */
literal|0x0a015001
block|,
literal|0x00010001
block|,
comment|/* cond: pcie.PRTY_MASK_H_0 */
literal|0x42060220
block|,
literal|0x0001000c
block|,
comment|/* cond: igu.pending_bits_status[0:11] */
literal|0x42060240
block|,
literal|0x0001000c
block|,
comment|/* cond: igu.write_done_pending[0:11] */
literal|0x0d0a8018
block|,
literal|0x00010001
block|,
comment|/* cond: pswhst.vf_disabled_error_valid */
literal|0x0d0a8017
block|,
literal|0x00000001
block|,
comment|/* info: pswhst.vf_disabled_error_data mode=all */
literal|0x410b41e3
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.cduwb_credit */
literal|0x1e0bc410
block|,
literal|0x00010010
block|,
comment|/* cond: qm.QstatusTx_0[0:15] */
literal|0x1e0bc430
block|,
literal|0x00010004
block|,
comment|/* cond: qm.QstatusOther_0[0:3] */
literal|0x1e0bc560
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqCrdLine[0:7] */
literal|0x1e0bc5a0
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqInitCrdLine[0:7] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc560
block|,
literal|0x00010014
block|,
comment|/* cond: qm.VoqCrdLine[0:19] */
literal|0x1e0bc5a0
block|,
literal|0x00010014
block|,
comment|/* cond: qm.VoqInitCrdLine[0:19] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc560
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqCrdLine[16] */
literal|0x1e0bc5a0
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqInitCrdLine[16] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc5e0
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqCrdByte[16] */
literal|0x1e0bc620
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqInitCrdByte[16] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc5e0
block|,
literal|0x00010014
block|,
comment|/* cond: qm.VoqCrdByte[0:19] */
literal|0x1e0bc620
block|,
literal|0x00010014
block|,
comment|/* cond: qm.VoqInitCrdByte[0:19] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bc5e0
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqCrdByte[0:7] */
literal|0x1e0bc620
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqInitCrdByte[0:7] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x210d03cc
block|,
literal|0x00010008
block|,
comment|/* cond: brb.wc_empty_0[0:7] */
literal|0x210d041e
block|,
literal|0x00010001
block|,
comment|/* cond: brb.rc_eop_empty */
literal|0x218d06c0
block|,
literal|0x00030008
block|,
comment|/* cond: brb.wc_status_0[0:7] width=3 access=WB */
literal|0x3b36c030
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_0 */
literal|0x3b36c031
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_0 */
literal|0x3bb6c400
block|,
literal|0x00000010
block|,
comment|/* info: btb.stopped_rd_req[0:7] width=2 access=WB mode=all */
literal|0x3bb6c440
block|,
literal|0x00000010
block|,
comment|/* info: btb.stopped_rls_req[0:7] width=2 access=WB mode=all */
literal|0x3b36c048
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_4 */
literal|0x3b36c049
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_4 */
literal|0x3bb6c400
block|,
literal|0x00000010
block|,
comment|/* info: btb.stopped_rd_req[0:7] width=2 access=WB mode=all */
literal|0x3bb6c440
block|,
literal|0x00000010
block|,
comment|/* info: btb.stopped_rls_req[0:7] width=2 access=WB mode=all */
literal|0x1b4002aa
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.msdm_length_mis */
literal|0x1b4002c4
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_msdm_fill_lvl */
literal|0x1b4002ca
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_ysem_fill_lvl */
literal|0x1c4202aa
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.msdm_length_mis */
literal|0x1c4202bd
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_msdm_fill_lvl */
literal|0x1d4402aa
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.psdm_length_mis */
literal|0x1d4402b3
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.is_psdm_fill_lvl */
literal|0x184602aa
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.tsdm_length_mis */
literal|0x184602bf
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_tsdm_fill_lvl */
literal|0x194802aa
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.msdm_length_mis */
literal|0x194802bf
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_msdm_fill_lvl */
literal|0x194802c4
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_ysem_fill_lvl */
literal|0x14090279
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_7 */
literal|0x140902d8
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq7 */
literal|0x1409027a
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_8 */
literal|0x140902d9
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq8 */
literal|0x1409027c
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_10 */
literal|0x140902db
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq10 */
literal|0x1409027f
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_13 */
literal|0x140902de
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq13 */
literal|0x14090280
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_14 */
literal|0x140902df
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq14 */
literal|0x14090286
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_20 */
literal|0x140902e5
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq20 */
literal|0x1409028b
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_25 */
literal|0x140902ea
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq25 */
literal|0x1409028d
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_27 */
literal|0x140902ec
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq27 */
literal|0x14090291
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.sr_cnt_per_vq_31 */
literal|0x140902f0
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_srs_vq31 */
literal|0x1409029a
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_7 */
literal|0x14090258
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq7 */
literal|0x1409029b
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_8 */
literal|0x14090259
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq8 */
literal|0x1409029d
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_10 */
literal|0x1409025b
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq10 */
literal|0x140902a0
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_13 */
literal|0x1409025e
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq13 */
literal|0x140902a1
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_14 */
literal|0x1409025f
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq14 */
literal|0x140902a7
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_20 */
literal|0x14090265
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq20 */
literal|0x140902ac
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_25 */
literal|0x1409026a
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq25 */
literal|0x140902ae
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_27 */
literal|0x1409026c
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq27 */
literal|0x140902b2
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.blk_cnt_per_vq_31 */
literal|0x14090270
block|,
literal|0x00010001
block|,
comment|/* cond: pswrq2.max_blks_vq31 */
literal|0x1f0b0064
block|,
literal|0x00010001
block|,
comment|/* cond: tm.INT_STS_1 */
literal|0x09150100
block|,
literal|0x00010001
block|,
comment|/* cond: bmb.PRTY_STS_H_0 */
literal|0x09150101
block|,
literal|0x00010001
block|,
comment|/* cond: bmb.PRTY_MASK_H_0 */
literal|0x09150104
block|,
literal|0x00010001
block|,
comment|/* cond: bmb.PRTY_STS_H_1 */
literal|0x09150105
block|,
literal|0x00010001
block|,
comment|/* cond: bmb.PRTY_MASK_H_1 */
literal|0x1f0b0064
block|,
literal|0x00010001
block|,
comment|/* cond: tm.INT_STS_1 */
literal|0x15000841
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.UNCORR_ERR_STATUS_OFF */
literal|0x15000841
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.UNCORR_ERR_STATUS_OFF */
literal|0x15000841
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.UNCORR_ERR_STATUS_OFF */
literal|0x15000847
block|,
literal|0x00010004
block|,
comment|/* cond: pglcs.pgl_cs.HDR_LOG_0_OFF[0:3] */
literal|0x15000e0c
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.syncfifo_pop_underflow */
literal|0x15000e0d
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.syncfifo_push_overflow */
literal|0x15000e0e
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.tx_syncfifo_pop_status */
literal|0x0a0151e8
block|,
literal|0x00010001
block|,
comment|/* cond: pcie.INT_STS */
literal|0x05086086
block|,
literal|0x00010001
block|,
comment|/* cond: cnig.INT_STS */
literal|0x05086087
block|,
literal|0x00010001
block|,
comment|/* cond: cnig.INT_MASK */
literal|0x050860a7
block|,
literal|0x00150001
block|,
comment|/* info: cnig.cnig_dbg_fifo_error mode=!(k2|e5) */
literal|0x0508608b
block|,
literal|0x00010001
block|,
comment|/* cond: cnig.PRTY_STS */
literal|0x0508608c
block|,
literal|0x00010001
block|,
comment|/* cond: cnig.PRTY_MASK */
literal|0x040aabf1
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.syncfifo_push_overflow */
literal|0x040aabf2
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.syncfifo_pop_underflow */
literal|0x040aabf3
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.rxh_syncfifo_pop_status */
literal|0x040aabf4
block|,
literal|0x00010001
block|,
comment|/* cond: pglue_b.rxd_syncfifo_pop_status */
literal|0x040aabf3
block|,
literal|0x00250001
block|,
comment|/* info: pglue_b.rxh_syncfifo_pop_status mode=!bb */
literal|0x1e8bc300
block|,
literal|0x00020080
block|,
comment|/* cond: qm.PtrTblOther[0:127] width=2 access=WB */
literal|0x1e8bc300
block|,
literal|0x00020080
block|,
comment|/* cond: qm.PtrTblOther[0:127] width=2 access=WB */
literal|0x1e8bf800
block|,
literal|0x00020200
block|,
comment|/* cond: qm.PtrTblTx[0:511] width=2 access=WB */
literal|0x1e8bf800
block|,
literal|0x00020200
block|,
comment|/* cond: qm.PtrTblTx[0:511] width=2 access=WB */
literal|0x210d0494
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac2_tc_occupancy_0 */
literal|0x210d0495
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac2_tc_occupancy_1 */
literal|0x210d0496
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac2_tc_occupancy_2 */
literal|0x210d0497
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac2_tc_occupancy_3 */
literal|0x210d0498
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac2_tc_occupancy_4 */
literal|0x210d04a4
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac3_tc_occupancy_0 */
literal|0x210d04a5
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac3_tc_occupancy_1 */
literal|0x210d04a6
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac3_tc_occupancy_2 */
literal|0x210d04a7
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac3_tc_occupancy_3 */
literal|0x210d04a8
block|,
literal|0x00010001
block|,
comment|/* cond: brb.mac3_tc_occupancy_4 */
literal|0x4b140028
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_6 */
literal|0x4b140029
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_6 */
literal|0x4b14002c
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_7 */
literal|0x4b14002d
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_7 */
literal|0x4b1406e8
block|,
literal|0x00000001
block|,
comment|/* info: nig.flowctrl_mode mode=all */
literal|0x4b140713
block|,
literal|0x00000001
block|,
comment|/* info: nig.rx_flowctrl_status mode=all */
literal|0x4b140030
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_8 */
literal|0x4b140031
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_8 */
literal|0x4b140034
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_STS_9 */
literal|0x4b140035
block|,
literal|0x00010001
block|,
comment|/* cond: nig.INT_MASK_9 */
literal|0x4b1406e8
block|,
literal|0x00000001
block|,
comment|/* info: nig.flowctrl_mode mode=all */
literal|0x4b140713
block|,
literal|0x00000001
block|,
comment|/* info: nig.rx_flowctrl_status mode=all */
literal|0x4b140038
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_STS */
literal|0x4b140039
block|,
literal|0x00010001
block|,
comment|/* cond: nig.PRTY_MASK */
literal|0x4b1422db
block|,
literal|0x00000001
block|,
comment|/* info: nig.rx_parity_err mode=all */
literal|0x4b1422dc
block|,
literal|0x00000001
block|,
comment|/* info: nig.tx_parity_err mode=all */
literal|0x4b1422dd
block|,
literal|0x00000001
block|,
comment|/* info: nig.lb_parity_err mode=all */
literal|0x501c0003
block|,
literal|0x00010001
block|,
comment|/* cond: nws.common_status */
literal|0x501c0003
block|,
literal|0x00010001
block|,
comment|/* cond: nws.common_status */
literal|0x501c0060
block|,
literal|0x00010001
block|,
comment|/* cond: nws.INT_STS_0 */
literal|0x501c0080
block|,
literal|0x00010001
block|,
comment|/* cond: nws.PRTY_STS_H_0 */
literal|0x501c0081
block|,
literal|0x00010001
block|,
comment|/* cond: nws.PRTY_MASK_H_0 */
literal|0x501c9827
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln0_top_phy_if_status */
literal|0x501c0000
block|,
literal|0x00010001
block|,
comment|/* cond: nws.common_control */
literal|0x501ca027
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln1_top_phy_if_status */
literal|0x501c0000
block|,
literal|0x00010001
block|,
comment|/* cond: nws.common_control */
literal|0x501ca827
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln2_top_phy_if_status */
literal|0x501c0000
block|,
literal|0x00010001
block|,
comment|/* cond: nws.common_control */
literal|0x501cb027
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln3_top_phy_if_status */
literal|0x501c0000
block|,
literal|0x00010001
block|,
comment|/* cond: nws.common_control */
literal|0x4f200001
block|,
literal|0x00010001
block|,
comment|/* cond: nwm.INT_STS */
literal|0x4f200001
block|,
literal|0x00010001
block|,
comment|/* cond: nwm.INT_STS */
literal|0x4f200080
block|,
literal|0x00010001
block|,
comment|/* cond: nwm.PRTY_STS_H_0 */
literal|0x4f200081
block|,
literal|0x00010001
block|,
comment|/* cond: nwm.PRTY_MASK_H_0 */
literal|0x4f200084
block|,
literal|0x00010001
block|,
comment|/* cond: nwm.PRTY_STS_H_1 */
literal|0x4f200085
block|,
literal|0x00010001
block|,
comment|/* cond: nwm.PRTY_MASK_H_1 */
literal|0x4f200088
block|,
literal|0x00010001
block|,
comment|/* cond: nwm.PRTY_STS_H_2 */
literal|0x4f200089
block|,
literal|0x00010001
block|,
comment|/* cond: nwm.PRTY_MASK_H_2 */
literal|0x3b36c26d
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_empty_4 */
literal|0x3b36c26e
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_empty_5 */
literal|0x3b36c26f
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_empty_6 */
literal|0x3b36c270
block|,
literal|0x00010001
block|,
comment|/* cond: btb.rc_pkt_empty_7 */
literal|0x1b401000
block|,
literal|0x00010200
block|,
comment|/* cond: xcm.qm_act_st_cnt[0:511] */
literal|0x2dd00108
block|,
literal|0x00080001
block|,
comment|/* cond: xsem.vf_err_vector width=8 access=WB */
literal|0x2ed40108
block|,
literal|0x00080001
block|,
comment|/* cond: ysem.vf_err_vector width=8 access=WB */
literal|0x2fd80108
block|,
literal|0x00080001
block|,
comment|/* cond: psem.vf_err_vector width=8 access=WB */
literal|0x2adc0108
block|,
literal|0x00080001
block|,
comment|/* cond: tsem.vf_err_vector width=8 access=WB */
literal|0x2be00108
block|,
literal|0x00080001
block|,
comment|/* cond: msem.vf_err_vector width=8 access=WB */
literal|0x2ce40108
block|,
literal|0x00080001
block|,
comment|/* cond: usem.vf_err_vector width=8 access=WB */
literal|0x42060220
block|,
literal|0x00010010
block|,
comment|/* cond: igu.pending_bits_status[0:15] */
literal|0x42060240
block|,
literal|0x00010010
block|,
comment|/* cond: igu.write_done_pending[0:15] */
literal|0x410b41e3
block|,
literal|0x00010001
block|,
comment|/* cond: tcfc.cduwb_credit */
literal|0x1e0bfe80
block|,
literal|0x00010024
block|,
comment|/* cond: qm.VoqCrdLine[0:35] */
literal|0x1e0bfec0
block|,
literal|0x00010024
block|,
comment|/* cond: qm.VoqInitCrdLine[0:35] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bfe80
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqCrdLine[0:7] */
literal|0x1e0bfec0
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqInitCrdLine[0:7] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bfe80
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqCrdLine[16] */
literal|0x1e0bfec0
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqInitCrdLine[16] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bff00
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqCrdByte[16] */
literal|0x1e0bff40
block|,
literal|0x10010001
block|,
comment|/* cond: qm.VoqInitCrdByte[16] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bff00
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqCrdByte[0:7] */
literal|0x1e0bff40
block|,
literal|0x00010008
block|,
comment|/* cond: qm.VoqInitCrdByte[0:7] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x1e0bff00
block|,
literal|0x00010024
block|,
comment|/* cond: qm.VoqCrdByte[0:35] */
literal|0x1e0bff40
block|,
literal|0x00010024
block|,
comment|/* cond: qm.VoqInitCrdByte[0:35] */
literal|0x02002300
block|,
literal|0x00010001
block|,
comment|/* cond: misc.port_mode */
literal|0x210d041e
block|,
literal|0x00010001
block|,
comment|/* cond: brb.rc_eop_empty */
literal|0x3b36c030
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_0 */
literal|0x3b36c031
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_0 */
literal|0x3bb6c400
block|,
literal|0x00000020
block|,
comment|/* info: btb.stopped_rd_req[0:7] width=3 access=WB mode=all */
literal|0x3bb6c440
block|,
literal|0x00000010
block|,
comment|/* info: btb.stopped_rls_req[0:7] width=2 access=WB mode=all */
literal|0x3b36c048
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_STS_4 */
literal|0x3b36c049
block|,
literal|0x00010001
block|,
comment|/* cond: btb.INT_MASK_4 */
literal|0x3bb6c400
block|,
literal|0x00000020
block|,
comment|/* info: btb.stopped_rd_req[0:7] width=3 access=WB mode=all */
literal|0x3bb6c440
block|,
literal|0x00000010
block|,
comment|/* info: btb.stopped_rls_req[0:7] width=2 access=WB mode=all */
literal|0x1b400791
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.msdm_length_mis */
literal|0x1b400793
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_msdm_fill_lvl */
literal|0x1b4007c2
block|,
literal|0x00010001
block|,
comment|/* cond: xcm.is_ysem_fill_lvl */
literal|0x1c4207b1
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.msdm_length_mis */
literal|0x1c4207b3
block|,
literal|0x00010001
block|,
comment|/* cond: ycm.is_msdm_fill_lvl */
literal|0x1d4405d5
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.psdm_length_mis */
literal|0x1d4405d7
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.is_psdm_fill_lvl */
literal|0x184606c1
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.tsdm_length_mis */
literal|0x184606c3
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_tsdm_fill_lvl */
literal|0x19480a41
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.msdm_length_mis */
literal|0x19480a43
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_msdm_fill_lvl */
literal|0x19480a82
block|,
literal|0x00010001
block|,
comment|/* cond: mcm.is_ysem_fill_lvl */
literal|0x15000841
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.uc_err_status */
literal|0x15000841
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.uc_err_status */
literal|0x15000841
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.uc_err_status */
literal|0x15000847
block|,
literal|0x00010004
block|,
comment|/* cond: pglcs.pgl_cs.header_log1[0:3] */
literal|0x15000a05
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.tl_ctrlstat_5 */
literal|0x15000a05
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.tl_ctrlstat_5 */
literal|0x15000a15
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.tl_func345_stat */
literal|0x15000a17
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.tl_func678_stat */
literal|0x15000c10
block|,
literal|0x00010001
block|,
comment|/* cond: pglcs.pgl_cs.DLATTN_VEC */
literal|0x01002464
block|,
literal|0x00010001
block|,
comment|/* cond: miscs.INT_STS_1 */
literal|0x01002465
block|,
literal|0x00010001
block|,
comment|/* cond: miscs.INT_MASK_1 */
literal|0x42060084
block|,
literal|0x00010001
block|,
comment|/* cond: igu.PRTY_STS_H_1 */
literal|0x42060085
block|,
literal|0x00010001
block|,
comment|/* cond: igu.PRTY_MASK_H_1 */
literal|0x4b140391
block|,
literal|0x00010001
block|,
comment|/* cond: nig.rx_macfifo_empty */
literal|0x08014c00
block|,
literal|0x00010001
block|,
comment|/* cond: opte.PRTY_STS_H_0 */
literal|0x08014c01
block|,
literal|0x00010001
block|,
comment|/* cond: opte.PRTY_MASK_H_0 */
literal|0x43070327
block|,
literal|0x00010001
block|,
comment|/* cond: cau.agg_units_0to15_state */
literal|0x43070328
block|,
literal|0x00010001
block|,
comment|/* cond: cau.agg_units_16to31_state */
literal|0x43070329
block|,
literal|0x00010001
block|,
comment|/* cond: cau.agg_units_32to47_state */
literal|0x4307032a
block|,
literal|0x00010001
block|,
comment|/* cond: cau.agg_units_48to63_state */
literal|0x430703c3
block|,
literal|0x00010001
block|,
comment|/* cond: cau.igu_cqe_cmd_fsm_status */
literal|0x430703c4
block|,
literal|0x00010001
block|,
comment|/* cond: cau.igu_cqe_agg_fsm_status */
literal|0x2307c085
block|,
literal|0x00010001
block|,
comment|/* cond: prs.PRTY_STS_H_1 */
literal|0x2307c086
block|,
literal|0x00010001
block|,
comment|/* cond: prs.PRTY_MASK_H_1 */
literal|0x2307c2d4
block|,
literal|0x00010001
block|,
comment|/* cond: prs.prs_pkt_ct */
literal|0x2307c3c3
block|,
literal|0x00010001
block|,
comment|/* cond: prs.tcm_current_credit */
literal|0x3008e30e
block|,
literal|0x00010001
block|,
comment|/* cond: rss.empty_status */
literal|0x3008e30f
block|,
literal|0x00010001
block|,
comment|/* cond: rss.full_status */
literal|0x3008e310
block|,
literal|0x00010001
block|,
comment|/* cond: rss.counters_status */
literal|0x3008e311
block|,
literal|0x00010001
block|,
comment|/* cond: rss.state_machines */
literal|0x33132013
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.pending_msg_to_ext_ev_1_ctr */
literal|0x33132014
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.pending_msg_to_ext_ev_2_ctr */
literal|0x33132015
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.pending_msg_to_ext_ev_3_ctr */
literal|0x33132016
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.pending_msg_to_ext_ev_4_ctr */
literal|0x33132017
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.pending_msg_to_ext_ev_5_ctr */
literal|0x33132018
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.foc_remain_credits */
literal|0x33132003
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.foci_foc_credits */
literal|0x3313202c
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.dbg_pending_ccfc_req */
literal|0x3313202d
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.dbg_pending_tcfc_req */
literal|0x33132080
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.PRTY_STS_H_0 */
literal|0x33132081
block|,
literal|0x00010001
block|,
comment|/* cond: yuld.PRTY_MASK_H_0 */
literal|0x4b140394
block|,
literal|0x00010001
block|,
comment|/* cond: nig.tx_macfifo_empty */
literal|0x3c360080
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.PRTY_STS_H_0 */
literal|0x3c360081
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.PRTY_MASK_H_0 */
literal|0x3c360084
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.PRTY_STS_H_1 */
literal|0x3c360085
block|,
literal|0x00010001
block|,
comment|/* cond: pbf.PRTY_MASK_H_1 */
literal|0x1d4402ab
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.pbf_length_mis */
literal|0x1d4402b4
block|,
literal|0x00010001
block|,
comment|/* cond: pcm.is_pbf_fill_lvl */
literal|0x184602ad
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.prs_length_mis */
literal|0x184602c4
block|,
literal|0x00010001
block|,
comment|/* cond: tcm.is_prs_fill_lvl */
literal|0x1a4a02b2
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.yuld_length_mis */
literal|0x1a4a02cd
block|,
literal|0x00010001
block|,
comment|/* cond: ucm.is_yuld_fill_lvl */
literal|0x2d500080
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.PRTY_STS_H_0 */
literal|0x2d500081
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.PRTY_MASK_H_0 */
literal|0x2d5002c1
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.thread_error */
literal|0x2d5002c2
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.thread_rdy */
literal|0x2d5002c4
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.thread_valid */
literal|0x2d500440
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.dra_empty */
literal|0x2d500450
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.slow_dbg_empty */
literal|0x2d500451
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.slow_dra_fin_empty */
literal|0x2d500452
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.slow_dra_rd_empty */
literal|0x2d500453
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.slow_dra_wr_empty */
literal|0x2d500456
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.slow_ram_rd_empty */
literal|0x2d500459
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.thread_fifo_empty */
literal|0x2d500490
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.pas_if_full */
literal|0x2d5004c2
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.thread_orun_num */
literal|0x2d500505
block|,
literal|0x00010001
block|,
comment|/* cond: xsem.dbg_if_full */
literal|0x2e540080
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.PRTY_STS_H_0 */
literal|0x2e540081
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.PRTY_MASK_H_0 */
literal|0x2e5402c1
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.thread_error */
literal|0x2e5402c2
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.thread_rdy */
literal|0x2e5402c4
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.thread_valid */
literal|0x2e540440
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.dra_empty */
literal|0x2e540450
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.slow_dbg_empty */
literal|0x2e540451
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.slow_dra_fin_empty */
literal|0x2e540452
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.slow_dra_rd_empty */
literal|0x2e540453
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.slow_dra_wr_empty */
literal|0x2e540456
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.slow_ram_rd_empty */
literal|0x2e540459
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.thread_fifo_empty */
literal|0x2e540490
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.pas_if_full */
literal|0x2e5404c2
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.thread_orun_num */
literal|0x2e540505
block|,
literal|0x00010001
block|,
comment|/* cond: ysem.dbg_if_full */
literal|0x2f580080
block|,
literal|0x00010001
block|,
comment|/* cond: psem.PRTY_STS_H_0 */
literal|0x2f580081
block|,
literal|0x00010001
block|,
comment|/* cond: psem.PRTY_MASK_H_0 */
literal|0x2f5802c1
block|,
literal|0x00010001
block|,
comment|/* cond: psem.thread_error */
literal|0x2f5802c2
block|,
literal|0x00010001
block|,
comment|/* cond: psem.thread_rdy */
literal|0x2f5802c4
block|,
literal|0x00010001
block|,
comment|/* cond: psem.thread_valid */
literal|0x2f580440
block|,
literal|0x00010001
block|,
comment|/* cond: psem.dra_empty */
literal|0x2f580450
block|,
literal|0x00010001
block|,
comment|/* cond: psem.slow_dbg_empty */
literal|0x2f580451
block|,
literal|0x00010001
block|,
comment|/* cond: psem.slow_dra_fin_empty */
literal|0x2f580452
block|,
literal|0x00010001
block|,
comment|/* cond: psem.slow_dra_rd_empty */
literal|0x2f580453
block|,
literal|0x00010001
block|,
comment|/* cond: psem.slow_dra_wr_empty */
literal|0x2f580456
block|,
literal|0x00010001
block|,
comment|/* cond: psem.slow_ram_rd_empty */
literal|0x2f580459
block|,
literal|0x00010001
block|,
comment|/* cond: psem.thread_fifo_empty */
literal|0x2f580490
block|,
literal|0x00010001
block|,
comment|/* cond: psem.pas_if_full */
literal|0x2f5804c2
block|,
literal|0x00010001
block|,
comment|/* cond: psem.thread_orun_num */
literal|0x2f580505
block|,
literal|0x00010001
block|,
comment|/* cond: psem.dbg_if_full */
literal|0x2a5c0080
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.PRTY_STS_H_0 */
literal|0x2a5c0081
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.PRTY_MASK_H_0 */
literal|0x2a5c02c1
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.thread_error */
literal|0x2a5c02c2
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.thread_rdy */
literal|0x2a5c02c4
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.thread_valid */
literal|0x2a5c0440
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.dra_empty */
literal|0x2a5c0450
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.slow_dbg_empty */
literal|0x2a5c0451
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.slow_dra_fin_empty */
literal|0x2a5c0452
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.slow_dra_rd_empty */
literal|0x2a5c0453
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.slow_dra_wr_empty */
literal|0x2a5c0456
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.slow_ram_rd_empty */
literal|0x2a5c0459
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.thread_fifo_empty */
literal|0x2a5c0490
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.pas_if_full */
literal|0x2a5c04c2
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.thread_orun_num */
literal|0x2a5c0505
block|,
literal|0x00010001
block|,
comment|/* cond: tsem.dbg_if_full */
literal|0x2b6002c1
block|,
literal|0x00010001
block|,
comment|/* cond: msem.thread_error */
literal|0x2b6002c2
block|,
literal|0x00010001
block|,
comment|/* cond: msem.thread_rdy */
literal|0x2b6002c4
block|,
literal|0x00010001
block|,
comment|/* cond: msem.thread_valid */
literal|0x2b600440
block|,
literal|0x00010001
block|,
comment|/* cond: msem.dra_empty */
literal|0x2b600450
block|,
literal|0x00010001
block|,
comment|/* cond: msem.slow_dbg_empty */
literal|0x2b600451
block|,
literal|0x00010001
block|,
comment|/* cond: msem.slow_dra_fin_empty */
literal|0x2b600452
block|,
literal|0x00010001
block|,
comment|/* cond: msem.slow_dra_rd_empty */
literal|0x2b600453
block|,
literal|0x00010001
block|,
comment|/* cond: msem.slow_dra_wr_empty */
literal|0x2b600456
block|,
literal|0x00010001
block|,
comment|/* cond: msem.slow_ram_rd_empty */
literal|0x2b600459
block|,
literal|0x00010001
block|,
comment|/* cond: msem.thread_fifo_empty */
literal|0x2b600490
block|,
literal|0x00010001
block|,
comment|/* cond: msem.pas_if_full */
literal|0x2b6004c2
block|,
literal|0x00010001
block|,
comment|/* cond: msem.thread_orun_num */
literal|0x2b600505
block|,
literal|0x00010001
block|,
comment|/* cond: msem.dbg_if_full */
literal|0x2c640080
block|,
literal|0x00010001
block|,
comment|/* cond: usem.PRTY_STS_H_0 */
literal|0x2c640081
block|,
literal|0x00010001
block|,
comment|/* cond: usem.PRTY_MASK_H_0 */
literal|0x2c6402c1
block|,
literal|0x00010001
block|,
comment|/* cond: usem.thread_error */
literal|0x2c6402c2
block|,
literal|0x00010001
block|,
comment|/* cond: usem.thread_rdy */
literal|0x2c6402c4
block|,
literal|0x00010001
block|,
comment|/* cond: usem.thread_valid */
literal|0x2c640440
block|,
literal|0x00010001
block|,
comment|/* cond: usem.dra_empty */
literal|0x2c640450
block|,
literal|0x00010001
block|,
comment|/* cond: usem.slow_dbg_empty */
literal|0x2c640451
block|,
literal|0x00010001
block|,
comment|/* cond: usem.slow_dra_fin_empty */
literal|0x2c640452
block|,
literal|0x00010001
block|,
comment|/* cond: usem.slow_dra_rd_empty */
literal|0x2c640453
block|,
literal|0x00010001
block|,
comment|/* cond: usem.slow_dra_wr_empty */
literal|0x2c640456
block|,
literal|0x00010001
block|,
comment|/* cond: usem.slow_ram_rd_empty */
literal|0x2c640459
block|,
literal|0x00010001
block|,
comment|/* cond: usem.thread_fifo_empty */
literal|0x2c640490
block|,
literal|0x00010001
block|,
comment|/* cond: usem.pas_if_full */
literal|0x2c6404c2
block|,
literal|0x00010001
block|,
comment|/* cond: usem.thread_orun_num */
literal|0x2c640505
block|,
literal|0x00010001
block|,
comment|/* cond: usem.dbg_if_full */
literal|0x0c014810
block|,
literal|0x00010001
block|,
comment|/* cond: mcp2.PRTY_STS */
literal|0x0c014811
block|,
literal|0x00010001
block|,
comment|/* cond: mcp2.PRTY_MASK */
literal|0x0c014881
block|,
literal|0x00010001
block|,
comment|/* cond: mcp2.PRTY_STS_H_0 */
literal|0x0c014882
block|,
literal|0x00010001
block|,
comment|/* cond: mcp2.PRTY_MASK_H_0 */
literal|0x07010000
block|,
literal|0x00010001
block|,
comment|/* cond: ncsi.PRTY_STS_H_0 */
literal|0x07010001
block|,
literal|0x00010001
block|,
comment|/* cond: ncsi.PRTY_MASK_H_0 */
literal|0x48014460
block|,
literal|0x00010001
block|,
comment|/* cond: umac.INT_STS */
literal|0x48014460
block|,
literal|0x00010001
block|,
comment|/* cond: umac.INT_STS */
literal|0x501c8180
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_err_ctrl0 */
literal|0x501c8181
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_err_ctrl1 */
literal|0x501c8182
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_err_ctrl2 */
literal|0x501c8188
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_regbus_err_info_status0 */
literal|0x501c8188
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_regbus_err_info_status0 */
literal|0x501c8188
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_regbus_err_info_status0 */
literal|0x501c8188
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_regbus_err_info_status0 */
literal|0x501c8189
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_regbus_err_info_status1 */
literal|0x501c818a
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_regbus_err_info_status2 */
literal|0x501c818b
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.phy0_top_regbus_err_info_status3 */
literal|0x501c8852
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.cmu_lc0_top_phy_if_status */
literal|0x501c8880
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.cmu_lc0_top_err_ctrl1 */
literal|0x501c8881
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.cmu_lc0_top_err_ctrl2 */
literal|0x501c8882
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.cmu_lc0_top_err_ctrl3 */
literal|0x501c8c52
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.cmu_r0_top_phy_if_status */
literal|0x501c8c80
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.cmu_r0_top_err_ctrl1 */
literal|0x501c8c81
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.cmu_r0_top_err_ctrl2 */
literal|0x501c8c82
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.cmu_r0_top_err_ctrl3 */
literal|0x501c9850
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln0_top_err_ctrl1 */
literal|0x501c9851
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln0_top_err_ctrl2 */
literal|0x501c9852
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln0_top_err_ctrl3 */
literal|0x501ca050
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln1_top_err_ctrl1 */
literal|0x501ca051
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln1_top_err_ctrl2 */
literal|0x501ca052
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln1_top_err_ctrl3 */
literal|0x501ca850
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln2_top_err_ctrl1 */
literal|0x501ca851
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln2_top_err_ctrl2 */
literal|0x501ca852
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln2_top_err_ctrl3 */
literal|0x501cb050
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln3_top_err_ctrl1 */
literal|0x501cb051
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln3_top_err_ctrl2 */
literal|0x501cb052
block|,
literal|0x00010001
block|,
comment|/* cond: nws.nws_cmu.ln3_top_err_ctrl3 */
literal|0x4e008147
block|,
literal|0x00010001
block|,
comment|/* cond: ipc.PRTY_STS */
literal|0x4e008148
block|,
literal|0x00010001
block|,
comment|/* cond: ipc.PRTY_MASK */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 13904 bytes */
end_comment

begin_comment
comment|/* Idle check immediates */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|idle_chk_imms
index|[]
init|=
block|{
literal|0x00000000
block|,
literal|0x000000b0
block|,
literal|0x00000000
block|,
literal|0x0000000f
block|,
literal|0x00000000
block|,
literal|0x34000000
block|,
literal|0x00000000
block|,
literal|0x00000060
block|,
literal|0x00000000
block|,
literal|0x00000005
block|,
literal|0x00000010
block|,
literal|0x00000002
block|,
literal|0x00000000
block|,
literal|0x00000001
block|,
literal|0x00000000
block|,
literal|0x00000020
block|,
literal|0x000000b7
block|,
literal|0x00000004
block|,
literal|0x00000008
block|,
literal|0x00000003
block|,
literal|0x00022aab
block|,
literal|0x0000eaaa
block|,
literal|0x0001bc01
block|,
literal|0x00000000
block|,
literal|0x0076417c
block|,
literal|0x00000000
block|,
literal|0x00000011
block|,
literal|0x00000001
block|,
literal|0x00000000
block|,
literal|0xffffffff
block|,
literal|0x007fffff
block|,
literal|0x80000000
block|,
literal|0x7f800000
block|,
literal|0x0000041e
block|,
literal|0x00000030
block|,
literal|0x000000ff
block|,
literal|0x000fffff
block|,
literal|0x0000ffff
block|,
literal|0x000000ff
block|,
literal|0x00000000
block|,
literal|0x00000007
block|,
literal|0x00000000
block|,
literal|0x00001ffe
block|,
literal|0x0000002e
block|,
literal|0x000001ff
block|,
literal|0x00000040
block|,
literal|0x00000028
block|,
literal|0x0000002a
block|,
literal|0x00000034
block|,
literal|0x0000001d
block|,
literal|0x0000003f
block|,
literal|0x0000000a
block|,
literal|0x0000000e
block|,
literal|0x0000001a
block|,
literal|0x00000026
block|,
literal|0x00000017
block|,
literal|0x0000002c
block|,
literal|0x0000003c
block|,
literal|0x00000032
block|,
literal|0x00003f02
block|,
literal|0x00000000
block|,
literal|0x3fffffc0
block|,
literal|0x00000006
block|,
literal|0xc0000000
block|,
literal|0x0000001e
block|,
literal|0x003fffff
block|,
literal|0x00000002
block|,
literal|0x00000030
block|,
literal|0x00000004
block|,
literal|0x00000003
block|,
literal|0x000003e1
block|,
literal|0x00000381
block|,
literal|0x00002000
block|,
literal|0x00000000
block|,
literal|0x000fd010
block|,
literal|0x00000000
block|,
literal|0x00100000
block|,
literal|0x00000000
block|,
literal|0x0000e001
block|,
literal|0x00000000
block|,
literal|0x00000004
block|,
literal|0x00000004
block|,
literal|0x00000002
block|,
literal|0x00000002
block|,
literal|0x00000001
block|,
literal|0x0000000e
block|,
literal|0x00000001
block|,
literal|0x00000001
block|,
literal|0x00000001
block|,
literal|0x0000000f
block|,
literal|0x00000001
block|,
literal|0x00000001
block|,
literal|0x00000001
block|,
literal|0x00000010
block|,
literal|0x00000001
block|,
literal|0x00000001
block|,
literal|0x00000001
block|,
literal|0x00000011
block|,
literal|0x00000001
block|,
literal|0x00000001
block|,
literal|0x000001fe
block|,
literal|0x00000000
block|,
literal|0x02000000
block|,
literal|0x00000000
block|,
literal|0x02040902
block|,
literal|0x00000000
block|,
literal|0x10240902
block|,
literal|0x00000000
block|,
literal|0x0000001f
block|,
literal|0x00000004
block|,
literal|0x00000000
block|,  }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 444 bytes */
end_comment

begin_comment
comment|/* Idle check rules */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|idle_chk_rules
index|[]
init|=
block|{
literal|0x0bb80000
block|,
comment|/* mode all */
literal|0x00000000
block|,
literal|0x00010002
block|,
literal|0x00000000
block|,
comment|/* ((r1&~r2)!=0), r1=misc.INT_STS, r2=misc.INT_MASK,  */
literal|0x01000001
block|,
literal|0x00010101
block|,
literal|0x00000002
block|,
comment|/* (r1!=0), r1=misc.aeu_after_invert_1_igu,  */
literal|0x04000002
block|,
literal|0x00020101
block|,
literal|0x00010004
block|,
comment|/* ((r1&~0xB0)!=0), r1=misc.aeu_after_invert_2_igu,  */
literal|0x04000003
block|,
literal|0x00020101
block|,
literal|0x00030006
block|,
comment|/* ((r1&~0xF)!=0), r1=misc.aeu_after_invert_4_igu,  */
literal|0x01000004
block|,
literal|0x00010101
block|,
literal|0x00000008
block|,
comment|/* (r1!=0), r1=misc.aeu_after_invert_5_igu,  */
literal|0x01000005
block|,
literal|0x00010101
block|,
literal|0x0000000a
block|,
comment|/* (r1!=0), r1=misc.aeu_after_invert_6_igu,  */
literal|0x01000006
block|,
literal|0x00010101
block|,
literal|0x0000000c
block|,
comment|/* (r1!=0), r1=misc.aeu_after_invert_7_igu,  */
literal|0x04000007
block|,
literal|0x00020101
block|,
literal|0x0005000e
block|,
comment|/* ((r1&~0x34000000)!=0), r1=misc.aeu_after_invert_8_igu,  */
literal|0x04000008
block|,
literal|0x00020101
block|,
literal|0x00070010
block|,
comment|/* ((r1&~0x60)!=0), r1=misc.aeu_after_invert_9_igu,  */
literal|0x01000009
block|,
literal|0x00010101
block|,
literal|0x00000012
block|,
comment|/* (r1!=0), r1=misc.aeu_after_invert_1_mcp,  */
literal|0x0400000a
block|,
literal|0x00020101
block|,
literal|0x00010014
block|,
comment|/* ((r1&~0xB0)!=0), r1=misc.aeu_after_invert_2_mcp,  */
literal|0x0400000b
block|,
literal|0x00020101
block|,
literal|0x00030016
block|,
comment|/* ((r1&~0xF)!=0), r1=misc.aeu_after_invert_4_mcp,  */
literal|0x0100000c
block|,
literal|0x00010101
block|,
literal|0x00000018
block|,
comment|/* (r1!=0), r1=misc.aeu_after_invert_5_mcp,  */
literal|0x0100000d
block|,
literal|0x00010101
block|,
literal|0x0000001a
block|,
comment|/* (r1!=0), r1=misc.aeu_after_invert_6_mcp,  */
literal|0x0100000e
block|,
literal|0x00010101
block|,
literal|0x0000001c
block|,
comment|/* (r1!=0), r1=misc.aeu_after_invert_7_mcp,  */
literal|0x0400000f
block|,
literal|0x00020101
block|,
literal|0x0005001e
block|,
comment|/* ((r1&~0x34000000)!=0), r1=misc.aeu_after_invert_8_mcp,  */
literal|0x04000010
block|,
literal|0x00020101
block|,
literal|0x00070020
block|,
comment|/* ((r1&~0x60)!=0), r1=misc.aeu_after_invert_9_mcp,  */
literal|0x01000011
block|,
literal|0x00010001
block|,
literal|0x00000022
block|,
comment|/* (r1!=0), r1=misc.aeu_sys_kill_occurred,  */
literal|0x00000012
block|,
literal|0x00010002
block|,
literal|0x00000023
block|,
comment|/* ((r1&~r2)!=0), r1=miscs.INT_STS_0, r2=miscs.INT_MASK_0,  */
literal|0x01020013
block|,
literal|0x00010001
block|,
literal|0x00000025
block|,
comment|/* (r1!=0), r1=miscs.pcie_hot_reset,  */
literal|0x01010014
block|,
literal|0x00010001
block|,
literal|0x00000026
block|,
comment|/* (r1!=0), r1=dmae.go_c0,  */
literal|0x01010015
block|,
literal|0x00010001
block|,
literal|0x00000027
block|,
comment|/* (r1!=0), r1=dmae.go_c1,  */
literal|0x01010016
block|,
literal|0x00010001
block|,
literal|0x00000028
block|,
comment|/* (r1!=0), r1=dmae.go_c2,  */
literal|0x01010017
block|,
literal|0x00010001
block|,
literal|0x00000029
block|,
comment|/* (r1!=0), r1=dmae.go_c3,  */
literal|0x01010018
block|,
literal|0x00010001
block|,
literal|0x0000002a
block|,
comment|/* (r1!=0), r1=dmae.go_c4,  */
literal|0x01010019
block|,
literal|0x00010001
block|,
literal|0x0000002b
block|,
comment|/* (r1!=0), r1=dmae.go_c5,  */
literal|0x0101001a
block|,
literal|0x00010001
block|,
literal|0x0000002c
block|,
comment|/* (r1!=0), r1=dmae.go_c6,  */
literal|0x0101001b
block|,
literal|0x00010001
block|,
literal|0x0000002d
block|,
comment|/* (r1!=0), r1=dmae.go_c7,  */
literal|0x0101001c
block|,
literal|0x00010001
block|,
literal|0x0000002e
block|,
comment|/* (r1!=0), r1=dmae.go_c8,  */
literal|0x0101001d
block|,
literal|0x00010001
block|,
literal|0x0000002f
block|,
comment|/* (r1!=0), r1=dmae.go_c9,  */
literal|0x0101001e
block|,
literal|0x00010001
block|,
literal|0x00000030
block|,
comment|/* (r1!=0), r1=dmae.go_c10,  */
literal|0x0101001f
block|,
literal|0x00010001
block|,
literal|0x00000031
block|,
comment|/* (r1!=0), r1=dmae.go_c11,  */
literal|0x01010020
block|,
literal|0x00010001
block|,
literal|0x00000032
block|,
comment|/* (r1!=0), r1=dmae.go_c12,  */
literal|0x01010021
block|,
literal|0x00010001
block|,
literal|0x00000033
block|,
comment|/* (r1!=0), r1=dmae.go_c13,  */
literal|0x01010022
block|,
literal|0x00010001
block|,
literal|0x00000034
block|,
comment|/* (r1!=0), r1=dmae.go_c14,  */
literal|0x01010023
block|,
literal|0x00010001
block|,
literal|0x00000035
block|,
comment|/* (r1!=0), r1=dmae.go_c15,  */
literal|0x01010024
block|,
literal|0x00010001
block|,
literal|0x00000036
block|,
comment|/* (r1!=0), r1=dmae.go_c16,  */
literal|0x01010025
block|,
literal|0x00010001
block|,
literal|0x00000037
block|,
comment|/* (r1!=0), r1=dmae.go_c17,  */
literal|0x01010026
block|,
literal|0x00010001
block|,
literal|0x00000038
block|,
comment|/* (r1!=0), r1=dmae.go_c18,  */
literal|0x01010027
block|,
literal|0x00010001
block|,
literal|0x00000039
block|,
comment|/* (r1!=0), r1=dmae.go_c19,  */
literal|0x01010028
block|,
literal|0x00010001
block|,
literal|0x0000003a
block|,
comment|/* (r1!=0), r1=dmae.go_c20,  */
literal|0x01010029
block|,
literal|0x00010001
block|,
literal|0x0000003b
block|,
comment|/* (r1!=0), r1=dmae.go_c21,  */
literal|0x0101002a
block|,
literal|0x00010001
block|,
literal|0x0000003c
block|,
comment|/* (r1!=0), r1=dmae.go_c22,  */
literal|0x0101002b
block|,
literal|0x00010001
block|,
literal|0x0000003d
block|,
comment|/* (r1!=0), r1=dmae.go_c23,  */
literal|0x0101002c
block|,
literal|0x00010001
block|,
literal|0x0000003e
block|,
comment|/* (r1!=0), r1=dmae.go_c24,  */
literal|0x0101002d
block|,
literal|0x00010001
block|,
literal|0x0000003f
block|,
comment|/* (r1!=0), r1=dmae.go_c25,  */
literal|0x0101002e
block|,
literal|0x00010001
block|,
literal|0x00000040
block|,
comment|/* (r1!=0), r1=dmae.go_c26,  */
literal|0x0101002f
block|,
literal|0x00010001
block|,
literal|0x00000041
block|,
comment|/* (r1!=0), r1=dmae.go_c27,  */
literal|0x01010030
block|,
literal|0x00010001
block|,
literal|0x00000042
block|,
comment|/* (r1!=0), r1=dmae.go_c28,  */
literal|0x01010031
block|,
literal|0x00010001
block|,
literal|0x00000043
block|,
comment|/* (r1!=0), r1=dmae.go_c29,  */
literal|0x01010032
block|,
literal|0x00010001
block|,
literal|0x00000044
block|,
comment|/* (r1!=0), r1=dmae.go_c30,  */
literal|0x01010033
block|,
literal|0x00010001
block|,
literal|0x00000045
block|,
comment|/* (r1!=0), r1=dmae.go_c31,  */
literal|0x00000034
block|,
literal|0x00010002
block|,
literal|0x00000046
block|,
comment|/* ((r1&~r2)!=0), r1=dmae.PRTY_STS_H_0, r2=dmae.PRTY_MASK_H_0,  */
literal|0x00000035
block|,
literal|0x00010002
block|,
literal|0x00000048
block|,
comment|/* ((r1&~r2)!=0), r1=dbg.PRTY_STS_H_0, r2=dbg.PRTY_MASK_H_0,  */
literal|0x01020036
block|,
literal|0x00010001
block|,
literal|0x0000004a
block|,
comment|/* (r1!=0), r1=grc.trace_fifo_valid_data,  */
literal|0x00000037
block|,
literal|0x00010002
block|,
literal|0x0000004b
block|,
comment|/* ((r1&~r2)!=0), r1=grc.INT_STS_0, r2=grc.INT_MASK_0,  */
literal|0x00000038
block|,
literal|0x00010002
block|,
literal|0x0000004d
block|,
comment|/* ((r1&~r2)!=0), r1=grc.PRTY_STS_H_0, r2=grc.PRTY_MASK_H_0,  */
literal|0x00000039
block|,
literal|0x00010002
block|,
literal|0x0000004f
block|,
comment|/* ((r1&~r2)!=0), r1=dorq.INT_STS, r2=dorq.INT_MASK,  */
literal|0x0000003a
block|,
literal|0x00010002
block|,
literal|0x00000051
block|,
comment|/* ((r1&~r2)!=0), r1=dorq.PRTY_STS_H_0, r2=dorq.PRTY_MASK_H_0,  */
literal|0x0100003b
block|,
literal|0x00010001
block|,
literal|0x00090053
block|,
comment|/* (r1!=reset1), r1=dorq.xcm_msg_init_crd,  */
literal|0x0100003c
block|,
literal|0x00010001
block|,
literal|0x00090054
block|,
comment|/* (r1!=reset1), r1=dorq.tcm_msg_init_crd,  */
literal|0x0100003d
block|,
literal|0x00010001
block|,
literal|0x00090055
block|,
comment|/* (r1!=reset1), r1=dorq.ucm_msg_init_crd,  */
literal|0x0100003e
block|,
literal|0x00010001
block|,
literal|0x000a0056
block|,
comment|/* (r1!=reset1), r1=dorq.pbf_cmd_init_crd,  */
literal|0x0100003f
block|,
literal|0x00010001
block|,
literal|0x00000057
block|,
comment|/* (r1!=0), r1=dorq.pf_usage_cnt,  */
literal|0x01000040
block|,
literal|0x00010001
block|,
literal|0x00000058
block|,
comment|/* (r1!=0), r1=dorq.vf_usage_cnt,  */
literal|0x01000041
block|,
literal|0x00010001
block|,
literal|0x00000059
block|,
comment|/* (r1!=0), r1=dorq.cfc_ld_req_fifo_fill_lvl,  */
literal|0x01000042
block|,
literal|0x00010001
block|,
literal|0x0000005a
block|,
comment|/* (r1!=0), r1=dorq.dorq_fifo_fill_lvl,  */
literal|0x01020043
block|,
literal|0x00010201
block|,
literal|0x0000005b
block|,
comment|/* (r1!=0), r1=dorq.db_drop_cnt,  */
literal|0x01020044
block|,
literal|0x00010201
block|,
literal|0x0000005e
block|,
comment|/* (r1!=0), r1=dorq.dpm_abort_cnt,  */
literal|0x01000045
block|,
literal|0x00010001
block|,
literal|0x00000061
block|,
comment|/* (r1!=0), r1=dorq.dpm_tbl_fill_lvl,  */
literal|0x00000046
block|,
literal|0x00010002
block|,
literal|0x00000062
block|,
comment|/* ((r1&~r2)!=0), r1=igu.PRTY_STS, r2=igu.PRTY_MASK,  */
literal|0x00000047
block|,
literal|0x00010002
block|,
literal|0x00000064
block|,
comment|/* ((r1&~r2)!=0), r1=igu.PRTY_STS_H_0, r2=igu.PRTY_MASK_H_0,  */
literal|0x01010048
block|,
literal|0x00010001
block|,
literal|0x00000066
block|,
comment|/* (r1!=0), r1=igu.attn_write_done_pending,  */
literal|0x01020049
block|,
literal|0x00010001
block|,
literal|0x00000067
block|,
comment|/* (r1!=0), r1=igu.Interrupt_status,  */
literal|0x0100004a
block|,
literal|0x00010001
block|,
literal|0x00000068
block|,
comment|/* (r1!=0), r1=igu.error_handling_data_valid,  */
literal|0x0100004b
block|,
literal|0x00010001
block|,
literal|0x00000069
block|,
comment|/* (r1!=0), r1=igu.silent_drop,  */
literal|0x0102004c
block|,
literal|0x00010001
block|,
literal|0x0000006a
block|,
comment|/* (r1!=0), r1=igu.sb_ctrl_fsm,  */
literal|0x0102004d
block|,
literal|0x00010001
block|,
literal|0x0000006b
block|,
comment|/* (r1!=0), r1=igu.int_handle_fsm,  */
literal|0x0402004e
block|,
literal|0x00020001
block|,
literal|0x000b006c
block|,
comment|/* ((r1&~0x2)!=0), r1=igu.attn_fsm,  */
literal|0x0402004f
block|,
literal|0x00020001
block|,
literal|0x000d006d
block|,
comment|/* ((r1&~0x1)!=0), r1=igu.ctrl_fsm,  */
literal|0x04020050
block|,
literal|0x00020001
block|,
literal|0x000d006e
block|,
comment|/* ((r1&~0x1)!=0), r1=igu.pxp_arb_fsm,  */
literal|0x00000051
block|,
literal|0x00010002
block|,
literal|0x0000006f
block|,
comment|/* ((r1&~r2)!=0), r1=cau.PRTY_STS_H_0, r2=cau.PRTY_MASK_H_0,  */
literal|0x01010052
block|,
literal|0x00010001
block|,
literal|0x000d0071
block|,
comment|/* (r1!=1), r1=cau.igu_req_credit_status,  */
literal|0x01010053
block|,
literal|0x00010001
block|,
literal|0x000d0072
block|,
comment|/* (r1!=1), r1=cau.igu_cmd_credit_status,  */
literal|0x01010054
block|,
literal|0x00010001
block|,
literal|0x00000073
block|,
comment|/* (r1!=0), r1=cau.debug_fifo_status,  */
literal|0x01000055
block|,
literal|0x00010001
block|,
literal|0x00000074
block|,
comment|/* (r1!=0), r1=cau.error_pxp_req,  */
literal|0x01000056
block|,
literal|0x00010101
block|,
literal|0x00000075
block|,
comment|/* (r1!=0), r1=cau.error_fsm_line,  */
literal|0x01000057
block|,
literal|0x00010001
block|,
literal|0x00000077
block|,
comment|/* (r1!=0), r1=cau.parity_latch_status,  */
literal|0x01000058
block|,
literal|0x00010001
block|,
literal|0x00000078
block|,
comment|/* (r1!=0), r1=cau.error_cleanup_cmd_reg,  */
literal|0x03010059
block|,
literal|0x00000002
block|,
literal|0x00000079
block|,
comment|/* (r1!=r2), r1=cau.req_counter, r2=cau.ack_counter,  */
literal|0x0301005a
block|,
literal|0x00000002
block|,
literal|0x0000007b
block|,
comment|/* (r1!=r2), r1=cau.req_counter, r2=cau.wdone_counter,  */
literal|0x0102005b
block|,
literal|0x00010001
block|,
literal|0x0000007d
block|,
comment|/* (r1!=0), r1=cau.main_fsm_status,  */
literal|0x0102005c
block|,
literal|0x00010001
block|,
literal|0x0000007e
block|,
comment|/* (r1!=0), r1=cau.var_read_fsm_status,  */
literal|0x0102005d
block|,
literal|0x00010001
block|,
literal|0x0000007f
block|,
comment|/* (r1!=0), r1=cau.igu_dma_fsm_status,  */
literal|0x0000005e
block|,
literal|0x00010302
block|,
literal|0x00000080
block|,
comment|/* ((r1&~r2)!=0), r1=prs.INT_STS_0, r2=prs.INT_MASK_0,  */
literal|0x0000005f
block|,
literal|0x00010002
block|,
literal|0x00000085
block|,
comment|/* ((r1&~r2)!=0), r1=prs.PRTY_STS, r2=prs.PRTY_MASK,  */
literal|0x00000060
block|,
literal|0x00010002
block|,
literal|0x00000087
block|,
comment|/* ((r1&~r2)!=0), r1=prs.PRTY_STS_H_0, r2=prs.PRTY_MASK_H_0,  */
literal|0x01010061
block|,
literal|0x00010001
block|,
literal|0x00000089
block|,
comment|/* (r1!=0), r1=prs.queue_pkt_avail_status,  */
literal|0x01010062
block|,
literal|0x00010001
block|,
literal|0x0000008a
block|,
comment|/* (r1!=0), r1=prs.storm_bkprs_status,  */
literal|0x01010063
block|,
literal|0x00010001
block|,
literal|0x0000008b
block|,
comment|/* (r1!=0), r1=prs.stop_parsing_status,  */
literal|0x01010064
block|,
literal|0x00010001
block|,
literal|0x0000008c
block|,
comment|/* (r1!=0), r1=prs.ccfc_search_current_credit,  */
literal|0x01010065
block|,
literal|0x00010001
block|,
literal|0x0000008d
block|,
comment|/* (r1!=0), r1=prs.tcfc_search_current_credit,  */
literal|0x01010066
block|,
literal|0x00010001
block|,
literal|0x0000008e
block|,
comment|/* (r1!=0), r1=prs.ccfc_load_current_credit,  */
literal|0x01010067
block|,
literal|0x00010001
block|,
literal|0x0000008f
block|,
comment|/* (r1!=0), r1=prs.tcfc_load_current_credit,  */
literal|0x01010068
block|,
literal|0x00010001
block|,
literal|0x00000090
block|,
comment|/* (r1!=0), r1=prs.ccfc_search_req_ct,  */
literal|0x01010069
block|,
literal|0x00010001
block|,
literal|0x00000091
block|,
comment|/* (r1!=0), r1=prs.tcfc_search_req_ct,  */
literal|0x0101006a
block|,
literal|0x00010001
block|,
literal|0x00000092
block|,
comment|/* (r1!=0), r1=prs.ccfc_load_req_ct,  */
literal|0x0101006b
block|,
literal|0x00010001
block|,
literal|0x00000093
block|,
comment|/* (r1!=0), r1=prs.tcfc_load_req_ct,  */
literal|0x0101006c
block|,
literal|0x00010001
block|,
literal|0x00000094
block|,
comment|/* (r1!=0), r1=prs.sop_req_ct,  */
literal|0x0101006d
block|,
literal|0x00010001
block|,
literal|0x00000095
block|,
comment|/* (r1!=0), r1=prs.eop_req_ct,  */
literal|0x0000006e
block|,
literal|0x00010002
block|,
literal|0x00000096
block|,
comment|/* ((r1&~r2)!=0), r1=prm.INT_STS, r2=prm.INT_MASK,  */
literal|0x0000006f
block|,
literal|0x00010002
block|,
literal|0x00000098
block|,
comment|/* ((r1&~r2)!=0), r1=prm.PRTY_STS_H_0, r2=prm.PRTY_MASK_H_0,  */
literal|0x01000070
block|,
literal|0x00010001
block|,
literal|0x000d009a
block|,
comment|/* (r1!=1), r1=rss.rss_init_done,  */
literal|0x00000071
block|,
literal|0x00010002
block|,
literal|0x0000009b
block|,
comment|/* ((r1&~r2)!=0), r1=rss.INT_STS, r2=rss.INT_MASK,  */
literal|0x00000072
block|,
literal|0x00010002
block|,
literal|0x0000009d
block|,
comment|/* ((r1&~r2)!=0), r1=rss.PRTY_STS_H_0, r2=rss.PRTY_MASK_H_0,  */
literal|0x01010073
block|,
literal|0x00010001
block|,
literal|0x000f009f
block|,
comment|/* (r1!=0x20), r1=rss.tmld_credit,  */
literal|0x01000074
block|,
literal|0x00010001
block|,
literal|0x000d00a0
block|,
comment|/* (r1!=1), r1=pswrq2.rbc_done,  */
literal|0x01000075
block|,
literal|0x00010001
block|,
literal|0x000d00a1
block|,
comment|/* (r1!=1), r1=pswrq2.cfg_done,  */
literal|0x00020076
block|,
literal|0x00010002
block|,
literal|0x000000a2
block|,
comment|/* ((r1&~r2)!=0), r1=pswrq2.INT_STS, r2=pswrq2.INT_MASK,  */
literal|0x00000077
block|,
literal|0x00010002
block|,
literal|0x000000a4
block|,
comment|/* ((r1&~r2)!=0), r1=pswrq2.PRTY_STS_H_0, r2=pswrq2.PRTY_MASK_H_0,  */
literal|0x01010078
block|,
literal|0x00010001
block|,
literal|0x000000a6
block|,
comment|/* (r1!=0), r1=pswrq2.vq0_entry_cnt[0:31],  */
literal|0x01000079
block|,
literal|0x00010001
block|,
literal|0x001000a7
block|,
comment|/* (r1!=0xb7), r1=pswrq2.BW_CREDIT,  */
literal|0x0101007a
block|,
literal|0x00010001
block|,
literal|0x000000a8
block|,
comment|/* (r1!=0), r1=pswrq2.treq_fifo_fill_lvl,  */
literal|0x0101007b
block|,
literal|0x00010001
block|,
literal|0x000000a9
block|,
comment|/* (r1!=0), r1=pswrq2.icpl_fifo_fill_lvl,  */
literal|0x0100007c
block|,
literal|0x00010001
block|,
literal|0x000000aa
block|,
comment|/* (r1!=0), r1=pswrq2.l2p_err_add_31_0,  */
literal|0x0100007d
block|,
literal|0x00010001
block|,
literal|0x000000ab
block|,
comment|/* (r1!=0), r1=pswrq2.l2p_err_add_63_32,  */
literal|0x0100007e
block|,
literal|0x00010001
block|,
literal|0x000000ac
block|,
comment|/* (r1!=0), r1=pswrq2.l2p_err_details,  */
literal|0x0100007f
block|,
literal|0x00010001
block|,
literal|0x000000ad
block|,
comment|/* (r1!=0), r1=pswrq2.l2p_err_details2,  */
literal|0x08010080
block|,
literal|0x00010002
block|,
literal|0x001100ae
block|,
comment|/* (r1<(r2-4)), r1=pswrq2.sr_cnt, r2=pswrq2.sr_num_cfg,  */
literal|0x03010081
block|,
literal|0x00000002
block|,
literal|0x000000b0
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt, r2=pswrq2.sr_num_cfg,  */
literal|0x03010082
block|,
literal|0x00000002
block|,
literal|0x000000b2
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_0, r2=pswrq2.max_srs_vq0,  */
literal|0x03010083
block|,
literal|0x00000002
block|,
literal|0x000000b4
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_1, r2=pswrq2.max_srs_vq1,  */
literal|0x03010084
block|,
literal|0x00000002
block|,
literal|0x000000b6
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_2, r2=pswrq2.max_srs_vq2,  */
literal|0x03010085
block|,
literal|0x00000002
block|,
literal|0x000000b8
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_3, r2=pswrq2.max_srs_vq3,  */
literal|0x03010086
block|,
literal|0x00000002
block|,
literal|0x000000ba
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_4, r2=pswrq2.max_srs_vq4,  */
literal|0x03010087
block|,
literal|0x00000002
block|,
literal|0x000000bc
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_5, r2=pswrq2.max_srs_vq5,  */
literal|0x03010088
block|,
literal|0x00000002
block|,
literal|0x000000be
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_6, r2=pswrq2.max_srs_vq6,  */
literal|0x03010089
block|,
literal|0x00000002
block|,
literal|0x000000c0
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_9, r2=pswrq2.max_srs_vq9,  */
literal|0x0301008a
block|,
literal|0x00000002
block|,
literal|0x000000c2
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_11, r2=pswrq2.max_srs_vq11,  */
literal|0x0301008b
block|,
literal|0x00000002
block|,
literal|0x000000c4
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_12, r2=pswrq2.max_srs_vq12,  */
literal|0x0301008c
block|,
literal|0x00000002
block|,
literal|0x000000c6
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_15, r2=pswrq2.max_srs_vq15,  */
literal|0x0301008d
block|,
literal|0x00000002
block|,
literal|0x000000c8
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_16, r2=pswrq2.max_srs_vq16,  */
literal|0x0301008e
block|,
literal|0x00000002
block|,
literal|0x000000ca
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_17, r2=pswrq2.max_srs_vq17,  */
literal|0x0301008f
block|,
literal|0x00000002
block|,
literal|0x000000cc
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_18, r2=pswrq2.max_srs_vq18,  */
literal|0x03010090
block|,
literal|0x00000002
block|,
literal|0x000000ce
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_19, r2=pswrq2.max_srs_vq19,  */
literal|0x03010091
block|,
literal|0x00000002
block|,
literal|0x000000d0
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_21, r2=pswrq2.max_srs_vq21,  */
literal|0x03010092
block|,
literal|0x00000002
block|,
literal|0x000000d2
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_22, r2=pswrq2.max_srs_vq22,  */
literal|0x03010093
block|,
literal|0x00000002
block|,
literal|0x000000d4
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_23, r2=pswrq2.max_srs_vq23,  */
literal|0x03010094
block|,
literal|0x00000002
block|,
literal|0x000000d6
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_24, r2=pswrq2.max_srs_vq24,  */
literal|0x03010095
block|,
literal|0x00000002
block|,
literal|0x000000d8
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_26, r2=pswrq2.max_srs_vq26,  */
literal|0x03010096
block|,
literal|0x00000002
block|,
literal|0x000000da
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_28, r2=pswrq2.max_srs_vq28,  */
literal|0x03010097
block|,
literal|0x00000002
block|,
literal|0x000000dc
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_29, r2=pswrq2.max_srs_vq29,  */
literal|0x03010098
block|,
literal|0x00000002
block|,
literal|0x000000de
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_30, r2=pswrq2.max_srs_vq30,  */
literal|0x08010099
block|,
literal|0x00010002
block|,
literal|0x001200e0
block|,
comment|/* (r1<(r2-8)), r1=pswrq2.blk_cnt, r2=pswrq2.blk_num_cfg,  */
literal|0x0301009a
block|,
literal|0x00000002
block|,
literal|0x000000e2
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt, r2=pswrq2.blk_num_cfg,  */
literal|0x0301009b
block|,
literal|0x00000002
block|,
literal|0x000000e4
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_0, r2=pswrq2.max_blks_vq0,  */
literal|0x0301009c
block|,
literal|0x00000002
block|,
literal|0x000000e6
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_1, r2=pswrq2.max_blks_vq1,  */
literal|0x0301009d
block|,
literal|0x00000002
block|,
literal|0x000000e8
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_2, r2=pswrq2.max_blks_vq2,  */
literal|0x0301009e
block|,
literal|0x00000002
block|,
literal|0x000000ea
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_3, r2=pswrq2.max_blks_vq3,  */
literal|0x0301009f
block|,
literal|0x00000002
block|,
literal|0x000000ec
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_4, r2=pswrq2.max_blks_vq4,  */
literal|0x030100a0
block|,
literal|0x00000002
block|,
literal|0x000000ee
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_5, r2=pswrq2.max_blks_vq5,  */
literal|0x030100a1
block|,
literal|0x00000002
block|,
literal|0x000000f0
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_6, r2=pswrq2.max_blks_vq6,  */
literal|0x030100a2
block|,
literal|0x00000002
block|,
literal|0x000000f2
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_9, r2=pswrq2.max_blks_vq9,  */
literal|0x030100a3
block|,
literal|0x00000002
block|,
literal|0x000000f4
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_11, r2=pswrq2.max_blks_vq11,  */
literal|0x030100a4
block|,
literal|0x00000002
block|,
literal|0x000000f6
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_12, r2=pswrq2.max_blks_vq12,  */
literal|0x030100a5
block|,
literal|0x00000002
block|,
literal|0x000000f8
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_15, r2=pswrq2.max_blks_vq15,  */
literal|0x030100a6
block|,
literal|0x00000002
block|,
literal|0x000000fa
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_16, r2=pswrq2.max_blks_vq16,  */
literal|0x030100a7
block|,
literal|0x00000002
block|,
literal|0x000000fc
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_17, r2=pswrq2.max_blks_vq17,  */
literal|0x030100a8
block|,
literal|0x00000002
block|,
literal|0x000000fe
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_18, r2=pswrq2.max_blks_vq18,  */
literal|0x030100a9
block|,
literal|0x00000002
block|,
literal|0x00000100
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_19, r2=pswrq2.max_blks_vq19,  */
literal|0x030100aa
block|,
literal|0x00000002
block|,
literal|0x00000102
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_21, r2=pswrq2.max_blks_vq21,  */
literal|0x030100ab
block|,
literal|0x00000002
block|,
literal|0x00000104
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_22, r2=pswrq2.max_blks_vq22,  */
literal|0x030100ac
block|,
literal|0x00000002
block|,
literal|0x00000106
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_23, r2=pswrq2.max_blks_vq23,  */
literal|0x030100ad
block|,
literal|0x00000002
block|,
literal|0x00000108
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_24, r2=pswrq2.max_blks_vq24,  */
literal|0x030100ae
block|,
literal|0x00000002
block|,
literal|0x0000010a
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_26, r2=pswrq2.max_blks_vq26,  */
literal|0x030100af
block|,
literal|0x00000002
block|,
literal|0x0000010c
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_28, r2=pswrq2.max_blks_vq28,  */
literal|0x030100b0
block|,
literal|0x00000002
block|,
literal|0x0000010e
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_29, r2=pswrq2.max_blks_vq29,  */
literal|0x030100b1
block|,
literal|0x00000002
block|,
literal|0x00000110
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_30, r2=pswrq2.max_blks_vq30,  */
literal|0x010000b2
block|,
literal|0x00010001
block|,
literal|0x00000112
block|,
comment|/* (r1!=0), r1=pswrq2.l2p_close_gate_sts,  */
literal|0x010000b3
block|,
literal|0x00010001
block|,
literal|0x00000113
block|,
comment|/* (r1!=0), r1=pswrq2.misc_close_gate_sts,  */
literal|0x010200b4
block|,
literal|0x00010001
block|,
literal|0x00000114
block|,
comment|/* (r1!=0), r1=pswrq2.misc_stall_mem_sts,  */
literal|0x000200b5
block|,
literal|0x00010002
block|,
literal|0x00000115
block|,
comment|/* ((r1&~r2)!=0), r1=pswrq.INT_STS, r2=pswrq.INT_MASK,  */
literal|0x000200b6
block|,
literal|0x00010002
block|,
literal|0x00000117
block|,
comment|/* ((r1&~r2)!=0), r1=pswwr.INT_STS, r2=pswwr.INT_MASK,  */
literal|0x010000b7
block|,
literal|0x00010001
block|,
literal|0x00000119
block|,
comment|/* (r1!=0), r1=pswwr2.pglue_eop_err_details,  */
literal|0x010100b8
block|,
literal|0x00010001
block|,
literal|0x0000011a
block|,
comment|/* (r1!=0), r1=pswwr2.prm_curr_fill_level,  */
literal|0x010100b9
block|,
literal|0x00010001
block|,
literal|0x0000011b
block|,
comment|/* (r1!=0), r1=pswwr2.cdu_curr_fill_level,  */
literal|0x000200ba
block|,
literal|0x00010002
block|,
literal|0x0000011c
block|,
comment|/* ((r1&~r2)!=0), r1=pswwr2.INT_STS, r2=pswwr2.INT_MASK,  */
literal|0x000000bb
block|,
literal|0x00010002
block|,
literal|0x0000011e
block|,
comment|/* ((r1&~r2)!=0), r1=pswwr2.PRTY_STS_H_0, r2=pswwr2.PRTY_MASK_H_0,  */
literal|0x000000bc
block|,
literal|0x00010002
block|,
literal|0x00000120
block|,
comment|/* ((r1&~r2)!=0), r1=pswwr2.PRTY_STS_H_1, r2=pswwr2.PRTY_MASK_H_1,  */
literal|0x000000bd
block|,
literal|0x00010002
block|,
literal|0x00000122
block|,
comment|/* ((r1&~r2)!=0), r1=pswwr2.PRTY_STS_H_2, r2=pswwr2.PRTY_MASK_H_2,  */
literal|0x000000be
block|,
literal|0x00010002
block|,
literal|0x00000124
block|,
comment|/* ((r1&~r2)!=0), r1=pswwr2.PRTY_STS_H_3, r2=pswwr2.PRTY_MASK_H_3,  */
literal|0x010000bf
block|,
literal|0x00010001
block|,
literal|0x00000126
block|,
comment|/* (r1!=0), r1=pswrd.fifo_full_status,  */
literal|0x000200c0
block|,
literal|0x00010002
block|,
literal|0x00000127
block|,
comment|/* ((r1&~r2)!=0), r1=pswrd.INT_STS, r2=pswrd.INT_MASK,  */
literal|0x010000c1
block|,
literal|0x00010001
block|,
literal|0x000d0129
block|,
comment|/* (r1!=1), r1=pswrd2.start_init,  */
literal|0x010000c2
block|,
literal|0x00010001
block|,
literal|0x000d012a
block|,
comment|/* (r1!=1), r1=pswrd2.init_done,  */
literal|0x010200c3
block|,
literal|0x00010001
block|,
literal|0x0000012b
block|,
comment|/* (r1!=0), r1=pswrd2.cpl_err_details,  */
literal|0x010200c4
block|,
literal|0x00010001
block|,
literal|0x0000012c
block|,
comment|/* (r1!=0), r1=pswrd2.cpl_err_details2,  */
literal|0x010100c5
block|,
literal|0x00010001
block|,
literal|0x000d012d
block|,
comment|/* (r1!=1), r1=pswrd2.port_is_idle_0,  */
literal|0x010100c6
block|,
literal|0x00010001
block|,
literal|0x000d012e
block|,
comment|/* (r1!=1), r1=pswrd2.port_is_idle_1,  */
literal|0x010000c7
block|,
literal|0x00010001
block|,
literal|0x0000012f
block|,
comment|/* (r1!=0), r1=pswrd2.almost_full_0[0:14],  */
literal|0x000200c8
block|,
literal|0x00010002
block|,
literal|0x00000130
block|,
comment|/* ((r1&~r2)!=0), r1=pswrd2.INT_STS, r2=pswrd2.INT_MASK,  */
literal|0x000000c9
block|,
literal|0x00010002
block|,
literal|0x00000132
block|,
comment|/* ((r1&~r2)!=0), r1=pswrd2.PRTY_STS_H_0, r2=pswrd2.PRTY_MASK_H_0,  */
literal|0x000000ca
block|,
literal|0x00010002
block|,
literal|0x00000134
block|,
comment|/* ((r1&~r2)!=0), r1=pswrd2.PRTY_STS_H_1, r2=pswrd2.PRTY_MASK_H_1,  */
literal|0x010000cb
block|,
literal|0x00010001
block|,
literal|0x00000136
block|,
comment|/* (r1!=0), r1=pswrd2.disable_inputs,  */
literal|0x010100cc
block|,
literal|0x00010001
block|,
literal|0x00000137
block|,
comment|/* (r1!=0), r1=pswhst2.header_fifo_status,  */
literal|0x010100cd
block|,
literal|0x00010001
block|,
literal|0x00000138
block|,
comment|/* (r1!=0), r1=pswhst2.data_fifo_status,  */
literal|0x000200ce
block|,
literal|0x00010002
block|,
literal|0x00000139
block|,
comment|/* ((r1&~r2)!=0), r1=pswhst2.INT_STS, r2=pswhst2.INT_MASK,  */
literal|0x010200cf
block|,
literal|0x00010001
block|,
literal|0x0000013b
block|,
comment|/* (r1!=0), r1=pswhst.discard_internal_writes_status,  */
literal|0x010200d0
block|,
literal|0x00010001
block|,
literal|0x0000013c
block|,
comment|/* (r1!=0), r1=pswhst.discard_doorbells_status,  */
literal|0x010200d1
block|,
literal|0x00010001
block|,
literal|0x0013013d
block|,
comment|/* (r1!=3), r1=pswhst.arb_is_idle,  */
literal|0x010200d2
block|,
literal|0x00010301
block|,
literal|0x0000013e
block|,
comment|/* (r1!=0), r1=pswhst.incorrect_access_valid,  */
literal|0x010200d3
block|,
literal|0x00010101
block|,
literal|0x00000142
block|,
comment|/* (r1!=0), r1=pswhst.per_violation_valid,  */
literal|0x010200d4
block|,
literal|0x00010001
block|,
literal|0x00140144
block|,
comment|/* (r1!=reset1), r1=pswhst.source_credits_avail,  */
literal|0x010200d5
block|,
literal|0x00010101
block|,
literal|0x00000145
block|,
comment|/* (r1!=0), r1=pswhst.source_credit_viol_valid,  */
literal|0x010200d6
block|,
literal|0x00010001
block|,
literal|0x00150147
block|,
comment|/* (r1!=60074), r1=pswhst.dest_credits_avail,  */
literal|0x010200d7
block|,
literal|0x00010001
block|,
literal|0x00000148
block|,
comment|/* (r1!=0), r1=pswhst.is_in_drain_mode,  */
literal|0x010200d8
block|,
literal|0x00010101
block|,
literal|0x00000149
block|,
comment|/* (r1!=0), r1=pswhst.timeout_valid,  */
literal|0x010200d9
block|,
literal|0x00010101
block|,
literal|0x0000014b
block|,
comment|/* (r1!=0), r1=pswhst.timeout_valid,  */
literal|0x010200da
block|,
literal|0x00010001
block|,
literal|0x0000014d
block|,
comment|/* (r1!=0), r1=pswhst.clients_waiting_to_source_arb[0:7],  */
literal|0x000200db
block|,
literal|0x00010002
block|,
literal|0x0000014e
block|,
comment|/* ((r1&~r2)!=0), r1=pswhst.INT_STS, r2=pswhst.INT_MASK,  */
literal|0x000000dc
block|,
literal|0x00010002
block|,
literal|0x00000150
block|,
comment|/* ((r1&~r2)!=0), r1=pswhst.PRTY_STS_H_0, r2=pswhst.PRTY_MASK_H_0,  */
literal|0x060000dd
block|,
literal|0x00020001
block|,
literal|0x00160152
block|,
comment|/* ((r1&0x01BC01)!=0), r1=pglue_b.INT_STS,  */
literal|0x060200de
block|,
literal|0x00020001
block|,
literal|0x00180153
block|,
comment|/* ((r1&0x76417C)!=0), r1=pglue_b.INT_STS,  */
literal|0x000000df
block|,
literal|0x00010002
block|,
literal|0x00000154
block|,
comment|/* ((r1&~r2)!=0), r1=pglue_b.PRTY_STS_H_0, r2=pglue_b.PRTY_MASK_H_0,  */
literal|0x010000e0
block|,
literal|0x00010001
block|,
literal|0x00000156
block|,
comment|/* (r1!=0), r1=pglue_b.pgl_write_blocked,  */
literal|0x010000e1
block|,
literal|0x00010001
block|,
literal|0x00000157
block|,
comment|/* (r1!=0), r1=pglue_b.pgl_read_blocked,  */
literal|0x010100e2
block|,
literal|0x00010001
block|,
literal|0x00000158
block|,
comment|/* (r1!=0), r1=pglue_b.read_fifo_occupancy_level,  */
literal|0x010200e3
block|,
literal|0x00010001
block|,
literal|0x00000159
block|,
comment|/* (r1!=0), r1=pglue_b.rx_legacy_errors,  */
literal|0x070100e4
block|,
literal|0x00030001
block|,
literal|0x001a015a
block|,
comment|/* (((r1>>17)&1)!=0), r1=pglue_b.pgl_txw_cdts,  */
literal|0x010200e5
block|,
literal|0x00010001
block|,
literal|0x0000015b
block|,
comment|/* (r1!=0), r1=pglue_b.cfg_space_a_request,  */
literal|0x010200e6
block|,
literal|0x00010001
block|,
literal|0x0000015c
block|,
comment|/* (r1!=0), r1=pglue_b.cfg_space_b_request,  */
literal|0x010200e7
block|,
literal|0x00010001
block|,
literal|0x0000015d
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_vf_31_0,  */
literal|0x010200e8
block|,
literal|0x00010001
block|,
literal|0x0000015e
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_vf_63_32,  */
literal|0x010200e9
block|,
literal|0x00010001
block|,
literal|0x0000015f
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_vf_95_64,  */
literal|0x010200ea
block|,
literal|0x00010001
block|,
literal|0x00000160
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_vf_127_96,  */
literal|0x010200eb
block|,
literal|0x00010001
block|,
literal|0x00000161
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_vf_159_128,  */
literal|0x010200ec
block|,
literal|0x00010001
block|,
literal|0x00000162
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_vf_191_160,  */
literal|0x010200ed
block|,
literal|0x00010001
block|,
literal|0x00000163
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_pf_31_0,  */
literal|0x010200ee
block|,
literal|0x00010001
block|,
literal|0x00000164
block|,
comment|/* (r1!=0), r1=pglue_b.sr_iov_disabled_request,  */
literal|0x010200ef
block|,
literal|0x00010001
block|,
literal|0x00000165
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_vf_31_0,  */
literal|0x010200f0
block|,
literal|0x00010001
block|,
literal|0x00000166
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_vf_63_32,  */
literal|0x010200f1
block|,
literal|0x00010001
block|,
literal|0x00000167
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_vf_95_64,  */
literal|0x010200f2
block|,
literal|0x00010001
block|,
literal|0x00000168
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_vf_127_96,  */
literal|0x010200f3
block|,
literal|0x00010001
block|,
literal|0x00000169
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_vf_159_128,  */
literal|0x010200f4
block|,
literal|0x00010001
block|,
literal|0x0000016a
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_vf_191_160,  */
literal|0x010200f5
block|,
literal|0x00010001
block|,
literal|0x0000016b
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_pf_31_0,  */
literal|0x010200f6
block|,
literal|0x00010001
block|,
literal|0x0000016c
block|,
comment|/* (r1!=0), r1=pglue_b.rx_err_details,  */
literal|0x010200f7
block|,
literal|0x00010001
block|,
literal|0x0000016d
block|,
comment|/* (r1!=0), r1=pglue_b.rx_tcpl_err_details,  */
literal|0x010200f8
block|,
literal|0x00010001
block|,
literal|0x0000016e
block|,
comment|/* (r1!=0), r1=pglue_b.tx_err_wr_add_31_0,  */
literal|0x010200f9
block|,
literal|0x00010001
block|,
literal|0x0000016f
block|,
comment|/* (r1!=0), r1=pglue_b.tx_err_wr_add_63_32,  */
literal|0x010200fa
block|,
literal|0x00010001
block|,
literal|0x00000170
block|,
comment|/* (r1!=0), r1=pglue_b.tx_err_wr_details,  */
literal|0x010200fb
block|,
literal|0x00010001
block|,
literal|0x00000171
block|,
comment|/* (r1!=0), r1=pglue_b.tx_err_wr_details2,  */
literal|0x010200fc
block|,
literal|0x00010001
block|,
literal|0x00000172
block|,
comment|/* (r1!=0), r1=pglue_b.tx_err_rd_add_31_0,  */
literal|0x010200fd
block|,
literal|0x00010001
block|,
literal|0x00000173
block|,
comment|/* (r1!=0), r1=pglue_b.tx_err_rd_add_63_32,  */
literal|0x010200fe
block|,
literal|0x00010001
block|,
literal|0x00000174
block|,
comment|/* (r1!=0), r1=pglue_b.tx_err_rd_details,  */
literal|0x010200ff
block|,
literal|0x00010001
block|,
literal|0x00000175
block|,
comment|/* (r1!=0), r1=pglue_b.tx_err_rd_details2,  */
literal|0x01020100
block|,
literal|0x00010001
block|,
literal|0x00000176
block|,
comment|/* (r1!=0), r1=pglue_b.vf_length_violation_details,  */
literal|0x01020101
block|,
literal|0x00010001
block|,
literal|0x00000177
block|,
comment|/* (r1!=0), r1=pglue_b.vf_length_violation_details2,  */
literal|0x01020102
block|,
literal|0x00010001
block|,
literal|0x00000178
block|,
comment|/* (r1!=0), r1=pglue_b.vf_grc_space_violation_details,  */
literal|0x01020103
block|,
literal|0x00010001
block|,
literal|0x00000179
block|,
comment|/* (r1!=0), r1=pglue_b.master_zlr_err_add_31_0,  */
literal|0x01020104
block|,
literal|0x00010001
block|,
literal|0x0000017a
block|,
comment|/* (r1!=0), r1=pglue_b.master_zlr_err_add_63_32,  */
literal|0x01020105
block|,
literal|0x00010001
block|,
literal|0x0000017b
block|,
comment|/* (r1!=0), r1=pglue_b.master_zlr_err_details,  */
literal|0x01020106
block|,
literal|0x00010001
block|,
literal|0x0000017c
block|,
comment|/* (r1!=0), r1=pglue_b.admin_window_violation_details,  */
literal|0x01000107
block|,
literal|0x00010001
block|,
literal|0x0000017d
block|,
comment|/* (r1!=0), r1=pglue_b.out_of_range_function_in_pretend_details,  */
literal|0x01000108
block|,
literal|0x00010001
block|,
literal|0x0000017e
block|,
comment|/* (r1!=0), r1=pglue_b.out_of_range_function_in_pretend_address,  */
literal|0x01010109
block|,
literal|0x00010001
block|,
literal|0x0000017f
block|,
comment|/* (r1!=0), r1=pglue_b.write_fifo_occupancy_level,  */
literal|0x0102010a
block|,
literal|0x00010001
block|,
literal|0x00000180
block|,
comment|/* (r1!=0), r1=pglue_b.illegal_address_add_31_0,  */
literal|0x0102010b
block|,
literal|0x00010001
block|,
literal|0x00000181
block|,
comment|/* (r1!=0), r1=pglue_b.illegal_address_add_63_32,  */
literal|0x0102010c
block|,
literal|0x00010001
block|,
literal|0x00000182
block|,
comment|/* (r1!=0), r1=pglue_b.illegal_address_details,  */
literal|0x0102010d
block|,
literal|0x00010001
block|,
literal|0x00000183
block|,
comment|/* (r1!=0), r1=pglue_b.illegal_address_details2,  */
literal|0x0102010e
block|,
literal|0x00010001
block|,
literal|0x001d0184
block|,
comment|/* (r1!=0xffffffff), r1=pglue_b.tags_31_0,  */
literal|0x0102010f
block|,
literal|0x00010001
block|,
literal|0x001d0185
block|,
comment|/* (r1!=0xffffffff), r1=pglue_b.tags_63_32,  */
literal|0x01020110
block|,
literal|0x00010001
block|,
literal|0x001d0186
block|,
comment|/* (r1!=0xffffffff), r1=pglue_b.tags_95_64,  */
literal|0x01020111
block|,
literal|0x00010001
block|,
literal|0x001d0187
block|,
comment|/* (r1!=0xffffffff), r1=pglue_b.tags_127_96,  */
literal|0x01020112
block|,
literal|0x00010001
block|,
literal|0x00000188
block|,
comment|/* (r1!=0), r1=pglue_b.vf_ilt_err_add_31_0,  */
literal|0x01020113
block|,
literal|0x00010001
block|,
literal|0x00000189
block|,
comment|/* (r1!=0), r1=pglue_b.vf_ilt_err_add_63_32,  */
literal|0x01020114
block|,
literal|0x00010001
block|,
literal|0x0000018a
block|,
comment|/* (r1!=0), r1=pglue_b.vf_ilt_err_details,  */
literal|0x01020115
block|,
literal|0x00010001
block|,
literal|0x0000018b
block|,
comment|/* (r1!=0), r1=pglue_b.vf_ilt_err_details2,  */
literal|0x0d000116
block|,
literal|0x00010001
block|,
literal|0x001e018c
block|,
comment|/* (r1&0x7FFFFF), r1=tm.INT_STS_0,  */
literal|0x0d020117
block|,
literal|0x00010001
block|,
literal|0x001f018d
block|,
comment|/* (r1&0x80000000), r1=tm.INT_STS_0,  */
literal|0x0d000118
block|,
literal|0x00010001
block|,
literal|0x0020018e
block|,
comment|/* (r1&0x7F800000), r1=tm.INT_STS_0,  */
literal|0x0d000119
block|,
literal|0x00010001
block|,
literal|0x0021018f
block|,
comment|/* (r1&0x41E), r1=tm.INT_STS_1,  */
literal|0x0000011a
block|,
literal|0x00010002
block|,
literal|0x00000190
block|,
comment|/* ((r1&~r2)!=0), r1=tm.PRTY_STS_H_0, r2=tm.PRTY_MASK_H_0,  */
literal|0x0101011b
block|,
literal|0x00010001
block|,
literal|0x00000192
block|,
comment|/* (r1!=0), r1=tm.pxp_read_data_fifo_status,  */
literal|0x0101011c
block|,
literal|0x00010001
block|,
literal|0x00000193
block|,
comment|/* (r1!=0), r1=tm.pxp_read_ctrl_fifo_status,  */
literal|0x0101011d
block|,
literal|0x00010001
block|,
literal|0x00000194
block|,
comment|/* (r1!=0), r1=tm.cfc_load_echo_fifo_status,  */
literal|0x0101011e
block|,
literal|0x00010001
block|,
literal|0x00000195
block|,
comment|/* (r1!=0), r1=tm.client_out_fifo_status,  */
literal|0x0101011f
block|,
literal|0x00010001
block|,
literal|0x00000196
block|,
comment|/* (r1!=0), r1=tm.client_in_pbf_fifo_status,  */
literal|0x01010120
block|,
literal|0x00010001
block|,
literal|0x00000197
block|,
comment|/* (r1!=0), r1=tm.client_in_xcm_fifo_status,  */
literal|0x01010121
block|,
literal|0x00010001
block|,
literal|0x00000198
block|,
comment|/* (r1!=0), r1=tm.client_in_tcm_fifo_status,  */
literal|0x01010122
block|,
literal|0x00010001
block|,
literal|0x00000199
block|,
comment|/* (r1!=0), r1=tm.client_in_ucm_fifo_status,  */
literal|0x01010123
block|,
literal|0x00010001
block|,
literal|0x0000019a
block|,
comment|/* (r1!=0), r1=tm.expiration_cmd_fifo_status,  */
literal|0x01010124
block|,
literal|0x00010001
block|,
literal|0x0000019b
block|,
comment|/* (r1!=0), r1=tm.ac_command_fifo_status,  */
literal|0x01000125
block|,
literal|0x00010001
block|,
literal|0x000d019c
block|,
comment|/* (r1!=1), r1=tcfc.ll_init_done,  */
literal|0x01000126
block|,
literal|0x00010001
block|,
literal|0x000d019d
block|,
comment|/* (r1!=1), r1=tcfc.ac_init_done,  */
literal|0x01000127
block|,
literal|0x00010001
block|,
literal|0x000d019e
block|,
comment|/* (r1!=1), r1=tcfc.cam_init_done,  */
literal|0x01000128
block|,
literal|0x00010001
block|,
literal|0x000d019f
block|,
comment|/* (r1!=1), r1=tcfc.tidram_init_done,  */
literal|0x00000129
block|,
literal|0x00010502
block|,
literal|0x000001a0
block|,
comment|/* ((r1&~r2)!=0), r1=tcfc.INT_STS_0, r2=tcfc.INT_MASK_0,  */
literal|0x0000012a
block|,
literal|0x00010002
block|,
literal|0x000001a7
block|,
comment|/* ((r1&~r2)!=0), r1=tcfc.PRTY_STS_H_0, r2=tcfc.PRTY_MASK_H_0,  */
literal|0x0101012b
block|,
literal|0x00010001
block|,
literal|0x000001a9
block|,
comment|/* (r1!=0x0), r1=tcfc.lstate_arriving,  */
literal|0x0101012c
block|,
literal|0x00010001
block|,
literal|0x000001aa
block|,
comment|/* (r1!=0x0), r1=tcfc.lstate_leaving,  */
literal|0x0101012d
block|,
literal|0x00010001
block|,
literal|0x002201ab
block|,
comment|/* (r1!=0x30), r1=tcfc.cduld_credit,  */
literal|0x0100012e
block|,
literal|0x00010001
block|,
literal|0x000d01ac
block|,
comment|/* (r1!=1), r1=ccfc.ll_init_done,  */
literal|0x0100012f
block|,
literal|0x00010001
block|,
literal|0x000d01ad
block|,
comment|/* (r1!=1), r1=ccfc.ac_init_done,  */
literal|0x01000130
block|,
literal|0x00010001
block|,
literal|0x000d01ae
block|,
comment|/* (r1!=1), r1=ccfc.cam_init_done,  */
literal|0x01000131
block|,
literal|0x00010001
block|,
literal|0x000d01af
block|,
comment|/* (r1!=1), r1=ccfc.tidram_init_done,  */
literal|0x00000132
block|,
literal|0x00010502
block|,
literal|0x000001b0
block|,
comment|/* ((r1&~r2)!=0), r1=ccfc.INT_STS_0, r2=ccfc.INT_MASK_0,  */
literal|0x00000133
block|,
literal|0x00010002
block|,
literal|0x000001b7
block|,
comment|/* ((r1&~r2)!=0), r1=ccfc.PRTY_STS_H_0, r2=ccfc.PRTY_MASK_H_0,  */
literal|0x00000134
block|,
literal|0x00010002
block|,
literal|0x000001b9
block|,
comment|/* ((r1&~r2)!=0), r1=ccfc.PRTY_STS, r2=ccfc.PRTY_MASK,  */
literal|0x01010135
block|,
literal|0x00010001
block|,
literal|0x000001bb
block|,
comment|/* (r1!=0x0), r1=ccfc.lstate_arriving,  */
literal|0x01010136
block|,
literal|0x00010001
block|,
literal|0x000001bc
block|,
comment|/* (r1!=0x0), r1=ccfc.lstate_leaving,  */
literal|0x01010137
block|,
literal|0x00010001
block|,
literal|0x002201bd
block|,
comment|/* (r1!=0x30), r1=ccfc.cduld_credit,  */
literal|0x01010138
block|,
literal|0x00010001
block|,
literal|0x000a01be
block|,
comment|/* (r1!=0x10), r1=ccfc.cduwb_credit,  */
literal|0x00000139
block|,
literal|0x00010002
block|,
literal|0x000001bf
block|,
comment|/* ((r1&~r2)!=0), r1=qm.INT_STS, r2=qm.INT_MASK,  */
literal|0x0000013a
block|,
literal|0x00010002
block|,
literal|0x000001c1
block|,
comment|/* ((r1&~r2)!=0), r1=qm.PRTY_STS, r2=qm.PRTY_MASK,  */
literal|0x0000013b
block|,
literal|0x00010002
block|,
literal|0x000001c3
block|,
comment|/* ((r1&~r2)!=0), r1=qm.PRTY_STS_H_0, r2=qm.PRTY_MASK_H_0,  */
literal|0x0000013c
block|,
literal|0x00010002
block|,
literal|0x000001c5
block|,
comment|/* ((r1&~r2)!=0), r1=qm.PRTY_STS_H_1, r2=qm.PRTY_MASK_H_1,  */
literal|0x0000013d
block|,
literal|0x00010002
block|,
literal|0x000001c7
block|,
comment|/* ((r1&~r2)!=0), r1=qm.PRTY_STS_H_2, r2=qm.PRTY_MASK_H_2,  */
literal|0x0100013e
block|,
literal|0x00010001
block|,
literal|0x000001c9
block|,
comment|/* (r1!=0), r1=qm.wrc_fifolvl_0[0:5],  */
literal|0x0300013f
block|,
literal|0x00000002
block|,
literal|0x000001ca
block|,
comment|/* (r1!=r2), r1=qm.OutLdReqCrdConnTx, r2=qm.OutLdReqSizeConnTx,  */
literal|0x03000140
block|,
literal|0x00000002
block|,
literal|0x000001cc
block|,
comment|/* (r1!=r2), r1=qm.OutLdReqCrdConnOther, r2=qm.OutLdReqSizeConnOther,  */
literal|0x01000141
block|,
literal|0x00010001
block|,
literal|0x000001ce
block|,
comment|/* (r1!=0), r1=qm.OvfQNumTx,  */
literal|0x01000142
block|,
literal|0x00010101
block|,
literal|0x000001cf
block|,
comment|/* (r1!=0), r1=qm.OvfErrorTx,  */
literal|0x01000143
block|,
literal|0x00010001
block|,
literal|0x000001d1
block|,
comment|/* (r1!=0), r1=qm.OvfQNumOther,  */
literal|0x01000144
block|,
literal|0x00010101
block|,
literal|0x000001d2
block|,
comment|/* (r1!=0), r1=qm.OvfErrorOther,  */
literal|0x03010145
block|,
literal|0x00000002
block|,
literal|0x000001d4
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_0, r2=qm.CmInitCrd_0,  */
literal|0x03010146
block|,
literal|0x00000002
block|,
literal|0x000001d6
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_1, r2=qm.CmInitCrd_1,  */
literal|0x03010147
block|,
literal|0x00000002
block|,
literal|0x000001d8
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_2, r2=qm.CmInitCrd_2,  */
literal|0x03010148
block|,
literal|0x00000002
block|,
literal|0x000001da
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_3, r2=qm.CmInitCrd_3,  */
literal|0x03010149
block|,
literal|0x00000002
block|,
literal|0x000001dc
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_4, r2=qm.CmInitCrd_4,  */
literal|0x0301014a
block|,
literal|0x00000002
block|,
literal|0x000001de
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_5, r2=qm.CmInitCrd_5,  */
literal|0x0301014b
block|,
literal|0x00000002
block|,
literal|0x000001e0
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_6, r2=qm.CmInitCrd_6,  */
literal|0x0301014c
block|,
literal|0x00000002
block|,
literal|0x000001e2
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_7, r2=qm.CmInitCrd_7,  */
literal|0x0301014d
block|,
literal|0x00000002
block|,
literal|0x000001e4
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_8, r2=qm.CmInitCrd_8,  */
literal|0x0301014e
block|,
literal|0x00000002
block|,
literal|0x000001e6
block|,
comment|/* (r1!=r2), r1=qm.CmCrd_9, r2=qm.CmInitCrd_9,  */
literal|0x0000014f
block|,
literal|0x00010002
block|,
literal|0x000001e8
block|,
comment|/* ((r1&~r2)!=0), r1=rdif.INT_STS, r2=rdif.INT_MASK,  */
literal|0x00000150
block|,
literal|0x00010002
block|,
literal|0x000001ea
block|,
comment|/* ((r1&~r2)!=0), r1=tdif.INT_STS, r2=tdif.INT_MASK,  */
literal|0x00000151
block|,
literal|0x00010002
block|,
literal|0x000001ec
block|,
comment|/* ((r1&~r2)!=0), r1=tdif.PRTY_STS_H_0, r2=tdif.PRTY_MASK_H_0,  */
literal|0x00000152
block|,
literal|0x00010202
block|,
literal|0x000001ee
block|,
comment|/* ((r1&~r2)!=0), r1=brb.INT_STS_0, r2=brb.INT_MASK_0,  */
literal|0x00000153
block|,
literal|0x00010002
block|,
literal|0x000001f2
block|,
comment|/* ((r1&~r2)!=0), r1=brb.INT_STS_1, r2=brb.INT_MASK_1,  */
literal|0x00000154
block|,
literal|0x00010002
block|,
literal|0x000001f4
block|,
comment|/* ((r1&~r2)!=0), r1=brb.INT_STS_2, r2=brb.INT_MASK_2,  */
literal|0x00000155
block|,
literal|0x00010002
block|,
literal|0x000001f6
block|,
comment|/* ((r1&~r2)!=0), r1=brb.INT_STS_3, r2=brb.INT_MASK_3,  */
literal|0x00000156
block|,
literal|0x00010202
block|,
literal|0x000001f8
block|,
comment|/* ((r1&~r2)!=0), r1=brb.INT_STS_4, r2=brb.INT_MASK_4,  */
literal|0x00000157
block|,
literal|0x00010002
block|,
literal|0x000001fc
block|,
comment|/* ((r1&~r2)!=0), r1=brb.PRTY_STS_H_0, r2=brb.PRTY_MASK_H_0,  */
literal|0x00000158
block|,
literal|0x00010002
block|,
literal|0x000001fe
block|,
comment|/* ((r1&~r2)!=0), r1=brb.PRTY_STS_H_1, r2=brb.PRTY_MASK_H_1,  */
literal|0x01010159
block|,
literal|0x00010001
block|,
literal|0x00000200
block|,
comment|/* (r1!=0), r1=brb.wc_bandwidth_if_full,  */
literal|0x0101015a
block|,
literal|0x00010001
block|,
literal|0x00000201
block|,
comment|/* (r1!=0), r1=brb.rc_pkt_if_full,  */
literal|0x0101015b
block|,
literal|0x00010001
block|,
literal|0x00230202
block|,
comment|/* (r1!=255), r1=brb.rc_pkt_empty_0[0:4],  */
literal|0x0101015c
block|,
literal|0x00010001
block|,
literal|0x00030203
block|,
comment|/* (r1!=15), r1=brb.rc_sop_empty,  */
literal|0x0101015d
block|,
literal|0x00010001
block|,
literal|0x000b0204
block|,
comment|/* (r1!=2), r1=brb.ll_arb_empty,  */
literal|0x0101015e
block|,
literal|0x00010001
block|,
literal|0x00000205
block|,
comment|/* (r1!=0), r1=brb.stop_packet_counter,  */
literal|0x0101015f
block|,
literal|0x00010001
block|,
literal|0x00000206
block|,
comment|/* (r1!=0), r1=brb.stop_byte_counter,  */
literal|0x01010160
block|,
literal|0x00010001
block|,
literal|0x00000207
block|,
comment|/* (r1!=0), r1=brb.rc_pkt_state,  */
literal|0x01010161
block|,
literal|0x00010001
block|,
literal|0x00000208
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_0,  */
literal|0x01010162
block|,
literal|0x00010001
block|,
literal|0x00000209
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_1,  */
literal|0x01010163
block|,
literal|0x00010001
block|,
literal|0x0000020a
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_2,  */
literal|0x01010164
block|,
literal|0x00010001
block|,
literal|0x0000020b
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_3,  */
literal|0x01010165
block|,
literal|0x00010001
block|,
literal|0x0000020c
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_4,  */
literal|0x01010166
block|,
literal|0x00010001
block|,
literal|0x0000020d
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_5,  */
literal|0x01010167
block|,
literal|0x00010001
block|,
literal|0x0000020e
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_6,  */
literal|0x01010168
block|,
literal|0x00010001
block|,
literal|0x0000020f
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_7,  */
literal|0x01010169
block|,
literal|0x00010001
block|,
literal|0x00000210
block|,
comment|/* (r1!=0), r1=brb.mac0_tc_occupancy_8,  */
literal|0x0101016a
block|,
literal|0x00010001
block|,
literal|0x00000211
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_0,  */
literal|0x0101016b
block|,
literal|0x00010001
block|,
literal|0x00000212
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_1,  */
literal|0x0101016c
block|,
literal|0x00010001
block|,
literal|0x00000213
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_2,  */
literal|0x0101016d
block|,
literal|0x00010001
block|,
literal|0x00000214
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_3,  */
literal|0x0101016e
block|,
literal|0x00010001
block|,
literal|0x00000215
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_4,  */
literal|0x0101016f
block|,
literal|0x00010001
block|,
literal|0x00000216
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_5,  */
literal|0x01010170
block|,
literal|0x00010001
block|,
literal|0x00000217
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_6,  */
literal|0x01010171
block|,
literal|0x00010001
block|,
literal|0x00000218
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_7,  */
literal|0x01010172
block|,
literal|0x00010001
block|,
literal|0x00000219
block|,
comment|/* (r1!=0), r1=brb.mac1_tc_occupancy_8,  */
literal|0x01010173
block|,
literal|0x00010001
block|,
literal|0x0000021a
block|,
comment|/* (r1!=0), r1=xyld.pending_msg_to_ext_ev_1_ctr,  */
literal|0x01010174
block|,
literal|0x00010001
block|,
literal|0x0000021b
block|,
comment|/* (r1!=0), r1=xyld.pending_msg_to_ext_ev_2_ctr,  */
literal|0x01010175
block|,
literal|0x00010001
block|,
literal|0x0000021c
block|,
comment|/* (r1!=0), r1=xyld.pending_msg_to_ext_ev_3_ctr,  */
literal|0x01010176
block|,
literal|0x00010001
block|,
literal|0x0000021d
block|,
comment|/* (r1!=0), r1=xyld.pending_msg_to_ext_ev_4_ctr,  */
literal|0x01010177
block|,
literal|0x00010001
block|,
literal|0x0000021e
block|,
comment|/* (r1!=0), r1=xyld.pending_msg_to_ext_ev_5_ctr,  */
literal|0x03010178
block|,
literal|0x00000002
block|,
literal|0x0000021f
block|,
comment|/* (r1!=r2), r1=xyld.foc_remain_credits, r2=xyld.foci_foc_credits,  */
literal|0x01010179
block|,
literal|0x00010001
block|,
literal|0x00000221
block|,
comment|/* (r1!=0), r1=xyld.pci_pending_msg_ctr,  */
literal|0x0101017a
block|,
literal|0x00010001
block|,
literal|0x00000222
block|,
comment|/* (r1!=0), r1=xyld.dbg_pending_ccfc_req,  */
literal|0x0101017b
block|,
literal|0x00010001
block|,
literal|0x00000223
block|,
comment|/* (r1!=0), r1=xyld.dbg_pending_tcfc_req,  */
literal|0x0000017c
block|,
literal|0x00010002
block|,
literal|0x00000224
block|,
comment|/* ((r1&~r2)!=0), r1=xyld.PRTY_STS_H_0, r2=xyld.PRTY_MASK_H_0,  */
literal|0x0101017d
block|,
literal|0x00010001
block|,
literal|0x00000226
block|,
comment|/* (r1!=0), r1=tmld.pending_msg_to_ext_ev_1_ctr,  */
literal|0x0101017e
block|,
literal|0x00010001
block|,
literal|0x00000227
block|,
comment|/* (r1!=0), r1=tmld.pending_msg_to_ext_ev_2_ctr,  */
literal|0x0101017f
block|,
literal|0x00010001
block|,
literal|0x00000228
block|,
comment|/* (r1!=0), r1=tmld.pending_msg_to_ext_ev_3_ctr,  */
literal|0x01010180
block|,
literal|0x00010001
block|,
literal|0x00000229
block|,
comment|/* (r1!=0), r1=tmld.pending_msg_to_ext_ev_4_ctr,  */
literal|0x01010181
block|,
literal|0x00010001
block|,
literal|0x0000022a
block|,
comment|/* (r1!=0), r1=tmld.pending_msg_to_ext_ev_5_ctr,  */
literal|0x03010182
block|,
literal|0x00000002
block|,
literal|0x0000022b
block|,
comment|/* (r1!=r2), r1=tmld.foc_remain_credits, r2=tmld.foci_foc_credits,  */
literal|0x01010183
block|,
literal|0x00010001
block|,
literal|0x0000022d
block|,
comment|/* (r1!=0), r1=tmld.dbg_pending_ccfc_req,  */
literal|0x01010184
block|,
literal|0x00010001
block|,
literal|0x0000022e
block|,
comment|/* (r1!=0), r1=tmld.dbg_pending_tcfc_req,  */
literal|0x00000185
block|,
literal|0x00010002
block|,
literal|0x0000022f
block|,
comment|/* ((r1&~r2)!=0), r1=tmld.PRTY_STS_H_0, r2=tmld.PRTY_MASK_H_0,  */
literal|0x01010186
block|,
literal|0x00010001
block|,
literal|0x00000231
block|,
comment|/* (r1!=0), r1=muld.pending_msg_to_ext_ev_1_ctr,  */
literal|0x01010187
block|,
literal|0x00010001
block|,
literal|0x00000232
block|,
comment|/* (r1!=0), r1=muld.pending_msg_to_ext_ev_2_ctr,  */
literal|0x01010188
block|,
literal|0x00010001
block|,
literal|0x00000233
block|,
comment|/* (r1!=0), r1=muld.pending_msg_to_ext_ev_3_ctr,  */
literal|0x01010189
block|,
literal|0x00010001
block|,
literal|0x00000234
block|,
comment|/* (r1!=0), r1=muld.pending_msg_to_ext_ev_4_ctr,  */
literal|0x0101018a
block|,
literal|0x00010001
block|,
literal|0x00000235
block|,
comment|/* (r1!=0), r1=muld.pending_msg_to_ext_ev_5_ctr,  */
literal|0x0301018b
block|,
literal|0x00000002
block|,
literal|0x00000236
block|,
comment|/* (r1!=r2), r1=muld.foc_remain_credits, r2=muld.foci_foc_credits,  */
literal|0x0101018c
block|,
literal|0x00010001
block|,
literal|0x00000238
block|,
comment|/* (r1!=0), r1=muld.bd_pending_msg_ctr,  */
literal|0x0101018d
block|,
literal|0x00010001
block|,
literal|0x00000239
block|,
comment|/* (r1!=0), r1=muld.sge_pending_msg_ctr,  */
literal|0x0101018e
block|,
literal|0x00010001
block|,
literal|0x0000023a
block|,
comment|/* (r1!=0), r1=muld.pci_pending_msg_ctr,  */
literal|0x0101018f
block|,
literal|0x00010001
block|,
literal|0x0000023b
block|,
comment|/* (r1!=0), r1=muld.dbg_pending_ccfc_req,  */
literal|0x01010190
block|,
literal|0x00010001
block|,
literal|0x0000023c
block|,
comment|/* (r1!=0), r1=muld.dbg_pending_tcfc_req,  */
literal|0x00000191
block|,
literal|0x00010002
block|,
literal|0x0000023d
block|,
comment|/* ((r1&~r2)!=0), r1=muld.PRTY_STS_H_0, r2=muld.PRTY_MASK_H_0,  */
literal|0x00000192
block|,
literal|0x00010002
block|,
literal|0x0000023f
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_0, r2=nig.INT_MASK_0,  */
literal|0x00000193
block|,
literal|0x00010002
block|,
literal|0x00000241
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_1, r2=nig.INT_MASK_1,  */
literal|0x00000194
block|,
literal|0x00010002
block|,
literal|0x00000243
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_2, r2=nig.INT_MASK_2,  */
literal|0x00020195
block|,
literal|0x00010202
block|,
literal|0x00000245
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_3, r2=nig.INT_MASK_3,  */
literal|0x00000196
block|,
literal|0x00010002
block|,
literal|0x00000249
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_4, r2=nig.INT_MASK_4,  */
literal|0x00020197
block|,
literal|0x00010202
block|,
literal|0x0000024b
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_5, r2=nig.INT_MASK_5,  */
literal|0x00000198
block|,
literal|0x00010002
block|,
literal|0x0000024f
block|,
comment|/* ((r1&~r2)!=0), r1=nig.PRTY_STS_H_0, r2=nig.PRTY_MASK_H_0,  */
literal|0x00000199
block|,
literal|0x00010002
block|,
literal|0x00000251
block|,
comment|/* ((r1&~r2)!=0), r1=nig.PRTY_STS_H_1, r2=nig.PRTY_MASK_H_1,  */
literal|0x0000019a
block|,
literal|0x00010002
block|,
literal|0x00000253
block|,
comment|/* ((r1&~r2)!=0), r1=nig.PRTY_STS_H_2, r2=nig.PRTY_MASK_H_2,  */
literal|0x0000019b
block|,
literal|0x00010002
block|,
literal|0x00000255
block|,
comment|/* ((r1&~r2)!=0), r1=nig.PRTY_STS_H_3, r2=nig.PRTY_MASK_H_3,  */
literal|0x0101019c
block|,
literal|0x00010001
block|,
literal|0x00240257
block|,
comment|/* (r1!=0x000fffff), r1=nig.lb_sopq_empty,  */
literal|0x0101019d
block|,
literal|0x00010001
block|,
literal|0x00250258
block|,
comment|/* (r1!=0x0000ffff), r1=nig.tx_sopq_empty,  */
literal|0x0101019e
block|,
literal|0x00010001
block|,
literal|0x000d0259
block|,
comment|/* (r1!=1), r1=nig.rx_llh_rfifo_empty,  */
literal|0x0101019f
block|,
literal|0x00010001
block|,
literal|0x000d025a
block|,
comment|/* (r1!=1), r1=nig.lb_btb_fifo_empty,  */
literal|0x010101a0
block|,
literal|0x00010001
block|,
literal|0x000d025b
block|,
comment|/* (r1!=1), r1=nig.lb_llh_rfifo_empty,  */
literal|0x050001a1
block|,
literal|0x00040002
block|,
literal|0x0026025c
block|,
comment|/* (((r1&0xff)!=0)&&((r2&0x7)!=0)), r1=nig.rx_ptp_ts_msb_err, r2=nig.rx_ptp_en,  */
literal|0x010101a2
block|,
literal|0x00010001
block|,
literal|0x000d025e
block|,
comment|/* (r1!=1), r1=nig.tx_btb_fifo_empty,  */
literal|0x010101a3
block|,
literal|0x00010001
block|,
literal|0x000d025f
block|,
comment|/* (r1!=1), r1=nig.debug_fifo_empty,  */
literal|0x010001a4
block|,
literal|0x00010001
block|,
literal|0x00000260
block|,
comment|/* (r1!=0), r1=ptu.pxp_err_ctr,  */
literal|0x010001a5
block|,
literal|0x00010001
block|,
literal|0x00000261
block|,
comment|/* (r1!=0), r1=ptu.inv_err_ctr,  */
literal|0x010001a6
block|,
literal|0x00010001
block|,
literal|0x00000262
block|,
comment|/* (r1!=0), r1=ptu.pbf_fill_level,  */
literal|0x010001a7
block|,
literal|0x00010001
block|,
literal|0x00000263
block|,
comment|/* (r1!=0), r1=ptu.prm_fill_level,  */
literal|0x000001a8
block|,
literal|0x00010002
block|,
literal|0x00000264
block|,
comment|/* ((r1&~r2)!=0), r1=ptu.INT_STS, r2=ptu.INT_MASK,  */
literal|0x000001a9
block|,
literal|0x00010002
block|,
literal|0x00000266
block|,
comment|/* ((r1&~r2)!=0), r1=ptu.PRTY_STS_H_0, r2=ptu.PRTY_MASK_H_0,  */
literal|0x000001aa
block|,
literal|0x00010602
block|,
literal|0x00000268
block|,
comment|/* ((r1&~r2)!=0), r1=cdu.INT_STS, r2=cdu.INT_MASK,  */
literal|0x000001ab
block|,
literal|0x00010002
block|,
literal|0x00000270
block|,
comment|/* ((r1&~r2)!=0), r1=cdu.PRTY_STS_H_0, r2=cdu.PRTY_MASK_H_0,  */
literal|0x010201ac
block|,
literal|0x00010001
block|,
literal|0x00000272
block|,
comment|/* (r1!=0), r1=pbf.num_pkts_received_with_error,  */
literal|0x010201ad
block|,
literal|0x00010001
block|,
literal|0x00000273
block|,
comment|/* (r1!=0), r1=pbf.num_pkts_sent_with_error_to_btb,  */
literal|0x010201ae
block|,
literal|0x00010001
block|,
literal|0x00000274
block|,
comment|/* (r1!=0), r1=pbf.num_pkts_sent_with_drop_to_btb,  */
literal|0x010101af
block|,
literal|0x00010001
block|,
literal|0x00000275
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq0,  */
literal|0x010101b0
block|,
literal|0x00010001
block|,
literal|0x00000276
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq0,  */
literal|0x010101b1
block|,
literal|0x00010001
block|,
literal|0x00000277
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq0,  */
literal|0x010101b2
block|,
literal|0x00010001
block|,
literal|0x00000278
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq1,  */
literal|0x010101b3
block|,
literal|0x00010001
block|,
literal|0x00000279
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq1,  */
literal|0x010101b4
block|,
literal|0x00010001
block|,
literal|0x0000027a
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq1,  */
literal|0x010101b5
block|,
literal|0x00010001
block|,
literal|0x0000027b
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq2,  */
literal|0x010101b6
block|,
literal|0x00010001
block|,
literal|0x0000027c
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq2,  */
literal|0x010101b7
block|,
literal|0x00010001
block|,
literal|0x0000027d
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq2,  */
literal|0x010101b8
block|,
literal|0x00010001
block|,
literal|0x0000027e
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq3,  */
literal|0x010101b9
block|,
literal|0x00010001
block|,
literal|0x0000027f
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq3,  */
literal|0x010101ba
block|,
literal|0x00010001
block|,
literal|0x00000280
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq3,  */
literal|0x010101bb
block|,
literal|0x00010001
block|,
literal|0x00000281
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq4,  */
literal|0x010101bc
block|,
literal|0x00010001
block|,
literal|0x00000282
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq4,  */
literal|0x010101bd
block|,
literal|0x00010001
block|,
literal|0x00000283
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq4,  */
literal|0x010101be
block|,
literal|0x00010001
block|,
literal|0x00000284
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq5,  */
literal|0x010101bf
block|,
literal|0x00010001
block|,
literal|0x00000285
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq5,  */
literal|0x010101c0
block|,
literal|0x00010001
block|,
literal|0x00000286
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq5,  */
literal|0x010101c1
block|,
literal|0x00010001
block|,
literal|0x00000287
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq6,  */
literal|0x010101c2
block|,
literal|0x00010001
block|,
literal|0x00000288
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq6,  */
literal|0x010101c3
block|,
literal|0x00010001
block|,
literal|0x00000289
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq6,  */
literal|0x010101c4
block|,
literal|0x00010001
block|,
literal|0x0000028a
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq7,  */
literal|0x010101c5
block|,
literal|0x00010001
block|,
literal|0x0000028b
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq7,  */
literal|0x010101c6
block|,
literal|0x00010001
block|,
literal|0x0000028c
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq7,  */
literal|0x010101c7
block|,
literal|0x00010001
block|,
literal|0x0000028d
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq8,  */
literal|0x010101c8
block|,
literal|0x00010001
block|,
literal|0x0000028e
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq8,  */
literal|0x010101c9
block|,
literal|0x00010001
block|,
literal|0x0000028f
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq8,  */
literal|0x010101ca
block|,
literal|0x00010001
block|,
literal|0x00000290
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq9,  */
literal|0x010101cb
block|,
literal|0x00010001
block|,
literal|0x00000291
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq9,  */
literal|0x010101cc
block|,
literal|0x00010001
block|,
literal|0x00000292
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq9,  */
literal|0x010101cd
block|,
literal|0x00010001
block|,
literal|0x00000293
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq10,  */
literal|0x010101ce
block|,
literal|0x00010001
block|,
literal|0x00000294
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq10,  */
literal|0x010101cf
block|,
literal|0x00010001
block|,
literal|0x00000295
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq10,  */
literal|0x010101d0
block|,
literal|0x00010001
block|,
literal|0x00000296
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq11,  */
literal|0x010101d1
block|,
literal|0x00010001
block|,
literal|0x00000297
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq11,  */
literal|0x010101d2
block|,
literal|0x00010001
block|,
literal|0x00000298
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq11,  */
literal|0x010101d3
block|,
literal|0x00010001
block|,
literal|0x00000299
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq12,  */
literal|0x010101d4
block|,
literal|0x00010001
block|,
literal|0x0000029a
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq12,  */
literal|0x010101d5
block|,
literal|0x00010001
block|,
literal|0x0000029b
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq12,  */
literal|0x010101d6
block|,
literal|0x00010001
block|,
literal|0x0000029c
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq13,  */
literal|0x010101d7
block|,
literal|0x00010001
block|,
literal|0x0000029d
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq13,  */
literal|0x010101d8
block|,
literal|0x00010001
block|,
literal|0x0000029e
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq13,  */
literal|0x010101d9
block|,
literal|0x00010001
block|,
literal|0x0000029f
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq14,  */
literal|0x010101da
block|,
literal|0x00010001
block|,
literal|0x000002a0
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq14,  */
literal|0x010101db
block|,
literal|0x00010001
block|,
literal|0x000002a1
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq14,  */
literal|0x010101dc
block|,
literal|0x00010001
block|,
literal|0x000002a2
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq15,  */
literal|0x010101dd
block|,
literal|0x00010001
block|,
literal|0x000002a3
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq15,  */
literal|0x010101de
block|,
literal|0x00010001
block|,
literal|0x000002a4
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq15,  */
literal|0x010101df
block|,
literal|0x00010001
block|,
literal|0x000002a5
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq16,  */
literal|0x010101e0
block|,
literal|0x00010001
block|,
literal|0x000002a6
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq16,  */
literal|0x010101e1
block|,
literal|0x00010001
block|,
literal|0x000002a7
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq16,  */
literal|0x010101e2
block|,
literal|0x00010001
block|,
literal|0x000002a8
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq17,  */
literal|0x010101e3
block|,
literal|0x00010001
block|,
literal|0x000002a9
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq17,  */
literal|0x010101e4
block|,
literal|0x00010001
block|,
literal|0x000002aa
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq17,  */
literal|0x010101e5
block|,
literal|0x00010001
block|,
literal|0x000002ab
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq18,  */
literal|0x010101e6
block|,
literal|0x00010001
block|,
literal|0x000002ac
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq18,  */
literal|0x010101e7
block|,
literal|0x00010001
block|,
literal|0x000002ad
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq18,  */
literal|0x010101e8
block|,
literal|0x00010001
block|,
literal|0x000002ae
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_cmd_cnt_voq19,  */
literal|0x010101e9
block|,
literal|0x00010001
block|,
literal|0x000002af
block|,
comment|/* (r1!=0), r1=pbf.ycmd_qs_occupancy_voq19,  */
literal|0x010101ea
block|,
literal|0x00010001
block|,
literal|0x000002b0
block|,
comment|/* (r1!=0), r1=pbf.btb_allocated_blocks_voq19,  */
literal|0x000001eb
block|,
literal|0x00010002
block|,
literal|0x000002b1
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_1, r2=btb.INT_MASK_1,  */
literal|0x000001ec
block|,
literal|0x00010002
block|,
literal|0x000002b3
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_2, r2=btb.INT_MASK_2,  */
literal|0x000001ed
block|,
literal|0x00010002
block|,
literal|0x000002b5
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_3, r2=btb.INT_MASK_3,  */
literal|0x000001ee
block|,
literal|0x00010002
block|,
literal|0x000002b7
block|,
comment|/* ((r1&~r2)!=0), r1=btb.PRTY_STS_H_0, r2=btb.PRTY_MASK_H_0,  */
literal|0x010101ef
block|,
literal|0x00010001
block|,
literal|0x000302b9
block|,
comment|/* (r1!=15), r1=btb.wc_dup_empty,  */
literal|0x010101f0
block|,
literal|0x00010001
block|,
literal|0x000002ba
block|,
comment|/* (r1!=0), r1=btb.wc_dup_status,  */
literal|0x010101f1
block|,
literal|0x00010001
block|,
literal|0x002a02bb
block|,
comment|/* (r1!=8190), r1=btb.wc_empty_0,  */
literal|0x010201f2
block|,
literal|0x00010001
block|,
literal|0x000002bc
block|,
comment|/* (r1!=0), r1=btb.wc_bandwidth_if_full,  */
literal|0x010201f3
block|,
literal|0x00010001
block|,
literal|0x000002bd
block|,
comment|/* (r1!=0), r1=btb.rc_pkt_if_full,  */
literal|0x010101f4
block|,
literal|0x00010001
block|,
literal|0x002302be
block|,
comment|/* (r1!=255), r1=btb.rc_pkt_empty_0,  */
literal|0x010101f5
block|,
literal|0x00010001
block|,
literal|0x002302bf
block|,
comment|/* (r1!=255), r1=btb.rc_pkt_empty_1,  */
literal|0x010101f6
block|,
literal|0x00010001
block|,
literal|0x002302c0
block|,
comment|/* (r1!=255), r1=btb.rc_pkt_empty_2,  */
literal|0x010101f7
block|,
literal|0x00010001
block|,
literal|0x002302c1
block|,
comment|/* (r1!=255), r1=btb.rc_pkt_empty_3,  */
literal|0x010101f8
block|,
literal|0x00010001
block|,
literal|0x000302c2
block|,
comment|/* (r1!=15), r1=btb.rc_sop_empty,  */
literal|0x010101f9
block|,
literal|0x00010001
block|,
literal|0x000b02c3
block|,
comment|/* (r1!=2), r1=btb.ll_arb_empty,  */
literal|0x020101fa
block|,
literal|0x00010001
block|,
literal|0x002b02c4
block|,
comment|/* (r1>46), r1=btb.block_occupancy,  */
literal|0x010101fb
block|,
literal|0x00010001
block|,
literal|0x000002c5
block|,
comment|/* (r1!=0), r1=btb.rc_pkt_state,  */
literal|0x010101fc
block|,
literal|0x00010001
block|,
literal|0x000b02c6
block|,
comment|/* (r1!=2), r1=btb.wc_status_0 width=3 access=WB,  */
literal|0x000001fd
block|,
literal|0x00010102
block|,
literal|0x000002c7
block|,
comment|/* ((r1&~r2)!=0), r1=xsdm.INT_STS, r2=xsdm.INT_MASK,  */
literal|0x000001fe
block|,
literal|0x00010002
block|,
literal|0x000002ca
block|,
comment|/* ((r1&~r2)!=0), r1=xsdm.PRTY_STS_H_0, r2=xsdm.PRTY_MASK_H_0,  */
literal|0x010101ff
block|,
literal|0x00010001
block|,
literal|0x000002cc
block|,
comment|/* (r1!=0), r1=xsdm.qm_full,  */
literal|0x01010200
block|,
literal|0x00010001
block|,
literal|0x000002cd
block|,
comment|/* (r1!=0), r1=xsdm.rsp_brb_if_full,  */
literal|0x01010201
block|,
literal|0x00010001
block|,
literal|0x000002ce
block|,
comment|/* (r1!=0), r1=xsdm.rsp_pxp_if_full,  */
literal|0x01010202
block|,
literal|0x00010001
block|,
literal|0x000002cf
block|,
comment|/* (r1!=0), r1=xsdm.dst_pxp_if_full,  */
literal|0x01010203
block|,
literal|0x00010001
block|,
literal|0x000002d0
block|,
comment|/* (r1!=0), r1=xsdm.dst_int_ram_if_full,  */
literal|0x01010204
block|,
literal|0x00010001
block|,
literal|0x000002d1
block|,
comment|/* (r1!=0), r1=xsdm.dst_pas_buf_if_full,  */
literal|0x01010205
block|,
literal|0x00010001
block|,
literal|0x000d02d2
block|,
comment|/* (r1!=1), r1=xsdm.int_cmpl_pend_empty,  */
literal|0x01010206
block|,
literal|0x00010001
block|,
literal|0x000d02d3
block|,
comment|/* (r1!=1), r1=xsdm.int_cprm_pend_empty,  */
literal|0x01010207
block|,
literal|0x00010001
block|,
literal|0x002c02d4
block|,
comment|/* (r1!=511), r1=xsdm.queue_empty,  */
literal|0x01010208
block|,
literal|0x00010001
block|,
literal|0x000d02d5
block|,
comment|/* (r1!=1), r1=xsdm.delay_fifo_empty,  */
literal|0x01010209
block|,
literal|0x00010001
block|,
literal|0x000d02d6
block|,
comment|/* (r1!=1), r1=xsdm.rsp_pxp_rdata_empty,  */
literal|0x0101020a
block|,
literal|0x00010001
block|,
literal|0x000d02d7
block|,
comment|/* (r1!=1), r1=xsdm.rsp_brb_rdata_empty,  */
literal|0x0101020b
block|,
literal|0x00010001
block|,
literal|0x000d02d8
block|,
comment|/* (r1!=1), r1=xsdm.rsp_int_ram_rdata_empty,  */
literal|0x0101020c
block|,
literal|0x00010001
block|,
literal|0x000d02d9
block|,
comment|/* (r1!=1), r1=xsdm.rsp_brb_pend_empty,  */
literal|0x0101020d
block|,
literal|0x00010001
block|,
literal|0x000d02da
block|,
comment|/* (r1!=1), r1=xsdm.rsp_int_ram_pend_empty,  */
literal|0x0101020e
block|,
literal|0x00010001
block|,
literal|0x000d02db
block|,
comment|/* (r1!=1), r1=xsdm.dst_pxp_immed_empty,  */
literal|0x0101020f
block|,
literal|0x00010001
block|,
literal|0x000d02dc
block|,
comment|/* (r1!=1), r1=xsdm.dst_pxp_dst_pend_empty,  */
literal|0x01010210
block|,
literal|0x00010001
block|,
literal|0x000d02dd
block|,
comment|/* (r1!=1), r1=xsdm.dst_pxp_src_pend_empty,  */
literal|0x01010211
block|,
literal|0x00010001
block|,
literal|0x000d02de
block|,
comment|/* (r1!=1), r1=xsdm.dst_brb_src_pend_empty,  */
literal|0x01010212
block|,
literal|0x00010001
block|,
literal|0x000d02df
block|,
comment|/* (r1!=1), r1=xsdm.dst_brb_src_addr_empty,  */
literal|0x01010213
block|,
literal|0x00010001
block|,
literal|0x000d02e0
block|,
comment|/* (r1!=1), r1=xsdm.dst_pxp_link_empty,  */
literal|0x01010214
block|,
literal|0x00010001
block|,
literal|0x000d02e1
block|,
comment|/* (r1!=1), r1=xsdm.dst_int_ram_wait_empty,  */
literal|0x01010215
block|,
literal|0x00010001
block|,
literal|0x000d02e2
block|,
comment|/* (r1!=1), r1=xsdm.dst_pas_buf_wait_empty,  */
literal|0x01010216
block|,
literal|0x00010001
block|,
literal|0x000d02e3
block|,
comment|/* (r1!=1), r1=xsdm.sh_delay_empty,  */
literal|0x01010217
block|,
literal|0x00010001
block|,
literal|0x000d02e4
block|,
comment|/* (r1!=1), r1=xsdm.cm_delay_empty,  */
literal|0x01010218
block|,
literal|0x00010001
block|,
literal|0x000d02e5
block|,
comment|/* (r1!=1), r1=xsdm.cmsg_que_empty,  */
literal|0x01010219
block|,
literal|0x00010001
block|,
literal|0x000d02e6
block|,
comment|/* (r1!=1), r1=xsdm.ccfc_load_pend_empty,  */
literal|0x0101021a
block|,
literal|0x00010001
block|,
literal|0x000d02e7
block|,
comment|/* (r1!=1), r1=xsdm.tcfc_load_pend_empty,  */
literal|0x0101021b
block|,
literal|0x00010001
block|,
literal|0x000d02e8
block|,
comment|/* (r1!=1), r1=xsdm.async_host_empty,  */
literal|0x0101021c
block|,
literal|0x00010001
block|,
literal|0x000d02e9
block|,
comment|/* (r1!=1), r1=xsdm.prm_fifo_empty,  */
literal|0x0000021d
block|,
literal|0x00010102
block|,
literal|0x000002ea
block|,
comment|/* ((r1&~r2)!=0), r1=ysdm.INT_STS, r2=ysdm.INT_MASK,  */
literal|0x0000021e
block|,
literal|0x00010002
block|,
literal|0x000002ed
block|,
comment|/* ((r1&~r2)!=0), r1=ysdm.PRTY_STS_H_0, r2=ysdm.PRTY_MASK_H_0,  */
literal|0x0101021f
block|,
literal|0x00010001
block|,
literal|0x000002ef
block|,
comment|/* (r1!=0), r1=ysdm.qm_full,  */
literal|0x01010220
block|,
literal|0x00010001
block|,
literal|0x000002f0
block|,
comment|/* (r1!=0), r1=ysdm.rsp_brb_if_full,  */
literal|0x01010221
block|,
literal|0x00010001
block|,
literal|0x000002f1
block|,
comment|/* (r1!=0), r1=ysdm.rsp_pxp_if_full,  */
literal|0x01010222
block|,
literal|0x00010001
block|,
literal|0x000002f2
block|,
comment|/* (r1!=0), r1=ysdm.dst_pxp_if_full,  */
literal|0x01010223
block|,
literal|0x00010001
block|,
literal|0x000002f3
block|,
comment|/* (r1!=0), r1=ysdm.dst_int_ram_if_full,  */
literal|0x01010224
block|,
literal|0x00010001
block|,
literal|0x000002f4
block|,
comment|/* (r1!=0), r1=ysdm.dst_pas_buf_if_full,  */
literal|0x01010225
block|,
literal|0x00010001
block|,
literal|0x000d02f5
block|,
comment|/* (r1!=1), r1=ysdm.int_cmpl_pend_empty,  */
literal|0x01010226
block|,
literal|0x00010001
block|,
literal|0x000d02f6
block|,
comment|/* (r1!=1), r1=ysdm.int_cprm_pend_empty,  */
literal|0x01010227
block|,
literal|0x00010001
block|,
literal|0x002c02f7
block|,
comment|/* (r1!=511), r1=ysdm.queue_empty,  */
literal|0x01010228
block|,
literal|0x00010001
block|,
literal|0x000d02f8
block|,
comment|/* (r1!=1), r1=ysdm.delay_fifo_empty,  */
literal|0x01010229
block|,
literal|0x00010001
block|,
literal|0x000d02f9
block|,
comment|/* (r1!=1), r1=ysdm.rsp_pxp_rdata_empty,  */
literal|0x0101022a
block|,
literal|0x00010001
block|,
literal|0x000d02fa
block|,
comment|/* (r1!=1), r1=ysdm.rsp_brb_rdata_empty,  */
literal|0x0101022b
block|,
literal|0x00010001
block|,
literal|0x000d02fb
block|,
comment|/* (r1!=1), r1=ysdm.rsp_int_ram_rdata_empty,  */
literal|0x0101022c
block|,
literal|0x00010001
block|,
literal|0x000d02fc
block|,
comment|/* (r1!=1), r1=ysdm.rsp_brb_pend_empty,  */
literal|0x0101022d
block|,
literal|0x00010001
block|,
literal|0x000d02fd
block|,
comment|/* (r1!=1), r1=ysdm.rsp_int_ram_pend_empty,  */
literal|0x0101022e
block|,
literal|0x00010001
block|,
literal|0x000d02fe
block|,
comment|/* (r1!=1), r1=ysdm.dst_pxp_immed_empty,  */
literal|0x0101022f
block|,
literal|0x00010001
block|,
literal|0x000d02ff
block|,
comment|/* (r1!=1), r1=ysdm.dst_pxp_dst_pend_empty,  */
literal|0x01010230
block|,
literal|0x00010001
block|,
literal|0x000d0300
block|,
comment|/* (r1!=1), r1=ysdm.dst_pxp_src_pend_empty,  */
literal|0x01010231
block|,
literal|0x00010001
block|,
literal|0x000d0301
block|,
comment|/* (r1!=1), r1=ysdm.dst_brb_src_pend_empty,  */
literal|0x01010232
block|,
literal|0x00010001
block|,
literal|0x000d0302
block|,
comment|/* (r1!=1), r1=ysdm.dst_brb_src_addr_empty,  */
literal|0x01010233
block|,
literal|0x00010001
block|,
literal|0x000d0303
block|,
comment|/* (r1!=1), r1=ysdm.dst_pxp_link_empty,  */
literal|0x01010234
block|,
literal|0x00010001
block|,
literal|0x000d0304
block|,
comment|/* (r1!=1), r1=ysdm.dst_int_ram_wait_empty,  */
literal|0x01010235
block|,
literal|0x00010001
block|,
literal|0x000d0305
block|,
comment|/* (r1!=1), r1=ysdm.dst_pas_buf_wait_empty,  */
literal|0x01010236
block|,
literal|0x00010001
block|,
literal|0x000d0306
block|,
comment|/* (r1!=1), r1=ysdm.sh_delay_empty,  */
literal|0x01010237
block|,
literal|0x00010001
block|,
literal|0x000d0307
block|,
comment|/* (r1!=1), r1=ysdm.cm_delay_empty,  */
literal|0x01010238
block|,
literal|0x00010001
block|,
literal|0x000d0308
block|,
comment|/* (r1!=1), r1=ysdm.cmsg_que_empty,  */
literal|0x01010239
block|,
literal|0x00010001
block|,
literal|0x000d0309
block|,
comment|/* (r1!=1), r1=ysdm.ccfc_load_pend_empty,  */
literal|0x0101023a
block|,
literal|0x00010001
block|,
literal|0x000d030a
block|,
comment|/* (r1!=1), r1=ysdm.tcfc_load_pend_empty,  */
literal|0x0101023b
block|,
literal|0x00010001
block|,
literal|0x000d030b
block|,
comment|/* (r1!=1), r1=ysdm.async_host_empty,  */
literal|0x0101023c
block|,
literal|0x00010001
block|,
literal|0x000d030c
block|,
comment|/* (r1!=1), r1=ysdm.prm_fifo_empty,  */
literal|0x0000023d
block|,
literal|0x00010102
block|,
literal|0x0000030d
block|,
comment|/* ((r1&~r2)!=0), r1=psdm.INT_STS, r2=psdm.INT_MASK,  */
literal|0x0000023e
block|,
literal|0x00010002
block|,
literal|0x00000310
block|,
comment|/* ((r1&~r2)!=0), r1=psdm.PRTY_STS_H_0, r2=psdm.PRTY_MASK_H_0,  */
literal|0x0101023f
block|,
literal|0x00010001
block|,
literal|0x00000312
block|,
comment|/* (r1!=0), r1=psdm.qm_full,  */
literal|0x01010240
block|,
literal|0x00010001
block|,
literal|0x00000313
block|,
comment|/* (r1!=0), r1=psdm.rsp_brb_if_full,  */
literal|0x01010241
block|,
literal|0x00010001
block|,
literal|0x00000314
block|,
comment|/* (r1!=0), r1=psdm.rsp_pxp_if_full,  */
literal|0x01010242
block|,
literal|0x00010001
block|,
literal|0x00000315
block|,
comment|/* (r1!=0), r1=psdm.dst_pxp_if_full,  */
literal|0x01010243
block|,
literal|0x00010001
block|,
literal|0x00000316
block|,
comment|/* (r1!=0), r1=psdm.dst_int_ram_if_full,  */
literal|0x01010244
block|,
literal|0x00010001
block|,
literal|0x00000317
block|,
comment|/* (r1!=0), r1=psdm.dst_pas_buf_if_full,  */
literal|0x01010245
block|,
literal|0x00010001
block|,
literal|0x000d0318
block|,
comment|/* (r1!=1), r1=psdm.int_cmpl_pend_empty,  */
literal|0x01010246
block|,
literal|0x00010001
block|,
literal|0x000d0319
block|,
comment|/* (r1!=1), r1=psdm.int_cprm_pend_empty,  */
literal|0x01010247
block|,
literal|0x00010001
block|,
literal|0x002c031a
block|,
comment|/* (r1!=511), r1=psdm.queue_empty,  */
literal|0x01010248
block|,
literal|0x00010001
block|,
literal|0x000d031b
block|,
comment|/* (r1!=1), r1=psdm.delay_fifo_empty,  */
literal|0x01010249
block|,
literal|0x00010001
block|,
literal|0x000d031c
block|,
comment|/* (r1!=1), r1=psdm.rsp_pxp_rdata_empty,  */
literal|0x0101024a
block|,
literal|0x00010001
block|,
literal|0x000d031d
block|,
comment|/* (r1!=1), r1=psdm.rsp_brb_rdata_empty,  */
literal|0x0101024b
block|,
literal|0x00010001
block|,
literal|0x000d031e
block|,
comment|/* (r1!=1), r1=psdm.rsp_int_ram_rdata_empty,  */
literal|0x0101024c
block|,
literal|0x00010001
block|,
literal|0x000d031f
block|,
comment|/* (r1!=1), r1=psdm.rsp_brb_pend_empty,  */
literal|0x0101024d
block|,
literal|0x00010001
block|,
literal|0x000d0320
block|,
comment|/* (r1!=1), r1=psdm.rsp_int_ram_pend_empty,  */
literal|0x0101024e
block|,
literal|0x00010001
block|,
literal|0x000d0321
block|,
comment|/* (r1!=1), r1=psdm.dst_pxp_immed_empty,  */
literal|0x0101024f
block|,
literal|0x00010001
block|,
literal|0x000d0322
block|,
comment|/* (r1!=1), r1=psdm.dst_pxp_dst_pend_empty,  */
literal|0x01010250
block|,
literal|0x00010001
block|,
literal|0x000d0323
block|,
comment|/* (r1!=1), r1=psdm.dst_pxp_src_pend_empty,  */
literal|0x01010251
block|,
literal|0x00010001
block|,
literal|0x000d0324
block|,
comment|/* (r1!=1), r1=psdm.dst_brb_src_pend_empty,  */
literal|0x01010252
block|,
literal|0x00010001
block|,
literal|0x000d0325
block|,
comment|/* (r1!=1), r1=psdm.dst_brb_src_addr_empty,  */
literal|0x01010253
block|,
literal|0x00010001
block|,
literal|0x000d0326
block|,
comment|/* (r1!=1), r1=psdm.dst_pxp_link_empty,  */
literal|0x01010254
block|,
literal|0x00010001
block|,
literal|0x000d0327
block|,
comment|/* (r1!=1), r1=psdm.dst_int_ram_wait_empty,  */
literal|0x01010255
block|,
literal|0x00010001
block|,
literal|0x000d0328
block|,
comment|/* (r1!=1), r1=psdm.dst_pas_buf_wait_empty,  */
literal|0x01010256
block|,
literal|0x00010001
block|,
literal|0x000d0329
block|,
comment|/* (r1!=1), r1=psdm.sh_delay_empty,  */
literal|0x01010257
block|,
literal|0x00010001
block|,
literal|0x000d032a
block|,
comment|/* (r1!=1), r1=psdm.cm_delay_empty,  */
literal|0x01010258
block|,
literal|0x00010001
block|,
literal|0x000d032b
block|,
comment|/* (r1!=1), r1=psdm.cmsg_que_empty,  */
literal|0x01010259
block|,
literal|0x00010001
block|,
literal|0x000d032c
block|,
comment|/* (r1!=1), r1=psdm.ccfc_load_pend_empty,  */
literal|0x0101025a
block|,
literal|0x00010001
block|,
literal|0x000d032d
block|,
comment|/* (r1!=1), r1=psdm.tcfc_load_pend_empty,  */
literal|0x0101025b
block|,
literal|0x00010001
block|,
literal|0x000d032e
block|,
comment|/* (r1!=1), r1=psdm.async_host_empty,  */
literal|0x0101025c
block|,
literal|0x00010001
block|,
literal|0x000d032f
block|,
comment|/* (r1!=1), r1=psdm.prm_fifo_empty,  */
literal|0x0000025d
block|,
literal|0x00010102
block|,
literal|0x00000330
block|,
comment|/* ((r1&~r2)!=0), r1=tsdm.INT_STS, r2=tsdm.INT_MASK,  */
literal|0x0000025e
block|,
literal|0x00010002
block|,
literal|0x00000333
block|,
comment|/* ((r1&~r2)!=0), r1=tsdm.PRTY_STS_H_0, r2=tsdm.PRTY_MASK_H_0,  */
literal|0x0101025f
block|,
literal|0x00010001
block|,
literal|0x00000335
block|,
comment|/* (r1!=0), r1=tsdm.qm_full,  */
literal|0x01010260
block|,
literal|0x00010001
block|,
literal|0x00000336
block|,
comment|/* (r1!=0), r1=tsdm.rsp_brb_if_full,  */
literal|0x01010261
block|,
literal|0x00010001
block|,
literal|0x00000337
block|,
comment|/* (r1!=0), r1=tsdm.rsp_pxp_if_full,  */
literal|0x01010262
block|,
literal|0x00010001
block|,
literal|0x00000338
block|,
comment|/* (r1!=0), r1=tsdm.dst_pxp_if_full,  */
literal|0x01010263
block|,
literal|0x00010001
block|,
literal|0x00000339
block|,
comment|/* (r1!=0), r1=tsdm.dst_int_ram_if_full,  */
literal|0x01010264
block|,
literal|0x00010001
block|,
literal|0x0000033a
block|,
comment|/* (r1!=0), r1=tsdm.dst_pas_buf_if_full,  */
literal|0x01010265
block|,
literal|0x00010001
block|,
literal|0x000d033b
block|,
comment|/* (r1!=1), r1=tsdm.int_cmpl_pend_empty,  */
literal|0x01010266
block|,
literal|0x00010001
block|,
literal|0x000d033c
block|,
comment|/* (r1!=1), r1=tsdm.int_cprm_pend_empty,  */
literal|0x01010267
block|,
literal|0x00010001
block|,
literal|0x002c033d
block|,
comment|/* (r1!=511), r1=tsdm.queue_empty,  */
literal|0x01010268
block|,
literal|0x00010001
block|,
literal|0x000d033e
block|,
comment|/* (r1!=1), r1=tsdm.delay_fifo_empty,  */
literal|0x01010269
block|,
literal|0x00010001
block|,
literal|0x000d033f
block|,
comment|/* (r1!=1), r1=tsdm.rsp_pxp_rdata_empty,  */
literal|0x0101026a
block|,
literal|0x00010001
block|,
literal|0x000d0340
block|,
comment|/* (r1!=1), r1=tsdm.rsp_brb_rdata_empty,  */
literal|0x0101026b
block|,
literal|0x00010001
block|,
literal|0x000d0341
block|,
comment|/* (r1!=1), r1=tsdm.rsp_int_ram_rdata_empty,  */
literal|0x0101026c
block|,
literal|0x00010001
block|,
literal|0x000d0342
block|,
comment|/* (r1!=1), r1=tsdm.rsp_brb_pend_empty,  */
literal|0x0101026d
block|,
literal|0x00010001
block|,
literal|0x000d0343
block|,
comment|/* (r1!=1), r1=tsdm.rsp_int_ram_pend_empty,  */
literal|0x0101026e
block|,
literal|0x00010001
block|,
literal|0x000d0344
block|,
comment|/* (r1!=1), r1=tsdm.dst_pxp_immed_empty,  */
literal|0x0101026f
block|,
literal|0x00010001
block|,
literal|0x000d0345
block|,
comment|/* (r1!=1), r1=tsdm.dst_pxp_dst_pend_empty,  */
literal|0x01010270
block|,
literal|0x00010001
block|,
literal|0x000d0346
block|,
comment|/* (r1!=1), r1=tsdm.dst_pxp_src_pend_empty,  */
literal|0x01010271
block|,
literal|0x00010001
block|,
literal|0x000d0347
block|,
comment|/* (r1!=1), r1=tsdm.dst_brb_src_pend_empty,  */
literal|0x01010272
block|,
literal|0x00010001
block|,
literal|0x000d0348
block|,
comment|/* (r1!=1), r1=tsdm.dst_brb_src_addr_empty,  */
literal|0x01010273
block|,
literal|0x00010001
block|,
literal|0x000d0349
block|,
comment|/* (r1!=1), r1=tsdm.dst_pxp_link_empty,  */
literal|0x01010274
block|,
literal|0x00010001
block|,
literal|0x000d034a
block|,
comment|/* (r1!=1), r1=tsdm.dst_int_ram_wait_empty,  */
literal|0x01010275
block|,
literal|0x00010001
block|,
literal|0x000d034b
block|,
comment|/* (r1!=1), r1=tsdm.dst_pas_buf_wait_empty,  */
literal|0x01010276
block|,
literal|0x00010001
block|,
literal|0x000d034c
block|,
comment|/* (r1!=1), r1=tsdm.sh_delay_empty,  */
literal|0x01010277
block|,
literal|0x00010001
block|,
literal|0x000d034d
block|,
comment|/* (r1!=1), r1=tsdm.cm_delay_empty,  */
literal|0x01010278
block|,
literal|0x00010001
block|,
literal|0x000d034e
block|,
comment|/* (r1!=1), r1=tsdm.cmsg_que_empty,  */
literal|0x01010279
block|,
literal|0x00010001
block|,
literal|0x000d034f
block|,
comment|/* (r1!=1), r1=tsdm.ccfc_load_pend_empty,  */
literal|0x0101027a
block|,
literal|0x00010001
block|,
literal|0x000d0350
block|,
comment|/* (r1!=1), r1=tsdm.tcfc_load_pend_empty,  */
literal|0x0101027b
block|,
literal|0x00010001
block|,
literal|0x000d0351
block|,
comment|/* (r1!=1), r1=tsdm.async_host_empty,  */
literal|0x0101027c
block|,
literal|0x00010001
block|,
literal|0x000d0352
block|,
comment|/* (r1!=1), r1=tsdm.prm_fifo_empty,  */
literal|0x0000027d
block|,
literal|0x00010102
block|,
literal|0x00000353
block|,
comment|/* ((r1&~r2)!=0), r1=msdm.INT_STS, r2=msdm.INT_MASK,  */
literal|0x0000027e
block|,
literal|0x00010002
block|,
literal|0x00000356
block|,
comment|/* ((r1&~r2)!=0), r1=msdm.PRTY_STS_H_0, r2=msdm.PRTY_MASK_H_0,  */
literal|0x0101027f
block|,
literal|0x00010001
block|,
literal|0x00000358
block|,
comment|/* (r1!=0), r1=msdm.qm_full,  */
literal|0x01010280
block|,
literal|0x00010001
block|,
literal|0x00000359
block|,
comment|/* (r1!=0), r1=msdm.rsp_brb_if_full,  */
literal|0x01010281
block|,
literal|0x00010001
block|,
literal|0x0000035a
block|,
comment|/* (r1!=0), r1=msdm.rsp_pxp_if_full,  */
literal|0x01010282
block|,
literal|0x00010001
block|,
literal|0x0000035b
block|,
comment|/* (r1!=0), r1=msdm.dst_pxp_if_full,  */
literal|0x01010283
block|,
literal|0x00010001
block|,
literal|0x0000035c
block|,
comment|/* (r1!=0), r1=msdm.dst_int_ram_if_full,  */
literal|0x01010284
block|,
literal|0x00010001
block|,
literal|0x0000035d
block|,
comment|/* (r1!=0), r1=msdm.dst_pas_buf_if_full,  */
literal|0x01010285
block|,
literal|0x00010001
block|,
literal|0x000d035e
block|,
comment|/* (r1!=1), r1=msdm.int_cmpl_pend_empty,  */
literal|0x01010286
block|,
literal|0x00010001
block|,
literal|0x000d035f
block|,
comment|/* (r1!=1), r1=msdm.int_cprm_pend_empty,  */
literal|0x01010287
block|,
literal|0x00010001
block|,
literal|0x002c0360
block|,
comment|/* (r1!=511), r1=msdm.queue_empty,  */
literal|0x01010288
block|,
literal|0x00010001
block|,
literal|0x000d0361
block|,
comment|/* (r1!=1), r1=msdm.delay_fifo_empty,  */
literal|0x01010289
block|,
literal|0x00010001
block|,
literal|0x000d0362
block|,
comment|/* (r1!=1), r1=msdm.rsp_pxp_rdata_empty,  */
literal|0x0101028a
block|,
literal|0x00010001
block|,
literal|0x000d0363
block|,
comment|/* (r1!=1), r1=msdm.rsp_brb_rdata_empty,  */
literal|0x0101028b
block|,
literal|0x00010001
block|,
literal|0x000d0364
block|,
comment|/* (r1!=1), r1=msdm.rsp_int_ram_rdata_empty,  */
literal|0x0101028c
block|,
literal|0x00010001
block|,
literal|0x000d0365
block|,
comment|/* (r1!=1), r1=msdm.rsp_brb_pend_empty,  */
literal|0x0101028d
block|,
literal|0x00010001
block|,
literal|0x000d0366
block|,
comment|/* (r1!=1), r1=msdm.rsp_int_ram_pend_empty,  */
literal|0x0101028e
block|,
literal|0x00010001
block|,
literal|0x000d0367
block|,
comment|/* (r1!=1), r1=msdm.dst_pxp_immed_empty,  */
literal|0x0101028f
block|,
literal|0x00010001
block|,
literal|0x000d0368
block|,
comment|/* (r1!=1), r1=msdm.dst_pxp_dst_pend_empty,  */
literal|0x01010290
block|,
literal|0x00010001
block|,
literal|0x000d0369
block|,
comment|/* (r1!=1), r1=msdm.dst_pxp_src_pend_empty,  */
literal|0x01010291
block|,
literal|0x00010001
block|,
literal|0x000d036a
block|,
comment|/* (r1!=1), r1=msdm.dst_brb_src_pend_empty,  */
literal|0x01010292
block|,
literal|0x00010001
block|,
literal|0x000d036b
block|,
comment|/* (r1!=1), r1=msdm.dst_brb_src_addr_empty,  */
literal|0x01010293
block|,
literal|0x00010001
block|,
literal|0x000d036c
block|,
comment|/* (r1!=1), r1=msdm.dst_pxp_link_empty,  */
literal|0x01010294
block|,
literal|0x00010001
block|,
literal|0x000d036d
block|,
comment|/* (r1!=1), r1=msdm.dst_int_ram_wait_empty,  */
literal|0x01010295
block|,
literal|0x00010001
block|,
literal|0x000d036e
block|,
comment|/* (r1!=1), r1=msdm.dst_pas_buf_wait_empty,  */
literal|0x01010296
block|,
literal|0x00010001
block|,
literal|0x000d036f
block|,
comment|/* (r1!=1), r1=msdm.sh_delay_empty,  */
literal|0x01010297
block|,
literal|0x00010001
block|,
literal|0x000d0370
block|,
comment|/* (r1!=1), r1=msdm.cm_delay_empty,  */
literal|0x01010298
block|,
literal|0x00010001
block|,
literal|0x000d0371
block|,
comment|/* (r1!=1), r1=msdm.cmsg_que_empty,  */
literal|0x01010299
block|,
literal|0x00010001
block|,
literal|0x000d0372
block|,
comment|/* (r1!=1), r1=msdm.ccfc_load_pend_empty,  */
literal|0x0101029a
block|,
literal|0x00010001
block|,
literal|0x000d0373
block|,
comment|/* (r1!=1), r1=msdm.tcfc_load_pend_empty,  */
literal|0x0101029b
block|,
literal|0x00010001
block|,
literal|0x000d0374
block|,
comment|/* (r1!=1), r1=msdm.async_host_empty,  */
literal|0x0101029c
block|,
literal|0x00010001
block|,
literal|0x000d0375
block|,
comment|/* (r1!=1), r1=msdm.prm_fifo_empty,  */
literal|0x0000029d
block|,
literal|0x00010102
block|,
literal|0x00000376
block|,
comment|/* ((r1&~r2)!=0), r1=usdm.INT_STS, r2=usdm.INT_MASK,  */
literal|0x0000029e
block|,
literal|0x00010002
block|,
literal|0x00000379
block|,
comment|/* ((r1&~r2)!=0), r1=usdm.PRTY_STS_H_0, r2=usdm.PRTY_MASK_H_0,  */
literal|0x0101029f
block|,
literal|0x00010001
block|,
literal|0x0000037b
block|,
comment|/* (r1!=0), r1=usdm.qm_full,  */
literal|0x010102a0
block|,
literal|0x00010001
block|,
literal|0x0000037c
block|,
comment|/* (r1!=0), r1=usdm.rsp_brb_if_full,  */
literal|0x010102a1
block|,
literal|0x00010001
block|,
literal|0x0000037d
block|,
comment|/* (r1!=0), r1=usdm.rsp_pxp_if_full,  */
literal|0x010102a2
block|,
literal|0x00010001
block|,
literal|0x0000037e
block|,
comment|/* (r1!=0), r1=usdm.dst_pxp_if_full,  */
literal|0x010102a3
block|,
literal|0x00010001
block|,
literal|0x0000037f
block|,
comment|/* (r1!=0), r1=usdm.dst_int_ram_if_full,  */
literal|0x010102a4
block|,
literal|0x00010001
block|,
literal|0x00000380
block|,
comment|/* (r1!=0), r1=usdm.dst_pas_buf_if_full,  */
literal|0x010102a5
block|,
literal|0x00010001
block|,
literal|0x000d0381
block|,
comment|/* (r1!=1), r1=usdm.int_cmpl_pend_empty,  */
literal|0x010102a6
block|,
literal|0x00010001
block|,
literal|0x000d0382
block|,
comment|/* (r1!=1), r1=usdm.int_cprm_pend_empty,  */
literal|0x010102a7
block|,
literal|0x00010001
block|,
literal|0x002c0383
block|,
comment|/* (r1!=511), r1=usdm.queue_empty,  */
literal|0x010102a8
block|,
literal|0x00010001
block|,
literal|0x000d0384
block|,
comment|/* (r1!=1), r1=usdm.delay_fifo_empty,  */
literal|0x010102a9
block|,
literal|0x00010001
block|,
literal|0x000d0385
block|,
comment|/* (r1!=1), r1=usdm.rsp_pxp_rdata_empty,  */
literal|0x010102aa
block|,
literal|0x00010001
block|,
literal|0x000d0386
block|,
comment|/* (r1!=1), r1=usdm.rsp_brb_rdata_empty,  */
literal|0x010102ab
block|,
literal|0x00010001
block|,
literal|0x000d0387
block|,
comment|/* (r1!=1), r1=usdm.rsp_int_ram_rdata_empty,  */
literal|0x010102ac
block|,
literal|0x00010001
block|,
literal|0x000d0388
block|,
comment|/* (r1!=1), r1=usdm.rsp_brb_pend_empty,  */
literal|0x010102ad
block|,
literal|0x00010001
block|,
literal|0x000d0389
block|,
comment|/* (r1!=1), r1=usdm.rsp_int_ram_pend_empty,  */
literal|0x010102ae
block|,
literal|0x00010001
block|,
literal|0x000d038a
block|,
comment|/* (r1!=1), r1=usdm.dst_pxp_immed_empty,  */
literal|0x010102af
block|,
literal|0x00010001
block|,
literal|0x000d038b
block|,
comment|/* (r1!=1), r1=usdm.dst_pxp_dst_pend_empty,  */
literal|0x010102b0
block|,
literal|0x00010001
block|,
literal|0x000d038c
block|,
comment|/* (r1!=1), r1=usdm.dst_pxp_src_pend_empty,  */
literal|0x010102b1
block|,
literal|0x00010001
block|,
literal|0x000d038d
block|,
comment|/* (r1!=1), r1=usdm.dst_brb_src_pend_empty,  */
literal|0x010102b2
block|,
literal|0x00010001
block|,
literal|0x000d038e
block|,
comment|/* (r1!=1), r1=usdm.dst_brb_src_addr_empty,  */
literal|0x010102b3
block|,
literal|0x00010001
block|,
literal|0x000d038f
block|,
comment|/* (r1!=1), r1=usdm.dst_pxp_link_empty,  */
literal|0x010102b4
block|,
literal|0x00010001
block|,
literal|0x000d0390
block|,
comment|/* (r1!=1), r1=usdm.dst_int_ram_wait_empty,  */
literal|0x010102b5
block|,
literal|0x00010001
block|,
literal|0x000d0391
block|,
comment|/* (r1!=1), r1=usdm.dst_pas_buf_wait_empty,  */
literal|0x010102b6
block|,
literal|0x00010001
block|,
literal|0x000d0392
block|,
comment|/* (r1!=1), r1=usdm.sh_delay_empty,  */
literal|0x010102b7
block|,
literal|0x00010001
block|,
literal|0x000d0393
block|,
comment|/* (r1!=1), r1=usdm.cm_delay_empty,  */
literal|0x010102b8
block|,
literal|0x00010001
block|,
literal|0x000d0394
block|,
comment|/* (r1!=1), r1=usdm.cmsg_que_empty,  */
literal|0x010102b9
block|,
literal|0x00010001
block|,
literal|0x000d0395
block|,
comment|/* (r1!=1), r1=usdm.ccfc_load_pend_empty,  */
literal|0x010102ba
block|,
literal|0x00010001
block|,
literal|0x000d0396
block|,
comment|/* (r1!=1), r1=usdm.tcfc_load_pend_empty,  */
literal|0x010102bb
block|,
literal|0x00010001
block|,
literal|0x000d0397
block|,
comment|/* (r1!=1), r1=usdm.async_host_empty,  */
literal|0x010102bc
block|,
literal|0x00010001
block|,
literal|0x000d0398
block|,
comment|/* (r1!=1), r1=usdm.prm_fifo_empty,  */
literal|0x000002bd
block|,
literal|0x00010002
block|,
literal|0x00000399
block|,
comment|/* ((r1&~r2)!=0), r1=xcm.INT_STS_0, r2=xcm.INT_MASK_0,  */
literal|0x000002be
block|,
literal|0x00010002
block|,
literal|0x0000039b
block|,
comment|/* ((r1&~r2)!=0), r1=xcm.INT_STS_1, r2=xcm.INT_MASK_1,  */
literal|0x000002bf
block|,
literal|0x00010102
block|,
literal|0x0000039d
block|,
comment|/* ((r1&~r2)!=0), r1=xcm.INT_STS_2, r2=xcm.INT_MASK_2,  */
literal|0x000002c0
block|,
literal|0x00010002
block|,
literal|0x000003a0
block|,
comment|/* ((r1&~r2)!=0), r1=xcm.PRTY_STS_H_0, r2=xcm.PRTY_MASK_H_0,  */
literal|0x000002c1
block|,
literal|0x00010002
block|,
literal|0x000003a2
block|,
comment|/* ((r1&~r2)!=0), r1=xcm.PRTY_STS_H_1, r2=xcm.PRTY_MASK_H_1,  */
literal|0x010002c2
block|,
literal|0x00010001
block|,
literal|0x000003a4
block|,
comment|/* (r1!=0), r1=xcm.fi_desc_input_violate,  */
literal|0x010102c3
block|,
literal|0x00010001
block|,
literal|0x000003a5
block|,
comment|/* (r1!=0), r1=xcm.ia_agg_con_part_fill_lvl,  */
literal|0x010102c4
block|,
literal|0x00010001
block|,
literal|0x000003a6
block|,
comment|/* (r1!=0), r1=xcm.ia_sm_con_part_fill_lvl,  */
literal|0x010102c5
block|,
literal|0x00010001
block|,
literal|0x000003a7
block|,
comment|/* (r1!=0), r1=xcm.ia_trans_part_fill_lvl,  */
literal|0x010102c6
block|,
literal|0x00010001
block|,
literal|0x002d03a8
block|,
comment|/* (r1!=reset1), r1=xcm.xx_free_cnt,  */
literal|0x010102c7
block|,
literal|0x00010001
block|,
literal|0x000003a9
block|,
comment|/* (r1!=0), r1=xcm.xx_lcid_cam_fill_lvl,  */
literal|0x010102c8
block|,
literal|0x00010001
block|,
literal|0x000003aa
block|,
comment|/* (r1!=0), r1=xcm.xx_lock_cnt,  */
literal|0x010102c9
block|,
literal|0x00010001
block|,
literal|0x000003ab
block|,
comment|/* (r1!=0), r1=xcm.xx_cbyp_tbl_fill_lvl,  */
literal|0x010102ca
block|,
literal|0x00010001
block|,
literal|0x000003ac
block|,
comment|/* (r1!=0), r1=xcm.agg_con_fic_buf_fill_lvl,  */
literal|0x010102cb
block|,
literal|0x00010001
block|,
literal|0x000003ad
block|,
comment|/* (r1!=0), r1=xcm.sm_con_fic_buf_fill_lvl,  */
literal|0x010102cc
block|,
literal|0x00010001
block|,
literal|0x000003ae
block|,
comment|/* (r1!=0), r1=xcm.in_prcs_tbl_fill_lvl,  */
literal|0x010102cd
block|,
literal|0x00010001
block|,
literal|0x000d03af
block|,
comment|/* (r1!=reset1), r1=xcm.ccfc_init_crd,  */
literal|0x010102ce
block|,
literal|0x00010001
block|,
literal|0x000a03b0
block|,
comment|/* (r1!=reset1), r1=xcm.qm_init_crd0,  */
literal|0x010102cf
block|,
literal|0x00010001
block|,
literal|0x000a03b1
block|,
comment|/* (r1!=reset1), r1=xcm.qm_init_crd1,  */
literal|0x010102d0
block|,
literal|0x00010001
block|,
literal|0x001103b2
block|,
comment|/* (r1!=reset1), r1=xcm.tm_init_crd,  */
literal|0x010102d1
block|,
literal|0x00010001
block|,
literal|0x002e03b3
block|,
comment|/* (r1!=reset1), r1=xcm.fic_init_crd,  */
literal|0x010002d2
block|,
literal|0x00010001
block|,
literal|0x000003b4
block|,
comment|/* (r1!=0), r1=xcm.xsdm_length_mis,  */
literal|0x010002d3
block|,
literal|0x00010001
block|,
literal|0x000003b5
block|,
comment|/* (r1!=0), r1=xcm.ysdm_length_mis,  */
literal|0x010002d4
block|,
literal|0x00010001
block|,
literal|0x000003b6
block|,
comment|/* (r1!=0), r1=xcm.dorq_length_mis,  */
literal|0x010002d5
block|,
literal|0x00010001
block|,
literal|0x000003b7
block|,
comment|/* (r1!=0), r1=xcm.pbf_length_mis,  */
literal|0x010102d6
block|,
literal|0x00010001
block|,
literal|0x000003b8
block|,
comment|/* (r1!=0), r1=xcm.is_qm_p_fill_lvl,  */
literal|0x010102d7
block|,
literal|0x00010001
block|,
literal|0x000003b9
block|,
comment|/* (r1!=0), r1=xcm.is_qm_s_fill_lvl,  */
literal|0x010102d8
block|,
literal|0x00010001
block|,
literal|0x000003ba
block|,
comment|/* (r1!=0), r1=xcm.is_tm_fill_lvl,  */
literal|0x010102d9
block|,
literal|0x00010001
block|,
literal|0x000003bb
block|,
comment|/* (r1!=0), r1=xcm.is_storm_fill_lvl,  */
literal|0x010102da
block|,
literal|0x00010001
block|,
literal|0x000003bc
block|,
comment|/* (r1!=0), r1=xcm.is_xsdm_fill_lvl,  */
literal|0x010102db
block|,
literal|0x00010001
block|,
literal|0x000003bd
block|,
comment|/* (r1!=0), r1=xcm.is_ysdm_fill_lvl,  */
literal|0x010102dc
block|,
literal|0x00010001
block|,
literal|0x000003be
block|,
comment|/* (r1!=0), r1=xcm.is_msem_fill_lvl,  */
literal|0x010102dd
block|,
literal|0x00010001
block|,
literal|0x000003bf
block|,
comment|/* (r1!=0), r1=xcm.is_usem_fill_lvl,  */
literal|0x010102de
block|,
literal|0x00010001
block|,
literal|0x000003c0
block|,
comment|/* (r1!=0), r1=xcm.is_dorq_fill_lvl,  */
literal|0x010102df
block|,
literal|0x00010001
block|,
literal|0x000003c1
block|,
comment|/* (r1!=0), r1=xcm.is_pbf_fill_lvl,  */
literal|0x000002e0
block|,
literal|0x00010002
block|,
literal|0x000003c2
block|,
comment|/* ((r1&~r2)!=0), r1=ycm.INT_STS_0, r2=ycm.INT_MASK_0,  */
literal|0x000002e1
block|,
literal|0x00010002
block|,
literal|0x000003c4
block|,
comment|/* ((r1&~r2)!=0), r1=ycm.INT_STS_1, r2=ycm.INT_MASK_1,  */
literal|0x000002e2
block|,
literal|0x00010002
block|,
literal|0x000003c6
block|,
comment|/* ((r1&~r2)!=0), r1=ycm.PRTY_STS_H_0, r2=ycm.PRTY_MASK_H_0,  */
literal|0x000002e3
block|,
literal|0x00010002
block|,
literal|0x000003c8
block|,
comment|/* ((r1&~r2)!=0), r1=ycm.PRTY_STS_H_1, r2=ycm.PRTY_MASK_H_1,  */
literal|0x010002e4
block|,
literal|0x00010001
block|,
literal|0x000003ca
block|,
comment|/* (r1!=0), r1=ycm.fi_desc_input_violate,  */
literal|0x010002e5
block|,
literal|0x00010001
block|,
literal|0x000003cb
block|,
comment|/* (r1!=0), r1=ycm.se_desc_input_violate,  */
literal|0x010102e6
block|,
literal|0x00010001
block|,
literal|0x000003cc
block|,
comment|/* (r1!=0), r1=ycm.ia_sm_con_part_fill_lvl,  */
literal|0x010102e7
block|,
literal|0x00010001
block|,
literal|0x000003cd
block|,
comment|/* (r1!=0), r1=ycm.ia_agg_task_part_fill_lvl,  */
literal|0x010102e8
block|,
literal|0x00010001
block|,
literal|0x000003ce
block|,
comment|/* (r1!=0), r1=ycm.ia_sm_task_part_fill_lvl,  */
literal|0x010102e9
block|,
literal|0x00010001
block|,
literal|0x000003cf
block|,
comment|/* (r1!=0), r1=ycm.ia_trans_part_fill_lvl,  */
literal|0x010102ea
block|,
literal|0x00010001
block|,
literal|0x002d03d0
block|,
comment|/* (r1!=reset1), r1=ycm.xx_free_cnt,  */
literal|0x010102eb
block|,
literal|0x00010001
block|,
literal|0x000003d1
block|,
comment|/* (r1!=0), r1=ycm.xx_lcid_cam_fill_lvl,  */
literal|0x010102ec
block|,
literal|0x00010001
block|,
literal|0x000003d2
block|,
comment|/* (r1!=0), r1=ycm.xx_lock_cnt,  */
literal|0x010102ed
block|,
literal|0x00010001
block|,
literal|0x000003d3
block|,
comment|/* (r1!=0), r1=ycm.xx_cbyp_tbl_fill_lvl,  */
literal|0x010102ee
block|,
literal|0x00010001
block|,
literal|0x000003d4
block|,
comment|/* (r1!=0), r1=ycm.xx_tbyp_tbl_fill_lvl,  */
literal|0x010102ef
block|,
literal|0x00010001
block|,
literal|0x000003d5
block|,
comment|/* (r1!=0), r1=ycm.xx_tbyp_tbl_fill_lvl,  */
literal|0x010102f0
block|,
literal|0x00010001
block|,
literal|0x000003d6
block|,
comment|/* (r1!=0), r1=ycm.sm_con_fic_buf_fill_lvl,  */
literal|0x010102f1
block|,
literal|0x00010001
block|,
literal|0x000003d7
block|,
comment|/* (r1!=0), r1=ycm.agg_task_fic_buf_fill_lvl,  */
literal|0x010102f2
block|,
literal|0x00010001
block|,
literal|0x000003d8
block|,
comment|/* (r1!=0), r1=ycm.sm_task_fic_buf_fill_lvl,  */
literal|0x010102f3
block|,
literal|0x00010001
block|,
literal|0x000003d9
block|,
comment|/* (r1!=0), r1=ycm.in_prcs_tbl_fill_lvl,  */
literal|0x010102f4
block|,
literal|0x00010001
block|,
literal|0x000d03da
block|,
comment|/* (r1!=reset1), r1=ycm.ccfc_init_crd,  */
literal|0x010102f5
block|,
literal|0x00010001
block|,
literal|0x000d03db
block|,
comment|/* (r1!=reset1), r1=ycm.tcfc_init_crd,  */
literal|0x010102f6
block|,
literal|0x00010001
block|,
literal|0x000a03dc
block|,
comment|/* (r1!=reset1), r1=ycm.qm_init_crd0,  */
literal|0x010102f7
block|,
literal|0x00010001
block|,
literal|0x002f03dd
block|,
comment|/* (r1!=reset1), r1=ycm.fic_init_crd,  */
literal|0x010002f8
block|,
literal|0x00010001
block|,
literal|0x000003de
block|,
comment|/* (r1!=0), r1=ycm.ysdm_length_mis,  */
literal|0x010002f9
block|,
literal|0x00010001
block|,
literal|0x000003df
block|,
comment|/* (r1!=0), r1=ycm.pbf_length_mis,  */
literal|0x010002fa
block|,
literal|0x00010001
block|,
literal|0x000003e0
block|,
comment|/* (r1!=0), r1=ycm.xyld_length_mis,  */
literal|0x010102fb
block|,
literal|0x00010001
block|,
literal|0x000003e1
block|,
comment|/* (r1!=0), r1=ycm.is_qm_p_fill_lvl,  */
literal|0x010102fc
block|,
literal|0x00010001
block|,
literal|0x000003e2
block|,
comment|/* (r1!=0), r1=ycm.is_qm_s_fill_lvl,  */
literal|0x010102fd
block|,
literal|0x00010001
block|,
literal|0x000003e3
block|,
comment|/* (r1!=0), r1=ycm.is_storm_fill_lvl,  */
literal|0x010102fe
block|,
literal|0x00010001
block|,
literal|0x000003e4
block|,
comment|/* (r1!=0), r1=ycm.is_ysdm_fill_lvl,  */
literal|0x010102ff
block|,
literal|0x00010001
block|,
literal|0x000003e5
block|,
comment|/* (r1!=0), r1=ycm.is_xyld_fill_lvl,  */
literal|0x01010300
block|,
literal|0x00010001
block|,
literal|0x000003e6
block|,
comment|/* (r1!=0), r1=ycm.is_msem_fill_lvl,  */
literal|0x01010301
block|,
literal|0x00010001
block|,
literal|0x000003e7
block|,
comment|/* (r1!=0), r1=ycm.is_usem_fill_lvl,  */
literal|0x01010302
block|,
literal|0x00010001
block|,
literal|0x000003e8
block|,
comment|/* (r1!=0), r1=ycm.is_pbf_fill_lvl,  */
literal|0x00000303
block|,
literal|0x00010002
block|,
literal|0x000003e9
block|,
comment|/* ((r1&~r2)!=0), r1=pcm.INT_STS_0, r2=pcm.INT_MASK_0,  */
literal|0x00000304
block|,
literal|0x00010002
block|,
literal|0x000003eb
block|,
comment|/* ((r1&~r2)!=0), r1=pcm.INT_STS_1, r2=pcm.INT_MASK_1,  */
literal|0x00000305
block|,
literal|0x00010002
block|,
literal|0x000003ed
block|,
comment|/* ((r1&~r2)!=0), r1=pcm.PRTY_STS_H_0, r2=pcm.PRTY_MASK_H_0,  */
literal|0x01000306
block|,
literal|0x00010001
block|,
literal|0x000003ef
block|,
comment|/* (r1!=0), r1=pcm.fi_desc_input_violate,  */
literal|0x01010307
block|,
literal|0x00010001
block|,
literal|0x000003f0
block|,
comment|/* (r1!=0), r1=pcm.ia_sm_con_part_fill_lvl,  */
literal|0x01010308
block|,
literal|0x00010001
block|,
literal|0x000003f1
block|,
comment|/* (r1!=0), r1=pcm.ia_trans_part_fill_lvl,  */
literal|0x01010309
block|,
literal|0x00010001
block|,
literal|0x001103f2
block|,
comment|/* (r1!=reset1), r1=pcm.xx_free_cnt,  */
literal|0x0101030a
block|,
literal|0x00010001
block|,
literal|0x000003f3
block|,
comment|/* (r1!=0), r1=pcm.xx_lcid_cam_fill_lvl,  */
literal|0x0101030b
block|,
literal|0x00010001
block|,
literal|0x000003f4
block|,
comment|/* (r1!=0), r1=pcm.xx_lock_cnt,  */
literal|0x0101030c
block|,
literal|0x00010001
block|,
literal|0x000003f5
block|,
comment|/* (r1!=0), r1=pcm.sm_con_fic_buf_fill_lvl,  */
literal|0x0101030d
block|,
literal|0x00010001
block|,
literal|0x000003f6
block|,
comment|/* (r1!=0), r1=pcm.in_prcs_tbl_fill_lvl,  */
literal|0x0101030e
block|,
literal|0x00010001
block|,
literal|0x000d03f7
block|,
comment|/* (r1!=reset1), r1=pcm.ccfc_init_crd,  */
literal|0x0101030f
block|,
literal|0x00010001
block|,
literal|0x002e03f8
block|,
comment|/* (r1!=reset1), r1=pcm.fic_init_crd,  */
literal|0x01010310
block|,
literal|0x00010001
block|,
literal|0x000003f9
block|,
comment|/* (r1!=0), r1=pcm.is_storm_fill_lvl,  */
literal|0x00000311
block|,
literal|0x00010002
block|,
literal|0x000003fa
block|,
comment|/* ((r1&~r2)!=0), r1=tcm.INT_STS_0, r2=tcm.INT_MASK_0,  */
literal|0x00000312
block|,
literal|0x00010002
block|,
literal|0x000003fc
block|,
comment|/* ((r1&~r2)!=0), r1=tcm.INT_STS_1, r2=tcm.INT_MASK_1,  */
literal|0x00000313
block|,
literal|0x00010002
block|,
literal|0x000003fe
block|,
comment|/* ((r1&~r2)!=0), r1=tcm.PRTY_STS_H_0, r2=tcm.PRTY_MASK_H_0,  */
literal|0x00000314
block|,
literal|0x00010002
block|,
literal|0x00000400
block|,
comment|/* ((r1&~r2)!=0), r1=tcm.PRTY_STS_H_1, r2=tcm.PRTY_MASK_H_1,  */
literal|0x01000315
block|,
literal|0x00010001
block|,
literal|0x00000402
block|,
comment|/* (r1!=0), r1=tcm.fi_desc_input_violate,  */
literal|0x01000316
block|,
literal|0x00010001
block|,
literal|0x00000403
block|,
comment|/* (r1!=0), r1=tcm.se_desc_input_violate,  */
literal|0x01010317
block|,
literal|0x00010001
block|,
literal|0x00000404
block|,
comment|/* (r1!=0), r1=tcm.ia_agg_con_part_fill_lvl,  */
literal|0x01010318
block|,
literal|0x00010001
block|,
literal|0x00000405
block|,
comment|/* (r1!=0), r1=tcm.ia_sm_con_part_fill_lvl,  */
literal|0x01010319
block|,
literal|0x00010001
block|,
literal|0x00000406
block|,
comment|/* (r1!=0), r1=tcm.ia_agg_task_part_fill_lvl,  */
literal|0x0101031a
block|,
literal|0x00010001
block|,
literal|0x00000407
block|,
comment|/* (r1!=0), r1=tcm.ia_sm_task_part_fill_lvl,  */
literal|0x0101031b
block|,
literal|0x00010001
block|,
literal|0x00000408
block|,
comment|/* (r1!=0), r1=tcm.ia_trans_part_fill_lvl,  */
literal|0x0101031c
block|,
literal|0x00010001
block|,
literal|0x002d0409
block|,
comment|/* (r1!=reset1), r1=tcm.xx_free_cnt,  */
literal|0x0101031d
block|,
literal|0x00010001
block|,
literal|0x0000040a
block|,
comment|/* (r1!=0), r1=tcm.xx_lcid_cam_fill_lvl,  */
literal|0x0101031e
block|,
literal|0x00010001
block|,
literal|0x0000040b
block|,
comment|/* (r1!=0), r1=tcm.xx_lock_cnt,  */
literal|0x0101031f
block|,
literal|0x00010001
block|,
literal|0x0000040c
block|,
comment|/* (r1!=0), r1=tcm.xx_cbyp_tbl_fill_lvl,  */
literal|0x01010320
block|,
literal|0x00010001
block|,
literal|0x0000040d
block|,
comment|/* (r1!=0), r1=tcm.xx_tbyp_tbl_fill_lvl,  */
literal|0x01010321
block|,
literal|0x00010001
block|,
literal|0x0000040e
block|,
comment|/* (r1!=0), r1=tcm.xx_tbyp_tbl_fill_lvl,  */
literal|0x01010322
block|,
literal|0x00010001
block|,
literal|0x0000040f
block|,
comment|/* (r1!=0), r1=tcm.agg_con_fic_buf_fill_lvl,  */
literal|0x01010323
block|,
literal|0x00010001
block|,
literal|0x00000410
block|,
comment|/* (r1!=0), r1=tcm.sm_con_fic_buf_fill_lvl,  */
literal|0x01010324
block|,
literal|0x00010001
block|,
literal|0x00000411
block|,
comment|/* (r1!=0), r1=tcm.agg_task_fic_buf_fill_lvl,  */
literal|0x01010325
block|,
literal|0x00010001
block|,
literal|0x00000412
block|,
comment|/* (r1!=0), r1=tcm.sm_task_fic_buf_fill_lvl,  */
literal|0x01010326
block|,
literal|0x00010001
block|,
literal|0x00000413
block|,
comment|/* (r1!=0), r1=tcm.in_prcs_tbl_fill_lvl,  */
literal|0x01010327
block|,
literal|0x00010001
block|,
literal|0x000d0414
block|,
comment|/* (r1!=reset1), r1=tcm.ccfc_init_crd,  */
literal|0x01010328
block|,
literal|0x00010001
block|,
literal|0x000d0415
block|,
comment|/* (r1!=reset1), r1=tcm.tcfc_init_crd,  */
literal|0x01010329
block|,
literal|0x00010001
block|,
literal|0x000a0416
block|,
comment|/* (r1!=reset1), r1=tcm.qm_init_crd0,  */
literal|0x0101032a
block|,
literal|0x00010001
block|,
literal|0x00110417
block|,
comment|/* (r1!=reset1), r1=tcm.tm_init_crd,  */
literal|0x0101032b
block|,
literal|0x00010001
block|,
literal|0x00300418
block|,
comment|/* (r1!=reset1), r1=tcm.fic_init_crd,  */
literal|0x0100032c
block|,
literal|0x00010001
block|,
literal|0x00000419
block|,
comment|/* (r1!=0), r1=tcm.dorq_length_mis,  */
literal|0x0100032d
block|,
literal|0x00010001
block|,
literal|0x0000041a
block|,
comment|/* (r1!=0), r1=tcm.pbf_length_mis,  */
literal|0x0101032e
block|,
literal|0x00010001
block|,
literal|0x0000041b
block|,
comment|/* (r1!=0), r1=tcm.is_qm_p_fill_lvl,  */
literal|0x0101032f
block|,
literal|0x00010001
block|,
literal|0x0000041c
block|,
comment|/* (r1!=0), r1=tcm.is_qm_s_fill_lvl,  */
literal|0x01010330
block|,
literal|0x00010001
block|,
literal|0x0000041d
block|,
comment|/* (r1!=0), r1=tcm.is_tm_fill_lvl,  */
literal|0x01010331
block|,
literal|0x00010001
block|,
literal|0x0000041e
block|,
comment|/* (r1!=0), r1=tcm.is_storm_fill_lvl,  */
literal|0x01010332
block|,
literal|0x00010001
block|,
literal|0x0000041f
block|,
comment|/* (r1!=0), r1=tcm.is_msem_fill_lvl,  */
literal|0x01010333
block|,
literal|0x00010001
block|,
literal|0x00000420
block|,
comment|/* (r1!=0), r1=tcm.is_dorq_fill_lvl,  */
literal|0x01010334
block|,
literal|0x00010001
block|,
literal|0x00000421
block|,
comment|/* (r1!=0), r1=tcm.is_pbf_fill_lvl,  */
literal|0x00000335
block|,
literal|0x00010002
block|,
literal|0x00000422
block|,
comment|/* ((r1&~r2)!=0), r1=mcm.INT_STS_0, r2=mcm.INT_MASK_0,  */
literal|0x00000336
block|,
literal|0x00010002
block|,
literal|0x00000424
block|,
comment|/* ((r1&~r2)!=0), r1=mcm.INT_STS_1, r2=mcm.INT_MASK_1,  */
literal|0x00000337
block|,
literal|0x00010002
block|,
literal|0x00000426
block|,
comment|/* ((r1&~r2)!=0), r1=mcm.PRTY_STS_H_0, r2=mcm.PRTY_MASK_H_0,  */
literal|0x00000338
block|,
literal|0x00010002
block|,
literal|0x00000428
block|,
comment|/* ((r1&~r2)!=0), r1=mcm.PRTY_STS_H_1, r2=mcm.PRTY_MASK_H_1,  */
literal|0x01000339
block|,
literal|0x00010001
block|,
literal|0x0000042a
block|,
comment|/* (r1!=0), r1=mcm.fi_desc_input_violate,  */
literal|0x0100033a
block|,
literal|0x00010001
block|,
literal|0x0000042b
block|,
comment|/* (r1!=0), r1=mcm.se_desc_input_violate,  */
literal|0x0101033b
block|,
literal|0x00010001
block|,
literal|0x0000042c
block|,
comment|/* (r1!=0), r1=mcm.ia_agg_con_part_fill_lvl,  */
literal|0x0101033c
block|,
literal|0x00010001
block|,
literal|0x0000042d
block|,
comment|/* (r1!=0), r1=mcm.ia_sm_con_part_fill_lvl,  */
literal|0x0101033d
block|,
literal|0x00010001
block|,
literal|0x0000042e
block|,
comment|/* (r1!=0), r1=mcm.ia_agg_task_part_fill_lvl,  */
literal|0x0101033e
block|,
literal|0x00010001
block|,
literal|0x0000042f
block|,
comment|/* (r1!=0), r1=mcm.ia_sm_task_part_fill_lvl,  */
literal|0x0101033f
block|,
literal|0x00010001
block|,
literal|0x00000430
block|,
comment|/* (r1!=0), r1=mcm.ia_trans_part_fill_lvl,  */
literal|0x01010340
block|,
literal|0x00010001
block|,
literal|0x002d0431
block|,
comment|/* (r1!=reset1), r1=mcm.xx_free_cnt,  */
literal|0x01010341
block|,
literal|0x00010001
block|,
literal|0x00000432
block|,
comment|/* (r1!=0), r1=mcm.xx_lcid_cam_fill_lvl,  */
literal|0x01010342
block|,
literal|0x00010001
block|,
literal|0x00000433
block|,
comment|/* (r1!=0), r1=mcm.xx_lock_cnt,  */
literal|0x01010343
block|,
literal|0x00010001
block|,
literal|0x00000434
block|,
comment|/* (r1!=0), r1=mcm.xx_cbyp_tbl_fill_lvl,  */
literal|0x01010344
block|,
literal|0x00010001
block|,
literal|0x00000435
block|,
comment|/* (r1!=0), r1=mcm.xx_tbyp_tbl_fill_lvl,  */
literal|0x01010345
block|,
literal|0x00010001
block|,
literal|0x00000436
block|,
comment|/* (r1!=0), r1=mcm.xx_tbyp_tbl_fill_lvl,  */
literal|0x01010346
block|,
literal|0x00010001
block|,
literal|0x00000437
block|,
comment|/* (r1!=0), r1=mcm.agg_con_fic_buf_fill_lvl,  */
literal|0x01010347
block|,
literal|0x00010001
block|,
literal|0x00000438
block|,
comment|/* (r1!=0), r1=mcm.sm_con_fic_buf_fill_lvl,  */
literal|0x01010348
block|,
literal|0x00010001
block|,
literal|0x00000439
block|,
comment|/* (r1!=0), r1=mcm.agg_task_fic_buf_fill_lvl,  */
literal|0x01010349
block|,
literal|0x00010001
block|,
literal|0x0000043a
block|,
comment|/* (r1!=0), r1=mcm.sm_task_fic_buf_fill_lvl,  */
literal|0x0101034a
block|,
literal|0x00010001
block|,
literal|0x0000043b
block|,
comment|/* (r1!=0), r1=mcm.in_prcs_tbl_fill_lvl,  */
literal|0x0101034b
block|,
literal|0x00010001
block|,
literal|0x000d043c
block|,
comment|/* (r1!=reset1), r1=mcm.ccfc_init_crd,  */
literal|0x0101034c
block|,
literal|0x00010001
block|,
literal|0x000d043d
block|,
comment|/* (r1!=reset1), r1=mcm.tcfc_init_crd,  */
literal|0x0101034d
block|,
literal|0x00010001
block|,
literal|0x000a043e
block|,
comment|/* (r1!=reset1), r1=mcm.qm_init_crd0,  */
literal|0x0101034e
block|,
literal|0x00010001
block|,
literal|0x0030043f
block|,
comment|/* (r1!=reset1), r1=mcm.fic_init_crd,  */
literal|0x0100034f
block|,
literal|0x00010001
block|,
literal|0x00000440
block|,
comment|/* (r1!=0), r1=mcm.ysdm_length_mis,  */
literal|0x01000350
block|,
literal|0x00010001
block|,
literal|0x00000441
block|,
comment|/* (r1!=0), r1=mcm.usdm_length_mis,  */
literal|0x01000351
block|,
literal|0x00010001
block|,
literal|0x00000442
block|,
comment|/* (r1!=0), r1=mcm.pbf_length_mis,  */
literal|0x01000352
block|,
literal|0x00010001
block|,
literal|0x00000443
block|,
comment|/* (r1!=0), r1=mcm.tmld_length_mis,  */
literal|0x01010353
block|,
literal|0x00010001
block|,
literal|0x00000444
block|,
comment|/* (r1!=0), r1=mcm.is_qm_p_fill_lvl,  */
literal|0x01010354
block|,
literal|0x00010001
block|,
literal|0x00000445
block|,
comment|/* (r1!=0), r1=mcm.is_qm_s_fill_lvl,  */
literal|0x01010355
block|,
literal|0x00010001
block|,
literal|0x00000446
block|,
comment|/* (r1!=0), r1=mcm.is_storm_fill_lvl,  */
literal|0x01010356
block|,
literal|0x00010001
block|,
literal|0x00000447
block|,
comment|/* (r1!=0), r1=mcm.is_ysdm_fill_lvl,  */
literal|0x01010357
block|,
literal|0x00010001
block|,
literal|0x00000448
block|,
comment|/* (r1!=0), r1=mcm.is_usdm_fill_lvl,  */
literal|0x01010358
block|,
literal|0x00010001
block|,
literal|0x00000449
block|,
comment|/* (r1!=0), r1=mcm.is_tmld_fill_lvl,  */
literal|0x01010359
block|,
literal|0x00010001
block|,
literal|0x0000044a
block|,
comment|/* (r1!=0), r1=mcm.is_usem_fill_lvl,  */
literal|0x0101035a
block|,
literal|0x00010001
block|,
literal|0x0000044b
block|,
comment|/* (r1!=0), r1=mcm.is_pbf_fill_lvl,  */
literal|0x0000035b
block|,
literal|0x00010002
block|,
literal|0x0000044c
block|,
comment|/* ((r1&~r2)!=0), r1=ucm.INT_STS_0, r2=ucm.INT_MASK_0,  */
literal|0x0000035c
block|,
literal|0x00010002
block|,
literal|0x0000044e
block|,
comment|/* ((r1&~r2)!=0), r1=ucm.INT_STS_1, r2=ucm.INT_MASK_1,  */
literal|0x0000035d
block|,
literal|0x00010002
block|,
literal|0x00000450
block|,
comment|/* ((r1&~r2)!=0), r1=ucm.PRTY_STS_H_0, r2=ucm.PRTY_MASK_H_0,  */
literal|0x0000035e
block|,
literal|0x00010002
block|,
literal|0x00000452
block|,
comment|/* ((r1&~r2)!=0), r1=ucm.PRTY_STS_H_1, r2=ucm.PRTY_MASK_H_1,  */
literal|0x0100035f
block|,
literal|0x00010001
block|,
literal|0x00000454
block|,
comment|/* (r1!=0), r1=ucm.fi_desc_input_violate,  */
literal|0x01000360
block|,
literal|0x00010001
block|,
literal|0x00000455
block|,
comment|/* (r1!=0), r1=ucm.se_desc_input_violate,  */
literal|0x01010361
block|,
literal|0x00010001
block|,
literal|0x00000456
block|,
comment|/* (r1!=0), r1=ucm.ia_agg_con_part_fill_lvl,  */
literal|0x01010362
block|,
literal|0x00010001
block|,
literal|0x00000457
block|,
comment|/* (r1!=0), r1=ucm.ia_sm_con_part_fill_lvl,  */
literal|0x01010363
block|,
literal|0x00010001
block|,
literal|0x00000458
block|,
comment|/* (r1!=0), r1=ucm.ia_agg_task_part_fill_lvl,  */
literal|0x01010364
block|,
literal|0x00010001
block|,
literal|0x00000459
block|,
comment|/* (r1!=0), r1=ucm.ia_sm_task_part_fill_lvl,  */
literal|0x01010365
block|,
literal|0x00010001
block|,
literal|0x0000045a
block|,
comment|/* (r1!=0), r1=ucm.ia_trans_part_fill_lvl,  */
literal|0x01010366
block|,
literal|0x00010001
block|,
literal|0x002d045b
block|,
comment|/* (r1!=reset1), r1=ucm.xx_free_cnt,  */
literal|0x01010367
block|,
literal|0x00010001
block|,
literal|0x0000045c
block|,
comment|/* (r1!=0), r1=ucm.xx_lcid_cam_fill_lvl,  */
literal|0x01010368
block|,
literal|0x00010001
block|,
literal|0x0000045d
block|,
comment|/* (r1!=0), r1=ucm.xx_lock_cnt,  */
literal|0x01010369
block|,
literal|0x00010001
block|,
literal|0x0000045e
block|,
comment|/* (r1!=0), r1=ucm.xx_cbyp_tbl_fill_lvl,  */
literal|0x0101036a
block|,
literal|0x00010001
block|,
literal|0x0000045f
block|,
comment|/* (r1!=0), r1=ucm.xx_tbyp_tbl_fill_lvl,  */
literal|0x0101036b
block|,
literal|0x00010001
block|,
literal|0x00000460
block|,
comment|/* (r1!=0), r1=ucm.xx_tbyp_tbl_fill_lvl,  */
literal|0x0101036c
block|,
literal|0x00010001
block|,
literal|0x00000461
block|,
comment|/* (r1!=0), r1=ucm.agg_con_fic_buf_fill_lvl,  */
literal|0x0101036d
block|,
literal|0x00010001
block|,
literal|0x00000462
block|,
comment|/* (r1!=0), r1=ucm.sm_con_fic_buf_fill_lvl,  */
literal|0x0101036e
block|,
literal|0x00010001
block|,
literal|0x00000463
block|,
comment|/* (r1!=0), r1=ucm.agg_task_fic_buf_fill_lvl,  */
literal|0x0101036f
block|,
literal|0x00010001
block|,
literal|0x00000464
block|,
comment|/* (r1!=0), r1=ucm.sm_task_fic_buf_fill_lvl,  */
literal|0x01010370
block|,
literal|0x00010001
block|,
literal|0x00000465
block|,
comment|/* (r1!=0), r1=ucm.in_prcs_tbl_fill_lvl,  */
literal|0x01010371
block|,
literal|0x00010001
block|,
literal|0x000d0466
block|,
comment|/* (r1!=reset1), r1=ucm.ccfc_init_crd,  */
literal|0x01010372
block|,
literal|0x00010001
block|,
literal|0x000d0467
block|,
comment|/* (r1!=reset1), r1=ucm.tcfc_init_crd,  */
literal|0x01010373
block|,
literal|0x00010001
block|,
literal|0x000a0468
block|,
comment|/* (r1!=reset1), r1=ucm.qm_init_crd0,  */
literal|0x01010374
block|,
literal|0x00010001
block|,
literal|0x00110469
block|,
comment|/* (r1!=reset1), r1=ucm.tm_init_crd,  */
literal|0x01010375
block|,
literal|0x00010001
block|,
literal|0x002f046a
block|,
comment|/* (r1!=reset1), r1=ucm.fic_init_crd,  */
literal|0x01000376
block|,
literal|0x00010001
block|,
literal|0x0000046b
block|,
comment|/* (r1!=0), r1=ucm.ysdm_length_mis,  */
literal|0x01000377
block|,
literal|0x00010001
block|,
literal|0x0000046c
block|,
comment|/* (r1!=0), r1=ucm.usdm_length_mis,  */
literal|0x01000378
block|,
literal|0x00010001
block|,
literal|0x0000046d
block|,
comment|/* (r1!=0), r1=ucm.dorq_length_mis,  */
literal|0x01000379
block|,
literal|0x00010001
block|,
literal|0x0000046e
block|,
comment|/* (r1!=0), r1=ucm.pbf_length_mis,  */
literal|0x0100037a
block|,
literal|0x00010001
block|,
literal|0x0000046f
block|,
comment|/* (r1!=0), r1=ucm.rdif_length_mis,  */
literal|0x0100037b
block|,
literal|0x00010001
block|,
literal|0x00000470
block|,
comment|/* (r1!=0), r1=ucm.tdif_length_mis,  */
literal|0x0100037c
block|,
literal|0x00010001
block|,
literal|0x00000471
block|,
comment|/* (r1!=0), r1=ucm.muld_length_mis,  */
literal|0x0101037d
block|,
literal|0x00010001
block|,
literal|0x00000472
block|,
comment|/* (r1!=0), r1=ucm.is_qm_p_fill_lvl,  */
literal|0x0101037e
block|,
literal|0x00010001
block|,
literal|0x00000473
block|,
comment|/* (r1!=0), r1=ucm.is_qm_s_fill_lvl,  */
literal|0x0101037f
block|,
literal|0x00010001
block|,
literal|0x00000474
block|,
comment|/* (r1!=0), r1=ucm.is_tm_fill_lvl,  */
literal|0x01010380
block|,
literal|0x00010001
block|,
literal|0x00000475
block|,
comment|/* (r1!=0), r1=ucm.is_storm_fill_lvl,  */
literal|0x01010381
block|,
literal|0x00010001
block|,
literal|0x00000476
block|,
comment|/* (r1!=0), r1=ucm.is_ysdm_fill_lvl,  */
literal|0x01010382
block|,
literal|0x00010001
block|,
literal|0x00000477
block|,
comment|/* (r1!=0), r1=ucm.is_usdm_fill_lvl,  */
literal|0x01010383
block|,
literal|0x00010001
block|,
literal|0x00000478
block|,
comment|/* (r1!=0), r1=ucm.is_rdif_fill_lvl,  */
literal|0x01010384
block|,
literal|0x00010001
block|,
literal|0x00000479
block|,
comment|/* (r1!=0), r1=ucm.is_tdif_fill_lvl,  */
literal|0x01010385
block|,
literal|0x00010001
block|,
literal|0x0000047a
block|,
comment|/* (r1!=0), r1=ucm.is_muld_fill_lvl,  */
literal|0x01010386
block|,
literal|0x00010001
block|,
literal|0x0000047b
block|,
comment|/* (r1!=0), r1=ucm.is_dorq_fill_lvl,  */
literal|0x01010387
block|,
literal|0x00010001
block|,
literal|0x0000047c
block|,
comment|/* (r1!=0), r1=ucm.is_pbf_fill_lvl,  */
literal|0x00000388
block|,
literal|0x00010002
block|,
literal|0x0000047d
block|,
comment|/* ((r1&~r2)!=0), r1=xsem.INT_STS_0, r2=xsem.INT_MASK_0,  */
literal|0x00000389
block|,
literal|0x00010002
block|,
literal|0x0000047f
block|,
comment|/* ((r1&~r2)!=0), r1=xsem.INT_STS_1, r2=xsem.INT_MASK_1,  */
literal|0x0000038a
block|,
literal|0x00010002
block|,
literal|0x00000481
block|,
comment|/* ((r1&~r2)!=0), r1=xsem.PRTY_STS, r2=xsem.PRTY_MASK,  */
literal|0x0102038b
block|,
literal|0x00010001
block|,
literal|0x00000483
block|,
comment|/* (r1!=0), r1=xsem.pf_err_vector,  */
literal|0x0101038c
block|,
literal|0x00010001
block|,
literal|0x00310484
block|,
comment|/* (r1!=0x1D), r1=xsem.foc_credit[1],  */
literal|0x0101038d
block|,
literal|0x00010001
block|,
literal|0x00320485
block|,
comment|/* (r1!=0x3F), r1=xsem.foc_credit,  */
literal|0x0101038e
block|,
literal|0x00010001
block|,
literal|0x000d0486
block|,
comment|/* (r1!=1), r1=xsem.ext_pas_empty,  */
literal|0x0101038f
block|,
literal|0x00010001
block|,
literal|0x000d0487
block|,
comment|/* (r1!=1), r1=xsem.fic_empty[0:1],  */
literal|0x01010390
block|,
literal|0x00010001
block|,
literal|0x000d0488
block|,
comment|/* (r1!=1), r1=xsem.slow_ext_store_empty,  */
literal|0x01010391
block|,
literal|0x00010001
block|,
literal|0x000d0489
block|,
comment|/* (r1!=1), r1=xsem.slow_ext_load_empty,  */
literal|0x01010392
block|,
literal|0x00010001
block|,
literal|0x000d048a
block|,
comment|/* (r1!=1), r1=xsem.slow_ram_wr_empty,  */
literal|0x01010393
block|,
literal|0x00010001
block|,
literal|0x000d048b
block|,
comment|/* (r1!=1), r1=xsem.sync_dbg_empty,  */
literal|0x01010394
block|,
literal|0x00010001
block|,
literal|0x0000048c
block|,
comment|/* (r1!=0), r1=xsem.ext_store_if_full,  */
literal|0x01010395
block|,
literal|0x00010001
block|,
literal|0x0000048d
block|,
comment|/* (r1!=0), r1=xsem.ram_if_full,  */
literal|0x00000396
block|,
literal|0x00010002
block|,
literal|0x0000048e
block|,
comment|/* ((r1&~r2)!=0), r1=ysem.INT_STS_0, r2=ysem.INT_MASK_0,  */
literal|0x00000397
block|,
literal|0x00010002
block|,
literal|0x00000490
block|,
comment|/* ((r1&~r2)!=0), r1=ysem.INT_STS_1, r2=ysem.INT_MASK_1,  */
literal|0x00000398
block|,
literal|0x00010002
block|,
literal|0x00000492
block|,
comment|/* ((r1&~r2)!=0), r1=ysem.PRTY_STS, r2=ysem.PRTY_MASK,  */
literal|0x01020399
block|,
literal|0x00010001
block|,
literal|0x00000494
block|,
comment|/* (r1!=0), r1=ysem.pf_err_vector,  */
literal|0x0101039a
block|,
literal|0x00010001
block|,
literal|0x00330495
block|,
comment|/* (r1!=0xA), r1=ysem.foc_credit[2],  */
literal|0x0101039b
block|,
literal|0x00010001
block|,
literal|0x00340496
block|,
comment|/* (r1!=0xE), r1=ysem.foc_credit,  */
literal|0x0101039c
block|,
literal|0x00010001
block|,
literal|0x00350497
block|,
comment|/* (r1!=0x1A), r1=ysem.foc_credit[1],  */
literal|0x0101039d
block|,
literal|0x00010001
block|,
literal|0x00280498
block|,
comment|/* (r1!=0x7), r1=ysem.foc_credit[3],  */
literal|0x0101039e
block|,
literal|0x00010001
block|,
literal|0x00360499
block|,
comment|/* (r1!=0x26), r1=ysem.foc_credit[4],  */
literal|0x0101039f
block|,
literal|0x00010001
block|,
literal|0x002e049a
block|,
comment|/* (r1!=0x28), r1=ysem.foc_credit[5],  */
literal|0x010103a0
block|,
literal|0x00010001
block|,
literal|0x000d049b
block|,
comment|/* (r1!=1), r1=ysem.ext_pas_empty,  */
literal|0x010103a1
block|,
literal|0x00010001
block|,
literal|0x000d049c
block|,
comment|/* (r1!=1), r1=ysem.fic_empty[0:1],  */
literal|0x010103a2
block|,
literal|0x00010001
block|,
literal|0x000d049d
block|,
comment|/* (r1!=1), r1=ysem.slow_ext_store_empty,  */
literal|0x010103a3
block|,
literal|0x00010001
block|,
literal|0x000d049e
block|,
comment|/* (r1!=1), r1=ysem.slow_ext_load_empty,  */
literal|0x010103a4
block|,
literal|0x00010001
block|,
literal|0x000d049f
block|,
comment|/* (r1!=1), r1=ysem.slow_ram_wr_empty,  */
literal|0x010103a5
block|,
literal|0x00010001
block|,
literal|0x000d04a0
block|,
comment|/* (r1!=1), r1=ysem.sync_dbg_empty,  */
literal|0x010103a6
block|,
literal|0x00010001
block|,
literal|0x000004a1
block|,
comment|/* (r1!=0), r1=ysem.ext_store_if_full,  */
literal|0x010103a7
block|,
literal|0x00010001
block|,
literal|0x000004a2
block|,
comment|/* (r1!=0), r1=ysem.ram_if_full,  */
literal|0x000003a8
block|,
literal|0x00010002
block|,
literal|0x000004a3
block|,
comment|/* ((r1&~r2)!=0), r1=psem.INT_STS_0, r2=psem.INT_MASK_0,  */
literal|0x000003a9
block|,
literal|0x00010002
block|,
literal|0x000004a5
block|,
comment|/* ((r1&~r2)!=0), r1=psem.INT_STS_1, r2=psem.INT_MASK_1,  */
literal|0x000003aa
block|,
literal|0x00010002
block|,
literal|0x000004a7
block|,
comment|/* ((r1&~r2)!=0), r1=psem.PRTY_STS, r2=psem.PRTY_MASK,  */
literal|0x010203ab
block|,
literal|0x00010001
block|,
literal|0x000004a9
block|,
comment|/* (r1!=0), r1=psem.pf_err_vector,  */
literal|0x010103ac
block|,
literal|0x00010001
block|,
literal|0x003704aa
block|,
comment|/* (r1!=0x17), r1=psem.foc_credit,  */
literal|0x010103ad
block|,
literal|0x00010001
block|,
literal|0x002d04ab
block|,
comment|/* (r1!=0x40), r1=psem.foc_credit[1],  */
literal|0x010103ae
block|,
literal|0x00010001
block|,
literal|0x000d04ac
block|,
comment|/* (r1!=1), r1=psem.ext_pas_empty,  */
literal|0x010103af
block|,
literal|0x00010001
block|,
literal|0x000d04ad
block|,
comment|/* (r1!=1), r1=psem.fic_empty,  */
literal|0x010103b0
block|,
literal|0x00010001
block|,
literal|0x000d04ae
block|,
comment|/* (r1!=1), r1=psem.slow_ext_store_empty,  */
literal|0x010103b1
block|,
literal|0x00010001
block|,
literal|0x000d04af
block|,
comment|/* (r1!=1), r1=psem.slow_ext_load_empty,  */
literal|0x010103b2
block|,
literal|0x00010001
block|,
literal|0x000d04b0
block|,
comment|/* (r1!=1), r1=psem.slow_ram_wr_empty,  */
literal|0x010103b3
block|,
literal|0x00010001
block|,
literal|0x000d04b1
block|,
comment|/* (r1!=1), r1=psem.sync_dbg_empty,  */
literal|0x010103b4
block|,
literal|0x00010001
block|,
literal|0x000004b2
block|,
comment|/* (r1!=0), r1=psem.ext_store_if_full,  */
literal|0x010103b5
block|,
literal|0x00010001
block|,
literal|0x000004b3
block|,
comment|/* (r1!=0), r1=psem.ram_if_full,  */
literal|0x000003b6
block|,
literal|0x00010002
block|,
literal|0x000004b4
block|,
comment|/* ((r1&~r2)!=0), r1=tsem.INT_STS_0, r2=tsem.INT_MASK_0,  */
literal|0x000003b7
block|,
literal|0x00010002
block|,
literal|0x000004b6
block|,
comment|/* ((r1&~r2)!=0), r1=tsem.INT_STS_1, r2=tsem.INT_MASK_1,  */
literal|0x000003b8
block|,
literal|0x00010002
block|,
literal|0x000004b8
block|,
comment|/* ((r1&~r2)!=0), r1=tsem.PRTY_STS, r2=tsem.PRTY_MASK,  */
literal|0x010203b9
block|,
literal|0x00010001
block|,
literal|0x000004ba
block|,
comment|/* (r1!=0), r1=tsem.pf_err_vector,  */
literal|0x010103ba
block|,
literal|0x00010001
block|,
literal|0x003804bb
block|,
comment|/* (r1!=0x2C), r1=tsem.foc_credit,  */
literal|0x010103bb
block|,
literal|0x00010001
block|,
literal|0x003904bc
block|,
comment|/* (r1!=0x3C), r1=tsem.foc_credit[1],  */
literal|0x010103bc
block|,
literal|0x00010001
block|,
literal|0x000d04bd
block|,
comment|/* (r1!=1), r1=tsem.ext_pas_empty,  */
literal|0x010103bd
block|,
literal|0x00010001
block|,
literal|0x000d04be
block|,
comment|/* (r1!=1), r1=tsem.fic_empty,  */
literal|0x010103be
block|,
literal|0x00010001
block|,
literal|0x000d04bf
block|,
comment|/* (r1!=1), r1=tsem.slow_ext_store_empty,  */
literal|0x010103bf
block|,
literal|0x00010001
block|,
literal|0x000d04c0
block|,
comment|/* (r1!=1), r1=tsem.slow_ext_load_empty,  */
literal|0x010103c0
block|,
literal|0x00010001
block|,
literal|0x000d04c1
block|,
comment|/* (r1!=1), r1=tsem.slow_ram_wr_empty,  */
literal|0x010103c1
block|,
literal|0x00010001
block|,
literal|0x000d04c2
block|,
comment|/* (r1!=1), r1=tsem.sync_dbg_empty,  */
literal|0x010103c2
block|,
literal|0x00010001
block|,
literal|0x000004c3
block|,
comment|/* (r1!=0), r1=tsem.ext_store_if_full,  */
literal|0x010103c3
block|,
literal|0x00010001
block|,
literal|0x000004c4
block|,
comment|/* (r1!=0), r1=tsem.ram_if_full,  */
literal|0x000003c4
block|,
literal|0x00010002
block|,
literal|0x000004c5
block|,
comment|/* ((r1&~r2)!=0), r1=msem.INT_STS_0, r2=msem.INT_MASK_0,  */
literal|0x000003c5
block|,
literal|0x00010002
block|,
literal|0x000004c7
block|,
comment|/* ((r1&~r2)!=0), r1=msem.INT_STS_1, r2=msem.INT_MASK_1,  */
literal|0x000003c6
block|,
literal|0x00010002
block|,
literal|0x000004c9
block|,
comment|/* ((r1&~r2)!=0), r1=msem.PRTY_STS, r2=msem.PRTY_MASK,  */
literal|0x000003c7
block|,
literal|0x00010002
block|,
literal|0x000004cb
block|,
comment|/* ((r1&~r2)!=0), r1=msem.PRTY_STS_H_0, r2=msem.PRTY_MASK_H_0,  */
literal|0x010203c8
block|,
literal|0x00010001
block|,
literal|0x000004cd
block|,
comment|/* (r1!=0), r1=msem.pf_err_vector,  */
literal|0x010103c9
block|,
literal|0x00010001
block|,
literal|0x001a04ce
block|,
comment|/* (r1!=0x11), r1=msem.foc_credit[3],  */
literal|0x010103ca
block|,
literal|0x00010001
block|,
literal|0x002804cf
block|,
comment|/* (r1!=0x7), r1=msem.foc_credit[4],  */
literal|0x010103cb
block|,
literal|0x00010001
block|,
literal|0x000f04d0
block|,
comment|/* (r1!=0x20), r1=msem.foc_credit[5],  */
literal|0x010103cc
block|,
literal|0x00010001
block|,
literal|0x000904d1
block|,
comment|/* (r1!=0x5), r1=msem.foc_credit,  */
literal|0x010103cd
block|,
literal|0x00010001
block|,
literal|0x003804d2
block|,
comment|/* (r1!=0x2C), r1=msem.foc_credit[1],  */
literal|0x010103ce
block|,
literal|0x00010001
block|,
literal|0x003704d3
block|,
comment|/* (r1!=0x17), r1=msem.foc_credit[2],  */
literal|0x010103cf
block|,
literal|0x00010001
block|,
literal|0x000d04d4
block|,
comment|/* (r1!=1), r1=msem.ext_pas_empty,  */
literal|0x010103d0
block|,
literal|0x00010001
block|,
literal|0x000d04d5
block|,
comment|/* (r1!=1), r1=msem.fic_empty,  */
literal|0x010103d1
block|,
literal|0x00010001
block|,
literal|0x000d04d6
block|,
comment|/* (r1!=1), r1=msem.slow_ext_store_empty,  */
literal|0x010103d2
block|,
literal|0x00010001
block|,
literal|0x000d04d7
block|,
comment|/* (r1!=1), r1=msem.slow_ext_load_empty,  */
literal|0x010103d3
block|,
literal|0x00010001
block|,
literal|0x000d04d8
block|,
comment|/* (r1!=1), r1=msem.slow_ram_wr_empty,  */
literal|0x010103d4
block|,
literal|0x00010001
block|,
literal|0x000d04d9
block|,
comment|/* (r1!=1), r1=msem.sync_dbg_empty,  */
literal|0x010103d5
block|,
literal|0x00010001
block|,
literal|0x000004da
block|,
comment|/* (r1!=0), r1=msem.ext_store_if_full,  */
literal|0x010103d6
block|,
literal|0x00010001
block|,
literal|0x000004db
block|,
comment|/* (r1!=0), r1=msem.ram_if_full,  */
literal|0x000003d7
block|,
literal|0x00010002
block|,
literal|0x000004dc
block|,
comment|/* ((r1&~r2)!=0), r1=usem.INT_STS_0, r2=usem.INT_MASK_0,  */
literal|0x000003d8
block|,
literal|0x00010002
block|,
literal|0x000004de
block|,
comment|/* ((r1&~r2)!=0), r1=usem.INT_STS_1, r2=usem.INT_MASK_1,  */
literal|0x000003d9
block|,
literal|0x00010002
block|,
literal|0x000004e0
block|,
comment|/* ((r1&~r2)!=0), r1=usem.PRTY_STS, r2=usem.PRTY_MASK,  */
literal|0x010203da
block|,
literal|0x00010001
block|,
literal|0x000004e2
block|,
comment|/* (r1!=0), r1=usem.pf_err_vector,  */
literal|0x010103db
block|,
literal|0x00010001
block|,
literal|0x003a04e3
block|,
comment|/* (r1!=0x32), r1=usem.foc_credit[1],  */
literal|0x010103dc
block|,
literal|0x00010001
block|,
literal|0x001304e4
block|,
comment|/* (r1!=0x3), r1=usem.foc_credit[3],  */
literal|0x010103dd
block|,
literal|0x00010001
block|,
literal|0x003304e5
block|,
comment|/* (r1!=0xA), r1=usem.foc_credit[2],  */
literal|0x010103de
block|,
literal|0x00010001
block|,
literal|0x000904e6
block|,
comment|/* (r1!=0x5), r1=usem.foc_credit,  */
literal|0x010103df
block|,
literal|0x00010001
block|,
literal|0x000f04e7
block|,
comment|/* (r1!=0x20), r1=usem.foc_credit[4],  */
literal|0x010103e0
block|,
literal|0x00010001
block|,
literal|0x000d04e8
block|,
comment|/* (r1!=1), r1=usem.ext_pas_empty,  */
literal|0x010103e1
block|,
literal|0x00010001
block|,
literal|0x000d04e9
block|,
comment|/* (r1!=1), r1=usem.fic_empty,  */
literal|0x010103e2
block|,
literal|0x00010001
block|,
literal|0x000d04ea
block|,
comment|/* (r1!=1), r1=usem.slow_ext_store_empty,  */
literal|0x010103e3
block|,
literal|0x00010001
block|,
literal|0x000d04eb
block|,
comment|/* (r1!=1), r1=usem.slow_ext_load_empty,  */
literal|0x010103e4
block|,
literal|0x00010001
block|,
literal|0x000d04ec
block|,
comment|/* (r1!=1), r1=usem.slow_ram_wr_empty,  */
literal|0x010103e5
block|,
literal|0x00010001
block|,
literal|0x000d04ed
block|,
comment|/* (r1!=1), r1=usem.sync_dbg_empty,  */
literal|0x010103e6
block|,
literal|0x00010001
block|,
literal|0x000004ee
block|,
comment|/* (r1!=0), r1=usem.ext_store_if_full,  */
literal|0x010103e7
block|,
literal|0x00010001
block|,
literal|0x000004ef
block|,
comment|/* (r1!=0), r1=usem.ram_if_full,  */
literal|0x009f0007
block|,
comment|/* mode bb */
literal|0x040003e8
block|,
literal|0x00020001
block|,
literal|0x003b04f0
block|,
comment|/* ((r1&~0x3f02)!=0), r1=pcie.PRTY_STS_H_0,  */
literal|0x010203e9
block|,
literal|0x00010001
block|,
literal|0x000004f1
block|,
comment|/* (r1!=0), r1=igu.pending_bits_status[0:8],  */
literal|0x010103ea
block|,
literal|0x00010001
block|,
literal|0x000004f2
block|,
comment|/* (r1!=0), r1=igu.write_done_pending[0:8],  */
literal|0x000003eb
block|,
literal|0x00010102
block|,
literal|0x000004f3
block|,
comment|/* ((r1&~r2)!=0), r1=cnig.INT_STS, r2=cnig.INT_MASK,  */
literal|0x000003ec
block|,
literal|0x00010002
block|,
literal|0x000004f6
block|,
comment|/* ((r1&~r2)!=0), r1=cnig.PRTY_STS, r2=cnig.PRTY_MASK,  */
literal|0x010203ed
block|,
literal|0x00010101
block|,
literal|0x000004f8
block|,
comment|/* (r1!=0), r1=pswhst.vf_disabled_error_valid,  */
literal|0x010203ee
block|,
literal|0x00010001
block|,
literal|0x000004fa
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_vf_223_192,  */
literal|0x010203ef
block|,
literal|0x00010001
block|,
literal|0x000004fb
block|,
comment|/* (r1!=0), r1=pglue_b.flr_request_vf_255_224,  */
literal|0x010003f0
block|,
literal|0x00010001
block|,
literal|0x000004fc
block|,
comment|/* (r1!=0), r1=pglue_b.incorrect_rcv_details,  */
literal|0x010203f1
block|,
literal|0x00010001
block|,
literal|0x000004fd
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_vf_223_192,  */
literal|0x010203f2
block|,
literal|0x00010001
block|,
literal|0x000004fe
block|,
comment|/* (r1!=0), r1=pglue_b.was_error_vf_255_224,  */
literal|0x010203f3
block|,
literal|0x00010001
block|,
literal|0x001d04ff
block|,
comment|/* (r1!=0xffffffff), r1=pglue_b.tags_159_128,  */
literal|0x010203f4
block|,
literal|0x00010001
block|,
literal|0x001d0500
block|,
comment|/* (r1!=0xffffffff), r1=pglue_b.tags_191_160,  */
literal|0x010203f5
block|,
literal|0x00010001
block|,
literal|0x001d0501
block|,
comment|/* (r1!=0xffffffff), r1=pglue_b.tags_223_192,  */
literal|0x010203f6
block|,
literal|0x00010001
block|,
literal|0x001d0502
block|,
comment|/* (r1!=0xffffffff), r1=pglue_b.tags_255_224,  */
literal|0x010103f7
block|,
literal|0x00010001
block|,
literal|0x00220503
block|,
comment|/* (r1!=reset1), r1=tcfc.cduwb_credit,  */
literal|0x090103f8
block|,
literal|0x00060001
block|,
literal|0x003d0504
block|,
comment|/* ((r1[0]&0x3FFFFFC0)>>6)!=(((r1[0]&0xC0000000)>>30)|((r1[1]&0x3FFFFF)<<2)), r1=qm.PtrTblOther[0:63] width=2 access=WB,  */
literal|0x0a0103f9
block|,
literal|0x00030001
block|,
literal|0x00430505
block|,
comment|/* ((r1&0x30)>>4)!=(r1&0x03), r1=qm.PtrTblOther[0:63] width=2 access=WB,  */
literal|0x010003fa
block|,
literal|0x00010001
block|,
literal|0x00000506
block|,
comment|/* (r1!=0), r1=qm.QstatusTx_0[0:13],  */
literal|0x010003fb
block|,
literal|0x00010001
block|,
literal|0x00000507
block|,
comment|/* (r1!=0), r1=qm.QstatusOther_0[0:1],  */
literal|0x0b0103fc
block|,
literal|0x00010003
block|,
literal|0x00000508
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdLine[0:7], r2=qm.VoqInitCrdLine[0:7], r3=misc.port_mode,  */
literal|0x0b0103fd
block|,
literal|0x00010003
block|,
literal|0x0000050b
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdLine[16], r2=qm.VoqInitCrdLine[16], r3=misc.port_mode,  */
literal|0x0c0103fe
block|,
literal|0x00010003
block|,
literal|0x0000050e
block|,
comment|/* (r1!=r2&&r3>0), r1=qm.VoqCrdLine[0:17], r2=qm.VoqInitCrdLine[0:17], r3=misc.port_mode,  */
literal|0x0b0103ff
block|,
literal|0x00010003
block|,
literal|0x00000511
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdByte[0:7], r2=qm.VoqInitCrdByte[0:7], r3=misc.port_mode,  */
literal|0x0b010400
block|,
literal|0x00010003
block|,
literal|0x00000514
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdByte[16], r2=qm.VoqInitCrdByte[16], r3=misc.port_mode,  */
literal|0x0c010401
block|,
literal|0x00010003
block|,
literal|0x00000517
block|,
comment|/* (r1!=r2&&r3>0), r1=qm.VoqCrdByte[0:17], r2=qm.VoqInitCrdByte[0:17], r3=misc.port_mode,  */
literal|0x0a010402
block|,
literal|0x00030001
block|,
literal|0x0043051a
block|,
comment|/* ((r1&0x30)>>4)!=(r1&0x03), r1=qm.PtrTblTx[0:447] width=2 access=WB,  */
literal|0x09010403
block|,
literal|0x00060001
block|,
literal|0x003d051b
block|,
comment|/* ((r1[0]&0x3FFFFFC0)>>6)!=(((r1[0]&0xC0000000)>>30)|((r1[1]&0x3FFFFF)<<2)), r1=qm.PtrTblTx[0:447] width=2 access=WB,  */
literal|0x01010404
block|,
literal|0x00010001
block|,
literal|0x002a051c
block|,
comment|/* (r1!=8190), r1=brb.wc_empty_0[0:3],  */
literal|0x01010405
block|,
literal|0x00010001
block|,
literal|0x0013051d
block|,
comment|/* (r1!=reset1), r1=brb.rc_eop_empty,  */
literal|0x01010406
block|,
literal|0x00010001
block|,
literal|0x000b051e
block|,
comment|/* (r1!=2), r1=brb.wc_status_0[0:3] width=3 access=WB,  */
literal|0x00000407
block|,
literal|0x00010302
block|,
literal|0x0000051f
block|,
comment|/* ((r1&~r2)!=0), r1=nig.PRTY_STS, r2=nig.PRTY_MASK,  */
literal|0x00000408
block|,
literal|0x00010202
block|,
literal|0x00000524
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_0, r2=btb.INT_MASK_0,  */
literal|0x00000409
block|,
literal|0x00010202
block|,
literal|0x00000528
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_4, r2=btb.INT_MASK_4,  */
literal|0x0100040a
block|,
literal|0x00010001
block|,
literal|0x0000052c
block|,
comment|/* (r1!=0), r1=xcm.msdm_length_mis,  */
literal|0x0101040b
block|,
literal|0x00010001
block|,
literal|0x0000052d
block|,
comment|/* (r1!=0), r1=xcm.is_msdm_fill_lvl,  */
literal|0x0101040c
block|,
literal|0x00010001
block|,
literal|0x0000052e
block|,
comment|/* (r1!=0), r1=xcm.is_ysem_fill_lvl,  */
literal|0x0101040d
block|,
literal|0x00010001
block|,
literal|0x0000052f
block|,
comment|/* (r1!=0), r1=xcm.qm_act_st_cnt[0:447],  */
literal|0x0100040e
block|,
literal|0x00010001
block|,
literal|0x00000530
block|,
comment|/* (r1!=0), r1=ycm.msdm_length_mis,  */
literal|0x0101040f
block|,
literal|0x00010001
block|,
literal|0x00000531
block|,
comment|/* (r1!=0), r1=ycm.is_msdm_fill_lvl,  */
literal|0x01000410
block|,
literal|0x00010001
block|,
literal|0x00000532
block|,
comment|/* (r1!=0), r1=pcm.psdm_length_mis,  */
literal|0x01010411
block|,
literal|0x00010001
block|,
literal|0x00000533
block|,
comment|/* (r1!=0), r1=pcm.is_psdm_fill_lvl,  */
literal|0x01000412
block|,
literal|0x00010001
block|,
literal|0x00000534
block|,
comment|/* (r1!=0), r1=tcm.tsdm_length_mis,  */
literal|0x01010413
block|,
literal|0x00010001
block|,
literal|0x00000535
block|,
comment|/* (r1!=0), r1=tcm.is_tsdm_fill_lvl,  */
literal|0x01000414
block|,
literal|0x00010001
block|,
literal|0x00000536
block|,
comment|/* (r1!=0), r1=mcm.msdm_length_mis,  */
literal|0x01010415
block|,
literal|0x00010001
block|,
literal|0x00000537
block|,
comment|/* (r1!=0), r1=mcm.is_msdm_fill_lvl,  */
literal|0x01010416
block|,
literal|0x00010001
block|,
literal|0x00000538
block|,
comment|/* (r1!=0), r1=mcm.is_ysem_fill_lvl,  */
literal|0x01020417
block|,
literal|0x00010001
block|,
literal|0x00000539
block|,
comment|/* (r1!=0), r1=xsem.vf_err_vector width=4 access=WB,  */
literal|0x01020418
block|,
literal|0x00010001
block|,
literal|0x0000053a
block|,
comment|/* (r1!=0), r1=ysem.vf_err_vector width=4 access=WB,  */
literal|0x01020419
block|,
literal|0x00010001
block|,
literal|0x0000053b
block|,
comment|/* (r1!=0), r1=psem.vf_err_vector width=4 access=WB,  */
literal|0x0102041a
block|,
literal|0x00010001
block|,
literal|0x0000053c
block|,
comment|/* (r1!=0), r1=tsem.vf_err_vector width=4 access=WB,  */
literal|0x0102041b
block|,
literal|0x00010001
block|,
literal|0x0000053d
block|,
comment|/* (r1!=0), r1=msem.vf_err_vector width=4 access=WB,  */
literal|0x0102041c
block|,
literal|0x00010001
block|,
literal|0x0000053e
block|,
comment|/* (r1!=0), r1=usem.vf_err_vector width=4 access=WB,  */
literal|0x005a0009
block|,
comment|/* mode k2 */
literal|0x0000041d
block|,
literal|0x00010002
block|,
literal|0x0000053f
block|,
comment|/* ((r1&~r2)!=0), r1=pcie.PRTY_STS_H_0, r2=pcie.PRTY_MASK_H_0,  */
literal|0x0102041e
block|,
literal|0x00010001
block|,
literal|0x00000541
block|,
comment|/* (r1!=0), r1=igu.pending_bits_status[0:11],  */
literal|0x0101041f
block|,
literal|0x00010001
block|,
literal|0x00000542
block|,
comment|/* (r1!=0), r1=igu.write_done_pending[0:11],  */
literal|0x01020420
block|,
literal|0x00010101
block|,
literal|0x00000543
block|,
comment|/* (r1!=0), r1=pswhst.vf_disabled_error_valid,  */
literal|0x01010421
block|,
literal|0x00010001
block|,
literal|0x00220545
block|,
comment|/* (r1!=reset1), r1=tcfc.cduwb_credit,  */
literal|0x01000422
block|,
literal|0x00010001
block|,
literal|0x00000546
block|,
comment|/* (r1!=0), r1=qm.QstatusTx_0[0:15],  */
literal|0x01000423
block|,
literal|0x00010001
block|,
literal|0x00000547
block|,
comment|/* (r1!=0), r1=qm.QstatusOther_0[0:3],  */
literal|0x0b010424
block|,
literal|0x00010003
block|,
literal|0x00000548
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdLine[0:7], r2=qm.VoqInitCrdLine[0:7], r3=misc.port_mode,  */
literal|0x0c010425
block|,
literal|0x00010003
block|,
literal|0x0000054b
block|,
comment|/* (r1!=r2&&r3>0), r1=qm.VoqCrdLine[0:19], r2=qm.VoqInitCrdLine[0:19], r3=misc.port_mode,  */
literal|0x0b010426
block|,
literal|0x00010003
block|,
literal|0x0000054e
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdLine[16], r2=qm.VoqInitCrdLine[16], r3=misc.port_mode,  */
literal|0x0b010427
block|,
literal|0x00010003
block|,
literal|0x00000551
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdByte[16], r2=qm.VoqInitCrdByte[16], r3=misc.port_mode,  */
literal|0x0c010428
block|,
literal|0x00010003
block|,
literal|0x00000554
block|,
comment|/* (r1!=r2&&r3>0), r1=qm.VoqCrdByte[0:19], r2=qm.VoqInitCrdByte[0:19], r3=misc.port_mode,  */
literal|0x0b010429
block|,
literal|0x00010003
block|,
literal|0x00000557
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdByte[0:7], r2=qm.VoqInitCrdByte[0:7], r3=misc.port_mode,  */
literal|0x0101042a
block|,
literal|0x00010001
block|,
literal|0x002a055a
block|,
comment|/* (r1!=8190), r1=brb.wc_empty_0[0:7],  */
literal|0x0101042b
block|,
literal|0x00010001
block|,
literal|0x0003055b
block|,
comment|/* (r1!=reset1), r1=brb.rc_eop_empty,  */
literal|0x0101042c
block|,
literal|0x00010001
block|,
literal|0x000b055c
block|,
comment|/* (r1!=2), r1=brb.wc_status_0[0:7] width=3 access=WB,  */
literal|0x0000042d
block|,
literal|0x00010202
block|,
literal|0x0000055d
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_0, r2=btb.INT_MASK_0,  */
literal|0x0000042e
block|,
literal|0x00010202
block|,
literal|0x00000561
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_4, r2=btb.INT_MASK_4,  */
literal|0x0100042f
block|,
literal|0x00010001
block|,
literal|0x00000565
block|,
comment|/* (r1!=0), r1=xcm.msdm_length_mis,  */
literal|0x01010430
block|,
literal|0x00010001
block|,
literal|0x00000566
block|,
comment|/* (r1!=0), r1=xcm.is_msdm_fill_lvl,  */
literal|0x01010431
block|,
literal|0x00010001
block|,
literal|0x00000567
block|,
comment|/* (r1!=0), r1=xcm.is_ysem_fill_lvl,  */
literal|0x01000432
block|,
literal|0x00010001
block|,
literal|0x00000568
block|,
comment|/* (r1!=0), r1=ycm.msdm_length_mis,  */
literal|0x01010433
block|,
literal|0x00010001
block|,
literal|0x00000569
block|,
comment|/* (r1!=0), r1=ycm.is_msdm_fill_lvl,  */
literal|0x01000434
block|,
literal|0x00010001
block|,
literal|0x0000056a
block|,
comment|/* (r1!=0), r1=pcm.psdm_length_mis,  */
literal|0x01010435
block|,
literal|0x00010001
block|,
literal|0x0000056b
block|,
comment|/* (r1!=0), r1=pcm.is_psdm_fill_lvl,  */
literal|0x01000436
block|,
literal|0x00010001
block|,
literal|0x0000056c
block|,
comment|/* (r1!=0), r1=tcm.tsdm_length_mis,  */
literal|0x01010437
block|,
literal|0x00010001
block|,
literal|0x0000056d
block|,
comment|/* (r1!=0), r1=tcm.is_tsdm_fill_lvl,  */
literal|0x01000438
block|,
literal|0x00010001
block|,
literal|0x0000056e
block|,
comment|/* (r1!=0), r1=mcm.msdm_length_mis,  */
literal|0x01010439
block|,
literal|0x00010001
block|,
literal|0x0000056f
block|,
comment|/* (r1!=0), r1=mcm.is_msdm_fill_lvl,  */
literal|0x0101043a
block|,
literal|0x00010001
block|,
literal|0x00000570
block|,
comment|/* (r1!=0), r1=mcm.is_ysem_fill_lvl,  */
literal|0x003f0021
block|,
comment|/* mode asic */
literal|0x0301043b
block|,
literal|0x00000002
block|,
literal|0x00000571
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_7, r2=pswrq2.max_srs_vq7,  */
literal|0x0301043c
block|,
literal|0x00000002
block|,
literal|0x00000573
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_8, r2=pswrq2.max_srs_vq8,  */
literal|0x0301043d
block|,
literal|0x00000002
block|,
literal|0x00000575
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_10, r2=pswrq2.max_srs_vq10,  */
literal|0x0301043e
block|,
literal|0x00000002
block|,
literal|0x00000577
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_13, r2=pswrq2.max_srs_vq13,  */
literal|0x0301043f
block|,
literal|0x00000002
block|,
literal|0x00000579
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_14, r2=pswrq2.max_srs_vq14,  */
literal|0x03010440
block|,
literal|0x00000002
block|,
literal|0x0000057b
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_20, r2=pswrq2.max_srs_vq20,  */
literal|0x03010441
block|,
literal|0x00000002
block|,
literal|0x0000057d
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_25, r2=pswrq2.max_srs_vq25,  */
literal|0x03010442
block|,
literal|0x00000002
block|,
literal|0x0000057f
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_27, r2=pswrq2.max_srs_vq27,  */
literal|0x03010443
block|,
literal|0x00000002
block|,
literal|0x00000581
block|,
comment|/* (r1!=r2), r1=pswrq2.sr_cnt_per_vq_31, r2=pswrq2.max_srs_vq31,  */
literal|0x03010444
block|,
literal|0x00000002
block|,
literal|0x00000583
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_7, r2=pswrq2.max_blks_vq7,  */
literal|0x03010445
block|,
literal|0x00000002
block|,
literal|0x00000585
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_8, r2=pswrq2.max_blks_vq8,  */
literal|0x03010446
block|,
literal|0x00000002
block|,
literal|0x00000587
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_10, r2=pswrq2.max_blks_vq10,  */
literal|0x03010447
block|,
literal|0x00000002
block|,
literal|0x00000589
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_13, r2=pswrq2.max_blks_vq13,  */
literal|0x03010448
block|,
literal|0x00000002
block|,
literal|0x0000058b
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_14, r2=pswrq2.max_blks_vq14,  */
literal|0x03010449
block|,
literal|0x00000002
block|,
literal|0x0000058d
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_20, r2=pswrq2.max_blks_vq20,  */
literal|0x0301044a
block|,
literal|0x00000002
block|,
literal|0x0000058f
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_25, r2=pswrq2.max_blks_vq25,  */
literal|0x0301044b
block|,
literal|0x00000002
block|,
literal|0x00000591
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_27, r2=pswrq2.max_blks_vq27,  */
literal|0x0301044c
block|,
literal|0x00000002
block|,
literal|0x00000593
block|,
comment|/* (r1!=r2), r1=pswrq2.blk_cnt_per_vq_31, r2=pswrq2.max_blks_vq31,  */
literal|0x0d02044d
block|,
literal|0x00010001
block|,
literal|0x00460595
block|,
comment|/* (r1&0x3E1), r1=tm.INT_STS_1,  */
literal|0x0000044e
block|,
literal|0x00010002
block|,
literal|0x00000596
block|,
comment|/* ((r1&~r2)!=0), r1=bmb.PRTY_STS_H_0, r2=bmb.PRTY_MASK_H_0,  */
literal|0x0000044f
block|,
literal|0x00010002
block|,
literal|0x00000598
block|,
comment|/* ((r1&~r2)!=0), r1=bmb.PRTY_STS_H_1, r2=bmb.PRTY_MASK_H_1,  */
literal|0x0003001f
block|,
comment|/* mode !asic */
literal|0x0d020450
block|,
literal|0x00010001
block|,
literal|0x0047059a
block|,
comment|/* (r1&0x381), r1=tm.INT_STS_1,  */
literal|0x00ab0025
block|,
comment|/* mode !bb */
literal|0x06020451
block|,
literal|0x00020001
block|,
literal|0x0048059b
block|,
comment|/* ((r1&0x2000)!=0), r1=pglcs.pgl_cs.UNCORR_ERR_STATUS_OFF,  */
literal|0x06000452
block|,
literal|0x00020001
block|,
literal|0x004a059c
block|,
comment|/* ((r1&0x0FD010)!=0), r1=pglcs.pgl_cs.UNCORR_ERR_STATUS_OFF,  */
literal|0x06020453
block|,
literal|0x00020001
block|,
literal|0x004c059d
block|,
comment|/* ((r1&0x100000)!=0), r1=pglcs.pgl_cs.UNCORR_ERR_STATUS_OFF,  */
literal|0x01020454
block|,
literal|0x00010001
block|,
literal|0x0000059e
block|,
comment|/* (r1!=0), r1=pglcs.pgl_cs.HDR_LOG_0_OFF[0:3],  */
literal|0x01000455
block|,
literal|0x00010001
block|,
literal|0x0000059f
block|,
comment|/* (r1!=0), r1=pglcs.syncfifo_pop_underflow,  */
literal|0x01000456
block|,
literal|0x00010001
block|,
literal|0x000005a0
block|,
comment|/* (r1!=0), r1=pglcs.syncfifo_push_overflow,  */
literal|0x01010457
block|,
literal|0x00010001
block|,
literal|0x000005a1
block|,
comment|/* (r1!=0), r1=pglcs.tx_syncfifo_pop_status,  */
literal|0x06000458
block|,
literal|0x00020001
block|,
literal|0x004e05a2
block|,
comment|/* ((r1&0xE001)!=0), r1=pcie.INT_STS,  */
literal|0x00000459
block|,
literal|0x00010102
block|,
literal|0x000005a3
block|,
comment|/* ((r1&~r2)!=0), r1=cnig.INT_STS, r2=cnig.INT_MASK,  */
literal|0x0000045a
block|,
literal|0x00010002
block|,
literal|0x000005a6
block|,
comment|/* ((r1&~r2)!=0), r1=cnig.PRTY_STS, r2=cnig.PRTY_MASK,  */
literal|0x0100045b
block|,
literal|0x00010001
block|,
literal|0x000005a8
block|,
comment|/* (r1!=0), r1=pglue_b.syncfifo_push_overflow,  */
literal|0x0100045c
block|,
literal|0x00010001
block|,
literal|0x000005a9
block|,
comment|/* (r1!=0), r1=pglue_b.syncfifo_pop_underflow,  */
literal|0x0101045d
block|,
literal|0x00010001
block|,
literal|0x000005aa
block|,
comment|/* (r1!=0), r1=pglue_b.rxh_syncfifo_pop_status,  */
literal|0x0101045e
block|,
literal|0x00010101
block|,
literal|0x000005ab
block|,
comment|/* (r1!=0), r1=pglue_b.rxd_syncfifo_pop_status,  */
literal|0x0901045f
block|,
literal|0x00060001
block|,
literal|0x003d05ad
block|,
comment|/* ((r1[0]&0x3FFFFFC0)>>6)!=(((r1[0]&0xC0000000)>>30)|((r1[1]&0x3FFFFF)<<2)), r1=qm.PtrTblOther[0:127] width=2 access=WB,  */
literal|0x0a010460
block|,
literal|0x00030001
block|,
literal|0x004305ae
block|,
comment|/* ((r1&0x30)>>4)!=(r1&0x03), r1=qm.PtrTblOther[0:127] width=2 access=WB,  */
literal|0x09010461
block|,
literal|0x00060001
block|,
literal|0x003d05af
block|,
comment|/* ((r1[0]&0x3FFFFFC0)>>6)!=(((r1[0]&0xC0000000)>>30)|((r1[1]&0x3FFFFF)<<2)), r1=qm.PtrTblTx[0:511] width=2 access=WB,  */
literal|0x0a010462
block|,
literal|0x00030001
block|,
literal|0x004305b0
block|,
comment|/* ((r1&0x30)>>4)!=(r1&0x03), r1=qm.PtrTblTx[0:511] width=2 access=WB,  */
literal|0x01010463
block|,
literal|0x00010001
block|,
literal|0x000005b1
block|,
comment|/* (r1!=0), r1=brb.mac2_tc_occupancy_0,  */
literal|0x01010464
block|,
literal|0x00010001
block|,
literal|0x000005b2
block|,
comment|/* (r1!=0), r1=brb.mac2_tc_occupancy_1,  */
literal|0x01010465
block|,
literal|0x00010001
block|,
literal|0x000005b3
block|,
comment|/* (r1!=0), r1=brb.mac2_tc_occupancy_2,  */
literal|0x01010466
block|,
literal|0x00010001
block|,
literal|0x000005b4
block|,
comment|/* (r1!=0), r1=brb.mac2_tc_occupancy_3,  */
literal|0x01010467
block|,
literal|0x00010001
block|,
literal|0x000005b5
block|,
comment|/* (r1!=0), r1=brb.mac2_tc_occupancy_4,  */
literal|0x01010468
block|,
literal|0x00010001
block|,
literal|0x000005b6
block|,
comment|/* (r1!=0), r1=brb.mac3_tc_occupancy_0,  */
literal|0x01010469
block|,
literal|0x00010001
block|,
literal|0x000005b7
block|,
comment|/* (r1!=0), r1=brb.mac3_tc_occupancy_1,  */
literal|0x0101046a
block|,
literal|0x00010001
block|,
literal|0x000005b8
block|,
comment|/* (r1!=0), r1=brb.mac3_tc_occupancy_2,  */
literal|0x0101046b
block|,
literal|0x00010001
block|,
literal|0x000005b9
block|,
comment|/* (r1!=0), r1=brb.mac3_tc_occupancy_3,  */
literal|0x0101046c
block|,
literal|0x00010001
block|,
literal|0x000005ba
block|,
comment|/* (r1!=0), r1=brb.mac3_tc_occupancy_4,  */
literal|0x0000046d
block|,
literal|0x00010002
block|,
literal|0x000005bb
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_6, r2=nig.INT_MASK_6,  */
literal|0x0002046e
block|,
literal|0x00010202
block|,
literal|0x000005bd
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_7, r2=nig.INT_MASK_7,  */
literal|0x0000046f
block|,
literal|0x00010002
block|,
literal|0x000005c1
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_8, r2=nig.INT_MASK_8,  */
literal|0x00020470
block|,
literal|0x00010202
block|,
literal|0x000005c3
block|,
comment|/* ((r1&~r2)!=0), r1=nig.INT_STS_9, r2=nig.INT_MASK_9,  */
literal|0x00000471
block|,
literal|0x00010302
block|,
literal|0x000005c7
block|,
comment|/* ((r1&~r2)!=0), r1=nig.PRTY_STS, r2=nig.PRTY_MASK,  */
literal|0x06000472
block|,
literal|0x00020001
block|,
literal|0x005005cc
block|,
comment|/* ((r1&0x00000004)!=4), r1=nws.common_status,  */
literal|0x06000473
block|,
literal|0x00020001
block|,
literal|0x005205cd
block|,
comment|/* ((r1&0x00000002)!=2), r1=nws.common_status,  */
literal|0x06000474
block|,
literal|0x00020001
block|,
literal|0x000d05ce
block|,
comment|/* ((r1&0x00000001)!=0), r1=nws.INT_STS_0,  */
literal|0x00000475
block|,
literal|0x00010002
block|,
literal|0x000005cf
block|,
comment|/* ((r1&~r2)!=0), r1=nws.PRTY_STS_H_0, r2=nws.PRTY_MASK_H_0,  */
literal|0x0e020476
block|,
literal|0x00040002
block|,
literal|0x005405d1
block|,
comment|/* ((r1!=1)&&(((r2>>14)&1)==1)), r1=nws.nws_cmu.ln0_top_phy_if_status, r2=nws.common_control,  */
literal|0x0e020477
block|,
literal|0x00040002
block|,
literal|0x005805d3
block|,
comment|/* ((r1!=1)&&(((r2>>15)&1)==1)), r1=nws.nws_cmu.ln1_top_phy_if_status, r2=nws.common_control,  */
literal|0x0e020478
block|,
literal|0x00040002
block|,
literal|0x005c05d5
block|,
comment|/* ((r1!=1)&&(((r2>>16)&1)==1)), r1=nws.nws_cmu.ln2_top_phy_if_status, r2=nws.common_control,  */
literal|0x0e020479
block|,
literal|0x00040002
block|,
literal|0x006005d7
block|,
comment|/* ((r1!=1)&&(((r2>>17)&1)==1)), r1=nws.nws_cmu.ln3_top_phy_if_status, r2=nws.common_control,  */
literal|0x0600047a
block|,
literal|0x00020001
block|,
literal|0x000d05d9
block|,
comment|/* ((r1&0x00000001)!=0), r1=nwm.INT_STS,  */
literal|0x0600047b
block|,
literal|0x00020001
block|,
literal|0x006405da
block|,
comment|/* ((r1&0x000001FE)!=0), r1=nwm.INT_STS,  */
literal|0x0000047c
block|,
literal|0x00010002
block|,
literal|0x000005db
block|,
comment|/* ((r1&~r2)!=0), r1=nwm.PRTY_STS_H_0, r2=nwm.PRTY_MASK_H_0,  */
literal|0x0000047d
block|,
literal|0x00010002
block|,
literal|0x000005dd
block|,
comment|/* ((r1&~r2)!=0), r1=nwm.PRTY_STS_H_1, r2=nwm.PRTY_MASK_H_1,  */
literal|0x0000047e
block|,
literal|0x00010002
block|,
literal|0x000005df
block|,
comment|/* ((r1&~r2)!=0), r1=nwm.PRTY_STS_H_2, r2=nwm.PRTY_MASK_H_2,  */
literal|0x0101047f
block|,
literal|0x00010001
block|,
literal|0x002305e1
block|,
comment|/* (r1!=255), r1=btb.rc_pkt_empty_4,  */
literal|0x01010480
block|,
literal|0x00010001
block|,
literal|0x002305e2
block|,
comment|/* (r1!=255), r1=btb.rc_pkt_empty_5,  */
literal|0x01010481
block|,
literal|0x00010001
block|,
literal|0x002305e3
block|,
comment|/* (r1!=255), r1=btb.rc_pkt_empty_6,  */
literal|0x01010482
block|,
literal|0x00010001
block|,
literal|0x002305e4
block|,
comment|/* (r1!=255), r1=btb.rc_pkt_empty_7,  */
literal|0x01010483
block|,
literal|0x00010001
block|,
literal|0x000005e5
block|,
comment|/* (r1!=0), r1=xcm.qm_act_st_cnt[0:511],  */
literal|0x01020484
block|,
literal|0x00010001
block|,
literal|0x000005e6
block|,
comment|/* (r1!=0), r1=xsem.vf_err_vector width=8 access=WB,  */
literal|0x01020485
block|,
literal|0x00010001
block|,
literal|0x000005e7
block|,
comment|/* (r1!=0), r1=ysem.vf_err_vector width=8 access=WB,  */
literal|0x01020486
block|,
literal|0x00010001
block|,
literal|0x000005e8
block|,
comment|/* (r1!=0), r1=psem.vf_err_vector width=8 access=WB,  */
literal|0x01020487
block|,
literal|0x00010001
block|,
literal|0x000005e9
block|,
comment|/* (r1!=0), r1=tsem.vf_err_vector width=8 access=WB,  */
literal|0x01020488
block|,
literal|0x00010001
block|,
literal|0x000005ea
block|,
comment|/* (r1!=0), r1=msem.vf_err_vector width=8 access=WB,  */
literal|0x01020489
block|,
literal|0x00010001
block|,
literal|0x000005eb
block|,
comment|/* (r1!=0), r1=usem.vf_err_vector width=8 access=WB,  */
literal|0x00480003
block|,
comment|/* mode !(bb|k2) */
literal|0x0102048a
block|,
literal|0x00010001
block|,
literal|0x000005ec
block|,
comment|/* (r1!=0), r1=igu.pending_bits_status[0:15],  */
literal|0x0101048b
block|,
literal|0x00010001
block|,
literal|0x000005ed
block|,
comment|/* (r1!=0), r1=igu.write_done_pending[0:15],  */
literal|0x0101048c
block|,
literal|0x00010001
block|,
literal|0x002d05ee
block|,
comment|/* (r1!=reset1), r1=tcfc.cduwb_credit,  */
literal|0x0c01048d
block|,
literal|0x00010003
block|,
literal|0x000005ef
block|,
comment|/* (r1!=r2&&r3>0), r1=qm.VoqCrdLine[0:35], r2=qm.VoqInitCrdLine[0:35], r3=misc.port_mode,  */
literal|0x0b01048e
block|,
literal|0x00010003
block|,
literal|0x000005f2
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdLine[0:7], r2=qm.VoqInitCrdLine[0:7], r3=misc.port_mode,  */
literal|0x0b01048f
block|,
literal|0x00010003
block|,
literal|0x000005f5
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdLine[16], r2=qm.VoqInitCrdLine[16], r3=misc.port_mode,  */
literal|0x0b010490
block|,
literal|0x00010003
block|,
literal|0x000005f8
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdByte[16], r2=qm.VoqInitCrdByte[16], r3=misc.port_mode,  */
literal|0x0b010491
block|,
literal|0x00010003
block|,
literal|0x000005fb
block|,
comment|/* (r1!=r2&&r3==0), r1=qm.VoqCrdByte[0:7], r2=qm.VoqInitCrdByte[0:7], r3=misc.port_mode,  */
literal|0x0c010492
block|,
literal|0x00010003
block|,
literal|0x000005fe
block|,
comment|/* (r1!=r2&&r3>0), r1=qm.VoqCrdByte[0:35], r2=qm.VoqInitCrdByte[0:35], r3=misc.port_mode,  */
literal|0x01010493
block|,
literal|0x00010001
block|,
literal|0x000d0601
block|,
comment|/* (r1!=reset1), r1=brb.rc_eop_empty,  */
literal|0x00000494
block|,
literal|0x00010202
block|,
literal|0x00000602
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_0, r2=btb.INT_MASK_0,  */
literal|0x00000495
block|,
literal|0x00010202
block|,
literal|0x00000606
block|,
comment|/* ((r1&~r2)!=0), r1=btb.INT_STS_4, r2=btb.INT_MASK_4,  */
literal|0x01000496
block|,
literal|0x00010001
block|,
literal|0x0000060a
block|,
comment|/* (r1!=0), r1=xcm.msdm_length_mis,  */
literal|0x01010497
block|,
literal|0x00010001
block|,
literal|0x0000060b
block|,
comment|/* (r1!=0), r1=xcm.is_msdm_fill_lvl,  */
literal|0x01010498
block|,
literal|0x00010001
block|,
literal|0x0000060c
block|,
comment|/* (r1!=0), r1=xcm.is_ysem_fill_lvl,  */
literal|0x01000499
block|,
literal|0x00010001
block|,
literal|0x0000060d
block|,
comment|/* (r1!=0), r1=ycm.msdm_length_mis,  */
literal|0x0101049a
block|,
literal|0x00010001
block|,
literal|0x0000060e
block|,
comment|/* (r1!=0), r1=ycm.is_msdm_fill_lvl,  */
literal|0x0100049b
block|,
literal|0x00010001
block|,
literal|0x0000060f
block|,
comment|/* (r1!=0), r1=pcm.psdm_length_mis,  */
literal|0x0101049c
block|,
literal|0x00010001
block|,
literal|0x00000610
block|,
comment|/* (r1!=0), r1=pcm.is_psdm_fill_lvl,  */
literal|0x0100049d
block|,
literal|0x00010001
block|,
literal|0x00000611
block|,
comment|/* (r1!=0), r1=tcm.tsdm_length_mis,  */
literal|0x0101049e
block|,
literal|0x00010001
block|,
literal|0x00000612
block|,
comment|/* (r1!=0), r1=tcm.is_tsdm_fill_lvl,  */
literal|0x0100049f
block|,
literal|0x00010001
block|,
literal|0x00000613
block|,
comment|/* (r1!=0), r1=mcm.msdm_length_mis,  */
literal|0x010104a0
block|,
literal|0x00010001
block|,
literal|0x00000614
block|,
comment|/* (r1!=0), r1=mcm.is_msdm_fill_lvl,  */
literal|0x010104a1
block|,
literal|0x00010001
block|,
literal|0x00000615
block|,
comment|/* (r1!=0), r1=mcm.is_ysem_fill_lvl,  */
literal|0x00240015
block|,
comment|/* mode !(k2|e5) */
literal|0x060004a2
block|,
literal|0x00020001
block|,
literal|0x004a0616
block|,
comment|/* ((r1&0x0FD010)!=0), r1=pglcs.pgl_cs.uc_err_status,  */
literal|0x060204a3
block|,
literal|0x00020001
block|,
literal|0x00480617
block|,
comment|/* ((r1&0x2000)!=0), r1=pglcs.pgl_cs.uc_err_status,  */
literal|0x060204a4
block|,
literal|0x00020001
block|,
literal|0x004c0618
block|,
comment|/* ((r1&0x100000)!=0), r1=pglcs.pgl_cs.uc_err_status,  */
literal|0x010204a5
block|,
literal|0x00010001
block|,
literal|0x00000619
block|,
comment|/* (r1!=0), r1=pglcs.pgl_cs.header_log1[0:3],  */
literal|0x060204a6
block|,
literal|0x00020001
block|,
literal|0x0066061a
block|,
comment|/* ((r1&0x2000000)!=0), r1=pglcs.pgl_cs.tl_ctrlstat_5,  */
literal|0x040004a7
block|,
literal|0x00020001
block|,
literal|0x0068061b
block|,
comment|/* ((r1&~0x2040902)!=0), r1=pglcs.pgl_cs.tl_ctrlstat_5,  */
literal|0x040004a8
block|,
literal|0x00020001
block|,
literal|0x006a061c
block|,
comment|/* ((r1&~0x10240902)!=0), r1=pglcs.pgl_cs.tl_func345_stat,  */
literal|0x040004a9
block|,
literal|0x00020001
block|,
literal|0x006a061d
block|,
comment|/* ((r1&~0x10240902)!=0), r1=pglcs.pgl_cs.tl_func678_stat,  */
literal|0x060004aa
block|,
literal|0x00020001
block|,
literal|0x000b061e
block|,
comment|/* ((r1&0x2)!=0), r1=pglcs.pgl_cs.DLATTN_VEC,  */
literal|0x000004ab
block|,
literal|0x00010002
block|,
literal|0x0000061f
block|,
comment|/* ((r1&~r2)!=0), r1=miscs.INT_STS_1, r2=miscs.INT_MASK_1,  */
literal|0x000004ac
block|,
literal|0x00010002
block|,
literal|0x00000621
block|,
comment|/* ((r1&~r2)!=0), r1=igu.PRTY_STS_H_1, r2=igu.PRTY_MASK_H_1,  */
literal|0x010104ad
block|,
literal|0x00010001
block|,
literal|0x000d0623
block|,
comment|/* (r1!=1), r1=nig.rx_macfifo_empty,  */
literal|0x01590043
block|,
comment|/* mode !e5 */
literal|0x000004ae
block|,
literal|0x00010002
block|,
literal|0x00000624
block|,
comment|/* ((r1&~r2)!=0), r1=opte.PRTY_STS_H_0, r2=opte.PRTY_MASK_H_0,  */
literal|0x010204af
block|,
literal|0x00010001
block|,
literal|0x00000626
block|,
comment|/* (r1!=0), r1=cau.agg_units_0to15_state,  */
literal|0x010204b0
block|,
literal|0x00010001
block|,
literal|0x00000627
block|,
comment|/* (r1!=0), r1=cau.agg_units_16to31_state,  */
literal|0x010204b1
block|,
literal|0x00010001
block|,
literal|0x00000628
block|,
comment|/* (r1!=0), r1=cau.agg_units_32to47_state,  */
literal|0x010204b2
block|,
literal|0x00010001
block|,
literal|0x00000629
block|,
comment|/* (r1!=0), r1=cau.agg_units_48to63_state,  */
literal|0x010204b3
block|,
literal|0x00010001
block|,
literal|0x0000062a
block|,
comment|/* (r1!=0), r1=cau.igu_cqe_cmd_fsm_status,  */
literal|0x010204b4
block|,
literal|0x00010001
block|,
literal|0x0000062b
block|,
comment|/* (r1!=0), r1=cau.igu_cqe_agg_fsm_status,  */
literal|0x000004b5
block|,
literal|0x00010002
block|,
literal|0x0000062c
block|,
comment|/* ((r1&~r2)!=0), r1=prs.PRTY_STS_H_1, r2=prs.PRTY_MASK_H_1,  */
literal|0x010104b6
block|,
literal|0x00010001
block|,
literal|0x0000062e
block|,
comment|/* (r1!=0), r1=prs.prs_pkt_ct,  */
literal|0x010104b7
block|,
literal|0x00010001
block|,
literal|0x0000062f
block|,
comment|/* (r1!=0), r1=prs.tcm_current_credit,  */
literal|0x010204b8
block|,
literal|0x00010001
block|,
literal|0x006c0630
block|,
comment|/* (r1!=31), r1=rss.empty_status,  */
literal|0x010204b9
block|,
literal|0x00010001
block|,
literal|0x00000631
block|,
comment|/* (r1!=0), r1=rss.full_status,  */
literal|0x010204ba
block|,
literal|0x00010001
block|,
literal|0x00000632
block|,
comment|/* (r1!=0), r1=rss.counters_status,  */
literal|0x010104bb
block|,
literal|0x00010001
block|,
literal|0x00000633
block|,
comment|/* (r1!=0), r1=rss.state_machines,  */
literal|0x010104bc
block|,
literal|0x00010001
block|,
literal|0x00000634
block|,
comment|/* (r1!=0), r1=yuld.pending_msg_to_ext_ev_1_ctr,  */
literal|0x010104bd
block|,
literal|0x00010001
block|,
literal|0x00000635
block|,
comment|/* (r1!=0), r1=yuld.pending_msg_to_ext_ev_2_ctr,  */
literal|0x010104be
block|,
literal|0x00010001
block|,
literal|0x00000636
block|,
comment|/* (r1!=0), r1=yuld.pending_msg_to_ext_ev_3_ctr,  */
literal|0x010104bf
block|,
literal|0x00010001
block|,
literal|0x00000637
block|,
comment|/* (r1!=0), r1=yuld.pending_msg_to_ext_ev_4_ctr,  */
literal|0x010104c0
block|,
literal|0x00010001
block|,
literal|0x00000638
block|,
comment|/* (r1!=0), r1=yuld.pending_msg_to_ext_ev_5_ctr,  */
literal|0x030104c1
block|,
literal|0x00000002
block|,
literal|0x00000639
block|,
comment|/* (r1!=r2), r1=yuld.foc_remain_credits, r2=yuld.foci_foc_credits,  */
literal|0x010104c2
block|,
literal|0x00010001
block|,
literal|0x0000063b
block|,
comment|/* (r1!=0), r1=yuld.dbg_pending_ccfc_req,  */
literal|0x010104c3
block|,
literal|0x00010001
block|,
literal|0x0000063c
block|,
comment|/* (r1!=0), r1=yuld.dbg_pending_tcfc_req,  */
literal|0x000004c4
block|,
literal|0x00010002
block|,
literal|0x0000063d
block|,
comment|/* ((r1&~r2)!=0), r1=yuld.PRTY_STS_H_0, r2=yuld.PRTY_MASK_H_0,  */
literal|0x010104c5
block|,
literal|0x00010001
block|,
literal|0x000d063f
block|,
comment|/* (r1!=1), r1=nig.tx_macfifo_empty,  */
literal|0x000004c6
block|,
literal|0x00010002
block|,
literal|0x00000640
block|,
comment|/* ((r1&~r2)!=0), r1=pbf.PRTY_STS_H_0, r2=pbf.PRTY_MASK_H_0,  */
literal|0x000004c7
block|,
literal|0x00010002
block|,
literal|0x00000642
block|,
comment|/* ((r1&~r2)!=0), r1=pbf.PRTY_STS_H_1, r2=pbf.PRTY_MASK_H_1,  */
literal|0x010004c8
block|,
literal|0x00010001
block|,
literal|0x00000644
block|,
comment|/* (r1!=0), r1=pcm.pbf_length_mis,  */
literal|0x010104c9
block|,
literal|0x00010001
block|,
literal|0x00000645
block|,
comment|/* (r1!=0), r1=pcm.is_pbf_fill_lvl,  */
literal|0x010004ca
block|,
literal|0x00010001
block|,
literal|0x00000646
block|,
comment|/* (r1!=0), r1=tcm.prs_length_mis,  */
literal|0x010104cb
block|,
literal|0x00010001
block|,
literal|0x00000647
block|,
comment|/* (r1!=0), r1=tcm.is_prs_fill_lvl,  */
literal|0x010004cc
block|,
literal|0x00010001
block|,
literal|0x00000648
block|,
comment|/* (r1!=0), r1=ucm.yuld_length_mis,  */
literal|0x010104cd
block|,
literal|0x00010001
block|,
literal|0x00000649
block|,
comment|/* (r1!=0), r1=ucm.is_yuld_fill_lvl,  */
literal|0x000004ce
block|,
literal|0x00010002
block|,
literal|0x0000064a
block|,
comment|/* ((r1&~r2)!=0), r1=xsem.PRTY_STS_H_0, r2=xsem.PRTY_MASK_H_0,  */
literal|0x010204cf
block|,
literal|0x00010001
block|,
literal|0x0000064c
block|,
comment|/* (r1!=0), r1=xsem.thread_error,  */
literal|0x010104d0
block|,
literal|0x00010001
block|,
literal|0x0000064d
block|,
comment|/* (r1!=0), r1=xsem.thread_rdy,  */
literal|0x010104d1
block|,
literal|0x00010001
block|,
literal|0x0000064e
block|,
comment|/* (r1!=0), r1=xsem.thread_valid,  */
literal|0x010104d2
block|,
literal|0x00010001
block|,
literal|0x000d064f
block|,
comment|/* (r1!=1), r1=xsem.dra_empty,  */
literal|0x010104d3
block|,
literal|0x00010001
block|,
literal|0x000d0650
block|,
comment|/* (r1!=1), r1=xsem.slow_dbg_empty,  */
literal|0x010104d4
block|,
literal|0x00010001
block|,
literal|0x000d0651
block|,
comment|/* (r1!=1), r1=xsem.slow_dra_fin_empty,  */
literal|0x010104d5
block|,
literal|0x00010001
block|,
literal|0x000d0652
block|,
comment|/* (r1!=1), r1=xsem.slow_dra_rd_empty,  */
literal|0x010104d6
block|,
literal|0x00010001
block|,
literal|0x000d0653
block|,
comment|/* (r1!=1), r1=xsem.slow_dra_wr_empty,  */
literal|0x010104d7
block|,
literal|0x00010001
block|,
literal|0x000d0654
block|,
comment|/* (r1!=1), r1=xsem.slow_ram_rd_empty,  */
literal|0x010104d8
block|,
literal|0x00010001
block|,
literal|0x000d0655
block|,
comment|/* (r1!=1), r1=xsem.thread_fifo_empty,  */
literal|0x010104d9
block|,
literal|0x00010001
block|,
literal|0x00000656
block|,
comment|/* (r1!=0), r1=xsem.pas_if_full,  */
literal|0x010204da
block|,
literal|0x00010001
block|,
literal|0x00000657
block|,
comment|/* (r1!=0), r1=xsem.thread_orun_num,  */
literal|0x010104db
block|,
literal|0x00010001
block|,
literal|0x00000658
block|,
comment|/* (r1!=0), r1=xsem.dbg_if_full,  */
literal|0x000004dc
block|,
literal|0x00010002
block|,
literal|0x00000659
block|,
comment|/* ((r1&~r2)!=0), r1=ysem.PRTY_STS_H_0, r2=ysem.PRTY_MASK_H_0,  */
literal|0x010204dd
block|,
literal|0x00010001
block|,
literal|0x0000065b
block|,
comment|/* (r1!=0), r1=ysem.thread_error,  */
literal|0x010104de
block|,
literal|0x00010001
block|,
literal|0x0000065c
block|,
comment|/* (r1!=0), r1=ysem.thread_rdy,  */
literal|0x010104df
block|,
literal|0x00010001
block|,
literal|0x0000065d
block|,
comment|/* (r1!=0), r1=ysem.thread_valid,  */
literal|0x010104e0
block|,
literal|0x00010001
block|,
literal|0x000d065e
block|,
comment|/* (r1!=1), r1=ysem.dra_empty,  */
literal|0x010104e1
block|,
literal|0x00010001
block|,
literal|0x000d065f
block|,
comment|/* (r1!=1), r1=ysem.slow_dbg_empty,  */
literal|0x010104e2
block|,
literal|0x00010001
block|,
literal|0x000d0660
block|,
comment|/* (r1!=1), r1=ysem.slow_dra_fin_empty,  */
literal|0x010104e3
block|,
literal|0x00010001
block|,
literal|0x000d0661
block|,
comment|/* (r1!=1), r1=ysem.slow_dra_rd_empty,  */
literal|0x010104e4
block|,
literal|0x00010001
block|,
literal|0x000d0662
block|,
comment|/* (r1!=1), r1=ysem.slow_dra_wr_empty,  */
literal|0x010104e5
block|,
literal|0x00010001
block|,
literal|0x000d0663
block|,
comment|/* (r1!=1), r1=ysem.slow_ram_rd_empty,  */
literal|0x010104e6
block|,
literal|0x00010001
block|,
literal|0x000d0664
block|,
comment|/* (r1!=1), r1=ysem.thread_fifo_empty,  */
literal|0x010104e7
block|,
literal|0x00010001
block|,
literal|0x00000665
block|,
comment|/* (r1!=0), r1=ysem.pas_if_full,  */
literal|0x010204e8
block|,
literal|0x00010001
block|,
literal|0x00000666
block|,
comment|/* (r1!=0), r1=ysem.thread_orun_num,  */
literal|0x010104e9
block|,
literal|0x00010001
block|,
literal|0x00000667
block|,
comment|/* (r1!=0), r1=ysem.dbg_if_full,  */
literal|0x000004ea
block|,
literal|0x00010002
block|,
literal|0x00000668
block|,
comment|/* ((r1&~r2)!=0), r1=psem.PRTY_STS_H_0, r2=psem.PRTY_MASK_H_0,  */
literal|0x010204eb
block|,
literal|0x00010001
block|,
literal|0x0000066a
block|,
comment|/* (r1!=0), r1=psem.thread_error,  */
literal|0x010104ec
block|,
literal|0x00010001
block|,
literal|0x0000066b
block|,
comment|/* (r1!=0), r1=psem.thread_rdy,  */
literal|0x010104ed
block|,
literal|0x00010001
block|,
literal|0x0000066c
block|,
comment|/* (r1!=0), r1=psem.thread_valid,  */
literal|0x010104ee
block|,
literal|0x00010001
block|,
literal|0x000d066d
block|,
comment|/* (r1!=1), r1=psem.dra_empty,  */
literal|0x010104ef
block|,
literal|0x00010001
block|,
literal|0x000d066e
block|,
comment|/* (r1!=1), r1=psem.slow_dbg_empty,  */
literal|0x010104f0
block|,
literal|0x00010001
block|,
literal|0x000d066f
block|,
comment|/* (r1!=1), r1=psem.slow_dra_fin_empty,  */
literal|0x010104f1
block|,
literal|0x00010001
block|,
literal|0x000d0670
block|,
comment|/* (r1!=1), r1=psem.slow_dra_rd_empty,  */
literal|0x010104f2
block|,
literal|0x00010001
block|,
literal|0x000d0671
block|,
comment|/* (r1!=1), r1=psem.slow_dra_wr_empty,  */
literal|0x010104f3
block|,
literal|0x00010001
block|,
literal|0x000d0672
block|,
comment|/* (r1!=1), r1=psem.slow_ram_rd_empty,  */
literal|0x010104f4
block|,
literal|0x00010001
block|,
literal|0x000d0673
block|,
comment|/* (r1!=1), r1=psem.thread_fifo_empty,  */
literal|0x010104f5
block|,
literal|0x00010001
block|,
literal|0x00000674
block|,
comment|/* (r1!=0), r1=psem.pas_if_full,  */
literal|0x010204f6
block|,
literal|0x00010001
block|,
literal|0x00000675
block|,
comment|/* (r1!=0), r1=psem.thread_orun_num,  */
literal|0x010104f7
block|,
literal|0x00010001
block|,
literal|0x00000676
block|,
comment|/* (r1!=0), r1=psem.dbg_if_full,  */
literal|0x000004f8
block|,
literal|0x00010002
block|,
literal|0x00000677
block|,
comment|/* ((r1&~r2)!=0), r1=tsem.PRTY_STS_H_0, r2=tsem.PRTY_MASK_H_0,  */
literal|0x010204f9
block|,
literal|0x00010001
block|,
literal|0x00000679
block|,
comment|/* (r1!=0), r1=tsem.thread_error,  */
literal|0x010104fa
block|,
literal|0x00010001
block|,
literal|0x0000067a
block|,
comment|/* (r1!=0), r1=tsem.thread_rdy,  */
literal|0x010104fb
block|,
literal|0x00010001
block|,
literal|0x0000067b
block|,
comment|/* (r1!=0), r1=tsem.thread_valid,  */
literal|0x010104fc
block|,
literal|0x00010001
block|,
literal|0x000d067c
block|,
comment|/* (r1!=1), r1=tsem.dra_empty,  */
literal|0x010104fd
block|,
literal|0x00010001
block|,
literal|0x000d067d
block|,
comment|/* (r1!=1), r1=tsem.slow_dbg_empty,  */
literal|0x010104fe
block|,
literal|0x00010001
block|,
literal|0x000d067e
block|,
comment|/* (r1!=1), r1=tsem.slow_dra_fin_empty,  */
literal|0x010104ff
block|,
literal|0x00010001
block|,
literal|0x000d067f
block|,
comment|/* (r1!=1), r1=tsem.slow_dra_rd_empty,  */
literal|0x01010500
block|,
literal|0x00010001
block|,
literal|0x000d0680
block|,
comment|/* (r1!=1), r1=tsem.slow_dra_wr_empty,  */
literal|0x01010501
block|,
literal|0x00010001
block|,
literal|0x000d0681
block|,
comment|/* (r1!=1), r1=tsem.slow_ram_rd_empty,  */
literal|0x01010502
block|,
literal|0x00010001
block|,
literal|0x000d0682
block|,
comment|/* (r1!=1), r1=tsem.thread_fifo_empty,  */
literal|0x01010503
block|,
literal|0x00010001
block|,
literal|0x00000683
block|,
comment|/* (r1!=0), r1=tsem.pas_if_full,  */
literal|0x01020504
block|,
literal|0x00010001
block|,
literal|0x00000684
block|,
comment|/* (r1!=0), r1=tsem.thread_orun_num,  */
literal|0x01010505
block|,
literal|0x00010001
block|,
literal|0x00000685
block|,
comment|/* (r1!=0), r1=tsem.dbg_if_full,  */
literal|0x01020506
block|,
literal|0x00010001
block|,
literal|0x00000686
block|,
comment|/* (r1!=0), r1=msem.thread_error,  */
literal|0x01010507
block|,
literal|0x00010001
block|,
literal|0x00000687
block|,
comment|/* (r1!=0), r1=msem.thread_rdy,  */
literal|0x01010508
block|,
literal|0x00010001
block|,
literal|0x00000688
block|,
comment|/* (r1!=0), r1=msem.thread_valid,  */
literal|0x01010509
block|,
literal|0x00010001
block|,
literal|0x000d0689
block|,
comment|/* (r1!=1), r1=msem.dra_empty,  */
literal|0x0101050a
block|,
literal|0x00010001
block|,
literal|0x000d068a
block|,
comment|/* (r1!=1), r1=msem.slow_dbg_empty,  */
literal|0x0101050b
block|,
literal|0x00010001
block|,
literal|0x000d068b
block|,
comment|/* (r1!=1), r1=msem.slow_dra_fin_empty,  */
literal|0x0101050c
block|,
literal|0x00010001
block|,
literal|0x000d068c
block|,
comment|/* (r1!=1), r1=msem.slow_dra_rd_empty,  */
literal|0x0101050d
block|,
literal|0x00010001
block|,
literal|0x000d068d
block|,
comment|/* (r1!=1), r1=msem.slow_dra_wr_empty,  */
literal|0x0101050e
block|,
literal|0x00010001
block|,
literal|0x000d068e
block|,
comment|/* (r1!=1), r1=msem.slow_ram_rd_empty,  */
literal|0x0101050f
block|,
literal|0x00010001
block|,
literal|0x000d068f
block|,
comment|/* (r1!=1), r1=msem.thread_fifo_empty,  */
literal|0x01010510
block|,
literal|0x00010001
block|,
literal|0x00000690
block|,
comment|/* (r1!=0), r1=msem.pas_if_full,  */
literal|0x01020511
block|,
literal|0x00010001
block|,
literal|0x00000691
block|,
comment|/* (r1!=0), r1=msem.thread_orun_num,  */
literal|0x01010512
block|,
literal|0x00010001
block|,
literal|0x00000692
block|,
comment|/* (r1!=0), r1=msem.dbg_if_full,  */
literal|0x00000513
block|,
literal|0x00010002
block|,
literal|0x00000693
block|,
comment|/* ((r1&~r2)!=0), r1=usem.PRTY_STS_H_0, r2=usem.PRTY_MASK_H_0,  */
literal|0x01020514
block|,
literal|0x00010001
block|,
literal|0x00000695
block|,
comment|/* (r1!=0), r1=usem.thread_error,  */
literal|0x01010515
block|,
literal|0x00010001
block|,
literal|0x00000696
block|,
comment|/* (r1!=0), r1=usem.thread_rdy,  */
literal|0x01010516
block|,
literal|0x00010001
block|,
literal|0x00000697
block|,
comment|/* (r1!=0), r1=usem.thread_valid,  */
literal|0x01010517
block|,
literal|0x00010001
block|,
literal|0x000d0698
block|,
comment|/* (r1!=1), r1=usem.dra_empty,  */
literal|0x01010518
block|,
literal|0x00010001
block|,
literal|0x000d0699
block|,
comment|/* (r1!=1), r1=usem.slow_dbg_empty,  */
literal|0x01010519
block|,
literal|0x00010001
block|,
literal|0x000d069a
block|,
comment|/* (r1!=1), r1=usem.slow_dra_fin_empty,  */
literal|0x0101051a
block|,
literal|0x00010001
block|,
literal|0x000d069b
block|,
comment|/* (r1!=1), r1=usem.slow_dra_rd_empty,  */
literal|0x0101051b
block|,
literal|0x00010001
block|,
literal|0x000d069c
block|,
comment|/* (r1!=1), r1=usem.slow_dra_wr_empty,  */
literal|0x0101051c
block|,
literal|0x00010001
block|,
literal|0x000d069d
block|,
comment|/* (r1!=1), r1=usem.slow_ram_rd_empty,  */
literal|0x0101051d
block|,
literal|0x00010001
block|,
literal|0x000d069e
block|,
comment|/* (r1!=1), r1=usem.thread_fifo_empty,  */
literal|0x0101051e
block|,
literal|0x00010001
block|,
literal|0x0000069f
block|,
comment|/* (r1!=0), r1=usem.pas_if_full,  */
literal|0x0102051f
block|,
literal|0x00010001
block|,
literal|0x000006a0
block|,
comment|/* (r1!=0), r1=usem.thread_orun_num,  */
literal|0x01010520
block|,
literal|0x00010001
block|,
literal|0x000006a1
block|,
comment|/* (r1!=0), r1=usem.dbg_if_full,  */
literal|0x0006001d
block|,
comment|/* mode !(!asic) */
literal|0x00000521
block|,
literal|0x00010002
block|,
literal|0x000006a2
block|,
comment|/* ((r1&~r2)!=0), r1=mcp2.PRTY_STS, r2=mcp2.PRTY_MASK,  */
literal|0x00000522
block|,
literal|0x00010002
block|,
literal|0x000006a4
block|,
comment|/* ((r1&~r2)!=0), r1=mcp2.PRTY_STS_H_0, r2=mcp2.PRTY_MASK_H_0,  */
literal|0x0003000b
block|,
comment|/* mode !(emul_reduced|fpga) */
literal|0x00000523
block|,
literal|0x00010002
block|,
literal|0x000006a6
block|,
comment|/* ((r1&~r2)!=0), r1=ncsi.PRTY_STS_H_0, r2=ncsi.PRTY_MASK_H_0,  */
literal|0x006000c3
block|,
comment|/* mode (!bb)&(!(!asic)) */
literal|0x06000524
block|,
literal|0x00020001
block|,
literal|0x000b06a8
block|,
comment|/* ((r1&0x00000002)!=0), r1=umac.INT_STS,  */
literal|0x06000525
block|,
literal|0x00020001
block|,
literal|0x000d06a9
block|,
comment|/* ((r1&0x00000001)!=0), r1=umac.INT_STS,  */
literal|0x01020526
block|,
literal|0x00010001
block|,
literal|0x000006aa
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.phy0_top_err_ctrl0,  */
literal|0x01020527
block|,
literal|0x00010001
block|,
literal|0x000006ab
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.phy0_top_err_ctrl1,  */
literal|0x01020528
block|,
literal|0x00010001
block|,
literal|0x000006ac
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.phy0_top_err_ctrl2,  */
literal|0x06000529
block|,
literal|0x00020001
block|,
literal|0x006d06ad
block|,
comment|/* ((r1&0x00000004)!=0), r1=nws.nws_cmu.phy0_top_regbus_err_info_status0,  */
literal|0x0600052a
block|,
literal|0x00020001
block|,
literal|0x000b06ae
block|,
comment|/* ((r1&0x00000002)!=0), r1=nws.nws_cmu.phy0_top_regbus_err_info_status0,  */
literal|0x0600052b
block|,
literal|0x00020001
block|,
literal|0x000d06af
block|,
comment|/* ((r1&0x00000001)!=0), r1=nws.nws_cmu.phy0_top_regbus_err_info_status0,  */
literal|0x0100052c
block|,
literal|0x00010001
block|,
literal|0x000006b0
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.phy0_top_regbus_err_info_status0,  */
literal|0x0100052d
block|,
literal|0x00010001
block|,
literal|0x000006b1
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.phy0_top_regbus_err_info_status1,  */
literal|0x0100052e
block|,
literal|0x00010001
block|,
literal|0x000006b2
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.phy0_top_regbus_err_info_status2,  */
literal|0x0100052f
block|,
literal|0x00010001
block|,
literal|0x000006b3
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.phy0_top_regbus_err_info_status3,  */
literal|0x01000530
block|,
literal|0x00010001
block|,
literal|0x000d06b4
block|,
comment|/* (r1!=1), r1=nws.nws_cmu.cmu_lc0_top_phy_if_status,  */
literal|0x01000531
block|,
literal|0x00010001
block|,
literal|0x000006b5
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.cmu_lc0_top_err_ctrl1,  */
literal|0x01000532
block|,
literal|0x00010001
block|,
literal|0x000006b6
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.cmu_lc0_top_err_ctrl2,  */
literal|0x01000533
block|,
literal|0x00010001
block|,
literal|0x000006b7
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.cmu_lc0_top_err_ctrl3,  */
literal|0x01000534
block|,
literal|0x00010001
block|,
literal|0x000d06b8
block|,
comment|/* (r1!=1), r1=nws.nws_cmu.cmu_r0_top_phy_if_status,  */
literal|0x01000535
block|,
literal|0x00010001
block|,
literal|0x000006b9
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.cmu_r0_top_err_ctrl1,  */
literal|0x01000536
block|,
literal|0x00010001
block|,
literal|0x000006ba
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.cmu_r0_top_err_ctrl2,  */
literal|0x01000537
block|,
literal|0x00010001
block|,
literal|0x000006bb
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.cmu_r0_top_err_ctrl3,  */
literal|0x01020538
block|,
literal|0x00010001
block|,
literal|0x000006bc
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln0_top_err_ctrl1,  */
literal|0x01020539
block|,
literal|0x00010001
block|,
literal|0x000006bd
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln0_top_err_ctrl2,  */
literal|0x0102053a
block|,
literal|0x00010001
block|,
literal|0x000006be
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln0_top_err_ctrl3,  */
literal|0x0102053b
block|,
literal|0x00010001
block|,
literal|0x000006bf
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln1_top_err_ctrl1,  */
literal|0x0102053c
block|,
literal|0x00010001
block|,
literal|0x000006c0
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln1_top_err_ctrl2,  */
literal|0x0102053d
block|,
literal|0x00010001
block|,
literal|0x000006c1
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln1_top_err_ctrl3,  */
literal|0x0102053e
block|,
literal|0x00010001
block|,
literal|0x000006c2
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln2_top_err_ctrl1,  */
literal|0x0102053f
block|,
literal|0x00010001
block|,
literal|0x000006c3
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln2_top_err_ctrl2,  */
literal|0x01020540
block|,
literal|0x00010001
block|,
literal|0x000006c4
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln2_top_err_ctrl3,  */
literal|0x01020541
block|,
literal|0x00010001
block|,
literal|0x000006c5
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln3_top_err_ctrl1,  */
literal|0x01020542
block|,
literal|0x00010001
block|,
literal|0x000006c6
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln3_top_err_ctrl2,  */
literal|0x01020543
block|,
literal|0x00010001
block|,
literal|0x000006c7
block|,
comment|/* (r1!=0), r1=nws.nws_cmu.ln3_top_err_ctrl3,  */
literal|0x0003018d
block|,
comment|/* mode bb&asic */
literal|0x00000544
block|,
literal|0x00010002
block|,
literal|0x000006c8
block|,
comment|/* ((r1&~r2)!=0), r1=ipc.PRTY_STS, r2=ipc.PRTY_MASK,  */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 16240 bytes */
end_comment

begin_comment
comment|/* Array of attentions data per register */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|attn_reg
index|[]
init|=
block|{
literal|0x00000000
block|,
literal|0x05014060
block|,
literal|0x00014063
block|,
literal|0x00014061
block|,
comment|/* grc.INT_STS_0 */
literal|0x00000000
block|,
literal|0x02014080
block|,
literal|0x00014083
block|,
literal|0x00014081
block|,
comment|/* grc.PRTY_STS_H_0 */
literal|0x00000000
block|,
literal|0x03002460
block|,
literal|0x00002463
block|,
literal|0x00002461
block|,
comment|/* miscs.INT_STS_0 */
literal|0x00030015
block|,
literal|0x0b002464
block|,
literal|0x00002467
block|,
literal|0x00002465
block|,
comment|/* miscs.INT_STS_1, mode !(k2|e5) */
literal|0x00000000
block|,
literal|0x01002468
block|,
literal|0x0000246b
block|,
literal|0x00002469
block|,
comment|/* miscs.PRTY_STS_0 */
literal|0x00000000
block|,
literal|0x01002060
block|,
literal|0x00002063
block|,
literal|0x00002061
block|,
comment|/* misc.INT_STS */
literal|0x00000000
block|,
literal|0x180aa060
block|,
literal|0x000aa063
block|,
literal|0x000aa061
block|,
comment|/* pglue_b.INT_STS */
literal|0x00000000
block|,
literal|0x010aa064
block|,
literal|0x000aa067
block|,
literal|0x000aa065
block|,
comment|/* pglue_b.PRTY_STS */
literal|0x012a0007
block|,
literal|0x160aa080
block|,
literal|0x000aa083
block|,
literal|0x000aa081
block|,
comment|/* pglue_b.PRTY_STS_H_0, mode bb */
literal|0x00010025
block|,
literal|0x1f0aa080
block|,
literal|0x000aa083
block|,
literal|0x000aa081
block|,
comment|/* pglue_b.PRTY_STS_H_0, mode !bb */
literal|0x00200025
block|,
literal|0x030aa084
block|,
literal|0x000aa087
block|,
literal|0x000aa085
block|,
comment|/* pglue_b.PRTY_STS_H_1, mode !bb */
literal|0x01400007
block|,
literal|0x060860ba
block|,
literal|0x000860bd
block|,
literal|0x000860bb
block|,
comment|/* cnig.INT_STS, mode bb */
literal|0x00000025
block|,
literal|0x07086086
block|,
literal|0x00086089
block|,
literal|0x00086087
block|,
comment|/* cnig.INT_STS, mode !bb */
literal|0x01460007
block|,
literal|0x020860d2
block|,
literal|0x000860d5
block|,
literal|0x000860d3
block|,
comment|/* cnig.PRTY_STS, mode bb */
literal|0x01480025
block|,
literal|0x0208608b
block|,
literal|0x0008608e
block|,
literal|0x0008608c
block|,
comment|/* cnig.PRTY_STS, mode !bb */
literal|0x00000000
block|,
literal|0x0100c0f8
block|,
literal|0x0000c0fb
block|,
literal|0x0000c0f9
block|,
comment|/* cpmu.INT_STS_0 */
literal|0x00000000
block|,
literal|0x01010133
block|,
literal|0x00010136
block|,
literal|0x00010134
block|,
comment|/* ncsi.INT_STS_0 */
literal|0x00000000
block|,
literal|0x03010000
block|,
literal|0x00010003
block|,
literal|0x00010001
block|,
comment|/* ncsi.PRTY_STS_H_0 */
literal|0x00000043
block|,
literal|0x01014c82
block|,
literal|0x00014c85
block|,
literal|0x00014c83
block|,
comment|/* opte.PRTY_STS, mode !e5 */
literal|0x00010043
block|,
literal|0x0b014c00
block|,
literal|0x00014c03
block|,
literal|0x00014c01
block|,
comment|/* opte.PRTY_STS_H_0, mode !e5 */
literal|0x014a0000
block|,
literal|0x17150030
block|,
literal|0x00150033
block|,
literal|0x00150031
block|,
comment|/* bmb.INT_STS_0 */
literal|0x01610000
block|,
literal|0x20150036
block|,
literal|0x00150039
block|,
literal|0x00150037
block|,
comment|/* bmb.INT_STS_1 */
literal|0x01810000
block|,
literal|0x1c15003c
block|,
literal|0x0015003f
block|,
literal|0x0015003d
block|,
comment|/* bmb.INT_STS_2 */
literal|0x019d0000
block|,
literal|0x20150042
block|,
literal|0x00150045
block|,
literal|0x00150043
block|,
comment|/* bmb.INT_STS_3 */
literal|0x01bd0000
block|,
literal|0x1d150048
block|,
literal|0x0015004b
block|,
literal|0x00150049
block|,
comment|/* bmb.INT_STS_4 */
literal|0x01da0000
block|,
literal|0x2015004e
block|,
literal|0x00150051
block|,
literal|0x0015004f
block|,
comment|/* bmb.INT_STS_5 */
literal|0x01fa0000
block|,
literal|0x20150054
block|,
literal|0x00150057
block|,
literal|0x00150055
block|,
comment|/* bmb.INT_STS_6 */
literal|0x00bb0000
block|,
literal|0x2015005a
block|,
literal|0x0015005d
block|,
literal|0x0015005b
block|,
comment|/* bmb.INT_STS_7 */
literal|0x00db0000
block|,
literal|0x20150061
block|,
literal|0x00150064
block|,
literal|0x00150062
block|,
comment|/* bmb.INT_STS_8 */
literal|0x021a0000
block|,
literal|0x25150067
block|,
literal|0x0015006a
block|,
literal|0x00150068
block|,
comment|/* bmb.INT_STS_9 */
literal|0x023f0000
block|,
literal|0x0715006d
block|,
literal|0x00150070
block|,
literal|0x0015006e
block|,
comment|/* bmb.INT_STS_10 */
literal|0x02460000
block|,
literal|0x08150073
block|,
literal|0x00150076
block|,
literal|0x00150074
block|,
comment|/* bmb.INT_STS_11 */
literal|0x00000000
block|,
literal|0x05150077
block|,
literal|0x0015007a
block|,
literal|0x00150078
block|,
comment|/* bmb.PRTY_STS */
literal|0x024e0000
block|,
literal|0x2e150100
block|,
literal|0x00150103
block|,
literal|0x00150101
block|,
comment|/* bmb.PRTY_STS_H_0 */
literal|0x027c0007
block|,
literal|0x0f150104
block|,
literal|0x00150107
block|,
literal|0x00150105
block|,
comment|/* bmb.PRTY_STS_H_1, mode bb */
literal|0x027c0009
block|,
literal|0x0f150104
block|,
literal|0x00150107
block|,
literal|0x00150105
block|,
comment|/* bmb.PRTY_STS_H_1, mode k2 */
literal|0x028b0003
block|,
literal|0x17150104
block|,
literal|0x00150107
block|,
literal|0x00150105
block|,
comment|/* bmb.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x00000025
block|,
literal|0x110151e8
block|,
literal|0x000151eb
block|,
literal|0x000151e9
block|,
comment|/* pcie.INT_STS, mode !bb */
literal|0x00000025
block|,
literal|0x030151ec
block|,
literal|0x000151ef
block|,
literal|0x000151ed
block|,
comment|/* pcie.PRTY_STS, mode !bb */
literal|0x02a20007
block|,
literal|0x11015000
block|,
literal|0x00015003
block|,
literal|0x00015001
block|,
comment|/* pcie.PRTY_STS_H_0, mode bb */
literal|0x00030025
block|,
literal|0x08015000
block|,
literal|0x00015003
block|,
literal|0x00015001
block|,
comment|/* pcie.PRTY_STS_H_0, mode !bb */
literal|0x00000000
block|,
literal|0x01014810
block|,
literal|0x00014813
block|,
literal|0x00014811
block|,
comment|/* mcp2.PRTY_STS */
literal|0x00010000
block|,
literal|0x0c014881
block|,
literal|0x00014884
block|,
literal|0x00014882
block|,
comment|/* mcp2.PRTY_STS_H_0 */
literal|0x00000000
block|,
literal|0x120a8060
block|,
literal|0x000a8063
block|,
literal|0x000a8061
block|,
comment|/* pswhst.INT_STS */
literal|0x00000000
block|,
literal|0x010a8064
block|,
literal|0x000a8067
block|,
literal|0x000a8065
block|,
comment|/* pswhst.PRTY_STS */
literal|0x00010000
block|,
literal|0x110a8080
block|,
literal|0x000a8083
block|,
literal|0x000a8081
block|,
comment|/* pswhst.PRTY_STS_H_0 */
literal|0x00000000
block|,
literal|0x050a7860
block|,
literal|0x000a7863
block|,
literal|0x000a7861
block|,
comment|/* pswhst2.INT_STS */
literal|0x00000000
block|,
literal|0x010a7864
block|,
literal|0x000a7867
block|,
literal|0x000a7865
block|,
comment|/* pswhst2.PRTY_STS */
literal|0x00000000
block|,
literal|0x030a7060
block|,
literal|0x000a7063
block|,
literal|0x000a7061
block|,
comment|/* pswrd.INT_STS */
literal|0x00000000
block|,
literal|0x010a7064
block|,
literal|0x000a7067
block|,
literal|0x000a7065
block|,
comment|/* pswrd.PRTY_STS */
literal|0x00000000
block|,
literal|0x050a7460
block|,
literal|0x000a7463
block|,
literal|0x000a7461
block|,
comment|/* pswrd2.INT_STS */
literal|0x00000000
block|,
literal|0x010a7464
block|,
literal|0x000a7467
block|,
literal|0x000a7465
block|,
comment|/* pswrd2.PRTY_STS */
literal|0x02b30007
block|,
literal|0x1f0a7480
block|,
literal|0x000a7483
block|,
literal|0x000a7481
block|,
comment|/* pswrd2.PRTY_STS_H_0, mode bb */
literal|0x02b30009
block|,
literal|0x1f0a7480
block|,
literal|0x000a7483
block|,
literal|0x000a7481
block|,
comment|/* pswrd2.PRTY_STS_H_0, mode k2 */
literal|0x00010003
block|,
literal|0x1f0a7480
block|,
literal|0x000a7483
block|,
literal|0x000a7481
block|,
comment|/* pswrd2.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x02d20007
block|,
literal|0x030a7484
block|,
literal|0x000a7487
block|,
literal|0x000a7485
block|,
comment|/* pswrd2.PRTY_STS_H_1, mode bb */
literal|0x02d20009
block|,
literal|0x030a7484
block|,
literal|0x000a7487
block|,
literal|0x000a7485
block|,
comment|/* pswrd2.PRTY_STS_H_1, mode k2 */
literal|0x02d50003
block|,
literal|0x030a7484
block|,
literal|0x000a7487
block|,
literal|0x000a7485
block|,
comment|/* pswrd2.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x130a6860
block|,
literal|0x000a6863
block|,
literal|0x000a6861
block|,
comment|/* pswwr.INT_STS */
literal|0x00000000
block|,
literal|0x010a6864
block|,
literal|0x000a6867
block|,
literal|0x000a6865
block|,
comment|/* pswwr.PRTY_STS */
literal|0x00000000
block|,
literal|0x160a6c60
block|,
literal|0x000a6c63
block|,
literal|0x000a6c61
block|,
comment|/* pswwr2.INT_STS */
literal|0x00000000
block|,
literal|0x010a6c64
block|,
literal|0x000a6c67
block|,
literal|0x000a6c65
block|,
comment|/* pswwr2.PRTY_STS */
literal|0x02d80007
block|,
literal|0x1f0a6c80
block|,
literal|0x000a6c83
block|,
literal|0x000a6c81
block|,
comment|/* pswwr2.PRTY_STS_H_0, mode bb */
literal|0x02d80009
block|,
literal|0x1f0a6c80
block|,
literal|0x000a6c83
block|,
literal|0x000a6c81
block|,
comment|/* pswwr2.PRTY_STS_H_0, mode k2 */
literal|0x00010003
block|,
literal|0x1f0a6c80
block|,
literal|0x000a6c83
block|,
literal|0x000a6c81
block|,
comment|/* pswwr2.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x02f70007
block|,
literal|0x1f0a6c84
block|,
literal|0x000a6c87
block|,
literal|0x000a6c85
block|,
comment|/* pswwr2.PRTY_STS_H_1, mode bb */
literal|0x02f70009
block|,
literal|0x1f0a6c84
block|,
literal|0x000a6c87
block|,
literal|0x000a6c85
block|,
comment|/* pswwr2.PRTY_STS_H_1, mode k2 */
literal|0x03160003
block|,
literal|0x1f0a6c84
block|,
literal|0x000a6c87
block|,
literal|0x000a6c85
block|,
comment|/* pswwr2.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x03350007
block|,
literal|0x1f0a6c88
block|,
literal|0x000a6c8b
block|,
literal|0x000a6c89
block|,
comment|/* pswwr2.PRTY_STS_H_2, mode bb */
literal|0x03350009
block|,
literal|0x1f0a6c88
block|,
literal|0x000a6c8b
block|,
literal|0x000a6c89
block|,
comment|/* pswwr2.PRTY_STS_H_2, mode k2 */
literal|0x03540003
block|,
literal|0x1f0a6c88
block|,
literal|0x000a6c8b
block|,
literal|0x000a6c89
block|,
comment|/* pswwr2.PRTY_STS_H_2, mode !(bb|k2) */
literal|0x03730007
block|,
literal|0x140a6c8c
block|,
literal|0x000a6c8f
block|,
literal|0x000a6c8d
block|,
comment|/* pswwr2.PRTY_STS_H_3, mode bb */
literal|0x03730009
block|,
literal|0x140a6c8c
block|,
literal|0x000a6c8f
block|,
literal|0x000a6c8d
block|,
comment|/* pswwr2.PRTY_STS_H_3, mode k2 */
literal|0x03870003
block|,
literal|0x1f0a6c8c
block|,
literal|0x000a6c8f
block|,
literal|0x000a6c8d
block|,
comment|/* pswwr2.PRTY_STS_H_3, mode !(bb|k2) */
literal|0x03a60003
block|,
literal|0x0d0a6c90
block|,
literal|0x000a6c93
block|,
literal|0x000a6c91
block|,
comment|/* pswwr2.PRTY_STS_H_4, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x170a0060
block|,
literal|0x000a0063
block|,
literal|0x000a0061
block|,
comment|/* pswrq.INT_STS */
literal|0x00000000
block|,
literal|0x010a0064
block|,
literal|0x000a0067
block|,
literal|0x000a0065
block|,
comment|/* pswrq.PRTY_STS */
literal|0x00000000
block|,
literal|0x0f090060
block|,
literal|0x00090063
block|,
literal|0x00090061
block|,
comment|/* pswrq2.INT_STS */
literal|0x03b30007
block|,
literal|0x09090080
block|,
literal|0x00090083
block|,
literal|0x00090081
block|,
comment|/* pswrq2.PRTY_STS_H_0, mode bb */
literal|0x00000025
block|,
literal|0x0a090080
block|,
literal|0x00090083
block|,
literal|0x00090081
block|,
comment|/* pswrq2.PRTY_STS_H_0, mode !bb */
literal|0x00000000
block|,
literal|0x02000740
block|,
literal|0x00000743
block|,
literal|0x00000741
block|,
comment|/* pglcs.INT_STS */
literal|0x00000000
block|,
literal|0x02003060
block|,
literal|0x00003063
block|,
literal|0x00003061
block|,
comment|/* dmae.INT_STS */
literal|0x00000000
block|,
literal|0x03003080
block|,
literal|0x00003083
block|,
literal|0x00003081
block|,
comment|/* dmae.PRTY_STS_H_0 */
literal|0x00000000
block|,
literal|0x08158060
block|,
literal|0x00158063
block|,
literal|0x00158061
block|,
comment|/* ptu.INT_STS */
literal|0x03bc0007
block|,
literal|0x12158080
block|,
literal|0x00158083
block|,
literal|0x00158081
block|,
comment|/* ptu.PRTY_STS_H_0, mode bb */
literal|0x03bc0009
block|,
literal|0x12158080
block|,
literal|0x00158083
block|,
literal|0x00158081
block|,
comment|/* ptu.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x11158080
block|,
literal|0x00158083
block|,
literal|0x00158081
block|,
comment|/* ptu.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x03ce0007
block|,
literal|0x08460060
block|,
literal|0x00460063
block|,
literal|0x00460061
block|,
comment|/* tcm.INT_STS_0, mode bb */
literal|0x03ce0009
block|,
literal|0x08460060
block|,
literal|0x00460063
block|,
literal|0x00460061
block|,
comment|/* tcm.INT_STS_0, mode k2 */
literal|0x00000003
block|,
literal|0x0e460060
block|,
literal|0x00460063
block|,
literal|0x00460061
block|,
comment|/* tcm.INT_STS_0, mode !(bb|k2) */
literal|0x03d60000
block|,
literal|0x22460064
block|,
literal|0x00460067
block|,
literal|0x00460065
block|,
comment|/* tcm.INT_STS_1 */
literal|0x00300000
block|,
literal|0x01460068
block|,
literal|0x0046006b
block|,
literal|0x00460069
block|,
comment|/* tcm.INT_STS_2 */
literal|0x03f80007
block|,
literal|0x1f460080
block|,
literal|0x00460083
block|,
literal|0x00460081
block|,
comment|/* tcm.PRTY_STS_H_0, mode bb */
literal|0x04170009
block|,
literal|0x1f460080
block|,
literal|0x00460083
block|,
literal|0x00460081
block|,
comment|/* tcm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f460080
block|,
literal|0x00460083
block|,
literal|0x00460081
block|,
comment|/* tcm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00390007
block|,
literal|0x02460084
block|,
literal|0x00460087
block|,
literal|0x00460085
block|,
comment|/* tcm.PRTY_STS_H_1, mode bb */
literal|0x04360009
block|,
literal|0x03460084
block|,
literal|0x00460087
block|,
literal|0x00460085
block|,
comment|/* tcm.PRTY_STS_H_1, mode k2 */
literal|0x04390003
block|,
literal|0x0a460084
block|,
literal|0x00460087
block|,
literal|0x00460085
block|,
comment|/* tcm.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x04430007
block|,
literal|0x0e480060
block|,
literal|0x00480063
block|,
literal|0x00480061
block|,
comment|/* mcm.INT_STS_0, mode bb */
literal|0x04430009
block|,
literal|0x0e480060
block|,
literal|0x00480063
block|,
literal|0x00480061
block|,
comment|/* mcm.INT_STS_0, mode k2 */
literal|0x00000003
block|,
literal|0x14480060
block|,
literal|0x00480063
block|,
literal|0x00480061
block|,
comment|/* mcm.INT_STS_0, mode !(bb|k2) */
literal|0x00140000
block|,
literal|0x1a480064
block|,
literal|0x00480067
block|,
literal|0x00480065
block|,
comment|/* mcm.INT_STS_1 */
literal|0x002e0000
block|,
literal|0x01480068
block|,
literal|0x0048006b
block|,
literal|0x00480069
block|,
comment|/* mcm.INT_STS_2 */
literal|0x04510007
block|,
literal|0x1f480080
block|,
literal|0x00480083
block|,
literal|0x00480081
block|,
comment|/* mcm.PRTY_STS_H_0, mode bb */
literal|0x04510009
block|,
literal|0x1f480080
block|,
literal|0x00480083
block|,
literal|0x00480081
block|,
comment|/* mcm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f480080
block|,
literal|0x00480083
block|,
literal|0x00480081
block|,
comment|/* mcm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00300007
block|,
literal|0x04480084
block|,
literal|0x00480087
block|,
literal|0x00480085
block|,
comment|/* mcm.PRTY_STS_H_1, mode bb */
literal|0x00300009
block|,
literal|0x04480084
block|,
literal|0x00480087
block|,
literal|0x00480085
block|,
comment|/* mcm.PRTY_STS_H_1, mode k2 */
literal|0x04700003
block|,
literal|0x0a480084
block|,
literal|0x00480087
block|,
literal|0x00480085
block|,
comment|/* mcm.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x047a0000
block|,
literal|0x144a0060
block|,
literal|0x004a0063
block|,
literal|0x004a0061
block|,
comment|/* ucm.INT_STS_0 */
literal|0x00150007
block|,
literal|0x1d4a0064
block|,
literal|0x004a0067
block|,
literal|0x004a0065
block|,
comment|/* ucm.INT_STS_1, mode bb */
literal|0x00150009
block|,
literal|0x1d4a0064
block|,
literal|0x004a0067
block|,
literal|0x004a0065
block|,
comment|/* ucm.INT_STS_1, mode k2 */
literal|0x00140003
block|,
literal|0x1e4a0064
block|,
literal|0x004a0067
block|,
literal|0x004a0065
block|,
comment|/* ucm.INT_STS_1, mode !(bb|k2) */
literal|0x00320000
block|,
literal|0x014a0068
block|,
literal|0x004a006b
block|,
literal|0x004a0069
block|,
comment|/* ucm.INT_STS_2 */
literal|0x048e0007
block|,
literal|0x1f4a0080
block|,
literal|0x004a0083
block|,
literal|0x004a0081
block|,
comment|/* ucm.PRTY_STS_H_0, mode bb */
literal|0x048e0009
block|,
literal|0x1f4a0080
block|,
literal|0x004a0083
block|,
literal|0x004a0081
block|,
comment|/* ucm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f4a0080
block|,
literal|0x004a0083
block|,
literal|0x004a0081
block|,
comment|/* ucm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x002a0000
block|,
literal|0x074a0084
block|,
literal|0x004a0087
block|,
literal|0x004a0085
block|,
comment|/* ucm.PRTY_STS_H_1 */
literal|0x00000000
block|,
literal|0x12400060
block|,
literal|0x00400063
block|,
literal|0x00400061
block|,
comment|/* xcm.INT_STS_0 */
literal|0x00120000
block|,
literal|0x19400064
block|,
literal|0x00400067
block|,
literal|0x00400065
block|,
comment|/* xcm.INT_STS_1 */
literal|0x002b0000
block|,
literal|0x08400068
block|,
literal|0x0040006b
block|,
literal|0x00400069
block|,
comment|/* xcm.INT_STS_2 */
literal|0x04ad0007
block|,
literal|0x1f400080
block|,
literal|0x00400083
block|,
literal|0x00400081
block|,
comment|/* xcm.PRTY_STS_H_0, mode bb */
literal|0x04cc0009
block|,
literal|0x1f400080
block|,
literal|0x00400083
block|,
literal|0x00400081
block|,
comment|/* xcm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f400080
block|,
literal|0x00400083
block|,
literal|0x00400081
block|,
comment|/* xcm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x04eb0007
block|,
literal|0x0b400084
block|,
literal|0x00400087
block|,
literal|0x00400085
block|,
comment|/* xcm.PRTY_STS_H_1, mode bb */
literal|0x04f60009
block|,
literal|0x0c400084
block|,
literal|0x00400087
block|,
literal|0x00400085
block|,
comment|/* xcm.PRTY_STS_H_1, mode k2 */
literal|0x05020003
block|,
literal|0x0d400084
block|,
literal|0x00400087
block|,
literal|0x00400085
block|,
comment|/* xcm.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x0f420060
block|,
literal|0x00420063
block|,
literal|0x00420061
block|,
comment|/* ycm.INT_STS_0 */
literal|0x000f0000
block|,
literal|0x17420064
block|,
literal|0x00420067
block|,
literal|0x00420065
block|,
comment|/* ycm.INT_STS_1 */
literal|0x00260000
block|,
literal|0x01420068
block|,
literal|0x0042006b
block|,
literal|0x00420069
block|,
comment|/* ycm.INT_STS_2 */
literal|0x050f0007
block|,
literal|0x1f420080
block|,
literal|0x00420083
block|,
literal|0x00420081
block|,
comment|/* ycm.PRTY_STS_H_0, mode bb */
literal|0x052e0009
block|,
literal|0x1f420080
block|,
literal|0x00420083
block|,
literal|0x00420081
block|,
comment|/* ycm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f420080
block|,
literal|0x00420083
block|,
literal|0x00420081
block|,
comment|/* ycm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00370007
block|,
literal|0x03420084
block|,
literal|0x00420087
block|,
literal|0x00420085
block|,
comment|/* ycm.PRTY_STS_H_1, mode bb */
literal|0x054d0009
block|,
literal|0x04420084
block|,
literal|0x00420087
block|,
literal|0x00420085
block|,
comment|/* ycm.PRTY_STS_H_1, mode k2 */
literal|0x05510003
block|,
literal|0x09420084
block|,
literal|0x00420087
block|,
literal|0x00420085
block|,
comment|/* ycm.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x09440060
block|,
literal|0x00440063
block|,
literal|0x00440061
block|,
comment|/* pcm.INT_STS_0 */
literal|0x055a0007
block|,
literal|0x0e440064
block|,
literal|0x00440067
block|,
literal|0x00440065
block|,
comment|/* pcm.INT_STS_1, mode bb */
literal|0x055a0009
block|,
literal|0x0e440064
block|,
literal|0x00440067
block|,
literal|0x00440065
block|,
comment|/* pcm.INT_STS_1, mode k2 */
literal|0x00090003
block|,
literal|0x0c440064
block|,
literal|0x00440067
block|,
literal|0x00440065
block|,
comment|/* pcm.INT_STS_1, mode !(bb|k2) */
literal|0x00170000
block|,
literal|0x01440068
block|,
literal|0x0044006b
block|,
literal|0x00440069
block|,
comment|/* pcm.INT_STS_2 */
literal|0x05680007
block|,
literal|0x0b440080
block|,
literal|0x00440083
block|,
literal|0x00440081
block|,
comment|/* pcm.PRTY_STS_H_0, mode bb */
literal|0x05730009
block|,
literal|0x0f440080
block|,
literal|0x00440083
block|,
literal|0x00440081
block|,
comment|/* pcm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x11440080
block|,
literal|0x00440083
block|,
literal|0x00440081
block|,
comment|/* pcm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x160bc060
block|,
literal|0x000bc063
block|,
literal|0x000bc061
block|,
comment|/* qm.INT_STS */
literal|0x00000000
block|,
literal|0x0b0bc064
block|,
literal|0x000bc067
block|,
literal|0x000bc065
block|,
comment|/* qm.PRTY_STS */
literal|0x05820007
block|,
literal|0x1f0bc080
block|,
literal|0x000bc083
block|,
literal|0x000bc081
block|,
comment|/* qm.PRTY_STS_H_0, mode bb */
literal|0x05820009
block|,
literal|0x1f0bc080
block|,
literal|0x000bc083
block|,
literal|0x000bc081
block|,
comment|/* qm.PRTY_STS_H_0, mode k2 */
literal|0x000b0003
block|,
literal|0x1f0bc080
block|,
literal|0x000bc083
block|,
literal|0x000bc081
block|,
comment|/* qm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x05a10007
block|,
literal|0x1f0bc084
block|,
literal|0x000bc087
block|,
literal|0x000bc085
block|,
comment|/* qm.PRTY_STS_H_1, mode bb */
literal|0x05a10009
block|,
literal|0x1f0bc084
block|,
literal|0x000bc087
block|,
literal|0x000bc085
block|,
comment|/* qm.PRTY_STS_H_1, mode k2 */
literal|0x05c00003
block|,
literal|0x1f0bc084
block|,
literal|0x000bc087
block|,
literal|0x000bc085
block|,
comment|/* qm.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x05df0007
block|,
literal|0x0b0bc088
block|,
literal|0x000bc08b
block|,
literal|0x000bc089
block|,
comment|/* qm.PRTY_STS_H_2, mode bb */
literal|0x00000025
block|,
literal|0x000bc088
block|,
literal|0x000bc08b
block|,
literal|0x000bc089
block|,
comment|/* qm.PRTY_STS_H_2, mode !bb */
literal|0x00000000
block|,
literal|0x200b0060
block|,
literal|0x000b0063
block|,
literal|0x000b0061
block|,
comment|/* tm.INT_STS_0 */
literal|0x00200000
block|,
literal|0x0b0b0064
block|,
literal|0x000b0067
block|,
literal|0x000b0065
block|,
comment|/* tm.INT_STS_1 */
literal|0x05ea0007
block|,
literal|0x110b0080
block|,
literal|0x000b0083
block|,
literal|0x000b0081
block|,
comment|/* tm.PRTY_STS_H_0, mode bb */
literal|0x05ea0009
block|,
literal|0x110b0080
block|,
literal|0x000b0083
block|,
literal|0x000b0081
block|,
comment|/* tm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0f0b0080
block|,
literal|0x000b0083
block|,
literal|0x000b0081
block|,
comment|/* tm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x0c040060
block|,
literal|0x00040063
block|,
literal|0x00040061
block|,
comment|/* dorq.INT_STS */
literal|0x00000000
block|,
literal|0x01040064
block|,
literal|0x00040067
block|,
literal|0x00040065
block|,
comment|/* dorq.PRTY_STS */
literal|0x05fb0007
block|,
literal|0x06040080
block|,
literal|0x00040083
block|,
literal|0x00040081
block|,
comment|/* dorq.PRTY_STS_H_0, mode bb */
literal|0x05fb0009
block|,
literal|0x06040080
block|,
literal|0x00040083
block|,
literal|0x00040081
block|,
comment|/* dorq.PRTY_STS_H_0, mode k2 */
literal|0x00010003
block|,
literal|0x0c040080
block|,
literal|0x00040083
block|,
literal|0x00040081
block|,
comment|/* dorq.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x200d0030
block|,
literal|0x000d0033
block|,
literal|0x000d0031
block|,
comment|/* brb.INT_STS_0 */
literal|0x06010000
block|,
literal|0x200d0036
block|,
literal|0x000d0039
block|,
literal|0x000d0037
block|,
comment|/* brb.INT_STS_1 */
literal|0x003e0000
block|,
literal|0x1c0d003c
block|,
literal|0x000d003f
block|,
literal|0x000d003d
block|,
comment|/* brb.INT_STS_2 */
literal|0x06210000
block|,
literal|0x200d0042
block|,
literal|0x000d0045
block|,
literal|0x000d0043
block|,
comment|/* brb.INT_STS_3 */
literal|0x06410000
block|,
literal|0x1c0d0048
block|,
literal|0x000d004b
block|,
literal|0x000d0049
block|,
comment|/* brb.INT_STS_4 */
literal|0x00940000
block|,
literal|0x010d004e
block|,
literal|0x000d0051
block|,
literal|0x000d004f
block|,
comment|/* brb.INT_STS_5 */
literal|0x065d0000
block|,
literal|0x0a0d0054
block|,
literal|0x000d0057
block|,
literal|0x000d0055
block|,
comment|/* brb.INT_STS_6 */
literal|0x009d0000
block|,
literal|0x200d005a
block|,
literal|0x000d005d
block|,
literal|0x000d005b
block|,
comment|/* brb.INT_STS_7 */
literal|0x00bd0000
block|,
literal|0x110d0061
block|,
literal|0x000d0064
block|,
literal|0x000d0062
block|,
comment|/* brb.INT_STS_8 */
literal|0x00ce0000
block|,
literal|0x010d0067
block|,
literal|0x000d006a
block|,
literal|0x000d0068
block|,
comment|/* brb.INT_STS_9 */
literal|0x06670000
block|,
literal|0x150d006d
block|,
literal|0x000d0070
block|,
literal|0x000d006e
block|,
comment|/* brb.INT_STS_10 */
literal|0x067c0000
block|,
literal|0x090d0073
block|,
literal|0x000d0076
block|,
literal|0x000d0074
block|,
comment|/* brb.INT_STS_11 */
literal|0x00000000
block|,
literal|0x050d0077
block|,
literal|0x000d007a
block|,
literal|0x000d0078
block|,
comment|/* brb.PRTY_STS */
literal|0x06850007
block|,
literal|0x1f0d0100
block|,
literal|0x000d0103
block|,
literal|0x000d0101
block|,
comment|/* brb.PRTY_STS_H_0, mode bb */
literal|0x06a40009
block|,
literal|0x1f0d0100
block|,
literal|0x000d0103
block|,
literal|0x000d0101
block|,
comment|/* brb.PRTY_STS_H_0, mode k2 */
literal|0x00050003
block|,
literal|0x1f0d0100
block|,
literal|0x000d0103
block|,
literal|0x000d0101
block|,
comment|/* brb.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x06c30007
block|,
literal|0x0e0d0104
block|,
literal|0x000d0107
block|,
literal|0x000d0105
block|,
comment|/* brb.PRTY_STS_H_1, mode bb */
literal|0x06d10009
block|,
literal|0x1e0d0104
block|,
literal|0x000d0107
block|,
literal|0x000d0105
block|,
comment|/* brb.PRTY_STS_H_1, mode k2 */
literal|0x06ef0003
block|,
literal|0x1f0d0104
block|,
literal|0x000d0107
block|,
literal|0x000d0105
block|,
comment|/* brb.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x00520003
block|,
literal|0x010d0108
block|,
literal|0x000d010b
block|,
literal|0x000d0109
block|,
comment|/* brb.PRTY_STS_H_2, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x0108e076
block|,
literal|0x0008e077
block|,
literal|0x0008e079
block|,
comment|/* src.INT_STS */
literal|0x00000000
block|,
literal|0x0207c010
block|,
literal|0x0007c013
block|,
literal|0x0007c011
block|,
comment|/* prs.INT_STS_0 */
literal|0x00000000
block|,
literal|0x0207c014
block|,
literal|0x0007c017
block|,
literal|0x0007c015
block|,
comment|/* prs.PRTY_STS */
literal|0x070e0007
block|,
literal|0x1f07c081
block|,
literal|0x0007c084
block|,
literal|0x0007c082
block|,
comment|/* prs.PRTY_STS_H_0, mode bb */
literal|0x072d0009
block|,
literal|0x1f07c081
block|,
literal|0x0007c084
block|,
literal|0x0007c082
block|,
comment|/* prs.PRTY_STS_H_0, mode k2 */
literal|0x00020003
block|,
literal|0x1707c081
block|,
literal|0x0007c084
block|,
literal|0x0007c082
block|,
comment|/* prs.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x074c0007
block|,
literal|0x0507c085
block|,
literal|0x0007c088
block|,
literal|0x0007c086
block|,
comment|/* prs.PRTY_STS_H_1, mode bb */
literal|0x0751011b
block|,
literal|0x1f07c085
block|,
literal|0x0007c088
block|,
literal|0x0007c086
block|,
comment|/* prs.PRTY_STS_H_1, mode !(bb|e5) */
literal|0x00000000
block|,
literal|0x1c3ec010
block|,
literal|0x003ec013
block|,
literal|0x003ec011
block|,
comment|/* tsdm.INT_STS */
literal|0x07700007
block|,
literal|0x0a3ec080
block|,
literal|0x003ec083
block|,
literal|0x003ec081
block|,
comment|/* tsdm.PRTY_STS_H_0, mode bb */
literal|0x07700009
block|,
literal|0x0a3ec080
block|,
literal|0x003ec083
block|,
literal|0x003ec081
block|,
comment|/* tsdm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0b3ec080
block|,
literal|0x003ec083
block|,
literal|0x003ec081
block|,
comment|/* tsdm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x1c3f0010
block|,
literal|0x003f0013
block|,
literal|0x003f0011
block|,
comment|/* msdm.INT_STS */
literal|0x077a0007
block|,
literal|0x0b3f0080
block|,
literal|0x003f0083
block|,
literal|0x003f0081
block|,
comment|/* msdm.PRTY_STS_H_0, mode bb */
literal|0x077a0009
block|,
literal|0x0b3f0080
block|,
literal|0x003f0083
block|,
literal|0x003f0081
block|,
comment|/* msdm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0c3f0080
block|,
literal|0x003f0083
block|,
literal|0x003f0081
block|,
comment|/* msdm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x1c3f4010
block|,
literal|0x003f4013
block|,
literal|0x003f4011
block|,
comment|/* usdm.INT_STS */
literal|0x07850007
block|,
literal|0x0a3f4080
block|,
literal|0x003f4083
block|,
literal|0x003f4081
block|,
comment|/* usdm.PRTY_STS_H_0, mode bb */
literal|0x07850009
block|,
literal|0x0a3f4080
block|,
literal|0x003f4083
block|,
literal|0x003f4081
block|,
comment|/* usdm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0b3f4080
block|,
literal|0x003f4083
block|,
literal|0x003f4081
block|,
comment|/* usdm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x1c3e0010
block|,
literal|0x003e0013
block|,
literal|0x003e0011
block|,
comment|/* xsdm.INT_STS */
literal|0x078f0007
block|,
literal|0x0a3e0080
block|,
literal|0x003e0083
block|,
literal|0x003e0081
block|,
comment|/* xsdm.PRTY_STS_H_0, mode bb */
literal|0x078f0009
block|,
literal|0x0a3e0080
block|,
literal|0x003e0083
block|,
literal|0x003e0081
block|,
comment|/* xsdm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0b3e0080
block|,
literal|0x003e0083
block|,
literal|0x003e0081
block|,
comment|/* xsdm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x1c3e4010
block|,
literal|0x003e4013
block|,
literal|0x003e4011
block|,
comment|/* ysdm.INT_STS */
literal|0x078f0007
block|,
literal|0x093e4080
block|,
literal|0x003e4083
block|,
literal|0x003e4081
block|,
comment|/* ysdm.PRTY_STS_H_0, mode bb */
literal|0x078f0009
block|,
literal|0x093e4080
block|,
literal|0x003e4083
block|,
literal|0x003e4081
block|,
comment|/* ysdm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0a3e4080
block|,
literal|0x003e4083
block|,
literal|0x003e4081
block|,
comment|/* ysdm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x1c3e8010
block|,
literal|0x003e8013
block|,
literal|0x003e8011
block|,
comment|/* psdm.INT_STS */
literal|0x07990007
block|,
literal|0x093e8080
block|,
literal|0x003e8083
block|,
literal|0x003e8081
block|,
comment|/* psdm.PRTY_STS_H_0, mode bb */
literal|0x07990009
block|,
literal|0x093e8080
block|,
literal|0x003e8083
block|,
literal|0x003e8081
block|,
comment|/* psdm.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0a3e8080
block|,
literal|0x003e8083
block|,
literal|0x003e8081
block|,
comment|/* psdm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x07a20007
block|,
literal|0x205c0010
block|,
literal|0x005c0013
block|,
literal|0x005c0011
block|,
comment|/* tsem.INT_STS_0, mode bb */
literal|0x07a20009
block|,
literal|0x205c0010
block|,
literal|0x005c0013
block|,
literal|0x005c0011
block|,
comment|/* tsem.INT_STS_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f5c0010
block|,
literal|0x005c0013
block|,
literal|0x005c0011
block|,
comment|/* tsem.INT_STS_0, mode !(bb|k2) */
literal|0x07c20000
block|,
literal|0x2d5c0014
block|,
literal|0x005c0017
block|,
literal|0x005c0015
block|,
comment|/* tsem.INT_STS_1 */
literal|0x07ef0003
block|,
literal|0x1f5c0018
block|,
literal|0x005c001b
block|,
literal|0x005c0019
block|,
comment|/* tsem.INT_STS_2, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x015d0010
block|,
literal|0x005d0013
block|,
literal|0x005d0011
block|,
comment|/* tsem.fast_memory.INT_STS */
literal|0x080e0007
block|,
literal|0x035c0032
block|,
literal|0x005c0035
block|,
literal|0x005c0033
block|,
comment|/* tsem.PRTY_STS, mode bb */
literal|0x080e0009
block|,
literal|0x035c0032
block|,
literal|0x005c0035
block|,
literal|0x005c0033
block|,
comment|/* tsem.PRTY_STS, mode k2 */
literal|0x00000003
block|,
literal|0x055c0032
block|,
literal|0x005c0035
block|,
literal|0x005c0033
block|,
comment|/* tsem.PRTY_STS, mode !(bb|k2) */
literal|0x00060043
block|,
literal|0x065c0080
block|,
literal|0x005c0083
block|,
literal|0x005c0081
block|,
comment|/* tsem.PRTY_STS_H_0, mode !e5 */
literal|0x08110009
block|,
literal|0x075d0080
block|,
literal|0x005d0083
block|,
literal|0x005d0081
block|,
comment|/* tsem.fast_memory.PRTY_STS_H_0, mode k2 */
literal|0x000c0003
block|,
literal|0x085d0080
block|,
literal|0x005d0083
block|,
literal|0x005d0081
block|,
comment|/* tsem.fast_memory.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x08180000
block|,
literal|0x075d2880
block|,
literal|0x005d2883
block|,
literal|0x005d2881
block|,
comment|/* tsem.fast_memory.vfc_config.PRTY_STS_H_0 */
literal|0x07a20007
block|,
literal|0x20600010
block|,
literal|0x00600013
block|,
literal|0x00600011
block|,
comment|/* msem.INT_STS_0, mode bb */
literal|0x07a20009
block|,
literal|0x20600010
block|,
literal|0x00600013
block|,
literal|0x00600011
block|,
comment|/* msem.INT_STS_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f600010
block|,
literal|0x00600013
block|,
literal|0x00600011
block|,
comment|/* msem.INT_STS_0, mode !(bb|k2) */
literal|0x07c20000
block|,
literal|0x2d600014
block|,
literal|0x00600017
block|,
literal|0x00600015
block|,
comment|/* msem.INT_STS_1 */
literal|0x07ef0003
block|,
literal|0x1f600018
block|,
literal|0x0060001b
block|,
literal|0x00600019
block|,
comment|/* msem.INT_STS_2, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x01610010
block|,
literal|0x00610013
block|,
literal|0x00610011
block|,
comment|/* msem.fast_memory.INT_STS */
literal|0x080e0007
block|,
literal|0x03600032
block|,
literal|0x00600035
block|,
literal|0x00600033
block|,
comment|/* msem.PRTY_STS, mode bb */
literal|0x080e0009
block|,
literal|0x03600032
block|,
literal|0x00600035
block|,
literal|0x00600033
block|,
comment|/* msem.PRTY_STS, mode k2 */
literal|0x00000003
block|,
literal|0x05600032
block|,
literal|0x00600035
block|,
literal|0x00600033
block|,
comment|/* msem.PRTY_STS, mode !(bb|k2) */
literal|0x081f0007
block|,
literal|0x06600080
block|,
literal|0x00600083
block|,
literal|0x00600081
block|,
comment|/* msem.PRTY_STS_H_0, mode bb */
literal|0x081f0009
block|,
literal|0x06600080
block|,
literal|0x00600083
block|,
literal|0x00600081
block|,
comment|/* msem.PRTY_STS_H_0, mode k2 */
literal|0x00060003
block|,
literal|0x10600080
block|,
literal|0x00600083
block|,
literal|0x00600081
block|,
comment|/* msem.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x08250009
block|,
literal|0x07610080
block|,
literal|0x00610083
block|,
literal|0x00610081
block|,
comment|/* msem.fast_memory.PRTY_STS_H_0, mode k2 */
literal|0x00160003
block|,
literal|0x08610080
block|,
literal|0x00610083
block|,
literal|0x00610081
block|,
comment|/* msem.fast_memory.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x07a20007
block|,
literal|0x20640010
block|,
literal|0x00640013
block|,
literal|0x00640011
block|,
comment|/* usem.INT_STS_0, mode bb */
literal|0x07a20009
block|,
literal|0x20640010
block|,
literal|0x00640013
block|,
literal|0x00640011
block|,
comment|/* usem.INT_STS_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f640010
block|,
literal|0x00640013
block|,
literal|0x00640011
block|,
comment|/* usem.INT_STS_0, mode !(bb|k2) */
literal|0x07c20000
block|,
literal|0x2d640014
block|,
literal|0x00640017
block|,
literal|0x00640015
block|,
comment|/* usem.INT_STS_1 */
literal|0x07ef0003
block|,
literal|0x1f640018
block|,
literal|0x0064001b
block|,
literal|0x00640019
block|,
comment|/* usem.INT_STS_2, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x01650010
block|,
literal|0x00650013
block|,
literal|0x00650011
block|,
comment|/* usem.fast_memory.INT_STS */
literal|0x080e0007
block|,
literal|0x03640032
block|,
literal|0x00640035
block|,
literal|0x00640033
block|,
comment|/* usem.PRTY_STS, mode bb */
literal|0x080e0009
block|,
literal|0x03640032
block|,
literal|0x00640035
block|,
literal|0x00640033
block|,
comment|/* usem.PRTY_STS, mode k2 */
literal|0x00000003
block|,
literal|0x05640032
block|,
literal|0x00640035
block|,
literal|0x00640033
block|,
comment|/* usem.PRTY_STS, mode !(bb|k2) */
literal|0x00060043
block|,
literal|0x06640080
block|,
literal|0x00640083
block|,
literal|0x00640081
block|,
comment|/* usem.PRTY_STS_H_0, mode !e5 */
literal|0x08110009
block|,
literal|0x07650080
block|,
literal|0x00650083
block|,
literal|0x00650081
block|,
comment|/* usem.fast_memory.PRTY_STS_H_0, mode k2 */
literal|0x000c0003
block|,
literal|0x08650080
block|,
literal|0x00650083
block|,
literal|0x00650081
block|,
comment|/* usem.fast_memory.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x07a20007
block|,
literal|0x20500010
block|,
literal|0x00500013
block|,
literal|0x00500011
block|,
comment|/* xsem.INT_STS_0, mode bb */
literal|0x07a20009
block|,
literal|0x20500010
block|,
literal|0x00500013
block|,
literal|0x00500011
block|,
comment|/* xsem.INT_STS_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f500010
block|,
literal|0x00500013
block|,
literal|0x00500011
block|,
comment|/* xsem.INT_STS_0, mode !(bb|k2) */
literal|0x07c20000
block|,
literal|0x2d500014
block|,
literal|0x00500017
block|,
literal|0x00500015
block|,
comment|/* xsem.INT_STS_1 */
literal|0x07ef0003
block|,
literal|0x1f500018
block|,
literal|0x0050001b
block|,
literal|0x00500019
block|,
comment|/* xsem.INT_STS_2, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x01510010
block|,
literal|0x00510013
block|,
literal|0x00510011
block|,
comment|/* xsem.fast_memory.INT_STS */
literal|0x080e0007
block|,
literal|0x03500032
block|,
literal|0x00500035
block|,
literal|0x00500033
block|,
comment|/* xsem.PRTY_STS, mode bb */
literal|0x080e0009
block|,
literal|0x03500032
block|,
literal|0x00500035
block|,
literal|0x00500033
block|,
comment|/* xsem.PRTY_STS, mode k2 */
literal|0x00000003
block|,
literal|0x05500032
block|,
literal|0x00500035
block|,
literal|0x00500033
block|,
comment|/* xsem.PRTY_STS, mode !(bb|k2) */
literal|0x00060043
block|,
literal|0x07500080
block|,
literal|0x00500083
block|,
literal|0x00500081
block|,
comment|/* xsem.PRTY_STS_H_0, mode !e5 */
literal|0x082c0009
block|,
literal|0x07510080
block|,
literal|0x00510083
block|,
literal|0x00510081
block|,
comment|/* xsem.fast_memory.PRTY_STS_H_0, mode k2 */
literal|0x000d0003
block|,
literal|0x08510080
block|,
literal|0x00510083
block|,
literal|0x00510081
block|,
comment|/* xsem.fast_memory.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x07a20007
block|,
literal|0x20540010
block|,
literal|0x00540013
block|,
literal|0x00540011
block|,
comment|/* ysem.INT_STS_0, mode bb */
literal|0x07a20009
block|,
literal|0x20540010
block|,
literal|0x00540013
block|,
literal|0x00540011
block|,
comment|/* ysem.INT_STS_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f540010
block|,
literal|0x00540013
block|,
literal|0x00540011
block|,
comment|/* ysem.INT_STS_0, mode !(bb|k2) */
literal|0x07c20000
block|,
literal|0x2d540014
block|,
literal|0x00540017
block|,
literal|0x00540015
block|,
comment|/* ysem.INT_STS_1 */
literal|0x07ef0003
block|,
literal|0x1f540018
block|,
literal|0x0054001b
block|,
literal|0x00540019
block|,
comment|/* ysem.INT_STS_2, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x01550010
block|,
literal|0x00550013
block|,
literal|0x00550011
block|,
comment|/* ysem.fast_memory.INT_STS */
literal|0x080e0007
block|,
literal|0x03540032
block|,
literal|0x00540035
block|,
literal|0x00540033
block|,
comment|/* ysem.PRTY_STS, mode bb */
literal|0x080e0009
block|,
literal|0x03540032
block|,
literal|0x00540035
block|,
literal|0x00540033
block|,
comment|/* ysem.PRTY_STS, mode k2 */
literal|0x00000003
block|,
literal|0x05540032
block|,
literal|0x00540035
block|,
literal|0x00540033
block|,
comment|/* ysem.PRTY_STS, mode !(bb|k2) */
literal|0x00060043
block|,
literal|0x07540080
block|,
literal|0x00540083
block|,
literal|0x00540081
block|,
comment|/* ysem.PRTY_STS_H_0, mode !e5 */
literal|0x082c0009
block|,
literal|0x07550080
block|,
literal|0x00550083
block|,
literal|0x00550081
block|,
comment|/* ysem.fast_memory.PRTY_STS_H_0, mode k2 */
literal|0x000d0003
block|,
literal|0x08550080
block|,
literal|0x00550083
block|,
literal|0x00550081
block|,
comment|/* ysem.fast_memory.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x07a20007
block|,
literal|0x20580010
block|,
literal|0x00580013
block|,
literal|0x00580011
block|,
comment|/* psem.INT_STS_0, mode bb */
literal|0x07a20009
block|,
literal|0x20580010
block|,
literal|0x00580013
block|,
literal|0x00580011
block|,
comment|/* psem.INT_STS_0, mode k2 */
literal|0x00000003
block|,
literal|0x1f580010
block|,
literal|0x00580013
block|,
literal|0x00580011
block|,
comment|/* psem.INT_STS_0, mode !(bb|k2) */
literal|0x07c20000
block|,
literal|0x2d580014
block|,
literal|0x00580017
block|,
literal|0x00580015
block|,
comment|/* psem.INT_STS_1 */
literal|0x07ef0003
block|,
literal|0x1f580018
block|,
literal|0x0058001b
block|,
literal|0x00580019
block|,
comment|/* psem.INT_STS_2, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x01590010
block|,
literal|0x00590013
block|,
literal|0x00590011
block|,
comment|/* psem.fast_memory.INT_STS */
literal|0x080e0007
block|,
literal|0x03580032
block|,
literal|0x00580035
block|,
literal|0x00580033
block|,
comment|/* psem.PRTY_STS, mode bb */
literal|0x080e0009
block|,
literal|0x03580032
block|,
literal|0x00580035
block|,
literal|0x00580033
block|,
comment|/* psem.PRTY_STS, mode k2 */
literal|0x00000003
block|,
literal|0x05580032
block|,
literal|0x00580035
block|,
literal|0x00580033
block|,
comment|/* psem.PRTY_STS, mode !(bb|k2) */
literal|0x00060043
block|,
literal|0x06580080
block|,
literal|0x00580083
block|,
literal|0x00580081
block|,
comment|/* psem.PRTY_STS_H_0, mode !e5 */
literal|0x08110009
block|,
literal|0x07590080
block|,
literal|0x00590083
block|,
literal|0x00590081
block|,
comment|/* psem.fast_memory.PRTY_STS_H_0, mode k2 */
literal|0x000c0003
block|,
literal|0x08590080
block|,
literal|0x00590083
block|,
literal|0x00590081
block|,
comment|/* psem.fast_memory.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x08180000
block|,
literal|0x07592880
block|,
literal|0x00592883
block|,
literal|0x00592881
block|,
comment|/* psem.fast_memory.vfc_config.PRTY_STS_H_0 */
literal|0x08330000
block|,
literal|0x1608e260
block|,
literal|0x0008e263
block|,
literal|0x0008e261
block|,
comment|/* rss.INT_STS */
literal|0x08490000
block|,
literal|0x0a08e280
block|,
literal|0x0008e283
block|,
literal|0x0008e281
block|,
comment|/* rss.PRTY_STS_H_0 */
literal|0x00000000
block|,
literal|0x06134060
block|,
literal|0x00134063
block|,
literal|0x00134061
block|,
comment|/* tmld.INT_STS */
literal|0x08530007
block|,
literal|0x08134080
block|,
literal|0x00134083
block|,
literal|0x00134081
block|,
comment|/* tmld.PRTY_STS_H_0, mode bb */
literal|0x08530009
block|,
literal|0x08134080
block|,
literal|0x00134083
block|,
literal|0x00134081
block|,
comment|/* tmld.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0e134080
block|,
literal|0x00134083
block|,
literal|0x00134081
block|,
comment|/* tmld.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x06138060
block|,
literal|0x00138063
block|,
literal|0x00138061
block|,
comment|/* muld.INT_STS */
literal|0x085b0007
block|,
literal|0x0a138080
block|,
literal|0x00138083
block|,
literal|0x00138081
block|,
comment|/* muld.PRTY_STS_H_0, mode bb */
literal|0x085b0009
block|,
literal|0x0a138080
block|,
literal|0x00138083
block|,
literal|0x00138081
block|,
comment|/* muld.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x10138080
block|,
literal|0x00138083
block|,
literal|0x00138081
block|,
comment|/* muld.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000043
block|,
literal|0x06132060
block|,
literal|0x00132063
block|,
literal|0x00132061
block|,
comment|/* yuld.INT_STS, mode !e5 */
literal|0x00000043
block|,
literal|0x06132080
block|,
literal|0x00132083
block|,
literal|0x00132081
block|,
comment|/* yuld.PRTY_STS_H_0, mode !e5 */
literal|0x00000000
block|,
literal|0x06130060
block|,
literal|0x00130063
block|,
literal|0x00130061
block|,
comment|/* xyld.INT_STS */
literal|0x08650007
block|,
literal|0x09130080
block|,
literal|0x00130083
block|,
literal|0x00130081
block|,
comment|/* xyld.PRTY_STS_H_0, mode bb */
literal|0x08650009
block|,
literal|0x09130080
block|,
literal|0x00130083
block|,
literal|0x00130081
block|,
comment|/* xyld.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0f130080
block|,
literal|0x00130083
block|,
literal|0x00130081
block|,
comment|/* xyld.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x06168060
block|,
literal|0x00168063
block|,
literal|0x00168061
block|,
comment|/* ptld.INT_STS, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x08168080
block|,
literal|0x00168083
block|,
literal|0x00168081
block|,
comment|/* ptld.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x06170060
block|,
literal|0x00170063
block|,
literal|0x00170061
block|,
comment|/* ypld.INT_STS, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x08170080
block|,
literal|0x00170083
block|,
literal|0x00170081
block|,
comment|/* ypld.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x086e0000
block|,
literal|0x0b08c010
block|,
literal|0x0008c013
block|,
literal|0x0008c011
block|,
comment|/* prm.INT_STS */
literal|0x00000000
block|,
literal|0x0108c014
block|,
literal|0x0008c017
block|,
literal|0x0008c015
block|,
comment|/* prm.PRTY_STS */
literal|0x08790007
block|,
literal|0x1808c080
block|,
literal|0x0008c083
block|,
literal|0x0008c081
block|,
comment|/* prm.PRTY_STS_H_0, mode bb */
literal|0x08910009
block|,
literal|0x1708c080
block|,
literal|0x0008c083
block|,
literal|0x0008c081
block|,
comment|/* prm.PRTY_STS_H_0, mode k2 */
literal|0x00010003
block|,
literal|0x1808c080
block|,
literal|0x0008c083
block|,
literal|0x0008c081
block|,
comment|/* prm.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x09368010
block|,
literal|0x00368013
block|,
literal|0x00368011
block|,
comment|/* pbf_pb1.INT_STS */
literal|0x00000000
block|,
literal|0x01368014
block|,
literal|0x00368017
block|,
literal|0x00368015
block|,
comment|/* pbf_pb1.PRTY_STS */
literal|0x00000000
block|,
literal|0x09369010
block|,
literal|0x00369013
block|,
literal|0x00369011
block|,
comment|/* pbf_pb2.INT_STS */
literal|0x00000000
block|,
literal|0x01369014
block|,
literal|0x00369017
block|,
literal|0x00369015
block|,
comment|/* pbf_pb2.PRTY_STS */
literal|0x00000000
block|,
literal|0x0908f010
block|,
literal|0x0008f013
block|,
literal|0x0008f011
block|,
comment|/* rpb.INT_STS */
literal|0x00000000
block|,
literal|0x0108f014
block|,
literal|0x0008f017
block|,
literal|0x0008f015
block|,
comment|/* rpb.PRTY_STS */
literal|0x08a80000
block|,
literal|0x1a36c030
block|,
literal|0x0036c033
block|,
literal|0x0036c031
block|,
comment|/* btb.INT_STS_0 */
literal|0x08c20000
block|,
literal|0x1236c036
block|,
literal|0x0036c039
block|,
literal|0x0036c037
block|,
comment|/* btb.INT_STS_1 */
literal|0x08d40000
block|,
literal|0x0536c03c
block|,
literal|0x0036c03f
block|,
literal|0x0036c03d
block|,
comment|/* btb.INT_STS_2 */
literal|0x00240000
block|,
literal|0x2036c042
block|,
literal|0x0036c045
block|,
literal|0x0036c043
block|,
comment|/* btb.INT_STS_3 */
literal|0x08d90000
block|,
literal|0x1c36c048
block|,
literal|0x0036c04b
block|,
literal|0x0036c049
block|,
comment|/* btb.INT_STS_4 */
literal|0x005b0000
block|,
literal|0x2036c04e
block|,
literal|0x0036c051
block|,
literal|0x0036c04f
block|,
comment|/* btb.INT_STS_5 */
literal|0x007b0000
block|,
literal|0x0136c054
block|,
literal|0x0036c057
block|,
literal|0x0036c055
block|,
comment|/* btb.INT_STS_6 */
literal|0x007c0000
block|,
literal|0x0136c061
block|,
literal|0x0036c064
block|,
literal|0x0036c062
block|,
comment|/* btb.INT_STS_8 */
literal|0x007d0000
block|,
literal|0x0136c067
block|,
literal|0x0036c06a
block|,
literal|0x0036c068
block|,
comment|/* btb.INT_STS_9 */
literal|0x08f50000
block|,
literal|0x0236c06d
block|,
literal|0x0036c070
block|,
literal|0x0036c06e
block|,
comment|/* btb.INT_STS_10 */
literal|0x08f70000
block|,
literal|0x0436c073
block|,
literal|0x0036c076
block|,
literal|0x0036c074
block|,
comment|/* btb.INT_STS_11 */
literal|0x00000000
block|,
literal|0x0536c077
block|,
literal|0x0036c07a
block|,
literal|0x0036c078
block|,
comment|/* btb.PRTY_STS */
literal|0x08fb0007
block|,
literal|0x1736c100
block|,
literal|0x0036c103
block|,
literal|0x0036c101
block|,
comment|/* btb.PRTY_STS_H_0, mode bb */
literal|0x09120009
block|,
literal|0x1f36c100
block|,
literal|0x0036c103
block|,
literal|0x0036c101
block|,
comment|/* btb.PRTY_STS_H_0, mode k2 */
literal|0x00050003
block|,
literal|0x1f36c100
block|,
literal|0x0036c103
block|,
literal|0x0036c101
block|,
comment|/* btb.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00240003
block|,
literal|0x0836c104
block|,
literal|0x0036c107
block|,
literal|0x0036c105
block|,
comment|/* btb.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x01360060
block|,
literal|0x00360063
block|,
literal|0x00360061
block|,
comment|/* pbf.INT_STS */
literal|0x00000000
block|,
literal|0x01360064
block|,
literal|0x00360067
block|,
literal|0x00360065
block|,
comment|/* pbf.PRTY_STS */
literal|0x00010043
block|,
literal|0x1f360080
block|,
literal|0x00360083
block|,
literal|0x00360081
block|,
comment|/* pbf.PRTY_STS_H_0, mode !e5 */
literal|0x00200043
block|,
literal|0x1b360084
block|,
literal|0x00360087
block|,
literal|0x00360085
block|,
comment|/* pbf.PRTY_STS_H_1, mode !e5 */
literal|0x00000000
block|,
literal|0x090c0060
block|,
literal|0x000c0063
block|,
literal|0x000c0061
block|,
comment|/* rdif.INT_STS */
literal|0x01480000
block|,
literal|0x020c0064
block|,
literal|0x000c0067
block|,
literal|0x000c0065
block|,
comment|/* rdif.PRTY_STS */
literal|0x00000000
block|,
literal|0x090c4060
block|,
literal|0x000c4063
block|,
literal|0x000c4061
block|,
comment|/* tdif.INT_STS */
literal|0x01480000
block|,
literal|0x020c4064
block|,
literal|0x000c4067
block|,
literal|0x000c4065
block|,
comment|/* tdif.PRTY_STS */
literal|0x09310007
block|,
literal|0x0b0c4080
block|,
literal|0x000c4083
block|,
literal|0x000c4081
block|,
comment|/* tdif.PRTY_STS_H_0, mode bb */
literal|0x09310009
block|,
literal|0x0b0c4080
block|,
literal|0x000c4083
block|,
literal|0x000c4081
block|,
comment|/* tdif.PRTY_STS_H_0, mode k2 */
literal|0x00010003
block|,
literal|0x0c0c4080
block|,
literal|0x000c4083
block|,
literal|0x000c4081
block|,
comment|/* tdif.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x08160070
block|,
literal|0x00160071
block|,
literal|0x00160073
block|,
comment|/* cdu.INT_STS */
literal|0x093c0007
block|,
literal|0x05160080
block|,
literal|0x00160083
block|,
literal|0x00160081
block|,
comment|/* cdu.PRTY_STS_H_0, mode bb */
literal|0x093c0009
block|,
literal|0x05160080
block|,
literal|0x00160083
block|,
literal|0x00160081
block|,
comment|/* cdu.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x04160080
block|,
literal|0x00160083
block|,
literal|0x00160081
block|,
comment|/* cdu.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x020b8060
block|,
literal|0x000b8063
block|,
literal|0x000b8061
block|,
comment|/* ccfc.INT_STS_0 */
literal|0x00000000
block|,
literal|0x060b8179
block|,
literal|0x000b817c
block|,
literal|0x000b817a
block|,
comment|/* ccfc.PRTY_STS */
literal|0x07970007
block|,
literal|0x020b8080
block|,
literal|0x000b8083
block|,
literal|0x000b8081
block|,
comment|/* ccfc.PRTY_STS_H_0, mode bb */
literal|0x07970009
block|,
literal|0x020b8080
block|,
literal|0x000b8083
block|,
literal|0x000b8081
block|,
comment|/* ccfc.PRTY_STS_H_0, mode k2 */
literal|0x00060003
block|,
literal|0x040b8080
block|,
literal|0x000b8083
block|,
literal|0x000b8081
block|,
comment|/* ccfc.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x020b4060
block|,
literal|0x000b4063
block|,
literal|0x000b4061
block|,
comment|/* tcfc.INT_STS_0 */
literal|0x00000000
block|,
literal|0x060b4179
block|,
literal|0x000b417c
block|,
literal|0x000b417a
block|,
comment|/* tcfc.PRTY_STS */
literal|0x00080007
block|,
literal|0x020b4080
block|,
literal|0x000b4083
block|,
literal|0x000b4081
block|,
comment|/* tcfc.PRTY_STS_H_0, mode bb */
literal|0x00080009
block|,
literal|0x020b4080
block|,
literal|0x000b4083
block|,
literal|0x000b4081
block|,
comment|/* tcfc.PRTY_STS_H_0, mode k2 */
literal|0x00060003
block|,
literal|0x040b4080
block|,
literal|0x000b4083
block|,
literal|0x000b4081
block|,
comment|/* tcfc.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000000
block|,
literal|0x0b060060
block|,
literal|0x00060063
block|,
literal|0x00060061
block|,
comment|/* igu.INT_STS */
literal|0x00000000
block|,
literal|0x01060064
block|,
literal|0x00060067
block|,
literal|0x00060065
block|,
comment|/* igu.PRTY_STS */
literal|0x09410007
block|,
literal|0x1f060080
block|,
literal|0x00060083
block|,
literal|0x00060081
block|,
comment|/* igu.PRTY_STS_H_0, mode bb */
literal|0x09600009
block|,
literal|0x1c060080
block|,
literal|0x00060083
block|,
literal|0x00060081
block|,
comment|/* igu.PRTY_STS_H_0, mode k2 */
literal|0x00010003
block|,
literal|0x1c060080
block|,
literal|0x00060083
block|,
literal|0x00060081
block|,
comment|/* igu.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x001e0015
block|,
literal|0x01060084
block|,
literal|0x00060087
block|,
literal|0x00060085
block|,
comment|/* igu.PRTY_STS_H_1, mode !(k2|e5) */
literal|0x097c0000
block|,
literal|0x0b070035
block|,
literal|0x00070036
block|,
literal|0x00070038
block|,
comment|/* cau.INT_STS */
literal|0x09870007
block|,
literal|0x0d070080
block|,
literal|0x00070083
block|,
literal|0x00070081
block|,
comment|/* cau.PRTY_STS_H_0, mode bb */
literal|0x09940009
block|,
literal|0x0d070080
block|,
literal|0x00070083
block|,
literal|0x00070081
block|,
comment|/* cau.PRTY_STS_H_0, mode k2 */
literal|0x00000003
block|,
literal|0x0a070080
block|,
literal|0x00070083
block|,
literal|0x00070081
block|,
comment|/* cau.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x023c0060
block|,
literal|0x003c0063
block|,
literal|0x003c0061
block|,
comment|/* rgfs.INT_STS, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x013c0064
block|,
literal|0x003c0067
block|,
literal|0x003c0065
block|,
comment|/* rgfs.PRTY_STS, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x010c8060
block|,
literal|0x000c8063
block|,
literal|0x000c8061
block|,
comment|/* rgsrc.INT_STS, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x020c8081
block|,
literal|0x000c8084
block|,
literal|0x000c8082
block|,
comment|/* rgsrc.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x02340060
block|,
literal|0x00340063
block|,
literal|0x00340061
block|,
comment|/* tgfs.INT_STS, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x01340064
block|,
literal|0x00340067
block|,
literal|0x00340065
block|,
comment|/* tgfs.PRTY_STS, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x010c8860
block|,
literal|0x000c8863
block|,
literal|0x000c8861
block|,
comment|/* tgsrc.INT_STS, mode !(bb|k2) */
literal|0x00000003
block|,
literal|0x020c8881
block|,
literal|0x000c8884
block|,
literal|0x000c8882
block|,
comment|/* tgsrc.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x00000025
block|,
literal|0x02014460
block|,
literal|0x00014463
block|,
literal|0x00014461
block|,
comment|/* umac.INT_STS, mode !bb */
literal|0x00000000
block|,
literal|0x01004060
block|,
literal|0x00004063
block|,
literal|0x00004061
block|,
comment|/* dbg.INT_STS */
literal|0x00000000
block|,
literal|0x01004080
block|,
literal|0x00004083
block|,
literal|0x00004081
block|,
comment|/* dbg.PRTY_STS_H_0 */
literal|0x00000000
block|,
literal|0x0e140010
block|,
literal|0x00140013
block|,
literal|0x00140011
block|,
comment|/* nig.INT_STS_0 */
literal|0x000e0000
block|,
literal|0x20140014
block|,
literal|0x00140017
block|,
literal|0x00140015
block|,
comment|/* nig.INT_STS_1 */
literal|0x002e0000
block|,
literal|0x16140018
block|,
literal|0x0014001b
block|,
literal|0x00140019
block|,
comment|/* nig.INT_STS_2 */
literal|0x00440000
block|,
literal|0x1214001c
block|,
literal|0x0014001f
block|,
literal|0x0014001d
block|,
comment|/* nig.INT_STS_3 */
literal|0x00560000
block|,
literal|0x16140020
block|,
literal|0x00140023
block|,
literal|0x00140021
block|,
comment|/* nig.INT_STS_4 */
literal|0x006c0000
block|,
literal|0x12140024
block|,
literal|0x00140027
block|,
literal|0x00140025
block|,
comment|/* nig.INT_STS_5 */
literal|0x007e0025
block|,
literal|0x14140028
block|,
literal|0x0014002b
block|,
literal|0x00140029
block|,
comment|/* nig.INT_STS_6, mode !bb */
literal|0x00940025
block|,
literal|0x1214002c
block|,
literal|0x0014002f
block|,
literal|0x0014002d
block|,
comment|/* nig.INT_STS_7, mode !bb */
literal|0x00a60025
block|,
literal|0x14140030
block|,
literal|0x00140033
block|,
literal|0x00140031
block|,
comment|/* nig.INT_STS_8, mode !bb */
literal|0x00bc0025
block|,
literal|0x12140034
block|,
literal|0x00140037
block|,
literal|0x00140035
block|,
comment|/* nig.INT_STS_9, mode !bb */
literal|0x00ce0003
block|,
literal|0x1014003c
block|,
literal|0x0014003f
block|,
literal|0x0014003d
block|,
comment|/* nig.INT_STS_10, mode !(bb|k2) */
literal|0x00000007
block|,
literal|0x01140028
block|,
literal|0x0014002b
block|,
literal|0x00140029
block|,
comment|/* nig.PRTY_STS, mode bb */
literal|0x00000025
block|,
literal|0x01140038
block|,
literal|0x0014003b
block|,
literal|0x00140039
block|,
comment|/* nig.PRTY_STS, mode !bb */
literal|0x09a10007
block|,
literal|0x1f140080
block|,
literal|0x00140083
block|,
literal|0x00140081
block|,
comment|/* nig.PRTY_STS_H_0, mode bb */
literal|0x09c00009
block|,
literal|0x1f140080
block|,
literal|0x00140083
block|,
literal|0x00140081
block|,
comment|/* nig.PRTY_STS_H_0, mode k2 */
literal|0x00010003
block|,
literal|0x1f140080
block|,
literal|0x00140083
block|,
literal|0x00140081
block|,
comment|/* nig.PRTY_STS_H_0, mode !(bb|k2) */
literal|0x09df0007
block|,
literal|0x1f140084
block|,
literal|0x00140087
block|,
literal|0x00140085
block|,
comment|/* nig.PRTY_STS_H_1, mode bb */
literal|0x09fe0009
block|,
literal|0x1f140084
block|,
literal|0x00140087
block|,
literal|0x00140085
block|,
comment|/* nig.PRTY_STS_H_1, mode k2 */
literal|0x0a1d0003
block|,
literal|0x1f140084
block|,
literal|0x00140087
block|,
literal|0x00140085
block|,
comment|/* nig.PRTY_STS_H_1, mode !(bb|k2) */
literal|0x0a3c0007
block|,
literal|0x1f140088
block|,
literal|0x0014008b
block|,
literal|0x00140089
block|,
comment|/* nig.PRTY_STS_H_2, mode bb */
literal|0x0a5b0009
block|,
literal|0x1f140088
block|,
literal|0x0014008b
block|,
literal|0x00140089
block|,
comment|/* nig.PRTY_STS_H_2, mode k2 */
literal|0x0a7a0003
block|,
literal|0x1f140088
block|,
literal|0x0014008b
block|,
literal|0x00140089
block|,
comment|/* nig.PRTY_STS_H_2, mode !(bb|k2) */
literal|0x0a990007
block|,
literal|0x1114008c
block|,
literal|0x0014008f
block|,
literal|0x0014008d
block|,
comment|/* nig.PRTY_STS_H_3, mode bb */
literal|0x0aaa0009
block|,
literal|0x0e14008c
block|,
literal|0x0014008f
block|,
literal|0x0014008d
block|,
comment|/* nig.PRTY_STS_H_3, mode k2 */
literal|0x0ab80003
block|,
literal|0x1914008c
block|,
literal|0x0014008f
block|,
literal|0x0014008d
block|,
comment|/* nig.PRTY_STS_H_3, mode !(bb|k2) */
literal|0x00000025
block|,
literal|0x01180010
block|,
literal|0x00180013
block|,
literal|0x00180011
block|,
comment|/* wol.INT_STS_0, mode !bb */
literal|0x00000025
block|,
literal|0x18180080
block|,
literal|0x00180083
block|,
literal|0x00180081
block|,
comment|/* wol.PRTY_STS_H_0, mode !bb */
literal|0x00000025
block|,
literal|0x01184010
block|,
literal|0x00184013
block|,
literal|0x00184011
block|,
comment|/* bmbn.INT_STS_0, mode !bb */
literal|0x0ad10007
block|,
literal|0x0e008143
block|,
literal|0x00008146
block|,
literal|0x00008144
block|,
comment|/* ipc.INT_STS_0, mode bb */
literal|0x0ad10025
block|,
literal|0x060080b7
block|,
literal|0x000080ba
block|,
literal|0x000080b8
block|,
comment|/* ipc.INT_STS_0, mode !bb */
literal|0x00000015
block|,
literal|0x01008147
block|,
literal|0x0000814a
block|,
literal|0x00008148
block|,
comment|/* ipc.PRTY_STS, mode !(k2|e5) */
literal|0x0adf0025
block|,
literal|0x12200001
block|,
literal|0x00200004
block|,
literal|0x00200002
block|,
comment|/* nwm.INT_STS, mode !bb */
literal|0x00000025
block|,
literal|0x1f200080
block|,
literal|0x00200083
block|,
literal|0x00200081
block|,
comment|/* nwm.PRTY_STS_H_0, mode !bb */
literal|0x001f0025
block|,
literal|0x1f200084
block|,
literal|0x00200087
block|,
literal|0x00200085
block|,
comment|/* nwm.PRTY_STS_H_1, mode !bb */
literal|0x003e0025
block|,
literal|0x0a200088
block|,
literal|0x0020008b
block|,
literal|0x00200089
block|,
comment|/* nwm.PRTY_STS_H_2, mode !bb */
literal|0x00000025
block|,
literal|0x0a1c0060
block|,
literal|0x001c0063
block|,
literal|0x001c0061
block|,
comment|/* nws.INT_STS_0, mode !bb */
literal|0x0af10025
block|,
literal|0x0a1c0064
block|,
literal|0x001c0067
block|,
literal|0x001c0065
block|,
comment|/* nws.INT_STS_1, mode !bb */
literal|0x0afb0025
block|,
literal|0x0a1c0068
block|,
literal|0x001c006b
block|,
literal|0x001c0069
block|,
comment|/* nws.INT_STS_2, mode !bb */
literal|0x0b050025
block|,
literal|0x0a1c006c
block|,
literal|0x001c006f
block|,
literal|0x001c006d
block|,
comment|/* nws.INT_STS_3, mode !bb */
literal|0x00000025
block|,
literal|0x041c0080
block|,
literal|0x001c0083
block|,
literal|0x001c0081
block|,
comment|/* nws.PRTY_STS_H_0, mode !bb */
literal|0x00000025
block|,
literal|0x011a8060
block|,
literal|0x001a8063
block|,
literal|0x001a8061
block|,
comment|/* ms.INT_STS, mode !bb */
literal|0x00000025
block|,
literal|0x011ae060
block|,
literal|0x001ae063
block|,
literal|0x001ae061
block|,
comment|/* led.INT_STS_0, mode !bb */
literal|0x0b0f011b
block|,
literal|0x031ad002
block|,
literal|0x001ad005
block|,
literal|0x001ad003
block|,
comment|/* avs_wrap.INT_STS, mode !(bb|e5) */
literal|0x0000011b
block|,
literal|0x031ad006
block|,
literal|0x001ad009
block|,
literal|0x001ad007
block|,
comment|/* avs_wrap.PRTY_STS, mode !(bb|e5) */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 6864 bytes */
end_comment

begin_comment
comment|/* Array of attentions data per block */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|attn_block
index|[]
init|=
block|{
literal|0x00000000
block|,
literal|0x00000001
block|,
literal|0x00000005
block|,
literal|0x00010001
block|,
comment|/* block grc, 1 interrupt regs (5 attentions), 1 parity regs (2 attentions) */
literal|0x00000007
block|,
literal|0x00020002
block|,
literal|0x00000015
block|,
literal|0x00040001
block|,
comment|/* block miscs, 2 interrupt regs (14 attentions), 1 parity regs (1 attentions) */
literal|0x00000000
block|,
literal|0x00050001
block|,
literal|0x00000000
block|,
literal|0x00060000
block|,
comment|/* block misc, 1 interrupt regs (1 attentions) */
literal|0x00000000
block|,
literal|0x00060000
block|,
literal|0x00000000
block|,
literal|0x00060000
block|,
comment|/* block dbu */
literal|0x00000016
block|,
literal|0x00060001
block|,
literal|0x0000002e
block|,
literal|0x00070004
block|,
comment|/* block pglue_b, 1 interrupt regs (24 attentions), 4 parity regs (35 attentions) */
literal|0x00000051
block|,
literal|0x000b0002
block|,
literal|0x0000005b
block|,
literal|0x000d0002
block|,
comment|/* block cnig, 2 interrupt regs (10 attentions), 2 parity regs (2 attentions) */
literal|0x00000000
block|,
literal|0x000f0001
block|,
literal|0x00000000
block|,
literal|0x00100000
block|,
comment|/* block cpmu, 1 interrupt regs (1 attentions) */
literal|0x00000000
block|,
literal|0x00100001
block|,
literal|0x0000005d
block|,
literal|0x00110001
block|,
comment|/* block ncsi, 1 interrupt regs (1 attentions), 1 parity regs (3 attentions) */
literal|0x00000000
block|,
literal|0x00120000
block|,
literal|0x00000060
block|,
literal|0x00120002
block|,
comment|/* block opte, 2 parity regs (12 attentions) */
literal|0x0000006c
block|,
literal|0x0014000c
block|,
literal|0x00000196
block|,
literal|0x00200005
block|,
comment|/* block bmb, 12 interrupt regs (298 attentions), 5 parity regs (66 attentions) */
literal|0x000001d8
block|,
literal|0x00250001
block|,
literal|0x000001e9
block|,
literal|0x00260003
block|,
comment|/* block pcie, 1 interrupt regs (17 attentions), 3 parity regs (24 attentions) */
literal|0x00000000
block|,
literal|0x00290000
block|,
literal|0x00000000
block|,
literal|0x00290000
block|,
comment|/* block mcp */
literal|0x00000000
block|,
literal|0x00290000
block|,
literal|0x00000201
block|,
literal|0x00290002
block|,
comment|/* block mcp2, 2 parity regs (13 attentions) */
literal|0x0000020e
block|,
literal|0x002b0001
block|,
literal|0x00000220
block|,
literal|0x002c0002
block|,
comment|/* block pswhst, 1 interrupt regs (18 attentions), 2 parity regs (18 attentions) */
literal|0x00000232
block|,
literal|0x002e0001
block|,
literal|0x0000002e
block|,
literal|0x002f0001
block|,
comment|/* block pswhst2, 1 interrupt regs (5 attentions), 1 parity regs (1 attentions) */
literal|0x00000237
block|,
literal|0x00300001
block|,
literal|0x0000002e
block|,
literal|0x00310001
block|,
comment|/* block pswrd, 1 interrupt regs (3 attentions), 1 parity regs (1 attentions) */
literal|0x0000023a
block|,
literal|0x00320001
block|,
literal|0x0000023f
block|,
literal|0x00330007
block|,
comment|/* block pswrd2, 1 interrupt regs (5 attentions), 7 parity regs (40 attentions) */
literal|0x00000267
block|,
literal|0x003a0001
block|,
literal|0x0000002e
block|,
literal|0x003b0001
block|,
comment|/* block pswwr, 1 interrupt regs (19 attentions), 1 parity regs (1 attentions) */
literal|0x0000027a
block|,
literal|0x003c0001
block|,
literal|0x00000290
block|,
literal|0x003d000e
block|,
comment|/* block pswwr2, 1 interrupt regs (22 attentions), 14 parity regs (161 attentions) */
literal|0x00000331
block|,
literal|0x004b0001
block|,
literal|0x00000348
block|,
literal|0x004c0001
block|,
comment|/* block pswrq, 1 interrupt regs (23 attentions), 1 parity regs (1 attentions) */
literal|0x00000349
block|,
literal|0x004d0001
block|,
literal|0x00000358
block|,
literal|0x004e0002
block|,
comment|/* block pswrq2, 1 interrupt regs (15 attentions), 2 parity regs (11 attentions) */
literal|0x00000363
block|,
literal|0x00500001
block|,
literal|0x00000000
block|,
literal|0x00510000
block|,
comment|/* block pglcs, 1 interrupt regs (2 attentions) */
literal|0x00000365
block|,
literal|0x00510001
block|,
literal|0x0000005d
block|,
literal|0x00520001
block|,
comment|/* block dmae, 1 interrupt regs (2 attentions), 1 parity regs (3 attentions) */
literal|0x00000367
block|,
literal|0x00530001
block|,
literal|0x0000036f
block|,
literal|0x00540003
block|,
comment|/* block ptu, 1 interrupt regs (8 attentions), 3 parity regs (20 attentions) */
literal|0x00000383
block|,
literal|0x00570005
block|,
literal|0x000003b4
block|,
literal|0x005c0006
block|,
comment|/* block tcm, 5 interrupt regs (49 attentions), 6 parity regs (59 attentions) */
literal|0x000003ef
block|,
literal|0x00620005
block|,
literal|0x0000041e
block|,
literal|0x00670006
block|,
comment|/* block mcm, 5 interrupt regs (47 attentions), 6 parity regs (52 attentions) */
literal|0x00000452
block|,
literal|0x006d0005
block|,
literal|0x00000485
block|,
literal|0x00720004
block|,
comment|/* block ucm, 5 interrupt regs (51 attentions), 4 parity regs (49 attentions) */
literal|0x000004b6
block|,
literal|0x00760003
block|,
literal|0x000004e9
block|,
literal|0x00790006
block|,
comment|/* block xcm, 3 interrupt regs (51 attentions), 6 parity regs (54 attentions) */
literal|0x0000051f
block|,
literal|0x007f0003
block|,
literal|0x00000546
block|,
literal|0x00820006
block|,
comment|/* block ycm, 3 interrupt regs (39 attentions), 6 parity regs (58 attentions) */
literal|0x00000580
block|,
literal|0x00880005
block|,
literal|0x00000598
block|,
literal|0x008d0003
block|,
comment|/* block pcm, 5 interrupt regs (24 attentions), 3 parity regs (24 attentions) */
literal|0x000005b0
block|,
literal|0x00900001
block|,
literal|0x000005c6
block|,
literal|0x00910009
block|,
comment|/* block qm, 1 interrupt regs (22 attentions), 9 parity regs (116 attentions) */
literal|0x0000063a
block|,
literal|0x009a0002
block|,
literal|0x00000665
block|,
literal|0x009c0003
block|,
comment|/* block tm, 2 interrupt regs (43 attentions), 3 parity regs (20 attentions) */
literal|0x00000679
block|,
literal|0x009f0001
block|,
literal|0x00000685
block|,
literal|0x00a00004
block|,
comment|/* block dorq, 1 interrupt regs (12 attentions), 4 parity regs (13 attentions) */
literal|0x00000692
block|,
literal|0x00a4000c
block|,
literal|0x0000077b
block|,
literal|0x00b00008
block|,
comment|/* block brb, 12 interrupt regs (233 attentions), 8 parity regs (83 attentions) */
literal|0x00000000
block|,
literal|0x00b80001
block|,
literal|0x00000000
block|,
literal|0x00b90000
block|,
comment|/* block src, 1 interrupt regs (1 attentions) */
literal|0x000007ce
block|,
literal|0x00b90001
block|,
literal|0x000007d0
block|,
literal|0x00ba0006
block|,
comment|/* block prs, 1 interrupt regs (2 attentions), 6 parity regs (78 attentions) */
literal|0x0000081e
block|,
literal|0x00c00001
block|,
literal|0x0000083a
block|,
literal|0x00c10003
block|,
comment|/* block tsdm, 1 interrupt regs (28 attentions), 3 parity regs (11 attentions) */
literal|0x0000081e
block|,
literal|0x00c40001
block|,
literal|0x00000845
block|,
literal|0x00c50003
block|,
comment|/* block msdm, 1 interrupt regs (28 attentions), 3 parity regs (14 attentions) */
literal|0x0000081e
block|,
literal|0x00c80001
block|,
literal|0x00000853
block|,
literal|0x00c90003
block|,
comment|/* block usdm, 1 interrupt regs (28 attentions), 3 parity regs (11 attentions) */
literal|0x0000081e
block|,
literal|0x00cc0001
block|,
literal|0x0000085e
block|,
literal|0x00cd0003
block|,
comment|/* block xsdm, 1 interrupt regs (28 attentions), 3 parity regs (11 attentions) */
literal|0x0000081e
block|,
literal|0x00d00001
block|,
literal|0x00000869
block|,
literal|0x00d10003
block|,
comment|/* block ysdm, 1 interrupt regs (28 attentions), 3 parity regs (10 attentions) */
literal|0x0000081e
block|,
literal|0x00d40001
block|,
literal|0x00000873
block|,
literal|0x00d50003
block|,
comment|/* block psdm, 1 interrupt regs (28 attentions), 3 parity regs (12 attentions) */
literal|0x0000087f
block|,
literal|0x00d80006
block|,
literal|0x00000901
block|,
literal|0x00de0007
block|,
comment|/* block tsem, 6 interrupt regs (130 attentions), 7 parity regs (24 attentions) */
literal|0x0000087f
block|,
literal|0x00e50006
block|,
literal|0x00000919
block|,
literal|0x00eb0008
block|,
comment|/* block msem, 6 interrupt regs (130 attentions), 8 parity regs (30 attentions) */
literal|0x0000087f
block|,
literal|0x00f30006
block|,
literal|0x00000901
block|,
literal|0x00f90006
block|,
comment|/* block usem, 6 interrupt regs (130 attentions), 6 parity regs (20 attentions) */
literal|0x0000087f
block|,
literal|0x00ff0006
block|,
literal|0x00000937
block|,
literal|0x01050006
block|,
comment|/* block xsem, 6 interrupt regs (130 attentions), 6 parity regs (21 attentions) */
literal|0x0000087f
block|,
literal|0x010b0006
block|,
literal|0x00000937
block|,
literal|0x01110006
block|,
comment|/* block ysem, 6 interrupt regs (130 attentions), 6 parity regs (21 attentions) */
literal|0x0000087f
block|,
literal|0x01170006
block|,
literal|0x00000901
block|,
literal|0x011d0007
block|,
comment|/* block psem, 6 interrupt regs (130 attentions), 7 parity regs (24 attentions) */
literal|0x0000094c
block|,
literal|0x01240001
block|,
literal|0x00000962
block|,
literal|0x01250001
block|,
comment|/* block rss, 1 interrupt regs (22 attentions), 1 parity regs (10 attentions) */
literal|0x0000096c
block|,
literal|0x01260001
block|,
literal|0x00000972
block|,
literal|0x01270003
block|,
comment|/* block tmld, 1 interrupt regs (6 attentions), 3 parity regs (15 attentions) */
literal|0x0000096c
block|,
literal|0x012a0001
block|,
literal|0x00000981
block|,
literal|0x012b0003
block|,
comment|/* block muld, 1 interrupt regs (6 attentions), 3 parity regs (19 attentions) */
literal|0x0000096c
block|,
literal|0x012e0001
block|,
literal|0x00000994
block|,
literal|0x012f0001
block|,
comment|/* block yuld, 1 interrupt regs (6 attentions), 1 parity regs (6 attentions) */
literal|0x0000096c
block|,
literal|0x01300001
block|,
literal|0x0000099a
block|,
literal|0x01310003
block|,
comment|/* block xyld, 1 interrupt regs (6 attentions), 3 parity regs (17 attentions) */
literal|0x0000096c
block|,
literal|0x01340001
block|,
literal|0x000009ab
block|,
literal|0x01350001
block|,
comment|/* block ptld, 1 interrupt regs (6 attentions), 1 parity regs (8 attentions) */
literal|0x0000096c
block|,
literal|0x01360001
block|,
literal|0x000009ab
block|,
literal|0x01370001
block|,
comment|/* block ypld, 1 interrupt regs (6 attentions), 1 parity regs (8 attentions) */
literal|0x000009b3
block|,
literal|0x01380001
block|,
literal|0x000009be
block|,
literal|0x01390004
block|,
comment|/* block prm, 1 interrupt regs (11 attentions), 4 parity regs (30 attentions) */
literal|0x000009dc
block|,
literal|0x013d0001
block|,
literal|0x0000002e
block|,
literal|0x013e0001
block|,
comment|/* block pbf_pb1, 1 interrupt regs (9 attentions), 1 parity regs (1 attentions) */
literal|0x000009dc
block|,
literal|0x013f0001
block|,
literal|0x0000002e
block|,
literal|0x01400001
block|,
comment|/* block pbf_pb2, 1 interrupt regs (9 attentions), 1 parity regs (1 attentions) */
literal|0x000009dc
block|,
literal|0x01410001
block|,
literal|0x0000002e
block|,
literal|0x01420001
block|,
comment|/* block rpb, 1 interrupt regs (9 attentions), 1 parity regs (1 attentions) */
literal|0x000009e5
block|,
literal|0x0143000b
block|,
literal|0x00000a66
block|,
literal|0x014e0005
block|,
comment|/* block btb, 11 interrupt regs (129 attentions), 5 parity regs (44 attentions) */
literal|0x00000000
block|,
literal|0x01530001
block|,
literal|0x00000a92
block|,
literal|0x01540003
block|,
comment|/* block pbf, 1 interrupt regs (1 attentions), 3 parity regs (59 attentions) */
literal|0x00000acd
block|,
literal|0x01570001
block|,
literal|0x0000002e
block|,
literal|0x01580001
block|,
comment|/* block rdif, 1 interrupt regs (9 attentions), 1 parity regs (1 attentions) */
literal|0x00000acd
block|,
literal|0x01590001
block|,
literal|0x00000ad6
block|,
literal|0x015a0004
block|,
comment|/* block tdif, 1 interrupt regs (9 attentions), 4 parity regs (13 attentions) */
literal|0x00000ae3
block|,
literal|0x015e0001
block|,
literal|0x00000aeb
block|,
literal|0x015f0003
block|,
comment|/* block cdu, 1 interrupt regs (8 attentions), 3 parity regs (5 attentions) */
literal|0x00000af0
block|,
literal|0x01620001
block|,
literal|0x00000af2
block|,
literal|0x01630004
block|,
comment|/* block ccfc, 1 interrupt regs (2 attentions), 4 parity regs (11 attentions) */
literal|0x00000af0
block|,
literal|0x01670001
block|,
literal|0x00000afd
block|,
literal|0x01680004
block|,
comment|/* block tcfc, 1 interrupt regs (2 attentions), 4 parity regs (10 attentions) */
literal|0x00000b07
block|,
literal|0x016c0001
block|,
literal|0x00000b12
block|,
literal|0x016d0005
block|,
comment|/* block igu, 1 interrupt regs (11 attentions), 5 parity regs (54 attentions) */
literal|0x00000b48
block|,
literal|0x01720001
block|,
literal|0x00000b53
block|,
literal|0x01730003
block|,
comment|/* block cau, 1 interrupt regs (11 attentions), 3 parity regs (16 attentions) */
literal|0x000005b0
block|,
literal|0x01760001
block|,
literal|0x000005c6
block|,
literal|0x01770001
block|,
comment|/* block rgfs, 1 interrupt regs (2 attentions), 1 parity regs (1 attentions) */
literal|0x00000000
block|,
literal|0x01780001
block|,
literal|0x00000968
block|,
literal|0x01790001
block|,
comment|/* block rgsrc, 1 interrupt regs (1 attentions), 1 parity regs (2 attentions) */
literal|0x000005b0
block|,
literal|0x017a0001
block|,
literal|0x000005c6
block|,
literal|0x017b0001
block|,
comment|/* block tgfs, 1 interrupt regs (2 attentions), 1 parity regs (1 attentions) */
literal|0x00000000
block|,
literal|0x017c0001
block|,
literal|0x00000968
block|,
literal|0x017d0001
block|,
comment|/* block tgsrc, 1 interrupt regs (1 attentions), 1 parity regs (2 attentions) */
literal|0x00000b63
block|,
literal|0x017e0001
block|,
literal|0x00000000
block|,
literal|0x017f0000
block|,
comment|/* block umac, 1 interrupt regs (2 attentions) */
literal|0x00000000
block|,
literal|0x017f0000
block|,
literal|0x00000000
block|,
literal|0x017f0000
block|,
comment|/* block xmac */
literal|0x00000000
block|,
literal|0x017f0001
block|,
literal|0x00000050
block|,
literal|0x01800001
block|,
comment|/* block dbg, 1 interrupt regs (1 attentions), 1 parity regs (1 attentions) */
literal|0x00000b65
block|,
literal|0x0181000b
block|,
literal|0x00000c43
block|,
literal|0x018c000e
block|,
comment|/* block nig, 11 interrupt regs (222 attentions), 14 parity regs (121 attentions) */
literal|0x00000000
block|,
literal|0x019a0001
block|,
literal|0x00000cbc
block|,
literal|0x019b0001
block|,
comment|/* block wol, 1 interrupt regs (1 attentions), 1 parity regs (24 attentions) */
literal|0x00000000
block|,
literal|0x019c0001
block|,
literal|0x00000000
block|,
literal|0x019d0000
block|,
comment|/* block bmbn, 1 interrupt regs (1 attentions) */
literal|0x00000cd4
block|,
literal|0x019d0002
block|,
literal|0x00000ce1
block|,
literal|0x019f0001
block|,
comment|/* block ipc, 2 interrupt regs (13 attentions), 1 parity regs (1 attentions) */
literal|0x00000ce2
block|,
literal|0x01a00001
block|,
literal|0x00000cf3
block|,
literal|0x01a10003
block|,
comment|/* block nwm, 1 interrupt regs (17 attentions), 3 parity regs (72 attentions) */
literal|0x00000d3b
block|,
literal|0x01a40004
block|,
literal|0x00000d60
block|,
literal|0x01a80001
block|,
comment|/* block nws, 4 interrupt regs (37 attentions), 1 parity regs (4 attentions) */
literal|0x00000000
block|,
literal|0x01a90001
block|,
literal|0x00000000
block|,
literal|0x01aa0000
block|,
comment|/* block ms, 1 interrupt regs (1 attentions) */
literal|0x00000000
block|,
literal|0x01aa0000
block|,
literal|0x00000000
block|,
literal|0x01aa0000
block|,
comment|/* block phy_pcie */
literal|0x00000000
block|,
literal|0x01aa0001
block|,
literal|0x00000000
block|,
literal|0x01ab0000
block|,
comment|/* block led, 1 interrupt regs (1 attentions) */
literal|0x00000d64
block|,
literal|0x01ab0001
block|,
literal|0x00000d66
block|,
literal|0x01ac0001
block|,
comment|/* block avs_wrap, 1 interrupt regs (2 attentions), 1 parity regs (3 attentions) */
literal|0x00000000
block|,
literal|0x01ad0000
block|,
literal|0x00000000
block|,
literal|0x01ad0000
block|,
comment|/* block misc_aeu */
literal|0x00000000
block|,
literal|0x01ad0000
block|,
literal|0x00000000
block|,
literal|0x01ad0000
block|,
comment|/* block bar0_map */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 1392 bytes */
end_comment

begin_comment
comment|/* Debug Bus lines */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|dbg_bus_lines
index|[]
init|=
block|{
literal|0x0301
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x0301
block|,
literal|0x0103
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x1003
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0002
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0502
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0003
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0102
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x1003
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0002
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0502
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0003
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0102
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x1003
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0001
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0014
block|,
literal|0x0502
block|,
literal|0x0512
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0512
block|,
literal|0x0502
block|,
literal|0x0402
block|,
literal|0x0502
block|,
literal|0x0001
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0002
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0202
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0103
block|,
literal|0x0102
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0512
block|,
literal|0x0512
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0512
block|,
literal|0x0512
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x1003
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0202
block|,
literal|0x0202
block|,
literal|0x1003
block|,
literal|0x0004
block|,
literal|0x1003
block|,
literal|0x0004
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x0002
block|,
literal|0x0002
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0402
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0402
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0002
block|,
literal|0x0102
block|,
literal|0x0502
block|,
literal|0x0002
block|,
literal|0x0102
block|,
literal|0x0502
block|,
literal|0x0002
block|,
literal|0x0102
block|,
literal|0x0502
block|,
literal|0x1003
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0002
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0502
block|,
literal|0x0002
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x1003
block|,
literal|0x0003
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0402
block|,
literal|0x0001
block|,
literal|0x0101
block|,
literal|0x0402
block|,
literal|0x0102
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0002
block|,
literal|0x0201
block|,
literal|0x0201
block|,
literal|0x0201
block|,
literal|0x0201
block|,
literal|0x0201
block|,
literal|0x0004
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0201
block|,
literal|0x0201
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0202
block|,
literal|0x0103
block|,
literal|0x0103
block|,
literal|0x0301
block|,
literal|0x0103
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0014
block|,
literal|0x0311
block|,
literal|0x0014
block|,
literal|0x0011
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0201
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0111
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0003
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0004
block|,
literal|0x0512
block|,
literal|0x0512
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0004
block|,
literal|0x0301
block|,
literal|0x0512
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0004
block|,
literal|0x0301
block|,
literal|0x0512
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0111
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0001
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0111
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0001
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0001
block|,
literal|0x0001
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0311
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0311
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0014
block|,
literal|0x0502
block|,
literal|0x0311
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0014
block|,
literal|0x0502
block|,
literal|0x0311
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0001
block|,
literal|0x0014
block|,
literal|0x0014
block|,
literal|0x0014
block|,
literal|0x0012
block|,
literal|0x0101
block|,
literal|0x0512
block|,
literal|0x0512
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0001
block|,
literal|0x0014
block|,
literal|0x0014
block|,
literal|0x0014
block|,
literal|0x0012
block|,
literal|0x0101
block|,
literal|0x0512
block|,
literal|0x0512
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0002
block|,
literal|0x0301
block|,
literal|0x0102
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0402
block|,
literal|0x0201
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0402
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0101
block|,
literal|0x0802
block|,
literal|0x0301
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0101
block|,
literal|0x0101
block|,
literal|0x0201
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0802
block|,
literal|0x0301
block|,
literal|0x0202
block|,
literal|0x0301
block|,
literal|0x0202
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0802
block|,
literal|0x0301
block|,
literal|0x0802
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0402
block|,
literal|0x0102
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0201
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0502
block|,
literal|0x0111
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0301
block|,
literal|0x0301
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0311
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,
literal|0x0004
block|,  }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 1752 bytes */
end_comment

begin_comment
comment|/* Debug Bus blocks */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|u32
name|dbg_bus_blocks
index|[]
init|=
block|{
literal|0x0000000f
block|,
comment|/* grc, bb, 15 lines */
literal|0x0000000f
block|,
comment|/* grc, k2, 15 lines */
literal|0x00000000
block|,
comment|/* grc, e5, 0 lines */
literal|0x00000000
block|,
comment|/* miscs, bb, 0 lines */
literal|0x00000000
block|,
comment|/* miscs, k2, 0 lines */
literal|0x00000000
block|,
comment|/* miscs, e5, 0 lines */
literal|0x00000000
block|,
comment|/* misc, bb, 0 lines */
literal|0x00000000
block|,
comment|/* misc, k2, 0 lines */
literal|0x00000000
block|,
comment|/* misc, e5, 0 lines */
literal|0x00000000
block|,
comment|/* dbu, bb, 0 lines */
literal|0x00000000
block|,
comment|/* dbu, k2, 0 lines */
literal|0x00000000
block|,
comment|/* dbu, e5, 0 lines */
literal|0x000f0127
block|,
comment|/* pglue_b, bb, 39 lines */
literal|0x0036012a
block|,
comment|/* pglue_b, k2, 42 lines */
literal|0x00000000
block|,
comment|/* pglue_b, e5, 0 lines */
literal|0x00000000
block|,
comment|/* cnig, bb, 0 lines */
literal|0x00120102
block|,
comment|/* cnig, k2, 2 lines */
literal|0x00000000
block|,
comment|/* cnig, e5, 0 lines */
literal|0x00000000
block|,
comment|/* cpmu, bb, 0 lines */
literal|0x00000000
block|,
comment|/* cpmu, k2, 0 lines */
literal|0x00000000
block|,
comment|/* cpmu, e5, 0 lines */
literal|0x00000001
block|,
comment|/* ncsi, bb, 1 lines */
literal|0x00000001
block|,
comment|/* ncsi, k2, 1 lines */
literal|0x00000000
block|,
comment|/* ncsi, e5, 0 lines */
literal|0x00000000
block|,
comment|/* opte, bb, 0 lines */
literal|0x00000000
block|,
comment|/* opte, k2, 0 lines */
literal|0x00000000
block|,
comment|/* opte, e5, 0 lines */
literal|0x00600085
block|,
comment|/* bmb, bb, 133 lines */
literal|0x00600085
block|,
comment|/* bmb, k2, 133 lines */
literal|0x00000000
block|,
comment|/* bmb, e5, 0 lines */
literal|0x00000000
block|,
comment|/* pcie, bb, 0 lines */
literal|0x00210008
block|,
comment|/* pcie, k2, 8 lines */
literal|0x00000000
block|,
comment|/* pcie, e5, 0 lines */
literal|0x00000000
block|,
comment|/* mcp, bb, 0 lines */
literal|0x00000000
block|,
comment|/* mcp, k2, 0 lines */
literal|0x00000000
block|,
comment|/* mcp, e5, 0 lines */
literal|0x00e50009
block|,
comment|/* mcp2, bb, 9 lines */
literal|0x00e50009
block|,
comment|/* mcp2, k2, 9 lines */
literal|0x00000000
block|,
comment|/* mcp2, e5, 0 lines */
literal|0x00ee0104
block|,
comment|/* pswhst, bb, 4 lines */
literal|0x00ee0104
block|,
comment|/* pswhst, k2, 4 lines */
literal|0x00000000
block|,
comment|/* pswhst, e5, 0 lines */
literal|0x00f20103
block|,
comment|/* pswhst2, bb, 3 lines */
literal|0x00f20103
block|,
comment|/* pswhst2, k2, 3 lines */
literal|0x00000000
block|,
comment|/* pswhst2, e5, 0 lines */
literal|0x00340101
block|,
comment|/* pswrd, bb, 1 lines */
literal|0x00340101
block|,
comment|/* pswrd, k2, 1 lines */
literal|0x00000000
block|,
comment|/* pswrd, e5, 0 lines */
literal|0x00f50119
block|,
comment|/* pswrd2, bb, 25 lines */
literal|0x00f50119
block|,
comment|/* pswrd2, k2, 25 lines */
literal|0x00000000
block|,
comment|/* pswrd2, e5, 0 lines */
literal|0x010e0109
block|,
comment|/* pswwr, bb, 9 lines */
literal|0x010e0109
block|,
comment|/* pswwr, k2, 9 lines */
literal|0x00000000
block|,
comment|/* pswwr, e5, 0 lines */
literal|0x00000000
block|,
comment|/* pswwr2, bb, 0 lines */
literal|0x00000000
block|,
comment|/* pswwr2, k2, 0 lines */
literal|0x00000000
block|,
comment|/* pswwr2, e5, 0 lines */
literal|0x001c0001
block|,
comment|/* pswrq, bb, 1 lines */
literal|0x001c0001
block|,
comment|/* pswrq, k2, 1 lines */
literal|0x00000000
block|,
comment|/* pswrq, e5, 0 lines */
literal|0x01170015
block|,
comment|/* pswrq2, bb, 21 lines */
literal|0x01170015
block|,
comment|/* pswrq2, k2, 21 lines */
literal|0x00000000
block|,
comment|/* pswrq2, e5, 0 lines */
literal|0x00000000
block|,
comment|/* pglcs, bb, 0 lines */
literal|0x00120006
block|,
comment|/* pglcs, k2, 6 lines */
literal|0x00000000
block|,
comment|/* pglcs, e5, 0 lines */
literal|0x00100001
block|,
comment|/* dmae, bb, 1 lines */
literal|0x00100001
block|,
comment|/* dmae, k2, 1 lines */
literal|0x00000000
block|,
comment|/* dmae, e5, 0 lines */
literal|0x012c0105
block|,
comment|/* ptu, bb, 5 lines */
literal|0x012c0105
block|,
comment|/* ptu, k2, 5 lines */
literal|0x00000000
block|,
comment|/* ptu, e5, 0 lines */
literal|0x01310120
block|,
comment|/* tcm, bb, 32 lines */
literal|0x01310120
block|,
comment|/* tcm, k2, 32 lines */
literal|0x00000000
block|,
comment|/* tcm, e5, 0 lines */
literal|0x01310120
block|,
comment|/* mcm, bb, 32 lines */
literal|0x01310120
block|,
comment|/* mcm, k2, 32 lines */
literal|0x00000000
block|,
comment|/* mcm, e5, 0 lines */
literal|0x01310120
block|,
comment|/* ucm, bb, 32 lines */
literal|0x01310120
block|,
comment|/* ucm, k2, 32 lines */
literal|0x00000000
block|,
comment|/* ucm, e5, 0 lines */
literal|0x01310120
block|,
comment|/* xcm, bb, 32 lines */
literal|0x01310120
block|,
comment|/* xcm, k2, 32 lines */
literal|0x00000000
block|,
comment|/* xcm, e5, 0 lines */
literal|0x01310120
block|,
comment|/* ycm, bb, 32 lines */
literal|0x01310120
block|,
comment|/* ycm, k2, 32 lines */
literal|0x00000000
block|,
comment|/* ycm, e5, 0 lines */
literal|0x01310120
block|,
comment|/* pcm, bb, 32 lines */
literal|0x01310120
block|,
comment|/* pcm, k2, 32 lines */
literal|0x00000000
block|,
comment|/* pcm, e5, 0 lines */
literal|0x01510062
block|,
comment|/* qm, bb, 98 lines */
literal|0x01510062
block|,
comment|/* qm, k2, 98 lines */
literal|0x00000000
block|,
comment|/* qm, e5, 0 lines */
literal|0x01b30021
block|,
comment|/* tm, bb, 33 lines */
literal|0x01b30021
block|,
comment|/* tm, k2, 33 lines */
literal|0x00000000
block|,
comment|/* tm, e5, 0 lines */
literal|0x01d40107
block|,
comment|/* dorq, bb, 7 lines */
literal|0x01d40107
block|,
comment|/* dorq, k2, 7 lines */
literal|0x00000000
block|,
comment|/* dorq, e5, 0 lines */
literal|0x00600185
block|,
comment|/* brb, bb, 133 lines */
literal|0x00600185
block|,
comment|/* brb, k2, 133 lines */
literal|0x00000000
block|,
comment|/* brb, e5, 0 lines */
literal|0x01db0019
block|,
comment|/* src, bb, 25 lines */
literal|0x01d9001a
block|,
comment|/* src, k2, 26 lines */
literal|0x00000000
block|,
comment|/* src, e5, 0 lines */
literal|0x01f40104
block|,
comment|/* prs, bb, 4 lines */
literal|0x01f40104
block|,
comment|/* prs, k2, 4 lines */
literal|0x00000000
block|,
comment|/* prs, e5, 0 lines */
literal|0x01f80133
block|,
comment|/* tsdm, bb, 51 lines */
literal|0x01f80133
block|,
comment|/* tsdm, k2, 51 lines */
literal|0x00000000
block|,
comment|/* tsdm, e5, 0 lines */
literal|0x01f80133
block|,
comment|/* msdm, bb, 51 lines */
literal|0x01f80133
block|,
comment|/* msdm, k2, 51 lines */
literal|0x00000000
block|,
comment|/* msdm, e5, 0 lines */
literal|0x01f80133
block|,
comment|/* usdm, bb, 51 lines */
literal|0x01f80133
block|,
comment|/* usdm, k2, 51 lines */
literal|0x00000000
block|,
comment|/* usdm, e5, 0 lines */
literal|0x01f80133
block|,
comment|/* xsdm, bb, 51 lines */
literal|0x01f80133
block|,
comment|/* xsdm, k2, 51 lines */
literal|0x00000000
block|,
comment|/* xsdm, e5, 0 lines */
literal|0x01f80133
block|,
comment|/* ysdm, bb, 51 lines */
literal|0x01f80133
block|,
comment|/* ysdm, k2, 51 lines */
literal|0x00000000
block|,
comment|/* ysdm, e5, 0 lines */
literal|0x01f80133
block|,
comment|/* psdm, bb, 51 lines */
literal|0x01f80133
block|,
comment|/* psdm, k2, 51 lines */
literal|0x00000000
block|,
comment|/* psdm, e5, 0 lines */
literal|0x022b010c
block|,
comment|/* tsem, bb, 12 lines */
literal|0x022b010c
block|,
comment|/* tsem, k2, 12 lines */
literal|0x00000000
block|,
comment|/* tsem, e5, 0 lines */
literal|0x022b010c
block|,
comment|/* msem, bb, 12 lines */
literal|0x022b010c
block|,
comment|/* msem, k2, 12 lines */
literal|0x00000000
block|,
comment|/* msem, e5, 0 lines */
literal|0x022b010c
block|,
comment|/* usem, bb, 12 lines */
literal|0x022b010c
block|,
comment|/* usem, k2, 12 lines */
literal|0x00000000
block|,
comment|/* usem, e5, 0 lines */
literal|0x022b010c
block|,
comment|/* xsem, bb, 12 lines */
literal|0x022b010c
block|,
comment|/* xsem, k2, 12 lines */
literal|0x00000000
block|,
comment|/* xsem, e5, 0 lines */
literal|0x022b010c
block|,
comment|/* ysem, bb, 12 lines */
literal|0x022b010c
block|,
comment|/* ysem, k2, 12 lines */
literal|0x00000000
block|,
comment|/* ysem, e5, 0 lines */
literal|0x022b010c
block|,
comment|/* psem, bb, 12 lines */
literal|0x022b010c
block|,
comment|/* psem, k2, 12 lines */
literal|0x00000000
block|,
comment|/* psem, e5, 0 lines */
literal|0x0237000d
block|,
comment|/* rss, bb, 13 lines */
literal|0x0237000d
block|,
comment|/* rss, k2, 13 lines */
literal|0x00000000
block|,
comment|/* rss, e5, 0 lines */
literal|0x02440106
block|,
comment|/* tmld, bb, 6 lines */
literal|0x02440106
block|,
comment|/* tmld, k2, 6 lines */
literal|0x00000000
block|,
comment|/* tmld, e5, 0 lines */
literal|0x024a0106
block|,
comment|/* muld, bb, 6 lines */
literal|0x024a0106
block|,
comment|/* muld, k2, 6 lines */
literal|0x00000000
block|,
comment|/* muld, e5, 0 lines */
literal|0x02440005
block|,
comment|/* yuld, bb, 5 lines */
literal|0x02440005
block|,
comment|/* yuld, k2, 5 lines */
literal|0x00000000
block|,
comment|/* yuld, e5, 0 lines */
literal|0x02500107
block|,
comment|/* xyld, bb, 7 lines */
literal|0x024a0107
block|,
comment|/* xyld, k2, 7 lines */
literal|0x00000000
block|,
comment|/* xyld, e5, 0 lines */
literal|0x00000000
block|,
comment|/* ptld, bb, 0 lines */
literal|0x00000000
block|,
comment|/* ptld, k2, 0 lines */
literal|0x00000000
block|,
comment|/* ptld, e5, 0 lines */
literal|0x00000000
block|,
comment|/* ypld, bb, 0 lines */
literal|0x00000000
block|,
comment|/* ypld, k2, 0 lines */
literal|0x00000000
block|,
comment|/* ypld, e5, 0 lines */
literal|0x0257010e
block|,
comment|/* prm, bb, 14 lines */
literal|0x02650110
block|,
comment|/* prm, k2, 16 lines */
literal|0x00000000
block|,
comment|/* prm, e5, 0 lines */
literal|0x0275000d
block|,
comment|/* pbf_pb1, bb, 13 lines */
literal|0x0275000d
block|,
comment|/* pbf_pb1, k2, 13 lines */
literal|0x00000000
block|,
comment|/* pbf_pb1, e5, 0 lines */
literal|0x0275000d
block|,
comment|/* pbf_pb2, bb, 13 lines */
literal|0x0275000d
block|,
comment|/* pbf_pb2, k2, 13 lines */
literal|0x00000000
block|,
comment|/* pbf_pb2, e5, 0 lines */
literal|0x0275000d
block|,
comment|/* rpb, bb, 13 lines */
literal|0x0275000d
block|,
comment|/* rpb, k2, 13 lines */
literal|0x00000000
block|,
comment|/* rpb, e5, 0 lines */
literal|0x00600185
block|,
comment|/* btb, bb, 133 lines */
literal|0x00600185
block|,
comment|/* btb, k2, 133 lines */
literal|0x00000000
block|,
comment|/* btb, e5, 0 lines */
literal|0x02820117
block|,
comment|/* pbf, bb, 23 lines */
literal|0x02820117
block|,
comment|/* pbf, k2, 23 lines */
literal|0x00000000
block|,
comment|/* pbf, e5, 0 lines */
literal|0x02990006
block|,
comment|/* rdif, bb, 6 lines */
literal|0x02990006
block|,
comment|/* rdif, k2, 6 lines */
literal|0x00000000
block|,
comment|/* rdif, e5, 0 lines */
literal|0x029f0006
block|,
comment|/* tdif, bb, 6 lines */
literal|0x029f0006
block|,
comment|/* tdif, k2, 6 lines */
literal|0x00000000
block|,
comment|/* tdif, e5, 0 lines */
literal|0x02a50003
block|,
comment|/* cdu, bb, 3 lines */
literal|0x02a8000e
block|,
comment|/* cdu, k2, 14 lines */
literal|0x00000000
block|,
comment|/* cdu, e5, 0 lines */
literal|0x02b6010d
block|,
comment|/* ccfc, bb, 13 lines */
literal|0x02c30117
block|,
comment|/* ccfc, k2, 23 lines */
literal|0x00000000
block|,
comment|/* ccfc, e5, 0 lines */
literal|0x02b6010d
block|,
comment|/* tcfc, bb, 13 lines */
literal|0x02c30117
block|,
comment|/* tcfc, k2, 23 lines */
literal|0x00000000
block|,
comment|/* tcfc, e5, 0 lines */
literal|0x02da0133
block|,
comment|/* igu, bb, 51 lines */
literal|0x02da0133
block|,
comment|/* igu, k2, 51 lines */
literal|0x00000000
block|,
comment|/* igu, e5, 0 lines */
literal|0x030d0106
block|,
comment|/* cau, bb, 6 lines */
literal|0x030d0106
block|,
comment|/* cau, k2, 6 lines */
literal|0x00000000
block|,
comment|/* cau, e5, 0 lines */
literal|0x00000000
block|,
comment|/* rgfs, bb, 0 lines */
literal|0x00000000
block|,
comment|/* rgfs, k2, 0 lines */
literal|0x00000000
block|,
comment|/* rgfs, e5, 0 lines */
literal|0x00000000
block|,
comment|/* rgsrc, bb, 0 lines */
literal|0x00000000
block|,
comment|/* rgsrc, k2, 0 lines */
literal|0x00000000
block|,
comment|/* rgsrc, e5, 0 lines */
literal|0x00000000
block|,
comment|/* tgfs, bb, 0 lines */
literal|0x00000000
block|,
comment|/* tgfs, k2, 0 lines */
literal|0x00000000
block|,
comment|/* tgfs, e5, 0 lines */
literal|0x00000000
block|,
comment|/* tgsrc, bb, 0 lines */
literal|0x00000000
block|,
comment|/* tgsrc, k2, 0 lines */
literal|0x00000000
block|,
comment|/* tgsrc, e5, 0 lines */
literal|0x00000000
block|,
comment|/* umac, bb, 0 lines */
literal|0x00120006
block|,
comment|/* umac, k2, 6 lines */
literal|0x00000000
block|,
comment|/* umac, e5, 0 lines */
literal|0x00000000
block|,
comment|/* xmac, bb, 0 lines */
literal|0x00000000
block|,
comment|/* xmac, k2, 0 lines */
literal|0x00000000
block|,
comment|/* xmac, e5, 0 lines */
literal|0x00000000
block|,
comment|/* dbg, bb, 0 lines */
literal|0x00000000
block|,
comment|/* dbg, k2, 0 lines */
literal|0x00000000
block|,
comment|/* dbg, e5, 0 lines */
literal|0x0313012b
block|,
comment|/* nig, bb, 43 lines */
literal|0x0313011d
block|,
comment|/* nig, k2, 29 lines */
literal|0x00000000
block|,
comment|/* nig, e5, 0 lines */
literal|0x00000000
block|,
comment|/* wol, bb, 0 lines */
literal|0x001c0002
block|,
comment|/* wol, k2, 2 lines */
literal|0x00000000
block|,
comment|/* wol, e5, 0 lines */
literal|0x00000000
block|,
comment|/* bmbn, bb, 0 lines */
literal|0x00210008
block|,
comment|/* bmbn, k2, 8 lines */
literal|0x00000000
block|,
comment|/* bmbn, e5, 0 lines */
literal|0x00000000
block|,
comment|/* ipc, bb, 0 lines */
literal|0x00000000
block|,
comment|/* ipc, k2, 0 lines */
literal|0x00000000
block|,
comment|/* ipc, e5, 0 lines */
literal|0x00000000
block|,
comment|/* nwm, bb, 0 lines */
literal|0x033e000b
block|,
comment|/* nwm, k2, 11 lines */
literal|0x00000000
block|,
comment|/* nwm, e5, 0 lines */
literal|0x00000000
block|,
comment|/* nws, bb, 0 lines */
literal|0x03490009
block|,
comment|/* nws, k2, 9 lines */
literal|0x00000000
block|,
comment|/* nws, e5, 0 lines */
literal|0x00000000
block|,
comment|/* ms, bb, 0 lines */
literal|0x00120004
block|,
comment|/* ms, k2, 4 lines */
literal|0x00000000
block|,
comment|/* ms, e5, 0 lines */
literal|0x00000000
block|,
comment|/* phy_pcie, bb, 0 lines */
literal|0x0352001a
block|,
comment|/* phy_pcie, k2, 26 lines */
literal|0x00000000
block|,
comment|/* phy_pcie, e5, 0 lines */
literal|0x00000000
block|,
comment|/* led, bb, 0 lines */
literal|0x00000000
block|,
comment|/* led, k2, 0 lines */
literal|0x00000000
block|,
comment|/* led, e5, 0 lines */
literal|0x00000000
block|,
comment|/* avs_wrap, bb, 0 lines */
literal|0x00000000
block|,
comment|/* avs_wrap, k2, 0 lines */
literal|0x00000000
block|,
comment|/* avs_wrap, e5, 0 lines */
literal|0x00000000
block|,
comment|/* bar0_map, bb, 0 lines */
literal|0x00000000
block|,
comment|/* bar0_map, k2, 0 lines */
literal|0x00000000
block|,
comment|/* bar0_map, e5, 0 lines */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data size: 1032 bytes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DBG_VALUES_H__ */
end_comment

end_unit

