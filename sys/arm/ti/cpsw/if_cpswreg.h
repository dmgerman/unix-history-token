begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Damjan Marion<dmarion@Freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_CPSWREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_CPSWREG_H
end_define

begin_define
define|#
directive|define
name|CPSW_SS_OFFSET
value|0x0000
end_define

begin_define
define|#
directive|define
name|CPSW_SS_IDVER
value|(CPSW_SS_OFFSET + 0x00)
end_define

begin_define
define|#
directive|define
name|CPSW_SS_SOFT_RESET
value|(CPSW_SS_OFFSET + 0x08)
end_define

begin_define
define|#
directive|define
name|CPSW_SS_STAT_PORT_EN
value|(CPSW_SS_OFFSET + 0x0C)
end_define

begin_define
define|#
directive|define
name|CPSW_SS_PTYPE
value|(CPSW_SS_OFFSET + 0x10)
end_define

begin_define
define|#
directive|define
name|CPSW_SS_FLOW_CONTROL
value|(CPSW_SS_OFFSET + 0x24)
end_define

begin_define
define|#
directive|define
name|CPSW_PORT_OFFSET
value|0x0100
end_define

begin_define
define|#
directive|define
name|CPSW_PORT_P_MAX_BLKS
parameter_list|(
name|p
parameter_list|)
value|(CPSW_PORT_OFFSET + 0x08 + ((p) * 0x100))
end_define

begin_define
define|#
directive|define
name|CPSW_PORT_P_BLK_CNT
parameter_list|(
name|p
parameter_list|)
value|(CPSW_PORT_OFFSET + 0x0C + ((p) * 0x100))
end_define

begin_define
define|#
directive|define
name|CPSW_PORT_P_TX_PRI_MAP
parameter_list|(
name|p
parameter_list|)
value|(CPSW_PORT_OFFSET + 0x118 + ((p-1) * 0x100))
end_define

begin_define
define|#
directive|define
name|CPSW_PORT_P0_CPDMA_TX_PRI_MAP
value|(CPSW_PORT_OFFSET + 0x01C)
end_define

begin_define
define|#
directive|define
name|CPSW_PORT_P0_CPDMA_RX_CH_MAP
value|(CPSW_PORT_OFFSET + 0x020)
end_define

begin_define
define|#
directive|define
name|CPSW_PORT_P_SA_LO
parameter_list|(
name|p
parameter_list|)
value|(CPSW_PORT_OFFSET + 0x120 + ((p-1) * 0x100))
end_define

begin_define
define|#
directive|define
name|CPSW_PORT_P_SA_HI
parameter_list|(
name|p
parameter_list|)
value|(CPSW_PORT_OFFSET + 0x124 + ((p-1) * 0x100))
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_OFFSET
value|0x0800
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_TX_CONTROL
value|(CPSW_CPDMA_OFFSET + 0x04)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_TX_TEARDOWN
value|(CPSW_CPDMA_OFFSET + 0x08)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_CONTROL
value|(CPSW_CPDMA_OFFSET + 0x14)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_TEARDOWN
value|(CPSW_CPDMA_OFFSET + 0x18)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_SOFT_RESET
value|(CPSW_CPDMA_OFFSET + 0x1c)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_DMACONTROL
value|(CPSW_CPDMA_OFFSET + 0x20)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_DMASTATUS
value|(CPSW_CPDMA_OFFSET + 0x24)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_BUFFER_OFFSET
value|(CPSW_CPDMA_OFFSET + 0x28)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_TX_INTSTAT_RAW
value|(CPSW_CPDMA_OFFSET + 0x80)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_TX_INTSTAT_MASKED
value|(CPSW_CPDMA_OFFSET + 0x84)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_TX_INTMASK_SET
value|(CPSW_CPDMA_OFFSET + 0x88)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_TX_INTMASK_CLEAR
value|(CPSW_CPDMA_OFFSET + 0x8C)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_CPDMA_EOI_VECTOR
value|(CPSW_CPDMA_OFFSET + 0x94)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_INTSTAT_RAW
value|(CPSW_CPDMA_OFFSET + 0xA0)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_INTSTAT_MASKED
value|(CPSW_CPDMA_OFFSET + 0xA4)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_INTMASK_SET
value|(CPSW_CPDMA_OFFSET + 0xA8)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_INTMASK_CLEAR
value|(CPSW_CPDMA_OFFSET + 0xAc)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_DMA_INTSTAT_RAW
value|(CPSW_CPDMA_OFFSET + 0xB0)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_DMA_INTSTAT_MASKED
value|(CPSW_CPDMA_OFFSET + 0xB4)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_DMA_INTMASK_SET
value|(CPSW_CPDMA_OFFSET + 0xB8)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_DMA_INTMASK_CLEAR
value|(CPSW_CPDMA_OFFSET + 0xBC)
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_FREEBUFFER
parameter_list|(
name|p
parameter_list|)
value|(CPSW_CPDMA_OFFSET + 0x0e0 + ((p) * 0x04))
end_define

begin_define
define|#
directive|define
name|CPSW_STATS_OFFSET
value|0x0900
end_define

begin_define
define|#
directive|define
name|CPSW_STATERAM_OFFSET
value|0x0A00
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_TX_HDP
parameter_list|(
name|p
parameter_list|)
value|(CPSW_STATERAM_OFFSET + 0x00 + ((p) * 0x04))
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_HDP
parameter_list|(
name|p
parameter_list|)
value|(CPSW_STATERAM_OFFSET + 0x20 + ((p) * 0x04))
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_TX_CP
parameter_list|(
name|p
parameter_list|)
value|(CPSW_STATERAM_OFFSET + 0x40 + ((p) * 0x04))
end_define

begin_define
define|#
directive|define
name|CPSW_CPDMA_RX_CP
parameter_list|(
name|p
parameter_list|)
value|(CPSW_STATERAM_OFFSET + 0x60 + ((p) * 0x04))
end_define

begin_define
define|#
directive|define
name|CPSW_CPTS_OFFSET
value|0x0C00
end_define

begin_define
define|#
directive|define
name|CPSW_ALE_OFFSET
value|0x0D00
end_define

begin_define
define|#
directive|define
name|CPSW_ALE_CONTROL
value|(CPSW_ALE_OFFSET + 0x08)
end_define

begin_define
define|#
directive|define
name|CPSW_ALE_TBLCTL
value|(CPSW_ALE_OFFSET + 0x20)
end_define

begin_define
define|#
directive|define
name|CPSW_ALE_TBLW2
value|(CPSW_ALE_OFFSET + 0x34)
end_define

begin_define
define|#
directive|define
name|CPSW_ALE_TBLW1
value|(CPSW_ALE_OFFSET + 0x38)
end_define

begin_define
define|#
directive|define
name|CPSW_ALE_TBLW0
value|(CPSW_ALE_OFFSET + 0x3C)
end_define

begin_define
define|#
directive|define
name|CPSW_ALE_PORTCTL
parameter_list|(
name|p
parameter_list|)
value|(CPSW_ALE_OFFSET + 0x40 + ((p) * 0x04))
end_define

begin_comment
comment|/* SL1 is at 0x0D80, SL2 is at 0x0DC0 */
end_comment

begin_define
define|#
directive|define
name|CPSW_SL_OFFSET
value|0x0D80
end_define

begin_define
define|#
directive|define
name|CPSW_SL_MACCONTROL
parameter_list|(
name|p
parameter_list|)
value|(CPSW_SL_OFFSET + (0x40 * (p)) + 0x04)
end_define

begin_define
define|#
directive|define
name|CPSW_SL_MACSTATUS
parameter_list|(
name|p
parameter_list|)
value|(CPSW_SL_OFFSET + (0x40 * (p)) + 0x08)
end_define

begin_define
define|#
directive|define
name|CPSW_SL_SOFT_RESET
parameter_list|(
name|p
parameter_list|)
value|(CPSW_SL_OFFSET + (0x40 * (p)) + 0x0C)
end_define

begin_define
define|#
directive|define
name|CPSW_SL_RX_MAXLEN
parameter_list|(
name|p
parameter_list|)
value|(CPSW_SL_OFFSET + (0x40 * (p)) + 0x10)
end_define

begin_define
define|#
directive|define
name|CPSW_SL_RX_PAUSE
parameter_list|(
name|p
parameter_list|)
value|(CPSW_SL_OFFSET + (0x40 * (p)) + 0x18)
end_define

begin_define
define|#
directive|define
name|CPSW_SL_TX_PAUSE
parameter_list|(
name|p
parameter_list|)
value|(CPSW_SL_OFFSET + (0x40 * (p)) + 0x1C)
end_define

begin_define
define|#
directive|define
name|CPSW_SL_RX_PRI_MAP
parameter_list|(
name|p
parameter_list|)
value|(CPSW_SL_OFFSET + (0x40 * (p)) + 0x24)
end_define

begin_define
define|#
directive|define
name|MDIO_OFFSET
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDIOCONTROL
value|(MDIO_OFFSET + 0x04)
end_define

begin_define
define|#
directive|define
name|MDIOUSERACCESS0
value|(MDIO_OFFSET + 0x80)
end_define

begin_define
define|#
directive|define
name|MDIOUSERPHYSEL0
value|(MDIO_OFFSET + 0x84)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_OFFSET
value|0x1200
end_define

begin_define
define|#
directive|define
name|CPSW_WR_SOFT_RESET
value|(CPSW_WR_OFFSET + 0x04)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_CONTROL
value|(CPSW_WR_OFFSET + 0x08)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_INT_CONTROL
value|(CPSW_WR_OFFSET + 0x0c)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_C_RX_THRESH_EN
parameter_list|(
name|p
parameter_list|)
value|(CPSW_WR_OFFSET + (0x10 * (p)) + 0x10)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_C_RX_EN
parameter_list|(
name|p
parameter_list|)
value|(CPSW_WR_OFFSET + (0x10 * (p)) + 0x14)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_C_TX_EN
parameter_list|(
name|p
parameter_list|)
value|(CPSW_WR_OFFSET + (0x10 * (p)) + 0x18)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_C_MISC_EN
parameter_list|(
name|p
parameter_list|)
value|(CPSW_WR_OFFSET + (0x10 * (p)) + 0x1C)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_C_RX_THRESH_STAT
parameter_list|(
name|p
parameter_list|)
value|(CPSW_WR_OFFSET + (0x10 * (p)) + 0x40)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_C_RX_STAT
parameter_list|(
name|p
parameter_list|)
value|(CPSW_WR_OFFSET + (0x10 * (p)) + 0x44)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_C_TX_STAT
parameter_list|(
name|p
parameter_list|)
value|(CPSW_WR_OFFSET + (0x10 * (p)) + 0x48)
end_define

begin_define
define|#
directive|define
name|CPSW_WR_C_MISC_STAT
parameter_list|(
name|p
parameter_list|)
value|(CPSW_WR_OFFSET + (0x10 * (p)) + 0x4C)
end_define

begin_define
define|#
directive|define
name|CPSW_CPPI_RAM_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|CPSW_CPPI_RAM_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_SOP
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_EOP
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_OWNER
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_EOQ
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_TDOWNCMPLT
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_PKT_ERR_MASK
value|(3<< 4)
end_define

begin_struct
struct|struct
name|cpsw_cpdma_bd
block|{
specifier|volatile
name|uint32_t
name|next
decl_stmt|;
specifier|volatile
name|uint32_t
name|bufptr
decl_stmt|;
specifier|volatile
name|uint16_t
name|buflen
decl_stmt|;
specifier|volatile
name|uint16_t
name|bufoff
decl_stmt|;
specifier|volatile
name|uint16_t
name|pktlen
decl_stmt|;
specifier|volatile
name|uint16_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_IF_CPSWREG_H */
end_comment

end_unit

