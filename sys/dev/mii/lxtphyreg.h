begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	OpenBSD: lxtphyreg.h,v 1.1 1998/11/11 19:34:47 jason Exp 	*/
end_comment

begin_comment
comment|/*	NetBSD: lxtphyreg.h,v 1.1 1998/10/24 00:33:17 thorpej Exp 	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_LXTPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_LXTPHYREG_H_
end_define

begin_comment
comment|/*  * LXT970 registers.  */
end_comment

begin_define
define|#
directive|define
name|MII_LXTPHY_MIRROR
value|0x10
end_define

begin_comment
comment|/* Mirror register */
end_comment

begin_comment
comment|/* All bits user-defined */
end_comment

begin_define
define|#
directive|define
name|MII_LXTPHY_IER
value|0x11
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|IER_MIIDRVLVL
value|0x0008
end_define

begin_comment
comment|/* Rediced MII driver levels */
end_comment

begin_define
define|#
directive|define
name|IER_LNK_CRITERIA
value|0x0004
end_define

begin_comment
comment|/* Enhanced Link Loss Criteria */
end_comment

begin_define
define|#
directive|define
name|IER_INTEN
value|0x0002
end_define

begin_comment
comment|/* Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IER_TINT
value|0x0001
end_define

begin_comment
comment|/* Force Interrupt */
end_comment

begin_define
define|#
directive|define
name|MII_LXTPHY_ISR
value|0x12
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|ISR_MINT
value|0x8000
end_define

begin_comment
comment|/* MII Interrupt Pending */
end_comment

begin_define
define|#
directive|define
name|ISR_XTALOK
value|0x4000
end_define

begin_comment
comment|/* Clocks OK */
end_comment

begin_define
define|#
directive|define
name|MII_LXTPHY_CONFIG
value|0x13
end_define

begin_comment
comment|/* Configuration Register */
end_comment

begin_define
define|#
directive|define
name|CONFIG_TXMIT_TEST
value|0x4000
end_define

begin_comment
comment|/* 100base-T Transmit Test */
end_comment

begin_define
define|#
directive|define
name|CONFIG_REPEATER
value|0x2000
end_define

begin_comment
comment|/* Repeater Mode */
end_comment

begin_define
define|#
directive|define
name|CONFIG_MDIO_INT
value|0x1000
end_define

begin_comment
comment|/* Enable intr signalling on MDIO */
end_comment

begin_define
define|#
directive|define
name|CONFIG_TPLOOP
value|0x0800
end_define

begin_comment
comment|/* Disable 10base-T Loopback */
end_comment

begin_define
define|#
directive|define
name|CONFIG_SQE
value|0x0400
end_define

begin_comment
comment|/* Enable SQE */
end_comment

begin_define
define|#
directive|define
name|CONFIG_DISJABBER
value|0x0200
end_define

begin_comment
comment|/* Disable Jabber */
end_comment

begin_define
define|#
directive|define
name|CONFIG_DISLINKTEST
value|0x0100
end_define

begin_comment
comment|/* Disable Link Test */
end_comment

begin_define
define|#
directive|define
name|CONFIG_LEDC1
value|0x0080
end_define

begin_comment
comment|/* LEDC configuration */
end_comment

begin_define
define|#
directive|define
name|CONFIG_LEDC0
value|0x0040
end_define

begin_comment
comment|/* ... */
end_comment

begin_comment
comment|/* 0 0 LEDC indicates collision */
end_comment

begin_comment
comment|/* 0 1 LEDC is off */
end_comment

begin_comment
comment|/* 1 0 LEDC indicates activity */
end_comment

begin_comment
comment|/* 1 1 LEDC is on */
end_comment

begin_define
define|#
directive|define
name|CONFIG_ADVTXCLK
value|0x0020
end_define

begin_comment
comment|/* Advance TX clock */
end_comment

begin_define
define|#
directive|define
name|CONFIG_5BSYMBOL
value|0x0010
end_define

begin_comment
comment|/* 5-bit Symbol mode */
end_comment

begin_define
define|#
directive|define
name|CONFIG_SCRAMBLER
value|0x0008
end_define

begin_comment
comment|/* Bypass scrambler */
end_comment

begin_define
define|#
directive|define
name|CONFIG_100BASEFX
value|0x0004
end_define

begin_comment
comment|/* 100base-FX */
end_comment

begin_define
define|#
directive|define
name|CONFIG_TXDISCON
value|0x0001
end_define

begin_comment
comment|/* Disconnect TP transmitter */
end_comment

begin_define
define|#
directive|define
name|MII_LXTPHY_CSR
value|0x14
end_define

begin_comment
comment|/* Chip Status Register */
end_comment

begin_define
define|#
directive|define
name|CSR_LINK
value|0x2000
end_define

begin_comment
comment|/* Link is up */
end_comment

begin_define
define|#
directive|define
name|CSR_DUPLEX
value|0x1000
end_define

begin_comment
comment|/* Full-duplex */
end_comment

begin_define
define|#
directive|define
name|CSR_SPEED
value|0x0800
end_define

begin_comment
comment|/* 100Mbps */
end_comment

begin_define
define|#
directive|define
name|CSR_ACOMP
value|0x0400
end_define

begin_comment
comment|/* Autonegotiation complete */
end_comment

begin_define
define|#
directive|define
name|CSR_PAGERCVD
value|0x0200
end_define

begin_comment
comment|/* Link page received */
end_comment

begin_define
define|#
directive|define
name|CSR_LOWVCC
value|0x0004
end_define

begin_comment
comment|/* Low Voltage Fault */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_LXTPHYREG_H_ */
end_comment

end_unit

