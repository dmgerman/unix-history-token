begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005, 2006  *	Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|RAL_NOISE_FLOOR
value|-95
end_define

begin_define
define|#
directive|define
name|RAL_RSSI_CORR
value|120
end_define

begin_define
define|#
directive|define
name|RAL_RX_DESC_SIZE
value|(sizeof (struct ural_rx_desc))
end_define

begin_define
define|#
directive|define
name|RAL_TX_DESC_SIZE
value|(sizeof (struct ural_tx_desc))
end_define

begin_define
define|#
directive|define
name|RAL_FRAME_SIZE
value|0x780
end_define

begin_comment
comment|/* NOTE: using 0x980 does not work */
end_comment

begin_define
define|#
directive|define
name|RAL_CONFIG_NO
value|1
end_define

begin_define
define|#
directive|define
name|RAL_IFACE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RAL_VENDOR_REQUEST
value|0x01
end_define

begin_define
define|#
directive|define
name|RAL_WRITE_MAC
value|0x02
end_define

begin_define
define|#
directive|define
name|RAL_READ_MAC
value|0x03
end_define

begin_define
define|#
directive|define
name|RAL_WRITE_MULTI_MAC
value|0x06
end_define

begin_define
define|#
directive|define
name|RAL_READ_MULTI_MAC
value|0x07
end_define

begin_define
define|#
directive|define
name|RAL_READ_EEPROM
value|0x09
end_define

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR0
value|0x0400
end_define

begin_comment
comment|/* ASIC Version */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR1
value|0x0402
end_define

begin_comment
comment|/* System control */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR2
value|0x0404
end_define

begin_comment
comment|/* MAC addr0 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR3
value|0x0406
end_define

begin_comment
comment|/* MAC addr1 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR4
value|0x0408
end_define

begin_comment
comment|/* MAC addr2 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR5
value|0x040a
end_define

begin_comment
comment|/* BSSID0 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR6
value|0x040c
end_define

begin_comment
comment|/* BSSID1 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR7
value|0x040e
end_define

begin_comment
comment|/* BSSID2 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR8
value|0x0410
end_define

begin_comment
comment|/* Max frame length */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR9
value|0x0412
end_define

begin_comment
comment|/* Timer control */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR10
value|0x0414
end_define

begin_comment
comment|/* Slot time */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR11
value|0x0416
end_define

begin_comment
comment|/* IFS */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR12
value|0x0418
end_define

begin_comment
comment|/* EIFS */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR13
value|0x041a
end_define

begin_comment
comment|/* Power mode0 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR14
value|0x041c
end_define

begin_comment
comment|/* Power mode1 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR15
value|0x041e
end_define

begin_comment
comment|/* Power saving transition0 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR16
value|0x0420
end_define

begin_comment
comment|/* Power saving transition1 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR17
value|0x0422
end_define

begin_comment
comment|/* Power state control */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR18
value|0x0424
end_define

begin_comment
comment|/* Auto wake-up control */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR19
value|0x0426
end_define

begin_comment
comment|/* GPIO control */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR20
value|0x0428
end_define

begin_comment
comment|/* LED control0 */
end_comment

begin_define
define|#
directive|define
name|RAL_MAC_CSR22
value|0x042c
end_define

begin_comment
comment|/* XXX not documented */
end_comment

begin_comment
comment|/*  * Tx/Rx Registers.  */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR0
value|0x0440
end_define

begin_comment
comment|/* Security control */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR2
value|0x0444
end_define

begin_comment
comment|/* Rx control */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR5
value|0x044a
end_define

begin_comment
comment|/* CCK Tx BBP ID0 */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR6
value|0x044c
end_define

begin_comment
comment|/* CCK Tx BBP ID1 */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR7
value|0x044e
end_define

begin_comment
comment|/* OFDM Tx BBP ID0 */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR8
value|0x0450
end_define

begin_comment
comment|/* OFDM Tx BBP ID1 */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR10
value|0x0454
end_define

begin_comment
comment|/* Auto responder control */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR11
value|0x0456
end_define

begin_comment
comment|/* Auto responder basic rate */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR18
value|0x0464
end_define

begin_comment
comment|/* Beacon interval */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR19
value|0x0466
end_define

begin_comment
comment|/* Beacon/sync control */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR20
value|0x0468
end_define

begin_comment
comment|/* Beacon alignment */
end_comment

begin_define
define|#
directive|define
name|RAL_TXRX_CSR21
value|0x046a
end_define

begin_comment
comment|/* XXX not documented */
end_comment

begin_comment
comment|/*  * Security registers.  */
end_comment

begin_define
define|#
directive|define
name|RAL_SEC_CSR0
value|0x0480
end_define

begin_comment
comment|/* Shared key 0, word 0 */
end_comment

begin_comment
comment|/*  * PHY registers.  */
end_comment

begin_define
define|#
directive|define
name|RAL_PHY_CSR2
value|0x04c4
end_define

begin_comment
comment|/* Tx MAC configuration */
end_comment

begin_define
define|#
directive|define
name|RAL_PHY_CSR4
value|0x04c8
end_define

begin_comment
comment|/* Interface configuration */
end_comment

begin_define
define|#
directive|define
name|RAL_PHY_CSR5
value|0x04ca
end_define

begin_comment
comment|/* BBP Pre-Tx CCK */
end_comment

begin_define
define|#
directive|define
name|RAL_PHY_CSR6
value|0x04cc
end_define

begin_comment
comment|/* BBP Pre-Tx OFDM */
end_comment

begin_define
define|#
directive|define
name|RAL_PHY_CSR7
value|0x04ce
end_define

begin_comment
comment|/* BBP serial control */
end_comment

begin_define
define|#
directive|define
name|RAL_PHY_CSR8
value|0x04d0
end_define

begin_comment
comment|/* BBP serial status */
end_comment

begin_define
define|#
directive|define
name|RAL_PHY_CSR9
value|0x04d2
end_define

begin_comment
comment|/* RF serial control0 */
end_comment

begin_define
define|#
directive|define
name|RAL_PHY_CSR10
value|0x04d4
end_define

begin_comment
comment|/* RF serial control1 */
end_comment

begin_comment
comment|/*  * Statistics registers.  */
end_comment

begin_define
define|#
directive|define
name|RAL_STA_CSR0
value|0x04e0
end_define

begin_comment
comment|/* FCS error */
end_comment

begin_define
define|#
directive|define
name|RAL_DISABLE_RX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RAL_DROP_CRC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RAL_DROP_PHY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RAL_DROP_CTL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RAL_DROP_NOT_TO_ME
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RAL_DROP_TODS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RAL_DROP_BAD_VERSION
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RAL_DROP_MULTICAST
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RAL_DROP_BROADCAST
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RAL_SHORT_PREAMBLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RAL_RESET_ASIC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RAL_RESET_BBP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RAL_HOST_READY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RAL_ENABLE_TSF
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RAL_ENABLE_TSF_SYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 1)
end_define

begin_define
define|#
directive|define
name|RAL_ENABLE_TBCN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RAL_ENABLE_BEACON_GENERATOR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RAL_RF_AWAKE
value|(3<< 7)
end_define

begin_define
define|#
directive|define
name|RAL_BBP_AWAKE
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|RAL_BBP_WRITE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RAL_BBP_BUSY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RAL_RF1_AUTOTUNE
value|0x08000
end_define

begin_define
define|#
directive|define
name|RAL_RF3_AUTOTUNE
value|0x00040
end_define

begin_define
define|#
directive|define
name|RAL_RF_2522
value|0x00
end_define

begin_define
define|#
directive|define
name|RAL_RF_2523
value|0x01
end_define

begin_define
define|#
directive|define
name|RAL_RF_2524
value|0x02
end_define

begin_define
define|#
directive|define
name|RAL_RF_2525
value|0x03
end_define

begin_define
define|#
directive|define
name|RAL_RF_2525E
value|0x04
end_define

begin_define
define|#
directive|define
name|RAL_RF_2526
value|0x05
end_define

begin_comment
comment|/* dual-band RF */
end_comment

begin_define
define|#
directive|define
name|RAL_RF_5222
value|0x10
end_define

begin_define
define|#
directive|define
name|RAL_BBP_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|RAL_BBP_TX
value|2
end_define

begin_define
define|#
directive|define
name|RAL_BBP_RX
value|14
end_define

begin_define
define|#
directive|define
name|RAL_BBP_ANTA
value|0x00
end_define

begin_define
define|#
directive|define
name|RAL_BBP_DIVERSITY
value|0x01
end_define

begin_define
define|#
directive|define
name|RAL_BBP_ANTB
value|0x02
end_define

begin_define
define|#
directive|define
name|RAL_BBP_ANTMASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RAL_BBP_FLIPIQ
value|0x04
end_define

begin_define
define|#
directive|define
name|RAL_JAPAN_FILTER
value|0x08
end_define

begin_struct
struct|struct
name|ural_tx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RAL_TX_RETRY
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
define|#
directive|define
name|RAL_TX_MORE_FRAG
value|(1<< 8)
define|#
directive|define
name|RAL_TX_ACK
value|(1<< 9)
define|#
directive|define
name|RAL_TX_TIMESTAMP
value|(1<< 10)
define|#
directive|define
name|RAL_TX_OFDM
value|(1<< 11)
define|#
directive|define
name|RAL_TX_NEWSEQ
value|(1<< 12)
define|#
directive|define
name|RAL_TX_IFS_MASK
value|0x00006000
define|#
directive|define
name|RAL_TX_IFS_BACKOFF
value|(0<< 13)
define|#
directive|define
name|RAL_TX_IFS_SIFS
value|(1<< 13)
define|#
directive|define
name|RAL_TX_IFS_NEWBACKOFF
value|(2<< 13)
define|#
directive|define
name|RAL_TX_IFS_NONE
value|(3<< 13)
name|uint16_t
name|wme
decl_stmt|;
define|#
directive|define
name|RAL_LOGCWMAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 12)
define|#
directive|define
name|RAL_LOGCWMIN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 8)
define|#
directive|define
name|RAL_AIFSN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
define|#
directive|define
name|RAL_IVOFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3f))
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|plcp_signal
decl_stmt|;
name|uint8_t
name|plcp_service
decl_stmt|;
define|#
directive|define
name|RAL_PLCP_LENGEXT
value|0x80
name|uint8_t
name|plcp_length_lo
decl_stmt|;
name|uint8_t
name|plcp_length_hi
decl_stmt|;
name|uint32_t
name|iv
decl_stmt|;
name|uint32_t
name|eiv
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ural_rx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RAL_RX_CRC_ERROR
value|(1<< 5)
define|#
directive|define
name|RAL_RX_OFDM
value|(1<< 6)
define|#
directive|define
name|RAL_RX_PHY_ERROR
value|(1<< 7)
name|uint8_t
name|rssi
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|iv
decl_stmt|;
name|uint32_t
name|eiv
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|RAL_RF_LOBUSY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RAL_RF_BUSY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|RAL_RF_20BIT
value|(20<< 24)
end_define

begin_define
define|#
directive|define
name|RAL_RF1
value|0
end_define

begin_define
define|#
directive|define
name|RAL_RF2
value|2
end_define

begin_define
define|#
directive|define
name|RAL_RF3
value|1
end_define

begin_define
define|#
directive|define
name|RAL_RF4
value|3
end_define

begin_define
define|#
directive|define
name|RAL_EEPROM_ADDRESS
value|0x0004
end_define

begin_define
define|#
directive|define
name|RAL_EEPROM_TXPOWER
value|0x003c
end_define

begin_define
define|#
directive|define
name|RAL_EEPROM_CONFIG0
value|0x0016
end_define

begin_define
define|#
directive|define
name|RAL_EEPROM_BBP_BASE
value|0x001c
end_define

end_unit

