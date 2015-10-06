begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * vm_event.h  *  * Memory event common structures.  *  * Copyright (c) 2009 by Citrix Systems, Inc. (Patrick Colp)  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_PUBLIC_VM_EVENT_H
end_ifndef

begin_define
define|#
directive|define
name|_XEN_PUBLIC_VM_EVENT_H
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_define
define|#
directive|define
name|VM_EVENT_INTERFACE_VERSION
value|0x00000001
end_define

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

begin_include
include|#
directive|include
file|"io/ring.h"
end_include

begin_comment
comment|/*  * Memory event flags  */
end_comment

begin_comment
comment|/*  * VCPU_PAUSED in a request signals that the vCPU triggering the event has been  *  paused  * VCPU_PAUSED in a response signals to unpause the vCPU  */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_FLAG_VCPU_PAUSED
value|(1<< 0)
end_define

begin_comment
comment|/* Flags to aid debugging vm_event */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_FLAG_FOREIGN
value|(1<< 1)
end_define

begin_comment
comment|/*  * The following flags can be set in response to a mem_access event.  *  * Emulate the fault-causing instruction (if set in the event response flags).  * This will allow the guest to continue execution without lifting the page  * access restrictions.  */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_FLAG_EMULATE
value|(1<< 2)
end_define

begin_comment
comment|/*  * Same as VM_EVENT_FLAG_EMULATE, but with write operations or operations  * potentially having side effects (like memory mapped or port I/O) disabled.  */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_FLAG_EMULATE_NOWRITE
value|(1<< 3)
end_define

begin_comment
comment|/*  * Toggle singlestepping on vm_event response.  * Requires the vCPU to be paused already (synchronous events only).  */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_FLAG_TOGGLE_SINGLESTEP
value|(1<< 4)
end_define

begin_comment
comment|/*  * Data is being sent back to the hypervisor in the event response, to be  * returned by the read function when emulating an instruction.  * This flag is only useful when combined with VM_EVENT_FLAG_EMULATE  * and takes precedence if combined with VM_EVENT_FLAG_EMULATE_NOWRITE  * (i.e. if both VM_EVENT_FLAG_EMULATE_NOWRITE and  * VM_EVENT_FLAG_SET_EMUL_READ_DATA are set, only the latter will be honored).  */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_FLAG_SET_EMUL_READ_DATA
value|(1<< 5)
end_define

begin_comment
comment|/*   * Deny completion of the operation that triggered the event.   * Currently only useful for MSR, CR0, CR3 and CR4 write events.   */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_FLAG_DENY
value|(1<< 6)
end_define

begin_comment
comment|/*  * This flag can be set in a request or a response  *  * On a request, indicates that the event occurred in the alternate p2m specified by  * the altp2m_idx request field.  *  * On a response, indicates that the VCPU should resume in the alternate p2m specified  * by the altp2m_idx response field if possible.  */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_FLAG_ALTERNATE_P2M
value|(1<< 7)
end_define

begin_comment
comment|/*  * Reasons for the vm event request  */
end_comment

begin_comment
comment|/* Default case */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_UNKNOWN
value|0
end_define

begin_comment
comment|/* Memory access violation */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_MEM_ACCESS
value|1
end_define

begin_comment
comment|/* Memory sharing event */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_MEM_SHARING
value|2
end_define

begin_comment
comment|/* Memory paging event */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_MEM_PAGING
value|3
end_define

begin_comment
comment|/* A control register was updated */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_WRITE_CTRLREG
value|4
end_define

begin_comment
comment|/* An MSR was updated. */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_MOV_TO_MSR
value|5
end_define

begin_comment
comment|/* Debug operation executed (e.g. int3) */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_SOFTWARE_BREAKPOINT
value|6
end_define

begin_comment
comment|/* Single-step (e.g. MTF) */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_SINGLESTEP
value|7
end_define

begin_comment
comment|/* An event has been requested via HVMOP_guest_request_vm_event. */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_REASON_GUEST_REQUEST
value|8
end_define

begin_comment
comment|/* Supported values for the vm_event_write_ctrlreg index. */
end_comment

begin_define
define|#
directive|define
name|VM_EVENT_X86_CR0
value|0
end_define

begin_define
define|#
directive|define
name|VM_EVENT_X86_CR3
value|1
end_define

begin_define
define|#
directive|define
name|VM_EVENT_X86_CR4
value|2
end_define

begin_define
define|#
directive|define
name|VM_EVENT_X86_XCR0
value|3
end_define

begin_comment
comment|/*  * Using a custom struct (not hvm_hw_cpu) so as to not fill  * the vm_event ring buffer too quickly.  */
end_comment

begin_struct
struct|struct
name|vm_event_regs_x86
block|{
name|uint64_t
name|rax
decl_stmt|;
name|uint64_t
name|rcx
decl_stmt|;
name|uint64_t
name|rdx
decl_stmt|;
name|uint64_t
name|rbx
decl_stmt|;
name|uint64_t
name|rsp
decl_stmt|;
name|uint64_t
name|rbp
decl_stmt|;
name|uint64_t
name|rsi
decl_stmt|;
name|uint64_t
name|rdi
decl_stmt|;
name|uint64_t
name|r8
decl_stmt|;
name|uint64_t
name|r9
decl_stmt|;
name|uint64_t
name|r10
decl_stmt|;
name|uint64_t
name|r11
decl_stmt|;
name|uint64_t
name|r12
decl_stmt|;
name|uint64_t
name|r13
decl_stmt|;
name|uint64_t
name|r14
decl_stmt|;
name|uint64_t
name|r15
decl_stmt|;
name|uint64_t
name|rflags
decl_stmt|;
name|uint64_t
name|dr7
decl_stmt|;
name|uint64_t
name|rip
decl_stmt|;
name|uint64_t
name|cr0
decl_stmt|;
name|uint64_t
name|cr2
decl_stmt|;
name|uint64_t
name|cr3
decl_stmt|;
name|uint64_t
name|cr4
decl_stmt|;
name|uint64_t
name|sysenter_cs
decl_stmt|;
name|uint64_t
name|sysenter_esp
decl_stmt|;
name|uint64_t
name|sysenter_eip
decl_stmt|;
name|uint64_t
name|msr_efer
decl_stmt|;
name|uint64_t
name|msr_star
decl_stmt|;
name|uint64_t
name|msr_lstar
decl_stmt|;
name|uint64_t
name|fs_base
decl_stmt|;
name|uint64_t
name|gs_base
decl_stmt|;
name|uint32_t
name|cs_arbytes
decl_stmt|;
name|uint32_t
name|_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * mem_access flag definitions  *  * These flags are set only as part of a mem_event request.  *  * R/W/X: Defines the type of violation that has triggered the event  *        Multiple types can be set in a single violation!  * GLA_VALID: If the gla field holds a guest VA associated with the event  * FAULT_WITH_GLA: If the violation was triggered by accessing gla  * FAULT_IN_GPT: If the violation was triggered during translating gla  */
end_comment

begin_define
define|#
directive|define
name|MEM_ACCESS_R
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_W
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_X
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_RWX
value|(MEM_ACCESS_R | MEM_ACCESS_W | MEM_ACCESS_X)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_RW
value|(MEM_ACCESS_R | MEM_ACCESS_W)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_RX
value|(MEM_ACCESS_R | MEM_ACCESS_X)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_WX
value|(MEM_ACCESS_W | MEM_ACCESS_X)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_GLA_VALID
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_FAULT_WITH_GLA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MEM_ACCESS_FAULT_IN_GPT
value|(1<< 5)
end_define

begin_struct
struct|struct
name|vm_event_mem_access
block|{
name|uint64_t
name|gfn
decl_stmt|;
name|uint64_t
name|offset
decl_stmt|;
name|uint64_t
name|gla
decl_stmt|;
comment|/* if flags has MEM_ACCESS_GLA_VALID set */
name|uint32_t
name|flags
decl_stmt|;
comment|/* MEM_ACCESS_* */
name|uint32_t
name|_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_event_write_ctrlreg
block|{
name|uint32_t
name|index
decl_stmt|;
name|uint32_t
name|_pad
decl_stmt|;
name|uint64_t
name|new_value
decl_stmt|;
name|uint64_t
name|old_value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_event_debug
block|{
name|uint64_t
name|gfn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_event_mov_to_msr
block|{
name|uint64_t
name|msr
decl_stmt|;
name|uint64_t
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MEM_PAGING_DROP_PAGE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MEM_PAGING_EVICT_FAIL
value|(1<< 1)
end_define

begin_struct
struct|struct
name|vm_event_paging
block|{
name|uint64_t
name|gfn
decl_stmt|;
name|uint32_t
name|p2mt
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_event_sharing
block|{
name|uint64_t
name|gfn
decl_stmt|;
name|uint32_t
name|p2mt
decl_stmt|;
name|uint32_t
name|_pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_event_emul_read_data
block|{
name|uint32_t
name|size
decl_stmt|;
comment|/* The struct is used in a union with vm_event_regs_x86. */
name|uint8_t
name|data
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|vm_event_regs_x86
argument_list|)
operator|-
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
struct|struct
name|vm_event_st
block|{
name|uint32_t
name|version
decl_stmt|;
comment|/* VM_EVENT_INTERFACE_VERSION */
name|uint32_t
name|flags
decl_stmt|;
comment|/* VM_EVENT_FLAG_* */
name|uint32_t
name|reason
decl_stmt|;
comment|/* VM_EVENT_REASON_* */
name|uint32_t
name|vcpu_id
decl_stmt|;
name|uint16_t
name|altp2m_idx
decl_stmt|;
comment|/* may be used during request and response */
name|uint16_t
name|_pad
index|[
literal|3
index|]
decl_stmt|;
union|union
block|{
name|struct
name|vm_event_paging
name|mem_paging
decl_stmt|;
name|struct
name|vm_event_sharing
name|mem_sharing
decl_stmt|;
name|struct
name|vm_event_mem_access
name|mem_access
decl_stmt|;
name|struct
name|vm_event_write_ctrlreg
name|write_ctrlreg
decl_stmt|;
name|struct
name|vm_event_mov_to_msr
name|mov_to_msr
decl_stmt|;
name|struct
name|vm_event_debug
name|software_breakpoint
decl_stmt|;
name|struct
name|vm_event_debug
name|singlestep
decl_stmt|;
block|}
name|u
union|;
union|union
block|{
union|union
block|{
name|struct
name|vm_event_regs_x86
name|x86
decl_stmt|;
block|}
name|regs
union|;
name|struct
name|vm_event_emul_read_data
name|emul_read_data
decl_stmt|;
block|}
name|data
union|;
block|}
name|vm_event_request_t
operator|,
name|vm_event_response_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|vm_event
argument_list|,
name|vm_event_request_t
argument_list|,
name|vm_event_response_t
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
comment|/* _XEN_PUBLIC_VM_EVENT_H */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

