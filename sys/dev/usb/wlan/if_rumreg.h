begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005, 2006 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2006 Niall O'Higgins<niallo@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|RT2573_NOISE_FLOOR
value|-95
end_define

begin_define
define|#
directive|define
name|RT2573_TX_DESC_SIZE
value|(sizeof (struct rum_tx_desc))
end_define

begin_define
define|#
directive|define
name|RT2573_RX_DESC_SIZE
value|(sizeof (struct rum_rx_desc))
end_define

begin_define
define|#
directive|define
name|RT2573_CONFIG_NO
value|1
end_define

begin_define
define|#
directive|define
name|RT2573_IFACE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RT2573_MCU_CNTL
value|0x01
end_define

begin_define
define|#
directive|define
name|RT2573_WRITE_MAC
value|0x02
end_define

begin_define
define|#
directive|define
name|RT2573_READ_MAC
value|0x03
end_define

begin_define
define|#
directive|define
name|RT2573_WRITE_MULTI_MAC
value|0x06
end_define

begin_define
define|#
directive|define
name|RT2573_READ_MULTI_MAC
value|0x07
end_define

begin_define
define|#
directive|define
name|RT2573_READ_EEPROM
value|0x09
end_define

begin_define
define|#
directive|define
name|RT2573_WRITE_LED
value|0x0a
end_define

begin_comment
comment|/*  * WME registers.  */
end_comment

begin_define
define|#
directive|define
name|RT2573_AIFSN_CSR
value|0x0400
end_define

begin_define
define|#
directive|define
name|RT2573_CWMIN_CSR
value|0x0404
end_define

begin_define
define|#
directive|define
name|RT2573_CWMAX_CSR
value|0x0408
end_define

begin_define
define|#
directive|define
name|RT2573_TXOP01_CSR
value|0x040C
end_define

begin_define
define|#
directive|define
name|RT2573_TXOP23_CSR
value|0x0410
end_define

begin_define
define|#
directive|define
name|RT2573_MCU_CODE_BASE
value|0x0800
end_define

begin_comment
comment|/*  * H/w encryption/decryption support  */
end_comment

begin_define
define|#
directive|define
name|KEY_SIZE
value|(IEEE80211_KEYBUF_SIZE + IEEE80211_MICBUF_SIZE)
end_define

begin_define
define|#
directive|define
name|RT2573_ADDR_MAX
value|64
end_define

begin_define
define|#
directive|define
name|RT2573_SKEY_MAX
value|4
end_define

begin_define
define|#
directive|define
name|RT2573_SKEY
parameter_list|(
name|vap
parameter_list|,
name|kidx
parameter_list|)
value|(0x1000 + ((vap) * RT2573_SKEY_MAX + \ 	(kidx)) * KEY_SIZE)
end_define

begin_define
define|#
directive|define
name|RT2573_PKEY
parameter_list|(
name|id
parameter_list|)
value|(0x1200 + (id) * KEY_SIZE)
end_define

begin_define
define|#
directive|define
name|RT2573_ADDR_ENTRY
parameter_list|(
name|id
parameter_list|)
value|(0x1a00 + (id) * 8)
end_define

begin_comment
comment|/*  * Shared memory area  */
end_comment

begin_define
define|#
directive|define
name|RT2573_HW_BCN_BASE
parameter_list|(
name|id
parameter_list|)
value|(0x2400 + (id) * 0x100)
end_define

begin_comment
comment|/*  * Control and status registers.  */
end_comment

begin_define
define|#
directive|define
name|RT2573_MAC_CSR0
value|0x3000
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR1
value|0x3004
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR2
value|0x3008
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR3
value|0x300c
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR4
value|0x3010
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR5
value|0x3014
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR6
value|0x3018
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR7
value|0x301c
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR8
value|0x3020
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR9
value|0x3024
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR10
value|0x3028
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR11
value|0x302c
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR12
value|0x3030
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR13
value|0x3034
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR14
value|0x3038
end_define

begin_define
define|#
directive|define
name|RT2573_MAC_CSR15
value|0x303c
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR0
value|0x3040
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR1
value|0x3044
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR2
value|0x3048
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR3
value|0x304c
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR4
value|0x3050
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR5
value|0x3054
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR6
value|0x3058
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR7
value|0x305c
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR8
value|0x3060
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR9
value|0x3064
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR10
value|0x3068
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR11
value|0x306c
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR12
value|0x3070
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR13
value|0x3074
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR14
value|0x3078
end_define

begin_define
define|#
directive|define
name|RT2573_TXRX_CSR15
value|0x307c
end_define

begin_define
define|#
directive|define
name|RT2573_PHY_CSR0
value|0x3080
end_define

begin_define
define|#
directive|define
name|RT2573_PHY_CSR1
value|0x3084
end_define

begin_define
define|#
directive|define
name|RT2573_PHY_CSR2
value|0x3088
end_define

begin_define
define|#
directive|define
name|RT2573_PHY_CSR3
value|0x308c
end_define

begin_define
define|#
directive|define
name|RT2573_PHY_CSR4
value|0x3090
end_define

begin_define
define|#
directive|define
name|RT2573_PHY_CSR5
value|0x3094
end_define

begin_define
define|#
directive|define
name|RT2573_PHY_CSR6
value|0x3098
end_define

begin_define
define|#
directive|define
name|RT2573_PHY_CSR7
value|0x309c
end_define

begin_define
define|#
directive|define
name|RT2573_SEC_CSR0
value|0x30a0
end_define

begin_define
define|#
directive|define
name|RT2573_SEC_CSR1
value|0x30a4
end_define

begin_define
define|#
directive|define
name|RT2573_SEC_CSR2
value|0x30a8
end_define

begin_define
define|#
directive|define
name|RT2573_SEC_CSR3
value|0x30ac
end_define

begin_define
define|#
directive|define
name|RT2573_SEC_CSR4
value|0x30b0
end_define

begin_define
define|#
directive|define
name|RT2573_SEC_CSR5
value|0x30b4
end_define

begin_define
define|#
directive|define
name|RT2573_STA_CSR0
value|0x30c0
end_define

begin_define
define|#
directive|define
name|RT2573_STA_CSR1
value|0x30c4
end_define

begin_define
define|#
directive|define
name|RT2573_STA_CSR2
value|0x30c8
end_define

begin_define
define|#
directive|define
name|RT2573_STA_CSR3
value|0x30cc
end_define

begin_define
define|#
directive|define
name|RT2573_STA_CSR4
value|0x30d0
end_define

begin_define
define|#
directive|define
name|RT2573_STA_CSR5
value|0x30d4
end_define

begin_comment
comment|/* possible values for register RT2573_ADDR_MODE */
end_comment

begin_define
define|#
directive|define
name|RT2573_MODE_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|RT2573_MODE_NOSEC
value|0
end_define

begin_define
define|#
directive|define
name|RT2573_MODE_WEP40
value|1
end_define

begin_define
define|#
directive|define
name|RT2573_MODE_WEP104
value|2
end_define

begin_define
define|#
directive|define
name|RT2573_MODE_TKIP
value|3
end_define

begin_define
define|#
directive|define
name|RT2573_MODE_AES_CCMP
value|4
end_define

begin_define
define|#
directive|define
name|RT2573_MODE_CKIP40
value|5
end_define

begin_define
define|#
directive|define
name|RT2573_MODE_CKIP104
value|6
end_define

begin_comment
comment|/* possible flags for register RT2573_MAC_CSR1 */
end_comment

begin_define
define|#
directive|define
name|RT2573_RESET_ASIC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2573_RESET_BBP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2573_HOST_READY
value|(1<< 2)
end_define

begin_comment
comment|/* possible flags for register MAC_CSR5 */
end_comment

begin_define
define|#
directive|define
name|RT2573_NUM_BSSID_MSK
parameter_list|(
name|n
parameter_list|)
value|(((n * 3)& 3)<< 16)
end_define

begin_comment
comment|/* possible flags for register TXRX_CSR0 */
end_comment

begin_comment
comment|/* Tx filter flags are in the low 16 bits */
end_comment

begin_define
define|#
directive|define
name|RT2573_AUTO_TX_SEQ
value|(1<< 15)
end_define

begin_comment
comment|/* Rx filter flags are in the high 16 bits */
end_comment

begin_define
define|#
directive|define
name|RT2573_DISABLE_RX
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_CRC_ERROR
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_PHY_ERROR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_CTL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_NOT_TO_ME
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_TODS
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_VER_ERROR
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_MULTICAST
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_BROADCAST
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2573_DROP_ACKCTS
value|(1<< 25)
end_define

begin_comment
comment|/* possible flags for register TXRX_CSR4 */
end_comment

begin_define
define|#
directive|define
name|RT2573_SHORT_PREAMBLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RT2573_MRR_ENABLED
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2573_MRR_CCK_FALLBACK
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RT2573_LONG_RETRY
parameter_list|(
name|max
parameter_list|)
value|((max)<< 24)
end_define

begin_define
define|#
directive|define
name|RT2573_LONG_RETRY_MASK
value|(0xf<< 24)
end_define

begin_define
define|#
directive|define
name|RT2573_SHORT_RETRY
parameter_list|(
name|max
parameter_list|)
value|((max)<< 28)
end_define

begin_define
define|#
directive|define
name|RT2573_SHORT_RETRY_MASK
value|(0xf<< 28)
end_define

begin_comment
comment|/* possible flags for register TXRX_CSR9 */
end_comment

begin_define
define|#
directive|define
name|RT2573_TSF_TIMER_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2573_TSF_SYNC_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 17)
end_define

begin_define
define|#
directive|define
name|RT2573_TSF_SYNC_MODE_DIS
value|0
end_define

begin_define
define|#
directive|define
name|RT2573_TSF_SYNC_MODE_STA
value|1
end_define

begin_define
define|#
directive|define
name|RT2573_TSF_SYNC_MODE_IBSS
value|2
end_define

begin_define
define|#
directive|define
name|RT2573_TSF_SYNC_MODE_HOSTAP
value|3
end_define

begin_define
define|#
directive|define
name|RT2573_TBTT_TIMER_EN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2573_BCN_TX_EN
value|(1<< 20)
end_define

begin_comment
comment|/* possible flags for register PHY_CSR0 */
end_comment

begin_define
define|#
directive|define
name|RT2573_PA_PE_2GHZ
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2573_PA_PE_5GHZ
value|(1<< 17)
end_define

begin_comment
comment|/* possible flags for register PHY_CSR3 */
end_comment

begin_define
define|#
directive|define
name|RT2573_BBP_READ
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2573_BBP_BUSY
value|(1<< 16)
end_define

begin_comment
comment|/* possible flags for register PHY_CSR4 */
end_comment

begin_define
define|#
directive|define
name|RT2573_RF_20BIT
value|(20<< 24)
end_define

begin_define
define|#
directive|define
name|RT2573_RF_BUSY
value|(1U<< 31)
end_define

begin_comment
comment|/* LED values */
end_comment

begin_define
define|#
directive|define
name|RT2573_LED_RADIO
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RT2573_LED_G
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RT2573_LED_A
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RT2573_LED_ON
value|0x1e1e
end_define

begin_define
define|#
directive|define
name|RT2573_LED_OFF
value|0x0
end_define

begin_define
define|#
directive|define
name|RT2573_MCU_RUN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2573_SMART_MODE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2573_BBPR94_DEFAULT
value|6
end_define

begin_define
define|#
directive|define
name|RT2573_BBP_WRITE
value|(1<< 15)
end_define

begin_comment
comment|/* dual-band RF */
end_comment

begin_define
define|#
directive|define
name|RT2573_RF_5226
value|1
end_define

begin_define
define|#
directive|define
name|RT2573_RF_5225
value|3
end_define

begin_comment
comment|/* single-band RF */
end_comment

begin_define
define|#
directive|define
name|RT2573_RF_2528
value|2
end_define

begin_define
define|#
directive|define
name|RT2573_RF_2527
value|4
end_define

begin_define
define|#
directive|define
name|RT2573_BBP_VERSION
value|0
end_define

begin_struct
struct|struct
name|rum_tx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2573_TX_BURST
value|(1<< 0)
define|#
directive|define
name|RT2573_TX_VALID
value|(1<< 1)
define|#
directive|define
name|RT2573_TX_MORE_FRAG
value|(1<< 2)
define|#
directive|define
name|RT2573_TX_NEED_ACK
value|(1<< 3)
define|#
directive|define
name|RT2573_TX_TIMESTAMP
value|(1<< 4)
define|#
directive|define
name|RT2573_TX_OFDM
value|(1<< 5)
define|#
directive|define
name|RT2573_TX_IFS_SIFS
value|(1<< 6)
define|#
directive|define
name|RT2573_TX_LONG_RETRY
value|(1<< 7)
define|#
directive|define
name|RT2573_TX_TKIPMIC
value|(1<< 8)
define|#
directive|define
name|RT2573_TX_KEY_PAIR
value|(1<< 9)
define|#
directive|define
name|RT2573_TX_KEY_ID
parameter_list|(
name|id
parameter_list|)
value|(((id)& 0x3f)<< 10)
define|#
directive|define
name|RT2573_TX_CIP_MODE
parameter_list|(
name|m
parameter_list|)
value|((m)<< 29)
name|uint16_t
name|wme
decl_stmt|;
define|#
directive|define
name|RT2573_QID
parameter_list|(
name|v
parameter_list|)
value|(v)
define|#
directive|define
name|RT2573_AIFSN
parameter_list|(
name|v
parameter_list|)
value|((v)<< 4)
define|#
directive|define
name|RT2573_LOGCWMIN
parameter_list|(
name|v
parameter_list|)
value|((v)<< 8)
define|#
directive|define
name|RT2573_LOGCWMAX
parameter_list|(
name|v
parameter_list|)
value|((v)<< 12)
name|uint8_t
name|hdrlen
decl_stmt|;
name|uint8_t
name|xflags
decl_stmt|;
define|#
directive|define
name|RT2573_TX_HWSEQ
value|(1<< 4)
name|uint8_t
name|plcp_signal
decl_stmt|;
name|uint8_t
name|plcp_service
decl_stmt|;
define|#
directive|define
name|RT2573_PLCP_LENGEXT
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
name|uint8_t
name|offset
decl_stmt|;
name|uint8_t
name|qid
decl_stmt|;
name|uint8_t
name|txpower
decl_stmt|;
define|#
directive|define
name|RT2573_DEFAULT_TXPOWER
value|0
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|rum_rx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2573_RX_BUSY
value|(1<< 0)
define|#
directive|define
name|RT2573_RX_DROP
value|(1<< 1)
define|#
directive|define
name|RT2573_RX_UC2ME
value|(1<< 2)
define|#
directive|define
name|RT2573_RX_MC
value|(1<< 3)
define|#
directive|define
name|RT2573_RX_BC
value|(1<< 4)
define|#
directive|define
name|RT2573_RX_MYBSS
value|(1<< 5)
define|#
directive|define
name|RT2573_RX_CRC_ERROR
value|(1<< 6)
define|#
directive|define
name|RT2573_RX_OFDM
value|(1<< 7)
define|#
directive|define
name|RT2573_RX_DEC_MASK
value|(3<< 8)
define|#
directive|define
name|RT2573_RX_DEC_OK
value|(0<< 8)
define|#
directive|define
name|RT2573_RX_IV_ERROR
value|(1<< 8)
define|#
directive|define
name|RT2573_RX_MIC_ERROR
value|(2<< 8)
define|#
directive|define
name|RT2573_RX_KEY_ERROR
value|(3<< 8)
define|#
directive|define
name|RT2573_RX_KEY_PAIR
value|(1<< 28)
define|#
directive|define
name|RT2573_RX_CIP_MASK
value|(7<< 29)
define|#
directive|define
name|RT2573_RX_CIP_MODE
parameter_list|(
name|m
parameter_list|)
value|((m)<< 29)
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rssi
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|offset
decl_stmt|;
name|uint32_t
name|iv
decl_stmt|;
name|uint32_t
name|eiv
decl_stmt|;
name|uint32_t
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|RT2573_RF1
value|0
end_define

begin_define
define|#
directive|define
name|RT2573_RF2
value|2
end_define

begin_define
define|#
directive|define
name|RT2573_RF3
value|1
end_define

begin_define
define|#
directive|define
name|RT2573_RF4
value|3
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_MACBBP
value|0x0000
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_ADDRESS
value|0x0004
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_ANTENNA
value|0x0020
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_CONFIG2
value|0x0022
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_BBP_BASE
value|0x0026
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_TXPOWER
value|0x0046
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_FREQ_OFFSET
value|0x005e
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_RSSI_2GHZ_OFFSET
value|0x009a
end_define

begin_define
define|#
directive|define
name|RT2573_EEPROM_RSSI_5GHZ_OFFSET
value|0x009c
end_define

end_unit

