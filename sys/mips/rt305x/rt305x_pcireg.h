begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Stanislav Galabov.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RT305X_PCIREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__RT305X_PCIREG_H__
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_NIRQS
value|1
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_BASESLOT
value|0
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCICFG
value|0x0000
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIINT
value|0x0008
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIENA
value|0x000C
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_CFGADDR
value|0x0020
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_CFGDATA
value|0x0024
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_MEMBASE
value|0x0028
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_IOBASE
value|0x002C
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PHY0_CFG
value|0x0090
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_BAR0SETUP
value|0x2010
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_BAR1SETUP
value|0x2014
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_IMBASEBAR0
value|0x2018
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_ID
value|0x2030
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_CLASS
value|0x2034
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_SUBID
value|0x2038
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_STATUS
value|0x2050
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_DLECR
value|0x2060
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_PCIE0_ECRC
value|0x2064
end_define

begin_define
define|#
directive|define
name|RT305X_PCIE0_IRQ
value|20
end_define

begin_define
define|#
directive|define
name|RT305X_PCIE1_IRQ
value|21
end_define

begin_define
define|#
directive|define
name|RT305X_PCIE2_IRQ
value|22
end_define

begin_define
define|#
directive|define
name|RT305X_PCI_INTR_PIN
value|2
end_define

begin_define
define|#
directive|define
name|PCI_MIN_IO_ALLOC
value|4
end_define

begin_define
define|#
directive|define
name|PCI_MIN_MEM_ALLOC
value|16
end_define

begin_define
define|#
directive|define
name|BITS_PER_UINT32
value|(NBBY * sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|RT_WRITE32
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_bst, (sc)->sc_bsh, (off), (val))
end_define

begin_define
define|#
directive|define
name|RT_WRITE16
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_bst, (sc)->sc_bsh, (off), (val))
end_define

begin_define
define|#
directive|define
name|RT_WRITE8
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_bst, (sc)->sc_bsh, (off), (val))
end_define

begin_define
define|#
directive|define
name|RT_READ32
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_bst, (sc)->sc_bsh, (off))
end_define

begin_define
define|#
directive|define
name|RT_READ16
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_bst, (sc)->sc_bsh, (off))
end_define

begin_define
define|#
directive|define
name|RT_READ8
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_bst, (sc)->sc_bsh, (off))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RT305X_PCIREG_H__ */
end_comment

end_unit

