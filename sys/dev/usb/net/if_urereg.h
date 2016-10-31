begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Kevin Lo<kevlo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|URE_CONFIG_IDX
value|0
end_define

begin_comment
comment|/* config number 1 */
end_comment

begin_define
define|#
directive|define
name|URE_IFACE_IDX
value|0
end_define

begin_define
define|#
directive|define
name|URE_CTL_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|URE_CTL_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|URE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|URE_PHY_TIMEOUT
value|2000
end_define

begin_define
define|#
directive|define
name|URE_BYTE_EN_DWORD
value|0xff
end_define

begin_define
define|#
directive|define
name|URE_BYTE_EN_WORD
value|0x33
end_define

begin_define
define|#
directive|define
name|URE_BYTE_EN_BYTE
value|0x11
end_define

begin_define
define|#
directive|define
name|URE_BYTE_EN_SIX_BYTES
value|0x3f
end_define

begin_define
define|#
directive|define
name|URE_MAX_FRAMELEN
value|(ETHER_MAX_LEN + ETHER_VLAN_ENCAP_LEN)
end_define

begin_define
define|#
directive|define
name|URE_PLA_IDR
value|0xc000
end_define

begin_define
define|#
directive|define
name|URE_PLA_RCR
value|0xc010
end_define

begin_define
define|#
directive|define
name|URE_PLA_RMS
value|0xc016
end_define

begin_define
define|#
directive|define
name|URE_PLA_RXFIFO_CTRL0
value|0xc0a0
end_define

begin_define
define|#
directive|define
name|URE_PLA_RXFIFO_CTRL1
value|0xc0a4
end_define

begin_define
define|#
directive|define
name|URE_PLA_RXFIFO_CTRL2
value|0xc0a8
end_define

begin_define
define|#
directive|define
name|URE_PLA_DMY_REG0
value|0xc0b0
end_define

begin_define
define|#
directive|define
name|URE_PLA_FMC
value|0xc0b4
end_define

begin_define
define|#
directive|define
name|URE_PLA_CFG_WOL
value|0xc0b6
end_define

begin_define
define|#
directive|define
name|URE_PLA_TEREDO_CFG
value|0xc0bc
end_define

begin_define
define|#
directive|define
name|URE_PLA_MAR0
value|0xcd00
end_define

begin_define
define|#
directive|define
name|URE_PLA_MAR4
value|0xcd04
end_define

begin_define
define|#
directive|define
name|URE_PLA_BACKUP
value|0xd000
end_define

begin_define
define|#
directive|define
name|URE_PAL_BDC_CR
value|0xd1a0
end_define

begin_define
define|#
directive|define
name|URE_PLA_TEREDO_TIMER
value|0xd2cc
end_define

begin_define
define|#
directive|define
name|URE_PLA_REALWOW_TIMER
value|0xd2e8
end_define

begin_define
define|#
directive|define
name|URE_PLA_LEDSEL
value|0xdd90
end_define

begin_define
define|#
directive|define
name|URE_PLA_LED_FEATURE
value|0xdd92
end_define

begin_define
define|#
directive|define
name|URE_PLA_PHYAR
value|0xde00
end_define

begin_define
define|#
directive|define
name|URE_PLA_BOOT_CTRL
value|0xe004
end_define

begin_define
define|#
directive|define
name|URE_PLA_GPHY_INTR_IMR
value|0xe022
end_define

begin_define
define|#
directive|define
name|URE_PLA_EEE_CR
value|0xe040
end_define

begin_define
define|#
directive|define
name|URE_PLA_EEEP_CR
value|0xe080
end_define

begin_define
define|#
directive|define
name|URE_PLA_MAC_PWR_CTRL
value|0xe0c0
end_define

begin_define
define|#
directive|define
name|URE_PLA_MAC_PWR_CTRL2
value|0xe0ca
end_define

begin_define
define|#
directive|define
name|URE_PLA_MAC_PWR_CTRL3
value|0xe0cc
end_define

begin_define
define|#
directive|define
name|URE_PLA_MAC_PWR_CTRL4
value|0xe0ce
end_define

begin_define
define|#
directive|define
name|URE_PLA_WDT6_CTRL
value|0xe428
end_define

begin_define
define|#
directive|define
name|URE_PLA_TCR0
value|0xe610
end_define

begin_define
define|#
directive|define
name|URE_PLA_TCR1
value|0xe612
end_define

begin_define
define|#
directive|define
name|URE_PLA_MTPS
value|0xe615
end_define

begin_define
define|#
directive|define
name|URE_PLA_TXFIFO_CTRL
value|0xe618
end_define

begin_define
define|#
directive|define
name|URE_PLA_RSTTELLY
value|0xe800
end_define

begin_define
define|#
directive|define
name|URE_PLA_CR
value|0xe813
end_define

begin_define
define|#
directive|define
name|URE_PLA_CRWECR
value|0xe81c
end_define

begin_define
define|#
directive|define
name|URE_PLA_CONFIG5
value|0xe822
end_define

begin_define
define|#
directive|define
name|URE_PLA_PHY_PWR
value|0xe84c
end_define

begin_define
define|#
directive|define
name|URE_PLA_OOB_CTRL
value|0xe84f
end_define

begin_define
define|#
directive|define
name|URE_PLA_CPCR
value|0xe854
end_define

begin_define
define|#
directive|define
name|URE_PLA_MISC_0
value|0xe858
end_define

begin_define
define|#
directive|define
name|URE_PLA_MISC_1
value|0xe85a
end_define

begin_define
define|#
directive|define
name|URE_PLA_OCP_GPHY_BASE
value|0xe86c
end_define

begin_define
define|#
directive|define
name|URE_PLA_TELLYCNT
value|0xe890
end_define

begin_define
define|#
directive|define
name|URE_PLA_SFF_STS_7
value|0xe8de
end_define

begin_define
define|#
directive|define
name|URE_GMEDIASTAT
value|0xe908
end_define

begin_define
define|#
directive|define
name|URE_USB_USB2PHY
value|0xb41e
end_define

begin_define
define|#
directive|define
name|URE_USB_SSPHYLINK2
value|0xb428
end_define

begin_define
define|#
directive|define
name|URE_USB_U2P3_CTRL
value|0xb460
end_define

begin_define
define|#
directive|define
name|URE_USB_CSR_DUMMY1
value|0xb464
end_define

begin_define
define|#
directive|define
name|URE_USB_CSR_DUMMY2
value|0xb466
end_define

begin_define
define|#
directive|define
name|URE_USB_DEV_STAT
value|0xb808
end_define

begin_define
define|#
directive|define
name|URE_USB_CONNECT_TIMER
value|0xcbf8
end_define

begin_define
define|#
directive|define
name|URE_USB_BURST_SIZE
value|0xcfc0
end_define

begin_define
define|#
directive|define
name|URE_USB_USB_CTRL
value|0xd406
end_define

begin_define
define|#
directive|define
name|URE_USB_PHY_CTRL
value|0xd408
end_define

begin_define
define|#
directive|define
name|URE_USB_TX_AGG
value|0xd40a
end_define

begin_define
define|#
directive|define
name|URE_USB_RX_BUF_TH
value|0xd40c
end_define

begin_define
define|#
directive|define
name|URE_USB_USB_TIMER
value|0xd428
end_define

begin_define
define|#
directive|define
name|URE_USB_RX_EARLY_AGG
value|0xd42c
end_define

begin_define
define|#
directive|define
name|URE_USB_PM_CTRL_STATUS
value|0xd432
end_define

begin_define
define|#
directive|define
name|URE_USB_TX_DMA
value|0xd434
end_define

begin_define
define|#
directive|define
name|URE_USB_TOLERANCE
value|0xd490
end_define

begin_define
define|#
directive|define
name|URE_USB_LPM_CTRL
value|0xd41a
end_define

begin_define
define|#
directive|define
name|URE_USB_UPS_CTRL
value|0xd800
end_define

begin_define
define|#
directive|define
name|URE_USB_MISC_0
value|0xd81a
end_define

begin_define
define|#
directive|define
name|URE_USB_POWER_CUT
value|0xd80a
end_define

begin_define
define|#
directive|define
name|URE_USB_AFE_CTRL2
value|0xd824
end_define

begin_define
define|#
directive|define
name|URE_USB_WDT11_CTRL
value|0xe43c
end_define

begin_comment
comment|/* OCP Registers. */
end_comment

begin_define
define|#
directive|define
name|URE_OCP_ALDPS_CONFIG
value|0x2010
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_CONFIG1
value|0x2080
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_CONFIG2
value|0x2092
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_CONFIG3
value|0x2094
end_define

begin_define
define|#
directive|define
name|URE_OCP_BASE_MII
value|0xa400
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_AR
value|0xa41a
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_DATA
value|0xa41c
end_define

begin_define
define|#
directive|define
name|URE_OCP_PHY_STATUS
value|0xa420
end_define

begin_define
define|#
directive|define
name|URE_OCP_POWER_CFG
value|0xa430
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_CFG
value|0xa432
end_define

begin_define
define|#
directive|define
name|URE_OCP_SRAM_ADDR
value|0xa436
end_define

begin_define
define|#
directive|define
name|URE_OCP_SRAM_DATA
value|0xa438
end_define

begin_define
define|#
directive|define
name|URE_OCP_DOWN_SPEED
value|0xa442
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_ABLE
value|0xa5c4
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_ADV
value|0xa5d0
end_define

begin_define
define|#
directive|define
name|URE_OCP_EEE_LPABLE
value|0xa5d2
end_define

begin_define
define|#
directive|define
name|URE_OCP_PHY_STATE
value|0xa708
end_define

begin_define
define|#
directive|define
name|URE_OCP_ADC_CFG
value|0xbc06
end_define

begin_comment
comment|/* SRAM Register. */
end_comment

begin_define
define|#
directive|define
name|URE_SRAM_LPF_CFG
value|0x8012
end_define

begin_define
define|#
directive|define
name|URE_SRAM_10M_AMP1
value|0x8080
end_define

begin_define
define|#
directive|define
name|URE_SRAM_10M_AMP2
value|0x8082
end_define

begin_define
define|#
directive|define
name|URE_SRAM_IMPEDANCE
value|0x8084
end_define

begin_comment
comment|/* PLA_RCR */
end_comment

begin_define
define|#
directive|define
name|URE_RCR_AAP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|URE_RCR_APM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|URE_RCR_AM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|URE_RCR_AB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|URE_RCR_ACPT_ALL
define|\
value|(URE_RCR_AAP | URE_RCR_APM | URE_RCR_AM | URE_RCR_AB)
end_define

begin_comment
comment|/* PLA_RXFIFO_CTRL0 */
end_comment

begin_define
define|#
directive|define
name|URE_RXFIFO_THR1_NORMAL
value|0x00080002
end_define

begin_define
define|#
directive|define
name|URE_RXFIFO_THR1_OOB
value|0x01800003
end_define

begin_comment
comment|/* PLA_RXFIFO_CTRL1 */
end_comment

begin_define
define|#
directive|define
name|URE_RXFIFO_THR2_FULL
value|0x00000060
end_define

begin_define
define|#
directive|define
name|URE_RXFIFO_THR2_HIGH
value|0x00000038
end_define

begin_define
define|#
directive|define
name|URE_RXFIFO_THR2_OOB
value|0x0000004a
end_define

begin_define
define|#
directive|define
name|URE_RXFIFO_THR2_NORMAL
value|0x00a0
end_define

begin_comment
comment|/* PLA_RXFIFO_CTRL2 */
end_comment

begin_define
define|#
directive|define
name|URE_RXFIFO_THR3_FULL
value|0x00000078
end_define

begin_define
define|#
directive|define
name|URE_RXFIFO_THR3_HIGH
value|0x00000048
end_define

begin_define
define|#
directive|define
name|URE_RXFIFO_THR3_OOB
value|0x0000005a
end_define

begin_define
define|#
directive|define
name|URE_RXFIFO_THR3_NORMAL
value|0x0110
end_define

begin_comment
comment|/* PLA_TXFIFO_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_TXFIFO_THR_NORMAL
value|0x00400008
end_define

begin_define
define|#
directive|define
name|URE_TXFIFO_THR_NORMAL2
value|0x01000008
end_define

begin_comment
comment|/* PLA_DMY_REG0 */
end_comment

begin_define
define|#
directive|define
name|URE_ECM_ALDPS
value|0x0002
end_define

begin_comment
comment|/* PLA_FMC */
end_comment

begin_define
define|#
directive|define
name|URE_FMC_FCR_MCU_EN
value|0x0001
end_define

begin_comment
comment|/* PLA_EEEP_CR */
end_comment

begin_define
define|#
directive|define
name|URE_EEEP_CR_EEEP_TX
value|0x0002
end_define

begin_comment
comment|/* PLA_WDT6_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_WDT6_SET_MODE
value|0x001
end_define

begin_comment
comment|/* PLA_TCR0 */
end_comment

begin_define
define|#
directive|define
name|URE_TCR0_TX_EMPTY
value|0x0800
end_define

begin_define
define|#
directive|define
name|URE_TCR0_AUTO_FIFO
value|0x0080
end_define

begin_comment
comment|/* PLA_TCR1 */
end_comment

begin_define
define|#
directive|define
name|URE_VERSION_MASK
value|0x7cf0
end_define

begin_comment
comment|/* PLA_CR */
end_comment

begin_define
define|#
directive|define
name|URE_CR_RST
value|0x10
end_define

begin_define
define|#
directive|define
name|URE_CR_RE
value|0x08
end_define

begin_define
define|#
directive|define
name|URE_CR_TE
value|0x04
end_define

begin_comment
comment|/* PLA_CRWECR */
end_comment

begin_define
define|#
directive|define
name|URE_CRWECR_NORAML
value|0x00
end_define

begin_define
define|#
directive|define
name|URE_CRWECR_CONFIG
value|0xc0
end_define

begin_comment
comment|/* PLA_OOB_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_NOW_IS_OOB
value|0x80
end_define

begin_define
define|#
directive|define
name|URE_TXFIFO_EMPTY
value|0x20
end_define

begin_define
define|#
directive|define
name|URE_RXFIFO_EMPTY
value|0x10
end_define

begin_define
define|#
directive|define
name|URE_LINK_LIST_READY
value|0x02
end_define

begin_define
define|#
directive|define
name|URE_DIS_MCU_CLROOB
value|0x01
end_define

begin_define
define|#
directive|define
name|URE_FIFO_EMPTY
value|(URE_TXFIFO_EMPTY | URE_RXFIFO_EMPTY)
end_define

begin_comment
comment|/* PLA_MISC_1 */
end_comment

begin_define
define|#
directive|define
name|URE_RXDY_GATED_EN
value|0x0008
end_define

begin_comment
comment|/* PLA_SFF_STS_7 */
end_comment

begin_define
define|#
directive|define
name|URE_RE_INIT_LL
value|0x8000
end_define

begin_define
define|#
directive|define
name|URE_MCU_BORW_EN
value|0x4000
end_define

begin_comment
comment|/* PLA_CPCR */
end_comment

begin_define
define|#
directive|define
name|URE_CPCR_RX_VLAN
value|0x0040
end_define

begin_comment
comment|/* PLA_TEREDO_CFG */
end_comment

begin_define
define|#
directive|define
name|URE_TEREDO_SEL
value|0x8000
end_define

begin_define
define|#
directive|define
name|URE_TEREDO_WAKE_MASK
value|0x7f00
end_define

begin_define
define|#
directive|define
name|URE_TEREDO_RS_EVENT_MASK
value|0x00fe
end_define

begin_define
define|#
directive|define
name|URE_OOB_TEREDO_EN
value|0x0001
end_define

begin_comment
comment|/* PAL_BDC_CR */
end_comment

begin_define
define|#
directive|define
name|URE_ALDPS_PROXY_MODE
value|0x0001
end_define

begin_comment
comment|/* PLA_CONFIG5 */
end_comment

begin_define
define|#
directive|define
name|URE_LAN_WAKE_EN
value|0x0002
end_define

begin_comment
comment|/* PLA_LED_FEATURE */
end_comment

begin_define
define|#
directive|define
name|URE_LED_MODE_MASK
value|0x0700
end_define

begin_comment
comment|/* PLA_PHY_PWR */
end_comment

begin_define
define|#
directive|define
name|URE_TX_10M_IDLE_EN
value|0x0080
end_define

begin_define
define|#
directive|define
name|URE_PFM_PWM_SWITCH
value|0x0040
end_define

begin_comment
comment|/* PLA_MAC_PWR_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_D3_CLK_GATED_EN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|URE_MCU_CLK_RATIO
value|0x07010f07
end_define

begin_define
define|#
directive|define
name|URE_MCU_CLK_RATIO_MASK
value|0x0f0f0f0f
end_define

begin_define
define|#
directive|define
name|URE_ALDPS_SPDWN_RATIO
value|0x0f87
end_define

begin_comment
comment|/* PLA_MAC_PWR_CTRL2 */
end_comment

begin_define
define|#
directive|define
name|URE_EEE_SPDWN_RATIO
value|0x8007
end_define

begin_comment
comment|/* PLA_MAC_PWR_CTRL3 */
end_comment

begin_define
define|#
directive|define
name|URE_PKT_AVAIL_SPDWN_EN
value|0x0100
end_define

begin_define
define|#
directive|define
name|URE_SUSPEND_SPDWN_EN
value|0x0004
end_define

begin_define
define|#
directive|define
name|URE_U1U2_SPDWN_EN
value|0x0002
end_define

begin_define
define|#
directive|define
name|URE_L1_SPDWN_EN
value|0x0001
end_define

begin_comment
comment|/* PLA_MAC_PWR_CTRL4 */
end_comment

begin_define
define|#
directive|define
name|URE_PWRSAVE_SPDWN_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|URE_RXDV_SPDWN_EN
value|0x0800
end_define

begin_define
define|#
directive|define
name|URE_TX10MIDLE_EN
value|0x0100
end_define

begin_define
define|#
directive|define
name|URE_TP100_SPDWN_EN
value|0x0020
end_define

begin_define
define|#
directive|define
name|URE_TP500_SPDWN_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|URE_TP1000_SPDWN_EN
value|0x0008
end_define

begin_define
define|#
directive|define
name|URE_EEE_SPDWN_EN
value|0x0001
end_define

begin_comment
comment|/* PLA_GPHY_INTR_IMR */
end_comment

begin_define
define|#
directive|define
name|URE_GPHY_STS_MSK
value|0x0001
end_define

begin_define
define|#
directive|define
name|URE_SPEED_DOWN_MSK
value|0x0002
end_define

begin_define
define|#
directive|define
name|URE_SPDWN_RXDV_MSK
value|0x0004
end_define

begin_define
define|#
directive|define
name|URE_SPDWN_LINKCHG_MSK
value|0x0008
end_define

begin_comment
comment|/* PLA_PHYAR */
end_comment

begin_define
define|#
directive|define
name|URE_PHYAR_PHYDATA
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|URE_PHYAR_BUSY
value|0x80000000
end_define

begin_comment
comment|/* PLA_EEE_CR */
end_comment

begin_define
define|#
directive|define
name|URE_EEE_RX_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|URE_EEE_TX_EN
value|0x0002
end_define

begin_comment
comment|/* PLA_BOOT_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_AUTOLOAD_DONE
value|0x0002
end_define

begin_comment
comment|/* USB_USB2PHY */
end_comment

begin_define
define|#
directive|define
name|URE_USB2PHY_SUSPEND
value|0x0001
end_define

begin_define
define|#
directive|define
name|URE_USB2PHY_L1
value|0x0002
end_define

begin_comment
comment|/* USB_SSPHYLINK2 */
end_comment

begin_define
define|#
directive|define
name|URE_PWD_DN_SCALE_MASK
value|0x3ffe
end_define

begin_define
define|#
directive|define
name|URE_PWD_DN_SCALE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_comment
comment|/* USB_CSR_DUMMY1 */
end_comment

begin_define
define|#
directive|define
name|URE_DYNAMIC_BURST
value|0x0001
end_define

begin_comment
comment|/* USB_CSR_DUMMY2 */
end_comment

begin_define
define|#
directive|define
name|URE_EP4_FULL_FC
value|0x0001
end_define

begin_comment
comment|/* USB_DEV_STAT */
end_comment

begin_define
define|#
directive|define
name|URE_STAT_SPEED_MASK
value|0x0006
end_define

begin_define
define|#
directive|define
name|URE_STAT_SPEED_HIGH
value|0x0000
end_define

begin_define
define|#
directive|define
name|URE_STAT_SPEED_FULL
value|0x0001
end_define

begin_comment
comment|/* USB_TX_AGG */
end_comment

begin_define
define|#
directive|define
name|URE_TX_AGG_MAX_THRESHOLD
value|0x03
end_define

begin_comment
comment|/* USB_RX_BUF_TH */
end_comment

begin_define
define|#
directive|define
name|URE_RX_THR_SUPER
value|0x0c350180
end_define

begin_define
define|#
directive|define
name|URE_RX_THR_HIGH
value|0x7a120180
end_define

begin_define
define|#
directive|define
name|URE_RX_THR_SLOW
value|0xffff0180
end_define

begin_comment
comment|/* USB_TX_DMA */
end_comment

begin_define
define|#
directive|define
name|URE_TEST_MODE_DISABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|URE_TX_SIZE_ADJUST1
value|0x00000100
end_define

begin_comment
comment|/* USB_UPS_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_POWER_CUT
value|0x0100
end_define

begin_comment
comment|/* USB_PM_CTRL_STATUS */
end_comment

begin_define
define|#
directive|define
name|URE_RESUME_INDICATE
value|0x0001
end_define

begin_comment
comment|/* USB_USB_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_RX_AGG_DISABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|URE_RX_ZERO_EN
value|0x0080
end_define

begin_comment
comment|/* USB_U2P3_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_U2P3_ENABLE
value|0x0001
end_define

begin_comment
comment|/* USB_POWER_CUT */
end_comment

begin_define
define|#
directive|define
name|URE_PWR_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|URE_PHASE2_EN
value|0x0008
end_define

begin_comment
comment|/* USB_MISC_0 */
end_comment

begin_define
define|#
directive|define
name|URE_PCUT_STATUS
value|0x0001
end_define

begin_comment
comment|/* USB_RX_EARLY_TIMEOUT */
end_comment

begin_define
define|#
directive|define
name|URE_COALESCE_SUPER
value|85000U
end_define

begin_define
define|#
directive|define
name|URE_COALESCE_HIGH
value|250000U
end_define

begin_define
define|#
directive|define
name|URE_COALESCE_SLOW
value|524280U
end_define

begin_comment
comment|/* USB_WDT11_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_TIMER11_EN
value|0x0001
end_define

begin_comment
comment|/* USB_LPM_CTRL */
end_comment

begin_define
define|#
directive|define
name|URE_FIFO_EMPTY_1FB
value|0x30
end_define

begin_define
define|#
directive|define
name|URE_LPM_TIMER_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|URE_LPM_TIMER_500MS
value|0x04
end_define

begin_define
define|#
directive|define
name|URE_LPM_TIMER_500US
value|0x0c
end_define

begin_define
define|#
directive|define
name|URE_ROK_EXIT_LPM
value|0x02
end_define

begin_comment
comment|/* USB_AFE_CTRL2 */
end_comment

begin_define
define|#
directive|define
name|URE_SEN_VAL_MASK
value|0xf800
end_define

begin_define
define|#
directive|define
name|URE_SEN_VAL_NORMAL
value|0xa000
end_define

begin_define
define|#
directive|define
name|URE_SEL_RXIDLE
value|0x0100
end_define

begin_comment
comment|/* OCP_ALDPS_CONFIG */
end_comment

begin_define
define|#
directive|define
name|URE_ENPWRSAVE
value|0x8000
end_define

begin_define
define|#
directive|define
name|URE_ENPDNPS
value|0x0200
end_define

begin_define
define|#
directive|define
name|URE_LINKENA
value|0x0100
end_define

begin_define
define|#
directive|define
name|URE_DIS_SDSAVE
value|0x0010
end_define

begin_comment
comment|/* OCP_PHY_STATUS */
end_comment

begin_define
define|#
directive|define
name|URE_PHY_STAT_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|URE_PHY_STAT_LAN_ON
value|3
end_define

begin_define
define|#
directive|define
name|URE_PHY_STAT_PWRDN
value|5
end_define

begin_comment
comment|/* OCP_POWER_CFG */
end_comment

begin_define
define|#
directive|define
name|URE_EEE_CLKDIV_EN
value|0x8000
end_define

begin_define
define|#
directive|define
name|URE_EN_ALDPS
value|0x0004
end_define

begin_define
define|#
directive|define
name|URE_EN_10M_PLLOFF
value|0x0001
end_define

begin_comment
comment|/* OCP_EEE_CFG */
end_comment

begin_define
define|#
directive|define
name|URE_CTAP_SHORT_EN
value|0x0040
end_define

begin_define
define|#
directive|define
name|URE_EEE10_EN
value|0x0010
end_define

begin_comment
comment|/* OCP_DOWN_SPEED */
end_comment

begin_define
define|#
directive|define
name|URE_EN_10M_BGOFF
value|0x0080
end_define

begin_comment
comment|/* OCP_PHY_STATE */
end_comment

begin_define
define|#
directive|define
name|URE_TXDIS_STATE
value|0x01
end_define

begin_define
define|#
directive|define
name|URE_ABD_STATE
value|0x02
end_define

begin_comment
comment|/* OCP_ADC_CFG */
end_comment

begin_define
define|#
directive|define
name|URE_CKADSEL_L
value|0x0100
end_define

begin_define
define|#
directive|define
name|URE_ADC_EN
value|0x0080
end_define

begin_define
define|#
directive|define
name|URE_EN_EMI_L
value|0x0040
end_define

begin_define
define|#
directive|define
name|URE_MCU_TYPE_PLA
value|0x0100
end_define

begin_define
define|#
directive|define
name|URE_MCU_TYPE_USB
value|0x0000
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
name|ure_intrpkt
block|{
name|uint8_t
name|ure_tsr
decl_stmt|;
name|uint8_t
name|ure_rsr
decl_stmt|;
name|uint8_t
name|ure_gep_msr
decl_stmt|;
name|uint8_t
name|ure_waksr
decl_stmt|;
name|uint8_t
name|ure_txok_cnt
decl_stmt|;
name|uint8_t
name|ure_rxlost_cnt
decl_stmt|;
name|uint8_t
name|ure_crcerr_cnt
decl_stmt|;
name|uint8_t
name|ure_col_cnt
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ure_rxpkt
block|{
name|uint32_t
name|ure_pktlen
decl_stmt|;
define|#
directive|define
name|URE_RXPKT_LEN_MASK
value|0x7fff
name|uint32_t
name|ure_rsvd0
decl_stmt|;
name|uint32_t
name|ure_rsvd1
decl_stmt|;
name|uint32_t
name|ure_rsvd2
decl_stmt|;
name|uint32_t
name|ure_rsvd3
decl_stmt|;
name|uint32_t
name|ure_rsvd4
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|ure_txpkt
block|{
name|uint32_t
name|ure_pktlen
decl_stmt|;
define|#
directive|define
name|URE_TKPKT_TX_FS
value|(1<< 31)
define|#
directive|define
name|URE_TKPKT_TX_LS
value|(1<< 30)
define|#
directive|define
name|URE_TXPKT_LEN_MASK
value|0xffff
name|uint32_t
name|ure_rsvd0
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
block|{
name|URE_BULK_DT_WR
block|,
name|URE_BULK_DT_RD
block|,
name|URE_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ure_softc
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
name|URE_N_TRANSFER
index|]
decl_stmt|;
name|int
name|sc_phyno
decl_stmt|;
name|u_int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|URE_FLAG_LINK
value|0x0001
define|#
directive|define
name|URE_FLAG_8152
value|0x1000
comment|/* RTL8152 */
name|u_int
name|sc_chip
decl_stmt|;
define|#
directive|define
name|URE_CHIP_VER_4C00
value|0x01
define|#
directive|define
name|URE_CHIP_VER_4C10
value|0x02
define|#
directive|define
name|URE_CHIP_VER_5C00
value|0x04
define|#
directive|define
name|URE_CHIP_VER_5C10
value|0x08
define|#
directive|define
name|URE_CHIP_VER_5C20
value|0x10
define|#
directive|define
name|URE_CHIP_VER_5C30
value|0x20
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|URE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|URE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|URE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|t
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, t)
end_define

end_unit

