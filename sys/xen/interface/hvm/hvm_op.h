begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_HVM_OP_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_HVM_OP_H__
end_define

begin_include
include|#
directive|include
file|"../xen.h"
end_include

begin_include
include|#
directive|include
file|"../trace.h"
end_include

begin_comment
comment|/* Get/set subcommands: extra argument == pointer to xen_hvm_param struct. */
end_comment

begin_define
define|#
directive|define
name|HVMOP_set_param
value|0
end_define

begin_define
define|#
directive|define
name|HVMOP_get_param
value|1
end_define

begin_struct
struct|struct
name|xen_hvm_param
block|{
name|domid_t
name|domid
decl_stmt|;
comment|/* IN */
name|uint32_t
name|index
decl_stmt|;
comment|/* IN */
name|uint64_t
name|value
decl_stmt|;
comment|/* IN/OUT */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_param
name|xen_hvm_param_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_param_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Set the logical level of one of a domain's PCI INTx wires. */
end_comment

begin_define
define|#
directive|define
name|HVMOP_set_pci_intx_level
value|2
end_define

begin_struct
struct|struct
name|xen_hvm_set_pci_intx_level
block|{
comment|/* Domain to be updated. */
name|domid_t
name|domid
decl_stmt|;
comment|/* PCI INTx identification in PCI topology (domain:bus:device:intx). */
name|uint8_t
name|domain
decl_stmt|,
name|bus
decl_stmt|,
name|device
decl_stmt|,
name|intx
decl_stmt|;
comment|/* Assertion level (0 = unasserted, 1 = asserted). */
name|uint8_t
name|level
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_set_pci_intx_level
name|xen_hvm_set_pci_intx_level_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_set_pci_intx_level_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Set the logical level of one of a domain's ISA IRQ wires. */
end_comment

begin_define
define|#
directive|define
name|HVMOP_set_isa_irq_level
value|3
end_define

begin_struct
struct|struct
name|xen_hvm_set_isa_irq_level
block|{
comment|/* Domain to be updated. */
name|domid_t
name|domid
decl_stmt|;
comment|/* ISA device identification, by ISA IRQ (0-15). */
name|uint8_t
name|isa_irq
decl_stmt|;
comment|/* Assertion level (0 = unasserted, 1 = asserted). */
name|uint8_t
name|level
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_set_isa_irq_level
name|xen_hvm_set_isa_irq_level_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_set_isa_irq_level_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HVMOP_set_pci_link_route
value|4
end_define

begin_struct
struct|struct
name|xen_hvm_set_pci_link_route
block|{
comment|/* Domain to be updated. */
name|domid_t
name|domid
decl_stmt|;
comment|/* PCI link identifier (0-3). */
name|uint8_t
name|link
decl_stmt|;
comment|/* ISA IRQ (1-15), or 0 (disable link). */
name|uint8_t
name|isa_irq
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_set_pci_link_route
name|xen_hvm_set_pci_link_route_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_set_pci_link_route_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Flushes all VCPU TLBs: @arg must be NULL. */
end_comment

begin_define
define|#
directive|define
name|HVMOP_flush_tlbs
value|5
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|HVMMEM_ram_rw
block|,
comment|/* Normal read/write guest RAM */
name|HVMMEM_ram_ro
block|,
comment|/* Read-only; writes are discarded */
name|HVMMEM_mmio_dm
block|,
comment|/* Reads and write go to the device model */
block|}
name|hvmmem_type_t
typedef|;
end_typedef

begin_comment
comment|/* Following tools-only interfaces may change in future. */
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

begin_comment
comment|/* Track dirty VRAM. */
end_comment

begin_define
define|#
directive|define
name|HVMOP_track_dirty_vram
value|6
end_define

begin_struct
struct|struct
name|xen_hvm_track_dirty_vram
block|{
comment|/* Domain to be tracked. */
name|domid_t
name|domid
decl_stmt|;
comment|/* First pfn to track. */
name|uint64_aligned_t
name|first_pfn
decl_stmt|;
comment|/* Number of pages to track. */
name|uint64_aligned_t
name|nr
decl_stmt|;
comment|/* OUT variable. */
comment|/* Dirty bitmap buffer. */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint8
argument_list|)
name|dirty_bitmap
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_track_dirty_vram
name|xen_hvm_track_dirty_vram_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_track_dirty_vram_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Notify that some pages got modified by the Device Model. */
end_comment

begin_define
define|#
directive|define
name|HVMOP_modified_memory
value|7
end_define

begin_struct
struct|struct
name|xen_hvm_modified_memory
block|{
comment|/* Domain to be updated. */
name|domid_t
name|domid
decl_stmt|;
comment|/* First pfn. */
name|uint64_aligned_t
name|first_pfn
decl_stmt|;
comment|/* Number of pages. */
name|uint64_aligned_t
name|nr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_modified_memory
name|xen_hvm_modified_memory_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_modified_memory_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HVMOP_set_mem_type
value|8
end_define

begin_comment
comment|/* Notify that a region of memory is to be treated in a specific way. */
end_comment

begin_struct
struct|struct
name|xen_hvm_set_mem_type
block|{
comment|/* Domain to be updated. */
name|domid_t
name|domid
decl_stmt|;
comment|/* Memory type */
name|uint16_t
name|hvmmem_type
decl_stmt|;
comment|/* Number of pages. */
name|uint32_t
name|nr
decl_stmt|;
comment|/* First pfn. */
name|uint64_aligned_t
name|first_pfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_set_mem_type
name|xen_hvm_set_mem_type_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_set_mem_type_t
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

begin_comment
comment|/* Hint from PV drivers for pagetable destruction. */
end_comment

begin_define
define|#
directive|define
name|HVMOP_pagetable_dying
value|9
end_define

begin_struct
struct|struct
name|xen_hvm_pagetable_dying
block|{
comment|/* Domain with a pagetable about to be destroyed. */
name|domid_t
name|domid
decl_stmt|;
name|uint16_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* align next field on 8-byte boundary */
comment|/* guest physical address of the toplevel pagetable dying */
name|uint64_t
name|gpa
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_pagetable_dying
name|xen_hvm_pagetable_dying_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_pagetable_dying_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Get the current Xen time, in nanoseconds since system boot. */
end_comment

begin_define
define|#
directive|define
name|HVMOP_get_time
value|10
end_define

begin_struct
struct|struct
name|xen_hvm_get_time
block|{
name|uint64_t
name|now
decl_stmt|;
comment|/* OUT */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_get_time
name|xen_hvm_get_time_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_get_time_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HVMOP_xentrace
value|11
end_define

begin_struct
struct|struct
name|xen_hvm_xentrace
block|{
name|uint16_t
name|event
decl_stmt|,
name|extra_bytes
decl_stmt|;
name|uint8_t
name|extra
index|[
name|TRACE_EXTRA_MAX
operator|*
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_xentrace
name|xen_hvm_xentrace_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_xentrace_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Following tools-only interfaces may change in future. */
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

begin_define
define|#
directive|define
name|HVMOP_set_mem_access
value|12
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|HVMMEM_access_n
block|,
name|HVMMEM_access_r
block|,
name|HVMMEM_access_w
block|,
name|HVMMEM_access_rw
block|,
name|HVMMEM_access_x
block|,
name|HVMMEM_access_rx
block|,
name|HVMMEM_access_wx
block|,
name|HVMMEM_access_rwx
block|,
name|HVMMEM_access_rx2rw
block|,
comment|/* Page starts off as r-x, but automatically                                 * change to r-w on a write */
name|HVMMEM_access_n2rwx
block|,
comment|/* Log access: starts off as n, automatically                                  * goes to rwx, generating an event without                                 * pausing the vcpu */
name|HVMMEM_access_default
comment|/* Take the domain default */
block|}
name|hvmmem_access_t
typedef|;
end_typedef

begin_comment
comment|/* Notify that a region of memory is to have specific access types */
end_comment

begin_struct
struct|struct
name|xen_hvm_set_mem_access
block|{
comment|/* Domain to be updated. */
name|domid_t
name|domid
decl_stmt|;
comment|/* Memory type */
name|uint16_t
name|hvmmem_access
decl_stmt|;
comment|/* hvm_access_t */
comment|/* Number of pages, ignored on setting default access */
name|uint32_t
name|nr
decl_stmt|;
comment|/* First pfn, or ~0ull to set the default access for new pages */
name|uint64_aligned_t
name|first_pfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_set_mem_access
name|xen_hvm_set_mem_access_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_set_mem_access_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HVMOP_get_mem_access
value|13
end_define

begin_comment
comment|/* Get the specific access type for that region of memory */
end_comment

begin_struct
struct|struct
name|xen_hvm_get_mem_access
block|{
comment|/* Domain to be queried. */
name|domid_t
name|domid
decl_stmt|;
comment|/* Memory type: OUT */
name|uint16_t
name|hvmmem_access
decl_stmt|;
comment|/* hvm_access_t */
comment|/* pfn, or ~0ull for default access for new pages.  IN */
name|uint64_aligned_t
name|pfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_get_mem_access
name|xen_hvm_get_mem_access_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_get_mem_access_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HVMOP_inject_trap
value|14
end_define

begin_comment
comment|/* Inject a trap into a VCPU, which will get taken up on the next  * scheduling of it. Note that the caller should know enough of the  * state of the CPU before injecting, to know what the effect of  * injecting the trap will be.  */
end_comment

begin_struct
struct|struct
name|xen_hvm_inject_trap
block|{
comment|/* Domain to be queried. */
name|domid_t
name|domid
decl_stmt|;
comment|/* VCPU */
name|uint32_t
name|vcpuid
decl_stmt|;
comment|/* Vector number */
name|uint32_t
name|vector
decl_stmt|;
comment|/* Trap type (HVMOP_TRAP_*) */
name|uint32_t
name|type
decl_stmt|;
comment|/* NB. This enumeration precisely matches hvm.h:X86_EVENTTYPE_* */
define|#
directive|define
name|HVMOP_TRAP_ext_int
value|0
comment|/* external interrupt */
define|#
directive|define
name|HVMOP_TRAP_nmi
value|2
comment|/* nmi */
define|#
directive|define
name|HVMOP_TRAP_hw_exc
value|3
comment|/* hardware exception */
define|#
directive|define
name|HVMOP_TRAP_sw_int
value|4
comment|/* software interrupt (CD nn) */
define|#
directive|define
name|HVMOP_TRAP_pri_sw_exc
value|5
comment|/* ICEBP (F1) */
define|#
directive|define
name|HVMOP_TRAP_sw_exc
value|6
comment|/* INT3 (CC), INTO (CE) */
comment|/* Error code, or ~0u to skip */
name|uint32_t
name|error_code
decl_stmt|;
comment|/* Intruction length */
name|uint32_t
name|insn_len
decl_stmt|;
comment|/* CR2 for page faults */
name|uint64_aligned_t
name|cr2
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_inject_trap
name|xen_hvm_inject_trap_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_inject_trap_t
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

begin_define
define|#
directive|define
name|HVMOP_get_mem_type
value|15
end_define

begin_comment
comment|/* Return hvmmem_type_t for the specified pfn. */
end_comment

begin_struct
struct|struct
name|xen_hvm_get_mem_type
block|{
comment|/* Domain to be queried. */
name|domid_t
name|domid
decl_stmt|;
comment|/* OUT variable. */
name|uint16_t
name|mem_type
decl_stmt|;
name|uint16_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* align next field on 8-byte boundary */
comment|/* IN variable. */
name|uint64_t
name|pfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_get_mem_type
name|xen_hvm_get_mem_type_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_get_mem_type_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Following tools-only interfaces may change in future. */
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

begin_comment
comment|/* MSI injection for emulated devices */
end_comment

begin_define
define|#
directive|define
name|HVMOP_inject_msi
value|16
end_define

begin_struct
struct|struct
name|xen_hvm_inject_msi
block|{
comment|/* Domain to be injected */
name|domid_t
name|domid
decl_stmt|;
comment|/* Data -- lower 32 bits */
name|uint32_t
name|data
decl_stmt|;
comment|/* Address (0xfeexxxxx) */
name|uint64_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_inject_msi
name|xen_hvm_inject_msi_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_inject_msi_t
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
comment|/* __XEN_PUBLIC_HVM_HVM_OP_H__ */
end_comment

end_unit

