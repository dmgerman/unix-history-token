begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * $Id$  */
end_comment

begin_comment
comment|/*  * Skeleton of this file was based on respective code for ARM  * code written by Olivier Houchard.  */
end_comment

begin_include
include|#
directive|include
file|"opt_uart.h"
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
file|<mips/alchemy/aureg.h>
end_include

begin_include
include|#
directive|include
file|"uart_if.h"
end_include

begin_function_decl
specifier|static
name|int
name|uart_alchemy_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|uart_alchemy_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|uart_alchemy_probe
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
name|uart_alchemy_driver
init|=
block|{
name|uart_driver_name
block|,
name|uart_alchemy_methods
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
name|uart_alchemy_probe
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
return|return
operator|(
name|uart_bus_probe
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|0
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
name|obio
argument_list|,
name|uart_alchemy_driver
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

