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
name|PMC_MDEP_CLASS_INDEX_MIPS
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

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

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_KERNEL
end_if

begin_comment
comment|/*  * MIPS event codes are encoded with a select bit.  The  * select bit is used when writing to CP0 so that we   * can select either counter 0/2 or 1/3.  The cycle  * and instruction counters are special in that they  * can be counted on either 0/2 or 1/3.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_CTR_ALL
value|255
end_define

begin_comment
comment|/* Count events in any counter. */
end_comment

begin_define
define|#
directive|define
name|MIPS_CTR_0
value|0
end_define

begin_comment
comment|/* Counter 0 Event */
end_comment

begin_define
define|#
directive|define
name|MIPS_CTR_1
value|1
end_define

begin_comment
comment|/* Counter 1 Event */
end_comment

begin_struct
struct|struct
name|mips_event_code_map
block|{
name|uint32_t
name|pe_ev
decl_stmt|;
comment|/* enum value */
name|uint8_t
name|pe_counter
decl_stmt|;
comment|/* Which counter this can be counted in. */
name|uint8_t
name|pe_code
decl_stmt|;
comment|/* numeric code */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mips_pmc_spec
block|{
name|uint32_t
name|ps_cpuclass
decl_stmt|;
name|uint32_t
name|ps_cputype
decl_stmt|;
name|uint32_t
name|ps_capabilities
decl_stmt|;
name|int
name|ps_counter_width
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|pmc_md_pmc
block|{
name|uint32_t
name|pm_mips_evsel
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

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|mips_event_code_map
name|mips_event_codes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|mips_event_codes_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mips_npmcs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mips_pmc_spec
name|mips_pmc_spec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_mips_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_mips_finalize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CPU-specific functions  */
end_comment

begin_function_decl
name|uint32_t
name|mips_get_perfctl
parameter_list|(
name|int
name|cpu
parameter_list|,
name|int
name|ri
parameter_list|,
name|uint32_t
name|event
parameter_list|,
name|uint32_t
name|caps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|mips_pmcn_read
parameter_list|(
name|unsigned
name|int
name|pmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|mips_pmcn_write
parameter_list|(
name|unsigned
name|int
name|pmc
parameter_list|,
name|uint64_t
name|v
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

