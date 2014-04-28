begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family Universal Serial Bus (USB) Controller  * Chapter 44-45, Vybrid Reference Manual, Rev. 5, 07/2013  */
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
file|"opt_bus.h"
end_include

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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/gpio.h>
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
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdi.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_busdma.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_process.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_controller.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/controller/ehci.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/controller/ehcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|"gpio_if.h"
end_include

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

begin_define
define|#
directive|define
name|ENUTMILEVEL3
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|ENUTMILEVEL2
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|GPIO_USB_PWR
value|134
end_define

begin_define
define|#
directive|define
name|USB_ID
value|0x000
end_define

begin_comment
comment|/* Identification register */
end_comment

begin_define
define|#
directive|define
name|USB_HWGENERAL
value|0x004
end_define

begin_comment
comment|/* Hardware General */
end_comment

begin_define
define|#
directive|define
name|USB_HWHOST
value|0x008
end_define

begin_comment
comment|/* Host Hardware Parameters */
end_comment

begin_define
define|#
directive|define
name|USB_HWDEVICE
value|0x00C
end_define

begin_comment
comment|/* Device Hardware Parameters */
end_comment

begin_define
define|#
directive|define
name|USB_HWTXBUF
value|0x010
end_define

begin_comment
comment|/* TX Buffer Hardware Parameters */
end_comment

begin_define
define|#
directive|define
name|USB_HWRXBUF
value|0x014
end_define

begin_comment
comment|/* RX Buffer Hardware Parameters */
end_comment

begin_define
define|#
directive|define
name|USB_HCSPARAMS
value|0x104
end_define

begin_comment
comment|/* Host Controller Structural Parameters */
end_comment

begin_define
define|#
directive|define
name|USBPHY_PWD
value|0x00
end_define

begin_comment
comment|/* PHY Power-Down Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_PWD_SET
value|0x04
end_define

begin_comment
comment|/* PHY Power-Down Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_PWD_CLR
value|0x08
end_define

begin_comment
comment|/* PHY Power-Down Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_PWD_TOG
value|0x0C
end_define

begin_comment
comment|/* PHY Power-Down Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_TX
value|0x10
end_define

begin_comment
comment|/* PHY Transmitter Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_RX
value|0x20
end_define

begin_comment
comment|/* PHY Receiver Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_RX_SET
value|0x24
end_define

begin_comment
comment|/* PHY Receiver Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_RX_CLR
value|0x28
end_define

begin_comment
comment|/* PHY Receiver Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_RX_TOG
value|0x2C
end_define

begin_comment
comment|/* PHY Receiver Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_CTRL
value|0x30
end_define

begin_comment
comment|/* PHY General Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_CTRL_SET
value|0x34
end_define

begin_comment
comment|/* PHY General Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_CTRL_CLR
value|0x38
end_define

begin_comment
comment|/* PHY General Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_CTRL_TOG
value|0x3C
end_define

begin_comment
comment|/* PHY General Control Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_STATUS
value|0x40
end_define

begin_comment
comment|/* PHY Status Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG
value|0x50
end_define

begin_comment
comment|/* PHY Debug Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG_SET
value|0x54
end_define

begin_comment
comment|/* PHY Debug Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG_CLR
value|0x58
end_define

begin_comment
comment|/* PHY Debug Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG_TOG
value|0x5C
end_define

begin_comment
comment|/* PHY Debug Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG0_STATUS
value|0x60
end_define

begin_comment
comment|/* UTMI Debug Status Register 0 */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG1
value|0x70
end_define

begin_comment
comment|/* UTMI Debug Status Register 1 */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG1_SET
value|0x74
end_define

begin_comment
comment|/* UTMI Debug Status Register 1 */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG1_CLR
value|0x78
end_define

begin_comment
comment|/* UTMI Debug Status Register 1 */
end_comment

begin_define
define|#
directive|define
name|USBPHY_DEBUG1_TOG
value|0x7C
end_define

begin_comment
comment|/* UTMI Debug Status Register 1 */
end_comment

begin_define
define|#
directive|define
name|USBPHY_VERSION
value|0x80
end_define

begin_comment
comment|/* UTMI RTL Version */
end_comment

begin_define
define|#
directive|define
name|USBPHY_IP
value|0x90
end_define

begin_comment
comment|/* PHY IP Block Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_IP_SET
value|0x94
end_define

begin_comment
comment|/* PHY IP Block Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_IP_CLR
value|0x98
end_define

begin_comment
comment|/* PHY IP Block Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_IP_TOG
value|0x9C
end_define

begin_comment
comment|/* PHY IP Block Register */
end_comment

begin_define
define|#
directive|define
name|USBPHY_CTRL_SFTRST
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|USBPHY_CTRL_CLKGATE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|USBPHY_DEBUG_CLKGATE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PHY_READ4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_space_read_4(_sc->bst_phy, _sc->bsh_phy, _reg)
end_define

begin_define
define|#
directive|define
name|PHY_WRITE4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_4(_sc->bst_phy, _sc->bsh_phy, _reg, _val)
end_define

begin_define
define|#
directive|define
name|USBC_READ4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_space_read_4(_sc->bst_usbc, _sc->bsh_usbc, _reg)
end_define

begin_define
define|#
directive|define
name|USBC_WRITE4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_4(_sc->bst_usbc, _sc->bsh_usbc, _reg, _val)
end_define

begin_comment
comment|/* Forward declarations */
end_comment

begin_function_decl
specifier|static
name|int
name|vybrid_ehci_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vybrid_ehci_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|vybrid_ehci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|vybrid_ehci_softc
block|{
name|ehci_softc_t
name|base
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
index|[
literal|6
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst_phy
decl_stmt|;
name|bus_space_handle_t
name|bsh_phy
decl_stmt|;
name|bus_space_tag_t
name|bst_usbc
decl_stmt|;
name|bus_space_handle_t
name|bsh_usbc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|vybrid_ehci_spec
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
name|SYS_RES_MEMORY
block|,
literal|1
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_MEMORY
block|,
literal|2
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

begin_decl_stmt
specifier|static
name|device_method_t
name|ehci_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|vybrid_ehci_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|vybrid_ehci_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|vybrid_ehci_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_suspend
argument_list|,
name|bus_generic_suspend
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_resume
argument_list|,
name|bus_generic_resume
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|bus_generic_shutdown
argument_list|)
block|,
comment|/* Bus interface */
name|DEVMETHOD
argument_list|(
name|bus_print_child
argument_list|,
name|bus_generic_print_child
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

begin_comment
comment|/* kobj_class definition */
end_comment

begin_decl_stmt
specifier|static
name|driver_t
name|ehci_driver
init|=
block|{
literal|"ehci"
block|,
name|ehci_methods
block|,
expr|sizeof
operator|(
name|ehci_softc_t
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|ehci_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ehci
argument_list|,
name|simplebus
argument_list|,
name|ehci_driver
argument_list|,
name|ehci_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ehci
argument_list|,
name|usb
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Public methods  */
end_comment

begin_function
specifier|static
name|int
name|vybrid_ehci_probe
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
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"fsl,mvf600-usb-ehci"
argument_list|)
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
literal|"Vybrid Family integrated USB controller"
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
name|phy_init
parameter_list|(
name|struct
name|vybrid_ehci_softc
modifier|*
name|esc
parameter_list|)
block|{
name|device_t
name|sc_gpio_dev
decl_stmt|;
name|int
name|reg
decl_stmt|;
comment|/* Reset phy */
name|reg
operator|=
name|PHY_READ4
argument_list|(
name|esc
argument_list|,
name|USBPHY_CTRL
argument_list|)
expr_stmt|;
name|reg
operator||=
operator|(
name|USBPHY_CTRL_SFTRST
operator|)
expr_stmt|;
name|PHY_WRITE4
argument_list|(
name|esc
argument_list|,
name|USBPHY_CTRL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Minimum reset time */
name|DELAY
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|USBPHY_CTRL_SFTRST
operator||
name|USBPHY_CTRL_CLKGATE
operator|)
expr_stmt|;
name|PHY_WRITE4
argument_list|(
name|esc
argument_list|,
name|USBPHY_CTRL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
operator|(
name|ENUTMILEVEL2
operator||
name|ENUTMILEVEL3
operator|)
expr_stmt|;
name|PHY_WRITE4
argument_list|(
name|esc
argument_list|,
name|USBPHY_CTRL_SET
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Get the GPIO device, we need this to give power to USB */
name|sc_gpio_dev
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
name|sc_gpio_dev
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|esc
operator|->
name|dev
argument_list|,
literal|"Error: failed to get the GPIO dev\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* Give power to USB */
name|GPIO_PIN_SETFLAGS
argument_list|(
name|sc_gpio_dev
argument_list|,
name|GPIO_USB_PWR
argument_list|,
name|GPIO_PIN_OUTPUT
argument_list|)
expr_stmt|;
name|GPIO_PIN_SET
argument_list|(
name|sc_gpio_dev
argument_list|,
name|GPIO_USB_PWR
argument_list|,
name|GPIO_PIN_HIGH
argument_list|)
expr_stmt|;
comment|/* Power up PHY */
name|PHY_WRITE4
argument_list|(
name|esc
argument_list|,
name|USBPHY_PWD
argument_list|,
literal|0x00
argument_list|)
expr_stmt|;
comment|/* Ungate clocks */
name|reg
operator|=
name|PHY_READ4
argument_list|(
name|esc
argument_list|,
name|USBPHY_DEBUG
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|USBPHY_DEBUG_CLKGATE
operator|)
expr_stmt|;
name|PHY_WRITE4
argument_list|(
name|esc
argument_list|,
name|USBPHY_DEBUG
argument_list|,
name|reg
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|printf("USBPHY_CTRL == 0x%08x\n", 	    PHY_READ4(esc, USBPHY_CTRL)); 	printf("USBPHY_IP == 0x%08x\n", 	    PHY_READ4(esc, USBPHY_IP)); 	printf("USBPHY_STATUS == 0x%08x\n", 	    PHY_READ4(esc, USBPHY_STATUS)); 	printf("USBPHY_DEBUG == 0x%08x\n", 	    PHY_READ4(esc, USBPHY_DEBUG)); 	printf("USBPHY_DEBUG0_STATUS == 0x%08x\n", 	    PHY_READ4(esc, USBPHY_DEBUG0_STATUS)); 	printf("USBPHY_DEBUG1 == 0x%08x\n", 	    PHY_READ4(esc, USBPHY_DEBUG1));
endif|#
directive|endif
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
name|vybrid_ehci_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|vybrid_ehci_softc
modifier|*
name|esc
decl_stmt|;
name|ehci_softc_t
modifier|*
name|sc
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|int
name|err
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|esc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|esc
operator|->
name|dev
operator|=
name|dev
expr_stmt|;
name|sc
operator|=
operator|&
name|esc
operator|->
name|base
expr_stmt|;
name|sc
operator|->
name|sc_bus
operator|.
name|parent
operator|=
name|dev
expr_stmt|;
name|sc
operator|->
name|sc_bus
operator|.
name|devices
operator|=
name|sc
operator|->
name|sc_devices
expr_stmt|;
name|sc
operator|->
name|sc_bus
operator|.
name|devices_max
operator|=
name|EHCI_MAX_DEVICES
expr_stmt|;
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|vybrid_ehci_spec
argument_list|,
name|esc
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
comment|/* EHCI registers */
name|sc
operator|->
name|sc_io_tag
operator|=
name|rman_get_bustag
argument_list|(
name|esc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|bsh
operator|=
name|rman_get_bushandle
argument_list|(
name|esc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_io_size
operator|=
name|rman_get_size
argument_list|(
name|esc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|esc
operator|->
name|bst_usbc
operator|=
name|rman_get_bustag
argument_list|(
name|esc
operator|->
name|res
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|esc
operator|->
name|bsh_usbc
operator|=
name|rman_get_bushandle
argument_list|(
name|esc
operator|->
name|res
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|esc
operator|->
name|bst_phy
operator|=
name|rman_get_bustag
argument_list|(
name|esc
operator|->
name|res
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|esc
operator|->
name|bsh_phy
operator|=
name|rman_get_bushandle
argument_list|(
name|esc
operator|->
name|res
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|/* get all DMA memory */
if|if
condition|(
name|usb_bus_mem_alloc_all
argument_list|(
operator|&
name|sc
operator|->
name|sc_bus
argument_list|,
name|USB_GET_DMA_TAG
argument_list|(
name|dev
argument_list|)
argument_list|,
operator|&
name|ehci_iterate_hw_softc
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|#
directive|if
literal|0
block|printf("USBx_HCSPARAMS is 0x%08x\n", 	    bus_space_read_4(sc->sc_io_tag, bsh, USB_HCSPARAMS)); 	printf("USB_ID == 0x%08x\n", 	    bus_space_read_4(sc->sc_io_tag, bsh, USB_ID)); 	printf("USB_HWGENERAL == 0x%08x\n", 	    bus_space_read_4(sc->sc_io_tag, bsh, USB_HWGENERAL)); 	printf("USB_HWHOST == 0x%08x\n", 	    bus_space_read_4(sc->sc_io_tag, bsh, USB_HWHOST)); 	printf("USB_HWDEVICE == 0x%08x\n", 	    bus_space_read_4(sc->sc_io_tag, bsh, USB_HWDEVICE)); 	printf("USB_HWTXBUF == 0x%08x\n", 	    bus_space_read_4(sc->sc_io_tag, bsh, USB_HWTXBUF)); 	printf("USB_HWRXBUF == 0x%08x\n", 	    bus_space_read_4(sc->sc_io_tag, bsh, USB_HWRXBUF));
endif|#
directive|endif
if|if
condition|(
name|phy_init
argument_list|(
name|esc
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Could not setup PHY\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* 	 * Set handle to USB related registers subregion used by 	 * generic EHCI driver. 	 */
name|err
operator|=
name|bus_space_subregion
argument_list|(
name|sc
operator|->
name|sc_io_tag
argument_list|,
name|bsh
argument_list|,
literal|0x100
argument_list|,
name|sc
operator|->
name|sc_io_size
argument_list|,
operator|&
name|sc
operator|->
name|sc_io_hdl
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
comment|/* Setup interrupt handler */
name|err
operator|=
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|esc
operator|->
name|res
index|[
literal|3
index|]
argument_list|,
name|INTR_TYPE_BIO
operator||
name|INTR_MPSAFE
argument_list|,
name|NULL
argument_list|,
operator|(
name|driver_intr_t
operator|*
operator|)
name|ehci_interrupt
argument_list|,
name|sc
argument_list|,
operator|&
name|sc
operator|->
name|sc_intr_hdl
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Could not setup irq, "
literal|"%d\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* Add USB device */
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
operator|=
name|device_add_child
argument_list|(
name|dev
argument_list|,
literal|"usbus"
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Could not add USB device\n"
argument_list|)
expr_stmt|;
name|err
operator|=
name|bus_teardown_intr
argument_list|(
name|dev
argument_list|,
name|esc
operator|->
name|res
index|[
literal|5
index|]
argument_list|,
name|sc
operator|->
name|sc_intr_hdl
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Could not tear down irq,"
literal|" %d\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|device_set_ivars
argument_list|(
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
argument_list|,
operator|&
name|sc
operator|->
name|sc_bus
argument_list|)
expr_stmt|;
name|strlcpy
argument_list|(
name|sc
operator|->
name|sc_vendor
argument_list|,
literal|"Freescale"
argument_list|,
sizeof|sizeof
argument_list|(
name|sc
operator|->
name|sc_vendor
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Set host mode */
name|reg
operator|=
name|bus_space_read_4
argument_list|(
name|sc
operator|->
name|sc_io_tag
argument_list|,
name|sc
operator|->
name|sc_io_hdl
argument_list|,
literal|0xA8
argument_list|)
expr_stmt|;
name|reg
operator||=
literal|0x3
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|sc
operator|->
name|sc_io_tag
argument_list|,
name|sc
operator|->
name|sc_io_hdl
argument_list|,
literal|0xA8
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Set flags */
name|sc
operator|->
name|sc_flags
operator||=
name|EHCI_SCFLG_SETMODE
operator||
name|EHCI_SCFLG_NORESTERM
expr_stmt|;
name|err
operator|=
name|ehci_init
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
block|{
name|sc
operator|->
name|sc_flags
operator||=
name|EHCI_SCFLG_DONEINIT
expr_stmt|;
name|err
operator|=
name|device_probe_and_attach
argument_list|(
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"USB init failed err=%d\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
name|device_delete_child
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
operator|=
name|NULL
expr_stmt|;
name|err
operator|=
name|bus_teardown_intr
argument_list|(
name|dev
argument_list|,
name|esc
operator|->
name|res
index|[
literal|5
index|]
argument_list|,
name|sc
operator|->
name|sc_intr_hdl
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Could not tear down irq,"
literal|" %d\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
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
name|vybrid_ehci_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|vybrid_ehci_softc
modifier|*
name|esc
decl_stmt|;
name|ehci_softc_t
modifier|*
name|sc
decl_stmt|;
name|int
name|err
decl_stmt|;
name|esc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|sc
operator|=
operator|&
name|esc
operator|->
name|base
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_flags
operator|&
name|EHCI_SCFLG_DONEINIT
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * only call ehci_detach() after ehci_init() 	 */
if|if
condition|(
name|sc
operator|->
name|sc_flags
operator|&
name|EHCI_SCFLG_DONEINIT
condition|)
block|{
name|ehci_detach
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_flags
operator|&=
operator|~
name|EHCI_SCFLG_DONEINIT
expr_stmt|;
block|}
comment|/* 	 * Disable interrupts that might have been switched on in 	 * ehci_init. 	 */
if|if
condition|(
name|sc
operator|->
name|sc_io_tag
operator|&&
name|sc
operator|->
name|sc_io_hdl
condition|)
name|bus_space_write_4
argument_list|(
name|sc
operator|->
name|sc_io_tag
argument_list|,
name|sc
operator|->
name|sc_io_hdl
argument_list|,
name|EHCI_USBINTR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|esc
operator|->
name|res
index|[
literal|5
index|]
operator|&&
name|sc
operator|->
name|sc_intr_hdl
condition|)
block|{
name|err
operator|=
name|bus_teardown_intr
argument_list|(
name|dev
argument_list|,
name|esc
operator|->
name|res
index|[
literal|5
index|]
argument_list|,
name|sc
operator|->
name|sc_intr_hdl
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Could not tear down irq,"
literal|" %d\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
name|sc
operator|->
name|sc_intr_hdl
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
condition|)
block|{
name|device_delete_child
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_bus
operator|.
name|bdev
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* During module unload there are lots of children leftover */
name|device_delete_children
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|bus_release_resources
argument_list|(
name|dev
argument_list|,
name|vybrid_ehci_spec
argument_list|,
name|esc
operator|->
name|res
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

