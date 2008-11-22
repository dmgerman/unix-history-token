begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kevin Lo.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<dev/ic/ns16550.h>
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
file|<arm/xscale/ixp425/ixp425reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425var.h>
end_include

begin_include
include|#
directive|include
file|"uart_if.h"
end_include

begin_function_decl
specifier|static
name|int
name|uart_ixp425_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|uart_ixp425_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|uart_ixp425_probe
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
name|uart_ixp425_driver
init|=
block|{
name|uart_driver_name
block|,
name|uart_ixp425_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|uart_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern SLIST_HEAD(uart_devinfo_list
operator|,
extern|uart_devinfo
end_extern

begin_expr_stmt
unit|)
name|uart_sysdevs
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|uart_ixp425_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|uart_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_sysdev
operator|=
name|SLIST_FIRST
argument_list|(
operator|&
name|uart_sysdevs
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_class
operator|=
operator|&
name|uart_ns8250_class
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|sc
operator|->
name|sc_sysdev
operator|->
name|bas
argument_list|,
operator|&
name|sc
operator|->
name|sc_bas
argument_list|,
sizeof|sizeof
argument_list|(
name|sc
operator|->
name|sc_bas
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * XXX set UART Unit Enable (0x40) AND 	 *     receiver timeout int enable (0x10). 	 * The first turns on the UART.  The second is necessary to get 	 * interrupts when the FIFO has data but is not full.  Note that 	 * uart_ns8250 carefully avoids touching these bits so we can 	 * just set them here and proceed.  But this is fragile... 	 */
name|bus_space_write_4
argument_list|(
operator|&
name|ixp425_a4x_bs_tag
argument_list|,
name|device_get_unit
argument_list|(
name|dev
argument_list|)
operator|==
literal|0
condition|?
name|IXP425_UART0_VBASE
else|:
name|IXP425_UART1_VBASE
argument_list|,
name|IXP425_UART_IER
argument_list|,
name|IXP425_UART_IER_UUE
operator||
name|IXP425_UART_IER_RTOIE
argument_list|)
expr_stmt|;
return|return
operator|(
name|uart_bus_probe
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
name|IXP425_UART_FREQ
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
name|ixp
argument_list|,
name|uart_ixp425_driver
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

