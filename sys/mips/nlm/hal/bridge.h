begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  * NETLOGIC_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_BRIDGE_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_BRIDGE_H__
end_define

begin_comment
comment|/** * @file_name mio.h * @author Netlogic Microsystems * @brief Basic definitions of XLP memory and io subsystem */
end_comment

begin_comment
comment|/* BRIDGE specific registers */
end_comment

begin_define
define|#
directive|define
name|XLP_BRIDGE_MODE_REG
value|0x40
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCI_CFG_BASE_REG
value|0x41
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCI_CFG_LIMIT_REG
value|0x42
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIE_CFG_BASE_REG
value|0x43
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIE_CFG_LIMIT_REG
value|0x44
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_BUSNUM_BAR0_REG
value|0x45
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_BUSNUM_BAR1_REG
value|0x46
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_BUSNUM_BAR2_REG
value|0x47
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_BUSNUM_BAR3_REG
value|0x48
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_BUSNUM_BAR4_REG
value|0x49
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_BUSNUM_BAR5_REG
value|0x4a
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_BUSNUM_BAR6_REG
value|0x4b
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_BAR0_REG
value|0x4c
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_BAR1_REG
value|0x4d
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_BAR2_REG
value|0x4e
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_BAR3_REG
value|0x4f
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_LIMIT0_REG
value|0x50
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_LIMIT1_REG
value|0x51
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_LIMIT2_REG
value|0x52
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_LIMIT3_REG
value|0x53
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR_REG
parameter_list|(
name|i
parameter_list|)
value|(0x54 + (i))
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR0_REG
value|0x54
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR1_REG
value|0x55
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR2_REG
value|0x56
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR3_REG
value|0x57
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR4_REG
value|0x58
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR5_REG
value|0x59
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR6_REG
value|0x5a
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_BAR7_REG
value|0x5b
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT_REG
parameter_list|(
name|i
parameter_list|)
value|(0x5c + (i))
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT0_REG
value|0x5c
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT1_REG
value|0x5d
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT2_REG
value|0x5e
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT3_REG
value|0x5f
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT4_REG
value|0x60
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT5_REG
value|0x61
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT6_REG
value|0x62
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_LIMIT7_REG
value|0x63
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_NODE_TRANSLN0_REG
value|0x64
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_NODE_TRANSLN1_REG
value|0x65
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_NODE_TRANSLN2_REG
value|0x66
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_NODE_TRANSLN3_REG
value|0x67
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_NODE_TRANSLN4_REG
value|0x68
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_NODE_TRANSLN5_REG
value|0x69
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_NODE_TRANSLN6_REG
value|0x6a
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_NODE_TRANSLN7_REG
value|0x6b
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_CHNL_TRANSLN0_REG
value|0x6c
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_CHNL_TRANSLN1_REG
value|0x6d
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_CHNL_TRANSLN2_REG
value|0x6e
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_CHNL_TRANSLN3_REG
value|0x6f
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_CHNL_TRANSLN4_REG
value|0x70
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_CHNL_TRANSLN5_REG
value|0x71
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_CHNL_TRANSLN6_REG
value|0x72
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DRAM_CHNL_TRANSLN7_REG
value|0x73
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_BASE0_REG
value|0x74
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_BASE1_REG
value|0x75
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_BASE2_REG
value|0x76
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_BASE3_REG
value|0x77
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_LIMIT0_REG
value|0x78
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_LIMIT1_REG
value|0x79
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_LIMIT2_REG
value|0x7a
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_LIMIT3_REG
value|0x7b
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_BASE0_REG
value|0x7c
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_BASE1_REG
value|0x7d
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_BASE2_REG
value|0x7e
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_BASE3_REG
value|0x7f
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_LIMIT0_REG
value|0x80
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_LIMIT1_REG
value|0x81
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_LIMIT2_REG
value|0x82
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_LIMIT3_REG
value|0x83
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_BASE4_REG
value|0x84
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_BASE5_REG
value|0x85
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_BASE6_REG
value|0x86
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_LIMIT4_REG
value|0x87
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_LIMIT5_REG
value|0x88
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEMEM_LIMIT6_REG
value|0x89
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_BASE4_REG
value|0x8a
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_BASE5_REG
value|0x8b
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_BASE6_REG
value|0x8c
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_LIMIT4_REG
value|0x8d
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_LIMIT5_REG
value|0x8e
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIEIO_LIMIT6_REG
value|0x8f
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_NBU_EVENT_CNT_CTL_REG
value|0x90
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_EVNTCTR1_LOW_REG
value|0x91
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_EVNTCTR1_HI_REG
value|0x92
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_EVNT_CNT_CTL2_REG
value|0x93
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_EVNTCTR2_LOW_REG
value|0x94
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_EVNTCTR2_HI_REG
value|0x95
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_MATCH_REG0
value|0x96
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_MATCH_REG1
value|0x97
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_MATCH_LOW_REG
value|0x98
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_MATCH_HI_REG
value|0x99
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_CTRL_REG
value|0x9a
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_INIT_REG
value|0x9b
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_ACCESS_REG
value|0x9c
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_READ_DATA_REG0
value|0x9d
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_READ_DATA_REG1
value|0x9d
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_READ_DATA_REG2
value|0x9f
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_READ_DATA_REG3
value|0xa0
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TRACEBUF_STATUS_REG
value|0xa1
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_ADDRESS_ERROR0_REG
value|0xa2
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_ADDRESS_ERROR1_REG
value|0xa3
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_ADDRESS_ERROR2_REG
value|0xa4
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TAG_ECC_ADDR_ERROR0_REG
value|0xa5
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TAG_ECC_ADDR_ERROR1_REG
value|0xa6
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_TAG_ECC_ADDR_ERROR2_REG
value|0xa7
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_LINE_FLUSH_REG0
value|0xa8
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_LINE_FLUSH_REG1
value|0xa9
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_NODE_ID_REG
value|0xaa
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_ERROR_INTERRUPT_EN_REG
value|0xab
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIE0_WEIGHT_REG
value|0x300
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIE1_WEIGHT_REG
value|0x301
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIE2_WEIGHT_REG
value|0x302
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_PCIE3_WEIGHT_REG
value|0x303
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_USB_WEIGHT_REG
value|0x304
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_NET_WEIGHT_REG
value|0x305
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_POE_WEIGHT_REG
value|0x306
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_CMS_WEIGHT_REG
value|0x307
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_DMAENG_WEIGHT_REG
value|0x308
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_SEC_WEIGHT_REG
value|0x309
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_COMP_WEIGHT_REG
value|0x30a
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_GIO_WEIGHT_REG
value|0x30b
end_define

begin_define
define|#
directive|define
name|XLP_BRIDGE_FLASH_WEIGHT_REG
value|0x30c
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
name|nlm_rdreg_bridge
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg_kseg(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_wreg_bridge
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg_kseg(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_pcibase_bridge
parameter_list|(
name|node
parameter_list|)
value|nlm_pcicfg_base(XLP_IO_BRIDGE_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_regbase_bridge
parameter_list|(
name|node
parameter_list|)
value|nlm_pcibase_bridge(node)
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

