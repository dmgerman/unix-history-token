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

begin_enum
enum|enum
name|vie_cpu_mode
block|{
name|CPU_MODE_COMPATIBILITY
block|,
comment|/* IA-32E mode (CS.L = 0) */
name|CPU_MODE_64BIT
block|,
comment|/* IA-32E mode (CS.L = 1) */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|vie_paging_mode
block|{
name|PAGING_MODE_FLAT
block|,
name|PAGING_MODE_32
block|,
name|PAGING_MODE_PAE
block|,
name|PAGING_MODE_64
block|, }
enum|;
end_enum

begin_comment
comment|/*  * The data structures 'vie' and 'vie_op' are meant to be opaque to the  * consumers of instruction decoding. The only reason why their contents  * need to be exposed is because they are part of the 'vm_exit' structure.  */
end_comment

begin_struct
struct|struct
name|vie_op
block|{
name|uint8_t
name|op_byte
decl_stmt|;
comment|/* actual opcode byte */
name|uint8_t
name|op_type
decl_stmt|;
comment|/* type of operation (e.g. MOV) */
name|uint16_t
name|op_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIE_INST_SIZE
value|15
end_define

begin_struct
struct|struct
name|vie
block|{
name|uint8_t
name|inst
index|[
name|VIE_INST_SIZE
index|]
decl_stmt|;
comment|/* instruction bytes */
name|uint8_t
name|num_valid
decl_stmt|;
comment|/* size of the instruction */
name|uint8_t
name|num_processed
decl_stmt|;
name|uint8_t
name|rex_w
range|:
literal|1
decl_stmt|,
comment|/* REX prefix */
name|rex_r
range|:
literal|1
decl_stmt|,
name|rex_x
range|:
literal|1
decl_stmt|,
name|rex_b
range|:
literal|1
decl_stmt|,
name|rex_present
range|:
literal|1
decl_stmt|;
name|uint8_t
name|mod
range|:
literal|2
decl_stmt|,
comment|/* ModRM byte */
name|reg
range|:
literal|4
decl_stmt|,
name|rm
range|:
literal|4
decl_stmt|;
name|uint8_t
name|ss
range|:
literal|2
decl_stmt|,
comment|/* SIB byte */
name|index
range|:
literal|4
decl_stmt|,
name|base
range|:
literal|4
decl_stmt|;
name|uint8_t
name|disp_bytes
decl_stmt|;
name|uint8_t
name|imm_bytes
decl_stmt|;
name|uint8_t
name|scale
decl_stmt|;
name|int
name|base_register
decl_stmt|;
comment|/* VM_REG_GUEST_xyz */
name|int
name|index_register
decl_stmt|;
comment|/* VM_REG_GUEST_xyz */
name|int64_t
name|displacement
decl_stmt|;
comment|/* optional addr displacement */
name|int64_t
name|immediate
decl_stmt|;
comment|/* optional immediate operand */
name|uint8_t
name|decoded
decl_stmt|;
comment|/* set to 1 if successfully decoded */
name|struct
name|vie_op
name|op
decl_stmt|;
comment|/* opcode description */
block|}
struct|;
end_struct

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
name|uint64_t
name|rip
parameter_list|,
name|int
name|inst_length
parameter_list|,
name|uint64_t
name|cr3
parameter_list|,
name|enum
name|vie_paging_mode
name|paging_mode
parameter_list|,
name|int
name|cpl
parameter_list|,
name|struct
name|vie
modifier|*
name|vie
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Translate the guest linear address 'gla' to a guest physical address.  *  * Returns 0 on success and '*gpa' contains the result of the translation.  * Returns 1 if a page fault exception was injected into the guest.  * Returns -1 otherwise.  */
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
name|uint64_t
name|gla
parameter_list|,
name|uint64_t
name|cr3
parameter_list|,
name|uint64_t
modifier|*
name|gpa
parameter_list|,
name|enum
name|vie_paging_mode
name|paging_mode
parameter_list|,
name|int
name|cpl
parameter_list|,
name|int
name|prot
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
name|vie_cpu_mode
name|cpu_mode
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

