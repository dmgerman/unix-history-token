begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * memory.h  *   * Memory reservation and information.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2005, Keir Fraser<keir@xensource.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_MEMORY_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_MEMORY_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_comment
comment|/*  * Increase or decrease the specified domain's memory reservation. Returns the  * number of extents successfully allocated or freed.  * arg == addr of struct xen_memory_reservation.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_increase_reservation
value|0
end_define

begin_define
define|#
directive|define
name|XENMEM_decrease_reservation
value|1
end_define

begin_define
define|#
directive|define
name|XENMEM_populate_physmap
value|6
end_define

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>=
literal|0x00030209
end_if

begin_comment
comment|/*  * Maximum # bits addressable by the user of the allocated region (e.g., I/O   * devices often have a 32-bit limitation even in 64-bit systems). If zero   * then the user has no addressing restriction. This field is not used by   * XENMEM_decrease_reservation.  */
end_comment

begin_define
define|#
directive|define
name|XENMEMF_address_bits
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|XENMEMF_get_address_bits
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffu)
end_define

begin_comment
comment|/* NUMA node to allocate from. */
end_comment

begin_define
define|#
directive|define
name|XENMEMF_node
parameter_list|(
name|x
parameter_list|)
value|(((x) + 1)<< 8)
end_define

begin_define
define|#
directive|define
name|XENMEMF_get_node
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 8) - 1)& 0xffu)
end_define

begin_comment
comment|/* Flag to populate physmap with populate-on-demand entries */
end_comment

begin_define
define|#
directive|define
name|XENMEMF_populate_on_demand
value|(1<<16)
end_define

begin_comment
comment|/* Flag to request allocation only from the node specified */
end_comment

begin_define
define|#
directive|define
name|XENMEMF_exact_node_request
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|XENMEMF_exact_node
parameter_list|(
name|n
parameter_list|)
value|(XENMEMF_node(n) | XENMEMF_exact_node_request)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|xen_memory_reservation
block|{
comment|/*      * XENMEM_increase_reservation:      *   OUT: MFN (*not* GMFN) bases of extents that were allocated      * XENMEM_decrease_reservation:      *   IN:  GMFN bases of extents to free      * XENMEM_populate_physmap:      *   IN:  GPFN bases of extents to populate with memory      *   OUT: GMFN bases of extents that were allocated      *   (NB. This command also updates the mach_to_phys translation table)      */
name|XEN_GUEST_HANDLE
argument_list|(
argument|xen_pfn_t
argument_list|)
name|extent_start
expr_stmt|;
comment|/* Number of extents, and size/alignment of each (2^extent_order pages). */
name|xen_ulong_t
name|nr_extents
decl_stmt|;
name|unsigned
name|int
name|extent_order
decl_stmt|;
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>=
literal|0x00030209
comment|/* XENMEMF flags. */
name|unsigned
name|int
name|mem_flags
decl_stmt|;
else|#
directive|else
name|unsigned
name|int
name|address_bits
decl_stmt|;
endif|#
directive|endif
comment|/*      * Domain whose reservation is being changed.      * Unprivileged domains can specify only DOMID_SELF.      */
name|domid_t
name|domid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_memory_reservation
name|xen_memory_reservation_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_memory_reservation_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * An atomic exchange of memory pages. If return code is zero then  * @out.extent_list provides GMFNs of the newly-allocated memory.  * Returns zero on complete success, otherwise a negative error code.  * On complete success then always @nr_exchanged == @in.nr_extents.  * On partial success @nr_exchanged indicates how much work was done.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_exchange
value|11
end_define

begin_struct
struct|struct
name|xen_memory_exchange
block|{
comment|/*      * [IN] Details of memory extents to be exchanged (GMFN bases).      * Note that @in.address_bits is ignored and unused.      */
name|struct
name|xen_memory_reservation
name|in
decl_stmt|;
comment|/*      * [IN/OUT] Details of new memory extents.      * We require that:      *  1. @in.domid == @out.domid      *  2. @in.nr_extents<< @in.extent_order ==       *     @out.nr_extents<< @out.extent_order      *  3. @in.extent_start and @out.extent_start lists must not overlap      *  4. @out.extent_start lists GPFN bases to be populated      *  5. @out.extent_start is overwritten with allocated GMFN bases      */
name|struct
name|xen_memory_reservation
name|out
decl_stmt|;
comment|/*      * [OUT] Number of input extents that were successfully exchanged:      *  1. The first @nr_exchanged input extents were successfully      *     deallocated.      *  2. The corresponding first entries in the output extent list correctly      *     indicate the GMFNs that were successfully exchanged.      *  3. All other input and output extents are untouched.      *  4. If not all input exents are exchanged then the return code of this      *     command will be non-zero.      *  5. THIS FIELD MUST BE INITIALISED TO ZERO BY THE CALLER!      */
name|xen_ulong_t
name|nr_exchanged
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_memory_exchange
name|xen_memory_exchange_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_memory_exchange_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Returns the maximum machine frame number of mapped RAM in this system.  * This command always succeeds (it never returns an error code).  * arg == NULL.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_maximum_ram_page
value|2
end_define

begin_comment
comment|/*  * Returns the current or maximum memory reservation, in pages, of the  * specified domain (may be DOMID_SELF). Returns -ve errcode on failure.  * arg == addr of domid_t.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_current_reservation
value|3
end_define

begin_define
define|#
directive|define
name|XENMEM_maximum_reservation
value|4
end_define

begin_comment
comment|/*  * Returns the maximum GPFN in use by the guest, or -ve errcode on failure.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_maximum_gpfn
value|14
end_define

begin_comment
comment|/*  * Returns a list of MFN bases of 2MB extents comprising the machine_to_phys  * mapping table. Architectures which do not have a m2p table do not implement  * this command.  * arg == addr of xen_machphys_mfn_list_t.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_machphys_mfn_list
value|5
end_define

begin_struct
struct|struct
name|xen_machphys_mfn_list
block|{
comment|/*      * Size of the 'extent_start' array. Fewer entries will be filled if the      * machphys table is smaller than max_extents * 2MB.      */
name|unsigned
name|int
name|max_extents
decl_stmt|;
comment|/*      * Pointer to buffer to fill with list of extent starts. If there are      * any large discontiguities in the machine address space, 2MB gaps in      * the machphys table will be represented by an MFN base of zero.      */
name|XEN_GUEST_HANDLE
argument_list|(
argument|xen_pfn_t
argument_list|)
name|extent_start
expr_stmt|;
comment|/*      * Number of extents written to the above array. This will be smaller      * than 'max_extents' if the machphys table is smaller than max_e * 2MB.      */
name|unsigned
name|int
name|nr_extents
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_machphys_mfn_list
name|xen_machphys_mfn_list_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_machphys_mfn_list_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Returns the location in virtual address space of the machine_to_phys  * mapping table. Architectures which do not have a m2p table, or which do not  * map it by default into guest address space, do not implement this command.  * arg == addr of xen_machphys_mapping_t.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_machphys_mapping
value|12
end_define

begin_struct
struct|struct
name|xen_machphys_mapping
block|{
name|xen_ulong_t
name|v_start
decl_stmt|,
name|v_end
decl_stmt|;
comment|/* Start and end virtual addresses.   */
name|xen_ulong_t
name|max_mfn
decl_stmt|;
comment|/* Maximum MFN that can be looked up. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_machphys_mapping
name|xen_machphys_mapping_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_machphys_mapping_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XENMAPSPACE_shared_info
value|0
end_define

begin_comment
comment|/* shared info page */
end_comment

begin_define
define|#
directive|define
name|XENMAPSPACE_grant_table
value|1
end_define

begin_comment
comment|/* grant table page */
end_comment

begin_define
define|#
directive|define
name|XENMAPSPACE_gmfn
value|2
end_define

begin_comment
comment|/* GMFN */
end_comment

begin_define
define|#
directive|define
name|XENMAPSPACE_gmfn_range
value|3
end_define

begin_comment
comment|/* GMFN range, XENMEM_add_to_physmap only. */
end_comment

begin_define
define|#
directive|define
name|XENMAPSPACE_gmfn_foreign
value|4
end_define

begin_comment
comment|/* GMFN from another dom,                                     * XENMEM_add_to_physmap_range only.                                     */
end_comment

begin_comment
comment|/*  * Sets the GPFN at which a particular page appears in the specified guest's  * pseudophysical address space.  * arg == addr of xen_add_to_physmap_t.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_add_to_physmap
value|7
end_define

begin_struct
struct|struct
name|xen_add_to_physmap
block|{
comment|/* Which domain to change the mapping for. */
name|domid_t
name|domid
decl_stmt|;
comment|/* Number of pages to go through for gmfn_range */
name|uint16_t
name|size
decl_stmt|;
comment|/* Source mapping space. */
define|#
directive|define
name|XENMAPSPACE_shared_info
value|0
comment|/* shared info page */
define|#
directive|define
name|XENMAPSPACE_grant_table
value|1
comment|/* grant table page */
define|#
directive|define
name|XENMAPSPACE_gmfn
value|2
comment|/* GMFN */
define|#
directive|define
name|XENMAPSPACE_gmfn_range
value|3
comment|/* GMFN range */
name|unsigned
name|int
name|space
decl_stmt|;
define|#
directive|define
name|XENMAPIDX_grant_table_status
value|0x80000000
comment|/* Index into source mapping space. */
name|xen_ulong_t
name|idx
decl_stmt|;
comment|/* GPFN where the source mapping page should appear. */
name|xen_pfn_t
name|gpfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_add_to_physmap
name|xen_add_to_physmap_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_add_to_physmap_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Unmaps the page appearing at a particular GPFN from the specified guest's  * pseudophysical address space.  * arg == addr of xen_remove_from_physmap_t.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_remove_from_physmap
value|15
end_define

begin_struct
struct|struct
name|xen_remove_from_physmap
block|{
comment|/* Which domain to change the mapping for. */
name|domid_t
name|domid
decl_stmt|;
comment|/* GPFN of the current mapping of the page. */
name|xen_pfn_t
name|gpfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_remove_from_physmap
name|xen_remove_from_physmap_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_remove_from_physmap_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*** REMOVED ***/
end_comment

begin_comment
comment|/*#define XENMEM_translate_gpfn_list  8*/
end_comment

begin_define
define|#
directive|define
name|XENMEM_add_to_physmap_range
value|23
end_define

begin_struct
struct|struct
name|xen_add_to_physmap_range
block|{
comment|/* IN */
comment|/* Which domain to change the mapping for. */
name|domid_t
name|domid
decl_stmt|;
name|uint16_t
name|space
decl_stmt|;
comment|/* => enum phys_map_space */
comment|/* Number of pages to go through */
name|uint16_t
name|size
decl_stmt|;
name|domid_t
name|foreign_domid
decl_stmt|;
comment|/* IFF gmfn_foreign */
comment|/* Indexes into space being mapped. */
name|XEN_GUEST_HANDLE
argument_list|(
argument|xen_ulong_t
argument_list|)
name|idxs
expr_stmt|;
comment|/* GPFN in domid where the source mapping page should appear. */
name|XEN_GUEST_HANDLE
argument_list|(
argument|xen_pfn_t
argument_list|)
name|gpfns
expr_stmt|;
comment|/* OUT */
comment|/* Per index error code. */
name|XEN_GUEST_HANDLE
argument_list|(
argument|int
argument_list|)
name|errs
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_add_to_physmap_range
name|xen_add_to_physmap_range_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_add_to_physmap_range_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Returns the pseudo-physical memory map as it was when the domain  * was started (specified by XENMEM_set_memory_map).  * arg == addr of xen_memory_map_t.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_memory_map
value|9
end_define

begin_struct
struct|struct
name|xen_memory_map
block|{
comment|/*      * On call the number of entries which can be stored in buffer. On      * return the number of entries which have been stored in      * buffer.      */
name|unsigned
name|int
name|nr_entries
decl_stmt|;
comment|/*      * Entries in the buffer are in the same format as returned by the      * BIOS INT 0x15 EAX=0xE820 call.      */
name|XEN_GUEST_HANDLE
argument_list|(
argument|void
argument_list|)
name|buffer
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_memory_map
name|xen_memory_map_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_memory_map_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Returns the real physical memory map. Passes the same structure as  * XENMEM_memory_map.  * arg == addr of xen_memory_map_t.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_machine_memory_map
value|10
end_define

begin_comment
comment|/*  * Set the pseudo-physical memory map of a domain, as returned by  * XENMEM_memory_map.  * arg == addr of xen_foreign_memory_map_t.  */
end_comment

begin_define
define|#
directive|define
name|XENMEM_set_memory_map
value|13
end_define

begin_struct
struct|struct
name|xen_foreign_memory_map
block|{
name|domid_t
name|domid
decl_stmt|;
name|struct
name|xen_memory_map
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_foreign_memory_map
name|xen_foreign_memory_map_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_foreign_memory_map_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XENMEM_set_pod_target
value|16
end_define

begin_define
define|#
directive|define
name|XENMEM_get_pod_target
value|17
end_define

begin_struct
struct|struct
name|xen_pod_target
block|{
comment|/* IN */
name|uint64_t
name|target_pages
decl_stmt|;
comment|/* OUT */
name|uint64_t
name|tot_pages
decl_stmt|;
name|uint64_t
name|pod_cache_pages
decl_stmt|;
name|uint64_t
name|pod_entries
decl_stmt|;
comment|/* IN */
name|domid_t
name|domid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_pod_target
name|xen_pod_target_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__XEN__
argument_list|)
operator|||
name|defined
argument_list|(
name|__XEN_TOOLS__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|uint64_aligned_t
end_ifndef

begin_define
define|#
directive|define
name|uint64_aligned_t
value|uint64_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Get the number of MFNs saved through memory sharing.  * The call never fails.   */
end_comment

begin_define
define|#
directive|define
name|XENMEM_get_sharing_freed_pages
value|18
end_define

begin_define
define|#
directive|define
name|XENMEM_get_sharing_shared_pages
value|19
end_define

begin_define
define|#
directive|define
name|XENMEM_paging_op
value|20
end_define

begin_define
define|#
directive|define
name|XENMEM_paging_op_nominate
value|0
end_define

begin_define
define|#
directive|define
name|XENMEM_paging_op_evict
value|1
end_define

begin_define
define|#
directive|define
name|XENMEM_paging_op_prep
value|2
end_define

begin_define
define|#
directive|define
name|XENMEM_access_op
value|21
end_define

begin_define
define|#
directive|define
name|XENMEM_access_op_resume
value|0
end_define

begin_struct
struct|struct
name|xen_mem_event_op
block|{
name|uint8_t
name|op
decl_stmt|;
comment|/* XENMEM_*_op_* */
name|domid_t
name|domain
decl_stmt|;
comment|/* PAGING_PREP IN: buffer to immediately fill page in */
name|uint64_aligned_t
name|buffer
decl_stmt|;
comment|/* Other OPs */
name|uint64_aligned_t
name|gfn
decl_stmt|;
comment|/* IN:  gfn of page being operated on */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_mem_event_op
name|xen_mem_event_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_mem_event_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XENMEM_sharing_op
value|22
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_nominate_gfn
value|0
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_nominate_gref
value|1
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_share
value|2
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_resume
value|3
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_debug_gfn
value|4
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_debug_mfn
value|5
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_debug_gref
value|6
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_add_physmap
value|7
end_define

begin_define
define|#
directive|define
name|XENMEM_sharing_op_audit
value|8
end_define

begin_define
define|#
directive|define
name|XENMEM_SHARING_OP_S_HANDLE_INVALID
value|(-10)
end_define

begin_define
define|#
directive|define
name|XENMEM_SHARING_OP_C_HANDLE_INVALID
value|(-9)
end_define

begin_comment
comment|/* The following allows sharing of grant refs. This is useful  * for sharing utilities sitting as "filters" in IO backends  * (e.g. memshr + blktap(2)). The IO backend is only exposed   * to grant references, and this allows sharing of the grefs */
end_comment

begin_define
define|#
directive|define
name|XENMEM_SHARING_OP_FIELD_IS_GREF_FLAG
value|(1ULL<< 62)
end_define

begin_define
define|#
directive|define
name|XENMEM_SHARING_OP_FIELD_MAKE_GREF
parameter_list|(
name|field
parameter_list|,
name|val
parameter_list|)
define|\
value|(field) = (XENMEM_SHARING_OP_FIELD_IS_GREF_FLAG | val)
end_define

begin_define
define|#
directive|define
name|XENMEM_SHARING_OP_FIELD_IS_GREF
parameter_list|(
name|field
parameter_list|)
define|\
value|((field)& XENMEM_SHARING_OP_FIELD_IS_GREF_FLAG)
end_define

begin_define
define|#
directive|define
name|XENMEM_SHARING_OP_FIELD_GET_GREF
parameter_list|(
name|field
parameter_list|)
define|\
value|((field)& (~XENMEM_SHARING_OP_FIELD_IS_GREF_FLAG))
end_define

begin_struct
struct|struct
name|xen_mem_sharing_op
block|{
name|uint8_t
name|op
decl_stmt|;
comment|/* XENMEM_sharing_op_* */
name|domid_t
name|domain
decl_stmt|;
union|union
block|{
struct|struct
name|mem_sharing_op_nominate
block|{
comment|/* OP_NOMINATE_xxx           */
union|union
block|{
name|uint64_aligned_t
name|gfn
decl_stmt|;
comment|/* IN: gfn to nominate       */
name|uint32_t
name|grant_ref
decl_stmt|;
comment|/* IN: grant ref to nominate */
block|}
name|u
union|;
name|uint64_aligned_t
name|handle
decl_stmt|;
comment|/* OUT: the handle           */
block|}
name|nominate
struct|;
struct|struct
name|mem_sharing_op_share
block|{
comment|/* OP_SHARE/ADD_PHYSMAP */
name|uint64_aligned_t
name|source_gfn
decl_stmt|;
comment|/* IN: the gfn of the source page */
name|uint64_aligned_t
name|source_handle
decl_stmt|;
comment|/* IN: handle to the source page */
name|uint64_aligned_t
name|client_gfn
decl_stmt|;
comment|/* IN: the client gfn */
name|uint64_aligned_t
name|client_handle
decl_stmt|;
comment|/* IN: handle to the client page */
name|domid_t
name|client_domain
decl_stmt|;
comment|/* IN: the client domain id */
block|}
name|share
struct|;
struct|struct
name|mem_sharing_op_debug
block|{
comment|/* OP_DEBUG_xxx */
union|union
block|{
name|uint64_aligned_t
name|gfn
decl_stmt|;
comment|/* IN: gfn to debug          */
name|uint64_aligned_t
name|mfn
decl_stmt|;
comment|/* IN: mfn to debug          */
name|uint32_t
name|gref
decl_stmt|;
comment|/* IN: gref to debug         */
block|}
name|u
union|;
block|}
name|debug
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_mem_sharing_op
name|xen_mem_sharing_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_mem_sharing_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__XEN__) || defined(__XEN_TOOLS__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_MEMORY_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

