begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHNDB_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHNDB_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|"bhndbvar.h"
end_include

begin_comment
comment|/*  * Private bhndb(4) driver definitions.  */
end_comment

begin_struct_decl
struct_decl|struct
name|bhndb_dw_alloc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhndb_region
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bhndb_resources
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|bhndb_find_resource_range
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|bhndb_find_regwin_resource
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|win
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhndb_resources
modifier|*
name|bhndb_alloc_resources
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|parent_dev
parameter_list|,
specifier|const
name|struct
name|bhndb_hwcfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhndb_free_resources
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_add_resource_region
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
name|bhnd_addr_t
name|addr
parameter_list|,
name|bhnd_size_t
name|size
parameter_list|,
name|bhndb_priority_t
name|priority
parameter_list|,
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|static_regwin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhndb_region
modifier|*
name|bhndb_find_resource_region
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
name|bhnd_addr_t
name|addr
parameter_list|,
name|bhnd_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhndb_dw_alloc
modifier|*
name|bhndb_dw_find_resource
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|dr
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhndb_dw_alloc
modifier|*
name|bhndb_dw_find_mapping
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
name|bhnd_addr_t
name|addr
parameter_list|,
name|bhnd_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_dw_retain
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
name|struct
name|bhndb_dw_alloc
modifier|*
name|dwa
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhndb_dw_release
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
name|struct
name|bhndb_dw_alloc
modifier|*
name|dwa
parameter_list|,
name|struct
name|resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhndb_dw_set_addr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
name|struct
name|bhndb_dw_alloc
modifier|*
name|dwa
parameter_list|,
name|bus_addr_t
name|addr
parameter_list|,
name|bus_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|bhndb_regwin_count
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|table
parameter_list|,
name|bhndb_regwin_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|bhndb_regwin_find_type
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|table
parameter_list|,
name|bhndb_regwin_type_t
name|type
parameter_list|,
name|bus_size_t
name|min_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|bhndb_regwin_find_core
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|table
parameter_list|,
name|bhnd_devclass_t
name|class
parameter_list|,
name|int
name|unit
parameter_list|,
name|bhnd_port_type
name|port_type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|bhndb_regwin_find_best
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|table
parameter_list|,
name|bhnd_devclass_t
name|class
parameter_list|,
name|int
name|unit
parameter_list|,
name|bhnd_port_type
name|port_type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|,
name|bus_size_t
name|min_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhndb_regwin_matches_device
parameter_list|(
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|regw
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhndb_hw_priority
modifier|*
name|bhndb_hw_priority_find_device
parameter_list|(
specifier|const
name|struct
name|bhndb_hw_priority
modifier|*
name|table
parameter_list|,
name|device_t
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Dynamic register window allocation reference.  */
end_comment

begin_struct
struct|struct
name|bhndb_dw_rentry
block|{
name|struct
name|resource
modifier|*
name|dw_res
decl_stmt|;
comment|/**< child resource */
name|LIST_ENTRY
argument_list|(
argument|bhndb_dw_rentry
argument_list|)
name|dw_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * A dynamic register window allocation record.   */
end_comment

begin_struct
struct|struct
name|bhndb_dw_alloc
block|{
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|win
decl_stmt|;
comment|/**< window definition */
name|struct
name|resource
modifier|*
name|parent_res
decl_stmt|;
comment|/**< enclosing resource */
name|u_int
name|rnid
decl_stmt|;
comment|/**< region identifier */
name|rman_res_t
name|target
decl_stmt|;
comment|/**< the current window address, or 0x0 if unknown */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|bhndb_dw_rentry
argument_list|)
name|refs
expr_stmt|;
comment|/**< references */
block|}
struct|;
end_struct

begin_comment
comment|/**  * A bus address region description.  */
end_comment

begin_struct
struct|struct
name|bhndb_region
block|{
name|bhnd_addr_t
name|addr
decl_stmt|;
comment|/**< start of mapped range */
name|bhnd_size_t
name|size
decl_stmt|;
comment|/**< size of mapped range */
name|bhndb_priority_t
name|priority
decl_stmt|;
comment|/**< direct resource allocation priority */
specifier|const
name|struct
name|bhndb_regwin
modifier|*
name|static_regwin
decl_stmt|;
comment|/**< fixed mapping regwin, if any */
name|STAILQ_ENTRY
argument_list|(
argument|bhndb_region
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * BHNDB resource allocation state.  */
end_comment

begin_struct
struct|struct
name|bhndb_resources
block|{
name|device_t
name|dev
decl_stmt|;
comment|/**< bridge device */
specifier|const
name|struct
name|bhndb_hwcfg
modifier|*
name|cfg
decl_stmt|;
comment|/**< hardware configuration */
name|device_t
name|parent_dev
decl_stmt|;
comment|/**< parent device */
name|struct
name|resource_spec
modifier|*
name|res_spec
decl_stmt|;
comment|/**< parent bus resource specs */
name|struct
name|resource
modifier|*
modifier|*
name|res
decl_stmt|;
comment|/**< parent bus resources */
name|struct
name|rman
name|ht_mem_rman
decl_stmt|;
comment|/**< host memory manager */
name|struct
name|rman
name|br_mem_rman
decl_stmt|;
comment|/**< bridged memory manager */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|bhndb_region
argument_list|)
name|bus_regions
expr_stmt|;
comment|/**< bus region descriptors */
name|struct
name|bhndb_dw_alloc
modifier|*
name|dw_alloc
decl_stmt|;
comment|/**< dynamic window allocation records */
name|size_t
name|dwa_count
decl_stmt|;
comment|/**< number of dynamic windows available. */
name|uint32_t
name|dwa_freelist
decl_stmt|;
comment|/**< dynamic window free list */
name|bhndb_priority_t
name|min_prio
decl_stmt|;
comment|/**< minimum resource priority required to 							     allocate a dynamic window */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Returns true if the all dynamic windows have been exhausted, false  * otherwise.  *   * @param br The resource state to check.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|bhndb_dw_exhausted
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|)
block|{
return|return
operator|(
name|br
operator|->
name|dwa_freelist
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Find the next free dynamic window region in @p br.  *   * @param br The resource state to search.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|bhndb_dw_alloc
modifier|*
name|bhndb_dw_next_free
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|)
block|{
name|struct
name|bhndb_dw_alloc
modifier|*
name|dw_free
decl_stmt|;
if|if
condition|(
name|bhndb_dw_exhausted
argument_list|(
name|br
argument_list|)
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|dw_free
operator|=
operator|&
name|br
operator|->
name|dw_alloc
index|[
name|__builtin_ctz
argument_list|(
name|br
operator|->
name|dwa_freelist
argument_list|)
index|]
expr_stmt|;
name|KASSERT
argument_list|(
name|LIST_EMPTY
argument_list|(
operator|&
name|dw_free
operator|->
name|refs
argument_list|)
argument_list|,
operator|(
literal|"free list out of sync with refs"
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|dw_free
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Returns true if a dynamic window allocation is marked as free.  *   * @param br The resource state owning @p dwa.  * @param dwa The dynamic window allocation record to be checked.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|bhndb_dw_is_free
parameter_list|(
name|struct
name|bhndb_resources
modifier|*
name|br
parameter_list|,
name|struct
name|bhndb_dw_alloc
modifier|*
name|dwa
parameter_list|)
block|{
name|bool
name|is_free
init|=
name|LIST_EMPTY
argument_list|(
operator|&
name|dwa
operator|->
name|refs
argument_list|)
decl_stmt|;
name|KASSERT
argument_list|(
name|is_free
operator|==
operator|(
operator|(
name|br
operator|->
name|dwa_freelist
operator|&
operator|(
literal|1
operator|<<
name|dwa
operator|->
name|rnid
operator|)
operator|)
operator|!=
literal|0
operator|)
argument_list|,
operator|(
literal|"refs out of sync with free list"
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|is_free
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|BHNDB_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->sc_mtx, device_get_nameunit((sc)->dev), \ 	    "bhndb resource allocator lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BHNDB_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BHNDB_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BHNDB_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->sc_mtx, what)
end_define

begin_define
define|#
directive|define
name|BHNDB_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->sc_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHNDB_PRIVATE_H_ */
end_comment

end_unit

