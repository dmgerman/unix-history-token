begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Wind River Systems  * Copyright (c) 2001  *	Bill Paul<wpaul@bsdi.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_NSGPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_NSGPHYREG_H_
end_define

begin_comment
comment|/*  * NatSemi DP83891 registers  */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|NSGPHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|NSGPHY_BMCR_LOOP
value|0x4000
end_define

begin_define
define|#
directive|define
name|NSGPHY_BMCR_SPD0
value|0x2000
end_define

begin_comment
comment|/* speed select, lower bit */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMCR_AUTOEN
value|0x1000
end_define

begin_comment
comment|/* Autoneg enabled */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMCR_PDOWN
value|0x0800
end_define

begin_comment
comment|/* Power down */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMCR_ISO
value|0x0400
end_define

begin_comment
comment|/* Isolate */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMCR_STARTNEG
value|0x0200
end_define

begin_comment
comment|/* Restart autoneg */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMCR_FDX
value|0x0100
end_define

begin_comment
comment|/* Duplex mode */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMCR_CTEST
value|0x0080
end_define

begin_comment
comment|/* Collision test enable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMCR_SPD1
value|0x0040
end_define

begin_comment
comment|/* Speed select, upper bit */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_S1000
value|NSGPHY_BMCR_SPD1
end_define

begin_comment
comment|/* 1000mbps */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_S100
value|NSGPHY_BMCR_SPD0
end_define

begin_comment
comment|/* 100mpbs */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_S10
value|0
end_define

begin_comment
comment|/* 10mbps */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|NSGPHY_BMSR_100BT4
value|0x8000
end_define

begin_comment
comment|/* 100baseT4 support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_100FDX
value|0x4000
end_define

begin_comment
comment|/* 100baseTX full duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_100HDX
value|0x2000
end_define

begin_comment
comment|/* 100baseTX half duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_10FDX
value|0x1000
end_define

begin_comment
comment|/* 10baseT full duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_10HDX
value|0x0800
end_define

begin_comment
comment|/* 10baseT half duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_100T2FDX
value|0x0400
end_define

begin_comment
comment|/* 100baseT2 full duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_100T2HDX
value|0x0200
end_define

begin_comment
comment|/* 100baseT2 full duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_EXTSTS
value|0x0100
end_define

begin_comment
comment|/* 1000baseT Extended status present */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_PRESUB
value|0x0040
end_define

begin_comment
comment|/* Preamble surpression */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_ACOMP
value|0x0020
end_define

begin_comment
comment|/* Autoneg complete */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_RFAULT
value|0x0010
end_define

begin_comment
comment|/* Remote fault condition occured */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_ANEG
value|0x0008
end_define

begin_comment
comment|/* Autoneg capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_LINK
value|0x0004
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_JABBER
value|0x0002
end_define

begin_comment
comment|/* Jabber detected */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_BMSR_EXT
value|0x0001
end_define

begin_comment
comment|/* Extended capability */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|NSGPHY_ANAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_RF
value|0x2000
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_ASP
value|0x0800
end_define

begin_comment
comment|/* Asymetric Pause */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_PC
value|0x0400
end_define

begin_comment
comment|/* Pause capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_100T4
value|0x0200
end_define

begin_comment
comment|/* 100baseT4 support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_100FDX
value|0x0100
end_define

begin_comment
comment|/* 100baseTX full duplex support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_100HDX
value|0x0080
end_define

begin_comment
comment|/* 100baseTX half duplex support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_10FDX
value|0x0040
end_define

begin_comment
comment|/* 10baseT full duplex support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_10HDX
value|0x0020
end_define

begin_comment
comment|/* 10baseT half duplex support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANAR_SEL
value|0x001F
end_define

begin_comment
comment|/* selector field, 00001=Ethernet */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_ANLPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_RF
value|0x2000
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_ASP
value|0x0800
end_define

begin_comment
comment|/* Asymetric Pause */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_PC
value|0x0400
end_define

begin_comment
comment|/* Pause capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_100T4
value|0x0200
end_define

begin_comment
comment|/* 100baseT4 support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_100FDX
value|0x0100
end_define

begin_comment
comment|/* 100baseTX full duplex support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_100HDX
value|0x0080
end_define

begin_comment
comment|/* 100baseTX half duplex support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_10FDX
value|0x0040
end_define

begin_comment
comment|/* 10baseT full duplex support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_10HDX
value|0x0020
end_define

begin_comment
comment|/* 10baseT half duplex support */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANLPAR_SEL
value|0x001F
end_define

begin_comment
comment|/* selector field, 00001=Ethernet */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_SEL_TYPE
value|0x0001
end_define

begin_comment
comment|/* ethernet */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_ANER
value|0x06
end_define

begin_define
define|#
directive|define
name|NSGPHY_ANER_PDF
value|0x0010
end_define

begin_comment
comment|/* Parallel detection fault */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANER_LPNP
value|0x0008
end_define

begin_comment
comment|/* Link partner can next page */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANER_NP
value|0x0004
end_define

begin_comment
comment|/* Local PHY can next page */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANER_RX
value|0x0002
end_define

begin_comment
comment|/* Next page received */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_ANER_LPAN
value|0x0001
end_define

begin_comment
comment|/* Link partner autoneg capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_NEXTP
value|0x07
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTP_NP
value|0x8000
end_define

begin_comment
comment|/* Next page indication */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTP_MP
value|0x2000
end_define

begin_comment
comment|/* Message page */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTP_ACK2
value|0x1000
end_define

begin_comment
comment|/* Acknowledge 2 */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTP_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* Toggle */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTP_CODE
value|0x07FF
end_define

begin_comment
comment|/* Code field */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_NEXTP_LP
value|0x08
end_define

begin_comment
comment|/* Next page of link partner */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTPLP_NP
value|0x8000
end_define

begin_comment
comment|/* Next page indication */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTPLP_MP
value|0x2000
end_define

begin_comment
comment|/* Message page */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTPLP_ACK2
value|0x1000
end_define

begin_comment
comment|/* Acknowledge 2 */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTPLP_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* Toggle */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_NEXTPLP_CODE
value|0x07FF
end_define

begin_comment
comment|/* Code field */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_1000CTL
value|0x09
end_define

begin_comment
comment|/* 1000baseT control */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000CTL_TST
value|0xE000
end_define

begin_comment
comment|/* test modes */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000CTL_MSE
value|0x1000
end_define

begin_comment
comment|/* Master/Slave config enable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000CTL_MSC
value|0x0800
end_define

begin_comment
comment|/* Master/Slave setting */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000CTL_RD
value|0x0400
end_define

begin_comment
comment|/* Port type: Repeater/DTE */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000CTL_AFD
value|0x0200
end_define

begin_comment
comment|/* Advertise full duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000CTL_AHD
value|0x0100
end_define

begin_comment
comment|/* Advertise half duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_1000STS
value|0x0A
end_define

begin_comment
comment|/* 1000baseT status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000STS_MSF
value|0x8000
end_define

begin_comment
comment|/* Master/slave fault */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000STS_MSR
value|0x4000
end_define

begin_comment
comment|/* Master/slave result */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000STS_LRS
value|0x2000
end_define

begin_comment
comment|/* Local receiver status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000STS_RRS
value|0x1000
end_define

begin_comment
comment|/* Remote receiver status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000STS_LPFD
value|0x0800
end_define

begin_comment
comment|/* Link partner can FD */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000STS_LPHD
value|0x0400
end_define

begin_comment
comment|/* Link partner can HD */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000STS_ASM_DIR
value|0x0200
end_define

begin_comment
comment|/* Asymetric pause capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_1000STS_IEC
value|0x00FF
end_define

begin_comment
comment|/* Idle error count */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_EXTSTS
value|0x0F
end_define

begin_comment
comment|/* Extended status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_EXTSTS_X_FD_CAP
value|0x8000
end_define

begin_comment
comment|/* 1000base-X FD capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_EXTSTS_X_HD_CAP
value|0x4000
end_define

begin_comment
comment|/* 1000base-X HD capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_EXTSTS_T_FD_CAP
value|0x2000
end_define

begin_comment
comment|/* 1000base-T FD capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_EXTSTS_T_HD_CAP
value|0x1000
end_define

begin_comment
comment|/* 1000base-T HD capable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_STRAPOPT
value|0x10
end_define

begin_comment
comment|/* Strap options */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_PHYADDR
value|0xF800
end_define

begin_comment
comment|/* PHY address */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_COMPAT
value|0x0400
end_define

begin_comment
comment|/* Broadcom compat mode */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_MMSE
value|0x0200
end_define

begin_comment
comment|/* Manual master/slave enable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_ANEG
value|0x0100
end_define

begin_comment
comment|/* Autoneg enable */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_MMSV
value|0x0080
end_define

begin_comment
comment|/* Manual master/slave setting */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_1000HDX
value|0x0010
end_define

begin_comment
comment|/* Advertise 1000 half-duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_1000FDX
value|0x0008
end_define

begin_comment
comment|/* Advertise 1000 full-duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_100_ADV
value|0x0004
end_define

begin_comment
comment|/* Advertise 100 full/half-duplex */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_STRAPOPT_SPDSEL
value|0x0003
end_define

begin_comment
comment|/* speed selection */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_MII_PHYSUP
value|0x11
end_define

begin_comment
comment|/* PHY support/current status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_SPDSTS
value|0x0018
end_define

begin_comment
comment|/* speed status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_LNKSTS
value|0x0004
end_define

begin_comment
comment|/* link status */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_DUPSTS
value|0x0002
end_define

begin_comment
comment|/* duplex status 1 == full */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_PHYSUP_10BT
value|0x0001
end_define

begin_comment
comment|/* 10baseT resolved */
end_comment

begin_define
define|#
directive|define
name|NSGPHY_SPDSTS_1000
value|0x0010
end_define

begin_define
define|#
directive|define
name|NSGPHY_SPDSTS_100
value|0x0008
end_define

begin_define
define|#
directive|define
name|NSGPHY_SPDSTS_10
value|0x0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_NSGPHY_MIIREG_H_ */
end_comment

end_unit

