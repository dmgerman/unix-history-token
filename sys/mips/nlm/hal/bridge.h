begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_HAL_BRIDGE_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_HAL_BRIDGE_H__
end_define

begin_comment
comment|/** * @file_name mio.h * @author Netlogic Microsystems * @brief Basic definitions of XLP memory and io subsystem */
end_comment

begin_comment
comment|/*  * BRIDGE specific registers  *  * These registers start after the PCIe header, which has 0x40  * standard entries  */
end_comment

begin_define
define|#
directive|define
name|BRIDGE_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCI_CFG_BASE
value|0x01
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCI_CFG_LIMIT
value|0x02
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIE_CFG_BASE
value|0x03
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIE_CFG_LIMIT
value|0x04
end_define

begin_define
define|#
directive|define
name|BRIDGE_BUSNUM_BAR0
value|0x05
end_define

begin_define
define|#
directive|define
name|BRIDGE_BUSNUM_BAR1
value|0x06
end_define

begin_define
define|#
directive|define
name|BRIDGE_BUSNUM_BAR2
value|0x07
end_define

begin_define
define|#
directive|define
name|BRIDGE_BUSNUM_BAR3
value|0x08
end_define

begin_define
define|#
directive|define
name|BRIDGE_BUSNUM_BAR4
value|0x09
end_define

begin_define
define|#
directive|define
name|BRIDGE_BUSNUM_BAR5
value|0x0a
end_define

begin_define
define|#
directive|define
name|BRIDGE_BUSNUM_BAR6
value|0x0b
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_BAR0
value|0x0c
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_BAR1
value|0x0d
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_BAR2
value|0x0e
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_BAR3
value|0x0f
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_LIMIT0
value|0x10
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_LIMIT1
value|0x11
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_LIMIT2
value|0x12
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_LIMIT3
value|0x13
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR
parameter_list|(
name|i
parameter_list|)
value|(0x14 + (i))
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR0
value|0x14
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR1
value|0x15
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR2
value|0x16
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR3
value|0x17
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR4
value|0x18
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR5
value|0x19
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR6
value|0x1a
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_BAR7
value|0x1b
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT
parameter_list|(
name|i
parameter_list|)
value|(0x1c + (i))
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT0
value|0x1c
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT1
value|0x1d
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT2
value|0x1e
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT3
value|0x1f
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT4
value|0x20
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT5
value|0x21
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT6
value|0x22
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_LIMIT7
value|0x23
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_NODE_TRANSLN0
value|0x24
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_NODE_TRANSLN1
value|0x25
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_NODE_TRANSLN2
value|0x26
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_NODE_TRANSLN3
value|0x27
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_NODE_TRANSLN4
value|0x28
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_NODE_TRANSLN5
value|0x29
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_NODE_TRANSLN6
value|0x2a
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_NODE_TRANSLN7
value|0x2b
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_CHNL_TRANSLN0
value|0x2c
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_CHNL_TRANSLN1
value|0x2d
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_CHNL_TRANSLN2
value|0x2e
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_CHNL_TRANSLN3
value|0x2f
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_CHNL_TRANSLN4
value|0x30
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_CHNL_TRANSLN5
value|0x31
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_CHNL_TRANSLN6
value|0x32
end_define

begin_define
define|#
directive|define
name|BRIDGE_DRAM_CHNL_TRANSLN7
value|0x33
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_BASE0
value|0x34
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_BASE1
value|0x35
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_BASE2
value|0x36
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_BASE3
value|0x37
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_LIMIT0
value|0x38
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_LIMIT1
value|0x39
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_LIMIT2
value|0x3a
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_LIMIT3
value|0x3b
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_BASE0
value|0x3c
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_BASE1
value|0x3d
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_BASE2
value|0x3e
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_BASE3
value|0x3f
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_LIMIT0
value|0x40
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_LIMIT1
value|0x41
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_LIMIT2
value|0x42
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_LIMIT3
value|0x43
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_BASE4
value|0x44
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_BASE5
value|0x45
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_BASE6
value|0x46
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_LIMIT4
value|0x47
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_LIMIT5
value|0x48
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEMEM_LIMIT6
value|0x49
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_BASE4
value|0x4a
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_BASE5
value|0x4b
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_BASE6
value|0x4c
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_LIMIT4
value|0x4d
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_LIMIT5
value|0x4e
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIEIO_LIMIT6
value|0x4f
end_define

begin_define
define|#
directive|define
name|BRIDGE_NBU_EVENT_CNT_CTL
value|0x50
end_define

begin_define
define|#
directive|define
name|BRIDGE_EVNTCTR1_LOW
value|0x51
end_define

begin_define
define|#
directive|define
name|BRIDGE_EVNTCTR1_HI
value|0x52
end_define

begin_define
define|#
directive|define
name|BRIDGE_EVNT_CNT_CTL2
value|0x53
end_define

begin_define
define|#
directive|define
name|BRIDGE_EVNTCTR2_LOW
value|0x54
end_define

begin_define
define|#
directive|define
name|BRIDGE_EVNTCTR2_HI
value|0x55
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_MATCH0
value|0x56
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_MATCH1
value|0x57
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_MATCH_LOW
value|0x58
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_MATCH_HI
value|0x59
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_CTRL
value|0x5a
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_INIT
value|0x5b
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_ACCESS
value|0x5c
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_READ_DATA0
value|0x5d
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_READ_DATA1
value|0x5d
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_READ_DATA2
value|0x5f
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_READ_DATA3
value|0x60
end_define

begin_define
define|#
directive|define
name|BRIDGE_TRACEBUF_STATUS
value|0x61
end_define

begin_define
define|#
directive|define
name|BRIDGE_ADDRESS_ERROR0
value|0x62
end_define

begin_define
define|#
directive|define
name|BRIDGE_ADDRESS_ERROR1
value|0x63
end_define

begin_define
define|#
directive|define
name|BRIDGE_ADDRESS_ERROR2
value|0x64
end_define

begin_define
define|#
directive|define
name|BRIDGE_TAG_ECC_ADDR_ERROR0
value|0x65
end_define

begin_define
define|#
directive|define
name|BRIDGE_TAG_ECC_ADDR_ERROR1
value|0x66
end_define

begin_define
define|#
directive|define
name|BRIDGE_TAG_ECC_ADDR_ERROR2
value|0x67
end_define

begin_define
define|#
directive|define
name|BRIDGE_LINE_FLUSH0
value|0x68
end_define

begin_define
define|#
directive|define
name|BRIDGE_LINE_FLUSH1
value|0x69
end_define

begin_define
define|#
directive|define
name|BRIDGE_NODE_ID
value|0x6a
end_define

begin_define
define|#
directive|define
name|BRIDGE_ERROR_INTERRUPT_EN
value|0x6b
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIE0_WEIGHT
value|0x2c0
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIE1_WEIGHT
value|0x2c1
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIE2_WEIGHT
value|0x2c2
end_define

begin_define
define|#
directive|define
name|BRIDGE_PCIE3_WEIGHT
value|0x2c3
end_define

begin_define
define|#
directive|define
name|BRIDGE_USB_WEIGHT
value|0x2c4
end_define

begin_define
define|#
directive|define
name|BRIDGE_NET_WEIGHT
value|0x2c5
end_define

begin_define
define|#
directive|define
name|BRIDGE_POE_WEIGHT
value|0x2c6
end_define

begin_define
define|#
directive|define
name|BRIDGE_CMS_WEIGHT
value|0x2c7
end_define

begin_define
define|#
directive|define
name|BRIDGE_DMAENG_WEIGHT
value|0x2c8
end_define

begin_define
define|#
directive|define
name|BRIDGE_SEC_WEIGHT
value|0x2c9
end_define

begin_define
define|#
directive|define
name|BRIDGE_COMP_WEIGHT
value|0x2ca
end_define

begin_define
define|#
directive|define
name|BRIDGE_GIO_WEIGHT
value|0x2cb
end_define

begin_define
define|#
directive|define
name|BRIDGE_FLASH_WEIGHT
value|0x2cc
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
name|nlm_read_bridge_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_write_bridge_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_get_bridge_pcibase
parameter_list|(
name|node
parameter_list|)
define|\
value|nlm_pcicfg_base(XLP_IO_BRIDGE_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_get_bridge_regbase
parameter_list|(
name|node
parameter_list|)
define|\
value|(nlm_get_bridge_pcibase(node) + XLP_IO_PCI_HDRSZ)
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

