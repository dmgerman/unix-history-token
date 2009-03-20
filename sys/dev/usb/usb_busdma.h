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
name|_USB2_BUSDMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_BUSDMA_H_
end_define

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/* defines */
end_comment

begin_define
define|#
directive|define
name|USB_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_comment
comment|/* use system PAGE_SIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|700020
operator|)
end_if

begin_define
define|#
directive|define
name|USB_GET_DMA_TAG
parameter_list|(
name|dev
parameter_list|)
value|bus_get_dma_tag(dev)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USB_GET_DMA_TAG
parameter_list|(
name|dev
parameter_list|)
value|NULL
end_define

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* structure prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|usb2_xfer_root
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb2_dma_parent_tag
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The following typedef defines the USB DMA load done callback.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb2_dma_callback_t
function_decl|)
parameter_list|(
name|struct
name|usb2_dma_parent_tag
modifier|*
name|udpt
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The following structure defines physical and non kernel virtual  * address of a memory page having size USB_PAGE_SIZE.  */
end_comment

begin_struct
struct|struct
name|usb2_page
block|{
if|#
directive|if
name|USB_HAVE_BUSDMA
name|bus_size_t
name|physaddr
decl_stmt|;
name|void
modifier|*
name|buffer
decl_stmt|;
comment|/* non Kernel Virtual Address */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure is used when needing the kernel virtual  * pointer and the physical address belonging to an offset in an USB  * page cache.  */
end_comment

begin_struct
struct|struct
name|usb2_page_search
block|{
name|void
modifier|*
name|buffer
decl_stmt|;
if|#
directive|if
name|USB_HAVE_BUSDMA
name|bus_size_t
name|physaddr
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure is used to keep information about a DMA  * memory allocation.  */
end_comment

begin_struct
struct|struct
name|usb2_page_cache
block|{
if|#
directive|if
name|USB_HAVE_BUSDMA
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|USB_HAVE_BUSDMA
operator|&&
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_dma_segment_t
modifier|*
name|p_seg
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|USB_HAVE_BUSDMA
name|struct
name|usb2_page
modifier|*
name|page_start
decl_stmt|;
endif|#
directive|endif
name|struct
name|usb2_dma_parent_tag
modifier|*
name|tag_parent
decl_stmt|;
comment|/* always set */
name|void
modifier|*
name|buffer
decl_stmt|;
comment|/* virtual buffer pointer */
if|#
directive|if
name|USB_HAVE_BUSDMA
operator|&&
name|defined
argument_list|(
name|_NetBSD__
argument_list|)
name|int
name|n_seg
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|USB_HAVE_BUSDMA
name|uint32_t
name|page_offset_buf
decl_stmt|;
name|uint32_t
name|page_offset_end
decl_stmt|;
name|uint8_t
name|isread
range|:
literal|1
decl_stmt|;
comment|/* set if we are currently reading 					 * from the memory. Else write. */
name|uint8_t
name|ismultiseg
range|:
literal|1
decl_stmt|;
comment|/* set if we can have multiple 					 * segments */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure describes the parent USB DMA tag.  */
end_comment

begin_struct
struct|struct
name|usb2_dma_parent_tag
block|{
if|#
directive|if
name|USB_HAVE_BUSDMA
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|struct
name|cv
name|cv
index|[
literal|1
index|]
decl_stmt|;
comment|/* internal condition variable */
endif|#
directive|endif
if|#
directive|if
name|USB_HAVE_BUSDMA
name|bus_dma_tag_t
name|tag
decl_stmt|;
comment|/* always set */
name|struct
name|mtx
modifier|*
name|mtx
decl_stmt|;
comment|/* private mutex, always set */
name|usb2_dma_callback_t
modifier|*
name|func
decl_stmt|;
comment|/* load complete callback function */
name|struct
name|usb2_dma_tag
modifier|*
name|utag_first
decl_stmt|;
comment|/* pointer to first USB DMA tag */
name|uint8_t
name|dma_error
decl_stmt|;
comment|/* set if DMA load operation failed */
name|uint8_t
name|dma_bits
decl_stmt|;
comment|/* number of DMA address lines */
name|uint8_t
name|utag_max
decl_stmt|;
comment|/* number of USB DMA tags */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure describes an USB DMA tag.  */
end_comment

begin_struct
struct|struct
name|usb2_dma_tag
block|{
if|#
directive|if
name|USB_HAVE_BUSDMA
operator|&&
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|bus_dma_segment_t
modifier|*
name|p_seg
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|USB_HAVE_BUSDMA
name|struct
name|usb2_dma_parent_tag
modifier|*
name|tag_parent
decl_stmt|;
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|uint32_t
name|align
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|USB_HAVE_BUSDMA
operator|&&
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|uint32_t
name|n_seg
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|int
name|usb2_uiomove
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|uint32_t
name|pc_offset
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb2_dma_tag
modifier|*
name|usb2_dma_tag_find
parameter_list|(
name|struct
name|usb2_dma_parent_tag
modifier|*
name|udpt
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|uint32_t
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_pc_alloc_mem
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|,
name|struct
name|usb2_page
modifier|*
name|pg
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|uint32_t
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_pc_dmamap_create
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_pc_load_mem
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|,
name|uint32_t
name|size
parameter_list|,
name|uint8_t
name|sync
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_bdma_done_event
parameter_list|(
name|struct
name|usb2_dma_parent_tag
modifier|*
name|udpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_bdma_post_sync
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
name|usb2_bdma_pre_sync
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
name|usb2_bdma_work_loop
parameter_list|(
name|struct
name|usb2_xfer_queue
modifier|*
name|pq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_bzero
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|cache
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_copy_in
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|cache
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb2_copy_in_user
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|cache
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_copy_out
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|cache
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb2_copy_out_user
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|cache
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_dma_tag_setup
parameter_list|(
name|struct
name|usb2_dma_parent_tag
modifier|*
name|udpt
parameter_list|,
name|struct
name|usb2_dma_tag
modifier|*
name|udt
parameter_list|,
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|usb2_dma_callback_t
modifier|*
name|func
parameter_list|,
name|uint8_t
name|ndmabits
parameter_list|,
name|uint8_t
name|nudt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_dma_tag_unsetup
parameter_list|(
name|struct
name|usb2_dma_parent_tag
modifier|*
name|udpt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_get_page
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|struct
name|usb2_page_search
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_m_copy_in
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|cache
parameter_list|,
name|uint32_t
name|dst_offset
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint32_t
name|src_offset
parameter_list|,
name|uint32_t
name|src_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_pc_cpu_flush
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_pc_cpu_invalidate
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_pc_dmamap_destroy
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_pc_free_mem
parameter_list|(
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_BUSDMA_H_ */
end_comment

end_unit

