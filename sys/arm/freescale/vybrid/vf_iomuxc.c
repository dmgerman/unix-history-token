begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family Input/Output Multiplexer Controller (IOMUXC)  * Chapter 5, Vybrid Reference Manual, Rev. 5, 07/2013  */
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
file|<sys/timeet.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<sys/watchdog.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|<arm/freescale/vybrid/vf_iomuxc.h>
end_include

begin_include
include|#
directive|include
file|<arm/freescale/vybrid/vf_common.h>
end_include

begin_define
define|#
directive|define
name|MUX_MODE_MASK
value|7
end_define

begin_define
define|#
directive|define
name|MUX_MODE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|MUX_MODE_GPIO
value|0
end_define

begin_define
define|#
directive|define
name|MUX_MODE_VBUS_EN_OTG
value|2
end_define

begin_define
define|#
directive|define
name|IBE
value|(1<< 0)
end_define

begin_comment
comment|/* Input Buffer Enable Field */
end_comment

begin_define
define|#
directive|define
name|OBE
value|(1<< 1)
end_define

begin_comment
comment|/* Output Buffer Enable Field. */
end_comment

begin_define
define|#
directive|define
name|PUE
value|(1<< 2)
end_define

begin_comment
comment|/* Pull / Keep Select Field. */
end_comment

begin_define
define|#
directive|define
name|PKE
value|(1<< 3)
end_define

begin_comment
comment|/* Pull / Keep Enable Field. */
end_comment

begin_define
define|#
directive|define
name|HYS
value|(1<< 9)
end_define

begin_comment
comment|/* Hysteresis Enable Field */
end_comment

begin_define
define|#
directive|define
name|ODE
value|(1<< 10)
end_define

begin_comment
comment|/* Open Drain Enable Field. */
end_comment

begin_define
define|#
directive|define
name|SRE
value|(1<< 11)
end_define

begin_comment
comment|/* Slew Rate Field. */
end_comment

begin_define
define|#
directive|define
name|SPEED_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SPEED_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|SPEED_LOW
value|0
end_define

begin_comment
comment|/* 50 MHz */
end_comment

begin_define
define|#
directive|define
name|SPEED_MEDIUM
value|0x1
end_define

begin_comment
comment|/* 100 MHz */
end_comment

begin_define
define|#
directive|define
name|SPEED_HIGH
value|0x3
end_define

begin_comment
comment|/* 200 MHz */
end_comment

begin_define
define|#
directive|define
name|PUS_SHIFT
value|4
end_define

begin_comment
comment|/* Pull Up / Down Config Field Shift */
end_comment

begin_define
define|#
directive|define
name|PUS_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|PUS_100_KOHM_PULL_DOWN
value|0
end_define

begin_define
define|#
directive|define
name|PUS_47_KOHM_PULL_UP
value|0x1
end_define

begin_define
define|#
directive|define
name|PUS_100_KOHM_PULL_UP
value|0x2
end_define

begin_define
define|#
directive|define
name|PUS_22_KOHM_PULL_UP
value|0x3
end_define

begin_define
define|#
directive|define
name|DSE_SHIFT
value|6
end_define

begin_comment
comment|/* Drive Strength Field Shift */
end_comment

begin_define
define|#
directive|define
name|DSE_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|DSE_DISABLED
value|0
end_define

begin_comment
comment|/* Output driver disabled */
end_comment

begin_define
define|#
directive|define
name|DSE_150_OHM
value|0x1
end_define

begin_define
define|#
directive|define
name|DSE_75_OHM
value|0x2
end_define

begin_define
define|#
directive|define
name|DSE_50_OHM
value|0x3
end_define

begin_define
define|#
directive|define
name|DSE_37_OHM
value|0x4
end_define

begin_define
define|#
directive|define
name|DSE_30_OHM
value|0x5
end_define

begin_define
define|#
directive|define
name|DSE_25_OHM
value|0x6
end_define

begin_define
define|#
directive|define
name|DSE_20_OHM
value|0x7
end_define

begin_define
define|#
directive|define
name|MAX_MUX_LEN
value|1024
end_define

begin_struct
struct|struct
name|iomuxc_softc
block|{
name|struct
name|resource
modifier|*
name|tmr_res
index|[
literal|1
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|iomuxc_spec
index|[]
init|=
block|{
block|{
name|SYS_RES_MEMORY
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|iomuxc_probe
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
literal|"fsl,mvf600-iomuxc"
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
literal|"Vybrid Family IOMUXC Unit"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|pinmux_set
parameter_list|(
name|struct
name|iomuxc_softc
modifier|*
name|sc
parameter_list|)
block|{
name|phandle_t
name|child
decl_stmt|,
name|parent
decl_stmt|,
name|root
decl_stmt|;
name|pcell_t
name|iomux_config
index|[
name|MAX_MUX_LEN
index|]
decl_stmt|;
name|int
name|len
decl_stmt|;
name|int
name|values
decl_stmt|;
name|int
name|pin
decl_stmt|;
name|int
name|pin_cfg
decl_stmt|;
name|int
name|i
decl_stmt|;
name|root
operator|=
name|OF_finddevice
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
name|len
operator|=
literal|0
expr_stmt|;
name|parent
operator|=
name|root
expr_stmt|;
comment|/* Find 'iomux_config' prop in the nodes */
for|for
control|(
name|child
operator|=
name|OF_child
argument_list|(
name|parent
argument_list|)
init|;
name|child
operator|!=
literal|0
condition|;
name|child
operator|=
name|OF_peer
argument_list|(
name|child
argument_list|)
control|)
block|{
comment|/* Find a 'leaf'. Start the search from this node. */
while|while
condition|(
name|OF_child
argument_list|(
name|child
argument_list|)
condition|)
block|{
name|parent
operator|=
name|child
expr_stmt|;
name|child
operator|=
name|OF_child
argument_list|(
name|child
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|fdt_is_enabled
argument_list|(
name|child
argument_list|)
condition|)
continue|continue;
if|if
condition|(
operator|(
name|len
operator|=
name|OF_getproplen
argument_list|(
name|child
argument_list|,
literal|"iomux_config"
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
name|OF_getprop
argument_list|(
name|child
argument_list|,
literal|"iomux_config"
argument_list|,
operator|&
name|iomux_config
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|values
operator|=
name|len
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|values
condition|;
name|i
operator|+=
literal|2
control|)
block|{
name|pin
operator|=
name|fdt32_to_cpu
argument_list|(
name|iomux_config
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|pin_cfg
operator|=
name|fdt32_to_cpu
argument_list|(
name|iomux_config
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|device_printf(sc->dev, "Set pin %d to 0x%08x\n", 				    pin, pin_cfg);
endif|#
directive|endif
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|IOMUXC
argument_list|(
name|pin
argument_list|)
argument_list|,
name|pin_cfg
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|OF_peer
argument_list|(
name|child
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* No more siblings. */
name|child
operator|=
name|parent
expr_stmt|;
name|parent
operator|=
name|OF_parent
argument_list|(
name|child
argument_list|)
expr_stmt|;
block|}
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|iomuxc_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|iomuxc_softc
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
name|dev
operator|=
name|dev
expr_stmt|;
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|iomuxc_spec
argument_list|,
name|sc
operator|->
name|tmr_res
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"could not allocate resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Memory interface */
name|sc
operator|->
name|bst
operator|=
name|rman_get_bustag
argument_list|(
name|sc
operator|->
name|tmr_res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|sc
operator|->
name|bsh
operator|=
name|rman_get_bushandle
argument_list|(
name|sc
operator|->
name|tmr_res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|pinmux_set
argument_list|(
name|sc
argument_list|)
expr_stmt|;
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
name|iomuxc_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|iomuxc_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|iomuxc_attach
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
name|iomuxc_driver
init|=
block|{
literal|"iomuxc"
block|,
name|iomuxc_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|iomuxc_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|iomuxc_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|iomuxc
argument_list|,
name|simplebus
argument_list|,
name|iomuxc_driver
argument_list|,
name|iomuxc_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

