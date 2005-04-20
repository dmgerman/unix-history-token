begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_CIPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_CIPHYREG_H_
end_define

begin_comment
comment|/*  * Register definitions for the Cicada CS8201 10/100/1000 gigE copper  * PHY, embedded within the VIA Networks VT6122 controller.  */
end_comment

begin_comment
comment|/* Command register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|CIPHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|CIPHY_BMCR_LOOP
value|0x4000
end_define

begin_define
define|#
directive|define
name|CIPHY_BMCR_SPD0
value|0x2000
end_define

begin_comment
comment|/* speed select, lower bit */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMCR_AUTOEN
value|0x1000
end_define

begin_comment
comment|/* Autoneg enabled */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMCR_PDOWN
value|0x0800
end_define

begin_comment
comment|/* Power down */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMCR_STARTNEG
value|0x0200
end_define

begin_comment
comment|/* Restart autoneg */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMCR_FDX
value|0x0100
end_define

begin_comment
comment|/* Duplex mode */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMCR_CTEST
value|0x0080
end_define

begin_comment
comment|/* Collision test enable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMCR_SPD1
value|0x0040
end_define

begin_comment
comment|/* Speed select, upper bit */
end_comment

begin_define
define|#
directive|define
name|CIPHY_S1000
value|CIPHY_BMCR_SPD1
end_define

begin_comment
comment|/* 1000mbps */
end_comment

begin_define
define|#
directive|define
name|CIPHY_S100
value|CIPHY_BMCR_SPD0
end_define

begin_comment
comment|/* 100mpbs */
end_comment

begin_define
define|#
directive|define
name|CIPHY_S10
value|0
end_define

begin_comment
comment|/* 10mbps */
end_comment

begin_comment
comment|/* Status register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|CIPHY_BMSR_100T4
value|0x8000
end_define

begin_comment
comment|/* 100 base T4 capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_100TXFDX
value|0x4000
end_define

begin_comment
comment|/* 100 base Tx full duplex capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_100TXHDX
value|0x2000
end_define

begin_comment
comment|/* 100 base Tx half duplex capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_10TFDX
value|0x1000
end_define

begin_comment
comment|/* 10 base T full duplex capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_10THDX
value|0x0800
end_define

begin_comment
comment|/* 10 base T half duplex capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_100T2FDX
value|0x0400
end_define

begin_comment
comment|/* 100 base T2 full duplex capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_100T2HDX
value|0x0200
end_define

begin_comment
comment|/* 100 base T2 half duplex capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_EXTSTS
value|0x0100
end_define

begin_comment
comment|/* Extended status present */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_PRESUB
value|0x0040
end_define

begin_comment
comment|/* Preamble surpression */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_ACOMP
value|0x0020
end_define

begin_comment
comment|/* Autoneg complete */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_RFAULT
value|0x0010
end_define

begin_comment
comment|/* Remote fault condition occured */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_ANEG
value|0x0008
end_define

begin_comment
comment|/* Autoneg capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_LINK
value|0x0004
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_JABBER
value|0x0002
end_define

begin_comment
comment|/* Jabber detected */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BMSR_EXT
value|0x0001
end_define

begin_comment
comment|/* Extended capability */
end_comment

begin_comment
comment|/* PHY ID registers */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_PHYIDR1
value|0x02
end_define

begin_define
define|#
directive|define
name|CIPHY_MII_PHYIDR2
value|0x03
end_define

begin_comment
comment|/* Autoneg advertisement */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|CIPHY_ANAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_RF
value|0x2000
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_ASP
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_PC
value|0x0400
end_define

begin_comment
comment|/* Pause capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_T4
value|0x0200
end_define

begin_comment
comment|/* local device supports 100bT4 */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_TX_FD
value|0x0100
end_define

begin_comment
comment|/* local device supports 100bTx FD */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_TX
value|0x0080
end_define

begin_comment
comment|/* local device supports 100bTx */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_10_FD
value|0x0040
end_define

begin_comment
comment|/* local device supports 10bT FD */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_10
value|0x0020
end_define

begin_comment
comment|/* local device supports 10bT */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANAR_SEL
value|0x001F
end_define

begin_comment
comment|/* selector field, 00001=Ethernet */
end_comment

begin_comment
comment|/* Autoneg link partner ability */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_ANLPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_ACK
value|0x4000
end_define

begin_comment
comment|/* link partner acknowledge */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_RF
value|0x2000
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_ASP
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_PC
value|0x0400
end_define

begin_comment
comment|/* Pause capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_T4
value|0x0200
end_define

begin_comment
comment|/* link partner supports 100bT4 */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_TX_FD
value|0x0100
end_define

begin_comment
comment|/* link partner supports 100bTx FD */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_TX
value|0x0080
end_define

begin_comment
comment|/* link partner supports 100bTx */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_10_FD
value|0x0040
end_define

begin_comment
comment|/* link partner supports 10bT FD */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_10
value|0x0020
end_define

begin_comment
comment|/* link partner supports 10bT */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANLPAR_SEL
value|0x001F
end_define

begin_comment
comment|/* selector field, 00001=Ethernet */
end_comment

begin_define
define|#
directive|define
name|CIPHY_SEL_TYPE
value|0x0001
end_define

begin_comment
comment|/* ethernet */
end_comment

begin_comment
comment|/* Antoneg expansion register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_ANER
value|0x06
end_define

begin_define
define|#
directive|define
name|CIPHY_ANER_PDF
value|0x0010
end_define

begin_comment
comment|/* Parallel detection fault */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANER_LPNP
value|0x0008
end_define

begin_comment
comment|/* Link partner can next page */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANER_NP
value|0x0004
end_define

begin_comment
comment|/* Local PHY can next page */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANER_RX
value|0x0002
end_define

begin_comment
comment|/* Next page received */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ANER_LPAN
value|0x0001
end_define

begin_comment
comment|/* Link partner autoneg capable */
end_comment

begin_comment
comment|/* Autoneg next page transmit regisyer */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_NEXTP
value|0x07
end_define

begin_define
define|#
directive|define
name|CIPHY_NEXTP_MOREP
value|0x8000
end_define

begin_comment
comment|/* More pages to follow */
end_comment

begin_define
define|#
directive|define
name|CIPHY_NEXTP_MESS
value|0x2000
end_define

begin_comment
comment|/* 1 = message page, 0 = unformatted */
end_comment

begin_define
define|#
directive|define
name|CIPHY_NEXTP_ACK2
value|0x1000
end_define

begin_comment
comment|/* MAC acknowledge */
end_comment

begin_define
define|#
directive|define
name|CIPHY_NEXTP_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* Toggle */
end_comment

begin_define
define|#
directive|define
name|CIPHY_NEXTP_CODE
value|0x07FF
end_define

begin_comment
comment|/* Code bits */
end_comment

begin_comment
comment|/* Autoneg link partner next page receive register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_NEXTP_LP
value|0x08
end_define

begin_define
define|#
directive|define
name|CIPHY_NEXTPLP_MOREP
value|0x8000
end_define

begin_comment
comment|/* More pages to follow */
end_comment

begin_define
define|#
directive|define
name|CIPHY_NEXTPLP_MESS
value|0x2000
end_define

begin_comment
comment|/* 1 = message page, 0 = unformatted */
end_comment

begin_define
define|#
directive|define
name|CIPHY_NEXTPLP_ACK2
value|0x1000
end_define

begin_comment
comment|/* MAC acknowledge */
end_comment

begin_define
define|#
directive|define
name|CIPHY_NEXTPLP_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* Toggle */
end_comment

begin_define
define|#
directive|define
name|CIPHY_NEXTPLP_CODE
value|0x07FF
end_define

begin_comment
comment|/* Code bits */
end_comment

begin_comment
comment|/* 1000BT control register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_1000CTL
value|0x09
end_define

begin_define
define|#
directive|define
name|CIPHY_1000CTL_TST
value|0xE000
end_define

begin_comment
comment|/* test modes */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000CTL_MSE
value|0x1000
end_define

begin_comment
comment|/* Master/Slave manual enable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000CTL_MSC
value|0x0800
end_define

begin_comment
comment|/* Master/Slave select */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000CTL_RD
value|0x0400
end_define

begin_comment
comment|/* Repeater/DTE */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000CTL_AFD
value|0x0200
end_define

begin_comment
comment|/* Advertise full duplex */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000CTL_AHD
value|0x0100
end_define

begin_comment
comment|/* Advertise half duplex */
end_comment

begin_define
define|#
directive|define
name|CIPHY_TEST_TX_JITTER
value|0x2000
end_define

begin_define
define|#
directive|define
name|CIPHY_TEST_TX_JITTER_MASTER_MODE
value|0x4000
end_define

begin_define
define|#
directive|define
name|CIPHY_TEST_TX_JITTER_SLAVE_MODE
value|0x6000
end_define

begin_define
define|#
directive|define
name|CIPHY_TEST_TX_DISTORTION
value|0x8000
end_define

begin_comment
comment|/* 1000BT status register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_1000STS
value|0x0A
end_define

begin_define
define|#
directive|define
name|CIPHY_1000STS_MSF
value|0x8000
end_define

begin_comment
comment|/* Master/slave fault */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS_MSR
value|0x4000
end_define

begin_comment
comment|/* Master/slave result */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS_LRS
value|0x2000
end_define

begin_comment
comment|/* Local receiver status */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS_RRS
value|0x1000
end_define

begin_comment
comment|/* Remote receiver status */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS_LPFD
value|0x0800
end_define

begin_comment
comment|/* Link partner can FD */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS_LPHD
value|0x0400
end_define

begin_comment
comment|/* Link partner can HD */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS_IEC
value|0x00FF
end_define

begin_comment
comment|/* Idle error count */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_EXTSTS
value|0x0F
end_define

begin_comment
comment|/* Extended status */
end_comment

begin_define
define|#
directive|define
name|CIPHY_EXTSTS_X_FD_CAP
value|0x8000
end_define

begin_comment
comment|/* 1000base-X FD capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_EXTSTS_X_HD_CAP
value|0x4000
end_define

begin_comment
comment|/* 1000base-X HD capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_EXTSTS_T_FD_CAP
value|0x2000
end_define

begin_comment
comment|/* 1000base-T FD capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_EXTSTS_T_HD_CAP
value|0x1000
end_define

begin_comment
comment|/* 1000base-T HD capable */
end_comment

begin_comment
comment|/* 1000BT status extension register #1 */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_1000STS1
value|0x0F
end_define

begin_define
define|#
directive|define
name|CIPHY_1000STS1_1000XFDX
value|0x8000
end_define

begin_comment
comment|/* 1000baseX FDX capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS1_1000XHDX
value|0x4000
end_define

begin_comment
comment|/* 1000baseX HDX capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS1_1000TFDX
value|0x2000
end_define

begin_comment
comment|/* 1000baseT FDX capable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS1_1000THDX
value|0x1000
end_define

begin_comment
comment|/* 1000baseT HDX capable */
end_comment

begin_comment
comment|/* Vendor-specific PHY registers */
end_comment

begin_comment
comment|/* 100baseTX status extention register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_100STS
value|0x10
end_define

begin_define
define|#
directive|define
name|CIPHY_100STS_DESLCK
value|0x8000
end_define

begin_comment
comment|/* descrambler locked */
end_comment

begin_define
define|#
directive|define
name|CIPHY_100STS_LKCERR
value|0x4000
end_define

begin_comment
comment|/* lock error detected/lock lost */
end_comment

begin_define
define|#
directive|define
name|CIPHY_100STS_DISC
value|0x2000
end_define

begin_comment
comment|/* disconnect state */
end_comment

begin_define
define|#
directive|define
name|CIPHY_100STS_LINK
value|0x1000
end_define

begin_comment
comment|/* current link state */
end_comment

begin_define
define|#
directive|define
name|CIPHY_100STS_RXERR
value|0x0800
end_define

begin_comment
comment|/* receive error detected */
end_comment

begin_define
define|#
directive|define
name|CIPHY_100STS_TXERR
value|0x0400
end_define

begin_comment
comment|/* transmit error detected */
end_comment

begin_define
define|#
directive|define
name|CIPHY_100STS_SSDERR
value|0x0200
end_define

begin_comment
comment|/* false carrier error detected */
end_comment

begin_define
define|#
directive|define
name|CIPHY_100STS_ESDERR
value|0x0100
end_define

begin_comment
comment|/* premature end of stream error */
end_comment

begin_comment
comment|/* 1000BT status extention register #2 */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_1000STS2
value|0x11
end_define

begin_define
define|#
directive|define
name|CIPHY_1000STS2_DESLCK
value|0x8000
end_define

begin_comment
comment|/* descrambler locked */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_LKCERR
value|0x4000
end_define

begin_comment
comment|/* lock error detected/lock lost */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_DISC
value|0x2000
end_define

begin_comment
comment|/* disconnect state */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_LINK
value|0x1000
end_define

begin_comment
comment|/* current link state */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_RXERR
value|0x0800
end_define

begin_comment
comment|/* receive error detected */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_TXERR
value|0x0400
end_define

begin_comment
comment|/* transmit error detected */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_SSDERR
value|0x0200
end_define

begin_comment
comment|/* false carrier error detected */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_ESDERR
value|0x0100
end_define

begin_comment
comment|/* premature end of stream error */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_CARREXT
value|0x0080
end_define

begin_comment
comment|/* carrier extention err detected */
end_comment

begin_define
define|#
directive|define
name|CIPHY_1000STS2_BCM5400
value|0x0040
end_define

begin_comment
comment|/* non-complient BCM5400 detected */
end_comment

begin_comment
comment|/* Bypass control register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_BYPASS
value|0x12
end_define

begin_define
define|#
directive|define
name|CIPHY_BYPASS_TX
value|0x8000
end_define

begin_comment
comment|/* transmit disable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_4B5B
value|0x4000
end_define

begin_comment
comment|/* bypass the 4B5B encoder */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_SCRAM
value|0x2000
end_define

begin_comment
comment|/* bypass scrambler */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_DSCAM
value|0x1000
end_define

begin_comment
comment|/* bypass descrambler */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_PCSRX
value|0x0800
end_define

begin_comment
comment|/* bypass PCS receive */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_PCSTX
value|0x0400
end_define

begin_comment
comment|/* bypass PCS transmit */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_LFI
value|0x0200
end_define

begin_comment
comment|/* bypass LFI timer */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_TXCLK
value|0x0100
end_define

begin_comment
comment|/* enable transmit clock on LED4 pin */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_BCM5400_F
value|0x0080
end_define

begin_comment
comment|/* force BCM5400 detect */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_BCM5400
value|0x0040
end_define

begin_comment
comment|/* bypass BCM5400 detect */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_PAIRSWAP
value|0x0020
end_define

begin_comment
comment|/* disable automatic pair swap */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_POLARITY
value|0x0010
end_define

begin_comment
comment|/* disable polarity correction */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_PARALLEL
value|0x0008
end_define

begin_comment
comment|/* parallel detect enable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_PULSE
value|0x0004
end_define

begin_comment
comment|/* disable pulse shaping filter */
end_comment

begin_define
define|#
directive|define
name|CIPHY_BYPASS_1000BNP
value|0x0002
end_define

begin_comment
comment|/* disable 1000BT next page exchange */
end_comment

begin_comment
comment|/* RX error count register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_RXERR
value|0x13
end_define

begin_comment
comment|/* False carrier sense count register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_FCSERR
value|0x14
end_define

begin_comment
comment|/* Ddisconnect error counter */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_DISCERR
value|0x15
end_define

begin_comment
comment|/* 10baseT control/status register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_10BTCSR
value|0x16
end_define

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_DLIT
value|0x8000
end_define

begin_comment
comment|/* Disable data link integrity test */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_JABBER
value|0x4000
end_define

begin_comment
comment|/* Disable jabber detect */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_ECHO
value|0x2000
end_define

begin_comment
comment|/* Disable echo mode */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_SQE
value|0x1000
end_define

begin_comment
comment|/* Disable signal quality error */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_SQUENCH
value|0x0C00
end_define

begin_comment
comment|/* Squelch control */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_EOFERR
value|0x0100
end_define

begin_comment
comment|/* End of Frame error */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_DISC
value|0x0080
end_define

begin_comment
comment|/* Disconnect status */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_LINK
value|0x0040
end_define

begin_comment
comment|/* current link state */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_ITRIM
value|0x0038
end_define

begin_comment
comment|/* current reference trim */
end_comment

begin_define
define|#
directive|define
name|CIPHY_10BTCSR_CSR
value|0x0006
end_define

begin_comment
comment|/* CSR behavior control */
end_comment

begin_define
define|#
directive|define
name|CIPHY_SQUELCH_300MV
value|0x0000
end_define

begin_define
define|#
directive|define
name|CIPHY_SQUELCH_197MV
value|0x0400
end_define

begin_define
define|#
directive|define
name|CIPHY_SQUELCH_450MV
value|0x0800
end_define

begin_define
define|#
directive|define
name|CIPHY_SQUELCH_RSVD
value|0x0C00
end_define

begin_define
define|#
directive|define
name|CIPHY_ITRIM_PLUS2
value|0x0000
end_define

begin_define
define|#
directive|define
name|CIPHY_ITRIM_PLUS4
value|0x0008
end_define

begin_define
define|#
directive|define
name|CIPHY_ITRIM_PLUS6
value|0x0010
end_define

begin_define
define|#
directive|define
name|CIPHY_ITRIM_PLUS6_
value|0x0018
end_define

begin_define
define|#
directive|define
name|CIPHY_ITRIM_MINUS4
value|0x0020
end_define

begin_define
define|#
directive|define
name|CIPHY_ITRIM_MINUS4_
value|0x0028
end_define

begin_define
define|#
directive|define
name|CIPHY_ITRIM_MINUS2
value|0x0030
end_define

begin_define
define|#
directive|define
name|CIPHY_ITRIM_ZERO
value|0x0038
end_define

begin_comment
comment|/* Extended PHY control register #1 */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_ECTL1
value|0x17
end_define

begin_define
define|#
directive|define
name|CIPHY_ECTL1_ACTIPHY
value|0x0020
end_define

begin_comment
comment|/* Enable ActiPHY power saving */
end_comment

begin_comment
comment|/* Extended PHY control register #2 */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_ECTL2
value|0x18
end_define

begin_define
define|#
directive|define
name|CIPHY_ECTL2_ERATE
value|0xE000
end_define

begin_comment
comment|/* 10/1000 edge rate control */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ECTL2_VTRIM
value|0x1C00
end_define

begin_comment
comment|/* voltage reference trim */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ECTL2_CABLELEN
value|0x000E
end_define

begin_comment
comment|/* Cable quality/length */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ECTL2_ANALOGLOOP
value|0x0001
end_define

begin_comment
comment|/* 1000BT analog loopback */
end_comment

begin_define
define|#
directive|define
name|CIPHY_CABLELEN_0TO10M
value|0x0000
end_define

begin_define
define|#
directive|define
name|CIPHY_CABLELEN_10TO20M
value|0x0002
end_define

begin_define
define|#
directive|define
name|CIPHY_CABLELEN_20TO40M
value|0x0004
end_define

begin_define
define|#
directive|define
name|CIPHY_CABLELEN_40TO80M
value|0x0006
end_define

begin_define
define|#
directive|define
name|CIPHY_CABLELEN_80TO100M
value|0x0008
end_define

begin_define
define|#
directive|define
name|CIPHY_CABLELEN_100TO140M
value|0x000A
end_define

begin_define
define|#
directive|define
name|CIPHY_CABLELEN_140TO180M
value|0x000C
end_define

begin_define
define|#
directive|define
name|CIPHY_CABLELEN_OVER180M
value|0x000E
end_define

begin_comment
comment|/* Interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_IMR
value|0x19
end_define

begin_define
define|#
directive|define
name|CIPHY_IMR_PINENABLE
value|0x8000
end_define

begin_comment
comment|/* Interrupt pin enable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_SPEED
value|0x4000
end_define

begin_comment
comment|/* speed changed event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_LINK
value|0x2000
end_define

begin_comment
comment|/* link change/ActiPHY event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_DPX
value|0x1000
end_define

begin_comment
comment|/* duplex change event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_ANEGERR
value|0x0800
end_define

begin_comment
comment|/* autoneg error event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_ANEGDONE
value|0x0400
end_define

begin_comment
comment|/* autoneg done event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_NPRX
value|0x0200
end_define

begin_comment
comment|/* page received event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_SYMERR
value|0x0100
end_define

begin_comment
comment|/* symbol error event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_LOCKERR
value|0x0080
end_define

begin_comment
comment|/* descrambler lock lost event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_XOVER
value|0x0040
end_define

begin_comment
comment|/* MDI crossover change event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_POLARITY
value|0x0020
end_define

begin_comment
comment|/* polarity change event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_JABBER
value|0x0010
end_define

begin_comment
comment|/* jabber detect event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_SSDERR
value|0x0008
end_define

begin_comment
comment|/* false carrier detect event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_ESDERR
value|0x0004
end_define

begin_comment
comment|/* parallel detect error event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_MASTERSLAVE
value|0x0002
end_define

begin_comment
comment|/* master/slave resolve done event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_IMR_RXERR
value|0x0001
end_define

begin_comment
comment|/* RX error event */
end_comment

begin_comment
comment|/* Interrupt status register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_ISR
value|0x1A
end_define

begin_define
define|#
directive|define
name|CIPHY_ISR_IPENDING
value|0x8000
end_define

begin_comment
comment|/* Interrupt is pending */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_SPEED
value|0x4000
end_define

begin_comment
comment|/* speed changed event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_LINK
value|0x2000
end_define

begin_comment
comment|/* link change/ActiPHY event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_DPX
value|0x1000
end_define

begin_comment
comment|/* duplex change event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_ANEGERR
value|0x0800
end_define

begin_comment
comment|/* autoneg error event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_ANEGDONE
value|0x0400
end_define

begin_comment
comment|/* autoneg done event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_NPRX
value|0x0200
end_define

begin_comment
comment|/* page received event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_SYMERR
value|0x0100
end_define

begin_comment
comment|/* symbol error event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_LOCKERR
value|0x0080
end_define

begin_comment
comment|/* descrambler lock lost event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_XOVER
value|0x0040
end_define

begin_comment
comment|/* MDI crossover change event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_POLARITY
value|0x0020
end_define

begin_comment
comment|/* polarity change event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_JABBER
value|0x0010
end_define

begin_comment
comment|/* jabber detect event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_SSDERR
value|0x0008
end_define

begin_comment
comment|/* false carrier detect event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_ESDERR
value|0x0004
end_define

begin_comment
comment|/* parallel detect error event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_MASTERSLAVE
value|0x0002
end_define

begin_comment
comment|/* master/slave resolve done event */
end_comment

begin_define
define|#
directive|define
name|CIPHY_ISR_RXERR
value|0x0001
end_define

begin_comment
comment|/* RX error event */
end_comment

begin_comment
comment|/* LED control register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_LED
value|0x1B
end_define

begin_define
define|#
directive|define
name|CIPHY_LED_LINK10FORCE
value|0x8000
end_define

begin_comment
comment|/* Force on link10 LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_LINK10DIS
value|0x4000
end_define

begin_comment
comment|/* Disable link10 LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_LINK100FORCE
value|0x2000
end_define

begin_comment
comment|/* Force on link10 LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_LINK100DIS
value|0x1000
end_define

begin_comment
comment|/* Disable link100 LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_LINK1000FORCE
value|0x0800
end_define

begin_comment
comment|/* Force on link1000 LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_LINK1000DIS
value|0x0400
end_define

begin_comment
comment|/* Disable link1000 LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_FDXFORCE
value|0x0200
end_define

begin_comment
comment|/* Force on duplex LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_FDXDIS
value|0x0100
end_define

begin_comment
comment|/* Disable duplex LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_ACTFORCE
value|0x0080
end_define

begin_comment
comment|/* Force on activity LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_ACTDIS
value|0x0040
end_define

begin_comment
comment|/* Disable activity LED */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_PULSE
value|0x0008
end_define

begin_comment
comment|/* LED pulse enable */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_LINKACTBLINK
value|0x0004
end_define

begin_comment
comment|/* enable link/activity LED blink */
end_comment

begin_define
define|#
directive|define
name|CIPHY_LED_BLINKRATE
value|0x0002
end_define

begin_comment
comment|/* blink rate 0=10hz, 1=5hz */
end_comment

begin_comment
comment|/* Auxilliary control and status register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_AUXCSR
value|0x1C
end_define

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_ANEGDONE
value|0x8000
end_define

begin_comment
comment|/* Autoneg complete */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_ANEGOFF
value|0x4000
end_define

begin_comment
comment|/* Autoneg disabled */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_XOVER
value|0x2000
end_define

begin_comment
comment|/* MDI/MDI-X crossover indication */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_PAIRSWAP
value|0x1000
end_define

begin_comment
comment|/* pair swap indication */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_APOLARITY
value|0x0800
end_define

begin_comment
comment|/* polarity inversion pair A */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_BPOLARITY
value|0x0400
end_define

begin_comment
comment|/* polarity inversion pair B */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_CPOLARITY
value|0x0200
end_define

begin_comment
comment|/* polarity inversion pair C */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_DPOLARITY
value|0x0100
end_define

begin_comment
comment|/* polarity inversion pair D */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_FDX
value|0x0020
end_define

begin_comment
comment|/* duplex 1=full, 0=half */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_SPEED
value|0x0018
end_define

begin_comment
comment|/* speed */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_MDPPS
value|0x0004
end_define

begin_comment
comment|/* No idea, not documented */
end_comment

begin_define
define|#
directive|define
name|CIPHY_AUXCSR_STICKYREST
value|0x0002
end_define

begin_comment
comment|/* reset clears sticky bits */
end_comment

begin_define
define|#
directive|define
name|CIPHY_SPEED10
value|0x0000
end_define

begin_define
define|#
directive|define
name|CIPHY_SPEED100
value|0x0008
end_define

begin_define
define|#
directive|define
name|CIPHY_SPEED1000
value|0x0010
end_define

begin_comment
comment|/* Delay skew status register */
end_comment

begin_define
define|#
directive|define
name|CIPHY_MII_DSKEW
value|0x1D
end_define

begin_define
define|#
directive|define
name|CIPHY_DSKEW_PAIRA
value|0x7000
end_define

begin_comment
comment|/* Pair A skew in symbol times */
end_comment

begin_define
define|#
directive|define
name|CIPHY_DSKEW_PAIRB
value|0x0700
end_define

begin_comment
comment|/* Pair B skew in symbol times */
end_comment

begin_define
define|#
directive|define
name|CIPHY_DSKEW_PAIRC
value|0x0070
end_define

begin_comment
comment|/* Pair C skew in symbol times */
end_comment

begin_define
define|#
directive|define
name|CIPHY_DSKEW_PAIRD
value|0x0007
end_define

begin_comment
comment|/* Pair D skew in symbol times */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_CIPHY_MIIREG_H_ */
end_comment

end_unit

