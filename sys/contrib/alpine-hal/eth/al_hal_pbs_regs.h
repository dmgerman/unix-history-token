begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  *  @{  * @file   al_hal_pbs_regs.h  *  * @brief ... registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_PBS_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_PBS_REGS_H__
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
name|al_pbs_unit
block|{
comment|/* [0x0] Conf_bus, Configuration of the SB */
name|uint32_t
name|conf_bus
decl_stmt|;
comment|/* [0x4] PASW high */
name|uint32_t
name|dram_0_nb_bar_high
decl_stmt|;
comment|/* [0x8] PASW low */
name|uint32_t
name|dram_0_nb_bar_low
decl_stmt|;
comment|/* [0xc] PASW high */
name|uint32_t
name|dram_1_nb_bar_high
decl_stmt|;
comment|/* [0x10] PASW low */
name|uint32_t
name|dram_1_nb_bar_low
decl_stmt|;
comment|/* [0x14] PASW high */
name|uint32_t
name|dram_2_nb_bar_high
decl_stmt|;
comment|/* [0x18] PASW low */
name|uint32_t
name|dram_2_nb_bar_low
decl_stmt|;
comment|/* [0x1c] PASW high */
name|uint32_t
name|dram_3_nb_bar_high
decl_stmt|;
comment|/* [0x20] PASW low */
name|uint32_t
name|dram_3_nb_bar_low
decl_stmt|;
comment|/* [0x24] PASW high */
name|uint32_t
name|msix_nb_bar_high
decl_stmt|;
comment|/* [0x28] PASW low */
name|uint32_t
name|msix_nb_bar_low
decl_stmt|;
comment|/* [0x2c] PASW high */
name|uint32_t
name|dram_0_sb_bar_high
decl_stmt|;
comment|/* [0x30] PASW low */
name|uint32_t
name|dram_0_sb_bar_low
decl_stmt|;
comment|/* [0x34] PASW high */
name|uint32_t
name|dram_1_sb_bar_high
decl_stmt|;
comment|/* [0x38] PASW low */
name|uint32_t
name|dram_1_sb_bar_low
decl_stmt|;
comment|/* [0x3c] PASW high */
name|uint32_t
name|dram_2_sb_bar_high
decl_stmt|;
comment|/* [0x40] PASW low */
name|uint32_t
name|dram_2_sb_bar_low
decl_stmt|;
comment|/* [0x44] PASW high */
name|uint32_t
name|dram_3_sb_bar_high
decl_stmt|;
comment|/* [0x48] PASW low */
name|uint32_t
name|dram_3_sb_bar_low
decl_stmt|;
comment|/* [0x4c] PASW high */
name|uint32_t
name|msix_sb_bar_high
decl_stmt|;
comment|/* [0x50] PASW low */
name|uint32_t
name|msix_sb_bar_low
decl_stmt|;
comment|/* [0x54] PASW high */
name|uint32_t
name|pcie_mem0_bar_high
decl_stmt|;
comment|/* [0x58] PASW low */
name|uint32_t
name|pcie_mem0_bar_low
decl_stmt|;
comment|/* [0x5c] PASW high */
name|uint32_t
name|pcie_mem1_bar_high
decl_stmt|;
comment|/* [0x60] PASW low */
name|uint32_t
name|pcie_mem1_bar_low
decl_stmt|;
comment|/* [0x64] PASW high */
name|uint32_t
name|pcie_mem2_bar_high
decl_stmt|;
comment|/* [0x68] PASW low */
name|uint32_t
name|pcie_mem2_bar_low
decl_stmt|;
comment|/* [0x6c] PASW high */
name|uint32_t
name|pcie_ext_ecam0_bar_high
decl_stmt|;
comment|/* [0x70] PASW low */
name|uint32_t
name|pcie_ext_ecam0_bar_low
decl_stmt|;
comment|/* [0x74] PASW high */
name|uint32_t
name|pcie_ext_ecam1_bar_high
decl_stmt|;
comment|/* [0x78] PASW low */
name|uint32_t
name|pcie_ext_ecam1_bar_low
decl_stmt|;
comment|/* [0x7c] PASW high */
name|uint32_t
name|pcie_ext_ecam2_bar_high
decl_stmt|;
comment|/* [0x80] PASW low */
name|uint32_t
name|pcie_ext_ecam2_bar_low
decl_stmt|;
comment|/* [0x84] PASW high */
name|uint32_t
name|pbs_nor_bar_high
decl_stmt|;
comment|/* [0x88] PASW low */
name|uint32_t
name|pbs_nor_bar_low
decl_stmt|;
comment|/* [0x8c] PASW high */
name|uint32_t
name|pbs_spi_bar_high
decl_stmt|;
comment|/* [0x90] PASW low */
name|uint32_t
name|pbs_spi_bar_low
decl_stmt|;
name|uint32_t
name|rsrvd_0
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0xa0] PASW high */
name|uint32_t
name|pbs_nand_bar_high
decl_stmt|;
comment|/* [0xa4] PASW low */
name|uint32_t
name|pbs_nand_bar_low
decl_stmt|;
comment|/* [0xa8] PASW high */
name|uint32_t
name|pbs_int_mem_bar_high
decl_stmt|;
comment|/* [0xac] PASW low */
name|uint32_t
name|pbs_int_mem_bar_low
decl_stmt|;
comment|/* [0xb0] PASW high */
name|uint32_t
name|pbs_boot_bar_high
decl_stmt|;
comment|/* [0xb4] PASW low */
name|uint32_t
name|pbs_boot_bar_low
decl_stmt|;
comment|/* [0xb8] PASW high */
name|uint32_t
name|nb_int_bar_high
decl_stmt|;
comment|/* [0xbc] PASW low */
name|uint32_t
name|nb_int_bar_low
decl_stmt|;
comment|/* [0xc0] PASW high */
name|uint32_t
name|nb_stm_bar_high
decl_stmt|;
comment|/* [0xc4] PASW low */
name|uint32_t
name|nb_stm_bar_low
decl_stmt|;
comment|/* [0xc8] PASW high */
name|uint32_t
name|pcie_ecam_int_bar_high
decl_stmt|;
comment|/* [0xcc] PASW low */
name|uint32_t
name|pcie_ecam_int_bar_low
decl_stmt|;
comment|/* [0xd0] PASW high */
name|uint32_t
name|pcie_mem_int_bar_high
decl_stmt|;
comment|/* [0xd4] PASW low */
name|uint32_t
name|pcie_mem_int_bar_low
decl_stmt|;
comment|/* [0xd8] Control */
name|uint32_t
name|winit_cntl
decl_stmt|;
comment|/* [0xdc] Control */
name|uint32_t
name|latch_bars
decl_stmt|;
comment|/* [0xe0] Control */
name|uint32_t
name|pcie_conf_0
decl_stmt|;
comment|/* [0xe4] Control */
name|uint32_t
name|pcie_conf_1
decl_stmt|;
comment|/* [0xe8] Control */
name|uint32_t
name|serdes_mux_pipe
decl_stmt|;
comment|/* [0xec] Control */
name|uint32_t
name|dma_io_master_map
decl_stmt|;
comment|/* [0xf0] Status */
name|uint32_t
name|i2c_pld_status_high
decl_stmt|;
comment|/* [0xf4] Status */
name|uint32_t
name|i2c_pld_status_low
decl_stmt|;
comment|/* [0xf8] Status */
name|uint32_t
name|spi_dbg_status_high
decl_stmt|;
comment|/* [0xfc] Status */
name|uint32_t
name|spi_dbg_status_low
decl_stmt|;
comment|/* [0x100] Status */
name|uint32_t
name|spi_mst_status_high
decl_stmt|;
comment|/* [0x104] Status */
name|uint32_t
name|spi_mst_status_low
decl_stmt|;
comment|/* [0x108] Log */
name|uint32_t
name|mem_pbs_parity_err_high
decl_stmt|;
comment|/* [0x10c] Log */
name|uint32_t
name|mem_pbs_parity_err_low
decl_stmt|;
comment|/* [0x110] Log */
name|uint32_t
name|boot_strap
decl_stmt|;
comment|/* [0x114] Conf */
name|uint32_t
name|cfg_axi_conf_0
decl_stmt|;
comment|/* [0x118] Conf */
name|uint32_t
name|cfg_axi_conf_1
decl_stmt|;
comment|/* [0x11c] Conf */
name|uint32_t
name|cfg_axi_conf_2
decl_stmt|;
comment|/* [0x120] Conf */
name|uint32_t
name|cfg_axi_conf_3
decl_stmt|;
comment|/* [0x124] Conf */
name|uint32_t
name|spi_mst_conf_0
decl_stmt|;
comment|/* [0x128] Conf */
name|uint32_t
name|spi_mst_conf_1
decl_stmt|;
comment|/* [0x12c] Conf */
name|uint32_t
name|spi_slv_conf_0
decl_stmt|;
comment|/* [0x130] Conf */
name|uint32_t
name|apb_mem_conf_int
decl_stmt|;
comment|/* [0x134] PASW remap register */
name|uint32_t
name|sb2nb_cfg_dram_remap
decl_stmt|;
comment|/* [0x138] Control */
name|uint32_t
name|pbs_mux_sel_0
decl_stmt|;
comment|/* [0x13c] Control */
name|uint32_t
name|pbs_mux_sel_1
decl_stmt|;
comment|/* [0x140] Control */
name|uint32_t
name|pbs_mux_sel_2
decl_stmt|;
comment|/* [0x144] Control */
name|uint32_t
name|pbs_mux_sel_3
decl_stmt|;
comment|/* [0x148] PASW high */
name|uint32_t
name|sb_int_bar_high
decl_stmt|;
comment|/* [0x14c] PASW low */
name|uint32_t
name|sb_int_bar_low
decl_stmt|;
comment|/* [0x150] log */
name|uint32_t
name|ufc_pbs_parity_err_high
decl_stmt|;
comment|/* [0x154] log */
name|uint32_t
name|ufc_pbs_parity_err_low
decl_stmt|;
comment|/* [0x158] Cntl - internal */
name|uint32_t
name|gen_conf
decl_stmt|;
comment|/* [0x15c] Device ID and Rev ID */
name|uint32_t
name|chip_id
decl_stmt|;
comment|/* [0x160] Status - internal */
name|uint32_t
name|uart0_debug
decl_stmt|;
comment|/* [0x164] Status - internal */
name|uint32_t
name|uart1_debug
decl_stmt|;
comment|/* [0x168] Status - internal */
name|uint32_t
name|uart2_debug
decl_stmt|;
comment|/* [0x16c] Status - internal */
name|uint32_t
name|uart3_debug
decl_stmt|;
comment|/* [0x170] Control - internal */
name|uint32_t
name|uart0_conf_status
decl_stmt|;
comment|/* [0x174] Control - internal */
name|uint32_t
name|uart1_conf_status
decl_stmt|;
comment|/* [0x178] Control - internal */
name|uint32_t
name|uart2_conf_status
decl_stmt|;
comment|/* [0x17c] Control - internal */
name|uint32_t
name|uart3_conf_status
decl_stmt|;
comment|/* [0x180] Control - internal */
name|uint32_t
name|gpio0_conf_status
decl_stmt|;
comment|/* [0x184] Control - internal */
name|uint32_t
name|gpio1_conf_status
decl_stmt|;
comment|/* [0x188] Control - internal */
name|uint32_t
name|gpio2_conf_status
decl_stmt|;
comment|/* [0x18c] Control - internal */
name|uint32_t
name|gpio3_conf_status
decl_stmt|;
comment|/* [0x190] Control - internal */
name|uint32_t
name|gpio4_conf_status
decl_stmt|;
comment|/* [0x194] Control - internal */
name|uint32_t
name|i2c_gen_conf_status
decl_stmt|;
comment|/* [0x198] Control - internal */
name|uint32_t
name|i2c_gen_debug
decl_stmt|;
comment|/* [0x19c] Cntl */
name|uint32_t
name|watch_dog_reset_out
decl_stmt|;
comment|/* [0x1a0] Cntl */
name|uint32_t
name|otp_magic_num
decl_stmt|;
comment|/* 	 * [0x1a4] Control - internal 	 */
name|uint32_t
name|otp_cntl
decl_stmt|;
comment|/* [0x1a8] Cfg - internal */
name|uint32_t
name|otp_cfg_0
decl_stmt|;
comment|/* [0x1ac] Cfg - internal */
name|uint32_t
name|otp_cfg_1
decl_stmt|;
comment|/* [0x1b0] Cfg - internal */
name|uint32_t
name|otp_cfg_3
decl_stmt|;
comment|/* [0x1b4] Cfg */
name|uint32_t
name|cfg_nand_0
decl_stmt|;
comment|/* [0x1b8] Cfg */
name|uint32_t
name|cfg_nand_1
decl_stmt|;
comment|/* [0x1bc] Cfg-- timing parameters internal. */
name|uint32_t
name|cfg_nand_2
decl_stmt|;
comment|/* [0x1c0] Cfg - internal */
name|uint32_t
name|cfg_nand_3
decl_stmt|;
comment|/* [0x1c4] PASW high */
name|uint32_t
name|nb_nic_regs_bar_high
decl_stmt|;
comment|/* [0x1c8] PASW low */
name|uint32_t
name|nb_nic_regs_bar_low
decl_stmt|;
comment|/* [0x1cc] PASW high */
name|uint32_t
name|sb_nic_regs_bar_high
decl_stmt|;
comment|/* [0x1d0] PASW low */
name|uint32_t
name|sb_nic_regs_bar_low
decl_stmt|;
comment|/* [0x1d4] Control */
name|uint32_t
name|serdes_mux_multi_0
decl_stmt|;
comment|/* [0x1d8] Control */
name|uint32_t
name|serdes_mux_multi_1
decl_stmt|;
comment|/* [0x1dc] Control - not in use any more - internal */
name|uint32_t
name|pbs_ulpi_mux_conf
decl_stmt|;
comment|/* [0x1e0] Cntl */
name|uint32_t
name|wr_once_dbg_dis_ovrd_reg
decl_stmt|;
comment|/* [0x1e4] Cntl - internal */
name|uint32_t
name|gpio5_conf_status
decl_stmt|;
comment|/* [0x1e8] PASW high */
name|uint32_t
name|pcie_mem3_bar_high
decl_stmt|;
comment|/* [0x1ec] PASW low */
name|uint32_t
name|pcie_mem3_bar_low
decl_stmt|;
comment|/* [0x1f0] PASW high */
name|uint32_t
name|pcie_mem4_bar_high
decl_stmt|;
comment|/* [0x1f4] PASW low */
name|uint32_t
name|pcie_mem4_bar_low
decl_stmt|;
comment|/* [0x1f8] PASW high */
name|uint32_t
name|pcie_mem5_bar_high
decl_stmt|;
comment|/* [0x1fc] PASW low */
name|uint32_t
name|pcie_mem5_bar_low
decl_stmt|;
comment|/* [0x200] PASW high */
name|uint32_t
name|pcie_ext_ecam3_bar_high
decl_stmt|;
comment|/* [0x204] PASW low */
name|uint32_t
name|pcie_ext_ecam3_bar_low
decl_stmt|;
comment|/* [0x208] PASW high */
name|uint32_t
name|pcie_ext_ecam4_bar_high
decl_stmt|;
comment|/* [0x20c] PASW low */
name|uint32_t
name|pcie_ext_ecam4_bar_low
decl_stmt|;
comment|/* [0x210] PASW high */
name|uint32_t
name|pcie_ext_ecam5_bar_high
decl_stmt|;
comment|/* [0x214] PASW low */
name|uint32_t
name|pcie_ext_ecam5_bar_low
decl_stmt|;
comment|/* [0x218] PASW high */
name|uint32_t
name|low_latency_sram_bar_high
decl_stmt|;
comment|/* [0x21c] PASW low */
name|uint32_t
name|low_latency_sram_bar_low
decl_stmt|;
comment|/* [0x220] Control */
name|uint32_t
name|pbs_mux_sel_4
decl_stmt|;
comment|/* [0x224] Control */
name|uint32_t
name|pbs_mux_sel_5
decl_stmt|;
comment|/* [0x228] Control */
name|uint32_t
name|serdes_mux_eth
decl_stmt|;
comment|/* [0x22c] Control */
name|uint32_t
name|serdes_mux_pcie
decl_stmt|;
comment|/* [0x230] Control */
name|uint32_t
name|serdes_mux_sata
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pbs_low_latency_sram_remap
block|{
comment|/* [0x0] PBS MEM Remap */
name|uint32_t
name|bar1_orig
decl_stmt|;
comment|/* [0x4] PBS MEM Remap */
name|uint32_t
name|bar1_remap
decl_stmt|;
comment|/* [0x8] ETH0 MEM Remap */
name|uint32_t
name|bar2_orig
decl_stmt|;
comment|/* [0xc] ETH0 MEM Remap */
name|uint32_t
name|bar2_remap
decl_stmt|;
comment|/* [0x10] ETH1 MEM Remap */
name|uint32_t
name|bar3_orig
decl_stmt|;
comment|/* [0x14] ETH1 MEM Remap */
name|uint32_t
name|bar3_remap
decl_stmt|;
comment|/* [0x18] ETH2 MEM Remap */
name|uint32_t
name|bar4_orig
decl_stmt|;
comment|/* [0x1c] ETH2 MEM Remap */
name|uint32_t
name|bar4_remap
decl_stmt|;
comment|/* [0x20] ETH3 MEM Remap */
name|uint32_t
name|bar5_orig
decl_stmt|;
comment|/* [0x24] ETH3 MEM Remap */
name|uint32_t
name|bar5_remap
decl_stmt|;
comment|/* [0x28] CRYPTO0 MEM Remap */
name|uint32_t
name|bar6_orig
decl_stmt|;
comment|/* [0x2c] CRYPTO0 MEM Remap */
name|uint32_t
name|bar6_remap
decl_stmt|;
comment|/* [0x30] RAID0 MEM Remap */
name|uint32_t
name|bar7_orig
decl_stmt|;
comment|/* [0x34] RAID0 MEM Remap */
name|uint32_t
name|bar7_remap
decl_stmt|;
comment|/* [0x38] CRYPTO1 MEM Remap */
name|uint32_t
name|bar8_orig
decl_stmt|;
comment|/* [0x3c] CRYPTO1 MEM Remap */
name|uint32_t
name|bar8_remap
decl_stmt|;
comment|/* [0x40] RAID1 MEM Remap */
name|uint32_t
name|bar9_orig
decl_stmt|;
comment|/* [0x44] RAID2 MEM Remap */
name|uint32_t
name|bar9_remap
decl_stmt|;
comment|/* [0x48] RESERVED MEM Remap */
name|uint32_t
name|bar10_orig
decl_stmt|;
comment|/* [0x4c] RESERVED MEM Remap */
name|uint32_t
name|bar10_remap
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pbs_target_id_enforcement
block|{
comment|/* [0x0] target enforcement */
name|uint32_t
name|cpu
decl_stmt|;
comment|/* [0x4] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|cpu_mask
decl_stmt|;
comment|/* [0x8] target enforcement */
name|uint32_t
name|debug_nb
decl_stmt|;
comment|/* [0xc] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|debug_nb_mask
decl_stmt|;
comment|/* [0x10] target enforcement */
name|uint32_t
name|debug_sb
decl_stmt|;
comment|/* [0x14] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|debug_sb_mask
decl_stmt|;
comment|/* [0x18] target enforcement */
name|uint32_t
name|eth_0
decl_stmt|;
comment|/* [0x1c] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|eth_0_mask
decl_stmt|;
comment|/* [0x20] target enforcement */
name|uint32_t
name|eth_1
decl_stmt|;
comment|/* [0x24] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|eth_1_mask
decl_stmt|;
comment|/* [0x28] target enforcement */
name|uint32_t
name|eth_2
decl_stmt|;
comment|/* [0x2c] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|eth_2_mask
decl_stmt|;
comment|/* [0x30] target enforcement */
name|uint32_t
name|eth_3
decl_stmt|;
comment|/* [0x34] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|eth_3_mask
decl_stmt|;
comment|/* [0x38] target enforcement */
name|uint32_t
name|sata_0
decl_stmt|;
comment|/* [0x3c] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|sata_0_mask
decl_stmt|;
comment|/* [0x40] target enforcement */
name|uint32_t
name|sata_1
decl_stmt|;
comment|/* [0x44] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|sata_1_mask
decl_stmt|;
comment|/* [0x48] target enforcement */
name|uint32_t
name|crypto_0
decl_stmt|;
comment|/* [0x4c] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|crypto_0_mask
decl_stmt|;
comment|/* [0x50] target enforcement */
name|uint32_t
name|crypto_1
decl_stmt|;
comment|/* [0x54] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|crypto_1_mask
decl_stmt|;
comment|/* [0x58] target enforcement */
name|uint32_t
name|pcie_0
decl_stmt|;
comment|/* [0x5c] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|pcie_0_mask
decl_stmt|;
comment|/* [0x60] target enforcement */
name|uint32_t
name|pcie_1
decl_stmt|;
comment|/* [0x64] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|pcie_1_mask
decl_stmt|;
comment|/* [0x68] target enforcement */
name|uint32_t
name|pcie_2
decl_stmt|;
comment|/* [0x6c] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|pcie_2_mask
decl_stmt|;
comment|/* [0x70] target enforcement */
name|uint32_t
name|pcie_3
decl_stmt|;
comment|/* [0x74] target enforcement mask (bits which are 0 are not compared) */
name|uint32_t
name|pcie_3_mask
decl_stmt|;
comment|/* [0x78] Control */
name|uint32_t
name|latch
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_pbs_regs
block|{
name|struct
name|al_pbs_unit
name|unit
decl_stmt|;
comment|/* [0x0] */
name|struct
name|al_pbs_low_latency_sram_remap
name|low_latency_sram_remap
decl_stmt|;
comment|/* [0x250] */
name|uint32_t
name|rsrvd_0
index|[
literal|88
index|]
decl_stmt|;
name|struct
name|al_pbs_target_id_enforcement
name|target_id_enforcement
decl_stmt|;
comment|/* [0x400] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** conf_bus register ****/
comment|/* Read slave error enable */
define|#
directive|define
name|PBS_UNIT_CONF_BUS_RD_SLVERR_EN
value|(1<< 0)
comment|/* Write slave error enable */
define|#
directive|define
name|PBS_UNIT_CONF_BUS_WR_SLVERR_EN
value|(1<< 1)
comment|/* Read decode error enable */
define|#
directive|define
name|PBS_UNIT_CONF_BUS_RD_DECERR_EN
value|(1<< 2)
comment|/* Write decode error enable */
define|#
directive|define
name|PBS_UNIT_CONF_BUS_WR_DECERR_EN
value|(1<< 3)
comment|/* For debug clear the APB SM */
define|#
directive|define
name|PBS_UNIT_CONF_BUS_CLR_APB_FSM
value|(1<< 4)
comment|/* For debug clear the WFIFO */
define|#
directive|define
name|PBS_UNIT_CONF_BUS_CLR_WFIFO_CLEAR
value|(1<< 5)
comment|/* Arbiter between read and write channel */
define|#
directive|define
name|PBS_UNIT_CONF_BUS_WRR_CNT_MASK
value|0x000001C0
define|#
directive|define
name|PBS_UNIT_CONF_BUS_WRR_CNT_SHIFT
value|6
comment|/* general PASWS */
comment|/* window size = 2 ^ (15 + win_size), zero value disable the win ... */
define|#
directive|define
name|PBS_PASW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_PASW_WIN_SIZE_SHIFT
value|0
comment|/* reserved fields */
define|#
directive|define
name|PBS_PASW_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_PASW_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_PASW_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_PASW_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** dram_0_nb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_DRAM_0_NB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_DRAM_0_NB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DRAM_0_NB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_DRAM_0_NB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_DRAM_0_NB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DRAM_0_NB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** dram_1_nb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_DRAM_1_NB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_DRAM_1_NB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DRAM_1_NB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_DRAM_1_NB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_DRAM_1_NB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DRAM_1_NB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** dram_2_nb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_DRAM_2_NB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_DRAM_2_NB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DRAM_2_NB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_DRAM_2_NB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_DRAM_2_NB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DRAM_2_NB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** dram_3_nb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_DRAM_3_NB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_DRAM_3_NB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DRAM_3_NB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_DRAM_3_NB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_DRAM_3_NB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DRAM_3_NB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** msix_nb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_MSIX_NB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_MSIX_NB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_MSIX_NB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_MSIX_NB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_MSIX_NB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_MSIX_NB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** dram_0_sb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_DRAM_0_SB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_DRAM_0_SB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DRAM_0_SB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_DRAM_0_SB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_DRAM_0_SB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DRAM_0_SB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** dram_1_sb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_DRAM_1_SB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_DRAM_1_SB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DRAM_1_SB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_DRAM_1_SB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_DRAM_1_SB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DRAM_1_SB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** dram_2_sb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_DRAM_2_SB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_DRAM_2_SB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DRAM_2_SB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_DRAM_2_SB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_DRAM_2_SB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DRAM_2_SB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** dram_3_sb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_DRAM_3_SB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_DRAM_3_SB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DRAM_3_SB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_DRAM_3_SB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_DRAM_3_SB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DRAM_3_SB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** msix_sb_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_MSIX_SB_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_MSIX_SB_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_MSIX_SB_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_MSIX_SB_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_MSIX_SB_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_MSIX_SB_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_mem0_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM0_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_MEM0_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM0_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_MEM0_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM0_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_MEM0_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_mem1_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM1_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_MEM1_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM1_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_MEM1_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM1_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_MEM1_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_mem2_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM2_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_MEM2_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM2_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_MEM2_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM2_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_MEM2_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_ext_ecam0_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM0_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM0_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM0_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM0_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM0_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM0_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_ext_ecam1_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM1_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM1_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM1_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM1_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM1_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM1_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_ext_ecam2_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM2_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM2_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM2_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM2_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM2_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM2_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pbs_nor_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PBS_NOR_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PBS_NOR_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PBS_NOR_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PBS_NOR_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PBS_NOR_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PBS_NOR_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pbs_spi_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PBS_SPI_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PBS_SPI_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PBS_SPI_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PBS_SPI_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PBS_SPI_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PBS_SPI_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pbs_nand_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PBS_NAND_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PBS_NAND_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PBS_NAND_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PBS_NAND_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PBS_NAND_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PBS_NAND_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pbs_int_mem_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PBS_INT_MEM_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PBS_INT_MEM_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PBS_INT_MEM_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PBS_INT_MEM_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PBS_INT_MEM_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PBS_INT_MEM_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pbs_boot_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PBS_BOOT_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PBS_BOOT_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PBS_BOOT_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PBS_BOOT_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PBS_BOOT_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PBS_BOOT_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** nb_int_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_NB_INT_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_NB_INT_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_NB_INT_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_NB_INT_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_NB_INT_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_NB_INT_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** nb_stm_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_NB_STM_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_NB_STM_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_NB_STM_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_NB_STM_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_NB_STM_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_NB_STM_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_ecam_int_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_ECAM_INT_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_ECAM_INT_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_ECAM_INT_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_ECAM_INT_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PCIE_ECAM_INT_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_ECAM_INT_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_mem_int_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM_INT_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_MEM_INT_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM_INT_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_MEM_INT_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM_INT_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_MEM_INT_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** winit_cntl register ****/
comment|/* When set, enables access to winit regs, in normal mode. */
define|#
directive|define
name|PBS_UNIT_WINIT_CNTL_ENABLE_WINIT_REGS_ACCESS
value|(1<< 0)
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_WINIT_CNTL_RSRVD_MASK
value|0xFFFFFFFE
define|#
directive|define
name|PBS_UNIT_WINIT_CNTL_RSRVD_SHIFT
value|1
comment|/**** latch_bars register ****/
comment|/*  * Software clears this bit before any bar update, and set it after all bars  * updated.  */
define|#
directive|define
name|PBS_UNIT_LATCH_BARS_ENABLE
value|(1<< 0)
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_LATCH_BARS_RSRVD_MASK
value|0xFFFFFFFE
define|#
directive|define
name|PBS_UNIT_LATCH_BARS_RSRVD_SHIFT
value|1
comment|/**** pcie_conf_0 register ****/
comment|/* NOT_use, config internal inside each PCIe core */
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_0_DEVS_TYPE_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_0_DEVS_TYPE_SHIFT
value|0
comment|/* sys_aux_det value */
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_0_SYS_AUX_PWR_DET_VEC_MASK
value|0x00007000
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_0_SYS_AUX_PWR_DET_VEC_SHIFT
value|12
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_0_RSRVD_MASK
value|0xFFFF8000
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_0_RSRVD_SHIFT
value|15
comment|/**** pcie_conf_1 register ****/
comment|/*  * Which PCIe exists? The PCIe device is under reset until the corresponding bit  * is set.  */
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_1_PCIE_EXIST_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_1_PCIE_EXIST_SHIFT
value|0
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_1_RSRVD_MASK
value|0xFFFFFFC0
define|#
directive|define
name|PBS_UNIT_PCIE_CONF_1_RSRVD_SHIFT
value|6
comment|/**** serdes_mux_pipe register ****/
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_SERDES_2_MASK
value|0x00000007
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_SERDES_2_SHIFT
value|0
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_RSRVD_3
value|(1<< 3)
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_SERDES_3_MASK
value|0x00000070
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_SERDES_3_SHIFT
value|4
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_RSRVD_7
value|(1<< 7)
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_PCI_B_0_MASK
value|0x00000300
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_PCI_B_0_SHIFT
value|8
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_PCI_B_1_MASK
value|0x00000C00
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_PCI_B_1_SHIFT
value|10
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_PCI_C_0_MASK
value|0x00003000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_PCI_C_0_SHIFT
value|12
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_PCI_C_1_MASK
value|0x0000C000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_PCI_C_1_SHIFT
value|14
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_USB_A_0_MASK
value|0x00030000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_USB_A_0_SHIFT
value|16
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_USB_B_0_MASK
value|0x000C0000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_USB_B_0_SHIFT
value|18
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_CLKI_SER_2_MASK
value|0x00300000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_CLKI_SER_2_SHIFT
value|20
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_RSRVD_23_22_MASK
value|0x00C00000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_RSRVD_23_22_SHIFT
value|22
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_CLKI_SER_3_MASK
value|0x07000000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_SELECT_OH_CLKI_SER_3_SHIFT
value|24
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_RSRVD_MASK
value|0xF8000000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_RSRVD_SHIFT
value|27
comment|/*  * 2'b01 - select pcie_b[0]  * 2'b10 - select pcie_a[2]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_2_MASK
value|0x00000003
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_2_SHIFT
value|0
comment|/*  * 2'b01 - select pcie_b[1]  * 2'b10 - select pcie_a[3]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_3_MASK
value|0x00000030
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_3_SHIFT
value|4
comment|/*  * 2'b01 - select pcie_b[0]  * 2'b10 - select pcie_a[4]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_4_MASK
value|0x00000300
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_4_SHIFT
value|8
comment|/*  * 2'b01 - select pcie_b[1]  * 2'b10 - select pcie_a[5]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_5_MASK
value|0x00003000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_5_SHIFT
value|12
comment|/*  * 2'b01 - select pcie_b[2]  * 2'b10 - select pcie_a[6]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_6_MASK
value|0x00030000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_6_SHIFT
value|16
comment|/*  * 2'b01 - select pcie_b[3]  * 2'b10 - select pcie_a[7]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_7_MASK
value|0x00300000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_7_SHIFT
value|20
comment|/*  * 2'b01 - select pcie_d[0]  * 2'b10 - select pcie_c[2]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_10_MASK
value|0x03000000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_10_SHIFT
value|24
comment|/*  * 2'b01 - select pcie_d[1]  * 2'b10 - select pcie_c[3]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_11_MASK
value|0x30000000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PIPE_PKR_SELECT_OH_SERDES_11_SHIFT
value|28
comment|/**** dma_io_master_map register ****/
comment|/*  * [0]: When set, maps all the io_dma transactions to the NB/DRAM, regardless of  * the window hit.  * [1]: When set, maps all the eth_0 transactions to the NB/DRAM, regardless of  * the window hit.  * [2]: When set, maps all the eth_2 transaction to the NB/DRAM, regardless of  * the window hit.  * [3]: When set, maps all the sata_0 transactions to the NB/DRAM, regardless of  * the window hit.  * [4]: When set, maps all the sata_1 transactions to the NB/DRAM, regardless of  * the window hit.  * [5]: When set, maps all the pcie_0 master transactions to the NB/DRAM,  * regardless of the window hit.  * [6]: When set, maps all the SPI debug port transactions to the NB/DRAM,  * regardless of the window hit.  * [7]: When set, maps all the CPU debug port transactions to the NB/DRAM,  * regardless of the window hit.  * [8] When set, maps all the Crypto transactions to the NB/DRAM, regardless of  * the window hit.  * [15:9] - Reserved  */
define|#
directive|define
name|PBS_UNIT_DMA_IO_MASTER_MAP_CNTL_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_DMA_IO_MASTER_MAP_CNTL_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_DMA_IO_MASTER_MAP_RSRVD_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_DMA_IO_MASTER_MAP_RSRVD_SHIFT
value|16
comment|/**** i2c_pld_status_high register ****/
comment|/* I2C pre-load status  */
define|#
directive|define
name|PBS_UNIT_I2C_PLD_STATUS_HIGH_STATUS_MASK
value|0x000000FF
define|#
directive|define
name|PBS_UNIT_I2C_PLD_STATUS_HIGH_STATUS_SHIFT
value|0
comment|/**** spi_dbg_status_high register ****/
comment|/* SPI DBG load status */
define|#
directive|define
name|PBS_UNIT_SPI_DBG_STATUS_HIGH_STATUS_MASK
value|0x000000FF
define|#
directive|define
name|PBS_UNIT_SPI_DBG_STATUS_HIGH_STATUS_SHIFT
value|0
comment|/**** spi_mst_status_high register ****/
comment|/* SP IMST load status */
define|#
directive|define
name|PBS_UNIT_SPI_MST_STATUS_HIGH_STATUS_MASK
value|0x000000FF
define|#
directive|define
name|PBS_UNIT_SPI_MST_STATUS_HIGH_STATUS_SHIFT
value|0
comment|/**** mem_pbs_parity_err_high register ****/
comment|/* Address latch in the case of a parity error */
define|#
directive|define
name|PBS_UNIT_MEM_PBS_PARITY_ERR_HIGH_ADDR_MASK
value|0x000000FF
define|#
directive|define
name|PBS_UNIT_MEM_PBS_PARITY_ERR_HIGH_ADDR_SHIFT
value|0
comment|/**** cfg_axi_conf_0 register ****/
comment|/* Sets the AXI field in the I2C preloader  interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_RD_ID_MASK
value|0x0000007F
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_RD_ID_SHIFT
value|0
comment|/* Sets the AXI field in the I2C preloader  interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_WR_ID_MASK
value|0x00003F80
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_WR_ID_SHIFT
value|7
comment|/* Sets the AXI field in the I2C preloader  interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_PLD_WR_ID_MASK
value|0x001FC000
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_PLD_WR_ID_SHIFT
value|14
comment|/* Sets the AXI field in the SPI debug interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_AWCACHE_MASK
value|0x01E00000
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_AWCACHE_SHIFT
value|21
comment|/* Sets the AXI field in the SPI debug interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_ARCACHE_MASK
value|0x1E000000
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_ARCACHE_SHIFT
value|25
comment|/* Sets the AXI field in the SPI debug interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_AXPROT_MASK
value|0xE0000000
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_0_DBG_AXPROT_SHIFT
value|29
comment|/**** cfg_axi_conf_1 register ****/
comment|/* Sets the AXI field in the SPI debug interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_1_DBG_ARUSER_MASK
value|0x03FFFFFF
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_1_DBG_ARUSER_SHIFT
value|0
comment|/* Sets the AXI field in the SPI debug interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_1_DBG_ARQOS_MASK
value|0x3C000000
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_1_DBG_ARQOS_SHIFT
value|26
comment|/**** cfg_axi_conf_2 register ****/
comment|/* Sets the AXI field in the SPI debug interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_2_DBG_AWUSER_MASK
value|0x03FFFFFF
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_2_DBG_AWUSER_SHIFT
value|0
comment|/* Sets the AXI field in the SPI debug interface. */
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_2_DBG_AWQOS_MASK
value|0x3C000000
define|#
directive|define
name|PBS_UNIT_CFG_AXI_CONF_2_DBG_AWQOS_SHIFT
value|26
comment|/**** spi_mst_conf_0 register ****/
comment|/*  * Sets the SPI master Configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_SRL
value|(1<< 0)
comment|/*  * Sets the SPI master Configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_SCPOL
value|(1<< 1)
comment|/*  * Sets the SPI master Configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_SCPH
value|(1<< 2)
comment|/*  * Set the SPI master configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_SER_MASK
value|0x00000078
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_SER_SHIFT
value|3
comment|/*  * Set the SPI master configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_BAUD_MASK
value|0x007FFF80
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_BAUD_SHIFT
value|7
comment|/*  * Sets the SPI master configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_RD_CMD_MASK
value|0x7F800000
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_0_CFG_SPI_MST_RD_CMD_SHIFT
value|23
comment|/**** spi_mst_conf_1 register ****/
comment|/*  * Sets the SPI master Configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_1_CFG_SPI_MST_WR_CMD_MASK
value|0x000000FF
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_1_CFG_SPI_MST_WR_CMD_SHIFT
value|0
comment|/*  * Sets the SPI master Configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_1_CFG_SPI_MST_ADDR_BYTES_NUM_MASK
value|0x00000700
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_1_CFG_SPI_MST_ADDR_BYTES_NUM_SHIFT
value|8
comment|/*  * Sets the SPI master Configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_1_CFG_SPI_MST_TMODE_MASK
value|0x00001800
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_1_CFG_SPI_MST_TMODE_SHIFT
value|11
comment|/*  * Sets the SPI master Configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_MST_CONF_1_CFG_SPI_MST_FAST_RD
value|(1<< 13)
comment|/**** spi_slv_conf_0 register ****/
comment|/*  * Sets the SPI slave configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_BAUD_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_BAUD_SHIFT
value|0
comment|/* Value. The reset value is according to bootstrap. */
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_SCPOL
value|(1<< 16)
comment|/* Value. The reset value is according to bootstrap. */
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_SCPH
value|(1<< 17)
comment|/*  * Sets the SPI slave configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_SER_MASK
value|0x03FC0000
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_SER_SHIFT
value|18
comment|/*  * Sets the SPI slave configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_SRL
value|(1<< 26)
comment|/*  * Sets the SPI slave configuration. For details see the SPI section in the  * documentation.  */
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_TMODE_MASK
value|0x18000000
define|#
directive|define
name|PBS_UNIT_SPI_SLV_CONF_0_CFG_SPI_SLV_TMODE_SHIFT
value|27
comment|/**** apb_mem_conf_int register ****/
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_PBS_WRR_CNT_MASK
value|0x00000007
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_PBS_WRR_CNT_SHIFT
value|0
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_I2C_PLD_APB_MIX_ARB
value|(1<< 3)
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_SPI_DBG_APB_MIX_ARB
value|(1<< 4)
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_SPI_MST_APB_MIX_ARB
value|(1<< 5)
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_I2C_PLD_CLEAR_FSM
value|(1<< 6)
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_SPI_DBG_CLEAR_FSM
value|(1<< 7)
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_SPI_MST_CLEAR_FSM
value|(1<< 8)
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_PBS_AXI_FSM_CLEAR
value|(1<< 9)
comment|/* Value-- internal */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_PBS_AXI_FIFOS_CLEAR
value|(1<< 10)
comment|/* Enables parity protection on the integrated SRAM. */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_BOOTROM_PARITY_EN
value|(1<< 11)
comment|/*  * When set, reports a slave error whenthe slave returns an AXI slave error, for  * configuration access to the internal configuration space.  */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_RD_SLV_ERR_EN
value|(1<< 12)
comment|/*  * When set, reports a decode error when timeout has occurred for configuration  * access to the internal configuration space.  */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_RD_DEC_ERR_EN
value|(1<< 13)
comment|/*  * When set, reports a slave error, when the slave returns an AXI slave error,  * for configuration access to the internal configuration space.  */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_WR_SLV_ERR_EN
value|(1<< 14)
comment|/*  * When set, reports a decode error when timeout has occurred for configuration  * access to the internal configuration space.  */
define|#
directive|define
name|PBS_UNIT_APB_MEM_CONF_INT_CFG_WR_DEC_ERR_EN
value|(1<< 15)
comment|/**** sb_int_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_SB_INT_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_SB_INT_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_SB_INT_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_SB_INT_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_SB_INT_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_SB_INT_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** ufc_pbs_parity_err_high register ****/
comment|/*  * Address latch in the case of a parity error in the Flash Controller internal  * memories.  */
define|#
directive|define
name|PBS_UNIT_UFC_PBS_PARITY_ERR_HIGH_ADDR_MASK
value|0x000000FF
define|#
directive|define
name|PBS_UNIT_UFC_PBS_PARITY_ERR_HIGH_ADDR_SHIFT
value|0
comment|/**** chip_id register ****/
comment|/* [15:0] : Dev Rev ID */
define|#
directive|define
name|PBS_UNIT_CHIP_ID_DEV_REV_ID_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_CHIP_ID_DEV_REV_ID_SHIFT
value|0
comment|/* [31:16] : 0x0 - Dev ID */
define|#
directive|define
name|PBS_UNIT_CHIP_ID_DEV_ID_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_CHIP_ID_DEV_ID_SHIFT
value|16
define|#
directive|define
name|PBS_UNIT_CHIP_ID_DEV_ID_ALPINE
value|0
define|#
directive|define
name|PBS_UNIT_CHIP_ID_DEV_ID_PEAKROCK
value|1
define|#
directive|define
name|PBS_UNIT_CHIP_ID_DEV_ID_COYOTE
value|2
comment|/**** uart0_conf_status register ****/
comment|/*  * Conf:  * // [0] -- DSR_N RW bit  * // [1] -- DCD_N RW bit  * // [2] -- RI_N bit  * // [3] -- dma_tx_ack_n  * // [4] -- dma_rx_ack_n  */
define|#
directive|define
name|PBS_UNIT_UART0_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_UART0_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status:  * // [16] -- dtr_n RO bit  * // [17] -- OUT1_N RO bit  * // [18] -- OUT2_N RO bit  * // [19] -- dma_tx_req_n RO bit  * // [20] -- dma_tx_single_n RO bit  * // [21] -- dma_rx_req_n RO bit  * // [22] -- dma_rx_single_n RO bit  * // [23] -- uart_lp_req_pclk RO bit  * // [24] -- baudout_n RO bit  */
define|#
directive|define
name|PBS_UNIT_UART0_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_UART0_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** uart1_conf_status register ****/
comment|/*  * Conf: // [0] -- DSR_N RW bit // [1] -- DCD_N RW bit // [2] -- RI_N bit // [3]  * -- dma_tx_ack_n // [4] - dma_rx_ack_n  */
define|#
directive|define
name|PBS_UNIT_UART1_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_UART1_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status: // [16] -- dtr_n RO bit // [17] -- OUT1_N RO bit // [18] -- OUT2_N RO  * bit // [19] -- dma_tx_req_n RO bit // [20] -- dma_tx_single_n RO bit // [21]  * -- dma_rx_req_n RO bit // [22] -- dma_rx_single_n RO bit // [23] --  * uart_lp_req_pclk RO bit // [24] -- baudout_n RO bit  */
define|#
directive|define
name|PBS_UNIT_UART1_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_UART1_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** uart2_conf_status register ****/
comment|/*  * Conf: // [0] -- DSR_N RW bit // [1] -- DCD_N RW bit // [2] -- RI_N bit // [3]  * -- dma_tx_ack_n // [4] - dma_rx_ack_n  */
define|#
directive|define
name|PBS_UNIT_UART2_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_UART2_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status: // [16] -- dtr_n RO bit // [17] -- OUT1_N RO bit // [18] -- OUT2_N RO  * bit // [19] -- dma_tx_req_n RO bit // [20] -- dma_tx_single_n RO bit // [21]  * -- dma_rx_req_n RO bit // [22] -- dma_rx_single_n RO bit // [23] --  * uart_lp_req_pclk RO bit // [24] -- baudout_n RO bit  */
define|#
directive|define
name|PBS_UNIT_UART2_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_UART2_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** uart3_conf_status register ****/
comment|/*  * Conf: // [0] -- DSR_N RW bit // [1] -- DCD_N RW bit // [2] -- RI_N bit // [3]  * -- dma_tx_ack_n // [4] - dma_rx_ack_n  */
define|#
directive|define
name|PBS_UNIT_UART3_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_UART3_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status: // [16] -- dtr_n RO bit // [17] -- OUT1_N RO bit // [18] -- OUT2_N RO  * bit // [19] -- dma_tx_req_n RO bit // [20] -- dma_tx_single_n RO bit // [21]  * -- dma_rx_req_n RO bit // [22] -- dma_rx_single_n RO bit // [23] --  * uart_lp_req_pclk RO bit // [24] -- baudout_n RO bit  */
define|#
directive|define
name|PBS_UNIT_UART3_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_UART3_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** gpio0_conf_status register ****/
comment|/*  * Cntl:  * //  [7:0] nGPAFEN;              // from regfile  * //  [15:8] GPAFOUT;             // from regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO0_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_GPIO0_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status:  * //  [24:16] GPAFIN;             // to regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO0_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_GPIO0_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** gpio1_conf_status register ****/
comment|/*  * Cntl:  * //  [7:0] nGPAFEN;              // from regfile  * //  [15:8] GPAFOUT;             // from regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO1_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_GPIO1_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status:  * //  [24:16] GPAFIN;             // to regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO1_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_GPIO1_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** gpio2_conf_status register ****/
comment|/*  * Cntl:  * //  [7:0] nGPAFEN;              // from regfile  * //  [15:8] GPAFOUT;             // from regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO2_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_GPIO2_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status:  * //  [24:16] GPAFIN;             // to regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO2_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_GPIO2_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** gpio3_conf_status register ****/
comment|/*  * Cntl:  * //  [7:0] nGPAFEN;              // from regfile  * //  [15:8] GPAFOUT;             // from regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO3_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_GPIO3_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status:  * //  [24:16] GPAFIN;             // to regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO3_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_GPIO3_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** gpio4_conf_status register ****/
comment|/*  * Cntl:  * //  [7:0] nGPAFEN;              // from regfile  * //  [15:8] GPAFOUT;             // from regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO4_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_GPIO4_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status:  * //  [24:16] GPAFIN;             // to regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO4_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_GPIO4_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** i2c_gen_conf_status register ****/
comment|/*  * cntl  * // [0] -- dma_tx_ack  * // [1] -- dma_rx_ack  */
define|#
directive|define
name|PBS_UNIT_I2C_GEN_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_I2C_GEN_CONF_STATUS_CONF_SHIFT
value|0
comment|/*  * Status  *  * // [16] -- dma_tx_req RO bit  * // [17] -- dma_tx_single RO bit  * // [18] -- dma_rx_req RO bit  * // [19] -- dma_rx_single RO bit  */
define|#
directive|define
name|PBS_UNIT_I2C_GEN_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_I2C_GEN_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** watch_dog_reset_out register ****/
comment|/*  * [0] If set to 1'b1, WD0 cannot generate reset_out_n  * [1] If set to 1'b1, WD1 cannot generate reset_out_n  * [2] If set to 1'b1, WD2 cannot generate reset_out_n  * [3] If set to 1'b1, WD3 cannot generate reset_out_n  * [4] If set to 1'b1, WD4 cannot generate reset_out_n  * [5] If set to 1'b1, WD5 cannot generate reset_out_n  * [6] If set to 1'b1, WD6 cannot generate reset_out_n  * [7] If set to 1'b1, WD7 cannot generate reset_out_n  */
define|#
directive|define
name|PBS_UNIT_WATCH_DOG_RESET_OUT_DISABLE_MASK
value|0x000000FF
define|#
directive|define
name|PBS_UNIT_WATCH_DOG_RESET_OUT_DISABLE_SHIFT
value|0
comment|/**** otp_cntl register ****/
comment|/* from reg file Config To bypass the copy from OTPW to OTPR */
define|#
directive|define
name|PBS_UNIT_OTP_CNTL_IGNORE_OTPW
value|(1<< 0)
comment|/* Not in use.Comes from bond. */
define|#
directive|define
name|PBS_UNIT_OTP_CNTL_IGNORE_PRELOAD
value|(1<< 1)
comment|/* Margin read from the fuse box */
define|#
directive|define
name|PBS_UNIT_OTP_CNTL_OTPW_MARGIN_READ
value|(1<< 2)
comment|/* Indicates when OTPis  busy.  */
define|#
directive|define
name|PBS_UNIT_OTP_CNTL_OTP_BUSY
value|(1<< 3)
comment|/**** otp_cfg_0 register ****/
comment|/* Cfg  to OTP cntl. */
define|#
directive|define
name|PBS_UNIT_OTP_CFG_0_CFG_OTPW_PWRDN_CNT_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_OTP_CFG_0_CFG_OTPW_PWRDN_CNT_SHIFT
value|0
comment|/* Cfg  to OTP cntl. */
define|#
directive|define
name|PBS_UNIT_OTP_CFG_0_CFG_OTPW_READ_CNT_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_OTP_CFG_0_CFG_OTPW_READ_CNT_SHIFT
value|16
comment|/**** otp_cfg_1 register ****/
comment|/* Cfg  to OTP cntl.  */
define|#
directive|define
name|PBS_UNIT_OTP_CFG_1_CFG_OTPW_PGM_CNT_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_OTP_CFG_1_CFG_OTPW_PGM_CNT_SHIFT
value|0
comment|/* Cfg  to OTP cntl. */
define|#
directive|define
name|PBS_UNIT_OTP_CFG_1_CFG_OTPW_PREP_CNT_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_OTP_CFG_1_CFG_OTPW_PREP_CNT_SHIFT
value|16
comment|/**** otp_cfg_3 register ****/
comment|/* Cfg  to OTP cntl. */
define|#
directive|define
name|PBS_UNIT_OTP_CFG_3_CFG_OTPW_PS18_CNT_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_OTP_CFG_3_CFG_OTPW_PS18_CNT_SHIFT
value|0
comment|/* Cfg  to OTP cntl. */
define|#
directive|define
name|PBS_UNIT_OTP_CFG_3_CFG_OTPW_PWRUP_CNT_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_OTP_CFG_3_CFG_OTPW_PWRUP_CNT_SHIFT
value|16
comment|/**** nb_nic_regs_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_NB_NIC_REGS_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_NB_NIC_REGS_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_NB_NIC_REGS_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_NB_NIC_REGS_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_NB_NIC_REGS_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_NB_NIC_REGS_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** sb_nic_regs_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_SB_NIC_REGS_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_SB_NIC_REGS_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_SB_NIC_REGS_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_SB_NIC_REGS_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* bar low address 16 MSB bits */
define|#
directive|define
name|PBS_UNIT_SB_NIC_REGS_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_SB_NIC_REGS_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** serdes_mux_multi_0 register ****/
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_8_MASK
value|0x00000007
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_8_SHIFT
value|0
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_RSRVD_3
value|(1<< 3)
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_9_MASK
value|0x00000070
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_9_SHIFT
value|4
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_RSRVD_7
value|(1<< 7)
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_10_MASK
value|0x00000700
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_10_SHIFT
value|8
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_RSRVD_11
value|(1<< 11)
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_11_MASK
value|0x00007000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_11_SHIFT
value|12
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_RSRVD_15
value|(1<< 15)
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_12_MASK
value|0x00030000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_12_SHIFT
value|16
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_13_MASK
value|0x000C0000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_13_SHIFT
value|18
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_14_MASK
value|0x00300000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_14_SHIFT
value|20
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_15_MASK
value|0x00C00000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_SELECT_OH_SERDES_15_SHIFT
value|22
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_RSRVD_MASK
value|0xFF000000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_RSRVD_SHIFT
value|24
comment|/*  * 2'b01 - select sata_b[0]  * 2'b10 - select eth_a[0]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_8_MASK
value|0x00000003
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_8_SHIFT
value|0
comment|/*  * 3'b001 - select sata_b[1]  * 3'b010 - select eth_b[0]  * 3'b100 - select eth_a[1]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_9_MASK
value|0x00000070
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_9_SHIFT
value|4
comment|/*  * 3'b001 - select sata_b[2]  * 3'b010 - select eth_c[0]  * 3'b100 - select eth_a[2]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_10_MASK
value|0x00000700
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_10_SHIFT
value|8
comment|/*  * 3'b001 - select sata_b[3]  * 3'b010 - select eth_d[0]  * 3'b100 - select eth_a[3]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_11_MASK
value|0x00007000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_11_SHIFT
value|12
comment|/*  * 2'b01 - select eth_a[0]  * 2'b10 - select sata_a[0]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_12_MASK
value|0x00030000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_12_SHIFT
value|16
comment|/*  * 3'b001 - select eth_b[0]  * 3'b010 - select eth_c[1]  * 3'b100 - select sata_a[1]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_13_MASK
value|0x00700000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_13_SHIFT
value|20
comment|/*  * 3'b001 - select eth_a[0]  * 3'b010 - select eth_c[2]  * 3'b100 - select sata_a[2]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_14_MASK
value|0x07000000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_14_SHIFT
value|24
comment|/*  * 3'b001 - select eth_d[0]  * 3'b010 - select eth_c[3]  * 3'b100 - select sata_a[3]  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_15_MASK
value|0x70000000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_0_PKR_SELECT_OH_SERDES_15_SHIFT
value|28
comment|/**** serdes_mux_multi_1 register ****/
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_SELECT_OH_ETH_A_0_MASK
value|0x00000003
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_SELECT_OH_ETH_A_0_SHIFT
value|0
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_RSRVD_3_2_MASK
value|0x0000000C
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_RSRVD_3_2_SHIFT
value|2
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_SELECT_OH_ETH_B_0_MASK
value|0x00000070
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_SELECT_OH_ETH_B_0_SHIFT
value|4
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_RSRVD_7
value|(1<< 7)
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_SELECT_OH_ETH_C_0_MASK
value|0x00000300
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_SELECT_OH_ETH_C_0_SHIFT
value|8
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_RSRVD_11_10_MASK
value|0x00000C00
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_RSRVD_11_10_SHIFT
value|10
comment|/* SerDes one hot mux control.  For details see datasheet.  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_SELECT_OH_ETH_D_0_MASK
value|0x00007000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_SELECT_OH_ETH_D_0_SHIFT
value|12
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_RSRVD_MASK
value|0xFFFF8000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_MULTI_1_RSRVD_SHIFT
value|15
comment|/**** pbs_ulpi_mux_conf register ****/
comment|/*  * Value 0 - Select dedicated pins for the USB-1 inputs.  * Value 1 - Select PBS mux pins for the USB-1 inputs.  * [0] ULPI_B_CLK  * [1] ULPI_B_DIR  * [2] ULPI_B_NXT  * [10:3] ULPI_B_DATA[7:0]  */
define|#
directive|define
name|PBS_UNIT_PBS_ULPI_MUX_CONF_SEL_UPLI_IN_PBSMUX_MASK
value|0x000007FF
define|#
directive|define
name|PBS_UNIT_PBS_ULPI_MUX_CONF_SEL_UPLI_IN_PBSMUX_SHIFT
value|0
comment|/*  * [3] - Force to zero  * [2] == 1 - Force register selection  * [1 : 0] -Binary selection of the input in bypass mode  */
define|#
directive|define
name|PBS_UNIT_PBS_ULPI_MUX_CONF_REG_MDIO_BYPASS_SEL_MASK
value|0x0000F000
define|#
directive|define
name|PBS_UNIT_PBS_ULPI_MUX_CONF_REG_MDIO_BYPASS_SEL_SHIFT
value|12
comment|/*  * [0] Sets the clk_ulpi OE for USB0, 1'b0 set to input, 1'b1 set to output.  * [1] Sets the clk_ulpi OE for USB01, 1'b0 set to input, 1'b1 set to output.  */
define|#
directive|define
name|PBS_UNIT_PBS_ULPI_MUX_CONF_RSRVD_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PBS_ULPI_MUX_CONF_RSRVD_SHIFT
value|16
comment|/**** wr_once_dbg_dis_ovrd_reg register ****/
comment|/* This register can be written only once. Use in the secure boot process. */
define|#
directive|define
name|PBS_UNIT_WR_ONCE_DBG_DIS_OVRD_REG_WR_ONCE_DBG_DIS_OVRD
value|(1<< 0)
define|#
directive|define
name|PBS_UNIT_WR_ONCE_DBG_DIS_OVRD_REG_RSRVD_MASK
value|0xFFFFFFFE
define|#
directive|define
name|PBS_UNIT_WR_ONCE_DBG_DIS_OVRD_REG_RSRVD_SHIFT
value|1
comment|/**** gpio5_conf_status register ****/
comment|/*  * Cntl: // [7:0] nGPAFEN; // from regfile // [15:8] GPAFOUT; // from regfile  */
define|#
directive|define
name|PBS_UNIT_GPIO5_CONF_STATUS_CONF_MASK
value|0x0000FFFF
define|#
directive|define
name|PBS_UNIT_GPIO5_CONF_STATUS_CONF_SHIFT
value|0
comment|/* Status: //  [24:16] GPAFIN;             // to regfile */
define|#
directive|define
name|PBS_UNIT_GPIO5_CONF_STATUS_STATUS_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_GPIO5_CONF_STATUS_STATUS_SHIFT
value|16
comment|/**** pcie_mem3_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM3_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_MEM3_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM3_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_MEM3_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM3_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_MEM3_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_mem4_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM4_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_MEM4_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM4_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_MEM4_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM4_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_MEM4_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_mem5_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM5_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_MEM5_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM5_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_MEM5_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_PCIE_MEM5_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_MEM5_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_ext_ecam3_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM3_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM3_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM3_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM3_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM3_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM3_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_ext_ecam4_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM4_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM4_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM4_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM4_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM4_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM4_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pcie_ext_ecam5_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM5_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM5_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM5_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM5_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM5_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_PCIE_EXT_ECAM5_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** low_latency_sram_bar_low register ****/
comment|/* Window size = 2 ^ (15 + win_size). Zero value: disable the window. */
define|#
directive|define
name|PBS_UNIT_LOW_LATENCY_SRAM_BAR_LOW_WIN_SIZE_MASK
value|0x0000003F
define|#
directive|define
name|PBS_UNIT_LOW_LATENCY_SRAM_BAR_LOW_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_UNIT_LOW_LATENCY_SRAM_BAR_LOW_RSRVD_MASK
value|0x0000FFC0
define|#
directive|define
name|PBS_UNIT_LOW_LATENCY_SRAM_BAR_LOW_RSRVD_SHIFT
value|6
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_LOW_LATENCY_SRAM_BAR_LOW_ADDR_HIGH_MASK
value|0xFFFF0000
define|#
directive|define
name|PBS_UNIT_LOW_LATENCY_SRAM_BAR_LOW_ADDR_HIGH_SHIFT
value|16
comment|/**** pbs_sb2nb_cfg_dram_remap register ****/
define|#
directive|define
name|PBS_UNIT_SB2NB_REMAP_BASE_ADDR_SHIFT
value|5
define|#
directive|define
name|PBS_UNIT_SB2NB_REMAP_BASE_ADDR_MASK
value|0x0000FFE0
define|#
directive|define
name|PBS_UNIT_SB2NB_REMAP_TRANSL_BASE_ADDR_SHIFT
value|21
define|#
directive|define
name|PBS_UNIT_SB2NB_REMAP_TRANSL_BASE_ADDR_MASK
value|0xFFE00000
comment|/* For remapping are used bits [39 - 29] of DRAM 40bit Physical address */
define|#
directive|define
name|PBS_UNIT_DRAM_SRC_REMAP_BASE_ADDR_SHIFT
value|29
define|#
directive|define
name|PBS_UNIT_DRAM_DST_REMAP_BASE_ADDR_SHIFT
value|29
define|#
directive|define
name|PBS_UNIT_DRAM_REMAP_BASE_ADDR_MASK
value|0xFFE0000000UL
comment|/**** serdes_mux_eth register ****/
comment|/*  * 2'b01 - eth_a[0] from serdes_8  * 2'b10 - eth_a[0] from serdes_14  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_A_0_MASK
value|0x00000003
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_A_0_SHIFT
value|0
comment|/*  * 2'b01 - eth_b[0] from serdes_9  * 2'b10 - eth_b[0] from serdes_13  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_B_0_MASK
value|0x00000030
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_B_0_SHIFT
value|4
comment|/*  * 2'b01 - eth_c[0] from serdes_10  * 2'b10 - eth_c[0] from serdes_12  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_C_0_MASK
value|0x00000300
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_C_0_SHIFT
value|8
comment|/*  * 2'b01 - eth_d[0] from serdes_11  * 2'b10 - eth_d[0] from serdes_15  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_D_0_MASK
value|0x00003000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_D_0_SHIFT
value|12
comment|/* which lane's is master clk */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_A_ICK_MASTER_MASK
value|0x00030000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_A_ICK_MASTER_SHIFT
value|16
comment|/* which lane's is master clk */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_C_ICK_MASTER_MASK
value|0x00300000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_C_ICK_MASTER_SHIFT
value|20
comment|/* enable xlaui on eth a */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_A_XLAUI_ENABLE
value|(1<< 24)
comment|/* enable xlaui on eth c */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_ETH_PKR_SELECT_OH_ETH_C_XLAUI_ENABLE
value|(1<< 28)
comment|/**** serdes_mux_pcie register ****/
comment|/*  * 2'b01 - select pcie_b[0] from serdes 2  * 2'b10 - select pcie_b[0] from serdes 4  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PCIE_PKR_SELECT_OH_PCIE_B_0_MASK
value|0x00000003
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PCIE_PKR_SELECT_OH_PCIE_B_0_SHIFT
value|0
comment|/*  * 2'b01 - select pcie_b[1] from serdes 3  * 2'b10 - select pcie_b[1] from serdes 5  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PCIE_PKR_SELECT_OH_PCIE_B_1_MASK
value|0x00000030
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PCIE_PKR_SELECT_OH_PCIE_B_1_SHIFT
value|4
comment|/*  * 2'b01 - select pcie_d[0] from serdes 10  * 2'b10 - select pcie_d[0] from serdes 12  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PCIE_PKR_SELECT_OH_PCIE_D_0_MASK
value|0x00000300
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PCIE_PKR_SELECT_OH_PCIE_D_0_SHIFT
value|8
comment|/*  * 2'b01 - select pcie_d[1] from serdes 11  * 2'b10 - select pcie_d[1] from serdes 13  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PCIE_PKR_SELECT_OH_PCIE_D_1_MASK
value|0x00003000
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_PCIE_PKR_SELECT_OH_PCIE_D_1_SHIFT
value|12
comment|/**** serdes_mux_sata register ****/
comment|/*  * 2'b01 - select sata_a from serdes group 1  * 2'b10 - select sata_a from serdes group 3  */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_SATA_SELECT_OH_SATA_A_MASK
value|0x00000003
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_SATA_SELECT_OH_SATA_A_SHIFT
value|0
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_SATA_RESERVED_3_2_MASK
value|0x0000000C
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_SATA_RESERVED_3_2_SHIFT
value|2
comment|/* Reserved */
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_SATA_RESERVED_MASK
value|0xFFFFFFF0
define|#
directive|define
name|PBS_UNIT_SERDES_MUX_SATA_RESERVED_SHIFT
value|4
comment|/**** bar1_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar1_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR1_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar2_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar2_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR2_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar3_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar3_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR3_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar4_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar4_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR4_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar5_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar5_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR5_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar6_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar6_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR6_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar7_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar7_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR7_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar8_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar8_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR8_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar9_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar9_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR9_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** bar10_orig register ****/
comment|/*  * Window size = 2 ^ (11 + win_size).  * Zero value: disable the window.  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_ORIG_WIN_SIZE_MASK
value|0x00000007
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_ORIG_WIN_SIZE_SHIFT
value|0
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_ORIG_RSRVD_MASK
value|0x00000FF8
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_ORIG_RSRVD_SHIFT
value|3
comment|/*  * offset within the SRAM, in resolution of 4KB.  * Only offsets which are inside the boundaries of the SRAM bar are allowed  */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_ORIG_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_ORIG_ADDR_HIGH_SHIFT
value|12
comment|/**** bar10_remap register ****/
comment|/* Reserved fields */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_REMAP_RSRVD_MASK
value|0x00000FFF
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_REMAP_RSRVD_SHIFT
value|0
comment|/* remapped address */
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_REMAP_ADDR_HIGH_MASK
value|0xFFFFF000
define|#
directive|define
name|PBS_LOW_LATENCY_SRAM_REMAP_BAR10_REMAP_ADDR_HIGH_SHIFT
value|12
comment|/**** cpu register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_DRAM_SHIFT
value|28
comment|/**** cpu_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CPU_MASK_DRAM_SHIFT
value|28
comment|/**** debug_nb register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_DRAM_SHIFT
value|28
comment|/**** debug_nb_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_NB_MASK_DRAM_SHIFT
value|28
comment|/**** debug_sb register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_DRAM_SHIFT
value|28
comment|/**** debug_sb_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_DEBUG_SB_MASK_DRAM_SHIFT
value|28
comment|/**** eth_0 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_DRAM_SHIFT
value|28
comment|/**** eth_0_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_0_MASK_DRAM_SHIFT
value|28
comment|/**** eth_1 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_DRAM_SHIFT
value|28
comment|/**** eth_1_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_1_MASK_DRAM_SHIFT
value|28
comment|/**** eth_2 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_DRAM_SHIFT
value|28
comment|/**** eth_2_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_2_MASK_DRAM_SHIFT
value|28
comment|/**** eth_3 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_DRAM_SHIFT
value|28
comment|/**** eth_3_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_ETH_3_MASK_DRAM_SHIFT
value|28
comment|/**** sata_0 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_DRAM_SHIFT
value|28
comment|/**** sata_0_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_0_MASK_DRAM_SHIFT
value|28
comment|/**** sata_1 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_DRAM_SHIFT
value|28
comment|/**** sata_1_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_SATA_1_MASK_DRAM_SHIFT
value|28
comment|/**** crypto_0 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_DRAM_SHIFT
value|28
comment|/**** crypto_0_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_0_MASK_DRAM_SHIFT
value|28
comment|/**** crypto_1 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_DRAM_SHIFT
value|28
comment|/**** crypto_1_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_CRYPTO_1_MASK_DRAM_SHIFT
value|28
comment|/**** pcie_0 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_DRAM_SHIFT
value|28
comment|/**** pcie_0_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_0_MASK_DRAM_SHIFT
value|28
comment|/**** pcie_1 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_DRAM_SHIFT
value|28
comment|/**** pcie_1_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_1_MASK_DRAM_SHIFT
value|28
comment|/**** pcie_2 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_DRAM_SHIFT
value|28
comment|/**** pcie_2_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_2_MASK_DRAM_SHIFT
value|28
comment|/**** pcie_3 register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_DRAM_SHIFT
value|28
comment|/**** pcie_3_mask register ****/
comment|/* map transactions according to address decoding */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_NO_ENFORCEMENT_MASK
value|0x0000000F
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_NO_ENFORCEMENT_SHIFT
value|0
comment|/* map transactions to pcie_0 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_0_MASK
value|0x000000F0
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_0_SHIFT
value|4
comment|/* map transactions to pcie_1 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_1_MASK
value|0x00000F00
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_1_SHIFT
value|8
comment|/* map transactions to pcie_2 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_2_MASK
value|0x0000F000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_2_SHIFT
value|12
comment|/* map transactions to pcie_3 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_3_MASK
value|0x000F0000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_3_SHIFT
value|16
comment|/* map transactions to pcie_4 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_4_MASK
value|0x00F00000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_4_SHIFT
value|20
comment|/* map transactions to pcie_5 */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_5_MASK
value|0x0F000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_PCIE_5_SHIFT
value|24
comment|/* map transactions to dram */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_DRAM_MASK
value|0xF0000000
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_PCIE_3_MASK_DRAM_SHIFT
value|28
comment|/**** latch register ****/
comment|/*  * Software clears this bit before any bar update, and set it after all bars  * updated.  */
define|#
directive|define
name|PBS_TARGET_ID_ENFORCEMENT_LATCH_ENABLE
value|(1<< 0)
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
comment|/* __AL_HAL_PBS_REGS_H__ */
end_comment

begin_comment
comment|/** @} end of ... group */
end_comment

end_unit

