begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@freebsd.org>  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
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
file|<dev/bhnd/bhnd_ids.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/siba/sibareg.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/siba/sibavar.h>
end_include

begin_include
include|#
directive|include
file|"bcm_machdep.h"
end_include

begin_include
include|#
directive|include
file|"bcm_mipsvar.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_nexusvar.h"
end_include

begin_comment
comment|/*  * Supports siba(4) attachment to a MIPS nexus bus.  *   * Derived from Bruce M. Simpson' original siba(4) driver.  */
end_comment

begin_assert
assert|_Static_assert
argument_list|(
name|SIBA_MAX_INTR
operator|==
name|BCM_MIPS_NINTR
argument_list|,
literal|"SIBA incompatible with "
literal|"generic NINTR"
argument_list|)
assert|;
end_assert

begin_function
specifier|static
name|int
name|siba_nexus_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|bcm_get_platform
argument_list|()
operator|->
name|cid
operator|.
name|chip_type
operator|!=
name|BHND_CHIPTYPE_SIBA
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
operator|(
name|error
operator|=
name|siba_probe
argument_list|(
name|dev
argument_list|)
operator|)
operator|>
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
comment|/* Set device description */
name|bhnd_set_default_bus_desc
argument_list|(
name|dev
argument_list|,
operator|&
name|bcm_get_platform
argument_list|()
operator|->
name|cid
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_SPECIFIC
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|siba_nexus_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
comment|/* Perform initial attach and enumerate our children. */
if|if
condition|(
operator|(
name|error
operator|=
name|siba_attach
argument_list|(
name|dev
argument_list|)
operator|)
condition|)
goto|goto
name|failed
goto|;
comment|/* Delegate remainder to standard bhnd method implementation */
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_generic_attach
argument_list|(
name|dev
argument_list|)
operator|)
condition|)
goto|goto
name|failed
goto|;
return|return
operator|(
literal|0
operator|)
return|;
name|failed
label|:
name|device_delete_children
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|siba_nexus_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|siba_nexus_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|siba_nexus_attach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_2
argument_list|(
name|bhnd
argument_list|,
name|siba_nexus_driver
argument_list|,
name|siba_nexus_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|siba_softc
argument_list|)
argument_list|,
name|bhnd_nexus_driver
argument_list|,
name|siba_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EARLY_DRIVER_MODULE
argument_list|(
name|siba_nexus
argument_list|,
name|nexus
argument_list|,
name|siba_nexus_driver
argument_list|,
name|bhnd_devclass
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

end_unit

