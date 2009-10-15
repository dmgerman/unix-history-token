begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EHCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_EHCIREG_H_
end_define

begin_comment
comment|/* PCI config registers  */
end_comment

begin_define
define|#
directive|define
name|PCI_CBMEM
value|0x10
end_define

begin_comment
comment|/* configuration base MEM */
end_comment

begin_define
define|#
directive|define
name|PCI_INTERFACE_EHCI
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_USBREV
value|0x60
end_define

begin_comment
comment|/* RO USB protocol revision */
end_comment

begin_define
define|#
directive|define
name|PCI_USB_REV_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|PCI_USB_REV_PRE_1_0
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_USB_REV_1_0
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_USB_REV_1_1
value|0x11
end_define

begin_define
define|#
directive|define
name|PCI_USB_REV_2_0
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_EHCI_FLADJ
value|0x61
end_define

begin_comment
comment|/* RW Frame len adj, SOF=59488+6*fladj */
end_comment

begin_define
define|#
directive|define
name|PCI_EHCI_PORTWAKECAP
value|0x62
end_define

begin_comment
comment|/* RW Port wake caps (opt)  */
end_comment

begin_comment
comment|/* EHCI Extended Capabilities */
end_comment

begin_define
define|#
directive|define
name|EHCI_EC_LEGSUP
value|0x01
end_define

begin_define
define|#
directive|define
name|EHCI_EECP_NEXT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|EHCI_EECP_ID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_comment
comment|/* Legacy support extended capability */
end_comment

begin_define
define|#
directive|define
name|EHCI_LEGSUP_BIOS_SEM
value|0x02
end_define

begin_define
define|#
directive|define
name|EHCI_LEGSUP_OS_SEM
value|0x03
end_define

begin_define
define|#
directive|define
name|EHCI_LEGSUP_USBLEGCTLSTS
value|0x04
end_define

begin_comment
comment|/* EHCI capability registers */
end_comment

begin_define
define|#
directive|define
name|EHCI_CAPLENGTH
value|0x00
end_define

begin_comment
comment|/* RO Capability register length field */
end_comment

begin_comment
comment|/* reserved			0x01 */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCIVERSION
value|0x02
end_define

begin_comment
comment|/* RO Interface version number */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCSPARAMS
value|0x04
end_define

begin_comment
comment|/* RO Structural parameters */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCS_DEBUGPORT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0xf)
end_define

begin_define
define|#
directive|define
name|EHCI_HCS_P_INDICATOR
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x10000)
end_define

begin_define
define|#
directive|define
name|EHCI_HCS_N_CC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xf)
end_define

begin_comment
comment|/* # of companion ctlrs */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCS_N_PCC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xf)
end_define

begin_comment
comment|/* # of ports per comp. */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCS_PPC
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x10)
end_define

begin_comment
comment|/* port power control */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCS_N_PORTS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_comment
comment|/* # of ports */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCCPARAMS
value|0x08
end_define

begin_comment
comment|/* RO Capability parameters */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCC_EECP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_comment
comment|/* extended ports caps */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCC_IST
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xf)
end_define

begin_comment
comment|/* isoc sched threshold */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCC_ASPC
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x4)
end_define

begin_comment
comment|/* async sched park cap */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCC_PFLF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x2)
end_define

begin_comment
comment|/* prog frame list flag */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCC_64BIT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1)
end_define

begin_comment
comment|/* 64 bit address cap */
end_comment

begin_define
define|#
directive|define
name|EHCI_HCSP_PORTROUTE
value|0x0c
end_define

begin_comment
comment|/* RO Companion port route description */
end_comment

begin_comment
comment|/* EHCI operational registers.  Offset given by EHCI_CAPLENGTH register */
end_comment

begin_define
define|#
directive|define
name|EHCI_USBCMD
value|0x00
end_define

begin_comment
comment|/* RO, RW, WO Command register */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_ITC_M
value|0x00ff0000
end_define

begin_comment
comment|/* RW interrupt threshold ctrl */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_ITC_1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EHCI_CMD_ITC_2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EHCI_CMD_ITC_4
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EHCI_CMD_ITC_8
value|0x00080000
end_define

begin_define
define|#
directive|define
name|EHCI_CMD_ITC_16
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EHCI_CMD_ITC_32
value|0x00200000
end_define

begin_define
define|#
directive|define
name|EHCI_CMD_ITC_64
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EHCI_CMD_ASPME
value|0x00000800
end_define

begin_comment
comment|/* RW/RO async park enable */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_ASPMC
value|0x00000300
end_define

begin_comment
comment|/* RW/RO async park count */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_LHCR
value|0x00000080
end_define

begin_comment
comment|/* RW light host ctrl reset */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_IAAD
value|0x00000040
end_define

begin_comment
comment|/* RW intr on async adv door 						 * bell */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_ASE
value|0x00000020
end_define

begin_comment
comment|/* RW async sched enable */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_PSE
value|0x00000010
end_define

begin_comment
comment|/* RW periodic sched enable */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_FLS_M
value|0x0000000c
end_define

begin_comment
comment|/* RW/RO frame list size */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_FLS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 3)
end_define

begin_comment
comment|/* RW/RO frame list size */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_HCRESET
value|0x00000002
end_define

begin_comment
comment|/* RW reset */
end_comment

begin_define
define|#
directive|define
name|EHCI_CMD_RS
value|0x00000001
end_define

begin_comment
comment|/* RW run/stop */
end_comment

begin_define
define|#
directive|define
name|EHCI_USBSTS
value|0x04
end_define

begin_comment
comment|/* RO, RW, RWC Status register */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_ASS
value|0x00008000
end_define

begin_comment
comment|/* RO async sched status */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_PSS
value|0x00004000
end_define

begin_comment
comment|/* RO periodic sched status */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_REC
value|0x00002000
end_define

begin_comment
comment|/* RO reclamation */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_HCH
value|0x00001000
end_define

begin_comment
comment|/* RO host controller halted */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_IAA
value|0x00000020
end_define

begin_comment
comment|/* RWC interrupt on async adv */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_HSE
value|0x00000010
end_define

begin_comment
comment|/* RWC host system error */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_FLR
value|0x00000008
end_define

begin_comment
comment|/* RWC frame list rollover */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_PCD
value|0x00000004
end_define

begin_comment
comment|/* RWC port change detect */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_ERRINT
value|0x00000002
end_define

begin_comment
comment|/* RWC error interrupt */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_INT
value|0x00000001
end_define

begin_comment
comment|/* RWC interrupt */
end_comment

begin_define
define|#
directive|define
name|EHCI_STS_INTRS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3f)
end_define

begin_comment
comment|/*  * NOTE: the doorbell interrupt is enabled, but the doorbell is never  * used! SiS chipsets require this.  */
end_comment

begin_define
define|#
directive|define
name|EHCI_NORMAL_INTRS
value|(EHCI_STS_IAA | EHCI_STS_HSE |	\ 				EHCI_STS_PCD | EHCI_STS_ERRINT | EHCI_STS_INT)
end_define

begin_define
define|#
directive|define
name|EHCI_USBINTR
value|0x08
end_define

begin_comment
comment|/* RW Interrupt register */
end_comment

begin_define
define|#
directive|define
name|EHCI_INTR_IAAE
value|0x00000020
end_define

begin_comment
comment|/* interrupt on async advance 						 * ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_INTR_HSEE
value|0x00000010
end_define

begin_comment
comment|/* host system error ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_INTR_FLRE
value|0x00000008
end_define

begin_comment
comment|/* frame list rollover ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_INTR_PCIE
value|0x00000004
end_define

begin_comment
comment|/* port change ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_INTR_UEIE
value|0x00000002
end_define

begin_comment
comment|/* USB error intr ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_INTR_UIE
value|0x00000001
end_define

begin_comment
comment|/* USB intr ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_FRINDEX
value|0x0c
end_define

begin_comment
comment|/* RW Frame Index register */
end_comment

begin_define
define|#
directive|define
name|EHCI_CTRLDSSEGMENT
value|0x10
end_define

begin_comment
comment|/* RW Control Data Structure Segment */
end_comment

begin_define
define|#
directive|define
name|EHCI_PERIODICLISTBASE
value|0x14
end_define

begin_comment
comment|/* RW Periodic List Base */
end_comment

begin_define
define|#
directive|define
name|EHCI_ASYNCLISTADDR
value|0x18
end_define

begin_comment
comment|/* RW Async List Base */
end_comment

begin_define
define|#
directive|define
name|EHCI_CONFIGFLAG
value|0x40
end_define

begin_comment
comment|/* RW Configure Flag register */
end_comment

begin_define
define|#
directive|define
name|EHCI_CONF_CF
value|0x00000001
end_define

begin_comment
comment|/* RW configure flag */
end_comment

begin_define
define|#
directive|define
name|EHCI_PORTSC
parameter_list|(
name|n
parameter_list|)
value|(0x40+(4*(n)))
end_define

begin_comment
comment|/* RO, RW, RWC Port Status reg */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_WKOC_E
value|0x00400000
end_define

begin_comment
comment|/* RW wake on over current ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_WKDSCNNT_E
value|0x00200000
end_define

begin_comment
comment|/* RW wake on disconnect ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_WKCNNT_E
value|0x00100000
end_define

begin_comment
comment|/* RW wake on connect ena */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_PTC
value|0x000f0000
end_define

begin_comment
comment|/* RW port test control */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_PIC
value|0x0000c000
end_define

begin_comment
comment|/* RW port indicator control */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_PO
value|0x00002000
end_define

begin_comment
comment|/* RW port owner */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_PP
value|0x00001000
end_define

begin_comment
comment|/* RW,RO port power */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_LS
value|0x00000c00
end_define

begin_comment
comment|/* RO line status */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_IS_LOWSPEED
parameter_list|(
name|x
parameter_list|)
value|(((x)& EHCI_PS_LS) == 0x00000400)
end_define

begin_define
define|#
directive|define
name|EHCI_PS_PR
value|0x00000100
end_define

begin_comment
comment|/* RW port reset */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_SUSP
value|0x00000080
end_define

begin_comment
comment|/* RW suspend */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_FPR
value|0x00000040
end_define

begin_comment
comment|/* RW force port resume */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_OCC
value|0x00000020
end_define

begin_comment
comment|/* RWC over current change */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_OCA
value|0x00000010
end_define

begin_comment
comment|/* RO over current active */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_PEC
value|0x00000008
end_define

begin_comment
comment|/* RWC port enable change */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_PE
value|0x00000004
end_define

begin_comment
comment|/* RW port enable */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_CSC
value|0x00000002
end_define

begin_comment
comment|/* RWC connect status change */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_CS
value|0x00000001
end_define

begin_comment
comment|/* RO connect status */
end_comment

begin_define
define|#
directive|define
name|EHCI_PS_CLEAR
value|(EHCI_PS_OCC | EHCI_PS_PEC | EHCI_PS_CSC)
end_define

begin_define
define|#
directive|define
name|EHCI_USBMODE
value|0x68
end_define

begin_comment
comment|/* RW USB Device mode register */
end_comment

begin_define
define|#
directive|define
name|EHCI_UM_CM
value|0x00000003
end_define

begin_comment
comment|/* R/WO Controller Mode */
end_comment

begin_define
define|#
directive|define
name|EHCI_UM_CM_IDLE
value|0x0
end_define

begin_comment
comment|/* Idle */
end_comment

begin_define
define|#
directive|define
name|EHCI_UM_CM_HOST
value|0x3
end_define

begin_comment
comment|/* Host Controller */
end_comment

begin_define
define|#
directive|define
name|EHCI_UM_ES
value|0x00000004
end_define

begin_comment
comment|/* R/WO Endian Select */
end_comment

begin_define
define|#
directive|define
name|EHCI_UM_ES_LE
value|0x0
end_define

begin_comment
comment|/* Little-endian byte alignment */
end_comment

begin_define
define|#
directive|define
name|EHCI_UM_ES_BE
value|0x4
end_define

begin_comment
comment|/* Big-endian byte alignment */
end_comment

begin_define
define|#
directive|define
name|EHCI_UM_SDIS
value|0x00000010
end_define

begin_comment
comment|/* R/WO Stream Disable Mode */
end_comment

begin_define
define|#
directive|define
name|EHCI_PORT_RESET_COMPLETE
value|2
end_define

begin_comment
comment|/* ms */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EHCIREG_H_ */
end_comment

end_unit

