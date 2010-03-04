begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_DEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_DEVICE_H_
end_define

begin_struct_decl
struct_decl|struct
name|usb_symlink
struct_decl|;
end_struct_decl

begin_comment
comment|/* UGEN */
end_comment

begin_struct_decl
struct_decl|struct
name|usb_device
struct_decl|;
end_struct_decl

begin_comment
comment|/* linux compat */
end_comment

begin_define
define|#
directive|define
name|USB_DEFAULT_XFER_MAX
value|2
end_define

begin_comment
comment|/* "usb_parse_config()" commands */
end_comment

begin_define
define|#
directive|define
name|USB_CFG_ALLOC
value|0
end_define

begin_define
define|#
directive|define
name|USB_CFG_FREE
value|1
end_define

begin_define
define|#
directive|define
name|USB_CFG_INIT
value|2
end_define

begin_comment
comment|/* "usb_unconfigure()" flags */
end_comment

begin_define
define|#
directive|define
name|USB_UNCFG_FLAG_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|USB_UNCFG_FLAG_FREE_EP0
value|0x02
end_define

begin_comment
comment|/* endpoint zero is freed */
end_comment

begin_struct
struct|struct
name|usb_clear_stall_msg
block|{
name|struct
name|usb_proc_msg
name|hdr
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|udev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The following four structures makes up a tree, where we have the  * leaf structure, "usb_host_endpoint", first, and the root structure,  * "usb_device", last. The four structures below mirror the structure  * of the USB descriptors belonging to an USB configuration. Please  * refer to the USB specification for a definition of "endpoints" and  * "interfaces".  */
end_comment

begin_struct
struct|struct
name|usb_host_endpoint
block|{
name|struct
name|usb_endpoint_descriptor
name|desc
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|urb
argument_list|)
name|bsd_urb_list
expr_stmt|;
name|struct
name|usb_xfer
modifier|*
name|bsd_xfer
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
modifier|*
name|extra
decl_stmt|;
comment|/* Extra descriptors */
name|usb_frlength_t
name|fbsd_buf_size
decl_stmt|;
name|uint16_t
name|extralen
decl_stmt|;
name|uint8_t
name|bsd_iface_index
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|USB_HOST_ALIGN
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|usb_host_interface
block|{
name|struct
name|usb_interface_descriptor
name|desc
decl_stmt|;
comment|/* the following array has size "desc.bNumEndpoint" */
name|struct
name|usb_host_endpoint
modifier|*
name|endpoint
decl_stmt|;
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
comment|/* iInterface string, if present */
name|uint8_t
modifier|*
name|extra
decl_stmt|;
comment|/* Extra descriptors */
name|uint16_t
name|extralen
decl_stmt|;
name|uint8_t
name|bsd_iface_index
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|USB_HOST_ALIGN
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines the USB device flags.  */
end_comment

begin_struct
struct|struct
name|usb_device_flags
block|{
name|enum
name|usb_hc_mode
name|usb_mode
decl_stmt|;
comment|/* host or device mode */
name|uint8_t
name|self_powered
range|:
literal|1
decl_stmt|;
comment|/* set if USB device is self powered */
name|uint8_t
name|no_strings
range|:
literal|1
decl_stmt|;
comment|/* set if USB device does not support 					 * strings */
name|uint8_t
name|remote_wakeup
range|:
literal|1
decl_stmt|;
comment|/* set if remote wakeup is enabled */
name|uint8_t
name|uq_bus_powered
range|:
literal|1
decl_stmt|;
comment|/* set if BUS powered quirk is present */
comment|/* 	 * NOTE: Although the flags below will reach the same value 	 * over time, but the instant values may differ, and 	 * consequently the flags cannot be merged into one! 	 */
name|uint8_t
name|peer_suspended
range|:
literal|1
decl_stmt|;
comment|/* set if peer is suspended */
name|uint8_t
name|self_suspended
range|:
literal|1
decl_stmt|;
comment|/* set if self is suspended */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure is used for power-save purposes. The data  * in this structure is protected by the USB BUS lock.  */
end_comment

begin_struct
struct|struct
name|usb_power_save
block|{
name|usb_ticks_t
name|last_xfer_time
decl_stmt|;
comment|/* copy of "ticks" */
name|usb_size_t
name|type_refs
index|[
literal|4
index|]
decl_stmt|;
comment|/* transfer reference count */
name|usb_size_t
name|read_refs
decl_stmt|;
comment|/* data read references */
name|usb_size_t
name|write_refs
decl_stmt|;
comment|/* data write references */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB device. There exists one of  * these structures for every USB device.  */
end_comment

begin_struct
struct|struct
name|usb_device
block|{
name|struct
name|usb_clear_stall_msg
name|cs_msg
index|[
literal|2
index|]
decl_stmt|;
comment|/* generic clear stall 						 * messages */
name|struct
name|sx
name|default_sx
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|mtx
name|default_mtx
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|cv
name|default_cv
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|usb_interface
modifier|*
name|ifaces
decl_stmt|;
name|struct
name|usb_endpoint
name|default_ep
decl_stmt|;
comment|/* Control Endpoint 0 */
name|struct
name|usb_endpoint
modifier|*
name|endpoints
decl_stmt|;
name|struct
name|usb_power_save
name|pwr_save
decl_stmt|;
comment|/* power save data */
name|struct
name|usb_bus
modifier|*
name|bus
decl_stmt|;
comment|/* our USB BUS */
name|device_t
name|parent_dev
decl_stmt|;
comment|/* parent device */
name|struct
name|usb_device
modifier|*
name|parent_hub
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|parent_hs_hub
decl_stmt|;
comment|/* high-speed parent HUB */
name|struct
name|usb_config_descriptor
modifier|*
name|cdesc
decl_stmt|;
comment|/* full config descr */
name|struct
name|usb_hub
modifier|*
name|hub
decl_stmt|;
comment|/* only if this is a hub */
name|struct
name|usb_xfer
modifier|*
name|default_xfer
index|[
name|USB_DEFAULT_XFER_MAX
index|]
decl_stmt|;
name|struct
name|usb_temp_data
modifier|*
name|usb_template_ptr
decl_stmt|;
name|struct
name|usb_endpoint
modifier|*
name|ep_curr
decl_stmt|;
comment|/* current clear stall endpoint */
if|#
directive|if
name|USB_HAVE_UGEN
name|struct
name|usb_fifo
modifier|*
name|fifo
index|[
name|USB_FIFO_MAX
index|]
decl_stmt|;
name|struct
name|usb_symlink
modifier|*
name|ugen_symlink
decl_stmt|;
comment|/* our generic symlink */
name|struct
name|cdev
modifier|*
name|default_dev
decl_stmt|;
comment|/* Control Endpoint 0 device node */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|usb_fs_privdata
argument_list|)
name|pd_list
expr_stmt|;
name|char
name|ugen_name
index|[
literal|20
index|]
decl_stmt|;
comment|/* name of ugenX.X device */
endif|#
directive|endif
name|usb_ticks_t
name|plugtime
decl_stmt|;
comment|/* copy of "ticks" */
name|enum
name|usb_dev_state
name|state
decl_stmt|;
name|enum
name|usb_dev_speed
name|speed
decl_stmt|;
name|uint16_t
name|refcount
decl_stmt|;
define|#
directive|define
name|USB_DEV_REF_MAX
value|0xffff
name|uint16_t
name|power
decl_stmt|;
comment|/* mA the device uses */
name|uint16_t
name|langid
decl_stmt|;
comment|/* language for strings */
name|uint8_t
name|address
decl_stmt|;
comment|/* device addess */
name|uint8_t
name|device_index
decl_stmt|;
comment|/* device index in "bus->devices" */
name|uint8_t
name|curr_config_index
decl_stmt|;
comment|/* current configuration index */
name|uint8_t
name|curr_config_no
decl_stmt|;
comment|/* current configuration number */
name|uint8_t
name|depth
decl_stmt|;
comment|/* distance from root HUB */
name|uint8_t
name|port_index
decl_stmt|;
comment|/* parent HUB port index */
name|uint8_t
name|port_no
decl_stmt|;
comment|/* parent HUB port number */
name|uint8_t
name|hs_hub_addr
decl_stmt|;
comment|/* high-speed HUB address */
name|uint8_t
name|hs_port_no
decl_stmt|;
comment|/* high-speed HUB port number */
name|uint8_t
name|driver_added_refcount
decl_stmt|;
comment|/* our driver added generation count */
name|uint8_t
name|power_mode
decl_stmt|;
comment|/* see USB_POWER_XXX */
name|uint8_t
name|ifaces_max
decl_stmt|;
comment|/* number of interfaces present */
name|uint8_t
name|endpoints_max
decl_stmt|;
comment|/* number of endpoints present */
comment|/* the "flags" field is write-protected by "bus->mtx" */
name|struct
name|usb_device_flags
name|flags
decl_stmt|;
name|struct
name|usb_endpoint_descriptor
name|default_ep_desc
decl_stmt|;
comment|/* for endpoint 0 */
name|struct
name|usb_device_descriptor
name|ddesc
decl_stmt|;
comment|/* device descriptor */
name|char
modifier|*
name|serial
decl_stmt|;
comment|/* serial number */
name|char
modifier|*
name|manufacturer
decl_stmt|;
comment|/* manufacturer string */
name|char
modifier|*
name|product
decl_stmt|;
comment|/* product string */
if|#
directive|if
name|USB_HAVE_COMPAT_LINUX
comment|/* Linux compat */
name|struct
name|usb_device_descriptor
name|descriptor
decl_stmt|;
name|struct
name|usb_host_endpoint
name|ep0
decl_stmt|;
name|struct
name|usb_interface
modifier|*
name|linux_iface_start
decl_stmt|;
name|struct
name|usb_interface
modifier|*
name|linux_iface_end
decl_stmt|;
name|struct
name|usb_host_endpoint
modifier|*
name|linux_endpoint_start
decl_stmt|;
name|struct
name|usb_host_endpoint
modifier|*
name|linux_endpoint_end
decl_stmt|;
name|uint16_t
name|devnum
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* globals */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|usb_template
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|usb_statestr
parameter_list|(
name|enum
name|usb_dev_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_device
modifier|*
name|usb_alloc_device
parameter_list|(
name|device_t
name|parent_dev
parameter_list|,
name|struct
name|usb_bus
modifier|*
name|bus
parameter_list|,
name|struct
name|usb_device
modifier|*
name|parent_hub
parameter_list|,
name|uint8_t
name|depth
parameter_list|,
name|uint8_t
name|port_index
parameter_list|,
name|uint8_t
name|port_no
parameter_list|,
name|enum
name|usb_dev_speed
name|speed
parameter_list|,
name|enum
name|usb_hc_mode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usb_probe_and_attach
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
name|usb_error_t
name|usb_reset_iface_endpoints
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
name|usb_error_t
name|usbd_set_config_index
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usbd_set_endpoint_stall
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|struct
name|usb_endpoint
modifier|*
name|ep
parameter_list|,
name|uint8_t
name|do_stall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usb_suspend_resume
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|do_suspend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_devinfo
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|char
modifier|*
name|dst_ptr
parameter_list|,
name|uint16_t
name|dst_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_free_device
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_linux_free_device
parameter_list|(
name|struct
name|usb_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb_peer_can_wakeup
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
name|usb_endpoint
modifier|*
name|usb_endpoint_foreach
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|struct
name|usb_endpoint
modifier|*
name|ep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_set_device_state
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|enum
name|usb_dev_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_enum_lock
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbd_enum_unlock
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usbd_enum_is_locked
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_DEVICE_H_ */
end_comment

end_unit

