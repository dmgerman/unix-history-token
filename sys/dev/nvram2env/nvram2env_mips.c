begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Aleksandr Rybalko.  * Copyright (c) 2016 Michael Zhilin.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Implementation of pseudo driver for MIPS to copy the NVRAM settings  * from various sources into the kernel environment.  */
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
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|"nvram2env.h"
end_include

begin_function
specifier|static
name|int
name|nvram2env_mips_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|nvram2env_softc
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
name|sc
operator|->
name|bst
operator|=
name|mips_bus_space_generic
expr_stmt|;
return|return
operator|(
name|nvram2env_probe
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|nvram2env_mips_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|nvram2env_mips_probe
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|nvram2env
argument_list|,
name|nvram2env_mips_driver
argument_list|,
name|nvram2env_mips_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|nvram2env_softc
argument_list|)
argument_list|,
name|nvram2env_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|nvram2env_mips
argument_list|,
name|nexus
argument_list|,
name|nvram2env_mips_driver
argument_list|,
name|nvram2env_devclass
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|nvram2env_mips
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|nvram2env_mips
argument_list|,
name|nvram2env
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

