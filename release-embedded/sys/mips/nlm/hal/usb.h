begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_USB_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_USB_H__
end_define

begin_define
define|#
directive|define
name|USB_CTL_0
value|0x01
end_define

begin_define
define|#
directive|define
name|USB_PHY_0
value|0x0A
end_define

begin_define
define|#
directive|define
name|USB_PHY_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|USB_PHY_PORT_RESET_0
value|0x10
end_define

begin_define
define|#
directive|define
name|USB_PHY_PORT_RESET_1
value|0x20
end_define

begin_define
define|#
directive|define
name|USB_CONTROLLER_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|USB_INT_STATUS
value|0x0E
end_define

begin_define
define|#
directive|define
name|USB_INT_EN
value|0x0F
end_define

begin_define
define|#
directive|define
name|USB_PHY_INTERRUPT_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|USB_OHCI_INTERRUPT_EN
value|0x02
end_define

begin_define
define|#
directive|define
name|USB_OHCI_INTERRUPT1_EN
value|0x04
end_define

begin_define
define|#
directive|define
name|USB_OHCI_INTERRUPT2_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|USB_CTRL_INTERRUPT_EN
value|0x10
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_define
define|#
directive|define
name|nlm_read_usb_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg(b,r)
end_define

begin_define
define|#
directive|define
name|nlm_write_usb_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg(b,r,v)
end_define

begin_define
define|#
directive|define
name|nlm_get_usb_pcibase
parameter_list|(
name|node
parameter_list|,
name|inst
parameter_list|)
value|nlm_pcicfg_base(XLP_IO_USB_OFFSET(node, inst))
end_define

begin_define
define|#
directive|define
name|nlm_get_usb_hcd_base
parameter_list|(
name|node
parameter_list|,
name|inst
parameter_list|)
value|nlm_xkphys_map_pcibar0(nlm_get_usb_pcibase(node, inst))
end_define

begin_define
define|#
directive|define
name|nlm_get_usb_regbase
parameter_list|(
name|node
parameter_list|,
name|inst
parameter_list|)
value|(nlm_get_usb_pcibase(node, inst) + XLP_IO_PCI_HDRSZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

