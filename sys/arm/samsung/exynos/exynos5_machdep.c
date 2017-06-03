begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<machine/armreg.h>
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
file|<machine/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<arm/samsung/exynos/exynos5_mp.h>
end_include

begin_include
include|#
directive|include
file|"platform_if.h"
end_include

begin_decl_stmt
specifier|static
name|platform_devmap_init_t
name|exynos5_devmap_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|platform_cpu_reset_t
name|exynos5_cpu_reset
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|exynos5_devmap_init
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
comment|/* CHIP ID */
name|devmap_add_entry
argument_list|(
literal|0x10000000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* UART */
name|devmap_add_entry
argument_list|(
literal|0x12C00000
argument_list|,
literal|0x100000
argument_list|)
expr_stmt|;
comment|/* DWMMC */
name|devmap_add_entry
argument_list|(
literal|0x12200000
argument_list|,
literal|0x100000
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
specifier|static
name|void
name|exynos5_cpu_reset
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_space_map
argument_list|(
name|fdtbus_bs_tag
argument_list|,
literal|0x10040400
argument_list|,
literal|0x1000
argument_list|,
literal|0
argument_list|,
operator|&
name|bsh
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|fdtbus_bs_tag
argument_list|,
name|bsh
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
name|platform_method_t
name|exynos5_methods
index|[]
init|=
block|{
name|PLATFORMMETHOD
argument_list|(
name|platform_devmap_init
argument_list|,
name|exynos5_devmap_init
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_cpu_reset
argument_list|,
name|exynos5_cpu_reset
argument_list|)
block|,
ifdef|#
directive|ifdef
name|SMP
name|PLATFORMMETHOD
argument_list|(
name|platform_mp_start_ap
argument_list|,
name|exynos5_mp_start_ap
argument_list|)
block|,
name|PLATFORMMETHOD
argument_list|(
name|platform_mp_setmaxid
argument_list|,
name|exynos5_mp_setmaxid
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
name|exynos5
argument_list|,
literal|"exynos5"
argument_list|,
literal|0
argument_list|,
literal|"samsung,exynos5"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

