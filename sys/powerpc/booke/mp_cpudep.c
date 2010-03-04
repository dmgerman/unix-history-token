begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2009 Semihalf, Rafal Jaworowski  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_include
include|#
directive|include
file|<machine/spr.h>
end_include

begin_function_decl
specifier|extern
name|void
name|dcache_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dcache_inval
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|icache_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|icache_inval
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|volatile
name|void
modifier|*
name|ap_pcpu
decl_stmt|;
end_decl_stmt

begin_function
name|uintptr_t
name|cpudep_ap_bootstrap
parameter_list|()
block|{
name|uint32_t
name|msr
decl_stmt|,
name|sp
decl_stmt|,
name|csr
decl_stmt|;
comment|/* Enable L1 caches */
name|csr
operator|=
name|mfspr
argument_list|(
name|SPR_L1CSR0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|csr
operator|&
name|L1CSR0_DCE
operator|)
operator|==
literal|0
condition|)
block|{
name|dcache_inval
argument_list|()
expr_stmt|;
name|dcache_enable
argument_list|()
expr_stmt|;
block|}
name|csr
operator|=
name|mfspr
argument_list|(
name|SPR_L1CSR1
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|csr
operator|&
name|L1CSR1_ICE
operator|)
operator|==
literal|0
condition|)
block|{
name|icache_inval
argument_list|()
expr_stmt|;
name|icache_enable
argument_list|()
expr_stmt|;
block|}
comment|/* Set MSR */
name|msr
operator|=
name|PSL_ME
expr_stmt|;
name|mtmsr
argument_list|(
name|msr
argument_list|)
expr_stmt|;
comment|/* Assign pcpu fields, return ptr to this AP's idle thread kstack */
name|pcpup
operator|->
name|pc_curthread
operator|=
name|pcpup
operator|->
name|pc_idlethread
expr_stmt|;
name|pcpup
operator|->
name|pc_curpcb
operator|=
name|pcpup
operator|->
name|pc_curthread
operator|->
name|td_pcb
expr_stmt|;
name|sp
operator|=
name|pcpup
operator|->
name|pc_curpcb
operator|->
name|pcb_sp
expr_stmt|;
comment|/* XXX shouldn't the pcb_sp be checked/forced for alignment here?? */
return|return
operator|(
name|sp
operator|)
return|;
block|}
end_function

begin_function
name|void
name|cpudep_ap_setup
parameter_list|()
block|{ }
end_function

end_unit

