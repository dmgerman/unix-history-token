begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: iommuvar.h,v 1.7 2001/07/20 00:07:13 eeh Exp  *  * $FreeBSD$  */
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
comment|/* IOMMU control regiter value */
name|struct
name|rman
name|is_dvma_rman
decl_stmt|;
comment|/* DVMA map for this instance */
name|vm_offset_t
name|is_flushpa
decl_stmt|;
comment|/* used to flush the SBUS */
comment|/* Needs to be volatile or egcs optimizes away loads */
specifier|volatile
name|int64_t
name|is_flush
decl_stmt|;
comment|/* copies of our parents state, to allow us to be self contained */
name|bus_space_tag_t
name|is_bustag
decl_stmt|;
comment|/* our bus tag */
name|struct
name|iommureg
modifier|*
name|is_iommu
decl_stmt|;
comment|/* IOMMU registers */
name|struct
name|iommu_strbuf
modifier|*
name|is_sb
decl_stmt|;
comment|/* streaming buffer */
name|u_int64_t
modifier|*
name|is_dtag
decl_stmt|;
comment|/* tag diagnostics access */
name|u_int64_t
modifier|*
name|is_ddram
decl_stmt|;
comment|/* data ram diag. access */
name|u_int64_t
modifier|*
name|is_dqueue
decl_stmt|;
comment|/* LRU queue diag. access */
name|u_int64_t
modifier|*
name|is_dva
decl_stmt|;
comment|/* VA diag. register */
name|u_int64_t
modifier|*
name|is_dtcmp
decl_stmt|;
comment|/* tag compare diag. access */
block|}
struct|;
end_struct

begin_comment
comment|/* interfaces for PCI/SBUS code */
end_comment

begin_decl_stmt
name|void
name|iommu_init
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|iommu_state
operator|*
operator|,
name|int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iommu_reset
name|__P
argument_list|(
operator|(
expr|struct
name|iommu_state
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iommu_enter
name|__P
argument_list|(
operator|(
expr|struct
name|iommu_state
operator|*
operator|,
name|vm_offset_t
operator|,
name|vm_offset_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iommu_remove
name|__P
argument_list|(
operator|(
expr|struct
name|iommu_state
operator|*
operator|,
name|vm_offset_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iommu_dvmamem_alloc
name|__P
argument_list|(
operator|(
name|bus_dma_tag_t
operator|,
expr|struct
name|iommu_state
operator|*
operator|,
name|void
operator|*
operator|*
operator|,
name|int
operator|,
name|bus_dmamap_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iommu_dvmamem_free
name|__P
argument_list|(
operator|(
name|bus_dma_tag_t
operator|,
expr|struct
name|iommu_state
operator|*
operator|,
name|void
operator|*
operator|,
name|bus_dmamap_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iommu_dvmamap_load
name|__P
argument_list|(
operator|(
name|bus_dma_tag_t
operator|,
expr|struct
name|iommu_state
operator|*
operator|,
name|bus_dmamap_t
operator|,
name|void
operator|*
operator|,
name|bus_size_t
operator|,
name|bus_dmamap_callback_t
operator|*
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iommu_dvmamap_unload
name|__P
argument_list|(
operator|(
name|bus_dma_tag_t
operator|,
expr|struct
name|iommu_state
operator|*
operator|,
name|bus_dmamap_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iommu_dvmamap_sync
name|__P
argument_list|(
operator|(
name|bus_dma_tag_t
operator|,
expr|struct
name|iommu_state
operator|*
operator|,
name|bus_dmamap_t
operator|,
name|bus_dmasync_op_t
operator|)
argument_list|)
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

