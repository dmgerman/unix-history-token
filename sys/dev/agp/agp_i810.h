begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Konstantin Belousov under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AGP_AGP_I810_H
end_ifndef

begin_define
define|#
directive|define
name|AGP_AGP_I810_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/sglist.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_comment
comment|/* Special gtt memory types */
end_comment

begin_define
define|#
directive|define
name|AGP_DCACHE_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|AGP_PHYS_MEMORY
value|2
end_define

begin_comment
comment|/* New caching attributes for gen6/sandybridge */
end_comment

begin_define
define|#
directive|define
name|AGP_USER_CACHED_MEMORY_LLC_MLC
value|(AGP_USER_TYPES + 2)
end_define

begin_define
define|#
directive|define
name|AGP_USER_UNCACHED_MEMORY
value|(AGP_USER_TYPES + 4)
end_define

begin_comment
comment|/* flag for GFDT type */
end_comment

begin_define
define|#
directive|define
name|AGP_USER_CACHED_MEMORY_GFDT
value|(1<< 3)
end_define

begin_struct
struct|struct
name|intel_gtt
block|{
comment|/* Size of memory reserved for graphics by the BIOS */
name|unsigned
name|int
name|stolen_size
decl_stmt|;
comment|/* Total number of gtt entries. */
name|unsigned
name|int
name|gtt_total_entries
decl_stmt|;
comment|/* Part of the gtt that is mappable by the cpu, for those chips where 	 * this is not the full gtt. */
name|unsigned
name|int
name|gtt_mappable_entries
decl_stmt|;
comment|/* Whether i915 needs to use the dmar apis or not. */
name|unsigned
name|int
name|needs_dmar
range|:
literal|1
decl_stmt|;
comment|/* Whether we idle the gpu before mapping/unmapping */
name|unsigned
name|int
name|do_idle_maps
range|:
literal|1
decl_stmt|;
comment|/* Share the scratch page dma with ppgtts. */
name|vm_paddr_t
name|scratch_page_dma
decl_stmt|;
name|vm_page_t
name|scratch_page
decl_stmt|;
comment|/* for ppgtt PDE access */
name|uint32_t
modifier|*
name|gtt
decl_stmt|;
comment|/* needed for ioremap in drm/i915 */
name|bus_addr_t
name|gma_bus_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|intel_gtt
name|agp_intel_gtt_get
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agp_intel_gtt_chipset_flush
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agp_intel_gtt_unmap_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|sglist
modifier|*
name|sg_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agp_intel_gtt_clear_range
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|first_entry
parameter_list|,
name|u_int
name|num_entries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|agp_intel_gtt_map_memory
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|vm_page_t
modifier|*
name|pages
parameter_list|,
name|u_int
name|num_entries
parameter_list|,
name|struct
name|sglist
modifier|*
modifier|*
name|sg_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agp_intel_gtt_insert_sg_entries
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|sglist
modifier|*
name|sg_list
parameter_list|,
name|u_int
name|pg_start
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|agp_intel_gtt_insert_pages
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|first_entry
parameter_list|,
name|u_int
name|num_entries
parameter_list|,
name|vm_page_t
modifier|*
name|pages
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|intel_gtt
modifier|*
name|intel_gtt_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intel_gtt_chipset_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intel_gtt_unmap_memory
parameter_list|(
name|struct
name|sglist
modifier|*
name|sg_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intel_gtt_clear_range
parameter_list|(
name|u_int
name|first_entry
parameter_list|,
name|u_int
name|num_entries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intel_gtt_install_pte
parameter_list|(
name|u_int
name|index
parameter_list|,
name|vm_paddr_t
name|addr
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intel_gtt_map_memory
parameter_list|(
name|vm_page_t
modifier|*
name|pages
parameter_list|,
name|u_int
name|num_entries
parameter_list|,
name|struct
name|sglist
modifier|*
modifier|*
name|sg_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intel_gtt_insert_sg_entries
parameter_list|(
name|struct
name|sglist
modifier|*
name|sg_list
parameter_list|,
name|u_int
name|pg_start
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intel_gtt_insert_pages
parameter_list|(
name|u_int
name|first_entry
parameter_list|,
name|u_int
name|num_entries
parameter_list|,
name|vm_page_t
modifier|*
name|pages
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|intel_gtt_read_pte_paddr
parameter_list|(
name|u_int
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|intel_gtt_read_pte
parameter_list|(
name|u_int
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|intel_gtt_get_bridge_device
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intel_gtt_write
parameter_list|(
name|u_int
name|entry
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

