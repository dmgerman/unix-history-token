begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbdi.h,v 1.28 1999/09/11 08:19:27 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (augustss@carlstedt.se) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
name|usbd_request
modifier|*
name|usbd_request_handle
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
comment|/* errors */
name|USBD_PENDING_REQUESTS
block|,
name|USBD_NOT_STARTED
block|,
name|USBD_INVAL
block|,
name|USBD_NOMEM
block|,
name|USBD_CANCELLED
block|,
name|USBD_BAD_ADDRESS
block|,
name|USBD_IN_USE
block|,
name|USBD_NO_ADDR
block|,
name|USBD_SET_ADDR_FAILED
block|,
name|USBD_NO_POWER
block|,
name|USBD_TOO_DEEP
block|,
name|USBD_IOERROR
block|,
name|USBD_NOT_CONFIGURED
block|,
name|USBD_TIMEOUT
block|,
name|USBD_SHORT_XFER
block|,
name|USBD_STALLED
block|,
name|USBD_INTERRUPTED
block|,
name|USBD_ERROR_MAX
block|,
comment|/* must be last */
block|}
name|usbd_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|usbd_lock_token
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*usbd_callback
argument_list|)
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
expr_stmt|;
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
comment|/* Request flags */
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
name|USBD_SYNCHRONOUS
value|0x08
end_define

begin_comment
comment|/* wait for completion */
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

begin_decl_stmt
name|usbd_status
name|usbd_open_pipe
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|,
name|u_int8_t
name|address
operator|,
name|u_int8_t
name|flags
operator|,
name|usbd_pipe_handle
operator|*
name|pipe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_close_pipe
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
name|pipe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_transfer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|req
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_request_handle
name|usbd_alloc_request
name|__P
argument_list|(
operator|(
name|usbd_device_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_free_request
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|reqh
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usbd_setup_request
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|reqh
operator|,
name|usbd_pipe_handle
name|pipe
operator|,
name|usbd_private_handle
name|priv
operator|,
name|void
operator|*
name|buffer
operator|,
name|u_int32_t
name|length
operator|,
name|u_int16_t
name|flags
operator|,
name|u_int32_t
name|timeout
operator|,
name|usbd_callback
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usbd_setup_default_request
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|reqh
operator|,
name|usbd_device_handle
name|dev
operator|,
name|usbd_private_handle
name|priv
operator|,
name|u_int32_t
name|timeout
operator|,
name|usb_device_request_t
operator|*
name|req
operator|,
name|void
operator|*
name|buffer
operator|,
name|u_int32_t
name|length
operator|,
name|u_int16_t
name|flags
operator|,
name|usbd_callback
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usbd_setup_isoc_request
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|reqh
operator|,
name|usbd_pipe_handle
name|pipe
operator|,
name|usbd_private_handle
name|priv
operator|,
name|u_int16_t
operator|*
name|frlengths
operator|,
name|u_int32_t
name|nframes
operator|,
name|usbd_callback
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usbd_get_request_status
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|reqh
operator|,
name|usbd_private_handle
operator|*
name|priv
operator|,
name|void
operator|*
operator|*
name|buffer
operator|,
name|u_int32_t
operator|*
name|count
operator|,
name|usbd_status
operator|*
name|status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_endpoint_descriptor_t
modifier|*
name|usbd_interface2endpoint_descriptor
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|,
name|u_int8_t
name|address
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_abort_pipe
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
name|pipe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_clear_endpoint_stall
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
name|pipe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_clear_endpoint_stall_async
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
name|pipe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_endpoint_count
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|dev
operator|,
name|u_int8_t
operator|*
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_interface_count
name|__P
argument_list|(
operator|(
name|usbd_device_handle
name|dev
operator|,
name|u_int8_t
operator|*
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_interface2device_handle
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|,
name|usbd_device_handle
operator|*
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_device2interface_handle
name|__P
argument_list|(
operator|(
name|usbd_device_handle
name|dev
operator|,
name|u_int8_t
name|ifaceno
operator|,
name|usbd_interface_handle
operator|*
name|iface
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_device_handle
name|usbd_pipe2device_handle
name|__P
argument_list|(
operator|(
name|usbd_pipe_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|usbd_alloc_buffer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|req
operator|,
name|u_int32_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usbd_free_buffer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|req
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_sync_transfer
name|__P
argument_list|(
operator|(
name|usbd_request_handle
name|req
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_open_pipe_intr
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|,
name|u_int8_t
name|address
operator|,
name|u_int8_t
name|flags
operator|,
name|usbd_pipe_handle
operator|*
name|pipe
operator|,
name|usbd_private_handle
name|priv
operator|,
name|void
operator|*
name|buffer
operator|,
name|u_int32_t
name|length
operator|,
name|usbd_callback
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_do_request
name|__P
argument_list|(
operator|(
name|usbd_device_handle
name|pipe
operator|,
name|usb_device_request_t
operator|*
name|req
operator|,
name|void
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_do_request_async
name|__P
argument_list|(
operator|(
name|usbd_device_handle
name|pipe
operator|,
name|usb_device_request_t
operator|*
name|req
operator|,
name|void
operator|*
name|data
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_do_request_flags
name|__P
argument_list|(
operator|(
name|usbd_device_handle
name|pipe
operator|,
name|usb_device_request_t
operator|*
name|req
operator|,
name|void
operator|*
name|data
operator|,
name|u_int16_t
name|flags
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_interface_descriptor_t
modifier|*
name|usbd_get_interface_descriptor
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_config_descriptor_t
modifier|*
name|usbd_get_config_descriptor
name|__P
argument_list|(
operator|(
name|usbd_device_handle
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_device_descriptor_t
modifier|*
name|usbd_get_device_descriptor
name|__P
argument_list|(
operator|(
name|usbd_device_handle
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_set_interface
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|usbd_get_no_alts
name|__P
argument_list|(
operator|(
name|usb_config_descriptor_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usbd_status
name|usbd_get_interface
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|,
name|u_int8_t
operator|*
name|aiface
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usbd_fill_deviceinfo
name|__P
argument_list|(
operator|(
name|usbd_device_handle
name|dev
operator|,
expr|struct
name|usb_device_info
operator|*
name|di
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|usbd_get_interface_altindex
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_interface_descriptor_t
modifier|*
name|usbd_find_idesc
name|__P
argument_list|(
operator|(
name|usb_config_descriptor_t
operator|*
name|cd
operator|,
name|int
name|iindex
operator|,
name|int
name|ano
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_endpoint_descriptor_t
modifier|*
name|usbd_find_edesc
name|__P
argument_list|(
operator|(
name|usb_config_descriptor_t
operator|*
name|cd
operator|,
name|int
name|ifaceidx
operator|,
name|int
name|altidx
operator|,
name|int
name|endptidx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usbd_dopoll
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|usbd_set_polling
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|,
name|int
name|on
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* for the moment disabled #define UMATCH_VENDOR_PRODUCT_REV			-14 #define UMATCH_VENDOR_PRODUCT				-13 #define UMATCH_VENDOR_DEVCLASS_DEVPROTO			-12 #define UMATCH_DEVCLASS_DEVSUBCLASS_DEVPROTO		-11 #define UMATCH_DEVCLASS_DEVSUBCLASS			-10 #define UMATCH_VENDOR_PRODUCT_REV_CONF_IFACE		 -9 #define UMATCH_VENDOR_PRODUCT_CONF_IFACE		 -8 #define UMATCH_VENDOR_IFACESUBCLASS_IFACEPROTO		 -7 #define UMATCH_VENDOR_IFACESUBCLASS			 -6 #define UMATCH_IFACECLASS_IFACESUBCLASS_IFACEPROTO	 -5 #define UMATCH_IFACECLASS_IFACESUBCLASS			 -4 #define UMATCH_IFACECLASS				 -3 #define UMATCH_IFACECLASS_GENERIC			 -2 #define UMATCH_GENERIC					 -1 #define UMATCH_NONE				      ENXIO  * For the moment we use Yes/No answers with appropriate * sorting in the config file */
end_comment

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_REV
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_DEVCLASS_DEVPROTO
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_DEVCLASS_DEVSUBCLASS_DEVPROTO
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_DEVCLASS_DEVSUBCLASS
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_REV_CONF_IFACE
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_PRODUCT_CONF_IFACE
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_IFACESUBCLASS_IFACEPROTO
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_VENDOR_IFACESUBCLASS
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_IFACESUBCLASS_IFACEPROTO
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_IFACESUBCLASS
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_IFACECLASS_GENERIC
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_GENERIC
value|0
end_define

begin_define
define|#
directive|define
name|UMATCH_NONE
value|ENXIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|usbd_devinfo
name|__P
argument_list|(
operator|(
name|usbd_device_handle
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|usbd_quirks
modifier|*
name|usbd_get_quirks
name|__P
argument_list|(
operator|(
name|usbd_device_handle
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|usb_endpoint_descriptor_t
modifier|*
name|usbd_get_endpoint_descriptor
name|__P
argument_list|(
operator|(
name|usbd_interface_handle
name|iface
operator|,
name|u_int8_t
name|address
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|usbd_errstr
name|__P
argument_list|(
operator|(
name|usbd_status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
name|int
name|usbd_driver_load
name|__P
argument_list|(
operator|(
name|module_t
name|mod
operator|,
name|int
name|what
operator|,
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|splusb
value|splbio
end_define

begin_define
define|#
directive|define
name|IPL_USB
value|IPL_BIO
end_define

begin_comment
comment|/* XXX */
end_comment

end_unit

