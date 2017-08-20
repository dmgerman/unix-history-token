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
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
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
file|<dev/usb/controller/dwc_otg.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/controller/dwc_otg_fdt.h>
end_include

begin_include
include|#
directive|include
file|<arm/broadcom/bcm2835/bcm2835_mbox_prop.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|ofw_compat_data
name|compat_data
index|[]
init|=
block|{
block|{
literal|"broadcom,bcm2835-usb"
block|,
literal|1
block|}
block|,
block|{
literal|"brcm,bcm2708-usb"
block|,
literal|1
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

begin_decl_stmt
specifier|static
name|device_probe_t
name|bcm283x_dwc_otg_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|device_attach_t
name|bcm283x_dwc_otg_attach
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|bcm283x_dwc_otg_probe
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
literal|"DWC OTG 2.0 integrated USB controller (bcm283x)"
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
name|bcm283x_dwc_otg_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
name|err
operator|=
name|bcm2835_mbox_set_power_state
argument_list|(
name|BCM2835_MBOX_POWER_ID_USB_HCD
argument_list|,
name|TRUE
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
literal|"failed to set power state, err=%d\n"
argument_list|,
name|err
argument_list|)
expr_stmt|;
return|return
operator|(
name|dwc_otg_attach
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
name|bcm283x_dwc_otg_methods
index|[]
init|=
block|{
comment|/* bus interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|bcm283x_dwc_otg_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|bcm283x_dwc_otg_attach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|bcm283x_dwc_otg_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_1
argument_list|(
name|bcm283x_dwcotg
argument_list|,
name|bcm283x_dwc_otg_driver
argument_list|,
name|bcm283x_dwc_otg_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|dwc_otg_fdt_softc
argument_list|)
argument_list|,
name|dwc_otg_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|bcm283x_dwcotg
argument_list|,
name|simplebus
argument_list|,
name|bcm283x_dwc_otg_driver
argument_list|,
name|bcm283x_dwc_otg_devclass
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
name|bcm283x_dwcotg
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

