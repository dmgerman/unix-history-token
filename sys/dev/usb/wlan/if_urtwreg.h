begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Weongyo Jeong<weongyo@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|URTW_CONFIG_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|URTW_IFACE_INDEX
value|0
end_define

begin_comment
comment|/* for 8187  */
end_comment

begin_define
define|#
directive|define
name|URTW_MAC0
value|0x0000
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_MAC1
value|0x0001
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_MAC2
value|0x0002
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_MAC3
value|0x0003
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_MAC4
value|0x0004
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_MAC5
value|0x0005
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_MAR
value|0x0008
end_define

begin_comment
comment|/* 6 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RXFIFO_CNT
value|0x0010
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TXFIFO_CNT
value|0x0012
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_BQREQ
value|0x0013
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TSFT
value|0x0018
end_define

begin_comment
comment|/* 6 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TLPDA
value|0x0020
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TNPDA
value|0x0024
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_THPDA
value|0x0028
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_BRSR
value|0x002c
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_BRSR_MBR_8185
value|(0x0fff)
end_define

begin_define
define|#
directive|define
name|URTW_8187B_EIFS
value|0x002d
end_define

begin_comment
comment|/* 1 byte for 8187B  */
end_comment

begin_define
define|#
directive|define
name|URTW_BSSID
value|0x002e
end_define

begin_comment
comment|/* 6 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_BRSR_8187B
value|0x0034
end_define

begin_comment
comment|/* 2 byte for 8187B  */
end_comment

begin_define
define|#
directive|define
name|URTW_RESP_RATE
value|0x0034
end_define

begin_comment
comment|/* 1 byte for 8187L  */
end_comment

begin_define
define|#
directive|define
name|URTW_RESP_MAX_RATE_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|URTW_RESP_MIN_RATE_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|URTW_EIFS
value|0x0035
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CMD
value|0x0037
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CMD_TX_ENABLE
value|(0x4)
end_define

begin_define
define|#
directive|define
name|URTW_CMD_RX_ENABLE
value|(0x8)
end_define

begin_define
define|#
directive|define
name|URTW_CMD_RST
value|(0x10)
end_define

begin_define
define|#
directive|define
name|URTW_INTR_MASK
value|0x003c
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_INTR_STATUS
value|0x003e
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TX_CONF
value|0x0040
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TX_LOOPBACK_SHIFT
value|(17)
end_define

begin_define
define|#
directive|define
name|URTW_TX_LOOPBACK_NONE
value|(0<< URTW_TX_LOOPBACK_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_TX_LOOPBACK_MAC
value|(1<< URTW_TX_LOOPBACK_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_TX_LOOPBACK_BASEBAND
value|(2<< URTW_TX_LOOPBACK_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_TX_LOOPBACK_CONTINUE
value|(3<< URTW_TX_LOOPBACK_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_TX_LOOPBACK_MASK
value|(0x60000)
end_define

begin_define
define|#
directive|define
name|URTW_TX_DPRETRY_MASK
value|(0xff00)
end_define

begin_define
define|#
directive|define
name|URTW_TX_RTSRETRY_MASK
value|(0xff)
end_define

begin_define
define|#
directive|define
name|URTW_TX_DPRETRY_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|URTW_TX_RTSRETRY_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|URTW_TX_NOCRC
value|(0x10000)
end_define

begin_define
define|#
directive|define
name|URTW_TX_MXDMA_MASK
value|(0xe00000)
end_define

begin_define
define|#
directive|define
name|URTW_TX_MXDMA_1024
value|(6<< URTW_TX_MXDMA_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_TX_MXDMA_2048
value|(7<< URTW_TX_MXDMA_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_TX_MXDMA_SHIFT
value|(21)
end_define

begin_define
define|#
directive|define
name|URTW_TX_DISCW
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|URTW_TX_SWPLCPLEN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|URTW_TX_R8187vD
value|(5<< 25)
end_define

begin_define
define|#
directive|define
name|URTW_TX_R8187vD_B
value|(6<< 25)
end_define

begin_define
define|#
directive|define
name|URTW_TX_HWMASK
value|(7<< 25)
end_define

begin_define
define|#
directive|define
name|URTW_TX_DISREQQSIZE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|URTW_TX_HW_SEQNUM
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|URTW_TX_CWMIN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|URTW_TX_NOICV
value|(0x80000)
end_define

begin_define
define|#
directive|define
name|URTW_RX
value|0x0044
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RX_9356SEL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_MASK
define|\
value|(URTW_RX_FILTER_ALLMAC | URTW_RX_FILTER_NICMAC | URTW_RX_FILTER_MCAST | \ 	URTW_RX_FILTER_BCAST | URTW_RX_FILTER_CRCERR | URTW_RX_FILTER_ICVERR | \ 	URTW_RX_FILTER_DATA | URTW_RX_FILTER_CTL | URTW_RX_FILTER_MNG |	\ 	(1<< 21) |							\ 	URTW_RX_FILTER_PWR | URTW_RX_CHECK_BSSID)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_ALLMAC
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_NICMAC
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_MCAST
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_BCAST
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_CRCERR
value|(0x00000020)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_ICVERR
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_DATA
value|(0x00040000)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_CTL
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_MNG
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FILTER_PWR
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|URTW_RX_CHECK_BSSID
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FIFO_THRESHOLD_MASK
value|((1<< 13) | (1<< 14) | (1<< 15))
end_define

begin_define
define|#
directive|define
name|URTW_RX_FIFO_THRESHOLD_SHIFT
value|(13)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FIFO_THRESHOLD_128
value|(3)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FIFO_THRESHOLD_256
value|(4)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FIFO_THRESHOLD_512
value|(5)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FIFO_THRESHOLD_1024
value|(6)
end_define

begin_define
define|#
directive|define
name|URTW_RX_FIFO_THRESHOLD_NONE
value|(7<< URTW_RX_FIFO_THRESHOLD_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_RX_AUTORESETPHY
value|(1<< URTW_RX_AUTORESETPHY_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_RX_AUTORESETPHY_SHIFT
value|(28)
end_define

begin_define
define|#
directive|define
name|URTW_MAX_RX_DMA_MASK
value|((1<<8) | (1<<9) | (1<<10))
end_define

begin_define
define|#
directive|define
name|URTW_MAX_RX_DMA_2048
value|(7<< URTW_MAX_RX_DMA_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_MAX_RX_DMA_1024
value|(6)
end_define

begin_define
define|#
directive|define
name|URTW_MAX_RX_DMA_SHIFT
value|(10)
end_define

begin_define
define|#
directive|define
name|URTW_RCR_ONLYERLPKT
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|URTW_INT_TIMEOUT
value|0x0048
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_INT_TBDA
value|0x004c
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_EPROM_CMD
value|0x0050
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_EPROM_CMD_NORMAL
value|(0x0)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CMD_NORMAL_MODE
define|\
value|(URTW_EPROM_CMD_NORMAL<< URTW_EPROM_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CMD_LOAD
value|(0x1)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CMD_PROGRAM
value|(0x2)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CMD_PROGRAM_MODE
define|\
value|(URTW_EPROM_CMD_PROGRAM<< URTW_EPROM_CMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CMD_CONFIG
value|(0x3)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CMD_SHIFT
value|(6)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CMD_MASK
value|((1<< 7) | (1<< 6))
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_READBIT
value|(0x1)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_WRITEBIT
value|(0x2)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CK
value|(0x4)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CS
value|(0x8)
end_define

begin_define
define|#
directive|define
name|URTW_CONFIG0
value|0x0051
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CONFIG1
value|0x0052
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CONFIG2
value|0x0053
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_ANAPARAM
value|0x0054
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_8225_ANAPARAM_ON
value|(0xa0000a59)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ANAPARAM_OFF
value|(0xa00beb59)
end_define

begin_define
define|#
directive|define
name|URTW_8187B_8225_ANAPARAM_ON
value|(0x45090658)
end_define

begin_define
define|#
directive|define
name|URTW_8187B_8225_ANAPARAM_OFF
value|(0x55480658)
end_define

begin_define
define|#
directive|define
name|URTW_MSR
value|0x0058
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_MSR_LINK_MASK
value|((1<< 2) | (1<< 3))
end_define

begin_define
define|#
directive|define
name|URTW_MSR_LINK_SHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|URTW_MSR_LINK_NONE
value|(0<< URTW_MSR_LINK_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_MSR_LINK_ADHOC
value|(1<< URTW_MSR_LINK_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_MSR_LINK_STA
value|(2<< URTW_MSR_LINK_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_MSR_LINK_HOSTAP
value|(3<< URTW_MSR_LINK_SHIFT)
end_define

begin_define
define|#
directive|define
name|URTW_MSR_LINK_ENEDCA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|URTW_CONFIG3
value|0x0059
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CONFIG3_ANAPARAM_WRITE
value|(0x40)
end_define

begin_define
define|#
directive|define
name|URTW_CONFIG3_GNT_SELECT
value|(0x80)
end_define

begin_define
define|#
directive|define
name|URTW_CONFIG3_ANAPARAM_W_SHIFT
value|(6)
end_define

begin_define
define|#
directive|define
name|URTW_CONFIG4
value|0x005a
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CONFIG4_VCOOFF
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|URTW_TESTR
value|0x005b
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_PSR
value|0x005e
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_SECURITY
value|0x005f
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_ANAPARAM2
value|0x0060
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_8225_ANAPARAM2_ON
value|(0x860c7312)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ANAPARAM2_OFF
value|(0x840dec11)
end_define

begin_define
define|#
directive|define
name|URTW_8187B_8225_ANAPARAM2_ON
value|(0x727f3f52)
end_define

begin_define
define|#
directive|define
name|URTW_8187B_8225_ANAPARAM2_OFF
value|(0x72003f50)
end_define

begin_define
define|#
directive|define
name|URTW_BEACON_INTERVAL
value|0x0070
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_ATIM_WND
value|0x0072
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_BEACON_INTERVAL_TIME
value|0x0074
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_ATIM_TR_ITV
value|0x0076
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_PHY_DELAY
value|0x0078
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CARRIER_SCOUNT
value|0x0079
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_PHY_MAGIC1
value|0x007c
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_PHY_MAGIC2
value|0x007d
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_PHY_MAGIC3
value|0x007e
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_PHY_MAGIC4
value|0x007f
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RF_PINS_OUTPUT
value|0x0080
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RF_PINS_OUTPUT_MAGIC1
value|(0x3a0)
end_define

begin_define
define|#
directive|define
name|URTW_BB_HOST_BANG_CLK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|URTW_BB_HOST_BANG_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|URTW_BB_HOST_BANG_RW
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|URTW_RF_PINS_ENABLE
value|0x0082
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RF_PINS_SELECT
value|0x0084
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_ADDR_MAGIC1
value|0x0085
end_define

begin_comment
comment|/* broken?  */
end_comment

begin_define
define|#
directive|define
name|URTW_RF_PINS_INPUT
value|0x0086
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RF_PINS_MAGIC1
value|(0xfff3)
end_define

begin_define
define|#
directive|define
name|URTW_RF_PINS_MAGIC2
value|(0xfff0)
end_define

begin_define
define|#
directive|define
name|URTW_RF_PINS_MAGIC3
value|(0x0007)
end_define

begin_define
define|#
directive|define
name|URTW_RF_PINS_MAGIC4
value|(0xf)
end_define

begin_define
define|#
directive|define
name|URTW_RF_PINS_MAGIC5
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|URTW_RF_PARA
value|0x0088
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RF_TIMING
value|0x008c
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_GP_ENABLE
value|0x0090
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_GP_ENABLE_DATA_MAGIC1
value|(0x1)
end_define

begin_define
define|#
directive|define
name|URTW_GPIO
value|0x0091
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_GPIO_DATA_MAGIC1
value|(0x1)
end_define

begin_define
define|#
directive|define
name|URTW_HSSI_PARA
value|0x0094
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TX_AGC_CTL
value|0x009c
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TX_AGC_CTL_PERPACKET_GAIN
value|(0x1)
end_define

begin_define
define|#
directive|define
name|URTW_TX_AGC_CTL_PERPACKET_ANTSEL
value|(0x2)
end_define

begin_define
define|#
directive|define
name|URTW_TX_AGC_CTL_FEEDBACK_ANT
value|(0x4)
end_define

begin_define
define|#
directive|define
name|URTW_TX_GAIN_CCK
value|0x009d
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TX_GAIN_OFDM
value|0x009e
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TX_ANTENNA
value|0x009f
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_WPA_CONFIG
value|0x00b0
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_SIFS
value|0x00b4
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_DIFS
value|0x00b5
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_SLOT
value|0x00b6
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CW_CONF
value|0x00bc
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CW_CONF_PERPACKET_RETRY
value|(0x2)
end_define

begin_define
define|#
directive|define
name|URTW_CW_CONF_PERPACKET_CW
value|(0x1)
end_define

begin_define
define|#
directive|define
name|URTW_CW_VAL
value|0x00bd
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RATE_FALLBACK
value|0x00be
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RATE_FALLBACK_ENABLE
value|(0x80)
end_define

begin_define
define|#
directive|define
name|URTW_ACM_CONTROL
value|0x00bf
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CONFIG5
value|0x00d8
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TXDMA_POLLING
value|0x00d9
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_CWR
value|0x00dc
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RETRY_CTR
value|0x00de
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_INT_MIG
value|0x00e2
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_RDSAR
value|0x00e4
end_define

begin_comment
comment|/* 4 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TID_AC_MAP
value|0x00e8
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_ANAPARAM3
value|0x00ee
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_8187B_8225_ANAPARAM3_ON
value|(0x0)
end_define

begin_define
define|#
directive|define
name|URTW_8187B_8225_ANAPARAM3_OFF
value|(0x0)
end_define

begin_define
define|#
directive|define
name|URTW_8187B_AC_VO
value|0x00f0
end_define

begin_comment
comment|/* 4 byte for 8187B  */
end_comment

begin_define
define|#
directive|define
name|URTW_FEMR
value|0x00f4
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_8187B_AC_VI
value|0x00f4
end_define

begin_comment
comment|/* 4 byte for 8187B  */
end_comment

begin_define
define|#
directive|define
name|URTW_8187B_AC_BE
value|0x00f8
end_define

begin_comment
comment|/* 4 byte for 8187B  */
end_comment

begin_define
define|#
directive|define
name|URTW_TALLY_CNT
value|0x00fa
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_TALLY_SEL
value|0x00fc
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_8187B_AC_BK
value|0x00fc
end_define

begin_comment
comment|/* 4 byte for 8187B  */
end_comment

begin_define
define|#
directive|define
name|URTW_ADDR_MAGIC2
value|0x00fe
end_define

begin_comment
comment|/* 2 byte  */
end_comment

begin_define
define|#
directive|define
name|URTW_ADDR_MAGIC3
value|0x00ff
end_define

begin_comment
comment|/* 1 byte  */
end_comment

begin_comment
comment|/* for 8225  */
end_comment

begin_define
define|#
directive|define
name|URTW_8225_ADDR_0_MAGIC
value|0x0
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_0_DATA_MAGIC1
value|(0x1b7)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_0_DATA_MAGIC2
value|(0x0b7)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_0_DATA_MAGIC3
value|(0x127)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_0_DATA_MAGIC4
value|(0x027)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_0_DATA_MAGIC5
value|(0x22f)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_0_DATA_MAGIC6
value|(0x2bf)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_1_MAGIC
value|0x1
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_2_MAGIC
value|0x2
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_2_DATA_MAGIC1
value|(0xc4d)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_2_DATA_MAGIC2
value|(0x44d)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_3_MAGIC
value|0x3
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_3_DATA_MAGIC1
value|(0x2)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_5_MAGIC
value|0x5
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_5_DATA_MAGIC1
value|(0x4)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_6_MAGIC
value|0x6
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_6_DATA_MAGIC1
value|(0xe6)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_6_DATA_MAGIC2
value|(0x80)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_7_MAGIC
value|0x7
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_8_MAGIC
value|0x8
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_8_DATA_MAGIC1
value|(0x588)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_9_MAGIC
value|0x9
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_9_DATA_MAGIC1
value|(0x700)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_C_MAGIC
value|0xc
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_C_DATA_MAGIC1
value|(0x850)
end_define

begin_define
define|#
directive|define
name|URTW_8225_ADDR_C_DATA_MAGIC2
value|(0x050)
end_define

begin_comment
comment|/* for EEPROM  */
end_comment

begin_define
define|#
directive|define
name|URTW_EPROM_CHANPLAN
value|0x03
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_TXPW_BASE
value|0x05
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_RFCHIPID
value|0x06
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_RFCHIPID_RTL8225U
value|(5)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_RFCHIPID_RTL8225Z2
value|(6)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_MACADDR
value|0x07
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_TXPW0
value|0x16
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_TXPW2
value|0x1b
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_TXPW1
value|0x3d
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_SWREV
value|0x3f
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CID_MASK
value|(0xff)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CID_RSVD0
value|(0x00)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CID_RSVD1
value|(0xff)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CID_ALPHA0
value|(0x01)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CID_SERCOMM_PS
value|(0x02)
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_CID_HW_LED
value|(0x03)
end_define

begin_comment
comment|/* LED  */
end_comment

begin_define
define|#
directive|define
name|URTW_CID_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|URTW_CID_8187_ALPHA0
value|1
end_define

begin_define
define|#
directive|define
name|URTW_CID_8187_SERCOMM_PS
value|2
end_define

begin_define
define|#
directive|define
name|URTW_CID_8187_HW_LED
value|3
end_define

begin_define
define|#
directive|define
name|URTW_SW_LED_MODE0
value|0
end_define

begin_define
define|#
directive|define
name|URTW_SW_LED_MODE1
value|1
end_define

begin_define
define|#
directive|define
name|URTW_SW_LED_MODE2
value|2
end_define

begin_define
define|#
directive|define
name|URTW_SW_LED_MODE3
value|3
end_define

begin_define
define|#
directive|define
name|URTW_HW_LED
value|4
end_define

begin_define
define|#
directive|define
name|URTW_LED_CTL_POWER_ON
value|0
end_define

begin_define
define|#
directive|define
name|URTW_LED_CTL_LINK
value|2
end_define

begin_define
define|#
directive|define
name|URTW_LED_CTL_TX
value|4
end_define

begin_define
define|#
directive|define
name|URTW_LED_PIN_GPIO0
value|0
end_define

begin_define
define|#
directive|define
name|URTW_LED_PIN_LED0
value|1
end_define

begin_define
define|#
directive|define
name|URTW_LED_PIN_LED1
value|2
end_define

begin_define
define|#
directive|define
name|URTW_LED_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|URTW_LED_ON
value|1
end_define

begin_define
define|#
directive|define
name|URTW_LED_OFF
value|2
end_define

begin_define
define|#
directive|define
name|URTW_LED_BLINK_NORMAL
value|3
end_define

begin_define
define|#
directive|define
name|URTW_LED_BLINK_SLOWLY
value|4
end_define

begin_define
define|#
directive|define
name|URTW_LED_POWER_ON_BLINK
value|5
end_define

begin_define
define|#
directive|define
name|URTW_LED_SCAN_BLINK
value|6
end_define

begin_define
define|#
directive|define
name|URTW_LED_NO_LINK_BLINK
value|7
end_define

begin_define
define|#
directive|define
name|URTW_LED_BLINK_CM3
value|8
end_define

begin_comment
comment|/* for extra area  */
end_comment

begin_define
define|#
directive|define
name|URTW_EPROM_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|URTW_EPROM_DELAY
value|10
end_define

begin_define
define|#
directive|define
name|URTW_8187_GETREGS_REQ
value|5
end_define

begin_define
define|#
directive|define
name|URTW_8187_SETREGS_REQ
value|5
end_define

begin_define
define|#
directive|define
name|URTW_8225_RF_MAX_SENS
value|6
end_define

begin_define
define|#
directive|define
name|URTW_8225_RF_DEF_SENS
value|4
end_define

begin_define
define|#
directive|define
name|URTW_DEFAULT_RTS_RETRY
value|7
end_define

begin_define
define|#
directive|define
name|URTW_DEFAULT_TX_RETRY
value|7
end_define

begin_define
define|#
directive|define
name|URTW_DEFAULT_RTS_THRESHOLD
value|2342U
end_define

begin_define
define|#
directive|define
name|URTW_ASIFS_TIME
value|10
end_define

begin_define
define|#
directive|define
name|URTW_ACKCTS_LEN
value|14
end_define

begin_comment
comment|/* len for ACK and CTS */
end_comment

begin_struct
struct|struct
name|urtw_8187b_rxhdr
block|{
name|uint32_t
name|flag
decl_stmt|;
define|#
directive|define
name|URTW_RX_FLAG_LEN
comment|/*  0 ~ 11 bits */
define|#
directive|define
name|URTW_RX_FLAG_ICV_ERR
value|(1<< 12)
define|#
directive|define
name|URTW_RX_FLAG_CRC32_ERR
value|(1<< 13)
define|#
directive|define
name|URTW_RX_FLAG_PM
value|(1<< 14)
define|#
directive|define
name|URTW_RX_FLAG_RX_ERR
value|(1<< 15)
define|#
directive|define
name|URTW_RX_FLAG_BCAST
value|(1<< 16)
define|#
directive|define
name|URTW_RX_FLAG_PAM
value|(1<< 17)
define|#
directive|define
name|URTW_RX_FLAG_MCAST
value|(1<< 18)
define|#
directive|define
name|URTW_RX_FLAG_QOS
value|(1<< 19)
comment|/* only for RTL8187B */
define|#
directive|define
name|URTW_RX_FLAG_RXRATE
comment|/* 20 ~ 23 bits */
define|#
directive|define
name|URTW_RX_FLAG_RXRATE_SHIFT
value|20
define|#
directive|define
name|URTW_RX_FLAG_TRSW
value|(1<< 24)
comment|/* only for RTL8187B */
define|#
directive|define
name|URTW_RX_FLAG_SPLCP
value|(1<< 25)
define|#
directive|define
name|URTW_RX_FLAG_FOF
value|(1<< 26)
define|#
directive|define
name|URTW_RX_FLAG_DMA_FAIL
value|(1<< 27)
define|#
directive|define
name|URTW_RX_FLAG_LAST
value|(1<< 28)
define|#
directive|define
name|URTW_RX_FLAG_FIRST
value|(1<< 29)
define|#
directive|define
name|URTW_RX_FLAG_EOR
value|(1<< 30)
define|#
directive|define
name|URTW_RX_FLAG_OWN
value|(1<< 31)
name|uint64_t
name|mactime
decl_stmt|;
name|uint8_t
name|noise
decl_stmt|;
name|uint8_t
name|rssi
decl_stmt|;
define|#
directive|define
name|URTW_RX_RSSI
comment|/*  0 ~  6 bits */
define|#
directive|define
name|URTW_RX_RSSI_MASK
value|0x3f
define|#
directive|define
name|URTW_RX_ANTENNA
value|(1<< 7)
name|uint8_t
name|agc
decl_stmt|;
name|uint8_t
name|flag2
decl_stmt|;
define|#
directive|define
name|URTW_RX_FLAG2_DECRYPTED
value|(1<< 0)
define|#
directive|define
name|URTW_RX_FLAG2_WAKUP
value|(1<< 1)
define|#
directive|define
name|URTW_RX_FLAG2_SHIFT
value|(1<< 2)
define|#
directive|define
name|URTW_RX_FLAG2_RSVD0
comment|/*  3 ~  7 bits */
name|uint16_t
name|flag3
decl_stmt|;
define|#
directive|define
name|URTW_RX_FLAG3_NUMMCSI
comment|/*  0 ~  3 bits */
define|#
directive|define
name|URTW_RX_FLAG3_SNR_L2E
comment|/*  4 ~  9 bits */
define|#
directive|define
name|URTW_RX_FLAG3_CFO_BIAS
comment|/* 10 ~ 15 bits */
name|int8_t
name|pwdb
decl_stmt|;
name|uint8_t
name|fot
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|urtw_8187b_txhdr
block|{
name|uint32_t
name|flag
decl_stmt|;
define|#
directive|define
name|URTW_TX_FLAG_PKTLEN
comment|/*  0 ~ 11 bits */
define|#
directive|define
name|URTW_TX_FLAG_RSVD0
comment|/* 12 ~ 14 bits */
define|#
directive|define
name|URTW_TX_FLAG_NO_ENC
value|(1<< 15)
define|#
directive|define
name|URTW_TX_FLAG_SPLCP
value|(1<< 16)
define|#
directive|define
name|URTW_TX_FLAG_MOREFRAG
value|(1<< 17)
define|#
directive|define
name|URTW_TX_FLAG_CTS
value|(1<< 18)
define|#
directive|define
name|URTW_TX_FLAG_RTSRATE
comment|/* 19 ~ 22 bits */
define|#
directive|define
name|URTW_TX_FLAG_RTSRATE_SHIFT
value|19
define|#
directive|define
name|URTW_TX_FLAG_RTS
value|(1<< 23)
define|#
directive|define
name|URTW_TX_FLAG_TXRATE
comment|/* 24 ~ 27 bits */
define|#
directive|define
name|URTW_TX_FLAG_TXRATE_SHIFT
value|24
define|#
directive|define
name|URTW_TX_FLAG_LAST
value|(1<< 28)
define|#
directive|define
name|URTW_TX_FLAG_FIRST
value|(1<< 29)
define|#
directive|define
name|URTW_TX_FLAG_DMA
value|(1<< 30)
define|#
directive|define
name|URTW_TX_FLAG_OWN
value|(1<< 31)
name|uint16_t
name|rtsdur
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
define|#
directive|define
name|URTW_TX_LEN
comment|/*  0 ~ 14 bits */
define|#
directive|define
name|URTW_TX_LEN_EXT
value|(1<< 15)
name|uint32_t
name|bufaddr
decl_stmt|;
name|uint16_t
name|flag1
decl_stmt|;
define|#
directive|define
name|URTW_TX_FLAG1_RXLEN
comment|/*  0 ~ 11 bits */
define|#
directive|define
name|URTW_TX_FLAG1_RSVD0
comment|/* 12 ~ 14 bits */
define|#
directive|define
name|URTW_TX_FLAG1_MICCAL
value|(1<< 15)
name|uint16_t
name|txdur
decl_stmt|;
name|uint32_t
name|nextdescaddr
decl_stmt|;
name|uint8_t
name|rtsagc
decl_stmt|;
name|uint8_t
name|retry
decl_stmt|;
name|uint16_t
name|flag2
decl_stmt|;
define|#
directive|define
name|URTW_TX_FLAG2_RTDB
value|(1<< 0)
define|#
directive|define
name|URTW_TX_FLAG2_NOACM
value|(1<< 1)
define|#
directive|define
name|URTW_TX_FLAG2_PIFS
value|(1<< 2)
define|#
directive|define
name|URTW_TX_FLAG2_RSVD0
comment|/*  3 ~  6 bits */
define|#
directive|define
name|URTW_TX_FLAG2_RTSRATEFALLBACK
comment|/*  7 ~ 10 bits */
define|#
directive|define
name|URTW_TX_FLAG2_RATEFALLBACK
comment|/* 11 ~ 15 bits */
name|uint16_t
name|delaybound
decl_stmt|;
name|uint16_t
name|flag3
decl_stmt|;
define|#
directive|define
name|URTW_TX_FLAG3_RSVD0
comment|/*  0 ~  3 bits */
define|#
directive|define
name|URTW_TX_FLAG3_AGC
comment|/*  4 ~ 11 bits */
define|#
directive|define
name|URTW_TX_FLAG3_ANTENNA
value|(1<< 12)
define|#
directive|define
name|URTW_TX_FLAG3_SPC
comment|/* 13 ~ 14 bits */
define|#
directive|define
name|URTW_TX_FLAG3_RSVD1
value|(1<< 15)
name|uint32_t
name|flag4
decl_stmt|;
define|#
directive|define
name|URTW_TX_FLAG4_LENADJUST
comment|/*  0 ~  1 bits */
define|#
directive|define
name|URTW_TX_FLAG4_RSVD0
value|(1<< 2)
define|#
directive|define
name|URTW_TX_FLAG4_TPCDESEN
value|(1<< 3)
define|#
directive|define
name|URTW_TX_FLAG4_TPCPOLARITY
comment|/*  4 ~  5 bits */
define|#
directive|define
name|URTW_TX_FLAG4_TPCEN
value|(1<< 6)
define|#
directive|define
name|URTW_TX_FLAG4_PTEN
value|(1<< 7)
define|#
directive|define
name|URTW_TX_FLAG4_BCKEY
comment|/*  8 ~ 13 bits */
define|#
directive|define
name|URTW_TX_FLAG4_ENBCKEY
value|(1<< 14)
define|#
directive|define
name|URTW_TX_FLAG4_ENPMPD
value|(1<< 15)
define|#
directive|define
name|URTW_TX_FLAG4_FRAGQSZ
comment|/* 16 ~ 31 bits */
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|urtw_8187l_rxhdr
block|{
name|uint32_t
name|flag
decl_stmt|;
name|uint8_t
name|noise
decl_stmt|;
name|uint8_t
name|rssi
decl_stmt|;
define|#
directive|define
name|URTW_RX_8187L_RSSI
comment|/*  0 ~  6 bits */
define|#
directive|define
name|URTW_RX_8187L_RSSI_MASK
value|0x3f
define|#
directive|define
name|URTW_RX_8187L_ANTENNA
value|(1<< 7)
name|uint8_t
name|agc
decl_stmt|;
name|uint8_t
name|flag2
decl_stmt|;
define|#
directive|define
name|URTW_RX_8187L_DECRYPTED
value|(1<< 0)
define|#
directive|define
name|URTW_RX_8187L_WAKEUP
value|(1<< 1)
define|#
directive|define
name|URTW_RX_8187L_SHIFT
value|(1<< 2)
define|#
directive|define
name|URTW_RX_8187L_RSVD0
comment|/*  3 ~ 7 bits */
name|uint64_t
name|mactime
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|urtw_8187l_txhdr
block|{
name|uint32_t
name|flag
decl_stmt|;
name|uint16_t
name|rtsdur
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint32_t
name|retry
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

end_unit

