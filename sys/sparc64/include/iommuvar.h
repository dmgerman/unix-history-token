begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: iommuvar.h,v 1.9 2001/07/20 00:07:13 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IOMMUVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IOMMUVAR_H_
end_define

begin_define
define|#
directive|define
name|IO_PAGE_SIZE
value|PAGE_SIZE_8K
end_define

begin_define
define|#
directive|define
name|IO_PAGE_MASK
value|PAGE_MASK_8K
end_define

begin_define
define|#
directive|define
name|IO_PAGE_SHIFT
value|PAGE_SHIFT_8K
end_define

begin_define
define|#
directive|define
name|round_io_page
parameter_list|(
name|x
parameter_list|)
value|round_page(x)
end_define

begin_define
define|#
directive|define
name|trunc_io_page
parameter_list|(
name|x
parameter_list|)
value|trunc_page(x)
end_define

begin_comment
comment|/*  * per-IOMMU state  */
end_comment

begin_struct
struct|struct
name|iommu_state
block|{
name|vm_offset_t
name|is_ptsb
decl_stmt|;
comment|/* TSB physical address */
name|u_int64_t
modifier|*
name|is_tsb
decl_stmt|;
comment|/* TSB virtual address */
name|int
name|is_tsbsize
decl_stmt|;
comment|/* 0 = 8K, ... */
name|u_int64_t
name|is_dvmabase
decl_stmt|;
name|int64_t
name|is_cr
decl_stmt|;
comment|/* IOMMU control register value */
name|struct
name|rman
name|is_dvma_rman
decl_stmt|;
comment|/* DVMA map for this instance */
name|vm_offset_t
name|is_flushpa
index|[
literal|2
index|]
decl_stmt|;
specifier|volatile
name|int64_t
modifier|*
name|is_flushva
index|[
literal|2
index|]
decl_stmt|;
comment|/* 	 * When a flush is completed, 64 bytes will be stored at the given 	 * location, the first double word being 1, to indicate completion. 	 * The lower 6 address bits are ignored, so the addresses need to be 	 * suitably aligned; over-allocate a large enough margin to be able 	 * to adjust it. 	 * Two such buffers are needed. 	 * Needs to be volatile or egcs optimizes away loads. 	 */
specifier|volatile
name|char
name|is_flush
index|[
name|STRBUF_FLUSHSYNC_NBYTES
operator|*
literal|3
operator|-
literal|1
index|]
decl_stmt|;
comment|/* copies of our parents state, to allow us to be self contained */
name|bus_space_tag_t
name|is_bustag
decl_stmt|;
comment|/* our bus tag */
name|bus_space_handle_t
name|is_bushandle
decl_stmt|;
name|bus_addr_t
name|is_iommu
decl_stmt|;
comment|/* IOMMU registers */
name|bus_addr_t
name|is_sb
index|[
literal|2
index|]
decl_stmt|;
comment|/* streaming buffer */
name|bus_addr_t
name|is_dtag
decl_stmt|;
comment|/* tag diagnostics access */
name|bus_addr_t
name|is_ddram
decl_stmt|;
comment|/* data ram diag. access */
name|bus_addr_t
name|is_dqueue
decl_stmt|;
comment|/* LRU queue diag. access */
name|bus_addr_t
name|is_dva
decl_stmt|;
comment|/* VA diag. register */
name|bus_addr_t
name|is_dtcmp
decl_stmt|;
comment|/* tag compare diag. access */
block|}
struct|;
end_struct

begin_comment
comment|/* interfaces for PCI/SBUS code */
end_comment

begin_function_decl
name|void
name|iommu_init
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iommu_reset
parameter_list|(
name|struct
name|iommu_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iommu_enter
parameter_list|(
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iommu_remove
parameter_list|(
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iommu_decode_fault
parameter_list|(
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iommu_dvmamap_create
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bus_dmamap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iommu_dvmamap_destroy
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iommu_dvmamap_load
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|,
name|bus_dmamap_callback_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iommu_dvmamap_unload
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iommu_dvmamap_sync
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|bus_dmamap_t
parameter_list|,
name|bus_dmasync_op_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iommu_dvmamem_alloc
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bus_dmamap_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iommu_dvmamem_free
parameter_list|(
name|bus_dma_tag_t
parameter_list|,
name|struct
name|iommu_state
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bus_dmamap_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IOMMUVAR_H_ */
end_comment

end_unit

