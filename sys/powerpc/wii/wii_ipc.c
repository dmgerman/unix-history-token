begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012 Margarida Gouveia  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/platform.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<powerpc/wii/wii_ipcreg.h>
end_include

begin_comment
comment|/*  * Driver to interface with the Wii's IOS. IOS are small "microkernels" that run  * on the Broadway GPU and provide access to system services like USB.  */
end_comment

begin_function_decl
specifier|static
name|int
name|wiiipc_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|wiiipc_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|wiiipc_softc
block|{ }
struct|;
end_struct

begin_decl_stmt
specifier|static
name|device_method_t
name|wiiipc_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|wiiipc_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|wiiipc_attach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|wiiipc_driver
init|=
block|{
literal|"wiiipc"
block|,
name|wiiipc_methods
block|,
expr|sizeof
operator|(
expr|struct
name|wiiipc_softc
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|wiiipc_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|wiiipc
argument_list|,
name|wiibus
argument_list|,
name|wiiipc_driver
argument_list|,
name|wiiipc_devclass
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
name|wiiipc_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Nintendo Wii IOS IPC"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_NOWILDCARD
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|wiiipc_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|wiiipc_softc
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
ifdef|#
directive|ifdef
name|notyet
name|sc
operator|->
name|sc_dev
operator|=
name|dev
expr_stmt|;
name|sc
operator|->
name|sc_rrid
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|sc_rres
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|sc
operator|->
name|sc_rrid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_rres
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"could not alloc mem resource\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|sc
operator|->
name|sc_bt
operator|=
name|rman_get_bustag
argument_list|(
name|sc
operator|->
name|sc_rres
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_bh
operator|=
name|rman_get_bushandle
argument_list|(
name|sc
operator|->
name|sc_rres
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

