begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2006 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5211REG_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5211REG_H
end_define

begin_comment
comment|/*  * Definitions for the Atheros AR5211/5311 chipset.  */
end_comment

begin_comment
comment|/*  * Maui2/Spirit specific registers/fields are indicated by AR5311.  * Oahu specific registers/fields are indicated by AR5211.  */
end_comment

begin_comment
comment|/* DMA Control and Interrupt Registers */
end_comment

begin_define
define|#
directive|define
name|AR_CR
value|0x0008
end_define

begin_comment
comment|/* control register */
end_comment

begin_define
define|#
directive|define
name|AR_RXDP
value|0x000C
end_define

begin_comment
comment|/* receive queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_CFG
value|0x0014
end_define

begin_comment
comment|/* configuration and status register */
end_comment

begin_define
define|#
directive|define
name|AR_IER
value|0x0024
end_define

begin_comment
comment|/* Interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|AR_RTSD0
value|0x0028
end_define

begin_comment
comment|/* RTS Duration Parameters 0 */
end_comment

begin_define
define|#
directive|define
name|AR_RTSD1
value|0x002c
end_define

begin_comment
comment|/* RTS Duration Parameters 1 */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG
value|0x0030
end_define

begin_comment
comment|/* tx DMA size config register */
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG
value|0x0034
end_define

begin_comment
comment|/* rx DMA size config register */
end_comment

begin_define
define|#
directive|define
name|AR5211_JUMBO_LAST
value|0x0038
end_define

begin_comment
comment|/* Jumbo descriptor last address */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC
value|0x0040
end_define

begin_comment
comment|/* MIB control register */
end_comment

begin_define
define|#
directive|define
name|AR_TOPS
value|0x0044
end_define

begin_comment
comment|/* timeout prescale count */
end_comment

begin_define
define|#
directive|define
name|AR_RXNPTO
value|0x0048
end_define

begin_comment
comment|/* no frame received timeout */
end_comment

begin_define
define|#
directive|define
name|AR_TXNPTO
value|0x004C
end_define

begin_comment
comment|/* no frame trasmitted timeout */
end_comment

begin_define
define|#
directive|define
name|AR_RFGTO
value|0x0050
end_define

begin_comment
comment|/* receive frame gap timeout */
end_comment

begin_define
define|#
directive|define
name|AR_RFCNT
value|0x0054
end_define

begin_comment
comment|/* receive frame count limit */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC
value|0x0058
end_define

begin_comment
comment|/* miscellaneous control/status */
end_comment

begin_define
define|#
directive|define
name|AR5311_QDCLKGATE
value|0x005c
end_define

begin_comment
comment|/* QCU/DCU clock gating control */
end_comment

begin_define
define|#
directive|define
name|AR_ISR
value|0x0080
end_define

begin_comment
comment|/* Primary interrupt status register */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S0
value|0x0084
end_define

begin_comment
comment|/* Secondary interrupt status reg 0 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1
value|0x0088
end_define

begin_comment
comment|/* Secondary interrupt status reg 1 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2
value|0x008c
end_define

begin_comment
comment|/* Secondary interrupt status reg 2 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S3
value|0x0090
end_define

begin_comment
comment|/* Secondary interrupt status reg 3 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S4
value|0x0094
end_define

begin_comment
comment|/* Secondary interrupt status reg 4 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR
value|0x00a0
end_define

begin_comment
comment|/* Primary interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S0
value|0x00a4
end_define

begin_comment
comment|/* Secondary interrupt mask reg 0 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S1
value|0x00a8
end_define

begin_comment
comment|/* Secondary interrupt mask reg 1 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2
value|0x00ac
end_define

begin_comment
comment|/* Secondary interrupt mask reg 2 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S3
value|0x00b0
end_define

begin_comment
comment|/* Secondary interrupt mask reg 3 */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S4
value|0x00b4
end_define

begin_comment
comment|/* Secondary interrupt mask reg 4 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RAC
value|0x00c0
end_define

begin_comment
comment|/* Primary interrupt status reg, */
end_comment

begin_comment
comment|/* Shadow copies with read-and-clear access */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S0_S
value|0x00c4
end_define

begin_comment
comment|/* Secondary interrupt status reg 0 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_S
value|0x00c8
end_define

begin_comment
comment|/* Secondary interrupt status reg 1 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_S
value|0x00cc
end_define

begin_comment
comment|/* Secondary interrupt status reg 2 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S3_S
value|0x00d0
end_define

begin_comment
comment|/* Secondary interrupt status reg 3 */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S4_S
value|0x00d4
end_define

begin_comment
comment|/* Secondary interrupt status reg 4 */
end_comment

begin_define
define|#
directive|define
name|AR_Q0_TXDP
value|0x0800
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q1_TXDP
value|0x0804
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q2_TXDP
value|0x0808
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q3_TXDP
value|0x080c
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q4_TXDP
value|0x0810
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q5_TXDP
value|0x0814
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q6_TXDP
value|0x0818
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q7_TXDP
value|0x081c
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q8_TXDP
value|0x0820
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_Q9_TXDP
value|0x0824
end_define

begin_comment
comment|/* Transmit Queue descriptor pointer */
end_comment

begin_define
define|#
directive|define
name|AR_QTXDP
parameter_list|(
name|i
parameter_list|)
value|(AR_Q0_TXDP + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q_TXE
value|0x0840
end_define

begin_comment
comment|/* Transmit Queue enable */
end_comment

begin_define
define|#
directive|define
name|AR_Q_TXD
value|0x0880
end_define

begin_comment
comment|/* Transmit Queue disable */
end_comment

begin_define
define|#
directive|define
name|AR_Q0_CBRCFG
value|0x08c0
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q1_CBRCFG
value|0x08c4
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q2_CBRCFG
value|0x08c8
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q3_CBRCFG
value|0x08cc
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q4_CBRCFG
value|0x08d0
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q5_CBRCFG
value|0x08d4
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q6_CBRCFG
value|0x08d8
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q7_CBRCFG
value|0x08dc
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q8_CBRCFG
value|0x08e0
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q9_CBRCFG
value|0x08e4
end_define

begin_comment
comment|/* CBR configuration */
end_comment

begin_define
define|#
directive|define
name|AR_QCBRCFG
parameter_list|(
name|i
parameter_list|)
value|(AR_Q0_CBRCFG + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q0_RDYTIMECFG
value|0x0900
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q1_RDYTIMECFG
value|0x0904
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q2_RDYTIMECFG
value|0x0908
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q3_RDYTIMECFG
value|0x090c
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q4_RDYTIMECFG
value|0x0910
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q5_RDYTIMECFG
value|0x0914
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q6_RDYTIMECFG
value|0x0918
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q7_RDYTIMECFG
value|0x091c
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q8_RDYTIMECFG
value|0x0920
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_Q9_RDYTIMECFG
value|0x0924
end_define

begin_comment
comment|/* ReadyTime configuration */
end_comment

begin_define
define|#
directive|define
name|AR_QRDYTIMECFG
parameter_list|(
name|i
parameter_list|)
value|(AR_Q0_RDYTIMECFG + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_SC
value|0x0940
end_define

begin_comment
comment|/* OneShotArm set control */
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_CC
value|0x0980
end_define

begin_comment
comment|/* OneShotArm clear control */
end_comment

begin_define
define|#
directive|define
name|AR_Q0_MISC
value|0x09c0
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q1_MISC
value|0x09c4
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q2_MISC
value|0x09c8
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q3_MISC
value|0x09cc
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q4_MISC
value|0x09d0
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q5_MISC
value|0x09d4
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q6_MISC
value|0x09d8
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q7_MISC
value|0x09dc
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q8_MISC
value|0x09e0
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_Q9_MISC
value|0x09e4
end_define

begin_comment
comment|/* Miscellaneous QCU settings */
end_comment

begin_define
define|#
directive|define
name|AR_QMISC
parameter_list|(
name|i
parameter_list|)
value|(AR_Q0_MISC + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q0_STS
value|0x0a00
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q1_STS
value|0x0a04
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q2_STS
value|0x0a08
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q3_STS
value|0x0a0c
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q4_STS
value|0x0a10
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q5_STS
value|0x0a14
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q6_STS
value|0x0a18
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q7_STS
value|0x0a1c
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q8_STS
value|0x0a20
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_Q9_STS
value|0x0a24
end_define

begin_comment
comment|/* Miscellaneous QCU status */
end_comment

begin_define
define|#
directive|define
name|AR_QSTS
parameter_list|(
name|i
parameter_list|)
value|(AR_Q0_STS + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_Q_RDYTIMESHDN
value|0x0a40
end_define

begin_comment
comment|/* ReadyTimeShutdown status */
end_comment

begin_define
define|#
directive|define
name|AR_D0_QCUMASK
value|0x1000
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D1_QCUMASK
value|0x1004
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D2_QCUMASK
value|0x1008
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D3_QCUMASK
value|0x100c
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D4_QCUMASK
value|0x1010
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D5_QCUMASK
value|0x1014
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D6_QCUMASK
value|0x1018
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D7_QCUMASK
value|0x101c
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D8_QCUMASK
value|0x1020
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_D9_QCUMASK
value|0x1024
end_define

begin_comment
comment|/* QCU Mask */
end_comment

begin_define
define|#
directive|define
name|AR_DQCUMASK
parameter_list|(
name|i
parameter_list|)
value|(AR_D0_QCUMASK + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D0_LCL_IFS
value|0x1040
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D1_LCL_IFS
value|0x1044
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D2_LCL_IFS
value|0x1048
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D3_LCL_IFS
value|0x104c
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D4_LCL_IFS
value|0x1050
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D5_LCL_IFS
value|0x1054
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D6_LCL_IFS
value|0x1058
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D7_LCL_IFS
value|0x105c
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D8_LCL_IFS
value|0x1060
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D9_LCL_IFS
value|0x1064
end_define

begin_comment
comment|/* DCU-specific IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_DLCL_IFS
parameter_list|(
name|i
parameter_list|)
value|(AR_D0_LCL_IFS + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D0_RETRY_LIMIT
value|0x1080
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D1_RETRY_LIMIT
value|0x1084
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D2_RETRY_LIMIT
value|0x1088
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D3_RETRY_LIMIT
value|0x108c
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D4_RETRY_LIMIT
value|0x1090
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D5_RETRY_LIMIT
value|0x1094
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D6_RETRY_LIMIT
value|0x1098
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D7_RETRY_LIMIT
value|0x109c
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D8_RETRY_LIMIT
value|0x10a0
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_D9_RETRY_LIMIT
value|0x10a4
end_define

begin_comment
comment|/* Retry limits */
end_comment

begin_define
define|#
directive|define
name|AR_DRETRY_LIMIT
parameter_list|(
name|i
parameter_list|)
value|(AR_D0_RETRY_LIMIT + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D0_CHNTIME
value|0x10c0
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D1_CHNTIME
value|0x10c4
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D2_CHNTIME
value|0x10c8
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D3_CHNTIME
value|0x10cc
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D4_CHNTIME
value|0x10d0
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D5_CHNTIME
value|0x10d4
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D6_CHNTIME
value|0x10d8
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D7_CHNTIME
value|0x10dc
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D8_CHNTIME
value|0x10e0
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_D9_CHNTIME
value|0x10e4
end_define

begin_comment
comment|/* ChannelTime settings */
end_comment

begin_define
define|#
directive|define
name|AR_DCHNTIME
parameter_list|(
name|i
parameter_list|)
value|(AR_D0_CHNTIME + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D0_MISC
value|0x1100
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D1_MISC
value|0x1104
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D2_MISC
value|0x1108
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D3_MISC
value|0x110c
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D4_MISC
value|0x1110
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D5_MISC
value|0x1114
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D6_MISC
value|0x1118
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D7_MISC
value|0x111c
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D8_MISC
value|0x1120
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_D9_MISC
value|0x1124
end_define

begin_comment
comment|/* Misc DCU-specific settings */
end_comment

begin_define
define|#
directive|define
name|AR_DMISC
parameter_list|(
name|i
parameter_list|)
value|(AR_D0_MISC + ((i)<<2))
end_define

begin_define
define|#
directive|define
name|AR_D0_SEQNUM
value|0x1140
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D1_SEQNUM
value|0x1144
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D2_SEQNUM
value|0x1148
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D3_SEQNUM
value|0x114c
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D4_SEQNUM
value|0x1150
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D5_SEQNUM
value|0x1154
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D6_SEQNUM
value|0x1158
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D7_SEQNUM
value|0x115c
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D8_SEQNUM
value|0x1160
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D9_SEQNUM
value|0x1164
end_define

begin_comment
comment|/* Frame seqnum control/status */
end_comment

begin_define
define|#
directive|define
name|AR_DSEQNUM
parameter_list|(
name|i
parameter_list|)
value|(AR_D0_SEQNUM + ((i<<2)))
end_define

begin_comment
comment|/* MAC DCU-global IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_SIFS
value|0x1030
end_define

begin_comment
comment|/* DCU global SIFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_SLOT
value|0x1070
end_define

begin_comment
comment|/* DC global slot interval */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_EIFS
value|0x10b0
end_define

begin_comment
comment|/* DCU global EIFS setting */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC
value|0x10f0
end_define

begin_comment
comment|/* DCU global misc. IFS settings */
end_comment

begin_define
define|#
directive|define
name|AR_D_FPCTL
value|0x1230
end_define

begin_comment
comment|/* DCU frame prefetch settings */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE
value|0x1270
end_define

begin_comment
comment|/* DCU transmit pause control/status */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXBLK_CMD
value|0x1038
end_define

begin_comment
comment|/* DCU transmit filter cmd (w/only) */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXBLK_DATA
parameter_list|(
name|i
parameter_list|)
value|(AR_D_TXBLK_CMD+(i))
end_define

begin_comment
comment|/* DCU transmit filter data */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXBLK_CLR
value|0x143c
end_define

begin_comment
comment|/* DCU clear tx filter (w/only) */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXBLK_SET
value|0x147c
end_define

begin_comment
comment|/* DCU set tx filter (w/only) */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE
value|0x1270
end_define

begin_comment
comment|/* DCU transmit pause control/status */
end_comment

begin_define
define|#
directive|define
name|AR_RC
value|0x4000
end_define

begin_comment
comment|/* Warm reset control register */
end_comment

begin_define
define|#
directive|define
name|AR_SCR
value|0x4004
end_define

begin_comment
comment|/* Sleep control register */
end_comment

begin_define
define|#
directive|define
name|AR_INTPEND
value|0x4008
end_define

begin_comment
comment|/* Interrupt Pending register */
end_comment

begin_define
define|#
directive|define
name|AR_SFR
value|0x400C
end_define

begin_comment
comment|/* Sleep force register */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG
value|0x4010
end_define

begin_comment
comment|/* PCI configuration register */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR
value|0x4014
end_define

begin_comment
comment|/* GPIO control register */
end_comment

begin_define
define|#
directive|define
name|AR_GPIODO
value|0x4018
end_define

begin_comment
comment|/* GPIO data output access register */
end_comment

begin_define
define|#
directive|define
name|AR_GPIODI
value|0x401C
end_define

begin_comment
comment|/* GPIO data input access register */
end_comment

begin_define
define|#
directive|define
name|AR_SREV
value|0x4020
end_define

begin_comment
comment|/* Silicon Revision register */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_ADDR
value|0x6000
end_define

begin_comment
comment|/* EEPROM address register (10 bit) */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_DATA
value|0x6004
end_define

begin_comment
comment|/* EEPROM data register (16 bit) */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CMD
value|0x6008
end_define

begin_comment
comment|/* EEPROM command register */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_STS
value|0x600c
end_define

begin_comment
comment|/* EEPROM status register */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CFG
value|0x6010
end_define

begin_comment
comment|/* EEPROM configuration register */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID0
value|0x8000
end_define

begin_comment
comment|/* station ID0 - low 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1
value|0x8004
end_define

begin_comment
comment|/* station ID1 - upper 16 bits */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID0
value|0x8008
end_define

begin_comment
comment|/* BSSID low 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID1
value|0x800C
end_define

begin_comment
comment|/* BSSID upper 16 bits / AID */
end_comment

begin_define
define|#
directive|define
name|AR_SLOT_TIME
value|0x8010
end_define

begin_comment
comment|/* Time-out after a collision */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT
value|0x8014
end_define

begin_comment
comment|/* ACK& CTS time-out */
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR
value|0x8018
end_define

begin_comment
comment|/* RSSI warning& missed beacon threshold */
end_comment

begin_define
define|#
directive|define
name|AR_USEC
value|0x801c
end_define

begin_comment
comment|/* transmit latency register */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON
value|0x8020
end_define

begin_comment
comment|/* beacon control value/mode bits */
end_comment

begin_define
define|#
directive|define
name|AR_CFP_PERIOD
value|0x8024
end_define

begin_comment
comment|/* CFP Interval (TU/msec) */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER0
value|0x8028
end_define

begin_comment
comment|/* Next beacon time (TU/msec) */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER1
value|0x802c
end_define

begin_comment
comment|/* DMA beacon alert time (1/8 TU) */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER2
value|0x8030
end_define

begin_comment
comment|/* Software beacon alert (1/8 TU) */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER3
value|0x8034
end_define

begin_comment
comment|/* ATIM window time */
end_comment

begin_define
define|#
directive|define
name|AR_CFP_DUR
value|0x8038
end_define

begin_comment
comment|/* maximum CFP duration in TU */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER
value|0x803C
end_define

begin_comment
comment|/* receive filter register */
end_comment

begin_define
define|#
directive|define
name|AR_MCAST_FIL0
value|0x8040
end_define

begin_comment
comment|/* multicast filter lower 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_MCAST_FIL1
value|0x8044
end_define

begin_comment
comment|/* multicast filter upper 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW
value|0x8048
end_define

begin_comment
comment|/* PCU control register */
end_comment

begin_define
define|#
directive|define
name|AR_TSF_L32
value|0x804c
end_define

begin_comment
comment|/* local clock lower 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_TSF_U32
value|0x8050
end_define

begin_comment
comment|/* local clock upper 32 bits */
end_comment

begin_define
define|#
directive|define
name|AR_TST_ADDAC
value|0x8054
end_define

begin_comment
comment|/* ADDAC test register */
end_comment

begin_define
define|#
directive|define
name|AR_DEF_ANTENNA
value|0x8058
end_define

begin_comment
comment|/* default antenna register */
end_comment

begin_define
define|#
directive|define
name|AR_LAST_TSTP
value|0x8080
end_define

begin_comment
comment|/* Time stamp of the last beacon rcvd */
end_comment

begin_define
define|#
directive|define
name|AR_NAV
value|0x8084
end_define

begin_comment
comment|/* current NAV value */
end_comment

begin_define
define|#
directive|define
name|AR_RTS_OK
value|0x8088
end_define

begin_comment
comment|/* RTS exchange success counter */
end_comment

begin_define
define|#
directive|define
name|AR_RTS_FAIL
value|0x808c
end_define

begin_comment
comment|/* RTS exchange failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_ACK_FAIL
value|0x8090
end_define

begin_comment
comment|/* ACK failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_FCS_FAIL
value|0x8094
end_define

begin_comment
comment|/* FCS check failure counter */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_CNT
value|0x8098
end_define

begin_comment
comment|/* Valid beacon counter */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_0
value|0x8800
end_define

begin_comment
comment|/* Encryption key table */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE_0 + ((n)*32))
end_define

begin_define
define|#
directive|define
name|AR_CR_RXE
value|0x00000004
end_define

begin_comment
comment|/* Receive enable */
end_comment

begin_define
define|#
directive|define
name|AR_CR_RXD
value|0x00000020
end_define

begin_comment
comment|/* Receive disable */
end_comment

begin_define
define|#
directive|define
name|AR_CR_SWI
value|0x00000040
end_define

begin_comment
comment|/* One-shot software interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_CR_BITS
value|"\20\3RXE\6RXD\7SWI"
end_define

begin_define
define|#
directive|define
name|AR_CFG_SWTD
value|0x00000001
end_define

begin_comment
comment|/* byteswap tx descriptor words */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWTB
value|0x00000002
end_define

begin_comment
comment|/* byteswap tx data buffer words */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRD
value|0x00000004
end_define

begin_comment
comment|/* byteswap rx descriptor words */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRB
value|0x00000008
end_define

begin_comment
comment|/* byteswap rx data buffer words */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_SWRG
value|0x00000010
end_define

begin_comment
comment|/* byteswap register access data words */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_AP_ADHOC_INDICATION
value|0x00000020
end_define

begin_comment
comment|/* AP/adhoc indication (0-AP, 1-Adhoc) */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_PHOK
value|0x00000100
end_define

begin_comment
comment|/* PHY OK status */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_EEBS
value|0x00000200
end_define

begin_comment
comment|/* EEPROM busy */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_CLK_GATE_DIS
value|0x00000400
end_define

begin_comment
comment|/* Clock gating disable (Oahu only) */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_PCI_MASTER_REQ_Q_THRESH_M
value|0x00060000
end_define

begin_comment
comment|/* Mask of PCI core master request queue full threshold */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_PCI_MASTER_REQ_Q_THRESH_S
value|17
end_define

begin_comment
comment|/* Shift for PCI core master request queue full threshold */
end_comment

begin_define
define|#
directive|define
name|AR_CFG_BITS
define|\
value|"\20\1SWTD\2SWTB\3SWRD\4SWRB\5SWRG\10PHYOK11EEBS"
end_define

begin_define
define|#
directive|define
name|AR_IER_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Global interrupt enable */
end_comment

begin_define
define|#
directive|define
name|AR_IER_DISABLE
value|0x00000000
end_define

begin_comment
comment|/* Global interrupt disable */
end_comment

begin_define
define|#
directive|define
name|AR_IER_BITS
value|"\20\1ENABLE"
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_6_M
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_6_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_9_M
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_9_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_12_M
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_12_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_18_M
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_18_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_24_M
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_24_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_36_M
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_36_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_48_M
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_48_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_54_M
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|AR_RTSD0_RTS_DURATION_54_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_DMASIZE_4B
value|0x00000000
end_define

begin_comment
comment|/* DMA size 4 bytes (TXCFG + RXCFG) */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_8B
value|0x00000001
end_define

begin_comment
comment|/* DMA size 8 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_16B
value|0x00000002
end_define

begin_comment
comment|/* DMA size 16 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_32B
value|0x00000003
end_define

begin_comment
comment|/* DMA size 32 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_64B
value|0x00000004
end_define

begin_comment
comment|/* DMA size 64 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_128B
value|0x00000005
end_define

begin_comment
comment|/* DMA size 128 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_256B
value|0x00000006
end_define

begin_comment
comment|/* DMA size 256 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_DMASIZE_512B
value|0x00000007
end_define

begin_comment
comment|/* DMA size 512 bytes */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_FTRIG_M
value|0x000003F0
end_define

begin_comment
comment|/* Mask for Frame trigger level */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_FTRIG_S
value|4
end_define

begin_comment
comment|/* Shift for Frame trigger level */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_FTRIG_IMMED
value|0x00000000
end_define

begin_comment
comment|/* bytes in PCU TX FIFO before air */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_FTRIG_64B
value|0x00000010
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_FTRIG_128B
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_FTRIG_192B
value|0x00000030
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_FTRIG_256B
value|0x00000040
end_define

begin_comment
comment|/* 5 bits total */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_BITS
value|"\20"
end_define

begin_define
define|#
directive|define
name|AR5311_RXCFG_DEF_RX_ANTENNA
value|0x00000008
end_define

begin_comment
comment|/* Default Receive Antenna */
end_comment

begin_comment
comment|/* Maui2/Spirit only - reserved on Oahu */
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG_ZLFDMA
value|0x00000010
end_define

begin_comment
comment|/* Enable DMA of zero-length frame */
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG_EN_JUM
value|0x00000020
end_define

begin_comment
comment|/* Enable jumbo rx descriptors */
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG_WR_JUM
value|0x00000040
end_define

begin_comment
comment|/* Wrap jumbo rx descriptors */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_COW
value|0x00000001
end_define

begin_comment
comment|/* counter overflow warning */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_FMC
value|0x00000002
end_define

begin_comment
comment|/* freeze MIB counters */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_CMC
value|0x00000004
end_define

begin_comment
comment|/* clear MIB counters */
end_comment

begin_define
define|#
directive|define
name|AR_MIBC_MCS
value|0x00000008
end_define

begin_comment
comment|/* MIB counter strobe, increment all */
end_comment

begin_define
define|#
directive|define
name|AR_TOPS_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Mask for timeout prescale */
end_comment

begin_define
define|#
directive|define
name|AR_RXNPTO_MASK
value|0x000003FF
end_define

begin_comment
comment|/* Mask for no frame received timeout */
end_comment

begin_define
define|#
directive|define
name|AR_TXNPTO_MASK
value|0x000003FF
end_define

begin_comment
comment|/* Mask for no frame transmitted timeout */
end_comment

begin_define
define|#
directive|define
name|AR_TXNPTO_QCU_MASK
value|0x03FFFC00
end_define

begin_comment
comment|/* Mask indicating the set of QCUs */
end_comment

begin_comment
comment|/* for which frame completions will cause */
end_comment

begin_comment
comment|/* a reset of the no frame transmitted timeout */
end_comment

begin_define
define|#
directive|define
name|AR_RPGTO_MASK
value|0x000003FF
end_define

begin_comment
comment|/* Mask for receive frame gap timeout */
end_comment

begin_define
define|#
directive|define
name|AR_RPCNT_MASK
value|0x0000001F
end_define

begin_comment
comment|/* Mask for receive frame count limit */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_M
value|0x000001E0
end_define

begin_comment
comment|/* Mask for DMA observation bus mux select */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_DMA_OBS_S
value|5
end_define

begin_comment
comment|/* Shift for DMA observation bus mux select */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS_M
value|0x00000E00
end_define

begin_comment
comment|/* Mask for MISC observation bus mux select */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MISC_OBS_S
value|9
end_define

begin_comment
comment|/* Shift for MISC observation bus mux select */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MAC_OBS_BUS_LSB_M
value|0x00007000
end_define

begin_comment
comment|/* Mask for MAC observation bus mux select (lsb) */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MAC_OBS_BUS_LSB_S
value|12
end_define

begin_comment
comment|/* Shift for MAC observation bus mux select (lsb) */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MAC_OBS_BUS_MSB_M
value|0x00038000
end_define

begin_comment
comment|/* Mask for MAC observation bus mux select (msb) */
end_comment

begin_define
define|#
directive|define
name|AR_MACMISC_MAC_OBS_BUS_MSB_S
value|15
end_define

begin_comment
comment|/* Shift for MAC observation bus mux select (msb) */
end_comment

begin_comment
comment|/* Maui2/Spirit only. */
end_comment

begin_define
define|#
directive|define
name|AR5311_QDCLKGATE_QCU_M
value|0x0000FFFF
end_define

begin_comment
comment|/* Mask for QCU clock disable */
end_comment

begin_define
define|#
directive|define
name|AR5311_QDCLKGATE_DCU_M
value|0x07FF0000
end_define

begin_comment
comment|/* Mask for DCU clock disable */
end_comment

begin_comment
comment|/* Interrupt Status Registers */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXOK
value|0x00000001
end_define

begin_comment
comment|/* At least one frame received sans errors */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXDESC
value|0x00000002
end_define

begin_comment
comment|/* Receive interrupt request */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXERR
value|0x00000004
end_define

begin_comment
comment|/* Receive error interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXNOPKT
value|0x00000008
end_define

begin_comment
comment|/* No frame received within timeout clock */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXEOL
value|0x00000010
end_define

begin_comment
comment|/* Received descriptor empty interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXORN
value|0x00000020
end_define

begin_comment
comment|/* Receive FIFO overrun interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXOK
value|0x00000040
end_define

begin_comment
comment|/* Transmit okay interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXDESC
value|0x00000080
end_define

begin_comment
comment|/* Transmit interrupt request */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXERR
value|0x00000100
end_define

begin_comment
comment|/* Transmit error interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXNOPKT
value|0x00000200
end_define

begin_comment
comment|/* No frame transmitted interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXEOL
value|0x00000400
end_define

begin_comment
comment|/* Transmit descriptor empty interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXURN
value|0x00000800
end_define

begin_comment
comment|/* Transmit FIFO underrun interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_MIB
value|0x00001000
end_define

begin_comment
comment|/* MIB interrupt - see MIBC */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_SWI
value|0x00002000
end_define

begin_comment
comment|/* Software interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXPHY
value|0x00004000
end_define

begin_comment
comment|/* PHY receive error interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXKCM
value|0x00008000
end_define

begin_comment
comment|/* Key-cache miss interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_SWBA
value|0x00010000
end_define

begin_comment
comment|/* Software beacon alert interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BRSSI
value|0x00020000
end_define

begin_comment
comment|/* Beacon threshold interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BMISS
value|0x00040000
end_define

begin_comment
comment|/* Beacon missed interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_HIUERR
value|0x00080000
end_define

begin_comment
comment|/* An unexpected bus error has occurred */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_BNR
value|0x00100000
end_define

begin_comment
comment|/* Beacon not ready interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TIM
value|0x00800000
end_define

begin_comment
comment|/* TIM interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_GPIO
value|0x01000000
end_define

begin_comment
comment|/* GPIO Interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_QCBROVF
value|0x02000000
end_define

begin_comment
comment|/* QCU CBR overflow interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_QCBRURN
value|0x04000000
end_define

begin_comment
comment|/* QCU CBR underrun interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_QTRIG
value|0x08000000
end_define

begin_comment
comment|/* QCU scheduling trigger interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RESV0
value|0xF0000000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S0_QCU_TXOK_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for TXOK (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S0_QCU_TXDESC_M
value|0x03FF0000
end_define

begin_comment
comment|/* Mask for TXDESC (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXERR_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for TXERR (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S1_QCU_TXEOL_M
value|0x03FF0000
end_define

begin_comment
comment|/* Mask for TXEOL (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_QCU_TXURN_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for TXURN (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_MCABT
value|0x00010000
end_define

begin_comment
comment|/* Master cycle abort interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_SSERR
value|0x00020000
end_define

begin_comment
comment|/* SERR interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_DPERR
value|0x00040000
end_define

begin_comment
comment|/* PCI bus parity error */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_RESV0
value|0xFFF80000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S3_QCU_QCBROVF_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for QCBROVF (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S3_QCU_QCBRURN_M
value|0x03FF0000
end_define

begin_comment
comment|/* Mask for QCBRURN (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S4_QCU_QTRIG_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for QTRIG (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S4_RESV0
value|0xFFFFFC00
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/* Interrupt Mask Registers */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXOK
value|0x00000001
end_define

begin_comment
comment|/* At least one frame received sans errors */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXDESC
value|0x00000002
end_define

begin_comment
comment|/* Receive interrupt request */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXERR
value|0x00000004
end_define

begin_comment
comment|/* Receive error interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXNOPKT
value|0x00000008
end_define

begin_comment
comment|/* No frame received within timeout clock */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXEOL
value|0x00000010
end_define

begin_comment
comment|/* Received descriptor empty interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXORN
value|0x00000020
end_define

begin_comment
comment|/* Receive FIFO overrun interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXOK
value|0x00000040
end_define

begin_comment
comment|/* Transmit okay interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXDESC
value|0x00000080
end_define

begin_comment
comment|/* Transmit interrupt request */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXERR
value|0x00000100
end_define

begin_comment
comment|/* Transmit error interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXNOPKT
value|0x00000200
end_define

begin_comment
comment|/* No frame transmitted interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXEOL
value|0x00000400
end_define

begin_comment
comment|/* Transmit descriptor empty interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXURN
value|0x00000800
end_define

begin_comment
comment|/* Transmit FIFO underrun interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_MIB
value|0x00001000
end_define

begin_comment
comment|/* MIB interrupt - see MIBC */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_SWI
value|0x00002000
end_define

begin_comment
comment|/* Software interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXPHY
value|0x00004000
end_define

begin_comment
comment|/* PHY receive error interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXKCM
value|0x00008000
end_define

begin_comment
comment|/* Key-cache miss interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_SWBA
value|0x00010000
end_define

begin_comment
comment|/* Software beacon alert interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BRSSI
value|0x00020000
end_define

begin_comment
comment|/* Beacon threshold interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BMISS
value|0x00040000
end_define

begin_comment
comment|/* Beacon missed interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_HIUERR
value|0x00080000
end_define

begin_comment
comment|/* An unexpected bus error has occurred */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_BNR
value|0x00100000
end_define

begin_comment
comment|/* BNR interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TIM
value|0x00800000
end_define

begin_comment
comment|/* TIM interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_GPIO
value|0x01000000
end_define

begin_comment
comment|/* GPIO Interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_QCBROVF
value|0x02000000
end_define

begin_comment
comment|/* QCU CBR overflow interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_QCBRURN
value|0x04000000
end_define

begin_comment
comment|/* QCU CBR underrun interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_QTRIG
value|0x08000000
end_define

begin_comment
comment|/* QCU scheduling trigger interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RESV0
value|0xF0000000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S0_QCU_TXOK
value|0x000003FF
end_define

begin_comment
comment|/* Mask for TXOK (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S0_QCU_TXOK_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_IMR_S0_QCU_TXDESC
value|0x03FF0000
end_define

begin_comment
comment|/* Mask for TXDESC (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S0_QCU_TXDESC_S
value|16
end_define

begin_comment
comment|/* Shift for TXDESC (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S1_QCU_TXERR
value|0x000003FF
end_define

begin_comment
comment|/* Mask for TXERR (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S1_QCU_TXERR_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_IMR_S1_QCU_TXEOL
value|0x03FF0000
end_define

begin_comment
comment|/* Mask for TXEOL (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S1_QCU_TXEOL_S
value|16
end_define

begin_comment
comment|/* Shift for TXEOL (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_QCU_TXURN
value|0x000003FF
end_define

begin_comment
comment|/* Mask for TXURN (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_QCU_TXURN_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_IMR_S2_MCABT
value|0x00010000
end_define

begin_comment
comment|/* Master cycle abort interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_SSERR
value|0x00020000
end_define

begin_comment
comment|/* SERR interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_DPERR
value|0x00040000
end_define

begin_comment
comment|/* PCI bus parity error */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_RESV0
value|0xFFF80000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S3_QCU_QCBROVF_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for QCBROVF (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S3_QCU_QCBRURN_M
value|0x03FF0000
end_define

begin_comment
comment|/* Mask for QCBRURN (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S3_QCU_QCBRURN_S
value|16
end_define

begin_comment
comment|/* Shift for QCBRURN (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S4_QCU_QTRIG_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for QTRIG (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S4_RESV0
value|0xFFFFFC00
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/* Interrupt status registers (read-and-clear access, secondary shadow copies) */
end_comment

begin_comment
comment|/* QCU registers */
end_comment

begin_define
define|#
directive|define
name|AR_NUM_QCU
value|10
end_define

begin_comment
comment|/* Only use QCU 0-9 for forward QCU compatibility */
end_comment

begin_define
define|#
directive|define
name|AR_QCU_0
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_QCU_1
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_QCU_2
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_QCU_3
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_QCU_4
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_QCU_5
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR_QCU_6
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_QCU_7
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_QCU_8
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_QCU_9
value|0x0200
end_define

begin_define
define|#
directive|define
name|AR_Q_TXE_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for TXE (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_TXD_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for TXD (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_CBRCFG_CBR_INTERVAL
value|0x00FFFFFF
end_define

begin_comment
comment|/* Mask for CBR interval (us) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_CBRCFG_CBR_INTERVAL_S
value|0
end_define

begin_comment
comment|/* Shift for CBR interval */
end_comment

begin_define
define|#
directive|define
name|AR_Q_CBRCFG_CBR_OVF_THRESH
value|0xFF000000
end_define

begin_comment
comment|/* Mask for CBR overflow threshold */
end_comment

begin_define
define|#
directive|define
name|AR_Q_CBRCFG_CBR_OVF_THRESH_S
value|24
end_define

begin_comment
comment|/* Shift for " " " */
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMECFG_INT
value|0x00FFFFFF
end_define

begin_comment
comment|/* CBR interval (us) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMECFG_INT_S
value|0
end_define

begin_comment
comment|/* Shift for ReadyTime Interval (us) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMECFG_DURATION_M
value|0x00FFFFFF
end_define

begin_comment
comment|/* Mask for CBR interval (us) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMECFG_EN
value|0x01000000
end_define

begin_comment
comment|/* ReadyTime enable */
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMECFG_RESV0
value|0xFE000000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_SC_M
value|0x0000FFFF
end_define

begin_comment
comment|/* Mask for MAC_Q_ONESHOTARM_SC (QCU 0-15) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_SC_RESV0
value|0xFFFF0000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_CC_M
value|0x0000FFFF
end_define

begin_comment
comment|/* Mask for MAC_Q_ONESHOTARM_CC (QCU 0-15) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_ONESHOTARM_CC_RESV0
value|0xFFFF0000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_M
value|0x0000000F
end_define

begin_comment
comment|/* Mask for Frame Scheduling Policy */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_ASAP
value|0
end_define

begin_comment
comment|/* ASAP */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_CBR
value|1
end_define

begin_comment
comment|/* CBR */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_DBA_GATED
value|2
end_define

begin_comment
comment|/* DMA Beacon Alert gated */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_TIM_GATED
value|3
end_define

begin_comment
comment|/* TIM gated */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_FSP_BEACON_SENT_GATED
value|4
end_define

begin_comment
comment|/* Beacon-sent-gated */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_ONE_SHOT_EN
value|0x00000010
end_define

begin_comment
comment|/* OneShot enable */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_CBR_INCR_DIS1
value|0x00000020
end_define

begin_comment
comment|/* Disable CBR expired counter 						   incr (empty q) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_CBR_INCR_DIS0
value|0x00000040
end_define

begin_comment
comment|/* Disable CBR expired counter 						   incr (empty beacon q) */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_BEACON_USE
value|0x00000080
end_define

begin_comment
comment|/* Beacon use indication */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_CBR_EXP_CNTR_LIMIT
value|0x00000100
end_define

begin_comment
comment|/* CBR expired counter limit enable */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_RDYTIME_EXP_POLICY
value|0x00000200
end_define

begin_comment
comment|/* Enable TXE cleared on ReadyTime expired or VEOL */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_RESET_CBR_EXP_CTR
value|0x00000400
end_define

begin_comment
comment|/* Reset CBR expired counter */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_DCU_EARLY_TERM_REQ
value|0x00000800
end_define

begin_comment
comment|/* DCU frame early termination request control */
end_comment

begin_define
define|#
directive|define
name|AR_Q_MISC_RESV0
value|0xFFFFF000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_Q_STS_PEND_FR_CNT_M
value|0x00000003
end_define

begin_comment
comment|/* Mask for Pending Frame Count */
end_comment

begin_define
define|#
directive|define
name|AR_Q_STS_RESV0
value|0x000000FC
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_Q_STS_CBR_EXP_CNT_M
value|0x0000FF00
end_define

begin_comment
comment|/* Mask for CBR expired counter */
end_comment

begin_define
define|#
directive|define
name|AR_Q_STS_RESV1
value|0xFFFF0000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_Q_RDYTIMESHDN_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for ReadyTimeShutdown status (QCU 0-9) */
end_comment

begin_comment
comment|/* DCU registers */
end_comment

begin_define
define|#
directive|define
name|AR_NUM_DCU
value|10
end_define

begin_comment
comment|/* Only use 10 DCU's for forward QCU/DCU compatibility */
end_comment

begin_define
define|#
directive|define
name|AR_DCU_0
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR_DCU_1
value|0x0002
end_define

begin_define
define|#
directive|define
name|AR_DCU_2
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR_DCU_3
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR_DCU_4
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR_DCU_5
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR_DCU_6
value|0x0040
end_define

begin_define
define|#
directive|define
name|AR_DCU_7
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR_DCU_8
value|0x0100
end_define

begin_define
define|#
directive|define
name|AR_DCU_9
value|0x0200
end_define

begin_define
define|#
directive|define
name|AR_D_QCUMASK_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask for QCU Mask (QCU 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_D_QCUMASK_RESV0
value|0xFFFFFC00
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_CWMIN
value|0x000003FF
end_define

begin_comment
comment|/* Mask for CW_MIN */
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_CWMIN_S
value|0
end_define

begin_comment
comment|/* Shift for CW_MIN */
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_CWMAX
value|0x000FFC00
end_define

begin_comment
comment|/* Mask for CW_MAX */
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_CWMAX_S
value|10
end_define

begin_comment
comment|/* Shift for CW_MAX */
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_AIFS
value|0x0FF00000
end_define

begin_comment
comment|/* Mask for AIFS */
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_AIFS_S
value|20
end_define

begin_comment
comment|/* Shift for AIFS */
end_comment

begin_define
define|#
directive|define
name|AR_D_LCL_IFS_RESV0
value|0xF0000000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_FR_SH
value|0x0000000F
end_define

begin_comment
comment|/* Mask for frame short retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_FR_SH_S
value|0
end_define

begin_comment
comment|/* Shift for frame short retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_FR_LG
value|0x000000F0
end_define

begin_comment
comment|/* Mask for frame long retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_FR_LG_S
value|4
end_define

begin_comment
comment|/* Shift for frame long retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_STA_SH
value|0x00003F00
end_define

begin_comment
comment|/* Mask for station short retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_STA_SH_S
value|8
end_define

begin_comment
comment|/* Shift for station short retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_STA_LG
value|0x000FC000
end_define

begin_comment
comment|/* Mask for station short retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_STA_LG_S
value|14
end_define

begin_comment
comment|/* Shift for station short retry limit */
end_comment

begin_define
define|#
directive|define
name|AR_D_RETRY_LIMIT_RESV0
value|0xFFF00000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_D_CHNTIME_EN
value|0x00100000
end_define

begin_comment
comment|/* ChannelTime enable */
end_comment

begin_define
define|#
directive|define
name|AR_D_CHNTIME_RESV0
value|0xFFE00000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_D_CHNTIME_DUR
value|0x000FFFFF
end_define

begin_comment
comment|/* Mask for ChannelTime duration (us) */
end_comment

begin_define
define|#
directive|define
name|AR_D_CHNTIME_DUR_S
value|0
end_define

begin_comment
comment|/* Shift for ChannelTime duration */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_BKOFF_THRESH_M
value|0x000007FF
end_define

begin_comment
comment|/* Mask for Backoff threshold setting */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_FRAG_BKOFF_EN
value|0x00000200
end_define

begin_comment
comment|/* Backoff during a frag burst */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_HCF_POLL_EN
value|0x00000800
end_define

begin_comment
comment|/* HFC poll enable */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_BKOFF_PERSISTENCE
value|0x00001000
end_define

begin_comment
comment|/* Backoff persistence factor setting */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_FR_PREFETCH_EN
value|0x00002000
end_define

begin_comment
comment|/* Frame prefetch enable */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIR_COL_HANDLING_M
value|0x0000C000
end_define

begin_comment
comment|/* Mask for Virtual collision handling policy */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIR_COL_HANDLING_NORMAL
value|0
end_define

begin_comment
comment|/* Normal */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIR_COL_HANDLING_MODIFIED
value|1
end_define

begin_comment
comment|/* Modified */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIR_COL_HANDLING_IGNORE
value|2
end_define

begin_comment
comment|/* Ignore */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_BEACON_USE
value|0x00010000
end_define

begin_comment
comment|/* Beacon use indication */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL
value|0x00060000
end_define

begin_comment
comment|/* Mask for DCU arbiter lockout control */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL_S
value|17
end_define

begin_comment
comment|/* Shift for DCU arbiter lockout control */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL_NONE
value|0
end_define

begin_comment
comment|/* No lockout */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL_INTRA_FR
value|1
end_define

begin_comment
comment|/* Intra-frame */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_CNTRL_GLOBAL
value|2
end_define

begin_comment
comment|/* Global */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_ARB_LOCKOUT_IGNORE
value|0x00080000
end_define

begin_comment
comment|/* DCU arbiter lockout ignore control */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_SEQ_NUM_INCR_DIS
value|0x00100000
end_define

begin_comment
comment|/* Sequence number increment disable */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_POST_FR_BKOFF_DIS
value|0x00200000
end_define

begin_comment
comment|/* Post-frame backoff disable */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_VIRT_COLL_POLICY
value|0x00400000
end_define

begin_comment
comment|/* Virtual coll. handling policy */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_BLOWN_IFS_POLICY
value|0x00800000
end_define

begin_comment
comment|/* Blown IFS handling policy */
end_comment

begin_define
define|#
directive|define
name|AR5311_D_MISC_SEQ_NUM_CONTROL
value|0x01000000
end_define

begin_comment
comment|/* Sequence Number local or global */
end_comment

begin_comment
comment|/* Maui2/Spirit only, reserved on Oahu */
end_comment

begin_define
define|#
directive|define
name|AR_D_MISC_RESV0
value|0xFE000000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_D_SEQNUM_M
value|0x00000FFF
end_define

begin_comment
comment|/* Mask for value of sequence number */
end_comment

begin_define
define|#
directive|define
name|AR_D_SEQNUM_RESV0
value|0xFFFFF000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_LFSR_SLICE_SEL
value|0x00000007
end_define

begin_comment
comment|/* Mask forLFSR slice select */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_TURBO_MODE
value|0x00000008
end_define

begin_comment
comment|/* Turbo mode indication */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_SIFS_DURATION_USEC
value|0x000003F0
end_define

begin_comment
comment|/* Mask for SIFS duration (us) */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_USEC_DURATION
value|0x000FFC00
end_define

begin_comment
comment|/* Mask for microsecond duration */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_DCU_ARBITER_DLY
value|0x00300000
end_define

begin_comment
comment|/* Mask for DCU arbiter delay */
end_comment

begin_define
define|#
directive|define
name|AR_D_GBL_IFS_MISC_RESV0
value|0xFFC00000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/* Oahu only */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE_CTRL_M
value|0x000003FF
end_define

begin_comment
comment|/* Mask of DCUs to pause (DCUs 0-9) */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE_RESV0
value|0x0000FC00
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE_STATUS
value|0x00010000
end_define

begin_comment
comment|/* Transmit pause status */
end_comment

begin_define
define|#
directive|define
name|AR_D_TXPSE_RESV1
value|0xFFFE0000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/* DMA& PCI Registers in PCI space (usable during sleep) */
end_comment

begin_define
define|#
directive|define
name|AR_RC_MAC
value|0x00000001
end_define

begin_comment
comment|/* MAC reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_BB
value|0x00000002
end_define

begin_comment
comment|/* Baseband reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_RESV0
value|0x00000004
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_RC_RESV1
value|0x00000008
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_RC_PCI
value|0x00000010
end_define

begin_comment
comment|/* PCI-core reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_BITS
value|"\20\1MAC\2BB\3RESV0\4RESV1\5RPCI"
end_define

begin_define
define|#
directive|define
name|AR_SCR_SLDUR
value|0x0000ffff
end_define

begin_comment
comment|/* sleep duration mask, units of 128us */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLDUR_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_SCR_SLE
value|0x00030000
end_define

begin_comment
comment|/* sleep enable mask */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_S
value|16
end_define

begin_comment
comment|/* sleep enable bits shift */
end_comment

begin_comment
comment|/*  * The previous values for the following three defines were:  *  *	AR_SCR_SLE_WAKE	0x00000000  *	AR_SCR_SLE_SLP	0x00010000  *	AR_SCR_SLE_NORM	0x00020000  *  * However, these have been pre-shifted with AR_SCR_SLE_S.  The  * OS_REG_READ() macro would attempt to shift them again, effectively  * shifting out any of the set bits completely.  */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_WAKE
value|0
end_define

begin_comment
comment|/* force wake */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_SLP
value|1
end_define

begin_comment
comment|/* force sleep */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_NORM
value|2
end_define

begin_comment
comment|/* sleep logic normal operation */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_SLE_UNITS
value|0x00000008
end_define

begin_comment
comment|/* SCR units/TU */
end_comment

begin_define
define|#
directive|define
name|AR_SCR_BITS
value|"\20\20SLE_SLP\21SLE"
end_define

begin_define
define|#
directive|define
name|AR_INTPEND_TRUE
value|0x00000001
end_define

begin_comment
comment|/* interrupt pending */
end_comment

begin_define
define|#
directive|define
name|AR_INTPEND_BITS
value|"\20\1IP"
end_define

begin_define
define|#
directive|define
name|AR_SFR_SLEEP
value|0x00000001
end_define

begin_comment
comment|/* force sleep */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_CLKRUNEN
value|0x00000004
end_define

begin_comment
comment|/* enable PCI CLKRUN function */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_EEPROM_SIZE_M
value|0x00000018
end_define

begin_comment
comment|/* Mask for EEPROM size */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_EEPROM_SIZE_S
value|3
end_define

begin_comment
comment|/* Mask for EEPROM size */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_EEPROM_SIZE_4K
value|0
end_define

begin_comment
comment|/* EEPROM size 4 Kbit */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_EEPROM_SIZE_8K
value|1
end_define

begin_comment
comment|/* EEPROM size 8 Kbit */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_EEPROM_SIZE_16K
value|2
end_define

begin_comment
comment|/* EEPROM size 16 Kbit */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_EEPROM_SIZE_FAILED
value|3
end_define

begin_comment
comment|/* Failure */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDCTL
value|0x00000060
end_define

begin_comment
comment|/* LED control Status */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDCTL_NONE
value|0x00000000
end_define

begin_comment
comment|/* STA is not associated or trying */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDCTL_PEND
value|0x00000020
end_define

begin_comment
comment|/* STA is trying to associate */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDCTL_ASSOC
value|0x00000040
end_define

begin_comment
comment|/* STA is associated */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_PCI_BUS_SEL_M
value|0x00000380
end_define

begin_comment
comment|/* Mask for PCI observation bus mux select */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_DIS_CBE_FIX
value|0x00000400
end_define

begin_comment
comment|/* Disable fix for bad PCI CBE# generation */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_SL_INTEN
value|0x00000800
end_define

begin_comment
comment|/* enable interrupt line assertion when asleep */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_RESV0
value|0x00001000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_SL_INPEN
value|0x00002000
end_define

begin_comment
comment|/* Force asleep when an interrupt is pending */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_RESV1
value|0x0000C000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_SPWR_DN
value|0x00010000
end_define

begin_comment
comment|/* mask for sleep/awake indication */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDMODE
value|0x000E0000
end_define

begin_comment
comment|/* LED mode */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDMODE_PROP
value|0x00000000
end_define

begin_comment
comment|/* Blink prop to filtered tx/rx */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDMODE_RPROP
value|0x00020000
end_define

begin_comment
comment|/* Blink prop to unfiltered tx/rx */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDMODE_SPLIT
value|0x00040000
end_define

begin_comment
comment|/* Blink power for tx/net for rx */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDMODE_RAND
value|0x00060000
end_define

begin_comment
comment|/* Blink randomly */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDBLINK
value|0x00700000
end_define

begin_comment
comment|/* LED blink threshold select */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_LEDBLINK_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_PCICFG_LEDSLOW
value|0x00800000
end_define

begin_comment
comment|/* LED slowest blink rate mode */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_RESV2
value|0xFF000000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_BITS
value|"\20\3CLKRUNEN\13SL_INTEN"
end_define

begin_define
define|#
directive|define
name|AR_GPIOCR_CR_SHIFT
value|2
end_define

begin_comment
comment|/* Each CR is 2 bits */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_0_CR_N
value|0x00000000
end_define

begin_comment
comment|/* Input only mode for GPIODO[0] */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_0_CR_0
value|0x00000001
end_define

begin_comment
comment|/* Output only if GPIODO[0] = 0 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_0_CR_1
value|0x00000002
end_define

begin_comment
comment|/* Output only if GPIODO[0] = 1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_0_CR_A
value|0x00000003
end_define

begin_comment
comment|/* Always output */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_1_CR_N
value|0x00000000
end_define

begin_comment
comment|/* Input only mode for GPIODO[1] */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_1_CR_0
value|0x00000004
end_define

begin_comment
comment|/* Output only if GPIODO[1] = 0 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_1_CR_1
value|0x00000008
end_define

begin_comment
comment|/* Output only if GPIODO[1] = 1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_1_CR_A
value|0x0000000C
end_define

begin_comment
comment|/* Always output */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_2_CR_N
value|0x00000000
end_define

begin_comment
comment|/* Input only mode for GPIODO[2] */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_2_CR_0
value|0x00000010
end_define

begin_comment
comment|/* Output only if GPIODO[2] = 0 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_2_CR_1
value|0x00000020
end_define

begin_comment
comment|/* Output only if GPIODO[2] = 1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_2_CR_A
value|0x00000030
end_define

begin_comment
comment|/* Always output */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_3_CR_N
value|0x00000000
end_define

begin_comment
comment|/* Input only mode for GPIODO[3] */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_3_CR_0
value|0x00000040
end_define

begin_comment
comment|/* Output only if GPIODO[3] = 0 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_3_CR_1
value|0x00000080
end_define

begin_comment
comment|/* Output only if GPIODO[3] = 1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_3_CR_A
value|0x000000C0
end_define

begin_comment
comment|/* Always output */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_4_CR_N
value|0x00000000
end_define

begin_comment
comment|/* Input only mode for GPIODO[4] */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_4_CR_0
value|0x00000100
end_define

begin_comment
comment|/* Output only if GPIODO[4] = 0 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_4_CR_1
value|0x00000200
end_define

begin_comment
comment|/* Output only if GPIODO[4] = 1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_4_CR_A
value|0x00000300
end_define

begin_comment
comment|/* Always output */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_5_CR_N
value|0x00000000
end_define

begin_comment
comment|/* Input only mode for GPIODO[5] */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_5_CR_0
value|0x00000400
end_define

begin_comment
comment|/* Output only if GPIODO[5] = 0 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_5_CR_1
value|0x00000800
end_define

begin_comment
comment|/* Output only if GPIODO[5] = 1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_5_CR_A
value|0x00000C00
end_define

begin_comment
comment|/* Always output */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SHIFT
value|12
end_define

begin_comment
comment|/* Interrupt select field shifter */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_MASK
value|0x00007000
end_define

begin_comment
comment|/* Interrupt select field mask */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SEL0
value|0x00000000
end_define

begin_comment
comment|/* Select Interrupt Pin GPIO_0 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SEL1
value|0x00001000
end_define

begin_comment
comment|/* Select Interrupt Pin GPIO_1 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SEL2
value|0x00002000
end_define

begin_comment
comment|/* Select Interrupt Pin GPIO_2 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SEL3
value|0x00003000
end_define

begin_comment
comment|/* Select Interrupt Pin GPIO_3 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SEL4
value|0x00004000
end_define

begin_comment
comment|/* Select Interrupt Pin GPIO_4 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SEL5
value|0x00005000
end_define

begin_comment
comment|/* Select Interrupt Pin GPIO_5 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_ENA
value|0x00008000
end_define

begin_comment
comment|/* Enable GPIO Interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SELL
value|0x00000000
end_define

begin_comment
comment|/* Generate Interrupt if selected pin is low */
end_comment

begin_define
define|#
directive|define
name|AR_GPIOCR_INT_SELH
value|0x00010000
end_define

begin_comment
comment|/* Generate Interrupt if selected pin is high */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_ID_M
value|0x000000FF
end_define

begin_comment
comment|/* Mask to read SREV info */
end_comment

begin_define
define|#
directive|define
name|AR_PCICFG_EEPROM_SIZE_16K
value|2
end_define

begin_comment
comment|/* EEPROM size 16 Kbit */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_ID_S
value|4
end_define

begin_comment
comment|/* Major Rev Info */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_M
value|0x0000000F
end_define

begin_comment
comment|/* Chip revision level */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_FPGA
value|1
end_define

begin_define
define|#
directive|define
name|AR_SREV_D2PLUS
value|2
end_define

begin_define
define|#
directive|define
name|AR_SREV_D2PLUS_MS
value|3
end_define

begin_comment
comment|/* metal spin */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_CRETE
value|4
end_define

begin_define
define|#
directive|define
name|AR_SREV_CRETE_MS
value|5
end_define

begin_comment
comment|/* FCS metal spin */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_CRETE_MS23
value|7
end_define

begin_comment
comment|/* 2.3 metal spin (6 skipped) */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_CRETE_23
value|8
end_define

begin_comment
comment|/* 2.3 full tape out */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION_M
value|0x000000F0
end_define

begin_comment
comment|/* Chip version indication */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION_CRETE
value|0
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_MAUI_1
value|1
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_MAUI_2
value|2
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_SPIRIT
value|3
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_OAHU
value|4
end_define

begin_define
define|#
directive|define
name|AR_SREV_OAHU_ES
value|0
end_define

begin_comment
comment|/* Engineering Sample */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_OAHU_PROD
value|2
end_define

begin_comment
comment|/* Production */
end_comment

begin_define
define|#
directive|define
name|RAD5_SREV_MAJOR
value|0x10
end_define

begin_comment
comment|/* All current supported ar5211 5 GHz radios are rev 0x10 */
end_comment

begin_define
define|#
directive|define
name|RAD5_SREV_PROD
value|0x15
end_define

begin_comment
comment|/* Current production level radios */
end_comment

begin_define
define|#
directive|define
name|RAD2_SREV_MAJOR
value|0x20
end_define

begin_comment
comment|/* All current supported ar5211 2 GHz radios are rev 0x10 */
end_comment

begin_comment
comment|/* EEPROM Registers in the MAC */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CMD_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CMD_WRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CMD_RESET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STS_READ_ERROR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STS_READ_COMPLETE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STS_WRITE_ERROR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STS_WRITE_COMPLETE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_SIZE_M
value|0x00000003
end_define

begin_comment
comment|/* Mask for EEPROM size determination override */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_SIZE_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_SIZE_4KBIT
value|1
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_SIZE_8KBIT
value|2
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_SIZE_16KBIT
value|3
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_DIS_WAIT_WRITE_COMPL
value|0x00000004
end_define

begin_comment
comment|/* Disable wait for write completion */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_CLOCK_M
value|0x00000018
end_define

begin_comment
comment|/* Mask for EEPROM clock rate control */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_CLOCK_S
value|3
end_define

begin_comment
comment|/* Shift for EEPROM clock rate control */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_CLOCK_156KHZ
value|0
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_CLOCK_312KHZ
value|1
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_CLOCK_625KHZ
value|2
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_RESV0
value|0x000000E0
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_PROT_KEY_M
value|0x00FFFF00
end_define

begin_comment
comment|/* Mask for EEPROM protection key */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_PROT_KEY_S
value|8
end_define

begin_comment
comment|/* Shift for EEPROM protection key */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_CFG_EN_L
value|0x01000000
end_define

begin_comment
comment|/* EPRM_EN_L setting */
end_comment

begin_comment
comment|/* MAC PCU Registers */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_SADH_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Mask for upper 16 bits of MAC addr */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_STA_AP
value|0x00010000
end_define

begin_comment
comment|/* Device is AP */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_ADHOC
value|0x00020000
end_define

begin_comment
comment|/* Device is ad-hoc */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_PWR_SAV
value|0x00040000
end_define

begin_comment
comment|/* Power save reporting in self-generated frames */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_KSRCHDIS
value|0x00080000
end_define

begin_comment
comment|/* Key search disable */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_PCF
value|0x00100000
end_define

begin_comment
comment|/* Observe PCF */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_DEFAULT_ANTENNA
value|0x00200000
end_define

begin_comment
comment|/* Use default antenna */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_DESC_ANTENNA
value|0x00400000
end_define

begin_comment
comment|/* Update default antenna w/ TX antenna */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_RTS_USE_DEF
value|0x00800000
end_define

begin_comment
comment|/* Use default antenna to send RTS */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_ACKCTS_6MB
value|0x01000000
end_define

begin_comment
comment|/* Use 6Mb/s rate for ACK& CTS */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_BASE_RATE_11B
value|0x02000000
end_define

begin_comment
comment|/* Use 11b base rate for ACK& CTS */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_BITS
define|\
value|"\20\20AP\21ADHOC\22PWR_SAV\23KSRCHDIS\25PCF"
end_define

begin_define
define|#
directive|define
name|AR_BSS_ID1_U16_M
value|0x0000FFFF
end_define

begin_comment
comment|/* Mask for upper 16 bits of BSSID */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID1_AID_M
value|0xFFFF0000
end_define

begin_comment
comment|/* Mask for association ID */
end_comment

begin_define
define|#
directive|define
name|AR_BSS_ID1_AID_S
value|16
end_define

begin_comment
comment|/* Shift for association ID */
end_comment

begin_define
define|#
directive|define
name|AR_SLOT_TIME_MASK
value|0x000007FF
end_define

begin_comment
comment|/* Slot time mask */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT_ACK
value|0x00001FFF
end_define

begin_comment
comment|/* Mask for ACK time-out */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT_ACK_S
value|0
end_define

begin_comment
comment|/* Shift for ACK time-out */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT_CTS
value|0x1FFF0000
end_define

begin_comment
comment|/* Mask for CTS time-out */
end_comment

begin_define
define|#
directive|define
name|AR_TIME_OUT_CTS_S
value|16
end_define

begin_comment
comment|/* Shift for CTS time-out */
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR_MASK
value|0x000000FF
end_define

begin_comment
comment|/* Mask for Beacon RSSI warning threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR_BM_THR
value|0x0000FF00
end_define

begin_comment
comment|/* Mask for Missed beacon threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RSSI_THR_BM_THR_S
value|8
end_define

begin_comment
comment|/* Shift for Missed beacon threshold */
end_comment

begin_define
define|#
directive|define
name|AR_USEC_M
value|0x0000007F
end_define

begin_comment
comment|/* Mask for clock cycles in 1 usec */
end_comment

begin_define
define|#
directive|define
name|AR_USEC_32_M
value|0x00003F80
end_define

begin_comment
comment|/* Mask for number of 32MHz clock cycles in 1 usec */
end_comment

begin_define
define|#
directive|define
name|AR_USEC_32_S
value|7
end_define

begin_comment
comment|/* Shift for number of 32MHz clock cycles in 1 usec */
end_comment

begin_comment
comment|/*  * Tx/Rx latencies are to signal start and are in usecs.  *  * NOTE: AR5211/AR5311 difference: on Oahu, the TX latency field  *       has increased from 6 bits to 9 bits.  The RX latency field  *	 is unchanged, but is shifted over 3 bits.  */
end_comment

begin_define
define|#
directive|define
name|AR5311_USEC_TX_LAT_M
value|0x000FC000
end_define

begin_comment
comment|/* Tx latency */
end_comment

begin_define
define|#
directive|define
name|AR5311_USEC_TX_LAT_S
value|14
end_define

begin_define
define|#
directive|define
name|AR5311_USEC_RX_LAT_M
value|0x03F00000
end_define

begin_comment
comment|/* Rx latency */
end_comment

begin_define
define|#
directive|define
name|AR5311_USEC_RX_LAT_S
value|20
end_define

begin_define
define|#
directive|define
name|AR5211_USEC_TX_LAT_M
value|0x007FC000
end_define

begin_comment
comment|/* Tx latency */
end_comment

begin_define
define|#
directive|define
name|AR5211_USEC_TX_LAT_S
value|14
end_define

begin_define
define|#
directive|define
name|AR5211_USEC_RX_LAT_M
value|0x1F800000
end_define

begin_comment
comment|/* Rx latency */
end_comment

begin_define
define|#
directive|define
name|AR5211_USEC_RX_LAT_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_BEACON_PERIOD
value|0x0000FFFF
end_define

begin_comment
comment|/* Beacon period in TU/msec */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_PERIOD_S
value|0
end_define

begin_comment
comment|/* Byte offset of PERIOD start*/
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_TIM
value|0x007F0000
end_define

begin_comment
comment|/* Byte offset of TIM start */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_TIM_S
value|16
end_define

begin_comment
comment|/* Byte offset of TIM start */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_EN
value|0x00800000
end_define

begin_comment
comment|/* beacon enable */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_RESET_TSF
value|0x01000000
end_define

begin_comment
comment|/* Clears TSF to 0 */
end_comment

begin_define
define|#
directive|define
name|AR_BEACON_BITS
value|"\20\27ENABLE\30RESET_TSF"
end_define

begin_define
define|#
directive|define
name|AR_RX_FILTER_ALL
value|0x00000000
end_define

begin_comment
comment|/* Disallow all frames */
end_comment

begin_define
define|#
directive|define
name|AR_RX_UCAST
value|0x00000001
end_define

begin_comment
comment|/* Allow unicast frames */
end_comment

begin_define
define|#
directive|define
name|AR_RX_MCAST
value|0x00000002
end_define

begin_comment
comment|/* Allow multicast frames */
end_comment

begin_define
define|#
directive|define
name|AR_RX_BCAST
value|0x00000004
end_define

begin_comment
comment|/* Allow broadcast frames */
end_comment

begin_define
define|#
directive|define
name|AR_RX_CONTROL
value|0x00000008
end_define

begin_comment
comment|/* Allow control frames */
end_comment

begin_define
define|#
directive|define
name|AR_RX_BEACON
value|0x00000010
end_define

begin_comment
comment|/* Allow beacon frames */
end_comment

begin_define
define|#
directive|define
name|AR_RX_PROM
value|0x00000020
end_define

begin_comment
comment|/* Promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|AR_RX_PHY_ERR
value|0x00000040
end_define

begin_comment
comment|/* Allow all phy errors */
end_comment

begin_define
define|#
directive|define
name|AR_RX_PHY_RADAR
value|0x00000080
end_define

begin_comment
comment|/* Allow radar phy errors */
end_comment

begin_define
define|#
directive|define
name|AR_RX_FILTER_BITS
define|\
value|"\20\1UCAST\2MCAST\3BCAST\4CONTROL\5BEACON\6PROMISC\7PHY_ERR\10PHY_RADAR"
end_define

begin_define
define|#
directive|define
name|AR_DIAG_SW_CACHE_ACK
value|0x00000001
end_define

begin_comment
comment|/* disable ACK if no valid key*/
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_ACK
value|0x00000002
end_define

begin_comment
comment|/* disable ACK generation */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_CTS
value|0x00000004
end_define

begin_comment
comment|/* disable CTS generation */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_ENCRYPT
value|0x00000008
end_define

begin_comment
comment|/* disable encryption */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_DECRYPT
value|0x00000010
end_define

begin_comment
comment|/* disable decryption */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_DIS_RX
value|0x00000020
end_define

begin_comment
comment|/* disable receive */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_CORR_FCS
value|0x00000080
end_define

begin_comment
comment|/* corrupt FCS */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_CHAN_INFO
value|0x00000100
end_define

begin_comment
comment|/* dump channel info */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_EN_SCRAMSD
value|0x00000200
end_define

begin_comment
comment|/* enable fixed scrambler seed*/
end_comment

begin_define
define|#
directive|define
name|AR5311_DIAG_SW_USE_ECO
value|0x00000400
end_define

begin_comment
comment|/* "super secret" use ECO enable bit */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_SCRAM_SEED_M
value|0x0001FC00
end_define

begin_comment
comment|/* Fixed scrambler seed mask */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_SCRAM_SEED_S
value|10
end_define

begin_comment
comment|/* Fixed scrambler seed shfit */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_FRAME_NV0
value|0x00020000
end_define

begin_comment
comment|/* accept frames of non-zero protocol version */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_OBS_PT_SEL_M
value|0x000C0000
end_define

begin_comment
comment|/* Observation point select */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_OBS_PT_SEL_S
value|18
end_define

begin_comment
comment|/* Observation point select */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SW_BITS
define|\
value|"\20\1DIS_CACHE_ACK\2DIS_ACK\3DIS_CTS\4DIS_ENC\5DIS_DEC\6DIS_RX"\ 	"\11CORR_FCS\12CHAN_INFO\13EN_SCRAM_SEED\14USE_ECO\24FRAME_NV0"
end_define

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY0
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 0)
end_define

begin_comment
comment|/* key bit 0-31 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY1
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 4)
end_define

begin_comment
comment|/* key bit 32-47 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY2
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 8)
end_define

begin_comment
comment|/* key bit 48-79 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY3
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 12)
end_define

begin_comment
comment|/* key bit 80-95 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_KEY4
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 16)
end_define

begin_comment
comment|/* key bit 96-127 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 20)
end_define

begin_comment
comment|/* key type */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_40
value|0x00000000
end_define

begin_comment
comment|/* WEP 40 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_104
value|0x00000001
end_define

begin_comment
comment|/* WEP 104 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_128
value|0x00000003
end_define

begin_comment
comment|/* WEP 128 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_AES
value|0x00000005
end_define

begin_comment
comment|/* AES 128 bit key */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_TYPE_CLR
value|0x00000007
end_define

begin_comment
comment|/* no encryption */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_MAC0
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 24)
end_define

begin_comment
comment|/* MAC address 1-32 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_MAC1
parameter_list|(
name|n
parameter_list|)
value|(AR_KEYTABLE(n) + 28)
end_define

begin_comment
comment|/* MAC address 33-47 */
end_comment

begin_define
define|#
directive|define
name|AR_KEYTABLE_VALID
value|0x00008000
end_define

begin_comment
comment|/* key and MAC address valid */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5211REG_H */
end_comment

end_unit

