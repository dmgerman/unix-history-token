begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Child driver for MIPS 3302 core.  * Interrupt controller registers live here. Interrupts may not be routed  * to the MIPS core if they are masked out.  */
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
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/siba/sibavar.h>
end_include

begin_include
include|#
directive|include
file|<dev/siba/sibareg.h>
end_include

begin_include
include|#
directive|include
file|<dev/siba/siba_ids.h>
end_include

begin_function_decl
specifier|static
name|int
name|siba_mips_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|siba_mips_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|siba_mips_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|siba_get_vendor
argument_list|(
name|dev
argument_list|)
operator|==
name|SIBA_VID_BROADCOM
operator|&&
name|siba_get_device
argument_list|(
name|dev
argument_list|)
operator|==
name|SIBA_DEVID_MIPS_3302
condition|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"MIPS 3302 processor"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|siba_mips_softc
block|{
name|void
modifier|*
name|notused
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|int
name|siba_mips_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
comment|//struct siba_mips_softc *sc = device_get_softc(dev);
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|int
name|rid
decl_stmt|;
comment|/* 	 * Allocate the resources which the parent bus has already 	 * determined for us. 	 * TODO: interrupt routing 	 */
define|#
directive|define
name|MIPS_MEM_RID
value|0x20
name|rid
operator|=
name|MIPS_MEM_RID
expr_stmt|;
name|mem
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|mem
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"unable to allocate memory\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
if|#
directive|if
literal|0
block|device_printf(dev, "start %08lx size %04lx\n", 	    rman_get_start(mem), rman_get_size(mem));
endif|#
directive|endif
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
name|siba_mips_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|siba_mips_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|siba_mips_probe
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
name|siba_mips_driver
init|=
block|{
literal|"siba_mips"
block|,
name|siba_mips_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|siba_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|siba_mips_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|siba_mips
argument_list|,
name|siba
argument_list|,
name|siba_mips_driver
argument_list|,
name|siba_mips_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

