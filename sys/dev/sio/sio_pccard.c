begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus_pio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/timepps.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccardreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccardvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pccard/pccarddevs.h>
end_include

begin_include
include|#
directive|include
file|<dev/sio/siovar.h>
end_include

begin_function_decl
specifier|static
name|int
name|sio_pccard_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|sio_pccard_match
parameter_list|(
name|device_t
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|sio_pccard_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|sio_pccard_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|pccard_compat_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|pccard_compat_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|siodetach
argument_list|)
block|,
comment|/* Card interface */
name|DEVMETHOD
argument_list|(
name|card_compat_match
argument_list|,
name|sio_pccard_match
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|card_compat_probe
argument_list|,
name|sio_pccard_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|card_compat_attach
argument_list|,
name|sio_pccard_attach
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
name|sio_pccard_driver
init|=
block|{
name|sio_driver_name
block|,
name|sio_pccard_methods
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|sio_pccard_match
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
name|u_int32_t
name|fcn
init|=
name|PCCARD_FUNCTION_UNSPEC
decl_stmt|;
name|error
operator|=
name|pccard_get_function
argument_list|(
name|dev
argument_list|,
operator|&
name|fcn
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* 	 * If a serial card, we are likely the right driver.  However, 	 * some serial cards are better servered by other drivers, so 	 * allow other drivers to claim it, if they want. 	 */
if|if
condition|(
name|fcn
operator|==
name|PCCARD_FUNCTION_SERIAL
condition|)
return|return
operator|(
operator|-
literal|100
operator|)
return|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sio_pccard_probe
parameter_list|(
name|dev
parameter_list|)
name|device_t
name|dev
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|PC98
name|SET_FLAG
argument_list|(
name|dev
argument_list|,
name|SET_IFTYPE
argument_list|(
name|COM_IF_MODEM_CARD
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Do not probe IRQ - pccard doesn't turn on the interrupt line */
comment|/* until bus_setup_intr */
return|return
operator|(
name|sioprobe
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|0UL
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sio_pccard_attach
parameter_list|(
name|dev
parameter_list|)
name|device_t
name|dev
decl_stmt|;
block|{
return|return
operator|(
name|sioattach
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|0UL
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|sio
argument_list|,
name|pccard
argument_list|,
name|sio_pccard_driver
argument_list|,
name|sio_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

