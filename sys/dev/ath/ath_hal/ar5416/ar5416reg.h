begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5416REG_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5416REG_H
end_define

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ar5212/ar5212reg.h>
end_include

begin_comment
comment|/*  * Register added starting with the AR5416  */
end_comment

begin_define
define|#
directive|define
name|AR_MIRT
value|0x0020
end_define

begin_comment
comment|/* interrupt rate threshold */
end_comment

begin_define
define|#
directive|define
name|AR_TIMT
value|0x0028
end_define

begin_comment
comment|/* Tx Interrupt mitigation threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RIMT
value|0x002C
end_define

begin_comment
comment|/* Rx Interrupt mitigation threshold */
end_comment

begin_define
define|#
directive|define
name|AR_GTXTO
value|0x0064
end_define

begin_comment
comment|/* global transmit timeout */
end_comment

begin_define
define|#
directive|define
name|AR_GTTM
value|0x0068
end_define

begin_comment
comment|/* global transmit timeout mode */
end_comment

begin_define
define|#
directive|define
name|AR_CST
value|0x006C
end_define

begin_comment
comment|/* carrier sense timeout */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED
value|0x1f04
end_define

begin_comment
comment|/* LED control */
end_comment

begin_define
define|#
directive|define
name|AR_WA
value|0x4004
end_define

begin_comment
comment|/* PCIE work-arounds */
end_comment

begin_define
define|#
directive|define
name|AR_PCIE_PM_CTRL
value|0x4014
end_define

begin_define
define|#
directive|define
name|AR_AHB_MODE
value|0x4024
end_define

begin_comment
comment|/* AHB mode for dma */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_CAUSE_CLR
value|0x4028
end_define

begin_comment
comment|/* clear interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_CAUSE
value|0x4028
end_define

begin_comment
comment|/* check pending interrupts */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_ENABLE
value|0x402c
end_define

begin_comment
comment|/* enable interrupts */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_MASK
value|0x4030
end_define

begin_comment
comment|/* asynchronous interrupt mask */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MASK
value|0x4034
end_define

begin_comment
comment|/* synchronous interrupt mask */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_CAUSE
value|0x4038
end_define

begin_comment
comment|/* check pending interrupts */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_ENABLE
value|0x403c
end_define

begin_comment
comment|/* enable interrupts */
end_comment

begin_define
define|#
directive|define
name|AR5416_PCIE_SERDES
value|0x4040
end_define

begin_define
define|#
directive|define
name|AR5416_PCIE_SERDES2
value|0x4044
end_define

begin_define
define|#
directive|define
name|AR_GPIO_IN_OUT
value|0x4048
end_define

begin_comment
comment|/* GPIO input/output register */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT
value|0x404c
end_define

begin_comment
comment|/* GPIO output enable register */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INTR_POL
value|0x4050
end_define

begin_comment
comment|/* GPIO interrupt polarity */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_EN_VAL
value|0x4054
end_define

begin_comment
comment|/* GPIO input enable and value */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX1
value|0x4058
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INPUT_MUX2
value|0x405c
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX1
value|0x4060
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX2
value|0x4064
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUTPUT_MUX3
value|0x4068
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA
value|0x407c
end_define

begin_define
define|#
directive|define
name|AR_OBS
value|0x4080
end_define

begin_define
define|#
directive|define
name|AR_RTC_RC
value|0x7000
end_define

begin_comment
comment|/* reset control */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_PLL_CONTROL
value|0x7014
end_define

begin_define
define|#
directive|define
name|AR_RTC_RESET
value|0x7040
end_define

begin_comment
comment|/* RTC reset register */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_STATUS
value|0x7044
end_define

begin_comment
comment|/* system sleep status */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_SLEEP_CLK
value|0x7048
end_define

begin_define
define|#
directive|define
name|AR_RTC_FORCE_WAKE
value|0x704c
end_define

begin_comment
comment|/* control MAC force wake */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_INTR_CAUSE
value|0x7050
end_define

begin_comment
comment|/* RTC interrupt cause/clear */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_INTR_ENABLE
value|0x7054
end_define

begin_comment
comment|/* RTC interrupt enable */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_INTR_MASK
value|0x7058
end_define

begin_comment
comment|/* RTC interrupt mask */
end_comment

begin_comment
comment|/* AR9280: rf long shift registers */
end_comment

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0
value|0x7810
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0
value|0x7818
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1
value|0x7834
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1
value|0x783C
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2
value|0x7894
end_define

begin_define
define|#
directive|define
name|AR_AN_SYNTH9
value|0x7868
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1
value|0x7820
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2
value|0x7824
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3
value|0x7828
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4
value|0x782C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6
value|0x7834
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7
value|0x7838
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G8
value|0x783C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G9
value|0x7840
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1
value|0x7854
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP2
value|0x7868
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3
value|0x786c
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP4
value|0x7870
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP4_DEFAULT
value|0x10142c00
end_define

begin_define
define|#
directive|define
name|AR_RESET_TSF
value|0x8020
end_define

begin_define
define|#
directive|define
name|AR_RXFIFO_CFG
value|0x8114
end_define

begin_define
define|#
directive|define
name|AR_PHY_ERR_1
value|0x812c
end_define

begin_define
define|#
directive|define
name|AR_PHY_ERR_MASK_1
value|0x8130
end_define

begin_comment
comment|/* mask for AR_PHY_ERR_1 */
end_comment

begin_define
define|#
directive|define
name|AR_PHY_ERR_2
value|0x8134
end_define

begin_define
define|#
directive|define
name|AR_PHY_ERR_MASK_2
value|0x8138
end_define

begin_comment
comment|/* mask for AR_PHY_ERR_2 */
end_comment

begin_define
define|#
directive|define
name|AR_TSFOOR_THRESHOLD
value|0x813c
end_define

begin_define
define|#
directive|define
name|AR_PHY_ERR_3
value|0x8168
end_define

begin_define
define|#
directive|define
name|AR_PHY_ERR_MASK_3
value|0x816c
end_define

begin_comment
comment|/* mask for AR_PHY_ERR_3 */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_X
value|0x81ec
end_define

begin_comment
comment|/* txop for legacy non-qos */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_0_3
value|0x81f0
end_define

begin_comment
comment|/* txop for various tid's */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_4_7
value|0x81f4
end_define

begin_define
define|#
directive|define
name|AR_TXOP_8_11
value|0x81f8
end_define

begin_define
define|#
directive|define
name|AR_TXOP_12_15
value|0x81fc
end_define

begin_comment
comment|/* generic timers based on tsf - all uS */
end_comment

begin_define
define|#
directive|define
name|AR_NEXT_TBTT
value|0x8200
end_define

begin_define
define|#
directive|define
name|AR_NEXT_DBA
value|0x8204
end_define

begin_define
define|#
directive|define
name|AR_NEXT_SWBA
value|0x8208
end_define

begin_define
define|#
directive|define
name|AR_NEXT_CFP
value|0x8208
end_define

begin_define
define|#
directive|define
name|AR_NEXT_HCF
value|0x820C
end_define

begin_define
define|#
directive|define
name|AR_NEXT_TIM
value|0x8210
end_define

begin_define
define|#
directive|define
name|AR_NEXT_DTIM
value|0x8214
end_define

begin_define
define|#
directive|define
name|AR_NEXT_QUIET
value|0x8218
end_define

begin_define
define|#
directive|define
name|AR_NEXT_NDP
value|0x821C
end_define

begin_define
define|#
directive|define
name|AR5416_BEACON_PERIOD
value|0x8220
end_define

begin_define
define|#
directive|define
name|AR_DBA_PERIOD
value|0x8224
end_define

begin_define
define|#
directive|define
name|AR_SWBA_PERIOD
value|0x8228
end_define

begin_define
define|#
directive|define
name|AR_HCF_PERIOD
value|0x822C
end_define

begin_define
define|#
directive|define
name|AR_TIM_PERIOD
value|0x8230
end_define

begin_define
define|#
directive|define
name|AR_DTIM_PERIOD
value|0x8234
end_define

begin_define
define|#
directive|define
name|AR_QUIET_PERIOD
value|0x8238
end_define

begin_define
define|#
directive|define
name|AR_NDP_PERIOD
value|0x823C
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE
value|0x8240
end_define

begin_define
define|#
directive|define
name|AR_SLP32_MODE
value|0x8244
end_define

begin_define
define|#
directive|define
name|AR_SLP32_WAKE
value|0x8248
end_define

begin_define
define|#
directive|define
name|AR_SLP32_INC
value|0x824c
end_define

begin_define
define|#
directive|define
name|AR_SLP_CNT
value|0x8250
end_define

begin_comment
comment|/* 32kHz cycles with mac asleep */
end_comment

begin_define
define|#
directive|define
name|AR_SLP_CYCLE_CNT
value|0x8254
end_define

begin_comment
comment|/* absolute number of 32kHz cycles */
end_comment

begin_define
define|#
directive|define
name|AR_SLP_MIB_CTRL
value|0x8258
end_define

begin_define
define|#
directive|define
name|AR_2040_MODE
value|0x8318
end_define

begin_define
define|#
directive|define
name|AR_EXTRCCNT
value|0x8328
end_define

begin_comment
comment|/* extension channel rx clear count */
end_comment

begin_define
define|#
directive|define
name|AR_SELFGEN_MASK
value|0x832c
end_define

begin_comment
comment|/* rx and cal chain masks */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_TXBUF_CTRL
value|0x8340
end_define

begin_comment
comment|/* DMA& PCI Registers in PCI space (usable during sleep)*/
end_comment

begin_define
define|#
directive|define
name|AR_RC_AHB
value|0x00000001
end_define

begin_comment
comment|/* AHB reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_APB
value|0x00000002
end_define

begin_comment
comment|/* APB reset */
end_comment

begin_define
define|#
directive|define
name|AR_RC_HOSTIF
value|0x00000100
end_define

begin_comment
comment|/* host interface reset */
end_comment

begin_define
define|#
directive|define
name|AR_MIRT_VAL
value|0x0000ffff
end_define

begin_comment
comment|/* in uS */
end_comment

begin_define
define|#
directive|define
name|AR_MIRT_VAL_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_TIMT_LAST
value|0x0000ffff
end_define

begin_comment
comment|/* Last packet threshold */
end_comment

begin_define
define|#
directive|define
name|AR_TIMT_LAST_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_TIMT_FIRST
value|0xffff0000
end_define

begin_comment
comment|/* First packet threshold */
end_comment

begin_define
define|#
directive|define
name|AR_TIMT_FIRST_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_RIMT_LAST
value|0x0000ffff
end_define

begin_comment
comment|/* Last packet threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RIMT_LAST_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RIMT_FIRST
value|0xffff0000
end_define

begin_comment
comment|/* First packet threshold */
end_comment

begin_define
define|#
directive|define
name|AR_RIMT_FIRST_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_GTXTO_TIMEOUT_COUNTER
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for timeout counter (in TUs)
end_comment

begin_define
define|#
directive|define
name|AR_GTXTO_TIMEOUT_LIMIT
value|0xFFFF0000
end_define

begin_comment
comment|// Mask for timeout limit (in  TUs)
end_comment

begin_define
define|#
directive|define
name|AR_GTXTO_TIMEOUT_LIMIT_S
value|16
end_define

begin_comment
comment|// Shift for timeout limit
end_comment

begin_define
define|#
directive|define
name|AR_GTTM_USEC
value|0x00000001
end_define

begin_comment
comment|// usec strobe
end_comment

begin_define
define|#
directive|define
name|AR_GTTM_IGNORE_IDLE
value|0x00000002
end_define

begin_comment
comment|// ignore channel idle
end_comment

begin_define
define|#
directive|define
name|AR_GTTM_RESET_IDLE
value|0x00000004
end_define

begin_comment
comment|// reset counter on channel idle low
end_comment

begin_define
define|#
directive|define
name|AR_GTTM_CST_USEC
value|0x00000008
end_define

begin_comment
comment|// CST usec strobe
end_comment

begin_define
define|#
directive|define
name|AR_CST_TIMEOUT_COUNTER
value|0x0000FFFF
end_define

begin_comment
comment|// Mask for timeout counter (in TUs)
end_comment

begin_define
define|#
directive|define
name|AR_CST_TIMEOUT_LIMIT
value|0xFFFF0000
end_define

begin_comment
comment|// Mask for timeout limit (in  TUs)
end_comment

begin_define
define|#
directive|define
name|AR_CST_TIMEOUT_LIMIT_S
value|16
end_define

begin_comment
comment|// Shift for timeout limit
end_comment

begin_comment
comment|/* MAC tx DMA size config  */
end_comment

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_4B
value|0
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_8B
value|1
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_16B
value|2
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_32B
value|3
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_64B
value|4
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_128B
value|5
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_256B
value|6
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_DMASZ_512B
value|7
end_define

begin_define
define|#
directive|define
name|AR_TXCFG_ATIM_TXPOLICY
value|0x00000800
end_define

begin_comment
comment|/* MAC rx DMA size config  */
end_comment

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_4B
value|0
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_8B
value|1
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_16B
value|2
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_32B
value|3
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_64B
value|4
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_128B
value|5
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_256B
value|6
end_define

begin_define
define|#
directive|define
name|AR_RXCFG_DMASZ_512B
value|7
end_define

begin_comment
comment|/* MAC Led registers */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_BLINK_SLOW
value|0x00000008
end_define

begin_comment
comment|/* LED slowest blink rate mode */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_BLINK_THRESH_SEL
value|0x00000070
end_define

begin_comment
comment|/* LED blink threshold select */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_MODE
value|0x00000380
end_define

begin_comment
comment|/* LED mode select */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_MODE_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_MAC_LED_MODE_PROP
value|0
end_define

begin_comment
comment|/* Blink prop to filtered tx/rx */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_MODE_RPROP
value|1
end_define

begin_comment
comment|/* Blink prop to unfiltered tx/rx */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_MODE_SPLIT
value|2
end_define

begin_comment
comment|/* Blink power for tx/net for rx */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_MODE_RAND
value|3
end_define

begin_comment
comment|/* Blink randomly */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_MODE_POWON
value|5
end_define

begin_comment
comment|/* Power LED on (s/w control) */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_MODE_NETON
value|6
end_define

begin_comment
comment|/* Network LED on (s/w control) */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_ASSOC
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|AR_MAC_LED_ASSOC_NONE
value|0x00000000
end_define

begin_comment
comment|/* STA is not associated or trying */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_ASSOC_ACTIVE
value|0x00000400
end_define

begin_comment
comment|/* STA is associated */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_ASSOC_PEND
value|0x00000800
end_define

begin_comment
comment|/* STA is trying to associate */
end_comment

begin_define
define|#
directive|define
name|AR_MAC_LED_ASSOC_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_WA_UNTIE_RESET_EN
value|0x00008000
end_define

begin_comment
comment|/* ena PCI reset to POR */
end_comment

begin_define
define|#
directive|define
name|AR_WA_RESET_EN
value|0x00040000
end_define

begin_comment
comment|/* ena AR_WA_UNTIE_RESET_EN */
end_comment

begin_define
define|#
directive|define
name|AR_WA_ANALOG_SHIFT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_WA_POR_SHORT
value|0x00200000
end_define

begin_comment
comment|/* PCIE phy reset control */
end_comment

begin_define
define|#
directive|define
name|AR_WA_DEFAULT
value|0x0000073f
end_define

begin_define
define|#
directive|define
name|AR9280_WA_DEFAULT
value|0x0040073f
end_define

begin_define
define|#
directive|define
name|AR9285_WA_DEFAULT
value|0x004a05cb
end_define

begin_define
define|#
directive|define
name|AR_PCIE_PM_CTRL_ENA
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_AHB_EXACT_WR_EN
value|0x00000000
end_define

begin_comment
comment|/* write exact bytes */
end_comment

begin_define
define|#
directive|define
name|AR_AHB_BUF_WR_EN
value|0x00000001
end_define

begin_comment
comment|/* buffer write upto cacheline*/
end_comment

begin_define
define|#
directive|define
name|AR_AHB_EXACT_RD_EN
value|0x00000000
end_define

begin_comment
comment|/* read exact bytes */
end_comment

begin_define
define|#
directive|define
name|AR_AHB_CACHELINE_RD_EN
value|0x00000002
end_define

begin_comment
comment|/* read upto end of cacheline */
end_comment

begin_define
define|#
directive|define
name|AR_AHB_PREFETCH_RD_EN
value|0x00000004
end_define

begin_comment
comment|/* prefetch upto page boundary*/
end_comment

begin_define
define|#
directive|define
name|AR_AHB_PAGE_SIZE_1K
value|0x00000000
end_define

begin_comment
comment|/* set page-size as 1k */
end_comment

begin_define
define|#
directive|define
name|AR_AHB_PAGE_SIZE_2K
value|0x00000008
end_define

begin_comment
comment|/* set page-size as 2k */
end_comment

begin_define
define|#
directive|define
name|AR_AHB_PAGE_SIZE_4K
value|0x00000010
end_define

begin_comment
comment|/* set page-size as 4k */
end_comment

begin_comment
comment|/* MAC PCU Registers */
end_comment

begin_define
define|#
directive|define
name|AR_STA_ID1_PRESERVE_SEQNUM
value|0x20000000
end_define

begin_comment
comment|/* Don't replace seq num */
end_comment

begin_comment
comment|/* Extended PCU DIAG_SW control fields */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_DUAL_CHAIN_INFO
value|0x01000000
end_define

begin_comment
comment|/* dual chain channel info */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_RX_ABORT
value|0x02000000
end_define

begin_comment
comment|/* abort rx */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_SATURATE_CCNT
value|0x04000000
end_define

begin_comment
comment|/* sat. cycle cnts (no shift) */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_OBS_PT_SEL2
value|0x08000000
end_define

begin_comment
comment|/* observation point sel */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_RXCLEAR_CTL_LOW
value|0x10000000
end_define

begin_comment
comment|/* force rx_clear(ctl) low/busy */
end_comment

begin_define
define|#
directive|define
name|AR_DIAG_RXCLEAR_EXT_LOW
value|0x20000000
end_define

begin_comment
comment|/* force rx_clear(ext) low/busy */
end_comment

begin_define
define|#
directive|define
name|AR_TXOP_X_VAL
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|AR_RESET_TSF_ONCE
value|0x01000000
end_define

begin_comment
comment|/* reset tsf once; self-clears*/
end_comment

begin_comment
comment|/* Interrupts */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXMINTR
value|0x00080000
end_define

begin_comment
comment|/* Maximum interrupt tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXMINTR
value|0x01000000
end_define

begin_comment
comment|/* Maximum interrupt rx rate */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_TXINTM
value|0x40000000
end_define

begin_comment
comment|/* Tx int after mitigation */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_RXINTM
value|0x80000000
end_define

begin_comment
comment|/* Rx int after mitigation */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_CST
value|0x00400000
end_define

begin_comment
comment|/* Carrier sense timeout */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_GTT
value|0x00800000
end_define

begin_comment
comment|/* Global transmit timeout */
end_comment

begin_define
define|#
directive|define
name|AR_ISR_S2_TSFOOR
value|0x40000000
end_define

begin_comment
comment|/* RX TSF out of range */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SPURIOUS
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|AR_INTR_RTC_IRQ
value|0x00000001
end_define

begin_comment
comment|/* rtc in shutdown state */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_MAC_IRQ
value|0x00000002
end_define

begin_comment
comment|/* pending mac interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_EEP_PROT_ACCESS
value|0x00000004
end_define

begin_comment
comment|/* eeprom protected access */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_MAC_AWAKE
value|0x00020000
end_define

begin_comment
comment|/* mac is awake */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_MAC_ASLEEP
value|0x00040000
end_define

begin_comment
comment|/* mac is asleep */
end_comment

begin_comment
comment|/* Interrupt Mask Registers */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXMINTR
value|0x00080000
end_define

begin_comment
comment|/* Maximum interrupt tx rate */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXMINTR
value|0x01000000
end_define

begin_comment
comment|/* Maximum interrupt rx rate */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_TXINTM
value|0x40000000
end_define

begin_comment
comment|/* Tx int after mitigation */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_RXINTM
value|0x80000000
end_define

begin_comment
comment|/* Rx int after mitigation */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_CST
value|0x00400000
end_define

begin_comment
comment|/* Carrier sense timeout */
end_comment

begin_define
define|#
directive|define
name|AR_IMR_S2_GTT
value|0x00800000
end_define

begin_comment
comment|/* Global transmit timeout */
end_comment

begin_comment
comment|/* synchronous interrupt signals */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_RTC_IRQ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MAC_IRQ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_EEPROM_ILLEGAL_ACCESS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_APB_TIMEOUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_PCI_MODE_CONFLICT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_HOST1_FATAL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_HOST1_PERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_TRCV_FIFO_PERR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_RADM_CPL_EP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_RADM_CPL_DLLP_ABORT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_RADM_CPL_TLP_ABORT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_RADM_CPL_ECRC_ERR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_RADM_CPL_TIMEOUT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_LOCAL_TIMEOUT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_PM_ACCESS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MAC_AWAKE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MAC_ASLEEP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MAC_SLEEP_ACCESS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_ALL
value|0x0003FFFF
end_define

begin_comment
comment|/* default synchronous interrupt signals enabled */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_SYNC_DEFAULT
define|\
value|(AR_INTR_SYNC_HOST1_FATAL | AR_INTR_SYNC_HOST1_PERR | \ 	 AR_INTR_SYNC_RADM_CPL_EP | AR_INTR_SYNC_RADM_CPL_DLLP_ABORT | \ 	 AR_INTR_SYNC_RADM_CPL_TLP_ABORT | AR_INTR_SYNC_RADM_CPL_ECRC_ERR | \ 	 AR_INTR_SYNC_RADM_CPL_TIMEOUT | AR_INTR_SYNC_LOCAL_TIMEOUT | \ 	 AR_INTR_SYNC_MAC_SLEEP_ACCESS)
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MASK_GPIO
value|0xFFFC0000
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_MASK_GPIO_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_ENABLE_GPIO
value|0xFFFC0000
end_define

begin_define
define|#
directive|define
name|AR_INTR_SYNC_ENABLE_GPIO_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_MASK_GPIO
value|0xFFFC0000
end_define

begin_comment
comment|/* async int mask */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_MASK_GPIO_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_CAUSE_GPIO
value|0xFFFC0000
end_define

begin_comment
comment|/* GPIO interrupts */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_USED
value|(AR_INTR_MAC_IRQ | AR_INTR_ASYNC_CAUSE_GPIO)
end_define

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_ENABLE_GPIO
value|0xFFFC0000
end_define

begin_comment
comment|/* enable interrupts */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_ASYNC_ENABLE_GPIO_S
value|18
end_define

begin_comment
comment|/* RTC registers */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_RC_M
value|0x00000003
end_define

begin_define
define|#
directive|define
name|AR_RTC_RC_MAC_WARM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_RTC_RC_MAC_COLD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_DIV
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_DIV_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_DIV2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_REFDIV_5
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|AR_RTC_SOWL_PLL_DIV
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|AR_RTC_SOWL_PLL_DIV_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_RTC_SOWL_PLL_REFDIV
value|0x00003C00
end_define

begin_define
define|#
directive|define
name|AR_RTC_SOWL_PLL_REFDIV_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_RTC_SOWL_PLL_CLKSEL
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|AR_RTC_SOWL_PLL_CLKSEL_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_RTC_RESET_EN
value|0x00000001
end_define

begin_comment
comment|/* Reset RTC bit */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_PM_STATUS_M
value|0x0000000f
end_define

begin_comment
comment|/* Pwr Mgmt Status */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_STATUS_M
value|0x0000003f
end_define

begin_comment
comment|/* RTC Status */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_STATUS_SHUTDOWN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_ON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_SLEEP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_WAKEUP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_RTC_STATUS_COLDRESET
value|0x00000010
end_define

begin_comment
comment|/* Not currently used */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_STATUS_PLLCHANGE
value|0x00000020
end_define

begin_comment
comment|/* Not currently used */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_SLEEP_DERIVED_CLK
value|0x2
end_define

begin_define
define|#
directive|define
name|AR_RTC_FORCE_WAKE_EN
value|0x00000001
end_define

begin_comment
comment|/* enable force wake */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_FORCE_WAKE_ON_INT
value|0x00000002
end_define

begin_comment
comment|/* auto-wake on MAC interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_RTC_PLL_CLKSEL
value|0x00000300
end_define

begin_define
define|#
directive|define
name|AR_RTC_PLL_CLKSEL_S
value|8
end_define

begin_comment
comment|/* AR9280: rf long shift registers */
end_comment

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0_OB
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0_OB_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0_DB
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH0_DB_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0_OB5
value|0x00070000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0_OB5_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0_DB5
value|0x00380000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH0_DB5_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1_OB
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1_OB_S
value|23
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1_DB
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF2G1_CH1_DB_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1_OB5
value|0x00070000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1_OB5_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1_DB5
value|0x00380000
end_define

begin_define
define|#
directive|define
name|AR_AN_RF5G1_CH1_DB5_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_XPABIAS_LVL
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_XPABIAS_LVL_S
value|30
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_LOCALBIAS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_LOCALBIAS_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_PWDCLKIND
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AR_AN_TOP2_PWDCLKIND_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_AN_SYNTH9_REFDIVA
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|AR_AN_SYNTH9_REFDIVA_S
value|27
end_define

begin_comment
comment|/* AR9285 Analog registers */
end_comment

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_ENPACAL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_ENPACAL_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV1
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV1_S
value|25
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV2
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPADRV2_S
value|24
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPAOUT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G1_PDPAOUT_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2_OFFCAL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G2_OFFCAL_S
value|12
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_PDVCCOMP
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_PDVCCOMP_S
value|25
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_0
value|0x00E00000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_0_S
value|21
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_1
value|0x001C0000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_1_S
value|18
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_2
value|0x00038000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_2_S
value|15
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_3
value|0x00007000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_3_S
value|12
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_4
value|0x00000E00
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_OB_4_S
value|9
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_0
value|0x000001C0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_0_S
value|6
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_1
value|0x00000038
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_1_S
value|3
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_2
value|0x00000007
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G3_DB1_2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_3
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_3_S
value|29
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_4
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB1_4_S
value|26
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_0
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_0_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_1
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_1_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_2
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_2_S
value|17
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_3
value|0x0001C000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_3_S
value|14
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_4
value|0x00003800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G4_DB2_4_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6_CCOMP
value|0x00007800
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6_CCOMP_S
value|11
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6_OFFS
value|0x03f00000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G6_OFFS_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9271_AN_RF2G6_OFFS
value|0x07f00000
end_define

begin_define
define|#
directive|define
name|AR9271_AN_RF2G6_OFFS_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7_PWDDB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7_PWDDB_S
value|1
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7_PADRVGN2TAB0
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G7_PADRVGN2TAB0_S
value|29
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G8_PADRVGN2TAB0
value|0x0001C000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RF2G8_PADRVGN2TAB0_S
value|14
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDRXTXBB1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDRXTXBB1_S
value|5
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDV2I
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDV2I_S
value|7
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDDACIF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_PDDACIF_S
value|8
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_SPARE9
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR9285_AN_RXTXBB1_SPARE9_S
value|0
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_XPABIAS_LVL
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_XPABIAS_LVL_S
value|2
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_PWDDAC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR9285_AN_TOP3_PWDDAC_S
value|23
end_define

begin_comment
comment|/* Sleep control */
end_comment

begin_define
define|#
directive|define
name|AR5416_SLEEP1_CAB_TIMEOUT
value|0xFFE00000
end_define

begin_comment
comment|/* Cab timeout (TU) */
end_comment

begin_define
define|#
directive|define
name|AR5416_SLEEP1_CAB_TIMEOUT_S
value|22
end_define

begin_define
define|#
directive|define
name|AR5416_SLEEP2_BEACON_TIMEOUT
value|0xFFE00000
end_define

begin_comment
comment|/* Beacon timeout (TU)*/
end_comment

begin_define
define|#
directive|define
name|AR5416_SLEEP2_BEACON_TIMEOUT_S
value|22
end_define

begin_comment
comment|/* Sleep Registers */
end_comment

begin_define
define|#
directive|define
name|AR_SLP32_HALFCLK_LATENCY
value|0x000FFFFF
end_define

begin_comment
comment|/* rising<-> falling edge */
end_comment

begin_define
define|#
directive|define
name|AR_SLP32_ENA
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AR_SLP32_TSF_WRITE_STATUS
value|0x00200000
end_define

begin_comment
comment|/* tsf update in progress */
end_comment

begin_define
define|#
directive|define
name|AR_SLP32_WAKE_XTL_TIME
value|0x0000FFFF
end_define

begin_comment
comment|/* time to wake crystal */
end_comment

begin_define
define|#
directive|define
name|AR_SLP32_TST_INC
value|0x000FFFFF
end_define

begin_define
define|#
directive|define
name|AR_SLP_MIB_CLEAR
value|0x00000001
end_define

begin_comment
comment|/* clear pending */
end_comment

begin_define
define|#
directive|define
name|AR_SLP_MIB_PENDING
value|0x00000002
end_define

begin_comment
comment|/* clear counters */
end_comment

begin_define
define|#
directive|define
name|AR_TIMER_MODE_TBTT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_DBA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_SWBA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_HCF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_TIM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_DTIM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_QUIET
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_NDP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_OVERFLOW_INDEX
value|0x00000700
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_OVERFLOW_INDEX_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_THRESH
value|0xFFFFF000
end_define

begin_define
define|#
directive|define
name|AR_TIMER_MODE_THRESH_S
value|12
end_define

begin_comment
comment|/* PCU Misc modes */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_FORCE_BSSID_MATCH
value|0x00000001
end_define

begin_comment
comment|/* force bssid to match */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MIC_NEW_LOC_ENA
value|0x00000004
end_define

begin_comment
comment|/* tx/rx mic keys together */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_TX_ADD_TSF
value|0x00000008
end_define

begin_comment
comment|/* add tx_tsf + int_tsf */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_CCK_SIFS_MODE
value|0x00000010
end_define

begin_comment
comment|/* assume 11b sifs */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_RX_ANT_UPDT
value|0x00000800
end_define

begin_comment
comment|/* KC_RX_ANT_UPDATE */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_TXOP_TBTT_LIMIT_ENA
value|0x00001000
end_define

begin_comment
comment|/* enforce txop / tbtt */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_MISS_BCN_IN_SLEEP
value|0x00004000
end_define

begin_comment
comment|/* count bmiss's when sleeping */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_BUG_12306_FIX_ENA
value|0x00020000
end_define

begin_comment
comment|/* use rx_clear to count sifs */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_FORCE_QUIET_COLL
value|0x00040000
end_define

begin_comment
comment|/* kill xmit for channel change */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_TBTT_PROTECT
value|0x00200000
end_define

begin_comment
comment|/* no xmit upto tbtt+20 uS */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_CLEAR_VMF
value|0x01000000
end_define

begin_comment
comment|/* clear vmf mode (fast cc)*/
end_comment

begin_define
define|#
directive|define
name|AR_PCU_CLEAR_BA_VALID
value|0x04000000
end_define

begin_comment
comment|/* clear ba state */
end_comment

begin_comment
comment|/* GPIO Interrupt */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_GPIO
value|0x3FF00000
end_define

begin_comment
comment|/* gpio interrupted */
end_comment

begin_define
define|#
directive|define
name|AR_INTR_GPIO_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUT_CTRL
value|0x000003FF
end_define

begin_comment
comment|/* 0 = out, 1 = in */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OUT_VAL
value|0x000FFC00
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OUT_VAL_S
value|10
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INTR_CTRL
value|0x3FF00000
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INTR_CTRL_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_GPIO_IN_VAL
value|0x0FFFC000
end_define

begin_comment
comment|/* pre-9280 */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_IN_VAL_S
value|14
end_define

begin_define
define|#
directive|define
name|AR928X_GPIO_IN_VAL
value|0x000FFC00
end_define

begin_define
define|#
directive|define
name|AR928X_GPIO_IN_VAL_S
value|10
end_define

begin_define
define|#
directive|define
name|AR9285_GPIO_IN_VAL
value|0x00FFF000
end_define

begin_define
define|#
directive|define
name|AR9285_GPIO_IN_VAL_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV
value|0x3
end_define

begin_comment
comment|/* 2 bit mask shifted by 2*bitpos */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV_NO
value|0x0
end_define

begin_comment
comment|/* tristate */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV_LOW
value|0x1
end_define

begin_comment
comment|/* drive if low */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV_HI
value|0x2
end_define

begin_comment
comment|/* drive if high */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_OE_OUT_DRV_ALL
value|0x3
end_define

begin_comment
comment|/* drive always */
end_comment

begin_define
define|#
directive|define
name|AR_GPIO_INTR_POL_VAL
value|0x1FFF
end_define

begin_define
define|#
directive|define
name|AR_GPIO_INTR_POL_VAL_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_2040_JOINED_RX_CLEAR
value|0x00000001
end_define

begin_comment
comment|/* use ctl + ext rx_clear for cca */
end_comment

begin_define
define|#
directive|define
name|AR_PCU_TXBUF_CTRL_SIZE_MASK
value|0x7FF
end_define

begin_define
define|#
directive|define
name|AR_PCU_TXBUF_CTRL_USABLE_SIZE
value|0x700
end_define

begin_define
define|#
directive|define
name|AR_9285_PCU_TXBUF_CTRL_USABLE_SIZE
value|0x380
end_define

begin_comment
comment|/* Eeprom defines */
end_comment

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_VAL
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_VAL_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_BUSY
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_BUSY_ACCESS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_PROT_ACCESS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_EEPROM_STATUS_DATA_ABSENT_ACCESS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_SREV_REVISION_OWL_10
value|0x08
end_define

begin_define
define|#
directive|define
name|AR_SREV_REVISION_OWL_20
value|0x09
end_define

begin_define
define|#
directive|define
name|AR_SREV_REVISION_OWL_22
value|0x0a
end_define

begin_define
define|#
directive|define
name|AR_RAD5133_SREV_MAJOR
value|0xc0
end_define

begin_comment
comment|/* Fowl: 2+5G/3x3 */
end_comment

begin_define
define|#
directive|define
name|AR_RAD2133_SREV_MAJOR
value|0xd0
end_define

begin_comment
comment|/* Fowl: 2G/3x3   */
end_comment

begin_define
define|#
directive|define
name|AR_RAD5122_SREV_MAJOR
value|0xe0
end_define

begin_comment
comment|/* Fowl: 5G/2x2   */
end_comment

begin_define
define|#
directive|define
name|AR_RAD2122_SREV_MAJOR
value|0xf0
end_define

begin_comment
comment|/* Fowl: 2+5G/2x2 */
end_comment

begin_comment
comment|/* Test macro for owl 1.0 */
end_comment

begin_define
define|#
directive|define
name|IS_5416V1
parameter_list|(
name|_ah
parameter_list|)
value|((_ah)->ah_macRev == AR_SREV_REVISION_OWL_10)
end_define

begin_define
define|#
directive|define
name|IS_5416V2
parameter_list|(
name|_ah
parameter_list|)
value|((_ah)->ah_macRev>= AR_SREV_REVISION_OWL_20)
end_define

begin_define
define|#
directive|define
name|IS_5416V2_2
parameter_list|(
name|_ah
parameter_list|)
value|((_ah)->ah_macRev == AR_SREV_REVISION_OWL_22)
end_define

begin_comment
comment|/* Expanded Mac Silicon Rev (16 bits starting with Sowl) */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_ID
value|0xFFFFFFFF
end_define

begin_comment
comment|/* Chip ID */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_ID_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_XSREV_VERSION
value|0xFFFC0000
end_define

begin_comment
comment|/* Chip version */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_VERSION_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_XSREV_TYPE
value|0x0003F000
end_define

begin_comment
comment|/* Chip type */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_TYPE_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_XSREV_TYPE_CHAIN
value|0x00001000
end_define

begin_comment
comment|/* Chain Mode (1:3 chains, 						 * 0:2 chains) */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_TYPE_HOST_MODE
value|0x00002000
end_define

begin_comment
comment|/* Host Mode (1:PCI, 0:PCIe) */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_XSREV_VERSION_OWL_PCI
value|0x0D
end_define

begin_define
define|#
directive|define
name|AR_XSREV_VERSION_OWL_PCIE
value|0x0C
end_define

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_OWL_10
value|0
end_define

begin_comment
comment|/* Owl 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_OWL_20
value|1
end_define

begin_comment
comment|/* Owl 2.0/2.1 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_OWL_22
value|2
end_define

begin_comment
comment|/* Owl 2.2 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_VERSION_SOWL
value|0x40
end_define

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_SOWL_10
value|0
end_define

begin_comment
comment|/* Sowl 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_SOWL_11
value|1
end_define

begin_comment
comment|/* Sowl 1.1 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_VERSION_MERLIN
value|0x80
end_define

begin_comment
comment|/* Merlin Version */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_MERLIN_10
value|0
end_define

begin_comment
comment|/* Merlin 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_MERLIN_20
value|1
end_define

begin_comment
comment|/* Merlin 2.0 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_MERLIN_21
value|2
end_define

begin_comment
comment|/* Merlin 2.1 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_VERSION_KITE
value|0xC0
end_define

begin_comment
comment|/* Kite Version */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_KITE_10
value|0
end_define

begin_comment
comment|/* Kite 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_KITE_11
value|1
end_define

begin_comment
comment|/* Kite 1.1 */
end_comment

begin_define
define|#
directive|define
name|AR_XSREV_REVISION_KITE_12
value|2
end_define

begin_comment
comment|/* Kite 1.2 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_OWL_20_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion>= AR_XSREV_VERSION_SOWL || \ 	 AH_PRIVATE((_ah))->ah_macRev>= AR_XSREV_REVISION_OWL_20)
end_define

begin_define
define|#
directive|define
name|AR_SREV_OWL_22_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion>= AR_XSREV_VERSION_SOWL || \ 	 AH_PRIVATE((_ah))->ah_macRev>= AR_XSREV_REVISION_OWL_22)
end_define

begin_define
define|#
directive|define
name|AR_SREV_SOWL
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion == AR_XSREV_VERSION_SOWL)
end_define

begin_define
define|#
directive|define
name|AR_SREV_SOWL_10_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion>= AR_XSREV_VERSION_SOWL)
end_define

begin_define
define|#
directive|define
name|AR_SREV_SOWL_11
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_SOWL(_ah)&& \ 	 AH_PRIVATE((_ah))->ah_macRev == AR_XSREV_REVISION_SOWL_11)
end_define

begin_define
define|#
directive|define
name|AR_SREV_MERLIN
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion == AR_XSREV_VERSION_MERLIN)
end_define

begin_define
define|#
directive|define
name|AR_SREV_MERLIN_10_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion>= AR_XSREV_VERSION_MERLIN)
end_define

begin_define
define|#
directive|define
name|AR_SREV_MERLIN_20
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_MERLIN(_ah)&& \ 	 AH_PRIVATE((_ah))->ah_macRev>= AR_XSREV_REVISION_MERLIN_20)
end_define

begin_define
define|#
directive|define
name|AR_SREV_MERLIN_20_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_MERLIN_20(_ah) || \ 	 AH_PRIVATE((_ah))->ah_macVersion> AR_XSREV_VERSION_MERLIN)
end_define

begin_define
define|#
directive|define
name|AR_SREV_KITE
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion == AR_XSREV_VERSION_KITE)
end_define

begin_define
define|#
directive|define
name|AR_SREV_KITE_10_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion>= AR_XSREV_VERSION_KITE)
end_define

begin_define
define|#
directive|define
name|AR_SREV_KITE_11
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_KITE(ah)&& \ 	 AH_PRIVATE((_ah))->ah_macRev == AR_XSREV_REVISION_KITE_11)
end_define

begin_define
define|#
directive|define
name|AR_SREV_KITE_11_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion>= AR_XSREV_VERSION_KITE || \ 	 AH_PRIVATE((_ah))->ah_macRev>= AR_XSREV_REVISION_KITE_11)
end_define

begin_define
define|#
directive|define
name|AR_SREV_KITE_12
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AR_SREV_KITE(ah)&& \ 	 AH_PRIVATE((_ah))->ah_macRev == AR_XSREV_REVISION_KITE_12)
end_define

begin_define
define|#
directive|define
name|AR_SREV_KITE_12_OR_LATER
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(AH_PRIVATE((_ah))->ah_macVersion>= AR_XSREV_VERSION_KITE || \ 	 AH_PRIVATE((_ah))->ah_macRev>= AR_XSREV_REVISION_KITE_12)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5416REG_H */
end_comment

end_unit

