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

begin_include
include|#
directive|include
file|<arm/mv/mvwin.h>
end_include

begin_comment
comment|/*  * Virtual address space layout:  * -----------------------------  * 0x0000_0000 - 0xbfff_ffff	: user process  *  * 0xc040_0000 - virtual_avail	: kernel reserved (text, data, page tables  *				: structures, ARM stacks etc.)  * virtual_avail - 0xefff_ffff	: KVA (virtual_avail is typically< 0xc0a0_0000)  * 0xf000_0000 - 0xf0ff_ffff	: no-cache allocation area (16MB)  * 0xf100_0000 - 0xf10f_ffff	: SoC integrated devices registers range (1MB)  * 0xf110_0000 - 0xf11f_ffff	: PCI-Express I/O space (1MB)  * 0xf120_0000 - 0xf12f_ffff	: unused (1MB)  * 0xf130_0000 - 0xf52f_ffff	: PCI-Express memory space (64MB)  * 0xf930_0000 - 0xfffe_ffff	: unused (~172MB)  * 0xffff_0000 - 0xffff_0fff	: 'high' vectors page (4KB)  * 0xffff_1000 - 0xffff_1fff	: ARM_TP_ADDRESS/RAS page (4KB)  * 0xffff_2000 - 0xffff_ffff	: unused (~55KB)  */
end_comment

begin_comment
comment|/* Static device mappings. */
end_comment

begin_decl_stmt
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

begin_decl_stmt
specifier|const
name|struct
name|gpio_config
name|mv_gpio_config
index|[]
init|=
block|{
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

begin_function
name|void
name|platform_mpp_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * MPP Configuration for DB-78100-BP 	 * 	 * MPP[0]:  GE1_TXCLK 	 * MPP[1]:  GE1_TXCTL 	 * MPP[2]:  GE1_RXCTL 	 * MPP[3]:  GE1_RXCLK 	 * MPP[4]:  GE1_TXD[0] 	 * MPP[5]:  GE1_TXD[1] 	 * MPP[6]:  GE1_TXD[2] 	 * MPP[7]:  GE1_TXD[3] 	 * MPP[8]:  GE1_RXD[0] 	 * MPP[9]:  GE1_RXD[1] 	 * MPP[10]: GE1_RXD[2] 	 * MPP[11]: GE1_RXD[3] 	 * MPP[13]: SYSRST_OUTn 	 * MPP[14]: SATA1_ACT 	 * MPP[15]: SATA0_ACT 	 * MPP[16]: UA2_TXD 	 * MPP[17]: UA2_RXD 	 * MPP[18]:<UNKNOWN> 	 * MPP[19]:<UNKNOWN> 	 * MPP[20]:<UNKNOWN> 	 * MPP[21]:<UNKNOWN> 	 * MPP[22]: UA3_TXD 	 * MPP[23]: UA3_RXD 	 * MPP[48]:<UNKNOWN> 	 * MPP[49]:<UNKNOWN> 	 * 	 * Others:  GPIO 	 * 	 *<UNKNOWN> entries are not documented, not on the schematics etc. 	 */
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL0
argument_list|,
literal|0x22222222
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
literal|0x33302222
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
literal|0x44333344
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL3
argument_list|,
literal|0x00000000
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL4
argument_list|,
literal|0x00000000
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL5
argument_list|,
literal|0x00000000
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL6
argument_list|,
literal|0x0000FFFF
argument_list|)
expr_stmt|;
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

