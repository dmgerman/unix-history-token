begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: if_iwnreg.h,v 1.9 2007/11/27 20:59:40 damien Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007  *	Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|EDCA_NUM_AC
value|4
end_define

begin_define
define|#
directive|define
name|IWN_TX_RING_COUNT
value|256
end_define

begin_define
define|#
directive|define
name|IWN_RX_RING_COUNT
value|64
end_define

begin_define
define|#
directive|define
name|IWN_NTXQUEUES
value|16
end_define

begin_define
define|#
directive|define
name|IWN_NTXCHAINS
value|2
end_define

begin_comment
comment|/*  * Rings must be aligned on a 256-byte boundary.  */
end_comment

begin_define
define|#
directive|define
name|IWN_RING_DMA_ALIGN
value|256
end_define

begin_comment
comment|/* maximum scatter/gather */
end_comment

begin_define
define|#
directive|define
name|IWN_MAX_SCATTER
value|20
end_define

begin_comment
comment|/* Rx buffers must be large enough to hold a full 4K A-MPDU */
end_comment

begin_define
define|#
directive|define
name|IWN_RBUF_SIZE
value|(4 * 1024)
end_define

begin_comment
comment|/*  * Control and status registers.  */
end_comment

begin_define
define|#
directive|define
name|IWN_HWCONFIG
value|0x000
end_define

begin_define
define|#
directive|define
name|IWN_INTR_MIT
value|0x004
end_define

begin_define
define|#
directive|define
name|IWN_INTR
value|0x008
end_define

begin_define
define|#
directive|define
name|IWN_MASK
value|0x00c
end_define

begin_define
define|#
directive|define
name|IWN_INTR_STATUS
value|0x010
end_define

begin_define
define|#
directive|define
name|IWN_RESET
value|0x020
end_define

begin_define
define|#
directive|define
name|IWN_GPIO_CTL
value|0x024
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_CTL
value|0x02c
end_define

begin_define
define|#
directive|define
name|IWN_UCODE_CLR
value|0x05c
end_define

begin_define
define|#
directive|define
name|IWN_CHICKEN
value|0x100
end_define

begin_define
define|#
directive|define
name|IWN_QUEUE_OFFSET
parameter_list|(
name|qid
parameter_list|)
value|(0x380 + (qid) * 8)
end_define

begin_define
define|#
directive|define
name|IWN_MEM_WADDR
value|0x410
end_define

begin_define
define|#
directive|define
name|IWN_MEM_WDATA
value|0x418
end_define

begin_define
define|#
directive|define
name|IWN_WRITE_MEM_ADDR
value|0x444
end_define

begin_define
define|#
directive|define
name|IWN_READ_MEM_ADDR
value|0x448
end_define

begin_define
define|#
directive|define
name|IWN_WRITE_MEM_DATA
value|0x44c
end_define

begin_define
define|#
directive|define
name|IWN_READ_MEM_DATA
value|0x450
end_define

begin_define
define|#
directive|define
name|IWN_TX_WIDX
value|0x460
end_define

begin_define
define|#
directive|define
name|IWN_KW_BASE
value|0x197c
end_define

begin_define
define|#
directive|define
name|IWN_TX_BASE
parameter_list|(
name|qid
parameter_list|)
value|(0x19d0 + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|IWN_RW_WIDX_PTR
value|0x1bc0
end_define

begin_define
define|#
directive|define
name|IWN_RX_BASE
value|0x1bc4
end_define

begin_define
define|#
directive|define
name|IWN_RX_WIDX
value|0x1bc8
end_define

begin_define
define|#
directive|define
name|IWN_RX_CONFIG
value|0x1c00
end_define

begin_define
define|#
directive|define
name|IWN_RX_STATUS
value|0x1c44
end_define

begin_define
define|#
directive|define
name|IWN_TX_CONFIG
parameter_list|(
name|qid
parameter_list|)
value|(0x1d00 + (qid) * 32)
end_define

begin_define
define|#
directive|define
name|IWN_TX_STATUS
value|0x1eb0
end_define

begin_define
define|#
directive|define
name|IWN_SRAM_BASE
value|0xa02c00
end_define

begin_define
define|#
directive|define
name|IWN_TX_ACTIVE
value|(IWN_SRAM_BASE + 0x01c)
end_define

begin_define
define|#
directive|define
name|IWN_QUEUE_RIDX
parameter_list|(
name|qid
parameter_list|)
value|(IWN_SRAM_BASE + 0x064 + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|IWN_SELECT_QCHAIN
value|(IWN_SRAM_BASE + 0x0d0)
end_define

begin_define
define|#
directive|define
name|IWN_QUEUE_INTR_MASK
value|(IWN_SRAM_BASE + 0x0e4)
end_define

begin_define
define|#
directive|define
name|IWN_TXQ_STATUS
parameter_list|(
name|qid
parameter_list|)
value|(IWN_SRAM_BASE + 0x104 + (qid) * 4)
end_define

begin_comment
comment|/*  * NIC internal memory offsets.  */
end_comment

begin_define
define|#
directive|define
name|IWN_CLOCK_CTL
value|0x3000
end_define

begin_define
define|#
directive|define
name|IWN_MEM_CLOCK2
value|0x3008
end_define

begin_define
define|#
directive|define
name|IWN_MEM_POWER
value|0x300c
end_define

begin_define
define|#
directive|define
name|IWN_MEM_PCIDEV
value|0x3010
end_define

begin_define
define|#
directive|define
name|IWN_MEM_UCODE_CTL
value|0x3400
end_define

begin_define
define|#
directive|define
name|IWN_MEM_UCODE_SRC
value|0x3404
end_define

begin_define
define|#
directive|define
name|IWN_MEM_UCODE_DST
value|0x3408
end_define

begin_define
define|#
directive|define
name|IWN_MEM_UCODE_SIZE
value|0x340c
end_define

begin_define
define|#
directive|define
name|IWN_MEM_TEXT_BASE
value|0x3490
end_define

begin_define
define|#
directive|define
name|IWN_MEM_TEXT_SIZE
value|0x3494
end_define

begin_define
define|#
directive|define
name|IWN_MEM_DATA_BASE
value|0x3498
end_define

begin_define
define|#
directive|define
name|IWN_MEM_DATA_SIZE
value|0x349c
end_define

begin_define
define|#
directive|define
name|IWN_MEM_UCODE_BASE
value|0x3800
end_define

begin_comment
comment|/* possible flags for register IWN_HWCONFIG */
end_comment

begin_define
define|#
directive|define
name|IWN_HW_EEPROM_LOCKED
value|(1<< 21)
end_define

begin_comment
comment|/* possible flags for registers IWN_READ_MEM_ADDR/IWN_WRITE_MEM_ADDR */
end_comment

begin_define
define|#
directive|define
name|IWN_MEM_4
value|((sizeof (uint32_t) - 1)<< 24)
end_define

begin_comment
comment|/* possible values for IWN_MEM_UCODE_DST */
end_comment

begin_define
define|#
directive|define
name|IWN_FW_TEXT
value|0x00000000
end_define

begin_comment
comment|/* possible flags for register IWN_RESET */
end_comment

begin_define
define|#
directive|define
name|IWN_NEVO_RESET
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_SW_RESET
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IWN_MASTER_DISABLED
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IWN_STOP_MASTER
value|(1<< 9)
end_define

begin_comment
comment|/* possible flags for register IWN_GPIO_CTL */
end_comment

begin_define
define|#
directive|define
name|IWN_GPIO_CLOCK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_GPIO_INIT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IWN_GPIO_MAC
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IWN_GPIO_SLEEP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IWN_GPIO_PWR_STATUS
value|0x07000000
end_define

begin_define
define|#
directive|define
name|IWN_GPIO_PWR_SLEEP
value|(4<< 24)
end_define

begin_define
define|#
directive|define
name|IWN_GPIO_RF_ENABLED
value|(1<< 27)
end_define

begin_comment
comment|/* possible flags for register IWN_CHICKEN */
end_comment

begin_define
define|#
directive|define
name|IWN_CHICKEN_DISLOS
value|(1<< 29)
end_define

begin_comment
comment|/* possible flags for register IWN_UCODE_CLR */
end_comment

begin_define
define|#
directive|define
name|IWN_RADIO_OFF
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IWN_DISABLE_CMD
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IWN_CTEMP_STOP_RF
value|(1<< 3)
end_define

begin_comment
comment|/* possible flags for IWN_RX_STATUS */
end_comment

begin_define
define|#
directive|define
name|IWN_RX_IDLE
value|(1<< 24)
end_define

begin_comment
comment|/* possible flags for register IWN_UC_CTL */
end_comment

begin_define
define|#
directive|define
name|IWN_UC_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|IWN_UC_RUN
value|(1<< 31)
end_define

begin_comment
comment|/* possible flags for register IWN_INTR */
end_comment

begin_define
define|#
directive|define
name|IWN_ALIVE_INTR
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|IWN_WAKEUP_INTR
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|IWN_SW_RX_INTR
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|IWN_CT_REACHED
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|IWN_RF_TOGGLED
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|IWN_SW_ERROR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|IWN_TX_INTR
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|IWN_HW_ERROR
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|IWN_RX_INTR
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IWN_INTR_BITS
value|"\20\1ALIVE\2WAKEUP\3SW_RX\6CT_REACHED\7RF_TOGGLED" \ 	"\32SW_ERROR\34TX_INTR\36HW_ERROR\40RX_INTR"
end_define

begin_define
define|#
directive|define
name|IWN_INTR_MASK
define|\
value|(IWN_SW_ERROR | IWN_HW_ERROR | IWN_TX_INTR | IWN_RX_INTR |	\ 	 IWN_ALIVE_INTR | IWN_WAKEUP_INTR | IWN_SW_RX_INTR |		\ 	 IWN_CT_REACHED | IWN_RF_TOGGLED)
end_define

begin_comment
comment|/* possible flags for register IWN_INTR_STATUS */
end_comment

begin_define
define|#
directive|define
name|IWN_STATUS_TXQ
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|IWN_STATUS_RXQ
parameter_list|(
name|x
parameter_list|)
value|(1<< ((x) + 16))
end_define

begin_define
define|#
directive|define
name|IWN_STATUS_PRI
value|(1<< 30)
end_define

begin_comment
comment|/* shortcuts for the above */
end_comment

begin_define
define|#
directive|define
name|IWN_TX_STATUS_INTR
define|\
value|(IWN_STATUS_TXQ(0) | IWN_STATUS_TXQ(1) | IWN_STATUS_TXQ(6))
end_define

begin_define
define|#
directive|define
name|IWN_RX_STATUS_INTR
define|\
value|(IWN_STATUS_RXQ(0) | IWN_STATUS_RXQ(1) | IWN_STATUS_RXQ(2) |	\ 	 IWN_STATUS_PRI)
end_define

begin_comment
comment|/* possible flags for register IWN_TX_STATUS */
end_comment

begin_define
define|#
directive|define
name|IWN_TX_IDLE
parameter_list|(
name|qid
parameter_list|)
value|(1<< ((qid) + 24) | 1<< ((qid) + 16))
end_define

begin_comment
comment|/* possible flags/masks for register IWN_EEPROM_CTL */
end_comment

begin_define
define|#
directive|define
name|IWN_EEPROM_READY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_MSK
value|(1<< 1)
end_define

begin_comment
comment|/* possible flags for register IWN_TXQ_STATUS */
end_comment

begin_define
define|#
directive|define
name|IWN_TXQ_STATUS_ACTIVE
value|0x0007fc01
end_define

begin_comment
comment|/* possible flags for register IWN_MEM_POWER */
end_comment

begin_define
define|#
directive|define
name|IWN_POWER_RESET
value|(1<< 26)
end_define

begin_comment
comment|/* possible flags for register IWN_MEM_TEXT_SIZE */
end_comment

begin_define
define|#
directive|define
name|IWN_FW_UPDATED
value|(1<< 31)
end_define

begin_comment
comment|/* possible flags for device-specific PCI register 0xe8 */
end_comment

begin_define
define|#
directive|define
name|IWN_DIS_NOSNOOP
value|(1<< 11)
end_define

begin_comment
comment|/* possible flags for device-specific PCI register 0xf0 */
end_comment

begin_define
define|#
directive|define
name|IWN_ENA_L1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IWN_TX_WINDOW
value|64
end_define

begin_struct
struct|struct
name|iwn_shared
block|{
name|uint16_t
name|len
index|[
name|IWN_NTXQUEUES
index|]
index|[
literal|512
index|]
decl_stmt|;
comment|/* 16KB total */
name|uint16_t
name|closed_count
decl_stmt|;
name|uint16_t
name|closed_rx_count
decl_stmt|;
name|uint16_t
name|finished_count
decl_stmt|;
name|uint16_t
name|finished_rx_count
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

begin_struct
struct|struct
name|iwn_tx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|w1
decl_stmt|;
name|uint32_t
name|w2
decl_stmt|;
name|uint32_t
name|w3
decl_stmt|;
block|}
name|__packed
name|segs
index|[
name|IWN_MAX_SCATTER
operator|/
literal|2
index|]
struct|;
comment|/* pad to 128 bytes */
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_SET_DESC_NSEGS
parameter_list|(
name|d
parameter_list|,
name|x
parameter_list|)
define|\
value|(d)->flags = htole32(((x)& 0x1f)<< 24)
end_define

begin_comment
comment|/* set a segment physical address and length in a Tx descriptor */
end_comment

begin_define
define|#
directive|define
name|IWN_SET_DESC_SEG
parameter_list|(
name|d
parameter_list|,
name|n
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
value|do {				\ 	if ((n)& 1) {							\ 		(d)->segs[(n) / 2].w2 |=				\ 		    htole32(((addr)& 0xffff)<< 16);			\ 		(d)->segs[(n) / 2].w3 =					\ 		    htole32((((addr)>> 16)& 0xffff) | (size)<< 20);	\ 	} else {							\ 		(d)->segs[(n) / 2].w1 = htole32(addr);			\ 		(d)->segs[(n) / 2].w2 = htole32((size)<< 4);		\ 	}								\ } while (0)
end_define

begin_struct
struct|struct
name|iwn_rx_desc
block|{
name|uint32_t
name|len
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
define|#
directive|define
name|IWN_UC_READY
value|1
define|#
directive|define
name|IWN_ADD_NODE_DONE
value|24
define|#
directive|define
name|IWN_TX_DONE
value|28
define|#
directive|define
name|IWN_START_SCAN
value|130
define|#
directive|define
name|IWN_STOP_SCAN
value|132
define|#
directive|define
name|IWN_RX_STATISTICS
value|156
define|#
directive|define
name|IWN_BEACON_STATISTICS
value|157
define|#
directive|define
name|IWN_STATE_CHANGED
value|161
define|#
directive|define
name|IWN_BEACON_MISSED
value|162
define|#
directive|define
name|IWN_AMPDU_RX_START
value|192
define|#
directive|define
name|IWN_AMPDU_RX_DONE
value|193
define|#
directive|define
name|IWN_RX_DONE
value|195
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|qid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* possible Rx status flags */
end_comment

begin_define
define|#
directive|define
name|IWN_RX_NO_CRC_ERR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWN_RX_NO_OVFL_ERR
value|(1<< 1)
end_define

begin_comment
comment|/* shortcut for the above */
end_comment

begin_define
define|#
directive|define
name|IWN_RX_NOERROR
value|(IWN_RX_NO_CRC_ERR | IWN_RX_NO_OVFL_ERR)
end_define

begin_struct
struct|struct
name|iwn_tx_cmd
block|{
name|uint8_t
name|code
decl_stmt|;
define|#
directive|define
name|IWN_CMD_CONFIGURE
value|0x10
comment|/* REPLY_RXON */
define|#
directive|define
name|IWN_CMD_ASSOCIATE
value|0x11
comment|/* REPLY_RXON_ASSOC */
define|#
directive|define
name|IWN_CMD_EDCA_PARAMS
value|0x13
comment|/* REPLY_QOS_PARAM */
define|#
directive|define
name|IWN_CMD_TSF
value|0x14
comment|/* REPLY_RXON_TIMING */
define|#
directive|define
name|IWN_CMD_ADD_NODE
value|0x18
comment|/* REPLY_ADD_STA */
define|#
directive|define
name|IWN_CMD_TX_DATA
value|0x1c
comment|/* REPLY_TX */
define|#
directive|define
name|IWN_CMD_TX_LINK_QUALITY
value|0x4e
comment|/* REPLY_TX_LINK_QUALITY_CMD */
define|#
directive|define
name|IWN_CMD_SET_LED
value|0x48
comment|/* REPLY_LEDS_CMD */
define|#
directive|define
name|IWN_CMD_SET_POWER_MODE
value|0x77
comment|/* POWER_TABLE_CMD */
define|#
directive|define
name|IWN_CMD_SCAN
value|0x80
comment|/* REPLY_SCAN_CMD */
define|#
directive|define
name|IWN_CMD_TXPOWER
value|0x97
comment|/* REPLY_TX_PWR_TABLE_CMD */
define|#
directive|define
name|IWN_CMD_BLUETOOTH
value|0x9b
comment|/* REPLY_BT_CONFIG */
define|#
directive|define
name|IWN_CMD_GET_STATISTICS
value|0x9c
comment|/* REPLY_STATISTICS_CMD */
define|#
directive|define
name|IWN_CMD_SET_CRITICAL_TEMP
value|0xa4
comment|/* REPLY_CT_KILL_CONFIG_CMD */
define|#
directive|define
name|IWN_SENSITIVITY
value|0xa8
comment|/* SENSITIVITY_CMD */
define|#
directive|define
name|IWN_PHY_CALIB
value|0xb0
comment|/* REPLY_PHY_CALIBRATION_CMD */
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|qid
decl_stmt|;
name|uint8_t
name|data
index|[
literal|136
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_CONFIGURE (aka RXON) */
end_comment

begin_struct
struct|struct
name|iwn_config
block|{
name|uint8_t
name|myaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint8_t
name|wlap
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
name|uint8_t
name|mode
decl_stmt|;
define|#
directive|define
name|IWN_MODE_HOSTAP
value|1
define|#
directive|define
name|IWN_MODE_STA
value|3
define|#
directive|define
name|IWN_MODE_IBSS
value|4
define|#
directive|define
name|IWN_MODE_MONITOR
value|6
name|uint8_t
name|unused4
decl_stmt|;
comment|/* air propagation */
name|uint16_t
name|rxchain
decl_stmt|;
define|#
directive|define
name|IWN_RXCHAIN_VALID
value|0x000e
comment|/* which antennae are valid */
define|#
directive|define
name|IWN_RXCHAIN_VALID_S
value|1
define|#
directive|define
name|IWN_RXCHAIN_FORCE
value|0x0070
define|#
directive|define
name|IWN_RXCHAIN_FORCE_S
value|4
define|#
directive|define
name|IWN_RXCHAIN_FORCE_MIMO
value|0x0380
define|#
directive|define
name|IWN_RXCHAIN_FORCE_MIMO_S
value|7
define|#
directive|define
name|IWN_RXCHAIN_CNT
value|0x0c00
define|#
directive|define
name|IWN_RXCHAIN_CNT_S
value|10
define|#
directive|define
name|IWN_RXCHAIN_MIMO_CNT
value|0x3000
define|#
directive|define
name|IWN_RXCHAIN_MIMO_CNT_S
value|12
define|#
directive|define
name|IWN_RXCHAIN_MIMO_FORCE
value|0x4000
define|#
directive|define
name|IWN_RXCHAIN_MIMO_FORCE_S
value|14
name|uint8_t
name|ofdm_mask
decl_stmt|;
comment|/* basic rates */
name|uint8_t
name|cck_mask
decl_stmt|;
comment|/* basic rates */
name|uint16_t
name|associd
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_CONFIG_24GHZ
value|0x00000001
comment|/* band */
define|#
directive|define
name|IWN_CONFIG_CCK
value|0x00000002
comment|/* modulation */
define|#
directive|define
name|IWN_CONFIG_AUTO
value|0x00000004
comment|/* 2.4-only auto-detect */
define|#
directive|define
name|IWN_CONFIG_HTPROT
value|0x00000008
comment|/* xmit with HT protection */
define|#
directive|define
name|IWN_CONFIG_SHSLOT
value|0x00000010
comment|/* short slot time */
define|#
directive|define
name|IWN_CONFIG_SHPREAMBLE
value|0x00000020
comment|/* short premable */
define|#
directive|define
name|IWN_CONFIG_NODIVERSITY
value|0x00000080
comment|/* disable antenna diversity */
define|#
directive|define
name|IWN_CONFIG_ANTENNA_A
value|0x00000100
define|#
directive|define
name|IWN_CONFIG_ANTENNA_B
value|0x00000200
define|#
directive|define
name|IWN_CONFIG_RADAR
value|0x00001000
comment|/* enable radar detect */
define|#
directive|define
name|IWN_CONFIG_NARROW
value|0x00002000
comment|/* MKK narrow band select */
define|#
directive|define
name|IWN_CONFIG_TSF
value|0x00008000
define|#
directive|define
name|IWN_CONFIG_HT
value|0x06400000
define|#
directive|define
name|IWN_CONFIG_HT20
value|0x02000000
define|#
directive|define
name|IWN_CONFIG_HT40U
value|0x04000000
define|#
directive|define
name|IWN_CONFIG_HT40D
value|0x04400000
name|uint32_t
name|filter
decl_stmt|;
define|#
directive|define
name|IWN_FILTER_PROMISC
value|(1<< 0)
comment|/* pass all data frames */
define|#
directive|define
name|IWN_FILTER_CTL
value|(1<< 1)
comment|/* pass ctl+mgt frames */
define|#
directive|define
name|IWN_FILTER_MULTICAST
value|(1<< 2)
comment|/* pass multi-cast frames */
define|#
directive|define
name|IWN_FILTER_NODECRYPT
value|(1<< 3)
comment|/* pass unicast undecrypted */
define|#
directive|define
name|IWN_FILTER_BSS
value|(1<< 5)
comment|/* station is associated */
define|#
directive|define
name|IWN_FILTER_ALLBEACONS
value|(1<< 6)
comment|/* pass overlapping bss beacons 						   (must be associated) */
name|uint16_t
name|chan
decl_stmt|;
comment|/* IEEE channel # of control/primary */
name|uint8_t
name|ht_single_mask
decl_stmt|;
comment|/* single-stream basic rates */
name|uint8_t
name|ht_dual_mask
decl_stmt|;
comment|/* dual-stream basic rates */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_ASSOCIATE */
end_comment

begin_struct
struct|struct
name|iwn_assoc
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|filter
decl_stmt|;
name|uint8_t
name|ofdm_mask
decl_stmt|;
name|uint8_t
name|cck_mask
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_EDCA_PARAMS */
end_comment

begin_struct
struct|struct
name|iwn_edca_params
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_EDCA_UPDATE
value|(1<< 0)
define|#
directive|define
name|IWN_EDCA_TXOP
value|(1<< 4)
struct|struct
block|{
name|uint16_t
name|cwmin
decl_stmt|;
name|uint16_t
name|cwmax
decl_stmt|;
name|uint8_t
name|aifsn
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|txoplimit
decl_stmt|;
block|}
name|__packed
name|ac
index|[
name|EDCA_NUM_AC
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_TSF */
end_comment

begin_struct
struct|struct
name|iwn_cmd_tsf
block|{
name|uint64_t
name|tstamp
decl_stmt|;
name|uint16_t
name|bintval
decl_stmt|;
name|uint16_t
name|atim
decl_stmt|;
name|uint32_t
name|binitval
decl_stmt|;
name|uint16_t
name|lintval
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_ADD_NODE */
end_comment

begin_struct
struct|struct
name|iwn_node_info
block|{
name|uint8_t
name|control
decl_stmt|;
define|#
directive|define
name|IWN_NODE_UPDATE
value|(1<< 0)
name|uint8_t
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
define|#
directive|define
name|IWN_ID_BSS
value|0
define|#
directive|define
name|IWN_ID_BROADCAST
value|31
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_FLAG_SET_KEY
value|(1<< 0)
name|uint16_t
name|reserved3
decl_stmt|;
name|uint16_t
name|security
decl_stmt|;
name|uint8_t
name|tsc2
decl_stmt|;
comment|/* TKIP TSC2 */
name|uint8_t
name|reserved4
decl_stmt|;
name|uint16_t
name|ttak
index|[
literal|5
index|]
decl_stmt|;
name|uint16_t
name|reserved5
decl_stmt|;
name|uint8_t
name|key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
name|uint32_t
name|htflags
decl_stmt|;
define|#
directive|define
name|IWN_MAXRXAMPDU_S
value|19
define|#
directive|define
name|IWN_MPDUDENSITY_S
value|23
name|uint32_t
name|mask
decl_stmt|;
name|uint16_t
name|tid
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
comment|/* legacy rate/MCS */
define|#
directive|define
name|IWN_RATE_MCS
value|0x08
comment|/* or'd to indicate MCS */
name|uint8_t
name|rflags
decl_stmt|;
define|#
directive|define
name|IWN_RFLAG_HT
value|(1<< 0)
comment|/* use HT modulation */
define|#
directive|define
name|IWN_RFLAG_CCK
value|(1<< 1)
comment|/* use CCK modulation */
define|#
directive|define
name|IWN_RFLAG_HT40
value|(1<< 3)
comment|/* use dual-stream */
define|#
directive|define
name|IWN_RFLAG_SGI
value|(1<< 5)
comment|/* use short GI */
define|#
directive|define
name|IWN_RFLAG_ANT_A
value|(1<< 6)
comment|/* start on antenna port A */
define|#
directive|define
name|IWN_RFLAG_ANT_B
value|(1<< 7)
comment|/* start on antenna port B */
name|uint8_t
name|add_imm
decl_stmt|;
name|uint8_t
name|del_imm
decl_stmt|;
name|uint16_t
name|add_imm_start
decl_stmt|;
name|uint32_t
name|reserved6
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_TX_DATA */
end_comment

begin_struct
struct|struct
name|iwn_cmd_data
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|lnext
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_TX_NEED_RTS
value|(1<<  1)
define|#
directive|define
name|IWN_TX_NEED_CTS
value|(1<<  2)
define|#
directive|define
name|IWN_TX_NEED_ACK
value|(1<<  3)
define|#
directive|define
name|IWN_TX_USE_NODE_RATE
value|(1<<  4)
define|#
directive|define
name|IWN_TX_FULL_TXOP
value|(1<<  7)
define|#
directive|define
name|IWN_TX_BT_DISABLE
value|(1<< 12)
comment|/* bluetooth coexistence */
define|#
directive|define
name|IWN_TX_AUTO_SEQ
value|(1<< 13)
define|#
directive|define
name|IWN_TX_INSERT_TSTAMP
value|(1<< 16)
define|#
directive|define
name|IWN_TX_NEED_PADDING
value|(1<< 20)
name|uint8_t
name|ntries
decl_stmt|;
name|uint8_t
name|bluetooth
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|security
decl_stmt|;
define|#
directive|define
name|IWN_CIPHER_WEP40
value|1
define|#
directive|define
name|IWN_CIPHER_CCMP
value|2
define|#
directive|define
name|IWN_CIPHER_TKIP
value|3
define|#
directive|define
name|IWN_CIPHER_WEP104
value|9
name|uint8_t
name|ridx
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|key
index|[
name|IEEE80211_KEYBUF_SIZE
index|]
decl_stmt|;
name|uint16_t
name|fnext
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
name|uint32_t
name|lifetime
decl_stmt|;
define|#
directive|define
name|IWN_LIFETIME_INFINITE
value|0xffffffff
name|uint32_t
name|loaddr
decl_stmt|;
name|uint8_t
name|hiaddr
decl_stmt|;
name|uint8_t
name|rts_ntries
decl_stmt|;
name|uint8_t
name|data_ntries
decl_stmt|;
name|uint8_t
name|tid
decl_stmt|;
name|uint16_t
name|timeout
decl_stmt|;
name|uint16_t
name|txop
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_TX_LINK_QUALITY */
end_comment

begin_define
define|#
directive|define
name|IWN_MAX_TX_RETRIES
value|16
end_define

begin_struct
struct|struct
name|iwn_cmd_link_quality
block|{
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|ctl
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|mimo
decl_stmt|;
comment|/* MIMO delimiter */
name|uint8_t
name|ssmask
decl_stmt|;
comment|/* single stream antenna mask */
name|uint8_t
name|dsmask
decl_stmt|;
comment|/* dual stream antenna mask */
name|uint8_t
name|ridx
index|[
name|EDCA_NUM_AC
index|]
decl_stmt|;
comment|/* starting rate index */
name|uint16_t
name|ampdu_limit
decl_stmt|;
comment|/* tx aggregation time limit */
name|uint8_t
name|ampdu_disable
decl_stmt|;
name|uint8_t
name|ampdu_max
decl_stmt|;
comment|/* frame count limit */
name|uint32_t
name|reserved2
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|rate
decl_stmt|;
define|#
directive|define
name|IWN_RATE_CCK1
value|0
define|#
directive|define
name|IWN_RATE_CCK11
value|3
define|#
directive|define
name|IWN_RATE_OFDM6
value|4
define|#
directive|define
name|IWN_RATE_OFDM54
value|11
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
block|}
name|table
index|[
name|IWN_MAX_TX_RETRIES
index|]
struct|;
name|uint32_t
name|reserved3
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_SET_LED */
end_comment

begin_struct
struct|struct
name|iwn_cmd_led
block|{
name|uint32_t
name|unit
decl_stmt|;
comment|/* multiplier (in usecs) */
name|uint8_t
name|which
decl_stmt|;
define|#
directive|define
name|IWN_LED_ACTIVITY
value|1
define|#
directive|define
name|IWN_LED_LINK
value|2
name|uint8_t
name|off
decl_stmt|;
name|uint8_t
name|on
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_SET_POWER_MODE */
end_comment

begin_struct
struct|struct
name|iwn_power
block|{
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_POWER_CAM
value|0
comment|/* constantly awake mode */
name|uint8_t
name|alive
decl_stmt|;
name|uint8_t
name|debug
decl_stmt|;
name|uint32_t
name|rx_timeout
decl_stmt|;
name|uint32_t
name|tx_timeout
decl_stmt|;
name|uint32_t
name|sleep
index|[
literal|5
index|]
decl_stmt|;
name|uint32_t
name|beacons
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structures for command IWN_CMD_SCAN */
end_comment

begin_struct
struct|struct
name|iwn_scan_essid
block|{
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|data
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_scan_hdr
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|nchan
decl_stmt|;
name|uint16_t
name|quiet
decl_stmt|;
name|uint16_t
name|plcp_threshold
decl_stmt|;
name|uint16_t
name|crc_threshold
decl_stmt|;
name|uint16_t
name|rxchain
decl_stmt|;
name|uint32_t
name|max_svc
decl_stmt|;
comment|/* background scans */
name|uint32_t
name|pause_svc
decl_stmt|;
comment|/* background scans */
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|filter
decl_stmt|;
comment|/* followed by a struct iwn_cmd_data */
comment|/* followed by an array of 4x struct iwn_scan_essid */
comment|/* followed by probe request body */
comment|/* followed by nchan x struct iwn_scan_chan */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_scan_chan
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_CHAN_ACTIVE
value|(1<< 0)
define|#
directive|define
name|IWN_CHAN_DIRECT
value|(1<< 1)
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|rf_gain
decl_stmt|;
name|uint8_t
name|dsp_gain
decl_stmt|;
name|uint16_t
name|active
decl_stmt|;
comment|/* msecs */
name|uint16_t
name|passive
decl_stmt|;
comment|/* msecs */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_TXPOWER */
end_comment

begin_define
define|#
directive|define
name|IWN_RIDX_MAX
value|32
end_define

begin_struct
struct|struct
name|iwn_cmd_txpower
block|{
name|uint8_t
name|band
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|rf_gain
index|[
name|IWN_NTXCHAINS
index|]
decl_stmt|;
name|uint8_t
name|dsp_gain
index|[
name|IWN_NTXCHAINS
index|]
decl_stmt|;
block|}
name|power
index|[
name|IWN_RIDX_MAX
operator|+
literal|1
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_BLUETOOTH */
end_comment

begin_struct
struct|struct
name|iwn_bluetooth
block|{
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|lead
decl_stmt|;
name|uint8_t
name|kill
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint32_t
name|ack
decl_stmt|;
name|uint32_t
name|cts
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_CMD_SET_CRITICAL_TEMP */
end_comment

begin_struct
struct|struct
name|iwn_critical_temp
block|{
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|tempM
decl_stmt|;
name|uint32_t
name|tempR
decl_stmt|;
comment|/* degK<-> degC conversion macros */
define|#
directive|define
name|IWN_CTOK
parameter_list|(
name|c
parameter_list|)
value|((c) + 273)
define|#
directive|define
name|IWN_KTOC
parameter_list|(
name|k
parameter_list|)
value|((k) - 273)
define|#
directive|define
name|IWN_CTOMUK
parameter_list|(
name|c
parameter_list|)
value|(((c) * 1000000) + 273150000)
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_SENSITIVITY */
end_comment

begin_struct
struct|struct
name|iwn_sensitivity_cmd
block|{
name|uint16_t
name|which
decl_stmt|;
define|#
directive|define
name|IWN_SENSITIVITY_DEFAULTTBL
value|0
define|#
directive|define
name|IWN_SENSITIVITY_WORKTBL
value|1
name|uint16_t
name|energy_cck
decl_stmt|;
name|uint16_t
name|energy_ofdm
decl_stmt|;
name|uint16_t
name|corr_ofdm_x1
decl_stmt|;
name|uint16_t
name|corr_ofdm_mrc_x1
decl_stmt|;
name|uint16_t
name|corr_cck_mrc_x4
decl_stmt|;
name|uint16_t
name|corr_ofdm_x4
decl_stmt|;
name|uint16_t
name|corr_ofdm_mrc_x4
decl_stmt|;
name|uint16_t
name|corr_barker
decl_stmt|;
name|uint16_t
name|corr_barker_mrc
decl_stmt|;
name|uint16_t
name|corr_cck_x4
decl_stmt|;
name|uint16_t
name|energy_ofdm_th
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for command IWN_PHY_CALIB */
end_comment

begin_struct
struct|struct
name|iwn_phy_calib_cmd
block|{
name|uint8_t
name|code
decl_stmt|;
define|#
directive|define
name|IWN_SET_DIFF_GAIN
value|7
name|uint8_t
name|flags
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|int8_t
name|gain
index|[
literal|3
index|]
decl_stmt|;
define|#
directive|define
name|IWN_GAIN_SET
value|(1<< 2)
name|uint8_t
name|reserved2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for IWN_UC_READY notification */
end_comment

begin_define
define|#
directive|define
name|IWN_NATTEN_GROUPS
value|5
end_define

begin_struct
struct|struct
name|iwn_ucode_info
block|{
name|uint8_t
name|minor
decl_stmt|;
name|uint8_t
name|major
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|revision
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|subtype
decl_stmt|;
define|#
directive|define
name|IWN_UCODE_RUNTIME
value|0
define|#
directive|define
name|IWN_UCODE_INIT
value|9
name|uint16_t
name|reserved2
decl_stmt|;
name|uint32_t
name|logptr
decl_stmt|;
name|uint32_t
name|errorptr
decl_stmt|;
name|uint32_t
name|tstamp
decl_stmt|;
name|uint32_t
name|valid
decl_stmt|;
comment|/* the following fields are for UCODE_INIT only */
name|int32_t
name|volt
decl_stmt|;
struct|struct
block|{
name|int32_t
name|chan20MHz
decl_stmt|;
name|int32_t
name|chan40MHz
decl_stmt|;
block|}
name|__packed
name|temp
index|[
literal|4
index|]
struct|;
name|int32_t
name|atten
index|[
name|IWN_NATTEN_GROUPS
index|]
index|[
name|IWN_NTXCHAINS
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for IWN_TX_DONE notification */
end_comment

begin_struct
struct|struct
name|iwn_tx_stat
block|{
name|uint8_t
name|nframes
decl_stmt|;
name|uint8_t
name|nkill
decl_stmt|;
name|uint8_t
name|nrts
decl_stmt|;
name|uint8_t
name|ntries
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
name|uint16_t
name|duration
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|power
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
define|#
directive|define
name|IWN_TX_SUCCESS
value|0x00
define|#
directive|define
name|IWN_TX_FAIL
value|0x80
comment|/* all failures have 0x80 set */
define|#
directive|define
name|IWN_TX_FAIL_SHORT_LIMIT
value|0x82
comment|/* too many RTS retries */
define|#
directive|define
name|IWN_TX_FAIL_LONG_LIMIT
value|0x83
comment|/* too many retries */
define|#
directive|define
name|IWN_TX_FAIL_FIFO_UNDERRRUN
value|0x84
comment|/* tx fifo not kept running */
define|#
directive|define
name|IWN_TX_FAIL_DEST_IN_PS
value|0x88
comment|/* sta found in power save */
define|#
directive|define
name|IWN_TX_FAIL_TX_LOCKED
value|0x90
comment|/* waiting to see traffic */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for IWN_BEACON_MISSED notification */
end_comment

begin_struct
struct|struct
name|iwn_beacon_missed
block|{
name|uint32_t
name|consecutive
decl_stmt|;
name|uint32_t
name|total
decl_stmt|;
name|uint32_t
name|expected
decl_stmt|;
name|uint32_t
name|received
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for IWN_AMPDU_RX_DONE notification */
end_comment

begin_struct
struct|struct
name|iwn_rx_ampdu
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for IWN_RX_DONE and IWN_AMPDU_RX_START notifications */
end_comment

begin_struct
struct|struct
name|iwn_rx_stat
block|{
name|uint8_t
name|phy_len
decl_stmt|;
name|uint8_t
name|cfg_phy_len
decl_stmt|;
define|#
directive|define
name|IWN_STAT_MAXLEN
value|20
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint64_t
name|tstamp
decl_stmt|;
name|uint32_t
name|beacon
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|chan
decl_stmt|;
name|uint16_t
name|antenna
decl_stmt|;
name|uint16_t
name|agc
decl_stmt|;
name|uint8_t
name|rssi
index|[
literal|6
index|]
decl_stmt|;
define|#
directive|define
name|IWN_RSSI_TO_DBM
value|44
name|uint8_t
name|reserved2
index|[
literal|22
index|]
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|reserve3
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for IWN_START_SCAN notification */
end_comment

begin_struct
struct|struct
name|iwn_start_scan
block|{
name|uint64_t
name|tstamp
decl_stmt|;
name|uint32_t
name|tbeacon
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|band
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for IWN_STOP_SCAN notification */
end_comment

begin_struct
struct|struct
name|iwn_stop_scan
block|{
name|uint8_t
name|nchan
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|chan
decl_stmt|;
name|uint64_t
name|tsf
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* structure for IWN_{RX,BEACON}_STATISTICS notification */
end_comment

begin_struct
struct|struct
name|iwn_rx_phy_stats
block|{
name|uint32_t
name|ina
decl_stmt|;
name|uint32_t
name|fina
decl_stmt|;
name|uint32_t
name|bad_plcp
decl_stmt|;
name|uint32_t
name|bad_crc32
decl_stmt|;
name|uint32_t
name|overrun
decl_stmt|;
name|uint32_t
name|eoverrun
decl_stmt|;
name|uint32_t
name|good_crc32
decl_stmt|;
name|uint32_t
name|fa
decl_stmt|;
name|uint32_t
name|bad_fina_sync
decl_stmt|;
name|uint32_t
name|sfd_timeout
decl_stmt|;
name|uint32_t
name|fina_timeout
decl_stmt|;
name|uint32_t
name|no_rts_ack
decl_stmt|;
name|uint32_t
name|rxe_limit
decl_stmt|;
name|uint32_t
name|ack
decl_stmt|;
name|uint32_t
name|cts
decl_stmt|;
name|uint32_t
name|ba_resp
decl_stmt|;
name|uint32_t
name|dsp_kill
decl_stmt|;
name|uint32_t
name|bad_mh
decl_stmt|;
name|uint32_t
name|rssi_sum
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_rx_general_stats
block|{
name|uint32_t
name|bad_cts
decl_stmt|;
name|uint32_t
name|bad_ack
decl_stmt|;
name|uint32_t
name|not_bss
decl_stmt|;
name|uint32_t
name|filtered
decl_stmt|;
name|uint32_t
name|bad_chan
decl_stmt|;
name|uint32_t
name|beacons
decl_stmt|;
name|uint32_t
name|missed_beacons
decl_stmt|;
name|uint32_t
name|adc_saturated
decl_stmt|;
comment|/* time in 0.8us */
name|uint32_t
name|ina_searched
decl_stmt|;
comment|/* time in 0.8us */
name|uint32_t
name|noise
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|load
decl_stmt|;
name|uint32_t
name|fa
decl_stmt|;
name|uint32_t
name|rssi
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|energy
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_rx_ht_phy_stats
block|{
name|uint32_t
name|bad_plcp
decl_stmt|;
name|uint32_t
name|overrun
decl_stmt|;
name|uint32_t
name|eoverrun
decl_stmt|;
name|uint32_t
name|good_crc32
decl_stmt|;
name|uint32_t
name|bad_crc32
decl_stmt|;
name|uint32_t
name|bad_mh
decl_stmt|;
name|uint32_t
name|good_ampdu_crc32
decl_stmt|;
name|uint32_t
name|ampdu
decl_stmt|;
name|uint32_t
name|fragment
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_rx_stats
block|{
name|struct
name|iwn_rx_phy_stats
name|ofdm
decl_stmt|;
name|struct
name|iwn_rx_phy_stats
name|cck
decl_stmt|;
name|struct
name|iwn_rx_general_stats
name|general
decl_stmt|;
name|struct
name|iwn_rx_ht_phy_stats
name|ht
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_tx_stats
block|{
name|uint32_t
name|preamble
decl_stmt|;
name|uint32_t
name|rx_detected
decl_stmt|;
name|uint32_t
name|bt_defer
decl_stmt|;
name|uint32_t
name|bt_kill
decl_stmt|;
name|uint32_t
name|short_len
decl_stmt|;
name|uint32_t
name|cts_timeout
decl_stmt|;
name|uint32_t
name|ack_timeout
decl_stmt|;
name|uint32_t
name|exp_ack
decl_stmt|;
name|uint32_t
name|ack
decl_stmt|;
name|uint32_t
name|msdu
decl_stmt|;
name|uint32_t
name|busrt_err1
decl_stmt|;
name|uint32_t
name|burst_err2
decl_stmt|;
name|uint32_t
name|cts_collision
decl_stmt|;
name|uint32_t
name|ack_collision
decl_stmt|;
name|uint32_t
name|ba_timeout
decl_stmt|;
name|uint32_t
name|ba_resched
decl_stmt|;
name|uint32_t
name|query_ampdu
decl_stmt|;
name|uint32_t
name|query
decl_stmt|;
name|uint32_t
name|query_ampdu_frag
decl_stmt|;
name|uint32_t
name|query_mismatch
decl_stmt|;
name|uint32_t
name|not_ready
decl_stmt|;
name|uint32_t
name|underrun
decl_stmt|;
name|uint32_t
name|bt_ht_kill
decl_stmt|;
name|uint32_t
name|rx_ba_resp
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

begin_struct
struct|struct
name|iwn_general_stats
block|{
name|uint32_t
name|temp
decl_stmt|;
name|uint32_t
name|temp_m
decl_stmt|;
name|uint32_t
name|burst_check
decl_stmt|;
name|uint32_t
name|burst
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|sleep
decl_stmt|;
name|uint32_t
name|slot_out
decl_stmt|;
name|uint32_t
name|slot_idle
decl_stmt|;
name|uint32_t
name|ttl_tstamp
decl_stmt|;
name|uint32_t
name|tx_ant_a
decl_stmt|;
name|uint32_t
name|tx_ant_b
decl_stmt|;
name|uint32_t
name|exec
decl_stmt|;
name|uint32_t
name|probe
decl_stmt|;
name|uint32_t
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|rx_enabled
decl_stmt|;
name|uint32_t
name|reserved3
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwn_stats
block|{
name|uint32_t
name|flags
decl_stmt|;
name|struct
name|iwn_rx_stats
name|rx
decl_stmt|;
name|struct
name|iwn_tx_stats
name|tx
decl_stmt|;
name|struct
name|iwn_general_stats
name|general
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* firmware image header */
end_comment

begin_struct
struct|struct
name|iwn_firmware_hdr
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|main_textsz
decl_stmt|;
name|uint32_t
name|main_datasz
decl_stmt|;
name|uint32_t
name|init_textsz
decl_stmt|;
name|uint32_t
name|init_datasz
decl_stmt|;
name|uint32_t
name|boot_textsz
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_FW_MAIN_TEXT_MAXSZ
value|(96 * 1024)
end_define

begin_define
define|#
directive|define
name|IWN_FW_MAIN_DATA_MAXSZ
value|(40 * 1024)
end_define

begin_define
define|#
directive|define
name|IWN_FW_INIT_TEXT_MAXSZ
value|(96 * 1024)
end_define

begin_define
define|#
directive|define
name|IWN_FW_INIT_DATA_MAXSZ
value|(40 * 1024)
end_define

begin_define
define|#
directive|define
name|IWN_FW_BOOT_TEXT_MAXSZ
value|1024
end_define

begin_comment
comment|/*  * Offsets into EEPROM.  */
end_comment

begin_define
define|#
directive|define
name|IWN_EEPROM_MAC
value|0x015
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_DOMAIN
value|0x060
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_BAND1
value|0x063
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_BAND2
value|0x072
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_BAND3
value|0x080
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_BAND4
value|0x08d
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_BAND5
value|0x099
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_BAND6
value|0x0a0
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_BAND7
value|0x0a8
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_MAXPOW
value|0x0e8
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_VOLTAGE
value|0x0e9
end_define

begin_define
define|#
directive|define
name|IWN_EEPROM_BANDS
value|0x0ea
end_define

begin_struct
struct|struct
name|iwn_eeprom_chan
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWN_EEPROM_CHAN_VALID
value|(1<< 0)
define|#
directive|define
name|IWN_EEPROM_CHAN_IBSS
value|(1<< 1)
comment|/* adhoc permitted */
comment|/* NB: bit 2 is reserved */
define|#
directive|define
name|IWN_EEPROM_CHAN_ACTIVE
value|(1<< 3)
comment|/* active/passive scan */
define|#
directive|define
name|IWN_EEPROM_CHAN_RADAR
value|(1<< 4)
comment|/* DFS required */
define|#
directive|define
name|IWN_EEPROM_CHAN_WIDE
value|(1<< 5)
comment|/* HT40 */
define|#
directive|define
name|IWN_EEPROM_CHAN_NARROW
value|(1<< 6)
comment|/* HT20 */
name|int8_t
name|maxpwr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_NSAMPLES
value|3
end_define

begin_struct
struct|struct
name|iwn_eeprom_chan_samples
block|{
name|uint8_t
name|num
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|temp
decl_stmt|;
name|uint8_t
name|gain
decl_stmt|;
name|uint8_t
name|power
decl_stmt|;
name|int8_t
name|pa_det
decl_stmt|;
block|}
name|samples
index|[
name|IWN_NTXCHAINS
index|]
index|[
name|IWN_NSAMPLES
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWN_NBANDS
value|8
end_define

begin_struct
struct|struct
name|iwn_eeprom_band
block|{
name|uint8_t
name|lo
decl_stmt|;
comment|/* low channel number */
name|uint8_t
name|hi
decl_stmt|;
comment|/* high channel number */
name|struct
name|iwn_eeprom_chan_samples
name|chans
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
name|IWN_MAX_PWR_INDEX
value|107
end_define

begin_comment
comment|/*  * RF Tx gain values from highest to lowest power (values obtained from  * the reference driver.)  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|iwn_rf_gain_2ghz
index|[
name|IWN_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3e
block|,
literal|0x3e
block|,
literal|0x3e
block|,
literal|0x3d
block|,
literal|0x3d
block|,
literal|0x3d
block|,
literal|0x3c
block|,
literal|0x3c
block|,
literal|0x3c
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3a
block|,
literal|0x3a
block|,
literal|0x3a
block|,
literal|0x39
block|,
literal|0x39
block|,
literal|0x39
block|,
literal|0x38
block|,
literal|0x38
block|,
literal|0x38
block|,
literal|0x37
block|,
literal|0x37
block|,
literal|0x37
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x35
block|,
literal|0x35
block|,
literal|0x35
block|,
literal|0x34
block|,
literal|0x34
block|,
literal|0x34
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x31
block|,
literal|0x31
block|,
literal|0x31
block|,
literal|0x30
block|,
literal|0x30
block|,
literal|0x30
block|,
literal|0x06
block|,
literal|0x06
block|,
literal|0x06
block|,
literal|0x05
block|,
literal|0x05
block|,
literal|0x05
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|iwn_rf_gain_5ghz
index|[
name|IWN_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3f
block|,
literal|0x3e
block|,
literal|0x3e
block|,
literal|0x3e
block|,
literal|0x3d
block|,
literal|0x3d
block|,
literal|0x3d
block|,
literal|0x3c
block|,
literal|0x3c
block|,
literal|0x3c
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3b
block|,
literal|0x3a
block|,
literal|0x3a
block|,
literal|0x3a
block|,
literal|0x39
block|,
literal|0x39
block|,
literal|0x39
block|,
literal|0x38
block|,
literal|0x38
block|,
literal|0x38
block|,
literal|0x37
block|,
literal|0x37
block|,
literal|0x37
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x35
block|,
literal|0x35
block|,
literal|0x35
block|,
literal|0x34
block|,
literal|0x34
block|,
literal|0x34
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x33
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x31
block|,
literal|0x31
block|,
literal|0x31
block|,
literal|0x30
block|,
literal|0x30
block|,
literal|0x30
block|,
literal|0x25
block|,
literal|0x25
block|,
literal|0x25
block|,
literal|0x24
block|,
literal|0x24
block|,
literal|0x24
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x23
block|,
literal|0x22
block|,
literal|0x18
block|,
literal|0x18
block|,
literal|0x17
block|,
literal|0x17
block|,
literal|0x17
block|,
literal|0x16
block|,
literal|0x16
block|,
literal|0x16
block|,
literal|0x15
block|,
literal|0x15
block|,
literal|0x15
block|,
literal|0x14
block|,
literal|0x14
block|,
literal|0x14
block|,
literal|0x13
block|,
literal|0x13
block|,
literal|0x13
block|,
literal|0x12
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x07
block|,
literal|0x07
block|,
literal|0x07
block|,
literal|0x06
block|,
literal|0x06
block|,
literal|0x06
block|,
literal|0x05
block|,
literal|0x05
block|,
literal|0x05
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x03
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * DSP pre-DAC gain values from highest to lowest power (values obtained  * from the reference driver.)  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|iwn_dsp_gain_2ghz
index|[
name|IWN_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x61
block|,
literal|0x60
block|,
literal|0x5f
block|,
literal|0x5e
block|,
literal|0x5d
block|,
literal|0x5c
block|,
literal|0x5b
block|,
literal|0x5a
block|,
literal|0x59
block|,
literal|0x58
block|,
literal|0x57
block|,
literal|0x56
block|,
literal|0x55
block|,
literal|0x54
block|,
literal|0x53
block|,
literal|0x52
block|,
literal|0x51
block|,
literal|0x50
block|,
literal|0x4f
block|,
literal|0x4e
block|,
literal|0x4d
block|,
literal|0x4c
block|,
literal|0x4b
block|,
literal|0x4a
block|,
literal|0x49
block|,
literal|0x48
block|,
literal|0x47
block|,
literal|0x46
block|,
literal|0x45
block|,
literal|0x44
block|,
literal|0x43
block|,
literal|0x42
block|,
literal|0x41
block|,
literal|0x40
block|,
literal|0x3f
block|,
literal|0x3e
block|,
literal|0x3d
block|,
literal|0x3c
block|,
literal|0x3b
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|iwn_dsp_gain_5ghz
index|[
name|IWN_MAX_PWR_INDEX
operator|+
literal|1
index|]
init|=
block|{
literal|0x7b
block|,
literal|0x75
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x6e
block|,
literal|0x68
block|,
literal|0x62
block|,
literal|0x5d
block|,
literal|0x58
block|,
literal|0x53
block|,
literal|0x4e
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IWN_READ
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
name|IWN_WRITE
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

begin_define
define|#
directive|define
name|IWN_WRITE_REGION_4
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|datap
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_region_4((sc)->sc_st, (sc)->sc_sh, (offset),	\ 	    (datap), (count))
end_define

end_unit

