begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_HAL_RING_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_RING_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_typedef
typedef|typedef
name|u8
name|vxge_hal_ring_block_t
index|[
name|VXGE_OS_HOST_PAGE_SIZE
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VXGE_HAL_RING_NEXT_BLOCK_POINTER_OFFSET
value|(VXGE_OS_HOST_PAGE_SIZE-8)
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_RING_MEMBLOCK_IDX_OFFSET
value|(VXGE_OS_HOST_PAGE_SIZE-16)
end_define

begin_comment
comment|/*  * struct __hal_ring_rxd_priv_t - Receive descriptor HAL-private data.  * @dma_addr: DMA (mapped) address of _this_ descriptor.  * @dma_handle: DMA handle used to map the descriptor onto device.  * @dma_offset: Descriptor's offset in the memory block. HAL allocates  *		descriptors in memory blocks of %VXGE_OS_HOST_PAGE_SIZE  *		bytes. Each memblock is contiguous DMA-able memory. Each  *		memblock contains 1 or more 4KB RxD blocks visible to the  *		X3100 hardware.  * @dma_object: DMA address and handle of the memory block that contains  *		the descriptor. This member is used only in the "checked"  *		version of the HAL (to enforce certain assertions);  *		otherwise it gets compiled out.  * @allocated: True if the descriptor is reserved, 0 otherwise. Internal usage.  * @db_bytes: Number of doorbell bytes to be posted for this Rxd. This includes  *		next RxD block pointers  *  * Per-receive decsriptor HAL-private data. HAL uses the space to keep DMA  * information associated with the descriptor. Note that ULD can ask HAL  * to allocate additional per-descriptor space for its own (ULD-specific)  * purposes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__hal_ring_rxd_priv_t
block|{
name|dma_addr_t
name|dma_addr
decl_stmt|;
name|pci_dma_h
name|dma_handle
decl_stmt|;
name|ptrdiff_t
name|dma_offset
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|VXGE_DEBUG_ASSERT
argument_list|)
name|vxge_hal_mempool_dma_t
modifier|*
name|dma_object
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|VXGE_OS_MEMORY_CHECK
argument_list|)
name|u32
name|allocated
decl_stmt|;
endif|#
directive|endif
name|u32
name|db_bytes
decl_stmt|;
block|}
name|__hal_ring_rxd_priv_t
typedef|;
end_typedef

begin_comment
comment|/*  * struct __hal_ring_t - Ring channel.  * @channel: Channel "base" of this ring, the common part of all HAL  *	channels.  * @mempool: Memory pool, the pool from which descriptors get allocated.  *	(See vxge_hal_mm.h).  * @config: Ring configuration, part of device configuration  *	(see vxge_hal_device_config_t {}).  * @ring_length: Length of the ring  * @buffer_mode: 1, 3, or 5. The value specifies a receive buffer mode,  *	as per X3100 User Guide.  * @indicate_max_pkts: Maximum number of packets processed within a single  *	interrupt. Can be used to limit the time spent inside hw interrupt.  * @rxd_size: RxD sizes for 1-, 3- or 5- buffer modes. As per X3100 spec,  *	1-buffer mode descriptor is 32 byte long, etc.  * @rxd_priv_size: Per RxD size reserved (by HAL) for ULD to keep per-descriptor  *		data (e.g., DMA handle for Solaris)  * @per_rxd_space: Per rxd space requested by ULD  * @rxds_per_block: Number of descriptors per hardware-defined RxD  *		block. Depends on the (1-, 3-, 5-) buffer mode.  * @rxdblock_priv_size: Reserved at the end of each RxD block. HAL internal  *			usage. Not to confuse with @rxd_priv_size.  * @rxd_mem_avail: Available RxD memory  * @db_byte_count: Number of doorbell bytes to be posted  * @cmpl_cnt: Completion counter. Is reset to zero upon entering the ISR.  *	Used in conjunction with @indicate_max_pkts.  * @active_sw_lros: List of Software LRO sessions in progess  * @active_sw_lro_count: Number of Software LRO sessions in progess  * @free_sw_lros: List of Software LRO sessions free  * @free_sw_lro_count: Number of Software LRO sessions free  * @sw_lro_lock: LRO session lists' lock  * @callback: Channel completion callback. HAL invokes the callback when there  *	    are new completions on that channel. In many implementations  *	    the @callback executes in the hw interrupt context.  * @rxd_init: Channel's descriptor-initialize callback.  *	    See vxge_hal_ring_rxd_init_f {}.  *	    If not NULL, HAL invokes the callback when opening the ring.  * @rxd_term: Channel's descriptor-terminate callback. If not NULL,  *	HAL invokes the callback when closing the corresponding channel.  *	See also vxge_hal_channel_rxd_term_f {}.  * @stats: Statistics for ring  * Ring channel.  *  * Note: The structure is cache line aligned to better utilize  *	   CPU cache performance.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__hal_ring_t
block|{
name|__hal_channel_t
name|channel
decl_stmt|;
name|vxge_hal_mempool_t
modifier|*
name|mempool
decl_stmt|;
name|vxge_hal_ring_config_t
modifier|*
name|config
decl_stmt|;
name|u32
name|ring_length
decl_stmt|;
name|u32
name|buffer_mode
decl_stmt|;
name|u32
name|indicate_max_pkts
decl_stmt|;
name|u32
name|rxd_size
decl_stmt|;
name|u32
name|rxd_priv_size
decl_stmt|;
name|u32
name|per_rxd_space
decl_stmt|;
name|u32
name|rxds_per_block
decl_stmt|;
name|u32
name|rxdblock_priv_size
decl_stmt|;
name|u32
name|rxd_mem_avail
decl_stmt|;
name|u32
name|db_byte_count
decl_stmt|;
name|u32
name|cmpl_cnt
decl_stmt|;
name|vxge_hal_ring_callback_f
name|callback
decl_stmt|;
name|vxge_hal_ring_rxd_init_f
name|rxd_init
decl_stmt|;
name|vxge_hal_ring_rxd_term_f
name|rxd_term
decl_stmt|;
name|vxge_hal_vpath_stats_sw_ring_info_t
modifier|*
name|stats
decl_stmt|;
block|}
name|__vxge_os_attr_cacheline_aligned
name|__hal_ring_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VXGE_HAL_RING_ULD_PRIV
parameter_list|(
name|ring
parameter_list|,
name|rxdh
parameter_list|)
define|\
value|ring->channel.dtr_arr[						\ 	    ((vxge_hal_ring_rxd_5_t *)(rxdh))->host_control].uld_priv
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_RING_HAL_PRIV
parameter_list|(
name|ring
parameter_list|,
name|rxdh
parameter_list|)
define|\
value|((__hal_ring_rxd_priv_t *)(ring->channel.dtr_arr[		\ 	    ((vxge_hal_ring_rxd_5_t *)(rxdh))->host_control].hal_priv))
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_RING_POST_DOORBELL
parameter_list|(
name|vph
parameter_list|,
name|ringh
parameter_list|)
define|\
value|{									\ 	if (((__hal_ring_t *)(ringh))->config->post_mode ==		\ 	    VXGE_HAL_RING_POST_MODE_DOORBELL) {				\ 		vxge_hal_ring_rxd_post_post_db(vph);			\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|VXGE_HAL_RING_RXD_INDEX
parameter_list|(
name|rxdp
parameter_list|)
define|\
value|(u32)((vxge_hal_ring_rxd_5_t *)rxdp)->host_control
end_define

begin_comment
comment|/* ========================== RING PRIVATE API ============================ */
end_comment

begin_function_decl
name|u64
name|__hal_ring_first_block_address_get
parameter_list|(
name|vxge_hal_ring_h
name|ringh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_ring_create
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|,
name|vxge_hal_ring_attr_t
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_ring_abort
parameter_list|(
name|vxge_hal_ring_h
name|ringh
parameter_list|,
name|vxge_hal_reopen_e
name|reopen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_ring_reset
parameter_list|(
name|vxge_hal_ring_h
name|ringh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__hal_ring_delete
parameter_list|(
name|vxge_hal_vpath_h
name|vpath_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|vxge_hal_ring_initial_replenish
parameter_list|(
name|__hal_ring_t
modifier|*
name|ring
parameter_list|,
name|vxge_hal_reopen_e
name|reopen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vxge_hal_status_e
name|__hal_ring_frame_length_set
parameter_list|(
name|__hal_virtualpath_t
modifier|*
name|vpath
parameter_list|,
name|u32
name|new_frmlen
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_RING_H */
end_comment

end_unit

