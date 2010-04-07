begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This file describes internal structures.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBUSB20_INT_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBUSB20_INT_H_
end_define

begin_struct_decl
struct_decl|struct
name|libusb20_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|libusb20_backend
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|libusb20_transfer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|libusb20_quirk
struct_decl|;
end_struct_decl

begin_union
union|union
name|libusb20_session_data
block|{
name|unsigned
name|long
name|session_data
decl_stmt|;
name|struct
name|timespec
name|tv
decl_stmt|;
name|uint32_t
name|plugtime
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* USB backend specific */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
name|libusb20_get_backend_name_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_root_get_dev_quirk_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_backend
modifier|*
name|pbe
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|struct
name|libusb20_quirk
modifier|*
name|pq
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_root_get_quirk_name_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_backend
modifier|*
name|pbe
parameter_list|,
name|uint16_t
name|index
parameter_list|,
name|struct
name|libusb20_quirk
modifier|*
name|pq
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_root_add_dev_quirk_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_backend
modifier|*
name|pbe
parameter_list|,
name|struct
name|libusb20_quirk
modifier|*
name|pq
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_root_remove_dev_quirk_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_backend
modifier|*
name|pbe
parameter_list|,
name|struct
name|libusb20_quirk
modifier|*
name|pq
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_close_device_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_dev_get_info_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|struct
name|usb_device_info
modifier|*
name|pinfo
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_dev_get_iface_desc_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|uint8_t
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_init_backend_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_backend
modifier|*
name|pbe
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_open_device_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint16_t
name|transfer_count_max
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|libusb20_exit_backend_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_backend
modifier|*
name|pbe
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_root_set_template_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_backend
modifier|*
name|pbe
parameter_list|,
name|int
name|temp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_root_get_template_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_backend
modifier|*
name|pbe
parameter_list|,
name|int
modifier|*
name|ptemp
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|LIBUSB20_DEFINE
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|)
define|\
value|libusb20_##field##_t *field;
end_define

begin_define
define|#
directive|define
name|LIBUSB20_DECLARE
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|)
define|\
comment|/* .field = */
value|n##_##field,
end_define

begin_define
define|#
directive|define
name|LIBUSB20_BACKEND
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
comment|/* description of this backend */
define|\
value|m(n, get_backend_name) \
comment|/* optional backend methods */
value|\   m(n, init_backend) \   m(n, exit_backend) \   m(n, dev_get_info) \   m(n, dev_get_iface_desc) \   m(n, root_get_dev_quirk) \   m(n, root_get_quirk_name) \   m(n, root_add_dev_quirk) \   m(n, root_remove_dev_quirk) \   m(n, root_set_template) \   m(n, root_get_template) \
comment|/* mandatory device methods */
value|\   m(n, open_device) \   m(n, close_device) \  struct libusb20_backend_methods {
end_define

begin_macro
name|LIBUSB20_BACKEND
argument_list|(
argument|LIBUSB20_DEFINE
argument_list|,)
end_macro

begin_comment
unit|};
comment|/* USB dummy methods */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_dummy_int_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|libusb20_dummy_void_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* USB device specific */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_detach_kernel_driver_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_do_request_sync_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|struct
name|LIBUSB20_CONTROL_SETUP_DECODED
modifier|*
name|setup
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|uint16_t
modifier|*
name|pactlen
parameter_list|,
name|uint32_t
name|timeout
parameter_list|,
name|uint8_t
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_get_config_desc_full_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|ppbuf
parameter_list|,
name|uint16_t
modifier|*
name|plen
parameter_list|,
name|uint8_t
name|index
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_get_config_index_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
modifier|*
name|pindex
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_kernel_driver_active_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_process_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_reset_device_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_set_power_mode_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
name|power_mode
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_get_power_mode_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
modifier|*
name|power_mode
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_set_alt_index_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint8_t
name|alt_index
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_set_config_index_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|,
name|uint8_t
name|index
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_check_connected_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_device
modifier|*
name|pdev
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* USB transfer specific */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_tr_open_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_transfer
modifier|*
name|xfer
parameter_list|,
name|uint32_t
name|MaxBufSize
parameter_list|,
name|uint32_t
name|MaxFrameCount
parameter_list|,
name|uint8_t
name|ep_no
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_tr_close_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_transfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|libusb20_tr_clear_stall_sync_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_transfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|libusb20_tr_submit_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_transfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|libusb20_tr_cancel_async_t
function_decl|)
parameter_list|(
name|struct
name|libusb20_transfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|LIBUSB20_DEVICE
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, detach_kernel_driver) \   m(n, do_request_sync) \   m(n, get_config_desc_full) \   m(n, get_config_index) \   m(n, kernel_driver_active) \   m(n, process) \   m(n, reset_device) \   m(n, check_connected) \   m(n, set_power_mode) \   m(n, get_power_mode) \   m(n, set_alt_index) \   m(n, set_config_index) \   m(n, tr_cancel_async) \   m(n, tr_clear_stall_sync) \   m(n, tr_close) \   m(n, tr_open) \   m(n, tr_submit) \  struct libusb20_device_methods {
end_define

begin_macro
name|LIBUSB20_DEVICE
argument_list|(
argument|LIBUSB20_DEFINE
argument_list|,)
end_macro

begin_struct
unit|};
struct|struct
name|libusb20_backend
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|libusb20_device
argument_list|)
name|usb_devs
expr_stmt|;
specifier|const
name|struct
name|libusb20_backend_methods
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|libusb20_transfer
block|{
name|struct
name|libusb20_device
modifier|*
name|pdev
decl_stmt|;
comment|/* the USB device we belong to */
name|libusb20_tr_callback_t
modifier|*
name|callback
decl_stmt|;
name|void
modifier|*
name|priv_sc0
decl_stmt|;
comment|/* private client data */
name|void
modifier|*
name|priv_sc1
decl_stmt|;
comment|/* private client data */
comment|/* 	 * Pointer to a list of buffer pointers: 	 */
name|void
modifier|*
modifier|*
name|ppBuffer
decl_stmt|;
comment|/* 	 * Pointer to frame lengths, which are updated to actual length 	 * after the USB transfer completes: 	 */
name|uint32_t
modifier|*
name|pLength
decl_stmt|;
name|uint32_t
name|maxTotalLength
decl_stmt|;
name|uint32_t
name|maxFrames
decl_stmt|;
comment|/* total number of frames */
name|uint32_t
name|nFrames
decl_stmt|;
comment|/* total number of frames */
name|uint32_t
name|aFrames
decl_stmt|;
comment|/* actual number of frames */
name|uint32_t
name|timeout
decl_stmt|;
comment|/* isochronous completion time in milliseconds */
name|uint16_t
name|timeComplete
decl_stmt|;
name|uint16_t
name|trIndex
decl_stmt|;
name|uint16_t
name|maxPacketLen
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
comment|/* see LIBUSB20_TRANSFER_XXX */
name|uint8_t
name|status
decl_stmt|;
comment|/* see LIBUSB20_TRANSFER_XXX */
name|uint8_t
name|is_opened
decl_stmt|;
name|uint8_t
name|is_pending
decl_stmt|;
name|uint8_t
name|is_cancel
decl_stmt|;
name|uint8_t
name|is_draining
decl_stmt|;
name|uint8_t
name|is_restart
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|libusb20_device
block|{
comment|/* device descriptor */
name|struct
name|LIBUSB20_DEVICE_DESC_DECODED
name|ddesc
decl_stmt|;
comment|/* device timestamp */
name|union
name|libusb20_session_data
name|session_data
decl_stmt|;
comment|/* our device entry */
name|TAILQ_ENTRY
argument_list|(
argument|libusb20_device
argument_list|)
name|dev_entry
expr_stmt|;
comment|/* device methods */
specifier|const
name|struct
name|libusb20_device_methods
modifier|*
name|methods
decl_stmt|;
comment|/* backend methods */
specifier|const
name|struct
name|libusb20_backend_methods
modifier|*
name|beMethods
decl_stmt|;
comment|/* list of USB transfers */
name|struct
name|libusb20_transfer
modifier|*
name|pTransfer
decl_stmt|;
comment|/* private backend data */
name|void
modifier|*
name|privBeData
decl_stmt|;
comment|/* libUSB v0.1 and v1.0 compat data */
name|void
modifier|*
name|privLuData
decl_stmt|;
comment|/* claimed interface */
name|uint8_t
name|claimed_interface
decl_stmt|;
comment|/* device file handle */
name|int
name|file
decl_stmt|;
comment|/* device file handle (control transfers only) */
name|int
name|file_ctrl
decl_stmt|;
comment|/* debugging level */
name|int
name|debug
decl_stmt|;
comment|/* number of USB transfers */
name|uint16_t
name|nTransfer
decl_stmt|;
name|uint8_t
name|bus_number
decl_stmt|;
name|uint8_t
name|device_address
decl_stmt|;
name|uint8_t
name|usb_mode
decl_stmt|;
name|uint8_t
name|usb_speed
decl_stmt|;
name|uint8_t
name|is_opened
decl_stmt|;
name|char
name|usb_desc
index|[
literal|96
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|libusb20_backend_methods
name|libusb20_ugen20_backend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|libusb20_backend_methods
name|libusb20_linux_backend
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBUSB20_INT_H_ */
end_comment

end_unit

