begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMM_INSTRUCTION_EMUL_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMM_INSTRUCTION_EMUL_H_
end_define

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_comment
comment|/*  * Callback functions to read and write memory regions.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|mem_region_read_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|uint64_t
name|gpa
parameter_list|,
name|uint64_t
modifier|*
name|rval
parameter_list|,
name|int
name|rsize
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|mem_region_write_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|uint64_t
name|gpa
parameter_list|,
name|uint64_t
name|wval
parameter_list|,
name|int
name|wsize
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Emulate the decoded 'vie' instruction.  *  * The callbacks 'mrr' and 'mrw' emulate reads and writes to the memory region  * containing 'gpa'. 'mrarg' is an opaque argument that is passed into the  * callback functions.  *  * 'void *vm' should be 'struct vm *' when called from kernel context and  * 'struct vmctx *' when called from user context.  * s  */
end_comment

begin_function_decl
name|int
name|vmm_emulate_instruction
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|uint64_t
name|gpa
parameter_list|,
name|struct
name|vie
modifier|*
name|vie
parameter_list|,
name|struct
name|vm_guest_paging
modifier|*
name|paging
parameter_list|,
name|mem_region_read_t
name|mrr
parameter_list|,
name|mem_region_write_t
name|mrw
parameter_list|,
name|void
modifier|*
name|mrarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vie_update_register
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|enum
name|vm_reg_name
name|reg
parameter_list|,
name|uint64_t
name|val
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns 1 if an alignment check exception should be injected and 0 otherwise.  */
end_comment

begin_function_decl
name|int
name|vie_alignment_check
parameter_list|(
name|int
name|cpl
parameter_list|,
name|int
name|operand_size
parameter_list|,
name|uint64_t
name|cr0
parameter_list|,
name|uint64_t
name|rflags
parameter_list|,
name|uint64_t
name|gla
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns 1 if the 'gla' is not canonical and 0 otherwise. */
end_comment

begin_function_decl
name|int
name|vie_canonical_check
parameter_list|(
name|enum
name|vm_cpu_mode
name|cpu_mode
parameter_list|,
name|uint64_t
name|gla
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vie_size2mask
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vie_calculate_gla
parameter_list|(
name|enum
name|vm_cpu_mode
name|cpu_mode
parameter_list|,
name|enum
name|vm_reg_name
name|seg
parameter_list|,
name|struct
name|seg_desc
modifier|*
name|desc
parameter_list|,
name|uint64_t
name|off
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|addrsize
parameter_list|,
name|int
name|prot
parameter_list|,
name|uint64_t
modifier|*
name|gla
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * APIs to fetch and decode the instruction from nested page fault handler.  *  * 'vie' must be initialized before calling 'vmm_fetch_instruction()'  */
end_comment

begin_function_decl
name|int
name|vmm_fetch_instruction
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|struct
name|vm_guest_paging
modifier|*
name|guest_paging
parameter_list|,
name|uint64_t
name|rip
parameter_list|,
name|int
name|inst_length
parameter_list|,
name|struct
name|vie
modifier|*
name|vie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Translate the guest linear address 'gla' to a guest physical address.  *  * Returns 0 on success and '*gpa' contains the result of the translation.  * Returns 1 if an exception was injected into the guest.  * Returns -1 otherwise.  */
end_comment

begin_function_decl
name|int
name|vmm_gla2gpa
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|struct
name|vm_guest_paging
modifier|*
name|paging
parameter_list|,
name|uint64_t
name|gla
parameter_list|,
name|int
name|prot
parameter_list|,
name|uint64_t
modifier|*
name|gpa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vie_init
parameter_list|(
name|struct
name|vie
modifier|*
name|vie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decode the instruction fetched into 'vie' so it can be emulated.  *  * 'gla' is the guest linear address provided by the hardware assist  * that caused the nested page table fault. It is used to verify that  * the software instruction decoding is in agreement with the hardware.  *   * Some hardware assists do not provide the 'gla' to the hypervisor.  * To skip the 'gla' verification for this or any other reason pass  * in VIE_INVALID_GLA instead.  */
end_comment

begin_define
define|#
directive|define
name|VIE_INVALID_GLA
value|(1UL<< 63)
end_define

begin_comment
comment|/* a non-canonical address */
end_comment

begin_function_decl
name|int
name|vmm_decode_instruction
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|uint64_t
name|gla
parameter_list|,
name|enum
name|vm_cpu_mode
name|cpu_mode
parameter_list|,
name|int
name|csd
parameter_list|,
name|struct
name|vie
modifier|*
name|vie
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VMM_INSTRUCTION_EMUL_H_ */
end_comment

end_unit

