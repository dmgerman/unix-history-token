begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Register definitions for ADMtek Pegasus AN986 USB to Ethernet  * chip. The Pegasus uses a total of four USB endpoints: the control  * endpoint (0), a bulk read endpoint for receiving packets (1),  * a bulk write endpoint for sending packets (2) and an interrupt  * endpoint for passing RX and TX status (3). Endpoint 0 is used  * to read and write the ethernet module's registers. All registers  * are 8 bits wide.  *  * Packet transfer is done in 64 byte chunks. The last chunk in a  * transfer is denoted by having a length less that 64 bytes. For  * the RX case, the data includes an optional RX status word.  */
end_comment

begin_define
define|#
directive|define
name|AUE_UR_READREG
value|0xF0
end_define

begin_define
define|#
directive|define
name|AUE_UR_WRITEREG
value|0xF1
end_define

begin_define
define|#
directive|define
name|AUE_CONFIG_INDEX
value|0
end_define

begin_comment
comment|/* config number 1 */
end_comment

begin_define
define|#
directive|define
name|AUE_IFACE_IDX
value|0
end_define

begin_comment
comment|/*  * Note that while the ADMtek technically has four endpoints, the control  * endpoint (endpoint 0) is regarded as special by the USB code and drivers  * don't have direct access to it (we access it using usbd_do_request()  * when reading/writing registers.  Consequently, our endpoint indexes  * don't match those in the ADMtek Pegasus manual: we consider the RX data  * endpoint to be index 0 and work up from there.  */
end_comment

begin_enum
enum|enum
block|{
name|AUE_BULK_DT_WR
block|,
name|AUE_BULK_DT_RD
block|,
name|AUE_INTR_DT_RD
block|,
name|AUE_N_TRANSFER
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|AUE_INTR_PKTLEN
value|0x8
end_define

begin_define
define|#
directive|define
name|AUE_CTL0
value|0x00
end_define

begin_define
define|#
directive|define
name|AUE_CTL1
value|0x01
end_define

begin_define
define|#
directive|define
name|AUE_CTL2
value|0x02
end_define

begin_define
define|#
directive|define
name|AUE_MAR0
value|0x08
end_define

begin_define
define|#
directive|define
name|AUE_MAR1
value|0x09
end_define

begin_define
define|#
directive|define
name|AUE_MAR2
value|0x0A
end_define

begin_define
define|#
directive|define
name|AUE_MAR3
value|0x0B
end_define

begin_define
define|#
directive|define
name|AUE_MAR4
value|0x0C
end_define

begin_define
define|#
directive|define
name|AUE_MAR5
value|0x0D
end_define

begin_define
define|#
directive|define
name|AUE_MAR6
value|0x0E
end_define

begin_define
define|#
directive|define
name|AUE_MAR7
value|0x0F
end_define

begin_define
define|#
directive|define
name|AUE_MAR
value|AUE_MAR0
end_define

begin_define
define|#
directive|define
name|AUE_PAR0
value|0x10
end_define

begin_define
define|#
directive|define
name|AUE_PAR1
value|0x11
end_define

begin_define
define|#
directive|define
name|AUE_PAR2
value|0x12
end_define

begin_define
define|#
directive|define
name|AUE_PAR3
value|0x13
end_define

begin_define
define|#
directive|define
name|AUE_PAR4
value|0x14
end_define

begin_define
define|#
directive|define
name|AUE_PAR5
value|0x15
end_define

begin_define
define|#
directive|define
name|AUE_PAR
value|AUE_PAR0
end_define

begin_define
define|#
directive|define
name|AUE_PAUSE0
value|0x18
end_define

begin_define
define|#
directive|define
name|AUE_PAUSE1
value|0x19
end_define

begin_define
define|#
directive|define
name|AUE_PAUSE
value|AUE_PAUSE0
end_define

begin_define
define|#
directive|define
name|AUE_RX_FLOWCTL_CNT
value|0x1A
end_define

begin_define
define|#
directive|define
name|AUE_RX_FLOWCTL_FIFO
value|0x1B
end_define

begin_define
define|#
directive|define
name|AUE_REG_1D
value|0x1D
end_define

begin_define
define|#
directive|define
name|AUE_EE_REG
value|0x20
end_define

begin_define
define|#
directive|define
name|AUE_EE_DATA0
value|0x21
end_define

begin_define
define|#
directive|define
name|AUE_EE_DATA1
value|0x22
end_define

begin_define
define|#
directive|define
name|AUE_EE_DATA
value|AUE_EE_DATA0
end_define

begin_define
define|#
directive|define
name|AUE_EE_CTL
value|0x23
end_define

begin_define
define|#
directive|define
name|AUE_PHY_ADDR
value|0x25
end_define

begin_define
define|#
directive|define
name|AUE_PHY_DATA0
value|0x26
end_define

begin_define
define|#
directive|define
name|AUE_PHY_DATA1
value|0x27
end_define

begin_define
define|#
directive|define
name|AUE_PHY_DATA
value|AUE_PHY_DATA0
end_define

begin_define
define|#
directive|define
name|AUE_PHY_CTL
value|0x28
end_define

begin_define
define|#
directive|define
name|AUE_USB_STS
value|0x2A
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT0
value|0x2B
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT1
value|0x2C
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT
value|AUE_TXSTAT0
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT
value|0x2D
end_define

begin_define
define|#
directive|define
name|AUE_PKTLOST0
value|0x2E
end_define

begin_define
define|#
directive|define
name|AUE_PKTLOST1
value|0x2F
end_define

begin_define
define|#
directive|define
name|AUE_PKTLOST
value|AUE_PKTLOST0
end_define

begin_define
define|#
directive|define
name|AUE_REG_7B
value|0x7B
end_define

begin_define
define|#
directive|define
name|AUE_GPIO0
value|0x7E
end_define

begin_define
define|#
directive|define
name|AUE_GPIO1
value|0x7F
end_define

begin_define
define|#
directive|define
name|AUE_REG_81
value|0x81
end_define

begin_define
define|#
directive|define
name|AUE_CTL0_INCLUDE_RXCRC
value|0x01
end_define

begin_define
define|#
directive|define
name|AUE_CTL0_ALLMULTI
value|0x02
end_define

begin_define
define|#
directive|define
name|AUE_CTL0_STOP_BACKOFF
value|0x04
end_define

begin_define
define|#
directive|define
name|AUE_CTL0_RXSTAT_APPEND
value|0x08
end_define

begin_define
define|#
directive|define
name|AUE_CTL0_WAKEON_ENB
value|0x10
end_define

begin_define
define|#
directive|define
name|AUE_CTL0_RXPAUSE_ENB
value|0x20
end_define

begin_define
define|#
directive|define
name|AUE_CTL0_RX_ENB
value|0x40
end_define

begin_define
define|#
directive|define
name|AUE_CTL0_TX_ENB
value|0x80
end_define

begin_define
define|#
directive|define
name|AUE_CTL1_HOMELAN
value|0x04
end_define

begin_define
define|#
directive|define
name|AUE_CTL1_RESETMAC
value|0x08
end_define

begin_define
define|#
directive|define
name|AUE_CTL1_SPEEDSEL
value|0x10
end_define

begin_comment
comment|/* 0 = 10mbps, 1 = 100mbps */
end_comment

begin_define
define|#
directive|define
name|AUE_CTL1_DUPLEX
value|0x20
end_define

begin_comment
comment|/* 0 = half, 1 = full */
end_comment

begin_define
define|#
directive|define
name|AUE_CTL1_DELAYHOME
value|0x40
end_define

begin_define
define|#
directive|define
name|AUE_CTL2_EP3_CLR
value|0x01
end_define

begin_comment
comment|/* reading EP3 clrs status regs */
end_comment

begin_define
define|#
directive|define
name|AUE_CTL2_RX_BADFRAMES
value|0x02
end_define

begin_define
define|#
directive|define
name|AUE_CTL2_RX_PROMISC
value|0x04
end_define

begin_define
define|#
directive|define
name|AUE_CTL2_LOOPBACK
value|0x08
end_define

begin_define
define|#
directive|define
name|AUE_CTL2_EEPROMWR_ENB
value|0x10
end_define

begin_define
define|#
directive|define
name|AUE_CTL2_EEPROM_LOAD
value|0x20
end_define

begin_define
define|#
directive|define
name|AUE_EECTL_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|AUE_EECTL_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|AUE_EECTL_DONE
value|0x04
end_define

begin_define
define|#
directive|define
name|AUE_PHYCTL_PHYREG
value|0x1F
end_define

begin_define
define|#
directive|define
name|AUE_PHYCTL_WRITE
value|0x20
end_define

begin_define
define|#
directive|define
name|AUE_PHYCTL_READ
value|0x40
end_define

begin_define
define|#
directive|define
name|AUE_PHYCTL_DONE
value|0x80
end_define

begin_define
define|#
directive|define
name|AUE_USBSTS_SUSPEND
value|0x01
end_define

begin_define
define|#
directive|define
name|AUE_USBSTS_RESUME
value|0x02
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT0_JABTIMO
value|0x04
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT0_CARLOSS
value|0x08
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT0_NOCARRIER
value|0x10
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT0_LATECOLL
value|0x20
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT0_EXCESSCOLL
value|0x40
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT0_UNDERRUN
value|0x80
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT1_PKTCNT
value|0x0F
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT1_FIFO_EMPTY
value|0x40
end_define

begin_define
define|#
directive|define
name|AUE_TXSTAT1_FIFO_FULL
value|0x80
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT_OVERRUN
value|0x01
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT_PAUSE
value|0x02
end_define

begin_define
define|#
directive|define
name|AUE_GPIO_IN0
value|0x01
end_define

begin_define
define|#
directive|define
name|AUE_GPIO_OUT0
value|0x02
end_define

begin_define
define|#
directive|define
name|AUE_GPIO_SEL0
value|0x04
end_define

begin_define
define|#
directive|define
name|AUE_GPIO_IN1
value|0x08
end_define

begin_define
define|#
directive|define
name|AUE_GPIO_OUT1
value|0x10
end_define

begin_define
define|#
directive|define
name|AUE_GPIO_SEL1
value|0x20
end_define

begin_define
define|#
directive|define
name|AUE_TIMEOUT
value|100
end_define

begin_comment
comment|/* 10*ms */
end_comment

begin_define
define|#
directive|define
name|AUE_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT_MCAST
value|0x01
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT_GIANT
value|0x02
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT_RUNT
value|0x04
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT_CRCERR
value|0x08
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT_DRIBBLE
value|0x10
end_define

begin_define
define|#
directive|define
name|AUE_RXSTAT_MASK
value|0x1E
end_define

begin_define
define|#
directive|define
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|uether_getmii(&(sc)->sc_ue)
end_define

begin_struct
struct|struct
name|aue_intrpkt
block|{
name|uint8_t
name|aue_txstat0
decl_stmt|;
name|uint8_t
name|aue_txstat1
decl_stmt|;
name|uint8_t
name|aue_rxstat
decl_stmt|;
name|uint8_t
name|aue_rxlostpkt0
decl_stmt|;
name|uint8_t
name|aue_rxlostpkt1
decl_stmt|;
name|uint8_t
name|aue_wakeupstat
decl_stmt|;
name|uint8_t
name|aue_rsvd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aue_rxpkt
block|{
name|uint16_t
name|aue_pktlen
decl_stmt|;
name|uint8_t
name|aue_rxstat
decl_stmt|;
name|uint8_t
name|pad
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|aue_softc
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
name|AUE_N_TRANSFER
index|]
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|AUE_FLAG_LSYS
value|0x0001
comment|/* use Linksys reset */
define|#
directive|define
name|AUE_FLAG_PNA
value|0x0002
comment|/* has Home PNA */
define|#
directive|define
name|AUE_FLAG_PII
value|0x0004
comment|/* Pegasus II chip */
define|#
directive|define
name|AUE_FLAG_LINK
value|0x0008
comment|/* wait for link to come up */
define|#
directive|define
name|AUE_FLAG_VER_2
value|0x0200
comment|/* chip is version 2 */
define|#
directive|define
name|AUE_FLAG_DUAL_PHY
value|0x0400
comment|/* chip has two transcivers */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AUE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|AUE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|AUE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

end_unit

