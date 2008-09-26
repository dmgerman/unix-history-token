begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * grant_table.h  *   * Interface for granting foreign access to page frames, and receiving  * page-ownership transfers.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2004, K A Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_GRANT_TABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_GRANT_TABLE_H__
end_define

begin_comment
comment|/***********************************  * GRANT TABLE REPRESENTATION  */
end_comment

begin_comment
comment|/* Some rough guidelines on accessing and updating grant-table entries  * in a concurrency-safe manner. For more information, Linux contains a  * reference implementation for guest OSes (arch/xen/kernel/grant_table.c).  *   * NB. WMB is a no-op on current-generation x86 processors. However, a  *     compiler barrier will still be required.  *   * Introducing a valid entry into the grant table:  *  1. Write ent->domid.  *  2. Write ent->frame:  *      GTF_permit_access:   Frame to which access is permitted.  *      GTF_accept_transfer: Pseudo-phys frame slot being filled by new  *                           frame, or zero if none.  *  3. Write memory barrier (WMB).  *  4. Write ent->flags, inc. valid type.  *   * Invalidating an unused GTF_permit_access entry:  *  1. flags = ent->flags.  *  2. Observe that !(flags& (GTF_reading|GTF_writing)).  *  3. Check result of SMP-safe CMPXCHG(&ent->flags, flags, 0).  *  NB. No need for WMB as reuse of entry is control-dependent on success of  *      step 3, and all architectures guarantee ordering of ctrl-dep writes.  *  * Invalidating an in-use GTF_permit_access entry:  *  This cannot be done directly. Request assistance from the domain controller  *  which can set a timeout on the use of a grant entry and take necessary  *  action. (NB. This is not yet implemented!).  *   * Invalidating an unused GTF_accept_transfer entry:  *  1. flags = ent->flags.  *  2. Observe that !(flags& GTF_transfer_committed). [*]  *  3. Check result of SMP-safe CMPXCHG(&ent->flags, flags, 0).  *  NB. No need for WMB as reuse of entry is control-dependent on success of  *      step 3, and all architectures guarantee ordering of ctrl-dep writes.  *  [*] If GTF_transfer_committed is set then the grant entry is 'committed'.  *      The guest must /not/ modify the grant entry until the address of the  *      transferred frame is written. It is safe for the guest to spin waiting  *      for this to occur (detect by observing GTF_transfer_completed in  *      ent->flags).  *  * Invalidating a committed GTF_accept_transfer entry:  *  1. Wait for (ent->flags& GTF_transfer_completed).  *  * Changing a GTF_permit_access from writable to read-only:  *  Use SMP-safe CMPXCHG to set GTF_readonly, while checking !GTF_writing.  *   * Changing a GTF_permit_access from read-only to writable:  *  Use SMP-safe bit-setting instruction.  */
end_comment

begin_comment
comment|/*  * A grant table comprises a packed array of grant entries in one or more  * page frames shared between Xen and a guest.  * [XEN]: This field is written by Xen and read by the sharing guest.  * [GST]: This field is written by the guest and read by Xen.  */
end_comment

begin_struct
struct|struct
name|grant_entry
block|{
comment|/* GTF_xxx: various type and flag information.  [XEN,GST] */
name|uint16_t
name|flags
decl_stmt|;
comment|/* The domain being granted foreign privileges. [GST] */
name|domid_t
name|domid
decl_stmt|;
comment|/*      * GTF_permit_access: Frame that @domid is allowed to map and access. [GST]      * GTF_accept_transfer: Frame whose ownership transferred by @domid. [XEN]      */
name|uint32_t
name|frame
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|grant_entry
name|grant_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Type of grant entry.  *  GTF_invalid: This grant entry grants no privileges.  *  GTF_permit_access: Allow @domid to map/access @frame.  *  GTF_accept_transfer: Allow @domid to transfer ownership of one page frame  *                       to this guest. Xen writes the page number to @frame.  */
end_comment

begin_define
define|#
directive|define
name|GTF_invalid
value|(0U<<0)
end_define

begin_define
define|#
directive|define
name|GTF_permit_access
value|(1U<<0)
end_define

begin_define
define|#
directive|define
name|GTF_accept_transfer
value|(2U<<0)
end_define

begin_define
define|#
directive|define
name|GTF_type_mask
value|(3U<<0)
end_define

begin_comment
comment|/*  * Subflags for GTF_permit_access.  *  GTF_readonly: Restrict @domid to read-only mappings and accesses. [GST]  *  GTF_reading: Grant entry is currently mapped for reading by @domid. [XEN]  *  GTF_writing: Grant entry is currently mapped for writing by @domid. [XEN]  *  GTF_PAT, GTF_PWT, GTF_PCD: (x86) cache attribute flags for the grant [GST]  */
end_comment

begin_define
define|#
directive|define
name|_GTF_readonly
value|(2)
end_define

begin_define
define|#
directive|define
name|GTF_readonly
value|(1U<<_GTF_readonly)
end_define

begin_define
define|#
directive|define
name|_GTF_reading
value|(3)
end_define

begin_define
define|#
directive|define
name|GTF_reading
value|(1U<<_GTF_reading)
end_define

begin_define
define|#
directive|define
name|_GTF_writing
value|(4)
end_define

begin_define
define|#
directive|define
name|GTF_writing
value|(1U<<_GTF_writing)
end_define

begin_define
define|#
directive|define
name|_GTF_PWT
value|(5)
end_define

begin_define
define|#
directive|define
name|GTF_PWT
value|(1U<<_GTF_PWT)
end_define

begin_define
define|#
directive|define
name|_GTF_PCD
value|(6)
end_define

begin_define
define|#
directive|define
name|GTF_PCD
value|(1U<<_GTF_PCD)
end_define

begin_define
define|#
directive|define
name|_GTF_PAT
value|(7)
end_define

begin_define
define|#
directive|define
name|GTF_PAT
value|(1U<<_GTF_PAT)
end_define

begin_comment
comment|/*  * Subflags for GTF_accept_transfer:  *  GTF_transfer_committed: Xen sets this flag to indicate that it is committed  *      to transferring ownership of a page frame. When a guest sees this flag  *      it must /not/ modify the grant entry until GTF_transfer_completed is  *      set by Xen.  *  GTF_transfer_completed: It is safe for the guest to spin-wait on this flag  *      after reading GTF_transfer_committed. Xen will always write the frame  *      address, followed by ORing this flag, in a timely manner.  */
end_comment

begin_define
define|#
directive|define
name|_GTF_transfer_committed
value|(2)
end_define

begin_define
define|#
directive|define
name|GTF_transfer_committed
value|(1U<<_GTF_transfer_committed)
end_define

begin_define
define|#
directive|define
name|_GTF_transfer_completed
value|(3)
end_define

begin_define
define|#
directive|define
name|GTF_transfer_completed
value|(1U<<_GTF_transfer_completed)
end_define

begin_comment
comment|/***********************************  * GRANT TABLE QUERIES AND USES  */
end_comment

begin_comment
comment|/*  * Reference to a grant entry in a specified domain's grant table.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|grant_ref_t
typedef|;
end_typedef

begin_comment
comment|/*  * Handle to track a mapping created via a grant reference.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|grant_handle_t
typedef|;
end_typedef

begin_comment
comment|/*  * GNTTABOP_map_grant_ref: Map the grant entry (<dom>,<ref>) for access  * by devices and/or host CPUs. If successful,<handle> is a tracking number  * that must be presented later to destroy the mapping(s). On error,<handle>  * is a negative status code.  * NOTES:  *  1. If GNTMAP_device_map is specified then<dev_bus_addr> is the address  *     via which I/O devices may access the granted frame.  *  2. If GNTMAP_host_map is specified then a mapping will be added at  *     either a host virtual address in the current address space, or at  *     a PTE at the specified machine address.  The type of mapping to  *     perform is selected through the GNTMAP_contains_pte flag, and the   *     address is specified in<host_addr>.  *  3. Mappings should only be destroyed via GNTTABOP_unmap_grant_ref. If a  *     host mapping is destroyed by other means then it is *NOT* guaranteed  *     to be accounted to the correct grant reference!  */
end_comment

begin_define
define|#
directive|define
name|GNTTABOP_map_grant_ref
value|0
end_define

begin_struct
struct|struct
name|gnttab_map_grant_ref
block|{
comment|/* IN parameters. */
name|uint64_t
name|host_addr
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* GNTMAP_* */
name|grant_ref_t
name|ref
decl_stmt|;
name|domid_t
name|dom
decl_stmt|;
comment|/* OUT parameters. */
name|int16_t
name|status
decl_stmt|;
comment|/* GNTST_* */
name|grant_handle_t
name|handle
decl_stmt|;
name|uint64_t
name|dev_bus_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gnttab_map_grant_ref
name|gnttab_map_grant_ref_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|gnttab_map_grant_ref_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * GNTTABOP_unmap_grant_ref: Destroy one or more grant-reference mappings  * tracked by<handle>. If<host_addr> or<dev_bus_addr> is zero, that  * field is ignored. If non-zero, they must refer to a device/host mapping  * that is tracked by<handle>  * NOTES:  *  1. The call may fail in an undefined manner if either mapping is not  *     tracked by<handle>.  *  3. After executing a batch of unmaps, it is guaranteed that no stale  *     mappings will remain in the device or host TLBs.  */
end_comment

begin_define
define|#
directive|define
name|GNTTABOP_unmap_grant_ref
value|1
end_define

begin_struct
struct|struct
name|gnttab_unmap_grant_ref
block|{
comment|/* IN parameters. */
name|uint64_t
name|host_addr
decl_stmt|;
name|uint64_t
name|dev_bus_addr
decl_stmt|;
name|grant_handle_t
name|handle
decl_stmt|;
comment|/* OUT parameters. */
name|int16_t
name|status
decl_stmt|;
comment|/* GNTST_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gnttab_unmap_grant_ref
name|gnttab_unmap_grant_ref_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|gnttab_unmap_grant_ref_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * GNTTABOP_setup_table: Set up a grant table for<dom> comprising at least  *<nr_frames> pages. The frame addresses are written to the<frame_list>.  * Only<nr_frames> addresses are written, even if the table is larger.  * NOTES:  *  1.<dom> may be specified as DOMID_SELF.  *  2. Only a sufficiently-privileged domain may specify<dom> != DOMID_SELF.  *  3. Xen may not support more than a single grant-table page per domain.  */
end_comment

begin_define
define|#
directive|define
name|GNTTABOP_setup_table
value|2
end_define

begin_struct
struct|struct
name|gnttab_setup_table
block|{
comment|/* IN parameters. */
name|domid_t
name|dom
decl_stmt|;
name|uint32_t
name|nr_frames
decl_stmt|;
comment|/* OUT parameters. */
name|int16_t
name|status
decl_stmt|;
comment|/* GNTST_* */
name|XEN_GUEST_HANDLE
argument_list|(
argument|ulong
argument_list|)
name|frame_list
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gnttab_setup_table
name|gnttab_setup_table_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|gnttab_setup_table_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * GNTTABOP_dump_table: Dump the contents of the grant table to the  * xen console. Debugging use only.  */
end_comment

begin_define
define|#
directive|define
name|GNTTABOP_dump_table
value|3
end_define

begin_struct
struct|struct
name|gnttab_dump_table
block|{
comment|/* IN parameters. */
name|domid_t
name|dom
decl_stmt|;
comment|/* OUT parameters. */
name|int16_t
name|status
decl_stmt|;
comment|/* GNTST_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gnttab_dump_table
name|gnttab_dump_table_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|gnttab_dump_table_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * GNTTABOP_transfer_grant_ref: Transfer<frame> to a foreign domain. The  * foreign domain has previously registered its interest in the transfer via  *<domid, ref>.  *   * Note that, even if the transfer fails, the specified page no longer belongs  * to the calling domain *unless* the error is GNTST_bad_page.  */
end_comment

begin_define
define|#
directive|define
name|GNTTABOP_transfer
value|4
end_define

begin_struct
struct|struct
name|gnttab_transfer
block|{
comment|/* IN parameters. */
name|xen_pfn_t
name|mfn
decl_stmt|;
name|domid_t
name|domid
decl_stmt|;
name|grant_ref_t
name|ref
decl_stmt|;
comment|/* OUT parameters. */
name|int16_t
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gnttab_transfer
name|gnttab_transfer_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|gnttab_transfer_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * GNTTABOP_copy: Hypervisor based copy  * source and destinations can be eithers MFNs or, for foreign domains,  * grant references. the foreign domain has to grant read/write access  * in its grant table.  *  * The flags specify what type source and destinations are (either MFN  * or grant reference).  *  * Note that this can also be used to copy data between two domains  * via a third party if the source and destination domains had previously  * grant appropriate access to their pages to the third party.  *  * source_offset specifies an offset in the source frame, dest_offset  * the offset in the target frame and  len specifies the number of  * bytes to be copied.  */
end_comment

begin_define
define|#
directive|define
name|_GNTCOPY_source_gref
value|(0)
end_define

begin_define
define|#
directive|define
name|GNTCOPY_source_gref
value|(1<<_GNTCOPY_source_gref)
end_define

begin_define
define|#
directive|define
name|_GNTCOPY_dest_gref
value|(1)
end_define

begin_define
define|#
directive|define
name|GNTCOPY_dest_gref
value|(1<<_GNTCOPY_dest_gref)
end_define

begin_define
define|#
directive|define
name|GNTTABOP_copy
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
name|gnttab_copy
block|{
comment|/* IN parameters. */
struct|struct
block|{
union|union
block|{
name|grant_ref_t
name|ref
decl_stmt|;
name|xen_pfn_t
name|gmfn
decl_stmt|;
block|}
name|u
union|;
name|domid_t
name|domid
decl_stmt|;
name|uint16_t
name|offset
decl_stmt|;
block|}
name|source
struct|,
name|dest
struct|;
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
comment|/* GNTCOPY_* */
comment|/* OUT parameters. */
name|int16_t
name|status
decl_stmt|;
block|}
name|gnttab_copy_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|gnttab_copy_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * GNTTABOP_query_size: Query the current and maximum sizes of the shared  * grant table.  * NOTES:  *  1.<dom> may be specified as DOMID_SELF.  *  2. Only a sufficiently-privileged domain may specify<dom> != DOMID_SELF.  */
end_comment

begin_define
define|#
directive|define
name|GNTTABOP_query_size
value|6
end_define

begin_struct
struct|struct
name|gnttab_query_size
block|{
comment|/* IN parameters. */
name|domid_t
name|dom
decl_stmt|;
comment|/* OUT parameters. */
name|uint32_t
name|nr_frames
decl_stmt|;
name|uint32_t
name|max_nr_frames
decl_stmt|;
name|int16_t
name|status
decl_stmt|;
comment|/* GNTST_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gnttab_query_size
name|gnttab_query_size_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|gnttab_query_size_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * GNTTABOP_unmap_and_replace: Destroy one or more grant-reference mappings  * tracked by<handle> but atomically replace the page table entry with one  * pointing to the machine address under<new_addr>.<new_addr> will be  * redirected to the null entry.  * NOTES:  *  1. The call may fail in an undefined manner if either mapping is not  *     tracked by<handle>.  *  2. After executing a batch of unmaps, it is guaranteed that no stale  *     mappings will remain in the device or host TLBs.  */
end_comment

begin_define
define|#
directive|define
name|GNTTABOP_unmap_and_replace
value|7
end_define

begin_struct
struct|struct
name|gnttab_unmap_and_replace
block|{
comment|/* IN parameters. */
name|uint64_t
name|host_addr
decl_stmt|;
name|uint64_t
name|new_addr
decl_stmt|;
name|grant_handle_t
name|handle
decl_stmt|;
comment|/* OUT parameters. */
name|int16_t
name|status
decl_stmt|;
comment|/* GNTST_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gnttab_unmap_and_replace
name|gnttab_unmap_and_replace_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|gnttab_unmap_and_replace_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Bitfield values for update_pin_status.flags.  */
end_comment

begin_comment
comment|/* Map the grant entry for access by I/O devices. */
end_comment

begin_define
define|#
directive|define
name|_GNTMAP_device_map
value|(0)
end_define

begin_define
define|#
directive|define
name|GNTMAP_device_map
value|(1<<_GNTMAP_device_map)
end_define

begin_comment
comment|/* Map the grant entry for access by host CPUs. */
end_comment

begin_define
define|#
directive|define
name|_GNTMAP_host_map
value|(1)
end_define

begin_define
define|#
directive|define
name|GNTMAP_host_map
value|(1<<_GNTMAP_host_map)
end_define

begin_comment
comment|/* Accesses to the granted frame will be restricted to read-only access. */
end_comment

begin_define
define|#
directive|define
name|_GNTMAP_readonly
value|(2)
end_define

begin_define
define|#
directive|define
name|GNTMAP_readonly
value|(1<<_GNTMAP_readonly)
end_define

begin_comment
comment|/*   * GNTMAP_host_map subflag:   *  0 => The host mapping is usable only by the guest OS.   *  1 => The host mapping is usable by guest OS + current application.   */
end_comment

begin_define
define|#
directive|define
name|_GNTMAP_application_map
value|(3)
end_define

begin_define
define|#
directive|define
name|GNTMAP_application_map
value|(1<<_GNTMAP_application_map)
end_define

begin_comment
comment|/*   * GNTMAP_contains_pte subflag:   *  0 => This map request contains a host virtual address.   *  1 => This map request contains the machine addess of the PTE to update.   */
end_comment

begin_define
define|#
directive|define
name|_GNTMAP_contains_pte
value|(4)
end_define

begin_define
define|#
directive|define
name|GNTMAP_contains_pte
value|(1<<_GNTMAP_contains_pte)
end_define

begin_comment
comment|/*  * Values for error status returns. All errors are -ve.  */
end_comment

begin_define
define|#
directive|define
name|GNTST_okay
value|(0)
end_define

begin_comment
comment|/* Normal return.                        */
end_comment

begin_define
define|#
directive|define
name|GNTST_general_error
value|(-1)
end_define

begin_comment
comment|/* General undefined error.              */
end_comment

begin_define
define|#
directive|define
name|GNTST_bad_domain
value|(-2)
end_define

begin_comment
comment|/* Unrecognsed domain id.                */
end_comment

begin_define
define|#
directive|define
name|GNTST_bad_gntref
value|(-3)
end_define

begin_comment
comment|/* Unrecognised or inappropriate gntref. */
end_comment

begin_define
define|#
directive|define
name|GNTST_bad_handle
value|(-4)
end_define

begin_comment
comment|/* Unrecognised or inappropriate handle. */
end_comment

begin_define
define|#
directive|define
name|GNTST_bad_virt_addr
value|(-5)
end_define

begin_comment
comment|/* Inappropriate virtual address to map. */
end_comment

begin_define
define|#
directive|define
name|GNTST_bad_dev_addr
value|(-6)
end_define

begin_comment
comment|/* Inappropriate device address to unmap.*/
end_comment

begin_define
define|#
directive|define
name|GNTST_no_device_space
value|(-7)
end_define

begin_comment
comment|/* Out of space in I/O MMU.              */
end_comment

begin_define
define|#
directive|define
name|GNTST_permission_denied
value|(-8)
end_define

begin_comment
comment|/* Not enough privilege for operation.  */
end_comment

begin_define
define|#
directive|define
name|GNTST_bad_page
value|(-9)
end_define

begin_comment
comment|/* Specified page was invalid for op.    */
end_comment

begin_define
define|#
directive|define
name|GNTST_bad_copy_arg
value|(-10)
end_define

begin_comment
comment|/* copy arguments cross page boundary.   */
end_comment

begin_define
define|#
directive|define
name|GNTST_address_too_big
value|(-11)
end_define

begin_comment
comment|/* transfer page address too large.      */
end_comment

begin_define
define|#
directive|define
name|GNTTABOP_error_msgs
value|{                   \     "okay",                                     \     "undefined error",                          \     "unrecognised domain id",                   \     "invalid grant reference",                  \     "invalid mapping handle",                   \     "invalid virtual address",                  \     "invalid device address",                   \     "no spare translation slot in the I/O MMU", \     "permission denied",                        \     "bad page",                                 \     "copy arguments cross page boundary",       \     "page address size too large"               \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_GRANT_TABLE_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

