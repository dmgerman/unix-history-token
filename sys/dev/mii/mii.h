begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: mii.h,v 1.1 1998/08/10 23:55:17 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Manuel Bouyer.  All rights reserved.  *  * Modification to match BSD/OS 3.0 MII interface by Jason R. Thorpe,  * Numerical Aerospace Simulation Facility, NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Manuel Bouyer.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_MII_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_MII_H_
end_define

begin_comment
comment|/*  * Registers common to all PHYs.  */
end_comment

begin_define
define|#
directive|define
name|MII_NPHY
value|32
end_define

begin_comment
comment|/* max # of PHYs per MII */
end_comment

begin_comment
comment|/*  * MII commands, used if a device must drive the MII lines  * manually.  */
end_comment

begin_define
define|#
directive|define
name|MII_COMMAND_START
value|0x01
end_define

begin_define
define|#
directive|define
name|MII_COMMAND_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|MII_COMMAND_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|MII_COMMAND_ACK
value|0x02
end_define

begin_define
define|#
directive|define
name|MII_BMCR
value|0x00
end_define

begin_comment
comment|/* Basic mode control register (rw) */
end_comment

begin_define
define|#
directive|define
name|BMCR_RESET
value|0x8000
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|BMCR_LOOP
value|0x4000
end_define

begin_comment
comment|/* loopback */
end_comment

begin_define
define|#
directive|define
name|BMCR_S100
value|0x2000
end_define

begin_comment
comment|/* speed (10/100) select */
end_comment

begin_define
define|#
directive|define
name|BMCR_AUTOEN
value|0x1000
end_define

begin_comment
comment|/* autonegotiation enable */
end_comment

begin_define
define|#
directive|define
name|BMCR_PDOWN
value|0x0800
end_define

begin_comment
comment|/* power down */
end_comment

begin_define
define|#
directive|define
name|BMCR_ISO
value|0x0400
end_define

begin_comment
comment|/* isolate */
end_comment

begin_define
define|#
directive|define
name|BMCR_STARTNEG
value|0x0200
end_define

begin_comment
comment|/* restart autonegotiation */
end_comment

begin_define
define|#
directive|define
name|BMCR_FDX
value|0x0100
end_define

begin_comment
comment|/* Set duplex mode */
end_comment

begin_define
define|#
directive|define
name|BMCR_CTEST
value|0x0080
end_define

begin_comment
comment|/* collision test */
end_comment

begin_define
define|#
directive|define
name|MII_BMSR
value|0x01
end_define

begin_comment
comment|/* Basic mode status register (ro) */
end_comment

begin_define
define|#
directive|define
name|BMSR_100T4
value|0x8000
end_define

begin_comment
comment|/* 100 base T4 capable */
end_comment

begin_define
define|#
directive|define
name|BMSR_100TXFDX
value|0x4000
end_define

begin_comment
comment|/* 100 base Tx full duplex capable */
end_comment

begin_define
define|#
directive|define
name|BMSR_100TXHDX
value|0x2000
end_define

begin_comment
comment|/* 100 base Tx half duplex capable */
end_comment

begin_define
define|#
directive|define
name|BMSR_10TFDX
value|0x1000
end_define

begin_comment
comment|/* 10 base T full duplex capable */
end_comment

begin_define
define|#
directive|define
name|BMSR_10THDX
value|0x0800
end_define

begin_comment
comment|/* 10 base T half duplex capable */
end_comment

begin_define
define|#
directive|define
name|BMSR_ACOMP
value|0x0020
end_define

begin_comment
comment|/* Autonegotiation complete */
end_comment

begin_define
define|#
directive|define
name|BMSR_RFAULT
value|0x0010
end_define

begin_comment
comment|/* Link partner fault */
end_comment

begin_define
define|#
directive|define
name|BMSR_ANEG
value|0x0008
end_define

begin_comment
comment|/* Autonegotiation capable */
end_comment

begin_define
define|#
directive|define
name|BMSR_LINK
value|0x0004
end_define

begin_comment
comment|/* Link status */
end_comment

begin_define
define|#
directive|define
name|BMSR_JABBER
value|0x0002
end_define

begin_comment
comment|/* Jabber detected */
end_comment

begin_define
define|#
directive|define
name|BMSR_EXT
value|0x0001
end_define

begin_comment
comment|/* Extended capability */
end_comment

begin_define
define|#
directive|define
name|BMSR_MEDIAMASK
value|(BMSR_100T4|BMSR_100TXFDX|BMSR_100TXHDX|BMSR_10TFDX| \ 			 BMSR_10THDX|BMSR_ANEG)
end_define

begin_comment
comment|/*  * Convert BMSR media capabilities to ANAR bits for autonegotiation.  * Note the shift chopps off the BMSR_ANEG bit.  */
end_comment

begin_define
define|#
directive|define
name|BMSR_MEDIA_TO_ANAR
parameter_list|(
name|x
parameter_list|)
value|(((x)& BMSR_MEDIAMASK)>> 6)
end_define

begin_define
define|#
directive|define
name|MII_PHYIDR1
value|0x02
end_define

begin_comment
comment|/* ID register 1 (ro) */
end_comment

begin_define
define|#
directive|define
name|MII_PHYIDR2
value|0x03
end_define

begin_comment
comment|/* ID register 2 (ro) */
end_comment

begin_define
define|#
directive|define
name|IDR2_OUILSB
value|0xfc00
end_define

begin_comment
comment|/* OUI LSB */
end_comment

begin_define
define|#
directive|define
name|IDR2_MODEL
value|0x03f0
end_define

begin_comment
comment|/* vendor model */
end_comment

begin_define
define|#
directive|define
name|IDR2_REV
value|0x000f
end_define

begin_comment
comment|/* vendor revision */
end_comment

begin_define
define|#
directive|define
name|MII_OUI
parameter_list|(
name|id1
parameter_list|,
name|id2
parameter_list|)
value|(((id1)<< 6) | ((id2)>> 10))
end_define

begin_define
define|#
directive|define
name|MII_MODEL
parameter_list|(
name|id2
parameter_list|)
value|(((id2)& IDR2_MODEL)>> 4)
end_define

begin_define
define|#
directive|define
name|MII_REV
parameter_list|(
name|id2
parameter_list|)
value|((id2)& IDR2_REV)
end_define

begin_define
define|#
directive|define
name|MII_ANAR
value|0x04
end_define

begin_comment
comment|/* Autonegotiation advertisement (rw) */
end_comment

begin_define
define|#
directive|define
name|ANAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page (ro) */
end_comment

begin_define
define|#
directive|define
name|ANAR_ACK
value|0x4000
end_define

begin_comment
comment|/* link partner abilities acknowledged (ro) */
end_comment

begin_define
define|#
directive|define
name|ANAR_RF
value|0x2000
end_define

begin_comment
comment|/* remote fault (ro) */
end_comment

begin_define
define|#
directive|define
name|ANAR_T4
value|0x0200
end_define

begin_comment
comment|/* local device supports 100bT4 */
end_comment

begin_define
define|#
directive|define
name|ANAR_TX_FD
value|0x0100
end_define

begin_comment
comment|/* local device supports 100bTx FD */
end_comment

begin_define
define|#
directive|define
name|ANAR_TX
value|0x0080
end_define

begin_comment
comment|/* local device supports 100bTx */
end_comment

begin_define
define|#
directive|define
name|ANAR_10_FD
value|0x0040
end_define

begin_comment
comment|/* local device supports 10bT FD */
end_comment

begin_define
define|#
directive|define
name|ANAR_10
value|0x0020
end_define

begin_comment
comment|/* local device supports 10bT */
end_comment

begin_define
define|#
directive|define
name|ANAR_CSMA
value|0x0001
end_define

begin_comment
comment|/* protocol selector CSMA/CD */
end_comment

begin_define
define|#
directive|define
name|MII_ANLPAR
value|0x05
end_define

begin_comment
comment|/* Autonegotiation lnk partner abilities (rw) */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_NP
value|0x8000
end_define

begin_comment
comment|/* Next page (ro) */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_ACK
value|0x4000
end_define

begin_comment
comment|/* link partner accepted ACK (ro) */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_RF
value|0x2000
end_define

begin_comment
comment|/* remote fault (ro) */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_T4
value|0x0200
end_define

begin_comment
comment|/* link partner supports 100bT4 */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_TX_FD
value|0x0100
end_define

begin_comment
comment|/* link partner supports 100bTx FD */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_TX
value|0x0080
end_define

begin_comment
comment|/* link partner supports 100bTx */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_10_FD
value|0x0040
end_define

begin_comment
comment|/* link partner supports 10bT FD */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_10
value|0x0020
end_define

begin_comment
comment|/* link partner supports 10bT */
end_comment

begin_define
define|#
directive|define
name|ANLPAR_CSMA
value|0x0001
end_define

begin_comment
comment|/* protocol selector CSMA/CD */
end_comment

begin_define
define|#
directive|define
name|MII_ANER
value|0x06
end_define

begin_comment
comment|/* Autonegotiation expansion (ro) */
end_comment

begin_define
define|#
directive|define
name|ANER_MLF
value|0x0010
end_define

begin_comment
comment|/* multiple link detection fault */
end_comment

begin_define
define|#
directive|define
name|ANER_LPNP
value|0x0008
end_define

begin_comment
comment|/* link parter next page-able */
end_comment

begin_define
define|#
directive|define
name|ANER_NP
value|0x0004
end_define

begin_comment
comment|/* next page-able */
end_comment

begin_define
define|#
directive|define
name|ANER_PAGE_RX
value|0x0002
end_define

begin_comment
comment|/* Page received */
end_comment

begin_define
define|#
directive|define
name|ANER_LPAN
value|0x0001
end_define

begin_comment
comment|/* link parter autoneg-able */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_MII_H_ */
end_comment

end_unit

