begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 2001 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Autoconfiguration and support routines for the Philips serial I2C bus  */
end_comment

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
file|<dev/iicbus/iiconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iicbus.h>
end_include

begin_include
include|#
directive|include
file|"iicbus_if.h"
end_include

begin_define
define|#
directive|define
name|DEVTOIICBUS
parameter_list|(
name|dev
parameter_list|)
value|((struct iicbus_device*)device_get_ivars(dev))
end_define

begin_decl_stmt
specifier|static
name|devclass_t
name|iicbus_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Device methods  */
end_comment

begin_function_decl
specifier|static
name|int
name|iicbus_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|iicbus_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|iicbus_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|iicbus_add_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|order
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|iicbus_methods
index|[]
init|=
block|{
comment|/* device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|iicbus_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|iicbus_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|iicbus_detach
argument_list|)
block|,
comment|/* bus interface */
name|DEVMETHOD
argument_list|(
name|bus_add_child
argument_list|,
name|iicbus_add_child
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_driver_added
argument_list|,
name|bus_generic_driver_added
argument_list|)
block|,
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
name|iicbus_driver
init|=
block|{
literal|"iicbus"
block|,
name|iicbus_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|iicbus_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|iicbus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Philips I2C bus"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|static int  iic_probe_device(device_t dev, u_char addr) { 	int count; 	char byte;  	if ((addr& 1) == 0) {
comment|/* is device writable? */
end_comment

begin_comment
unit|if (!iicbus_start(dev, (u_char)addr, 0)) { 			iicbus_stop(dev); 			return (1); 		} 	} else {
comment|/* is device readable? */
end_comment

begin_endif
unit|if (!iicbus_block_read(dev, (u_char)addr,&byte, 1,&count)) 			return (1); 	}  	return (0); }
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We add all the devices which we know about.  * The generic attach routine will attach them if they are alive.  */
end_comment

begin_function
specifier|static
name|int
name|iicbus_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|iicbus_reset
argument_list|(
name|dev
argument_list|,
name|IIC_FASTEST
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* device probing is meaningless since the bus is supposed to be 	 * hot-plug. Moreover, some I2C chips do not appreciate random 	 * accesses like stop after start to fast, reads for less than 	 * x bytes... 	 */
if|#
directive|if
literal|0
block|printf("Probing for devices on iicbus%d:", device_get_unit(dev));
comment|/* probe any devices */
block|for (addr = FIRST_SLAVE_ADDR; addr<= LAST_SLAVE_ADDR; addr++) { 		if (iic_probe_device(dev, (u_char)addr)) { 			printf("<%x>", addr); 		} 	} 	printf("\n");
endif|#
directive|endif
comment|/* attach any known device */
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
specifier|static
name|int
name|iicbus_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|iicbus_reset
argument_list|(
name|dev
argument_list|,
name|IIC_FASTEST
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|bus_generic_detach
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
specifier|static
name|int
name|iicbus_add_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|order
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|)
block|{
name|device_add_child_ordered
argument_list|(
name|dev
argument_list|,
name|order
argument_list|,
name|name
argument_list|,
name|unit
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
name|int
name|iicbus_generic_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|event
parameter_list|,
name|char
modifier|*
name|buf
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
name|int
name|iicbus_null_callback
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|index
parameter_list|,
name|caddr_t
name|data
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
name|int
name|iicbus_null_repeated_start
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_char
name|addr
parameter_list|)
block|{
return|return
operator|(
name|IIC_ENOTSUPP
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|iicbus
argument_list|,
name|pcf
argument_list|,
name|iicbus_driver
argument_list|,
name|iicbus_devclass
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
name|iicbus
argument_list|,
name|iicbb
argument_list|,
name|iicbus_driver
argument_list|,
name|iicbus_devclass
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
name|iicbus
argument_list|,
name|bti2c
argument_list|,
name|iicbus_driver
argument_list|,
name|iicbus_devclass
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
name|iicbus
argument_list|,
name|IICBUS_MODVER
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

