begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @file   al_hal_udma_regs_s2m.h  *  * @brief C Header file for the UDMA S2M registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_UDMA_S2M_REG_H
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_UDMA_S2M_REG_H
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
name|udma_axi_s2m
block|{
comment|/* [0x0] Data write master configuration */
name|uint32_t
name|data_wr_cfg_1
decl_stmt|;
comment|/* [0x4] Data write master configuration */
name|uint32_t
name|data_wr_cfg_2
decl_stmt|;
comment|/* [0x8] Descriptor read master configuration */
name|uint32_t
name|desc_rd_cfg_4
decl_stmt|;
comment|/* [0xc] Descriptor read master configuration */
name|uint32_t
name|desc_rd_cfg_5
decl_stmt|;
comment|/* [0x10] Completion  write master configuration */
name|uint32_t
name|comp_wr_cfg_1
decl_stmt|;
comment|/* [0x14] Completion  write master configuration */
name|uint32_t
name|comp_wr_cfg_2
decl_stmt|;
comment|/* [0x18] Data write master configuration */
name|uint32_t
name|data_wr_cfg
decl_stmt|;
comment|/* [0x1c] Descriptors read master configuration */
name|uint32_t
name|desc_rd_cfg_3
decl_stmt|;
comment|/* [0x20] Completion descriptors write master configuration */
name|uint32_t
name|desc_wr_cfg_1
decl_stmt|;
comment|/* [0x24] AXI outstanding read configuration */
name|uint32_t
name|ostand_cfg_rd
decl_stmt|;
comment|/* [0x28] AXI outstanding write configuration */
name|uint32_t
name|ostand_cfg_wr
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|53
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_s2m
block|{
comment|/* 	 * [0x0] DMA state 	 * 00  - No pending tasks 	 * 01 â Normal (active) 	 * 10 â Abort (error condition) 	 * 11 â Reserved 	 */
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
comment|/* 	 * [0xc] S2M DMA error log mask. 	 * Each error has an interrupt controller cause bit. 	 * This register determines if these errors cause the S2M DMA to log the 	 * error condition. 	 * 0 - Log is enable 	 * 1 - Log is masked. 	 */
name|uint32_t
name|err_log_mask
decl_stmt|;
name|uint32_t
name|rsrvd_1
decl_stmt|;
comment|/* 	 * [0x14] DMA header log 	 * Sample the packet header that caused the error 	 */
name|uint32_t
name|log_0
decl_stmt|;
comment|/* 	 * [0x18] DMA header log 	 * Sample the packet header that caused the error. 	 */
name|uint32_t
name|log_1
decl_stmt|;
comment|/* 	 * [0x1c] DMA header log 	 * Sample the packet header that caused the error. 	 */
name|uint32_t
name|log_2
decl_stmt|;
comment|/* 	 * [0x20] DMA header log 	 * Sample the packet header that caused the error 	 */
name|uint32_t
name|log_3
decl_stmt|;
comment|/* [0x24] DMA clear error log */
name|uint32_t
name|clear_err_log
decl_stmt|;
comment|/* [0x28] S2M stream data FIFO status */
name|uint32_t
name|s_data_fifo_status
decl_stmt|;
comment|/* [0x2c] S2M stream header FIFO status */
name|uint32_t
name|s_header_fifo_status
decl_stmt|;
comment|/* [0x30] S2M AXI data FIFO status */
name|uint32_t
name|axi_data_fifo_status
decl_stmt|;
comment|/* [0x34] S2M unack FIFO status */
name|uint32_t
name|unack_fifo_status
decl_stmt|;
comment|/* [0x38] Select queue for debug */
name|uint32_t
name|indirect_ctrl
decl_stmt|;
comment|/* 	 * [0x3c] S2M prefetch FIFO status. 	 * Status of the selected queue in S2M_indirect_ctrl 	 */
name|uint32_t
name|sel_pref_fifo_status
decl_stmt|;
comment|/* 	 * [0x40] S2M completion FIFO status. 	 * Status of the selected queue in S2M_indirect_ctrl 	 */
name|uint32_t
name|sel_comp_fifo_status
decl_stmt|;
comment|/* [0x44] S2M state machine and FIFO clear control */
name|uint32_t
name|clear_ctrl
decl_stmt|;
comment|/* [0x48] S2M Misc Check enable */
name|uint32_t
name|check_en
decl_stmt|;
comment|/* [0x4c] S2M FIFO enable control, internal */
name|uint32_t
name|fifo_en
decl_stmt|;
comment|/* [0x50] Stream interface configuration */
name|uint32_t
name|stream_cfg
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
name|udma_s2m_rd
block|{
comment|/* [0x0] S2M descriptor prefetch configuration */
name|uint32_t
name|desc_pref_cfg_1
decl_stmt|;
comment|/* [0x4] S2M descriptor prefetch configuration */
name|uint32_t
name|desc_pref_cfg_2
decl_stmt|;
comment|/* [0x8] S2M descriptor prefetch configuration */
name|uint32_t
name|desc_pref_cfg_3
decl_stmt|;
comment|/* [0xc] S2M descriptor prefetch configuration */
name|uint32_t
name|desc_pref_cfg_4
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
name|udma_s2m_wr
block|{
comment|/* [0x0] Stream data FIFO configuration */
name|uint32_t
name|data_cfg_1
decl_stmt|;
comment|/* [0x4] Data write configuration */
name|uint32_t
name|data_cfg_2
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
name|udma_s2m_comp
block|{
comment|/* [0x0] Completion controller configuration */
name|uint32_t
name|cfg_1c
decl_stmt|;
comment|/* [0x4] Completion controller configuration */
name|uint32_t
name|cfg_2c
decl_stmt|;
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0xc] Completion controller application acknowledge configuration */
name|uint32_t
name|cfg_application_ack
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
name|udma_s2m_stat
block|{
name|uint32_t
name|rsrvd_0
decl_stmt|;
comment|/* [0x4] Number of dropped packets */
name|uint32_t
name|drop_pkt
decl_stmt|;
comment|/* 	 * [0x8] Counting the net length of the data buffers [64-bit] 	 * Should be read before rx_bytes_high 	 */
name|uint32_t
name|rx_bytes_low
decl_stmt|;
comment|/* 	 * [0xc] Counting the net length of the data buffers [64-bit] 	 * Should be read after tx_bytes_low (value is sampled when reading 	 * Should be read before rx_bytes_low 	 */
name|uint32_t
name|rx_bytes_high
decl_stmt|;
comment|/* [0x10] Total number of descriptors read from the host memory */
name|uint32_t
name|prefed_desc
decl_stmt|;
comment|/* [0x14] Number of packets written into the completion ring */
name|uint32_t
name|comp_pkt
decl_stmt|;
comment|/* [0x18] Number of descriptors written into the completion ring */
name|uint32_t
name|comp_desc
decl_stmt|;
comment|/* 	 * [0x1c] Number of acknowledged packets. 	 * (acknowledge sent to the stream interface) 	 */
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
name|udma_s2m_feature
block|{
comment|/* 	 * [0x0] S2M Feature register 	 * S2M instantiation parameters 	 */
name|uint32_t
name|reg_1
decl_stmt|;
comment|/* [0x4] Reserved S2M feature register */
name|uint32_t
name|reg_2
decl_stmt|;
comment|/* 	 * [0x8] S2M Feature register 	 * S2M instantiation parameters 	 */
name|uint32_t
name|reg_3
decl_stmt|;
comment|/* 	 * [0xc] S2M Feature register. 	 * S2M instantiation parameters. 	 */
name|uint32_t
name|reg_4
decl_stmt|;
comment|/* 	 * [0x10] S2M Feature register. 	 * S2M instantiation parameters. 	 */
name|uint32_t
name|reg_5
decl_stmt|;
comment|/* [0x14] S2M Feature register. S2M instantiation parameters. */
name|uint32_t
name|reg_6
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
name|udma_s2m_q
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|8
index|]
decl_stmt|;
comment|/* [0x20] S2M Descriptor ring configuration */
name|uint32_t
name|cfg
decl_stmt|;
comment|/* [0x24] S2M Descriptor ring status and information */
name|uint32_t
name|status
decl_stmt|;
comment|/* [0x28] Rx Descriptor Ring Base Pointer [31:4] */
name|uint32_t
name|rdrbp_low
decl_stmt|;
comment|/* [0x2c] Rx Descriptor Ring Base Pointer [63:32] */
name|uint32_t
name|rdrbp_high
decl_stmt|;
comment|/* 	 * [0x30] Rx Descriptor Ring Length[23:2] 	 */
name|uint32_t
name|rdrl
decl_stmt|;
comment|/* [0x34] RX Descriptor Ring Head Pointer */
name|uint32_t
name|rdrhp
decl_stmt|;
comment|/* [0x38] Rx Descriptor Tail Pointer increment */
name|uint32_t
name|rdrtp_inc
decl_stmt|;
comment|/* [0x3c] Rx Descriptor Tail Pointer */
name|uint32_t
name|rdrtp
decl_stmt|;
comment|/* [0x40] RX Descriptor Current Pointer */
name|uint32_t
name|rdcp
decl_stmt|;
comment|/* [0x44] Rx Completion Ring Base Pointer [31:4] */
name|uint32_t
name|rcrbp_low
decl_stmt|;
comment|/* [0x48] Rx Completion Ring Base Pointer [63:32] */
name|uint32_t
name|rcrbp_high
decl_stmt|;
comment|/* [0x4c] Rx Completion Ring Head Pointer */
name|uint32_t
name|rcrhp
decl_stmt|;
comment|/* 	 * [0x50] RX Completion Ring Head Pointer internal. 	 * (Before the coalescing FIFO) 	 */
name|uint32_t
name|rcrhp_internal
decl_stmt|;
comment|/* [0x54] Completion controller configuration for the queue */
name|uint32_t
name|comp_cfg
decl_stmt|;
comment|/* [0x58] Completion controller configuration for the queue */
name|uint32_t
name|comp_cfg_2
decl_stmt|;
comment|/* [0x5c] Packet handler configuration */
name|uint32_t
name|pkt_cfg
decl_stmt|;
comment|/* [0x60] Queue QoS configuration */
name|uint32_t
name|qos_cfg
decl_stmt|;
comment|/* [0x64] DMB software control */
name|uint32_t
name|q_sw_ctrl
decl_stmt|;
comment|/* [0x68] Number of S2M Rx packets after completion  */
name|uint32_t
name|q_rx_pkt
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|997
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_s2m_regs
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|udma_axi_s2m
name|axi_s2m
decl_stmt|;
comment|/* [0x100] */
name|struct
name|udma_s2m
name|s2m
decl_stmt|;
comment|/* [0x200] */
name|struct
name|udma_s2m_rd
name|s2m_rd
decl_stmt|;
comment|/* [0x300] */
name|struct
name|udma_s2m_wr
name|s2m_wr
decl_stmt|;
comment|/* [0x340] */
name|struct
name|udma_s2m_comp
name|s2m_comp
decl_stmt|;
comment|/* [0x380] */
name|uint32_t
name|rsrvd_1
index|[
literal|80
index|]
decl_stmt|;
name|struct
name|udma_s2m_stat
name|s2m_stat
decl_stmt|;
comment|/* [0x500] */
name|struct
name|udma_s2m_feature
name|s2m_feature
decl_stmt|;
comment|/* [0x600] */
name|uint32_t
name|rsrvd_2
index|[
literal|576
index|]
decl_stmt|;
name|struct
name|udma_s2m_q
name|s2m_q
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x1000] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** data_wr_cfg_1 register ****/
comment|/* AXI write  ID (AWID) */
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_1_AWID_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_1_AWID_SHIFT
value|0
comment|/* Cache Type */
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_1_AWCACHE_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_1_AWCACHE_SHIFT
value|16
comment|/* Burst type */
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_1_AWBURST_MASK
value|0x03000000
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_1_AWBURST_SHIFT
value|24
comment|/**** data_wr_cfg_2 register ****/
comment|/* User extension */
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_2_AWUSER_MASK
value|0x000FFFFF
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_2_AWUSER_SHIFT
value|0
comment|/* Bus size, 128-bit */
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_2_AWSIZE_MASK
value|0x00700000
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_2_AWSIZE_SHIFT
value|20
comment|/*  * AXI Master QoS.  * Used for arbitration between AXI masters  */
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_2_AWQOS_MASK
value|0x07000000
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_2_AWQOS_SHIFT
value|24
comment|/* Protection Type */
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_2_AWPROT_MASK
value|0x70000000
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_2_AWPROT_SHIFT
value|28
comment|/**** desc_rd_cfg_4 register ****/
comment|/* AXI read  ID (ARID) */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_4_ARID_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_4_ARID_SHIFT
value|0
comment|/* Cache Type */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_4_ARCACHE_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_4_ARCACHE_SHIFT
value|16
comment|/* Burst type */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_4_ARBURST_MASK
value|0x03000000
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_4_ARBURST_SHIFT
value|24
comment|/**** desc_rd_cfg_5 register ****/
comment|/* User extension */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_5_ARUSER_MASK
value|0x000FFFFF
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_5_ARUSER_SHIFT
value|0
comment|/* Bus size, 128-bit */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_5_ARSIZE_MASK
value|0x00700000
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_5_ARSIZE_SHIFT
value|20
comment|/*  * AXI Master QoS.  * Used for arbitration between AXI masters  */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_5_ARQOS_MASK
value|0x07000000
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_5_ARQOS_SHIFT
value|24
comment|/* Protection Type */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_5_ARPROT_MASK
value|0x70000000
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_5_ARPROT_SHIFT
value|28
comment|/**** comp_wr_cfg_1 register ****/
comment|/* AXI write  ID (AWID) */
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_1_AWID_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_1_AWID_SHIFT
value|0
comment|/* Cache Type */
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_1_AWCACHE_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_1_AWCACHE_SHIFT
value|16
comment|/* Burst type */
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_1_AWBURST_MASK
value|0x03000000
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_1_AWBURST_SHIFT
value|24
comment|/**** comp_wr_cfg_2 register ****/
comment|/* User extension */
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_2_AWUSER_MASK
value|0x000FFFFF
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_2_AWUSER_SHIFT
value|0
comment|/* Bus size, 128-bit */
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_2_AWSIZE_MASK
value|0x00700000
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_2_AWSIZE_SHIFT
value|20
comment|/*  * AXI Master QoS.  * Used for arbitration between AXI masters  */
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_2_AWQOS_MASK
value|0x07000000
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_2_AWQOS_SHIFT
value|24
comment|/* Protection Type */
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_2_AWPROT_MASK
value|0x70000000
define|#
directive|define
name|UDMA_AXI_S2M_COMP_WR_CFG_2_AWPROT_SHIFT
value|28
comment|/**** data_wr_cfg register ****/
comment|/*  * Defines the maximum number of AXI beats for a single AXI burst. This value is  * used for the burst split decision.  */
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_MAX_AXI_BEATS_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_S2M_DATA_WR_CFG_MAX_AXI_BEATS_SHIFT
value|0
comment|/**** desc_rd_cfg_3 register ****/
comment|/*  * Defines the maximum number of AXI beats for a single AXI burst. This value is  * used for the burst split decision.  */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_3_MAX_AXI_BEATS_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_3_MAX_AXI_BEATS_SHIFT
value|0
comment|/*  * Enables breaking descriptor read request.  * Aligned to max_AXI_beats when the total read size is less than max_AXI_beats.  */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_RD_CFG_3_ALWAYS_BREAK_ON_MAX_BOUDRY
value|(1<< 16)
comment|/**** desc_wr_cfg_1 register ****/
comment|/*  * Defines the maximum number of AXI beats for a single AXI burst. This value is  * used for the burst split decision.  */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_WR_CFG_1_MAX_AXI_BEATS_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_AXI_S2M_DESC_WR_CFG_1_MAX_AXI_BEATS_SHIFT
value|0
comment|/*  * Minimum burst for writing completion descriptors.  * (AXI beats).  * Value must be aligned to cache lines (64 bytes).  * Default value is 2 cache lines, 8 beats.  */
define|#
directive|define
name|UDMA_AXI_S2M_DESC_WR_CFG_1_MIN_AXI_BEATS_MASK
value|0x00FF0000
define|#
directive|define
name|UDMA_AXI_S2M_DESC_WR_CFG_1_MIN_AXI_BEATS_SHIFT
value|16
comment|/**** ostand_cfg_rd register ****/
comment|/*  * Maximum number of outstanding descriptor reads to the AXI.  * (AXI transactions).  */
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_RD_MAX_DESC_RD_OSTAND_MASK
value|0x0000003F
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_RD_MAX_DESC_RD_OSTAND_SHIFT
value|0
comment|/* Maximum number of outstanding stream acknowledges. */
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_RD_MAX_STREAM_ACK_MASK
value|0x001F0000
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_RD_MAX_STREAM_ACK_SHIFT
value|16
comment|/**** ostand_cfg_wr register ****/
comment|/*  * Maximum number of outstanding data writes to the AXI.  * (AXI transactions).  */
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_WR_MAX_DATA_WR_OSTAND_MASK
value|0x0000003F
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_WR_MAX_DATA_WR_OSTAND_SHIFT
value|0
comment|/*  * Maximum number of outstanding data beats for data write to AXI.  * (AXI beats).  */
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_WR_MAX_DATA_BEATS_WR_OSTAND_MASK
value|0x0000FF00
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_WR_MAX_DATA_BEATS_WR_OSTAND_SHIFT
value|8
comment|/*  * Maximum number of outstanding descriptor writes to the AXI.  * (AXI transactions).  */
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_WR_MAX_COMP_REQ_MASK
value|0x003F0000
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_WR_MAX_COMP_REQ_SHIFT
value|16
comment|/*  * Maximum number of outstanding data beats for descriptor write to AXI.  * (AXI beats).  */
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_WR_MAX_COMP_DATA_WR_OSTAND_MASK
value|0xFF000000
define|#
directive|define
name|UDMA_AXI_S2M_OSTAND_CFG_WR_MAX_COMP_DATA_WR_OSTAND_SHIFT
value|24
comment|/**** state register ****/
define|#
directive|define
name|UDMA_S2M_STATE_COMP_CTRL_MASK
value|0x00000003
define|#
directive|define
name|UDMA_S2M_STATE_COMP_CTRL_SHIFT
value|0
define|#
directive|define
name|UDMA_S2M_STATE_STREAM_IF_MASK
value|0x00000030
define|#
directive|define
name|UDMA_S2M_STATE_STREAM_IF_SHIFT
value|4
define|#
directive|define
name|UDMA_S2M_STATE_DATA_WR_CTRL_MASK
value|0x00000300
define|#
directive|define
name|UDMA_S2M_STATE_DATA_WR_CTRL_SHIFT
value|8
define|#
directive|define
name|UDMA_S2M_STATE_DESC_PREF_MASK
value|0x00003000
define|#
directive|define
name|UDMA_S2M_STATE_DESC_PREF_SHIFT
value|12
define|#
directive|define
name|UDMA_S2M_STATE_AXI_WR_DATA_MASK
value|0x00030000
define|#
directive|define
name|UDMA_S2M_STATE_AXI_WR_DATA_SHIFT
value|16
comment|/**** change_state register ****/
comment|/* Start normal operation */
define|#
directive|define
name|UDMA_S2M_CHANGE_STATE_NORMAL
value|(1<< 0)
comment|/* Stop normal operation */
define|#
directive|define
name|UDMA_S2M_CHANGE_STATE_DIS
value|(1<< 1)
comment|/*  * Stop all machines.  * (Prefetch, scheduling, completion and stream interface)  */
define|#
directive|define
name|UDMA_S2M_CHANGE_STATE_ABORT
value|(1<< 2)
comment|/**** clear_err_log register ****/
comment|/* Clear error log */
define|#
directive|define
name|UDMA_S2M_CLEAR_ERR_LOG_CLEAR
value|(1<< 0)
comment|/**** s_data_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_S2M_S_DATA_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_S2M_S_DATA_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_S2M_S_DATA_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_S2M_S_DATA_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** s_header_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_S2M_S_HEADER_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_S2M_S_HEADER_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_S2M_S_HEADER_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_S2M_S_HEADER_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** axi_data_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_S2M_AXI_DATA_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_S2M_AXI_DATA_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_S2M_AXI_DATA_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_S2M_AXI_DATA_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** unack_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_S2M_UNACK_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_S2M_UNACK_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_S2M_UNACK_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_S2M_UNACK_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** indirect_ctrl register ****/
comment|/* Selected queue for status read */
define|#
directive|define
name|UDMA_S2M_INDIRECT_CTRL_Q_NUM_MASK
value|0x00000FFF
define|#
directive|define
name|UDMA_S2M_INDIRECT_CTRL_Q_NUM_SHIFT
value|0
comment|/**** sel_pref_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_S2M_SEL_PREF_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_S2M_SEL_PREF_FIFO_STATUS_USED_SHIFT
value|0
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_S2M_SEL_PREF_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_S2M_SEL_PREF_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** sel_comp_fifo_status register ****/
comment|/* FIFO used indication */
define|#
directive|define
name|UDMA_S2M_SEL_COMP_FIFO_STATUS_USED_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_S2M_SEL_COMP_FIFO_STATUS_USED_SHIFT
value|0
comment|/* Coalescing ACTIVE FSM state indication. */
define|#
directive|define
name|UDMA_S2M_SEL_COMP_FIFO_STATUS_COAL_ACTIVE_STATE_MASK
value|0x00300000
define|#
directive|define
name|UDMA_S2M_SEL_COMP_FIFO_STATUS_COAL_ACTIVE_STATE_SHIFT
value|20
comment|/* FIFO empty indication */
define|#
directive|define
name|UDMA_S2M_SEL_COMP_FIFO_STATUS_EMPTY
value|(1<< 24)
comment|/* FIFO full indication */
define|#
directive|define
name|UDMA_S2M_SEL_COMP_FIFO_STATUS_FULL
value|(1<< 28)
comment|/**** stream_cfg register ****/
comment|/*  * Disables the stream interface operation.  * Changing to 1 stops at the end of packet reception.  */
define|#
directive|define
name|UDMA_S2M_STREAM_CFG_DISABLE
value|(1<< 0)
comment|/*  * Flush the stream interface operation.  * Changing to 1 stops at the end of packet reception and assert ready to the  * stream I/F.  */
define|#
directive|define
name|UDMA_S2M_STREAM_CFG_FLUSH
value|(1<< 4)
comment|/* Stop descriptor prefetch when the stream is disabled and the S2M is idle. */
define|#
directive|define
name|UDMA_S2M_STREAM_CFG_STOP_PREFETCH
value|(1<< 8)
comment|/**** desc_pref_cfg_1 register ****/
comment|/*  * Size of the descriptor prefetch FIFO.  * (descriptors)  */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_1_FIFO_DEPTH_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_1_FIFO_DEPTH_SHIFT
value|0
comment|/**** desc_pref_cfg_2 register ****/
comment|/* Enable promotion of the current queue in progress */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_2_Q_PROMOTION
value|(1<< 0)
comment|/* Force promotion of the current queue in progress */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_2_FORCE_PROMOTION
value|(1<< 1)
comment|/* Enable prefetch prediction of next packet in line. */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_2_EN_PREF_PREDICTION
value|(1<< 2)
comment|/*  * Threshold for queue promotion.  * Queue is promoted for prefetch if there are less descriptors in the prefetch  * FIFO than the threshold  */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_2_PROMOTION_TH_MASK
value|0x0000FF00
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_2_PROMOTION_TH_SHIFT
value|8
comment|/*  * Force RR arbitration in the prefetch arbiter.  * 0 - Standard arbitration based on queue QoS  * 1 - Force round robin arbitration  */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_2_PREF_FORCE_RR
value|(1<< 16)
comment|/**** desc_pref_cfg_3 register ****/
comment|/*  * Minimum descriptor burst size when prefetch FIFO level is below the  * descriptor prefetch threshold  * (must be 1)  */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_3_MIN_BURST_BELOW_THR_MASK
value|0x0000000F
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_3_MIN_BURST_BELOW_THR_SHIFT
value|0
comment|/*  * Minimum descriptor burst size when prefetch FIFO level is above the  * descriptor prefetch threshold  */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_3_MIN_BURST_ABOVE_THR_MASK
value|0x000000F0
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_3_MIN_BURST_ABOVE_THR_SHIFT
value|4
comment|/*  * Descriptor fetch threshold.  * Used as a threshold to determine the allowed minimum descriptor burst size.  * (Must be at least "max_desc_per_pkt")  */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_3_PREF_THR_MASK
value|0x0000FF00
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_3_PREF_THR_SHIFT
value|8
comment|/**** desc_pref_cfg_4 register ****/
comment|/*  * Used as a threshold for generating almost FULL indication to the application  */
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_4_A_FULL_THR_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_S2M_RD_DESC_PREF_CFG_4_A_FULL_THR_SHIFT
value|0
comment|/**** data_cfg_1 register ****/
comment|/*  * Maximum number of data beats in the data write FIFO.  * Defined based on data FIFO size  * (default FIFO size 512B â 32 beats)  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_1_DATA_FIFO_DEPTH_MASK
value|0x000003FF
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_1_DATA_FIFO_DEPTH_SHIFT
value|0
comment|/*  * Maximum number of packets in the data write FIFO.  * Defined based on header FIFO size  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_1_MAX_PKT_LIMIT_MASK
value|0x00FF0000
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_1_MAX_PKT_LIMIT_SHIFT
value|16
comment|/*  * Internal use  * Data FIFO margin  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_1_FIFO_MARGIN_MASK
value|0xFF000000
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_1_FIFO_MARGIN_SHIFT
value|24
comment|/**** data_cfg_2 register ****/
comment|/*  * Drop timer.  * Waiting time for the host to write new descriptor to the queue  * (for the current packet in process)  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_2_DESC_WAIT_TIMER_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_2_DESC_WAIT_TIMER_SHIFT
value|0
comment|/*  * Drop enable.  * Enable packet drop if there are no available descriptors in the system for  * this queue  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_2_DROP_IF_NO_DESC
value|(1<< 27)
comment|/*  * Lack of descriptors hint.  * Generate interrupt when a packet is waiting but there are no available  * descriptors in the queue  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_2_HINT_IF_NO_DESC
value|(1<< 28)
comment|/*  * Drop conditions  * Wait until a descriptor is available in the prefetch FIFO or the host before  * dropping packet.  * 1 - Drop if a descriptor is not available in the prefetch.  * 0 - Drop if a descriptor is not available in the system  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_2_WAIT_FOR_PREF
value|(1<< 29)
comment|/*  * DRAM write optimization  * 0 - Data write with byte enable  * 1 - Data write is always in Full AXI bus width (128 bit)  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_2_FULL_LINE_MODE
value|(1<< 30)
comment|/*  * Direct data write address  * 1 - Use buffer 1 instead of buffer 2 when direct data placement is used with  * header split.  * 0 - Use buffer 2 for the header.  */
define|#
directive|define
name|UDMA_S2M_WR_DATA_CFG_2_DIRECT_HDR_USE_BUF1
value|(1<< 31)
comment|/**** cfg_1c register ****/
comment|/*  * Completion descriptor size.  * (words)  */
define|#
directive|define
name|UDMA_S2M_COMP_CFG_1C_DESC_SIZE_MASK
value|0x0000000F
define|#
directive|define
name|UDMA_S2M_COMP_CFG_1C_DESC_SIZE_SHIFT
value|0
comment|/*  * Completion queue counter configuration.  * Completion FIFO in use counter measured in words or descriptors  * 1 - Words  * 0 - Descriptors  */
define|#
directive|define
name|UDMA_S2M_COMP_CFG_1C_CNT_WORDS
value|(1<< 8)
comment|/*  * Enable promotion of the current queue in progress in the completion write  * scheduler.  */
define|#
directive|define
name|UDMA_S2M_COMP_CFG_1C_Q_PROMOTION
value|(1<< 12)
comment|/* Force RR arbitration in the completion arbiter */
define|#
directive|define
name|UDMA_S2M_COMP_CFG_1C_FORCE_RR
value|(1<< 16)
comment|/* Minimum number of free completion entries to qualify for promotion */
define|#
directive|define
name|UDMA_S2M_COMP_CFG_1C_Q_FREE_MIN_MASK
value|0xF0000000
define|#
directive|define
name|UDMA_S2M_COMP_CFG_1C_Q_FREE_MIN_SHIFT
value|28
comment|/**** cfg_2c register ****/
comment|/*  * Completion FIFO size.  * (words per queue)  */
define|#
directive|define
name|UDMA_S2M_COMP_CFG_2C_COMP_FIFO_DEPTH_MASK
value|0x00000FFF
define|#
directive|define
name|UDMA_S2M_COMP_CFG_2C_COMP_FIFO_DEPTH_SHIFT
value|0
comment|/*  * Unacknowledged FIFO size.  * (descriptors)  */
define|#
directive|define
name|UDMA_S2M_COMP_CFG_2C_UNACK_FIFO_DEPTH_MASK
value|0x0FFF0000
define|#
directive|define
name|UDMA_S2M_COMP_CFG_2C_UNACK_FIFO_DEPTH_SHIFT
value|16
comment|/**** reg_1 register ****/
comment|/*  * Descriptor prefetch FIFO size  * (descriptors)  */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_1_DESC_PREFERCH_FIFO_DEPTH_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_1_DESC_PREFERCH_FIFO_DEPTH_SHIFT
value|0
comment|/**** reg_3 register ****/
comment|/*  * Maximum number of data beats in the data write FIFO.  * Defined based on data FIFO size  * (default FIFO size 512B â32 beats)  */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_3_DATA_FIFO_DEPTH_MASK
value|0x000003FF
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_3_DATA_FIFO_DEPTH_SHIFT
value|0
comment|/*  * Maximum number of packets in the data write FIFO.  * Defined based on header FIFO size  */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_3_DATA_WR_MAX_PKT_LIMIT_MASK
value|0x00FF0000
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_3_DATA_WR_MAX_PKT_LIMIT_SHIFT
value|16
comment|/**** reg_4 register ****/
comment|/*  * Completion FIFO size.  * (words per queue)  */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_4_COMP_FIFO_DEPTH_MASK
value|0x00000FFF
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_4_COMP_FIFO_DEPTH_SHIFT
value|0
comment|/*  * Unacknowledged FIFO size.  * (descriptors)  */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_4_COMP_UNACK_FIFO_DEPTH_MASK
value|0x0FFF0000
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_4_COMP_UNACK_FIFO_DEPTH_SHIFT
value|16
comment|/**** reg_5 register ****/
comment|/* Maximum number of outstanding data writes to the AXI */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_5_MAX_DATA_WR_OSTAND_MASK
value|0x0000003F
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_5_MAX_DATA_WR_OSTAND_SHIFT
value|0
comment|/*  * Maximum number of outstanding data beats for data write to AXI.  * (AXI beats)  */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_5_MAX_DATA_BEATS_WR_OSTAND_MASK
value|0x0000FF00
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_5_MAX_DATA_BEATS_WR_OSTAND_SHIFT
value|8
comment|/*  * Maximum number of outstanding descriptor reads to the AXI.  * (AXI transactions)  */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_5_MAX_COMP_REQ_MASK
value|0x003F0000
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_5_MAX_COMP_REQ_SHIFT
value|16
comment|/*  * Maximum number of outstanding data beats for descriptor write to AXI.  * (AXI beats)  */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_5_MAX_COMP_DATA_WR_OSTAND_MASK
value|0xFF000000
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_5_MAX_COMP_DATA_WR_OSTAND_SHIFT
value|24
comment|/**** reg_6 register ****/
comment|/* Maximum number of outstanding descriptor reads to the AXI */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_6_MAX_DESC_RD_OSTAND_MASK
value|0x0000003F
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_6_MAX_DESC_RD_OSTAND_SHIFT
value|0
comment|/* Maximum number of outstanding stream acknowledges */
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_6_MAX_STREAM_ACK_MASK
value|0x001F0000
define|#
directive|define
name|UDMA_S2M_FEATURE_REG_6_MAX_STREAM_ACK_SHIFT
value|16
comment|/**** cfg register ****/
comment|/*  * Configure the AXI AWCACHE  * for header write.  */
define|#
directive|define
name|UDMA_S2M_Q_CFG_AXI_AWCACHE_HDR_MASK
value|0x0000000F
define|#
directive|define
name|UDMA_S2M_Q_CFG_AXI_AWCACHE_HDR_SHIFT
value|0
comment|/*  * Configure the AXI AWCACHE  * for data write.  */
define|#
directive|define
name|UDMA_S2M_Q_CFG_AXI_AWCACHE_DATA_MASK
value|0x000000F0
define|#
directive|define
name|UDMA_S2M_Q_CFG_AXI_AWCACHE_DATA_SHIFT
value|4
comment|/*  * Enable operation of this queue.  * Start prefetch.  */
define|#
directive|define
name|UDMA_S2M_Q_CFG_EN_PREF
value|(1<< 16)
comment|/* Enables the reception of packets from the stream to this queue */
define|#
directive|define
name|UDMA_S2M_Q_CFG_EN_STREAM
value|(1<< 17)
comment|/* Allow prefetch of less than minimum prefetch burst size. */
define|#
directive|define
name|UDMA_S2M_Q_CFG_ALLOW_LT_MIN_PREF
value|(1<< 20)
comment|/*  * Configure the AXI AWCACHE  * for completion descriptor write  */
define|#
directive|define
name|UDMA_S2M_Q_CFG_AXI_AWCACHE_COMP_MASK
value|0x0F000000
define|#
directive|define
name|UDMA_S2M_Q_CFG_AXI_AWCACHE_COMP_SHIFT
value|24
comment|/*  * AXI QoS  * This value is used in AXI transactions associated with this queue and the  * prefetch and completion arbiters.  */
define|#
directive|define
name|UDMA_S2M_Q_CFG_AXI_QOS_MASK
value|0x70000000
define|#
directive|define
name|UDMA_S2M_Q_CFG_AXI_QOS_SHIFT
value|28
comment|/**** status register ****/
comment|/* Indicates how many entries are used in the Queue */
define|#
directive|define
name|UDMA_S2M_Q_STATUS_Q_USED_MASK
value|0x01FFFFFF
define|#
directive|define
name|UDMA_S2M_Q_STATUS_Q_USED_SHIFT
value|0
comment|/*  * prefetch status  * 0 â prefetch operation is stopped  * 1 â prefetch is operational  */
define|#
directive|define
name|UDMA_S2M_Q_STATUS_PREFETCH
value|(1<< 28)
comment|/*  * Queue receive status  * 0 -queue RX operation is stopped  * 1 â RX queue is active and processing packets  */
define|#
directive|define
name|UDMA_S2M_Q_STATUS_RX
value|(1<< 29)
comment|/*  * Indicates if the queue is full.  * (Used by the host when head pointer equals tail pointer)  */
define|#
directive|define
name|UDMA_S2M_Q_STATUS_Q_FULL
value|(1<< 31)
comment|/*  * S2M Descriptor Ring Base address [31:4].  * Value of the base address of the S2M descriptor ring  * [3:0] - 0 - 16B alignment is enforced  * ([11:4] should be 0 for 4KB alignment)  */
define|#
directive|define
name|UDMA_S2M_Q_RDRBP_LOW_ADDR_MASK
value|0xFFFFFFF0
define|#
directive|define
name|UDMA_S2M_Q_RDRBP_LOW_ADDR_SHIFT
value|4
comment|/**** RDRL register ****/
comment|/*  * Length of the descriptor ring.  * (descriptors)  * Associated with the ring base address ends at maximum burst size alignment  */
define|#
directive|define
name|UDMA_S2M_Q_RDRL_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_S2M_Q_RDRL_OFFSET_SHIFT
value|0
comment|/**** RDRHP register ****/
comment|/*  * Relative offset of the next descriptor that needs to be read into the  * prefetch FIFO.  * Incremented when the DMA reads valid descriptors from the host memory to the  * prefetch FIFO.  * Note that this is the offset in # of descriptors and not in byte address.  */
define|#
directive|define
name|UDMA_S2M_Q_RDRHP_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_S2M_Q_RDRHP_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_S2M_Q_RDRHP_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_S2M_Q_RDRHP_RING_ID_SHIFT
value|30
comment|/**** RDRTP_inc register ****/
comment|/*  * Increments the value in Q_RDRTP with the value written to this field in  * number of descriptors.  */
define|#
directive|define
name|UDMA_S2M_Q_RDRTP_INC_VAL_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_S2M_Q_RDRTP_INC_VAL_SHIFT
value|0
comment|/**** RDRTP register ****/
comment|/*  * Relative offset of the next free descriptor in the host memory.  * Note that this is the offset in # of descriptors and not in byte address.  */
define|#
directive|define
name|UDMA_S2M_Q_RDRTP_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_S2M_Q_RDRTP_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_S2M_Q_RDRTP_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_S2M_Q_RDRTP_RING_ID_SHIFT
value|30
comment|/**** RDCP register ****/
comment|/* Relative offset of the first descriptor in the prefetch FIFO.  */
define|#
directive|define
name|UDMA_S2M_Q_RDCP_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_S2M_Q_RDCP_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_S2M_Q_RDCP_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_S2M_Q_RDCP_RING_ID_SHIFT
value|30
comment|/*  * S2M Descriptor Ring Base address [31:4].  * Value of the base address of the S2M descriptor ring  * [3:0] - 0 - 16B alignment is enforced  * ([11:4] Must be 0 for 4KB alignment)  * NOTE:  * Length of the descriptor ring (in descriptors) associated with the ring base  * address ends at maximum burst size alignment  */
define|#
directive|define
name|UDMA_S2M_Q_RCRBP_LOW_ADDR_MASK
value|0xFFFFFFF0
define|#
directive|define
name|UDMA_S2M_Q_RCRBP_LOW_ADDR_SHIFT
value|4
comment|/**** RCRHP register ****/
comment|/*  * Relative offset of the next descriptor that needs to be updated by the  * completion controller.  * Note: This is in descriptors and not in byte address.  */
define|#
directive|define
name|UDMA_S2M_Q_RCRHP_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_S2M_Q_RCRHP_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_S2M_Q_RCRHP_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_S2M_Q_RCRHP_RING_ID_SHIFT
value|30
comment|/**** RCRHP_internal register ****/
comment|/*  * Relative offset of the next descriptor that needs to be updated by the  * completion controller.  * Note: This is in descriptors and not in byte address.  */
define|#
directive|define
name|UDMA_S2M_Q_RCRHP_INTERNAL_OFFSET_MASK
value|0x00FFFFFF
define|#
directive|define
name|UDMA_S2M_Q_RCRHP_INTERNAL_OFFSET_SHIFT
value|0
comment|/* Ring ID */
define|#
directive|define
name|UDMA_S2M_Q_RCRHP_INTERNAL_RING_ID_MASK
value|0xC0000000
define|#
directive|define
name|UDMA_S2M_Q_RCRHP_INTERNAL_RING_ID_SHIFT
value|30
comment|/**** comp_cfg register ****/
comment|/* Enables writing to the completion ring. */
define|#
directive|define
name|UDMA_S2M_Q_COMP_CFG_EN_COMP_RING_UPDATE
value|(1<< 0)
comment|/* Disables the completion coalescing function. */
define|#
directive|define
name|UDMA_S2M_Q_COMP_CFG_DIS_COMP_COAL
value|(1<< 1)
comment|/* Reserved */
define|#
directive|define
name|UDMA_S2M_Q_COMP_CFG_FIRST_PKT_PROMOTION
value|(1<< 2)
comment|/*  * Buffer 2 location.  * Determines the position of the buffer 2 length in the S2M completion  * descriptor.  * 0 - WORD 1 [31:16]  * 1 - WORD 2 [31:16]  */
define|#
directive|define
name|UDMA_S2M_Q_COMP_CFG_BUF2_LEN_LOCATION
value|(1<< 3)
comment|/**** pkt_cfg register ****/
comment|/* Header size. (bytes) */
define|#
directive|define
name|UDMA_S2M_Q_PKT_CFG_HDR_SPLIT_SIZE_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_S2M_Q_PKT_CFG_HDR_SPLIT_SIZE_SHIFT
value|0
comment|/* Force header split */
define|#
directive|define
name|UDMA_S2M_Q_PKT_CFG_FORCE_HDR_SPLIT
value|(1<< 16)
comment|/* Enable header split. */
define|#
directive|define
name|UDMA_S2M_Q_PKT_CFG_EN_HDR_SPLIT
value|(1<< 17)
comment|/**** qos_cfg register ****/
comment|/* Queue QoS */
define|#
directive|define
name|UDMA_S2M_QOS_CFG_Q_QOS_MASK
value|0x000000FF
define|#
directive|define
name|UDMA_S2M_QOS_CFG_Q_QOS_SHIFT
value|0
comment|/* Reset the tail pointer hardware. */
define|#
directive|define
name|UDMA_S2M_Q_SW_CTRL_RST_TAIL_PTR
value|(1<< 1)
comment|/* Reset the head pointer hardware. */
define|#
directive|define
name|UDMA_S2M_Q_SW_CTRL_RST_HEAD_PTR
value|(1<< 2)
comment|/* Reset the current pointer hardware. */
define|#
directive|define
name|UDMA_S2M_Q_SW_CTRL_RST_CURRENT_PTR
value|(1<< 3)
comment|/* Reset the prefetch FIFO */
define|#
directive|define
name|UDMA_S2M_Q_SW_CTRL_RST_PREFETCH
value|(1<< 4)
comment|/* Reset the queue */
define|#
directive|define
name|UDMA_S2M_Q_SW_CTRL_RST_Q
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
comment|/* __AL_HAL_UDMA_S2M_REG_H */
end_comment

end_unit

