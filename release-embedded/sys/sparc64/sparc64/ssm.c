begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_comment
comment|/*  * Glue allowing devices beneath the scalable shared memory node to be  * treated like nexus(4) children  */
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
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/nexusvar.h>
end_include

begin_decl_stmt
specifier|static
name|device_probe_t
name|ssm_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_method_t
name|ssm_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ssm_probe
argument_list|)
block|,
comment|/* Bus interface */
comment|/* ofw_bus interface */
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|ssm_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|ssm
argument_list|,
name|ssm_driver
argument_list|,
name|ssm_methods
argument_list|,
literal|1
comment|/* no softc */
argument_list|,
name|nexus_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EARLY_DRIVER_MODULE
argument_list|(
name|ssm
argument_list|,
name|nexus
argument_list|,
name|ssm_driver
argument_list|,
name|ssm_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|BUS_PASS_BUS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ssm
argument_list|,
name|nexus
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ssm
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|ssm_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|ofw_bus_get_name
argument_list|(
name|dev
argument_list|)
argument_list|,
literal|"ssm"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Scalable Shared Memory"
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

end_unit

