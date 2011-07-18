begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  * NETLOGIC_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_IOMAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_IOMAP_H__
end_define

begin_comment
comment|/** * @file_name xlpiomap.h * @author Netlogic Microsystems * @brief Basic definitions Netlogic XLP IO BASEs */
end_comment

begin_comment
comment|/* ----------------------------------  *   XLP RESET Physical Address Map  * ----------------------------------  * PCI ECFG : 0x18000000 - 0x1bffffff  * PCI CFG  : 0x1c000000 - 0x1cffffff  * FLASH    : 0x1fc00000 - 0x1fffffff  * ----------------------------------  */
end_comment

begin_define
define|#
directive|define
name|XLP_DEFAULT_IO_BASE
value|0x18000000
end_define

begin_define
define|#
directive|define
name|XLP_DEFAULT_IO_BASE_KSEG1
value|0xb8000000
end_define

begin_define
define|#
directive|define
name|XLP_IO_SIZE
value|(64<< 20)
end_define

begin_comment
comment|/* Size of the ECFG Space      */
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
value|XLP_HDR_OFFSET(node,0,0,0)
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
value|XLP_HDR_OFFSET(node,0,0,1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_CIC1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,0,2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_CIC2_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,0,3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PIC_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,0,4)
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
value|XLP_HDR_OFFSET(node,0,1,i)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,1,0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,1,1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE2_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,1,2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_PCIE3_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,1,3)
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
value|XLP_HDR_OFFSET(node,0,2,i)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_EHCI0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,2,0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OHCI0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,2,1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OHCI1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,2,2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_EHCI1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,2,3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OHCI2_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,2,4)
end_define

begin_define
define|#
directive|define
name|XLP_IO_USB_OHCI3_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,2,5)
end_define

begin_define
define|#
directive|define
name|XLP_IO_NAE_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,3,0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_POE_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,3,1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_CMS_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,4,0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_DMA_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,5,1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_SEC_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,5,2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_CMP_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,5,3)
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
value|XLP_HDR_OFFSET(node,0,6,i)
end_define

begin_define
define|#
directive|define
name|XLP_IO_UART0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,6,0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_UART1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,6,1)
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
value|XLP_HDR_OFFSET(node,0,6,2+i)
end_define

begin_define
define|#
directive|define
name|XLP_IO_I2C0_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,6,2)
end_define

begin_define
define|#
directive|define
name|XLP_IO_I2C1_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,6,3)
end_define

begin_define
define|#
directive|define
name|XLP_IO_GPIO_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,6,4)
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
value|XLP_HDR_OFFSET(node,0,6,5)
end_define

begin_define
define|#
directive|define
name|XLP_IO_JTAG_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,6,6)
end_define

begin_define
define|#
directive|define
name|XLP_IO_NOR_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,7,0)
end_define

begin_define
define|#
directive|define
name|XLP_IO_NAND_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,7,1)
end_define

begin_define
define|#
directive|define
name|XLP_IO_SPI_OFFSET
parameter_list|(
name|node
parameter_list|)
value|XLP_HDR_OFFSET(node,0,7,2)
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
value|XLP_HDR_OFFSET(node,0,7,3)
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

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_NLMIO_H__
end_ifndef

begin_error
error|#
directive|error
error|iomap.h needs mmio.h to be included
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_read_reg_kseg
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|addr
init|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|base
operator|+
name|reg
decl_stmt|;
return|return
operator|(
operator|*
name|addr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_write_reg_kseg
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|addr
init|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|base
operator|+
name|reg
decl_stmt|;
operator|*
name|addr
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_read_reg64_kseg
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
specifier|volatile
name|uint64_t
modifier|*
name|addr
init|=
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|base
operator|+
operator|(
name|reg
operator|>>
literal|1
operator|)
decl_stmt|;
return|return
operator|(
name|nlm_load_dword
argument_list|(
name|addr
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_write_reg64_kseg
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
specifier|volatile
name|uint64_t
modifier|*
name|addr
init|=
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|base
operator|+
operator|(
name|reg
operator|>>
literal|1
operator|)
decl_stmt|;
return|return
operator|(
name|nlm_store_dword
argument_list|(
name|addr
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Routines to store 32/64 bit values to 64 bit addresses,  * used when going thru XKPHYS to access registers  */
end_comment

begin_function
specifier|static
name|__inline__
name|uint32_t
name|nlm_read_reg_xkseg
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
name|uint64_t
name|addr
init|=
name|base
operator|+
name|reg
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
decl_stmt|;
return|return
operator|(
name|nlm_load_word_daddr
argument_list|(
name|addr
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_write_reg_xkseg
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint64_t
name|addr
init|=
name|base
operator|+
name|reg
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
decl_stmt|;
return|return
operator|(
name|nlm_store_word_daddr
argument_list|(
name|addr
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_read_reg64_xkseg
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
name|uint64_t
name|addr
init|=
name|base
operator|+
operator|(
name|reg
operator|>>
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
decl_stmt|;
return|return
operator|(
name|nlm_load_dword_daddr
argument_list|(
name|addr
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|nlm_write_reg64_xkseg
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|addr
init|=
name|base
operator|+
operator|(
name|reg
operator|>>
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
decl_stmt|;
return|return
operator|(
name|nlm_store_dword_daddr
argument_list|(
name|addr
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Location where IO base is mapped */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|nlm_pcicfg_baseaddr
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_pcicfg_base
parameter_list|(
name|uint32_t
name|devoffset
parameter_list|)
block|{
return|return
operator|(
name|nlm_pcicfg_baseaddr
operator|+
name|devoffset
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|uint64_t
name|nlm_pcibar0_base_xkphys
parameter_list|(
name|uint64_t
name|pcibase
parameter_list|)
block|{
name|uint64_t
name|paddr
decl_stmt|;
name|paddr
operator|=
name|nlm_read_reg_kseg
argument_list|(
name|pcibase
argument_list|,
name|XLP_PCI_CFGREG4
argument_list|)
operator|&
operator|~
literal|0xfu
expr_stmt|;
return|return
operator|(
literal|0x9000000000000000
operator||
name|paddr
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|nlm_pci_rdreg
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
name|nlm_pci_wreg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg_kseg(b, r, v)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE&& !__ASSEMBLY__*/
end_comment

begin_comment
comment|/* COMPAT stuff - TODO remove */
end_comment

begin_define
define|#
directive|define
name|bit_set
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
value|((p) |= (m))
end_define

begin_define
define|#
directive|define
name|bit_clear
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
value|((p)&= ~(m))
end_define

begin_define
define|#
directive|define
name|bit_get
parameter_list|(
name|p
parameter_list|,
name|m
parameter_list|)
value|((p)& (m))
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|x
parameter_list|)
value|(0x01<< (x))
end_define

begin_define
define|#
directive|define
name|XLP_MAX_NODES
value|4
end_define

begin_define
define|#
directive|define
name|XLP_MAX_CORES
value|8
end_define

begin_define
define|#
directive|define
name|XLP_MAX_THREADS
value|4
end_define

begin_define
define|#
directive|define
name|XLP_CACHELINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|XLP_NUM_NODES
value|1
end_define

begin_comment
comment|/* we support only one now */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

