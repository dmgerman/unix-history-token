begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2007, Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PMCSTAT_PL_CALLGRAPH_H_
end_ifndef

begin_define
define|#
directive|define
name|_PMCSTAT_PL_CALLGRAPH_H_
end_define

begin_comment
comment|/*  * Each call graph node is tracked by a pmcstat_cgnode struct.  */
end_comment

begin_struct
struct|struct
name|pmcstat_cgnode
block|{
name|struct
name|pmcstat_image
modifier|*
name|pcg_image
decl_stmt|;
name|uintfptr_t
name|pcg_func
decl_stmt|;
name|uint32_t
name|pcg_count
decl_stmt|;
name|uint32_t
name|pcg_nchildren
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|pmcstat_cgnode
argument_list|)
name|pcg_sibling
expr_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|pmcstat_cgnode
argument_list|)
name|pcg_children
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmcstat_cgnode_hash
block|{
name|struct
name|pmcstat_cgnode
modifier|*
name|pch_cgnode
decl_stmt|;
name|pmc_id_t
name|pch_pmcid
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|pmcstat_cgnode_hash
argument_list|)
name|pch_next
expr_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern LIST_HEAD(pmcstat_cgnode_hash_list
operator|,
extern|pmcstat_cgnode_hash
end_extern

begin_expr_stmt
unit|)
name|pmcstat_cgnode_hash
index|[
name|PMCSTAT_NHASH
index|]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|pmcstat_cgnode_hash_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function prototypes */
end_comment

begin_function_decl
name|int
name|pmcpl_cg_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcpl_cg_shutdown
parameter_list|(
name|FILE
modifier|*
name|mf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcpl_cg_process
parameter_list|(
name|struct
name|pmcstat_process
modifier|*
name|pp
parameter_list|,
name|struct
name|pmcstat_pmcrecord
modifier|*
name|pmcr
parameter_list|,
name|uint32_t
name|nsamples
parameter_list|,
name|uintfptr_t
modifier|*
name|cc
parameter_list|,
name|int
name|usermode
parameter_list|,
name|uint32_t
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmcpl_cg_topkeypress
parameter_list|(
name|int
name|c
parameter_list|,
name|void
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcpl_cg_topdisplay
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmcpl_cg_configure
parameter_list|(
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PMCSTAT_PL_CALLGRAPH_H_ */
end_comment

end_unit

