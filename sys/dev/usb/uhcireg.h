begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: uhcireg.h,v 1.9 1999/11/20 00:57:09 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_PCI_UHCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_PCI_UHCIREG_H_
end_define

begin_comment
comment|/*** PCI config registers ***/
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
name|PCI_USBREV_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|PCI_USBREV_PRE_1_0
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_USBREV_1_0
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_USBREV_1_1
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
comment|/*** UHCI registers ***/
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
name|UHCI_FRAMELIST_COUNT
value|1024
end_define

begin_define
define|#
directive|define
name|UHCI_FRAMELIST_ALIGN
value|4096
end_define

begin_define
define|#
directive|define
name|UHCI_TD_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|UHCI_QH_ALIGN
value|16
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|uhci_physaddr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UHCI_PTR_T
value|0x00000001
end_define

begin_define
define|#
directive|define
name|UHCI_PTR_Q
value|0x00000002
end_define

begin_define
define|#
directive|define
name|UHCI_PTR_VF
value|0x00000004
end_define

begin_comment
comment|/*  * The Queue Heads and Transfer Descriptors and accessed  * by both the CPU and the USB controller which runs  * concurrently.  This means that they have to be accessed  * with great care.  As long as the data structures are  * not linked into the controller's frame list they cannot  * be accessed by it and anything goes.  As soon as a  * TD is accessible by the controller it "owns" the td_status  * field; it will not be written by the CPU.  Similarly  * the controller "owns" the qh_elink field.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uhci_physaddr_t
name|td_link
decl_stmt|;
name|u_int32_t
name|td_status
decl_stmt|;
define|#
directive|define
name|UHCI_TD_GET_ACTLEN
parameter_list|(
name|s
parameter_list|)
value|(((s) + 1)& 0x3ff)
define|#
directive|define
name|UHCI_TD_ZERO_ACTLEN
parameter_list|(
name|t
parameter_list|)
value|((t) | 0x3ff)
define|#
directive|define
name|UHCI_TD_BITSTUFF
value|0x00020000
define|#
directive|define
name|UHCI_TD_CRCTO
value|0x00040000
define|#
directive|define
name|UHCI_TD_NAK
value|0x00080000
define|#
directive|define
name|UHCI_TD_BABBLE
value|0x00100000
define|#
directive|define
name|UHCI_TD_DBUFFER
value|0x00200000
define|#
directive|define
name|UHCI_TD_STALLED
value|0x00400000
define|#
directive|define
name|UHCI_TD_ACTIVE
value|0x00800000
define|#
directive|define
name|UHCI_TD_IOC
value|0x01000000
define|#
directive|define
name|UHCI_TD_IOS
value|0x02000000
define|#
directive|define
name|UHCI_TD_LS
value|0x04000000
define|#
directive|define
name|UHCI_TD_GET_ERRCNT
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 27)& 3)
define|#
directive|define
name|UHCI_TD_SET_ERRCNT
parameter_list|(
name|n
parameter_list|)
value|((n)<< 27)
define|#
directive|define
name|UHCI_TD_SPD
value|0x20000000
name|u_int32_t
name|td_token
decl_stmt|;
define|#
directive|define
name|UHCI_TD_PID_IN
value|0x00000069
define|#
directive|define
name|UHCI_TD_PID_OUT
value|0x000000e1
define|#
directive|define
name|UHCI_TD_PID_SETUP
value|0x0000002d
define|#
directive|define
name|UHCI_TD_GET_PID
parameter_list|(
name|s
parameter_list|)
value|((s)& 0xff)
define|#
directive|define
name|UHCI_TD_SET_DEVADDR
parameter_list|(
name|a
parameter_list|)
value|((a)<< 8)
define|#
directive|define
name|UHCI_TD_GET_DEVADDR
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 8)& 0x7f)
define|#
directive|define
name|UHCI_TD_SET_ENDPT
parameter_list|(
name|e
parameter_list|)
value|(((e)&0xf)<< 15)
define|#
directive|define
name|UHCI_TD_GET_ENDPT
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 15)& 0xf)
define|#
directive|define
name|UHCI_TD_SET_DT
parameter_list|(
name|t
parameter_list|)
value|((t)<< 19)
define|#
directive|define
name|UHCI_TD_GET_DT
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 19)& 1)
define|#
directive|define
name|UHCI_TD_SET_MAXLEN
parameter_list|(
name|l
parameter_list|)
value|(((l)-1)<< 21)
define|#
directive|define
name|UHCI_TD_GET_MAXLEN
parameter_list|(
name|s
parameter_list|)
value|((((s)>> 21) + 1)& 0x7ff)
define|#
directive|define
name|UHCI_TD_MAXLEN_MASK
value|0xffe00000
name|u_int32_t
name|td_buffer
decl_stmt|;
block|}
name|uhci_td_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UHCI_TD_ERROR
value|(UHCI_TD_BITSTUFF|UHCI_TD_CRCTO|UHCI_TD_BABBLE|UHCI_TD_DBUFFER|UHCI_TD_STALLED)
end_define

begin_define
define|#
directive|define
name|UHCI_TD_SETUP
parameter_list|(
name|len
parameter_list|,
name|endp
parameter_list|,
name|dev
parameter_list|)
value|(UHCI_TD_SET_MAXLEN(len) | \      UHCI_TD_SET_ENDPT(endp) | UHCI_TD_SET_DEVADDR(dev) | UHCI_TD_PID_SETUP)
end_define

begin_define
define|#
directive|define
name|UHCI_TD_OUT
parameter_list|(
name|len
parameter_list|,
name|endp
parameter_list|,
name|dev
parameter_list|,
name|dt
parameter_list|)
value|(UHCI_TD_SET_MAXLEN(len) | \      UHCI_TD_SET_ENDPT(endp) | UHCI_TD_SET_DEVADDR(dev) | \      UHCI_TD_PID_OUT | UHCI_TD_SET_DT(dt))
end_define

begin_define
define|#
directive|define
name|UHCI_TD_IN
parameter_list|(
name|len
parameter_list|,
name|endp
parameter_list|,
name|dev
parameter_list|,
name|dt
parameter_list|)
value|(UHCI_TD_SET_MAXLEN(len) | \      UHCI_TD_SET_ENDPT(endp) | UHCI_TD_SET_DEVADDR(dev) | UHCI_TD_PID_IN | \      UHCI_TD_SET_DT(dt))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uhci_physaddr_t
name|qh_hlink
decl_stmt|;
name|uhci_physaddr_t
name|qh_elink
decl_stmt|;
block|}
name|uhci_qh_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_PCI_UHCIREG_H_ */
end_comment

end_unit

