begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xen-x86_32.h  *   * Guest OS interface to x86 32-bit Xen.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2004-2007, K A Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ARCH_X86_XEN_X86_32_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ARCH_X86_XEN_X86_32_H__
end_define

begin_comment
comment|/*  * Hypercall interface:  *  Input:  %ebx, %ecx, %edx, %esi, %edi, %ebp (arguments 1-6)  *  Output: %eax  * Access is via hypercall page (set up by guest loader or via a Xen MSR):  *  call hypercall_page + hypercall-number * 32  * Clobbered: Argument registers (e.g., 2-arg hypercall clobbers %ebx,%ecx)  */
end_comment

begin_comment
comment|/*  * These flat segments are in the Xen-private section of every GDT. Since these  * are also present in the initial GDT, many OSes will be able to avoid  * installing their own GDT.  */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING1_CS
value|0xe019
end_define

begin_comment
comment|/* GDT index 259 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING1_DS
value|0xe021
end_define

begin_comment
comment|/* GDT index 260 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING1_SS
value|0xe021
end_define

begin_comment
comment|/* GDT index 260 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_CS
value|0xe02b
end_define

begin_comment
comment|/* GDT index 261 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_DS
value|0xe033
end_define

begin_comment
comment|/* GDT index 262 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_SS
value|0xe033
end_define

begin_comment
comment|/* GDT index 262 */
end_comment

begin_define
define|#
directive|define
name|FLAT_KERNEL_CS
value|FLAT_RING1_CS
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_DS
value|FLAT_RING1_DS
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_SS
value|FLAT_RING1_SS
end_define

begin_define
define|#
directive|define
name|FLAT_USER_CS
value|FLAT_RING3_CS
end_define

begin_define
define|#
directive|define
name|FLAT_USER_DS
value|FLAT_RING3_DS
end_define

begin_define
define|#
directive|define
name|FLAT_USER_SS
value|FLAT_RING3_SS
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_VIRT_START_PAE
value|0xF5800000
end_define

begin_define
define|#
directive|define
name|__MACH2PHYS_VIRT_START_PAE
value|0xF5800000
end_define

begin_define
define|#
directive|define
name|__MACH2PHYS_VIRT_END_PAE
value|0xF6800000
end_define

begin_define
define|#
directive|define
name|HYPERVISOR_VIRT_START_PAE
define|\
value|mk_unsigned_long(__HYPERVISOR_VIRT_START_PAE)
end_define

begin_define
define|#
directive|define
name|MACH2PHYS_VIRT_START_PAE
define|\
value|mk_unsigned_long(__MACH2PHYS_VIRT_START_PAE)
end_define

begin_define
define|#
directive|define
name|MACH2PHYS_VIRT_END_PAE
define|\
value|mk_unsigned_long(__MACH2PHYS_VIRT_END_PAE)
end_define

begin_comment
comment|/* Non-PAE bounds are obsolete. */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_VIRT_START_NONPAE
value|0xFC000000
end_define

begin_define
define|#
directive|define
name|__MACH2PHYS_VIRT_START_NONPAE
value|0xFC000000
end_define

begin_define
define|#
directive|define
name|__MACH2PHYS_VIRT_END_NONPAE
value|0xFC400000
end_define

begin_define
define|#
directive|define
name|HYPERVISOR_VIRT_START_NONPAE
define|\
value|mk_unsigned_long(__HYPERVISOR_VIRT_START_NONPAE)
end_define

begin_define
define|#
directive|define
name|MACH2PHYS_VIRT_START_NONPAE
define|\
value|mk_unsigned_long(__MACH2PHYS_VIRT_START_NONPAE)
end_define

begin_define
define|#
directive|define
name|MACH2PHYS_VIRT_END_NONPAE
define|\
value|mk_unsigned_long(__MACH2PHYS_VIRT_END_NONPAE)
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_VIRT_START
value|__HYPERVISOR_VIRT_START_PAE
end_define

begin_define
define|#
directive|define
name|__MACH2PHYS_VIRT_START
value|__MACH2PHYS_VIRT_START_PAE
end_define

begin_define
define|#
directive|define
name|__MACH2PHYS_VIRT_END
value|__MACH2PHYS_VIRT_END_PAE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HYPERVISOR_VIRT_START
end_ifndef

begin_define
define|#
directive|define
name|HYPERVISOR_VIRT_START
value|mk_unsigned_long(__HYPERVISOR_VIRT_START)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MACH2PHYS_VIRT_START
value|mk_unsigned_long(__MACH2PHYS_VIRT_START)
end_define

begin_define
define|#
directive|define
name|MACH2PHYS_VIRT_END
value|mk_unsigned_long(__MACH2PHYS_VIRT_END)
end_define

begin_define
define|#
directive|define
name|MACH2PHYS_NR_ENTRIES
value|((MACH2PHYS_VIRT_END-MACH2PHYS_VIRT_START)>>2)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|machine_to_phys_mapping
end_ifndef

begin_define
define|#
directive|define
name|machine_to_phys_mapping
value|((unsigned long *)MACH2PHYS_VIRT_START)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 32-/64-bit invariability for control interfaces (domctl/sysctl). */
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

begin_undef
undef|#
directive|undef
name|___DEFINE_XEN_GUEST_HANDLE
end_undef

begin_define
define|#
directive|define
name|___DEFINE_XEN_GUEST_HANDLE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|typedef struct { type *p; }                                 \         __guest_handle_ ## name;                                \     typedef struct { union { type *p; uint64_aligned_t q; }; }  \         __guest_handle_64_ ## name
end_define

begin_undef
undef|#
directive|undef
name|set_xen_guest_handle_raw
end_undef

begin_define
define|#
directive|define
name|set_xen_guest_handle_raw
parameter_list|(
name|hnd
parameter_list|,
name|val
parameter_list|)
define|\
value|do { if ( sizeof(hnd) == 8 ) *(uint64_t *)&(hnd) = 0;   \          (hnd).p = val;                                     \     } while ( 0 )
end_define

begin_define
define|#
directive|define
name|uint64_aligned_t
value|uint64_t __attribute__((aligned(8)))
end_define

begin_define
define|#
directive|define
name|__XEN_GUEST_HANDLE_64
parameter_list|(
name|name
parameter_list|)
value|__guest_handle_64_ ## name
end_define

begin_define
define|#
directive|define
name|XEN_GUEST_HANDLE_64
parameter_list|(
name|name
parameter_list|)
value|__XEN_GUEST_HANDLE_64(name)
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
name|cpu_user_regs
block|{
name|uint32_t
name|ebx
decl_stmt|;
name|uint32_t
name|ecx
decl_stmt|;
name|uint32_t
name|edx
decl_stmt|;
name|uint32_t
name|esi
decl_stmt|;
name|uint32_t
name|edi
decl_stmt|;
name|uint32_t
name|ebp
decl_stmt|;
name|uint32_t
name|eax
decl_stmt|;
name|uint16_t
name|error_code
decl_stmt|;
comment|/* private */
name|uint16_t
name|entry_vector
decl_stmt|;
comment|/* private */
name|uint32_t
name|eip
decl_stmt|;
name|uint16_t
name|cs
decl_stmt|;
name|uint8_t
name|saved_upcall_mask
decl_stmt|;
name|uint8_t
name|_pad0
decl_stmt|;
name|uint32_t
name|eflags
decl_stmt|;
comment|/* eflags.IF == !saved_upcall_mask */
name|uint32_t
name|esp
decl_stmt|;
name|uint16_t
name|ss
decl_stmt|,
name|_pad1
decl_stmt|;
name|uint16_t
name|es
decl_stmt|,
name|_pad2
decl_stmt|;
name|uint16_t
name|ds
decl_stmt|,
name|_pad3
decl_stmt|;
name|uint16_t
name|fs
decl_stmt|,
name|_pad4
decl_stmt|;
name|uint16_t
name|gs
decl_stmt|,
name|_pad5
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cpu_user_regs
name|cpu_user_regs_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|cpu_user_regs_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Page-directory addresses above 4GB do not fit into architectural %cr3.  * When accessing %cr3, or equivalent field in vcpu_guest_context, guests  * must use the following accessor macros to pack/unpack valid MFNs.  */
end_comment

begin_define
define|#
directive|define
name|xen_pfn_to_cr3
parameter_list|(
name|pfn
parameter_list|)
value|(((unsigned)(pfn)<< 12) | ((unsigned)(pfn)>> 20))
end_define

begin_define
define|#
directive|define
name|xen_cr3_to_pfn
parameter_list|(
name|cr3
parameter_list|)
value|(((unsigned)(cr3)>> 12) | ((unsigned)(cr3)<< 20))
end_define

begin_struct
struct|struct
name|arch_vcpu_info
block|{
name|unsigned
name|long
name|cr2
decl_stmt|;
name|unsigned
name|long
name|pad
index|[
literal|5
index|]
decl_stmt|;
comment|/* sizeof(vcpu_info_t) == 64 */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arch_vcpu_info
name|arch_vcpu_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|xen_callback
block|{
name|unsigned
name|long
name|cs
decl_stmt|;
name|unsigned
name|long
name|eip
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_callback
name|xen_callback_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_ARCH_X86_XEN_X86_32_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

