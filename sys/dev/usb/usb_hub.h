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
name|_USB_HUB_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_HUB_H_
end_define

begin_comment
comment|/*  * The following structure defines an USB port.   */
end_comment

begin_struct
struct|struct
name|usb_port
block|{
name|uint8_t
name|restartcnt
decl_stmt|;
define|#
directive|define
name|USB_RESTART_MAX
value|5
name|uint8_t
name|device_index
decl_stmt|;
comment|/* zero means not valid */
name|enum
name|usb_hc_mode
name|usb_mode
decl_stmt|;
comment|/* host or device mode */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines how many bytes are  * left in an 1ms USB time slot.  */
end_comment

begin_struct
struct|struct
name|usb_fs_isoc_schedule
block|{
name|uint16_t
name|total_bytes
decl_stmt|;
name|uint8_t
name|frame_bytes
decl_stmt|;
name|uint8_t
name|frame_slot
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB HUB.  */
end_comment

begin_struct
struct|struct
name|usb_hub
block|{
if|#
directive|if
name|USB_HAVE_TT_SUPPORT
name|struct
name|usb_fs_isoc_schedule
name|fs_isoc_schedule
index|[
name|USB_ISOC_TIME_MAX
index|]
decl_stmt|;
endif|#
directive|endif
name|struct
name|usb_device
modifier|*
name|hubudev
decl_stmt|;
comment|/* the HUB device */
name|usb_error_t
function_decl|(
modifier|*
name|explore
function_decl|)
parameter_list|(
name|struct
name|usb_device
modifier|*
name|hub
parameter_list|)
function_decl|;
name|void
modifier|*
name|hubsoftc
decl_stmt|;
name|usb_size_t
name|uframe_usage
index|[
name|USB_HS_MICRO_FRAMES_MAX
index|]
decl_stmt|;
name|uint16_t
name|portpower
decl_stmt|;
comment|/* mA per USB port */
name|uint8_t
name|isoc_last_time
decl_stmt|;
name|uint8_t
name|nports
decl_stmt|;
name|struct
name|usb_port
name|ports
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|void
name|usb_hs_bandwidth_alloc
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
name|usb_hs_bandwidth_free
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
name|usbd_fs_isoc_schedule_init_all
parameter_list|(
name|struct
name|usb_fs_isoc_schedule
modifier|*
name|fss
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_bus_port_set_device
parameter_list|(
name|struct
name|usb_bus
modifier|*
name|bus
parameter_list|,
name|struct
name|usb_port
modifier|*
name|up
parameter_list|,
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|device_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_device
modifier|*
name|usb_bus_port_get_device
parameter_list|(
name|struct
name|usb_bus
modifier|*
name|bus
parameter_list|,
name|struct
name|usb_port
modifier|*
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_needs_explore
parameter_list|(
name|struct
name|usb_bus
modifier|*
name|bus
parameter_list|,
name|uint8_t
name|do_probe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_needs_explore_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_bus_power_update
parameter_list|(
name|struct
name|usb_bus
modifier|*
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_bus_powerd
parameter_list|(
name|struct
name|usb_bus
modifier|*
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uhub_root_intr
parameter_list|(
name|struct
name|usb_bus
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_HUB_H_ */
end_comment

end_unit

