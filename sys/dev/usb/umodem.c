begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: umodem.c,v 1.5 1999/01/08 11:58:25 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (augustss@carlstedt.se) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

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
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbcdc.h>
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
file|<dev/usb/usbdevs.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_quirks.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UMODEM_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|)
value|if (umodemdebug) logprintf x
end_define

begin_define
define|#
directive|define
name|DPRINTFN
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
value|if (umodemdebug>(n)) logprintf x
end_define

begin_decl_stmt
name|int
name|umodemdebug
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DPRINTFN
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|umodem_softc
block|{
name|USBBASEDEVICE
name|sc_dev
decl_stmt|;
comment|/* base device */
name|usbd_interface_handle
name|sc_ctl
decl_stmt|;
comment|/* control interface */
name|usbd_interface_handle
name|sc_data
decl_stmt|;
comment|/* data interface */
name|uByte
name|cmCaps
decl_stmt|;
name|uByte
name|acmCaps
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|umodem_intr
name|__P
argument_list|(
operator|(
name|usbd_request_handle
operator|,
name|usbd_private_handle
operator|,
name|usbd_status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|umodem_disco
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|USB_DECLARE_DRIVER
argument_list|(
name|umodem
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|USB_MATCH
argument_list|(
argument|umodem
argument_list|)
end_macro

begin_block
block|{
name|USB_MATCH_START
argument_list|(
name|umodem
argument_list|,
name|uaa
argument_list|)
expr_stmt|;
name|usb_interface_descriptor_t
modifier|*
name|id
decl_stmt|;
if|if
condition|(
operator|!
name|uaa
operator|->
name|iface
condition|)
return|return
operator|(
name|UMATCH_NONE
operator|)
return|;
name|id
operator|=
name|usbd_get_interface_descriptor
argument_list|(
name|uaa
operator|->
name|iface
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|id
operator|||
name|id
operator|->
name|bInterfaceClass
operator|!=
name|UCLASS_CDC
operator|||
name|id
operator|->
name|bInterfaceSubClass
operator|!=
name|USUBCLASS_ABSTRACT_CONTROL_MODEL
operator|||
name|id
operator|->
name|bInterfaceProtocol
operator|!=
name|UPROTO_CDC_AT
condition|)
return|return
operator|(
name|UMATCH_NONE
operator|)
return|;
return|return
operator|(
name|UMATCH_IFACECLASS_IFACESUBCLASS_IFACEPROTO
operator|)
return|;
block|}
end_block

begin_macro
name|USB_ATTACH
argument_list|(
argument|umodem
argument_list|)
end_macro

begin_block
block|{
name|USB_ATTACH_START
argument_list|(
name|umodem
argument_list|,
name|sc
argument_list|,
name|uaa
argument_list|)
expr_stmt|;
name|usbd_interface_handle
name|iface
init|=
name|uaa
operator|->
name|iface
decl_stmt|;
name|usb_interface_descriptor_t
modifier|*
name|id
decl_stmt|;
name|char
name|devinfo
index|[
literal|1024
index|]
decl_stmt|;
name|sc
operator|->
name|sc_ctl
operator|=
name|iface
expr_stmt|;
name|id
operator|=
name|usbd_get_interface_descriptor
argument_list|(
name|iface
argument_list|)
expr_stmt|;
name|usbd_devinfo
argument_list|(
name|uaa
operator|->
name|device
argument_list|,
literal|0
argument_list|,
name|devinfo
argument_list|)
expr_stmt|;
name|USB_ATTACH_SETUP
expr_stmt|;
name|printf
argument_list|(
literal|"%s: %s, iclass %d/%d\n"
argument_list|,
name|USBDEVNAME
argument_list|(
name|sc
operator|->
name|sc_dev
argument_list|)
argument_list|,
name|devinfo
argument_list|,
name|id
operator|->
name|bInterfaceClass
argument_list|,
name|id
operator|->
name|bInterfaceSubClass
argument_list|)
expr_stmt|;
name|USB_ATTACH_SUCCESS_RETURN
expr_stmt|;
block|}
end_block

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_function
specifier|static
name|int
name|umodem_detach
parameter_list|(
name|device_t
name|self
parameter_list|)
block|{
name|DPRINTF
argument_list|(
operator|(
literal|"%s: disconnected\n"
operator|,
name|USBDEVNAME
argument_list|(
name|self
argument_list|)
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|umodem
argument_list|,
name|uhub
argument_list|,
name|umodem_driver
argument_list|,
name|umodem_devclass
argument_list|,
name|usbd_driver_load
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

