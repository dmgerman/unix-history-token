begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rui Paulo<rpaulo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|PMC_MDEP_CLASS_INDEX_XSCALE
value|0
end_define

begin_comment
comment|/*  * On the ARM platform we support the following PMCs.  *  * XSCALE	Intel XScale processors  */
end_comment

begin_include
include|#
directive|include
file|<dev/hwpmc/hwpmc_xscale.h>
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
name|pmc_md_xscale_pmc
name|pm_xscale
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
value|((TF)->tf_pc)
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
name|pmc_xscale_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_xscale_finalize
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

