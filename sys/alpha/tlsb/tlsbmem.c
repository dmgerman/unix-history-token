begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997, 2000 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Dummy Node for TLSB Memory Modules found on  * AlphaServer 8200 and 8400 systems.  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/tlsbreg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/tlsbvar.h>
end_include

begin_comment
comment|/*  * Device methods  */
end_comment

begin_function_decl
specifier|static
name|int
name|tlsbmem_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|tlsbmem_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|tlsbmem_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|bus_generic_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|bus_generic_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|bus_generic_shutdown
argument_list|)
block|,
comment|/* Bus interface */
name|DEVMETHOD
argument_list|(
name|bus_print_child
argument_list|,
name|bus_generic_print_child
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_read_ivar
argument_list|,
name|bus_generic_read_ivar
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_write_ivar
argument_list|,
name|bus_generic_write_ivar
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_setup_intr
argument_list|,
name|bus_generic_setup_intr
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_teardown_intr
argument_list|,
name|bus_generic_teardown_intr
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
name|devclass_t
name|tlsbmem_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|tlsbmem_driver
init|=
block|{
literal|"tlsbmem"
block|,
name|tlsbmem_methods
block|,
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|tlsbmem_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|tlsb_device
modifier|*
name|tdev
init|=
name|DEVTOTLSB
argument_list|(
name|dev
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|TLDEV_ISMEM
argument_list|(
name|tdev
operator|->
name|td_tldev
argument_list|)
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|tlsbmem
argument_list|,
name|tlsb
argument_list|,
name|tlsbmem_driver
argument_list|,
name|tlsbmem_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

