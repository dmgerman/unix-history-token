begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Stanislav Galabov.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
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

begin_include
include|#
directive|include
file|<dev/fdt/simplebus.h>
end_include

begin_comment
comment|/*  * Driver for Mediatek/Ralink Palmbus  *  * Currently the only reason for the existence of this driver is so that we can  * minimize the changes required to the upstream DTS files we use.  * Otherwise palmbus is a very simple subclass of our simplebus and the only  * difference between the two is the actual value of the compatible property.  */
end_comment

begin_function
specifier|static
name|int
name|palmbus_probe
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
operator|(
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"palmbus"
argument_list|)
operator|&&
name|ofw_bus_has_prop
argument_list|(
name|dev
argument_list|,
literal|"ranges"
argument_list|)
operator|)
operator|&&
operator|(
name|ofw_bus_get_type
argument_list|(
name|dev
argument_list|)
operator|==
name|NULL
operator|||
name|strcmp
argument_list|(
name|ofw_bus_get_type
argument_list|(
name|dev
argument_list|)
argument_list|,
literal|"soc"
argument_list|)
operator|!=
literal|0
operator|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"MTK Palmbus"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|palmbus_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|palmbus_probe
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|palmbus
argument_list|,
name|palmbus_driver
argument_list|,
name|palmbus_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|simplebus_softc
argument_list|)
argument_list|,
name|simplebus_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|palmbus_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|EARLY_DRIVER_MODULE
argument_list|(
name|palmbus
argument_list|,
name|ofwbus
argument_list|,
name|palmbus_driver
argument_list|,
name|palmbus_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|BUS_PASS_BUS
operator|+
name|BUS_PASS_ORDER_MIDDLE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|palmbus
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

