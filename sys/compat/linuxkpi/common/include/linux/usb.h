begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 Luigi Rizzo - Universita` di Pisa. All rights reserved.  * Copyright (c) 2007 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_COMPAT_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|_USB_COMPAT_LINUX_H
end_define

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
name|usb_driver
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|urb
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
modifier|*
name|pm_message_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb_complete_t
function_decl|)
parameter_list|(
name|struct
name|urb
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|USB_MAX_FULL_SPEED_ISOC_FRAMES
value|(60 * 1)
end_define

begin_define
define|#
directive|define
name|USB_MAX_HIGH_SPEED_ISOC_FRAMES
value|(60 * 8)
end_define

begin_define
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEVICE
define|\
value|(USB_DEVICE_ID_MATCH_VENDOR | USB_DEVICE_ID_MATCH_PRODUCT)
end_define

begin_define
define|#
directive|define
name|USB_DEVICE
parameter_list|(
name|vend
parameter_list|,
name|prod
parameter_list|)
define|\
value|.match_flags = USB_DEVICE_ID_MATCH_DEVICE, .idVendor = (vend), \ 	.idProduct = (prod)
end_define

begin_comment
comment|/* The "usb_driver" structure holds the Linux USB device driver  * callbacks, and a pointer to device ID's which this entry should  * match against. Usually this entry is exposed to the USB emulation  * layer using the "USB_DRIVER_EXPORT()" macro, which is defined  * below.  */
end_comment

begin_struct
struct|struct
name|usb_driver
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|,
specifier|const
name|struct
name|usb_device_id
modifier|*
name|id
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|disconnect
function_decl|)
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ioctl
function_decl|)
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|,
name|unsigned
name|int
name|code
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|suspend
function_decl|)
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|,
name|pm_message_t
name|message
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|resume
function_decl|)
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|)
function_decl|;
specifier|const
name|struct
name|usb_device_id
modifier|*
name|id_table
decl_stmt|;
name|void
function_decl|(
modifier|*
name|shutdown
function_decl|)
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|)
function_decl|;
name|LIST_ENTRY
argument_list|(
argument|usb_driver
argument_list|)
name|linux_driver_list
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_DRIVER_EXPORT
parameter_list|(
name|id
parameter_list|,
name|p_usb_drv
parameter_list|)
define|\
value|SYSINIT(id,SI_SUB_KLD,SI_ORDER_FIRST,usb_linux_register,p_usb_drv); \   SYSUNINIT(id,SI_SUB_KLD,SI_ORDER_ANY,usb_linux_deregister,p_usb_drv)
end_define

begin_define
define|#
directive|define
name|USB_DT_ENDPOINT_SIZE
value|7
end_define

begin_define
define|#
directive|define
name|USB_DT_ENDPOINT_AUDIO_SIZE
value|9
end_define

begin_comment
comment|/*  * Endpoints  */
end_comment

begin_define
define|#
directive|define
name|USB_ENDPOINT_NUMBER_MASK
value|0x0f
end_define

begin_comment
comment|/* in bEndpointAddress */
end_comment

begin_define
define|#
directive|define
name|USB_ENDPOINT_DIR_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|USB_ENDPOINT_XFERTYPE_MASK
value|0x03
end_define

begin_comment
comment|/* in bmAttributes */
end_comment

begin_define
define|#
directive|define
name|USB_ENDPOINT_XFER_CONTROL
value|0
end_define

begin_define
define|#
directive|define
name|USB_ENDPOINT_XFER_ISOC
value|1
end_define

begin_define
define|#
directive|define
name|USB_ENDPOINT_XFER_BULK
value|2
end_define

begin_define
define|#
directive|define
name|USB_ENDPOINT_XFER_INT
value|3
end_define

begin_define
define|#
directive|define
name|USB_ENDPOINT_MAX_ADJUSTABLE
value|0x80
end_define

begin_comment
comment|/* CONTROL REQUEST SUPPORT */
end_comment

begin_comment
comment|/*  * Definition of direction mask for  * "bEndpointAddress" and "bmRequestType":  */
end_comment

begin_define
define|#
directive|define
name|USB_DIR_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|USB_DIR_OUT
value|0x00
end_define

begin_comment
comment|/* write to USB device */
end_comment

begin_define
define|#
directive|define
name|USB_DIR_IN
value|0x80
end_define

begin_comment
comment|/* read from USB device */
end_comment

begin_comment
comment|/*  * Definition of type mask for  * "bmRequestType":  */
end_comment

begin_define
define|#
directive|define
name|USB_TYPE_MASK
value|(0x03<< 5)
end_define

begin_define
define|#
directive|define
name|USB_TYPE_STANDARD
value|(0x00<< 5)
end_define

begin_define
define|#
directive|define
name|USB_TYPE_CLASS
value|(0x01<< 5)
end_define

begin_define
define|#
directive|define
name|USB_TYPE_VENDOR
value|(0x02<< 5)
end_define

begin_define
define|#
directive|define
name|USB_TYPE_RESERVED
value|(0x03<< 5)
end_define

begin_comment
comment|/*  * Definition of receiver mask for  * "bmRequestType":  */
end_comment

begin_define
define|#
directive|define
name|USB_RECIP_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|USB_RECIP_DEVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|USB_RECIP_INTERFACE
value|0x01
end_define

begin_define
define|#
directive|define
name|USB_RECIP_ENDPOINT
value|0x02
end_define

begin_define
define|#
directive|define
name|USB_RECIP_OTHER
value|0x03
end_define

begin_comment
comment|/*  * Definition of standard request values for  * "bRequest":  */
end_comment

begin_define
define|#
directive|define
name|USB_REQ_GET_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|USB_REQ_CLEAR_FEATURE
value|0x01
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_FEATURE
value|0x03
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_ADDRESS
value|0x05
end_define

begin_define
define|#
directive|define
name|USB_REQ_GET_DESCRIPTOR
value|0x06
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_DESCRIPTOR
value|0x07
end_define

begin_define
define|#
directive|define
name|USB_REQ_GET_CONFIGURATION
value|0x08
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_CONFIGURATION
value|0x09
end_define

begin_define
define|#
directive|define
name|USB_REQ_GET_INTERFACE
value|0x0A
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_INTERFACE
value|0x0B
end_define

begin_define
define|#
directive|define
name|USB_REQ_SYNCH_FRAME
value|0x0C
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_ENCRYPTION
value|0x0D
end_define

begin_comment
comment|/* Wireless USB */
end_comment

begin_define
define|#
directive|define
name|USB_REQ_GET_ENCRYPTION
value|0x0E
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_HANDSHAKE
value|0x0F
end_define

begin_define
define|#
directive|define
name|USB_REQ_GET_HANDSHAKE
value|0x10
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_CONNECTION
value|0x11
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_SECURITY_DATA
value|0x12
end_define

begin_define
define|#
directive|define
name|USB_REQ_GET_SECURITY_DATA
value|0x13
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_WUSB_DATA
value|0x14
end_define

begin_define
define|#
directive|define
name|USB_REQ_LOOPBACK_DATA_WRITE
value|0x15
end_define

begin_define
define|#
directive|define
name|USB_REQ_LOOPBACK_DATA_READ
value|0x16
end_define

begin_define
define|#
directive|define
name|USB_REQ_SET_INTERFACE_DS
value|0x17
end_define

begin_comment
comment|/*  * USB feature flags are written using USB_REQ_{CLEAR,SET}_FEATURE, and  * are read as a bit array returned by USB_REQ_GET_STATUS.  (So there  * are at most sixteen features of each type.)  */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_SELF_POWERED
value|0
end_define

begin_comment
comment|/* (read only) */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_REMOTE_WAKEUP
value|1
end_define

begin_comment
comment|/* dev may initiate wakeup */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_TEST_MODE
value|2
end_define

begin_comment
comment|/* (wired high speed only) */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_BATTERY
value|2
end_define

begin_comment
comment|/* (wireless) */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_B_HNP_ENABLE
value|3
end_define

begin_comment
comment|/* (otg) dev may initiate HNP */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_WUSB_DEVICE
value|3
end_define

begin_comment
comment|/* (wireless) */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_A_HNP_SUPPORT
value|4
end_define

begin_comment
comment|/* (otg) RH port supports HNP */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_A_ALT_HNP_SUPPORT
value|5
end_define

begin_comment
comment|/* (otg) other RH port does */
end_comment

begin_define
define|#
directive|define
name|USB_DEVICE_DEBUG_MODE
value|6
end_define

begin_comment
comment|/* (special devices only) */
end_comment

begin_define
define|#
directive|define
name|USB_ENDPOINT_HALT
value|0
end_define

begin_comment
comment|/* IN/OUT will STALL */
end_comment

begin_define
define|#
directive|define
name|PIPE_ISOCHRONOUS
value|0x01
end_define

begin_comment
comment|/* UE_ISOCHRONOUS */
end_comment

begin_define
define|#
directive|define
name|PIPE_INTERRUPT
value|0x03
end_define

begin_comment
comment|/* UE_INTERRUPT */
end_comment

begin_define
define|#
directive|define
name|PIPE_CONTROL
value|0x00
end_define

begin_comment
comment|/* UE_CONTROL */
end_comment

begin_define
define|#
directive|define
name|PIPE_BULK
value|0x02
end_define

begin_comment
comment|/* UE_BULK */
end_comment

begin_comment
comment|/* Whenever Linux references an USB endpoint:  * a) to initialize "urb->endpoint"  * b) second argument passed to "usb_control_msg()"  *  * Then it uses one of the following macros. The "endpoint" argument  * is the physical endpoint value masked by 0xF. The "dev" argument  * is a pointer to "struct usb_device".  */
end_comment

begin_define
define|#
directive|define
name|usb_sndctrlpipe
parameter_list|(
name|dev
parameter_list|,
name|endpoint
parameter_list|)
define|\
value|usb_find_host_endpoint(dev, PIPE_CONTROL, (endpoint) | USB_DIR_OUT)
end_define

begin_define
define|#
directive|define
name|usb_rcvctrlpipe
parameter_list|(
name|dev
parameter_list|,
name|endpoint
parameter_list|)
define|\
value|usb_find_host_endpoint(dev, PIPE_CONTROL, (endpoint) | USB_DIR_IN)
end_define

begin_define
define|#
directive|define
name|usb_sndisocpipe
parameter_list|(
name|dev
parameter_list|,
name|endpoint
parameter_list|)
define|\
value|usb_find_host_endpoint(dev, PIPE_ISOCHRONOUS, (endpoint) | USB_DIR_OUT)
end_define

begin_define
define|#
directive|define
name|usb_rcvisocpipe
parameter_list|(
name|dev
parameter_list|,
name|endpoint
parameter_list|)
define|\
value|usb_find_host_endpoint(dev, PIPE_ISOCHRONOUS, (endpoint) | USB_DIR_IN)
end_define

begin_define
define|#
directive|define
name|usb_sndbulkpipe
parameter_list|(
name|dev
parameter_list|,
name|endpoint
parameter_list|)
define|\
value|usb_find_host_endpoint(dev, PIPE_BULK, (endpoint) | USB_DIR_OUT)
end_define

begin_define
define|#
directive|define
name|usb_rcvbulkpipe
parameter_list|(
name|dev
parameter_list|,
name|endpoint
parameter_list|)
define|\
value|usb_find_host_endpoint(dev, PIPE_BULK, (endpoint) | USB_DIR_IN)
end_define

begin_define
define|#
directive|define
name|usb_sndintpipe
parameter_list|(
name|dev
parameter_list|,
name|endpoint
parameter_list|)
define|\
value|usb_find_host_endpoint(dev, PIPE_INTERRUPT, (endpoint) | USB_DIR_OUT)
end_define

begin_define
define|#
directive|define
name|usb_rcvintpipe
parameter_list|(
name|dev
parameter_list|,
name|endpoint
parameter_list|)
define|\
value|usb_find_host_endpoint(dev, PIPE_INTERRUPT, (endpoint) | USB_DIR_IN)
end_define

begin_comment
comment|/*  * The following structure is used to extend "struct urb" when we are  * dealing with an isochronous endpoint. It contains information about  * the data offset and data length of an isochronous packet.  * The "actual_length" field is updated before the "complete"  * callback in the "urb" structure is called.  */
end_comment

begin_struct
struct|struct
name|usb_iso_packet_descriptor
block|{
name|uint32_t
name|offset
decl_stmt|;
comment|/* depreciated buffer offset (the 					 * packets are usually back to back) */
name|uint16_t
name|length
decl_stmt|;
comment|/* expected length */
name|uint16_t
name|actual_length
decl_stmt|;
name|int16_t
name|status
decl_stmt|;
comment|/* transfer status */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure holds various information about an USB  * transfer. This structure is used for all kinds of USB transfers.  *  * URB is short for USB Request Block.  */
end_comment

begin_struct
struct|struct
name|urb
block|{
name|TAILQ_ENTRY
argument_list|(
argument|urb
argument_list|)
name|bsd_urb_list
expr_stmt|;
name|struct
name|cv
name|cv_wait
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|dev
decl_stmt|;
comment|/* (in) pointer to associated device */
name|struct
name|usb_host_endpoint
modifier|*
name|endpoint
decl_stmt|;
comment|/* (in) pipe pointer */
name|uint8_t
modifier|*
name|setup_packet
decl_stmt|;
comment|/* (in) setup packet (control only) */
name|uint8_t
modifier|*
name|bsd_data_ptr
decl_stmt|;
name|void
modifier|*
name|transfer_buffer
decl_stmt|;
comment|/* (in) associated data buffer */
name|void
modifier|*
name|context
decl_stmt|;
comment|/* (in) context for completion */
name|usb_complete_t
modifier|*
name|complete
decl_stmt|;
comment|/* (in) completion routine */
name|usb_size_t
name|transfer_buffer_length
decl_stmt|;
comment|/* (in) data buffer length */
name|usb_size_t
name|bsd_length_rem
decl_stmt|;
name|usb_size_t
name|actual_length
decl_stmt|;
comment|/* (return) actual transfer length */
name|usb_timeout_t
name|timeout
decl_stmt|;
comment|/* FreeBSD specific */
name|uint16_t
name|transfer_flags
decl_stmt|;
comment|/* (in) */
define|#
directive|define
name|URB_SHORT_NOT_OK
value|0x0001
comment|/* report short transfers like errors */
define|#
directive|define
name|URB_ISO_ASAP
value|0x0002
comment|/* ignore "start_frame" field */
define|#
directive|define
name|URB_ZERO_PACKET
value|0x0004
comment|/* the USB transfer ends with a short 					 * packet */
define|#
directive|define
name|URB_NO_TRANSFER_DMA_MAP
value|0x0008
comment|/* "transfer_dma" is valid on submit */
define|#
directive|define
name|URB_WAIT_WAKEUP
value|0x0010
comment|/* custom flags */
define|#
directive|define
name|URB_IS_SLEEPING
value|0x0020
comment|/* custom flags */
name|usb_frcount_t
name|start_frame
decl_stmt|;
comment|/* (modify) start frame (ISO) */
name|usb_frcount_t
name|number_of_packets
decl_stmt|;
comment|/* (in) number of ISO packets */
name|uint16_t
name|interval
decl_stmt|;
comment|/* (modify) transfer interval 					 * (INT/ISO) */
name|uint16_t
name|error_count
decl_stmt|;
comment|/* (return) number of ISO errors */
name|int16_t
name|status
decl_stmt|;
comment|/* (return) status */
name|uint8_t
name|setup_dma
decl_stmt|;
comment|/* (in) not used on FreeBSD */
name|uint8_t
name|transfer_dma
decl_stmt|;
comment|/* (in) not used on FreeBSD */
name|uint8_t
name|bsd_isread
decl_stmt|;
name|uint8_t
name|kill_count
decl_stmt|;
comment|/* FreeBSD specific */
name|struct
name|usb_iso_packet_descriptor
name|iso_frame_desc
index|[]
decl_stmt|;
comment|/* (in) ISO ONLY */
block|}
struct|;
end_struct

begin_comment
comment|/* various prototypes */
end_comment

begin_function_decl
name|int
name|usb_submit_urb
parameter_list|(
name|struct
name|urb
modifier|*
name|urb
parameter_list|,
name|uint16_t
name|mem_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_unlink_urb
parameter_list|(
name|struct
name|urb
modifier|*
name|urb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_clear_halt
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|,
name|struct
name|usb_host_endpoint
modifier|*
name|uhe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_control_msg
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|,
name|struct
name|usb_host_endpoint
modifier|*
name|ep
parameter_list|,
name|uint8_t
name|request
parameter_list|,
name|uint8_t
name|requesttype
parameter_list|,
name|uint16_t
name|value
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|uint16_t
name|size
parameter_list|,
name|usb_timeout_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_set_interface
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|,
name|uint8_t
name|ifnum
parameter_list|,
name|uint8_t
name|alternate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_setup_endpoint
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|,
name|struct
name|usb_host_endpoint
modifier|*
name|uhe
parameter_list|,
name|usb_frlength_t
name|bufsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_host_endpoint
modifier|*
name|usb_find_host_endpoint
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|,
name|uint8_t
name|type
parameter_list|,
name|uint8_t
name|ep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|urb
modifier|*
name|usb_alloc_urb
parameter_list|(
name|uint16_t
name|iso_packets
parameter_list|,
name|uint16_t
name|mem_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_host_interface
modifier|*
name|usb_altnum_to_altsetting
parameter_list|(
specifier|const
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|,
name|uint8_t
name|alt_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_interface
modifier|*
name|usb_ifnum_to_if
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|,
name|uint8_t
name|iface_no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usb_buffer_alloc
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|,
name|usb_size_t
name|size
parameter_list|,
name|uint16_t
name|mem_flags
parameter_list|,
name|uint8_t
modifier|*
name|dma_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usbd_get_intfdata
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_buffer_free
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|,
name|usb_size_t
name|size
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|uint8_t
name|dma_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_free_urb
parameter_list|(
name|struct
name|urb
modifier|*
name|urb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_init_urb
parameter_list|(
name|struct
name|urb
modifier|*
name|urb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_kill_urb
parameter_list|(
name|struct
name|urb
modifier|*
name|urb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_set_intfdata
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|intf
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_linux_register
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_linux_deregister
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_fill_bulk_urb
parameter_list|(
name|struct
name|urb
modifier|*
parameter_list|,
name|struct
name|usb_device
modifier|*
parameter_list|,
name|struct
name|usb_host_endpoint
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|usb_complete_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_bulk_msg
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|,
name|struct
name|usb_host_endpoint
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint16_t
modifier|*
parameter_list|,
name|usb_timeout_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|interface_to_usbdev
parameter_list|(
name|intf
parameter_list|)
value|(intf)->linux_udev
end_define

begin_define
define|#
directive|define
name|interface_to_bsddev
parameter_list|(
name|intf
parameter_list|)
value|(intf)->linux_udev
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_COMPAT_LINUX_H */
end_comment

end_unit

