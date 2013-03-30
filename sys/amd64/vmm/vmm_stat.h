begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMM_STAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMM_STAT_H_
end_define

begin_struct_decl
struct_decl|struct
name|vm
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|MAX_VMM_STAT_TYPES
value|64
end_define

begin_comment
comment|/* arbitrary */
end_comment

begin_enum
enum|enum
name|vmm_stat_scope
block|{
name|VMM_STAT_SCOPE_ANY
block|,
name|VMM_STAT_SCOPE_INTEL
block|,
comment|/* Intel VMX specific statistic */
name|VMM_STAT_SCOPE_AMD
block|,
comment|/* AMD SVM specific statistic */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|vmm_stat_type
block|{
name|int
name|index
decl_stmt|;
comment|/* position in the stats buffer */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* description of statistic */
name|enum
name|vmm_stat_scope
name|scope
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|vmm_stat_init
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VMM_STAT_DEFINE
parameter_list|(
name|type
parameter_list|,
name|desc
parameter_list|,
name|scope
parameter_list|)
define|\
value|struct vmm_stat_type type[1] = {				\ 		{ -1, desc, scope }					\ 	};								\ 	SYSINIT(type##_stat, SI_SUB_KLD, SI_ORDER_ANY, vmm_stat_init, type)
end_define

begin_define
define|#
directive|define
name|VMM_STAT_DECLARE
parameter_list|(
name|type
parameter_list|)
define|\
value|extern struct vmm_stat_type type[1]
end_define

begin_define
define|#
directive|define
name|VMM_STAT
parameter_list|(
name|type
parameter_list|,
name|desc
parameter_list|)
define|\
value|VMM_STAT_DEFINE(type, desc, VMM_STAT_SCOPE_ANY)
end_define

begin_define
define|#
directive|define
name|VMM_STAT_INTEL
parameter_list|(
name|type
parameter_list|,
name|desc
parameter_list|)
define|\
value|VMM_STAT_DEFINE(type, desc, VMM_STAT_SCOPE_INTEL)
end_define

begin_define
define|#
directive|define
name|VMM_STAT_AMD
parameter_list|(
name|type
parameter_list|,
name|desc
parameter_list|)
define|\
value|VMM_STAT_DEFINE(type, desc, VMM_STAT_SCOPE_AMD)
end_define

begin_function_decl
name|void
modifier|*
name|vmm_stat_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmm_stat_free
parameter_list|(
name|void
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * 'buf' should be at least fit 'MAX_VMM_STAT_TYPES' entries  */
end_comment

begin_function_decl
name|int
name|vmm_stat_copy
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|int
modifier|*
name|num_stats
parameter_list|,
name|uint64_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|vmm_stat_desc
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|__inline
name|vmm_stat_incr
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|struct
name|vmm_stat_type
modifier|*
name|vst
parameter_list|,
name|uint64_t
name|x
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|VMM_KEEP_STATS
name|uint64_t
modifier|*
name|stats
init|=
name|vcpu_stats
argument_list|(
name|vm
argument_list|,
name|vcpu
argument_list|)
decl_stmt|;
if|if
condition|(
name|vst
operator|->
name|index
operator|>=
literal|0
condition|)
name|stats
index|[
name|vst
operator|->
name|index
index|]
operator|+=
name|x
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VCPU_MIGRATIONS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_COUNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_EXTINT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_HLT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_CR_ACCESS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_RDMSR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_WRMSR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_MTRAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_PAUSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_INTR_WINDOW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_NMI_WINDOW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_INOUT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_CPUID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_EPT_FAULT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_UNKNOWN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_ASTPENDING
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT_DECLARE
argument_list|(
name|VMEXIT_USERSPACE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

