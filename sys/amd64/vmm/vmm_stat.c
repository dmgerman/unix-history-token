begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmm.h>
end_include

begin_include
include|#
directive|include
file|"vmm_util.h"
end_include

begin_include
include|#
directive|include
file|"vmm_stat.h"
end_include

begin_comment
comment|/*  * 'vst_num_elems' is the total number of addressable statistic elements  * 'vst_num_types' is the number of unique statistic types  *  * It is always true that 'vst_num_elems' is greater than or equal to  * 'vst_num_types'. This is because a stat type may represent more than  * one element (for e.g. VMM_STAT_ARRAY).  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|vst_num_elems
decl_stmt|,
name|vst_num_types
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|vmm_stat_type
modifier|*
name|vsttab
index|[
name|MAX_VMM_STAT_ELEMS
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|MALLOC_DEFINE
argument_list|(
name|M_VMM_STAT
argument_list|,
literal|"vmm stat"
argument_list|,
literal|"vmm stat"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|vst_size
value|((size_t)vst_num_elems * sizeof(uint64_t))
end_define

begin_function
name|void
name|vmm_stat_register
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|vmm_stat_type
modifier|*
name|vst
init|=
name|arg
decl_stmt|;
comment|/* We require all stats to identify themselves with a description */
if|if
condition|(
name|vst
operator|->
name|desc
operator|==
name|NULL
condition|)
return|return;
if|if
condition|(
name|vst
operator|->
name|scope
operator|==
name|VMM_STAT_SCOPE_INTEL
operator|&&
operator|!
name|vmm_is_intel
argument_list|()
condition|)
return|return;
if|if
condition|(
name|vst
operator|->
name|scope
operator|==
name|VMM_STAT_SCOPE_AMD
operator|&&
operator|!
name|vmm_is_amd
argument_list|()
condition|)
return|return;
if|if
condition|(
name|vst_num_elems
operator|+
name|vst
operator|->
name|nelems
operator|>=
name|MAX_VMM_STAT_ELEMS
condition|)
block|{
name|printf
argument_list|(
literal|"Cannot accomodate vmm stat type \"%s\"!\n"
argument_list|,
name|vst
operator|->
name|desc
argument_list|)
expr_stmt|;
return|return;
block|}
name|vst
operator|->
name|index
operator|=
name|vst_num_elems
expr_stmt|;
name|vst_num_elems
operator|+=
name|vst
operator|->
name|nelems
expr_stmt|;
name|vsttab
index|[
name|vst_num_types
operator|++
index|]
operator|=
name|vst
expr_stmt|;
block|}
end_function

begin_function
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
block|{
name|struct
name|vmm_stat_type
modifier|*
name|vst
decl_stmt|;
name|uint64_t
modifier|*
name|stats
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|vcpu
operator|<
literal|0
operator|||
name|vcpu
operator|>=
name|VM_MAXCPU
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
comment|/* Let stats functions update their counters */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|vst_num_types
condition|;
name|i
operator|++
control|)
block|{
name|vst
operator|=
name|vsttab
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|vst
operator|->
name|func
operator|!=
name|NULL
condition|)
call|(
modifier|*
name|vst
operator|->
name|func
call|)
argument_list|(
name|vm
argument_list|,
name|vcpu
argument_list|,
name|vst
argument_list|)
expr_stmt|;
block|}
comment|/* Copy over the stats */
name|stats
operator|=
name|vcpu_stats
argument_list|(
name|vm
argument_list|,
name|vcpu
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|vst_num_elems
condition|;
name|i
operator|++
control|)
name|buf
index|[
name|i
index|]
operator|=
name|stats
index|[
name|i
index|]
expr_stmt|;
operator|*
name|num_stats
operator|=
name|vst_num_elems
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|vmm_stat_alloc
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|malloc
argument_list|(
name|vst_size
argument_list|,
name|M_VMM_STAT
argument_list|,
name|M_WAITOK
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|vmm_stat_init
parameter_list|(
name|void
modifier|*
name|vp
parameter_list|)
block|{
name|bzero
argument_list|(
name|vp
argument_list|,
name|vst_size
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|vmm_stat_free
parameter_list|(
name|void
modifier|*
name|vp
parameter_list|)
block|{
name|free
argument_list|(
name|vp
argument_list|,
name|M_VMM_STAT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|vmm_stat_desc_copy
parameter_list|(
name|int
name|index
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|bufsize
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|struct
name|vmm_stat_type
modifier|*
name|vst
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|vst_num_types
condition|;
name|i
operator|++
control|)
block|{
name|vst
operator|=
name|vsttab
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|index
operator|>=
name|vst
operator|->
name|index
operator|&&
name|index
operator|<
name|vst
operator|->
name|index
operator|+
name|vst
operator|->
name|nelems
condition|)
block|{
if|if
condition|(
name|vst
operator|->
name|nelems
operator|>
literal|1
condition|)
block|{
name|snprintf
argument_list|(
name|buf
argument_list|,
name|bufsize
argument_list|,
literal|"%s[%d]"
argument_list|,
name|vst
operator|->
name|desc
argument_list|,
name|index
operator|-
name|vst
operator|->
name|index
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|strlcpy
argument_list|(
name|buf
argument_list|,
name|vst
operator|->
name|desc
argument_list|,
name|bufsize
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
comment|/* found it */
block|}
block|}
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* global statistics */
end_comment

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VCPU_MIGRATIONS
argument_list|,
literal|"vcpu migration across host cpus"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_COUNT
argument_list|,
literal|"total number of vm exits"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_EXTINT
argument_list|,
literal|"vm exits due to external interrupt"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_HLT
argument_list|,
literal|"number of times hlt was intercepted"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_CR_ACCESS
argument_list|,
literal|"number of times %cr access was intercepted"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_RDMSR
argument_list|,
literal|"number of times rdmsr was intercepted"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_WRMSR
argument_list|,
literal|"number of times wrmsr was intercepted"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_MTRAP
argument_list|,
literal|"number of monitor trap exits"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_PAUSE
argument_list|,
literal|"number of times pause was intercepted"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_INTR_WINDOW
argument_list|,
literal|"vm exits due to interrupt window opening"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_NMI_WINDOW
argument_list|,
literal|"vm exits due to nmi window opening"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_INOUT
argument_list|,
literal|"number of times in/out was intercepted"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_CPUID
argument_list|,
literal|"number of times cpuid was intercepted"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_NESTED_FAULT
argument_list|,
literal|"vm exits due to nested page fault"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_INST_EMUL
argument_list|,
literal|"vm exits for instruction emulation"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_UNKNOWN
argument_list|,
literal|"number of vm exits for unknown reason"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_ASTPENDING
argument_list|,
literal|"number of times astpending at exit"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_USERSPACE
argument_list|,
literal|"number of vm exits handled in userspace"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_RENDEZVOUS
argument_list|,
literal|"number of times rendezvous pending at exit"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VMM_STAT
argument_list|(
name|VMEXIT_EXCEPTION
argument_list|,
literal|"number of vm exits due to exceptions"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

