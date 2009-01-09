begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 MARVELL INTERNATIONAL LTD.  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of MARVELL nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<arm/mv/mvreg.h>
end_include

begin_include
include|#
directive|include
file|<arm/mv/mvvar.h>
end_include

begin_comment
comment|/*  * Virtual address space layout:  * -----------------------------  * 0x0000_0000 - 0xbfff_ffff	: user process  *  * 0xc040_0000 - virtual_avail	: kernel reserved (text, data, page tables  *				: structures, ARM stacks etc.)  * virtual_avail - 0xefff_ffff	: KVA (virtual_avail is typically< 0xc0a0_0000)  * 0xf000_0000 - 0xf0ff_ffff	: no-cache allocation area (16MB)  * 0xf100_0000 - 0xf10f_ffff	: SoC integrated devices registers range (1MB)  * 0xf110_0000 - 0xf11f_ffff	: PCI-Express I/O space (1MB)  * 0xf120_0000 - 0xf12f_ffff	: PCI I/O space (1MB)  * 0xf130_0000 - 0xf52f_ffff	: PCI-Express memory space (64MB)  * 0xf530_0000 - 0xf92f_ffff	: PCI memory space (64MB)  * 0xf930_0000 - 0xfffe_ffff	: unused (~108MB)  * 0xffff_0000 - 0xffff_0fff	: 'high' vectors page (4KB)  * 0xffff_1000 - 0xffff_1fff	: ARM_TP_ADDRESS/RAS page (4KB)  * 0xffff_2000 - 0xffff_ffff	: unused (~55KB)  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|pmap_devmap
modifier|*
name|pmap_devmap_bootstrap_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vm_offset_t
name|pmap_bootstrap_lastaddr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|platform_pci_get_irq
parameter_list|(
name|u_int
name|bus
parameter_list|,
name|u_int
name|slot
parameter_list|,
name|u_int
name|func
parameter_list|,
name|u_int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Static device mappings. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|pmap_devmap
name|pmap_devmap
index|[]
init|=
block|{
comment|/* 	 * Map the on-board devices VA == PA so that we can access them 	 * with the MMU on or off. 	 */
block|{
comment|/* SoC integrated peripherals registers range */
name|MV_BASE
block|,
name|MV_PHYS_BASE
block|,
name|MV_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, 	}
block|,
block|{
comment|/* PCIE I/O */
name|MV_PCIE_IO_BASE
block|,
name|MV_PCIE_IO_PHYS_BASE
block|,
name|MV_PCIE_IO_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, 	}
block|,
block|{
comment|/* PCIE Memory */
name|MV_PCIE_MEM_BASE
block|,
name|MV_PCIE_MEM_PHYS_BASE
block|,
name|MV_PCIE_MEM_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, 	}
block|,
block|{
comment|/* PCI I/O */
name|MV_PCI_IO_BASE
block|,
name|MV_PCI_IO_PHYS_BASE
block|,
name|MV_PCI_IO_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, 	}
block|,
block|{
comment|/* PCI Memory */
name|MV_PCI_MEM_BASE
block|,
name|MV_PCI_MEM_PHYS_BASE
block|,
name|MV_PCI_MEM_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, 	}
block|,
block|{
comment|/* 7-seg LED */
name|MV_DEV_CS0_BASE
block|,
name|MV_DEV_CS0_PHYS_BASE
block|,
name|MV_DEV_CS0_SIZE
block|,
name|VM_PROT_READ
operator||
name|VM_PROT_WRITE
block|,
name|PTE_NOCACHE
block|, 	}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The pci_irq_map table consists of 3 columns:  * - PCI slot number (less than zero means ANY).  * - PCI IRQ pin (less than zero means ANY).  * - PCI IRQ (less than zero marks end of table).  *  * IRQ number from the first matching entry is used to configure PCI device  */
end_comment

begin_comment
comment|/* PCI IRQ Map for DB-88F5281 */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|obio_pci_irq_map
name|pci_irq_map
index|[]
init|=
block|{
block|{
literal|7
block|,
operator|-
literal|1
block|,
name|GPIO2IRQ
argument_list|(
literal|12
argument_list|)
block|}
block|,
block|{
literal|8
block|,
operator|-
literal|1
block|,
name|GPIO2IRQ
argument_list|(
literal|13
argument_list|)
block|}
block|,
block|{
literal|9
block|,
operator|-
literal|1
block|,
name|GPIO2IRQ
argument_list|(
literal|13
argument_list|)
block|}
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* PCI IRQ Map for DB-88F5182 */
end_comment

begin_endif
unit|const struct obio_pci_irq_map pci_irq_map[] = { 	{ 7, -1, GPIO2IRQ(0) }, 	{ 8, -1, GPIO2IRQ(1) }, 	{ 9, -1, GPIO2IRQ(1) }, 	{ -1, -1, -1 } };
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * mv_gpio_config row structure:  *<GPIO number>,<GPIO flags>,<GPIO mode>  *  * - GPIO pin number (less than zero marks end of table)  * - GPIO flags:  *	MV_GPIO_BLINK  *	MV_GPIO_POLAR_LOW  *	MV_GPIO_EDGE  *	MV_GPIO_LEVEL  * - GPIO mode:  *	1	- Output, set to HIGH.  *	0	- Output, set to LOW.  *	-1	- Input.  */
end_comment

begin_comment
comment|/* GPIO Configuration for DB-88F5281 */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|gpio_config
name|mv_gpio_config
index|[]
init|=
block|{
block|{
literal|12
block|,
name|MV_GPIO_POLAR_LOW
operator||
name|MV_GPIO_LEVEL
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|13
block|,
name|MV_GPIO_POLAR_LOW
operator||
name|MV_GPIO_LEVEL
block|,
operator|-
literal|1
block|}
block|,
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* GPIO Configuration for DB-88F5182 */
end_comment

begin_endif
unit|const struct gpio_config mv_gpio_config[] = { 	{ 0, MV_GPIO_POLAR_LOW | MV_GPIO_LEVEL, -1 }, 	{ 1, MV_GPIO_POLAR_LOW | MV_GPIO_LEVEL, -1 }, 	{ -1, -1, -1 } };
endif|#
directive|endif
end_endif

begin_function
name|int
name|platform_pmap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|pmap_bootstrap_lastaddr
operator|=
name|MV_BASE
operator|-
name|ARM_NOCACHE_KVA_SIZE
expr_stmt|;
name|pmap_devmap_bootstrap_table
operator|=
operator|&
name|pmap_devmap
index|[
literal|0
index|]
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|platform_mpp_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * MPP configuration for DB-88F5281 	 * 	 * MPP[2]:  PCI_REQn[3] 	 * MPP[3]:  PCI_GNTn[3] 	 * MPP[4]:  PCI_REQn[4] 	 * MPP[5]:  PCI_GNTn[4] 	 * MPP[6]:<UNKNOWN> 	 * MPP[7]:<UNKNOWN> 	 * MPP[8]:<UNKNOWN> 	 * MPP[9]:<UNKNOWN> 	 * MPP[14]: NAND Flash REn[2] 	 * MPP[15]: NAND Flash WEn[2] 	 * MPP[16]: UA1_RXD 	 * MPP[17]: UA1_TXD 	 * MPP[18]: UA1_CTS 	 * MPP[19]: UA1_RTS 	 * 	 * Others:  GPIO 	 * 	 *<UNKNOWN> entries are not documented, not on the schematics etc. 	 */
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL0
argument_list|,
literal|0x33222203
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL1
argument_list|,
literal|0x44000033
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL2
argument_list|,
literal|0x00000000
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* 	 * MPP configuration for DB-88F5182 	 * 	 * MPP[2]:  PCI_REQn[3] 	 * MPP[3]:  PCI_GNTn[3] 	 * MPP[4]:  PCI_REQn[4] 	 * MPP[5]:  PCI_GNTn[4] 	 * MPP[6]:  SATA0_ACT 	 * MPP[7]:  SATA1_ACT 	 * MPP[12]: SATA0_PRESENT 	 * MPP[13]: SATA1_PRESENT 	 * MPP[14]: NAND_FLASH_REn[2] 	 * MPP[15]: NAND_FLASH_WEn[2] 	 * MPP[16]: UA1_RXD 	 * MPP[17]: UA1_TXD 	 * MPP[18]: UA1_CTS 	 * MPP[19]: UA1_RTS 	 * 	 * Others:  GPIO 	 */
block|bus_space_write_4(obio_tag, MV_MPP_BASE, MPP_CONTROL0, 0x55222203); 	bus_space_write_4(obio_tag, MV_MPP_BASE, MPP_CONTROL1, 0x44550000); 	bus_space_write_4(obio_tag, MV_MPP_BASE, MPP_CONTROL2, 0x00000000);
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|void
name|platform_identify
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|soc_identify
argument_list|()
expr_stmt|;
comment|/* 	 * XXX Board identification e.g. read out from FPGA or similar should 	 * go here 	 */
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|platform_identify
argument_list|,
name|SI_SUB_CPU
argument_list|,
name|SI_ORDER_SECOND
argument_list|,
name|platform_identify
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

