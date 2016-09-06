begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @file   al_hal_udma_regs_m2s.h  *  * @brief C Header file for the UDMA M2S registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_UDMA_M2S_REG_H
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_UDMA_M2S_REG_H
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
name|udma_axi_m2s
block|{
comment|/* [0x0] Completion write master configuration */
name|uint32_t
name|comp_wr_cfg_1
decl_stmt|;
comment|/* [0x4] Completion write master configuration */
name|uint32_t
name|comp_wr_cfg_2
decl_stmt|;
comment|/* [0x8] Data read master configuration */
name|uint32_t
name|data_rd_cfg_1
decl_stmt|;
comment|/* [0xc] Data read master configuration */
name|uint32_t
name|data_rd_cfg_2
decl_stmt|;
comment|/* [0x10] Descriptor read master configuration */
name|uint32_t
name|desc_rd_cfg_1
decl_stmt|;
comment|/* [0x14] Descriptor read master configuration */
name|uint32_t
name|desc_rd_cfg_2
decl_stmt|;
comment|/* [0x18] Data read master configuration */
name|uint32_t
name|data_rd_cfg
decl_stmt|;
comment|/* [0x1c] Descriptors read master configuration */
name|uint32_t
name|desc_rd_cfg_3
decl_stmt|;
comment|/* [0x20] Descriptors write master configuration (completion) */
name|uint32_t
name|desc_wr_cfg_1
decl_stmt|;
comment|/* [0x24] AXI outstanding  configuration */
name|uint32_t
name|ostand_cfg
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|54
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_m2s
block|{
comment|/* 	 * [0x0] DMA state. 	 * 00  - No pending tasks 	 * 01 â Normal (active) 	 * 10 â Abort (error condition) 	 * 11 â Reserved 	 */
name|uint32_t
name|state
decl_stmt|;
comment|/* [0x4] CPU request to change DMA state */
name|uint32_t
name|change_state
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* 	 * [0xc] M2S DMA error log mask. 	 * Each error has an interrupt controller cause bit. 	 * This register determines if these errors cause the M2S DMA to log the 	 * error condition. 	 * 0 - Log is enabled. 	 * 1 - Log is masked. 	 */
name|uint32_t
name|err_log_mask
decl_stmt|;
name|uint32_t
name|rsrvd_1
decl_stmt|;
comment|/* 	 * [0x14] DMA header log. 	 * Sample the packet header that caused the error. 	 */
name|uint32_t
name|log_0
decl_stmt|;
comment|/* 	 * [0x18] DMA header log. 	 * Sample the packet header that caused the error. 	 */
name|uint32_t
name|log_1
decl_stmt|;
comment|/* 	 * [0x1c] DMA header log. 	 * Sample the packet header that caused the error. 	 */
name|uint32_t
name|log_2
decl_stmt|;
comment|/* 	 * [0x20] DMA header log. 	 * Sample the packet header that caused the error. 	 */
name|uint32_t
name|log_3
decl_stmt|;
comment|/* [0x24] DMA clear error log */
name|uint32_t
name|clear_err_log
decl_stmt|;
comment|/* [0x28] M2S data FIFO status */
name|uint32_t
name|data_fifo_status
decl_stmt|;
comment|/* [0x2c] M2S header FIFO status */
name|uint32_t
name|header_fifo_status
decl_stmt|;
comment|/* [0x30] M2S unack FIFO status */
name|uint32_t
name|unack_fifo_status
decl_stmt|;
comment|/* [0x34] Select queue for debug */
name|uint32_t
name|indirect_ctrl
decl_stmt|;
comment|/* 	 * [0x38] M2S prefetch FIFO status. 	 * Status of the selected queue in M2S_indirect_ctrl 	 */
name|uint32_t
name|sel_pref_fifo_status
decl_stmt|;
comment|/* 	 * [0x3c] M2S completion FIFO status. 	 * Status of the selected queue in M2S_indirect_ctrl 	 */
name|uint32_t
name|sel_comp_fifo_status
decl_stmt|;
comment|/* 	 * [0x40] M2S rate limit status. 	 * Status of the selected queue in M2S_indirect_ctrl 	 */
name|uint32_t
name|sel_rate_limit_status
decl_stmt|;
comment|/* 	 * [0x44] M2S DWRR scheduler status. 	 * Status of the selected queue in M2S_indirect_ctrl 	 */
name|uint32_t
name|sel_dwrr_status
decl_stmt|;
comment|/* [0x48] M2S state machine and FIFO clear control */
name|uint32_t
name|clear_ctrl
decl_stmt|;
comment|/* [0x4c] Misc Check enable */
name|uint32_t
name|check_en
decl_stmt|;
comment|/* [0x50] M2S FIFO enable control, internal */
name|uint32_t
name|fifo_en
decl_stmt|;
comment|/* [0x54] M2S packet length configuration */
name|uint32_t
name|cfg_len
decl_stmt|;
comment|/* [0x58] Stream interface configuration */
name|uint32_t
name|stream_cfg
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|41
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_m2s_rd
block|{
comment|/* [0x0] M2S descriptor prefetch configuration */
name|uint32_t
name|desc_pref_cfg_1
decl_stmt|;
comment|/* [0x4] M2S descriptor prefetch configuration */
name|uint32_t
name|desc_pref_cfg_2
decl_stmt|;
comment|/* [0x8] M2S descriptor prefetch configuration */
name|uint32_t
name|desc_pref_cfg_3
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x10] Data burst read configuration */
name|uint32_t
name|data_cfg
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
name|udma_m2s_dwrr
block|{
comment|/* [0x0] Tx DMA DWRR scheduler configuration */
name|uint32_t
name|cfg_sched
decl_stmt|;
comment|/* [0x4] Token bucket rate limit control */
name|uint32_t
name|ctrl_deficit_cnt
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_m2s_rate_limiter
block|{
comment|/* [0x0] Token bucket rate limit configuration */
name|uint32_t
name|gen_cfg
decl_stmt|;
comment|/* 	 * [0x4] Token bucket rate limit control. 	 * Controls the cycle counters. 	 */
name|uint32_t
name|ctrl_cycle_cnt
decl_stmt|;
comment|/* 	 * [0x8] Token bucket rate limit control. 	 * Controls the token bucket counter. 	 */
name|uint32_t
name|ctrl_token
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|13
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_rlimit_common
block|{
comment|/* [0x0] Token bucket configuration */
name|uint32_t
name|cfg_1s
decl_stmt|;
comment|/* [0x4] Token bucket rate limit configuration */
name|uint32_t
name|cfg_cycle
decl_stmt|;
comment|/* [0x8] Token bucket rate limit configuration */
name|uint32_t
name|cfg_token_size_1
decl_stmt|;
comment|/* [0xc] Token bucket rate limit configuration */
name|uint32_t
name|cfg_token_size_2
decl_stmt|;
comment|/* [0x10] Token bucket rate limit configuration */
name|uint32_t
name|sw_ctrl
decl_stmt|;
comment|/* 	 * [0x14] Mask the different types of rate limiter. 	 * 0 - Rate limit is active. 	 * 1 - Rate limit is masked. 	 */
name|uint32_t
name|mask
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_m2s_stream_rate_limiter
block|{
name|struct
name|udma_rlimit_common
name|rlimit
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_m2s_comp
block|{
comment|/* [0x0] Completion controller configuration */
name|uint32_t
name|cfg_1c
decl_stmt|;
comment|/* [0x4] Completion controller coalescing configuration */
name|uint32_t
name|cfg_coal
decl_stmt|;
comment|/* [0x8] Completion controller application acknowledge configuration */
name|uint32_t
name|cfg_application_ack
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
name|udma_m2s_stat
block|{
comment|/* [0x0] Statistics counters configuration */
name|uint32_t
name|cfg_st
decl_stmt|;
comment|/* [0x4] Counting number of descriptors with First-bit set. */
name|uint32_t
name|tx_pkt
decl_stmt|;
comment|/* 	 * [0x8] Counting the net length of the data buffers [64-bit] 	 * Should be read before tx_bytes_high 	 */
name|uint32_t
name|tx_bytes_low
decl_stmt|;
comment|/* 	 * [0xc] Counting the net length of the data buffers [64-bit], 	 * Should be read after tx_bytes_low (value is sampled when reading 	 * Should be read before tx_bytes_low 	 */
name|uint32_t
name|tx_bytes_high
decl_stmt|;
comment|/* [0x10] Total number of descriptors read from the host memory */
name|uint32_t
name|prefed_desc
decl_stmt|;
comment|/* [0x14] Number of packets read from the unack FIFO */
name|uint32_t
name|comp_pkt
decl_stmt|;
comment|/* [0x18] Number of descriptors written into the completion ring */
name|uint32_t
name|comp_desc
decl_stmt|;
comment|/* 	 * [0x1c] Number of acknowledged packets. 	 * (acknowledge received from the stream interface) 	 */
name|uint32_t
name|ack_pkts
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|56
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_m2s_feature
block|{
comment|/* 	 * [0x0] M2S Feature register. 	 * M2S instantiation parameters 	 */
name|uint32_t
name|reg_1
decl_stmt|;
comment|/* [0x4] Reserved M2S feature register */
name|uint32_t
name|reg_2
decl_stmt|;
comment|/* 	 * [0x8] M2S Feature register. 	 * M2S instantiation parameters 	 */
name|uint32_t
name|reg_3
decl_stmt|;
comment|/* 	 * [0xc] M2S Feature register. 	 * M2S instantiation parameters 	 */
name|uint32_t
name|reg_4
decl_stmt|;
comment|/* 	 * [0x10] M2S Feature register. 	 * M2S instantiation parameters 	 */
name|uint32_t
name|reg_5
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|59
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_m2s_q
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|8
index|]
decl_stmt|;
comment|/* [0x20] M2S descriptor ring configuration */
name|uint32_t
name|cfg
decl_stmt|;
comment|/* [0x24] M2S descriptor ring status and information */
name|uint32_t
name|status
decl_stmt|;
comment|/* [0x28] TX Descriptor Ring Base Pointer [31:4] */
name|uint32_t
name|tdrbp_low
decl_stmt|;
comment|/* [0x2c] TX Descriptor Ring Base Pointer [63:32] */
name|uint32_t
name|tdrbp_high
decl_stmt|;
comment|/* 	 * [0x30] TX Descriptor Ring Length[23:2] 	 */
name|uint32_t
name|tdrl
decl_stmt|;
comment|/* [0x34] TX Descriptor Ring Head Pointer */
name|uint32_t
name|tdrhp
decl_stmt|;
comment|/* [0x38] Tx Descriptor Tail Pointer increment */
name|uint32_t
name|tdrtp_inc
decl_stmt|;
comment|/* [0x3c] Tx Descriptor Tail Pointer */
name|uint32_t
name|tdrtp
decl_stmt|;
comment|/* [0x40] TX Descriptor Current Pointer */
name|uint32_t
name|tdcp
decl_stmt|;
comment|/* [0x44] Tx Completion Ring Base Pointer [31:4] */
name|uint32_t
name|tcrbp_low
decl_stmt|;
comment|/* [0x48] TX Completion Ring Base Pointer [63:32] */
name|uint32_t
name|tcrbp_high
decl_stmt|;
comment|/* [0x4c] TX Completion Ring Head Pointer */
name|uint32_t
name|tcrhp
decl_stmt|;
comment|/* 	 * [0x50] Tx Completion Ring Head Pointer internal (Before the 	 * coalescing FIFO) 	 */
name|uint32_t
name|tcrhp_internal
decl_stmt|;
name|uint32_t
name|rsrvd_1
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x60] Rate limit configuration */
name|struct
name|udma_rlimit_common
name|rlimit
decl_stmt|;
name|uint32_t
name|rsrvd_2
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x80] DWRR scheduler configuration */
name|uint32_t
name|dwrr_cfg_1
decl_stmt|;
comment|/* [0x84] DWRR scheduler configuration */
name|uint32_t
name|dwrr_cfg_2
decl_stmt|;
comment|/* [0x88] DWRR scheduler configuration */
name|uint32_t
name|dwrr_cfg_3
decl_stmt|;
comment|/* [0x8c] DWRR scheduler software control */
name|uint32_t
name|dwrr_sw_ctrl
decl_stmt|;
name|uint32_t
name|rsrvd_3
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0xa0] Completion controller configuration */
name|uint32_t
name|comp_cfg
decl_stmt|;
name|uint32_t
name|rsrvd_4
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0xb0] SW control  */
name|uint32_t
name|q_sw_ctrl
decl_stmt|;
name|uint32_t
name|rsrvd_5
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0xc0] Number of M2S Tx packets after the scheduler */
name|uint32_t
name|q_tx_pkt
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|975
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_m2s_regs
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|udma_axi_m2s
name|axi_m2s
decl_stmt|;
comment|/* [0x100] */
name|struct
name|udma_m2s
name|m2s
decl_stmt|;
comment|/* [0x200] */
name|struct
name|udma_m2s_rd
name|m2s_rd
decl_stmt|;
comment|/* [0x300] */
name|struct
name|udma_m2s_dwrr
name|m2s_dwrr
decl_stmt|;
comment|/* [0x340] */
name|struct
name|udma_m2s_rate_limiter
name|m2s_rate_limiter
decl_stmt|;
comment|/* [0x380] */
name|struct
name|udma_m2s_stream_rate_limiter
name|m2s_stream_rate_limiter
decl_stmt|;
comment|/* [0x3c0] */
name|struct
name|udma_m2s_comp
name|m2s_comp
decl_stmt|;
comment|/* [0x400] */
name|struct
name|udma_m2s_stat
name|m2s_stat
decl_stmt|;
comment|/* [0x500] */
name|struct
name|udma_m2s_feature
name|m2s_feature
decl_stmt|;
comment|/* [0x600] */
name|uint32_t
name|rsrvd_1
index|[
literal|576
index|]
decl_stmt|;
name|struct
name|udma_m2s_q
name|m2s_q
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x1000] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** comp_wr_cfg_1 register ****/
comment|/* AXI write  ID (AWID) */
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_1_AWID_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_1_AWID_SHIFT
value|0
comment|/* Cache Type */
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_1_AWCACHE_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_1_AWCACHE_SHIFT
value|16
comment|/* Burst type */
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_1_AWBURST_MASK
value|0x03000000
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_1_AWBURST_SHIFT
value|24
comment|/**** comp_wr_cfg_2 register ****/
comment|/* User extension */
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_2_AWUSER_MASK
value|0x000FFFFF
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_2_AWUSER_SHIFT
value|0
comment|/* Bus size, 128-bit */
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_2_AWSIZE_MASK
value|0x00700000
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_2_AWSIZE_SHIFT
value|20
comment|/*  * AXI Master QoS.  * Used for arbitration between AXI masters  */
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_2_AWQOS_MASK
value|0x07000000
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_2_AWQOS_SHIFT
value|24
comment|/* Protection Type */
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_2_AWPROT_MASK
value|0x70000000
define|#
directive|define
name|UDMA_AXI_M2S_COMP_WR_CFG_2_AWPROT_SHIFT
value|28
comment|/**** data_rd_cfg_1 register ****/
comment|/* AXI read  ID (ARID) */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_1_ARID_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_1_ARID_SHIFT
value|0
comment|/* Cache Type */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_1_ARCACHE_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_1_ARCACHE_SHIFT
value|16
comment|/* Burst type */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_1_ARBURST_MASK
value|0x03000000
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_1_ARBURST_SHIFT
value|24
comment|/**** data_rd_cfg_2 register ****/
comment|/* User extension */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_2_ARUSER_MASK
value|0x000FFFFF
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_2_ARUSER_SHIFT
value|0
comment|/* Bus size, 128-bit */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_2_ARSIZE_MASK
value|0x00700000
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_2_ARSIZE_SHIFT
value|20
comment|/*  * AXI Master QoS.  * Used for arbitration between AXI masters  */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_2_ARQOS_MASK
value|0x07000000
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_2_ARQOS_SHIFT
value|24
comment|/* Protection Type */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_2_ARPROT_MASK
value|0x70000000
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_2_ARPROT_SHIFT
value|28
comment|/**** desc_rd_cfg_1 register ****/
comment|/* AXI read  ID (ARID) */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_1_ARID_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_1_ARID_SHIFT
value|0
comment|/* Cache Type */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_1_ARCACHE_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_1_ARCACHE_SHIFT
value|16
comment|/* Burst type */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_1_ARBURST_MASK
value|0x03000000
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_1_ARBURST_SHIFT
value|24
comment|/**** desc_rd_cfg_2 register ****/
comment|/* User extension */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_2_ARUSER_MASK
value|0x000FFFFF
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_2_ARUSER_SHIFT
value|0
comment|/* Bus size, 128-bit */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_2_ARSIZE_MASK
value|0x00700000
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_2_ARSIZE_SHIFT
value|20
comment|/*  * AXI Master QoS  * Used for arbitration between AXI masters  */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_2_ARQOS_MASK
value|0x07000000
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_2_ARQOS_SHIFT
value|24
comment|/* Protection Type */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_2_ARPROT_MASK
value|0x70000000
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_2_ARPROT_SHIFT
value|28
comment|/**** data_rd_cfg register ****/
comment|/*  * Defines the maximum number of AXI beats for a single AXI burst.  * This value is used for a burst split decision.  */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_MAX_AXI_BEATS_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_MAX_AXI_BEATS_SHIFT
value|0
comment|/*  * Enable breaking data read request.  * Aligned to max_AXI_beats when the total read size is less than max_AXI_beats  */
define|#
directive|define
name|UDMA_AXI_M2S_DATA_RD_CFG_ALWAYS_BREAK_ON_MAX_BOUDRY
value|(1<< 16)
comment|/**** desc_rd_cfg_3 register ****/
comment|/*  * Defines the maximum number of AXI beats for a single AXI burst.  * This value is used for a burst split decision.  * Maximum burst size for reading data( in AXI beats, 128-bits)  * (default â 16 beats, 256 bytes)  */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_3_MAX_AXI_BEATS_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_3_MAX_AXI_BEATS_SHIFT
value|0
comment|/*  * Enable breaking descriptor read request.  * Aligned to max_AXI_beats when the total read size is less than max_AXI_beats.  */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_RD_CFG_3_ALWAYS_BREAK_ON_MAX_BOUDRY
value|(1<< 16)
comment|/**** desc_wr_cfg_1 register ****/
comment|/*  * Defines the maximum number of AXI beats for a single AXI burst.  * This value is used for a burst split decision.  */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_WR_CFG_1_MAX_AXI_BEATS_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_M2S_DESC_WR_CFG_1_MAX_AXI_BEATS_SHIFT
value|0
comment|/*  * Minimum burst for writing completion descriptors.  * Defined in AXI beats  * 4 Descriptors per beat.  * Value must be aligned to cache lines (64 bytes).  * Default value is 2 cache lines, 32 descriptors, 8 beats.  */
define|#
directive|define
name|UDMA_AXI_M2S_DESC_WR_CFG_1_MIN_AXI_BEATS_MASK
value|0x00FF0000
define|#
directive|define
name|UDMA_AXI_M2S_DESC_WR_CFG_1_MIN_AXI_BEATS_SHIFT
value|16
comment|/**** ostand_cfg register ****/
comment|/* Maximum number of outstanding data reads to the AXI (AXI transactions) */
define|#
directive|define
name|UDMA_AXI_M2S_OSTAND_CFG_MAX_DATA_RD_MASK
value|0x0000003F
define|#
directive|define
name|UDMA_AXI_M2S_OSTAND_CFG_MAX_DATA_RD_SHIFT
value|0
comment|/*  * Maximum number of outstanding descriptor reads to the AXI (AXI transactions)  */
define|#
directive|define
name|UDMA_AXI_M2S_OSTAND_CFG_MAX_DESC_RD_MASK
value|0x00003F00
define|#
directive|define
name|UDMA_AXI_M2S_OSTAND_CFG_MAX_DESC_RD_SHIFT
value|8
comment|/*  * Maximum number of outstanding descriptor writes to the AXI (AXI transactions)  */
define|#
directive|define
name|UDMA_AXI_M2S_OSTAND_CFG_MAX_COMP_REQ_MASK
value|0x003F0000
define|#
directive|define
name|UDMA_AXI_M2S_OSTAND_CFG_MAX_COMP_REQ_SHIFT
value|16
comment|/*  * Maximum number of outstanding data beats for descriptor write to AXI (AXI  * beats)  */
define|#
directive|define
name|UDMA_AXI_M2S_OSTAND_CFG_MAX_COMP_DATA_WR_MASK
value|0xFF000000
define|#
directive|define
name|UDMA_AXI_M2S_OSTAND_CFG_MAX_COMP_DATA_WR_SHIFT
value|24
comment|/**** state register ****/
comment|/* Completion control */
define|#
directive|define
name|UDMA_M2S_STATE_COMP_CTRL_MASK
value|0x00000003
define|#
directive|define
name|UDMA_M2S_STATE_COMP_CTRL_SHIFT
value|0
comment|/* Stream interface */
define|#
directive|define
name|UDMA_M2S_STATE_STREAM_IF_MASK
value|0x00000030
define|#
directive|define
name|UDMA_M2S_STATE_STREAM_IF_SHIFT
value|4
comment|/* Data read control */
define|#
directive|define
name|UDMA_M2S_STATE_DATA_RD_CTRL_MASK
value|0x00000300
define|#
directive|define
name|UDMA_M2S_STATE_DATA_RD_CTRL_SHIFT
value|8
comment|/* Descriptor prefetch */
define|#
directive|define
name|UDMA_M2S_STATE_DESC_PREF_MASK
value|0x00003000
define|#
directive|define
name|UDMA_M2S_STATE_DESC_PREF_SHIFT
value|12
comment|/**** change_state register ****/
comment|/* Start normal operation */
define|#
directive|define
name|UDMA_M2S_CHANGE_STATE_NORMAL
value|(1<< 0)
comment|/* Stop normal operation */
define|#
directive|define
name|UDMA_M2S_CHANGE_STATE_DIS
value|(1<< 1)
comment|/*  * Stop all machines.  * (Prefetch, scheduling, completion and stream interface)  */
define|#
directive|define
name|UDMA_M2S_CHANGE_STATE_ABORT
value|(1<< 2)
comment|/**** err_log_mask register ****/
comment|/*  * Mismatch of packet serial number.  * (between first packet in the unacknowledged FIFO and received ack from the  * stream)  */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_COMP_PKT_MISMATCH
value|(1<< 0)
comment|/* Parity error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_STREAM_AXI_PARITY
value|(1<< 1)
comment|/* AXI response error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_STREAM_AXI_RESPONSE
value|(1<< 2)
comment|/* AXI timeout (ack not received) */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_STREAM_AXI_TOUT
value|(1<< 3)
comment|/* Parity error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_COMP_AXI_PARITY
value|(1<< 4)
comment|/* AXI response error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_COMP_AXI_RESPONSE
value|(1<< 5)
comment|/* AXI timeout */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_COMP_AXI_TOUT
value|(1<< 6)
comment|/* Parity error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_DATA_AXI_PARITY
value|(1<< 7)
comment|/* AXI response error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_DATA_AXI_RESPONSE
value|(1<< 8)
comment|/* AXI timeout */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_DATA_AXI_TOUT
value|(1<< 9)
comment|/* Parity error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_PREF_AXI_PARITY
value|(1<< 10)
comment|/* AXI response error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_PREF_AXI_RESPONSE
value|(1<< 11)
comment|/* AXI timeout */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_PREF_AXI_TOUT
value|(1<< 12)
comment|/* Packet length error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_PREF_PKT_LEN_OVERFLOW
value|(1<< 13)
comment|/* Maximum number of descriptors per packet error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_PREF_MAX_DESC_CNT
value|(1<< 14)
comment|/* Error in first bit indication of the descriptor */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_PREF_FIRST
value|(1<< 15)
comment|/* Error in last bit indication of the descriptor */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_PREF_LAST
value|(1<< 16)
comment|/* Ring_ID error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_PREF_RING_ID
value|(1<< 17)
comment|/* Data buffer parity error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_DATA_BUFF_PARITY
value|(1<< 18)
comment|/* Internal error */
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_INTERNAL_MASK
value|0xFFF80000
define|#
directive|define
name|UDMA_M2S_ERR_LOG_MASK_INTERNAL_SHIFT
value|19
comment|/**** clear_err_log register ****/
comment|/* Clear error log */
define|#
directive|define
name|UDMA_M2S_CLEAR_ERR_LOG_CLEAR
value|(1<< 0)
comment|/**** data_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_M2S_DATA_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_DATA_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_M2S_DATA_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_M2S_DATA_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** header_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_M2S_HEADER_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_HEADER_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_M2S_HEADER_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_M2S_HEADER_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** unack_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_M2S_UNACK_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_UNACK_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_M2S_UNACK_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_M2S_UNACK_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** indirect_ctrl register ****/
comment|/* Selected queue for status read */
define|#
directive|define
name|UDMA_M2S_INDIRECT_CTRL_Q_NUM_MASK
value|0x00000FFF
define|#
directive|define
name|UDMA_M2S_INDIRECT_CTRL_Q_NUM_SHIFT
value|0
comment|/**** sel_pref_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_M2S_SEL_PREF_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_SEL_PREF_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_M2S_SEL_PREF_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_M2S_SEL_PREF_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** sel_comp_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_M2S_SEL_COMP_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_SEL_COMP_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_M2S_SEL_COMP_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_M2S_SEL_COMP_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** sel_rate_limit_status register ****/
comment|/* Token counter */
define|#
directive|define
name|UDMA_M2S_SEL_RATE_LIMIT_STATUS_TOKEN_CNT_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_SEL_RATE_LIMIT_STATUS_TOKEN_CNT_SHIFT
value|0
comment|/**** sel_dwrr_status register ****/
comment|/* Deficit counter */
define|#
directive|define
name|UDMA_M2S_SEL_DWRR_STATUS_DEFICIT_CNT_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_SEL_DWRR_STATUS_DEFICIT_CNT_SHIFT
value|0
comment|/**** cfg_len register ****/
comment|/* Maximum packet size for the M2S */
define|#
directive|define
name|UDMA_M2S_CFG_LEN_MAX_PKT_SIZE_MASK
value|0x000FFFFF
define|#
directive|define
name|UDMA_M2S_CFG_LEN_MAX_PKT_SIZE_SHIFT
value|0
comment|/*  * Length encoding for 64K.  * 0 - length 0x0000 = 0  * 1 - length 0x0000 = 64k  */
define|#
directive|define
name|UDMA_M2S_CFG_LEN_ENCODE_64K
value|(1<< 24)
comment|/**** stream_cfg register ****/
comment|/*  * Disables the stream interface operation.  * Changing to 1 stops at the end of packet transmission.  */
define|#
directive|define
name|UDMA_M2S_STREAM_CFG_DISABLE
value|(1<< 0)
comment|/*  * Configuration of the stream FIFO read control.  * 0 - Cut through  * 1 - Threshold based  */
define|#
directive|define
name|UDMA_M2S_STREAM_CFG_RD_MODE
value|(1<< 1)
comment|/* Minimum number of beats to start packet transmission. */
define|#
directive|define
name|UDMA_M2S_STREAM_CFG_RD_TH_MASK
value|0x0003FF00
define|#
directive|define
name|UDMA_M2S_STREAM_CFG_RD_TH_SHIFT
value|8
comment|/**** desc_pref_cfg_1 register ****/
comment|/* Size of the descriptor prefetch FIFO (in descriptors) */
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_1_FIFO_DEPTH_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_1_FIFO_DEPTH_SHIFT
value|0
comment|/**** desc_pref_cfg_2 register ****/
comment|/* Maximum number of descriptors per packet */
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_2_MAX_DESC_PER_PKT_MASK
value|0x0000001F
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_2_MAX_DESC_PER_PKT_SHIFT
value|0
comment|/*  * Force RR arbitration in the prefetch arbiter.  * 0 -Standard arbitration based on queue QoS  * 1 - Force Round Robin arbitration  */
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_2_PREF_FORCE_RR
value|(1<< 16)
comment|/**** desc_pref_cfg_3 register ****/
comment|/*  * Minimum descriptor burst size when prefetch FIFO level is below the  * descriptor prefetch threshold  * (must be 1)  */
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_3_MIN_BURST_BELOW_THR_MASK
value|0x0000000F
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_3_MIN_BURST_BELOW_THR_SHIFT
value|0
comment|/*  * Minimum descriptor burst size when prefetch FIFO level is above the  * descriptor prefetch threshold  */
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_3_MIN_BURST_ABOVE_THR_MASK
value|0x000000F0
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_3_MIN_BURST_ABOVE_THR_SHIFT
value|4
comment|/*  * Descriptor fetch threshold.  * Used as a threshold to determine the allowed minimum descriptor burst size.  * (Must be at least max_desc_per_pkt)  */
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_3_PREF_THR_MASK
value|0x0000FF00
define|#
directive|define
name|UDMA_M2S_RD_DESC_PREF_CFG_3_PREF_THR_SHIFT
value|8
comment|/**** data_cfg register ****/
comment|/*  * Maximum number of data beats in the data read FIFO.  * Defined based on data FIFO size  * (default FIFO size 2KB â 128 beats)  */
define|#
directive|define
name|UDMA_M2S_RD_DATA_CFG_DATA_FIFO_DEPTH_MASK
value|0x000003FF
define|#
directive|define
name|UDMA_M2S_RD_DATA_CFG_DATA_FIFO_DEPTH_SHIFT
value|0
comment|/*  * Maximum number of packets in the data read FIFO.  * Defined based on header FIFO size  */
define|#
directive|define
name|UDMA_M2S_RD_DATA_CFG_MAX_PKT_LIMIT_MASK
value|0x00FF0000
define|#
directive|define
name|UDMA_M2S_RD_DATA_CFG_MAX_PKT_LIMIT_SHIFT
value|16
comment|/**** cfg_sched register ****/
comment|/*  * Enable the DWRR scheduler.  * If this bit is 0, queues with same QoS will be served with RR scheduler.  */
define|#
directive|define
name|UDMA_M2S_DWRR_CFG_SCHED_EN_DWRR
value|(1<< 0)
comment|/*  * Scheduler operation mode.  * 0 - Byte mode  * 1 - Packet mode  */
define|#
directive|define
name|UDMA_M2S_DWRR_CFG_SCHED_PKT_MODE_EN
value|(1<< 4)
comment|/*  * Enable incrementing the weight factor between DWRR iterations.  * 00 - Don't increase the increment factor.  * 01 - Increment once  * 10 - Increment exponential  * 11 - Reserved  */
define|#
directive|define
name|UDMA_M2S_DWRR_CFG_SCHED_WEIGHT_INC_MASK
value|0x00000300
define|#
directive|define
name|UDMA_M2S_DWRR_CFG_SCHED_WEIGHT_INC_SHIFT
value|8
comment|/*  * Increment factor power of 2.  * 7 --> 128 bytes  * This is the factor used to multiply the weight.  */
define|#
directive|define
name|UDMA_M2S_DWRR_CFG_SCHED_INC_FACTOR_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_M2S_DWRR_CFG_SCHED_INC_FACTOR_SHIFT
value|16
comment|/**** ctrl_deficit_cnt register ****/
comment|/*  * Init value for the deficit counter.  * Initializes the deficit counters of all queues to this value any time this  * register is written.  */
define|#
directive|define
name|UDMA_M2S_DWRR_CTRL_DEFICIT_CNT_INIT_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_DWRR_CTRL_DEFICIT_CNT_INIT_SHIFT
value|0
comment|/**** gen_cfg register ****/
comment|/* Size of the basic token fill cycle, system clock cycles */
define|#
directive|define
name|UDMA_M2S_RATE_LIMITER_GEN_CFG_SHORT_CYCLE_SIZE_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_RATE_LIMITER_GEN_CFG_SHORT_CYCLE_SIZE_SHIFT
value|0
comment|/*  * Rate limiter operation mode.  * 0 - Byte mode  * 1 - Packet mode  */
define|#
directive|define
name|UDMA_M2S_RATE_LIMITER_GEN_CFG_PKT_MODE_EN
value|(1<< 24)
comment|/**** ctrl_cycle_cnt register ****/
comment|/* Reset the short and long cycle counters. */
define|#
directive|define
name|UDMA_M2S_RATE_LIMITER_CTRL_CYCLE_CNT_RST
value|(1<< 0)
comment|/**** ctrl_token register ****/
comment|/*  * Init value for the token counter.  * Initializes the token counters of all queues to this value any time this  * register is written.  */
define|#
directive|define
name|UDMA_M2S_RATE_LIMITER_CTRL_TOKEN_RST_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_RATE_LIMITER_CTRL_TOKEN_RST_SHIFT
value|0
comment|/**** cfg_1s register ****/
comment|/* Maximum number of accumulated bytes in the token counter */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_1S_MAX_BURST_SIZE_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_1S_MAX_BURST_SIZE_SHIFT
value|0
comment|/* Enable the rate limiter. */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_1S_EN
value|(1<< 24)
comment|/* Stop token fill. */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_1S_PAUSE
value|(1<< 25)
comment|/**** cfg_cycle register ****/
comment|/* Number of short cycles between token fills */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_CYCLE_LONG_CYCLE_SIZE_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_CYCLE_LONG_CYCLE_SIZE_SHIFT
value|0
comment|/**** cfg_token_size_1 register ****/
comment|/* Number of bits to add in each long cycle */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_TOKEN_SIZE_1_LONG_CYCLE_MASK
value|0x0007FFFF
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_TOKEN_SIZE_1_LONG_CYCLE_SHIFT
value|0
comment|/**** cfg_token_size_2 register ****/
comment|/* Number of bits to add in each short cycle */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_TOKEN_SIZE_2_SHORT_CYCLE_MASK
value|0x0007FFFF
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_CFG_TOKEN_SIZE_2_SHORT_CYCLE_SHIFT
value|0
comment|/**** sw_ctrl register ****/
comment|/* Reset the token bucket counter. */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_SW_CTRL_RST_TOKEN_CNT
value|(1<< 0)
comment|/**** mask register ****/
comment|/* Mask the external rate limiter. */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_MASK_EXTERNAL_RATE_LIMITER
value|(1<< 0)
comment|/* Mask the internal rate limiter. */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_MASK_INTERNAL_RATE_LIMITER
value|(1<< 1)
comment|/* Mask the external application pause interface. */
define|#
directive|define
name|UDMA_M2S_STREAM_RATE_LIMITER_MASK_EXTERNAL_PAUSE
value|(1<< 3)
comment|/**** cfg_1c register ****/
comment|/*  * Completion FIFO size  *  (descriptors per queue)  */
define|#
directive|define
name|UDMA_M2S_COMP_CFG_1C_COMP_FIFO_DEPTH_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_M2S_COMP_CFG_1C_COMP_FIFO_DEPTH_SHIFT
value|0
comment|/*  * Unacknowledged FIFO size.  * (descriptors)  */
define|#
directive|define
name|UDMA_M2S_COMP_CFG_1C_UNACK_FIFO_DEPTH_MASK
value|0x0001FF00
define|#
directive|define
name|UDMA_M2S_COMP_CFG_1C_UNACK_FIFO_DEPTH_SHIFT
value|8
comment|/*  * Enable promotion.  * Enable the promotion of the current queue in progress for the completion  * write scheduler.  */
define|#
directive|define
name|UDMA_M2S_COMP_CFG_1C_Q_PROMOTION
value|(1<< 24)
comment|/* Force RR arbitration in the completion arbiter */
define|#
directive|define
name|UDMA_M2S_COMP_CFG_1C_FORCE_RR
value|(1<< 25)
comment|/* Minimum number of free completion entries to qualify for promotion */
define|#
directive|define
name|UDMA_M2S_COMP_CFG_1C_Q_FREE_MIN_MASK
value|0xF0000000
define|#
directive|define
name|UDMA_M2S_COMP_CFG_1C_Q_FREE_MIN_SHIFT
value|28
comment|/**** cfg_application_ack register ****/
comment|/*  * Acknowledge timeout timer.  * ACK from the application through the stream interface)  */
define|#
directive|define
name|UDMA_M2S_COMP_CFG_APPLICATION_ACK_TOUT_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_COMP_CFG_APPLICATION_ACK_TOUT_SHIFT
value|0
comment|/**** cfg_st register ****/
comment|/* Use additional length value for all statistics counters. */
define|#
directive|define
name|UDMA_M2S_STAT_CFG_ST_USE_EXTRA_LEN
value|(1<< 0)
comment|/**** reg_1 register ****/
comment|/*  * Read the size of the descriptor prefetch FIFO  * (descriptors).  */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_1_DESC_PREFERCH_FIFO_DEPTH_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_1_DESC_PREFERCH_FIFO_DEPTH_SHIFT
value|0
comment|/**** reg_3 register ****/
comment|/*  * Maximum number of data beats in the data read FIFO.  * Defined based on data FIFO size  * (default FIFO size 2KB â 128 beats)  */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_3_DATA_FIFO_DEPTH_MASK
value|0x000003FF
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_3_DATA_FIFO_DEPTH_SHIFT
value|0
comment|/*  * Maximum number of packets in the data read FIFO.  * Defined based on header FIFO size  */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_3_DATA_RD_MAX_PKT_LIMIT_MASK
value|0x00FF0000
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_3_DATA_RD_MAX_PKT_LIMIT_SHIFT
value|16
comment|/**** reg_4 register ****/
comment|/*  * Size of the completion FIFO of each queue  * (words)  */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_4_COMP_FIFO_DEPTH_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_4_COMP_FIFO_DEPTH_SHIFT
value|0
comment|/* Size of the unacknowledged FIFO (descriptors) */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_4_COMP_UNACK_FIFO_DEPTH_MASK
value|0x0001FF00
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_4_COMP_UNACK_FIFO_DEPTH_SHIFT
value|8
comment|/**** reg_5 register ****/
comment|/* Maximum number of outstanding data reads to AXI */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_5_MAX_DATA_RD_OSTAND_MASK
value|0x0000003F
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_5_MAX_DATA_RD_OSTAND_SHIFT
value|0
comment|/* Maximum number of outstanding descriptor reads to AXI */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_5_MAX_DESC_RD_OSTAND_MASK
value|0x00003F00
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_5_MAX_DESC_RD_OSTAND_SHIFT
value|8
comment|/*  * Maximum number of outstanding descriptor writes to AXI.  * (AXI transactions)  */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_5_MAX_COMP_REQ_MASK
value|0x003F0000
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_5_MAX_COMP_REQ_SHIFT
value|16
comment|/*  * Maximum number of outstanding data beats for descriptor write to AXI.  * (AXI beats)  */
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_5_MAX_COMP_DATA_WR_OSTAND_MASK
value|0xFF000000
define|#
directive|define
name|UDMA_M2S_FEATURE_REG_5_MAX_COMP_DATA_WR_OSTAND_SHIFT
value|24
comment|/**** cfg register ****/
comment|/*  * Length offset to be used for each packet from this queue.  * (length offset is used for the scheduler and rate limiter).  */
define|#
directive|define
name|UDMA_M2S_Q_CFG_PKT_LEN_OFFSET_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_Q_CFG_PKT_LEN_OFFSET_SHIFT
value|0
comment|/*  * Enable operation of this queue.  * Start prefetch.  */
define|#
directive|define
name|UDMA_M2S_Q_CFG_EN_PREF
value|(1<< 16)
comment|/*  * Enable operation of this queue.  * Start scheduling.  */
define|#
directive|define
name|UDMA_M2S_Q_CFG_EN_SCHEDULING
value|(1<< 17)
comment|/* Allow prefetch of less than minimum prefetch burst size. */
define|#
directive|define
name|UDMA_M2S_Q_CFG_ALLOW_LT_MIN_PREF
value|(1<< 20)
comment|/* Configure the AXI AWCACHE for completion write.  */
define|#
directive|define
name|UDMA_M2S_Q_CFG_AXI_AWCACHE_COMP_MASK
value|0x0F000000
define|#
directive|define
name|UDMA_M2S_Q_CFG_AXI_AWCACHE_COMP_SHIFT
value|24
comment|/*  * AXI QoS for the selected queue.  * This value is used in AXI transactions associated with this queue and the  * prefetch and completion arbiters.  */
define|#
directive|define
name|UDMA_M2S_Q_CFG_AXI_QOS_MASK
value|0x70000000
define|#
directive|define
name|UDMA_M2S_Q_CFG_AXI_QOS_SHIFT
value|28
comment|/**** status register ****/
comment|/* Indicates how many entries are used in the queue */
define|#
directive|define
name|UDMA_M2S_Q_STATUS_Q_USED_MASK
value|0x01FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_STATUS_Q_USED_SHIFT
value|0
comment|/*  * prefetch status  * 0 â prefetch operation is stopped  * 1 â prefetch is operational  */
define|#
directive|define
name|UDMA_M2S_Q_STATUS_PREFETCH
value|(1<< 28)
comment|/*  * Queue scheduler status  * 0 â queue is not active and not participating in scheduling  * 1 â queue is active and participating in the scheduling process  */
define|#
directive|define
name|UDMA_M2S_Q_STATUS_SCHEDULER
value|(1<< 29)
comment|/* Queue is suspended due to DMB */
define|#
directive|define
name|UDMA_M2S_Q_STATUS_Q_DMB
value|(1<< 30)
comment|/*  * Queue full indication.  * (used by the host when head pointer equals tail pointer).  */
define|#
directive|define
name|UDMA_M2S_Q_STATUS_Q_FULL
value|(1<< 31)
comment|/*  * M2S Descriptor Ring Base address [31:4].  * Value of the base address of the M2S descriptor ring  * [3:0] - 0 - 16B alignment is enforced  * ([11:4] should be 0 for 4KB alignment)  */
define|#
directive|define
name|UDMA_M2S_Q_TDRBP_LOW_ADDR_MASK
value|0xFFFFFFF0
define|#
directive|define
name|UDMA_M2S_Q_TDRBP_LOW_ADDR_SHIFT
value|4
comment|/**** TDRL register ****/
comment|/*  * Length of the descriptor ring.  * (descriptors)  * Associated with the ring base address, ends at maximum burst size alignment.  */
define|#
directive|define
name|UDMA_M2S_Q_TDRL_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_TDRL_OFFSET_SHIFT
value|0
comment|/**** TDRHP register ****/
comment|/*  * Relative offset of the next descriptor that needs to be read into the  * prefetch FIFO.  * Incremented when the DMA reads valid descriptors from the host memory to the  * prefetch FIFO.  * Note that this is the offset in # of descriptors and not in byte address.  */
define|#
directive|define
name|UDMA_M2S_Q_TDRHP_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_TDRHP_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_M2S_Q_TDRHP_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_M2S_Q_TDRHP_RING_ID_SHIFT
value|30
comment|/**** TDRTP_inc register ****/
comment|/* Increments the value in Q_TDRTP (descriptors) */
define|#
directive|define
name|UDMA_M2S_Q_TDRTP_INC_VAL_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_TDRTP_INC_VAL_SHIFT
value|0
comment|/**** TDRTP register ****/
comment|/*  * Relative offset of the next free descriptor in the host memory.  * Note that this is the offset in # of descriptors and not in byte address.  */
define|#
directive|define
name|UDMA_M2S_Q_TDRTP_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_TDRTP_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_M2S_Q_TDRTP_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_M2S_Q_TDRTP_RING_ID_SHIFT
value|30
comment|/**** TDCP register ****/
comment|/*  * Relative offset of the first descriptor in the prefetch FIFO.  * This is the next descriptor that will be read by the scheduler.  */
define|#
directive|define
name|UDMA_M2S_Q_TDCP_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_TDCP_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_M2S_Q_TDCP_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_M2S_Q_TDCP_RING_ID_SHIFT
value|30
comment|/*  * M2S Descriptor Ring Base address [31:4].  * Value of the base address of the M2S descriptor ring  * [3:0] - 0 - 16B alignment is enforced  * ([11:4] should be 0 for 4KB alignment)  * NOTE:  * Length of the descriptor ring (in descriptors) associated with the ring base  * address. Ends at maximum burst size alignment.  */
define|#
directive|define
name|UDMA_M2S_Q_TCRBP_LOW_ADDR_MASK
value|0xFFFFFFF0
define|#
directive|define
name|UDMA_M2S_Q_TCRBP_LOW_ADDR_SHIFT
value|4
comment|/**** TCRHP register ****/
comment|/*  * Relative offset of the next descriptor that needs to be updated by the  * completion controller.  * Note: This is in descriptors and not in byte address.  */
define|#
directive|define
name|UDMA_M2S_Q_TCRHP_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_TCRHP_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_M2S_Q_TCRHP_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_M2S_Q_TCRHP_RING_ID_SHIFT
value|30
comment|/**** TCRHP_internal register ****/
comment|/*  * Relative offset of the next descriptor that needs to be updated by the  * completion controller.  * Note: This is in descriptors and not in byte address.  */
define|#
directive|define
name|UDMA_M2S_Q_TCRHP_INTERNAL_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_TCRHP_INTERNAL_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_M2S_Q_TCRHP_INTERNAL_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_M2S_Q_TCRHP_INTERNAL_RING_ID_SHIFT
value|30
comment|/**** rate_limit_cfg_1 register ****/
comment|/* Maximum number of accumulated bytes in the token counter. */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_1_MAX_BURST_SIZE_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_1_MAX_BURST_SIZE_SHIFT
value|0
comment|/* Enable the rate limiter. */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_1_EN
value|(1<< 24)
comment|/* Stop token fill. */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_1_PAUSE
value|(1<< 25)
comment|/**** rate_limit_cfg_cycle register ****/
comment|/* Number of short cycles between token fills */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_CYCLE_LONG_CYCLE_SIZE_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_CYCLE_LONG_CYCLE_SIZE_SHIFT
value|0
comment|/**** rate_limit_cfg_token_size_1 register ****/
comment|/* Number of bits to add in each long cycle */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_TOKEN_SIZE_1_LONG_CYCLE_MASK
value|0x0007FFFF
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_TOKEN_SIZE_1_LONG_CYCLE_SHIFT
value|0
comment|/**** rate_limit_cfg_token_size_2 register ****/
comment|/* Number of bits to add in each cycle */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_TOKEN_SIZE_2_SHORT_CYCLE_MASK
value|0x0007FFFF
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_CFG_TOKEN_SIZE_2_SHORT_CYCLE_SHIFT
value|0
comment|/**** rate_limit_sw_ctrl register ****/
comment|/* Reset the token bucket counter. */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_SW_CTRL_RST_TOKEN_CNT
value|(1<< 0)
comment|/**** rate_limit_mask register ****/
comment|/* Mask the external rate limiter. */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_MASK_EXTERNAL_RATE_LIMITER
value|(1<< 0)
comment|/* Mask the internal rate limiter. */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_MASK_INTERNAL_RATE_LIMITER
value|(1<< 1)
comment|/*  * Mask the internal pause mechanism for DMB.  * (Data Memory Barrier).  */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_MASK_INTERNAL_PAUSE_DMB
value|(1<< 2)
comment|/* Mask the external application pause interface. */
define|#
directive|define
name|UDMA_M2S_Q_RATE_LIMIT_MASK_EXTERNAL_PAUSE
value|(1<< 3)
comment|/**** dwrr_cfg_1 register ****/
comment|/* Maximum number of accumulated bytes in the deficit counter */
define|#
directive|define
name|UDMA_M2S_Q_DWRR_CFG_1_MAX_DEFICIT_CNT_SIZE_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_M2S_Q_DWRR_CFG_1_MAX_DEFICIT_CNT_SIZE_SHIFT
value|0
comment|/* Bypass the DWRR.  */
define|#
directive|define
name|UDMA_M2S_Q_DWRR_CFG_1_STRICT
value|(1<< 24)
comment|/* Stop deficit counter increment. */
define|#
directive|define
name|UDMA_M2S_Q_DWRR_CFG_1_PAUSE
value|(1<< 25)
comment|/**** dwrr_cfg_2 register ****/
comment|/*  * Value for the queue QoS.  * Queues with the same QoS value are scheduled with RR/DWRR.  * Only LOG(number of queues) is used.  */
define|#
directive|define
name|UDMA_M2S_Q_DWRR_CFG_2_Q_QOS_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_M2S_Q_DWRR_CFG_2_Q_QOS_SHIFT
value|0
comment|/**** dwrr_cfg_3 register ****/
comment|/* Queue weight */
define|#
directive|define
name|UDMA_M2S_Q_DWRR_CFG_3_WEIGHT_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_M2S_Q_DWRR_CFG_3_WEIGHT_SHIFT
value|0
comment|/**** dwrr_sw_ctrl register ****/
comment|/* Reset the DWRR deficit counter. */
define|#
directive|define
name|UDMA_M2S_Q_DWRR_SW_CTRL_RST_CNT
value|(1<< 0)
comment|/**** comp_cfg register ****/
comment|/* Enable writing to the completion ring */
define|#
directive|define
name|UDMA_M2S_Q_COMP_CFG_EN_COMP_RING_UPDATE
value|(1<< 0)
comment|/* Disable the completion coalescing function. */
define|#
directive|define
name|UDMA_M2S_Q_COMP_CFG_DIS_COMP_COAL
value|(1<< 1)
comment|/**** q_sw_ctrl register ****/
comment|/*  * Reset the DMB hardware barrier  * (enable queue operation).  */
define|#
directive|define
name|UDMA_M2S_Q_SW_CTRL_RST_DMB
value|(1<< 0)
comment|/* Reset the tail pointer hardware. */
define|#
directive|define
name|UDMA_M2S_Q_SW_CTRL_RST_TAIL_PTR
value|(1<< 1)
comment|/* Reset the head pointer hardware. */
define|#
directive|define
name|UDMA_M2S_Q_SW_CTRL_RST_HEAD_PTR
value|(1<< 2)
comment|/* Reset the current pointer hardware. */
define|#
directive|define
name|UDMA_M2S_Q_SW_CTRL_RST_CURRENT_PTR
value|(1<< 3)
comment|/* Reset the queue */
define|#
directive|define
name|UDMA_M2S_Q_SW_CTRL_RST_Q
value|(1<< 8)
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
comment|/* __AL_HAL_UDMA_M2S_REG_H */
end_comment

end_unit

