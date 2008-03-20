begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbdi.h,v 1.64 2004/10/23 13:26:34 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USBDI_H_
end_ifndef

begin_define
define|#
directive|define
name|_USBDI_H_
end_define

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

begin_define
define|#
directive|define
name|USBD_BITS
value|"\20\1NO_COPY\2SYNCHRONOUS\4FORCE_SHORT_XFER"
end_define

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

begin_function_decl
name|usbd_status
name|usbd_open_pipe
parameter_list|(
name|usbd_interface_handle
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|usbd_pipe_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_close_pipe
parameter_list|(
name|usbd_pipe_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_transfer
parameter_list|(
name|usbd_xfer_handle
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_setup_xfer
parameter_list|(
name|usbd_xfer_handle
parameter_list|,
name|usbd_pipe_handle
parameter_list|,
name|usbd_private_handle
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int32_t
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
parameter_list|,
name|usbd_device_handle
parameter_list|,
name|usbd_private_handle
parameter_list|,
name|u_int32_t
parameter_list|,
name|usb_device_request_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int16_t
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
parameter_list|,
name|usbd_pipe_handle
parameter_list|,
name|usbd_private_handle
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int16_t
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
parameter_list|,
name|usbd_private_handle
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|usbd_status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_endpoint_descriptor_t
modifier|*
name|usbd_interface2endpoint_descriptor
parameter_list|(
name|usbd_interface_handle
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_abort_pipe
parameter_list|(
name|usbd_pipe_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_abort_default_pipe
parameter_list|(
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_clear_endpoint_stall
parameter_list|(
name|usbd_pipe_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_clear_endpoint_stall_async
parameter_list|(
name|usbd_pipe_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_clear_endpoint_toggle
parameter_list|(
name|usbd_pipe_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_endpoint_count
parameter_list|(
name|usbd_interface_handle
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_interface_count
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_interface2device_handle
parameter_list|(
name|usbd_interface_handle
parameter_list|,
name|usbd_device_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_device2interface_handle
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|u_int8_t
parameter_list|,
name|usbd_interface_handle
modifier|*
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
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_free_buffer
parameter_list|(
name|usbd_xfer_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usbd_get_buffer
parameter_list|(
name|usbd_xfer_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_sync_transfer
parameter_list|(
name|usbd_xfer_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_open_pipe_intr
parameter_list|(
name|usbd_interface_handle
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|usbd_pipe_handle
modifier|*
parameter_list|,
name|usbd_private_handle
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int32_t
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
parameter_list|,
name|usb_device_request_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_do_request_async
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|usb_device_request_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_do_request_flags
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|usb_device_request_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_do_request_flags_pipe
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|usbd_pipe_handle
parameter_list|,
name|usb_device_request_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_interface_descriptor_t
modifier|*
name|usbd_get_interface_descriptor
parameter_list|(
name|usbd_interface_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_config_descriptor_t
modifier|*
name|usbd_get_config_descriptor
parameter_list|(
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_device_descriptor_t
modifier|*
name|usbd_get_device_descriptor
parameter_list|(
name|usbd_device_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usbd_get_speed
parameter_list|(
name|usbd_device_handle
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
parameter_list|,
name|u_int8_t
modifier|*
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
parameter_list|,
name|int
parameter_list|,
name|int
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
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
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
name|usbd_device_handle
parameter_list|,
name|int
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
name|device_t
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
parameter_list|,
name|u_int8_t
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

begin_function_decl
name|int
name|usbd_ratecheck
parameter_list|(
name|struct
name|timeval
modifier|*
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usbd_status
name|usbd_get_string
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|int
name|si
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* An iterator for descriptors. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|uByte
modifier|*
name|cur
decl_stmt|;
specifier|const
name|uByte
modifier|*
name|end
decl_stmt|;
block|}
name|usbd_desc_iter_t
typedef|;
end_typedef

begin_function_decl
name|void
name|usb_desc_iter_init
parameter_list|(
name|usbd_device_handle
name|dev
parameter_list|,
name|usbd_desc_iter_t
modifier|*
name|iter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|usb_descriptor_t
modifier|*
name|usb_desc_iter_next
parameter_list|(
name|usbd_desc_iter_t
modifier|*
name|iter
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
name|TAILQ_ENTRY
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
name|int
name|queue
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_TASKQ_HC
value|0
end_define

begin_define
define|#
directive|define
name|USB_TASKQ_DRIVER
value|1
end_define

begin_define
define|#
directive|define
name|USB_NUM_TASKQS
value|2
end_define

begin_define
define|#
directive|define
name|USB_TASKQ_NAMES
value|{"usbtask-hc", "usbtask-dr"}
end_define

begin_function_decl
name|void
name|usb_add_task
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|struct
name|usb_task
modifier|*
parameter_list|,
name|int
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_rem_task
parameter_list|(
name|usbd_device_handle
parameter_list|,
name|struct
name|usb_task
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|usb_init_task
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|((t)->fun = (f), (t)->arg = (a), (t)->queue = -1)
end_define

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
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
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

begin_define
define|#
directive|define
name|USB_PRODUCT_ANY
value|0xffff
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
name|int
name|matchlvl
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

begin_define
define|#
directive|define
name|USBD_SHOW_DEVICE_CLASS
value|0x1
end_define

begin_define
define|#
directive|define
name|USBD_SHOW_INTERFACE_CLASS
value|0x2
end_define

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

begin_function
specifier|static
specifier|inline
name|int
name|usb_get_port
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|usb_attach_arg
modifier|*
name|uap
init|=
name|device_get_ivars
argument_list|(
name|dev
argument_list|)
decl_stmt|;
return|return
operator|(
name|uap
operator|->
name|port
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|usbd_interface
modifier|*
name|usb_get_iface
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|usb_attach_arg
modifier|*
name|uap
init|=
name|device_get_ivars
argument_list|(
name|dev
argument_list|)
decl_stmt|;
return|return
operator|(
name|uap
operator|->
name|iface
operator|)
return|;
block|}
end_function

begin_comment
comment|/* XXX Perhaps USB should have its own levels? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USB_USE_SOFTINTR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__HAVE_GENERIC_SOFT_INTERRUPTS
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
value|splsoftclock
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HAVE_GENERIC_SOFT_INTERRUPTS */
end_comment

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

begin_comment
comment|/* USB_USE_SOFTINTR */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USBDI_H_ */
end_comment

end_unit

