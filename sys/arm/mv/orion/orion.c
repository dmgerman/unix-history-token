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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
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

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern const struct obio_pci_irq_map pci_irq_map[]; const struct obio_pci mv_pci_info[] = { 	{ MV_TYPE_PCIE, 		MV_PCIE_BASE,	MV_PCIE_SIZE, 		MV_PCIE_IO_BASE, MV_PCIE_IO_SIZE,	4, 0x51, 		MV_PCIE_MEM_BASE, MV_PCIE_MEM_SIZE,	4, 0x59, 		NULL, MV_INT_PEX0 	},  	{ MV_TYPE_PCI, 		MV_PCI_BASE, MV_PCI_SIZE, 		MV_PCI_IO_BASE, MV_PCI_IO_SIZE,		3, 0x51, 		MV_PCI_MEM_BASE, MV_PCI_MEM_SIZE,	3, 0x59, 		pci_irq_map, -1 	},  	{ 0, 0, 0 } };
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|resource_spec
name|mv_gpio_res
index|[]
init|=
block|{
block|{
name|SYS_RES_MEMORY
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|1
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|2
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|3
block|,
name|RF_ACTIVE
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|decode_win
name|idma_win_tbl
index|[]
init|=
block|{
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|decode_win
modifier|*
name|idma_wins
init|=
name|idma_win_tbl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|idma_wins_no
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|uint32_t
name|get_tclk
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|sar
decl_stmt|;
comment|/* 	 * On Orion TCLK is can be configured to 150 MHz or 166 MHz. 	 * Current setting is read from Sample At Reset register. 	 */
comment|/* XXX MPP addr should be retrieved from the DT */
name|sar
operator|=
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|MV_MPP_BASE
argument_list|,
name|SAMPLE_AT_RESET
argument_list|)
expr_stmt|;
name|sar
operator|=
operator|(
name|sar
operator|&
name|TCLK_MASK
operator|)
operator|>>
name|TCLK_SHIFT
expr_stmt|;
switch|switch
condition|(
name|sar
condition|)
block|{
case|case
literal|1
case|:
return|return
operator|(
name|TCLK_150MHZ
operator|)
return|;
case|case
literal|2
case|:
return|return
operator|(
name|TCLK_166MHZ
operator|)
return|;
default|default:
name|panic
argument_list|(
literal|"Unknown TCLK settings!"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|uint32_t
name|get_cpu_freq
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

