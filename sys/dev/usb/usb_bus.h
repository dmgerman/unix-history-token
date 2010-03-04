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
name|_USB_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_BUS_H_
end_define

begin_comment
comment|/*  * The following structure defines the USB explore message sent to the USB  * explore process.  */
end_comment

begin_struct
struct|struct
name|usb_bus_msg
block|{
name|struct
name|usb_proc_msg
name|hdr
decl_stmt|;
name|struct
name|usb_bus
modifier|*
name|bus
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines the USB statistics structure.  */
end_comment

begin_struct
struct|struct
name|usb_bus_stat
block|{
name|uint32_t
name|uds_requests
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB BUS. There is one USB BUS  * for every Host or Device controller.  */
end_comment

begin_struct
struct|struct
name|usb_bus
block|{
name|struct
name|usb_bus_stat
name|stats_err
decl_stmt|;
name|struct
name|usb_bus_stat
name|stats_ok
decl_stmt|;
name|struct
name|root_hold_token
modifier|*
name|bus_roothold
decl_stmt|;
comment|/* 	 * There are two callback processes. One for Giant locked 	 * callbacks. One for non-Giant locked callbacks. This should 	 * avoid congestion and reduce response time in most cases. 	 */
name|struct
name|usb_process
name|giant_callback_proc
decl_stmt|;
name|struct
name|usb_process
name|non_giant_callback_proc
decl_stmt|;
comment|/* Explore process */
name|struct
name|usb_process
name|explore_proc
decl_stmt|;
comment|/* Control request process */
name|struct
name|usb_process
name|control_xfer_proc
decl_stmt|;
name|struct
name|usb_bus_msg
name|explore_msg
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|usb_bus_msg
name|detach_msg
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|usb_bus_msg
name|attach_msg
index|[
literal|2
index|]
decl_stmt|;
comment|/* 	 * This mutex protects the USB hardware: 	 */
name|struct
name|mtx
name|bus_mtx
decl_stmt|;
name|struct
name|usb_xfer_queue
name|intr_q
decl_stmt|;
name|struct
name|usb_callout
name|power_wdog
decl_stmt|;
comment|/* power management */
name|device_t
name|parent
decl_stmt|;
name|device_t
name|bdev
decl_stmt|;
comment|/* filled by HC driver */
if|#
directive|if
name|USB_HAVE_BUSDMA
name|struct
name|usb_dma_parent_tag
name|dma_parent_tag
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|usb_dma_tag
name|dma_tags
index|[
name|USB_BUS_DMA_TAG_MAX
index|]
decl_stmt|;
endif|#
directive|endif
name|struct
name|usb_bus_methods
modifier|*
name|methods
decl_stmt|;
comment|/* filled by HC driver */
name|struct
name|usb_device
modifier|*
modifier|*
name|devices
decl_stmt|;
name|usb_power_mask_t
name|hw_power_state
decl_stmt|;
comment|/* see USB_HW_POWER_XXX */
name|usb_size_t
name|uframe_usage
index|[
name|USB_HS_MICRO_FRAMES_MAX
index|]
decl_stmt|;
name|uint16_t
name|isoc_time_last
decl_stmt|;
comment|/* in milliseconds */
name|uint8_t
name|alloc_failed
decl_stmt|;
comment|/* Set if memory allocation failed. */
name|uint8_t
name|driver_added_refcount
decl_stmt|;
comment|/* Current driver generation count */
name|enum
name|usb_revision
name|usbrev
decl_stmt|;
comment|/* USB revision. See "USB_REV_XXX". */
name|uint8_t
name|devices_max
decl_stmt|;
comment|/* maximum number of USB devices */
name|uint8_t
name|do_probe
decl_stmt|;
comment|/* set if USB BUS should be re-probed */
comment|/*  	 * The scratch area can only be used inside the explore thread 	 * belonging to the give serial bus. 	 */
union|union
block|{
name|struct
name|usb_hw_ep_scratch
name|hw_ep_scratch
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|usb_temp_setup
name|temp_setup
index|[
literal|1
index|]
decl_stmt|;
name|uint8_t
name|data
index|[
literal|255
index|]
decl_stmt|;
block|}
name|scratch
index|[
literal|1
index|]
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_BUS_H_ */
end_comment

end_unit

