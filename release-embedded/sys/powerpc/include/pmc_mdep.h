begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is in the public domain.  *  * $FreeBSD$  */
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
name|PMC_MDEP_CLASS_INDEX_CPU
value|1
end_define

begin_define
define|#
directive|define
name|PMC_MDEP_CLASS_INDEX_PPC7450
value|1
end_define

begin_define
define|#
directive|define
name|PMC_MDEP_CLASS_INDEX_PPC970
value|1
end_define

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

begin_struct
struct|struct
name|pmc_md_powerpc_pmc
block|{
name|uint32_t
name|pm_powerpc_evsel
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|pmc_md_pmc
block|{
name|struct
name|pmc_md_powerpc_pmc
name|pm_powerpc
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
value|((TF)->srr0)
end_define

begin_define
define|#
directive|define
name|PMC_TRAPFRAME_TO_FP
parameter_list|(
name|TF
parameter_list|)
value|((TF)->fixreg[1])
end_define

begin_define
define|#
directive|define
name|PMC_TRAPFRAME_TO_SP
parameter_list|(
name|TF
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PMC_MDEP_H_ */
end_comment

end_unit

