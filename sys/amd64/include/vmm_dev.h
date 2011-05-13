begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD: vmm_dev.h 482 2011-05-09 21:22:43Z grehan $  */
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
name|void
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
name|hpa
decl_stmt|;
comment|/* out */
name|vm_paddr_t
name|gpa
decl_stmt|;
comment|/* in */
name|size_t
name|len
decl_stmt|;
comment|/* in */
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
name|vm_pin
block|{
name|int
name|vm_cpuid
decl_stmt|;
name|int
name|host_cpuid
decl_stmt|;
comment|/* -1 to unpin */
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
name|vm_event
block|{
name|int
name|cpuid
decl_stmt|;
name|enum
name|vm_event_type
name|type
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
name|int
name|vector
decl_stmt|;
name|int
name|destcpu
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

begin_enum
enum|enum
block|{
name|IOCNUM_RUN
block|,
name|IOCNUM_SET_PINNING
block|,
name|IOCNUM_GET_PINNING
block|,
name|IOCNUM_MAP_MEMORY
block|,
name|IOCNUM_GET_MEMORY_SEG
block|,
name|IOCNUM_SET_REGISTER
block|,
name|IOCNUM_GET_REGISTER
block|,
name|IOCNUM_SET_SEGMENT_DESCRIPTOR
block|,
name|IOCNUM_GET_SEGMENT_DESCRIPTOR
block|,
name|IOCNUM_INJECT_EVENT
block|,
name|IOCNUM_LAPIC_IRQ
block|,
name|IOCNUM_SET_CAPABILITY
block|,
name|IOCNUM_GET_CAPABILITY
block|,
name|IOCNUM_BIND_PPTDEV
block|,
name|IOCNUM_UNBIND_PPTDEV
block|,
name|IOCNUM_MAP_PPTDEV_MMIO
block|,
name|IOCNUM_PPTDEV_MSI
block|,
name|IOCNUM_INJECT_NMI
block|,
name|IOCNUM_VM_STATS
block|,
name|IOCNUM_VM_STAT_DESC
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
name|VM_SET_PINNING
define|\
value|_IOW('v', IOCNUM_SET_PINNING, struct vm_pin)
end_define

begin_define
define|#
directive|define
name|VM_GET_PINNING
define|\
value|_IOWR('v', IOCNUM_GET_PINNING, struct vm_pin)
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
name|VM_INJECT_EVENT
define|\
value|_IOW('v', IOCNUM_INJECT_EVENT, struct vm_event)
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

