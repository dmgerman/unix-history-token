begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 HAYAKAWA Koichi.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HAYAKAWA Koichi.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: pccbbreg.h,v 1.4 1999/08/02 01:35:50 kanaoka Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_PCI_PCCBBREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_PCI_PCCBBREG_H_
end_define

begin_define
define|#
directive|define
name|PCI_SOCKBASE
value|0x10
end_define

begin_comment
comment|/* Socket Base Address Register */
end_comment

begin_define
define|#
directive|define
name|PCI_BUSNUM
value|0x18
end_define

begin_comment
comment|/* latency timer, Subordinate bus number */
end_comment

begin_define
define|#
directive|define
name|PCI_BCR_INTR
value|0x3C
end_define

begin_comment
comment|/* intr line, intr pin, bridge control regs */
end_comment

begin_define
define|#
directive|define
name|PCI_LEGACY
value|0x44
end_define

begin_comment
comment|/* legacy IO register address (32 bits) */
end_comment

begin_define
define|#
directive|define
name|PCI_CBCTRL
value|0x90
end_define

begin_comment
comment|/* Retry status, Card ctrl, Device ctrl */
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_INTERFACE_MASK
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_INTERFACE_YENTA
value|0x06070000
end_define

begin_define
define|#
directive|define
name|PCI_BHLC_REG
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCI_LATTIMER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PCI_LATTIMER_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|PCI_LATTIMER
parameter_list|(
name|bhlcr
parameter_list|)
define|\
value|(((bhlcr)>> PCI_LATTIMER_SHIFT)& PCI_LATTIMER_MASK)
end_define

begin_define
define|#
directive|define
name|PCI_SOCKBASE
value|0x10
end_define

begin_comment
comment|/* Socket Base Address Register */
end_comment

begin_define
define|#
directive|define
name|PCI_BUSNUM
value|0x18
end_define

begin_comment
comment|/* latency timer, Subordinate bus number */
end_comment

begin_define
define|#
directive|define
name|PCI_BCR_INTR
value|0x3C
end_define

begin_comment
comment|/* intr line, intr pin, bridge control regs */
end_comment

begin_define
define|#
directive|define
name|PCI_LEGACY
value|0x44
end_define

begin_comment
comment|/* legacy IO register address (32 bits) */
end_comment

begin_define
define|#
directive|define
name|PCI_CBCTRL
value|0x90
end_define

begin_comment
comment|/* Retry status, Card ctrl, Device ctrl */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_EVENT
value|0x00
end_define

begin_comment
comment|/* offset of cardbus socket event reg */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_MASK
value|0x04
end_define

begin_comment
comment|/* offset of cardbus socket mask register */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT
value|0x08
end_define

begin_comment
comment|/* offset of cardbus socket present-state */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_FORCE
value|0x0c
end_define

begin_comment
comment|/* offset of cardbus socket force event */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL
value|0x10
end_define

begin_comment
comment|/* offset of cardbus socket control reg */
end_comment

begin_comment
comment|/* CardBus latency timer, Subordinate bus no, CardBus bus no and PCI bus no */
end_comment

begin_define
define|#
directive|define
name|PCI_CB_LSCP_REG
value|0x18
end_define

begin_comment
comment|/* CardBus memory and io windows */
end_comment

begin_define
define|#
directive|define
name|PCI_CB_MEMBASE0
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCI_CB_MEMLIMIT0
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_CB_MEMBASE1
value|0x24
end_define

begin_define
define|#
directive|define
name|PCI_CB_MEMLIMIT1
value|0x28
end_define

begin_define
define|#
directive|define
name|PCI_CB_IOBASE0
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCI_CB_IOLIMIT0
value|0x30
end_define

begin_define
define|#
directive|define
name|PCI_CB_IOBASE1
value|0x34
end_define

begin_define
define|#
directive|define
name|PCI_CB_IOLIMIT1
value|0x38
end_define

begin_comment
comment|/* PCI_CB_LSCP_REG */
end_comment

begin_define
define|#
directive|define
name|PCI_CB_LATENCY_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PCI_CB_LATENCY_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|PCI_CB_LATENCY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> PCI_CB_LATENCY_SHIFT)& PCI_CB_LATENCY_MASK)
end_define

begin_comment
comment|/* PCI_BCR_INTR bits for generic PCI-CardBus bridge */
end_comment

begin_define
define|#
directive|define
name|CB_BCR_INTR_IREQ_ENABLE
value|0x0800000
end_define

begin_define
define|#
directive|define
name|CB_BCR_WRITE_POST_ENABLE
value|0x4000000
end_define

begin_comment
comment|/*  PCI_CBCTRL bits for TI PCI113X */
end_comment

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_INT_SERIAL
value|0x040000
end_define

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_INT_ISA
value|0x020000
end_define

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_INT_MASK
value|0x060000
end_define

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_RIENB
value|0x8000
end_define

begin_comment
comment|/* Ring indicate output enable */
end_comment

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_ZVENAB
value|0x4000
end_define

begin_comment
comment|/* ZV mode enable */
end_comment

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_PCI_IRQ_ENA
value|0x2000
end_define

begin_comment
comment|/* PCI intr enable (funct and CSC) */
end_comment

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_PCI_INTR
value|0x1000
end_define

begin_comment
comment|/* PCI functional intr req */
end_comment

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_PCI_CSC
value|0x0800
end_define

begin_comment
comment|/* CSC intr route to PCI */
end_comment

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_PCI_CSC_D
value|0x0400
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_SPK_ENA
value|0x0200
end_define

begin_comment
comment|/* Speaker enable */
end_comment

begin_define
define|#
directive|define
name|PCI113X_CBCTRL_INTR_DET
value|0x0100
end_define

begin_comment
comment|/* functional interrupt detect */
end_comment

begin_comment
comment|/*  PCI_CBCTRL bits for TI PCI12XX */
end_comment

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_INT_SERIAL
value|0x040000
end_define

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_INT_ISA
value|0x020000
end_define

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_INT_PCI
value|0x000000
end_define

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_INT_MASK
value|0x060000
end_define

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_RIENB
value|0x8000
end_define

begin_comment
comment|/* Ring indicate output enable */
end_comment

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_ZVENAB
value|0x4000
end_define

begin_comment
comment|/* ZV mode enable */
end_comment

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_AUD2MUX
value|0x0400
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_SPK_ENA
value|0x0200
end_define

begin_comment
comment|/* Speaker enable */
end_comment

begin_define
define|#
directive|define
name|PCI12XX_CBCTRL_INTR_DET
value|0x0100
end_define

begin_comment
comment|/* functional interrupt detect */
end_comment

begin_comment
comment|/* PCI_BCR_INTR additional bit for RF5C46[567] */
end_comment

begin_define
define|#
directive|define
name|CB_BCRI_RL_3E0_ENA
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CB_BCRI_RL_3E2_ENA
value|0x10000000
end_define

begin_comment
comment|/*  * Special resister definition for Toshiba ToPIC95/97  * These values are borrowed from pcmcia-cs/Linux.  */
end_comment

begin_define
define|#
directive|define
name|TOPIC_SOCKET_CTRL
value|0x90
end_define

begin_define
define|#
directive|define
name|TOPIC_SOCKET_CTRL_SCR_IRQSEL
value|0x00000001
end_define

begin_comment
comment|/* PCI intr */
end_comment

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL
value|0xa0
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_SLOTON
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_SLOTEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_ID_LOCK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_ID_WP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_PORT_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_PORT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_OSF_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_OSF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_INTB
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_INTA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_INT_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_CLOCK_MASK
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_CLOCK_2
value|0x00000800
end_define

begin_comment
comment|/* PCI Clock/2 */
end_comment

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_CLOCK_1
value|0x00000400
end_define

begin_comment
comment|/* PCI Clock */
end_comment

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_CLOCK_0
value|0x00000000
end_define

begin_comment
comment|/* no clock */
end_comment

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_CARDBUS
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_VS1
value|0x04000000
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_VS2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TOPIC_SLOT_CTRL_SWDETECT
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TOPIC_REG_CTRL
value|0x00a4
end_define

begin_define
define|#
directive|define
name|TOPIC_REG_CTRL_RESUME_RESET
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TOPIC_REG_CTRL_REMOVE_RESET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TOPIC97_REG_CTRL_CLKRUN_ENA
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TOPIC97_REG_CTRL_TESTMODE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TOPIC97_REG_CTRL_IOPLUP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|TOPIC_REG_CTRL_BUFOFF_PWROFF
value|0x02000000
end_define

begin_define
define|#
directive|define
name|TOPIC_REG_CTRL_BUFOFF_SIGOFF
value|0x01000000
end_define

begin_define
define|#
directive|define
name|TOPIC97_REG_CTRL_CB_DEV_MASK
value|0x0000f800
end_define

begin_define
define|#
directive|define
name|TOPIC97_REG_CTRL_CB_DEV_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|TOPIC97_REG_CTRL_RI_DISABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TOPIC97_REG_CTRL_CAUDIO_OFF
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TOPIC_REG_CTRL_CAUDIO_INVERT
value|0x00000001
end_define

begin_comment
comment|/* socket event register (CB_SOCKET_EVENT) elements */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_EVENT_CSTS
value|0x01
end_define

begin_comment
comment|/* CARDSTS event occurs */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_EVENT_CD
value|0x06
end_define

begin_comment
comment|/* CD event occurs */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_EVENT_CD1
value|0x02
end_define

begin_comment
comment|/* CD1 event occurs */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_EVENT_CD2
value|0x04
end_define

begin_comment
comment|/* CD2 event occurs */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_EVENT_POWER
value|0x08
end_define

begin_comment
comment|/* Power cycle event occurs */
end_comment

begin_comment
comment|/* socket mask register (CB_SOCKET_MASK) elements */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_MASK_CSTS
value|0x01
end_define

begin_comment
comment|/* CARDSTS event mask */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_MASK_CD
value|0x06
end_define

begin_comment
comment|/* CD event mask */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_MASK_POWER
value|0x08
end_define

begin_comment
comment|/* Power cycle event mask */
end_comment

begin_comment
comment|/* socket present-state register (CB_SOCKET_STAT) elements */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_CARDSTS
value|0x01
end_define

begin_comment
comment|/* card status change bit */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_CD1
value|0x02
end_define

begin_comment
comment|/* card detect 1 */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_CD2
value|0x04
end_define

begin_comment
comment|/* card detect 2 */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_CD
value|0x06
end_define

begin_comment
comment|/* card detect 1 and 2 */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_PWRCYCLE
value|0x08
end_define

begin_comment
comment|/* power cycle */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_16BIT
value|0x010
end_define

begin_comment
comment|/* 16-bit card */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_CB
value|0x020
end_define

begin_comment
comment|/* cardbus card */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_IREQ
value|0x040
end_define

begin_comment
comment|/* READY(~IREQ)//(~CINT) bit */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_NOTCARD
value|0x080
end_define

begin_comment
comment|/* Inserted card is unrecognisable */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_DATALOST
value|0x0100
end_define

begin_comment
comment|/* data lost */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_BADVCC
value|0x0200
end_define

begin_comment
comment|/* Bad Vcc Request */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_5VCARD
value|0x0400
end_define

begin_comment
comment|/* 5 V Card */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_3VCARD
value|0x0800
end_define

begin_comment
comment|/* 3.3 V Card */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_XVCARD
value|0x01000
end_define

begin_comment
comment|/* X.X V Card */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_YVCARD
value|0x02000
end_define

begin_comment
comment|/* Y.Y V Card */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_5VSOCK
value|0x10000000
end_define

begin_comment
comment|/* 5 V Socket */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_3VSOCK
value|0x20000000
end_define

begin_comment
comment|/* 3.3 V Socket */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_XVSOCK
value|0x20000000
end_define

begin_comment
comment|/* X.X V Socket */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_STAT_YVSOCK
value|0x20000000
end_define

begin_comment
comment|/* Y.Y V Socket */
end_comment

begin_comment
comment|/* socket force event register (CB_SOCKET_FORCE) elements */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_FORCE_BADVCC
value|0x0200
end_define

begin_comment
comment|/* Bad Vcc Request */
end_comment

begin_comment
comment|/* socket control register (CB_SOCKET_CTRL) elements */
end_comment

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VPPMASK
value|0x07
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VPP_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VPP_12V
value|0x01
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VPP_5V
value|0x02
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VPP_3V
value|0x03
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VPP_XV
value|0x04
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VPP_YV
value|0x05
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VCCMASK
value|0x070
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VCC_OFF
value|0x000
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VCC_5V
value|0x020
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VCC_3V
value|0x030
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VCC_XV
value|0x040
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_VCC_YV
value|0x050
end_define

begin_define
define|#
directive|define
name|CB_SOCKET_CTRL_STOPCLK
value|0x080
end_define

begin_comment
comment|/* PCCARD VOLTAGE */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VCC_UKN
value|0x00
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VCC_5V
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_VCC_3V
value|0x02
end_define

begin_define
define|#
directive|define
name|PCCARD_VCC_XV
value|0x04
end_define

begin_define
define|#
directive|define
name|PCCARD_VCC_YV
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_PCI_PCCBBREG_H_ */
end_comment

end_unit

