begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Benno Rice.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/uart/uart.h>
end_include

begin_include
include|#
directive|include
file|<dev/uart/uart_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/uart/uart_cpu.h>
end_include

begin_include
include|#
directive|include
file|<dev/ic/ns16550.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/pxa/pxavar.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/pxa/pxareg.h>
end_include

begin_include
include|#
directive|include
file|"uart_if.h"
end_include

begin_define
define|#
directive|define
name|PXA_UART_UUE
value|0x40
end_define

begin_comment
comment|/* UART Unit Enable */
end_comment

begin_function_decl
specifier|static
name|int
name|uart_pxa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|uart_pxa_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|uart_pxa_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|uart_bus_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|uart_bus_detach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|uart_pxa_driver
init|=
block|{
name|uart_driver_name
block|,
name|uart_pxa_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|uart_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|uart_pxa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|bus_space_handle_t
name|base
decl_stmt|;
name|struct
name|uart_softc
modifier|*
name|sc
decl_stmt|;
name|base
operator|=
operator|(
name|bus_space_handle_t
operator|)
name|pxa_get_base
argument_list|(
name|dev
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QEMU_WORKAROUNDS
comment|/* 	 * QEMU really exposes only the first uart unless 	 * you specify several of them in the configuration. 	 * Otherwise all the rest of UARTs stay unconnected, 	 * which causes problems in the ns16550 attach routine. 	 * Unfortunately, even if you provide qemu with 4 uarts 	 * on the command line, it has a bug where it segfaults 	 * trying to enable bluetooth on the HWUART.  So we just 	 * allow the FFUART to be attached. 	 * Also, don't check the UUE (UART Unit Enable) bit, as 	 * the gumstix bootloader doesn't set it. 	 */
if|if
condition|(
name|base
operator|!=
name|PXA2X0_FFUART_BASE
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
else|#
directive|else
comment|/* Check to see if the enable bit's on. */
if|if
condition|(
operator|(
name|bus_space_read_4
argument_list|(
name|obio_tag
argument_list|,
name|base
argument_list|,
operator|(
name|REG_IER
operator|<<
literal|2
operator|)
argument_list|)
operator|&
name|PXA_UART_UUE
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
endif|#
directive|endif
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_class
operator|=
operator|&
name|uart_ns8250_class
expr_stmt|;
return|return
operator|(
name|uart_bus_probe
argument_list|(
name|dev
argument_list|,
literal|2
argument_list|,
name|PXA2X0_COM_FREQ
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|uart
argument_list|,
name|pxa
argument_list|,
name|uart_pxa_driver
argument_list|,
name|uart_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

