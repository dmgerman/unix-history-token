begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: nsphyterreg.h,v 1.4 2005/12/11 12:22:42 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999, 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_NSPHYTERREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_NSPHYTERREG_H_
end_define

begin_comment
comment|/*  * DP83843 registers; We also have the MacPHYTER (DP83815) internal  * PHY register definitions here, since the two are, for our purposes,  * compatible.  */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_PHYSTS
value|0x10
end_define

begin_comment
comment|/* PHY status */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_REL
value|0x8000
end_define

begin_comment
comment|/* receive error latch */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_CIML
value|0x4000
end_define

begin_comment
comment|/* CIM latch */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_FCSL
value|0x2000
end_define

begin_comment
comment|/* false carrier sense latch */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_DEVRDY
value|0x0800
end_define

begin_comment
comment|/* device ready */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_PGRX
value|0x0400
end_define

begin_comment
comment|/* page received */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_ANEGEN
value|0x0200
end_define

begin_comment
comment|/* autoneg. enabled */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MIIINTR
value|0x0100
end_define

begin_comment
comment|/* MII interrupt */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_REMFAULT
value|0x0080
end_define

begin_comment
comment|/* remote fault */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_JABBER
value|0x0040
end_define

begin_comment
comment|/* jabber detect */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_NWAYCOMP
value|0x0020
end_define

begin_comment
comment|/* NWAY complete */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_RESETSTAT
value|0x0010
end_define

begin_comment
comment|/* reset status */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_LOOPBACK
value|0x0008
end_define

begin_comment
comment|/* loopback status */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_DUPLEX
value|0x0004
end_define

begin_comment
comment|/* full duplex */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_SPEED10
value|0x0002
end_define

begin_comment
comment|/* speed == 10Mb/s */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_LINK
value|0x0001
end_define

begin_comment
comment|/* link up */
end_comment

begin_comment
comment|/* Below are the MacPHYTER bits that are different. */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_REL
value|0x2000
end_define

begin_comment
comment|/* receive error latch */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_POLARITY
value|0x1000
end_define

begin_comment
comment|/* polarity inverted */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_FCSL
value|0x0800
end_define

begin_comment
comment|/* false carrier sense latch */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_SIGNAL
value|0x0400
end_define

begin_comment
comment|/* signal detect */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_DESCRLK
value|0x0200
end_define

begin_comment
comment|/* de-scrambler lock */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_PGRX
value|0x0100
end_define

begin_comment
comment|/* page received */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_MIIINTR
value|0x0080
end_define

begin_comment
comment|/* MII interrupt */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_REMFAULT
value|0x0040
end_define

begin_comment
comment|/* remote fault */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_JABBER
value|0x0020
end_define

begin_comment
comment|/* jabber detect */
end_comment

begin_define
define|#
directive|define
name|PHYSTS_MP_NWAYCOMP
value|0x0010
end_define

begin_comment
comment|/* NWAY complete */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_MIPSCR
value|0x11
end_define

begin_comment
comment|/* MII interrupt PHY specific 					   control */
end_comment

begin_define
define|#
directive|define
name|MIPSCR_INTEN
value|0x0002
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|MIPSCR_TINT
value|0x0001
end_define

begin_comment
comment|/* test interrupt */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_MIPGSR
value|0x12
end_define

begin_comment
comment|/* MII interrupt PHY generic 					   status */
end_comment

begin_define
define|#
directive|define
name|MIPGSR_MINT
value|0x8000
end_define

begin_comment
comment|/* MII interrupt pending */
end_comment

begin_comment
comment|/* The bits below are MacPHYTER only. */
end_comment

begin_define
define|#
directive|define
name|MIPGSR_MSK_LINK
value|0x4000
end_define

begin_comment
comment|/* mask link status event */
end_comment

begin_define
define|#
directive|define
name|MIPGSR_MSK_JAB
value|0x2000
end_define

begin_comment
comment|/* mask jabber event */
end_comment

begin_define
define|#
directive|define
name|MIPGSR_MSK_RF
value|0x1000
end_define

begin_comment
comment|/* mask remote fault event */
end_comment

begin_define
define|#
directive|define
name|MIPGSR_MSK_ANC
value|0x0800
end_define

begin_comment
comment|/* mask auto-neg complete event */
end_comment

begin_define
define|#
directive|define
name|MIPGSR_MSK_FHF
value|0x0400
end_define

begin_comment
comment|/* mask false carrier half full event */
end_comment

begin_define
define|#
directive|define
name|MIPGSR_MSK_RHF
value|0x0200
end_define

begin_comment
comment|/* mask RX error half full event */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_DCR
value|0x13
end_define

begin_comment
comment|/* Disconnect counter */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_FCSCR
value|0x14
end_define

begin_comment
comment|/* False carrier sense counter */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_RECR
value|0x15
end_define

begin_comment
comment|/* Receive error counter */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_PCSR
value|0x16
end_define

begin_comment
comment|/* PCS configuration and status */
end_comment

begin_define
define|#
directive|define
name|PCSR_SINGLE_SD
value|0x8000
end_define

begin_comment
comment|/* single-ended SD mode */
end_comment

begin_define
define|#
directive|define
name|PCSR_FEFI_EN
value|0x4000
end_define

begin_comment
comment|/* far end fault indication mode */
end_comment

begin_define
define|#
directive|define
name|PCSR_DESCR_TO_RST
value|0x2000
end_define

begin_comment
comment|/* reset descrambler timeout counter */
end_comment

begin_define
define|#
directive|define
name|PCSR_DESCR_TO_SEL
value|0x1000
end_define

begin_comment
comment|/* descrambler timer mode */
end_comment

begin_define
define|#
directive|define
name|PCSR_DESCR_TO_DIS
value|0x0800
end_define

begin_comment
comment|/* descrambler timer disable */
end_comment

begin_define
define|#
directive|define
name|PCSR_LD_SCR_SD
value|0x0400
end_define

begin_comment
comment|/* load scrambler seed */
end_comment

begin_define
define|#
directive|define
name|PCSR_TX_QUIET
value|0x0200
end_define

begin_comment
comment|/* 100Mb/s transmit true quiet mode */
end_comment

begin_define
define|#
directive|define
name|PCSR_TX_PATTERN
value|0x0180
end_define

begin_comment
comment|/* 100Mb/s transmit test pattern */
end_comment

begin_define
define|#
directive|define
name|PCSR_F_LINK_100
value|0x0040
end_define

begin_comment
comment|/* force good link in 100Mb/s */
end_comment

begin_define
define|#
directive|define
name|PCSR_CIM_DIS
value|0x0020
end_define

begin_comment
comment|/* carrier integrity monitor disable */
end_comment

begin_define
define|#
directive|define
name|PCSR_CIM_STATUS
value|0x0010
end_define

begin_comment
comment|/* carrier integrity monitor status */
end_comment

begin_define
define|#
directive|define
name|PCSR_CODE_ERR
value|0x0008
end_define

begin_comment
comment|/* code errors */
end_comment

begin_define
define|#
directive|define
name|PCSR_PME_ERR
value|0x0004
end_define

begin_comment
comment|/* premature end errors */
end_comment

begin_define
define|#
directive|define
name|PCSR_LINK_ERR
value|0x0002
end_define

begin_comment
comment|/* link errors */
end_comment

begin_define
define|#
directive|define
name|PCSR_PKT_ERR
value|0x0001
end_define

begin_comment
comment|/* packet errors */
end_comment

begin_comment
comment|/* Below are the MacPHYTER bits that are different. */
end_comment

begin_define
define|#
directive|define
name|PCSR_MP_BYP_4B5B
value|0x1000
end_define

begin_comment
comment|/* bypass encoder */
end_comment

begin_define
define|#
directive|define
name|PCSR_MP_FREE_CLK
value|0x0800
end_define

begin_comment
comment|/* free funning RX clock */
end_comment

begin_define
define|#
directive|define
name|PCSR_MP_TQ_EN
value|0x0400
end_define

begin_comment
comment|/* enable True Quiet mode */
end_comment

begin_define
define|#
directive|define
name|PCSR_MP_SD_FORCE_B
value|0x0200
end_define

begin_comment
comment|/* force signal detection */
end_comment

begin_define
define|#
directive|define
name|PCSR_MP_SD_OPTION
value|0x0100
end_define

begin_comment
comment|/* enhanced signal detection alg. */
end_comment

begin_define
define|#
directive|define
name|PCSR_MP_NRZI_BYPASS
value|0x0004
end_define

begin_comment
comment|/* NRZI bypass enabled */
end_comment

begin_comment
comment|/* The bits below are not on MacPHYTER. */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_LBR
value|0x17
end_define

begin_comment
comment|/* loopback and bypass */
end_comment

begin_define
define|#
directive|define
name|LBR_BP_STRETCH
value|0x4000
end_define

begin_comment
comment|/* bypass LED stretching */
end_comment

begin_define
define|#
directive|define
name|LBR_BP_4B5B
value|0x2000
end_define

begin_comment
comment|/* bypass encoding/decoding */
end_comment

begin_define
define|#
directive|define
name|LBR_BP_SCR
value|0x1000
end_define

begin_comment
comment|/* bypass scrambler/descrambler */
end_comment

begin_define
define|#
directive|define
name|LBR_BP_RX
value|0x0800
end_define

begin_comment
comment|/* bypass receive function */
end_comment

begin_define
define|#
directive|define
name|LBR_BP_TX
value|0x0400
end_define

begin_comment
comment|/* bypass transmit function */
end_comment

begin_define
define|#
directive|define
name|LBR_100_DP_CTL
value|0x0380
end_define

begin_comment
comment|/* 100Mb/s data patch control */
end_comment

begin_define
define|#
directive|define
name|LBR_TW_LBEN
value|0x0020
end_define

begin_comment
comment|/* TWISTER loopback enable */
end_comment

begin_define
define|#
directive|define
name|LBR_10_ENDEC_LB
value|0x0010
end_define

begin_comment
comment|/* 10Mb/s ENDEC loopback */
end_comment

begin_comment
comment|/* The bits below are not on MacPHYTER. */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_10BTSCR
value|0x18
end_define

begin_comment
comment|/* 10baseT status and control */
end_comment

begin_define
define|#
directive|define
name|BTSCR_AUI_TPI
value|0x2000
end_define

begin_comment
comment|/* TREX operating mode */
end_comment

begin_define
define|#
directive|define
name|BTSCR_RX_SERIAL
value|0x1000
end_define

begin_comment
comment|/* 10baseT RX serial mode */
end_comment

begin_define
define|#
directive|define
name|BTSCR_TX_SERIAL
value|0x0800
end_define

begin_comment
comment|/* 10baseT TX serial mode */
end_comment

begin_define
define|#
directive|define
name|BTSCR_POL_DS
value|0x0400
end_define

begin_comment
comment|/* polarity detection and correction 					   disable */
end_comment

begin_define
define|#
directive|define
name|BTSCR_AUTOSW_EN
value|0x0200
end_define

begin_comment
comment|/* AUI/TPI autoswitch */
end_comment

begin_define
define|#
directive|define
name|BTSCR_LP_DS
value|0x0100
end_define

begin_comment
comment|/* link pulse disable */
end_comment

begin_define
define|#
directive|define
name|BTSCR_HB_DS
value|0x0080
end_define

begin_comment
comment|/* heartbeat disabled */
end_comment

begin_define
define|#
directive|define
name|BTSCR_LS_SEL
value|0x0040
end_define

begin_comment
comment|/* low squelch select */
end_comment

begin_define
define|#
directive|define
name|BTSCR_AUI_SEL
value|0x0020
end_define

begin_comment
comment|/* AUI select */
end_comment

begin_define
define|#
directive|define
name|BTSCR_JAB_DS
value|0x0010
end_define

begin_comment
comment|/* jabber disable */
end_comment

begin_define
define|#
directive|define
name|BTSCR_THIN_SEL
value|0x0008
end_define

begin_comment
comment|/* thin ethernet select */
end_comment

begin_define
define|#
directive|define
name|BTSCR_TX_FILT_DS
value|0x0004
end_define

begin_comment
comment|/* TPI receive filter disable */
end_comment

begin_define
define|#
directive|define
name|MII_NSPHYTER_PHYCTRL
value|0x19
end_define

begin_comment
comment|/* PHY control */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_TW_EQSEL
value|0x3000
end_define

begin_comment
comment|/* TWISTER e.q. select */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_BLW_DS
value|0x0800
end_define

begin_comment
comment|/* TWISTER base line wander disable */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_REPEATER
value|0x0200
end_define

begin_comment
comment|/* repeater mode */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_LED_TXRX_MODE
value|0x0180
end_define

begin_comment
comment|/* LED TX/RX mode */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_LED_DUP_MODE
value|0x0040
end_define

begin_comment
comment|/* LED DUP mode */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_FX_EN
value|0x0020
end_define

begin_comment
comment|/* Fiber mode enable */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_PHYADDR
value|0x001f
end_define

begin_comment
comment|/* PHY address */
end_comment

begin_comment
comment|/* Below are the MacPHYTER bits that are different. */
end_comment

begin_define
define|#
directive|define
name|PHYCRTL_MP_PSR_15
value|0x0800
end_define

begin_comment
comment|/* BIST sequence select */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_MP_BIST_STAT
value|0x0400
end_define

begin_comment
comment|/* BIST passed */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_MP_BIST_START
value|0x0200
end_define

begin_comment
comment|/* start BIST */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_MP_BP_STRETCH
value|0x0100
end_define

begin_comment
comment|/* bypass LED stretching */
end_comment

begin_define
define|#
directive|define
name|PHYCTRL_MP_PAUSE_STS
value|0x0080
end_define

begin_comment
comment|/* pause status */
end_comment

begin_comment
comment|/* The bits below are MacPHYTER only. */
end_comment

begin_define
define|#
directive|define
name|MII_MACPHYTER_TBTCTL
value|0x1a
end_define

begin_comment
comment|/* 10baseT Control */
end_comment

begin_define
define|#
directive|define
name|TBTCTL_LOOPBACK_10_DIS
value|0x0100
end_define

begin_comment
comment|/* loopback 10Mb/s disable */
end_comment

begin_define
define|#
directive|define
name|TBTCTL_LP_DIS
value|0x0080
end_define

begin_comment
comment|/* link pulse disable */
end_comment

begin_define
define|#
directive|define
name|TBTCTL_FORCE_LINK_10
value|0x0040
end_define

begin_comment
comment|/* force 10Mb/s link good */
end_comment

begin_define
define|#
directive|define
name|TBTCTL_FORCE_POL_COR
value|0x0020
end_define

begin_comment
comment|/* force polarity correction */
end_comment

begin_define
define|#
directive|define
name|TBTCTL_INV_POLARITY
value|0x0010
end_define

begin_comment
comment|/* inverted polarity */
end_comment

begin_define
define|#
directive|define
name|TBTCTL_AUTOPOL_DIS
value|0x0008
end_define

begin_comment
comment|/* auto-polarity disable */
end_comment

begin_define
define|#
directive|define
name|TBTCTL_HEARTBEAT_DIS
value|0x0002
end_define

begin_comment
comment|/* heartbeat disable */
end_comment

begin_define
define|#
directive|define
name|TBTCTL_JABBER_DIS
value|0x0001
end_define

begin_comment
comment|/* jabber disable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_NSPHYTERREG_H_ */
end_comment

end_unit

