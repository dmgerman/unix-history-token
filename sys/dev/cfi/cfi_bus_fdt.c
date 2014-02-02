begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007, Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<dev/cfi/cfi_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_function_decl
specifier|static
name|int
name|cfi_fdt_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|cfi_fdt_methods
index|[]
init|=
block|{
comment|/* device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|cfi_fdt_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|cfi_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|cfi_detach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|cfi_fdt_driver
init|=
block|{
name|cfi_driver_name
block|,
name|cfi_fdt_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|cfi_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|cfi
argument_list|,
name|lbc
argument_list|,
name|cfi_fdt_driver
argument_list|,
name|cfi_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|cfi
argument_list|,
name|simplebus
argument_list|,
name|cfi_fdt_driver
argument_list|,
name|cfi_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|cfi_fdt_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_status_okay
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"cfi-flash"
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
return|return
operator|(
name|cfi_probe
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

