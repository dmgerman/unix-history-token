begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id */
end_comment

begin_comment
comment|/* $NetBSD: gbus.c,v 1.8 1998/05/13 22:13:35 thorpej Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 by Matthew Jacob  * NASA AMES Research Center.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Autoconfiguration and support routines for the Gbus: the internal  * bus on AlphaServer CPU modules.  */
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
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/gbusreg.h>
end_include

begin_include
include|#
directive|include
file|<alpha/tlsb/gbusvar.h>
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

begin_decl_stmt
specifier|extern
name|int
name|cputype
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KV
parameter_list|(
name|_addr
parameter_list|)
value|((caddr_t)ALPHA_PHYS_TO_K0SEG((_addr)))
end_define

begin_comment
comment|/*  * The structure used to attach devices to the Gbus.  */
end_comment

begin_struct
struct|struct
name|gbus_device
block|{
specifier|const
name|char
modifier|*
name|gd_name
decl_stmt|;
name|int
name|gd_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEVTOGBUS
parameter_list|(
name|dev
parameter_list|)
value|((struct gbus_device*) device_get_ivars(dev))
end_define

begin_decl_stmt
name|struct
name|gbus_device
name|gbus_children
index|[]
init|=
block|{
block|{
literal|"zsc"
block|,
name|GBUS_DUART0_OFFSET
block|}
block|,
comment|/* 	{ "zsc",	GBUS_DUART1_OFFSET },*/
block|{
literal|"mcclock"
block|,
name|GBUS_CLOCK_OFFSET
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|gbus_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Device methods  */
end_comment

begin_function_decl
specifier|static
name|int
name|gbus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|gbus_print_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|gbus_read_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|u_long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
name|device_method_t
name|gbus_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|gbus_probe
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
name|gbus_print_child
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_read_ivar
argument_list|,
name|gbus_read_ivar
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
name|driver_t
name|gbus_driver
init|=
block|{
literal|"gbus"
block|,
name|gbus_methods
block|,
literal|1
block|,
comment|/* no softc */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * At 'probe' time, we add all the devices which we know about to the  * bus.  The generic attach routine will probe and attach them if they  * are alive.  */
end_comment

begin_function
specifier|static
name|int
name|gbus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|gbus_device
modifier|*
name|gdev
decl_stmt|;
comment|/* 	 * Make sure we're looking for a Gbus. 	 * Right now, only Gbus could be a 	 * child of a TLSB CPU Node. 	 */
if|if
condition|(
operator|!
name|TLDEV_ISCPU
argument_list|(
name|tlsb_get_dtype
argument_list|(
name|dev
argument_list|)
argument_list|)
condition|)
return|return
name|ENXIO
return|;
for|for
control|(
name|gdev
operator|=
name|gbus_children
init|;
name|gdev
operator|->
name|gd_name
condition|;
name|gdev
operator|++
control|)
name|device_add_child
argument_list|(
name|dev
argument_list|,
name|gdev
operator|->
name|gd_name
argument_list|,
operator|-
literal|1
argument_list|,
name|gdev
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|gbus_print_child
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|gbus_device
modifier|*
name|gdev
init|=
name|DEVTOGBUS
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|" at %s%d offset 0x%x"
argument_list|,
name|device_get_name
argument_list|(
name|bus
argument_list|)
argument_list|,
name|device_get_unit
argument_list|(
name|bus
argument_list|)
argument_list|,
name|gdev
operator|->
name|gd_offset
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|gbus_read_ivar
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|index
parameter_list|,
name|u_long
modifier|*
name|result
parameter_list|)
block|{
name|struct
name|gbus_device
modifier|*
name|gdev
init|=
name|DEVTOGBUS
argument_list|(
name|dev
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|index
condition|)
block|{
case|case
name|GBUS_IVAR_OFFSET
case|:
operator|*
name|result
operator|=
name|gdev
operator|->
name|gd_offset
expr_stmt|;
break|break;
block|}
return|return
name|ENOENT
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|gbus
argument_list|,
name|tlsb
argument_list|,
name|gbus_driver
argument_list|,
name|gbus_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

