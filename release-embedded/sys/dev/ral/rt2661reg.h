begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006  *	Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|RT2661_NOISE_FLOOR
value|-95
end_define

begin_define
define|#
directive|define
name|RT2661_TX_RING_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|RT2661_MGT_RING_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|RT2661_RX_RING_COUNT
value|64
end_define

begin_define
define|#
directive|define
name|RT2661_TX_DESC_SIZE
value|(sizeof (struct rt2661_tx_desc))
end_define

begin_define
define|#
directive|define
name|RT2661_TX_DESC_WSIZE
value|(RT2661_TX_DESC_SIZE / 4)
end_define

begin_define
define|#
directive|define
name|RT2661_RX_DESC_SIZE
value|(sizeof (struct rt2661_rx_desc))
end_define

begin_define
define|#
directive|define
name|RT2661_RX_DESC_WSIZE
value|(RT2661_RX_DESC_SIZE / 4)
end_define

begin_define
define|#
directive|define
name|RT2661_MAX_SCATTER
value|5
end_define

begin_comment
comment|/*  * Control and status registers.  */
end_comment

begin_define
define|#
directive|define
name|RT2661_HOST_CMD_CSR
value|0x0008
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_CNTL_CSR
value|0x000c
end_define

begin_define
define|#
directive|define
name|RT2661_SOFT_RESET_CSR
value|0x0010
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_INT_SOURCE_CSR
value|0x0014
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_INT_MASK_CSR
value|0x0018
end_define

begin_define
define|#
directive|define
name|RT2661_PCI_USEC_CSR
value|0x001c
end_define

begin_define
define|#
directive|define
name|RT2661_H2M_MAILBOX_CSR
value|0x2100
end_define

begin_define
define|#
directive|define
name|RT2661_M2H_CMD_DONE_CSR
value|0x2104
end_define

begin_define
define|#
directive|define
name|RT2661_HW_BEACON_BASE0
value|0x2c00
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR0
value|0x3000
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR1
value|0x3004
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR2
value|0x3008
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR3
value|0x300c
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR4
value|0x3010
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR5
value|0x3014
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR6
value|0x3018
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR7
value|0x301c
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR8
value|0x3020
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR9
value|0x3024
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR10
value|0x3028
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR11
value|0x302c
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR12
value|0x3030
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR13
value|0x3034
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR14
value|0x3038
end_define

begin_define
define|#
directive|define
name|RT2661_MAC_CSR15
value|0x303c
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR0
value|0x3040
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR1
value|0x3044
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR2
value|0x3048
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR3
value|0x304c
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR4
value|0x3050
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR5
value|0x3054
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR6
value|0x3058
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR7
value|0x305c
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR8
value|0x3060
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR9
value|0x3064
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR10
value|0x3068
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR11
value|0x306c
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR12
value|0x3070
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR13
value|0x3074
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR14
value|0x3078
end_define

begin_define
define|#
directive|define
name|RT2661_TXRX_CSR15
value|0x307c
end_define

begin_define
define|#
directive|define
name|RT2661_PHY_CSR0
value|0x3080
end_define

begin_define
define|#
directive|define
name|RT2661_PHY_CSR1
value|0x3084
end_define

begin_define
define|#
directive|define
name|RT2661_PHY_CSR2
value|0x3088
end_define

begin_define
define|#
directive|define
name|RT2661_PHY_CSR3
value|0x308c
end_define

begin_define
define|#
directive|define
name|RT2661_PHY_CSR4
value|0x3090
end_define

begin_define
define|#
directive|define
name|RT2661_PHY_CSR5
value|0x3094
end_define

begin_define
define|#
directive|define
name|RT2661_PHY_CSR6
value|0x3098
end_define

begin_define
define|#
directive|define
name|RT2661_PHY_CSR7
value|0x309c
end_define

begin_define
define|#
directive|define
name|RT2661_SEC_CSR0
value|0x30a0
end_define

begin_define
define|#
directive|define
name|RT2661_SEC_CSR1
value|0x30a4
end_define

begin_define
define|#
directive|define
name|RT2661_SEC_CSR2
value|0x30a8
end_define

begin_define
define|#
directive|define
name|RT2661_SEC_CSR3
value|0x30ac
end_define

begin_define
define|#
directive|define
name|RT2661_SEC_CSR4
value|0x30b0
end_define

begin_define
define|#
directive|define
name|RT2661_SEC_CSR5
value|0x30b4
end_define

begin_define
define|#
directive|define
name|RT2661_STA_CSR0
value|0x30c0
end_define

begin_define
define|#
directive|define
name|RT2661_STA_CSR1
value|0x30c4
end_define

begin_define
define|#
directive|define
name|RT2661_STA_CSR2
value|0x30c8
end_define

begin_define
define|#
directive|define
name|RT2661_STA_CSR3
value|0x30cc
end_define

begin_define
define|#
directive|define
name|RT2661_STA_CSR4
value|0x30d0
end_define

begin_define
define|#
directive|define
name|RT2661_AC0_BASE_CSR
value|0x3400
end_define

begin_define
define|#
directive|define
name|RT2661_AC1_BASE_CSR
value|0x3404
end_define

begin_define
define|#
directive|define
name|RT2661_AC2_BASE_CSR
value|0x3408
end_define

begin_define
define|#
directive|define
name|RT2661_AC3_BASE_CSR
value|0x340c
end_define

begin_define
define|#
directive|define
name|RT2661_MGT_BASE_CSR
value|0x3410
end_define

begin_define
define|#
directive|define
name|RT2661_TX_RING_CSR0
value|0x3418
end_define

begin_define
define|#
directive|define
name|RT2661_TX_RING_CSR1
value|0x341c
end_define

begin_define
define|#
directive|define
name|RT2661_AIFSN_CSR
value|0x3420
end_define

begin_define
define|#
directive|define
name|RT2661_CWMIN_CSR
value|0x3424
end_define

begin_define
define|#
directive|define
name|RT2661_CWMAX_CSR
value|0x3428
end_define

begin_define
define|#
directive|define
name|RT2661_TX_DMA_DST_CSR
value|0x342c
end_define

begin_define
define|#
directive|define
name|RT2661_TX_CNTL_CSR
value|0x3430
end_define

begin_define
define|#
directive|define
name|RT2661_LOAD_TX_RING_CSR
value|0x3434
end_define

begin_define
define|#
directive|define
name|RT2661_RX_BASE_CSR
value|0x3450
end_define

begin_define
define|#
directive|define
name|RT2661_RX_RING_CSR
value|0x3454
end_define

begin_define
define|#
directive|define
name|RT2661_RX_CNTL_CSR
value|0x3458
end_define

begin_define
define|#
directive|define
name|RT2661_PCI_CFG_CSR
value|0x3460
end_define

begin_define
define|#
directive|define
name|RT2661_INT_SOURCE_CSR
value|0x3468
end_define

begin_define
define|#
directive|define
name|RT2661_INT_MASK_CSR
value|0x346c
end_define

begin_define
define|#
directive|define
name|RT2661_E2PROM_CSR
value|0x3470
end_define

begin_define
define|#
directive|define
name|RT2661_AC_TXOP_CSR0
value|0x3474
end_define

begin_define
define|#
directive|define
name|RT2661_AC_TXOP_CSR1
value|0x3478
end_define

begin_define
define|#
directive|define
name|RT2661_TEST_MODE_CSR
value|0x3484
end_define

begin_define
define|#
directive|define
name|RT2661_IO_CNTL_CSR
value|0x3498
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_CODE_BASE
value|0x4000
end_define

begin_comment
comment|/* possible flags for register HOST_CMD_CSR */
end_comment

begin_define
define|#
directive|define
name|RT2661_KICK_CMD
value|(1<< 7)
end_define

begin_comment
comment|/* Host to MCU (8051) command identifiers */
end_comment

begin_define
define|#
directive|define
name|RT2661_MCU_CMD_SLEEP
value|0x30
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_CMD_WAKEUP
value|0x31
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_SET_LED
value|0x50
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_SET_RSSI_LED
value|0x52
end_define

begin_comment
comment|/* possible flags for register MCU_CNTL_CSR */
end_comment

begin_define
define|#
directive|define
name|RT2661_MCU_SEL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_READY
value|(1<< 2)
end_define

begin_comment
comment|/* possible flags for register MCU_INT_SOURCE_CSR */
end_comment

begin_define
define|#
directive|define
name|RT2661_MCU_CMD_DONE
value|0xff
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_WAKEUP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RT2661_MCU_BEACON_EXPIRE
value|(1<< 9)
end_define

begin_comment
comment|/* possible flags for register H2M_MAILBOX_CSR */
end_comment

begin_define
define|#
directive|define
name|RT2661_H2M_BUSY
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2661_TOKEN_NO_INTR
value|0xff
end_define

begin_comment
comment|/* possible flags for register MAC_CSR5 */
end_comment

begin_define
define|#
directive|define
name|RT2661_ONE_BSSID
value|3
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
name|RT2661_AUTO_TX_SEQ
value|(1<< 15)
end_define

begin_comment
comment|/* Rx filter flags are in the high 16 bits */
end_comment

begin_define
define|#
directive|define
name|RT2661_DISABLE_RX
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_CRC_ERROR
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_PHY_ERROR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_CTL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_NOT_TO_ME
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_TODS
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_VER_ERROR
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_MULTICAST
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_BROADCAST
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2661_DROP_ACKCTS
value|(1<< 25)
end_define

begin_comment
comment|/* possible flags for register TXRX_CSR4 */
end_comment

begin_define
define|#
directive|define
name|RT2661_SHORT_PREAMBLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2661_MRR_ENABLED
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RT2661_MRR_CCK_FALLBACK
value|(1<< 23)
end_define

begin_comment
comment|/* possible flags for register TXRX_CSR9 */
end_comment

begin_define
define|#
directive|define
name|RT2661_TSF_TICKING
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2661_TSF_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 17)
end_define

begin_comment
comment|/* TBTT stands for Target Beacon Transmission Time */
end_comment

begin_define
define|#
directive|define
name|RT2661_ENABLE_TBTT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2661_GENERATE_BEACON
value|(1<< 20)
end_define

begin_comment
comment|/* possible flags for register PHY_CSR0 */
end_comment

begin_define
define|#
directive|define
name|RT2661_PA_PE_2GHZ
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2661_PA_PE_5GHZ
value|(1<< 17)
end_define

begin_comment
comment|/* possible flags for register PHY_CSR3 */
end_comment

begin_define
define|#
directive|define
name|RT2661_BBP_READ
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2661_BBP_BUSY
value|(1<< 16)
end_define

begin_comment
comment|/* possible flags for register PHY_CSR4 */
end_comment

begin_define
define|#
directive|define
name|RT2661_RF_21BIT
value|(21<< 24)
end_define

begin_define
define|#
directive|define
name|RT2661_RF_BUSY
value|(1U<< 31)
end_define

begin_comment
comment|/* possible values for register STA_CSR4 */
end_comment

begin_define
define|#
directive|define
name|RT2661_TX_STAT_VALID
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2661_TX_RESULT
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 1)& 0x7)
end_define

begin_define
define|#
directive|define
name|RT2661_TX_RETRYCNT
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|RT2661_TX_QID
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 8)& 0xf)
end_define

begin_define
define|#
directive|define
name|RT2661_TX_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|RT2661_TX_RETRY_FAIL
value|6
end_define

begin_comment
comment|/* possible flags for register TX_CNTL_CSR */
end_comment

begin_define
define|#
directive|define
name|RT2661_KICK_MGT
value|(1<< 4)
end_define

begin_comment
comment|/* possible flags for register INT_SOURCE_CSR */
end_comment

begin_define
define|#
directive|define
name|RT2661_TX_DONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2661_RX_DONE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2661_TX0_DMA_DONE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2661_TX1_DMA_DONE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RT2661_TX2_DMA_DONE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RT2661_TX3_DMA_DONE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2661_MGT_DONE
value|(1<< 20)
end_define

begin_comment
comment|/* possible flags for register E2PROM_CSR */
end_comment

begin_define
define|#
directive|define
name|RT2661_C
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2661_S
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2661_D
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2661_Q
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RT2661_93C46
value|(1<< 5)
end_define

begin_comment
comment|/* Tx descriptor */
end_comment

begin_struct
struct|struct
name|rt2661_tx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2661_TX_BUSY
value|(1<< 0)
define|#
directive|define
name|RT2661_TX_VALID
value|(1<< 1)
define|#
directive|define
name|RT2661_TX_MORE_FRAG
value|(1<< 2)
define|#
directive|define
name|RT2661_TX_NEED_ACK
value|(1<< 3)
define|#
directive|define
name|RT2661_TX_TIMESTAMP
value|(1<< 4)
define|#
directive|define
name|RT2661_TX_OFDM
value|(1<< 5)
define|#
directive|define
name|RT2661_TX_IFS
value|(1<< 6)
define|#
directive|define
name|RT2661_TX_LONG_RETRY
value|(1<< 7)
define|#
directive|define
name|RT2661_TX_BURST
value|(1<< 28)
name|uint16_t
name|wme
decl_stmt|;
define|#
directive|define
name|RT2661_QID
parameter_list|(
name|v
parameter_list|)
value|(v)
define|#
directive|define
name|RT2661_AIFSN
parameter_list|(
name|v
parameter_list|)
value|((v)<< 4)
define|#
directive|define
name|RT2661_LOGCWMIN
parameter_list|(
name|v
parameter_list|)
value|((v)<< 8)
define|#
directive|define
name|RT2661_LOGCWMAX
parameter_list|(
name|v
parameter_list|)
value|((v)<< 12)
name|uint16_t
name|xflags
decl_stmt|;
define|#
directive|define
name|RT2661_TX_HWSEQ
value|(1<< 12)
name|uint8_t
name|plcp_signal
decl_stmt|;
name|uint8_t
name|plcp_service
decl_stmt|;
define|#
directive|define
name|RT2661_PLCP_LENGEXT
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
define|#
directive|define
name|RT2661_QID_MGT
value|13
name|uint8_t
name|txpower
decl_stmt|;
define|#
directive|define
name|RT2661_DEFAULT_TXPOWER
value|0
name|uint8_t
name|reserved1
decl_stmt|;
name|uint32_t
name|addr
index|[
name|RT2661_MAX_SCATTER
index|]
decl_stmt|;
name|uint16_t
name|len
index|[
name|RT2661_MAX_SCATTER
index|]
decl_stmt|;
name|uint16_t
name|reserved2
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
name|rt2661_rx_desc
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2661_RX_BUSY
value|(1<< 0)
define|#
directive|define
name|RT2661_RX_DROP
value|(1<< 1)
define|#
directive|define
name|RT2661_RX_CRC_ERROR
value|(1<< 6)
define|#
directive|define
name|RT2661_RX_OFDM
value|(1<< 7)
define|#
directive|define
name|RT2661_RX_PHY_ERROR
value|(1<< 8)
define|#
directive|define
name|RT2661_RX_CIPHER_MASK
value|0x00000600
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
decl_stmt|;
name|uint32_t
name|physaddr
decl_stmt|;
name|uint32_t
name|reserved3
index|[
literal|10
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

begin_comment
comment|/* dual-band RF */
end_comment

begin_define
define|#
directive|define
name|RT2661_RF_5225
value|1
end_define

begin_define
define|#
directive|define
name|RT2661_RF_5325
value|2
end_define

begin_comment
comment|/* single-band RF */
end_comment

begin_define
define|#
directive|define
name|RT2661_RF_2527
value|3
end_define

begin_define
define|#
directive|define
name|RT2661_RF_2529
value|4
end_define

begin_define
define|#
directive|define
name|RT2661_RX_DESC_BACK
value|4
end_define

begin_define
define|#
directive|define
name|RT2661_SMART_MODE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2661_BBPR94_DEFAULT
value|6
end_define

begin_define
define|#
directive|define
name|RT2661_SHIFT_D
value|3
end_define

begin_define
define|#
directive|define
name|RT2661_SHIFT_Q
value|4
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_MAC01
value|0x02
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_MAC23
value|0x03
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_MAC45
value|0x04
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_ANTENNA
value|0x10
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_CONFIG2
value|0x11
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_BBP_BASE
value|0x13
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_TXPOWER
value|0x23
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_FREQ_OFFSET
value|0x2f
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_RSSI_2GHZ_OFFSET
value|0x4d
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_RSSI_5GHZ_OFFSET
value|0x4e
end_define

begin_define
define|#
directive|define
name|RT2661_EEPROM_DELAY
value|1
end_define

begin_comment
comment|/* minimum hold time (microsecond) */
end_comment

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
name|RAL_READ_REGION_4
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
value|bus_space_read_region_4((sc)->sc_st, (sc)->sc_sh, (offset),	\ 	    (datap), (count))
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

begin_define
define|#
directive|define
name|RAL_WRITE_REGION_1
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
value|bus_space_write_region_1((sc)->sc_st, (sc)->sc_sh, (offset),	\ 	    (datap), (count))
end_define

begin_comment
comment|/*  * EEPROM access macro  */
end_comment

begin_define
define|#
directive|define
name|RT2661_EEPROM_CTL
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	RAL_WRITE((sc), RT2661_E2PROM_CSR, (val));			\ 	DELAY(RT2661_EEPROM_DELAY);					\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_comment
comment|/*  * Default values for MAC registers; values taken from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2661_DEF_MAC
define|\
value|{ RT2661_TXRX_CSR0,        0x0000b032 },	\ 	{ RT2661_TXRX_CSR1,        0x9eb39eb3 },	\ 	{ RT2661_TXRX_CSR2,        0x8a8b8c8d },	\ 	{ RT2661_TXRX_CSR3,        0x00858687 },	\ 	{ RT2661_TXRX_CSR7,        0x2e31353b },	\ 	{ RT2661_TXRX_CSR8,        0x2a2a2a2c },	\ 	{ RT2661_TXRX_CSR15,       0x0000000f },	\ 	{ RT2661_MAC_CSR6,         0x00000fff },	\ 	{ RT2661_MAC_CSR8,         0x016c030a },	\ 	{ RT2661_MAC_CSR10,        0x00000718 },	\ 	{ RT2661_MAC_CSR12,        0x00000004 },	\ 	{ RT2661_MAC_CSR13,        0x0000e000 },	\ 	{ RT2661_SEC_CSR0,         0x00000000 },	\ 	{ RT2661_SEC_CSR1,         0x00000000 },	\ 	{ RT2661_SEC_CSR5,         0x00000000 },	\ 	{ RT2661_PHY_CSR1,         0x000023b0 },	\ 	{ RT2661_PHY_CSR5,         0x060a100c },	\ 	{ RT2661_PHY_CSR6,         0x00080606 },	\ 	{ RT2661_PHY_CSR7,         0x00000a08 },	\ 	{ RT2661_PCI_CFG_CSR,      0x3cca4808 },	\ 	{ RT2661_AIFSN_CSR,        0x00002273 },	\ 	{ RT2661_CWMIN_CSR,        0x00002344 },	\ 	{ RT2661_CWMAX_CSR,        0x000034aa },	\ 	{ RT2661_TEST_MODE_CSR,    0x00000200 },	\ 	{ RT2661_M2H_CMD_DONE_CSR, 0xffffffff }
end_define

begin_comment
comment|/*  * Default values for BBP registers; values taken from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2661_DEF_BBP
define|\
value|{   3, 0x00 },	\ 	{  15, 0x30 },	\ 	{  17, 0x20 },	\ 	{  21, 0xc8 },	\ 	{  22, 0x38 },	\ 	{  23, 0x06 },	\ 	{  24, 0xfe },	\ 	{  25, 0x0a },	\ 	{  26, 0x0d },	\ 	{  34, 0x12 },	\ 	{  37, 0x07 },	\ 	{  39, 0xf8 },	\ 	{  41, 0x60 },	\ 	{  53, 0x10 },	\ 	{  54, 0x18 },	\ 	{  60, 0x10 },	\ 	{  61, 0x04 },	\ 	{  62, 0x04 },	\ 	{  75, 0xfe },	\ 	{  86, 0xfe },	\ 	{  88, 0xfe },	\ 	{  90, 0x0f },	\ 	{  99, 0x00 },	\ 	{ 102, 0x16 },	\ 	{ 107, 0x04 }
end_define

begin_comment
comment|/*  * Default settings for RF registers; values taken from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2661_RF5225_1
define|\
value|{   1, 0x00b33, 0x011e1, 0x1a014, 0x30282 },	\ 	{   2, 0x00b33, 0x011e1, 0x1a014, 0x30287 },	\ 	{   3, 0x00b33, 0x011e2, 0x1a014, 0x30282 },	\ 	{   4, 0x00b33, 0x011e2, 0x1a014, 0x30287 },	\ 	{   5, 0x00b33, 0x011e3, 0x1a014, 0x30282 },	\ 	{   6, 0x00b33, 0x011e3, 0x1a014, 0x30287 },	\ 	{   7, 0x00b33, 0x011e4, 0x1a014, 0x30282 },	\ 	{   8, 0x00b33, 0x011e4, 0x1a014, 0x30287 },	\ 	{   9, 0x00b33, 0x011e5, 0x1a014, 0x30282 },	\ 	{  10, 0x00b33, 0x011e5, 0x1a014, 0x30287 },	\ 	{  11, 0x00b33, 0x011e6, 0x1a014, 0x30282 },	\ 	{  12, 0x00b33, 0x011e6, 0x1a014, 0x30287 },	\ 	{  13, 0x00b33, 0x011e7, 0x1a014, 0x30282 },	\ 	{  14, 0x00b33, 0x011e8, 0x1a014, 0x30284 },	\ 							\ 	{  36, 0x00b33, 0x01266, 0x26014, 0x30288 },	\ 	{  40, 0x00b33, 0x01268, 0x26014, 0x30280 },	\ 	{  44, 0x00b33, 0x01269, 0x26014, 0x30282 },	\ 	{  48, 0x00b33, 0x0126a, 0x26014, 0x30284 },	\ 	{  52, 0x00b33, 0x0126b, 0x26014, 0x30286 },	\ 	{  56, 0x00b33, 0x0126c, 0x26014, 0x30288 },	\ 	{  60, 0x00b33, 0x0126e, 0x26014, 0x30280 },	\ 	{  64, 0x00b33, 0x0126f, 0x26014, 0x30282 },	\ 							\ 	{ 100, 0x00b33, 0x0128a, 0x2e014, 0x30280 },	\ 	{ 104, 0x00b33, 0x0128b, 0x2e014, 0x30282 },	\ 	{ 108, 0x00b33, 0x0128c, 0x2e014, 0x30284 },	\ 	{ 112, 0x00b33, 0x0128d, 0x2e014, 0x30286 },	\ 	{ 116, 0x00b33, 0x0128e, 0x2e014, 0x30288 },	\ 	{ 120, 0x00b33, 0x012a0, 0x2e014, 0x30280 },	\ 	{ 124, 0x00b33, 0x012a1, 0x2e014, 0x30282 },	\ 	{ 128, 0x00b33, 0x012a2, 0x2e014, 0x30284 },	\ 	{ 132, 0x00b33, 0x012a3, 0x2e014, 0x30286 },	\ 	{ 136, 0x00b33, 0x012a4, 0x2e014, 0x30288 },	\ 	{ 140, 0x00b33, 0x012a6, 0x2e014, 0x30280 },	\ 							\ 	{ 149, 0x00b33, 0x012a8, 0x2e014, 0x30287 },	\ 	{ 153, 0x00b33, 0x012a9, 0x2e014, 0x30289 },	\ 	{ 157, 0x00b33, 0x012ab, 0x2e014, 0x30281 },	\ 	{ 161, 0x00b33, 0x012ac, 0x2e014, 0x30283 },	\ 	{ 165, 0x00b33, 0x012ad, 0x2e014, 0x30285 }
end_define

begin_define
define|#
directive|define
name|RT2661_RF5225_2
define|\
value|{   1, 0x00b33, 0x011e1, 0x1a014, 0x30282 },	\ 	{   2, 0x00b33, 0x011e1, 0x1a014, 0x30287 },	\ 	{   3, 0x00b33, 0x011e2, 0x1a014, 0x30282 },	\ 	{   4, 0x00b33, 0x011e2, 0x1a014, 0x30287 },	\ 	{   5, 0x00b33, 0x011e3, 0x1a014, 0x30282 },	\ 	{   6, 0x00b33, 0x011e3, 0x1a014, 0x30287 },	\ 	{   7, 0x00b33, 0x011e4, 0x1a014, 0x30282 },	\ 	{   8, 0x00b33, 0x011e4, 0x1a014, 0x30287 },	\ 	{   9, 0x00b33, 0x011e5, 0x1a014, 0x30282 },	\ 	{  10, 0x00b33, 0x011e5, 0x1a014, 0x30287 },	\ 	{  11, 0x00b33, 0x011e6, 0x1a014, 0x30282 },	\ 	{  12, 0x00b33, 0x011e6, 0x1a014, 0x30287 },	\ 	{  13, 0x00b33, 0x011e7, 0x1a014, 0x30282 },	\ 	{  14, 0x00b33, 0x011e8, 0x1a014, 0x30284 },	\ 							\ 	{  36, 0x00b35, 0x11206, 0x26014, 0x30280 },	\ 	{  40, 0x00b34, 0x111a0, 0x26014, 0x30280 },	\ 	{  44, 0x00b34, 0x111a1, 0x26014, 0x30286 },	\ 	{  48, 0x00b34, 0x111a3, 0x26014, 0x30282 },	\ 	{  52, 0x00b34, 0x111a4, 0x26014, 0x30288 },	\ 	{  56, 0x00b34, 0x111a6, 0x26014, 0x30284 },	\ 	{  60, 0x00b34, 0x111a8, 0x26014, 0x30280 },	\ 	{  64, 0x00b34, 0x111a9, 0x26014, 0x30286 },	\ 							\ 	{ 100, 0x00b35, 0x11226, 0x2e014, 0x30280 },	\ 	{ 104, 0x00b35, 0x11228, 0x2e014, 0x30280 },	\ 	{ 108, 0x00b35, 0x1122a, 0x2e014, 0x30280 },	\ 	{ 112, 0x00b35, 0x1122c, 0x2e014, 0x30280 },	\ 	{ 116, 0x00b35, 0x1122e, 0x2e014, 0x30280 },	\ 	{ 120, 0x00b34, 0x111c0, 0x2e014, 0x30280 },	\ 	{ 124, 0x00b34, 0x111c1, 0x2e014, 0x30286 },	\ 	{ 128, 0x00b34, 0x111c3, 0x2e014, 0x30282 },	\ 	{ 132, 0x00b34, 0x111c4, 0x2e014, 0x30288 },	\ 	{ 136, 0x00b34, 0x111c6, 0x2e014, 0x30284 },	\ 	{ 140, 0x00b34, 0x111c8, 0x2e014, 0x30280 },	\ 							\ 	{ 149, 0x00b34, 0x111cb, 0x2e014, 0x30286 },	\ 	{ 153, 0x00b34, 0x111cd, 0x2e014, 0x30282 },	\ 	{ 157, 0x00b35, 0x11242, 0x2e014, 0x30285 },	\ 	{ 161, 0x00b35, 0x11244, 0x2e014, 0x30285 },	\ 	{ 165, 0x00b35, 0x11246, 0x2e014, 0x30285 }
end_define

end_unit

