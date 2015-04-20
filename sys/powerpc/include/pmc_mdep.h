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
name|PMC_MDEP_CLASS_INDEX_POWERPC
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

begin_define
define|#
directive|define
name|mtpmr
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|__asm __volatile("mtpmr %0,%1" : : "K"(reg), "r"(val))
end_define

begin_define
define|#
directive|define
name|mfpmr
parameter_list|(
name|reg
parameter_list|)
define|\
value|( { register_t val;						\ 	  __asm __volatile("mfpmr %0,%1" : "=r"(val) : "K"(reg));	\ 	  val; } )
end_define

begin_define
define|#
directive|define
name|PMR_PMC0
value|16
end_define

begin_define
define|#
directive|define
name|PMR_PMC1
value|17
end_define

begin_define
define|#
directive|define
name|PMR_PMC2
value|18
end_define

begin_define
define|#
directive|define
name|PMR_PMC3
value|19
end_define

begin_define
define|#
directive|define
name|PMR_PMLCa0
value|144
end_define

begin_define
define|#
directive|define
name|PMLCax_FC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PMLCax_FCS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PMLCax_FCU
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PMLCax_FCM1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PMLCax_FCM0
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PMLCax_CE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PMLCax_EVENT
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|PMLCax_FCGS1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PMLCax_FCGS0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PMR_PMLCa1
value|145
end_define

begin_define
define|#
directive|define
name|PMR_PMLCa2
value|146
end_define

begin_define
define|#
directive|define
name|PMR_PMLCa3
value|147
end_define

begin_define
define|#
directive|define
name|PMR_PMLCb0
value|272
end_define

begin_define
define|#
directive|define
name|PMLCbx_TRIGONCTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|PMLCbx_TRIGOFFCTL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|PMLCbx_PMCC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PMLCbx_PMP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 13)
end_define

begin_define
define|#
directive|define
name|PMLCbx_TREHMUL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|PMLCbx_TRESHOLD
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|PMR_PMLCb1
value|273
end_define

begin_define
define|#
directive|define
name|PMR_PMLCb2
value|274
end_define

begin_define
define|#
directive|define
name|PMR_PMLCb3
value|275
end_define

begin_define
define|#
directive|define
name|PMR_PMGC0
value|400
end_define

begin_define
define|#
directive|define
name|PMGC_FAC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PMGC_PMIE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PMGC_FCECE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PMGC_TBSEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|PMGC_TBEE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PMR_UPMC0
value|0
end_define

begin_define
define|#
directive|define
name|PMR_UPMC1
value|1
end_define

begin_define
define|#
directive|define
name|PMR_UPMC2
value|2
end_define

begin_define
define|#
directive|define
name|PMR_UPMC3
value|3
end_define

begin_define
define|#
directive|define
name|PMR_UPMLCa0
value|128
end_define

begin_define
define|#
directive|define
name|PMR_UPMLCa1
value|129
end_define

begin_define
define|#
directive|define
name|PMR_UPMLCa2
value|130
end_define

begin_define
define|#
directive|define
name|PMR_UPMLCa3
value|131
end_define

begin_define
define|#
directive|define
name|PMR_UPMLCb0
value|256
end_define

begin_define
define|#
directive|define
name|PMR_UPMLCb1
value|257
end_define

begin_define
define|#
directive|define
name|PMR_UPMLCb2
value|258
end_define

begin_define
define|#
directive|define
name|PMR_UPMLCb3
value|259
end_define

begin_define
define|#
directive|define
name|PMR_UPMGC0
value|384
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

