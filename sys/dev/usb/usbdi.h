begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbdi.h,v 1.48 2001/01/21 19:00:06 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|usbd_bus
modifier|*
name|usbd_bus_handle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|usbd_device
modifier|*
name|usbd_device_handle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|usbd_interface
modifier|*
name|usbd_interface_handle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|usbd_pipe
modifier|*
name|usbd_pipe_handle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|usbd_xfer
modifier|*
name|usbd_xfer_handle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|usbd_private_handle
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* keep in sync with usbd_status_msgs */
name|USBD_NORMAL_COMPLETION
init|=
literal|0
block|,
comment|/* must be 0 */
name|USBD_IN_PROGRESS
block|,
comment|/* 1 */
comment|/* errors */
name|USBD_PENDING_REQUESTS
block|,
comment|/* 2 */
name|USBD_NOT_STARTED
block|,
comment|/* 3 */
name|USBD_INVAL
block|,
comment|/* 4 */
name|USBD_NOMEM
block|,
comment|/* 5 */
name|USBD_CANCELLED
block|,
comment|/* 6 */
name|USBD_BAD_ADDRESS
block|,
comment|/* 7 */
name|USBD_IN_USE
block|,
comment|/* 8 */
name|USBD_NO_ADDR
block|,
comment|/* 9 */
name|USBD_SET_ADDR_FAILED
block|,
comment|/* 10 */
name|USBD_NO_POWER
block|,
comment|/* 11 */
name|USBD_TOO_DEEP
block|,
comment|/* 12 */
name|USBD_IOERROR
block|,
comment|/* 13 */
name|USBD_NOT_CONFIGURED
block|,
comment|/* 14 */
name|USBD_TIMEOUT
block|,
comment|/* 15 */
name|USBD_SHORT_XFER
block|,
comment|/* 16 */
name|USBD_STALLED
block|,
comment|/* 17 */
name|USBD_INTERRUPTED
block|,
comment|/* 18 */
name|USBD_ERROR_MAX
comment|/* must be last */
block|}
name|usbd_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|usbd_callback
function_decl|)
parameter_list|(
name|usbd_xfer_handle
parameter_list|,
name|usbd_private_handle
parameter_list|,
name|usbd_status
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Open flags */
end_comment

begin_define
define|#
directive|define
name|USBD_EXCLUSIVE_USE
value|0x01
end_define

begin_comment
comment|/* Use default (specified by ep. desc.) interval on interrupt pipe */
end_comment

begin_define
define|#
directive|define
name|USBD_DEFAULT_INTERVAL
value|(-1)
end_define

begin_comment
comment|/* Request flags */
end_comment

begin_define
define|#
directive|define
name|USBD_NO_COPY
value|0x01
end_define

begin_comment
comment|/* do not copy data to DMA buffer */
end_comment

begin_define
define|#
directive|define
name|USBD_SYNCHRONOUS
value|0x02
end_define

begin_comment
comment|/* wait for completion */
end_comment

begin_comment
comment|/* in usb.h #define USBD_SHORT_XFER_OK	0x04*/
end_comment

begin_comment
comment|/* allow short reads */
end_comment

begin_define
define|#
directive|define
name|USBD_FORCE_SHORT_XFER
value|0x08
end_define

begin_comment
comment|/* force last short packet on write */
end_comment

begin_comment
comment|/* XXX Temporary hack XXX */
end_comment

begin_define
define|#
directive|define
name|USBD_NO_TSLEEP
value|0x80
end_define

begin_comment
comment|/* XXX use busy wait */
end_comment

begin_define
define|#
directive|define
name|USBD_NO_TIMEOUT
value|0
end_define

begin_define
define|#
directive|define
name|USBD_DEFAULT_TIMEOUT
value|5000
end_define

begin_comment
comment|/* ms = 5 s */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|USB_CDEV_MAJOR
value|108
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|usbd_status
name|usbd_open_pipe
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|,
name|u_int8_t
name|address
parameter_list|,
name|u_int8_t
name|flags
parameter_list|,
name|usbd_pipe_handle
modifier|*
name|pipe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_close_pipe
parameter_list|(
name|usbd_pipe_handle
name|pipe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_transfer
parameter_list|(
name|usbd_xfer_handle
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_xfer_handle
name|usbd_alloc_xfer
parameter_list|(
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_free_xfer
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_setup_xfer
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|,
name|usbd_pipe_handle
name|pipe
parameter_list|,
name|usbd_private_handle
name|priv
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|u_int32_t
name|length
parameter_list|,
name|u_int16_t
name|flags
parameter_list|,
name|u_int32_t
name|timeout
parameter_list|,
name|usbd_callback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_setup_default_xfer
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|,
name|usbd_device_handle
name|dev
parameter_list|,
name|usbd_private_handle
name|priv
parameter_list|,
name|u_int32_t
name|timeout
parameter_list|,
name|usb_device_request_t
modifier|*
name|req
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|u_int32_t
name|length
parameter_list|,
name|u_int16_t
name|flags
parameter_list|,
name|usbd_callback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_setup_isoc_xfer
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|,
name|usbd_pipe_handle
name|pipe
parameter_list|,
name|usbd_private_handle
name|priv
parameter_list|,
name|u_int16_t
modifier|*
name|frlengths
parameter_list|,
name|u_int32_t
name|nframes
parameter_list|,
name|u_int16_t
name|flags
parameter_list|,
name|usbd_callback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_get_xfer_status
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|,
name|usbd_private_handle
modifier|*
name|priv
parameter_list|,
name|void
modifier|*
modifier|*
name|buffer
parameter_list|,
name|u_int32_t
modifier|*
name|count
parameter_list|,
name|usbd_status
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_endpoint_descriptor_t
modifier|*
name|usbd_interface2endpoint_descriptor
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|,
name|u_int8_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_abort_pipe
parameter_list|(
name|usbd_pipe_handle
name|pipe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_clear_endpoint_stall
parameter_list|(
name|usbd_pipe_handle
name|pipe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_clear_endpoint_stall_async
parameter_list|(
name|usbd_pipe_handle
name|pipe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_clear_endpoint_toggle
parameter_list|(
name|usbd_pipe_handle
name|pipe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_endpoint_count
parameter_list|(
name|usbd_interface_handle
name|dev
parameter_list|,
name|u_int8_t
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_interface_count
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|u_int8_t
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_interface2device_handle
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|,
name|usbd_device_handle
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_device2interface_handle
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|u_int8_t
name|ifaceno
parameter_list|,
name|usbd_interface_handle
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_device_handle
name|usbd_pipe2device_handle
parameter_list|(
name|usbd_pipe_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usbd_alloc_buffer
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|,
name|u_int32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_free_buffer
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usbd_get_buffer
parameter_list|(
name|usbd_xfer_handle
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_sync_transfer
parameter_list|(
name|usbd_xfer_handle
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_open_pipe_intr
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|,
name|u_int8_t
name|address
parameter_list|,
name|u_int8_t
name|flags
parameter_list|,
name|usbd_pipe_handle
modifier|*
name|pipe
parameter_list|,
name|usbd_private_handle
name|priv
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|u_int32_t
name|length
parameter_list|,
name|usbd_callback
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_do_request
parameter_list|(
name|usbd_device_handle
name|pipe
parameter_list|,
name|usb_device_request_t
modifier|*
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_do_request_async
parameter_list|(
name|usbd_device_handle
name|pipe
parameter_list|,
name|usb_device_request_t
modifier|*
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_do_request_flags
parameter_list|(
name|usbd_device_handle
name|pipe
parameter_list|,
name|usb_device_request_t
modifier|*
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|u_int16_t
name|flags
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_do_request_flags_pipe
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|usbd_pipe_handle
name|pipe
parameter_list|,
name|usb_device_request_t
modifier|*
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|u_int16_t
name|flags
parameter_list|,
name|int
modifier|*
name|actlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_interface_descriptor_t
modifier|*
name|usbd_get_interface_descriptor
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_config_descriptor_t
modifier|*
name|usbd_get_config_descriptor
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_device_descriptor_t
modifier|*
name|usbd_get_device_descriptor
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_set_interface
parameter_list|(
name|usbd_interface_handle
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usbd_get_no_alts
parameter_list|(
name|usb_config_descriptor_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_get_interface
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|,
name|u_int8_t
modifier|*
name|aiface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_fill_deviceinfo
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|struct
name|usb_device_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usbd_get_interface_altindex
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_interface_descriptor_t
modifier|*
name|usbd_find_idesc
parameter_list|(
name|usb_config_descriptor_t
modifier|*
name|cd
parameter_list|,
name|int
name|iindex
parameter_list|,
name|int
name|ano
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_endpoint_descriptor_t
modifier|*
name|usbd_find_edesc
parameter_list|(
name|usb_config_descriptor_t
modifier|*
name|cd
parameter_list|,
name|int
name|ifaceidx
parameter_list|,
name|int
name|altidx
parameter_list|,
name|int
name|endptidx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_dopoll
parameter_list|(
name|usbd_interface_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_set_polling
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|usbd_errstr
parameter_list|(
name|usbd_status
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_add_dev_event
parameter_list|(
name|int
parameter_list|,
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_add_drv_event
parameter_list|(
name|int
parameter_list|,
name|usbd_device_handle
parameter_list|,
name|device_ptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_devinfo
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|usbd_quirks
modifier|*
name|usbd_get_quirks
parameter_list|(
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_endpoint_descriptor_t
modifier|*
name|usbd_get_endpoint_descriptor
parameter_list|(
name|usbd_interface_handle
name|iface
parameter_list|,
name|u_int8_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_reload_device_desc
parameter_list|(
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The usb_task structs form a queue of things to run in the USB event  * thread.  Normally this is just device discovery when a connect/disconnect  * has been detected.  But it may also be used by drivers that need to  * perform (short) tasks that must have a process context.  */
end_comment

begin_struct
struct|struct
name|usb_task
block|{
name|SIMPLEQ_ENTRY
argument_list|(
argument|usb_task
argument_list|)
name|next
expr_stmt|;
name|void
function_decl|(
modifier|*
name|fun
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg
decl_stmt|;
name|char
name|onqueue
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|usb_add_task
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|struct
name|usb_task
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|usb_devno
block|{
name|u_int16_t
name|ud_vendor
decl_stmt|;
name|u_int16_t
name|ud_product
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|struct
name|usb_devno
modifier|*
name|usb_match_device
parameter_list|(
specifier|const
name|struct
name|usb_devno
modifier|*
name|tbl
parameter_list|,
name|u_int
name|nentries
parameter_list|,
name|u_int
name|sz
parameter_list|,
name|u_int16_t
name|vendor
parameter_list|,
name|u_int16_t
name|product
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|usb_lookup
parameter_list|(
name|tbl
parameter_list|,
name|vendor
parameter_list|,
name|product
parameter_list|)
define|\
value|usb_match_device((const struct usb_devno *)(tbl), sizeof (tbl) / sizeof ((tbl)[0]), sizeof ((tbl)[0]), (vendor), (product))
end_define

begin_comment
comment|/* NetBSD attachment information */
end_comment

begin_comment
comment|/* Attach data */
end_comment

begin_struct
struct|struct
name|usb_attach_arg
block|{
name|int
name|port
decl_stmt|;
name|int
name|configno
decl_stmt|;
name|int
name|ifaceno
decl_stmt|;
name|int
name|vendor
decl_stmt|;
name|int
name|product
decl_stmt|;
name|int
name|release
decl_stmt|;
name|usbd_device_handle
name|device
decl_stmt|;
comment|/* current device */
name|usbd_interface_handle
name|iface
decl_stmt|;
comment|/* current interface */
name|int
name|usegeneric
decl_stmt|;
name|usbd_interface_handle
modifier|*
name|ifaces
decl_stmt|;
comment|/* all interfaces */
name|int
name|nifaces
decl_stmt|;
comment|/* number of interfaces */
block|}
struct|;
end_struct

begin_if
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
end_if

begin_comment
comment|/* Match codes. */
end_comment

begin_comment
comment|/* First five codes is for a whole device. */
end_comment

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_REV
value|14
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT
value|13
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_DEVCLASS_DEVPROTO
value|12
end_define

begin_define
define|#
directive|define
name|UMATCH_DEVCLASS_DEVSUBCLASS_DEVPROTO
value|11
end_define

begin_define
define|#
directive|define
name|UMATCH_DEVCLASS_DEVSUBCLASS
value|10
end_define

begin_comment
comment|/* Next six codes are for interfaces. */
end_comment

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_REV_CONF_IFACE
value|9
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_CONF_IFACE
value|8
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_IFACESUBCLASS_IFACEPROTO
value|7
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_IFACESUBCLASS
value|6
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_IFACESUBCLASS_IFACEPROTO
value|5
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_IFACESUBCLASS
value|4
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS
value|3
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_GENERIC
value|2
end_define

begin_comment
comment|/* Generic driver */
end_comment

begin_define
define|#
directive|define
name|UMATCH_GENERIC
value|1
end_define

begin_comment
comment|/* No match */
end_comment

begin_define
define|#
directive|define
name|UMATCH_NONE
value|0
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_comment
comment|/* FreeBSD needs values less than zero */
end_comment

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_REV
value|(-10)
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT
value|(-20)
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_DEVCLASS_DEVPROTO
value|(-30)
end_define

begin_define
define|#
directive|define
name|UMATCH_DEVCLASS_DEVSUBCLASS_DEVPROTO
value|(-40)
end_define

begin_define
define|#
directive|define
name|UMATCH_DEVCLASS_DEVSUBCLASS
value|(-50)
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_REV_CONF_IFACE
value|(-60)
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_CONF_IFACE
value|(-70)
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_IFACESUBCLASS_IFACEPROTO
value|(-80)
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_IFACESUBCLASS
value|(-90)
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_IFACESUBCLASS_IFACEPROTO
value|(-100)
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_IFACESUBCLASS
value|(-110)
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS
value|(-120)
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_GENERIC
value|(-130)
end_define

begin_define
define|#
directive|define
name|UMATCH_GENERIC
value|(-140)
end_define

begin_define
define|#
directive|define
name|UMATCH_NONE
value|(ENXIO)
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
name|__FreeBSD__
argument_list|)
end_if

begin_function_decl
name|int
name|usbd_driver_load
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|what
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX Perhaps USB should have its own levels? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USB_USE_SOFTINTR
end_ifdef

begin_define
define|#
directive|define
name|splusb
value|splsoftnet
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|splusb
value|splbio
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|splhardusb
value|splbio
end_define

begin_define
define|#
directive|define
name|IPL_USB
value|IPL_BIO
end_define

end_unit

