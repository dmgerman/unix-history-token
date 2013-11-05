begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/reboot.h>
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
file|<arm/freescale/imx/imx_machdep.h>
end_include

begin_include
include|#
directive|include
file|<arm/freescale/imx/imx_wdogreg.h>
end_include

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

begin_comment
comment|/*  * This code which manipulates the watchdog hardware is here to implement  * cpu_reset() because the watchdog is the only way for software to reset the  * chip.  Why here and not in imx_wdog.c?  Because there's no requirement that  * the watchdog driver be compiled in, but it's nice to be able to reboot even  * if it's not.  */
end_comment

begin_function
name|void
name|imx_wdog_cpu_reset
parameter_list|(
name|vm_offset_t
name|wdcr_physaddr
parameter_list|)
block|{
specifier|volatile
name|uint16_t
modifier|*
name|pcr
decl_stmt|;
comment|/* 	 * The deceptively simple write of WDOG_CR_WDE enables the watchdog, 	 * sets the timeout to its minimum value (half a second), and also 	 * clears the SRS bit which results in the SFTW (software-requested 	 * reset) bit being set in the watchdog status register after the reset. 	 * This is how software can distinguish a reset from a wdog timeout. 	 */
if|if
condition|(
operator|(
name|pcr
operator|=
name|arm_devmap_ptov
argument_list|(
name|wdcr_physaddr
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|pcr
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"cpu_reset() can't find its control register... locking up now."
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|pcr
operator|=
name|WDOG_CR_WDE
expr_stmt|;
block|}
for|for
control|(
init|;
condition|;
control|)
continue|continue;
block|}
end_function

begin_function
name|u_int
name|imx_soc_family
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|imx_soc_type
argument_list|()
operator|>>
name|IMXSOC_FAMSHIFT
operator|)
return|;
block|}
end_function

end_unit

