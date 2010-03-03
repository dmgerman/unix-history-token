begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is in the public domain.  *  *	from: src/sys/alpha/include/pmc_mdep.h,v 1.2 2005/06/09 19:45:06 jkoshy  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PMC_MDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PMC_MDEP_H_
end_define

begin_define
define|#
directive|define
name|PMC_MDEP_CLASS_INDEX_MIPS24K
value|0
end_define

begin_include
include|#
directive|include
file|<dev/hwpmc/hwpmc_mips24k.h>
end_include

begin_union
union|union
name|pmc_md_op_pmcallocate
block|{
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
value|PMCLOG_READ32
end_define

begin_define
define|#
directive|define
name|PMCLOG_EMITADDR
value|PMCLOG_EMIT32
end_define

begin_if
if|#
directive|if
name|_KERNEL
end_if

begin_union
union|union
name|pmc_md_pmc
block|{
name|struct
name|pmc_md_mips24k_pmc
name|pm_mips24k
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
value|((TF)->pc)
end_define

begin_define
define|#
directive|define
name|PMC_TRAPFRAME_TO_FP
parameter_list|(
name|TF
parameter_list|)
value|((TF)->tf_usr_lr)
end_define

begin_define
define|#
directive|define
name|PMC_TRAPFRAME_TO_SP
parameter_list|(
name|TF
parameter_list|)
value|((TF)->tf_usr_sp)
end_define

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_mips24k_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_mips24k_finalize
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
comment|/* !_MACHINE_PMC_MDEP_H_ */
end_comment

end_unit

