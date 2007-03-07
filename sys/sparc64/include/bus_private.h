begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998 Justin T. Gibbs.  * Copyright (c) 2002 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/i386/busdma_machdep.c,v 1.25 2002/01/05  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BUS_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BUS_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Helpers  */
end_comment

begin_function_decl
name|int
name|sparc64_bus_mem_map
parameter_list|(
name|bus_space_tag_t
parameter_list|,
name|bus_space_handle_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|,
name|vm_offset_t
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sparc64_bus_mem_unmap
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_space_handle_t
name|sparc64_fake_bustag
parameter_list|(
name|int
parameter_list|,
name|bus_addr_t
parameter_list|,
name|struct
name|bus_space_tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bus_dmamap_res
block|{
name|struct
name|resource
modifier|*
name|dr_res
decl_stmt|;
name|bus_size_t
name|dr_used
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|bus_dmamap_res
argument_list|)
name|dr_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Callers of the bus_dma interfaces must always protect their tags and maps  * appropriately against concurrent access. However, when a map is on a LRU  * queue, there is a second access path to it; for this case, the locking rules  * are given in the parenthesized comments below:  *	q - locked by the mutex protecting the queue.  *	p - private to the owner of the map, no access through the queue.  *	* - comment refers to pointer target.  * Only the owner of the map is allowed to insert the map into a queue. Removal  * and repositioning (i.e. temporal removal and reinsertion) is allowed to all  * if the queue lock is held.  */
end_comment

begin_struct
struct|struct
name|bus_dmamap
block|{
name|TAILQ_ENTRY
argument_list|(
argument|bus_dmamap
argument_list|)
name|dm_maplruq
expr_stmt|;
comment|/* (q) */
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|bus_dmamap_res
argument_list|)
name|dm_reslist
expr_stmt|;
comment|/* (q, *q) */
name|int
name|dm_onq
decl_stmt|;
comment|/* (q) */
name|int
name|dm_flags
decl_stmt|;
comment|/* (p) */
block|}
struct|;
end_struct

begin_comment
comment|/* Flag values. */
end_comment

begin_define
define|#
directive|define
name|DMF_LOADED
value|1
end_define

begin_comment
comment|/* Map is loaded */
end_comment

begin_define
define|#
directive|define
name|DMF_COHERENT
value|2
end_define

begin_comment
comment|/* Coherent mapping requested */
end_comment

begin_function_decl
name|int
name|sparc64_dma_alloc_map
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
modifier|*
name|mapp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sparc64_dma_free_map
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BUS_PRIVATE_H_ */
end_comment

end_unit

