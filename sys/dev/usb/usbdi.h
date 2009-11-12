begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Andrew Thompson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_USBDI_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_USBDI_H_
end_define

begin_struct_decl
struct_decl|struct
name|usb_fifo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_xfer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_interface
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_endpoint
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_page_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_page_search
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_process
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_proc_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* keep in sync with usb_errstr_table */
name|USB_ERR_NORMAL_COMPLETION
init|=
literal|0
block|,
name|USB_ERR_PENDING_REQUESTS
block|,
comment|/* 1 */
name|USB_ERR_NOT_STARTED
block|,
comment|/* 2 */
name|USB_ERR_INVAL
block|,
comment|/* 3 */
name|USB_ERR_NOMEM
block|,
comment|/* 4 */
name|USB_ERR_CANCELLED
block|,
comment|/* 5 */
name|USB_ERR_BAD_ADDRESS
block|,
comment|/* 6 */
name|USB_ERR_BAD_BUFSIZE
block|,
comment|/* 7 */
name|USB_ERR_BAD_FLAG
block|,
comment|/* 8 */
name|USB_ERR_NO_CALLBACK
block|,
comment|/* 9 */
name|USB_ERR_IN_USE
block|,
comment|/* 10 */
name|USB_ERR_NO_ADDR
block|,
comment|/* 11 */
name|USB_ERR_NO_PIPE
block|,
comment|/* 12 */
name|USB_ERR_ZERO_NFRAMES
block|,
comment|/* 13 */
name|USB_ERR_ZERO_MAXP
block|,
comment|/* 14 */
name|USB_ERR_SET_ADDR_FAILED
block|,
comment|/* 15 */
name|USB_ERR_NO_POWER
block|,
comment|/* 16 */
name|USB_ERR_TOO_DEEP
block|,
comment|/* 17 */
name|USB_ERR_IOERROR
block|,
comment|/* 18 */
name|USB_ERR_NOT_CONFIGURED
block|,
comment|/* 19 */
name|USB_ERR_TIMEOUT
block|,
comment|/* 20 */
name|USB_ERR_SHORT_XFER
block|,
comment|/* 21 */
name|USB_ERR_STALLED
block|,
comment|/* 22 */
name|USB_ERR_INTERRUPTED
block|,
comment|/* 23 */
name|USB_ERR_DMA_LOAD_FAILED
block|,
comment|/* 24 */
name|USB_ERR_BAD_CONTEXT
block|,
comment|/* 25 */
name|USB_ERR_NO_ROOT_HUB
block|,
comment|/* 26 */
name|USB_ERR_NO_INTR_THREAD
block|,
comment|/* 27 */
name|USB_ERR_NOT_LOCKED
block|,
comment|/* 28 */
name|USB_ERR_MAX
block|}
name|usb_error_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags for transfers  */
end_comment

begin_define
define|#
directive|define
name|USB_FORCE_SHORT_XFER
value|0x0001
end_define

begin_comment
comment|/* force a short transmit last */
end_comment

begin_define
define|#
directive|define
name|USB_SHORT_XFER_OK
value|0x0004
end_define

begin_comment
comment|/* allow short reads */
end_comment

begin_define
define|#
directive|define
name|USB_DELAY_STATUS_STAGE
value|0x0010
end_define

begin_comment
comment|/* insert delay before STATUS stage */
end_comment

begin_define
define|#
directive|define
name|USB_USER_DATA_PTR
value|0x0020
end_define

begin_comment
comment|/* internal flag */
end_comment

begin_define
define|#
directive|define
name|USB_MULTI_SHORT_OK
value|0x0040
end_define

begin_comment
comment|/* allow multiple short frames */
end_comment

begin_define
define|#
directive|define
name|USB_MANUAL_STATUS
value|0x0080
end_define

begin_comment
comment|/* manual ctrl status */
end_comment

begin_define
define|#
directive|define
name|USB_NO_TIMEOUT
value|0
end_define

begin_define
define|#
directive|define
name|USB_DEFAULT_TIMEOUT
value|5000
end_define

begin_comment
comment|/* 5000 ms = 5 seconds */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_comment
comment|/* typedefs */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb_callback_t
function_decl|)
parameter_list|(
name|struct
name|usb_xfer
modifier|*
parameter_list|,
name|usb_error_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb_proc_callback_t
function_decl|)
parameter_list|(
name|struct
name|usb_proc_msg
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|usb_error_t
function_decl|(
name|usb_handle_req_t
function_decl|)
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|,
name|struct
name|usb_device_request
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|usb_fifo_open_t
function_decl|)
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|,
name|int
name|fflags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb_fifo_close_t
function_decl|)
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|,
name|int
name|fflags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|usb_fifo_ioctl_t
function_decl|)
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|fflags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb_fifo_cmd_t
function_decl|)
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb_fifo_filter_t
function_decl|)
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|,
name|struct
name|usb_mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The following macros are used used to convert milliseconds into  * HZ. We use 1024 instead of 1000 milliseconds per second to save a  * full division.  */
end_comment

begin_define
define|#
directive|define
name|USB_MS_HZ
value|1024
end_define

begin_define
define|#
directive|define
name|USB_MS_TO_TICKS
parameter_list|(
name|ms
parameter_list|)
define|\
value|(((uint32_t)((((uint32_t)(ms)) * ((uint32_t)(hz))) + USB_MS_HZ - 1)) / USB_MS_HZ)
end_define

begin_comment
comment|/*  * Common queue structure for USB transfers.  */
end_comment

begin_struct
struct|struct
name|usb_xfer_queue
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|usb_xfer
argument_list|)
name|head
expr_stmt|;
name|struct
name|usb_xfer
modifier|*
name|curr
decl_stmt|;
comment|/* current USB transfer processed */
name|void
function_decl|(
modifier|*
name|command
function_decl|)
parameter_list|(
name|struct
name|usb_xfer_queue
modifier|*
name|pq
parameter_list|)
function_decl|;
name|uint8_t
name|recurse_1
range|:
literal|1
decl_stmt|;
name|uint8_t
name|recurse_2
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB endpoint  * USB endpoint.  */
end_comment

begin_struct
struct|struct
name|usb_endpoint
block|{
name|struct
name|usb_xfer_queue
name|endpoint_q
decl_stmt|;
comment|/* queue of USB transfers */
name|struct
name|usb_endpoint_descriptor
modifier|*
name|edesc
decl_stmt|;
name|struct
name|usb_pipe_methods
modifier|*
name|methods
decl_stmt|;
comment|/* set by HC driver */
name|uint16_t
name|isoc_next
decl_stmt|;
name|uint16_t
name|refcount
decl_stmt|;
name|uint8_t
name|toggle_next
range|:
literal|1
decl_stmt|;
comment|/* next data toggle value */
name|uint8_t
name|is_stalled
range|:
literal|1
decl_stmt|;
comment|/* set if endpoint is stalled */
name|uint8_t
name|is_synced
range|:
literal|1
decl_stmt|;
comment|/* set if we a synchronised */
name|uint8_t
name|unused
range|:
literal|5
decl_stmt|;
name|uint8_t
name|iface_index
decl_stmt|;
comment|/* not used by "default endpoint" */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB interface.  */
end_comment

begin_struct
struct|struct
name|usb_interface
block|{
name|struct
name|usb_interface_descriptor
modifier|*
name|idesc
decl_stmt|;
name|device_t
name|subdev
decl_stmt|;
name|uint8_t
name|alt_index
decl_stmt|;
name|uint8_t
name|parent_iface_index
decl_stmt|;
comment|/* Linux compat */
name|struct
name|usb_host_interface
modifier|*
name|altsetting
decl_stmt|;
name|struct
name|usb_host_interface
modifier|*
name|cur_altsetting
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|linux_udev
decl_stmt|;
name|void
modifier|*
name|bsd_priv_sc
decl_stmt|;
comment|/* device specific information */
name|uint8_t
name|num_altsetting
decl_stmt|;
comment|/* number of alternate settings */
name|uint8_t
name|bsd_iface_index
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines a set of USB transfer flags.  */
end_comment

begin_struct
struct|struct
name|usb_xfer_flags
block|{
name|uint8_t
name|force_short_xfer
range|:
literal|1
decl_stmt|;
comment|/* force a short transmit transfer 					 * last */
name|uint8_t
name|short_xfer_ok
range|:
literal|1
decl_stmt|;
comment|/* allow short receive transfers */
name|uint8_t
name|short_frames_ok
range|:
literal|1
decl_stmt|;
comment|/* allow short frames */
name|uint8_t
name|pipe_bof
range|:
literal|1
decl_stmt|;
comment|/* block pipe on failure */
name|uint8_t
name|proxy_buffer
range|:
literal|1
decl_stmt|;
comment|/* makes buffer size a factor of 					 * "max_frame_size" */
name|uint8_t
name|ext_buffer
range|:
literal|1
decl_stmt|;
comment|/* uses external DMA buffer */
name|uint8_t
name|manual_status
range|:
literal|1
decl_stmt|;
comment|/* non automatic status stage on 					 * control transfers */
name|uint8_t
name|no_pipe_ok
range|:
literal|1
decl_stmt|;
comment|/* set if "USB_ERR_NO_PIPE" error can 					 * be ignored */
name|uint8_t
name|stall_pipe
range|:
literal|1
decl_stmt|;
comment|/* set if the endpoint belonging to 					 * this USB transfer should be stalled 					 * before starting this transfer! */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure define an USB configuration, that basically  * is used when setting up an USB transfer.  */
end_comment

begin_struct
struct|struct
name|usb_config
block|{
name|usb_callback_t
modifier|*
name|callback
decl_stmt|;
comment|/* USB transfer callback */
name|usb_frlength_t
name|bufsize
decl_stmt|;
comment|/* total pipe buffer size in bytes */
name|usb_frcount_t
name|frames
decl_stmt|;
comment|/* maximum number of USB frames */
name|usb_timeout_t
name|interval
decl_stmt|;
comment|/* interval in milliseconds */
define|#
directive|define
name|USB_DEFAULT_INTERVAL
value|0
name|usb_timeout_t
name|timeout
decl_stmt|;
comment|/* transfer timeout in milliseconds */
name|struct
name|usb_xfer_flags
name|flags
decl_stmt|;
comment|/* transfer flags */
name|enum
name|usb_hc_mode
name|usb_mode
decl_stmt|;
comment|/* host or device mode */
name|uint8_t
name|type
decl_stmt|;
comment|/* pipe type */
name|uint8_t
name|endpoint
decl_stmt|;
comment|/* pipe number */
name|uint8_t
name|direction
decl_stmt|;
comment|/* pipe direction */
name|uint8_t
name|ep_index
decl_stmt|;
comment|/* pipe index match to use */
name|uint8_t
name|if_index
decl_stmt|;
comment|/* "ifaces" index to use */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure is used when looking up an USB driver for  * an USB device. It is inspired by the Linux structure called  * "usb_device_id".  */
end_comment

begin_struct
struct|struct
name|usb_device_id
block|{
comment|/* Hook for driver specific information */
name|unsigned
name|long
name|driver_info
decl_stmt|;
comment|/* Used for product specific matches; the BCD range is inclusive */
name|uint16_t
name|idVendor
decl_stmt|;
name|uint16_t
name|idProduct
decl_stmt|;
name|uint16_t
name|bcdDevice_lo
decl_stmt|;
name|uint16_t
name|bcdDevice_hi
decl_stmt|;
comment|/* Used for device class matches */
name|uint8_t
name|bDeviceClass
decl_stmt|;
name|uint8_t
name|bDeviceSubClass
decl_stmt|;
name|uint8_t
name|bDeviceProtocol
decl_stmt|;
comment|/* Used for interface class matches */
name|uint8_t
name|bInterfaceClass
decl_stmt|;
name|uint8_t
name|bInterfaceSubClass
decl_stmt|;
name|uint8_t
name|bInterfaceProtocol
decl_stmt|;
comment|/* Select which fields to match against */
name|uint8_t
name|match_flag_vendor
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_product
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_lo
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_hi
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_class
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_subclass
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_protocol
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_int_class
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_int_subclass
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_int_protocol
range|:
literal|1
decl_stmt|;
if|#
directive|if
name|USB_HAVE_COMPAT_LINUX
comment|/* which fields to match against */
name|uint16_t
name|match_flags
decl_stmt|;
define|#
directive|define
name|USB_DEVICE_ID_MATCH_VENDOR
value|0x0001
define|#
directive|define
name|USB_DEVICE_ID_MATCH_PRODUCT
value|0x0002
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_LO
value|0x0004
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_HI
value|0x0008
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_CLASS
value|0x0010
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_SUBCLASS
value|0x0020
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_PROTOCOL
value|0x0040
define|#
directive|define
name|USB_DEVICE_ID_MATCH_INT_CLASS
value|0x0080
define|#
directive|define
name|USB_DEVICE_ID_MATCH_INT_SUBCLASS
value|0x0100
define|#
directive|define
name|USB_DEVICE_ID_MATCH_INT_PROTOCOL
value|0x0200
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_VENDOR
parameter_list|(
name|vend
parameter_list|)
define|\
value|.match_flag_vendor = 1, .idVendor = (vend)
end_define

begin_define
define|#
directive|define
name|USB_PRODUCT
parameter_list|(
name|prod
parameter_list|)
define|\
value|.match_flag_product = 1, .idProduct = (prod)
end_define

begin_define
define|#
directive|define
name|USB_VP
parameter_list|(
name|vend
parameter_list|,
name|prod
parameter_list|)
define|\
value|USB_VENDOR(vend), USB_PRODUCT(prod)
end_define

begin_define
define|#
directive|define
name|USB_VPI
parameter_list|(
name|vend
parameter_list|,
name|prod
parameter_list|,
name|info
parameter_list|)
define|\
value|USB_VENDOR(vend), USB_PRODUCT(prod), USB_DRIVER_INFO(info)
end_define

begin_define
define|#
directive|define
name|USB_DEV_BCD_GTEQ
parameter_list|(
name|lo
parameter_list|)
comment|/* greater than or equal */
define|\
value|.match_flag_dev_lo = 1, .bcdDevice_lo = (lo)
end_define

begin_define
define|#
directive|define
name|USB_DEV_BCD_LTEQ
parameter_list|(
name|hi
parameter_list|)
comment|/* less than or equal */
define|\
value|.match_flag_dev_hi = 1, .bcdDevice_hi = (hi)
end_define

begin_define
define|#
directive|define
name|USB_DEV_CLASS
parameter_list|(
name|dc
parameter_list|)
define|\
value|.match_flag_dev_class = 1, .bDeviceClass = (dc)
end_define

begin_define
define|#
directive|define
name|USB_DEV_SUBCLASS
parameter_list|(
name|dsc
parameter_list|)
define|\
value|.match_flag_dev_subclass = 1, .bDeviceSubClass = (dsc)
end_define

begin_define
define|#
directive|define
name|USB_DEV_PROTOCOL
parameter_list|(
name|dp
parameter_list|)
define|\
value|.match_flag_dev_protocol = 1, .bDeviceProtocol = (dp)
end_define

begin_define
define|#
directive|define
name|USB_IFACE_CLASS
parameter_list|(
name|ic
parameter_list|)
define|\
value|.match_flag_int_class = 1, .bInterfaceClass = (ic)
end_define

begin_define
define|#
directive|define
name|USB_IFACE_SUBCLASS
parameter_list|(
name|isc
parameter_list|)
define|\
value|.match_flag_int_subclass = 1, .bInterfaceSubClass = (isc)
end_define

begin_define
define|#
directive|define
name|USB_IFACE_PROTOCOL
parameter_list|(
name|ip
parameter_list|)
define|\
value|.match_flag_int_protocol = 1, .bInterfaceProtocol = (ip)
end_define

begin_define
define|#
directive|define
name|USB_IF_CSI
parameter_list|(
name|class
parameter_list|,
name|subclass
parameter_list|,
name|info
parameter_list|)
define|\
value|USB_IFACE_CLASS(class), USB_IFACE_SUBCLASS(subclass), USB_DRIVER_INFO(info)
end_define

begin_define
define|#
directive|define
name|USB_DRIVER_INFO
parameter_list|(
name|n
parameter_list|)
define|\
value|.driver_info = (n)
end_define

begin_define
define|#
directive|define
name|USB_GET_DRIVER_INFO
parameter_list|(
name|did
parameter_list|)
define|\
value|(did)->driver_info
end_define

begin_comment
comment|/*  * The following structure keeps information that is used to match  * against an array of "usb_device_id" elements.  */
end_comment

begin_struct
struct|struct
name|usbd_lookup_info
block|{
name|uint16_t
name|idVendor
decl_stmt|;
name|uint16_t
name|idProduct
decl_stmt|;
name|uint16_t
name|bcdDevice
decl_stmt|;
name|uint8_t
name|bDeviceClass
decl_stmt|;
name|uint8_t
name|bDeviceSubClass
decl_stmt|;
name|uint8_t
name|bDeviceProtocol
decl_stmt|;
name|uint8_t
name|bInterfaceClass
decl_stmt|;
name|uint8_t
name|bInterfaceSubClass
decl_stmt|;
name|uint8_t
name|bInterfaceProtocol
decl_stmt|;
name|uint8_t
name|bIfaceIndex
decl_stmt|;
name|uint8_t
name|bIfaceNum
decl_stmt|;
name|uint8_t
name|bConfigIndex
decl_stmt|;
name|uint8_t
name|bConfigNum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure used by probe and attach */
end_comment

begin_struct
struct|struct
name|usb_attach_arg
block|{
name|struct
name|usbd_lookup_info
name|info
decl_stmt|;
name|device_t
name|temp_dev
decl_stmt|;
comment|/* for internal use */
name|unsigned
name|long
name|driver_info
decl_stmt|;
comment|/* for internal use */
name|void
modifier|*
name|driver_ivar
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|device
decl_stmt|;
comment|/* current device */
name|struct
name|usb_interface
modifier|*
name|iface
decl_stmt|;
comment|/* current interface */
name|enum
name|usb_hc_mode
name|usb_mode
decl_stmt|;
comment|/* host or device mode */
name|uint8_t
name|port
decl_stmt|;
name|uint8_t
name|use_generic
decl_stmt|;
comment|/* hint for generic drivers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following is a wrapper for the callout structure to ease  * porting the code to other platforms.  */
end_comment

begin_struct
struct|struct
name|usb_callout
block|{
name|struct
name|callout
name|co
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|usb_callout_init_mtx
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|,
name|f
parameter_list|)
value|callout_init_mtx(&(c)->co,m,f)
end_define

begin_define
define|#
directive|define
name|usb_callout_reset
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|d
parameter_list|)
value|callout_reset(&(c)->co,t,f,d)
end_define

begin_define
define|#
directive|define
name|usb_callout_stop
parameter_list|(
name|c
parameter_list|)
value|callout_stop(&(c)->co)
end_define

begin_define
define|#
directive|define
name|usb_callout_drain
parameter_list|(
name|c
parameter_list|)
value|callout_drain(&(c)->co)
end_define

begin_define
define|#
directive|define
name|usb_callout_pending
parameter_list|(
name|c
parameter_list|)
value|callout_pending(&(c)->co)
end_define

begin_comment
comment|/* USB transfer states */
end_comment

begin_define
define|#
directive|define
name|USB_ST_SETUP
value|0
end_define

begin_define
define|#
directive|define
name|USB_ST_TRANSFERRED
value|1
end_define

begin_define
define|#
directive|define
name|USB_ST_ERROR
value|2
end_define

begin_comment
comment|/* USB handle request states */
end_comment

begin_define
define|#
directive|define
name|USB_HR_NOT_COMPLETE
value|0
end_define

begin_define
define|#
directive|define
name|USB_HR_COMPLETE_OK
value|1
end_define

begin_define
define|#
directive|define
name|USB_HR_COMPLETE_ERR
value|2
end_define

begin_comment
comment|/*  * The following macro will return the current state of an USB  * transfer like defined by the "USB_ST_XXX" enums.  */
end_comment

begin_define
define|#
directive|define
name|USB_GET_STATE
parameter_list|(
name|xfer
parameter_list|)
value|(usbd_xfer_state(xfer))
end_define

begin_comment
comment|/*  * The following structure defines the USB process message header.  */
end_comment

begin_struct
struct|struct
name|usb_proc_msg
block|{
name|TAILQ_ENTRY
argument_list|(
argument|usb_proc_msg
argument_list|)
name|pm_qentry
expr_stmt|;
name|usb_proc_callback_t
modifier|*
name|pm_callback
decl_stmt|;
name|usb_size_t
name|pm_num
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_FIFO_TX
value|0
end_define

begin_define
define|#
directive|define
name|USB_FIFO_RX
value|1
end_define

begin_comment
comment|/*  * Locking note for the following functions.  All the  * "usb_fifo_cmd_t" and "usb_fifo_filter_t" functions are called  * locked. The others are called unlocked.  */
end_comment

begin_struct
struct|struct
name|usb_fifo_methods
block|{
name|usb_fifo_open_t
modifier|*
name|f_open
decl_stmt|;
name|usb_fifo_close_t
modifier|*
name|f_close
decl_stmt|;
name|usb_fifo_ioctl_t
modifier|*
name|f_ioctl
decl_stmt|;
comment|/* 	 * NOTE: The post-ioctl callback is called after the USB reference 	 * gets locked in the IOCTL handler: 	 */
name|usb_fifo_ioctl_t
modifier|*
name|f_ioctl_post
decl_stmt|;
name|usb_fifo_cmd_t
modifier|*
name|f_start_read
decl_stmt|;
name|usb_fifo_cmd_t
modifier|*
name|f_stop_read
decl_stmt|;
name|usb_fifo_cmd_t
modifier|*
name|f_start_write
decl_stmt|;
name|usb_fifo_cmd_t
modifier|*
name|f_stop_write
decl_stmt|;
name|usb_fifo_filter_t
modifier|*
name|f_filter_read
decl_stmt|;
name|usb_fifo_filter_t
modifier|*
name|f_filter_write
decl_stmt|;
specifier|const
name|char
modifier|*
name|basename
index|[
literal|4
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|postfix
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_fifo_sc
block|{
name|struct
name|usb_fifo
modifier|*
name|fp
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|cdev
modifier|*
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|char
modifier|*
name|usbd_errstr
parameter_list|(
name|usb_error_t
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usbd_find_descriptor
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|void
modifier|*
name|id
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint8_t
name|type
parameter_list|,
name|uint8_t
name|type_mask
parameter_list|,
name|uint8_t
name|subtype
parameter_list|,
name|uint8_t
name|subtype_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_config_descriptor
modifier|*
name|usbd_get_config_descriptor
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_device_descriptor
modifier|*
name|usbd_get_device_descriptor
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_interface
modifier|*
name|usbd_get_iface
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_interface_descriptor
modifier|*
name|usbd_get_interface_descriptor
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_endpoint
modifier|*
name|usbd_get_endpoint
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
specifier|const
name|struct
name|usb_config
modifier|*
name|setup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_endpoint
modifier|*
name|usbd_get_ep_by_addr
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|ea_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usbd_interface_count
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|usb_hc_mode
name|usbd_get_mode
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|usb_dev_speed
name|usbd_get_speed
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_usb_desc
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_pause_mtx
parameter_list|(
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|int
name|_ticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|usb_device_id
modifier|*
name|usbd_lookup_id_by_info
parameter_list|(
specifier|const
name|struct
name|usb_device_id
modifier|*
name|id
parameter_list|,
name|usb_size_t
name|sizeof_id
parameter_list|,
specifier|const
name|struct
name|usbd_lookup_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usbd_lookup_id_by_uaa
parameter_list|(
specifier|const
name|struct
name|usb_device_id
modifier|*
name|id
parameter_list|,
name|usb_size_t
name|sizeof_id
parameter_list|,
name|struct
name|usb_attach_arg
modifier|*
name|uaa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usbd_do_request_flags
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|struct
name|usb_device_request
modifier|*
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|uint16_t
modifier|*
name|actlen
parameter_list|,
name|usb_timeout_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|usbd_do_request
parameter_list|(
name|u
parameter_list|,
name|m
parameter_list|,
name|r
parameter_list|,
name|d
parameter_list|)
define|\
value|usbd_do_request_flags(u,m,r,d,0,NULL,USB_DEFAULT_TIMEOUT)
end_define

begin_function_decl
name|uint8_t
name|usbd_clear_stall_callback
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer1
parameter_list|,
name|struct
name|usb_xfer
modifier|*
name|xfer2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usbd_get_interface_altindex
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usbd_set_alt_interface_index
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint8_t
name|alt_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|usbd_get_isoc_fps
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usbd_transfer_setup
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|ifaces
parameter_list|,
name|struct
name|usb_xfer
modifier|*
modifier|*
name|pxfer
parameter_list|,
specifier|const
name|struct
name|usb_config
modifier|*
name|setup_start
parameter_list|,
name|uint16_t
name|n_setup
parameter_list|,
name|void
modifier|*
name|priv_sc
parameter_list|,
name|struct
name|mtx
modifier|*
name|priv_mtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_transfer_submit
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_transfer_clear_stall
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_transfer_drain
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usbd_transfer_pending
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_transfer_start
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_transfer_stop
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_transfer_unsetup
parameter_list|(
name|struct
name|usb_xfer
modifier|*
modifier|*
name|pxfer
parameter_list|,
name|uint16_t
name|n_setup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_transfer_poll
parameter_list|(
name|struct
name|usb_xfer
modifier|*
modifier|*
name|ppxfer
parameter_list|,
name|uint16_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_set_parent_iface
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint8_t
name|parent_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usbd_get_bus_index
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usbd_get_device_index
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_set_power_mode
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|power_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usbd_device_attached
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_status
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|int
modifier|*
name|actlen
parameter_list|,
name|int
modifier|*
name|sumlen
parameter_list|,
name|int
modifier|*
name|aframes
parameter_list|,
name|int
modifier|*
name|nframes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_page_cache
modifier|*
name|usbd_xfer_get_frame
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|usb_frcount_t
name|frindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usbd_xfer_softc
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usbd_xfer_get_priv
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_priv
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_interval
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usbd_xfer_state
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_frame_data
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|usb_frcount_t
name|frindex
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_frame_data
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|usb_frcount_t
name|frindex
parameter_list|,
name|void
modifier|*
modifier|*
name|ptr
parameter_list|,
name|int
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_frame_offset
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
name|usb_frcount_t
name|frindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_frlength_t
name|usbd_xfer_max_len
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_frlength_t
name|usbd_xfer_max_framelen
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_frcount_t
name|usbd_xfer_max_frames
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usbd_xfer_get_fps_shift
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_frlength_t
name|usbd_xfer_frame_len
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|usb_frcount_t
name|frindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_frame_len
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|usb_frcount_t
name|frindex
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_timeout
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_frames
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|usb_frcount_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_stall
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usbd_xfer_is_stalled
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_set_flag
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_xfer_clr_flag
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|usbd_xfer_get_timestamp
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_copy_in
parameter_list|(
name|struct
name|usb_page_cache
modifier|*
name|cache
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usbd_copy_in_user
parameter_list|(
name|struct
name|usb_page_cache
modifier|*
name|cache
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_copy_out
parameter_list|(
name|struct
name|usb_page_cache
modifier|*
name|cache
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usbd_copy_out_user
parameter_list|(
name|struct
name|usb_page_cache
modifier|*
name|cache
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_get_page
parameter_list|(
name|struct
name|usb_page_cache
modifier|*
name|pc
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
name|struct
name|usb_page_search
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_m_copy_in
parameter_list|(
name|struct
name|usb_page_cache
modifier|*
name|cache
parameter_list|,
name|usb_frlength_t
name|dst_offset
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|usb_size_t
name|src_offset
parameter_list|,
name|usb_frlength_t
name|src_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_frame_zero
parameter_list|(
name|struct
name|usb_page_cache
modifier|*
name|cache
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_fifo_attach
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|void
modifier|*
name|priv_sc
parameter_list|,
name|struct
name|mtx
modifier|*
name|priv_mtx
parameter_list|,
name|struct
name|usb_fifo_methods
modifier|*
name|pm
parameter_list|,
name|struct
name|usb_fifo_sc
modifier|*
name|f_sc
parameter_list|,
name|uint16_t
name|unit
parameter_list|,
name|uint16_t
name|subunit
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_detach
parameter_list|(
name|struct
name|usb_fifo_sc
modifier|*
name|f_sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_fifo_alloc_buffer
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|f
parameter_list|,
name|uint32_t
name|bufsize
parameter_list|,
name|uint16_t
name|nbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_free_buffer
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|usb_fifo_put_bytes_max
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_put_data
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|,
name|struct
name|usb_page_cache
modifier|*
name|pc
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|,
name|uint8_t
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_put_data_linear
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|usb_size_t
name|len
parameter_list|,
name|uint8_t
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb_fifo_put_data_buffer
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|usb_size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_put_data_error
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb_fifo_get_data
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|,
name|struct
name|usb_page_cache
modifier|*
name|pc
parameter_list|,
name|usb_frlength_t
name|offset
parameter_list|,
name|usb_frlength_t
name|len
parameter_list|,
name|usb_frlength_t
modifier|*
name|actlen
parameter_list|,
name|uint8_t
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb_fifo_get_data_linear
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|usb_size_t
name|len
parameter_list|,
name|usb_size_t
modifier|*
name|actlen
parameter_list|,
name|uint8_t
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb_fifo_get_data_buffer
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|f
parameter_list|,
name|void
modifier|*
modifier|*
name|pptr
parameter_list|,
name|usb_size_t
modifier|*
name|plen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_reset
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_wakeup
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_get_data_error
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usb_fifo_softc
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_set_close_zlp
parameter_list|(
name|struct
name|usb_fifo
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_set_write_defrag
parameter_list|(
name|struct
name|usb_fifo
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fifo_free
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_USBDI_H_ */
end_comment

end_unit

