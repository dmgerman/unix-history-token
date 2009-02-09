begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_udavreg.h,v 1.2 2003/09/04 15:17:39 tsutsui Exp $	*/
end_comment

begin_comment
comment|/*	$nabe: if_udavreg.h,v 1.2 2003/08/21 16:26:40 nabe Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003  *     Shingo WATANABE<nabe@nabechan.org>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_define
define|#
directive|define
name|UDAV_IFACE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|UDAV_CONFIG_INDEX
value|0
end_define

begin_comment
comment|/* config number 1 */
end_comment

begin_define
define|#
directive|define
name|UDAV_TX_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|UDAV_TIMEOUT
value|10000
end_define

begin_define
define|#
directive|define
name|UDAV_TX_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|UDAV_TIMEOUT
value|10000
end_define

begin_comment
comment|/* Packet length */
end_comment

begin_define
define|#
directive|define
name|UDAV_MIN_FRAME_LEN
value|60
end_define

begin_comment
comment|/* Request */
end_comment

begin_define
define|#
directive|define
name|UDAV_REQ_REG_READ
value|0x00
end_define

begin_comment
comment|/* Read from register(s) */
end_comment

begin_define
define|#
directive|define
name|UDAV_REQ_REG_WRITE
value|0x01
end_define

begin_comment
comment|/* Write to register(s) */
end_comment

begin_define
define|#
directive|define
name|UDAV_REQ_REG_WRITE1
value|0x03
end_define

begin_comment
comment|/* Write to a register */
end_comment

begin_define
define|#
directive|define
name|UDAV_REQ_MEM_READ
value|0x02
end_define

begin_comment
comment|/* Read from memory */
end_comment

begin_define
define|#
directive|define
name|UDAV_REQ_MEM_WRITE
value|0x05
end_define

begin_comment
comment|/* Write to memory */
end_comment

begin_define
define|#
directive|define
name|UDAV_REQ_MEM_WRITE1
value|0x07
end_define

begin_comment
comment|/* Write a byte to memory */
end_comment

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|UDAV_NCR
value|0x00
end_define

begin_comment
comment|/* Network Control Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_NCR_EXT_PHY
value|(1<<7)
end_define

begin_comment
comment|/* Select External PHY */
end_comment

begin_define
define|#
directive|define
name|UDAV_NCR_WAKEEN
value|(1<<6)
end_define

begin_comment
comment|/* Wakeup Event Enable */
end_comment

begin_define
define|#
directive|define
name|UDAV_NCR_FCOL
value|(1<<4)
end_define

begin_comment
comment|/* Force Collision Mode */
end_comment

begin_define
define|#
directive|define
name|UDAV_NCR_FDX
value|(1<<3)
end_define

begin_comment
comment|/* Full-Duplex Mode (RO on Int. PHY) */
end_comment

begin_define
define|#
directive|define
name|UDAV_NCR_LBK1
value|(1<<2)
end_define

begin_comment
comment|/* Lookback Mode */
end_comment

begin_define
define|#
directive|define
name|UDAV_NCR_LBK0
value|(1<<1)
end_define

begin_comment
comment|/* Lookback Mode */
end_comment

begin_define
define|#
directive|define
name|UDAV_NCR_RST
value|(1<<0)
end_define

begin_comment
comment|/* Software reset */
end_comment

begin_define
define|#
directive|define
name|UDAV_RCR
value|0x05
end_define

begin_comment
comment|/* RX Control Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_RCR_WTDIS
value|(1<<6)
end_define

begin_comment
comment|/* Watchdog Timer Disable */
end_comment

begin_define
define|#
directive|define
name|UDAV_RCR_DIS_LONG
value|(1<<5)
end_define

begin_comment
comment|/* Discard Long Packet(over 1522Byte) */
end_comment

begin_define
define|#
directive|define
name|UDAV_RCR_DIS_CRC
value|(1<<4)
end_define

begin_comment
comment|/* Discard CRC Error Packet */
end_comment

begin_define
define|#
directive|define
name|UDAV_RCR_ALL
value|(1<<3)
end_define

begin_comment
comment|/* Pass All Multicast */
end_comment

begin_define
define|#
directive|define
name|UDAV_RCR_RUNT
value|(1<<2)
end_define

begin_comment
comment|/* Pass Runt Packet */
end_comment

begin_define
define|#
directive|define
name|UDAV_RCR_PRMSC
value|(1<<1)
end_define

begin_comment
comment|/* Promiscuous Mode */
end_comment

begin_define
define|#
directive|define
name|UDAV_RCR_RXEN
value|(1<<0)
end_define

begin_comment
comment|/* RX Enable */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR
value|0x06
end_define

begin_comment
comment|/* RX Status Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_RF
value|(1<<7)
end_define

begin_comment
comment|/* Runt Frame */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_MF
value|(1<<6)
end_define

begin_comment
comment|/* Multicast Frame */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_LCS
value|(1<<5)
end_define

begin_comment
comment|/* Late Collision Seen */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_RWTO
value|(1<<4)
end_define

begin_comment
comment|/* Receive Watchdog Time-Out */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_PLE
value|(1<<3)
end_define

begin_comment
comment|/* Physical Layer Error */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_AE
value|(1<<2)
end_define

begin_comment
comment|/* Alignment Error */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_CE
value|(1<<1)
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_FOE
value|(1<<0)
end_define

begin_comment
comment|/* FIFO Overflow Error */
end_comment

begin_define
define|#
directive|define
name|UDAV_RSR_ERR
value|(UDAV_RSR_RF | UDAV_RSR_LCS |		\ 				    UDAV_RSR_RWTO | UDAV_RSR_PLE |	\ 				    UDAV_RSR_AE | UDAV_RSR_CE | UDAV_RSR_FOE)
end_define

begin_define
define|#
directive|define
name|UDAV_EPCR
value|0x0b
end_define

begin_comment
comment|/* EEPROM& PHY Control Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPCR_REEP
value|(1<<5)
end_define

begin_comment
comment|/* Reload EEPROM */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPCR_WEP
value|(1<<4)
end_define

begin_comment
comment|/* Write EEPROM enable */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPCR_EPOS
value|(1<<3)
end_define

begin_comment
comment|/* EEPROM or PHY Operation Select */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPCR_ERPRR
value|(1<<2)
end_define

begin_comment
comment|/* EEPROM/PHY Register Read Command */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPCR_ERPRW
value|(1<<1)
end_define

begin_comment
comment|/* EEPROM/PHY Register Write Command */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPCR_ERRE
value|(1<<0)
end_define

begin_comment
comment|/* EEPROM/PHY Access Status */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPAR
value|0x0c
end_define

begin_comment
comment|/* EEPROM& PHY Control Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPAR_PHY_ADR1
value|(1<<7)
end_define

begin_comment
comment|/* PHY Address bit 1 */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPAR_PHY_ADR0
value|(1<<6)
end_define

begin_comment
comment|/* PHY Address bit 0 */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPAR_EROA
value|(1<<0)
end_define

begin_comment
comment|/* EEPROM Word/PHY Register Address */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPAR_EROA_MASK
value|(0x1f)
end_define

begin_comment
comment|/* [5:0] */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPDRL
value|0x0d
end_define

begin_comment
comment|/* EEPROM& PHY Data Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_EPDRH
value|0x0e
end_define

begin_comment
comment|/* EEPROM& PHY Data Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_PAR0
value|0x10
end_define

begin_comment
comment|/* Ethernet Address, load from EEPROM */
end_comment

begin_define
define|#
directive|define
name|UDAV_PAR1
value|0x11
end_define

begin_comment
comment|/* Ethernet Address, load from EEPROM */
end_comment

begin_define
define|#
directive|define
name|UDAV_PAR2
value|0x12
end_define

begin_comment
comment|/* Ethernet Address, load from EEPROM */
end_comment

begin_define
define|#
directive|define
name|UDAV_PAR3
value|0x13
end_define

begin_comment
comment|/* Ethernet Address, load from EEPROM */
end_comment

begin_define
define|#
directive|define
name|UDAV_PAR4
value|0x14
end_define

begin_comment
comment|/* Ethernet Address, load from EEPROM */
end_comment

begin_define
define|#
directive|define
name|UDAV_PAR5
value|0x15
end_define

begin_comment
comment|/* Ethernet Address, load from EEPROM */
end_comment

begin_define
define|#
directive|define
name|UDAV_PAR
value|UDAV_PAR0
end_define

begin_define
define|#
directive|define
name|UDAV_MAR0
value|0x16
end_define

begin_comment
comment|/* Multicast Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_MAR1
value|0x17
end_define

begin_comment
comment|/* Multicast Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_MAR2
value|0x18
end_define

begin_comment
comment|/* Multicast Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_MAR3
value|0x19
end_define

begin_comment
comment|/* Multicast Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_MAR4
value|0x1a
end_define

begin_comment
comment|/* Multicast Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_MAR5
value|0x1b
end_define

begin_comment
comment|/* Multicast Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_MAR6
value|0x1c
end_define

begin_comment
comment|/* Multicast Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_MAR7
value|0x1d
end_define

begin_comment
comment|/* Multicast Register */
end_comment

begin_define
define|#
directive|define
name|UDAV_MAR
value|UDAV_MAR0
end_define

begin_define
define|#
directive|define
name|UDAV_GPCR
value|0x1e
end_define

begin_comment
comment|/* General purpose control register */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPCR_GEP_CNTL6
value|(1<<6)
end_define

begin_comment
comment|/* General purpose control 6 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPCR_GEP_CNTL5
value|(1<<5)
end_define

begin_comment
comment|/* General purpose control 5 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPCR_GEP_CNTL4
value|(1<<4)
end_define

begin_comment
comment|/* General purpose control 4 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPCR_GEP_CNTL3
value|(1<<3)
end_define

begin_comment
comment|/* General purpose control 3 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPCR_GEP_CNTL2
value|(1<<2)
end_define

begin_comment
comment|/* General purpose control 2 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPCR_GEP_CNTL1
value|(1<<1)
end_define

begin_comment
comment|/* General purpose control 1 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPCR_GEP_CNTL0
value|(1<<0)
end_define

begin_comment
comment|/* General purpose control 0 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPR
value|0x1f
end_define

begin_comment
comment|/* General purpose register */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPR_GEPIO6
value|(1<<6)
end_define

begin_comment
comment|/* General purpose 6 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPR_GEPIO5
value|(1<<5)
end_define

begin_comment
comment|/* General purpose 5 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPR_GEPIO4
value|(1<<4)
end_define

begin_comment
comment|/* General purpose 4 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPR_GEPIO3
value|(1<<3)
end_define

begin_comment
comment|/* General purpose 3 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPR_GEPIO2
value|(1<<2)
end_define

begin_comment
comment|/* General purpose 2 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPR_GEPIO1
value|(1<<1)
end_define

begin_comment
comment|/* General purpose 1 */
end_comment

begin_define
define|#
directive|define
name|UDAV_GPR_GEPIO0
value|(1<<0)
end_define

begin_comment
comment|/* General purpose 0 */
end_comment

begin_define
define|#
directive|define
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|usb2_ether_getmii(&(sc)->sc_ue)
end_define

begin_struct
struct|struct
name|udav_rxpkt
block|{
name|uint8_t
name|rxstat
decl_stmt|;
name|uint16_t
name|pktlen
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
block|{
name|UDAV_BULK_DT_WR
block|,
name|UDAV_BULK_DT_RD
block|,
name|UDAV_INTR_DT_RD
block|,
name|UDAV_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|udav_softc
block|{
name|struct
name|usb2_ether
name|sc_ue
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|usb2_xfer
modifier|*
name|sc_xfer
index|[
name|UDAV_N_TRANSFER
index|]
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|UDAV_FLAG_LINK
value|0x0001
define|#
directive|define
name|UDAV_FLAG_EXT_PHY
value|0x0040
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UDAV_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|UDAV_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|UDAV_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

end_unit

