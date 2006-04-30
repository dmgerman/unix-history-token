begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2002 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * PSIM local bus 16550  */
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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/timepps.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<powerpc/psim/iobusvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/sio/sioreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/sio/siovar.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_comment
comment|/* for isa_irq_pending() prototype */
end_comment

begin_function_decl
specifier|static
name|int
name|sio_iobus_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|sio_iobus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|sio_iobus_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|sio_iobus_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|sio_iobus_attach
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
name|sio_iobus_driver
init|=
block|{
name|sio_driver_name
block|,
name|sio_iobus_methods
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|sio_iobus_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|sioattach
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
name|DEFAULT_RCLK
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sio_iobus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|char
modifier|*
name|type
init|=
name|iobus_get_name
argument_list|(
name|dev
argument_list|)
decl_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|type
argument_list|,
literal|"com"
argument_list|,
literal|3
argument_list|)
operator|!=
literal|0
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
literal|"PSIM serial port"
argument_list|)
expr_stmt|;
comment|/* 	 * Call sioprobe with noprobe=1, to avoid hitting a psim bug 	 */
return|return
operator|(
name|sioprobe
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
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
name|iobus
argument_list|,
name|sio_iobus_driver
argument_list|,
name|sio_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Stub function. Perhaps a way to get this to work correctly would  * be for child devices to set a field in the dev structure to  * inform the parent that they are isa devices, and then use a  * intr_pending() call which would propagate up to nexus to see  * if the interrupt controller had any intrs in the isa group set  */
end_comment

begin_function
name|intrmask_t
name|isa_irq_pending
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

end_unit

