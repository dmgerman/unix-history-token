begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Konstantin Belousov<kib@FreeBSD.org>  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86_IOMMU_BUSDMA_DMAR_H
end_ifndef

begin_define
define|#
directive|define
name|__X86_IOMMU_BUSDMA_DMAR_H
end_define

begin_struct_decl
struct_decl|struct
name|dmar_map_entry
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|dmar_map_entries_tailq
argument_list|,
name|dmar_map_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|bus_dma_tag_dmar
block|{
name|struct
name|bus_dma_tag_common
name|common
decl_stmt|;
name|struct
name|dmar_ctx
modifier|*
name|ctx
decl_stmt|;
name|device_t
name|owner
decl_stmt|;
name|int
name|map_count
decl_stmt|;
name|bus_dma_segment_t
modifier|*
name|segments
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bus_dmamap_dmar
block|{
name|struct
name|bus_dma_tag_dmar
modifier|*
name|tag
decl_stmt|;
name|struct
name|memdesc
name|mem
decl_stmt|;
name|bus_dmamap_callback_t
modifier|*
name|callback
decl_stmt|;
name|void
modifier|*
name|callback_arg
decl_stmt|;
name|struct
name|dmar_map_entries_tailq
name|map_entries
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|bus_dmamap_dmar
argument_list|)
name|delay_link
expr_stmt|;
name|bool
name|locked
decl_stmt|;
name|bool
name|cansleep
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BUS_DMAMAP_DMAR_MALLOC
value|0x0001
end_define

begin_define
define|#
directive|define
name|BUS_DMAMAP_DMAR_KMEM_ALLOC
value|0x0002
end_define

begin_decl_stmt
specifier|extern
name|struct
name|bus_dma_impl
name|bus_dma_dmar_impl
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bus_dma_tag_t
name|dmar_get_dma_tag
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

