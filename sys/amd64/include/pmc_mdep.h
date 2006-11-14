begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2005 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<dev/hwpmc/hwpmc_amd.h>
end_include

begin_include
include|#
directive|include
file|<dev/hwpmc/hwpmc_piv.h>
end_include

begin_union
union|union
name|pmc_md_op_pmcallocate
block|{
name|struct
name|pmc_md_amd_op_pmcallocate
name|pm_amd
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
name|pmc_md_p4_pmc
name|pm_p4
decl_stmt|;
block|}
union|;
end_union

begin_struct_decl
struct_decl|struct
name|pmc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_function_decl
name|void
name|pmc_x86_lapic_enable_pmc_interrupt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PMC_MDEP_H */
end_comment

end_unit

