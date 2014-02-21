begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Damjan Marion.  * Copyright (c) 1994-1998 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: FreeBSD: //depot/projects/arm/src/sys/arm/mv/mv_machdep.c  */
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
file|<dev/fdt/fdt_common.h>
end_include

begin_define
define|#
directive|define
name|TEGRA2_CLK_RST_PA_BASE
value|0x60006000
end_define

begin_define
define|#
directive|define
name|TEGRA2_CLK_RST_OSC_FREQ_DET_REG
value|0x58
end_define

begin_define
define|#
directive|define
name|TEGRA2_CLK_RST_OSC_FREQ_DET_STAT_REG
value|0x5C
end_define

begin_define
define|#
directive|define
name|OSC_FREQ_DET_TRIG
value|(1U<<31)
end_define

begin_define
define|#
directive|define
name|OSC_FREQ_DET_BUSY
value|(1U<<31)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static int tegra2_osc_freq_detect(void) { 	bus_space_handle_t	bsh; 	uint32_t		c; 	uint32_t		r=0; 	int			i=0;  	struct { 		uint32_t val; 		uint32_t freq; 	} freq_det_cnts[] = { 		{ 732,  12000000 }, 		{ 794,  13000000 }, 		{1172,  19200000 }, 		{1587,  26000000 }, 		{  -1,         0 }, 	};  	printf("Measuring...\n"); 	bus_space_map(fdtbus_bs_tag,TEGRA2_CLK_RST_PA_BASE, 0x1000, 0,&bsh);  	bus_space_write_4(fdtbus_bs_tag, bsh, TEGRA2_CLK_RST_OSC_FREQ_DET_REG, 			OSC_FREQ_DET_TRIG | 1 ); 	do {} while (bus_space_read_4(fdtbus_bs_tag, bsh, 			TEGRA2_CLK_RST_OSC_FREQ_DET_STAT_REG)& OSC_FREQ_DET_BUSY);  	c = bus_space_read_4(fdtbus_bs_tag, bsh, TEGRA2_CLK_RST_OSC_FREQ_DET_STAT_REG);  	while (freq_det_cnts[i].val> 0) { 		if (((freq_det_cnts[i].val - 3)< c)&& (c< (freq_det_cnts[i].val + 3))) 			r = freq_det_cnts[i].freq; 		i++; 	} 	printf("c=%u r=%u\n",c,r ); 	bus_space_free(fdtbus_bs_tag, bsh, 0x1000); 	return r; }
endif|#
directive|endif
end_endif

begin_function
name|vm_offset_t
name|initarm_lastaddr
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
name|initarm_early_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|initarm_gpio_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|initarm_late_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * Add a static mapping for the register range that includes the debug uart.  * It's not clear this is needed, but the original code established this mapping  * before conversion to the newer arm_devmap_add_entry() routine.  */
end_comment

begin_function
name|int
name|initarm_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|arm_devmap_add_entry
argument_list|(
literal|0x70000000
argument_list|,
literal|0x00100000
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

end_unit

