begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008, 2009 Michael Shalayeff  * Copyright (c) 2009, 2010 Hans-Joerg Hoexer  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER IN  * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<isa/isareg.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<machine/conf.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/isareg.h>
end_include

begin_include
include|#
directive|include
file|<dev/isa/isavar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tpmvar.h"
end_include

begin_function
specifier|static
name|int
name|tpm_isa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|bus_space_tag_t
name|iot
decl_stmt|;
name|bus_space_handle_t
name|ioh
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|int
name|rv
decl_stmt|,
name|mem_rid
decl_stmt|;
name|mem_rid
operator|=
literal|0
expr_stmt|;
name|mem_res
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|mem_rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|mem_res
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|iot
operator|=
name|rman_get_bustag
argument_list|(
name|mem_res
argument_list|)
expr_stmt|;
name|ioh
operator|=
name|rman_get_bushandle
argument_list|(
name|mem_res
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|rv
operator|=
name|tpm_tis12_probe
argument_list|(
name|iot
argument_list|,
name|ioh
argument_list|)
operator|)
condition|)
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Trusted Platform Module"
argument_list|)
expr_stmt|;
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
name|mem_rid
argument_list|,
name|mem_res
argument_list|)
expr_stmt|;
return|return
name|rv
condition|?
literal|0
else|:
name|ENXIO
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|tpm_methods
index|[]
init|=
block|{
if|#
directive|if
literal|0
block|DEVMETHOD(device_identify,	tpm_identify),
endif|#
directive|endif
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|tpm_isa_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|tpm_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|tpm_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_suspend
argument_list|,
name|tpm_suspend
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_resume
argument_list|,
name|tpm_resume
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
name|tpm_driver
init|=
block|{
literal|"tpm"
block|,
name|tpm_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|tpm_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|tpm_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|tpm
argument_list|,
name|isa
argument_list|,
name|tpm_driver
argument_list|,
name|tpm_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

