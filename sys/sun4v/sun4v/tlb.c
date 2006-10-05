begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_pmap.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/tlb.h>
end_include

begin_expr_stmt
name|PMAP_STATS_VAR
argument_list|(
name|tlb_ncontext_demap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PMAP_STATS_VAR
argument_list|(
name|tlb_npage_demap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PMAP_STATS_VAR
argument_list|(
name|tlb_nrange_demap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|tlb_flush_user_t
modifier|*
name|tlb_flush_user
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Some tlb operations must be atomic, so no interrupt or trap can be allowed  * while they are in progress. Traps should not happen, but interrupts need to  * be explicitely disabled. critical_enter() cannot be used here, since it only  * disables soft interrupts.  */
end_comment

begin_function
name|void
name|tlb_context_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|tlb_page_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|tlb_range_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|,
name|vm_offset_t
name|start
parameter_list|,
name|vm_offset_t
name|end
parameter_list|)
block|{ }
end_function

end_unit

