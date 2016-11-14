begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Oleksandr Tymoshenko<gonzo@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/simplebus.h>
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
file|<dev/usb/usb_core.h>
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
file|<dev/usb/usb_util.h>
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
file|<dev/usb/controller/musb_otg.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_debug.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/ti_prcm.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/ti_scm.h>
end_include

begin_include
include|#
directive|include
file|<arm/ti/am335x/am335x_scm.h>
end_include

begin_define
define|#
directive|define
name|AM335X_USB_PORTS
value|2
end_define

begin_define
define|#
directive|define
name|USBSS_REVREG
value|0x00
end_define

begin_define
define|#
directive|define
name|USBSS_SYSCONFIG
value|0x10
end_define

begin_define
define|#
directive|define
name|USBSS_SYSCONFIG_SRESET
value|1
end_define

begin_define
define|#
directive|define
name|USBCTRL_REV
value|0x00
end_define

begin_define
define|#
directive|define
name|USBCTRL_CTRL
value|0x14
end_define

begin_define
define|#
directive|define
name|USBCTRL_STAT
value|0x18
end_define

begin_define
define|#
directive|define
name|USBCTRL_IRQ_STAT0
value|0x30
end_define

begin_define
define|#
directive|define
name|IRQ_STAT0_RXSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IRQ_STAT0_TXSHIFT
value|0
end_define

begin_define
define|#
directive|define
name|USBCTRL_IRQ_STAT1
value|0x34
end_define

begin_define
define|#
directive|define
name|IRQ_STAT1_DRVVBUS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|USBCTRL_INTEN_SET0
value|0x38
end_define

begin_define
define|#
directive|define
name|USBCTRL_INTEN_SET1
value|0x3C
end_define

begin_define
define|#
directive|define
name|USBCTRL_INTEN_USB_ALL
value|0x1ff
end_define

begin_define
define|#
directive|define
name|USBCTRL_INTEN_USB_SOF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|USBCTRL_INTEN_CLR0
value|0x40
end_define

begin_define
define|#
directive|define
name|USBCTRL_INTEN_CLR1
value|0x44
end_define

begin_define
define|#
directive|define
name|USBCTRL_UTMI
value|0xE0
end_define

begin_define
define|#
directive|define
name|USBCTRL_UTMI_FSDATAEXT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|USBCTRL_MODE
value|0xE8
end_define

begin_define
define|#
directive|define
name|USBCTRL_MODE_IDDIG
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|USBCTRL_MODE_IDDIGMUX
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|USBSS_WRITE4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((sc)->sc_mem_res, (reg), (val))
end_define

begin_define
define|#
directive|define
name|USBSS_READ4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4((sc)->sc_mem_res, (reg))
end_define

begin_decl_stmt
specifier|static
name|device_probe_t
name|usbss_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_attach_t
name|usbss_attach
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_detach_t
name|usbss_detach
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|usbss_softc
block|{
name|struct
name|simplebus_softc
name|simplebus_sc
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
decl_stmt|;
name|int
name|sc_mem_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|int
name|usbss_probe
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
literal|"ti,am33xx-usb"
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
literal|"TI AM33xx integrated USB OTG controller"
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
name|usbss_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|usbss_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|int
name|i
decl_stmt|;
name|uint32_t
name|rev
decl_stmt|;
name|phandle_t
name|node
decl_stmt|;
comment|/* Request the memory resources */
name|sc
operator|->
name|sc_mem_res
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
operator|&
name|sc
operator|->
name|sc_mem_rid
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_mem_res
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Error: could not allocate mem resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Enable device clocks. */
name|ti_prcm_clk_enable
argument_list|(
name|MUSB0_CLK
argument_list|)
expr_stmt|;
comment|/* 	 * Reset USBSS, USB0 and USB1. 	 * The registers of USB subsystem must not be accessed while the 	 * reset pulse is active (200ns). 	 */
name|USBSS_WRITE4
argument_list|(
name|sc
argument_list|,
name|USBSS_SYSCONFIG
argument_list|,
name|USBSS_SYSCONFIG_SRESET
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|i
operator|=
literal|10
expr_stmt|;
while|while
condition|(
name|USBSS_READ4
argument_list|(
name|sc
argument_list|,
name|USBSS_SYSCONFIG
argument_list|)
operator|&
name|USBSS_SYSCONFIG_SRESET
condition|)
block|{
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|--
operator|==
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"reset timeout.\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
block|}
comment|/* Read the module revision. */
name|rev
operator|=
name|USBSS_READ4
argument_list|(
name|sc
argument_list|,
name|USBSS_REVREG
argument_list|)
expr_stmt|;
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"TI AM335X USBSS v%d.%d.%d\n"
argument_list|,
operator|(
name|rev
operator|>>
literal|8
operator|)
operator|&
literal|7
argument_list|,
operator|(
name|rev
operator|>>
literal|6
operator|)
operator|&
literal|3
argument_list|,
name|rev
operator|&
literal|63
argument_list|)
expr_stmt|;
name|node
operator|=
name|ofw_bus_get_node
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|==
operator|-
literal|1
condition|)
block|{
name|usbss_detach
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|simplebus_init
argument_list|(
name|dev
argument_list|,
name|node
argument_list|)
expr_stmt|;
comment|/* 	 * Allow devices to identify. 	 */
name|bus_generic_probe
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* 	 * Now walk the OFW tree and attach top-level devices. 	 */
for|for
control|(
name|node
operator|=
name|OF_child
argument_list|(
name|node
argument_list|)
init|;
name|node
operator|>
literal|0
condition|;
name|node
operator|=
name|OF_peer
argument_list|(
name|node
argument_list|)
control|)
name|simplebus_add_device
argument_list|(
name|dev
argument_list|,
name|node
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
operator|-
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|(
name|bus_generic_attach
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|usbss_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|usbss_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
comment|/* Free resources if any */
if|if
condition|(
name|sc
operator|->
name|sc_mem_res
condition|)
name|bus_release_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_MEMORY
argument_list|,
name|sc
operator|->
name|sc_mem_rid
argument_list|,
name|sc
operator|->
name|sc_mem_res
argument_list|)
expr_stmt|;
comment|/* during module unload there are lots of children leftover */
name|device_delete_children
argument_list|(
name|dev
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
name|usbss_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|usbss_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|usbss_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|usbss_detach
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
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|usbss
argument_list|,
name|usbss_driver
argument_list|,
name|usbss_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|usbss_softc
argument_list|)
argument_list|,
name|simplebus_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|usbss_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|usbss
argument_list|,
name|simplebus
argument_list|,
name|usbss_driver
argument_list|,
name|usbss_devclass
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
name|usbss
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

end_unit

