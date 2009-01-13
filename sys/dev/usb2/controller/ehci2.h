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
name|_EHCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_EHCI_H_
end_define

begin_define
define|#
directive|define
name|EHCI_MAX_DEVICES
value|USB_MAX_DEVICES
end_define

begin_comment
comment|/* PCI config registers */
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

begin_comment
comment|/*  * Alignment NOTE: structures must be aligned so that the hardware can index  * without performing addition.  */
end_comment

begin_define
define|#
directive|define
name|EHCI_FRAMELIST_ALIGN
value|0x1000
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|EHCI_FRAMELIST_COUNT
value|1024
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|EHCI_VIRTUAL_FRAMELIST_COUNT
value|128
end_define

begin_comment
comment|/* units */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
literal|8
operator|*
name|EHCI_VIRTUAL_FRAMELIST_COUNT
operator|)
operator|<
name|USB_MAX_HS_ISOC_FRAMES_PER_XFER
operator|)
end_if

begin_error
error|#
directive|error
literal|"maximum number of high-speed isochronous frames is higher than supported!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|EHCI_VIRTUAL_FRAMELIST_COUNT
operator|<
name|USB_MAX_FS_ISOC_FRAMES_PER_XFER
operator|)
end_if

begin_error
error|#
directive|error
literal|"maximum number of full-speed isochronous frames is higher than supported!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Link types */
end_comment

begin_define
define|#
directive|define
name|EHCI_LINK_TERMINATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EHCI_LINK_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x00000006)
end_define

begin_define
define|#
directive|define
name|EHCI_LINK_ITD
value|0x0
end_define

begin_define
define|#
directive|define
name|EHCI_LINK_QH
value|0x2
end_define

begin_define
define|#
directive|define
name|EHCI_LINK_SITD
value|0x4
end_define

begin_define
define|#
directive|define
name|EHCI_LINK_FSTN
value|0x6
end_define

begin_define
define|#
directive|define
name|EHCI_LINK_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)&~ 0x1f)
end_define

begin_comment
comment|/* Structures alignment (bytes) */
end_comment

begin_define
define|#
directive|define
name|EHCI_ITD_ALIGN
value|128
end_define

begin_define
define|#
directive|define
name|EHCI_SITD_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|EHCI_QTD_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|EHCI_QH_ALIGN
value|128
end_define

begin_define
define|#
directive|define
name|EHCI_FSTN_ALIGN
value|32
end_define

begin_comment
comment|/* Data buffers are divided into one or more pages */
end_comment

begin_define
define|#
directive|define
name|EHCI_PAGE_SIZE
value|0x1000
end_define

begin_if
if|#
directive|if
operator|(
operator|(
name|USB_PAGE_SIZE
operator|<
name|EHCI_PAGE_SIZE
operator|)
operator|||
operator|(
name|EHCI_PAGE_SIZE
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|EHCI_ITD_ALIGN
operator|)
operator|||
operator|(
name|EHCI_ITD_ALIGN
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|EHCI_SITD_ALIGN
operator|)
operator|||
operator|(
name|EHCI_SITD_ALIGN
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|EHCI_QTD_ALIGN
operator|)
operator|||
operator|(
name|EHCI_QTD_ALIGN
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|EHCI_QH_ALIGN
operator|)
operator|||
operator|(
name|EHCI_QH_ALIGN
operator|==
literal|0
operator|)
operator|||
expr|\
operator|(
name|USB_PAGE_SIZE
operator|<
name|EHCI_FSTN_ALIGN
operator|)
operator|||
operator|(
name|EHCI_FSTN_ALIGN
operator|==
literal|0
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Invalid USB page size!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Isochronous Transfer Descriptor.  This descriptor is used for high speed  * transfers only.  */
end_comment

begin_struct
struct|struct
name|ehci_itd
block|{
specifier|volatile
name|uint32_t
name|itd_next
decl_stmt|;
specifier|volatile
name|uint32_t
name|itd_status
index|[
literal|8
index|]
decl_stmt|;
define|#
directive|define
name|EHCI_ITD_SET_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
define|#
directive|define
name|EHCI_ITD_GET_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFF)
define|#
directive|define
name|EHCI_ITD_IOC
value|(1<< 15)
define|#
directive|define
name|EHCI_ITD_SET_PG
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
define|#
directive|define
name|EHCI_ITD_GET_PG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x7)
define|#
directive|define
name|EHCI_ITD_SET_OFFS
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|EHCI_ITD_GET_OFFS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFF)
define|#
directive|define
name|EHCI_ITD_ACTIVE
value|(1<< 31)
define|#
directive|define
name|EHCI_ITD_DATABUFERR
value|(1<< 30)
define|#
directive|define
name|EHCI_ITD_BABBLE
value|(1<< 29)
define|#
directive|define
name|EHCI_ITD_XACTERR
value|(1<< 28)
specifier|volatile
name|uint32_t
name|itd_bp
index|[
literal|7
index|]
decl_stmt|;
comment|/* itd_bp[0] */
define|#
directive|define
name|EHCI_ITD_SET_ADDR
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|EHCI_ITD_GET_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7F)
define|#
directive|define
name|EHCI_ITD_SET_ENDPT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
define|#
directive|define
name|EHCI_ITD_GET_ENDPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
comment|/* itd_bp[1] */
define|#
directive|define
name|EHCI_ITD_SET_DIR_IN
value|(1<< 11)
define|#
directive|define
name|EHCI_ITD_SET_DIR_OUT
value|(0<< 11)
define|#
directive|define
name|EHCI_ITD_SET_MPL
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|EHCI_ITD_GET_MPL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FF)
specifier|volatile
name|uint32_t
name|itd_bp_hi
index|[
literal|7
index|]
decl_stmt|;
comment|/*  * Extra information needed:  */
name|uint32_t
name|itd_self
decl_stmt|;
name|struct
name|ehci_itd
modifier|*
name|next
decl_stmt|;
name|struct
name|ehci_itd
modifier|*
name|prev
decl_stmt|;
name|struct
name|ehci_itd
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|usb2_page_cache
modifier|*
name|page_cache
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|EHCI_ITD_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ehci_itd
name|ehci_itd_t
typedef|;
end_typedef

begin_comment
comment|/*  * Split Transaction Isochronous Transfer Descriptor.  This descriptor is used  * for full speed transfers only.  */
end_comment

begin_struct
struct|struct
name|ehci_sitd
block|{
specifier|volatile
name|uint32_t
name|sitd_next
decl_stmt|;
specifier|volatile
name|uint32_t
name|sitd_portaddr
decl_stmt|;
define|#
directive|define
name|EHCI_SITD_SET_DIR_OUT
value|(0<< 31)
define|#
directive|define
name|EHCI_SITD_SET_DIR_IN
value|(1<< 31)
define|#
directive|define
name|EHCI_SITD_SET_ADDR
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|EHCI_SITD_GET_ADDR
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7F)
define|#
directive|define
name|EHCI_SITD_SET_ENDPT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
define|#
directive|define
name|EHCI_SITD_GET_ENDPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
define|#
directive|define
name|EHCI_SITD_GET_DIR
parameter_list|(
name|x
parameter_list|)
value|((x)>> 31)
define|#
directive|define
name|EHCI_SITD_SET_PORT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
define|#
directive|define
name|EHCI_SITD_GET_PORT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x7F)
define|#
directive|define
name|EHCI_SITD_SET_HUBA
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
define|#
directive|define
name|EHCI_SITD_GET_HUBA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x7F)
specifier|volatile
name|uint32_t
name|sitd_mask
decl_stmt|;
define|#
directive|define
name|EHCI_SITD_SET_SMASK
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|EHCI_SITD_SET_CMASK
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
specifier|volatile
name|uint32_t
name|sitd_status
decl_stmt|;
define|#
directive|define
name|EHCI_SITD_COMPLETE_SPLIT
value|(1<<1)
define|#
directive|define
name|EHCI_SITD_START_SPLIT
value|(0<<1)
define|#
directive|define
name|EHCI_SITD_MISSED_MICRO_FRAME
value|(1<<2)
define|#
directive|define
name|EHCI_SITD_XACTERR
value|(1<<3)
define|#
directive|define
name|EHCI_SITD_BABBLE
value|(1<<4)
define|#
directive|define
name|EHCI_SITD_DATABUFERR
value|(1<<5)
define|#
directive|define
name|EHCI_SITD_ERROR
value|(1<<6)
define|#
directive|define
name|EHCI_SITD_ACTIVE
value|(1<<7)
define|#
directive|define
name|EHCI_SITD_IOC
value|(1<<31)
define|#
directive|define
name|EHCI_SITD_SET_LEN
parameter_list|(
name|len
parameter_list|)
value|((len)<<16)
define|#
directive|define
name|EHCI_SITD_GET_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>>16)& 0x3FF)
specifier|volatile
name|uint32_t
name|sitd_bp
index|[
literal|2
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|sitd_back
decl_stmt|;
specifier|volatile
name|uint32_t
name|sitd_bp_hi
index|[
literal|2
index|]
decl_stmt|;
comment|/*  * Extra information needed:  */
name|uint32_t
name|sitd_self
decl_stmt|;
name|struct
name|ehci_sitd
modifier|*
name|next
decl_stmt|;
name|struct
name|ehci_sitd
modifier|*
name|prev
decl_stmt|;
name|struct
name|ehci_sitd
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|usb2_page_cache
modifier|*
name|page_cache
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|EHCI_SITD_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ehci_sitd
name|ehci_sitd_t
typedef|;
end_typedef

begin_comment
comment|/* Queue Element Transfer Descriptor */
end_comment

begin_struct
struct|struct
name|ehci_qtd
block|{
specifier|volatile
name|uint32_t
name|qtd_next
decl_stmt|;
specifier|volatile
name|uint32_t
name|qtd_altnext
decl_stmt|;
specifier|volatile
name|uint32_t
name|qtd_status
decl_stmt|;
define|#
directive|define
name|EHCI_QTD_GET_STATUS
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  0)& 0xff)
define|#
directive|define
name|EHCI_QTD_SET_STATUS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
define|#
directive|define
name|EHCI_QTD_ACTIVE
value|0x80
define|#
directive|define
name|EHCI_QTD_HALTED
value|0x40
define|#
directive|define
name|EHCI_QTD_BUFERR
value|0x20
define|#
directive|define
name|EHCI_QTD_BABBLE
value|0x10
define|#
directive|define
name|EHCI_QTD_XACTERR
value|0x08
define|#
directive|define
name|EHCI_QTD_MISSEDMICRO
value|0x04
define|#
directive|define
name|EHCI_QTD_SPLITXSTATE
value|0x02
define|#
directive|define
name|EHCI_QTD_PINGSTATE
value|0x01
define|#
directive|define
name|EHCI_QTD_STATERRS
value|0x74
define|#
directive|define
name|EHCI_QTD_GET_PID
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0x3)
define|#
directive|define
name|EHCI_QTD_SET_PID
parameter_list|(
name|x
parameter_list|)
value|((x)<<  8)
define|#
directive|define
name|EHCI_QTD_PID_OUT
value|0x0
define|#
directive|define
name|EHCI_QTD_PID_IN
value|0x1
define|#
directive|define
name|EHCI_QTD_PID_SETUP
value|0x2
define|#
directive|define
name|EHCI_QTD_GET_CERR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)&  0x3)
define|#
directive|define
name|EHCI_QTD_SET_CERR
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
define|#
directive|define
name|EHCI_QTD_GET_C_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)&  0x7)
define|#
directive|define
name|EHCI_QTD_SET_C_PAGE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
define|#
directive|define
name|EHCI_QTD_GET_IOC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)&  0x1)
define|#
directive|define
name|EHCI_QTD_IOC
value|0x00008000
define|#
directive|define
name|EHCI_QTD_GET_BYTES
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)&  0x7fff)
define|#
directive|define
name|EHCI_QTD_SET_BYTES
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
define|#
directive|define
name|EHCI_QTD_GET_TOGGLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)&  0x1)
define|#
directive|define
name|EHCI_QTD_SET_TOGGLE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 31)
define|#
directive|define
name|EHCI_QTD_TOGGLE_MASK
value|0x80000000
define|#
directive|define
name|EHCI_QTD_NBUFFERS
value|5
define|#
directive|define
name|EHCI_QTD_PAYLOAD_MAX
value|((EHCI_QTD_NBUFFERS-1)*EHCI_PAGE_SIZE)
specifier|volatile
name|uint32_t
name|qtd_buffer
index|[
name|EHCI_QTD_NBUFFERS
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|qtd_buffer_hi
index|[
name|EHCI_QTD_NBUFFERS
index|]
decl_stmt|;
comment|/*  * Extra information needed:  */
name|struct
name|ehci_qtd
modifier|*
name|alt_next
decl_stmt|;
name|struct
name|ehci_qtd
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|usb2_page_cache
modifier|*
name|page_cache
decl_stmt|;
name|uint32_t
name|qtd_self
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|EHCI_QTD_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ehci_qtd
name|ehci_qtd_t
typedef|;
end_typedef

begin_comment
comment|/* Queue Head Sub Structure */
end_comment

begin_struct
struct|struct
name|ehci_qh_sub
block|{
specifier|volatile
name|uint32_t
name|qtd_next
decl_stmt|;
specifier|volatile
name|uint32_t
name|qtd_altnext
decl_stmt|;
specifier|volatile
name|uint32_t
name|qtd_status
decl_stmt|;
specifier|volatile
name|uint32_t
name|qtd_buffer
index|[
name|EHCI_QTD_NBUFFERS
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|qtd_buffer_hi
index|[
name|EHCI_QTD_NBUFFERS
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Queue Head */
end_comment

begin_struct
struct|struct
name|ehci_qh
block|{
specifier|volatile
name|uint32_t
name|qh_link
decl_stmt|;
specifier|volatile
name|uint32_t
name|qh_endp
decl_stmt|;
define|#
directive|define
name|EHCI_QH_GET_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  0)& 0x7f)
comment|/* endpoint addr */
define|#
directive|define
name|EHCI_QH_SET_ADDR
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|EHCI_QH_ADDRMASK
value|0x0000007f
define|#
directive|define
name|EHCI_QH_GET_INACT
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  7)& 0x01)
comment|/* inactivate on next */
define|#
directive|define
name|EHCI_QH_INACT
value|0x00000080
define|#
directive|define
name|EHCI_QH_GET_ENDPT
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0x0f)
comment|/* endpoint no */
define|#
directive|define
name|EHCI_QH_SET_ENDPT
parameter_list|(
name|x
parameter_list|)
value|((x)<<  8)
define|#
directive|define
name|EHCI_QH_GET_EPS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x03)
comment|/* endpoint speed */
define|#
directive|define
name|EHCI_QH_SET_EPS
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
define|#
directive|define
name|EHCI_QH_SPEED_FULL
value|0x0
define|#
directive|define
name|EHCI_QH_SPEED_LOW
value|0x1
define|#
directive|define
name|EHCI_QH_SPEED_HIGH
value|0x2
define|#
directive|define
name|EHCI_QH_GET_DTC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x01)
comment|/* data toggle control */
define|#
directive|define
name|EHCI_QH_DTC
value|0x00004000
define|#
directive|define
name|EHCI_QH_GET_HRECL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x01)
comment|/* head of reclamation */
define|#
directive|define
name|EHCI_QH_HRECL
value|0x00008000
define|#
directive|define
name|EHCI_QH_GET_MPL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x7ff)
comment|/* max packet len */
define|#
directive|define
name|EHCI_QH_SET_MPL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
define|#
directive|define
name|EHCI_QH_MPLMASK
value|0x07ff0000
define|#
directive|define
name|EHCI_QH_GET_CTL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x01)
comment|/* control endpoint */
define|#
directive|define
name|EHCI_QH_CTL
value|0x08000000
define|#
directive|define
name|EHCI_QH_GET_NRL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x0f)
comment|/* NAK reload */
define|#
directive|define
name|EHCI_QH_SET_NRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
specifier|volatile
name|uint32_t
name|qh_endphub
decl_stmt|;
define|#
directive|define
name|EHCI_QH_GET_SMASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  0)& 0xff)
comment|/* intr sched mask */
define|#
directive|define
name|EHCI_QH_SET_SMASK
parameter_list|(
name|x
parameter_list|)
value|((x)<<  0)
define|#
directive|define
name|EHCI_QH_GET_CMASK
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0xff)
comment|/* split completion mask */
define|#
directive|define
name|EHCI_QH_SET_CMASK
parameter_list|(
name|x
parameter_list|)
value|((x)<<  8)
define|#
directive|define
name|EHCI_QH_GET_HUBA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x7f)
comment|/* hub address */
define|#
directive|define
name|EHCI_QH_SET_HUBA
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
define|#
directive|define
name|EHCI_QH_GET_PORT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x7f)
comment|/* hub port */
define|#
directive|define
name|EHCI_QH_SET_PORT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 23)
define|#
directive|define
name|EHCI_QH_GET_MULT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x03)
comment|/* pipe multiplier */
define|#
directive|define
name|EHCI_QH_SET_MULT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 30)
specifier|volatile
name|uint32_t
name|qh_curqtd
decl_stmt|;
name|struct
name|ehci_qh_sub
name|qh_qtd
decl_stmt|;
comment|/*  * Extra information needed:  */
name|struct
name|ehci_qh
modifier|*
name|next
decl_stmt|;
name|struct
name|ehci_qh
modifier|*
name|prev
decl_stmt|;
name|struct
name|ehci_qh
modifier|*
name|obj_next
decl_stmt|;
name|struct
name|usb2_page_cache
modifier|*
name|page_cache
decl_stmt|;
name|uint32_t
name|qh_self
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|EHCI_QH_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ehci_qh
name|ehci_qh_t
typedef|;
end_typedef

begin_comment
comment|/* Periodic Frame Span Traversal Node */
end_comment

begin_struct
struct|struct
name|ehci_fstn
block|{
specifier|volatile
name|uint32_t
name|fstn_link
decl_stmt|;
specifier|volatile
name|uint32_t
name|fstn_back
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|EHCI_FSTN_ALIGN
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ehci_fstn
name|ehci_fstn_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ehci_hw_softc
block|{
name|struct
name|usb2_page_cache
name|pframes_pc
decl_stmt|;
name|struct
name|usb2_page_cache
name|async_start_pc
decl_stmt|;
name|struct
name|usb2_page_cache
name|intr_start_pc
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb2_page_cache
name|isoc_hs_start_pc
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb2_page_cache
name|isoc_fs_start_pc
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb2_page
name|pframes_pg
decl_stmt|;
name|struct
name|usb2_page
name|async_start_pg
decl_stmt|;
name|struct
name|usb2_page
name|intr_start_pg
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb2_page
name|isoc_hs_start_pg
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|usb2_page
name|isoc_fs_start_pg
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ehci_config_desc
block|{
name|struct
name|usb2_config_descriptor
name|confd
decl_stmt|;
name|struct
name|usb2_interface_descriptor
name|ifcd
decl_stmt|;
name|struct
name|usb2_endpoint_descriptor
name|endpd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|ehci_hub_desc
block|{
name|struct
name|usb2_status
name|stat
decl_stmt|;
name|struct
name|usb2_port_status
name|ps
decl_stmt|;
name|struct
name|usb2_device_descriptor
name|devd
decl_stmt|;
name|struct
name|usb2_device_qualifier
name|odevd
decl_stmt|;
name|struct
name|usb2_hub_descriptor
name|hubd
decl_stmt|;
name|uint8_t
name|temp
index|[
literal|128
index|]
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
struct|struct
name|ehci_softc
block|{
name|struct
name|ehci_hw_softc
name|sc_hw
decl_stmt|;
name|struct
name|usb2_bus
name|sc_bus
decl_stmt|;
comment|/* base device */
name|struct
name|usb2_config_td
name|sc_config_td
decl_stmt|;
name|struct
name|usb2_callout
name|sc_tmo_pcd
decl_stmt|;
name|union
name|ehci_hub_desc
name|sc_hub_desc
decl_stmt|;
name|struct
name|usb2_sw_transfer
name|sc_root_ctrl
decl_stmt|;
name|struct
name|usb2_sw_transfer
name|sc_root_intr
decl_stmt|;
name|struct
name|usb2_device
modifier|*
name|sc_devices
index|[
name|EHCI_MAX_DEVICES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_io_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|struct
name|ehci_qh
modifier|*
name|sc_async_p_last
decl_stmt|;
name|struct
name|ehci_qh
modifier|*
name|sc_intr_p_last
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|ehci_sitd
modifier|*
name|sc_isoc_fs_p_last
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|struct
name|ehci_itd
modifier|*
name|sc_isoc_hs_p_last
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|void
modifier|*
name|sc_intr_hdl
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|bus_size_t
name|sc_io_size
decl_stmt|;
name|bus_space_tag_t
name|sc_io_tag
decl_stmt|;
name|bus_space_handle_t
name|sc_io_hdl
decl_stmt|;
name|uint32_t
name|sc_eintrs
decl_stmt|;
name|uint32_t
name|sc_cmd
decl_stmt|;
comment|/* shadow of cmd register during 					 * suspend */
name|uint16_t
name|sc_intr_stat
index|[
name|EHCI_VIRTUAL_FRAMELIST_COUNT
index|]
decl_stmt|;
name|uint16_t
name|sc_id_vendor
decl_stmt|;
comment|/* vendor ID for root hub */
name|uint16_t
name|sc_flags
decl_stmt|;
comment|/* chip specific flags */
define|#
directive|define
name|EHCI_SCFLG_SETMODE
value|0x0001
comment|/* set bridge mode again after init */
define|#
directive|define
name|EHCI_SCFLG_FORCESPEED
value|0x0002
comment|/* force speed */
define|#
directive|define
name|EHCI_SCFLG_NORESTERM
value|0x0004
comment|/* don't terminate reset sequence */
define|#
directive|define
name|EHCI_SCFLG_BIGEDESC
value|0x0008
comment|/* big-endian byte order descriptors */
define|#
directive|define
name|EHCI_SCFLG_BIGEMMIO
value|0x0010
comment|/* big-endian byte order MMIO */
define|#
directive|define
name|EHCI_SCFLG_TT
value|0x0020
comment|/* transaction translator present */
name|uint8_t
name|sc_offs
decl_stmt|;
comment|/* offset to operational registers */
name|uint8_t
name|sc_doorbell_disable
decl_stmt|;
comment|/* set on doorbell failure */
name|uint8_t
name|sc_noport
decl_stmt|;
name|uint8_t
name|sc_addr
decl_stmt|;
comment|/* device address */
name|uint8_t
name|sc_conf
decl_stmt|;
comment|/* device configuration */
name|uint8_t
name|sc_isreset
decl_stmt|;
name|uint8_t
name|sc_hub_idata
index|[
literal|8
index|]
decl_stmt|;
name|char
name|sc_vendor
index|[
literal|16
index|]
decl_stmt|;
comment|/* vendor string for root hub */
block|}
name|ehci_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EREAD1
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_1((sc)->sc_io_tag, (sc)->sc_io_hdl, (a))
end_define

begin_define
define|#
directive|define
name|EREAD2
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_2((sc)->sc_io_tag, (sc)->sc_io_hdl, (a))
end_define

begin_define
define|#
directive|define
name|EREAD4
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
value|bus_space_read_4((sc)->sc_io_tag, (sc)->sc_io_hdl, (a))
end_define

begin_define
define|#
directive|define
name|EWRITE1
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_io_tag, (sc)->sc_io_hdl, (a), (x))
end_define

begin_define
define|#
directive|define
name|EWRITE2
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_io_tag, (sc)->sc_io_hdl, (a), (x))
end_define

begin_define
define|#
directive|define
name|EWRITE4
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_io_tag, (sc)->sc_io_hdl, (a), (x))
end_define

begin_define
define|#
directive|define
name|EOREAD1
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_io_tag, (sc)->sc_io_hdl, (sc)->sc_offs+(a))
end_define

begin_define
define|#
directive|define
name|EOREAD2
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_io_tag, (sc)->sc_io_hdl, (sc)->sc_offs+(a))
end_define

begin_define
define|#
directive|define
name|EOREAD4
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_io_tag, (sc)->sc_io_hdl, (sc)->sc_offs+(a))
end_define

begin_define
define|#
directive|define
name|EOWRITE1
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_io_tag, (sc)->sc_io_hdl, (sc)->sc_offs+(a), (x))
end_define

begin_define
define|#
directive|define
name|EOWRITE2
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_io_tag, (sc)->sc_io_hdl, (sc)->sc_offs+(a), (x))
end_define

begin_define
define|#
directive|define
name|EOWRITE4
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_io_tag, (sc)->sc_io_hdl, (sc)->sc_offs+(a), (x))
end_define

begin_decl_stmt
name|usb2_bus_mem_cb_t
name|ehci_iterate_hw_softc
decl_stmt|;
end_decl_stmt

begin_function_decl
name|usb2_error_t
name|ehci_init
parameter_list|(
name|ehci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ehci_detach
parameter_list|(
name|struct
name|ehci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ehci_suspend
parameter_list|(
name|struct
name|ehci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ehci_resume
parameter_list|(
name|struct
name|ehci_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ehci_shutdown
parameter_list|(
name|ehci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ehci_interrupt
parameter_list|(
name|ehci_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EHCI_H_ */
end_comment

end_unit

