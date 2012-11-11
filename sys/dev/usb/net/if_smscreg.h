begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012  *	Ben Gray<bgray@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_SMSCREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_SMSCREG_H_
end_define

begin_comment
comment|/*  * Definitions for the SMSC LAN9514 and LAN9514 USB to ethernet controllers.  *  * This information was gleaned from the SMSC driver in the linux kernel, where  * it is Copyrighted (C) 2007-2008 SMSC.  *  */
end_comment

begin_comment
comment|/**  * TRANSMIT FRAMES  * ---------------  *   Tx frames are prefixed with an 8-byte header which describes the frame  *  *         4 bytes      4 bytes           variable  *      +------------+------------+--- . . . . . . . . . . . . ---+  *      | TX_CTRL_0  | TX_CTRL_1  |  Ethernet frame data          |  *      +------------+------------+--- . . . . . . . . . . . . ---+  *  *   Where the headers have the following fields:  *  *      TX_CTRL_0<20:16>  Data offset  *      TX_CTRL_0<13>     First segment of frame indicator  *      TX_CTRL_0<12>     Last segment of frame indicator  *      TX_CTRL_0<10:0>   Buffer size (?)  *  *      TX_CTRL_1<14>     Perform H/W checksuming on IP packets   *      TX_CTRL_1<13>     Disable automatic ethernet CRC generation  *      TX_CTRL_1<12>     Disable padding (?)  *      TX_CTRL_1<10:0>   Packet byte length  *  */
end_comment

begin_define
define|#
directive|define
name|SMSC_TX_CTRL_0_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FUL)<< 16)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CTRL_0_FIRST_SEG
value|(0x1UL<< 13)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CTRL_0_LAST_SEG
value|(0x1UL<< 12)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CTRL_0_BUF_SIZE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x000007FFUL)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CTRL_1_CSUM_ENABLE
value|(0x1UL<< 14)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CTRL_1_CRC_DISABLE
value|(0x1UL<< 13)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CTRL_1_PADDING_DISABLE
value|(0x1UL<< 12)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CTRL_1_PKT_LENGTH
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x000007FFUL)
end_define

begin_comment
comment|/**  * RECEIVE FRAMES  * --------------  *   Rx frames are prefixed with an 4-byte status header which describes any  *   errors with the frame as well as things like the length  *  *         4 bytes             variable  *      +------------+--- . . . . . . . . . . . . ---+  *      |   RX_STAT  |  Ethernet frame data          |  *      +------------+--- . . . . . . . . . . . . ---+  *  *   Where the status header has the following fields:  *  *      RX_STAT<30>     Filter Fail  *      RX_STAT<29:16>  Frame Length  *      RX_STAT<15>     Error Summary  *      RX_STAT<13>     Broadcast Frame  *      RX_STAT<12>     Length Error  *      RX_STAT<11>     Runt Frame  *      RX_STAT<10>     Multicast Frame  *      RX_STAT<7>      Frame too long  *      RX_STAT<6>      Collision Seen  *      RX_STAT<5>      Frame Type  *      RX_STAT<4>      Receive Watchdog  *      RX_STAT<3>      Mii Error  *      RX_STAT<2>      Dribbling  *      RX_STAT<1>      CRC Error  *  */
end_comment

begin_define
define|#
directive|define
name|SMSC_RX_STAT_FILTER_FAIL
value|(0x1UL<< 30)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_FRM_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3FFFUL)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_ERROR
value|(0x1UL<< 15)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_BROADCAST
value|(0x1UL<< 13)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_LENGTH_ERROR
value|(0x1UL<< 12)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_RUNT
value|(0x1UL<< 11)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_MULTICAST
value|(0x1UL<< 10)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_FRM_TO_LONG
value|(0x1UL<< 7)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_COLLISION
value|(0x1UL<< 6)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_FRM_TYPE
value|(0x1UL<< 5)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_WATCHDOG
value|(0x1UL<< 4)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_MII_ERROR
value|(0x1UL<< 3)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_DRIBBLING
value|(0x1UL<< 2)
end_define

begin_define
define|#
directive|define
name|SMSC_RX_STAT_CRC_ERROR
value|(0x1UL<< 1)
end_define

begin_comment
comment|/**  * REGISTERS  *  */
end_comment

begin_define
define|#
directive|define
name|SMSC_ID_REV
value|0x000
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_STATUS
value|0x008
end_define

begin_define
define|#
directive|define
name|SMSC_RX_CFG
value|0x00C
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CFG
value|0x010
end_define

begin_define
define|#
directive|define
name|SMSC_HW_CFG
value|0x014
end_define

begin_define
define|#
directive|define
name|SMSC_PM_CTRL
value|0x020
end_define

begin_define
define|#
directive|define
name|SMSC_LED_GPIO_CFG
value|0x024
end_define

begin_define
define|#
directive|define
name|SMSC_GPIO_CFG
value|0x028
end_define

begin_define
define|#
directive|define
name|SMSC_AFC_CFG
value|0x02C
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD
value|0x030
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_DATA
value|0x034
end_define

begin_define
define|#
directive|define
name|SMSC_BURST_CAP
value|0x038
end_define

begin_define
define|#
directive|define
name|SMSC_GPIO_WAKE
value|0x064
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_CFG
value|0x068
end_define

begin_define
define|#
directive|define
name|SMSC_BULK_IN_DLY
value|0x06C
end_define

begin_define
define|#
directive|define
name|SMSC_MAC_CSR
value|0x100
end_define

begin_define
define|#
directive|define
name|SMSC_MAC_ADDRH
value|0x104
end_define

begin_define
define|#
directive|define
name|SMSC_MAC_ADDRL
value|0x108
end_define

begin_define
define|#
directive|define
name|SMSC_HASHH
value|0x10C
end_define

begin_define
define|#
directive|define
name|SMSC_HASHL
value|0x110
end_define

begin_define
define|#
directive|define
name|SMSC_MII_ADDR
value|0x114
end_define

begin_define
define|#
directive|define
name|SMSC_MII_DATA
value|0x118
end_define

begin_define
define|#
directive|define
name|SMSC_FLOW
value|0x11C
end_define

begin_define
define|#
directive|define
name|SMSC_VLAN1
value|0x120
end_define

begin_define
define|#
directive|define
name|SMSC_VLAN2
value|0x124
end_define

begin_define
define|#
directive|define
name|SMSC_WUFF
value|0x128
end_define

begin_define
define|#
directive|define
name|SMSC_WUCSR
value|0x12C
end_define

begin_define
define|#
directive|define
name|SMSC_COE_CTRL
value|0x130
end_define

begin_comment
comment|/* ID / Revision register */
end_comment

begin_define
define|#
directive|define
name|SMSC_ID_REV_CHIP_ID_MASK
value|0xFFFF0000UL
end_define

begin_define
define|#
directive|define
name|SMSC_ID_REV_CHIP_REV_MASK
value|0x0000FFFFUL
end_define

begin_define
define|#
directive|define
name|SMSC_RX_FIFO_FLUSH
value|(0x1UL<< 0)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CFG_ON
value|(0x1UL<< 2)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CFG_STOP
value|(0x1UL<< 1)
end_define

begin_define
define|#
directive|define
name|SMSC_TX_CFG_FIFO_FLUSH
value|(0x1UL<< 0)
end_define

begin_define
define|#
directive|define
name|SMSC_HW_CFG_BIR
value|(0x1UL<< 12)
end_define

begin_define
define|#
directive|define
name|SMSC_HW_CFG_LEDB
value|(0x1UL<< 11)
end_define

begin_define
define|#
directive|define
name|SMSC_HW_CFG_RXDOFF
value|(0x3UL<< 9)
end_define

begin_comment
comment|/* RX pkt alignment */
end_comment

begin_define
define|#
directive|define
name|SMSC_HW_CFG_DRP
value|(0x1UL<< 6)
end_define

begin_define
define|#
directive|define
name|SMSC_HW_CFG_MEF
value|(0x1UL<< 5)
end_define

begin_define
define|#
directive|define
name|SMSC_HW_CFG_LRST
value|(0x1UL<< 3)
end_define

begin_comment
comment|/* Lite reset */
end_comment

begin_define
define|#
directive|define
name|SMSC_HW_CFG_PSEL
value|(0x1UL<< 2)
end_define

begin_define
define|#
directive|define
name|SMSC_HW_CFG_BCE
value|(0x1UL<< 1)
end_define

begin_define
define|#
directive|define
name|SMSC_HW_CFG_SRST
value|(0x1UL<< 0)
end_define

begin_define
define|#
directive|define
name|SMSC_PM_CTRL_PHY_RST
value|(0x1UL<< 4)
end_define

begin_comment
comment|/* PHY reset */
end_comment

begin_define
define|#
directive|define
name|SMSC_LED_GPIO_CFG_SPD_LED
value|(0x1UL<< 24)
end_define

begin_define
define|#
directive|define
name|SMSC_LED_GPIO_CFG_LNK_LED
value|(0x1UL<< 20)
end_define

begin_define
define|#
directive|define
name|SMSC_LED_GPIO_CFG_FDX_LED
value|(0x1UL<< 16)
end_define

begin_comment
comment|/* Hi watermark = 15.5Kb (~10 mtu pkts) */
end_comment

begin_comment
comment|/* low watermark = 3k (~2 mtu pkts) */
end_comment

begin_comment
comment|/* backpressure duration = ~ 350us */
end_comment

begin_comment
comment|/* Apply FC on any frame. */
end_comment

begin_define
define|#
directive|define
name|AFC_CFG_DEFAULT
value|(0x00F830A1)
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD_BUSY
value|(0x1UL<< 31)
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD_MASK
value|(0x7UL<< 28)
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD_READ
value|(0x0UL<< 28)
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD_WRITE
value|(0x3UL<< 28)
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD_ERASE
value|(0x5UL<< 28)
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD_RELOAD
value|(0x7UL<< 28)
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD_TIMEOUT
value|(0x1UL<< 10)
end_define

begin_define
define|#
directive|define
name|SMSC_EEPROM_CMD_ADDR_MASK
value|0x000001FFUL
end_define

begin_comment
comment|/* MAC Control and Status Register */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_RCVOWN
value|(0x1UL<< 23)
end_define

begin_comment
comment|/* Half duplex */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_LOOPBK
value|(0x1UL<< 21)
end_define

begin_comment
comment|/* Loopback */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_FDPX
value|(0x1UL<< 20)
end_define

begin_comment
comment|/* Full duplex */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_MCPAS
value|(0x1UL<< 19)
end_define

begin_comment
comment|/* Multicast mode */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_PRMS
value|(0x1UL<< 18)
end_define

begin_comment
comment|/* Promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_INVFILT
value|(0x1UL<< 17)
end_define

begin_comment
comment|/* Inverse filtering */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_PASSBAD
value|(0x1UL<< 16)
end_define

begin_comment
comment|/* Pass on bad frames */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_HPFILT
value|(0x1UL<< 13)
end_define

begin_comment
comment|/* Hash filtering */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_BCAST
value|(0x1UL<< 11)
end_define

begin_comment
comment|/* Broadcast */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_TXEN
value|(0x1UL<< 3)
end_define

begin_comment
comment|/* TX enable */
end_comment

begin_define
define|#
directive|define
name|SMSC_MAC_CSR_RXEN
value|(0x1UL<< 2)
end_define

begin_comment
comment|/* RX enable */
end_comment

begin_comment
comment|/* Interrupt control register */
end_comment

begin_define
define|#
directive|define
name|SMSC_INTR_NTEP
value|(0x1UL<< 31)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_MACRTO
value|(0x1UL<< 19)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_TX_STOP
value|(0x1UL<< 17)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_RX_STOP
value|(0x1UL<< 16)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_PHY_INT
value|(0x1UL<< 15)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_TXE
value|(0x1UL<< 14)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_TDFU
value|(0x1UL<< 13)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_TDFO
value|(0x1UL<< 12)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_RXDF
value|(0x1UL<< 11)
end_define

begin_define
define|#
directive|define
name|SMSC_INTR_GPIOS
value|0x000007FFUL
end_define

begin_comment
comment|/* Phy MII interface register */
end_comment

begin_define
define|#
directive|define
name|SMSC_MII_WRITE
value|(0x1UL<< 1)
end_define

begin_define
define|#
directive|define
name|SMSC_MII_READ
value|(0x0UL<< 1)
end_define

begin_define
define|#
directive|define
name|SMSC_MII_BUSY
value|(0x1UL<< 0)
end_define

begin_comment
comment|/* H/W checksum register */
end_comment

begin_define
define|#
directive|define
name|SMSC_COE_CTRL_TX_EN
value|(0x1UL<< 16)
end_define

begin_comment
comment|/* Tx H/W csum enable */
end_comment

begin_define
define|#
directive|define
name|SMSC_COE_CTRL_RX_MODE
value|(0x1UL<< 1)
end_define

begin_define
define|#
directive|define
name|SMSC_COE_CTRL_RX_EN
value|(0x1UL<< 0)
end_define

begin_comment
comment|/* Rx H/W csum enable */
end_comment

begin_comment
comment|/* Registers on the phy, accessed via MII/MDIO */
end_comment

begin_define
define|#
directive|define
name|SMSC_PHY_INTR_STAT
value|(29)
end_define

begin_define
define|#
directive|define
name|SMSC_PHY_INTR_MASK
value|(30)
end_define

begin_define
define|#
directive|define
name|SMSC_PHY_INTR_ENERGY_ON
value|(0x1U<< 7)
end_define

begin_define
define|#
directive|define
name|SMSC_PHY_INTR_ANEG_COMP
value|(0x1U<< 6)
end_define

begin_define
define|#
directive|define
name|SMSC_PHY_INTR_REMOTE_FAULT
value|(0x1U<< 5)
end_define

begin_define
define|#
directive|define
name|SMSC_PHY_INTR_LINK_DOWN
value|(0x1U<< 4)
end_define

begin_comment
comment|/* USB Vendor Requests */
end_comment

begin_define
define|#
directive|define
name|SMSC_UR_WRITE_REG
value|0xA0
end_define

begin_define
define|#
directive|define
name|SMSC_UR_READ_REG
value|0xA1
end_define

begin_define
define|#
directive|define
name|SMSC_UR_GET_STATS
value|0xA2
end_define

begin_define
define|#
directive|define
name|SMSC_CONFIG_INDEX
value|0
end_define

begin_comment
comment|/* config number 1 */
end_comment

begin_define
define|#
directive|define
name|SMSC_IFACE_IDX
value|0
end_define

begin_comment
comment|/*  * USB endpoints.  */
end_comment

begin_enum
enum|enum
block|{
name|SMSC_BULK_DT_RD
block|,
name|SMSC_BULK_DT_WR
block|,
comment|/* the LAN9514 device does support interrupt endpoints, however I couldn't 	 * get then to work reliably and since they are unneeded (poll the mii 	 * status) they are unused. 	 * SMSC_INTR_DT_WR, 	 * SMSC_INTR_DT_RD, 	 */
name|SMSC_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|smsc_softc
block|{
name|struct
name|usb_ether
name|sc_ue
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|SMSC_N_TRANSFER
index|]
decl_stmt|;
name|int
name|sc_phyno
decl_stmt|;
comment|/* The following stores the settings in the mac control (MAC_CSR) register */
name|uint32_t
name|sc_mac_csr
decl_stmt|;
name|uint32_t
name|sc_rev_id
decl_stmt|;
name|uint32_t
name|sc_flags
decl_stmt|;
define|#
directive|define
name|SMSC_FLAG_LINK
value|0x0001
define|#
directive|define
name|SMSC_FLAG_LAN9514
value|0x1000
comment|/* LAN9514 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SMSC_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|SMSC_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|SMSC_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_SMSCREG_H_ */
end_comment

end_unit

