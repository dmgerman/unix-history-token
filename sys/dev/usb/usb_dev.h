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
name|_USB_DEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_DEV_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USB_GLOBAL_INCLUDE_FILE
end_ifndef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|usb_fifo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_mbuf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|usb_symlink
block|{
name|TAILQ_ENTRY
argument_list|(
argument|usb_symlink
argument_list|)
name|sym_entry
expr_stmt|;
name|char
name|src_path
index|[
literal|32
index|]
decl_stmt|;
comment|/* Source path - including terminating 					 * zero */
name|char
name|dst_path
index|[
literal|32
index|]
decl_stmt|;
comment|/* Destination path - including 					 * terminating zero */
name|uint8_t
name|src_len
decl_stmt|;
comment|/* String length */
name|uint8_t
name|dst_len
decl_stmt|;
comment|/* String length */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Private per-device information.  */
end_comment

begin_struct
struct|struct
name|usb_cdev_privdata
block|{
name|struct
name|usb_bus
modifier|*
name|bus
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|udev
decl_stmt|;
name|struct
name|usb_interface
modifier|*
name|iface
decl_stmt|;
name|int
name|bus_index
decl_stmt|;
comment|/* bus index */
name|int
name|dev_index
decl_stmt|;
comment|/* device index */
name|int
name|ep_addr
decl_stmt|;
comment|/* endpoint address */
name|int
name|fflags
decl_stmt|;
name|uint8_t
name|fifo_index
decl_stmt|;
comment|/* FIFO index */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines a minimum re-implementation of the  * ifqueue structure in the kernel.  */
end_comment

begin_struct
struct|struct
name|usb_ifqueue
block|{
name|struct
name|usb_mbuf
modifier|*
name|ifq_head
decl_stmt|;
name|struct
name|usb_mbuf
modifier|*
name|ifq_tail
decl_stmt|;
name|usb_size_t
name|ifq_len
decl_stmt|;
name|usb_size_t
name|ifq_maxlen
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Private per-device and per-thread reference information  */
end_comment

begin_struct
struct|struct
name|usb_cdev_refdata
block|{
name|struct
name|usb_fifo
modifier|*
name|rxfifo
decl_stmt|;
name|struct
name|usb_fifo
modifier|*
name|txfifo
decl_stmt|;
name|uint8_t
name|is_read
decl_stmt|;
comment|/* location has read access */
name|uint8_t
name|is_write
decl_stmt|;
comment|/* location has write access */
name|uint8_t
name|is_uref
decl_stmt|;
comment|/* USB refcount decr. needed */
name|uint8_t
name|is_usbfs
decl_stmt|;
comment|/* USB-FS is active */
name|uint8_t
name|do_unlock
decl_stmt|;
comment|/* USB enum unlock needed */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_fs_privdata
block|{
name|int
name|bus_index
decl_stmt|;
name|int
name|dev_index
decl_stmt|;
name|int
name|ep_addr
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|int
name|fifo_index
decl_stmt|;
name|struct
name|cdev
modifier|*
name|cdev
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|usb_fs_privdata
argument_list|)
name|pd_next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Most of the fields in the "usb_fifo" structure are used by the  * generic USB access layer.  */
end_comment

begin_struct
struct|struct
name|usb_fifo
block|{
name|struct
name|usb_ifqueue
name|free_q
decl_stmt|;
name|struct
name|usb_ifqueue
name|used_q
decl_stmt|;
name|struct
name|selinfo
name|selinfo
decl_stmt|;
name|struct
name|cv
name|cv_io
decl_stmt|;
name|struct
name|cv
name|cv_drain
decl_stmt|;
name|struct
name|usb_fifo_methods
modifier|*
name|methods
decl_stmt|;
name|struct
name|usb_symlink
modifier|*
name|symlink
index|[
literal|2
index|]
decl_stmt|;
comment|/* our symlinks */
name|struct
name|proc
modifier|*
name|async_p
decl_stmt|;
comment|/* process that wants SIGIO */
name|struct
name|usb_fs_endpoint
modifier|*
name|fs_ep_ptr
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|udev
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|xfer
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
modifier|*
name|fs_xfer
decl_stmt|;
name|struct
name|mtx
modifier|*
name|priv_mtx
decl_stmt|;
comment|/* client data */
comment|/* set if FIFO is opened by a FILE: */
name|struct
name|usb_cdev_privdata
modifier|*
name|curr_cpd
decl_stmt|;
name|void
modifier|*
name|priv_sc0
decl_stmt|;
comment|/* client data */
name|void
modifier|*
name|priv_sc1
decl_stmt|;
comment|/* client data */
name|void
modifier|*
name|queue_data
decl_stmt|;
name|usb_timeout_t
name|timeout
decl_stmt|;
comment|/* timeout in milliseconds */
name|usb_frlength_t
name|bufsize
decl_stmt|;
comment|/* BULK and INTERRUPT buffer size */
name|usb_frcount_t
name|nframes
decl_stmt|;
comment|/* for isochronous mode */
name|uint16_t
name|dev_ep_index
decl_stmt|;
comment|/* our device endpoint index */
name|uint8_t
name|flag_sleeping
decl_stmt|;
comment|/* set if FIFO is sleeping */
name|uint8_t
name|flag_iscomplete
decl_stmt|;
comment|/* set if a USB transfer is complete */
name|uint8_t
name|flag_iserror
decl_stmt|;
comment|/* set if FIFO error happened */
name|uint8_t
name|flag_isselect
decl_stmt|;
comment|/* set if FIFO is selected */
name|uint8_t
name|flag_flushing
decl_stmt|;
comment|/* set if FIFO is flushing data */
name|uint8_t
name|flag_short
decl_stmt|;
comment|/* set if short_ok or force_short 					 * transfer flags should be set */
name|uint8_t
name|flag_stall
decl_stmt|;
comment|/* set if clear stall should be run */
name|uint8_t
name|flag_write_defrag
decl_stmt|;
comment|/* set to defrag written data */
name|uint8_t
name|flag_have_fragment
decl_stmt|;
comment|/* set if defragging */
name|uint8_t
name|iface_index
decl_stmt|;
comment|/* set to the interface we belong to */
name|uint8_t
name|fifo_index
decl_stmt|;
comment|/* set to the FIFO index in "struct 					 * usb_device" */
name|uint8_t
name|fs_ep_max
decl_stmt|;
name|uint8_t
name|fifo_zlp
decl_stmt|;
comment|/* zero length packet count */
name|uint8_t
name|refcount
decl_stmt|;
define|#
directive|define
name|USB_FIFO_REF_MAX
value|0xFF
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|cdevsw
name|usb_devsw
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|usb_fifo_wait
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
name|usb_fifo_signal
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
name|usb_fifo_opened
parameter_list|(
name|struct
name|usb_fifo
modifier|*
name|fifo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_symlink
modifier|*
name|usb_alloc_symlink
parameter_list|(
specifier|const
name|char
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_free_symlink
parameter_list|(
name|struct
name|usb_symlink
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_read_symlink
parameter_list|(
name|uint8_t
modifier|*
name|user_ptr
parameter_list|,
name|uint32_t
name|startentry
parameter_list|,
name|uint32_t
name|user_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_DEV_H_ */
end_comment

end_unit

