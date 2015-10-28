begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2007, Keir Fraser  */
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

begin_include
include|#
directive|include
file|"../event_channel.h"
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
name|HVMMEM_mmio_write_dm
comment|/* Read-only; writes go to the device model */
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
comment|/* Number of pages to track. */
name|uint32_t
name|nr
decl_stmt|;
comment|/* First pfn to track. */
name|uint64_aligned_t
name|first_pfn
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

begin_comment
comment|/* Deprecated by XENMEM_access_op_set_access */
end_comment

begin_define
define|#
directive|define
name|HVMOP_set_mem_access
value|12
end_define

begin_comment
comment|/* Deprecated by XENMEM_access_op_get_access */
end_comment

begin_define
define|#
directive|define
name|HVMOP_get_mem_access
value|13
end_define

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

begin_comment
comment|/*  * IOREQ Servers  *  * The interface between an I/O emulator an Xen is called an IOREQ Server.  * A domain supports a single 'legacy' IOREQ Server which is instantiated if  * parameter...  *  * HVM_PARAM_IOREQ_PFN is read (to get the gmfn containing the synchronous  * ioreq structures), or...  * HVM_PARAM_BUFIOREQ_PFN is read (to get the gmfn containing the buffered  * ioreq ring), or...  * HVM_PARAM_BUFIOREQ_EVTCHN is read (to get the event channel that Xen uses  * to request buffered I/O emulation).  *   * The following hypercalls facilitate the creation of IOREQ Servers for  * 'secondary' emulators which are invoked to implement port I/O, memory, or  * PCI config space ranges which they explicitly register.  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|ioservid_t
typedef|;
end_typedef

begin_comment
comment|/*  * HVMOP_create_ioreq_server: Instantiate a new IOREQ Server for a secondary  *                            emulator servicing domain<domid>.  *  * The<id> handed back is unique for<domid>. If<handle_bufioreq> is zero  * the buffered ioreq ring will not be allocated and hence all emulation  * requestes to this server will be synchronous.  */
end_comment

begin_define
define|#
directive|define
name|HVMOP_create_ioreq_server
value|17
end_define

begin_struct
struct|struct
name|xen_hvm_create_ioreq_server
block|{
name|domid_t
name|domid
decl_stmt|;
comment|/* IN - domain to be serviced */
define|#
directive|define
name|HVM_IOREQSRV_BUFIOREQ_OFF
value|0
define|#
directive|define
name|HVM_IOREQSRV_BUFIOREQ_LEGACY
value|1
comment|/*  * Use this when read_pointer gets updated atomically and  * the pointer pair gets read atomically:  */
define|#
directive|define
name|HVM_IOREQSRV_BUFIOREQ_ATOMIC
value|2
name|uint8_t
name|handle_bufioreq
decl_stmt|;
comment|/* IN - should server handle buffered ioreqs */
name|ioservid_t
name|id
decl_stmt|;
comment|/* OUT - server id */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_create_ioreq_server
name|xen_hvm_create_ioreq_server_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_create_ioreq_server_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * HVMOP_get_ioreq_server_info: Get all the information necessary to access  *                              IOREQ Server<id>.   *  * The emulator needs to map the synchronous ioreq structures and buffered  * ioreq ring (if it exists) that Xen uses to request emulation. These are  * hosted in domain<domid>'s gmfns<ioreq_pfn> and<bufioreq_pfn>  * respectively. In addition, if the IOREQ Server is handling buffered  * emulation requests, the emulator needs to bind to event channel  *<bufioreq_port> to listen for them. (The event channels used for  * synchronous emulation requests are specified in the per-CPU ioreq  * structures in<ioreq_pfn>).  * If the IOREQ Server is not handling buffered emulation requests then the  * values handed back in<bufioreq_pfn> and<bufioreq_port> will both be 0.  */
end_comment

begin_define
define|#
directive|define
name|HVMOP_get_ioreq_server_info
value|18
end_define

begin_struct
struct|struct
name|xen_hvm_get_ioreq_server_info
block|{
name|domid_t
name|domid
decl_stmt|;
comment|/* IN - domain to be serviced */
name|ioservid_t
name|id
decl_stmt|;
comment|/* IN - server id */
name|evtchn_port_t
name|bufioreq_port
decl_stmt|;
comment|/* OUT - buffered ioreq port */
name|uint64_aligned_t
name|ioreq_pfn
decl_stmt|;
comment|/* OUT - sync ioreq pfn */
name|uint64_aligned_t
name|bufioreq_pfn
decl_stmt|;
comment|/* OUT - buffered ioreq pfn */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_get_ioreq_server_info
name|xen_hvm_get_ioreq_server_info_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_get_ioreq_server_info_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * HVM_map_io_range_to_ioreq_server: Register an I/O range of domain<domid>  *                                   for emulation by the client of IOREQ  *                                   Server<id>  * HVM_unmap_io_range_from_ioreq_server: Deregister an I/O range of<domid>  *                                       for emulation by the client of IOREQ  *                                       Server<id>  *  * There are three types of I/O that can be emulated: port I/O, memory accesses  * and PCI config space accesses. The<type> field denotes which type of range  * the<start> and<end> (inclusive) fields are specifying.  * PCI config space ranges are specified by segment/bus/device/function values  * which should be encoded using the HVMOP_PCI_SBDF helper macro below.  *  * NOTE: unless an emulation request falls entirely within a range mapped  * by a secondary emulator, it will not be passed to that emulator.  */
end_comment

begin_define
define|#
directive|define
name|HVMOP_map_io_range_to_ioreq_server
value|19
end_define

begin_define
define|#
directive|define
name|HVMOP_unmap_io_range_from_ioreq_server
value|20
end_define

begin_struct
struct|struct
name|xen_hvm_io_range
block|{
name|domid_t
name|domid
decl_stmt|;
comment|/* IN - domain to be serviced */
name|ioservid_t
name|id
decl_stmt|;
comment|/* IN - server id */
name|uint32_t
name|type
decl_stmt|;
comment|/* IN - type of range */
define|#
directive|define
name|HVMOP_IO_RANGE_PORT
value|0
comment|/* I/O port range */
define|#
directive|define
name|HVMOP_IO_RANGE_MEMORY
value|1
comment|/* MMIO range */
define|#
directive|define
name|HVMOP_IO_RANGE_PCI
value|2
comment|/* PCI segment/bus/dev/func range */
name|uint64_aligned_t
name|start
decl_stmt|,
name|end
decl_stmt|;
comment|/* IN - inclusive start and end of range */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_io_range
name|xen_hvm_io_range_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_io_range_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|HVMOP_PCI_SBDF
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|)
define|\
value|((((s)& 0xffff)<< 16) |                   \ 	 (((b)& 0xff)<< 8) |                      \ 	 (((d)& 0x1f)<< 3) |                      \ 	 ((f)& 0x07))
end_define

begin_comment
comment|/*  * HVMOP_destroy_ioreq_server: Destroy the IOREQ Server<id> servicing domain  *<domid>.  *  * Any registered I/O ranges will be automatically deregistered.  */
end_comment

begin_define
define|#
directive|define
name|HVMOP_destroy_ioreq_server
value|21
end_define

begin_struct
struct|struct
name|xen_hvm_destroy_ioreq_server
block|{
name|domid_t
name|domid
decl_stmt|;
comment|/* IN - domain to be serviced */
name|ioservid_t
name|id
decl_stmt|;
comment|/* IN - server id */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_destroy_ioreq_server
name|xen_hvm_destroy_ioreq_server_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_destroy_ioreq_server_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * HVMOP_set_ioreq_server_state: Enable or disable the IOREQ Server<id> servicing  *                               domain<domid>.  *  * The IOREQ Server will not be passed any emulation requests until it is in the  * enabled state.  * Note that the contents of the ioreq_pfn and bufioreq_fn (see  * HVMOP_get_ioreq_server_info) are not meaningful until the IOREQ Server is in  * the enabled state.  */
end_comment

begin_define
define|#
directive|define
name|HVMOP_set_ioreq_server_state
value|22
end_define

begin_struct
struct|struct
name|xen_hvm_set_ioreq_server_state
block|{
name|domid_t
name|domid
decl_stmt|;
comment|/* IN - domain to be serviced */
name|ioservid_t
name|id
decl_stmt|;
comment|/* IN - server id */
name|uint8_t
name|enabled
decl_stmt|;
comment|/* IN - enabled? */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_set_ioreq_server_state
name|xen_hvm_set_ioreq_server_state_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_set_ioreq_server_state_t
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

begin_comment
comment|/*  * HVMOP_set_evtchn_upcall_vector: Set a<vector> that should be used for event  *                                 channel upcalls on the specified<vcpu>. If set,  *                                 this vector will be used in preference to the  *                                 domain global callback via (see  *                                 HVM_PARAM_CALLBACK_IRQ).  */
end_comment

begin_define
define|#
directive|define
name|HVMOP_set_evtchn_upcall_vector
value|23
end_define

begin_struct
struct|struct
name|xen_hvm_evtchn_upcall_vector
block|{
name|uint32_t
name|vcpu
decl_stmt|;
name|uint8_t
name|vector
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_evtchn_upcall_vector
name|xen_hvm_evtchn_upcall_vector_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_evtchn_upcall_vector_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__i386__) || defined(__x86_64__) */
end_comment

begin_define
define|#
directive|define
name|HVMOP_guest_request_vm_event
value|24
end_define

begin_comment
comment|/* HVMOP_altp2m: perform altp2m state operations */
end_comment

begin_define
define|#
directive|define
name|HVMOP_altp2m
value|25
end_define

begin_define
define|#
directive|define
name|HVMOP_ALTP2M_INTERFACE_VERSION
value|0x00000001
end_define

begin_struct
struct|struct
name|xen_hvm_altp2m_domain_state
block|{
comment|/* IN or OUT variable on/off */
name|uint8_t
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_altp2m_domain_state
name|xen_hvm_altp2m_domain_state_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_altp2m_domain_state_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_hvm_altp2m_vcpu_enable_notify
block|{
name|uint32_t
name|vcpu_id
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
comment|/* #VE info area gfn */
name|uint64_t
name|gfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_altp2m_vcpu_enable_notify
name|xen_hvm_altp2m_vcpu_enable_notify_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_altp2m_vcpu_enable_notify_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_hvm_altp2m_view
block|{
comment|/* IN/OUT variable */
name|uint16_t
name|view
decl_stmt|;
comment|/* Create view only: default access type      * NOTE: currently ignored */
name|uint16_t
name|hvmmem_default_access
decl_stmt|;
comment|/* xenmem_access_t */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_altp2m_view
name|xen_hvm_altp2m_view_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_altp2m_view_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_hvm_altp2m_set_mem_access
block|{
comment|/* view */
name|uint16_t
name|view
decl_stmt|;
comment|/* Memory type */
name|uint16_t
name|hvmmem_access
decl_stmt|;
comment|/* xenmem_access_t */
name|uint32_t
name|pad
decl_stmt|;
comment|/* gfn */
name|uint64_t
name|gfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_altp2m_set_mem_access
name|xen_hvm_altp2m_set_mem_access_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_altp2m_set_mem_access_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_hvm_altp2m_change_gfn
block|{
comment|/* view */
name|uint16_t
name|view
decl_stmt|;
name|uint16_t
name|pad1
decl_stmt|;
name|uint32_t
name|pad2
decl_stmt|;
comment|/* old gfn */
name|uint64_t
name|old_gfn
decl_stmt|;
comment|/* new gfn, INVALID_GFN (~0UL) means revert */
name|uint64_t
name|new_gfn
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_hvm_altp2m_change_gfn
name|xen_hvm_altp2m_change_gfn_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_altp2m_change_gfn_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_hvm_altp2m_op
block|{
name|uint32_t
name|version
decl_stmt|;
comment|/* HVMOP_ALTP2M_INTERFACE_VERSION */
name|uint32_t
name|cmd
decl_stmt|;
comment|/* Get/set the altp2m state for a domain */
define|#
directive|define
name|HVMOP_altp2m_get_domain_state
value|1
define|#
directive|define
name|HVMOP_altp2m_set_domain_state
value|2
comment|/* Set the current VCPU to receive altp2m event notifications */
define|#
directive|define
name|HVMOP_altp2m_vcpu_enable_notify
value|3
comment|/* Create a new view */
define|#
directive|define
name|HVMOP_altp2m_create_p2m
value|4
comment|/* Destroy a view */
define|#
directive|define
name|HVMOP_altp2m_destroy_p2m
value|5
comment|/* Switch view for an entire domain */
define|#
directive|define
name|HVMOP_altp2m_switch_p2m
value|6
comment|/* Notify that a page of memory is to have specific access types */
define|#
directive|define
name|HVMOP_altp2m_set_mem_access
value|7
comment|/* Change a p2m entry to have a different gfn->mfn mapping */
define|#
directive|define
name|HVMOP_altp2m_change_gfn
value|8
name|domid_t
name|domain
decl_stmt|;
name|uint16_t
name|pad1
decl_stmt|;
name|uint32_t
name|pad2
decl_stmt|;
union|union
block|{
name|struct
name|xen_hvm_altp2m_domain_state
name|domain_state
decl_stmt|;
name|struct
name|xen_hvm_altp2m_vcpu_enable_notify
name|enable_notify
decl_stmt|;
name|struct
name|xen_hvm_altp2m_view
name|view
decl_stmt|;
name|struct
name|xen_hvm_altp2m_set_mem_access
name|set_mem_access
decl_stmt|;
name|struct
name|xen_hvm_altp2m_change_gfn
name|change_gfn
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|64
index|]
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
name|xen_hvm_altp2m_op
name|xen_hvm_altp2m_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_hvm_altp2m_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_HVM_OP_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

