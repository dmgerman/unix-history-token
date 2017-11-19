begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_RGEPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_RGEPHYREG_H_
end_define

begin_define
define|#
directive|define
name|RGEPHY_8211B
value|2
end_define

begin_define
define|#
directive|define
name|RGEPHY_8211C
value|3
end_define

begin_define
define|#
directive|define
name|RGEPHY_8211F
value|6
end_define

begin_comment
comment|/*  * RealTek 8169S/8110S gigE PHY registers  */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|RGEPHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|RGEPHY_BMCR_LOOP
value|0x4000
end_define

begin_define
define|#
directive|define
name|RGEPHY_BMCR_SPD0
value|0x2000
end_define

begin_comment
comment|/* speed select, lower bit */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMCR_AUTOEN
value|0x1000
end_define

begin_comment
comment|/* Autoneg enabled */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMCR_PDOWN
value|0x0800
end_define

begin_comment
comment|/* Power down */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMCR_ISO
value|0x0400
end_define

begin_comment
comment|/* Isolate */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMCR_STARTNEG
value|0x0200
end_define

begin_comment
comment|/* Restart autoneg */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMCR_FDX
value|0x0100
end_define

begin_comment
comment|/* Duplex mode */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMCR_CTEST
value|0x0080
end_define

begin_comment
comment|/* Collision test enable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMCR_SPD1
value|0x0040
end_define

begin_comment
comment|/* Speed select, upper bit */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_S1000
value|RGEPHY_BMCR_SPD1
end_define

begin_comment
comment|/* 1000mbps */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_S100
value|RGEPHY_BMCR_SPD0
end_define

begin_comment
comment|/* 100mpbs */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_S10
value|0
end_define

begin_comment
comment|/* 10mbps */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|RGEPHY_BMSR_100T4
value|0x8000
end_define

begin_comment
comment|/* 100 base T4 capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_100TXFDX
value|0x4000
end_define

begin_comment
comment|/* 100 base Tx full duplex capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_100TXHDX
value|0x2000
end_define

begin_comment
comment|/* 100 base Tx half duplex capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_10TFDX
value|0x1000
end_define

begin_comment
comment|/* 10 base T full duplex capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_10THDX
value|0x0800
end_define

begin_comment
comment|/* 10 base T half duplex capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_100T2FDX
value|0x0400
end_define

begin_comment
comment|/* 100 base T2 full duplex capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_100T2HDX
value|0x0200
end_define

begin_comment
comment|/* 100 base T2 half duplex capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_EXTSTS
value|0x0100
end_define

begin_comment
comment|/* Extended status present */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_PRESUB
value|0x0040
end_define

begin_comment
comment|/* Preamble surpression */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_ACOMP
value|0x0020
end_define

begin_comment
comment|/* Autoneg complete */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_RFAULT
value|0x0010
end_define

begin_comment
comment|/* Remote fault condition occurred */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_ANEG
value|0x0008
end_define

begin_comment
comment|/* Autoneg capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_LINK
value|0x0004
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_JABBER
value|0x0002
end_define

begin_comment
comment|/* Jabber detected */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_BMSR_EXT
value|0x0001
end_define

begin_comment
comment|/* Extended capability */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|RGEPHY_ANAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_RF
value|0x2000
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_ASP
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_PC
value|0x0400
end_define

begin_comment
comment|/* Pause capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_T4
value|0x0200
end_define

begin_comment
comment|/* local device supports 100bT4 */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_TX_FD
value|0x0100
end_define

begin_comment
comment|/* local device supports 100bTx FD */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_TX
value|0x0080
end_define

begin_comment
comment|/* local device supports 100bTx */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_10_FD
value|0x0040
end_define

begin_comment
comment|/* local device supports 10bT FD */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_10
value|0x0020
end_define

begin_comment
comment|/* local device supports 10bT */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANAR_SEL
value|0x001F
end_define

begin_comment
comment|/* selector field, 00001=Ethernet */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_ANLPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_RF
value|0x2000
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_ASP
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_PC
value|0x0400
end_define

begin_comment
comment|/* Pause capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_T4
value|0x0200
end_define

begin_comment
comment|/* link partner supports 100bT4 */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_TX_FD
value|0x0100
end_define

begin_comment
comment|/* link partner supports 100bTx FD */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_TX
value|0x0080
end_define

begin_comment
comment|/* link partner supports 100bTx */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_10_FD
value|0x0040
end_define

begin_comment
comment|/* link partner supports 10bT FD */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_10
value|0x0020
end_define

begin_comment
comment|/* link partner supports 10bT */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANLPAR_SEL
value|0x001F
end_define

begin_comment
comment|/* selector field, 00001=Ethernet */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SEL_TYPE
value|0x0001
end_define

begin_comment
comment|/* ethernet */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_ANER
value|0x06
end_define

begin_define
define|#
directive|define
name|RGEPHY_ANER_PDF
value|0x0010
end_define

begin_comment
comment|/* Parallel detection fault */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANER_LPNP
value|0x0008
end_define

begin_comment
comment|/* Link partner can next page */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANER_NP
value|0x0004
end_define

begin_comment
comment|/* Local PHY can next page */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANER_RX
value|0x0002
end_define

begin_comment
comment|/* Next page received */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_ANER_LPAN
value|0x0001
end_define

begin_comment
comment|/* Link partner autoneg capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_NEXTP
value|0x07
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_NEXTP_LP
value|0x08
end_define

begin_comment
comment|/* Next page of link partner */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_1000CTL
value|0x09
end_define

begin_comment
comment|/* 1000baseT control */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000CTL_TST
value|0xE000
end_define

begin_comment
comment|/* test modes */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000CTL_MSE
value|0x1000
end_define

begin_comment
comment|/* Master/Slave manual enable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000CTL_MSC
value|0x0800
end_define

begin_comment
comment|/* Master/Slave select */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000CTL_RD
value|0x0400
end_define

begin_comment
comment|/* Repeater/DTE */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000CTL_AFD
value|0x0200
end_define

begin_comment
comment|/* Advertise full duplex */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000CTL_AHD
value|0x0100
end_define

begin_comment
comment|/* Advertise half duplex */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_TEST_TX_JITTER
value|0x2000
end_define

begin_define
define|#
directive|define
name|RGEPHY_TEST_TX_JITTER_MASTER_MODE
value|0x4000
end_define

begin_define
define|#
directive|define
name|RGEPHY_TEST_TX_JITTER_SLAVE_MODE
value|0x6000
end_define

begin_define
define|#
directive|define
name|RGEPHY_TEST_TX_DISTORTION
value|0x8000
end_define

begin_define
define|#
directive|define
name|RGEPHY_MII_1000STS
value|0x0A
end_define

begin_comment
comment|/* 1000baseT status */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000STS_MSF
value|0x8000
end_define

begin_comment
comment|/* Master/slave fault */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000STS_MSR
value|0x4000
end_define

begin_comment
comment|/* Master/slave result */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000STS_LRS
value|0x2000
end_define

begin_comment
comment|/* Local receiver status */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000STS_RRS
value|0x1000
end_define

begin_comment
comment|/* Remote receiver status */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000STS_LPFD
value|0x0800
end_define

begin_comment
comment|/* Link partner can FD */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000STS_LPHD
value|0x0400
end_define

begin_comment
comment|/* Link partner can HD */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_1000STS_IEC
value|0x00FF
end_define

begin_comment
comment|/* Idle error count */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_EXTSTS
value|0x0F
end_define

begin_comment
comment|/* Extended status */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_EXTSTS_X_FD_CAP
value|0x8000
end_define

begin_comment
comment|/* 1000base-X FD capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_EXTSTS_X_HD_CAP
value|0x4000
end_define

begin_comment
comment|/* 1000base-X HD capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_EXTSTS_T_FD_CAP
value|0x2000
end_define

begin_comment
comment|/* 1000base-T FD capable */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_EXTSTS_T_HD_CAP
value|0x1000
end_define

begin_comment
comment|/* 1000base-T HD capable */
end_comment

begin_comment
comment|/* RTL8211B(L)/RTL8211C(L) */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_PCR
value|0x10
end_define

begin_comment
comment|/* PHY Specific control register */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_PCR_ASSERT_CRS
value|0x0800
end_define

begin_define
define|#
directive|define
name|RGEPHY_PCR_FORCE_LINK
value|0x0400
end_define

begin_define
define|#
directive|define
name|RGEPHY_PCR_MDI_MASK
value|0x0060
end_define

begin_define
define|#
directive|define
name|RGEPHY_PCR_MDIX_AUTO
value|0x0040
end_define

begin_define
define|#
directive|define
name|RGEPHY_PCR_MDIX_MANUAL
value|0x0020
end_define

begin_define
define|#
directive|define
name|RGEPHY_PCR_MDI_MANUAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|RGEPHY_PCR_CLK125_DIS
value|0x0010
end_define

begin_define
define|#
directive|define
name|RGEPHY_PCR_JABBER_DIS
value|0x0001
end_define

begin_comment
comment|/* RTL8211B(L)/RTL8211C(L) */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_MII_SSR
value|0x11
end_define

begin_comment
comment|/* PHY Specific status register */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_S1000
value|0x8000
end_define

begin_comment
comment|/* 1000Mbps */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_S100
value|0x4000
end_define

begin_comment
comment|/* 100Mbps */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_S10
value|0x0000
end_define

begin_comment
comment|/* 10Mbps */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_SPD_MASK
value|0xc000
end_define

begin_define
define|#
directive|define
name|RGEPHY_SSR_FDX
value|0x2000
end_define

begin_comment
comment|/* full duplex */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_PAGE_RECEIVED
value|0x1000
end_define

begin_comment
comment|/* new page received */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_SPD_DPLX_RESOLVED
value|0x0800
end_define

begin_comment
comment|/* speed/duplex resolved */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_LINK
value|0x0400
end_define

begin_comment
comment|/* link up */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_MDI_XOVER
value|0x0040
end_define

begin_comment
comment|/* MDI crossover */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_ALDPS
value|0x0008
end_define

begin_comment
comment|/* RTL8211C(L) only */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_SSR_JABBER
value|0x0001
end_define

begin_comment
comment|/* Jabber */
end_comment

begin_comment
comment|/* RTL8211F */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_MII_PCR1
value|0x18
end_define

begin_comment
comment|/* PHY Specific control register 1 */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_PCR1_MDI_MM
value|0x0200
end_define

begin_comment
comment|/* MDI / MDIX Manual Mode */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_PCR1_MDI_MODE
value|0x0100
end_define

begin_comment
comment|/* MDI Mode (0=MDIX,1=MDI) */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_PCR1_ALDPS_EN
value|0x0004
end_define

begin_comment
comment|/* Link Down Power Saving Enable */
end_comment

begin_comment
comment|/* RTL8211F */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_MII_SSR
value|0x1A
end_define

begin_comment
comment|/* PHY Specific status register */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_SSR_S1000
value|0x0020
end_define

begin_comment
comment|/* 1000Mbps */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_SSR_S100
value|0x0010
end_define

begin_comment
comment|/* 100Mbps */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_SSR_S10
value|0x0000
end_define

begin_comment
comment|/* 10Mbps */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_SSR_SPD_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|RGEPHY_F_SSR_FDX
value|0x0008
end_define

begin_comment
comment|/* full duplex */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_SSR_LINK
value|0x0004
end_define

begin_comment
comment|/* link up */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_SSR_MDI
value|0x0002
end_define

begin_comment
comment|/* MDI/MDIX */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_SSR_JABBER
value|0x0001
end_define

begin_comment
comment|/* Jabber */
end_comment

begin_comment
comment|/* RTL8211F */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_EPAGSR
value|0x1F
end_define

begin_comment
comment|/* Extension page select register */
end_comment

begin_comment
comment|/* RTL8211F */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_MMD_DEV_7
value|0x07
end_define

begin_comment
comment|/* RTL8211F MMD device 7 */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_MMD_EEEAR
value|0x3C
end_define

begin_comment
comment|/* EEE advertisement */
end_comment

begin_define
define|#
directive|define
name|EEEAR_1000T
value|0x0004
end_define

begin_comment
comment|/* adv. 1000baseT EEE */
end_comment

begin_define
define|#
directive|define
name|EEEAR_100TX
value|0x0002
end_define

begin_comment
comment|/* adv. 100baseTX EEE */
end_comment

begin_comment
comment|/* RTL8211F MMD device 7 */
end_comment

begin_define
define|#
directive|define
name|RGEPHY_F_MMD_EEELPAR
value|0x3D
end_define

begin_comment
comment|/* EEE link partner abilities */
end_comment

begin_define
define|#
directive|define
name|EEELPAR_1000T
value|0x0004
end_define

begin_comment
comment|/* link partner 1000baseT EEE capable */
end_comment

begin_define
define|#
directive|define
name|EEELPAR_100TX
value|0x0002
end_define

begin_comment
comment|/* link partner 100baseTX EEE capable */
end_comment

begin_comment
comment|/* RTL8153 */
end_comment

begin_define
define|#
directive|define
name|URE_GMEDIASTAT
value|0xe908
end_define

begin_comment
comment|/* media status register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_RGEPHY_MIIREG_H_ */
end_comment

end_unit

