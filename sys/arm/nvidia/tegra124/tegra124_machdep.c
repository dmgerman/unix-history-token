begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

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
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/devmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
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
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<arm/nvidia/tegra124/tegra124_mp.h>
end_include

begin_include
include|#
directive|include
file|"platform_if.h"
end_include

begin_define
define|#
directive|define
name|PMC_PHYSBASE
value|0x7000e400
end_define

begin_define
define|#
directive|define
name|PMC_SIZE
value|0x400
end_define

begin_define
define|#
directive|define
name|PMC_CONTROL_REG
value|0x0
end_define

begin_define
define|#
directive|define
name|PMC_SCRATCH0
value|0x50
end_define

begin_define
define|#
directive|define
name|PMC_SCRATCH0_MODE_RECOVERY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|PMC_SCRATCH0_MODE_BOOTLOADER
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PMC_SCRATCH0_MODE_RCM
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PMC_SCRATCH0_MODE_MASK
value|(PMC_SCRATCH0_MODE_RECOVERY | \ 					PMC_SCRATCH0_MODE_BOOTLOADER | \ 					PMC_SCRATCH0_MODE_RCM)
end_define

begin_function
specifier|static
name|vm_offset_t
name|tegra124_lastaddr
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
return|return
operator|(
name|devmap_lastaddr
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|tegra124_attach
parameter_list|(
name|platform_t
name|plat
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
specifier|static
name|void
name|tegra124_late_init
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{  }
end_function

begin_comment
comment|/*  * Set up static device mappings.  *  */
end_comment

begin_function
specifier|static
name|int
name|tegra124_devmap_init
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|devmap_add_entry
argument_list|(
literal|0x70000000
argument_list|,
literal|0x01000000
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
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
block|{
name|bus_space_handle_t
name|pmc
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
name|printf
argument_list|(
literal|"Resetting...\n"
argument_list|)
expr_stmt|;
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|PMC_PHYSBASE
argument_list|,
name|PMC_SIZE
argument_list|,
literal|0
argument_list|,
operator|&
name|pmc
argument_list|)
expr_stmt|;
name|reg
operator|=
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|pmc
argument_list|,
name|PMC_SCRATCH0
argument_list|)
expr_stmt|;
name|reg
operator|&=
name|PMC_SCRATCH0_MODE_MASK
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|pmc
argument_list|,
name|PMC_SCRATCH0
argument_list|,
name|reg
operator||
name|PMC_SCRATCH0_MODE_BOOTLOADER
argument_list|)
expr_stmt|;
comment|/* boot to bootloader */
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|pmc
argument_list|,
name|PMC_SCRATCH0
argument_list|)
expr_stmt|;
name|reg
operator|=
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|pmc
argument_list|,
name|PMC_CONTROL_REG
argument_list|)
expr_stmt|;
name|spinlock_enter
argument_list|()
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|pmc
argument_list|,
name|PMC_CONTROL_REG
argument_list|,
name|reg
operator||
literal|0x10
argument_list|)
expr_stmt|;
name|bus_space_read_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|pmc
argument_list|,
name|PMC_CONTROL_REG
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_comment
comment|/*  * Early putc routine for EARLY_PRINTF support.  To use, add to kernel config:  *   option SOCDEV_PA=0x70000000  *   option SOCDEV_VA=0x70000000  *   option EARLY_PRINTF  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EARLY_PRINTF
end_ifdef

begin_function
specifier|static
name|void
name|tegra124_early_putc
parameter_list|(
name|int
name|c
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|UART_STAT_REG
init|=
operator|(
name|uint32_t
operator|*
operator|)
operator|(
literal|0x70006314
operator|)
decl_stmt|;
specifier|volatile
name|uint32_t
modifier|*
name|UART_TX_REG
init|=
operator|(
name|uint32_t
operator|*
operator|)
operator|(
literal|0x70006300
operator|)
decl_stmt|;
specifier|const
name|uint32_t
name|UART_TXRDY
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
decl_stmt|;
while|while
condition|(
operator|(
operator|*
name|UART_STAT_REG
operator|&
name|UART_TXRDY
operator|)
operator|==
literal|0
condition|)
continue|continue;
operator|*
name|UART_TX_REG
operator|=
name|c
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|early_putc_t
modifier|*
name|early_putc
init|=
name|tegra124_early_putc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|platform_method_t
name|tegra124_methods
index|[]
init|=
block|{
name|PLATFORMMETHOD
argument_list|(
name|platform_attach
argument_list|,
name|tegra124_attach
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_lastaddr
argument_list|,
name|tegra124_lastaddr
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_devmap_init
argument_list|,
name|tegra124_devmap_init
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_late_init
argument_list|,
name|tegra124_late_init
argument_list|)
block|,
ifdef|#
directive|ifdef
name|SMP
name|PLATFORMMETHOD
argument_list|(
name|platform_mp_start_ap
argument_list|,
name|tegra124_mp_start_ap
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_mp_setmaxid
argument_list|,
name|tegra124_mp_setmaxid
argument_list|)
block|,
endif|#
directive|endif
name|PLATFORMMETHOD_END
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FDT_PLATFORM_DEF
argument_list|(
name|tegra124
argument_list|,
literal|"Nvidia Jetson-TK1"
argument_list|,
literal|0
argument_list|,
literal|"nvidia,jetson-tk1"
argument_list|,
literal|120
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

