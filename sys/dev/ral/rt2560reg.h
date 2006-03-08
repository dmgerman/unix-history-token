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
name|RT2560_TX_RING_COUNT
value|48
end_define

begin_define
define|#
directive|define
name|RT2560_ATIM_RING_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|RT2560_PRIO_RING_COUNT
value|16
end_define

begin_define
define|#
directive|define
name|RT2560_BEACON_RING_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|RT2560_RX_RING_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|RT2560_TX_DESC_SIZE
value|(sizeof (struct rt2560_tx_desc))
end_define

begin_define
define|#
directive|define
name|RT2560_RX_DESC_SIZE
value|(sizeof (struct rt2560_rx_desc))
end_define

begin_define
define|#
directive|define
name|RT2560_MAX_SCATTER
value|1
end_define

begin_comment
comment|/*  * Control and status registers.  */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR0
value|0x0000
end_define

begin_comment
comment|/* ASIC version number */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR1
value|0x0004
end_define

begin_comment
comment|/* System control */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR3
value|0x000c
end_define

begin_comment
comment|/* STA MAC address 0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR4
value|0x0010
end_define

begin_comment
comment|/* STA MAC address 1 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR5
value|0x0014
end_define

begin_comment
comment|/* BSSID 0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR6
value|0x0018
end_define

begin_comment
comment|/* BSSID 1 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR7
value|0x001c
end_define

begin_comment
comment|/* Interrupt source */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR8
value|0x0020
end_define

begin_comment
comment|/* Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR9
value|0x0024
end_define

begin_comment
comment|/* Maximum frame length */
end_comment

begin_define
define|#
directive|define
name|RT2560_SECCSR0
value|0x0028
end_define

begin_comment
comment|/* WEP control */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR11
value|0x002c
end_define

begin_comment
comment|/* Back-off control */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR12
value|0x0030
end_define

begin_comment
comment|/* Synchronization configuration 0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR13
value|0x0034
end_define

begin_comment
comment|/* Synchronization configuration 1 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR14
value|0x0038
end_define

begin_comment
comment|/* Synchronization control */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR15
value|0x003c
end_define

begin_comment
comment|/* Synchronization status */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR16
value|0x0040
end_define

begin_comment
comment|/* TSF timer 0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR17
value|0x0044
end_define

begin_comment
comment|/* TSF timer 1 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR18
value|0x0048
end_define

begin_comment
comment|/* IFS timer 0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR19
value|0x004c
end_define

begin_comment
comment|/* IFS timer 1 */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR20
value|0x0050
end_define

begin_comment
comment|/* WAKEUP timer */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR21
value|0x0054
end_define

begin_comment
comment|/* EEPROM control */
end_comment

begin_define
define|#
directive|define
name|RT2560_CSR22
value|0x0058
end_define

begin_comment
comment|/* CFP control */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR0
value|0x0060
end_define

begin_comment
comment|/* TX control */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR1
value|0x0064
end_define

begin_comment
comment|/* TX configuration */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR2
value|0x0068
end_define

begin_comment
comment|/* TX descriptor configuration */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR3
value|0x006c
end_define

begin_comment
comment|/* TX ring base address */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR4
value|0x0070
end_define

begin_comment
comment|/* TX ATIM ring base address */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR5
value|0x0074
end_define

begin_comment
comment|/* TX PRIO ring base address */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR6
value|0x0078
end_define

begin_comment
comment|/* Beacon base address */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR7
value|0x007c
end_define

begin_comment
comment|/* AutoResponder control */
end_comment

begin_define
define|#
directive|define
name|RT2560_RXCSR0
value|0x0080
end_define

begin_comment
comment|/* RX control */
end_comment

begin_define
define|#
directive|define
name|RT2560_RXCSR1
value|0x0084
end_define

begin_comment
comment|/* RX descriptor configuration */
end_comment

begin_define
define|#
directive|define
name|RT2560_RXCSR2
value|0x0088
end_define

begin_comment
comment|/* RX ring base address */
end_comment

begin_define
define|#
directive|define
name|RT2560_PCICSR
value|0x008c
end_define

begin_comment
comment|/* PCI control */
end_comment

begin_define
define|#
directive|define
name|RT2560_RXCSR3
value|0x0090
end_define

begin_comment
comment|/* BBP ID 0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXCSR9
value|0x0094
end_define

begin_comment
comment|/* OFDM TX BBP */
end_comment

begin_define
define|#
directive|define
name|RT2560_ARSP_PLCP_0
value|0x0098
end_define

begin_comment
comment|/* Auto Responder PLCP address */
end_comment

begin_define
define|#
directive|define
name|RT2560_ARSP_PLCP_1
value|0x009c
end_define

begin_comment
comment|/* Auto Responder Basic Rate mask */
end_comment

begin_define
define|#
directive|define
name|RT2560_CNT0
value|0x00a0
end_define

begin_comment
comment|/* FCS error counter */
end_comment

begin_define
define|#
directive|define
name|RT2560_CNT1
value|0x00ac
end_define

begin_comment
comment|/* PLCP error counter */
end_comment

begin_define
define|#
directive|define
name|RT2560_CNT2
value|0x00b0
end_define

begin_comment
comment|/* Long error counter */
end_comment

begin_define
define|#
directive|define
name|RT2560_CNT3
value|0x00b8
end_define

begin_comment
comment|/* CCA false alarm counter */
end_comment

begin_define
define|#
directive|define
name|RT2560_CNT4
value|0x00bc
end_define

begin_comment
comment|/* RX FIFO Overflow counter */
end_comment

begin_define
define|#
directive|define
name|RT2560_CNT5
value|0x00c0
end_define

begin_comment
comment|/* Tx FIFO Underrun counter */
end_comment

begin_define
define|#
directive|define
name|RT2560_PWRCSR0
value|0x00c4
end_define

begin_comment
comment|/* Power mode configuration */
end_comment

begin_define
define|#
directive|define
name|RT2560_PSCSR0
value|0x00c8
end_define

begin_comment
comment|/* Power state transition time */
end_comment

begin_define
define|#
directive|define
name|RT2560_PSCSR1
value|0x00cc
end_define

begin_comment
comment|/* Power state transition time */
end_comment

begin_define
define|#
directive|define
name|RT2560_PSCSR2
value|0x00d0
end_define

begin_comment
comment|/* Power state transition time */
end_comment

begin_define
define|#
directive|define
name|RT2560_PSCSR3
value|0x00d4
end_define

begin_comment
comment|/* Power state transition time */
end_comment

begin_define
define|#
directive|define
name|RT2560_PWRCSR1
value|0x00d8
end_define

begin_comment
comment|/* Manual power control/status */
end_comment

begin_define
define|#
directive|define
name|RT2560_TIMECSR
value|0x00dc
end_define

begin_comment
comment|/* Timer control */
end_comment

begin_define
define|#
directive|define
name|RT2560_MACCSR0
value|0x00e0
end_define

begin_comment
comment|/* MAC configuration */
end_comment

begin_define
define|#
directive|define
name|RT2560_MACCSR1
value|0x00e4
end_define

begin_comment
comment|/* MAC configuration */
end_comment

begin_define
define|#
directive|define
name|RT2560_RALINKCSR
value|0x00e8
end_define

begin_comment
comment|/* Ralink RX auto-reset BBCR */
end_comment

begin_define
define|#
directive|define
name|RT2560_BCNCSR
value|0x00ec
end_define

begin_comment
comment|/* Beacon interval control */
end_comment

begin_define
define|#
directive|define
name|RT2560_BBPCSR
value|0x00f0
end_define

begin_comment
comment|/* BBP serial control */
end_comment

begin_define
define|#
directive|define
name|RT2560_RFCSR
value|0x00f4
end_define

begin_comment
comment|/* RF serial control */
end_comment

begin_define
define|#
directive|define
name|RT2560_LEDCSR
value|0x00f8
end_define

begin_comment
comment|/* LED control */
end_comment

begin_define
define|#
directive|define
name|RT2560_SECCSR3
value|0x00fc
end_define

begin_comment
comment|/* XXX not documented */
end_comment

begin_define
define|#
directive|define
name|RT2560_DMACSR0
value|0x0100
end_define

begin_comment
comment|/* Current RX ring address */
end_comment

begin_define
define|#
directive|define
name|RT2560_DMACSR1
value|0x0104
end_define

begin_comment
comment|/* Current Tx ring address */
end_comment

begin_define
define|#
directive|define
name|RT2560_DMACSR2
value|0x0104
end_define

begin_comment
comment|/* Current Priority ring address */
end_comment

begin_define
define|#
directive|define
name|RT2560_DMACSR3
value|0x0104
end_define

begin_comment
comment|/* Current ATIM ring address */
end_comment

begin_define
define|#
directive|define
name|RT2560_TXACKCSR0
value|0x0110
end_define

begin_comment
comment|/* XXX not documented */
end_comment

begin_define
define|#
directive|define
name|RT2560_GPIOCSR
value|0x0120
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|RT2560_BBBPPCSR
value|0x0124
end_define

begin_comment
comment|/* BBP Pin Control */
end_comment

begin_define
define|#
directive|define
name|RT2560_FIFOCSR0
value|0x0128
end_define

begin_comment
comment|/* TX FIFO pointer */
end_comment

begin_define
define|#
directive|define
name|RT2560_FIFOCSR1
value|0x012c
end_define

begin_comment
comment|/* RX FIFO pointer */
end_comment

begin_define
define|#
directive|define
name|RT2560_BCNOCSR
value|0x0130
end_define

begin_comment
comment|/* Beacon time offset */
end_comment

begin_define
define|#
directive|define
name|RT2560_RLPWCSR
value|0x0134
end_define

begin_comment
comment|/* RX_PE Low Width */
end_comment

begin_define
define|#
directive|define
name|RT2560_TESTCSR
value|0x0138
end_define

begin_comment
comment|/* Test Mode Select */
end_comment

begin_define
define|#
directive|define
name|RT2560_PLCP1MCSR
value|0x013c
end_define

begin_comment
comment|/* Signal/Service/Length of ACK @1M */
end_comment

begin_define
define|#
directive|define
name|RT2560_PLCP2MCSR
value|0x0140
end_define

begin_comment
comment|/* Signal/Service/Length of ACK @2M */
end_comment

begin_define
define|#
directive|define
name|RT2560_PLCP5p5MCSR
value|0x0144
end_define

begin_comment
comment|/* Signal/Service/Length of ACK @5.5M */
end_comment

begin_define
define|#
directive|define
name|RT2560_PLCP11MCSR
value|0x0148
end_define

begin_comment
comment|/* Signal/Service/Length of ACK @11M */
end_comment

begin_define
define|#
directive|define
name|RT2560_ACKPCTCSR
value|0x014c
end_define

begin_comment
comment|/* ACK/CTS padload consume time */
end_comment

begin_define
define|#
directive|define
name|RT2560_ARTCSR1
value|0x0150
end_define

begin_comment
comment|/* ACK/CTS padload consume time */
end_comment

begin_define
define|#
directive|define
name|RT2560_ARTCSR2
value|0x0154
end_define

begin_comment
comment|/* ACK/CTS padload consume time */
end_comment

begin_define
define|#
directive|define
name|RT2560_SECCSR1
value|0x0158
end_define

begin_comment
comment|/* WEP control */
end_comment

begin_define
define|#
directive|define
name|RT2560_BBPCSR1
value|0x015c
end_define

begin_comment
comment|/* BBP TX Configuration */
end_comment

begin_comment
comment|/* possible flags for register RXCSR0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_DISABLE_RX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2560_DROP_CRC_ERROR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2560_DROP_PHY_ERROR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2560_DROP_CTL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2560_DROP_NOT_TO_ME
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RT2560_DROP_TODS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RT2560_DROP_VERSION_ERROR
value|(1<< 6)
end_define

begin_comment
comment|/* possible flags for register CSR1 */
end_comment

begin_define
define|#
directive|define
name|RT2560_RESET_ASIC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2560_RESET_BBP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2560_HOST_READY
value|(1<< 2)
end_define

begin_comment
comment|/* possible flags for register CSR14 */
end_comment

begin_define
define|#
directive|define
name|RT2560_ENABLE_TSF
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2560_ENABLE_TSF_SYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 1)
end_define

begin_define
define|#
directive|define
name|RT2560_ENABLE_TBCN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2560_ENABLE_BEACON_GENERATOR
value|(1<< 6)
end_define

begin_comment
comment|/* possible flags for register CSR21 */
end_comment

begin_define
define|#
directive|define
name|RT2560_C
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2560_S
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2560_D
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2560_Q
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RT2560_93C46
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RT2560_SHIFT_D
value|3
end_define

begin_define
define|#
directive|define
name|RT2560_SHIFT_Q
value|4
end_define

begin_comment
comment|/* possible flags for register TXCSR0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_KICK_TX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2560_KICK_ATIM
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2560_KICK_PRIO
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2560_ABORT_TX
value|(1<< 3)
end_define

begin_comment
comment|/* possible flags for register SECCSR0 */
end_comment

begin_define
define|#
directive|define
name|RT2560_KICK_DECRYPT
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register SECCSR1 */
end_comment

begin_define
define|#
directive|define
name|RT2560_KICK_ENCRYPT
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register CSR7 */
end_comment

begin_define
define|#
directive|define
name|RT2560_BEACON_EXPIRE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RT2560_WAKEUP_EXPIRE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RT2560_ATIM_EXPIRE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RT2560_TX_DONE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RT2560_ATIM_DONE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RT2560_PRIO_DONE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RT2560_RX_DONE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RT2560_DECRYPTION_DONE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RT2560_ENCRYPTION_DONE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RT2560_INTR_MASK
define|\
value|(~(RT2560_BEACON_EXPIRE | RT2560_WAKEUP_EXPIRE | RT2560_TX_DONE |	\ 	   RT2560_PRIO_DONE | RT2560_RX_DONE | RT2560_DECRYPTION_DONE |		\ 	   RT2560_ENCRYPTION_DONE))
end_define

begin_comment
comment|/* Tx descriptor */
end_comment

begin_struct
struct|struct
name|rt2560_tx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2560_TX_BUSY
value|(1<< 0)
define|#
directive|define
name|RT2560_TX_VALID
value|(1<< 1)
define|#
directive|define
name|RT2560_TX_RESULT_MASK
value|0x0000001c
define|#
directive|define
name|RT2560_TX_SUCCESS
value|(0<< 2)
define|#
directive|define
name|RT2560_TX_SUCCESS_RETRY
value|(1<< 2)
define|#
directive|define
name|RT2560_TX_FAIL_RETRY
value|(2<< 2)
define|#
directive|define
name|RT2560_TX_FAIL_INVALID
value|(3<< 2)
define|#
directive|define
name|RT2560_TX_FAIL_OTHER
value|(4<< 2)
define|#
directive|define
name|RT2560_TX_MORE_FRAG
value|(1<< 8)
define|#
directive|define
name|RT2560_TX_ACK
value|(1<< 9)
define|#
directive|define
name|RT2560_TX_TIMESTAMP
value|(1<< 10)
define|#
directive|define
name|RT2560_TX_OFDM
value|(1<< 11)
define|#
directive|define
name|RT2560_TX_CIPHER_BUSY
value|(1<< 12)
define|#
directive|define
name|RT2560_TX_IFS_MASK
value|0x00006000
define|#
directive|define
name|RT2560_TX_IFS_BACKOFF
value|(0<< 13)
define|#
directive|define
name|RT2560_TX_IFS_SIFS
value|(1<< 13)
define|#
directive|define
name|RT2560_TX_IFS_NEWBACKOFF
value|(2<< 13)
define|#
directive|define
name|RT2560_TX_IFS_NONE
value|(3<< 13)
define|#
directive|define
name|RT2560_TX_LONG_RETRY
value|(1<< 15)
define|#
directive|define
name|RT2560_TX_CIPHER_MASK
value|0xe0000000
define|#
directive|define
name|RT2560_TX_CIPHER_NONE
value|(0<< 29)
define|#
directive|define
name|RT2560_TX_CIPHER_WEP40
value|(1<< 29)
define|#
directive|define
name|RT2560_TX_CIPHER_WEP104
value|(2<< 29)
define|#
directive|define
name|RT2560_TX_CIPHER_TKIP
value|(3<< 29)
define|#
directive|define
name|RT2560_TX_CIPHER_AES
value|(4<< 29)
name|uint32_t
name|physaddr
decl_stmt|;
name|uint16_t
name|wme
decl_stmt|;
define|#
directive|define
name|RT2560_LOGCWMAX
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 12)
define|#
directive|define
name|RT2560_LOGCWMIN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xf)<< 8)
define|#
directive|define
name|RT2560_AIFSN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
define|#
directive|define
name|RT2560_IVOFFSET
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
name|RT2560_PLCP_LENGEXT
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
name|key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
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

begin_comment
comment|/* Rx descriptor */
end_comment

begin_struct
struct|struct
name|rt2560_rx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2560_RX_BUSY
value|(1<< 0)
define|#
directive|define
name|RT2560_RX_CRC_ERROR
value|(1<< 5)
define|#
directive|define
name|RT2560_RX_OFDM
value|(1<< 6)
define|#
directive|define
name|RT2560_RX_PHY_ERROR
value|(1<< 7)
define|#
directive|define
name|RT2560_RX_CIPHER_BUSY
value|(1<< 8)
define|#
directive|define
name|RT2560_RX_ICV_ERROR
value|(1<< 9)
define|#
directive|define
name|RT2560_RX_CIPHER_MASK
value|0xe0000000
define|#
directive|define
name|RT2560_RX_CIPHER_NONE
value|(0<< 29)
define|#
directive|define
name|RT2560_RX_CIPHER_WEP40
value|(1<< 29)
define|#
directive|define
name|RT2560_RX_CIPHER_WEP104
value|(2<< 29)
define|#
directive|define
name|RT2560_RX_CIPHER_TKIP
value|(3<< 29)
define|#
directive|define
name|RT2560_RX_CIPHER_AES
value|(4<< 29)
name|uint32_t
name|physaddr
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rssi
decl_stmt|;
name|uint8_t
name|ta
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|iv
decl_stmt|;
name|uint32_t
name|eiv
decl_stmt|;
name|uint8_t
name|key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
name|uint32_t
name|reserved
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
name|RT2560_RF1_AUTOTUNE
value|0x08000
end_define

begin_define
define|#
directive|define
name|RT2560_RF3_AUTOTUNE
value|0x00040
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_BUSY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_WRITE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2560_RF_20BIT
value|(20<< 24)
end_define

begin_define
define|#
directive|define
name|RT2560_RF_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RT2560_RF_2522
value|0x00
end_define

begin_define
define|#
directive|define
name|RT2560_RF_2523
value|0x01
end_define

begin_define
define|#
directive|define
name|RT2560_RF_2524
value|0x02
end_define

begin_define
define|#
directive|define
name|RT2560_RF_2525
value|0x03
end_define

begin_define
define|#
directive|define
name|RT2560_RF_2525E
value|0x04
end_define

begin_define
define|#
directive|define
name|RT2560_RF_2526
value|0x05
end_define

begin_comment
comment|/* dual-band RF */
end_comment

begin_define
define|#
directive|define
name|RT2560_RF_5222
value|0x10
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_TX
value|2
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_RX
value|14
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_ANTA
value|0x00
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_DIVERSITY
value|0x01
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_ANTB
value|0x02
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_ANTMASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RT2560_BBP_FLIPIQ
value|0x04
end_define

begin_define
define|#
directive|define
name|RT2560_LED_MODE_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|RT2560_LED_MODE_TXRX_ACTIVITY
value|1
end_define

begin_define
define|#
directive|define
name|RT2560_LED_MODE_SINGLE
value|2
end_define

begin_define
define|#
directive|define
name|RT2560_LED_MODE_ASUS
value|3
end_define

begin_define
define|#
directive|define
name|RT2560_JAPAN_FILTER
value|0x8
end_define

begin_define
define|#
directive|define
name|RT2560_EEPROM_DELAY
value|1
end_define

begin_comment
comment|/* minimum hold time (microsecond) */
end_comment

begin_define
define|#
directive|define
name|RT2560_EEPROM_CONFIG0
value|16
end_define

begin_define
define|#
directive|define
name|RT2560_EEPROM_BBP_BASE
value|19
end_define

begin_define
define|#
directive|define
name|RT2560_EEPROM_TXPOWER
value|35
end_define

begin_comment
comment|/*  * control and status registers access macros  */
end_comment

begin_define
define|#
directive|define
name|RAL_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|RAL_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_comment
comment|/*  * EEPROM access macro  */
end_comment

begin_define
define|#
directive|define
name|RT2560_EEPROM_CTL
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	RAL_WRITE((sc), RT2560_CSR21, (val));				\ 	DELAY(RT2560_EEPROM_DELAY);					\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_comment
comment|/*  * Default values for MAC registers; values taken from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2560_DEF_MAC
define|\
value|{ RT2560_PSCSR0,      0x00020002 },	\ 	{ RT2560_PSCSR1,      0x00000002 },	\ 	{ RT2560_PSCSR2,      0x00020002 },	\ 	{ RT2560_PSCSR3,      0x00000002 },	\ 	{ RT2560_TIMECSR,     0x00003f21 },	\ 	{ RT2560_CSR9,        0x00000780 },	\ 	{ RT2560_CSR11,       0x07041483 },	\ 	{ RT2560_CNT3,        0x00000000 },	\ 	{ RT2560_TXCSR1,      0x07614562 },	\ 	{ RT2560_ARSP_PLCP_0, 0x8c8d8b8a },	\ 	{ RT2560_ACKPCTCSR,   0x7038140a },	\ 	{ RT2560_ARTCSR1,     0x1d21252d },	\ 	{ RT2560_ARTCSR2,     0x1919191d },	\ 	{ RT2560_RXCSR0,      0xffffffff },	\ 	{ RT2560_RXCSR3,      0xb3aab3af },	\ 	{ RT2560_PCICSR,      0x000003b8 },	\ 	{ RT2560_PWRCSR0,     0x3f3b3100 },	\ 	{ RT2560_GPIOCSR,     0x0000ff00 },	\ 	{ RT2560_TESTCSR,     0x000000f0 },	\ 	{ RT2560_PWRCSR1,     0x000001ff },	\ 	{ RT2560_MACCSR0,     0x00213223 },	\ 	{ RT2560_MACCSR1,     0x00235518 },	\ 	{ RT2560_RLPWCSR,     0x00000040 },	\ 	{ RT2560_RALINKCSR,   0x9a009a11 },	\ 	{ RT2560_CSR7,        0xffffffff },	\ 	{ RT2560_BBPCSR1,     0x82188200 },	\ 	{ RT2560_TXACKCSR0,   0x00000020 },	\ 	{ RT2560_SECCSR3,     0x0000e78f }
end_define

begin_comment
comment|/*  * Default values for BBP registers; values taken from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2560_DEF_BBP
define|\
value|{  3, 0x02 },	\ 	{  4, 0x19 },	\ 	{ 14, 0x1c },	\ 	{ 15, 0x30 },	\ 	{ 16, 0xac },	\ 	{ 17, 0x48 },	\ 	{ 18, 0x18 },	\ 	{ 19, 0xff },	\ 	{ 20, 0x1e },	\ 	{ 21, 0x08 },	\ 	{ 22, 0x08 },	\ 	{ 23, 0x08 },	\ 	{ 24, 0x80 },	\ 	{ 25, 0x50 },	\ 	{ 26, 0x08 },	\ 	{ 27, 0x23 },	\ 	{ 30, 0x10 },	\ 	{ 31, 0x2b },	\ 	{ 32, 0xb9 },	\ 	{ 34, 0x12 },	\ 	{ 35, 0x50 },	\ 	{ 39, 0xc4 },	\ 	{ 40, 0x02 },	\ 	{ 41, 0x60 },	\ 	{ 53, 0x10 },	\ 	{ 54, 0x18 },	\ 	{ 56, 0x08 },	\ 	{ 57, 0x10 },	\ 	{ 58, 0x08 },	\ 	{ 61, 0x60 },	\ 	{ 62, 0x10 },	\ 	{ 75, 0xff }
end_define

begin_comment
comment|/*  * Default values for RF register R2 indexed by channel numbers; values taken  * from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2560_RF2522_R2
define|\
value|{									\ 	0x307f6, 0x307fb, 0x30800, 0x30805, 0x3080a, 0x3080f, 0x30814,	\ 	0x30819, 0x3081e, 0x30823, 0x30828, 0x3082d, 0x30832, 0x3083e	\ }
end_define

begin_define
define|#
directive|define
name|RT2560_RF2523_R2
define|\
value|{									\ 	0x00327, 0x00328, 0x00329, 0x0032a, 0x0032b, 0x0032c, 0x0032d,	\ 	0x0032e, 0x0032f, 0x00340, 0x00341, 0x00342, 0x00343, 0x00346	\ }
end_define

begin_define
define|#
directive|define
name|RT2560_RF2524_R2
define|\
value|{									\ 	0x00327, 0x00328, 0x00329, 0x0032a, 0x0032b, 0x0032c, 0x0032d,	\ 	0x0032e, 0x0032f, 0x00340, 0x00341, 0x00342, 0x00343, 0x00346	\ }
end_define

begin_define
define|#
directive|define
name|RT2560_RF2525_R2
define|\
value|{									\ 	0x20327, 0x20328, 0x20329, 0x2032a, 0x2032b, 0x2032c, 0x2032d,	\ 	0x2032e, 0x2032f, 0x20340, 0x20341, 0x20342, 0x20343, 0x20346	\ }
end_define

begin_define
define|#
directive|define
name|RT2560_RF2525_HI_R2
define|\
value|{									\ 	0x2032f, 0x20340, 0x20341, 0x20342, 0x20343, 0x20344, 0x20345,	\ 	0x20346, 0x20347, 0x20348, 0x20349, 0x2034a, 0x2034b, 0x2034e	\ }
end_define

begin_define
define|#
directive|define
name|RT2560_RF2525E_R2
define|\
value|{									\ 	0x2044d, 0x2044e, 0x2044f, 0x20460, 0x20461, 0x20462, 0x20463,	\ 	0x20464, 0x20465, 0x20466, 0x20467, 0x20468, 0x20469, 0x2046b	\ }
end_define

begin_define
define|#
directive|define
name|RT2560_RF2526_HI_R2
define|\
value|{									\ 	0x0022a, 0x0022b, 0x0022b, 0x0022c, 0x0022c, 0x0022d, 0x0022d,	\ 	0x0022e, 0x0022e, 0x0022f, 0x0022d, 0x00240, 0x00240, 0x00241	\ }
end_define

begin_define
define|#
directive|define
name|RT2560_RF2526_R2
define|\
value|{									\ 	0x00226, 0x00227, 0x00227, 0x00228, 0x00228, 0x00229, 0x00229,	\ 	0x0022a, 0x0022a, 0x0022b, 0x0022b, 0x0022c, 0x0022c, 0x0022d	\ }
end_define

begin_comment
comment|/*  * For dual-band RF, RF registers R1 and R4 also depend on channel number;  * values taken from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2560_RF5222
define|\
value|{   1, 0x08808, 0x0044d, 0x00282 },	\ 	{   2, 0x08808, 0x0044e, 0x00282 },	\ 	{   3, 0x08808, 0x0044f, 0x00282 },	\ 	{   4, 0x08808, 0x00460, 0x00282 },	\ 	{   5, 0x08808, 0x00461, 0x00282 },	\ 	{   6, 0x08808, 0x00462, 0x00282 },	\ 	{   7, 0x08808, 0x00463, 0x00282 },	\ 	{   8, 0x08808, 0x00464, 0x00282 },	\ 	{   9, 0x08808, 0x00465, 0x00282 },	\ 	{  10, 0x08808, 0x00466, 0x00282 },	\ 	{  11, 0x08808, 0x00467, 0x00282 },	\ 	{  12, 0x08808, 0x00468, 0x00282 },	\ 	{  13, 0x08808, 0x00469, 0x00282 },	\ 	{  14, 0x08808, 0x0046b, 0x00286 },	\ 						\ 	{  36, 0x08804, 0x06225, 0x00287 },	\ 	{  40, 0x08804, 0x06226, 0x00287 },	\ 	{  44, 0x08804, 0x06227, 0x00287 },	\ 	{  48, 0x08804, 0x06228, 0x00287 },	\ 	{  52, 0x08804, 0x06229, 0x00287 },	\ 	{  56, 0x08804, 0x0622a, 0x00287 },	\ 	{  60, 0x08804, 0x0622b, 0x00287 },	\ 	{  64, 0x08804, 0x0622c, 0x00287 },	\ 						\ 	{ 100, 0x08804, 0x02200, 0x00283 },	\ 	{ 104, 0x08804, 0x02201, 0x00283 },	\ 	{ 108, 0x08804, 0x02202, 0x00283 },	\ 	{ 112, 0x08804, 0x02203, 0x00283 },	\ 	{ 116, 0x08804, 0x02204, 0x00283 },	\ 	{ 120, 0x08804, 0x02205, 0x00283 },	\ 	{ 124, 0x08804, 0x02206, 0x00283 },	\ 	{ 128, 0x08804, 0x02207, 0x00283 },	\ 	{ 132, 0x08804, 0x02208, 0x00283 },	\ 	{ 136, 0x08804, 0x02209, 0x00283 },	\ 	{ 140, 0x08804, 0x0220a, 0x00283 },	\ 						\ 	{ 149, 0x08808, 0x02429, 0x00281 },	\ 	{ 153, 0x08808, 0x0242b, 0x00281 },	\ 	{ 157, 0x08808, 0x0242d, 0x00281 },	\ 	{ 161, 0x08808, 0x0242f, 0x00281 }
end_define

end_unit

