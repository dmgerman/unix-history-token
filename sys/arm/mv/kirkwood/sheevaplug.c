begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 MARVELL INTERNATIONAL LTD.  * Copyright (C) 2009 Semihalf  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of MARVELL nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
comment|/*  * Virtual address space layout:  * -----------------------------  * 0x0000_0000 - 0x7FFF_FFFF	: User Process (2 GB)  * 0x8000_0000 - 0xBBFF_FFFF	: Unused (960 MB)  * 0xBC00_0000 - 0xBDFF_FFFF	: Device Bus: CS1 (32 MB)  * 0xBE00_0000 - 0xBECF_FFFF	: Unused (13 MB)  * 0xBED0_0000 - 0xBEDF_FFFF	: Device Bus: CS2 (1 MB)  * 0xBEE0_0000 - 0xBEEF_FFFF	: Device Bus: CS0 (1 MB)  * 0xBEF0_0000 - 0xBEFF_FFFF	: Device Bus: BOOT (1 MB)  * 0xBF00_0000 - 0xBFFF_FFFF	: Unused (16 MB)  * 0xC000_0000 - virtual_avail	: Kernel Reserved (text, data, page tables,  * 				: stack etc.)  * virtual-avail - 0xEFFF_FFFF	: KVA (virtual_avail is typically< 0xc0a0_0000)  * 0xF000_0000 - 0xF0FF_FFFF	: No-Cache allocation area (16 MB)  * 0xF100_0000 - 0xF10F_FFFF	: SoC Integrated devices registers range (1 MB)  * 0xF110_0000 - 0xF11F_FFFF	: CESA SRAM (1 MB)  * 0xF120_0000 - 0xFFFE_FFFF	: Unused (237 MB + 960 kB)  * 0xFFFF_0000 - 0xFFFF_0FFF	: 'High' vectors page (4 kB)  * 0xFFFF_1000 - 0xFFFF_1FFF	: ARM_TP_ADDRESS/RAS page (4 kB)  * 0xFFFF_2000 - 0xFFFF_FFFF	: Unused (56 kB)  */
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
comment|/* CESA SRAM */
name|MV_CESA_SRAM_BASE
block|,
name|MV_CESA_SRAM_PHYS_BASE
block|,
name|MV_CESA_SRAM_SIZE
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
comment|/* 	 * MPP configuration for Sheeva Plug 	 * 	 * MPP[0]:  NF_IO[2] 	 * MPP[1]:  NF_IO[3] 	 * MPP[2]:  NF_IO[4] 	 * MPP[3]:  NF_IO[5] 	 * MPP[4]:  NF_IO[6] 	 * MPP[5]:  NF_IO[7] 	 * MPP[6]:  SYSRST_OUTn 	 * MPP[8]:  UA0_RTS 	 * MPP[9]:  UA0_CTS 	 * MPP[10]: UA0_TXD 	 * MPP[11]: UA0_RXD 	 * MPP[12]: SD_CLK 	 * MPP[13]: SD_CMD 	 * MPP[14]: SD_D[0] 	 * MPP[15]: SD_D[1] 	 * MPP[16]: SD_D[2] 	 * MPP[17]: SD_D[3] 	 * MPP[18]: NF_IO[0] 	 * MPP[19]: NF_IO[1] 	 * MPP[29]: TSMP[9] 	 * 	 * Others:  GPIO 	 */
name|bus_space_write_4
argument_list|(
name|obio_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|MPP_CONTROL0
argument_list|,
literal|0x01111111
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
literal|0x11113322
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
literal|0x00001111
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
literal|0x00100000
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
literal|0x00000000
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

