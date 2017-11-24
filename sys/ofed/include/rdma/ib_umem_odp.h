begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Mellanox Technologies. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_UMEM_ODP_H
end_ifndef

begin_define
define|#
directive|define
name|IB_UMEM_ODP_H
end_define

begin_include
include|#
directive|include
file|<linux/rbtree.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_umem.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_verbs.h>
end_include

begin_struct
struct|struct
name|umem_odp_node
block|{
name|u64
name|__subtree_last
decl_stmt|;
name|struct
name|rb_node
name|rb
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_umem_odp
block|{
comment|/* 	 * An array of the pages included in the on-demand paging umem. 	 * Indices of pages that are currently not mapped into the device will 	 * contain NULL. 	 */
name|struct
name|page
modifier|*
modifier|*
name|page_list
decl_stmt|;
comment|/* 	 * An array of the same size as page_list, with DMA addresses mapped 	 * for pages the pages in page_list. The lower two bits designate 	 * access permissions. See ODP_READ_ALLOWED_BIT and 	 * ODP_WRITE_ALLOWED_BIT. 	 */
name|dma_addr_t
modifier|*
name|dma_list
decl_stmt|;
comment|/* 	 * The umem_mutex protects the page_list and dma_list fields of an ODP 	 * umem, allowing only a single thread to map/unmap pages. The mutex 	 * also protects access to the mmu notifier counters. 	 */
name|struct
name|mutex
name|umem_mutex
decl_stmt|;
name|void
modifier|*
name|private
decl_stmt|;
comment|/* for the HW driver to use. */
comment|/* When false, use the notifier counter in the ucontext struct. */
name|bool
name|mn_counters_active
decl_stmt|;
name|int
name|notifiers_seq
decl_stmt|;
name|int
name|notifiers_count
decl_stmt|;
comment|/* A linked list of umems that don't have private mmu notifier 	 * counters yet. */
name|struct
name|list_head
name|no_private_counters
decl_stmt|;
name|struct
name|ib_umem
modifier|*
name|umem
decl_stmt|;
comment|/* Tree tracking */
name|struct
name|umem_odp_node
name|interval_tree
decl_stmt|;
name|struct
name|completion
name|notifier_completion
decl_stmt|;
name|int
name|dying
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_INFINIBAND_ON_DEMAND_PAGING
end_ifdef

begin_function_decl
name|int
name|ib_umem_odp_get
parameter_list|(
name|struct
name|ib_ucontext
modifier|*
name|context
parameter_list|,
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ib_umem_odp_release
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The lower 2 bits of the DMA address signal the R/W permissions for  * the entry. To upgrade the permissions, provide the appropriate  * bitmask to the map_dma_pages function.  *  * Be aware that upgrading a mapped address might result in change of  * the DMA address for the page.  */
end_comment

begin_define
define|#
directive|define
name|ODP_READ_ALLOWED_BIT
value|(1<<0ULL)
end_define

begin_define
define|#
directive|define
name|ODP_WRITE_ALLOWED_BIT
value|(1<<1ULL)
end_define

begin_define
define|#
directive|define
name|ODP_DMA_ADDR_MASK
value|(~(ODP_READ_ALLOWED_BIT | ODP_WRITE_ALLOWED_BIT))
end_define

begin_function_decl
name|int
name|ib_umem_odp_map_dma_pages
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|,
name|u64
name|start_offset
parameter_list|,
name|u64
name|bcnt
parameter_list|,
name|u64
name|access_mask
parameter_list|,
name|unsigned
name|long
name|current_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ib_umem_odp_unmap_dma_pages
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|,
name|u64
name|start_offset
parameter_list|,
name|u64
name|bound
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rbt_ib_umem_insert
parameter_list|(
name|struct
name|umem_odp_node
modifier|*
name|node
parameter_list|,
name|struct
name|rb_root
modifier|*
name|root
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rbt_ib_umem_remove
parameter_list|(
name|struct
name|umem_odp_node
modifier|*
name|node
parameter_list|,
name|struct
name|rb_root
modifier|*
name|root
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|umem_call_back
function_decl|)
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|item
parameter_list|,
name|u64
name|start
parameter_list|,
name|u64
name|end
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Call the callback on each ib_umem in the range. Returns the logical or of  * the return values of the functions called.  */
end_comment

begin_function_decl
name|int
name|rbt_ib_umem_for_each_in_range
parameter_list|(
name|struct
name|rb_root
modifier|*
name|root
parameter_list|,
name|u64
name|start
parameter_list|,
name|u64
name|end
parameter_list|,
name|umem_call_back
name|cb
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|umem_odp_node
modifier|*
name|rbt_ib_umem_iter_first
parameter_list|(
name|struct
name|rb_root
modifier|*
name|root
parameter_list|,
name|u64
name|start
parameter_list|,
name|u64
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|umem_odp_node
modifier|*
name|rbt_ib_umem_iter_next
parameter_list|(
name|struct
name|umem_odp_node
modifier|*
name|node
parameter_list|,
name|u64
name|start
parameter_list|,
name|u64
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|ib_umem_mmu_notifier_retry
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|item
parameter_list|,
name|unsigned
name|long
name|mmu_seq
parameter_list|)
block|{
comment|/* 	 * This code is strongly based on the KVM code from 	 * mmu_notifier_retry. Should be called with 	 * the relevant locks taken (item->odp_data->umem_mutex 	 * and the ucontext umem_mutex semaphore locked for read). 	 */
comment|/* Do not allow page faults while the new ib_umem hasn't seen a state 	 * with zero notifiers yet, and doesn't have its own valid set of 	 * private counters. */
if|if
condition|(
operator|!
name|item
operator|->
name|odp_data
operator|->
name|mn_counters_active
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|unlikely
argument_list|(
name|item
operator|->
name|odp_data
operator|->
name|notifiers_count
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|item
operator|->
name|odp_data
operator|->
name|notifiers_seq
operator|!=
name|mmu_seq
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_INFINIBAND_ON_DEMAND_PAGING */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|ib_umem_odp_get
parameter_list|(
name|struct
name|ib_ucontext
modifier|*
name|context
parameter_list|,
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|)
block|{
return|return
operator|-
name|EINVAL
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ib_umem_odp_release
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|)
block|{}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_INFINIBAND_ON_DEMAND_PAGING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_UMEM_ODP_H */
end_comment

end_unit

