begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xen.h  *   * Guest OS interface to Xen.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2004, K A Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_XEN_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_XEN_H__
end_define

begin_include
include|#
directive|include
file|"xen-compat.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"arch-x86/xen.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"arch-ia64.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"arch-arm.h"
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unsupported architecture"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_comment
comment|/* Guest handles for primitive C types. */
end_comment

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|char
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
argument|uchar
argument_list|,
argument|unsigned char
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|long
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
argument|ulong
argument_list|,
argument|unsigned long
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|uint64_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_pfn_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_ulong_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * HYPERCALLS  */
end_comment

begin_comment
comment|/* `incontents 100 hcalls List of hypercalls  * ` enum hypercall_num { // __HYPERVISOR_* => HYPERVISOR_*()  */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_set_trap_table
value|0
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_mmu_update
value|1
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_set_gdt
value|2
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_stack_switch
value|3
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_set_callbacks
value|4
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_fpu_taskswitch
value|5
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_sched_op_compat
value|6
end_define

begin_comment
comment|/* compat since 0x00030101 */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_platform_op
value|7
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_set_debugreg
value|8
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_get_debugreg
value|9
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_update_descriptor
value|10
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_memory_op
value|12
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_multicall
value|13
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_update_va_mapping
value|14
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_set_timer_op
value|15
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_event_channel_op_compat
value|16
end_define

begin_comment
comment|/* compat since 0x00030202 */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_xen_version
value|17
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_console_io
value|18
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_physdev_op_compat
value|19
end_define

begin_comment
comment|/* compat since 0x00030202 */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_grant_table_op
value|20
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_vm_assist
value|21
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_update_va_mapping_otherdomain
value|22
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_iret
value|23
end_define

begin_comment
comment|/* x86 only */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_vcpu_op
value|24
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_set_segment_base
value|25
end_define

begin_comment
comment|/* x86/64 only */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_mmuext_op
value|26
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_xsm_op
value|27
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_nmi_op
value|28
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_sched_op
value|29
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_callback_op
value|30
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_xenoprof_op
value|31
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_event_channel_op
value|32
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_physdev_op
value|33
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_hvm_op
value|34
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_sysctl
value|35
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_domctl
value|36
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_kexec_op
value|37
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_tmem_op
value|38
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_xc_reserved_op
value|39
end_define

begin_comment
comment|/* reserved for XenClient */
end_comment

begin_comment
comment|/* Architecture-specific hypercall definitions. */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_arch_0
value|48
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_arch_1
value|49
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_arch_2
value|50
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_arch_3
value|51
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_arch_4
value|52
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_arch_5
value|53
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_arch_6
value|54
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_arch_7
value|55
end_define

begin_comment
comment|/* ` } */
end_comment

begin_comment
comment|/*  * HYPERCALL COMPATIBILITY.  */
end_comment

begin_comment
comment|/* New sched_op hypercall introduced in 0x00030101. */
end_comment

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|<
literal|0x00030101
end_if

begin_undef
undef|#
directive|undef
name|__HYPERVISOR_sched_op
end_undef

begin_define
define|#
directive|define
name|__HYPERVISOR_sched_op
value|__HYPERVISOR_sched_op_compat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* New event-channel and physdev hypercalls introduced in 0x00030202. */
end_comment

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|<
literal|0x00030202
end_if

begin_undef
undef|#
directive|undef
name|__HYPERVISOR_event_channel_op
end_undef

begin_define
define|#
directive|define
name|__HYPERVISOR_event_channel_op
value|__HYPERVISOR_event_channel_op_compat
end_define

begin_undef
undef|#
directive|undef
name|__HYPERVISOR_physdev_op
end_undef

begin_define
define|#
directive|define
name|__HYPERVISOR_physdev_op
value|__HYPERVISOR_physdev_op_compat
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* New platform_op hypercall introduced in 0x00030204. */
end_comment

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|<
literal|0x00030204
end_if

begin_define
define|#
directive|define
name|__HYPERVISOR_dom0_op
value|__HYPERVISOR_platform_op
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * VIRTUAL INTERRUPTS  *   * Virtual interrupts that a guest OS may receive from Xen.  *   * In the side comments, 'V.' denotes a per-VCPU VIRQ while 'G.' denotes a  * global VIRQ. The former can be bound once per VCPU and cannot be re-bound.  * The latter can be allocated only once per guest: they must initially be  * allocated to VCPU0 but can subsequently be re-bound.  */
end_comment

begin_comment
comment|/* ` enum virq { */
end_comment

begin_define
define|#
directive|define
name|VIRQ_TIMER
value|0
end_define

begin_comment
comment|/* V. Timebase update, and/or requested timeout.  */
end_comment

begin_define
define|#
directive|define
name|VIRQ_DEBUG
value|1
end_define

begin_comment
comment|/* V. Request guest to dump debug info.           */
end_comment

begin_define
define|#
directive|define
name|VIRQ_CONSOLE
value|2
end_define

begin_comment
comment|/* G. (DOM0) Bytes received on emergency console. */
end_comment

begin_define
define|#
directive|define
name|VIRQ_DOM_EXC
value|3
end_define

begin_comment
comment|/* G. (DOM0) Exceptional event for some domain.   */
end_comment

begin_define
define|#
directive|define
name|VIRQ_TBUF
value|4
end_define

begin_comment
comment|/* G. (DOM0) Trace buffer has records available.  */
end_comment

begin_define
define|#
directive|define
name|VIRQ_DEBUGGER
value|6
end_define

begin_comment
comment|/* G. (DOM0) A domain has paused for debugging.   */
end_comment

begin_define
define|#
directive|define
name|VIRQ_XENOPROF
value|7
end_define

begin_comment
comment|/* V. XenOprofile interrupt: new sample available */
end_comment

begin_define
define|#
directive|define
name|VIRQ_CON_RING
value|8
end_define

begin_comment
comment|/* G. (DOM0) Bytes received on console            */
end_comment

begin_define
define|#
directive|define
name|VIRQ_PCPU_STATE
value|9
end_define

begin_comment
comment|/* G. (DOM0) PCPU state changed                   */
end_comment

begin_define
define|#
directive|define
name|VIRQ_MEM_EVENT
value|10
end_define

begin_comment
comment|/* G. (DOM0) A memory event has occured           */
end_comment

begin_define
define|#
directive|define
name|VIRQ_XC_RESERVED
value|11
end_define

begin_comment
comment|/* G. Reserved for XenClient                     */
end_comment

begin_define
define|#
directive|define
name|VIRQ_ENOMEM
value|12
end_define

begin_comment
comment|/* G. (DOM0) Low on heap memory       */
end_comment

begin_comment
comment|/* Architecture-specific VIRQ definitions. */
end_comment

begin_define
define|#
directive|define
name|VIRQ_ARCH_0
value|16
end_define

begin_define
define|#
directive|define
name|VIRQ_ARCH_1
value|17
end_define

begin_define
define|#
directive|define
name|VIRQ_ARCH_2
value|18
end_define

begin_define
define|#
directive|define
name|VIRQ_ARCH_3
value|19
end_define

begin_define
define|#
directive|define
name|VIRQ_ARCH_4
value|20
end_define

begin_define
define|#
directive|define
name|VIRQ_ARCH_5
value|21
end_define

begin_define
define|#
directive|define
name|VIRQ_ARCH_6
value|22
end_define

begin_define
define|#
directive|define
name|VIRQ_ARCH_7
value|23
end_define

begin_comment
comment|/* ` } */
end_comment

begin_define
define|#
directive|define
name|NR_VIRQS
value|24
end_define

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_mmu_update(const struct mmu_update reqs[],  * `                       unsigned count, unsigned *done_out,  * `                       unsigned foreigndom)  * `  * @reqs is an array of mmu_update_t structures ((ptr, val) pairs).  * @count is the length of the above array.  * @pdone is an output parameter indicating number of completed operations  * @foreigndom[15:0]: FD, the expected owner of data pages referenced in this  *                    hypercall invocation. Can be DOMID_SELF.  * @foreigndom[31:16]: PFD, the expected owner of pagetable pages referenced  *                     in this hypercall invocation. The value of this field  *                     (x) encodes the PFD as follows:  *                     x == 0 => PFD == DOMID_SELF  *                     x != 0 => PFD == x - 1  *   * Sub-commands: ptr[1:0] specifies the appropriate MMU_* command.  * -------------  * ptr[1:0] == MMU_NORMAL_PT_UPDATE:  * Updates an entry in a page table belonging to PFD. If updating an L1 table,  * and the new table entry is valid/present, the mapped frame must belong to  * FD. If attempting to map an I/O page then the caller assumes the privilege  * of the FD.  * FD == DOMID_IO: Permit /only/ I/O mappings, at the priv level of the caller.  * FD == DOMID_XEN: Map restricted areas of Xen's heap space.  * ptr[:2]  -- Machine address of the page-table entry to modify.  * val      -- Value to write.  *  * There also certain implicit requirements when using this hypercall. The  * pages that make up a pagetable must be mapped read-only in the guest.  * This prevents uncontrolled guest updates to the pagetable. Xen strictly  * enforces this, and will disallow any pagetable update which will end up  * mapping pagetable page RW, and will disallow using any writable page as a  * pagetable. In practice it means that when constructing a page table for a  * process, thread, etc, we MUST be very dilligient in following these rules:  *  1). Start with top-level page (PGD or in Xen language: L4). Fill out  *      the entries.  *  2). Keep on going, filling out the upper (PUD or L3), and middle (PMD  *      or L2).  *  3). Start filling out the PTE table (L1) with the PTE entries. Once  *  	done, make sure to set each of those entries to RO (so writeable bit  *  	is unset). Once that has been completed, set the PMD (L2) for this  *  	PTE table as RO.  *  4). When completed with all of the PMD (L2) entries, and all of them have  *  	been set to RO, make sure to set RO the PUD (L3). Do the same  *  	operation on PGD (L4) pagetable entries that have a PUD (L3) entry.  *  5). Now before you can use those pages (so setting the cr3), you MUST also  *      pin them so that the hypervisor can verify the entries. This is done  *      via the HYPERVISOR_mmuext_op(MMUEXT_PIN_L4_TABLE, guest physical frame  *      number of the PGD (L4)). And this point the HYPERVISOR_mmuext_op(  *      MMUEXT_NEW_BASEPTR, guest physical frame number of the PGD (L4)) can be  *      issued.  * For 32-bit guests, the L4 is not used (as there is less pagetables), so  * instead use L3.  * At this point the pagetables can be modified using the MMU_NORMAL_PT_UPDATE  * hypercall. Also if so desired the OS can also try to write to the PTE  * and be trapped by the hypervisor (as the PTE entry is RO).  *  * To deallocate the pages, the operations are the reverse of the steps  * mentioned above. The argument is MMUEXT_UNPIN_TABLE for all levels and the  * pagetable MUST not be in use (meaning that the cr3 is not set to it).  *   * ptr[1:0] == MMU_MACHPHYS_UPDATE:  * Updates an entry in the machine->pseudo-physical mapping table.  * ptr[:2]  -- Machine address within the frame whose mapping to modify.  *             The frame must belong to the FD, if one is specified.  * val      -- Value to write into the mapping entry.  *   * ptr[1:0] == MMU_PT_UPDATE_PRESERVE_AD:  * As MMU_NORMAL_PT_UPDATE above, but A/D bits currently in the PTE are ORed  * with those in @val.  *  * @val is usually the machine frame number along with some attributes.  * The attributes by default follow the architecture defined bits. Meaning that  * if this is a X86_64 machine and four page table layout is used, the layout  * of val is:  *  - 63 if set means No execute (NX)  *  - 46-13 the machine frame number  *  - 12 available for guest  *  - 11 available for guest  *  - 10 available for guest  *  - 9 available for guest  *  - 8 global  *  - 7 PAT (PSE is disabled, must use hypercall to make 4MB or 2MB pages)  *  - 6 dirty  *  - 5 accessed  *  - 4 page cached disabled  *  - 3 page write through  *  - 2 userspace accessible  *  - 1 writeable  *  - 0 present  *  *  The one bits that does not fit with the default layout is the PAGE_PSE  *  also called PAGE_PAT). The MMUEXT_[UN]MARK_SUPER arguments to the  *  HYPERVISOR_mmuext_op serve as mechanism to set a pagetable to be 4MB  *  (or 2MB) instead of using the PAGE_PSE bit.  *  *  The reason that the PAGE_PSE (bit 7) is not being utilized is due to Xen  *  using it as the Page Attribute Table (PAT) bit - for details on it please  *  refer to Intel SDM 10.12. The PAT allows to set the caching attributes of  *  pages instead of using MTRRs.  *  *  The PAT MSR is as follow (it is a 64-bit value, each entry is 8 bits):  *             PAT4                 PAT0  *   +---+----+----+----+-----+----+----+  *    WC | WC | WB | UC | UC- | WC | WB |<= Linux  *   +---+----+----+----+-----+----+----+  *    WC | WT | WB | UC | UC- | WT | WB |<= BIOS (default when machine boots)  *   +---+----+----+----+-----+----+----+  *    WC | WP | WC | UC | UC- | WT | WB |<= Xen  *   +---+----+----+----+-----+----+----+  *  *  The lookup of this index table translates to looking up  *  Bit 7, Bit 4, and Bit 3 of val entry:  *  *  PAT/PSE (bit 7) ... PCD (bit 4) .. PWT (bit 3).  *  *  If all bits are off, then we are using PAT0. If bit 3 turned on,  *  then we are using PAT1, if bit 3 and bit 4, then PAT2..  *  *  As you can see, the Linux PAT1 translates to PAT4 under Xen. Which means  *  that if a guest that follows Linux's PAT setup and would like to set Write  *  Combined on pages it MUST use PAT4 entry. Meaning that Bit 7 (PAGE_PAT) is  *  set. For example, under Linux it only uses PAT0, PAT1, and PAT2 for the  *  caching as:  *  *   WB = none (so PAT0)  *   WC = PWT (bit 3 on)  *   UC = PWT | PCD (bit 3 and 4 are on).  *  * To make it work with Xen, it needs to translate the WC bit as so:  *  *  PWT (so bit 3 on) --> PAT (so bit 7 is on) and clear bit 3  *  * And to translate back it would:  *  * PAT (bit 7 on) --> PWT (bit 3 on) and clear bit 7.  */
end_comment

begin_define
define|#
directive|define
name|MMU_NORMAL_PT_UPDATE
value|0
end_define

begin_comment
comment|/* checked '*ptr = val'. ptr is MA.      */
end_comment

begin_define
define|#
directive|define
name|MMU_MACHPHYS_UPDATE
value|1
end_define

begin_comment
comment|/* ptr = MA of frame to modify entry for */
end_comment

begin_define
define|#
directive|define
name|MMU_PT_UPDATE_PRESERVE_AD
value|2
end_define

begin_comment
comment|/* atomically: *ptr = val | (*ptr&(A|D)) */
end_comment

begin_comment
comment|/*  * MMU EXTENDED OPERATIONS  *   * HYPERVISOR_mmuext_op() accepts a list of mmuext_op structures.  * A foreigndom (FD) can be specified (or DOMID_SELF for none).  * Where the FD has some effect, it is described below.  *   * cmd: MMUEXT_(UN)PIN_*_TABLE  * mfn: Machine frame number to be (un)pinned as a p.t. page.  *      The frame must belong to the FD, if one is specified.  *   * cmd: MMUEXT_NEW_BASEPTR  * mfn: Machine frame number of new page-table base to install in MMU.  *   * cmd: MMUEXT_NEW_USER_BASEPTR [x86/64 only]  * mfn: Machine frame number of new page-table base to install in MMU  *      when in user space.  *   * cmd: MMUEXT_TLB_FLUSH_LOCAL  * No additional arguments. Flushes local TLB.  *   * cmd: MMUEXT_INVLPG_LOCAL  * linear_addr: Linear address to be flushed from the local TLB.  *   * cmd: MMUEXT_TLB_FLUSH_MULTI  * vcpumask: Pointer to bitmap of VCPUs to be flushed.  *   * cmd: MMUEXT_INVLPG_MULTI  * linear_addr: Linear address to be flushed.  * vcpumask: Pointer to bitmap of VCPUs to be flushed.  *   * cmd: MMUEXT_TLB_FLUSH_ALL  * No additional arguments. Flushes all VCPUs' TLBs.  *   * cmd: MMUEXT_INVLPG_ALL  * linear_addr: Linear address to be flushed from all VCPUs' TLBs.  *   * cmd: MMUEXT_FLUSH_CACHE  * No additional arguments. Writes back and flushes cache contents.  *  * cmd: MMUEXT_FLUSH_CACHE_GLOBAL  * No additional arguments. Writes back and flushes cache contents  * on all CPUs in the system.  *   * cmd: MMUEXT_SET_LDT  * linear_addr: Linear address of LDT base (NB. must be page-aligned).  * nr_ents: Number of entries in LDT.  *  * cmd: MMUEXT_CLEAR_PAGE  * mfn: Machine frame number to be cleared.  *  * cmd: MMUEXT_COPY_PAGE  * mfn: Machine frame number of the destination page.  * src_mfn: Machine frame number of the source page.  *  * cmd: MMUEXT_[UN]MARK_SUPER  * mfn: Machine frame number of head of superpage to be [un]marked.  */
end_comment

begin_define
define|#
directive|define
name|MMUEXT_PIN_L1_TABLE
value|0
end_define

begin_define
define|#
directive|define
name|MMUEXT_PIN_L2_TABLE
value|1
end_define

begin_define
define|#
directive|define
name|MMUEXT_PIN_L3_TABLE
value|2
end_define

begin_define
define|#
directive|define
name|MMUEXT_PIN_L4_TABLE
value|3
end_define

begin_define
define|#
directive|define
name|MMUEXT_UNPIN_TABLE
value|4
end_define

begin_define
define|#
directive|define
name|MMUEXT_NEW_BASEPTR
value|5
end_define

begin_define
define|#
directive|define
name|MMUEXT_TLB_FLUSH_LOCAL
value|6
end_define

begin_define
define|#
directive|define
name|MMUEXT_INVLPG_LOCAL
value|7
end_define

begin_define
define|#
directive|define
name|MMUEXT_TLB_FLUSH_MULTI
value|8
end_define

begin_define
define|#
directive|define
name|MMUEXT_INVLPG_MULTI
value|9
end_define

begin_define
define|#
directive|define
name|MMUEXT_TLB_FLUSH_ALL
value|10
end_define

begin_define
define|#
directive|define
name|MMUEXT_INVLPG_ALL
value|11
end_define

begin_define
define|#
directive|define
name|MMUEXT_FLUSH_CACHE
value|12
end_define

begin_define
define|#
directive|define
name|MMUEXT_SET_LDT
value|13
end_define

begin_define
define|#
directive|define
name|MMUEXT_NEW_USER_BASEPTR
value|15
end_define

begin_define
define|#
directive|define
name|MMUEXT_CLEAR_PAGE
value|16
end_define

begin_define
define|#
directive|define
name|MMUEXT_COPY_PAGE
value|17
end_define

begin_define
define|#
directive|define
name|MMUEXT_FLUSH_CACHE_GLOBAL
value|18
end_define

begin_define
define|#
directive|define
name|MMUEXT_MARK_SUPER
value|19
end_define

begin_define
define|#
directive|define
name|MMUEXT_UNMARK_SUPER
value|20
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_struct
struct|struct
name|mmuext_op
block|{
name|unsigned
name|int
name|cmd
decl_stmt|;
union|union
block|{
comment|/* [UN]PIN_TABLE, NEW_BASEPTR, NEW_USER_BASEPTR          * CLEAR_PAGE, COPY_PAGE, [UN]MARK_SUPER */
name|xen_pfn_t
name|mfn
decl_stmt|;
comment|/* INVLPG_LOCAL, INVLPG_ALL, SET_LDT */
name|unsigned
name|long
name|linear_addr
decl_stmt|;
block|}
name|arg1
union|;
union|union
block|{
comment|/* SET_LDT */
name|unsigned
name|int
name|nr_ents
decl_stmt|;
comment|/* TLB_FLUSH_MULTI, INVLPG_MULTI */
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>=
literal|0x00030205
name|XEN_GUEST_HANDLE
argument_list|(
argument|const_void
argument_list|)
name|vcpumask
expr_stmt|;
else|#
directive|else
specifier|const
name|void
modifier|*
name|vcpumask
decl_stmt|;
endif|#
directive|endif
comment|/* COPY_PAGE */
name|xen_pfn_t
name|src_mfn
decl_stmt|;
block|}
name|arg2
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mmuext_op
name|mmuext_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|mmuext_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are passed as 'flags' to update_va_mapping. They can be ORed. */
end_comment

begin_comment
comment|/* When specifying UVMF_MULTI, also OR in a pointer to a CPU bitmap.   */
end_comment

begin_comment
comment|/* UVMF_LOCAL is merely UVMF_MULTI with a NULL bitmap pointer.         */
end_comment

begin_define
define|#
directive|define
name|UVMF_NONE
value|(0UL<<0)
end_define

begin_comment
comment|/* No flushing at all.   */
end_comment

begin_define
define|#
directive|define
name|UVMF_TLB_FLUSH
value|(1UL<<0)
end_define

begin_comment
comment|/* Flush entire TLB(s).  */
end_comment

begin_define
define|#
directive|define
name|UVMF_INVLPG
value|(2UL<<0)
end_define

begin_comment
comment|/* Flush only one entry. */
end_comment

begin_define
define|#
directive|define
name|UVMF_FLUSHTYPE_MASK
value|(3UL<<0)
end_define

begin_define
define|#
directive|define
name|UVMF_MULTI
value|(0UL<<2)
end_define

begin_comment
comment|/* Flush subset of TLBs. */
end_comment

begin_define
define|#
directive|define
name|UVMF_LOCAL
value|(0UL<<2)
end_define

begin_comment
comment|/* Flush local TLB.      */
end_comment

begin_define
define|#
directive|define
name|UVMF_ALL
value|(1UL<<2)
end_define

begin_comment
comment|/* Flush all TLBs.       */
end_comment

begin_comment
comment|/*  * Commands to HYPERVISOR_console_io().  */
end_comment

begin_define
define|#
directive|define
name|CONSOLEIO_write
value|0
end_define

begin_define
define|#
directive|define
name|CONSOLEIO_read
value|1
end_define

begin_comment
comment|/*  * Commands to HYPERVISOR_vm_assist().  */
end_comment

begin_define
define|#
directive|define
name|VMASST_CMD_enable
value|0
end_define

begin_define
define|#
directive|define
name|VMASST_CMD_disable
value|1
end_define

begin_comment
comment|/* x86/32 guests: simulate full 4GB segment limits. */
end_comment

begin_define
define|#
directive|define
name|VMASST_TYPE_4gb_segments
value|0
end_define

begin_comment
comment|/* x86/32 guests: trap (vector 15) whenever above vmassist is used. */
end_comment

begin_define
define|#
directive|define
name|VMASST_TYPE_4gb_segments_notify
value|1
end_define

begin_comment
comment|/*  * x86 guests: support writes to bottom-level PTEs.  * NB1. Page-directory entries cannot be written.  * NB2. Guest must continue to remove all writable mappings of PTEs.  */
end_comment

begin_define
define|#
directive|define
name|VMASST_TYPE_writable_pagetables
value|2
end_define

begin_comment
comment|/* x86/PAE guests: support PDPTs above 4GB. */
end_comment

begin_define
define|#
directive|define
name|VMASST_TYPE_pae_extended_cr3
value|3
end_define

begin_define
define|#
directive|define
name|MAX_VMASST_TYPE
value|3
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_typedef
typedef|typedef
name|uint16_t
name|domid_t
typedef|;
end_typedef

begin_comment
comment|/* Domain ids>= DOMID_FIRST_RESERVED cannot be used for ordinary domains. */
end_comment

begin_define
define|#
directive|define
name|DOMID_FIRST_RESERVED
value|(0x7FF0U)
end_define

begin_comment
comment|/* DOMID_SELF is used in certain contexts to refer to oneself. */
end_comment

begin_define
define|#
directive|define
name|DOMID_SELF
value|(0x7FF0U)
end_define

begin_comment
comment|/*  * DOMID_IO is used to restrict page-table updates to mapping I/O memory.  * Although no Foreign Domain need be specified to map I/O pages, DOMID_IO  * is useful to ensure that no mappings to the OS's own heap are accidentally  * installed. (e.g., in Linux this could cause havoc as reference counts  * aren't adjusted on the I/O-mapping code path).  * This only makes sense in MMUEXT_SET_FOREIGNDOM, but in that context can  * be specified by any calling domain.  */
end_comment

begin_define
define|#
directive|define
name|DOMID_IO
value|(0x7FF1U)
end_define

begin_comment
comment|/*  * DOMID_XEN is used to allow privileged domains to map restricted parts of  * Xen's heap space (e.g., the machine_to_phys table).  * This only makes sense in MMUEXT_SET_FOREIGNDOM, and is only permitted if  * the caller is privileged.  */
end_comment

begin_define
define|#
directive|define
name|DOMID_XEN
value|(0x7FF2U)
end_define

begin_comment
comment|/*  * DOMID_COW is used as the owner of sharable pages */
end_comment

begin_define
define|#
directive|define
name|DOMID_COW
value|(0x7FF3U)
end_define

begin_comment
comment|/* DOMID_INVALID is used to identify pages with unknown owner. */
end_comment

begin_define
define|#
directive|define
name|DOMID_INVALID
value|(0x7FF4U)
end_define

begin_comment
comment|/* Idle domain. */
end_comment

begin_define
define|#
directive|define
name|DOMID_IDLE
value|(0x7FFFU)
end_define

begin_comment
comment|/*  * Send an array of these to HYPERVISOR_mmu_update().  * NB. The fields are natural pointer/address size for this architecture.  */
end_comment

begin_struct
struct|struct
name|mmu_update
block|{
name|uint64_t
name|ptr
decl_stmt|;
comment|/* Machine address of PTE. */
name|uint64_t
name|val
decl_stmt|;
comment|/* New contents of PTE.    */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mmu_update
name|mmu_update_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|mmu_update_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Send an array of these to HYPERVISOR_multicall().  * NB. The fields are natural register size for this architecture.  */
end_comment

begin_struct
struct|struct
name|multicall_entry
block|{
name|unsigned
name|long
name|op
decl_stmt|,
name|result
decl_stmt|;
name|unsigned
name|long
name|args
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|multicall_entry
name|multicall_entry_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|multicall_entry_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Event channel endpoints per domain:  *  1024 if a long is 32 bits; 4096 if a long is 64 bits.  */
end_comment

begin_define
define|#
directive|define
name|NR_EVENT_CHANNELS
value|(sizeof(unsigned long) * sizeof(unsigned long) * 64)
end_define

begin_struct
struct|struct
name|vcpu_time_info
block|{
comment|/*      * Updates to the following values are preceded and followed by an      * increment of 'version'. The guest can therefore detect updates by      * looking for changes to 'version'. If the least-significant bit of      * the version number is set then an update is in progress and the guest      * must wait to read a consistent set of values.      * The correct way to interact with the version number is similar to      * Linux's seqlock: see the implementations of read_seqbegin/read_seqretry.      */
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|pad0
decl_stmt|;
name|uint64_t
name|tsc_timestamp
decl_stmt|;
comment|/* TSC at last update of time vals.  */
name|uint64_t
name|system_time
decl_stmt|;
comment|/* Time, in nanosecs, since boot.    */
comment|/*      * Current system time:      *   system_time +      *   ((((tsc - tsc_timestamp)<< tsc_shift) * tsc_to_system_mul)>> 32)      * CPU frequency (Hz):      *   ((10^9<< 32) / tsc_to_system_mul)>> tsc_shift      */
name|uint32_t
name|tsc_to_system_mul
decl_stmt|;
name|int8_t
name|tsc_shift
decl_stmt|;
name|int8_t
name|pad1
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* 32 bytes */
end_comment

begin_typedef
typedef|typedef
name|struct
name|vcpu_time_info
name|vcpu_time_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vcpu_info
block|{
comment|/*      * 'evtchn_upcall_pending' is written non-zero by Xen to indicate      * a pending notification for a particular VCPU. It is then cleared       * by the guest OS /before/ checking for pending work, thus avoiding      * a set-and-check race. Note that the mask is only accessed by Xen      * on the CPU that is currently hosting the VCPU. This means that the      * pending and mask flags can be updated by the guest without special      * synchronisation (i.e., no need for the x86 LOCK prefix).      * This may seem suboptimal because if the pending flag is set by      * a different CPU then an IPI may be scheduled even when the mask      * is set. However, note:      *  1. The task of 'interrupt holdoff' is covered by the per-event-      *     channel mask bits. A 'noisy' event that is continually being      *     triggered can be masked at source at this very precise      *     granularity.      *  2. The main purpose of the per-VCPU mask is therefore to restrict      *     reentrant execution: whether for concurrency control, or to      *     prevent unbounded stack usage. Whatever the purpose, we expect      *     that the mask will be asserted only for short periods at a time,      *     and so the likelihood of a 'spurious' IPI is suitably small.      * The mask is read before making an event upcall to the guest: a      * non-zero mask therefore guarantees that the VCPU will not receive      * an upcall activation. The mask is cleared when the VCPU requests      * to block: this avoids wakeup-waiting races.      */
name|uint8_t
name|evtchn_upcall_pending
decl_stmt|;
name|uint8_t
name|evtchn_upcall_mask
decl_stmt|;
name|unsigned
name|long
name|evtchn_pending_sel
decl_stmt|;
name|struct
name|arch_vcpu_info
name|arch
decl_stmt|;
name|struct
name|vcpu_time_info
name|time
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* 64 bytes (x86) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN__
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|vcpu_info
name|vcpu_info_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Xen/kernel shared data -- pointer provided in start_info.  *  * This structure is defined to be both smaller than a page, and the  * only data on the shared page, but may vary in actual size even within  * compatible Xen versions; guests should not rely on the size  * of this structure remaining constant.  */
end_comment

begin_struct
struct|struct
name|shared_info
block|{
name|struct
name|vcpu_info
name|vcpu_info
index|[
name|XEN_LEGACY_MAX_VCPUS
index|]
decl_stmt|;
comment|/*      * A domain can create "event channels" on which it can send and receive      * asynchronous event notifications. There are three classes of event that      * are delivered by this mechanism:      *  1. Bi-directional inter- and intra-domain connections. Domains must      *     arrange out-of-band to set up a connection (usually by allocating      *     an unbound 'listener' port and avertising that via a storage service      *     such as xenstore).      *  2. Physical interrupts. A domain with suitable hardware-access      *     privileges can bind an event-channel port to a physical interrupt      *     source.      *  3. Virtual interrupts ('events'). A domain can bind an event-channel      *     port to a virtual interrupt source, such as the virtual-timer      *     device or the emergency console.      *       * Event channels are addressed by a "port index". Each channel is      * associated with two bits of information:      *  1. PENDING -- notifies the domain that there is a pending notification      *     to be processed. This bit is cleared by the guest.      *  2. MASK -- if this bit is clear then a 0->1 transition of PENDING      *     will cause an asynchronous upcall to be scheduled. This bit is only      *     updated by the guest. It is read-only within Xen. If a channel      *     becomes pending while the channel is masked then the 'edge' is lost      *     (i.e., when the channel is unmasked, the guest must manually handle      *     pending notifications as no upcall will be scheduled by Xen).      *       * To expedite scanning of pending notifications, any 0->1 pending      * transition on an unmasked channel causes a corresponding bit in a      * per-vcpu selector word to be set. Each bit in the selector covers a      * 'C long' in the PENDING bitfield array.      */
name|unsigned
name|long
name|evtchn_pending
index|[
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|*
literal|8
expr|]
expr_stmt|;
name|unsigned
name|long
name|evtchn_mask
index|[
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|*
literal|8
expr|]
expr_stmt|;
comment|/*      * Wallclock time: updated only by control software. Guests should base      * their gettimeofday() syscall on this wallclock-base value.      */
name|uint32_t
name|wc_version
decl_stmt|;
comment|/* Version counter: see vcpu_time_info_t. */
name|uint32_t
name|wc_sec
decl_stmt|;
comment|/* Secs  00:00:00 UTC, Jan 1, 1970.  */
name|uint32_t
name|wc_nsec
decl_stmt|;
comment|/* Nsecs 00:00:00 UTC, Jan 1, 1970.  */
name|struct
name|arch_shared_info
name|arch
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN__
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|shared_info
name|shared_info_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Start-of-day memory layout:  *  1. The domain is started within contiguous virtual-memory region.  *  2. The contiguous region ends on an aligned 4MB boundary.  *  3. This the order of bootstrap elements in the initial virtual region:  *      a. relocated kernel image  *      b. initial ram disk              [mod_start, mod_len]  *      c. list of allocated page frames [mfn_list, nr_pages]  *         (unless relocated due to XEN_ELFNOTE_INIT_P2M)  *      d. start_info_t structure        [register ESI (x86)]  *      e. bootstrap page tables         [pt_base, CR3 (x86)]  *      f. bootstrap stack               [register ESP (x86)]  *  4. Bootstrap elements are packed together, but each is 4kB-aligned.  *  5. The initial ram disk may be omitted.  *  6. The list of page frames forms a contiguous 'pseudo-physical' memory  *     layout for the domain. In particular, the bootstrap virtual-memory  *     region is a 1:1 mapping to the first section of the pseudo-physical map.  *  7. All bootstrap elements are mapped read-writable for the guest OS. The  *     only exception is the bootstrap page table, which is mapped read-only.  *  8. There is guaranteed to be at least 512kB padding after the final  *     bootstrap element. If necessary, the bootstrap virtual region is  *     extended by an extra 4MB to ensure this.  */
end_comment

begin_define
define|#
directive|define
name|MAX_GUEST_CMDLINE
value|1024
end_define

begin_struct
struct|struct
name|start_info
block|{
comment|/* THE FOLLOWING ARE FILLED IN BOTH ON INITIAL BOOT AND ON RESUME.    */
name|char
name|magic
index|[
literal|32
index|]
decl_stmt|;
comment|/* "xen-<version>-<platform>".            */
name|unsigned
name|long
name|nr_pages
decl_stmt|;
comment|/* Total pages allocated to this domain.  */
name|unsigned
name|long
name|shared_info
decl_stmt|;
comment|/* MACHINE address of shared info struct. */
name|uint32_t
name|flags
decl_stmt|;
comment|/* SIF_xxx flags.                         */
name|xen_pfn_t
name|store_mfn
decl_stmt|;
comment|/* MACHINE page number of shared page.    */
name|uint32_t
name|store_evtchn
decl_stmt|;
comment|/* Event channel for store communication. */
union|union
block|{
struct|struct
block|{
name|xen_pfn_t
name|mfn
decl_stmt|;
comment|/* MACHINE page number of console page.   */
name|uint32_t
name|evtchn
decl_stmt|;
comment|/* Event channel for console page.        */
block|}
name|domU
struct|;
struct|struct
block|{
name|uint32_t
name|info_off
decl_stmt|;
comment|/* Offset of console_info struct.         */
name|uint32_t
name|info_size
decl_stmt|;
comment|/* Size of console_info struct from start.*/
block|}
name|dom0
struct|;
block|}
name|console
union|;
comment|/* THE FOLLOWING ARE ONLY FILLED IN ON INITIAL BOOT (NOT RESUME).     */
name|unsigned
name|long
name|pt_base
decl_stmt|;
comment|/* VIRTUAL address of page directory.     */
name|unsigned
name|long
name|nr_pt_frames
decl_stmt|;
comment|/* Number of bootstrap p.t. frames.       */
name|unsigned
name|long
name|mfn_list
decl_stmt|;
comment|/* VIRTUAL address of page-frame list.    */
name|unsigned
name|long
name|mod_start
decl_stmt|;
comment|/* VIRTUAL address of pre-loaded module   */
comment|/* (PFN of pre-loaded module if           */
comment|/*  SIF_MOD_START_PFN set in flags).      */
name|unsigned
name|long
name|mod_len
decl_stmt|;
comment|/* Size (bytes) of pre-loaded module.     */
name|int8_t
name|cmd_line
index|[
name|MAX_GUEST_CMDLINE
index|]
decl_stmt|;
comment|/* The pfn range here covers both page table and p->m table frames.   */
name|unsigned
name|long
name|first_p2m_pfn
decl_stmt|;
comment|/* 1st pfn forming initial P->M table.    */
name|unsigned
name|long
name|nr_p2m_frames
decl_stmt|;
comment|/* # of pfns forming initial P->M table.  */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|start_info
name|start_info_t
typedef|;
end_typedef

begin_comment
comment|/* New console union for dom0 introduced in 0x00030203. */
end_comment

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|<
literal|0x00030203
end_if

begin_define
define|#
directive|define
name|console_mfn
value|console.domU.mfn
end_define

begin_define
define|#
directive|define
name|console_evtchn
value|console.domU.evtchn
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These flags are passed in the 'flags' field of start_info_t. */
end_comment

begin_define
define|#
directive|define
name|SIF_PRIVILEGED
value|(1<<0)
end_define

begin_comment
comment|/* Is the domain privileged? */
end_comment

begin_define
define|#
directive|define
name|SIF_INITDOMAIN
value|(1<<1)
end_define

begin_comment
comment|/* Is this the initial control domain? */
end_comment

begin_define
define|#
directive|define
name|SIF_MULTIBOOT_MOD
value|(1<<2)
end_define

begin_comment
comment|/* Is mod_start a multiboot module? */
end_comment

begin_define
define|#
directive|define
name|SIF_MOD_START_PFN
value|(1<<3)
end_define

begin_comment
comment|/* Is mod_start a PFN? */
end_comment

begin_define
define|#
directive|define
name|SIF_PM_MASK
value|(0xFF<<8)
end_define

begin_comment
comment|/* reserve 1 byte for xen-pm options */
end_comment

begin_comment
comment|/*  * A multiboot module is a package containing modules very similar to a  * multiboot module array. The only differences are:  * - the array of module descriptors is by convention simply at the beginning  *   of the multiboot module,  * - addresses in the module descriptors are based on the beginning of the  *   multiboot module,  * - the number of modules is determined by a termination descriptor that has  *   mod_start == 0.  *  * This permits to both build it statically and reference it in a configuration  * file, and let the PV guest easily rebase the addresses to virtual addresses  * and at the same time count the number of modules.  */
end_comment

begin_struct
struct|struct
name|xen_multiboot_mod_list
block|{
comment|/* Address of first byte of the module */
name|uint32_t
name|mod_start
decl_stmt|;
comment|/* Address of last byte of the module (inclusive) */
name|uint32_t
name|mod_end
decl_stmt|;
comment|/* Address of zero-terminated command line */
name|uint32_t
name|cmdline
decl_stmt|;
comment|/* Unused, must be zero */
name|uint32_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|dom0_vga_console_info
block|{
name|uint8_t
name|video_type
decl_stmt|;
comment|/* DOM0_VGA_CONSOLE_??? */
define|#
directive|define
name|XEN_VGATYPE_TEXT_MODE_3
value|0x03
define|#
directive|define
name|XEN_VGATYPE_VESA_LFB
value|0x23
define|#
directive|define
name|XEN_VGATYPE_EFI_LFB
value|0x70
union|union
block|{
struct|struct
block|{
comment|/* Font height, in pixels. */
name|uint16_t
name|font_height
decl_stmt|;
comment|/* Cursor location (column, row). */
name|uint16_t
name|cursor_x
decl_stmt|,
name|cursor_y
decl_stmt|;
comment|/* Number of rows and columns (dimensions in characters). */
name|uint16_t
name|rows
decl_stmt|,
name|columns
decl_stmt|;
block|}
name|text_mode_3
struct|;
struct|struct
block|{
comment|/* Width and height, in pixels. */
name|uint16_t
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* Bytes per scan line. */
name|uint16_t
name|bytes_per_line
decl_stmt|;
comment|/* Bits per pixel. */
name|uint16_t
name|bits_per_pixel
decl_stmt|;
comment|/* LFB physical address, and size (in units of 64kB). */
name|uint32_t
name|lfb_base
decl_stmt|;
name|uint32_t
name|lfb_size
decl_stmt|;
comment|/* RGB mask offsets and sizes, as defined by VBE 1.2+ */
name|uint8_t
name|red_pos
decl_stmt|,
name|red_size
decl_stmt|;
name|uint8_t
name|green_pos
decl_stmt|,
name|green_size
decl_stmt|;
name|uint8_t
name|blue_pos
decl_stmt|,
name|blue_size
decl_stmt|;
name|uint8_t
name|rsvd_pos
decl_stmt|,
name|rsvd_size
decl_stmt|;
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>=
literal|0x00030206
comment|/* VESA capabilities (offset 0xa, VESA command 0x4f00). */
name|uint32_t
name|gbl_caps
decl_stmt|;
comment|/* Mode attributes (offset 0x0, VESA command 0x4f01). */
name|uint16_t
name|mode_attrs
decl_stmt|;
endif|#
directive|endif
block|}
name|vesa_lfb
struct|;
block|}
name|u
union|;
block|}
name|dom0_vga_console_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|xen_vga_console_info
value|dom0_vga_console_info
end_define

begin_define
define|#
directive|define
name|xen_vga_console_info_t
value|dom0_vga_console_info_t
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|xen_domain_handle_t
index|[
literal|16
index|]
typedef|;
end_typedef

begin_comment
comment|/* Turn a plain number into a C unsigned long constant. */
end_comment

begin_define
define|#
directive|define
name|__mk_unsigned_long
parameter_list|(
name|x
parameter_list|)
value|x ## UL
end_define

begin_define
define|#
directive|define
name|mk_unsigned_long
parameter_list|(
name|x
parameter_list|)
value|__mk_unsigned_long(x)
end_define

begin_expr_stmt
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|uint8
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|uint16
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|uint32
argument_list|,
name|uint32_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|uint64
argument_list|,
name|uint64_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ASSEMBLY__ */
end_comment

begin_comment
comment|/* In assembly code we cannot use C numeric constant suffixes. */
end_comment

begin_define
define|#
directive|define
name|mk_unsigned_long
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY__ */
end_comment

begin_comment
comment|/* Default definitions for macros used by domctl/sysctl. */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|XEN_GUEST_HANDLE_64
end_ifndef

begin_define
define|#
directive|define
name|XEN_GUEST_HANDLE_64
parameter_list|(
name|name
parameter_list|)
value|XEN_GUEST_HANDLE(name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_struct
struct|struct
name|xenctl_cpumap
block|{
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint8
argument_list|)
name|bitmap
expr_stmt|;
name|uint32_t
name|nr_cpus
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* __XEN_PUBLIC_XEN_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

