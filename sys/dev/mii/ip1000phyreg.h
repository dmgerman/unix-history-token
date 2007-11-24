begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006, Pyun YongHyeon  * All rights reserved.  *                * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:               * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.    * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_IP1000PHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_IP1000PHYREG_H_
end_define

begin_comment
comment|/*  * Registers for the IC Plus IP1000A internal PHY.  */
end_comment

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_BMCR
value|0x00
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_FDX
value|0x0100
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_STARTNEG
value|0x0200
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_ISO
value|0x0400
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_PDOWN
value|0x0800
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_AUTOEN
value|0x1000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_LOOP
value|0x4000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_100
value|0x2000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMCR_1000
value|0x0040
end_define

begin_comment
comment|/* Status register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_BMSR
value|0x01
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMSR_EXT
value|0x0001
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMSR_LINK
value|0x0004
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMSR_ANEG
value|0x0008
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMSR_RFAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMSR_ANEGCOMP
value|0x0020
end_define

begin_define
define|#
directive|define
name|IP1000PHY_BMSR_EXTSTS
value|0x0100
end_define

begin_define
define|#
directive|define
name|IP1000PHY_MII_ID1
value|0x02
end_define

begin_comment
comment|/* Autonegotiation advertisement register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_ANAR
value|0x04
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_10T
value|0x0020
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_10T_FDX
value|0x0040
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_100TX
value|0x0080
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_100TX_FDX
value|0x0100
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_100T4
value|0x0200
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_APAUSE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_RFAULT
value|0x2000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANAR_NP
value|0x8000
end_define

begin_comment
comment|/* Autonegotiation link parnet ability register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_ANLPAR
value|0x05
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_10T
value|0x0020
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_10T_FDX
value|0x0040
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_100TX
value|0x0080
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_100TX_FDX
value|0x0100
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_100T4
value|0x0200
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_APAUSE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_RFAULT
value|0x2000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_ACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANLPAR_NP
value|0x8000
end_define

begin_comment
comment|/* Autonegotiation expansion register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_ANER
value|0x06
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANER_LPNWAY
value|0x0001
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANER_PRCVD
value|0x0002
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANER_NEXTP
value|0x0004
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANER_LPNEXTP
value|0x0008
end_define

begin_define
define|#
directive|define
name|IP1000PHY_ANER_PDF
value|0x0100
end_define

begin_comment
comment|/* Autonegotiation next page transmit register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_NEXTP
value|0x07
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTP_MSGC
value|0x0001
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTP_TOGGLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTP_ACK2
value|0x1000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTP_MSGP
value|0x2000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTP_NEXTP
value|0x8000
end_define

begin_comment
comment|/* Autonegotiation link partner next page register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_NEXTPLP
value|0x08
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTPLP_MSGC
value|0x0001
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTPLP_TOGGLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTPLP_ACK2
value|0x1000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTPLP_MSGP
value|0x2000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTPLP_ACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_NEXTPLP_NEXTP
value|0x8000
end_define

begin_comment
comment|/* 1000baseT control register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_1000CR
value|0x09
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_1000T
value|0x0100
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_1000T_FDX
value|0x0200
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_MASTER
value|0x0400
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_MMASTER
value|0x0800
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_MANUAL
value|0x1000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_TMNORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_TM1
value|0x2000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_TM2
value|0x4000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_TM3
value|0x6000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000CR_TM4
value|0x8000
end_define

begin_comment
comment|/* 1000baseT status register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_1000SR
value|0x0A
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000SR_LP
value|0x0400
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000SR_LP_FDX
value|0x0800
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000SR_RXSTAT
value|0x1000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000SR_LRXSTAT
value|0x2000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000SR_MASTER
value|0x4000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_1000SR_MASTERF
value|0x8000
end_define

begin_comment
comment|/* Extended status register */
end_comment

begin_define
define|#
directive|define
name|IP1000PHY_MII_EXTSTS
value|0x0F
end_define

begin_define
define|#
directive|define
name|IP1000PHY_EXTSTS_1000T
value|0x1000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_EXTSTS_1000T_FDX
value|0x2000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_EXTSTS_1000X
value|0x4000
end_define

begin_define
define|#
directive|define
name|IP1000PHY_EXTSTS_1000X_FDX
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_IP1000PHYREG_H_ */
end_comment

end_unit

