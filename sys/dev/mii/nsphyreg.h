begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: nsphyreg.h,v 1.1 1998/08/10 23:58:39 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_NSPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_NSPHYREG_H_
end_define

begin_comment
comment|/*  * DP83840 registers.  */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_DCR
value|0x12
end_define

begin_comment
comment|/* Disconnect counter */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_FCSCR
value|0x13
end_define

begin_comment
comment|/* False carrier sense counter */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_RECR
value|0x15
end_define

begin_comment
comment|/* Receive error counter */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_SRR
value|0x16
end_define

begin_comment
comment|/* Silicon revision */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_PCR
value|0x17
end_define

begin_comment
comment|/* PCS sub-layer configuration */
end_comment

begin_define
define|#
directive|define
name|PCR_NRZI
value|0x8000
end_define

begin_comment
comment|/* NRZI encoding enabled for 100TX */
end_comment

begin_define
define|#
directive|define
name|PCR_DESCRTOSEL
value|0x4000
end_define

begin_comment
comment|/* descrambler t/o select (2ms) */
end_comment

begin_define
define|#
directive|define
name|PCR_DESCRTODIS
value|0x2000
end_define

begin_comment
comment|/* descrambler t/o disable */
end_comment

begin_define
define|#
directive|define
name|PCR_REPEATER
value|0x1000
end_define

begin_comment
comment|/* repeater mode */
end_comment

begin_define
define|#
directive|define
name|PCR_ENCSEL
value|0x0800
end_define

begin_comment
comment|/* encoder mode select */
end_comment

begin_define
define|#
directive|define
name|PCR_CLK25MDIS
value|0x0080
end_define

begin_comment
comment|/* CLK25M disable */
end_comment

begin_define
define|#
directive|define
name|PCR_FLINK100
value|0x0040
end_define

begin_comment
comment|/* force good link in 100mbps */
end_comment

begin_define
define|#
directive|define
name|PCR_CIMDIS
value|0x0020
end_define

begin_comment
comment|/* carrier integrity monitor disable */
end_comment

begin_define
define|#
directive|define
name|PCR_TXOFF
value|0x0010
end_define

begin_comment
comment|/* force transmit off */
end_comment

begin_define
define|#
directive|define
name|PCR_LED1MODE
value|0x0004
end_define

begin_comment
comment|/* LED1 mode: see below */
end_comment

begin_define
define|#
directive|define
name|PCR_LED4MODE
value|0x0002
end_define

begin_comment
comment|/* LED4 mode: see below */
end_comment

begin_comment
comment|/*  * LED1 Mode:  *  *	1	LED1 output configured to PAR's CON_STATUS, useful for  *		network management in 100baseTX mode.  *  *	0	Normal LED1 operation - 10baseTX and 100baseTX transmission  *		activity.  *  * LED4 Mode:  *  *	1	LED4 output configured to indicate full-duplex in both  *		10baseT and 100baseTX modes.  *  *	0	LED4 output configured to indicate polarity in 10baseT  *		mode and full-duplex in 100baseTX mode.  */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_LBREMR
value|0x18
end_define

begin_comment
comment|/* Loopback, bypass, error mask */
end_comment

begin_define
define|#
directive|define
name|LBREMR_BADSSDEN
value|0x8000
end_define

begin_comment
comment|/* enable bad SSD detection */
end_comment

begin_define
define|#
directive|define
name|LBREMR_BP4B5B
value|0x4000
end_define

begin_comment
comment|/* bypass 4b/5b encoding */
end_comment

begin_define
define|#
directive|define
name|LBREMR_BPSCR
value|0x2000
end_define

begin_comment
comment|/* bypass scrambler */
end_comment

begin_define
define|#
directive|define
name|LBREMR_BPALIGN
value|0x1000
end_define

begin_comment
comment|/* bypass alignment function */
end_comment

begin_define
define|#
directive|define
name|LBREMR_10LOOP
value|0x0800
end_define

begin_comment
comment|/* 10baseT loopback */
end_comment

begin_define
define|#
directive|define
name|LBREMR_LB1
value|0x0200
end_define

begin_comment
comment|/* loopback ctl 1 */
end_comment

begin_define
define|#
directive|define
name|LBREMR_LB0
value|0x0100
end_define

begin_comment
comment|/* loopback ctl 0 */
end_comment

begin_define
define|#
directive|define
name|LBREMR_ALTCRS
value|0x0040
end_define

begin_comment
comment|/* alt crs operation */
end_comment

begin_define
define|#
directive|define
name|LBREMR_LOOPXMTDIS
value|0x0020
end_define

begin_comment
comment|/* disable transmit in 100TX loopbk */
end_comment

begin_define
define|#
directive|define
name|LBREMR_CODEERR
value|0x0010
end_define

begin_comment
comment|/* code errors */
end_comment

begin_define
define|#
directive|define
name|LBREMR_PEERR
value|0x0008
end_define

begin_comment
comment|/* premature end errors */
end_comment

begin_define
define|#
directive|define
name|LBREMR_LINKERR
value|0x0004
end_define

begin_comment
comment|/* link errors */
end_comment

begin_define
define|#
directive|define
name|LBREMR_PKTERR
value|0x0002
end_define

begin_comment
comment|/* packet errors */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_PAR
value|0x19
end_define

begin_comment
comment|/* Physical address and status */
end_comment

begin_define
define|#
directive|define
name|PAR_DISCRSJAB
value|0x0800
end_define

begin_comment
comment|/* disable car sense during jab */
end_comment

begin_define
define|#
directive|define
name|PAR_ANENSTAT
value|0x0400
end_define

begin_comment
comment|/* autoneg mode status */
end_comment

begin_define
define|#
directive|define
name|PAR_FEFIEN
value|0x0100
end_define

begin_comment
comment|/* far end fault enable */
end_comment

begin_define
define|#
directive|define
name|PAR_FDX
value|0x0080
end_define

begin_comment
comment|/* full duplex status */
end_comment

begin_define
define|#
directive|define
name|PAR_10
value|0x0040
end_define

begin_comment
comment|/* 10mbps mode */
end_comment

begin_define
define|#
directive|define
name|PAR_CON
value|0x0020
end_define

begin_comment
comment|/* connect status */
end_comment

begin_define
define|#
directive|define
name|PAR_AMASK
value|0x001f
end_define

begin_comment
comment|/* PHY address bits */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_10BTSR
value|0x1b
end_define

begin_comment
comment|/* 10baseT status */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHY_10BTCR
value|0x1c
end_define

begin_comment
comment|/* 10baseT configuration */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_NSPHYREG_H_ */
end_comment

end_unit

