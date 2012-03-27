begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_HAL_IOMAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_HAL_IOMAP_H__
end_define

begin_define
define|#
directive|define
name|XLP_DEFAULT_IO_BASE
value|0x18000000
end_define

begin_define
define|#
directive|define
name|NMI_BASE
value|0xbfc00000
end_define

begin_define
define|#
directive|define
name|XLP_IO_CLK
value|133333333
end_define

begin_define
define|#
directive|define
name|XLP_L2L3_CACHELINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|XLP_PCIE_CFG_SIZE
value|0x1000
end_define

begin_comment
comment|/* 4K */
end_comment

begin_define
define|#
directive|define
name|XLP_PCIE_DEV_BLK_SIZE
value|(8 * XLP_PCIE_CFG_SIZE)
end_define

begin_define
define|#
directive|define
name|XLP_PCIE_BUS_BLK_SIZE
value|(256 * XLP_PCIE_DEV_BLK_SIZE)
end_define

begin_define
define|#
directive|define
name|XLP_IO_SIZE
value|(64<< 20)
end_define

begin_comment
comment|/* ECFG space size */
end_comment

begin_define
define|#
directive|define
name|XLP_IO_PCI_HDRSZ
value|0x100
end_define

begin_define
define|#
directive|define
name|XLP_IO_DEV
parameter_list|(
name|node
parameter_list|,
name|dev
parameter_list|)
value|((dev) + (node) * 8)
end_define

begin_define
define|#
directive|define
name|XLP_HDR_OFFSET
parameter_list|(
name|node
parameter_list|,
name|bus
parameter_list|,
name|dev
parameter_list|,
name|fn
parameter_list|)
value|(((bus)<< 20) | \ 				((XLP_IO_DEV(node, dev))<< 15) | ((fn)<< 12))
end_define

begin_define
define|#
directive|define
name|XLP_IO_BRIDGE_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 0, 0)
end_define

begin_comment
comment|/* coherent inter chip */
end_comment

begin_define
define|#
directive|define
name|XLP_IO_CIC0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 0, 1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_CIC1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 0, 2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_CIC2_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 0, 3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PIC_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 0, 4)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE_OFFSET
parameter_list|(
name|node
parameter_list|,
name|i
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 1, i)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 1, 0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 1, 1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE2_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 1, 2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE3_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 1, 3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OFFSET
parameter_list|(
name|node
parameter_list|,
name|i
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 2, i)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_EHCI0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 2, 0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OHCI0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 2, 1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OHCI1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 2, 2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_EHCI1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 2, 3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OHCI2_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 2, 4)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OHCI3_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 2, 5)
end_define

begin_define
define|#
directive|define
name|XLP_IO_NAE_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 3, 0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_POE_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 3, 1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_SATA_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 3, 2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_CMS_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 4, 0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_DMA_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 5, 0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_SEC_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 5, 1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_RSA_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 5, 2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_CMP_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 5, 3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_SRIO_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 5, 4)
end_define

begin_define
define|#
directive|define
name|XLP_IO_REGEX_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 5, 5)
end_define

begin_define
define|#
directive|define
name|XLP_IO_UART_OFFSET
parameter_list|(
name|node
parameter_list|,
name|i
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, i)
end_define

begin_define
define|#
directive|define
name|XLP_IO_UART0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, 0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_UART1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, 1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_I2C_OFFSET
parameter_list|(
name|node
parameter_list|,
name|i
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, 2 + i)
end_define

begin_define
define|#
directive|define
name|XLP_IO_I2C0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, 2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_I2C1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, 3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_GPIO_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, 4)
end_define

begin_comment
comment|/* system management */
end_comment

begin_define
define|#
directive|define
name|XLP_IO_SYS_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, 5)
end_define

begin_define
define|#
directive|define
name|XLP_IO_JTAG_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 6, 6)
end_define

begin_define
define|#
directive|define
name|XLP_IO_NOR_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 7, 0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_NAND_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 7, 1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_SPI_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 7, 2)
end_define

begin_comment
comment|/* SD flash */
end_comment

begin_define
define|#
directive|define
name|XLP_IO_SD_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node, 0, 7, 3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_MMC_OFFSET
parameter_list|(
name|node
parameter_list|,
name|slot
parameter_list|)
define|\
value|((XLP_IO_SD_OFFSET(node))+(slot*0x100)+XLP_IO_PCI_HDRSZ)
end_define

begin_comment
comment|/* PCI config header register id's */
end_comment

begin_define
define|#
directive|define
name|XLP_PCI_CFGREG0
value|0x00
end_define

begin_define
define|#
directive|define
name|XLP_PCI_CFGREG1
value|0x01
end_define

begin_define
define|#
directive|define
name|XLP_PCI_CFGREG2
value|0x02
end_define

begin_define
define|#
directive|define
name|XLP_PCI_CFGREG3
value|0x03
end_define

begin_define
define|#
directive|define
name|XLP_PCI_CFGREG4
value|0x04
end_define

begin_define
define|#
directive|define
name|XLP_PCI_CFGREG5
value|0x05
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVINFO_REG0
value|0x30
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVINFO_REG1
value|0x31
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVINFO_REG2
value|0x32
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVINFO_REG3
value|0x33
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVINFO_REG4
value|0x34
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVINFO_REG5
value|0x35
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVINFO_REG6
value|0x36
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVINFO_REG7
value|0x37
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVSCRATCH_REG0
value|0x38
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVSCRATCH_REG1
value|0x39
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVSCRATCH_REG2
value|0x3a
end_define

begin_define
define|#
directive|define
name|XLP_PCI_DEVSCRATCH_REG3
value|0x3b
end_define

begin_define
define|#
directive|define
name|XLP_PCI_MSGSTN_REG
value|0x3c
end_define

begin_define
define|#
directive|define
name|XLP_PCI_IRTINFO_REG
value|0x3d
end_define

begin_define
define|#
directive|define
name|XLP_PCI_UCODEINFO_REG
value|0x3e
end_define

begin_define
define|#
directive|define
name|XLP_PCI_SBB_WT_REG
value|0x3f
end_define

begin_comment
comment|/* PCI IDs for SoC device */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_NETLOGIC
value|0x184e
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_ROOT
value|0x1001
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_ICI
value|0x1002
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_PIC
value|0x1003
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_PCIE
value|0x1004
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_EHCI
value|0x1007
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_ILK
value|0x1008
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_NAE
value|0x1009
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_POE
value|0x100A
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_FMN
value|0x100B
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_RAID
value|0x100D
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_SAE
value|0x100D
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_RSA
value|0x100E
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_CMP
value|0x100F
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_UART
value|0x1010
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_I2C
value|0x1011
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_NOR
value|0x1015
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_NAND
value|0x1016
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_NLM_MMC
value|0x1018
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
name|nlm_read_pci_reg
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
name|nlm_write_pci_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg(b, r, v)
end_define

begin_decl_stmt
specifier|extern
name|uint64_t
name|xlp_sys_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|xlp_pic_base
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline__
name|int
name|nlm_dev_exists
parameter_list|(
name|uint32_t
name|devoffset
parameter_list|)
block|{
name|uint64_t
name|pcibase
init|=
name|nlm_pcicfg_base
argument_list|(
name|devoffset
argument_list|)
decl_stmt|;
return|return
operator|(
name|nlm_read_reg
argument_list|(
name|pcibase
argument_list|,
name|XLP_PCI_CFGREG0
argument_list|)
operator|!=
literal|0xffffffff
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_qidstart
parameter_list|(
name|uint64_t
name|pcibase
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_reg
argument_list|(
name|pcibase
argument_list|,
name|XLP_PCI_MSGSTN_REG
argument_list|)
operator|&
literal|0xffff
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_qnum
parameter_list|(
name|uint64_t
name|pcibase
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_reg
argument_list|(
name|pcibase
argument_list|,
name|XLP_PCI_MSGSTN_REG
argument_list|)
operator|>>
literal|16
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_irtstart
parameter_list|(
name|uint64_t
name|pcibase
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_reg
argument_list|(
name|pcibase
argument_list|,
name|XLP_PCI_IRTINFO_REG
argument_list|)
operator|&
literal|0xffff
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_irtnum
parameter_list|(
name|uint64_t
name|pcibase
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_reg
argument_list|(
name|pcibase
argument_list|,
name|XLP_PCI_IRTINFO_REG
argument_list|)
operator|>>
literal|16
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|nlm_num_uengines
parameter_list|(
name|uint64_t
name|pcibase
parameter_list|)
block|{
return|return
name|nlm_read_reg
argument_list|(
name|pcibase
argument_list|,
name|XLP_PCI_UCODEINFO_REG
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Find node on which a given Soc device is located.  * input is the pci device (slot) number.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|nlm_get_device_node
parameter_list|(
name|int
name|device
parameter_list|)
block|{
return|return
operator|(
name|device
operator|/
literal|8
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE or !__ASSEMBLY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NLM_HAL_IOMAP_H__ */
end_comment

end_unit

