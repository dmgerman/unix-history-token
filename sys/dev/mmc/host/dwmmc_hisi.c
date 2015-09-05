begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2015 Andrew Turner.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<dev/mmc/bridge.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|<dev/mmc/host/dwmmc_var.h>
end_include

begin_decl_stmt
specifier|static
name|device_probe_t
name|hisi_dwmmc_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_attach_t
name|hisi_dwmmc_attach
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|hisi_dwmmc_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_status_okay
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"hisilicon,hi6220-dw-mshc"
argument_list|)
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
literal|"Synopsys DesignWare Mobile "
literal|"Storage Host Controller (HiSilicon)"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_VENDOR
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|hisi_dwmmc_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|dwmmc_softc
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
name|hwtype
operator|=
name|HWTYPE_HISILICON
expr_stmt|;
comment|/* TODO: Calculate this from a clock driver */
name|sc
operator|->
name|bus_hz
operator|=
literal|24000000
expr_stmt|;
comment|/* 24MHz */
comment|/* 	 * ARM64TODO: This is likely because we lack support for 	 * DMA when the controller is not cache-coherent on arm64. 	 */
name|sc
operator|->
name|use_pio
operator|=
literal|1
expr_stmt|;
name|sc
operator|->
name|desc_count
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|dwmmc_attach
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
name|hisi_dwmmc_methods
index|[]
init|=
block|{
comment|/* bus interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|hisi_dwmmc_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|hisi_dwmmc_attach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|hisi_dwmmc_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|hisi_dwmmc
argument_list|,
name|hisi_dwmmc_driver
argument_list|,
name|hisi_dwmmc_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|dwmmc_softc
argument_list|)
argument_list|,
name|dwmmc_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|hisi_dwmmc
argument_list|,
name|simplebus
argument_list|,
name|hisi_dwmmc_driver
argument_list|,
name|hisi_dwmmc_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

