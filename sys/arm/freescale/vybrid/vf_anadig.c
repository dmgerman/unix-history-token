begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family Analog components control digital interface (ANADIG)  * Chapter 11, Vybrid Reference Manual, Rev. 5, 07/2013  */
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
file|<arm/freescale/vybrid/vf_common.h>
end_include

begin_define
define|#
directive|define
name|ANADIG_PLL3_CTRL
value|0x010
end_define

begin_comment
comment|/* PLL3 Control */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL7_CTRL
value|0x020
end_define

begin_comment
comment|/* PLL7 Control */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL2_CTRL
value|0x030
end_define

begin_comment
comment|/* PLL2 Control */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL2_SS
value|0x040
end_define

begin_comment
comment|/* PLL2 Spread Spectrum */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL2_NUM
value|0x050
end_define

begin_comment
comment|/* PLL2 Numerator */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL2_DENOM
value|0x060
end_define

begin_comment
comment|/* PLL2 Denominator */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL4_CTRL
value|0x070
end_define

begin_comment
comment|/* PLL4 Control */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL4_NUM
value|0x080
end_define

begin_comment
comment|/* PLL4 Numerator */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL4_DENOM
value|0x090
end_define

begin_comment
comment|/* PLL4 Denominator */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL6_CTRL
value|0x0A0
end_define

begin_comment
comment|/* PLL6 Control */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL6_NUM
value|0x0B0
end_define

begin_comment
comment|/* PLL6 Numerator */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL6_DENOM
value|0x0C0
end_define

begin_comment
comment|/* PLL6 Denominator */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL5_CTRL
value|0x0E0
end_define

begin_comment
comment|/* PLL5 Control */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL3_PFD
value|0x0F0
end_define

begin_comment
comment|/* PLL3 PFD */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL2_PFD
value|0x100
end_define

begin_comment
comment|/* PLL2 PFD */
end_comment

begin_define
define|#
directive|define
name|ANADIG_REG_1P1
value|0x110
end_define

begin_comment
comment|/* Regulator 1P1 */
end_comment

begin_define
define|#
directive|define
name|ANADIG_REG_3P0
value|0x120
end_define

begin_comment
comment|/* Regulator 3P0 */
end_comment

begin_define
define|#
directive|define
name|ANADIG_REG_2P5
value|0x130
end_define

begin_comment
comment|/* Regulator 2P5 */
end_comment

begin_define
define|#
directive|define
name|ANADIG_ANA_MISC0
value|0x150
end_define

begin_comment
comment|/* Analog Miscellaneous */
end_comment

begin_define
define|#
directive|define
name|ANADIG_ANA_MISC1
value|0x160
end_define

begin_comment
comment|/* Analog Miscellaneous */
end_comment

begin_define
define|#
directive|define
name|ANADIG_ANADIG_DIGPROG
value|0x260
end_define

begin_comment
comment|/* Digital Program */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL1_CTRL
value|0x270
end_define

begin_comment
comment|/* PLL1 Control */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL1_SS
value|0x280
end_define

begin_comment
comment|/* PLL1 Spread Spectrum */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL1_NUM
value|0x290
end_define

begin_comment
comment|/* PLL1 Numerator */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL1_DENOM
value|0x2A0
end_define

begin_comment
comment|/* PLL1 Denominator */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL1_PFD
value|0x2B0
end_define

begin_comment
comment|/* PLL1_PFD */
end_comment

begin_define
define|#
directive|define
name|ANADIG_PLL_LOCK
value|0x2C0
end_define

begin_comment
comment|/* PLL Lock */
end_comment

begin_define
define|#
directive|define
name|USB_VBUS_DETECT
parameter_list|(
name|n
parameter_list|)
value|(0x1A0 + 0x60 * n)
end_define

begin_define
define|#
directive|define
name|USB_CHRG_DETECT
parameter_list|(
name|n
parameter_list|)
value|(0x1B0 + 0x60 * n)
end_define

begin_define
define|#
directive|define
name|USB_VBUS_DETECT_STATUS
parameter_list|(
name|n
parameter_list|)
value|(0x1C0 + 0x60 * n)
end_define

begin_define
define|#
directive|define
name|USB_CHRG_DETECT_STATUS
parameter_list|(
name|n
parameter_list|)
value|(0x1D0 + 0x60 * n)
end_define

begin_define
define|#
directive|define
name|USB_LOOPBACK
parameter_list|(
name|n
parameter_list|)
value|(0x1E0 + 0x60 * n)
end_define

begin_define
define|#
directive|define
name|USB_MISC
parameter_list|(
name|n
parameter_list|)
value|(0x1F0 + 0x60 * n)
end_define

begin_define
define|#
directive|define
name|ANADIG_PLL_LOCKED
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|ENABLE_LINREG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EN_CLK_TO_UTMI
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|CTRL_BYPASS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|CTRL_PWR
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|CTRL_PLL_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|EN_USB_CLKS
value|(1<< 6)
end_define

begin_struct
struct|struct
name|anadig_softc
block|{
name|struct
name|resource
modifier|*
name|res
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
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|anadig_spec
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
name|anadig_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"fsl,mvf600-anadig"
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
literal|"Vybrid Family ANADIG Unit"
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
name|enable_pll
parameter_list|(
name|struct
name|anadig_softc
modifier|*
name|sc
parameter_list|,
name|int
name|pll_ctrl
parameter_list|)
block|{
name|int
name|reg
decl_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|pll_ctrl
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|CTRL_BYPASS
operator||
name|CTRL_PWR
operator|)
expr_stmt|;
if|if
condition|(
name|pll_ctrl
operator|==
name|ANADIG_PLL3_CTRL
operator|||
name|pll_ctrl
operator|==
name|ANADIG_PLL7_CTRL
condition|)
block|{
comment|/* It is USB PLL. Power bit logic is reversed */
name|reg
operator||=
operator|(
name|CTRL_PWR
operator||
name|EN_USB_CLKS
operator|)
expr_stmt|;
block|}
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|pll_ctrl
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Wait for PLL lock */
while|while
condition|(
operator|!
operator|(
name|READ4
argument_list|(
name|sc
argument_list|,
name|pll_ctrl
argument_list|)
operator|&
name|ANADIG_PLL_LOCKED
operator|)
condition|)
empty_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|pll_ctrl
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|CTRL_PLL_EN
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|pll_ctrl
argument_list|,
name|reg
argument_list|)
expr_stmt|;
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
name|anadig_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|anadig_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|anadig_spec
argument_list|,
name|sc
operator|->
name|res
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
name|res
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
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* Enable USB PLLs */
name|enable_pll
argument_list|(
name|sc
argument_list|,
name|ANADIG_PLL3_CTRL
argument_list|)
expr_stmt|;
name|enable_pll
argument_list|(
name|sc
argument_list|,
name|ANADIG_PLL7_CTRL
argument_list|)
expr_stmt|;
comment|/* Enable other */
name|enable_pll
argument_list|(
name|sc
argument_list|,
name|ANADIG_PLL1_CTRL
argument_list|)
expr_stmt|;
name|enable_pll
argument_list|(
name|sc
argument_list|,
name|ANADIG_PLL2_CTRL
argument_list|)
expr_stmt|;
name|enable_pll
argument_list|(
name|sc
argument_list|,
name|ANADIG_PLL4_CTRL
argument_list|)
expr_stmt|;
name|enable_pll
argument_list|(
name|sc
argument_list|,
name|ANADIG_PLL5_CTRL
argument_list|)
expr_stmt|;
name|enable_pll
argument_list|(
name|sc
argument_list|,
name|ANADIG_PLL6_CTRL
argument_list|)
expr_stmt|;
comment|/* Enable USB voltage regulator */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|ANADIG_REG_3P0
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|ENABLE_LINREG
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|ANADIG_REG_3P0
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Give clocks to USB */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|USB_MISC
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|EN_CLK_TO_UTMI
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_MISC
argument_list|(
literal|0
argument_list|)
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|USB_MISC
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|EN_CLK_TO_UTMI
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_MISC
argument_list|(
literal|1
argument_list|)
argument_list|,
name|reg
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|printf("USB_ANALOG_USB_MISC(0) == 0x%08x\n", 	    READ4(sc, USB_ANALOG_USB_MISC(0))); 	printf("USB_ANALOG_USB_MISC(1) == 0x%08x\n", 	    READ4(sc, USB_ANALOG_USB_MISC(1)));
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
name|anadig_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|anadig_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|anadig_attach
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
name|anadig_driver
init|=
block|{
literal|"anadig"
block|,
name|anadig_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|anadig_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|anadig_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|anadig
argument_list|,
name|simplebus
argument_list|,
name|anadig_driver
argument_list|,
name|anadig_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

