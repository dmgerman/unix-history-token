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
name|_USB2_DEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_DEVICE_H_
end_define

begin_struct_decl
struct_decl|struct
name|usb2_symlink
struct_decl|;
end_struct_decl

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

begin_struct
struct|struct
name|usb2_clear_stall_msg
block|{
name|struct
name|usb2_proc_msg
name|hdr
decl_stmt|;
name|struct
name|usb2_device
modifier|*
name|udev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB pipe which is equal to an  * USB endpoint.  */
end_comment

begin_struct
struct|struct
name|usb2_pipe
block|{
name|struct
name|usb2_xfer_queue
name|pipe_q
decl_stmt|;
comment|/* queue of USB transfers */
name|struct
name|usb2_xfer
modifier|*
name|xfer_block
decl_stmt|;
comment|/* blocking USB transfer */
name|struct
name|usb2_endpoint_descriptor
modifier|*
name|edesc
decl_stmt|;
name|struct
name|usb2_pipe_methods
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
comment|/* set if pipe is stalled */
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
comment|/* not used by "default pipe" */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB interface.  */
end_comment

begin_struct
struct|struct
name|usb2_interface
block|{
name|struct
name|usb2_interface_descriptor
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines the USB device flags.  */
end_comment

begin_struct
struct|struct
name|usb2_device_flags
block|{
name|uint8_t
name|usb2_mode
range|:
literal|1
decl_stmt|;
comment|/* USB mode (see USB_MODE_XXX) */
name|uint8_t
name|self_powered
range|:
literal|1
decl_stmt|;
comment|/* set if USB device is self powered */
name|uint8_t
name|suspended
range|:
literal|1
decl_stmt|;
comment|/* set if USB device is suspended */
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
name|uint8_t
name|uq_power_claim
range|:
literal|1
decl_stmt|;
comment|/* set if power claim quirk is present */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure is used for power-save purposes. The data  * in this structure is protected by the USB BUS lock.  */
end_comment

begin_struct
struct|struct
name|usb2_power_save
block|{
name|usb2_ticks_t
name|last_xfer_time
decl_stmt|;
comment|/* copy of "ticks" */
name|usb2_size_t
name|type_refs
index|[
literal|4
index|]
decl_stmt|;
comment|/* transfer reference count */
name|usb2_size_t
name|read_refs
decl_stmt|;
comment|/* data read references */
name|usb2_size_t
name|write_refs
decl_stmt|;
comment|/* data write references */
name|uint8_t
name|suspended
decl_stmt|;
comment|/* set if USB device is suspended */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB device. There exists one of  * these structures for every USB device.  */
end_comment

begin_struct
struct|struct
name|usb2_device
block|{
name|struct
name|usb2_clear_stall_msg
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
name|usb2_interface
name|ifaces
index|[
name|USB_IFACE_MAX
index|]
decl_stmt|;
name|struct
name|usb2_pipe
name|default_pipe
decl_stmt|;
comment|/* Control Endpoint 0 */
name|struct
name|cdev
modifier|*
name|default_dev
decl_stmt|;
comment|/* Control Endpoint 0 device node */
name|struct
name|usb2_pipe
name|pipes
index|[
name|USB_EP_MAX
index|]
decl_stmt|;
name|struct
name|usb2_power_save
name|pwr_save
decl_stmt|;
comment|/* power save data */
name|struct
name|usb2_bus
modifier|*
name|bus
decl_stmt|;
comment|/* our USB BUS */
name|device_t
name|parent_dev
decl_stmt|;
comment|/* parent device */
name|struct
name|usb2_device
modifier|*
name|parent_hub
decl_stmt|;
name|struct
name|usb2_config_descriptor
modifier|*
name|cdesc
decl_stmt|;
comment|/* full config descr */
name|struct
name|usb2_hub
modifier|*
name|hub
decl_stmt|;
comment|/* only if this is a hub */
if|#
directive|if
name|USB_HAVE_COMPAT_LINUX
name|struct
name|usb_device
modifier|*
name|linux_dev
decl_stmt|;
endif|#
directive|endif
name|struct
name|usb2_xfer
modifier|*
name|default_xfer
index|[
name|USB_DEFAULT_XFER_MAX
index|]
decl_stmt|;
name|struct
name|usb2_temp_data
modifier|*
name|usb2_template_ptr
decl_stmt|;
name|struct
name|usb2_pipe
modifier|*
name|pipe_curr
decl_stmt|;
comment|/* current clear stall pipe */
name|struct
name|usb2_fifo
modifier|*
name|fifo
index|[
name|USB_FIFO_MAX
index|]
decl_stmt|;
name|char
name|ugen_name
index|[
literal|20
index|]
decl_stmt|;
comment|/* name of ugenX.X device */
name|struct
name|usb2_symlink
modifier|*
name|ugen_symlink
decl_stmt|;
comment|/* our generic symlink */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|usb2_fs_privdata
argument_list|)
name|pd_list
expr_stmt|;
name|usb2_ticks_t
name|plugtime
decl_stmt|;
comment|/* copy of "ticks" */
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
name|speed
decl_stmt|;
comment|/* low/full/high speed */
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
comment|/* the "flags" field is write-protected by "bus->mtx" */
name|struct
name|usb2_device_flags
name|flags
decl_stmt|;
name|struct
name|usb2_endpoint_descriptor
name|default_ep_desc
decl_stmt|;
comment|/* for pipe 0 */
name|struct
name|usb2_device_descriptor
name|ddesc
decl_stmt|;
comment|/* device descriptor */
name|char
name|serial
index|[
literal|64
index|]
decl_stmt|;
comment|/* serial number */
name|char
name|manufacturer
index|[
literal|64
index|]
decl_stmt|;
comment|/* manufacturer string */
name|char
name|product
index|[
literal|64
index|]
decl_stmt|;
comment|/* product string */
block|}
struct|;
end_struct

begin_comment
comment|/* globals */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|usb2_template
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|struct
name|usb2_device
modifier|*
name|usb2_alloc_device
parameter_list|(
name|device_t
name|parent_dev
parameter_list|,
name|struct
name|usb2_bus
modifier|*
name|bus
parameter_list|,
name|struct
name|usb2_device
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
name|uint8_t
name|speed
parameter_list|,
name|uint8_t
name|usb2_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb2_pipe
modifier|*
name|usb2_get_pipe
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
specifier|const
name|struct
name|usb2_config
modifier|*
name|setup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb2_pipe
modifier|*
name|usb2_get_pipe_by_addr
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|ea_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb2_error_t
name|usb2_interface_count
parameter_list|(
name|struct
name|usb2_device
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
name|usb2_error_t
name|usb2_probe_and_attach
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb2_error_t
name|usb2_reset_iface_endpoints
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb2_error_t
name|usb2_set_config_index
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb2_error_t
name|usb2_set_endpoint_stall
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|struct
name|usb2_pipe
modifier|*
name|pipe
parameter_list|,
name|uint8_t
name|do_stall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb2_error_t
name|usb2_suspend_resume
parameter_list|(
name|struct
name|usb2_device
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
name|usb2_detach_device
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint8_t
name|free_subdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_devinfo
parameter_list|(
name|struct
name|usb2_device
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
name|usb2_free_device
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usb2_find_descriptor
parameter_list|(
name|struct
name|usb2_device
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
name|usb2_peer_can_wakeup
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb2_pipe
modifier|*
name|usb2_pipe_foreach
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|struct
name|usb2_pipe
modifier|*
name|pipe
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_DEVICE_H_ */
end_comment

end_unit

