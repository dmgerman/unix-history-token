begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * gnttab.h  *   * Two sets of functionality:  * 1. Granting foreign access to our memory reservation.  * 2. Accessing others' memory reservations via grant references.  * (i.e., mechanisms for both sender and recipient of grant references)  *   * Copyright (c) 2004-2005, K A Fraser  * Copyright (c) 2005, Christopher Clark  *   * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License version 2  * as published by the Free Software Foundation; or, when distributed  * separately from the Linux kernel or incorporated into other  * software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASM_GNTTAB_H__
end_ifndef

begin_include
include|#
directive|include
file|<xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<xen/hypervisor.h>
end_include

begin_include
include|#
directive|include
file|<xen/features.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/grant_table.h>
end_include

begin_define
define|#
directive|define
name|GNTTAB_LIST_END
value|GRANT_REF_INVALID
end_define

begin_struct
struct|struct
name|gnttab_free_callback
block|{
name|struct
name|gnttab_free_callback
modifier|*
name|next
decl_stmt|;
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg
decl_stmt|;
name|uint16_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|gnttab_init
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate a grant table reference and return it in *result. Returns  * zero on success or errno on error.  */
end_comment

begin_function_decl
name|int
name|gnttab_grant_foreign_access
parameter_list|(
name|domid_t
name|domid
parameter_list|,
name|unsigned
name|long
name|frame
parameter_list|,
name|int
name|flags
parameter_list|,
name|grant_ref_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * End access through the given grant reference, iff the grant entry is no  * longer in use.  Return 1 if the grant entry was freed, 0 if it is still in  * use.  */
end_comment

begin_function_decl
name|int
name|gnttab_end_foreign_access_ref
parameter_list|(
name|grant_ref_t
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Eventually end access through the given grant reference, and once that  * access has been ended, free the given page too.  Access will be ended  * immediately iff the grant entry is not in use, otherwise it will happen  * some time later.  page may be 0, in which case no freeing will occur.  */
end_comment

begin_function_decl
name|void
name|gnttab_end_foreign_access
parameter_list|(
name|grant_ref_t
name|ref
parameter_list|,
name|void
modifier|*
name|page
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Eventually end access through the given array of grant references.  * Access will be ended immediately iff the grant entry is not in use,  * otherwise it will happen some time later  */
end_comment

begin_function_decl
name|void
name|gnttab_end_foreign_access_references
parameter_list|(
name|u_int
name|count
parameter_list|,
name|grant_ref_t
modifier|*
name|refs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnttab_grant_foreign_transfer
parameter_list|(
name|domid_t
name|domid
parameter_list|,
name|unsigned
name|long
name|pfn
parameter_list|,
name|grant_ref_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|gnttab_end_foreign_transfer_ref
parameter_list|(
name|grant_ref_t
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|gnttab_end_foreign_transfer
parameter_list|(
name|grant_ref_t
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnttab_query_foreign_access
parameter_list|(
name|grant_ref_t
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * operations on reserved batches of grant references  */
end_comment

begin_function_decl
name|int
name|gnttab_alloc_grant_references
parameter_list|(
name|uint16_t
name|count
parameter_list|,
name|grant_ref_t
modifier|*
name|pprivate_head
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gnttab_free_grant_reference
parameter_list|(
name|grant_ref_t
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gnttab_free_grant_references
parameter_list|(
name|grant_ref_t
name|head
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnttab_empty_grant_references
parameter_list|(
specifier|const
name|grant_ref_t
modifier|*
name|pprivate_head
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnttab_claim_grant_reference
parameter_list|(
name|grant_ref_t
modifier|*
name|pprivate_head
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gnttab_release_grant_reference
parameter_list|(
name|grant_ref_t
modifier|*
name|private_head
parameter_list|,
name|grant_ref_t
name|release
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gnttab_request_free_callback
parameter_list|(
name|struct
name|gnttab_free_callback
modifier|*
name|callback
parameter_list|,
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|uint16_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gnttab_cancel_free_callback
parameter_list|(
name|struct
name|gnttab_free_callback
modifier|*
name|callback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gnttab_grant_foreign_access_ref
parameter_list|(
name|grant_ref_t
name|ref
parameter_list|,
name|domid_t
name|domid
parameter_list|,
name|unsigned
name|long
name|frame
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gnttab_grant_foreign_transfer_ref
parameter_list|(
name|grant_ref_t
parameter_list|,
name|domid_t
name|domid
parameter_list|,
name|unsigned
name|long
name|pfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnttab_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnttab_resume
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<xen/features.h>
end_include

begin_endif
unit|static inline void gnttab_set_map_op(struct gnttab_map_grant_ref *map, vm_paddr_t addr, 		  uint32_t flags, grant_ref_t ref, domid_t domid) { 	if (flags& GNTMAP_contains_pte) 		map->host_addr = addr; 	else if (xen_feature(XENFEAT_auto_translated_physmap)) 		map->host_addr = vtophys(addr); 	else 		map->host_addr = addr;  	map->flags = flags; 	map->ref = ref; 	map->dom = domid; }  static inline void gnttab_set_unmap_op(struct gnttab_unmap_grant_ref *unmap, vm_paddr_t addr, 		    uint32_t flags, grant_handle_t handle) { 	if (flags& GNTMAP_contains_pte) 		unmap->host_addr = addr; 	else if (xen_feature(XENFEAT_auto_translated_physmap)) 		unmap->host_addr = vtophys(addr); 	else 		unmap->host_addr = addr;  	unmap->handle = handle; 	unmap->dev_bus_addr = 0; }  static inline void gnttab_set_replace_op(struct gnttab_unmap_and_replace *unmap, vm_paddr_t addr, 		      vm_paddr_t new_addr, grant_handle_t handle) { 	if (xen_feature(XENFEAT_auto_translated_physmap)) { 		unmap->host_addr = vtophys(addr); 		unmap->new_addr = vtophys(new_addr); 	} else { 		unmap->host_addr = addr; 		unmap->new_addr = new_addr; 	}  	unmap->handle = handle; }
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASM_GNTTAB_H__ */
end_comment

end_unit

