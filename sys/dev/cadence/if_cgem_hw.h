begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2013 Thomas Skibo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Hardware and register defines for Cadence GEM Gigabit Ethernet  * controller such as the one used in Zynq-7000 SoC.  *  * Reference: Zynq-7000 All Programmable SoC Technical Reference Manual.  * (v1.4) November 16, 2012.  Xilinx doc UG585.  GEM is covered in Ch. 16  * and register definitions are in appendix B.18.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_CGEM_HW_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_CGEM_HW_H_
end_define

begin_comment
comment|/* Cadence GEM hardware register definitions. */
end_comment

begin_define
define|#
directive|define
name|CGEM_NET_CTRL
value|0x000
end_define

begin_comment
comment|/* Network Control */
end_comment

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_FLUSH_DPRAM_PKT
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_TX_PFC_PRI_PAUSE_FRAME
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_EN_PFC_PRI_PAUSE_RX
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_STORE_RX_TSTAMP
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_TX_ZEROQ_PAUSE_FRAME
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_TX_PAUSE_FRAME
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_TX_HALT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_START_TX
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_BACK_PRESSURE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_WREN_STAT_REGS
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_INCR_STAT_REGS
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_CLR_STAT_REGS
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_MGMT_PORT_EN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_TX_EN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_RX_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CTRL_LOOP_LOCAL
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG
value|0x004
end_define

begin_comment
comment|/* Netowrk Configuration */
end_comment

begin_define
define|#
directive|define
name|CGEM_NET_CFG_UNIDIR_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_IGNORE_IPG_RX_ER
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_RX_BAD_PREAMBLE
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_IPG_STRETCH_EN
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_SGMII_EN
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_IGNORE_RX_FCS
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_RX_HD_WHILE_TX
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_RX_CHKSUM_OFFLD_EN
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_DIS_CP_PAUSE_FRAME
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_DBUS_WIDTH_32
value|(0<<21)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_DBUS_WIDTH_64
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_DBUS_WIDTH_128
value|(2<<21)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_DBUS_WIDTH_MASK
value|(3<<21)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_8
value|(0<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_16
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_32
value|(2<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_48
value|(3<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_64
value|(4<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_96
value|(5<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_128
value|(6<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_224
value|(7<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MDC_CLK_DIV_MASK
value|(7<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_FCS_REMOVE
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_LEN_ERR_FRAME_DISC
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_RX_BUF_OFFSET_SHFT
value|14
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_RX_BUF_OFFSET_MASK
value|(3<<14)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_RX_BUF_OFFSET
parameter_list|(
name|n
parameter_list|)
value|((n)<<14)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_PAUSE_EN
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_RETRY_TEST
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_PCS_SEL
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_GIGE_EN
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_EXT_ADDR_MATCH_EN
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_1536RXEN
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_UNI_HASH_EN
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_MULTI_HASH_EN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_NO_BCAST
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_COPY_ALL
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_DISC_NON_VLAN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_FULL_DUPLEX
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_CFG_SPEED100
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_STAT
value|0x008
end_define

begin_comment
comment|/* Network Status */
end_comment

begin_define
define|#
directive|define
name|CGEM_NET_STAT_PFC_PRI_PAUSE_NEG
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_STAT_PCS_AUTONEG_PAUSE_TX_RES
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_STAT_PCS_AUTONEG_PAUSE_RX_RES
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_STAT_PCS_AUTONEG_DUP_RES
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_STAT_PHY_MGMT_IDLE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_STAT_MDIO_IN_PIN_STATUS
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CGEM_NET_STAT_PCS_LINK_STATE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_USER_IO
value|0x00C
end_define

begin_comment
comment|/* User I/O */
end_comment

begin_define
define|#
directive|define
name|CGEM_DMA_CFG
value|0x010
end_define

begin_comment
comment|/* DMA Config */
end_comment

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_DISC_WHEN_NO_AHB
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_RX_BUF_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_RX_BUF_SIZE_MASK
value|(0xff<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_RX_BUF_SIZE
parameter_list|(
name|sz
parameter_list|)
value|((((sz) + 63) / 64)<< 16)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_CHKSUM_GEN_OFFLOAD_EN
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_TX_PKTBUF_MEMSZ_SEL
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_RX_PKTBUF_MEMSZ_SEL_1K
value|(0<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_RX_PKTBUF_MEMSZ_SEL_2K
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_RX_PKTBUF_MEMSZ_SEL_4K
value|(2<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_RX_PKTBUF_MEMSZ_SEL_8K
value|(3<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_RX_PKTBUF_MEMSZ_SEL_MASK
value|(3<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_AHB_ENDIAN_SWAP_PKT_EN
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_AHB_ENDIAN_SWAP_MGMT_EN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_AHB_FIXED_BURST_LEN_1
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_AHB_FIXED_BURST_LEN_4
value|(4<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_AHB_FIXED_BURST_LEN_8
value|(8<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_AHB_FIXED_BURST_LEN_16
value|(16<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_DMA_CFG_AHB_FIXED_BURST_LEN_MASK
value|(0x1f<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT
value|0x014
end_define

begin_comment
comment|/* Transmit Status */
end_comment

begin_define
define|#
directive|define
name|CGEM_TX_STAT_HRESP_NOT_OK
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_LATE_COLL
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_UNDERRUN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_COMPLETE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_CORRUPT_AHB_ERR
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_GO
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_RETRY_LIMIT_EXC
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_COLLISION
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_USED_BIT_READ
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_STAT_ALL
value|0x1ff
end_define

begin_define
define|#
directive|define
name|CGEM_RX_QBAR
value|0x018
end_define

begin_comment
comment|/* Receive Buf Q Base Addr */
end_comment

begin_define
define|#
directive|define
name|CGEM_TX_QBAR
value|0x01C
end_define

begin_comment
comment|/* Transmit Buf Q Base Addr */
end_comment

begin_define
define|#
directive|define
name|CGEM_RX_STAT
value|0x020
end_define

begin_comment
comment|/* Receive Status */
end_comment

begin_define
define|#
directive|define
name|CGEM_RX_STAT_HRESP_NOT_OK
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CGEM_RX_STAT_OVERRUN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CGEM_RX_STAT_FRAME_RECD
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CGEM_RX_STAT_BUF_NOT_AVAIL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_RX_STAT_ALL
value|0xf
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_STAT
value|0x024
end_define

begin_comment
comment|/* Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|CGEM_INTR_EN
value|0x028
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|CGEM_INTR_DIS
value|0x02C
end_define

begin_comment
comment|/* Interrupt Disable */
end_comment

begin_define
define|#
directive|define
name|CGEM_INTR_MASK
value|0x030
end_define

begin_comment
comment|/* Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|CGEM_INTR_TSU_SEC_INCR
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_PDELAY_RESP_TX
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_PDELAY_REQ_TX
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_PDELAY_RESP_RX
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_PDELAY_REQ_RX
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_SYNX_TX
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_DELAY_REQ_TX
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_SYNC_RX
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_DELAY_REQ_RX
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_PARTNER_PG_RX
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_AUTONEG_COMPL
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_EXT_INTR
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_PAUSE_TX
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_PAUSE_ZERO
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_PAUSE_NONZEROQ_RX
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_HRESP_NOT_OK
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_RX_OVERRUN
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_LINK_CHNG
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_TX_COMPLETE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_TX_CORRUPT_AHB_ERR
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_RETRY_EX_LATE_COLLISION
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_TX_USED_READ
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_RX_USED_READ
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_RX_COMPLETE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_MGMT_SENT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CGEM_INTR_ALL
value|0x7FFFEFF
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT
value|0x034
end_define

begin_comment
comment|/* PHY Maintenenace */
end_comment

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_CLAUSE_22
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_OP_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_OP_MASK
value|(3<<28)
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_OP_READ
value|(2<<28)
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_OP_WRITE
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_PHY_ADDR_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_PHY_ADDR_MASK
value|(0x1f<<23)
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_REG_ADDR_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_REG_ADDR_MASK
value|(0x1f<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_MUST_10
value|(2<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_PHY_MAINT_DATA_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|CGEM_RX_PAUSEQ
value|0x038
end_define

begin_comment
comment|/* Received Pause Quantum */
end_comment

begin_define
define|#
directive|define
name|CGEM_TX_PAUSEQ
value|0x03C
end_define

begin_comment
comment|/* Transmit Puase Quantum */
end_comment

begin_define
define|#
directive|define
name|CGEM_HASH_BOT
value|0x080
end_define

begin_comment
comment|/* Hash Reg Bottom [31:0] */
end_comment

begin_define
define|#
directive|define
name|CGEM_HASH_TOP
value|0x084
end_define

begin_comment
comment|/* Hash Reg Top [63:32] */
end_comment

begin_define
define|#
directive|define
name|CGEM_SPEC_ADDR_LOW
parameter_list|(
name|n
parameter_list|)
value|(0x088+(n)*8)
end_define

begin_comment
comment|/* Specific Addr low */
end_comment

begin_define
define|#
directive|define
name|CGEM_SPEC_ADDR_HI
parameter_list|(
name|n
parameter_list|)
value|(0x08C+(n)*8)
end_define

begin_comment
comment|/* Specific Addr hi */
end_comment

begin_define
define|#
directive|define
name|CGEM_TYPE_ID_MATCH1
value|0x0A8
end_define

begin_comment
comment|/* Type ID Match 1 */
end_comment

begin_define
define|#
directive|define
name|CGEM_TYPE_ID_MATCH_COPY_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|CGEM_TYPE_ID_MATCH2
value|0x0AC
end_define

begin_comment
comment|/* Type ID Match 2 */
end_comment

begin_define
define|#
directive|define
name|CGEM_TYPE_ID_MATCH3
value|0x0B0
end_define

begin_comment
comment|/* Type ID Match 3 */
end_comment

begin_define
define|#
directive|define
name|CGEM_TYPE_ID_MATCH4
value|0x0B4
end_define

begin_comment
comment|/* Type ID Match 4 */
end_comment

begin_define
define|#
directive|define
name|CGEM_WAKE_ON_LAN
value|0x0B8
end_define

begin_comment
comment|/* Wake on LAN Register */
end_comment

begin_define
define|#
directive|define
name|CGEM_WOL_MULTI_HASH_EN
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|CGEM_WOL_SPEC_ADDR1_EN
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|CGEM_WOL_ARP_REQ_EN
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|CGEM_WOL_MAGIC_PKT_EN
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_WOL_ARP_REQ_IP_ADDR_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|CGEM_IPG_STRETCH
end_define

begin_comment
comment|/* IPG Stretch Register */
end_comment

begin_define
define|#
directive|define
name|CGEM_STACKED_VLAN
value|0x0C0
end_define

begin_comment
comment|/* Stacked VLAN Register */
end_comment

begin_define
define|#
directive|define
name|CGEM_STACKED_VLAN_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_PFC_PAUSE
value|0x0C4
end_define

begin_comment
comment|/* Transmit PFC Pause Reg */
end_comment

begin_define
define|#
directive|define
name|CGEM_TX_PFC_PAUSEQ_SEL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CGEM_TX_PFC_PAUSEQ_SEL_MASK
value|(0xff<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_TX_PFC_PAUSE_PRI_EN_VEC_VAL_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|CGEM_SPEC_ADDR1_MASK_BOT
value|0x0C8
end_define

begin_comment
comment|/* Specific Addr Mask1 [31:0]*/
end_comment

begin_define
define|#
directive|define
name|CGEM_SPEC_ADDR1_MASK_TOP
value|0x0CC
end_define

begin_comment
comment|/* Specific Addr Mask1[47:32]*/
end_comment

begin_define
define|#
directive|define
name|CGEM_MODULE_ID
value|0x0FC
end_define

begin_comment
comment|/* Module ID */
end_comment

begin_define
define|#
directive|define
name|CGEM_OCTETS_TX_BOT
value|0x100
end_define

begin_comment
comment|/* Octets xmitted [31:0] */
end_comment

begin_define
define|#
directive|define
name|CGEM_OCTETS_TX_TOP
value|0x104
end_define

begin_comment
comment|/* Octets xmitted [47:32] */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_TX
value|0x108
end_define

begin_comment
comment|/* Frames xmitted */
end_comment

begin_define
define|#
directive|define
name|CGEM_BCAST_FRAMES_TX
value|0x10C
end_define

begin_comment
comment|/* Broadcast Frames xmitted */
end_comment

begin_define
define|#
directive|define
name|CGEM_MULTI_FRAMES_TX
value|0x110
end_define

begin_comment
comment|/* Multicast Frames xmitted */
end_comment

begin_define
define|#
directive|define
name|CGEM_PAUSE_FRAMES_TX
value|0x114
end_define

begin_comment
comment|/* Pause Frames xmitted */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_64B_TX
value|0x118
end_define

begin_comment
comment|/* 64-Byte Frames xmitted */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_65_127B_TX
value|0x11C
end_define

begin_comment
comment|/* 65-127 Byte Frames xmitted*/
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_128_255B_TX
value|0x120
end_define

begin_comment
comment|/* 128-255 Byte Frames xmit */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_256_511B_TX
value|0x124
end_define

begin_comment
comment|/* 256-511 Byte Frames xmit */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_512_1023B_TX
value|0x128
end_define

begin_comment
comment|/* 512-1023 Byte frames xmit */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_1024_1518B_TX
value|0x12C
end_define

begin_comment
comment|/* 1024-1518 Byte frames xmit*/
end_comment

begin_define
define|#
directive|define
name|CGEM_TX_UNDERRUNS
value|0x134
end_define

begin_comment
comment|/* Transmit Under-runs */
end_comment

begin_define
define|#
directive|define
name|CGEM_SINGLE_COLL_FRAMES
value|0x138
end_define

begin_comment
comment|/* Single-Collision Frames */
end_comment

begin_define
define|#
directive|define
name|CGEM_MULTI_COLL_FRAMES
value|0x13C
end_define

begin_comment
comment|/* Multi-Collision Frames */
end_comment

begin_define
define|#
directive|define
name|CGEM_EXCESSIVE_COLL_FRAMES
value|0x140
end_define

begin_comment
comment|/* Excessive Collision Frames*/
end_comment

begin_define
define|#
directive|define
name|CGEM_LATE_COLL
value|0x144
end_define

begin_comment
comment|/* Late Collisions */
end_comment

begin_define
define|#
directive|define
name|CGEM_DEFERRED_TX_FRAMES
value|0x148
end_define

begin_comment
comment|/* Deferred Transmit Frames */
end_comment

begin_define
define|#
directive|define
name|CGEM_CARRIER_SENSE_ERRS
value|0x14C
end_define

begin_comment
comment|/* Carrier Sense Errors */
end_comment

begin_define
define|#
directive|define
name|CGEM_OCTETS_RX_BOT
value|0x150
end_define

begin_comment
comment|/* Octets Received [31:0] */
end_comment

begin_define
define|#
directive|define
name|CGEM_OCTETS_RX_TOP
value|0x154
end_define

begin_comment
comment|/* Octets Received [47:32] */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_RX
value|0x158
end_define

begin_comment
comment|/* Frames Received */
end_comment

begin_define
define|#
directive|define
name|CGEM_BCAST_FRAMES_RX
value|0x15C
end_define

begin_comment
comment|/* Broadcast Frames Received */
end_comment

begin_define
define|#
directive|define
name|CGEM_MULTI_FRAMES_RX
value|0x160
end_define

begin_comment
comment|/* Multicast Frames Received */
end_comment

begin_define
define|#
directive|define
name|CGEM_PAUSE_FRAMES_RX
value|0x164
end_define

begin_comment
comment|/* Pause Frames Reeived */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_64B_RX
value|0x168
end_define

begin_comment
comment|/* 64-Byte Frames Received */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_65_127B_RX
value|0x16C
end_define

begin_comment
comment|/* 65-127 Byte Frames Rx'd */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_128_255B_RX
value|0x170
end_define

begin_comment
comment|/* 128-255 Byte Frames Rx'd */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_256_511B_RX
value|0x174
end_define

begin_comment
comment|/* 256-511 Byte Frames Rx'd */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_512_1023B_RX
value|0x178
end_define

begin_comment
comment|/* 512-1023 Byte Frames Rx'd */
end_comment

begin_define
define|#
directive|define
name|CGEM_FRAMES_1024_1518B_RX
value|0x17C
end_define

begin_comment
comment|/* 1024-1518 Byte Frames Rx'd*/
end_comment

begin_define
define|#
directive|define
name|CGEM_UNDERSZ_RX
value|0x184
end_define

begin_comment
comment|/* Undersize Frames Rx'd */
end_comment

begin_define
define|#
directive|define
name|CGEM_OVERSZ_RX
value|0x188
end_define

begin_comment
comment|/* Oversize Frames Rx'd */
end_comment

begin_define
define|#
directive|define
name|CGEM_JABBERS_RX
value|0x18C
end_define

begin_comment
comment|/* Jabbers received */
end_comment

begin_define
define|#
directive|define
name|CGEM_FCS_ERRS
value|0x190
end_define

begin_comment
comment|/* Frame Check Sequence Errs */
end_comment

begin_define
define|#
directive|define
name|CGEM_LENGTH_FIELD_ERRS
value|0x194
end_define

begin_comment
comment|/* Length Firled Frame Errs */
end_comment

begin_define
define|#
directive|define
name|CGEM_RX_SYMBOL_ERRS
value|0x198
end_define

begin_comment
comment|/* Receive Symbol Errs */
end_comment

begin_define
define|#
directive|define
name|CGEM_ALIGN_ERRS
value|0x19C
end_define

begin_comment
comment|/* Alignment Errors */
end_comment

begin_define
define|#
directive|define
name|CGEM_RX_RESOURCE_ERRS
value|0x1A0
end_define

begin_comment
comment|/* Receive Resoure Errors */
end_comment

begin_define
define|#
directive|define
name|CGEM_RX_OVERRUN_ERRS
value|0x1A4
end_define

begin_comment
comment|/* Receive Overrun Errors */
end_comment

begin_define
define|#
directive|define
name|CGEM_IP_HDR_CKSUM_ERRS
value|0x1A8
end_define

begin_comment
comment|/* IP Hdr Checksum Errors */
end_comment

begin_define
define|#
directive|define
name|CGEM_TCP_CKSUM_ERRS
value|0x1AC
end_define

begin_comment
comment|/* TCP Checksum Errors */
end_comment

begin_define
define|#
directive|define
name|CGEM_UDP_CKSUM_ERRS
value|0x1B0
end_define

begin_comment
comment|/* UDP Checksum Errors */
end_comment

begin_define
define|#
directive|define
name|CGEM_TIMER_STROBE_S
value|0x1C8
end_define

begin_comment
comment|/* 1588 timer sync strobe s */
end_comment

begin_define
define|#
directive|define
name|CGEM_TIMER_STROBE_NS
value|0x1CC
end_define

begin_comment
comment|/* timer sync strobe ns */
end_comment

begin_define
define|#
directive|define
name|CGEM_TIMER_S
value|0x1D0
end_define

begin_comment
comment|/* 1588 timer seconds */
end_comment

begin_define
define|#
directive|define
name|CGEM_TIMER_NS
value|0x1D4
end_define

begin_comment
comment|/* 1588 timer ns */
end_comment

begin_define
define|#
directive|define
name|CGEM_ADJUST
value|0x1D8
end_define

begin_comment
comment|/* 1588 timer adjust */
end_comment

begin_define
define|#
directive|define
name|CGEM_INCR
value|0x1DC
end_define

begin_comment
comment|/* 1588 timer increment */
end_comment

begin_define
define|#
directive|define
name|CGEM_PTP_TX_S
value|0x1E0
end_define

begin_comment
comment|/* PTP Event Frame xmit secs */
end_comment

begin_define
define|#
directive|define
name|CGEM_PTP_TX_NS
value|0x1E4
end_define

begin_comment
comment|/* PTP Event Frame xmit ns */
end_comment

begin_define
define|#
directive|define
name|CGEM_PTP_RX_S
value|0x1E8
end_define

begin_comment
comment|/* PTP Event Frame rcv'd s */
end_comment

begin_define
define|#
directive|define
name|CGEM_PTP_RX_NS
value|0x1EC
end_define

begin_comment
comment|/* PTP Event Frame rcv'd ns */
end_comment

begin_define
define|#
directive|define
name|CGEM_PTP_PEER_TX_S
value|0x1F0
end_define

begin_comment
comment|/* PTP Peer Event xmit s */
end_comment

begin_define
define|#
directive|define
name|CGEM_PTP_PEER_TX_NS
value|0x1F4
end_define

begin_comment
comment|/* PTP Peer Event xmit ns */
end_comment

begin_define
define|#
directive|define
name|CGEM_PTP_PEER_RX_S
value|0x1F8
end_define

begin_comment
comment|/* PTP Peer Event rcv'd s */
end_comment

begin_define
define|#
directive|define
name|CGEM_PTP_PEER_RX_NS
value|0x1FC
end_define

begin_comment
comment|/* PTP Peer Event rcv'd ns */
end_comment

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2
value|0x284
end_define

begin_comment
comment|/* Design Configuration 2 */
end_comment

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_TX_PBUF_ADDR_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_TX_PBUF_ADDR_MASK
value|(0xf<<26)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_RX_PBUF_ADDR_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_RX_PBUF_ADDR_MASK
value|(0xf<<22)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_TX_PKT_BUF
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_RX_PKT_BUF
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_HPROT_VAL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_HPROT_VAL_MASK
value|(0xf<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG2_JUMBO_MAX_LEN_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG3
value|0x288
end_define

begin_comment
comment|/* Design Configuration 3 */
end_comment

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG3_RX_BASE2_FIFO_SZ_MASK
value|(0xffff<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG3_RX_BASE2_FIFO_SZ_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG3_RX_FIFO_SIZE_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG4
value|0x28C
end_define

begin_comment
comment|/* Design Configuration 4 */
end_comment

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG4_TX_BASE2_FIFO_SZ_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG4_TX_BASE2_FIFO_SZ_MASK
value|(0xffff<<16)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG4_TX_FIFO_SIZE_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5
value|0x290
end_define

begin_comment
comment|/* Design Configuration 5 */
end_comment

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_TSU_CLK
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_RX_BUF_LEN_DEF_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_RX_BUF_LEN_DEF_MASK
value|(0xff<<20)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_TX_PBUF_SIZE_DEF
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_RX_PBUF_SIZE_DEF_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_RX_PBUF_SIZE_DEF_MASK
value|(3<<17)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_ENDIAN_SWAP_DEF_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_ENDIAN_SWAP_DEF_MASK
value|(3<<15)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_MDC_CLOCK_DIV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_MDC_CLOCK_DIV_MASK
value|(7<<12)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_DMA_BUS_WIDTH_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_DMA_BUS_WIDTH_MASK
value|(3<<10)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_PHY_IDENT
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_TSU
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_TX_FIFO_CNT_WIDTH_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_TX_FIFO_CNT_WIDTH_MASK
value|(0xf<<4)
end_define

begin_define
define|#
directive|define
name|CGEM_DESIGN_CFG5_RX_FIFO_CNT_WIDTH_MASK
value|0xf
end_define

begin_comment
comment|/* Transmit Descriptors */
end_comment

begin_struct
struct|struct
name|cgem_tx_desc
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|ctl
decl_stmt|;
define|#
directive|define
name|CGEM_TXDESC_USED
value|(1<<31)
comment|/* done transmitting */
define|#
directive|define
name|CGEM_TXDESC_WRAP
value|(1<<30)
comment|/* end of descr ring */
define|#
directive|define
name|CGEM_TXDESC_RETRY_ERR
value|(1<<29)
define|#
directive|define
name|CGEM_TXDESC_AHB_ERR
value|(1<<27)
define|#
directive|define
name|CGEM_TXDESC_LATE_COLL
value|(1<<26)
define|#
directive|define
name|CGEM_TXDESC_CKSUM_GEN_STAT_MASK
value|(7<<20)
define|#
directive|define
name|CGEM_TXDESC_CKSUM_GEN_STAT_VLAN_HDR_ERR
value|(1<<20)
define|#
directive|define
name|CGEM_TXDESC_CKSUM_GEN_STAT_SNAP_HDR_ERR
value|(2<<20)
define|#
directive|define
name|CGEM_TXDESC_CKSUM_GEN_STAT_IP_HDR_ERR
value|(3<<20)
define|#
directive|define
name|CGEM_TXDESC_CKSUM_GEN_STAT_UNKNOWN_TYPE
value|(4<<20)
define|#
directive|define
name|CGEM_TXDESC_CKSUM_GEN_STAT_UNSUPP_FRAG
value|(5<<20)
define|#
directive|define
name|CGEM_TXDESC_CKSUM_GEN_STAT_NOT_TCPUDP
value|(6<<20)
define|#
directive|define
name|CGEM_TXDESC_CKSUM_GEN_STAT_SHORT_PKT
value|(7<<20)
define|#
directive|define
name|CGEM_TXDESC_NO_CRC_APPENDED
value|(1<<16)
define|#
directive|define
name|CGEM_TXDESC_LAST_BUF
value|(1<<15)
comment|/* last buf in frame */
define|#
directive|define
name|CGEM_TXDESC_LENGTH_MASK
value|0x3fff
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cgem_rx_desc
block|{
name|uint32_t
name|addr
decl_stmt|;
define|#
directive|define
name|CGEM_RXDESC_WRAP
value|(1<<1)
comment|/* goes in addr! */
define|#
directive|define
name|CGEM_RXDESC_OWN
value|(1<<0)
comment|/* buf filled */
name|uint32_t
name|ctl
decl_stmt|;
define|#
directive|define
name|CGEM_RXDESC_BCAST
value|(1<<31)
comment|/* all 1's broadcast */
define|#
directive|define
name|CGEM_RXDESC_MULTI_MATCH
value|(1<<30)
comment|/* mutlicast match */
define|#
directive|define
name|CGEM_RXDESC_UNICAST_MATCH
value|(1<<29)
define|#
directive|define
name|CGEM_RXDESC_EXTERNAL_MATCH
value|(1<<28)
comment|/* ext addr match */
define|#
directive|define
name|CGEM_RXDESC_SPEC_MATCH_SHIFT
value|25
define|#
directive|define
name|CGEM_RXDESC_SPEC_MATCH_MASK
value|(3<<25)
define|#
directive|define
name|CGEM_RXDESC_TYPE_ID_MATCH_SHIFT
value|22
define|#
directive|define
name|CGEM_RXDESC_TYPE_ID_MATCH_MASK
value|(3<<22)
define|#
directive|define
name|CGEM_RXDESC_CKSUM_STAT_MASK
value|(3<<22)
comment|/* same field above */
define|#
directive|define
name|CGEM_RXDESC_CKSUM_STAT_NONE
value|(0<<22)
define|#
directive|define
name|CGEM_RXDESC_CKSUM_STAT_IP_GOOD
value|(1<<22)
define|#
directive|define
name|CGEM_RXDESC_CKSUM_STAT_TCP_GOOD
value|(2<<22)
comment|/* and ip good */
define|#
directive|define
name|CGEM_RXDESC_CKSUM_STAT_UDP_GOOD
value|(3<<22)
comment|/* and ip good */
define|#
directive|define
name|CGEM_RXDESC_VLAN_DETECTED
value|(1<<21)
define|#
directive|define
name|CGEM_RXDESC_PRIO_DETECTED
value|(1<<20)
define|#
directive|define
name|CGEM_RXDESC_VLAN_PRIO_SHIFT
value|17
define|#
directive|define
name|CGEM_RXDESC_VLAN_PRIO_MASK
value|(7<<17)
define|#
directive|define
name|CGEM_RXDESC_CFI
value|(1<<16)
define|#
directive|define
name|CGEM_RXDESC_EOF
value|(1<<15)
comment|/* end of frame */
define|#
directive|define
name|CGEM_RXDESC_SOF
value|(1<<14)
comment|/* start of frame */
define|#
directive|define
name|CGEM_RXDESC_BAD_FCS
value|(1<<13)
define|#
directive|define
name|CGEM_RXDESC_LENGTH_MASK
value|0x1fff
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_CGEM_HW_H_ */
end_comment

end_unit

