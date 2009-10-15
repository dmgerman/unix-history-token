begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UHCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_UHCIREG_H_
end_define

begin_comment
comment|/* PCI config registers  */
end_comment

begin_define
define|#
directive|define
name|PCI_USBREV
value|0x60
end_define

begin_comment
comment|/* USB protocol revision */
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
name|PCI_LEGSUP
value|0xc0
end_define

begin_comment
comment|/* Legacy Support register */
end_comment

begin_define
define|#
directive|define
name|PCI_LEGSUP_USBPIRQDEN
value|0x2000
end_define

begin_comment
comment|/* USB PIRQ D Enable */
end_comment

begin_define
define|#
directive|define
name|PCI_CBIO
value|0x20
end_define

begin_comment
comment|/* configuration base IO */
end_comment

begin_define
define|#
directive|define
name|PCI_INTERFACE_UHCI
value|0x00
end_define

begin_comment
comment|/* UHCI registers */
end_comment

begin_define
define|#
directive|define
name|UHCI_CMD
value|0x00
end_define

begin_define
define|#
directive|define
name|UHCI_CMD_RS
value|0x0001
end_define

begin_define
define|#
directive|define
name|UHCI_CMD_HCRESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|UHCI_CMD_GRESET
value|0x0004
end_define

begin_define
define|#
directive|define
name|UHCI_CMD_EGSM
value|0x0008
end_define

begin_define
define|#
directive|define
name|UHCI_CMD_FGR
value|0x0010
end_define

begin_define
define|#
directive|define
name|UHCI_CMD_SWDBG
value|0x0020
end_define

begin_define
define|#
directive|define
name|UHCI_CMD_CF
value|0x0040
end_define

begin_define
define|#
directive|define
name|UHCI_CMD_MAXP
value|0x0080
end_define

begin_define
define|#
directive|define
name|UHCI_STS
value|0x02
end_define

begin_define
define|#
directive|define
name|UHCI_STS_USBINT
value|0x0001
end_define

begin_define
define|#
directive|define
name|UHCI_STS_USBEI
value|0x0002
end_define

begin_define
define|#
directive|define
name|UHCI_STS_RD
value|0x0004
end_define

begin_define
define|#
directive|define
name|UHCI_STS_HSE
value|0x0008
end_define

begin_define
define|#
directive|define
name|UHCI_STS_HCPE
value|0x0010
end_define

begin_define
define|#
directive|define
name|UHCI_STS_HCH
value|0x0020
end_define

begin_define
define|#
directive|define
name|UHCI_STS_ALLINTRS
value|0x003f
end_define

begin_define
define|#
directive|define
name|UHCI_INTR
value|0x04
end_define

begin_define
define|#
directive|define
name|UHCI_INTR_TOCRCIE
value|0x0001
end_define

begin_define
define|#
directive|define
name|UHCI_INTR_RIE
value|0x0002
end_define

begin_define
define|#
directive|define
name|UHCI_INTR_IOCE
value|0x0004
end_define

begin_define
define|#
directive|define
name|UHCI_INTR_SPIE
value|0x0008
end_define

begin_define
define|#
directive|define
name|UHCI_FRNUM
value|0x06
end_define

begin_define
define|#
directive|define
name|UHCI_FRNUM_MASK
value|0x03ff
end_define

begin_define
define|#
directive|define
name|UHCI_FLBASEADDR
value|0x08
end_define

begin_define
define|#
directive|define
name|UHCI_SOF
value|0x0c
end_define

begin_define
define|#
directive|define
name|UHCI_SOF_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC1
value|0x010
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC2
value|0x012
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_CCS
value|0x0001
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_CSC
value|0x0002
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_PE
value|0x0004
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_POEDC
value|0x0008
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_LS
value|0x0030
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_LS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_RD
value|0x0040
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_LSDA
value|0x0100
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_PR
value|0x0200
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_OCI
value|0x0400
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_OCIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|UHCI_PORTSC_SUSP
value|0x1000
end_define

begin_define
define|#
directive|define
name|URWMASK
parameter_list|(
name|x
parameter_list|)
value|((x)& (UHCI_PORTSC_SUSP |		\ 				UHCI_PORTSC_PR | UHCI_PORTSC_RD |	\ 				UHCI_PORTSC_PE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UHCIREG_H_ */
end_comment

end_unit

