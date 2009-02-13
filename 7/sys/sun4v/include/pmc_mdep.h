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
value|PMCLOG_READ64
end_define

begin_define
define|#
directive|define
name|PMCLOG_EMITADDR
value|PMCLOG_EMIT64
end_define

begin_if
if|#
directive|if
name|_KERNEL
end_if

begin_union
union|union
name|pmc_md_pmc
block|{ }
union|;
end_union

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

