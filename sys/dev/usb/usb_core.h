begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Including this file is mandatory for all USB related c-files in the kernel.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_CORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_CORE_H_
end_define

begin_comment
comment|/*  * The following macro will tell if an USB transfer is currently  * receiving or transferring data.  */
end_comment

begin_define
define|#
directive|define
name|USB_GET_DATA_ISREAD
parameter_list|(
name|xfer
parameter_list|)
value|((xfer)->flags_int.usb_mode == \ 	USB_MODE_DEVICE ? (((xfer)->endpointno& UE_DIR_IN) ? 0 : 1) : \ 	(((xfer)->endpointno& UE_DIR_IN) ? 1 : 0))
end_define

begin_comment
comment|/* macros */
end_comment

begin_define
define|#
directive|define
name|USB_BUS_LOCK
parameter_list|(
name|_b
parameter_list|)
value|mtx_lock(&(_b)->bus_mtx)
end_define

begin_define
define|#
directive|define
name|USB_BUS_UNLOCK
parameter_list|(
name|_b
parameter_list|)
value|mtx_unlock(&(_b)->bus_mtx)
end_define

begin_define
define|#
directive|define
name|USB_BUS_LOCK_ASSERT
parameter_list|(
name|_b
parameter_list|,
name|_t
parameter_list|)
value|mtx_assert(&(_b)->bus_mtx, _t)
end_define

begin_define
define|#
directive|define
name|USB_XFER_LOCK
parameter_list|(
name|_x
parameter_list|)
value|mtx_lock((_x)->xroot->xfer_mtx)
end_define

begin_define
define|#
directive|define
name|USB_XFER_UNLOCK
parameter_list|(
name|_x
parameter_list|)
value|mtx_unlock((_x)->xroot->xfer_mtx)
end_define

begin_define
define|#
directive|define
name|USB_XFER_LOCK_ASSERT
parameter_list|(
name|_x
parameter_list|,
name|_t
parameter_list|)
value|mtx_assert((_x)->xroot->xfer_mtx, _t)
end_define

begin_comment
comment|/* helper for converting pointers to integers */
end_comment

begin_define
define|#
directive|define
name|USB_P2U
parameter_list|(
name|ptr
parameter_list|)
define|\
value|(((const uint8_t *)(ptr)) - ((const uint8_t *)0))
end_define

begin_comment
comment|/* helper for computing offsets */
end_comment

begin_define
define|#
directive|define
name|USB_ADD_BYTES
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|((void *)(USB_P2U(ptr) + (size)))
end_define

begin_comment
comment|/* debug macro */
end_comment

begin_define
define|#
directive|define
name|USB_ASSERT
value|KASSERT
end_define

begin_comment
comment|/* structure prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_bus
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_device_request
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_page
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_page_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_xfer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_xfer_root
struct_decl|;
end_struct_decl

begin_comment
comment|/* typedefs */
end_comment

begin_comment
comment|/* structures */
end_comment

begin_comment
comment|/*  * The following structure defines a set of internal USB transfer  * flags.  */
end_comment

begin_struct
struct|struct
name|usb_xfer_flags_int
block|{
name|enum
name|usb_hc_mode
name|usb_mode
decl_stmt|;
comment|/* shadow copy of "udev->usb_mode" */
name|uint16_t
name|control_rem
decl_stmt|;
comment|/* remainder in bytes */
name|uint8_t
name|open
range|:
literal|1
decl_stmt|;
comment|/* set if USB pipe has been opened */
name|uint8_t
name|transferring
range|:
literal|1
decl_stmt|;
comment|/* set if an USB transfer is in 					 * progress */
name|uint8_t
name|did_dma_delay
range|:
literal|1
decl_stmt|;
comment|/* set if we waited for HW DMA */
name|uint8_t
name|did_close
range|:
literal|1
decl_stmt|;
comment|/* set if we closed the USB transfer */
name|uint8_t
name|draining
range|:
literal|1
decl_stmt|;
comment|/* set if we are draining an USB 					 * transfer */
name|uint8_t
name|started
range|:
literal|1
decl_stmt|;
comment|/* keeps track of started or stopped */
name|uint8_t
name|bandwidth_reclaimed
range|:
literal|1
decl_stmt|;
name|uint8_t
name|control_xfr
range|:
literal|1
decl_stmt|;
comment|/* set if control transfer */
name|uint8_t
name|control_hdr
range|:
literal|1
decl_stmt|;
comment|/* set if control header should be 					 * sent */
name|uint8_t
name|control_act
range|:
literal|1
decl_stmt|;
comment|/* set if control transfer is active */
name|uint8_t
name|control_stall
range|:
literal|1
decl_stmt|;
comment|/* set if control transfer should be stalled */
name|uint8_t
name|short_frames_ok
range|:
literal|1
decl_stmt|;
comment|/* filtered version */
name|uint8_t
name|short_xfer_ok
range|:
literal|1
decl_stmt|;
comment|/* filtered version */
if|#
directive|if
name|USB_HAVE_BUSDMA
name|uint8_t
name|bdma_enable
range|:
literal|1
decl_stmt|;
comment|/* filtered version (only set if 					 * hardware supports DMA) */
name|uint8_t
name|bdma_no_post_sync
range|:
literal|1
decl_stmt|;
comment|/* set if the USB callback wrapper 					 * should not do the BUS-DMA post sync 					 * operation */
name|uint8_t
name|bdma_setup
range|:
literal|1
decl_stmt|;
comment|/* set if BUS-DMA has been setup */
endif|#
directive|endif
name|uint8_t
name|isochronous_xfr
range|:
literal|1
decl_stmt|;
comment|/* set if isochronous transfer */
name|uint8_t
name|curr_dma_set
range|:
literal|1
decl_stmt|;
comment|/* used by USB HC/DC driver */
name|uint8_t
name|can_cancel_immed
range|:
literal|1
decl_stmt|;
comment|/* set if USB transfer can be 					 * cancelled immediately */
name|uint8_t
name|doing_callback
range|:
literal|1
decl_stmt|;
comment|/* set if executing the callback */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB transfer.  */
end_comment

begin_struct
struct|struct
name|usb_xfer
block|{
name|struct
name|usb_callout
name|timeout_handle
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|usb_xfer
argument_list|)
name|wait_entry
expr_stmt|;
comment|/* used at various places */
name|struct
name|usb_page_cache
modifier|*
name|buf_fixup
decl_stmt|;
comment|/* fixup buffer(s) */
name|struct
name|usb_xfer_queue
modifier|*
name|wait_queue
decl_stmt|;
comment|/* pointer to queue that we 						 * are waiting on */
name|struct
name|usb_page
modifier|*
name|dma_page_ptr
decl_stmt|;
name|struct
name|usb_endpoint
modifier|*
name|endpoint
decl_stmt|;
comment|/* our USB endpoint */
name|struct
name|usb_xfer_root
modifier|*
name|xroot
decl_stmt|;
comment|/* used by HC driver */
name|void
modifier|*
name|qh_start
index|[
literal|2
index|]
decl_stmt|;
comment|/* used by HC driver */
name|void
modifier|*
name|td_start
index|[
literal|2
index|]
decl_stmt|;
comment|/* used by HC driver */
name|void
modifier|*
name|td_transfer_first
decl_stmt|;
comment|/* used by HC driver */
name|void
modifier|*
name|td_transfer_last
decl_stmt|;
comment|/* used by HC driver */
name|void
modifier|*
name|td_transfer_cache
decl_stmt|;
comment|/* used by HC driver */
name|void
modifier|*
name|priv_sc
decl_stmt|;
comment|/* device driver data pointer 1 */
name|void
modifier|*
name|priv_fifo
decl_stmt|;
comment|/* device driver data pointer 2 */
name|void
modifier|*
name|local_buffer
decl_stmt|;
name|usb_frlength_t
modifier|*
name|frlengths
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|frbuffers
decl_stmt|;
name|usb_callback_t
modifier|*
name|callback
decl_stmt|;
name|usb_frlength_t
name|max_hc_frame_size
decl_stmt|;
name|usb_frlength_t
name|max_data_length
decl_stmt|;
name|usb_frlength_t
name|sumlen
decl_stmt|;
comment|/* sum of all lengths in bytes */
name|usb_frlength_t
name|actlen
decl_stmt|;
comment|/* actual length in bytes */
name|usb_timeout_t
name|timeout
decl_stmt|;
comment|/* milliseconds */
name|usb_frcount_t
name|max_frame_count
decl_stmt|;
comment|/* initial value of "nframes" after 					 * setup */
name|usb_frcount_t
name|nframes
decl_stmt|;
comment|/* number of USB frames to transfer */
name|usb_frcount_t
name|aframes
decl_stmt|;
comment|/* actual number of USB frames 					 * transferred */
name|uint16_t
name|max_packet_size
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
name|uint16_t
name|qh_pos
decl_stmt|;
name|uint16_t
name|isoc_time_complete
decl_stmt|;
comment|/* in ms */
name|usb_timeout_t
name|interval
decl_stmt|;
comment|/* milliseconds */
name|uint8_t
name|address
decl_stmt|;
comment|/* physical USB address */
name|uint8_t
name|endpointno
decl_stmt|;
comment|/* physical USB endpoint */
name|uint8_t
name|max_packet_count
decl_stmt|;
name|uint8_t
name|usb_state
decl_stmt|;
name|uint8_t
name|fps_shift
decl_stmt|;
comment|/* down shift of FPS, 0..3 */
name|usb_error_t
name|error
decl_stmt|;
name|struct
name|usb_xfer_flags
name|flags
decl_stmt|;
name|struct
name|usb_xfer_flags_int
name|flags_int
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* external variables */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|usb_ref_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* typedefs */
end_comment

begin_typedef
typedef|typedef
name|struct
name|malloc_type
modifier|*
name|usb_malloc_type
typedef|;
end_typedef

begin_comment
comment|/* prototypes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_CORE_H_ */
end_comment

end_unit

