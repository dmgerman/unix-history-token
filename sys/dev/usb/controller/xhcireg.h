begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XHCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_XHCIREG_H_
end_define

begin_comment
comment|/* XHCI PCI config registers */
end_comment

begin_define
define|#
directive|define
name|PCI_XHCI_CBMEM
value|0x10
end_define

begin_comment
comment|/* configuration base MEM */
end_comment

begin_define
define|#
directive|define
name|PCI_XHCI_USBREV
value|0x60
end_define

begin_comment
comment|/* RO USB protocol revision */
end_comment

begin_define
define|#
directive|define
name|PCI_USB_REV_3_0
value|0x30
end_define

begin_comment
comment|/* USB 3.0 */
end_comment

begin_define
define|#
directive|define
name|PCI_XHCI_FLADJ
value|0x61
end_define

begin_comment
comment|/* RW frame length adjust */
end_comment

begin_define
define|#
directive|define
name|PCI_XHCI_INTEL_XUSB2PR
value|0xD0
end_define

begin_comment
comment|/* Intel USB2 Port Routing */
end_comment

begin_define
define|#
directive|define
name|PCI_XHCI_INTEL_USB2PRM
value|0xD4
end_define

begin_comment
comment|/* Intel USB2 Port Routing Mask */
end_comment

begin_define
define|#
directive|define
name|PCI_XHCI_INTEL_USB3_PSSEN
value|0xD8
end_define

begin_comment
comment|/* Intel USB3 Port SuperSpeed Enable */
end_comment

begin_define
define|#
directive|define
name|PCI_XHCI_INTEL_USB3PRM
value|0xDC
end_define

begin_comment
comment|/* Intel USB3 Port Routing Mask */
end_comment

begin_comment
comment|/* XHCI capability registers */
end_comment

begin_define
define|#
directive|define
name|XHCI_CAPLENGTH
value|0x00
end_define

begin_comment
comment|/* RO capability */
end_comment

begin_define
define|#
directive|define
name|XHCI_RESERVED
value|0x01
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCIVERSION
value|0x02
end_define

begin_comment
comment|/* RO Interface version number */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCIVERSION_0_9
value|0x0090
end_define

begin_comment
comment|/* xHCI version 0.9 */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCIVERSION_1_0
value|0x0100
end_define

begin_comment
comment|/* xHCI version 1.0 */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCSPARAMS1
value|0x04
end_define

begin_comment
comment|/* RO structual parameters 1 */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS1_DEVSLOT_MAX
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|XHCI_HCS1_IRQ_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3FF)
end_define

begin_define
define|#
directive|define
name|XHCI_HCS1_N_PORTS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0xFF)
end_define

begin_define
define|#
directive|define
name|XHCI_HCSPARAMS2
value|0x08
end_define

begin_comment
comment|/* RO structual parameters 2 */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS2_IST
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xF)
end_define

begin_define
define|#
directive|define
name|XHCI_HCS2_ERST_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xF)
end_define

begin_define
define|#
directive|define
name|XHCI_HCS2_SPR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|XHCI_HCS2_SPB_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x7F)
end_define

begin_define
define|#
directive|define
name|XHCI_HCSPARAMS3
value|0x0C
end_define

begin_comment
comment|/* RO structual parameters 3 */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS3_U1_DEL
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|XHCI_HCS3_U2_DEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|XHCI_HCSPARAMS0
value|0x10
end_define

begin_comment
comment|/* RO capability parameters */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_AC64
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1)
end_define

begin_comment
comment|/* 64-bit capable */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_BNC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_comment
comment|/* BW negotiation */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_CSZ
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_comment
comment|/* context size */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_PPC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_comment
comment|/* port power control */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_PIND
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_comment
comment|/* port indicators */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_LHRC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_comment
comment|/* light HC reset */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_LTC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_comment
comment|/* latency tolerance msg */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_NSS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_comment
comment|/* no secondary sid */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_PSA_SZ_MAX
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xF)
end_define

begin_comment
comment|/* max pri. stream array size */
end_comment

begin_define
define|#
directive|define
name|XHCI_HCS0_XECP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_comment
comment|/* extended capabilities pointer */
end_comment

begin_define
define|#
directive|define
name|XHCI_DBOFF
value|0x14
end_define

begin_comment
comment|/* RO doorbell offset */
end_comment

begin_define
define|#
directive|define
name|XHCI_RTSOFF
value|0x18
end_define

begin_comment
comment|/* RO runtime register space offset */
end_comment

begin_comment
comment|/* XHCI operational registers.  Offset given by XHCI_CAPLENGTH register */
end_comment

begin_define
define|#
directive|define
name|XHCI_USBCMD
value|0x00
end_define

begin_comment
comment|/* XHCI command */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_RS
value|0x00000001
end_define

begin_comment
comment|/* RW Run/Stop */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_HCRST
value|0x00000002
end_define

begin_comment
comment|/* RW Host Controller Reset */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_INTE
value|0x00000004
end_define

begin_comment
comment|/* RW Interrupter Enable */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_HSEE
value|0x00000008
end_define

begin_comment
comment|/* RW Host System Error Enable */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_LHCRST
value|0x00000080
end_define

begin_comment
comment|/* RO/RW Light Host Controller Reset */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_CSS
value|0x00000100
end_define

begin_comment
comment|/* RW Controller Save State */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_CRS
value|0x00000200
end_define

begin_comment
comment|/* RW Controller Restore State */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_EWE
value|0x00000400
end_define

begin_comment
comment|/* RW Enable Wrap Event */
end_comment

begin_define
define|#
directive|define
name|XHCI_CMD_EU3S
value|0x00000800
end_define

begin_comment
comment|/* RW Enable U3 MFINDEX Stop */
end_comment

begin_define
define|#
directive|define
name|XHCI_USBSTS
value|0x04
end_define

begin_comment
comment|/* XHCI status */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_HCH
value|0x00000001
end_define

begin_comment
comment|/* RO - Host Controller Halted */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_HSE
value|0x00000004
end_define

begin_comment
comment|/* RW - Host System Error */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_EINT
value|0x00000008
end_define

begin_comment
comment|/* RW - Event Interrupt */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_PCD
value|0x00000010
end_define

begin_comment
comment|/* RW - Port Change Detect */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_SSS
value|0x00000100
end_define

begin_comment
comment|/* RO - Save State Status */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_RSS
value|0x00000200
end_define

begin_comment
comment|/* RO - Restore State Status */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_SRE
value|0x00000400
end_define

begin_comment
comment|/* RW - Save/Restore Error */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_CNR
value|0x00000800
end_define

begin_comment
comment|/* RO - Controller Not Ready */
end_comment

begin_define
define|#
directive|define
name|XHCI_STS_HCE
value|0x00001000
end_define

begin_comment
comment|/* RO - Host Controller Error */
end_comment

begin_define
define|#
directive|define
name|XHCI_PAGESIZE
value|0x08
end_define

begin_comment
comment|/* XHCI page size mask */
end_comment

begin_define
define|#
directive|define
name|XHCI_PAGESIZE_4K
value|0x00000001
end_define

begin_comment
comment|/* 4K Page Size */
end_comment

begin_define
define|#
directive|define
name|XHCI_PAGESIZE_8K
value|0x00000002
end_define

begin_comment
comment|/* 8K Page Size */
end_comment

begin_define
define|#
directive|define
name|XHCI_PAGESIZE_16K
value|0x00000004
end_define

begin_comment
comment|/* 16K Page Size */
end_comment

begin_define
define|#
directive|define
name|XHCI_PAGESIZE_32K
value|0x00000008
end_define

begin_comment
comment|/* 32K Page Size */
end_comment

begin_define
define|#
directive|define
name|XHCI_PAGESIZE_64K
value|0x00000010
end_define

begin_comment
comment|/* 64K Page Size */
end_comment

begin_define
define|#
directive|define
name|XHCI_DNCTRL
value|0x14
end_define

begin_comment
comment|/* XHCI device notification control */
end_comment

begin_define
define|#
directive|define
name|XHCI_DNCTRL_MASK
parameter_list|(
name|n
parameter_list|)
value|(1U<< (n))
end_define

begin_define
define|#
directive|define
name|XHCI_CRCR_LO
value|0x18
end_define

begin_comment
comment|/* XHCI command ring control */
end_comment

begin_define
define|#
directive|define
name|XHCI_CRCR_LO_RCS
value|0x00000001
end_define

begin_comment
comment|/* RW - consumer cycle state */
end_comment

begin_define
define|#
directive|define
name|XHCI_CRCR_LO_CS
value|0x00000002
end_define

begin_comment
comment|/* RW - command stop */
end_comment

begin_define
define|#
directive|define
name|XHCI_CRCR_LO_CA
value|0x00000004
end_define

begin_comment
comment|/* RW - command abort */
end_comment

begin_define
define|#
directive|define
name|XHCI_CRCR_LO_CRR
value|0x00000008
end_define

begin_comment
comment|/* RW - command ring running */
end_comment

begin_define
define|#
directive|define
name|XHCI_CRCR_LO_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|XHCI_CRCR_HI
value|0x1C
end_define

begin_comment
comment|/* XHCI command ring control */
end_comment

begin_define
define|#
directive|define
name|XHCI_DCBAAP_LO
value|0x30
end_define

begin_comment
comment|/* XHCI dev context BA pointer */
end_comment

begin_define
define|#
directive|define
name|XHCI_DCBAAP_HI
value|0x34
end_define

begin_comment
comment|/* XHCI dev context BA pointer */
end_comment

begin_define
define|#
directive|define
name|XHCI_CONFIG
value|0x38
end_define

begin_define
define|#
directive|define
name|XHCI_CONFIG_SLOTS_MASK
value|0x000000FF
end_define

begin_comment
comment|/* RW - number of device slots enabled */
end_comment

begin_comment
comment|/* XHCI port status registers */
end_comment

begin_define
define|#
directive|define
name|XHCI_PORTSC
parameter_list|(
name|n
parameter_list|)
value|(0x3F0 + (0x10 * (n)))
end_define

begin_comment
comment|/* XHCI port status */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_CCS
value|0x00000001
end_define

begin_comment
comment|/* RO - current connect status */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PED
value|0x00000002
end_define

begin_comment
comment|/* RW - port enabled / disabled */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_OCA
value|0x00000008
end_define

begin_comment
comment|/* RO - over current active */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PR
value|0x00000010
end_define

begin_comment
comment|/* RW - port reset */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PLS_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0xF)
end_define

begin_comment
comment|/* RW - port link state */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PLS_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 5)
end_define

begin_comment
comment|/* RW - port link state */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PP
value|0x00000200
end_define

begin_comment
comment|/* RW - port power */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_SPEED_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0xF)
end_define

begin_comment
comment|/* RO - port speed */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PIC_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x3)
end_define

begin_comment
comment|/* RW - port indicator */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PIC_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 14)
end_define

begin_comment
comment|/* RW - port indicator */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_LWS
value|0x00010000
end_define

begin_comment
comment|/* RW - port link state write strobe */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_CSC
value|0x00020000
end_define

begin_comment
comment|/* RW - connect status change */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PEC
value|0x00040000
end_define

begin_comment
comment|/* RW - port enable/disable change */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_WRC
value|0x00080000
end_define

begin_comment
comment|/* RW - warm port reset change */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_OCC
value|0x00100000
end_define

begin_comment
comment|/* RW - over-current change */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PRC
value|0x00200000
end_define

begin_comment
comment|/* RW - port reset change */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_PLC
value|0x00400000
end_define

begin_comment
comment|/* RW - port link state change */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_CEC
value|0x00800000
end_define

begin_comment
comment|/* RW - config error change */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_CAS
value|0x01000000
end_define

begin_comment
comment|/* RO - cold attach status */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_WCE
value|0x02000000
end_define

begin_comment
comment|/* RW - wake on connect enable */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_WDE
value|0x04000000
end_define

begin_comment
comment|/* RW - wake on disconnect enable */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_WOE
value|0x08000000
end_define

begin_comment
comment|/* RW - wake on over-current enable */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_DR
value|0x40000000
end_define

begin_comment
comment|/* RO - device removable */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_WPR
value|0x80000000U
end_define

begin_comment
comment|/* RW - warm port reset */
end_comment

begin_define
define|#
directive|define
name|XHCI_PS_CLEAR
value|0x80FF01FFU
end_define

begin_comment
comment|/* command bits */
end_comment

begin_define
define|#
directive|define
name|XHCI_PORTPMSC
parameter_list|(
name|n
parameter_list|)
value|(0x3F4 + (0x10 * (n)))
end_define

begin_comment
comment|/* XHCI status and control */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM3_U1TO_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFF)
end_define

begin_comment
comment|/* RW - U1 timeout */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM3_U1TO_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 0)
end_define

begin_comment
comment|/* RW - U1 timeout */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM3_U2TO_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
end_define

begin_comment
comment|/* RW - U2 timeout */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM3_U2TO_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 8)
end_define

begin_comment
comment|/* RW - U2 timeout */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM3_FLA
value|0x00010000
end_define

begin_comment
comment|/* RW - Force Link PM Accept */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM2_L1S_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7)
end_define

begin_comment
comment|/* RO - L1 status */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM2_RWE
value|0x00000008
end_define

begin_comment
comment|/* RW - remote wakup enable */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM2_HIRD_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xF)
end_define

begin_comment
comment|/* RW - host initiated resume duration */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM2_HIRD_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 4)
end_define

begin_comment
comment|/* RW - host initiated resume duration */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM2_L1SLOT_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
end_define

begin_comment
comment|/* RW - L1 device slot */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM2_L1SLOT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 8)
end_define

begin_comment
comment|/* RW - L1 device slot */
end_comment

begin_define
define|#
directive|define
name|XHCI_PM2_HLE
value|0x00010000
end_define

begin_comment
comment|/* RW - hardware LPM enable */
end_comment

begin_define
define|#
directive|define
name|XHCI_PORTLI
parameter_list|(
name|n
parameter_list|)
value|(0x3F8 + (0x10 * (n)))
end_define

begin_comment
comment|/* XHCI port link info */
end_comment

begin_define
define|#
directive|define
name|XHCI_PLI3_ERR_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_comment
comment|/* RO - port link errors */
end_comment

begin_define
define|#
directive|define
name|XHCI_PORTRSV
parameter_list|(
name|n
parameter_list|)
value|(0x3FC + (0x10 * (n)))
end_define

begin_comment
comment|/* XHCI port reserved */
end_comment

begin_comment
comment|/* XHCI runtime registers.  Offset given by XHCI_CAPLENGTH + XHCI_RTSOFF registers */
end_comment

begin_define
define|#
directive|define
name|XHCI_MFINDEX
value|0x0000
end_define

begin_comment
comment|/* RO - microframe index */
end_comment

begin_define
define|#
directive|define
name|XHCI_MFINDEX_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|XHCI_IMAN
parameter_list|(
name|n
parameter_list|)
value|(0x0020 + (0x20 * (n)))
end_define

begin_comment
comment|/* XHCI interrupt management */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMAN_INTR_PEND
value|0x00000001
end_define

begin_comment
comment|/* RW - interrupt pending */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMAN_INTR_ENA
value|0x00000002
end_define

begin_comment
comment|/* RW - interrupt enable */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMOD
parameter_list|(
name|n
parameter_list|)
value|(0x0024 + (0x20 * (n)))
end_define

begin_comment
comment|/* XHCI interrupt moderation */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMOD_IVAL_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_comment
comment|/* 250ns unit */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMOD_IVAL_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_comment
comment|/* 250ns unit */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMOD_ICNT_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_comment
comment|/* 250ns unit */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMOD_ICNT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_comment
comment|/* 250ns unit */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMOD_DEFAULT
value|0x000001F4U
end_define

begin_comment
comment|/* 8000 IRQs/second */
end_comment

begin_define
define|#
directive|define
name|XHCI_IMOD_DEFAULT_LP
value|0x000003F8U
end_define

begin_comment
comment|/* 4000 IRQs/second - LynxPoint */
end_comment

begin_define
define|#
directive|define
name|XHCI_ERSTSZ
parameter_list|(
name|n
parameter_list|)
value|(0x0028 + (0x20 * (n)))
end_define

begin_comment
comment|/* XHCI event ring segment table size */
end_comment

begin_define
define|#
directive|define
name|XHCI_ERSTS_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|XHCI_ERSTS_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|XHCI_ERSTBA_LO
parameter_list|(
name|n
parameter_list|)
value|(0x0030 + (0x20 * (n)))
end_define

begin_comment
comment|/* XHCI event ring segment table BA */
end_comment

begin_define
define|#
directive|define
name|XHCI_ERSTBA_HI
parameter_list|(
name|n
parameter_list|)
value|(0x0034 + (0x20 * (n)))
end_define

begin_comment
comment|/* XHCI event ring segment table BA */
end_comment

begin_define
define|#
directive|define
name|XHCI_ERDP_LO
parameter_list|(
name|n
parameter_list|)
value|(0x0038 + (0x20 * (n)))
end_define

begin_comment
comment|/* XHCI event ring dequeue pointer */
end_comment

begin_define
define|#
directive|define
name|XHCI_ERDP_LO_SINDEX
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_comment
comment|/* RO - dequeue segment index */
end_comment

begin_define
define|#
directive|define
name|XHCI_ERDP_LO_BUSY
value|0x00000008
end_define

begin_comment
comment|/* RW - event handler busy */
end_comment

begin_define
define|#
directive|define
name|XHCI_ERDP_HI
parameter_list|(
name|n
parameter_list|)
value|(0x003C + (0x20 * (n)))
end_define

begin_comment
comment|/* XHCI event ring dequeue pointer */
end_comment

begin_comment
comment|/* XHCI doorbell registers. Offset given by XHCI_CAPLENGTH + XHCI_DBOFF registers */
end_comment

begin_define
define|#
directive|define
name|XHCI_DOORBELL
parameter_list|(
name|n
parameter_list|)
value|(0x0000 + (4 * (n)))
end_define

begin_define
define|#
directive|define
name|XHCI_DB_TARGET_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_comment
comment|/* RW - doorbell target */
end_comment

begin_define
define|#
directive|define
name|XHCI_DB_TARGET_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_comment
comment|/* RW - doorbell target */
end_comment

begin_define
define|#
directive|define
name|XHCI_DB_SID_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_comment
comment|/* RW - doorbell stream ID */
end_comment

begin_define
define|#
directive|define
name|XHCI_DB_SID_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_comment
comment|/* RW - doorbell stream ID */
end_comment

begin_comment
comment|/* XHCI legacy support */
end_comment

begin_define
define|#
directive|define
name|XHCI_XECP_ID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|XHCI_XECP_NEXT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
end_define

begin_define
define|#
directive|define
name|XHCI_XECP_BIOS_SEM
value|0x0002
end_define

begin_define
define|#
directive|define
name|XHCI_XECP_OS_SEM
value|0x0003
end_define

begin_comment
comment|/* XHCI capability ID's */
end_comment

begin_define
define|#
directive|define
name|XHCI_ID_USB_LEGACY
value|0x0001
end_define

begin_define
define|#
directive|define
name|XHCI_ID_PROTOCOLS
value|0x0002
end_define

begin_define
define|#
directive|define
name|XHCI_ID_POWER_MGMT
value|0x0003
end_define

begin_define
define|#
directive|define
name|XHCI_ID_VIRTUALIZATION
value|0x0004
end_define

begin_define
define|#
directive|define
name|XHCI_ID_MSG_IRQ
value|0x0005
end_define

begin_define
define|#
directive|define
name|XHCI_ID_USB_LOCAL_MEM
value|0x0006
end_define

begin_comment
comment|/* XHCI register R/W wrappers */
end_comment

begin_define
define|#
directive|define
name|XREAD1
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|,
name|a
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_io_tag, (sc)->sc_io_hdl, \ 		(a) + (sc)->sc_##what##_off)
end_define

begin_define
define|#
directive|define
name|XREAD2
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|,
name|a
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_io_tag, (sc)->sc_io_hdl, \ 		(a) + (sc)->sc_##what##_off)
end_define

begin_define
define|#
directive|define
name|XREAD4
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|,
name|a
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_io_tag, (sc)->sc_io_hdl, \ 		(a) + (sc)->sc_##what##_off)
end_define

begin_define
define|#
directive|define
name|XWRITE1
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_io_tag, (sc)->sc_io_hdl, \ 		(a) + (sc)->sc_##what##_off, (x))
end_define

begin_define
define|#
directive|define
name|XWRITE2
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_io_tag, (sc)->sc_io_hdl, \ 		(a) + (sc)->sc_##what##_off, (x))
end_define

begin_define
define|#
directive|define
name|XWRITE4
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|,
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_io_tag, (sc)->sc_io_hdl, \ 		(a) + (sc)->sc_##what##_off, (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XHCIREG_H_ */
end_comment

end_unit

