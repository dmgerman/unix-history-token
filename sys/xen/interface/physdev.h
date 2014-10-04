begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_PHYSDEV_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_PHYSDEV_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_comment
comment|/*  * Prototype for this hypercall is:  *  int physdev_op(int cmd, void *args)  * @cmd  == PHYSDEVOP_??? (physdev operation).  * @args == Operation-specific extra arguments (NULL if none).  */
end_comment

begin_comment
comment|/*  * Notify end-of-interrupt (EOI) for the specified IRQ.  * @arg == pointer to physdev_eoi structure.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_eoi
value|12
end_define

begin_struct
struct|struct
name|physdev_eoi
block|{
comment|/* IN */
name|uint32_t
name|irq
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_eoi
name|physdev_eoi_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_eoi_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Register a shared page for the hypervisor to indicate whether the guest  * must issue PHYSDEVOP_eoi. The semantics of PHYSDEVOP_eoi change slightly  * once the guest used this function in that the associated event channel  * will automatically get unmasked. The page registered is used as a bit  * array indexed by Xen's PIRQ value.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_pirq_eoi_gmfn_v1
value|17
end_define

begin_comment
comment|/*  * Register a shared page for the hypervisor to indicate whether the  * guest must issue PHYSDEVOP_eoi. This hypercall is very similar to  * PHYSDEVOP_pirq_eoi_gmfn_v1 but it doesn't change the semantics of  * PHYSDEVOP_eoi. The page registered is used as a bit array indexed by  * Xen's PIRQ value.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_pirq_eoi_gmfn_v2
value|28
end_define

begin_struct
struct|struct
name|physdev_pirq_eoi_gmfn
block|{
comment|/* IN */
name|xen_pfn_t
name|gmfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_pirq_eoi_gmfn
name|physdev_pirq_eoi_gmfn_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_pirq_eoi_gmfn_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Query the status of an IRQ line.  * @arg == pointer to physdev_irq_status_query structure.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_irq_status_query
value|5
end_define

begin_struct
struct|struct
name|physdev_irq_status_query
block|{
comment|/* IN */
name|uint32_t
name|irq
decl_stmt|;
comment|/* OUT */
name|uint32_t
name|flags
decl_stmt|;
comment|/* XENIRQSTAT_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_irq_status_query
name|physdev_irq_status_query_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_irq_status_query_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Need to call PHYSDEVOP_eoi when the IRQ has been serviced? */
end_comment

begin_define
define|#
directive|define
name|_XENIRQSTAT_needs_eoi
value|(0)
end_define

begin_define
define|#
directive|define
name|XENIRQSTAT_needs_eoi
value|(1U<<_XENIRQSTAT_needs_eoi)
end_define

begin_comment
comment|/* IRQ shared by multiple guests? */
end_comment

begin_define
define|#
directive|define
name|_XENIRQSTAT_shared
value|(1)
end_define

begin_define
define|#
directive|define
name|XENIRQSTAT_shared
value|(1U<<_XENIRQSTAT_shared)
end_define

begin_comment
comment|/*  * Set the current VCPU's I/O privilege level.  * @arg == pointer to physdev_set_iopl structure.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_set_iopl
value|6
end_define

begin_struct
struct|struct
name|physdev_set_iopl
block|{
comment|/* IN */
name|uint32_t
name|iopl
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_set_iopl
name|physdev_set_iopl_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_set_iopl_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Set the current VCPU's I/O-port permissions bitmap.  * @arg == pointer to physdev_set_iobitmap structure.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_set_iobitmap
value|7
end_define

begin_struct
struct|struct
name|physdev_set_iobitmap
block|{
comment|/* IN */
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>=
literal|0x00030205
name|XEN_GUEST_HANDLE
argument_list|(
argument|uint8
argument_list|)
name|bitmap
expr_stmt|;
else|#
directive|else
name|uint8_t
modifier|*
name|bitmap
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|nr_ports
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_set_iobitmap
name|physdev_set_iobitmap_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_set_iobitmap_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Read or write an IO-APIC register.  * @arg == pointer to physdev_apic structure.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_apic_read
value|8
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_apic_write
value|9
end_define

begin_struct
struct|struct
name|physdev_apic
block|{
comment|/* IN */
name|unsigned
name|long
name|apic_physbase
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
comment|/* IN or OUT */
name|uint32_t
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_apic
name|physdev_apic_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_apic_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Allocate or free a physical upcall vector for the specified IRQ line.  * @arg == pointer to physdev_irq structure.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_alloc_irq_vector
value|10
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_free_irq_vector
value|11
end_define

begin_struct
struct|struct
name|physdev_irq
block|{
comment|/* IN */
name|uint32_t
name|irq
decl_stmt|;
comment|/* IN or OUT */
name|uint32_t
name|vector
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_irq
name|physdev_irq_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_irq_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MAP_PIRQ_TYPE_MSI
value|0x0
end_define

begin_define
define|#
directive|define
name|MAP_PIRQ_TYPE_GSI
value|0x1
end_define

begin_define
define|#
directive|define
name|MAP_PIRQ_TYPE_UNKNOWN
value|0x2
end_define

begin_define
define|#
directive|define
name|MAP_PIRQ_TYPE_MSI_SEG
value|0x3
end_define

begin_define
define|#
directive|define
name|MAP_PIRQ_TYPE_MULTI_MSI
value|0x4
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_map_pirq
value|13
end_define

begin_struct
struct|struct
name|physdev_map_pirq
block|{
name|domid_t
name|domid
decl_stmt|;
comment|/* IN */
name|int
name|type
decl_stmt|;
comment|/* IN */
name|int
name|index
decl_stmt|;
comment|/* IN or OUT */
name|int
name|pirq
decl_stmt|;
comment|/* IN - high 16 bits hold segment for MAP_PIRQ_TYPE_MSI_SEG */
name|int
name|bus
decl_stmt|;
comment|/* IN */
name|int
name|devfn
decl_stmt|;
comment|/* IN */
name|int
name|entry_nr
decl_stmt|;
comment|/* IN */
name|uint64_t
name|table_base
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_map_pirq
name|physdev_map_pirq_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_map_pirq_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PHYSDEVOP_unmap_pirq
value|14
end_define

begin_struct
struct|struct
name|physdev_unmap_pirq
block|{
name|domid_t
name|domid
decl_stmt|;
comment|/* IN */
name|int
name|pirq
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_unmap_pirq
name|physdev_unmap_pirq_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_unmap_pirq_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PHYSDEVOP_manage_pci_add
value|15
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_manage_pci_remove
value|16
end_define

begin_struct
struct|struct
name|physdev_manage_pci
block|{
comment|/* IN */
name|uint8_t
name|bus
decl_stmt|;
name|uint8_t
name|devfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_manage_pci
name|physdev_manage_pci_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_manage_pci_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PHYSDEVOP_restore_msi
value|19
end_define

begin_struct
struct|struct
name|physdev_restore_msi
block|{
comment|/* IN */
name|uint8_t
name|bus
decl_stmt|;
name|uint8_t
name|devfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_restore_msi
name|physdev_restore_msi_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_restore_msi_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PHYSDEVOP_manage_pci_add_ext
value|20
end_define

begin_struct
struct|struct
name|physdev_manage_pci_ext
block|{
comment|/* IN */
name|uint8_t
name|bus
decl_stmt|;
name|uint8_t
name|devfn
decl_stmt|;
name|unsigned
name|is_extfn
decl_stmt|;
name|unsigned
name|is_virtfn
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|bus
decl_stmt|;
name|uint8_t
name|devfn
decl_stmt|;
block|}
name|physfn
struct|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_manage_pci_ext
name|physdev_manage_pci_ext_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_manage_pci_ext_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Argument to physdev_op_compat() hypercall. Superceded by new physdev_op()  * hypercall since 0x00030202.  */
end_comment

begin_struct
struct|struct
name|physdev_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
union|union
block|{
name|struct
name|physdev_irq_status_query
name|irq_status_query
decl_stmt|;
name|struct
name|physdev_set_iopl
name|set_iopl
decl_stmt|;
name|struct
name|physdev_set_iobitmap
name|set_iobitmap
decl_stmt|;
name|struct
name|physdev_apic
name|apic_op
decl_stmt|;
name|struct
name|physdev_irq
name|irq_op
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_op
name|physdev_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PHYSDEVOP_setup_gsi
value|21
end_define

begin_struct
struct|struct
name|physdev_setup_gsi
block|{
name|int
name|gsi
decl_stmt|;
comment|/* IN */
name|uint8_t
name|triggering
decl_stmt|;
comment|/* IN */
name|uint8_t
name|polarity
decl_stmt|;
comment|/* IN */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_setup_gsi
name|physdev_setup_gsi_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_setup_gsi_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* leave PHYSDEVOP 22 free */
end_comment

begin_comment
comment|/* type is MAP_PIRQ_TYPE_GSI or MAP_PIRQ_TYPE_MSI  * the hypercall returns a free pirq */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_get_free_pirq
value|23
end_define

begin_struct
struct|struct
name|physdev_get_free_pirq
block|{
comment|/* IN */
name|int
name|type
decl_stmt|;
comment|/* OUT */
name|uint32_t
name|pirq
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_get_free_pirq
name|physdev_get_free_pirq_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_get_free_pirq_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_PCI_MMCFG_RESERVED
value|0x1
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_pci_mmcfg_reserved
value|24
end_define

begin_struct
struct|struct
name|physdev_pci_mmcfg_reserved
block|{
name|uint64_t
name|address
decl_stmt|;
name|uint16_t
name|segment
decl_stmt|;
name|uint8_t
name|start_bus
decl_stmt|;
name|uint8_t
name|end_bus
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_pci_mmcfg_reserved
name|physdev_pci_mmcfg_reserved_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_pci_mmcfg_reserved_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_PCI_DEV_EXTFN
value|0x1
end_define

begin_define
define|#
directive|define
name|XEN_PCI_DEV_VIRTFN
value|0x2
end_define

begin_define
define|#
directive|define
name|XEN_PCI_DEV_PXM
value|0x4
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_pci_device_add
value|25
end_define

begin_struct
struct|struct
name|physdev_pci_device_add
block|{
comment|/* IN */
name|uint16_t
name|seg
decl_stmt|;
name|uint8_t
name|bus
decl_stmt|;
name|uint8_t
name|devfn
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|bus
decl_stmt|;
name|uint8_t
name|devfn
decl_stmt|;
block|}
name|physfn
struct|;
if|#
directive|if
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
name|uint32_t
name|optarr
index|[]
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
name|uint32_t
name|optarr
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_pci_device_add
name|physdev_pci_device_add_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_pci_device_add_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PHYSDEVOP_pci_device_remove
value|26
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_restore_msi_ext
value|27
end_define

begin_struct
struct|struct
name|physdev_pci_device
block|{
comment|/* IN */
name|uint16_t
name|seg
decl_stmt|;
name|uint8_t
name|bus
decl_stmt|;
name|uint8_t
name|devfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|physdev_pci_device
name|physdev_pci_device_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|physdev_pci_device_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Notify that some PIRQ-bound event channels have been unmasked.  * ** This command is obsolete since interface version 0x00030202 and is **  * ** unsupported by newer versions of Xen.                              **  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_IRQ_UNMASK_NOTIFY
value|4
end_define

begin_comment
comment|/*  * These all-capitals physdev operation names are superceded by the new names  * (defined above) since interface version 0x00030202.  */
end_comment

begin_define
define|#
directive|define
name|PHYSDEVOP_IRQ_STATUS_QUERY
value|PHYSDEVOP_irq_status_query
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_SET_IOPL
value|PHYSDEVOP_set_iopl
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_SET_IOBITMAP
value|PHYSDEVOP_set_iobitmap
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_APIC_READ
value|PHYSDEVOP_apic_read
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_APIC_WRITE
value|PHYSDEVOP_apic_write
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_ASSIGN_VECTOR
value|PHYSDEVOP_alloc_irq_vector
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_FREE_VECTOR
value|PHYSDEVOP_free_irq_vector
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_IRQ_NEEDS_UNMASK_NOTIFY
value|XENIRQSTAT_needs_eoi
end_define

begin_define
define|#
directive|define
name|PHYSDEVOP_IRQ_SHARED
value|XENIRQSTAT_shared
end_define

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|<
literal|0x00040200
end_if

begin_define
define|#
directive|define
name|PHYSDEVOP_pirq_eoi_gmfn
value|PHYSDEVOP_pirq_eoi_gmfn_v1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PHYSDEVOP_pirq_eoi_gmfn
value|PHYSDEVOP_pirq_eoi_gmfn_v2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_PHYSDEV_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

