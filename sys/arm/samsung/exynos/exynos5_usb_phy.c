begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * DWC3 USB 3.0 DRD (dual role device) PHY  */
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
file|<sys/gpio.h>
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
file|<arm/samsung/exynos/exynos5_common.h>
end_include

begin_include
include|#
directive|include
file|<arm/samsung/exynos/exynos5_pmu.h>
end_include

begin_include
include|#
directive|include
file|"gpio_if.h"
end_include

begin_define
define|#
directive|define
name|USB_DRD_LINKSYSTEM
value|0x04
end_define

begin_define
define|#
directive|define
name|LINKSYSTEM_FLADJ_MASK
value|(0x3f<< 1)
end_define

begin_define
define|#
directive|define
name|LINKSYSTEM_FLADJ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|LINKSYSTEM_XHCI_VERSION_CTRL
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYUTMI
value|0x08
end_define

begin_define
define|#
directive|define
name|PHYUTMI_OTGDISABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PHYUTMI_FORCESUSPEND
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PHYUTMI_FORCESLEEP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYPIPE
value|0x0c
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYCLKRST
value|0x10
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_PORTRESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_COMMONONN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_EN_UTMISUSPEND
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_SSC_REFCLKSEL_MASK
value|(0xff<< 23)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_SSC_REFCLKSEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 23)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_SSC_RANGE_MASK
value|(0x03<< 21)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_SSC_RANGE
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_SSC_EN
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_REF_SSP_EN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_REF_CLKDIV2
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_MPLL_MLTPR_MASK
value|(0x7f<< 11)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_MPLL_MLTPR_100MHZ
value|(0x19<< 11)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_MPLL_MLTPR_50M
value|(0x32<< 11)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_MPLL_MLTPR_24MHZ
value|(0x68<< 11)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_MPLL_MLTPR_20MHZ
value|(0x7d<< 11)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_MPLL_MLTPR_19200KHZ
value|(0x02<< 11)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_UTMI_MASK
value|(0x7<< 5)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_PIPE_MASK
value|(0x7<< 8)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_9MHZ6
value|0x0
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_10MHZ
value|0x1
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_12MHZ
value|0x2
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_19MHZ2
value|0x3
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_20MHZ
value|0x4
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_24MHZ
value|0x5
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_FSEL_50MHZ
value|0x7
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_RETENABLEN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_REFCLKSEL_MASK
value|(0x03<< 2)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_REFCLKSEL_PAD_REFCLK
value|(0x2<< 2)
end_define

begin_define
define|#
directive|define
name|PHYCLKRST_REFCLKSEL_EXT_REFCLK
value|(0x3<< 2)
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYREG0
value|0x14
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYREG1
value|0x18
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYPARAM0
value|0x1c
end_define

begin_define
define|#
directive|define
name|PHYPARAM0_REF_USE_PAD
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|PHYPARAM0_REF_LOSLEVEL_MASK
value|(0x1f<< 26)
end_define

begin_define
define|#
directive|define
name|PHYPARAM0_REF_LOSLEVEL
value|(0x9<< 26)
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYPARAM1
value|0x20
end_define

begin_define
define|#
directive|define
name|PHYPARAM1_PCS_TXDEEMPH_MASK
value|(0x1f<< 0)
end_define

begin_define
define|#
directive|define
name|PHYPARAM1_PCS_TXDEEMPH
value|(0x1c)
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYTERM
value|0x24
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYTEST
value|0x28
end_define

begin_define
define|#
directive|define
name|PHYTEST_POWERDOWN_SSP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PHYTEST_POWERDOWN_HSP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYADP
value|0x2c
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYUTMICLKSEL
value|0x30
end_define

begin_define
define|#
directive|define
name|PHYUTMICLKSEL_UTMI_CLKSEL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|USB_DRD_PHYRESUME
value|0x34
end_define

begin_define
define|#
directive|define
name|USB_DRD_LINKPORT
value|0x44
end_define

begin_struct
struct|struct
name|usb_phy_softc
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
name|usb_phy_spec
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
name|usb_phy_probe
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
literal|"samsung,exynos5420-usbdrd-phy"
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
literal|"Samsung Exynos 5 USB PHY"
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
name|vbus_on
parameter_list|(
name|struct
name|usb_phy_softc
modifier|*
name|sc
parameter_list|)
block|{
name|pcell_t
name|dts_value
index|[
literal|3
index|]
decl_stmt|;
name|device_t
name|gpio_dev
decl_stmt|;
name|phandle_t
name|node
decl_stmt|;
name|pcell_t
name|pin
decl_stmt|;
name|int
name|len
decl_stmt|;
if|if
condition|(
operator|(
name|node
operator|=
name|ofw_bus_get_node
argument_list|(
name|sc
operator|->
name|dev
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* Power pin */
if|if
condition|(
operator|(
name|len
operator|=
name|OF_getproplen
argument_list|(
name|node
argument_list|,
literal|"vbus-supply"
argument_list|)
operator|)
operator|<=
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|OF_getencprop
argument_list|(
name|node
argument_list|,
literal|"vbus-supply"
argument_list|,
name|dts_value
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|pin
operator|=
name|dts_value
index|[
literal|0
index|]
expr_stmt|;
name|gpio_dev
operator|=
name|devclass_get_device
argument_list|(
name|devclass_find
argument_list|(
literal|"gpio"
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|gpio_dev
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
literal|"cant find gpio_dev\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|GPIO_PIN_SETFLAGS
argument_list|(
name|gpio_dev
argument_list|,
name|pin
argument_list|,
name|GPIO_PIN_OUTPUT
argument_list|)
expr_stmt|;
name|GPIO_PIN_SET
argument_list|(
name|gpio_dev
argument_list|,
name|pin
argument_list|,
name|GPIO_PIN_HIGH
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
name|usb3_phy_init
parameter_list|(
name|struct
name|usb_phy_softc
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|reg
decl_stmt|;
comment|/* Reset USB 3.0 PHY */
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYREG0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYPARAM0
argument_list|)
expr_stmt|;
comment|/* PHY CLK src */
name|reg
operator|&=
operator|~
operator|(
name|PHYPARAM0_REF_USE_PAD
operator|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|PHYPARAM0_REF_LOSLEVEL_MASK
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|PHYPARAM0_REF_LOSLEVEL
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYPARAM0
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYRESUME
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|reg
operator|=
operator|(
name|LINKSYSTEM_XHCI_VERSION_CTRL
operator||
name|LINKSYSTEM_FLADJ
argument_list|(
literal|0x20
argument_list|)
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_LINKSYSTEM
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
name|USB_DRD_PHYPARAM1
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|PHYPARAM1_PCS_TXDEEMPH_MASK
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|PHYPARAM1_PCS_TXDEEMPH
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYPARAM1
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
name|USB_DRD_PHYUTMICLKSEL
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|PHYUTMICLKSEL_UTMI_CLKSEL
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYUTMICLKSEL
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
name|USB_DRD_PHYTEST
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|PHYTEST_POWERDOWN_HSP
operator|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|PHYTEST_POWERDOWN_SSP
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYTEST
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYUTMI
argument_list|,
name|PHYUTMI_OTGDISABLE
argument_list|)
expr_stmt|;
comment|/* Clock */
name|reg
operator|=
operator|(
name|PHYCLKRST_REFCLKSEL_EXT_REFCLK
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|PHYCLKRST_FSEL
argument_list|(
name|PHYCLKRST_FSEL_24MHZ
argument_list|)
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|PHYCLKRST_MPLL_MLTPR_24MHZ
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|PHYCLKRST_SSC_REFCLKSEL
argument_list|(
literal|0x88
argument_list|)
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|PHYCLKRST_RETENABLEN
operator||
name|PHYCLKRST_REF_SSP_EN
operator||
comment|/* Super speed */
name|PHYCLKRST_SSC_EN
operator||
comment|/* Spread spectrum */
name|PHYCLKRST_COMMONONN
operator||
name|PHYCLKRST_PORTRESET
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYCLKRST
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|50000
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
name|PHYCLKRST_PORTRESET
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|USB_DRD_PHYCLKRST
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
name|usb_phy_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|usb_phy_softc
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
name|usb_phy_spec
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
name|vbus_on
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|usbdrd_phy_power_on
argument_list|()
expr_stmt|;
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|usb3_phy_init
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
name|usb_phy_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|usb_phy_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|usb_phy_attach
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
name|usb_phy_driver
init|=
block|{
literal|"usb_phy"
block|,
name|usb_phy_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|usb_phy_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|usb_phy_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|usb_phy
argument_list|,
name|simplebus
argument_list|,
name|usb_phy_driver
argument_list|,
name|usb_phy_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

