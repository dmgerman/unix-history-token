begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 2001 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  */
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/smbus/smbconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/smbus/smbus.h>
end_include

begin_comment
comment|/*  * Autoconfiguration and support routines for the Philips serial I2C bus  */
end_comment

begin_define
define|#
directive|define
name|DEVTOSMBUS
parameter_list|(
name|dev
parameter_list|)
value|((struct smbus_device*)device_get_ivars(dev))
end_define

begin_decl_stmt
specifier|static
name|devclass_t
name|smbus_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Device methods  */
end_comment

begin_function_decl
specifier|static
name|int
name|smbus_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|smbus_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|smbus_methods
index|[]
init|=
block|{
comment|/* device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|smbus_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|smbus_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|bus_generic_detach
argument_list|)
block|,
comment|/* bus interface */
name|DEVMETHOD
argument_list|(
name|bus_print_child
argument_list|,
name|bus_generic_print_child
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
name|smbus_driver
init|=
block|{
literal|"smbus"
block|,
name|smbus_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbus_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * At 'probe' time, we add all the devices which we know about to the  * bus.  The generic attach routine will probe and attach them if they  * are alive.  */
end_comment

begin_function
specifier|static
name|int
name|smbus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"System Management Bus"
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
name|int
name|smbus_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_add_child
argument_list|(
name|dev
argument_list|,
name|NULL
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|bus_generic_attach
argument_list|(
name|dev
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
name|smbus_generic_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
name|devaddr
parameter_list|,
name|char
name|low
parameter_list|,
name|char
name|high
parameter_list|)
block|{
return|return;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|smbus
argument_list|,
name|iicsmb
argument_list|,
name|smbus_driver
argument_list|,
name|smbus_devclass
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
name|smbus
argument_list|,
name|bktr
argument_list|,
name|smbus_driver
argument_list|,
name|smbus_devclass
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
name|smbus
argument_list|,
name|intsmb
argument_list|,
name|smbus_driver
argument_list|,
name|smbus_devclass
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
name|smbus
argument_list|,
name|alpm
argument_list|,
name|smbus_driver
argument_list|,
name|smbus_devclass
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
name|smbus
argument_list|,
name|ichsmb
argument_list|,
name|smbus_driver
argument_list|,
name|smbus_devclass
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
name|smbus
argument_list|,
name|amdpm
argument_list|,
name|smbus_driver
argument_list|,
name|smbus_devclass
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
name|smbus
argument_list|,
name|viapropm
argument_list|,
name|smbus_driver
argument_list|,
name|smbus_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|smbus
argument_list|,
name|SMBUS_MODVER
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

