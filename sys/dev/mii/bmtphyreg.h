begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from NetBSD: bmtphyreg.h,v 1.1 2001/06/02 21:42:10 thorpej Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_BMTPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_BMTPHYREG_H_
end_define

begin_comment
comment|/*  * BCM5201/BCM5202 registers.  */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_AUX_CTL
value|0x10
end_define

begin_comment
comment|/* auxiliary control */
end_comment

begin_define
define|#
directive|define
name|AUX_CTL_TXDIS
value|0x2000
end_define

begin_comment
comment|/* transmitter disable */
end_comment

begin_define
define|#
directive|define
name|AUX_CTL_4B5B_BYPASS
value|0x0400
end_define

begin_comment
comment|/* bypass 4b5b encoder */
end_comment

begin_define
define|#
directive|define
name|AUX_CTL_SCR_BYPASS
value|0x0200
end_define

begin_comment
comment|/* bypass scrambler */
end_comment

begin_define
define|#
directive|define
name|AUX_CTL_NRZI_BYPASS
value|0x0100
end_define

begin_comment
comment|/* bypass NRZI encoder */
end_comment

begin_define
define|#
directive|define
name|AUX_CTL_RXALIGN_BYPASS
value|0x0080
end_define

begin_comment
comment|/* bypass rx symbol alignment */
end_comment

begin_define
define|#
directive|define
name|AUX_CTL_BASEWANDER_DIS
value|0x0040
end_define

begin_comment
comment|/* disable baseline wander correction */
end_comment

begin_define
define|#
directive|define
name|AUX_CTL_FEF_EN
value|0x0020
end_define

begin_comment
comment|/* far-end fault enable */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_AUX_STS
value|0x11
end_define

begin_comment
comment|/* auxiliary status */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_FX_MODE
value|0x0400
end_define

begin_comment
comment|/* 100base-FX mode (strap pin) */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_LOCKED
value|0x0200
end_define

begin_comment
comment|/* descrambler locked */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_100BASE_LINK
value|0x0100
end_define

begin_comment
comment|/* 1 = 100base link */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_REMFAULT
value|0x0080
end_define

begin_comment
comment|/* remote fault */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_DISCON_STATE
value|0x0040
end_define

begin_comment
comment|/* disconnect state */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_FCARDET
value|0x0020
end_define

begin_comment
comment|/* false carrier detected */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_BAD_ESD
value|0x0010
end_define

begin_comment
comment|/* bad ESD detected */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_RXERROR
value|0x0008
end_define

begin_comment
comment|/* Rx error detected */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_TXERROR
value|0x0004
end_define

begin_comment
comment|/* Tx error detected */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_LOCKERROR
value|0x0002
end_define

begin_comment
comment|/* lock error detected */
end_comment

begin_define
define|#
directive|define
name|AUX_STS_MLT3ERROR
value|0x0001
end_define

begin_comment
comment|/* MLT3 code error detected */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_RXERROR_CTR
value|0x12
end_define

begin_comment
comment|/* 100base-X Rx error counter */
end_comment

begin_define
define|#
directive|define
name|RXERROR_CTR_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|MII_BMTPHY_FCS_CTR
value|0x13
end_define

begin_comment
comment|/* 100base-X false carrier counter */
end_comment

begin_define
define|#
directive|define
name|FCS_CTR_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|MII_BMTPHY_DIS_CTR
value|0x14
end_define

begin_comment
comment|/* 100base-X disconnect counter */
end_comment

begin_define
define|#
directive|define
name|DIS_CTR_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|MII_BMTPHY_PTEST
value|0x17
end_define

begin_comment
comment|/* PTEST */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_AUX_CSR
value|0x18
end_define

begin_comment
comment|/* auxiliary control/status */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_JABBER_DIS
value|0x8000
end_define

begin_comment
comment|/* jabber disable */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_FLINK
value|0x4000
end_define

begin_comment
comment|/* force 10baseT link pass */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_HSQ
value|0x0080
end_define

begin_comment
comment|/* SQ high */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_LSQ
value|0x0040
end_define

begin_comment
comment|/* SQ low */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_ER1
value|0x0020
end_define

begin_comment
comment|/* edge rate 1 */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_ER0
value|0x0010
end_define

begin_comment
comment|/* edge rate 0 */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_ANEG
value|0x0008
end_define

begin_comment
comment|/* auto-negotiation activated */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_F100
value|0x0004
end_define

begin_comment
comment|/* force 100base */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_SPEED
value|0x0002
end_define

begin_comment
comment|/* 1 = 100, 0 = 10 */
end_comment

begin_define
define|#
directive|define
name|AUX_CSR_FDX
value|0x0001
end_define

begin_comment
comment|/* full-duplex */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_AUX_SS
value|0x19
end_define

begin_comment
comment|/* auxiliary status summary */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_ACOMP
value|0x8000
end_define

begin_comment
comment|/* auto-negotiation complete */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_ACOMP_ACK
value|0x4000
end_define

begin_comment
comment|/* auto-negotiation compl. ack */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_AACK_DET
value|0x2000
end_define

begin_comment
comment|/* auto-neg. ack detected */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_ANLPAD
value|0x1000
end_define

begin_comment
comment|/* auto-neg. link part. ability det */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_ANEG_PAUSE
value|0x0800
end_define

begin_comment
comment|/* pause operation bit */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_HCD
value|0x0700
end_define

begin_comment
comment|/* highest common denominator */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_HCD_NONE
value|0x0000
end_define

begin_comment
comment|/*    none */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_HCD_10T
value|0x0100
end_define

begin_comment
comment|/*    10baseT */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_HCD_10T_FDX
value|0x0200
end_define

begin_comment
comment|/*    10baseT-FDX */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_HCD_100TX
value|0x0300
end_define

begin_comment
comment|/*    100baseTX-FDX */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_HCD_100T4
value|0x0400
end_define

begin_comment
comment|/*    100baseT4 */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_HCD_100TX_FDX
value|0x0500
end_define

begin_comment
comment|/*    100baseTX-FDX */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_PDF
value|0x0080
end_define

begin_comment
comment|/* parallel detection fault */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_LPRF
value|0x0040
end_define

begin_comment
comment|/* link partner remote fault */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_LPPR
value|0x0020
end_define

begin_comment
comment|/* link partner page received */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_LPANA
value|0x0010
end_define

begin_comment
comment|/* link partner auto-neg able */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_SPEED
value|0x0008
end_define

begin_comment
comment|/* 1 = 100, 0 = 10 */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_LINK
value|0x0004
end_define

begin_comment
comment|/* link pass */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_ANEN
value|0x0002
end_define

begin_comment
comment|/* auto-neg. enabled */
end_comment

begin_define
define|#
directive|define
name|AUX_SS_JABBER
value|0x0001
end_define

begin_comment
comment|/* jabber detected */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_INTR
value|0x1a
end_define

begin_comment
comment|/* interrupt register */
end_comment

begin_define
define|#
directive|define
name|INTR_FDX_LED
value|0x8000
end_define

begin_comment
comment|/* full-duplex led enable */
end_comment

begin_define
define|#
directive|define
name|INTR_INTR_EN
value|0x4000
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|INTR_FDX_MASK
value|0x0800
end_define

begin_comment
comment|/* full-dupled intr mask */
end_comment

begin_define
define|#
directive|define
name|INTR_SPD_MASK
value|0x0400
end_define

begin_comment
comment|/* speed intr mask */
end_comment

begin_define
define|#
directive|define
name|INTR_LINK_MASK
value|0x0200
end_define

begin_comment
comment|/* link intr mask */
end_comment

begin_define
define|#
directive|define
name|INTR_INTR_MASK
value|0x0100
end_define

begin_comment
comment|/* master interrupt mask */
end_comment

begin_define
define|#
directive|define
name|INTR_FDX_CHANGE
value|0x0008
end_define

begin_comment
comment|/* full-duplex change */
end_comment

begin_define
define|#
directive|define
name|INTR_SPD_CHANGE
value|0x0004
end_define

begin_comment
comment|/* speed change */
end_comment

begin_define
define|#
directive|define
name|INTR_LINK_CHANGE
value|0x0002
end_define

begin_comment
comment|/* link change */
end_comment

begin_define
define|#
directive|define
name|INTR_INTR_STATUS
value|0x0001
end_define

begin_comment
comment|/* interrupt status */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_AUX2
value|0x1b
end_define

begin_comment
comment|/* auliliary mode 2 */
end_comment

begin_define
define|#
directive|define
name|AUX2_BLOCK_RXDV
value|0x0200
end_define

begin_comment
comment|/* block RXDV mode enabled */
end_comment

begin_define
define|#
directive|define
name|AUX2_ANPDQ
value|0x0100
end_define

begin_comment
comment|/* auto-neg parallel detection Q mode */
end_comment

begin_define
define|#
directive|define
name|AUX2_TRAFFIC_LED
value|0x0040
end_define

begin_comment
comment|/* traffic meter led enable */
end_comment

begin_define
define|#
directive|define
name|AUX2_FXMTRCV_LED
value|0x0020
end_define

begin_comment
comment|/* force Tx and Rx LEDs */
end_comment

begin_define
define|#
directive|define
name|AUX2_HS_TOKEN
value|0x0010
end_define

begin_comment
comment|/* high-speed token ring mode */
end_comment

begin_define
define|#
directive|define
name|AUX2_AUTO_LP
value|0x0008
end_define

begin_comment
comment|/* auto low-power mode */
end_comment

begin_define
define|#
directive|define
name|AUX2_TWOLINK_LED
value|0x0004
end_define

begin_comment
comment|/* two link LEDs */
end_comment

begin_define
define|#
directive|define
name|AUX2_SQE_DIS
value|0x0002
end_define

begin_comment
comment|/* disable SQE pulse */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_AUXERR
value|0x1c
end_define

begin_comment
comment|/* auxiliary error */
end_comment

begin_define
define|#
directive|define
name|AUXERR_MANCHESTER
value|0x0400
end_define

begin_comment
comment|/* Manchester code error */
end_comment

begin_define
define|#
directive|define
name|AUXERR_EOF
value|0x0200
end_define

begin_comment
comment|/* EOF detection error */
end_comment

begin_define
define|#
directive|define
name|AUXERR_POLARITY
value|0x0100
end_define

begin_comment
comment|/* polarity inversion */
end_comment

begin_define
define|#
directive|define
name|AUXERR_ANEG
value|0x0008
end_define

begin_comment
comment|/* autonegotiation enabled */
end_comment

begin_define
define|#
directive|define
name|AUXERR_F100
value|0x0004
end_define

begin_comment
comment|/* force 100base */
end_comment

begin_define
define|#
directive|define
name|AUXERR_SPEED
value|0x0002
end_define

begin_comment
comment|/* 1 = 100, 0 = 10 */
end_comment

begin_define
define|#
directive|define
name|AUXERR_FDX
value|0x0001
end_define

begin_comment
comment|/* full-duplex */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_AUXMODE
value|0x1d
end_define

begin_comment
comment|/* auxiliary mode */
end_comment

begin_define
define|#
directive|define
name|AUXMODE_ACT_LED_DIS
value|0x0010
end_define

begin_comment
comment|/* activity LED disable */
end_comment

begin_define
define|#
directive|define
name|AUXMODE_LINK_LED_DIS
value|0x0008
end_define

begin_comment
comment|/* link LED disable */
end_comment

begin_define
define|#
directive|define
name|AUXMODE_BLOCK_TXEN
value|0x0002
end_define

begin_comment
comment|/* enable block TXEN */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_AUXMPHY
value|0x1e
end_define

begin_comment
comment|/* auxiliary multiple phy register */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_HCD_TX_FDX
value|0x8000
end_define

begin_comment
comment|/* res. is 100baseTX-FDX */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_HCD_T4
value|0x4000
end_define

begin_comment
comment|/* res. is 100baseT4 */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_HCD_TX
value|0x2000
end_define

begin_comment
comment|/* res. is 100baseTX */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_HCD_10T_FDX
value|0x1000
end_define

begin_comment
comment|/* res. is 10baseT-FDX */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_HCD_10T
value|0x0800
end_define

begin_comment
comment|/* res. is 10baseT */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_RES_ANEG
value|0x0100
end_define

begin_comment
comment|/* restart auto-negotiation */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_ANEG_COMP
value|0x0080
end_define

begin_comment
comment|/* auto-negotiation complete */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_ACK_COMP
value|0x0040
end_define

begin_comment
comment|/* acknowledge complete */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_ACK_DET
value|0x0020
end_define

begin_comment
comment|/* acknowledge detected */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_ABILITY_DET
value|0x0010
end_define

begin_comment
comment|/* waiting for LP ability */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_SUPER_ISO
value|0x0008
end_define

begin_comment
comment|/* super-isolate mode */
end_comment

begin_define
define|#
directive|define
name|AUXMPHY_10T_SERIAL
value|0x0002
end_define

begin_comment
comment|/* 10baseT serial mode */
end_comment

begin_define
define|#
directive|define
name|MII_BMTPHY_TEST
value|0x1d
end_define

begin_comment
comment|/* Broadcom test register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_BMTPHYREG_H_ */
end_comment

end_unit

