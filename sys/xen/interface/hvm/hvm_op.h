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
name|hvmmem_type_t
name|hvmmem_type
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_HVM_OP_H__ */
end_comment

end_unit

