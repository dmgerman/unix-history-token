begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: rt2860reg.h,v 1.19 2009/05/18 19:25:07 damien Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007  *	Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_RUNREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_RUNREG_H_
end_define

begin_define
define|#
directive|define
name|RT2860_CONFIG_NO
value|1
end_define

begin_define
define|#
directive|define
name|RT2860_IFACE_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|RT3070_OPT_14
value|0x0114
end_define

begin_comment
comment|/* SCH/DMA registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_INT_STATUS
value|0x0200
end_define

begin_define
define|#
directive|define
name|RT2860_INT_MASK
value|0x0204
end_define

begin_define
define|#
directive|define
name|RT2860_WPDMA_GLO_CFG
value|0x0208
end_define

begin_define
define|#
directive|define
name|RT2860_WPDMA_RST_IDX
value|0x020c
end_define

begin_define
define|#
directive|define
name|RT2860_DELAY_INT_CFG
value|0x0210
end_define

begin_define
define|#
directive|define
name|RT2860_WMM_AIFSN_CFG
value|0x0214
end_define

begin_define
define|#
directive|define
name|RT2860_WMM_CWMIN_CFG
value|0x0218
end_define

begin_define
define|#
directive|define
name|RT2860_WMM_CWMAX_CFG
value|0x021c
end_define

begin_define
define|#
directive|define
name|RT2860_WMM_TXOP0_CFG
value|0x0220
end_define

begin_define
define|#
directive|define
name|RT2860_WMM_TXOP1_CFG
value|0x0224
end_define

begin_define
define|#
directive|define
name|RT2860_GPIO_CTRL
value|0x0228
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_REG
value|0x022c
end_define

begin_define
define|#
directive|define
name|RT2860_TX_BASE_PTR
parameter_list|(
name|qid
parameter_list|)
value|(0x0230 + (qid) * 16)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_MAX_CNT
parameter_list|(
name|qid
parameter_list|)
value|(0x0234 + (qid) * 16)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_CTX_IDX
parameter_list|(
name|qid
parameter_list|)
value|(0x0238 + (qid) * 16)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DTX_IDX
parameter_list|(
name|qid
parameter_list|)
value|(0x023c + (qid) * 16)
end_define

begin_define
define|#
directive|define
name|RT2860_RX_BASE_PTR
value|0x0290
end_define

begin_define
define|#
directive|define
name|RT2860_RX_MAX_CNT
value|0x0294
end_define

begin_define
define|#
directive|define
name|RT2860_RX_CALC_IDX
value|0x0298
end_define

begin_define
define|#
directive|define
name|RT2860_FS_DRX_IDX
value|0x029c
end_define

begin_define
define|#
directive|define
name|RT2860_USB_DMA_CFG
value|0x02a0
end_define

begin_comment
comment|/* RT2870 only */
end_comment

begin_define
define|#
directive|define
name|RT2860_US_CYC_CNT
value|0x02a4
end_define

begin_comment
comment|/* PBF registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_SYS_CTRL
value|0x0400
end_define

begin_define
define|#
directive|define
name|RT2860_HOST_CMD
value|0x0404
end_define

begin_define
define|#
directive|define
name|RT2860_PBF_CFG
value|0x0408
end_define

begin_define
define|#
directive|define
name|RT2860_MAX_PCNT
value|0x040c
end_define

begin_define
define|#
directive|define
name|RT2860_BUF_CTRL
value|0x0410
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_INT_STA
value|0x0414
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_INT_ENA
value|0x0418
end_define

begin_define
define|#
directive|define
name|RT2860_TXQ_IO
parameter_list|(
name|qid
parameter_list|)
value|(0x041c + (qid) * 4)
end_define

begin_define
define|#
directive|define
name|RT2860_RX0Q_IO
value|0x0424
end_define

begin_define
define|#
directive|define
name|RT2860_BCN_OFFSET0
value|0x042c
end_define

begin_define
define|#
directive|define
name|RT2860_BCN_OFFSET1
value|0x0430
end_define

begin_define
define|#
directive|define
name|RT2860_TXRXQ_STA
value|0x0434
end_define

begin_define
define|#
directive|define
name|RT2860_TXRXQ_PCNT
value|0x0438
end_define

begin_define
define|#
directive|define
name|RT2860_PBF_DBG
value|0x043c
end_define

begin_define
define|#
directive|define
name|RT2860_CAP_CTRL
value|0x0440
end_define

begin_comment
comment|/* RT3070 registers */
end_comment

begin_define
define|#
directive|define
name|RT3070_RF_CSR_CFG
value|0x0500
end_define

begin_define
define|#
directive|define
name|RT3070_EFUSE_CTRL
value|0x0580
end_define

begin_define
define|#
directive|define
name|RT3070_EFUSE_DATA0
value|0x0590
end_define

begin_define
define|#
directive|define
name|RT3070_EFUSE_DATA1
value|0x0594
end_define

begin_define
define|#
directive|define
name|RT3070_EFUSE_DATA2
value|0x0598
end_define

begin_define
define|#
directive|define
name|RT3070_EFUSE_DATA3
value|0x059c
end_define

begin_define
define|#
directive|define
name|RT3070_LDO_CFG0
value|0x05d4
end_define

begin_define
define|#
directive|define
name|RT3070_GPIO_SWITCH
value|0x05dc
end_define

begin_comment
comment|/* RT5592 registers */
end_comment

begin_define
define|#
directive|define
name|RT5592_DEBUG_INDEX
value|0x05e8
end_define

begin_comment
comment|/* MAC registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_ASIC_VER_ID
value|0x1000
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_SYS_CTRL
value|0x1004
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_ADDR_DW0
value|0x1008
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_ADDR_DW1
value|0x100c
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_BSSID_DW0
value|0x1010
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_BSSID_DW1
value|0x1014
end_define

begin_define
define|#
directive|define
name|RT2860_MAX_LEN_CFG
value|0x1018
end_define

begin_define
define|#
directive|define
name|RT2860_BBP_CSR_CFG
value|0x101c
end_define

begin_define
define|#
directive|define
name|RT2860_RF_CSR_CFG0
value|0x1020
end_define

begin_define
define|#
directive|define
name|RT2860_RF_CSR_CFG1
value|0x1024
end_define

begin_define
define|#
directive|define
name|RT2860_RF_CSR_CFG2
value|0x1028
end_define

begin_define
define|#
directive|define
name|RT2860_LED_CFG
value|0x102c
end_define

begin_comment
comment|/* undocumented registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_DEBUG
value|0x10f4
end_define

begin_comment
comment|/* MAC Timing control registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_XIFS_TIME_CFG
value|0x1100
end_define

begin_define
define|#
directive|define
name|RT2860_BKOFF_SLOT_CFG
value|0x1104
end_define

begin_define
define|#
directive|define
name|RT2860_NAV_TIME_CFG
value|0x1108
end_define

begin_define
define|#
directive|define
name|RT2860_CH_TIME_CFG
value|0x110c
end_define

begin_define
define|#
directive|define
name|RT2860_PBF_LIFE_TIMER
value|0x1110
end_define

begin_define
define|#
directive|define
name|RT2860_BCN_TIME_CFG
value|0x1114
end_define

begin_define
define|#
directive|define
name|RT2860_TBTT_SYNC_CFG
value|0x1118
end_define

begin_define
define|#
directive|define
name|RT2860_TSF_TIMER_DW0
value|0x111c
end_define

begin_define
define|#
directive|define
name|RT2860_TSF_TIMER_DW1
value|0x1120
end_define

begin_define
define|#
directive|define
name|RT2860_TBTT_TIMER
value|0x1124
end_define

begin_define
define|#
directive|define
name|RT2860_INT_TIMER_CFG
value|0x1128
end_define

begin_define
define|#
directive|define
name|RT2860_INT_TIMER_EN
value|0x112c
end_define

begin_define
define|#
directive|define
name|RT2860_CH_IDLE_TIME
value|0x1130
end_define

begin_comment
comment|/* MAC Power Save configuration registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_MAC_STATUS_REG
value|0x1200
end_define

begin_define
define|#
directive|define
name|RT2860_PWR_PIN_CFG
value|0x1204
end_define

begin_define
define|#
directive|define
name|RT2860_AUTO_WAKEUP_CFG
value|0x1208
end_define

begin_comment
comment|/* MAC TX configuration registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_EDCA_AC_CFG
parameter_list|(
name|aci
parameter_list|)
value|(0x1300 + (aci) * 4)
end_define

begin_define
define|#
directive|define
name|RT2860_EDCA_TID_AC_MAP
value|0x1310
end_define

begin_define
define|#
directive|define
name|RT2860_TX_PWR_CFG
parameter_list|(
name|ridx
parameter_list|)
value|(0x1314 + (ridx) * 4)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_PIN_CFG
value|0x1328
end_define

begin_define
define|#
directive|define
name|RT2860_TX_BAND_CFG
value|0x132c
end_define

begin_define
define|#
directive|define
name|RT2860_TX_SW_CFG0
value|0x1330
end_define

begin_define
define|#
directive|define
name|RT2860_TX_SW_CFG1
value|0x1334
end_define

begin_define
define|#
directive|define
name|RT2860_TX_SW_CFG2
value|0x1338
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_THRES_CFG
value|0x133c
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_CTRL_CFG
value|0x1340
end_define

begin_define
define|#
directive|define
name|RT2860_TX_RTS_CFG
value|0x1344
end_define

begin_define
define|#
directive|define
name|RT2860_TX_TIMEOUT_CFG
value|0x1348
end_define

begin_define
define|#
directive|define
name|RT2860_TX_RTY_CFG
value|0x134c
end_define

begin_define
define|#
directive|define
name|RT2860_TX_LINK_CFG
value|0x1350
end_define

begin_define
define|#
directive|define
name|RT2860_HT_FBK_CFG0
value|0x1354
end_define

begin_define
define|#
directive|define
name|RT2860_HT_FBK_CFG1
value|0x1358
end_define

begin_define
define|#
directive|define
name|RT2860_LG_FBK_CFG0
value|0x135c
end_define

begin_define
define|#
directive|define
name|RT2860_LG_FBK_CFG1
value|0x1360
end_define

begin_define
define|#
directive|define
name|RT2860_CCK_PROT_CFG
value|0x1364
end_define

begin_define
define|#
directive|define
name|RT2860_OFDM_PROT_CFG
value|0x1368
end_define

begin_define
define|#
directive|define
name|RT2860_MM20_PROT_CFG
value|0x136c
end_define

begin_define
define|#
directive|define
name|RT2860_MM40_PROT_CFG
value|0x1370
end_define

begin_define
define|#
directive|define
name|RT2860_GF20_PROT_CFG
value|0x1374
end_define

begin_define
define|#
directive|define
name|RT2860_GF40_PROT_CFG
value|0x1378
end_define

begin_define
define|#
directive|define
name|RT2860_EXP_CTS_TIME
value|0x137c
end_define

begin_define
define|#
directive|define
name|RT2860_EXP_ACK_TIME
value|0x1380
end_define

begin_comment
comment|/* MAC RX configuration registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_RX_FILTR_CFG
value|0x1400
end_define

begin_define
define|#
directive|define
name|RT2860_AUTO_RSP_CFG
value|0x1404
end_define

begin_define
define|#
directive|define
name|RT2860_LEGACY_BASIC_RATE
value|0x1408
end_define

begin_define
define|#
directive|define
name|RT2860_HT_BASIC_RATE
value|0x140c
end_define

begin_define
define|#
directive|define
name|RT2860_HT_CTRL_CFG
value|0x1410
end_define

begin_define
define|#
directive|define
name|RT2860_SIFS_COST_CFG
value|0x1414
end_define

begin_define
define|#
directive|define
name|RT2860_RX_PARSER_CFG
value|0x1418
end_define

begin_comment
comment|/* MAC Security configuration registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_TX_SEC_CNT0
value|0x1500
end_define

begin_define
define|#
directive|define
name|RT2860_RX_SEC_CNT0
value|0x1504
end_define

begin_define
define|#
directive|define
name|RT2860_CCMP_FC_MUTE
value|0x1508
end_define

begin_comment
comment|/* MAC HCCA/PSMP configuration registers */
end_comment

begin_define
define|#
directive|define
name|RT2860_TXOP_HLDR_ADDR0
value|0x1600
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_HLDR_ADDR1
value|0x1604
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_HLDR_ET
value|0x1608
end_define

begin_define
define|#
directive|define
name|RT2860_QOS_CFPOLL_RA_DW0
value|0x160c
end_define

begin_define
define|#
directive|define
name|RT2860_QOS_CFPOLL_A1_DW1
value|0x1610
end_define

begin_define
define|#
directive|define
name|RT2860_QOS_CFPOLL_QC
value|0x1614
end_define

begin_comment
comment|/* MAC Statistics Counters */
end_comment

begin_define
define|#
directive|define
name|RT2860_RX_STA_CNT0
value|0x1700
end_define

begin_define
define|#
directive|define
name|RT2860_RX_STA_CNT1
value|0x1704
end_define

begin_define
define|#
directive|define
name|RT2860_RX_STA_CNT2
value|0x1708
end_define

begin_define
define|#
directive|define
name|RT2860_TX_STA_CNT0
value|0x170c
end_define

begin_define
define|#
directive|define
name|RT2860_TX_STA_CNT1
value|0x1710
end_define

begin_define
define|#
directive|define
name|RT2860_TX_STA_CNT2
value|0x1714
end_define

begin_define
define|#
directive|define
name|RT2860_TX_STAT_FIFO
value|0x1718
end_define

begin_comment
comment|/* RX WCID search table */
end_comment

begin_define
define|#
directive|define
name|RT2860_WCID_ENTRY
parameter_list|(
name|wcid
parameter_list|)
value|(0x1800 + (wcid) * 8)
end_define

begin_define
define|#
directive|define
name|RT2860_FW_BASE
value|0x2000
end_define

begin_define
define|#
directive|define
name|RT2870_FW_BASE
value|0x3000
end_define

begin_comment
comment|/* Pair-wise key table */
end_comment

begin_define
define|#
directive|define
name|RT2860_PKEY
parameter_list|(
name|wcid
parameter_list|)
value|(0x4000 + (wcid) * 32)
end_define

begin_comment
comment|/* IV/EIV table */
end_comment

begin_define
define|#
directive|define
name|RT2860_IVEIV
parameter_list|(
name|wcid
parameter_list|)
value|(0x6000 + (wcid) * 8)
end_define

begin_comment
comment|/* WCID attribute table */
end_comment

begin_define
define|#
directive|define
name|RT2860_WCID_ATTR
parameter_list|(
name|wcid
parameter_list|)
value|(0x6800 + (wcid) * 4)
end_define

begin_comment
comment|/* Shared Key Table */
end_comment

begin_define
define|#
directive|define
name|RT2860_SKEY
parameter_list|(
name|vap
parameter_list|,
name|kidx
parameter_list|)
value|(0x6c00 + (vap) * 128 + (kidx) * 32)
end_define

begin_comment
comment|/* Shared Key Mode */
end_comment

begin_define
define|#
directive|define
name|RT2860_SKEY_MODE_0_7
value|0x7000
end_define

begin_define
define|#
directive|define
name|RT2860_SKEY_MODE_8_15
value|0x7004
end_define

begin_define
define|#
directive|define
name|RT2860_SKEY_MODE_16_23
value|0x7008
end_define

begin_define
define|#
directive|define
name|RT2860_SKEY_MODE_24_31
value|0x700c
end_define

begin_comment
comment|/* Shared Memory between MCU and host */
end_comment

begin_define
define|#
directive|define
name|RT2860_H2M_MAILBOX
value|0x7010
end_define

begin_define
define|#
directive|define
name|RT2860_H2M_MAILBOX_CID
value|0x7014
end_define

begin_define
define|#
directive|define
name|RT2860_H2M_MAILBOX_STATUS
value|0x701c
end_define

begin_define
define|#
directive|define
name|RT2860_H2M_INTSRC
value|0x7024
end_define

begin_define
define|#
directive|define
name|RT2860_H2M_BBPAGENT
value|0x7028
end_define

begin_define
define|#
directive|define
name|RT2860_BCN_BASE
parameter_list|(
name|vap
parameter_list|)
value|(0x7800 + (vap) * 512)
end_define

begin_comment
comment|/* possible flags for register RT2860_PCI_EECTRL */
end_comment

begin_define
define|#
directive|define
name|RT2860_C
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT2860_S
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_D
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2860_SHIFT_D
value|2
end_define

begin_define
define|#
directive|define
name|RT2860_Q
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2860_SHIFT_Q
value|3
end_define

begin_comment
comment|/* possible flags for registers INT_STATUS/INT_MASK */
end_comment

begin_define
define|#
directive|define
name|RT2860_TX_COHERENT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RT2860_RX_COHERENT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_INT_4
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_INT_3
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_INT_2
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_INT_1
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_INT_0
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_RX_COHERENT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_INT
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DONE_INT5
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DONE_INT4
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DONE_INT3
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DONE_INT2
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DONE_INT1
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DONE_INT0
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RT2860_RX_DONE_INT
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DLY_INT
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RT2860_RX_DLY_INT
value|(1<<  0)
end_define

begin_comment
comment|/* possible flags for register WPDMA_GLO_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_HDR_SEG_LEN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_BIG_ENDIAN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_WB_DDONE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RT2860_WPDMA_BT_SIZE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RT2860_WPDMA_BT_SIZE16
value|0
end_define

begin_define
define|#
directive|define
name|RT2860_WPDMA_BT_SIZE32
value|1
end_define

begin_define
define|#
directive|define
name|RT2860_WPDMA_BT_SIZE64
value|2
end_define

begin_define
define|#
directive|define
name|RT2860_WPDMA_BT_SIZE128
value|3
end_define

begin_define
define|#
directive|define
name|RT2860_RX_DMA_BUSY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2860_RX_DMA_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DMA_BUSY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_DMA_EN
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register DELAY_INT_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_TXDLY_INT_EN
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|RT2860_TXMAX_PINT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_TXMAX_PTIME_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_RXDLY_INT_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2860_RXMAX_PINT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_RXMAX_PTIME_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register GPIO_CTRL */
end_comment

begin_define
define|#
directive|define
name|RT2860_GPIO_D_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_GPIO_O_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register USB_DMA_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_USB_TX_BUSY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_RX_BUSY
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_EPOUT_VLD_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_USB_TX_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_RX_EN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_RX_AGG_EN
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_TXOP_HALT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_TX_CLEAR
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_PHY_WD_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_PHY_MAN_RST
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2860_USB_RX_AGG_LMT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* in unit of 1KB */
end_comment

begin_define
define|#
directive|define
name|RT2860_USB_RX_AGG_TO
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_comment
comment|/* in unit of 33ns */
end_comment

begin_comment
comment|/* possible flags for register US_CYC_CNT */
end_comment

begin_define
define|#
directive|define
name|RT2860_TEST_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2860_TEST_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_BT_MODE_EN
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RT2860_US_CYC_CNT_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register SYS_CTRL */
end_comment

begin_define
define|#
directive|define
name|RT2860_HST_PM_SEL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_CAP_MODE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RT2860_PME_OEN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RT2860_CLKSELECT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RT2860_PBF_CLK_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_CLK_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RT2860_DMA_CLK_EN
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_READY
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RT2860_ASY_RESET
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RT2860_PBF_RESET
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_RESET
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RT2860_DMA_RESET
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_RESET
value|(1<<  0)
end_define

begin_comment
comment|/* possible values for register HOST_CMD */
end_comment

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_SLEEP
value|0x30
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_WAKEUP
value|0x31
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_LEDS
value|0x50
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_LED_RSSI
value|0x51
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_LED1
value|0x52
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_LED2
value|0x53
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_LED3
value|0x54
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_RFRESET
value|0x72
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_ANTSEL
value|0x73
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_BBP
value|0x80
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_CMD_PSLEVEL
value|0x83
end_define

begin_comment
comment|/* possible flags for register PBF_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_TX1Q_NUM_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|RT2860_TX2Q_NUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_NULL0_MODE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2860_NULL1_MODE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RT2860_RX_DROP_MODE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RT2860_TX0Q_MANUAL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RT2860_TX1Q_MANUAL
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RT2860_TX2Q_MANUAL
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RT2860_RX0Q_MANUAL
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RT2860_HCCA_EN
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RT2860_TX0Q_EN
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RT2860_TX1Q_EN
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RT2860_TX2Q_EN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RT2860_RX0Q_EN
value|(1<<  1)
end_define

begin_comment
comment|/* possible flags for register BUF_CTRL */
end_comment

begin_define
define|#
directive|define
name|RT2860_WRITE_TXQ
parameter_list|(
name|qid
parameter_list|)
value|(1<< (11 - (qid)))
end_define

begin_define
define|#
directive|define
name|RT2860_NULL0_KICK
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RT2860_NULL1_KICK
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RT2860_BUF_RESET
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RT2860_READ_TXQ
parameter_list|(
name|qid
parameter_list|)
value|(1<< (3 - (qid))
end_define

begin_define
define|#
directive|define
name|RT2860_READ_RX0Q
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for registers MCU_INT_STA/MCU_INT_ENA */
end_comment

begin_define
define|#
directive|define
name|RT2860_MCU_MAC_INT_8
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_MAC_INT_7
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_MAC_INT_6
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_MAC_INT_4
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_MAC_INT_3
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_MAC_INT_2
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_MAC_INT_1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RT2860_MCU_MAC_INT_0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_DTX0_INT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RT2860_DTX1_INT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RT2860_DTX2_INT
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RT2860_DRX0_INT
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RT2860_HCMD_INT
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RT2860_N0TX_INT
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RT2860_N1TX_INT
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RT2860_BCNTX_INT
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RT2860_MTX0_INT
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RT2860_MTX1_INT
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RT2860_MTX2_INT
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RT2860_MRX0_INT
value|(1<<  0)
end_define

begin_comment
comment|/* possible flags for register TXRXQ_PCNT */
end_comment

begin_define
define|#
directive|define
name|RT2860_RX0Q_PCNT_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|RT2860_TX2Q_PCNT_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|RT2860_TX1Q_PCNT_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|RT2860_TX0Q_PCNT_MASK
value|0x000000ff
end_define

begin_comment
comment|/* possible flags for register CAP_CTRL */
end_comment

begin_define
define|#
directive|define
name|RT2860_CAP_ADC_FEQ
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|RT2860_CAP_START
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RT2860_MAN_TRIG
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RT2860_TRIG_OFFSET_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_START_ADDR_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register RF_CSR_CFG */
end_comment

begin_define
define|#
directive|define
name|RT3070_RF_KICK
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RT3070_RF_WRITE
value|(1<< 16)
end_define

begin_comment
comment|/* possible flags for register EFUSE_CTRL */
end_comment

begin_define
define|#
directive|define
name|RT3070_SEL_EFUSE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|RT3070_EFSROM_KICK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RT3070_EFSROM_AIN_MASK
value|0x03ff0000
end_define

begin_define
define|#
directive|define
name|RT3070_EFSROM_AIN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT3070_EFSROM_MODE_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|RT3070_EFUSE_AOUT_MASK
value|0x0000003f
end_define

begin_comment
comment|/* possible flag for register DEBUG_INDEX */
end_comment

begin_define
define|#
directive|define
name|RT5592_SEL_XTAL
value|(1U<< 31)
end_define

begin_comment
comment|/* possible flags for register MAC_SYS_CTRL */
end_comment

begin_define
define|#
directive|define
name|RT2860_RX_TS_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RT2860_WLAN_HALT_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RT2860_PBF_LOOP_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RT2860_CONT_TX_TEST
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_RX_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_TX_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2860_BBP_HRST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_MAC_SRST
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register MAC_BSSID_DW1 */
end_comment

begin_define
define|#
directive|define
name|RT2860_MULTI_BCN_NUM_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|RT2860_MULTI_BSSID_MODE_SHIFT
value|16
end_define

begin_comment
comment|/* possible flags for register MAX_LEN_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_MIN_MPDU_LEN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_MAX_PSDU_LEN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RT2860_MAX_PSDU_LEN8K
value|0
end_define

begin_define
define|#
directive|define
name|RT2860_MAX_PSDU_LEN16K
value|1
end_define

begin_define
define|#
directive|define
name|RT2860_MAX_PSDU_LEN32K
value|2
end_define

begin_define
define|#
directive|define
name|RT2860_MAX_PSDU_LEN64K
value|3
end_define

begin_define
define|#
directive|define
name|RT2860_MAX_MPDU_LEN_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for registers BBP_CSR_CFG/H2M_BBPAGENT */
end_comment

begin_define
define|#
directive|define
name|RT2860_BBP_RW_PARALLEL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2860_BBP_PAR_DUR_112_5
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RT2860_BBP_CSR_KICK
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RT2860_BBP_CSR_READ
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_BBP_ADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_BBP_DATA_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register RF_CSR_CFG0 */
end_comment

begin_define
define|#
directive|define
name|RT2860_RF_REG_CTRL
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|RT2860_RF_LE_SEL1
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RT2860_RF_LE_STBY
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RT2860_RF_REG_WIDTH_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_RF_REG_0_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register RF_CSR_CFG1 */
end_comment

begin_define
define|#
directive|define
name|RT2860_RF_DUR_5
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2860_RF_REG_1_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register LED_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_LED_POL
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RT2860_Y_LED_MODE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RT2860_G_LED_MODE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|RT2860_R_LED_MODE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_LED_MODE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|RT2860_LED_MODE_BLINK_TX
value|1
end_define

begin_define
define|#
directive|define
name|RT2860_LED_MODE_SLOW_BLINK
value|2
end_define

begin_define
define|#
directive|define
name|RT2860_LED_MODE_ON
value|3
end_define

begin_define
define|#
directive|define
name|RT2860_SLOW_BLK_TIME_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_LED_OFF_TIME_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_LED_ON_TIME_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register XIFS_TIME_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_BB_RXEND_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RT2860_EIFS_TIME_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RT2860_OFDM_XIFS_TIME_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_OFDM_SIFS_TIME_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_CCK_SIFS_TIME_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register BKOFF_SLOT_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_CC_DELAY_TIME_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_SLOT_TIME
value|0
end_define

begin_comment
comment|/* possible flags for register NAV_TIME_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_NAV_UPD
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|RT2860_NAV_UPD_VAL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_NAV_CLR_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2860_NAV_TIMER_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register CH_TIME_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_EIFS_AS_CH_BUSY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RT2860_NAV_AS_CH_BUSY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2860_RX_AS_CH_BUSY
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_AS_CH_BUSY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_CH_STA_TIMER_EN
value|(1<< 0)
end_define

begin_comment
comment|/* possible values for register BCN_TIME_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_TSF_INS_COMP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_BCN_TX_EN
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RT2860_TBTT_TIMER_EN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2860_TSF_SYNC_MODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|RT2860_TSF_SYNC_MODE_DIS
value|0
end_define

begin_define
define|#
directive|define
name|RT2860_TSF_SYNC_MODE_STA
value|1
end_define

begin_define
define|#
directive|define
name|RT2860_TSF_SYNC_MODE_IBSS
value|2
end_define

begin_define
define|#
directive|define
name|RT2860_TSF_SYNC_MODE_HOSTAP
value|3
end_define

begin_define
define|#
directive|define
name|RT2860_TSF_TIMER_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_BCN_INTVAL_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register TBTT_SYNC_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_BCN_CWMIN_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RT2860_BCN_AIFSN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_BCN_EXP_WIN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_TBTT_ADJUST_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register INT_TIMER_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_GP_TIMER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_PRE_TBTT_TIMER_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register INT_TIMER_EN */
end_comment

begin_define
define|#
directive|define
name|RT2860_GP_TIMER_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_PRE_TBTT_INT_EN
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register MAC_STATUS_REG */
end_comment

begin_define
define|#
directive|define
name|RT2860_RX_STATUS_BUSY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_STATUS_BUSY
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register PWR_PIN_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_IO_ADDA_PD
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2860_IO_PLL_PD
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2860_IO_RA_PE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_IO_RF_PE
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register AUTO_WAKEUP_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_AUTO_WAKEUP_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2860_SLEEP_TBTT_NUM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_WAKEUP_LEAD_TIME_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register TX_PIN_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_TRSW_POL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RT2860_TRSW_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RT2860_RFTR_POL
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RT2860_RFTR_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE_G1_POL
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE_A1_POL
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE_G0_POL
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE_A0_POL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE_G1_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE_A1_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE1_EN
value|(RT2860_LNA_PE_A1_EN | RT2860_LNA_PE_G1_EN)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE_G0_EN
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE_A0_EN
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RT2860_LNA_PE0_EN
value|(RT2860_LNA_PE_A0_EN | RT2860_LNA_PE_G0_EN)
end_define

begin_define
define|#
directive|define
name|RT2860_PA_PE_G1_POL
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RT2860_PA_PE_A1_POL
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RT2860_PA_PE_G0_POL
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RT2860_PA_PE_A0_POL
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RT2860_PA_PE_G1_EN
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RT2860_PA_PE_A1_EN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RT2860_PA_PE_G0_EN
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RT2860_PA_PE_A0_EN
value|(1<<  0)
end_define

begin_comment
comment|/* possible flags for register TX_BAND_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_5G_BAND_SEL_N
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2860_5G_BAND_SEL_P
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_BAND_SEL
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register TX_SW_CFG0 */
end_comment

begin_define
define|#
directive|define
name|RT2860_DLY_RFTR_EN_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_DLY_TRSW_EN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_DLY_PAPE_EN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_DLY_TXPE_EN_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register TX_SW_CFG1 */
end_comment

begin_define
define|#
directive|define
name|RT2860_DLY_RFTR_DIS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_DLY_TRSW_DIS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_DLY_PAPE_DIS
value|SHIFT	0
end_define

begin_comment
comment|/* possible flags for register TX_SW_CFG2 */
end_comment

begin_define
define|#
directive|define
name|RT2860_DLY_LNA_EN_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_DLY_LNA_DIS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_DLY_DAC_EN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_DLY_DAC_DIS_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register TXOP_THRES_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_TXOP_REM_THRES_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_CF_END_THRES_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_RDG_IN_THRES
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_RDG_OUT_THRES
value|0
end_define

begin_comment
comment|/* possible flags for register TXOP_CTRL_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_EXT_CW_MIN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_EXT_CCA_DLY_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_EXT_CCA_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RT2860_LSIG_TXOP_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_TRUN_EN_MIMOPS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_TRUN_EN_TXOP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_TRUN_EN_RATE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_TRUN_EN_AC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_TRUN_EN_TIMEOUT
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register TX_RTS_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_RTS_FBK_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2860_RTS_THRES_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_RTS_RTY_LIMIT_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register TX_TIMEOUT_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_TXOP_TIMEOUT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_RX_ACK_TIMEOUT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_MPDU_LIFE_TIME_SHIFT
value|4
end_define

begin_comment
comment|/* possible flags for register TX_RTY_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_TX_AUTOFB_EN
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RT2860_AGG_RTY_MODE_TIMER
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RT2860_NAG_RTY_MODE_TIMER
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RT2860_LONG_RTY_THRES_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_LONG_RTY_LIMIT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_SHORT_RTY_LIMIT_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register TX_LINK_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_REMOTE_MFS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RT2860_REMOTE_MFB_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_TX_CFACK_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_RDG_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_MRQ_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RT2860_REMOTE_UMFS_EN
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RT2860_TX_MFB_EN
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RT2860_REMOTE_MFB_LT_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for registers *_PROT_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_RTSTH_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ALLOW_GF40
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ALLOW_GF20
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ALLOW_MM40
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ALLOW_MM20
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ALLOW_OFDM
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ALLOW_CCK
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ALLOW_ALL
value|(0x3f<< 20)
end_define

begin_define
define|#
directive|define
name|RT2860_PROT_NAV_SHORT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RT2860_PROT_NAV_LONG
value|(2<< 18)
end_define

begin_define
define|#
directive|define
name|RT2860_PROT_CTRL_RTS_CTS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_PROT_CTRL_CTS
value|(2<< 16)
end_define

begin_comment
comment|/* possible flags for registers EXP_{CTS,ACK}_TIME */
end_comment

begin_define
define|#
directive|define
name|RT2860_EXP_OFDM_TIME_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_EXP_CCK_TIME_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register RX_FILTR_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_DROP_CTRL_RSV
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_BAR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_BA
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_PSPOLL
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_RTS
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_CTS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_ACK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_CFEND
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_CFACK
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_DUPL
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_BC
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_MC
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_VER_ERR
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_NOT_MYBSS
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_UC_NOME
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_PHY_ERR
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RT2860_DROP_CRC_ERR
value|(1<<  0)
end_define

begin_comment
comment|/* possible flags for register AUTO_RSP_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_CTRL_PWR_BIT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RT2860_BAC_ACK_POLICY
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RT2860_CCK_SHORT_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RT2860_CTS_40M_REF_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT2860_CTS_40M_MODE_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT2860_BAC_ACKPOLICY_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT2860_AUTO_RSP_EN
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register SIFS_COST_CFG */
end_comment

begin_define
define|#
directive|define
name|RT2860_OFDM_SIFS_COST_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_CCK_SIFS_COST_SHIFT
value|0
end_define

begin_comment
comment|/* possible flags for register TXOP_HLDR_ET */
end_comment

begin_define
define|#
directive|define
name|RT2860_TXOP_ETM1_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ETM0_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ETM_THRES_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ETO_EN
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RT2860_TXOP_ETO_THRES_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|RT2860_PER_RX_RST_EN
value|(1<<  0)
end_define

begin_comment
comment|/* possible flags for register TX_STAT_FIFO */
end_comment

begin_define
define|#
directive|define
name|RT2860_TXQ_MCS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RT2860_TXQ_WCID_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RT2860_TXQ_ACKREQ
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RT2860_TXQ_AGG
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RT2860_TXQ_OK
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RT2860_TXQ_PID_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|RT2860_TXQ_VLD
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register WCID_ATTR */
end_comment

begin_define
define|#
directive|define
name|RT2860_MODE_NOSEC
value|0
end_define

begin_define
define|#
directive|define
name|RT2860_MODE_WEP40
value|1
end_define

begin_define
define|#
directive|define
name|RT2860_MODE_WEP104
value|2
end_define

begin_define
define|#
directive|define
name|RT2860_MODE_TKIP
value|3
end_define

begin_define
define|#
directive|define
name|RT2860_MODE_AES_CCMP
value|4
end_define

begin_define
define|#
directive|define
name|RT2860_MODE_CKIP40
value|5
end_define

begin_define
define|#
directive|define
name|RT2860_MODE_CKIP104
value|6
end_define

begin_define
define|#
directive|define
name|RT2860_MODE_CKIP128
value|7
end_define

begin_define
define|#
directive|define
name|RT2860_RX_PKEY_EN
value|(1<< 0)
end_define

begin_comment
comment|/* possible flags for register H2M_MAILBOX */
end_comment

begin_define
define|#
directive|define
name|RT2860_H2M_BUSY
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RT2860_TOKEN_NO_INTR
value|0xff
end_define

begin_comment
comment|/* possible flags for MCU command RT2860_MCU_CMD_LEDS */
end_comment

begin_define
define|#
directive|define
name|RT2860_LED_RADIO
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RT2860_LED_LINK_2GHZ
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RT2860_LED_LINK_5GHZ
value|(1<< 15)
end_define

begin_comment
comment|/* possible flags for RT3020 RF register 1 */
end_comment

begin_define
define|#
directive|define
name|RT3070_RF_BLOCK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RT3070_PLL_PD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RT3070_RX0_PD
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT3070_TX0_PD
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RT3070_RX1_PD
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RT3070_TX1_PD
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RT3070_RX2_PD
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RT3070_TX2_PD
value|(1<< 7)
end_define

begin_comment
comment|/* possible flags for RT3020 RF register 15 */
end_comment

begin_define
define|#
directive|define
name|RT3070_TX_LO2
value|(1<< 3)
end_define

begin_comment
comment|/* possible flags for RT3020 RF register 17 */
end_comment

begin_define
define|#
directive|define
name|RT3070_TX_LO1
value|(1<< 3)
end_define

begin_comment
comment|/* possible flags for RT3020 RF register 20 */
end_comment

begin_define
define|#
directive|define
name|RT3070_RX_LO1
value|(1<< 3)
end_define

begin_comment
comment|/* possible flags for RT3020 RF register 21 */
end_comment

begin_define
define|#
directive|define
name|RT3070_RX_LO2
value|(1<< 3)
end_define

begin_comment
comment|/* possible flags for RT3053 RF register 18 */
end_comment

begin_define
define|#
directive|define
name|RT3593_AUTOTUNE_BYPASS
value|(1<< 6)
end_define

begin_comment
comment|/* possible flags for RT3053 RF register 50 */
end_comment

begin_define
define|#
directive|define
name|RT3593_TX_LO2
value|(1<< 4)
end_define

begin_comment
comment|/* possible flags for RT3053 RF register 51 */
end_comment

begin_define
define|#
directive|define
name|RT3593_TX_LO1
value|(1<< 4)
end_define

begin_comment
comment|/* Possible flags for RT5390 RF register 2. */
end_comment

begin_define
define|#
directive|define
name|RT5390_RESCAL
value|(1<< 7)
end_define

begin_comment
comment|/* Possible flags for RT5390 RF register 3. */
end_comment

begin_define
define|#
directive|define
name|RT5390_VCOCAL
value|(1<< 7)
end_define

begin_comment
comment|/* Possible flags for RT5390 RF register 38. */
end_comment

begin_define
define|#
directive|define
name|RT5390_RX_LO1
value|(1<< 5)
end_define

begin_comment
comment|/* Possible flags for RT5390 RF register 39. */
end_comment

begin_define
define|#
directive|define
name|RT5390_RX_LO2
value|(1<< 7)
end_define

begin_comment
comment|/* Possible flags for RT5390 BBP register 4. */
end_comment

begin_define
define|#
directive|define
name|RT5390_MAC_IF_CTRL
value|(1<< 6)
end_define

begin_comment
comment|/* Possible flags for RT5390 BBP register 105. */
end_comment

begin_define
define|#
directive|define
name|RT5390_MLD
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RT5390_EN_SIG_MODULATION
value|(1<< 3)
end_define

begin_comment
comment|/* RT2860 TX descriptor */
end_comment

begin_struct
struct|struct
name|rt2860_txd
block|{
name|uint32_t
name|sdp0
decl_stmt|;
comment|/* Segment Data Pointer 0 */
name|uint16_t
name|sdl1
decl_stmt|;
comment|/* Segment Data Length 1 */
define|#
directive|define
name|RT2860_TX_BURST
value|(1<< 15)
define|#
directive|define
name|RT2860_TX_LS1
value|(1<< 14)
comment|/* SDP1 is the last segment */
name|uint16_t
name|sdl0
decl_stmt|;
comment|/* Segment Data Length 0 */
define|#
directive|define
name|RT2860_TX_DDONE
value|(1<< 15)
define|#
directive|define
name|RT2860_TX_LS0
value|(1<< 14)
comment|/* SDP0 is the last segment */
name|uint32_t
name|sdp1
decl_stmt|;
comment|/* Segment Data Pointer 1 */
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2860_TX_QSEL_SHIFT
value|1
define|#
directive|define
name|RT2860_TX_QSEL_MGMT
value|(0<< 1)
define|#
directive|define
name|RT2860_TX_QSEL_HCCA
value|(1<< 1)
define|#
directive|define
name|RT2860_TX_QSEL_EDCA
value|(2<< 1)
define|#
directive|define
name|RT2860_TX_WIV
value|(1<< 0)
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* RT2870 TX descriptor */
end_comment

begin_struct
struct|struct
name|rt2870_txd
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|pad
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* TX Wireless Information */
end_comment

begin_struct
struct|struct
name|rt2860_txwi
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2860_TX_MPDU_DSITY_SHIFT
value|5
define|#
directive|define
name|RT2860_TX_AMPDU
value|(1<< 4)
define|#
directive|define
name|RT2860_TX_TS
value|(1<< 3)
define|#
directive|define
name|RT2860_TX_CFACK
value|(1<< 2)
define|#
directive|define
name|RT2860_TX_MMPS
value|(1<< 1)
define|#
directive|define
name|RT2860_TX_FRAG
value|(1<< 0)
name|uint8_t
name|txop
decl_stmt|;
define|#
directive|define
name|RT2860_TX_TXOP_HT
value|0
define|#
directive|define
name|RT2860_TX_TXOP_PIFS
value|1
define|#
directive|define
name|RT2860_TX_TXOP_SIFS
value|2
define|#
directive|define
name|RT2860_TX_TXOP_BACKOFF
value|3
name|uint16_t
name|phy
decl_stmt|;
define|#
directive|define
name|RT2860_PHY_MODE
value|0xc000
define|#
directive|define
name|RT2860_PHY_CCK
value|(0<< 14)
define|#
directive|define
name|RT2860_PHY_OFDM
value|(1<< 14)
define|#
directive|define
name|RT2860_PHY_HT
value|(2<< 14)
define|#
directive|define
name|RT2860_PHY_HT_GF
value|(3<< 14)
define|#
directive|define
name|RT2860_PHY_SGI
value|(1<< 8)
define|#
directive|define
name|RT2860_PHY_BW40
value|(1<< 7)
define|#
directive|define
name|RT2860_PHY_MCS
value|0x7f
define|#
directive|define
name|RT2860_PHY_SHPRE
value|(1<< 3)
name|uint8_t
name|xflags
decl_stmt|;
define|#
directive|define
name|RT2860_TX_BAWINSIZE_SHIFT
value|2
define|#
directive|define
name|RT2860_TX_NSEQ
value|(1<< 1)
define|#
directive|define
name|RT2860_TX_ACK
value|(1<< 0)
name|uint8_t
name|wcid
decl_stmt|;
comment|/* Wireless Client ID */
name|uint16_t
name|len
decl_stmt|;
define|#
directive|define
name|RT2860_TX_PID_SHIFT
value|12
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

begin_comment
comment|/* RT2860 RX descriptor */
end_comment

begin_struct
struct|struct
name|rt2860_rxd
block|{
name|uint32_t
name|sdp0
decl_stmt|;
name|uint16_t
name|sdl1
decl_stmt|;
comment|/* unused */
name|uint16_t
name|sdl0
decl_stmt|;
define|#
directive|define
name|RT2860_RX_DDONE
value|(1<< 15)
define|#
directive|define
name|RT2860_RX_LS0
value|(1<< 14)
name|uint32_t
name|sdp1
decl_stmt|;
comment|/* unused */
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RT2860_RX_DEC
value|(1<< 16)
define|#
directive|define
name|RT2860_RX_AMPDU
value|(1<< 15)
define|#
directive|define
name|RT2860_RX_L2PAD
value|(1<< 14)
define|#
directive|define
name|RT2860_RX_RSSI
value|(1<< 13)
define|#
directive|define
name|RT2860_RX_HTC
value|(1<< 12)
define|#
directive|define
name|RT2860_RX_AMSDU
value|(1<< 11)
define|#
directive|define
name|RT2860_RX_MICERR
value|(1<< 10)
define|#
directive|define
name|RT2860_RX_ICVERR
value|(1<<  9)
define|#
directive|define
name|RT2860_RX_CRCERR
value|(1<<  8)
define|#
directive|define
name|RT2860_RX_MYBSS
value|(1<<  7)
define|#
directive|define
name|RT2860_RX_BC
value|(1<<  6)
define|#
directive|define
name|RT2860_RX_MC
value|(1<<  5)
define|#
directive|define
name|RT2860_RX_UC2ME
value|(1<<  4)
define|#
directive|define
name|RT2860_RX_FRAG
value|(1<<  3)
define|#
directive|define
name|RT2860_RX_NULL
value|(1<<  2)
define|#
directive|define
name|RT2860_RX_DATA
value|(1<<  1)
define|#
directive|define
name|RT2860_RX_BA
value|(1<<  0)
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* RT2870 RX descriptor */
end_comment

begin_struct
struct|struct
name|rt2870_rxd
block|{
comment|/* single 32-bit field */
name|uint32_t
name|flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* RX Wireless Information */
end_comment

begin_struct
struct|struct
name|rt2860_rxwi
block|{
name|uint8_t
name|wcid
decl_stmt|;
name|uint8_t
name|keyidx
decl_stmt|;
define|#
directive|define
name|RT2860_RX_UDF_SHIFT
value|5
define|#
directive|define
name|RT2860_RX_BSS_IDX_SHIFT
value|2
name|uint16_t
name|len
decl_stmt|;
define|#
directive|define
name|RT2860_RX_TID_SHIFT
value|12
name|uint16_t
name|seq
decl_stmt|;
name|uint16_t
name|phy
decl_stmt|;
name|uint8_t
name|rssi
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|snr
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|RT2860_RF_2820
value|0x0001
end_define

begin_comment
comment|/* 2T3R */
end_comment

begin_define
define|#
directive|define
name|RT2860_RF_2850
value|0x0002
end_define

begin_comment
comment|/* dual-band 2T3R */
end_comment

begin_define
define|#
directive|define
name|RT2860_RF_2720
value|0x0003
end_define

begin_comment
comment|/* 1T2R */
end_comment

begin_define
define|#
directive|define
name|RT2860_RF_2750
value|0x0004
end_define

begin_comment
comment|/* dual-band 1T2R */
end_comment

begin_define
define|#
directive|define
name|RT3070_RF_3020
value|0x0005
end_define

begin_comment
comment|/* 1T1R */
end_comment

begin_define
define|#
directive|define
name|RT3070_RF_2020
value|0x0006
end_define

begin_comment
comment|/* b/g */
end_comment

begin_define
define|#
directive|define
name|RT3070_RF_3021
value|0x0007
end_define

begin_comment
comment|/* 1T2R */
end_comment

begin_define
define|#
directive|define
name|RT3070_RF_3022
value|0x0008
end_define

begin_comment
comment|/* 2T2R */
end_comment

begin_define
define|#
directive|define
name|RT3070_RF_3052
value|0x0009
end_define

begin_comment
comment|/* dual-band 2T2R */
end_comment

begin_define
define|#
directive|define
name|RT3593_RF_3053
value|0x000d
end_define

begin_comment
comment|/* dual-band 3T3R */
end_comment

begin_define
define|#
directive|define
name|RT5592_RF_5592
value|0x000f
end_define

begin_comment
comment|/* dual-band 2T2R */
end_comment

begin_define
define|#
directive|define
name|RT5390_RF_5370
value|0x5370
end_define

begin_comment
comment|/* 1T1R */
end_comment

begin_define
define|#
directive|define
name|RT5390_RF_5372
value|0x5372
end_define

begin_comment
comment|/* 2T2R */
end_comment

begin_comment
comment|/* USB commands for RT2870 only */
end_comment

begin_define
define|#
directive|define
name|RT2870_RESET
value|1
end_define

begin_define
define|#
directive|define
name|RT2870_WRITE_2
value|2
end_define

begin_define
define|#
directive|define
name|RT2870_WRITE_REGION_1
value|6
end_define

begin_define
define|#
directive|define
name|RT2870_READ_REGION_1
value|7
end_define

begin_define
define|#
directive|define
name|RT2870_EEPROM_READ
value|9
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_DELAY
value|1
end_define

begin_comment
comment|/* minimum hold time (microsecond) */
end_comment

begin_define
define|#
directive|define
name|RT2860_EEPROM_VERSION
value|0x01
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_MAC01
value|0x02
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_MAC23
value|0x03
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_MAC45
value|0x04
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_PCIE_PSLEVEL
value|0x11
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_REV
value|0x12
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_ANTENNA
value|0x1a
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_CONFIG
value|0x1b
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_COUNTRY
value|0x1c
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_FREQ_LEDS
value|0x1d
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_LED1
value|0x1e
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_LED2
value|0x1f
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_LED3
value|0x20
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_LNA
value|0x22
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_RSSI1_2GHZ
value|0x23
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_RSSI2_2GHZ
value|0x24
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_RSSI1_5GHZ
value|0x25
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_RSSI2_5GHZ
value|0x26
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_DELTAPWR
value|0x28
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_PWR2GHZ_BASE1
value|0x29
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_PWR2GHZ_BASE2
value|0x30
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI1_2GHZ
value|0x37
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI2_2GHZ
value|0x38
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI3_2GHZ
value|0x39
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI4_2GHZ
value|0x3a
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI5_2GHZ
value|0x3b
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_PWR5GHZ_BASE1
value|0x3c
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_PWR5GHZ_BASE2
value|0x53
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI1_5GHZ
value|0x6a
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI2_5GHZ
value|0x6b
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI3_5GHZ
value|0x6c
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI4_5GHZ
value|0x6d
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_TSSI5_5GHZ
value|0x6e
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_RPWR
value|0x6f
end_define

begin_define
define|#
directive|define
name|RT2860_EEPROM_BBP_BASE
value|0x78
end_define

begin_define
define|#
directive|define
name|RT3071_EEPROM_RF_BASE
value|0x82
end_define

begin_comment
comment|/* EEPROM registers for RT3593. */
end_comment

begin_define
define|#
directive|define
name|RT3593_EEPROM_FREQ_LEDS
value|0x21
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_FREQ
value|0x22
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_LED1
value|0x22
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_LED2
value|0x23
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_LED3
value|0x24
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_LNA
value|0x26
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_LNA_5GHZ
value|0x27
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_RSSI1_2GHZ
value|0x28
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_RSSI2_2GHZ
value|0x29
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_RSSI1_5GHZ
value|0x2a
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_RSSI2_5GHZ
value|0x2b
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_PWR2GHZ_BASE1
value|0x30
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_PWR2GHZ_BASE2
value|0x37
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_PWR2GHZ_BASE3
value|0x3e
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_PWR5GHZ_BASE1
value|0x4b
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_PWR5GHZ_BASE2
value|0x65
end_define

begin_define
define|#
directive|define
name|RT3593_EEPROM_PWR5GHZ_BASE3
value|0x7f
end_define

begin_comment
comment|/*  * EEPROM IQ calibration.  */
end_comment

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_GAIN_CAL_TX0_2GHZ
value|0x130
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_PHASE_CAL_TX0_2GHZ
value|0x131
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_GAIN_CAL_TX1_2GHZ
value|0x133
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_PHASE_CAL_TX1_2GHZ
value|0x134
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_RF_IQ_COMPENSATION_CTL
value|0x13c
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_RF_IQ_IMBALANCE_COMPENSATION_CTL
value|0x13d
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_GAIN_CAL_TX0_CH36_TO_CH64_5GHZ
value|0x144
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_PHASE_CAL_TX0_CH36_TO_CH64_5GHZ
value|0x145
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_GAIN_CAL_TX0_CH100_TO_CH138_5GHZ
value|0x146
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_PHASE_CAL_TX0_CH100_TO_CH138_5GHZ
value|0x147
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_GAIN_CAL_TX0_CH140_TO_CH165_5GHZ
value|0x148
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_PHASE_CAL_TX0_CH140_TO_CH165_5GHZ
value|0x149
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_GAIN_CAL_TX1_CH36_TO_CH64_5GHZ
value|0x14a
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_PHASE_CAL_TX1_CH36_TO_CH64_5GHZ
value|0x14b
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_GAIN_CAL_TX1_CH100_TO_CH138_5GHZ
value|0x14c
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_PHASE_CAL_TX1_CH100_TO_CH138_5GHZ
value|0x14d
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_GAIN_CAL_TX1_CH140_TO_CH165_5GHZ
value|0x14e
end_define

begin_define
define|#
directive|define
name|RT5390_EEPROM_IQ_PHASE_CAL_TX1_CH140_TO_CH165_5GHZ
value|0x14f
end_define

begin_define
define|#
directive|define
name|RT2860_RIDX_CCK1
value|0
end_define

begin_define
define|#
directive|define
name|RT2860_RIDX_CCK11
value|3
end_define

begin_define
define|#
directive|define
name|RT2860_RIDX_OFDM6
value|4
end_define

begin_define
define|#
directive|define
name|RT2860_RIDX_MAX
value|12
end_define

begin_comment
comment|/*  * EEPROM access macro.  */
end_comment

begin_define
define|#
directive|define
name|RT2860_EEPROM_CTL
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	RAL_WRITE((sc), RT2860_PCI_EECTRL, (val));			\ 	RAL_BARRIER_READ_WRITE((sc));					\ 	DELAY(RT2860_EEPROM_DELAY);					\ } while (
comment|/* CONSTCOND */
value|0)
end_define

begin_comment
comment|/*  * Default values for MAC registers; values taken from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2870_DEF_MAC
define|\
value|{ RT2860_BCN_OFFSET0,		0xf8f0e8e0 },	\ 	{ RT2860_BCN_OFFSET1,		0x6f77d0c8 },	\ 	{ RT2860_LEGACY_BASIC_RATE,	0x0000013f },	\ 	{ RT2860_HT_BASIC_RATE,		0x00008003 },	\ 	{ RT2860_MAC_SYS_CTRL,		0x00000000 },	\ 	{ RT2860_BKOFF_SLOT_CFG,	0x00000209 },	\ 	{ RT2860_TX_SW_CFG0,		0x00000000 },	\ 	{ RT2860_TX_SW_CFG1,		0x00080606 },	\ 	{ RT2860_TX_LINK_CFG,		0x00001020 },	\ 	{ RT2860_TX_TIMEOUT_CFG,	0x000a2090 },	\ 	{ RT2860_MAX_LEN_CFG,		0x00001f00 },	\ 	{ RT2860_LED_CFG,		0x7f031e46 },	\ 	{ RT2860_WMM_AIFSN_CFG,		0x00002273 },	\ 	{ RT2860_WMM_CWMIN_CFG,		0x00002344 },	\ 	{ RT2860_WMM_CWMAX_CFG,		0x000034aa },	\ 	{ RT2860_MAX_PCNT,		0x1f3fbf9f },	\ 	{ RT2860_TX_RTY_CFG,		0x47d01f0f },	\ 	{ RT2860_AUTO_RSP_CFG,		0x00000013 },	\ 	{ RT2860_CCK_PROT_CFG,		0x05740003 },	\ 	{ RT2860_OFDM_PROT_CFG,		0x05740003 },	\ 	{ RT2860_PBF_CFG,		0x00f40006 },	\ 	{ RT2860_WPDMA_GLO_CFG,		0x00000030 },	\ 	{ RT2860_GF20_PROT_CFG,		0x01744004 },	\ 	{ RT2860_GF40_PROT_CFG,		0x03f44084 },	\ 	{ RT2860_MM20_PROT_CFG,		0x01744004 },	\ 	{ RT2860_MM40_PROT_CFG,		0x03f44084 },	\ 	{ RT2860_TXOP_CTRL_CFG,		0x0000583f },	\ 	{ RT2860_TXOP_HLDR_ET,		0x00000002 },	\ 	{ RT2860_TX_RTS_CFG,		0x00092b20 },	\ 	{ RT2860_EXP_ACK_TIME,		0x002400ca },	\ 	{ RT2860_XIFS_TIME_CFG,		0x33a41010 },	\ 	{ RT2860_PWR_PIN_CFG,		0x00000003 }
end_define

begin_comment
comment|/*  * Default values for BBP registers; values taken from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2860_DEF_BBP
define|\
value|{  65, 0x2c },	\ 	{  66, 0x38 },	\ 	{  68, 0x0b },	\ 	{  69, 0x12 },	\ 	{  70, 0x0a },	\ 	{  73, 0x10 },	\ 	{  81, 0x37 },	\ 	{  82, 0x62 },	\ 	{  83, 0x6a },	\ 	{  84, 0x99 },	\ 	{  86, 0x00 },	\ 	{  91, 0x04 },	\ 	{  92, 0x00 },	\ 	{ 103, 0x00 },	\ 	{ 105, 0x05 },	\ 	{ 106, 0x35 }
end_define

begin_define
define|#
directive|define
name|RT5390_DEF_BBP
define|\
value|{  31, 0x08 },	\ 	{  65, 0x2c },	\ 	{  66, 0x38 },	\ 	{  68, 0x0b },	\ 	{  69, 0x0d },	\ 	{  70, 0x06 },	\ 	{  73, 0x13 },	\ 	{  75, 0x46 },	\ 	{  76, 0x28 },	\ 	{  77, 0x59 },	\ 	{  81, 0x37 },	\ 	{  82, 0x62 },	\ 	{  83, 0x7a },	\ 	{  84, 0x9a },	\ 	{  86, 0x38 },	\ 	{  91, 0x04 },	\ 	{  92, 0x02 },	\ 	{ 103, 0xc0 },	\ 	{ 104, 0x92 },	\ 	{ 105, 0x3c },	\ 	{ 106, 0x03 },	\ 	{ 128, 0x12 }
end_define

begin_define
define|#
directive|define
name|RT5592_DEF_BBP
define|\
value|{  20, 0x06 },	\ 	{  31, 0x08 },	\ 	{  65, 0x2c },	\ 	{  66, 0x38 },	\ 	{  68, 0xdd },	\ 	{  69, 0x1a },	\ 	{  70, 0x05 },	\ 	{  73, 0x13 },	\ 	{  74, 0x0f },	\ 	{  75, 0x4f },	\ 	{  76, 0x28 },	\ 	{  77, 0x59 },	\ 	{  81, 0x37 },	\ 	{  82, 0x62 },	\ 	{  83, 0x6a },	\ 	{  84, 0x9a },	\ 	{  86, 0x38 },	\ 	{  88, 0x90 },	\ 	{  91, 0x04 },	\ 	{  92, 0x02 },	\ 	{  95, 0x9a },	\ 	{  98, 0x12 },	\ 	{ 103, 0xc0 },	\ 	{ 104, 0x92 },	\ 	{ 105, 0x3c },	\ 	{ 106, 0x35 },	\ 	{ 128, 0x12 },	\ 	{ 134, 0xd0 },	\ 	{ 135, 0xf6 },	\ 	{ 137, 0x0f }
end_define

begin_comment
comment|/*  * Default settings for RF registers; values derived from the reference driver.  */
end_comment

begin_define
define|#
directive|define
name|RT2860_RF2850
define|\
value|{   1, 0x98402ecc, 0x984c0786, 0x9816b455, 0x9800510b },	\ 	{   2, 0x98402ecc, 0x984c0786, 0x98168a55, 0x9800519f },	\ 	{   3, 0x98402ecc, 0x984c078a, 0x98168a55, 0x9800518b },	\ 	{   4, 0x98402ecc, 0x984c078a, 0x98168a55, 0x9800519f },	\ 	{   5, 0x98402ecc, 0x984c078e, 0x98168a55, 0x9800518b },	\ 	{   6, 0x98402ecc, 0x984c078e, 0x98168a55, 0x9800519f },	\ 	{   7, 0x98402ecc, 0x984c0792, 0x98168a55, 0x9800518b },	\ 	{   8, 0x98402ecc, 0x984c0792, 0x98168a55, 0x9800519f },	\ 	{   9, 0x98402ecc, 0x984c0796, 0x98168a55, 0x9800518b },	\ 	{  10, 0x98402ecc, 0x984c0796, 0x98168a55, 0x9800519f },	\ 	{  11, 0x98402ecc, 0x984c079a, 0x98168a55, 0x9800518b },	\ 	{  12, 0x98402ecc, 0x984c079a, 0x98168a55, 0x9800519f },	\ 	{  13, 0x98402ecc, 0x984c079e, 0x98168a55, 0x9800518b },	\ 	{  14, 0x98402ecc, 0x984c07a2, 0x98168a55, 0x98005193 },	\ 	{  36, 0x98402ecc, 0x984c099a, 0x98158a55, 0x980ed1a3 },	\ 	{  38, 0x98402ecc, 0x984c099e, 0x98158a55, 0x980ed193 },	\ 	{  40, 0x98402ec8, 0x984c0682, 0x98158a55, 0x980ed183 },	\ 	{  44, 0x98402ec8, 0x984c0682, 0x98158a55, 0x980ed1a3 },	\ 	{  46, 0x98402ec8, 0x984c0686, 0x98158a55, 0x980ed18b },	\ 	{  48, 0x98402ec8, 0x984c0686, 0x98158a55, 0x980ed19b },	\ 	{  52, 0x98402ec8, 0x984c068a, 0x98158a55, 0x980ed193 },	\ 	{  54, 0x98402ec8, 0x984c068a, 0x98158a55, 0x980ed1a3 },	\ 	{  56, 0x98402ec8, 0x984c068e, 0x98158a55, 0x980ed18b },	\ 	{  60, 0x98402ec8, 0x984c0692, 0x98158a55, 0x980ed183 },	\ 	{  62, 0x98402ec8, 0x984c0692, 0x98158a55, 0x980ed193 },	\ 	{  64, 0x98402ec8, 0x984c0692, 0x98158a55, 0x980ed1a3 },	\ 	{ 100, 0x98402ec8, 0x984c06b2, 0x98178a55, 0x980ed783 },	\ 	{ 102, 0x98402ec8, 0x985c06b2, 0x98578a55, 0x980ed793 },	\ 	{ 104, 0x98402ec8, 0x985c06b2, 0x98578a55, 0x980ed1a3 },	\ 	{ 108, 0x98402ecc, 0x985c0a32, 0x98578a55, 0x980ed193 },	\ 	{ 110, 0x98402ecc, 0x984c0a36, 0x98178a55, 0x980ed183 },	\ 	{ 112, 0x98402ecc, 0x984c0a36, 0x98178a55, 0x980ed19b },	\ 	{ 116, 0x98402ecc, 0x984c0a3a, 0x98178a55, 0x980ed1a3 },	\ 	{ 118, 0x98402ecc, 0x984c0a3e, 0x98178a55, 0x980ed193 },	\ 	{ 120, 0x98402ec4, 0x984c0382, 0x98178a55, 0x980ed183 },	\ 	{ 124, 0x98402ec4, 0x984c0382, 0x98178a55, 0x980ed193 },	\ 	{ 126, 0x98402ec4, 0x984c0382, 0x98178a55, 0x980ed15b },	\ 	{ 128, 0x98402ec4, 0x984c0382, 0x98178a55, 0x980ed1a3 },	\ 	{ 132, 0x98402ec4, 0x984c0386, 0x98178a55, 0x980ed18b },	\ 	{ 134, 0x98402ec4, 0x984c0386, 0x98178a55, 0x980ed193 },	\ 	{ 136, 0x98402ec4, 0x984c0386, 0x98178a55, 0x980ed19b },	\ 	{ 140, 0x98402ec4, 0x984c038a, 0x98178a55, 0x980ed183 },	\ 	{ 149, 0x98402ec4, 0x984c038a, 0x98178a55, 0x980ed1a7 },	\ 	{ 151, 0x98402ec4, 0x984c038e, 0x98178a55, 0x980ed187 },	\ 	{ 153, 0x98402ec4, 0x984c038e, 0x98178a55, 0x980ed18f },	\ 	{ 157, 0x98402ec4, 0x984c038e, 0x98178a55, 0x980ed19f },	\ 	{ 159, 0x98402ec4, 0x984c038e, 0x98178a55, 0x980ed1a7 },	\ 	{ 161, 0x98402ec4, 0x984c0392, 0x98178a55, 0x980ed187 },	\ 	{ 165, 0x98402ec4, 0x984c0392, 0x98178a55, 0x980ed197 },	\ 	{ 167, 0x98402ec4, 0x984c03d2, 0x98179855, 0x9815531f },	\ 	{ 169, 0x98402ec4, 0x984c03d2, 0x98179855, 0x98155327 },	\ 	{ 171, 0x98402ec4, 0x984c03d6, 0x98179855, 0x98155307 },	\ 	{ 173, 0x98402ec4, 0x984c03d6, 0x98179855, 0x9815530f },	\ 	{ 184, 0x95002ccc, 0x9500491e, 0x9509be55, 0x950c0a0b },	\ 	{ 188, 0x95002ccc, 0x95004922, 0x9509be55, 0x950c0a13 },	\ 	{ 192, 0x95002ccc, 0x95004926, 0x9509be55, 0x950c0a1b },	\ 	{ 196, 0x95002ccc, 0x9500492a, 0x9509be55, 0x950c0a23 },	\ 	{ 208, 0x95002ccc, 0x9500493a, 0x9509be55, 0x950c0a13 },	\ 	{ 212, 0x95002ccc, 0x9500493e, 0x9509be55, 0x950c0a1b },	\ 	{ 216, 0x95002ccc, 0x95004982, 0x9509be55, 0x950c0a23 }
end_define

begin_define
define|#
directive|define
name|RT3070_RF3052
define|\
value|{ 0xf1, 2,  2 },	\ 	{ 0xf1, 2,  7 },	\ 	{ 0xf2, 2,  2 },	\ 	{ 0xf2, 2,  7 },	\ 	{ 0xf3, 2,  2 },	\ 	{ 0xf3, 2,  7 },	\ 	{ 0xf4, 2,  2 },	\ 	{ 0xf4, 2,  7 },	\ 	{ 0xf5, 2,  2 },	\ 	{ 0xf5, 2,  7 },	\ 	{ 0xf6, 2,  2 },	\ 	{ 0xf6, 2,  7 },	\ 	{ 0xf7, 2,  2 },	\ 	{ 0xf8, 2,  4 },	\ 	{ 0x56, 0,  4 },	\ 	{ 0x56, 0,  6 },	\ 	{ 0x56, 0,  8 },	\ 	{ 0x57, 0,  0 },	\ 	{ 0x57, 0,  2 },	\ 	{ 0x57, 0,  4 },	\ 	{ 0x57, 0,  8 },	\ 	{ 0x57, 0, 10 },	\ 	{ 0x58, 0,  0 },	\ 	{ 0x58, 0,  4 },	\ 	{ 0x58, 0,  6 },	\ 	{ 0x58, 0,  8 },	\ 	{ 0x5b, 0,  8 },	\ 	{ 0x5b, 0, 10 },	\ 	{ 0x5c, 0,  0 },	\ 	{ 0x5c, 0,  4 },	\ 	{ 0x5c, 0,  6 },	\ 	{ 0x5c, 0,  8 },	\ 	{ 0x5d, 0,  0 },	\ 	{ 0x5d, 0,  2 },	\ 	{ 0x5d, 0,  4 },	\ 	{ 0x5d, 0,  8 },	\ 	{ 0x5d, 0, 10 },	\ 	{ 0x5e, 0,  0 },	\ 	{ 0x5e, 0,  4 },	\ 	{ 0x5e, 0,  6 },	\ 	{ 0x5e, 0,  8 },	\ 	{ 0x5f, 0,  0 },	\ 	{ 0x5f, 0,  9 },	\ 	{ 0x5f, 0, 11 },	\ 	{ 0x60, 0,  1 },	\ 	{ 0x60, 0,  5 },	\ 	{ 0x60, 0,  7 },	\ 	{ 0x60, 0,  9 },	\ 	{ 0x61, 0,  1 },	\ 	{ 0x61, 0,  3 },	\ 	{ 0x61, 0,  5 },	\ 	{ 0x61, 0,  7 },	\ 	{ 0x61, 0,  9 }
end_define

begin_define
define|#
directive|define
name|RT5592_RF5592_20MHZ
define|\
value|{ 0x1e2,  4, 10, 3 },	\ 	{ 0x1e3,  4, 10, 3 },	\ 	{ 0x1e4,  4, 10, 3 },	\ 	{ 0x1e5,  4, 10, 3 },	\ 	{ 0x1e6,  4, 10, 3 },	\ 	{ 0x1e7,  4, 10, 3 },	\ 	{ 0x1e8,  4, 10, 3 },	\ 	{ 0x1e9,  4, 10, 3 },	\ 	{ 0x1ea,  4, 10, 3 },	\ 	{ 0x1eb,  4, 10, 3 },	\ 	{ 0x1ec,  4, 10, 3 },	\ 	{ 0x1ed,  4, 10, 3 },	\ 	{ 0x1ee,  4, 10, 3 },	\ 	{ 0x1f0,  8, 10, 3 },	\ 	{  0xac,  8, 12, 1 },	\ 	{  0xad,  0, 12, 1 },	\ 	{  0xad,  4, 12, 1 },	\ 	{  0xae,  0, 12, 1 },	\ 	{  0xae,  4, 12, 1 },	\ 	{  0xae,  8, 12, 1 },	\ 	{  0xaf,  4, 12, 1 },	\ 	{  0xaf,  8, 12, 1 },	\ 	{  0xb0,  0, 12, 1 },	\ 	{  0xb0,  8, 12, 1 },	\ 	{  0xb1,  0, 12, 1 },	\ 	{  0xb1,  4, 12, 1 },	\ 	{  0xb7,  4, 12, 1 },	\ 	{  0xb7,  8, 12, 1 },	\ 	{  0xb8,  0, 12, 1 },	\ 	{  0xb8,  8, 12, 1 },	\ 	{  0xb9,  0, 12, 1 },	\ 	{  0xb9,  4, 12, 1 },	\ 	{  0xba,  0, 12, 1 },	\ 	{  0xba,  4, 12, 1 },	\ 	{  0xba,  8, 12, 1 },	\ 	{  0xbb,  4, 12, 1 },	\ 	{  0xbb,  8, 12, 1 },	\ 	{  0xbc,  0, 12, 1 },	\ 	{  0xbc,  8, 12, 1 },	\ 	{  0xbd,  0, 12, 1 },	\ 	{  0xbd,  4, 12, 1 },	\ 	{  0xbe,  0, 12, 1 },	\ 	{  0xbf,  6, 12, 1 },	\ 	{  0xbf, 10, 12, 1 },	\ 	{  0xc0,  2, 12, 1 },	\ 	{  0xc0, 10, 12, 1 },	\ 	{  0xc1,  2, 12, 1 },	\ 	{  0xc1,  6, 12, 1 },	\ 	{  0xc2,  2, 12, 1 },	\ 	{  0xa4,  0, 12, 1 },	\ 	{  0xa4,  4, 12, 1 },	\ 	{  0xa5,  8, 12, 1 },	\ 	{  0xa6,  0, 12, 1 }
end_define

begin_define
define|#
directive|define
name|RT5592_RF5592_40MHZ
define|\
value|{ 0xf1,  2, 10, 3 },	\ 	{ 0xf1,  7, 10, 3 },	\ 	{ 0xf2,  2, 10, 3 },	\ 	{ 0xf2,  7, 10, 3 },	\ 	{ 0xf3,  2, 10, 3 },	\ 	{ 0xf3,  7, 10, 3 },	\ 	{ 0xf4,  2, 10, 3 },	\ 	{ 0xf4,  7, 10, 3 },	\ 	{ 0xf5,  2, 10, 3 },	\ 	{ 0xf5,  7, 10, 3 },	\ 	{ 0xf6,  2, 10, 3 },	\ 	{ 0xf6,  7, 10, 3 },	\ 	{ 0xf7,  2, 10, 3 },	\ 	{ 0xf8,  4, 10, 3 },	\ 	{ 0x56,  4, 12, 1 },	\ 	{ 0x56,  6, 12, 1 },	\ 	{ 0x56,  8, 12, 1 },	\ 	{ 0x57,  0, 12, 1 },	\ 	{ 0x57,  2, 12, 1 },	\ 	{ 0x57,  4, 12, 1 },	\ 	{ 0x57,  8, 12, 1 },	\ 	{ 0x57, 10, 12, 1 },	\ 	{ 0x58,  0, 12, 1 },	\ 	{ 0x58,  4, 12, 1 },	\ 	{ 0x58,  6, 12, 1 },	\ 	{ 0x58,  8, 12, 1 },	\ 	{ 0x5b,  8, 12, 1 },	\ 	{ 0x5b, 10, 12, 1 },	\ 	{ 0x5c,  0, 12, 1 },	\ 	{ 0x5c,  4, 12, 1 },	\ 	{ 0x5c,  6, 12, 1 },	\ 	{ 0x5c,  8, 12, 1 },	\ 	{ 0x5d,  0, 12, 1 },	\ 	{ 0x5d,  2, 12, 1 },	\ 	{ 0x5d,  4, 12, 1 },	\ 	{ 0x5d,  8, 12, 1 },	\ 	{ 0x5d, 10, 12, 1 },	\ 	{ 0x5e,  0, 12, 1 },	\ 	{ 0x5e,  4, 12, 1 },	\ 	{ 0x5e,  6, 12, 1 },	\ 	{ 0x5e,  8, 12, 1 },	\ 	{ 0x5f,  0, 12, 1 },	\ 	{ 0x5f,  9, 12, 1 },	\ 	{ 0x5f, 11, 12, 1 },	\ 	{ 0x60,  1, 12, 1 },	\ 	{ 0x60,  5, 12, 1 },	\ 	{ 0x60,  7, 12, 1 },	\ 	{ 0x60,  9, 12, 1 },	\ 	{ 0x61,  1, 12, 1 },	\ 	{ 0x52,  0, 12, 1 },	\ 	{ 0x52,  4, 12, 1 },	\ 	{ 0x52,  8, 12, 1 },	\ 	{ 0x53,  0, 12, 1 }
end_define

begin_define
define|#
directive|define
name|RT3070_DEF_RF
define|\
value|{  4, 0x40 },	\ 	{  5, 0x03 },	\ 	{  6, 0x02 },	\ 	{  7, 0x60 },	\ 	{  9, 0x0f },	\ 	{ 10, 0x41 },	\ 	{ 11, 0x21 },	\ 	{ 12, 0x7b },	\ 	{ 14, 0x90 },	\ 	{ 15, 0x58 },	\ 	{ 16, 0xb3 },	\ 	{ 17, 0x92 },	\ 	{ 18, 0x2c },	\ 	{ 19, 0x02 },	\ 	{ 20, 0xba },	\ 	{ 21, 0xdb },	\ 	{ 24, 0x16 },	\ 	{ 25, 0x03 },	\ 	{ 29, 0x1f }
end_define

begin_define
define|#
directive|define
name|RT3572_DEF_RF
define|\
value|{  0, 0x70 },	\ 	{  1, 0x81 },	\ 	{  2, 0xf1 },	\ 	{  3, 0x02 },	\ 	{  4, 0x4c },	\ 	{  5, 0x05 },	\ 	{  6, 0x4a },	\ 	{  7, 0xd8 },	\ 	{  9, 0xc3 },	\ 	{ 10, 0xf1 },	\ 	{ 11, 0xb9 },	\ 	{ 12, 0x70 },	\ 	{ 13, 0x65 },	\ 	{ 14, 0xa0 },	\ 	{ 15, 0x53 },	\ 	{ 16, 0x4c },	\ 	{ 17, 0x23 },	\ 	{ 18, 0xac },	\ 	{ 19, 0x93 },	\ 	{ 20, 0xb3 },	\ 	{ 21, 0xd0 },	\ 	{ 22, 0x00 },  	\ 	{ 23, 0x3c },	\ 	{ 24, 0x16 },	\ 	{ 25, 0x15 },	\ 	{ 26, 0x85 },	\ 	{ 27, 0x00 },	\ 	{ 28, 0x00 },	\ 	{ 29, 0x9b },	\ 	{ 30, 0x09 },	\ 	{ 31, 0x10 }
end_define

begin_define
define|#
directive|define
name|RT3593_DEF_RF
define|\
value|{  1, 0x03 },	\ 	{  3, 0x80 },	\ 	{  5, 0x00 },	\ 	{  6, 0x40 },	\ 	{  8, 0xf1 },	\ 	{  9, 0x02 },	\ 	{ 10, 0xd3 },	\ 	{ 11, 0x40 },	\ 	{ 12, 0x4e },	\ 	{ 13, 0x12 },	\ 	{ 18, 0x40 },	\ 	{ 22, 0x20 },	\ 	{ 30, 0x10 },	\ 	{ 31, 0x80 },	\ 	{ 32, 0x78 },	\ 	{ 33, 0x3b },	\ 	{ 34, 0x3c },	\ 	{ 35, 0xe0 },	\ 	{ 38, 0x86 },	\ 	{ 39, 0x23 },	\ 	{ 44, 0xd3 },	\ 	{ 45, 0xbb },	\ 	{ 46, 0x60 },	\ 	{ 49, 0x81 },	\ 	{ 50, 0x86 },	\ 	{ 51, 0x75 },	\ 	{ 52, 0x45 },	\ 	{ 53, 0x18 },	\ 	{ 54, 0x18 },	\ 	{ 55, 0x18 },	\ 	{ 56, 0xdb },	\ 	{ 57, 0x6e }
end_define

begin_define
define|#
directive|define
name|RT5390_DEF_RF
define|\
value|{  1, 0x0f },	\ 	{  2, 0x80 },	\ 	{  3, 0x88 },	\ 	{  5, 0x10 },	\ 	{  6, 0xa0 },	\ 	{  7, 0x00 },	\ 	{ 10, 0x53 },	\ 	{ 11, 0x4a },	\ 	{ 12, 0x46 },	\ 	{ 13, 0x9f },	\ 	{ 14, 0x00 },	\ 	{ 15, 0x00 },	\ 	{ 16, 0x00 },	\ 	{ 18, 0x03 },	\ 	{ 19, 0x00 },	\ 	{ 20, 0x00 },	\ 	{ 21, 0x00 },	\ 	{ 22, 0x20 },  	\ 	{ 23, 0x00 },	\ 	{ 24, 0x00 },	\ 	{ 25, 0xc0 },	\ 	{ 26, 0x00 },	\ 	{ 27, 0x09 },	\ 	{ 28, 0x00 },	\ 	{ 29, 0x10 },	\ 	{ 30, 0x10 },	\ 	{ 31, 0x80 },	\ 	{ 32, 0x80 },	\ 	{ 33, 0x00 },	\ 	{ 34, 0x07 },	\ 	{ 35, 0x12 },	\ 	{ 36, 0x00 },	\ 	{ 37, 0x08 },	\ 	{ 38, 0x85 },	\ 	{ 39, 0x1b },	\ 	{ 40, 0x0b },	\ 	{ 41, 0xbb },	\ 	{ 42, 0xd2 },	\ 	{ 43, 0x9a },	\ 	{ 44, 0x0e },	\ 	{ 45, 0xa2 },	\ 	{ 46, 0x7b },	\ 	{ 47, 0x00 },	\ 	{ 48, 0x10 },	\ 	{ 49, 0x94 },	\ 	{ 52, 0x38 },	\ 	{ 53, 0x84 },	\ 	{ 54, 0x78 },	\ 	{ 55, 0x44 },	\ 	{ 56, 0x22 },	\ 	{ 57, 0x80 },	\ 	{ 58, 0x7f },	\ 	{ 59, 0x8f },	\ 	{ 60, 0x45 },	\ 	{ 61, 0xdd },	\ 	{ 62, 0x00 },	\ 	{ 63, 0x00 }
end_define

begin_define
define|#
directive|define
name|RT5392_DEF_RF
define|\
value|{  1, 0x17 },	\ 	{  3, 0x88 },	\ 	{  5, 0x10 },	\ 	{  6, 0xe0 },	\ 	{  7, 0x00 },	\ 	{ 10, 0x53 },	\ 	{ 11, 0x4a },	\ 	{ 12, 0x46 },	\ 	{ 13, 0x9f },	\ 	{ 14, 0x00 },	\ 	{ 15, 0x00 },	\ 	{ 16, 0x00 },	\ 	{ 18, 0x03 },	\ 	{ 19, 0x4d },	\ 	{ 20, 0x00 },	\ 	{ 21, 0x8d },	\ 	{ 22, 0x20 },  	\ 	{ 23, 0x0b },	\ 	{ 24, 0x44 },	\ 	{ 25, 0x80 },	\ 	{ 26, 0x82 },	\ 	{ 27, 0x09 },	\ 	{ 28, 0x00 },	\ 	{ 29, 0x10 },	\ 	{ 30, 0x10 },	\ 	{ 31, 0x80 },	\ 	{ 32, 0x20 },	\ 	{ 33, 0xc0 },	\ 	{ 34, 0x07 },	\ 	{ 35, 0x12 },	\ 	{ 36, 0x00 },	\ 	{ 37, 0x08 },	\ 	{ 38, 0x89 },	\ 	{ 39, 0x1b },	\ 	{ 40, 0x0f },	\ 	{ 41, 0xbb },	\ 	{ 42, 0xd5 },	\ 	{ 43, 0x9b },	\ 	{ 44, 0x0e },	\ 	{ 45, 0xa2 },	\ 	{ 46, 0x73 },	\ 	{ 47, 0x0c },	\ 	{ 48, 0x10 },	\ 	{ 49, 0x94 },	\ 	{ 50, 0x94 },	\ 	{ 51, 0x3a },	\ 	{ 52, 0x48 },	\ 	{ 53, 0x44 },	\ 	{ 54, 0x38 },	\ 	{ 55, 0x43 },	\ 	{ 56, 0xa1 },	\ 	{ 57, 0x00 },	\ 	{ 58, 0x39 },	\ 	{ 59, 0x07 },	\ 	{ 60, 0x45 },	\ 	{ 61, 0x91 },	\ 	{ 62, 0x39 },	\ 	{ 63, 0x07 }
end_define

begin_define
define|#
directive|define
name|RT5592_DEF_RF
define|\
value|{  1, 0x3f },	\ 	{  3, 0x08 },	\ 	{  5, 0x10 },	\ 	{  6, 0xe4 },	\ 	{  7, 0x00 },	\ 	{ 14, 0x00 },	\ 	{ 15, 0x00 },	\ 	{ 16, 0x00 },	\ 	{ 18, 0x03 },	\ 	{ 19, 0x4d },	\ 	{ 20, 0x10 },	\ 	{ 21, 0x8d },	\ 	{ 26, 0x82 },	\ 	{ 28, 0x00 },	\ 	{ 29, 0x10 },	\ 	{ 33, 0xc0 },	\ 	{ 34, 0x07 },	\ 	{ 35, 0x12 },	\ 	{ 47, 0x0c },	\ 	{ 53, 0x22 },	\ 	{ 63, 0x07 }
end_define

begin_define
define|#
directive|define
name|RT5592_2GHZ_DEF_RF
define|\
value|{ 10, 0x90 },		\ 	{ 11, 0x4a },		\ 	{ 12, 0x52 },		\ 	{ 13, 0x42 },		\ 	{ 22, 0x40 },		\ 	{ 24, 0x4a },		\ 	{ 25, 0x80 },		\ 	{ 27, 0x42 },		\ 	{ 36, 0x80 },		\ 	{ 37, 0x08 },		\ 	{ 38, 0x89 },		\ 	{ 39, 0x1b },		\ 	{ 40, 0x0d },		\ 	{ 41, 0x9b },		\ 	{ 42, 0xd5 },		\ 	{ 43, 0x72 },		\ 	{ 44, 0x0e },		\ 	{ 45, 0xa2 },		\ 	{ 46, 0x6b },		\ 	{ 48, 0x10 },		\ 	{ 51, 0x3e },		\ 	{ 52, 0x48 },		\ 	{ 54, 0x38 },		\ 	{ 56, 0xa1 },		\ 	{ 57, 0x00 },		\ 	{ 58, 0x39 },		\ 	{ 60, 0x45 },		\ 	{ 61, 0x91 },		\ 	{ 62, 0x39 }
end_define

begin_define
define|#
directive|define
name|RT5592_5GHZ_DEF_RF
define|\
value|{ 10, 0x97 },		\ 	{ 11, 0x40 },		\ 	{ 25, 0xbf },		\ 	{ 27, 0x42 },		\ 	{ 36, 0x00 },		\ 	{ 37, 0x04 },		\ 	{ 38, 0x85 },		\ 	{ 40, 0x42 },		\ 	{ 41, 0xbb },		\ 	{ 42, 0xd7 },		\ 	{ 45, 0x41 },		\ 	{ 48, 0x00 },		\ 	{ 57, 0x77 },		\ 	{ 60, 0x05 },		\ 	{ 61, 0x01 }
end_define

begin_define
define|#
directive|define
name|RT5592_CHAN_5GHZ
define|\
value|{  36,  64, 12, 0x2e },	\ 	{ 100, 165, 12, 0x0e },	\ 	{  36,  64, 13, 0x22 },	\ 	{ 100, 165, 13, 0x42 },	\ 	{  36,  64, 22, 0x60 },	\ 	{ 100, 165, 22, 0x40 },	\ 	{  36,  64, 23, 0x7f },	\ 	{ 100, 153, 23, 0x3c },	\ 	{ 155, 165, 23, 0x38 },	\ 	{  36,  50, 24, 0x09 },	\ 	{  52,  64, 24, 0x07 },	\ 	{ 100, 153, 24, 0x06 },	\ 	{ 155, 165, 24, 0x05 },	\ 	{  36,  64, 39, 0x1c },	\ 	{ 100, 138, 39, 0x1a },	\ 	{ 140, 165, 39, 0x18 },	\ 	{  36,  64, 43, 0x5b },	\ 	{ 100, 138, 43, 0x3b },	\ 	{ 140, 165, 43, 0x1b },	\ 	{  36,  64, 44, 0x40 },	\ 	{ 100, 138, 44, 0x20 },	\ 	{ 140, 165, 44, 0x10 },	\ 	{  36,  64, 46, 0x00 },	\ 	{ 100, 138, 46, 0x18 },	\ 	{ 140, 165, 46, 0x08 },	\ 	{  36,  64, 51, 0xfe },	\ 	{ 100, 124, 51, 0xfc },	\ 	{ 126, 165, 51, 0xec },	\ 	{  36,  64, 52, 0x0c },	\ 	{ 100, 138, 52, 0x06 },	\ 	{ 140, 165, 52, 0x06 },	\ 	{  36,  64, 54, 0xf8 },	\ 	{ 100, 165, 54, 0xeb },	\ 	{ 36,   50, 55, 0x06 },	\ 	{ 52,   64, 55, 0x04 },	\ 	{ 100, 138, 55, 0x01 },	\ 	{ 140, 165, 55, 0x00 },	\ 	{  36,  50, 56, 0xd3 },	\ 	{  52, 128, 56, 0xbb },	\ 	{ 130, 165, 56, 0xab },	\ 	{  36,  64, 58, 0x15 },	\ 	{ 100, 116, 58, 0x1d },	\ 	{ 118, 165, 58, 0x15 },	\ 	{  36,  64, 59, 0x7f },	\ 	{ 100, 138, 59, 0x3f },	\ 	{ 140, 165, 59, 0x7c },	\ 	{  36,  64, 62, 0x15 },	\ 	{ 100, 116, 62, 0x1d },	\ 	{ 118, 165, 62, 0x15 }
end_define

begin_union
union|union
name|run_stats
block|{
name|uint32_t
name|raw
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|fail
decl_stmt|;
name|uint16_t
name|pad
decl_stmt|;
block|}
name|error
struct|;
struct|struct
block|{
name|uint16_t
name|success
decl_stmt|;
name|uint16_t
name|retry
decl_stmt|;
block|}
name|tx
struct|;
block|}
name|__aligned
argument_list|(
literal|4
argument_list|)
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_RUNREG_H_ */
end_comment

end_unit

