begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Including this file is mandatory for all USB related c-files in the  * kernel.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB2_CORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_CORE_H_
end_define

begin_comment
comment|/* Default USB configuration */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USB_NO_POLL
end_ifndef

begin_define
define|#
directive|define
name|USB_NO_POLL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USB_USE_CONDVAR
end_ifndef

begin_define
define|#
directive|define
name|USB_USE_CONDVAR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USB_TD_GET_PROC
end_ifndef

begin_define
define|#
directive|define
name|USB_TD_GET_PROC
parameter_list|(
name|td
parameter_list|)
value|(td)->td_proc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USB_PROC_GET_GID
end_ifndef

begin_define
define|#
directive|define
name|USB_PROC_GET_GID
parameter_list|(
name|td
parameter_list|)
value|(td)->p_pgid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USB_VNOPS_FO_CLOSE
end_ifndef

begin_define
define|#
directive|define
name|USB_VNOPS_FO_CLOSE
parameter_list|(
name|fp
parameter_list|,
name|td
parameter_list|,
name|perr
parameter_list|)
value|do {	\     (td)->td_fpop = (fp);			\     *(perr) = vnops.fo_close(fp, td);		\     (td)->td_fpop = NULL;			\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USB_VNOPS_FO_STAT
end_ifndef

begin_define
define|#
directive|define
name|USB_VNOPS_FO_STAT
parameter_list|(
name|fp
parameter_list|,
name|sb
parameter_list|,
name|cred
parameter_list|,
name|td
parameter_list|)
define|\
value|vnops.fo_stat(fp, sb, cred, td)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USB_VNOPS_FO_TRUNCATE
end_ifndef

begin_define
define|#
directive|define
name|USB_VNOPS_FO_TRUNCATE
parameter_list|(
name|fp
parameter_list|,
name|length
parameter_list|,
name|cred
parameter_list|,
name|td
parameter_list|)
define|\
value|vnops.fo_truncate(fp, length, cred, td)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include files */
end_comment

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb2/include/usb2_mfunc.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb2/include/usb2_revision.h>
end_include

begin_include
include|#
directive|include
file|"usb2_if.h"
end_include

begin_include
include|#
directive|include
file|"opt_usb.h"
end_include

begin_include
include|#
directive|include
file|"opt_bus.h"
end_include

begin_define
define|#
directive|define
name|USB_STACK_VERSION
value|2000
end_define

begin_comment
comment|/* 2.0 */
end_comment

begin_define
define|#
directive|define
name|USB_HOST_ALIGN
value|8
end_define

begin_comment
comment|/* bytes, must be power of two */
end_comment

begin_define
define|#
directive|define
name|USB_ROOT_HUB_ADDR
value|1
end_define

begin_comment
comment|/* value */
end_comment

begin_define
define|#
directive|define
name|USB_ISOC_TIME_MAX
value|128
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_FS_ISOC_UFRAME_MAX
value|4
end_define

begin_comment
comment|/* exclusive unit */
end_comment

begin_if
if|#
directive|if
operator|(
name|USB_FS_ISOC_UFRAME_MAX
operator|>
literal|6
operator|)
end_if

begin_error
error|#
directive|error
literal|"USB_FS_ISOC_UFRAME_MAX cannot be set higher than 6"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USB_MAX_FS_ISOC_FRAMES_PER_XFER
value|(120)
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_HS_ISOC_FRAMES_PER_XFER
value|(8*120)
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_IPACKET
value|8
end_define

begin_comment
comment|/* maximum size of the initial USB 					 * data packet */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USB_VERBOSE
end_ifndef

begin_define
define|#
directive|define
name|USB_VERBOSE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USB_HUB_MAX_DEPTH
value|5
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
comment|/*  * The following macro will return the current state of an USB  * transfer like defined by the "USB_ST_XXX" enums.  */
end_comment

begin_define
define|#
directive|define
name|USB_GET_STATE
parameter_list|(
name|xfer
parameter_list|)
value|((xfer)->usb2_state)
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
value|(((xfer)->flags_int.usb2_mode == \ 	USB_MODE_DEVICE) ? ((xfer->endpoint& UE_DIR_IN) ? 0 : 1) : \ 	((xfer->endpoint& UE_DIR_IN) ? 1 : 0))
end_define

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
comment|/* macros */
end_comment

begin_define
define|#
directive|define
name|usb2_callout_init_mtx
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
name|usb2_callout_reset
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
name|usb2_callout_stop
parameter_list|(
name|c
parameter_list|)
value|callout_stop(&(c)->co)
end_define

begin_define
define|#
directive|define
name|usb2_callout_drain
parameter_list|(
name|c
parameter_list|)
value|callout_drain(&(c)->co)
end_define

begin_define
define|#
directive|define
name|usb2_callout_pending
parameter_list|(
name|c
parameter_list|)
value|callout_pending(&(c)->co)
end_define

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
value|mtx_lock((_x)->xfer_mtx)
end_define

begin_define
define|#
directive|define
name|USB_XFER_UNLOCK
parameter_list|(
name|_x
parameter_list|)
value|mtx_unlock((_x)->xfer_mtx)
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
value|mtx_assert((_x)->xfer_mtx, _t)
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
name|usb2_bus
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb2_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb2_page
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb2_page_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb2_xfer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb2_xfer_root
struct_decl|;
end_struct_decl

begin_comment
comment|/* typedefs */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|usb2_error_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb2_callback_t
function_decl|)
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* structures */
end_comment

begin_comment
comment|/*  * This structure contains permissions.  */
end_comment

begin_struct
struct|struct
name|usb2_perm
block|{
name|uint32_t
name|uid
decl_stmt|;
name|uint32_t
name|gid
decl_stmt|;
name|uint16_t
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common queue structure for USB transfers.  */
end_comment

begin_struct
struct|struct
name|usb2_xfer_queue
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|usb2_xfer
argument_list|)
name|head
expr_stmt|;
name|struct
name|usb2_xfer
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
name|usb2_xfer_queue
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
comment|/*  * The following is a wrapper for the callout structure to ease  * porting the code to other platforms.  */
end_comment

begin_struct
struct|struct
name|usb2_callout
block|{
name|struct
name|callout
name|co
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines a set of USB transfer flags.  */
end_comment

begin_struct
struct|struct
name|usb2_xfer_flags
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
comment|/*  * The following structure defines a set of internal USB transfer  * flags.  */
end_comment

begin_struct
struct|struct
name|usb2_xfer_flags_int
block|{
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
name|uint8_t
name|isochronous_xfr
range|:
literal|1
decl_stmt|;
comment|/* set if isochronous transfer */
name|uint8_t
name|usb2_mode
range|:
literal|1
decl_stmt|;
comment|/* shadow copy of "udev->usb2_mode" */
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines the symmetric part of an USB config  * structure.  */
end_comment

begin_struct
struct|struct
name|usb2_config_sub
block|{
name|usb2_callback_t
modifier|*
name|callback
decl_stmt|;
comment|/* USB transfer callback */
name|uint32_t
name|bufsize
decl_stmt|;
comment|/* total pipe buffer size in bytes */
name|uint32_t
name|frames
decl_stmt|;
comment|/* maximum number of USB frames */
name|uint16_t
name|interval
decl_stmt|;
comment|/* interval in milliseconds */
define|#
directive|define
name|USB_DEFAULT_INTERVAL
value|0
name|uint16_t
name|timeout
decl_stmt|;
comment|/* transfer timeout in milliseconds */
name|struct
name|usb2_xfer_flags
name|flags
decl_stmt|;
comment|/* transfer flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure define an USB configuration, that basically  * is used when setting up an USB transfer.  */
end_comment

begin_struct
struct|struct
name|usb2_config
block|{
name|struct
name|usb2_config_sub
name|mh
decl_stmt|;
comment|/* parameters for USB_MODE_HOST */
name|struct
name|usb2_config_sub
name|md
decl_stmt|;
comment|/* parameters for USB_MODE_DEVICE */
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
comment|/*  * The following structure defines an USB transfer.  */
end_comment

begin_struct
struct|struct
name|usb2_xfer
block|{
name|struct
name|usb2_callout
name|timeout_handle
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|usb2_xfer
argument_list|)
name|wait_entry
expr_stmt|;
comment|/* used at various places */
name|struct
name|usb2_page_cache
modifier|*
name|buf_fixup
decl_stmt|;
comment|/* fixup buffer(s) */
name|struct
name|usb2_xfer_queue
modifier|*
name|wait_queue
decl_stmt|;
comment|/* pointer to queue that we 						 * are waiting on */
name|struct
name|usb2_page
modifier|*
name|dma_page_ptr
decl_stmt|;
name|struct
name|usb2_pipe
modifier|*
name|pipe
decl_stmt|;
comment|/* our USB pipe */
name|struct
name|usb2_device
modifier|*
name|udev
decl_stmt|;
name|struct
name|mtx
modifier|*
name|xfer_mtx
decl_stmt|;
comment|/* cannot be changed during operation */
name|struct
name|usb2_xfer_root
modifier|*
name|usb2_root
decl_stmt|;
comment|/* used by HC driver */
name|void
modifier|*
name|usb2_sc
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
name|uint32_t
modifier|*
name|frlengths
decl_stmt|;
name|struct
name|usb2_page_cache
modifier|*
name|frbuffers
decl_stmt|;
name|usb2_callback_t
modifier|*
name|callback
decl_stmt|;
name|uint32_t
name|max_usb2_frame_size
decl_stmt|;
name|uint32_t
name|max_data_length
decl_stmt|;
name|uint32_t
name|sumlen
decl_stmt|;
comment|/* sum of all lengths in bytes */
name|uint32_t
name|actlen
decl_stmt|;
comment|/* actual length in bytes */
name|uint32_t
name|timeout
decl_stmt|;
comment|/* milliseconds */
define|#
directive|define
name|USB_NO_TIMEOUT
value|0
define|#
directive|define
name|USB_DEFAULT_TIMEOUT
value|5000
comment|/* 5000 ms = 5 seconds */
name|uint32_t
name|max_frame_count
decl_stmt|;
comment|/* initial value of "nframes" after 					 * setup */
name|uint32_t
name|nframes
decl_stmt|;
comment|/* number of USB frames to transfer */
name|uint32_t
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
name|uint16_t
name|interval
decl_stmt|;
comment|/* milliseconds */
name|uint8_t
name|address
decl_stmt|;
comment|/* physical USB address */
name|uint8_t
name|endpoint
decl_stmt|;
comment|/* physical USB endpoint */
name|uint8_t
name|max_packet_count
decl_stmt|;
name|uint8_t
name|usb2_smask
decl_stmt|;
name|uint8_t
name|usb2_cmask
decl_stmt|;
name|uint8_t
name|usb2_uframe
decl_stmt|;
name|uint8_t
name|usb2_state
decl_stmt|;
name|usb2_error_t
name|error
decl_stmt|;
name|struct
name|usb2_xfer_flags
name|flags
decl_stmt|;
name|struct
name|usb2_xfer_flags_int
name|flags_int
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure keeps information that is used to match  * against an array of "usb2_device_id" elements.  */
end_comment

begin_struct
struct|struct
name|usb2_lookup_info
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
name|usb2_attach_arg
block|{
name|struct
name|usb2_lookup_info
name|info
decl_stmt|;
name|device_t
name|temp_dev
decl_stmt|;
comment|/* for internal use */
specifier|const
name|void
modifier|*
name|driver_info
decl_stmt|;
comment|/* for internal use */
name|struct
name|usb2_device
modifier|*
name|device
decl_stmt|;
comment|/* current device */
name|struct
name|usb2_interface
modifier|*
name|iface
decl_stmt|;
comment|/* current interface */
name|uint8_t
name|usb2_mode
decl_stmt|;
comment|/* see USB_MODE_XXX */
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
comment|/* Structure used when referring an USB device */
end_comment

begin_struct
struct|struct
name|usb2_location
block|{
name|struct
name|usb2_bus
modifier|*
name|bus
decl_stmt|;
name|struct
name|usb2_device
modifier|*
name|udev
decl_stmt|;
name|struct
name|usb2_interface
modifier|*
name|iface
decl_stmt|;
name|struct
name|usb2_fifo
modifier|*
name|rxfifo
decl_stmt|;
name|struct
name|usb2_fifo
modifier|*
name|txfifo
decl_stmt|;
name|uint32_t
name|devloc
decl_stmt|;
comment|/* original devloc */
name|uint16_t
name|bus_index
decl_stmt|;
comment|/* bus index */
name|uint8_t
name|dev_index
decl_stmt|;
comment|/* device index */
name|uint8_t
name|iface_index
decl_stmt|;
comment|/* interface index */
name|uint8_t
name|fifo_index
decl_stmt|;
comment|/* FIFO index */
name|uint8_t
name|is_read
decl_stmt|;
comment|/* set if location has read access */
name|uint8_t
name|is_write
decl_stmt|;
comment|/* set if location has write access */
name|uint8_t
name|is_uref
decl_stmt|;
comment|/* set if USB refcount decr. needed */
name|uint8_t
name|is_usbfs
decl_stmt|;
comment|/* set if USB-FS is active */
block|}
struct|;
end_struct

begin_comment
comment|/* external variables */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USBDEV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USBHC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|usb2_ref_lock
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
name|usb2_malloc_type
typedef|;
end_typedef

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|usb2_errstr
parameter_list|(
name|usb2_error_t
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb2_config_descriptor
modifier|*
name|usb2_get_config_descriptor
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
name|usb2_device_descriptor
modifier|*
name|usb2_get_device_descriptor
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
name|usb2_interface
modifier|*
name|usb2_get_iface
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
name|struct
name|usb2_interface_descriptor
modifier|*
name|usb2_get_interface_descriptor
parameter_list|(
name|struct
name|usb2_interface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_clear_stall_callback
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer1
parameter_list|,
name|struct
name|usb2_xfer
modifier|*
name|xfer2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_get_interface_altindex
parameter_list|(
name|struct
name|usb2_interface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb2_error_t
name|usb2_set_alt_interface_index
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
name|alt_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_get_speed
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb2_error_t
name|usb2_transfer_setup
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|ifaces
parameter_list|,
name|struct
name|usb2_xfer
modifier|*
modifier|*
name|pxfer
parameter_list|,
specifier|const
name|struct
name|usb2_config
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
name|usb2_set_frame_data
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|frindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_set_frame_offset
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|frindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_start_hardware
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_transfer_clear_stall
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_transfer_drain
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_transfer_set_stall
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_transfer_start
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_transfer_stop
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_transfer_unsetup
parameter_list|(
name|struct
name|usb2_xfer
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
name|usb2_error_t
name|usb2_ref_device
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|struct
name|usb2_location
modifier|*
name|ploc
parameter_list|,
name|uint32_t
name|devloc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_unref_device
parameter_list|(
name|struct
name|usb2_location
modifier|*
name|ploc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_set_parent_iface
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
name|parent_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_set_iface_perm
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint32_t
name|uid
parameter_list|,
name|uint32_t
name|gid
parameter_list|,
name|uint16_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_get_bus_index
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_get_device_index
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_CORE_H_ */
end_comment

end_unit

