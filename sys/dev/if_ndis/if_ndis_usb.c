begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005  *      Bill Paul<wpaul@ee.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
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
file|<dev/usb/usbdi_util.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdevs.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_ethersubr.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/pe_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/resource_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/ntoskrnl_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/ndis_var.h>
end_include

begin_include
include|#
directive|include
file|<compat/ndis/cfg_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/if_ndis/if_ndisvar.h>
end_include

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ndis
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

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ndis
argument_list|,
name|ether
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
name|MODULE_DEPEND
argument_list|(
name|ndis
argument_list|,
name|wlan
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
name|MODULE_DEPEND
argument_list|(
name|ndis
argument_list|,
name|ndisapi
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"ndis_driver_data.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NDIS_USB_DEV_TABLE
end_ifdef

begin_function_decl
name|Static
name|int
name|ndisusb_match
parameter_list|(
name|device_ptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Static
name|int
name|ndisusb_attach
parameter_list|(
name|device_ptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Static
name|struct
name|resource_list
modifier|*
name|ndis_get_resource_list
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndisdrv_modevent
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_shutdown
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_suspend
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_resume
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|drv_data
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Static
name|device_method_t
name|ndis_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ndisusb_match
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ndisusb_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|ndis_detach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_shutdown
argument_list|,
name|ndis_shutdown
argument_list|)
block|,
comment|/* bus interface */
name|DEVMETHOD
argument_list|(
name|bus_print_child
argument_list|,
name|bus_generic_print_child
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_driver_added
argument_list|,
name|bus_generic_driver_added
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|bus_get_resource_list
argument_list|,
name|ndis_get_resource_list
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
name|Static
name|driver_t
name|ndis_driver
init|=
block|{
ifdef|#
directive|ifdef
name|NDIS_DEVNAME
name|NDIS_DEVNAME
block|,
else|#
directive|else
literal|"ndis"
block|,
endif|#
directive|endif
name|ndis_methods
block|,
expr|sizeof
operator|(
expr|struct
name|ndis_softc
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Static
name|devclass_t
name|ndis_devclass
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NDIS_MODNAME
end_ifdef

begin_define
define|#
directive|define
name|NDIS_MODNAME_OVERRIDE_USB
parameter_list|(
name|x
parameter_list|)
end_define

begin_macro
name|DRIVER_MODULE
argument_list|(
argument|x
argument_list|,
argument|usb
argument_list|,
argument|ndis_driver
argument_list|,
argument|ndis_devclass
argument_list|,
argument|ndisdrv_modevent
argument_list|,
literal|0
argument_list|)
end_macro

begin_expr_stmt
name|NDIS_MODNAME_OVERRIDE_USB
argument_list|(
name|NDIS_MODNAME
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ndis
argument_list|,
name|uhub
argument_list|,
name|ndis_driver
argument_list|,
name|ndis_devclass
argument_list|,
name|ndisdrv_modevent
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|USB_MATCH
argument_list|(
argument|ndisusb
argument_list|)
end_macro

begin_block
block|{
name|USB_MATCH_START
argument_list|(
name|ndisusb
argument_list|,
name|uaa
argument_list|)
expr_stmt|;
if|if
condition|(
name|windrv_lookup
argument_list|(
name|NULL
argument_list|,
literal|"USB Bus"
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|UMATCH_NONE
operator|)
return|;
if|if
condition|(
name|uaa
operator|->
name|iface
operator|!=
name|NULL
condition|)
return|return
operator|(
name|UMATCH_NONE
operator|)
return|;
return|return
operator|(
name|UMATCH_NONE
operator|)
return|;
block|}
end_block

begin_macro
name|USB_ATTACH
argument_list|(
argument|ndisusb
argument_list|)
end_macro

begin_block
block|{
name|USB_ATTACH_START
argument_list|(
name|ndisusb
argument_list|,
name|dummy
argument_list|,
name|uaa
argument_list|)
expr_stmt|;
name|struct
name|ndis_softc
modifier|*
name|sc
decl_stmt|;
name|driver_object
modifier|*
name|drv
decl_stmt|;
name|sc
operator|=
operator|(
expr|struct
name|ndis_softc
operator|*
operator|)
name|dummy
expr_stmt|;
name|sc
operator|->
name|ndis_dev
operator|=
name|self
expr_stmt|;
comment|/* Create PDO for this device instance */
name|drv
operator|=
name|windrv_lookup
argument_list|(
name|NULL
argument_list|,
literal|"USB Bus"
argument_list|)
expr_stmt|;
name|windrv_create_pdo
argument_list|(
name|drv
argument_list|,
name|self
argument_list|)
expr_stmt|;
if|if
condition|(
name|ndis_attach
argument_list|(
name|self
argument_list|)
operator|!=
literal|0
condition|)
name|USB_ATTACH_ERROR_RETURN
expr_stmt|;
name|USB_ATTACH_SUCCESS_RETURN
expr_stmt|;
block|}
end_block

begin_function
specifier|static
name|struct
name|resource_list
modifier|*
name|ndis_get_resource_list
parameter_list|(
name|dev
parameter_list|,
name|child
parameter_list|)
name|device_t
name|dev
decl_stmt|;
name|device_t
name|child
decl_stmt|;
block|{
name|struct
name|ndis_softc
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
return|return
operator|(
name|BUS_GET_RESOURCE_LIST
argument_list|(
name|device_get_parent
argument_list|(
name|sc
operator|->
name|ndis_dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NDIS_USB_DEV_TABLE */
end_comment

end_unit

