begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbdivar.h,v 1.61 2001/01/18 20:28:23 jdolecek Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_comment
comment|/* From usb_mem.h */
end_comment

begin_expr_stmt
name|DECLARE_USB_DMA_T
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|usbd_xfer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usbd_pipe
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|usbd_endpoint
block|{
name|usb_endpoint_descriptor_t
modifier|*
name|edesc
decl_stmt|;
name|int
name|refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbd_bus_methods
block|{
name|usbd_status
function_decl|(
modifier|*
name|open_pipe
function_decl|)
parameter_list|(
name|struct
name|usbd_pipe
modifier|*
name|pipe
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|soft_intr
function_decl|)
parameter_list|(
name|struct
name|usbd_bus
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|do_poll
function_decl|)
parameter_list|(
name|struct
name|usbd_bus
modifier|*
parameter_list|)
function_decl|;
name|usbd_status
function_decl|(
modifier|*
name|allocm
function_decl|)
parameter_list|(
name|struct
name|usbd_bus
modifier|*
parameter_list|,
name|usb_dma_t
modifier|*
parameter_list|,
name|u_int32_t
name|bufsize
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|freem
function_decl|)
parameter_list|(
name|struct
name|usbd_bus
modifier|*
parameter_list|,
name|usb_dma_t
modifier|*
parameter_list|)
function_decl|;
name|struct
name|usbd_xfer
modifier|*
function_decl|(
modifier|*
name|allocx
function_decl|)
parameter_list|(
name|struct
name|usbd_bus
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|freex
function_decl|)
parameter_list|(
name|struct
name|usbd_bus
modifier|*
parameter_list|,
name|struct
name|usbd_xfer
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbd_pipe_methods
block|{
name|usbd_status
function_decl|(
modifier|*
name|transfer
function_decl|)
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
name|usbd_status
function_decl|(
modifier|*
name|start
function_decl|)
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|abort
function_decl|)
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|usbd_pipe_handle
name|pipe
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cleartoggle
function_decl|)
parameter_list|(
name|usbd_pipe_handle
name|pipe
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|done
function_decl|)
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbd_port
block|{
name|usb_port_status_t
name|status
decl_stmt|;
name|u_int16_t
name|power
decl_stmt|;
comment|/* mA of current on port */
name|u_int8_t
name|portno
decl_stmt|;
name|u_int8_t
name|restartcnt
decl_stmt|;
define|#
directive|define
name|USBD_RESTART_MAX
value|5
name|struct
name|usbd_device
modifier|*
name|device
decl_stmt|;
name|struct
name|usbd_device
modifier|*
name|parent
decl_stmt|;
comment|/* The ports hub */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbd_hub
block|{
name|usbd_status
function_decl|(
modifier|*
name|explore
function_decl|)
parameter_list|(
name|usbd_device_handle
name|hub
parameter_list|)
function_decl|;
name|void
modifier|*
name|hubsoftc
decl_stmt|;
name|usb_hub_descriptor_t
name|hubdesc
decl_stmt|;
name|struct
name|usbd_port
name|ports
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|usb_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/*****/
end_comment

begin_struct
struct|struct
name|usbd_bus
block|{
comment|/* Filled by HC driver */
name|USBBASEDEVICE
name|bdev
decl_stmt|;
comment|/* base device, host adapter */
name|struct
name|usbd_bus_methods
modifier|*
name|methods
decl_stmt|;
name|u_int32_t
name|pipe_size
decl_stmt|;
comment|/* size of a pipe struct */
comment|/* Filled by usb driver */
name|struct
name|usbd_device
modifier|*
name|root_hub
decl_stmt|;
name|usbd_device_handle
name|devices
index|[
name|USB_MAX_DEVICES
index|]
decl_stmt|;
name|char
name|needs_explore
decl_stmt|;
comment|/* a hub a signalled a change */
name|char
name|use_polling
decl_stmt|;
name|struct
name|usb_softc
modifier|*
name|usbctl
decl_stmt|;
name|struct
name|usb_device_stats
name|stats
decl_stmt|;
name|int
name|intr_context
decl_stmt|;
name|u_int
name|no_intrs
decl_stmt|;
name|int
name|usbrev
decl_stmt|;
comment|/* USB revision */
define|#
directive|define
name|USBREV_UNKNOWN
value|0
define|#
directive|define
name|USBREV_PRE_1_0
value|1
define|#
directive|define
name|USBREV_1_0
value|2
define|#
directive|define
name|USBREV_1_1
value|3
define|#
directive|define
name|USBREV_2_0
value|4
define|#
directive|define
name|USBREV_STR
value|{ "unknown", "pre 1.0", "1.0", "1.1" }
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
name|bus_dma_tag_t
name|dmatag
decl_stmt|;
comment|/* DMA tag */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbd_device
block|{
name|struct
name|usbd_bus
modifier|*
name|bus
decl_stmt|;
comment|/* our controller */
name|struct
name|usbd_pipe
modifier|*
name|default_pipe
decl_stmt|;
comment|/* pipe 0 */
name|u_int8_t
name|address
decl_stmt|;
comment|/* device addess */
name|u_int8_t
name|config
decl_stmt|;
comment|/* current configuration # */
name|u_int8_t
name|depth
decl_stmt|;
comment|/* distance from root hub */
name|u_int8_t
name|speed
decl_stmt|;
comment|/* low/full/high speed */
name|u_int8_t
name|self_powered
decl_stmt|;
comment|/* flag for self powered */
name|u_int16_t
name|power
decl_stmt|;
comment|/* mA the device uses */
name|int16_t
name|langid
decl_stmt|;
comment|/* language for strings */
define|#
directive|define
name|USBD_NOLANG
value|(-1)
name|usb_event_cookie_t
name|cookie
decl_stmt|;
comment|/* unique connection id */
name|struct
name|usbd_port
modifier|*
name|powersrc
decl_stmt|;
comment|/* upstream hub port, or 0 */
name|struct
name|usbd_endpoint
name|def_ep
decl_stmt|;
comment|/* for pipe 0 */
name|usb_endpoint_descriptor_t
name|def_ep_desc
decl_stmt|;
comment|/* for pipe 0 */
name|struct
name|usbd_interface
modifier|*
name|ifaces
decl_stmt|;
comment|/* array of all interfaces */
name|usb_device_descriptor_t
name|ddesc
decl_stmt|;
comment|/* device descriptor */
name|usb_config_descriptor_t
modifier|*
name|cdesc
decl_stmt|;
comment|/* full config descr */
specifier|const
name|struct
name|usbd_quirks
modifier|*
name|quirks
decl_stmt|;
comment|/* device quirks, always set */
name|struct
name|usbd_hub
modifier|*
name|hub
decl_stmt|;
comment|/* only if this is a hub */
name|device_ptr_t
modifier|*
name|subdevs
decl_stmt|;
comment|/* sub-devices, 0 terminated */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbd_interface
block|{
name|struct
name|usbd_device
modifier|*
name|device
decl_stmt|;
name|usb_interface_descriptor_t
modifier|*
name|idesc
decl_stmt|;
name|int
name|index
decl_stmt|;
name|int
name|altindex
decl_stmt|;
name|struct
name|usbd_endpoint
modifier|*
name|endpoints
decl_stmt|;
name|void
modifier|*
name|priv
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|usbd_pipe
argument_list|)
name|pipes
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbd_pipe
block|{
name|struct
name|usbd_interface
modifier|*
name|iface
decl_stmt|;
name|struct
name|usbd_device
modifier|*
name|device
decl_stmt|;
name|struct
name|usbd_endpoint
modifier|*
name|endpoint
decl_stmt|;
name|int
name|refcnt
decl_stmt|;
name|char
name|running
decl_stmt|;
name|char
name|aborting
decl_stmt|;
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|usbd_xfer
argument_list|)
name|queue
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|usbd_pipe
argument_list|)
name|next
expr_stmt|;
name|usbd_xfer_handle
name|intrxfer
decl_stmt|;
comment|/* used for repeating requests */
name|char
name|repeat
decl_stmt|;
name|int
name|interval
decl_stmt|;
name|usb_callout_t
name|abort_handle
decl_stmt|;
comment|/* Filled by HC driver. */
name|struct
name|usbd_pipe_methods
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbd_xfer
block|{
name|struct
name|usbd_pipe
modifier|*
name|pipe
decl_stmt|;
name|void
modifier|*
name|priv
decl_stmt|;
name|void
modifier|*
name|buffer
decl_stmt|;
name|u_int32_t
name|length
decl_stmt|;
name|u_int32_t
name|actlen
decl_stmt|;
name|u_int16_t
name|flags
decl_stmt|;
name|u_int32_t
name|timeout
decl_stmt|;
name|usbd_status
name|status
decl_stmt|;
name|usbd_callback
name|callback
decl_stmt|;
name|__volatile
name|char
name|done
decl_stmt|;
ifdef|#
directive|ifdef
name|DIAGNOSTIC
name|u_int32_t
name|busy_free
decl_stmt|;
define|#
directive|define
name|XFER_FREE
value|0x46524545
define|#
directive|define
name|XFER_BUSY
value|0x42555357
endif|#
directive|endif
comment|/* For control pipe */
name|usb_device_request_t
name|request
decl_stmt|;
comment|/* For isoc */
name|u_int16_t
modifier|*
name|frlengths
decl_stmt|;
name|int
name|nframes
decl_stmt|;
comment|/* For memory allocation */
name|struct
name|usbd_device
modifier|*
name|device
decl_stmt|;
name|usb_dma_t
name|dmabuf
decl_stmt|;
name|int
name|rqflags
decl_stmt|;
define|#
directive|define
name|URQ_REQUEST
value|0x01
define|#
directive|define
name|URQ_AUTO_DMABUF
value|0x10
define|#
directive|define
name|URQ_DEV_DMABUF
value|0x20
name|SIMPLEQ_ENTRY
argument_list|(
argument|usbd_xfer
argument_list|)
name|next
expr_stmt|;
name|void
modifier|*
name|hcpriv
decl_stmt|;
comment|/* private use by the HC driver */
name|usb_callout_t
name|timeout_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|usbd_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines from usb_subr.c */
end_comment

begin_function_decl
name|int
name|usbctlprint
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_delay_ms
parameter_list|(
name|usbd_bus_handle
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_reset_port
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|int
name|port
parameter_list|,
name|usb_port_status_t
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_setup_pipe
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|usbd_interface_handle
name|iface
parameter_list|,
name|struct
name|usbd_endpoint
modifier|*
parameter_list|,
name|int
parameter_list|,
name|usbd_pipe_handle
modifier|*
name|pipe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_new_device
parameter_list|(
name|device_ptr_t
name|parent
parameter_list|,
name|usbd_bus_handle
name|bus
parameter_list|,
name|int
name|depth
parameter_list|,
name|int
name|lowspeed
parameter_list|,
name|int
name|port
parameter_list|,
name|struct
name|usbd_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_remove_device
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|struct
name|usbd_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usbd_printBCD
parameter_list|(
name|char
modifier|*
name|cp
parameter_list|,
name|int
name|bcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_fill_iface_data
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|int
name|i
parameter_list|,
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_free_device
parameter_list|(
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usb_insert_transfer
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_transfer_complete
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_disconnect_port
parameter_list|(
name|struct
name|usbd_port
modifier|*
name|up
parameter_list|,
name|device_ptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines from usb.c */
end_comment

begin_function_decl
name|void
name|usb_needs_explore
parameter_list|(
name|usbd_bus_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_schedsoftintr
parameter_list|(
name|struct
name|usbd_bus
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXX This check is extremely bogus. Bad Bad Bad.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DIAGNOSTIC
argument_list|)
operator|&&
literal|0
end_if

begin_define
define|#
directive|define
name|SPLUSBCHECK
define|\
value|do { int _s = splusb(), _su = splusb(); \              if (!cold&& _s != _su) printf("SPLUSBCHECK failed 0x%x!=0x%x, %s:%d\n", \ 				   _s, _su, __FILE__, __LINE__); \ 	     splx(_s); \         } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPLUSBCHECK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Locator stuff. */
end_comment

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
file|"locators.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_elif

begin_comment
comment|/* XXX these values are used to statically bind some elements in the USB tree  * to specific driver instances. This should be somehow emulated in FreeBSD  * but can be done later on.  * The values are copied from the files.usb file in the NetBSD sources.  */
end_comment

begin_define
define|#
directive|define
name|UHUBCF_PORT_DEFAULT
value|-1
end_define

begin_define
define|#
directive|define
name|UHUBCF_CONFIGURATION_DEFAULT
value|-1
end_define

begin_define
define|#
directive|define
name|UHUBCF_INTERFACE_DEFAULT
value|-1
end_define

begin_define
define|#
directive|define
name|UHUBCF_VENDOR_DEFAULT
value|-1
end_define

begin_define
define|#
directive|define
name|UHUBCF_PRODUCT_DEFAULT
value|-1
end_define

begin_define
define|#
directive|define
name|UHUBCF_RELEASE_DEFAULT
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|UHUBCF_PORT
value|0
end_define

begin_define
define|#
directive|define
name|UHUBCF_CONFIGURATION
value|1
end_define

begin_define
define|#
directive|define
name|UHUBCF_INTERFACE
value|2
end_define

begin_define
define|#
directive|define
name|UHUBCF_VENDOR
value|3
end_define

begin_define
define|#
directive|define
name|UHUBCF_PRODUCT
value|4
end_define

begin_define
define|#
directive|define
name|UHUBCF_RELEASE
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|uhubcf_port
value|cf_loc[UHUBCF_PORT]
end_define

begin_define
define|#
directive|define
name|uhubcf_configuration
value|cf_loc[UHUBCF_CONFIGURATION]
end_define

begin_define
define|#
directive|define
name|uhubcf_interface
value|cf_loc[UHUBCF_INTERFACE]
end_define

begin_define
define|#
directive|define
name|uhubcf_vendor
value|cf_loc[UHUBCF_VENDOR]
end_define

begin_define
define|#
directive|define
name|uhubcf_product
value|cf_loc[UHUBCF_PRODUCT]
end_define

begin_define
define|#
directive|define
name|uhubcf_release
value|cf_loc[UHUBCF_RELEASE]
end_define

begin_define
define|#
directive|define
name|UHUB_UNK_PORT
value|UHUBCF_PORT_DEFAULT
end_define

begin_comment
comment|/* wildcarded 'port' */
end_comment

begin_define
define|#
directive|define
name|UHUB_UNK_CONFIGURATION
value|UHUBCF_CONFIGURATION_DEFAULT
end_define

begin_comment
comment|/* wildcarded 'configuration' */
end_comment

begin_define
define|#
directive|define
name|UHUB_UNK_INTERFACE
value|UHUBCF_INTERFACE_DEFAULT
end_define

begin_comment
comment|/* wildcarded 'interface' */
end_comment

begin_define
define|#
directive|define
name|UHUB_UNK_VENDOR
value|UHUBCF_VENDOR_DEFAULT
end_define

begin_comment
comment|/* wildcarded 'vendor' */
end_comment

begin_define
define|#
directive|define
name|UHUB_UNK_PRODUCT
value|UHUBCF_PRODUCT_DEFAULT
end_define

begin_comment
comment|/* wildcarded 'product' */
end_comment

begin_define
define|#
directive|define
name|UHUB_UNK_RELEASE
value|UHUBCF_RELEASE_DEFAULT
end_define

begin_comment
comment|/* wildcarded 'release' */
end_comment

end_unit

