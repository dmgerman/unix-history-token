begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmm.h>
end_include

begin_include
include|#
directive|include
file|"vmm_lapic.h"
end_include

begin_include
include|#
directive|include
file|"vmm_msr.h"
end_include

begin_define
define|#
directive|define
name|VMM_MSR_F_EMULATE
value|0x01
end_define

begin_define
define|#
directive|define
name|VMM_MSR_F_READONLY
value|0x02
end_define

begin_define
define|#
directive|define
name|VMM_MSR_F_INVALID
value|0x04
end_define

begin_comment
comment|/* guest_msr_valid() can override this */
end_comment

begin_struct
struct|struct
name|vmm_msr
block|{
name|int
name|num
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|uint64_t
name|hostval
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|vmm_msr
name|vmm_msr
index|[]
init|=
block|{
block|{
name|MSR_LSTAR
block|,
literal|0
block|}
block|,
block|{
name|MSR_CSTAR
block|,
literal|0
block|}
block|,
block|{
name|MSR_STAR
block|,
literal|0
block|}
block|,
block|{
name|MSR_SF_MASK
block|,
literal|0
block|}
block|,
block|{
name|MSR_PAT
block|,
name|VMM_MSR_F_EMULATE
operator||
name|VMM_MSR_F_INVALID
block|}
block|,
block|{
name|MSR_BIOS_SIGN
block|,
name|VMM_MSR_F_EMULATE
block|}
block|,
block|{
name|MSR_MCG_CAP
block|,
name|VMM_MSR_F_EMULATE
operator||
name|VMM_MSR_F_READONLY
block|}
block|,
block|{
name|MSR_IA32_PLATFORM_ID
block|,
name|VMM_MSR_F_EMULATE
operator||
name|VMM_MSR_F_READONLY
block|}
block|,
block|{
name|MSR_IA32_MISC_ENABLE
block|,
name|VMM_MSR_F_EMULATE
operator||
name|VMM_MSR_F_READONLY
block|}
block|,
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vmm_msr_num
value|(sizeof(vmm_msr) / sizeof(vmm_msr[0]))
end_define

begin_expr_stmt
name|CTASSERT
argument_list|(
name|VMM_MSR_NUM
operator|>=
name|vmm_msr_num
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|readonly_msr
parameter_list|(
name|idx
parameter_list|)
define|\
value|((vmm_msr[(idx)].flags& VMM_MSR_F_READONLY) != 0)
end_define

begin_define
define|#
directive|define
name|emulated_msr
parameter_list|(
name|idx
parameter_list|)
define|\
value|((vmm_msr[(idx)].flags& VMM_MSR_F_EMULATE) != 0)
end_define

begin_define
define|#
directive|define
name|invalid_msr
parameter_list|(
name|idx
parameter_list|)
define|\
value|((vmm_msr[(idx)].flags& VMM_MSR_F_INVALID) != 0)
end_define

begin_function
name|void
name|vmm_msr_init
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|vmm_msr_num
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|emulated_msr
argument_list|(
name|i
argument_list|)
condition|)
continue|continue;
comment|/* 		 * XXX this assumes that the value of the host msr does not 		 * change after we have cached it. 		 */
name|vmm_msr
index|[
name|i
index|]
operator|.
name|hostval
operator|=
name|rdmsr
argument_list|(
name|vmm_msr
index|[
name|i
index|]
operator|.
name|num
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|guest_msrs_init
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|cpu
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
if|#
directive|if
literal|0
block|uint64_t *guest_msrs, misc;
else|#
directive|else
name|uint64_t
modifier|*
name|guest_msrs
decl_stmt|;
endif|#
directive|endif
name|guest_msrs
operator|=
name|vm_guest_msrs
argument_list|(
name|vm
argument_list|,
name|cpu
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|vmm_msr_num
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|vmm_msr
index|[
name|i
index|]
operator|.
name|num
condition|)
block|{
case|case
name|MSR_LSTAR
case|:
case|case
name|MSR_CSTAR
case|:
case|case
name|MSR_STAR
case|:
case|case
name|MSR_SF_MASK
case|:
case|case
name|MSR_BIOS_SIGN
case|:
case|case
name|MSR_MCG_CAP
case|:
name|guest_msrs
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|MSR_PAT
case|:
name|guest_msrs
index|[
name|i
index|]
operator|=
name|PAT_VALUE
argument_list|(
literal|0
argument_list|,
name|PAT_WRITE_BACK
argument_list|)
operator||
name|PAT_VALUE
argument_list|(
literal|1
argument_list|,
name|PAT_WRITE_THROUGH
argument_list|)
operator||
name|PAT_VALUE
argument_list|(
literal|2
argument_list|,
name|PAT_UNCACHED
argument_list|)
operator||
name|PAT_VALUE
argument_list|(
literal|3
argument_list|,
name|PAT_UNCACHEABLE
argument_list|)
operator||
name|PAT_VALUE
argument_list|(
literal|4
argument_list|,
name|PAT_WRITE_BACK
argument_list|)
operator||
name|PAT_VALUE
argument_list|(
literal|5
argument_list|,
name|PAT_WRITE_THROUGH
argument_list|)
operator||
name|PAT_VALUE
argument_list|(
literal|6
argument_list|,
name|PAT_UNCACHED
argument_list|)
operator||
name|PAT_VALUE
argument_list|(
literal|7
argument_list|,
name|PAT_UNCACHEABLE
argument_list|)
expr_stmt|;
break|break;
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX unsupported on AMD */
end_comment

begin_comment
unit|case MSR_IA32_MISC_ENABLE: 			misc = rdmsr(MSR_IA32_MISC_ENABLE);
comment|/* 			 * Set mandatory bits 			 *  11:   branch trace disabled 			 *  12:   PEBS unavailable 			 * Clear unsupported features 			 *  16:   SpeedStep enable 			 *  18:   enable MONITOR FSM                          */
end_comment

begin_comment
unit|misc |= (1<< 12) | (1<< 11); 			misc&= ~((1<< 18) | (1<< 16)); 			guest_msrs[i] = misc; 			break; 		case MSR_IA32_PLATFORM_ID: 			guest_msrs[i] = 0; 			break; 		default: 			panic("guest_msrs_init: missing initialization for msr " 			      "0x%0x", vmm_msr[i].num); 		} 	} }  static int msr_num_to_idx(u_int num) { 	int i;  	for (i = 0; i< vmm_msr_num; i++) 		if (vmm_msr[i].num == num) 			return (i);  	return (-1); }  int emulate_wrmsr(struct vm *vm, int cpu, u_int num, uint64_t val) { 	int idx; 	uint64_t *guest_msrs;  	if (lapic_msr(num)) 		return (lapic_wrmsr(vm, cpu, num, val));  	idx = msr_num_to_idx(num); 	if (idx< 0 || invalid_msr(idx)) 		return (EINVAL);  	if (!readonly_msr(idx)) { 		guest_msrs = vm_guest_msrs(vm, cpu);
comment|/* Stash the value */
end_comment

begin_comment
unit|guest_msrs[idx] = val;
comment|/* Update processor state for non-emulated MSRs */
end_comment

begin_comment
unit|if (!emulated_msr(idx)) 			wrmsr(vmm_msr[idx].num, val); 	}  	return (0); }  int emulate_rdmsr(struct vm *vm, int cpu, u_int num) { 	int error, idx; 	uint32_t eax, edx; 	uint64_t result, *guest_msrs;  	if (lapic_msr(num)) { 		error = lapic_rdmsr(vm, cpu, num,&result); 		goto done; 	}  	idx = msr_num_to_idx(num); 	if (idx< 0 || invalid_msr(idx)) { 		error = EINVAL; 		goto done; 	}  	guest_msrs = vm_guest_msrs(vm, cpu); 	result = guest_msrs[idx];
comment|/* 	 * If this is not an emulated msr register make sure that the processor 	 * state matches our cached state. 	 */
end_comment

begin_comment
unit|if (!emulated_msr(idx)&& (rdmsr(num) != result)) { 		panic("emulate_rdmsr: msr 0x%0x has inconsistent cached " 		      "(0x%016lx) and actual (0x%016lx) values", num, 		      result, rdmsr(num)); 	}  	error = 0;  done: 	if (error == 0) { 		eax = result; 		edx = result>> 32; 		error = vm_set_register(vm, cpu, VM_REG_GUEST_RAX, eax); 		if (error) 			panic("vm_set_register(rax) error %d", error); 		error = vm_set_register(vm, cpu, VM_REG_GUEST_RDX, edx); 		if (error) 			panic("vm_set_register(rdx) error %d", error); 	} 	return (error); }  void restore_guest_msrs(struct vm *vm, int cpu) { 	int i; 	uint64_t *guest_msrs;  	guest_msrs = vm_guest_msrs(vm, cpu);  	for (i = 0; i< vmm_msr_num; i++) { 		if (emulated_msr(i)) 			continue; 		else 			wrmsr(vmm_msr[i].num, guest_msrs[i]); 	} }  void restore_host_msrs(struct vm *vm, int cpu) { 	int i;  	for (i = 0; i< vmm_msr_num; i++) { 		if (emulated_msr(i)) 			continue; 		else 			wrmsr(vmm_msr[i].num, vmm_msr[i].hostval); 	} }
comment|/*  * Must be called by the CPU-specific code before any guests are  * created  */
end_comment

unit|void guest_msr_valid(int msr) { 	int i;  	for (i = 0; i< vmm_msr_num; i++) { 		if (vmm_msr[i].num == msr&& invalid_msr(i)) { 			vmm_msr[i].flags&= ~VMM_MSR_F_INVALID; 		} 	} }
end_unit

