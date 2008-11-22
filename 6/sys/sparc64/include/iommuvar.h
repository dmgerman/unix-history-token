begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: iommuvar.h,v 1.9 2001/07/20 00:07:13 eeh Exp  *  * $FreeBSD$  */
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
comment|/*  * Per-IOMMU state. The parenthesized comments indicate the locking strategy:  *	i - protected by iommu_mtx.  *	r - read-only after initialization.  *	* - comment refers to pointer target / target hardware registers  *	    (for bus_addr_t).  * iommu_map_lruq is also locked by iommu_mtx. Elements of iommu_tsb may only  * be accessed from functions operating on the map owning the corresponding  * resource, so the locking the user is required to do to protect the map is  * sufficient. As soon as the TSBs are divorced, these will be moved into struct  * iommu_state, and each state struct will get its own lock.  * iommu_dvma_rman needs to be moved there too, but has its own internal lock.  */
end_comment

begin_struct
struct|struct
name|iommu_state
block|{
name|int
name|is_tsbsize
decl_stmt|;
comment|/* (r) 0 = 8K, ... */
name|uint64_t
name|is_dvmabase
decl_stmt|;
comment|/* (r) */
name|int64_t
name|is_cr
decl_stmt|;
comment|/* (r) Control reg value */
name|vm_paddr_t
name|is_flushpa
index|[
literal|2
index|]
decl_stmt|;
comment|/* (r) */
specifier|volatile
name|int64_t
modifier|*
name|is_flushva
index|[
literal|2
index|]
decl_stmt|;
comment|/* (r, *i) */
comment|/* 	 * (i) 	 * When a flush is completed, 64 bytes will be stored at the given 	 * location, the first double word being 1, to indicate completion. 	 * The lower 6 address bits are ignored, so the addresses need to be 	 * suitably aligned; over-allocate a large enough margin to be able 	 * to adjust it. 	 * Two such buffers are needed. 	 */
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
comment|/* (r) Our bus tag */
name|bus_space_handle_t
name|is_bushandle
decl_stmt|;
comment|/* (r) */
name|bus_addr_t
name|is_iommu
decl_stmt|;
comment|/* (r, *i) IOMMU registers */
name|bus_addr_t
name|is_sb
index|[
literal|2
index|]
decl_stmt|;
comment|/* (r, *i) Streaming buffer */
comment|/* Tag diagnostics access */
name|bus_addr_t
name|is_dtag
decl_stmt|;
comment|/* (r, *r) */
comment|/* Data RAM diagnostic access */
name|bus_addr_t
name|is_ddram
decl_stmt|;
comment|/* (r, *r) */
comment|/* LRU queue diag. access */
name|bus_addr_t
name|is_dqueue
decl_stmt|;
comment|/* (r, *r) */
comment|/* Virtual address diagnostics register */
name|bus_addr_t
name|is_dva
decl_stmt|;
comment|/* (r, *r) */
comment|/* Tag compare diagnostics access */
name|bus_addr_t
name|is_dtcmp
decl_stmt|;
comment|/* (r, *r) */
name|STAILQ_ENTRY
argument_list|(
argument|iommu_state
argument_list|)
name|is_link
expr_stmt|;
comment|/* (r) */
block|}
struct|;
end_struct

begin_comment
comment|/* interfaces for PCI/SBus code */
end_comment

begin_function_decl
name|void
name|iommu_init
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|iommu_state
modifier|*
name|is
parameter_list|,
name|int
name|tsbsize
parameter_list|,
name|uint32_t
name|iovabase
parameter_list|,
name|int
name|resvpg
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
name|is
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
name|is
parameter_list|,
name|vm_offset_t
name|phys
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|bus_dma_methods
name|iommu_dma_methods
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_IOMMUVAR_H_ */
end_comment

end_unit

