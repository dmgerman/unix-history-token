begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @file   al_hal_udma_regs_gen.h  *  * @brief C Header file for the UDMA general registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_UDMA_GEN_REG_H
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_UDMA_GEN_REG_H
end_define

begin_include
include|#
directive|include
file|"al_hal_udma_iofic_regs.h"
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
name|udma_gen_dma_misc
block|{
comment|/* [0x0] Reserved register for the interrupt controller */
name|uint32_t
name|int_cfg
decl_stmt|;
comment|/* [0x4] Revision register */
name|uint32_t
name|revision
decl_stmt|;
comment|/* [0x8] Reserved for future use */
name|uint32_t
name|general_cfg_1
decl_stmt|;
comment|/* [0xc] Reserved for future use */
name|uint32_t
name|general_cfg_2
decl_stmt|;
comment|/* [0x10] Reserved for future use */
name|uint32_t
name|general_cfg_3
decl_stmt|;
comment|/* [0x14] Reserved for future use */
name|uint32_t
name|general_cfg_4
decl_stmt|;
comment|/* [0x18] General timer configuration */
name|uint32_t
name|general_cfg_5
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|57
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_gen_mailbox
block|{
comment|/* 	 * [0x0] Mailbox interrupt generator. 	 * Generates interrupt to neighbor DMA 	 */
name|uint32_t
name|interrupt
decl_stmt|;
comment|/* [0x4] Mailbox message data out */
name|uint32_t
name|msg_out
decl_stmt|;
comment|/* [0x8] Mailbox message data in */
name|uint32_t
name|msg_in
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
name|udma_gen_axi
block|{
comment|/* [0x0] Configuration of the AXI masters */
name|uint32_t
name|cfg_1
decl_stmt|;
comment|/* [0x4] Configuration of the AXI masters */
name|uint32_t
name|cfg_2
decl_stmt|;
comment|/* [0x8] Configuration of the AXI masters. Endianess configuration */
name|uint32_t
name|endian_cfg
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
name|udma_gen_sram_ctrl
block|{
comment|/* [0x0] Timing configuration */
name|uint32_t
name|timing
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_gen_vmid
block|{
comment|/* [0x0] VMID control */
name|uint32_t
name|cfg_vmid_0
decl_stmt|;
comment|/* [0x4] TX queue 0/1 VMID */
name|uint32_t
name|cfg_vmid_1
decl_stmt|;
comment|/* [0x8] TX queue 2/3 VMID */
name|uint32_t
name|cfg_vmid_2
decl_stmt|;
comment|/* [0xc] RX queue 0/1 VMID */
name|uint32_t
name|cfg_vmid_3
decl_stmt|;
comment|/* [0x10] RX queue 2/3 VMID */
name|uint32_t
name|cfg_vmid_4
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_gen_vmaddr
block|{
comment|/* [0x0] TX queue 0/1 VMADDR */
name|uint32_t
name|cfg_vmaddr_0
decl_stmt|;
comment|/* [0x4] TX queue 2/3 VMADDR */
name|uint32_t
name|cfg_vmaddr_1
decl_stmt|;
comment|/* [0x8] RX queue 0/1 VMADDR */
name|uint32_t
name|cfg_vmaddr_2
decl_stmt|;
comment|/* [0xc] RX queue 2/3 VMADDR */
name|uint32_t
name|cfg_vmaddr_3
decl_stmt|;
block|}
struct|;
struct|struct
name|udma_gen_vmpr
block|{
comment|/* [0x0] TX VMPR control */
name|uint32_t
name|cfg_vmpr_0
decl_stmt|;
comment|/* [0x4] TX VMPR Address High Regsiter */
name|uint32_t
name|cfg_vmpr_1
decl_stmt|;
comment|/* [0x8] TX queue VMID values */
name|uint32_t
name|cfg_vmpr_2
decl_stmt|;
comment|/* [0xc] TX queue VMID values */
name|uint32_t
name|cfg_vmpr_3
decl_stmt|;
comment|/* [0x10] RX VMPR control */
name|uint32_t
name|cfg_vmpr_4
decl_stmt|;
comment|/* [0x14] RX VMPR Buffer2 MSB address */
name|uint32_t
name|cfg_vmpr_5
decl_stmt|;
comment|/* [0x18] RX queue VMID values */
name|uint32_t
name|cfg_vmpr_6
decl_stmt|;
comment|/* [0x1c] RX queue BUF1 VMID values */
name|uint32_t
name|cfg_vmpr_7
decl_stmt|;
comment|/* [0x20] RX queue BUF2 VMID values */
name|uint32_t
name|cfg_vmpr_8
decl_stmt|;
comment|/* [0x24] RX queue Direct Data Placement VMID values */
name|uint32_t
name|cfg_vmpr_9
decl_stmt|;
comment|/* [0x28] RX VMPR BUF1 Address High Regsiter */
name|uint32_t
name|cfg_vmpr_10
decl_stmt|;
comment|/* [0x2c] RX VMPR BUF2 Address High Regsiter */
name|uint32_t
name|cfg_vmpr_11
decl_stmt|;
comment|/* [0x30] RX VMPR DDP Address High Regsiter */
name|uint32_t
name|cfg_vmpr_12
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
name|udma_gen_regs
block|{
name|struct
name|udma_iofic_regs
name|interrupt_regs
decl_stmt|;
comment|/* [0x0000] */
name|struct
name|udma_gen_dma_misc
name|dma_misc
decl_stmt|;
comment|/* [0x2080] */
name|struct
name|udma_gen_mailbox
name|mailbox
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x2180] */
name|struct
name|udma_gen_axi
name|axi
decl_stmt|;
comment|/* [0x2280] */
name|struct
name|udma_gen_sram_ctrl
name|sram_ctrl
index|[
literal|25
index|]
decl_stmt|;
comment|/* [0x2380] */
name|uint32_t
name|rsrvd_1
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|udma_gen_vmid
name|vmid
decl_stmt|;
comment|/* [0x23ec] */
name|struct
name|udma_gen_vmaddr
name|vmaddr
decl_stmt|;
comment|/* [0x2400] */
name|uint32_t
name|rsrvd_2
index|[
literal|252
index|]
decl_stmt|;
name|struct
name|udma_gen_vmpr
name|vmpr
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0x2800] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** int_cfg register ****/
comment|/*  * MSIX data width  * 1 - 64 bit  * 0 â 32 bit  */
define|#
directive|define
name|UDMA_GEN_DMA_MISC_INT_CFG_MSIX_64
value|(1<< 0)
comment|/* General configuration */
define|#
directive|define
name|UDMA_GEN_DMA_MISC_INT_CFG_RESERVED_3_1_MASK
value|0x0000000E
define|#
directive|define
name|UDMA_GEN_DMA_MISC_INT_CFG_RESERVED_3_1_SHIFT
value|1
comment|/* MSIx AXI QoS */
define|#
directive|define
name|UDMA_GEN_DMA_MISC_INT_CFG_MSIX_AXI_QOS_MASK
value|0x00000070
define|#
directive|define
name|UDMA_GEN_DMA_MISC_INT_CFG_MSIX_AXI_QOS_SHIFT
value|4
define|#
directive|define
name|UDMA_GEN_DMA_MISC_INT_CFG_RESERVED_31_7_MASK
value|0xFFFFFF80
define|#
directive|define
name|UDMA_GEN_DMA_MISC_INT_CFG_RESERVED_31_7_SHIFT
value|7
comment|/**** revision register ****/
comment|/* Design programming interface  revision ID */
define|#
directive|define
name|UDMA_GEN_DMA_MISC_REVISION_PROGRAMMING_ID_MASK
value|0x00000FFF
define|#
directive|define
name|UDMA_GEN_DMA_MISC_REVISION_PROGRAMMING_ID_SHIFT
value|0
comment|/* Design minor revision ID */
define|#
directive|define
name|UDMA_GEN_DMA_MISC_REVISION_MINOR_ID_MASK
value|0x00FFF000
define|#
directive|define
name|UDMA_GEN_DMA_MISC_REVISION_MINOR_ID_SHIFT
value|12
comment|/* Design major revision ID */
define|#
directive|define
name|UDMA_GEN_DMA_MISC_REVISION_MAJOR_ID_MASK
value|0xFF000000
define|#
directive|define
name|UDMA_GEN_DMA_MISC_REVISION_MAJOR_ID_SHIFT
value|24
comment|/**** Interrupt register ****/
comment|/* Generate interrupt to another DMA */
define|#
directive|define
name|UDMA_GEN_MAILBOX_INTERRUPT_SET
value|(1<< 0)
comment|/**** cfg_2 register ****/
comment|/*  * Enable arbitration promotion.  * Increment master priority after configured number of arbitration cycles  */
define|#
directive|define
name|UDMA_GEN_AXI_CFG_2_ARB_PROMOTION_MASK
value|0x0000000F
define|#
directive|define
name|UDMA_GEN_AXI_CFG_2_ARB_PROMOTION_SHIFT
value|0
comment|/**** endian_cfg register ****/
comment|/* Swap M2S descriptor read and completion descriptor write.  */
define|#
directive|define
name|UDMA_GEN_AXI_ENDIAN_CFG_SWAP_M2S_DESC
value|(1<< 0)
comment|/* Swap M2S data read. */
define|#
directive|define
name|UDMA_GEN_AXI_ENDIAN_CFG_SWAP_M2S_DATA
value|(1<< 1)
comment|/* Swap S2M descriptor read and completion descriptor write.  */
define|#
directive|define
name|UDMA_GEN_AXI_ENDIAN_CFG_SWAP_S2M_DESC
value|(1<< 2)
comment|/* Swap S2M data write. */
define|#
directive|define
name|UDMA_GEN_AXI_ENDIAN_CFG_SWAP_S2M_DATA
value|(1<< 3)
comment|/*  * Swap 32 or 64 bit mode:  * 0 - Swap groups of 4 bytes  * 1 - Swap groups of 8 bytes  */
define|#
directive|define
name|UDMA_GEN_AXI_ENDIAN_CFG_SWAP_64B_EN
value|(1<< 4)
comment|/**** timing register ****/
comment|/* Write margin */
define|#
directive|define
name|UDMA_GEN_SRAM_CTRL_TIMING_RMA_MASK
value|0x0000000F
define|#
directive|define
name|UDMA_GEN_SRAM_CTRL_TIMING_RMA_SHIFT
value|0
comment|/* Write margin enable */
define|#
directive|define
name|UDMA_GEN_SRAM_CTRL_TIMING_RMEA
value|(1<< 8)
comment|/* Read margin */
define|#
directive|define
name|UDMA_GEN_SRAM_CTRL_TIMING_RMB_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_GEN_SRAM_CTRL_TIMING_RMB_SHIFT
value|16
comment|/* Read margin enable */
define|#
directive|define
name|UDMA_GEN_SRAM_CTRL_TIMING_RMEB
value|(1<< 24)
comment|/**** cfg_vmid_0 register ****/
comment|/* For M2S queues 3:0, enable usage of the VMID from the buffer address 63:56 */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_TX_Q_VMID_DESC_EN_MASK
value|0x0000000F
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_TX_Q_VMID_DESC_EN_SHIFT
value|0
comment|/*  * For M2S queues 3:0, enable usage of the VMID from the configuration register  * (cfg_vmid_1/2 used for M2S queue_x)  */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_TX_Q_VMID_QUEUE_EN_MASK
value|0x000000F0
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_TX_Q_VMID_QUEUE_EN_SHIFT
value|4
comment|/* use VMID_n [7:0] from MSI-X Controller for MSI-X message  */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_MSIX_VMID_SEL
value|(1<< 8)
comment|/* Enable write to all VMID_n registers in the MSI-X Controller */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_MSIX_VMID_ACCESS_EN
value|(1<< 9)
comment|/* For S2M queues 3:0, enable usage of the VMID from the buffer address 63:56 */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_RX_Q_VMID_DESC_EN_MASK
value|0x000F0000
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_RX_Q_VMID_DESC_EN_SHIFT
value|16
comment|/*  * For S2M queues 3:0, enable usage of the VMID from the configuration register  * (cfg_vmid_3/4 used for M2S queue_x)  */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_RX_Q_VMID_QUEUE_EN_MASK
value|0x00F00000
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_0_RX_Q_VMID_QUEUE_EN_SHIFT
value|20
comment|/**** cfg_vmid_1 register ****/
comment|/* TX queue 0 VMID value */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_1_TX_Q_0_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_1_TX_Q_0_VMID_SHIFT
value|0
comment|/* TX queue 1 VMID value */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_1_TX_Q_1_VMID_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_1_TX_Q_1_VMID_SHIFT
value|16
comment|/**** cfg_vmid_2 register ****/
comment|/* TX queue 2 VMID value */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_2_TX_Q_2_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_2_TX_Q_2_VMID_SHIFT
value|0
comment|/* TX queue 3 VMID value */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_2_TX_Q_3_VMID_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_2_TX_Q_3_VMID_SHIFT
value|16
comment|/**** cfg_vmid_3 register ****/
comment|/* RX queue 0 VMID value */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_3_RX_Q_0_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_3_RX_Q_0_VMID_SHIFT
value|0
comment|/* RX queue 1 VMID value */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_3_RX_Q_1_VMID_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_3_RX_Q_1_VMID_SHIFT
value|16
comment|/**** cfg_vmid_4 register ****/
comment|/* RX queue 2 VMID value */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_4_RX_Q_2_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_4_RX_Q_2_VMID_SHIFT
value|0
comment|/* RX queue 3 VMID value */
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_4_RX_Q_3_VMID_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMID_CFG_VMID_4_RX_Q_3_VMID_SHIFT
value|16
comment|/**** cfg_vmaddr_0 register ****/
comment|/* TX queue 0 VMADDR value */
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_0_TX_Q_0_VMADDR_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_0_TX_Q_0_VMADDR_SHIFT
value|0
comment|/* TX queue 1 VMADDR value */
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_0_TX_Q_1_VMADDR_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_0_TX_Q_1_VMADDR_SHIFT
value|16
comment|/**** cfg_vmaddr_1 register ****/
comment|/* TX queue 2 VMADDR value */
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_1_TX_Q_2_VMADDR_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_1_TX_Q_2_VMADDR_SHIFT
value|0
comment|/* TX queue 3 VMADDR value */
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_1_TX_Q_3_VMADDR_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_1_TX_Q_3_VMADDR_SHIFT
value|16
comment|/**** cfg_vmaddr_2 register ****/
comment|/* RX queue 0 VMADDR value */
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_2_RX_Q_0_VMADDR_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_2_RX_Q_0_VMADDR_SHIFT
value|0
comment|/* RX queue 1 VMADDR value */
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_2_RX_Q_1_VMADDR_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_2_RX_Q_1_VMADDR_SHIFT
value|16
comment|/**** cfg_vmaddr_3 register ****/
comment|/* RX queue 2 VMADDR value */
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_3_RX_Q_2_VMADDR_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_3_RX_Q_2_VMADDR_SHIFT
value|0
comment|/* RX queue 3 VMADDR value */
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_3_RX_Q_3_VMADDR_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMADDR_CFG_VMADDR_3_RX_Q_3_VMADDR_SHIFT
value|16
comment|/**** cfg_vmpr_0 register ****/
comment|/* TX High Address Select Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_0_TX_Q_HISEL_MASK
value|0x0000003F
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_0_TX_Q_HISEL_SHIFT
value|0
comment|/* TX Data VMID Enable Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_0_TX_Q_DATA_VMID_EN
value|(1<< 7)
comment|/* TX Prefetch VMID Enable Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_0_TX_Q_PREF_VMID_EN
value|(1<< 28)
comment|/* TX Completions VMID Enable Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_0_TX_Q_CMPL_VMID_EN
value|(1<< 29)
comment|/**** cfg_vmpr_2 register ****/
comment|/* TX queue Prefetch VMID */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_2_TX_Q_PREF_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_2_TX_Q_PREF_VMID_SHIFT
value|0
comment|/* TX queue Completion VMID */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_2_TX_Q_CMPL_VMID_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_2_TX_Q_CMPL_VMID_SHIFT
value|16
comment|/**** cfg_vmpr_3 register ****/
comment|/* TX queue Data VMID */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_3_TX_Q_DATA_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_3_TX_Q_DATA_VMID_SHIFT
value|0
comment|/* TX queue Data VMID select */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_3_TX_Q_DATA_VMID_SEL_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_3_TX_Q_DATA_VMID_SEL_SHIFT
value|16
comment|/**** cfg_vmpr_4 register ****/
comment|/* RX Data Buffer1 - High Address Select Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_BUF1_HISEL_MASK
value|0x0000003F
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_BUF1_HISEL_SHIFT
value|0
comment|/* RX Data Buffer1 VMID Enable Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_BUF1_VMID_EN
value|(1<< 7)
comment|/* RX Data Buffer2 - High Address Select Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_BUF2_HISEL_MASK
value|0x00003F00
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_BUF2_HISEL_SHIFT
value|8
comment|/* RX Data Buffer2 VMID Enable Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_BUF2_VMID_EN
value|(1<< 15)
comment|/* RX Direct Data Placement - High Address Select Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_DDP_HISEL_MASK
value|0x003F0000
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_DDP_HISEL_SHIFT
value|16
comment|/* RX Direct Data Placement VMID Enable Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_DDP_VMID_EN
value|(1<< 23)
comment|/* RX Buffer 2 MSB address word selects per bytes, per queue */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_BUF2_MSB_ADDR_SEL_MASK
value|0x0F000000
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_BUF2_MSB_ADDR_SEL_SHIFT
value|24
comment|/* RX Prefetch VMID Enable Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_PREF_VMID_EN
value|(1<< 28)
comment|/* RX Completions VMID Enable Per Q */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_4_RX_Q_CMPL_VMID_EN
value|(1<< 29)
comment|/**** cfg_vmpr_6 register ****/
comment|/* RX queue Prefetch VMID */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_6_RX_Q_PREF_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_6_RX_Q_PREF_VMID_SHIFT
value|0
comment|/* RX queue Completion VMID */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_6_RX_Q_CMPL_VMID_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_6_RX_Q_CMPL_VMID_SHIFT
value|16
comment|/**** cfg_vmpr_7 register ****/
comment|/* RX queue Data Buffer 1 VMID */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_7_RX_Q_BUF1_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_7_RX_Q_BUF1_VMID_SHIFT
value|0
comment|/* RX queue Data Buffer 1 VMID select */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_7_RX_Q_BUF1_VMID_SEL_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_7_RX_Q_BUF1_VMID_SEL_SHIFT
value|16
comment|/**** cfg_vmpr_8 register ****/
comment|/* RX queue Data Buffer 2 VMID */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_8_RX_Q_BUF2_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_8_RX_Q_BUF2_VMID_SHIFT
value|0
comment|/* RX queue Data Buffer 2 VMID select */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_8_RX_Q_BUF2_VMID_SEL_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_8_RX_Q_BUF2_VMID_SEL_SHIFT
value|16
comment|/**** cfg_vmpr_9 register ****/
comment|/* RX queue DDP VMID */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_9_RX_Q_DDP_VMID_MASK
value|0x0000FFFF
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_9_RX_Q_DDP_VMID_SHIFT
value|0
comment|/* RX queue DDP VMID select */
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_9_RX_Q_DDP_VMID_SEL_MASK
value|0xFFFF0000
define|#
directive|define
name|UDMA_GEN_VMPR_CFG_VMPR_9_RX_Q_DDP_VMID_SEL_SHIFT
value|16
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
comment|/* __AL_HAL_UDMA_GEN_REG_H */
end_comment

end_unit

