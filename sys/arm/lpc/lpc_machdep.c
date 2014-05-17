begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1998 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: FreeBSD: //depot/projects/arm/src/sys/arm/at91/kb920x_machdep.c, rev 45  */
end_comment

begin_include
include|#
directive|include
file|"opt_ddb.h"
end_include

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

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

begin_define
define|#
directive|define
name|_ARM32_BUS_DMA_PRIVATE
end_define

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
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<machine/devmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/platform.h>
end_include

begin_include
include|#
directive|include
file|<arm/lpc/lpcreg.h>
end_include

begin_include
include|#
directive|include
file|<arm/lpc/lpcvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_function
name|vm_offset_t
name|platform_lastaddr
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|arm_devmap_lastaddr
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
name|void
name|platform_probe_and_attach
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|platform_gpio_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * Set initial values of GPIO output ports 	 */
name|lpc_gpio_init
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|platform_late_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * Add a single static device mapping.  * The values used were taken from the ranges property of the SoC node in the  * dts file when this code was converted to arm_devmap_add_entry().  */
end_comment

begin_function
name|int
name|platform_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|arm_devmap_add_entry
argument_list|(
name|LPC_DEV_PHYS_BASE
argument_list|,
name|LPC_DEV_SIZE
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|arm32_dma_range
modifier|*
name|bus_dma_get_range
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
name|int
name|bus_dma_get_range_nb
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

begin_function
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
block|{
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bst
operator|=
name|fdtbus_bs_tag
expr_stmt|;
comment|/* Enable WDT */
name|bus_space_map
argument_list|(
name|bst
argument_list|,
name|LPC_CLKPWR_PHYS_BASE
argument_list|,
name|LPC_CLKPWR_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|bsh
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|bst
argument_list|,
name|bsh
argument_list|,
name|LPC_CLKPWR_TIMCLK_CTRL
argument_list|,
name|LPC_CLKPWR_TIMCLK_CTRL_WATCHDOG
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|bst
argument_list|,
name|bsh
argument_list|,
name|LPC_CLKPWR_SIZE
argument_list|)
expr_stmt|;
comment|/* Instant assert of RESETOUT_N with pulse length 1ms */
name|bus_space_map
argument_list|(
name|bst
argument_list|,
name|LPC_WDTIM_PHYS_BASE
argument_list|,
name|LPC_WDTIM_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|bsh
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|bst
argument_list|,
name|bsh
argument_list|,
name|LPC_WDTIM_PULSE
argument_list|,
literal|13000
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|bst
argument_list|,
name|bsh
argument_list|,
name|LPC_WDTIM_MCTRL
argument_list|,
literal|0x70
argument_list|)
expr_stmt|;
name|bus_space_unmap
argument_list|(
name|bst
argument_list|,
name|bsh
argument_list|,
name|LPC_WDTIM_SIZE
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
continue|continue;
block|}
end_function

end_unit

