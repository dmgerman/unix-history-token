begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: icsphyreg.h,v 1.2 2003/07/01 22:46:08 msaitoh Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_ICSPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_ICSPHYREG_H_
end_define

begin_comment
comment|/*  * ICS1890 registers.  *	http://www.icst.com/pdf/18??.pdf  */
end_comment

begin_comment
comment|/* HEX				1889	1890	1892	1893  *--------------------------------------------------------------  *  0 Control			*	*	*	*  *  1 Status			*	*	*	*  *  2 PHY Identifier		*	*	*	*  *  3 PHY Identifier		*	*	*	*  *  4 Auto-Neg. Advertisement		*	*	*  *  5 Auto-Neg. Link Parent Adv		*	*	*  *  6 Auto-Neg. Expansion		*	*	*  *  7 Auto-Neg. Next Page Tx			*	*  *  8 ANg Nxt Page Lnk Parnt Abl		*	*  * 10 Extended Control		*	*	*	*  * 11 Quick Poll Status		*	*	*	*  * 12 10Base-T Operation		*	*	*  * 13 Extended Control2			*	*	*  */
end_comment

begin_define
define|#
directive|define
name|MII_ICSPHY_ECR
value|0x10
end_define

begin_comment
comment|/* Extended Control Register */
end_comment

begin_define
define|#
directive|define
name|ECR_OVR
value|0x8000
end_define

begin_comment
comment|/* disable command reg overwrites */
end_comment

begin_define
define|#
directive|define
name|ECR_PHYADDR_MASK
value|0x07c0
end_define

begin_comment
comment|/* PHY address mask */
end_comment

begin_define
define|#
directive|define
name|ECR_CTEST
value|0x0020
end_define

begin_comment
comment|/* Stream Cipher Test Mode */
end_comment

begin_define
define|#
directive|define
name|ECR_IECT
value|0x0004
end_define

begin_comment
comment|/* Invalid Error Code Test */
end_comment

begin_define
define|#
directive|define
name|ECR_SSD
value|0x0001
end_define

begin_comment
comment|/* Stream Cipher Disable */
end_comment

begin_define
define|#
directive|define
name|MII_ICSPHY_QPR
value|0x11
end_define

begin_comment
comment|/* Quick Poll Register */
end_comment

begin_define
define|#
directive|define
name|QPR_SPEED
value|0x8000
end_define

begin_comment
comment|/* 100Mbps */
end_comment

begin_define
define|#
directive|define
name|QPR_FDX
value|0x4000
end_define

begin_comment
comment|/* Full dupled */
end_comment

begin_define
define|#
directive|define
name|QPR_ANB2
value|0x2000
end_define

begin_comment
comment|/* Autoneg monitor bit 2 */
end_comment

begin_define
define|#
directive|define
name|QPR_ANB1
value|0x1000
end_define

begin_comment
comment|/* Autoneg monitor bit 1 */
end_comment

begin_define
define|#
directive|define
name|QPR_ANB0
value|0x0800
end_define

begin_comment
comment|/* Autoneg monitor bit 0 */
end_comment

begin_define
define|#
directive|define
name|QPR_RXERR
value|0x0400
end_define

begin_comment
comment|/* Receive signal lost */
end_comment

begin_define
define|#
directive|define
name|QPR_PLLERR
value|0x0200
end_define

begin_comment
comment|/* PLL error */
end_comment

begin_define
define|#
directive|define
name|QPR_FCARR
value|0x0100
end_define

begin_comment
comment|/* False carrier detected */
end_comment

begin_define
define|#
directive|define
name|QPR_INVALSYM
value|0x0080
end_define

begin_comment
comment|/* Invalid Symbol Detected */
end_comment

begin_define
define|#
directive|define
name|QPR_HALT
value|0x0040
end_define

begin_comment
comment|/* Halt Symbol Detected */
end_comment

begin_define
define|#
directive|define
name|QPR_PREEM
value|0x0020
end_define

begin_comment
comment|/* Two Idle Symbols together */
end_comment

begin_define
define|#
directive|define
name|QPR_ACOMP
value|0x0010
end_define

begin_comment
comment|/* Autonegotiation complete */
end_comment

begin_define
define|#
directive|define
name|QPR_SDETECT
value|0x0008
end_define

begin_comment
comment|/* signal detect */
end_comment

begin_define
define|#
directive|define
name|QPR_JABBER
value|0x0004
end_define

begin_comment
comment|/* Jabber detected */
end_comment

begin_define
define|#
directive|define
name|QPR_RFAULT
value|0x0002
end_define

begin_comment
comment|/* Remote Fault */
end_comment

begin_define
define|#
directive|define
name|QPR_LINK
value|0x0001
end_define

begin_comment
comment|/* Link */
end_comment

begin_define
define|#
directive|define
name|MII_ICSPHY_TTR
value|0x12
end_define

begin_comment
comment|/* 10baseT Operations Register */
end_comment

begin_define
define|#
directive|define
name|TTR_RJABBER
value|0x8000
end_define

begin_comment
comment|/* Remote Jabber */
end_comment

begin_define
define|#
directive|define
name|TTR_POLARITY
value|0x4000
end_define

begin_comment
comment|/* Polarity Reversed */
end_comment

begin_define
define|#
directive|define
name|TTR_NOJABBER
value|0x0020
end_define

begin_comment
comment|/* Disable Jabber Check */
end_comment

begin_define
define|#
directive|define
name|TTR_LOOP
value|0x0010
end_define

begin_comment
comment|/* Loopback mode */
end_comment

begin_define
define|#
directive|define
name|TTR_NOAPOLARITY
value|0x0008
end_define

begin_comment
comment|/* Disable auto polarity correction */
end_comment

begin_define
define|#
directive|define
name|TTR_NOSQE
value|0x0004
end_define

begin_comment
comment|/* Disable SQE check */
end_comment

begin_define
define|#
directive|define
name|TTR_NOLINK
value|0x0002
end_define

begin_comment
comment|/* Disable Link check */
end_comment

begin_define
define|#
directive|define
name|TTR_NOSQUELCH
value|0x0001
end_define

begin_comment
comment|/* Disable squelch */
end_comment

begin_comment
comment|/*  * Extended Control Register 2  *  * HEX					1889	1890	1892	1893  *-------------------------------------------------------------------  * 8000	Node/Repeater Mode			*	*	*  * 4000 Hardware/Software Mode			*	*	*  * 2000 Link Partner Support Remote Flt		*  * 2000 Remote Fault					*	*  * 1000  * 0800  * 0400 Xmitted Remote Fault status		*  * 0200  * 0100  * 0080 Tri-state Enable					*  * 0040  * 0020  * 0010 A-N Powerup Remote Flt			*  * 0008  * 0004  * 0002 Automatic 10Base-T Power Down			*  * 0001 Automatic 100Base-TX Power Down		*	*	*  */
end_comment

begin_define
define|#
directive|define
name|MII_ICSPHY_ECR2
value|0x13
end_define

begin_comment
comment|/* Extended Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|ECR2_REPEATER
value|0x8000
end_define

begin_comment
comment|/* Repeater Mode */
end_comment

begin_define
define|#
directive|define
name|ECR2_HWSW
value|0x4000
end_define

begin_comment
comment|/* hw/sw config priority */
end_comment

begin_define
define|#
directive|define
name|ECR2_LPRF
value|0x2000
end_define

begin_comment
comment|/* link partner supports rem fault */
end_comment

begin_define
define|#
directive|define
name|ECR2_FORCERF
value|0x0400
end_define

begin_comment
comment|/* Force transmit of rem fault */
end_comment

begin_define
define|#
directive|define
name|ECR2_RFPUP
value|0x0010
end_define

begin_comment
comment|/* A-N Powerup Remote fault */
end_comment

begin_define
define|#
directive|define
name|ECR2_10AUTOPWRDN
value|0x0002
end_define

begin_comment
comment|/* Automatic 10baseT power down */
end_comment

begin_define
define|#
directive|define
name|ECR2_100AUTOPWRDN
value|0x0001
end_define

begin_comment
comment|/* Automatic 100baseTX power down */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_ICSPHYREG_H_ */
end_comment

end_unit

