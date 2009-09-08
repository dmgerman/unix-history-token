begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2008 Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Machine dependent interfaces */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PMC_MDEP_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PMC_MDEP_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|pmc_mdep
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/hwpmc/hwpmc_amd.h>
end_include

begin_include
include|#
directive|include
file|<dev/hwpmc/hwpmc_core.h>
end_include

begin_include
include|#
directive|include
file|<dev/hwpmc/hwpmc_piv.h>
end_include

begin_include
include|#
directive|include
file|<dev/hwpmc/hwpmc_tsc.h>
end_include

begin_comment
comment|/*  * Intel processors implementing V2 and later of the Intel performance  * measurement architecture have PMCs of the following classes: TSC,  * IAF and IAP.  */
end_comment

begin_define
define|#
directive|define
name|PMC_MDEP_CLASS_INDEX_TSC
value|0
end_define

begin_define
define|#
directive|define
name|PMC_MDEP_CLASS_INDEX_K8
value|1
end_define

begin_define
define|#
directive|define
name|PMC_MDEP_CLASS_INDEX_P4
value|1
end_define

begin_define
define|#
directive|define
name|PMC_MDEP_CLASS_INDEX_IAP
value|1
end_define

begin_define
define|#
directive|define
name|PMC_MDEP_CLASS_INDEX_IAF
value|2
end_define

begin_comment
comment|/*  * On the amd64 platform we support the following PMCs.  *  * TSC		The timestamp counter  * K8		AMD Athlon64 and Opteron PMCs in 64 bit mode.  * PIV		Intel P4/HTT and P4/EMT64  * IAP		Intel Core/Core2/Atom CPUs in 64 bits mode.  * IAF		Intel fixed-function PMCs in Core2 and later CPUs.  */
end_comment

begin_union
union|union
name|pmc_md_op_pmcallocate
block|{
name|struct
name|pmc_md_amd_op_pmcallocate
name|pm_amd
decl_stmt|;
name|struct
name|pmc_md_iaf_op_pmcallocate
name|pm_iaf
decl_stmt|;
name|struct
name|pmc_md_iap_op_pmcallocate
name|pm_iap
decl_stmt|;
name|struct
name|pmc_md_p4_op_pmcallocate
name|pm_p4
decl_stmt|;
name|uint64_t
name|__pad
index|[
literal|4
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Logging */
end_comment

begin_define
define|#
directive|define
name|PMCLOG_READADDR
value|PMCLOG_READ64
end_define

begin_define
define|#
directive|define
name|PMCLOG_EMITADDR
value|PMCLOG_EMIT64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_union
union|union
name|pmc_md_pmc
block|{
name|struct
name|pmc_md_amd_pmc
name|pm_amd
decl_stmt|;
name|struct
name|pmc_md_iaf_pmc
name|pm_iaf
decl_stmt|;
name|struct
name|pmc_md_iap_pmc
name|pm_iap
decl_stmt|;
name|struct
name|pmc_md_p4_pmc
name|pm_p4
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|PMC_TRAPFRAME_TO_PC
parameter_list|(
name|TF
parameter_list|)
value|((TF)->tf_rip)
end_define

begin_define
define|#
directive|define
name|PMC_TRAPFRAME_TO_FP
parameter_list|(
name|TF
parameter_list|)
value|((TF)->tf_rbp)
end_define

begin_define
define|#
directive|define
name|PMC_TRAPFRAME_TO_USER_SP
parameter_list|(
name|TF
parameter_list|)
value|((TF)->tf_rsp)
end_define

begin_define
define|#
directive|define
name|PMC_TRAPFRAME_TO_KERNEL_SP
parameter_list|(
name|TF
parameter_list|)
value|((TF)->tf_rsp)
end_define

begin_define
define|#
directive|define
name|PMC_AT_FUNCTION_PROLOGUE_PUSH_BP
parameter_list|(
name|I
parameter_list|)
define|\
value|(((I)& 0xffffffff) == 0xe5894855)
end_define

begin_comment
comment|/* pushq %rbp; movq %rsp,%rbp */
end_comment

begin_define
define|#
directive|define
name|PMC_AT_FUNCTION_PROLOGUE_MOV_SP_BP
parameter_list|(
name|I
parameter_list|)
define|\
value|(((I)& 0x00ffffff) == 0x00e58948)
end_define

begin_comment
comment|/* movq %rsp,%rbp */
end_comment

begin_define
define|#
directive|define
name|PMC_AT_FUNCTION_EPILOGUE_RET
parameter_list|(
name|I
parameter_list|)
define|\
value|(((I)& 0xFF) == 0xC3)
end_define

begin_comment
comment|/* ret */
end_comment

begin_define
define|#
directive|define
name|PMC_IN_TRAP_HANDLER
parameter_list|(
name|PC
parameter_list|)
define|\
value|((PC)>= (uintptr_t) start_exceptions&&	\ 	 (PC)< (uintptr_t) end_exceptions)
end_define

begin_define
define|#
directive|define
name|PMC_IN_KERNEL_STACK
parameter_list|(
name|S
parameter_list|,
name|START
parameter_list|,
name|END
parameter_list|)
define|\
value|((S)>= (START)&& (S)< (END))
end_define

begin_define
define|#
directive|define
name|PMC_IN_KERNEL
parameter_list|(
name|va
parameter_list|)
value|(((va)>= DMAP_MIN_ADDRESS&&			\ 	(va)< DMAP_MAX_ADDRESS) || ((va)>= VM_MIN_KERNEL_ADDRESS&&	\ 	(va)< VM_MAX_KERNEL_ADDRESS))
end_define

begin_define
define|#
directive|define
name|PMC_IN_USERSPACE
parameter_list|(
name|va
parameter_list|)
value|((va)<= VM_MAXUSER_ADDRESS)
end_define

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_decl_stmt
name|void
name|start_exceptions
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|end_exceptions
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_amd_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_amd_finalize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_intel_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_intel_finalize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
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
comment|/* _MACHINE_PMC_MDEP_H */
end_comment

end_unit

