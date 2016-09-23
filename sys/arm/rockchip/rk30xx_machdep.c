begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: FreeBSD: //depot/projects/arm/src/sys/arm/ti/ti_machdep.c  */
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
file|<vm/pmap.h>
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
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<arm/rockchip/rk30xx_wdog.h>
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
name|devmap_lastaddr
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
block|{  }
end_function

begin_function
name|void
name|platform_gpio_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|platform_late_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Enable cache */
name|cpufunc_control
argument_list|(
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
argument_list|,
name|CPU_CONTROL_DC_ENABLE
operator||
name|CPU_CONTROL_IC_ENABLE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Set up static device mappings.  */
end_comment

begin_function
name|int
name|platform_devmap_init
parameter_list|(
name|void
parameter_list|)
block|{
name|devmap_add_entry
argument_list|(
literal|0x10000000
argument_list|,
literal|0x00200000
argument_list|)
expr_stmt|;
name|devmap_add_entry
argument_list|(
literal|0x20000000
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
name|void
name|cpu_reset
parameter_list|()
block|{
name|rk30_wd_watchdog_reset
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"Reset failed!\n"
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

end_unit

