begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  * Copyright (c) 1998 The NetBSD Foundation, Inc. All rights reserved.  * Copyright (c) 1998 Lennart Augustsson. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_IOCTL_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USB_GLOBAL_INCLUDE_FILE
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* Building "kdump" depends on these includes */
end_comment

begin_include
include|#
directive|include
file|<dev/usb/usb_endian.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USB_DEVICE_NAME
value|"usbctl"
end_define

begin_define
define|#
directive|define
name|USB_DEVICE_DIR
value|"usb"
end_define

begin_define
define|#
directive|define
name|USB_GENERIC_NAME
value|"ugen"
end_define

begin_define
define|#
directive|define
name|USB_TEMPLATE_SYSCTL
value|"hw.usb.template"
end_define

begin_comment
comment|/* integer type */
end_comment

begin_comment
comment|/*  * Align IOCTL structures to hide differences when running 32-bit  * programs under 64-bit kernels:  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_32BIT
end_ifdef

begin_define
define|#
directive|define
name|USB_IOCTL_STRUCT_ALIGN
parameter_list|(
name|n
parameter_list|)
value|__aligned(n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USB_IOCTL_STRUCT_ALIGN
parameter_list|(
name|n
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Definition of valid template sysctl values */
end_comment

begin_enum
enum|enum
block|{
name|USB_TEMP_MSC
block|,
comment|/* USB Mass Storage */
name|USB_TEMP_CDCE
block|,
comment|/* USB CDC Ethernet */
name|USB_TEMP_MTP
block|,
comment|/* Message Transfer Protocol */
name|USB_TEMP_MODEM
block|,
comment|/* USB CDC Modem */
name|USB_TEMP_AUDIO
block|,
comment|/* USB Audio */
name|USB_TEMP_KBD
block|,
comment|/* USB Keyboard */
name|USB_TEMP_MOUSE
block|,
comment|/* USB Mouse */
name|USB_TEMP_PHONE
block|,
comment|/* USB Phone */
name|USB_TEMP_MAX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|usb_read_dir
block|{
ifdef|#
directive|ifdef
name|COMPAT_32BIT
name|uint64_t
name|urd_data
decl_stmt|;
else|#
directive|else
name|void
modifier|*
name|urd_data
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|urd_startentry
decl_stmt|;
name|uint32_t
name|urd_maxlen
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_ctl_request
block|{
ifdef|#
directive|ifdef
name|COMPAT_32BIT
name|uint64_t
name|ucr_data
decl_stmt|;
else|#
directive|else
name|void
modifier|*
name|ucr_data
decl_stmt|;
endif|#
directive|endif
name|uint16_t
name|ucr_flags
decl_stmt|;
name|uint16_t
name|ucr_actlen
decl_stmt|;
comment|/* actual length transferred */
name|uint8_t
name|ucr_addr
decl_stmt|;
comment|/* zero - currently not used */
name|struct
name|usb_device_request
name|ucr_request
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_alt_interface
block|{
name|uint8_t
name|uai_interface_index
decl_stmt|;
name|uint8_t
name|uai_alt_index
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|1
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_gen_descriptor
block|{
ifdef|#
directive|ifdef
name|COMPAT_32BIT
name|uint64_t
name|ugd_data
decl_stmt|;
else|#
directive|else
name|void
modifier|*
name|ugd_data
decl_stmt|;
endif|#
directive|endif
name|uint16_t
name|ugd_lang_id
decl_stmt|;
name|uint16_t
name|ugd_maxlen
decl_stmt|;
name|uint16_t
name|ugd_actlen
decl_stmt|;
name|uint16_t
name|ugd_offset
decl_stmt|;
name|uint8_t
name|ugd_config_index
decl_stmt|;
name|uint8_t
name|ugd_string_index
decl_stmt|;
name|uint8_t
name|ugd_iface_index
decl_stmt|;
name|uint8_t
name|ugd_altif_index
decl_stmt|;
name|uint8_t
name|ugd_endpt_index
decl_stmt|;
name|uint8_t
name|ugd_report_type
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_device_info
block|{
name|uint16_t
name|udi_productNo
decl_stmt|;
name|uint16_t
name|udi_vendorNo
decl_stmt|;
name|uint16_t
name|udi_releaseNo
decl_stmt|;
name|uint16_t
name|udi_power
decl_stmt|;
comment|/* power consumption in mA, 0 if 					 * selfpowered */
name|uint8_t
name|udi_bus
decl_stmt|;
name|uint8_t
name|udi_addr
decl_stmt|;
comment|/* device address */
name|uint8_t
name|udi_index
decl_stmt|;
comment|/* device index */
name|uint8_t
name|udi_class
decl_stmt|;
name|uint8_t
name|udi_subclass
decl_stmt|;
name|uint8_t
name|udi_protocol
decl_stmt|;
name|uint8_t
name|udi_config_no
decl_stmt|;
comment|/* current config number */
name|uint8_t
name|udi_config_index
decl_stmt|;
comment|/* current config index */
name|uint8_t
name|udi_speed
decl_stmt|;
comment|/* see "USB_SPEED_XXX" */
name|uint8_t
name|udi_mode
decl_stmt|;
comment|/* see "USB_MODE_XXX" */
name|uint8_t
name|udi_nports
decl_stmt|;
name|uint8_t
name|udi_hubaddr
decl_stmt|;
comment|/* parent HUB address */
name|uint8_t
name|udi_hubindex
decl_stmt|;
comment|/* parent HUB device index */
name|uint8_t
name|udi_hubport
decl_stmt|;
comment|/* parent HUB port */
name|uint8_t
name|udi_power_mode
decl_stmt|;
comment|/* see "USB_POWER_MODE_XXX" */
name|uint8_t
name|udi_suspended
decl_stmt|;
comment|/* set if device is suspended */
name|uint8_t
name|udi_reserved
index|[
literal|16
index|]
decl_stmt|;
comment|/* leave space for the future */
name|char
name|udi_product
index|[
literal|128
index|]
decl_stmt|;
name|char
name|udi_vendor
index|[
literal|128
index|]
decl_stmt|;
name|char
name|udi_serial
index|[
literal|64
index|]
decl_stmt|;
name|char
name|udi_release
index|[
literal|8
index|]
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|2
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_DEVICE_PORT_PATH_MAX
value|32
end_define

begin_struct
struct|struct
name|usb_device_port_path
block|{
name|uint8_t
name|udp_bus
decl_stmt|;
comment|/* which bus we are on */
name|uint8_t
name|udp_index
decl_stmt|;
comment|/* which device index */
name|uint8_t
name|udp_port_level
decl_stmt|;
comment|/* how many levels: 0, 1, 2 ... */
name|uint8_t
name|udp_port_no
index|[
name|USB_DEVICE_PORT_PATH_MAX
index|]
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|1
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_device_stats
block|{
name|uint32_t
name|uds_requests_ok
index|[
literal|4
index|]
decl_stmt|;
comment|/* Indexed by transfer type UE_XXX */
name|uint32_t
name|uds_requests_fail
index|[
literal|4
index|]
decl_stmt|;
comment|/* Indexed by transfer type UE_XXX */
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_start
block|{
name|uint8_t
name|ep_index
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|1
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_stop
block|{
name|uint8_t
name|ep_index
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|1
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_complete
block|{
name|uint8_t
name|ep_index
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|1
argument_list|)
struct|;
end_struct

begin_comment
comment|/* This structure is used for all endpoint types */
end_comment

begin_struct
struct|struct
name|usb_fs_endpoint
block|{
comment|/* 	 * NOTE: isochronous USB transfer only use one buffer, but can have 	 * multiple frame lengths ! 	 */
ifdef|#
directive|ifdef
name|COMPAT_32BIT
name|uint64_t
name|ppBuffer
decl_stmt|;
name|uint64_t
name|pLength
decl_stmt|;
else|#
directive|else
name|void
modifier|*
modifier|*
name|ppBuffer
decl_stmt|;
comment|/* pointer to userland buffers */
name|uint32_t
modifier|*
name|pLength
decl_stmt|;
comment|/* pointer to frame lengths, updated 					 * to actual length */
endif|#
directive|endif
name|uint32_t
name|nFrames
decl_stmt|;
comment|/* number of frames */
name|uint32_t
name|aFrames
decl_stmt|;
comment|/* actual number of frames */
name|uint16_t
name|flags
decl_stmt|;
comment|/* a single short frame will terminate */
define|#
directive|define
name|USB_FS_FLAG_SINGLE_SHORT_OK
value|0x0001
comment|/* multiple short frames are allowed */
define|#
directive|define
name|USB_FS_FLAG_MULTI_SHORT_OK
value|0x0002
comment|/* all frame(s) transmitted are short terminated */
define|#
directive|define
name|USB_FS_FLAG_FORCE_SHORT
value|0x0004
comment|/* will do a clear-stall before xfer */
define|#
directive|define
name|USB_FS_FLAG_CLEAR_STALL
value|0x0008
name|uint16_t
name|timeout
decl_stmt|;
comment|/* in milliseconds */
comment|/* isocronous completion time in milliseconds - used for echo cancel */
name|uint16_t
name|isoc_time_complete
decl_stmt|;
comment|/* timeout value for no timeout */
define|#
directive|define
name|USB_FS_TIMEOUT_NONE
value|0
name|int
name|status
decl_stmt|;
comment|/* see USB_ERR_XXX */
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_init
block|{
comment|/* userland pointer to endpoints structure */
ifdef|#
directive|ifdef
name|COMPAT_32BIT
name|uint64_t
name|pEndpoints
decl_stmt|;
else|#
directive|else
name|struct
name|usb_fs_endpoint
modifier|*
name|pEndpoints
decl_stmt|;
endif|#
directive|endif
comment|/* maximum number of endpoints */
name|uint8_t
name|ep_index_max
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_uninit
block|{
name|uint8_t
name|dummy
decl_stmt|;
comment|/* zero */
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|1
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_open
block|{
define|#
directive|define
name|USB_FS_MAX_BUFSIZE
value|(1<< 18)
name|uint32_t
name|max_bufsize
decl_stmt|;
define|#
directive|define
name|USB_FS_MAX_FRAMES
value|(1U<< 12)
define|#
directive|define
name|USB_FS_MAX_FRAMES_PRE_SCALE
value|(1U<< 31)
comment|/* for ISOCHRONOUS transfers */
name|uint32_t
name|max_frames
decl_stmt|;
comment|/* read and write */
name|uint16_t
name|max_packet_length
decl_stmt|;
comment|/* read only */
name|uint8_t
name|dev_index
decl_stmt|;
comment|/* currently unused */
name|uint8_t
name|ep_index
decl_stmt|;
name|uint8_t
name|ep_no
decl_stmt|;
comment|/* bEndpointNumber */
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_open_stream
block|{
name|struct
name|usb_fs_open
name|fs_open
decl_stmt|;
name|uint16_t
name|stream_id
decl_stmt|;
comment|/* stream ID */
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_close
block|{
name|uint8_t
name|ep_index
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|1
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_clear_stall_sync
block|{
name|uint8_t
name|ep_index
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|1
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_gen_quirk
block|{
name|uint16_t
name|index
decl_stmt|;
comment|/* Quirk Index */
name|uint16_t
name|vid
decl_stmt|;
comment|/* Vendor ID */
name|uint16_t
name|pid
decl_stmt|;
comment|/* Product ID */
name|uint16_t
name|bcdDeviceLow
decl_stmt|;
comment|/* Low Device Revision */
name|uint16_t
name|bcdDeviceHigh
decl_stmt|;
comment|/* High Device Revision */
name|uint16_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 	 * String version of quirk including terminating zero. See 	 * UQ_XXX in "usb_quirk.h". 	 */
name|char
name|quirkname
index|[
literal|64
operator|-
literal|14
index|]
decl_stmt|;
block|}
name|USB_IOCTL_STRUCT_ALIGN
argument_list|(
literal|2
argument_list|)
struct|;
end_struct

begin_comment
comment|/* USB controller */
end_comment

begin_define
define|#
directive|define
name|USB_REQUEST
value|_IOWR('U', 1, struct usb_ctl_request)
end_define

begin_define
define|#
directive|define
name|USB_SETDEBUG
value|_IOW ('U', 2, int)
end_define

begin_define
define|#
directive|define
name|USB_DISCOVER
value|_IO  ('U', 3)
end_define

begin_define
define|#
directive|define
name|USB_DEVICEINFO
value|_IOWR('U', 4, struct usb_device_info)
end_define

begin_define
define|#
directive|define
name|USB_DEVICESTATS
value|_IOR ('U', 5, struct usb_device_stats)
end_define

begin_define
define|#
directive|define
name|USB_DEVICEENUMERATE
value|_IOW ('U', 6, int)
end_define

begin_comment
comment|/* Generic HID device */
end_comment

begin_define
define|#
directive|define
name|USB_GET_REPORT_DESC
value|_IOWR('U', 21, struct usb_gen_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_SET_IMMED
value|_IOW ('U', 22, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_REPORT
value|_IOWR('U', 23, struct usb_gen_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_SET_REPORT
value|_IOW ('U', 24, struct usb_gen_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_GET_REPORT_ID
value|_IOR ('U', 25, int)
end_define

begin_comment
comment|/* Generic USB device */
end_comment

begin_define
define|#
directive|define
name|USB_GET_CONFIG
value|_IOR ('U', 100, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_CONFIG
value|_IOW ('U', 101, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_ALTINTERFACE
value|_IOWR('U', 102, struct usb_alt_interface)
end_define

begin_define
define|#
directive|define
name|USB_SET_ALTINTERFACE
value|_IOWR('U', 103, struct usb_alt_interface)
end_define

begin_define
define|#
directive|define
name|USB_GET_DEVICE_DESC
value|_IOR ('U', 105, struct usb_device_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_GET_CONFIG_DESC
value|_IOR ('U', 106, struct usb_config_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_GET_RX_INTERFACE_DESC
value|_IOR ('U', 107, struct usb_interface_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_GET_RX_ENDPOINT_DESC
value|_IOR ('U', 108, struct usb_endpoint_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_GET_FULL_DESC
value|_IOWR('U', 109, struct usb_gen_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_GET_STRING_DESC
value|_IOWR('U', 110, struct usb_gen_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_DO_REQUEST
value|_IOWR('U', 111, struct usb_ctl_request)
end_define

begin_define
define|#
directive|define
name|USB_GET_DEVICEINFO
value|_IOR ('U', 112, struct usb_device_info)
end_define

begin_define
define|#
directive|define
name|USB_SET_RX_SHORT_XFER
value|_IOW ('U', 113, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_RX_TIMEOUT
value|_IOW ('U', 114, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_RX_FRAME_SIZE
value|_IOR ('U', 115, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_RX_BUFFER_SIZE
value|_IOR ('U', 117, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_RX_BUFFER_SIZE
value|_IOW ('U', 118, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_RX_STALL_FLAG
value|_IOW ('U', 119, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_TX_STALL_FLAG
value|_IOW ('U', 120, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_IFACE_DRIVER
value|_IOWR('U', 121, struct usb_gen_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_CLAIM_INTERFACE
value|_IOW ('U', 122, int)
end_define

begin_define
define|#
directive|define
name|USB_RELEASE_INTERFACE
value|_IOW ('U', 123, int)
end_define

begin_define
define|#
directive|define
name|USB_IFACE_DRIVER_ACTIVE
value|_IOW ('U', 124, int)
end_define

begin_define
define|#
directive|define
name|USB_IFACE_DRIVER_DETACH
value|_IOW ('U', 125, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_PLUGTIME
value|_IOR ('U', 126, uint32_t)
end_define

begin_define
define|#
directive|define
name|USB_READ_DIR
value|_IOW ('U', 127, struct usb_read_dir)
end_define

begin_comment
comment|/* 128 - 133 unused */
end_comment

begin_define
define|#
directive|define
name|USB_GET_DEV_PORT_PATH
value|_IOR ('U', 134, struct usb_device_port_path)
end_define

begin_define
define|#
directive|define
name|USB_GET_POWER_USAGE
value|_IOR ('U', 135, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_TX_FORCE_SHORT
value|_IOW ('U', 136, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_TX_TIMEOUT
value|_IOW ('U', 137, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_TX_FRAME_SIZE
value|_IOR ('U', 138, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_TX_BUFFER_SIZE
value|_IOR ('U', 139, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_TX_BUFFER_SIZE
value|_IOW ('U', 140, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_TX_INTERFACE_DESC
value|_IOR ('U', 141, struct usb_interface_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_GET_TX_ENDPOINT_DESC
value|_IOR ('U', 142, struct usb_endpoint_descriptor)
end_define

begin_define
define|#
directive|define
name|USB_SET_PORT_ENABLE
value|_IOW ('U', 143, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_PORT_DISABLE
value|_IOW ('U', 144, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_POWER_MODE
value|_IOW ('U', 145, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_POWER_MODE
value|_IOR ('U', 146, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_TEMPLATE
value|_IOW ('U', 147, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_TEMPLATE
value|_IOR ('U', 148, int)
end_define

begin_comment
comment|/* Modem device */
end_comment

begin_define
define|#
directive|define
name|USB_GET_CM_OVER_DATA
value|_IOR ('U', 180, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_CM_OVER_DATA
value|_IOW ('U', 181, int)
end_define

begin_comment
comment|/* GPIO control */
end_comment

begin_define
define|#
directive|define
name|USB_GET_GPIO
value|_IOR ('U', 182, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_GPIO
value|_IOW ('U', 183, int)
end_define

begin_comment
comment|/* USB file system interface */
end_comment

begin_define
define|#
directive|define
name|USB_FS_START
value|_IOW ('U', 192, struct usb_fs_start)
end_define

begin_define
define|#
directive|define
name|USB_FS_STOP
value|_IOW ('U', 193, struct usb_fs_stop)
end_define

begin_define
define|#
directive|define
name|USB_FS_COMPLETE
value|_IOR ('U', 194, struct usb_fs_complete)
end_define

begin_define
define|#
directive|define
name|USB_FS_INIT
value|_IOW ('U', 195, struct usb_fs_init)
end_define

begin_define
define|#
directive|define
name|USB_FS_UNINIT
value|_IOW ('U', 196, struct usb_fs_uninit)
end_define

begin_define
define|#
directive|define
name|USB_FS_OPEN
value|_IOWR('U', 197, struct usb_fs_open)
end_define

begin_define
define|#
directive|define
name|USB_FS_CLOSE
value|_IOW ('U', 198, struct usb_fs_close)
end_define

begin_define
define|#
directive|define
name|USB_FS_CLEAR_STALL_SYNC
value|_IOW ('U', 199, struct usb_fs_clear_stall_sync)
end_define

begin_define
define|#
directive|define
name|USB_FS_OPEN_STREAM
value|_IOWR('U', 200, struct usb_fs_open_stream)
end_define

begin_comment
comment|/* USB quirk system interface */
end_comment

begin_define
define|#
directive|define
name|USB_DEV_QUIRK_GET
value|_IOWR('Q', 0, struct usb_gen_quirk)
end_define

begin_define
define|#
directive|define
name|USB_QUIRK_NAME_GET
value|_IOWR('Q', 1, struct usb_gen_quirk)
end_define

begin_define
define|#
directive|define
name|USB_DEV_QUIRK_ADD
value|_IOW ('Q', 2, struct usb_gen_quirk)
end_define

begin_define
define|#
directive|define
name|USB_DEV_QUIRK_REMOVE
value|_IOW ('Q', 3, struct usb_gen_quirk)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_IOCTL_H_ */
end_comment

end_unit

