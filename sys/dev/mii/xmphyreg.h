begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000  *	Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_XMPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_XMPHYREG_H_
end_define

begin_comment
comment|/*  * XaQti XMAC II PHY registers  */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|XMPHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|XMPHY_BMCR_LOOP
value|0x4000
end_define

begin_define
define|#
directive|define
name|XMPHY_BMCR_AUTOEN
value|0x1000
end_define

begin_comment
comment|/* Autoneg enabled */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMCR_PDOWN
value|0x0800
end_define

begin_comment
comment|/* Power down */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMCR_ISO
value|0x0400
end_define

begin_comment
comment|/* Isolate */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMCR_STARTNEG
value|0x0200
end_define

begin_comment
comment|/* Restart autoneg */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMCR_FDX
value|0x0100
end_define

begin_comment
comment|/* Duplex mode */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|XMPHY_BMSR_EXTSTS
value|0x0100
end_define

begin_comment
comment|/* Extended status present */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMSR_ACOMP
value|0x0020
end_define

begin_comment
comment|/* Autoneg complete */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMSR_RFAULT
value|0x0010
end_define

begin_comment
comment|/* Remote fault condition occured */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMSR_ANEG
value|0x0008
end_define

begin_comment
comment|/* Autoneg capable */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMSR_LINK
value|0x0004
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|XMPHY_BMSR_EXT
value|0x0001
end_define

begin_comment
comment|/* Extended capability */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|XMPHY_ANAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANAR_ACK
value|0x4000
end_define

begin_comment
comment|/* Next page or base received */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANAR_RFBITS
value|0x3000
end_define

begin_comment
comment|/* Remote fault bits */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANAR_PAUSEBITS
value|0x0180
end_define

begin_comment
comment|/* Pause bits */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANAR_FDX
value|0x0040
end_define

begin_comment
comment|/* Select full duplex */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANAR_HDX
value|0x0020
end_define

begin_comment
comment|/* Select half duplex */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_ANLPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|XMPHY_ANLPAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANLPAR_ACK
value|0x4000
end_define

begin_comment
comment|/* Next page or base received */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANLPAR_RFBITS
value|0x3000
end_define

begin_comment
comment|/* Remote fault bits */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANLPAR_PAUSEBITS
value|0x0180
end_define

begin_comment
comment|/* Pause bits */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANLPAR_FDX
value|0x0040
end_define

begin_comment
comment|/* Select full duplex */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANLPAR_HDX
value|0x0020
end_define

begin_comment
comment|/* Select half duplex */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RF_OK
value|0x0000
end_define

begin_comment
comment|/* No error -- link is good */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RF_LINKFAIL
value|0x1000
end_define

begin_comment
comment|/* Link failure */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RF_OFFLINE
value|0x2000
end_define

begin_comment
comment|/* Offline */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RF_ANEGFAIL
value|0x3000
end_define

begin_comment
comment|/* Autonegotiation error */
end_comment

begin_define
define|#
directive|define
name|XMPHY_PAUSE_NOPAUSE
value|0x0000
end_define

begin_comment
comment|/* No pause possible */
end_comment

begin_define
define|#
directive|define
name|XMPHY_PAUSE_ASYMETRIC
value|0x0080
end_define

begin_comment
comment|/* Asymetric pause toward LP */
end_comment

begin_define
define|#
directive|define
name|XMPHY_PAUSE_SYMETRIC
value|0x0100
end_define

begin_comment
comment|/* Symetric pause */
end_comment

begin_define
define|#
directive|define
name|XMPHY_PAUSE_BOTH
value|0x0180
end_define

begin_comment
comment|/* Both sym and asym pause */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_ANER
value|0x06
end_define

begin_define
define|#
directive|define
name|XMPHY_ANER_LPNP
value|0x0008
end_define

begin_comment
comment|/* Link partner can next page */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANER_NP
value|0x0004
end_define

begin_comment
comment|/* Local PHY can next page */
end_comment

begin_define
define|#
directive|define
name|XMPHY_ANER_RX
value|0x0002
end_define

begin_comment
comment|/* Next page received */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_NEXTP
value|0x07
end_define

begin_comment
comment|/* Next page */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTP_MORE
value|0x8000
end_define

begin_comment
comment|/* More next pages to follow */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTP_ACK1
value|0x4000
end_define

begin_comment
comment|/* Ack bit received OK */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTP_MP
value|0x2000
end_define

begin_comment
comment|/* Page is message page */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTP_ACK2
value|0x1000
end_define

begin_comment
comment|/* can comply with message (r/o) */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTP_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* sync with LP */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTP_MESSAGE
value|0x07FF
end_define

begin_comment
comment|/* message */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_NEXTPLP
value|0x08
end_define

begin_comment
comment|/* Next page of link partner */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTPLP_MORE
value|0x8000
end_define

begin_comment
comment|/* More next pages to follow */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTPLP_ACK1
value|0x4000
end_define

begin_comment
comment|/* Ack bit received OK */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTPLP_MP
value|0x2000
end_define

begin_comment
comment|/* Page is message page */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTPLP_ACK2
value|0x1000
end_define

begin_comment
comment|/* can comply with message (r/o) */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTPLP_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* sync with LP */
end_comment

begin_define
define|#
directive|define
name|XMPHY_NEXTPLP_MESSAGE
value|0x07FF
end_define

begin_comment
comment|/* message */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_EXTSTS
value|0x0F
end_define

begin_comment
comment|/* Extended status */
end_comment

begin_define
define|#
directive|define
name|XMPHY_EXTSTS_FDX
value|0x8000
end_define

begin_comment
comment|/* 1000base-X FD capable */
end_comment

begin_define
define|#
directive|define
name|XMPHY_EXTSTS_HDX
value|0x4000
end_define

begin_comment
comment|/* 1000base-X HD capable */
end_comment

begin_define
define|#
directive|define
name|XMPHY_MII_RESAB
value|0x10
end_define

begin_comment
comment|/* Resolved ability */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RESAB_PAUSEBITS
value|0x0180
end_define

begin_comment
comment|/* Pause bits */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RESAB_HDX
value|0x0040
end_define

begin_comment
comment|/* Half duplex selected */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RESAB_FDX
value|0x0020
end_define

begin_comment
comment|/* Full duplex selected */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RESAB_ABLMIS
value|0x0010
end_define

begin_comment
comment|/* Ability mismatch */
end_comment

begin_define
define|#
directive|define
name|XMPHY_RESAB_PAUSEMIS
value|0x0008
end_define

begin_comment
comment|/* Pause mismatch */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_XMPHYREG_H_ */
end_comment

end_unit

