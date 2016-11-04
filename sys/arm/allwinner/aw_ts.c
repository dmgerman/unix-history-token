begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Allwinner Touch Sreen driver  * Touch screen part is not done, only the thermal sensor part is.  */
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
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
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

begin_define
define|#
directive|define
name|READ
parameter_list|(
name|_sc
parameter_list|,
name|_r
parameter_list|)
value|bus_read_4((_sc)->res[0], (_r))
end_define

begin_define
define|#
directive|define
name|WRITE
parameter_list|(
name|_sc
parameter_list|,
name|_r
parameter_list|,
name|_v
parameter_list|)
value|bus_write_4((_sc)->res[0], (_r), (_v))
end_define

begin_comment
comment|/* Control register 0 */
end_comment

begin_define
define|#
directive|define
name|TP_CTRL0
value|0x00
end_define

begin_define
define|#
directive|define
name|TP_CTRL0_TACQ
parameter_list|(
name|x
parameter_list|)
value|((x& 0xFF)<< 0)
end_define

begin_define
define|#
directive|define
name|TP_CTRL0_FS_DIV
parameter_list|(
name|x
parameter_list|)
value|((x& 0xF)<< 16)
end_define

begin_define
define|#
directive|define
name|TP_CTRL0_CLK_DIV
parameter_list|(
name|x
parameter_list|)
value|((x& 0x3)<< 20)
end_define

begin_define
define|#
directive|define
name|TP_CTRL0_CLK_SELECT
parameter_list|(
name|x
parameter_list|)
value|((x& 0x1)<< 22)
end_define

begin_comment
comment|/* Control register 1 */
end_comment

begin_define
define|#
directive|define
name|TP_CTRL1
value|0x04
end_define

begin_define
define|#
directive|define
name|TP_CTRL1_MODE_EN
value|(1<< 4)
end_define

begin_comment
comment|/* Control register 2 */
end_comment

begin_define
define|#
directive|define
name|TP_CTRL2
value|0x08
end_define

begin_comment
comment|/* Control register 3 */
end_comment

begin_define
define|#
directive|define
name|TP_CTRL3
value|0x0C
end_define

begin_comment
comment|/* Int/FIFO control register */
end_comment

begin_define
define|#
directive|define
name|TP_FIFOC
value|0x10
end_define

begin_define
define|#
directive|define
name|TP_FIFOC_TEMP_IRQ_ENABLE
value|(1<< 18)
end_define

begin_comment
comment|/* Int/FIFO status register */
end_comment

begin_define
define|#
directive|define
name|TP_FIFOS
value|0x14
end_define

begin_define
define|#
directive|define
name|TP_FIFOS_TEMP_IRQ_PENDING
value|(1<< 18)
end_define

begin_comment
comment|/* Temperature Period Register */
end_comment

begin_define
define|#
directive|define
name|TP_TPR
value|0x18
end_define

begin_define
define|#
directive|define
name|TP_TPR_TEMP_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|TP_TPR_TEMP_PERIOD
parameter_list|(
name|x
parameter_list|)
value|(x<< 0)
end_define

begin_comment
comment|/* Common data register */
end_comment

begin_define
define|#
directive|define
name|TP_CDAT
value|0x1C
end_define

begin_comment
comment|/* Temperature data register */
end_comment

begin_define
define|#
directive|define
name|TEMP_DATA
value|0x20
end_define

begin_comment
comment|/* TP Data register*/
end_comment

begin_define
define|#
directive|define
name|TP_DATA
value|0x24
end_define

begin_comment
comment|/* TP IO config register */
end_comment

begin_define
define|#
directive|define
name|TP_IO_CONFIG
value|0x28
end_define

begin_comment
comment|/* TP IO port data register */
end_comment

begin_define
define|#
directive|define
name|TP_IO_DATA
value|0x2C
end_define

begin_struct
struct|struct
name|aw_ts_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|intrhand
decl_stmt|;
name|int
name|temp_data
decl_stmt|;
name|int
name|temp_offset
decl_stmt|;
name|int
name|temp_step
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|aw_ts_spec
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
name|SYS_RES_IRQ
block|,
literal|0
block|,
name|RF_ACTIVE
operator||
name|RF_SHAREABLE
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

begin_define
define|#
directive|define
name|A10_TS
value|1
end_define

begin_define
define|#
directive|define
name|A13_TS
value|2
end_define

begin_define
define|#
directive|define
name|AW_TS_TEMP_SYSCTL
value|1
end_define

begin_decl_stmt
specifier|static
name|struct
name|ofw_compat_data
name|compat_data
index|[]
init|=
block|{
block|{
literal|"allwinner,sun4i-a10-ts"
block|,
name|A10_TS
block|}
block|,
block|{
literal|"allwinner,sun5i-a13-ts"
block|,
name|A13_TS
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|aw_ts_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|aw_ts_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|val
decl_stmt|;
name|sc
operator|=
operator|(
expr|struct
name|aw_ts_softc
operator|*
operator|)
name|arg
expr_stmt|;
name|val
operator|=
name|READ
argument_list|(
name|sc
argument_list|,
name|TP_FIFOS
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|&
name|TP_FIFOS_TEMP_IRQ_PENDING
condition|)
block|{
comment|/* Convert the value to millicelsius then millikelvin */
name|sc
operator|->
name|temp_data
operator|=
operator|(
name|READ
argument_list|(
name|sc
argument_list|,
name|TEMP_DATA
argument_list|)
operator|*
name|sc
operator|->
name|temp_step
operator|-
name|sc
operator|->
name|temp_offset
operator|)
operator|+
literal|273150
expr_stmt|;
block|}
name|WRITE
argument_list|(
name|sc
argument_list|,
name|TP_FIFOS
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|aw_ts_probe
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
name|ofw_bus_search_compatible
argument_list|(
name|dev
argument_list|,
name|compat_data
argument_list|)
operator|->
name|ocd_data
operator|==
literal|0
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
literal|"Allwinner Touch Screen controller"
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
name|aw_ts_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|aw_ts_softc
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
name|aw_ts_spec
argument_list|,
name|sc
operator|->
name|res
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"could not allocate memory resource\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
if|if
condition|(
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|res
index|[
literal|1
index|]
argument_list|,
name|INTR_TYPE_MISC
operator||
name|INTR_MPSAFE
argument_list|,
name|NULL
argument_list|,
name|aw_ts_intr
argument_list|,
name|sc
argument_list|,
operator|&
name|sc
operator|->
name|intrhand
argument_list|)
condition|)
block|{
name|bus_release_resources
argument_list|(
name|dev
argument_list|,
name|aw_ts_spec
argument_list|,
name|sc
operator|->
name|res
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"cannot setup interrupt handler\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* 	 * Thoses magic values were taken from linux which take them from 	 * the allwinner SDK or found them by deduction 	 */
switch|switch
condition|(
name|ofw_bus_search_compatible
argument_list|(
name|dev
argument_list|,
name|compat_data
argument_list|)
operator|->
name|ocd_data
condition|)
block|{
case|case
name|A10_TS
case|:
name|sc
operator|->
name|temp_offset
operator|=
literal|257000
expr_stmt|;
name|sc
operator|->
name|temp_step
operator|=
literal|133
expr_stmt|;
break|break;
case|case
name|A13_TS
case|:
name|sc
operator|->
name|temp_offset
operator|=
literal|144700
expr_stmt|;
name|sc
operator|->
name|temp_step
operator|=
literal|100
expr_stmt|;
break|break;
block|}
comment|/* Enable clock and set divisers */
name|WRITE
argument_list|(
name|sc
argument_list|,
name|TP_CTRL0
argument_list|,
name|TP_CTRL0_CLK_SELECT
argument_list|(
literal|0
argument_list|)
operator||
name|TP_CTRL0_CLK_DIV
argument_list|(
literal|2
argument_list|)
operator||
name|TP_CTRL0_FS_DIV
argument_list|(
literal|7
argument_list|)
operator||
name|TP_CTRL0_TACQ
argument_list|(
literal|63
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Enable TS module */
name|WRITE
argument_list|(
name|sc
argument_list|,
name|TP_CTRL1
argument_list|,
name|TP_CTRL1_MODE_EN
argument_list|)
expr_stmt|;
comment|/* Enable Temperature, period is ~2s */
name|WRITE
argument_list|(
name|sc
argument_list|,
name|TP_TPR
argument_list|,
name|TP_TPR_TEMP_EN
operator||
name|TP_TPR_TEMP_PERIOD
argument_list|(
literal|1953
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Enable temp irq */
name|WRITE
argument_list|(
name|sc
argument_list|,
name|TP_FIFOC
argument_list|,
name|TP_FIFOC_TEMP_IRQ_ENABLE
argument_list|)
expr_stmt|;
comment|/* Add sysctl */
name|SYSCTL_ADD_PROC
argument_list|(
name|device_get_sysctl_ctx
argument_list|(
name|dev
argument_list|)
argument_list|,
name|SYSCTL_CHILDREN
argument_list|(
name|device_get_sysctl_tree
argument_list|(
name|dev
argument_list|)
argument_list|)
argument_list|,
name|OID_AUTO
argument_list|,
literal|"temperature"
argument_list|,
name|CTLTYPE_INT
operator||
name|CTLFLAG_RD
argument_list|,
operator|&
name|sc
operator|->
name|temp_data
argument_list|,
literal|0
argument_list|,
name|sysctl_handle_int
argument_list|,
literal|"IK3"
argument_list|,
literal|"CPU Temperature"
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
name|aw_ts_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|aw_ts_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|aw_ts_attach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|aw_ts_driver
init|=
block|{
literal|"aw_ts"
block|,
name|aw_ts_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|aw_ts_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|aw_ts_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|aw_ts
argument_list|,
name|simplebus
argument_list|,
name|aw_ts_driver
argument_list|,
name|aw_ts_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

