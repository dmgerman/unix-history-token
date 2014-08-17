begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMM_DEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMM_DEV_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|vmmdev_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmmdev_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vm_memory_segment
block|{
name|vm_paddr_t
name|gpa
decl_stmt|;
comment|/* in */
name|size_t
name|len
decl_stmt|;
name|int
name|wired
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_register
block|{
name|int
name|cpuid
decl_stmt|;
name|int
name|regnum
decl_stmt|;
comment|/* enum vm_reg_name */
name|uint64_t
name|regval
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_seg_desc
block|{
comment|/* data or code segment */
name|int
name|cpuid
decl_stmt|;
name|int
name|regnum
decl_stmt|;
comment|/* enum vm_reg_name */
name|struct
name|seg_desc
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_run
block|{
name|int
name|cpuid
decl_stmt|;
name|uint64_t
name|rip
decl_stmt|;
comment|/* start running here */
name|struct
name|vm_exit
name|vm_exit
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_exception
block|{
name|int
name|cpuid
decl_stmt|;
name|int
name|vector
decl_stmt|;
name|uint32_t
name|error_code
decl_stmt|;
name|int
name|error_code_valid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_lapic_msi
block|{
name|uint64_t
name|msg
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_lapic_irq
block|{
name|int
name|cpuid
decl_stmt|;
name|int
name|vector
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_ioapic_irq
block|{
name|int
name|irq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_isa_irq
block|{
name|int
name|atpic_irq
decl_stmt|;
name|int
name|ioapic_irq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_isa_irq_trigger
block|{
name|int
name|atpic_irq
decl_stmt|;
name|enum
name|vm_intr_trigger
name|trigger
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_capability
block|{
name|int
name|cpuid
decl_stmt|;
name|enum
name|vm_cap_type
name|captype
decl_stmt|;
name|int
name|capval
decl_stmt|;
name|int
name|allcpus
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_pptdev
block|{
name|int
name|bus
decl_stmt|;
name|int
name|slot
decl_stmt|;
name|int
name|func
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_pptdev_mmio
block|{
name|int
name|bus
decl_stmt|;
name|int
name|slot
decl_stmt|;
name|int
name|func
decl_stmt|;
name|vm_paddr_t
name|gpa
decl_stmt|;
name|vm_paddr_t
name|hpa
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_pptdev_msi
block|{
name|int
name|vcpu
decl_stmt|;
name|int
name|bus
decl_stmt|;
name|int
name|slot
decl_stmt|;
name|int
name|func
decl_stmt|;
name|int
name|numvec
decl_stmt|;
comment|/* 0 means disabled */
name|uint64_t
name|msg
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_pptdev_msix
block|{
name|int
name|vcpu
decl_stmt|;
name|int
name|bus
decl_stmt|;
name|int
name|slot
decl_stmt|;
name|int
name|func
decl_stmt|;
name|int
name|idx
decl_stmt|;
name|uint64_t
name|msg
decl_stmt|;
name|uint32_t
name|vector_control
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_nmi
block|{
name|int
name|cpuid
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_VM_STATS
value|64
end_define

begin_struct
struct|struct
name|vm_stats
block|{
name|int
name|cpuid
decl_stmt|;
comment|/* in */
name|int
name|num_entries
decl_stmt|;
comment|/* out */
name|struct
name|timeval
name|tv
decl_stmt|;
name|uint64_t
name|statbuf
index|[
name|MAX_VM_STATS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_stat_desc
block|{
name|int
name|index
decl_stmt|;
comment|/* in */
name|char
name|desc
index|[
literal|128
index|]
decl_stmt|;
comment|/* out */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_x2apic
block|{
name|int
name|cpuid
decl_stmt|;
name|enum
name|x2apic_state
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_gpa_pte
block|{
name|uint64_t
name|gpa
decl_stmt|;
comment|/* in */
name|uint64_t
name|pte
index|[
literal|4
index|]
decl_stmt|;
comment|/* out */
name|int
name|ptenum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_hpet_cap
block|{
name|uint32_t
name|capabilities
decl_stmt|;
comment|/* lower 32 bits of HPET capabilities */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_suspend
block|{
name|enum
name|vm_suspend_how
name|how
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_gla2gpa
block|{
name|int
name|vcpuid
decl_stmt|;
comment|/* inputs */
name|int
name|prot
decl_stmt|;
comment|/* PROT_READ or PROT_WRITE */
name|uint64_t
name|gla
decl_stmt|;
name|struct
name|vm_guest_paging
name|paging
decl_stmt|;
name|int
name|fault
decl_stmt|;
comment|/* outputs */
name|uint64_t
name|gpa
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_activate_cpu
block|{
name|int
name|vcpuid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vm_cpuset
block|{
name|int
name|which
decl_stmt|;
name|int
name|cpusetsize
decl_stmt|;
name|cpuset_t
modifier|*
name|cpus
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VM_ACTIVE_CPUS
value|0
end_define

begin_define
define|#
directive|define
name|VM_SUSPENDED_CPUS
value|1
end_define

begin_enum
enum|enum
block|{
comment|/* general routines */
name|IOCNUM_ABIVERS
init|=
literal|0
block|,
name|IOCNUM_RUN
init|=
literal|1
block|,
name|IOCNUM_SET_CAPABILITY
init|=
literal|2
block|,
name|IOCNUM_GET_CAPABILITY
init|=
literal|3
block|,
name|IOCNUM_SUSPEND
init|=
literal|4
block|,
name|IOCNUM_REINIT
init|=
literal|5
block|,
comment|/* memory apis */
name|IOCNUM_MAP_MEMORY
init|=
literal|10
block|,
name|IOCNUM_GET_MEMORY_SEG
init|=
literal|11
block|,
name|IOCNUM_GET_GPA_PMAP
init|=
literal|12
block|,
name|IOCNUM_GLA2GPA
init|=
literal|13
block|,
comment|/* register/state accessors */
name|IOCNUM_SET_REGISTER
init|=
literal|20
block|,
name|IOCNUM_GET_REGISTER
init|=
literal|21
block|,
name|IOCNUM_SET_SEGMENT_DESCRIPTOR
init|=
literal|22
block|,
name|IOCNUM_GET_SEGMENT_DESCRIPTOR
init|=
literal|23
block|,
comment|/* interrupt injection */
name|IOCNUM_INJECT_EXCEPTION
init|=
literal|30
block|,
name|IOCNUM_LAPIC_IRQ
init|=
literal|31
block|,
name|IOCNUM_INJECT_NMI
init|=
literal|32
block|,
name|IOCNUM_IOAPIC_ASSERT_IRQ
init|=
literal|33
block|,
name|IOCNUM_IOAPIC_DEASSERT_IRQ
init|=
literal|34
block|,
name|IOCNUM_IOAPIC_PULSE_IRQ
init|=
literal|35
block|,
name|IOCNUM_LAPIC_MSI
init|=
literal|36
block|,
name|IOCNUM_LAPIC_LOCAL_IRQ
init|=
literal|37
block|,
name|IOCNUM_IOAPIC_PINCOUNT
init|=
literal|38
block|,
comment|/* PCI pass-thru */
name|IOCNUM_BIND_PPTDEV
init|=
literal|40
block|,
name|IOCNUM_UNBIND_PPTDEV
init|=
literal|41
block|,
name|IOCNUM_MAP_PPTDEV_MMIO
init|=
literal|42
block|,
name|IOCNUM_PPTDEV_MSI
init|=
literal|43
block|,
name|IOCNUM_PPTDEV_MSIX
init|=
literal|44
block|,
comment|/* statistics */
name|IOCNUM_VM_STATS
init|=
literal|50
block|,
name|IOCNUM_VM_STAT_DESC
init|=
literal|51
block|,
comment|/* kernel device state */
name|IOCNUM_SET_X2APIC_STATE
init|=
literal|60
block|,
name|IOCNUM_GET_X2APIC_STATE
init|=
literal|61
block|,
name|IOCNUM_GET_HPET_CAPABILITIES
init|=
literal|62
block|,
comment|/* legacy interrupt injection */
name|IOCNUM_ISA_ASSERT_IRQ
init|=
literal|80
block|,
name|IOCNUM_ISA_DEASSERT_IRQ
init|=
literal|81
block|,
name|IOCNUM_ISA_PULSE_IRQ
init|=
literal|82
block|,
name|IOCNUM_ISA_SET_IRQ_TRIGGER
init|=
literal|83
block|,
comment|/* vm_cpuset */
name|IOCNUM_ACTIVATE_CPU
init|=
literal|90
block|,
name|IOCNUM_GET_CPUSET
init|=
literal|91
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|VM_RUN
define|\
value|_IOWR('v', IOCNUM_RUN, struct vm_run)
end_define

begin_define
define|#
directive|define
name|VM_SUSPEND
define|\
value|_IOW('v', IOCNUM_SUSPEND, struct vm_suspend)
end_define

begin_define
define|#
directive|define
name|VM_REINIT
define|\
value|_IO('v', IOCNUM_REINIT)
end_define

begin_define
define|#
directive|define
name|VM_MAP_MEMORY
define|\
value|_IOWR('v', IOCNUM_MAP_MEMORY, struct vm_memory_segment)
end_define

begin_define
define|#
directive|define
name|VM_GET_MEMORY_SEG
define|\
value|_IOWR('v', IOCNUM_GET_MEMORY_SEG, struct vm_memory_segment)
end_define

begin_define
define|#
directive|define
name|VM_SET_REGISTER
define|\
value|_IOW('v', IOCNUM_SET_REGISTER, struct vm_register)
end_define

begin_define
define|#
directive|define
name|VM_GET_REGISTER
define|\
value|_IOWR('v', IOCNUM_GET_REGISTER, struct vm_register)
end_define

begin_define
define|#
directive|define
name|VM_SET_SEGMENT_DESCRIPTOR
define|\
value|_IOW('v', IOCNUM_SET_SEGMENT_DESCRIPTOR, struct vm_seg_desc)
end_define

begin_define
define|#
directive|define
name|VM_GET_SEGMENT_DESCRIPTOR
define|\
value|_IOWR('v', IOCNUM_GET_SEGMENT_DESCRIPTOR, struct vm_seg_desc)
end_define

begin_define
define|#
directive|define
name|VM_INJECT_EXCEPTION
define|\
value|_IOW('v', IOCNUM_INJECT_EXCEPTION, struct vm_exception)
end_define

begin_define
define|#
directive|define
name|VM_LAPIC_IRQ
define|\
value|_IOW('v', IOCNUM_LAPIC_IRQ, struct vm_lapic_irq)
end_define

begin_define
define|#
directive|define
name|VM_LAPIC_LOCAL_IRQ
define|\
value|_IOW('v', IOCNUM_LAPIC_LOCAL_IRQ, struct vm_lapic_irq)
end_define

begin_define
define|#
directive|define
name|VM_LAPIC_MSI
define|\
value|_IOW('v', IOCNUM_LAPIC_MSI, struct vm_lapic_msi)
end_define

begin_define
define|#
directive|define
name|VM_IOAPIC_ASSERT_IRQ
define|\
value|_IOW('v', IOCNUM_IOAPIC_ASSERT_IRQ, struct vm_ioapic_irq)
end_define

begin_define
define|#
directive|define
name|VM_IOAPIC_DEASSERT_IRQ
define|\
value|_IOW('v', IOCNUM_IOAPIC_DEASSERT_IRQ, struct vm_ioapic_irq)
end_define

begin_define
define|#
directive|define
name|VM_IOAPIC_PULSE_IRQ
define|\
value|_IOW('v', IOCNUM_IOAPIC_PULSE_IRQ, struct vm_ioapic_irq)
end_define

begin_define
define|#
directive|define
name|VM_IOAPIC_PINCOUNT
define|\
value|_IOR('v', IOCNUM_IOAPIC_PINCOUNT, int)
end_define

begin_define
define|#
directive|define
name|VM_ISA_ASSERT_IRQ
define|\
value|_IOW('v', IOCNUM_ISA_ASSERT_IRQ, struct vm_isa_irq)
end_define

begin_define
define|#
directive|define
name|VM_ISA_DEASSERT_IRQ
define|\
value|_IOW('v', IOCNUM_ISA_DEASSERT_IRQ, struct vm_isa_irq)
end_define

begin_define
define|#
directive|define
name|VM_ISA_PULSE_IRQ
define|\
value|_IOW('v', IOCNUM_ISA_PULSE_IRQ, struct vm_isa_irq)
end_define

begin_define
define|#
directive|define
name|VM_ISA_SET_IRQ_TRIGGER
define|\
value|_IOW('v', IOCNUM_ISA_SET_IRQ_TRIGGER, struct vm_isa_irq_trigger)
end_define

begin_define
define|#
directive|define
name|VM_SET_CAPABILITY
define|\
value|_IOW('v', IOCNUM_SET_CAPABILITY, struct vm_capability)
end_define

begin_define
define|#
directive|define
name|VM_GET_CAPABILITY
define|\
value|_IOWR('v', IOCNUM_GET_CAPABILITY, struct vm_capability)
end_define

begin_define
define|#
directive|define
name|VM_BIND_PPTDEV
define|\
value|_IOW('v', IOCNUM_BIND_PPTDEV, struct vm_pptdev)
end_define

begin_define
define|#
directive|define
name|VM_UNBIND_PPTDEV
define|\
value|_IOW('v', IOCNUM_UNBIND_PPTDEV, struct vm_pptdev)
end_define

begin_define
define|#
directive|define
name|VM_MAP_PPTDEV_MMIO
define|\
value|_IOW('v', IOCNUM_MAP_PPTDEV_MMIO, struct vm_pptdev_mmio)
end_define

begin_define
define|#
directive|define
name|VM_PPTDEV_MSI
define|\
value|_IOW('v', IOCNUM_PPTDEV_MSI, struct vm_pptdev_msi)
end_define

begin_define
define|#
directive|define
name|VM_PPTDEV_MSIX
define|\
value|_IOW('v', IOCNUM_PPTDEV_MSIX, struct vm_pptdev_msix)
end_define

begin_define
define|#
directive|define
name|VM_INJECT_NMI
define|\
value|_IOW('v', IOCNUM_INJECT_NMI, struct vm_nmi)
end_define

begin_define
define|#
directive|define
name|VM_STATS
define|\
value|_IOWR('v', IOCNUM_VM_STATS, struct vm_stats)
end_define

begin_define
define|#
directive|define
name|VM_STAT_DESC
define|\
value|_IOWR('v', IOCNUM_VM_STAT_DESC, struct vm_stat_desc)
end_define

begin_define
define|#
directive|define
name|VM_SET_X2APIC_STATE
define|\
value|_IOW('v', IOCNUM_SET_X2APIC_STATE, struct vm_x2apic)
end_define

begin_define
define|#
directive|define
name|VM_GET_X2APIC_STATE
define|\
value|_IOWR('v', IOCNUM_GET_X2APIC_STATE, struct vm_x2apic)
end_define

begin_define
define|#
directive|define
name|VM_GET_HPET_CAPABILITIES
define|\
value|_IOR('v', IOCNUM_GET_HPET_CAPABILITIES, struct vm_hpet_cap)
end_define

begin_define
define|#
directive|define
name|VM_GET_GPA_PMAP
define|\
value|_IOWR('v', IOCNUM_GET_GPA_PMAP, struct vm_gpa_pte)
end_define

begin_define
define|#
directive|define
name|VM_GLA2GPA
define|\
value|_IOWR('v', IOCNUM_GLA2GPA, struct vm_gla2gpa)
end_define

begin_define
define|#
directive|define
name|VM_ACTIVATE_CPU
define|\
value|_IOW('v', IOCNUM_ACTIVATE_CPU, struct vm_activate_cpu)
end_define

begin_define
define|#
directive|define
name|VM_GET_CPUS
define|\
value|_IOW('v', IOCNUM_GET_CPUSET, struct vm_cpuset)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

