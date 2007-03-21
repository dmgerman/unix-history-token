begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_BRGPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_BRGPHYREG_H_
end_define

begin_comment
comment|/*  * Broadcom BCM5400 registers  */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|BRGPHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|BRGPHY_BMCR_LOOP
value|0x4000
end_define

begin_define
define|#
directive|define
name|BRGPHY_BMCR_SPD0
value|0x2000
end_define

begin_comment
comment|/* Speed select, lower bit */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMCR_AUTOEN
value|0x1000
end_define

begin_comment
comment|/* Autoneg enabled */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMCR_PDOWN
value|0x0800
end_define

begin_comment
comment|/* Power down */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMCR_ISO
value|0x0400
end_define

begin_comment
comment|/* Isolate */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMCR_STARTNEG
value|0x0200
end_define

begin_comment
comment|/* Restart autoneg */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMCR_FDX
value|0x0100
end_define

begin_comment
comment|/* Duplex mode */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMCR_CTEST
value|0x0080
end_define

begin_comment
comment|/* Collision test enable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMCR_SPD1
value|0x0040
end_define

begin_comment
comment|/* Speed select, upper bit */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_S1000
value|BRGPHY_BMCR_SPD1
end_define

begin_comment
comment|/* 1000mbps */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_S100
value|BRGPHY_BMCR_SPD0
end_define

begin_comment
comment|/* 100mpbs */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_S10
value|0
end_define

begin_comment
comment|/* 10mbps */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|BRGPHY_BMSR_EXTSTS
value|0x0100
end_define

begin_comment
comment|/* Extended status present */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMSR_PRESUB
value|0x0040
end_define

begin_comment
comment|/* Preamble surpression */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMSR_ACOMP
value|0x0020
end_define

begin_comment
comment|/* Autoneg complete */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMSR_RFAULT
value|0x0010
end_define

begin_comment
comment|/* Remote fault condition occured */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMSR_ANEG
value|0x0008
end_define

begin_comment
comment|/* Autoneg capable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMSR_LINK
value|0x0004
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMSR_JABBER
value|0x0002
end_define

begin_comment
comment|/* Jabber detected */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_BMSR_EXT
value|0x0001
end_define

begin_comment
comment|/* Extended capability */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|BRGPHY_ANAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANAR_RF
value|0x2000
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANAR_ASP
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANAR_PC
value|0x0400
end_define

begin_comment
comment|/* Pause capable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANAR_SEL
value|0x001F
end_define

begin_comment
comment|/* Selector field, 00001=Ethernet */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_ANLPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|BRGPHY_ANLPAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANLPAR_RF
value|0x2000
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANLPAR_ASP
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANLPAR_PC
value|0x0400
end_define

begin_comment
comment|/* Pause capable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANLPAR_SEL
value|0x001F
end_define

begin_comment
comment|/* Selector field, 00001=Ethernet */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_SEL_TYPE
value|0x0001
end_define

begin_comment
comment|/* Ethernet */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_ANER
value|0x06
end_define

begin_define
define|#
directive|define
name|BRGPHY_ANER_PDF
value|0x0010
end_define

begin_comment
comment|/* Parallel detection fault */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANER_LPNP
value|0x0008
end_define

begin_comment
comment|/* Link partner can next page */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANER_NP
value|0x0004
end_define

begin_comment
comment|/* Local PHY can next page */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANER_RX
value|0x0002
end_define

begin_comment
comment|/* Next page received */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ANER_LPAN
value|0x0001
end_define

begin_comment
comment|/* Link partner autoneg capable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_NEXTP
value|0x07
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_NEXTP_LP
value|0x08
end_define

begin_comment
comment|/* Next page of link partner */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_1000CTL
value|0x09
end_define

begin_comment
comment|/* 1000baseT control */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000CTL_TST
value|0xE000
end_define

begin_comment
comment|/* Test modes */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000CTL_MSE
value|0x1000
end_define

begin_comment
comment|/* Master/Slave enable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000CTL_MSC
value|0x0800
end_define

begin_comment
comment|/* Master/Slave configuration */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000CTL_RD
value|0x0400
end_define

begin_comment
comment|/* Repeater/DTE */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000CTL_AFD
value|0x0200
end_define

begin_comment
comment|/* Advertise full duplex */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000CTL_AHD
value|0x0100
end_define

begin_comment
comment|/* Advertise half duplex */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_1000STS
value|0x0A
end_define

begin_comment
comment|/* 1000baseT status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000STS_MSF
value|0x8000
end_define

begin_comment
comment|/* Master/slave fault */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000STS_MSR
value|0x4000
end_define

begin_comment
comment|/* Master/slave result */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000STS_LRS
value|0x2000
end_define

begin_comment
comment|/* Local receiver status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000STS_RRS
value|0x1000
end_define

begin_comment
comment|/* Remote receiver status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000STS_LPFD
value|0x0800
end_define

begin_comment
comment|/* Link partner can FD */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000STS_LPHD
value|0x0400
end_define

begin_comment
comment|/* Link partner can HD */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_1000STS_IEC
value|0x00FF
end_define

begin_comment
comment|/* Idle error count */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_EXTSTS
value|0x0F
end_define

begin_comment
comment|/* Extended status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_EXTSTS_X_FD_CAP
value|0x8000
end_define

begin_comment
comment|/* 1000base-X FD capable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_EXTSTS_X_HD_CAP
value|0x4000
end_define

begin_comment
comment|/* 1000base-X HD capable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_EXTSTS_T_FD_CAP
value|0x2000
end_define

begin_comment
comment|/* 1000base-T FD capable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_EXTSTS_T_HD_CAP
value|0x1000
end_define

begin_comment
comment|/* 1000base-T HD capable */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_PHY_EXTCTL
value|0x10
end_define

begin_comment
comment|/* PHY extended control */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_MAC_PHY
value|0x8000
end_define

begin_comment
comment|/* 10BIT/GMI-interface */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_DIS_CROSS
value|0x4000
end_define

begin_comment
comment|/* Disable MDI crossover */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_TX_DIS
value|0x2000
end_define

begin_comment
comment|/* TX output disabled */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_INT_DIS
value|0x1000
end_define

begin_comment
comment|/* Interrupts disabled */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_F_INT
value|0x0800
end_define

begin_comment
comment|/* Force interrupt */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_BY_45
value|0x0400
end_define

begin_comment
comment|/* Bypass 4B5B-Decoder */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_BY_SCR
value|0x0200
end_define

begin_comment
comment|/* Bypass scrambler */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_BY_MLT3
value|0x0100
end_define

begin_comment
comment|/* Bypass MLT3 encoder */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_BY_RXA
value|0x0080
end_define

begin_comment
comment|/* Bypass RX alignment */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_RES_SCR
value|0x0040
end_define

begin_comment
comment|/* Reset scrambler */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_EN_LTR
value|0x0020
end_define

begin_comment
comment|/* Enable LED traffic mode */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_LED_ON
value|0x0010
end_define

begin_comment
comment|/* Force LEDs on */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_LED_OFF
value|0x0008
end_define

begin_comment
comment|/* Force LEDs off */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_EX_IPG
value|0x0004
end_define

begin_comment
comment|/* Extended TX IPG mode */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_3_LED
value|0x0002
end_define

begin_comment
comment|/* Three link LED mode */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTCTL_HIGH_LA
value|0x0001
end_define

begin_comment
comment|/* GMII Fifo Elasticy (?) */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_PHY_EXTSTS
value|0x11
end_define

begin_comment
comment|/* PHY extended status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_CROSS_STAT
value|0x2000
end_define

begin_comment
comment|/* MDI crossover status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_INT_STAT
value|0x1000
end_define

begin_comment
comment|/* Interrupt status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_RRS
value|0x0800
end_define

begin_comment
comment|/* Remote receiver status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_LRS
value|0x0400
end_define

begin_comment
comment|/* Local receiver status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_LOCKED
value|0x0200
end_define

begin_comment
comment|/* Locked */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_LS
value|0x0100
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_RF
value|0x0080
end_define

begin_comment
comment|/* Remove fault */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_CE_ER
value|0x0040
end_define

begin_comment
comment|/* Carrier ext error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_BAD_SSD
value|0x0020
end_define

begin_comment
comment|/* Bad SSD */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_BAD_ESD
value|0x0010
end_define

begin_comment
comment|/* Bad ESS */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_RX_ER
value|0x0008
end_define

begin_comment
comment|/* RX error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_TX_ER
value|0x0004
end_define

begin_comment
comment|/* TX error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_LOCK_ER
value|0x0002
end_define

begin_comment
comment|/* Lock error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_PHY_EXTSTS_MLT3_ER
value|0x0001
end_define

begin_comment
comment|/* MLT3 code error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_RXERRCNT
value|0x12
end_define

begin_comment
comment|/* RX error counter */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_FCERRCNT
value|0x13
end_define

begin_comment
comment|/* False carrier sense counter */
end_comment

begin_define
define|#
directive|define
name|BGRPHY_FCERRCNT
value|0x00FF
end_define

begin_comment
comment|/* False carrier counter */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_RXNOCNT
value|0x14
end_define

begin_comment
comment|/* RX not OK counter */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RXNOCNT_LOCAL
value|0xFF00
end_define

begin_comment
comment|/* Local RX not OK counter */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RXNOCNT_REMOTE
value|0x00FF
end_define

begin_comment
comment|/* Local RX not OK counter */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_DSP_RW_PORT
value|0x15
end_define

begin_comment
comment|/* DSP coefficient r/w port */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_DSP_ADDR_REG
value|0x17
end_define

begin_comment
comment|/* DSP coefficient addr register */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_DSP_TAP_NUMBER_MASK
value|0x00
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_AGC_A
value|0x00
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_AGC_B
value|0x01
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_MSE_PAIR_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_SOFT_DECISION
value|0x03
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_PHASE_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_SKEW
value|0x05
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_POWER_SAVER_UPPER_BOUND
value|0x06
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_POWER_SAVER_LOWER_BOUND
value|0x07
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_LAST_ECHO
value|0x08
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FREQUENCY
value|0x09
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_PLL_BANDWIDTH
value|0x0A
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_PLL_PHASE_OFFSET
value|0x0B
end_define

begin_define
define|#
directive|define
name|BRGPHYDSP_FILTER_DCOFFSET
value|0x0C00
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_FEXT3
value|0x0B00
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_FEXT2
value|0x0A00
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_FEXT1
value|0x0900
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_FEXT0
value|0x0800
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_NEXT3
value|0x0700
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_NEXT2
value|0x0600
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_NEXT1
value|0x0500
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_NEXT0
value|0x0400
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_ECHO
value|0x0300
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_DFE
value|0x0200
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_FILTER_FFE
value|0x0100
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_CONTROL_ALL_FILTERS
value|0x1000
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_SEL_CH_0
value|0x0000
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_SEL_CH_1
value|0x2000
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_SEL_CH_2
value|0x4000
end_define

begin_define
define|#
directive|define
name|BRGPHY_DSP_SEL_CH_3
value|0x6000
end_define

begin_define
define|#
directive|define
name|BRGPHY_MII_AUXCTL
value|0x18
end_define

begin_comment
comment|/* AUX control */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXCTL_LOW_SQ
value|0x8000
end_define

begin_comment
comment|/* Low squelch */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXCTL_LONG_PKT
value|0x4000
end_define

begin_comment
comment|/* RX long packets */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXCTL_ER_CTL
value|0x3000
end_define

begin_comment
comment|/* Edgerate control */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXCTL_TX_TST
value|0x0400
end_define

begin_comment
comment|/* TX test, always 1 */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXCTL_DIS_PRF
value|0x0080
end_define

begin_comment
comment|/* dis part resp filter */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXCTL_DIAG_MODE
value|0x0004
end_define

begin_comment
comment|/* Diagnostic mode */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_AUXSTS
value|0x19
end_define

begin_comment
comment|/* AUX status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_ACOMP
value|0x8000
end_define

begin_comment
comment|/* Autoneg complete */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_AN_ACK
value|0x4000
end_define

begin_comment
comment|/* Autoneg complete ack */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_AN_ACK_D
value|0x2000
end_define

begin_comment
comment|/* Autoneg complete ack detect */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_AN_NPW
value|0x1000
end_define

begin_comment
comment|/* Autoneg next page wait */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_AN_RES
value|0x0700
end_define

begin_comment
comment|/* Autoneg HDC */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_PDF
value|0x0080
end_define

begin_comment
comment|/* Parallel detect. fault */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_RF
value|0x0040
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_ANP_R
value|0x0020
end_define

begin_comment
comment|/* Autoneg page received */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_LP_ANAB
value|0x0010
end_define

begin_comment
comment|/* Link partner autoneg ability */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_LP_NPAB
value|0x0008
end_define

begin_comment
comment|/* Link partner next page ability */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_LINK
value|0x0004
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_PRR
value|0x0002
end_define

begin_comment
comment|/* Pause resolution-RX */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_AUXSTS_PRT
value|0x0001
end_define

begin_comment
comment|/* Pause resolution-TX */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RES_1000FD
value|0x0700
end_define

begin_comment
comment|/* 1000baseT full duplex */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RES_1000HD
value|0x0600
end_define

begin_comment
comment|/* 1000baseT half duplex */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RES_100FD
value|0x0500
end_define

begin_comment
comment|/* 100baseT full duplex */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RES_100T4
value|0x0400
end_define

begin_comment
comment|/* 100baseT4 */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RES_100HD
value|0x0300
end_define

begin_comment
comment|/* 100baseT half duplex */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RES_10FD
value|0x0200
end_define

begin_comment
comment|/* 10baseT full duplex */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_RES_10HD
value|0x0100
end_define

begin_comment
comment|/* 10baseT half duplex */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_ISR
value|0x1A
end_define

begin_comment
comment|/* Interrupt status */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_PSERR
value|0x4000
end_define

begin_comment
comment|/* Pair swap error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_MDXI_SC
value|0x2000
end_define

begin_comment
comment|/* MDIX Status Change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_HCT
value|0x1000
end_define

begin_comment
comment|/* Counter above 32K */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_LCT
value|0x0800
end_define

begin_comment
comment|/* All counter below 128 */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_AN_PR
value|0x0400
end_define

begin_comment
comment|/* Autoneg page received */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_NO_HDCL
value|0x0200
end_define

begin_comment
comment|/* No HCD Link */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_NO_HDC
value|0x0100
end_define

begin_comment
comment|/* No HCD */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_USHDC
value|0x0080
end_define

begin_comment
comment|/* Negotiated Unsupported HCD */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_SCR_S_ERR
value|0x0040
end_define

begin_comment
comment|/* Scrambler sync error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_RRS_CHG
value|0x0020
end_define

begin_comment
comment|/* Remote RX status change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_LRS_CHG
value|0x0010
end_define

begin_comment
comment|/* Local RX status change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_DUP_CHG
value|0x0008
end_define

begin_comment
comment|/* Duplex mode change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_LSP_CHG
value|0x0004
end_define

begin_comment
comment|/* Link speed changed */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_LNK_CHG
value|0x0002
end_define

begin_comment
comment|/* Link status change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_ISR_CRCERR
value|0x0001
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_IMR
value|0x1B
end_define

begin_comment
comment|/* Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_PSERR
value|0x4000
end_define

begin_comment
comment|/* Pair swap error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_MDXI_SC
value|0x2000
end_define

begin_comment
comment|/* MDIX Status Change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_HCT
value|0x1000
end_define

begin_comment
comment|/* Counter above 32K */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_LCT
value|0x0800
end_define

begin_comment
comment|/* All counter below 128 */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_AN_PR
value|0x0400
end_define

begin_comment
comment|/* Autoneg page received */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_NO_HDCL
value|0x0200
end_define

begin_comment
comment|/* No HCD Link */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_NO_HDC
value|0x0100
end_define

begin_comment
comment|/* No HCD */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_USHDC
value|0x0080
end_define

begin_comment
comment|/* Negotiated Unsupported HCD */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_SCR_S_ERR
value|0x0040
end_define

begin_comment
comment|/* Scrambler sync error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_RRS_CHG
value|0x0020
end_define

begin_comment
comment|/* Remote RX status change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_LRS_CHG
value|0x0010
end_define

begin_comment
comment|/* Local RX status change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_DUP_CHG
value|0x0008
end_define

begin_comment
comment|/* Duplex mode change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_LSP_CHG
value|0x0004
end_define

begin_comment
comment|/* Link speed changed */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_LNK_CHG
value|0x0002
end_define

begin_comment
comment|/* Link status change */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_IMR_CRCERR
value|0x0001
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|BRGPHY_MII_TEST1
value|0x1E
end_define

begin_define
define|#
directive|define
name|BRGPHY_TEST1_TRIM_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|BRGPHY_TEST1_CRC_EN
value|0x8000
end_define

begin_define
define|#
directive|define
name|BRGPHY_INTRS
define|\
value|~(BRGPHY_IMR_LNK_CHG|BRGPHY_IMR_LSP_CHG|BRGPHY_IMR_DUP_CHG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_BRGPHY_MIIREG_H_ */
end_comment

end_unit

