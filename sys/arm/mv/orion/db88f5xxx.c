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
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
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

begin_include
include|#
directive|include
file|<arm/mv/mvwin.h>
end_include

begin_comment
comment|/*  * Virtual address space layout:  * -----------------------------  * 0x0000_0000 - 0xbfff_ffff	: user process  *  * 0xc040_0000 - virtual_avail	: kernel reserved (text, data, page tables  *				: structures, ARM stacks etc.)  * virtual_avail - 0xefff_ffff	: KVA (virtual_avail is typically< 0xc0a0_0000)  * 0xf000_0000 - 0xf0ff_ffff	: no-cache allocation area (16MB)  * 0xf100_0000 - 0xf10f_ffff	: SoC integrated devices registers range (1MB)  * 0xf110_0000 - 0xf11f_ffff	: PCI-Express I/O space (1MB)  * 0xf120_0000 - 0xf12f_ffff	: PCI I/O space (1MB)  * 0xf130_0000 - 0xf52f_ffff	: PCI-Express memory space (64MB)  * 0xf530_0000 - 0xf92f_ffff	: PCI memory space (64MB)  * 0xf930_0000 - 0xfffe_ffff	: unused (~108MB)  * 0xffff_0000 - 0xffff_0fff	: 'high' vectors page (4KB)  * 0xffff_1000 - 0xffff_1fff	: ARM_TP_ADDRESS/RAS page (4KB)  * 0xffff_2000 - 0xffff_ffff	: unused (~55KB)  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|int platform_pci_get_irq(u_int bus, u_int slot, u_int func, u_int pin);
comment|/* Static device mappings. */
end_comment

begin_comment
unit|const struct pmap_devmap pmap_devmap[] = {
comment|/* 	 * Map the on-board devices VA == PA so that we can access them 	 * with the MMU on or off. 	 */
end_comment

begin_comment
unit|{
comment|/* SoC integrated peripherals registers range */
end_comment

begin_comment
unit|MV_BASE, 		MV_PHYS_BASE, 		MV_SIZE, 		VM_PROT_READ | VM_PROT_WRITE, 		PTE_DEVICE, 	}, 	{
comment|/* PCIE I/O */
end_comment

begin_comment
unit|MV_PCIE_IO_BASE, 		MV_PCIE_IO_PHYS_BASE, 		MV_PCIE_IO_SIZE, 		VM_PROT_READ | VM_PROT_WRITE, 		PTE_DEVICE, 	}, 	{
comment|/* PCIE Memory */
end_comment

begin_comment
unit|MV_PCIE_MEM_BASE, 		MV_PCIE_MEM_PHYS_BASE, 		MV_PCIE_MEM_SIZE, 		VM_PROT_READ | VM_PROT_WRITE, 		PTE_DEVICE, 	}, 	{
comment|/* PCI I/O */
end_comment

begin_comment
unit|MV_PCI_IO_BASE, 		MV_PCI_IO_PHYS_BASE, 		MV_PCI_IO_SIZE, 		VM_PROT_READ | VM_PROT_WRITE, 		PTE_DEVICE, 	}, 	{
comment|/* PCI Memory */
end_comment

begin_comment
unit|MV_PCI_MEM_BASE, 		MV_PCI_MEM_PHYS_BASE, 		MV_PCI_MEM_SIZE, 		VM_PROT_READ | VM_PROT_WRITE, 		PTE_DEVICE, 	}, 	{
comment|/* 7-seg LED */
end_comment

begin_comment
unit|MV_DEV_CS0_BASE, 		MV_DEV_CS0_PHYS_BASE, 		MV_DEV_CS0_SIZE, 		VM_PROT_READ | VM_PROT_WRITE, 		PTE_DEVICE, 	}, 	{ 0, 0, 0, 0, 0, } };
comment|/*  * The pci_irq_map table consists of 3 columns:  * - PCI slot number (less than zero means ANY).  * - PCI IRQ pin (less than zero means ANY).  * - PCI IRQ (less than zero marks end of table).  *  * IRQ number from the first matching entry is used to configure PCI device  */
end_comment

begin_comment
comment|/* PCI IRQ Map for DB-88F5281 */
end_comment

begin_comment
unit|const struct obio_pci_irq_map pci_irq_map[] = { 	{ 7, -1, GPIO2IRQ(12) }, 	{ 8, -1, GPIO2IRQ(13) }, 	{ 9, -1, GPIO2IRQ(13) }, 	{ -1, -1, -1 } };
comment|/* PCI IRQ Map for DB-88F5182 */
end_comment

begin_endif
unit|const struct obio_pci_irq_map pci_irq_map[] = { 	{ 7, -1, GPIO2IRQ(0) }, 	{ 8, -1, GPIO2IRQ(1) }, 	{ 9, -1, GPIO2IRQ(1) }, 	{ -1, -1, -1 } };
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * mv_gpio_config row structure:  *<GPIO number>,<GPIO flags>,<GPIO mode>  *  * - GPIO pin number (less than zero marks end of table)  * - GPIO flags:  *	MV_GPIO_BLINK  *	MV_GPIO_POLAR_LOW  *	MV_GPIO_EDGE  *	MV_GPIO_LEVEL  * - GPIO mode:  *	1	- Output, set to HIGH.  *	0	- Output, set to LOW.  *	-1	- Input.  */
end_comment

begin_comment
comment|/* GPIO Configuration for DB-88F5281 */
end_comment

begin_if
unit|const struct gpio_config mv_gpio_config[] = { 	{ 12, MV_GPIO_POLAR_LOW | MV_GPIO_LEVEL, -1 }, 	{ 13, MV_GPIO_POLAR_LOW | MV_GPIO_LEVEL, -1 }, 	{ -1, -1, -1 } };
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

